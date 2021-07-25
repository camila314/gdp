void PlayerObject::ringJump(GameObject* ringObj) {
    if (!this->isDead && this->hasQueuedHold && !this->isDashing && this->isHolding2) {
        if (this->canHitCustomRing && (this->unknown_74a || ringObj->objectType != kCustomRing)) {
            return;
        }

        this->hasJustHitRing = true;
        this->untouchedRings->removeObject(ringObj);
        if (ringObj->objectType == kCustomRing) {
            this->unknown_74a = true;

            GJBL->objectTriggered(ringObj);
            this->hasQueuedHold = false;
        } else {
            this->canHitCustomRing = true;
            this->unknown_628 = true;

            if (ringObj->objectType == kGreenDashRing || ringObj->objectType == kPinkDashRing) {
                if (ringObj->objectType == kPinkDashRing) {
                    if (this->inPlayLayer) {
                        PL->flipGravity(this, !m_upsideDown, true);
                        PL->playGravityEffect(m_upsideDown);
                    } else {
                        if (EL) {
                            EL->flipGravity(this, !m_upsideDown, true);
                        } else {
                           this->flipGravity(!m_upsideDown, true);
                        }
                    }
                }
                this->startDashing(ringObj);
            } else if (ringObj->objectType == kBlackRing) {
                this->hasQueuedHold = false;
                float new_y_accel;
                if (this->isShip || this->isBird || this->isDart) {
                    new_y_accel = m_upsideDown ? 14 : -14;
                    if (this->isBird) {
                        new_y_accel *= 0.8;
                    }
                } else {
                    new_y_accel = m_upsideDown ? 15 : -15;
                    if (this->isSpider) {
                        new_y_accel *= 1.10;
                    }
                }
                this->yAccel = new_y_accel;

                if (this->isBall) {
                    this->runBallRotation2();
                } else {
                    this->runRotateAction(false, !m_upsideDown);
                }
                this->activateStreak();
                this->unimportant_7c1 = true;
                this->hitPortal = true;
                if (this->isBall) {
                    this->isHolding = false;
                }
            } else {
                this->isRising = true;
                this->isSliding = false;
                this->onGround = false;
                this->hasQueuedHold = false;
                float new_y_accel = this->jumpPower;
                if (ringObj->objectType == kRedRing) {
                    if (this->isShip) {
                        if (this->vehicleSize != 1.0)
                            new_y_accel *= 1.4;
                    } else if (this->isBird) {
                        if (this->vehicleSize == 1.0) {
                            new_y_accel *= 1.02; //i highly doubt the 0.02 extra *really mattered* that much
                        } else {
                            new_y_accel *= 1.36;
                        }
                    } else if (this->isBall) {
                        new_y_accel *= 1.34;
                    } else if (this->isRobot) {
                        new_y_accel *= 1.28;
                    } else if (this->isSpider) {
                        new_y_accel *= 1.34;
                    } else { //cube
                        new_y_accel *= 1.38;
                    }
                } else if(ringObj->objectType == kPinkRing) {
                    if (this->isShip) {
                        new_y_accel *= 1.37;
                    } else if (this->isBird) {
                        new_y_accel *= 0.42;
                    } else if (this->isBall) {
                        new_y_accel *= 0.77;
                    } else {
                        new_y_accel *= 0.72;
                    }
                } else if (ringObj->objectType == kGreenRing) {
                    if (this->isShip)
                        new_y_accel *= 0.7;

                    if (this->inPlayLayer) {
                        PL->flipGravity(this, !m_upsideDown, true);
                        PL->playGravityEffect(m_upsideDown);
                    } else {
                        if (EL) {
                            EL->flipGravity(this, !m_upsideDown, true);
                        } else {
                           this->flipGravity(!m_upsideDown, true);
                        }
                    }
                } else if (ringObj->objectType == kBlueRing) {
                    new_y_accel *= 0.8;
                } else {
                    if (this->isRobot) {
                        new_y_accel *= 0.9;
                    }
                }
                new_y_accel *= m_upsideDown ? -1.0 : 1.0;
                new_y_accel *= this->vehicleSize < 1.0 : 0.8 : 1.0;
                this->yAccel = new_y_accel;
                if (this->isBall) {
                    this->runBallRotation2();
                }
                else {
                    this->runRotateAction(false, !m_upsideDown);
                }
                this->lastHitGround = this->getPosition();
                this->activateStreak();
                this->unimportant_7c1 =true;
                if (this->isBall || this->isSpider) {
                    this->yAccel *= 0.7;
                    this->isHolding = false;
                }

                if (ringObj->objectType == kBlueRing) {
                    GJBL->flipGravity(this, !m_upsideDown, true);

                    if (this->inPlayLayer)
                        PL->playGravityEffect(m_upsideDown);
                    if (this->isRobot)
                        this->robotSprite->runAnimation("jump_start");
                }
                if (this->isSpider) {
                    this->spiderSprite->stopTween();
                    this->spiderSprite->animationManager->stopAnimations();
                    this->spiderSprite->tweenToAnimation("jump", 0.06);
                }
                if (ringObj->objectType == kRedRing)
                    this->hitPortal = true;
            } else {
                if (this->inPlayLayer) {
                    PL->flipGravity(this, !m_upsideDown, true);
                    PL->playGravityEffect(m_upsideDown);
                } else {
                    if (EL) {
                        EL->flipGravity(this, !m_upsideDown, true);
                    } else {
                       this->flipGravity(!m_upsideDown, true);
                    }
                }
            }
        }
    }
    if (!this->unnamed_629) {
        auto circleCol = ccc3(255,255,255); 
        if (this->inPlayLayer && !GM->lowDetail && !ringObj->hasBeenActivated()) {
            switch (ringObj->objectType) {
                case kBlueRing:
                    circleCol = ccc3(0,0,255);
                    break;
                case kPinkRing:
                    circleCol = ccc3(255,0,255);
                    break;
                case kGreenRing: 
                    circleCol = ccc3(0,255,0);
                case kGreenDashRing:
                case kPinkDashRing:
                case kBlackRing:
                    circleCol = PL->effectManager->activeColorForIndex(1007);
                case kRedRing:
                    circleCol = ccc3(255,100,0);
                case kCustomRing:
                    GameObject* obj;
                    if (ringObj->unk_sprite_350) {
                        obj = ringObj->unk_sprite_350;
                    } else {
                        obj = ringObj;
                    }
                    circleCol = obj->getColor();
                    break;
                default: // rob made yellow the default case
                    circleCol = ccc3(255,200,0);
            }
            auto circle = CCCircleWave::create(ringObj->objectType == kRedRing ? 42.0 : 35.0, 5.0, 0.35,true);
            circle->color = circleCol;
            circle->setPosition(circle, ringObj->getPosition());
            circle->followObject(ringObj, true);
            circle->delegate = PL;
            PL->addCircle(circle);
            this->unk_layer_798->addChild(circle, 0);
        }
    }
    ringObj->activatedByPlayer(this);
    ringObj->powerOffObject();

    if (this->inPlayLayer) {
        PL->incrementJumps();
        this->unimportant_7c0 = true;
    }
}
