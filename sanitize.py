# makes things easier for me
import re

data = open("why.cpp", "r").read()

#data = data.replace(" "*8, " "*4)

#playerobject members
if data.startswith("PlayerObject"):
	data = data.replace("*(int8_t *)(this + 0x62b)", "m_unknown_62b")
	data = data.replace("*(int8_t *)(this + 0x62c)", "m_inPlayLayer")
	data = data.replace("*(int8_t *)(this + 0x732)", "m_hitPortal")
	data = data.replace("*(int8_t *)(this + 0x745)", "m_isHolding")
	data = data.replace("*(int8_t *)(this + 0x769)", "m_onSlope2")
	data = data.replace("*(int8_t *)(this + 0x770)", "m_isShip")
	data = data.replace("*(int8_t *)(this + 0x771)", "m_isBird")
	data = data.replace("*(int8_t *)(this + 0x772)", "m_isBall")
	data = data.replace("*(int8_t *)(this + 0x773)", "m_isDart")
	data = data.replace("*(int8_t *)(this + 0x774)", "m_isRobot")
	data = data.replace("*(int8_t *)(this + 0x775)", "m_isSpider")
	data = data.replace("*(int8_t *)(this + 0x776)", "m_upsideDown")
	data = data.replace("*(int8_t *)(this + 0x778)", "m_onGround")
	data = data.replace("*(int8_t *)(this + 0x779)", "m_isDashing")
	data = data.replace("*(int8_t *)(this + 0x7a0)", "m_isSliding")
	data = data.replace("*(int8_t *)(this + 0x7a1)", "m_isRising")
	data = data.replace("*(int32_t *)(this + 0x77c)", "m_vehicleSize")
	data = data.replace("*(int32_t *)(this + 0x780)", "m_playerSpeedMultiplier")
	data = data.replace("*(int32_t *)(this + 0x584)", "m_collidedUUID")
	data = data.replace("*(this + 0x608)", "m_playerSpeed")
	data = data.replace("*(this + 0x760)", "m_yAccel")
	data = data.replace("*(this + 0x6b0)", "m_spiderSprite")
	data = data.replace("*(this + 0x6a8)", "m_robotSprite")
	data = data.replace("*(this + 0x7b8)", "m_lastPortal")
	data = data.replace("*(int32_t *)(this + 0x76c)", "m_slopeRotation")
	data = data.replace("*(this + 0x570)", "m_collidedSlopeObj")
	data = data.replace("this + 0x78c", "m_lastPortalLocation")
	data = data.replace("this + 0x7a4", "m_lastHitGround")
if data.startswith("GameObject"):
	data = data.replace("*(this + 0x410)", "m_mainColor")
	data = data.replace("*(int8_t *)(this + 0x279)", "m_inEditorMode")
	data = data.replace("*(this + 0x350)", "m_hasDetailChannel")
	data = data.replace("*(int32_t *)(this + 0x428)", "m_zLayer")
	data = data.replace("*(int32_t *)(this + 0x3b4)", "m_batchLayer")
	data = data.replace("*(int8_t *)(this + 0x2e4)", "m_modifierBlock")
	data = data.replace("*(int32_t *)(this + 0x3c4)", "m_objectID")
	data = data.replace("*(int8_t *)(this + 0x347)", "m_shouldBlendMain")
	data = data.replace("*(this + 0x418)", "m_detailColor")
	data = data.replace("*(int8_t *)(this + 0x348)", "m_shouldBlendDetail")
	data = data.replace("*(int32_t *)(this + 0x424)", "m_defaultZLayer")
	data = data.replace("*(int8_t *)(this + 0x3d8)", "m_effectSheet")
	data = data.replace("*(int32_t *)(this + 0x42c)", "m_zOrder")
	


	#data = data.replace("*(this + 0x418)", )

#314

data = data.replace("*(int32_t *)value ","")
data = data.replace("*(GameManager::sharedState() + 0x180)", "PL")
data = data.replace("*(GameManager::sharedState() + 0x188)", "LEL")
data = data.replace("*(int8_t *)(GameManager::sharedState() + 0x2a1)", "GM->m_ldm")
data = data.replace("std::basic_string<char, std::char_traits<char>, std::allocator<char> >::basic_string", "std::string")
data = re.sub(r"intrinsic_movs[sd]\(\w+, (.+)\);", r"\1;", data)
data = re.sub(r"= intrinsic_adds[sd]\((\w+), (.+)\);", r"+= \2;", data)
data = re.sub(r"= intrinsic_subs[sd]\((\w+), (.+)\);", r"-= \2;", data)
data = re.sub(r"= intrinsic_muls[sd]\((\w+), (.+)\);", r"*= \2;", data)
data = re.sub(r"(\w+) == 0x0 \? 0x1 : 0x0", r"!\1", data)
data = re.sub(r"}\n\s+else", r"} else", data)
data = data.replace("(*(rax + 0x4f8))", "GameObject::getObjectRect")
data = data.replace("(*(rax + 0x200))", "CCNode::removeFromParentAndCleanup")
data = data.replace("(*(*this + 0xc0))", "this->getPosition")
data = data.replace("(*(*this + 0x1f0))(this)", "this->getParent()")
print(data)