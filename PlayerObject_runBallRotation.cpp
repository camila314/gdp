void PlayerObject::runBallRotation(float speed) {
    if (m_isDashing || m_isPlatformer)
        return;

    m_rotateSpeed = speed;
    m_isBallRotating = speed != 1.0;

    float v5 = (m_vehicleSize != 1.0 ? 0.16 : 0.2);
    switch ((int)(m_playerSpeed * 10)) {
    case 7:
    	v5 *= 1.2405638;
    	break;
    case 11:
    	v5 *= 0.80424345;
    	break;
    case 13:
    	v5 *= 0.6657693;
    	break;
    case 16:
    	v5 *= 0.5409375;
    	break;
    default:
    	break;
    }

    m_rotationSpeed = (120 * this->flipMod() * this->reverseMod() * (m_isSideways ? -1 : 1)) / v5;
    m_isRotating = true;
}
