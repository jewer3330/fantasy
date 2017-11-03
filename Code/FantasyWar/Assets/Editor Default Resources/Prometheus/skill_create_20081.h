#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

#include "skill_psnode_actorfilternewpene.h"
#include "skill_psnode_addskillbuffs.h"
#include "skill_psnode_comparefloat.h"
#include "skill_psnode_createtriggernewpene.h"
#include "skill_psnode_delay.h"
#include "skill_psnode_detect.h"
#include "skill_psnode_endphase.h"
#include "skill_psnode_getactorattribute.h"
#include "skill_psnode_getlocation.h"
#include "skill_psnode_getrotation.h"
#include "skill_psnode_if.h"
#include "skill_psnode_offsetcalculate.h"
#include "skill_psnode_playanimation.h"
#include "skill_psnode_playeffect.h"
#include "skill_psnode_playsound.h"
#include "skill_psnode_raiseevent.h"
#include "skill_psnode_resetcd.h"
#include "skill_psnode_skillendnotify.h"
#include "skill_psnode_spawncollider.h"
#include "skill_psnode_startphase.h"
#include "skill_psnode_stopeffect.h"
#include "skill_psnode_triggercheck.h"
#include "skill_psnode_triggerupdate.h"

namespace pvp {

//变量声明
//--------------------------------------------------------------------------------
// StartPhase
//
REGISTER_REGISTER_SKILL_NODE(20081, 1) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_StartPhase::TRIGGER_START, 103, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_StartPhase::TRIGGER_START, 69, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(20081, 1) {
    auto node1 = GET_SKILL_NODE(1, PhaseNode_StartPhase);
    if (node1 == nullptr) {
        node1 = new PhaseNode_StartPhase(1, phase);
        CALL_REGISTER_SKILL_NODE(20081, 1, node1)
    }
    if (noInit == true) {
        return node1;
    }
    return node1;
}
//--------------------------------------------------------------------------------
// TriggerUpdate
//
REGISTER_REGISTER_SKILL_NODE(20081, 2) {
}

REGISTER_CREATE_SKILL_NODE(20081, 2) {
    auto node2 = GET_SKILL_NODE(2, PhaseNode_TriggerUpdate);
    if (node2 == nullptr) {
        node2 = new PhaseNode_TriggerUpdate(2, phase);
        CALL_REGISTER_SKILL_NODE(20081, 2, node2)
    }
    if (noInit == true) {
        return node2;
    }
    return node2;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(20081, 7) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_Delay::TRIGGER_DONE, 74, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(20081, 7) {
    auto node7 = GET_SKILL_NODE(7, PhaseNode_Delay);
    if (node7 == nullptr) {
        node7 = new PhaseNode_Delay(7, phase);
        node7->setTime(.60f);
        CALL_REGISTER_SKILL_NODE(20081, 7, node7)
    }
    if (noInit == true) {
        return node7;
    }
    return node7;
}
//--------------------------------------------------------------------------------
// SpawnCollider
//
REGISTER_REGISTER_SKILL_NODE(20081, 12) {
    pnode->resizeTrigger(PhaseNode_SpawnCollider::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_SpawnCollider::TRIGGER_DONE, 99, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_SpawnCollider::TRIGGER_DONE, 86, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(20081, 12) {
    auto node12 = GET_SKILL_NODE(12, PhaseNode_SpawnCollider);
    if (node12 == nullptr) {
        node12 = new PhaseNode_SpawnCollider(12, phase);
        node12->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node12->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node12->setMesh("");
        node12->setMeshScale(.00f);
        node12->setEffectID(0);
        node12->setEffectScale(.00f);
        node12->setType(PhaseNode_SpawnCollider::SpawnCollider_Type::Sector);
        node12->setTypeParams(0, 5.00f);
        node12->setTypeParams(1, 90.00f);
        node12->setTime(1.00f);
        node12->setPosZ(.00f);
        node12->setreentry(false);
        node12->setCheckPeneSound(false);
        CALL_REGISTER_SKILL_NODE(20081, 12, node12)
    }
    if (noInit == true) {
        return node12;
    }
    auto node68 = GET_SKILL_NODE(68, PhaseNode_OffsetCalculate);
    if (node68 != nullptr) node12->setPosX(node68->getOutPosX());
    if (node68 != nullptr) node12->setPosY(node68->getOutPosY());
    if (node68 != nullptr) node12->setRotation(node68->getOutRotation());
    return node12;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(20081, 25) {
}

REGISTER_CREATE_SKILL_NODE(20081, 25) {
    auto node25 = GET_SKILL_NODE(25, PhaseNode_EndPhase);
    if (node25 == nullptr) {
        node25 = new PhaseNode_EndPhase(25, phase);
        node25->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node25->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(20081, 25, node25)
    }
    if (noInit == true) {
        return node25;
    }
    return node25;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(20081, 62) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_Detect::TRIGGER_ON, 64, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(20081, 62) {
    auto node62 = GET_SKILL_NODE(62, PhaseNode_Detect);
    if (node62 == nullptr) {
        node62 = new PhaseNode_Detect(62, phase);
        node62->setSelf(0U);
        node62->setEvent("");
        node62->setType(PhaseNode_Detect::Detect_Type::Actor_Dead);
        node62->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(20081, 62, node62)
    }
    if (noInit == true) {
        return node62;
    }
    return node62;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(20081, 64) {
}

REGISTER_CREATE_SKILL_NODE(20081, 64) {
    auto node64 = GET_SKILL_NODE(64, PhaseNode_EndPhase);
    if (node64 == nullptr) {
        node64 = new PhaseNode_EndPhase(64, phase);
        node64->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node64->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(20081, 64, node64)
    }
    if (noInit == true) {
        return node64;
    }
    return node64;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(20081, 66) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetRotation>(PhaseNode_GetLocation::TRIGGER_DONE, 67, PhaseNode_GetRotation::FUNC_DO, &PhaseNode_GetRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(20081, 66) {
    auto node66 = GET_SKILL_NODE(66, PhaseNode_GetLocation);
    if (node66 == nullptr) {
        node66 = new PhaseNode_GetLocation(66, phase);
        node66->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node66->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(20081, 66, node66)
    }
    if (noInit == true) {
        return node66;
    }
    return node66;
}
//--------------------------------------------------------------------------------
// GetRotation
//
REGISTER_REGISTER_SKILL_NODE(20081, 67) {
    pnode->resizeTrigger(PhaseNode_GetRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_OffsetCalculate>(PhaseNode_GetRotation::TRIGGER_DONE, 68, PhaseNode_OffsetCalculate::FUNC_DO, &PhaseNode_OffsetCalculate::Do);
}

REGISTER_CREATE_SKILL_NODE(20081, 67) {
    auto node67 = GET_SKILL_NODE(67, PhaseNode_GetRotation);
    if (node67 == nullptr) {
        node67 = new PhaseNode_GetRotation(67, phase);
        node67->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node67->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(20081, 67, node67)
    }
    if (noInit == true) {
        return node67;
    }
    return node67;
}
//--------------------------------------------------------------------------------
// OffsetCalculate
//
REGISTER_REGISTER_SKILL_NODE(20081, 68) {
    pnode->resizeTrigger(PhaseNode_OffsetCalculate::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 7, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(20081, 68) {
    auto node68 = GET_SKILL_NODE(68, PhaseNode_OffsetCalculate);
    if (node68 == nullptr) {
        node68 = new PhaseNode_OffsetCalculate(68, phase);
        node68->setPosZ(.00f);
        node68->setOffsetX(.10f);
        node68->setOffsetY(2.20f);
        node68->setOffsetZ(4.00f);
        node68->setRotOffset(.00f);
        CALL_REGISTER_SKILL_NODE(20081, 68, node68)
    }
    if (noInit == true) {
        return node68;
    }
    auto node66 = GET_SKILL_NODE(66, PhaseNode_GetLocation);
    auto node67 = GET_SKILL_NODE(67, PhaseNode_GetRotation);
    if (node66 != nullptr) node68->setPosX(node66->getX());
    if (node66 != nullptr) node68->setPosY(node66->getY());
    if (node67 != nullptr) node68->setRotation(node67->getAngle());
    return node68;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(20081, 69) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_ResetCD::TRIGGER_DONE, 70, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(20081, 69) {
    auto node69 = GET_SKILL_NODE(69, PhaseNode_ResetCD);
    if (node69 == nullptr) {
        node69 = new PhaseNode_ResetCD(69, phase);
        node69->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node69->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node69->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(20081, 69, node69)
    }
    if (noInit == true) {
        return node69;
    }
    return node69;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(20081, 70) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_PlayAnimation::TRIGGER_DONE, 71, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(20081, 70) {
    auto node70 = GET_SKILL_NODE(70, PhaseNode_PlayAnimation);
    if (node70 == nullptr) {
        node70 = new PhaseNode_PlayAnimation(70, phase);
        node70->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node70->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node70->setTarget(0U);
        node70->setAnimation("Skill1S1");
        node70->setParameter("");
        node70->setValue(false);
        CALL_REGISTER_SKILL_NODE(20081, 70, node70)
    }
    if (noInit == true) {
        return node70;
    }
    return node70;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(20081, 71) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlaySound::TRIGGER_DONE, 72, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(20081, 71) {
    auto node71 = GET_SKILL_NODE(71, PhaseNode_PlaySound);
    if (node71 == nullptr) {
        node71 = new PhaseNode_PlaySound(71, phase);
        node71->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node71->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node71->setSoundID("");
        node71->setTarget(0U);
        node71->setUsePos(false);
        node71->setPosX(.00f);
        node71->setPosY(.00f);
        node71->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(20081, 71, node71)
    }
    if (noInit == true) {
        return node71;
    }
    return node71;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(20081, 72) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_Delay::TRIGGER_DONE, 66, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(20081, 72) {
    auto node72 = GET_SKILL_NODE(72, PhaseNode_Delay);
    if (node72 == nullptr) {
        node72 = new PhaseNode_Delay(72, phase);
        node72->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(20081, 72, node72)
    }
    if (noInit == true) {
        return node72;
    }
    return node72;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(20081, 73) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_PlayEffect::TRIGGER_DONE, 76, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(20081, 73) {
    auto node73 = GET_SKILL_NODE(73, PhaseNode_PlayEffect);
    if (node73 == nullptr) {
        node73 = new PhaseNode_PlayEffect(73, phase);
        node73->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node73->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node73->setEffectID(200811);
        node73->setChangeColor(false);
        node73->setType(PhaseNode_PlayEffect::PlayEffect_Type::WithTarget);
        node73->getVars().reserve(5);
        node73->getVars().setVariable<uint64_t>(0, 0U);
        node73->getVars().setVariable<std::string>(1, "");
        node73->getVars().setVariable<float>(2, .00f);
        node73->getVars().setVariable<float>(3, .00f);
        node73->getVars().setVariable<float>(4, .00f);
        node73->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(20081, 73, node73)
    }
    if (noInit == true) {
        return node73;
    }
    auto node68 = GET_SKILL_NODE(68, PhaseNode_OffsetCalculate);
    if (node68 != nullptr) node73->getVars().setVariable<float>(2, node68->getOutPosX());
    if (node68 != nullptr) node73->getVars().setVariable<float>(3, node68->getOutPosY());
    if (node68 != nullptr) node73->getVars().setVariable<float>(4, node68->getOutPosZ());
    if (node68 != nullptr) node73->setRotation(node68->getOutRotation());
    return node73;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(20081, 74) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_FALSE, 75, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_TRUE, 73, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(20081, 74) {
    auto node74 = GET_SKILL_NODE(74, PhaseNode_If);
    if (node74 == nullptr) {
        node74 = new PhaseNode_If(74, phase);
        node74->setCondition(false);
        CALL_REGISTER_SKILL_NODE(20081, 74, node74)
    }
    if (noInit == true) {
        return node74;
    }
    return node74;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(20081, 75) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_PlayEffect::TRIGGER_DONE, 76, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(20081, 75) {
    auto node75 = GET_SKILL_NODE(75, PhaseNode_PlayEffect);
    if (node75 == nullptr) {
        node75 = new PhaseNode_PlayEffect(75, phase);
        node75->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node75->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node75->setEffectID(200811);
        node75->setChangeColor(false);
        node75->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node75->getVars().reserve(3);
        node75->getVars().setVariable<float>(0, .00f);
        node75->getVars().setVariable<float>(1, .00f);
        node75->getVars().setVariable<float>(2, .00f);
        node75->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(20081, 75, node75)
    }
    if (noInit == true) {
        return node75;
    }
    auto node68 = GET_SKILL_NODE(68, PhaseNode_OffsetCalculate);
    if (node68 != nullptr) node75->getVars().setVariable<float>(0, node68->getOutPosX());
    if (node68 != nullptr) node75->getVars().setVariable<float>(1, node68->getOutPosY());
    if (node68 != nullptr) node75->getVars().setVariable<float>(2, node68->getOutPosZ());
    if (node68 != nullptr) node75->setRotation(node68->getOutRotation());
    return node75;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(20081, 76) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnCollider>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 12, PhaseNode_SpawnCollider::FUNC_DO, &PhaseNode_SpawnCollider::Do);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_LESS, 77, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_SpawnCollider>(PhaseNode_CompareFloat::TRIGGER_LESS, 12, PhaseNode_SpawnCollider::FUNC_DO, &PhaseNode_SpawnCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(20081, 76) {
    auto node76 = GET_SKILL_NODE(76, PhaseNode_CompareFloat);
    if (node76 == nullptr) {
        node76 = new PhaseNode_CompareFloat(76, phase);
        node76->setA(.00f);
        node76->setB(.00f);
        CALL_REGISTER_SKILL_NODE(20081, 76, node76)
    }
    if (noInit == true) {
        return node76;
    }
    return node76;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(20081, 77) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StopEffect>(PhaseNode_Delay::TRIGGER_DONE, 78, PhaseNode_StopEffect::FUNC_DO, &PhaseNode_StopEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(20081, 77) {
    auto node77 = GET_SKILL_NODE(77, PhaseNode_Delay);
    if (node77 == nullptr) {
        node77 = new PhaseNode_Delay(77, phase);
        node77->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(20081, 77, node77)
    }
    if (noInit == true) {
        return node77;
    }
    return node77;
}
//--------------------------------------------------------------------------------
// StopEffect
//
REGISTER_REGISTER_SKILL_NODE(20081, 78) {
}

REGISTER_CREATE_SKILL_NODE(20081, 78) {
    auto node78 = GET_SKILL_NODE(78, PhaseNode_StopEffect);
    if (node78 == nullptr) {
        node78 = new PhaseNode_StopEffect(78, phase);
        node78->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node78->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node78->setEffectID(200811);
        CALL_REGISTER_SKILL_NODE(20081, 78, node78)
    }
    if (noInit == true) {
        return node78;
    }
    return node78;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(20081, 79) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 91, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 93, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(20081, 79) {
    auto node79 = GET_SKILL_NODE(79, PhaseNode_CreateTriggerNewPene);
    if (node79 == nullptr) {
        node79 = new PhaseNode_CreateTriggerNewPene(79, phase);
        node79->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::In);
        node79->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node79->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Enemy);
        node79->setOnHero(true);
        node79->setOnMinion(true);
        node79->setOnDestruct(false);
        node79->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(20081, 79, node79)
    }
    if (noInit == true) {
        return node79;
    }
    auto node12 = GET_SKILL_NODE(12, PhaseNode_SpawnCollider);
    if (node12 != nullptr) node79->setColliderID(node12->getColliderID());
    return node79;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(20081, 80) {
}

REGISTER_CREATE_SKILL_NODE(20081, 80) {
    auto node80 = GET_SKILL_NODE(80, PhaseNode_TriggerCheck);
    if (node80 == nullptr) {
        node80 = new PhaseNode_TriggerCheck(80, phase);
        auto node2 = GET_SKILL_NODE(2, PhaseNode_TriggerUpdate);
        if (node2 != nullptr) node2->addTriggerCheck(node80);
        
        CALL_REGISTER_SKILL_NODE(20081, 80, node80)
    }
    if (noInit == true) {
        return node80;
    }
    auto node89 = GET_SKILL_NODE(89, PhaseNode_CreateTriggerNewPene);
    if (node89 != nullptr) node80->setTrigger(0, node89->getTriggerID());
    return node80;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(20081, 81) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 82, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(20081, 81) {
    auto node81 = GET_SKILL_NODE(81, PhaseNode_ActorFilterNewPene);
    if (node81 == nullptr) {
        node81 = new PhaseNode_ActorFilterNewPene(81, phase);
        node81->setHero(true);
        node81->setMinion(true);
        node81->setDestruct(false);
        node81->setShield(false);
        node81->setTotalCount(0);
        node81->setPerCount(0);
        CALL_REGISTER_SKILL_NODE(20081, 81, node81)
    }
    if (noInit == true) {
        return node81;
    }
    auto node85 = GET_SKILL_NODE(85, PhaseNode_CreateTriggerNewPene);
    if (node85 != nullptr) node81->setInput(node85->getOther());
    return node81;
}
//--------------------------------------------------------------------------------
// GetActorAttribute
//
REGISTER_REGISTER_SKILL_NODE(20081, 82) {
    pnode->resizeTrigger(PhaseNode_GetActorAttribute::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 83, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 96, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 97, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 98, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
}

REGISTER_CREATE_SKILL_NODE(20081, 82) {
    auto node82 = GET_SKILL_NODE(82, PhaseNode_GetActorAttribute);
    if (node82 == nullptr) {
        node82 = new PhaseNode_GetActorAttribute(82, phase);
        node82->setTarget(0U);
        node82->setType({202});
        CALL_REGISTER_SKILL_NODE(20081, 82, node82)
    }
    if (noInit == true) {
        return node82;
    }
    return node82;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(20081, 83) {
}

REGISTER_CREATE_SKILL_NODE(20081, 83) {
    auto node83 = GET_SKILL_NODE(83, PhaseNode_AddSkillBuffs);
    if (node83 == nullptr) {
        node83 = new PhaseNode_AddSkillBuffs(83, phase);
        node83->setConfigID({11});
        CALL_REGISTER_SKILL_NODE(20081, 83, node83)
    }
    if (noInit == true) {
        return node83;
    }
    auto node81 = GET_SKILL_NODE(81, PhaseNode_ActorFilterNewPene);
    auto node82 = GET_SKILL_NODE(82, PhaseNode_GetActorAttribute);
    if (node81 != nullptr) node83->setTarget(node81->getOutput());
    if (node82 != nullptr) node83->setAttribute(node82->getAttribute());
    return node83;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(20081, 84) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 79, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_LESS, 85, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
}

REGISTER_CREATE_SKILL_NODE(20081, 84) {
    auto node84 = GET_SKILL_NODE(84, PhaseNode_CompareFloat);
    if (node84 == nullptr) {
        node84 = new PhaseNode_CompareFloat(84, phase);
        node84->setA(.00f);
        node84->setB(.30f);
        CALL_REGISTER_SKILL_NODE(20081, 84, node84)
    }
    if (noInit == true) {
        return node84;
    }
    return node84;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(20081, 85) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 90, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 81, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(20081, 85) {
    auto node85 = GET_SKILL_NODE(85, PhaseNode_CreateTriggerNewPene);
    if (node85 == nullptr) {
        node85 = new PhaseNode_CreateTriggerNewPene(85, phase);
        node85->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::Tick);
        node85->setTypeParams(0, .30f);
        node85->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node85->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Enemy);
        node85->setOnHero(true);
        node85->setOnMinion(true);
        node85->setOnDestruct(false);
        node85->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(20081, 85, node85)
    }
    if (noInit == true) {
        return node85;
    }
    auto node12 = GET_SKILL_NODE(12, PhaseNode_SpawnCollider);
    if (node12 != nullptr) node85->setColliderID(node12->getColliderID());
    return node85;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(20081, 86) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_If::TRIGGER_FALSE, 87, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_If::TRIGGER_TRUE, 84, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(20081, 86) {
    auto node86 = GET_SKILL_NODE(86, PhaseNode_If);
    if (node86 == nullptr) {
        node86 = new PhaseNode_If(86, phase);
        node86->setCondition(true);
        CALL_REGISTER_SKILL_NODE(20081, 86, node86)
    }
    if (noInit == true) {
        return node86;
    }
    return node86;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(20081, 87) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 89, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_LESS, 88, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
}

REGISTER_CREATE_SKILL_NODE(20081, 87) {
    auto node87 = GET_SKILL_NODE(87, PhaseNode_CompareFloat);
    if (node87 == nullptr) {
        node87 = new PhaseNode_CompareFloat(87, phase);
        node87->setA(.00f);
        node87->setB(.30f);
        CALL_REGISTER_SKILL_NODE(20081, 87, node87)
    }
    if (noInit == true) {
        return node87;
    }
    return node87;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(20081, 88) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 92, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 94, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(20081, 88) {
    auto node88 = GET_SKILL_NODE(88, PhaseNode_CreateTriggerNewPene);
    if (node88 == nullptr) {
        node88 = new PhaseNode_CreateTriggerNewPene(88, phase);
        node88->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::Tick);
        node88->setTypeParams(0, .30f);
        node88->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node88->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Friend);
        node88->setOnHero(true);
        node88->setOnMinion(true);
        node88->setOnDestruct(false);
        node88->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(20081, 88, node88)
    }
    if (noInit == true) {
        return node88;
    }
    auto node12 = GET_SKILL_NODE(12, PhaseNode_SpawnCollider);
    if (node12 != nullptr) node88->setColliderID(node12->getColliderID());
    return node88;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(20081, 89) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 80, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 95, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(20081, 89) {
    auto node89 = GET_SKILL_NODE(89, PhaseNode_CreateTriggerNewPene);
    if (node89 == nullptr) {
        node89 = new PhaseNode_CreateTriggerNewPene(89, phase);
        node89->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::In);
        node89->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node89->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Friend);
        node89->setOnHero(true);
        node89->setOnMinion(true);
        node89->setOnDestruct(false);
        node89->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(20081, 89, node89)
    }
    if (noInit == true) {
        return node89;
    }
    auto node12 = GET_SKILL_NODE(12, PhaseNode_SpawnCollider);
    if (node12 != nullptr) node89->setColliderID(node12->getColliderID());
    return node89;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(20081, 90) {
}

REGISTER_CREATE_SKILL_NODE(20081, 90) {
    auto node90 = GET_SKILL_NODE(90, PhaseNode_TriggerCheck);
    if (node90 == nullptr) {
        node90 = new PhaseNode_TriggerCheck(90, phase);
        auto node2 = GET_SKILL_NODE(2, PhaseNode_TriggerUpdate);
        if (node2 != nullptr) node2->addTriggerCheck(node90);
        
        CALL_REGISTER_SKILL_NODE(20081, 90, node90)
    }
    if (noInit == true) {
        return node90;
    }
    auto node85 = GET_SKILL_NODE(85, PhaseNode_CreateTriggerNewPene);
    if (node85 != nullptr) node90->setTrigger(0, node85->getTriggerID());
    return node90;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(20081, 91) {
}

REGISTER_CREATE_SKILL_NODE(20081, 91) {
    auto node91 = GET_SKILL_NODE(91, PhaseNode_TriggerCheck);
    if (node91 == nullptr) {
        node91 = new PhaseNode_TriggerCheck(91, phase);
        auto node2 = GET_SKILL_NODE(2, PhaseNode_TriggerUpdate);
        if (node2 != nullptr) node2->addTriggerCheck(node91);
        
        CALL_REGISTER_SKILL_NODE(20081, 91, node91)
    }
    if (noInit == true) {
        return node91;
    }
    auto node79 = GET_SKILL_NODE(79, PhaseNode_CreateTriggerNewPene);
    if (node79 != nullptr) node91->setTrigger(0, node79->getTriggerID());
    return node91;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(20081, 92) {
}

REGISTER_CREATE_SKILL_NODE(20081, 92) {
    auto node92 = GET_SKILL_NODE(92, PhaseNode_TriggerCheck);
    if (node92 == nullptr) {
        node92 = new PhaseNode_TriggerCheck(92, phase);
        auto node2 = GET_SKILL_NODE(2, PhaseNode_TriggerUpdate);
        if (node2 != nullptr) node2->addTriggerCheck(node92);
        
        CALL_REGISTER_SKILL_NODE(20081, 92, node92)
    }
    if (noInit == true) {
        return node92;
    }
    auto node88 = GET_SKILL_NODE(88, PhaseNode_CreateTriggerNewPene);
    if (node88 != nullptr) node92->setTrigger(0, node88->getTriggerID());
    return node92;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(20081, 93) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 82, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(20081, 93) {
    auto node93 = GET_SKILL_NODE(93, PhaseNode_ActorFilterNewPene);
    if (node93 == nullptr) {
        node93 = new PhaseNode_ActorFilterNewPene(93, phase);
        node93->setHero(true);
        node93->setMinion(true);
        node93->setDestruct(false);
        node93->setShield(false);
        node93->setTotalCount(0);
        node93->setPerCount(0);
        CALL_REGISTER_SKILL_NODE(20081, 93, node93)
    }
    if (noInit == true) {
        return node93;
    }
    auto node79 = GET_SKILL_NODE(79, PhaseNode_CreateTriggerNewPene);
    if (node79 != nullptr) node93->setInput(node79->getOther());
    return node93;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(20081, 94) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 82, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(20081, 94) {
    auto node94 = GET_SKILL_NODE(94, PhaseNode_ActorFilterNewPene);
    if (node94 == nullptr) {
        node94 = new PhaseNode_ActorFilterNewPene(94, phase);
        node94->setHero(true);
        node94->setMinion(true);
        node94->setDestruct(false);
        node94->setShield(false);
        node94->setTotalCount(0);
        node94->setPerCount(0);
        CALL_REGISTER_SKILL_NODE(20081, 94, node94)
    }
    if (noInit == true) {
        return node94;
    }
    auto node88 = GET_SKILL_NODE(88, PhaseNode_CreateTriggerNewPene);
    if (node88 != nullptr) node94->setInput(node88->getOther());
    return node94;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(20081, 95) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 82, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(20081, 95) {
    auto node95 = GET_SKILL_NODE(95, PhaseNode_ActorFilterNewPene);
    if (node95 == nullptr) {
        node95 = new PhaseNode_ActorFilterNewPene(95, phase);
        node95->setHero(true);
        node95->setMinion(true);
        node95->setDestruct(false);
        node95->setShield(false);
        node95->setTotalCount(0);
        node95->setPerCount(0);
        CALL_REGISTER_SKILL_NODE(20081, 95, node95)
    }
    if (noInit == true) {
        return node95;
    }
    auto node89 = GET_SKILL_NODE(89, PhaseNode_CreateTriggerNewPene);
    if (node89 != nullptr) node95->setInput(node89->getOther());
    return node95;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(20081, 96) {
}

REGISTER_CREATE_SKILL_NODE(20081, 96) {
    auto node96 = GET_SKILL_NODE(96, PhaseNode_AddSkillBuffs);
    if (node96 == nullptr) {
        node96 = new PhaseNode_AddSkillBuffs(96, phase);
        node96->setConfigID({11});
        CALL_REGISTER_SKILL_NODE(20081, 96, node96)
    }
    if (noInit == true) {
        return node96;
    }
    auto node93 = GET_SKILL_NODE(93, PhaseNode_ActorFilterNewPene);
    auto node82 = GET_SKILL_NODE(82, PhaseNode_GetActorAttribute);
    if (node93 != nullptr) node96->setTarget(node93->getOutput());
    if (node82 != nullptr) node96->setAttribute(node82->getAttribute());
    return node96;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(20081, 97) {
}

REGISTER_CREATE_SKILL_NODE(20081, 97) {
    auto node97 = GET_SKILL_NODE(97, PhaseNode_AddSkillBuffs);
    if (node97 == nullptr) {
        node97 = new PhaseNode_AddSkillBuffs(97, phase);
        node97->setConfigID({11});
        CALL_REGISTER_SKILL_NODE(20081, 97, node97)
    }
    if (noInit == true) {
        return node97;
    }
    auto node94 = GET_SKILL_NODE(94, PhaseNode_ActorFilterNewPene);
    auto node82 = GET_SKILL_NODE(82, PhaseNode_GetActorAttribute);
    if (node94 != nullptr) node97->setTarget(node94->getOutput());
    if (node82 != nullptr) node97->setAttribute(node82->getAttribute());
    return node97;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(20081, 98) {
}

REGISTER_CREATE_SKILL_NODE(20081, 98) {
    auto node98 = GET_SKILL_NODE(98, PhaseNode_AddSkillBuffs);
    if (node98 == nullptr) {
        node98 = new PhaseNode_AddSkillBuffs(98, phase);
        node98->setConfigID({11});
        CALL_REGISTER_SKILL_NODE(20081, 98, node98)
    }
    if (noInit == true) {
        return node98;
    }
    auto node95 = GET_SKILL_NODE(95, PhaseNode_ActorFilterNewPene);
    auto node82 = GET_SKILL_NODE(82, PhaseNode_GetActorAttribute);
    if (node95 != nullptr) node98->setTarget(node95->getOutput());
    if (node82 != nullptr) node98->setAttribute(node82->getAttribute());
    return node98;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(20081, 99) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_Delay::TRIGGER_DONE, 101, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(20081, 99) {
    auto node99 = GET_SKILL_NODE(99, PhaseNode_Delay);
    if (node99 == nullptr) {
        node99 = new PhaseNode_Delay(99, phase);
        node99->setTime(1.40f);
        CALL_REGISTER_SKILL_NODE(20081, 99, node99)
    }
    if (noInit == true) {
        return node99;
    }
    return node99;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(20081, 100) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 25, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(20081, 100) {
    auto node100 = GET_SKILL_NODE(100, PhaseNode_SkillEndNotify);
    if (node100 == nullptr) {
        node100 = new PhaseNode_SkillEndNotify(100, phase);
        node100->setReturnType(false);
        CALL_REGISTER_SKILL_NODE(20081, 100, node100)
    }
    if (noInit == true) {
        return node100;
    }
    return node100;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(20081, 101) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_FALSE, 102, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_TRUE, 100, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
}

REGISTER_CREATE_SKILL_NODE(20081, 101) {
    auto node101 = GET_SKILL_NODE(101, PhaseNode_If);
    if (node101 == nullptr) {
        node101 = new PhaseNode_If(101, phase);
        node101->setCondition(false);
        CALL_REGISTER_SKILL_NODE(20081, 101, node101)
    }
    if (noInit == true) {
        return node101;
    }
    return node101;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(20081, 102) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 25, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(20081, 102) {
    auto node102 = GET_SKILL_NODE(102, PhaseNode_SkillEndNotify);
    if (node102 == nullptr) {
        node102 = new PhaseNode_SkillEndNotify(102, phase);
        node102->setReturnType(true);
        CALL_REGISTER_SKILL_NODE(20081, 102, node102)
    }
    if (noInit == true) {
        return node102;
    }
    return node102;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(20081, 103) {
}

REGISTER_CREATE_SKILL_NODE(20081, 103) {
    auto node103 = GET_SKILL_NODE(103, PhaseNode_RaiseEvent);
    if (node103 == nullptr) {
        node103 = new PhaseNode_RaiseEvent(103, phase);
        node103->setEvent("MonsterInterrupt");
        node103->setTarget(0U);
        node103->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node103->setTypeParams(0, 0);
        node103->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(20081, 103, node103)
    }
    if (noInit == true) {
        return node103;
    }
    return node103;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(20081, 104) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_Detect::TRIGGER_ON, 107, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(20081, 104) {
    auto node104 = GET_SKILL_NODE(104, PhaseNode_Detect);
    if (node104 == nullptr) {
        node104 = new PhaseNode_Detect(104, phase);
        node104->setSelf(0U);
        node104->setEvent("MonsterInterrupt");
        node104->setType(PhaseNode_Detect::Detect_Type::Interrupt_Skill);
        node104->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(20081, 104, node104)
    }
    if (noInit == true) {
        return node104;
    }
    return node104;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(20081, 105) {
}

REGISTER_CREATE_SKILL_NODE(20081, 105) {
    auto node105 = GET_SKILL_NODE(105, PhaseNode_EndPhase);
    if (node105 == nullptr) {
        node105 = new PhaseNode_EndPhase(105, phase);
        node105->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node105->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(20081, 105, node105)
    }
    if (noInit == true) {
        return node105;
    }
    return node105;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(20081, 107) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_Delay::TRIGGER_DONE, 109, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(20081, 107) {
    auto node107 = GET_SKILL_NODE(107, PhaseNode_Delay);
    if (node107 == nullptr) {
        node107 = new PhaseNode_Delay(107, phase);
        node107->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(20081, 107, node107)
    }
    if (noInit == true) {
        return node107;
    }
    return node107;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(20081, 108) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 105, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(20081, 108) {
    auto node108 = GET_SKILL_NODE(108, PhaseNode_SkillEndNotify);
    if (node108 == nullptr) {
        node108 = new PhaseNode_SkillEndNotify(108, phase);
        node108->setReturnType(false);
        CALL_REGISTER_SKILL_NODE(20081, 108, node108)
    }
    if (noInit == true) {
        return node108;
    }
    return node108;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(20081, 109) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_FALSE, 110, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_TRUE, 108, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
}

REGISTER_CREATE_SKILL_NODE(20081, 109) {
    auto node109 = GET_SKILL_NODE(109, PhaseNode_If);
    if (node109 == nullptr) {
        node109 = new PhaseNode_If(109, phase);
        node109->setCondition(false);
        CALL_REGISTER_SKILL_NODE(20081, 109, node109)
    }
    if (noInit == true) {
        return node109;
    }
    return node109;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(20081, 110) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 105, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(20081, 110) {
    auto node110 = GET_SKILL_NODE(110, PhaseNode_SkillEndNotify);
    if (node110 == nullptr) {
        node110 = new PhaseNode_SkillEndNotify(110, phase);
        node110->setReturnType(true);
        CALL_REGISTER_SKILL_NODE(20081, 110, node110)
    }
    if (noInit == true) {
        return node110;
    }
    return node110;
}

//--------------------------------------------------------------------------------
// SkillCreator_20081
//
class SkillCreator_20081 : public SkillCreator {
public:
    SkillCreator_20081() {}
    virtual ~SkillCreator_20081() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_20081

//--------------------------------------------------------------------------------
// SkillPhase_20081
//
class SkillPhase_20081 : public SkillPhase {
public:
    SkillPhase_20081(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_20081() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(20081, 1) // StartPhase
        CASE_CREATE_SKILL_NODE(20081, 2) // TriggerUpdate
        CASE_CREATE_SKILL_NODE(20081, 7) // Delay
        CASE_CREATE_SKILL_NODE(20081, 12) // SpawnCollider
        CASE_CREATE_SKILL_NODE(20081, 25) // EndPhase
        CASE_CREATE_SKILL_NODE(20081, 62) // Detect
        CASE_CREATE_SKILL_NODE(20081, 64) // EndPhase
        CASE_CREATE_SKILL_NODE(20081, 66) // GetLocation
        CASE_CREATE_SKILL_NODE(20081, 67) // GetRotation
        CASE_CREATE_SKILL_NODE(20081, 68) // OffsetCalculate
        CASE_CREATE_SKILL_NODE(20081, 69) // ResetCD
        CASE_CREATE_SKILL_NODE(20081, 70) // PlayAnimation
        CASE_CREATE_SKILL_NODE(20081, 71) // PlaySound
        CASE_CREATE_SKILL_NODE(20081, 72) // Delay
        CASE_CREATE_SKILL_NODE(20081, 73) // PlayEffect
        CASE_CREATE_SKILL_NODE(20081, 74) // If
        CASE_CREATE_SKILL_NODE(20081, 75) // PlayEffect
        CASE_CREATE_SKILL_NODE(20081, 76) // CompareFloat
        CASE_CREATE_SKILL_NODE(20081, 77) // Delay
        CASE_CREATE_SKILL_NODE(20081, 78) // StopEffect
        CASE_CREATE_SKILL_NODE(20081, 79) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(20081, 80) // TriggerCheck
        CASE_CREATE_SKILL_NODE(20081, 81) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(20081, 82) // GetActorAttribute
        CASE_CREATE_SKILL_NODE(20081, 83) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(20081, 84) // CompareFloat
        CASE_CREATE_SKILL_NODE(20081, 85) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(20081, 86) // If
        CASE_CREATE_SKILL_NODE(20081, 87) // CompareFloat
        CASE_CREATE_SKILL_NODE(20081, 88) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(20081, 89) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(20081, 90) // TriggerCheck
        CASE_CREATE_SKILL_NODE(20081, 91) // TriggerCheck
        CASE_CREATE_SKILL_NODE(20081, 92) // TriggerCheck
        CASE_CREATE_SKILL_NODE(20081, 93) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(20081, 94) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(20081, 95) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(20081, 96) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(20081, 97) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(20081, 98) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(20081, 99) // Delay
        CASE_CREATE_SKILL_NODE(20081, 100) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(20081, 101) // If
        CASE_CREATE_SKILL_NODE(20081, 102) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(20081, 103) // RaiseEvent
        CASE_CREATE_SKILL_NODE(20081, 104) // Detect
        CASE_CREATE_SKILL_NODE(20081, 105) // EndPhase
        CASE_CREATE_SKILL_NODE(20081, 107) // Delay
        CASE_CREATE_SKILL_NODE(20081, 108) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(20081, 109) // If
        CASE_CREATE_SKILL_NODE(20081, 110) // SkillEndNotify
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_20081

SkillLogic* SkillCreator_20081::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //创建阶段phase
    auto phase = new SkillPhase_20081(1, logic, 3);
    //设置phase执行器
    phase->setRunPhaseNode(1, 1);
    phase->setRunPhaseNode(2, 2);
    phase->setDetectPhaseNode(3, 62);
    phase->setDetectPhaseNode(3, 104);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_20081::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
