PlayLayer::resetLevel() {
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
    m_cameraShakeOffset g_10069c5b0;
    this->stopActionByTag(0xa);
    this->stopActionByTag(0xb);
    m_camera4f0 = 0;
    m_cameraXLocked = false;
    m_cameraYLocked = false;
    if (!GM->m_ldm) {
        m_hasGlitter = false;
        m_particleSystem->stopSystem();
    }
    m_isDead = false;
    m_startCameraAtCorner = *(int8_t *)(this + 0x748);
    m_pickedUpItems->removeAllObjects();
    *(this + 0x540)->removeAllObjects();
    *(this + 0x650)->removeAllObjects();

    for (int i = 0; rbx < m_objects->count(); ++rbx) {
        GameObject* obj = m_objects->objectAtIndex(i);
        
        auto oldPosition = obj->getRealPosition(obj);
        obj->resetObject(obj);
        obj->m_activeEnterEffect = 1;

        auto oldSection = obj->getSectionIdx();
        this->reorderObjectSection(obj);
        auto newSection = obj->getSectionIdx();

        if (oldSection != newSection) {
            rcx = m_firstVisibleSection;
            rax = m_lastVisibleSection;

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

    m_player1->resetObject(rdi);
    if (m_isDualMode) {
        m_player2->resetObject(rdi);
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

    if (*(int8_t *)(this + 0x504)) {
        for (int i = m_firstVisibleSection; i <= m_lastVisibleSection; ++i) {
            auto objs = m_sectionObjects->objectAtIndex(i);
            for (int j = 0; j < objs->count(); ++j) {
                objs->objectAtIndex(i)->deactivateObject(true);
            }
        }
    }
    rax = PlayLayer::updateVisibility(this);
    rax = PlayLayer::toggleDualMode(this, 0x0, 0x0, 0x0, 0x0);
    rax = PlayLayer::loadDefaultColors(this);
    if (m_checkpoints->count() != 0x0) {
        rax = cocos2d::CCArray::lastObject(m_checkpoints);
        rax = PlayLayer::loadFromCheckpoint(this, rax);
    }
    if (m_checkpoints->count() != 0x0) goto loc_100072274;

loc_100072238:
    rax = m_startPos;
    if (rax == 0x0) goto loc_10007225a;

loc_100072244:
    rsi = *(this + 0x528);
    if (rsi == 0x0) goto loc_100072263;

loc_100072250:
    rax = PlayLayer::loadFromCheckpoint(this, rsi);
    goto loc_100072274;

loc_100072274:
    rbx = m_player1;
    rax = *rbx;
    rax = (*(rax + 0xc0))(rbx);
    rax = cocos2d::CCPoint::CCPoint(var_60, rax);
    rax = cocos2d::CCPoint::operator=(rbx + 0x7c8, var_60);
    if (m_isDualMode != 0x0) {
        rbx = m_player2;
        rax = *rbx;
        rax = (*(rax + 0xc0))(rbx);
        rax = cocos2d::CCPoint::CCPoint(var_58, rax);
        rax = cocos2d::CCPoint::operator=(rbx + 0x7c8, var_58);
    }
    rbx = m_player1;
    rax = *rbx;
    rax = (*(rax + 0xc0))(rbx);
    rax = GameObject::setLastPosition(rbx, rax);
    if (m_isDualMode != 0x0) {
        rbx = m_player2;
        rax = *rbx;
        rax = (*(rax + 0xc0))(rbx);
        rax = GameObject::setLastPosition(rbx, rax);
    }
    if (m_checkpoints->count() == 0x0) {
        if ((m_startPos != 0x0) && (*(this + 0x528) == 0x0)) {
            rdi = m_player1;
            xmm0 = *(int32_t *)rdi->getPosition(rdi);
            rax = GJBaseGameLayer::loadUpToPosition(this);
        }
    }
    this->stopActionByTag(0x14);
    if (m_isPracticeMode != 0x0) {
        *(int8_t *)(this + 0x7e8) = true;
        *(int32_t *)(this + 0x4d8) = 1;
        rax = rand();
        rax = intrinsic_cvttss2si(rax, intrinsic_mulss(intrinsic_mulss(intrinsic_cvtsi2ss(0x0, rax), *(int32_t *)its 0.0), 1000.00));
        m_dontSaveSeed = rax;
        m_dontSaveRand = rax + 1;
    } else {
        *(int8_t *)(this + 0x7e8) = false;
        *(int32_t *)(this + 0x4d8) = 0;
        rax = rand();
        rax = intrinsic_cvttss2si(rax, intrinsic_mulss(intrinsic_mulss(intrinsic_cvtsi2ss(0x0, rax), *(int32_t *)its 0.0), 1000.00));
        m_dontSaveSeed = rax;
        m_dontSaveRand = rax;
        xmm0 = intrinsic_cvtsi2ss(0x0, rand());
        xmm0 *= *(int32_t *)its 0.0;
        xmm1 = 5.0;
        xmm0 *= xmm1;
        xmm0 += xmm1;
        rdx = 0;
        rax = 0;
        rdi = cocos2d::CCDelayTime::create();
        rsi = cocos2d::CCCallFunc::create(this, PlayLayer::vfDChk(), 0x0);
        r15 = cocos2d::CCSequence::create();
        rax = *r15;
        rax = (*(rax + 0x48))(r15, 0x14);
        rbx = *(this + 0x7e0);
        if (rbx != 0x0) {
            r13 = *(*rbx + 0x520);
            rdi = m_player1;
            rax = *rdi;
            rax = (*(rax + 0xc0))(rdi);
            rax = cocos2d::CCPoint::CCPoint(var_50, rax);
            rax = (r13)(rbx, var_50);
        }
        rax = _ZN7cocos2d6CCNode9runActionEPNS_8CCActionPvE(this, r15);
    }
    this->stopActionByTag(0x13);
    m_isCameraShaking = 0;
    if ((m_startPos == 0x0) && (m_checkpoints->count() == 0x0)) {
        rax = GJBaseGameLayer::checkSpawnObjects(this, 0x13);
    }
    rax = PlayLayer::updateLevelColors(this);
    xmm0 = 0;
    rax = PlayLayer::updateCamera(this);
    rax = PlayLayer::updateVisibility(this);
    rax = PlayLayer::updateAttempts(this);
    rsi = "2";
    rdi = GameStatsManager::sharedState();
    rax =  _ZN16GameStatsManager13incrementStatEPvPKc();
    rbx = m_level;
    r15 = *(int32_t *)(rbx + 0x1dc);
    r15 = r15 - *(int32_t *)(rbx + 0x1e0);
    *(int32_t *)(rbx + 0x1e4) = r15 + 1;
    rax = rand();
    rax = intrinsic_cvttss2si(rax, intrinsic_mulss(intrinsic_mulss(intrinsic_cvtsi2ss(0x0, rax), *(int32_t *)its 0.0), 1000.00));
    *(int32_t *)(rbx + 0x1e0) = rax;
    *(int32_t *)(rbx + 0x1dc) = rax + r15 + 1;
    rax = PlayLayer::updateProgressbar(this);
    rax = GJBaseGameLayer::refreshCounterLabels(this);
    if ((m_startPos != 0x0) && (*(this + 0x528) == 0x0)) {
        rax = PlayLayer::createCheckpoint(this);
        *(this + 0x528) = rax;
        rax = cocos2d::CCObject::retain(rax);
    }
    if (*(int8_t *)(this + 0x4dc) != 0x0) {
        rax = PlayLayer::startMusic(this);
    }
    rax = GameManager::sharedState();
    if (*(int8_t *)(rax + 0x29f) == 0x0) goto loc_1000725fc;

loc_1000725d3:
    if (m_isPracticeMode != 0x0) goto loc_100072606;

loc_1000725dd:
    if (m_isTestMode == 0x0) {
        this->stopActionByTag(0x12);
        *(int8_t *)(this + 0x77d) = false;
    }
    goto loc_1000725fc;

loc_1000725fc:
    if (m_isPracticeMode != 0x0) {
        *(int8_t *)(this + 0x7e9) = true;
    } else {
        *(int8_t *)(this + 0x7e9) = false;
        xmm0 = intrinsic_cvtsi2ss(0x0, rand());
        xmm0 *= *(int32_t *)its 0.0;
        xmm1 = 5.0;
        xmm0 *= xmm1;
        xmm0 += xmm1;
        rdx = 0;
        rax = 0;
        rdi = cocos2d::CCDelayTime::create();
        rsi = cocos2d::CCCallFunc::create(this, nothing, 0x0);
        rbx = cocos2d::CCSequence::create();
        rax = *rbx;
        rax = (*(rax + 0x48))(rbx, 0x15);
        rax = _ZN7cocos2d6CCNode9runActionEPNS_8CCActionPvE(this, rbx);
    }
    goto loc_100072683;

loc_100072683:
    *(int8_t *)(this + 0x748) = false;
    *(int8_t *)(this + 0x73a) = false;
    return rax;

loc_100072606:
    *(int8_t *)(this + 0x7e9) = true;
    goto loc_100072683;

loc_100072263:
    rax = rax + 0x5e0;
    goto loc_100072269;

loc_100072269:
    rax = PlayLayer::setupLevelStart(this, *rax, 0x0, 0x0);
    goto loc_100072274;

loc_10007225a:
    rax = m_levelSettings;
    goto loc_100072269;
}

