# makes things easier for me
import re

data = open("why.cpp", "r").read()

def repl(str1, str2):
	global data
	data = data.replace(str1, str2)

def subs(str1, str2):
	global data
	data = re.sub(str1, str2, data)

classes = r"(PlayerObject|GameObject|PlayLayer|cocos2d::CCArray|cocos2d::CCNode)"

#playerobject members
if data.startswith("PlayerObject"):
	repl("*(int32_t *)(this + 0x584)", "m_collidedUUID")
	repl("*(int32_t *)(this + 0x728)", "m_slopeRotation")
	repl("*(int32_t *)(this + 0x76c)", "m_slopeVelocity")
	repl("*(int32_t *)(this + 0x77c)", "m_vehicleSize")
	repl("*(int32_t *)(this + 0x780)", "m_playerSpeed")
	repl("*(int8_t *)(this + 0x629)", "m_unk539")
	repl("*(int8_t *)(this + 0x62b)", "m_unk53b")
	repl("*(int8_t *)(this + 0x62c)", "m_isInPlayLayer")
	repl("*(int8_t *)(this + 0x630)", "m_isCheckpointQueued")
	repl("*(int8_t *)(this + 0x688)", "m_hasHitRing")
	repl("*(int8_t *)(this + 0x732)", "m_hasHitPortal")
	repl("*(int8_t *)(this + 0x745)", "m_isHolding")
	repl("*(int8_t *)(this + 0x768)", "m_isOnSlope")
	repl("*(int8_t *)(this + 0x769)", "m_wasOnSlope")
	repl("*(int8_t *)(this + 0x770)", "m_isShip")
	repl("*(int8_t *)(this + 0x771)", "m_isBird")
	repl("*(int8_t *)(this + 0x772)", "m_isBall")
	repl("*(int8_t *)(this + 0x773)", "m_isDart")
	repl("*(int8_t *)(this + 0x774)", "m_isRobot")
	repl("*(int8_t *)(this + 0x775)", "m_isSpider")
	repl("*(int8_t *)(this + 0x776)", "m_upsideDown")
	repl("*(int8_t *)(this + 0x777)", "m_isDead")
	repl("*(int8_t *)(this + 0x778)", "m_onGround")
	repl("*(int8_t *)(this + 0x779)", "m_isDashing")
	repl("*(int8_t *)(this + 0x7a0)", "m_isSliding")
	repl("*(int8_t *)(this + 0x7a1)", "m_isRising")
	repl("*(int8_t *)(this + 0x7a2)", "m_isLocked")
	repl("*(this + 0x528)", "m_collidedSlope")
	repl("*(this + 0x570)", "m_nearbySlope")
	repl("*(this + 0x608)", "m_playerSpeed")
	repl("*(this + 0x618)", "m_gravity")
	repl("*(this + 0x698)", "m_checkpoint")
	repl("*(this + 0x6a8)", "m_robotSprite")
	repl("*(this + 0x6b0)", "m_spiderSprite")
	repl("*(this + 0x760)", "m_yAccel")
	repl("*(this + 0x7b8)", "m_lastPortal")
	repl("this + 0x78c", "m_lastPortalLocation")
	repl("this + 0x7a4", "m_lastHitGround")
if data.startswith("GameObject") or data.startswith("EffectGameObject"):
	repl("*(this + 0x410)", "m_mainColor")
	repl("*(int8_t *)(this + 0x279)", "m_inEditorMode")
	repl("*(this + 0x350)", "m_hasDetailChannel")
	repl("*(int32_t *)(this + 0x428)", "m_zLayer")
	repl("*(int32_t *)(this + 0x3b4)", "m_batchLayer")
	repl("*(int8_t *)(this + 0x2e4)", "m_modifierBlock")
	repl("*(int32_t *)(this + 0x3c4)", "m_objectID")
	repl("*(int8_t *)(this + 0x347)", "m_shouldBlendMain")
	repl("*(this + 0x418)", "m_detailColor")
	repl("*(int8_t *)(this + 0x348)", "m_shouldBlendDetail")
	repl("*(int32_t *)(this + 0x424)", "m_defaultZLayer")
	repl("*(int8_t *)(this + 0x3d8)", "m_effectSheet")
	repl("*(int32_t *)(this + 0x42c)", "m_zOrder")
	repl("*(int32_t *)(this + 0x3c0)", "m_scale")
	repl("*(int32_t *)(this + 0x2dc)", "m_objectSize")
	repl("*(int32_t *)(this + 0x2e0)", "m_objectSize.height")
	repl("*(int8_t *)(this + 0x330)", "m_objectRectDirty")
	repl("*(int8_t *)(this + 0x2b8)", "m_usesOrientedBox")
	repl("*(int8_t *)(this + 0x2b0)", "m_orientedBox")
	repl("*(int8_t *)(this + 0x360)", "m_onSide")
if data.startswith("PlayLayer"):
	repl("*(int8_t *)(this + 0x4dc)", "m_debugPauseOff")
	repl("*(int8_t *)(this + 0x4dd)", "m_shouldSmoothCamera")
	repl("*(int8_t *)(this + 0x769)", "m_hasLevelCompleteMenu")
	repl("*(int8_t *)(this + 0x76a)", "m_hasCompletedLevel")
	repl("*(int32_t *)(this + 0x4d0)", "m_dontSaveRand")
	repl("*(int32_t *)(this + 0x4d4)", "m_dontSaveSeed")
	repl("*(int32_t *)(this + 0x4f0)", "m_camera4f0")
	repl("*(int32_t *)(this + 0x4fc)", "m_groundRestriction")
	repl("*(int32_t *)(this + 0x500)", "m_ceilRestriction")
	repl("*(int8_t *)(this + 0x504)", "m_fullReset")
	repl("*(this + 0x520)", "m_startPos")
	repl("*(this + 0x528)", "m_startPosCheckpoint")
	repl("*(this + 0x538)", "m_checkpoints")
	repl("*(this + 0x598)", "m_particleSystem")
	repl("*(this + 0x5a0)", "m_pickedUpItems")
	repl("*(this + 0x5b8)", "m_audioEffectsLayer")
	repl("*(this + 0x5c8)", "m_bottomGround")
	repl("*(this + 0x5d0)", "m_topGround")
	repl("*(this + 0x5f0)", "m_lockGroundToCamera")
	repl("*(int8_t *)(this + 0x5e0)", "m_isDead")
	repl("*(int8_t *)(this + 0x5e1)", "m_startCameraAtCorner")
	repl("*(int8_t *)(this + 0x5e2)", "m_cameraYLocked")
	repl("*(int8_t *)(this + 0x5e3)", "m_cameraXLocked")
	repl("*(int8_t *)(this + 0x610)", "m_isCameraShaking")
	repl("*(int32_t *)(this + 0x618)", "m_currentShakeInterval")
	repl("*(this + 0x620)", "m_lastShakeTime")
	repl("*(this + 0x628)", "m_cameraShakeOffset")
	repl("*(this + 0x634)", "m_backgroundScrollOffset")
	repl("*(int32_t *)(this + 0x688)", "m_activeGravityEffects")
	repl("*(this + 0x6a0)", "m_previousRecords")
	repl("*(this + 0x6b0)", "m_time")
	repl("*(this + 0x708)", "m_latestVehicle")
	repl("*(this + 0x710)", "m_dualObject")
	repl("*(int8_t *)(this + 0x718)", "m_isFlipped")
	repl("*(int32_t *)(this + 0x71c)", "m_mirrorTransition")
	repl("*(this + 0x720)", "m_UILayer")
	repl("*(this + 0x728)", "m_level")
	repl("*(int8_t *)(this + 0x738)", "m_isTestMode")
	repl("*(int8_t *)(this + 0x739)", "m_isPracticeMode")
	repl("*(int8_t *)(this + 0x7dc)", "m_hasGlitter")
	repl("*(this + 0x7e0)", "m_antiCheatObject")
	repl("*(int8_t *)(this + 0x7e8)", "m_antiCheatPassed")
	repl("*(int32_t*)(this + 0x5f8)", "m_levelLength")

	# gjbl
	repl("*(int8_t *)(this + 0x490)", "m_activeDualTouch")
	repl("*(this + 0x180)", "m_effectManager")
	repl("*(this + 0x3a0)", "m_objects")
	repl("*(this + 0x380)", "m_player1")
	repl("*(this + 0x388)", "m_player2")
	repl("*(this + 0x390)", "m_levelSettings")
	repl("*(this + 0x3a8)", "m_sectionObjects")
	repl("*(int8_t *)(this + 0x489)", "m_isDualMode")
	repl("*(int8_t *)(this + 0x490)", "m_activeDualTouch")
	repl("*(int32_t *)(this + 0x494)", "m_attemptClickCount")
	repl("*(int32_t *)(this + 0x498)", "m_lastVisibleSection")
	repl("*(int32_t *)(this + 0x49c)", "m_firstVisibleSection")
if data.startswith("EffectGameObject"):
	repl("*(int8_t *)(this + 0x594)", "m_multiTrigger")
	repl("*(int32_t *)(this + 0x4f0)", "m_duration")
	repl("*(int32_t *)(this + 0x4f4)", "m_opacity")
	repl("*(int32_t *)(this + 0x4f8)", "m_targetGroupID")
	repl("*(int32_t *)(this + 0x4fc)", "m_centerGroupID")
	repl("*(int32_t *)(this + 0x500)", "m_shakeStrength")
	repl("*(int32_t *)(this + 0x504)", "m_shakeInterval")
	repl("*(int8_t *)(this + 0x508)", "m_tintGround")
	repl("*(int8_t *)(this + 0x509)", "m_playerColor1")
	repl("*(int8_t *)(this + 0x50a)", "m_playerColor2")
	repl("*(int8_t *)(this + 0x50b)", "m_blending")
	repl("this + 0x50c", "m_move")
	repl("*(int32_t *)(this + 0x514)", "m_easingType")
	repl("*(int32_t *)(this + 0x518)", "m_easingRate")
	repl("*(int8_t *)(this + 0x51c)", "m_lockToPlayerX")
	repl("*(int8_t *)(this + 0x51d)", "m_lockToPlayerY")
	repl("*(int8_t *)(this + 0x51e)", "m_useTarget")
	repl("*(int32_t *)(this + 0x520)", "m_moveTargetType")
	repl("*(int32_t *)(this + 0x524)", "m_rotateDegrees")
	repl("*(int32_t *)(this + 0x528)", "m_times360")
	repl("*(int8_t *)(this + 0x52c)", "m_lockObjectRotation")
	repl("this + 0x530", "m_followMod")
	repl("*(int8_t *)(this + 0x538)", "m_UndocuementedLevelProperty74")
	repl("*(int32_t *)(this + 0x53c)", "m_followYSpeed")
	repl("*(int32_t *)(this + 0x540)", "m_followYDelay")
	repl("*(int32_t *)(this + 0x544)", "m_followYOffset")
	repl("*(int32_t *)(this + 0x548)", "m_followYMaxSpeed")
	repl("*(int32_t *)(this + 0x54c)", "m_fadeInTime")
	repl("*(int32_t *)(this + 0x550)", "m_holdTime")
	repl("*(int32_t *)(this + 0x554)", "m_fadeOutTime")
	repl("*(int32_t *)(this + 0x558)", "m_pulseHSVMode")
	repl("*(int32_t *)(this + 0x55c)", "m_pulseGroupMode")
	repl("this + 0x560", "m_HSVValue")
	repl("*(int32_t *)(this + 0x570)", "m_copyColorID")
	repl("*(int8_t *)(this + 0x574)", "m_copyOpacity")
	repl("*(int8_t *)(this + 0x575)", "m_pulseMainOnly")
	repl("*(int8_t *)(this + 0x576)", "m_pulseDetailOnly")
	repl("*(int8_t *)(this + 0x577)", "m_pulseExclusive")
	repl("*(int8_t *)(this + 0x578)", "m_activateGroup")
	repl("*(int8_t *)(this + 0x579)", "m_touchHoldMode")
	repl("*(int32_t *)(this + 0x57c)", "m_touchToggleMode")
	repl("*(int8_t *)(this + 0x580)", "m_touchDualMode")
	repl("*(int32_t *)(this + 0x584)", "m_animationID")
	repl("*(int32_t *)(this + 0x588)", "m_spawnDelay")
	repl("this + 0x58c", "m_spawnPosition")
	repl("*(int8_t *)(this + 0x594)", "m_multiTrigger")
	repl("*(int8_t *)(this + 0x595)", "m_editorDisabled")
	repl("*(int32_t *)(this + 0x598)", "m_targetCount")
	repl("*(int8_t *)(this + 0x59c)", "m_subtractCount")
	repl("*(int32_t *)(this + 0x5a0)", "m_comparisonType")
	repl("*(int8_t *)(this + 0x5a4)", "m_multiActivate")
	repl("*(int8_t *)(this + 0x5a5)", "m_triggerOnExit")
	repl("*(int32_t *)(this + 0x5a8)", "m_blockBID")
	repl("*(int8_t *)(this + 0x5ac)", "m_dynamicBlock")
	repl("*(int32_t *)(this + 0x5b0)", "m_targetItemID")
	repl("*(int32_t *)(this + 0x5b4)", "m_pickupMode")

#314

subs(r"rax = cocos2d::CCPoint::CCPoint\((\w+), ", r"\1 = cocos2d::CCPoint::CCPoint(")

subs(r"cocos2d::CCArray::count\((\w+)\)", r"\1->count()")

subs(classes + r"::(\w+)\(([^\(\)]+?)(?:(?:, ([^\(]+?))|())\)", r"\3->\2(\4)")

repl("*(int32_t *)value ","")
repl("*(GameManager::sharedState() + 0x180)", "PL")
repl("*(GameManager::sharedState() + 0x188)", "LEL")
repl("*(int8_t *)(GameManager::sharedState() + 0x2a1)", "GM->m_ldm")
repl("std::basic_string<char, std::char_traits<char>, std::allocator<char> >::basic_string", "std::string")

subs(r"intrinsic_movs[sd]\(\w+, (.+)\);", r"\1;")
subs(r"= intrinsic_adds[sd]\((\w+), (.+)\);", r"+= \2;")
subs(r"= intrinsic_subs[sd]\((\w+), (.+)\);", r"-= \2;")
subs(r"= intrinsic_muls[sd]\((\w+), (.+)\);", r"*= \2;")
subs(r"(\w+) == 0x0 \? 0x1 : 0x0", r"!\1")
subs(r"}\n\s+else", r"} else")

repl("(*(rax + 0x4f8))", "GameObject::getObjectRect")
repl("(*(rax + 0x200))", "CCNode::removeFromParentAndCleanup")
repl("(*(*this + 0xc0))", "this->getPosition")
repl("(*(rax + 0xb8))", "CCNode::setPosition")
repl("(*(*this + 0x1f0))(this)", "this->getParent()")

print(data)