int _ZN12PlayerObject10updateJumpEPvf(int arg0) {
    delta = intrinsic_movss(delta, xmm0);
    r15 = arg0;
    r14 = *(int8_t *)(r15 + 0x778);
    rax = 0x0;
    rbx = 0xd5;
    if (r14 == 0x0) {
            rbx = 0x0;
    }
    *(int32_t *)(r15 + 0x754) = rbx;
    rax = rand();
    xmm0 = intrinsic_cvtsi2ss(0x0, rax);
    xmm0 = intrinsic_mulss(xmm0, *(int32_t *)its 0.0);
    xmm0 = intrinsic_mulss(xmm0, *(int32_t *)value 1000.00);
    rax = intrinsic_cvttss2si(rax, xmm0);
    *(int32_t *)(r15 + 0x750) = rax;
    *(int32_t *)(r15 + 0x74c) = rbx + rax;
    r10 = *(int8_t *)(r15 + 0x778);
    xmm0 = intrinsic_movsd(xmm0, *(r15 + 0x618));
    rdx = *(int8_t *)(r15 + 0x745);
    r9 = *(int8_t *)(r15 + 0x774);
    rax = rdx;
    if (r9 != 0x0) {
            rax = (*(int8_t *)(r15 + 0x746) != 0x0 ? 0x1 : 0x0) & (rdx != 0x0 ? 0x1 : 0x0);
    }
    rcx = *(int8_t *)(r15 + 0x770);
    r8 = *(int8_t *)(r15 + 0x772);
    if (r8 == 0x0) goto loc_10021976c;

loc_10021972a :
    xmm1 = intrinsic_movss(xmm1, *(int32_t *)(r15 + 0x77c));
    asm{ cmpneqss   xmm1, dword [value 1.0] };
    rsi = zero_extend_32(xmm1) & 0x1;
    rdi = 0x1;
    xmm5 = intrinsic_movss(xmm5, *(int32_t *)0x100510eb8);
    if (rcx == 0x0) goto loc_100219813;

loc_100219756 :
    if (rsi == 0x0) {
            xmm6 = intrinsic_movss(xmm6, *(int32_t *)value 1.0);
    }
    else {
            xmm6 = intrinsic_movss(xmm6, *(int32_t *)0x10050d3dc);
    }
    goto loc_100219856;

loc_100219856 :
    xmm2 = intrinsic_movss(xmm2, *(int32_t *)0x10050c764);
    xmm7 = intrinsic_movaps(xmm7, xmm2);
    xmm7 = intrinsic_divss(xmm7, xmm6);
    xmm8 = intrinsic_movss(xmm8, *(int32_t *)0x100510ebc);
    xmm8 = intrinsic_divss(xmm8, xmm6);
    r8 = *(int8_t *)(r15 + 0x776);
    xmm1 = intrinsic_movsd(xmm1, *(r15 + 0x760));
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
                                            *(int8_t *)(r15 + 0x732) = 0x0;
                                    }
                            }
                    }
                    else {
                            *(int8_t *)(r15 + 0x732) = 0x0;
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
                                    *(int8_t *)(r15 + 0x732) = 0x0;
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
                                            *(int8_t *)(r15 + 0x732) = 0x0;
                                    }
                            }
                    }
                    else {
                            *(int8_t *)(r15 + 0x732) = 0x0;
                    }
            }
            else {
                    xmm3 = intrinsic_ucomisd(xmm3, xmm1);
                    if (xmm3 >= 0x0) {
                            xmm3 = intrinsic_cvtss2sd(0x0, xmm8);
                            xmm1 = intrinsic_ucomisd(xmm1, xmm3);
                            if (xmm1 > 0x0) {
                                    *(int8_t *)(r15 + 0x732) = 0x0;
                            }
                    }
            }
    }
    if (rdi == 0x0) goto loc_100219921;

loc_1002198f4 :
    rax = *(int8_t *)(r15 + 0x732);
    if (rdx == 0x0) goto loc_1002199ab;

loc_100219903 :
    if (rax != 0x0) goto loc_1002199b3;

loc_10021990b :
    xmm2 = intrinsic_movss(xmm2, *(int32_t *)value -1.00);
    if (r8 == 0x0) {
            if (*(int8_t *)(r15 + 0x7d1) != 0x0) {
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
    goto loc_100219a22;

loc_100219a22 :
    if ((COND_BYTE_SET(G)) != 0x0) {
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
    *(r15 + 0x760) = intrinsic_movsd(*(r15 + 0x760), xmm1);
    if (rdx != 0x0) {
            *(int8_t *)(r15 + 0x7a0) = 0x0;
            if (*(int8_t *)(r15 + 0x732) == 0x0) {
                    if (*(int8_t *)(r15 + 0x773) == 0x0) {
                            if (r8 != 0x0) {
                                    xmm0 = intrinsic_movss(xmm0, *(int32_t *)value -8);
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
                            *(r15 + 0x760) = intrinsic_movsd(*(r15 + 0x760), intrinsic_minsd(xmm1, xmm0));
                    }
            }
    }
    else {
            if (*(int8_t *)(r15 + 0x732) == 0x0) {
                    if (*(int8_t *)(r15 + 0x773) == 0x0) {
                            if (r8 != 0x0) {
                                    xmm0 = intrinsic_movss(xmm0, *(int32_t *)value -8);
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
                            *(r15 + 0x760) = intrinsic_movsd(*(r15 + 0x760), intrinsic_minsd(xmm1, xmm0));
                    }
            }
    }
    goto loc_100219da5;

loc_100219da5 :
    rbx = stack[2044];
    r14 = stack[2045];
    r15 = stack[2046];
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
            if (*(int8_t *)(r15 + 0x7d1) != 0x0) {
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
            if (*(int8_t *)(r15 + 0x7d1) != 0x0) {
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
            if (*(int8_t *)(r15 + 0x7d1) != 0x0) {
                    xmm0 = intrinsic_xorpd(xmm0, *(int128_t *)0x10050e430);
            }
            xmm0 = intrinsic_cvtsd2ss(xmm0, xmm0);
            xmm0 = intrinsic_addss(xmm0, xmm0);
            xmm0 = intrinsic_cvtss2sd(xmm0, xmm0);
            xmm0 = intrinsic_ucomisd(xmm0, xmm1);
    }
    goto loc_100219ad2;

loc_100219921 :
    if (*(int8_t *)(r15 + 0x771) != 0x0) {
            if ((*(int8_t *)(r15 + 0x746) != 0x0) && (rdx != 0x0)) {
                    if (rsi == 0x0) {
                            xmm2 = intrinsic_movss(xmm2, *(int32_t *)0x10050ca5c);
                    }
                    r14 = r15 + 0x760;
                    rax = 0x0;
                    *(int8_t *)(r15 + 0x746) = 0x0;
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
                                    *(r15 + 0x760) = intrinsic_movsd(*(r15 + 0x760), xmm0);
                                    if ((*(int8_t *)(r15 + 0x769) != 0x0) || (*(int8_t *)(r15 + 0x768) != 0x0)) {
                                            xmm1 = intrinsic_movss(xmm1, *(int32_t *)(r15 + 0x76c));
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
                                    *(r15 + 0x760) = intrinsic_movsd(*(r15 + 0x760), xmm0);
                                    if ((*(int8_t *)(r15 + 0x769) != 0x0) || (*(int8_t *)(r15 + 0x768) != 0x0)) {
                                            xmm1 = intrinsic_movss(xmm1, *(int32_t *)(r15 + 0x76c));
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
                    rax = sub_10021c780(r15);
                    xmm0 = intrinsic_movsd(xmm0, *(r15 + 0x618));
                    r8 = *(int8_t *)(r15 + 0x776);
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
                    if (*(int8_t *)(r15 + 0x7d1) != 0x0) {
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
            xmm1 = intrinsic_addsd(xmm1, *(r15 + 0x760));
            *(r15 + 0x760) = intrinsic_movsd(*(r15 + 0x760), xmm1);
            if (*(int8_t *)(r15 + 0x745) != 0x0) {
                    *(int8_t *)(r15 + 0x7a0) = 0x0;
            }
            if (*(int8_t *)(r15 + 0x732) == 0x0) {
                    if (*(int8_t *)(r15 + 0x773) == 0x0) {
                            if (r8 != 0x0) {
                                    xmm0 = intrinsic_movss(xmm0, *(int32_t *)value -8);
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
                            *(r15 + 0x760) = intrinsic_movsd(*(r15 + 0x760), intrinsic_minsd(xmm1, xmm0));
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
            xmm1 = intrinsic_movss(xmm1, *(int32_t *)(r15 + 0x780));
            xmm1 = intrinsic_cvtss2sd(xmm1, xmm1);
            xmm1 = intrinsic_mulsd(xmm1, *(r15 + 0x608));
            xmm1 = intrinsic_mulsd(xmm1, xmm3);
            if (rdx == 0x0) {
                    xmm0 = intrinsic_movapd(xmm0, xmm2);
            }
            xmm1 = intrinsic_mulsd(xmm1, xmm0);
            *(r15 + 0x760) = intrinsic_movsd(*(r15 + 0x760), xmm1);
            if (*(int8_t *)(r15 + 0x732) == 0x0) {
                    if (*(int8_t *)(r15 + 0x773) == 0x0) {
                            if (r8 != 0x0) {
                                    xmm0 = intrinsic_movss(xmm0, *(int32_t *)value -8);
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
                            *(r15 + 0x760) = intrinsic_movsd(*(r15 + 0x760), intrinsic_minsd(xmm1, xmm0));
                    }
            }
    }
    goto loc_100219da5;

loc_100219813 :
    xmm1 = zero_extend_32(*(int32_t *)(0x10050e370 + rsi * 0x4));
    if (*(int8_t *)(r15 + 0x771) == 0x0) goto loc_100219835;

loc_100219829 :
    rdi = 0x0;
    if (rsi == 0x0) {
            xmm6 = intrinsic_movss(xmm6, *(int32_t *)value 1.0);
    }
    else {
            xmm6 = intrinsic_movss(xmm6, *(int32_t *)0x10050d3dc);
    }
    goto loc_100219856;

loc_100219835 :
    if (*(int8_t *)(r15 + 0x773) == 0x0) goto loc_100219b45;

loc_100219843 :
    rdi = 0x0;
    if (rsi != 0x0) {
            xmm6 = intrinsic_movss(xmm6, *(int32_t *)0x10050d3dc);
    }
    else {
            xmm6 = intrinsic_movss(xmm6, *(int32_t *)value 1.0);
    }
    goto loc_100219856;

loc_100219b45 :
    if (r8 != 0x0) goto loc_100219b61;

loc_100219b4a :
    rcx = 0x0;
    rsi = r9 == 0x0 ? 0x1 : 0x0;
    if (*(int8_t *)(r15 + 0x775) == 0x0) goto loc_100219e2c;

loc_100219b61 :
    xmm2 = intrinsic_movss(xmm2, *(int32_t *)value 0.60);
    if (rax == 0x0) goto loc_100219b98;

loc_100219b6d :
    if (r10 == 0x0) goto loc_100219b98;

loc_100219b72 :
    if ((*(int8_t *)(r15 + 0x775) == 0x0) || (*(int8_t *)(r15 + 0x779) != 0x0)) goto loc_100219b8a;

loc_100219fc7 :
    rdi = r15;
    rbx = stack[2044];
    r14 = stack[2045];
    r15 = stack[2046];
    rsp = rsp + 0x98;
    rbp = stack[2047];
    rax = PlayerObject::spiderTestJump(rdi, 0x0);
    return rax;

loc_100219b8a :
    if (*(int8_t *)(r15 + 0x779) == 0x0) goto loc_100219ec9;

loc_100219b98 :
    if (*(int8_t *)(r15 + 0x7a1) == 0x0) goto loc_100219dfd;

loc_100219ba6 :
    if (((r9 == 0x0) || (rdx == 0x0)) || (*(int8_t *)(r15 + 0x758) != 0x0)) goto loc_100219db0;

loc_100219bc5 :
    xmm1 = intrinsic_movss(xmm1, *(int32_t *)(r15 + 0x674));
    xmm3 = intrinsic_movss(xmm3, *(int32_t *)value 1.5);
    xmm3 = intrinsic_ucomiss(xmm3, xmm1);
    if (xmm3 <= 0x0) goto loc_100219db0;

loc_100219bdf :
    *(int32_t *)(r15 + 0x674) = intrinsic_movss(*(int32_t *)(r15 + 0x674), intrinsic_addss(intrinsic_mulss(intrinsic_movss(xmm2, delta), *(int32_t *)value 0.10), xmm1));
    rax = *(int8_t *)(r15 + 0x776);
    xmm1 = intrinsic_movsd(xmm1, *(r15 + 0x760));
    if (rax != 0x0) goto loc_100219df1;

loc_100219e48 :
    if (*(int8_t *)(r15 + 0x7d1) != 0x0) {
            xmm0 = intrinsic_xorpd(xmm0, *(int128_t *)0x10050e430);
    }
    xmm0 = intrinsic_cvtsd2ss(xmm0, xmm0);
    xmm0 = intrinsic_addss(xmm0, xmm0);
    xmm0 = intrinsic_cvtss2sd(xmm0, xmm0);
    xmm0 = intrinsic_ucomisd(xmm0, xmm1);
    if (xmm0 <= 0x0) goto loc_100219da5;

loc_100219e70 :
    *(int8_t *)(r15 + 0x7a1) = 0x0;
    *(int8_t *)(r15 + 0x62a) = 0x1;
    *(int8_t *)(r15 + 0x7a0) = 0x0;
    if (r9 == 0x0) goto loc_10021a195;

loc_100219e91 :
    rbx = *(r15 + 0x6a8);
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
    goto loc_100219da5;

loc_10021a195 :
    if (*(int8_t *)(r15 + 0x775) == 0x0) goto loc_100219da5;

loc_10021a1a3 :
    rbx = *(r15 + 0x6b0);
    rax = std::basic_string<char, std::char_traits<char>, std::allocator<char> >::basic_string(var_50, "fall_loop", var_20);
    xmm0 = intrinsic_movss(xmm0, *(int32_t *)value 0.10);
    rax = CCAnimatedSprite::tweenToAnimation(rbx, var_50);
    rax = var_50;
    goto loc_10021a382;

loc_100219df1 :
    xmm0 = intrinsic_addsd(xmm0, xmm0);
    xmm1 = intrinsic_ucomisd(xmm1, xmm0);
    if (xmm1 <= 0x0) goto loc_100219da5;
    goto loc_100219e70;

loc_100219db0 :
    xmm5 = intrinsic_mulss(xmm5, delta);
    rax = *(int8_t *)(r15 + 0x776);
    rcx = 0x0;
    xmm2 = intrinsic_mulss(xmm2, intrinsic_mulss(xmm5, *(int32_t *)(0x10050d470 + (rax == 0x0 ? 0x1 : 0x0) * 0x4)));
    xmm2 = intrinsic_cvtss2sd(xmm2, xmm2);
    xmm1 = intrinsic_movsd(xmm1, *(r15 + 0x760));
    xmm1 = intrinsic_subsd(xmm1, xmm2);
    *(r15 + 0x760) = intrinsic_movsd(*(r15 + 0x760), xmm1);
    if (rax == 0x0) goto loc_100219e48;
    goto loc_100219df1;

loc_100219dfd :
    rax = *(int8_t *)(r15 + 0x776);
    xmm1 = intrinsic_movsd(xmm1, *(r15 + 0x760));
    if (rax != 0x0) {
            xmm3 = intrinsic_movapd(xmm3, xmm0);
            xmm3 = intrinsic_addsd(xmm3, xmm3);
            xmm1 = intrinsic_ucomisd(xmm1, xmm3);
            if (xmm1 > 0x0) {
                    *(int8_t *)(r15 + 0x778) = 0x0;
            }
    }
    else {
            COND = *(int8_t *)(r15 + 0x7d1) == 0x0;
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
                    *(int8_t *)(r15 + 0x778) = 0x0;
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
            *(r15 + 0x760) = intrinsic_movsd(*(r15 + 0x760), xmm2);
            if (!CPU_FLAGS & NE) {
                    if (*(int8_t *)(r15 + 0x7d1) != 0x0) {
                            xmm0 = intrinsic_xorpd(xmm0, *(int128_t *)0x10050e430);
                    }
                    xmm0 = intrinsic_cvtsd2ss(xmm0, xmm0);
                    xmm0 = intrinsic_addss(xmm0, xmm0);
                    xmm0 = intrinsic_cvtss2sd(xmm0, xmm0);
                    xmm0 = intrinsic_ucomisd(xmm0, xmm2);
                    if (xmm0 > 0x0) {
                            if (r8 == 0x0) {
                                    rax = r9 != 0x0 ? 0x1 : 0x0;
                                    if (((((*(int8_t *)(r15 + 0x775) == 0x0) && (rax == 0x0)) && (PlayerObject::fadeOutStreak2(r15, 0x0) == 0x0)) && (*(int8_t *)(r15 + 0x768) == 0x0)) && (*(int8_t *)(r15 + 0x554) == 0x0)) {
                                            rax = PlayerObject::runRotateAction(r15, 0x1, rdx);
                                    }
                            }
                            xmm0 = intrinsic_movsd(xmm0, *(r15 + 0x760));
                            xmm0 = intrinsic_ucomisd(xmm0, *0x100510160);
                            rax = xmm0 > 0x0 ? 0x1 : 0x0;
                            xmm1 = intrinsic_movsd(xmm1, *0x1005110a0);
                            xmm1 = intrinsic_ucomisd(xmm1, xmm0);
                            rcx = xmm1 > 0x0 ? 0x1 : 0x0;
                            if (*(int8_t *)(r15 + 0x776) != 0x0) {
                                    rcx = rax;
                            }
                            if (rcx == 0x1) {
                                    if (((*(int8_t *)(r15 + 0x774) != 0x0) && (*(int8_t *)(r15 + 0x7a0) != 0x0)) && (*(int8_t *)(r15 + 0x6b8) == 0x0)) {
                                            r14 = *(r15 + 0x6a8);
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
                                            r14 = r15 + 0x7a0;
                                            *(int8_t *)r14 = 0x0;
                                    }
                                    else {
                                            r14 = r15 + 0x7a0;
                                            if (((*(int8_t *)(r15 + 0x775) != 0x0) && (*(int8_t *)r14 != 0x0)) && (*(int8_t *)(r15 + 0x6b8) == 0x0)) {
                                                    rbx = *(r15 + 0x6b0);
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
                                    rax = r9 != 0x0 ? 0x1 : 0x0;
                                    if (((((*(int8_t *)(r15 + 0x775) == 0x0) && (rax == 0x0)) && (PlayerObject::fadeOutStreak2(r15, 0x0) == 0x0)) && (*(int8_t *)(r15 + 0x768) == 0x0)) && (*(int8_t *)(r15 + 0x554) == 0x0)) {
                                            rax = PlayerObject::runRotateAction(r15, 0x1, rdx);
                                    }
                            }
                            xmm0 = intrinsic_movsd(xmm0, *(r15 + 0x760));
                            xmm0 = intrinsic_ucomisd(xmm0, *0x100510160);
                            rax = xmm0 > 0x0 ? 0x1 : 0x0;
                            xmm1 = intrinsic_movsd(xmm1, *0x1005110a0);
                            xmm1 = intrinsic_ucomisd(xmm1, xmm0);
                            rcx = xmm1 > 0x0 ? 0x1 : 0x0;
                            if (*(int8_t *)(r15 + 0x776) != 0x0) {
                                    rcx = rax;
                            }
                            if (rcx == 0x1) {
                                    if (((*(int8_t *)(r15 + 0x774) != 0x0) && (*(int8_t *)(r15 + 0x7a0) != 0x0)) && (*(int8_t *)(r15 + 0x6b8) == 0x0)) {
                                            r14 = *(r15 + 0x6a8);
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
                                            r14 = r15 + 0x7a0;
                                            *(int8_t *)r14 = 0x0;
                                    }
                                    else {
                                            r14 = r15 + 0x7a0;
                                            if (((*(int8_t *)(r15 + 0x775) != 0x0) && (*(int8_t *)r14 != 0x0)) && (*(int8_t *)(r15 + 0x6b8) == 0x0)) {
                                                    rbx = *(r15 + 0x6b0);
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
            *(r15 + 0x760) = intrinsic_movsd(*(r15 + 0x760), xmm2);
            if (!CPU_FLAGS & E) {
                    xmm0 = intrinsic_addsd(xmm0, xmm0);
                    xmm2 = intrinsic_ucomisd(xmm2, xmm0);
                    if (xmm2 > 0x0) {
                            if (r8 == 0x0) {
                                    rax = r9 != 0x0 ? 0x1 : 0x0;
                                    if (((((*(int8_t *)(r15 + 0x775) == 0x0) && (rax == 0x0)) && (PlayerObject::fadeOutStreak2(r15, 0x0) == 0x0)) && (*(int8_t *)(r15 + 0x768) == 0x0)) && (*(int8_t *)(r15 + 0x554) == 0x0)) {
                                            rax = PlayerObject::runRotateAction(r15, 0x1, rdx);
                                    }
                            }
                            xmm0 = intrinsic_movsd(xmm0, *(r15 + 0x760));
                            xmm0 = intrinsic_ucomisd(xmm0, *0x100510160);
                            rax = xmm0 > 0x0 ? 0x1 : 0x0;
                            xmm1 = intrinsic_movsd(xmm1, *0x1005110a0);
                            xmm1 = intrinsic_ucomisd(xmm1, xmm0);
                            rcx = xmm1 > 0x0 ? 0x1 : 0x0;
                            if (*(int8_t *)(r15 + 0x776) != 0x0) {
                                    rcx = rax;
                            }
                            if (rcx == 0x1) {
                                    if (((*(int8_t *)(r15 + 0x774) != 0x0) && (*(int8_t *)(r15 + 0x7a0) != 0x0)) && (*(int8_t *)(r15 + 0x6b8) == 0x0)) {
                                            r14 = *(r15 + 0x6a8);
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
                                            r14 = r15 + 0x7a0;
                                            *(int8_t *)r14 = 0x0;
                                    }
                                    else {
                                            r14 = r15 + 0x7a0;
                                            if (((*(int8_t *)(r15 + 0x775) != 0x0) && (*(int8_t *)r14 != 0x0)) && (*(int8_t *)(r15 + 0x6b8) == 0x0)) {
                                                    rbx = *(r15 + 0x6b0);
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
                    if (*(int8_t *)(r15 + 0x7d1) != 0x0) {
                            xmm0 = intrinsic_xorpd(xmm0, *(int128_t *)0x10050e430);
                    }
                    xmm0 = intrinsic_cvtsd2ss(xmm0, xmm0);
                    xmm0 = intrinsic_addss(xmm0, xmm0);
                    xmm0 = intrinsic_cvtss2sd(xmm0, xmm0);
                    xmm0 = intrinsic_ucomisd(xmm0, xmm2);
                    if (xmm0 > 0x0) {
                            if (r8 == 0x0) {
                                    rax = r9 != 0x0 ? 0x1 : 0x0;
                                    if (((((*(int8_t *)(r15 + 0x775) == 0x0) && (rax == 0x0)) && (PlayerObject::fadeOutStreak2(r15, 0x0) == 0x0)) && (*(int8_t *)(r15 + 0x768) == 0x0)) && (*(int8_t *)(r15 + 0x554) == 0x0)) {
                                            rax = PlayerObject::runRotateAction(r15, 0x1, rdx);
                                    }
                            }
                            xmm0 = intrinsic_movsd(xmm0, *(r15 + 0x760));
                            xmm0 = intrinsic_ucomisd(xmm0, *0x100510160);
                            rax = xmm0 > 0x0 ? 0x1 : 0x0;
                            xmm1 = intrinsic_movsd(xmm1, *0x1005110a0);
                            xmm1 = intrinsic_ucomisd(xmm1, xmm0);
                            rcx = xmm1 > 0x0 ? 0x1 : 0x0;
                            if (*(int8_t *)(r15 + 0x776) != 0x0) {
                                    rcx = rax;
                            }
                            if (rcx == 0x1) {
                                    if (((*(int8_t *)(r15 + 0x774) != 0x0) && (*(int8_t *)(r15 + 0x7a0) != 0x0)) && (*(int8_t *)(r15 + 0x6b8) == 0x0)) {
                                            r14 = *(r15 + 0x6a8);
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
                                            r14 = r15 + 0x7a0;
                                            *(int8_t *)r14 = 0x0;
                                    }
                                    else {
                                            r14 = r15 + 0x7a0;
                                            if (((*(int8_t *)(r15 + 0x775) != 0x0) && (*(int8_t *)r14 != 0x0)) && (*(int8_t *)(r15 + 0x6b8) == 0x0)) {
                                                    rbx = *(r15 + 0x6b0);
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
    goto loc_100219da5;

loc_100219ec9 :
    *(int8_t *)(r15 + 0x7a1) = 0x1;
    *(int8_t *)(r15 + 0x7a0) = 0x0;
    *(int8_t *)(r15 + 0x778) = 0x0;
    *(int8_t *)(r15 + 0x746) = 0x0;
    *(int8_t *)(r15 + 0x758) = 0x0;
    *(int32_t *)(r15 + 0x674) = 0x0;
    xmm0 = intrinsic_movsd(xmm0, *(r15 + 0x610));
    xmm0 = intrinsic_cvtsd2ss(xmm0, xmm0);
    if (r9 != 0x0) {
            xmm0 = intrinsic_mulss(xmm0, *(int32_t *)value 0.5);
    }
    if (r14 == 0x0) {
            *(int8_t *)(r15 + 0x732) = 0x1;
            xmm0 = intrinsic_movss(xmm0, *(int32_t *)value 1/32);
    }
    rax = *(int8_t *)(r15 + 0x776);
    rcx = 0x0;
    xmm3 = intrinsic_movss(xmm3, *(int32_t *)(0x10050d470 + (rax == 0x0 ? 0x1 : 0x0) * 0x4));
    xmm1 = intrinsic_mulss(xmm1, intrinsic_mulss(xmm0, xmm3));
    xmm0 = intrinsic_cvtss2sd(0x0, xmm1);
    *(r15 + 0x760) = intrinsic_movsd(*(r15 + 0x760), xmm0);
    if ((*(int8_t *)(r15 + 0x769) != 0x0) || (*(int8_t *)(r15 + 0x768) != 0x0)) {
            xmm2 = intrinsic_movss(xmm2, *(int32_t *)(r15 + 0x76c));
            xmm3 = intrinsic_mulss(xmm3, xmm2);
            xmm4 = 0x0;
            xmm3 = intrinsic_ucomiss(xmm3, xmm4);
            if (xmm3 > 0x0) {
                    xmm3 = intrinsic_movsd(xmm3, *(r15 + 0x7d8));
                    xmm3 = intrinsic_subsd(xmm3, *(r15 + 0x500));
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
                    *(r15 + 0x760) = intrinsic_movsd(*(r15 + 0x760), xmm1);
            }
    }
    *(int8_t *)(r15 + 0x62b) = 0x1;
    rax = ftime(var_38);
    rax = (0xfffff & var_38) * 0x3e8;
    xmm0 = intrinsic_cvtsi2sd(0x0, (var_30 & 0xffff) + rax);
    xmm0 = intrinsic_divsd(xmm0, *0x10050c940);
    *(r15 + 0x640) = intrinsic_movsd(*(r15 + 0x640), xmm0);
    if (*(int8_t *)(r15 + 0x62c) != 0x0) {
            rax = PlayLayer::incrementJumps(*(GameManager::sharedState() + 0x180));
            *(int8_t *)(r15 + 0x7c0) = 0x1;
    }
    if (*(int8_t *)(r15 + 0x772) == 0x0) goto loc_10021a345;

loc_10021a2f1 :
    rsi = 0x0;
    rax = PlayerObject::flipGravity(r15, *(int8_t *)(r15 + 0x776) == 0x0 ? 0x1 : 0x0, 0x1);
    xmm0 = intrinsic_movsd(xmm0, *(r15 + 0x760));
    xmm0 = intrinsic_mulsd(xmm0, *0x100511088);
    *(r15 + 0x760) = intrinsic_movsd(*(r15 + 0x760), xmm0);
    *(int8_t *)(r15 + 0x62f) = 0x0;
    *(int8_t *)(r15 + 0x745) = 0x0;
    goto loc_10021a336;

loc_10021a336 :
    if (*(int8_t *)(r15 + 0x774) != 0x0) goto loc_10021a34f;
    goto loc_100219da5;

loc_10021a34f :
    rbx = *(r15 + 0x6a8);
    rax = std::basic_string<char, std::char_traits<char>, std::allocator<char> >::basic_string(var_60, "jump_loop", var_20);
    xmm0 = intrinsic_movss(xmm0, *(int32_t *)value 0.10);
    rax = CCAnimatedSprite::tweenToAnimation(rbx, var_60);
    rax = var_60;
    goto loc_10021a382;

loc_10021a345 :
    if (*(int8_t *)(r15 + 0x774) == 0x0) goto loc_10021a3b3;
    goto loc_10021a34f;

loc_10021a3b3 :
    if (*(int8_t *)(r15 + 0x775) != 0x0) goto loc_10021a336;

loc_10021a3c1 :
    rax = PlayerObject::runRotateAction(r15, 0x1, 0x10050d470);
    if (*(int8_t *)(r15 + 0x774) != 0x0) goto loc_10021a34f;
    goto loc_100219da5;

loc_100219e2c :
    xmm2 = intrinsic_movss(xmm2, *(int32_t *)(0x100511068 + rsi * 0x4));
    if (rax != 0x0) goto loc_100219b6d;
    goto loc_100219b98;

loc_10021976c :
    if (rcx == 0x0) goto loc_10021979f;

loc_100219770 :
    xmm1 = intrinsic_movss(xmm1, *(int32_t *)(r15 + 0x77c));
    asm{ cmpneqss   xmm1, dword [value 1.0] };
    rsi = zero_extend_32(xmm1) & 0x1;
    rdi = 0x1;
    xmm5 = intrinsic_movss(xmm5, *(int32_t *)0x100510eb8);
    if (rsi == 0x0) {
            xmm6 = intrinsic_movss(xmm6, *(int32_t *)value 1.0);
    }
    else {
            xmm6 = intrinsic_movss(xmm6, *(int32_t *)0x10050d3dc);
    }
    goto loc_100219856;

loc_10021979f :
    if (((*(int8_t *)(r15 + 0x771) != 0x0) || (*(int8_t *)(r15 + 0x773) != 0x0)) || (*(int8_t *)(r15 + 0x775) != 0x0)) goto loc_1002197bd;

loc_1002197f6 :
    xmm5 = intrinsic_cvtsd2ss(xmm5, xmm0);
    xmm1 = intrinsic_movss(xmm1, *(int32_t *)(r15 + 0x77c));
    asm{ cmpneqss   xmm1, dword [value 1.0] };
    rsi = zero_extend_32(xmm1) & 0x1;
    goto loc_100219813;

loc_1002197bd :
    xmm1 = intrinsic_movss(xmm1, *(int32_t *)(r15 + 0x77c));
    asm{ cmpneqss   xmm1, dword [value 1.0] };
    rsi = zero_extend_32(xmm1) & 0x1;
    xmm1 = zero_extend_32(*(int32_t *)(0x10050e370 + rsi * 0x4));
    xmm5 = intrinsic_movss(xmm5, *(int32_t *)0x100510eb8);
    if (*(int8_t *)(r15 + 0x771) != 0x0) goto loc_100219829;
}