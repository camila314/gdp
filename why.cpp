EffectGameObject::customObjectSetup(int arg1) { // effectgameobject

    *(int8_t *)(this + 0x378) = atoi(mainMap["11"]);
    *(int8_t *)(this + 0x379) = atoi(mainMap["62"]);
    *(int8_t *)(this + 0x594) = atoi(mainMap["87"]);

    switch (m_objectID) {
        case 901:
            *(int32_t *)(this + 0x4f8) = atoi(mainMap["51"]);
            var_40 = cocos2d::CCPoint::CCPoint(atoi(mainMap["28"]), atoi(mainMap["29"]));
            cocos2d::CCPoint::operator=(this + 0x50c, var_40);



            var_70 = atof(mainMap["85"]);
            if (var_70 <= 0.0) {
                var_70 = 2.0;
            }

            *(int32_t *)(this + 0x4f0) = atof(mainMap["10"]);
            *(int32_t *)(this + 0x514) = atoi(mainMap["30"]);
            *(int32_t *)(this + 0x518) = var_70;
            *(int8_t *)(this + 0x51c) = atoi(mainMap["58"]);
            *(int8_t *)(this + 0x51d) = atoi(mainMap["59"]);
            *(int8_t *)(this + 0x51e) = atoi(mainMap["100"]);
            *(int32_t *)(this + 0x4fc) = atoi(mainMap["71"]);
            *(int32_t *)(this + 0x520) = atoi(mainMap["101"]);
            break;
        case 1006:
            *(int32_t *)(this + 0x4f8) = atof(mainMap["51"]);
            *(int32_t *)(this + 0x54c) = atof(mainMap["45"]);
            *(int32_t *)(this + 0x550) = atof(mainMap["46"]);
            *(int32_t *)(this + 0x554) = atof(mainMap["47"]);
            *(int32_t *)(this + 0x558) = atof(mainMap["48"]);
            *(int8_t *)(this + 0x575) = atof(mainMap["65"]);
            *(int8_t *)(this + 0x576) = atof(mainMap["66"]);
            *(int32_t *)(this + 0x55c) = atof(mainMap["52"]);
            *(int8_t *)(this + 0x577) = atof(mainMap["86"]);

            if (*(int32_t *)(this + 0x558) != 0x0) {
                *(this + 0x560) = GameToolbox::hsvFromString(mainMap["49"], "a");
                *(int32_t *)(this + 0x570) = atof(mainMap["50"]);
            } else {
                *(int16_t *)(this + 0x4ed) = ccc3(atoi(mainMap["7"]), atoi(mainMap["8"]), atoi(mainMap["9"]));
            }

            *(int32_t *)(this + 0x4f8) = atof(mainMap["51"]);
            *(int32_t *)(this + 0x4f0) = atof(mainMap["10"]);
            *(int32_t *)(this + 0x4f4) = atof(mainMap["35"]);
            break;
        case 1007:
            *(int32_t *)(this + 0x4f8) = atoi(mainMap["51"]);
            *(int32_t *)(this + 0x4f0) = atof(mainMap["10"]);
            *(int32_t *)(this + 0x4f4) = atof(mainMap["35"]);
            break;
        case 1049:
            *(int32_t *)(this + 0x4f8) = atof(mainMap["51"]);
            *(int8_t *)(this + 0x578) = atoi(mainMap["56"]);
            break;
        case 1268:
            *(int32_t *)(this + 0x4f8) = atoi(mainMap["51"]);
            *(int32_t *)(this + 0x588) = atof(mainMap["63"]);
            *(int8_t *)(this + 0x595) = atoi(mainMap["102"]);
            break;
        case 1275:
            *(int32_t *)(this + 0x4f8) = atoi(mainMap["51"]);
            *(int8_t *)(this + 0x59c) = atoi(mainMap["78"]);
            *(int32_t *)(this + 0x5b4) = atoi(mainMap["79"]);
            *(int32_t *)(this + 0x5b0) = atoi(mainMap["80"]);
            *(int8_t *)(this + 0x578) = atoi(mainMap["56"]);
            break;
        case 1346:
            *(int32_t *)(this + 0x4f8) = atoi(mainMap["51"]);
            *(int32_t *)(this + 0x4fc) = atoi(mainMap["71"]);
            *(int32_t *)(this + 0x4f0) = atof(mainMap["10"]);
            *(int32_t *)(this + 0x514) = atoi(mainMap["30"]);

            xmm1 = atof(mainMap["85"]);
            if (xmm1 <= 0.0) {
                xmm1 = 2.0;
            }
            *(int32_t *)(this + 0x518) = xmm1;
            *(int32_t *)(this + 0x524) = atoi(mainMap["68"]);
            *(int32_t *)(this + 0x528) = atoi(mainMap["69"]);
            *(int8_t *)(this + 0x52c) = atoi(mainMap["70"]);
            break;
        case 1347:
            *(int32_t *)(this + 0x4f8) = atoi(mainMap["51"]);
            *(int32_t *)(this + 0x4fc) = atoi(mainMap["71"]);
            *(int32_t *)(this + 0x4f0) = atof(mainMap["10"]);
            *(int32_t *)(this + 0x530) = atof(mainMap["72"]);
            *(int32_t *)(this + 0x534) = atof(mainMap["73"]);
            *(int8_t *)(this + 0x538) = atoi(mainMap["74"]);
            break;
        case 1520:
            *(int32_t *)(this + 0x4f0) = atof(mainMap["10"]);
            *(int32_t *)(this + 0x500) = atof(mainMap["75"]);
            *(int32_t *)(this + 0x504) = atof(mainMap["84"]);
            break;
        case 1585:
            *(int32_t *)(this + 0x4f8) = atoi(mainMap["51"]);
            *(int32_t *)(this + 0x584) = atoi(mainMap["76"]);
            break;
        case 1595:
            *(int32_t *)(this + 0x4f8) = atoi(mainMap["51"]);
            *(int8_t *)(this + 0x578) = atoi(mainMap["56"]);
            *(int8_t *)(this + 0x579) = atoi(mainMap["81"]);
            *(int32_t *)(this + 0x57c) = atoi(mainMap["82"]);
            *(int8_t *)(this + 0x580) = atoi(mainMap["89"]);
            break;
        case 1611:
            *(int32_t *)(this + 0x5b0) = atoi(mainMap["80"]);
            *(int32_t *)(this + 0x4f8) = atoi(mainMap["51"]);
            *(int32_t *)(this + 0x598) = atoi(mainMap["77"]);
            *(int8_t *)(this + 0x578) = atoi(mainMap["56"]);
            *(int8_t *)(this + 0x5a4) = atoi(mainMap["104"]);
            break;
        case 1616:
            *(int32_t *)(this + 0x4f8) = atoi(mainMap["51"]);
            break;
        case 1587:
        case 1589:
        case 1598:
        case 1614:
            *(int32_t *)(this + 0x4f8) = atoi(mainMap["51"]);
            *(int8_t *)(this + 0x59c) = atoi(mainMap["78"]);
            *(int32_t *)(this + 0x5b4) = atoi(mainMap["79"]);
            *(int32_t *)(this + 0x5b0) = atoi(mainMap["80"]);
            *(int8_t *)(this + 0x578) = atoi(mainMap["56"]);
            break;
        case 1811:
            *(int32_t *)(this + 0x5b0) = atoi(mainMap["80"]);
            *(int32_t *)(this + 0x4f8) = atoi(mainMap["51"]);
            *(int32_t *)(this + 0x598) = atoi(mainMap["77"]);
            *(int32_t *)(this + 0x5a0) = atoi(mainMap["88"]);
            *(int8_t *)(this + 0x578) = atoi(mainMap["56"]);
            break;
        case 1812:
            *(int32_t *)(this + 0x4f8) = atoi(mainMap["51"]);
            *(int8_t *)(this + 0x578) = atoi(mainMap["56"]);
            break;
        case 1814:
            *(int32_t *)(this + 0x53c) = atof(mainMap["90"]);
            *(int32_t *)(this + 0x540) = atof(mainMap["91"]);
            *(int32_t *)(this + 0x544) = atoi(mainMap["92"]);
            *(int32_t *)(this + 0x548) = atof(mainMap["105"]);
            *(int32_t *)(this + 0x4f8) = atoi(mainMap["51"]);
            *(int32_t *)(this + 0x4f0) = atof(mainMap["10"]);
            break;
        case 1815:
            *(int32_t *)(this + 0x5b0) = atoi(mainMap["80"]);
            *(int32_t *)(this + 0x5a8) = atoi(mainMap["95"]);
            *(int32_t *)(this + 0x4f8) = atoi(mainMap["51"]);
            *(int32_t *)(this + 0x4f0) = atof(mainMap["10"]);
            *(int8_t *)(this + 0x5a5) = atoi(mainMap["93"]);
            *(int8_t *)(this + 0x578) = atoi(mainMap["56"]);
            break;
        case 1816:
            *(int32_t *)(this + 0x5b0) = atoi(mainMap["80"]);
            *(int8_t *)(this + 0x5ac) = atoi(mainMap["94"]);
            break;
        case 1817:
            *(int32_t *)(this + 0x5b0) = atoi(mainMap["80"]);
            *(int32_t *)(this + 0x598) = atoi(mainMap["77"]);
            break;

        default:
            break;
    }

    if (m_objectID == 105 || m_objectID < 31 || (743 < m_objectID && m_objectID < 901) || m_objectID == 915) {
        *(int16_t *)(this + 0x4ed) = ccc3(atoi(mainMap["7"]), atoi(mainMap["8"]), atoi(mainMap["9"]));
        *(int32_t *)(this + 0x4f0) = atof(mainMap["10"]);

        *(int8_t *)(this + 0x508) = atof(mainMap["14"]);
        *(int8_t *)(this + 0x509) = atof(mainMap["15"]);
        *(int8_t *)(this + 0x50a) = atof(mainMap["16"]);
        *(int8_t *)(this + 0x50b) = atof(mainMap["17"]);
        *(int8_t *)(this + 0x574) = atof(mainMap["60"]);

        rbx = atoi(mainMap["23"]);
        if (rbx > 1) {
            *(int32_t *)(this + 0x3bc) = rbx;
        }

        *(int32_t *)(this + 0x4f4) = atoi(mainMap["36"]) ? atof(mainMap["35"]) : 1.0;

        *(this + 0x560) = GameToolbox::hsvFromString(mainMap["49"], "a");
        *(int32_t *)(this + 0x570) = atof(mainMap["50"]);

        if (m_objectID < 31 || m_objectID == 105 || m_objectID == 900) {
            *(int8_t *)(this + 0x50b) = 0x0;
            *(int32_t *)(this + 0x4f4) = 1.0;
        }
    }

    xmm0 = intrinsic_xorpd(xmm0, xmm0);
    xmm0 = intrinsic_ucomiss(xmm0, *(int32_t *)(this + 0x518));
    if (xmm0 >= 0x0) {
            *(int32_t *)(this + 0x518) = 0x40000000;
    }

    return m_objectID;
}
