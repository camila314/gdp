void PlayerObject::boostPlayer(float arg1) {
    m_isRising = true;
    m_isSliding = false;
    m_onGround = false;
    m_unknown_62b = true;
    m_hitPortal = true;
    m_yAccel = arg1;
    if (!m_isDashing) {
        if (m_isSpider) {
            m_spiderSprite->tweenToAnimation("fall_loop", 0.1);
        } else if (!(m_isShip || m_isBird || m_isBall || m_isDart || m_isRobot)) { // dumb vehicle var system
            this->stopActionByTag(0);
            this->stopActionByTag(1);
            m_unknown_568 = false;
            auto rot = CCRotateBy::create(m_vehicleSize == 1.0 ? 13.0/15.0 : 2.0/3.0, m_upsideDown ? 180.0 : -180.0);
            rot->setTag(0);
            this->runAction(rot);
        }
    }
    m_lastHitGround = this->getPosition();
}
