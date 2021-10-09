GameObject* GameObject::createWithKey(int object_id) {
    auto texture = ObjectToolbox::sharedState()->intKeyToFrame(object_id);
    GameObject* ret = nullptr;

    if (!texture) {
        return nullptr;
    }

    if (object_id < 1008 && object_id > 748) {
        ret = LabelGameObject::create(texture);
    } else if (object_id <= 1819 && object_id > 1704) {
        ret = LabelGameObject::create(texture);
    } else switch (object_id) {
        case 22:
        case 23:
        case 24:
        case 25:
        case 26:
        case 27:
        case 28:
        case 29:
        case 30:
        case 32:
        case 33:
        case 55:
        case 56:
        case 57:
        case 58:
        case 59:
        case 105:
        case 1268:
        case 1342:
        case 1343:
        case 1344:
        case 1346:
        case 1347:
        case 1585:
        case 1587:
        case 1589:
        case 1595:
        case 1598:
        case 1611:
        case 1612:
        case 1613:
        case 1614:
        case 1616:
        case 899:
        case 900:
        case 901:
        case 913:
        case 744:
        case 1049:
        case 1520:
            ret = LabelGameObject::create(texture);
            break;
        case 36:
        case 84:
        case 141:
        case 1022:
        case 1330:
        case 1333:
        case 1594:
        case 1704:
        case 1751:
            ret = RingObject::create(texture);
            break;
        case 1327:
        case 1328:
        case 1584:
            ret = AnimatedGameObject::create(texture);
            break;
        case 1615:
            ret = RingObject::create();
            break;
        case 31:
            ret = StartPosObject::create();
            break;
        case 747: 
            ret = TeleportPortalObject::create(texture);
            break;
        case 914: 
            auto font = cocos2d::CCTextureCache::sharedTextureCache()->addImage(GM->getFontTexture(GM->m_editorFont), false);
            ret = new GameObject;
            if (!ret->initWithTexture(font)) {
                delete ret;
                return nullptr;
            }
            ret->autorelease();
            break;
        default:
            ret = GameObject::createWithFrame(texture);
            break;
    }

    if (ret) {
        ret->m_objectID = object_id;
    }
    return ret;
}
