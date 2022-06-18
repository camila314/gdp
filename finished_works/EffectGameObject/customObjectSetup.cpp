EffectGameObject::customObjectSetup(std::map<std::string, std::string> mainMap) {

    m_touchTriggered = atoi(mainMap["11"]);
    m_spawnTriggered = atoi(mainMap["62"]);
    m_multiTrigger = atoi(mainMap["87"]);

    switch (m_objectID) {
        case 901:
            m_easingRate = atof(mainMap["85"]);
            m_targetGroupID = atoi(mainMap["51"]);
            m_move = ccp(atoi(mainMap["28"]), atoi(mainMap["29"]));
            m_duration = atof(mainMap["10"]);
            m_easingType = atoi(mainMap["30"]);
            m_lockToPlayerX = atoi(mainMap["58"]);
            m_lockToPlayerY = atoi(mainMap["59"]);
            m_useTarget = atoi(mainMap["100"]);
            m_centerGroupID = atoi(mainMap["71"]);
            m_moveTargetType = atoi(mainMap["101"]);
            break;
        case 1006:
            m_targetGroupID = atof(mainMap["51"]);
            m_fadeInTime = atof(mainMap["45"]);
            m_holdTime = atof(mainMap["46"]);
            m_fadeOutTime = atof(mainMap["47"]);
            m_pulseHSVMode = atoi(mainMap["48"]);
            m_pulseMainOnly = atoi(mainMap["65"]);
            m_pulseDetailOnly = atoi(mainMap["66"]);
            m_pulseGroupMode = atoi(mainMap["52"]);
            m_pulseExclusive = atoi(mainMap["86"]);

            if (m_pulseHSVMode) {
                m_HSVValue = GameToolbox::hsvFromString(mainMap["49"], "a");
                m_copyColorID = atoi(mainMap["50"]);
            } else {
                m_unknownColor = ccc3(atoi(mainMap["7"]), atoi(mainMap["8"]), atoi(mainMap["9"]));
            }

            m_targetGroupID = atof(mainMap["51"]);
            m_duration = atof(mainMap["10"]);
            m_opacity = atof(mainMap["35"]);
            break;
        case 1007:
            m_targetGroupID = atoi(mainMap["51"]);
            m_duration = atof(mainMap["10"]);
            m_opacity = atof(mainMap["35"]);
            break;
        case 1049:
            m_targetGroupID = atof(mainMap["51"]);
            m_activateGroup = atoi(mainMap["56"]);
            break;
        case 1268:
            m_targetGroupID = atoi(mainMap["51"]);
            m_spawnDelay = atof(mainMap["63"]);
            m_editorDisabled = atoi(mainMap["102"]);
            break;
        case 1275:
            m_targetGroupID = atoi(mainMap["51"]);
            m_subtractCount = atoi(mainMap["78"]);
            m_pickupMode = atoi(mainMap["79"]);
            m_targetItemID = atoi(mainMap["80"]);
            m_activateGroup = atoi(mainMap["56"]);
            break;
        case 1346:
            m_targetGroupID = atoi(mainMap["51"]);
            m_centerGroupID = atoi(mainMap["71"]);
            m_duration = atof(mainMap["10"]);
            m_easingType = atoi(mainMap["30"]);

            m_easingRate = atof(mainMap["85"]);
            m_rotateDegrees = atoi(mainMap["68"]);
            m_times360 = atoi(mainMap["69"]);
            m_lockObjectRotation = atoi(mainMap["70"]);
            break;
        case 1347:
            m_targetGroupID = atoi(mainMap["51"]);
            m_centerGroupID = atoi(mainMap["71"]);
            m_duration = atof(mainMap["10"]);
            m_followMod = ccp(atof(mainMap["72"]), atof(mainMap["73"]));
            UndocuementedLevelProperty74 = atoi(mainMap["74"]);
            break;
        case 1520:
            m_duration = atof(mainMap["10"]);
            m_shakeStrength = atof(mainMap["75"]);
            m_shakeInterval = atof(mainMap["84"]);
            break;
        case 1585:
            m_targetGroupID = atoi(mainMap["51"]);
            m_animationID = atoi(mainMap["76"]);
            break;
        case 1595:
            m_targetGroupID = atoi(mainMap["51"]);
            m_activateGroup = atoi(mainMap["56"]);
            m_touchHoldMode = atoi(mainMap["81"]);
            m_touchToggleMode = atoi(mainMap["82"]);
            m_touchDualMode = atoi(mainMap["89"]);
            break;
        case 1611:
            m_targetItemID = atoi(mainMap["80"]);
            m_targetGroupID = atoi(mainMap["51"]);
            m_targetCount = atoi(mainMap["77"]);
            m_activateGroup = atoi(mainMap["56"]);
            m_multiActivate = atoi(mainMap["104"]);
            break;
        case 1616:
            m_targetGroupID = atoi(mainMap["51"]);
            break;
        case 1587:
        case 1589:
        case 1598:
        case 1614:
            m_targetGroupID = atoi(mainMap["51"]);
            m_subtractCount = atoi(mainMap["78"]);
            m_pickupMode = atoi(mainMap["79"]);
            m_targetItemID = atoi(mainMap["80"]);
            m_activateGroup = atoi(mainMap["56"]);
            break;
        case 1811:
            m_targetItemID = atoi(mainMap["80"]);
            m_targetGroupID = atoi(mainMap["51"]);
            m_targetCount = atoi(mainMap["77"]);
            m_comparisonType = atoi(mainMap["88"]);
            m_activateGroup = atoi(mainMap["56"]);
            break;
        case 1812:
            m_targetGroupID = atoi(mainMap["51"]);
            m_activateGroup = atoi(mainMap["56"]);
            break;
        case 1814:
            m_followYSpeed = atof(mainMap["90"]);
            m_followYDelay = atof(mainMap["91"]);
            m_followYOffset = atoi(mainMap["92"]);
            m_followYMaxSpeed = atof(mainMap["105"]);
            m_targetGroupID = atoi(mainMap["51"]);
            m_duration = atof(mainMap["10"]);
            break;
        case 1815:
            m_targetItemID = atoi(mainMap["80"]);
            m_blockBID = atoi(mainMap["95"]);
            m_targetGroupID = atoi(mainMap["51"]);
            m_duration = atof(mainMap["10"]);
            m_triggerOnExit = atoi(mainMap["93"]);
            m_activateGroup = atoi(mainMap["56"]);
            break;
        case 1816:
            m_targetItemID = atoi(mainMap["80"]);
            m_dynamicBlock = atoi(mainMap["94"]);
            break;
        case 1817:
            m_targetItemID = atoi(mainMap["80"]);
            m_targetCount = atoi(mainMap["77"]);
            break;

        default:
            break;
    }

    if (m_objectID == 105 || m_objectID < 31 || (743 < m_objectID && m_objectID < 901) || m_objectID == 915) {
        m_unknownColor = ccc3(atoi(mainMap["7"]), atoi(mainMap["8"]), atoi(mainMap["9"]));
        m_duration = atof(mainMap["10"]);

        m_tintGround = atof(mainMap["14"]);
        m_playerColor1 = atof(mainMap["15"]);
        m_playerColor2 = atof(mainMap["16"]);
        m_blending = atof(mainMap["17"]);
        m_copyOpacity = atof(mainMap["60"]);

        int targetCol = atoi(mainMap["23"]);
        if (targetCol > 1) {
            m_targetColorID = targetCol;
        }

        m_opacity = atoi(mainMap["36"]) ? atof(mainMap["35"]) : 1.0;

        m_HSVValue = GameToolbox::hsvFromString(mainMap["49"], "a");
        m_copyColorID = atof(mainMap["50"]);

        if (m_objectID < 31 || m_objectID == 105 || m_objectID == 900) {
            m_blending = false;
            m_opacity = 1.0;
        }
    }

    if (m_easingRate <= 0.0) {
            m_easingRate = 2.0;
    }
}