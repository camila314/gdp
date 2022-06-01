        //loc_10021e281:
        CMP(r10, 0x1);
        rax = !(rax - rax + CARRY(RFLAGS(cf))) | 0x1;
        rcx = -rax;
        *(this + 0x578) = gobj;
        m_collidedSlopeObj = gobj;
        *(int32_t *)(this + 0x580) = intrinsic_movss(*(int32_t *)(this + 0x580), intrinsic_subss(xmm5, xmm1));
        *(int8_t *)(this + 0x733) = var_34;
        *(int32_t *)(this + 0x72c) = intrinsic_movss(*(int32_t *)(this + 0x72c), xmm4);
        m_collidedUUID = *(int32_t *)(gobj + 0x36c);
        *(int8_t *)(this + 0x588) = r9;
        xmm0 = *(int32_t *)(this + 0x724);
        var_34 = xmm0;
        m_unknown_730 = var_2C;
        *(int8_t *)(this + 0x731) = r8;
        if (r9 != 0x0) {
            rcx = rax;
        }
        rax = -rcx;
        if (var_9C == 0x0) {
            rax = rcx;
        }
        xmm0 = *(int32_t *)0x10050db64;
        xmm0 *= var_7C;
        xmm1 = intrinsic_cvtsi2ss(xmm1, rax);
        xmm1 *= xmm0;
        xmm1 *= *(int32_t *)0x10050cad4;
        *(int32_t *)(this + 0x724) = intrinsic_movss(*(int32_t *)(this + 0x724), xmm1);
        rax = *this;
        r13 = *(rax + 0xb8);
        var_60 = intrinsic_movaps(var_60, xmm4);
        xmm0 = *(int32_t *)(*(rax + 0xc0))();
        xmm1 = intrinsic_movapd(xmm1, var_60);
        cocos2d::CCPoint::CCPoint(var_78, xmm0, xmm1);
        (r13)(this, var_78);
        *(int8_t *)(this + 0x768) = 0x1;
        if (m_onSlope2 == 0x0) {
            *(this + 0x500) = *(this + 0x7d8);
        }
        r13 = var_44;
        xmm2 = intrinsic_movaps(xmm2, var_C0);
        rbx = var_40;
        rax = var_70;
        if (r12 == 0x0) {
            if (var_B0 != 0x0) {
                COND = m_upsideDown == 0x0;
                xmm0 = m_yAccel;
                r12 = rax;
                xmm1 = intrinsic_xorpd(xmm1, xmm1);
                if (!COND) {
                    xmm1 = intrinsic_ucomisd(xmm1, xmm0);
                    if (xmm1 <= 0x0) {
                        xmm1 = intrinsic_movapd(xmm1, xmm0);
                    }
                } else {
                    xmm0 = intrinsic_ucomisd(xmm0, xmm1);
                    if (xmm0 <= 0x0) {
                        xmm1 = intrinsic_movapd(xmm1, xmm0);
                    }
                }
                m_yAccel = xmm1;
                m_onGround = 0x0;
                m_isSliding = 0x0;
                r14 = *(int32_t *)(r14 + 0x36c);
                xmm0 = *(int32_t *)((*(*this + 0x4f8))(this) + 0xc);
                xmm0 *= 0.5;
                var_60 = xmm0;
                rax = *this;
                rax = (*(rax + 0xc0))(this);
                xmm3 = var_60;
                rcx = m_upsideDown;
                xmm3 *= *(int32_t *)(-1.0 + (!rcx) * 0x4);
                xmm3 += *(int32_t *)(rax + 0x4);
                xmm0 = *(int32_t *)(this + 0x734);
                xmm1 = intrinsic_xorpd(xmm1, xmm1);
                xmm0 = intrinsic_ucomiss(xmm0, xmm1);
                if ((xmm0 == 0x0) && (!CPU_FLAGS & P)) {
                    xmm2 = intrinsic_movaps(xmm2, var_C0);
                    rbx = var_40;
                    rax = r12;
                } else {
                    xmm2 = intrinsic_movaps(xmm2, var_C0);
                    rbx = var_40;
                    rax = r12;
                    if (rcx != 0x0) {
                        xmm3 = intrinsic_maxss(xmm3, xmm0);
                    } else {
                        xmm3 = intrinsic_minss(xmm3, xmm0);
                    }
                }
                *(int32_t *)(this + 0x734) = intrinsic_movss(*(int32_t *)(this + 0x734), xmm3);
                if ((r14 != 0x0) && (*(int32_t *)(this + 0x564) != r14)) {
                    rbx = rax;
                    *(int32_t *)(this + 0x564) = r14;
                    cocos2d::CCDictionary::setObject(*(this + 0x518), *(this + 0x510), sign_extend_64(r14));
                    rax = rbx;
                    rbx = var_40;
                    xmm2 = intrinsic_movaps(xmm2, var_C0);
                }
            } else {
                r12 = rax;
                PlayerObject::hitGround(this, 0x0, 0x0);
                rbx = *(int32_t *)(gobj + 0x36c);
                xmm0 = *(int32_t *)((*(*this + 0x4f8))(this) + 0xc);
                xmm0 *= -0.5;
                var_60 = xmm0;
                rax = *this;
                rax = (*(rax + 0xc0))(this);
                xmm2 = var_60;
                rcx = m_upsideDown;
                xmm2 *= *(int32_t *)(-1.0 + (!rcx) * 0x4);
                xmm2 += *(int32_t *)(rax + 0x4);
                xmm0 = *(int32_t *)(this + 0x738);
                xmm1 = intrinsic_xorpd(xmm1, xmm1);
                xmm0 = intrinsic_ucomiss(xmm0, xmm1);
                if ((xmm0 != 0x0) || (!CPU_FLAGS & NP)) {
                    if (rcx != 0x0) {
                        xmm2 = intrinsic_minss(xmm2, xmm0);
                    } else {
                        xmm2 = intrinsic_maxss(xmm2, xmm0);
                    }
                }
                *(int32_t *)(this + 0x738) = intrinsic_movss(*(int32_t *)(this + 0x738), xmm2);
                if ((rbx != 0x0) && (*(int32_t *)(this + 0x560) != rbx)) {
                    *(int32_t *)(this + 0x560) = rbx;
                    cocos2d::CCDictionary::setObject(*(this + 0x520), *(this + 0x510), sign_extend_64(rbx));
                }
                *(this + 0x528) = gobj;
                rax = GameObject::getLastPosition(gobj);
                cocos2d::CCPoint::CCPoint(var_78, rax);
                rax = *gobj;
                (*(rax + 0x518))(var_98, gobj);
                xmm0 = var_98;
                xmm2 = intrinsic_movaps(xmm2, var_C0);
                rbx = var_40;
                rax = r12;

                if (xmm0 != var_78 || var_94 != var_7474) {
                    xmm1 = var_74;
                    xmm0 = var_94;
                    if (this->flipMod()*xmm0 > this->flipMod()*xmm1) {
                        xmm0 += xmm1;
                        xmm0 = intrinsic_divss(xmm0, var_48);
                        *(int32_t *)(this + 0x54c) = intrinsic_movss(*(int32_t *)(this + 0x54c), xmm0);
                    }
                }
            }
        }

        if ((rax & 0x1) != 0x0) {
            rax = m_upsideDown;
            xmm0 = m_yAccel;
            if (this->flipMod()*xmm0 > -2.0) {
                xmm0 = *(0x100510fb0 + (!rax) * 0x8);
                m_yAccel = xmm0;
            }
        }

        rcx = m_upsideDown;
        if (var_30 == 0x0) {
            //loc_10021e537:
            rax = rcx;
        } else {
            //loc_10021e458:
            xmm0 = m_yAccel;
            if (rcx == 0x0) {
                //loc_10021e509:
                xmm1 = *0x10050d498;
                xmm1 = intrinsic_ucomisd(xmm1, xmm0);
            } else {
                //loc_10021e469:
                rax = 0x1;
                xmm0 = intrinsic_ucomisd(xmm0, *0x100511118);
            }
            if (xmm1 > 0x0) {
                //loc_10021e51b:
                xmm0 = *(0x100510fc0 + (!rcx) * 0x8);
                m_yAccel = xmm0;
                rax = rcx;
            } else {
                rax = 0x0;
            }
        }
        //loc_10021e539:
        *(int32_t *)(this + 0x728) = intrinsic_movss(*(int32_t *)(this + 0x728), xmm2);
        xmm0 = 0.8;
        xmm0 = intrinsic_divss(xmm0, var_7C);
        xmm0 = intrinsic_minss(xmm0, 1.10);
        xmm2 *= 1.4;
        xmm2 *= xmm0;
        if (rbx == 0x0 || r13 != 0x0) {
            xmm0 = xmm2;
        } else {
            xmm0 = -xmm2;
        }

        xmm0 *= *(int32_t *)(-1.0 + (!rax) * 0x4);
        *(int32_t *)(this + 0x76c) = intrinsic_movss(*(int32_t *)(this + 0x76c), xmm0);
        if (!m_isShip && !m_isBird && !m_isDart && !m_isBall) {
            xmm0 = var_48;
            PlayerObject::updateSlopeRotation(this);
        } else {
            xmm0 *= *(int32_t *)0x10050c730;
            *(int32_t *)(this + 0x76c) = intrinsic_movss(*(int32_t *)(this + 0x76c), xmm0);
            if (m_isBall) {
                xmm0 = *(int32_t *)(this + 0x724);
                xmm1 = var_34;
                xmm1 = intrinsic_ucomiss(xmm1, xmm0);
                if ((xmm1 != 0x0) || (!CPU_FLAGS & NP)) {
                    xmm0 = intrinsic_cvtss2sd(xmm0, xmm0);
                    cos(xmm0);
                    var_40 = xmm0;
                    cocos2d::CCNode::stopActionByTag(this, 0x0);
                    rax = cocos2d::CCNode::stopActionByTag(this, 0x1);
                    *(int8_t *)(this + 0x568) = 0x0;
                    if (!m_isDashing) {
                        xmm0 = *value 1.0 v2;
                        xmm0 = intrinsic_divsd(xmm0, var_40);
                        xmm1 = intrinsic_cvtsd2ss(0x0, xmm0);
                        xmm1 += -1.00;
                        xmm1 *= 0.70;
                        xmm1 += 1.0;
                        xmm1 = intrinsic_ucomiss(xmm1, 1.0);
                        COND = xmm1 != 0x0;
                        *(int8_t *)(this + 0x568) = (COND ? 0x1 : 0x0) | rax;
                        xmm2 = m_vehicleSize;
                        xmm0 = m_playerSpeedMultiplier;

                        switch (xmm9) {
                            case 0.7:
                                xmm0 = *(int32_t *)0x100510ec8;
                            case 1.10:
                                xmm0 = *(int32_t *)0x100510ecc;
                            case 1.30:
                                xmm0 = *(int32_t *)0x100510ed0;
                            case 1.60:
                                xmm0 = *(int32_t *)0x100510ed4;
                            default:
                                xmm0 = 1.0;
                        }

                        COND = m_upsideDown == 0x0;
                        xmm0 *= *(int32_t *)(0x1005110b8 + (zero_extend_32(xmm2 == 1.0) & 0x1) * 0x4);
                        intrinsic_mulss(xmm1, *(int32_t *)(0x1005110c0 + (COND ? 0x1 : 0x0) * 0x4));
                        rbx = cocos2d::CCRepeatForever::create(cocos2d::CCRotateBy::create());
                        rax = *rbx;
                        (*(rax + 0x48))(rbx, 0x0);
                        cocos2d::CCNode::runAction(this, rbx);
                    }
                }
            } else {
                xmm0 = var_48;
                PlayerObject::updateSlopeRotation(this);
            }
        }
        return;

