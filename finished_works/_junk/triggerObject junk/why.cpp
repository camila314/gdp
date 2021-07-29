int EffectGameObject::triggerObject(GJBaseGameLayer* gameLayer) { // r14
    if (this->objectType == kCollectible) {

        //loc_1000c9886 :
        if (this->collectibleMode == 2) {
            gameLayer->toggleGroupTriggered(this->targetedGroupID, this->toggleOn);
        } else if (this->collectibleMode == 1) {
            gameLayer->collectedObject(this);
        }
        return;
    }

    switch (this->objectID) {
        // loop inside switchtmp.cpp
    }
loc_1000c98ad :
    rax = *(int32_t *)(this + 0x3c4);
    if (rax > 0x392) goto loc_1000c98f1;

loc_1000c98ba :
    if (rax > 0x2e7) goto loc_1000c99fd;

loc_1000c98c5 :
    rax = rax - 22;
    if (rax > 0x53) goto loc_1000c9e36;

loc_1000c98d1 :
    rax = sign_extend_64(*(int32_t *)(0x1000c9ff8 + rax * 0x4));
    rax = rax + 0x1000c9ff8; // doned
    goto *0x1000c9ff8[rax];

loc_1000c98e1 :
    *(int32_t *)(r14 + 0x48c) = 0x1;
    goto loc_ret2;

loc_ret2 :
    rsp = rsp + 0x18;
    return rax;

loc_1000c9d42 :
    *(int32_t *)(r14 + 0x48c) = 0x5;
    goto loc_ret2;

loc_1000c9d52 :
    *(int32_t *)(r14 + 0x48c) = 0x4;
    goto loc_ret2;

loc_1000c9d62 :
    *(int32_t *)(r14 + 0x48c) = 0x6;
    goto loc_ret2;

loc_1000c9d72 :
    *(int32_t *)(r14 + 0x48c) = 0x7;
    goto loc_ret2;

loc_1000c9d82 :
    *(int32_t *)(r14 + 0x48c) = 0x2;
    goto loc_ret2;

loc_1000c9d92 :
    *(int32_t *)(r14 + 0x48c) = 0x3;
    goto loc_ret2;

loc_1000c9a72 :
    r10 = *r14;
    rcx = *(int16_t *)(this + 0x4ed) & 0xffff;
    rsi = *(int8_t *)(this + 0x4ef) & 0xff;
    rsi = rsi << 0x10 | rcx;
    xmm0 = intrinsic_movss(xmm0, this->duration);
    r11 = this->uuid;
    rdx = this->colorID;
    xmm1 = intrinsic_movss(xmm1, this->opacity);
    xmm2 = intrinsic_movsd(xmm2, *(this + 0x560));
    r8 = *(this + 0x568);
    r9 = *(int32_t *)(this + 0x570);
    rcx = *(int8_t *)(this + 0x50b) & 0xff;

    rax = (*(r10 + 0x458))(r14);
    rsp = (rsp - 0x20) + 0x20;
    if ((*(int32_t *)(this + 0x3c4) == 0x1d) && (*(int8_t *)(this + 0x508) != 0x0)) {
            r10 = *r14;
            rcx = *(int16_t *)(this + 0x4ed) & 0xffff;
            rsi = *(int8_t *)(this + 0x4ef) & 0xff;
            rsi = rsi << 0x10 | rcx;
            xmm0 = intrinsic_movss(xmm0, this->duration);
            xmm2 = intrinsic_movsd(xmm2, *(this + 0x560));
            r8 = *(this + 0x568);
            r9 = *(int32_t *)(this + 0x570);
            rax = this->uuid;
            r11 = *(int8_t *)(this + 0x574) & 0xff;
            xmm1 = intrinsic_movss(xmm1, *(int32_t *)value 1.0);
            rdx = 0x3e9;
            rcx = 0x0;

            rax = (*(r10 + 0x458))(r14);
            rsp = (rsp - 0x20) + 0x20;
    }
    goto loc_ret2;

loc_1000c9e36 :
    rdi = this;
    rsi = r14;
    rsp = rsp + 0x18;
    rax = GameObject::triggerObject(rdi, rsi);
    return rax;

loc_1000c9da2 :
    if (this->inEditorMode != 0x0) goto loc_ret2;

loc_1000c9daf :
    rdi = GameManager::sharedState()->playLayer;
    rsi = 0x1;
    goto loc_1000c9ddd;

loc_1000c9ddd :
    rsp = rsp + 0x18;
    rax = sub_10007fe40(rdi, rsi);
    return rax;

loc_1000c9dc2 :
    if (this->inEditorMode != 0x0) goto loc_ret2;

loc_1000c9dcf :
    rdi = GameManager::sharedState()->playLayer;
    rsi = 0x0;
    goto loc_1000c9ddd;

loc_1000c9de6 :
    *(int32_t *)(r14 + 0x48c) = 0xa;
    goto loc_ret2;

loc_1000c9df6 :
    *(int32_t *)(r14 + 0x48c) = 0x9;
    goto loc_ret2;

loc_1000c9e06 :
    *(int32_t *)(r14 + 0x48c) = 0x8;
    goto loc_ret2;

loc_1000c9e16 :
    *(int32_t *)(r14 + 0x48c) = 0xb;
    goto loc_ret2;

loc_1000c9e26 :
    *(int32_t *)(r14 + 0x48c) = 0xc;
    goto loc_ret2;

loc_1000c99fd :
    if ((rax < 0x385) || (rax == 0x2e8)) goto loc_1000c9a72;

loc_1000c9a0f :
    if (rax == 0x385) {
            loc_1000c9a1a :
            // doned
            rdi = r14;
            rsi = this;
            rsp = rsp + 0x18;
            rax = sub_1000b7290(rdi, rsi);
    }
    else {
            rdi = this;
            rsi = r14;
            rsp = rsp + 0x18;
            rax = GameObject::triggerObject(rdi, rsi);
    }
    return rax;

loc_1000c98f1 :
    if (rax <= 0x5ef) goto loc_1000c9974;

loc_1000c98f8 :
    rcx = rax - 1811;
    if (rax <= 1819) goto loc_1000c99c0;

loc_1000c9907 :
    rcx = rax - 1585;
    if (rcx > 1616) goto loc_1000c9cd8;

loc_1000c9916 :
    rax = 0x1000ca148; // doned
    goto *0x1000ca148[sign_extend_64(*(int32_t *)(rax + rcx * 0x4)) + rax];

loc_1000c9926 :
    if (this->inEditorMode == 0x0) {
            rdi = GameManager::sharedState()->playLayer;
            rdx = this->targetedGroupID;
            rsi = *(int32_t *)(this + 0x584);
            rsp = rsp + 0x18;
            rax = sub_100075930();
    }
    else {
            rsp = rsp + 0x18;
    }
    return rax;

loc_1000c9f5d :
    rdi = gameLayer->effectManager;
    r9 = this->uuid;
    rsi = this->targetedGroupID;
    rcx = *(int32_t *)(this + 0x57c);
    r8 = *(int8_t *)(this + 0x580) & 0xff;
    rdx = *(int8_t *)(this + 0x579) & 0xff;
    rsp = rsp + 0x18;
    rax = sub_100185460(rdi, rsi, rdx, rcx, r8, r9);
    return rax;

loc_1000c9f8f :
    rdi = gameLayer->effectManager;
    rsi = this->itemID;
    rdx = this->targetCount;
    rax = this->uuid;
    rsp = rsp - 0x10;
    rax = sub_1001858d0(rdi, rsi, rdx, *(int8_t *)(this + 0x5a4) & 0xff, this->targetedGroupID, this->toggleOn, rax);
    goto loc_ret1;

loc_ret1 :
    rsp = rsp + 0x10;
    goto loc_ret2;

loc_1000c9fd1 :
    rsi = 0x0;
    goto loc_1000c9fda;

loc_1000c9fda :
    rdi = r14;
    rsp = rsp + 0x18;
    rax = sub_1000ba910(rdi, rsi);
    return rax;

loc_1000c9fd5 :
    rsi = 0x1;
    goto loc_1000c9fda;

loc_1000c9fe6 :
    rsi = this->targetedGroupID;
    rdi = r14;
    rsp = rsp + 0x18;
    rax = sub_1000b71d0(rdi, rsi);
    return rax;

loc_1000c9cd8 :
    if (rax == 0x5f0) { // doned
            loc_1000c9ce3 :
            if (this->inEditorMode == 0x0) {
                    xmm1 = intrinsic_movss(xmm1, this->duration);
                    xmm1 = intrinsic_ucomiss(xmm1, 0x0);
                    if (xmm1 > 0x0) {
                            xmm0 = 0x0;
                            xmm1 = intrinsic_movss(xmm1, *(int32_t *)(this + 0x500));
                            xmm1 = intrinsic_ucomiss(xmm1, xmm0);
                            if (xmm1 > 0x0) {
                                    rdi = GameManager::sharedState()->playLayer;
                                    xmm0 = intrinsic_movss(xmm0, this->duration);
                                    xmm1 = intrinsic_movss(xmm1, *(int32_t *)(this + 0x500));
                                    xmm2 = intrinsic_movss(xmm2, *(int32_t *)(this + 0x504));
                                    rsp = rsp + 0x18;
                                    rax = PlayLayer::shakeCamera(rdi);
                            }
                            else {
                                    rsp = rsp + 0x18;
                            }
                    }
                    else {
                            rsp = rsp + 0x18;
                    }
            }
            else {
                    rsp = rsp + 0x18;
            }
    }
    else {
            rdi = this;
            rsi = r14;
            rsp = rsp + 0x18;
            rax = GameObject::triggerObject(rdi, rsi);
    }
    return rax;

loc_1000c99c0 : // offset 1811 // doned
    rax = 0x1000ca1c8;
    goto *0x1000ca1c8[sign_extend_64(*(int32_t *)(rax + rcx * 0x4)) + rax];

loc_1000c99d0 :
    rsi = this->itemID;
    rcx = this->targetedGroupID;
    rdx = this->targetCount;
    r9 = this->compareType;
    r8 = this->toggleOn;
    rdi = r14;
    rsp = rsp + 0x18;
    rax = sub_1000b9ae0(rdi);
    return rax;

loc_1000c9e45 :
    if (this->inEditorMode == 0x0) {
            rdi = *(GameManager::sharedState()->playLayer + 0x180);
            rcx = this->uuid;
            rsi = this->targetedGroupID;
            rdx = this->toggleOn;
            rsp = rsp + 0x18;
            rax = sub_1001857a0(rdi, rsi, rdx, rcx);
    }
    else {
            rsp = rsp + 0x18;
    }
    return rax;

loc_1000c9e81 :
    rdi = gameLayer->effectManager;
    xmm0 = intrinsic_movss(xmm0, *(int32_t *)(this + 0x53c));
    xmm1 = intrinsic_movss(xmm1, *(int32_t *)(this + 0x540));
    rsi = *(int32_t *)(this + 0x544);
    xmm2 = intrinsic_movss(xmm2, *(int32_t *)(this + 0x548));
    xmm3 = intrinsic_movss(xmm3, this->duration);
    rdx = this->targetedGroupID;
    rcx = this->uuid;
    rsp = rsp + 0x18;
    rax = sub_100182fe0(rdi, rsi, rdx, rcx);
    return rax;

loc_1000c9ec3 :
    rdi = gameLayer->effectManager;
    rax = this->uuid;
    rsp = rsp - 0x10;
    rax = sub_100182b70(rdi, this->targetedGroupID, this->itemID, *(int32_t *)(this + 0x5a8), *(int8_t *)(this + 0x5a5) & 0xff, this->toggleOn, rax);
    goto loc_ret1;

loc_1000c9f01 :
    rdx = this->targetCount;
    rsi = this->itemID;
    rdi = r14;
    rsp = rsp + 0x18;
    rax = sub_1000b9e20(rdi, rsi, rdx);
    return rax;

loc_1000c9f19 :
    if (this->inEditorMode != 0x0) goto loc_ret2;

loc_1000c9f26 :
    rdi = GameManager::sharedState()->playLayer;
    rsi = 0x1;
    goto loc_1000c9f54;

loc_1000c9f54 :
    rsp = rsp + 0x18;
    rax = sub_10007fe80(rdi, rsi);
    return rax;

loc_1000c9f39 :
    if (this->inEditorMode != 0x0) goto loc_ret2;

loc_1000c9f46 :
    rdi = GameManager::sharedState()->playLayer;
    rsi = 0x0;
    goto loc_1000c9f54;

loc_1000c9974 :
    if (rax <= 0x418) goto loc_1000c9a29;

loc_1000c997f :
    if (rax > 0x541) goto loc_1000c9b68;

loc_1000c998a :
    if (rax != 0x419) {
            if (rax == 0x4f4) {
                    loc_1000c99a0 :
                    // doned
                    rdx = this->uuid;
                    rsi = this->targetedGroupID;
                    xmm0 = intrinsic_movss(xmm0, *(int32_t *)(this + 0x588));
                    rdi = r14;
                    rsp = rsp + 0x18;
                    rax = sub_1000b7020(rdi);
            }
            else {
                    rdi = this;
                    rsi = r14;
                    rsp = rsp + 0x18;
                    rax = GameObject::triggerObject(rdi, rsi);
            }
    }
    else {
            // rax == 0x419
            loc_1000c998a :
            // doned
            rsi = this->targetedGroupID;
            rdx = this->toggleOn;
            rdi = r14;
            rsp = rsp + 0x18;
            rax = sub_1000b75f0(rdi, rsi, rdx);
    }
    return rax;

loc_1000c9b68 :
    if (rax == 0x542) goto loc_1000c9c81; // doned

loc_1000c9b73 :
    if (rax == 0x543) { // doned
            loc_1000c9b7e :
            *(int8_t *)(this + 0x538) = 0x1;
            rdi = gameLayer->effectManager;
            xmm0 = intrinsic_movss(xmm0, *(int32_t *)(this + 0x530));
            xmm1 = intrinsic_movss(xmm1, *(int32_t *)(this + 0x534));
            xmm2 = intrinsic_movss(xmm2, this->duration);
            rsi = this->targetedGroupID;
            rdx = this->targetedGroupID2;
            r8 = this->uuid;
            rsp = rsp + 0x18;
            rax = sub_100182ed0(rdi, rsi, rdx, 0x1, r8);
    }
    else {
            rdi = this;
            rsi = r14;
            rsp = rsp + 0x18;
            rax = GameObject::triggerObject(rdi, rsi);
    }
    return rax;

loc_1000c9c81 :
    rdi = gameLayer->effectManager;
    rsi = *(int32_t *)(this + 0x528) * 0x168;
    rsi = rsi + *(int32_t *)(this + 0x524);
    xmm0 = intrinsic_movss(xmm0, this->duration);
    rdx = this->targetedGroupID;
    rcx = this->targetedGroupID2;
    r8 = this->easingType;
    xmm1 = intrinsic_movss(xmm1, *(int32_t *)(this + 0x518));
    rax = this->uuid;
    rsp = rsp - 0x10;
    rax = sub_100182df0(rdi, rsi, rdx, rcx, r8, *(int8_t *)(this + 0x52c) & 0xff, rax);
    goto loc_ret1;

loc_1000c9a29 :
    if (rax == 0x393) goto loc_1000c9a72; // doned

loc_1000c9a30 :
    if (rax == 0x3ee) goto loc_1000c9bde; // doned

loc_1000c9a3b :
    if (rax == 0x3ef) { // doned
        loc_1000c9a46 :
            rdi = gameLayer->effectManager;
            rsi = this->targetedGroupID;
            xmm0 = intrinsic_movss(xmm0, this->duration);
            xmm1 = intrinsic_movss(xmm1, this->opacity);
            rdx = this->uuid;
            rsp = rsp + 0x18;
            rax = sub_1001845d0(rdi, rsi, rdx);
    }
    else {
            rdi = this;
            rsi = r14;
            rsp = rsp + 0x18;
            rax = GameObject::triggerObject(rdi, rsi);
    }
    return rax;

loc_1000c9bde :
    CMP(this->pulseMode, 0x1);
    rcx = this->pulseMode+1;
    rdi = gameLayer->effectManager;
    r10 = this->uuid;
    rsi = this->targetedGroupID;
    rdx = (this->pulseTarget == 1);
    xmm0 = intrinsic_movss(xmm0, *(int32_t *)(this + 0x54c));
    xmm1 = intrinsic_movss(xmm1, *(int32_t *)(this + 0x550));
    xmm2 = intrinsic_movss(xmm2, *(int32_t *)(this + 0x554));
    xmm3 = intrinsic_movsd(xmm3, this->hsvData);
    r8 = this->color;
    r11 = *(int32_t *)(this + 0x570);
    r14 = *(int8_t *)(this + 0x575) & 0xff;
    rax = *(int8_t *)(this + 0x576) & 0xff;
    gameLayer->effectManager->sub_100184890(rsi, rdx, xmm0, xmm1, xmm2, rcx, r8, r11, r14, rax, *(int8_t *)(this + 0x577) & 0xff, r10);
    goto loc_ret2;
}