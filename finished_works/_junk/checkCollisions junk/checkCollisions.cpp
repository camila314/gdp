inline bool PlayerObject::isRestricted() {
    return this->isFlying() || this->isSpider || this->isBall;
}

inline bool playerTouchesObject(CCRect playerRect, CCRect hitboxRect) {
    float playerMaxX = playerRect->getMaxX();
    float playerMinX = playerRect->getMinX();
    float playerMaxY = playerRect->getMaxY();
    float playerMinY = playerRect->getMinY();

    float objMinX = hitboxRect->getMinX();
    float objMaxX = hitboxRect->getMaxX();
    float objMinY = hitboxRect->getMinY();
    float objMaxY = hitboxRect->getMaxY();

    return (objMinX <= playerMinX && objMaxX <= playerMaxX && objMinY <= playerMinY && objMaxY <= playerMaxY);

}

float _ZN9PlayLayer15checkCollisionsEPvP12PlayerObjectf(PlayerObject* player, float delta) {
    
    player->preCollision();
    float groundHeight = player->groundHeight;

    float cubeSizeScalar;
    if (player->vehicleSize == 1.0) {
            cubeSizeScalar = 0.0;
    }
    else {
            cubeSizeScalar = (1.0 - player->vehicleSize) * groundHeight * 0.5;
    }
    groundHeight /= 2;
    float groundY = 90.0 + groundHeight - xmm2;

    float ypos = player->getPositionY();
    if (player->getPositionY() >= groundY || player->isRestricted() || this->unknown_489 || !player->isUpsideDown) {
        if (ypos > 2790.0 + cubeSizeScalar) {
            return;
        }
        if(!player->isUpsideDown && !player->isRising) {
            player->setPositionY(groundY);
            player->hitGround(false);
            player->updateCollide(player, true, 0);
            player->isOnSlope2 = false;
        }

        r14 = !player->isFlying() && !player->isBall && this->unknown_489;

        if (player->isRestricted() || this->unknown_489) {

            float ceiling;
            float ground;
            if (this->unknown_489 != 0x0) {
                    CCSize wSize = CCDirector::sharedDirector()->getWinSize();

                    groundPos = this->groundLayer2->getPosition();
                    float difference = this->groundLayer1->getGroundY() - groundPos.y;

                    ceiling = this->cameraY + wSize.height - difference + 1;
                    if (this->unknown_489 != 0x0) {
                            float pos = this->groundLayer1->getPosition();
                            ground = this->groundLayer1->getGroundY() + pos.y + this->cameraY - 1;
                    }
            } else {
                    ceiling = this->ceilingRestrictionY;
                    ground = this->groundRestrictionY;
            }
            float localGround = this->groundRestrictionY;
            float restrictedSpace = ceiling - groundHeight + cubeSizeScalar;

            if (player->getPositionY() > restrictedSpace) {
                if (player->isOnSlope2 && player->getPositionY() > ceiling + cubeSizeScalar) {
                    this->destroyPlayer(player, nullptr);
                    return;
                } else {
                    bool shouldPush = false;
                    if (!player->isFlying() && !player->isBall && this->unknown_489 && !player->isUpsideDown) {
                        shouldPushn = true;
                        if (!player->isSafeFlip(0.2)) {
                            if (!player->isSafeMode(0.2)) {
                                this->destroyPlayer(player, nullptr);
                                return;
                            }
                        }
                    }

                    player->setPositionY(restrictedSpace);

                    if (shouldPush) {
                        player->pushDown();
                    } else if (player->yAccel > 0) {
                        player->hitGround(!player->isUpsideDown() || -5.0 > ceiling - this->ceilingRestrictionY);
                    }

                    player->updateCollide(player->isUpsideDown, 0);

                    if (-5.0 > ceiling - this->ceilingRestrictionY) {
                            if (player->yAccel >= 0) {
                                    player->specialGroundHit();
                            }
                    }
                    player->isOnSlope2 = false;
                }
            } else {
                float relativeGround = groundHeight + groundY - cubeSizeScalar;
                if (relativeGround > player->getPositionY()) {
                    if (player->isOnSlope2 && groundY - cubeSizeScalar > player->getPositionY()) {
                        this->destroyPlayer(player, nullptr);
                        return;
                    }
                    bool shouldPush;
                    if (!player->isFlying() && !player->isBall && this->unknown_489 && player->isUpsideDown) {
                        if (!player->isSafeFlip(0.2) && !player->isSafeMode(0.2)) {
                            this->destroyPlayer(player, nullptr);
                            return;
                        }
                        shouldPush = true;
                    } else {
                        shouldPush = false;
                    }

                    player->setPositionY(relativeGround);
                    if (shouldPush) {
                        player->pushDown(player);
                    } else {
                        player->hitGround(ground- this->groundRestrictionY > 0.5 || player->isUpsideDown);
                    }
                    player->updateCollide(!player->isUpsideDown, 0);
                    if (ground - this->groundRestrictionY > 0.5) {
                            if (player->yAccel <= 0) {
                                    player->specialGroundHit();
                            }
                    }
                    player->isOnSlope2 = false;
                }
            }
        }

        var_90 = this->unknown_489;

        CCRect playerRect = player->getObjectRect();

        int section = this->sectionForPos(player->getPositionX());


        CCArray* sect;
        for (int index = section-1; index <= section; index++) {

            if (0 > r15 >= this->sections->count()) {
                CCArray* sect = this->sections->objectAtIndex(index);
                if (sect) {
                    if (sect->count() > 0) {
                        CCARRAY_FOREACH(gameObj, sect) {
                            int objectType = gameObj->objectType;
                            if (!gameObj->unknown_27a && !gameObj->unknown_391 && (objectType <= 39 || !gameObj->hasBeenActivatedByPlayer(player))) {
                                switch (objectType) {
                                    case 0:
                                    case 21:
                                        this->touchedSurfaces->addObject(gameObj);
                                        break;
                                    case 2: 
                                        this->touchedHazards->addObject(gameObj);
                                        break;
                                    case 7:
                                    case 39: 
                                        break;
                                    default: 
                                        if (!gameObj->hasBeenActivatedByPlayer(player)) {
                                            cocos2d::CCRect hitboxRect;
                                            if (objectType == 25) {
                                                hitboxRect = gameObj->getObjectRect(2., 2.);
                                            } else {
                                                hitboxRect = gameObj->getObjectRect();
                                            }

                                            bool didCollide;
                                            if (playerTouchesObject(playerRect, hiboxRect)) {
                                                didCollide = true;
                                            } else {
                                                didCollide = false;
                                            }
                                            if ( (didCollide && gameObj->hitboxSize > 0) || this->sub_1000b66e0(var_38, player)) {
                                                bool condition_r14 = true;
                                                if (gameObj->unknown_2b8) {
                                                    OBB2D* oldBox = gameObj->getOrientedBox();
                                                    gameObj->updateOrientedBox();
                                                    OBB2D* newBox = gameObj->getOrientedBox();
                                                    condition_r14 = oldBox->overlaps1Way(newBox);
                                                }
                                                if (objectType == 25) {
                                                    hitboxRect = gameObj->getObjectRect();
                                                }
                                                if (condition_r14) {
                                                    objectType -= 3;
                                                    if (objectType <= 37) {
                                                        switch (objectType) {
                                                            case kYellowGravity:
                                                                if (!player->isUpsideDown) {
                                                                        this->playGravityEffect(true);
                                                                }
                                                                player->portalCircleLocation = gameObj->getPosition();
                                                                player->portalCircleObject = gameObj;
                                                                this->flipGravity(player, true, false);
                                                                gameObj->playShineEffect(r13);
                                                                gameObj->activatedByPlayer(player);
                                                                break;
                                                            case kBlueGravity:
                                                                if (player->isUpsideDown) {
                                                                        this->playGravityEffect(false);
                                                                }
                                                                player->portalCircleLocation = gameObj->getPosition();
                                                                player->portalCircleObject = gameObj;
                                                                this->flipGravity(player, false, false);
                                                                gameObj->playShineEffect();
                                                                gameObj->activatedByPlayer(player);
                                                                break;
                                                            case kVehicleShip:
                                                                this->playerWillSwitchMode(player, gameObj);
                                                                this->switchToFlyMode(player, gameObj, false, 5);
                                                                gameObj->playShineEffect();
                                                                gameObj->activatedByPlayer(player);
                                                                break;
                                                            case kVehicleCube:
                                                                this->playerWillSwitchMode(player, gameObj);
                                                                player->portalCircleLocation = gameObj->getPosition();
                                                                player->portalCircleObject = gameObj;
                                                                this->willSwitchToMode(false, player);
                                                                player->modeDidChange();
                                                                gameObj->playShineEffect();
                                                                gameObj->activatedByPlayer(player);
                                                                break;
                                                            case kYellowBump:
                                                            case kPurpleBump:
                                                            case kRedBump:
                                                                this->bumpPlayer(player, gameObj);
                                                                break;
                                                            case kBlueBump:
                                                                if (player->isUpsideDown ^ !local_isPadUpsideDown(gameObj)) {
                                                                    bool newDirection =  !player->isUpsideDown;
                                                                    this->playGravityEffect(newDirection);

                                                                    CCPoint objPosition = gameObj->getPosition();
                                                                    objPosition.y -= 10;
                                                                    player->portalCircleLocation = objPosition;
                                                                    player->portalCircleObject = gameObj;

                                                                    gameObj->activatedByPlayer(player);
                                                                    player->propellPlayer(0.8);
                                                                    this->flipFravity(player, newDirection, true);
                                                                    player->unknown_628 = true;
                                                                }
                                                                break;
                                                            case kYellowRing:
                                                            case kPinkRing:
                                                            case kBlueRing:
                                                            case kRedRing:
                                                                this->playerTouchedRing(player, gameObj);
                                                                break;
                                                            case kFlipScreenPortal:
                                                                player->portalCircleLocation = gameObj->getPosition();
                                                                player->portalCircleObject = gameObj;
                                                                this->toggleFlipped(true, false);
                                                                gameObj->playShineEffect();
                                                                gameObj->triggerActivated(0.0);
                                                            case kUnflipScreenPortal:
                                                                player->portalCircleLocation = gameObj->getPosition();
                                                                player->portalCircleObject = gameObj;
                                                                this->toggleFlipped(false, false);
                                                                gameObj->playShineEffect();
                                                                gameObj->triggerActivated(0.0);
                                                            case kVehicleBall:
                                                                this->playerWillSwitchMode(player, gameObj);
                                                                this->willSwitchToMode(16, player);
                                                                if (this->unknown_489) {
                                                                    GameObject* what = *(this + 0x710);
                                                                    if (what) {
                                                                            gameObj = what;
                                                                    }
                                                                }
                                                                player->portalCircleLocation = gameObj->getPosition();
                                                                player->portalCircleObject = gameObj;
                                                                this->unknown_708 = gameObj;

                                                                player->toggleRollMode(true);
                                                                gameObj->playShineEffect();
                                                                gameObj->activatedByPlayer(player);
                                                            case kScaleSmall:
                                                                player->portalCircleLocation = gameObj->getPosition();
                                                                player->portalCircleObject = gameObj;
                                                                player->togglePlayerScale(false);
                                                                gameObj->playShineEffect();
                                                                gameObj->activatedByPlayer(player);
                                                            case kScaleNormal:
                                                                player->portalCircleLocation = gameObj->getPosition();
                                                                player->portalCircleObject = gameObj;
                                                                player->togglePlayerScale(true);
                                                                gameObj->playShineEffect();
                                                                gameObj->activatedByPlayer(player);
                                                            case kVehicleBird:
                                                                this->playerWillSwitchMode(player, gameObj);
                                                                this->switchToFlyMode(player, gameObj, false, 19);
                                                                gameObj->playShineEffect();
                                                                gameObj->activatedByPlayer(player);
                                                                break;
                                                            case kTrigger:
                                                                if (gameObj->touchTriggered) {
                                                                    if (!this->effectManager->hasBeenTriggered(gameObj->uniqueID)) {
                                                                            this->effectManager->storeTriggeredID(gameObj->uniqueID);
                                                                            gameObj->triggerObject(this);
                                                                    }
                                                                    gameObj->triggerActivated(0.0);
                                                                }
                                                            case kSilverCoin:
                                                            case kGoldCoin:
                                                                if (!this->practiceMode) {
                                                                    gameObj->triggerObject(this);
                                                                    gameObj->triggerActivated(0.0);
                                                                    gameObj->destroyObject();
                                                                    if (!this->hasUniqueCoin(gameObj)) {
                                                                        this->pickupItem(gameObj);
                                                                    }
                                                                }
                                                                break;
                                                            case kDualOnPortal:
                                                                player->portalCircleLocation = gameObj->getPosition();
                                                                player->portalCircleObject = gameObj;
                                                                this->player2->unknown_7e0 = true;
                                                                this->toggleDualMode(r13, true, player, false);
                                                                this->player2->unknown_7e0 = false;
                                                                gameObj->playShineEffect();
                                                                gameObj->triggerActivated(0.0);
                                                                break;
                                                            case kDualOffPortal:
                                                                player->portalCircleLocation = gameObj->getPosition();
                                                                player->portalCircleObject = gameObj;
                                                                this->toggleDualMode(r13, false, player, false);
                                                                gameObj->playShineEffect();
                                                                gameObj->triggerActivated(0.0);
                                                                break;
                                                            case kSlope:
                                                                player->collidedWithSlope(delta, gameObj, false);
                                                                CCRect pRect = player->getObjectRect();
                                                                playerMaxX = pRect->getMaxX();
                                                                playerMinX = pRect->getMinX();
                                                                playerMaxY = pRect->getMaxY();
                                                                playerMinY = pRect->getMinY();
                                                                break;
                                                            case kVehicleDart:
                                                                this->playerWillSwitchMode(player, gameObj);
                                                                this->switchToFlyMode(player, gameObj, false, 26);
                                                                gameObj->playShineEffect();
                                                                gameObj->activatedByPlayer(player);
                                                                break;
                                                            case kVehicleRobot:
                                                                this->playerWillSwitchMode(player, gameObj);
                                                                this->willSwitchToMode(27, player);
                                                                if (this->unknown_489) {
                                                                    GameObject* what = *(this + 0x710);
                                                                    if (what) {
                                                                            gameObj = what;
                                                                    }
                                                                }
                                                                player->portalCircleLocation = gameObj->getPosition();
                                                                player->portalCircleObject = gameObj;
                                                                this->unknown_708 = gameObj;

                                                                player->toggleRobotModeMode(true);
                                                                gameObj->playShineEffect();
                                                                gameObj->activatedByPlayer(player);
                                                                break;
                                                            case kTeleportPortal:
                                                                player->portalCircleLocation = gameObj->getPosition();
                                                                player->portalCircleObject = gameObj;
                                                                float newY = gameObj->getRealPosition().y + gameObj->teleportY;
                                                                player->setPositionY(newY)
                                                                gameObj->playShineEffect();
                                                                gameObj->activatedByPlayer(player);
                                                                player->spawnPortalCircle(ccc3(255, 255, 0), 50.0);

                                                                GameObject* destObj = gameObj->teleportDestObject;
                                                                if (destObj) {
                                                                        player->portalCircleLocation = destObj->getPosition();
                                                                        player->portalCircleObject = destObj;
                                                                        destObj->playShineEffect();
                                                                        player->spawnPortalCircle(ccc3(0, 200, 255), 50.0);
                                                                        player->resetStreak();
                                                                        if (player->isDart) {
                                                                            player->addStreakPoint();
                                                                        }
                                                                        this->lightningFlash(gameObj->getPosition(), destObj->getPosition(), player->glowColor, 4.0, 0.2, 100, true, 1.0);
                                                                }
                                                                float something = 60.0;
                                                                if (gameObj->unknown_508) {
                                                                        this->cameraSmoothness = 0.5;
                                                                        something = 180.0;
                                                                }
                                                                CCSize winSize = cocos2d::CCDirector::sharedDirector()->getWinSize();

                                                                player->playerTeleported();
                                                                if (player->getPositionY() <= this->cameraY + xmm1 + winSize.y && this->cameraY - player->getPositionY() > xmm1) {
                                                                    this->unknown_4dd = true;
                                                                }
                                                                break;
                                                            case kCollectible:
                                                                if (!this->effectManager->hasBeenTriggered(gameObj->uniqueID)) {
                                                                    this->effectManager->storeTriggeredID(gameObj->uniqueID);
                                                                    gameObj->triggerObject(this);
                                                                }
                                                                gameObj->triggerObject(this);
                                                                gameObj->triggerActivated(0.0);
                                                                gameObj->destroyObject();
                                                                break;
                                                            case kVehicleSpider:
                                                                this->playerWillSwitchMode(player, gameObj);
                                                                this->willSwitchToMode(33, player);
                                                                if (this->unknown_489) {
                                                                    GameObject* what = this->unknown_710;
                                                                    if (what) {
                                                                        gameObj = what;
                                                                    }
                                                                }
                                                                player->portalCircleLocation = gameObj->getPosition();
                                                                player->portalCircleObject = gameObj;
                                                                this->unknown_708 = gameObj;

                                                                player->toggleSpiderMode(true);
                                                                gameObj->playShineEffect();
                                                                gameObj->activatedByPlayer(player);
                                                                break;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                        break;
                                }
                            }
                        }
                    }
                }
            }
        }

        bool loopCondition = player->unknown_540 && player->unknown_554;
        GameObject* loopObject;
        CCARRAY_FOREACH(loopObject, this->touchedSurfaces) {
            if (!loopObject->getGroupDisabled()) {
                    if (loopCondition && loopObjct->groupIDCount > 0) {
                        loopCondition = player->sub_10021eb70(loopObject, delta) ^ 0x1;
                    }
                    if (playerTouchesObject(player->getObjectRect(), loopObject->getObjectRect())) {
                        player->collidedWithObject(delta, loopObject);
                    }
            }
        }
        this->touchedSurfaces->removeAllObjects();

        playerRect = player->getObjectRect();
        player->updateOrientedBox();

        CCARRAY_FOREACH(loopObject, this->touchedHazards) {
            if (!loopObject->getGroupDisabled()) {
                if ( (playerTouchesObject(playerRect, loopObject->getObjectRect()) && loopObject->hitboxRect <= 0.0) || sub_1000b66e0(1, player, loopObject)) {

                    OBB2D* objBox = loopObject->getOrientedBox();
                    OBB2D* playerBox = player->getOrientedBox();
                    if (loopObject->unknown_2b8) {
                        if (objBox->overlaps1Way(playerBox) && playerBox->overlaps1Way(objBox) || (loopObject->unknown_2b8 && !this->unknown_700)) {
                            this->destroyPlayer(player, loopObject);
                            return;
                        }
                    }
                }
            }
        }
        this->touchedHazards->removeAllObjects();
        player->postCollision(delta);
        return;
    } else if (!player->isSafeFlip()) {
        this->destroyPlayer(player, nullptr);
        return;
    } else {
        player->setPositionY(groundY);
        player->hitGround(true);
        player->updateCollide(false, 0);
        player->isSliding = false;
        player->isOnSlope2 = 0x0;
        return;
    }
}