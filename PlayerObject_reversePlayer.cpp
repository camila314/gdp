void PlayerObject::reversePlayer(EffectGameObject *effObj) {
    if (m_isPlatformer)
        return;

    if (effObj && m_reverseSync) {
        speedVector = ccp(m_maybeReverseSpeed, m_maybeReverseSpeed);
        auto result = effObj->getRealPosition() - (speedVector + getPosition());
        this->m_maybeReverseSpeed += 2 * (m_isSideways ? result.y : result.x);
    }

    doReversePlayer(!m_isGoingLeft);
    return;
}
