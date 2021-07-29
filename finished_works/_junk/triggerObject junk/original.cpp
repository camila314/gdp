int _ZN16EffectGameObject13triggerObjectEP15GJBaseGameLayer(void * arg0, void * arg1) {
    r14 = arg1;
    rbx = arg0;
    if (*(int32_t *)(rbx + 0x370) != 0x1e) goto loc_1000c98ad;

loc_1000c9886 :
    rax = *(int32_t *)(rbx + 0x5b4);
    if (rax == 0x2) {
            rax = *r14;
            rax = *(rax + 0x470);
            rsi = *(int32_t *)(rbx + 0x4f8);
            rdx = *(int8_t *)(rbx + 0x578) & 0xff;
            rdi = r14;
            rbx = stack[2045];
            r14 = stack[2046];
            rsp = rsp + 0x18;
            rbp = stack[2047];
            rax = (rax)(rdi, rsi, rdx);
    } else if (rax == 0x1) {
        rdi = r14;
        rsi = rbx;
        sub_1000b9b60(rdi, rsi);
    }
    return;
loc_1000c98ad :
    rax = *(int32_t *)(rbx + 0x3c4);
    if (rax > 0x392) goto loc_1000c98f1;

loc_1000c98ba :
    if (rax > 0x2e7) goto loc_1000c99fd;

loc_1000c98c5 :
    rax = rax + 0xffffffea;
    if (rax > 0x53) goto loc_1000c9e36;

loc_1000c98d1 :
    rax = sign_extend_64(*(int32_t *)(0x1000c9ff8 + rax * 0x4));
    rax = rax + 0x1000c9ff8;
    goto *0x1000c9ff8[rax];

loc_1000c98e1 :
    *(int32_t *)(r14 + 0x48c) = 0x1;
    goto loc_1000c9fcc;

loc_1000c9fcc :
    rbx = stack[2045];
    r14 = stack[2046];
    rsp = rsp + 0x18;
    rbp = stack[2047];
    return rax;

loc_1000c9d42 :
    *(int32_t *)(r14 + 0x48c) = 0x5;
    goto loc_1000c9fcc;

loc_1000c9d52 :
    *(int32_t *)(r14 + 0x48c) = 0x4;
    goto loc_1000c9fcc;

loc_1000c9d62 :
    *(int32_t *)(r14 + 0x48c) = 0x6;
    goto loc_1000c9fcc;

loc_1000c9d72 :
    *(int32_t *)(r14 + 0x48c) = 0x7;
    goto loc_1000c9fcc;

loc_1000c9d82 :
    *(int32_t *)(r14 + 0x48c) = 0x2;
    goto loc_1000c9fcc;

loc_1000c9d92 :
    *(int32_t *)(r14 + 0x48c) = 0x3;
    goto loc_1000c9fcc;

loc_1000c9a72 :
    r10 = *r14;
    rcx = *(int16_t *)(rbx + 0x4ed) & 0xffff;
    rsi = *(int8_t *)(rbx + 0x4ef) & 0xff;
    rsi = rsi << 0x10 | rcx;
    xmm0 = intrinsic_movss(xmm0, *(int32_t *)(rbx + 0x4f0));
    r11 = *(int32_t *)(rbx + 0x36c);
    rdx = *(int32_t *)(rbx + 0x3bc);
    xmm1 = intrinsic_movss(xmm1, *(int32_t *)(rbx + 0x4f4));
    xmm2 = intrinsic_movsd(xmm2, *(rbx + 0x560));
    r8 = *(rbx + 0x568);
    r9 = *(int32_t *)(rbx + 0x570);
    rcx = *(int8_t *)(rbx + 0x50b) & 0xff;
    stack[2043] = rbx;
    stack[2042] = r11;
    stack[2041] = *(int8_t *)(rbx + 0x574) & 0xff;
    rax = (*(r10 + 0x458))(r14);
    rsp = (rsp - 0x20) + 0x20;
    if ((*(int32_t *)(rbx + 0x3c4) == 0x1d) && (*(int8_t *)(rbx + 0x508) != 0x0)) {
            r10 = *r14;
            rcx = *(int16_t *)(rbx + 0x4ed) & 0xffff;
            rsi = *(int8_t *)(rbx + 0x4ef) & 0xff;
            rsi = rsi << 0x10 | rcx;
            xmm0 = intrinsic_movss(xmm0, *(int32_t *)(rbx + 0x4f0));
            xmm2 = intrinsic_movsd(xmm2, *(rbx + 0x560));
            r8 = *(rbx + 0x568);
            r9 = *(int32_t *)(rbx + 0x570);
            rax = *(int32_t *)(rbx + 0x36c);
            r11 = *(int8_t *)(rbx + 0x574) & 0xff;
            xmm1 = intrinsic_movss(xmm1, *(int32_t *)value 1.0);
            rdx = 0x3e9;
            rcx = 0x0;
            stack[2043] = rbx;
            stack[2042] = rax;
            stack[2041] = r11;
            rax = (*(r10 + 0x458))(r14);
            rsp = (rsp - 0x20) + 0x20;
    }
    goto loc_1000c9fcc;

loc_1000c9e36 :
    rdi = rbx;
    rsi = r14;
    rbx = stack[2045];
    r14 = stack[2046];
    rsp = rsp + 0x18;
    rbp = stack[2047];
    rax = GameObject::triggerObject(rdi, rsi);
    return rax;

loc_1000c9da2 :
    if (*(int8_t *)(rbx + 0x279) != 0x0) goto loc_1000c9fcc;

loc_1000c9daf :
    rdi = *(GameManager::sharedState() + 0x180);
    rsi = 0x1;
    goto loc_1000c9ddd;

loc_1000c9ddd :
    rbx = stack[2045];
    r14 = stack[2046];
    rsp = rsp + 0x18;
    rbp = stack[2047];
    rax = sub_10007fe40(rdi, rsi);
    return rax;

loc_1000c9dc2 :
    if (*(int8_t *)(rbx + 0x279) != 0x0) goto loc_1000c9fcc;

loc_1000c9dcf :
    rdi = *(GameManager::sharedState() + 0x180);
    rsi = 0x0;
    goto loc_1000c9ddd;

loc_1000c9de6 :
    *(int32_t *)(r14 + 0x48c) = 0xa;
    goto loc_1000c9fcc;

loc_1000c9df6 :
    *(int32_t *)(r14 + 0x48c) = 0x9;
    goto loc_1000c9fcc;

loc_1000c9e06 :
    *(int32_t *)(r14 + 0x48c) = 0x8;
    goto loc_1000c9fcc;

loc_1000c9e16 :
    *(int32_t *)(r14 + 0x48c) = 0xb;
    goto loc_1000c9fcc;

loc_1000c9e26 :
    *(int32_t *)(r14 + 0x48c) = 0xc;
    goto loc_1000c9fcc;

loc_1000c99fd :
    if ((rax < 0x385) || (rax == 0x2e8)) goto loc_1000c9a72;

loc_1000c9a0f :
    if (rax == 0x385) {
            rdi = r14;
            rsi = rbx;
            rbx = stack[2045];
            r14 = stack[2046];
            rsp = rsp + 0x18;
            rbp = stack[2047];
            rax = sub_1000b7290(rdi, rsi);
    }
    else {
            rdi = rbx;
            rsi = r14;
            rbx = stack[2045];
            r14 = stack[2046];
            rsp = rsp + 0x18;
            rbp = stack[2047];
            rax = GameObject::triggerObject(rdi, rsi);
    }
    return rax;

loc_1000c98f1 :
    if (rax <= 0x5ef) goto loc_1000c9974;

loc_1000c98f8 :
    rcx = rax + 0xfffffffffffff8ed;
    if (rcx <= 0x8) goto loc_1000c99c0;

loc_1000c9907 :
    rcx = rax + 0xfffffffffffff9cf;
    if (rcx > 0x1f) goto loc_1000c9cd8;

loc_1000c9916 :
    rax = 0x1000ca148;
    goto *0x1000ca148[sign_extend_64(*(int32_t *)(rax + rcx * 0x4)) + rax];

loc_1000c9926 :
    if (*(int8_t *)(rbx + 0x279) == 0x0) {
            rdi = *(GameManager::sharedState() + 0x180);
            rdx = *(int32_t *)(rbx + 0x4f8);
            rsi = *(int32_t *)(rbx + 0x584);
            rbx = stack[2045];
            r14 = stack[2046];
            rsp = rsp + 0x18;
            rbp = stack[2047];
            rax = sub_100075930();
    }
    else {
            rbx = stack[2045];
            r14 = stack[2046];
            rsp = rsp + 0x18;
            rbp = stack[2047];
    }
    return rax;

loc_1000c9f5d :
    rdi = *(r14 + 0x180);
    r9 = *(int32_t *)(rbx + 0x36c);
    rsi = *(int32_t *)(rbx + 0x4f8);
    rcx = *(int32_t *)(rbx + 0x57c);
    r8 = *(int8_t *)(rbx + 0x580) & 0xff;
    rdx = *(int8_t *)(rbx + 0x579) & 0xff;
    rbx = stack[2045];
    r14 = stack[2046];
    rsp = rsp + 0x18;
    rbp = stack[2047];
    rax = sub_100185460(rdi, rsi, rdx, rcx, r8, r9);
    return rax;

loc_1000c9f8f :
    rdi = *(r14 + 0x180);
    rsi = *(int32_t *)(rbx + 0x5b0);
    rdx = *(int32_t *)(rbx + 0x598);
    rax = *(int32_t *)(rbx + 0x36c);
    rsp = rsp - 0x10;
    rax = sub_1001858d0(rdi, rsi, rdx, *(int8_t *)(rbx + 0x5a4) & 0xff, *(int32_t *)(rbx + 0x4f8), *(int8_t *)(rbx + 0x578) & 0xff, rax);
    goto loc_1000c9fc8;

loc_1000c9fc8 :
    rsp = rsp + 0x10;
    goto loc_1000c9fcc;

loc_1000c9fd1 :
    rsi = 0x0;
    goto loc_1000c9fda;

loc_1000c9fda :
    rdi = r14;
    rbx = stack[2045];
    r14 = stack[2046];
    rsp = rsp + 0x18;
    rbp = stack[2047];
    rax = sub_1000ba910(rdi, rsi);
    return rax;

loc_1000c9fd5 :
    rsi = 0x1;
    goto loc_1000c9fda;

loc_1000c9fe6 :
    rsi = *(int32_t *)(rbx + 0x4f8);
    rdi = r14;
    rbx = stack[2045];
    r14 = stack[2046];
    rsp = rsp + 0x18;
    rbp = stack[2047];
    rax = sub_1000b71d0(rdi, rsi);
    return rax;

loc_1000c9cd8 :
    if (rax == 0x5f0) {
            if (*(int8_t *)(rbx + 0x279) == 0x0) {
                    xmm1 = intrinsic_movss(xmm1, *(int32_t *)(rbx + 0x4f0));
                    xmm1 = intrinsic_ucomiss(xmm1, 0x0);
                    if (xmm1 > 0x0) {
                            xmm0 = 0x0;
                            xmm1 = intrinsic_movss(xmm1, *(int32_t *)(rbx + 0x500));
                            xmm1 = intrinsic_ucomiss(xmm1, xmm0);
                            if (xmm1 > 0x0) {
                                    rdi = *(GameManager::sharedState() + 0x180);
                                    xmm0 = intrinsic_movss(xmm0, *(int32_t *)(rbx + 0x4f0));
                                    xmm1 = intrinsic_movss(xmm1, *(int32_t *)(rbx + 0x500));
                                    xmm2 = intrinsic_movss(xmm2, *(int32_t *)(rbx + 0x504));
                                    rbx = stack[2045];
                                    r14 = stack[2046];
                                    rsp = rsp + 0x18;
                                    rbp = stack[2047];
                                    rax = PlayLayer::shakeCamera(rdi);
                            }
                            else {
                                    rbx = stack[2045];
                                    r14 = stack[2046];
                                    rsp = rsp + 0x18;
                                    rbp = stack[2047];
                            }
                    }
                    else {
                            rbx = stack[2045];
                            r14 = stack[2046];
                            rsp = rsp + 0x18;
                            rbp = stack[2047];
                    }
            }
            else {
                    rbx = stack[2045];
                    r14 = stack[2046];
                    rsp = rsp + 0x18;
                    rbp = stack[2047];
            }
    }
    else {
            rdi = rbx;
            rsi = r14;
            rbx = stack[2045];
            r14 = stack[2046];
            rsp = rsp + 0x18;
            rbp = stack[2047];
            rax = GameObject::triggerObject(rdi, rsi);
    }
    return rax;

loc_1000c99c0 :
    rax = 0x1000ca1c8;
    goto *0x1000ca1c8[sign_extend_64(*(int32_t *)(rax + rcx * 0x4)) + rax];

loc_1000c99d0 :
    rsi = *(int32_t *)(rbx + 0x5b0);
    rcx = *(int32_t *)(rbx + 0x4f8);
    rdx = *(int32_t *)(rbx + 0x598);
    r9 = *(int32_t *)(rbx + 0x5a0);
    r8 = *(int8_t *)(rbx + 0x578) & 0xff;
    rdi = r14;
    rbx = stack[2045];
    r14 = stack[2046];
    rsp = rsp + 0x18;
    rbp = stack[2047];
    rax = sub_1000b9ae0(rdi);
    return rax;

loc_1000c9e45 :
    if (*(int8_t *)(rbx + 0x279) == 0x0) {
            rdi = *(*(GameManager::sharedState() + 0x180) + 0x180);
            rcx = *(int32_t *)(rbx + 0x36c);
            rsi = *(int32_t *)(rbx + 0x4f8);
            rdx = *(int8_t *)(rbx + 0x578) & 0xff;
            rbx = stack[2045];
            r14 = stack[2046];
            rsp = rsp + 0x18;
            rbp = stack[2047];
            rax = sub_1001857a0(rdi, rsi, rdx, rcx);
    }
    else {
            rbx = stack[2045];
            r14 = stack[2046];
            rsp = rsp + 0x18;
            rbp = stack[2047];
    }
    return rax;

loc_1000c9e81 :
    rdi = *(r14 + 0x180);
    xmm0 = intrinsic_movss(xmm0, *(int32_t *)(rbx + 0x53c));
    xmm1 = intrinsic_movss(xmm1, *(int32_t *)(rbx + 0x540));
    rsi = *(int32_t *)(rbx + 0x544);
    xmm2 = intrinsic_movss(xmm2, *(int32_t *)(rbx + 0x548));
    xmm3 = intrinsic_movss(xmm3, *(int32_t *)(rbx + 0x4f0));
    rdx = *(int32_t *)(rbx + 0x4f8);
    rcx = *(int32_t *)(rbx + 0x36c);
    rbx = stack[2045];
    r14 = stack[2046];
    rsp = rsp + 0x18;
    rbp = stack[2047];
    rax = sub_100182fe0(rdi, rsi, rdx, rcx);
    return rax;

loc_1000c9ec3 :
    rdi = *(r14 + 0x180);
    rax = *(int32_t *)(rbx + 0x36c);
    rsp = rsp - 0x10;
    rax = sub_100182b70(rdi, *(int32_t *)(rbx + 0x4f8), *(int32_t *)(rbx + 0x5b0), *(int32_t *)(rbx + 0x5a8), *(int8_t *)(rbx + 0x5a5) & 0xff, *(int8_t *)(rbx + 0x578) & 0xff, rax);
    goto loc_1000c9fc8;

loc_1000c9f01 :
    rdx = *(int32_t *)(rbx + 0x598);
    rsi = *(int32_t *)(rbx + 0x5b0);
    rdi = r14;
    rbx = stack[2045];
    r14 = stack[2046];
    rsp = rsp + 0x18;
    rbp = stack[2047];
    rax = sub_1000b9e20(rdi, rsi, rdx);
    return rax;

loc_1000c9f19 :
    if (*(int8_t *)(rbx + 0x279) != 0x0) goto loc_1000c9fcc;

loc_1000c9f26 :
    rdi = *(GameManager::sharedState() + 0x180);
    rsi = 0x1;
    goto loc_1000c9f54;

loc_1000c9f54 :
    rbx = stack[2045];
    r14 = stack[2046];
    rsp = rsp + 0x18;
    rbp = stack[2047];
    rax = sub_10007fe80(rdi, rsi);
    return rax;

loc_1000c9f39 :
    if (*(int8_t *)(rbx + 0x279) != 0x0) goto loc_1000c9fcc;

loc_1000c9f46 :
    rdi = *(GameManager::sharedState() + 0x180);
    rsi = 0x0;
    goto loc_1000c9f54;

loc_1000c9974 :
    if (rax <= 0x418) goto loc_1000c9a29;

loc_1000c997f :
    if (rax > 0x541) goto loc_1000c9b68;

loc_1000c998a :
    if (rax != 0x419) {
            if (rax == 0x4f4) {
                    rdx = *(int32_t *)(rbx + 0x36c);
                    rsi = *(int32_t *)(rbx + 0x4f8);
                    xmm0 = intrinsic_movss(xmm0, *(int32_t *)(rbx + 0x588));
                    rdi = r14;
                    rbx = stack[2045];
                    r14 = stack[2046];
                    rsp = rsp + 0x18;
                    rbp = stack[2047];
                    rax = sub_1000b7020(rdi);
            }
            else {
                    rdi = rbx;
                    rsi = r14;
                    rbx = stack[2045];
                    r14 = stack[2046];
                    rsp = rsp + 0x18;
                    rbp = stack[2047];
                    rax = GameObject::triggerObject(rdi, rsi);
            }
    }
    else {
            rsi = *(int32_t *)(rbx + 0x4f8);
            rdx = *(int8_t *)(rbx + 0x578) & 0xff;
            rdi = r14;
            rbx = stack[2045];
            r14 = stack[2046];
            rsp = rsp + 0x18;
            rbp = stack[2047];
            rax = sub_1000b75f0(rdi, rsi, rdx);
    }
    return rax;

loc_1000c9b68 :
    if (rax == 0x542) goto loc_1000c9c81;

loc_1000c9b73 :
    if (rax == 0x543) {
            *(int8_t *)(rbx + 0x538) = 0x1;
            rdi = *(r14 + 0x180);
            xmm0 = intrinsic_movss(xmm0, *(int32_t *)(rbx + 0x530));
            xmm1 = intrinsic_movss(xmm1, *(int32_t *)(rbx + 0x534));
            xmm2 = intrinsic_movss(xmm2, *(int32_t *)(rbx + 0x4f0));
            rsi = *(int32_t *)(rbx + 0x4f8);
            rdx = *(int32_t *)(rbx + 0x4fc);
            r8 = *(int32_t *)(rbx + 0x36c);
            rbx = stack[2045];
            r14 = stack[2046];
            rsp = rsp + 0x18;
            rbp = stack[2047];
            rax = sub_100182ed0(rdi, rsi, rdx, 0x1, r8);
    }
    else {
            rdi = rbx;
            rsi = r14;
            rbx = stack[2045];
            r14 = stack[2046];
            rsp = rsp + 0x18;
            rbp = stack[2047];
            rax = GameObject::triggerObject(rdi, rsi);
    }
    return rax;

loc_1000c9c81 :
    rdi = *(r14 + 0x180);
    rsi = *(int32_t *)(rbx + 0x528) * 0x168;
    rsi = rsi + *(int32_t *)(rbx + 0x524);
    xmm0 = intrinsic_movss(xmm0, *(int32_t *)(rbx + 0x4f0));
    rdx = *(int32_t *)(rbx + 0x4f8);
    rcx = *(int32_t *)(rbx + 0x4fc);
    r8 = *(int32_t *)(rbx + 0x514);
    xmm1 = intrinsic_movss(xmm1, *(int32_t *)(rbx + 0x518));
    rax = *(int32_t *)(rbx + 0x36c);
    rsp = rsp - 0x10;
    rax = sub_100182df0(rdi, rsi, rdx, rcx, r8, *(int8_t *)(rbx + 0x52c) & 0xff, rax);
    goto loc_1000c9fc8;

loc_1000c9a29 :
    if (rax == 0x393) goto loc_1000c9a72;

loc_1000c9a30 :
    if (rax == 0x3ee) goto loc_1000c9bde;

loc_1000c9a3b :
    if (rax == 0x3ef) {
            rdi = *(r14 + 0x180);
            rsi = *(int32_t *)(rbx + 0x4f8);
            xmm0 = intrinsic_movss(xmm0, *(int32_t *)(rbx + 0x4f0));
            xmm1 = intrinsic_movss(xmm1, *(int32_t *)(rbx + 0x4f4));
            rdx = *(int32_t *)(rbx + 0x36c);
            rbx = stack[2045];
            r14 = stack[2046];
            rsp = rsp + 0x18;
            rbp = stack[2047];
            rax = sub_1001845d0(rdi, rsi, rdx);
    }
    else {
            rdi = rbx;
            rsi = r14;
            rbx = stack[2045];
            r14 = stack[2046];
            rsp = rsp + 0x18;
            rbp = stack[2047];
            rax = GameObject::triggerObject(rdi, rsi);
    }
    return rax;

loc_1000c9bde :
    CMP(*(int32_t *)(rbx + 0x558), 0x1);
    rdi = *(r14 + 0x180);
    r10 = *(int32_t *)(rbx + 0x36c);
    rsi = *(int32_t *)(rbx + 0x4f8);
    rdx = 0x0;
    COND = *(int32_t *)(rbx + 0x55c) == 0x1;
    xmm0 = intrinsic_movss(xmm0, *(int32_t *)(rbx + 0x54c), COND ? 0x1 : 0x0, 0x1 + CARRY(RFLAGS(cf)));
    xmm1 = intrinsic_movss(xmm1, *(int32_t *)(rbx + 0x550));
    xmm2 = intrinsic_movss(xmm2, *(int32_t *)(rbx + 0x554));
    rax = *(int16_t *)(rbx + 0x4ed) & 0xffff;
    r8 = *(int8_t *)(rbx + 0x4ef) & 0xff;
    r8 = r8 << 0x10 | rax;
    xmm3 = intrinsic_movsd(xmm3, *(rbx + 0x560));
    r9 = *(rbx + 0x568);
    r11 = *(int32_t *)(rbx + 0x570);
    r14 = *(int8_t *)(rbx + 0x575) & 0xff;
    rax = *(int8_t *)(rbx + 0x576) & 0xff;
    rax = sub_100184890(rdi, rsi, COND ? 0x1 : 0x0, 0x1 + CARRY(RFLAGS(cf)), r8, r9, r11, r14, rax, *(int8_t *)(rbx + 0x577) & 0xff, r10);
    rsp = (rsp - 0x30) + 0x30;
    goto loc_1000c9fcc;
}