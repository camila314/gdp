int GameObject::objectFromString(std::string inputString, bool ldm) {
    auto mainMap = GameToolbox::stringSetupToMap(inputString, ",");

    bool highDetail = static_cast<bool>(atoi(mainMap["103"]));

    if (highDetail && ldm)
        return NULL;

    int objID = atoi(mainMap["1"]);
    int idBeforeSub = -1;

    if (objID == 717 || objID == 718 || objID == 743 || objID == 221) {     // color trigger 1,2,3,4
        idBeforeSub = objID;
        objID = 899;
    } else if (objID == 1008) {                                             // some gradient thing
        objID = 1292;
    } else if (objID == 104) {                                              // line trigger, this is stupid
        objID = 915;
        idBeforeSub = 104;
    }

    auto gameObj = GameObject::createWithKey(objID);
    if (!gameObj)
        return NULL;

    gameObj->objectID = objID;
    if (gameObj->objectID == 1715 || gameObj->objectID == 9) { // unknown_3d4 has haunted me for so long, im convinced its unused
            gameObj->unknown_3d4 = 2;
    }

    gameObj->addToGroup(gameObj, atoi(mainMap["26"]));
    gameObj->addToGroup(gameObj, atoi(mainMap["33"]));
    gameObj->loadGroupsFromString(mainMap["57"]);

    gameObj->zLayer = atoi(mainMap["24"]);
    gameObj->zOrder = atoi(mainMap["25"]);
    gameObj->customRotationSpeed = atoi(mainMap["97"]);
    gameObj->disableRotation = atoi(mainMap["98"]);
    gameObj->linkedGroup = atoi(mainMap["108"]);
    gameObj->highDetail = atoi(mainMap["103"]);
    gameObj->isGroupParent = atoi(mainMap["34"]);
    gameObj->dontFade = atoi(mainMap["64"]);
    gameObj->dontEnter = atoi(mainMap["67"]);
    gameObj->flippedHorizontal = atoi(mainMap["4"]);
    gameObj->flippedVertical = atoi(mainMap["5"]);
    gameObj->editorLayer1 = atoi(mainMap["20"]);
    gameObj->editorLayer2 = atoi(mainMap["61"]);
    gameObj->disableGlow = atoi(mainMap["96"]);
    float size = atof(mainMap["32"]); // size
    if (size != 0) {
            size = roundf(size*100)/100.0;
            gameObj->size = size;
            gameObj->setRScale(1.0);

            gameObj->objRectDirty = true;
            gameObj->textureRectDirty = true;
    }

    switch (objID) {
        case 914:
            gameObj->updateTextObject(LevelTools:base64DecodeString(mainMap["31"]));
            break;
        case 142:
            gameObj->secretCoinID = atoi(mainMap["12"]);
            break;
        case 31:
            auto settings = LevelSettingsObject::objectFromDict(GameToolbox::stringSetupToDict(arg0, ","));
            gameObj->setSettings(settings);
        case 200:
        case 201:
        case 202:
        case 203:
        case 660:
        case 1331:
        case 1334:
        case 47:
        case 111:
        case 13:
            gameObj->portalChecked = atoi(mainMap["13"]);
    }
    editorlayer1 = atoi(mainMap["20"]);
    editorlayer2 = atoi(mainMap["61"]);

    gameObj->multiActivate = atoi(mainMap["99"]);

    gameObj->customSetup();
    gameObj->customObjectSetup(mainMap);

    gameObj->addGlow();
    gameObj->addColorSprite();
    gameObj->setupCustomSprites();

    gameObj->setFlipX(gameObj->flippedHorizontal);
    gameObj->setFlipY(gameObj->flippedVertical);

    gameObj->objectRotation = atof(mainMap["6"]); // robtop doesn't actually do this, its just easier for me to do this and its functionally equivalent
    if (gameObj->objectType == 0 || gameObj->objectType == 21 || gameObj->objectType == 25) {
        gameObj->objectRotation = floor(var_rotation/90)*90;
    }
    gameObj->setRotation(gameObj->objectRotation);
    gameObj->setStartPos(ccp(atof(mainMap["2"]), atof(mainMap["3"])+90));
    gameObj->getObjectTextureRect();

    switch (idBeforeSub) {
        case 743:
            gameObj->colorID = 4;
            break;
        case 718:
            gameObj->colorID = 3;
            break;
        case 717:
            gameObj->colorID = 2;
            break;
        case 221:
            gameObj->colorID = 1;
            break;
        case 104:
            gameObj->blendingEnabled = true;
            break;
    }
    if (gameObj->animatedCircle) {
        gameObj->animationRandomStart = atoi(mainMap["106"]);
        gameObj->animationSpeed = atof(mainMap["107"]);
    }


    // both of these are guesswork. but they probably work so
    if (atoi(mainMap["41"])) {
    	gameObj->baseSpriteColor->hsv = GameToolbox::hsvFromString(std::string(mainMap["43"]), "a");
    }
    if (atoi(mainMap["42"])) {
    	gameObj->detailSpriteColor->hsv = GameToolbox::hsvFromString(std::string(mainMap["44"]), "a");
    }


	int legacyColorID;
    switch (atoi(mainMap["19"])) {
        case 0:
            int colorChannel = atoi(mainMap["21"]);
            if (colorChannel) {
                if (colorChannel < 0)
                    colorChannel = 1011;

                gameObj->baseSpriteColor->colorID = colorChannel;
            }

            colorChannel = atoi(mainMap["22"]);
            if (colorChannel) {
                if (gameObj->detailSpriteColor) {
                    if (colorChannel < 0)
                        colorChannel = 1011;

                    gameObj->detailSpriteColor->colorID = colorChannel;
                }
            }

            gameObj->saveActiveColors();
            return gameObj;
        case 1:
            break;
        case 2:
            legacyColorID = 1006;
            break;
        case 3:
            legacyColorID = 1;
            break;
        case 4:
            legacyColorID = 2;
            break;
        case 5:
            legacyColorID = 1007;
            break;
        case 6:
            legacyColorID = 3;
            break;
        case 7:
            legacyColorID = 4;
            break;
        case 8:
            legacyColorID = 1003;
            break;
        default:
            gameObj->saveActiveColors();
            return gameObj;
    }

    auto spritecol = gameObj->detailSpriteColor;
    if (!spritecol) {
            spritecol = gameObj->baseSpriteColor;
    }
    spritecol->colorID = legacyColorID;
    gameObj->saveActiveColors();
    return gameObj;
}
