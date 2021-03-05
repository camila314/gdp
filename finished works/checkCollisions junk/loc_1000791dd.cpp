                        //loc_1000791dd
                        var_90 = r15;
                        xmm0 = intrinsic_movss(xmm0, var_3C);
                        xmm0 = intrinsic_subss(xmm0, var_48);
                        var_3C = intrinsic_movss(var_3C, xmm0);
                        rax = *player;
                        r12 = *(rax + 0xb8);
                        xmm0 = intrinsic_movss(xmm0, *(int32_t *)(*(rax + 0xc0))(player));
                        xmm1 = intrinsic_movss(xmm1, var_58);
                        rax = cocos2d::CCPoint::CCPoint(var_80, xmm0, xmm1);
                        rax = (r12)(player, var_80);
                        if (this != 0x0) {
                                rax = PlayerObject::pushDown(player);
                        }
                        else {
                                COND = player->isUpsideDown != 0x0;
                                xmm0 = intrinsic_movss(xmm0, var_3C);
                                xmm0 = intrinsic_ucomiss(xmm0, *(int32_t *)value 0.5);
                                rcx = (xmm0 > 0x0 ? 0x1 : 0x0) | (COND ? 0x1 : 0x0);
                                rax = PlayerObject::hitGround(player, rcx & 0xff, rdx);
                        }
                        rsi = 0x0;
                        rsi = player->isUpsideDown == 0x0 ? 0x1 : 0x0;
                        rdx = 0x0;
                        rax = PlayerObject::updateCollide(player, rsi, rdx, rcx);
                        xmm0 = intrinsic_movss(xmm0, var_3C);
                        xmm0 = intrinsic_ucomiss(xmm0, *(int32_t *)value 0.5);
                        
                        if (xmm0 > 0x0) {
                                xmm0 = intrinsic_ucomisd(0x0, *(player + 0x760));
                                if (xmm0 >= 0x0) {
                                        rax = sub_10022dbf0(player, rsi);
                                }
                        }
                        player->isOnSlope2 = false;
                        goto loc_1000792a3;