GameObject::addMainSpriteToParent(bool reorder) {
    int colorID = m_mainColor->colorID;
    if (colorID == 0) {
        colorID = m_mainColor->defaultColorID;
    }

    if (m_mainColor->colorID == m_mainColor->defaultColorID) { // robtop you suck at coding
        colorID = m_mainColor->defaultColorID;
    }

    if (m_pulsingStick) {
        colorID = 0;
    }

    if (m_inEditorMode) {
        m_shouldBlendMain = LEL->shouldBlend(colorID);
    } else {
        if (colorID == 0)
            m_shouldBlendMain = false;
        else if (colorID == 1012)
            while (true) {} // i'm not fucking kidding
        else if (colorID < 1008)
            m_shouldBlendMain = true;
        else
            m_shouldBlendMain = PL->shouldBlend(colorID);
    }

    if (m_hasDetailChannel) {
        int colorID2 = m_detailColor->colorID;
        if (colorID2 == 0)
            colorID2 = m_detailColor->defaultColorID;

        if (m_detailColor->colorID == m_detailColor->defaultColorID) { // robtop you suck at coding
            colorID2 = m_detailColor->defaultColorID;
        }

        if (m_pulsingStick)
            colorID2 = 0;

        if (m_inEditorMode) {
            m_shouldBlendDetail = LEL->shouldBlend(colorID2);
        } else {
            if (colorID2 == 0)
                m_shouldBlendDetail = false;
            else if (colorID2 == 1024)
                while (true) {}
            else if (colorID2 < 1008)
                m_shouldBlendDetail = true;
            else
                m_shouldBlendDetail = PL->shouldBlend(colorID2);
        }
    } else {
        m_shouldBlendDetail = false;
    }

    int zLayer = m_zLayer ? m_zLayer : m_defaultZLayer;

    if (m_shouldBlendMain && m_hasDetailChannel && !m_shouldBlendDetail) {
        zLayer = zLayer + static_cast<int>(!m_unknown_3d9);
    }

    if (m_batchLayer == -1) {
      //loc_10033a706:
        if (m_modifierBlock) {
            m_batchLayer = 4;
        } else if (m_effectSheet) {
            m_batchLayer = 1;
        } else switch (m_objectID) {
            case 914:
                m_batchLayer = 2;
                break;
            case 918: // L
            case 920:
            case 921:
            case 923:
            case 924:
            case 1327:
            case 1328:
            case 1329:
            case 1584:
            case 1614:
            case 1618:
            case 1844:
            case 1845:
            case 1846:
            case 1847:
            case 1848:
            case 1849:
            case 1850:
            case 1851:
            case 1852:
            case 1853:
            case 1854:
            case 1855:
            case 1856:
            case 1857:
            case 1858:
            case 1860:
                m_batchLayer = 2;
                break;
            case 899: 
            case 901: 
            case 1006:
            case 1007:
            case 1049:
            case 1268:
            case 1346:
            case 1347:
            case 1520:
            case 1585:
            case 1595:
            case 1611:
            case 1615:
            case 1616:
            case 1755:
            case 1811:
            case 1812:
            case 1813:
            case 1814:
            case 1815:
            case 1816:
            case 1817:
            case 1829:
            case 1859:
                m_batchLayer = 4;
                break;
            default:
                m_batchLayer = 0;
                break;
        }
    }

    auto parent = GJBL->parentForZLayer(zLayer, m_hasDetailChannel, m_batchLayer);
    int zOrder = m_zOrder ? m_zOrder : m_defaultZOrder;

    if (this->getParent() == parent) {
        if (reorder)
            parent->reorderChild(this, zOrder);
    } else {
        this->removeFromParentAndCleanup();
        parent->addChild(this, zOrder);
    }

    m_unknown_420 = m_shouldBlendMain | m_shouldBlendDetail;
}
