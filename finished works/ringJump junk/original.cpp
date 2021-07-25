void _ZN12PlayerObject8ringJumpEPvP10GameObject(int arg0, int arg1) {
    r14 = arg1;
    rbx = arg0;
    if (*(int8_t *)(rbx + 0x777) == 0x0) goto loc_10022ac1b;

loc_10022ac0e:
    rbx = stack[2043];
    r12 = stack[2044];
    r14 = stack[2045];
    r15 = stack[2046];
    rsp = rsp + 0x58;
    rbp = stack[2047];
    return;

loc_10022ac1b:
    if (((*(int8_t *)(rbx + 0x748) == 0x0) || (*(int8_t *)(rbx + 0x779) != 0x0)) || (*(int8_t *)(rbx + 0x747) == 0x0)) goto loc_10022ac0e;

loc_10022ac36:
    if ((*(int8_t *)(rbx + 0x749) != 0x0) || ((*(*r14 + 0x5e8))(r14) == 0x24)) goto loc_10022ac50;

loc_10022ac6a:
    *(int8_t *)(rbx + 0x688) = 0x1;
    if ((*(*r14 + 0x5e8))(r14) == 0x24) {
            *(int8_t *)(rbx + 0x74a) = 0x1;
    }
    else {
            *(int8_t *)(rbx + 0x749) = 0x1;
    }
    rdx = 0x1;
    rax = cocos2d::CCArray::removeObject(*(rbx + 0x7b0), r14, rdx);
    if ((*(*r14 + 0x5e8))(r14) != 0x24) {
            *(int8_t *)(rbx + 0x628) = 0x1;
    }
    if ((*(*r14 + 0x5e8))(r14) != 0x24) goto loc_10022acf1;

loc_10022accf:
    r15 = *(int8_t *)(rbx + 0x279);
    rax = GameManager::sharedState();
    if (r15 != 0x0) {
            rdi = *(rax + 0x188);
    }
    else {
            rdi = *(rax + 0x180);
    }
    rax = GJBaseGameLayer::objectTriggered(rdi, r14);
    *(int8_t *)(rbx + 0x746) = 0x0;
    if (*(int8_t *)(rbx + 0x629) == 0x0) {
            if (((*(int8_t *)(GameManager::sharedState() + 0x2a1) == 0x0) && (loc_100342a80(r14) == 0x0)) && (*(int8_t *)(rbx + 0x62c) != 0x0)) {
                    r15 = 0xffff00;
                    if ((*(*r14 + 0x5e8))(r14) != 0xd) {
                            r15 = 0xff00ff;
                            if ((*(*r14 + 0x5e8))(r14) != 0xc) {
                                    r15 = 0xff00;
                                    if ((*(*r14 + 0x5e8))(r14) != 0x1d) {
                                            if ((((*(*r14 + 0x5e8))(r14) != 0x20) && ((*(*r14 + 0x5e8))(r14) != 0x25)) && ((*(*r14 + 0x5e8))(r14) != 0x26)) {
                                                    r15 = 0x64ff;
                                                    if ((*(*r14 + 0x5e8))(r14) != 0x23) {
                                                            r15 = 0xc8ff;
                                                            if ((*(*r14 + 0x5e8))(r14) == 0x24) {
                                                                    rdi = *(r14 + 0x350);
                                                                    if (rdi != 0x0) {
                                                                            rax = *rdi;
                                                                    }
                                                                    else {
                                                                            rax = *r14;
                                                                            rdi = r14;
                                                                    }
                                                                    rax = (*(rax + 0x388))();
                                                                    rcx = *(int16_t *)rax & 0xffff;
                                                                    r15 = *(int8_t *)(rax + 0x2) & 0xff;
                                                                    r15 = r15 << 0x10 | rcx;
                                                            }
                                                    }
                                            }
                                            else {
                                                    rdi = *(*(GameManager::sharedState() + 0x180) + 0x180);
                                                    rsi = 0x3ef;
                                                    r15 = GJEffectManager::activeColorForIndex();
                                            }
                                    }
                            }
                    }
                    rcx = 0x0;
                    xmm0 = intrinsic_movss(xmm0, *(int32_t *)(0x100511178 + ((*(*r14 + 0x5e8))(r14) == 0x23 ? 0x1 : 0x0) * 0x4));
                    xmm1 = intrinsic_movss(xmm1, *(int32_t *)value 5.0);
                    xmm2 = intrinsic_movss(xmm2, *(int32_t *)0x10050c770);
                    r12 = CCCircleWave::create(0x1);
                    *(int8_t *)(r12 + 0x136) = r15 >> 0x10;
                    *(int16_t *)(r12 + 0x134) = r15;
                    r15 = *(*r12 + 0xb8);
                    rax = *r14;
                    rax = (*(rax + 0xc0))(r14);
                    rax = (r15)(r12, rax);
                    rax = CCCircleWave::followObject(r12, r14, 0x1);
                    rax = GameManager::sharedState();
                    rax = *(rax + 0x180);
                    rcx = rax + 0x4b0;
                    if (rax == 0x0) {
                            rcx = rax;
                    }
                    *(r12 + 0x150) = rcx;
                    rsi = r12;
                    rax = PlayLayer::addCircle(*(GameManager::sharedState() + 0x180));
                    rdi = *(rbx + 0x798);
                    rax = *rdi;
                    rax = (*(rax + 0x1c0))(rdi, r12, 0x0);
            }
    }
    goto loc_10022b5fe;

loc_10022b5fe:
    rax = GameObject::activatedByPlayer(r14, rbx);
    rax = *r14;
    rax = (*(rax + 0x590))(r14);
    if (*(int8_t *)(rbx + 0x62c) != 0x0) {
            rax = PlayLayer::incrementJumps(*(GameManager::sharedState() + 0x180));
            *(int8_t *)(rbx + 0x7c0) = 0x1;
    }
    goto loc_10022ac0e;

loc_10022acf1:
    if ((*(*r14 + 0x5e8))(r14) == 0x25) goto loc_10022af5e;

loc_10022ad06:
    if ((*(*r14 + 0x5e8))(r14) != 0x26) goto loc_10022ad96;

loc_10022ad17:
    r15 = *(int8_t *)(rbx + 0x62c);
    rax = GameManager::sharedState();
    if (r15 != 0x0) {
            rdi = *(rax + 0x180);
            rax = *rdi;
            rdx = 0x0;
            rax = (*(rax + 0x460))(rdi, rbx, *(int8_t *)(rbx + 0x776) == 0x0 ? 0x1 : 0x0, 0x1);
            rax = PlayLayer::playGravityEffect(*(GameManager::sharedState() + 0x180), *(int8_t *)(rbx + 0x776) & 0xff);
    }
    else {
            if (*(rax + 0x188) != 0x0) {
                    rdi = *(GameManager::sharedState() + 0x188);
                    rax = *rdi;
                    rdx = 0x0;
                    rax = (*(rax + 0x460))(rdi, rbx, *(int8_t *)(rbx + 0x776) == 0x0 ? 0x1 : 0x0, 0x1);
            }
            else {
                    rsi = 0x0;
                    rax = PlayerObject::flipGravity(rbx, *(int8_t *)(rbx + 0x776) == 0x0 ? 0x1 : 0x0, 0x1);
            }
    }
    goto loc_10022af5e;

loc_10022af5e:
    rax = sub_100221d70(rbx, r14);
    if (*(int8_t *)(rbx + 0x629) == 0x0) {
            if (((*(int8_t *)(GameManager::sharedState() + 0x2a1) == 0x0) && (loc_100342a80(r14) == 0x0)) && (*(int8_t *)(rbx + 0x62c) != 0x0)) {
                    r15 = 0xffff00;
                    if ((*(*r14 + 0x5e8))(r14) != 0xd) {
                            r15 = 0xff00ff;
                            if ((*(*r14 + 0x5e8))(r14) != 0xc) {
                                    r15 = 0xff00;
                                    if ((*(*r14 + 0x5e8))(r14) != 0x1d) {
                                            if ((((*(*r14 + 0x5e8))(r14) != 0x20) && ((*(*r14 + 0x5e8))(r14) != 0x25)) && ((*(*r14 + 0x5e8))(r14) != 0x26)) {
                                                    r15 = 0x64ff;
                                                    if ((*(*r14 + 0x5e8))(r14) != 0x23) {
                                                            r15 = 0xc8ff;
                                                            if ((*(*r14 + 0x5e8))(r14) == 0x24) {
                                                                    rdi = *(r14 + 0x350);
                                                                    if (rdi != 0x0) {
                                                                            rax = *rdi;
                                                                    }
                                                                    else {
                                                                            rax = *r14;
                                                                            rdi = r14;
                                                                    }
                                                                    rax = (*(rax + 0x388))();
                                                                    rcx = *(int16_t *)rax & 0xffff;
                                                                    r15 = *(int8_t *)(rax + 0x2) & 0xff;
                                                                    r15 = r15 << 0x10 | rcx;
                                                            }
                                                    }
                                            }
                                            else {
                                                    rdi = *(*(GameManager::sharedState() + 0x180) + 0x180);
                                                    rsi = 0x3ef;
                                                    r15 = GJEffectManager::activeColorForIndex();
                                            }
                                    }
                            }
                    }
                    rcx = 0x0;
                    xmm0 = intrinsic_movss(xmm0, *(int32_t *)(0x100511178 + ((*(*r14 + 0x5e8))(r14) == 0x23 ? 0x1 : 0x0) * 0x4));
                    xmm1 = intrinsic_movss(xmm1, *(int32_t *)value 5.0);
                    xmm2 = intrinsic_movss(xmm2, *(int32_t *)0x10050c770);
                    r12 = CCCircleWave::create(0x1);
                    *(int8_t *)(r12 + 0x136) = r15 >> 0x10;
                    *(int16_t *)(r12 + 0x134) = r15;
                    r15 = *(*r12 + 0xb8);
                    rax = *r14;
                    rax = (*(rax + 0xc0))(r14);
                    rax = (r15)(r12, rax);
                    rax = CCCircleWave::followObject(r12, r14, 0x1);
                    rax = GameManager::sharedState();
                    rax = *(rax + 0x180);
                    rcx = rax + 0x4b0;
                    if (rax == 0x0) {
                            rcx = rax;
                    }
                    *(r12 + 0x150) = rcx;
                    rsi = r12;
                    rax = PlayLayer::addCircle(*(GameManager::sharedState() + 0x180));
                    rdi = *(rbx + 0x798);
                    rax = *rdi;
                    rax = (*(rax + 0x1c0))(rdi, r12, 0x0);
            }
    }
    goto loc_10022b5fe;

loc_10022ad96:
    if ((*(*r14 + 0x5e8))(r14) != 0x20) goto loc_10022ae24;

loc_10022ada7:
    *(int8_t *)(rbx + 0x746) = 0x0;
    rax = *(int8_t *)(rbx + 0x771);
    rcx = *(int8_t *)(rbx + 0x776);
    rsi = 0x0;
    rdx = rcx == 0x0 ? 0x1 : 0x0;
    if (*(int8_t *)(rbx + 0x770) != 0x0) goto loc_10022addf;

loc_10022adca:
    rax = 0x1;
    if (0x1 != 0x0) goto loc_10022addf;

loc_10022add0:
    if (*(int8_t *)(rbx + 0x773) == 0x0) goto loc_10022b1b9;

loc_10022addd:
    rax = 0x0;
    goto loc_10022addf;

loc_10022addf:
    rdx = 0x0;
    rdx = rcx == 0x0 ? 0x1 : 0x0;
    xmm0 = intrinsic_movss(xmm0, *(int32_t *)(14 or -14 + rdx * 0x4));
    if (rax != 0x0) {
            xmm0 = intrinsic_mulss(xmm0, *(int32_t *)value 0.8);
    }
    goto loc_10022adfe;

loc_10022adfe:
    xmm0 = intrinsic_cvtss2sd(xmm0, xmm0);
    *(rbx + 0x760) = intrinsic_movsd(*(rbx + 0x760), xmm0);
    if (*(int8_t *)(rbx + 0x772) != 0x0) {
            rax = sub_10021cb10(rbx);
    }
    else {
            rax = PlayerObject::runRotateAction(rbx, 0x0, rdx);
    }
    rax = sub_10021aef0(rbx);
    *(int8_t *)(rbx + 0x7c1) = 0x1;
    *(int8_t *)(rbx + 0x732) = 0x1;
    if (*(int8_t *)(rbx + 0x772) != 0x0) {
            *(int8_t *)(rbx + 0x745) = 0x0;
            if (*(int8_t *)(rbx + 0x629) == 0x0) {
                    if (((*(int8_t *)(GameManager::sharedState() + 0x2a1) == 0x0) && (loc_100342a80(r14) == 0x0)) && (*(int8_t *)(rbx + 0x62c) != 0x0)) {
                            r15 = 0xffff00;
                            if ((*(*r14 + 0x5e8))(r14) != 0xd) {
                                    r15 = 0xff00ff;
                                    if ((*(*r14 + 0x5e8))(r14) != 0xc) {
                                            r15 = 0xff00;
                                            if ((*(*r14 + 0x5e8))(r14) != 0x1d) {
                                                    if ((((*(*r14 + 0x5e8))(r14) != 0x20) && ((*(*r14 + 0x5e8))(r14) != 0x25)) && ((*(*r14 + 0x5e8))(r14) != 0x26)) {
                                                            r15 = 0x64ff;
                                                            if ((*(*r14 + 0x5e8))(r14) != 0x23) {
                                                                    r15 = 0xc8ff;
                                                                    if ((*(*r14 + 0x5e8))(r14) == 0x24) {
                                                                            rdi = *(r14 + 0x350);
                                                                            if (rdi != 0x0) {
                                                                                    rax = *rdi;
                                                                            }
                                                                            else {
                                                                                    rax = *r14;
                                                                                    rdi = r14;
                                                                            }
                                                                            rax = (*(rax + 0x388))();
                                                                            rcx = *(int16_t *)rax & 0xffff;
                                                                            r15 = *(int8_t *)(rax + 0x2) & 0xff;
                                                                            r15 = r15 << 0x10 | rcx;
                                                                    }
                                                            }
                                                    }
                                                    else {
                                                            rdi = *(*(GameManager::sharedState() + 0x180) + 0x180);
                                                            rsi = 0x3ef;
                                                            r15 = GJEffectManager::activeColorForIndex();
                                                    }
                                            }
                                    }
                            }
                            rcx = 0x0;
                            xmm0 = intrinsic_movss(xmm0, *(int32_t *)(0x100511178 + ((*(*r14 + 0x5e8))(r14) == 0x23 ? 0x1 : 0x0) * 0x4));
                            xmm1 = intrinsic_movss(xmm1, *(int32_t *)value 5.0);
                            xmm2 = intrinsic_movss(xmm2, *(int32_t *)0x10050c770);
                            r12 = CCCircleWave::create(0x1);
                            *(int8_t *)(r12 + 0x136) = r15 >> 0x10;
                            *(int16_t *)(r12 + 0x134) = r15;
                            r15 = *(*r12 + 0xb8);
                            rax = *r14;
                            rax = (*(rax + 0xc0))(r14);
                            rax = (r15)(r12, rax);
                            rax = CCCircleWave::followObject(r12, r14, 0x1);
                            rax = GameManager::sharedState();
                            rax = *(rax + 0x180);
                            rcx = rax + 0x4b0;
                            if (rax == 0x0) {
                                    rcx = rax;
                            }
                            *(r12 + 0x150) = rcx;
                            rsi = r12;
                            rax = PlayLayer::addCircle(*(GameManager::sharedState() + 0x180));
                            rdi = *(rbx + 0x798);
                            rax = *rdi;
                            rax = (*(rax + 0x1c0))(rdi, r12, 0x0);
                    }
            }
    }
    else {
            if (*(int8_t *)(rbx + 0x629) == 0x0) {
                    if (((*(int8_t *)(GameManager::sharedState() + 0x2a1) == 0x0) && (loc_100342a80(r14) == 0x0)) && (*(int8_t *)(rbx + 0x62c) != 0x0)) {
                            r15 = 0xffff00;
                            if ((*(*r14 + 0x5e8))(r14) != 0xd) {
                                    r15 = 0xff00ff;
                                    if ((*(*r14 + 0x5e8))(r14) != 0xc) {
                                            r15 = 0xff00;
                                            if ((*(*r14 + 0x5e8))(r14) != 0x1d) {
                                                    if ((((*(*r14 + 0x5e8))(r14) != 0x20) && ((*(*r14 + 0x5e8))(r14) != 0x25)) && ((*(*r14 + 0x5e8))(r14) != 0x26)) {
                                                            r15 = 0x64ff;
                                                            if ((*(*r14 + 0x5e8))(r14) != 0x23) {
                                                                    r15 = 0xc8ff;
                                                                    if ((*(*r14 + 0x5e8))(r14) == 0x24) {
                                                                            rdi = *(r14 + 0x350);
                                                                            if (rdi != 0x0) {
                                                                                    rax = *rdi;
                                                                            }
                                                                            else {
                                                                                    rax = *r14;
                                                                                    rdi = r14;
                                                                            }
                                                                            rax = (*(rax + 0x388))();
                                                                            rcx = *(int16_t *)rax & 0xffff;
                                                                            r15 = *(int8_t *)(rax + 0x2) & 0xff;
                                                                            r15 = r15 << 0x10 | rcx;
                                                                    }
                                                            }
                                                    }
                                                    else {
                                                            rdi = *(*(GameManager::sharedState() + 0x180) + 0x180);
                                                            rsi = 0x3ef;
                                                            r15 = GJEffectManager::activeColorForIndex();
                                                    }
                                            }
                                    }
                            }
                            rcx = 0x0;
                            xmm0 = intrinsic_movss(xmm0, *(int32_t *)(0x100511178 + ((*(*r14 + 0x5e8))(r14) == 0x23 ? 0x1 : 0x0) * 0x4));
                            xmm1 = intrinsic_movss(xmm1, *(int32_t *)value 5.0);
                            xmm2 = intrinsic_movss(xmm2, *(int32_t *)0x10050c770);
                            r12 = CCCircleWave::create(0x1);
                            *(int8_t *)(r12 + 0x136) = r15 >> 0x10;
                            *(int16_t *)(r12 + 0x134) = r15;
                            r15 = *(*r12 + 0xb8);
                            rax = *r14;
                            rax = (*(rax + 0xc0))(r14);
                            rax = (r15)(r12, rax);
                            rax = CCCircleWave::followObject(r12, r14, 0x1);
                            rax = GameManager::sharedState();
                            rax = *(rax + 0x180);
                            rcx = rax + 0x4b0;
                            if (rax == 0x0) {
                                    rcx = rax;
                            }
                            *(r12 + 0x150) = rcx;
                            rsi = r12;
                            rax = PlayLayer::addCircle(*(GameManager::sharedState() + 0x180));
                            rdi = *(rbx + 0x798);
                            rax = *rdi;
                            rax = (*(rax + 0x1c0))(rdi, r12, 0x0);
                    }
            }
    }
    goto loc_10022b5fe;

loc_10022b1b9:
    xmm0 = intrinsic_movss(xmm0, *(int32_t *)(0x100511138 + rdx * 0x4));
    if ((*(int8_t *)(rbx + 0x774) == 0x0) && (*(int8_t *)(rbx + 0x775) != 0x0)) {
            xmm0 = intrinsic_mulss(xmm0, *(int32_t *)value 1.10);
    }
    goto loc_10022adfe;

loc_10022ae24:
    *(int8_t *)(rbx + 0x7a1) = 0x1;
    *(int8_t *)(rbx + 0x7a0) = 0x0;
    *(int8_t *)(rbx + 0x778) = 0x0;
    *(int8_t *)(rbx + 0x746) = 0x0;
    xmm0 = intrinsic_movss(xmm0, *(int32_t *)(rbx + 0x77c));
    asm{ cmpneqss   xmm0, dword [value 1.0] };
    r15 = zero_extend_32(xmm0) & 0x1;
    r12 = 0x10050e370;
    xmm0 = intrinsic_movsd(xmm0, *(rbx + 0x610));
    xmm0 = intrinsic_cvtsd2ss(xmm0, xmm0);
    var_24 = intrinsic_movss(var_24, xmm0);
    if ((*(*r14 + 0x5e8))(r14) != 0xd) goto loc_10022aed1;

loc_10022ae83:
    xmm0 = intrinsic_movss(xmm0, var_24);
    xmm0 = intrinsic_mulss(xmm0, *(int32_t *)value 0.8);
    goto loc_10022b2f9;

loc_10022b2f9:
    var_24 = intrinsic_movss(var_24, xmm0);
    goto loc_10022b2fe;

loc_10022b2fe:
    xmm0 = intrinsic_movss(xmm0, *(int32_t *)(0x10050e370 + r15 * 0x4));
    var_44 = intrinsic_movss(var_44, xmm0);
    if ((*(*r14 + 0x5e8))(r14) == 0x1d) {
            r15 = *(int8_t *)(rbx + 0x62c);
            rax = GameManager::sharedState();
            if (r15 != 0x0) {
                    rdi = *(rax + 0x180);
                    rax = *rdi;
                    rdx = 0x0;
                    rdx = *(int8_t *)(rbx + 0x776) == 0x0 ? 0x1 : 0x0;
                    rax = (*(rax + 0x460))(rdi, rbx, rdx, 0x1);
                    rax = PlayLayer::playGravityEffect(*(GameManager::sharedState() + 0x180), *(int8_t *)(rbx + 0x776) & 0xff);
            }
            else {
                    if (*(rax + 0x188) != 0x0) {
                            rdi = *(GameManager::sharedState() + 0x188);
                            rax = *rdi;
                            rdx = 0x0;
                            rdx = *(int8_t *)(rbx + 0x776) == 0x0 ? 0x1 : 0x0;
                            rax = (*(rax + 0x460))(rdi, rbx, rdx, 0x1);
                    }
                    else {
                            rsi = 0x0;
                            rdx = 0x1;
                            rax = PlayerObject::flipGravity(rbx, *(int8_t *)(rbx + 0x776) == 0x0 ? 0x1 : 0x0, rdx);
                    }
            }
    }
    rax = 0x0;
    COND = *(int8_t *)(rbx + 0x776) == 0x0;
    xmm0 = intrinsic_movss(xmm0, var_24);
    xmm0 = intrinsic_mulss(xmm0, *(int32_t *)(0x10050d470 + (COND ? 0x1 : 0x0) * 0x4));
    xmm1 = intrinsic_movss(xmm1, var_44);
    xmm1 = intrinsic_mulss(xmm1, xmm0);
    xmm0 = intrinsic_cvtss2sd(0x0, xmm1);
    *(rbx + 0x760) = intrinsic_movsd(*(rbx + 0x760), xmm0);
    if (*(int8_t *)(rbx + 0x772) != 0x0) {
            rax = sub_10021cb10(rbx);
    }
    else {
            rax = PlayerObject::runRotateAction(rbx, 0x0, rdx);
    }
    rax = *rbx;
    rax = (*(rax + 0xc0))(rbx);
    rax = cocos2d::CCPoint::operator=(rbx + 0x7a4, rax);
    rax = sub_10021aef0(rbx);
    *(int8_t *)(rbx + 0x7c1) = 0x1;
    if ((*(int8_t *)(rbx + 0x772) != 0x0) || (*(int8_t *)(rbx + 0x775) != 0x0)) {
            xmm0 = intrinsic_movsd(xmm0, *(rbx + 0x760));
            xmm0 = intrinsic_mulsd(xmm0, *0x100511168);
            *(rbx + 0x760) = intrinsic_movsd(*(rbx + 0x760), xmm0);
            *(int8_t *)(rbx + 0x745) = 0x0;
    }
    if ((*(*r14 + 0x5e8))(r14) != 0xd) goto loc_10022b533;

loc_10022b47f:
    r15 = *(int8_t *)(rbx + 0x62c);
    rax = GameManager::sharedState();
    if (r15 == 0x0) goto loc_10022b4db;

loc_10022b491:
    rdi = *(rax + 0x180);
    rax = *rdi;
    rdx = 0x0;
    rax = (*(rax + 0x460))(rdi, rbx, *(int8_t *)(rbx + 0x776) == 0x0 ? 0x1 : 0x0, 0x1);
    rax = PlayLayer::playGravityEffect(*(GameManager::sharedState() + 0x180), *(int8_t *)(rbx + 0x776) & 0xff);
    if (*(int8_t *)(rbx + 0x774) != 0x0) goto loc_10022b53c;

loc_10022b569:
    if (*(int8_t *)(rbx + 0x775) == 0x0) goto loc_10022b5d5;

loc_10022b572:
    rax = CCAnimatedSprite::stopTween(*(rbx + 0x6b0));
    rax = SpriteAnimationManager::stopAnimations(*(*(rbx + 0x6b0) + 0x248));
    r15 = *(rbx + 0x6b0);
    rax = std::basic_string<char, std::char_traits<char>, std::allocator<char> >::basic_string(var_38, "jump", var_30);
    xmm0 = intrinsic_movss(xmm0, *(int32_t *)0x100510ea4);
    rax = CCAnimatedSprite::tweenToAnimation(r15, var_38);
    rax = var_38;
    goto loc_10022b5c4;

loc_10022b5c4:
    if (rax + 0xffffffffffffffe8 != std::string::_Rep::_S_empty_rep_storage) {
            *(int32_t *)(rax + 0xfffffffffffffff8) = lock intrinsic_xadd(*(int32_t *)(rax + 0xfffffffffffffff8), 0xffffffff);
            if (0xffffffff <= 0x0) {
                    rsi = var_28;
                    rax = std::string::_Rep::_M_destroy();
            }
    }
    goto loc_10022b5d5;

loc_10022b5d5:
    if ((*(*r14 + 0x5e8))(r14) == 0x23) {
            *(int8_t *)(rbx + 0x732) = 0x1;
            if (*(int8_t *)(rbx + 0x629) == 0x0) {
                    if (((*(int8_t *)(GameManager::sharedState() + 0x2a1) == 0x0) && (loc_100342a80(r14) == 0x0)) && (*(int8_t *)(rbx + 0x62c) != 0x0)) {
                            r15 = 0xffff00;
                            if ((*(*r14 + 0x5e8))(r14) != 0xd) {
                                    r15 = 0xff00ff;
                                    if ((*(*r14 + 0x5e8))(r14) != 0xc) {
                                            r15 = 0xff00;
                                            if ((*(*r14 + 0x5e8))(r14) != 0x1d) {
                                                    if ((((*(*r14 + 0x5e8))(r14) != 0x20) && ((*(*r14 + 0x5e8))(r14) != 0x25)) && ((*(*r14 + 0x5e8))(r14) != 0x26)) {
                                                            r15 = 0x64ff;
                                                            if ((*(*r14 + 0x5e8))(r14) != 0x23) {
                                                                    r15 = 0xc8ff;
                                                                    if ((*(*r14 + 0x5e8))(r14) == 0x24) {
                                                                            rdi = *(r14 + 0x350);
                                                                            if (rdi != 0x0) {
                                                                                    rax = *rdi;
                                                                            }
                                                                            else {
                                                                                    rax = *r14;
                                                                                    rdi = r14;
                                                                            }
                                                                            rax = (*(rax + 0x388))();
                                                                            rcx = *(int16_t *)rax & 0xffff;
                                                                            r15 = *(int8_t *)(rax + 0x2) & 0xff;
                                                                            r15 = r15 << 0x10 | rcx;
                                                                    }
                                                            }
                                                    }
                                                    else {
                                                            rdi = *(*(GameManager::sharedState() + 0x180) + 0x180);
                                                            rsi = 0x3ef;
                                                            r15 = GJEffectManager::activeColorForIndex();
                                                    }
                                            }
                                    }
                            }
                            rcx = 0x0;
                            xmm0 = intrinsic_movss(xmm0, *(int32_t *)(0x100511178 + ((*(*r14 + 0x5e8))(r14) == 0x23 ? 0x1 : 0x0) * 0x4));
                            xmm1 = intrinsic_movss(xmm1, *(int32_t *)value 5.0);
                            xmm2 = intrinsic_movss(xmm2, *(int32_t *)0x10050c770);
                            r12 = CCCircleWave::create(0x1);
                            *(int8_t *)(r12 + 0x136) = r15 >> 0x10;
                            *(int16_t *)(r12 + 0x134) = r15;
                            r15 = *(*r12 + 0xb8);
                            rax = *r14;
                            rax = (*(rax + 0xc0))(r14);
                            rax = (r15)(r12, rax);
                            rax = CCCircleWave::followObject(r12, r14, 0x1);
                            rax = GameManager::sharedState();
                            rax = *(rax + 0x180);
                            rcx = rax + 0x4b0;
                            if (rax == 0x0) {
                                    rcx = rax;
                            }
                            *(r12 + 0x150) = rcx;
                            rsi = r12;
                            rax = PlayLayer::addCircle(*(GameManager::sharedState() + 0x180));
                            rdi = *(rbx + 0x798);
                            rax = *rdi;
                            rax = (*(rax + 0x1c0))(rdi, r12, 0x0);
                    }
            }
    }
    else {
            if (*(int8_t *)(rbx + 0x629) == 0x0) {
                    if (((*(int8_t *)(GameManager::sharedState() + 0x2a1) == 0x0) && (loc_100342a80(r14) == 0x0)) && (*(int8_t *)(rbx + 0x62c) != 0x0)) {
                            r15 = 0xffff00;
                            if ((*(*r14 + 0x5e8))(r14) != 0xd) {
                                    r15 = 0xff00ff;
                                    if ((*(*r14 + 0x5e8))(r14) != 0xc) {
                                            r15 = 0xff00;
                                            if ((*(*r14 + 0x5e8))(r14) != 0x1d) {
                                                    if ((((*(*r14 + 0x5e8))(r14) != 0x20) && ((*(*r14 + 0x5e8))(r14) != 0x25)) && ((*(*r14 + 0x5e8))(r14) != 0x26)) {
                                                            r15 = 0x64ff;
                                                            if ((*(*r14 + 0x5e8))(r14) != 0x23) {
                                                                    r15 = 0xc8ff;
                                                                    if ((*(*r14 + 0x5e8))(r14) == 0x24) {
                                                                            rdi = *(r14 + 0x350);
                                                                            if (rdi != 0x0) {
                                                                                    rax = *rdi;
                                                                            }
                                                                            else {
                                                                                    rax = *r14;
                                                                                    rdi = r14;
                                                                            }
                                                                            rax = (*(rax + 0x388))();
                                                                            rcx = *(int16_t *)rax & 0xffff;
                                                                            r15 = *(int8_t *)(rax + 0x2) & 0xff;
                                                                            r15 = r15 << 0x10 | rcx;
                                                                    }
                                                            }
                                                    }
                                                    else {
                                                            rdi = *(*(GameManager::sharedState() + 0x180) + 0x180);
                                                            rsi = 0x3ef;
                                                            r15 = GJEffectManager::activeColorForIndex();
                                                    }
                                            }
                                    }
                            }
                            rcx = 0x0;
                            xmm0 = intrinsic_movss(xmm0, *(int32_t *)(0x100511178 + ((*(*r14 + 0x5e8))(r14) == 0x23 ? 0x1 : 0x0) * 0x4));
                            xmm1 = intrinsic_movss(xmm1, *(int32_t *)value 5.0);
                            xmm2 = intrinsic_movss(xmm2, *(int32_t *)0x10050c770);
                            r12 = CCCircleWave::create(0x1);
                            *(int8_t *)(r12 + 0x136) = r15 >> 0x10;
                            *(int16_t *)(r12 + 0x134) = r15;
                            r15 = *(*r12 + 0xb8);
                            rax = *r14;
                            rax = (*(rax + 0xc0))(r14);
                            rax = (r15)(r12, rax);
                            rax = CCCircleWave::followObject(r12, r14, 0x1);
                            rax = GameManager::sharedState();
                            rax = *(rax + 0x180);
                            rcx = rax + 0x4b0;
                            if (rax == 0x0) {
                                    rcx = rax;
                            }
                            *(r12 + 0x150) = rcx;
                            rsi = r12;
                            rax = PlayLayer::addCircle(*(GameManager::sharedState() + 0x180));
                            rdi = *(rbx + 0x798);
                            rax = *rdi;
                            rax = (*(rax + 0x1c0))(rdi, r12, 0x0);
                    }
            }
    }
    goto loc_10022b5fe;

loc_10022b53c:
    r15 = *(rbx + 0x6a8);
    rax = std::basic_string<char, std::char_traits<char>, std::allocator<char> >::basic_string(var_40, "jump_start", var_30);
    rsi = var_40;
    rax = CCAnimatedSprite::runAnimation(r15);
    rax = var_40;
    goto loc_10022b5c4;

loc_10022b4db:
    if (*(rax + 0x188) == 0x0) goto loc_10022b519;

loc_10022b4e5:
    rdi = *(GameManager::sharedState() + 0x188);
    rax = *rdi;
    rdx = 0x0;
    rax = (*(rax + 0x460))(rdi, rbx, *(int8_t *)(rbx + 0x776) == 0x0 ? 0x1 : 0x0, 0x1);
    if (*(int8_t *)(rbx + 0x774) != 0x0) goto loc_10022b53c;
    goto loc_10022b569;

loc_10022b519:
    rsi = 0x0;
    rax = PlayerObject::flipGravity(rbx, *(int8_t *)(rbx + 0x776) == 0x0 ? 0x1 : 0x0, 0x1);
    goto loc_10022b533;

loc_10022b533:
    if (*(int8_t *)(rbx + 0x774) == 0x0) goto loc_10022b569;
    goto loc_10022b53c;

loc_10022aed1:
    if ((*(*r14 + 0x5e8))(r14) != 0x1d) goto loc_10022b119;

loc_10022aee6:
    if (*(int8_t *)(rbx + 0x770) != 0x0) {
            xmm0 = intrinsic_movss(xmm0, var_24);
            xmm0 = intrinsic_mulss(xmm0, *(int32_t *)value 0.70);
    }
    else {
            xmm0 = intrinsic_movss(xmm0, var_24);
    }
    goto loc_10022b2f9;

loc_10022b119:
    if ((*(*r14 + 0x5e8))(r14) != 0xc) goto loc_10022b153;

loc_10022b12a:
    if (*(int8_t *)(rbx + 0x770) != 0x0) {
            xmm0 = intrinsic_movss(xmm0, var_24);
            xmm0 = intrinsic_mulss(xmm0, *(int32_t *)0x100510f24);
    }
    else {
            if (*(int8_t *)(rbx + 0x771) != 0x0) {
                    xmm0 = intrinsic_movss(xmm0, var_24);
                    xmm0 = intrinsic_mulss(xmm0, *(int32_t *)0x10050f184);
            }
            else {
                    if (*(int8_t *)(rbx + 0x772) != 0x0) {
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

loc_10022b153:
    if ((*(*r14 + 0x5e8))(r14) != 0x23) goto loc_10022b19a;

loc_10022b164:
    if (*(int8_t *)(rbx + 0x770) == 0x0) goto loc_10022b20a;

loc_10022b171:
    xmm0 = intrinsic_movss(xmm0, *(int32_t *)(rbx + 0x77c));
    xmm0 = intrinsic_ucomiss(xmm0, *(int32_t *)value 1.0);
    if ((xmm0 != 0x0) || (!CPU_FLAGS & NP)) goto loc_10022b188;
    goto loc_10022b2fe;

loc_10022b188:
    xmm0 = intrinsic_movss(xmm0, var_24);
    xmm0 = intrinsic_mulss(xmm0, *(int32_t *)value 1.4);
    goto loc_10022b2f9;

loc_10022b20a:
    if (*(int8_t *)(rbx + 0x771) != 0x0) {
            xmm0 = intrinsic_movss(xmm0, *(int32_t *)(rbx + 0x77c));
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
            if (*(int8_t *)(rbx + 0x772) != 0x0) {
                    xmm0 = intrinsic_movss(xmm0, var_24);
                    xmm0 = intrinsic_mulss(xmm0, *(int32_t *)0x100510f18);
            }
            else {
                    if (*(int8_t *)(rbx + 0x774) != 0x0) {
                            xmm0 = intrinsic_movss(xmm0, var_24);
                            xmm0 = intrinsic_mulss(xmm0, *(int32_t *)0x100510f1c);
                    }
                    else {
                            if (*(int8_t *)(rbx + 0x775) == 0x0) {
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

loc_10022b19a:
    if (*(int8_t *)(rbx + 0x774) == 0x0) goto loc_10022b2fe;

loc_10022b1a7:
    xmm0 = intrinsic_movss(xmm0, var_24);
    xmm0 = intrinsic_mulss(xmm0, *(int32_t *)value 0.9);
    goto loc_10022b2f9;

loc_10022ac50:
    if ((*(int8_t *)(rbx + 0x74a) != 0x0) || ((*(*r14 + 0x5e8))(r14) != 0x24)) goto loc_10022ac0e;
    goto loc_10022ac6a;

}