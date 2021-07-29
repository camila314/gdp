// loc_10022ae24 :
*(int8_t *)(this + 0x7a1) = 0x1;
*(int8_t *)(this + 0x7a0) = 0x0;
*(int8_t *)(this + 0x778) = 0x0;
this->hasQueuedHold = 0x0;
xmm0 = intrinsic_movss(xmm0, *(int32_t *)(this + 0x77c));
r15 = xmm0 != 1.0;
xmm0 = intrinsic_movsd(xmm0, *(this + 0x610));
xmm0 = intrinsic_cvtsd2ss(xmm0, xmm0);
var_24 = intrinsic_movss(var_24, xmm0);
if (ringObj->objectType == kRedRing) {
    //loc_10022b164 :
    if (*(int8_t *)(this + 0x770) == 0x0) {
        //loc_10022b20a :
        if (*(int8_t *)(this + 0x771) != 0x0) {
            xmm0 = intrinsic_movss(xmm0, *(int32_t *)(this + 0x77c));
            xmm0 = intrinsic_ucomiss(xmm0, *(int32_t *)value 1.0);
            if ((xmm0 == 0x0) && (CPU_FLAGS & NP)) {
                xmm0 = intrinsic_movss(xmm0, var_24);
                xmm0 = intrinsic_mulss(xmm0, *(int32_t *)0x100510f10);
            } else {
                xmm0 = intrinsic_movss(xmm0, var_24);
                xmm0 = intrinsic_mulss(xmm0, *(int32_t *)0x100510f14);
            }
        } else {
            if (*(int8_t *)(this + 0x772) != 0x0) {
                xmm0 = intrinsic_movss(xmm0, var_24);
                xmm0 = intrinsic_mulss(xmm0, *(int32_t *)0x100510f18);
            } else {
                if (*(int8_t *)(this + 0x774) != 0x0) {
                    xmm0 = intrinsic_movss(xmm0, var_24);
                    xmm0 = intrinsic_mulss(xmm0, *(int32_t *)0x100510f1c);
                } else {
                    if (*(int8_t *)(this + 0x775) == 0x0) {
                        xmm0 = intrinsic_movss(xmm0, var_24);
                        xmm0 = intrinsic_mulss(xmm0, *(int32_t *)0x100510f20);
                    } else {
                        xmm0 = intrinsic_movss(xmm0, var_24);
                        xmm0 = intrinsic_mulss(xmm0, *(int32_t *)0x100510f18);
                    }
                }
            }
        }
        var_24 = intrinsic_movss(var_24, xmm0);
    } else {
        //loc_10022b171 :
        xmm0 = intrinsic_movss(xmm0, *(int32_t *)(this + 0x77c));
        xmm0 = intrinsic_ucomiss(xmm0, *(int32_t *)value 1.0);
        if ((xmm0) || (!CPU_FLAGS & NP)) {
            xmm0 = intrinsic_movss(xmm0, var_24);
            xmm0 = intrinsic_mulss(xmm0, *(int32_t *)value 1.4);
            var_24 = intrinsic_movss(var_24, xmm0);
        }
    }
} else if(ringObj->objectType == kPinkRing) {
    // loc_10022b12a :
    if (*(int8_t *)(this + 0x770) != 0x0) {
        xmm0 = intrinsic_movss(xmm0, var_24);
        xmm0 = intrinsic_mulss(xmm0, *(int32_t *)0x100510f24);
    } else {
        if (*(int8_t *)(this + 0x771) != 0x0) {
            xmm0 = intrinsic_movss(xmm0, var_24);
            xmm0 = intrinsic_mulss(xmm0, *(int32_t *)0x10050f184);
        } else {
            if (*(int8_t *)(this + 0x772) != 0x0) {
                xmm0 = intrinsic_movss(xmm0, var_24);
                xmm0 = intrinsic_mulss(xmm0, *(int32_t *)0x100510f28);
            } else {
                xmm0 = intrinsic_movss(xmm0, var_24);
                xmm0 = intrinsic_mulss(xmm0, *(int32_t *)0x100510480);
            }
        }
    }
    var_24 = intrinsic_movss(var_24, xmm0);
} else if (ringObj->objectType == kGreenRing || ringObj->objectType == kBlueRing) {
    if (ringObj->objectType == kGreenRing) {
        if (*(int8_t *)(this + 0x770) != 0x0) {
            xmm0 = intrinsic_movss(xmm0, var_24);
            xmm0 = intrinsic_mulss(xmm0, *(int32_t *)value 0.70);
        } else {
            xmm0 = intrinsic_movss(xmm0, var_24);
        }
    } else {
        xmm0 = intrinsic_movss(xmm0, var_24);
        xmm0 = intrinsic_mulss(xmm0, *(int32_t *)value 0.8);
    }

    //common code
    var_24 = intrinsic_movss(var_24, xmm0);
    r15 = this->inPlayLayer;
    rax = GM;
    if (r15) {
        rdi = *(rax + 0x180);
        rax = *rdi;
        rdx = *(int8_t *)(this + 0x776) == 0x0 ? 0x1 : 0x0;
        (*(rax + 0x460))(rdi, this, rdx, 0x1);
        PlayLayer::playGravityEffect(PLAYLAYER, *(int8_t *)(this + 0x776) & 0xff);
    }
    else {
        if (*(rax + 0x188) != 0x0) {
            rdi = EDITLAYER;
            rax = *rdi;
            rdx = *(int8_t *)(this + 0x776) == 0x0 ? 0x1 : 0x0;
            (*(rax + 0x460))(rdi, this, rdx, 0x1);
        }
        else {
            rdx = 0x1;
            PlayerObject::flipGravity(this, *(int8_t *)(this + 0x776) == 0x0 ? 0x1 : 0x0, rdx);
        }
    }
} else {
    //loc_10022b19a.
    if (*(int8_t *)(this + 0x774)) {
        //loc_10022b1a7
        xmm0 = intrinsic_movss(xmm0, var_24);
        xmm0 = intrinsic_mulss(xmm0, *(int32_t *)value 0.9);
        var_24 = intrinsic_movss(var_24, xmm0);
    }
}
xmm0 = intrinsic_movss(xmm0, *(int32_t *)(0x10050e370 + r15 * 0x4));
var_44 = intrinsic_movss(var_44, xmm0);
COND = *(int8_t *)(this + 0x776) == 0x0;
xmm0 = intrinsic_movss(xmm0, var_24);
xmm0 = intrinsic_mulss(xmm0, *(int32_t *)(0x10050d470 + (COND ? 0x1 : 0x0) * 0x4));
xmm1 = intrinsic_movss(xmm1, var_44);
xmm1 = intrinsic_mulss(xmm1, xmm0);
xmm0 = intrinsic_cvtss2sd(0x0, xmm1);
*(this + 0x760) = intrinsic_movsd(*(this + 0x760), xmm0);
if (*(int8_t *)(this + 0x772) != 0x0) {
    sub_10021cb10(this);
}
else {
    PlayerObject::runRotateAction(this, 0x0, rdx);
}
rax = *this;
rax = (*(rax + 0xc0))(this);
cocos2d::CCPoint::operator=(this + 0x7a4, rax);
sub_10021aef0(this);
*(int8_t *)(this + 0x7c1) = 0x1;
if ((*(int8_t *)(this + 0x772) != 0x0) || (*(int8_t *)(this + 0x775) != 0x0)) {
    xmm0 = intrinsic_movsd(xmm0, *(this + 0x760));
    xmm0 = intrinsic_mulsd(xmm0, *0x100511168);
    *(this + 0x760) = intrinsic_movsd(*(this + 0x760), xmm0);
    *(int8_t *)(this + 0x745) = 0x0;
}

// loc_10022b5d5 :
if (ringObj->objectType == kRedRing) {
    *(int8_t *)(this + 0x732) = 0x1;
}
goto chunk1;