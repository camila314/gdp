inline bool PlayerObject::isRestricted() {
    return this->isFlying() || this->isSpider || this->isBall;
}

inline bool playerTouchesObject(CCRect playerRect, CCRect hitboxRect) {
    float playerMaxX = playerRect->getMaxX(); // var_50
    float playerMinX = playerRect->getMinX(); // var_50
    float playerMaxY = playerRect->getMaxY(); // var_88
    float playerMinY = playerRect->getMinY(); // var_84

    float objMinX = hitboxRect->getMinX();
    float objMaxX = hitboxRect->getMaxX();
    float objMinY = hitboxRect->getMinY();
    float objMaxY = hitboxRect->getMaxY();

    return (objMinX <= playerMinX && objMaxX <= playerMaxX && objMinY <= playerMinY && objMaxY <= playerMaxY);

}
enum GameObjectType {
    kTypeYellowGravity,
    kTypeBlueGravity,
    kTypeVehicleShip
};


float _ZN9PlayLayer15checkCollisionsEPvP12PlayerObjectf(PlayerObject* player, float delta) {
    
    player->preCollision();
    float groundHeight = player->groundHeight;

    float cubeSizeScalar; // xmm2
    if (player->vehicleSize == 1.0) { // nonparity check here too
            cubeSizeScalar = 0.0;
    }
    else {
            cubeSizeScalar = (1.0 - player->vehicleSize) * groundHeight * 0.5;
    }
    groundHeight /= 2;
    float groundY = 90.0 + groundHeight - xmm2; // xmm0

    //var_50 = groundHeight;
    //var_58 = cubeSizeScalar;
    //var_3C = xmm0;

    float ypos = player->getPositionY(); // xmm0
    if (player->getPositionY() >= groundY || player->isRestricted() || this->unknown_489 || !player->isUpsideDown) {
        //loc_100078d5e
        if (ypos > 2790.0 + cubeSizeScalar) { // xmm0 = pos.y
            return;
        }
        if(!player->isUpsideDown && !player->isRising) {
            // loc_100078e22
            player->setPositionY(groundY);
            player->hitGround(false);
            player->updateCollide(player, true, 0);
            player->isOnSlope2 = false;
        }
        goto loc_100078e83; // see tmp.cpp
    } else if (!player->isSafeFlip()) {
        this->destroyPlayer(player, nullptr);
        return;
    } else {
        // loc_100078dc2
        player->setPositionY(groundY);
        player->hitGround(true);
        player->updateCollide(false, 0);
        player->isSliding = false;
        player->isOnSlope2 = 0x0;
        return;
    }
}

loc_100078da4 :
    if (player->isUpsideDown == 0x0) goto loc_100078e22;

loc_100078dae :
    xmm0 = intrinsic_movss(xmm0, *(int32_t *)value 0.10);
    if (PlayerObject::isSafeFlip(player) == 0x0) goto loc_retDestroy;

loc_100078dc2 :
    rax = *player;
    r15 = *(rax + 0xb8);
    xmm0 = intrinsic_movss(xmm0, *(int32_t *)(*(rax + 0xc0))(player));
    rax = cocos2d::CCPoint::CCPoint(var_80, xmm0, intrinsic_movss(xmm1, var_3C));
    rax = (r15)(player, var_80);
    rax = PlayerObject::hitGround(player, 0x1, rdx);
    rax = PlayerObject::updateCollide(player, 0x0, 0x0, rcx);
    player->isSliding = 0x0;
    player->isOnSlope2 = 0x0;
    goto loc_ret1;

loc_ret1 :
    rbx = stack[2042];
    r12 = stack[2043];
    player = stack[2044];
    this = stack[2045];
    r15 = stack[2046];
    rsp = rsp + 0x128;
    rbp = stack[2047];
    return xmm0;

loc_retDestroy :
    rdi = this;
    rsi = player;
    rbx = stack[2042];
    r12 = stack[2043];
    player = stack[2044];
    this = stack[2045];
    r15 = stack[2046];
    rsp = rsp + 0x128;
    rbp = stack[2047];
    rax = PlayLayer::destroyPlayer(rdi, rsi, 0x0, rcx, r8, r9);
    return xmm0;

loc_100078e22 :
    if (player->isRising == 0x0) {
            rax = *player;
            r15 = *(rax + 0xb8);
            xmm0 = intrinsic_movss(xmm0, *(int32_t *)(*(rax + 0xc0))(player));
            xmm1 = intrinsic_movss(xmm1, var_3C);
            rax = cocos2d::CCPoint::CCPoint(var_80, xmm0, xmm1);
            
            rax = (r15)(player, var_80);
            rax = PlayerObject::hitGround(player, 0x0, 0x0);
            rdx = 0x0;
            rax = PlayerObject::updateCollide(player, 0x1, rdx, rcx);
            player->isOnSlope2 = 0x0;
    }
    goto loc_100078e83;

loc_100078e83 :
    if (PlayerObject::isFlying(player) != 0x0) {
            this = 0x0;
    }
    else {
            if (player->isBall != 0x0) {
                    this = 0x0;
            }
            else {
                    this = this->unknown_489 != 0x0 ? 0x1 : 0x0;
            }
    }
    if ((((PlayerObject::isFlying(player) != 0x0) || (player->isBall != 0x0)) || (player->isSpider != 0x0)) || (this->unknown_489 != 0x0)) goto loc_100078ee0;

loc_10007a57e :
    
    var_90 = this + 0x489;
    goto loc_1000792a3;

loc_1000792a3 :
    rbx = (*(*player + 0x4f8))(player);
    rax = cocos2d::CCRect::getMaxX(rbx);
    var_50 = intrinsic_movss(var_50, xmm0);
    rax = cocos2d::CCRect::getMinX(rbx);
    var_40 = intrinsic_movss(var_40, xmm0);
    rax = cocos2d::CCRect::getMaxY(rbx);
    var_88 = intrinsic_movss(var_88, xmm0);
    var_60 = rbx;
    rax = cocos2d::CCRect::getMinY(rbx);
    var_84 = intrinsic_movss(var_84, xmm0);
    xmm0 = intrinsic_movss(xmm0, *(int32_t *)(*(*player + 0xc0))(player));
    rdi = this;
    r15 = sub_1000b6120();
    var_3C = cocos2d::CCArray::count(*(this + 0x3a8));
    var_58 = r15;
    r15 = r15 - 1;
    var_38 = player;
    var_48 = player + 0x78c;
    goto loc_100079340;

loc_100079340 :
    if ((r15 < 0x0) || (r15 >= var_3C)) goto loc_10007a180;

loc_100079353 :
    rax = cocos2d::CCArray::objectAtIndex(*(this + 0x3a8), r15);
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
    player = *r12;
    if (player == 0x0) goto loc_10007a180;

loc_10007939d :
    rax = *(int32_t *)(player + 0x370);
    if (((rax == 0x7) || (*(int8_t *)(player + 0x27a) != 0x0)) || (*(int8_t *)(player + 0x391) != 0x0)) goto loc_1000793c0;

loc_1000793ce :
    if (rax > 0x27) goto loc_1000793ee;

loc_1000793d3 :
    rcx = 0x10007a598;
    goto *0x10007a598[sign_extend_64(*(int32_t *)(rcx + rax * 0x4)) + rcx];

loc_1000793e5 :
    rdi = *(this + 0x550);
    goto loc_100079452;

loc_100079452 :
    rax = cocos2d::CCArray::addObject(rdi, player);
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
    rbx = cocos2d::CCArray::count(*(this + 0x550));
    if (rbx > 0x0) {
            rbx = rbx - 0x1;
            player = var_80;
            r12 = var_38;
            do {
                    this = cocos2d::CCArray::objectAtIndex(*(this + 0x550), rbx);
                    if (sub_10033b0e0(this) == 0x0) {
                            rax = *this;
                            rax = (*(rax + 0x4f8))(this);
                            rax = cocos2d::CCRect::CCRect(player, rax);
                            if ((r15 & 0x1) != 0x0) {
                                    if (*(int16_t *)(this + 0x460) > 0x0) {
                                            xmm0 = intrinsic_movss(xmm0, delta);
                                            r15 = sub_10021eb70(var_38, this) ^ 0x1;
                                    }
                            }
                            rax = cocos2d::CCRect::getMinX(player);
                            xmm0 = intrinsic_ucomiss(xmm0, var_58);
                            if (xmm0 <= 0x0) {
                                    rax = cocos2d::CCRect::getMaxX(player);
                                    xmm1 = intrinsic_movss(xmm1, var_3C);
                                    xmm1 = intrinsic_ucomiss(xmm1, xmm0);
                                    if (xmm1 <= 0x0) {
                                            rax = cocos2d::CCRect::getMinY(player);
                                            xmm0 = intrinsic_ucomiss(xmm0, var_50);
                                            if (xmm0 <= 0x0) {
                                                    rax = cocos2d::CCRect::getMaxY(player);
                                                    xmm1 = intrinsic_movss(xmm1, var_40);
                                                    xmm1 = intrinsic_ucomiss(xmm1, xmm0);
                                                    if (xmm1 <= 0x0) {
                                                            xmm0 = intrinsic_movss(xmm0, delta);
                                                            rax = sub_10021d880(r12, this);
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
                    
            } while (rbx != 0xffffffff);
    }
    rax = cocos2d::CCArray::removeAllObjects(*(this + 0x550));
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
    rax = cocos2d::CCArray::count(*(this + 0x568));
    rdi = *(this + 0x568);
    if (rax == 0x0) goto loc_10007a50f;

loc_10007a3d1 :
    rbx = 0x0;
    r15 = var_80;
    goto loc_10007a3e0;

loc_10007a3e0 :
    rsi = rbx;
    player = cocos2d::CCArray::objectAtIndex(rdi, rsi);
    if (sub_10033b0e0(player) != 0x0) goto loc_10007a4f2;

loc_10007a3fa :
    rsi = (*(*player + 0x4f8))(player);
    rax = cocos2d::CCRect::CCRect(r15, rsi);
    xmm0 = intrinsic_movss(xmm0, *(int32_t *)(player + 0x35c));
    xmm0 = intrinsic_ucomiss(xmm0, *(int32_t *)value 0.00);
    if (xmm0 <= 0x0) goto loc_10007a440;

loc_10007a424 :
    rdi = this;
    rsi = var_38;
    rdx = player;
    if (sub_1000b66e0() != 0x0) goto loc_10007a499;

loc_10007a4ee :
    
    goto loc_10007a4f2;

loc_10007a4f2 :
    rbx = rbx + 0x1;
    rax = cocos2d::CCArray::count(*(this + 0x568));
    rdi = *(this + 0x568);
    if (rbx < rax) goto loc_10007a3e0;

loc_10007a50f :
    rax = cocos2d::CCArray::removeAllObjects(rdi);
    xmm0 = intrinsic_movss(xmm0, delta);
    rax = sub_10021cd10(var_38, rsi);
    goto loc_ret1;

loc_10007a499 :
    if (*(int8_t *)(player + 0x2b8) == 0x0) goto loc_10007a4e1;

loc_10007a4a3 :
    this = (*(*player + 0x5a8))(player);
    r12 = (*(*var_38 + 0x5a8))(var_38);
    rsi = r12;
    if (sub_10035b0d0(this, rsi) == 0x0) goto loc_10007a4ee;

loc_10007a4d2 :
    rsi = this;
    if (sub_10035b0d0(r12, rsi) == 0x0) goto loc_10007a4ee;

loc_10007a4e1 :
    if (*(int8_t *)(this + 0x700) == 0x0) goto loc_10007a534;
    goto loc_10007a4ee;

loc_10007a534 :
    rax = PlayLayer::destroyPlayer(this, var_38, player, rcx, r8, 0x1);
    goto loc_ret1;

loc_10007a440 :
    rax = cocos2d::CCRect::getMinX(r15);
    this = 0x1;
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
                            this = xmm1 > 0x0 ? 0x1 : 0x0;
                    }
            }
    }
    if ((this ^ 0x1) == 0x0) goto loc_10007a4ee;
    goto loc_10007a499;

loc_1000793ee :
    if (loc_100342a50(player, var_38) != 0x0) goto loc_1000793c0;

loc_1000793fe :
    rax = cocos2d::CCRect::CCRect(var_80);
    if ((*(*player + 0x5e8))(player) == 0x19) {
            rax = *player;
            rcx = var_A0;
            rdi = rcx;
            rsi = player;
            xmm0 = intrinsic_movss(xmm0, *(int32_t *)value 2.00);
            xmm1 = intrinsic_movaps(xmm1, xmm0);
            rax = (*(rax + 0x500))();
            rdi = var_80;
            rsi = var_A0;
    }
    else {
            rdi = var_80;
            rsi = (*(*player + 0x4f8))(player);
    }
    rax = cocos2d::CCRect::operator=(rdi, rsi);
    xmm0 = intrinsic_movss(xmm0, *(int32_t *)(player + 0x35c));
    xmm0 = intrinsic_ucomiss(xmm0, *(int32_t *)value 0.00);
    if (xmm0 <= 0x0) goto loc_1000794b3;

loc_100079497 :
    rdi = this;
    rsi = var_38;
    rdx = player;
    if (sub_1000b66e0() != 0x0) goto loc_10007950e;

loc_100079565 :
    
    r12 = r12 + 0x8;
    if (r12 <= rbx) goto loc_100079390;
    goto loc_10007a180;

loc_10007950e :
    if (*(int8_t *)(player + 0x2b8) != 0x0) {
            var_70 = (*(*player + 0x5a8))(player);
            rax = GameObject::updateOrientedBox(var_38);
            this = (*(*var_38 + 0x5a8))(var_38);
            if (sub_10035b0d0(var_70, this) != 0x0) {
                    this = sub_10035b0d0(this, var_70);
            }
            else {
                    this = 0x0;
            }
    }
    else {
            this = 0x1;
    }
    if ((*(*player + 0x5e8))(player) == 0x19) {
            rax = *player;
            rax = (*(rax + 0x4f8))(player);
            rax = cocos2d::CCRect::operator=(var_80, rax);
    }
    if (this == 0x0) goto loc_1000795fb;

loc_1000795b3 :
    rax = *(int32_t *)(player + 0x370);
    rax = rax + 0xfffffffd;
    
    if (rax > 0x25) goto loc_1000793c0;

loc_1000795ca :
    rcx = 0x10007a638;
    goto *0x10007a638[sign_extend_64(*(int32_t *)(rcx + rax * 0x4)) + rcx];

loc_100079698 :
    this = var_38;
    if (*(int8_t *)(this + 0x776) == 0x0) {
            rax = PlayLayer::playGravityEffect(this, 0x1);
    }
    rax = *player;
    rax = (*(rax + 0xc0))(player);
    rax = cocos2d::CCPoint::CCPoint(var_E0, rax);
    rax = cocos2d::CCPoint::operator=(var_48, var_E0);
    *(this + 0x7b8) = player;
    rsi = this;
    
    rax = *this;
    rdx = 0x1;
    rcx = 0x0;
    rax = (*(rax + 0x460))(this, rsi, rdx, rcx);
    rax = GameObject::playShineEffect(player);
    rax = GameObject::activatedByPlayer(player, var_38);
    r12 = r12 + 0x8;
    if (r12 <= rbx) goto loc_100079390;
    goto loc_10007a180;

loc_100079727 :
    if (*(int8_t *)(var_38 + 0x776) != 0x0) {
            rax = PlayLayer::playGravityEffect(this, 0x0);
    }
    rax = *player;
    rax = (*(rax + 0xc0))(player);
    rax = cocos2d::CCPoint::CCPoint(var_120, rax);
    rax = cocos2d::CCPoint::operator=(var_48, var_120);
    this = var_38;
    *(this + 0x7b8) = player;
    rax = *this;
    rdx = 0x0;
    rcx = 0x0;
    rax = (*(rax + 0x460))(this, this, rdx, rcx);
    goto loc_100079c33;

loc_100079c33 :
    rax = GameObject::playShineEffect(player);
    rsi = this;
    
    rax = GameObject::activatedByPlayer(player, rsi);
    r12 = r12 + 0x8;
    if (r12 <= rbx) goto loc_100079390;
    goto loc_10007a180;

loc_100079791 :
    rdi = this;
    this = var_38;
    rax = PlayLayer::playerWillSwitchMode(rdi, this, player, 0x0);
    rcx = 0x0;
    r8 = 0x5;
    goto loc_100079c24;

loc_100079c24 :
    rdx = player;
    rax = sub_10007baf0(this, this, rdx);
    goto loc_100079c33;

loc_1000797b0 :
    rcx = 0x10007a638;
    rdi = this;
    this = var_38;
    rax = PlayLayer::playerWillSwitchMode(rdi, this, player, rcx);
    rax = *player;
    rax = (*(rax + 0xc0))(player);
    rax = cocos2d::CCPoint::CCPoint(var_D8, rax);
    rax = cocos2d::CCPoint::operator=(var_48, var_D8);
    *(this + 0x7b8) = player;
    rdx = this;
    rax = PlayLayer::willSwitchToMode(this, 0x0, rdx);
    rax = PlayerObject::modeDidChange(this);
    goto loc_100079c33;

loc_1000793c0 :
    r12 = r12 + 0x8;
    if (r12 <= rbx) goto loc_100079390;
    goto loc_10007a180;

loc_100079611 :
    rdi = this;
    rsi = var_38;
    rdx = player;
    rax = GJBaseGameLayer::bumpPlayer();
    r12 = r12 + 0x8;
    if (r12 <= rbx) goto loc_100079390;
    goto loc_10007a180;

loc_100079810 :
    rax = loc_100342cf0(player);
    rax = rax ^ 0x1;
    this = var_38;
    rcx = (*(int8_t *)(this + 0x776) != 0x0 ? 0x1 : 0x0) ^ rax;
    if (rcx != 0x1) goto loc_10007a04b;

loc_100079834 :
    var_70 = rax & 0xff;
    rax = PlayLayer::playGravityEffect(this, rax & 0xff);
    var_A8 = (*(*player + 0xc0))(player);
    xmm1 = intrinsic_movss(xmm1, *(int32_t *)value -10.00);
    rax = cocos2d::CCPoint::CCPoint(var_A0, 0x0, xmm1);
    rax = cocos2d::CCPoint::operator+(var_B0, var_A8, var_A0);
    rax = cocos2d::CCPoint::operator=(var_48, var_B0);
    rax = GameObject::activatedByPlayer(player, this);
    *(this + 0x7b8) = player;
    xmm0 = intrinsic_movss(0x0, *(int32_t *)value 0.8);
    rax = sub_10022d8e0(this, this);
    rax = *this;
    rcx = 0x1;
    rdx = var_70;
    rax = (*(rax + 0x460))(this, this, rdx, rcx);
    *(int8_t *)(this + 0x628) = 0x1;
    
    r12 = r12 + 0x8;
    if (r12 <= rbx) goto loc_100079390;
    goto loc_10007a180;

loc_10007a04b :
    
    r12 = r12 + 0x8;
    if (r12 <= rbx) goto loc_100079390;
    goto loc_10007a180;

loc_1000795da :
    rdi = this;
    rsi = var_38;
    rdx = player;
    rax = GJBaseGameLayer::playerTouchedRing();
    r12 = r12 + 0x8;
    if (r12 <= rbx) goto loc_100079390;
    goto loc_10007a180;

loc_1000798f2 :
    rax = *player;
    rax = (*(rax + 0xc0))(player);
    rax = cocos2d::CCPoint::CCPoint(var_F8, rax);
    
    rax = cocos2d::CCPoint::operator=(var_48, var_F8);
    *(var_38 + 0x7b8) = player;
    rsi = 0x1;
    goto loc_10007996f;

loc_10007996f :
    rdx = 0x0;
    rax = sub_10007bdc0(this, rsi, rdx);
    goto loc_100079b6c;

loc_100079b6c :
    rax = GameObject::playShineEffect(player);
    goto loc_100079b74;

loc_100079b74 :
    rax = *player;
    xmm0 = 0x0;
    rax = (*(rax + 0x580))(player);
    r12 = r12 + 0x8;
    if (r12 <= rbx) goto loc_100079390;
    goto loc_10007a180;

loc_100079933 :
    rax = *player;
    rax = (*(rax + 0xc0))(player);
    rax = cocos2d::CCPoint::CCPoint(var_100, rax);
    
    rax = cocos2d::CCPoint::operator=(var_48, var_100);
    *(var_38 + 0x7b8) = player;
    rsi = 0x0;
    goto loc_10007996f;

loc_10007997e :
    rcx = 0x10007a638;
    rax = PlayLayer::playerWillSwitchMode(this, var_38, player, rcx);
    rdx = var_38;
    rax = PlayLayer::willSwitchToMode(this, 0x10, rdx);
    if (*(int8_t *)var_90 != 0x0) {
            this = *(this + 0x710);
            if (this == 0x0) {
                    this = player;
            }
    }
    else {
            this = player;
    }
    rax = *this;
    rax = (*(rax + 0xc0))(this);
    rax = cocos2d::CCPoint::CCPoint(var_A0, rax);
    rax = cocos2d::CCPoint::operator=(var_48, var_A0);
    *(var_38 + 0x7b8) = this;
    *(this + 0x708) = this;
    this = var_38;
    rax = PlayerObject::toggleRollMode(var_38, 0x1);
    goto loc_10007a15b;

loc_10007a15b :
    rax = GameObject::playShineEffect(player);
    rax = GameObject::activatedByPlayer(player, this);
    
    r12 = r12 + 0x8;
    if (r12 <= rbx) goto loc_100079390;
    goto loc_10007a180;

loc_1000799c5 :
    rax = *player;
    rax = (*(rax + 0xc0))(player);
    rax = cocos2d::CCPoint::CCPoint(var_110, rax);
    rax = cocos2d::CCPoint::operator=(var_48, var_110);
    this = var_38;
    *(this + 0x7b8) = player;
    rsi = 0x0;
    goto loc_100079a3a;

loc_100079a3a :
    rax = PlayerObject::togglePlayerScale(this, rsi, rdx);
    goto loc_100079c33;

loc_1000799ff :
    rax = *player;
    rax = (*(rax + 0xc0))(player);
    rax = cocos2d::CCPoint::CCPoint(var_108, rax);
    rax = cocos2d::CCPoint::operator=(var_48, var_108);
    this = var_38;
    *(this + 0x7b8) = player;
    rsi = 0x1;
    goto loc_100079a3a;

loc_100079a47 :
    rdi = this;
    this = var_38;
    rax = PlayLayer::playerWillSwitchMode(rdi, this, player, 0x0);
    rcx = 0x0;
    r8 = 0x13;
    goto loc_100079c24;

loc_100079a66 :
    if (*(int8_t *)(player + 0x378) == 0x0) goto loc_1000793c0;

loc_100079a74 :
    if (GJEffectManager::hasBeenTriggered(*(this + 0x180), *(int32_t *)(player + 0x36c)) == 0x0) {
            rax = GJEffectManager::storeTriggeredID(*(this + 0x180), *(int32_t *)(player + 0x36c));
            rax = *player;
            rax = (*(rax + 0x4e0))(player, this);
    }
    goto loc_100079b74;

loc_100079632 :
    if (*(int8_t *)(this + 0x739) != 0x0) goto loc_1000793c0;

loc_100079640 :
    rax = *player;
    rax = (*(rax + 0x4e0))(player, this);
    rax = *player;
    xmm0 = 0x0;
    rax = (*(rax + 0x580))(player);
    rax = GameObject::destroyObject(player, this);
    if (PlayLayer::hasUniqueCoin(this, player) != 0x0) goto loc_1000793c0;

loc_10007967b :
    rax = PlayLayer::pickupItem(this, player);
    r12 = r12 + 0x8;
    if (r12 <= rbx) goto loc_100079390;
    goto loc_10007a180;

loc_100079ab7 :
    rax = *player;
    rax = (*(rax + 0xc0))(player);
    rax = cocos2d::CCPoint::CCPoint(var_E8, rax);
    
    rax = cocos2d::CCPoint::operator=(var_48, var_E8);
    rcx = var_38;
    *(rcx + 0x7b8) = player;
    *(int8_t *)(*(this + 0x388) + 0x7e0) = 0x1;
    rdx = 0x1;
    r8 = 0x0;
    rax = PlayLayer::toggleDualMode(this, player, rdx, rcx, r8);
    *(int8_t *)(*(this + 0x388) + 0x7e0) = 0x0;
    goto loc_100079b6c;

loc_100079b22 :
    rax = *player;
    rax = (*(rax + 0xc0))(player);
    rax = cocos2d::CCPoint::CCPoint(var_F0, rax);
    
    rax = cocos2d::CCPoint::operator=(var_48, var_F0);
    rcx = var_38;
    *(rcx + 0x7b8) = player;
    rdx = 0x0;
    r8 = 0x0;
    rax = PlayLayer::toggleDualMode(this, player, rdx, rcx, r8);
    goto loc_100079b6c;

loc_100079b96 :
    rdx = 0x0;
    xmm0 = intrinsic_movss(xmm0, delta);
    rax = PlayerObject::collidedWithSlope(var_38, player, rdx);
    rax = *var_38;
    
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
    rdi = this;
    this = var_38;
    rax = PlayLayer::playerWillSwitchMode(rdi, this, player, 0x0);
    rcx = 0x0;
    r8 = 0x1a;
    goto loc_100079c24;

loc_100079c5c :
    rcx = 0x10007a638;
    rax = PlayLayer::playerWillSwitchMode(this, var_38, player, rcx);
    rdx = var_38;
    rax = PlayLayer::willSwitchToMode(this, 0x1b, rdx);
    if (*(int8_t *)var_90 != 0x0) {
            this = *(this + 0x710);
            if (this == 0x0) {
                    this = player;
            }
    }
    else {
            this = player;
    }
    rax = *this;
    rax = (*(rax + 0xc0))(this);
    rax = cocos2d::CCPoint::CCPoint(var_A0, rax);
    rax = cocos2d::CCPoint::operator=(var_48, var_A0);
    *(var_38 + 0x7b8) = this;
    *(this + 0x708) = this;
    this = var_38;
    rax = sub_100223c70(var_38, 0x1, rdx);
    goto loc_10007a15b;

loc_100079ca3 :
    rax = *player;
    rax = (*(rax + 0xc0))(player);
    rax = cocos2d::CCPoint::CCPoint(var_118, rax);
    rax = cocos2d::CCPoint::operator=(var_48, var_118);
    *(var_38 + 0x7b8) = player;
    rax = *var_38;
    rcx = *(rax + 0xb8);
    xmm0 = intrinsic_movss(xmm0, *(int32_t *)(*(rax + 0xc0))(var_38));
    var_40 = intrinsic_movss(var_40, xmm0);
    rax = *player;
    rax = (*(rax + 0x518))(var_D0, player);
    xmm1 = intrinsic_movss(xmm1, var_CC);
    xmm1 = intrinsic_addss(xmm1, *(int32_t *)(player + 0x504));
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
    this = var_38;
    rax = cocos2d::CCRect::getMinY(var_60);
    var_84 = intrinsic_movss(var_84, xmm0);
    rax = GameObject::playShineEffect(player);
    rax = GameObject::activatedByPlayer(player, this);
    xmm0 = intrinsic_movss(xmm0, *(int32_t *)value 50.00);
    rax = PlayerObject::spawnPortalCircle(this, 0xffff00, rdx);
    rdi = *(player + 0x4f8);
    if (rdi != 0x0) {
            rax = *rdi;
            rax = (*(rax + 0xc0))();
            rax = cocos2d::CCPoint::CCPoint(var_C8, rax);
            rax = cocos2d::CCPoint::operator=(var_48, var_C8);
            rdi = *(player + 0x4f8);
            *(this + 0x7b8) = rdi;
            rax = GameObject::playShineEffect(rdi);
            xmm0 = intrinsic_movss(xmm0, *(int32_t *)value 50.00);
            rax = PlayerObject::spawnPortalCircle(this, 0xc8ff, rdx);
            rax = sub_10021ae10(this);
            if (*(int8_t *)(this + 0x773) != 0x0) {
                    rax = sub_10021af90(this);
            }
            rax = *player;
            rax = (*(rax + 0xc0))(player);
            rax = cocos2d::CCPoint::CCPoint(var_C0, rax);
            rdi = *(player + 0x4f8);
            rax = *rdi;
            rax = (*(rax + 0xc0))(rdi);
            rax = cocos2d::CCPoint::CCPoint(var_B8, rax);
            rax = *(int16_t *)(this + 0x7c2) & 0xffff;
            rcx = *(int8_t *)(this + 0x7c4) & 0xff;
            xmm0 = intrinsic_movss(xmm0, *(int32_t *)0x10050c79c);
            xmm1 = intrinsic_movss(xmm1, *(int32_t *)value 0.20);
            xmm2 = intrinsic_movss(xmm2, *(int32_t *)value 1.0);
            r8 = 0x64;
            rdx = var_B8;
            rax = sub_100075cc0(this, var_C0, rdx, rcx << 0x10 | rax, r8, 0x1);
    }
    rax = this;
    if (*(int8_t *)(player + 0x508) != 0x0) {
            *(int32_t *)(rax + 0x4e0) = 0x3f000000;
    }
    rax = cocos2d::CCDirector::sharedDirector();
    rax = cocos2d::CCDirector::getWinSize(var_A0, rax);
    rcx = 0x10050d4a8;
    xmm0 = intrinsic_movss(xmm0, *(int32_t *)(rcx + (*(int8_t *)(player + 0x508) & 0xff) * 0x4));
    var_70 = intrinsic_movss(var_70, xmm0);
    rax = sub_10022b840(var_38);
    xmm0 = intrinsic_movss(xmm0, *(int32_t *)((*(*var_38 + 0xc0))(var_38) + 0x4));
    
    xmm1 = intrinsic_movss(xmm1, *(int32_t *)(this + 0x734));
    xmm1 = intrinsic_addss(xmm1, var_9C);
    xmm1 = intrinsic_addss(xmm1, var_70);
    xmm0 = intrinsic_ucomiss(xmm0, xmm1);
    if (xmm0 > 0x0) goto loc_100079f68;

loc_100079f43 :
    rax = *var_38;
    rax = (*(rax + 0xc0))(var_38);
    xmm0 = intrinsic_movss(xmm0, *(int32_t *)(this + 0x734));
    xmm0 = intrinsic_subss(xmm0, var_70);
    xmm0 = intrinsic_ucomiss(xmm0, *(int32_t *)(rax + 0x4));
    if (xmm0 <= 0x0) goto loc_1000793c0;

loc_100079f68 :
    *(int8_t *)(this + 0x4dd) = 0x1;
    r12 = r12 + 0x8;
    if (r12 <= rbx) goto loc_100079390;
    goto loc_10007a180;

loc_100079f82 :
    rdi = *(this + 0x180);
    rsi = *(int32_t *)(player + 0x36c);
    if (GJEffectManager::hasBeenTriggered(rdi, rsi) == 0x0) {
            rax = GJEffectManager::storeTriggeredID(*(this + 0x180), *(int32_t *)(player + 0x36c));
            rax = *player;
            rsi = this;
            rax = (*(rax + 0x4e0))(player, rsi);
    }
    rax = *player;
    xmm0 = 0x0;
    rax = (*(rax + 0x580))(player);
    rax = GameObject::destroyObject(player, rsi);
    r12 = r12 + 0x8;
    if (r12 <= rbx) goto loc_100079390;
    goto loc_10007a180;

loc_100079fe6 :
    rcx = 0x10007a638;
    rax = PlayLayer::playerWillSwitchMode(this, var_38, player, rcx);
    rdx = var_38;
    rax = PlayLayer::willSwitchToMode(this, 0x21, rdx);
    if (*(int8_t *)var_90 != 0x0) {
            this = *(this + 0x710);
            if (this == 0x0) {
                    this = player;
            }
    }
    else {
            this = player;
    }
    rax = *this;
    rax = (*(rax + 0xc0))(this);
    rax = cocos2d::CCPoint::CCPoint(var_A0, rax);
    rax = cocos2d::CCPoint::operator=(var_48, var_A0);
    *(var_38 + 0x7b8) = this;
    *(this + 0x708) = this;
    this = var_38;
    rax = PlayerObject::toggleSpiderMode(var_38, 0x1, rdx);
    goto loc_10007a15b;

loc_10007a02d :
    rax = PlayerObject::touchedObject(var_38, player, rdx);
    r12 = r12 + 0x8;
    if (r12 <= rbx) goto loc_100079390;
    goto loc_10007a180;

loc_1000795fb :
    
    r12 = r12 + 0x8;
    if (r12 <= rbx) goto loc_100079390;
    goto loc_10007a180;

loc_1000794b3 :
    rax = cocos2d::CCRect::getMinX(var_80);
    this = 0x1;
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
                            this = xmm1 > 0x0 ? 0x1 : 0x0;
                    }
            }
    }
    if ((this ^ 0x1) == 0x0) goto loc_100079565;
    goto loc_10007950e;

loc_10007944b :
    rdi = *(this + 0x568);
    goto loc_100079452;

loc_100078ee0 :
    rbx = this;
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
    xmm0 = intrinsic_movss(xmm0, *(int32_t *)((*(*player + 0xc0))(player) + 0x4));
    xmm0 = intrinsic_ucomiss(xmm0, var_60);
    if (xmm0 <= 0x0) goto loc_1000790a0;

loc_10007900c :
    if (player->isOnSlope2 == 0x0) goto loc_10007903b;

loc_100079016 :
    xmm0 = intrinsic_movss(xmm0, *(int32_t *)((*(*player + 0xc0))(player) + 0x4));
    xmm1 = intrinsic_movss(xmm1, var_50);
    xmm1 = intrinsic_addss(xmm1, var_60);
    xmm0 = intrinsic_ucomiss(xmm0, xmm1);
    if (xmm0 > 0x0) goto loc_1000790f3;

loc_10007903b :
    if ((this == 0x0) || (player->isUpsideDown != 0x0)) goto loc_10007904e;

loc_10007a546 :
    xmm0 = intrinsic_movss(xmm0, *(int32_t *)value 0.20);
    this = 0x1;
    if (PlayerObject::isSafeFlip(player) != 0x0) goto loc_100079051;

loc_10007a561 :
    xmm0 = intrinsic_movss(xmm0, *(int32_t *)value 0.20);
    if (sub_1002209b0(player) != 0x0) goto loc_100079051;

loc_1000790f3 :
    rax = PlayLayer::destroyPlayer(this, player, 0x0, rcx, r8, r9);
    goto loc_ret1;

loc_100079051 :
    var_90 = r15;
    rax = *player;
    r12 = *(rax + 0xb8);
    xmm0 = intrinsic_movss(xmm0, *(int32_t *)(*(rax + 0xc0))(player));
    xmm1 = intrinsic_movss(xmm1, var_60);
    rax = cocos2d::CCPoint::CCPoint(var_80, xmm0, xmm1);
    rax = (r12)(player, var_80);
    if (this != 0x0) {
            rax = PlayerObject::pushDown(player);
    }
    else {
            xmm0 = intrinsic_movsd(xmm0, *(player + 0x760));
            xmm1 = 0x0;
            xmm0 = intrinsic_ucomisd(xmm0, xmm1);
            if (xmm0 > 0x0) {
                    xmm0 = intrinsic_movss(xmm0, *(int32_t *)0x10050c978);
                    xmm0 = intrinsic_ucomiss(xmm0, var_40);
                    rcx = (player->isUpsideDown == 0x0 ? 0x1 : 0x0) | (xmm0 > 0x0 ? 0x1 : 0x0);
                    rax = PlayerObject::hitGround(player, rcx & 0xff, rdx);
            }
    }
    rsi = player->isUpsideDown & 0xff;
    rdx = 0x0;
    rax = PlayerObject::updateCollide(player, rsi, rdx, rcx);
    xmm0 = intrinsic_movss(xmm0, *(int32_t *)0x10050c978);
    xmm0 = intrinsic_ucomiss(xmm0, var_40);
    
    if (xmm0 > 0x0) {
            xmm0 = intrinsic_movsd(xmm0, *(player + 0x760));
            xmm1 = 0x0;
            xmm0 = intrinsic_ucomisd(xmm0, xmm1);
            if (xmm0 >= 0x0) {
                    rax = sub_10022dbf0(player, rsi);
            }
    }
    goto loc_10007929b;

loc_10007929b :
    player->isOnSlope2 = 0x0;
    goto loc_1000792a3;

loc_10007904e :
    this = 0x0;
    goto loc_100079051;

loc_1000790a0 :
    xmm0 = intrinsic_movss(xmm0, var_50);
    xmm0 = intrinsic_addss(xmm0, var_3C);
    xmm0 = intrinsic_subss(xmm0, var_58);
    var_58 = intrinsic_movss(var_58, xmm0);
    rax = *player;
    rax = (*(rax + 0xc0))(player);
    xmm0 = intrinsic_movss(xmm0, var_58);
    xmm0 = intrinsic_ucomiss(xmm0, *(int32_t *)(rax + 0x4));
    if (xmm0 <= 0x0) goto loc_100079106;

loc_1000790cc :
    if (player->isOnSlope2 == 0x0) goto loc_100079116;

loc_1000790d6 :
    rax = *player;
    rax = (*(rax + 0xc0))(player);
    xmm0 = intrinsic_movss(xmm0, var_58);
    xmm0 = intrinsic_subss(xmm0, var_50);
    xmm0 = intrinsic_ucomiss(xmm0, *(int32_t *)(rax + 0x4));
    if (xmm0 <= 0x0) goto loc_100079116;
    goto loc_1000790f3;

loc_100079116 :
    if ((this == 0x0) || (player->isUpsideDown == 0x0)) goto loc_1000791da;

loc_10007912d :
    xmm0 = intrinsic_movss(xmm0, *(int32_t *)value 0.20);
    this = 0x1;
    if (PlayerObject::isSafeFlip(player) != 0x0) goto loc_1000791dd;

loc_100079148 :
    xmm0 = intrinsic_movss(xmm0, *(int32_t *)value 0.20);
    if (sub_1002209b0(player) == 0x0) goto loc_1000790f3;

loc_1000791dd :
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
    goto loc_10007929b;

loc_1000791da :
    this = 0x0;
    goto loc_1000791dd;

loc_100079106 :
    var_90 = r15;
    
    goto loc_1000792a3;

loc_100078d5e :
    xmm0 = intrinsic_movss(xmm0, *(int32_t *)((*(*player + 0xc0))(player) + 0x4));
    xmm1 = intrinsic_movss(xmm1, *(int32_t *)0x10050d418);
    xmm1 = intrinsic_addss(xmm1, var_58);
    xmm0 = intrinsic_ucomiss(xmm0, xmm1);
    if (xmm0 <= 0x0) goto loc_100078e83;
}