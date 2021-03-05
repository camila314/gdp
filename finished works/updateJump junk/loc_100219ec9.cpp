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
        this->yAccel = this->yAccel * 0.6;
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
