#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

#include "skill_psnode_delay.h"
#include "skill_psnode_detect.h"
#include "skill_psnode_disable.h"
#include "skill_psnode_endphase.h"
#include "skill_psnode_getactorattribute.h"
#include "skill_psnode_getinputobject.h"
#include "skill_psnode_getlinerotation.h"
#include "skill_psnode_getlocation.h"
#include "skill_psnode_if.h"
#include "skill_psnode_isinterrupttype.h"
#include "skill_psnode_playanimation.h"
#include "skill_psnode_playeffect.h"
#include "skill_psnode_playsound.h"
#include "skill_psnode_raiseevent.h"
#include "skill_psnode_resetcd.h"
#include "skill_psnode_setbool.h"
#include "skill_psnode_spawnprojectile.h"
#include "skill_psnode_startphase.h"
#include "skill_psnode_startpreinput.h"
#include "skill_psnode_switchtoint.h"

namespace pvp {

//变量声明
uint64_t Variable_10232_a102322 = 0;
uint64_t Variable_10232_InterruptAnimat = 0;
//--------------------------------------------------------------------------------
// StartPhase
//
REGISTER_REGISTER_SKILL_NODE(10232, 1) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_StartPhase::TRIGGER_START, 251, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(10232, 1) {
    auto node1 = GET_SKILL_NODE(1, PhaseNode_StartPhase);
    if (node1 == nullptr) {
        node1 = new PhaseNode_StartPhase(1, phase);
        CALL_REGISTER_SKILL_NODE(10232, 1, node1)
    }
    if (noInit == true) {
        return node1;
    }
    return node1;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(10232, 18) {
}

REGISTER_CREATE_SKILL_NODE(10232, 18) {
    auto node18 = GET_SKILL_NODE(18, PhaseNode_EndPhase);
    if (node18 == nullptr) {
        node18 = new PhaseNode_EndPhase(18, phase);
        node18->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node18->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10232, 18, node18)
    }
    if (noInit == true) {
        return node18;
    }
    return node18;
}
//--------------------------------------------------------------------------------
// Disable
//
REGISTER_REGISTER_SKILL_NODE(10232, 145) {
    pnode->resizeTrigger(PhaseNode_Disable::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_Disable::TRIGGER_DONE, 226, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_Disable::TRIGGER_DONE, 259, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10232, 145) {
    auto node145 = GET_SKILL_NODE(145, PhaseNode_Disable);
    if (node145 == nullptr) {
        node145 = new PhaseNode_Disable(145, phase);
        node145->setTarget(0U);
        node145->setMove(false);
        node145->setSkill(true);
        node145->setShoot(true);
        node145->setTime(.30f);
        node145->setRotate(false);
        CALL_REGISTER_SKILL_NODE(10232, 145, node145)
    }
    if (noInit == true) {
        return node145;
    }
    return node145;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10232, 174) {
}

REGISTER_CREATE_SKILL_NODE(10232, 174) {
    auto node174 = GET_SKILL_NODE(174, PhaseNode_PlaySound);
    if (node174 == nullptr) {
        node174 = new PhaseNode_PlaySound(174, phase);
        node174->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node174->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node174->setSoundID("SE_Hero106_SkillB_P1");
        node174->setTarget(0U);
        node174->setUsePos(false);
        node174->setPosX(.00f);
        node174->setPosY(.00f);
        node174->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10232, 174, node174)
    }
    if (noInit == true) {
        return node174;
    }
    return node174;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10232, 194) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_Delay::TRIGGER_DONE, 18, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(10232, 194) {
    auto node194 = GET_SKILL_NODE(194, PhaseNode_Delay);
    if (node194 == nullptr) {
        node194 = new PhaseNode_Delay(194, phase);
        node194->setTime(.85f);
        CALL_REGISTER_SKILL_NODE(10232, 194, node194)
    }
    if (noInit == true) {
        return node194;
    }
    return node194;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(10232, 226) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnProjectile>(PhaseNode_PlayEffect::TRIGGER_DONE, 229, PhaseNode_SpawnProjectile::FUNC_DO, &PhaseNode_SpawnProjectile::Do);
}

REGISTER_CREATE_SKILL_NODE(10232, 226) {
    auto node226 = GET_SKILL_NODE(226, PhaseNode_PlayEffect);
    if (node226 == nullptr) {
        node226 = new PhaseNode_PlayEffect(226, phase);
        node226->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node226->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node226->setEffectID(102303);
        node226->setChangeColor(false);
        node226->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node226->getVars().reserve(3);
        node226->getVars().setVariable<float>(0, .00f);
        node226->getVars().setVariable<float>(1, .00f);
        node226->getVars().setVariable<float>(2, .00f);
        node226->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(10232, 226, node226)
    }
    if (noInit == true) {
        return node226;
    }
    auto node250 = GET_SKILL_NODE(250, PhaseNode_GetLocation);
    auto node242 = GET_SKILL_NODE(242, PhaseNode_GetLineRotation);
    if (node250 != nullptr) node226->getVars().setVariable<float>(0, node250->getX());
    if (node250 != nullptr) node226->getVars().setVariable<float>(1, node250->getY());
    if (node242 != nullptr) node226->setRotation(node242->getRotation());
    return node226;
}
//--------------------------------------------------------------------------------
// SpawnProjectile
//
REGISTER_REGISTER_SKILL_NODE(10232, 229) {
    pnode->resizeTrigger(PhaseNode_SpawnProjectile::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_SpawnProjectile::TRIGGER_DONE, 194, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10232, 229) {
    auto node229 = GET_SKILL_NODE(229, PhaseNode_SpawnProjectile);
    if (node229 == nullptr) {
        node229 = new PhaseNode_SpawnProjectile(229, phase);
        node229->setDataId(55232);
        node229->setPosX(.00f);
        node229->setPosY(.00f);
        node229->setPosZ(.00f);
        node229->setEndPosZ(.00f);
        node229->setMaxCount(0);
        CALL_REGISTER_SKILL_NODE(10232, 229, node229)
    }
    if (noInit == true) {
        return node229;
    }
    auto node250 = GET_SKILL_NODE(250, PhaseNode_GetLocation);
    auto node242 = GET_SKILL_NODE(242, PhaseNode_GetLineRotation);
    if (node250 != nullptr) node229->setEndPosX(node250->getX());
    if (node250 != nullptr) node229->setEndPosY(node250->getY());
    if (node242 != nullptr) node229->setRotation(node242->getRotation());
    return node229;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10232, 237) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_PlaySound::TRIGGER_DONE, 174, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10232, 237) {
    auto node237 = GET_SKILL_NODE(237, PhaseNode_PlaySound);
    if (node237 == nullptr) {
        node237 = new PhaseNode_PlaySound(237, phase);
        node237->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node237->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node237->setSoundID("VO_Hero123_Skill_B");
        node237->setTarget(0U);
        node237->setUsePos(false);
        node237->setPosX(.00f);
        node237->setPosY(.00f);
        node237->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10232, 237, node237)
    }
    if (noInit == true) {
        return node237;
    }
    return node237;
}
//--------------------------------------------------------------------------------
// GetLineRotation
//
REGISTER_REGISTER_SKILL_NODE(10232, 242) {
    pnode->resizeTrigger(PhaseNode_GetLineRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Disable>(PhaseNode_GetLineRotation::TRIGGER_DONE, 145, PhaseNode_Disable::FUNC_DO, &PhaseNode_Disable::Do);
}

REGISTER_CREATE_SKILL_NODE(10232, 242) {
    auto node242 = GET_SKILL_NODE(242, PhaseNode_GetLineRotation);
    if (node242 == nullptr) {
        node242 = new PhaseNode_GetLineRotation(242, phase);
        CALL_REGISTER_SKILL_NODE(10232, 242, node242)
    }
    if (noInit == true) {
        return node242;
    }
    auto node246 = GET_SKILL_NODE(246, PhaseNode_GetLocation);
    auto node250 = GET_SKILL_NODE(250, PhaseNode_GetLocation);
    if (node246 != nullptr) node242->setStartX(node246->getX());
    if (node246 != nullptr) node242->setStartY(node246->getY());
    if (node250 != nullptr) node242->setEndX(node250->getX());
    if (node250 != nullptr) node242->setEndY(node250->getY());
    return node242;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(10232, 246) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetInputObject>(PhaseNode_GetLocation::TRIGGER_DONE, 248, PhaseNode_GetInputObject::FUNC_DO, &PhaseNode_GetInputObject::Do);
}

REGISTER_CREATE_SKILL_NODE(10232, 246) {
    auto node246 = GET_SKILL_NODE(246, PhaseNode_GetLocation);
    if (node246 == nullptr) {
        node246 = new PhaseNode_GetLocation(246, phase);
        node246->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node246->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(10232, 246, node246)
    }
    if (noInit == true) {
        return node246;
    }
    return node246;
}
//--------------------------------------------------------------------------------
// GetInputObject
//
REGISTER_REGISTER_SKILL_NODE(10232, 248) {
    pnode->resizeTrigger(PhaseNode_GetInputObject::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_GetInputObject::TRIGGER_DONE, 250, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(10232, 248) {
    auto node248 = GET_SKILL_NODE(248, PhaseNode_GetInputObject);
    if (node248 == nullptr) {
        node248 = new PhaseNode_GetInputObject(248, phase);
        node248->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        CALL_REGISTER_SKILL_NODE(10232, 248, node248)
    }
    if (noInit == true) {
        return node248;
    }
    return node248;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(10232, 250) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLineRotation>(PhaseNode_GetLocation::TRIGGER_DONE, 242, PhaseNode_GetLineRotation::FUNC_DO, &PhaseNode_GetLineRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(10232, 250) {
    auto node250 = GET_SKILL_NODE(250, PhaseNode_GetLocation);
    if (node250 == nullptr) {
        node250 = new PhaseNode_GetLocation(250, phase);
        node250->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        CALL_REGISTER_SKILL_NODE(10232, 250, node250)
    }
    if (noInit == true) {
        return node250;
    }
    auto node248 = GET_SKILL_NODE(248, PhaseNode_GetInputObject);
    if (node248 != nullptr) node250->setTarget(node248->getSceneObjId());
    return node250;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(10232, 251) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_ResetCD::TRIGGER_DONE, 252, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10232, 251) {
    auto node251 = GET_SKILL_NODE(251, PhaseNode_ResetCD);
    if (node251 == nullptr) {
        node251 = new PhaseNode_ResetCD(251, phase);
        node251->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node251->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node251->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(10232, 251, node251)
    }
    if (noInit == true) {
        return node251;
    }
    return node251;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10232, 252) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_PlayAnimation::TRIGGER_DONE, 254, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(10232, 252) {
    auto node252 = GET_SKILL_NODE(252, PhaseNode_PlayAnimation);
    if (node252 == nullptr) {
        node252 = new PhaseNode_PlayAnimation(252, phase);
        node252->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node252->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node252->setTarget(0U);
        node252->setAnimation("Skill2S1");
        node252->setParameter("SkillArmBusy");
        node252->setValue(true);
        CALL_REGISTER_SKILL_NODE(10232, 252, node252)
    }
    if (noInit == true) {
        return node252;
    }
    return node252;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10232, 253) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_PlaySound::TRIGGER_DONE, 246, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(10232, 253) {
    auto node253 = GET_SKILL_NODE(253, PhaseNode_PlaySound);
    if (node253 == nullptr) {
        node253 = new PhaseNode_PlaySound(253, phase);
        node253->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node253->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node253->setSoundID("VO_Hero123_Skill_B");
        node253->setTarget(0U);
        node253->setUsePos(false);
        node253->setPosX(.00f);
        node253->setPosY(.00f);
        node253->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10232, 253, node253)
    }
    if (noInit == true) {
        return node253;
    }
    return node253;
}
//--------------------------------------------------------------------------------
// GetActorAttribute
//
REGISTER_REGISTER_SKILL_NODE(10232, 254) {
    pnode->resizeTrigger(PhaseNode_GetActorAttribute::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 253, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10232, 254) {
    auto node254 = GET_SKILL_NODE(254, PhaseNode_GetActorAttribute);
    if (node254 == nullptr) {
        node254 = new PhaseNode_GetActorAttribute(254, phase);
        node254->setTarget(0U);
        node254->setType({});
        CALL_REGISTER_SKILL_NODE(10232, 254, node254)
    }
    if (noInit == true) {
        return node254;
    }
    return node254;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10232, 256) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_IsInterruptType>(PhaseNode_Detect::TRIGGER_ON, 262, PhaseNode_IsInterruptType::FUNC_DO, &PhaseNode_IsInterruptType::Do);
}

REGISTER_CREATE_SKILL_NODE(10232, 256) {
    auto node256 = GET_SKILL_NODE(256, PhaseNode_Detect);
    if (node256 == nullptr) {
        node256 = new PhaseNode_Detect(256, phase);
        node256->setSelf(0U);
        node256->setEvent("daduan_001");
        node256->setType(PhaseNode_Detect::Detect_Type::Interrupt_Skill);
        node256->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10232, 256, node256)
    }
    if (noInit == true) {
        return node256;
    }
    return node256;
}
//--------------------------------------------------------------------------------
// SwitchToInt
//
REGISTER_REGISTER_SKILL_NODE(10232, 257) {
    pnode->resizeTrigger(4);
    pnode->regTrigger<PhaseNode_EndPhase>(1, 18, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(10232, 257) {
    auto node257 = GET_SKILL_NODE(257, PhaseNode_SwitchToInt);
    if (node257 == nullptr) {
        node257 = new PhaseNode_SwitchToInt(257, phase);
        CALL_REGISTER_SKILL_NODE(10232, 257, node257)
    }
    if (noInit == true) {
        return node257;
    }
    auto variables = node257->getVariables();
    if (variables != nullptr) {
        node257->setSelection(variables->getVariable<int32_t>(Variable_10232_a102322));
    }
    return node257;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10232, 259) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_RaiseEvent::TRIGGER_DONE, 268, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10232, 259) {
    auto node259 = GET_SKILL_NODE(259, PhaseNode_RaiseEvent);
    if (node259 == nullptr) {
        node259 = new PhaseNode_RaiseEvent(259, phase);
        node259->setEvent("daduan_001");
        node259->setTarget(0U);
        node259->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node259->setTypeParams(0, 0);
        node259->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10232, 259, node259)
    }
    if (noInit == true) {
        return node259;
    }
    return node259;
}
//--------------------------------------------------------------------------------
// StartPreInput
//
REGISTER_REGISTER_SKILL_NODE(10232, 260) {
    pnode->resizeTrigger(PhaseNode_StartPreInput::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_StartPreInput::TRIGGER_DONE, 264, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_StartPreInput::TRIGGER_DONE, 237, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10232, 260) {
    auto node260 = GET_SKILL_NODE(260, PhaseNode_StartPreInput);
    if (node260 == nullptr) {
        node260 = new PhaseNode_StartPreInput(260, phase);
        node260->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node260->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node260->setDelayTime(.00f);
        CALL_REGISTER_SKILL_NODE(10232, 260, node260)
    }
    if (noInit == true) {
        return node260;
    }
    return node260;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(10232, 261) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_If::TRIGGER_TRUE, 263, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10232, 261) {
    auto node261 = GET_SKILL_NODE(261, PhaseNode_If);
    if (node261 == nullptr) {
        node261 = new PhaseNode_If(261, phase);
        CALL_REGISTER_SKILL_NODE(10232, 261, node261)
    }
    if (noInit == true) {
        return node261;
    }
    auto variables = node261->getVariables();
    if (variables != nullptr) {
        node261->setCondition(variables->getVariable<bool>(Variable_10232_InterruptAnimat));
    }
    return node261;
}
//--------------------------------------------------------------------------------
// IsInterruptType
//
REGISTER_REGISTER_SKILL_NODE(10232, 262) {
    pnode->resizeTrigger(PhaseNode_IsInterruptType::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SwitchToInt>(PhaseNode_IsInterruptType::TRIGGER_BUFF, 257, PhaseNode_SwitchToInt::FUNC_SWITCH, &PhaseNode_SwitchToInt::Switch);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_POSCHANGE, 261, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTAIM, 261, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTFIRE, 261, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTRELOAD, 261, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_USESKILL, 261, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(10232, 262) {
    auto node262 = GET_SKILL_NODE(262, PhaseNode_IsInterruptType);
    if (node262 == nullptr) {
        node262 = new PhaseNode_IsInterruptType(262, phase);
        node262->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node262->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10232, 262, node262)
    }
    if (noInit == true) {
        return node262;
    }
    auto node256 = GET_SKILL_NODE(256, PhaseNode_Detect);
    if (node256 != nullptr) node262->setType(node256->getVars().getVariable<int32_t>(2));
    return node262;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10232, 263) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_PlayAnimation::TRIGGER_DONE, 18, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(10232, 263) {
    auto node263 = GET_SKILL_NODE(263, PhaseNode_PlayAnimation);
    if (node263 == nullptr) {
        node263 = new PhaseNode_PlayAnimation(263, phase);
        node263->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node263->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node263->setTarget(0U);
        node263->setAnimation("Idle");
        node263->setParameter("");
        node263->setValue(false);
        CALL_REGISTER_SKILL_NODE(10232, 263, node263)
    }
    if (noInit == true) {
        return node263;
    }
    return node263;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10232, 264) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_Delay::TRIGGER_DONE, 267, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(10232, 264) {
    auto node264 = GET_SKILL_NODE(264, PhaseNode_Delay);
    if (node264 == nullptr) {
        node264 = new PhaseNode_Delay(264, phase);
        node264->setTime(.20f);
        CALL_REGISTER_SKILL_NODE(10232, 264, node264)
    }
    if (noInit == true) {
        return node264;
    }
    return node264;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(10232, 267) {
}

REGISTER_CREATE_SKILL_NODE(10232, 267) {
    auto node267 = GET_SKILL_NODE(267, PhaseNode_SetBool);
    if (node267 == nullptr) {
        node267 = new PhaseNode_SetBool(267, phase);
        node267->setName("InterruptAnimat");
        node267->setValue(true);
        CALL_REGISTER_SKILL_NODE(10232, 267, node267)
    }
    if (noInit == true) {
        return node267;
    }
    return node267;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10232, 268) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StartPreInput>(PhaseNode_RaiseEvent::TRIGGER_DONE, 260, PhaseNode_StartPreInput::FUNC_DO, &PhaseNode_StartPreInput::Do);
}

REGISTER_CREATE_SKILL_NODE(10232, 268) {
    auto node268 = GET_SKILL_NODE(268, PhaseNode_RaiseEvent);
    if (node268 == nullptr) {
        node268 = new PhaseNode_RaiseEvent(268, phase);
        node268->setEvent("Dead_001");
        node268->setTarget(0U);
        node268->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node268->setTypeParams(0, 0);
        node268->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10232, 268, node268)
    }
    if (noInit == true) {
        return node268;
    }
    return node268;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10232, 269) {
}

REGISTER_CREATE_SKILL_NODE(10232, 269) {
    auto node269 = GET_SKILL_NODE(269, PhaseNode_Detect);
    if (node269 == nullptr) {
        node269 = new PhaseNode_Detect(269, phase);
        node269->setSelf(0U);
        node269->setEvent("Dead_001");
        node269->setType(PhaseNode_Detect::Detect_Type::Actor_Dead);
        node269->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10232, 269, node269)
    }
    if (noInit == true) {
        return node269;
    }
    return node269;
}

//--------------------------------------------------------------------------------
// SkillCreator_10232
//
class SkillCreator_10232 : public SkillCreator {
public:
    SkillCreator_10232() {}
    virtual ~SkillCreator_10232() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_10232

//--------------------------------------------------------------------------------
// SkillPhase_10232
//
class SkillPhase_10232 : public SkillPhase {
public:
    SkillPhase_10232(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_10232() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(10232, 1) // StartPhase
        CASE_CREATE_SKILL_NODE(10232, 18) // EndPhase
        CASE_CREATE_SKILL_NODE(10232, 145) // Disable
        CASE_CREATE_SKILL_NODE(10232, 174) // PlaySound
        CASE_CREATE_SKILL_NODE(10232, 194) // Delay
        CASE_CREATE_SKILL_NODE(10232, 226) // PlayEffect
        CASE_CREATE_SKILL_NODE(10232, 229) // SpawnProjectile
        CASE_CREATE_SKILL_NODE(10232, 237) // PlaySound
        CASE_CREATE_SKILL_NODE(10232, 242) // GetLineRotation
        CASE_CREATE_SKILL_NODE(10232, 246) // GetLocation
        CASE_CREATE_SKILL_NODE(10232, 248) // GetInputObject
        CASE_CREATE_SKILL_NODE(10232, 250) // GetLocation
        CASE_CREATE_SKILL_NODE(10232, 251) // ResetCD
        CASE_CREATE_SKILL_NODE(10232, 252) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10232, 253) // PlaySound
        CASE_CREATE_SKILL_NODE(10232, 254) // GetActorAttribute
        CASE_CREATE_SKILL_NODE(10232, 256) // Detect
        CASE_CREATE_SKILL_NODE(10232, 257) // SwitchToInt
        CASE_CREATE_SKILL_NODE(10232, 259) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10232, 260) // StartPreInput
        CASE_CREATE_SKILL_NODE(10232, 261) // If
        CASE_CREATE_SKILL_NODE(10232, 262) // IsInterruptType
        CASE_CREATE_SKILL_NODE(10232, 263) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10232, 264) // Delay
        CASE_CREATE_SKILL_NODE(10232, 267) // SetBool
        CASE_CREATE_SKILL_NODE(10232, 268) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10232, 269) // Detect
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_10232

SkillLogic* SkillCreator_10232::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //设置变量
    Variable_10232_a102322 = logic->getVariables().setVariable<int32_t>("a102322", 1);
    Variable_10232_InterruptAnimat = logic->getVariables().setVariable<bool>("InterruptAnimat");
    //创建阶段phase
    auto phase = new SkillPhase_10232(1, logic, 2);
    //设置phase执行器
    phase->setRunPhaseNode(1, 1);
    phase->setDetectPhaseNode(2, 256);
    phase->setDetectPhaseNode(2, 269);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_10232::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
