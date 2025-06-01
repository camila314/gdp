void PlayerObject::boostPlayer(float amount) {
    m_maybeIsBoosted = true;
    m_isOnGround2 = false;
    m_isOnGround = false;
    m_shouldTryPlacingCheckpoint = true;
    m_isAccelerating = true;

    setYVelocity(amount, 0);

    if (!m_isDashing) {
        if (isInNormalMode()) {
            m_isRotating = true;
            m_isBallRotating = false;
            m_isBallRotating2 = false;

            float speedMult = (m_vehicleSize == 1 ? 3.0/2.0 : 15.0/13.0);
            m_rotationSpeed = 180 * speedMult * flipMod();
        } else if (this->m_isSpider) {
            m_spiderSprite->tweenToAnimation("fall_loop", 0.1);
        }
    }

    m_lastGroundedPos = getPosition();
}
