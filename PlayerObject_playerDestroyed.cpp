void PlayerObject::playerDestroyed(bool isOtherPlayer) {
    if (m_isDart)
        fadeOutStreak2(0.2);

    stopDashing();
    m_isDead = true;
    stopRotation(true, 5);
    stopParticles();
    
    m_lastPosition = getCurrentPosition();

    if (m_robotFire) {
        m_robotFire->stopAllActions();
        m_robotFire->setVisible(false);
    }

    toggleGhostEffect(GhostType::Disabled);
    disableSwingFire();

    if (m_playEffects && !isOtherPlayer && !m_isHidden) {
        playDeathEffect();
    } else {
        setOpacity(0);
    }
}
