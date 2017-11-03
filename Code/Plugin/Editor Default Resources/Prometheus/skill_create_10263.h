#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

#include "skill_psnode_delay.h"
#include "skill_psnode_detect.h"
#include "skill_psnode_disable.h"
#include "skill_psnode_endphase.h"
#include "skill_psnode_getinputlocation.h"
#include "skill_psnode_getlinerotation.h"
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
#include "skill_psnode_triggerupdate.h"

namespace pvp {

//变量声明
uint64_t Variable_10263_102632 = 0;
uint64_t Variable_10263_InterruptAnimat = 0;
//--------------------------------------------------------------------------------
// StartPhase
//
REGISTER_REGISTER_SKILL_NODE(10263, 2) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_StartPhase::TRIGGER_START, 10, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(10263, 2) {
    auto node2 = GET_SKILL_NODE(2, PhaseNode_StartPhase);
    if (node2 == nullptr) {
        node2 = new PhaseNode_StartPhase(2, phase);
        CALL_REGISTER_SKILL_NODE(10263, 2, node2)
    }
    if (noInit == true) {
        return node2;
    }
    return node2;
}
//--------------------------------------------------------------------------------
// TriggerUpdate
//
REGISTER_REGISTER_SKILL_NODE(10263, 4) {
}

REGISTER_CREATE_SKILL_NODE(10263, 4) {
    auto node4 = GET_SKILL_NODE(4, PhaseNode_TriggerUpdate);
    if (node4 == nullptr) {
        node4 = new PhaseNode_TriggerUpdate(4, phase);
        CALL_REGISTER_SKILL_NODE(10263, 4, node4)
    }
    if (noInit == true) {
        return node4;
    }
    return node4;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10263, 8) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Disable>(PhaseNode_PlayAnimation::TRIGGER_DONE, 12, PhaseNode_Disable::FUNC_DO, &PhaseNode_Disable::Do);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_PlayAnimation::TRIGGER_DONE, 287, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10263, 8) {
    auto node8 = GET_SKILL_NODE(8, PhaseNode_PlayAnimation);
    if (node8 == nullptr) {
        node8 = new PhaseNode_PlayAnimation(8, phase);
        node8->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node8->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node8->setTarget(0U);
        node8->setAnimation("Skill3S1");
        node8->setParameter("");
        node8->setValue(false);
        CALL_REGISTER_SKILL_NODE(10263, 8, node8)
    }
    if (noInit == true) {
        return node8;
    }
    return node8;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(10263, 10) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_ResetCD::TRIGGER_DONE, 8, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10263, 10) {
    auto node10 = GET_SKILL_NODE(10, PhaseNode_ResetCD);
    if (node10 == nullptr) {
        node10 = new PhaseNode_ResetCD(10, phase);
        node10->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node10->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node10->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(10263, 10, node10)
    }
    if (noInit == true) {
        return node10;
    }
    return node10;
}
//--------------------------------------------------------------------------------
// Disable
//
REGISTER_REGISTER_SKILL_NODE(10263, 12) {
    pnode->resizeTrigger(PhaseNode_Disable::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_Disable::TRIGGER_DONE, 44, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_Disable::TRIGGER_DONE, 155, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_Disable::TRIGGER_DONE, 280, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10263, 12) {
    auto node12 = GET_SKILL_NODE(12, PhaseNode_Disable);
    if (node12 == nullptr) {
        node12 = new PhaseNode_Disable(12, phase);
        node12->setTarget(0U);
        node12->setMove(true);
        node12->setSkill(true);
        node12->setShoot(true);
        node12->setTime(.50f);
        node12->setRotate(true);
        CALL_REGISTER_SKILL_NODE(10263, 12, node12)
    }
    if (noInit == true) {
        return node12;
    }
    return node12;
}
//--------------------------------------------------------------------------------
// OffsetCalculate
//
REGISTER_REGISTER_SKILL_NODE(10263, 18) {
    pnode->resizeTrigger(PhaseNode_OffsetCalculate::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnProjectile>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 272, PhaseNode_SpawnProjectile::FUNC_DO, &PhaseNode_SpawnProjectile::Do);
}

REGISTER_CREATE_SKILL_NODE(10263, 18) {
    auto node18 = GET_SKILL_NODE(18, PhaseNode_OffsetCalculate);
    if (node18 == nullptr) {
        node18 = new PhaseNode_OffsetCalculate(18, phase);
        node18->setPosZ(.00f);
        node18->setOffsetX(.40f);
        node18->setOffsetY(.90f);
        node18->setOffsetZ(.00f);
        node18->setRotOffset(.00f);
        CALL_REGISTER_SKILL_NODE(10263, 18, node18)
    }
    if (noInit == true) {
        return node18;
    }
    auto node23 = GET_SKILL_NODE(23, PhaseNode_GetLocation);
    auto node282 = GET_SKILL_NODE(282, PhaseNode_GetLineRotation);
    if (node23 != nullptr) node18->setPosX(node23->getX());
    if (node23 != nullptr) node18->setPosY(node23->getY());
    if (node282 != nullptr) node18->setRotation(node282->getRotation());
    return node18;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(10263, 23) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetInputLocation>(PhaseNode_GetLocation::TRIGGER_DONE, 278, PhaseNode_GetInputLocation::FUNC_DO, &PhaseNode_GetInputLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(10263, 23) {
    auto node23 = GET_SKILL_NODE(23, PhaseNode_GetLocation);
    if (node23 == nullptr) {
        node23 = new PhaseNode_GetLocation(23, phase);
        node23->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node23->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(10263, 23, node23)
    }
    if (noInit == true) {
        return node23;
    }
    return node23;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10263, 44) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_Delay::TRIGGER_DONE, 23, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(10263, 44) {
    auto node44 = GET_SKILL_NODE(44, PhaseNode_Delay);
    if (node44 == nullptr) {
        node44 = new PhaseNode_Delay(44, phase);
        node44->setTime(.10f);
        CALL_REGISTER_SKILL_NODE(10263, 44, node44)
    }
    if (noInit == true) {
        return node44;
    }
    return node44;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(10263, 155) {
}

REGISTER_CREATE_SKILL_NODE(10263, 155) {
    auto node155 = GET_SKILL_NODE(155, PhaseNode_PlayEffect);
    if (node155 == nullptr) {
        node155 = new PhaseNode_PlayEffect(155, phase);
        node155->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node155->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node155->setEffectID(102633);
        node155->setChangeColor(true);
        node155->setType(PhaseNode_PlayEffect::PlayEffect_Type::WithTarget);
        node155->getVars().reserve(5);
        node155->getVars().setVariable<uint64_t>(0, 0U);
        node155->getVars().setVariable<std::string>(1, "Effect");
        node155->getVars().setVariable<float>(2, .00f);
        node155->getVars().setVariable<float>(3, .00f);
        node155->getVars().setVariable<float>(4, .00f);
        node155->setRotation(.00f);
        node155->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(10263, 155, node155)
    }
    if (noInit == true) {
        return node155;
    }
    return node155;
}
//--------------------------------------------------------------------------------
// SpawnProjectile
//
REGISTER_REGISTER_SKILL_NODE(10263, 272) {
    pnode->resizeTrigger(PhaseNode_SpawnProjectile::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_SpawnProjectile::TRIGGER_DONE, 276, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10263, 272) {
    auto node272 = GET_SKILL_NODE(272, PhaseNode_SpawnProjectile);
    if (node272 == nullptr) {
        node272 = new PhaseNode_SpawnProjectile(272, phase);
        node272->setDataId(55263);
        node272->setPosZ(.00f);
        node272->setEndPosZ(.00f);
        node272->setMaxCount(0);
        CALL_REGISTER_SKILL_NODE(10263, 272, node272)
    }
    if (noInit == true) {
        return node272;
    }
    auto node18 = GET_SKILL_NODE(18, PhaseNode_OffsetCalculate);
    auto node278 = GET_SKILL_NODE(278, PhaseNode_GetInputLocation);
    if (node18 != nullptr) node272->setPosX(node18->getOutPosX());
    if (node18 != nullptr) node272->setPosY(node18->getOutPosY());
    if (node278 != nullptr) node272->setEndPosX(node278->getX());
    if (node278 != nullptr) node272->setEndPosY(node278->getY());
    if (node18 != nullptr) node272->setRotation(node18->getOutRotation());
    return node272;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(10263, 274) {
}

REGISTER_CREATE_SKILL_NODE(10263, 274) {
    auto node274 = GET_SKILL_NODE(274, PhaseNode_EndPhase);
    if (node274 == nullptr) {
        node274 = new PhaseNode_EndPhase(274, phase);
        node274->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node274->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10263, 274, node274)
    }
    if (noInit == true) {
        return node274;
    }
    return node274;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10263, 276) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_Delay::TRIGGER_DONE, 274, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(10263, 276) {
    auto node276 = GET_SKILL_NODE(276, PhaseNode_Delay);
    if (node276 == nullptr) {
        node276 = new PhaseNode_Delay(276, phase);
        node276->setTime(.56f);
        CALL_REGISTER_SKILL_NODE(10263, 276, node276)
    }
    if (noInit == true) {
        return node276;
    }
    return node276;
}
//--------------------------------------------------------------------------------
// GetInputLocation
//
REGISTER_REGISTER_SKILL_NODE(10263, 278) {
    pnode->resizeTrigger(PhaseNode_GetInputLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLineRotation>(PhaseNode_GetInputLocation::TRIGGER_DONE, 282, PhaseNode_GetLineRotation::FUNC_DO, &PhaseNode_GetLineRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(10263, 278) {
    auto node278 = GET_SKILL_NODE(278, PhaseNode_GetInputLocation);
    if (node278 == nullptr) {
        node278 = new PhaseNode_GetInputLocation(278, phase);
        node278->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        CALL_REGISTER_SKILL_NODE(10263, 278, node278)
    }
    if (noInit == true) {
        return node278;
    }
    return node278;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10263, 280) {
}

REGISTER_CREATE_SKILL_NODE(10263, 280) {
    auto node280 = GET_SKILL_NODE(280, PhaseNode_PlaySound);
    if (node280 == nullptr) {
        node280 = new PhaseNode_PlaySound(280, phase);
        node280->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node280->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node280->setSoundID("VO_Hero119_Skill_C");
        node280->setTarget(0U);
        node280->setUsePos(false);
        node280->setPosX(.00f);
        node280->setPosY(.00f);
        node280->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10263, 280, node280)
    }
    if (noInit == true) {
        return node280;
    }
    return node280;
}
//--------------------------------------------------------------------------------
// GetLineRotation
//
REGISTER_REGISTER_SKILL_NODE(10263, 282) {
    pnode->resizeTrigger(PhaseNode_GetLineRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_OffsetCalculate>(PhaseNode_GetLineRotation::TRIGGER_DONE, 18, PhaseNode_OffsetCalculate::FUNC_DO, &PhaseNode_OffsetCalculate::Do);
}

REGISTER_CREATE_SKILL_NODE(10263, 282) {
    auto node282 = GET_SKILL_NODE(282, PhaseNode_GetLineRotation);
    if (node282 == nullptr) {
        node282 = new PhaseNode_GetLineRotation(282, phase);
        CALL_REGISTER_SKILL_NODE(10263, 282, node282)
    }
    if (noInit == true) {
        return node282;
    }
    auto node23 = GET_SKILL_NODE(23, PhaseNode_GetLocation);
    auto node278 = GET_SKILL_NODE(278, PhaseNode_GetInputLocation);
    if (node23 != nullptr) node282->setStartX(node23->getX());
    if (node23 != nullptr) node282->setStartY(node23->getY());
    if (node278 != nullptr) node282->setEndX(node278->getX());
    if (node278 != nullptr) node282->setEndY(node278->getY());
    return node282;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10263, 284) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_IsInterruptType>(PhaseNode_Detect::TRIGGER_ON, 290, PhaseNode_IsInterruptType::FUNC_DO, &PhaseNode_IsInterruptType::Do);
}

REGISTER_CREATE_SKILL_NODE(10263, 284) {
    auto node284 = GET_SKILL_NODE(284, PhaseNode_Detect);
    if (node284 == nullptr) {
        node284 = new PhaseNode_Detect(284, phase);
        node284->setSelf(0U);
        node284->setEvent("daduan_001");
        node284->setType(PhaseNode_Detect::Detect_Type::Interrupt_Skill);
        node284->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10263, 284, node284)
    }
    if (noInit == true) {
        return node284;
    }
    return node284;
}
//--------------------------------------------------------------------------------
// SwitchToInt
//
REGISTER_REGISTER_SKILL_NODE(10263, 285) {
    pnode->resizeTrigger(4);
    pnode->regTrigger<PhaseNode_EndPhase>(1, 274, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(10263, 285) {
    auto node285 = GET_SKILL_NODE(285, PhaseNode_SwitchToInt);
    if (node285 == nullptr) {
        node285 = new PhaseNode_SwitchToInt(285, phase);
        CALL_REGISTER_SKILL_NODE(10263, 285, node285)
    }
    if (noInit == true) {
        return node285;
    }
    auto variables = node285->getVariables();
    if (variables != nullptr) {
        node285->setSelection(variables->getVariable<int32_t>(Variable_10263_102632));
    }
    return node285;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10263, 287) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_RaiseEvent::TRIGGER_DONE, 296, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10263, 287) {
    auto node287 = GET_SKILL_NODE(287, PhaseNode_RaiseEvent);
    if (node287 == nullptr) {
        node287 = new PhaseNode_RaiseEvent(287, phase);
        node287->setEvent("daduan_001");
        node287->setTarget(0U);
        node287->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node287->setTypeParams(0, 0);
        node287->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10263, 287, node287)
    }
    if (noInit == true) {
        return node287;
    }
    return node287;
}
//--------------------------------------------------------------------------------
// StartPreInput
//
REGISTER_REGISTER_SKILL_NODE(10263, 288) {
    pnode->resizeTrigger(PhaseNode_StartPreInput::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_StartPreInput::TRIGGER_DONE, 292, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10263, 288) {
    auto node288 = GET_SKILL_NODE(288, PhaseNode_StartPreInput);
    if (node288 == nullptr) {
        node288 = new PhaseNode_StartPreInput(288, phase);
        node288->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node288->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node288->setDelayTime(.00f);
        CALL_REGISTER_SKILL_NODE(10263, 288, node288)
    }
    if (noInit == true) {
        return node288;
    }
    return node288;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(10263, 289) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_If::TRIGGER_TRUE, 291, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10263, 289) {
    auto node289 = GET_SKILL_NODE(289, PhaseNode_If);
    if (node289 == nullptr) {
        node289 = new PhaseNode_If(289, phase);
        CALL_REGISTER_SKILL_NODE(10263, 289, node289)
    }
    if (noInit == true) {
        return node289;
    }
    auto variables = node289->getVariables();
    if (variables != nullptr) {
        node289->setCondition(variables->getVariable<bool>(Variable_10263_InterruptAnimat));
    }
    return node289;
}
//--------------------------------------------------------------------------------
// IsInterruptType
//
REGISTER_REGISTER_SKILL_NODE(10263, 290) {
    pnode->resizeTrigger(PhaseNode_IsInterruptType::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SwitchToInt>(PhaseNode_IsInterruptType::TRIGGER_BUFF, 285, PhaseNode_SwitchToInt::FUNC_SWITCH, &PhaseNode_SwitchToInt::Switch);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_POSCHANGE, 289, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTAIM, 289, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTFIRE, 289, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTRELOAD, 289, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_USESKILL, 289, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(10263, 290) {
    auto node290 = GET_SKILL_NODE(290, PhaseNode_IsInterruptType);
    if (node290 == nullptr) {
        node290 = new PhaseNode_IsInterruptType(290, phase);
        node290->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node290->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10263, 290, node290)
    }
    if (noInit == true) {
        return node290;
    }
    auto node284 = GET_SKILL_NODE(284, PhaseNode_Detect);
    if (node284 != nullptr) node290->setType(node284->getVars().getVariable<int32_t>(2));
    return node290;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10263, 291) {
}

REGISTER_CREATE_SKILL_NODE(10263, 291) {
    auto node291 = GET_SKILL_NODE(291, PhaseNode_PlayAnimation);
    if (node291 == nullptr) {
        node291 = new PhaseNode_PlayAnimation(291, phase);
        node291->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node291->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node291->setTarget(0U);
        node291->setAnimation("Idle");
        node291->setParameter("");
        node291->setValue(false);
        CALL_REGISTER_SKILL_NODE(10263, 291, node291)
    }
    if (noInit == true) {
        return node291;
    }
    return node291;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10263, 292) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_Delay::TRIGGER_DONE, 295, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(10263, 292) {
    auto node292 = GET_SKILL_NODE(292, PhaseNode_Delay);
    if (node292 == nullptr) {
        node292 = new PhaseNode_Delay(292, phase);
        node292->setTime(.20f);
        CALL_REGISTER_SKILL_NODE(10263, 292, node292)
    }
    if (noInit == true) {
        return node292;
    }
    return node292;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(10263, 295) {
}

REGISTER_CREATE_SKILL_NODE(10263, 295) {
    auto node295 = GET_SKILL_NODE(295, PhaseNode_SetBool);
    if (node295 == nullptr) {
        node295 = new PhaseNode_SetBool(295, phase);
        node295->setName("InterruptAnimat");
        node295->setValue(true);
        CALL_REGISTER_SKILL_NODE(10263, 295, node295)
    }
    if (noInit == true) {
        return node295;
    }
    return node295;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10263, 296) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StartPreInput>(PhaseNode_RaiseEvent::TRIGGER_DONE, 288, PhaseNode_StartPreInput::FUNC_DO, &PhaseNode_StartPreInput::Do);
}

REGISTER_CREATE_SKILL_NODE(10263, 296) {
    auto node296 = GET_SKILL_NODE(296, PhaseNode_RaiseEvent);
    if (node296 == nullptr) {
        node296 = new PhaseNode_RaiseEvent(296, phase);
        node296->setEvent("Dead_001");
        node296->setTarget(0U);
        node296->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node296->setTypeParams(0, 0);
        node296->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10263, 296, node296)
    }
    if (noInit == true) {
        return node296;
    }
    return node296;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10263, 297) {
}

REGISTER_CREATE_SKILL_NODE(10263, 297) {
    auto node297 = GET_SKILL_NODE(297, PhaseNode_Detect);
    if (node297 == nullptr) {
        node297 = new PhaseNode_Detect(297, phase);
        node297->setSelf(0U);
        node297->setEvent("Dead_001");
        node297->setType(PhaseNode_Detect::Detect_Type::Actor_Dead);
        node297->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10263, 297, node297)
    }
    if (noInit == true) {
        return node297;
    }
    return node297;
}

//--------------------------------------------------------------------------------
// SkillCreator_10263
//
class SkillCreator_10263 : public SkillCreator {
public:
    SkillCreator_10263() {}
    virtual ~SkillCreator_10263() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_10263

//--------------------------------------------------------------------------------
// SkillPhase_10263
//
class SkillPhase_10263 : public SkillPhase {
public:
    SkillPhase_10263(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_10263() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(10263, 2) // StartPhase
        CASE_CREATE_SKILL_NODE(10263, 4) // TriggerUpdate
        CASE_CREATE_SKILL_NODE(10263, 8) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10263, 10) // ResetCD
        CASE_CREATE_SKILL_NODE(10263, 12) // Disable
        CASE_CREATE_SKILL_NODE(10263, 18) // OffsetCalculate
        CASE_CREATE_SKILL_NODE(10263, 23) // GetLocation
        CASE_CREATE_SKILL_NODE(10263, 44) // Delay
        CASE_CREATE_SKILL_NODE(10263, 155) // PlayEffect
        CASE_CREATE_SKILL_NODE(10263, 272) // SpawnProjectile
        CASE_CREATE_SKILL_NODE(10263, 274) // EndPhase
        CASE_CREATE_SKILL_NODE(10263, 276) // Delay
        CASE_CREATE_SKILL_NODE(10263, 278) // GetInputLocation
        CASE_CREATE_SKILL_NODE(10263, 280) // PlaySound
        CASE_CREATE_SKILL_NODE(10263, 282) // GetLineRotation
        CASE_CREATE_SKILL_NODE(10263, 284) // Detect
        CASE_CREATE_SKILL_NODE(10263, 285) // SwitchToInt
        CASE_CREATE_SKILL_NODE(10263, 287) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10263, 288) // StartPreInput
        CASE_CREATE_SKILL_NODE(10263, 289) // If
        CASE_CREATE_SKILL_NODE(10263, 290) // IsInterruptType
        CASE_CREATE_SKILL_NODE(10263, 291) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10263, 292) // Delay
        CASE_CREATE_SKILL_NODE(10263, 295) // SetBool
        CASE_CREATE_SKILL_NODE(10263, 296) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10263, 297) // Detect
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_10263

SkillLogic* SkillCreator_10263::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //设置变量
    Variable_10263_102632 = logic->getVariables().setVariable<int32_t>("102632", 1);
    Variable_10263_InterruptAnimat = logic->getVariables().setVariable<bool>("InterruptAnimat");
    //创建阶段phase
    auto phase = new SkillPhase_10263(1, logic, 3);
    //设置phase执行器
    phase->setRunPhaseNode(1, 2);
    phase->setRunPhaseNode(2, 4);
    phase->setDetectPhaseNode(3, 284);
    phase->setDetectPhaseNode(3, 297);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_10263::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
