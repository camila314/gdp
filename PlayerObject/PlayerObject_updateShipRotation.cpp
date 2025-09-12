void PlayerObject::updateShipRotation(PlayerObject *this, float dt) {
    if (m_isOnSlope || m_isDashing)
        return;

    // essentially just m_isGoingLeft. i'm not sure why robtop did this
    bool v5 = (m_isBird || m_isShip || m_isSwing || m_isDart) && m_isGoingLeft;

    CCPoint diff = this->getPosition() - m_shipRotation;

    if (m_isSideways) {
        diff = ccp(diff.y, diff.x);
    } else {
        diff.y = -diff.y;
    }

    if (v5) {
        diff.x = std::abs(diff.x);
    }

    if (dt * 1.2 > (std::pow(diff.x, 2) + std::pow(diff.y, 2)) && (!m_isPlatformer || !m_isShip && !m_isBird))
        return;

    float fromAngle = this->getRotation() * 0.017453292f; // pi/180
    float toAngle = atan2(diff.y, diff.x);
    float interp = 0.07;

    if (m_isCollidingWithSlope && this->isFlying())
        toAngle = 0.0;
    if (v5)
        toAngle = -toAngle;

    if (m_isBird) {
        bool directionMatchGravity = m_isGoingLeft == m_isUpsideDown;
        float v15 = (directionMatchGravity ? -0.1 : 0.1);

        if (m_isPlatformer && (fabs(m_platformerXVelocity) <= 0.5 || m_isOnGround2)) {
            toAngle = 0.0;
        } else if (directionMatchGravity) {
            toAngle = std::max(toAngle * -0.4f, v15);
        } else {
            toAngle = std::min(toAngle * -0.4f, v15);
        }
    } else if (m_isDart) {
        interp = (m_vehicleSize == 1.0 ? 0.25 : 0.4);
    } else if (!m_isPlatformer || !m_isShip) {
        interp = 0.15;
    } else if (!m_holdingLeft && !m_holdingRight && !m_platformerMovingLeft && !m_platformerMovingRight) {
        interp = 0.06;
        toAngle = 0.0;
    } else {
        int crazyMod = this->reverseMod() * (m_isUpsideDown == m_isSideways ? 1 : -1);

        if (fabsf(toAngle) - fabsf(fromAngle) < 0.100000001) {
            interp = 0.015;
            toAngle = crazyMod * 0.7854;
        } else {
            toAngle = crazyMod * 0.5236;
        }
    }

    if (m_isCollidingWithSlope && this->isFlying()) {
        interp *= 0.25;
    }

    this->setRotation(Slerp2D(fromAngle, toAngle, std::min(dt * interp, dt)) * 57.29578); // 180/pi
}