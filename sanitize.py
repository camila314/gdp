# makes things easier for me

data = open("why.cpp", "r").read()

data = data.replace(" "*8, " "*4)

#playerobject members
if data.startswith("PlayerObject"):
	data = data.replace("*(int8_t *)(this + 0x778)", "m_onGround")
	data = data.replace("*(int8_t *)(this + 0x7a1)", "m_isRising")
	data = data.replace("*(int8_t *)(this + 0x7a0)", "m_isSliding")
	data = data.replace("*(int8_t *)(this + 0x62b)", "m_unknown_62b")
	data = data.replace("*(int8_t *)(this + 0x732)", "m_hitPortal")
	data = data.replace("*(int8_t *)(this + 0x779)", "m_isDashing")
	data = data.replace("*(int8_t *)(this + 0x770)", "m_isShip")
	data = data.replace("*(int8_t *)(this + 0x771)", "m_isBird")
	data = data.replace("*(int8_t *)(this + 0x772)", "m_isBall")
	data = data.replace("*(int8_t *)(this + 0x773)", "m_isDart")
	data = data.replace("*(int8_t *)(this + 0x774)", "m_isRobot")
	data = data.replace("*(int8_t *)(this + 0x775)", "m_isSpider")
	data = data.replace("*(int8_t *)(this + 0x776)", "m_upsideDown")
	data = data.replace("*(int32_t *)(this + 0x77c)", "m_vehicleSize")
	data = data.replace("*(this + 0x760)", "m_yAccel")
	data = data.replace("*(this + 0x6b0)", "m_spiderSprite")
	data = data.replace("this + 0x7a4", "m_lastHitGround")

#314
print(data)