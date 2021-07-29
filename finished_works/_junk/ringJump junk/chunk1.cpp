    if (!this->unknown_629) {
        auto circleCol = ccc3(255,255,255); 
        if (!(GM->unknown_2a1 || loc_100342a80(ringObj) || !this->inPlayLayer)) {
            switch (ringObj->objectType) {
                case kBlueRing:
                    circleCol = ccc3(0,0,255);
                    break;
                case kPinkRing:
                    circleCol = ccc3(255,0,255);
                    break;
                case kGreenRing:
                    circleCol = ccc3(0,255,0);
                case kGreenDashRing:
                case kPinkDashRing:
                case kBlackRing:
                    circleCol = PL->effectManager->activeColorForIndex(1007);
                case kRedRing:
                    circleCol = ccc3(255,100,0);
                case kCustomRing:
                    rdi = *(ringObj + 0x350);
                    if (rdi) {
                        rax = *rdi;
                    }
                    else {
                        rax = *ringObj;
                    }
                    rax = (*(rax + 0x388))();
                    rcx = *(int16_t *)rax & 0xffff;
                    circleCol = *(int8_t *)(rax + 0x2) & 0xff;
                    circleCol = circleCol << 0x10 | rcx;
                    break;
                default: // rob made yellow the default case
                    circleCol = ccc3(255,200,0);
            }
            intrinsic_movss(xmm0, *(int32_t *)(0x100511178 + (ringObj->objectType == 0x23 ? 0x1 : 0x0) * 0x4));
            intrinsic_movss(xmm1, *(int32_t *)value 5.0);
            intrinsic_movss(xmm2, *(int32_t *)0x10050c770);
            r12 = CCCircleWave::create(0x1);
            *(int8_t *)(r12 + 0x136) = circleCol >> 0x10;
            *(int16_t *)(r12 + 0x134) = circleCol;
            r15 = *(*r12 + 0xb8);
            rax = *ringObj;
            rax = (*(rax + 0xc0))(ringObj);
            (r15)(r12, rax);
            CCCircleWave::followObject(r12, ringObj, 0x1);
            rax = GM;
            rax = *(rax + 0x180);
            rcx = rax + 0x4b0;
            if (rax == 0x0) {
                rcx = rax;
            }
            *(r12 + 0x150) = rcx;
            PLAYLAYER->addCircle();
            rdi = *(this + 0x798);
            rax = *rdi;
            (*(rax + 0x1c0))(rdi, r12, 0x0);
        }
    }
    GameObject::activatedByPlayer(ringObj, this);
    rax = *ringObj;
    (*(rax + 0x590))(ringObj);
    if (this->inPlayLayer != 0x0) {
        PLAYLAYER->incrementJumps();
        *(int8_t *)(this + 0x7c0) = 0x1;
    }
    return;