/*
    loc_100219921 register info

    rdx = this->isHolding
    r8 = this->isUpsideDown
    xmm1 = this->yAccel
    xmm0 = gravity
    xmm2 = 8.0
    rsi = isSmall
    xmm6 = size
    xmm7 = 8.0 / size;
    xmm8 = -6.4 / size;
    xmm5 = local_gravity
*/
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
                    // xmm0 is now gravity again
                    // r8 is now upside down again
                    // xmm1 is now yAccel again
            }

            float step = (sign*gravity*2 <= sign*this->yAccel) ? 1.2 : 0.8; // xmm0

            this->yAccel -= (local_gravity * delta * sign * step / 2) / size;
            if (this->isHolding) {
                    this->isSliding = false;
            }
            if (!this->hasHitPortal) {
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
            }
    } else { // dart
            double direction = (this->isHolding ^ this->isUpsideDown) ? -1.0 : 1.0;
            this->yAccel = this->playerSpeedMultiplier * this->playerSpeed * direction;
    }
    return;