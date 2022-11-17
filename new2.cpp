HardStreak::updateStroke(float dt) {
    static CCPoint var_38;

    this->clear();
    if (m_pointsArr->count() > 0 && this->getOpacity() > 0) {
        var_A4 = (m_isSolid ? 1 : 2);
        int i = 0; // r13
        while (true) {
            if (m_pointsArr->count() > 0) {
                // this function will never append to m_pointsArr
                r12 = 0x0;
                var_A8 = r13;
            } else {
                r13 = r13 + 0x1;
                if (r13 < var_A4) {
                    r12 = 0x0;
                    var_A8 = r13;
                }
            }

            do {
                var_98 = r12;
                rax = cocos2d::CCArray::objectAtIndex(m_pointsArr, var_98);
                var_60 = cocos2d::CCPoint::CCPoint(rax + 0x24);
                rcx = var_98;
                if (rcx < m_pointsArr->count() - 0x1) {
                        rsi = cocos2d::CCArray::objectAtIndex(m_pointsArr, rcx + 0x1) + 0x24;
                        rdi = var_58;
                } else {
                        rdi = var_58;
                        rsi = m_currentPoint;
                }
                rdi = cocos2d::CCPoint::CCPoint(rsi);
                rax = cocos2d::CCPoint::CCPoint(var_50);
                rax = cocos2d::CCPoint::CCPoint(var_48);
                rax = cocos2d::CCPoint::CCPoint(var_40);
                rax = cocos2d::CCPoint::CCPoint(var_38);
                xmm0 = m_waveSize;
                if (r13 != 0x0) {
                        xmm0 += xmm0;
                } else {
                        xmm0 *= *(int32_t *)0x10050ca58;
                }
                xmm0 *= m_pulseSize;
                var_90 = xmm0;
                r15 = var_60;
                var_C8 = cocos2d::CCPoint::CCPoint(r15);
                var_C0 = cocos2d::CCPoint::CCPoint(var_58);
                xmm0 = 1.0;
                xmm1 = var_90;
                xmm0 = intrinsic_ucomiss(xmm0, xmm1);
                xmm2 = intrinsic_movaps(xmm2, xmm1);
                if (xmm0 > 0x0) {
                        var_78 = cocos2d::CCPoint::CCPoint(0x10069c540);
                        xmm1 = var_90;
                        xmm1 *= 0.5;
                } else {
                        xmm1 = var_C0;
                        xmm0 = var_BC;
                        xmm1 -= var_C8;
                        xmm0 -= var_C4;
                        xmm2 *= 0.5;
                        var_90 = xmm2;
                        xmm0 = intrinsic_cvtss2sd(xmm0, xmm0);
                        xmm1 = intrinsic_cvtss2sd(xmm1, xmm1);
                        rax = atan2(xmm0, xmm1);
                        xmm1 = intrinsic_movapd(xmm1, xmm0);
                        xmm1 *= *0x10050d2f8;
                        xmm1 = intrinsic_divsd(xmm1, *0x10050d300);
                        xmm1 += *0x10050d308;
                        xmm1 = intrinsic_ucomisd(xmm1, *0x10050d310);
                        if (xmm1 > 0x0) {
                                xmm1 += *0x10050d318;
                        } else {
                                xmm0 = intrinsic_xorpd(xmm0, xmm0);
                                xmm0 = intrinsic_ucomisd(xmm0, xmm1);
                                if (xmm0 > 0x0) {
                                        xmm1 += *0x10050d310;
                                }
                        }
                        xmm1 *= *0x10050d300;
                        xmm1 = intrinsic_divsd(xmm1, *0x10050d2f8);
                        var_F0 = xmm1;
                        xmm0 = intrinsic_movapd(xmm0, xmm1);
                        rax = sin(xmm0);
                        xmm1 = intrinsic_movapd(xmm1, xmm0);
                        xmm0 = var_90;
                        xmm0 = intrinsic_cvtss2sd(xmm0, xmm0);
                        var_E0 = xmm0;
                        xmm1 *= xmm0;
                        var_A0 = xmm1;
                        xmm0 = var_F0;
                        rax = cos(xmm0);
                        xmm0 *= var_E0;
                        xmm0 = intrinsic_cvtsd2ss(xmm0, xmm0);
                        xmm1 = var_A0;
                        xmm1 = intrinsic_cvtsd2ss(xmm1, xmm1);
                        var_78 = cocos2d::CCPoint::CCPoint(xmm0, xmm1);
                        xmm1 = var_90;
                }
                xmm2 = var_78;
                var_90 = intrinsic_movaps(var_90, xmm2);
                xmm0 = intrinsic_movaps(xmm0, *(int128_t *)0x10050cb40);
                xmm2 = intrinsic_andps(xmm2, xmm0);
                var_F0 = intrinsic_movaps(var_F0, xmm2);
                xmm0 = intrinsic_movaps(xmm0, xmm2);
                xmm0 = intrinsic_divss(xmm0, xmm1);
                rax = asinf(xmm0);
                rax = tanf(xmm0);
                var_E0 = intrinsic_movaps(var_E0, xmm0);
                xmm1 = intrinsic_movaps(xmm1, var_90);
                xmm1 *= xmm0;
                xmm1 = intrinsic_andps(xmm1, *(int128_t *)0x10050cb40);
                var_90 = intrinsic_movaps(var_90, xmm1);
                rbx = (var_98 >= m_pointsArr->count() - 0x1 ? 0x1 : 0x0) & (!r13);
                if (rbx == 0x1) {
                        rax = cocos2d::ccpDistance(r15, var_58);
                        xmm0 = intrinsic_andps(xmm0, *(int128_t *)0x10050cb40);
                        xmm0 = intrinsic_ucomiss(xmm0, 10.0);
                        if (xmm0 > 0x0) {
                                xmm3 = intrinsic_movaps(xmm3, var_E0);
                                xmm3 *= 4.0;
                                xmm0 = intrinsic_movaps(xmm0, xmm3);
                                xmm0 = intrinsic_andps(xmm0, *(int128_t *)0x10050cb40);
                                xmm1 = var_58;
                                xmm1 += -4.0;
                                var_58 = xmm1;
                                xmm1 = var_5C;
                                xmm2 = var_54;
                                xmm3 = intrinsic_orps(xmm3, *(int128_t *)value -0.00);
                                asm{ cmpltss    xmm1, xmm2 };
                                xmm3 = intrinsic_andps(xmm3, xmm1);
                                xmm1 = intrinsic_andnps(xmm1, xmm0);
                                xmm1 = intrinsic_orps(xmm1, xmm3);
                                xmm1 += xmm2;
                                var_54 = xmm1;
                        }
                }
                r14 = var_70;
                r14 = cocos2d::CCPoint::CCPoint(r15);
                var_68 = cocos2d::CCPoint::CCPoint(var_58);
                xmm0 = var_70;
                xmm1 = intrinsic_movaps(xmm1, var_F0);
                xmm0 -= xmm1;
                var_70 = xmm0;
                xmm0 = var_68;
                xmm0 += xmm1;
                var_68 = xmm0;
                if (r13 != 0x0) {
                        xmm0 = var_60;
                        xmm0 += xmm1;
                        var_60 = xmm0;
                        xmm0 = var_58;
                        xmm0 -= xmm1;
                        var_58 = xmm0;
                }
                xmm0 = var_6C;
                xmm1 = var_64;
                xmm1 = intrinsic_ucomiss(xmm1, xmm0);
                xmm3 = intrinsic_movaps(xmm3, var_90);
                var_A0 = rbx;
                if (xmm1 <= 0x0) {
                    xmm2 = intrinsic_movaps(xmm2, xmm3);
                    xmm2 += xmm0;
                    var_6C = xmm2;
                    xmm2 = intrinsic_movaps(xmm2, xmm1);
                    xmm2 -= xmm3;
                    var_64 = xmm2;

                    if (r13 != 0x0) {
                        xmm2 = var_5C;
                        xmm2 -= xmm3;
                        var_5C = xmm2;
                        xmm2 = var_54;
                        xmm2 += xmm3;
                        var_54 = xmm2;
                    }
                } else {
                    xmm2 = intrinsic_movaps(xmm2, xmm0);
                    xmm2 -= xmm3;
                    var_6C = xmm2;
                    xmm2 = intrinsic_movaps(xmm2, xmm3);
                    xmm2 += xmm1;
                    var_64 = xmm2;

                    if (r13 != 0x0) {
                        xmm2 = var_5C;
                        xmm2 += xmm3;
                        var_5C = xmm2;
                        xmm2 = var_54;
                        xmm2 -= xmm3;
                    }
                }

                var_54 = xmm2;

                xmm1 = intrinsic_ucomiss(xmm1, xmm0);
                rsi = r15;
                asm{ cmova      rsi, r14 };
                asm{ cmova      r14, r15 };
                rbx = var_58;
                r15 = rbx;
                r13 = var_68;
                asm{ cmova      r15, r13 };
                asm{ cmova      r13, rbx };
                rax = cocos2d::CCPoint::operator-(var_B8, rsi, var_78);
                r12 = var_B8;
                rax = cocos2d::CCPoint::operator=(var_50, r12);
                rax = cocos2d::CCPoint::operator+(r12, r14, var_78);
                rax = cocos2d::CCPoint::operator=(var_48, r12);
                if (var_A0 != 0x0) {
                        r15 = rbx;
                }
                if (CPU_FLAGS & NE) {
                        r13 = rbx;
                }
                rax = cocos2d::CCPoint::operator+(r12, r15, var_78);
                rax = cocos2d::CCPoint::operator=(var_40, r12);
                rax = cocos2d::CCPoint::operator-(r12, r13, var_78);
                rax = cocos2d::CCPoint::operator=(var_48, r12);
                r13 = var_A8;
                rax = 0x10050d340;
                if (r13 == 0x0) {
                        rax = this->getColor();
                }
                rcx = *(int16_t *)rax & 0xffff;
                rax = *(int8_t *)(rax + 0x2) & 0xff;
                xmm0 = intrinsic_cvtsi2ss(xmm0, (rax << 0x10 | rcx) & 0xff);
                xmm2 = intrinsic_movaps(xmm2, 255.00);
                xmm0 = intrinsic_divss(xmm0, xmm2);
                xmm0 = intrinsic_unpcklps(xmm0, intrinsic_divss(intrinsic_cvtsi2ss(0x0, (rax << 0x10 | rcx) & 0xff), xmm2));
                xmm1 = intrinsic_cvtsi2ss(0x0, (rax << 0x10 | rcx) >> 0x10);
                xmm1 = intrinsic_divss(xmm1, xmm2);
                xmm2 = 1.0;
                xmm1 = intrinsic_unpcklps(xmm1, xmm2);
                var_B8 = intrinsic_movlps(var_B8, xmm0);
                var_B0 = intrinsic_movlps(var_B0, xmm1);
                xmm0 = intrinsic_cvtsi2ss(0x0, this->getOpacity() & 0xff);
                xmm0 = intrinsic_divss(xmm0, 255.00);
                if (r13 != 0x0) {
                        xmm0 *= *(int32_t *)0x10050ce14;
                }
                var_AC = 0x0;
                var_110 = intrinsic_movaps(var_110, 0x0);
                xmm0 = 0x0;
                rax = cocos2d::CCDrawNode::drawPolygon(this, var_50, 0x4, var_B8, var_110);
                r12 = var_98 + 0x1;
        } while (r12 < m_pointsArr->count());
    }
}
