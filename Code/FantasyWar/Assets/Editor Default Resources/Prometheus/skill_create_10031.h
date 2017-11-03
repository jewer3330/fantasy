#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

#include "skill_psnode_addskillbuff.h"
#include "skill_psnode_areacollisionnewpene.h"
#include "skill_psnode_damagereduce.h"
#include "skill_psnode_delay.h"
#include "skill_psnode_detect.h"
#include "skill_psnode_disable.h"
#include "skill_psnode_endphase.h"
#include "skill_psnode_for.h"
#include "skill_psnode_forcontinue.h"
#include "skill_psnode_getactorattribute.h"
#include "skill_psnode_getlocation.h"
#include "skill_psnode_getuint64svalue.h"
#include "skill_psnode_if.h"
#include "skill_psnode_isinterrupttype.h"
#include "skill_psnode_linechecknewpene.h"
#include "skill_psnode_playanimation.h"
#include "skill_psnode_playsound.h"
#include "skill_psnode_raiseevent.h"
#include "skill_psnode_removeskillbuff.h"
#include "skill_psnode_resetcd.h"
#include "skill_psnode_revisemapi32.h"
#include "skill_psnode_setbool.h"
#include "skill_psnode_startphase.h"
#include "skill_psnode_startpreinput.h"
#include "skill_psnode_switchtoint.h"
#include "skill_psnode_timedown.h"
#include "skill_psnode_triggerupdate.h"
#include "skill_psnode_uint64ssize.h"

namespace pvp {

//变量声明
uint64_t Variable_10031_a100312 = 0;
uint64_t Variable_10031_InterruptAnimat = 0;
//--------------------------------------------------------------------------------
// StartPhase
//
REGISTER_REGISTER_SKILL_NODE(10031, 76) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_StartPhase::TRIGGER_START, 214, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(10031, 76) {
    auto node76 = GET_SKILL_NODE(76, PhaseNode_StartPhase);
    if (node76 == nullptr) {
        node76 = new PhaseNode_StartPhase(76, phase);
        CALL_REGISTER_SKILL_NODE(10031, 76, node76)
    }
    if (noInit == true) {
        return node76;
    }
    return node76;
}
//--------------------------------------------------------------------------------
// TriggerUpdate
//
REGISTER_REGISTER_SKILL_NODE(10031, 78) {
}

REGISTER_CREATE_SKILL_NODE(10031, 78) {
    auto node78 = GET_SKILL_NODE(78, PhaseNode_TriggerUpdate);
    if (node78 == nullptr) {
        node78 = new PhaseNode_TriggerUpdate(78, phase);
        CALL_REGISTER_SKILL_NODE(10031, 78, node78)
    }
    if (noInit == true) {
        return node78;
    }
    return node78;
}
//--------------------------------------------------------------------------------
// Disable
//
REGISTER_REGISTER_SKILL_NODE(10031, 98) {
    pnode->resizeTrigger(PhaseNode_Disable::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuff>(PhaseNode_Disable::TRIGGER_DONE, 102, PhaseNode_AddSkillBuff::FUNC_ADD, &PhaseNode_AddSkillBuff::Add);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_Disable::TRIGGER_DONE, 222, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
    pnode->regTrigger<PhaseNode_TimeDown>(PhaseNode_Disable::TRIGGER_DONE, 209, PhaseNode_TimeDown::FUNC_DO, &PhaseNode_TimeDown::Do);
}

REGISTER_CREATE_SKILL_NODE(10031, 98) {
    auto node98 = GET_SKILL_NODE(98, PhaseNode_Disable);
    if (node98 == nullptr) {
        node98 = new PhaseNode_Disable(98, phase);
        node98->setTarget(0U);
        node98->setMove(false);
        node98->setSkill(true);
        node98->setShoot(true);
        node98->setTime(.75f);
        node98->setRotate(true);
        CALL_REGISTER_SKILL_NODE(10031, 98, node98)
    }
    if (noInit == true) {
        return node98;
    }
    return node98;
}
//--------------------------------------------------------------------------------
// AddSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10031, 102) {
    pnode->resizeTrigger(PhaseNode_AddSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_AddSkillBuff::TRIGGER_DONE, 113, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10031, 102) {
    auto node102 = GET_SKILL_NODE(102, PhaseNode_AddSkillBuff);
    if (node102 == nullptr) {
        node102 = new PhaseNode_AddSkillBuff(102, phase);
        node102->setConfigID(100311);
        node102->setConfigIDs({});
        node102->setTarget(0U);
        node102->setAttribute({{}});
        CALL_REGISTER_SKILL_NODE(10031, 102, node102)
    }
    if (noInit == true) {
        return node102;
    }
    return node102;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10031, 113) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RemoveSkillBuff>(PhaseNode_Delay::TRIGGER_DONE, 171, PhaseNode_RemoveSkillBuff::FUNC_REMOVE, &PhaseNode_RemoveSkillBuff::Remove);
}

REGISTER_CREATE_SKILL_NODE(10031, 113) {
    auto node113 = GET_SKILL_NODE(113, PhaseNode_Delay);
    if (node113 == nullptr) {
        node113 = new PhaseNode_Delay(113, phase);
        node113->setTime(1.00f);
        CALL_REGISTER_SKILL_NODE(10031, 113, node113)
    }
    if (noInit == true) {
        return node113;
    }
    return node113;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(10031, 117) {
}

REGISTER_CREATE_SKILL_NODE(10031, 117) {
    auto node117 = GET_SKILL_NODE(117, PhaseNode_EndPhase);
    if (node117 == nullptr) {
        node117 = new PhaseNode_EndPhase(117, phase);
        node117->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node117->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10031, 117, node117)
    }
    if (noInit == true) {
        return node117;
    }
    return node117;
}
//--------------------------------------------------------------------------------
// UInt64sSize
//
REGISTER_REGISTER_SKILL_NODE(10031, 121) {
    pnode->resizeTrigger(PhaseNode_UInt64sSize::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_For>(PhaseNode_UInt64sSize::TRIGGER_DONE, 123, PhaseNode_For::FUNC_START, &PhaseNode_For::Start);
}

REGISTER_CREATE_SKILL_NODE(10031, 121) {
    auto node121 = GET_SKILL_NODE(121, PhaseNode_UInt64sSize);
    if (node121 == nullptr) {
        node121 = new PhaseNode_UInt64sSize(121, phase);
        CALL_REGISTER_SKILL_NODE(10031, 121, node121)
    }
    if (noInit == true) {
        return node121;
    }
    auto node213 = GET_SKILL_NODE(213, PhaseNode_LineCheckNewPene);
    if (node213 != nullptr) node121->setArr(node213->getOutput());
    return node121;
}
//--------------------------------------------------------------------------------
// For
//
REGISTER_REGISTER_SKILL_NODE(10031, 123) {
    pnode->resizeTrigger(PhaseNode_For::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetUInt64sValue>(PhaseNode_For::TRIGGER_DO, 125, PhaseNode_GetUInt64sValue::FUNC_DO, &PhaseNode_GetUInt64sValue::Do);
}

REGISTER_CREATE_SKILL_NODE(10031, 123) {
    auto node123 = GET_SKILL_NODE(123, PhaseNode_For);
    if (node123 == nullptr) {
        node123 = new PhaseNode_For(123, phase);
        node123->setBegin(0);
        node123->setIncrease(1);
        CALL_REGISTER_SKILL_NODE(10031, 123, node123)
    }
    if (noInit == true) {
        return node123;
    }
    auto node121 = GET_SKILL_NODE(121, PhaseNode_UInt64sSize);
    if (node121 != nullptr) node123->setEnd(node121->getSize());
    return node123;
}
//--------------------------------------------------------------------------------
// GetUInt64sValue
//
REGISTER_REGISTER_SKILL_NODE(10031, 125) {
    pnode->resizeTrigger(PhaseNode_GetUInt64sValue::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_DamageReduce>(PhaseNode_GetUInt64sValue::TRIGGER_DONE, 130, PhaseNode_DamageReduce::FUNC_DO, &PhaseNode_DamageReduce::Do);
}

REGISTER_CREATE_SKILL_NODE(10031, 125) {
    auto node125 = GET_SKILL_NODE(125, PhaseNode_GetUInt64sValue);
    if (node125 == nullptr) {
        node125 = new PhaseNode_GetUInt64sValue(125, phase);
        CALL_REGISTER_SKILL_NODE(10031, 125, node125)
    }
    if (noInit == true) {
        return node125;
    }
    auto node213 = GET_SKILL_NODE(213, PhaseNode_LineCheckNewPene);
    auto node123 = GET_SKILL_NODE(123, PhaseNode_For);
    if (node213 != nullptr) node125->setArr(node213->getOutput());
    if (node123 != nullptr) node125->setIndex(node123->getValue());
    return node125;
}
//--------------------------------------------------------------------------------
// DamageReduce
//
REGISTER_REGISTER_SKILL_NODE(10031, 130) {
    pnode->resizeTrigger(PhaseNode_DamageReduce::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ReviseMapI32>(PhaseNode_DamageReduce::TRIGGER_DONE, 132, PhaseNode_ReviseMapI32::FUNC_DO, &PhaseNode_ReviseMapI32::Do);
}

REGISTER_CREATE_SKILL_NODE(10031, 130) {
    auto node130 = GET_SKILL_NODE(130, PhaseNode_DamageReduce);
    if (node130 == nullptr) {
        node130 = new PhaseNode_DamageReduce(130, phase);
        node130->setOriginZ(.00f);
        node130->setReductionDist(3.50f);
        node130->setRate(.10f);
        node130->setMinRate(.80f);
        CALL_REGISTER_SKILL_NODE(10031, 130, node130)
    }
    if (noInit == true) {
        return node130;
    }
    auto node211 = GET_SKILL_NODE(211, PhaseNode_GetLocation);
    auto node125 = GET_SKILL_NODE(125, PhaseNode_GetUInt64sValue);
    if (node211 != nullptr) node130->setOriginX(node211->getX());
    if (node211 != nullptr) node130->setOriginY(node211->getY());
    if (node125 != nullptr) node130->setTarget(node125->getValue());
    return node130;
}
//--------------------------------------------------------------------------------
// ReviseMapI32
//
REGISTER_REGISTER_SKILL_NODE(10031, 132) {
    pnode->resizeTrigger(PhaseNode_ReviseMapI32::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuff>(PhaseNode_ReviseMapI32::TRIGGER_DONE, 134, PhaseNode_AddSkillBuff::FUNC_ADD, &PhaseNode_AddSkillBuff::Add);
}

REGISTER_CREATE_SKILL_NODE(10031, 132) {
    auto node132 = GET_SKILL_NODE(132, PhaseNode_ReviseMapI32);
    if (node132 == nullptr) {
        node132 = new PhaseNode_ReviseMapI32(132, phase);
        node132->reviseValue(201, .00f);
        CALL_REGISTER_SKILL_NODE(10031, 132, node132)
    }
    if (noInit == true) {
        return node132;
    }
    auto node217 = GET_SKILL_NODE(217, PhaseNode_GetActorAttribute);
    auto node130 = GET_SKILL_NODE(130, PhaseNode_DamageReduce);
    if (node217 != nullptr) node132->setInAttri(node217->getAttribute());
    if (node130 != nullptr) node132->reviseValue(201, node130->getRatio());
    return node132;
}
//--------------------------------------------------------------------------------
// AddSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10031, 134) {
    pnode->resizeTrigger(PhaseNode_AddSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ForContinue>(PhaseNode_AddSkillBuff::TRIGGER_DONE, 136, PhaseNode_ForContinue::FUNC_DO, &PhaseNode_ForContinue::Do);
}

REGISTER_CREATE_SKILL_NODE(10031, 134) {
    auto node134 = GET_SKILL_NODE(134, PhaseNode_AddSkillBuff);
    if (node134 == nullptr) {
        node134 = new PhaseNode_AddSkillBuff(134, phase);
        node134->setConfigID(100312);
        node134->setConfigIDs({});
        CALL_REGISTER_SKILL_NODE(10031, 134, node134)
    }
    if (noInit == true) {
        return node134;
    }
    auto node125 = GET_SKILL_NODE(125, PhaseNode_GetUInt64sValue);
    auto node132 = GET_SKILL_NODE(132, PhaseNode_ReviseMapI32);
    if (node125 != nullptr) node134->setTarget(node125->getValue());
    if (node132 != nullptr) node134->setAttribute(node132->getOutAttri());
    return node134;
}
//--------------------------------------------------------------------------------
// ForContinue
//
REGISTER_REGISTER_SKILL_NODE(10031, 136) {
}

REGISTER_CREATE_SKILL_NODE(10031, 136) {
    auto node136 = GET_SKILL_NODE(136, PhaseNode_ForContinue);
    if (node136 == nullptr) {
        node136 = new PhaseNode_ForContinue(136, phase);
        CALL_REGISTER_SKILL_NODE(10031, 136, node136)
    }
    if (noInit == true) {
        return node136;
    }
    auto node123 = GET_SKILL_NODE(123, PhaseNode_For);
    if (node123 != nullptr) node136->setFID(node123->getFID());
    return node136;
}
//--------------------------------------------------------------------------------
// RemoveSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10031, 171) {
    pnode->resizeTrigger(PhaseNode_RemoveSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_RemoveSkillBuff::TRIGGER_DONE, 117, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(10031, 171) {
    auto node171 = GET_SKILL_NODE(171, PhaseNode_RemoveSkillBuff);
    if (node171 == nullptr) {
        node171 = new PhaseNode_RemoveSkillBuff(171, phase);
        node171->setBuffID(0U);
        node171->setBuffIDs({});
        node171->setConfigID(100311);
        node171->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(10031, 171, node171)
    }
    if (noInit == true) {
        return node171;
    }
    return node171;
}
//--------------------------------------------------------------------------------
// AreaCollisionNewPene
//
REGISTER_REGISTER_SKILL_NODE(10031, 206) {
    pnode->resizeTrigger(PhaseNode_AreaCollisionNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_LineCheckNewPene>(PhaseNode_AreaCollisionNewPene::TRIGGER_DONE, 213, PhaseNode_LineCheckNewPene::FUNC_DO, &PhaseNode_LineCheckNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(10031, 206) {
    auto node206 = GET_SKILL_NODE(206, PhaseNode_AreaCollisionNewPene);
    if (node206 == nullptr) {
        node206 = new PhaseNode_AreaCollisionNewPene(206, phase);
        node206->setState(PhaseNode_AreaCollisionNewPene::AreaCollisionNewPene_State::Alive);
        node206->setFaction(PhaseNode_AreaCollisionNewPene::AreaCollisionNewPene_Faction::Enemy);
        node206->setOnHero(true);
        node206->setOnMinion(true);
        node206->setOnDestruct(true);
        node206->setOnShield(true);
        node206->setType(PhaseNode_AreaCollisionNewPene::AreaCollisionNewPene_Type::Circle);
        node206->setTypeParams(0, 6.00f);
        node206->setPositionZ(.00f);
        node206->setRotation(.00f);
        CALL_REGISTER_SKILL_NODE(10031, 206, node206)
    }
    if (noInit == true) {
        return node206;
    }
    auto node211 = GET_SKILL_NODE(211, PhaseNode_GetLocation);
    if (node211 != nullptr) node206->setPositionX(node211->getX());
    if (node211 != nullptr) node206->setPositionY(node211->getY());
    return node206;
}
//--------------------------------------------------------------------------------
// TimeDown
//
REGISTER_REGISTER_SKILL_NODE(10031, 209) {
    pnode->resizeTrigger(PhaseNode_TimeDown::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_TimeDown::TRIGGER_DONE, 211, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(10031, 209) {
    auto node209 = GET_SKILL_NODE(209, PhaseNode_TimeDown);
    if (node209 == nullptr) {
        node209 = new PhaseNode_TimeDown(209, phase);
        node209->setTime(.20f);
        node209->setNum(4);
        node209->setIsImmediateFirst(true);
        CALL_REGISTER_SKILL_NODE(10031, 209, node209)
    }
    if (noInit == true) {
        return node209;
    }
    return node209;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(10031, 211) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AreaCollisionNewPene>(PhaseNode_GetLocation::TRIGGER_DONE, 206, PhaseNode_AreaCollisionNewPene::FUNC_DO, &PhaseNode_AreaCollisionNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(10031, 211) {
    auto node211 = GET_SKILL_NODE(211, PhaseNode_GetLocation);
    if (node211 == nullptr) {
        node211 = new PhaseNode_GetLocation(211, phase);
        node211->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node211->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(10031, 211, node211)
    }
    if (noInit == true) {
        return node211;
    }
    return node211;
}
//--------------------------------------------------------------------------------
// LineCheckNewPene
//
REGISTER_REGISTER_SKILL_NODE(10031, 213) {
    pnode->resizeTrigger(PhaseNode_LineCheckNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_UInt64sSize>(PhaseNode_LineCheckNewPene::TRIGGER_DONE, 121, PhaseNode_UInt64sSize::FUNC_DO, &PhaseNode_UInt64sSize::Do);
}

REGISTER_CREATE_SKILL_NODE(10031, 213) {
    auto node213 = GET_SKILL_NODE(213, PhaseNode_LineCheckNewPene);
    if (node213 == nullptr) {
        node213 = new PhaseNode_LineCheckNewPene(213, phase);
        node213->setPeneProjectile(15);
        CALL_REGISTER_SKILL_NODE(10031, 213, node213)
    }
    if (noInit == true) {
        return node213;
    }
    auto node206 = GET_SKILL_NODE(206, PhaseNode_AreaCollisionNewPene);
    auto node211 = GET_SKILL_NODE(211, PhaseNode_GetLocation);
    if (node206 != nullptr) node213->setTargets(node206->getColliders());
    if (node211 != nullptr) node213->setFromX(node211->getX());
    if (node211 != nullptr) node213->setFromY(node211->getY());
    return node213;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(10031, 214) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_ResetCD::TRIGGER_DONE, 215, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10031, 214) {
    auto node214 = GET_SKILL_NODE(214, PhaseNode_ResetCD);
    if (node214 == nullptr) {
        node214 = new PhaseNode_ResetCD(214, phase);
        node214->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node214->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node214->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(10031, 214, node214)
    }
    if (noInit == true) {
        return node214;
    }
    return node214;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10031, 215) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_PlayAnimation::TRIGGER_DONE, 217, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(10031, 215) {
    auto node215 = GET_SKILL_NODE(215, PhaseNode_PlayAnimation);
    if (node215 == nullptr) {
        node215 = new PhaseNode_PlayAnimation(215, phase);
        node215->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node215->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node215->setTarget(0U);
        node215->setAnimation("Skill1S1");
        node215->setParameter("");
        node215->setValue(false);
        CALL_REGISTER_SKILL_NODE(10031, 215, node215)
    }
    if (noInit == true) {
        return node215;
    }
    return node215;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10031, 216) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Disable>(PhaseNode_PlaySound::TRIGGER_DONE, 98, PhaseNode_Disable::FUNC_DO, &PhaseNode_Disable::Do);
}

REGISTER_CREATE_SKILL_NODE(10031, 216) {
    auto node216 = GET_SKILL_NODE(216, PhaseNode_PlaySound);
    if (node216 == nullptr) {
        node216 = new PhaseNode_PlaySound(216, phase);
        node216->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node216->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node216->setSoundID("SE_Hero111_Skill_A");
        node216->setTarget(0U);
        node216->setUsePos(false);
        node216->setPosX(.00f);
        node216->setPosY(.00f);
        node216->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10031, 216, node216)
    }
    if (noInit == true) {
        return node216;
    }
    return node216;
}
//--------------------------------------------------------------------------------
// GetActorAttribute
//
REGISTER_REGISTER_SKILL_NODE(10031, 217) {
    pnode->resizeTrigger(PhaseNode_GetActorAttribute::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 216, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10031, 217) {
    auto node217 = GET_SKILL_NODE(217, PhaseNode_GetActorAttribute);
    if (node217 == nullptr) {
        node217 = new PhaseNode_GetActorAttribute(217, phase);
        node217->setTarget(0U);
        node217->setType({});
        CALL_REGISTER_SKILL_NODE(10031, 217, node217)
    }
    if (noInit == true) {
        return node217;
    }
    return node217;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10031, 219) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_IsInterruptType>(PhaseNode_Detect::TRIGGER_ON, 225, PhaseNode_IsInterruptType::FUNC_DO, &PhaseNode_IsInterruptType::Do);
}

REGISTER_CREATE_SKILL_NODE(10031, 219) {
    auto node219 = GET_SKILL_NODE(219, PhaseNode_Detect);
    if (node219 == nullptr) {
        node219 = new PhaseNode_Detect(219, phase);
        node219->setSelf(0U);
        node219->setEvent("daduan_001");
        node219->setType(PhaseNode_Detect::Detect_Type::Interrupt_Skill);
        node219->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10031, 219, node219)
    }
    if (noInit == true) {
        return node219;
    }
    return node219;
}
//--------------------------------------------------------------------------------
// SwitchToInt
//
REGISTER_REGISTER_SKILL_NODE(10031, 220) {
    pnode->resizeTrigger(4);
    pnode->regTrigger<PhaseNode_RemoveSkillBuff>(1, 171, PhaseNode_RemoveSkillBuff::FUNC_REMOVE, &PhaseNode_RemoveSkillBuff::Remove);
    pnode->regTrigger<PhaseNode_TimeDown>(1, 209, PhaseNode_TimeDown::FUNC_CANCEL, &PhaseNode_TimeDown::Cancel);
}

REGISTER_CREATE_SKILL_NODE(10031, 220) {
    auto node220 = GET_SKILL_NODE(220, PhaseNode_SwitchToInt);
    if (node220 == nullptr) {
        node220 = new PhaseNode_SwitchToInt(220, phase);
        CALL_REGISTER_SKILL_NODE(10031, 220, node220)
    }
    if (noInit == true) {
        return node220;
    }
    auto variables = node220->getVariables();
    if (variables != nullptr) {
        node220->setSelection(variables->getVariable<int32_t>(Variable_10031_a100312));
    }
    return node220;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10031, 222) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_RaiseEvent::TRIGGER_DONE, 231, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10031, 222) {
    auto node222 = GET_SKILL_NODE(222, PhaseNode_RaiseEvent);
    if (node222 == nullptr) {
        node222 = new PhaseNode_RaiseEvent(222, phase);
        node222->setEvent("daduan_001");
        node222->setTarget(0U);
        node222->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node222->setTypeParams(0, 0);
        node222->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10031, 222, node222)
    }
    if (noInit == true) {
        return node222;
    }
    return node222;
}
//--------------------------------------------------------------------------------
// StartPreInput
//
REGISTER_REGISTER_SKILL_NODE(10031, 223) {
    pnode->resizeTrigger(PhaseNode_StartPreInput::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_StartPreInput::TRIGGER_DONE, 227, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10031, 223) {
    auto node223 = GET_SKILL_NODE(223, PhaseNode_StartPreInput);
    if (node223 == nullptr) {
        node223 = new PhaseNode_StartPreInput(223, phase);
        node223->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node223->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node223->setDelayTime(.00f);
        CALL_REGISTER_SKILL_NODE(10031, 223, node223)
    }
    if (noInit == true) {
        return node223;
    }
    return node223;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(10031, 224) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_If::TRIGGER_TRUE, 226, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10031, 224) {
    auto node224 = GET_SKILL_NODE(224, PhaseNode_If);
    if (node224 == nullptr) {
        node224 = new PhaseNode_If(224, phase);
        CALL_REGISTER_SKILL_NODE(10031, 224, node224)
    }
    if (noInit == true) {
        return node224;
    }
    auto variables = node224->getVariables();
    if (variables != nullptr) {
        node224->setCondition(variables->getVariable<bool>(Variable_10031_InterruptAnimat));
    }
    return node224;
}
//--------------------------------------------------------------------------------
// IsInterruptType
//
REGISTER_REGISTER_SKILL_NODE(10031, 225) {
    pnode->resizeTrigger(PhaseNode_IsInterruptType::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SwitchToInt>(PhaseNode_IsInterruptType::TRIGGER_BUFF, 220, PhaseNode_SwitchToInt::FUNC_SWITCH, &PhaseNode_SwitchToInt::Switch);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_POSCHANGE, 224, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTAIM, 224, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTFIRE, 224, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTRELOAD, 224, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_USESKILL, 224, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(10031, 225) {
    auto node225 = GET_SKILL_NODE(225, PhaseNode_IsInterruptType);
    if (node225 == nullptr) {
        node225 = new PhaseNode_IsInterruptType(225, phase);
        node225->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node225->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10031, 225, node225)
    }
    if (noInit == true) {
        return node225;
    }
    auto node219 = GET_SKILL_NODE(219, PhaseNode_Detect);
    if (node219 != nullptr) node225->setType(node219->getVars().getVariable<int32_t>(2));
    return node225;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10031, 226) {
}

REGISTER_CREATE_SKILL_NODE(10031, 226) {
    auto node226 = GET_SKILL_NODE(226, PhaseNode_PlayAnimation);
    if (node226 == nullptr) {
        node226 = new PhaseNode_PlayAnimation(226, phase);
        node226->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node226->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node226->setTarget(0U);
        node226->setAnimation("Idle");
        node226->setParameter("");
        node226->setValue(false);
        CALL_REGISTER_SKILL_NODE(10031, 226, node226)
    }
    if (noInit == true) {
        return node226;
    }
    return node226;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10031, 227) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_Delay::TRIGGER_DONE, 230, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(10031, 227) {
    auto node227 = GET_SKILL_NODE(227, PhaseNode_Delay);
    if (node227 == nullptr) {
        node227 = new PhaseNode_Delay(227, phase);
        node227->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(10031, 227, node227)
    }
    if (noInit == true) {
        return node227;
    }
    return node227;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(10031, 230) {
}

REGISTER_CREATE_SKILL_NODE(10031, 230) {
    auto node230 = GET_SKILL_NODE(230, PhaseNode_SetBool);
    if (node230 == nullptr) {
        node230 = new PhaseNode_SetBool(230, phase);
        node230->setName("InterruptAnimat");
        node230->setValue(true);
        CALL_REGISTER_SKILL_NODE(10031, 230, node230)
    }
    if (noInit == true) {
        return node230;
    }
    return node230;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10031, 231) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StartPreInput>(PhaseNode_RaiseEvent::TRIGGER_DONE, 223, PhaseNode_StartPreInput::FUNC_DO, &PhaseNode_StartPreInput::Do);
}

REGISTER_CREATE_SKILL_NODE(10031, 231) {
    auto node231 = GET_SKILL_NODE(231, PhaseNode_RaiseEvent);
    if (node231 == nullptr) {
        node231 = new PhaseNode_RaiseEvent(231, phase);
        node231->setEvent("Dead_001");
        node231->setTarget(0U);
        node231->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node231->setTypeParams(0, 0);
        node231->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10031, 231, node231)
    }
    if (noInit == true) {
        return node231;
    }
    return node231;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10031, 232) {
}

REGISTER_CREATE_SKILL_NODE(10031, 232) {
    auto node232 = GET_SKILL_NODE(232, PhaseNode_Detect);
    if (node232 == nullptr) {
        node232 = new PhaseNode_Detect(232, phase);
        node232->setSelf(0U);
        node232->setEvent("Dead_001");
        node232->setType(PhaseNode_Detect::Detect_Type::Actor_Dead);
        node232->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10031, 232, node232)
    }
    if (noInit == true) {
        return node232;
    }
    return node232;
}

//--------------------------------------------------------------------------------
// SkillCreator_10031
//
class SkillCreator_10031 : public SkillCreator {
public:
    SkillCreator_10031() {}
    virtual ~SkillCreator_10031() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_10031

//--------------------------------------------------------------------------------
// SkillPhase_10031
//
class SkillPhase_10031 : public SkillPhase {
public:
    SkillPhase_10031(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_10031() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(10031, 76) // StartPhase
        CASE_CREATE_SKILL_NODE(10031, 78) // TriggerUpdate
        CASE_CREATE_SKILL_NODE(10031, 98) // Disable
        CASE_CREATE_SKILL_NODE(10031, 102) // AddSkillBuff
        CASE_CREATE_SKILL_NODE(10031, 113) // Delay
        CASE_CREATE_SKILL_NODE(10031, 117) // EndPhase
        CASE_CREATE_SKILL_NODE(10031, 121) // UInt64sSize
        CASE_CREATE_SKILL_NODE(10031, 123) // For
        CASE_CREATE_SKILL_NODE(10031, 125) // GetUInt64sValue
        CASE_CREATE_SKILL_NODE(10031, 130) // DamageReduce
        CASE_CREATE_SKILL_NODE(10031, 132) // ReviseMapI32
        CASE_CREATE_SKILL_NODE(10031, 134) // AddSkillBuff
        CASE_CREATE_SKILL_NODE(10031, 136) // ForContinue
        CASE_CREATE_SKILL_NODE(10031, 171) // RemoveSkillBuff
        CASE_CREATE_SKILL_NODE(10031, 206) // AreaCollisionNewPene
        CASE_CREATE_SKILL_NODE(10031, 209) // TimeDown
        CASE_CREATE_SKILL_NODE(10031, 211) // GetLocation
        CASE_CREATE_SKILL_NODE(10031, 213) // LineCheckNewPene
        CASE_CREATE_SKILL_NODE(10031, 214) // ResetCD
        CASE_CREATE_SKILL_NODE(10031, 215) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10031, 216) // PlaySound
        CASE_CREATE_SKILL_NODE(10031, 217) // GetActorAttribute
        CASE_CREATE_SKILL_NODE(10031, 219) // Detect
        CASE_CREATE_SKILL_NODE(10031, 220) // SwitchToInt
        CASE_CREATE_SKILL_NODE(10031, 222) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10031, 223) // StartPreInput
        CASE_CREATE_SKILL_NODE(10031, 224) // If
        CASE_CREATE_SKILL_NODE(10031, 225) // IsInterruptType
        CASE_CREATE_SKILL_NODE(10031, 226) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10031, 227) // Delay
        CASE_CREATE_SKILL_NODE(10031, 230) // SetBool
        CASE_CREATE_SKILL_NODE(10031, 231) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10031, 232) // Detect
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_10031

SkillLogic* SkillCreator_10031::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //设置变量
    Variable_10031_a100312 = logic->getVariables().setVariable<int32_t>("a100312", 1);
    Variable_10031_InterruptAnimat = logic->getVariables().setVariable<bool>("InterruptAnimat");
    //创建阶段phase
    auto phase = new SkillPhase_10031(1, logic, 3);
    //设置phase执行器
    phase->setRunPhaseNode(1, 76);
    phase->setRunPhaseNode(2, 78);
    phase->setDetectPhaseNode(3, 219);
    phase->setDetectPhaseNode(3, 232);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_10031::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
