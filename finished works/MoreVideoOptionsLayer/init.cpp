bool _ZN21MoreVideoOptionsLayer4initEPv(int arg0) {
    this = arg0;
    if (CCLayerColor::initWithColor(arg0, 0x4b000000) != 0x0) {
            CCDirector::sharedDirector()->getTouchDispatcher()->incrementForcePrio(2);
            this->registerWithTouchDispatcher(1);
            this->setKeypadEnabled(true);
            CCSize wSize = CCDirector::sharedDirector()->getWinSize(rax);
            auto mainL = CCLayer::create();
            m_mainLayer = mainL;
            this->addChild(mainL);

            auto scale9 = extension::CCScale9Sprite::create("GJ_square01.png");
            scale9->setContentSize(CCSizeMake(300, 280));
            m_mainLayer->addChild(scale9, -1);
            xmm2 = 0.5;
            xmm0 = wSize.width;
            xmm0 = intrinsic_mulss(xmm0, xmm2);
            xmm1 = wSize.height;
            xmm1 = intrinsic_mulss(xmm1, xmm2);
            rax = CCPoint::CCPoint(var_48, xmm0, xmm1);
            scale9->setPosition()
            rbx = CCLabelBMFont::create("Advanced Video Options", "bigFont.fnt");
            r12 = *(*rbx + 0xb8);
            xmm0 = wSize.width;
            xmm2 = 0.5;
            xmm0 = intrinsic_mulss(xmm0, xmm2);
            xmm1 = wSize.height;
            xmm1 = intrinsic_mulss(xmm1, xmm2);
            xmm1 = intrinsic_addss(xmm1, *(int32_t *)0x10050ce68);
            xmm1 = intrinsic_addss(xmm1, -16.0);
            rax = CCPoint::CCPoint(var_48, xmm0, xmm1);
            rax = (r12)(rbx, var_48);
            rdi = m_mainLayer;
            rax = *rdi;
            rax = (*(rax + 0x1b8))(rdi, rbx);
            rax = *rbx;
            xmm0 = 0.60;
            rax = (*(rax + 0xa0))(rbx);
            *(int32_t *)(this + 0x200) = 0xffffffff;
            rax = CCDictionary::create();
            *(this + 0x268) = rax;
            rax = CCObject::retain(rax);
            rax = CCDictionary::create();
            *(this + 0x260) = rax;
            rdi = rax;
            rax = CCObject::retain(rdi);
            rax = CCMenu::create(rdi, rbx);
            *(this + 0x1f8) = rax;
            rdi = m_mainLayer;
            rcx = *rdi;
            rax = (*(rcx + 0x1c0))(rdi, rax, 0xa, rcx);
            rax = MoreVideoOptionsLayer::addToggle(this, "Smooth Fix", "0023", "Makes some assumptions that can reduce lag on fast systems. Disable if game speed becomes inconsistent.");
            r14 = CCMenuItemSpriteExtra::create(CCSprite::createWithSpriteFrameName("GJ_closeBtn_001.png"), 0x0, this, sub_100444aa0, 0x0);
            xmm0 = 1.5;
            rax = CCMenuItemSpriteExtra::setSizeMult(r14);
            rdi = *(this + 0x1f8);
            rax = *rdi;
            rax = (*(rax + 0x1b8))(rdi, r14);
            var_40 = *(*r14 + 0xb8);
            r12 = *(this + 0x1f8);
            xmm0 = 0x4b000000;
            xmm2 = 0.5;
            var_34 = intrinsic_movss(var_34, xmm2);
            xmm0 = intrinsic_mulss(xmm0, xmm2);
            xmm0 = intrinsic_addss(xmm0, *(int32_t *)0x10050cda0);
            xmm0 = intrinsic_addss(xmm0, 5.0);
            xmm1 = wSize.height;
            xmm1 = intrinsic_mulss(xmm1, xmm2);
            xmm1 = intrinsic_addss(xmm1, *(int32_t *)0x10050ce68);
            xmm1 = intrinsic_addss(xmm1, -5.00);
            rax = CCPoint::CCPoint(var_50, xmm0, xmm1);
            rax = CCNode::convertToNodeSpace(var_48, r12, var_50);
            rax = (var_40)(r14, var_48);
            xmm0 = var_34;
            xmm0 = intrinsic_mulss(xmm0, wSize.height);
            var_34 = intrinsic_movss(var_34, xmm0);
            rax = CCSprite::createWithSpriteFrameName("GJ_arrow_01_001.png");
            rax = CCMenuItemSpriteExtra::create(rax, 0x0, this, sub_100444ad0, 0x0);
            *(this + 0x270) = rax;
            rdi = *(this + 0x1f8);
            rax = (*(*rdi + 0x1b8))(rdi, rax);
            rbx = *(this + 0x270);
            var_40 = *(*rbx + 0xb8);
            r12 = *(this + 0x1f8);
            rax = CCDirector::sharedDirector();
            rax = CCDirector::getScreenLeft(rax);
            xmm0 = intrinsic_addss(xmm0, *(int32_t *)0x10050cd9c);
            xmm1 = var_34;
            rax = CCPoint::CCPoint(var_50, xmm0, xmm1);
            rax = CCNode::convertToNodeSpace(var_48, r12, var_50);
            rax = (var_40)(rbx, var_48);
            rbx = CCSprite::createWithSpriteFrameName("GJ_arrow_01_001.png");
            rax = setFlipX(rbx, 0x1);
            rax = CCMenuItemSpriteExtra::create(rbx, 0x0, this, sub_100444af0, 0x0);
            *(this + 0x278) = rax;
            rdi = *(this + 0x1f8);
            rax = (*(*rdi + 0x1b8))(rdi, rax);
            rbx = *(this + 0x278);
            var_40 = *(*rbx + 0xb8);
            r14 = *(this + 0x1f8);
            rax = CCDirector::sharedDirector();
            rax = CCDirector::getScreenRight(rax);
            rax = CCPoint::CCPoint(var_50, intrinsic_addss(xmm0, -24.0), intrinsic_movss(xmm1, var_34));
            rax = CCNode::convertToNodeSpace(var_48, r14, var_50);
            rax = (var_40)(rbx, var_48);
            rax = MoreVideoOptionsLayer::goToPage(this, 0x0);
            return true;
    } else {
        return false;
    }
}