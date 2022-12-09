PlayerObject::checkSnapJumpToObject(GameObject* arg1) {
    if (arg1 != 0x0) {
        rdi = *(this + 0x690);
        if (((rdi != 0x0) && (*(int32_t *)(rdi + 0x36c) != *(int32_t *)(arg1 + 0x36c))) && ((*(*rdi + 0x5e8))() == 0x0)) {
            rdi = *(this + 0x690);
            rax = *rdi;
            rax = (*(rax + 0xc0))(rdi);
            rax = cocos2d::CCPoint::CCPoint(var_38, rax);
            rax = *arg1;
            rax = (*(rax + 0xc0))(arg1);
            rax = cocos2d::CCPoint::CCPoint(var_30, rax);
            xmm1 = intrinsic_movss(xmm1, *(int32_t *)(this + 0x780));
            xmm1 = intrinsic_ucomiss(xmm1, *(int32_t *)value 0.9);
            if ((xmm1 == 0x0) && (!CPU_FLAGS & P)) {
                xmm1 = intrinsic_movss(xmm1, *(int32_t *)(this + 0x77c));
                xmm0 = intrinsic_movsd(xmm0, *value 1.0 v2);
                xmm7 = intrinsic_movss(xmm7, *(int32_t *)value 1.0);
                xmm2 = intrinsic_movss(xmm2, *(int32_t *)value 150.0);
                xmm1 = intrinsic_ucomiss(xmm1, xmm7);
                if (xmm1 == 0x0) {
                    if (!CPU_FLAGS & NP) {
                        xmm3 = intrinsic_movaps(xmm3, xmm1);
                    }
                    else {
                        xmm3 = intrinsic_movss(xmm3, *(int32_t *)value 120.0);
                    }
                } else {
                    xmm3 = intrinsic_movaps(xmm3, xmm1);
                }

                xmm1 = intrinsic_movss(xmm1, *(int32_t *)value 90.00);
            }
            else {
                xmm3 = intrinsic_movss(xmm3, *(int32_t *)value 90.00);
                xmm0 = intrinsic_movsd(xmm0, *value 1.0 v2);
                xmm7 = intrinsic_movss(xmm7, *(int32_t *)value 1.0);
                xmm1 = intrinsic_ucomiss(xmm1, *(int32_t *)value 0.70);
                if ((xmm1 == 0x0) && (!CPU_FLAGS & P)) {
                    xmm1 = intrinsic_movss(xmm1, *(int32_t *)value 60.0);
                    xmm2 = intrinsic_movss(xmm2, *(int32_t *)value 120.0);
                }
                else {
                    xmm1 = intrinsic_ucomiss(xmm1, *(int32_t *)value 1.10);
                    if ((xmm1 == 0x0) && (!CPU_FLAGS & P)) {
                        xmm4 = intrinsic_movss(xmm4, *(int32_t *)(this + 0x77c));
                        xmm0 = intrinsic_movsd(xmm0, *value 0.000);
                        xmm7 = intrinsic_movss(xmm7, *(int32_t *)value 2.00);
                        xmm1 = intrinsic_movss(xmm1, *(int32_t *)value 120.0);
                        xmm2 = intrinsic_movss(xmm2, *(int32_t *)value 195.0);
                        xmm4 = intrinsic_ucomiss(xmm4, *(int32_t *)value 1.0);
                        if ((xmm4 == 0x0) && (!CPU_FLAGS & P)) {
                            xmm3 = intrinsic_movss(xmm3, *(int32_t *)value 150.0);
                        }
                    }
                    else {
                        xmm1 = intrinsic_ucomiss(xmm1, *(int32_t *)value 1.30);
                        if ((xmm1 == 0x0) && (!CPU_FLAGS & P)) {
                            xmm3 = intrinsic_movss(xmm3, *(int32_t *)(this + 0x77c));
                            xmm0 = intrinsic_movsd(xmm0, *value 0.000);
                            xmm7 = intrinsic_movss(xmm7, *(int32_t *)value 2.00);
                            xmm1 = intrinsic_movss(xmm1, *(int32_t *)value 135.0);
                            xmm2 = intrinsic_movss(xmm2, *(int32_t *)value 225.0);
                            xmm3 = intrinsic_ucomiss(xmm3, *(int32_t *)value 1.0);
                            if ((xmm3 == 0x0) && (CPU_FLAGS & NP)) {
                                xmm3 = intrinsic_movss(xmm3, *(int32_t *)value 180.0);
                            }
                            else {
                                xmm3 = intrinsic_movss(xmm3, *(int32_t *)value 90.00);
                            }
                        }
                        else {
                            xmm3 = intrinsic_movss(xmm3, *(int32_t *)value 120.0);
                            xmm1 = intrinsic_movss(xmm1, *(int32_t *)value 90.00);
                            xmm2 = intrinsic_movss(xmm2, *(int32_t *)value 150.0);
                        }
                    }
                }
            }
            xmm4 = intrinsic_movss(xmm4, var_30);
            xmm5 = intrinsic_movss(xmm5, var_38);
            xmm3 = intrinsic_addss(xmm3, xmm5);
            xmm6 = intrinsic_movaps(xmm6, xmm4);
            xmm6 = intrinsic_subss(xmm6, xmm3);
            xmm6 = intrinsic_andps(xmm6, *(int128_t *)abs float mask);
            xmm3 = intrinsic_cvtss2sd(0x0, xmm6);
            xmm0 = intrinsic_ucomisd(xmm0, xmm3);
            if (xmm0 >= 0x0) {
                xmm3 = intrinsic_movss(xmm3, var_2C);
                rax = 0x0;
                xmm3 = intrinsic_subss(xmm3, intrinsic_addss(intrinsic_movss(xmm6, var_34), *(int32_t *)(-30.0 or 30.0 + (*(int8_t *)(this + 0x776) == 0x0 ? 0x1 : 0x0) * 0x4)));
                xmm3 = intrinsic_andps(xmm3, *(int128_t *)abs float mask);
                xmm3 = intrinsic_cvtss2sd(xmm3, xmm3);
                xmm0 = intrinsic_ucomisd(xmm0, xmm3);
                if (xmm0 < 0x0) {
                    xmm2 = intrinsic_addss(xmm2, xmm5);
                    xmm3 = intrinsic_movaps(xmm3, xmm4);
                    xmm3 = intrinsic_subss(xmm3, xmm2);
                    xmm3 = intrinsic_andps(xmm3, *(int128_t *)abs float mask);
                    xmm2 = intrinsic_cvtss2sd(0x0, xmm3);
                    xmm0 = intrinsic_ucomisd(xmm0, xmm2);
                    if (xmm0 >= 0x0) {
                        xmm2 = intrinsic_movss(xmm2, var_2C);
                        rax = 0x0;
                        COND = *(int8_t *)(this + 0x776) == 0x0;
                        xmm3 = intrinsic_movss(xmm3, var_34);
                        xmm3 = intrinsic_addss(xmm3, *(int32_t *)(30.0 or -30.0 + (COND ? 0x1 : 0x0) * 0x4));
                        xmm2 = intrinsic_subss(xmm2, xmm3);
                        xmm2 = intrinsic_andps(xmm2, *(int128_t *)abs float mask);
                        xmm2 = intrinsic_cvtss2sd(xmm2, xmm2);
                        xmm0 = intrinsic_ucomisd(xmm0, xmm2);
                        if (xmm0 < 0x0) {
                            xmm1 = intrinsic_cvtss2sd(0x0, intrinsic_andps(intrinsic_subss(xmm4, intrinsic_addss(xmm1, xmm5)), *(int128_t *)abs float mask));
                            xmm0 = intrinsic_ucomisd(xmm0, xmm1);
                            if (xmm0 >= 0x0) {
                                xmm1 = intrinsic_movss(xmm1, var_2C);
                                rax = 0x0;
                                COND = *(int8_t *)(this + 0x776) == 0x0;
                                xmm2 = intrinsic_movss(xmm2, var_34);
                                xmm2 = intrinsic_addss(xmm2, *(int32_t *)(-60.0 or 60.0 + (COND ? 0x1 : 0x0) * 0x4));
                                xmm1 = intrinsic_subss(xmm1, xmm2);
                                xmm1 = intrinsic_andps(xmm1, *(int128_t *)abs float mask);
                                xmm1 = intrinsic_cvtss2sd(xmm1, xmm1);
                                xmm0 = intrinsic_ucomisd(xmm0, xmm1);
                                if (xmm0 >= 0x0) {
                                    rax = *arg1;
                                    rdi = arg1;
                                    var_3C = intrinsic_movss(var_3C, xmm7);
                                    xmm0 = intrinsic_movss(xmm0, *(int32_t *)(*(rax + 0xc0))());
                                    xmm0 = intrinsic_cvtss2sd(xmm0, xmm0);
                                    xmm0 = intrinsic_addsd(xmm0, *(this + 0x680));
                                    xmm0 = intrinsic_cvtsd2ss(xmm0, xmm0);
                                    var_24 = intrinsic_movss(var_24, xmm0);
                                    rax = *this;
                                    rax = (*(rax + 0xc0))(this);
                                    xmm3 = intrinsic_movss(xmm3, var_24);
                                    xmm2 = intrinsic_movss(xmm2, var_3C);
                                    xmm0 = intrinsic_movss(xmm0, *(int32_t *)rax);
                                    xmm1 = intrinsic_movaps(xmm1, xmm3);
                                    xmm1 = intrinsic_subss(xmm1, xmm0);
                                    xmm1 = intrinsic_andps(xmm1, *(int128_t *)abs float mask);
                                    xmm2 = intrinsic_ucomiss(xmm2, xmm1);
                                    if (xmm2 < 0x0) {
                                        xmm3 = intrinsic_ucomiss(xmm3, xmm0);
                                        if (xmm3 > 0x0) {
                                            var_24 = intrinsic_movss(var_24, intrinsic_addss(xmm2, xmm0));
                                        }
                                        else {
                                            xmm0 = intrinsic_subss(xmm0, xmm2);
                                            var_24 = intrinsic_movss(var_24, xmm0);
                                        }
                                    }
                                    rax = *this;
                                    r12 = *(rax + 0xb8);
                                    xmm1 = intrinsic_movss(xmm1, *(int32_t *)((*(rax + 0xc0))(this) + 0x4));
                                    xmm0 = intrinsic_movss(xmm0, var_24);
                                    rax = cocos2d::CCPoint::CCPoint(var_48, xmm0, xmm1);
                                    rax = (r12)(this, var_48);
                                }
                            }
                        }
                        else {
                            rax = *arg1;
                            rdi = arg1;
                            var_3C = intrinsic_movss(var_3C, xmm7);
                            xmm0 = intrinsic_movss(xmm0, *(int32_t *)(*(rax + 0xc0))());
                            xmm0 = intrinsic_cvtss2sd(xmm0, xmm0);
                            xmm0 = intrinsic_addsd(xmm0, *(this + 0x680));
                            xmm0 = intrinsic_cvtsd2ss(xmm0, xmm0);
                            var_24 = intrinsic_movss(var_24, xmm0);
                            rax = *this;
                            rax = (*(rax + 0xc0))(this);
                            xmm3 = intrinsic_movss(xmm3, var_24);
                            xmm2 = intrinsic_movss(xmm2, var_3C);
                            xmm0 = intrinsic_movss(xmm0, *(int32_t *)rax);
                            xmm1 = intrinsic_movaps(xmm1, xmm3);
                            xmm1 = intrinsic_subss(xmm1, xmm0);
                            xmm1 = intrinsic_andps(xmm1, *(int128_t *)abs float mask);
                            xmm2 = intrinsic_ucomiss(xmm2, xmm1);
                            if (xmm2 < 0x0) {
                                xmm3 = intrinsic_ucomiss(xmm3, xmm0);
                                if (xmm3 > 0x0) {
                                    var_24 = intrinsic_movss(var_24, intrinsic_addss(xmm2, xmm0));
                                }
                                else {
                                    xmm0 = intrinsic_subss(xmm0, xmm2);
                                    var_24 = intrinsic_movss(var_24, xmm0);
                                }
                            }
                            rax = *this;
                            r12 = *(rax + 0xb8);
                            xmm1 = intrinsic_movss(xmm1, *(int32_t *)((*(rax + 0xc0))(this) + 0x4));
                            xmm0 = intrinsic_movss(xmm0, var_24);
                            rax = cocos2d::CCPoint::CCPoint(var_48, xmm0, xmm1);
                            rax = (r12)(this, var_48);
                        }
                    }
                    else {
                        xmm1 = intrinsic_cvtss2sd(0x0, intrinsic_andps(intrinsic_subss(xmm4, intrinsic_addss(xmm1, xmm5)), *(int128_t *)abs float mask));
                        xmm0 = intrinsic_ucomisd(xmm0, xmm1);
                        if (xmm0 >= 0x0) {
                            xmm1 = intrinsic_movss(xmm1, var_2C);
                            rax = 0x0;
                            COND = *(int8_t *)(this + 0x776) == 0x0;
                            xmm2 = intrinsic_movss(xmm2, var_34);
                            xmm2 = intrinsic_addss(xmm2, *(int32_t *)(-60.0 or 60.0 + (COND ? 0x1 : 0x0) * 0x4));
                            xmm1 = intrinsic_subss(xmm1, xmm2);
                            xmm1 = intrinsic_andps(xmm1, *(int128_t *)abs float mask);
                            xmm1 = intrinsic_cvtss2sd(xmm1, xmm1);
                            xmm0 = intrinsic_ucomisd(xmm0, xmm1);
                            if (xmm0 >= 0x0) {
                                rax = *arg1;
                                rdi = arg1;
                                var_3C = intrinsic_movss(var_3C, xmm7);
                                xmm0 = intrinsic_movss(xmm0, *(int32_t *)(*(rax + 0xc0))());
                                xmm0 = intrinsic_cvtss2sd(xmm0, xmm0);
                                xmm0 = intrinsic_addsd(xmm0, *(this + 0x680));
                                xmm0 = intrinsic_cvtsd2ss(xmm0, xmm0);
                                var_24 = intrinsic_movss(var_24, xmm0);
                                rax = *this;
                                rax = (*(rax + 0xc0))(this);
                                xmm3 = intrinsic_movss(xmm3, var_24);
                                xmm2 = intrinsic_movss(xmm2, var_3C);
                                xmm0 = intrinsic_movss(xmm0, *(int32_t *)rax);
                                xmm1 = intrinsic_movaps(xmm1, xmm3);
                                xmm1 = intrinsic_subss(xmm1, xmm0);
                                xmm1 = intrinsic_andps(xmm1, *(int128_t *)abs float mask);
                                xmm2 = intrinsic_ucomiss(xmm2, xmm1);
                                if (xmm2 < 0x0) {
                                    xmm3 = intrinsic_ucomiss(xmm3, xmm0);
                                    if (xmm3 > 0x0) {
                                        var_24 = intrinsic_movss(var_24, intrinsic_addss(xmm2, xmm0));
                                    }
                                    else {
                                        xmm0 = intrinsic_subss(xmm0, xmm2);
                                        var_24 = intrinsic_movss(var_24, xmm0);
                                    }
                                }
                                rax = *this;
                                r12 = *(rax + 0xb8);
                                xmm1 = intrinsic_movss(xmm1, *(int32_t *)((*(rax + 0xc0))(this) + 0x4));
                                xmm0 = intrinsic_movss(xmm0, var_24);
                                rax = cocos2d::CCPoint::CCPoint(var_48, xmm0, xmm1);
                                rax = (r12)(this, var_48);
                            }
                        }
                    }
                }
                else {
                    rax = *arg1;
                    rdi = arg1;
                    var_3C = intrinsic_movss(var_3C, xmm7);
                    xmm0 = intrinsic_movss(xmm0, *(int32_t *)(*(rax + 0xc0))());
                    xmm0 = intrinsic_cvtss2sd(xmm0, xmm0);
                    xmm0 = intrinsic_addsd(xmm0, *(this + 0x680));
                    xmm0 = intrinsic_cvtsd2ss(xmm0, xmm0);
                    var_24 = intrinsic_movss(var_24, xmm0);
                    rax = *this;
                    rax = (*(rax + 0xc0))(this);
                    xmm3 = intrinsic_movss(xmm3, var_24);
                    xmm2 = intrinsic_movss(xmm2, var_3C);
                    xmm0 = intrinsic_movss(xmm0, *(int32_t *)rax);
                    xmm1 = intrinsic_movaps(xmm1, xmm3);
                    xmm1 = intrinsic_subss(xmm1, xmm0);
                    xmm1 = intrinsic_andps(xmm1, *(int128_t *)abs float mask);
                    xmm2 = intrinsic_ucomiss(xmm2, xmm1);
                    if (xmm2 < 0x0) {
                        xmm3 = intrinsic_ucomiss(xmm3, xmm0);
                        if (xmm3 > 0x0) {
                            var_24 = intrinsic_movss(var_24, intrinsic_addss(xmm2, xmm0));
                        }
                        else {
                            xmm0 = intrinsic_subss(xmm0, xmm2);
                            var_24 = intrinsic_movss(var_24, xmm0);
                        }
                    }
                    rax = *this;
                    r12 = *(rax + 0xb8);
                    xmm1 = intrinsic_movss(xmm1, *(int32_t *)((*(rax + 0xc0))(this) + 0x4));
                    xmm0 = intrinsic_movss(xmm0, var_24);
                    rax = cocos2d::CCPoint::CCPoint(var_48, xmm0, xmm1);
                    rax = (r12)(this, var_48);
                }
            }
            else {
                xmm2 = intrinsic_addss(xmm2, xmm5);
                xmm3 = intrinsic_movaps(xmm3, xmm4);
                xmm3 = intrinsic_subss(xmm3, xmm2);
                xmm3 = intrinsic_andps(xmm3, *(int128_t *)abs float mask);
                xmm2 = intrinsic_cvtss2sd(0x0, xmm3);
                xmm0 = intrinsic_ucomisd(xmm0, xmm2);
                if (xmm0 >= 0x0) {
                    xmm2 = intrinsic_movss(xmm2, var_2C);
                    rax = 0x0;
                    COND = *(int8_t *)(this + 0x776) == 0x0;
                    xmm3 = intrinsic_movss(xmm3, var_34);
                    xmm3 = intrinsic_addss(xmm3, *(int32_t *)(30.0 or -30.0 + (COND ? 0x1 : 0x0) * 0x4));
                    xmm2 = intrinsic_subss(xmm2, xmm3);
                    xmm2 = intrinsic_andps(xmm2, *(int128_t *)abs float mask);
                    xmm2 = intrinsic_cvtss2sd(xmm2, xmm2);
                    xmm0 = intrinsic_ucomisd(xmm0, xmm2);
                    if (xmm0 < 0x0) {
                        xmm1 = intrinsic_cvtss2sd(0x0, intrinsic_andps(intrinsic_subss(xmm4, intrinsic_addss(xmm1, xmm5)), *(int128_t *)abs float mask));
                        xmm0 = intrinsic_ucomisd(xmm0, xmm1);
                        if (xmm0 >= 0x0) {
                            xmm1 = intrinsic_movss(xmm1, var_2C);
                            rax = 0x0;
                            COND = *(int8_t *)(this + 0x776) == 0x0;
                            xmm2 = intrinsic_movss(xmm2, var_34);
                            xmm2 = intrinsic_addss(xmm2, *(int32_t *)(-60.0 or 60.0 + (COND ? 0x1 : 0x0) * 0x4));
                            xmm1 = intrinsic_subss(xmm1, xmm2);
                            xmm1 = intrinsic_andps(xmm1, *(int128_t *)abs float mask);
                            xmm1 = intrinsic_cvtss2sd(xmm1, xmm1);
                            xmm0 = intrinsic_ucomisd(xmm0, xmm1);
                            if (xmm0 >= 0x0) {
                                rax = *arg1;
                                rdi = arg1;
                                var_3C = intrinsic_movss(var_3C, xmm7);
                                xmm0 = intrinsic_movss(xmm0, *(int32_t *)(*(rax + 0xc0))());
                                xmm0 = intrinsic_cvtss2sd(xmm0, xmm0);
                                xmm0 = intrinsic_addsd(xmm0, *(this + 0x680));
                                xmm0 = intrinsic_cvtsd2ss(xmm0, xmm0);
                                var_24 = intrinsic_movss(var_24, xmm0);
                                rax = *this;
                                rax = (*(rax + 0xc0))(this);
                                xmm3 = intrinsic_movss(xmm3, var_24);
                                xmm2 = intrinsic_movss(xmm2, var_3C);
                                xmm0 = intrinsic_movss(xmm0, *(int32_t *)rax);
                                xmm1 = intrinsic_movaps(xmm1, xmm3);
                                xmm1 = intrinsic_subss(xmm1, xmm0);
                                xmm1 = intrinsic_andps(xmm1, *(int128_t *)abs float mask);
                                xmm2 = intrinsic_ucomiss(xmm2, xmm1);
                                if (xmm2 < 0x0) {
                                    xmm3 = intrinsic_ucomiss(xmm3, xmm0);
                                    if (xmm3 > 0x0) {
                                        var_24 = intrinsic_movss(var_24, intrinsic_addss(xmm2, xmm0));
                                    }
                                    else {
                                        xmm0 = intrinsic_subss(xmm0, xmm2);
                                        var_24 = intrinsic_movss(var_24, xmm0);
                                    }
                                }
                                rax = *this;
                                r12 = *(rax + 0xb8);
                                xmm1 = intrinsic_movss(xmm1, *(int32_t *)((*(rax + 0xc0))(this) + 0x4));
                                xmm0 = intrinsic_movss(xmm0, var_24);
                                rax = cocos2d::CCPoint::CCPoint(var_48, xmm0, xmm1);
                                rax = (r12)(this, var_48);
                            }
                        }
                    }
                    else {
                        rax = *arg1;
                        rdi = arg1;
                        var_3C = intrinsic_movss(var_3C, xmm7);
                        xmm0 = intrinsic_movss(xmm0, *(int32_t *)(*(rax + 0xc0))());
                        xmm0 = intrinsic_cvtss2sd(xmm0, xmm0);
                        xmm0 = intrinsic_addsd(xmm0, *(this + 0x680));
                        xmm0 = intrinsic_cvtsd2ss(xmm0, xmm0);
                        var_24 = intrinsic_movss(var_24, xmm0);
                        rax = *this;
                        rax = (*(rax + 0xc0))(this);
                        xmm3 = intrinsic_movss(xmm3, var_24);
                        xmm2 = intrinsic_movss(xmm2, var_3C);
                        xmm0 = intrinsic_movss(xmm0, *(int32_t *)rax);
                        xmm1 = intrinsic_movaps(xmm1, xmm3);
                        xmm1 = intrinsic_subss(xmm1, xmm0);
                        xmm1 = intrinsic_andps(xmm1, *(int128_t *)abs float mask);
                        xmm2 = intrinsic_ucomiss(xmm2, xmm1);
                        if (xmm2 < 0x0) {
                            xmm3 = intrinsic_ucomiss(xmm3, xmm0);
                            if (xmm3 > 0x0) {
                                var_24 = intrinsic_movss(var_24, intrinsic_addss(xmm2, xmm0));
                            }
                            else {
                                xmm0 = intrinsic_subss(xmm0, xmm2);
                                var_24 = intrinsic_movss(var_24, xmm0);
                            }
                        }
                        rax = *this;
                        r12 = *(rax + 0xb8);
                        xmm1 = intrinsic_movss(xmm1, *(int32_t *)((*(rax + 0xc0))(this) + 0x4));
                        xmm0 = intrinsic_movss(xmm0, var_24);
                        rax = cocos2d::CCPoint::CCPoint(var_48, xmm0, xmm1);
                        rax = (r12)(this, var_48);
                    }
                }
                else {
                    xmm1 = intrinsic_cvtss2sd(0x0, intrinsic_andps(intrinsic_subss(xmm4, intrinsic_addss(xmm1, xmm5)), *(int128_t *)abs float mask));
                    xmm0 = intrinsic_ucomisd(xmm0, xmm1);
                    if (xmm0 >= 0x0) {
                        xmm1 = intrinsic_movss(xmm1, var_2C);
                        rax = 0x0;
                        COND = *(int8_t *)(this + 0x776) == 0x0;
                        xmm2 = intrinsic_movss(xmm2, var_34);
                        xmm2 = intrinsic_addss(xmm2, *(int32_t *)(-60.0 or 60.0 + (COND ? 0x1 : 0x0) * 0x4));
                        xmm1 = intrinsic_subss(xmm1, xmm2);
                        xmm1 = intrinsic_andps(xmm1, *(int128_t *)abs float mask);
                        xmm1 = intrinsic_cvtss2sd(xmm1, xmm1);
                        xmm0 = intrinsic_ucomisd(xmm0, xmm1);
                        if (xmm0 >= 0x0) {
                            rax = *arg1;
                            rdi = arg1;
                            var_3C = intrinsic_movss(var_3C, xmm7);
                            xmm0 = intrinsic_movss(xmm0, *(int32_t *)(*(rax + 0xc0))());
                            xmm0 = intrinsic_cvtss2sd(xmm0, xmm0);
                            xmm0 = intrinsic_addsd(xmm0, *(this + 0x680));
                            xmm0 = intrinsic_cvtsd2ss(xmm0, xmm0);
                            var_24 = intrinsic_movss(var_24, xmm0);
                            rax = *this;
                            rax = (*(rax + 0xc0))(this);
                            xmm3 = intrinsic_movss(xmm3, var_24);
                            xmm2 = intrinsic_movss(xmm2, var_3C);
                            xmm0 = intrinsic_movss(xmm0, *(int32_t *)rax);
                            xmm1 = intrinsic_movaps(xmm1, xmm3);
                            xmm1 = intrinsic_subss(xmm1, xmm0);
                            xmm1 = intrinsic_andps(xmm1, *(int128_t *)abs float mask);
                            xmm2 = intrinsic_ucomiss(xmm2, xmm1);
                            if (xmm2 < 0x0) {
                                xmm3 = intrinsic_ucomiss(xmm3, xmm0);
                                if (xmm3 > 0x0) {
                                    var_24 = intrinsic_movss(var_24, intrinsic_addss(xmm2, xmm0));
                                }
                                else {
                                    xmm0 = intrinsic_subss(xmm0, xmm2);
                                    var_24 = intrinsic_movss(var_24, xmm0);
                                }
                            }
                            rax = *this;
                            r12 = *(rax + 0xb8);
                            xmm1 = intrinsic_movss(xmm1, *(int32_t *)((*(rax + 0xc0))(this) + 0x4));
                            xmm0 = intrinsic_movss(xmm0, var_24);
                            rax = cocos2d::CCPoint::CCPoint(var_48, xmm0, xmm1);
                            rax = (r12)(this, var_48);
                        }
                    }
                }
            }
        }
        *(this + 0x690) = arg1;
        xmm0 = intrinsic_movss(xmm0, *(int32_t *)(*(*this + 0xc0))(this));
        var_24 = intrinsic_movss(var_24, xmm0);
        rax = *arg1;
        rax = (*(rax + 0xc0))(arg1);
        xmm0 = intrinsic_movss(xmm0, var_24);
        xmm0 = intrinsic_subss(xmm0, *(int32_t *)rax);
        *(this + 0x680) = intrinsic_movsd(*(this + 0x680), intrinsic_cvtss2sd(xmm0, xmm0));
    }

    return;
}