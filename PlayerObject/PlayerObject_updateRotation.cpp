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

void PlayerObject::updateRotation(float dt, float angle) {
    if (m_isDashing)
        return;

    float fromAngle = this->getRotation() * 0.017453; // pi/180
    float toAngle = angle * 0.017453; // pi/180

    float mult = m_playerSpeed * 0.175;
    if (m_isShip) {
        mult *= 0.5;
    } else if (!this->isFlying() && !m_isBall && m_isOnGround2 && !m_isOnSlope && !m_wasOnSlope) {
        mult *= 3.0;
    }

    float slerp = Slerp2D(fromAngle, toAngle, std::min(dt, dt * mult)) * 57.296; // 180/pi

    if (!m_isPlatformer)
        return this->setRotation(slerp);

    if (m_isPlatformer && this->isFlying() && m_isOnSlope && m_reverseRelated > 0)
        this->setRotation(angle);
    else
        this->setRotation(slerp);
}

