#define GRAV_MOD (m_isUpsideDown ? -1 : 1);

void PlayerObject::updateJump(PlayerObject *this, float dt) {
    /*_BOOL4 m_isRobot;               // w1
    double gravity;                 // d10
    float m_gravityMod;             // s0
    float v16;                      // s9
    float float_b;                  // s10
    _BOOL4 m_platformerMovingLeft;  // w0
    unsigned int v19;               // w21
    int v20;                        // w2
    int v21;                        // w0
    double v22;                     // d0
    double v23;                     // d1
    GJRobotSprite *m_robotSprite;   // x22
    std::string v26;                // x1
    float m_vehicleSize;            // s3
    _BOOL4 m_isUpsideDown;          // w1
    double m_yVelocity;             // d1
    float v30;                      // s0
    bool v31;                       // nf
    bool v32;                       // cc
    float v33;                      // s2
    float v34;                      // s10
    int v35;                        // w0
    double v36;                     // d1
    double v37;                     // d0
    float m_slopeVelocity;          // s0
    float v39;                      // s10
    double v40;                     // d0
    float v41;                      // s10
    float v42;                      // s13
    int v43;                        // w0
    double v44;                     // d1
    double v45;                     // d0
    double v46;                     // d0
    bool IsFallingBugged;           // w0
    bool m_touchedPad;              // w1
    float slopeAngleDegrees;        // s0
    _BOOL4 m_jumpBuffered;          // w0
    float v51;                      // s12
    float v52;                      // s10
    float float_c_times_dt;         // s8
    int flipMod;                    // w0 MAPDST
    GJSpiderSprite *m_spiderSprite; // x22
    std::string v56;                // x1
    PlayerObject_vtbl *__vtable;    // x1
    const cocos2d::CCPoint *(__fastcall * getPosition)(cocos2d::CCNode *
                                                                                                         __hidden); // x1
    cocos2d::CCPoint *position;                                   // x0
    _BOOL4 isRobot;                                               // w1
    GJSpiderSprite *spiderSprite;                                 // x22
    void *v63;                                                    // x0
    unsigned int *v64;                                            // x2
    int v65;                                                      // w1
    float v66;                                                    // s12
    float v67;                                                    // s9
    int v68;                                                      // w0
    int v69;                                                      // w0
    _BOOL4 v70;                                                   // w0
    unsigned int m_isPlatformer;                                  // w1
    double m_totalTime;                                           // x0
    float yStart;                                                 // s8
    unsigned int jumpRelatedAC2Not213;                            // w21
    double platXSpeed;                                            // d0
    double totalSpeed;                                            // d1
    int m_maybeSlidingTime;                                       // w2
    float slopeVelocity;                                          // s8
    float velMult;                                                // s8
    float ModifiedSlopeYVel;                                      // s0
    double velMult_d;                                             // d0
    std::string jumpStr;                                          // x1
    double v86;                                                   // d0
    double v87;                                                   // d0
    double m_accelerationOrSpeed;                                 // d9
    float v90;                                                    // s0
    float v91;                                                    // s1
    double v92;                                                   // d8
    double v93;                                                   // d8
    double v94;                                                   // d0
    GJRobotSprite *robotSprite;                                   // x22 MAPDST
    std::string fallStr;                                          // x1 MAPDST
    void *v97;                                                    // x0
    double yVelocityTmp;                                          // d0 MAPDST
    GameManager *gm;                                              // x0
    unsigned int *v100;                                           // x2
    int v101;                                                     // w1
    __int64 v102; // [xsp+90h] [xbp+90h] BYREF*/

    unsigned rightBtn = this->m_rightBtn;
    unsigned leftBtn = this->m_leftBtn;
    if (this->m_rightBtn && this->m_leftBtn) {
        rightBtn = !this->m_leftPressedFirst;
        leftBtn = this->m_leftPressedFirst;
    }

    if (this->m_isPlatformer && this->m_isOnSlope && fabsf(this->m_slopeAngleRadians * 57.296) >= (this->m_currentSlope->m_isIceBlock ? 40.0 : 80.0)) {
        this->m_isOnGround = false;
    }

    bool onGround = this->m_isOnGround;
    //gravity = this->m_gravity;

    int seed = (rand() / (float)RAND_MAX) * 1000;
    int jumpRelated = this->m_isOnGround ? 213 : 0;
    this->m_jumpRelatedAC2.value = jumpRelated;
    this->m_jumpRelatedAC2.seed = seed;
    this->m_jumpRelatedAC2.random = jumpRelated + jumpRelatedSeed;

    bool jumpBufferedAndRingJump = this->m_jumpBuffered && (this->m_stateRingJump || !this->m_isRobot);

    float usedGravity = (this->m_isBall || this->isFlying() || this->m_isSpider ? 0.9582 : this->m_gravity);

    m_gravityMod = this->m_gravityMod;
    float float_c = usedGravity * m_gravityMod;

    v16 = 1.0;
    if (this->m_vehicleSize != 1.0)
        v16 = 0.8;

    if (this->isFlying()) {
        m_vehicleSize = this->m_vehicleSize;

        if (m_vehicleSize == 1.0) {
            v30 = 8.0 / v16;
            v33 = -6.4 / v16;
        } else {
            v33 = -7.5294;
            v30 = 9.4118;
            v16 = 0.85;
        }

        if (this->m_isUpsideDown) {
            if (m_yVelocity <= 0.0; && m_yVelocity > -v30)
                this->m_isAccelerating = false;

            if (m_yVelocity >= 0.0 && m_yVelocity < -v33)
                this->m_isAccelerating = false;
        } else {
            if (m_yVelocity >= 0.0 && m_yVelocity < v30)
                this->m_isAccelerating = false;

            if (m_yVelocity <= 0.0 && m_yVelocity > v33)
                this->m_isAccelerating = false;
        }

        if (!this->m_isShip) {
            if (!this->m_isBird) {
                if (this->m_isSwing) {
                    if (this->m_stateRingJump && this->m_jumpBuffered) {
                        v66 = m_yVelocity;
                        this->m_stateRingJump = 0;
                        this->flipGravity(!m_isUpsideDown, 1);
                        this->setYVelocity((float)(v66 * 0.8), 10);
                        if (this->m_gameLayer)
                            this->gameEventTriggered(20, 0);
                        m_vehicleSize = this->m_vehicleSize;
                    }
                    if (m_vehicleSize == 1.0)
                        v67 = 0.4;
                    else
                        v67 = 0.6;
                    v68 = this->flipMod();
                    PlayerObject::addToYVelocity(
                            this,
                            (float)-(float)((float)((float)(float_c * dt) * (float)v68) *
                                                            v67),
                            67);
                    v42 = 1.0;
                    v16 = 1.0;
                    if (this->m_jumpBuffered) {
                        this->m_isOnGround2 = 0;
                        v16 = 1.0;
                    }
                } else {
                    v90 = (float)this->flipMod() * 8.0;
                    if (this->m_jumpBuffered)
                        v91 = 1.0;
                    else
                        v91 = -1.0;
                    this->setYVelocity((float)(v90 * v91), 11);
                    v92 = this->m_playerSpeed * this->m_speedMultiplier;
                    v93 = v92 * (double)this->flipMod();
                    if (this->m_jumpBuffered)
                        v94 = 1.0;
                    else
                        v94 = -1.0;
                    this->setYVelocity(v93 * v94, 12);
                    if (!this->m_gameLayer || this->m_wasJumpBuffered == this->m_jumpBuffered) {
                        v42 = 0.8;
                    } else {
                        if (this->m_jumpBuffered)
                            this->gameEventTriggered(21, 0);
                        else
                            this->gameEventTriggered(22, 0);
                        v42 = 0.8;
                    }
                }
            } else if (this->m_stateRingJump && this->m_jumpBuffered) {
                this->m_stateRingJump = 0;
                if (m_vehicleSize == 1.0)
                    v34 = 7.0;
                else
                    v34 = 8.0;
                v35 = this->flipMod();
                v36 = this->m_yVelocity;
                v37 = v35 * v34 * v16;
                if ((this->m_isUpsideDown ? v37 < v36 : v37 > v36)) {
                    this->setYVelocity(v37, 7);
                    if (this->m_wasOnSlope || this->m_isOnSlope) {
                        m_slopeVelocity = this->m_slopeVelocity;
                        if (m_slopeVelocity > 0.0) {
                            v39 = this->m_yVelocity * 1.39999998;
                            this->addToYVelocity(m_slopeVelocity * 0.5, 8);
                            v40 = v39;
                            if (this->m_yVelocity <= v39)
                                v40 = this->m_yVelocity;
                            this->setYVelocity(v40, 9);
                        }
                    }
                }
                this->playBurstEffect();
                if (this->m_gameLayer)
                    this->gameEventTriggered(15, 0);
            }

            v42 = 0.8;
            if (this->playerIsFallingBugged()) {
                v41 = 0.8;
            } else {
                v41 = 1.2;
            }
            v43 = this->flipMod();
            this->addToYVelocity(-float_c * dt * v43 * v41 * 0.5 / v16, 66);
            if (this->m_jumpBuffered)
                this->m_isOnGround2 = 0;
        } else {
            v42 = 0.8;

            if (this->m_jumpBuffered) {
                if (this->m_isAccelerating && (m_isUpsideDown ? m_yVelocity <= 0.0 : m_yVelocity >= 0.0)) {
                    v51 = 0.8;
                } else {
                    v51 = -1.0;
                }
            } else if (!this->m_isAccelerating) {
                v51 = 0.8;

                if (!this->playerIsFallingBugged()) {
                    v51 = 1.2;
                }
            }

            v52 = this->playerIsFallingBugged() ? 0.5 : 0.4;

            if (this->m_isPlatformer || this->m_isAccelerating) {
                if (this->m_isPlatformer)
                    float_c = float_c * 0.8;

                if (v51 < 0.0) {
                    float_c = usedGravity;
                }
            } else if (this->m_jumpBuffered) {
                float_c = usedGravity;
            } else {
                v52 = 0.4;
            }

            v69 = this->flipMod();
            this->addToYVelocity(-v51 * float_c * dt * v69 * v52 / v16, 64);
            v70 = this->m_jumpBuffered;
            if (this->m_jumpBuffered)
                this->m_isOnGround2 = 0;
            if (this->m_gameLayer && this->m_wasJumpBuffered != v70) {
                if (v70)
                    this->gameEventTriggered(16, 0);
                else
                    this->gameEventTriggered(17, 0);
            }
        }

        if (!this->m_isAccelerating && !this->m_isDart) {
            v44 = this->m_yVelocity;
            if (this->m_isUpsideDown) {
                v86 = (float)(-8.0 / v16);
                if (v44 >= v86)
                    v86 = this->m_yVelocity;
                this->setYVelocity(v86, 15);
                v87 = (float)((float)(v42 * 8.0) / v16);
                if (this->m_yVelocity <= v87)
                    v87 = this->m_yVelocity;
                this->setYVelocity(v87, 16);
            } else {
                v45 = (float)((float)(v42 * -8.0) / v16);
                if (v44 >= v45)
                    v45 = this->m_yVelocity;
                this->setYVelocity(v45, 13);
                v46 = (float)(8.0 / v16);
                if (this->m_yVelocity <= v46)
                    v46 = this->m_yVelocity;
                this->setYVelocity(v46, 14);
            }
        }
        IsFallingBugged = this->playerIsFallingBugged();
        m_touchedPad = this->m_touchedPad;
        if (IsFallingBugged)
            this->m_maybeIsBoosted = 0;
    } else {
        if (this->m_isBall || this->m_isSpider || this->m_isSwing) {
            float_b = 0.6;
        } else if (this->m_isRobot) {
            float_b = 0.9;
        } else {
            float_b = 1.0;
        }

        v20 = leftBtn < this->m_platformerMovingLeft || this->m_platformerMovingRight > rightBtn;
        if (v20 && this->m_isSlidingRight != this->m_platformerMovingLeft && !this->m_slopeSlidingMaybeRotated) {
            this->m_maybeSlidingTime = 0;
        }
        v19 = (v20 ? this->m_maybeSlidingTime <= 1 : true);

        if (this->m_isOnGround && jumpBufferedAndRingJump && !this->m_isDashing && (!this->m_isPlatformer || v19)) {
            if (this->m_isSpider) {
                this->spiderTestJump(0);
            } else {
                this->m_isOnGround2 = 0;
                this->m_maybeIsBoosted = 1;
                this->m_isOnGround = 0;
                this->m_stateRingJump = 0;
                this->m_touchedPad = 0;
                this->m_accelerationOrSpeed = 0.0;
                if (!m_platformerMovingLeft && !this->m_platformerMovingRight &&
                        this->m_maybeSlidingTime > 0) {
                    m_totalTime = this->m_totalTime;
                    this->m_maybeSlidingTime = 0;
                    this->m_maybeSlidingStartTime = m_totalTime;
                }
                yStart = this->m_yStart;
                if (this->m_isRobot)
                    yStart = yStart * 0.5;
                if (this->m_jumpRelatedAC2.random - this->m_jumpRelatedAC2.seed == 213) {
                    jumpRelatedAC2Not213 = 0;
                } else {
                    yStart = 9999.0;
                    jumpRelatedAC2Not213 = 1;
                    this->m_isAccelerating = 1;
                }
                if (v20 && m_isPlatformer) {
                    if (this->m_isMoving &&
                            (platXSpeed = fabs(this->m_platformerXVelocity),
                             totalSpeed = this->m_playerSpeed * this->m_speedMultiplier,
                             platXSpeed > totalSpeed)) {
                        m_maybeSlidingTime = this->m_maybeSlidingTime;
                        yStart = yStart + platXSpeed / totalSpeed;
                    } else {
                        m_maybeSlidingTime = this->m_maybeSlidingTime;
                        if (m_maybeSlidingTime > 0)
                            yStart =
                                    yStart * (float)(1.0 - (float)((float)m_maybeSlidingTime * 0.3));
                    }
                    this->m_maybeSlidingTime = m_maybeSlidingTime + 1;
                }
                flipMod = this->flipMod();
                this->setYVelocity(flipMod * yStart * v16, 2);
                if (this->m_wasOnSlope || this->m_isOnSlope) {
                    slopeVelocity = this->m_slopeVelocity;
                    if ((float)(slopeVelocity * (float)this->flipMod()) > 0.0 && (!this->m_isPlatformer || fabs(this->m_platformerXVelocity) > 4.0)) {
                        velMult = this->m_yVelocity * 1.39999998;
                        ModifiedSlopeYVel = this->getModifiedSlopeYVel();
                        if (this->m_isBall)
                            ModifiedSlopeYVel = this->m_slopeVelocity;
                        this->addToYVelocity((float)(ModifiedSlopeYVel * 0.25),
                                                                                 60);
                        velMult_d = velMult;
                        yVelocityTmp = this->m_yVelocity;
                        if (this->m_isUpsideDown) {
                            if (yVelocityTmp >= velMult)
                                velMult_d = this->m_yVelocity;
                            this->setYVelocity(velMult_d, 4);
                        } else {
                            if (yVelocityTmp <= velMult)
                                velMult_d = this->m_yVelocity;
                            this->setYVelocity(velMult_d, 3);
                        }
                    }
                }
                this->m_shouldTryPlacingCheckpoint = 1;
                this->m_lastJumpTime = sub_615B20();
                this->incrementJumps();
                if (this->m_isBall) {
                    this->flipGravity(!this->m_isUpsideDown, 1);
                    this->m_isOnGround3 = 0;
                    yVelocityTmp = this->m_yVelocity;
                    this->m_jumpBuffered = 0;
                    this->m_yVelocity = yVelocityTmp * 0.600000024;
                } else if (this->m_isRobot) {
                    this->m_robotSprite->tweenToAnimation("jump_loop", 0.1);
                } else if (!this->m_isSpider) {
                    this->runRotateAction(1, 11);
                }

                if (this->m_gameLayer) {
                    if (this->isInNormalMode()) {
                        this->gameEventTriggered(12, 0);
                    } else if (this->m_isRobot) {
                        this->gameEventTriggered(13, 0);
                    } else if (this->m_isBall) {
                        this->gameEventTriggered(19, 0);
                    }
                }
                if (!jumpRelatedAC2Not213 && !onGround) {
                    GM->setGameVariable("0055", true);
                }
                if (this->m_isPlatformer) {
                    this->animatePlatformerJump(1.0);
                }
            }
        } else {
            if (this->m_isOnGround && !this->m_maybeIsBoosted) {
                this->m_fallStartY = this->getPositionY();
            }
            if (this->m_maybeIsBoosted) {
                float float_d = this->flipMod() * float_c * dt * float_b;
                if (this->m_isRobot && this->m_jumpBuffered && !this->m_touchedPad && this->m_accelerationOrSpeed < 1.5) {
                    this->m_accelerationOrSpeed += dt / 10.;
                    this->addToYVelocity(float_d, 61);
                }
                this->addToYVelocity(-float_d, 62);

                if (this->m_isRobot && this->m_touchedPad && !this->m_wasRobotJump && this->m_gameLayer)
                    this->gameEventTriggered(GJGameEvent::RobotBoostStop, 0);

                if (this->playerIsFallingBugged() || (this->m_isPlatformer && this->playerIsMovingUp())) {
                    this->m_maybeIsBoosted = false;
                    this->m_maybeIsFalling = true;
                    this->m_isOnGround2 = false;
                    this->m_fallStartY = this->getPositionY();

                    if (this->m_isRobot) {
                        this->m_robotSprite->tweenToAnimation("fall_loop", 0.1);
                        if (!this->m_touchedPad && this->m_gameLayer) {
                            this->gameEventTriggered(GJGameEvent::RobotBoostStop, 0);
                        }
                    } else if (this->m_isSpider) {
                        this->m_spiderSprite->tweenToAnimation("fall_loop", 0.1);
                    }
                }
            } else {
                if (this->playerIsFallingBugged() && (!this->m_isPlatformer || this->m_totalTime - this->m_lastLandTime >= 0.0500000045 || !v19)) {
                    this->m_isOnGround = 0;
                }

                PlayerObject::addToYVelocity(this, -float_c * dt * this->flipMod() * float_b, 63);

                if (this->m_isUpsideDown) {
                    this->setYVelocity(std::min(this->m_yVelocity, 15), 6);
                } else {
                    this->setYVelocity(std::max(this->m_yVelocity, -15), 5);
                }

                if (this->playerIsFalling(-0.25) && !this->m_isBall && !this->m_isSpider && !this->m_isRobot && !this->m_isRotating && !this->m_isOnSlope && !this->m_isCollidingWithSlope && (!this->m_isPlatformer || !this->m_isOnGround2)) {
                    this->runRotateAction(1, 12);
                }

                if (this->playerIsFallingBugged() && GRAV_MOD * this->m_yVelocity < -4.0) {
                    GJRobotSprite* tweened = (this->m_isSpider ? this->m_spiderSprite : 
                                                (this->m_isRobot ? this->m_robotSprite : nullptr)
                                             );

                    if (tweened && this->m_isOnGround2 && !this->m_maybeSpriteRelated) {
                        tweened->tweenToAnimation("fall_loop", 0.1);
                    }
                    this->m_isOnGround2 = false;
                }
            }
        }
    }

    this->m_wasJumpBuffered = this->m_jumpBuffered;
    this->m_wasRobotJump = this->m_touchedPad;
    return;
}