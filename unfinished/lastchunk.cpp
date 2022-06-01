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
return xmm0;