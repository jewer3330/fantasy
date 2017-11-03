#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

#include "skill_psnode_addskillbuff.h"
#include "skill_psnode_delay.h"
#include "skill_psnode_detect.h"
#include "skill_psnode_endphase.h"
#include "skill_psnode_getlocation.h"
#include "skill_psnode_getrotation.h"
#include "skill_psnode_if.h"
#include "skill_psnode_isinterrupttype.h"
#include "skill_psnode_playanimation.h"
#include "skill_psnode_playeffect.h"
#include "skill_psnode_playsound.h"
#include "skill_psnode_raiseevent.h"
#include "skill_psnode_removeskillbuff.h"
#include "skill_psnode_resetcd.h"
#include "skill_psnode_setbool.h"
#include "skill_psnode_startphase.h"
#include "skill_psnode_startpreinput.h"
#include "skill_psnode_switchtoint.h"
#include "skill_psnode_timedown.h"

namespace pvp {

//变量声明
uint64_t Variable_10071_a100712 = 0;
uint64_t Variable_10071_InterruptAnimat = 0;
//--------------------------------------------------------------------------------
// StartPhase
//
REGISTER_REGISTER_SKILL_NODE(10071, 1) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_StartPhase::TRIGGER_START, 48, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(10071, 1) {
    auto node1 = GET_SKILL_NODE(1, PhaseNode_StartPhase);
    if (node1 == nullptr) {
        node1 = new PhaseNode_StartPhase(1, phase);
        CALL_REGISTER_SKILL_NODE(10071, 1, node1)
    }
    if (noInit == true) {
        return node1;
    }
    return node1;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(10071, 6) {
}

REGISTER_CREATE_SKILL_NODE(10071, 6) {
    auto node6 = GET_SKILL_NODE(6, PhaseNode_EndPhase);
    if (node6 == nullptr) {
        node6 = new PhaseNode_EndPhase(6, phase);
        node6->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node6->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10071, 6, node6)
    }
    if (noInit == true) {
        return node6;
    }
    return node6;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(10071, 48) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_ResetCD::TRIGGER_DONE, 90, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_ResetCD::TRIGGER_DONE, 97, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10071, 48) {
    auto node48 = GET_SKILL_NODE(48, PhaseNode_ResetCD);
    if (node48 == nullptr) {
        node48 = new PhaseNode_ResetCD(48, phase);
        node48->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node48->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node48->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(10071, 48, node48)
    }
    if (noInit == true) {
        return node48;
    }
    return node48;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10071, 54) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_RaiseEvent::TRIGGER_DONE, 78, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10071, 54) {
    auto node54 = GET_SKILL_NODE(54, PhaseNode_RaiseEvent);
    if (node54 == nullptr) {
        node54 = new PhaseNode_RaiseEvent(54, phase);
        node54->setEvent("shoushang");
        node54->setTarget(0U);
        node54->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node54->setTypeParams(0, 0);
        node54->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10071, 54, node54)
    }
    if (noInit == true) {
        return node54;
    }
    return node54;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10071, 56) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TimeDown>(PhaseNode_Detect::TRIGGER_ON, 88, PhaseNode_TimeDown::FUNC_DO, &PhaseNode_TimeDown::Do);
}

REGISTER_CREATE_SKILL_NODE(10071, 56) {
    auto node56 = GET_SKILL_NODE(56, PhaseNode_Detect);
    if (node56 == nullptr) {
        node56 = new PhaseNode_Detect(56, phase);
        node56->setSelf(0U);
        node56->setEvent("shoushang");
        node56->setType(PhaseNode_Detect::Detect_Type::Damage);
        node56->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10071, 56, node56)
    }
    if (noInit == true) {
        return node56;
    }
    return node56;
}
//--------------------------------------------------------------------------------
// AddSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10071, 60) {
    pnode->resizeTrigger(PhaseNode_AddSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_AddSkillBuff::TRIGGER_DONE, 54, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10071, 60) {
    auto node60 = GET_SKILL_NODE(60, PhaseNode_AddSkillBuff);
    if (node60 == nullptr) {
        node60 = new PhaseNode_AddSkillBuff(60, phase);
        node60->setConfigID(0);
        node60->setConfigIDs({100711,100712});
        node60->setTarget(0U);
        node60->setAttribute({{}});
        CALL_REGISTER_SKILL_NODE(10071, 60, node60)
    }
    if (noInit == true) {
        return node60;
    }
    return node60;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10071, 65) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_Delay::TRIGGER_DONE, 86, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10071, 65) {
    auto node65 = GET_SKILL_NODE(65, PhaseNode_Delay);
    if (node65 == nullptr) {
        node65 = new PhaseNode_Delay(65, phase);
        node65->setTime(4.00f);
        CALL_REGISTER_SKILL_NODE(10071, 65, node65)
    }
    if (noInit == true) {
        return node65;
    }
    return node65;
}
//--------------------------------------------------------------------------------
// RemoveSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10071, 70) {
    pnode->resizeTrigger(PhaseNode_RemoveSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_RemoveSkillBuff::TRIGGER_DONE, 86, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10071, 70) {
    auto node70 = GET_SKILL_NODE(70, PhaseNode_RemoveSkillBuff);
    if (node70 == nullptr) {
        node70 = new PhaseNode_RemoveSkillBuff(70, phase);
        node70->setBuffID(0U);
        node70->setBuffIDs({});
        node70->setConfigID(100711);
        node70->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(10071, 70, node70)
    }
    if (noInit == true) {
        return node70;
    }
    return node70;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(10071, 76) {
}

REGISTER_CREATE_SKILL_NODE(10071, 76) {
    auto node76 = GET_SKILL_NODE(76, PhaseNode_PlayEffect);
    if (node76 == nullptr) {
        node76 = new PhaseNode_PlayEffect(76, phase);
        node76->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node76->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node76->setEffectID(100711);
        node76->setChangeColor(true);
        node76->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node76->getVars().reserve(3);
        node76->getVars().setVariable<float>(0, .00f);
        node76->getVars().setVariable<float>(1, .00f);
        node76->getVars().setVariable<float>(2, .00f);
        node76->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(10071, 76, node76)
    }
    if (noInit == true) {
        return node76;
    }
    auto node90 = GET_SKILL_NODE(90, PhaseNode_GetLocation);
    auto node92 = GET_SKILL_NODE(92, PhaseNode_GetRotation);
    if (node90 != nullptr) node76->getVars().setVariable<float>(0, node90->getX());
    if (node90 != nullptr) node76->getVars().setVariable<float>(1, node90->getY());
    if (node92 != nullptr) node76->setRotation(node92->getAngle());
    return node76;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10071, 78) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_RaiseEvent::TRIGGER_DONE, 65, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10071, 78) {
    auto node78 = GET_SKILL_NODE(78, PhaseNode_RaiseEvent);
    if (node78 == nullptr) {
        node78 = new PhaseNode_RaiseEvent(78, phase);
        node78->setEvent("kaihuo");
        node78->setTarget(0U);
        node78->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node78->setTypeParams(0, 0);
        node78->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10071, 78, node78)
    }
    if (noInit == true) {
        return node78;
    }
    return node78;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10071, 81) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RemoveSkillBuff>(PhaseNode_Detect::TRIGGER_ON, 70, PhaseNode_RemoveSkillBuff::FUNC_REMOVE, &PhaseNode_RemoveSkillBuff::Remove);
}

REGISTER_CREATE_SKILL_NODE(10071, 81) {
    auto node81 = GET_SKILL_NODE(81, PhaseNode_Detect);
    if (node81 == nullptr) {
        node81 = new PhaseNode_Detect(81, phase);
        node81->setSelf(0U);
        node81->setEvent("kaihuo");
        node81->setType(PhaseNode_Detect::Detect_Type::Hold_Fire);
        node81->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10071, 81, node81)
    }
    if (noInit == true) {
        return node81;
    }
    return node81;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10071, 84) {
}

REGISTER_CREATE_SKILL_NODE(10071, 84) {
    auto node84 = GET_SKILL_NODE(84, PhaseNode_PlaySound);
    if (node84 == nullptr) {
        node84 = new PhaseNode_PlaySound(84, phase);
        node84->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node84->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node84->setSoundID("SE_Hero104_SkillA_P1");
        node84->setTarget(0U);
        node84->setUsePos(false);
        node84->setPosX(.00f);
        node84->setPosY(.00f);
        node84->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10071, 84, node84)
    }
    if (noInit == true) {
        return node84;
    }
    return node84;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10071, 86) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_PlaySound::TRIGGER_DONE, 6, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(10071, 86) {
    auto node86 = GET_SKILL_NODE(86, PhaseNode_PlaySound);
    if (node86 == nullptr) {
        node86 = new PhaseNode_PlaySound(86, phase);
        node86->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node86->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node86->setSoundID("SE_Hero104_SkillA_P2");
        node86->setTarget(0U);
        node86->setUsePos(false);
        node86->setPosX(.00f);
        node86->setPosY(.00f);
        node86->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10071, 86, node86)
    }
    if (noInit == true) {
        return node86;
    }
    return node86;
}
//--------------------------------------------------------------------------------
// TimeDown
//
REGISTER_REGISTER_SKILL_NODE(10071, 88) {
    pnode->resizeTrigger(PhaseNode_TimeDown::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RemoveSkillBuff>(PhaseNode_TimeDown::TRIGGER_DONE, 70, PhaseNode_RemoveSkillBuff::FUNC_REMOVE, &PhaseNode_RemoveSkillBuff::Remove);
}

REGISTER_CREATE_SKILL_NODE(10071, 88) {
    auto node88 = GET_SKILL_NODE(88, PhaseNode_TimeDown);
    if (node88 == nullptr) {
        node88 = new PhaseNode_TimeDown(88, phase);
        node88->setTime(1.50f);
        node88->setNum(1);
        node88->setIsImmediateFirst(false);
        CALL_REGISTER_SKILL_NODE(10071, 88, node88)
    }
    if (noInit == true) {
        return node88;
    }
    return node88;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(10071, 90) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetRotation>(PhaseNode_GetLocation::TRIGGER_DONE, 92, PhaseNode_GetRotation::FUNC_DO, &PhaseNode_GetRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(10071, 90) {
    auto node90 = GET_SKILL_NODE(90, PhaseNode_GetLocation);
    if (node90 == nullptr) {
        node90 = new PhaseNode_GetLocation(90, phase);
        node90->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node90->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(10071, 90, node90)
    }
    if (noInit == true) {
        return node90;
    }
    return node90;
}
//--------------------------------------------------------------------------------
// GetRotation
//
REGISTER_REGISTER_SKILL_NODE(10071, 92) {
    pnode->resizeTrigger(PhaseNode_GetRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuff>(PhaseNode_GetRotation::TRIGGER_DONE, 60, PhaseNode_AddSkillBuff::FUNC_ADD, &PhaseNode_AddSkillBuff::Add);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_GetRotation::TRIGGER_DONE, 76, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(10071, 92) {
    auto node92 = GET_SKILL_NODE(92, PhaseNode_GetRotation);
    if (node92 == nullptr) {
        node92 = new PhaseNode_GetRotation(92, phase);
        node92->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node92->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(10071, 92, node92)
    }
    if (noInit == true) {
        return node92;
    }
    return node92;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10071, 94) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_IsInterruptType>(PhaseNode_Detect::TRIGGER_ON, 100, PhaseNode_IsInterruptType::FUNC_DO, &PhaseNode_IsInterruptType::Do);
}

REGISTER_CREATE_SKILL_NODE(10071, 94) {
    auto node94 = GET_SKILL_NODE(94, PhaseNode_Detect);
    if (node94 == nullptr) {
        node94 = new PhaseNode_Detect(94, phase);
        node94->setSelf(0U);
        node94->setEvent("daduan_001");
        node94->setType(PhaseNode_Detect::Detect_Type::Interrupt_Skill);
        node94->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10071, 94, node94)
    }
    if (noInit == true) {
        return node94;
    }
    return node94;
}
//--------------------------------------------------------------------------------
// SwitchToInt
//
REGISTER_REGISTER_SKILL_NODE(10071, 95) {
    pnode->resizeTrigger(4);
    pnode->regTrigger<PhaseNode_TimeDown>(1, 88, PhaseNode_TimeDown::FUNC_DO, &PhaseNode_TimeDown::Do);
}

REGISTER_CREATE_SKILL_NODE(10071, 95) {
    auto node95 = GET_SKILL_NODE(95, PhaseNode_SwitchToInt);
    if (node95 == nullptr) {
        node95 = new PhaseNode_SwitchToInt(95, phase);
        CALL_REGISTER_SKILL_NODE(10071, 95, node95)
    }
    if (noInit == true) {
        return node95;
    }
    auto variables = node95->getVariables();
    if (variables != nullptr) {
        node95->setSelection(variables->getVariable<int32_t>(Variable_10071_a100712));
    }
    return node95;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10071, 97) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_RaiseEvent::TRIGGER_DONE, 106, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10071, 97) {
    auto node97 = GET_SKILL_NODE(97, PhaseNode_RaiseEvent);
    if (node97 == nullptr) {
        node97 = new PhaseNode_RaiseEvent(97, phase);
        node97->setEvent("daduan_001");
        node97->setTarget(0U);
        node97->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node97->setTypeParams(0, 0);
        node97->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10071, 97, node97)
    }
    if (noInit == true) {
        return node97;
    }
    return node97;
}
//--------------------------------------------------------------------------------
// StartPreInput
//
REGISTER_REGISTER_SKILL_NODE(10071, 98) {
    pnode->resizeTrigger(PhaseNode_StartPreInput::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_StartPreInput::TRIGGER_DONE, 102, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_StartPreInput::TRIGGER_DONE, 84, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10071, 98) {
    auto node98 = GET_SKILL_NODE(98, PhaseNode_StartPreInput);
    if (node98 == nullptr) {
        node98 = new PhaseNode_StartPreInput(98, phase);
        node98->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node98->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node98->setDelayTime(.00f);
        CALL_REGISTER_SKILL_NODE(10071, 98, node98)
    }
    if (noInit == true) {
        return node98;
    }
    return node98;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(10071, 99) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_If::TRIGGER_TRUE, 101, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10071, 99) {
    auto node99 = GET_SKILL_NODE(99, PhaseNode_If);
    if (node99 == nullptr) {
        node99 = new PhaseNode_If(99, phase);
        CALL_REGISTER_SKILL_NODE(10071, 99, node99)
    }
    if (noInit == true) {
        return node99;
    }
    auto variables = node99->getVariables();
    if (variables != nullptr) {
        node99->setCondition(variables->getVariable<bool>(Variable_10071_InterruptAnimat));
    }
    return node99;
}
//--------------------------------------------------------------------------------
// IsInterruptType
//
REGISTER_REGISTER_SKILL_NODE(10071, 100) {
    pnode->resizeTrigger(PhaseNode_IsInterruptType::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SwitchToInt>(PhaseNode_IsInterruptType::TRIGGER_BUFF, 95, PhaseNode_SwitchToInt::FUNC_SWITCH, &PhaseNode_SwitchToInt::Switch);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_POSCHANGE, 99, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTAIM, 99, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTFIRE, 99, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTRELOAD, 99, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_USESKILL, 99, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(10071, 100) {
    auto node100 = GET_SKILL_NODE(100, PhaseNode_IsInterruptType);
    if (node100 == nullptr) {
        node100 = new PhaseNode_IsInterruptType(100, phase);
        node100->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node100->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10071, 100, node100)
    }
    if (noInit == true) {
        return node100;
    }
    auto node94 = GET_SKILL_NODE(94, PhaseNode_Detect);
    if (node94 != nullptr) node100->setType(node94->getVars().getVariable<int32_t>(2));
    return node100;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10071, 101) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RemoveSkillBuff>(PhaseNode_PlayAnimation::TRIGGER_DONE, 70, PhaseNode_RemoveSkillBuff::FUNC_REMOVE, &PhaseNode_RemoveSkillBuff::Remove);
}

REGISTER_CREATE_SKILL_NODE(10071, 101) {
    auto node101 = GET_SKILL_NODE(101, PhaseNode_PlayAnimation);
    if (node101 == nullptr) {
        node101 = new PhaseNode_PlayAnimation(101, phase);
        node101->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node101->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node101->setTarget(0U);
        node101->setAnimation("Idle");
        node101->setParameter("");
        node101->setValue(false);
        CALL_REGISTER_SKILL_NODE(10071, 101, node101)
    }
    if (noInit == true) {
        return node101;
    }
    return node101;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10071, 102) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_Delay::TRIGGER_DONE, 105, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(10071, 102) {
    auto node102 = GET_SKILL_NODE(102, PhaseNode_Delay);
    if (node102 == nullptr) {
        node102 = new PhaseNode_Delay(102, phase);
        node102->setTime(.10f);
        CALL_REGISTER_SKILL_NODE(10071, 102, node102)
    }
    if (noInit == true) {
        return node102;
    }
    return node102;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(10071, 105) {
}

REGISTER_CREATE_SKILL_NODE(10071, 105) {
    auto node105 = GET_SKILL_NODE(105, PhaseNode_SetBool);
    if (node105 == nullptr) {
        node105 = new PhaseNode_SetBool(105, phase);
        node105->setName("InterruptAnimat");
        node105->setValue(true);
        CALL_REGISTER_SKILL_NODE(10071, 105, node105)
    }
    if (noInit == true) {
        return node105;
    }
    return node105;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10071, 106) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StartPreInput>(PhaseNode_RaiseEvent::TRIGGER_DONE, 98, PhaseNode_StartPreInput::FUNC_DO, &PhaseNode_StartPreInput::Do);
}

REGISTER_CREATE_SKILL_NODE(10071, 106) {
    auto node106 = GET_SKILL_NODE(106, PhaseNode_RaiseEvent);
    if (node106 == nullptr) {
        node106 = new PhaseNode_RaiseEvent(106, phase);
        node106->setEvent("Dead_001");
        node106->setTarget(0U);
        node106->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node106->setTypeParams(0, 0);
        node106->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10071, 106, node106)
    }
    if (noInit == true) {
        return node106;
    }
    return node106;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10071, 107) {
}

REGISTER_CREATE_SKILL_NODE(10071, 107) {
    auto node107 = GET_SKILL_NODE(107, PhaseNode_Detect);
    if (node107 == nullptr) {
        node107 = new PhaseNode_Detect(107, phase);
        node107->setSelf(0U);
        node107->setEvent("Dead_001");
        node107->setType(PhaseNode_Detect::Detect_Type::Actor_Dead);
        node107->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10071, 107, node107)
    }
    if (noInit == true) {
        return node107;
    }
    return node107;
}

//--------------------------------------------------------------------------------
// SkillCreator_10071
//
class SkillCreator_10071 : public SkillCreator {
public:
    SkillCreator_10071() {}
    virtual ~SkillCreator_10071() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_10071

//--------------------------------------------------------------------------------
// SkillPhase_10071
//
class SkillPhase_10071 : public SkillPhase {
public:
    SkillPhase_10071(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_10071() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(10071, 1) // StartPhase
        CASE_CREATE_SKILL_NODE(10071, 6) // EndPhase
        CASE_CREATE_SKILL_NODE(10071, 48) // ResetCD
        CASE_CREATE_SKILL_NODE(10071, 54) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10071, 56) // Detect
        CASE_CREATE_SKILL_NODE(10071, 60) // AddSkillBuff
        CASE_CREATE_SKILL_NODE(10071, 65) // Delay
        CASE_CREATE_SKILL_NODE(10071, 70) // RemoveSkillBuff
        CASE_CREATE_SKILL_NODE(10071, 76) // PlayEffect
        CASE_CREATE_SKILL_NODE(10071, 78) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10071, 81) // Detect
        CASE_CREATE_SKILL_NODE(10071, 84) // PlaySound
        CASE_CREATE_SKILL_NODE(10071, 86) // PlaySound
        CASE_CREATE_SKILL_NODE(10071, 88) // TimeDown
        CASE_CREATE_SKILL_NODE(10071, 90) // GetLocation
        CASE_CREATE_SKILL_NODE(10071, 92) // GetRotation
        CASE_CREATE_SKILL_NODE(10071, 94) // Detect
        CASE_CREATE_SKILL_NODE(10071, 95) // SwitchToInt
        CASE_CREATE_SKILL_NODE(10071, 97) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10071, 98) // StartPreInput
        CASE_CREATE_SKILL_NODE(10071, 99) // If
        CASE_CREATE_SKILL_NODE(10071, 100) // IsInterruptType
        CASE_CREATE_SKILL_NODE(10071, 101) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10071, 102) // Delay
        CASE_CREATE_SKILL_NODE(10071, 105) // SetBool
        CASE_CREATE_SKILL_NODE(10071, 106) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10071, 107) // Detect
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_10071

SkillLogic* SkillCreator_10071::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //设置变量
    Variable_10071_a100712 = logic->getVariables().setVariable<int32_t>("a100712", 1);
    Variable_10071_InterruptAnimat = logic->getVariables().setVariable<bool>("InterruptAnimat");
    //创建阶段phase
    auto phase = new SkillPhase_10071(1, logic, 2);
    //设置phase执行器
    phase->setRunPhaseNode(1, 1);
    phase->setDetectPhaseNode(2, 56);
    phase->setDetectPhaseNode(2, 81);
    phase->setDetectPhaseNode(2, 94);
    phase->setDetectPhaseNode(2, 107);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_10071::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
