double GameObject::slopeYPos(float playerX) {
    CCRect objectRect = this->getObjectRect();
    float slopeLeft = objectRect->getMinX();
    float slopeRight = objectRect->getMaxX();
    float slopeBottom = objectRect->getMinY();
    float slopeTop = objectRect->getMaxY();
    float slopeRatio = (objectRect.size.height / objectRect.size.width);

    float result;
    if (slopeLeft < playerX) {
        float distanceFromRight = playerX - slopeRight;
        if (this->m_slopeUphill)
            result = slopeTop + distanceFromRight * slopeRatio;
        else
            result = slopeBottom - distanceFromRight * slopeRatio;
    } else {
    	float distanceFromLeft = slopeLeft - playerX;
    	if (!this->m_slopeUphill)
    	    result = slopeTop + distanceFromLeft * slopeRatio;
    	else
    		result = slopeBottom - distanceFromLeft * slopeRatio;
    }

    if (m_slopeIsHazard)
    	result += (this->slopeFloorTop() ? -4 : 4);

    return result;
}