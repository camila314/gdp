void PlayerObject::flipGravity(bool upsideDown, bool arg2) {
    if (m_upsideDown != upsideDown) {
        if (!m_unnamed_629) {
            if (m_isDart && !m_unknown_7a2 && m_unknown_73c && m_inPlaylayer && !PL->isFlipping()) {
                m_hardStreak->addPoint(this->getPosition());
            }
        }
        m_unknown_508 = false;
        m_upsideDown = upsideDown;
        m_unknown_648 = m_time;
        m_unknown_734 = false;
        if (m_onSlope2 || m_onSlope) {
            m_goingDownhill = !m_goingDownhill;
        }
        m_dict_518->removeAllObjects(m_dict_518);
        m_dict_520->removeAllObjects();
        m_collidedUUID = 0;
        if (!m_unnamed_629) {
            m_yAccel *= 1.75;
        }
        m_particleSystems[0]->setAngle(m_particleSystems[0]->getAngle() + 180);
        m_particleSystems[0]->setGravity(ccp(m_particleSystems[0]->getGravity().x, -m_particleSystems[0]->getGravity().y));

        m_particleSystems[4]->setAngle(m_particleSystems[4]->getAngle() + 180);
        m_particleSystems[4]->setGravity(ccp(m_particleSystems[0]->getGravity().x, -m_particleSystems[4]->getGravity().y));

        m_particleSystems[5]->setAngle(m_particleSystems[5]->getAngle() + 180);
        m_particleSystems[5]->setGravity(ccp(m_particleSystems[0]->getGravity().x, -m_particleSystems[5]->getGravity().y));
        if (!m_unnamed_629 && !arg2) {
            auto col = upsideDown ? ccc3(255, 200, 0) : ccc3(0, 150, 255);
            this->spawnPortalCircle(col, 45.0);
        }
        this->stopActionByTag(5);
        this->setScaleX(m_vehicleSize);
        this->setScaleY((m_upsideDown && !m_isCube) ? -m_vehicleSize : m_vehicleSize);

        m_particleSystems[3]->setAngle(m_particleSystems[3]->getAngle() + 180);
        m_particleSystems[3]->setGravity(ccp(m_particleSystems[3]->getGravity().x, -m_particleSystems[3]->getGravity().y));

        if (!m_isBall) {
            if (PL && !PL->m_unknown_748 && !m_isDart) {
                if (!m_unnamed_629) {
                    m_unknown_62b = 0x1;
                    this->activateStreak();
                }
            }
        }
        m_lastHitGround = m_lastPortalLocation;
        m_onGround = false;
        if (m_isBall) {
            this->stopActionByTag(0);
            this->stopActionByTag(1);
            m_unknown_568 = false;
            this->runBallRotation2();
        }
    }
}