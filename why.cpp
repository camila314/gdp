PlayerObject::resetObject(CCObject * this) {
    *(int8_t *)(this + 0x629) = 0x1;
    *(this + 0x528) = 0x0;
    *(int8_t *)(this + 0x730) = 0x0;
    *(int8_t *)(this + 0x688) = 0x0;
    *(this + 0x540) = 0x0;
    *(this + 0x538) = 0x0;
    *(int8_t *)(this + 0x554) = 0x0;
    *(this + 0x54c) = 0x0;
    rax = PlayerObject::toggleVisibility(this, 0x1);
    xmm0 = intrinsic_movsd(xmm0, *(this + 0x650));
    xmm0 = intrinsic_ucomisd(xmm0, 0x0);
    if (xmm0 > 0x0) {
        *(this + 0x650) = 0x0;
        rax = *this;
        rax = (*(rax + 0x398))(this, this + 0x73e);
        rdi = *(this + 0x5b0);
        rax = *rdi;
        rax = (*(rax + 0x398))(rdi, this + 0x741);
        rdi = *(this + 0x5d0);
        rax = *rdi;
        rax = (*(rax + 0x398))(rdi, this + 0x741);
        rdi = *(this + 0x6a8);
        rax = *(int16_t *)(this + 0x741) & 0xffff;
        rax = GJRobotSprite::updateColor02(rdi, (*(int8_t *)(this + 0x743) & 0xff) << 0x10 | rax);
        rdi = *(this + 0x6b0);
        rax = *(int16_t *)(this + 0x741) & 0xffff;
        rax = GJRobotSprite::updateColor02(rdi, (*(int8_t *)(this + 0x743) & 0xff) << 0x10 | rax);
    }
    *(int32_t *)(this + 0xb28) = 0x0;
    *(this + 0xb20) = 0x0;
    *(this + 0xb18) = 0x0;
    rax = cocos2d::CCArray::removeAllObjects(*(this + 0x7b0));
    rax = __bzero(this + 0x7f4, 0x324);
    rax = PlayerObject::stopDashing(this, 0x324, rdx);
    rax = PlayerObject::deactivateStreak(this, 0x0);
    rdi = *(this + 0x698);
    if (rdi != 0x0) {
        r14 = CheckpointObject::getObject(rdi);
        rax = GJBaseGameLayer::removeObjectFromSection(*(GameManager::sharedState() + 0x180), r14);
        rax = GameObject::removeGlow(r14);
        rax = *r14;
        rax = (*(rax + 0x208))(r14);
        rax = cocos2d::CCObject::release(*(this + 0x698));
        *(this + 0x698) = 0x0;
    }
    rax = cocos2d::CCNode::stopActionByTag(*(this + 0x6b0), 0x9);
    rax = **(this + 0x6b0);
    xmm0 = intrinsic_movss(xmm0, *(int32_t *)value 1.0);
    rax = (*(rax + 0xa0))();
    *(int8_t *)(this + 0x630) = 0x0;
    *(int8_t *)(this + 0x73d) = 0x0;
    rax = cocos2d::CCPoint::operator=(this + 0x7a4, PlayerObject::someSharedValue);
    *(this + 0x7b8) = 0x0;
    rax = cocos2d::CCPoint::operator=(this + 0x78c, PlayerObject::someSharedValue);
    *(int8_t *)(this + 0x7a2) = 0x0;
    *(this + 0x690) = 0x0;
    *(int8_t *)(this + 0x62b) = 0x0;
    *(int8_t *)(this + 0x768) = 0x0;
    *(int8_t *)(this + 0x769) = 0x0;
    *(int32_t *)(this + 0x76c) = 0x0;
    *(int32_t *)(this + 0x584) = -1;
    *(int32_t *)(this + 0x728) = 0x0;
    *(int8_t *)(this + 0x732) = 0x0;
    *(int32_t *)(this + 0x724) = 0x0;
    *(int8_t *)(this + 0x569) = 0x0;
    *(int32_t *)(this + 0x734) = 0x0;
    *(int32_t *)(this + 0x738) = 0x0;
    *(this + 0x7d8) = 0x0;
    *(int8_t *)(this + 0x7a1) = 0x0;
    *(this + 0x578) = 0x0;
    *(this + 0x570) = 0x0;
    if (*(int8_t *)(this + 0x62c) != 0x0) {
        r15 = *(*this + 0xb8);
        rax = cocos2d::CCPoint::CCPoint(var_20, *(GameManager::sharedState() + 0x180) + 0x74c);
        rax = (r15)(this, var_20);
    }
    *(this + 0x760) = 0x0;
    rax = PlayerObject::flipGravity(this, 0x0, 0x0);
    rax = PlayerObject::toggleBirdMode(this, 0x0);
    rax = PlayerObject::toggleRollMode(this, 0x0);
    rax = PlayerObject::toggleRobotMode(this, 0x0, 0x0);
    rax = PlayerObject::toggleBirdMode(this, 0x0);
    rax = PlayerObject::toggleDartMode(this, 0x0);
    rax = PlayerObject::toggleSpiderMode(this, 0x0, 0x0);
    rax = PlayerObject::togglePlayerScale(this, 0x0, 0x0);
    rax = cocos2d::CCNode::stopActionByTag(this, 0x0);
    rax = cocos2d::CCNode::stopActionByTag(this, 0x1);
    *(int8_t *)(this + 0x568) = 0x0;
    rax = *this;
    xmm0 = 0x0;
    rax = (*(rax + 0x158))(this);
    *(int8_t *)(this + 0x777) = 0x0;
    rax = cocos2d::CCNode::stopActionByTag(this, 0x3);
    rax = *this;
    rax = (*(rax + 0x368))(this, 0xff);
    rax = PlayerObject::toggleGhostEffect(this, 0x0, 0x0);
    if (*(int8_t *)(this + 0x629) == 0x0) {
        if (*(int8_t *)(this + 0x62c) != 0x0) {
            xmm0 = intrinsic_movss(xmm0, *(int32_t *)(this + 0x780));
            xmm0 = intrinsic_ucomiss(xmm0, *(int32_t *)value 0.9);
            if ((xmm0 != 0x0) || (!CPU_FLAGS & NP)) {
                rdi = *(GameManager::sharedState() + 0x180);
                xmm0 = intrinsic_movss(xmm0, *(int32_t *)value 0.9);
                rax = PlayLayer::playSpeedParticle(rdi);
            }
        }
    }
    *(int32_t *)(this + 0x780) = 0.900000f;
    *(this + 0x618) = 0.958199;
    xmm0 = intrinsic_movaps(xmm0, *(int128_t *)value 5.77);
    *(int128_t *)(this + 0x608) = intrinsic_movups(*(int128_t *)(this + 0x608), xmm0);
    rax = PlayerObject::updateRobotAnimationSpeed(this);
    if (*(int8_t *)(this + 0x772) != 0x0) {
        rax = PlayerObject::runRotateAction(this, 0x0, 0x0);
    }
    if (((*(GameManager::sharedState() + 0x180) != 0x0) && (*(int8_t *)(*(GameManager::sharedState() + 0x180) + 0x748) == 0x0)) && (*(int8_t *)(this + 0x7e0) == 0x0)) {
        rax = cocos2d::CCNode::stopActionByTag(this, 0xa);
        xmm0 = intrinsic_movss(xmm0, *(int32_t *)value 0.4);
        rdx = 0x0;
        rax = 0x0;
        rdi = cocos2d::CCBlink::create(0x4);
        rsi = cocos2d::CCShow::create();
        r14 = cocos2d::CCSequence::create();
        rax = *r14;
        rax = (*(rax + 0x48))(r14, 0xa);
        rax = cocos2d::CCNode::runAction(this, r14);
        if (*(int8_t *)(GameManager::sharedState() + 0x2a1) == 0x0) {
            rdx = 0x0;
            rax = 0x0;
            rdi = cocos2d::CCDelayTime::create();
            rsi = cocos2d::CCCallFunc::create(this, PlayerObject::spawnCircle(), 0x0);
            rax = cocos2d::CCSequence::create();
            rax = cocos2d::CCNode::runAction(this, rax);
            xmm0 = intrinsic_movss(0x0, *(int32_t *)value 0.10);
            rdx = 0x0;
            rax = 0x0;
            rdi = cocos2d::CCDelayTime::create();
            rsi = cocos2d::CCCallFunc::create(this, PlayerObject::spawnCircle(), 0x0);
            rax = cocos2d::CCSequence::create();
            rax = cocos2d::CCNode::runAction(this, rax);
            xmm0 = intrinsic_movss(xmm0, *(int32_t *)value 0.20);
            rdx = 0x0;
            rax = 0x0;
            rdi = cocos2d::CCDelayTime::create();
            rsi = cocos2d::CCCallFunc::create(this, PlayerObject::spawnCircle(), 0x0);
            rax = cocos2d::CCSequence::create();
            rax = cocos2d::CCNode::runAction(this, rax);
            xmm0 = intrinsic_movss(xmm0, *(int32_t *)value 0.30);
            rdx = 0x0;
            rax = 0x0;
            rdi = cocos2d::CCDelayTime::create();
            rsi = cocos2d::CCCallFunc::create(this, PlayerObject::spawnCircle(), 0x0);
            rax = cocos2d::CCSequence::create();
            rax = cocos2d::CCNode::runAction(this, rax);
        }
    }
    rax = PlayerObject::resetStreak(this);
    rax = PlayerObject::levelFlipFinished(this);
    *(int8_t *)(this + 0x629) = 0x0;
    if (*(int8_t *)(this + 0x721) != 0x0) {
        rax = PlayerObject::activateStreak(this);
    }
    return;
}