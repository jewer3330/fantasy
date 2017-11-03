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
REGISTER_REGISTER_SKILL_NODE(22052, 2) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_StartPhase::TRIGGER_START, 116, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_StartPhase::TRIGGER_START, 93, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(22052, 2) {
    auto node2 = GET_SKILL_NODE(2, PhaseNode_StartPhase);
    if (node2 == nullptr) {
        node2 = new PhaseNode_StartPhase(2, phase);
        CALL_REGISTER_SKILL_NODE(22052, 2, node2)
    }
    if (noInit == true) {
        return node2;
    }
    return node2;
}
//--------------------------------------------------------------------------------
// TriggerUpdate
//
REGISTER_REGISTER_SKILL_NODE(22052, 4) {
}

REGISTER_CREATE_SKILL_NODE(22052, 4) {
    auto node4 = GET_SKILL_NODE(4, PhaseNode_TriggerUpdate);
    if (node4 == nullptr) {
        node4 = new PhaseNode_TriggerUpdate(4, phase);
        CALL_REGISTER_SKILL_NODE(22052, 4, node4)
    }
    if (noInit == true) {
        return node4;
    }
    return node4;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(22052, 12) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_PlayAnimation::TRIGGER_DONE, 107, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(22052, 12) {
    auto node12 = GET_SKILL_NODE(12, PhaseNode_PlayAnimation);
    if (node12 == nullptr) {
        node12 = new PhaseNode_PlayAnimation(12, phase);
        node12->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node12->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node12->setTarget(0U);
        node12->setAnimation("Skill2S1");
        node12->setParameter("");
        node12->setValue(false);
        CALL_REGISTER_SKILL_NODE(22052, 12, node12)
    }
    if (noInit == true) {
        return node12;
    }
    return node12;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22052, 14) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnCollider>(PhaseNode_Delay::TRIGGER_DONE, 18, PhaseNode_SpawnCollider::FUNC_DO, &PhaseNode_SpawnCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(22052, 14) {
    auto node14 = GET_SKILL_NODE(14, PhaseNode_Delay);
    if (node14 == nullptr) {
        node14 = new PhaseNode_Delay(14, phase);
        node14->setTime(.35f);
        CALL_REGISTER_SKILL_NODE(22052, 14, node14)
    }
    if (noInit == true) {
        return node14;
    }
    return node14;
}
//--------------------------------------------------------------------------------
// SpawnCollider
//
REGISTER_REGISTER_SKILL_NODE(22052, 18) {
    pnode->resizeTrigger(PhaseNode_SpawnCollider::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_SpawnCollider::TRIGGER_DONE, 112, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_SpawnCollider::TRIGGER_DONE, 80, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(22052, 18) {
    auto node18 = GET_SKILL_NODE(18, PhaseNode_SpawnCollider);
    if (node18 == nullptr) {
        node18 = new PhaseNode_SpawnCollider(18, phase);
        node18->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node18->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node18->setMesh("");
        node18->setMeshScale(.00f);
        node18->setEffectID(0);
        node18->setEffectScale(.00f);
        node18->setType(PhaseNode_SpawnCollider::SpawnCollider_Type::Sector);
        node18->setTypeParams(0, 5.00f);
        node18->setTypeParams(1, 120.00f);
        node18->setTime(.30f);
        node18->setreentry(false);
        node18->setCheckPeneSound(false);
        CALL_REGISTER_SKILL_NODE(22052, 18, node18)
    }
    if (noInit == true) {
        return node18;
    }
    auto node99 = GET_SKILL_NODE(99, PhaseNode_OffsetCalculate);
    if (node99 != nullptr) node18->setPosX(node99->getOutPosX());
    if (node99 != nullptr) node18->setPosY(node99->getOutPosY());
    if (node99 != nullptr) node18->setPosZ(node99->getOutPosZ());
    if (node99 != nullptr) node18->setRotation(node99->getOutRotation());
    return node18;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(22052, 29) {
}

REGISTER_CREATE_SKILL_NODE(22052, 29) {
    auto node29 = GET_SKILL_NODE(29, PhaseNode_EndPhase);
    if (node29 == nullptr) {
        node29 = new PhaseNode_EndPhase(29, phase);
        node29->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node29->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(22052, 29, node29)
    }
    if (noInit == true) {
        return node29;
    }
    return node29;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22052, 44) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_Delay::TRIGGER_DONE, 120, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_Delay::TRIGGER_DONE, 122, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_Delay::TRIGGER_DONE, 12, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(22052, 44) {
    auto node44 = GET_SKILL_NODE(44, PhaseNode_Delay);
    if (node44 == nullptr) {
        node44 = new PhaseNode_Delay(44, phase);
        node44->setTime(.15f);
        CALL_REGISTER_SKILL_NODE(22052, 44, node44)
    }
    if (noInit == true) {
        return node44;
    }
    return node44;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(22052, 73) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 85, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 87, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(22052, 73) {
    auto node73 = GET_SKILL_NODE(73, PhaseNode_CreateTriggerNewPene);
    if (node73 == nullptr) {
        node73 = new PhaseNode_CreateTriggerNewPene(73, phase);
        node73->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::In);
        node73->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node73->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Enemy);
        node73->setOnHero(true);
        node73->setOnMinion(true);
        node73->setOnDestruct(false);
        node73->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(22052, 73, node73)
    }
    if (noInit == true) {
        return node73;
    }
    auto node18 = GET_SKILL_NODE(18, PhaseNode_SpawnCollider);
    if (node18 != nullptr) node73->setColliderID(node18->getColliderID());
    return node73;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(22052, 74) {
}

REGISTER_CREATE_SKILL_NODE(22052, 74) {
    auto node74 = GET_SKILL_NODE(74, PhaseNode_TriggerCheck);
    if (node74 == nullptr) {
        node74 = new PhaseNode_TriggerCheck(74, phase);
        auto node4 = GET_SKILL_NODE(4, PhaseNode_TriggerUpdate);
        if (node4 != nullptr) node4->addTriggerCheck(node74);
        
        CALL_REGISTER_SKILL_NODE(22052, 74, node74)
    }
    if (noInit == true) {
        return node74;
    }
    auto node83 = GET_SKILL_NODE(83, PhaseNode_CreateTriggerNewPene);
    if (node83 != nullptr) node74->setTrigger(0, node83->getTriggerID());
    return node74;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(22052, 75) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 76, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(22052, 75) {
    auto node75 = GET_SKILL_NODE(75, PhaseNode_ActorFilterNewPene);
    if (node75 == nullptr) {
        node75 = new PhaseNode_ActorFilterNewPene(75, phase);
        node75->setHero(true);
        node75->setMinion(true);
        node75->setDestruct(false);
        node75->setShield(false);
        node75->setTotalCount(0);
        node75->setPerCount(1);
        CALL_REGISTER_SKILL_NODE(22052, 75, node75)
    }
    if (noInit == true) {
        return node75;
    }
    auto node79 = GET_SKILL_NODE(79, PhaseNode_CreateTriggerNewPene);
    if (node79 != nullptr) node75->setInput(node79->getOther());
    return node75;
}
//--------------------------------------------------------------------------------
// GetActorAttribute
//
REGISTER_REGISTER_SKILL_NODE(22052, 76) {
    pnode->resizeTrigger(PhaseNode_GetActorAttribute::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 77, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 90, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 91, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 92, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
}

REGISTER_CREATE_SKILL_NODE(22052, 76) {
    auto node76 = GET_SKILL_NODE(76, PhaseNode_GetActorAttribute);
    if (node76 == nullptr) {
        node76 = new PhaseNode_GetActorAttribute(76, phase);
        node76->setTarget(0U);
        node76->setType({202});
        CALL_REGISTER_SKILL_NODE(22052, 76, node76)
    }
    if (noInit == true) {
        return node76;
    }
    return node76;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(22052, 77) {
}

REGISTER_CREATE_SKILL_NODE(22052, 77) {
    auto node77 = GET_SKILL_NODE(77, PhaseNode_AddSkillBuffs);
    if (node77 == nullptr) {
        node77 = new PhaseNode_AddSkillBuffs(77, phase);
        node77->setConfigID({11});
        CALL_REGISTER_SKILL_NODE(22052, 77, node77)
    }
    if (noInit == true) {
        return node77;
    }
    auto node75 = GET_SKILL_NODE(75, PhaseNode_ActorFilterNewPene);
    auto node76 = GET_SKILL_NODE(76, PhaseNode_GetActorAttribute);
    if (node75 != nullptr) node77->setTarget(node75->getOutput());
    if (node76 != nullptr) node77->setAttribute(node76->getAttribute());
    return node77;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(22052, 78) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 73, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_LESS, 79, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
}

REGISTER_CREATE_SKILL_NODE(22052, 78) {
    auto node78 = GET_SKILL_NODE(78, PhaseNode_CompareFloat);
    if (node78 == nullptr) {
        node78 = new PhaseNode_CompareFloat(78, phase);
        node78->setA(.00f);
        node78->setB(.00f);
        CALL_REGISTER_SKILL_NODE(22052, 78, node78)
    }
    if (noInit == true) {
        return node78;
    }
    return node78;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(22052, 79) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 84, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 75, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(22052, 79) {
    auto node79 = GET_SKILL_NODE(79, PhaseNode_CreateTriggerNewPene);
    if (node79 == nullptr) {
        node79 = new PhaseNode_CreateTriggerNewPene(79, phase);
        node79->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::Tick);
        node79->setTypeParams(0, .00f);
        node79->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node79->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Enemy);
        node79->setOnHero(true);
        node79->setOnMinion(true);
        node79->setOnDestruct(false);
        node79->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(22052, 79, node79)
    }
    if (noInit == true) {
        return node79;
    }
    auto node18 = GET_SKILL_NODE(18, PhaseNode_SpawnCollider);
    if (node18 != nullptr) node79->setColliderID(node18->getColliderID());
    return node79;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(22052, 80) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_If::TRIGGER_FALSE, 81, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_If::TRIGGER_TRUE, 78, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(22052, 80) {
    auto node80 = GET_SKILL_NODE(80, PhaseNode_If);
    if (node80 == nullptr) {
        node80 = new PhaseNode_If(80, phase);
        node80->setCondition(true);
        CALL_REGISTER_SKILL_NODE(22052, 80, node80)
    }
    if (noInit == true) {
        return node80;
    }
    return node80;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(22052, 81) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 83, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_LESS, 82, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
}

REGISTER_CREATE_SKILL_NODE(22052, 81) {
    auto node81 = GET_SKILL_NODE(81, PhaseNode_CompareFloat);
    if (node81 == nullptr) {
        node81 = new PhaseNode_CompareFloat(81, phase);
        node81->setA(.00f);
        node81->setB(.00f);
        CALL_REGISTER_SKILL_NODE(22052, 81, node81)
    }
    if (noInit == true) {
        return node81;
    }
    return node81;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(22052, 82) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 86, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 88, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(22052, 82) {
    auto node82 = GET_SKILL_NODE(82, PhaseNode_CreateTriggerNewPene);
    if (node82 == nullptr) {
        node82 = new PhaseNode_CreateTriggerNewPene(82, phase);
        node82->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::Tick);
        node82->setTypeParams(0, .00f);
        node82->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node82->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Friend);
        node82->setOnHero(true);
        node82->setOnMinion(true);
        node82->setOnDestruct(false);
        node82->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(22052, 82, node82)
    }
    if (noInit == true) {
        return node82;
    }
    auto node18 = GET_SKILL_NODE(18, PhaseNode_SpawnCollider);
    if (node18 != nullptr) node82->setColliderID(node18->getColliderID());
    return node82;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(22052, 83) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 74, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 89, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(22052, 83) {
    auto node83 = GET_SKILL_NODE(83, PhaseNode_CreateTriggerNewPene);
    if (node83 == nullptr) {
        node83 = new PhaseNode_CreateTriggerNewPene(83, phase);
        node83->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::In);
        node83->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node83->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Friend);
        node83->setOnHero(true);
        node83->setOnMinion(true);
        node83->setOnDestruct(false);
        node83->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(22052, 83, node83)
    }
    if (noInit == true) {
        return node83;
    }
    auto node18 = GET_SKILL_NODE(18, PhaseNode_SpawnCollider);
    if (node18 != nullptr) node83->setColliderID(node18->getColliderID());
    return node83;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(22052, 84) {
}

REGISTER_CREATE_SKILL_NODE(22052, 84) {
    auto node84 = GET_SKILL_NODE(84, PhaseNode_TriggerCheck);
    if (node84 == nullptr) {
        node84 = new PhaseNode_TriggerCheck(84, phase);
        auto node4 = GET_SKILL_NODE(4, PhaseNode_TriggerUpdate);
        if (node4 != nullptr) node4->addTriggerCheck(node84);
        
        CALL_REGISTER_SKILL_NODE(22052, 84, node84)
    }
    if (noInit == true) {
        return node84;
    }
    auto node79 = GET_SKILL_NODE(79, PhaseNode_CreateTriggerNewPene);
    if (node79 != nullptr) node84->setTrigger(0, node79->getTriggerID());
    return node84;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(22052, 85) {
}

REGISTER_CREATE_SKILL_NODE(22052, 85) {
    auto node85 = GET_SKILL_NODE(85, PhaseNode_TriggerCheck);
    if (node85 == nullptr) {
        node85 = new PhaseNode_TriggerCheck(85, phase);
        auto node4 = GET_SKILL_NODE(4, PhaseNode_TriggerUpdate);
        if (node4 != nullptr) node4->addTriggerCheck(node85);
        
        CALL_REGISTER_SKILL_NODE(22052, 85, node85)
    }
    if (noInit == true) {
        return node85;
    }
    auto node73 = GET_SKILL_NODE(73, PhaseNode_CreateTriggerNewPene);
    if (node73 != nullptr) node85->setTrigger(0, node73->getTriggerID());
    return node85;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(22052, 86) {
}

REGISTER_CREATE_SKILL_NODE(22052, 86) {
    auto node86 = GET_SKILL_NODE(86, PhaseNode_TriggerCheck);
    if (node86 == nullptr) {
        node86 = new PhaseNode_TriggerCheck(86, phase);
        auto node4 = GET_SKILL_NODE(4, PhaseNode_TriggerUpdate);
        if (node4 != nullptr) node4->addTriggerCheck(node86);
        
        CALL_REGISTER_SKILL_NODE(22052, 86, node86)
    }
    if (noInit == true) {
        return node86;
    }
    auto node82 = GET_SKILL_NODE(82, PhaseNode_CreateTriggerNewPene);
    if (node82 != nullptr) node86->setTrigger(0, node82->getTriggerID());
    return node86;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(22052, 87) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 76, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(22052, 87) {
    auto node87 = GET_SKILL_NODE(87, PhaseNode_ActorFilterNewPene);
    if (node87 == nullptr) {
        node87 = new PhaseNode_ActorFilterNewPene(87, phase);
        node87->setHero(true);
        node87->setMinion(true);
        node87->setDestruct(false);
        node87->setShield(false);
        node87->setTotalCount(0);
        node87->setPerCount(1);
        CALL_REGISTER_SKILL_NODE(22052, 87, node87)
    }
    if (noInit == true) {
        return node87;
    }
    auto node73 = GET_SKILL_NODE(73, PhaseNode_CreateTriggerNewPene);
    if (node73 != nullptr) node87->setInput(node73->getOther());
    return node87;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(22052, 88) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 76, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(22052, 88) {
    auto node88 = GET_SKILL_NODE(88, PhaseNode_ActorFilterNewPene);
    if (node88 == nullptr) {
        node88 = new PhaseNode_ActorFilterNewPene(88, phase);
        node88->setHero(true);
        node88->setMinion(true);
        node88->setDestruct(false);
        node88->setShield(false);
        node88->setTotalCount(0);
        node88->setPerCount(1);
        CALL_REGISTER_SKILL_NODE(22052, 88, node88)
    }
    if (noInit == true) {
        return node88;
    }
    auto node82 = GET_SKILL_NODE(82, PhaseNode_CreateTriggerNewPene);
    if (node82 != nullptr) node88->setInput(node82->getOther());
    return node88;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(22052, 89) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 76, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(22052, 89) {
    auto node89 = GET_SKILL_NODE(89, PhaseNode_ActorFilterNewPene);
    if (node89 == nullptr) {
        node89 = new PhaseNode_ActorFilterNewPene(89, phase);
        node89->setHero(true);
        node89->setMinion(true);
        node89->setDestruct(false);
        node89->setShield(false);
        node89->setTotalCount(0);
        node89->setPerCount(1);
        CALL_REGISTER_SKILL_NODE(22052, 89, node89)
    }
    if (noInit == true) {
        return node89;
    }
    auto node83 = GET_SKILL_NODE(83, PhaseNode_CreateTriggerNewPene);
    if (node83 != nullptr) node89->setInput(node83->getOther());
    return node89;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(22052, 90) {
}

REGISTER_CREATE_SKILL_NODE(22052, 90) {
    auto node90 = GET_SKILL_NODE(90, PhaseNode_AddSkillBuffs);
    if (node90 == nullptr) {
        node90 = new PhaseNode_AddSkillBuffs(90, phase);
        node90->setConfigID({11});
        CALL_REGISTER_SKILL_NODE(22052, 90, node90)
    }
    if (noInit == true) {
        return node90;
    }
    auto node87 = GET_SKILL_NODE(87, PhaseNode_ActorFilterNewPene);
    auto node76 = GET_SKILL_NODE(76, PhaseNode_GetActorAttribute);
    if (node87 != nullptr) node90->setTarget(node87->getOutput());
    if (node76 != nullptr) node90->setAttribute(node76->getAttribute());
    return node90;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(22052, 91) {
}

REGISTER_CREATE_SKILL_NODE(22052, 91) {
    auto node91 = GET_SKILL_NODE(91, PhaseNode_AddSkillBuffs);
    if (node91 == nullptr) {
        node91 = new PhaseNode_AddSkillBuffs(91, phase);
        node91->setConfigID({11});
        CALL_REGISTER_SKILL_NODE(22052, 91, node91)
    }
    if (noInit == true) {
        return node91;
    }
    auto node88 = GET_SKILL_NODE(88, PhaseNode_ActorFilterNewPene);
    auto node76 = GET_SKILL_NODE(76, PhaseNode_GetActorAttribute);
    if (node88 != nullptr) node91->setTarget(node88->getOutput());
    if (node76 != nullptr) node91->setAttribute(node76->getAttribute());
    return node91;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(22052, 92) {
}

REGISTER_CREATE_SKILL_NODE(22052, 92) {
    auto node92 = GET_SKILL_NODE(92, PhaseNode_AddSkillBuffs);
    if (node92 == nullptr) {
        node92 = new PhaseNode_AddSkillBuffs(92, phase);
        node92->setConfigID({11});
        CALL_REGISTER_SKILL_NODE(22052, 92, node92)
    }
    if (noInit == true) {
        return node92;
    }
    auto node89 = GET_SKILL_NODE(89, PhaseNode_ActorFilterNewPene);
    auto node76 = GET_SKILL_NODE(76, PhaseNode_GetActorAttribute);
    if (node89 != nullptr) node92->setTarget(node89->getOutput());
    if (node76 != nullptr) node92->setAttribute(node76->getAttribute());
    return node92;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(22052, 93) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_ResetCD::TRIGGER_DONE, 94, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(22052, 93) {
    auto node93 = GET_SKILL_NODE(93, PhaseNode_ResetCD);
    if (node93 == nullptr) {
        node93 = new PhaseNode_ResetCD(93, phase);
        node93->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node93->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node93->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(22052, 93, node93)
    }
    if (noInit == true) {
        return node93;
    }
    return node93;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(22052, 94) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_PlayAnimation::TRIGGER_DONE, 95, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(22052, 94) {
    auto node94 = GET_SKILL_NODE(94, PhaseNode_PlayAnimation);
    if (node94 == nullptr) {
        node94 = new PhaseNode_PlayAnimation(94, phase);
        node94->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node94->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node94->setTarget(0U);
        node94->setAnimation("Idle");
        node94->setParameter("");
        node94->setValue(false);
        CALL_REGISTER_SKILL_NODE(22052, 94, node94)
    }
    if (noInit == true) {
        return node94;
    }
    return node94;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(22052, 95) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlaySound::TRIGGER_DONE, 96, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(22052, 95) {
    auto node95 = GET_SKILL_NODE(95, PhaseNode_PlaySound);
    if (node95 == nullptr) {
        node95 = new PhaseNode_PlaySound(95, phase);
        node95->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node95->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node95->setSoundID("");
        node95->setTarget(0U);
        node95->setUsePos(false);
        node95->setPosX(.00f);
        node95->setPosY(.00f);
        node95->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(22052, 95, node95)
    }
    if (noInit == true) {
        return node95;
    }
    return node95;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22052, 96) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_Delay::TRIGGER_DONE, 97, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(22052, 96) {
    auto node96 = GET_SKILL_NODE(96, PhaseNode_Delay);
    if (node96 == nullptr) {
        node96 = new PhaseNode_Delay(96, phase);
        node96->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(22052, 96, node96)
    }
    if (noInit == true) {
        return node96;
    }
    return node96;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(22052, 97) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetRotation>(PhaseNode_GetLocation::TRIGGER_DONE, 98, PhaseNode_GetRotation::FUNC_DO, &PhaseNode_GetRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(22052, 97) {
    auto node97 = GET_SKILL_NODE(97, PhaseNode_GetLocation);
    if (node97 == nullptr) {
        node97 = new PhaseNode_GetLocation(97, phase);
        node97->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node97->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(22052, 97, node97)
    }
    if (noInit == true) {
        return node97;
    }
    return node97;
}
//--------------------------------------------------------------------------------
// GetRotation
//
REGISTER_REGISTER_SKILL_NODE(22052, 98) {
    pnode->resizeTrigger(PhaseNode_GetRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_OffsetCalculate>(PhaseNode_GetRotation::TRIGGER_DONE, 99, PhaseNode_OffsetCalculate::FUNC_DO, &PhaseNode_OffsetCalculate::Do);
}

REGISTER_CREATE_SKILL_NODE(22052, 98) {
    auto node98 = GET_SKILL_NODE(98, PhaseNode_GetRotation);
    if (node98 == nullptr) {
        node98 = new PhaseNode_GetRotation(98, phase);
        node98->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node98->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(22052, 98, node98)
    }
    if (noInit == true) {
        return node98;
    }
    return node98;
}
//--------------------------------------------------------------------------------
// OffsetCalculate
//
REGISTER_REGISTER_SKILL_NODE(22052, 99) {
    pnode->resizeTrigger(PhaseNode_OffsetCalculate::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 101, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(22052, 99) {
    auto node99 = GET_SKILL_NODE(99, PhaseNode_OffsetCalculate);
    if (node99 == nullptr) {
        node99 = new PhaseNode_OffsetCalculate(99, phase);
        node99->setPosZ(.00f);
        node99->setOffsetX(.00f);
        node99->setOffsetY(.00f);
        node99->setOffsetZ(.00f);
        node99->setRotOffset(.00f);
        CALL_REGISTER_SKILL_NODE(22052, 99, node99)
    }
    if (noInit == true) {
        return node99;
    }
    auto node97 = GET_SKILL_NODE(97, PhaseNode_GetLocation);
    auto node98 = GET_SKILL_NODE(98, PhaseNode_GetRotation);
    if (node97 != nullptr) node99->setPosX(node97->getX());
    if (node97 != nullptr) node99->setPosY(node97->getY());
    if (node98 != nullptr) node99->setRotation(node98->getAngle());
    return node99;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(22052, 100) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_PlayEffect::TRIGGER_DONE, 103, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(22052, 100) {
    auto node100 = GET_SKILL_NODE(100, PhaseNode_PlayEffect);
    if (node100 == nullptr) {
        node100 = new PhaseNode_PlayEffect(100, phase);
        node100->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node100->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node100->setEffectID(220600);
        node100->setChangeColor(false);
        node100->setType(PhaseNode_PlayEffect::PlayEffect_Type::WithTarget);
        node100->getVars().reserve(5);
        node100->getVars().setVariable<uint64_t>(0, 0U);
        node100->getVars().setVariable<std::string>(1, "");
        node100->getVars().setVariable<float>(2, .00f);
        node100->getVars().setVariable<float>(3, .00f);
        node100->getVars().setVariable<float>(4, .00f);
        node100->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(22052, 100, node100)
    }
    if (noInit == true) {
        return node100;
    }
    auto node99 = GET_SKILL_NODE(99, PhaseNode_OffsetCalculate);
    if (node99 != nullptr) node100->getVars().setVariable<float>(2, node99->getOutPosX());
    if (node99 != nullptr) node100->getVars().setVariable<float>(3, node99->getOutPosY());
    if (node99 != nullptr) node100->getVars().setVariable<float>(4, node99->getOutPosZ());
    if (node99 != nullptr) node100->setRotation(node99->getOutRotation());
    return node100;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(22052, 101) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_FALSE, 102, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_TRUE, 100, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(22052, 101) {
    auto node101 = GET_SKILL_NODE(101, PhaseNode_If);
    if (node101 == nullptr) {
        node101 = new PhaseNode_If(101, phase);
        node101->setCondition(false);
        CALL_REGISTER_SKILL_NODE(22052, 101, node101)
    }
    if (noInit == true) {
        return node101;
    }
    return node101;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(22052, 102) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_PlayEffect::TRIGGER_DONE, 103, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(22052, 102) {
    auto node102 = GET_SKILL_NODE(102, PhaseNode_PlayEffect);
    if (node102 == nullptr) {
        node102 = new PhaseNode_PlayEffect(102, phase);
        node102->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node102->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node102->setEffectID(220600);
        node102->setChangeColor(false);
        node102->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node102->getVars().reserve(3);
        node102->getVars().setVariable<float>(0, .00f);
        node102->getVars().setVariable<float>(1, .00f);
        node102->getVars().setVariable<float>(2, .00f);
        node102->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(22052, 102, node102)
    }
    if (noInit == true) {
        return node102;
    }
    auto node99 = GET_SKILL_NODE(99, PhaseNode_OffsetCalculate);
    if (node99 != nullptr) node102->getVars().setVariable<float>(0, node99->getOutPosX());
    if (node99 != nullptr) node102->getVars().setVariable<float>(1, node99->getOutPosY());
    if (node99 != nullptr) node102->getVars().setVariable<float>(2, node99->getOutPosZ());
    if (node99 != nullptr) node102->setRotation(node99->getOutRotation());
    return node102;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(22052, 103) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 44, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_LESS, 104, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_LESS, 44, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(22052, 103) {
    auto node103 = GET_SKILL_NODE(103, PhaseNode_CompareFloat);
    if (node103 == nullptr) {
        node103 = new PhaseNode_CompareFloat(103, phase);
        node103->setA(.00f);
        node103->setB(.80f);
        CALL_REGISTER_SKILL_NODE(22052, 103, node103)
    }
    if (noInit == true) {
        return node103;
    }
    return node103;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22052, 104) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StopEffect>(PhaseNode_Delay::TRIGGER_DONE, 105, PhaseNode_StopEffect::FUNC_DO, &PhaseNode_StopEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(22052, 104) {
    auto node104 = GET_SKILL_NODE(104, PhaseNode_Delay);
    if (node104 == nullptr) {
        node104 = new PhaseNode_Delay(104, phase);
        node104->setTime(.80f);
        CALL_REGISTER_SKILL_NODE(22052, 104, node104)
    }
    if (noInit == true) {
        return node104;
    }
    return node104;
}
//--------------------------------------------------------------------------------
// StopEffect
//
REGISTER_REGISTER_SKILL_NODE(22052, 105) {
}

REGISTER_CREATE_SKILL_NODE(22052, 105) {
    auto node105 = GET_SKILL_NODE(105, PhaseNode_StopEffect);
    if (node105 == nullptr) {
        node105 = new PhaseNode_StopEffect(105, phase);
        node105->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node105->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node105->setEffectID(220600);
        CALL_REGISTER_SKILL_NODE(22052, 105, node105)
    }
    if (noInit == true) {
        return node105;
    }
    return node105;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(22052, 106) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_PlayEffect::TRIGGER_DONE, 109, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(22052, 106) {
    auto node106 = GET_SKILL_NODE(106, PhaseNode_PlayEffect);
    if (node106 == nullptr) {
        node106 = new PhaseNode_PlayEffect(106, phase);
        node106->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node106->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node106->setEffectID(220621);
        node106->setChangeColor(false);
        node106->setType(PhaseNode_PlayEffect::PlayEffect_Type::WithTarget);
        node106->getVars().reserve(5);
        node106->getVars().setVariable<uint64_t>(0, 0U);
        node106->getVars().setVariable<std::string>(1, "");
        node106->getVars().setVariable<float>(2, .00f);
        node106->getVars().setVariable<float>(3, .00f);
        node106->getVars().setVariable<float>(4, .00f);
        node106->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(22052, 106, node106)
    }
    if (noInit == true) {
        return node106;
    }
    auto node99 = GET_SKILL_NODE(99, PhaseNode_OffsetCalculate);
    if (node99 != nullptr) node106->getVars().setVariable<float>(2, node99->getOutPosX());
    if (node99 != nullptr) node106->getVars().setVariable<float>(3, node99->getOutPosY());
    if (node99 != nullptr) node106->getVars().setVariable<float>(4, node99->getOutPosZ());
    if (node99 != nullptr) node106->setRotation(node99->getOutRotation());
    return node106;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(22052, 107) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_FALSE, 108, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_TRUE, 106, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(22052, 107) {
    auto node107 = GET_SKILL_NODE(107, PhaseNode_If);
    if (node107 == nullptr) {
        node107 = new PhaseNode_If(107, phase);
        node107->setCondition(false);
        CALL_REGISTER_SKILL_NODE(22052, 107, node107)
    }
    if (noInit == true) {
        return node107;
    }
    return node107;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(22052, 108) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_PlayEffect::TRIGGER_DONE, 109, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(22052, 108) {
    auto node108 = GET_SKILL_NODE(108, PhaseNode_PlayEffect);
    if (node108 == nullptr) {
        node108 = new PhaseNode_PlayEffect(108, phase);
        node108->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node108->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node108->setEffectID(220621);
        node108->setChangeColor(false);
        node108->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node108->getVars().reserve(3);
        node108->getVars().setVariable<float>(0, .00f);
        node108->getVars().setVariable<float>(1, .00f);
        node108->getVars().setVariable<float>(2, .00f);
        node108->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(22052, 108, node108)
    }
    if (noInit == true) {
        return node108;
    }
    auto node99 = GET_SKILL_NODE(99, PhaseNode_OffsetCalculate);
    if (node99 != nullptr) node108->getVars().setVariable<float>(0, node99->getOutPosX());
    if (node99 != nullptr) node108->getVars().setVariable<float>(1, node99->getOutPosY());
    if (node99 != nullptr) node108->getVars().setVariable<float>(2, node99->getOutPosZ());
    if (node99 != nullptr) node108->setRotation(node99->getOutRotation());
    return node108;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(22052, 109) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 14, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_LESS, 110, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_LESS, 14, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(22052, 109) {
    auto node109 = GET_SKILL_NODE(109, PhaseNode_CompareFloat);
    if (node109 == nullptr) {
        node109 = new PhaseNode_CompareFloat(109, phase);
        node109->setA(.00f);
        node109->setB(.00f);
        CALL_REGISTER_SKILL_NODE(22052, 109, node109)
    }
    if (noInit == true) {
        return node109;
    }
    return node109;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22052, 110) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StopEffect>(PhaseNode_Delay::TRIGGER_DONE, 111, PhaseNode_StopEffect::FUNC_DO, &PhaseNode_StopEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(22052, 110) {
    auto node110 = GET_SKILL_NODE(110, PhaseNode_Delay);
    if (node110 == nullptr) {
        node110 = new PhaseNode_Delay(110, phase);
        node110->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(22052, 110, node110)
    }
    if (noInit == true) {
        return node110;
    }
    return node110;
}
//--------------------------------------------------------------------------------
// StopEffect
//
REGISTER_REGISTER_SKILL_NODE(22052, 111) {
}

REGISTER_CREATE_SKILL_NODE(22052, 111) {
    auto node111 = GET_SKILL_NODE(111, PhaseNode_StopEffect);
    if (node111 == nullptr) {
        node111 = new PhaseNode_StopEffect(111, phase);
        node111->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node111->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node111->setEffectID(220621);
        CALL_REGISTER_SKILL_NODE(22052, 111, node111)
    }
    if (noInit == true) {
        return node111;
    }
    return node111;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22052, 112) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_Delay::TRIGGER_DONE, 114, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(22052, 112) {
    auto node112 = GET_SKILL_NODE(112, PhaseNode_Delay);
    if (node112 == nullptr) {
        node112 = new PhaseNode_Delay(112, phase);
        node112->setTime(1.00f);
        CALL_REGISTER_SKILL_NODE(22052, 112, node112)
    }
    if (noInit == true) {
        return node112;
    }
    return node112;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(22052, 113) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 29, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(22052, 113) {
    auto node113 = GET_SKILL_NODE(113, PhaseNode_SkillEndNotify);
    if (node113 == nullptr) {
        node113 = new PhaseNode_SkillEndNotify(113, phase);
        node113->setReturnType(false);
        CALL_REGISTER_SKILL_NODE(22052, 113, node113)
    }
    if (noInit == true) {
        return node113;
    }
    return node113;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(22052, 114) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_FALSE, 115, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_TRUE, 113, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
}

REGISTER_CREATE_SKILL_NODE(22052, 114) {
    auto node114 = GET_SKILL_NODE(114, PhaseNode_If);
    if (node114 == nullptr) {
        node114 = new PhaseNode_If(114, phase);
        node114->setCondition(false);
        CALL_REGISTER_SKILL_NODE(22052, 114, node114)
    }
    if (noInit == true) {
        return node114;
    }
    return node114;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(22052, 115) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 29, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(22052, 115) {
    auto node115 = GET_SKILL_NODE(115, PhaseNode_SkillEndNotify);
    if (node115 == nullptr) {
        node115 = new PhaseNode_SkillEndNotify(115, phase);
        node115->setReturnType(true);
        CALL_REGISTER_SKILL_NODE(22052, 115, node115)
    }
    if (noInit == true) {
        return node115;
    }
    return node115;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(22052, 116) {
}

REGISTER_CREATE_SKILL_NODE(22052, 116) {
    auto node116 = GET_SKILL_NODE(116, PhaseNode_RaiseEvent);
    if (node116 == nullptr) {
        node116 = new PhaseNode_RaiseEvent(116, phase);
        node116->setEvent("MonsterInterrupt");
        node116->setTarget(0U);
        node116->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node116->setTypeParams(0, 0);
        node116->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(22052, 116, node116)
    }
    if (noInit == true) {
        return node116;
    }
    return node116;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(22052, 117) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_Detect::TRIGGER_ON, 124, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(22052, 117) {
    auto node117 = GET_SKILL_NODE(117, PhaseNode_Detect);
    if (node117 == nullptr) {
        node117 = new PhaseNode_Detect(117, phase);
        node117->setSelf(0U);
        node117->setEvent("MonsterInterrupt");
        node117->setType(PhaseNode_Detect::Detect_Type::Interrupt_Skill);
        node117->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(22052, 117, node117)
    }
    if (noInit == true) {
        return node117;
    }
    return node117;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(22052, 118) {
}

REGISTER_CREATE_SKILL_NODE(22052, 118) {
    auto node118 = GET_SKILL_NODE(118, PhaseNode_EndPhase);
    if (node118 == nullptr) {
        node118 = new PhaseNode_EndPhase(118, phase);
        node118->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node118->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(22052, 118, node118)
    }
    if (noInit == true) {
        return node118;
    }
    return node118;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22052, 120) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_Delay::TRIGGER_DONE, 121, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(22052, 120) {
    auto node120 = GET_SKILL_NODE(120, PhaseNode_Delay);
    if (node120 == nullptr) {
        node120 = new PhaseNode_Delay(120, phase);
        node120->setTime(.30f);
        CALL_REGISTER_SKILL_NODE(22052, 120, node120)
    }
    if (noInit == true) {
        return node120;
    }
    return node120;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(22052, 121) {
}

REGISTER_CREATE_SKILL_NODE(22052, 121) {
    auto node121 = GET_SKILL_NODE(121, PhaseNode_PlaySound);
    if (node121 == nullptr) {
        node121 = new PhaseNode_PlaySound(121, phase);
        node121->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node121->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node121->setSoundID("SE_MON2206_ATK_A");
        node121->setTarget(0U);
        node121->setUsePos(false);
        node121->setPosX(.00f);
        node121->setPosY(.00f);
        node121->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(22052, 121, node121)
    }
    if (noInit == true) {
        return node121;
    }
    return node121;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22052, 122) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_Delay::TRIGGER_DONE, 123, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(22052, 122) {
    auto node122 = GET_SKILL_NODE(122, PhaseNode_Delay);
    if (node122 == nullptr) {
        node122 = new PhaseNode_Delay(122, phase);
        node122->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(22052, 122, node122)
    }
    if (noInit == true) {
        return node122;
    }
    return node122;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(22052, 123) {
}

REGISTER_CREATE_SKILL_NODE(22052, 123) {
    auto node123 = GET_SKILL_NODE(123, PhaseNode_PlaySound);
    if (node123 == nullptr) {
        node123 = new PhaseNode_PlaySound(123, phase);
        node123->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node123->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node123->setSoundID("VO_MON2206_ATK");
        node123->setTarget(0U);
        node123->setUsePos(false);
        node123->setPosX(.00f);
        node123->setPosY(.00f);
        node123->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(22052, 123, node123)
    }
    if (noInit == true) {
        return node123;
    }
    return node123;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22052, 124) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_Delay::TRIGGER_DONE, 126, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(22052, 124) {
    auto node124 = GET_SKILL_NODE(124, PhaseNode_Delay);
    if (node124 == nullptr) {
        node124 = new PhaseNode_Delay(124, phase);
        node124->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(22052, 124, node124)
    }
    if (noInit == true) {
        return node124;
    }
    return node124;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(22052, 125) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 118, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(22052, 125) {
    auto node125 = GET_SKILL_NODE(125, PhaseNode_SkillEndNotify);
    if (node125 == nullptr) {
        node125 = new PhaseNode_SkillEndNotify(125, phase);
        node125->setReturnType(false);
        CALL_REGISTER_SKILL_NODE(22052, 125, node125)
    }
    if (noInit == true) {
        return node125;
    }
    return node125;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(22052, 126) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_FALSE, 127, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_TRUE, 125, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
}

REGISTER_CREATE_SKILL_NODE(22052, 126) {
    auto node126 = GET_SKILL_NODE(126, PhaseNode_If);
    if (node126 == nullptr) {
        node126 = new PhaseNode_If(126, phase);
        node126->setCondition(false);
        CALL_REGISTER_SKILL_NODE(22052, 126, node126)
    }
    if (noInit == true) {
        return node126;
    }
    return node126;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(22052, 127) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 118, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(22052, 127) {
    auto node127 = GET_SKILL_NODE(127, PhaseNode_SkillEndNotify);
    if (node127 == nullptr) {
        node127 = new PhaseNode_SkillEndNotify(127, phase);
        node127->setReturnType(true);
        CALL_REGISTER_SKILL_NODE(22052, 127, node127)
    }
    if (noInit == true) {
        return node127;
    }
    return node127;
}

//--------------------------------------------------------------------------------
// SkillCreator_22052
//
class SkillCreator_22052 : public SkillCreator {
public:
    SkillCreator_22052() {}
    virtual ~SkillCreator_22052() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_22052

//--------------------------------------------------------------------------------
// SkillPhase_22052
//
class SkillPhase_22052 : public SkillPhase {
public:
    SkillPhase_22052(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_22052() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(22052, 2) // StartPhase
        CASE_CREATE_SKILL_NODE(22052, 4) // TriggerUpdate
        CASE_CREATE_SKILL_NODE(22052, 12) // PlayAnimation
        CASE_CREATE_SKILL_NODE(22052, 14) // Delay
        CASE_CREATE_SKILL_NODE(22052, 18) // SpawnCollider
        CASE_CREATE_SKILL_NODE(22052, 29) // EndPhase
        CASE_CREATE_SKILL_NODE(22052, 44) // Delay
        CASE_CREATE_SKILL_NODE(22052, 73) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(22052, 74) // TriggerCheck
        CASE_CREATE_SKILL_NODE(22052, 75) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(22052, 76) // GetActorAttribute
        CASE_CREATE_SKILL_NODE(22052, 77) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(22052, 78) // CompareFloat
        CASE_CREATE_SKILL_NODE(22052, 79) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(22052, 80) // If
        CASE_CREATE_SKILL_NODE(22052, 81) // CompareFloat
        CASE_CREATE_SKILL_NODE(22052, 82) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(22052, 83) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(22052, 84) // TriggerCheck
        CASE_CREATE_SKILL_NODE(22052, 85) // TriggerCheck
        CASE_CREATE_SKILL_NODE(22052, 86) // TriggerCheck
        CASE_CREATE_SKILL_NODE(22052, 87) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(22052, 88) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(22052, 89) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(22052, 90) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(22052, 91) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(22052, 92) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(22052, 93) // ResetCD
        CASE_CREATE_SKILL_NODE(22052, 94) // PlayAnimation
        CASE_CREATE_SKILL_NODE(22052, 95) // PlaySound
        CASE_CREATE_SKILL_NODE(22052, 96) // Delay
        CASE_CREATE_SKILL_NODE(22052, 97) // GetLocation
        CASE_CREATE_SKILL_NODE(22052, 98) // GetRotation
        CASE_CREATE_SKILL_NODE(22052, 99) // OffsetCalculate
        CASE_CREATE_SKILL_NODE(22052, 100) // PlayEffect
        CASE_CREATE_SKILL_NODE(22052, 101) // If
        CASE_CREATE_SKILL_NODE(22052, 102) // PlayEffect
        CASE_CREATE_SKILL_NODE(22052, 103) // CompareFloat
        CASE_CREATE_SKILL_NODE(22052, 104) // Delay
        CASE_CREATE_SKILL_NODE(22052, 105) // StopEffect
        CASE_CREATE_SKILL_NODE(22052, 106) // PlayEffect
        CASE_CREATE_SKILL_NODE(22052, 107) // If
        CASE_CREATE_SKILL_NODE(22052, 108) // PlayEffect
        CASE_CREATE_SKILL_NODE(22052, 109) // CompareFloat
        CASE_CREATE_SKILL_NODE(22052, 110) // Delay
        CASE_CREATE_SKILL_NODE(22052, 111) // StopEffect
        CASE_CREATE_SKILL_NODE(22052, 112) // Delay
        CASE_CREATE_SKILL_NODE(22052, 113) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(22052, 114) // If
        CASE_CREATE_SKILL_NODE(22052, 115) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(22052, 116) // RaiseEvent
        CASE_CREATE_SKILL_NODE(22052, 117) // Detect
        CASE_CREATE_SKILL_NODE(22052, 118) // EndPhase
        CASE_CREATE_SKILL_NODE(22052, 120) // Delay
        CASE_CREATE_SKILL_NODE(22052, 121) // PlaySound
        CASE_CREATE_SKILL_NODE(22052, 122) // Delay
        CASE_CREATE_SKILL_NODE(22052, 123) // PlaySound
        CASE_CREATE_SKILL_NODE(22052, 124) // Delay
        CASE_CREATE_SKILL_NODE(22052, 125) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(22052, 126) // If
        CASE_CREATE_SKILL_NODE(22052, 127) // SkillEndNotify
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_22052

SkillLogic* SkillCreator_22052::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //创建阶段phase
    auto phase = new SkillPhase_22052(1, logic, 3);
    //设置phase执行器
    phase->setRunPhaseNode(1, 2);
    phase->setRunPhaseNode(2, 4);
    phase->setDetectPhaseNode(3, 117);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_22052::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
