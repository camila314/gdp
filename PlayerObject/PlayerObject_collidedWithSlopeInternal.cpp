void PlayerObject::collidedWithSlopeInternal(float dt, GameObject* object, bool forced) {
    if (!forced && this->preSlopeCollision(dt, object))
        return;

    cocos2d::CCRect playerRect = this->getObjectRect();
    cocos2d::CCRect objRect = object->getObjectRect();
    float playerRadius = playerRect.size.height / 2.0;

    cocos2d::CCPoint slopeMoveSpeed = object->getRealPosition() - object->getLastPosition();
    if (m_isSideways)
        slopeMoveSpeed = ccp(slopeMoveSpeed.y, slopeMoveSpeed.x);

    // is the slope moving faster than the player is moving
    bool slopeOutpaces = slopeMoveSpeed.x > m_playerSpeed * m_speedMultiplier * dt;

    bool slopeFloorTop = object->slopeFloorTop();
    bool goingLeft = m_isPlatformer ? m_platformerXVelocity < 0.0 : m_isGoingLeft;

    bool slopeUphill = object->m_slopeUphill ^ !goingLeft;
    bool playerUphill = slopeUphill ^ (m_isUpsideDown != m_isSideways) ^ slopeOutpaces;

    int flipMod = this->flipMod();
    int upsideMod = m_isUpsideDown ? -1 : 1;

    float slopeYVelocity = (objRect.size.height * m_playerSpeed * m_speedMultiplier) / objRect.size.width;

    float float_g = playerUphill ? (m_wasOnSlope ? 4.0 : 1.0) : 0.0;

    bool slopeTopRelated = playerUphill && m_isCurrentSlopeTop == slopeFloorTop && m_isUpsideDown == slopeFloorTop;
    if (m_wasOnSlope && m_slopeVelocity * flipMod > 0.0 && (slopeTopRelated || m_currentSlopeYVelocity > slopeYVelocity))
        return;

    bool slopeMoveDown = upsideMod * slopeMoveSpeed.y < 0;

    if (slopeMoveDown || forced) {
        float_g += std::min(fabs(slopeMoveSpeed.y), dt * (m_isPlatformer ? 10 : 5));
    }

    // when the player is on the slope, its radius measured from bottom to top is different.
    // e.g for angle 0º it's 15 and for angle 45º it's 15 * sqrt(2)
    float playerRadOnSlope = playerRadius / cosf(object->getSlopeAngle());
    float playerRadOnPrevSlope = playerRadius / cosf(m_slopeRotation);

    // the Y value that represents how high above the slope you can be while still "being on the slope"
    float onSlopeThreshold = this->getPositionY() - upsideMod * (playerRadOnPrevSlope + float_g);

    if (m_wasOnSlope) {
        if (m_isUpsideDown && onSlopeThreshold < objRect.origin.y) {
            return;
        } else if (onSlopeThreshold > (objRect.origin.y + objRect.size.height)) {
            return;
        }
    } else {
        cocos2d::CCRect exitRect = objRect;
        exitRect.origin.y += 1.0;
        exitRect.size.height -= 2.0;

        if (!playerRect.intersectsRect(exitRect))
            return;
    }

    cocos2d::CCPoint playerPos = this->getPosition();
    float minY = objRect.getMinY();
    float maxY = objRect.getMaxY();

    bool isNewSlope = m_wasOnSlope && m_collidingWithSlopeId != object->m_uniqueID && m_isCurrentSlopeTop != slopeFloorTop;
    float newSlopeScalar = (isNewSlope && !m_isPlatformer) ? m_vehicleSize * 20 : 0;

    float slopeYPos = object->slopeYPos(playerPos.x);
    float newPlayerY = slopeYPos + (playerRadOnSlope - newSlopeScalar) * (slopeFloorTop ? -1 : 1);
    bool bool_e, bool_f;

    if (slopeFloorTop) {
        float temp = minY - playerRadius + newSlopeScalar;
        newPlayerY = std::max(newPlayerY, temp);
        bool_f = (newPlayerY == temp);

        newPlayerY = std::min(newPlayerY, maxY);
        bool_e = (newPlayerY == maxY);
    } else {
        float temp = maxY + playerRadius - newSlopeScalar;
        newPlayerY = std::min(newPlayerY, temp);
        bool_f = (newPlayerY == temp);

        newPlayerY = std::max(newPlayerY, minY);
        bool_e = (newPlayerY == minY);
    }

    bool collidedSlope, bool_i;
    bool slopeUpsideDown = m_isUpsideDown != slopeFloorTop;

    bool bool_b = !slopeUpsideDown && m_jumpBuffered && this->isFlying() && (!playerUphill || m_isPlatformer);

    if (slopeUpsideDown) {
        float float_p = playerUphill ? 0 : float_g;
        if (this->isFlying() && m_jumpBuffered) {
            float_p = m_wasOnSlope ? 2.0 : 1.0;
        }

        collidedSlope = !m_isOnSlope 
                   && !isNewSlope 
                   && (!this->isFlying() || m_isPlatformer || !playerUphill)
                   && upsideMod * playerPos.y > upsideMod * (newPlayerY - float_p);
        if (upsideMod * playerPos.y > upsideMod * newPlayerY) {
            collidedSlope = true;
        }

        bool_i = (this->isFlying() || m_isBall) && !m_jumpBuffered && playerUphill && m_wasOnSlope && !m_isPlatformer;

        if (collidedSlope && !this->isFlying() && !m_isBall && !m_isPlatformer && m_stateHitHead == 0) {
            bool notSafe = !this->isSafeMode(0.1) && !this->isSafeFlip(0.1);
            if (!notSafe || (upsideMod * playerPos.y - 2) <= upsideMod * newPlayerY) {
                if (notSafe) {
                    this->setPositionY(newPlayerY);

                    float newVel = m_isUpsideDown ? std::max(m_yVelocity, 2.0) : std::min(m_yVelocity, -2.0);
                    this->setYVelocity(newVel, 18);
                }

                m_isOnGround = 0;
                m_isOnGround2 = 0;
            } else if (!m_ignoreDamage) {
                // LABEL_190
                if (m_maybeCanRunIntoBlocks) {
                    m_maybeIsColliding = 1;
                } else {
                    PlayLayer::get()->destroyPlayer(this, 0);
                }
            }

            return;
        }
    } else {
        bool bool_h = playerUphill ? (!isNewSlope && !m_isOnSlope && (!m_maybeIsBoosted || this->isFlying()) && (!m_isShip || m_jumpBuffered)) : (forced || slopeMoveDown);
        
        collidedSlope = true;
        if (upsideMod * playerPos.y >= upsideMod * newPlayerY) {
            collidedSlope = false;
            if (bool_h && upsideMod * playerPos.y < upsideMod * (newPlayerY + float_g)) {
                collidedSlope = m_isBird ? upsideMod * this->m_yVelocity <= 0.0 : true;
            }
        }

        bool_i = bool_b && isNewSlope && !m_isPlatformer;
    }

    if (collidedSlope && !m_ignoreDamage && (object->m_slopeIsHazard || (!m_isPlatformer && m_stateHitHead <= 0 && (isNewSlope || (m_isDart && m_stateDartSlide <= 0))))) {
        if (this->m_maybeCanRunIntoBlocks) {
            this->m_maybeIsColliding = 1;
        } else {
            PlayLayer::get()->destroyPlayer(this, 0);
        }
        return;
    }

    float float_d = newPlayerY;
    if (m_isSideways && m_rotateObjectsRelated.count(object->m_uniqueID)) {
        float_d -= m_rotateObjectsRelated[object->m_uniqueID].m_y;
    }

    if (m_wasOnSlope) {
        if (m_unk3d0 == newPlayerY || m_isSideways && m_blackOrbRelated == float_d) {
            if (!m_isPlatformer || fabs(m_platformerXVelocity) >= 0.1)
                return;
        }

        if (slopeMoveSpeed.y != 0.0 && ((bool_f && m_unk3e0) || (bool_e && m_unk3e1))) {
            if (!m_isDashing) {
                if (!m_isPlatformer || fabs(m_platformerXVelocity) > 0.1)
                    return;
            }
        }
    }

    // if platformer, slopes have smaller hitbox i guess
    if (m_isPlatformer) {
        cocos2d::CCRect tempRect = playerRect;
        tempRect.origin.x -= 2.0;
        tempRect.origin.y -= 10.0;
        tempRect.size.width += 4.0;
        tempRect.size.height += 20.0;

        if (!objRect.intersectsRect(tempRect))
            return;
    }

    // no collision? no problemo
    if (!collidedSlope || (playerUphill && m_isDart && m_jumpBuffered && m_isUpsideDown == slopeFloorTop)) {
        return;
    }

    // set a bunch of stuff
    m_currentSlope = object;
    m_currentSlope3 = m_currentSlope;
    m_slopeAngleRadians = object->getSlopeAngle();
    m_maybeRotatedObjectsMap[object->m_uniqueID] = object;
    m_unk3e0 = bool_f;
    m_unk3e1 = bool_e;
    m_unk3d0 = newPlayerY;
    m_isCurrentSlopeTop = slopeFloorTop;
    m_collidingWithSlopeId = object->m_uniqueID;
    m_slopeFlipGravityRelated = playerUphill;
    m_blackOrbRelated = float_d;
    this->unk_584 = playerRadOnSlope - playerRadius;

    // set new slope rotation
    int someMod = flipMod * (!playerUphill ? -1 : 1) * (slopeOutpaces ? -1 : 1) * (goingLeft ? -1 : 1) * (m_isSideways ? -1 : 1);
    float oldRotation = m_slopeRotation;
    m_slopeRotation = m_slopeAngleRadians * someMod;

    this->setPositionY(newPlayerY);
    m_isOnSlope = true;

    // if new slope, set the slope start time etc.
    if (!m_wasOnSlope) {
        m_slopeStartTime = m_totalTime;
        m_yVelocityBeforeSlope = m_yVelocity;
    }
    m_maybeUpsideDownSlope = slopeUpsideDown;

    // bool_i directly related to whether to process ground collisions
    if (!bool_i) {
        if (slopeUpsideDown) {
            this->setYVelocity(upsideMod * m_yVelocity > 0 ? 0 : m_yVelocity , 20);
            m_isOnGround = 0;
            m_isOnGround2 = 0;
            this->updateCollide(PlayerCollisionDirection::Top, object);
        } else {
            float oldVelocity = m_yVelocity;
            this->hitGround(object, 0);
            if (upsideMod * oldVelocity > upsideMod * 5.0)
                this->setYVelocity(oldVelocity, 100);

            if (m_isPlatformer && fabs(m_slopeAngleRadians * 57.29578) > 40.0 && oldVelocity < -5.0 && m_platformerXVelocity > 0.0) {
                m_platformerXVelocity /= 2.0;
            }

            this->updateCollide(PlayerCollisionDirection::Bottom, object);
            m_currentSlope2 = object;
            m_slopeAngle = object->getSlopeAngle();
            m_slopeSlidingMaybeRotated = object->m_slopeUphill ^ m_isSideways;

            if (m_slopeAngle >= 1.0 && m_slopeSlidingMaybeRotated)
                this->m_maybeSlidingTime = 3;

            // if the slope is moving your ground velocity gets adjusted
            if (slopeMoveSpeed != CCPointZero) {
                if (m_isUpsideDown && slopeMoveSpeed.x < 0) {
                    m_groundYVelocity = slopeMoveSpeed.x / dt;
                } else if (!m_isUpsideDown && slopeMoveSpeed.y > 0) {
                    m_groundYVelocity = slopeMoveSpeed.y / dt;
                }
            }
        }
    }

    // clamp velocities down when flying at slope
    if (slopeUpsideDown && this->isFlying() && playerUphill && !m_jumpBuffered && upsideMod * m_yVelocity > upsideMod * -2.0) {
        this->setYVelocity(flipMod * -2.0, 21);
    } else if (bool_b && upsideMod * m_yVelocity < upsideMod * 2.0) {
        this->setYVelocity(flipMod * 2.0, 22);
    }

    // set exit velocity multipliers for slope
    m_currentSlopeYVelocity = slopeYVelocity;
    m_slopeVelocity = std::min(1.12 / slopeAngle, 1.54) * m_currentSlopeYVelocity * flipMod * (playerUphill && !(slopeOutpaces && m_isUpsideDown != slopeUphill) ? -1 : 1);

    // no jumps when in contact with upside-down slope while platformer ufo i guess
    if (slopeUpsideDown && m_isPlatformer && m_isBird)
        m_jumpBuffered = false;

    if (this->isFlying() || m_isBall) {
        m_slopeVelocity *= 0.75;

        if (m_isBall && oldRotation != m_slopeRotation) {
            // run ball rotation
            float ballRot = 1.0 / cosf(m_slopeRotation);
            if (ballRot > 2.0)
                ballRot = ballRot * 0.7 + 0.3;

            this->stopRotation(1, 1);
            this->runBallRotation(ballRot);
            return;   
        }
    }

    this->updateSlopeRotation(dt);
}
