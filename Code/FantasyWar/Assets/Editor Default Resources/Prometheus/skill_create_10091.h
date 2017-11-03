#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

#include "skill_psnode_cameraxyzshake.h"
#include "skill_psnode_delay.h"
#include "skill_psnode_detect.h"
#include "skill_psnode_disable.h"
#include "skill_psnode_endphase.h"
#include "skill_psnode_getactorattribute.h"
#include "skill_psnode_getinputrotation.h"
#include "skill_psnode_getlocation.h"
#include "skill_psnode_if.h"
#include "skill_psnode_isinterrupttype.h"
#include "skill_psnode_offsetcalculate.h"
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
uint64_t Variable_10091_100912 = 0;
uint64_t Variable_10091_InterruptAnimat = 0;
//--------------------------------------------------------------------------------
// StartPhase
//
REGISTER_REGISTER_SKILL_NODE(10091, 2) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_StartPhase::TRIGGER_START, 268, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(10091, 2) {
    auto node2 = GET_SKILL_NODE(2, PhaseNode_StartPhase);
    if (node2 == nullptr) {
        node2 = new PhaseNode_StartPhase(2, phase);
        CALL_REGISTER_SKILL_NODE(10091, 2, node2)
    }
    if (noInit == true) {
        return node2;
    }
    return node2;
}
//--------------------------------------------------------------------------------
// Disable
//
REGISTER_REGISTER_SKILL_NODE(10091, 4) {
    pnode->resizeTrigger(PhaseNode_Disable::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_Disable::TRIGGER_DONE, 33, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10091, 4) {
    auto node4 = GET_SKILL_NODE(4, PhaseNode_Disable);
    if (node4 == nullptr) {
        node4 = new PhaseNode_Disable(4, phase);
        node4->setTarget(0U);
        node4->setMove(true);
        node4->setSkill(true);
        node4->setShoot(true);
        node4->setTime(.45f);
        node4->setRotate(true);
        CALL_REGISTER_SKILL_NODE(10091, 4, node4)
    }
    if (noInit == true) {
        return node4;
    }
    return node4;
}
//--------------------------------------------------------------------------------
// OffsetCalculate
//
REGISTER_REGISTER_SKILL_NODE(10091, 31) {
    pnode->resizeTrigger(PhaseNode_OffsetCalculate::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 75, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(10091, 31) {
    auto node31 = GET_SKILL_NODE(31, PhaseNode_OffsetCalculate);
    if (node31 == nullptr) {
        node31 = new PhaseNode_OffsetCalculate(31, phase);
        node31->setPosZ(.00f);
        node31->setOffsetX(.00f);
        node31->setOffsetY(.50f);
        node31->setOffsetZ(1.50f);
        node31->setRotOffset(.00f);
        CALL_REGISTER_SKILL_NODE(10091, 31, node31)
    }
    if (noInit == true) {
        return node31;
    }
    auto node259 = GET_SKILL_NODE(259, PhaseNode_GetLocation);
    auto node261 = GET_SKILL_NODE(261, PhaseNode_GetInputRotation);
    if (node259 != nullptr) node31->setPosX(node259->getX());
    if (node259 != nullptr) node31->setPosY(node259->getY());
    if (node261 != nullptr) node31->setRotation(node261->getAngle());
    return node31;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10091, 33) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CameraXYZShake>(PhaseNode_Delay::TRIGGER_DONE, 253, PhaseNode_CameraXYZShake::FUNC_DO, &PhaseNode_CameraXYZShake::Do);
    pnode->regTrigger<PhaseNode_SpawnProjectile>(PhaseNode_Delay::TRIGGER_DONE, 256, PhaseNode_SpawnProjectile::FUNC_DO, &PhaseNode_SpawnProjectile::Do);
}

REGISTER_CREATE_SKILL_NODE(10091, 33) {
    auto node33 = GET_SKILL_NODE(33, PhaseNode_Delay);
    if (node33 == nullptr) {
        node33 = new PhaseNode_Delay(33, phase);
        node33->setTime(.25f);
        CALL_REGISTER_SKILL_NODE(10091, 33, node33)
    }
    if (noInit == true) {
        return node33;
    }
    return node33;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(10091, 45) {
}

REGISTER_CREATE_SKILL_NODE(10091, 45) {
    auto node45 = GET_SKILL_NODE(45, PhaseNode_EndPhase);
    if (node45 == nullptr) {
        node45 = new PhaseNode_EndPhase(45, phase);
        node45->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node45->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10091, 45, node45)
    }
    if (noInit == true) {
        return node45;
    }
    return node45;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(10091, 75) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Disable>(PhaseNode_PlayEffect::TRIGGER_DONE, 4, PhaseNode_Disable::FUNC_DO, &PhaseNode_Disable::Do);
}

REGISTER_CREATE_SKILL_NODE(10091, 75) {
    auto node75 = GET_SKILL_NODE(75, PhaseNode_PlayEffect);
    if (node75 == nullptr) {
        node75 = new PhaseNode_PlayEffect(75, phase);
        node75->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node75->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node75->setEffectID(100911);
        node75->setChangeColor(true);
        node75->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node75->getVars().reserve(3);
        node75->getVars().setVariable<float>(0, .00f);
        node75->getVars().setVariable<float>(1, .00f);
        node75->getVars().setVariable<float>(2, .00f);
        node75->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(10091, 75, node75)
    }
    if (noInit == true) {
        return node75;
    }
    auto node31 = GET_SKILL_NODE(31, PhaseNode_OffsetCalculate);
    if (node31 != nullptr) node75->getVars().setVariable<float>(0, node31->getOutPosX());
    if (node31 != nullptr) node75->getVars().setVariable<float>(1, node31->getOutPosY());
    if (node31 != nullptr) node75->getVars().setVariable<float>(2, node31->getOutPosZ());
    if (node31 != nullptr) node75->setRotation(node31->getOutRotation());
    return node75;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10091, 193) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_Delay::TRIGGER_DONE, 45, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(10091, 193) {
    auto node193 = GET_SKILL_NODE(193, PhaseNode_Delay);
    if (node193 == nullptr) {
        node193 = new PhaseNode_Delay(193, phase);
        node193->setTime(.31f);
        CALL_REGISTER_SKILL_NODE(10091, 193, node193)
    }
    if (noInit == true) {
        return node193;
    }
    return node193;
}
//--------------------------------------------------------------------------------
// CameraXYZShake
//
REGISTER_REGISTER_SKILL_NODE(10091, 253) {
}

REGISTER_CREATE_SKILL_NODE(10091, 253) {
    auto node253 = GET_SKILL_NODE(253, PhaseNode_CameraXYZShake);
    if (node253 == nullptr) {
        node253 = new PhaseNode_CameraXYZShake(253, phase);
        node253->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node253->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node253->setShakeStyle(0);
        node253->setTarget(0U);
        node253->setX(.25f);
        node253->setY(.25f);
        node253->setZ(.25f);
        node253->setDuration(.10f);
        node253->setTimes(2);
        CALL_REGISTER_SKILL_NODE(10091, 253, node253)
    }
    if (noInit == true) {
        return node253;
    }
    return node253;
}
//--------------------------------------------------------------------------------
// SpawnProjectile
//
REGISTER_REGISTER_SKILL_NODE(10091, 256) {
    pnode->resizeTrigger(PhaseNode_SpawnProjectile::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_SpawnProjectile::TRIGGER_DONE, 193, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10091, 256) {
    auto node256 = GET_SKILL_NODE(256, PhaseNode_SpawnProjectile);
    if (node256 == nullptr) {
        node256 = new PhaseNode_SpawnProjectile(256, phase);
        node256->setDataId(55091);
        node256->setEndPosX(.00f);
        node256->setEndPosY(.00f);
        node256->setEndPosZ(.00f);
        node256->setMaxCount(0);
        CALL_REGISTER_SKILL_NODE(10091, 256, node256)
    }
    if (noInit == true) {
        return node256;
    }
    auto node31 = GET_SKILL_NODE(31, PhaseNode_OffsetCalculate);
    if (node31 != nullptr) node256->setPosX(node31->getOutPosX());
    if (node31 != nullptr) node256->setPosY(node31->getOutPosY());
    if (node31 != nullptr) node256->setPosZ(node31->getOutPosZ());
    if (node31 != nullptr) node256->setRotation(node31->getOutRotation());
    return node256;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(10091, 259) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetInputRotation>(PhaseNode_GetLocation::TRIGGER_DONE, 261, PhaseNode_GetInputRotation::FUNC_DO, &PhaseNode_GetInputRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(10091, 259) {
    auto node259 = GET_SKILL_NODE(259, PhaseNode_GetLocation);
    if (node259 == nullptr) {
        node259 = new PhaseNode_GetLocation(259, phase);
        node259->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node259->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(10091, 259, node259)
    }
    if (noInit == true) {
        return node259;
    }
    return node259;
}
//--------------------------------------------------------------------------------
// GetInputRotation
//
REGISTER_REGISTER_SKILL_NODE(10091, 261) {
    pnode->resizeTrigger(PhaseNode_GetInputRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_OffsetCalculate>(PhaseNode_GetInputRotation::TRIGGER_DONE, 31, PhaseNode_OffsetCalculate::FUNC_DO, &PhaseNode_OffsetCalculate::Do);
}

REGISTER_CREATE_SKILL_NODE(10091, 261) {
    auto node261 = GET_SKILL_NODE(261, PhaseNode_GetInputRotation);
    if (node261 == nullptr) {
        node261 = new PhaseNode_GetInputRotation(261, phase);
        node261->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        CALL_REGISTER_SKILL_NODE(10091, 261, node261)
    }
    if (noInit == true) {
        return node261;
    }
    return node261;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10091, 267) {
}

REGISTER_CREATE_SKILL_NODE(10091, 267) {
    auto node267 = GET_SKILL_NODE(267, PhaseNode_PlaySound);
    if (node267 == nullptr) {
        node267 = new PhaseNode_PlaySound(267, phase);
        node267->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node267->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node267->setSoundID("SE_Hero109_Skill_A_P1");
        node267->setTarget(0U);
        node267->setUsePos(false);
        node267->setPosX(.00f);
        node267->setPosY(.00f);
        node267->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10091, 267, node267)
    }
    if (noInit == true) {
        return node267;
    }
    return node267;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(10091, 268) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_ResetCD::TRIGGER_DONE, 269, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10091, 268) {
    auto node268 = GET_SKILL_NODE(268, PhaseNode_ResetCD);
    if (node268 == nullptr) {
        node268 = new PhaseNode_ResetCD(268, phase);
        node268->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node268->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node268->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(10091, 268, node268)
    }
    if (noInit == true) {
        return node268;
    }
    return node268;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10091, 269) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_PlayAnimation::TRIGGER_DONE, 271, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(10091, 269) {
    auto node269 = GET_SKILL_NODE(269, PhaseNode_PlayAnimation);
    if (node269 == nullptr) {
        node269 = new PhaseNode_PlayAnimation(269, phase);
        node269->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node269->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node269->setTarget(0U);
        node269->setAnimation("Skill1S1");
        node269->setParameter("");
        node269->setValue(false);
        CALL_REGISTER_SKILL_NODE(10091, 269, node269)
    }
    if (noInit == true) {
        return node269;
    }
    return node269;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10091, 270) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_PlaySound::TRIGGER_DONE, 259, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_PlaySound::TRIGGER_DONE, 267, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_PlaySound::TRIGGER_DONE, 276, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10091, 270) {
    auto node270 = GET_SKILL_NODE(270, PhaseNode_PlaySound);
    if (node270 == nullptr) {
        node270 = new PhaseNode_PlaySound(270, phase);
        node270->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node270->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node270->setSoundID("");
        node270->setTarget(0U);
        node270->setUsePos(false);
        node270->setPosX(.00f);
        node270->setPosY(.00f);
        node270->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10091, 270, node270)
    }
    if (noInit == true) {
        return node270;
    }
    return node270;
}
//--------------------------------------------------------------------------------
// GetActorAttribute
//
REGISTER_REGISTER_SKILL_NODE(10091, 271) {
    pnode->resizeTrigger(PhaseNode_GetActorAttribute::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 270, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10091, 271) {
    auto node271 = GET_SKILL_NODE(271, PhaseNode_GetActorAttribute);
    if (node271 == nullptr) {
        node271 = new PhaseNode_GetActorAttribute(271, phase);
        node271->setTarget(0U);
        node271->setType({});
        CALL_REGISTER_SKILL_NODE(10091, 271, node271)
    }
    if (noInit == true) {
        return node271;
    }
    return node271;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10091, 273) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_IsInterruptType>(PhaseNode_Detect::TRIGGER_ON, 279, PhaseNode_IsInterruptType::FUNC_DO, &PhaseNode_IsInterruptType::Do);
}

REGISTER_CREATE_SKILL_NODE(10091, 273) {
    auto node273 = GET_SKILL_NODE(273, PhaseNode_Detect);
    if (node273 == nullptr) {
        node273 = new PhaseNode_Detect(273, phase);
        node273->setSelf(0U);
        node273->setEvent("daduan_001");
        node273->setType(PhaseNode_Detect::Detect_Type::Interrupt_Skill);
        node273->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10091, 273, node273)
    }
    if (noInit == true) {
        return node273;
    }
    return node273;
}
//--------------------------------------------------------------------------------
// SwitchToInt
//
REGISTER_REGISTER_SKILL_NODE(10091, 274) {
    pnode->resizeTrigger(4);
    pnode->regTrigger<PhaseNode_EndPhase>(1, 45, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(10091, 274) {
    auto node274 = GET_SKILL_NODE(274, PhaseNode_SwitchToInt);
    if (node274 == nullptr) {
        node274 = new PhaseNode_SwitchToInt(274, phase);
        CALL_REGISTER_SKILL_NODE(10091, 274, node274)
    }
    if (noInit == true) {
        return node274;
    }
    auto variables = node274->getVariables();
    if (variables != nullptr) {
        node274->setSelection(variables->getVariable<int32_t>(Variable_10091_100912));
    }
    return node274;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10091, 276) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_RaiseEvent::TRIGGER_DONE, 285, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10091, 276) {
    auto node276 = GET_SKILL_NODE(276, PhaseNode_RaiseEvent);
    if (node276 == nullptr) {
        node276 = new PhaseNode_RaiseEvent(276, phase);
        node276->setEvent("daduan_001");
        node276->setTarget(0U);
        node276->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node276->setTypeParams(0, 0);
        node276->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10091, 276, node276)
    }
    if (noInit == true) {
        return node276;
    }
    return node276;
}
//--------------------------------------------------------------------------------
// StartPreInput
//
REGISTER_REGISTER_SKILL_NODE(10091, 277) {
    pnode->resizeTrigger(PhaseNode_StartPreInput::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_StartPreInput::TRIGGER_DONE, 281, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10091, 277) {
    auto node277 = GET_SKILL_NODE(277, PhaseNode_StartPreInput);
    if (node277 == nullptr) {
        node277 = new PhaseNode_StartPreInput(277, phase);
        node277->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node277->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node277->setDelayTime(.00f);
        CALL_REGISTER_SKILL_NODE(10091, 277, node277)
    }
    if (noInit == true) {
        return node277;
    }
    return node277;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(10091, 278) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_If::TRIGGER_TRUE, 280, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10091, 278) {
    auto node278 = GET_SKILL_NODE(278, PhaseNode_If);
    if (node278 == nullptr) {
        node278 = new PhaseNode_If(278, phase);
        CALL_REGISTER_SKILL_NODE(10091, 278, node278)
    }
    if (noInit == true) {
        return node278;
    }
    auto variables = node278->getVariables();
    if (variables != nullptr) {
        node278->setCondition(variables->getVariable<bool>(Variable_10091_InterruptAnimat));
    }
    return node278;
}
//--------------------------------------------------------------------------------
// IsInterruptType
//
REGISTER_REGISTER_SKILL_NODE(10091, 279) {
    pnode->resizeTrigger(PhaseNode_IsInterruptType::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SwitchToInt>(PhaseNode_IsInterruptType::TRIGGER_BUFF, 274, PhaseNode_SwitchToInt::FUNC_SWITCH, &PhaseNode_SwitchToInt::Switch);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_POSCHANGE, 278, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTAIM, 278, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTFIRE, 278, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTRELOAD, 278, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_USESKILL, 278, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(10091, 279) {
    auto node279 = GET_SKILL_NODE(279, PhaseNode_IsInterruptType);
    if (node279 == nullptr) {
        node279 = new PhaseNode_IsInterruptType(279, phase);
        node279->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node279->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10091, 279, node279)
    }
    if (noInit == true) {
        return node279;
    }
    auto node273 = GET_SKILL_NODE(273, PhaseNode_Detect);
    if (node273 != nullptr) node279->setType(node273->getVars().getVariable<int32_t>(2));
    return node279;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10091, 280) {
}

REGISTER_CREATE_SKILL_NODE(10091, 280) {
    auto node280 = GET_SKILL_NODE(280, PhaseNode_PlayAnimation);
    if (node280 == nullptr) {
        node280 = new PhaseNode_PlayAnimation(280, phase);
        node280->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node280->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node280->setTarget(0U);
        node280->setAnimation("Idle");
        node280->setParameter("");
        node280->setValue(false);
        CALL_REGISTER_SKILL_NODE(10091, 280, node280)
    }
    if (noInit == true) {
        return node280;
    }
    return node280;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10091, 281) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_Delay::TRIGGER_DONE, 284, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(10091, 281) {
    auto node281 = GET_SKILL_NODE(281, PhaseNode_Delay);
    if (node281 == nullptr) {
        node281 = new PhaseNode_Delay(281, phase);
        node281->setTime(.30f);
        CALL_REGISTER_SKILL_NODE(10091, 281, node281)
    }
    if (noInit == true) {
        return node281;
    }
    return node281;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(10091, 284) {
}

REGISTER_CREATE_SKILL_NODE(10091, 284) {
    auto node284 = GET_SKILL_NODE(284, PhaseNode_SetBool);
    if (node284 == nullptr) {
        node284 = new PhaseNode_SetBool(284, phase);
        node284->setName("InterruptAnimat");
        node284->setValue(true);
        CALL_REGISTER_SKILL_NODE(10091, 284, node284)
    }
    if (noInit == true) {
        return node284;
    }
    return node284;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10091, 285) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StartPreInput>(PhaseNode_RaiseEvent::TRIGGER_DONE, 277, PhaseNode_StartPreInput::FUNC_DO, &PhaseNode_StartPreInput::Do);
}

REGISTER_CREATE_SKILL_NODE(10091, 285) {
    auto node285 = GET_SKILL_NODE(285, PhaseNode_RaiseEvent);
    if (node285 == nullptr) {
        node285 = new PhaseNode_RaiseEvent(285, phase);
        node285->setEvent("Dead_001");
        node285->setTarget(0U);
        node285->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node285->setTypeParams(0, 0);
        node285->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10091, 285, node285)
    }
    if (noInit == true) {
        return node285;
    }
    return node285;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10091, 286) {
}

REGISTER_CREATE_SKILL_NODE(10091, 286) {
    auto node286 = GET_SKILL_NODE(286, PhaseNode_Detect);
    if (node286 == nullptr) {
        node286 = new PhaseNode_Detect(286, phase);
        node286->setSelf(0U);
        node286->setEvent("Dead_001");
        node286->setType(PhaseNode_Detect::Detect_Type::Actor_Dead);
        node286->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10091, 286, node286)
    }
    if (noInit == true) {
        return node286;
    }
    return node286;
}

//--------------------------------------------------------------------------------
// SkillCreator_10091
//
class SkillCreator_10091 : public SkillCreator {
public:
    SkillCreator_10091() {}
    virtual ~SkillCreator_10091() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_10091

//--------------------------------------------------------------------------------
// SkillPhase_10091
//
class SkillPhase_10091 : public SkillPhase {
public:
    SkillPhase_10091(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_10091() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(10091, 2) // StartPhase
        CASE_CREATE_SKILL_NODE(10091, 4) // Disable
        CASE_CREATE_SKILL_NODE(10091, 31) // OffsetCalculate
        CASE_CREATE_SKILL_NODE(10091, 33) // Delay
        CASE_CREATE_SKILL_NODE(10091, 45) // EndPhase
        CASE_CREATE_SKILL_NODE(10091, 75) // PlayEffect
        CASE_CREATE_SKILL_NODE(10091, 193) // Delay
        CASE_CREATE_SKILL_NODE(10091, 253) // CameraXYZShake
        CASE_CREATE_SKILL_NODE(10091, 256) // SpawnProjectile
        CASE_CREATE_SKILL_NODE(10091, 259) // GetLocation
        CASE_CREATE_SKILL_NODE(10091, 261) // GetInputRotation
        CASE_CREATE_SKILL_NODE(10091, 267) // PlaySound
        CASE_CREATE_SKILL_NODE(10091, 268) // ResetCD
        CASE_CREATE_SKILL_NODE(10091, 269) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10091, 270) // PlaySound
        CASE_CREATE_SKILL_NODE(10091, 271) // GetActorAttribute
        CASE_CREATE_SKILL_NODE(10091, 273) // Detect
        CASE_CREATE_SKILL_NODE(10091, 274) // SwitchToInt
        CASE_CREATE_SKILL_NODE(10091, 276) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10091, 277) // StartPreInput
        CASE_CREATE_SKILL_NODE(10091, 278) // If
        CASE_CREATE_SKILL_NODE(10091, 279) // IsInterruptType
        CASE_CREATE_SKILL_NODE(10091, 280) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10091, 281) // Delay
        CASE_CREATE_SKILL_NODE(10091, 284) // SetBool
        CASE_CREATE_SKILL_NODE(10091, 285) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10091, 286) // Detect
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_10091

SkillLogic* SkillCreator_10091::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //设置变量
    Variable_10091_100912 = logic->getVariables().setVariable<int32_t>("100912", 1);
    Variable_10091_InterruptAnimat = logic->getVariables().setVariable<bool>("InterruptAnimat");
    //创建阶段phase
    auto phase = new SkillPhase_10091(1, logic, 2);
    //设置phase执行器
    phase->setRunPhaseNode(1, 2);
    phase->setDetectPhaseNode(2, 273);
    phase->setDetectPhaseNode(2, 286);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_10091::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
