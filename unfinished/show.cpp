PlayerObject::collidedWithSlope(float arg0, GameObject* gobj, int arg2) {
    if (arg2 || !this->preSlopeCollision(gobj)) {
        //loc_10021d90f:
        auto playerRect = this->getObjectRect();
        auto objRect = gobj->getObjectRect();

        auto slopeTop = gobj->slopeFloorTop();
        float objDistance = gobj->getRealPosition().x - gobj->getLastPosition().x;
        float movedDistance = arg0 * m_playerSpeed * m_playerSpeedMultiplier;

        r13 = false;
        var_9C = false;
        if (objDistance > movedDistance) {
            var_9C = true;
            r13 = m_upsideDown;
            if (m_goingUphill) {
                r13 = !r13;
            }
        }

        var_40 = m_upsideDown;
        if (objDistance <= movedDistance) {
            var_40 = !rcx;
        }

        var_30 = gobj->getRealPosition().y - gobj->getLastPosition().y;

        if (m_onSlope2) {
            //loc_10021da5c:
            if (var_40)  {
                //loc_10021da67:

                xmm0 = (!m_upsideDown ? 1.0 : -1.0) * m_slopeRotation;
                if (xmm0 > 0 && m_unknown_733 == rcx && m_unknown_733 == slopeTop) {
                    return;
                }
            }
        }

        //loc_10021da9f:
        var_C0 = objRect.size.height / (objRect.size.width / (m_playerSpeedMultiplier * m_playerSpeed));
        if (m_onSlope2) {
            //loc_10021dada:
            if (m_slopeRotation * (rcx ? 1 : -1) > 0) {
                //loc_10021daff:
                if (m_unknown_728 > var_C0)
                    return;
            }
        }

        //loc_10021db11:
        var_60 = var_40 ? 1.0 : 0.0;

        if (m_onSlope2) {
            var_60 = var_40 ? 4.0 : 0.0;
        }

        r12 = true;
        if (-var_30 <= 0 || m_upsideDown) {
            r12 = gobj->getLastPosition().y > -var_30 && m_upsideDown;
        }

        if (r12 || arg2) {
            var_60 += min(arg0 * 5, -var_30);
        }
        var_70 = objRect.size.height * 0.5;
        xmm0 = cos(m_slopeRotation);
        xmm1 = var_70;
        xmm1 = intrinsic_divsd(xmm1, xmm0);
        xmm0 = intrinsic_cvtsd2ss(0x0, xmm1);
        var_70 = xmm0;
        xmm0 = *(int32_t *)((*(*this + 0xc0))(this) + 0x4);
        if (m_upsideDown) {
            //loc_10021dc30:
            xmm1 = var_70;
            xmm1 += xmm0;
            xmm1 += var_60;
            xmm0 = xmm1;
        } else {
            //loc_10021dc4d:
            xmm0 += var_70;
            xmm0 += var_60;
        }

        if (m_onSlope2) {
            //loc_10021dc61:
            xmm1 = objRect.origin.y;
            if (m_upsideDown == 0x0) {
                //loc_10021dcda:
                xmm1 += objRect.size.height;
                if (xmm0 > xmm1) {
                    return;
                }
            } else if (xmm1 > xmm0) {
                return;
            }
        } else {
            //loc_10021dc7d:
            xmm1 = objRect.origin.y;
            xmm1 += 1.0;
            xmm0 = objRect.origin.x;
            xmm2 = objRect.size.width;
            xmm3 = objRect.size.height;
            xmm3 += -2.0;
            cocos2d::CCRect::CCRect(var_D0, xmm0, xmm1, xmm2, xmm3);
            r13 = r13;
            if (!cocos2d::CCRect::intersectsRect(playerRect, var_D0)) {
                return;
            }
        }

        //loc_10021dceb:
        rax = *this;
        rax = (*(rax + 0xc0))(this);
        cocos2d::CCPoint::CCPoint(var_D0, rax);
        cocos2d::CCRect::getMinY(objRect);
        var_B0 = intrinsic_movaps(var_B0, xmm0);
        cocos2d::CCRect::getMaxY(objRect);
        var_110 = intrinsic_movaps(var_110, xmm0);
        xmm1 = *(int32_t *)(gobj + 0x400);
        xmm0 = objRect.size.height;
        var_70 = intrinsic_cvtss2sd(xmm0, xmm0);
        var_7C = xmm1;
        xmm0 = intrinsic_cvtss2sd(0x0, xmm1);
        cos(xmm0);
        xmm1 = var_70;
        xmm1 = intrinsic_divsd(xmm1, xmm0);
        xmm1 *= *0x10050c8b8;
        if ((m_onSlope2 == 0x0) || m_collidedUUID == obj->uuid) {
            var_2C = intrinsic_xorpd(xmm0, xmm0);
            rbx = r13;
            r13 = false;
        } else {
            //loc_10021df0b:
            rbx = r13;
            rcx = slopeTop & 0xff;
            if ((m_unknown_733 & 0xff) != rcx) {
                var_2C = intrinsic_mulss(m_vehicleSize), 20.0;
                r13 = 0x1;
            } else {
                //loc_10021df1e:
                var_2C = intrinsic_xorpd(xmm0, xmm0);
                r13 = false;
            }
        }

        //loc_10021dd94:
        xmm0 = intrinsic_cvtsd2ss(0x0, xmm1);
        var_70 = xmm0;
        xmm0 = var_D0;
        sub_100342900(gobj);
        xmm1 = objRect.size.height;
        xmm1 *= 0.5;
        if (slopeTop == 0x0) {
            //loc_10021ddc6:
            xmm3 = intrinsic_movaps(xmm3, var_B0);
            xmm3 += xmm1;
            xmm2 = var_2C;
            xmm3 += xmm2;
            xmm5 = var_70;
            xmm0 += xmm5;
            xmm0 += xmm2;
            xmm3 = intrinsic_ucomiss(xmm3, xmm0);
            var_2C = xmm3 >= 0x0 ? 0x1 : 0x0;
            xmm2 = intrinsic_movaps(xmm2, xmm0);
            asm{ cmpnless   xmm2, xmm3 };
            xmm0 = intrinsic_andps(xmm0, xmm2);
            xmm2 = intrinsic_andnps(xmm2, xmm3);
            xmm2 = intrinsic_orps(xmm2, xmm0);
            xmm3 = intrinsic_movaps(xmm3, var_110);
            xmm2 = intrinsic_ucomiss(xmm2, xmm3);
            r8 = xmm2 >= 0x0 ? 0x1 : 0x0;
            xmm4 = intrinsic_movaps(xmm4, xmm3);
            asm{ cmpnless   xmm4, xmm2 };
            xmm0 = intrinsic_movaps(xmm0, xmm4);
            xmm0 = intrinsic_andps(xmm0, xmm2);
            xmm4 = intrinsic_andnps(xmm4, xmm3);
            xmm4 = intrinsic_orps(xmm4, xmm0);
            r10 = 0x1;
        } else {
            //loc_10021de3b:
            xmm3 = intrinsic_movaps(xmm3, var_110);
            xmm3 += xmm1;
            xmm2 = var_2C;
            xmm3 += xmm2;
            xmm5 = var_70;
            xmm0 += xmm5;
            xmm0 += xmm2;
            xmm0 = intrinsic_ucomiss(xmm0, xmm3);
            var_2C = xmm0 >= 0x0 ? 0x1 : 0x0;
            xmm2 = intrinsic_movaps(xmm2, xmm3);
            asm{ cmpnless   xmm2, xmm0 };
            xmm0 = intrinsic_andps(xmm0, xmm2);
            xmm2 = intrinsic_andnps(xmm2, xmm3);
            xmm2 = intrinsic_orps(xmm2, xmm0);
            xmm3 = intrinsic_movaps(xmm3, var_B0);
            xmm3 = intrinsic_ucomiss(xmm3, xmm2);
            r8 = xmm3 >= 0x0 ? 0x1 : 0x0;
            xmm4 = intrinsic_movaps(xmm4, xmm2);
            asm{ cmpnless   xmm4, xmm3 };
            xmm0 = intrinsic_movaps(xmm0, xmm4);
            xmm0 = intrinsic_andps(xmm0, xmm2);
            xmm4 = intrinsic_andnps(xmm4, xmm3);
            xmm4 = intrinsic_orps(xmm4, xmm0);
            r10 = 0x0;
        }

        r10 = !r10;
        r9 = var_40;
        if (m_upsideDown != 0x0) {
            //loc_10021df2f:
            r11 = rbx;
            rdi = !r9;
            rax = r13 | rdi;
            if (rax) {
                rsi = false;
            } else {
                if (m_onSlope) {
                    rsi = false;
                } else {
                    if (m_isShip) {
                        rsi = !m_isHolding;
                    } else if (m_isRising && !m_isBird  && !m_isDart) {
                        rsi = false;
                    } else {
                        rsi = true;
                    }
                }
            }
            rdx = 0x1;
            rax = rsi;
            if (r9 == 0x0) {
                rax = 0x1;
            }
            if (arg2 == 0x0) {
                rax = rsi;
            }
            if ((r12 & 0x1) == 0x0) {
                rdx = rax;
            }
            if (r9 == 0x0) {
                rax = rdx;
            }
            xmm0 = var_CC;
            rsi = 0x1;
            if (r10) {
                //loc_10021dfe8:
                if (xmm0 <= xmm4) {
                    //loc_10021dfed:
                    xmm2 = intrinsic_movaps(xmm2, xmm4);
                    xmm2 += var_60;
                    rsi = 0x0;
                    if (xmm0 > xmm2 && rax) {
                        //loc_10021e000:
                        rsi = 0x1;
                        if (m_isBird) {
                            //loc_10021e00d:
                            rsi = m_yAccel > 0;
                        }
                    }
                }
            } else {
                //loc_10021e01f:
                if (xmm4 <= xmm0) {
                    //loc_10021e024:
                    xmm2 = var_60;
                    xmm2 += xmm4;
                    rsi = 0x0;
                    xmm2 = intrinsic_ucomiss(xmm2, xmm0);
                    if (xmm2 > xmm0 && rax) {
                        //loc_10021e038:
                        rsi = 0x1;
                        if (m_isBird) {
                            //loc_10021e045:
                            rsi = xmm0 > m_yAccel;
                        }
                    }
                }
            }
            //loc_10021e055:
            if ((m_isHolding == 0x0) || (((m_isShip == 0x0) && (m_isBird == 0x0)) && (m_isDart == 0x0))) {
                rdi = 0x0;
            }
            rbx = 0x0;
            rdx = 0x0;
            rax = rdi;
            if (rsi && (r13 || obj->m_unknown_404 || (m_isDart && m_unknown_b24 <= 0))) {
                if (m_inPlayLayer && !PL->m_collisionDisabled) {
                    PL->destroyPlayer(this, nullptr);
                } else {
                    m_unknown_744 = true;
                }
                return;
            }
        } else {
            r10 = !r10;

            //    loc_10021deab
            r11 = rbx;
            xmm2 = 0.0;
            if (!r9) {
                xmm2 = var_60;
                if ((m_isShip || m_isBird || m_isDart) && m_isHolding) {
                    xmm2 = *(int32_t *)(0x100511110 + (m_onSlope2 & 0xff) * 0x4);
                }
            }

            //loc_10021defb:
            if (r13) {
                rax = 0x0;
            } else {
                rax = 0x1;
                if (!m_isShip && !m_isBird) {
                    rax = m_isDart;
                }
                if (r9 && rax) {
                    rax = 0x0;
                } else {
                    rax = *(int8_t *)(this + 0x768) == 0x0 ? 0x1 : 0x0;
                }
            }
            //loc_10021e0e3:
            xmm0 = var_CC;
            if (r10 == 0x0) {
                //loc_10021e106:
                xmm0 = intrinsic_ucomiss(xmm0, xmm4);
                rsi = COND_BYTE_SET(G);
                if (xmm0 <= 0x0) {
                    //loc_10021e10f:
                    rax = rax ^ 0x1;
                    if (rax == 0x0) {
                        //loc_10021e113:
                        xmm3 = intrinsic_movaps(xmm3, xmm4);
                        xmm3 += xmm2;
                        xmm0 = intrinsic_ucomiss(xmm0, xmm3);
                        //loc_10021e11d:
                        rsi = COND_BYTE_SET(G);
                    }
                }
            } else {
                //loc_10021e0f0:
                xmm4 = intrinsic_ucomiss(xmm4, xmm0);
                rsi = COND_BYTE_SET(G);
                if (xmm4 <= 0x0) {
                    //loc_10021e0f9:
                    rax = rax ^ 0x1;
                    if (rax == 0x0) {
                        //loc_10021e0fd:
                        xmm2 += xmm4;
                        xmm2 = intrinsic_ucomiss(xmm2, xmm0);
                        //loc_10021e11d:
                        rsi = COND_BYTE_SET(G);
                    }
                }
            }

            if (m_isHolding != 0x0) {
                rdi = 0x0;
                rdx = 0x0;
            } else {
                rax = m_isShip;

                if ((m_isShip || m_isBird || m_isDart || m_isBall) && r9) {
                    rdi = m_onSlope2;
                } else {
                    rdi = 0;
                }
                if (m_isShip) {
                    rdx = r9;
                } else {
                    rdx = 0;
                }
            }
            rbx = 0x1;
            if (rsi) {
                //loc_10021e192:
                if (m_isShip || m_isBird || m_isDart || m_isBall) {
                    //loc_10021e1be:
                    rax = 0x0;
                    if (rsi && (r13 || objc->m_unknown_404 || m_isDart || m_unknown_b24 <= 0)) {
                        if (m_inPlayLayer && (PL->m_collisionDisabled == 0x0)) {
                            PlayLayer::destroyPlayer(PL, this, 0x0, rcx, r8, r9);
                        } else {
                            m_unknown_744 = 0x1;
                        }
                        return;
                    }
                } else {
                    //loc_10021e93f:
                    xmm1 = *(int32_t *)(this + 0x624);
                    xmm2 = 0x0;
                    if (xmm1 != xmm2) {
                        //loc_10021e952:
                        xmm2 = *(this + 0x7d8);
                        xmm1 = intrinsic_cvtss2sd(xmm1, xmm1);
                        xmm2 += xmm1;
                        xmm1 = *0x100511070;
                        xmm1 = intrinsic_ucomisd(xmm1, xmm2);
                        if (xmm1 > 0x0) {
                            //loc_10021ea10:
                            rax = *this;
                            rbx = *(rax + 0xb8);
                            var_60 = intrinsic_movaps(var_60, xmm4);
                            xmm0 = *(int32_t *)(*(rax + 0xc0))();
                            xmm1 = intrinsic_movaps(xmm1, var_60);
                            cocos2d::CCPoint::CCPoint(var_78, xmm0, xmm1);
                            (rbx)(this, var_78);
                            COND = m_upsideDown == 0x0;
                            xmm0 = m_yAccel;
                            if (!COND) {
                                xmm1 = *0x10050d498;
                                xmm1 = intrinsic_ucomisd(xmm1, xmm0);
                                if (xmm1 <= 0x0) {
                                    xmm1 = intrinsic_movapd(xmm1, xmm0);
                                }
                            } else {
                                xmm1 = *0x100511118;
                                xmm0 = intrinsic_ucomisd(xmm0, xmm1);
                                if (xmm0 <= 0x0) {
                                    xmm1 = intrinsic_movapd(xmm1, xmm0);
                                }
                            }
                            m_yAccel = xmm1;
                            m_onGround = 0x0;
                            m_isSliding = 0x0;
                            return;
                        }
                    }
                    //loc_10021e975:
                    xmm1 = *(this + 0x648);
                    xmm2 = 0x0;
                    xmm1 = intrinsic_ucomisd(xmm1, xmm2);
                    if (xmm1 != xmm2) {
                        //loc_10021e989:
                        xmm2 = *(this + 0x7d8);
                        xmm2 += xmm1;
                        xmm1 = *0x100511070;
                        xmm1 = intrinsic_ucomisd(xmm1, xmm2);
                        rax = COND_BYTE_SET(G);
                    }

                    if (xmm1 > xmm2) {
                    //loc_10021e9a7:
                        rcx = 0x0;
                        if (!rax) {
                            if (m_inPlayLayer && (PL->m_collisionDisabled == 0x0)) {
                                PlayLayer::destroyPlayer(PL, this, 0x0, rcx, r8, r9);
                            } else {
                                m_unknown_744 = 0x1;
                            }
                            return;
                        }
                    } else {
                        //loc_10021e9d9
                        xmm1 = 2.00;
                        xmm1 += xmm0;
                        xmm4 = intrinsic_ucomiss(xmm4, xmm1);
                        rdx = xmm4 > 0x0 ? 0x1 : 0x0;
                        xmm0 += -2.0;
                        xmm0 = intrinsic_ucomiss(xmm0, xmm4);
                        rax = xmm0 > 0x0 ? 0x1 : 0x0;
                        if (r10 != 0x0) {
                            rax = rdx;
                        }
                        rcx = 0x1;
                        if ((rax ^ 0x1) == 0x0) {
                            if (m_inPlayLayer && (PL->m_collisionDisabled == 0x0)) {
                                PlayLayer::destroyPlayer(PL, this, 0x0, rcx, r8, r9);
                            } else {
                                m_unknown_744 = 0x1;
                            }
                            return;
                        }
                    }
                    //loc_10021ea08:
                    if (rcx == 0x0) {
                        rax = *this;
                        rbx = *(rax + 0xb8);
                        var_60 = intrinsic_movaps(var_60, xmm4);
                        xmm0 = *(int32_t *)(*(rax + 0xc0))();
                        xmm1 = intrinsic_movaps(xmm1, var_60);
                        cocos2d::CCPoint::CCPoint(var_78, xmm0, xmm1);
                        (rbx)(this, var_78);
                        COND = m_upsideDown == 0x0;
                        xmm0 = m_yAccel;
                        if (!COND) {
                            xmm1 = *0x10050d498;
                            xmm1 = intrinsic_ucomisd(xmm1, xmm0);
                            if (xmm1 <= 0x0) {
                                xmm1 = intrinsic_movapd(xmm1, xmm0);
                            }
                        } else {
                            xmm1 = *0x100511118;
                            xmm0 = intrinsic_ucomisd(xmm0, xmm1);
                            if (xmm0 <= 0x0) {
                                xmm1 = intrinsic_movapd(xmm1, xmm0);
                            }
                        }
                        m_yAccel = xmm1;
                    }

                    //loc_10021eadd:
                    m_onGround = 0x0;
                    m_isSliding = 0x0;
                    return;
                }
            } else {
                //loc_10021e217:
                rax = 0x0;
                rsi = 0x0;
            }
        }
        //loc_10021e1c5:
        if (m_onSlope2) {
            //loc_10021e225

            xmm0 = *(int32_t *)(this + 0x72c);
            if (xmm0 == xmm4) {
                return;
            }
            //loc_10021e239:
            xmm0 = 0x0;
            xmm2 = var_30;
            if (xmm2 != xmm0) {
                //loc_10021e248:
                if ((var_2C && m_unknown_730) || (r8 && !rsi)) {
                    return;
                }
            }
        }

        if (!rsi) {
            return;
        }
        //loc_10021e26e:
        var_B0 = rbx;
        var_30 = rax;
        var_70 = rdx;
        r12 = rdi;
        var_44 = r11;
        //loc_10021e281:
        CMP(r10, 0x1);
        rax = !(rax - rax + CARRY(RFLAGS(cf))) | 0x1;
        rcx = -rax;
        *(this + 0x578) = gobj;
        m_collidedSlopeObj = gobj;
        *(int32_t *)(this + 0x580) = intrinsic_movss(*(int32_t *)(this + 0x580), intrinsic_subss(xmm5, xmm1));
        m_unknown_733 = slopeTop;
        *(int32_t *)(this + 0x72c) = intrinsic_movss(*(int32_t *)(this + 0x72c), xmm4);
        m_collidedUUID = *(int32_t *)(gobj + 0x36c);
        *(int8_t *)(this + 0x588) = r9;
        xmm0 = m_slopeRotation;
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
        m_slopeRotation = intrinsic_movss(m_slopeRotation, xmm1);
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
                rax = gobj->getLastPosition();
                cocos2d::CCPoint::CCPoint(var_78, rax);
                rax = *gobj;
                var_98 = gobj->getRealPosition();
                xmm0 = var_98;
                xmm2 = intrinsic_movaps(xmm2, var_C0);
                rbx = var_40;
                rax = r12;

                if (xmm0 != var_78 || objRect.y != var_7474) {
                    xmm1 = var_74;
                    xmm0 = objRect.y;
                    if (this->flipMod()*xmm0 > this->flipMod()*xmm1) {
                        xmm0 += xmm1;
                        xmm0 = intrinsic_divss(xmm0, arg0);
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
        m_unknown_728 = intrinsic_movss(m_unknown_728, xmm2);
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
        m_slopeRotation = intrinsic_movss(m_slopeRotation, xmm0);
        if (!m_isShip && !m_isBird && !m_isDart && !m_isBall) {
            xmm0 = arg0;
            PlayerObject::updateSlopeRotation(this);
        } else {
            xmm0 *= *(int32_t *)0x10050c730;
            m_slopeRotation = intrinsic_movss(m_slopeRotation, xmm0);
            if (m_isBall) {
                xmm0 = m_slopeRotation;
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
                xmm0 = arg0;
                PlayerObject::updateSlopeRotation(this);
            }
        }
    }
}