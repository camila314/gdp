void PlayerObject::updateRotation(float dt) {

    if (m_isLocked || m_isDashing)
        return;

    if (!m_isBall) {
        if (m_isOnSlope) {
            this->updateSlopeRotation(dt);
        } else if (this->isFlying()) {
            this->updateShipRotation(dt);
        } else if (!m_wasOnSlope) {
            if ((!m_isOnGround2 || this->playerIsFalling(-0.25)) && (m_isRobot || m_isSpider)) {
                this->updateRotation(dt * 0.5, 0.0);
            } else if (!m_isPlatformer || !m_isRotating) {
                this->stopRotation(0, 2);
                this->updateRotation(dt, this->convertToClosestRotation(0.0));
            }
        }
    }

    if (m_rotationSpeed != 0.0) {
        float rotateSpeed = (m_isBall && m_isBallRotating) ? 1.0 : m_rotateSpeed;
        this->setRotation(this->getRotation() + (dt / 60.0) * m_rotationSpeed * rotateSpeed);
    }
}
