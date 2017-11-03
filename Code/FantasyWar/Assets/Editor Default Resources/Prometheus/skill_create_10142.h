#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

#include "skill_psnode_addcurmag.h"
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
#include "skill_psnode_setbool.h"
#include "skill_psnode_spawncollider.h"
#include "skill_psnode_startphase.h"
#include "skill_psnode_startpreinput.h"
#include "skill_psnode_stopweapon.h"
#include "skill_psnode_switchtoint.h"

namespace pvp {

//变量声明
uint64_t Variable_10142_101422 = 0;
uint64_t Variable_10142_InterruptAnimat = 0;
//--------------------------------------------------------------------------------
// StartPhase
//
REGISTER_REGISTER_SKILL_NODE(10142, 4) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_StartPhase::TRIGGER_START, 140, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(10142, 4) {
    auto node4 = GET_SKILL_NODE(4, PhaseNode_StartPhase);
    if (node4 == nullptr) {
        node4 = new PhaseNode_StartPhase(4, phase);
        CALL_REGISTER_SKILL_NODE(10142, 4, node4)
    }
    if (noInit == true) {
        return node4;
    }
    return node4;
}
//--------------------------------------------------------------------------------
// SpawnCollider
//
REGISTER_REGISTER_SKILL_NODE(10142, 15) {
    pnode->resizeTrigger(PhaseNode_SpawnCollider::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AttachTo>(PhaseNode_SpawnCollider::TRIGGER_DONE, 23, PhaseNode_AttachTo::FUNC_DO, &PhaseNode_AttachTo::Do);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_SpawnCollider::TRIGGER_DONE, 137, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10142, 15) {
    auto node15 = GET_SKILL_NODE(15, PhaseNode_SpawnCollider);
    if (node15 == nullptr) {
        node15 = new PhaseNode_SpawnCollider(15, phase);
        node15->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node15->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node15->setMesh("");
        node15->setMeshScale(.00f);
        node15->setEffectID(0);
        node15->setEffectScale(.00f);
        node15->setType(PhaseNode_SpawnCollider::SpawnCollider_Type::Circle);
        node15->setTypeParams(0, .20f);
        node15->setTime(.80f);
        node15->setPosZ(.00f);
        node15->setRotation(.00f);
        node15->setreentry(false);
        node15->setCheckPeneSound(false);
        CALL_REGISTER_SKILL_NODE(10142, 15, node15)
    }
    if (noInit == true) {
        return node15;
    }
    auto node120 = GET_SKILL_NODE(120, PhaseNode_GetLocation);
    if (node120 != nullptr) node15->setPosX(node120->getX());
    if (node120 != nullptr) node15->setPosY(node120->getY());
    return node15;
}
//--------------------------------------------------------------------------------
// Disable
//
REGISTER_REGISTER_SKILL_NODE(10142, 19) {
    pnode->resizeTrigger(PhaseNode_Disable::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddCurMag>(PhaseNode_Disable::TRIGGER_DONE, 128, PhaseNode_AddCurMag::FUNC_ADD, &PhaseNode_AddCurMag::Add);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_Disable::TRIGGER_DONE, 148, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10142, 19) {
    auto node19 = GET_SKILL_NODE(19, PhaseNode_Disable);
    if (node19 == nullptr) {
        node19 = new PhaseNode_Disable(19, phase);
        node19->setTarget(0U);
        node19->setMove(true);
        node19->setSkill(true);
        node19->setShoot(true);
        node19->setTime(.47f);
        node19->setRotate(true);
        CALL_REGISTER_SKILL_NODE(10142, 19, node19)
    }
    if (noInit == true) {
        return node19;
    }
    return node19;
}
//--------------------------------------------------------------------------------
// AttachTo
//
REGISTER_REGISTER_SKILL_NODE(10142, 23) {
    pnode->resizeTrigger(PhaseNode_AttachTo::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_MoveNewPene>(PhaseNode_AttachTo::TRIGGER_DONE, 72, PhaseNode_MoveNewPene::FUNC_DO, &PhaseNode_MoveNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(10142, 23) {
    auto node23 = GET_SKILL_NODE(23, PhaseNode_AttachTo);
    if (node23 == nullptr) {
        node23 = new PhaseNode_AttachTo(23, phase);
        node23->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node23->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node23->setChild(0U);
        node23->setChangeRotation(false);
        node23->setreentry(false);
        CALL_REGISTER_SKILL_NODE(10142, 23, node23)
    }
    if (noInit == true) {
        return node23;
    }
    auto node15 = GET_SKILL_NODE(15, PhaseNode_SpawnCollider);
    if (node15 != nullptr) node23->setParent(node15->getColliderID());
    return node23;
}
//--------------------------------------------------------------------------------
// DestroyCollider
//
REGISTER_REGISTER_SKILL_NODE(10142, 38) {
}

REGISTER_CREATE_SKILL_NODE(10142, 38) {
    auto node38 = GET_SKILL_NODE(38, PhaseNode_DestroyCollider);
    if (node38 == nullptr) {
        node38 = new PhaseNode_DestroyCollider(38, phase);
        CALL_REGISTER_SKILL_NODE(10142, 38, node38)
    }
    if (noInit == true) {
        return node38;
    }
    auto node15 = GET_SKILL_NODE(15, PhaseNode_SpawnCollider);
    if (node15 != nullptr) node38->setColliderID(node15->getColliderID());
    return node38;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10142, 62) {
}

REGISTER_CREATE_SKILL_NODE(10142, 62) {
    auto node62 = GET_SKILL_NODE(62, PhaseNode_PlaySound);
    if (node62 == nullptr) {
        node62 = new PhaseNode_PlaySound(62, phase);
        node62->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node62->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node62->setSoundID("SE_Hero108_SkillB_P1");
        node62->setTarget(0U);
        node62->setUsePos(false);
        node62->setPosX(.00f);
        node62->setPosY(.00f);
        node62->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10142, 62, node62)
    }
    if (noInit == true) {
        return node62;
    }
    return node62;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(10142, 66) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Disable>(PhaseNode_PlayEffect::TRIGGER_DONE, 19, PhaseNode_Disable::FUNC_DO, &PhaseNode_Disable::Do);
}

REGISTER_CREATE_SKILL_NODE(10142, 66) {
    auto node66 = GET_SKILL_NODE(66, PhaseNode_PlayEffect);
    if (node66 == nullptr) {
        node66 = new PhaseNode_PlayEffect(66, phase);
        node66->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node66->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node66->setEffectID(101421);
        node66->setChangeColor(false);
        node66->setType(PhaseNode_PlayEffect::PlayEffect_Type::WithTarget);
        node66->getVars().reserve(5);
        node66->getVars().setVariable<uint64_t>(0, 0U);
        node66->getVars().setVariable<std::string>(1, "");
        node66->getVars().setVariable<float>(2, .00f);
        node66->getVars().setVariable<float>(3, .00f);
        node66->getVars().setVariable<float>(4, .00f);
        node66->setRotation(.00f);
        node66->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(10142, 66, node66)
    }
    if (noInit == true) {
        return node66;
    }
    return node66;
}
//--------------------------------------------------------------------------------
// MoveNewPene
//
REGISTER_REGISTER_SKILL_NODE(10142, 72) {
    pnode->resizeTrigger(PhaseNode_MoveNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_DestroyCollider>(PhaseNode_MoveNewPene::TRIGGER_BLOCKBYSHIELD, 38, PhaseNode_DestroyCollider::FUNC_DO, &PhaseNode_DestroyCollider::Do);
    pnode->regTrigger<PhaseNode_DestroyCollider>(PhaseNode_MoveNewPene::TRIGGER_BLOCKBYWALL, 38, PhaseNode_DestroyCollider::FUNC_DO, &PhaseNode_DestroyCollider::Do);
    pnode->regTrigger<PhaseNode_DestroyCollider>(PhaseNode_MoveNewPene::TRIGGER_DONE, 38, PhaseNode_DestroyCollider::FUNC_DO, &PhaseNode_DestroyCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(10142, 72) {
    auto node72 = GET_SKILL_NODE(72, PhaseNode_MoveNewPene);
    if (node72 == nullptr) {
        node72 = new PhaseNode_MoveNewPene(72, phase);
        node72->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node72->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node72->setPeneType(PhaseNode_MoveNewPene::MoveNewPene_PeneType::Move);
        node72->setPeneValue(15);
        node72->setType(PhaseNode_MoveNewPene::MoveNewPene_Type::Charge);
        node72->getVars().reserve(4);
        node72->getVars().setVariable<float>(0, 13.00f);
        node72->getVars().setVariable<float>(1, 6.00f);
        node72->getVars().setVariable<float>(2, .00f);
        node72->getVars().setVariable<float>(3, .00f);
        node72->setreentry(false);
        node72->setStopWhenFail(false);
        node72->setCheckFaction(PhaseNode_MoveNewPene::MoveNewPene_CheckFaction::Enemy);
        CALL_REGISTER_SKILL_NODE(10142, 72, node72)
    }
    if (noInit == true) {
        return node72;
    }
    auto node15 = GET_SKILL_NODE(15, PhaseNode_SpawnCollider);
    auto node122 = GET_SKILL_NODE(122, PhaseNode_GetInputRotation);
    if (node15 != nullptr) node72->setTarget(node15->getColliderID());
    if (node122 != nullptr) node72->getVars().setVariable<float>(2, node122->getAngle());
    return node72;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(10142, 80) {
}

REGISTER_CREATE_SKILL_NODE(10142, 80) {
    auto node80 = GET_SKILL_NODE(80, PhaseNode_EndPhase);
    if (node80 == nullptr) {
        node80 = new PhaseNode_EndPhase(80, phase);
        node80->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node80->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10142, 80, node80)
    }
    if (noInit == true) {
        return node80;
    }
    return node80;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(10142, 120) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetInputRotation>(PhaseNode_GetLocation::TRIGGER_DONE, 122, PhaseNode_GetInputRotation::FUNC_DO, &PhaseNode_GetInputRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(10142, 120) {
    auto node120 = GET_SKILL_NODE(120, PhaseNode_GetLocation);
    if (node120 == nullptr) {
        node120 = new PhaseNode_GetLocation(120, phase);
        node120->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node120->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(10142, 120, node120)
    }
    if (noInit == true) {
        return node120;
    }
    return node120;
}
//--------------------------------------------------------------------------------
// GetInputRotation
//
REGISTER_REGISTER_SKILL_NODE(10142, 122) {
    pnode->resizeTrigger(PhaseNode_GetInputRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_GetInputRotation::TRIGGER_DONE, 66, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(10142, 122) {
    auto node122 = GET_SKILL_NODE(122, PhaseNode_GetInputRotation);
    if (node122 == nullptr) {
        node122 = new PhaseNode_GetInputRotation(122, phase);
        node122->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        CALL_REGISTER_SKILL_NODE(10142, 122, node122)
    }
    if (noInit == true) {
        return node122;
    }
    return node122;
}
//--------------------------------------------------------------------------------
// AddCurMag
//
REGISTER_REGISTER_SKILL_NODE(10142, 128) {
    pnode->resizeTrigger(PhaseNode_AddCurMag::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StopWeapon>(PhaseNode_AddCurMag::TRIGGER_DONE, 139, PhaseNode_StopWeapon::FUNC_DO, &PhaseNode_StopWeapon::Do);
}

REGISTER_CREATE_SKILL_NODE(10142, 128) {
    auto node128 = GET_SKILL_NODE(128, PhaseNode_AddCurMag);
    if (node128 == nullptr) {
        node128 = new PhaseNode_AddCurMag(128, phase);
        node128->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node128->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node128->setDeltaMag(99);
        CALL_REGISTER_SKILL_NODE(10142, 128, node128)
    }
    if (noInit == true) {
        return node128;
    }
    return node128;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10142, 137) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_Delay::TRIGGER_DONE, 80, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(10142, 137) {
    auto node137 = GET_SKILL_NODE(137, PhaseNode_Delay);
    if (node137 == nullptr) {
        node137 = new PhaseNode_Delay(137, phase);
        node137->setTime(.60f);
        CALL_REGISTER_SKILL_NODE(10142, 137, node137)
    }
    if (noInit == true) {
        return node137;
    }
    return node137;
}
//--------------------------------------------------------------------------------
// StopWeapon
//
REGISTER_REGISTER_SKILL_NODE(10142, 139) {
    pnode->resizeTrigger(PhaseNode_StopWeapon::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnCollider>(PhaseNode_StopWeapon::TRIGGER_DONE, 15, PhaseNode_SpawnCollider::FUNC_DO, &PhaseNode_SpawnCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(10142, 139) {
    auto node139 = GET_SKILL_NODE(139, PhaseNode_StopWeapon);
    if (node139 == nullptr) {
        node139 = new PhaseNode_StopWeapon(139, phase);
        node139->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node139->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10142, 139, node139)
    }
    if (noInit == true) {
        return node139;
    }
    return node139;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(10142, 140) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_ResetCD::TRIGGER_DONE, 141, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10142, 140) {
    auto node140 = GET_SKILL_NODE(140, PhaseNode_ResetCD);
    if (node140 == nullptr) {
        node140 = new PhaseNode_ResetCD(140, phase);
        node140->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node140->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node140->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(10142, 140, node140)
    }
    if (noInit == true) {
        return node140;
    }
    return node140;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10142, 141) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_PlayAnimation::TRIGGER_DONE, 143, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(10142, 141) {
    auto node141 = GET_SKILL_NODE(141, PhaseNode_PlayAnimation);
    if (node141 == nullptr) {
        node141 = new PhaseNode_PlayAnimation(141, phase);
        node141->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node141->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node141->setTarget(0U);
        node141->setAnimation("Skill2S1");
        node141->setParameter("");
        node141->setValue(false);
        CALL_REGISTER_SKILL_NODE(10142, 141, node141)
    }
    if (noInit == true) {
        return node141;
    }
    return node141;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10142, 142) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_PlaySound::TRIGGER_DONE, 120, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_PlaySound::TRIGGER_DONE, 62, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10142, 142) {
    auto node142 = GET_SKILL_NODE(142, PhaseNode_PlaySound);
    if (node142 == nullptr) {
        node142 = new PhaseNode_PlaySound(142, phase);
        node142->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node142->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node142->setSoundID("VO_Hero108_Skill_A");
        node142->setTarget(0U);
        node142->setUsePos(false);
        node142->setPosX(.00f);
        node142->setPosY(.00f);
        node142->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10142, 142, node142)
    }
    if (noInit == true) {
        return node142;
    }
    return node142;
}
//--------------------------------------------------------------------------------
// GetActorAttribute
//
REGISTER_REGISTER_SKILL_NODE(10142, 143) {
    pnode->resizeTrigger(PhaseNode_GetActorAttribute::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 142, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10142, 143) {
    auto node143 = GET_SKILL_NODE(143, PhaseNode_GetActorAttribute);
    if (node143 == nullptr) {
        node143 = new PhaseNode_GetActorAttribute(143, phase);
        node143->setTarget(0U);
        node143->setType({});
        CALL_REGISTER_SKILL_NODE(10142, 143, node143)
    }
    if (noInit == true) {
        return node143;
    }
    return node143;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10142, 145) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_IsInterruptType>(PhaseNode_Detect::TRIGGER_ON, 151, PhaseNode_IsInterruptType::FUNC_DO, &PhaseNode_IsInterruptType::Do);
}

REGISTER_CREATE_SKILL_NODE(10142, 145) {
    auto node145 = GET_SKILL_NODE(145, PhaseNode_Detect);
    if (node145 == nullptr) {
        node145 = new PhaseNode_Detect(145, phase);
        node145->setSelf(0U);
        node145->setEvent("daduan_001");
        node145->setType(PhaseNode_Detect::Detect_Type::Interrupt_Skill);
        node145->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10142, 145, node145)
    }
    if (noInit == true) {
        return node145;
    }
    return node145;
}
//--------------------------------------------------------------------------------
// SwitchToInt
//
REGISTER_REGISTER_SKILL_NODE(10142, 146) {
    pnode->resizeTrigger(4);
    pnode->regTrigger<PhaseNode_EndPhase>(1, 80, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
    pnode->regTrigger<PhaseNode_MoveNewPene>(1, 72, PhaseNode_MoveNewPene::FUNC_STOP, &PhaseNode_MoveNewPene::Stop);
}

REGISTER_CREATE_SKILL_NODE(10142, 146) {
    auto node146 = GET_SKILL_NODE(146, PhaseNode_SwitchToInt);
    if (node146 == nullptr) {
        node146 = new PhaseNode_SwitchToInt(146, phase);
        CALL_REGISTER_SKILL_NODE(10142, 146, node146)
    }
    if (noInit == true) {
        return node146;
    }
    auto variables = node146->getVariables();
    if (variables != nullptr) {
        node146->setSelection(variables->getVariable<int32_t>(Variable_10142_101422));
    }
    return node146;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10142, 148) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_RaiseEvent::TRIGGER_DONE, 157, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10142, 148) {
    auto node148 = GET_SKILL_NODE(148, PhaseNode_RaiseEvent);
    if (node148 == nullptr) {
        node148 = new PhaseNode_RaiseEvent(148, phase);
        node148->setEvent("daduan_001");
        node148->setTarget(0U);
        node148->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node148->setTypeParams(0, 0);
        node148->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10142, 148, node148)
    }
    if (noInit == true) {
        return node148;
    }
    return node148;
}
//--------------------------------------------------------------------------------
// StartPreInput
//
REGISTER_REGISTER_SKILL_NODE(10142, 149) {
    pnode->resizeTrigger(PhaseNode_StartPreInput::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_StartPreInput::TRIGGER_DONE, 153, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10142, 149) {
    auto node149 = GET_SKILL_NODE(149, PhaseNode_StartPreInput);
    if (node149 == nullptr) {
        node149 = new PhaseNode_StartPreInput(149, phase);
        node149->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node149->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node149->setDelayTime(.00f);
        CALL_REGISTER_SKILL_NODE(10142, 149, node149)
    }
    if (noInit == true) {
        return node149;
    }
    return node149;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(10142, 150) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_If::TRIGGER_TRUE, 152, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10142, 150) {
    auto node150 = GET_SKILL_NODE(150, PhaseNode_If);
    if (node150 == nullptr) {
        node150 = new PhaseNode_If(150, phase);
        CALL_REGISTER_SKILL_NODE(10142, 150, node150)
    }
    if (noInit == true) {
        return node150;
    }
    auto variables = node150->getVariables();
    if (variables != nullptr) {
        node150->setCondition(variables->getVariable<bool>(Variable_10142_InterruptAnimat));
    }
    return node150;
}
//--------------------------------------------------------------------------------
// IsInterruptType
//
REGISTER_REGISTER_SKILL_NODE(10142, 151) {
    pnode->resizeTrigger(PhaseNode_IsInterruptType::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SwitchToInt>(PhaseNode_IsInterruptType::TRIGGER_BUFF, 146, PhaseNode_SwitchToInt::FUNC_SWITCH, &PhaseNode_SwitchToInt::Switch);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_POSCHANGE, 150, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTAIM, 150, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTFIRE, 150, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTRELOAD, 150, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_USESKILL, 150, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(10142, 151) {
    auto node151 = GET_SKILL_NODE(151, PhaseNode_IsInterruptType);
    if (node151 == nullptr) {
        node151 = new PhaseNode_IsInterruptType(151, phase);
        node151->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node151->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10142, 151, node151)
    }
    if (noInit == true) {
        return node151;
    }
    auto node145 = GET_SKILL_NODE(145, PhaseNode_Detect);
    if (node145 != nullptr) node151->setType(node145->getVars().getVariable<int32_t>(2));
    return node151;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10142, 152) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_PlayAnimation::TRIGGER_DONE, 80, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(10142, 152) {
    auto node152 = GET_SKILL_NODE(152, PhaseNode_PlayAnimation);
    if (node152 == nullptr) {
        node152 = new PhaseNode_PlayAnimation(152, phase);
        node152->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node152->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node152->setTarget(0U);
        node152->setAnimation("Idle");
        node152->setParameter("");
        node152->setValue(false);
        CALL_REGISTER_SKILL_NODE(10142, 152, node152)
    }
    if (noInit == true) {
        return node152;
    }
    return node152;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10142, 153) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_Delay::TRIGGER_DONE, 156, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(10142, 153) {
    auto node153 = GET_SKILL_NODE(153, PhaseNode_Delay);
    if (node153 == nullptr) {
        node153 = new PhaseNode_Delay(153, phase);
        node153->setTime(.20f);
        CALL_REGISTER_SKILL_NODE(10142, 153, node153)
    }
    if (noInit == true) {
        return node153;
    }
    return node153;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(10142, 156) {
}

REGISTER_CREATE_SKILL_NODE(10142, 156) {
    auto node156 = GET_SKILL_NODE(156, PhaseNode_SetBool);
    if (node156 == nullptr) {
        node156 = new PhaseNode_SetBool(156, phase);
        node156->setName("InterruptAnimat");
        node156->setValue(true);
        CALL_REGISTER_SKILL_NODE(10142, 156, node156)
    }
    if (noInit == true) {
        return node156;
    }
    return node156;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10142, 157) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StartPreInput>(PhaseNode_RaiseEvent::TRIGGER_DONE, 149, PhaseNode_StartPreInput::FUNC_DO, &PhaseNode_StartPreInput::Do);
}

REGISTER_CREATE_SKILL_NODE(10142, 157) {
    auto node157 = GET_SKILL_NODE(157, PhaseNode_RaiseEvent);
    if (node157 == nullptr) {
        node157 = new PhaseNode_RaiseEvent(157, phase);
        node157->setEvent("Dead_001");
        node157->setTarget(0U);
        node157->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node157->setTypeParams(0, 0);
        node157->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10142, 157, node157)
    }
    if (noInit == true) {
        return node157;
    }
    return node157;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10142, 158) {
}

REGISTER_CREATE_SKILL_NODE(10142, 158) {
    auto node158 = GET_SKILL_NODE(158, PhaseNode_Detect);
    if (node158 == nullptr) {
        node158 = new PhaseNode_Detect(158, phase);
        node158->setSelf(0U);
        node158->setEvent("Dead_001");
        node158->setType(PhaseNode_Detect::Detect_Type::Actor_Dead);
        node158->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10142, 158, node158)
    }
    if (noInit == true) {
        return node158;
    }
    return node158;
}

//--------------------------------------------------------------------------------
// SkillCreator_10142
//
class SkillCreator_10142 : public SkillCreator {
public:
    SkillCreator_10142() {}
    virtual ~SkillCreator_10142() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_10142

//--------------------------------------------------------------------------------
// SkillPhase_10142
//
class SkillPhase_10142 : public SkillPhase {
public:
    SkillPhase_10142(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_10142() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(10142, 4) // StartPhase
        CASE_CREATE_SKILL_NODE(10142, 15) // SpawnCollider
        CASE_CREATE_SKILL_NODE(10142, 19) // Disable
        CASE_CREATE_SKILL_NODE(10142, 23) // AttachTo
        CASE_CREATE_SKILL_NODE(10142, 38) // DestroyCollider
        CASE_CREATE_SKILL_NODE(10142, 62) // PlaySound
        CASE_CREATE_SKILL_NODE(10142, 66) // PlayEffect
        CASE_CREATE_SKILL_NODE(10142, 72) // MoveNewPene
        CASE_CREATE_SKILL_NODE(10142, 80) // EndPhase
        CASE_CREATE_SKILL_NODE(10142, 120) // GetLocation
        CASE_CREATE_SKILL_NODE(10142, 122) // GetInputRotation
        CASE_CREATE_SKILL_NODE(10142, 128) // AddCurMag
        CASE_CREATE_SKILL_NODE(10142, 137) // Delay
        CASE_CREATE_SKILL_NODE(10142, 139) // StopWeapon
        CASE_CREATE_SKILL_NODE(10142, 140) // ResetCD
        CASE_CREATE_SKILL_NODE(10142, 141) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10142, 142) // PlaySound
        CASE_CREATE_SKILL_NODE(10142, 143) // GetActorAttribute
        CASE_CREATE_SKILL_NODE(10142, 145) // Detect
        CASE_CREATE_SKILL_NODE(10142, 146) // SwitchToInt
        CASE_CREATE_SKILL_NODE(10142, 148) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10142, 149) // StartPreInput
        CASE_CREATE_SKILL_NODE(10142, 150) // If
        CASE_CREATE_SKILL_NODE(10142, 151) // IsInterruptType
        CASE_CREATE_SKILL_NODE(10142, 152) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10142, 153) // Delay
        CASE_CREATE_SKILL_NODE(10142, 156) // SetBool
        CASE_CREATE_SKILL_NODE(10142, 157) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10142, 158) // Detect
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_10142

SkillLogic* SkillCreator_10142::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //设置变量
    Variable_10142_101422 = logic->getVariables().setVariable<int32_t>("101422", 1);
    Variable_10142_InterruptAnimat = logic->getVariables().setVariable<bool>("InterruptAnimat");
    //创建阶段phase
    auto phase = new SkillPhase_10142(1, logic, 2);
    //设置phase执行器
    phase->setRunPhaseNode(1, 4);
    phase->setDetectPhaseNode(2, 145);
    phase->setDetectPhaseNode(2, 158);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_10142::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
