float _ZN9PlayLayer15checkCollisionsEPvP12PlayerObjectf(int arg0, int arg1, int arg2) {
    rdx = arg2;
    var_64 = intrinsic_movss(var_64, xmm0, rdx);
    r13 = arg1;
    r14 = arg0;
    rax = PlayerObject::preCollision(r13);
    xmm0 = intrinsic_movss(xmm0, *(int32_t *)(r13 + 0x77c));
    xmm1 = intrinsic_movss(xmm1, *(int32_t *)(r13 + 0x7e8));
    xmm0 = intrinsic_ucomiss(xmm0, *(int32_t *)value 1.0);
    if ((xmm0 == 0x0) && (CPU_FLAGS & NP)) {
            xmm2 = 0x0;
    }
    else {
            xmm2 = intrinsic_movss(xmm2, *(int32_t *)value 1.0);
            xmm2 = intrinsic_subss(xmm2, xmm0);
            xmm2 = intrinsic_mulss(xmm2, xmm1);
            xmm2 = intrinsic_mulss(xmm2, *(int32_t *)value 0.5);
    }
    xmm1 = intrinsic_mulss(xmm1, *(int32_t *)value 0.5);
    xmm0 = intrinsic_movss(xmm0, *(int32_t *)value 90.00);
    var_50 = intrinsic_movss(var_50, xmm1);
    xmm0 = intrinsic_addss(xmm0, xmm1);
    var_58 = intrinsic_movss(var_58, xmm2);
    xmm0 = intrinsic_subss(xmm0, xmm2);
    var_3C = intrinsic_movss(var_3C, xmm0);
    rax = *r13;
    rax = (*(rax + 0xc0))(r13);
    xmm0 = intrinsic_movss(xmm0, var_3C);
    xmm0 = intrinsic_ucomiss(xmm0, *(int32_t *)(rax + 0x4));
    var_30 = r14;
    if (((((xmm0 <= 0x0) || (PlayerObject::isFlying(r13) != 0x0)) || (*(int8_t *)(r13 + 0x772) != 0x0)) || (*(int8_t *)(r14 + 0x489) != 0x0)) || (*(int8_t *)(r13 + 0x775) != 0x0)) goto loc_100078d5e;

loc_100078da4 :
    if (*(int8_t *)(r13 + 0x776) == 0x0) goto loc_100078e22;

loc_100078dae :
    xmm0 = intrinsic_movss(xmm0, *(int32_t *)value 0.10);
    if (PlayerObject::isSafeFlip(r13) == 0x0) goto loc_100078d86;

loc_100078dc2 :
    rax = *r13;
    r15 = *(rax + 0xb8);
    xmm0 = intrinsic_movss(xmm0, *(int32_t *)(*(rax + 0xc0))(r13));
    rax = cocos2d::CCPoint::CCPoint(var_80, xmm0, intrinsic_movss(xmm1, var_3C));
    rax = (r15)(r13, var_80);
    rax = PlayerObject::hitGround(r13, 0x1, rdx);
    rax = PlayerObject::updateCollide(r13, 0x0, 0x0, rcx);
    *(int8_t *)(r13 + 0x7a0) = 0x0;
    *(int8_t *)(r13 + 0x769) = 0x0;
    goto loc_10007a522;

loc_10007a522 :
    rbx = stack[2042];
    r12 = stack[2043];
    r13 = stack[2044];
    r14 = stack[2045];
    r15 = stack[2046];
    rsp = rsp + 0x128;
    rbp = stack[2047];
    return xmm0;

loc_100078d86 :
    rdi = r14;
    rsi = r13;
    rbx = stack[2042];
    r12 = stack[2043];
    r13 = stack[2044];
    r14 = stack[2045];
    r15 = stack[2046];
    rsp = rsp + 0x128;
    rbp = stack[2047];
    rax = PlayLayer::destroyPlayer(rdi, rsi, 0x0, rcx, r8, r9);
    return xmm0;

loc_100078e22 :
    if (*(int8_t *)(r13 + 0x7a1) == 0x0) {
            rax = *r13;
            r15 = *(rax + 0xb8);
            xmm0 = intrinsic_movss(xmm0, *(int32_t *)(*(rax + 0xc0))(r13));
            xmm1 = intrinsic_movss(xmm1, var_3C);
            rax = cocos2d::CCPoint::CCPoint(var_80, xmm0, xmm1);
            r14 = var_30;
            rax = (r15)(r13, var_80);
            rax = PlayerObject::hitGround(r13, 0x0, 0x0);
            rdx = 0x0;
            rax = PlayerObject::updateCollide(r13, 0x1, rdx, rcx);
            *(int8_t *)(r13 + 0x769) = 0x0;
    }
    goto loc_100078e83;

loc_100078e83 :
    if (PlayerObject::isFlying(r13) != 0x0) {
            r14 = 0x0;
    }
    else {
            if (*(int8_t *)(r13 + 0x772) != 0x0) {
                    r14 = 0x0;
            }
            else {
                    r14 = *(int8_t *)(r14 + 0x489) != 0x0 ? 0x1 : 0x0;
            }
    }
    if ((((PlayerObject::isFlying(r13) != 0x0) || (*(int8_t *)(r13 + 0x772) != 0x0)) || (*(int8_t *)(r13 + 0x775) != 0x0)) || (*(int8_t *)(var_30 + 0x489) != 0x0)) goto loc_100078ee0;

loc_10007a57e :
    r14 = var_30;
    var_90 = r14 + 0x489;
    goto loc_1000792a3;

loc_1000792a3 :
    rbx = (*(*r13 + 0x4f8))(r13);
    rax = cocos2d::CCRect::getMaxX(rbx);
    var_50 = intrinsic_movss(var_50, xmm0);
    rax = cocos2d::CCRect::getMinX(rbx);
    var_40 = intrinsic_movss(var_40, xmm0);
    rax = cocos2d::CCRect::getMaxY(rbx);
    var_88 = intrinsic_movss(var_88, xmm0);
    var_60 = rbx;
    rax = cocos2d::CCRect::getMinY(rbx);
    var_84 = intrinsic_movss(var_84, xmm0);
    xmm0 = intrinsic_movss(xmm0, *(int32_t *)(*(*r13 + 0xc0))(r13));
    rdi = r14;
    r15 = sub_1000b6120();
    var_3C = cocos2d::CCArray::count(*(r14 + 0x3a8));
    var_58 = r15;
    r15 = r15 + 0xffffffffffffffff;
    var_38 = r13;
    var_48 = r13 + 0x78c;
    goto loc_100079340;

loc_100079340 :
    if ((r15 < 0x0) || (r15 >= var_3C)) goto loc_10007a180;

loc_100079353 :
    rax = cocos2d::CCArray::objectAtIndex(*(r14 + 0x3a8), r15);
    if (rax == 0x0) goto loc_10007a180;

loc_10007936b :
    rax = *(rax + 0x28);
    rcx = *(int32_t *)rax;
    if (rcx == 0x0) goto loc_10007a180;

loc_10007937a :
    r12 = *(rax + 0x8);
    rbx = r12 + rcx * 0x8 + 0xfffffffffffffff8;
    if (r12 > rbx) goto loc_10007a180;

loc_100079390 :
    r13 = *r12;
    if (r13 == 0x0) goto loc_10007a180;

loc_10007939d :
    rax = *(int32_t *)(r13 + 0x370);
    if (((rax == 0x7) || (*(int8_t *)(r13 + 0x27a) != 0x0)) || (*(int8_t *)(r13 + 0x391) != 0x0)) goto loc_1000793c0;

loc_1000793ce :
    if (rax > 0x27) goto loc_1000793ee;

loc_1000793d3 :
    rcx = 0x10007a598;
    goto *0x10007a598[sign_extend_64(*(int32_t *)(rcx + rax * 0x4)) + rcx];

loc_1000793e5 :
    rdi = *(r14 + 0x550);
    goto loc_100079452;

loc_100079452 :
    rax = cocos2d::CCArray::addObject(rdi, r13);
    r12 = r12 + 0x8;
    if (r12 <= rbx) goto loc_100079390;

loc_10007a180 :
    COND = r15 <= var_58;
    r15 = r15 + 0x1;
    if (COND) goto loc_100079340;

loc_10007a191 :
    rax = var_38;
    if (*(rax + 0x540) != 0x0) {
            rdi = rax;
            r15 = *(int8_t *)(rax + 0x554) != 0x0 ? 0x1 : 0x0;
    }
    else {
            rdi = rax;
            r15 = 0x0;
    }
    rax = *rdi;
    rax = (*(rax + 0x4f8))();
    rax = cocos2d::CCRect::operator=(var_60, rax);
    rax = cocos2d::CCRect::getMaxX(var_60);
    var_58 = intrinsic_movss(var_58, xmm0);
    rax = cocos2d::CCRect::getMinX(var_60);
    var_3C = intrinsic_movss(var_3C, xmm0);
    rax = cocos2d::CCRect::getMaxY(var_60);
    var_50 = intrinsic_movss(var_50, xmm0);
    rax = cocos2d::CCRect::getMinY(var_60);
    var_40 = intrinsic_movss(var_40, xmm0);
    rbx = cocos2d::CCArray::count(*(r14 + 0x550));
    if (rbx > 0x0) {
            rbx = rbx - 0x1;
            r13 = var_80;
            r12 = var_38;
            do {
                    r14 = cocos2d::CCArray::objectAtIndex(*(r14 + 0x550), rbx);
                    if (sub_10033b0e0(r14) == 0x0) {
                            rax = *r14;
                            rax = (*(rax + 0x4f8))(r14);
                            rax = cocos2d::CCRect::CCRect(r13, rax);
                            if ((r15 & 0x1) != 0x0) {
                                    if (*(int16_t *)(r14 + 0x460) > 0x0) {
                                            xmm0 = intrinsic_movss(xmm0, var_64);
                                            r15 = sub_10021eb70(var_38, r14) ^ 0x1;
                                    }
                            }
                            rax = cocos2d::CCRect::getMinX(r13);
                            xmm0 = intrinsic_ucomiss(xmm0, var_58);
                            if (xmm0 <= 0x0) {
                                    rax = cocos2d::CCRect::getMaxX(r13);
                                    xmm1 = intrinsic_movss(xmm1, var_3C);
                                    xmm1 = intrinsic_ucomiss(xmm1, xmm0);
                                    if (xmm1 <= 0x0) {
                                            rax = cocos2d::CCRect::getMinY(r13);
                                            xmm0 = intrinsic_ucomiss(xmm0, var_50);
                                            if (xmm0 <= 0x0) {
                                                    rax = cocos2d::CCRect::getMaxY(r13);
                                                    xmm1 = intrinsic_movss(xmm1, var_40);
                                                    xmm1 = intrinsic_ucomiss(xmm1, xmm0);
                                                    if (xmm1 <= 0x0) {
                                                            xmm0 = intrinsic_movss(xmm0, var_64);
                                                            rax = sub_10021d880(r12, r14);
                                                            rax = *r12;
                                                            rax = (*(rax + 0x4f8))(r12);
                                                            rax = cocos2d::CCRect::operator=(var_60, rax);
                                                            rax = cocos2d::CCRect::getMaxX(var_60);
                                                            var_58 = intrinsic_movss(var_58, xmm0);
                                                            rax = cocos2d::CCRect::getMinX(var_60);
                                                            var_3C = intrinsic_movss(var_3C, xmm0);
                                                            rax = cocos2d::CCRect::getMaxY(var_60);
                                                            var_50 = intrinsic_movss(var_50, xmm0);
                                                            rax = cocos2d::CCRect::getMinY(var_60);
                                                            var_40 = intrinsic_movss(var_40, xmm0);
                                                    }
                                            }
                                    }
                            }
                    }
                    rbx = rbx - 0x1;
                    r14 = var_30;
            } while (rbx != 0xffffffff);
    }
    rax = cocos2d::CCArray::removeAllObjects(*(r14 + 0x550));
    rsi = (*(*var_38 + 0x4f8))(var_38);
    rax = cocos2d::CCRect::operator=(var_60, rsi);
    rax = cocos2d::CCRect::getMaxX(var_60);
    var_58 = intrinsic_movss(var_58, xmm0);
    rax = cocos2d::CCRect::getMinX(var_60);
    var_3C = intrinsic_movss(var_3C, xmm0);
    rax = cocos2d::CCRect::getMaxY(var_60);
    var_50 = intrinsic_movss(var_50, xmm0);
    rax = cocos2d::CCRect::getMinY(var_60);
    var_60 = intrinsic_movss(var_60, xmm0);
    rax = GameObject::updateOrientedBox(var_38);
    rax = cocos2d::CCArray::count(*(r14 + 0x568));
    rdi = *(r14 + 0x568);
    if (rax == 0x0) goto loc_10007a50f;

loc_10007a3d1 :
    rbx = 0x0;
    r15 = var_80;
    goto loc_10007a3e0;

loc_10007a3e0 :
    rsi = rbx;
    r13 = cocos2d::CCArray::objectAtIndex(rdi, rsi);
    if (sub_10033b0e0(r13) != 0x0) goto loc_10007a4f2;

loc_10007a3fa :
    rsi = (*(*r13 + 0x4f8))(r13);
    rax = cocos2d::CCRect::CCRect(r15, rsi);
    xmm0 = intrinsic_movss(xmm0, *(int32_t *)(r13 + 0x35c));
    xmm0 = intrinsic_ucomiss(xmm0, *(int32_t *)value 0.00);
    if (xmm0 <= 0x0) goto loc_10007a440;

loc_10007a424 :
    rdi = r14;
    rsi = var_38;
    rdx = r13;
    if (sub_1000b66e0() != 0x0) goto loc_10007a499;

loc_10007a4ee :
    r14 = var_30;
    goto loc_10007a4f2;

loc_10007a4f2 :
    rbx = rbx + 0x1;
    rax = cocos2d::CCArray::count(*(r14 + 0x568));
    rdi = *(r14 + 0x568);
    if (rbx < rax) goto loc_10007a3e0;

loc_10007a50f :
    rax = cocos2d::CCArray::removeAllObjects(rdi);
    xmm0 = intrinsic_movss(xmm0, var_64);
    rax = sub_10021cd10(var_38, rsi);
    goto loc_10007a522;

loc_10007a499 :
    if (*(int8_t *)(r13 + 0x2b8) == 0x0) goto loc_10007a4e1;

loc_10007a4a3 :
    r14 = (*(*r13 + 0x5a8))(r13);
    r12 = (*(*var_38 + 0x5a8))(var_38);
    rsi = r12;
    if (sub_10035b0d0(r14, rsi) == 0x0) goto loc_10007a4ee;

loc_10007a4d2 :
    rsi = r14;
    if (sub_10035b0d0(r12, rsi) == 0x0) goto loc_10007a4ee;

loc_10007a4e1 :
    if (*(int8_t *)(var_30 + 0x700) == 0x0) goto loc_10007a534;
    goto loc_10007a4ee;

loc_10007a534 :
    rax = PlayLayer::destroyPlayer(var_30, var_38, r13, rcx, r8, 0x1);
    goto loc_10007a522;

loc_10007a440 :
    rax = cocos2d::CCRect::getMinX(r15);
    r14 = 0x1;
    xmm0 = intrinsic_ucomiss(xmm0, var_58);
    if (xmm0 <= 0x0) {
            rax = cocos2d::CCRect::getMaxX(r15);
            xmm1 = intrinsic_movss(xmm1, var_3C);
            xmm1 = intrinsic_ucomiss(xmm1, xmm0);
            if (xmm1 <= 0x0) {
                    rax = cocos2d::CCRect::getMinY(r15);
                    xmm0 = intrinsic_ucomiss(xmm0, var_50);
                    if (xmm0 <= 0x0) {
                            rax = cocos2d::CCRect::getMaxY(r15);
                            xmm1 = intrinsic_movss(xmm1, var_60);
                            xmm1 = intrinsic_ucomiss(xmm1, xmm0);
                            r14 = xmm1 > 0x0 ? 0x1 : 0x0;
                    }
            }
    }
    if ((r14 ^ 0x1) == 0x0) goto loc_10007a4ee;
    goto loc_10007a499;

loc_1000793ee :
    if (loc_100342a50(r13, var_38) != 0x0) goto loc_1000793c0;

loc_1000793fe :
    rax = cocos2d::CCRect::CCRect(var_80);
    if ((*(*r13 + 0x5e8))(r13) == 0x19) {
            rax = *r13;
            rcx = var_A0;
            rdi = rcx;
            rsi = r13;
            xmm0 = intrinsic_movss(xmm0, *(int32_t *)value 2.00);
            xmm1 = intrinsic_movaps(xmm1, xmm0);
            rax = (*(rax + 0x500))();
            rdi = var_80;
            rsi = var_A0;
    }
    else {
            rdi = var_80;
            rsi = (*(*r13 + 0x4f8))(r13);
    }
    rax = cocos2d::CCRect::operator=(rdi, rsi);
    xmm0 = intrinsic_movss(xmm0, *(int32_t *)(r13 + 0x35c));
    xmm0 = intrinsic_ucomiss(xmm0, *(int32_t *)value 0.00);
    if (xmm0 <= 0x0) goto loc_1000794b3;

loc_100079497 :
    rdi = r14;
    rsi = var_38;
    rdx = r13;
    if (sub_1000b66e0() != 0x0) goto loc_10007950e;

loc_100079565 :
    r14 = var_30;
    r12 = r12 + 0x8;
    if (r12 <= rbx) goto loc_100079390;
    goto loc_10007a180;

loc_10007950e :
    if (*(int8_t *)(r13 + 0x2b8) != 0x0) {
            var_70 = (*(*r13 + 0x5a8))(r13);
            rax = GameObject::updateOrientedBox(var_38);
            r14 = (*(*var_38 + 0x5a8))(var_38);
            if (sub_10035b0d0(var_70, r14) != 0x0) {
                    r14 = sub_10035b0d0(r14, var_70);
            }
            else {
                    r14 = 0x0;
            }
    }
    else {
            r14 = 0x1;
    }
    if ((*(*r13 + 0x5e8))(r13) == 0x19) {
            rax = *r13;
            rax = (*(rax + 0x4f8))(r13);
            rax = cocos2d::CCRect::operator=(var_80, rax);
    }
    if (r14 == 0x0) goto loc_1000795fb;

loc_1000795b3 :
    rax = *(int32_t *)(r13 + 0x370);
    rax = rax + 0xfffffffd;
    r14 = var_30;
    if (rax > 0x25) goto loc_1000793c0;

loc_1000795ca :
    rcx = 0x10007a638;
    goto *0x10007a638[sign_extend_64(*(int32_t *)(rcx + rax * 0x4)) + rcx];

loc_100079698 :
    r14 = var_38;
    if (*(int8_t *)(r14 + 0x776) == 0x0) {
            rax = PlayLayer::playGravityEffect(var_30, 0x1);
    }
    rax = *r13;
    rax = (*(rax + 0xc0))(r13);
    rax = cocos2d::CCPoint::CCPoint(var_E0, rax);
    rax = cocos2d::CCPoint::operator=(var_48, var_E0);
    *(r14 + 0x7b8) = r13;
    rsi = r14;
    r14 = var_30;
    rax = *r14;
    rdx = 0x1;
    rcx = 0x0;
    rax = (*(rax + 0x460))(r14, rsi, rdx, rcx);
    rax = GameObject::playShineEffect(r13);
    rax = GameObject::activatedByPlayer(r13, var_38);
    r12 = r12 + 0x8;
    if (r12 <= rbx) goto loc_100079390;
    goto loc_10007a180;

loc_100079727 :
    if (*(int8_t *)(var_38 + 0x776) != 0x0) {
            rax = PlayLayer::playGravityEffect(r14, 0x0);
    }
    rax = *r13;
    rax = (*(rax + 0xc0))(r13);
    rax = cocos2d::CCPoint::CCPoint(var_120, rax);
    rax = cocos2d::CCPoint::operator=(var_48, var_120);
    r14 = var_38;
    *(r14 + 0x7b8) = r13;
    rax = *var_30;
    rdx = 0x0;
    rcx = 0x0;
    rax = (*(rax + 0x460))(var_30, r14, rdx, rcx);
    goto loc_100079c33;

loc_100079c33 :
    rax = GameObject::playShineEffect(r13);
    rsi = r14;
    r14 = var_30;
    rax = GameObject::activatedByPlayer(r13, rsi);
    r12 = r12 + 0x8;
    if (r12 <= rbx) goto loc_100079390;
    goto loc_10007a180;

loc_100079791 :
    rdi = r14;
    r14 = var_38;
    rax = PlayLayer::playerWillSwitchMode(rdi, r14, r13, 0x0);
    rcx = 0x0;
    r8 = 0x5;
    goto loc_100079c24;

loc_100079c24 :
    rdx = r13;
    rax = sub_10007baf0(var_30, r14, rdx);
    goto loc_100079c33;

loc_1000797b0 :
    rcx = 0x10007a638;
    rdi = r14;
    r14 = var_38;
    rax = PlayLayer::playerWillSwitchMode(rdi, r14, r13, rcx);
    rax = *r13;
    rax = (*(rax + 0xc0))(r13);
    rax = cocos2d::CCPoint::CCPoint(var_D8, rax);
    rax = cocos2d::CCPoint::operator=(var_48, var_D8);
    *(r14 + 0x7b8) = r13;
    rdx = r14;
    rax = PlayLayer::willSwitchToMode(var_30, 0x0, rdx);
    rax = PlayerObject::modeDidChange(r14);
    goto loc_100079c33;

loc_1000793c0 :
    r12 = r12 + 0x8;
    if (r12 <= rbx) goto loc_100079390;
    goto loc_10007a180;

loc_100079611 :
    rdi = r14;
    rsi = var_38;
    rdx = r13;
    rax = GJBaseGameLayer::bumpPlayer();
    r12 = r12 + 0x8;
    if (r12 <= rbx) goto loc_100079390;
    goto loc_10007a180;

loc_100079810 :
    rax = loc_100342cf0(r13);
    rax = rax ^ 0x1;
    r14 = var_38;
    rcx = (*(int8_t *)(r14 + 0x776) != 0x0 ? 0x1 : 0x0) ^ rax;
    if (rcx != 0x1) goto loc_10007a04b;

loc_100079834 :
    var_70 = rax & 0xff;
    rax = PlayLayer::playGravityEffect(var_30, rax & 0xff);
    var_A8 = (*(*r13 + 0xc0))(r13);
    xmm1 = intrinsic_movss(xmm1, *(int32_t *)value -10.00);
    rax = cocos2d::CCPoint::CCPoint(var_A0, 0x0, xmm1);
    rax = cocos2d::CCPoint::operator+(var_B0, var_A8, var_A0);
    rax = cocos2d::CCPoint::operator=(var_48, var_B0);
    rax = GameObject::activatedByPlayer(r13, r14);
    *(r14 + 0x7b8) = r13;
    xmm0 = intrinsic_movss(0x0, *(int32_t *)value 0.8);
    rax = sub_10022d8e0(r14, r14);
    rax = *var_30;
    rcx = 0x1;
    rdx = var_70;
    rax = (*(rax + 0x460))(var_30, r14, rdx, rcx);
    *(int8_t *)(r14 + 0x628) = 0x1;
    r14 = var_30;
    r12 = r12 + 0x8;
    if (r12 <= rbx) goto loc_100079390;
    goto loc_10007a180;

loc_10007a04b :
    r14 = var_30;
    r12 = r12 + 0x8;
    if (r12 <= rbx) goto loc_100079390;
    goto loc_10007a180;

loc_1000795da :
    rdi = r14;
    rsi = var_38;
    rdx = r13;
    rax = GJBaseGameLayer::playerTouchedRing();
    r12 = r12 + 0x8;
    if (r12 <= rbx) goto loc_100079390;
    goto loc_10007a180;

loc_1000798f2 :
    rax = *r13;
    rax = (*(rax + 0xc0))(r13);
    rax = cocos2d::CCPoint::CCPoint(var_F8, rax);
    r14 = var_30;
    rax = cocos2d::CCPoint::operator=(var_48, var_F8);
    *(var_38 + 0x7b8) = r13;
    rsi = 0x1;
    goto loc_10007996f;

loc_10007996f :
    rdx = 0x0;
    rax = sub_10007bdc0(r14, rsi, rdx);
    goto loc_100079b6c;

loc_100079b6c :
    rax = GameObject::playShineEffect(r13);
    goto loc_100079b74;

loc_100079b74 :
    rax = *r13;
    xmm0 = 0x0;
    rax = (*(rax + 0x580))(r13);
    r12 = r12 + 0x8;
    if (r12 <= rbx) goto loc_100079390;
    goto loc_10007a180;

loc_100079933 :
    rax = *r13;
    rax = (*(rax + 0xc0))(r13);
    rax = cocos2d::CCPoint::CCPoint(var_100, rax);
    r14 = var_30;
    rax = cocos2d::CCPoint::operator=(var_48, var_100);
    *(var_38 + 0x7b8) = r13;
    rsi = 0x0;
    goto loc_10007996f;

loc_10007997e :
    rcx = 0x10007a638;
    rax = PlayLayer::playerWillSwitchMode(r14, var_38, r13, rcx);
    rdx = var_38;
    rax = PlayLayer::willSwitchToMode(r14, 0x10, rdx);
    if (*(int8_t *)var_90 != 0x0) {
            r14 = *(var_30 + 0x710);
            if (r14 == 0x0) {
                    r14 = r13;
            }
    }
    else {
            r14 = r13;
    }
    rax = *r14;
    rax = (*(rax + 0xc0))(r14);
    rax = cocos2d::CCPoint::CCPoint(var_A0, rax);
    rax = cocos2d::CCPoint::operator=(var_48, var_A0);
    *(var_38 + 0x7b8) = r14;
    *(var_30 + 0x708) = r14;
    r14 = var_38;
    rax = PlayerObject::toggleRollMode(var_38, 0x1);
    goto loc_10007a15b;

loc_10007a15b :
    rax = GameObject::playShineEffect(r13);
    rax = GameObject::activatedByPlayer(r13, r14);
    r14 = var_30;
    r12 = r12 + 0x8;
    if (r12 <= rbx) goto loc_100079390;
    goto loc_10007a180;

loc_1000799c5 :
    rax = *r13;
    rax = (*(rax + 0xc0))(r13);
    rax = cocos2d::CCPoint::CCPoint(var_110, rax);
    rax = cocos2d::CCPoint::operator=(var_48, var_110);
    r14 = var_38;
    *(r14 + 0x7b8) = r13;
    rsi = 0x0;
    goto loc_100079a3a;

loc_100079a3a :
    rax = PlayerObject::togglePlayerScale(r14, rsi, rdx);
    goto loc_100079c33;

loc_1000799ff :
    rax = *r13;
    rax = (*(rax + 0xc0))(r13);
    rax = cocos2d::CCPoint::CCPoint(var_108, rax);
    rax = cocos2d::CCPoint::operator=(var_48, var_108);
    r14 = var_38;
    *(r14 + 0x7b8) = r13;
    rsi = 0x1;
    goto loc_100079a3a;

loc_100079a47 :
    rdi = r14;
    r14 = var_38;
    rax = PlayLayer::playerWillSwitchMode(rdi, r14, r13, 0x0);
    rcx = 0x0;
    r8 = 0x13;
    goto loc_100079c24;

loc_100079a66 :
    if (*(int8_t *)(r13 + 0x378) == 0x0) goto loc_1000793c0;

loc_100079a74 :
    if (GJEffectManager::hasBeenTriggered(*(r14 + 0x180), *(int32_t *)(r13 + 0x36c)) == 0x0) {
            rax = GJEffectManager::storeTriggeredID(*(r14 + 0x180), *(int32_t *)(r13 + 0x36c));
            rax = *r13;
            rax = (*(rax + 0x4e0))(r13, r14);
    }
    goto loc_100079b74;

loc_100079632 :
    if (*(int8_t *)(r14 + 0x739) != 0x0) goto loc_1000793c0;

loc_100079640 :
    rax = *r13;
    rax = (*(rax + 0x4e0))(r13, r14);
    rax = *r13;
    xmm0 = 0x0;
    rax = (*(rax + 0x580))(r13);
    rax = GameObject::destroyObject(r13, r14);
    if (PlayLayer::hasUniqueCoin(r14, r13) != 0x0) goto loc_1000793c0;

loc_10007967b :
    rax = PlayLayer::pickupItem(r14, r13);
    r12 = r12 + 0x8;
    if (r12 <= rbx) goto loc_100079390;
    goto loc_10007a180;

loc_100079ab7 :
    rax = *r13;
    rax = (*(rax + 0xc0))(r13);
    rax = cocos2d::CCPoint::CCPoint(var_E8, rax);
    r14 = var_30;
    rax = cocos2d::CCPoint::operator=(var_48, var_E8);
    rcx = var_38;
    *(rcx + 0x7b8) = r13;
    *(int8_t *)(*(r14 + 0x388) + 0x7e0) = 0x1;
    rdx = 0x1;
    r8 = 0x0;
    rax = PlayLayer::toggleDualMode(r14, r13, rdx, rcx, r8);
    *(int8_t *)(*(r14 + 0x388) + 0x7e0) = 0x0;
    goto loc_100079b6c;

loc_100079b22 :
    rax = *r13;
    rax = (*(rax + 0xc0))(r13);
    rax = cocos2d::CCPoint::CCPoint(var_F0, rax);
    r14 = var_30;
    rax = cocos2d::CCPoint::operator=(var_48, var_F0);
    rcx = var_38;
    *(rcx + 0x7b8) = r13;
    rdx = 0x0;
    r8 = 0x0;
    rax = PlayLayer::toggleDualMode(r14, r13, rdx, rcx, r8);
    goto loc_100079b6c;

loc_100079b96 :
    rdx = 0x0;
    xmm0 = intrinsic_movss(xmm0, var_64);
    rax = PlayerObject::collidedWithSlope(var_38, r13, rdx);
    rax = *var_38;
    r14 = var_30;
    rax = (*(rax + 0x4f8))(var_38);
    rax = cocos2d::CCRect::operator=(var_60, rax);
    rax = cocos2d::CCRect::getMaxX(var_60);
    var_50 = intrinsic_movss(var_50, xmm0);
    rax = cocos2d::CCRect::getMinX(var_60);
    var_40 = intrinsic_movss(var_40, xmm0);
    rax = cocos2d::CCRect::getMaxY(var_60);
    var_88 = intrinsic_movss(var_88, xmm0);
    rax = cocos2d::CCRect::getMinY(var_60);
    var_84 = intrinsic_movss(var_84, xmm0);
    goto loc_1000793c0;

loc_100079c0a :
    rdi = r14;
    r14 = var_38;
    rax = PlayLayer::playerWillSwitchMode(rdi, r14, r13, 0x0);
    rcx = 0x0;
    r8 = 0x1a;
    goto loc_100079c24;

loc_100079c5c :
    rcx = 0x10007a638;
    rax = PlayLayer::playerWillSwitchMode(r14, var_38, r13, rcx);
    rdx = var_38;
    rax = PlayLayer::willSwitchToMode(r14, 0x1b, rdx);
    if (*(int8_t *)var_90 != 0x0) {
            r14 = *(var_30 + 0x710);
            if (r14 == 0x0) {
                    r14 = r13;
            }
    }
    else {
            r14 = r13;
    }
    rax = *r14;
    rax = (*(rax + 0xc0))(r14);
    rax = cocos2d::CCPoint::CCPoint(var_A0, rax);
    rax = cocos2d::CCPoint::operator=(var_48, var_A0);
    *(var_38 + 0x7b8) = r14;
    *(var_30 + 0x708) = r14;
    r14 = var_38;
    rax = sub_100223c70(var_38, 0x1, rdx);
    goto loc_10007a15b;

loc_100079ca3 :
    rax = *r13;
    rax = (*(rax + 0xc0))(r13);
    rax = cocos2d::CCPoint::CCPoint(var_118, rax);
    rax = cocos2d::CCPoint::operator=(var_48, var_118);
    *(var_38 + 0x7b8) = r13;
    rax = *var_38;
    rcx = *(rax + 0xb8);
    xmm0 = intrinsic_movss(xmm0, *(int32_t *)(*(rax + 0xc0))(var_38));
    var_40 = intrinsic_movss(var_40, xmm0);
    rax = *r13;
    rax = (*(rax + 0x518))(var_D0, r13);
    xmm1 = intrinsic_movss(xmm1, var_CC);
    xmm1 = intrinsic_addss(xmm1, *(int32_t *)(r13 + 0x504));
    xmm0 = intrinsic_movss(xmm0, var_40);
    rax = cocos2d::CCPoint::CCPoint(var_A0, xmm0, xmm1);
    rax = (rcx)(var_38, var_A0);
    rax = *var_38;
    rax = (*(rax + 0x4f8))(var_38);
    rax = cocos2d::CCRect::operator=(var_60, rax);
    rax = cocos2d::CCRect::getMaxX(var_60);
    var_50 = intrinsic_movss(rcx, xmm0);
    rax = cocos2d::CCRect::getMinX(var_60);
    var_40 = intrinsic_movss(var_40, xmm0);
    rax = cocos2d::CCRect::getMaxY(var_60);
    var_88 = intrinsic_movss(var_88, xmm0);
    r14 = var_38;
    rax = cocos2d::CCRect::getMinY(var_60);
    var_84 = intrinsic_movss(var_84, xmm0);
    rax = GameObject::playShineEffect(r13);
    rax = GameObject::activatedByPlayer(r13, r14);
    xmm0 = intrinsic_movss(xmm0, *(int32_t *)value 50.00);
    rax = PlayerObject::spawnPortalCircle(r14, 0xffff00, rdx);
    rdi = *(r13 + 0x4f8);
    if (rdi != 0x0) {
            rax = *rdi;
            rax = (*(rax + 0xc0))();
            rax = cocos2d::CCPoint::CCPoint(var_C8, rax);
            rax = cocos2d::CCPoint::operator=(var_48, var_C8);
            rdi = *(r13 + 0x4f8);
            *(r14 + 0x7b8) = rdi;
            rax = GameObject::playShineEffect(rdi);
            xmm0 = intrinsic_movss(xmm0, *(int32_t *)value 50.00);
            rax = PlayerObject::spawnPortalCircle(r14, 0xc8ff, rdx);
            rax = sub_10021ae10(r14);
            if (*(int8_t *)(r14 + 0x773) != 0x0) {
                    rax = sub_10021af90(r14);
            }
            rax = *r13;
            rax = (*(rax + 0xc0))(r13);
            rax = cocos2d::CCPoint::CCPoint(var_C0, rax);
            rdi = *(r13 + 0x4f8);
            rax = *rdi;
            rax = (*(rax + 0xc0))(rdi);
            rax = cocos2d::CCPoint::CCPoint(var_B8, rax);
            rax = *(int16_t *)(r14 + 0x7c2) & 0xffff;
            rcx = *(int8_t *)(r14 + 0x7c4) & 0xff;
            xmm0 = intrinsic_movss(xmm0, *(int32_t *)0x10050c79c);
            xmm1 = intrinsic_movss(xmm1, *(int32_t *)value 0.20);
            xmm2 = intrinsic_movss(xmm2, *(int32_t *)value 1.0);
            r8 = 0x64;
            rdx = var_B8;
            rax = sub_100075cc0(var_30, var_C0, rdx, rcx << 0x10 | rax, r8, 0x1);
    }
    rax = var_30;
    if (*(int8_t *)(r13 + 0x508) != 0x0) {
            *(int32_t *)(rax + 0x4e0) = 0x3f000000;
    }
    rax = cocos2d::CCDirector::sharedDirector();
    rax = cocos2d::CCDirector::getWinSize(var_A0, rax);
    rcx = 0x10050d4a8;
    xmm0 = intrinsic_movss(xmm0, *(int32_t *)(rcx + (*(int8_t *)(r13 + 0x508) & 0xff) * 0x4));
    var_70 = intrinsic_movss(var_70, xmm0);
    rax = sub_10022b840(var_38);
    xmm0 = intrinsic_movss(xmm0, *(int32_t *)((*(*var_38 + 0xc0))(var_38) + 0x4));
    r14 = var_30;
    xmm1 = intrinsic_movss(xmm1, *(int32_t *)(r14 + 0x734));
    xmm1 = intrinsic_addss(xmm1, var_9C);
    xmm1 = intrinsic_addss(xmm1, var_70);
    xmm0 = intrinsic_ucomiss(xmm0, xmm1);
    if (xmm0 > 0x0) goto loc_100079f68;

loc_100079f43 :
    rax = *var_38;
    rax = (*(rax + 0xc0))(var_38);
    xmm0 = intrinsic_movss(xmm0, *(int32_t *)(r14 + 0x734));
    xmm0 = intrinsic_subss(xmm0, var_70);
    xmm0 = intrinsic_ucomiss(xmm0, *(int32_t *)(rax + 0x4));
    if (xmm0 <= 0x0) goto loc_1000793c0;

loc_100079f68 :
    *(int8_t *)(r14 + 0x4dd) = 0x1;
    r12 = r12 + 0x8;
    if (r12 <= rbx) goto loc_100079390;
    goto loc_10007a180;

loc_100079f82 :
    rdi = *(r14 + 0x180);
    rsi = *(int32_t *)(r13 + 0x36c);
    if (GJEffectManager::hasBeenTriggered(rdi, rsi) == 0x0) {
            rax = GJEffectManager::storeTriggeredID(*(r14 + 0x180), *(int32_t *)(r13 + 0x36c));
            rax = *r13;
            rsi = r14;
            rax = (*(rax + 0x4e0))(r13, rsi);
    }
    rax = *r13;
    xmm0 = 0x0;
    rax = (*(rax + 0x580))(r13);
    rax = GameObject::destroyObject(r13, rsi);
    r12 = r12 + 0x8;
    if (r12 <= rbx) goto loc_100079390;
    goto loc_10007a180;

loc_100079fe6 :
    rcx = 0x10007a638;
    rax = PlayLayer::playerWillSwitchMode(r14, var_38, r13, rcx);
    rdx = var_38;
    rax = PlayLayer::willSwitchToMode(r14, 0x21, rdx);
    if (*(int8_t *)var_90 != 0x0) {
            r14 = *(var_30 + 0x710);
            if (r14 == 0x0) {
                    r14 = r13;
            }
    }
    else {
            r14 = r13;
    }
    rax = *r14;
    rax = (*(rax + 0xc0))(r14);
    rax = cocos2d::CCPoint::CCPoint(var_A0, rax);
    rax = cocos2d::CCPoint::operator=(var_48, var_A0);
    *(var_38 + 0x7b8) = r14;
    *(var_30 + 0x708) = r14;
    r14 = var_38;
    rax = PlayerObject::toggleSpiderMode(var_38, 0x1, rdx);
    goto loc_10007a15b;

loc_10007a02d :
    rax = PlayerObject::touchedObject(var_38, r13, rdx);
    r12 = r12 + 0x8;
    if (r12 <= rbx) goto loc_100079390;
    goto loc_10007a180;

loc_1000795fb :
    r14 = var_30;
    r12 = r12 + 0x8;
    if (r12 <= rbx) goto loc_100079390;
    goto loc_10007a180;

loc_1000794b3 :
    rax = cocos2d::CCRect::getMinX(var_80);
    r14 = 0x1;
    xmm0 = intrinsic_ucomiss(xmm0, var_50);
    if (xmm0 <= 0x0) {
            rax = cocos2d::CCRect::getMaxX(var_80);
            xmm1 = intrinsic_movss(xmm1, var_40);
            xmm1 = intrinsic_ucomiss(xmm1, xmm0);
            if (xmm1 <= 0x0) {
                    rax = cocos2d::CCRect::getMinY(var_80);
                    xmm0 = intrinsic_ucomiss(xmm0, var_88);
                    if (xmm0 <= 0x0) {
                            rax = cocos2d::CCRect::getMaxY(var_80);
                            xmm1 = intrinsic_movss(xmm1, var_84);
                            xmm1 = intrinsic_ucomiss(xmm1, xmm0);
                            r14 = xmm1 > 0x0 ? 0x1 : 0x0;
                    }
            }
    }
    if ((r14 ^ 0x1) == 0x0) goto loc_100079565;
    goto loc_10007950e;

loc_10007944b :
    rdi = *(r14 + 0x568);
    goto loc_100079452;

loc_100078ee0 :
    rbx = var_30;
    if (*(int8_t *)(rbx + 0x489) != 0x0) {
            rax = cocos2d::CCDirector::sharedDirector();
            rax = cocos2d::CCDirector::getWinSize(var_80, rax);
            rax = GJGroundLayer::getGroundY(*(rbx + 0x5c8));
            var_3C = intrinsic_movss(var_3C, xmm0);
            rdi = *(rbx + 0x5d0);
            rax = *rdi;
            rax = (*(rax + 0xc0))(rdi);
            xmm2 = intrinsic_movss(xmm2, *(int32_t *)(rbx + 0x734));
            xmm2 = intrinsic_addss(xmm2, var_7C);
            xmm0 = intrinsic_movss(xmm0, var_3C);
            xmm0 = intrinsic_subss(xmm0, *(int32_t *)(rax + 0x4));
            xmm2 = intrinsic_subss(xmm2, xmm0);
            xmm2 = intrinsic_addss(xmm2, *(int32_t *)value 1.0);
            if (*(int8_t *)(rbx + 0x489) != 0x0) {
                    rdi = *(rbx + 0x5c8);
                    var_40 = intrinsic_movss(var_40, xmm2);
                    rax = GJGroundLayer::getGroundY(rdi);
                    var_3C = intrinsic_movss(var_3C, xmm0);
                    rdi = *(rbx + 0x5c8);
                    rax = *rdi;
                    rax = (*(rax + 0xc0))(rdi);
                    xmm2 = intrinsic_movss(xmm2, var_40);
                    xmm0 = intrinsic_movss(xmm0, var_3C);
                    xmm0 = intrinsic_addss(xmm0, *(int32_t *)(rax + 0x4));
                    xmm0 = intrinsic_addss(xmm0, *(int32_t *)(rbx + 0x734));
                    xmm0 = intrinsic_addss(xmm0, *(int32_t *)value -1.00);
                    var_3C = intrinsic_movss(var_3C, xmm0);
                    xmm0 = intrinsic_movss(xmm0, *(int32_t *)(rbx + 0x4fc));
                    var_48 = intrinsic_movss(var_48, xmm0);
            }
            else {
                    xmm0 = intrinsic_movss(xmm0, *(int32_t *)(rbx + 0x4fc));
                    var_48 = intrinsic_movss(var_48, xmm0);
                    var_3C = intrinsic_movss(var_3C, xmm0);
            }
    }
    else {
            xmm2 = intrinsic_movss(xmm2, *(int32_t *)(rbx + 0x500));
            xmm0 = intrinsic_movss(xmm0, *(int32_t *)(rbx + 0x4fc));
            var_48 = intrinsic_movss(var_48, xmm0);
            var_3C = intrinsic_movss(var_3C, xmm0);
    }
    xmm0 = intrinsic_movss(xmm0, var_50);
    xmm1 = intrinsic_movss(xmm1, var_58);
    r15 = rbx + 0x489;
    var_60 = intrinsic_movss(var_60, intrinsic_addss(intrinsic_subss(intrinsic_movaps(xmm3, xmm2), xmm0), xmm1));
    xmm2 = intrinsic_subss(xmm2, *(int32_t *)(rbx + 0x500));
    var_40 = intrinsic_movss(var_40, xmm2);
    xmm0 = intrinsic_movss(xmm0, *(int32_t *)((*(*r13 + 0xc0))(r13) + 0x4));
    xmm0 = intrinsic_ucomiss(xmm0, var_60);
    if (xmm0 <= 0x0) goto loc_1000790a0;

loc_10007900c :
    if (*(int8_t *)(r13 + 0x769) == 0x0) goto loc_10007903b;

loc_100079016 :
    xmm0 = intrinsic_movss(xmm0, *(int32_t *)((*(*r13 + 0xc0))(r13) + 0x4));
    xmm1 = intrinsic_movss(xmm1, var_50);
    xmm1 = intrinsic_addss(xmm1, var_60);
    xmm0 = intrinsic_ucomiss(xmm0, xmm1);
    if (xmm0 > 0x0) goto loc_1000790f3;

loc_10007903b :
    if ((r14 == 0x0) || (*(int8_t *)(r13 + 0x776) != 0x0)) goto loc_10007904e;

loc_10007a546 :
    xmm0 = intrinsic_movss(xmm0, *(int32_t *)value 0.20);
    r14 = 0x1;
    if (PlayerObject::isSafeFlip(r13) != 0x0) goto loc_100079051;

loc_10007a561 :
    xmm0 = intrinsic_movss(xmm0, *(int32_t *)value 0.20);
    if (sub_1002209b0(r13) != 0x0) goto loc_100079051;

loc_1000790f3 :
    rax = PlayLayer::destroyPlayer(var_30, r13, 0x0, rcx, r8, r9);
    goto loc_10007a522;

loc_100079051 :
    var_90 = r15;
    rax = *r13;
    r12 = *(rax + 0xb8);
    xmm0 = intrinsic_movss(xmm0, *(int32_t *)(*(rax + 0xc0))(r13));
    xmm1 = intrinsic_movss(xmm1, var_60);
    rax = cocos2d::CCPoint::CCPoint(var_80, xmm0, xmm1);
    rax = (r12)(r13, var_80);

    
    if (r14 != 0x0) {
            rax = sub_10022dbd0(r13);
    }
    else {
            xmm0 = intrinsic_movsd(xmm0, *(r13 + 0x760));
            xmm1 = 0x0;
            xmm0 = intrinsic_ucomisd(xmm0, xmm1);
            if (xmm0 > 0x0) {
                    xmm0 = intrinsic_movss(xmm0, *(int32_t *)0x10050c978);
                    xmm0 = intrinsic_ucomiss(xmm0, var_40);
                    rcx = (*(int8_t *)(r13 + 0x776) == 0x0 ? 0x1 : 0x0) | (xmm0 > 0x0 ? 0x1 : 0x0);
                    rax = PlayerObject::hitGround(r13, rcx & 0xff, rdx);
            }
    }
    rsi = *(int8_t *)(r13 + 0x776) & 0xff;
    rdx = 0x0;
    rax = PlayerObject::updateCollide(r13, rsi, rdx, rcx);
    xmm0 = intrinsic_movss(xmm0, *(int32_t *)0x10050c978);
    xmm0 = intrinsic_ucomiss(xmm0, var_40);
    r14 = var_30;
    if (xmm0 > 0x0) {
            xmm0 = intrinsic_movsd(xmm0, *(r13 + 0x760));
            xmm1 = 0x0;
            xmm0 = intrinsic_ucomisd(xmm0, xmm1);
            if (xmm0 >= 0x0) {
                    rax = sub_10022dbf0(r13, rsi);
            }
    }
    goto loc_10007929b;

loc_10007929b :
    *(int8_t *)(r13 + 0x769) = 0x0;
    goto loc_1000792a3;

loc_10007904e :
    r14 = 0x0;
    goto loc_100079051;

loc_1000790a0 :
    xmm0 = intrinsic_movss(xmm0, var_50);
    xmm0 = intrinsic_addss(xmm0, var_3C);
    xmm0 = intrinsic_subss(xmm0, var_58);
    var_58 = intrinsic_movss(var_58, xmm0);
    rax = *r13;
    rax = (*(rax + 0xc0))(r13);
    xmm0 = intrinsic_movss(xmm0, var_58);
    xmm0 = intrinsic_ucomiss(xmm0, *(int32_t *)(rax + 0x4));
    if (xmm0 <= 0x0) goto loc_100079106;

loc_1000790cc :
    if (*(int8_t *)(r13 + 0x769) == 0x0) goto loc_100079116;

loc_1000790d6 :
    rax = *r13;
    rax = (*(rax + 0xc0))(r13);
    xmm0 = intrinsic_movss(xmm0, var_58);
    xmm0 = intrinsic_subss(xmm0, var_50);
    xmm0 = intrinsic_ucomiss(xmm0, *(int32_t *)(rax + 0x4));
    if (xmm0 <= 0x0) goto loc_100079116;
    goto loc_1000790f3;

loc_100079116 :
    if ((r14 == 0x0) || (*(int8_t *)(r13 + 0x776) == 0x0)) goto loc_1000791da;

loc_10007912d :
    xmm0 = intrinsic_movss(xmm0, *(int32_t *)value 0.20);
    r14 = 0x1;
    if (PlayerObject::isSafeFlip(r13) != 0x0) goto loc_1000791dd;

loc_100079148 :
    xmm0 = intrinsic_movss(xmm0, *(int32_t *)value 0.20);
    if (sub_1002209b0(r13) == 0x0) goto loc_1000790f3;

loc_1000791dd :
    var_90 = r15;
    xmm0 = intrinsic_movss(xmm0, var_3C);
    xmm0 = intrinsic_subss(xmm0, var_48);
    var_3C = intrinsic_movss(var_3C, xmm0);
    rax = *r13;
    r12 = *(rax + 0xb8);
    xmm0 = intrinsic_movss(xmm0, *(int32_t *)(*(rax + 0xc0))(r13));
    xmm1 = intrinsic_movss(xmm1, var_58);
    rax = cocos2d::CCPoint::CCPoint(var_80, xmm0, xmm1);
    rax = (r12)(r13, var_80);
    if (r14 != 0x0) {
            rax = sub_10022dbd0(r13);
    }
    else {
            COND = *(int8_t *)(r13 + 0x776) != 0x0;
            xmm0 = intrinsic_movss(xmm0, var_3C);
            xmm0 = intrinsic_ucomiss(xmm0, *(int32_t *)value 0.5);
            rcx = (xmm0 > 0x0 ? 0x1 : 0x0) | (COND ? 0x1 : 0x0);
            rax = PlayerObject::hitGround(r13, rcx & 0xff, rdx);
    }
    rsi = 0x0;
    rsi = *(int8_t *)(r13 + 0x776) == 0x0 ? 0x1 : 0x0;
    rdx = 0x0;
    rax = PlayerObject::updateCollide(r13, rsi, rdx, rcx);
    xmm0 = intrinsic_movss(xmm0, var_3C);
    xmm0 = intrinsic_ucomiss(xmm0, *(int32_t *)value 0.5);
    r14 = var_30;
    if (xmm0 > 0x0) {
            xmm0 = intrinsic_ucomisd(0x0, *(r13 + 0x760));
            if (xmm0 >= 0x0) {
                    rax = sub_10022dbf0(r13, rsi);
            }
    }
    goto loc_10007929b;

loc_1000791da :
    r14 = 0x0;
    goto loc_1000791dd;

loc_100079106 :
    var_90 = r15;
    r14 = var_30;
    goto loc_1000792a3;

loc_100078d5e :
    xmm0 = intrinsic_movss(xmm0, *(int32_t *)((*(*r13 + 0xc0))(r13) + 0x4));
    xmm1 = intrinsic_movss(xmm1, *(int32_t *)0x10050d418);
    xmm1 = intrinsic_addss(xmm1, var_58);
    xmm0 = intrinsic_ucomiss(xmm0, xmm1);
    if (xmm0 <= 0x0) goto loc_100078e83;
}