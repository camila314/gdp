int PlayerObject::updateJump(float delta) {
    bool shouldJump = 0;

    bool onGround = this->isOnGround;
    double gravity = this->gravity;

    if (this->isRobot) {
            shouldJump = this->hasJustHeld & this->isHolding;
    }

    bool is_small = this->vehicleSize!=1.0;

    if (this->isShip || this->isBird || this->isDart) {
        double local_gravity = 0.958199;
        rdi = this->isShip;
        float size = is_small ? 0.85 : 1.0;

        if (this->isShip) {
            if (!this->hasHitPortal) {
                float sign = this->isUpsideDown ? -1.0 : 1.0;

                float multiplier = -1.0;
                float step = (gravity*2 == this->yAccel)? 0.5 : 0.4;
                if (!this->isHolding && shouldJump) {
                    multiplier = sign*this->yAccel < gravity*2*sign ? 1.2 : 0.8;
                    step = 0.4;
                }

                this->yAccel += (gravity * delta * sign * step * multiplier)/size;
                this->isSliding = false;

                if (!this->isDart) {
                    double lowerBound;
                    double upperBound;
                    if (this->isUpsideDown) {
                        upperBound = -8 / size;
                        lowerBound = 6.4/size;
                    } else {
                        upperBound = -6.4/size;
                        lowerBound = 8/size;
                    }
                    this->yAccel = min(max(upperBound, this->yAccel), lowerBound);
                }
                return;
            }
        } else {
            float sign = this->isUpsideDown ? -1.0 : 1.0;

            if (this->isBird) {
                    if (this->hasJustHeld && this->isHolding) {
                            this->hasJustHeld = false;

                            float bump = (isSmall ? 8.0 : 7.0) * size * sign;
                            double yAccel = this->yAccel;

                            if (sign*bump < sign*this->yAccel) {
                                this->yAccel = bump;
                                if (this->isOnSlope2 || this->isOnSlope) {
                                    float slopeRota = this->slopeRotation;
                                    if (slopeRota > 0) {
                                        this->yAccel = min(bump*1.4, (slopeRota/2)+bump);
                                    }
                                }
                            }
                            this->playBurstEffect();
                    }

                    float step = (sign*gravity*2 <= sign*this->yAccel) ? 1.2 : 0.8;

                    this->yAccel -= (local_gravity * delta * sign * step / 2) / size;
                    if (this->isHolding) {
                            this->isSliding = false;
                    }
                    if (!this->hasHitPortal) {
                        double lowerBound;
                        double upperBound;
                        if (this->isUpsideDown) {
                            upperBound = -8 / size;
                            lowerBound = 6.4/size;
                        } else {
                            upperBound = -6.4/size;
                            lowerBound = 8/size;
                        }
                        this->yAccel = min(max(upperBound, this->yAccel), lowerBound);
                    }
            } else {
                    double direction = (this->isHolding ^ this->isUpsideDown) ? -1.0 : 1.0;
                    this->yAccel = this->playerSpeedMultiplier * this->playerSpeed * direction;
            }
            return;
        }
    } else {
        double local_gravity = this->isCube ? gravity : 0.958199;
        rdi = this->isBall;
        float size = is_small ? 0.8 : 1.0;
          
        float its_1_if_ball = 0.60;
        if (this->isBall) {
            its_1_if_ball = 1.0;
        }

        if (this->isSpider && !this->isDashing) {
            this->spiderTestJump(0);
        } else {
            if (!this->isDashing || !onGround) {
                if (this->isRising) {
                    if (this->isRobot && this->isHolding && !this->robotCanJump) {

                        float dRate = this->decelRate;
                        if (dRate== 1.5) {
                            this->decelRate = (delta * 0.1) + dRate;
                            double yAccel = this->yAccel;

                            if (!this->isUpsideDown) {
                                if (yAccel <= 0) {
                                    this->isRising = false;
                                    this->isSliding = false;
                                    this->unknown_62a = true;

                                    this->animatedSprite1->tweenToAnimation("fall_loop", 0.1);
                                }
                            } else {
                                if (yAccel > gravity*2) {
                                    this->isRising = false;
                                    this->isSliding = false;
                                    this->unknown_62a = true;

                                    this->animatedSprite1->tweenToAnimation("fall_loop", 0.1);
                                }
                            }
                            return;
                        } else {
                            float fall_accel = its_1_if_ball * (local_gravity * delta);
                            if (this->isUpsideDown)
                                fall_accel *= -1.0;

                            this->yAccel -= fall_accel;
                            if (!this->isUpsideDown) {
                                if (this->yAccel <= 0) {
                                    this->isRising = false;
                                    this->isSliding = false;
                                    this->unknown_62a = true;

                                    this->animatedSprite1->tweenToAnimation("fall_loop", 0.1);
                                }
                            } else {
                                if (yAccel > gravity*2) {
                                    this->isRising = false;
                                    this->isSliding = false;
                                    this->unknown_62a = true;

                                    this->animatedSprite1->tweenToAnimation("fall_loop", 0.1);
                                }
                            }
                            return;
                        }
                    } else {
                        float fall_accel = its_1_if_ball * (local_gravity * delta);
                        if (this->isUpsideDown)
                            fall_accel *= -1.0;

                        this->yAccel -= fall_accel;
                        if (!this->isUpsideDown) {
                            if (this->yAccel <= 0) {
                                this->isRising = false;
                                this->isSliding = false;
                                this->unknown_62a = true;

                                this->animatedSprite1->tweenToAnimation("fall_loop", 0.1);
                            }
                        } else {
                            if (yAccel > gravity*2) {
                                this->isRising = false;
                                this->isSliding = false;
                                this->unknown_62a = true;

                                this->animatedSprite1->tweenToAnimation("fall_loop", 0.1);
                            }
                        }
                        return;
                    }
                } else {
                    double yaccel = this->yAccel;
                    if (this->isUpsideDown) {
                        if (yaccel > gravity*2) {
                                this->isOnGround = false;
                        }
                    } else {
                        if (gravity*2 > yaccel) {
                            this->isOnGround = false;
                        }
                    }

                    float fall_accel = its_1_if_ball * 0.958199 * delta;
                    if (this->isUpsideDown)
                        fall_accel*= -1;

                    yAccel -= fall_accel;

                    bool yInequality_2;

                    if (this->isUpsideDown) {
                        float terminal_velocity = 15.0;
                        this->yAccel = min(termanl_velocity, yAccel);
                        yInequality_2 = gravity*2 > this->yAccel;
                    } else {
                        float terminal_velocity = -15.0;
                        this->yAccel = max(terminal_velocity, gravity);
                        yInequality_2 = this->yAccel > gravity*2;
                    }

                    if (yInequality_2) {
                        if (!this->isBall) {
                            if (!(this->isSpider || this->isRobot || this->fadeOutStreak2(0) || this->isOnSlope || this->isOnSlope2)) {
                                this->runRotateAction(true);
                            }
                        }

                        bool yInequality = -4 > this->yAccel;
                        if (this->isUpsideDown) {
                            yInqeuality = this->yAccel > 4;
                        }

                        if (yInequality) {
                            if ( (this->isRobot || this->isSpider) && this->isSliding && !this->unknown_6b8) {
                                CCAnimatedSprite* sprite = this->isRobot ? this->animatedSprite1 : this->animatedSprite2;
                                sprite->tweenToAnimation("fall_loop", 0.1);
                            }
                            this->isSliding = false;
                        }
                    }
                    return;
                }
            } else {
                PlayLayer* playLayer = GameManager::sharedState()->playLayer;
                this->isRising = true;
                this->isSliding = false;
                this->isOnGround = false;
                this->hasJustHeld = false;
                this->robotCanJump = false;
                this->decelRate = 0.0;
                float jumpPower = 11.180032;

                if (this->isRobot) {
                        jumpPower /= 2.0;
                }
                if (!onGround) {
                        this->hasHitPortal = true;
                        jumpPower = 1./32;
                }

                float sign = this->isUpsideDown ? -1. : 1.;
                this->yAccel = size * jumpPower * sign;

                if (this->isOnSlope2 || this->isOnSlope) {
                        if (sign * this->slopeRotation > 0.) {
                                float slopeDelta = this->time - this->timeSinceLastSlopeCollision;
                                if (slopeDelta < 0.1) {
                                        slopeDelta = max(slopeDelta*10.0, 0.4);
                                } else {
                                        slopeDelta = 1.0;
                                }
                                float liftOff = this->slopeRotation/4.;
                                if (!this->isBall) {
                                        liftOff *= slopeDelta;
                                }
                                liftOff += gravity;
                                this->yAccel = this->isUpsideDown ? max(size * 1.4, liftOff) : min(size * 1.4, liftOff);
                        }
                }
                this->didJumpIDK = true;
                struct timeb tp;
                ftime(&tp);
                this->timeSinceLastJump = (tp.millitm + tp.time*1000)/1000;
                if (this->isInPlayLayer) {
                        playLayer->incrementJumps();
                        this->unknown_7c0 = true;
                }
                if (this->isBall) {
                    this->flipGravity(!this->isUpsideDown, true);
                    this->yAccel = this->yAccel * its_1_if_ball;
                    this->slideParticlesGoOnBottom = false;
                    this->isHolding = false;
                    return;
                } else if (this->isRobot) {
                    rax =  this->animatedSprite1->tweenToAnimation("jump_loop", 0.1);
                    return;
                } else {
                    if (!this->isSpider)
                        this->runRotateAction(true);

                    return;
                }
            }
        }
    }
}