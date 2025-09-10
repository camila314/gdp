float PlayerObject::convertToClosestRotation(float angle) {
    if (this->isFlying() || m_isRobot || m_isSpider || m_isDashing)
        return angle;

    float playerRotation = (int)this->getRotation() % 360;

    float diff = std::mod(playerRotation - angle, 90.0f);
    if (diff < 0)
        diff += 90.0f;

    if (std::abs(playerRotation - angle) < std::abs(diff))
        return angle;
    else
        return playerRotation - diff;
}