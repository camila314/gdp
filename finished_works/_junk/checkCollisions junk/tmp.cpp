//loc_100078e83
/* 
	Register info
	var_30, this = this
    var_50 = ground height
	var_58 = cube size scalar
	var_3C= ground Y position
    var_64 = delta
	xmm0 = ypos
    r13 = player
*/

r14 = !player->isFlying() && !player->isBall && this->unknown_489;

if (player->isRestricted() || this->unknown_489) {
	//loc_100078ee0

    float ceiling; // xmm2
    float ground;
    if (this->unknown_489 != 0x0) {
            CCSize wSize = CCDirector::sharedDirector()->getWinSize(); // var_80 = width, var_7c = height

            groundPos = this->groundLayer2->getPosition(); // rax
            float difference = this->groundLayer1->getGroundY() - groundPos.y; // xmm0

            ceiling = this->cameraY + wSize.height - difference + 1;
            if (this->unknown_489 != 0x0) {
                    float pos = this->groundLayer1->getPosition();
                    ground = this->groundLayer1->getGroundY() + pos.y + this->cameraY - 1;
            }
    } else {
            ceiling = this->ceilingRestrictionY;
            ground = this->groundRestrictionY;
    }
    float localGround = this->groundRestrictionY; //var_48
    float restrictedSpace = ceiling - groundHeight + cubeSizeScalar;

    if (player->getPositionY() > restrictedSpace) {
		//loc_10007900c
	    if (player->isOnSlope2 && player->getPositionY() > ceiling + cubeSizeScalar) {
			//loc_100079016
            this->destroyPlayer(player, nullptr);
            return;
	    } else {
            bool shouldPush = false; // r14
            if (!player->isFlying() && !player->isBall && this->unknown_489 && !player->isUpsideDown) {
                //loc_10007a546
                shouldPushn = true;
                if (!player->isSafeFlip(0.2)) {
                    //loc_10007a561
                    if (!player->isSafeMode(0.2)) {
                        //loc_1000790f3
                        this->destroyPlayer(player, nullptr);
                        return;
                    }
                }
            }
            // loc_100079051

            player->setPositionY(restrictedSpace);

            if (shouldPush) { // r14
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
    	// loc_1000790a0
        float relativeGround = groundHeight + groundY - cubeSizeScalar; // var_58
        if (relativeGround > player->getPositionY()) {
            //loc_1000790cc
            if (player->isOnSlope2 && groundY - cubeSizeScalar > player->getPositionY()) {
                //loc_1000790d6
                this->destroyPlayer(player, nullptr);
                return;
            }
            //loc_100079116
            bool shouldPush; // r14
            if (!player->isFlying() && !player->isBall && this->unknown_489 && player->isUpsideDown) {
                //loc_10007912d :
                if (!player->isSafeFlip(0.2) && !player->isSafeMode(0.2)) {
                    //loc_100079148
                    this->destroyPlayer(player, nullptr);
                    return;
                }
                shouldPush = true;
            } else {
                shouldPush = false;
            }
            //loc_1000791dd

            player->setPositionY(relativeGround);
            if (shouldPush) {
                player->pushDown(player);
            } else {
                player->hitGround(ground- this->groundRestrictionY > 0.5 || player->isUpsideDown);
            }
            rsi = 0x0;
            rdx = 0x0;
            rax = player->updateCollide(!player->isUpsideDown, 0);
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
// loc_1000792a3

CCRect playerRect = player->getObjectRect(); // rbx
//var_60 = playerRect;

int section = this->sectionForPos(player->getPositionX());
//var_38 = player;
//loc_100079340
// loop #1 start


CCArray* sect;
for (int index = section-1; index <= section; index++) {

    if (0 > r15 >= this->sections->count()) {
        //loc_100079353
        CCArray* sect = this->sections->objectAtIndex(index); // rax
        if (sect) {
            //loc_10007936b
            if (sect->count() > 0) {

                //loc_10007937a
                //r12 = *(rax + 0x8);
                //rbx = r12 + rcx * 0x8 + 0xfffffffffffffff8;
                // note: anything "continue" means goto loc_1000793c0
                // loop #2 start
                CCARRAY_FOREACH(gameObj, sect) {
                    //loc_10007939d
                    int objectType = gameObj->objectType; // rax
                    if (!gameObj->unknown_27a && !gameObj->unknown_391 && (objectType <= 39 || !gameObj->hasBeenActivatedByPlayer(player))) {
                        switch (objectType) {
                            case 0:
                            case 21:
                                //loc_1000793e5
                                this->touchedSurfaces->addObject(gameObj);
                                break;
                            case 2: 
                                this->touchedHazards->addObject(gameObj);
                                break;
                            case 7:
                            case 39: 
                                break;
                            default: 
                                //loc_1000g
                                if (!gameObj->hasBeenActivatedByPlayer(player)) {
                                    //loc_1000793fe
                                    cocos2d::CCRect hitboxRect; // var_80
                                    if (objectType == 25) {
                                        hitboxRect = gameObj->getObjectRect(2., 2.);
                                    } else {
                                        hitboxRect = gameObj->getObjectRect();
                                    }

                                    // loc_1000794b3

                                    bool didCollide; // r14
                                    if (playerTouchesObject(playerRect, hiboxRect)) {
                                        didCollide = true;
                                    } else {
                                        didCollide = false;
                                    }
                                    if ( (didCollide && gameObj->hitboxSize > 0) || this->sub_1000b66e0(var_38, player)) {
                                        // var_38 = gameObj
                                        //loc_10007950e
                                        bool condition_r14 = true;
                                        if (gameObj->usesOrientedBox) {
                                            OBB2D* oldBox = gameObj->getOrientedBox(); // var_70
                                            gameObj->updateOrientedBox();
                                            OBB2D* newBox = gameObj->getOrientedBox(); // r14
                                            condition_r14 = oldBox->overlaps1Way(newBox);
                                        }
                                        if (objectType == 25) {
                                            hitboxRect = gameObj->getObjectRect();
                                        }
                                        if (condition_r14) {
                                            //loc_1000795b3
                                            objectType -= 3;
                                            // r14 = this
                                            if (objectType <= 37) {
                                                //loc_1000795ca
                                                switch (objectType) {
                                                    case kYellowGravity: // case 3
                                                        // loc_100079698
                                                        //r14 = player;
                                                        if (!player->isUpsideDown) {
                                                                rax = this->playGravityEffect(true);
                                                        }
                                                        player->portalCircleLocation = gameObj->getPosition();
                                                        player->portalCircleObject = gameObj;
                                                        rax = this->flipGravity(player, true, false);
                                                        gameObj->playShineEffect(r13);
                                                        gameObj->activatedByPlayer(player);
                                                        break;
                                                    case kBlueGravity: // case 4
                                                        // loc_100079727
                                                        if (player->isUpsideDown) {
                                                                this->playGravityEffect(false);
                                                        }
                                                        player->portalCircleLocation = gameObj->getPosition();
                                                        player->portalCircleObject = gameObj;
                                                        this->flipGravity(player, false, false);
                                                        gameObj->playShineEffect();
                                                        gameObj->activatedByPlayer(player);
                                                        break;
                                                    case kVehicleShip: // case 5
                                                        // loc_100079791
                                                        this->playerWillSwitchMode(player, gameObj);
                                                        this->switchToFlyMode(player, gameObj, false, 5);
                                                        gameObj->playShineEffect();
                                                        gameObj->activatedByPlayer(player);
                                                        break;
                                                    case kVehicleCube: // case 6
                                                        //loc_1000797b0
                                                        this->playerWillSwitchMode(player, gameObj);
                                                        player->portalCircleLocation = gameObj->getPosition();
                                                        player->portalCircleObject = gameObj;
                                                        this->willSwitchToMode(false, player);
                                                        player->modeDidChange();
                                                        gameObj->playShineEffect();
                                                        gameObj->activatedByPlayer(player);
                                                        break;
                                                    case kYellowBump: // case 8
                                                    case kPurpleBump: // case 9
                                                    case kRedBump: // case 34
                                                        this->bumpPlayer(player, gameObj);
                                                        break;
                                                    case kBlueBump: // case 10
                                                        //loc_100079810
                                                        if (player->isUpsideDown ^ !local_isPadUpsideDown(gameObj)) {
                                                            //loc_100079834
                                                            bool newDirection =  !player->isUpsideDown; // var_70
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
                                                    case kYellowRing: // case 11
                                                    case kPinkRing: // case 12
                                                    case kBlueRing: // case 13
                                                    case kRedRing: // case 35
                                                        this->playerTouchedRing(player, gameObj);
                                                        break;
                                                    case kFlipScreenPortal: // case 14
                                                        //loc_1000798f2
                                                        player->portalCircleLocation = gameObj->getPosition();
                                                        player->portalCircleObject = gameObj;
                                                        this->toggleFlipped(true, false);
                                                        gameObj->playShineEffect();
                                                        gameObj->triggerActivated(0.0);
                                                    case kUnflipScreenPortal: // case 15
                                                        //loc_100079933
                                                        player->portalCircleLocation = gameObj->getPosition();
                                                        player->portalCircleObject = gameObj;
                                                        this->toggleFlipped(false, false);
                                                        gameObj->playShineEffect();
                                                        gameObj->triggerActivated(0.0);
                                                    case kVehicleBall: // case 16
                                                        //loc_10007997e
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
                                                    case kScaleSmall: // case 17
                                                        //loc_1000799c5
                                                        player->portalCircleLocation = gameObj->getPosition();
                                                        player->portalCircleObject = gameObj;
                                                        player->togglePlayerScale(false);
                                                        gameObj->playShineEffect();
                                                        gameObj->activatedByPlayer(player);
                                                    case kScaleNormal: // case 18
                                                        //loc_1000799ff
                                                        player->portalCircleLocation = gameObj->getPosition();
                                                        player->portalCircleObject = gameObj;
                                                        player->togglePlayerScale(true);
                                                        gameObj->playShineEffect();
                                                        gameObj->activatedByPlayer(player);
                                                    case kVehicleBird: // case 19
                                                        //loc_100079a47
                                                        this->playerWillSwitchMode(player, gameObj);
                                                        this->switchToFlyMode(player, gameObj, false, 19);
                                                        gameObj->playShineEffect();
                                                        gameObj->activatedByPlayer(player);
                                                        break;
                                                    case kTrigger: // case 20
                                                        // loc_100079a66
                                                        if (gameObj->touchTriggered) {
                                                        //loc_100079a74
                                                            if (!this->effectManager->hasBeenTriggered(gameObj->uniqueID)) {
                                                                    rax = this->effectManager->storeTriggeredID(gameObj->uniqueID);
                                                                    gameObj->triggerObject(this);
                                                            }
                                                            // loc_100079b74
                                                            gameObj->triggerActivated(0.0);
                                                        }
                                                    case kSilverCoin: // case 31
                                                    case kGoldCoin: // case 22
                                                        //loc_100079632
                                                        if (!this->practiceMode) {
                                                            gameObj->triggerObject(this);
                                                            gameObj->triggerActivated(0.0);
                                                            gameObj->destroyObject();
                                                            if (!this->hasUniqueCoin(gameObj)) {
                                                                //loc_10007967b :
                                                                this->pickupItem(gameObj);
                                                            }
                                                        }
                                                        break;
                                                    case kDualOnPortal: // case 23
                                                        //loc_100079ab7
                                                        player->portalCircleLocation = gameObj->getPosition();
                                                        player->portalCircleObject = gameObj;
                                                        this->player2->unknown_7e0 = true;
                                                        this->toggleDualMode(r13, true, player, false);
                                                        this->player2->unknown_7e0 = false;
                                                        gameObj->playShineEffect();
                                                        gameObj->triggerActivated(0.0);
                                                        break;
                                                    case kDualOffPortal: // case 24
                                                        //loc_100079ab7
                                                        player->portalCircleLocation = gameObj->getPosition();
                                                        player->portalCircleObject = gameObj;
                                                        this->toggleDualMode(r13, false, player, false);
                                                        gameObj->playShineEffect();
                                                        gameObj->triggerActivated(0.0);
                                                        break;
                                                    case kSlope: // case 25
                                                        //loc_100079b96
                                                        rax = player->collidedWithSlope(delta, gameObj, false);
                                                        CCRect pRect = player->getObjectRect();
                                                        playerMaxX = pRect->getMaxX();
                                                        playerMinX = pRect->getMinX();
                                                        playerMaxY = pRect->getMaxY();
                                                        playerMinY = pRect->getMinY();
                                                        break;
                                                    case kVehicleDart: // case 26
                                                        //loc_100079c0a
                                                        this->playerWillSwitchMode(player, gameObj);
                                                        // loc_100079c24
                                                        this->switchToFlyMode(player, gameObj, false, 26);
                                                        gameObj->playShineEffect();
                                                        gameObj->activatedByPlayer(player);
                                                        break;
                                                    case kVehicleRobot: // case 27
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
                                                    case kTeleportPortal: // case 28
                                                        //loc_100079ca3
                                                        player->portalCircleLocation = gameObj->getPosition();
                                                        player->portalCircleObject = gameObj;
                                                        float newY = gameObj->getRealPosition().y + gameObj->teleportY; // xmm1
                                                        player->setPositionY(newY)
                                                        gameObj->playShineEffect();
                                                        gameObj->activatedByPlayer(player);
                                                        player->spawnPortalCircle(ccc3(255, 255, 0), 50.0);

                                                        GameObject* destObj = gameObj->teleportDestObject; // rdi
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
                                                                //0x79EC2
                                                        }
                                                        float something = 60.0; // xmm1
                                                        if (gameObj->unknown_508) {
                                                                this->cameraSmoothness = 0.5;
                                                                something = 180.0;
                                                        }
                                                        CCSize winSize = cocos2d::CCDirector::sharedDirector()->getWinSize();

                                                        player->playerTeleported();
                                                        if (player->getPositionY() <= this->cameraY + xmm1 + winSize.y && this->cameraY - player->getPositionY() > xmm1) {
                                                            //loc_100079f43
                                                            this->unknown_4dd = true;
                                                        }
                                                        //loc_100079f68
                                                        break;
                                                    case kCollectible: // case 30
                                                        //loc_100079f82
                                                        if (!this->effectManager->hasBeenTriggered(gameObj->uniqueID)) {
                                                            rax = this->effectManager->storeTriggeredID(gameObj->uniqueID);
                                                            gameObj->triggerObject(this);
                                                        }
                                                        gameObj->triggerObject(this);
                                                        gameObj->triggerActivated(0.0);
                                                        gameObj->destroyObject();
                                                        break;
                                                    case kVehicleSpider: // case 33
                                                        //loc_100079fe6
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

//loc_10007a191

//var_38 = player
//r14 = this
//r13 = player

rax, rdi, r12 = player;

bool loopCondition = player->unknown_540 && player->unknown_554;
GameObject* loopObject;
CCARRAY_FOREACH(loopObject, this->touchedSurfaces) { // r14
    if (!loopObject->getGroupDisabled()) {
            if (loopCondition && loopObjct->groupIDCount > 0) {
                loopCondition = player->testForMoving(delta, loopObject) ^ 0x1;
            }
            if (playerTouchesObject(player->getObjectRect(), loopObject->getObjectRect())) {
                player->collidedWithObject(delta, loopObject);
            }
    }
}
// r14 = this
this->touchedSurfaces->removeAllObjects();

playerRect = player->getObjectRect(); // var_60
player->updateOrientedBox();

CCARRAY_FOREACH(loopObject, this->touchedHazards) { // r13
    //rbx = 0;
    //r15 = var_80;
    //loc_10007a3e0
    if (!loopObject->getGroupDisabled()) {
        if ( (playerTouchesObject(playerRect, loopObject->getObjectRect()) && loopObject->hitboxRect <= 0.0) || sub_1000b66e0(1, player, loopObject)) {
            //loc_10007a499

            OBB2D* objBox = loopObject->getOrientedBox();
            OBB2D* playerBox = player->getOrientedBox();
            //loc_10007a4a3
            if (!loopObject->usesOrientedBox || (objBox->overlaps1Way(playerBox) && playerBox->overlaps1Way(objBox)) && !this->collisionsDisabled) {
                this->destroyPlayer(player, loopObject);
                return;
            }
        }
    }
}
//loc_10007a50f : // after loop
this->touchedHazards->removeAllObjects();
player->postCollision(delta);
return;