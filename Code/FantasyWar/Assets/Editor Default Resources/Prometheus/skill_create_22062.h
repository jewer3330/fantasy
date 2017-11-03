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
REGISTER_REGISTER_SKILL_NODE(22062, 2) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_StartPhase::TRIGGER_START, 92, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_StartPhase::TRIGGER_START, 88, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_StartPhase::TRIGGER_START, 71, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(22062, 2) {
    auto node2 = GET_SKILL_NODE(2, PhaseNode_StartPhase);
    if (node2 == nullptr) {
        node2 = new PhaseNode_StartPhase(2, phase);
        CALL_REGISTER_SKILL_NODE(22062, 2, node2)
    }
    if (noInit == true) {
        return node2;
    }
    return node2;
}
//--------------------------------------------------------------------------------
// TriggerUpdate
//
REGISTER_REGISTER_SKILL_NODE(22062, 4) {
}

REGISTER_CREATE_SKILL_NODE(22062, 4) {
    auto node4 = GET_SKILL_NODE(4, PhaseNode_TriggerUpdate);
    if (node4 == nullptr) {
        node4 = new PhaseNode_TriggerUpdate(4, phase);
        CALL_REGISTER_SKILL_NODE(22062, 4, node4)
    }
    if (noInit == true) {
        return node4;
    }
    return node4;
}
//--------------------------------------------------------------------------------
// SpawnCollider
//
REGISTER_REGISTER_SKILL_NODE(22062, 21) {
    pnode->resizeTrigger(PhaseNode_SpawnCollider::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_SpawnCollider::TRIGGER_DONE, 78, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_SpawnCollider::TRIGGER_DONE, 58, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(22062, 21) {
    auto node21 = GET_SKILL_NODE(21, PhaseNode_SpawnCollider);
    if (node21 == nullptr) {
        node21 = new PhaseNode_SpawnCollider(21, phase);
        node21->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node21->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node21->setMesh("");
        node21->setMeshScale(.00f);
        node21->setEffectID(0);
        node21->setEffectScale(.00f);
        node21->setType(PhaseNode_SpawnCollider::SpawnCollider_Type::Sector);
        node21->setTypeParams(0, 4.00f);
        node21->setTypeParams(1, 60.00f);
        node21->setTime(.30f);
        node21->setreentry(false);
        node21->setCheckPeneSound(false);
        CALL_REGISTER_SKILL_NODE(22062, 21, node21)
    }
    if (noInit == true) {
        return node21;
    }
    auto node77 = GET_SKILL_NODE(77, PhaseNode_OffsetCalculate);
    if (node77 != nullptr) node21->setPosX(node77->getOutPosX());
    if (node77 != nullptr) node21->setPosY(node77->getOutPosY());
    if (node77 != nullptr) node21->setPosZ(node77->getOutPosZ());
    if (node77 != nullptr) node21->setRotation(node77->getOutRotation());
    return node21;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(22062, 36) {
}

REGISTER_CREATE_SKILL_NODE(22062, 36) {
    auto node36 = GET_SKILL_NODE(36, PhaseNode_EndPhase);
    if (node36 == nullptr) {
        node36 = new PhaseNode_EndPhase(36, phase);
        node36->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node36->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(22062, 36, node36)
    }
    if (noInit == true) {
        return node36;
    }
    return node36;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(22062, 51) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 63, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 65, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(22062, 51) {
    auto node51 = GET_SKILL_NODE(51, PhaseNode_CreateTriggerNewPene);
    if (node51 == nullptr) {
        node51 = new PhaseNode_CreateTriggerNewPene(51, phase);
        node51->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::In);
        node51->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node51->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Enemy);
        node51->setOnHero(true);
        node51->setOnMinion(true);
        node51->setOnDestruct(false);
        node51->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(22062, 51, node51)
    }
    if (noInit == true) {
        return node51;
    }
    auto node21 = GET_SKILL_NODE(21, PhaseNode_SpawnCollider);
    if (node21 != nullptr) node51->setColliderID(node21->getColliderID());
    return node51;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(22062, 52) {
}

REGISTER_CREATE_SKILL_NODE(22062, 52) {
    auto node52 = GET_SKILL_NODE(52, PhaseNode_TriggerCheck);
    if (node52 == nullptr) {
        node52 = new PhaseNode_TriggerCheck(52, phase);
        auto node4 = GET_SKILL_NODE(4, PhaseNode_TriggerUpdate);
        if (node4 != nullptr) node4->addTriggerCheck(node52);
        
        CALL_REGISTER_SKILL_NODE(22062, 52, node52)
    }
    if (noInit == true) {
        return node52;
    }
    auto node61 = GET_SKILL_NODE(61, PhaseNode_CreateTriggerNewPene);
    if (node61 != nullptr) node52->setTrigger(0, node61->getTriggerID());
    return node52;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(22062, 53) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 54, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(22062, 53) {
    auto node53 = GET_SKILL_NODE(53, PhaseNode_ActorFilterNewPene);
    if (node53 == nullptr) {
        node53 = new PhaseNode_ActorFilterNewPene(53, phase);
        node53->setHero(true);
        node53->setMinion(true);
        node53->setDestruct(false);
        node53->setShield(false);
        node53->setTotalCount(0);
        node53->setPerCount(1);
        CALL_REGISTER_SKILL_NODE(22062, 53, node53)
    }
    if (noInit == true) {
        return node53;
    }
    auto node57 = GET_SKILL_NODE(57, PhaseNode_CreateTriggerNewPene);
    if (node57 != nullptr) node53->setInput(node57->getOther());
    return node53;
}
//--------------------------------------------------------------------------------
// GetActorAttribute
//
REGISTER_REGISTER_SKILL_NODE(22062, 54) {
    pnode->resizeTrigger(PhaseNode_GetActorAttribute::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 55, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 68, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 69, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 70, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
}

REGISTER_CREATE_SKILL_NODE(22062, 54) {
    auto node54 = GET_SKILL_NODE(54, PhaseNode_GetActorAttribute);
    if (node54 == nullptr) {
        node54 = new PhaseNode_GetActorAttribute(54, phase);
        node54->setTarget(0U);
        node54->setType({202});
        CALL_REGISTER_SKILL_NODE(22062, 54, node54)
    }
    if (noInit == true) {
        return node54;
    }
    return node54;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(22062, 55) {
}

REGISTER_CREATE_SKILL_NODE(22062, 55) {
    auto node55 = GET_SKILL_NODE(55, PhaseNode_AddSkillBuffs);
    if (node55 == nullptr) {
        node55 = new PhaseNode_AddSkillBuffs(55, phase);
        node55->setConfigID({13});
        CALL_REGISTER_SKILL_NODE(22062, 55, node55)
    }
    if (noInit == true) {
        return node55;
    }
    auto node53 = GET_SKILL_NODE(53, PhaseNode_ActorFilterNewPene);
    auto node54 = GET_SKILL_NODE(54, PhaseNode_GetActorAttribute);
    if (node53 != nullptr) node55->setTarget(node53->getOutput());
    if (node54 != nullptr) node55->setAttribute(node54->getAttribute());
    return node55;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(22062, 56) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 51, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_LESS, 57, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
}

REGISTER_CREATE_SKILL_NODE(22062, 56) {
    auto node56 = GET_SKILL_NODE(56, PhaseNode_CompareFloat);
    if (node56 == nullptr) {
        node56 = new PhaseNode_CompareFloat(56, phase);
        node56->setA(.00f);
        node56->setB(.00f);
        CALL_REGISTER_SKILL_NODE(22062, 56, node56)
    }
    if (noInit == true) {
        return node56;
    }
    return node56;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(22062, 57) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 62, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 53, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(22062, 57) {
    auto node57 = GET_SKILL_NODE(57, PhaseNode_CreateTriggerNewPene);
    if (node57 == nullptr) {
        node57 = new PhaseNode_CreateTriggerNewPene(57, phase);
        node57->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::Tick);
        node57->setTypeParams(0, .00f);
        node57->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node57->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Enemy);
        node57->setOnHero(true);
        node57->setOnMinion(true);
        node57->setOnDestruct(false);
        node57->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(22062, 57, node57)
    }
    if (noInit == true) {
        return node57;
    }
    auto node21 = GET_SKILL_NODE(21, PhaseNode_SpawnCollider);
    if (node21 != nullptr) node57->setColliderID(node21->getColliderID());
    return node57;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(22062, 58) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_If::TRIGGER_FALSE, 59, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_If::TRIGGER_TRUE, 56, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(22062, 58) {
    auto node58 = GET_SKILL_NODE(58, PhaseNode_If);
    if (node58 == nullptr) {
        node58 = new PhaseNode_If(58, phase);
        node58->setCondition(true);
        CALL_REGISTER_SKILL_NODE(22062, 58, node58)
    }
    if (noInit == true) {
        return node58;
    }
    return node58;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(22062, 59) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 61, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_LESS, 60, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
}

REGISTER_CREATE_SKILL_NODE(22062, 59) {
    auto node59 = GET_SKILL_NODE(59, PhaseNode_CompareFloat);
    if (node59 == nullptr) {
        node59 = new PhaseNode_CompareFloat(59, phase);
        node59->setA(.00f);
        node59->setB(.00f);
        CALL_REGISTER_SKILL_NODE(22062, 59, node59)
    }
    if (noInit == true) {
        return node59;
    }
    return node59;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(22062, 60) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 64, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 66, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(22062, 60) {
    auto node60 = GET_SKILL_NODE(60, PhaseNode_CreateTriggerNewPene);
    if (node60 == nullptr) {
        node60 = new PhaseNode_CreateTriggerNewPene(60, phase);
        node60->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::Tick);
        node60->setTypeParams(0, .00f);
        node60->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node60->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Friend);
        node60->setOnHero(true);
        node60->setOnMinion(true);
        node60->setOnDestruct(false);
        node60->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(22062, 60, node60)
    }
    if (noInit == true) {
        return node60;
    }
    auto node21 = GET_SKILL_NODE(21, PhaseNode_SpawnCollider);
    if (node21 != nullptr) node60->setColliderID(node21->getColliderID());
    return node60;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(22062, 61) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 52, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 67, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(22062, 61) {
    auto node61 = GET_SKILL_NODE(61, PhaseNode_CreateTriggerNewPene);
    if (node61 == nullptr) {
        node61 = new PhaseNode_CreateTriggerNewPene(61, phase);
        node61->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::In);
        node61->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node61->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Friend);
        node61->setOnHero(true);
        node61->setOnMinion(true);
        node61->setOnDestruct(false);
        node61->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(22062, 61, node61)
    }
    if (noInit == true) {
        return node61;
    }
    auto node21 = GET_SKILL_NODE(21, PhaseNode_SpawnCollider);
    if (node21 != nullptr) node61->setColliderID(node21->getColliderID());
    return node61;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(22062, 62) {
}

REGISTER_CREATE_SKILL_NODE(22062, 62) {
    auto node62 = GET_SKILL_NODE(62, PhaseNode_TriggerCheck);
    if (node62 == nullptr) {
        node62 = new PhaseNode_TriggerCheck(62, phase);
        auto node4 = GET_SKILL_NODE(4, PhaseNode_TriggerUpdate);
        if (node4 != nullptr) node4->addTriggerCheck(node62);
        
        CALL_REGISTER_SKILL_NODE(22062, 62, node62)
    }
    if (noInit == true) {
        return node62;
    }
    auto node57 = GET_SKILL_NODE(57, PhaseNode_CreateTriggerNewPene);
    if (node57 != nullptr) node62->setTrigger(0, node57->getTriggerID());
    return node62;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(22062, 63) {
}

REGISTER_CREATE_SKILL_NODE(22062, 63) {
    auto node63 = GET_SKILL_NODE(63, PhaseNode_TriggerCheck);
    if (node63 == nullptr) {
        node63 = new PhaseNode_TriggerCheck(63, phase);
        auto node4 = GET_SKILL_NODE(4, PhaseNode_TriggerUpdate);
        if (node4 != nullptr) node4->addTriggerCheck(node63);
        
        CALL_REGISTER_SKILL_NODE(22062, 63, node63)
    }
    if (noInit == true) {
        return node63;
    }
    auto node51 = GET_SKILL_NODE(51, PhaseNode_CreateTriggerNewPene);
    if (node51 != nullptr) node63->setTrigger(0, node51->getTriggerID());
    return node63;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(22062, 64) {
}

REGISTER_CREATE_SKILL_NODE(22062, 64) {
    auto node64 = GET_SKILL_NODE(64, PhaseNode_TriggerCheck);
    if (node64 == nullptr) {
        node64 = new PhaseNode_TriggerCheck(64, phase);
        auto node4 = GET_SKILL_NODE(4, PhaseNode_TriggerUpdate);
        if (node4 != nullptr) node4->addTriggerCheck(node64);
        
        CALL_REGISTER_SKILL_NODE(22062, 64, node64)
    }
    if (noInit == true) {
        return node64;
    }
    auto node60 = GET_SKILL_NODE(60, PhaseNode_CreateTriggerNewPene);
    if (node60 != nullptr) node64->setTrigger(0, node60->getTriggerID());
    return node64;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(22062, 65) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 54, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(22062, 65) {
    auto node65 = GET_SKILL_NODE(65, PhaseNode_ActorFilterNewPene);
    if (node65 == nullptr) {
        node65 = new PhaseNode_ActorFilterNewPene(65, phase);
        node65->setHero(true);
        node65->setMinion(true);
        node65->setDestruct(false);
        node65->setShield(false);
        node65->setTotalCount(0);
        node65->setPerCount(1);
        CALL_REGISTER_SKILL_NODE(22062, 65, node65)
    }
    if (noInit == true) {
        return node65;
    }
    auto node51 = GET_SKILL_NODE(51, PhaseNode_CreateTriggerNewPene);
    if (node51 != nullptr) node65->setInput(node51->getOther());
    return node65;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(22062, 66) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 54, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(22062, 66) {
    auto node66 = GET_SKILL_NODE(66, PhaseNode_ActorFilterNewPene);
    if (node66 == nullptr) {
        node66 = new PhaseNode_ActorFilterNewPene(66, phase);
        node66->setHero(true);
        node66->setMinion(true);
        node66->setDestruct(false);
        node66->setShield(false);
        node66->setTotalCount(0);
        node66->setPerCount(1);
        CALL_REGISTER_SKILL_NODE(22062, 66, node66)
    }
    if (noInit == true) {
        return node66;
    }
    auto node60 = GET_SKILL_NODE(60, PhaseNode_CreateTriggerNewPene);
    if (node60 != nullptr) node66->setInput(node60->getOther());
    return node66;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(22062, 67) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 54, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(22062, 67) {
    auto node67 = GET_SKILL_NODE(67, PhaseNode_ActorFilterNewPene);
    if (node67 == nullptr) {
        node67 = new PhaseNode_ActorFilterNewPene(67, phase);
        node67->setHero(true);
        node67->setMinion(true);
        node67->setDestruct(false);
        node67->setShield(false);
        node67->setTotalCount(0);
        node67->setPerCount(1);
        CALL_REGISTER_SKILL_NODE(22062, 67, node67)
    }
    if (noInit == true) {
        return node67;
    }
    auto node61 = GET_SKILL_NODE(61, PhaseNode_CreateTriggerNewPene);
    if (node61 != nullptr) node67->setInput(node61->getOther());
    return node67;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(22062, 68) {
}

REGISTER_CREATE_SKILL_NODE(22062, 68) {
    auto node68 = GET_SKILL_NODE(68, PhaseNode_AddSkillBuffs);
    if (node68 == nullptr) {
        node68 = new PhaseNode_AddSkillBuffs(68, phase);
        node68->setConfigID({13});
        CALL_REGISTER_SKILL_NODE(22062, 68, node68)
    }
    if (noInit == true) {
        return node68;
    }
    auto node65 = GET_SKILL_NODE(65, PhaseNode_ActorFilterNewPene);
    auto node54 = GET_SKILL_NODE(54, PhaseNode_GetActorAttribute);
    if (node65 != nullptr) node68->setTarget(node65->getOutput());
    if (node54 != nullptr) node68->setAttribute(node54->getAttribute());
    return node68;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(22062, 69) {
}

REGISTER_CREATE_SKILL_NODE(22062, 69) {
    auto node69 = GET_SKILL_NODE(69, PhaseNode_AddSkillBuffs);
    if (node69 == nullptr) {
        node69 = new PhaseNode_AddSkillBuffs(69, phase);
        node69->setConfigID({13});
        CALL_REGISTER_SKILL_NODE(22062, 69, node69)
    }
    if (noInit == true) {
        return node69;
    }
    auto node66 = GET_SKILL_NODE(66, PhaseNode_ActorFilterNewPene);
    auto node54 = GET_SKILL_NODE(54, PhaseNode_GetActorAttribute);
    if (node66 != nullptr) node69->setTarget(node66->getOutput());
    if (node54 != nullptr) node69->setAttribute(node54->getAttribute());
    return node69;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(22062, 70) {
}

REGISTER_CREATE_SKILL_NODE(22062, 70) {
    auto node70 = GET_SKILL_NODE(70, PhaseNode_AddSkillBuffs);
    if (node70 == nullptr) {
        node70 = new PhaseNode_AddSkillBuffs(70, phase);
        node70->setConfigID({13});
        CALL_REGISTER_SKILL_NODE(22062, 70, node70)
    }
    if (noInit == true) {
        return node70;
    }
    auto node67 = GET_SKILL_NODE(67, PhaseNode_ActorFilterNewPene);
    auto node54 = GET_SKILL_NODE(54, PhaseNode_GetActorAttribute);
    if (node67 != nullptr) node70->setTarget(node67->getOutput());
    if (node54 != nullptr) node70->setAttribute(node54->getAttribute());
    return node70;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(22062, 71) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_ResetCD::TRIGGER_DONE, 72, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(22062, 71) {
    auto node71 = GET_SKILL_NODE(71, PhaseNode_ResetCD);
    if (node71 == nullptr) {
        node71 = new PhaseNode_ResetCD(71, phase);
        node71->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node71->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node71->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(22062, 71, node71)
    }
    if (noInit == true) {
        return node71;
    }
    return node71;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(22062, 72) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_PlayAnimation::TRIGGER_DONE, 73, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(22062, 72) {
    auto node72 = GET_SKILL_NODE(72, PhaseNode_PlayAnimation);
    if (node72 == nullptr) {
        node72 = new PhaseNode_PlayAnimation(72, phase);
        node72->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node72->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node72->setTarget(0U);
        node72->setAnimation("Skill2S1");
        node72->setParameter("");
        node72->setValue(false);
        CALL_REGISTER_SKILL_NODE(22062, 72, node72)
    }
    if (noInit == true) {
        return node72;
    }
    return node72;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(22062, 73) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlaySound::TRIGGER_DONE, 74, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(22062, 73) {
    auto node73 = GET_SKILL_NODE(73, PhaseNode_PlaySound);
    if (node73 == nullptr) {
        node73 = new PhaseNode_PlaySound(73, phase);
        node73->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node73->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node73->setSoundID("");
        node73->setTarget(0U);
        node73->setUsePos(false);
        node73->setPosX(.00f);
        node73->setPosY(.00f);
        node73->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(22062, 73, node73)
    }
    if (noInit == true) {
        return node73;
    }
    return node73;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22062, 74) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_Delay::TRIGGER_DONE, 75, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(22062, 74) {
    auto node74 = GET_SKILL_NODE(74, PhaseNode_Delay);
    if (node74 == nullptr) {
        node74 = new PhaseNode_Delay(74, phase);
        node74->setTime(1.00f);
        CALL_REGISTER_SKILL_NODE(22062, 74, node74)
    }
    if (noInit == true) {
        return node74;
    }
    return node74;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(22062, 75) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetRotation>(PhaseNode_GetLocation::TRIGGER_DONE, 76, PhaseNode_GetRotation::FUNC_DO, &PhaseNode_GetRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(22062, 75) {
    auto node75 = GET_SKILL_NODE(75, PhaseNode_GetLocation);
    if (node75 == nullptr) {
        node75 = new PhaseNode_GetLocation(75, phase);
        node75->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node75->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(22062, 75, node75)
    }
    if (noInit == true) {
        return node75;
    }
    return node75;
}
//--------------------------------------------------------------------------------
// GetRotation
//
REGISTER_REGISTER_SKILL_NODE(22062, 76) {
    pnode->resizeTrigger(PhaseNode_GetRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_OffsetCalculate>(PhaseNode_GetRotation::TRIGGER_DONE, 77, PhaseNode_OffsetCalculate::FUNC_DO, &PhaseNode_OffsetCalculate::Do);
}

REGISTER_CREATE_SKILL_NODE(22062, 76) {
    auto node76 = GET_SKILL_NODE(76, PhaseNode_GetRotation);
    if (node76 == nullptr) {
        node76 = new PhaseNode_GetRotation(76, phase);
        node76->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node76->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(22062, 76, node76)
    }
    if (noInit == true) {
        return node76;
    }
    return node76;
}
//--------------------------------------------------------------------------------
// OffsetCalculate
//
REGISTER_REGISTER_SKILL_NODE(22062, 77) {
    pnode->resizeTrigger(PhaseNode_OffsetCalculate::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 83, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(22062, 77) {
    auto node77 = GET_SKILL_NODE(77, PhaseNode_OffsetCalculate);
    if (node77 == nullptr) {
        node77 = new PhaseNode_OffsetCalculate(77, phase);
        node77->setPosZ(.00f);
        node77->setOffsetX(.00f);
        node77->setOffsetY(.00f);
        node77->setOffsetZ(.00f);
        node77->setRotOffset(.00f);
        CALL_REGISTER_SKILL_NODE(22062, 77, node77)
    }
    if (noInit == true) {
        return node77;
    }
    auto node75 = GET_SKILL_NODE(75, PhaseNode_GetLocation);
    auto node76 = GET_SKILL_NODE(76, PhaseNode_GetRotation);
    if (node75 != nullptr) node77->setPosX(node75->getX());
    if (node75 != nullptr) node77->setPosY(node75->getY());
    if (node76 != nullptr) node77->setRotation(node76->getAngle());
    return node77;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22062, 78) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_Delay::TRIGGER_DONE, 80, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(22062, 78) {
    auto node78 = GET_SKILL_NODE(78, PhaseNode_Delay);
    if (node78 == nullptr) {
        node78 = new PhaseNode_Delay(78, phase);
        node78->setTime(.70f);
        CALL_REGISTER_SKILL_NODE(22062, 78, node78)
    }
    if (noInit == true) {
        return node78;
    }
    return node78;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(22062, 79) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 36, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(22062, 79) {
    auto node79 = GET_SKILL_NODE(79, PhaseNode_SkillEndNotify);
    if (node79 == nullptr) {
        node79 = new PhaseNode_SkillEndNotify(79, phase);
        node79->setReturnType(false);
        CALL_REGISTER_SKILL_NODE(22062, 79, node79)
    }
    if (noInit == true) {
        return node79;
    }
    return node79;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(22062, 80) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_FALSE, 81, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_TRUE, 79, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
}

REGISTER_CREATE_SKILL_NODE(22062, 80) {
    auto node80 = GET_SKILL_NODE(80, PhaseNode_If);
    if (node80 == nullptr) {
        node80 = new PhaseNode_If(80, phase);
        node80->setCondition(false);
        CALL_REGISTER_SKILL_NODE(22062, 80, node80)
    }
    if (noInit == true) {
        return node80;
    }
    return node80;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(22062, 81) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 36, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(22062, 81) {
    auto node81 = GET_SKILL_NODE(81, PhaseNode_SkillEndNotify);
    if (node81 == nullptr) {
        node81 = new PhaseNode_SkillEndNotify(81, phase);
        node81->setReturnType(true);
        CALL_REGISTER_SKILL_NODE(22062, 81, node81)
    }
    if (noInit == true) {
        return node81;
    }
    return node81;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(22062, 82) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_PlayEffect::TRIGGER_DONE, 85, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(22062, 82) {
    auto node82 = GET_SKILL_NODE(82, PhaseNode_PlayEffect);
    if (node82 == nullptr) {
        node82 = new PhaseNode_PlayEffect(82, phase);
        node82->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node82->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node82->setEffectID(220722);
        node82->setChangeColor(false);
        node82->setType(PhaseNode_PlayEffect::PlayEffect_Type::WithTarget);
        node82->getVars().reserve(5);
        node82->getVars().setVariable<uint64_t>(0, 0U);
        node82->getVars().setVariable<std::string>(1, "");
        node82->getVars().setVariable<float>(2, .00f);
        node82->getVars().setVariable<float>(3, .00f);
        node82->getVars().setVariable<float>(4, .00f);
        node82->setScale(.00f);
        CALL_REGISTER_SKILL_NODE(22062, 82, node82)
    }
    if (noInit == true) {
        return node82;
    }
    auto node77 = GET_SKILL_NODE(77, PhaseNode_OffsetCalculate);
    if (node77 != nullptr) node82->getVars().setVariable<float>(2, node77->getOutPosX());
    if (node77 != nullptr) node82->getVars().setVariable<float>(3, node77->getOutPosY());
    if (node77 != nullptr) node82->getVars().setVariable<float>(4, node77->getOutPosZ());
    if (node77 != nullptr) node82->setRotation(node77->getOutRotation());
    return node82;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(22062, 83) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_FALSE, 84, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_TRUE, 82, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(22062, 83) {
    auto node83 = GET_SKILL_NODE(83, PhaseNode_If);
    if (node83 == nullptr) {
        node83 = new PhaseNode_If(83, phase);
        node83->setCondition(false);
        CALL_REGISTER_SKILL_NODE(22062, 83, node83)
    }
    if (noInit == true) {
        return node83;
    }
    return node83;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(22062, 84) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_PlayEffect::TRIGGER_DONE, 85, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(22062, 84) {
    auto node84 = GET_SKILL_NODE(84, PhaseNode_PlayEffect);
    if (node84 == nullptr) {
        node84 = new PhaseNode_PlayEffect(84, phase);
        node84->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node84->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node84->setEffectID(220722);
        node84->setChangeColor(false);
        node84->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node84->getVars().reserve(3);
        node84->getVars().setVariable<float>(0, .00f);
        node84->getVars().setVariable<float>(1, .00f);
        node84->getVars().setVariable<float>(2, .00f);
        node84->setScale(.00f);
        CALL_REGISTER_SKILL_NODE(22062, 84, node84)
    }
    if (noInit == true) {
        return node84;
    }
    auto node77 = GET_SKILL_NODE(77, PhaseNode_OffsetCalculate);
    if (node77 != nullptr) node84->getVars().setVariable<float>(0, node77->getOutPosX());
    if (node77 != nullptr) node84->getVars().setVariable<float>(1, node77->getOutPosY());
    if (node77 != nullptr) node84->getVars().setVariable<float>(2, node77->getOutPosZ());
    if (node77 != nullptr) node84->setRotation(node77->getOutRotation());
    return node84;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(22062, 85) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnCollider>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 21, PhaseNode_SpawnCollider::FUNC_DO, &PhaseNode_SpawnCollider::Do);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_LESS, 86, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_SpawnCollider>(PhaseNode_CompareFloat::TRIGGER_LESS, 21, PhaseNode_SpawnCollider::FUNC_DO, &PhaseNode_SpawnCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(22062, 85) {
    auto node85 = GET_SKILL_NODE(85, PhaseNode_CompareFloat);
    if (node85 == nullptr) {
        node85 = new PhaseNode_CompareFloat(85, phase);
        node85->setA(.00f);
        node85->setB(.00f);
        CALL_REGISTER_SKILL_NODE(22062, 85, node85)
    }
    if (noInit == true) {
        return node85;
    }
    return node85;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22062, 86) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StopEffect>(PhaseNode_Delay::TRIGGER_DONE, 87, PhaseNode_StopEffect::FUNC_DO, &PhaseNode_StopEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(22062, 86) {
    auto node86 = GET_SKILL_NODE(86, PhaseNode_Delay);
    if (node86 == nullptr) {
        node86 = new PhaseNode_Delay(86, phase);
        node86->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(22062, 86, node86)
    }
    if (noInit == true) {
        return node86;
    }
    return node86;
}
//--------------------------------------------------------------------------------
// StopEffect
//
REGISTER_REGISTER_SKILL_NODE(22062, 87) {
}

REGISTER_CREATE_SKILL_NODE(22062, 87) {
    auto node87 = GET_SKILL_NODE(87, PhaseNode_StopEffect);
    if (node87 == nullptr) {
        node87 = new PhaseNode_StopEffect(87, phase);
        node87->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node87->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node87->setEffectID(220722);
        CALL_REGISTER_SKILL_NODE(22062, 87, node87)
    }
    if (noInit == true) {
        return node87;
    }
    return node87;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(22062, 88) {
}

REGISTER_CREATE_SKILL_NODE(22062, 88) {
    auto node88 = GET_SKILL_NODE(88, PhaseNode_RaiseEvent);
    if (node88 == nullptr) {
        node88 = new PhaseNode_RaiseEvent(88, phase);
        node88->setEvent("MonsterInterrupt");
        node88->setTarget(0U);
        node88->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node88->setTypeParams(0, 0);
        node88->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(22062, 88, node88)
    }
    if (noInit == true) {
        return node88;
    }
    return node88;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(22062, 89) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_Detect::TRIGGER_ON, 94, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(22062, 89) {
    auto node89 = GET_SKILL_NODE(89, PhaseNode_Detect);
    if (node89 == nullptr) {
        node89 = new PhaseNode_Detect(89, phase);
        node89->setSelf(0U);
        node89->setEvent("MonsterInterrupt");
        node89->setType(PhaseNode_Detect::Detect_Type::Interrupt_Skill);
        node89->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(22062, 89, node89)
    }
    if (noInit == true) {
        return node89;
    }
    return node89;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(22062, 90) {
}

REGISTER_CREATE_SKILL_NODE(22062, 90) {
    auto node90 = GET_SKILL_NODE(90, PhaseNode_EndPhase);
    if (node90 == nullptr) {
        node90 = new PhaseNode_EndPhase(90, phase);
        node90->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node90->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(22062, 90, node90)
    }
    if (noInit == true) {
        return node90;
    }
    return node90;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22062, 92) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_Delay::TRIGGER_DONE, 93, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(22062, 92) {
    auto node92 = GET_SKILL_NODE(92, PhaseNode_Delay);
    if (node92 == nullptr) {
        node92 = new PhaseNode_Delay(92, phase);
        node92->setTime(.80f);
        CALL_REGISTER_SKILL_NODE(22062, 92, node92)
    }
    if (noInit == true) {
        return node92;
    }
    return node92;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(22062, 93) {
}

REGISTER_CREATE_SKILL_NODE(22062, 93) {
    auto node93 = GET_SKILL_NODE(93, PhaseNode_PlaySound);
    if (node93 == nullptr) {
        node93 = new PhaseNode_PlaySound(93, phase);
        node93->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node93->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node93->setSoundID("SE_MON2207_ATK_C");
        node93->setTarget(0U);
        node93->setUsePos(false);
        node93->setPosX(.00f);
        node93->setPosY(.00f);
        node93->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(22062, 93, node93)
    }
    if (noInit == true) {
        return node93;
    }
    return node93;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22062, 94) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_Delay::TRIGGER_DONE, 96, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(22062, 94) {
    auto node94 = GET_SKILL_NODE(94, PhaseNode_Delay);
    if (node94 == nullptr) {
        node94 = new PhaseNode_Delay(94, phase);
        node94->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(22062, 94, node94)
    }
    if (noInit == true) {
        return node94;
    }
    return node94;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(22062, 95) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 90, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(22062, 95) {
    auto node95 = GET_SKILL_NODE(95, PhaseNode_SkillEndNotify);
    if (node95 == nullptr) {
        node95 = new PhaseNode_SkillEndNotify(95, phase);
        node95->setReturnType(false);
        CALL_REGISTER_SKILL_NODE(22062, 95, node95)
    }
    if (noInit == true) {
        return node95;
    }
    return node95;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(22062, 96) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_FALSE, 97, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_TRUE, 95, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
}

REGISTER_CREATE_SKILL_NODE(22062, 96) {
    auto node96 = GET_SKILL_NODE(96, PhaseNode_If);
    if (node96 == nullptr) {
        node96 = new PhaseNode_If(96, phase);
        node96->setCondition(false);
        CALL_REGISTER_SKILL_NODE(22062, 96, node96)
    }
    if (noInit == true) {
        return node96;
    }
    return node96;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(22062, 97) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 90, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(22062, 97) {
    auto node97 = GET_SKILL_NODE(97, PhaseNode_SkillEndNotify);
    if (node97 == nullptr) {
        node97 = new PhaseNode_SkillEndNotify(97, phase);
        node97->setReturnType(true);
        CALL_REGISTER_SKILL_NODE(22062, 97, node97)
    }
    if (noInit == true) {
        return node97;
    }
    return node97;
}

//--------------------------------------------------------------------------------
// SkillCreator_22062
//
class SkillCreator_22062 : public SkillCreator {
public:
    SkillCreator_22062() {}
    virtual ~SkillCreator_22062() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_22062

//--------------------------------------------------------------------------------
// SkillPhase_22062
//
class SkillPhase_22062 : public SkillPhase {
public:
    SkillPhase_22062(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_22062() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(22062, 2) // StartPhase
        CASE_CREATE_SKILL_NODE(22062, 4) // TriggerUpdate
        CASE_CREATE_SKILL_NODE(22062, 21) // SpawnCollider
        CASE_CREATE_SKILL_NODE(22062, 36) // EndPhase
        CASE_CREATE_SKILL_NODE(22062, 51) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(22062, 52) // TriggerCheck
        CASE_CREATE_SKILL_NODE(22062, 53) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(22062, 54) // GetActorAttribute
        CASE_CREATE_SKILL_NODE(22062, 55) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(22062, 56) // CompareFloat
        CASE_CREATE_SKILL_NODE(22062, 57) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(22062, 58) // If
        CASE_CREATE_SKILL_NODE(22062, 59) // CompareFloat
        CASE_CREATE_SKILL_NODE(22062, 60) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(22062, 61) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(22062, 62) // TriggerCheck
        CASE_CREATE_SKILL_NODE(22062, 63) // TriggerCheck
        CASE_CREATE_SKILL_NODE(22062, 64) // TriggerCheck
        CASE_CREATE_SKILL_NODE(22062, 65) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(22062, 66) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(22062, 67) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(22062, 68) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(22062, 69) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(22062, 70) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(22062, 71) // ResetCD
        CASE_CREATE_SKILL_NODE(22062, 72) // PlayAnimation
        CASE_CREATE_SKILL_NODE(22062, 73) // PlaySound
        CASE_CREATE_SKILL_NODE(22062, 74) // Delay
        CASE_CREATE_SKILL_NODE(22062, 75) // GetLocation
        CASE_CREATE_SKILL_NODE(22062, 76) // GetRotation
        CASE_CREATE_SKILL_NODE(22062, 77) // OffsetCalculate
        CASE_CREATE_SKILL_NODE(22062, 78) // Delay
        CASE_CREATE_SKILL_NODE(22062, 79) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(22062, 80) // If
        CASE_CREATE_SKILL_NODE(22062, 81) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(22062, 82) // PlayEffect
        CASE_CREATE_SKILL_NODE(22062, 83) // If
        CASE_CREATE_SKILL_NODE(22062, 84) // PlayEffect
        CASE_CREATE_SKILL_NODE(22062, 85) // CompareFloat
        CASE_CREATE_SKILL_NODE(22062, 86) // Delay
        CASE_CREATE_SKILL_NODE(22062, 87) // StopEffect
        CASE_CREATE_SKILL_NODE(22062, 88) // RaiseEvent
        CASE_CREATE_SKILL_NODE(22062, 89) // Detect
        CASE_CREATE_SKILL_NODE(22062, 90) // EndPhase
        CASE_CREATE_SKILL_NODE(22062, 92) // Delay
        CASE_CREATE_SKILL_NODE(22062, 93) // PlaySound
        CASE_CREATE_SKILL_NODE(22062, 94) // Delay
        CASE_CREATE_SKILL_NODE(22062, 95) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(22062, 96) // If
        CASE_CREATE_SKILL_NODE(22062, 97) // SkillEndNotify
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_22062

SkillLogic* SkillCreator_22062::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //创建阶段phase
    auto phase = new SkillPhase_22062(1, logic, 3);
    //设置phase执行器
    phase->setRunPhaseNode(1, 2);
    phase->setRunPhaseNode(2, 4);
    phase->setDetectPhaseNode(3, 89);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_22062::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
