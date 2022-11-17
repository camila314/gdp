HardStreak::updateStroke(float dt) {
    this->clear();
    int runs = (m_isSolid ? 1 : 2);

    for (int makeSolid = 0; makeSolid < runs; ++makeSolid) {
        if (m_pointsArr->count() == 0) {
            continue;
        }

        for (int pointIdx = 0; pointIdx < m_pointsArr->count(); ++pointIdx) {
            point = m_pointsArr->objectAtIndex(pointIdx)->m_point; // r15
            nextPoint = m_currentPoint;

            if (pointIdx < m_pointsArr->count() - 1) {
                nextPoint = m_pointsArr->objectAtIndex(m_pointsArr, pointIdx + 1)->m_point;
            }

            var_50 = cocos2d::CCPoint();
            var_48 = cocos2d::CCPoint();
            var_40 = cocos2d::CCPoint();
            var_38 = cocos2d::CCPoint();

            float mult = makeSolid ? 2 : 6;
            float size_90 = m_waveSize * m_pulseSize * mult * 0.5;

            CCPoint pos_78;

            if (size_90 < 0.5) {
                pos_78 = cocos2d::CCPoint(global_69c540);
            } else {
                double angle = atan2(nextPoint.y - point.y, nextPoint.x - point.x) + PI/2;
                if (angle > PI*2) {
                    angle -= PI*2;
                } else if (angle < 0) {
                    angle += PI*2;
                }

                pos_78 = cocos2d::CCPoint(cos(angle) * size_90, sin(angle) * size_90);
            }

            float tangent = tanf(asinf(fabs(pos_78.x) / size_90));

            if (pointIdx >= m_pointsArr->count() - 1 && !makeSolid) {
                if (fabs(cocos2d::ccpDistance(point, nextPoint)) > 10) {
                    float some_value = fabs(tangent * 4.0);

                    nextPoint.x -= 4;

                    if (point.y < nextPoint.y)
                        nextPoint.y -= some_value;
                    else
                        nextPoint.y += some_value;
                }
            }

            var_70 = cocos2d::CCPoint(point);
            var_68 = cocos2d::CCPoint(nextPoint);

            float absolute_pos = fabs(pos_78.x);

            var_70.x -= absolute_pos;
            var_68.x += absolute_pos;
            if (makeSolid) {
                point.x += absolute_pos;
                nextPoint.x -= absolute_pos;
            }

            float some_tangent = fabs(pos_78.x * tangent);

            if (var_68.y <= var_70.y) {
                some_tangent = -some_tangent;
            }

            var_70.y -= some_tangent;
            var_68.y += some_tangent;
            if (makeSolid) {
                point.y += some_tangent;
                nextPoint.y -= some_tangent;
            }

            if (xmm1 > xmm0) {
                rsi = var_70;
                var_70 = point;
                r15 = var_68;
                var_68 = nextPoint;
            } else {
                rsi = point;
                r15 = nextPoint;
            }

            var_50 = rsi - pos_78;
            var_48 = var_70 + pos_78;
            if (pointIdx >= m_pointsArr->count() - 1 && !var_68) {
                    r15 = nextPoint;
            }
            if (CPU_FLAGS & NE) {
                    var_68 = nextPoint;
            }
            var_40 = r15 + var_78
            var_38 = var_68 - pos_78;

            cocos2d::_ccColor3B color = ccc3(255, 255, 255);
            if (!makeSolid) {
                color = this->getColor();
            }

            float opacity = this->getOpacity() / 255.0;
            if (makeSolid) {
                opacity *= 0.65;
            }
            this->drawPolygon(var_50, 4, ccc4f(color.r / 255.0, color.g / 255.0, color.b / 255.0, opacity), 0.0, ccc4f(0, 0, 0, 0));
        }
    } 
}
