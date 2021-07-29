void EffectGameObject::triggerObject(GJBaseGameLayer* gameLayer) {
    if (this->objectType == kCollectible) {
        if (this->collectibleMode == 2) {
            gameLayer->toggleGroupTriggered(this->targetedGroupID, this->toggleOn);
        } else if (this->collectibleMode == 1) {
            gameLayer->collectedObject(this);
        }
        return;
    }

    switch (this->objectID) {
        case kExitEffectNone:
            this->exitEffectType = 1;
            break;
        case kExitEffect1:
            this->exitEffectType = 5;
            break;
        case kExitEffect2:
            this->exitEffectType = 4;
            break;
        case kExitEffect3:
            this->exitEffectType = 6;
            break;
        case kExitEffect4:
            this->exitEffectType = 7;
            break;
        case kExitEffect5:
            this->exitEffectType = 2;
            break;
        case kExitEffect6: 
            this->exitEffectType = 3;
            break;
        case kBgColor:
        case kGroundColor:
        case kLine3DColor:
        case kLineColor:
        case kObjColor:
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
                GameManager::sharedState()->playLayer->toggleGhostEffect(this->objectID == kEnableGhost);
            }
            break;
        case kExitEffect7:
            this->exitEffectType = 10;
            break;
        case kExitEffect8:
            this->exitEffectType = 9;
            break;
        case kExitEffect9:
            this->exitEffectType = 8;
            break;
        case kExitEffect10:
            this->exitEffectType = 11;
            break;
        case kExitEffect11:
            this->exitEffectType = 12;
            break;
        case kPulse:
            gameLayer->effectManager->runPulseEffect(
                this->targetedGroupID, this->pulseTarget, this->fadeIn,
                this->hold, this->fadeOut, this->pulseMode+1, this->color,
                this->hsvData, this->channelID, this->mainOnly, this->detailOnly,
                this->exclusive, this->uuid
            );
            break;
        case kAlpha:
            gameLayer->effectManager->runOpacityActionOnGroup(this->targetedGroupID, this->duration, this->opacity, this->uuid);
            break;
        case kToggle:
            gameLayer->toggleGroup(this->targetedGroupID, this->toggleOn);
            break;
        case kSpawn:
            gameLayer->spawnGroupTriggered(this->targetedGroupID, this->spawnDelay, this->uuid);
            break;
        case kRotate:
            gameLayer->effectManager->createRotateCommand(
                (this->times360 * 360) + this->rotateDegrees,
                this->duration, this->targetedGroupID,
                this->targetedGroupID2, this->easingType,
                this->easingAmount, this->lockObjectRotation,
                this->uuid
            );
            break;
        case kFollow:
            this->unknown_538 = true;

            gameLayer->effectManager->createFollowCommand(
                this->followXMod, this->followYMod, this->duration,
                this->targetedGroupID, this->targetedGroupID2, true, this->uuid
            );
            break;
        case kShake:
            if (!this->inEditorMode && this->duration > 0 && this->shakeStrength > 0) {
                GameManager::sharedState()->playLayer->shakeCamera(this->duration, this->shakeStrength, this->shakeInterval);
            }
            break;
        case kMove:
            gameLayer->triggerMoveCommand(this);
            break;
        case kAnimate:
            if (!this->inEditorMode) { 
                GameManager::sharedState()->playLayer->playAnimationCommand(this->animationID, this->targetGroupID);
            }
            break;
        case kTouch:
            gameLayer->effectManager->runTouchTriggerCommand(
                this->targetedGroupID, this->touchHoldMode, 
                this->touchToggleMode, this->touchDualMode, this->uuid
            );
            break;
        case kCount:
            gameLayer->effectManager->runCountTrigger(
                this->itemID, this->targetCount, this->countMultiActivate,
                this->targetedGroupID, this->toggleOn, this->uuid
            );
            break;
        case kHidePlayer:
        case kShowPlayer:
            gameLayer->togglePlayerVisibility(this->objectID == kShowPlayer);
            break;
        case kInstantCount:
            gameLayer->testInstantCountTrigger(
                this->itemID, this->targetCount, 
                this->targetedGroupID, this->toggleOn, this->compareType
            );
            break;
        case kOnDeath:
            if (!this->inEditorMode) {
                    GameManager::sharedState()->playLayer
                                              ->effectManager
                                              ->runDeathTrigger(this->targetedGroupID, this->toggleOn, this->uuid);
            }
            break;
        case kFollowPlayerY:
            gameLayer->effectManager->createPlayerFollowCommand(
                this->followSpeed, this->followDelay, this->followOffset,
                this->followMaxSpeed, this->duration, this->targetedGroupID, this->uuid
            );
            break;
        case kCollision:
            gameLayer->effectManager->registerCollisionTrigger(
                this->targetedGroupID, this->itemID, this->blockBID, 
                this->triggerOnCollisionExit, this->toggleOn, this->uuid
            );
            break;
        case kPickup:
            gameLayer->collectItem(this->itemID, this->targetCount);
            break;
        case kBGEffectOn:
        case kBGEffectOff:
            if (!this->inEditorMode) {
                GameManager::sharedState()->playLayer->toggleBGEffectVisibility(this->objectID == kBGEffectOn);
            }
            break;
        default:
            this->triggerObject(gameLayer);
    }
}