void PlayerObject::checkSnapJumpToObject(GameObject* obj) {
    if (obj) {
        rand(); // bro.

        float posX = this->getPositionX();
        float objPosX = obj->getPositionX();

        if (m_objectSnappedTo && m_objectSnappedTo->m_uniqueID != obj->m_uniqueID && m_objectSnappedTo->getType()) {
            CCPoint snapPos = m_objectSnappedTo->getRealPosition();
            CCPoint objPos = obj->getRealPosition();

            float threshold, bigStair, downStair, littleStair;

            if (m_playerSpeed == 0.9) {
                threshold = 1.0;
                bigStair = 90.0;
                downStair = 150.0;
                littleStair = m_vehicleSize == 1.0 ? 120.0 : 90.0;
            } else if (m_playerSpeed == 0.7) {
                threshold = 1.0;
                bigStair = 60.0;
                downStair = 120.0;
                littleStair = 90.0;
            } else if (m_playerSpeed == 1.1) {
                threshold = 2.0;
                bigStair = 120.0;
                downStair = 195.0;
                littleStair = m_vehicleSize == 1.0 ? 150.0 : 90.0;
            } else if (m_playerSpeed == 1.3) {
                threshold = 2.0;
                bigStair = 135.0;
                downStair = 225.0;
                littleStair = 90.0;
            } else {
                if (m_vehicleSize == 1.0) {
                    threshold = 2.0;
                    bigStair = 135.0;
                    downStair = 225.0;
                    littleStair = 180.0;
                } else {
                    threshold = 1.0;
                    bigStair = 90.0;
                    downStair = 150.0;
                    littleStair = 120.0;
                }
            }

            float blockLength = this->flipMod() * 30.0f;
            float diff = objPos - snapPos;

            if (
                (abs(diff.x - littleStair) <= threshold && abs(diff.y - blockLength) <= threshold) ||
                (abs(diff.x - downStair) <= threshold && abs(diff.y + blockLength) <= threshold) ||
                (abs(diff.x - bigStair)  <= threshold && abs(diff.y - blockLength*2) <= threshold)) {

                float newPosX = objPosX + m_snapDistance;

                if (abs(newPosX - posX) > threshold) {
                    if (newPosX <= posX)
                        newPosX = posX - threshold;
                    else
                        newPosX = posX + threshold;
                }
                this->setPositionX(newPosX);
            }
        }

        m_objectSnappedTo = obj;
        m_snapDistance = posX - objPosX;
    }
}
