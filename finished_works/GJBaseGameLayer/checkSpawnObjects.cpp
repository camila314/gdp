GJBaseGameLayer::checkSpawnObjects() {
    while (m_triggerQueue->count() > 0) {
        auto trigger = m_triggerQueue->objectAtIndex(0);
        if (trigger->m_startingX < m_playerObject1->getPositionX() || trigger->m_toggledOff) {
            break;
        }

        trigger->triggerObject();
        m_triggerQueue->removeObjectAtIndex(0);
    }
}
