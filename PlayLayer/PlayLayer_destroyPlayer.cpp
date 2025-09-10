void PlayLayer::destroyPlayer(PlayerObject* player, GameObject* go) {
    if (!player)
        player = m_player1;
    if (m_player1->m_isLocked || m_playerDied)
        return;

    if (go && m_anticheatSpike && go->m_uniqueID == m_anticheatSpike->m_uniqueID) {
        setDamageVerifiedIdx(m_coinsCollected);
        m_damageVerified = true;
        return;
    }

    GameManager* gm = GameManager::sharedState();

    stopActionByTag(20);
    updateTimeWarp(1.0);
    commitJumps();

    m_effectManager->playerDied();
    m_gameState.m_pauseCounter = 0;

    if (!m_isPracticeMode && !gm->getGameVariable("0014")) {
        shakeCamera(0.15, 1.0, 0.0);
    }

    m_unk3268 = true;
    if (!m_hintShown && m_attempts > 1) {
        int levelID = m_level->m_levelID.value();
        if (
            (levelID == 1 || levelID == 1001) && !m_player1->m_hasEverJumped
            || (levelID == 3 || levelID == 1003) && !m_player1->m_hasEverHitRing
        ) {
            showHint();
        }
    }

    m_playerDied = true;
    player->playerDestroyed();

    if (m_gameState.m_isDualMode) {
        PlayerObject* otherPlayer = getOtherPlayer(player);
        otherPlayer->playExitDualEffect();
        otherPlayer->playerDestroyed();
    }

    int diamondsAwarded = 0;
    int currencyAwarded = 0;
    bool newBest = false;
    bool noReward = false;
    if (!m_isTestMode && !m_isPlatformer) {
        uint currentPercent = std::max(0, std::min(getCurrentPercentInt(), 99));
        newBest = !m_isPracticeMode && currentPercent > m_level->getNormalPercent();
        canEarnOrbs = !m_isPracticeMode && currentPercent > m_level->m_orbCompletion.value();
        noReward = m_showLeaderboardPercentage && !m_isPracticeMode;

        if (noReward && !m_isPracticeMode && !newBest) {
            noReward = false;
            if (!canEarnOrbs && currentPercent > m_level->m_newNormalPercent2.value()) {
                newBest = true;
                noReward = true;
            }
        }

        m_level->savePercentage(
            currentPercent,
            m_isPracticeMode,
            m_clicks,
            getTempMilliTime() - m_pauseTime - m_currentTime,
            m_damageVerified && m_damageVerifiedIndex.value() == m_coinsCollected
        );

        if (m_level->m_levelType == Local) {
            gm->reportPercentageForLevel(m_level->m_levelID.value(), currentPercent, m_isPracticeMode);
        }

        if (!m_isPracticeMode && m_level->m_stars.value() > 0 && !m_isPlatformer) {
            GameStatsManager* gsm = GameStatsManager::sharedState();

            currencyAwarded = gsm->awardCurrencyForLevel(m_level);
            diamondsAwarded = m_level->m_gauntletLevel.value();
            if (m_level->m_dailyID.value() > 0 || diamondsAwarded > 0) {
                diamondsAwarded = gsm->awardDiamondsForLevel(m_level);
            }
        }
    }
    bool hasEarned = (currencyAwarded + diamondsAwarded) > 0;
    if (!m_isPracticeMode) {
        m_lastAttemptPercent = getCurrentPercentInt();
    }

    if (!m_gameState.m_unkBool22) {
        if (!m_isPracticeMode || m_practiceMusicSync) {
            FMODAudioEngine::sharedEngine()->pauseAllMusic();
        }
        FMODAudioEngine::sharedEngine()->stopAllEffects();
    }

    if (!m_gameState.m_unkBool26) {
        FMODAudioEngine::sharedEngine()->playEffect(
            "player_died", 1.0, 0.0, 0.65, diamondsAwarded, newBest
        );
    }

    if (!gm->getGameVariable("0026") && !m_isPracticeMode) {
        if (hasEarned) {
            showNewBest(!newBest, currencyAwarded, diamondsAwarded, false, false, false);
        }

        m_uilayer->disableMenu();
        float delay = m_gameState.m_unkUint14;
        if (delay < 0.5f || std::isnan(delay))
            delay = 0.5f;
        auto delayTime = CCDelayTime::create(delay);
        auto callFunc = CCCallFunc::create(this, callfunc_selector(PlayLayer::showRetryLayer));

        auto sequence = CCSequence::create(delayTime, callFunc, nullptr);
        runAction(sequence);
    } else {
        m_inResetDelay = true;
        float resetDelay = 1.0f;
        if (gm->getGameVariable("0052"))
            resetDelay = 0.5f;
        if (m_gameState.m_unkUint14 > resetDelay) {
            resetDelay = m_gameState.m_unkUint14;
        }

        if (newBest || hasEarned) {
            GameStatsManager* gsm = GameStatsManager::sharedState();
            bool delayResetLevel = !gm->getUGV("17") && gsm->getStat("14") > 500;

            bool awardKey = gsm->awardSecretKey();
            showNewBest(!newBest, currencyAwarded, diamondsAwarded, awardKey, delayResetLevel, noReward);
            
            if (resetDelay < 1.4f) {
                resetDelay = 1.4f;
            }

            if (!delayResetLevel) {
                stopActionByTag(16);
                return;
            }

            gm->setUGV("17", true);
            auto dialogObject = DialogObject::create("The Shopkeeper", "I see you have a lot of <cl>orbs</c>. You should visit my <cy>shop</c>!", 5, 1.0, false, ccc3(255, 255, 255));
            auto dialogLayer = DialogLayer::create(dialogObject, 1);
            
            addChild(dialogLayer, 100);
            dialogLayer->setOpacity(0);

            dialogLayer->m_delegate = this;
            dialogLayer->updateChatPlacement(1);
            dialogLayer->animateIn(4);
            stopActionByTag(16);
        } else {
            stopActionByTag(16);
            auto delayTime = CCDelayTime::create(resetDelay);
            auto callFunc = CCCallFunc::create(this, callfunc_selector(PlayLayer::delayedResetLevel));
            auto sequence = CCSequence::create(delayTime, callFunc, nullptr);
            sequence->setTag(16);
            runAction(sequence);
        }
    }
}