bool PlayerObject::preSlopeCollision(GameObject* obj, float arg2) {
    if (obj->m_uuid != m_slopeCollidedUUID) {
        auto objectRect = obj->getObjectRect();
        auto playerRect = this->getObjectRect();
        float var_2C;
        bool ignoreSettingSlopeVars;

        if (obj->slopeWallLeft()) {
            if (objectRect.origin.x > this->getPosition().x) {
                CCRect hitbox(objectRect.origin.x, objectRect.origin.y, 1.0, objectRect.height);
                if (playerRect->intersectsRect(hitbox)) {
                    this->collidedWithObject(obj, arg2, hitbox);
                }
                ignoreSettingSlopeVars = true;
            } else {
                var_2C = 0.0;
                ignoreSettingSlopeVars = false;
            }
        } else {
            ignoreSettingSlopeVars = false;
            if (obj->getRealPosition(obj).x + obj->getLastPosition().x > m_playerSpeedMultiplier * m_playerSpeed * arg2) {
                if (this->getPosition().x > objectRect->getMaxX()) {
                    var_2C = 1.0;
                    auto hitbox = cocos2d::CCRect::CCRect(objectRect + objectRect.size.width - 1.00, objectRect.origin.y + 1.0, 1.0, objectRect.size.height - 2);
                    ignoreSettingSlopeVars = true;
                    if (playerRect->intersectsRect(hitbox)) {
                        this->collidedWithObject(obj, arg2, hitbox);
                    }
                }
            }
        }
        CCRect hitbox;
        if (obj->slopeFloorTop())
            hitbox = CCRect(var_2C + objectRect.origin.x, objectRect.origin.y + objectRect.size.height - 1.00, var_2C * -2 + objectRect.size.width, 1.0);
        else
            hitbox = CCRect(var_2C + objectRect.origin.x, objectRect.origin.y, var_2C * -2 + objectRect.size.width, 1.0);

        bool unk_b = true;

        if (this->getPosition().y >= hitbox.origin.y + hitbox.size.height) {
            if (playerRect->intersectsRect(hitbox)) {
                this->collidedWithObject(obj, hitbox, arg2);
            }
        } else {
            if (!ignoreSettingSlopeVars) {
                m_notOnSlope = false;
                if (!m_onSlope) { // holy fuck robtop why do you have such bad slope code
                    // this is incredibly messy but idk how else to simplify it
                    if (m_collidedSlopeObj && m_collidedSlopeObj->goingUphill && !m_collidedSlopeObj->slopeFloorTop()) {
                        if (obj->getPositionX() > m_collidedSlopeObj->getPositionX()) {
                            m_collidedSlopeObj = obj;
                        }
                    } else if (!m_collidedSlopeObj || obj->goingUphill && !obj->slopeFloorTop() && m_collidedSlopeObj->getPositionX() <= obj->getPositionX()){
                        m_collidedSlopeObj = obj;
                    }
                }
                unk_b = false;
            }
        }
        return !objectRect->intersectsRect(playerRect) || unk_b;
    }
    return false;
}
