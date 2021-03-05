    // loc_100219856
    //xmm7 = 8.0 / size;
    //xmm8 = -6.4 / size;
    //r8 = this->isUpsideDown;
    //rsi = isSmall

    float yAccel = this->yAccel; // xmm1
    
    //xmm3 = intrinsic_xorpd(xmm3, xmm3);  xmm3 = 0

    // i removed a large block of code that seemed to do literally nothing.


    if (this->isShip) { // rdi
        //loc_100219903
        if (!this->hasHitPortal) {
            //loc_10021990b
            float sign = this->isUpsideDown ? -1.0 : 1.0; // technically from loc_100219ae9 but its convenient to define here

            float multiplier = -1.0;
            float step = (gravity*2 == yAccel)? 0.5 : 0.4; // xmm0
            if (!this->isHolding && shouldJump) {
                multiplier = sign*this->yAccel < gravity*2*sign ? 1.2 : 0.8;
                step = 0.4;
            }

            // loc_100219ae9

            this->yAccel += (gravity * delta * sign * step)/size;
            this->isSliding = false;

            if (!this->isDart) { // this code is reused later, dont worry about this
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
        //loc_100219921
        float sign = this->isUpsideDown ? -1.0 : 1.0;

        if (this->isBird) {
                if (this->hasJustHeld && this->isHolding) {
                        this->hasJustHeld = false;

                        float bump = (isSmall ? 8.0 : 7.0) * size * sign; // xmm2
                        double yAccel = this->yAccel; // r14

                        //xmm0 = bump;

                        if (sign*bump < sign*this->yAccel) {
                            this->yAccel = bump;
                            if (this->isOnSlope2 || this->isOnSlope) {
                                float slopeRota = this->slopeRotation; // xmm1
                                if (slopeRota > 0) {
                                    this->yAccel = min(bump*1.4, (slopeRota/2)+bump);
                                }
                            }
                        }
                        this->playBurstEffect();
                }

                float step = (sign*gravity*2 <= sign*this->yAccel) ? 1.2 : 0.8; // xmm0

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
        } else { // dart
                double direction = (this->isHolding ^ this->isUpsideDown) ? -1.0 : 1.0;
                this->yAccel = this->playerSpeedMultiplier * this->playerSpeed * direction;
        }
        return;
    }