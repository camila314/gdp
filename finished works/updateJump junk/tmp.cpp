
if (!this->isDashing || !onGround) { // loc_100219b8a // probably wrong
    if (this->isRising) { // loc_100219b98
        if (this->isRobot && this->isHolding && !this->robotCanJump) { // loc_100219ba6

            float dRate = this->decelRate; // xmm1, loc_100219bc5
            if (dRate== 1.5) {
                this->decelRate = (delta * 0.1) + xmm1; // loc_100219bdf
                double yAccel = this->yAccel; // xmm1

                if (!this->isUpsideDown) {
                    if (yAccel <= 0) { // loc_100219e48
                        this->isRising = false; // loc_100219e70
                        this->isSliding = false;
                        *(int8_t *)(this + 0x62a) = true; // idk yet

                        this->animatedSprite1->tweenToAnimation("fall_loop", 0.1);
                    }
                } else {
                    if (yAccel > gravity*2) { // loc_100219df1
                        this->isRising = false; // loc_100219e70
                        this->isSliding = false;
                        *(int8_t *)(this + 0x62a) = true; // idk yet

                        this->animatedSprite1->tweenToAnimation("fall_loop", 0.1);
                    }
                }
                return;
            } else {
                // loc_100219db0

                //rax = this->isUpsideDown;
                rcx = 0x0;
                float fall_accel = its_1_if_ball * (local_gravity * delta); // 0.6
                if (this->isUpsideDown)
                    fall_accel *= -1.0;

                this->yAccel -= fall_accel;
                if (!this->isUpsideDown) {
                    if (this->yAccel <= 0) { // loc_100219e48
                        this->isRising = false; // loc_100219e70
                        this->isSliding = false;
                        *(int8_t *)(this + 0x62a) = true; // idk yet

                        this->animatedSprite1->tweenToAnimation("fall_loop", 0.1);
                    }
                } else {
                    if (yAccel > gravity*2) { // loc_100219df1
                        this->isRising = false; // loc_100219e70
                        this->isSliding = false;
                        *(int8_t *)(this + 0x62a) = true; // idk yet

                        this->animatedSprite1->tweenToAnimation("fall_loop", 0.1);
                    }
                }
                return;
            }
        } else {
            // loc_100219db0

            //rax = this->isUpsideDown;
            rcx = 0x0;
            float fall_accel = its_1_if_ball * (local_gravity * delta); // 0.6 = xmm2
            if (this->isUpsideDown)
                fall_accel *= -1.0;

            this->yAccel -= fall_accel;
            if (!this->isUpsideDown) {
                if (this->yAccel <= 0) { // loc_100219e48
                    this->isRising = false; // loc_100219e70
                    this->isSliding = false;
                    *(int8_t *)(this + 0x62a) = true; // idk yet

                    this->animatedSprite1->tweenToAnimation("fall_loop", 0.1);
                }
            } else {
                if (yAccel > gravity*2) { // loc_100219df1
                    this->isRising = false; // loc_100219e70
                    this->isSliding = false;
                    *(int8_t *)(this + 0x62a) = true; // idk yet

                    this->animatedSprite1->tweenToAnimation("fall_loop", 0.1);
                }
            }
            return;
        }
    } else {
        // loc_100219dfd
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

        rcx = 0x0;

        float fall_accel = its_1_if_ball * 0.958199 * delta; // xmm5
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
    // loc_100219ec9
    PlayLayer* playLayer = GameManager::sharedState()->playLayer;
    this->isRising = true;
    this->isSliding = false;
    this->isOnGround = false;
    this->hasJustHeld = false;
    this->robotCanJump = false;
    this->decelRate = 0.0;
    float jumpPower = 11.180032; // this->jumpPower

    // rax = this->isUpsideDown;

    if (this->isRobot) {
            jumpPower /= 2.0;
    }
    if (!onGround) { // this is probably for testing only
            *(int8_t *)(this + 0x732) = true;
            jumpPower = 1./32; // 0x50dd44
    }
    rcx = 0x0; // idk yet, keeping in case its important

    float sign = this->isUpsideDown ? -1. : 1.; // xmm3
    this->yAccel = size * jumpPower * sign;

    if (this->isOnSlope2 || this->isOnSlope) { // slope stuff omg
            if (sign * this->slopeRotation > 0.) { /// sloperotation = xmm2
                    float slopeDelta = this->time - this->timeSinceLastSlopeCollision; // xmm3
                    if (slopeDelta < 0.1) { // 0x100511070
                            slopeDelta = max(slopeDelta*10.0, 0.4); // 0.4 = 0x100511080
                    } else {
                            slopeDelta = 1.0; // 0x10050c8c8
                    }
                    float liftOff = this->slopeRotation/4.;
                    if (!this->isBall) { // r8
                            liftOff *= slopeDelta;
                    }
                    liftOff += gravity;
                    this->yAccel = this->isUpsideDown ? max(size * 1.4, liftOff) : min(size * 1.4, liftOff); // 0x10050c788
            }
    }
    this->didJumpIDK = 0x1; // 0x62b
    struct timeb tp; // var_38
    ftime(&tp);
    xmm0 = (tp.millitm + tp.time*1000)/1000;
    this->timeSinceLastJump = (tp.millitm + tp.time*1000)/1000;
    if (this->isInPlayLayer) {
            playLayer->incrementJumps();
            this->unknown_7c0 = true; // can't find any reads to this address, maybe "has jumped at all"
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