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
#include "skill_psnode_movenewpene.h"
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
REGISTER_REGISTER_SKILL_NODE(21051, 1) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_StartPhase::TRIGGER_START, 140, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_StartPhase::TRIGGER_START, 117, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(21051, 1) {
    auto node1 = GET_SKILL_NODE(1, PhaseNode_StartPhase);
    if (node1 == nullptr) {
        node1 = new PhaseNode_StartPhase(1, phase);
        CALL_REGISTER_SKILL_NODE(21051, 1, node1)
    }
    if (noInit == true) {
        return node1;
    }
    return node1;
}
//--------------------------------------------------------------------------------
// TriggerUpdate
//
REGISTER_REGISTER_SKILL_NODE(21051, 2) {
}

REGISTER_CREATE_SKILL_NODE(21051, 2) {
    auto node2 = GET_SKILL_NODE(2, PhaseNode_TriggerUpdate);
    if (node2 == nullptr) {
        node2 = new PhaseNode_TriggerUpdate(2, phase);
        CALL_REGISTER_SKILL_NODE(21051, 2, node2)
    }
    if (noInit == true) {
        return node2;
    }
    return node2;
}
//--------------------------------------------------------------------------------
// SpawnCollider
//
REGISTER_REGISTER_SKILL_NODE(21051, 9) {
    pnode->resizeTrigger(PhaseNode_SpawnCollider::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_SpawnCollider::TRIGGER_DONE, 104, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_MoveNewPene>(PhaseNode_SpawnCollider::TRIGGER_DONE, 88, PhaseNode_MoveNewPene::FUNC_DO, &PhaseNode_MoveNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(21051, 9) {
    auto node9 = GET_SKILL_NODE(9, PhaseNode_SpawnCollider);
    if (node9 == nullptr) {
        node9 = new PhaseNode_SpawnCollider(9, phase);
        node9->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node9->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node9->setMesh("");
        node9->setMeshScale(.00f);
        node9->setEffectID(0);
        node9->setEffectScale(.00f);
        node9->setType(PhaseNode_SpawnCollider::SpawnCollider_Type::Circle);
        node9->setTypeParams(0, .50f);
        node9->setTime(.00f);
        node9->setreentry(false);
        node9->setCheckPeneSound(false);
        CALL_REGISTER_SKILL_NODE(21051, 9, node9)
    }
    if (noInit == true) {
        return node9;
    }
    auto node123 = GET_SKILL_NODE(123, PhaseNode_OffsetCalculate);
    if (node123 != nullptr) node9->setPosX(node123->getOutPosX());
    if (node123 != nullptr) node9->setPosY(node123->getOutPosY());
    if (node123 != nullptr) node9->setPosZ(node123->getOutPosZ());
    if (node123 != nullptr) node9->setRotation(node123->getOutRotation());
    return node9;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(21051, 13) {
}

REGISTER_CREATE_SKILL_NODE(21051, 13) {
    auto node13 = GET_SKILL_NODE(13, PhaseNode_EndPhase);
    if (node13 == nullptr) {
        node13 = new PhaseNode_EndPhase(13, phase);
        node13->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node13->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(21051, 13, node13)
    }
    if (noInit == true) {
        return node13;
    }
    return node13;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(21051, 54) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_Detect::TRIGGER_ON, 56, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(21051, 54) {
    auto node54 = GET_SKILL_NODE(54, PhaseNode_Detect);
    if (node54 == nullptr) {
        node54 = new PhaseNode_Detect(54, phase);
        node54->setSelf(0U);
        node54->setEvent("");
        node54->setType(PhaseNode_Detect::Detect_Type::Actor_Dead);
        node54->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(21051, 54, node54)
    }
    if (noInit == true) {
        return node54;
    }
    return node54;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(21051, 56) {
}

REGISTER_CREATE_SKILL_NODE(21051, 56) {
    auto node56 = GET_SKILL_NODE(56, PhaseNode_EndPhase);
    if (node56 == nullptr) {
        node56 = new PhaseNode_EndPhase(56, phase);
        node56->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node56->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(21051, 56, node56)
    }
    if (noInit == true) {
        return node56;
    }
    return node56;
}
//--------------------------------------------------------------------------------
// MoveNewPene
//
REGISTER_REGISTER_SKILL_NODE(21051, 88) {
    pnode->resizeTrigger(PhaseNode_MoveNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_MoveNewPene::TRIGGER_DONE, 124, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(21051, 88) {
    auto node88 = GET_SKILL_NODE(88, PhaseNode_MoveNewPene);
    if (node88 == nullptr) {
        node88 = new PhaseNode_MoveNewPene(88, phase);
        node88->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node88->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node88->setPeneType(PhaseNode_MoveNewPene::MoveNewPene_PeneType::Projectile);
        node88->setPeneValue(30);
        node88->setType(PhaseNode_MoveNewPene::MoveNewPene_Type::Charge);
        node88->getVars().reserve(4);
        node88->getVars().setVariable<float>(0, 6.00f);
        node88->getVars().setVariable<float>(1, 6.00f);
        node88->getVars().setVariable<float>(2, .00f);
        node88->getVars().setVariable<float>(3, .00f);
        node88->setreentry(false);
        node88->setStopWhenFail(false);
        node88->setCheckFaction(PhaseNode_MoveNewPene::MoveNewPene_CheckFaction::Enemy);
        CALL_REGISTER_SKILL_NODE(21051, 88, node88)
    }
    if (noInit == true) {
        return node88;
    }
    auto node9 = GET_SKILL_NODE(9, PhaseNode_SpawnCollider);
    auto node123 = GET_SKILL_NODE(123, PhaseNode_OffsetCalculate);
    if (node9 != nullptr) node88->setTarget(node9->getColliderID());
    if (node123 != nullptr) node88->getVars().setVariable<float>(3, node123->getOutRotation());
    return node88;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(21051, 97) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 109, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 111, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(21051, 97) {
    auto node97 = GET_SKILL_NODE(97, PhaseNode_CreateTriggerNewPene);
    if (node97 == nullptr) {
        node97 = new PhaseNode_CreateTriggerNewPene(97, phase);
        node97->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::In);
        node97->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node97->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Enemy);
        node97->setOnHero(true);
        node97->setOnMinion(true);
        node97->setOnDestruct(true);
        node97->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(21051, 97, node97)
    }
    if (noInit == true) {
        return node97;
    }
    auto node9 = GET_SKILL_NODE(9, PhaseNode_SpawnCollider);
    if (node9 != nullptr) node97->setColliderID(node9->getColliderID());
    return node97;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(21051, 98) {
}

REGISTER_CREATE_SKILL_NODE(21051, 98) {
    auto node98 = GET_SKILL_NODE(98, PhaseNode_TriggerCheck);
    if (node98 == nullptr) {
        node98 = new PhaseNode_TriggerCheck(98, phase);
        auto node2 = GET_SKILL_NODE(2, PhaseNode_TriggerUpdate);
        if (node2 != nullptr) node2->addTriggerCheck(node98);
        
        CALL_REGISTER_SKILL_NODE(21051, 98, node98)
    }
    if (noInit == true) {
        return node98;
    }
    auto node107 = GET_SKILL_NODE(107, PhaseNode_CreateTriggerNewPene);
    if (node107 != nullptr) node98->setTrigger(0, node107->getTriggerID());
    return node98;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(21051, 99) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 100, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(21051, 99) {
    auto node99 = GET_SKILL_NODE(99, PhaseNode_ActorFilterNewPene);
    if (node99 == nullptr) {
        node99 = new PhaseNode_ActorFilterNewPene(99, phase);
        node99->setHero(true);
        node99->setMinion(true);
        node99->setDestruct(true);
        node99->setShield(false);
        node99->setTotalCount(0);
        node99->setPerCount(1);
        CALL_REGISTER_SKILL_NODE(21051, 99, node99)
    }
    if (noInit == true) {
        return node99;
    }
    auto node103 = GET_SKILL_NODE(103, PhaseNode_CreateTriggerNewPene);
    if (node103 != nullptr) node99->setInput(node103->getOther());
    return node99;
}
//--------------------------------------------------------------------------------
// GetActorAttribute
//
REGISTER_REGISTER_SKILL_NODE(21051, 100) {
    pnode->resizeTrigger(PhaseNode_GetActorAttribute::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 101, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 114, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 115, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 116, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
}

REGISTER_CREATE_SKILL_NODE(21051, 100) {
    auto node100 = GET_SKILL_NODE(100, PhaseNode_GetActorAttribute);
    if (node100 == nullptr) {
        node100 = new PhaseNode_GetActorAttribute(100, phase);
        node100->setTarget(0U);
        node100->setType({202});
        CALL_REGISTER_SKILL_NODE(21051, 100, node100)
    }
    if (noInit == true) {
        return node100;
    }
    return node100;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(21051, 101) {
}

REGISTER_CREATE_SKILL_NODE(21051, 101) {
    auto node101 = GET_SKILL_NODE(101, PhaseNode_AddSkillBuffs);
    if (node101 == nullptr) {
        node101 = new PhaseNode_AddSkillBuffs(101, phase);
        node101->setConfigID({11});
        CALL_REGISTER_SKILL_NODE(21051, 101, node101)
    }
    if (noInit == true) {
        return node101;
    }
    auto node99 = GET_SKILL_NODE(99, PhaseNode_ActorFilterNewPene);
    auto node100 = GET_SKILL_NODE(100, PhaseNode_GetActorAttribute);
    if (node99 != nullptr) node101->setTarget(node99->getOutput());
    if (node100 != nullptr) node101->setAttribute(node100->getAttribute());
    return node101;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(21051, 102) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 97, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_LESS, 103, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
}

REGISTER_CREATE_SKILL_NODE(21051, 102) {
    auto node102 = GET_SKILL_NODE(102, PhaseNode_CompareFloat);
    if (node102 == nullptr) {
        node102 = new PhaseNode_CompareFloat(102, phase);
        node102->setA(.00f);
        node102->setB(.00f);
        CALL_REGISTER_SKILL_NODE(21051, 102, node102)
    }
    if (noInit == true) {
        return node102;
    }
    return node102;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(21051, 103) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 108, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 99, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(21051, 103) {
    auto node103 = GET_SKILL_NODE(103, PhaseNode_CreateTriggerNewPene);
    if (node103 == nullptr) {
        node103 = new PhaseNode_CreateTriggerNewPene(103, phase);
        node103->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::Tick);
        node103->setTypeParams(0, .00f);
        node103->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node103->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Enemy);
        node103->setOnHero(true);
        node103->setOnMinion(true);
        node103->setOnDestruct(true);
        node103->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(21051, 103, node103)
    }
    if (noInit == true) {
        return node103;
    }
    auto node9 = GET_SKILL_NODE(9, PhaseNode_SpawnCollider);
    if (node9 != nullptr) node103->setColliderID(node9->getColliderID());
    return node103;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(21051, 104) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_If::TRIGGER_FALSE, 105, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_If::TRIGGER_TRUE, 102, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(21051, 104) {
    auto node104 = GET_SKILL_NODE(104, PhaseNode_If);
    if (node104 == nullptr) {
        node104 = new PhaseNode_If(104, phase);
        node104->setCondition(true);
        CALL_REGISTER_SKILL_NODE(21051, 104, node104)
    }
    if (noInit == true) {
        return node104;
    }
    return node104;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(21051, 105) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 107, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_LESS, 106, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
}

REGISTER_CREATE_SKILL_NODE(21051, 105) {
    auto node105 = GET_SKILL_NODE(105, PhaseNode_CompareFloat);
    if (node105 == nullptr) {
        node105 = new PhaseNode_CompareFloat(105, phase);
        node105->setA(.00f);
        node105->setB(.00f);
        CALL_REGISTER_SKILL_NODE(21051, 105, node105)
    }
    if (noInit == true) {
        return node105;
    }
    return node105;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(21051, 106) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 110, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 112, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(21051, 106) {
    auto node106 = GET_SKILL_NODE(106, PhaseNode_CreateTriggerNewPene);
    if (node106 == nullptr) {
        node106 = new PhaseNode_CreateTriggerNewPene(106, phase);
        node106->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::Tick);
        node106->setTypeParams(0, .00f);
        node106->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node106->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Friend);
        node106->setOnHero(true);
        node106->setOnMinion(true);
        node106->setOnDestruct(true);
        node106->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(21051, 106, node106)
    }
    if (noInit == true) {
        return node106;
    }
    auto node9 = GET_SKILL_NODE(9, PhaseNode_SpawnCollider);
    if (node9 != nullptr) node106->setColliderID(node9->getColliderID());
    return node106;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(21051, 107) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 98, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 113, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(21051, 107) {
    auto node107 = GET_SKILL_NODE(107, PhaseNode_CreateTriggerNewPene);
    if (node107 == nullptr) {
        node107 = new PhaseNode_CreateTriggerNewPene(107, phase);
        node107->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::In);
        node107->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node107->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Friend);
        node107->setOnHero(true);
        node107->setOnMinion(true);
        node107->setOnDestruct(true);
        node107->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(21051, 107, node107)
    }
    if (noInit == true) {
        return node107;
    }
    auto node9 = GET_SKILL_NODE(9, PhaseNode_SpawnCollider);
    if (node9 != nullptr) node107->setColliderID(node9->getColliderID());
    return node107;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(21051, 108) {
}

REGISTER_CREATE_SKILL_NODE(21051, 108) {
    auto node108 = GET_SKILL_NODE(108, PhaseNode_TriggerCheck);
    if (node108 == nullptr) {
        node108 = new PhaseNode_TriggerCheck(108, phase);
        auto node2 = GET_SKILL_NODE(2, PhaseNode_TriggerUpdate);
        if (node2 != nullptr) node2->addTriggerCheck(node108);
        
        CALL_REGISTER_SKILL_NODE(21051, 108, node108)
    }
    if (noInit == true) {
        return node108;
    }
    auto node103 = GET_SKILL_NODE(103, PhaseNode_CreateTriggerNewPene);
    if (node103 != nullptr) node108->setTrigger(0, node103->getTriggerID());
    return node108;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(21051, 109) {
}

REGISTER_CREATE_SKILL_NODE(21051, 109) {
    auto node109 = GET_SKILL_NODE(109, PhaseNode_TriggerCheck);
    if (node109 == nullptr) {
        node109 = new PhaseNode_TriggerCheck(109, phase);
        auto node2 = GET_SKILL_NODE(2, PhaseNode_TriggerUpdate);
        if (node2 != nullptr) node2->addTriggerCheck(node109);
        
        CALL_REGISTER_SKILL_NODE(21051, 109, node109)
    }
    if (noInit == true) {
        return node109;
    }
    auto node97 = GET_SKILL_NODE(97, PhaseNode_CreateTriggerNewPene);
    if (node97 != nullptr) node109->setTrigger(0, node97->getTriggerID());
    return node109;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(21051, 110) {
}

REGISTER_CREATE_SKILL_NODE(21051, 110) {
    auto node110 = GET_SKILL_NODE(110, PhaseNode_TriggerCheck);
    if (node110 == nullptr) {
        node110 = new PhaseNode_TriggerCheck(110, phase);
        auto node2 = GET_SKILL_NODE(2, PhaseNode_TriggerUpdate);
        if (node2 != nullptr) node2->addTriggerCheck(node110);
        
        CALL_REGISTER_SKILL_NODE(21051, 110, node110)
    }
    if (noInit == true) {
        return node110;
    }
    auto node106 = GET_SKILL_NODE(106, PhaseNode_CreateTriggerNewPene);
    if (node106 != nullptr) node110->setTrigger(0, node106->getTriggerID());
    return node110;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(21051, 111) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 100, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(21051, 111) {
    auto node111 = GET_SKILL_NODE(111, PhaseNode_ActorFilterNewPene);
    if (node111 == nullptr) {
        node111 = new PhaseNode_ActorFilterNewPene(111, phase);
        node111->setHero(true);
        node111->setMinion(true);
        node111->setDestruct(true);
        node111->setShield(false);
        node111->setTotalCount(0);
        node111->setPerCount(1);
        CALL_REGISTER_SKILL_NODE(21051, 111, node111)
    }
    if (noInit == true) {
        return node111;
    }
    auto node97 = GET_SKILL_NODE(97, PhaseNode_CreateTriggerNewPene);
    if (node97 != nullptr) node111->setInput(node97->getOther());
    return node111;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(21051, 112) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 100, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(21051, 112) {
    auto node112 = GET_SKILL_NODE(112, PhaseNode_ActorFilterNewPene);
    if (node112 == nullptr) {
        node112 = new PhaseNode_ActorFilterNewPene(112, phase);
        node112->setHero(true);
        node112->setMinion(true);
        node112->setDestruct(true);
        node112->setShield(false);
        node112->setTotalCount(0);
        node112->setPerCount(1);
        CALL_REGISTER_SKILL_NODE(21051, 112, node112)
    }
    if (noInit == true) {
        return node112;
    }
    auto node106 = GET_SKILL_NODE(106, PhaseNode_CreateTriggerNewPene);
    if (node106 != nullptr) node112->setInput(node106->getOther());
    return node112;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(21051, 113) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 100, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(21051, 113) {
    auto node113 = GET_SKILL_NODE(113, PhaseNode_ActorFilterNewPene);
    if (node113 == nullptr) {
        node113 = new PhaseNode_ActorFilterNewPene(113, phase);
        node113->setHero(true);
        node113->setMinion(true);
        node113->setDestruct(true);
        node113->setShield(false);
        node113->setTotalCount(0);
        node113->setPerCount(1);
        CALL_REGISTER_SKILL_NODE(21051, 113, node113)
    }
    if (noInit == true) {
        return node113;
    }
    auto node107 = GET_SKILL_NODE(107, PhaseNode_CreateTriggerNewPene);
    if (node107 != nullptr) node113->setInput(node107->getOther());
    return node113;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(21051, 114) {
}

REGISTER_CREATE_SKILL_NODE(21051, 114) {
    auto node114 = GET_SKILL_NODE(114, PhaseNode_AddSkillBuffs);
    if (node114 == nullptr) {
        node114 = new PhaseNode_AddSkillBuffs(114, phase);
        node114->setConfigID({11});
        CALL_REGISTER_SKILL_NODE(21051, 114, node114)
    }
    if (noInit == true) {
        return node114;
    }
    auto node111 = GET_SKILL_NODE(111, PhaseNode_ActorFilterNewPene);
    auto node100 = GET_SKILL_NODE(100, PhaseNode_GetActorAttribute);
    if (node111 != nullptr) node114->setTarget(node111->getOutput());
    if (node100 != nullptr) node114->setAttribute(node100->getAttribute());
    return node114;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(21051, 115) {
}

REGISTER_CREATE_SKILL_NODE(21051, 115) {
    auto node115 = GET_SKILL_NODE(115, PhaseNode_AddSkillBuffs);
    if (node115 == nullptr) {
        node115 = new PhaseNode_AddSkillBuffs(115, phase);
        node115->setConfigID({11});
        CALL_REGISTER_SKILL_NODE(21051, 115, node115)
    }
    if (noInit == true) {
        return node115;
    }
    auto node112 = GET_SKILL_NODE(112, PhaseNode_ActorFilterNewPene);
    auto node100 = GET_SKILL_NODE(100, PhaseNode_GetActorAttribute);
    if (node112 != nullptr) node115->setTarget(node112->getOutput());
    if (node100 != nullptr) node115->setAttribute(node100->getAttribute());
    return node115;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(21051, 116) {
}

REGISTER_CREATE_SKILL_NODE(21051, 116) {
    auto node116 = GET_SKILL_NODE(116, PhaseNode_AddSkillBuffs);
    if (node116 == nullptr) {
        node116 = new PhaseNode_AddSkillBuffs(116, phase);
        node116->setConfigID({11});
        CALL_REGISTER_SKILL_NODE(21051, 116, node116)
    }
    if (noInit == true) {
        return node116;
    }
    auto node113 = GET_SKILL_NODE(113, PhaseNode_ActorFilterNewPene);
    auto node100 = GET_SKILL_NODE(100, PhaseNode_GetActorAttribute);
    if (node113 != nullptr) node116->setTarget(node113->getOutput());
    if (node100 != nullptr) node116->setAttribute(node100->getAttribute());
    return node116;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(21051, 117) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_ResetCD::TRIGGER_DONE, 118, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(21051, 117) {
    auto node117 = GET_SKILL_NODE(117, PhaseNode_ResetCD);
    if (node117 == nullptr) {
        node117 = new PhaseNode_ResetCD(117, phase);
        node117->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node117->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node117->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(21051, 117, node117)
    }
    if (noInit == true) {
        return node117;
    }
    return node117;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(21051, 118) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_PlayAnimation::TRIGGER_DONE, 119, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(21051, 118) {
    auto node118 = GET_SKILL_NODE(118, PhaseNode_PlayAnimation);
    if (node118 == nullptr) {
        node118 = new PhaseNode_PlayAnimation(118, phase);
        node118->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node118->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node118->setTarget(0U);
        node118->setAnimation("Skill1S1");
        node118->setParameter("");
        node118->setValue(false);
        CALL_REGISTER_SKILL_NODE(21051, 118, node118)
    }
    if (noInit == true) {
        return node118;
    }
    return node118;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(21051, 119) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlaySound::TRIGGER_DONE, 120, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(21051, 119) {
    auto node119 = GET_SKILL_NODE(119, PhaseNode_PlaySound);
    if (node119 == nullptr) {
        node119 = new PhaseNode_PlaySound(119, phase);
        node119->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node119->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node119->setSoundID("SE_MON_Npc_Welder_Laser");
        node119->setTarget(0U);
        node119->setUsePos(false);
        node119->setPosX(.00f);
        node119->setPosY(.00f);
        node119->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(21051, 119, node119)
    }
    if (noInit == true) {
        return node119;
    }
    return node119;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(21051, 120) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_Delay::TRIGGER_DONE, 121, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(21051, 120) {
    auto node120 = GET_SKILL_NODE(120, PhaseNode_Delay);
    if (node120 == nullptr) {
        node120 = new PhaseNode_Delay(120, phase);
        node120->setTime(.20f);
        CALL_REGISTER_SKILL_NODE(21051, 120, node120)
    }
    if (noInit == true) {
        return node120;
    }
    return node120;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(21051, 121) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetRotation>(PhaseNode_GetLocation::TRIGGER_DONE, 122, PhaseNode_GetRotation::FUNC_DO, &PhaseNode_GetRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(21051, 121) {
    auto node121 = GET_SKILL_NODE(121, PhaseNode_GetLocation);
    if (node121 == nullptr) {
        node121 = new PhaseNode_GetLocation(121, phase);
        node121->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node121->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(21051, 121, node121)
    }
    if (noInit == true) {
        return node121;
    }
    return node121;
}
//--------------------------------------------------------------------------------
// GetRotation
//
REGISTER_REGISTER_SKILL_NODE(21051, 122) {
    pnode->resizeTrigger(PhaseNode_GetRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_OffsetCalculate>(PhaseNode_GetRotation::TRIGGER_DONE, 123, PhaseNode_OffsetCalculate::FUNC_DO, &PhaseNode_OffsetCalculate::Do);
}

REGISTER_CREATE_SKILL_NODE(21051, 122) {
    auto node122 = GET_SKILL_NODE(122, PhaseNode_GetRotation);
    if (node122 == nullptr) {
        node122 = new PhaseNode_GetRotation(122, phase);
        node122->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node122->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(21051, 122, node122)
    }
    if (noInit == true) {
        return node122;
    }
    return node122;
}
//--------------------------------------------------------------------------------
// OffsetCalculate
//
REGISTER_REGISTER_SKILL_NODE(21051, 123) {
    pnode->resizeTrigger(PhaseNode_OffsetCalculate::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 129, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(21051, 123) {
    auto node123 = GET_SKILL_NODE(123, PhaseNode_OffsetCalculate);
    if (node123 == nullptr) {
        node123 = new PhaseNode_OffsetCalculate(123, phase);
        node123->setPosZ(.00f);
        node123->setOffsetX(.00f);
        node123->setOffsetY(.00f);
        node123->setOffsetZ(.00f);
        node123->setRotOffset(.00f);
        CALL_REGISTER_SKILL_NODE(21051, 123, node123)
    }
    if (noInit == true) {
        return node123;
    }
    auto node121 = GET_SKILL_NODE(121, PhaseNode_GetLocation);
    auto node122 = GET_SKILL_NODE(122, PhaseNode_GetRotation);
    if (node121 != nullptr) node123->setPosX(node121->getX());
    if (node121 != nullptr) node123->setPosY(node121->getY());
    if (node122 != nullptr) node123->setRotation(node122->getAngle());
    return node123;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(21051, 124) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_Delay::TRIGGER_DONE, 126, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(21051, 124) {
    auto node124 = GET_SKILL_NODE(124, PhaseNode_Delay);
    if (node124 == nullptr) {
        node124 = new PhaseNode_Delay(124, phase);
        node124->setTime(.35f);
        CALL_REGISTER_SKILL_NODE(21051, 124, node124)
    }
    if (noInit == true) {
        return node124;
    }
    return node124;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(21051, 125) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 13, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(21051, 125) {
    auto node125 = GET_SKILL_NODE(125, PhaseNode_SkillEndNotify);
    if (node125 == nullptr) {
        node125 = new PhaseNode_SkillEndNotify(125, phase);
        node125->setReturnType(false);
        CALL_REGISTER_SKILL_NODE(21051, 125, node125)
    }
    if (noInit == true) {
        return node125;
    }
    return node125;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(21051, 126) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_FALSE, 127, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_TRUE, 125, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
}

REGISTER_CREATE_SKILL_NODE(21051, 126) {
    auto node126 = GET_SKILL_NODE(126, PhaseNode_If);
    if (node126 == nullptr) {
        node126 = new PhaseNode_If(126, phase);
        node126->setCondition(false);
        CALL_REGISTER_SKILL_NODE(21051, 126, node126)
    }
    if (noInit == true) {
        return node126;
    }
    return node126;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(21051, 127) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 13, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(21051, 127) {
    auto node127 = GET_SKILL_NODE(127, PhaseNode_SkillEndNotify);
    if (node127 == nullptr) {
        node127 = new PhaseNode_SkillEndNotify(127, phase);
        node127->setReturnType(true);
        CALL_REGISTER_SKILL_NODE(21051, 127, node127)
    }
    if (noInit == true) {
        return node127;
    }
    return node127;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(21051, 128) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_PlayEffect::TRIGGER_DONE, 131, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(21051, 128) {
    auto node128 = GET_SKILL_NODE(128, PhaseNode_PlayEffect);
    if (node128 == nullptr) {
        node128 = new PhaseNode_PlayEffect(128, phase);
        node128->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node128->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node128->setEffectID(1038);
        node128->setChangeColor(false);
        node128->setType(PhaseNode_PlayEffect::PlayEffect_Type::WithTarget);
        node128->getVars().reserve(5);
        node128->getVars().setVariable<uint64_t>(0, 0U);
        node128->getVars().setVariable<std::string>(1, "Bone011");
        node128->getVars().setVariable<float>(2, .00f);
        node128->getVars().setVariable<float>(3, .00f);
        node128->getVars().setVariable<float>(4, .00f);
        node128->setRotation(.00f);
        node128->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(21051, 128, node128)
    }
    if (noInit == true) {
        return node128;
    }
    return node128;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(21051, 129) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_FALSE, 130, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_TRUE, 128, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(21051, 129) {
    auto node129 = GET_SKILL_NODE(129, PhaseNode_If);
    if (node129 == nullptr) {
        node129 = new PhaseNode_If(129, phase);
        node129->setCondition(true);
        CALL_REGISTER_SKILL_NODE(21051, 129, node129)
    }
    if (noInit == true) {
        return node129;
    }
    return node129;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(21051, 130) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_PlayEffect::TRIGGER_DONE, 131, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(21051, 130) {
    auto node130 = GET_SKILL_NODE(130, PhaseNode_PlayEffect);
    if (node130 == nullptr) {
        node130 = new PhaseNode_PlayEffect(130, phase);
        node130->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node130->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node130->setEffectID(1038);
        node130->setChangeColor(false);
        node130->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node130->getVars().reserve(3);
        node130->getVars().setVariable<float>(0, .00f);
        node130->getVars().setVariable<float>(1, .00f);
        node130->getVars().setVariable<float>(2, .00f);
        node130->setRotation(.00f);
        node130->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(21051, 130, node130)
    }
    if (noInit == true) {
        return node130;
    }
    return node130;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(21051, 131) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 135, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_LESS, 132, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_CompareFloat::TRIGGER_LESS, 135, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(21051, 131) {
    auto node131 = GET_SKILL_NODE(131, PhaseNode_CompareFloat);
    if (node131 == nullptr) {
        node131 = new PhaseNode_CompareFloat(131, phase);
        node131->setA(.00f);
        node131->setB(.00f);
        CALL_REGISTER_SKILL_NODE(21051, 131, node131)
    }
    if (noInit == true) {
        return node131;
    }
    return node131;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(21051, 132) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StopEffect>(PhaseNode_Delay::TRIGGER_DONE, 133, PhaseNode_StopEffect::FUNC_DO, &PhaseNode_StopEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(21051, 132) {
    auto node132 = GET_SKILL_NODE(132, PhaseNode_Delay);
    if (node132 == nullptr) {
        node132 = new PhaseNode_Delay(132, phase);
        node132->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(21051, 132, node132)
    }
    if (noInit == true) {
        return node132;
    }
    return node132;
}
//--------------------------------------------------------------------------------
// StopEffect
//
REGISTER_REGISTER_SKILL_NODE(21051, 133) {
}

REGISTER_CREATE_SKILL_NODE(21051, 133) {
    auto node133 = GET_SKILL_NODE(133, PhaseNode_StopEffect);
    if (node133 == nullptr) {
        node133 = new PhaseNode_StopEffect(133, phase);
        node133->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node133->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node133->setEffectID(1038);
        CALL_REGISTER_SKILL_NODE(21051, 133, node133)
    }
    if (noInit == true) {
        return node133;
    }
    return node133;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(21051, 134) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_PlayEffect::TRIGGER_DONE, 137, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(21051, 134) {
    auto node134 = GET_SKILL_NODE(134, PhaseNode_PlayEffect);
    if (node134 == nullptr) {
        node134 = new PhaseNode_PlayEffect(134, phase);
        node134->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node134->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node134->setEffectID(1039);
        node134->setChangeColor(false);
        node134->setType(PhaseNode_PlayEffect::PlayEffect_Type::WithTarget);
        node134->getVars().reserve(5);
        node134->getVars().setVariable<uint64_t>(0, 0U);
        node134->getVars().setVariable<std::string>(1, "");
        node134->getVars().setVariable<float>(2, .00f);
        node134->getVars().setVariable<float>(3, .00f);
        node134->getVars().setVariable<float>(4, .00f);
        node134->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(21051, 134, node134)
    }
    if (noInit == true) {
        return node134;
    }
    auto node123 = GET_SKILL_NODE(123, PhaseNode_OffsetCalculate);
    if (node123 != nullptr) node134->getVars().setVariable<float>(2, node123->getOutPosX());
    if (node123 != nullptr) node134->getVars().setVariable<float>(3, node123->getOutPosY());
    if (node123 != nullptr) node134->getVars().setVariable<float>(4, node123->getOutPosZ());
    if (node123 != nullptr) node134->setRotation(node123->getOutRotation());
    return node134;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(21051, 135) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_FALSE, 136, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_TRUE, 134, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(21051, 135) {
    auto node135 = GET_SKILL_NODE(135, PhaseNode_If);
    if (node135 == nullptr) {
        node135 = new PhaseNode_If(135, phase);
        node135->setCondition(false);
        CALL_REGISTER_SKILL_NODE(21051, 135, node135)
    }
    if (noInit == true) {
        return node135;
    }
    return node135;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(21051, 136) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_PlayEffect::TRIGGER_DONE, 137, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(21051, 136) {
    auto node136 = GET_SKILL_NODE(136, PhaseNode_PlayEffect);
    if (node136 == nullptr) {
        node136 = new PhaseNode_PlayEffect(136, phase);
        node136->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node136->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node136->setEffectID(1039);
        node136->setChangeColor(false);
        node136->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node136->getVars().reserve(3);
        node136->getVars().setVariable<float>(0, .00f);
        node136->getVars().setVariable<float>(1, .00f);
        node136->getVars().setVariable<float>(2, .00f);
        node136->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(21051, 136, node136)
    }
    if (noInit == true) {
        return node136;
    }
    auto node123 = GET_SKILL_NODE(123, PhaseNode_OffsetCalculate);
    if (node123 != nullptr) node136->getVars().setVariable<float>(0, node123->getOutPosX());
    if (node123 != nullptr) node136->getVars().setVariable<float>(1, node123->getOutPosY());
    if (node123 != nullptr) node136->getVars().setVariable<float>(2, node123->getOutPosZ());
    if (node123 != nullptr) node136->setRotation(node123->getOutRotation());
    return node136;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(21051, 137) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnCollider>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 9, PhaseNode_SpawnCollider::FUNC_DO, &PhaseNode_SpawnCollider::Do);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_LESS, 138, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_SpawnCollider>(PhaseNode_CompareFloat::TRIGGER_LESS, 9, PhaseNode_SpawnCollider::FUNC_DO, &PhaseNode_SpawnCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(21051, 137) {
    auto node137 = GET_SKILL_NODE(137, PhaseNode_CompareFloat);
    if (node137 == nullptr) {
        node137 = new PhaseNode_CompareFloat(137, phase);
        node137->setA(.00f);
        node137->setB(.00f);
        CALL_REGISTER_SKILL_NODE(21051, 137, node137)
    }
    if (noInit == true) {
        return node137;
    }
    return node137;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(21051, 138) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StopEffect>(PhaseNode_Delay::TRIGGER_DONE, 139, PhaseNode_StopEffect::FUNC_DO, &PhaseNode_StopEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(21051, 138) {
    auto node138 = GET_SKILL_NODE(138, PhaseNode_Delay);
    if (node138 == nullptr) {
        node138 = new PhaseNode_Delay(138, phase);
        node138->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(21051, 138, node138)
    }
    if (noInit == true) {
        return node138;
    }
    return node138;
}
//--------------------------------------------------------------------------------
// StopEffect
//
REGISTER_REGISTER_SKILL_NODE(21051, 139) {
}

REGISTER_CREATE_SKILL_NODE(21051, 139) {
    auto node139 = GET_SKILL_NODE(139, PhaseNode_StopEffect);
    if (node139 == nullptr) {
        node139 = new PhaseNode_StopEffect(139, phase);
        node139->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node139->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node139->setEffectID(1039);
        CALL_REGISTER_SKILL_NODE(21051, 139, node139)
    }
    if (noInit == true) {
        return node139;
    }
    return node139;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(21051, 140) {
}

REGISTER_CREATE_SKILL_NODE(21051, 140) {
    auto node140 = GET_SKILL_NODE(140, PhaseNode_RaiseEvent);
    if (node140 == nullptr) {
        node140 = new PhaseNode_RaiseEvent(140, phase);
        node140->setEvent("MonsterInterrupt");
        node140->setTarget(0U);
        node140->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node140->setTypeParams(0, 0);
        node140->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(21051, 140, node140)
    }
    if (noInit == true) {
        return node140;
    }
    return node140;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(21051, 141) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_Detect::TRIGGER_ON, 144, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(21051, 141) {
    auto node141 = GET_SKILL_NODE(141, PhaseNode_Detect);
    if (node141 == nullptr) {
        node141 = new PhaseNode_Detect(141, phase);
        node141->setSelf(0U);
        node141->setEvent("MonsterInterrupt");
        node141->setType(PhaseNode_Detect::Detect_Type::Interrupt_Skill);
        node141->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(21051, 141, node141)
    }
    if (noInit == true) {
        return node141;
    }
    return node141;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(21051, 142) {
}

REGISTER_CREATE_SKILL_NODE(21051, 142) {
    auto node142 = GET_SKILL_NODE(142, PhaseNode_EndPhase);
    if (node142 == nullptr) {
        node142 = new PhaseNode_EndPhase(142, phase);
        node142->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node142->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(21051, 142, node142)
    }
    if (noInit == true) {
        return node142;
    }
    return node142;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(21051, 144) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_Delay::TRIGGER_DONE, 146, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(21051, 144) {
    auto node144 = GET_SKILL_NODE(144, PhaseNode_Delay);
    if (node144 == nullptr) {
        node144 = new PhaseNode_Delay(144, phase);
        node144->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(21051, 144, node144)
    }
    if (noInit == true) {
        return node144;
    }
    return node144;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(21051, 145) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 142, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(21051, 145) {
    auto node145 = GET_SKILL_NODE(145, PhaseNode_SkillEndNotify);
    if (node145 == nullptr) {
        node145 = new PhaseNode_SkillEndNotify(145, phase);
        node145->setReturnType(false);
        CALL_REGISTER_SKILL_NODE(21051, 145, node145)
    }
    if (noInit == true) {
        return node145;
    }
    return node145;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(21051, 146) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_FALSE, 147, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_TRUE, 145, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
}

REGISTER_CREATE_SKILL_NODE(21051, 146) {
    auto node146 = GET_SKILL_NODE(146, PhaseNode_If);
    if (node146 == nullptr) {
        node146 = new PhaseNode_If(146, phase);
        node146->setCondition(false);
        CALL_REGISTER_SKILL_NODE(21051, 146, node146)
    }
    if (noInit == true) {
        return node146;
    }
    return node146;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(21051, 147) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 142, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(21051, 147) {
    auto node147 = GET_SKILL_NODE(147, PhaseNode_SkillEndNotify);
    if (node147 == nullptr) {
        node147 = new PhaseNode_SkillEndNotify(147, phase);
        node147->setReturnType(true);
        CALL_REGISTER_SKILL_NODE(21051, 147, node147)
    }
    if (noInit == true) {
        return node147;
    }
    return node147;
}

//--------------------------------------------------------------------------------
// SkillCreator_21051
//
class SkillCreator_21051 : public SkillCreator {
public:
    SkillCreator_21051() {}
    virtual ~SkillCreator_21051() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_21051

//--------------------------------------------------------------------------------
// SkillPhase_21051
//
class SkillPhase_21051 : public SkillPhase {
public:
    SkillPhase_21051(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_21051() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(21051, 1) // StartPhase
        CASE_CREATE_SKILL_NODE(21051, 2) // TriggerUpdate
        CASE_CREATE_SKILL_NODE(21051, 9) // SpawnCollider
        CASE_CREATE_SKILL_NODE(21051, 13) // EndPhase
        CASE_CREATE_SKILL_NODE(21051, 54) // Detect
        CASE_CREATE_SKILL_NODE(21051, 56) // EndPhase
        CASE_CREATE_SKILL_NODE(21051, 88) // MoveNewPene
        CASE_CREATE_SKILL_NODE(21051, 97) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(21051, 98) // TriggerCheck
        CASE_CREATE_SKILL_NODE(21051, 99) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(21051, 100) // GetActorAttribute
        CASE_CREATE_SKILL_NODE(21051, 101) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(21051, 102) // CompareFloat
        CASE_CREATE_SKILL_NODE(21051, 103) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(21051, 104) // If
        CASE_CREATE_SKILL_NODE(21051, 105) // CompareFloat
        CASE_CREATE_SKILL_NODE(21051, 106) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(21051, 107) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(21051, 108) // TriggerCheck
        CASE_CREATE_SKILL_NODE(21051, 109) // TriggerCheck
        CASE_CREATE_SKILL_NODE(21051, 110) // TriggerCheck
        CASE_CREATE_SKILL_NODE(21051, 111) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(21051, 112) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(21051, 113) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(21051, 114) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(21051, 115) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(21051, 116) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(21051, 117) // ResetCD
        CASE_CREATE_SKILL_NODE(21051, 118) // PlayAnimation
        CASE_CREATE_SKILL_NODE(21051, 119) // PlaySound
        CASE_CREATE_SKILL_NODE(21051, 120) // Delay
        CASE_CREATE_SKILL_NODE(21051, 121) // GetLocation
        CASE_CREATE_SKILL_NODE(21051, 122) // GetRotation
        CASE_CREATE_SKILL_NODE(21051, 123) // OffsetCalculate
        CASE_CREATE_SKILL_NODE(21051, 124) // Delay
        CASE_CREATE_SKILL_NODE(21051, 125) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(21051, 126) // If
        CASE_CREATE_SKILL_NODE(21051, 127) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(21051, 128) // PlayEffect
        CASE_CREATE_SKILL_NODE(21051, 129) // If
        CASE_CREATE_SKILL_NODE(21051, 130) // PlayEffect
        CASE_CREATE_SKILL_NODE(21051, 131) // CompareFloat
        CASE_CREATE_SKILL_NODE(21051, 132) // Delay
        CASE_CREATE_SKILL_NODE(21051, 133) // StopEffect
        CASE_CREATE_SKILL_NODE(21051, 134) // PlayEffect
        CASE_CREATE_SKILL_NODE(21051, 135) // If
        CASE_CREATE_SKILL_NODE(21051, 136) // PlayEffect
        CASE_CREATE_SKILL_NODE(21051, 137) // CompareFloat
        CASE_CREATE_SKILL_NODE(21051, 138) // Delay
        CASE_CREATE_SKILL_NODE(21051, 139) // StopEffect
        CASE_CREATE_SKILL_NODE(21051, 140) // RaiseEvent
        CASE_CREATE_SKILL_NODE(21051, 141) // Detect
        CASE_CREATE_SKILL_NODE(21051, 142) // EndPhase
        CASE_CREATE_SKILL_NODE(21051, 144) // Delay
        CASE_CREATE_SKILL_NODE(21051, 145) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(21051, 146) // If
        CASE_CREATE_SKILL_NODE(21051, 147) // SkillEndNotify
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_21051

SkillLogic* SkillCreator_21051::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //创建阶段phase
    auto phase = new SkillPhase_21051(1, logic, 3);
    //设置phase执行器
    phase->setRunPhaseNode(1, 1);
    phase->setRunPhaseNode(2, 2);
    phase->setDetectPhaseNode(3, 54);
    phase->setDetectPhaseNode(3, 141);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_21051::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
