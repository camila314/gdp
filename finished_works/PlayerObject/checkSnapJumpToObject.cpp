void PlayerObject::checkSnapJumpToObject(GameObject* obj) {
    if (obj) {
        if (m_snappedObject && m_snappedObject->m_uniqueID != obj->m_uniqueID && m_snappedObject->getType() == GameObjectType::Solid) {

            CCPoint oldSnapPos = m_snappedObject->getPosition();
            CCPoint newSnapPos = obj->getPosition();

            float unknownUse = 1.0;
            float upTwoGap = 90.0;
            float downOneGap = 150.0;
            float upOneGap = 90.0;
            float xShift = 1.0;

            if (m_playerSpeed == 0.9) {
                if (m_vehicleSize == 1.0) {
                    upOneGap = 120.0;
                }
            } else if (m_playerSpeed == 0.7) {
                upTwoGap = 60.0;
                downOneGap = 120.0;
            } else if (m_playerSpeed == 1.1) {
                unknownUse = 0.0;
                xShift = 2.00;
                upTwoGap = 120.0;
                downOneGap = 195.0;
                if (m_vehicleSize == 1.0) {
                    upOneGap = 150.0;
                }
            } else if (m_playerSpeed == 1.3) {
                unknownUse = 0.0;
                xShift = 2.00;
                upTwoGap = 135.0;
                downOneGap = 225.0;
                if (m_vehicleSize == 1.0) {
                    upOneGap = 180.0;
                }
            } else {
                upOneGap = 120.0;
            }

            upOneGap += oldSnapPos.x;
            downOneGap += oldSnapPos.x;

            float someMultiplier = (m_isUpsideDown ? 30.0 : -30.0);

            if (unknownUse >= upOneGap)
                oldSnapPos.y = fabs(newSnapPos.x - upOneGap) + someMultiplier;

            float value1 = fabs(newSnapPos.y - (oldSnapPos.y + someMultiplier));
            float value2 = fabs(newSnapPos.y - (oldSnapPos.y + someMultiplier * 2));
            float value3 = fabs(newSnapPos.x - downOneGap);
            float value4 = fabs(newSnapPos.x - (upTwoGap + oldSnapPos.x));
            float value5 = fabs(newSnapPos.y - oldSnapPos.y);

            if (
                (unknownUse >= upOneGap && unknownUse >= value5) ||
                (unknownUse >= value3 && unknownUse >= value1) ||
                (unknownUse >= value4 && unknownUse >= value2)
            ) {
                float newPos = obj->getPositionX() + this->m_snapDifference;
                float oldPos = this->getPositionX();

                if (xShift < fabs(newPos - oldPos)) {
                    if (newPos > oldPos) {
                        newPos += oldPos;
                    } else {
                        newPos = oldPos - xShift;
                    }
                }
                this->setPositionX(newPos);
            }
        }

        m_snappedObject = obj;
        m_snapDifference = this->getPositionX() - obj->getPositionX();
    }
}
