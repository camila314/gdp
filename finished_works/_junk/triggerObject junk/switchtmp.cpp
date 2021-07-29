case kExitEffectNone:
    this->exitEffectType = 1;
    break;
case kExitEffect1:
    //loc_1000c9d42
    this->exitEffectType = 5;
    break;
case kExitEffect2:
    //loc_1000c9d52
    this->exitEffectType = 4;
    break;
case kExitEffect3:
    //loc_1000c9d62
    this->exitEffectType = 6;
    break;
case kExitEffect4:
    //loc_1000c9d72
    this->exitEffectType = 7;
    break;
case kExitEffect5:
    //loc_1000c9d82
    this->exitEffectType = 2;
    break;
case kExitEffect6: 
    //loc_1000c9d92
    this->exitEffectType = 3;
    break;
case kBgColor:
case kGroundColor:
case kLine3DColor:
case kLineColor:
case kObjColor:
    //loc_1000c9a72;
    gameLayer->updateColor(
        this->color, this->duration, this->colorID, this->blending,
        this->opacity, this->hsvData, this->channelID,
        this->copyOpacity, this->uuid, this
    );
    if (this->objectID == kBgColor && this->tintGround) {
        gameLayer->updateColor(
            this->color, this->duration, 1001, false, this->opacity, this->hsvData,
            this->channelID, this->copyOpacity, this->uuid, this
        );
    }
    break;
case kEnableGhost:
case kDisableGhost:
    if (!this->inEditorMode) {
        //loc_1000c9ddd
        GameManager::sharedState()->playLayer->toggleGhostEffect(this->objectID == kEnableGhost);
    }
    break;
case kExitEffect7:
    //loc_1000c9de6
    this->exitEffectType = 10;
    break;
case kExitEffect8:
    //loc_1000c9df6
    this->exitEffectType = 9;
    break;
case kExitEffect9:
    //loc_1000c9e06
    this->exitEffectType = 8;
    break;
case kExitEffect10:
    //loc_1000c9e16
    this->exitEffectType = 11;
    break;
case kExitEffect11:
    //loc_1000c9e26
    this->exitEffectType = 12;
    break;
case kPulse:
    //loc_1000c9bde
    gameLayer->effectManager->runPulseEffect(
        this->targetedGroupID, this->pulseTarget, this->fadeIn,
        this->hold, this->fadeOut, this->pulseMode+1, this->color,
        this->hsvData, this->channelID, this->mainOnly, this->detailOnly,
        this->exclusive, this->uuid
    );
    break;
case kAlpha:
    //loc_1000c9a46
    gameLayer->effectManager->runOpacityActionOnGroup(this->targetedGroupID, this->duration, this->opacity, this->uuid);
    break;
case kToggle:
    //loc_1000c998a
    gameLayer->toggleGroup(this->targetedGroupID, this->toggleOn);
    break;
case kSpawn:
    //loc_1000c99a0;
    gameLayer->spawnGroupTriggered(this->targetedGroupID, this->spawnDelay, this->uuid);
    break;
case kRotate:
    //loc_1000c9c81
    gameLayer->effectManager->createRotateCommand(
        (this->times360 * 360) + this->rotateDegrees,
        this->duration, this->targetedGroupID,
        this->targetedGroupID2, this->easingType,
        this->easingAmount, this->lockObjectRotation,
        this->uuid
    );
    break;
case kFollow:
    //loc_1000c9b7e
    this->unknown_538 = true;

    gameLayer->effectManager->createFollowCommand(
        this->followXMod, this->followYMod, this->duration,
        this->targetedGroupID, this->targetedGroupID2, true, this->uuid
    );
    break;
case kShake:
    //loc_1000c9ce3
    if (!this->inEditorMode && this->duration > 0 && this->shakeStrength > 0) {
        GameManager::sharedState()->playLayer->shakeCamera(this->duration, this->shakeStrength, this->shakeInterval);
    }
    break;
case kMove:
    //loc_1000c9a1a
    gameLayer->triggerMoveCommand(this);
    break;
case kAnimate:
    //loc_1000c9926
    if (!this->inEditorMode) { 
        GameManager::sharedState()->playLayer->playAnimationCommand(this->animationID, this->targetGroupID);
    }
    break;
case kTouch:
    //loc_1000c9f5d
    gameLayer->effectManager->runTouchTriggerCommand(
        this->targetedGroupID, this->touchHoldMode, 
        this->touchToggleMode, this->touchDualMode, this->uuid
    );
    break;
case kCount:
    //loc_1000c9f8f
    gameLayer->effectManager->runCountTrigger(
        this->itemID, this->targetCount, this->countMultiActivate,
        this->targetedGroupID, this->toggleOn, this->uuid
    );
    break;
case kHidePlayer:
case kShowPlayer:
    //loc_1000c9fda
    gameLayer->togglePlayerVisibility(this->objectID == kShowPlayer);
    break;
case kInstantCount:
    //loc_1000c99d0
    gameLayer->testInstantCountTrigger(
        this->itemID, this->targetCount, 
        this->targetedGroupID, this->toggleOn, this->compareType
    );
    break;
case kOnDeath:
    //loc_1000c9e45
    if (!this->inEditorMode) {
            GameManager::sharedState()->playLayer
                                      ->effectManager
                                      ->runDeathTrigger(this->targetedGroupID, this->toggleOn, this->uuid);
    }
    break;
case kFollowPlayerY:
    //loc_1000c9e81
    gameLayer->effectManager->createPlayerFollowCommand(
        this->followSpeed, this->followDelay, this->followOffset,
        this->followMaxSpeed, this->duration, this->targetedGroupID, this->uuid
    );
    break;
case kCollision:
    //loc_1000c9ec3
    gameLayer->effectManager->registerCollisionTrigger(
        this->targetedGroupID, this->itemID, this->blockBID, 
        this->triggerOnCollisionExit, this->toggleOn, this->uuid
    );
    break;
case kPickup:
    //loc_1000c9f01
    gameLayer->collectItem(this->itemID, this->targetCount);
    break;
case kBGEffectOn:
case kBGEffectOff:
    if (!this->inEditorMode) {
        //loc_1000c9f54
        GameManager::sharedState()->playLayer->toggleBGEffectVisibility(this->objectID == kBGEffectOn);
    }
    break;
default:
    this->triggerObject(gameLayer);