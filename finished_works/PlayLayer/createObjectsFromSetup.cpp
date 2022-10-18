template<typename Out>
void split(const std::string &s, char delim, Out result) {
    std::stringstream ss;
    ss.str(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        *(result++) = item;
    }
}

std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, std::back_inserter(elems));
    return elems;
}

enum CoinType {
    kSecretCoin = 22;
    kUserCoin = 31;
}

void PlayLayer::createObjectsFromSetup(std::string setupStr) {
    if (setupStr.size() > 1) {
            std::vector<std::string> objs = split(setupStr, ";");
            std::string header = objs[0];
            m_levelSettings = LevelSettingsObject::objectFromString(header);    

            m_levelSettings->retain();
            m_levelSettings->gameLevel = m_gameLevel;
            m_levelSettings->effectManager->updateColors(m_player1->pCol1, m_player1->pCol2);
            GM->loadFont(m_levelSettings->font);

            auto userCoins = cocos2d::CCArray::create();
            if (objs.size()>1) {
                    for (int i = 1; i < objs.size(); i++) {
                        auto object = GameObject::objectFromString(objs[i], m_gameLevel->lowDetailMode);

                        if (m_gameLevel->isOfficial && object->getType() == CoinType::kSecretCoin)
                            continue

                        if (object) {
                            if (object->m_objectType == GameObjectType::UserCoin && userCoins->count() < 3) { 
                                userCoins->addObject(object);
                            }
                            this->addObject(object);
                        }
                    }
            }
            if (userCoins->count()) {
                    qsort(userCoins->data, userCoins->count(), sizeof(CCObject*), xCompRealPos);
                    CCObject* ob;
                    for (int i = 0; i < userCoins->count(); i++) {
                        if (i>2)
                            break;
                        GameObject* gob = userCoins->objectAtIndex(i);
                        gob->coinID = i+1;
                        gob->setupCoinArt();
                    }
            }
    }

    float screenEnd = CCDirector::sharedDirector()->getScreenRight() + 300;
    m_levelLength = m_trueLevelLength + 340;
    if (m_levelLength <= screenEnd) {
        m_levelLength = screenEnd;
    }
    m_endPortal = EndPortalObject::create();
    m_endPortal->setStartPos(ccp(m_levelLength, 225.0));
    m_endPortal->m_defaultZOrder = 11;
    this->addToSection(m_endPortal);

    m_objects->addObject(m_endPortal);
    m_endPortal->updateColors(m_endPortal, m_player1->pCol1);
    m_endPortal->setVisible(false);
    m_unk248->addObject(m_endPortal);
    m_endPortal->calculateSpawnXPos();
    qsort(this->unk3CC->data, this->unk3CC->count(), sizeof(CCObject*), xCompSpeed);
}
