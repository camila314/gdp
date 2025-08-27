void PlayerObject::updateTimeMod(float speed, bool noParticle) {
    if (!m_maybeReducedEffects && m_playEffects && !noParticle && m_playerSpeed != speed) {
        GameManager::sharedState()->m_playLayer->playSpeedParticle(speed);
    }

    m_playerSpeed = speed;

    if (speed == 0.9) {
        m_yStart = 11.1800318;
        m_gravity = 0.958199024;
        m_speedMultiplier = 5.77000189;
    } else if (speed == 0.7) {
        m_yStart = 10.620032;
        m_gravity = 0.940199;
        m_speedMultiplier = 5.980002;
    } else if (speed == 1.1) {
        m_yStart = 11.420032;
        m_gravity = 0.957199;
        m_speedMultiplier = 5.870002;
    } else if (speed == 1.3 || speed == 1.6) {
        m_yStart = 11.230032;
        m_gravity = 0.961199;
        m_speedMultiplier = 6.000002;
    } else {
        m_speedMultiplier = 5.77000189;
    }

    this->updateRobotAnimationSpeed();
    if (m_isBall)
        this->runRotateAction(0, 9);

    if (m_shipStreak)
        m_shipStreak->updateStreakSettings(m_shipStreakType, this);
}
