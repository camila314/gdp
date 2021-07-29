void PlayerObject::propellPlayer(float arg1) {
    m_isRising = 0x1;
    m_isSliding = 0x0;
    m_onGround = 0x0;
    m_unknown_62b = 0x1;
    m_yAccel = 16.00 * arg1 * (m_upsideDown ? -1.0 : 1.0) * (m_vehicleSize == 1.0 ? 1.0 : 0.8);

    if (m_isBall || m_isSpider) {
        m_yAccel *= 0.6;
    }
    this->runRotateAction(false, -1);
    if (GM->m_ldm && m_inPlayLayer) {
        circleWave = CCCircleWave::create(arg1 == 1.25 ? 12.0 : 10.0, 40.0, 0.25, false);

        auto col = ccc3(255, 200, 0);
        if (arg1 == 0.8) {
            col = ccc3(0, 255, 255);
        } else if (arg1 < 1.0) {
            col = ccc3(255, 0, 255);
        }
        circleWave->m_color = col;
        circleWave->setPosition(m_lastPortalLocation);

        if (m_lastPortal) {
            circleWave->followObject(m_lastPortal, true);
            circleWave->m_delegate = PL;
            PL->addCircle(circleWave);
        }
        m_layer_798->addCircle(circleWave, 0);
    }
    if (m_isRobot) {
        m_robotSprite->runAnimation("jump_start");
    } else if (m_isSpider) {
        m_spiderSprite->runAnimation("fall_loop");
    }
    this->activateStreak();
    m_lastHitGroun d= this->getPosition();
}
