void PlayerObject::doReversePlayer(bool flipRight) {
    bool changingDirections = m_isGoingLeft ^ flipRight;

    m_isGoingLeft = flipRight;
    if (changingDirections) {
        m_reverseRelated = 2;

        if (m_isDart) {
            createFadeOutDartStreak();
        }
    }

    m_waveTrail->m_isFlipped = flipRight;

    float sidewaysMod = (m_isSideways ? -1 : 1);
    m_vehicleGroundParticles->setScaleX(reverseMod() * sidewaysMod);

    updatePlayerGlow();
    updatePlayerArt();

    if (m_fadeOutStreak && m_isDart && changingDirections) {
        m_waveTrail->reset();
        placeStreakPoint();
    }

    if (m_isBall) {
        runRotateAction(true, 1);
    }
}
