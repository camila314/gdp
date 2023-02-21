void PlayerObject::resetObject() {
    m_unk539 = true;
    m_collidedSlope = nullptr;
    m_unknown_730 = false;
    m_hasHitRing = false;
    m_unknown_540 = 0.0;
    m_unknown_538 = 0.0;
    m_unknown_554 = false;
    m_unknown_54c = 0.0;
    
    this->toggleVisibility(true);

    if (m_unk560 > 0.0) {
        m_unk560 = 0.0;

        this->setColor(m_unknown73e);
        m_iconSprite->setColor(m_unknown741);
        m_vehicleSprite->setColor(m_unknown741);
        m_robotSprite->updateColor02(m_unknown741);
        m_spiderSprite->updateColor02(m_unknown741);
    }

    m_unknown_b28 = 1;
    m_unknown_b20 = nullptr;
    m_unknown_b18 = nullptr;
    m_touchingRings->removeAllObjects();

    std::fill(m_unk6A4.begin(), m_unk6A4.end(), 0);

    this->stopDashing();
    this->deactivateStreak(false);

    if (m_checkpoint) {
        auto checkObj = m_checkpoint->getObject();
        PL->removeObjectFromSection(checkObj);
        checkObj->removeGlow();
        checkObj->removeMeAndCleanup();

        m_checkpoint->release();
        m_checkpoint = nullptr;
    }

    m_spiderSprite->stopActionByTag(9);
    m_spiderSprite->setScale(1.0);

    m_isCheckpointQueued = false;
    m_unknown73d = false;
    m_lastHitGround = PlayerObject::someSharedValue;
    m_lastPortal = nullptr;
    m_lastPortalLocation = PlayerObject::someSharedValue;
    m_isLocked = false;
    m_objectSnappedTo = nullptr;
    m_unk53b = false;
    m_isOnSlope = false;
    m_wasOnSlope2 = false;
    m_slopeVelocity = 0.0;
    m_collidedUUID = -1;
    m_unknown_728 = 0;
    m_hasHitPortal = false;
    m_slopeRotation = 0.0;
    m_unknown_569 = false;
    m_unknown_734 = 0;
    m_unknown_738 = 0;
    m_time = 0.0;
    m_isRising = false;
    m_unknown_578 = nullptr;
    m_collidedSlopeObj = nullptr;

    if (m_isInPlayLayer) {
        this->setPosition(PL->m_playerStartPosition);
    }

    m_yAccel = 0.0;
    this->flipGravity(false, false);
    this->toggleBirdMode(false);
    this->toggleRollMode(false);
    this->toggleRobotMode(false);
    this->toggleBirdMode(false);
    this->toggleDartMode(false);
    this->toggleSpiderMode(false);
    this->togglePlayerScale(false);
    this->stopActionByTag(0);
    this->stopActionByTag(0x1);

    m_unknown_568 = false;
    this->setRotation(0.0);
    m_isDead = false;
    this->stopActionByTag(3);
    this->setOpacity(255);
    this->toggleGhostEffect(0);

    if (!m_unk539 && m_isInPlayLayer && m_playerSpeed != 0.9) {
        PL->playSpeedParticle(0.9);
    }

    m_playerSpeed = 0.9;
    m_gravity = 0.958199;
    m_xAccel = 5.77;
    m_jumpAccel = 11.180032;

    this->updateRobotAnimationSpeed();
    if (m_isBall) {
        this->runRotateAction(false);
    }

    if (PL && !PL->m_unk49C && !m_unknown_7e0) {
        this->stopActionByTag(10);

        auto seq = cocos2d::CCSequence::create(
            cocos2d::CCBlink::create(0.4, 4),
            cocos2d::CCShow::create()
        );

        seq->setTag(10);
        this->runAction(seq);

        if (!GM->m_ldm) {
            this->runAction(CCSequence::create(
                cocos2d::CCDelayTime::create(0.0),
                cocos2d::CCCallFunc::create(this, &PlayerObject::spawnCircle)
            ));

            this->runAction(CCSequence::create(
                cocos2d::CCDelayTime::create(0.1),
                cocos2d::CCCallFunc::create(this, &PlayerObject::spawnCircle)
            ));

            this->runAction(CCSequence::create(
                cocos2d::CCDelayTime::create(0.2),
                cocos2d::CCCallFunc::create(this, &PlayerObject::spawnCircle)
            ));

            this->runAction(CCSequence::create(
                cocos2d::CCDelayTime::create(0.3),
                cocos2d::CCCallFunc::create(this, &PlayerObject::spawnCircle)
            ));
        }
    }

    this->resetStreak();
    this->levelFlipFinished();
    m_unk539 = false;

    if (m_unknown_721) {
        this->activateStreak();
    }
    return;
}
