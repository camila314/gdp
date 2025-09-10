void PlayerObject::updateSlopeRotation(float dt) {
    float rot = this->convertToClosestRotation(m_slopeRotation * 57.2957802); // 180 / pi
    if (m_isPlatformer && m_maybeChangedDirectionAngle > 80.0 && (m_platformerMovingLeft || m_platformerMovingRight)) {
    	rot = 0.0;
    }
    return this->updateRotation(dt, rot);
}