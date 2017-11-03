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
REGISTER_REGISTER_SKILL_NODE(21021, 1) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_StartPhase::TRIGGER_START, 137, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_StartPhase::TRIGGER_START, 133, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_StartPhase::TRIGGER_START, 110, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(21021, 1) {
    auto node1 = GET_SKILL_NODE(1, PhaseNode_StartPhase);
    if (node1 == nullptr) {
        node1 = new PhaseNode_StartPhase(1, phase);
        CALL_REGISTER_SKILL_NODE(21021, 1, node1)
    }
    if (noInit == true) {
        return node1;
    }
    return node1;
}
//--------------------------------------------------------------------------------
// TriggerUpdate
//
REGISTER_REGISTER_SKILL_NODE(21021, 2) {
}

REGISTER_CREATE_SKILL_NODE(21021, 2) {
    auto node2 = GET_SKILL_NODE(2, PhaseNode_TriggerUpdate);
    if (node2 == nullptr) {
        node2 = new PhaseNode_TriggerUpdate(2, phase);
        CALL_REGISTER_SKILL_NODE(21021, 2, node2)
    }
    if (noInit == true) {
        return node2;
    }
    return node2;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(21021, 8) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnCollider>(PhaseNode_Delay::TRIGGER_DONE, 9, PhaseNode_SpawnCollider::FUNC_DO, &PhaseNode_SpawnCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(21021, 8) {
    auto node8 = GET_SKILL_NODE(8, PhaseNode_Delay);
    if (node8 == nullptr) {
        node8 = new PhaseNode_Delay(8, phase);
        node8->setTime(.80f);
        CALL_REGISTER_SKILL_NODE(21021, 8, node8)
    }
    if (noInit == true) {
        return node8;
    }
    return node8;
}
//--------------------------------------------------------------------------------
// SpawnCollider
//
REGISTER_REGISTER_SKILL_NODE(21021, 9) {
    pnode->resizeTrigger(PhaseNode_SpawnCollider::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_SpawnCollider::TRIGGER_DONE, 129, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_SpawnCollider::TRIGGER_DONE, 139, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_SpawnCollider::TRIGGER_DONE, 97, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(21021, 9) {
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
        node9->setTypeParams(0, 4.00f);
        node9->setTime(.30f);
        node9->setPosZ(.00f);
        node9->setRotation(.00f);
        node9->setreentry(false);
        node9->setCheckPeneSound(false);
        CALL_REGISTER_SKILL_NODE(21021, 9, node9)
    }
    if (noInit == true) {
        return node9;
    }
    auto node116 = GET_SKILL_NODE(116, PhaseNode_OffsetCalculate);
    if (node116 != nullptr) node9->setPosX(node116->getOutPosX());
    if (node116 != nullptr) node9->setPosY(node116->getOutPosY());
    return node9;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(21021, 13) {
}

REGISTER_CREATE_SKILL_NODE(21021, 13) {
    auto node13 = GET_SKILL_NODE(13, PhaseNode_EndPhase);
    if (node13 == nullptr) {
        node13 = new PhaseNode_EndPhase(13, phase);
        node13->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node13->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(21021, 13, node13)
    }
    if (noInit == true) {
        return node13;
    }
    return node13;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(21021, 54) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_Detect::TRIGGER_ON, 56, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(21021, 54) {
    auto node54 = GET_SKILL_NODE(54, PhaseNode_Detect);
    if (node54 == nullptr) {
        node54 = new PhaseNode_Detect(54, phase);
        node54->setSelf(0U);
        node54->setEvent("");
        node54->setType(PhaseNode_Detect::Detect_Type::Actor_Dead);
        node54->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(21021, 54, node54)
    }
    if (noInit == true) {
        return node54;
    }
    return node54;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(21021, 56) {
}

REGISTER_CREATE_SKILL_NODE(21021, 56) {
    auto node56 = GET_SKILL_NODE(56, PhaseNode_EndPhase);
    if (node56 == nullptr) {
        node56 = new PhaseNode_EndPhase(56, phase);
        node56->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node56->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(21021, 56, node56)
    }
    if (noInit == true) {
        return node56;
    }
    return node56;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(21021, 90) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 102, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 104, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(21021, 90) {
    auto node90 = GET_SKILL_NODE(90, PhaseNode_CreateTriggerNewPene);
    if (node90 == nullptr) {
        node90 = new PhaseNode_CreateTriggerNewPene(90, phase);
        node90->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::In);
        node90->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node90->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Enemy);
        node90->setOnHero(true);
        node90->setOnMinion(true);
        node90->setOnDestruct(true);
        node90->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(21021, 90, node90)
    }
    if (noInit == true) {
        return node90;
    }
    auto node9 = GET_SKILL_NODE(9, PhaseNode_SpawnCollider);
    if (node9 != nullptr) node90->setColliderID(node9->getColliderID());
    return node90;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(21021, 91) {
}

REGISTER_CREATE_SKILL_NODE(21021, 91) {
    auto node91 = GET_SKILL_NODE(91, PhaseNode_TriggerCheck);
    if (node91 == nullptr) {
        node91 = new PhaseNode_TriggerCheck(91, phase);
        auto node2 = GET_SKILL_NODE(2, PhaseNode_TriggerUpdate);
        if (node2 != nullptr) node2->addTriggerCheck(node91);
        
        CALL_REGISTER_SKILL_NODE(21021, 91, node91)
    }
    if (noInit == true) {
        return node91;
    }
    auto node100 = GET_SKILL_NODE(100, PhaseNode_CreateTriggerNewPene);
    if (node100 != nullptr) node91->setTrigger(0, node100->getTriggerID());
    return node91;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(21021, 92) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 93, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(21021, 92) {
    auto node92 = GET_SKILL_NODE(92, PhaseNode_ActorFilterNewPene);
    if (node92 == nullptr) {
        node92 = new PhaseNode_ActorFilterNewPene(92, phase);
        node92->setHero(true);
        node92->setMinion(true);
        node92->setDestruct(true);
        node92->setShield(false);
        node92->setTotalCount(0);
        node92->setPerCount(1);
        CALL_REGISTER_SKILL_NODE(21021, 92, node92)
    }
    if (noInit == true) {
        return node92;
    }
    auto node96 = GET_SKILL_NODE(96, PhaseNode_CreateTriggerNewPene);
    if (node96 != nullptr) node92->setInput(node96->getOther());
    return node92;
}
//--------------------------------------------------------------------------------
// GetActorAttribute
//
REGISTER_REGISTER_SKILL_NODE(21021, 93) {
    pnode->resizeTrigger(PhaseNode_GetActorAttribute::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 107, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 108, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 109, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 94, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
}

REGISTER_CREATE_SKILL_NODE(21021, 93) {
    auto node93 = GET_SKILL_NODE(93, PhaseNode_GetActorAttribute);
    if (node93 == nullptr) {
        node93 = new PhaseNode_GetActorAttribute(93, phase);
        node93->setTarget(0U);
        node93->setType({202});
        CALL_REGISTER_SKILL_NODE(21021, 93, node93)
    }
    if (noInit == true) {
        return node93;
    }
    return node93;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(21021, 94) {
}

REGISTER_CREATE_SKILL_NODE(21021, 94) {
    auto node94 = GET_SKILL_NODE(94, PhaseNode_AddSkillBuffs);
    if (node94 == nullptr) {
        node94 = new PhaseNode_AddSkillBuffs(94, phase);
        node94->setConfigID({11});
        CALL_REGISTER_SKILL_NODE(21021, 94, node94)
    }
    if (noInit == true) {
        return node94;
    }
    auto node92 = GET_SKILL_NODE(92, PhaseNode_ActorFilterNewPene);
    auto node93 = GET_SKILL_NODE(93, PhaseNode_GetActorAttribute);
    if (node92 != nullptr) node94->setTarget(node92->getOutput());
    if (node93 != nullptr) node94->setAttribute(node93->getAttribute());
    return node94;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(21021, 95) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 90, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_LESS, 96, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
}

REGISTER_CREATE_SKILL_NODE(21021, 95) {
    auto node95 = GET_SKILL_NODE(95, PhaseNode_CompareFloat);
    if (node95 == nullptr) {
        node95 = new PhaseNode_CompareFloat(95, phase);
        node95->setA(.00f);
        node95->setB(.00f);
        CALL_REGISTER_SKILL_NODE(21021, 95, node95)
    }
    if (noInit == true) {
        return node95;
    }
    return node95;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(21021, 96) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 101, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 92, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(21021, 96) {
    auto node96 = GET_SKILL_NODE(96, PhaseNode_CreateTriggerNewPene);
    if (node96 == nullptr) {
        node96 = new PhaseNode_CreateTriggerNewPene(96, phase);
        node96->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::Tick);
        node96->setTypeParams(0, .00f);
        node96->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node96->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Enemy);
        node96->setOnHero(true);
        node96->setOnMinion(true);
        node96->setOnDestruct(true);
        node96->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(21021, 96, node96)
    }
    if (noInit == true) {
        return node96;
    }
    auto node9 = GET_SKILL_NODE(9, PhaseNode_SpawnCollider);
    if (node9 != nullptr) node96->setColliderID(node9->getColliderID());
    return node96;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(21021, 97) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_If::TRIGGER_FALSE, 98, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_If::TRIGGER_TRUE, 95, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(21021, 97) {
    auto node97 = GET_SKILL_NODE(97, PhaseNode_If);
    if (node97 == nullptr) {
        node97 = new PhaseNode_If(97, phase);
        node97->setCondition(true);
        CALL_REGISTER_SKILL_NODE(21021, 97, node97)
    }
    if (noInit == true) {
        return node97;
    }
    return node97;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(21021, 98) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 100, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_LESS, 99, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
}

REGISTER_CREATE_SKILL_NODE(21021, 98) {
    auto node98 = GET_SKILL_NODE(98, PhaseNode_CompareFloat);
    if (node98 == nullptr) {
        node98 = new PhaseNode_CompareFloat(98, phase);
        node98->setA(.00f);
        node98->setB(.00f);
        CALL_REGISTER_SKILL_NODE(21021, 98, node98)
    }
    if (noInit == true) {
        return node98;
    }
    return node98;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(21021, 99) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 103, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 105, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(21021, 99) {
    auto node99 = GET_SKILL_NODE(99, PhaseNode_CreateTriggerNewPene);
    if (node99 == nullptr) {
        node99 = new PhaseNode_CreateTriggerNewPene(99, phase);
        node99->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::Tick);
        node99->setTypeParams(0, .00f);
        node99->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node99->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Friend);
        node99->setOnHero(true);
        node99->setOnMinion(true);
        node99->setOnDestruct(true);
        node99->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(21021, 99, node99)
    }
    if (noInit == true) {
        return node99;
    }
    auto node9 = GET_SKILL_NODE(9, PhaseNode_SpawnCollider);
    if (node9 != nullptr) node99->setColliderID(node9->getColliderID());
    return node99;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(21021, 100) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 91, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 106, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(21021, 100) {
    auto node100 = GET_SKILL_NODE(100, PhaseNode_CreateTriggerNewPene);
    if (node100 == nullptr) {
        node100 = new PhaseNode_CreateTriggerNewPene(100, phase);
        node100->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::In);
        node100->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node100->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Friend);
        node100->setOnHero(true);
        node100->setOnMinion(true);
        node100->setOnDestruct(true);
        node100->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(21021, 100, node100)
    }
    if (noInit == true) {
        return node100;
    }
    auto node9 = GET_SKILL_NODE(9, PhaseNode_SpawnCollider);
    if (node9 != nullptr) node100->setColliderID(node9->getColliderID());
    return node100;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(21021, 101) {
}

REGISTER_CREATE_SKILL_NODE(21021, 101) {
    auto node101 = GET_SKILL_NODE(101, PhaseNode_TriggerCheck);
    if (node101 == nullptr) {
        node101 = new PhaseNode_TriggerCheck(101, phase);
        auto node2 = GET_SKILL_NODE(2, PhaseNode_TriggerUpdate);
        if (node2 != nullptr) node2->addTriggerCheck(node101);
        
        CALL_REGISTER_SKILL_NODE(21021, 101, node101)
    }
    if (noInit == true) {
        return node101;
    }
    auto node96 = GET_SKILL_NODE(96, PhaseNode_CreateTriggerNewPene);
    if (node96 != nullptr) node101->setTrigger(0, node96->getTriggerID());
    return node101;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(21021, 102) {
}

REGISTER_CREATE_SKILL_NODE(21021, 102) {
    auto node102 = GET_SKILL_NODE(102, PhaseNode_TriggerCheck);
    if (node102 == nullptr) {
        node102 = new PhaseNode_TriggerCheck(102, phase);
        auto node2 = GET_SKILL_NODE(2, PhaseNode_TriggerUpdate);
        if (node2 != nullptr) node2->addTriggerCheck(node102);
        
        CALL_REGISTER_SKILL_NODE(21021, 102, node102)
    }
    if (noInit == true) {
        return node102;
    }
    auto node90 = GET_SKILL_NODE(90, PhaseNode_CreateTriggerNewPene);
    if (node90 != nullptr) node102->setTrigger(0, node90->getTriggerID());
    return node102;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(21021, 103) {
}

REGISTER_CREATE_SKILL_NODE(21021, 103) {
    auto node103 = GET_SKILL_NODE(103, PhaseNode_TriggerCheck);
    if (node103 == nullptr) {
        node103 = new PhaseNode_TriggerCheck(103, phase);
        auto node2 = GET_SKILL_NODE(2, PhaseNode_TriggerUpdate);
        if (node2 != nullptr) node2->addTriggerCheck(node103);
        
        CALL_REGISTER_SKILL_NODE(21021, 103, node103)
    }
    if (noInit == true) {
        return node103;
    }
    auto node99 = GET_SKILL_NODE(99, PhaseNode_CreateTriggerNewPene);
    if (node99 != nullptr) node103->setTrigger(0, node99->getTriggerID());
    return node103;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(21021, 104) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 93, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(21021, 104) {
    auto node104 = GET_SKILL_NODE(104, PhaseNode_ActorFilterNewPene);
    if (node104 == nullptr) {
        node104 = new PhaseNode_ActorFilterNewPene(104, phase);
        node104->setHero(true);
        node104->setMinion(true);
        node104->setDestruct(true);
        node104->setShield(false);
        node104->setTotalCount(0);
        node104->setPerCount(1);
        CALL_REGISTER_SKILL_NODE(21021, 104, node104)
    }
    if (noInit == true) {
        return node104;
    }
    auto node90 = GET_SKILL_NODE(90, PhaseNode_CreateTriggerNewPene);
    if (node90 != nullptr) node104->setInput(node90->getOther());
    return node104;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(21021, 105) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 93, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(21021, 105) {
    auto node105 = GET_SKILL_NODE(105, PhaseNode_ActorFilterNewPene);
    if (node105 == nullptr) {
        node105 = new PhaseNode_ActorFilterNewPene(105, phase);
        node105->setHero(true);
        node105->setMinion(true);
        node105->setDestruct(true);
        node105->setShield(false);
        node105->setTotalCount(0);
        node105->setPerCount(1);
        CALL_REGISTER_SKILL_NODE(21021, 105, node105)
    }
    if (noInit == true) {
        return node105;
    }
    auto node99 = GET_SKILL_NODE(99, PhaseNode_CreateTriggerNewPene);
    if (node99 != nullptr) node105->setInput(node99->getOther());
    return node105;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(21021, 106) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 93, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(21021, 106) {
    auto node106 = GET_SKILL_NODE(106, PhaseNode_ActorFilterNewPene);
    if (node106 == nullptr) {
        node106 = new PhaseNode_ActorFilterNewPene(106, phase);
        node106->setHero(true);
        node106->setMinion(true);
        node106->setDestruct(true);
        node106->setShield(false);
        node106->setTotalCount(0);
        node106->setPerCount(1);
        CALL_REGISTER_SKILL_NODE(21021, 106, node106)
    }
    if (noInit == true) {
        return node106;
    }
    auto node100 = GET_SKILL_NODE(100, PhaseNode_CreateTriggerNewPene);
    if (node100 != nullptr) node106->setInput(node100->getOther());
    return node106;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(21021, 107) {
}

REGISTER_CREATE_SKILL_NODE(21021, 107) {
    auto node107 = GET_SKILL_NODE(107, PhaseNode_AddSkillBuffs);
    if (node107 == nullptr) {
        node107 = new PhaseNode_AddSkillBuffs(107, phase);
        node107->setConfigID({11});
        CALL_REGISTER_SKILL_NODE(21021, 107, node107)
    }
    if (noInit == true) {
        return node107;
    }
    auto node104 = GET_SKILL_NODE(104, PhaseNode_ActorFilterNewPene);
    auto node93 = GET_SKILL_NODE(93, PhaseNode_GetActorAttribute);
    if (node104 != nullptr) node107->setTarget(node104->getOutput());
    if (node93 != nullptr) node107->setAttribute(node93->getAttribute());
    return node107;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(21021, 108) {
}

REGISTER_CREATE_SKILL_NODE(21021, 108) {
    auto node108 = GET_SKILL_NODE(108, PhaseNode_AddSkillBuffs);
    if (node108 == nullptr) {
        node108 = new PhaseNode_AddSkillBuffs(108, phase);
        node108->setConfigID({11});
        CALL_REGISTER_SKILL_NODE(21021, 108, node108)
    }
    if (noInit == true) {
        return node108;
    }
    auto node105 = GET_SKILL_NODE(105, PhaseNode_ActorFilterNewPene);
    auto node93 = GET_SKILL_NODE(93, PhaseNode_GetActorAttribute);
    if (node105 != nullptr) node108->setTarget(node105->getOutput());
    if (node93 != nullptr) node108->setAttribute(node93->getAttribute());
    return node108;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(21021, 109) {
}

REGISTER_CREATE_SKILL_NODE(21021, 109) {
    auto node109 = GET_SKILL_NODE(109, PhaseNode_AddSkillBuffs);
    if (node109 == nullptr) {
        node109 = new PhaseNode_AddSkillBuffs(109, phase);
        node109->setConfigID({11});
        CALL_REGISTER_SKILL_NODE(21021, 109, node109)
    }
    if (noInit == true) {
        return node109;
    }
    auto node106 = GET_SKILL_NODE(106, PhaseNode_ActorFilterNewPene);
    auto node93 = GET_SKILL_NODE(93, PhaseNode_GetActorAttribute);
    if (node106 != nullptr) node109->setTarget(node106->getOutput());
    if (node93 != nullptr) node109->setAttribute(node93->getAttribute());
    return node109;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(21021, 110) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_ResetCD::TRIGGER_DONE, 111, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(21021, 110) {
    auto node110 = GET_SKILL_NODE(110, PhaseNode_ResetCD);
    if (node110 == nullptr) {
        node110 = new PhaseNode_ResetCD(110, phase);
        node110->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node110->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node110->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(21021, 110, node110)
    }
    if (noInit == true) {
        return node110;
    }
    return node110;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(21021, 111) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_PlayAnimation::TRIGGER_DONE, 112, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(21021, 111) {
    auto node111 = GET_SKILL_NODE(111, PhaseNode_PlayAnimation);
    if (node111 == nullptr) {
        node111 = new PhaseNode_PlayAnimation(111, phase);
        node111->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node111->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node111->setTarget(0U);
        node111->setAnimation("Skill1S1");
        node111->setParameter("");
        node111->setValue(false);
        CALL_REGISTER_SKILL_NODE(21021, 111, node111)
    }
    if (noInit == true) {
        return node111;
    }
    return node111;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(21021, 112) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlaySound::TRIGGER_DONE, 113, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(21021, 112) {
    auto node112 = GET_SKILL_NODE(112, PhaseNode_PlaySound);
    if (node112 == nullptr) {
        node112 = new PhaseNode_PlaySound(112, phase);
        node112->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node112->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node112->setSoundID("");
        node112->setTarget(0U);
        node112->setUsePos(false);
        node112->setPosX(.00f);
        node112->setPosY(.00f);
        node112->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(21021, 112, node112)
    }
    if (noInit == true) {
        return node112;
    }
    return node112;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(21021, 113) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_Delay::TRIGGER_DONE, 114, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(21021, 113) {
    auto node113 = GET_SKILL_NODE(113, PhaseNode_Delay);
    if (node113 == nullptr) {
        node113 = new PhaseNode_Delay(113, phase);
        node113->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(21021, 113, node113)
    }
    if (noInit == true) {
        return node113;
    }
    return node113;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(21021, 114) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetRotation>(PhaseNode_GetLocation::TRIGGER_DONE, 115, PhaseNode_GetRotation::FUNC_DO, &PhaseNode_GetRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(21021, 114) {
    auto node114 = GET_SKILL_NODE(114, PhaseNode_GetLocation);
    if (node114 == nullptr) {
        node114 = new PhaseNode_GetLocation(114, phase);
        node114->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node114->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(21021, 114, node114)
    }
    if (noInit == true) {
        return node114;
    }
    return node114;
}
//--------------------------------------------------------------------------------
// GetRotation
//
REGISTER_REGISTER_SKILL_NODE(21021, 115) {
    pnode->resizeTrigger(PhaseNode_GetRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_OffsetCalculate>(PhaseNode_GetRotation::TRIGGER_DONE, 116, PhaseNode_OffsetCalculate::FUNC_DO, &PhaseNode_OffsetCalculate::Do);
}

REGISTER_CREATE_SKILL_NODE(21021, 115) {
    auto node115 = GET_SKILL_NODE(115, PhaseNode_GetRotation);
    if (node115 == nullptr) {
        node115 = new PhaseNode_GetRotation(115, phase);
        node115->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node115->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(21021, 115, node115)
    }
    if (noInit == true) {
        return node115;
    }
    return node115;
}
//--------------------------------------------------------------------------------
// OffsetCalculate
//
REGISTER_REGISTER_SKILL_NODE(21021, 116) {
    pnode->resizeTrigger(PhaseNode_OffsetCalculate::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 118, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(21021, 116) {
    auto node116 = GET_SKILL_NODE(116, PhaseNode_OffsetCalculate);
    if (node116 == nullptr) {
        node116 = new PhaseNode_OffsetCalculate(116, phase);
        node116->setPosZ(.00f);
        node116->setOffsetX(.00f);
        node116->setOffsetY(.00f);
        node116->setOffsetZ(.00f);
        node116->setRotOffset(.00f);
        CALL_REGISTER_SKILL_NODE(21021, 116, node116)
    }
    if (noInit == true) {
        return node116;
    }
    auto node114 = GET_SKILL_NODE(114, PhaseNode_GetLocation);
    auto node115 = GET_SKILL_NODE(115, PhaseNode_GetRotation);
    if (node114 != nullptr) node116->setPosX(node114->getX());
    if (node114 != nullptr) node116->setPosY(node114->getY());
    if (node115 != nullptr) node116->setRotation(node115->getAngle());
    return node116;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(21021, 117) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_PlayEffect::TRIGGER_DONE, 120, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(21021, 117) {
    auto node117 = GET_SKILL_NODE(117, PhaseNode_PlayEffect);
    if (node117 == nullptr) {
        node117 = new PhaseNode_PlayEffect(117, phase);
        node117->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node117->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node117->setEffectID(1050);
        node117->setChangeColor(false);
        node117->setType(PhaseNode_PlayEffect::PlayEffect_Type::WithTarget);
        node117->getVars().reserve(5);
        node117->getVars().setVariable<uint64_t>(0, 0U);
        node117->getVars().setVariable<std::string>(1, "Bone001");
        node117->getVars().setVariable<float>(2, .00f);
        node117->getVars().setVariable<float>(3, .00f);
        node117->getVars().setVariable<float>(4, .00f);
        node117->setRotation(.00f);
        node117->setScale(.00f);
        CALL_REGISTER_SKILL_NODE(21021, 117, node117)
    }
    if (noInit == true) {
        return node117;
    }
    return node117;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(21021, 118) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_FALSE, 119, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_TRUE, 117, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(21021, 118) {
    auto node118 = GET_SKILL_NODE(118, PhaseNode_If);
    if (node118 == nullptr) {
        node118 = new PhaseNode_If(118, phase);
        node118->setCondition(true);
        CALL_REGISTER_SKILL_NODE(21021, 118, node118)
    }
    if (noInit == true) {
        return node118;
    }
    return node118;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(21021, 119) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_PlayEffect::TRIGGER_DONE, 120, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(21021, 119) {
    auto node119 = GET_SKILL_NODE(119, PhaseNode_PlayEffect);
    if (node119 == nullptr) {
        node119 = new PhaseNode_PlayEffect(119, phase);
        node119->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node119->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node119->setEffectID(1050);
        node119->setChangeColor(false);
        node119->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node119->getVars().reserve(3);
        node119->getVars().setVariable<float>(0, .00f);
        node119->getVars().setVariable<float>(1, .00f);
        node119->getVars().setVariable<float>(2, .00f);
        node119->setRotation(.00f);
        node119->setScale(.00f);
        CALL_REGISTER_SKILL_NODE(21021, 119, node119)
    }
    if (noInit == true) {
        return node119;
    }
    return node119;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(21021, 120) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 124, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_LESS, 121, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_CompareFloat::TRIGGER_LESS, 124, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(21021, 120) {
    auto node120 = GET_SKILL_NODE(120, PhaseNode_CompareFloat);
    if (node120 == nullptr) {
        node120 = new PhaseNode_CompareFloat(120, phase);
        node120->setA(.00f);
        node120->setB(.00f);
        CALL_REGISTER_SKILL_NODE(21021, 120, node120)
    }
    if (noInit == true) {
        return node120;
    }
    return node120;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(21021, 121) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StopEffect>(PhaseNode_Delay::TRIGGER_DONE, 122, PhaseNode_StopEffect::FUNC_DO, &PhaseNode_StopEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(21021, 121) {
    auto node121 = GET_SKILL_NODE(121, PhaseNode_Delay);
    if (node121 == nullptr) {
        node121 = new PhaseNode_Delay(121, phase);
        node121->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(21021, 121, node121)
    }
    if (noInit == true) {
        return node121;
    }
    return node121;
}
//--------------------------------------------------------------------------------
// StopEffect
//
REGISTER_REGISTER_SKILL_NODE(21021, 122) {
}

REGISTER_CREATE_SKILL_NODE(21021, 122) {
    auto node122 = GET_SKILL_NODE(122, PhaseNode_StopEffect);
    if (node122 == nullptr) {
        node122 = new PhaseNode_StopEffect(122, phase);
        node122->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node122->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node122->setEffectID(1050);
        CALL_REGISTER_SKILL_NODE(21021, 122, node122)
    }
    if (noInit == true) {
        return node122;
    }
    return node122;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(21021, 123) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_PlayEffect::TRIGGER_DONE, 126, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(21021, 123) {
    auto node123 = GET_SKILL_NODE(123, PhaseNode_PlayEffect);
    if (node123 == nullptr) {
        node123 = new PhaseNode_PlayEffect(123, phase);
        node123->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node123->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node123->setEffectID(1014);
        node123->setChangeColor(false);
        node123->setType(PhaseNode_PlayEffect::PlayEffect_Type::WithTarget);
        node123->getVars().reserve(5);
        node123->getVars().setVariable<uint64_t>(0, 0U);
        node123->getVars().setVariable<std::string>(1, "");
        node123->getVars().setVariable<float>(2, .00f);
        node123->getVars().setVariable<float>(3, .00f);
        node123->getVars().setVariable<float>(4, .00f);
        node123->setScale(2.00f);
        CALL_REGISTER_SKILL_NODE(21021, 123, node123)
    }
    if (noInit == true) {
        return node123;
    }
    auto node116 = GET_SKILL_NODE(116, PhaseNode_OffsetCalculate);
    if (node116 != nullptr) node123->getVars().setVariable<float>(2, node116->getOutPosX());
    if (node116 != nullptr) node123->getVars().setVariable<float>(3, node116->getOutPosY());
    if (node116 != nullptr) node123->getVars().setVariable<float>(4, node116->getOutPosZ());
    if (node116 != nullptr) node123->setRotation(node116->getOutRotation());
    return node123;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(21021, 124) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_FALSE, 125, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_TRUE, 123, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(21021, 124) {
    auto node124 = GET_SKILL_NODE(124, PhaseNode_If);
    if (node124 == nullptr) {
        node124 = new PhaseNode_If(124, phase);
        node124->setCondition(false);
        CALL_REGISTER_SKILL_NODE(21021, 124, node124)
    }
    if (noInit == true) {
        return node124;
    }
    return node124;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(21021, 125) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_PlayEffect::TRIGGER_DONE, 126, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(21021, 125) {
    auto node125 = GET_SKILL_NODE(125, PhaseNode_PlayEffect);
    if (node125 == nullptr) {
        node125 = new PhaseNode_PlayEffect(125, phase);
        node125->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node125->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node125->setEffectID(1014);
        node125->setChangeColor(false);
        node125->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node125->getVars().reserve(3);
        node125->getVars().setVariable<float>(0, .00f);
        node125->getVars().setVariable<float>(1, .00f);
        node125->getVars().setVariable<float>(2, .00f);
        node125->setScale(2.00f);
        CALL_REGISTER_SKILL_NODE(21021, 125, node125)
    }
    if (noInit == true) {
        return node125;
    }
    auto node116 = GET_SKILL_NODE(116, PhaseNode_OffsetCalculate);
    if (node116 != nullptr) node125->getVars().setVariable<float>(0, node116->getOutPosX());
    if (node116 != nullptr) node125->getVars().setVariable<float>(1, node116->getOutPosY());
    if (node116 != nullptr) node125->getVars().setVariable<float>(2, node116->getOutPosZ());
    if (node116 != nullptr) node125->setRotation(node116->getOutRotation());
    return node125;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(21021, 126) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 8, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_LESS, 127, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_LESS, 8, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(21021, 126) {
    auto node126 = GET_SKILL_NODE(126, PhaseNode_CompareFloat);
    if (node126 == nullptr) {
        node126 = new PhaseNode_CompareFloat(126, phase);
        node126->setA(.00f);
        node126->setB(1.10f);
        CALL_REGISTER_SKILL_NODE(21021, 126, node126)
    }
    if (noInit == true) {
        return node126;
    }
    return node126;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(21021, 127) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StopEffect>(PhaseNode_Delay::TRIGGER_DONE, 128, PhaseNode_StopEffect::FUNC_DO, &PhaseNode_StopEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(21021, 127) {
    auto node127 = GET_SKILL_NODE(127, PhaseNode_Delay);
    if (node127 == nullptr) {
        node127 = new PhaseNode_Delay(127, phase);
        node127->setTime(1.10f);
        CALL_REGISTER_SKILL_NODE(21021, 127, node127)
    }
    if (noInit == true) {
        return node127;
    }
    return node127;
}
//--------------------------------------------------------------------------------
// StopEffect
//
REGISTER_REGISTER_SKILL_NODE(21021, 128) {
}

REGISTER_CREATE_SKILL_NODE(21021, 128) {
    auto node128 = GET_SKILL_NODE(128, PhaseNode_StopEffect);
    if (node128 == nullptr) {
        node128 = new PhaseNode_StopEffect(128, phase);
        node128->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node128->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node128->setEffectID(1014);
        CALL_REGISTER_SKILL_NODE(21021, 128, node128)
    }
    if (noInit == true) {
        return node128;
    }
    return node128;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(21021, 129) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_Delay::TRIGGER_DONE, 131, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(21021, 129) {
    auto node129 = GET_SKILL_NODE(129, PhaseNode_Delay);
    if (node129 == nullptr) {
        node129 = new PhaseNode_Delay(129, phase);
        node129->setTime(.80f);
        CALL_REGISTER_SKILL_NODE(21021, 129, node129)
    }
    if (noInit == true) {
        return node129;
    }
    return node129;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(21021, 130) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 13, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(21021, 130) {
    auto node130 = GET_SKILL_NODE(130, PhaseNode_SkillEndNotify);
    if (node130 == nullptr) {
        node130 = new PhaseNode_SkillEndNotify(130, phase);
        node130->setReturnType(false);
        CALL_REGISTER_SKILL_NODE(21021, 130, node130)
    }
    if (noInit == true) {
        return node130;
    }
    return node130;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(21021, 131) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_FALSE, 132, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_TRUE, 130, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
}

REGISTER_CREATE_SKILL_NODE(21021, 131) {
    auto node131 = GET_SKILL_NODE(131, PhaseNode_If);
    if (node131 == nullptr) {
        node131 = new PhaseNode_If(131, phase);
        node131->setCondition(false);
        CALL_REGISTER_SKILL_NODE(21021, 131, node131)
    }
    if (noInit == true) {
        return node131;
    }
    return node131;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(21021, 132) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 13, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(21021, 132) {
    auto node132 = GET_SKILL_NODE(132, PhaseNode_SkillEndNotify);
    if (node132 == nullptr) {
        node132 = new PhaseNode_SkillEndNotify(132, phase);
        node132->setReturnType(true);
        CALL_REGISTER_SKILL_NODE(21021, 132, node132)
    }
    if (noInit == true) {
        return node132;
    }
    return node132;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(21021, 133) {
}

REGISTER_CREATE_SKILL_NODE(21021, 133) {
    auto node133 = GET_SKILL_NODE(133, PhaseNode_RaiseEvent);
    if (node133 == nullptr) {
        node133 = new PhaseNode_RaiseEvent(133, phase);
        node133->setEvent("MonsterInterrupt");
        node133->setTarget(0U);
        node133->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node133->setTypeParams(0, 0);
        node133->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(21021, 133, node133)
    }
    if (noInit == true) {
        return node133;
    }
    return node133;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(21021, 134) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_Detect::TRIGGER_ON, 141, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(21021, 134) {
    auto node134 = GET_SKILL_NODE(134, PhaseNode_Detect);
    if (node134 == nullptr) {
        node134 = new PhaseNode_Detect(134, phase);
        node134->setSelf(0U);
        node134->setEvent("MonsterInterrupt");
        node134->setType(PhaseNode_Detect::Detect_Type::Interrupt_Skill);
        node134->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(21021, 134, node134)
    }
    if (noInit == true) {
        return node134;
    }
    return node134;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(21021, 135) {
}

REGISTER_CREATE_SKILL_NODE(21021, 135) {
    auto node135 = GET_SKILL_NODE(135, PhaseNode_EndPhase);
    if (node135 == nullptr) {
        node135 = new PhaseNode_EndPhase(135, phase);
        node135->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node135->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(21021, 135, node135)
    }
    if (noInit == true) {
        return node135;
    }
    return node135;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(21021, 137) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_Delay::TRIGGER_DONE, 138, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(21021, 137) {
    auto node137 = GET_SKILL_NODE(137, PhaseNode_Delay);
    if (node137 == nullptr) {
        node137 = new PhaseNode_Delay(137, phase);
        node137->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(21021, 137, node137)
    }
    if (noInit == true) {
        return node137;
    }
    return node137;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(21021, 138) {
}

REGISTER_CREATE_SKILL_NODE(21021, 138) {
    auto node138 = GET_SKILL_NODE(138, PhaseNode_PlaySound);
    if (node138 == nullptr) {
        node138 = new PhaseNode_PlaySound(138, phase);
        node138->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node138->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node138->setSoundID("SE_MON2102_ATK_P0");
        node138->setTarget(0U);
        node138->setUsePos(false);
        node138->setPosX(.00f);
        node138->setPosY(.00f);
        node138->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(21021, 138, node138)
    }
    if (noInit == true) {
        return node138;
    }
    return node138;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(21021, 139) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_Delay::TRIGGER_DONE, 140, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(21021, 139) {
    auto node139 = GET_SKILL_NODE(139, PhaseNode_Delay);
    if (node139 == nullptr) {
        node139 = new PhaseNode_Delay(139, phase);
        node139->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(21021, 139, node139)
    }
    if (noInit == true) {
        return node139;
    }
    return node139;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(21021, 140) {
}

REGISTER_CREATE_SKILL_NODE(21021, 140) {
    auto node140 = GET_SKILL_NODE(140, PhaseNode_PlaySound);
    if (node140 == nullptr) {
        node140 = new PhaseNode_PlaySound(140, phase);
        node140->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node140->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node140->setSoundID("SE_MON2102_ATK_P1");
        node140->setTarget(0U);
        node140->setUsePos(false);
        node140->setPosX(.00f);
        node140->setPosY(.00f);
        node140->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(21021, 140, node140)
    }
    if (noInit == true) {
        return node140;
    }
    return node140;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(21021, 141) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_Delay::TRIGGER_DONE, 143, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(21021, 141) {
    auto node141 = GET_SKILL_NODE(141, PhaseNode_Delay);
    if (node141 == nullptr) {
        node141 = new PhaseNode_Delay(141, phase);
        node141->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(21021, 141, node141)
    }
    if (noInit == true) {
        return node141;
    }
    return node141;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(21021, 142) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 135, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(21021, 142) {
    auto node142 = GET_SKILL_NODE(142, PhaseNode_SkillEndNotify);
    if (node142 == nullptr) {
        node142 = new PhaseNode_SkillEndNotify(142, phase);
        node142->setReturnType(false);
        CALL_REGISTER_SKILL_NODE(21021, 142, node142)
    }
    if (noInit == true) {
        return node142;
    }
    return node142;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(21021, 143) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_FALSE, 144, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_TRUE, 142, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
}

REGISTER_CREATE_SKILL_NODE(21021, 143) {
    auto node143 = GET_SKILL_NODE(143, PhaseNode_If);
    if (node143 == nullptr) {
        node143 = new PhaseNode_If(143, phase);
        node143->setCondition(false);
        CALL_REGISTER_SKILL_NODE(21021, 143, node143)
    }
    if (noInit == true) {
        return node143;
    }
    return node143;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(21021, 144) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 135, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(21021, 144) {
    auto node144 = GET_SKILL_NODE(144, PhaseNode_SkillEndNotify);
    if (node144 == nullptr) {
        node144 = new PhaseNode_SkillEndNotify(144, phase);
        node144->setReturnType(true);
        CALL_REGISTER_SKILL_NODE(21021, 144, node144)
    }
    if (noInit == true) {
        return node144;
    }
    return node144;
}

//--------------------------------------------------------------------------------
// SkillCreator_21021
//
class SkillCreator_21021 : public SkillCreator {
public:
    SkillCreator_21021() {}
    virtual ~SkillCreator_21021() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_21021

//--------------------------------------------------------------------------------
// SkillPhase_21021
//
class SkillPhase_21021 : public SkillPhase {
public:
    SkillPhase_21021(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_21021() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(21021, 1) // StartPhase
        CASE_CREATE_SKILL_NODE(21021, 2) // TriggerUpdate
        CASE_CREATE_SKILL_NODE(21021, 8) // Delay
        CASE_CREATE_SKILL_NODE(21021, 9) // SpawnCollider
        CASE_CREATE_SKILL_NODE(21021, 13) // EndPhase
        CASE_CREATE_SKILL_NODE(21021, 54) // Detect
        CASE_CREATE_SKILL_NODE(21021, 56) // EndPhase
        CASE_CREATE_SKILL_NODE(21021, 90) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(21021, 91) // TriggerCheck
        CASE_CREATE_SKILL_NODE(21021, 92) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(21021, 93) // GetActorAttribute
        CASE_CREATE_SKILL_NODE(21021, 94) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(21021, 95) // CompareFloat
        CASE_CREATE_SKILL_NODE(21021, 96) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(21021, 97) // If
        CASE_CREATE_SKILL_NODE(21021, 98) // CompareFloat
        CASE_CREATE_SKILL_NODE(21021, 99) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(21021, 100) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(21021, 101) // TriggerCheck
        CASE_CREATE_SKILL_NODE(21021, 102) // TriggerCheck
        CASE_CREATE_SKILL_NODE(21021, 103) // TriggerCheck
        CASE_CREATE_SKILL_NODE(21021, 104) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(21021, 105) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(21021, 106) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(21021, 107) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(21021, 108) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(21021, 109) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(21021, 110) // ResetCD
        CASE_CREATE_SKILL_NODE(21021, 111) // PlayAnimation
        CASE_CREATE_SKILL_NODE(21021, 112) // PlaySound
        CASE_CREATE_SKILL_NODE(21021, 113) // Delay
        CASE_CREATE_SKILL_NODE(21021, 114) // GetLocation
        CASE_CREATE_SKILL_NODE(21021, 115) // GetRotation
        CASE_CREATE_SKILL_NODE(21021, 116) // OffsetCalculate
        CASE_CREATE_SKILL_NODE(21021, 117) // PlayEffect
        CASE_CREATE_SKILL_NODE(21021, 118) // If
        CASE_CREATE_SKILL_NODE(21021, 119) // PlayEffect
        CASE_CREATE_SKILL_NODE(21021, 120) // CompareFloat
        CASE_CREATE_SKILL_NODE(21021, 121) // Delay
        CASE_CREATE_SKILL_NODE(21021, 122) // StopEffect
        CASE_CREATE_SKILL_NODE(21021, 123) // PlayEffect
        CASE_CREATE_SKILL_NODE(21021, 124) // If
        CASE_CREATE_SKILL_NODE(21021, 125) // PlayEffect
        CASE_CREATE_SKILL_NODE(21021, 126) // CompareFloat
        CASE_CREATE_SKILL_NODE(21021, 127) // Delay
        CASE_CREATE_SKILL_NODE(21021, 128) // StopEffect
        CASE_CREATE_SKILL_NODE(21021, 129) // Delay
        CASE_CREATE_SKILL_NODE(21021, 130) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(21021, 131) // If
        CASE_CREATE_SKILL_NODE(21021, 132) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(21021, 133) // RaiseEvent
        CASE_CREATE_SKILL_NODE(21021, 134) // Detect
        CASE_CREATE_SKILL_NODE(21021, 135) // EndPhase
        CASE_CREATE_SKILL_NODE(21021, 137) // Delay
        CASE_CREATE_SKILL_NODE(21021, 138) // PlaySound
        CASE_CREATE_SKILL_NODE(21021, 139) // Delay
        CASE_CREATE_SKILL_NODE(21021, 140) // PlaySound
        CASE_CREATE_SKILL_NODE(21021, 141) // Delay
        CASE_CREATE_SKILL_NODE(21021, 142) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(21021, 143) // If
        CASE_CREATE_SKILL_NODE(21021, 144) // SkillEndNotify
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_21021

SkillLogic* SkillCreator_21021::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //创建阶段phase
    auto phase = new SkillPhase_21021(1, logic, 3);
    //设置phase执行器
    phase->setRunPhaseNode(1, 1);
    phase->setRunPhaseNode(2, 2);
    phase->setDetectPhaseNode(3, 54);
    phase->setDetectPhaseNode(3, 134);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_21021::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
