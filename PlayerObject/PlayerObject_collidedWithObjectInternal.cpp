// All members should be accurate for commit 20ae4b1 on the bindings repo

int PlayerObject::collidedWithObjectInternal(float param_f,GameObject *obj,CCRect param_r,bool param_b) {
    int gravityMult = m_isUpsideDown ? -1 : 1;
    enum {
        Cube,
        Ship,
        Ball,
        Ufo,
        Wave,
        Robot,
        Spider,
        Swing
    } vType = m_isShip ? Ship : m_isBall ? Ball : m_isBird ? Ufo : m_isDart ? Wave : m_isRobot ? Robot : m_isSpider ? Spider : m_isSwing ? Swing : Cube;
    bool isFly = vType == Ufo || vType == Wave || vType == Ship || vType == Swing;

    auto object = obj;
    if (param_r != CCRectZero) 
        object = nullptr;
    int uuid = object ? object->m_uniqueID : 0;

    auto playerRect = getObjectRect();
    auto objRect = param_r;
    if (object)
        objRect = object->getObjectRect();

    double snapUpThreshold = 10.0;
    if (m_stateScale >= 1)
        snapUpThreshold = 15.0;
    else if (m_isPlatformer && !m_wasOnSlope && !m_isOnSlope)
        snapUpThreshold = 5.0;

    double origSnapUpThres = snapUpThreshold;

    if (isFly && !m_isPlatformer)
        snapUpThreshold = gravityMult * 6.0;
    else
        snapUpThreshold *= gravityMult;
    if (m_wasOnSlope)
        snapUpThreshold += unk_584 * gravityMult;

    double adjustedObjY;
    double adjustedObjLastY;
    double scaleDeltaY;
    CCPoint lastPosition;
    CCPoint realPosition;
    if (obj) {
        lastPosition = obj->getLastPosition();
        realPosition = obj->getRealPosition();

        adjustedObjLastY = m_isSideways ? lastPosition.x : lastPosition.y;
        adjustedObjY = m_isSideways ? realPosition.x : realPosition.y;
        scaleDeltaY = (m_isSideways ? obj->getScalePosDelta().y : obj->getScalePosDelta().x);
    }

    bool boolH = false;
    bool boolL = false;
    bool boolD = false;
    double newGroundVel = 0.0;
    bool objPassable = object ? object->m_isPassable : false;

    if (param_f > 0.0 && obj) {
        float expectedY = adjustedObjLastY + scaleDeltaY * (adjustedObjY <= getPositionY() ? -1 : 1);
        if (realPosition.x != lastPosition.x || realPosition.y != lastPosition.y) {
            if (m_isUpsideDown ? expectedY > adjustedObjY : expectedY < adjustedObjY) {
                boolD = true;
                boolL = std::abs(adjustedObjY) > 5.0;
                newGroundVel = (adjustedObjY - expectedY) / param_f;

                snapUpThreshold += std::abs(newGroundVel) * gravityMult;
                if (!m_isPlatformer)
                    m_groundYVelocity = newGroundVel;
            } else if (adjustedObjY != expectedY) {
                boolH = true;
            }
        }
    }

    float floatT = m_isPlatformer ? 5.0 : 0.0;
    bool boolB = !objPassable && (m_stateHitHead >= 1 || m_isPlatformer || m_stateFlipGravity >= 1);

    float adjustedY = m_isSideways ? getPositionX() : getPositionY();
    float adjustedLastY = m_isSideways ? m_lastPosition.x : m_lastPosition.y;
    float adjustedYDelta = adjustedY - adjustedLastY;
    float playerHeight = playerRect.size.height;
    float floatC = objRect.getMaxY();

    bool boolJ = adjustedYDelta * gravityMult > 0.0;
    bool canSnap = false;

    if (m_isDart && m_stateDartSlide < 1) {
        boolJ = true;
    } else {
        float playerBottom = getPositionY() + -playerRect.size.height / 2 * gravityMult;
        bool boolE = false;
        bool boolM = false;
        bool boolG = false;

        if (m_isOnSlope || m_wasOnSlope || !m_maybeRotatedObjectsMap.empty()) {
            for (auto& [k, someObject] : m_maybeRotatedObjectsMap) {
                auto someRect = someObject->getObjectRect();
                if (!m_isOnSlope && !m_wasOnSlope && object && someObject != m_currentSlope && (someRect.getMinX() >= object->getPositionX() || someRect.getMaxX() <= object->getPositionX())) {
                    continue;
                }

                if (objRect.intersectsRect(someObject->getObjectRect(1.2, 1.1))) {
                    boolE = true;
                    float slopeY = someObject->slopeYPos(objRect);
                    bool slopeFloorTop = someObject->slopeFloorTop();

                    if (objRect.getMaxY() <= slopeY + 2.0 && slopeFloorTop == (m_currentSlope == someObject)) {
                        break;
                    }
                    if (slopeY - 2.0 <= objRect.getMinY() && (slopeFloorTop || m_currentSlope == someObject)) {
                        break;
                    }
                }
            };

            boolG = true;
            boolM = true;
        }

        bool isBreakable = object && object->getType() == GameObjectType::Breakable;
        float maxSnapY = snapUpThreshold + playerBottom;
        float floatG = maxSnapY - adjustedYDelta;

        CCRect someRect = playerRect;
        someRect.origin.x += floatT / 2;
        someRect.size.width -= floatT;

        bool boolC = ((isFly || m_isBall) && !objPassable) || !m_isUpsideDown;
        bool shouldBreakBlock = false;
        if (m_isUpsideDown ?
                (maxSnapY >= objRect.getMaxY() || floatG >= objRect.getMaxY())
                : (maxSnapY <= objRect.getMinY() || floatG <= objRect.getMinY())
        ) {
            canSnap = true;
            shouldBreakBlock = !m_maybeTouchedBreakableBlock && m_isPlatformer && isBreakable && boolJ;
        }

        if (m_isPlatformer && !param_b && !someRect.intersectsRect(objRect)) {
            boolJ = true;
        } else {
            if (m_isPlatformer) {
                if ((m_isOnSlope || m_wasOnSlope) && m_maybeUpsideDownSlope != canSnap)
                    boolE = false;

                if (!param_b)
                    boolJ = false;
            }

            float playerTop = getPositionY() + playerHeight / 2 * gravityMult;
            double minSnapY = playerTop - snapUpThreshold;
            float floatL = minSnapY - adjustedYDelta;

            if (!boolC && !boolB) {
                boolJ = true;
            } else {
                float floatH = m_isUpsideDown ? minSnapY : maxSnapY;
                float floatU = m_isUpsideDown ? floatL : floatG;

                if (floatH < objRect.getMaxY() && floatU < objRect.getMaxY()) {
                    boolJ = true;
                } else if (m_isUpsideDown && m_isBird && isBreakable && !m_isPlatformer) {
                    boolJ = objRect.intersectsRect(getObjectRect(0.3, 0.3));
                    if (boolJ) {
                        if (m_gameLayer)
                            m_gameLayer->destroyObject(object);
                        else
                            object->destroyObject();
                        return 1;
                    }
                } else if ((m_yVelocity > 0.0 && !m_wasOnSlope && !boolL) || (boolE && boolG)) {
                    boolJ = false;

                    if (canSnap || !boolD || m_isUpsideDown) {
                        if (m_isUpsideDown && boolH && canSnap) {
                            setPositionY(objRect.getMaxY() + playerRect.size.height * 0.5);

                            bool tmp_1 = m_isOnGround;
                            bool tmp_2 = m_isOnGround2;
                            float tmp_3 = m_lastLandTime;
                            hitGround(nullptr, isFly);
                            m_isOnGround = tmp_1;
                            m_isOnGround2 = tmp_2;
                            m_lastLandTime = tmp_3;

                            if (!isBreakable && !objPassable) {
                                updateCollideTop(objRect.getMaxY(), object);
                            }

                            setYVelocity(std::max(m_groundYVelocity + 1.0, m_yVelocity), 0);
                            if (m_stateFlipGravity > 0) {
                                flipGravity(!m_isUpsideDown, true);
                                setYVelocity(-2 * gravityMult, 0);

                                m_maybeIsBoosted = true;
                                m_isOnGround2 = false;
                                if (m_stateNoAutoJump > 0) {
                                    m_isOnGround = false;
                                    m_jumpBuffered = false;
                                    m_stateRingJump = false;
                                }
                            }
                            if (shouldBreakBlock) {
                                m_maybeTouchedBreakableBlock = true;

                                if (m_gameLayer)
                                    m_gameLayer->destroyObject(object);
                                else
                                    object->destroyObject();
                            }
                        }
                    } else {
                        setPositionY(objRect.getMaxY() + playerRect.size.height * 0.5);
                        hitGround(object,isFly && m_isUpsideDown);

                        if (m_collidedBottomMaxY == 0 || (m_isUpsideDown ? objRect.getMaxY() < m_collidedBottomMaxY : objRect.getMaxY() > m_collidedBottomMaxY)) {
                            m_collidedBottomMaxY = objRect.getMaxY();
                        }

                        if (uuid && m_lastCollisionBottom != uuid) {
                            m_lastCollisionBottom = uuid;
                            if (m_collisionLogBottom) {
                                m_collisionLogBottom->setObject(m_maybeLastGroundObject, uuid);
                            }
                        }

                        if (obj) {
                            m_lastGroundObject = obj;
                            if (obj->m_isDontBoostY) {
                                m_stateBoostX = 2;
                            }
                            if (obj->m_isDontBoostX) {
                                m_stateBoostY = 2;
                            }
                        }

                        m_groundYVelocity = newGroundVel;
                        setYVelocity(std::max(m_groundYVelocity, m_yVelocity), 0);
                    }
                } else {
                    if (canSnap && m_yVelocity * gravityMult > 0.0 && m_gameLayer) {
                        m_gameLayer->gameEventTriggered(GJGameEvent::HitHead, 0, m_uniqueID);
                    }

                    setPositionY(objRect.getMaxY() + playerRect.size.height * 0.5);
                    if (vType == Cube) {
                        checkSnapJumpToObject(object);
                    }

                    if (!boolB || boolC) {
                        if (canSnap) {
                            bool tmp1 = m_isOnGround;
                            bool tmp2 = m_isOnGround2;
                            bool tmp3 = m_lastLandTime;
                            hitGround(nullptr, m_isUpsideDown && isFly);
                            m_isOnGround = tmp1;
                            m_isOnGround2 = tmp2;
                            m_lastLandTime = tmp3;
                        } else {
                            hitGround(object,m_isUpsideDown && isFly);
                        }
                    } else {
                        m_yVelocity = 0.0;
                    }

                    objPassable = !canSnap || isBreakable || objPassable;

                    if (m_isUpsideDown) {
                        floatT = floatC;
                        if (objPassable)
                            floatC = objRect.getMinY();
                    }


                    if (objPassable && !canSnap) {
                        updateCollideBottom(floatC, object);
                    } else if (!objPassable) {
                        if (m_collidedTopMinY == 0 || (m_isUpsideDown ? minSnapY > m_collidedTopMinY : minSnapY < m_collidedTopMinY)) {
                            m_collidedTopMinY = floatT;
                        }

                        if (uuid && m_lastCollisionTop != uuid) {
                            m_lastCollisionTop = uuid;
                            if (m_collisionLogTop) {
                                m_collisionLogTop->setObject(m_maybeLastGroundObject, uuid);
                            }
                        }
                    }

                    if (!canSnap) {
                        if (obj) {
                            m_lastGroundObject = obj;
                            if (obj->m_isDontBoostY) {
                                m_stateBoostX = 2;
                            }
                            if (obj->m_isDontBoostX) {
                                m_stateBoostY = 2;
                            }
                        }
                        m_groundYVelocity = newGroundVel;
                    }

                    if (m_isPlatformer) {
                        exitPlatformerAnimateJump();
                    }

                    if (vType == Cube && m_stateNoAutoJump > 0 && m_padRingRelated) {
                        m_jumpBuffered = false;
                    }

                    if (canSnap) {
                        if (m_stateFlipGravity > 0) {
                            flipGravity(!m_isUpsideDown, true);
                            setYVelocity(-2 * gravityMult, 0);

                            m_maybeIsBoosted = true;
                            m_isOnGround2 = false;
                            if (m_stateNoAutoJump > 0) {
                                m_isOnGround = false;
                                m_jumpBuffered = false;
                                m_stateRingJump = false;
                            }
                        } else if (isFly && boolD) {
                            setYVelocity(m_groundYVelocity, 0);
                        }
                    }

                    if (!shouldBreakBlock) {
                        return 1;
                    }
                    m_maybeTouchedBreakableBlock = true;
                    if (m_gameLayer)
                        m_gameLayer->destroyObject(object);
                    else
                        object->destroyObject();
                    return 1;
                }
            }

            boolC = m_isUpsideDown || ((isFly || m_isBall) && !objPassable);
            if (boolJ && (boolC || boolB)) {
                if (m_isUpsideDown) {
                    minSnapY += (double)playerBottom;
                    floatL = floatG;
                }

                if (objRect.getMinY() < minSnapY && floatL > objRect.getMinY() && uuid != (m_isUpsideDown ? m_unk50C : m_unk510)) {
                    boolJ = true;
                } else if (m_isBird && isBreakable && !m_isPlatformer && !m_isUpsideDown) {
                    if (objRect.intersectsRect(getObjectRect(0.3, 0.3))){
                        if (m_gameLayer)
                            m_gameLayer->destroyObject(object);
                        else
                            object->destroyObject();
                        return 1;
                    }

                    boolJ = false;
                } else {
                    gravityMult = m_isUpsideDown ? -1 : 1;
                    if ((m_yVelocity >= 0.0 || m_wasOnSlope || boolL || (m_isPlatformer && m_yVelocityRelated > 0.0)) && (!boolE || !boolM)) {
                        if (canSnap && m_yVelocity * gravityMult > 0.0 && m_gameLayer) {
                            m_gameLayer->gameEventTriggered(GJGameEvent::HitHead, 0, m_uniqueID);
                        }

                        setPositionY(objRect.getMinY() - playerRect.size.height * 0.5);
                        if (vType == Cube) {
                            checkSnapJumpToObject(object);
                        }

                        if (!boolB || boolC) {
                            if (canSnap) {
                                bool tmp1 = m_isOnGround;
                                bool tmp2 = m_isOnGround2;
                                bool tmp3 = m_lastLandTime;
                                hitGround(nullptr, m_isUpsideDown && isFly);
                                m_isOnGround = tmp1;
                                m_isOnGround2 = tmp2;
                                m_lastLandTime = tmp3;
                            } else {
                                hitGround(object,m_isUpsideDown && isFly);
                            }
                        } else {
                            m_yVelocity = 0.0;
                        }

                        if (m_isUpsideDown) {
                            floatC = objRect.getMinY();
                        }

                        if (canSnap && !isBreakable && !objPassable) {
                            if (m_isUpsideDown) {
                                if (objRect.getMaxY() >= m_collidedTopMinY) {
                                    m_collidedTopMinY = objRect.getMaxY();
                                }

                                if (uuid && m_lastCollisionTop != uuid) {
                                    m_lastCollisionTop = uuid;
                                    if (m_collisionLogTop) {
                                        m_collisionLogTop->setObject(m_maybeLastGroundObject, uuid);
                                    }
                                }
                            } else {
                                updateCollideTop(objRect.getMinY(), object);
                            }
                        } else if (!canSnap) {
                            if (m_collidedBottomMaxY == 0 || (m_isUpsideDown ? floatC < m_collidedBottomMaxY : floatC > m_collidedBottomMaxY)) {
                                m_collidedBottomMaxY = floatC;
                            }

                            if (uuid && m_lastCollisionBottom != uuid) {
                                m_lastCollisionBottom = uuid;
                                if (m_collisionLogBottom) {
                                    m_collisionLogBottom->setObject(m_maybeLastGroundObject, uuid);
                                }
                            }
                        }

                        if (!canSnap) {
                            if (obj) {
                                m_lastGroundObject = obj;
                                if (obj->m_isDontBoostY)
                                    m_stateBoostX = 2;

                                if (obj->m_isDontBoostX)
                                    m_stateBoostY = 2;
                            }
                            m_groundYVelocity = newGroundVel;
                        }

                        if (m_isPlatformer) {
                            exitPlatformerAnimateJump();
                        }

                        if (vType == Cube && m_stateNoAutoJump > 0 && m_padRingRelated) {
                            m_jumpBuffered = false;
                        }

                        if (canSnap) {
                            if (m_stateFlipGravity > 0) {
                                flipGravity(!m_isUpsideDown, true);
                                setYVelocity(-2 * gravityMult, 0);

                                m_maybeIsBoosted = true;
                                m_isOnGround2 = false;
                                if (m_stateNoAutoJump > 0) {
                                    m_isOnGround = false;
                                    m_jumpBuffered = false;
                                    m_stateRingJump = false;
                                }
                            } else if (isFly && boolD) {
                                setYVelocity(m_groundYVelocity, 0);
                            }
                        }

                        if (!shouldBreakBlock) {
                            return 1;
                        }
                        m_maybeTouchedBreakableBlock = true;
                        if (m_gameLayer)
                            m_gameLayer->destroyObject(object);
                        else
                            object->destroyObject();
                        return 1;
                    } else if (canSnap || !boolD || !m_isUpsideDown) {
                        if (!m_isUpsideDown && boolH && canSnap) {
                            setPositionY(objRect.getMinY() - playerRect.size.height * 0.5);

                            bool tmp_1 = m_isOnGround;
                            bool tmp_2 = m_isOnGround2;
                            float tmp_3 = m_lastLandTime;
                            hitGround(nullptr, isFly);
                            m_isOnGround = tmp_1;
                            m_isOnGround2 = tmp_2;
                            m_lastLandTime = tmp_3;

                            if (!isBreakable && !objPassable) {
                                updateCollideTop(objRect.getMinY(), object);
                            }

                            setYVelocity(std::max(m_groundYVelocity - 1.0, m_yVelocity), 0);
                            if (m_stateFlipGravity > 0) {
                                flipGravity(!m_isUpsideDown, true);
                                setYVelocity(-2 * gravityMult, 0);

                                m_maybeIsBoosted = true;
                                m_isOnGround2 = false;
                                if (m_stateNoAutoJump > 0) {
                                    m_isOnGround = false;
                                    m_jumpBuffered = false;
                                    m_stateRingJump = false;
                                }
                            }
                            if (shouldBreakBlock) {
                                m_maybeTouchedBreakableBlock = true;

                                if (m_gameLayer)
                                    m_gameLayer->destroyObject(object);
                                else
                                    object->destroyObject();
                            }
                        }
                    }
                }
            }
        }
    }

    if (m_isPlatformer) {
        bool rightBtn = m_holdingRight;
        bool leftBtn = m_holdingLeft;

        if (rightBtn && leftBtn) {
            leftBtn = m_leftPressedFirst;
            rightBtn = !leftBtn;
        }

        bool boolY = false;
        bool boolP = false;
        float scaleXRelated4 = 0.0;

        if (param_f > 0.0 && obj) {
            adjustedY = m_isSideways ? getPositionX() : getPositionY();

            float diffY = adjustedObjY - adjustedObjLastY;
            boolY = diffY + scaleDeltaY < 0.0;
            boolP = diffY - scaleDeltaY > 0.0;
            if (adjustedObjY <= adjustedY) {
                scaleDeltaY = -scaleDeltaY;
            }

            scaleXRelated4 = (adjustedObjY - (adjustedObjLastY + scaleDeltaY)) / param_f;

        }

        double slopeSnapY;
        if (m_isOnSlope || m_wasOnSlope || m_totalTime - m_slopeEndTime < 0.2) {
            slopeSnapY = getPositionY() + playerHeight / 2. * (m_isUpsideDown ? -1 : 1);
        } else {
            slopeSnapY = origSnapUpThres + (getPositionY() - playerHeight / 2.);
        }

        bool collideWithLeft = obj ? m_collidingWithLeft == obj : false;
        bool collideWithRight = obj ? m_collidingWithRight == obj : false;

        CCRect someRect = playerRect;
        someRect.origin.y += floatT * 0.5;
        someRect.size.height -= floatT;

        if (!objPassable && (someRect.intersectsRect(objRect) || collideWithLeft || collideWithRight) && slopeSnapY < objRect.getMaxY() && objRect.getMinY() < slopeSnapY) {
            m_scaleXRelated4 = scaleXRelated4;
            bool platformerMoving;

            if (!collideWithLeft && (getPositionX() <= objRect.origin.x + objRect.size.width * 0.5 || collideWithRight)) {
                m_collidedRightMinX = m_collidedRightMinX == 0 ? objRect.getMinX() : std::max(m_collidedRightMinX, (double)objRect.getMinX());
                if (uuid) {
                    if (m_lastCollisionRight != uuid) {
                        m_lastCollisionRight = uuid;
                        if (m_collisionLogRight) {
                            m_collisionLogRight->setObject(m_maybeLastGroundObject, uuid);
                        }
                    }
                    m_collidingWithRight = object;
                    m_collidingWithLeft = nullptr;
                }

                setPositionX(objRect.getMinX() - playerRect.size.width * 0.5);
                if ((m_platformerXVelocity > 0.0) && (!rightBtn || !boolP)) {
                    m_platformerXVelocity = 0.0;
                }

                if (m_dashRing && (!m_dashRing || !m_dashRing->m_allowCollide)) {
                    stopDashing();
                    m_jumpBuffered = false;
                }
                platformerMoving = m_platformerMovingRight;
            } else {
                m_collidedLeftMaxX = m_collidedLeftMaxX == 0 ? objRect.getMaxX() : std::max(m_collidedLeftMaxX, (double)objRect.getMaxX());

                if (uuid) {
                    if (m_lastCollisionLeft != uuid) {
                        m_lastCollisionLeft = uuid;
                        if (m_collisionLogLeft) {
                            m_collisionLogLeft->setObject(m_maybeLastGroundObject, uuid);
                        }
                    }
                    m_collidingWithLeft = object;
                    m_collidingWithRight = nullptr;
                }

                setPositionX(objRect.getMaxX() + playerRect.size.width * 0.5);
                if (m_platformerXVelocity < 0.0 && (!leftBtn || !boolY)) {
                    m_platformerXVelocity = 0.0;
                }

                if (m_dashRing && (!m_dashRing || !m_dashRing->m_allowCollide)) {
                    stopDashing();
                    m_jumpBuffered = false;
                }
                platformerMoving = m_platformerMovingLeft;
            }

            if (platformerMoving) {
                m_maybeSlidingTime = 0;
            }
        }
    }

    if (!boolJ || m_isPlatformer || objPassable) {
        return 0;
    }

    CCRect smallHitbox = getObjectRect(0.3, 0.3);
    if (!objRect.intersectsRect(smallHitbox)) {
        return 0;
    }

    if (canSnap && m_lastFlipTime != 0.0 && m_totalTime - m_lastFlipTime < 0.1) {
        if (m_isUpsideDown) {
            setPositionY(floatC + playerRect.size.height * 0.5);
        } else {
            setPositionY(objRect.getMinY() - playerRect.size.height * 0.5);
        }

        hitGround(object, true);
        m_isOnGround2 = false;
        return 1;
    }

    if (m_isSpider && objRect.getMaxX() < smallHitbox.getMaxX() && m_lastSpiderFlipTime != 0.0 && m_totalTime - m_lastSpiderFlipTime < 0.04) {
        return 1;
    }

    if (object && object->getType() == GameObjectType::Breakable) {
        if (m_gameLayer)
            m_gameLayer->destroyObject(object);
        else
            object->destroyObject();
        return 1;
    } else {
        if (m_maybeCanRunIntoBlocks == false) {
            GameManager::sharedState()->m_playLayer->destroyPlayer(this, nullptr);
            return 1;
        } else if (m_ignoreDamage) {
            return 0;
        } else {
            m_maybeIsColliding = true;
            return 1;
        }
    }
}