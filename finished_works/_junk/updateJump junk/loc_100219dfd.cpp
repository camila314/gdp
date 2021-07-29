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

    float fall_accel = 0.6 * 0.958199 * delta; // xmm2, xmm5
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
            if (!(this->isSpider || this->isRobot || this->fadeOutStreak2(0) || this->rotationLocked || this->fallRotationLocked)) {
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
    return 0;