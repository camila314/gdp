PlayLayer::updateProgressbar() {
    auto newWidth = (m_player1->getPositionX() / m_levelLength);

    newWidth = fmax(newWidth, 0.001);
    newWidth = fmin(newWidth * m_sliderSize.width, m_sliderSize.width);

    m_sliderBarSprite->setTextureRect(CCRect(0, 0, newWidth, m_sliderSize.height));

    if (m_percentLabel->isVisible()) {
        percent = (m_player1->getPositionX() / m_levelLength) * 100;

        if (percent < 0)
            percent = 0;

        if (percent > 100)
            percent = 100;

        m_percentLabel->setString(CCString::createWithFormat("%i%%", percent)->getCString());
    }
}
