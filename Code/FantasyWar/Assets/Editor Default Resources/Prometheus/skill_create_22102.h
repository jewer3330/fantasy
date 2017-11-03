#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

#include "skill_psnode_actorfilternewpene.h"
#include "skill_psnode_addskillbuffs.h"
#include "skill_psnode_attachto.h"
#include "skill_psnode_comparefloat.h"
#include "skill_psnode_createtriggernewpene.h"
#include "skill_psnode_delay.h"
#include "skill_psnode_detect.h"
#include "skill_psnode_distance.h"
#include "skill_psnode_getactorattribute.h"
#include "skill_psnode_getlocation.h"
#include "skill_psnode_getrotation.h"
#include "skill_psnode_getself.h"
#include "skill_psnode_if.h"
#include "skill_psnode_offsetcalculate.h"
#include "skill_psnode_setfloat.h"
#include "skill_psnode_skillendnotify.h"
#include "skill_psnode_spawncollider.h"
#include "skill_psnode_startphase.h"
#include "skill_psnode_triggercheck.h"
#include "skill_psnode_triggerupdate.h"

namespace pvp {

//变量声明
uint64_t Variable_22102_Fire = 0;
uint64_t Variable_22102_LastX = 0;
uint64_t Variable_22102_LastY = 0;
//--------------------------------------------------------------------------------
// StartPhase
//
REGISTER_REGISTER_SKILL_NODE(22102, 3) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_StartPhase::TRIGGER_START, 97, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(22102, 3) {
    auto node3 = GET_SKILL_NODE(3, PhaseNode_StartPhase);
    if (node3 == nullptr) {
        node3 = new PhaseNode_StartPhase(3, phase);
        CALL_REGISTER_SKILL_NODE(22102, 3, node3)
    }
    if (noInit == true) {
        return node3;
    }
    return node3;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(22102, 5) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_Detect::TRIGGER_ON, 104, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(22102, 5) {
    auto node5 = GET_SKILL_NODE(5, PhaseNode_Detect);
    if (node5 == nullptr) {
        node5 = new PhaseNode_Detect(5, phase);
        node5->setSelf(0U);
        node5->setEvent("");
        node5->setType(PhaseNode_Detect::Detect_Type::Actor_POS);
        node5->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(22102, 5, node5)
    }
    if (noInit == true) {
        return node5;
    }
    return node5;
}
//--------------------------------------------------------------------------------
// SpawnCollider
//
REGISTER_REGISTER_SKILL_NODE(22102, 15) {
    pnode->resizeTrigger(PhaseNode_SpawnCollider::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetSelf>(PhaseNode_SpawnCollider::TRIGGER_DONE, 76, PhaseNode_GetSelf::FUNC_DO, &PhaseNode_GetSelf::Do);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_SpawnCollider::TRIGGER_DONE, 84, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(22102, 15) {
    auto node15 = GET_SKILL_NODE(15, PhaseNode_SpawnCollider);
    if (node15 == nullptr) {
        node15 = new PhaseNode_SpawnCollider(15, phase);
        node15->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node15->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node15->setMesh("");
        node15->setMeshScale(.00f);
        node15->setEffectID(221021);
        node15->setEffectScale(2.00f);
        node15->setType(PhaseNode_SpawnCollider::SpawnCollider_Type::Circle);
        node15->setTypeParams(0, 3.00f);
        node15->setTime(.00f);
        node15->setPosZ(.00f);
        node15->setRotation(.00f);
        node15->setreentry(false);
        node15->setCheckPeneSound(false);
        CALL_REGISTER_SKILL_NODE(22102, 15, node15)
    }
    if (noInit == true) {
        return node15;
    }
    auto node99 = GET_SKILL_NODE(99, PhaseNode_OffsetCalculate);
    if (node99 != nullptr) node15->setPosX(node99->getOutPosX());
    if (node99 != nullptr) node15->setPosY(node99->getOutPosY());
    return node15;
}
//--------------------------------------------------------------------------------
// TriggerUpdate
//
REGISTER_REGISTER_SKILL_NODE(22102, 26) {
}

REGISTER_CREATE_SKILL_NODE(22102, 26) {
    auto node26 = GET_SKILL_NODE(26, PhaseNode_TriggerUpdate);
    if (node26 == nullptr) {
        node26 = new PhaseNode_TriggerUpdate(26, phase);
        CALL_REGISTER_SKILL_NODE(22102, 26, node26)
    }
    if (noInit == true) {
        return node26;
    }
    return node26;
}
//--------------------------------------------------------------------------------
// SetFloat
//
REGISTER_REGISTER_SKILL_NODE(22102, 35) {
    pnode->resizeTrigger(PhaseNode_SetFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetFloat>(PhaseNode_SetFloat::TRIGGER_DONE, 37, PhaseNode_SetFloat::FUNC_SET, &PhaseNode_SetFloat::Set);
}

REGISTER_CREATE_SKILL_NODE(22102, 35) {
    auto node35 = GET_SKILL_NODE(35, PhaseNode_SetFloat);
    if (node35 == nullptr) {
        node35 = new PhaseNode_SetFloat(35, phase);
        node35->setName("LastX");
        CALL_REGISTER_SKILL_NODE(22102, 35, node35)
    }
    if (noInit == true) {
        return node35;
    }
    auto node53 = GET_SKILL_NODE(53, PhaseNode_GetLocation);
    if (node53 != nullptr) node35->setValue(node53->getX());
    return node35;
}
//--------------------------------------------------------------------------------
// SetFloat
//
REGISTER_REGISTER_SKILL_NODE(22102, 37) {
}

REGISTER_CREATE_SKILL_NODE(22102, 37) {
    auto node37 = GET_SKILL_NODE(37, PhaseNode_SetFloat);
    if (node37 == nullptr) {
        node37 = new PhaseNode_SetFloat(37, phase);
        node37->setName("LastY");
        CALL_REGISTER_SKILL_NODE(22102, 37, node37)
    }
    if (noInit == true) {
        return node37;
    }
    auto node53 = GET_SKILL_NODE(53, PhaseNode_GetLocation);
    if (node53 != nullptr) node37->setValue(node53->getY());
    return node37;
}
//--------------------------------------------------------------------------------
// Distance
//
REGISTER_REGISTER_SKILL_NODE(22102, 39) {
    pnode->resizeTrigger(PhaseNode_Distance::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_Distance::TRIGGER_DONE, 49, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(22102, 39) {
    auto node39 = GET_SKILL_NODE(39, PhaseNode_Distance);
    if (node39 == nullptr) {
        node39 = new PhaseNode_Distance(39, phase);
        CALL_REGISTER_SKILL_NODE(22102, 39, node39)
    }
    if (noInit == true) {
        return node39;
    }
    auto variables = node39->getVariables();
    if (variables != nullptr) {
        node39->setAX(variables->getVariable<float>(Variable_22102_LastX));
        node39->setAY(variables->getVariable<float>(Variable_22102_LastY));
    }
    auto node106 = GET_SKILL_NODE(106, PhaseNode_OffsetCalculate);
    if (node106 != nullptr) node39->setBX(node106->getOutPosX());
    if (node106 != nullptr) node39->setBY(node106->getOutPosY());
    return node39;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(22102, 49) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnCollider>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 71, PhaseNode_SpawnCollider::FUNC_DO, &PhaseNode_SpawnCollider::Do);
    pnode->regTrigger<PhaseNode_SpawnCollider>(PhaseNode_CompareFloat::TRIGGER_LESS, 71, PhaseNode_SpawnCollider::FUNC_DO, &PhaseNode_SpawnCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(22102, 49) {
    auto node49 = GET_SKILL_NODE(49, PhaseNode_CompareFloat);
    if (node49 == nullptr) {
        node49 = new PhaseNode_CompareFloat(49, phase);
        node49->setA(4.00f);
        CALL_REGISTER_SKILL_NODE(22102, 49, node49)
    }
    if (noInit == true) {
        return node49;
    }
    auto node39 = GET_SKILL_NODE(39, PhaseNode_Distance);
    if (node39 != nullptr) node49->setB(node39->getResult());
    return node49;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(22102, 53) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetFloat>(PhaseNode_GetLocation::TRIGGER_DONE, 35, PhaseNode_SetFloat::FUNC_SET, &PhaseNode_SetFloat::Set);
}

REGISTER_CREATE_SKILL_NODE(22102, 53) {
    auto node53 = GET_SKILL_NODE(53, PhaseNode_GetLocation);
    if (node53 == nullptr) {
        node53 = new PhaseNode_GetLocation(53, phase);
        node53->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        CALL_REGISTER_SKILL_NODE(22102, 53, node53)
    }
    if (noInit == true) {
        return node53;
    }
    auto node71 = GET_SKILL_NODE(71, PhaseNode_SpawnCollider);
    if (node71 != nullptr) node53->setTarget(node71->getColliderID());
    return node53;
}
//--------------------------------------------------------------------------------
// SpawnCollider
//
REGISTER_REGISTER_SKILL_NODE(22102, 71) {
    pnode->resizeTrigger(PhaseNode_SpawnCollider::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_SpawnCollider::TRIGGER_DONE, 53, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_SpawnCollider::TRIGGER_DONE, 114, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(22102, 71) {
    auto node71 = GET_SKILL_NODE(71, PhaseNode_SpawnCollider);
    if (node71 == nullptr) {
        node71 = new PhaseNode_SpawnCollider(71, phase);
        node71->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node71->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node71->setMesh("");
        node71->setMeshScale(.00f);
        node71->setEffectID(221022);
        node71->setEffectScale(1.00f);
        node71->setType(PhaseNode_SpawnCollider::SpawnCollider_Type::Circle);
        node71->setTypeParams(0, .00f);
        node71->setTime(4.00f);
        node71->setPosZ(.20f);
        node71->setRotation(.00f);
        node71->setreentry(true);
        node71->setCheckPeneSound(false);
        CALL_REGISTER_SKILL_NODE(22102, 71, node71)
    }
    if (noInit == true) {
        return node71;
    }
    auto node106 = GET_SKILL_NODE(106, PhaseNode_OffsetCalculate);
    if (node106 != nullptr) node71->setPosX(node106->getOutPosX());
    if (node106 != nullptr) node71->setPosY(node106->getOutPosY());
    return node71;
}
//--------------------------------------------------------------------------------
// AttachTo
//
REGISTER_REGISTER_SKILL_NODE(22102, 74) {
    pnode->resizeTrigger(PhaseNode_AttachTo::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_AttachTo::TRIGGER_DONE, 100, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(22102, 74) {
    auto node74 = GET_SKILL_NODE(74, PhaseNode_AttachTo);
    if (node74 == nullptr) {
        node74 = new PhaseNode_AttachTo(74, phase);
        node74->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node74->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node74->setChangeRotation(false);
        node74->setreentry(false);
        CALL_REGISTER_SKILL_NODE(22102, 74, node74)
    }
    if (noInit == true) {
        return node74;
    }
    auto node76 = GET_SKILL_NODE(76, PhaseNode_GetSelf);
    auto node15 = GET_SKILL_NODE(15, PhaseNode_SpawnCollider);
    if (node76 != nullptr) node74->setParent(node76->getTarget());
    if (node15 != nullptr) node74->setChild(node15->getColliderID());
    return node74;
}
//--------------------------------------------------------------------------------
// GetSelf
//
REGISTER_REGISTER_SKILL_NODE(22102, 76) {
    pnode->resizeTrigger(PhaseNode_GetSelf::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AttachTo>(PhaseNode_GetSelf::TRIGGER_DONE, 74, PhaseNode_AttachTo::FUNC_DO, &PhaseNode_AttachTo::Do);
}

REGISTER_CREATE_SKILL_NODE(22102, 76) {
    auto node76 = GET_SKILL_NODE(76, PhaseNode_GetSelf);
    if (node76 == nullptr) {
        node76 = new PhaseNode_GetSelf(76, phase);
        CALL_REGISTER_SKILL_NODE(22102, 76, node76)
    }
    if (noInit == true) {
        return node76;
    }
    return node76;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(22102, 77) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 89, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 91, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(22102, 77) {
    auto node77 = GET_SKILL_NODE(77, PhaseNode_CreateTriggerNewPene);
    if (node77 == nullptr) {
        node77 = new PhaseNode_CreateTriggerNewPene(77, phase);
        node77->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::In);
        node77->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node77->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Enemy);
        node77->setOnHero(true);
        node77->setOnMinion(true);
        node77->setOnDestruct(false);
        node77->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(22102, 77, node77)
    }
    if (noInit == true) {
        return node77;
    }
    auto node15 = GET_SKILL_NODE(15, PhaseNode_SpawnCollider);
    if (node15 != nullptr) node77->setColliderID(node15->getColliderID());
    return node77;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(22102, 78) {
}

REGISTER_CREATE_SKILL_NODE(22102, 78) {
    auto node78 = GET_SKILL_NODE(78, PhaseNode_TriggerCheck);
    if (node78 == nullptr) {
        node78 = new PhaseNode_TriggerCheck(78, phase);
        auto node26 = GET_SKILL_NODE(26, PhaseNode_TriggerUpdate);
        if (node26 != nullptr) node26->addTriggerCheck(node78);
        
        CALL_REGISTER_SKILL_NODE(22102, 78, node78)
    }
    if (noInit == true) {
        return node78;
    }
    auto node87 = GET_SKILL_NODE(87, PhaseNode_CreateTriggerNewPene);
    if (node87 != nullptr) node78->setTrigger(0, node87->getTriggerID());
    return node78;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(22102, 79) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 80, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(22102, 79) {
    auto node79 = GET_SKILL_NODE(79, PhaseNode_ActorFilterNewPene);
    if (node79 == nullptr) {
        node79 = new PhaseNode_ActorFilterNewPene(79, phase);
        node79->setHero(true);
        node79->setMinion(true);
        node79->setDestruct(false);
        node79->setShield(false);
        node79->setTotalCount(0);
        node79->setPerCount(0);
        CALL_REGISTER_SKILL_NODE(22102, 79, node79)
    }
    if (noInit == true) {
        return node79;
    }
    auto node83 = GET_SKILL_NODE(83, PhaseNode_CreateTriggerNewPene);
    if (node83 != nullptr) node79->setInput(node83->getOther());
    return node79;
}
//--------------------------------------------------------------------------------
// GetActorAttribute
//
REGISTER_REGISTER_SKILL_NODE(22102, 80) {
    pnode->resizeTrigger(PhaseNode_GetActorAttribute::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 81, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 94, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 95, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 96, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
}

REGISTER_CREATE_SKILL_NODE(22102, 80) {
    auto node80 = GET_SKILL_NODE(80, PhaseNode_GetActorAttribute);
    if (node80 == nullptr) {
        node80 = new PhaseNode_GetActorAttribute(80, phase);
        node80->setTarget(0U);
        node80->setType({202});
        CALL_REGISTER_SKILL_NODE(22102, 80, node80)
    }
    if (noInit == true) {
        return node80;
    }
    return node80;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(22102, 81) {
}

REGISTER_CREATE_SKILL_NODE(22102, 81) {
    auto node81 = GET_SKILL_NODE(81, PhaseNode_AddSkillBuffs);
    if (node81 == nullptr) {
        node81 = new PhaseNode_AddSkillBuffs(81, phase);
        node81->setConfigID({18});
        CALL_REGISTER_SKILL_NODE(22102, 81, node81)
    }
    if (noInit == true) {
        return node81;
    }
    auto node79 = GET_SKILL_NODE(79, PhaseNode_ActorFilterNewPene);
    auto node80 = GET_SKILL_NODE(80, PhaseNode_GetActorAttribute);
    if (node79 != nullptr) node81->setTarget(node79->getOutput());
    if (node80 != nullptr) node81->setAttribute(node80->getAttribute());
    return node81;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(22102, 82) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 77, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_LESS, 83, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
}

REGISTER_CREATE_SKILL_NODE(22102, 82) {
    auto node82 = GET_SKILL_NODE(82, PhaseNode_CompareFloat);
    if (node82 == nullptr) {
        node82 = new PhaseNode_CompareFloat(82, phase);
        node82->setA(.00f);
        node82->setB(.50f);
        CALL_REGISTER_SKILL_NODE(22102, 82, node82)
    }
    if (noInit == true) {
        return node82;
    }
    return node82;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(22102, 83) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 88, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 79, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(22102, 83) {
    auto node83 = GET_SKILL_NODE(83, PhaseNode_CreateTriggerNewPene);
    if (node83 == nullptr) {
        node83 = new PhaseNode_CreateTriggerNewPene(83, phase);
        node83->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::Tick);
        node83->setTypeParams(0, .50f);
        node83->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node83->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Enemy);
        node83->setOnHero(true);
        node83->setOnMinion(true);
        node83->setOnDestruct(false);
        node83->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(22102, 83, node83)
    }
    if (noInit == true) {
        return node83;
    }
    auto node15 = GET_SKILL_NODE(15, PhaseNode_SpawnCollider);
    if (node15 != nullptr) node83->setColliderID(node15->getColliderID());
    return node83;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(22102, 84) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_If::TRIGGER_FALSE, 85, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_If::TRIGGER_TRUE, 82, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(22102, 84) {
    auto node84 = GET_SKILL_NODE(84, PhaseNode_If);
    if (node84 == nullptr) {
        node84 = new PhaseNode_If(84, phase);
        node84->setCondition(true);
        CALL_REGISTER_SKILL_NODE(22102, 84, node84)
    }
    if (noInit == true) {
        return node84;
    }
    return node84;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(22102, 85) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 87, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_LESS, 86, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
}

REGISTER_CREATE_SKILL_NODE(22102, 85) {
    auto node85 = GET_SKILL_NODE(85, PhaseNode_CompareFloat);
    if (node85 == nullptr) {
        node85 = new PhaseNode_CompareFloat(85, phase);
        node85->setA(.00f);
        node85->setB(.50f);
        CALL_REGISTER_SKILL_NODE(22102, 85, node85)
    }
    if (noInit == true) {
        return node85;
    }
    return node85;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(22102, 86) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 90, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 92, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(22102, 86) {
    auto node86 = GET_SKILL_NODE(86, PhaseNode_CreateTriggerNewPene);
    if (node86 == nullptr) {
        node86 = new PhaseNode_CreateTriggerNewPene(86, phase);
        node86->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::Tick);
        node86->setTypeParams(0, .50f);
        node86->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node86->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Friend);
        node86->setOnHero(true);
        node86->setOnMinion(true);
        node86->setOnDestruct(false);
        node86->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(22102, 86, node86)
    }
    if (noInit == true) {
        return node86;
    }
    auto node15 = GET_SKILL_NODE(15, PhaseNode_SpawnCollider);
    if (node15 != nullptr) node86->setColliderID(node15->getColliderID());
    return node86;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(22102, 87) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 78, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 93, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(22102, 87) {
    auto node87 = GET_SKILL_NODE(87, PhaseNode_CreateTriggerNewPene);
    if (node87 == nullptr) {
        node87 = new PhaseNode_CreateTriggerNewPene(87, phase);
        node87->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::In);
        node87->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node87->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Friend);
        node87->setOnHero(true);
        node87->setOnMinion(true);
        node87->setOnDestruct(false);
        node87->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(22102, 87, node87)
    }
    if (noInit == true) {
        return node87;
    }
    auto node15 = GET_SKILL_NODE(15, PhaseNode_SpawnCollider);
    if (node15 != nullptr) node87->setColliderID(node15->getColliderID());
    return node87;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(22102, 88) {
}

REGISTER_CREATE_SKILL_NODE(22102, 88) {
    auto node88 = GET_SKILL_NODE(88, PhaseNode_TriggerCheck);
    if (node88 == nullptr) {
        node88 = new PhaseNode_TriggerCheck(88, phase);
        auto node26 = GET_SKILL_NODE(26, PhaseNode_TriggerUpdate);
        if (node26 != nullptr) node26->addTriggerCheck(node88);
        
        CALL_REGISTER_SKILL_NODE(22102, 88, node88)
    }
    if (noInit == true) {
        return node88;
    }
    auto node83 = GET_SKILL_NODE(83, PhaseNode_CreateTriggerNewPene);
    if (node83 != nullptr) node88->setTrigger(0, node83->getTriggerID());
    return node88;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(22102, 89) {
}

REGISTER_CREATE_SKILL_NODE(22102, 89) {
    auto node89 = GET_SKILL_NODE(89, PhaseNode_TriggerCheck);
    if (node89 == nullptr) {
        node89 = new PhaseNode_TriggerCheck(89, phase);
        auto node26 = GET_SKILL_NODE(26, PhaseNode_TriggerUpdate);
        if (node26 != nullptr) node26->addTriggerCheck(node89);
        
        CALL_REGISTER_SKILL_NODE(22102, 89, node89)
    }
    if (noInit == true) {
        return node89;
    }
    auto node77 = GET_SKILL_NODE(77, PhaseNode_CreateTriggerNewPene);
    if (node77 != nullptr) node89->setTrigger(0, node77->getTriggerID());
    return node89;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(22102, 90) {
}

REGISTER_CREATE_SKILL_NODE(22102, 90) {
    auto node90 = GET_SKILL_NODE(90, PhaseNode_TriggerCheck);
    if (node90 == nullptr) {
        node90 = new PhaseNode_TriggerCheck(90, phase);
        auto node26 = GET_SKILL_NODE(26, PhaseNode_TriggerUpdate);
        if (node26 != nullptr) node26->addTriggerCheck(node90);
        
        CALL_REGISTER_SKILL_NODE(22102, 90, node90)
    }
    if (noInit == true) {
        return node90;
    }
    auto node86 = GET_SKILL_NODE(86, PhaseNode_CreateTriggerNewPene);
    if (node86 != nullptr) node90->setTrigger(0, node86->getTriggerID());
    return node90;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(22102, 91) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 80, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(22102, 91) {
    auto node91 = GET_SKILL_NODE(91, PhaseNode_ActorFilterNewPene);
    if (node91 == nullptr) {
        node91 = new PhaseNode_ActorFilterNewPene(91, phase);
        node91->setHero(true);
        node91->setMinion(true);
        node91->setDestruct(false);
        node91->setShield(false);
        node91->setTotalCount(0);
        node91->setPerCount(0);
        CALL_REGISTER_SKILL_NODE(22102, 91, node91)
    }
    if (noInit == true) {
        return node91;
    }
    auto node77 = GET_SKILL_NODE(77, PhaseNode_CreateTriggerNewPene);
    if (node77 != nullptr) node91->setInput(node77->getOther());
    return node91;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(22102, 92) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 80, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(22102, 92) {
    auto node92 = GET_SKILL_NODE(92, PhaseNode_ActorFilterNewPene);
    if (node92 == nullptr) {
        node92 = new PhaseNode_ActorFilterNewPene(92, phase);
        node92->setHero(true);
        node92->setMinion(true);
        node92->setDestruct(false);
        node92->setShield(false);
        node92->setTotalCount(0);
        node92->setPerCount(0);
        CALL_REGISTER_SKILL_NODE(22102, 92, node92)
    }
    if (noInit == true) {
        return node92;
    }
    auto node86 = GET_SKILL_NODE(86, PhaseNode_CreateTriggerNewPene);
    if (node86 != nullptr) node92->setInput(node86->getOther());
    return node92;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(22102, 93) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 80, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(22102, 93) {
    auto node93 = GET_SKILL_NODE(93, PhaseNode_ActorFilterNewPene);
    if (node93 == nullptr) {
        node93 = new PhaseNode_ActorFilterNewPene(93, phase);
        node93->setHero(true);
        node93->setMinion(true);
        node93->setDestruct(false);
        node93->setShield(false);
        node93->setTotalCount(0);
        node93->setPerCount(0);
        CALL_REGISTER_SKILL_NODE(22102, 93, node93)
    }
    if (noInit == true) {
        return node93;
    }
    auto node87 = GET_SKILL_NODE(87, PhaseNode_CreateTriggerNewPene);
    if (node87 != nullptr) node93->setInput(node87->getOther());
    return node93;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(22102, 94) {
}

REGISTER_CREATE_SKILL_NODE(22102, 94) {
    auto node94 = GET_SKILL_NODE(94, PhaseNode_AddSkillBuffs);
    if (node94 == nullptr) {
        node94 = new PhaseNode_AddSkillBuffs(94, phase);
        node94->setConfigID({18});
        CALL_REGISTER_SKILL_NODE(22102, 94, node94)
    }
    if (noInit == true) {
        return node94;
    }
    auto node91 = GET_SKILL_NODE(91, PhaseNode_ActorFilterNewPene);
    auto node80 = GET_SKILL_NODE(80, PhaseNode_GetActorAttribute);
    if (node91 != nullptr) node94->setTarget(node91->getOutput());
    if (node80 != nullptr) node94->setAttribute(node80->getAttribute());
    return node94;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(22102, 95) {
}

REGISTER_CREATE_SKILL_NODE(22102, 95) {
    auto node95 = GET_SKILL_NODE(95, PhaseNode_AddSkillBuffs);
    if (node95 == nullptr) {
        node95 = new PhaseNode_AddSkillBuffs(95, phase);
        node95->setConfigID({18});
        CALL_REGISTER_SKILL_NODE(22102, 95, node95)
    }
    if (noInit == true) {
        return node95;
    }
    auto node92 = GET_SKILL_NODE(92, PhaseNode_ActorFilterNewPene);
    auto node80 = GET_SKILL_NODE(80, PhaseNode_GetActorAttribute);
    if (node92 != nullptr) node95->setTarget(node92->getOutput());
    if (node80 != nullptr) node95->setAttribute(node80->getAttribute());
    return node95;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(22102, 96) {
}

REGISTER_CREATE_SKILL_NODE(22102, 96) {
    auto node96 = GET_SKILL_NODE(96, PhaseNode_AddSkillBuffs);
    if (node96 == nullptr) {
        node96 = new PhaseNode_AddSkillBuffs(96, phase);
        node96->setConfigID({18});
        CALL_REGISTER_SKILL_NODE(22102, 96, node96)
    }
    if (noInit == true) {
        return node96;
    }
    auto node93 = GET_SKILL_NODE(93, PhaseNode_ActorFilterNewPene);
    auto node80 = GET_SKILL_NODE(80, PhaseNode_GetActorAttribute);
    if (node93 != nullptr) node96->setTarget(node93->getOutput());
    if (node80 != nullptr) node96->setAttribute(node80->getAttribute());
    return node96;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(22102, 97) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetRotation>(PhaseNode_GetLocation::TRIGGER_DONE, 98, PhaseNode_GetRotation::FUNC_DO, &PhaseNode_GetRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(22102, 97) {
    auto node97 = GET_SKILL_NODE(97, PhaseNode_GetLocation);
    if (node97 == nullptr) {
        node97 = new PhaseNode_GetLocation(97, phase);
        node97->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node97->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(22102, 97, node97)
    }
    if (noInit == true) {
        return node97;
    }
    return node97;
}
//--------------------------------------------------------------------------------
// GetRotation
//
REGISTER_REGISTER_SKILL_NODE(22102, 98) {
    pnode->resizeTrigger(PhaseNode_GetRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_OffsetCalculate>(PhaseNode_GetRotation::TRIGGER_DONE, 99, PhaseNode_OffsetCalculate::FUNC_DO, &PhaseNode_OffsetCalculate::Do);
}

REGISTER_CREATE_SKILL_NODE(22102, 98) {
    auto node98 = GET_SKILL_NODE(98, PhaseNode_GetRotation);
    if (node98 == nullptr) {
        node98 = new PhaseNode_GetRotation(98, phase);
        node98->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node98->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(22102, 98, node98)
    }
    if (noInit == true) {
        return node98;
    }
    return node98;
}
//--------------------------------------------------------------------------------
// OffsetCalculate
//
REGISTER_REGISTER_SKILL_NODE(22102, 99) {
    pnode->resizeTrigger(PhaseNode_OffsetCalculate::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnCollider>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 15, PhaseNode_SpawnCollider::FUNC_DO, &PhaseNode_SpawnCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(22102, 99) {
    auto node99 = GET_SKILL_NODE(99, PhaseNode_OffsetCalculate);
    if (node99 == nullptr) {
        node99 = new PhaseNode_OffsetCalculate(99, phase);
        node99->setPosZ(.00f);
        node99->setOffsetX(.00f);
        node99->setOffsetY(.00f);
        node99->setOffsetZ(.00f);
        node99->setRotOffset(.00f);
        CALL_REGISTER_SKILL_NODE(22102, 99, node99)
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
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22102, 100) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_Delay::TRIGGER_DONE, 102, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(22102, 100) {
    auto node100 = GET_SKILL_NODE(100, PhaseNode_Delay);
    if (node100 == nullptr) {
        node100 = new PhaseNode_Delay(100, phase);
        node100->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(22102, 100, node100)
    }
    if (noInit == true) {
        return node100;
    }
    return node100;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(22102, 101) {
}

REGISTER_CREATE_SKILL_NODE(22102, 101) {
    auto node101 = GET_SKILL_NODE(101, PhaseNode_SkillEndNotify);
    if (node101 == nullptr) {
        node101 = new PhaseNode_SkillEndNotify(101, phase);
        node101->setReturnType(false);
        CALL_REGISTER_SKILL_NODE(22102, 101, node101)
    }
    if (noInit == true) {
        return node101;
    }
    return node101;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(22102, 102) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_FALSE, 103, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_TRUE, 101, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
}

REGISTER_CREATE_SKILL_NODE(22102, 102) {
    auto node102 = GET_SKILL_NODE(102, PhaseNode_If);
    if (node102 == nullptr) {
        node102 = new PhaseNode_If(102, phase);
        node102->setCondition(false);
        CALL_REGISTER_SKILL_NODE(22102, 102, node102)
    }
    if (noInit == true) {
        return node102;
    }
    return node102;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(22102, 103) {
}

REGISTER_CREATE_SKILL_NODE(22102, 103) {
    auto node103 = GET_SKILL_NODE(103, PhaseNode_SkillEndNotify);
    if (node103 == nullptr) {
        node103 = new PhaseNode_SkillEndNotify(103, phase);
        node103->setReturnType(true);
        CALL_REGISTER_SKILL_NODE(22102, 103, node103)
    }
    if (noInit == true) {
        return node103;
    }
    return node103;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(22102, 104) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetRotation>(PhaseNode_GetLocation::TRIGGER_DONE, 105, PhaseNode_GetRotation::FUNC_DO, &PhaseNode_GetRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(22102, 104) {
    auto node104 = GET_SKILL_NODE(104, PhaseNode_GetLocation);
    if (node104 == nullptr) {
        node104 = new PhaseNode_GetLocation(104, phase);
        node104->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node104->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(22102, 104, node104)
    }
    if (noInit == true) {
        return node104;
    }
    return node104;
}
//--------------------------------------------------------------------------------
// GetRotation
//
REGISTER_REGISTER_SKILL_NODE(22102, 105) {
    pnode->resizeTrigger(PhaseNode_GetRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_OffsetCalculate>(PhaseNode_GetRotation::TRIGGER_DONE, 106, PhaseNode_OffsetCalculate::FUNC_DO, &PhaseNode_OffsetCalculate::Do);
}

REGISTER_CREATE_SKILL_NODE(22102, 105) {
    auto node105 = GET_SKILL_NODE(105, PhaseNode_GetRotation);
    if (node105 == nullptr) {
        node105 = new PhaseNode_GetRotation(105, phase);
        node105->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node105->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(22102, 105, node105)
    }
    if (noInit == true) {
        return node105;
    }
    return node105;
}
//--------------------------------------------------------------------------------
// OffsetCalculate
//
REGISTER_REGISTER_SKILL_NODE(22102, 106) {
    pnode->resizeTrigger(PhaseNode_OffsetCalculate::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Distance>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 39, PhaseNode_Distance::FUNC_DO, &PhaseNode_Distance::Do);
}

REGISTER_CREATE_SKILL_NODE(22102, 106) {
    auto node106 = GET_SKILL_NODE(106, PhaseNode_OffsetCalculate);
    if (node106 == nullptr) {
        node106 = new PhaseNode_OffsetCalculate(106, phase);
        node106->setPosZ(.00f);
        node106->setOffsetX(.00f);
        node106->setOffsetY(.00f);
        node106->setOffsetZ(.00f);
        node106->setRotOffset(.00f);
        CALL_REGISTER_SKILL_NODE(22102, 106, node106)
    }
    if (noInit == true) {
        return node106;
    }
    auto node104 = GET_SKILL_NODE(104, PhaseNode_GetLocation);
    auto node105 = GET_SKILL_NODE(105, PhaseNode_GetRotation);
    if (node104 != nullptr) node106->setPosX(node104->getX());
    if (node104 != nullptr) node106->setPosY(node104->getY());
    if (node105 != nullptr) node106->setRotation(node105->getAngle());
    return node106;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(22102, 107) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 119, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 121, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(22102, 107) {
    auto node107 = GET_SKILL_NODE(107, PhaseNode_CreateTriggerNewPene);
    if (node107 == nullptr) {
        node107 = new PhaseNode_CreateTriggerNewPene(107, phase);
        node107->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::In);
        node107->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node107->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Enemy);
        node107->setOnHero(true);
        node107->setOnMinion(true);
        node107->setOnDestruct(false);
        node107->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(22102, 107, node107)
    }
    if (noInit == true) {
        return node107;
    }
    auto node71 = GET_SKILL_NODE(71, PhaseNode_SpawnCollider);
    if (node71 != nullptr) node107->setColliderID(node71->getColliderID());
    return node107;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(22102, 108) {
}

REGISTER_CREATE_SKILL_NODE(22102, 108) {
    auto node108 = GET_SKILL_NODE(108, PhaseNode_TriggerCheck);
    if (node108 == nullptr) {
        node108 = new PhaseNode_TriggerCheck(108, phase);
        auto node26 = GET_SKILL_NODE(26, PhaseNode_TriggerUpdate);
        if (node26 != nullptr) node26->addTriggerCheck(node108);
        
        CALL_REGISTER_SKILL_NODE(22102, 108, node108)
    }
    if (noInit == true) {
        return node108;
    }
    auto node117 = GET_SKILL_NODE(117, PhaseNode_CreateTriggerNewPene);
    if (node117 != nullptr) node108->setTrigger(0, node117->getTriggerID());
    return node108;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(22102, 109) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 110, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(22102, 109) {
    auto node109 = GET_SKILL_NODE(109, PhaseNode_ActorFilterNewPene);
    if (node109 == nullptr) {
        node109 = new PhaseNode_ActorFilterNewPene(109, phase);
        node109->setHero(true);
        node109->setMinion(true);
        node109->setDestruct(false);
        node109->setShield(false);
        node109->setTotalCount(0);
        node109->setPerCount(0);
        CALL_REGISTER_SKILL_NODE(22102, 109, node109)
    }
    if (noInit == true) {
        return node109;
    }
    auto node113 = GET_SKILL_NODE(113, PhaseNode_CreateTriggerNewPene);
    if (node113 != nullptr) node109->setInput(node113->getOther());
    return node109;
}
//--------------------------------------------------------------------------------
// GetActorAttribute
//
REGISTER_REGISTER_SKILL_NODE(22102, 110) {
    pnode->resizeTrigger(PhaseNode_GetActorAttribute::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 111, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 124, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 125, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 126, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
}

REGISTER_CREATE_SKILL_NODE(22102, 110) {
    auto node110 = GET_SKILL_NODE(110, PhaseNode_GetActorAttribute);
    if (node110 == nullptr) {
        node110 = new PhaseNode_GetActorAttribute(110, phase);
        node110->setTarget(0U);
        node110->setType({202});
        CALL_REGISTER_SKILL_NODE(22102, 110, node110)
    }
    if (noInit == true) {
        return node110;
    }
    return node110;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(22102, 111) {
}

REGISTER_CREATE_SKILL_NODE(22102, 111) {
    auto node111 = GET_SKILL_NODE(111, PhaseNode_AddSkillBuffs);
    if (node111 == nullptr) {
        node111 = new PhaseNode_AddSkillBuffs(111, phase);
        node111->setConfigID({17});
        CALL_REGISTER_SKILL_NODE(22102, 111, node111)
    }
    if (noInit == true) {
        return node111;
    }
    auto node109 = GET_SKILL_NODE(109, PhaseNode_ActorFilterNewPene);
    auto node110 = GET_SKILL_NODE(110, PhaseNode_GetActorAttribute);
    if (node109 != nullptr) node111->setTarget(node109->getOutput());
    if (node110 != nullptr) node111->setAttribute(node110->getAttribute());
    return node111;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(22102, 112) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 107, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_LESS, 113, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
}

REGISTER_CREATE_SKILL_NODE(22102, 112) {
    auto node112 = GET_SKILL_NODE(112, PhaseNode_CompareFloat);
    if (node112 == nullptr) {
        node112 = new PhaseNode_CompareFloat(112, phase);
        node112->setA(.00f);
        node112->setB(.50f);
        CALL_REGISTER_SKILL_NODE(22102, 112, node112)
    }
    if (noInit == true) {
        return node112;
    }
    return node112;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(22102, 113) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 118, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 109, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(22102, 113) {
    auto node113 = GET_SKILL_NODE(113, PhaseNode_CreateTriggerNewPene);
    if (node113 == nullptr) {
        node113 = new PhaseNode_CreateTriggerNewPene(113, phase);
        node113->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::Tick);
        node113->setTypeParams(0, .50f);
        node113->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node113->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Enemy);
        node113->setOnHero(true);
        node113->setOnMinion(true);
        node113->setOnDestruct(false);
        node113->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(22102, 113, node113)
    }
    if (noInit == true) {
        return node113;
    }
    auto node71 = GET_SKILL_NODE(71, PhaseNode_SpawnCollider);
    if (node71 != nullptr) node113->setColliderID(node71->getColliderID());
    return node113;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(22102, 114) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_If::TRIGGER_FALSE, 115, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_If::TRIGGER_TRUE, 112, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(22102, 114) {
    auto node114 = GET_SKILL_NODE(114, PhaseNode_If);
    if (node114 == nullptr) {
        node114 = new PhaseNode_If(114, phase);
        node114->setCondition(true);
        CALL_REGISTER_SKILL_NODE(22102, 114, node114)
    }
    if (noInit == true) {
        return node114;
    }
    return node114;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(22102, 115) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 117, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_LESS, 116, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
}

REGISTER_CREATE_SKILL_NODE(22102, 115) {
    auto node115 = GET_SKILL_NODE(115, PhaseNode_CompareFloat);
    if (node115 == nullptr) {
        node115 = new PhaseNode_CompareFloat(115, phase);
        node115->setA(.00f);
        node115->setB(.50f);
        CALL_REGISTER_SKILL_NODE(22102, 115, node115)
    }
    if (noInit == true) {
        return node115;
    }
    return node115;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(22102, 116) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 120, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 122, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(22102, 116) {
    auto node116 = GET_SKILL_NODE(116, PhaseNode_CreateTriggerNewPene);
    if (node116 == nullptr) {
        node116 = new PhaseNode_CreateTriggerNewPene(116, phase);
        node116->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::Tick);
        node116->setTypeParams(0, .50f);
        node116->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node116->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Friend);
        node116->setOnHero(true);
        node116->setOnMinion(true);
        node116->setOnDestruct(false);
        node116->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(22102, 116, node116)
    }
    if (noInit == true) {
        return node116;
    }
    auto node71 = GET_SKILL_NODE(71, PhaseNode_SpawnCollider);
    if (node71 != nullptr) node116->setColliderID(node71->getColliderID());
    return node116;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(22102, 117) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 108, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 123, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(22102, 117) {
    auto node117 = GET_SKILL_NODE(117, PhaseNode_CreateTriggerNewPene);
    if (node117 == nullptr) {
        node117 = new PhaseNode_CreateTriggerNewPene(117, phase);
        node117->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::In);
        node117->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node117->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Friend);
        node117->setOnHero(true);
        node117->setOnMinion(true);
        node117->setOnDestruct(false);
        node117->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(22102, 117, node117)
    }
    if (noInit == true) {
        return node117;
    }
    auto node71 = GET_SKILL_NODE(71, PhaseNode_SpawnCollider);
    if (node71 != nullptr) node117->setColliderID(node71->getColliderID());
    return node117;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(22102, 118) {
}

REGISTER_CREATE_SKILL_NODE(22102, 118) {
    auto node118 = GET_SKILL_NODE(118, PhaseNode_TriggerCheck);
    if (node118 == nullptr) {
        node118 = new PhaseNode_TriggerCheck(118, phase);
        auto node26 = GET_SKILL_NODE(26, PhaseNode_TriggerUpdate);
        if (node26 != nullptr) node26->addTriggerCheck(node118);
        
        CALL_REGISTER_SKILL_NODE(22102, 118, node118)
    }
    if (noInit == true) {
        return node118;
    }
    auto node113 = GET_SKILL_NODE(113, PhaseNode_CreateTriggerNewPene);
    if (node113 != nullptr) node118->setTrigger(0, node113->getTriggerID());
    return node118;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(22102, 119) {
}

REGISTER_CREATE_SKILL_NODE(22102, 119) {
    auto node119 = GET_SKILL_NODE(119, PhaseNode_TriggerCheck);
    if (node119 == nullptr) {
        node119 = new PhaseNode_TriggerCheck(119, phase);
        auto node26 = GET_SKILL_NODE(26, PhaseNode_TriggerUpdate);
        if (node26 != nullptr) node26->addTriggerCheck(node119);
        
        CALL_REGISTER_SKILL_NODE(22102, 119, node119)
    }
    if (noInit == true) {
        return node119;
    }
    auto node107 = GET_SKILL_NODE(107, PhaseNode_CreateTriggerNewPene);
    if (node107 != nullptr) node119->setTrigger(0, node107->getTriggerID());
    return node119;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(22102, 120) {
}

REGISTER_CREATE_SKILL_NODE(22102, 120) {
    auto node120 = GET_SKILL_NODE(120, PhaseNode_TriggerCheck);
    if (node120 == nullptr) {
        node120 = new PhaseNode_TriggerCheck(120, phase);
        auto node26 = GET_SKILL_NODE(26, PhaseNode_TriggerUpdate);
        if (node26 != nullptr) node26->addTriggerCheck(node120);
        
        CALL_REGISTER_SKILL_NODE(22102, 120, node120)
    }
    if (noInit == true) {
        return node120;
    }
    auto node116 = GET_SKILL_NODE(116, PhaseNode_CreateTriggerNewPene);
    if (node116 != nullptr) node120->setTrigger(0, node116->getTriggerID());
    return node120;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(22102, 121) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 110, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(22102, 121) {
    auto node121 = GET_SKILL_NODE(121, PhaseNode_ActorFilterNewPene);
    if (node121 == nullptr) {
        node121 = new PhaseNode_ActorFilterNewPene(121, phase);
        node121->setHero(true);
        node121->setMinion(true);
        node121->setDestruct(false);
        node121->setShield(false);
        node121->setTotalCount(0);
        node121->setPerCount(0);
        CALL_REGISTER_SKILL_NODE(22102, 121, node121)
    }
    if (noInit == true) {
        return node121;
    }
    auto node107 = GET_SKILL_NODE(107, PhaseNode_CreateTriggerNewPene);
    if (node107 != nullptr) node121->setInput(node107->getOther());
    return node121;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(22102, 122) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 110, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(22102, 122) {
    auto node122 = GET_SKILL_NODE(122, PhaseNode_ActorFilterNewPene);
    if (node122 == nullptr) {
        node122 = new PhaseNode_ActorFilterNewPene(122, phase);
        node122->setHero(true);
        node122->setMinion(true);
        node122->setDestruct(false);
        node122->setShield(false);
        node122->setTotalCount(0);
        node122->setPerCount(0);
        CALL_REGISTER_SKILL_NODE(22102, 122, node122)
    }
    if (noInit == true) {
        return node122;
    }
    auto node116 = GET_SKILL_NODE(116, PhaseNode_CreateTriggerNewPene);
    if (node116 != nullptr) node122->setInput(node116->getOther());
    return node122;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(22102, 123) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 110, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(22102, 123) {
    auto node123 = GET_SKILL_NODE(123, PhaseNode_ActorFilterNewPene);
    if (node123 == nullptr) {
        node123 = new PhaseNode_ActorFilterNewPene(123, phase);
        node123->setHero(true);
        node123->setMinion(true);
        node123->setDestruct(false);
        node123->setShield(false);
        node123->setTotalCount(0);
        node123->setPerCount(0);
        CALL_REGISTER_SKILL_NODE(22102, 123, node123)
    }
    if (noInit == true) {
        return node123;
    }
    auto node117 = GET_SKILL_NODE(117, PhaseNode_CreateTriggerNewPene);
    if (node117 != nullptr) node123->setInput(node117->getOther());
    return node123;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(22102, 124) {
}

REGISTER_CREATE_SKILL_NODE(22102, 124) {
    auto node124 = GET_SKILL_NODE(124, PhaseNode_AddSkillBuffs);
    if (node124 == nullptr) {
        node124 = new PhaseNode_AddSkillBuffs(124, phase);
        node124->setConfigID({17});
        CALL_REGISTER_SKILL_NODE(22102, 124, node124)
    }
    if (noInit == true) {
        return node124;
    }
    auto node121 = GET_SKILL_NODE(121, PhaseNode_ActorFilterNewPene);
    auto node110 = GET_SKILL_NODE(110, PhaseNode_GetActorAttribute);
    if (node121 != nullptr) node124->setTarget(node121->getOutput());
    if (node110 != nullptr) node124->setAttribute(node110->getAttribute());
    return node124;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(22102, 125) {
}

REGISTER_CREATE_SKILL_NODE(22102, 125) {
    auto node125 = GET_SKILL_NODE(125, PhaseNode_AddSkillBuffs);
    if (node125 == nullptr) {
        node125 = new PhaseNode_AddSkillBuffs(125, phase);
        node125->setConfigID({17});
        CALL_REGISTER_SKILL_NODE(22102, 125, node125)
    }
    if (noInit == true) {
        return node125;
    }
    auto node122 = GET_SKILL_NODE(122, PhaseNode_ActorFilterNewPene);
    auto node110 = GET_SKILL_NODE(110, PhaseNode_GetActorAttribute);
    if (node122 != nullptr) node125->setTarget(node122->getOutput());
    if (node110 != nullptr) node125->setAttribute(node110->getAttribute());
    return node125;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(22102, 126) {
}

REGISTER_CREATE_SKILL_NODE(22102, 126) {
    auto node126 = GET_SKILL_NODE(126, PhaseNode_AddSkillBuffs);
    if (node126 == nullptr) {
        node126 = new PhaseNode_AddSkillBuffs(126, phase);
        node126->setConfigID({17});
        CALL_REGISTER_SKILL_NODE(22102, 126, node126)
    }
    if (noInit == true) {
        return node126;
    }
    auto node123 = GET_SKILL_NODE(123, PhaseNode_ActorFilterNewPene);
    auto node110 = GET_SKILL_NODE(110, PhaseNode_GetActorAttribute);
    if (node123 != nullptr) node126->setTarget(node123->getOutput());
    if (node110 != nullptr) node126->setAttribute(node110->getAttribute());
    return node126;
}

//--------------------------------------------------------------------------------
// SkillCreator_22102
//
class SkillCreator_22102 : public SkillCreator {
public:
    SkillCreator_22102() {}
    virtual ~SkillCreator_22102() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_22102

//--------------------------------------------------------------------------------
// SkillPhase_22102
//
class SkillPhase_22102 : public SkillPhase {
public:
    SkillPhase_22102(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_22102() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(22102, 3) // StartPhase
        CASE_CREATE_SKILL_NODE(22102, 5) // Detect
        CASE_CREATE_SKILL_NODE(22102, 15) // SpawnCollider
        CASE_CREATE_SKILL_NODE(22102, 26) // TriggerUpdate
        CASE_CREATE_SKILL_NODE(22102, 35) // SetFloat
        CASE_CREATE_SKILL_NODE(22102, 37) // SetFloat
        CASE_CREATE_SKILL_NODE(22102, 39) // Distance
        CASE_CREATE_SKILL_NODE(22102, 49) // CompareFloat
        CASE_CREATE_SKILL_NODE(22102, 53) // GetLocation
        CASE_CREATE_SKILL_NODE(22102, 71) // SpawnCollider
        CASE_CREATE_SKILL_NODE(22102, 74) // AttachTo
        CASE_CREATE_SKILL_NODE(22102, 76) // GetSelf
        CASE_CREATE_SKILL_NODE(22102, 77) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(22102, 78) // TriggerCheck
        CASE_CREATE_SKILL_NODE(22102, 79) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(22102, 80) // GetActorAttribute
        CASE_CREATE_SKILL_NODE(22102, 81) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(22102, 82) // CompareFloat
        CASE_CREATE_SKILL_NODE(22102, 83) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(22102, 84) // If
        CASE_CREATE_SKILL_NODE(22102, 85) // CompareFloat
        CASE_CREATE_SKILL_NODE(22102, 86) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(22102, 87) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(22102, 88) // TriggerCheck
        CASE_CREATE_SKILL_NODE(22102, 89) // TriggerCheck
        CASE_CREATE_SKILL_NODE(22102, 90) // TriggerCheck
        CASE_CREATE_SKILL_NODE(22102, 91) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(22102, 92) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(22102, 93) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(22102, 94) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(22102, 95) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(22102, 96) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(22102, 97) // GetLocation
        CASE_CREATE_SKILL_NODE(22102, 98) // GetRotation
        CASE_CREATE_SKILL_NODE(22102, 99) // OffsetCalculate
        CASE_CREATE_SKILL_NODE(22102, 100) // Delay
        CASE_CREATE_SKILL_NODE(22102, 101) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(22102, 102) // If
        CASE_CREATE_SKILL_NODE(22102, 103) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(22102, 104) // GetLocation
        CASE_CREATE_SKILL_NODE(22102, 105) // GetRotation
        CASE_CREATE_SKILL_NODE(22102, 106) // OffsetCalculate
        CASE_CREATE_SKILL_NODE(22102, 107) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(22102, 108) // TriggerCheck
        CASE_CREATE_SKILL_NODE(22102, 109) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(22102, 110) // GetActorAttribute
        CASE_CREATE_SKILL_NODE(22102, 111) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(22102, 112) // CompareFloat
        CASE_CREATE_SKILL_NODE(22102, 113) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(22102, 114) // If
        CASE_CREATE_SKILL_NODE(22102, 115) // CompareFloat
        CASE_CREATE_SKILL_NODE(22102, 116) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(22102, 117) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(22102, 118) // TriggerCheck
        CASE_CREATE_SKILL_NODE(22102, 119) // TriggerCheck
        CASE_CREATE_SKILL_NODE(22102, 120) // TriggerCheck
        CASE_CREATE_SKILL_NODE(22102, 121) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(22102, 122) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(22102, 123) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(22102, 124) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(22102, 125) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(22102, 126) // AddSkillBuffs
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_22102

SkillLogic* SkillCreator_22102::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //设置变量
    Variable_22102_Fire = logic->getVariables().setVariable<uint64_t>("Fire", 0U);
    Variable_22102_LastX = logic->getVariables().setVariable<float>("LastX");
    Variable_22102_LastY = logic->getVariables().setVariable<float>("LastY");
    //创建阶段phase
    auto phase = new SkillPhase_22102(1, logic, 3);
    //设置phase执行器
    phase->setRunPhaseNode(1, 3);
    phase->setDetectPhaseNode(2, 5);
    phase->setRunPhaseNode(3, 26);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_22102::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
