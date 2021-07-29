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

constexpr int kUserCoin = 31;
constexpr int kSecretCoin = 22;

void PlayLayer::createObjectsFromSetup(std::string setupStr) {
    if (setupStr.size() > 1) {
            std::vector<std::string> objs = split(setupStr, ";");
            std::string header = objs[0];
            this->levelSettings = LevelSettingsObject::objectFromString(header);    

            this->levelSettings->retain();
            this->levelSettings->gameLevel = this->gameLevel;
            this->levelSettings->effectManager->updateColors(this->player1->pCol1, this->player1->pCol2);
            GM->loadFont(this->levelSettings->font);

            auto userCoins = cocos2d::CCArray::create(); // r14
            if (objs.size()>1) {
                    for (int i = 1; i < objs.size(); i++) {
                        auto object = GameObject::objectFromString(objs[i], this->gameLevel->lowDetailMode);

                        if (this->gameLevel->isOfficial && object->getType() == kSecretCoin)
                            continue

                        if (object) {
                            if (object->getType() == kUserCoin && userCoins->count() < 3) { 
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
    this->levelLength = this->trueLevelLength + 340;
    if (this->levelLength <= screenEnd) {
        this->levelLength = screenEnd;
    }
    this->endPortal = EndPortalObject::create();
    this->endPortal->setStartPos(ccp(this->levelLength, 225.0));
    reinterpret_cast<int>(this->endPortal->valOffset(0x3d4)) = 11;
    this->addToSection(this->endPortal);
    this->objects->addObject(this->endPortal);
    this->endPortal->updateColors(this->endPortal, this->player1->pCol1);
    this->endPortal->setVisible(false);
    reinterpret_cast<CCArray*>(this->valOffset(0x3c8))->addObject(this->endPortal);
    this->endPortal->calculateSpawnXPos();
    CCArray* idk = reinterpret_cast<CCArray*>(this->valOffset(0x548));
    qsort(idk->data, idk->count(), sizeof(CCObject*), xCompSpeed);
}