void PlayerObject::placeStreakPoint() {
	if (!m_maybeReducedEffects && m_isDart && !m_isLocked && m_fadeOutStreak && !levelFlipping()) {
		m_waveTrail->addPoint(getPosition());
	}
	m_justPlacedStreak = false;
}
