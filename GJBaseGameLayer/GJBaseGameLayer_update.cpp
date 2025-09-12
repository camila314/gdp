/// GJBaseGameLayer
// m_resumeAudioTimer: 0x30fc
// m_audioNeedsResume: 0x348e
// m_gameStarted: 0x30b0
// m_deltaRemainder: 0x30a8 (double)
// m_totalTime: 0x390 (double)
// m_attemptWarpedTime: 0x398
// m_totalWarpedTime: 0x3a0 (double)
// m_timewarp: 0x330
// m_isTwoPlayer: 0x3ea
// m_fixedStartCam: 0x308a
// m_cameraVelocity: 0x474
// m_effectManager: 0x840
// m_gameState: 0x1a8 (.zoomLevel)
// m_audioEffects: 0x720 (std::unordered_map)
// m_playerDied: 0x30a2
// m_editorIgnoreDamage: 0x78e
// m_someDebugVar: 0x2f24
// m_prevMaxPortalY: 0x6b4
// m_practiceMode: 0x3048
// m_levelReset: 0x30b1
// m_isPlatformer: 0x2f26
// m_shakeCountdown: 0x4c0
// m_isShake: 0x4bd
// m_flipAmount: 0x3e4
// m_isFlipping: 0x3e9
// m_flipAmountDest: 0x305c
// m_cameraPos: 0x3d8
// m_audioEffectTimer: 0x33ec
// m_queuedTimeMod: 0x480
// m_timeMod: 0x484
// m_editorClicked: 0x2f10

/// PlayerObject
// m_rotation: 0x137
// m_didReset: 0x9da
// m_position: 0xa28
// m_shipRotation: 0x9a8
// m_totalTime: 0xa38
// m_yVelocity: 0xa4c
// m_prevRotation: 0x9b8


/// GJEffectManager
// m_playerVelocity: 0x600
// m_cameraVelocity: 0x608
// m_p1RotVelocity: 0x610
// m_p2RotVelocity: 0x614


void GJBaseGameLayer::update(float delta) {
    auto ws = CCDirector::sharedDirector()->getWinSize();

    if (m_resumeAudioTimer < 1 && m_audioNeedsResume) {
        this->resumeAudio();
        m_audioNeedsResume = false;
    }

    if (m_gameStarted) {
        this->applyTimeWarp(m_timewarp);
        delta = this->getModifiedDelta(delta);
    } else {
        m_deltaRemainder = 0; 
    }

    float warpDelta = (delta / m_timewarp);

    if (m_gameStarted && m_resumeAudioTimer < 1) {
        if (delta > 0.0) {
            m_player1->m_bool_934 = false;
            m_player2->m_bool_934 = false;
            if (!m_player1->m_didReset) {
                m_player1->setPosition(m_player1->m_position);
            }
            if (m_isTwoPlayer && !m_player2->m_didReset) {
                m_player2->setPosition(m_player2->m_position);
            }
            int stepCount = fmax(1.0, (delta * 240.0) / fmin(m_timewarp, 1));
            m_editorClicked = false;
            if (!m_fixedStartCam && m_levelReset) {
                m_cameraVelocity.x = ws.width * 0.5 + -75.0 + 15.0;
            }
            m_levelReset = false;
            unknown_matmul(&this->m_unk345c, &this->m_unk342c, 0.1); // 0x10020396c

            bool hasDeltaRemainder = false;

            if (stepCount > 0) {
                float physicsDelta = delta / stepCount;
                float physicsSecond = (delta * 60.0) / stepCount;
                float warpedPhysicsDelta = (delta / m_timewarp) / stepCount;
                float prevTimewarp = m_timewarp;

                for (int stepIter = 0; stepIter < stepCount; ++stepIter) {
                    // i dont know what this is
                    this->m_unk342c = {0, 0, 0, 0};

                    m_totalTime += physicsDelta;
                    m_totalWarpedTime += warpedPhysicsDelta;
                    if (!this->m_bool_32b8)
                        this->m_double_32b0 += warpedPhysicsDelta;

                    this->updateAttemptTime(warpedPhysicsDelta);
                    m_player1->m_totalTime = m_totalTime;
                    m_player2->m_totalTime = m_totalTime;

                    this->m_map_2ea8.clear();
                    this->m_map_f48.clear();

                    m_effectManager->updateSpawnTriggers(physicsDelta);

                    if (m_queuedTimeMod != 0.0)
                        this->updateTimeMod(1, m_timeMod);
                    this->applyTimewarp(m_timewarp);

                    this->processCommands(physicsDelta);

                    m_player1->resetTouchedRings(false);
                    m_player1->resetCollisionLog(false);
                    if (m_isTwoPlayer) {
                        m_player2->resetTouchedRings(false);
                        m_player2->resetCollisionLog(false);
                    }

                    m_effectManager->preCollisionCheck();
                    this->m_map_f48.clear();

                    CCPoint velocity = m_player1->getPosition() - m_player1->getLastPosition();

                    if (m_playerDied) {
                        velocity = ccp(0, 0);
                    } else if (physicsSecond * 16.0 < ABS(velocity.y - m_player1->m_yVelocity)) {
                        velocity.y = 0;
                    }
                    m_effectManager->m_playerVelocity = velocity;
                    m_effectManager->m_cameraVelocity = ccp(-m_cameraVelocity.x, -m_cameraVelocity.y);

                    m_effectManager->m_p1RotVelocity = m_player1->getRotation() - m_player1->m_prevRotation;
                    m_effectManager->m_p2RotVelocity = m_player2->getRotation() - m_player2->m_prevRotation;

                    m_effectManager->updateTimers(physicsDelta, m_timewarp);
                    m_effectManager->prepareMoveActions(physicsDelta, stepIter < stepCount - 1);
                    m_effectManager->processMoveActionsStep(physicsDelta, stepIter == stepCount - 1);
                    m_effectManager->postMoveActions();

                    this->updateVerifyDamage();
                    this->updateCollisionBlocks();
                    if (!m_playerDied) {
                        m_player2->m_point_980 = m_player1->m_point_980;
                        m_player1->updateInternalActions(physicsDelta);
                        if (m_isTwoPlayer)
                            m_player2->updateInternalActions(physicsDelta);

                        m_player1->update(physicsSecond);
                        if (!m_player1->m_didReset && this->checkCollisions(m_player1, physicsSecond, m_someDebugVar) && m_someDebugVar && !m_editorIgnoreDamage)
                            this->playerTookDamage(m_player1);
                        m_player1->updateSpecial(physicsDelta);

                        if (m_isTwoPlayer) {
                            m_player2->update(physicsSecond);
                            if (!m_player2->m_didReset && this->checkCollisions(m_player2, physicsSecond, m_someDebugVar) && m_someDebugVar && !m_editorIgnoreDamage)
                                this->playerTookDamage(m_player2);
                            m_player2->updateSpecial(physicsDelta);
                        }

                        m_attemptWarpedTime += physicsDelta / m_timewarp;
                        this->checkSpawnObjects();

                        m_player1->m_rotation = m_player1->getRotation();
                        m_player2->m_rotation = m_player2->getRotation();

                        m_player1->updateRotation(physicsDelta * 60);
                        if (m_isTwoPlayer)
                            m_player2->updateRotation(physicsDelta * 60);

                        // why is there another one? IDK
                        m_player1->m_shipRotation = m_player1->getPosition();
                        if (m_isTwoPlayer)
                            m_player2->m_shipRotation = m_player2->getPosition();


                        this->updateSavePositionObjects();

                        m_prevMaxPortalY = this->getMaxPortalY();
                        this->checkForEnd();
                        stepRemainder = stepCount - stepIter - 1;
                        if (prevTimewarp != m_timewarp && stepRemainder > 0) {
                            deltaRemainder = physicsDelta * stepRemainder;

                            delta -= deltaRemainder;
                            m_deltaRemainder += deltaRemainder;
                            hasDeltaRemainder = true;
                            stepIter = stepCount; // loop will end
                        }

                        prevTimewarp = m_timewarp;
                    }

                    m_effectManager->postCollisionCheck();
                    this->checkRepellPlayer();
                    this->processStateObjects();

                    m_gameState.processStateTriggers();
                    m_gameState.updateTweenActions(physicsDelta);

                    this->updateCamera(physicsDelta * 60);
                    this->checkSnapshot();

                    if (m_practiceMode) {
                        m_player1->updateCheckpointTest();
                    }
                }
            }

            if (m_isPlatformer)
                this->updateSpecialLabels();
            this->updateTimerLabels();
            this->updateQueuedLabels();

            CCPoint p1FlipPos;
            CCPoint p2FlipPos;
            bool flipping = m_flipAmount != 0.0 && m_flipAmount != 1.0;

            if (!m_player1->m_didReset) {
                m_player1->m_position = m_player1->getPosition();

                if (m_isTwoPlayer)
                    m_player2->m_position = m_player2->getPosition();

                if (flipping) {
                    float flipAmt = (m_flipAmountDest == 1.0) ? m_flipAmount : 1.0 - m_flipAmount;
                    float cameraDist = m_player1->getPositionX() - this->m_cameraPos.x;
                    float visibleWidth = ws.width / m_gameState.zoomLevel;

                    float flipMult = (cameraDist * -2 + visibleWidth) * flipAmt;

                    p1FlipPos = m_player1->getPosition() + ccp(flipMult, 0);
                    if (m_isTwoPlayer)
                        p2FlipPos = m_player2->getPosition() + ccp(flipMult, 0);
                }
            }

            m_isShake = m_shakeCountdown > 0;
            if (m_isShake)
                m_shakeCountdown -= delta;

            m_effectManager->updateEffects(delta);
            m_player1->updateEffects(delta);
            m_player2->updateEffects(delta);

            this->updateGradientLayers();
            this->updateShaderLayer(delta);

            if (flipping) {
                m_player1->setPosition(p1FlipPos);
                if (m_isTwoPlayer)
                    m_player2->setPosition(p2FlipPos);
            }

            this->postUpdate(delta);
            this->updateGuideArt();
            this->updateProximityVolumeEffects();
            this->updateAudioVisualizer();

            if (!flipping && m_isFlipping)
                this->flipFinished();

            m_audioEffectTimer += delta;

            if (m_audioEffectTimer >= 1) {
                m_audioEffectTimer = 0;
                for (auto& [k, v] : m_audioEffects) {
                    if (FMODAudioEngine::sharedEngine()->isMusicPlaying(k)) {
                        m_audioEffects.erase(k);
                    }
                }
            }

            this->m_bool_2fd9 = 0;
            if (hasDeltaRemainder) {
                this->update(0);
            }
        }
    } else {
        m_totalTime += delta;
        m_totalWarpedTime += delta / m_timewarp;
        m_effectManager->updateEffects(delta);
        m_player1->updateEffects(delta);
        m_player2->updateEffects(delta);
        this->updateGradientLayers();
        this->updateShaderLayer(delta);
        this->postUpdate(delta);
        this->updateGuideArt();
        this->updateAudioVisualizer();
    }
}
