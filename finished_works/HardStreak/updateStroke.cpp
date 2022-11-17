void HardStreak::updateStroke(float dt) {
	this->clear();
	int runs = (m_isSolid ? 1 : 2);

	for (int makeSolid = 0; makeSolid < runs; ++makeSolid) {
		// no idea why this isn't a break statement
	    if (m_pointsArr->count() == 0) {
	        continue;
	    }

	    for (int pointIdx = 0; pointIdx < m_pointsArr->count(); ++pointIdx) {
	        auto point = reinterpret_cast<PointNode*>(m_pointsArr->objectAtIndex(pointIdx))->m_point;
	        auto nextPoint = m_currentPoint;

	        if (pointIdx < m_pointsArr->count() - 1) {
	            nextPoint = reinterpret_cast<PointNode*>(m_pointsArr->objectAtIndex(pointIdx + 1))->m_point;
	        }

	        float streakSize = m_waveSize * m_pulseSize * (makeSolid ? 2 : 6) * 0.5;

	        // X and Y offset from the edge of the streak to the center perpendicular to the direction of the streak
	        CCPoint streakLineOffset = CCPointZero;

	        if (streakSize >= 0.5) {
	            double angle = atan2(nextPoint.y - point.y, nextPoint.x - point.x) + PI/2;
	            if (angle > PI*2) {
	                angle -= PI*2;
	            } else if (angle < 0) {
	                angle += PI*2;
	            }

	            streakLineOffset = ccp(cos(angle) * streakSize, sin(angle) * streakSize);
	        }

	        // 0 for stationary, 1 for big wave, 2 for small wave
	        float directionMultiplier = tanf(asinf(fabs(streakLineOffset.x) / streakSize));

	        // Adjust streak to match where the player is rotated to
	        if (pointIdx >= m_pointsArr->count() - 1 && !makeSolid) {
	            if (fabs(ccpDistance(point, nextPoint)) > 10) {
	                float playerOffset = fabs(directionMultiplier * 4.0);

	                nextPoint.x -= 4;

	                if (point.y < nextPoint.y)
	                    nextPoint.y -= playerOffset;
	                else
	                    nextPoint.y += playerOffset;
	            }
	        }

	        CCPoint streak[4] = {point, point, nextPoint, nextPoint};

	        // Streak bounds 
	        CCPoint streakBounds = ccp(fabs(streakLineOffset.x), fabs(streakLineOffset.x * directionMultiplier));

	        if (streak[3].y <= streak[1].y) {
	            streakBounds.y = -streakBounds.y;
	        }

	        streak[1] = streak[1] - streakBounds;
	        streak[3] = streak[3] + streakBounds;

	        if (makeSolid) {
	            point = point + streakBounds;
	            nextPoint = nextPoint - streakBounds;
	        }

	        // flip it
	        if (streak[3].y > streak[1].y) {
	            streak[0] = streak[1];
	            streak[2] = streak[3];
	            streak[1] = point;
	            streak[3] = nextPoint;
	        }

	        if (pointIdx >= m_pointsArr->count() - 1 && !makeSolid) {
	            streak[2] = nextPoint;
	            streak[3] = nextPoint;
	        }

	        streak[0] = streak[0] - streakLineOffset;
	        streak[1] = streak[1] + streakLineOffset;
	        streak[2] = streak[2] + streakLineOffset;
	        streak[3] = streak[3] - streakLineOffset;

	        _ccColor3B color = ccc3(255, 255, 255);
	        if (!makeSolid)
	            color = this->getColor();

	        float opacity = this->getOpacity() / 255.0;
	        if (makeSolid)
	            opacity *= 0.65;

	        this->drawPolygon(streak, 4, ccc4f(color.r / 255.0, color.g / 255.0, color.b / 255.0, opacity), 0.0, ccc4f(0, 0, 0, 0));
	    }
	} 
}
