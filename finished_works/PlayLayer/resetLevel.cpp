void PlayLayer::resetLevel() {
    m_activeDualTouch = false;
    *(int32_t *)(this + 0x4c8) = 0;
    m_effectManager->resetEffects();
    *(int32_t *)(this + 0x4e0) = 0;
    *(int32_t *)(this + 0x5f4) = 0;
    *(int8_t *)(this + 0x73a) = true;
    *(int8_t *)(this + 0x75c) = false;
    *(int8_t *)(this + 0x76b) = false;
    *(int8_t *)(this + 0x770) = false;
    *(this + 0x774) = nullptr;
    *(int8_t *)(this + 0x77c) = false;
    *(int32_t *)(this + 0x7d8) = 0;
    m_activeGravityEffects = 0;
    m_hasCompletedLevel = false;
    m_hasLevelCompleteMenu = false;
    m_previousRecords = "";
    m_shouldSmoothCamera = false;
    m_time = 0.0;
    m_UILayer->enableMenu();
    this->stopActionByTag(0x13);
    *(int32_t *)(this + 0x48c) = 1;
    m_attemptClickCount = 0;
    *(this + 0x7b8) = nullptr;
    *(this + 0x7c8) = nullptr;
    *(this + 0x7d0) = nullptr;
    m_currentShakeInterval = 0.0;
    m_isCameraShaking = false;
    m_lastShakeTime = 0.0;
    m_cameraShakeOffset = g_10069c5b0;
    this->stopActionByTag(0xa);
    this->stopActionByTag(0xb);
    m_camera4f0 = 0;
    m_cameraXLocked = false;
    m_cameraYLocked = false;
    if (!GameManager::sharedState()->m_ldm) {
        m_hasGlitter = false;
        m_particleSystem->stopSystem();
    }
    m_isDead = false;
    m_startCameraAtCorner = *(int8_t *)(this + 0x748);
    m_pickedUpItems->removeAllObjects();
    *(this + 0x540)->removeAllObjects();
    *(this + 0x650)->removeAllObjects();

    for (int i = 0; i < m_objects->count(); ++i) {
        GameObject* obj = m_objects->objectAtIndex(i);
        
        auto oldPosition = obj->getRealPosition(obj);
        obj->resetObject(obj);
        obj->m_activeEnterEffect = 1;

        auto oldSection = obj->getSectionIdx();
        this->reorderObjectSection(obj);
        auto newSection = obj->getSectionIdx();

        if (oldSection != newSection) {
            if (
                oldSection >= m_firstVisibleSection &&
                oldSection <= m_lastVisibleSection &&
                (newSection > m_lastVisibleSection || newSection >= m_firstVisibleSection)
            ) {
                obj->deactivateObject(true);
            }
        }

        if (obj->getRealPosition() != oldPosition) {
            obj->m_textureRectDirty = true;
            obj->setObjectRectDirty(true);
            obj->setOrientedRectDirty(true);
        }  
    }

    *(int8_t *)(this + 0x63c) = false;
    *(int8_t *)(this + 0x6c0) = false;
    m_backgroundScrollOffset = 0.007812;
    m_dualObject = nullptr;
    m_isFlipped = false;
    m_latestVehicle = nullptr;
    m_mirrorTransition = 0;
    this->stopActionByTag(0xe);
    m_audioEffectsLayer->resetAudioVars(m_audioEffectsLayer);

    m_player1->resetObject();
    if (m_isDualMode) {
        m_player2->resetObject();
    }
    *(int8_t *)(this + 0x564) = false;

    auto adjustedGroundY = m_bottomGround->getGroundY() + 1;

    cocos2d::CCPoint newBottomGround(0, -adjustedGroundY);
    cocos2d::CCPoint newTopGround(0, adjustedGroundY);

    m_bottomGround->deactivateGround();
    m_topGround->deactivateGround();

    m_lockGroundToCamera = false;
    m_groundRestriction = 90.000000f;

    m_topGround->setVisible(false);

    m_bottomGround->setPosition(newBottomGround);
    m_topGround->setPosition(newTopGround);

    m_lockGroundToCamera = false; // lol im not kidding

    this->prepareSpawnObjects();

    *(this + 0x660)->stopAllActions(*(this + 0x660));
    *(this + 0x660)->setVisible(false);

    auto winSize = cocos2d::CCDirector::sharedDirector()->getWinSize();
    m_cameraPosition.y = 90.0 + m_player1->getPosition() - winSize.y;
    this->updateCamera(0.0);

    if (m_fullReset) {
        for (int i = m_firstVisibleSection; i <= m_lastVisibleSection; ++i) {
            auto objs = m_sectionObjects->objectAtIndex(i);
            for (int j = 0; j < objs->count(); ++j) {
                objs->objectAtIndex(i)->deactivateObject(true);
            }
        }
    }

    this->updateVisibility();
    this->toggleDualMode(this, nullptr, false, nullptr, false);
    this->loadDefaultColors();

    if (m_checkpoints->count()) {
        auto lastCheckpoint = m_checkpoints->lastObject(m_checkpoints);
        this->loadFromCheckpoint(lastCheckpoint);

        if (m_startPosCheckpoint) {
            this->loadUpToPosition(m_player1->getPosition());
        }
    } else if (m_startPosCheckpoint) {
        this->loadFromCheckpoint(m_startPosCheckpoint);
    } else {
        auto levelSettings = m_levelSettings;
        if (m_startPos) {
            m_startPosCheckpoint = this->createCheckpoint();
            m_startPosCheckpoint->retain();

            levelSettings = m_startPos->m_levelSettings;
        } else {
            this->checkSpawnObjects();
        }

        this->setupLevelStart(this, levelSettings);
    }

    m_player1->m_position = m_player1->getPosition();
    m_player1->setLastPosition(m_player1->getPosition());

    if (m_isDualMode) {
        m_player2->m_position = m_player2->getPosition();
        m_player2->setLastPosition(m_player2->getPosition());
    }

    this->stopActionByTag(0x14);

    double seed = rand() / RAND_MAX * 1000.0;
    m_dontSaveSeed = seed;
    m_dontSaveRand = seed;

    if (m_isPracticeMode) {
        m_antiCheatPassed = true;
        *(int32_t *)(this + 0x4d8) = 1;

        m_dontSaveRand++;
    } else {
        m_antiCheatPassed = false;
        *(int32_t *)(this + 0x4d8) = 0;

        double acDelay = rand() / RAND_MAX * 5.0 + 5.0;

        auto dt = cocos2d::CCDelayTime::create(acDelay);
        auto cf = cocos2d::CCCallFunc::create(this, &PlayLayer::vfDChk());

        auto seq = cocos2d::CCSequence::create(dt, cf, nullptr);
        seq->setTag(0x14);

        if (m_antiCheatObject)
            m_antiCheatObject->setStartPos(m_player1->getPosition());

        this->runAction(seq);
    }

    this->stopActionByTag(0x13);
    m_isCameraShaking = false;
    this->updateLevelColors();
    this->updateCamera(0.0);
    this->updateVisibility();
    this->updateAttempts();

    GameStatsManager::sharedState()->incrementStat("2");

    m_level->m_attempts = m_level->m_attemptsRand - m_level->m_attemptsSeed + 1;
    m_level->m_attemptsSeed = rand() / RAND_MAX * 1000.0;
    m_level->m_attemptsRand = m_level->m_attemptsSeed + m_level->m_attempts;

    this->updateProgressbar();
    this->refreshCounterLabels();

    if (m_debugPauseOff) {
        this->startMusic();
    }

    if (GameManager::sharedState()->m_recordGameplay) {
        // would exist on mobile platforms
    }

    *(int8_t *)(this + 0x748) = false;
    *(int8_t *)(this + 0x73a) = false;
}
