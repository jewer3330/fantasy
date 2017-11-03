#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

#include "skill_psnode_delay.h"
#include "skill_psnode_detect.h"
#include "skill_psnode_disable.h"
#include "skill_psnode_endphase.h"
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
#include "skill_psnode_setint.h"
#include "skill_psnode_spawnprojectile.h"
#include "skill_psnode_startphase.h"
#include "skill_psnode_startpreinput.h"
#include "skill_psnode_switchtoint.h"
#include "skill_psnode_triggerupdate.h"

namespace pvp {

//变量声明
uint64_t Variable_10261_a102612 = 0;
uint64_t Variable_10261_InterruptAnimat = 0;
//--------------------------------------------------------------------------------
// StartPhase
//
REGISTER_REGISTER_SKILL_NODE(10261, 2) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_StartPhase::TRIGGER_START, 6, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(10261, 2) {
    auto node2 = GET_SKILL_NODE(2, PhaseNode_StartPhase);
    if (node2 == nullptr) {
        node2 = new PhaseNode_StartPhase(2, phase);
        CALL_REGISTER_SKILL_NODE(10261, 2, node2)
    }
    if (noInit == true) {
        return node2;
    }
    return node2;
}
//--------------------------------------------------------------------------------
// TriggerUpdate
//
REGISTER_REGISTER_SKILL_NODE(10261, 4) {
}

REGISTER_CREATE_SKILL_NODE(10261, 4) {
    auto node4 = GET_SKILL_NODE(4, PhaseNode_TriggerUpdate);
    if (node4 == nullptr) {
        node4 = new PhaseNode_TriggerUpdate(4, phase);
        CALL_REGISTER_SKILL_NODE(10261, 4, node4)
    }
    if (noInit == true) {
        return node4;
    }
    return node4;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(10261, 6) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Disable>(PhaseNode_ResetCD::TRIGGER_DONE, 48, PhaseNode_Disable::FUNC_DO, &PhaseNode_Disable::Do);
}

REGISTER_CREATE_SKILL_NODE(10261, 6) {
    auto node6 = GET_SKILL_NODE(6, PhaseNode_ResetCD);
    if (node6 == nullptr) {
        node6 = new PhaseNode_ResetCD(6, phase);
        node6->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node6->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node6->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(10261, 6, node6)
    }
    if (noInit == true) {
        return node6;
    }
    return node6;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10261, 10) {
}

REGISTER_CREATE_SKILL_NODE(10261, 10) {
    auto node10 = GET_SKILL_NODE(10, PhaseNode_PlayAnimation);
    if (node10 == nullptr) {
        node10 = new PhaseNode_PlayAnimation(10, phase);
        node10->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node10->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node10->setTarget(0U);
        node10->setAnimation("Skill1S1");
        node10->setParameter("SkillArmBusy");
        node10->setValue(true);
        CALL_REGISTER_SKILL_NODE(10261, 10, node10)
    }
    if (noInit == true) {
        return node10;
    }
    return node10;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10261, 12) {
}

REGISTER_CREATE_SKILL_NODE(10261, 12) {
    auto node12 = GET_SKILL_NODE(12, PhaseNode_PlaySound);
    if (node12 == nullptr) {
        node12 = new PhaseNode_PlaySound(12, phase);
        node12->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node12->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node12->setSoundID("SE_Hero119_Skill_A_P1");
        node12->setTarget(0U);
        node12->setUsePos(false);
        node12->setPosX(.00f);
        node12->setPosY(.00f);
        node12->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10261, 12, node12)
    }
    if (noInit == true) {
        return node12;
    }
    return node12;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10261, 15) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_Delay::TRIGGER_DONE, 39, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_Delay::TRIGGER_DONE, 12, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
    pnode->regTrigger<PhaseNode_SetInt>(PhaseNode_Delay::TRIGGER_DONE, 182, PhaseNode_SetInt::FUNC_SET, &PhaseNode_SetInt::Set);
}

REGISTER_CREATE_SKILL_NODE(10261, 15) {
    auto node15 = GET_SKILL_NODE(15, PhaseNode_Delay);
    if (node15 == nullptr) {
        node15 = new PhaseNode_Delay(15, phase);
        node15->setTime(.20f);
        CALL_REGISTER_SKILL_NODE(10261, 15, node15)
    }
    if (noInit == true) {
        return node15;
    }
    return node15;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(10261, 39) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_OffsetCalculate>(PhaseNode_GetLocation::TRIGGER_DONE, 41, PhaseNode_OffsetCalculate::FUNC_DO, &PhaseNode_OffsetCalculate::Do);
}

REGISTER_CREATE_SKILL_NODE(10261, 39) {
    auto node39 = GET_SKILL_NODE(39, PhaseNode_GetLocation);
    if (node39 == nullptr) {
        node39 = new PhaseNode_GetLocation(39, phase);
        node39->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node39->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(10261, 39, node39)
    }
    if (noInit == true) {
        return node39;
    }
    return node39;
}
//--------------------------------------------------------------------------------
// OffsetCalculate
//
REGISTER_REGISTER_SKILL_NODE(10261, 41) {
    pnode->resizeTrigger(PhaseNode_OffsetCalculate::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 132, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
    pnode->regTrigger<PhaseNode_SpawnProjectile>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 193, PhaseNode_SpawnProjectile::FUNC_DO, &PhaseNode_SpawnProjectile::Do);
}

REGISTER_CREATE_SKILL_NODE(10261, 41) {
    auto node41 = GET_SKILL_NODE(41, PhaseNode_OffsetCalculate);
    if (node41 == nullptr) {
        node41 = new PhaseNode_OffsetCalculate(41, phase);
        node41->setPosZ(.00f);
        node41->setOffsetX(.20f);
        node41->setOffsetY(.80f);
        node41->setOffsetZ(.00f);
        node41->setRotOffset(.00f);
        CALL_REGISTER_SKILL_NODE(10261, 41, node41)
    }
    if (noInit == true) {
        return node41;
    }
    auto node39 = GET_SKILL_NODE(39, PhaseNode_GetLocation);
    auto node201 = GET_SKILL_NODE(201, PhaseNode_GetInputRotation);
    if (node39 != nullptr) node41->setPosX(node39->getX());
    if (node39 != nullptr) node41->setPosY(node39->getY());
    if (node201 != nullptr) node41->setRotation(node201->getAngle());
    return node41;
}
//--------------------------------------------------------------------------------
// Disable
//
REGISTER_REGISTER_SKILL_NODE(10261, 48) {
    pnode->resizeTrigger(PhaseNode_Disable::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetInputRotation>(PhaseNode_Disable::TRIGGER_DONE, 201, PhaseNode_GetInputRotation::FUNC_DO, &PhaseNode_GetInputRotation::Do);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_Disable::TRIGGER_DONE, 10, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_Disable::TRIGGER_DONE, 206, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10261, 48) {
    auto node48 = GET_SKILL_NODE(48, PhaseNode_Disable);
    if (node48 == nullptr) {
        node48 = new PhaseNode_Disable(48, phase);
        node48->setTarget(0U);
        node48->setMove(false);
        node48->setSkill(true);
        node48->setShoot(true);
        node48->setTime(.35f);
        node48->setRotate(true);
        CALL_REGISTER_SKILL_NODE(10261, 48, node48)
    }
    if (noInit == true) {
        return node48;
    }
    return node48;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(10261, 71) {
}

REGISTER_CREATE_SKILL_NODE(10261, 71) {
    auto node71 = GET_SKILL_NODE(71, PhaseNode_EndPhase);
    if (node71 == nullptr) {
        node71 = new PhaseNode_EndPhase(71, phase);
        node71->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node71->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10261, 71, node71)
    }
    if (noInit == true) {
        return node71;
    }
    return node71;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(10261, 132) {
}

REGISTER_CREATE_SKILL_NODE(10261, 132) {
    auto node132 = GET_SKILL_NODE(132, PhaseNode_PlayEffect);
    if (node132 == nullptr) {
        node132 = new PhaseNode_PlayEffect(132, phase);
        node132->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node132->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node132->setEffectID(102613);
        node132->setChangeColor(true);
        node132->setType(PhaseNode_PlayEffect::PlayEffect_Type::WithTarget);
        node132->getVars().reserve(5);
        node132->getVars().setVariable<uint64_t>(0, 0U);
        node132->getVars().setVariable<std::string>(1, "Effect");
        node132->getVars().setVariable<float>(2, .00f);
        node132->getVars().setVariable<float>(3, .00f);
        node132->getVars().setVariable<float>(4, .00f);
        node132->setRotation(.00f);
        node132->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(10261, 132, node132)
    }
    if (noInit == true) {
        return node132;
    }
    return node132;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10261, 138) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_Delay::TRIGGER_DONE, 71, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(10261, 138) {
    auto node138 = GET_SKILL_NODE(138, PhaseNode_Delay);
    if (node138 == nullptr) {
        node138 = new PhaseNode_Delay(138, phase);
        node138->setTime(.50f);
        CALL_REGISTER_SKILL_NODE(10261, 138, node138)
    }
    if (noInit == true) {
        return node138;
    }
    return node138;
}
//--------------------------------------------------------------------------------
// SetInt
//
REGISTER_REGISTER_SKILL_NODE(10261, 182) {
}

REGISTER_CREATE_SKILL_NODE(10261, 182) {
    auto node182 = GET_SKILL_NODE(182, PhaseNode_SetInt);
    if (node182 == nullptr) {
        node182 = new PhaseNode_SetInt(182, phase);
        node182->setName("a102612");
        node182->setValue(2);
        CALL_REGISTER_SKILL_NODE(10261, 182, node182)
    }
    if (noInit == true) {
        return node182;
    }
    return node182;
}
//--------------------------------------------------------------------------------
// SpawnProjectile
//
REGISTER_REGISTER_SKILL_NODE(10261, 193) {
    pnode->resizeTrigger(PhaseNode_SpawnProjectile::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_SpawnProjectile::TRIGGER_DONE, 138, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10261, 193) {
    auto node193 = GET_SKILL_NODE(193, PhaseNode_SpawnProjectile);
    if (node193 == nullptr) {
        node193 = new PhaseNode_SpawnProjectile(193, phase);
        node193->setDataId(55261);
        node193->setEndPosX(.00f);
        node193->setEndPosY(.00f);
        node193->setEndPosZ(.00f);
        node193->setMaxCount(0);
        CALL_REGISTER_SKILL_NODE(10261, 193, node193)
    }
    if (noInit == true) {
        return node193;
    }
    auto node41 = GET_SKILL_NODE(41, PhaseNode_OffsetCalculate);
    auto node201 = GET_SKILL_NODE(201, PhaseNode_GetInputRotation);
    if (node41 != nullptr) node193->setPosX(node41->getOutPosX());
    if (node41 != nullptr) node193->setPosY(node41->getOutPosY());
    if (node41 != nullptr) node193->setPosZ(node41->getOutPosZ());
    if (node201 != nullptr) node193->setRotation(node201->getAngle());
    return node193;
}
//--------------------------------------------------------------------------------
// GetInputRotation
//
REGISTER_REGISTER_SKILL_NODE(10261, 201) {
    pnode->resizeTrigger(PhaseNode_GetInputRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_GetInputRotation::TRIGGER_DONE, 15, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10261, 201) {
    auto node201 = GET_SKILL_NODE(201, PhaseNode_GetInputRotation);
    if (node201 == nullptr) {
        node201 = new PhaseNode_GetInputRotation(201, phase);
        node201->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        CALL_REGISTER_SKILL_NODE(10261, 201, node201)
    }
    if (noInit == true) {
        return node201;
    }
    return node201;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10261, 203) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_IsInterruptType>(PhaseNode_Detect::TRIGGER_ON, 209, PhaseNode_IsInterruptType::FUNC_DO, &PhaseNode_IsInterruptType::Do);
}

REGISTER_CREATE_SKILL_NODE(10261, 203) {
    auto node203 = GET_SKILL_NODE(203, PhaseNode_Detect);
    if (node203 == nullptr) {
        node203 = new PhaseNode_Detect(203, phase);
        node203->setSelf(0U);
        node203->setEvent("daduan_001");
        node203->setType(PhaseNode_Detect::Detect_Type::Interrupt_Skill);
        node203->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10261, 203, node203)
    }
    if (noInit == true) {
        return node203;
    }
    return node203;
}
//--------------------------------------------------------------------------------
// SwitchToInt
//
REGISTER_REGISTER_SKILL_NODE(10261, 204) {
    pnode->resizeTrigger(4);
    pnode->regTrigger<PhaseNode_EndPhase>(1, 71, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(10261, 204) {
    auto node204 = GET_SKILL_NODE(204, PhaseNode_SwitchToInt);
    if (node204 == nullptr) {
        node204 = new PhaseNode_SwitchToInt(204, phase);
        CALL_REGISTER_SKILL_NODE(10261, 204, node204)
    }
    if (noInit == true) {
        return node204;
    }
    auto variables = node204->getVariables();
    if (variables != nullptr) {
        node204->setSelection(variables->getVariable<int32_t>(Variable_10261_a102612));
    }
    return node204;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10261, 206) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_RaiseEvent::TRIGGER_DONE, 215, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10261, 206) {
    auto node206 = GET_SKILL_NODE(206, PhaseNode_RaiseEvent);
    if (node206 == nullptr) {
        node206 = new PhaseNode_RaiseEvent(206, phase);
        node206->setEvent("daduan_001");
        node206->setTarget(0U);
        node206->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node206->setTypeParams(0, 0);
        node206->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10261, 206, node206)
    }
    if (noInit == true) {
        return node206;
    }
    return node206;
}
//--------------------------------------------------------------------------------
// StartPreInput
//
REGISTER_REGISTER_SKILL_NODE(10261, 207) {
    pnode->resizeTrigger(PhaseNode_StartPreInput::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_StartPreInput::TRIGGER_DONE, 211, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10261, 207) {
    auto node207 = GET_SKILL_NODE(207, PhaseNode_StartPreInput);
    if (node207 == nullptr) {
        node207 = new PhaseNode_StartPreInput(207, phase);
        node207->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node207->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node207->setDelayTime(.00f);
        CALL_REGISTER_SKILL_NODE(10261, 207, node207)
    }
    if (noInit == true) {
        return node207;
    }
    return node207;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(10261, 208) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_If::TRIGGER_TRUE, 210, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10261, 208) {
    auto node208 = GET_SKILL_NODE(208, PhaseNode_If);
    if (node208 == nullptr) {
        node208 = new PhaseNode_If(208, phase);
        CALL_REGISTER_SKILL_NODE(10261, 208, node208)
    }
    if (noInit == true) {
        return node208;
    }
    auto variables = node208->getVariables();
    if (variables != nullptr) {
        node208->setCondition(variables->getVariable<bool>(Variable_10261_InterruptAnimat));
    }
    return node208;
}
//--------------------------------------------------------------------------------
// IsInterruptType
//
REGISTER_REGISTER_SKILL_NODE(10261, 209) {
    pnode->resizeTrigger(PhaseNode_IsInterruptType::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SwitchToInt>(PhaseNode_IsInterruptType::TRIGGER_BUFF, 204, PhaseNode_SwitchToInt::FUNC_SWITCH, &PhaseNode_SwitchToInt::Switch);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_POSCHANGE, 208, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTAIM, 208, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTFIRE, 208, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTRELOAD, 208, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_USESKILL, 208, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(10261, 209) {
    auto node209 = GET_SKILL_NODE(209, PhaseNode_IsInterruptType);
    if (node209 == nullptr) {
        node209 = new PhaseNode_IsInterruptType(209, phase);
        node209->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node209->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10261, 209, node209)
    }
    if (noInit == true) {
        return node209;
    }
    auto node203 = GET_SKILL_NODE(203, PhaseNode_Detect);
    if (node203 != nullptr) node209->setType(node203->getVars().getVariable<int32_t>(2));
    return node209;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10261, 210) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_PlayAnimation::TRIGGER_DONE, 71, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(10261, 210) {
    auto node210 = GET_SKILL_NODE(210, PhaseNode_PlayAnimation);
    if (node210 == nullptr) {
        node210 = new PhaseNode_PlayAnimation(210, phase);
        node210->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node210->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node210->setTarget(0U);
        node210->setAnimation("Idle");
        node210->setParameter("");
        node210->setValue(false);
        CALL_REGISTER_SKILL_NODE(10261, 210, node210)
    }
    if (noInit == true) {
        return node210;
    }
    return node210;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10261, 211) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_Delay::TRIGGER_DONE, 214, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(10261, 211) {
    auto node211 = GET_SKILL_NODE(211, PhaseNode_Delay);
    if (node211 == nullptr) {
        node211 = new PhaseNode_Delay(211, phase);
        node211->setTime(.35f);
        CALL_REGISTER_SKILL_NODE(10261, 211, node211)
    }
    if (noInit == true) {
        return node211;
    }
    return node211;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(10261, 214) {
}

REGISTER_CREATE_SKILL_NODE(10261, 214) {
    auto node214 = GET_SKILL_NODE(214, PhaseNode_SetBool);
    if (node214 == nullptr) {
        node214 = new PhaseNode_SetBool(214, phase);
        node214->setName("InterruptAnimat");
        node214->setValue(true);
        CALL_REGISTER_SKILL_NODE(10261, 214, node214)
    }
    if (noInit == true) {
        return node214;
    }
    return node214;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10261, 215) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StartPreInput>(PhaseNode_RaiseEvent::TRIGGER_DONE, 207, PhaseNode_StartPreInput::FUNC_DO, &PhaseNode_StartPreInput::Do);
}

REGISTER_CREATE_SKILL_NODE(10261, 215) {
    auto node215 = GET_SKILL_NODE(215, PhaseNode_RaiseEvent);
    if (node215 == nullptr) {
        node215 = new PhaseNode_RaiseEvent(215, phase);
        node215->setEvent("Dead_001");
        node215->setTarget(0U);
        node215->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node215->setTypeParams(0, 0);
        node215->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10261, 215, node215)
    }
    if (noInit == true) {
        return node215;
    }
    return node215;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10261, 216) {
}

REGISTER_CREATE_SKILL_NODE(10261, 216) {
    auto node216 = GET_SKILL_NODE(216, PhaseNode_Detect);
    if (node216 == nullptr) {
        node216 = new PhaseNode_Detect(216, phase);
        node216->setSelf(0U);
        node216->setEvent("Dead_001");
        node216->setType(PhaseNode_Detect::Detect_Type::Actor_Dead);
        node216->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10261, 216, node216)
    }
    if (noInit == true) {
        return node216;
    }
    return node216;
}

//--------------------------------------------------------------------------------
// SkillCreator_10261
//
class SkillCreator_10261 : public SkillCreator {
public:
    SkillCreator_10261() {}
    virtual ~SkillCreator_10261() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_10261

//--------------------------------------------------------------------------------
// SkillPhase_10261
//
class SkillPhase_10261 : public SkillPhase {
public:
    SkillPhase_10261(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_10261() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(10261, 2) // StartPhase
        CASE_CREATE_SKILL_NODE(10261, 4) // TriggerUpdate
        CASE_CREATE_SKILL_NODE(10261, 6) // ResetCD
        CASE_CREATE_SKILL_NODE(10261, 10) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10261, 12) // PlaySound
        CASE_CREATE_SKILL_NODE(10261, 15) // Delay
        CASE_CREATE_SKILL_NODE(10261, 39) // GetLocation
        CASE_CREATE_SKILL_NODE(10261, 41) // OffsetCalculate
        CASE_CREATE_SKILL_NODE(10261, 48) // Disable
        CASE_CREATE_SKILL_NODE(10261, 71) // EndPhase
        CASE_CREATE_SKILL_NODE(10261, 132) // PlayEffect
        CASE_CREATE_SKILL_NODE(10261, 138) // Delay
        CASE_CREATE_SKILL_NODE(10261, 182) // SetInt
        CASE_CREATE_SKILL_NODE(10261, 193) // SpawnProjectile
        CASE_CREATE_SKILL_NODE(10261, 201) // GetInputRotation
        CASE_CREATE_SKILL_NODE(10261, 203) // Detect
        CASE_CREATE_SKILL_NODE(10261, 204) // SwitchToInt
        CASE_CREATE_SKILL_NODE(10261, 206) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10261, 207) // StartPreInput
        CASE_CREATE_SKILL_NODE(10261, 208) // If
        CASE_CREATE_SKILL_NODE(10261, 209) // IsInterruptType
        CASE_CREATE_SKILL_NODE(10261, 210) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10261, 211) // Delay
        CASE_CREATE_SKILL_NODE(10261, 214) // SetBool
        CASE_CREATE_SKILL_NODE(10261, 215) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10261, 216) // Detect
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_10261

SkillLogic* SkillCreator_10261::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //设置变量
    Variable_10261_a102612 = logic->getVariables().setVariable<int32_t>("a102612", 1);
    Variable_10261_InterruptAnimat = logic->getVariables().setVariable<bool>("InterruptAnimat");
    //创建阶段phase
    auto phase = new SkillPhase_10261(1, logic, 3);
    //设置phase执行器
    phase->setRunPhaseNode(1, 2);
    phase->setRunPhaseNode(2, 4);
    phase->setDetectPhaseNode(3, 203);
    phase->setDetectPhaseNode(3, 216);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_10261::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
