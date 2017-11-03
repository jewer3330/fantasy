#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

#include "skill_psnode_addskillbuff.h"
#include "skill_psnode_delay.h"
#include "skill_psnode_detect.h"
#include "skill_psnode_disable.h"
#include "skill_psnode_endphase.h"
#include "skill_psnode_getactorattribute.h"
#include "skill_psnode_getinputlocation.h"
#include "skill_psnode_getinputrotation.h"
#include "skill_psnode_if.h"
#include "skill_psnode_isinterrupttype.h"
#include "skill_psnode_playanimation.h"
#include "skill_psnode_playeffect.h"
#include "skill_psnode_playsound.h"
#include "skill_psnode_raiseevent.h"
#include "skill_psnode_removeskillbuff.h"
#include "skill_psnode_resetcd.h"
#include "skill_psnode_setbool.h"
#include "skill_psnode_spawnactor.h"
#include "skill_psnode_startphase.h"
#include "skill_psnode_startpreinput.h"
#include "skill_psnode_switchtoint.h"

namespace pvp {

//变量声明
uint64_t Variable_10101_101012 = 0;
uint64_t Variable_10101_InterruptAnimat = 0;
//--------------------------------------------------------------------------------
// StartPhase
//
REGISTER_REGISTER_SKILL_NODE(10101, 1) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_StartPhase::TRIGGER_START, 183, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(10101, 1) {
    auto node1 = GET_SKILL_NODE(1, PhaseNode_StartPhase);
    if (node1 == nullptr) {
        node1 = new PhaseNode_StartPhase(1, phase);
        CALL_REGISTER_SKILL_NODE(10101, 1, node1)
    }
    if (noInit == true) {
        return node1;
    }
    return node1;
}
//--------------------------------------------------------------------------------
// SpawnActor
//
REGISTER_REGISTER_SKILL_NODE(10101, 5) {
    pnode->resizeTrigger(PhaseNode_SpawnActor::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_SpawnActor::TRIGGER_DONE, 85, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10101, 5) {
    auto node5 = GET_SKILL_NODE(5, PhaseNode_SpawnActor);
    if (node5 == nullptr) {
        node5 = new PhaseNode_SpawnActor(5, phase);
        node5->setConfigID(4011);
        node5->setTime(.00f);
        node5->setPosZ(.00f);
        node5->setLevel(1);
        node5->setMaxCount(1);
        CALL_REGISTER_SKILL_NODE(10101, 5, node5)
    }
    if (noInit == true) {
        return node5;
    }
    auto node158 = GET_SKILL_NODE(158, PhaseNode_GetInputLocation);
    auto node167 = GET_SKILL_NODE(167, PhaseNode_GetInputRotation);
    if (node158 != nullptr) node5->setPosX(node158->getX());
    if (node158 != nullptr) node5->setPosY(node158->getY());
    if (node167 != nullptr) node5->setRotation(node167->getAngle());
    return node5;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(10101, 6) {
}

REGISTER_CREATE_SKILL_NODE(10101, 6) {
    auto node6 = GET_SKILL_NODE(6, PhaseNode_EndPhase);
    if (node6 == nullptr) {
        node6 = new PhaseNode_EndPhase(6, phase);
        node6->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node6->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10101, 6, node6)
    }
    if (noInit == true) {
        return node6;
    }
    return node6;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10101, 85) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuff>(PhaseNode_Delay::TRIGGER_DONE, 182, PhaseNode_AddSkillBuff::FUNC_ADD, &PhaseNode_AddSkillBuff::Add);
}

REGISTER_CREATE_SKILL_NODE(10101, 85) {
    auto node85 = GET_SKILL_NODE(85, PhaseNode_Delay);
    if (node85 == nullptr) {
        node85 = new PhaseNode_Delay(85, phase);
        node85->setTime(.67f);
        CALL_REGISTER_SKILL_NODE(10101, 85, node85)
    }
    if (noInit == true) {
        return node85;
    }
    return node85;
}
//--------------------------------------------------------------------------------
// Disable
//
REGISTER_REGISTER_SKILL_NODE(10101, 94) {
    pnode->resizeTrigger(PhaseNode_Disable::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RemoveSkillBuff>(PhaseNode_Disable::TRIGGER_DONE, 179, PhaseNode_RemoveSkillBuff::FUNC_REMOVE, &PhaseNode_RemoveSkillBuff::Remove);
}

REGISTER_CREATE_SKILL_NODE(10101, 94) {
    auto node94 = GET_SKILL_NODE(94, PhaseNode_Disable);
    if (node94 == nullptr) {
        node94 = new PhaseNode_Disable(94, phase);
        node94->setTarget(0U);
        node94->setMove(true);
        node94->setSkill(true);
        node94->setShoot(true);
        node94->setTime(.45f);
        node94->setRotate(true);
        CALL_REGISTER_SKILL_NODE(10101, 94, node94)
    }
    if (noInit == true) {
        return node94;
    }
    return node94;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10101, 100) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnActor>(PhaseNode_Delay::TRIGGER_DONE, 5, PhaseNode_SpawnActor::FUNC_DO, &PhaseNode_SpawnActor::Do);
}

REGISTER_CREATE_SKILL_NODE(10101, 100) {
    auto node100 = GET_SKILL_NODE(100, PhaseNode_Delay);
    if (node100 == nullptr) {
        node100 = new PhaseNode_Delay(100, phase);
        node100->setTime(.23f);
        CALL_REGISTER_SKILL_NODE(10101, 100, node100)
    }
    if (noInit == true) {
        return node100;
    }
    return node100;
}
//--------------------------------------------------------------------------------
// GetInputLocation
//
REGISTER_REGISTER_SKILL_NODE(10101, 158) {
    pnode->resizeTrigger(PhaseNode_GetInputLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Disable>(PhaseNode_GetInputLocation::TRIGGER_DONE, 94, PhaseNode_Disable::FUNC_DO, &PhaseNode_Disable::Do);
}

REGISTER_CREATE_SKILL_NODE(10101, 158) {
    auto node158 = GET_SKILL_NODE(158, PhaseNode_GetInputLocation);
    if (node158 == nullptr) {
        node158 = new PhaseNode_GetInputLocation(158, phase);
        node158->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        CALL_REGISTER_SKILL_NODE(10101, 158, node158)
    }
    if (noInit == true) {
        return node158;
    }
    return node158;
}
//--------------------------------------------------------------------------------
// GetInputRotation
//
REGISTER_REGISTER_SKILL_NODE(10101, 167) {
    pnode->resizeTrigger(PhaseNode_GetInputRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetInputLocation>(PhaseNode_GetInputRotation::TRIGGER_DONE, 158, PhaseNode_GetInputLocation::FUNC_DO, &PhaseNode_GetInputLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(10101, 167) {
    auto node167 = GET_SKILL_NODE(167, PhaseNode_GetInputRotation);
    if (node167 == nullptr) {
        node167 = new PhaseNode_GetInputRotation(167, phase);
        node167->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        CALL_REGISTER_SKILL_NODE(10101, 167, node167)
    }
    if (noInit == true) {
        return node167;
    }
    return node167;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(10101, 169) {
}

REGISTER_CREATE_SKILL_NODE(10101, 169) {
    auto node169 = GET_SKILL_NODE(169, PhaseNode_PlayEffect);
    if (node169 == nullptr) {
        node169 = new PhaseNode_PlayEffect(169, phase);
        node169->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node169->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node169->setEffectID(101027);
        node169->setChangeColor(true);
        node169->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node169->getVars().reserve(3);
        node169->getVars().setVariable<float>(0, .00f);
        node169->getVars().setVariable<float>(1, .00f);
        node169->getVars().setVariable<float>(2, .00f);
        node169->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(10101, 169, node169)
    }
    if (noInit == true) {
        return node169;
    }
    auto node158 = GET_SKILL_NODE(158, PhaseNode_GetInputLocation);
    auto node167 = GET_SKILL_NODE(167, PhaseNode_GetInputRotation);
    if (node158 != nullptr) node169->getVars().setVariable<float>(0, node158->getX());
    if (node158 != nullptr) node169->getVars().setVariable<float>(1, node158->getY());
    if (node167 != nullptr) node169->setRotation(node167->getAngle());
    return node169;
}
//--------------------------------------------------------------------------------
// RemoveSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10101, 179) {
    pnode->resizeTrigger(PhaseNode_RemoveSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_RemoveSkillBuff::TRIGGER_DONE, 100, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_RemoveSkillBuff::TRIGGER_DONE, 169, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(10101, 179) {
    auto node179 = GET_SKILL_NODE(179, PhaseNode_RemoveSkillBuff);
    if (node179 == nullptr) {
        node179 = new PhaseNode_RemoveSkillBuff(179, phase);
        node179->setBuffID(0U);
        node179->setBuffIDs({});
        node179->setConfigID(101041);
        node179->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(10101, 179, node179)
    }
    if (noInit == true) {
        return node179;
    }
    return node179;
}
//--------------------------------------------------------------------------------
// AddSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10101, 182) {
    pnode->resizeTrigger(PhaseNode_AddSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_AddSkillBuff::TRIGGER_DONE, 6, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(10101, 182) {
    auto node182 = GET_SKILL_NODE(182, PhaseNode_AddSkillBuff);
    if (node182 == nullptr) {
        node182 = new PhaseNode_AddSkillBuff(182, phase);
        node182->setConfigID(101041);
        node182->setConfigIDs({});
        node182->setTarget(0U);
        node182->setAttribute({{}});
        CALL_REGISTER_SKILL_NODE(10101, 182, node182)
    }
    if (noInit == true) {
        return node182;
    }
    return node182;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(10101, 183) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_ResetCD::TRIGGER_DONE, 184, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10101, 183) {
    auto node183 = GET_SKILL_NODE(183, PhaseNode_ResetCD);
    if (node183 == nullptr) {
        node183 = new PhaseNode_ResetCD(183, phase);
        node183->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node183->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node183->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(10101, 183, node183)
    }
    if (noInit == true) {
        return node183;
    }
    return node183;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10101, 184) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_PlayAnimation::TRIGGER_DONE, 186, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(10101, 184) {
    auto node184 = GET_SKILL_NODE(184, PhaseNode_PlayAnimation);
    if (node184 == nullptr) {
        node184 = new PhaseNode_PlayAnimation(184, phase);
        node184->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node184->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node184->setTarget(0U);
        node184->setAnimation("Skill1S1");
        node184->setParameter("");
        node184->setValue(false);
        CALL_REGISTER_SKILL_NODE(10101, 184, node184)
    }
    if (noInit == true) {
        return node184;
    }
    return node184;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10101, 185) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetInputRotation>(PhaseNode_PlaySound::TRIGGER_DONE, 167, PhaseNode_GetInputRotation::FUNC_DO, &PhaseNode_GetInputRotation::Do);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_PlaySound::TRIGGER_DONE, 191, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10101, 185) {
    auto node185 = GET_SKILL_NODE(185, PhaseNode_PlaySound);
    if (node185 == nullptr) {
        node185 = new PhaseNode_PlaySound(185, phase);
        node185->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node185->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node185->setSoundID("VO_Hero103_Skill_A");
        node185->setTarget(0U);
        node185->setUsePos(false);
        node185->setPosX(.00f);
        node185->setPosY(.00f);
        node185->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10101, 185, node185)
    }
    if (noInit == true) {
        return node185;
    }
    return node185;
}
//--------------------------------------------------------------------------------
// GetActorAttribute
//
REGISTER_REGISTER_SKILL_NODE(10101, 186) {
    pnode->resizeTrigger(PhaseNode_GetActorAttribute::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 185, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10101, 186) {
    auto node186 = GET_SKILL_NODE(186, PhaseNode_GetActorAttribute);
    if (node186 == nullptr) {
        node186 = new PhaseNode_GetActorAttribute(186, phase);
        node186->setTarget(0U);
        node186->setType({});
        CALL_REGISTER_SKILL_NODE(10101, 186, node186)
    }
    if (noInit == true) {
        return node186;
    }
    return node186;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10101, 188) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_IsInterruptType>(PhaseNode_Detect::TRIGGER_ON, 194, PhaseNode_IsInterruptType::FUNC_DO, &PhaseNode_IsInterruptType::Do);
}

REGISTER_CREATE_SKILL_NODE(10101, 188) {
    auto node188 = GET_SKILL_NODE(188, PhaseNode_Detect);
    if (node188 == nullptr) {
        node188 = new PhaseNode_Detect(188, phase);
        node188->setSelf(0U);
        node188->setEvent("daduan_001");
        node188->setType(PhaseNode_Detect::Detect_Type::Interrupt_Skill);
        node188->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10101, 188, node188)
    }
    if (noInit == true) {
        return node188;
    }
    return node188;
}
//--------------------------------------------------------------------------------
// SwitchToInt
//
REGISTER_REGISTER_SKILL_NODE(10101, 189) {
    pnode->resizeTrigger(4);
    pnode->regTrigger<PhaseNode_AddSkillBuff>(1, 182, PhaseNode_AddSkillBuff::FUNC_ADD, &PhaseNode_AddSkillBuff::Add);
}

REGISTER_CREATE_SKILL_NODE(10101, 189) {
    auto node189 = GET_SKILL_NODE(189, PhaseNode_SwitchToInt);
    if (node189 == nullptr) {
        node189 = new PhaseNode_SwitchToInt(189, phase);
        CALL_REGISTER_SKILL_NODE(10101, 189, node189)
    }
    if (noInit == true) {
        return node189;
    }
    auto variables = node189->getVariables();
    if (variables != nullptr) {
        node189->setSelection(variables->getVariable<int32_t>(Variable_10101_101012));
    }
    return node189;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10101, 191) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_RaiseEvent::TRIGGER_DONE, 200, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10101, 191) {
    auto node191 = GET_SKILL_NODE(191, PhaseNode_RaiseEvent);
    if (node191 == nullptr) {
        node191 = new PhaseNode_RaiseEvent(191, phase);
        node191->setEvent("daduan_001");
        node191->setTarget(0U);
        node191->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node191->setTypeParams(0, 0);
        node191->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10101, 191, node191)
    }
    if (noInit == true) {
        return node191;
    }
    return node191;
}
//--------------------------------------------------------------------------------
// StartPreInput
//
REGISTER_REGISTER_SKILL_NODE(10101, 192) {
    pnode->resizeTrigger(PhaseNode_StartPreInput::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_StartPreInput::TRIGGER_DONE, 196, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10101, 192) {
    auto node192 = GET_SKILL_NODE(192, PhaseNode_StartPreInput);
    if (node192 == nullptr) {
        node192 = new PhaseNode_StartPreInput(192, phase);
        node192->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node192->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node192->setDelayTime(.00f);
        CALL_REGISTER_SKILL_NODE(10101, 192, node192)
    }
    if (noInit == true) {
        return node192;
    }
    return node192;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(10101, 193) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_If::TRIGGER_TRUE, 195, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10101, 193) {
    auto node193 = GET_SKILL_NODE(193, PhaseNode_If);
    if (node193 == nullptr) {
        node193 = new PhaseNode_If(193, phase);
        CALL_REGISTER_SKILL_NODE(10101, 193, node193)
    }
    if (noInit == true) {
        return node193;
    }
    auto variables = node193->getVariables();
    if (variables != nullptr) {
        node193->setCondition(variables->getVariable<bool>(Variable_10101_InterruptAnimat));
    }
    return node193;
}
//--------------------------------------------------------------------------------
// IsInterruptType
//
REGISTER_REGISTER_SKILL_NODE(10101, 194) {
    pnode->resizeTrigger(PhaseNode_IsInterruptType::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SwitchToInt>(PhaseNode_IsInterruptType::TRIGGER_BUFF, 189, PhaseNode_SwitchToInt::FUNC_SWITCH, &PhaseNode_SwitchToInt::Switch);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_POSCHANGE, 193, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTAIM, 193, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTFIRE, 193, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTRELOAD, 193, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_USESKILL, 193, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(10101, 194) {
    auto node194 = GET_SKILL_NODE(194, PhaseNode_IsInterruptType);
    if (node194 == nullptr) {
        node194 = new PhaseNode_IsInterruptType(194, phase);
        node194->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node194->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10101, 194, node194)
    }
    if (noInit == true) {
        return node194;
    }
    auto node188 = GET_SKILL_NODE(188, PhaseNode_Detect);
    if (node188 != nullptr) node194->setType(node188->getVars().getVariable<int32_t>(2));
    return node194;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10101, 195) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuff>(PhaseNode_PlayAnimation::TRIGGER_DONE, 182, PhaseNode_AddSkillBuff::FUNC_ADD, &PhaseNode_AddSkillBuff::Add);
}

REGISTER_CREATE_SKILL_NODE(10101, 195) {
    auto node195 = GET_SKILL_NODE(195, PhaseNode_PlayAnimation);
    if (node195 == nullptr) {
        node195 = new PhaseNode_PlayAnimation(195, phase);
        node195->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node195->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node195->setTarget(0U);
        node195->setAnimation("Idle");
        node195->setParameter("");
        node195->setValue(false);
        CALL_REGISTER_SKILL_NODE(10101, 195, node195)
    }
    if (noInit == true) {
        return node195;
    }
    return node195;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10101, 196) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_Delay::TRIGGER_DONE, 199, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(10101, 196) {
    auto node196 = GET_SKILL_NODE(196, PhaseNode_Delay);
    if (node196 == nullptr) {
        node196 = new PhaseNode_Delay(196, phase);
        node196->setTime(.20f);
        CALL_REGISTER_SKILL_NODE(10101, 196, node196)
    }
    if (noInit == true) {
        return node196;
    }
    return node196;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(10101, 199) {
}

REGISTER_CREATE_SKILL_NODE(10101, 199) {
    auto node199 = GET_SKILL_NODE(199, PhaseNode_SetBool);
    if (node199 == nullptr) {
        node199 = new PhaseNode_SetBool(199, phase);
        node199->setName("InterruptAnimat");
        node199->setValue(true);
        CALL_REGISTER_SKILL_NODE(10101, 199, node199)
    }
    if (noInit == true) {
        return node199;
    }
    return node199;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10101, 200) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StartPreInput>(PhaseNode_RaiseEvent::TRIGGER_DONE, 192, PhaseNode_StartPreInput::FUNC_DO, &PhaseNode_StartPreInput::Do);
}

REGISTER_CREATE_SKILL_NODE(10101, 200) {
    auto node200 = GET_SKILL_NODE(200, PhaseNode_RaiseEvent);
    if (node200 == nullptr) {
        node200 = new PhaseNode_RaiseEvent(200, phase);
        node200->setEvent("Dead_001");
        node200->setTarget(0U);
        node200->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node200->setTypeParams(0, 0);
        node200->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10101, 200, node200)
    }
    if (noInit == true) {
        return node200;
    }
    return node200;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10101, 201) {
}

REGISTER_CREATE_SKILL_NODE(10101, 201) {
    auto node201 = GET_SKILL_NODE(201, PhaseNode_Detect);
    if (node201 == nullptr) {
        node201 = new PhaseNode_Detect(201, phase);
        node201->setSelf(0U);
        node201->setEvent("Dead_001");
        node201->setType(PhaseNode_Detect::Detect_Type::Actor_Dead);
        node201->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10101, 201, node201)
    }
    if (noInit == true) {
        return node201;
    }
    return node201;
}

//--------------------------------------------------------------------------------
// SkillCreator_10101
//
class SkillCreator_10101 : public SkillCreator {
public:
    SkillCreator_10101() {}
    virtual ~SkillCreator_10101() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_10101

//--------------------------------------------------------------------------------
// SkillPhase_10101
//
class SkillPhase_10101 : public SkillPhase {
public:
    SkillPhase_10101(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_10101() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(10101, 1) // StartPhase
        CASE_CREATE_SKILL_NODE(10101, 5) // SpawnActor
        CASE_CREATE_SKILL_NODE(10101, 6) // EndPhase
        CASE_CREATE_SKILL_NODE(10101, 85) // Delay
        CASE_CREATE_SKILL_NODE(10101, 94) // Disable
        CASE_CREATE_SKILL_NODE(10101, 100) // Delay
        CASE_CREATE_SKILL_NODE(10101, 158) // GetInputLocation
        CASE_CREATE_SKILL_NODE(10101, 167) // GetInputRotation
        CASE_CREATE_SKILL_NODE(10101, 169) // PlayEffect
        CASE_CREATE_SKILL_NODE(10101, 179) // RemoveSkillBuff
        CASE_CREATE_SKILL_NODE(10101, 182) // AddSkillBuff
        CASE_CREATE_SKILL_NODE(10101, 183) // ResetCD
        CASE_CREATE_SKILL_NODE(10101, 184) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10101, 185) // PlaySound
        CASE_CREATE_SKILL_NODE(10101, 186) // GetActorAttribute
        CASE_CREATE_SKILL_NODE(10101, 188) // Detect
        CASE_CREATE_SKILL_NODE(10101, 189) // SwitchToInt
        CASE_CREATE_SKILL_NODE(10101, 191) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10101, 192) // StartPreInput
        CASE_CREATE_SKILL_NODE(10101, 193) // If
        CASE_CREATE_SKILL_NODE(10101, 194) // IsInterruptType
        CASE_CREATE_SKILL_NODE(10101, 195) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10101, 196) // Delay
        CASE_CREATE_SKILL_NODE(10101, 199) // SetBool
        CASE_CREATE_SKILL_NODE(10101, 200) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10101, 201) // Detect
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_10101

SkillLogic* SkillCreator_10101::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //设置变量
    Variable_10101_101012 = logic->getVariables().setVariable<int32_t>("101012", 1);
    Variable_10101_InterruptAnimat = logic->getVariables().setVariable<bool>("InterruptAnimat");
    //创建阶段phase
    auto phase = new SkillPhase_10101(1, logic, 2);
    //设置phase执行器
    phase->setRunPhaseNode(1, 1);
    phase->setDetectPhaseNode(2, 188);
    phase->setDetectPhaseNode(2, 201);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_10101::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
