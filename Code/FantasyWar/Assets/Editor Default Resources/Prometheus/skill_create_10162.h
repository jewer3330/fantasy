#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

#include "skill_psnode_addskillbuffs.h"
#include "skill_psnode_areacollisionnewpene.h"
#include "skill_psnode_compareint.h"
#include "skill_psnode_costbuffattribute.h"
#include "skill_psnode_delay.h"
#include "skill_psnode_detect.h"
#include "skill_psnode_disable.h"
#include "skill_psnode_endphase.h"
#include "skill_psnode_getactorattribute.h"
#include "skill_psnode_getbuffattribute.h"
#include "skill_psnode_getlocation.h"
#include "skill_psnode_if.h"
#include "skill_psnode_isinterrupttype.h"
#include "skill_psnode_playanimation.h"
#include "skill_psnode_playeffect.h"
#include "skill_psnode_playsound.h"
#include "skill_psnode_raiseevent.h"
#include "skill_psnode_resetcd.h"
#include "skill_psnode_setbool.h"
#include "skill_psnode_startphase.h"
#include "skill_psnode_startpreinput.h"
#include "skill_psnode_switchtoint.h"

namespace pvp {

//变量声明
uint64_t Variable_10162_HaveEnergy = 0;
uint64_t Variable_10162_stop = 0;
uint64_t Variable_10162_InterruptAnimat = 0;
//--------------------------------------------------------------------------------
// StartPhase
//
REGISTER_REGISTER_SKILL_NODE(10162, 3) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_StartPhase::TRIGGER_START, 55, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(10162, 3) {
    auto node3 = GET_SKILL_NODE(3, PhaseNode_StartPhase);
    if (node3 == nullptr) {
        node3 = new PhaseNode_StartPhase(3, phase);
        CALL_REGISTER_SKILL_NODE(10162, 3, node3)
    }
    if (noInit == true) {
        return node3;
    }
    return node3;
}
//--------------------------------------------------------------------------------
// Disable
//
REGISTER_REGISTER_SKILL_NODE(10162, 8) {
    pnode->resizeTrigger(PhaseNode_Disable::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_Disable::TRIGGER_DONE, 10, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_Disable::TRIGGER_DONE, 54, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_Disable::TRIGGER_DONE, 63, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10162, 8) {
    auto node8 = GET_SKILL_NODE(8, PhaseNode_Disable);
    if (node8 == nullptr) {
        node8 = new PhaseNode_Disable(8, phase);
        node8->setTarget(0U);
        node8->setMove(false);
        node8->setSkill(true);
        node8->setShoot(true);
        node8->setTime(1.00f);
        node8->setRotate(false);
        CALL_REGISTER_SKILL_NODE(10162, 8, node8)
    }
    if (noInit == true) {
        return node8;
    }
    return node8;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10162, 10) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_Delay::TRIGGER_DONE, 32, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(10162, 10) {
    auto node10 = GET_SKILL_NODE(10, PhaseNode_Delay);
    if (node10 == nullptr) {
        node10 = new PhaseNode_Delay(10, phase);
        node10->setTime(1.26f);
        CALL_REGISTER_SKILL_NODE(10162, 10, node10)
    }
    if (noInit == true) {
        return node10;
    }
    return node10;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10162, 16) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetBuffAttribute>(PhaseNode_Delay::TRIGGER_DONE, 36, PhaseNode_GetBuffAttribute::FUNC_DO, &PhaseNode_GetBuffAttribute::Do);
}

REGISTER_CREATE_SKILL_NODE(10162, 16) {
    auto node16 = GET_SKILL_NODE(16, PhaseNode_Delay);
    if (node16 == nullptr) {
        node16 = new PhaseNode_Delay(16, phase);
        node16->setTime(.40f);
        CALL_REGISTER_SKILL_NODE(10162, 16, node16)
    }
    if (noInit == true) {
        return node16;
    }
    return node16;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(10162, 18) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AreaCollisionNewPene>(PhaseNode_GetLocation::TRIGGER_DONE, 26, PhaseNode_AreaCollisionNewPene::FUNC_DO, &PhaseNode_AreaCollisionNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(10162, 18) {
    auto node18 = GET_SKILL_NODE(18, PhaseNode_GetLocation);
    if (node18 == nullptr) {
        node18 = new PhaseNode_GetLocation(18, phase);
        node18->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node18->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(10162, 18, node18)
    }
    if (noInit == true) {
        return node18;
    }
    return node18;
}
//--------------------------------------------------------------------------------
// AreaCollisionNewPene
//
REGISTER_REGISTER_SKILL_NODE(10162, 26) {
    pnode->resizeTrigger(PhaseNode_AreaCollisionNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_AreaCollisionNewPene::TRIGGER_DONE, 43, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(10162, 26) {
    auto node26 = GET_SKILL_NODE(26, PhaseNode_AreaCollisionNewPene);
    if (node26 == nullptr) {
        node26 = new PhaseNode_AreaCollisionNewPene(26, phase);
        node26->setState(PhaseNode_AreaCollisionNewPene::AreaCollisionNewPene_State::Alive);
        node26->setFaction(PhaseNode_AreaCollisionNewPene::AreaCollisionNewPene_Faction::Friend);
        node26->setOnHero(true);
        node26->setOnMinion(false);
        node26->setOnDestruct(false);
        node26->setOnShield(false);
        node26->setType(PhaseNode_AreaCollisionNewPene::AreaCollisionNewPene_Type::Circle);
        node26->setTypeParams(0, 8.00f);
        node26->setPositionZ(.00f);
        node26->setRotation(.00f);
        CALL_REGISTER_SKILL_NODE(10162, 26, node26)
    }
    if (noInit == true) {
        return node26;
    }
    auto node18 = GET_SKILL_NODE(18, PhaseNode_GetLocation);
    if (node18 != nullptr) node26->setPositionX(node18->getX());
    if (node18 != nullptr) node26->setPositionY(node18->getY());
    return node26;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(10162, 28) {
}

REGISTER_CREATE_SKILL_NODE(10162, 28) {
    auto node28 = GET_SKILL_NODE(28, PhaseNode_AddSkillBuffs);
    if (node28 == nullptr) {
        node28 = new PhaseNode_AddSkillBuffs(28, phase);
        node28->setConfigID({101621,101622});
        CALL_REGISTER_SKILL_NODE(10162, 28, node28)
    }
    if (noInit == true) {
        return node28;
    }
    auto node26 = GET_SKILL_NODE(26, PhaseNode_AreaCollisionNewPene);
    auto node58 = GET_SKILL_NODE(58, PhaseNode_GetActorAttribute);
    if (node26 != nullptr) node28->setTarget(node26->getColliders());
    if (node58 != nullptr) node28->setAttribute(node58->getAttribute());
    return node28;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(10162, 30) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_PlayEffect::TRIGGER_DONE, 50, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
}

REGISTER_CREATE_SKILL_NODE(10162, 30) {
    auto node30 = GET_SKILL_NODE(30, PhaseNode_PlayEffect);
    if (node30 == nullptr) {
        node30 = new PhaseNode_PlayEffect(30, phase);
        node30->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node30->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node30->setEffectID(101621);
        node30->setChangeColor(true);
        node30->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node30->getVars().reserve(3);
        node30->getVars().setVariable<float>(0, .00f);
        node30->getVars().setVariable<float>(1, .00f);
        node30->getVars().setVariable<float>(2, .00f);
        node30->setRotation(.00f);
        node30->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(10162, 30, node30)
    }
    if (noInit == true) {
        return node30;
    }
    auto node18 = GET_SKILL_NODE(18, PhaseNode_GetLocation);
    if (node18 != nullptr) node30->getVars().setVariable<float>(0, node18->getX());
    if (node18 != nullptr) node30->getVars().setVariable<float>(1, node18->getY());
    return node30;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(10162, 32) {
}

REGISTER_CREATE_SKILL_NODE(10162, 32) {
    auto node32 = GET_SKILL_NODE(32, PhaseNode_EndPhase);
    if (node32 == nullptr) {
        node32 = new PhaseNode_EndPhase(32, phase);
        node32->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node32->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10162, 32, node32)
    }
    if (noInit == true) {
        return node32;
    }
    return node32;
}
//--------------------------------------------------------------------------------
// GetBuffAttribute
//
REGISTER_REGISTER_SKILL_NODE(10162, 36) {
    pnode->resizeTrigger(PhaseNode_GetBuffAttribute::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareInt>(PhaseNode_GetBuffAttribute::TRIGGER_DONE, 37, PhaseNode_CompareInt::FUNC_COMPARE, &PhaseNode_CompareInt::Compare);
}

REGISTER_CREATE_SKILL_NODE(10162, 36) {
    auto node36 = GET_SKILL_NODE(36, PhaseNode_GetBuffAttribute);
    if (node36 == nullptr) {
        node36 = new PhaseNode_GetBuffAttribute(36, phase);
        node36->setTarget(0U);
        node36->setAttribute(45);
        CALL_REGISTER_SKILL_NODE(10162, 36, node36)
    }
    if (noInit == true) {
        return node36;
    }
    return node36;
}
//--------------------------------------------------------------------------------
// CompareInt
//
REGISTER_REGISTER_SKILL_NODE(10162, 37) {
    pnode->resizeTrigger(PhaseNode_CompareInt::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CostBuffAttribute>(PhaseNode_CompareInt::TRIGGER_EQUAL, 38, PhaseNode_CostBuffAttribute::FUNC_DO, &PhaseNode_CostBuffAttribute::Do);
    pnode->regTrigger<PhaseNode_CostBuffAttribute>(PhaseNode_CompareInt::TRIGGER_GREATER, 38, PhaseNode_CostBuffAttribute::FUNC_DO, &PhaseNode_CostBuffAttribute::Do);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_CompareInt::TRIGGER_LESS, 18, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(10162, 37) {
    auto node37 = GET_SKILL_NODE(37, PhaseNode_CompareInt);
    if (node37 == nullptr) {
        node37 = new PhaseNode_CompareInt(37, phase);
        node37->setB(5000);
        CALL_REGISTER_SKILL_NODE(10162, 37, node37)
    }
    if (noInit == true) {
        return node37;
    }
    auto node36 = GET_SKILL_NODE(36, PhaseNode_GetBuffAttribute);
    if (node36 != nullptr) node37->setA(node36->getValue());
    return node37;
}
//--------------------------------------------------------------------------------
// CostBuffAttribute
//
REGISTER_REGISTER_SKILL_NODE(10162, 38) {
    pnode->resizeTrigger(PhaseNode_CostBuffAttribute::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_CostBuffAttribute::TRIGGER_DONE, 39, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(10162, 38) {
    auto node38 = GET_SKILL_NODE(38, PhaseNode_CostBuffAttribute);
    if (node38 == nullptr) {
        node38 = new PhaseNode_CostBuffAttribute(38, phase);
        node38->setTarget(0U);
        node38->setAttribute(45);
        node38->setValue(5000);
        CALL_REGISTER_SKILL_NODE(10162, 38, node38)
    }
    if (noInit == true) {
        return node38;
    }
    return node38;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(10162, 39) {
    pnode->resizeTrigger(PhaseNode_SetBool::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_SetBool::TRIGGER_DONE, 18, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(10162, 39) {
    auto node39 = GET_SKILL_NODE(39, PhaseNode_SetBool);
    if (node39 == nullptr) {
        node39 = new PhaseNode_SetBool(39, phase);
        node39->setName("HaveEnergy");
        node39->setValue(true);
        CALL_REGISTER_SKILL_NODE(10162, 39, node39)
    }
    if (noInit == true) {
        return node39;
    }
    return node39;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(10162, 43) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_FALSE, 30, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_TRUE, 52, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(10162, 43) {
    auto node43 = GET_SKILL_NODE(43, PhaseNode_If);
    if (node43 == nullptr) {
        node43 = new PhaseNode_If(43, phase);
        CALL_REGISTER_SKILL_NODE(10162, 43, node43)
    }
    if (noInit == true) {
        return node43;
    }
    auto variables = node43->getVariables();
    if (variables != nullptr) {
        node43->setCondition(variables->getVariable<bool>(Variable_10162_HaveEnergy));
    }
    return node43;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(10162, 50) {
}

REGISTER_CREATE_SKILL_NODE(10162, 50) {
    auto node50 = GET_SKILL_NODE(50, PhaseNode_AddSkillBuffs);
    if (node50 == nullptr) {
        node50 = new PhaseNode_AddSkillBuffs(50, phase);
        node50->setConfigID({101622});
        CALL_REGISTER_SKILL_NODE(10162, 50, node50)
    }
    if (noInit == true) {
        return node50;
    }
    auto node26 = GET_SKILL_NODE(26, PhaseNode_AreaCollisionNewPene);
    auto node58 = GET_SKILL_NODE(58, PhaseNode_GetActorAttribute);
    if (node26 != nullptr) node50->setTarget(node26->getColliders());
    if (node58 != nullptr) node50->setAttribute(node58->getAttribute());
    return node50;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(10162, 52) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_PlayEffect::TRIGGER_DONE, 28, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
}

REGISTER_CREATE_SKILL_NODE(10162, 52) {
    auto node52 = GET_SKILL_NODE(52, PhaseNode_PlayEffect);
    if (node52 == nullptr) {
        node52 = new PhaseNode_PlayEffect(52, phase);
        node52->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node52->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node52->setEffectID(101624);
        node52->setChangeColor(true);
        node52->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node52->getVars().reserve(3);
        node52->getVars().setVariable<float>(0, .00f);
        node52->getVars().setVariable<float>(1, .00f);
        node52->getVars().setVariable<float>(2, .00f);
        node52->setRotation(.00f);
        node52->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(10162, 52, node52)
    }
    if (noInit == true) {
        return node52;
    }
    auto node18 = GET_SKILL_NODE(18, PhaseNode_GetLocation);
    if (node18 != nullptr) node52->getVars().setVariable<float>(0, node18->getX());
    if (node18 != nullptr) node52->getVars().setVariable<float>(1, node18->getY());
    return node52;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10162, 54) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlaySound::TRIGGER_DONE, 16, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10162, 54) {
    auto node54 = GET_SKILL_NODE(54, PhaseNode_PlaySound);
    if (node54 == nullptr) {
        node54 = new PhaseNode_PlaySound(54, phase);
        node54->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node54->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node54->setSoundID("SE_Hero135_SkillB");
        node54->setTarget(0U);
        node54->setUsePos(false);
        node54->setPosX(.00f);
        node54->setPosY(.00f);
        node54->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10162, 54, node54)
    }
    if (noInit == true) {
        return node54;
    }
    return node54;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(10162, 55) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_ResetCD::TRIGGER_DONE, 56, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10162, 55) {
    auto node55 = GET_SKILL_NODE(55, PhaseNode_ResetCD);
    if (node55 == nullptr) {
        node55 = new PhaseNode_ResetCD(55, phase);
        node55->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node55->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node55->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(10162, 55, node55)
    }
    if (noInit == true) {
        return node55;
    }
    return node55;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10162, 56) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_PlayAnimation::TRIGGER_DONE, 58, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(10162, 56) {
    auto node56 = GET_SKILL_NODE(56, PhaseNode_PlayAnimation);
    if (node56 == nullptr) {
        node56 = new PhaseNode_PlayAnimation(56, phase);
        node56->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node56->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node56->setTarget(0U);
        node56->setAnimation("Skill2S1");
        node56->setParameter("SkillArmBusy");
        node56->setValue(true);
        CALL_REGISTER_SKILL_NODE(10162, 56, node56)
    }
    if (noInit == true) {
        return node56;
    }
    return node56;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10162, 57) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Disable>(PhaseNode_PlaySound::TRIGGER_DONE, 8, PhaseNode_Disable::FUNC_DO, &PhaseNode_Disable::Do);
}

REGISTER_CREATE_SKILL_NODE(10162, 57) {
    auto node57 = GET_SKILL_NODE(57, PhaseNode_PlaySound);
    if (node57 == nullptr) {
        node57 = new PhaseNode_PlaySound(57, phase);
        node57->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node57->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node57->setSoundID("");
        node57->setTarget(0U);
        node57->setUsePos(false);
        node57->setPosX(.00f);
        node57->setPosY(.00f);
        node57->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10162, 57, node57)
    }
    if (noInit == true) {
        return node57;
    }
    return node57;
}
//--------------------------------------------------------------------------------
// GetActorAttribute
//
REGISTER_REGISTER_SKILL_NODE(10162, 58) {
    pnode->resizeTrigger(PhaseNode_GetActorAttribute::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 57, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10162, 58) {
    auto node58 = GET_SKILL_NODE(58, PhaseNode_GetActorAttribute);
    if (node58 == nullptr) {
        node58 = new PhaseNode_GetActorAttribute(58, phase);
        node58->setTarget(0U);
        node58->setType({});
        CALL_REGISTER_SKILL_NODE(10162, 58, node58)
    }
    if (noInit == true) {
        return node58;
    }
    return node58;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10162, 60) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_IsInterruptType>(PhaseNode_Detect::TRIGGER_ON, 66, PhaseNode_IsInterruptType::FUNC_DO, &PhaseNode_IsInterruptType::Do);
}

REGISTER_CREATE_SKILL_NODE(10162, 60) {
    auto node60 = GET_SKILL_NODE(60, PhaseNode_Detect);
    if (node60 == nullptr) {
        node60 = new PhaseNode_Detect(60, phase);
        node60->setSelf(0U);
        node60->setEvent("daduan_001");
        node60->setType(PhaseNode_Detect::Detect_Type::Interrupt_Skill);
        node60->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10162, 60, node60)
    }
    if (noInit == true) {
        return node60;
    }
    return node60;
}
//--------------------------------------------------------------------------------
// SwitchToInt
//
REGISTER_REGISTER_SKILL_NODE(10162, 61) {
    pnode->resizeTrigger(4);
    pnode->regTrigger<PhaseNode_EndPhase>(1, 32, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(10162, 61) {
    auto node61 = GET_SKILL_NODE(61, PhaseNode_SwitchToInt);
    if (node61 == nullptr) {
        node61 = new PhaseNode_SwitchToInt(61, phase);
        CALL_REGISTER_SKILL_NODE(10162, 61, node61)
    }
    if (noInit == true) {
        return node61;
    }
    auto variables = node61->getVariables();
    if (variables != nullptr) {
        node61->setSelection(variables->getVariable<int32_t>(Variable_10162_stop));
    }
    return node61;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10162, 63) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_RaiseEvent::TRIGGER_DONE, 72, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10162, 63) {
    auto node63 = GET_SKILL_NODE(63, PhaseNode_RaiseEvent);
    if (node63 == nullptr) {
        node63 = new PhaseNode_RaiseEvent(63, phase);
        node63->setEvent("daduan_001");
        node63->setTarget(0U);
        node63->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node63->setTypeParams(0, 0);
        node63->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10162, 63, node63)
    }
    if (noInit == true) {
        return node63;
    }
    return node63;
}
//--------------------------------------------------------------------------------
// StartPreInput
//
REGISTER_REGISTER_SKILL_NODE(10162, 64) {
    pnode->resizeTrigger(PhaseNode_StartPreInput::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_StartPreInput::TRIGGER_DONE, 68, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10162, 64) {
    auto node64 = GET_SKILL_NODE(64, PhaseNode_StartPreInput);
    if (node64 == nullptr) {
        node64 = new PhaseNode_StartPreInput(64, phase);
        node64->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node64->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node64->setDelayTime(.00f);
        CALL_REGISTER_SKILL_NODE(10162, 64, node64)
    }
    if (noInit == true) {
        return node64;
    }
    return node64;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(10162, 65) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_If::TRIGGER_TRUE, 67, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10162, 65) {
    auto node65 = GET_SKILL_NODE(65, PhaseNode_If);
    if (node65 == nullptr) {
        node65 = new PhaseNode_If(65, phase);
        CALL_REGISTER_SKILL_NODE(10162, 65, node65)
    }
    if (noInit == true) {
        return node65;
    }
    auto variables = node65->getVariables();
    if (variables != nullptr) {
        node65->setCondition(variables->getVariable<bool>(Variable_10162_InterruptAnimat));
    }
    return node65;
}
//--------------------------------------------------------------------------------
// IsInterruptType
//
REGISTER_REGISTER_SKILL_NODE(10162, 66) {
    pnode->resizeTrigger(PhaseNode_IsInterruptType::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SwitchToInt>(PhaseNode_IsInterruptType::TRIGGER_BUFF, 61, PhaseNode_SwitchToInt::FUNC_SWITCH, &PhaseNode_SwitchToInt::Switch);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_POSCHANGE, 65, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTAIM, 65, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTFIRE, 65, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTRELOAD, 65, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_USESKILL, 65, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(10162, 66) {
    auto node66 = GET_SKILL_NODE(66, PhaseNode_IsInterruptType);
    if (node66 == nullptr) {
        node66 = new PhaseNode_IsInterruptType(66, phase);
        node66->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node66->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10162, 66, node66)
    }
    if (noInit == true) {
        return node66;
    }
    auto node60 = GET_SKILL_NODE(60, PhaseNode_Detect);
    if (node60 != nullptr) node66->setType(node60->getVars().getVariable<int32_t>(2));
    return node66;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10162, 67) {
}

REGISTER_CREATE_SKILL_NODE(10162, 67) {
    auto node67 = GET_SKILL_NODE(67, PhaseNode_PlayAnimation);
    if (node67 == nullptr) {
        node67 = new PhaseNode_PlayAnimation(67, phase);
        node67->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node67->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node67->setTarget(0U);
        node67->setAnimation("Idle");
        node67->setParameter("");
        node67->setValue(false);
        CALL_REGISTER_SKILL_NODE(10162, 67, node67)
    }
    if (noInit == true) {
        return node67;
    }
    return node67;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10162, 68) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_Delay::TRIGGER_DONE, 71, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(10162, 68) {
    auto node68 = GET_SKILL_NODE(68, PhaseNode_Delay);
    if (node68 == nullptr) {
        node68 = new PhaseNode_Delay(68, phase);
        node68->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(10162, 68, node68)
    }
    if (noInit == true) {
        return node68;
    }
    return node68;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(10162, 71) {
}

REGISTER_CREATE_SKILL_NODE(10162, 71) {
    auto node71 = GET_SKILL_NODE(71, PhaseNode_SetBool);
    if (node71 == nullptr) {
        node71 = new PhaseNode_SetBool(71, phase);
        node71->setName("InterruptAnimat");
        node71->setValue(true);
        CALL_REGISTER_SKILL_NODE(10162, 71, node71)
    }
    if (noInit == true) {
        return node71;
    }
    return node71;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10162, 72) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StartPreInput>(PhaseNode_RaiseEvent::TRIGGER_DONE, 64, PhaseNode_StartPreInput::FUNC_DO, &PhaseNode_StartPreInput::Do);
}

REGISTER_CREATE_SKILL_NODE(10162, 72) {
    auto node72 = GET_SKILL_NODE(72, PhaseNode_RaiseEvent);
    if (node72 == nullptr) {
        node72 = new PhaseNode_RaiseEvent(72, phase);
        node72->setEvent("Dead_001");
        node72->setTarget(0U);
        node72->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node72->setTypeParams(0, 0);
        node72->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10162, 72, node72)
    }
    if (noInit == true) {
        return node72;
    }
    return node72;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10162, 73) {
}

REGISTER_CREATE_SKILL_NODE(10162, 73) {
    auto node73 = GET_SKILL_NODE(73, PhaseNode_Detect);
    if (node73 == nullptr) {
        node73 = new PhaseNode_Detect(73, phase);
        node73->setSelf(0U);
        node73->setEvent("Dead_001");
        node73->setType(PhaseNode_Detect::Detect_Type::Actor_Dead);
        node73->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10162, 73, node73)
    }
    if (noInit == true) {
        return node73;
    }
    return node73;
}

//--------------------------------------------------------------------------------
// SkillCreator_10162
//
class SkillCreator_10162 : public SkillCreator {
public:
    SkillCreator_10162() {}
    virtual ~SkillCreator_10162() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_10162

//--------------------------------------------------------------------------------
// SkillPhase_10162
//
class SkillPhase_10162 : public SkillPhase {
public:
    SkillPhase_10162(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_10162() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(10162, 3) // StartPhase
        CASE_CREATE_SKILL_NODE(10162, 8) // Disable
        CASE_CREATE_SKILL_NODE(10162, 10) // Delay
        CASE_CREATE_SKILL_NODE(10162, 16) // Delay
        CASE_CREATE_SKILL_NODE(10162, 18) // GetLocation
        CASE_CREATE_SKILL_NODE(10162, 26) // AreaCollisionNewPene
        CASE_CREATE_SKILL_NODE(10162, 28) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(10162, 30) // PlayEffect
        CASE_CREATE_SKILL_NODE(10162, 32) // EndPhase
        CASE_CREATE_SKILL_NODE(10162, 36) // GetBuffAttribute
        CASE_CREATE_SKILL_NODE(10162, 37) // CompareInt
        CASE_CREATE_SKILL_NODE(10162, 38) // CostBuffAttribute
        CASE_CREATE_SKILL_NODE(10162, 39) // SetBool
        CASE_CREATE_SKILL_NODE(10162, 43) // If
        CASE_CREATE_SKILL_NODE(10162, 50) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(10162, 52) // PlayEffect
        CASE_CREATE_SKILL_NODE(10162, 54) // PlaySound
        CASE_CREATE_SKILL_NODE(10162, 55) // ResetCD
        CASE_CREATE_SKILL_NODE(10162, 56) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10162, 57) // PlaySound
        CASE_CREATE_SKILL_NODE(10162, 58) // GetActorAttribute
        CASE_CREATE_SKILL_NODE(10162, 60) // Detect
        CASE_CREATE_SKILL_NODE(10162, 61) // SwitchToInt
        CASE_CREATE_SKILL_NODE(10162, 63) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10162, 64) // StartPreInput
        CASE_CREATE_SKILL_NODE(10162, 65) // If
        CASE_CREATE_SKILL_NODE(10162, 66) // IsInterruptType
        CASE_CREATE_SKILL_NODE(10162, 67) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10162, 68) // Delay
        CASE_CREATE_SKILL_NODE(10162, 71) // SetBool
        CASE_CREATE_SKILL_NODE(10162, 72) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10162, 73) // Detect
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_10162

SkillLogic* SkillCreator_10162::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //设置变量
    Variable_10162_HaveEnergy = logic->getVariables().setVariable<bool>("HaveEnergy");
    Variable_10162_stop = logic->getVariables().setVariable<int32_t>("stop", 1);
    Variable_10162_InterruptAnimat = logic->getVariables().setVariable<bool>("InterruptAnimat");
    //创建阶段phase
    auto phase = new SkillPhase_10162(1, logic, 2);
    //设置phase执行器
    phase->setRunPhaseNode(1, 3);
    phase->setDetectPhaseNode(2, 60);
    phase->setDetectPhaseNode(2, 73);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_10162::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
