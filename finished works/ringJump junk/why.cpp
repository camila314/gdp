void PlayerObject::ringJump(GameObject* ringObj) {
    if (!this->isDead && this->hasQueuedHold && !this->isDashing && this->isHolding2) {
        //loc_10022ac36
        if (this->canHitCustomRing && (this->unknown_74a || ringObj->objectType != kCustomRing)) {
            return;
        }

        //loc_10022ac6a
        this->hasJustHitRing = true;
        this->untouchedRings->removeObject(ringObj);
        if (ringObj->objectType == kCustomRing) {
            this->unknown_74a = true;
            //loc_10022accf
            r15 = this->inEditorMode;
            GJBL->objectTriggered(ringObj);
            this->hasQueuedHold = false;
        } else {
            this->canHitCustomRing = true;
            this->unknown_628 = 0x1;

                //loc_10022acf1
            if (ringObj->objectType == kGreenDashRing || ringObj->objectType == kPinkDashRing) {
                if (ringObj->objectType == kPinkDashRing) {
                    r15 = *(int8_t *)(this + 0x62c);
                    rax = GameManager::sharedState();
                    if (r15 != 0x0) {
                            rdi = *(rax + 0x180);
                            rax = *rdi;
                            rdx = 0x0;
                            rax = (*(rax + 0x460))(rdi, this, *(int8_t *)(this + 0x776) == 0x0 ? 0x1 : 0x0, 0x1);
                            rax = PlayLayer::playGravityEffect(*(GameManager::sharedState() + 0x180), *(int8_t *)(this + 0x776) & 0xff);
                    }
                    else {
                            if (*(rax + 0x188) != 0x0) {
                                    rdi = *(GameManager::sharedState() + 0x188);
                                    rax = *rdi;
                                    rdx = 0x0;
                                    rax = (*(rax + 0x460))(rdi, this, *(int8_t *)(this + 0x776) == 0x0 ? 0x1 : 0x0, 0x1);
                            }
                            else {
                                    rsi = 0x0;
                                    rax = PlayerObject::flipGravity(this, *(int8_t *)(this + 0x776) == 0x0 ? 0x1 : 0x0, 0x1);
                            }
                    }
                }
                sub_100221d70(this, ringObj);
            } else if (ringObj->objectType == kBlackRing) {
                //loc_10022b164 :
                if (this->isShip == 0x0) {
                    //loc_10022ada7
                    this->hasQueuedHold = 0x0;
                    rax = *(int8_t *)(this + 0x771);
                    rcx = *(int8_t *)(this + 0x776);
                    rdx = rcx == 0x0 ? 0x1 : 0x0;
                    bool unk_b;
                    if (this->unknown_770 != 0 || unk_b++ || (unk_b=0,this->unknown_773)) {
                            //loc_10022addf :
                            rdx = rcx == 0x0 ? 0x1 : 0x0;
                            xmm0 = intrinsic_movss(xmm0, *(int32_t *)(14 or -14 + rdx * 0x4));
                            if (rax) {
                                    xmm0 = intrinsic_mulss(xmm0, *(int32_t *)value 0.8);
                            }
                        } else {
                        // b1b9
                        xmm0 = intrinsic_movss(xmm0, *(int32_t *)(0x100511138 + rdx * 0x4));
                        if ((*(int8_t *)(this + 0x774) == 0x0) && (*(int8_t *)(this + 0x775) != 0x0)) {
                                xmm0 = intrinsic_mulss(xmm0, *(int32_t *)value 1.10);
                        }
                    }
                    //loc_10022adfe 
                    xmm0 = intrinsic_cvtss2sd(xmm0, xmm0);
                    *(this + 0x760) = intrinsic_movsd(*(this + 0x760), xmm0);
                    if (*(int8_t *)(this + 0x772) != 0x0) {
                            sub_10021cb10(this);
                    }
                    else {
                            PlayerObject::runRotateAction(this, 0x0, rdx);
                    }
                    sub_10021aef0(this);
                    *(int8_t *)(this + 0x7c1) = 0x1;
                    *(int8_t *)(this + 0x732) = 0x1;
                    if (*(int8_t *)(this + 0x772) != 0x0) {
                            *(int8_t *)(this + 0x745) = 0x0;
                    }
                } else {
                    // loc_10022ae24 :
                    *(int8_t *)(this + 0x7a1) = 0x1;
                    *(int8_t *)(this + 0x7a0) = 0x0;
                    *(int8_t *)(this + 0x778) = 0x0;
                    this->hasQueuedHold = 0x0;
                    xmm0 = intrinsic_movss(xmm0, *(int32_t *)(this + 0x77c));
                    r15 = xmm0 != 1.0;
                    xmm0 = intrinsic_movsd(xmm0, *(this + 0x610));
                    xmm0 = intrinsic_cvtsd2ss(xmm0, xmm0);
                    var_24 = intrinsic_movss(var_24, xmm0);
                    if (ringObj->objectType == kRedRing) {
                        //loc_10022b164 :
                        if (this->isShip == 0x0) {
                            //loc_10022b20a :
                            if (*(int8_t *)(this + 0x771) != 0x0) {
                                xmm0 = intrinsic_movss(xmm0, *(int32_t *)(this + 0x77c));
                                xmm0 = intrinsic_ucomiss(xmm0, *(int32_t *)value 1.0);
                                if ((xmm0 == 0x0) && (CPU_FLAGS & NP)) {
                                    xmm0 = intrinsic_movss(xmm0, var_24);
                                    xmm0 = intrinsic_mulss(xmm0, *(int32_t *)0x100510f10);
                                } else {
                                    xmm0 = intrinsic_movss(xmm0, var_24);
                                    xmm0 = intrinsic_mulss(xmm0, *(int32_t *)0x100510f14);
                                }
                            } else {
                                if (*(int8_t *)(this + 0x772) != 0x0) {
                                    xmm0 = intrinsic_movss(xmm0, var_24);
                                    xmm0 = intrinsic_mulss(xmm0, *(int32_t *)0x100510f18);
                                } else {
                                    if (*(int8_t *)(this + 0x774) != 0x0) {
                                        xmm0 = intrinsic_movss(xmm0, var_24);
                                        xmm0 = intrinsic_mulss(xmm0, *(int32_t *)0x100510f1c);
                                    } else {
                                        if (*(int8_t *)(this + 0x775) == 0x0) {
                                            xmm0 = intrinsic_movss(xmm0, var_24);
                                            xmm0 = intrinsic_mulss(xmm0, *(int32_t *)0x100510f20);
                                        } else {
                                            xmm0 = intrinsic_movss(xmm0, var_24);
                                            xmm0 = intrinsic_mulss(xmm0, *(int32_t *)0x100510f18);
                                        }
                                    }
                                }
                            }
                            var_24 = intrinsic_movss(var_24, xmm0);
                        } else {
                            //loc_10022b171 :
                            xmm0 = intrinsic_movss(xmm0, *(int32_t *)(this + 0x77c));
                            xmm0 = intrinsic_ucomiss(xmm0, *(int32_t *)value 1.0);
                            if ((xmm0) || (!CPU_FLAGS & NP)) {
                                xmm0 = intrinsic_movss(xmm0, var_24);
                                xmm0 = intrinsic_mulss(xmm0, *(int32_t *)value 1.4);
                                var_24 = intrinsic_movss(var_24, xmm0);
                            }
                        }
                    } else if(ringObj->objectType == kPinkRing) {
                        // loc_10022b12a :
                        if (this->isShip != 0x0) {
                            xmm0 = intrinsic_movss(xmm0, var_24);
                            xmm0 = intrinsic_mulss(xmm0, *(int32_t *)0x100510f24);
                        } else {
                            if (*(int8_t *)(this + 0x771) != 0x0) {
                                xmm0 = intrinsic_movss(xmm0, var_24);
                                xmm0 = intrinsic_mulss(xmm0, *(int32_t *)0x10050f184);
                            } else {
                                if (*(int8_t *)(this + 0x772) != 0x0) {
                                    xmm0 = intrinsic_movss(xmm0, var_24);
                                    xmm0 = intrinsic_mulss(xmm0, *(int32_t *)0x100510f28);
                                } else {
                                    xmm0 = intrinsic_movss(xmm0, var_24);
                                    xmm0 = intrinsic_mulss(xmm0, *(int32_t *)0x100510480);
                                }
                            }
                        }
                        var_24 = intrinsic_movss(var_24, xmm0);
                    } else if (ringObj->objectType == kGreenRing || ringObj->objectType == kBlueRing) {
                        if (ringObj->objectType == kGreenRing) {
                            if (this->isShip != 0x0) {
                                xmm0 = intrinsic_movss(xmm0, var_24);
                                xmm0 = intrinsic_mulss(xmm0, *(int32_t *)value 0.70);
                            } else {
                                xmm0 = intrinsic_movss(xmm0, var_24);
                            }
                        } else {
                            xmm0 = intrinsic_movss(xmm0, var_24);
                            xmm0 = intrinsic_mulss(xmm0, *(int32_t *)value 0.8);
                        }

                        //common code
                        var_24 = intrinsic_movss(var_24, xmm0);
                        r15 = this->inPlayLayer;
                        rax = GM;
                        if (r15) {
                            rdi = *(rax + 0x180);
                            rax = *rdi;
                            rdx = *(int8_t *)(this + 0x776) == 0x0 ? 0x1 : 0x0;
                            (*(rax + 0x460))(rdi, this, rdx, 0x1);
                            PlayLayer::playGravityEffect(PLAYLAYER, *(int8_t *)(this + 0x776) & 0xff);
                        }
                        else {
                            if (*(rax + 0x188) != 0x0) {
                                rdi = EDITLAYER;
                                rax = *rdi;
                                rdx = *(int8_t *)(this + 0x776) == 0x0 ? 0x1 : 0x0;
                                (*(rax + 0x460))(rdi, this, rdx, 0x1);
                            }
                            else {
                                rdx = 0x1;
                                PlayerObject::flipGravity(this, *(int8_t *)(this + 0x776) == 0x0 ? 0x1 : 0x0, rdx);
                            }
                        }
                    } else {
                        //loc_10022b19a.
                        if (*(int8_t *)(this + 0x774)) {
                            //loc_10022b1a7
                            xmm0 = intrinsic_movss(xmm0, var_24);
                            xmm0 = intrinsic_mulss(xmm0, *(int32_t *)value 0.9);
                            var_24 = intrinsic_movss(var_24, xmm0);
                        }
                    }
                    xmm0 = intrinsic_movss(xmm0, *(int32_t *)(0x10050e370 + r15 * 0x4));
                    var_44 = intrinsic_movss(var_44, xmm0);
                    COND = *(int8_t *)(this + 0x776) == 0x0;
                    xmm0 = intrinsic_movss(xmm0, var_24);
                    xmm0 = intrinsic_mulss(xmm0, *(int32_t *)(0x10050d470 + (COND ? 0x1 : 0x0) * 0x4));
                    xmm1 = intrinsic_movss(xmm1, var_44);
                    xmm1 = intrinsic_mulss(xmm1, xmm0);
                    xmm0 = intrinsic_cvtss2sd(0x0, xmm1);
                    *(this + 0x760) = intrinsic_movsd(*(this + 0x760), xmm0);
                    if (*(int8_t *)(this + 0x772) != 0x0) {
                        sub_10021cb10(this);
                    }
                    else {
                        PlayerObject::runRotateAction(this, 0x0, rdx);
                    }
                    rax = *this;
                    rax = (*(rax + 0xc0))(this);
                    cocos2d::CCPoint::operator=(this + 0x7a4, rax);
                    sub_10021aef0(this);
                    *(int8_t *)(this + 0x7c1) = 0x1;
                    if ((*(int8_t *)(this + 0x772) != 0x0) || (*(int8_t *)(this + 0x775) != 0x0)) {
                        xmm0 = intrinsic_movsd(xmm0, *(this + 0x760));
                        xmm0 = intrinsic_mulsd(xmm0, *0x100511168);
                        *(this + 0x760) = intrinsic_movsd(*(this + 0x760), xmm0);
                        *(int8_t *)(this + 0x745) = 0x0;
                    }

                    // loc_10022b5d5 :
                    if (ringObj->objectType == kRedRing) {
                        *(int8_t *)(this + 0x732) = 0x1;
                    }
                }
            } else {
                //loc_10022ad17
                r15 = this->inPlayLayer;
                rax = GM;
                if (r15) {
                        rdi = *(rax + 0x180);
                        rax = *rdi;
                        (*(rax + 0x460))(rdi, this, *(int8_t *)(this + 0x776) == 0x0 ? 0x1 : 0x0, 0x1);
                        PlayLayer::playGravityEffect(PLAYLAYER, *(int8_t *)(this + 0x776) & 0xff);
                } else {
                        if (*(rax + 0x188) != 0x0) {
                                rdi = EDITLAYER;
                                rax = *rdi;
                                (*(rax + 0x460))(rdi, this, *(int8_t *)(this + 0x776) == 0x0 ? 0x1 : 0x0, 0x1);
                        } else {
                                PlayerObject::flipGravity(this, *(int8_t *)(this + 0x776) == 0x0 ? 0x1 : 0x0, 0x1);
                        }
                }
                //loc_10022af5e
                sub_100221d70(this, ringObj);
            }
        }
    }
    if (!this->unknown_629) {
        auto circleCol = ccc3(255,255,255); 
        if (this->inPlayLayer && !GM->unknown_2a1 && !loc_100342a80(ringObj)) {
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
                    rdi = *(ringObj + 0x350);
                    if (rdi) {
                        rax = *rdi;
                    }
                    else {
                        rax = *ringObj;
                    }
                    rax = (*(rax + 0x388))();
                    rcx = *(int16_t *)rax & 0xffff;
                    circleCol = *(int8_t *)(rax + 0x2) & 0xff;
                    circleCol = circleCol << 0x10 | rcx;
                    break;
                default: // rob made yellow the default case
                    circleCol = ccc3(255,200,0);
            }
            intrinsic_movss(xmm0, *(int32_t *)(0x100511178 + (ringObj->objectType == 0x23 ? 0x1 : 0x0) * 0x4));
            intrinsic_movss(xmm1, *(int32_t *)value 5.0);
            intrinsic_movss(xmm2, *(int32_t *)0x10050c770);
            r12 = CCCircleWave::create(0x1);
            *(int8_t *)(r12 + 0x136) = circleCol >> 0x10;
            *(int16_t *)(r12 + 0x134) = circleCol;
            r15 = *(*r12 + 0xb8);
            rax = *ringObj;
            rax = (*(rax + 0xc0))(ringObj);
            (r15)(r12, rax);
            CCCircleWave::followObject(r12, ringObj, 0x1);
            rax = GM;
            rax = *(rax + 0x180);
            rcx = rax + 0x4b0;
            if (rax == 0x0) {
                rcx = rax;
            }
            *(r12 + 0x150) = rcx;
            PLAYLAYER->addCircle();
            rdi = *(this + 0x798);
            rax = *rdi;
            (*(rax + 0x1c0))(rdi, r12, 0x0);
        }
    }
    GameObject::activatedByPlayer(ringObj, this);
    rax = *ringObj;
    (*(rax + 0x590))(ringObj);
    if (this->inPlayLayer) {
        PLAYLAYER->incrementJumps();
        *(int8_t *)(this + 0x7c0) = 0x1;
    }
    return ;
}

.l3:
    return;

loc_10022ac1b :
    if (((this->hasJustHeld == 0x0) || (this->isDashing)) || (this->isHolding2 == 0x0)) goto .l3;

loc_10022ac36 :
    if (this->canHitCustomRing || (ringObj->objectType == kCustomRing)) goto loc_10022ac50;

loc_10022ac6a :
    this->hasJustHitRing = 0x1;
    if (ringObj->objectType == kCustomRing) {
            this->unknown_74a = 0x1;
    }
    else {
            this->canHitCustomRing = 0x1;
    }
    this->untouchedRings->removeObject(ringObj);
    if (ringObj->objectType != kCustomRing) {
            this->unknown_628 = 0x1;
    }
    if (ringObj->objectType != kCustomRing) goto loc_10022acf1;

loc_10022accf :
    r15 = this->inEditorMode;
    rax = GM;
    if (r15) {
            rdi = *(rax + 0x188);
    }
    else {
            rdi = *(rax + 0x180);
    }
    rdi->objectTriggered(ringObj);
    this->hasQueuedHold = 0x0;
    goto chunk1;

loc_10022acf1 :
    if (ringObj->objectType == kGreenDashRing) goto loc_10022af5e;

loc_10022ad06 :
    if (ringObj->objectType != kPinkDashRing) goto loc_10022ad96;

loc_10022ad17 :
    r15 = this->inPlayLayer;
    rax = GM;
    if (r15) {
            rdi = *(rax + 0x180);
            rax = *rdi;
            (*(rax + 0x460))(rdi, this, *(int8_t *)(this + 0x776) == 0x0 ? 0x1 : 0x0, 0x1);
            PlayLayer::playGravityEffect(PLAYLAYER, *(int8_t *)(this + 0x776) & 0xff);
    }
    else {
            if (*(rax + 0x188) != 0x0) {
                    rdi = EDITLAYER;
                    rax = *rdi;
                    (*(rax + 0x460))(rdi, this, *(int8_t *)(this + 0x776) == 0x0 ? 0x1 : 0x0, 0x1);
            }
            else {
                    PlayerObject::flipGravity(this, *(int8_t *)(this + 0x776) == 0x0 ? 0x1 : 0x0, 0x1);
            }
    }
    goto loc_10022af5e;

loc_10022af5e :
    sub_100221d70(this, ringObj);
    goto chunk1;


loc_10022ad96 :
    if (ringObj->objectType != kBlackRing) goto loc_10022ae24;

loc_10022ada7 :
    this->hasQueuedHold = 0x0;
    rax = *(int8_t *)(this + 0x771);
    rcx = *(int8_t *)(this + 0x776);
    rdx = rcx == 0x0 ? 0x1 : 0x0;
    if (this->isShip != 0x0) goto loc_10022addf;

loc_10022adca :
    rax = 0x1;
    if (0x1) goto loc_10022addf;

loc_10022add0 :
    if (*(int8_t *)(this + 0x773) == 0x0) goto loc_10022b1b9;

loc_10022addd :
    rax = 0x0;
    goto loc_10022addf;

loc_10022addf :
    rdx = rcx == 0x0 ? 0x1 : 0x0;
    xmm0 = intrinsic_movss(xmm0, *(int32_t *)(14 or -14 + rdx * 0x4));
    if (rax) {
            xmm0 = intrinsic_mulss(xmm0, *(int32_t *)value 0.8);
    }
    goto loc_10022adfe;

loc_10022adfe :
    xmm0 = intrinsic_cvtss2sd(xmm0, xmm0);
    *(this + 0x760) = intrinsic_movsd(*(this + 0x760), xmm0);
    if (*(int8_t *)(this + 0x772) != 0x0) {
            sub_10021cb10(this);
    }
    else {
            PlayerObject::runRotateAction(this, 0x0, rdx);
    }
    sub_10021aef0(this);
    *(int8_t *)(this + 0x7c1) = 0x1;
    *(int8_t *)(this + 0x732) = 0x1;
    if (*(int8_t *)(this + 0x772) != 0x0) {
            *(int8_t *)(this + 0x745) = 0x0;
            goto chunk1;
    }
    else {
            goto chunk1;
    }


loc_10022b1b9 :
    xmm0 = intrinsic_movss(xmm0, *(int32_t *)(0x100511138 + rdx * 0x4));
    if ((*(int8_t *)(this + 0x774) == 0x0) && (*(int8_t *)(this + 0x775) != 0x0)) {
            xmm0 = intrinsic_mulss(xmm0, *(int32_t *)value 1.10);
    }
    goto loc_10022adfe;

loc_10022ae24 :
    *(int8_t *)(this + 0x7a1) = 0x1;
    *(int8_t *)(this + 0x7a0) = 0x0;
    *(int8_t *)(this + 0x778) = 0x0;
    this->hasQueuedHold = 0x0;
    xmm0 = intrinsic_movss(xmm0, *(int32_t *)(this + 0x77c));
    asm{ cmpneqss   xmm0, dword [value 1.0] };
    r15 = zero_extend_32(xmm0) & 0x1;
    xmm0 = intrinsic_movsd(xmm0, *(this + 0x610));
    xmm0 = intrinsic_cvtsd2ss(xmm0, xmm0);
    var_24 = intrinsic_movss(var_24, xmm0);
    if (ringObj->objectType != kBlueRing) goto loc_10022aed1;

loc_10022ae83 :
    xmm0 = intrinsic_movss(xmm0, var_24);
    xmm0 = intrinsic_mulss(xmm0, *(int32_t *)value 0.8);
    goto loc_10022b2f9;

loc_10022b2f9 :
    var_24 = intrinsic_movss(var_24, xmm0);
    goto loc_10022b2fe;

loc_10022b2fe :
    xmm0 = intrinsic_movss(xmm0, *(int32_t *)(0x10050e370 + r15 * 0x4));
    var_44 = intrinsic_movss(var_44, xmm0);
    if (ringObj->objectType == kGreenRing) {
            r15 = this->inPlayLayer;
            rax = GM;
            if (r15) {
                    rdi = *(rax + 0x180);
                    rax = *rdi;
                    rdx = *(int8_t *)(this + 0x776) == 0x0 ? 0x1 : 0x0;
                    (*(rax + 0x460))(rdi, this, rdx, 0x1);
                    PlayLayer::playGravityEffect(PLAYLAYER, *(int8_t *)(this + 0x776) & 0xff);
            }
            else {
                    if (*(rax + 0x188) != 0x0) {
                            rdi = EDITLAYER;
                            rax = *rdi;
                            rdx = *(int8_t *)(this + 0x776) == 0x0 ? 0x1 : 0x0;
                            (*(rax + 0x460))(rdi, this, rdx, 0x1);
                    }
                    else {
                            rdx = 0x1;
                            PlayerObject::flipGravity(this, *(int8_t *)(this + 0x776) == 0x0 ? 0x1 : 0x0, rdx);
                    }
            }
    }
    COND = *(int8_t *)(this + 0x776) == 0x0;
    xmm0 = intrinsic_movss(xmm0, var_24);
    xmm0 = intrinsic_mulss(xmm0, *(int32_t *)(0x10050d470 + (COND ? 0x1 : 0x0) * 0x4));
    xmm1 = intrinsic_movss(xmm1, var_44);
    xmm1 = intrinsic_mulss(xmm1, xmm0);
    xmm0 = intrinsic_cvtss2sd(0x0, xmm1);
    *(this + 0x760) = intrinsic_movsd(*(this + 0x760), xmm0);
    if (*(int8_t *)(this + 0x772) != 0x0) {
            sub_10021cb10(this);
    }
    else {
            PlayerObject::runRotateAction(this, 0x0, rdx);
    }
    rax = *this;
    rax = (*(rax + 0xc0))(this);
    cocos2d::CCPoint::operator=(this + 0x7a4, rax);
    sub_10021aef0(this);
    *(int8_t *)(this + 0x7c1) = 0x1;
    if ((*(int8_t *)(this + 0x772) != 0x0) || (*(int8_t *)(this + 0x775) != 0x0)) {
            xmm0 = intrinsic_movsd(xmm0, *(this + 0x760));
            xmm0 = intrinsic_mulsd(xmm0, *0x100511168);
            *(this + 0x760) = intrinsic_movsd(*(this + 0x760), xmm0);
            *(int8_t *)(this + 0x745) = 0x0;
    }
    if (ringObj->objectType != kBlueRing) goto loc_10022b533;

loc_10022b47f :
    r15 = this->inPlayLayer;
    rax = GM;
    if (r15 == 0x0) goto loc_10022b4db;

loc_10022b491 :
    rdi = *(rax + 0x180);
    rax = *rdi;
    (*(rax + 0x460))(rdi, this, *(int8_t *)(this + 0x776) == 0x0 ? 0x1 : 0x0, 0x1);
    PlayLayer::playGravityEffect(PLAYLAYER, *(int8_t *)(this + 0x776) & 0xff);
    if (*(int8_t *)(this + 0x774) != 0x0) goto loc_10022b53c;

loc_10022b569 :
    if (*(int8_t *)(this + 0x775) == 0x0) goto loc_10022b5d5;

loc_10022b572 :
    CCAnimatedSprite::stopTween(*(this + 0x6b0));
    SpriteAnimationManager::stopAnimations(*(*(this + 0x6b0) + 0x248));
    r15 = *(this + 0x6b0);
    std::basic_string<char, std::char_traits<char>, std::allocator<char> >::basic_string(var_38, "jump", var_30);
    xmm0 = intrinsic_movss(xmm0, *(int32_t *)0x100510ea4);
    CCAnimatedSprite::tweenToAnimation(r15, var_38);
    rax = var_38;
    goto loc_10022b5c4;

loc_10022b5c4 :
    if (rax + 0xffffffffffffffe8 != std::string::_Rep::_S_empty_rep_storage) {
            *(int32_t *)(rax + 0xfffffffffffffff8) = lock intrinsic_xadd(*(int32_t *)(rax + 0xfffffffffffffff8), 0xffffffff);
            if (0xffffffff <= 0x0) {
                    std::string::_Rep::_M_destroy();
            }
    }
    goto loc_10022b5d5;

loc_10022b5d5 :
    if (ringObj->objectType == 0x23) {
            *(int8_t *)(this + 0x732) = 0x1;
            goto chunk1;
    }
    else {
            goto chunk1;
    }


loc_10022b53c :
    r15 = *(this + 0x6a8);
    std::basic_string<char, std::char_traits<char>, std::allocator<char> >::basic_string(var_40, "jump_start", var_30);
    CCAnimatedSprite::runAnimation(r15);
    rax = var_40;
    goto loc_10022b5c4;

loc_10022b4db :
    if (*(rax + 0x188) == 0x0) goto loc_10022b519;

loc_10022b4e5 :
    rdi = EDITLAYER;
    rax = *rdi;
    (*(rax + 0x460))(rdi, this, *(int8_t *)(this + 0x776) == 0x0 ? 0x1 : 0x0, 0x1);
    if (*(int8_t *)(this + 0x774) != 0x0) goto loc_10022b53c;
    goto loc_10022b569;

loc_10022b519 :
    PlayerObject::flipGravity(this, *(int8_t *)(this + 0x776) == 0x0 ? 0x1 : 0x0, 0x1);
    goto loc_10022b533;

loc_10022b533 :
    if (*(int8_t *)(this + 0x774) == 0x0) goto loc_10022b569;
    goto loc_10022b53c;

loc_10022aed1 :
    if (ringObj->objectType != kGreenRing) goto loc_10022b119;

loc_10022aee6 :
    if (this->isShip != 0x0) {
            xmm0 = intrinsic_movss(xmm0, var_24);
            xmm0 = intrinsic_mulss(xmm0, *(int32_t *)value 0.70);
    }
    else {
            xmm0 = intrinsic_movss(xmm0, var_24);
    }
    goto loc_10022b2f9;

loc_10022b119 :
    if (ringObj->objectType != kPinkRing) goto loc_10022b153;

loc_10022b12a :
    if (this->isShip != 0x0) {
            xmm0 = intrinsic_movss(xmm0, var_24);
            xmm0 = intrinsic_mulss(xmm0, *(int32_t *)0x100510f24);
    }
    else {
            if (*(int8_t *)(this + 0x771) != 0x0) {
                    xmm0 = intrinsic_movss(xmm0, var_24);
                    xmm0 = intrinsic_mulss(xmm0, *(int32_t *)0x10050f184);
            }
            else {
                    if (*(int8_t *)(this + 0x772) != 0x0) {
                            xmm0 = intrinsic_movss(xmm0, var_24);
                            xmm0 = intrinsic_mulss(xmm0, *(int32_t *)0x100510f28);
                    }
                    else {
                            xmm0 = intrinsic_movss(xmm0, var_24);
                            xmm0 = intrinsic_mulss(xmm0, *(int32_t *)0x100510480);
                    }
            }
    }
    goto loc_10022b2f9;

loc_10022b153 :
    if (ringObj->objectType != 0x23) goto loc_10022b19a;

loc_10022b164 :
    if (this->isShip == 0x0) goto loc_10022b20a;

loc_10022b171 :
    xmm0 = intrinsic_movss(xmm0, *(int32_t *)(this + 0x77c));
    xmm0 = intrinsic_ucomiss(xmm0, *(int32_t *)value 1.0);
    if ((xmm0) || (!CPU_FLAGS & NP)) goto loc_10022b188;
    goto loc_10022b2fe;

loc_10022b188 :
    xmm0 = intrinsic_movss(xmm0, var_24);
    xmm0 = intrinsic_mulss(xmm0, *(int32_t *)value 1.4);
    goto loc_10022b2f9;

loc_10022b20a :
    if (*(int8_t *)(this + 0x771) != 0x0) {
            xmm0 = intrinsic_movss(xmm0, *(int32_t *)(this + 0x77c));
            xmm0 = intrinsic_ucomiss(xmm0, *(int32_t *)value 1.0);
            if ((xmm0 == 0x0) && (CPU_FLAGS & NP)) {
                    xmm0 = intrinsic_movss(xmm0, var_24);
                    xmm0 = intrinsic_mulss(xmm0, *(int32_t *)0x100510f10);
            }
            else {
                    xmm0 = intrinsic_movss(xmm0, var_24);
                    xmm0 = intrinsic_mulss(xmm0, *(int32_t *)0x100510f14);
            }
    }
    else {
            if (*(int8_t *)(this + 0x772) != 0x0) {
                    xmm0 = intrinsic_movss(xmm0, var_24);
                    xmm0 = intrinsic_mulss(xmm0, *(int32_t *)0x100510f18);
            }
            else {
                    if (*(int8_t *)(this + 0x774) != 0x0) {
                            xmm0 = intrinsic_movss(xmm0, var_24);
                            xmm0 = intrinsic_mulss(xmm0, *(int32_t *)0x100510f1c);
                    }
                    else {
                            if (*(int8_t *)(this + 0x775) == 0x0) {
                                    xmm0 = intrinsic_movss(xmm0, var_24);
                                    xmm0 = intrinsic_mulss(xmm0, *(int32_t *)0x100510f20);
                            }
                            else {
                                    xmm0 = intrinsic_movss(xmm0, var_24);
                                    xmm0 = intrinsic_mulss(xmm0, *(int32_t *)0x100510f18);
                            }
                    }
            }
    }
    goto loc_10022b2f9;

loc_10022b19a :
    if (*(int8_t *)(this + 0x774) == 0x0) goto loc_10022b2fe;

loc_10022b1a7 :
    xmm0 = intrinsic_movss(xmm0, var_24);
    xmm0 = intrinsic_mulss(xmm0, *(int32_t *)value 0.9);
    goto loc_10022b2f9;

loc_10022ac50 :
    if ((this->unknown_74a != 0x0) || (ringObj->objectType != kCustomRing)) goto .l3;
    goto loc_10022ac6a;

