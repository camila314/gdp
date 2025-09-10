void __thiscall PlayLayer::postUpdate(PlayLayer *this,float param_1) {
    long lVar1;
    bool gameVar;
    GameManager *gm;
    CheckpointObject *check;
    GameObject *mainObj;
    GameObject *checkObj;
    cocos2d::CCPoint *playerPos;
    CheckpointGameObject *activated;
    PlayerCheckpoint *playerCheck;
    code *pcVar2;
    cocos2d::CCPoint cStack_28;
    cocos2d::CCRect local_20;
    int centerGroup;
    
    lVar1 = ___stack_chk_guard;
    if (this->m_skipAudioStep == false) {
        AudioEffectsLayer::audioStep(this->m_audioEffectsLayer,param_1);
    }
    if (this->m_tryPlaceCheckpoint != false) {
        this->m_tryPlaceCheckpoint = false;
        markCheckpoint(this);
    }
    if (this->m_activatedCheckpoint != (CheckpointGameObject *)0x0) {
        gm = (GameManager *)GameManager::sharedState();
        gameVar = GameManager::getGameVariable(gm,"0146");
        if ((gameVar) || (check = markCheckpoint(this), check == (CheckpointObject *)0x0)) {
            activated = this->m_activatedCheckpoint;
        }
        else {
            (**(code **)(*(long *)this->m_activatedCheckpoint + 0x540))
                      (&cStack_28,this->m_activatedCheckpoint);
            if (this->m_activatedCheckpoint->m_targetPlayer1 == false) {
                centerGroup = this->m_activatedCheckpoint->m_centerGroupID;
                if ((centerGroup > 0) &&
                   (mainObj = GJBaseGameLayer::tryGetMainObject((GJBaseGameLayer *)this,centerGroup)
                   , mainObj != (GameObject *)0x0)) {
                    (**(code **)(*(long *)mainObj + 0x540))(&local_20);
                    cocos2d::CCPoint::operator=(&cStack_28,&local_20.origin);
                }
            }
            else {
                playerPos = (cocos2d::CCPoint *)
                            (**(code **)(*(long *)this->m_player1 + 0xc0))(this->m_player1);
                cocos2d::CCPoint::operator=(&cStack_28,playerPos);
            }
            checkObj = CheckpointObject::getObject(check);
            pcVar2 = *(code **)(*(long *)checkObj + 0x548);
            cocos2d::CCPoint::CCPoint(&local_20.origin,&cStack_28);
            (*pcVar2)(checkObj,&local_20);
            playerCheck = check->m_player1Checkpoint;
            cocos2d::CCPoint::CCPoint(&local_20.origin,&cStack_28);
            cocos2d::CCPoint::operator=(&playerCheck->m_position,&local_20.origin);
            check->m_player1Checkpoint->m_platformerCheckpoint = true;
            mainObj = CheckpointObject::getObject(check);
            GameObject::makeInvisible(mainObj);
            activated = this->m_activatedCheckpoint;
            check->m_uniqueID = activated->m_uniqueID;
            check->m_respawnID = activated->m_respawnID;
        }
        if (activated->m_targetGroupID > 0) {
            local_20.origin.x = 0.0;
            local_20.origin.y = 0.0;
            local_20.size.width = 0.0;
            local_20.size.height = 0.0;
                    /* try { // try from 006d7d50 to 006d7d53 has its CatchHandler @ 006d7f14 */
            (**(code **)(*(long *)this + 0x4d0))
                      (0,this,activated->m_targetGroupID,0,&local_20,activated->m_uniqueID,
                       activated->m_controlID);
            if (local_20.origin != (cocos2d::CCPoint)0x0) {
                operator.delete(local_20.origin.x);
            }
        }
        GJBaseGameLayer::gameEventTriggered((GJBaseGameLayer *)this,0x3c,0,0);
        this->m_activatedCheckpoint = (CheckpointGameObject *)0x0;
    }
    (**(code **)(*(long *)this + 0x498))(param_1,this);
    GJBaseGameLayer::updateLevelColors((GJBaseGameLayer *)this);
    updateProgressbar(this);
    updateInfoLabel(this);
    updateEffectPositions(this);
    if (lVar1 != ___stack_chk_guard) {
                    /* WARNING: Subroutine does not return */
        __stack_chk_fail();
    }
    return;
}



// Cleaned up version of function
// Remove this->, remove stack chk, keep virtual function weirdness, convert functions with this as the first parameter into this->function format
// Fix up operator overloads for operator=
void PlayLayer::postUpdate(float param_1) {
	

}



