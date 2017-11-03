#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

#include "skill_psnode_attachto.h"
#include "skill_psnode_delay.h"
#include "skill_psnode_destroycollider.h"
#include "skill_psnode_detect.h"
#include "skill_psnode_disable.h"
#include "skill_psnode_endphase.h"
#include "skill_psnode_getactorattribute.h"
#include "skill_psnode_getinputrotation.h"
#include "skill_psnode_getlocation.h"
#include "skill_psnode_if.h"
#include "skill_psnode_isinterrupttype.h"
#include "skill_psnode_movenewpene.h"
#include "skill_psnode_playanimation.h"
#include "skill_psnode_playeffect.h"
#include "skill_psnode_playsound.h"
#include "skill_psnode_raiseevent.h"
#include "skill_psnode_resetcd.h"
#include "skill_psnode_resetskill.h"
#include "skill_psnode_setbool.h"
#include "skill_psnode_spawncollider.h"
#include "skill_psnode_startphase.h"
#include "skill_psnode_startpreinput.h"
#include "skill_psnode_switchtoint.h"

namespace pvp {

//变量声明
uint64_t Variable_10132_a101328 = 0;
uint64_t Variable_10132_InterruptAnimat = 0;
//--------------------------------------------------------------------------------
// StartPhase
//
REGISTER_REGISTER_SKILL_NODE(10132, 0) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_StartPhase::TRIGGER_START, 78, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(10132, 0) {
    auto node0 = GET_SKILL_NODE(0, PhaseNode_StartPhase);
    if (node0 == nullptr) {
        node0 = new PhaseNode_StartPhase(0, phase);
        CALL_REGISTER_SKILL_NODE(10132, 0, node0)
    }
    if (noInit == true) {
        return node0;
    }
    return node0;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(10132, 2) {
}

REGISTER_CREATE_SKILL_NODE(10132, 2) {
    auto node2 = GET_SKILL_NODE(2, PhaseNode_EndPhase);
    if (node2 == nullptr) {
        node2 = new PhaseNode_EndPhase(2, phase);
        node2->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node2->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10132, 2, node2)
    }
    if (noInit == true) {
        return node2;
    }
    return node2;
}
//--------------------------------------------------------------------------------
// Disable
//
REGISTER_REGISTER_SKILL_NODE(10132, 24) {
    pnode->resizeTrigger(PhaseNode_Disable::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_Disable::TRIGGER_CANCEL, 62, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_Disable::TRIGGER_DONE, 58, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
    pnode->regTrigger<PhaseNode_SpawnCollider>(PhaseNode_Disable::TRIGGER_DONE, 41, PhaseNode_SpawnCollider::FUNC_DO, &PhaseNode_SpawnCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(10132, 24) {
    auto node24 = GET_SKILL_NODE(24, PhaseNode_Disable);
    if (node24 == nullptr) {
        node24 = new PhaseNode_Disable(24, phase);
        node24->setTarget(0U);
        node24->setMove(true);
        node24->setSkill(true);
        node24->setShoot(true);
        node24->setTime(.60f);
        node24->setRotate(true);
        CALL_REGISTER_SKILL_NODE(10132, 24, node24)
    }
    if (noInit == true) {
        return node24;
    }
    return node24;
}
//--------------------------------------------------------------------------------
// SpawnCollider
//
REGISTER_REGISTER_SKILL_NODE(10132, 41) {
    pnode->resizeTrigger(PhaseNode_SpawnCollider::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AttachTo>(PhaseNode_SpawnCollider::TRIGGER_DONE, 43, PhaseNode_AttachTo::FUNC_DO, &PhaseNode_AttachTo::Do);
}

REGISTER_CREATE_SKILL_NODE(10132, 41) {
    auto node41 = GET_SKILL_NODE(41, PhaseNode_SpawnCollider);
    if (node41 == nullptr) {
        node41 = new PhaseNode_SpawnCollider(41, phase);
        node41->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node41->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node41->setMesh("");
        node41->setMeshScale(.00f);
        node41->setEffectID(0);
        node41->setEffectScale(.00f);
        node41->setType(PhaseNode_SpawnCollider::SpawnCollider_Type::Circle);
        node41->setTypeParams(0, .79f);
        node41->setTime(.70f);
        node41->setPosZ(.00f);
        node41->setRotation(.00f);
        node41->setreentry(false);
        node41->setCheckPeneSound(false);
        CALL_REGISTER_SKILL_NODE(10132, 41, node41)
    }
    if (noInit == true) {
        return node41;
    }
    auto node54 = GET_SKILL_NODE(54, PhaseNode_GetLocation);
    if (node54 != nullptr) node41->setPosX(node54->getX());
    if (node54 != nullptr) node41->setPosY(node54->getY());
    return node41;
}
//--------------------------------------------------------------------------------
// AttachTo
//
REGISTER_REGISTER_SKILL_NODE(10132, 43) {
    pnode->resizeTrigger(PhaseNode_AttachTo::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_MoveNewPene>(PhaseNode_AttachTo::TRIGGER_DONE, 45, PhaseNode_MoveNewPene::FUNC_DO, &PhaseNode_MoveNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(10132, 43) {
    auto node43 = GET_SKILL_NODE(43, PhaseNode_AttachTo);
    if (node43 == nullptr) {
        node43 = new PhaseNode_AttachTo(43, phase);
        node43->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node43->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node43->setChild(0U);
        node43->setChangeRotation(false);
        node43->setreentry(false);
        CALL_REGISTER_SKILL_NODE(10132, 43, node43)
    }
    if (noInit == true) {
        return node43;
    }
    auto node41 = GET_SKILL_NODE(41, PhaseNode_SpawnCollider);
    if (node41 != nullptr) node43->setParent(node41->getColliderID());
    return node43;
}
//--------------------------------------------------------------------------------
// MoveNewPene
//
REGISTER_REGISTER_SKILL_NODE(10132, 45) {
    pnode->resizeTrigger(PhaseNode_MoveNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ResetSkill>(PhaseNode_MoveNewPene::TRIGGER_DONE, 47, PhaseNode_ResetSkill::FUNC_DO, &PhaseNode_ResetSkill::Do);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_MoveNewPene::TRIGGER_STARTMOVE, 50, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(10132, 45) {
    auto node45 = GET_SKILL_NODE(45, PhaseNode_MoveNewPene);
    if (node45 == nullptr) {
        node45 = new PhaseNode_MoveNewPene(45, phase);
        node45->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node45->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node45->setPeneType(PhaseNode_MoveNewPene::MoveNewPene_PeneType::Move);
        node45->setPeneValue(15);
        node45->setType(PhaseNode_MoveNewPene::MoveNewPene_Type::Charge);
        node45->getVars().reserve(4);
        node45->getVars().setVariable<float>(0, 15.00f);
        node45->getVars().setVariable<float>(1, 7.50f);
        node45->getVars().setVariable<float>(2, .00f);
        node45->getVars().setVariable<float>(3, .00f);
        node45->setreentry(false);
        node45->setStopWhenFail(false);
        node45->setCheckFaction(PhaseNode_MoveNewPene::MoveNewPene_CheckFaction::Enemy);
        CALL_REGISTER_SKILL_NODE(10132, 45, node45)
    }
    if (noInit == true) {
        return node45;
    }
    auto node41 = GET_SKILL_NODE(41, PhaseNode_SpawnCollider);
    auto node56 = GET_SKILL_NODE(56, PhaseNode_GetInputRotation);
    if (node41 != nullptr) node45->setTarget(node41->getColliderID());
    if (node56 != nullptr) node45->getVars().setVariable<float>(2, node56->getAngle());
    return node45;
}
//--------------------------------------------------------------------------------
// ResetSkill
//
REGISTER_REGISTER_SKILL_NODE(10132, 47) {
    pnode->resizeTrigger(PhaseNode_ResetSkill::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_DestroyCollider>(PhaseNode_ResetSkill::TRIGGER_DONE, 60, PhaseNode_DestroyCollider::FUNC_DO, &PhaseNode_DestroyCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(10132, 47) {
    auto node47 = GET_SKILL_NODE(47, PhaseNode_ResetSkill);
    if (node47 == nullptr) {
        node47 = new PhaseNode_ResetSkill(47, phase);
        node47->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node47->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node47->setSkillID({10131});
        node47->setTime(5.00f);
        CALL_REGISTER_SKILL_NODE(10132, 47, node47)
    }
    if (noInit == true) {
        return node47;
    }
    return node47;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(10132, 50) {
}

REGISTER_CREATE_SKILL_NODE(10132, 50) {
    auto node50 = GET_SKILL_NODE(50, PhaseNode_PlayEffect);
    if (node50 == nullptr) {
        node50 = new PhaseNode_PlayEffect(50, phase);
        node50->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node50->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node50->setEffectID(101321);
        node50->setChangeColor(false);
        node50->setType(PhaseNode_PlayEffect::PlayEffect_Type::WithTarget);
        node50->getVars().reserve(6);
        node50->getVars().setVariable<uint64_t>(0, 0U);
        node50->getVars().setVariable<std::string>(1, "");
        node50->getVars().setVariable<float>(2, .00f);
        node50->getVars().setVariable<float>(3, .00f);
        node50->getVars().setVariable<float>(4, 1.00f);
        node50->getVars().setVariable<bool>(5, false);
        node50->setRotation(.00f);
        node50->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(10132, 50, node50)
    }
    if (noInit == true) {
        return node50;
    }
    return node50;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(10132, 54) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetInputRotation>(PhaseNode_GetLocation::TRIGGER_DONE, 56, PhaseNode_GetInputRotation::FUNC_DO, &PhaseNode_GetInputRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(10132, 54) {
    auto node54 = GET_SKILL_NODE(54, PhaseNode_GetLocation);
    if (node54 == nullptr) {
        node54 = new PhaseNode_GetLocation(54, phase);
        node54->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node54->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(10132, 54, node54)
    }
    if (noInit == true) {
        return node54;
    }
    return node54;
}
//--------------------------------------------------------------------------------
// GetInputRotation
//
REGISTER_REGISTER_SKILL_NODE(10132, 56) {
    pnode->resizeTrigger(PhaseNode_GetInputRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Disable>(PhaseNode_GetInputRotation::TRIGGER_DONE, 24, PhaseNode_Disable::FUNC_DO, &PhaseNode_Disable::Do);
}

REGISTER_CREATE_SKILL_NODE(10132, 56) {
    auto node56 = GET_SKILL_NODE(56, PhaseNode_GetInputRotation);
    if (node56 == nullptr) {
        node56 = new PhaseNode_GetInputRotation(56, phase);
        node56->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        CALL_REGISTER_SKILL_NODE(10132, 56, node56)
    }
    if (noInit == true) {
        return node56;
    }
    return node56;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10132, 58) {
}

REGISTER_CREATE_SKILL_NODE(10132, 58) {
    auto node58 = GET_SKILL_NODE(58, PhaseNode_PlaySound);
    if (node58 == nullptr) {
        node58 = new PhaseNode_PlaySound(58, phase);
        node58->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node58->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node58->setSoundID("SE_Hero105_SkillB_P1");
        node58->setTarget(0U);
        node58->setUsePos(false);
        node58->setPosX(.00f);
        node58->setPosY(.00f);
        node58->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10132, 58, node58)
    }
    if (noInit == true) {
        return node58;
    }
    return node58;
}
//--------------------------------------------------------------------------------
// DestroyCollider
//
REGISTER_REGISTER_SKILL_NODE(10132, 60) {
    pnode->resizeTrigger(PhaseNode_DestroyCollider::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Disable>(PhaseNode_DestroyCollider::TRIGGER_DONE, 24, PhaseNode_Disable::FUNC_CANCLE, &PhaseNode_Disable::Cancle);
}

REGISTER_CREATE_SKILL_NODE(10132, 60) {
    auto node60 = GET_SKILL_NODE(60, PhaseNode_DestroyCollider);
    if (node60 == nullptr) {
        node60 = new PhaseNode_DestroyCollider(60, phase);
        CALL_REGISTER_SKILL_NODE(10132, 60, node60)
    }
    if (noInit == true) {
        return node60;
    }
    auto node41 = GET_SKILL_NODE(41, PhaseNode_SpawnCollider);
    if (node41 != nullptr) node60->setColliderID(node41->getColliderID());
    return node60;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10132, 62) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_Delay::TRIGGER_DONE, 2, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(10132, 62) {
    auto node62 = GET_SKILL_NODE(62, PhaseNode_Delay);
    if (node62 == nullptr) {
        node62 = new PhaseNode_Delay(62, phase);
        node62->setTime(.36f);
        CALL_REGISTER_SKILL_NODE(10132, 62, node62)
    }
    if (noInit == true) {
        return node62;
    }
    return node62;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10132, 64) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_IsInterruptType>(PhaseNode_Detect::TRIGGER_ON, 70, PhaseNode_IsInterruptType::FUNC_DO, &PhaseNode_IsInterruptType::Do);
}

REGISTER_CREATE_SKILL_NODE(10132, 64) {
    auto node64 = GET_SKILL_NODE(64, PhaseNode_Detect);
    if (node64 == nullptr) {
        node64 = new PhaseNode_Detect(64, phase);
        node64->setSelf(0U);
        node64->setEvent("daduan_001");
        node64->setType(PhaseNode_Detect::Detect_Type::Interrupt_Skill);
        node64->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10132, 64, node64)
    }
    if (noInit == true) {
        return node64;
    }
    return node64;
}
//--------------------------------------------------------------------------------
// SwitchToInt
//
REGISTER_REGISTER_SKILL_NODE(10132, 65) {
    pnode->resizeTrigger(4);
    pnode->regTrigger<PhaseNode_EndPhase>(1, 2, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(10132, 65) {
    auto node65 = GET_SKILL_NODE(65, PhaseNode_SwitchToInt);
    if (node65 == nullptr) {
        node65 = new PhaseNode_SwitchToInt(65, phase);
        CALL_REGISTER_SKILL_NODE(10132, 65, node65)
    }
    if (noInit == true) {
        return node65;
    }
    auto variables = node65->getVariables();
    if (variables != nullptr) {
        node65->setSelection(variables->getVariable<int32_t>(Variable_10132_a101328));
    }
    return node65;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10132, 67) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_RaiseEvent::TRIGGER_DONE, 76, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10132, 67) {
    auto node67 = GET_SKILL_NODE(67, PhaseNode_RaiseEvent);
    if (node67 == nullptr) {
        node67 = new PhaseNode_RaiseEvent(67, phase);
        node67->setEvent("daduan_001");
        node67->setTarget(0U);
        node67->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node67->setTypeParams(0, 0);
        node67->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10132, 67, node67)
    }
    if (noInit == true) {
        return node67;
    }
    return node67;
}
//--------------------------------------------------------------------------------
// StartPreInput
//
REGISTER_REGISTER_SKILL_NODE(10132, 68) {
    pnode->resizeTrigger(PhaseNode_StartPreInput::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_StartPreInput::TRIGGER_DONE, 72, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10132, 68) {
    auto node68 = GET_SKILL_NODE(68, PhaseNode_StartPreInput);
    if (node68 == nullptr) {
        node68 = new PhaseNode_StartPreInput(68, phase);
        node68->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node68->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node68->setDelayTime(.00f);
        CALL_REGISTER_SKILL_NODE(10132, 68, node68)
    }
    if (noInit == true) {
        return node68;
    }
    return node68;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(10132, 69) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_If::TRIGGER_TRUE, 71, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10132, 69) {
    auto node69 = GET_SKILL_NODE(69, PhaseNode_If);
    if (node69 == nullptr) {
        node69 = new PhaseNode_If(69, phase);
        CALL_REGISTER_SKILL_NODE(10132, 69, node69)
    }
    if (noInit == true) {
        return node69;
    }
    auto variables = node69->getVariables();
    if (variables != nullptr) {
        node69->setCondition(variables->getVariable<bool>(Variable_10132_InterruptAnimat));
    }
    return node69;
}
//--------------------------------------------------------------------------------
// IsInterruptType
//
REGISTER_REGISTER_SKILL_NODE(10132, 70) {
    pnode->resizeTrigger(PhaseNode_IsInterruptType::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SwitchToInt>(PhaseNode_IsInterruptType::TRIGGER_BUFF, 65, PhaseNode_SwitchToInt::FUNC_SWITCH, &PhaseNode_SwitchToInt::Switch);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_POSCHANGE, 69, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTAIM, 69, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTFIRE, 69, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTRELOAD, 69, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_USESKILL, 69, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(10132, 70) {
    auto node70 = GET_SKILL_NODE(70, PhaseNode_IsInterruptType);
    if (node70 == nullptr) {
        node70 = new PhaseNode_IsInterruptType(70, phase);
        node70->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node70->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10132, 70, node70)
    }
    if (noInit == true) {
        return node70;
    }
    auto node64 = GET_SKILL_NODE(64, PhaseNode_Detect);
    if (node64 != nullptr) node70->setType(node64->getVars().getVariable<int32_t>(2));
    return node70;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10132, 71) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_PlayAnimation::TRIGGER_DONE, 2, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(10132, 71) {
    auto node71 = GET_SKILL_NODE(71, PhaseNode_PlayAnimation);
    if (node71 == nullptr) {
        node71 = new PhaseNode_PlayAnimation(71, phase);
        node71->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node71->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node71->setTarget(0U);
        node71->setAnimation("Idle");
        node71->setParameter("");
        node71->setValue(false);
        CALL_REGISTER_SKILL_NODE(10132, 71, node71)
    }
    if (noInit == true) {
        return node71;
    }
    return node71;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10132, 72) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_Delay::TRIGGER_DONE, 75, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(10132, 72) {
    auto node72 = GET_SKILL_NODE(72, PhaseNode_Delay);
    if (node72 == nullptr) {
        node72 = new PhaseNode_Delay(72, phase);
        node72->setTime(.20f);
        CALL_REGISTER_SKILL_NODE(10132, 72, node72)
    }
    if (noInit == true) {
        return node72;
    }
    return node72;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(10132, 75) {
}

REGISTER_CREATE_SKILL_NODE(10132, 75) {
    auto node75 = GET_SKILL_NODE(75, PhaseNode_SetBool);
    if (node75 == nullptr) {
        node75 = new PhaseNode_SetBool(75, phase);
        node75->setName("InterruptAnimat");
        node75->setValue(true);
        CALL_REGISTER_SKILL_NODE(10132, 75, node75)
    }
    if (noInit == true) {
        return node75;
    }
    return node75;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10132, 76) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StartPreInput>(PhaseNode_RaiseEvent::TRIGGER_DONE, 68, PhaseNode_StartPreInput::FUNC_DO, &PhaseNode_StartPreInput::Do);
}

REGISTER_CREATE_SKILL_NODE(10132, 76) {
    auto node76 = GET_SKILL_NODE(76, PhaseNode_RaiseEvent);
    if (node76 == nullptr) {
        node76 = new PhaseNode_RaiseEvent(76, phase);
        node76->setEvent("Dead_001");
        node76->setTarget(0U);
        node76->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node76->setTypeParams(0, 0);
        node76->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10132, 76, node76)
    }
    if (noInit == true) {
        return node76;
    }
    return node76;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10132, 77) {
}

REGISTER_CREATE_SKILL_NODE(10132, 77) {
    auto node77 = GET_SKILL_NODE(77, PhaseNode_Detect);
    if (node77 == nullptr) {
        node77 = new PhaseNode_Detect(77, phase);
        node77->setSelf(0U);
        node77->setEvent("Dead_001");
        node77->setType(PhaseNode_Detect::Detect_Type::Actor_Dead);
        node77->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10132, 77, node77)
    }
    if (noInit == true) {
        return node77;
    }
    return node77;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(10132, 78) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_ResetCD::TRIGGER_DONE, 79, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10132, 78) {
    auto node78 = GET_SKILL_NODE(78, PhaseNode_ResetCD);
    if (node78 == nullptr) {
        node78 = new PhaseNode_ResetCD(78, phase);
        node78->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node78->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node78->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(10132, 78, node78)
    }
    if (noInit == true) {
        return node78;
    }
    return node78;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10132, 79) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_PlayAnimation::TRIGGER_DONE, 81, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(10132, 79) {
    auto node79 = GET_SKILL_NODE(79, PhaseNode_PlayAnimation);
    if (node79 == nullptr) {
        node79 = new PhaseNode_PlayAnimation(79, phase);
        node79->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node79->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node79->setTarget(0U);
        node79->setAnimation("Skill2S1");
        node79->setParameter("");
        node79->setValue(false);
        CALL_REGISTER_SKILL_NODE(10132, 79, node79)
    }
    if (noInit == true) {
        return node79;
    }
    return node79;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10132, 80) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_PlaySound::TRIGGER_DONE, 54, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_PlaySound::TRIGGER_DONE, 67, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10132, 80) {
    auto node80 = GET_SKILL_NODE(80, PhaseNode_PlaySound);
    if (node80 == nullptr) {
        node80 = new PhaseNode_PlaySound(80, phase);
        node80->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node80->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node80->setSoundID("VO_Hero105_Skill_B");
        node80->setTarget(0U);
        node80->setUsePos(false);
        node80->setPosX(.00f);
        node80->setPosY(.00f);
        node80->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10132, 80, node80)
    }
    if (noInit == true) {
        return node80;
    }
    return node80;
}
//--------------------------------------------------------------------------------
// GetActorAttribute
//
REGISTER_REGISTER_SKILL_NODE(10132, 81) {
    pnode->resizeTrigger(PhaseNode_GetActorAttribute::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 80, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10132, 81) {
    auto node81 = GET_SKILL_NODE(81, PhaseNode_GetActorAttribute);
    if (node81 == nullptr) {
        node81 = new PhaseNode_GetActorAttribute(81, phase);
        node81->setTarget(0U);
        node81->setType({});
        CALL_REGISTER_SKILL_NODE(10132, 81, node81)
    }
    if (noInit == true) {
        return node81;
    }
    return node81;
}

//--------------------------------------------------------------------------------
// SkillCreator_10132
//
class SkillCreator_10132 : public SkillCreator {
public:
    SkillCreator_10132() {}
    virtual ~SkillCreator_10132() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_10132

//--------------------------------------------------------------------------------
// SkillPhase_10132
//
class SkillPhase_10132 : public SkillPhase {
public:
    SkillPhase_10132(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_10132() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(10132, 0) // StartPhase
        CASE_CREATE_SKILL_NODE(10132, 2) // EndPhase
        CASE_CREATE_SKILL_NODE(10132, 24) // Disable
        CASE_CREATE_SKILL_NODE(10132, 41) // SpawnCollider
        CASE_CREATE_SKILL_NODE(10132, 43) // AttachTo
        CASE_CREATE_SKILL_NODE(10132, 45) // MoveNewPene
        CASE_CREATE_SKILL_NODE(10132, 47) // ResetSkill
        CASE_CREATE_SKILL_NODE(10132, 50) // PlayEffect
        CASE_CREATE_SKILL_NODE(10132, 54) // GetLocation
        CASE_CREATE_SKILL_NODE(10132, 56) // GetInputRotation
        CASE_CREATE_SKILL_NODE(10132, 58) // PlaySound
        CASE_CREATE_SKILL_NODE(10132, 60) // DestroyCollider
        CASE_CREATE_SKILL_NODE(10132, 62) // Delay
        CASE_CREATE_SKILL_NODE(10132, 64) // Detect
        CASE_CREATE_SKILL_NODE(10132, 65) // SwitchToInt
        CASE_CREATE_SKILL_NODE(10132, 67) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10132, 68) // StartPreInput
        CASE_CREATE_SKILL_NODE(10132, 69) // If
        CASE_CREATE_SKILL_NODE(10132, 70) // IsInterruptType
        CASE_CREATE_SKILL_NODE(10132, 71) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10132, 72) // Delay
        CASE_CREATE_SKILL_NODE(10132, 75) // SetBool
        CASE_CREATE_SKILL_NODE(10132, 76) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10132, 77) // Detect
        CASE_CREATE_SKILL_NODE(10132, 78) // ResetCD
        CASE_CREATE_SKILL_NODE(10132, 79) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10132, 80) // PlaySound
        CASE_CREATE_SKILL_NODE(10132, 81) // GetActorAttribute
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_10132

SkillLogic* SkillCreator_10132::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //设置变量
    Variable_10132_a101328 = logic->getVariables().setVariable<int32_t>("a101328", 1);
    Variable_10132_InterruptAnimat = logic->getVariables().setVariable<bool>("InterruptAnimat");
    //创建阶段phase
    auto phase = new SkillPhase_10132(1, logic, 2);
    //设置phase执行器
    phase->setRunPhaseNode(1, 0);
    phase->setDetectPhaseNode(2, 64);
    phase->setDetectPhaseNode(2, 77);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_10132::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
