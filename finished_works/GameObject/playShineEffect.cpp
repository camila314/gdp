void GameObject::playShineEffect() {
    if (m_activated || m_activatedp2 || this->getOpacity() == 0 || PL==NULL)
        return;

    std::string shineFrame;
    bool playCircle;

    if (m_objectID == 1331) {
        shineFrame = "portal_16_shine_001.png";
        playCircle = false;
    } else if (m_objectID < 204 || m_objectID == 1334) {
        shineFrame = StaticTools::replaceAll(m_textureName, "_001.png", "_shine_001.png");
        playCircle = true;
    } else {
        shineFrame = StaticTools::replaceAll(m_textureName, "_front_001.png", "_shine_001.png");
        playCircle = false;
    }

    auto circleColor = ccc3(255, 255, 0);
    switch (m_objectID) {
        case 201:
            circleColor = ccc3(0, 150, 255);//0xff9600;
            break;
        case 202:
            circleColor = ccc3(0, 255, 150);//0x96ff00;
            break;
        case 203:
            circleColor = ccc3(255, 0, 255);//0xff00ff;
            break;
        case 1334:
            circleColor = ccc3(255, 50, 50);//0x3232ff;
            break;
        default:
            if (m_objectID > 203) {
                circleColor = ccc3(0, 150, 255);//0xff9600;
            } else {
                circleColor = ccc3(255, 255, 255);
            }
    }

    auto shineSprite = CCSpritePlus::createWithSpriteFrameName(shineFrame.c_str());
    if (this->getParent()) {
        PL->m_objectLayer->addChild(shineSprite, this->getParent()->getZOrder(); + 1);
    }
    shineSprite->setPosition(shineSprite, this->getRealPosition());
    shineSprite->setRotation(this->getRotation());
    shineSprite->setFlipX(this->isFlipX());
    shineSprite->setFlipY(this->isFlipY());
    shineSprite->setScaleX(this->getScaleX());
    shineSprite->setScaleY(this->getScaleY());
    shineSprite->setOpacity(this->getOpacity());
    shineSprite->followSprite(this);
    shineSprite->setBlendFunc({700, 1});

    auto sequence = CCSequence::create(
        CCFadeIn::create(0.05),
        CCFadeOut::create(0.3),
        CCCallFunc::create(shineSprite, &CCSpritePlus::stopFollow),
        CCCallFunc::create(shineSprite, 521) // ¿qué?
    );
    shineSprite->runAction(sequence);

    if (playCircle) {
        float duration = 70.0;
        switch (m_objectID) {
            case 200:
                duration = 60.0;
                break;
            case 201:
                duration = 65.0;
                break;
            case 203:
                duration = 80.0;
                break;
            case 1334:
                duration = 90.0;
                break;
            default:
                duration = 70.0;
                break;
        }
        auto circleWave = CCCircleWave::create(5.0, duration, 0.3, false);
        circleWave->m_color = circleColor;

        circleWave->setPosition(this->getPosition());
        if (this->getParent()) {
            PL->m_objectLayer->addChild(circleWave, this->getParent()->getZOrder() - 1);
        }
        
        //*(circleWave + 0x140) = 0x600000001; ill sort this out later, its just visual who cares
        circleWave->followObject(this, true);
        circleWave->m_delegate = PL;
        PL->addCircle(circleWave);
    }
}