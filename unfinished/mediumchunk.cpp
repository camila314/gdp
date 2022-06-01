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