int PlayerObject::updateJump(float delta) {
    bool shouldJump = 0; // rax

    bool onGround = this->isOnGround; // r14
    double gravity = this->gravity; // xmm0

    if (this->isRobot) {
            shouldJump = this->hasJustHeld & this->isHolding;
    }

    bool is_small = this->vehicleSize!=1.0; // rsi?
    float xmm5 = 0.958199;
    // r8 = this->isBall
    // rdx = this->isHolding;

    if (this->isShip || this->isBird || this->isDart) {
        rdi = this->isShip;
        float size = is_small ? 0.85 : 1.0; // xmm6

        goto loc_100219856; // look inside tmp2.cpp
    } else {
        double local_gravity = this->isCube ? gravity : 0.958199; // xmm5
        rdi = this->isBall;
        float size = is_small ? 0.8 : 1.0; // xmm1
          
        float its_1_if_ball = 0.60; // xmm2
        if (this->isBall) { // r8
            rcx = 0x0;
            its_1_if_ball = 1.0;
        }

        if (this->isSpider && !this->isDashing) {
            this->spiderTestJump(0);
        } else {
            goto loc_100219b8a; // look inside tmp.cpp
        }
    }


loc_100219856 :
    xmm2 = intrinsic_movss(xmm2, *(int32_t *)0x10050c764);
    xmm7 = intrinsic_movaps(xmm7, xmm2);
    xmm7 = intrinsic_divss(xmm7, xmm6);
    xmm8 = intrinsic_movss(xmm8, *(int32_t *)0x100510ebc);
    xmm8 = intrinsic_divss(xmm8, xmm6);
    r8 = this->isUpsideDown;
    xmm1 = intrinsic_movsd(xmm1, this->yAccel);
    xmm3 = intrinsic_xorpd(xmm3, xmm3);
    if (r8 != 0x0) {
            xmm3 = intrinsic_ucomisd(xmm3, xmm1);
            if (xmm3 >= 0x0) {
                    xmm4 = intrinsic_movaps(xmm4, *(int128_t *)value -0.00);
                    xmm4 = intrinsic_xorps(xmm4, xmm7);
                    xmm4 = intrinsic_cvtss2sd(xmm4, xmm4);
                    xmm1 = intrinsic_ucomisd(xmm1, xmm4);
                    if (xmm1 <= 0x0) {
                            xmm1 = intrinsic_ucomisd(xmm1, xmm3);
                            if (xmm1 >= 0x0) {
                                    xmm3 = intrinsic_movaps(xmm3, *(int128_t *)value -0.00);
                                    xmm3 = intrinsic_xorps(xmm3, xmm8);
                                    xmm3 = intrinsic_cvtss2sd(xmm3, xmm3);
                                    xmm3 = intrinsic_ucomisd(xmm3, xmm1);
                                    if (xmm3 > 0x0) {
                                            this->hasHitPortal = 0x0;
                                    }
                            }
                    }
                    else {
                            this->hasHitPortal = 0x0;
                    }
            }
            else {
                    xmm1 = intrinsic_ucomisd(xmm1, xmm3);
                    if (xmm1 >= 0x0) {
                            xmm3 = intrinsic_movaps(xmm3, *(int128_t *)value -0.00);
                            xmm3 = intrinsic_xorps(xmm3, xmm8);
                            xmm3 = intrinsic_cvtss2sd(xmm3, xmm3);
                            xmm3 = intrinsic_ucomisd(xmm3, xmm1);
                            if (xmm3 > 0x0) {
                                    this->hasHitPortal = 0x0;
                            }
                    }
            }
    }
    else {
            xmm1 = intrinsic_ucomisd(xmm1, xmm3);
            if (xmm1 >= 0x0) {
                    xmm4 = intrinsic_cvtss2sd(xmm4, xmm7);
                    xmm4 = intrinsic_ucomisd(xmm4, xmm1);
                    if (xmm4 <= 0x0) {
                            xmm3 = intrinsic_ucomisd(xmm3, xmm1);
                            if (xmm3 >= 0x0) {
                                    xmm3 = intrinsic_cvtss2sd(0x0, xmm8);
                                    xmm1 = intrinsic_ucomisd(xmm1, xmm3);
                                    if (xmm1 > 0x0) {
                                            this->hasHitPortal = 0x0;
                                    }
                            }
                    }
                    else {
                            this->hasHitPortal = 0x0;
                    }
            }
            else {
                    xmm3 = intrinsic_ucomisd(xmm3, xmm1);
                    if (xmm3 >= 0x0) {
                            xmm3 = intrinsic_cvtss2sd(0x0, xmm8);
                            xmm1 = intrinsic_ucomisd(xmm1, xmm3);
                            if (xmm1 > 0x0) {
                                    this->hasHitPortal = 0x0;
                            }
                    }
            }
    }
    if (rdi == 0x0) goto loc_100219921;

loc_1002198f4 :
    rax = this->hasHitPortal;
    if (rdx == 0x0) goto loc_1002199ab;

loc_100219903 :
    if (rax != 0x0) goto loc_1002199b3;

loc_10021990b :
    xmm2 = -1.0;
    if (r8 == 0x0) {
            if (*(int8_t *)(this + 0x7d1) != 0x0) {
                    xmm0 ^= 0.f;
            }
            xmm0 = (float)xmm0;
            xmm0 += xmm0;
            xmm0 = (double)xmm0;
    }
    else {
            xmm0 = intrinsic_addsd(xmm0, xmm0);
    }
    goto loc_100219a22;

loc_100219a22 :
    if (xmm0 == xmm1) {
            xmm0 = intrinsic_movss(xmm0, *(int32_t *)value 0.5);
    }
    else {
            xmm0 = intrinsic_movss(xmm0, *(int32_t *)value 0.4);
    }
    goto loc_100219ae9;

loc_100219ae9 :
    rax = 0x0;
    rax = r8 == 0x0 ? 0x1 : 0x0;
    xmm0 = intrinsic_cvtss2sd(0x0, intrinsic_divss(intrinsic_mulss(intrinsic_mulss(intrinsic_mulss(intrinsic_mulss(xmm5, delta), *(int32_t *)(0x10050d470 + rax * 0x4)), xmm2), xmm0), xmm6));
    xmm1 = intrinsic_subsd(xmm1, xmm0);
    this->yAccel = intrinsic_movsd(this->yAccel, xmm1);
    if (rdx != 0x0) {
            this->isSliding = 0x0;
            if (this->hasHitPortal == 0x0) {
                    if (this->isDart == 0x0) {
                            if (r8 != 0x0) {
                                    xmm0 = intrinsic_movss(xmm0, *(int32_t *)0x10050c9c4);
                                    xmm0 = intrinsic_divss(xmm0, xmm6);
                                    xmm0 = intrinsic_cvtss2sd(xmm0, xmm0);
                                    xmm0 = intrinsic_maxsd(xmm0, xmm1);
                                    xmm1 = intrinsic_movss(xmm1, *(int32_t *)0x100510ec0);
                                    xmm1 = intrinsic_divss(xmm1, xmm6);
                                    xmm1 = intrinsic_cvtss2sd(xmm1, xmm1);
                            }
                            else {
                                    xmm0 = intrinsic_cvtss2sd(0x0, xmm8);
                                    xmm0 = intrinsic_maxsd(xmm0, xmm1);
                                    xmm1 = intrinsic_cvtss2sd(0x0, xmm7);
                            }
                            this->yAccel = intrinsic_movsd(this->yAccel, intrinsic_minsd(xmm1, xmm0));
                    }
            }
    }
    else {
            if (this->hasHitPortal == 0x0) {
                    if (this->isDart == 0x0) {
                            if (r8 != 0x0) {
                                    xmm0 = intrinsic_movss(xmm0, *(int32_t *)0x10050c9c4);
                                    xmm0 = intrinsic_divss(xmm0, xmm6);
                                    xmm0 = intrinsic_cvtss2sd(xmm0, xmm0);
                                    xmm0 = intrinsic_maxsd(xmm0, xmm1);
                                    xmm1 = intrinsic_movss(xmm1, *(int32_t *)0x100510ec0);
                                    xmm1 = intrinsic_divss(xmm1, xmm6);
                                    xmm1 = intrinsic_cvtss2sd(xmm1, xmm1);
                            }
                            else {
                                    xmm0 = intrinsic_cvtss2sd(0x0, xmm8);
                                    xmm0 = intrinsic_maxsd(xmm0, xmm1);
                                    xmm1 = intrinsic_cvtss2sd(0x0, xmm7);
                            }
                            this->yAccel = intrinsic_movsd(this->yAccel, intrinsic_minsd(xmm1, xmm0));
                    }
            }
    }
    goto loc_ret;

loc_ret :
    rbx = stack[2044];
    r14 = stack[2045];
    this = stack[2046];
    rsp = rsp + 0x98;
    rbp = stack[2047];
    return rax;

loc_1002199b3 :
    xmm2 = 0x0;
    if (r8 == 0x0) goto loc_1002199c3;

loc_1002199bb :
    xmm2 = 0x0;
    xmm1 = intrinsic_ucomisd(xmm1, xmm2);
    if (xmm1 > 0x0) goto loc_1002199c9;

loc_1002199d7 :
    xmm2 = intrinsic_movss(xmm2, *(int32_t *)value 0.8);
    if (rdx == 0x0) goto loc_1002199f2;

loc_1002199e3 :
    if (r8 != 0x0) {
            xmm0 = intrinsic_addsd(xmm0, xmm0);
            xmm1 = intrinsic_ucomisd(xmm1, xmm0);
    }
    else {
            if (*(int8_t *)(this + 0x7d1) != 0x0) {
                    xmm0 = intrinsic_xorpd(xmm0, *(int128_t *)0x10050e430);
            }
            xmm0 = intrinsic_cvtsd2ss(xmm0, xmm0);
            xmm0 = intrinsic_addss(xmm0, xmm0);
            xmm0 = intrinsic_cvtss2sd(xmm0, xmm0);
            xmm0 = intrinsic_ucomisd(xmm0, xmm1);
    }
    goto loc_100219a22;

loc_1002199f2 :
    if (r8 == 0x0) {
            if (*(int8_t *)(this + 0x7d1) != 0x0) {
                    xmm0 = intrinsic_xorpd(xmm0, *(int128_t *)0x10050e430);
            }
            xmm0 = intrinsic_cvtsd2ss(xmm0, xmm0);
            xmm0 = intrinsic_addss(xmm0, xmm0);
            xmm0 = intrinsic_cvtss2sd(xmm0, xmm0);
            xmm0 = intrinsic_ucomisd(xmm0, xmm1);
    }
    else {
            xmm0 = intrinsic_addsd(xmm0, xmm0);
            xmm1 = intrinsic_ucomisd(xmm1, xmm0);
    }
    goto loc_100219ad2;

loc_100219ad2 :
    if ((COND_BYTE_SET(G)) == 0x0) {
            xmm2 = intrinsic_movss(xmm2, *(int32_t *)value 1.2);
    }
    xmm0 = intrinsic_movss(xmm0, *(int32_t *)value 0.4);
    goto loc_100219ae9;

loc_1002199c9 :
    xmm2 = intrinsic_movss(xmm2, *(int32_t *)value -1.00);
    if (rdx != 0x0) goto loc_1002199e3;
    goto loc_1002199f2;

loc_1002199c3 :
    xmm2 = intrinsic_ucomisd(xmm2, xmm1);
    if (xmm2 <= 0x0) goto loc_1002199d7;
    goto loc_1002199c9;

loc_1002199ab :
    if (rax == 0x0) goto loc_100219a99;
    goto loc_1002199b3;

loc_100219a99 :
    xmm2 = intrinsic_movss(xmm2, *(int32_t *)value 0.8);
    if (r8 != 0x0) {
            xmm0 = intrinsic_addsd(xmm0, xmm0);
            xmm1 = intrinsic_ucomisd(xmm1, xmm0);
    }
    else {
            if (*(int8_t *)(this + 0x7d1) != 0x0) {
                    xmm0 = intrinsic_xorpd(xmm0, *(int128_t *)0x10050e430);
            }
            xmm0 = intrinsic_cvtsd2ss(xmm0, xmm0);
            xmm0 = intrinsic_addss(xmm0, xmm0);
            xmm0 = intrinsic_cvtss2sd(xmm0, xmm0);
            xmm0 = intrinsic_ucomisd(xmm0, xmm1);
    }
    goto loc_100219ad2;

loc_100219921 :
    if (this->isBird != 0x0) {
            if ((this->hasJustHeld != 0x0) && (rdx != 0x0)) {
                    if (rsi == 0x0) {
                            xmm2 = intrinsic_movss(xmm2, *(int32_t *)0x10050ca5c);
                    }
                    r14 = this + 0x760;
                    rax = 0x0;
                    this->hasJustHeld = 0x0;
                    xmm2 = intrinsic_mulss(xmm2, *(int32_t *)(0x10050d470 + (COND_BYTE_SET(E)) * 0x4));
                    xmm2 = intrinsic_mulss(xmm2, xmm6);
                    xmm0 = intrinsic_cvtss2sd(0x0, xmm2);
                    var_68 = intrinsic_movss(var_68, xmm5);
                    var_64 = intrinsic_movss(var_64, xmm6);
                    var_90 = intrinsic_movaps(var_90, xmm7);
                    var_80 = intrinsic_movaps(var_80, xmm8);
                    if (r8 != 0x0) {
                            xmm1 = intrinsic_ucomisd(xmm1, xmm0);
                            if (xmm1 > 0x0) {
                                    this->yAccel = intrinsic_movsd(this->yAccel, xmm0);
                                    if ((*(int8_t *)(this + 0x769) != 0x0) || (this->isOnSlope != 0x0)) {
                                            xmm1 = intrinsic_movss(xmm1, this->slopeRotation);
                                            xmm3 = intrinsic_xorpd(xmm3, xmm3);
                                            xmm1 = intrinsic_ucomiss(xmm1, xmm3);
                                            if (xmm1 > 0x0) {
                                                    xmm2 = intrinsic_mulss(xmm2, *(int32_t *)value 1.4);
                                                    xmm1 = intrinsic_mulss(xmm1, *(int32_t *)value 0.5);
                                                    xmm1 = intrinsic_cvtss2sd(xmm1, xmm1);
                                                    xmm1 = intrinsic_addsd(xmm1, xmm0);
                                                    xmm0 = intrinsic_cvtss2sd(0x0, xmm2);
                                                    xmm0 = intrinsic_minsd(xmm0, xmm1);
                                                    *r14 = intrinsic_movsd(*r14, xmm0);
                                            }
                                    }
                            }
                    }
                    else {
                            xmm0 = intrinsic_ucomisd(xmm0, xmm1);
                            if (xmm0 > 0x0) {
                                    this->yAccel = intrinsic_movsd(this->yAccel, xmm0);
                                    if ((*(int8_t *)(this + 0x769) != 0x0) || (this->isOnSlope != 0x0)) {
                                            xmm1 = intrinsic_movss(xmm1, this->slopeRotation);
                                            xmm3 = intrinsic_xorpd(xmm3, xmm3);
                                            xmm1 = intrinsic_ucomiss(xmm1, xmm3);
                                            if (xmm1 > 0x0) {
                                                    xmm2 = intrinsic_mulss(xmm2, *(int32_t *)value 1.4);
                                                    xmm1 = intrinsic_mulss(xmm1, *(int32_t *)value 0.5);
                                                    xmm1 = intrinsic_cvtss2sd(xmm1, xmm1);
                                                    xmm1 = intrinsic_addsd(xmm1, xmm0);
                                                    xmm0 = intrinsic_cvtss2sd(0x0, xmm2);
                                                    xmm0 = intrinsic_minsd(xmm0, xmm1);
                                                    *r14 = intrinsic_movsd(*r14, xmm0);
                                            }
                                    }
                            }
                    }
                    rax = sub_10021c780(this);
                    xmm0 = intrinsic_movsd(xmm0, this->gravity);
                    r8 = this->isUpsideDown;
                    xmm1 = intrinsic_movsd(xmm1, *r14);
                    xmm5 = intrinsic_movss(xmm5, var_68);
                    xmm6 = intrinsic_movss(xmm6, var_64);
                    xmm7 = intrinsic_movaps(xmm7, var_90);
                    xmm8 = intrinsic_movaps(xmm8, var_80);
            }
            if (r8 != 0x0) {
                    xmm0 = intrinsic_addsd(xmm0, xmm0);
                    xmm1 = intrinsic_ucomisd(xmm1, xmm0);
            }
            else {
                    if (*(int8_t *)(this + 0x7d1) != 0x0) {
                            xmm0 = intrinsic_xorpd(xmm0, *(int128_t *)0x10050e430);
                    }
                    xmm0 = intrinsic_cvtsd2ss(xmm0, xmm0);
                    xmm0 = intrinsic_addss(xmm0, xmm0);
                    xmm0 = intrinsic_cvtss2sd(xmm0, xmm0);
                    xmm0 = intrinsic_ucomisd(xmm0, xmm1);
            }
            rax = 0x0;
            rdx = r8 == 0x0 ? 0x1 : 0x0;
            if ((COND_BYTE_SET(G)) == 0x0) {
                    xmm0 = intrinsic_movss(xmm0, *(int32_t *)value 1.2);
            }
            else {
                    xmm0 = intrinsic_movss(xmm0, *(int32_t *)value 0.8);
            }
            rax = rdx;
            xmm1 = intrinsic_cvtss2sd(0x0, intrinsic_divss(intrinsic_mulss(intrinsic_mulss(intrinsic_mulss(intrinsic_mulss(xmm5, delta), *(int32_t *)(0x10050d470 + rax * 0x4)), xmm0), *(int32_t *)0x10050c978), xmm6));
            xmm1 = intrinsic_addsd(xmm1, this->yAccel);
            this->yAccel = intrinsic_movsd(this->yAccel, xmm1);
            if (this->isHolding != 0x0) {
                    this->isSliding = 0x0;
            }
            if (this->hasHitPortal == 0x0) {
                    if (this->isDart == 0x0) {
                            if (r8 != 0x0) {
                                    xmm0 = intrinsic_movss(xmm0, *(int32_t *)0x10050c9c4);
                                    xmm0 = intrinsic_divss(xmm0, xmm6);
                                    xmm0 = intrinsic_cvtss2sd(xmm0, xmm0);
                                    xmm0 = intrinsic_maxsd(xmm0, xmm1);
                                    xmm1 = intrinsic_movss(xmm1, *(int32_t *)0x100510ec0);
                                    xmm1 = intrinsic_divss(xmm1, xmm6);
                                    xmm1 = intrinsic_cvtss2sd(xmm1, xmm1);
                            }
                            else {
                                    xmm0 = intrinsic_cvtss2sd(0x0, xmm8);
                                    xmm0 = intrinsic_maxsd(xmm0, xmm1);
                                    xmm1 = intrinsic_cvtss2sd(0x0, xmm7);
                            }
                            this->yAccel = intrinsic_movsd(this->yAccel, intrinsic_minsd(xmm1, xmm0));
                    }
            }
    }
    else {
            xmm0 = intrinsic_movsd(xmm0, *0x10050c8c8);
            xmm2 = intrinsic_movsd(xmm2, *0x10050c8d0);
            xmm3 = intrinsic_movapd(xmm3, xmm0);
            if (r8 != 0x0) {
                    xmm3 = intrinsic_movapd(xmm3, xmm2);
            }
            xmm1 = intrinsic_movss(xmm1, *(int32_t *)(this + 0x780));
            xmm1 = intrinsic_cvtss2sd(xmm1, xmm1);
            xmm1 = intrinsic_mulsd(xmm1, this->playerSpeed);
            xmm1 = intrinsic_mulsd(xmm1, xmm3);
            if (rdx == 0x0) {
                    xmm0 = intrinsic_movapd(xmm0, xmm2);
            }
            xmm1 = intrinsic_mulsd(xmm1, xmm0);
            this->yAccel = intrinsic_movsd(this->yAccel, xmm1);
            if (this->hasHitPortal == 0x0) {
                    if (this->isDart == 0x0) {
                            if (r8 != 0x0) {
                                    xmm0 = intrinsic_movss(xmm0, *(int32_t *)0x10050c9c4);
                                    xmm0 = intrinsic_divss(xmm0, xmm6);
                                    xmm0 = intrinsic_cvtss2sd(xmm0, xmm0);
                                    xmm0 = intrinsic_maxsd(xmm0, xmm1);
                                    xmm1 = intrinsic_movss(xmm1, *(int32_t *)0x100510ec0);
                                    xmm1 = intrinsic_divss(xmm1, xmm6);
                                    xmm1 = intrinsic_cvtss2sd(xmm1, xmm1);
                            }
                            else {
                                    xmm0 = intrinsic_cvtss2sd(0x0, xmm8);
                                    xmm0 = intrinsic_maxsd(xmm0, xmm1);
                                    xmm1 = intrinsic_cvtss2sd(0x0, xmm7);
                            }
                            this->yAccel = intrinsic_movsd(this->yAccel, intrinsic_minsd(xmm1, xmm0));
                    }
            }
    }
    goto loc_ret;


loc_100219b6d :
    if (onGround == 0x0) goto loc_100219b98;

loc_100219b72 :
    if ((*(int8_t *)(this + 0x775) == 0x0) || (*(int8_t *)(this + 0x779) != 0x0)) goto loc_100219b8a;

loc_100219fc7 :
    rdi = this;
    rbx = stack[2044];
    r14 = stack[2045];
    this = stack[2046];
    rsp = rsp + 0x98;
    rbp = stack[2047];
    rax = PlayerObject::spiderTestJump(rdi, 0x0);
    return rax;

loc_100219b8a :
    if (*(int8_t *)(this + 0x779) == 0x0) goto loc_100219ec9;

loc_100219b98 :
    if (this->isRising == 0x0) goto loc_100219dfd;

loc_100219ba6 :
    if (((this->isRobot == 0x0) || (rdx == 0x0)) || (this->robotCanJump != 0x0)) goto loc_100219db0;

loc_100219bc5 :
    xmm1 = intrinsic_movss(xmm1, this->decelRate);
    xmm3 = intrinsic_movss(xmm3, *(int32_t *)value 1.5);
    xmm3 = intrinsic_ucomiss(xmm3, xmm1);
    if (xmm3 <= 0x0) goto loc_100219db0;

loc_100219bdf :
    this->decelRate = intrinsic_movss(this->decelRate, intrinsic_addss(intrinsic_mulss(intrinsic_movss(xmm2, delta), *(int32_t *)value 0.10), xmm1));
    rax = this->isUpsideDown;
    xmm1 = intrinsic_movsd(xmm1, this->yAccel);
    if (rax != 0x0) goto loc_100219df1;

loc_100219e48 :
    if (*(int8_t *)(this + 0x7d1) != 0x0) {
            xmm0 = intrinsic_xorpd(xmm0, *(int128_t *)0x10050e430);
    }
    xmm0 = intrinsic_cvtsd2ss(xmm0, xmm0);
    xmm0 = intrinsic_addss(xmm0, xmm0);
    xmm0 = intrinsic_cvtss2sd(xmm0, xmm0);
    xmm0 = intrinsic_ucomisd(xmm0, xmm1);
    if (xmm0 <= 0x0) goto loc_ret;

loc_100219e70 :
    this->isRising = 0x0;
    *(int8_t *)(this + 0x62a) = 0x1;
    this->isSliding = 0x0;
    if (this->isRobot == 0x0) goto loc_10021a195;

loc_100219e91 :
    rbx = this->animatedSprite1;
    rax = std::basic_string<char, std::char_traits<char>, std::allocator<char> >::basic_string(var_58, "fall_loop", var_20);
    xmm0 = intrinsic_movss(xmm0, *(int32_t *)value 0.10);
    rax = CCAnimatedSprite::tweenToAnimation(rbx, var_58);
    rax = var_58;
    goto loc_10021a382;

loc_10021a382 :
    if (rax + 0xffffffffffffffe8 != std::string::_Rep::_S_empty_rep_storage) {
            *(int32_t *)(rax + 0xfffffffffffffff8) = lock intrinsic_xadd(*(int32_t *)(rax + 0xfffffffffffffff8), 0xffffffff);
            if (0xffffffff <= 0x0) {
                    rsi = var_38;
                    rax = std::string::_Rep::_M_destroy();
            }
    }
    goto loc_ret;

loc_10021a195 :
    if (this->isSpider == 0x0) goto loc_ret;

loc_10021a1a3 :
    rbx = *(this + 0x6b0);
    rax = std::basic_string<char, std::char_traits<char>, std::allocator<char> >::basic_string(var_50, "fall_loop", var_20);
    xmm0 = intrinsic_movss(xmm0, *(int32_t *)value 0.10);
    rax = CCAnimatedSprite::tweenToAnimation(rbx, var_50);
    rax = var_50;
    goto loc_10021a382;

loc_100219df1 :
    xmm0 = intrinsic_addsd(xmm0, xmm0);
    xmm1 = intrinsic_ucomisd(xmm1, xmm0);
    if (xmm1 <= 0x0) goto loc_ret;
    goto loc_100219e70;

loc_100219db0 :
    xmm5 = intrinsic_mulss(xmm5, delta);
    rax = this->isUpsideDown;
    rcx = 0x0;
    xmm2 = intrinsic_mulss(xmm2, intrinsic_mulss(xmm5, *(int32_t *)(0x10050d470 + (rax == 0x0 ? 0x1 : 0x0) * 0x4)));
    xmm2 = intrinsic_cvtss2sd(xmm2, xmm2);
    xmm1 = intrinsic_movsd(xmm1, this->yAccel);
    xmm1 = intrinsic_subsd(xmm1, xmm2);
    this->yAccel = intrinsic_movsd(this->yAccel, xmm1);
    if (rax == 0x0) goto loc_100219e48;
    goto loc_100219df1;

loc_100219dfd :
    rax = this->isUpsideDown;
    xmm1 = intrinsic_movsd(xmm1, this->yAccel);
    if (rax != 0x0) {
            xmm3 = intrinsic_movapd(xmm3, xmm0);
            xmm3 = intrinsic_addsd(xmm3, xmm3);
            xmm1 = intrinsic_ucomisd(xmm1, xmm3);
            if (xmm1 > 0x0) {
                    *(int8_t *)this->isOnGround = 0x0;
            }
    }
    else {
            COND = *(int8_t *)(this + 0x7d1) == 0x0;
            xmm3 = intrinsic_movapd(xmm3, xmm0);
            if (!COND) {
                    xmm3 = intrinsic_movapd(xmm3, *(int128_t *)0x10050e430);
                    xmm3 = intrinsic_xorpd(xmm3, xmm0);
            }
            xmm3 = intrinsic_cvtsd2ss(xmm3, xmm3);
            xmm3 = intrinsic_addss(xmm3, xmm3);
            xmm3 = intrinsic_cvtss2sd(xmm3, xmm3);
            xmm3 = intrinsic_ucomisd(xmm3, xmm1);
            if (xmm3 > 0x0) {
                    *(int8_t *)this->isOnGround = 0x0;
            }
    }
    rcx = 0x0;
    rax = 0x10050d470;
    xmm2 = intrinsic_mulss(xmm2, intrinsic_mulss(intrinsic_mulss(xmm5, delta), *(int32_t *)(rax + (COND_BYTE_SET(E)) * 0x4)));
    xmm2 = intrinsic_cvtss2sd(xmm2, xmm2);
    xmm1 = intrinsic_subsd(xmm1, xmm2);
    if (0x10050d470 != 0x0) {
            xmm2 = intrinsic_movsd(xmm2, *0x100511098);
            xmm2 = intrinsic_minsd(xmm2, xmm1);
            this->yAccel = intrinsic_movsd(this->yAccel, xmm2);
            if (!CPU_FLAGS & NE) {
                    if (*(int8_t *)(this + 0x7d1) != 0x0) {
                            xmm0 = intrinsic_xorpd(xmm0, *(int128_t *)0x10050e430);
                    }
                    xmm0 = intrinsic_cvtsd2ss(xmm0, xmm0);
                    xmm0 = intrinsic_addss(xmm0, xmm0);
                    xmm0 = intrinsic_cvtss2sd(xmm0, xmm0);
                    xmm0 = intrinsic_ucomisd(xmm0, xmm2);
                    if (xmm0 > 0x0) {
                            if (r8 == 0x0) {
                                    rax = this->isRobot != 0x0 ? 0x1 : 0x0;
                                    if (((((this->isSpider == 0x0) && (rax == 0x0)) && (PlayerObject::fadeOutStreak2(this, 0x0) == 0x0)) && (this->isOnSlope == 0x0)) && (this->isOnSlope2 == 0x0)) {
                                            rax = sub_10021c570(this, 0x1, rdx);
                                    }
                            }
                            xmm0 = intrinsic_movsd(xmm0, this->yAccel);
                            xmm0 = intrinsic_ucomisd(xmm0, *0x100510160);
                            rax = xmm0 > 0x0 ? 0x1 : 0x0;
                            xmm1 = intrinsic_movsd(xmm1, *0x1005110a0);
                            xmm1 = intrinsic_ucomisd(xmm1, xmm0);
                            rcx = xmm1 > 0x0 ? 0x1 : 0x0;
                            if (this->isUpsideDown != 0x0) {
                                    rcx = rax;
                            }
                            if (rcx == 0x1) {
                                    if (((this->isRobot != 0x0) && (this->isSliding != 0x0)) && (*(int8_t *)(this + 0x6b8) == 0x0)) {
                                            r14 = this->animatedSprite1;
                                            rax = std::basic_string<char, std::char_traits<char>, std::allocator<char> >::basic_string(var_48, "fall_loop", var_20);
                                            xmm0 = intrinsic_movss(xmm0, *(int32_t *)value 0.10);
                                            rax = CCAnimatedSprite::tweenToAnimation(r14, var_48);
                                            rax = var_48;
                                            if (rax + 0xffffffffffffffe8 != std::string::_Rep::_S_empty_rep_storage) {
                                                    *(int32_t *)(rax + 0xfffffffffffffff8) = lock intrinsic_xadd(*(int32_t *)(rax + 0xfffffffffffffff8), 0xffffffff);
                                                    if (0xffffffff <= 0x0) {
                                                            rsi = var_38;
                                                            rax = std::string::_Rep::_M_destroy();
                                                    }
                                            }
                                            r14 = this + 0x7a0;
                                            *(int8_t *)r14 = 0x0;
                                    }
                                    else {
                                            r14 = this + 0x7a0;
                                            if (((this->isSpider != 0x0) && (*(int8_t *)r14 != 0x0)) && (*(int8_t *)(this + 0x6b8) == 0x0)) {
                                                    rbx = *(this + 0x6b0);
                                                    rax = std::basic_string<char, std::char_traits<char>, std::allocator<char> >::basic_string(var_40, "fall_loop", var_20);
                                                    xmm0 = intrinsic_movss(xmm0, *(int32_t *)value 0.10);
                                                    rax = CCAnimatedSprite::tweenToAnimation(rbx, var_40);
                                                    rax = var_40;
                                                    if (rax + 0xffffffffffffffe8 != std::string::_Rep::_S_empty_rep_storage) {
                                                            *(int32_t *)(rax + 0xfffffffffffffff8) = lock intrinsic_xadd(*(int32_t *)(rax + 0xfffffffffffffff8), 0xffffffff);
                                                            if (0xffffffff <= 0x0) {
                                                                    rsi = var_38;
                                                                    rax = std::string::_Rep::_M_destroy();
                                                                    *(int8_t *)r14 = 0x0;
                                                            }
                                                            else {
                                                                    *(int8_t *)r14 = 0x0;
                                                            }
                                                    }
                                                    else {
                                                            *(int8_t *)r14 = 0x0;
                                                    }
                                            }
                                            else {
                                                    *(int8_t *)r14 = 0x0;
                                            }
                                    }
                            }
                    }
            }
            else {
                    xmm0 = intrinsic_addsd(xmm0, xmm0);
                    xmm2 = intrinsic_ucomisd(xmm2, xmm0);
                    if (xmm2 > 0x0) {
                            if (r8 == 0x0) {
                                    rax = this->isRobot != 0x0 ? 0x1 : 0x0;
                                    if (((((this->isSpider == 0x0) && (rax == 0x0)) && (PlayerObject::fadeOutStreak2(this, 0x0) == 0x0)) && (this->isOnSlope == 0x0)) && (this->isOnSlope2 == 0x0)) {
                                            rax = sub_10021c570(this, 0x1, rdx);
                                    }
                            }
                            xmm0 = intrinsic_movsd(xmm0, this->yAccel);
                            xmm0 = intrinsic_ucomisd(xmm0, *0x100510160);
                            rax = xmm0 > 0x0 ? 0x1 : 0x0;
                            xmm1 = intrinsic_movsd(xmm1, *0x1005110a0);
                            xmm1 = intrinsic_ucomisd(xmm1, xmm0);
                            rcx = xmm1 > 0x0 ? 0x1 : 0x0;
                            if (this->isUpsideDown != 0x0) {
                                    rcx = rax;
                            }
                            if (rcx == 0x1) {
                                    if (((this->isRobot != 0x0) && (this->isSliding != 0x0)) && (*(int8_t *)(this + 0x6b8) == 0x0)) {
                                            r14 = this->animatedSprite1;
                                            rax = std::basic_string<char, std::char_traits<char>, std::allocator<char> >::basic_string(var_48, "fall_loop", var_20);
                                            xmm0 = intrinsic_movss(xmm0, *(int32_t *)value 0.10);
                                            rax = CCAnimatedSprite::tweenToAnimation(r14, var_48);
                                            rax = var_48;
                                            if (rax + 0xffffffffffffffe8 != std::string::_Rep::_S_empty_rep_storage) {
                                                    *(int32_t *)(rax + 0xfffffffffffffff8) = lock intrinsic_xadd(*(int32_t *)(rax + 0xfffffffffffffff8), 0xffffffff);
                                                    if (0xffffffff <= 0x0) {
                                                            rsi = var_38;
                                                            rax = std::string::_Rep::_M_destroy();
                                                    }
                                            }
                                            r14 = this + 0x7a0;
                                            *(int8_t *)r14 = 0x0;
                                    }
                                    else {
                                            r14 = this + 0x7a0;
                                            if (((this->isSpider != 0x0) && (*(int8_t *)r14 != 0x0)) && (*(int8_t *)(this + 0x6b8) == 0x0)) {
                                                    rbx = *(this + 0x6b0);
                                                    rax = std::basic_string<char, std::char_traits<char>, std::allocator<char> >::basic_string(var_40, "fall_loop", var_20);
                                                    xmm0 = intrinsic_movss(xmm0, *(int32_t *)value 0.10);
                                                    rax = CCAnimatedSprite::tweenToAnimation(rbx, var_40);
                                                    rax = var_40;
                                                    if (rax + 0xffffffffffffffe8 != std::string::_Rep::_S_empty_rep_storage) {
                                                            *(int32_t *)(rax + 0xfffffffffffffff8) = lock intrinsic_xadd(*(int32_t *)(rax + 0xfffffffffffffff8), 0xffffffff);
                                                            if (0xffffffff <= 0x0) {
                                                                    rsi = var_38;
                                                                    rax = std::string::_Rep::_M_destroy();
                                                                    *(int8_t *)r14 = 0x0;
                                                            }
                                                            else {
                                                                    *(int8_t *)r14 = 0x0;
                                                            }
                                                    }
                                                    else {
                                                            *(int8_t *)r14 = 0x0;
                                                    }
                                            }
                                            else {
                                                    *(int8_t *)r14 = 0x0;
                                            }
                                    }
                            }
                    }
            }
    }
    else {
            xmm2 = intrinsic_movsd(xmm2, *0x100511090);
            xmm2 = intrinsic_maxsd(xmm2, xmm1);
            this->yAccel = intrinsic_movsd(this->yAccel, xmm2);
            if (!CPU_FLAGS & E) {
                    xmm0 = intrinsic_addsd(xmm0, xmm0);
                    xmm2 = intrinsic_ucomisd(xmm2, xmm0);
                    if (xmm2 > 0x0) {
                            if (r8 == 0x0) {
                                    rax = this->isRobot != 0x0 ? 0x1 : 0x0;
                                    if (((((this->isSpider == 0x0) && (rax == 0x0)) && (PlayerObject::fadeOutStreak2(this, 0x0) == 0x0)) && (this->isOnSlope == 0x0)) && (this->isOnSlope2 == 0x0)) {
                                            rax = sub_10021c570(this, 0x1, rdx);
                                    }
                            }
                            xmm0 = intrinsic_movsd(xmm0, this->yAccel);
                            xmm0 = intrinsic_ucomisd(xmm0, *0x100510160);
                            rax = xmm0 > 0x0 ? 0x1 : 0x0;
                            xmm1 = intrinsic_movsd(xmm1, *0x1005110a0);
                            xmm1 = intrinsic_ucomisd(xmm1, xmm0);
                            rcx = xmm1 > 0x0 ? 0x1 : 0x0;
                            if (this->isUpsideDown != 0x0) {
                                    rcx = rax;
                            }
                            if (rcx == 0x1) {
                                    if (((this->isRobot != 0x0) && (this->isSliding != 0x0)) && (*(int8_t *)(this + 0x6b8) == 0x0)) {
                                            r14 = this->animatedSprite1;
                                            rax = std::basic_string<char, std::char_traits<char>, std::allocator<char> >::basic_string(var_48, "fall_loop", var_20);
                                            xmm0 = intrinsic_movss(xmm0, *(int32_t *)value 0.10);
                                            rax = CCAnimatedSprite::tweenToAnimation(r14, var_48);
                                            rax = var_48;
                                            if (rax + 0xffffffffffffffe8 != std::string::_Rep::_S_empty_rep_storage) {
                                                    *(int32_t *)(rax + 0xfffffffffffffff8) = lock intrinsic_xadd(*(int32_t *)(rax + 0xfffffffffffffff8), 0xffffffff);
                                                    if (0xffffffff <= 0x0) {
                                                            rsi = var_38;
                                                            rax = std::string::_Rep::_M_destroy();
                                                    }
                                            }
                                            r14 = this + 0x7a0;
                                            *(int8_t *)r14 = 0x0;
                                    }
                                    else {
                                            r14 = this + 0x7a0;
                                            if (((this->isSpider != 0x0) && (*(int8_t *)r14 != 0x0)) && (*(int8_t *)(this + 0x6b8) == 0x0)) {
                                                    rbx = *(this + 0x6b0);
                                                    rax = std::basic_string<char, std::char_traits<char>, std::allocator<char> >::basic_string(var_40, "fall_loop", var_20);
                                                    xmm0 = intrinsic_movss(xmm0, *(int32_t *)value 0.10);
                                                    rax = CCAnimatedSprite::tweenToAnimation(rbx, var_40);
                                                    rax = var_40;
                                                    if (rax + 0xffffffffffffffe8 != std::string::_Rep::_S_empty_rep_storage) {
                                                            *(int32_t *)(rax + 0xfffffffffffffff8) = lock intrinsic_xadd(*(int32_t *)(rax + 0xfffffffffffffff8), 0xffffffff);
                                                            if (0xffffffff <= 0x0) {
                                                                    rsi = var_38;
                                                                    rax = std::string::_Rep::_M_destroy();
                                                                    *(int8_t *)r14 = 0x0;
                                                            }
                                                            else {
                                                                    *(int8_t *)r14 = 0x0;
                                                            }
                                                    }
                                                    else {
                                                            *(int8_t *)r14 = 0x0;
                                                    }
                                            }
                                            else {
                                                    *(int8_t *)r14 = 0x0;
                                            }
                                    }
                            }
                    }
            }
            else {
                    if (*(int8_t *)(this + 0x7d1) != 0x0) {
                            xmm0 = intrinsic_xorpd(xmm0, *(int128_t *)0x10050e430);
                    }
                    xmm0 = intrinsic_cvtsd2ss(xmm0, xmm0);
                    xmm0 = intrinsic_addss(xmm0, xmm0);
                    xmm0 = intrinsic_cvtss2sd(xmm0, xmm0);
                    xmm0 = intrinsic_ucomisd(xmm0, xmm2);
                    if (xmm0 > 0x0) {
                            if (r8 == 0x0) {
                                    rax = this->isRobot != 0x0 ? 0x1 : 0x0;
                                    if (((((this->isSpider == 0x0) && (rax == 0x0)) && (PlayerObject::fadeOutStreak2(this, 0x0) == 0x0)) && (this->isOnSlope == 0x0)) && (this->isOnSlope2 == 0x0)) {
                                            rax = sub_10021c570(this, 0x1, rdx);
                                    }
                            }
                            xmm0 = intrinsic_movsd(xmm0, this->yAccel);
                            xmm0 = intrinsic_ucomisd(xmm0, *0x100510160);
                            rax = xmm0 > 0x0 ? 0x1 : 0x0;
                            xmm1 = intrinsic_movsd(xmm1, *0x1005110a0);
                            xmm1 = intrinsic_ucomisd(xmm1, xmm0);
                            rcx = xmm1 > 0x0 ? 0x1 : 0x0;
                            if (this->isUpsideDown != 0x0) {
                                    rcx = rax;
                            }
                            if (rcx == 0x1) {
                                    if (((this->isRobot != 0x0) && (this->isSliding != 0x0)) && (*(int8_t *)(this + 0x6b8) == 0x0)) {
                                            r14 = this->animatedSprite1;
                                            rax = std::basic_string<char, std::char_traits<char>, std::allocator<char> >::basic_string(var_48, "fall_loop", var_20);
                                            xmm0 = intrinsic_movss(xmm0, *(int32_t *)value 0.10);
                                            rax = CCAnimatedSprite::tweenToAnimation(r14, var_48);
                                            rax = var_48;
                                            if (rax + 0xffffffffffffffe8 != std::string::_Rep::_S_empty_rep_storage) {
                                                    *(int32_t *)(rax + 0xfffffffffffffff8) = lock intrinsic_xadd(*(int32_t *)(rax + 0xfffffffffffffff8), 0xffffffff);
                                                    if (0xffffffff <= 0x0) {
                                                            rsi = var_38;
                                                            rax = std::string::_Rep::_M_destroy();
                                                    }
                                            }
                                            r14 = this + 0x7a0;
                                            *(int8_t *)r14 = 0x0;
                                    }
                                    else {
                                            r14 = this + 0x7a0;
                                            if (((this->isSpider != 0x0) && (*(int8_t *)r14 != 0x0)) && (*(int8_t *)(this + 0x6b8) == 0x0)) {
                                                    rbx = *(this + 0x6b0);
                                                    rax = std::basic_string<char, std::char_traits<char>, std::allocator<char> >::basic_string(var_40, "fall_loop", var_20);
                                                    xmm0 = intrinsic_movss(xmm0, *(int32_t *)value 0.10);
                                                    rax = CCAnimatedSprite::tweenToAnimation(rbx, var_40);
                                                    rax = var_40;
                                                    if (rax + 0xffffffffffffffe8 != std::string::_Rep::_S_empty_rep_storage) {
                                                            *(int32_t *)(rax + 0xfffffffffffffff8) = lock intrinsic_xadd(*(int32_t *)(rax + 0xfffffffffffffff8), 0xffffffff);
                                                            if (0xffffffff <= 0x0) {
                                                                    rsi = var_38;
                                                                    rax = std::string::_Rep::_M_destroy();
                                                                    *(int8_t *)r14 = 0x0;
                                                            }
                                                            else {
                                                                    *(int8_t *)r14 = 0x0;
                                                            }
                                                    }
                                                    else {
                                                            *(int8_t *)r14 = 0x0;
                                                    }
                                            }
                                            else {
                                                    *(int8_t *)r14 = 0x0;
                                            }
                                    }
                            }
                    }
            }
    }
    goto loc_ret;

loc_100219ec9 :
    this->isRising = 0x1;
    this->isSliding = 0x0;
    *(int8_t *)this->isOnGround = 0x0;
    this->hasJustHeld = 0x0;
    this->robotCanJump = 0x0;
    this->decelRate = 0x0;
    xmm0 = intrinsic_movsd(xmm0, this->jumpPower);
    xmm0 = intrinsic_cvtsd2ss(xmm0, xmm0);
    if (this->isRobot != 0x0) {
            xmm0 = intrinsic_mulss(xmm0, *(int32_t *)value 0.5);
    }
    if (r14 == 0x0) {
            this->hasHitPortal = 0x1;
            xmm0 = intrinsic_movss(xmm0, *(int32_t *)0x10050dd44);
    }
    rax = this->isUpsideDown;
    rcx = 0x0;
    xmm3 = intrinsic_movss(xmm3, *(int32_t *)(0x10050d470 + (rax == 0x0 ? 0x1 : 0x0) * 0x4));
    xmm1 = intrinsic_mulss(xmm1, intrinsic_mulss(xmm0, xmm3));
    xmm0 = intrinsic_cvtss2sd(0x0, xmm1);
    this->yAccel = intrinsic_movsd(this->yAccel, xmm0);
    if ((*(int8_t *)(this + 0x769) != 0x0) || (this->isOnSlope != 0x0)) {
            xmm2 = intrinsic_movss(xmm2, this->slopeRotation);
            xmm3 = intrinsic_mulss(xmm3, xmm2);
            xmm4 = 0x0;
            xmm3 = intrinsic_ucomiss(xmm3, xmm4);
            if (xmm3 > 0x0) {
                    xmm3 = intrinsic_movsd(xmm3, this->time);
                    xmm3 = intrinsic_subsd(xmm3, this->timeSinceLastSlopeCollision);
                    xmm4 = intrinsic_movsd(xmm4, *0x100511070);
                    xmm4 = intrinsic_ucomisd(xmm4, xmm3);
                    if (xmm4 > 0x0) {
                            xmm3 = intrinsic_mulsd(xmm3, *0x100511078);
                            xmm3 = intrinsic_maxsd(xmm3, *0x100511080);
                    }
                    else {
                            xmm3 = intrinsic_movsd(xmm3, *0x10050c8c8);
                    }
                    xmm1 = intrinsic_mulss(xmm1, *(int32_t *)value 1.4);
                    if (r8 == 0x0) {
                            xmm2 = intrinsic_cvtsd2ss(0x0, intrinsic_mulsd(xmm3, intrinsic_cvtss2sd(xmm2, xmm2)));
                    }
                    xmm2 = intrinsic_mulss(xmm2, *(int32_t *)0x10050cee4);
                    xmm0 = intrinsic_addsd(xmm0, intrinsic_cvtss2sd(xmm2, xmm2));
                    xmm1 = intrinsic_cvtss2sd(xmm1, xmm1);
                    if (rax != 0x0) {
                            xmm1 = intrinsic_maxsd(xmm1, xmm0);
                    }
                    else {
                            xmm1 = intrinsic_minsd(xmm1, xmm0);
                    }
                    this->yAccel = intrinsic_movsd(this->yAccel, xmm1);
            }
    }
    this->didJumpIDK = 0x1;
    rax = ftime(var_38);
    rax = (0xfffff & var_38) * 0x3e8;
    xmm0 = intrinsic_cvtsi2sd(0x0, (var_30 & 0xffff) + rax);
    xmm0 = intrinsic_divsd(xmm0, *0x10050c940);
    this->timeSinceLastJump = intrinsic_movsd(this->timeSinceLastJump, xmm0);
    if (this->isInPlayLayer != 0x0) {
            rax = sub_10007ff40(*(GameManager::sharedState() + 0x180));
            *(int8_t *)(this + 0x7c0) = 0x1;
    }
    if (this->isBall == 0x0) goto loc_10021a345;

loc_10021a2f1 :
    rsi = 0x0;
    rax = PlayerObject::flipGravity(this, this->isUpsideDown == 0x0 ? 0x1 : 0x0, 0x1);
    xmm0 = intrinsic_movsd(xmm0, this->yAccel);
    xmm0 = intrinsic_mulsd(xmm0, *0x100511088);
    this->yAccel = intrinsic_movsd(this->yAccel, xmm0);
    this->slideParticlesGoOnBottom = 0x0;
    this->isHolding = 0x0;
    goto loc_10021a336;

loc_10021a3b3 :
    if (this->isSpider != 0x0) goto loc_10021a336;

loc_10021a336 :
    if (this->isRobot != 0x0) goto loc_10021a34f;
    goto loc_ret;

loc_10021a34f :
    rbx = this->animatedSprite1;
    rax = std::basic_string<char, std::char_traits<char>, std::allocator<char> >::basic_string(var_60, "jump_loop", var_20);
    xmm0 = intrinsic_movss(xmm0, *(int32_t *)value 0.10);
    rax = CCAnimatedSprite::tweenToAnimation(rbx, var_60);
    rax = var_60;
    goto loc_10021a382;

loc_10021a345 :
    if (this->isRobot == 0x0) goto loc_10021a3b3;
    goto loc_10021a34f;

loc_10021a3c1 :
    rax = sub_10021c570(this, 0x1, 0x10050d470);
    if (this->isRobot != 0x0) goto loc_10021a34f;
    goto loc_ret;
}