#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

#include "skill_psnode_actorfilternewpene.h"
#include "skill_psnode_addskillbuffs.h"
#include "skill_psnode_comparefloat.h"
#include "skill_psnode_createtriggernewpene.h"
#include "skill_psnode_delay.h"
#include "skill_psnode_destroyactor.h"
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
#include "skill_psnode_resetcd.h"
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
REGISTER_REGISTER_SKILL_NODE(22091, 2) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_StartPhase::TRIGGER_START, 76, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_StartPhase::TRIGGER_START, 81, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(22091, 2) {
    auto node2 = GET_SKILL_NODE(2, PhaseNode_StartPhase);
    if (node2 == nullptr) {
        node2 = new PhaseNode_StartPhase(2, phase);
        CALL_REGISTER_SKILL_NODE(22091, 2, node2)
    }
    if (noInit == true) {
        return node2;
    }
    return node2;
}
//--------------------------------------------------------------------------------
// TriggerUpdate
//
REGISTER_REGISTER_SKILL_NODE(22091, 4) {
}

REGISTER_CREATE_SKILL_NODE(22091, 4) {
    auto node4 = GET_SKILL_NODE(4, PhaseNode_TriggerUpdate);
    if (node4 == nullptr) {
        node4 = new PhaseNode_TriggerUpdate(4, phase);
        CALL_REGISTER_SKILL_NODE(22091, 4, node4)
    }
    if (noInit == true) {
        return node4;
    }
    return node4;
}
//--------------------------------------------------------------------------------
// SpawnCollider
//
REGISTER_REGISTER_SKILL_NODE(22091, 14) {
    pnode->resizeTrigger(PhaseNode_SpawnCollider::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_SpawnCollider::TRIGGER_DONE, 42, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_SpawnCollider::TRIGGER_DONE, 63, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(22091, 14) {
    auto node14 = GET_SKILL_NODE(14, PhaseNode_SpawnCollider);
    if (node14 == nullptr) {
        node14 = new PhaseNode_SpawnCollider(14, phase);
        node14->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node14->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node14->setMesh("");
        node14->setMeshScale(.00f);
        node14->setEffectID(0);
        node14->setEffectScale(.00f);
        node14->setType(PhaseNode_SpawnCollider::SpawnCollider_Type::Circle);
        node14->setTypeParams(0, 3.00f);
        node14->setTime(.20f);
        node14->setPosZ(.00f);
        node14->setRotation(.00f);
        node14->setreentry(false);
        node14->setCheckPeneSound(false);
        CALL_REGISTER_SKILL_NODE(22091, 14, node14)
    }
    if (noInit == true) {
        return node14;
    }
    auto node80 = GET_SKILL_NODE(80, PhaseNode_OffsetCalculate);
    if (node80 != nullptr) node14->setPosX(node80->getOutPosX());
    if (node80 != nullptr) node14->setPosY(node80->getOutPosY());
    return node14;
}
//--------------------------------------------------------------------------------
// DestroyActor
//
REGISTER_REGISTER_SKILL_NODE(22091, 33) {
    pnode->resizeTrigger(PhaseNode_DestroyActor::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_DestroyActor::TRIGGER_DONE, 35, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(22091, 33) {
    auto node33 = GET_SKILL_NODE(33, PhaseNode_DestroyActor);
    if (node33 == nullptr) {
        node33 = new PhaseNode_DestroyActor(33, phase);
        node33->setActorID(0U);
        CALL_REGISTER_SKILL_NODE(22091, 33, node33)
    }
    if (noInit == true) {
        return node33;
    }
    return node33;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(22091, 35) {
}

REGISTER_CREATE_SKILL_NODE(22091, 35) {
    auto node35 = GET_SKILL_NODE(35, PhaseNode_EndPhase);
    if (node35 == nullptr) {
        node35 = new PhaseNode_EndPhase(35, phase);
        node35->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node35->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(22091, 35, node35)
    }
    if (noInit == true) {
        return node35;
    }
    return node35;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(22091, 38) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_Detect::TRIGGER_ON, 40, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(22091, 38) {
    auto node38 = GET_SKILL_NODE(38, PhaseNode_Detect);
    if (node38 == nullptr) {
        node38 = new PhaseNode_Detect(38, phase);
        node38->setSelf(0U);
        node38->setEvent("");
        node38->setType(PhaseNode_Detect::Detect_Type::Actor_Dead);
        node38->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(22091, 38, node38)
    }
    if (noInit == true) {
        return node38;
    }
    return node38;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(22091, 40) {
}

REGISTER_CREATE_SKILL_NODE(22091, 40) {
    auto node40 = GET_SKILL_NODE(40, PhaseNode_EndPhase);
    if (node40 == nullptr) {
        node40 = new PhaseNode_EndPhase(40, phase);
        node40->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node40->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(22091, 40, node40)
    }
    if (noInit == true) {
        return node40;
    }
    return node40;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22091, 42) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_DestroyActor>(PhaseNode_Delay::TRIGGER_DONE, 33, PhaseNode_DestroyActor::FUNC_DO, &PhaseNode_DestroyActor::Do);
}

REGISTER_CREATE_SKILL_NODE(22091, 42) {
    auto node42 = GET_SKILL_NODE(42, PhaseNode_Delay);
    if (node42 == nullptr) {
        node42 = new PhaseNode_Delay(42, phase);
        node42->setTime(.10f);
        CALL_REGISTER_SKILL_NODE(22091, 42, node42)
    }
    if (noInit == true) {
        return node42;
    }
    return node42;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(22091, 56) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 68, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 70, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(22091, 56) {
    auto node56 = GET_SKILL_NODE(56, PhaseNode_CreateTriggerNewPene);
    if (node56 == nullptr) {
        node56 = new PhaseNode_CreateTriggerNewPene(56, phase);
        node56->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::In);
        node56->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node56->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Enemy);
        node56->setOnHero(true);
        node56->setOnMinion(true);
        node56->setOnDestruct(true);
        node56->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(22091, 56, node56)
    }
    if (noInit == true) {
        return node56;
    }
    auto node14 = GET_SKILL_NODE(14, PhaseNode_SpawnCollider);
    if (node14 != nullptr) node56->setColliderID(node14->getColliderID());
    return node56;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(22091, 57) {
}

REGISTER_CREATE_SKILL_NODE(22091, 57) {
    auto node57 = GET_SKILL_NODE(57, PhaseNode_TriggerCheck);
    if (node57 == nullptr) {
        node57 = new PhaseNode_TriggerCheck(57, phase);
        auto node4 = GET_SKILL_NODE(4, PhaseNode_TriggerUpdate);
        if (node4 != nullptr) node4->addTriggerCheck(node57);
        
        CALL_REGISTER_SKILL_NODE(22091, 57, node57)
    }
    if (noInit == true) {
        return node57;
    }
    auto node66 = GET_SKILL_NODE(66, PhaseNode_CreateTriggerNewPene);
    if (node66 != nullptr) node57->setTrigger(0, node66->getTriggerID());
    return node57;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(22091, 58) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 59, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(22091, 58) {
    auto node58 = GET_SKILL_NODE(58, PhaseNode_ActorFilterNewPene);
    if (node58 == nullptr) {
        node58 = new PhaseNode_ActorFilterNewPene(58, phase);
        node58->setHero(true);
        node58->setMinion(true);
        node58->setDestruct(true);
        node58->setShield(false);
        node58->setTotalCount(0);
        node58->setPerCount(1);
        CALL_REGISTER_SKILL_NODE(22091, 58, node58)
    }
    if (noInit == true) {
        return node58;
    }
    auto node62 = GET_SKILL_NODE(62, PhaseNode_CreateTriggerNewPene);
    if (node62 != nullptr) node58->setInput(node62->getOther());
    return node58;
}
//--------------------------------------------------------------------------------
// GetActorAttribute
//
REGISTER_REGISTER_SKILL_NODE(22091, 59) {
    pnode->resizeTrigger(PhaseNode_GetActorAttribute::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 60, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 73, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 74, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 75, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
}

REGISTER_CREATE_SKILL_NODE(22091, 59) {
    auto node59 = GET_SKILL_NODE(59, PhaseNode_GetActorAttribute);
    if (node59 == nullptr) {
        node59 = new PhaseNode_GetActorAttribute(59, phase);
        node59->setTarget(0U);
        node59->setType({202});
        CALL_REGISTER_SKILL_NODE(22091, 59, node59)
    }
    if (noInit == true) {
        return node59;
    }
    return node59;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(22091, 60) {
}

REGISTER_CREATE_SKILL_NODE(22091, 60) {
    auto node60 = GET_SKILL_NODE(60, PhaseNode_AddSkillBuffs);
    if (node60 == nullptr) {
        node60 = new PhaseNode_AddSkillBuffs(60, phase);
        node60->setConfigID({11});
        CALL_REGISTER_SKILL_NODE(22091, 60, node60)
    }
    if (noInit == true) {
        return node60;
    }
    auto node58 = GET_SKILL_NODE(58, PhaseNode_ActorFilterNewPene);
    auto node59 = GET_SKILL_NODE(59, PhaseNode_GetActorAttribute);
    if (node58 != nullptr) node60->setTarget(node58->getOutput());
    if (node59 != nullptr) node60->setAttribute(node59->getAttribute());
    return node60;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(22091, 61) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 56, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_LESS, 62, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
}

REGISTER_CREATE_SKILL_NODE(22091, 61) {
    auto node61 = GET_SKILL_NODE(61, PhaseNode_CompareFloat);
    if (node61 == nullptr) {
        node61 = new PhaseNode_CompareFloat(61, phase);
        node61->setA(.00f);
        node61->setB(.00f);
        CALL_REGISTER_SKILL_NODE(22091, 61, node61)
    }
    if (noInit == true) {
        return node61;
    }
    return node61;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(22091, 62) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 67, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 58, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(22091, 62) {
    auto node62 = GET_SKILL_NODE(62, PhaseNode_CreateTriggerNewPene);
    if (node62 == nullptr) {
        node62 = new PhaseNode_CreateTriggerNewPene(62, phase);
        node62->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::Tick);
        node62->setTypeParams(0, .00f);
        node62->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node62->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Enemy);
        node62->setOnHero(true);
        node62->setOnMinion(true);
        node62->setOnDestruct(true);
        node62->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(22091, 62, node62)
    }
    if (noInit == true) {
        return node62;
    }
    auto node14 = GET_SKILL_NODE(14, PhaseNode_SpawnCollider);
    if (node14 != nullptr) node62->setColliderID(node14->getColliderID());
    return node62;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(22091, 63) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_If::TRIGGER_FALSE, 64, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_If::TRIGGER_TRUE, 61, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(22091, 63) {
    auto node63 = GET_SKILL_NODE(63, PhaseNode_If);
    if (node63 == nullptr) {
        node63 = new PhaseNode_If(63, phase);
        node63->setCondition(true);
        CALL_REGISTER_SKILL_NODE(22091, 63, node63)
    }
    if (noInit == true) {
        return node63;
    }
    return node63;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(22091, 64) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 66, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_LESS, 65, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
}

REGISTER_CREATE_SKILL_NODE(22091, 64) {
    auto node64 = GET_SKILL_NODE(64, PhaseNode_CompareFloat);
    if (node64 == nullptr) {
        node64 = new PhaseNode_CompareFloat(64, phase);
        node64->setA(.00f);
        node64->setB(.00f);
        CALL_REGISTER_SKILL_NODE(22091, 64, node64)
    }
    if (noInit == true) {
        return node64;
    }
    return node64;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(22091, 65) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 69, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 71, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(22091, 65) {
    auto node65 = GET_SKILL_NODE(65, PhaseNode_CreateTriggerNewPene);
    if (node65 == nullptr) {
        node65 = new PhaseNode_CreateTriggerNewPene(65, phase);
        node65->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::Tick);
        node65->setTypeParams(0, .00f);
        node65->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node65->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Friend);
        node65->setOnHero(true);
        node65->setOnMinion(true);
        node65->setOnDestruct(true);
        node65->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(22091, 65, node65)
    }
    if (noInit == true) {
        return node65;
    }
    auto node14 = GET_SKILL_NODE(14, PhaseNode_SpawnCollider);
    if (node14 != nullptr) node65->setColliderID(node14->getColliderID());
    return node65;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(22091, 66) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 57, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 72, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(22091, 66) {
    auto node66 = GET_SKILL_NODE(66, PhaseNode_CreateTriggerNewPene);
    if (node66 == nullptr) {
        node66 = new PhaseNode_CreateTriggerNewPene(66, phase);
        node66->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::In);
        node66->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node66->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Friend);
        node66->setOnHero(true);
        node66->setOnMinion(true);
        node66->setOnDestruct(true);
        node66->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(22091, 66, node66)
    }
    if (noInit == true) {
        return node66;
    }
    auto node14 = GET_SKILL_NODE(14, PhaseNode_SpawnCollider);
    if (node14 != nullptr) node66->setColliderID(node14->getColliderID());
    return node66;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(22091, 67) {
}

REGISTER_CREATE_SKILL_NODE(22091, 67) {
    auto node67 = GET_SKILL_NODE(67, PhaseNode_TriggerCheck);
    if (node67 == nullptr) {
        node67 = new PhaseNode_TriggerCheck(67, phase);
        auto node4 = GET_SKILL_NODE(4, PhaseNode_TriggerUpdate);
        if (node4 != nullptr) node4->addTriggerCheck(node67);
        
        CALL_REGISTER_SKILL_NODE(22091, 67, node67)
    }
    if (noInit == true) {
        return node67;
    }
    auto node62 = GET_SKILL_NODE(62, PhaseNode_CreateTriggerNewPene);
    if (node62 != nullptr) node67->setTrigger(0, node62->getTriggerID());
    return node67;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(22091, 68) {
}

REGISTER_CREATE_SKILL_NODE(22091, 68) {
    auto node68 = GET_SKILL_NODE(68, PhaseNode_TriggerCheck);
    if (node68 == nullptr) {
        node68 = new PhaseNode_TriggerCheck(68, phase);
        auto node4 = GET_SKILL_NODE(4, PhaseNode_TriggerUpdate);
        if (node4 != nullptr) node4->addTriggerCheck(node68);
        
        CALL_REGISTER_SKILL_NODE(22091, 68, node68)
    }
    if (noInit == true) {
        return node68;
    }
    auto node56 = GET_SKILL_NODE(56, PhaseNode_CreateTriggerNewPene);
    if (node56 != nullptr) node68->setTrigger(0, node56->getTriggerID());
    return node68;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(22091, 69) {
}

REGISTER_CREATE_SKILL_NODE(22091, 69) {
    auto node69 = GET_SKILL_NODE(69, PhaseNode_TriggerCheck);
    if (node69 == nullptr) {
        node69 = new PhaseNode_TriggerCheck(69, phase);
        auto node4 = GET_SKILL_NODE(4, PhaseNode_TriggerUpdate);
        if (node4 != nullptr) node4->addTriggerCheck(node69);
        
        CALL_REGISTER_SKILL_NODE(22091, 69, node69)
    }
    if (noInit == true) {
        return node69;
    }
    auto node65 = GET_SKILL_NODE(65, PhaseNode_CreateTriggerNewPene);
    if (node65 != nullptr) node69->setTrigger(0, node65->getTriggerID());
    return node69;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(22091, 70) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 59, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(22091, 70) {
    auto node70 = GET_SKILL_NODE(70, PhaseNode_ActorFilterNewPene);
    if (node70 == nullptr) {
        node70 = new PhaseNode_ActorFilterNewPene(70, phase);
        node70->setHero(true);
        node70->setMinion(true);
        node70->setDestruct(true);
        node70->setShield(false);
        node70->setTotalCount(0);
        node70->setPerCount(1);
        CALL_REGISTER_SKILL_NODE(22091, 70, node70)
    }
    if (noInit == true) {
        return node70;
    }
    auto node56 = GET_SKILL_NODE(56, PhaseNode_CreateTriggerNewPene);
    if (node56 != nullptr) node70->setInput(node56->getOther());
    return node70;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(22091, 71) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 59, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(22091, 71) {
    auto node71 = GET_SKILL_NODE(71, PhaseNode_ActorFilterNewPene);
    if (node71 == nullptr) {
        node71 = new PhaseNode_ActorFilterNewPene(71, phase);
        node71->setHero(true);
        node71->setMinion(true);
        node71->setDestruct(true);
        node71->setShield(false);
        node71->setTotalCount(0);
        node71->setPerCount(1);
        CALL_REGISTER_SKILL_NODE(22091, 71, node71)
    }
    if (noInit == true) {
        return node71;
    }
    auto node65 = GET_SKILL_NODE(65, PhaseNode_CreateTriggerNewPene);
    if (node65 != nullptr) node71->setInput(node65->getOther());
    return node71;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(22091, 72) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 59, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(22091, 72) {
    auto node72 = GET_SKILL_NODE(72, PhaseNode_ActorFilterNewPene);
    if (node72 == nullptr) {
        node72 = new PhaseNode_ActorFilterNewPene(72, phase);
        node72->setHero(true);
        node72->setMinion(true);
        node72->setDestruct(true);
        node72->setShield(false);
        node72->setTotalCount(0);
        node72->setPerCount(1);
        CALL_REGISTER_SKILL_NODE(22091, 72, node72)
    }
    if (noInit == true) {
        return node72;
    }
    auto node66 = GET_SKILL_NODE(66, PhaseNode_CreateTriggerNewPene);
    if (node66 != nullptr) node72->setInput(node66->getOther());
    return node72;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(22091, 73) {
}

REGISTER_CREATE_SKILL_NODE(22091, 73) {
    auto node73 = GET_SKILL_NODE(73, PhaseNode_AddSkillBuffs);
    if (node73 == nullptr) {
        node73 = new PhaseNode_AddSkillBuffs(73, phase);
        node73->setConfigID({11});
        CALL_REGISTER_SKILL_NODE(22091, 73, node73)
    }
    if (noInit == true) {
        return node73;
    }
    auto node70 = GET_SKILL_NODE(70, PhaseNode_ActorFilterNewPene);
    auto node59 = GET_SKILL_NODE(59, PhaseNode_GetActorAttribute);
    if (node70 != nullptr) node73->setTarget(node70->getOutput());
    if (node59 != nullptr) node73->setAttribute(node59->getAttribute());
    return node73;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(22091, 74) {
}

REGISTER_CREATE_SKILL_NODE(22091, 74) {
    auto node74 = GET_SKILL_NODE(74, PhaseNode_AddSkillBuffs);
    if (node74 == nullptr) {
        node74 = new PhaseNode_AddSkillBuffs(74, phase);
        node74->setConfigID({11});
        CALL_REGISTER_SKILL_NODE(22091, 74, node74)
    }
    if (noInit == true) {
        return node74;
    }
    auto node71 = GET_SKILL_NODE(71, PhaseNode_ActorFilterNewPene);
    auto node59 = GET_SKILL_NODE(59, PhaseNode_GetActorAttribute);
    if (node71 != nullptr) node74->setTarget(node71->getOutput());
    if (node59 != nullptr) node74->setAttribute(node59->getAttribute());
    return node74;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(22091, 75) {
}

REGISTER_CREATE_SKILL_NODE(22091, 75) {
    auto node75 = GET_SKILL_NODE(75, PhaseNode_AddSkillBuffs);
    if (node75 == nullptr) {
        node75 = new PhaseNode_AddSkillBuffs(75, phase);
        node75->setConfigID({11});
        CALL_REGISTER_SKILL_NODE(22091, 75, node75)
    }
    if (noInit == true) {
        return node75;
    }
    auto node72 = GET_SKILL_NODE(72, PhaseNode_ActorFilterNewPene);
    auto node59 = GET_SKILL_NODE(59, PhaseNode_GetActorAttribute);
    if (node72 != nullptr) node75->setTarget(node72->getOutput());
    if (node59 != nullptr) node75->setAttribute(node59->getAttribute());
    return node75;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22091, 76) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_Delay::TRIGGER_DONE, 77, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(22091, 76) {
    auto node76 = GET_SKILL_NODE(76, PhaseNode_Delay);
    if (node76 == nullptr) {
        node76 = new PhaseNode_Delay(76, phase);
        node76->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(22091, 76, node76)
    }
    if (noInit == true) {
        return node76;
    }
    return node76;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(22091, 77) {
}

REGISTER_CREATE_SKILL_NODE(22091, 77) {
    auto node77 = GET_SKILL_NODE(77, PhaseNode_PlaySound);
    if (node77 == nullptr) {
        node77 = new PhaseNode_PlaySound(77, phase);
        node77->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node77->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node77->setSoundID("  SE_MON2209_ATK");
        node77->setTarget(0U);
        node77->setUsePos(false);
        node77->setPosX(.00f);
        node77->setPosY(.00f);
        node77->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(22091, 77, node77)
    }
    if (noInit == true) {
        return node77;
    }
    return node77;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(22091, 78) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetRotation>(PhaseNode_GetLocation::TRIGGER_DONE, 79, PhaseNode_GetRotation::FUNC_DO, &PhaseNode_GetRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(22091, 78) {
    auto node78 = GET_SKILL_NODE(78, PhaseNode_GetLocation);
    if (node78 == nullptr) {
        node78 = new PhaseNode_GetLocation(78, phase);
        node78->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node78->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(22091, 78, node78)
    }
    if (noInit == true) {
        return node78;
    }
    return node78;
}
//--------------------------------------------------------------------------------
// GetRotation
//
REGISTER_REGISTER_SKILL_NODE(22091, 79) {
    pnode->resizeTrigger(PhaseNode_GetRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_OffsetCalculate>(PhaseNode_GetRotation::TRIGGER_DONE, 80, PhaseNode_OffsetCalculate::FUNC_DO, &PhaseNode_OffsetCalculate::Do);
}

REGISTER_CREATE_SKILL_NODE(22091, 79) {
    auto node79 = GET_SKILL_NODE(79, PhaseNode_GetRotation);
    if (node79 == nullptr) {
        node79 = new PhaseNode_GetRotation(79, phase);
        node79->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node79->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(22091, 79, node79)
    }
    if (noInit == true) {
        return node79;
    }
    return node79;
}
//--------------------------------------------------------------------------------
// OffsetCalculate
//
REGISTER_REGISTER_SKILL_NODE(22091, 80) {
    pnode->resizeTrigger(PhaseNode_OffsetCalculate::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 86, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(22091, 80) {
    auto node80 = GET_SKILL_NODE(80, PhaseNode_OffsetCalculate);
    if (node80 == nullptr) {
        node80 = new PhaseNode_OffsetCalculate(80, phase);
        node80->setPosZ(.00f);
        node80->setOffsetX(.00f);
        node80->setOffsetY(.00f);
        node80->setOffsetZ(.00f);
        node80->setRotOffset(.00f);
        CALL_REGISTER_SKILL_NODE(22091, 80, node80)
    }
    if (noInit == true) {
        return node80;
    }
    auto node78 = GET_SKILL_NODE(78, PhaseNode_GetLocation);
    auto node79 = GET_SKILL_NODE(79, PhaseNode_GetRotation);
    if (node78 != nullptr) node80->setPosX(node78->getX());
    if (node78 != nullptr) node80->setPosY(node78->getY());
    if (node79 != nullptr) node80->setRotation(node79->getAngle());
    return node80;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(22091, 81) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_ResetCD::TRIGGER_DONE, 82, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(22091, 81) {
    auto node81 = GET_SKILL_NODE(81, PhaseNode_ResetCD);
    if (node81 == nullptr) {
        node81 = new PhaseNode_ResetCD(81, phase);
        node81->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node81->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node81->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(22091, 81, node81)
    }
    if (noInit == true) {
        return node81;
    }
    return node81;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(22091, 82) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_PlayAnimation::TRIGGER_DONE, 83, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(22091, 82) {
    auto node82 = GET_SKILL_NODE(82, PhaseNode_PlayAnimation);
    if (node82 == nullptr) {
        node82 = new PhaseNode_PlayAnimation(82, phase);
        node82->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node82->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node82->setTarget(0U);
        node82->setAnimation("");
        node82->setParameter("");
        node82->setValue(false);
        CALL_REGISTER_SKILL_NODE(22091, 82, node82)
    }
    if (noInit == true) {
        return node82;
    }
    return node82;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(22091, 83) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlaySound::TRIGGER_DONE, 84, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(22091, 83) {
    auto node83 = GET_SKILL_NODE(83, PhaseNode_PlaySound);
    if (node83 == nullptr) {
        node83 = new PhaseNode_PlaySound(83, phase);
        node83->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node83->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node83->setSoundID("");
        node83->setTarget(0U);
        node83->setUsePos(false);
        node83->setPosX(.00f);
        node83->setPosY(.00f);
        node83->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(22091, 83, node83)
    }
    if (noInit == true) {
        return node83;
    }
    return node83;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22091, 84) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_Delay::TRIGGER_DONE, 78, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(22091, 84) {
    auto node84 = GET_SKILL_NODE(84, PhaseNode_Delay);
    if (node84 == nullptr) {
        node84 = new PhaseNode_Delay(84, phase);
        node84->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(22091, 84, node84)
    }
    if (noInit == true) {
        return node84;
    }
    return node84;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(22091, 85) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_PlayEffect::TRIGGER_DONE, 88, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(22091, 85) {
    auto node85 = GET_SKILL_NODE(85, PhaseNode_PlayEffect);
    if (node85 == nullptr) {
        node85 = new PhaseNode_PlayEffect(85, phase);
        node85->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node85->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node85->setEffectID(220911);
        node85->setChangeColor(false);
        node85->setType(PhaseNode_PlayEffect::PlayEffect_Type::WithTarget);
        node85->getVars().reserve(5);
        node85->getVars().setVariable<uint64_t>(0, 0U);
        node85->getVars().setVariable<std::string>(1, "");
        node85->getVars().setVariable<float>(2, .00f);
        node85->getVars().setVariable<float>(3, .00f);
        node85->getVars().setVariable<float>(4, .00f);
        node85->setRotation(.00f);
        node85->setScale(.00f);
        CALL_REGISTER_SKILL_NODE(22091, 85, node85)
    }
    if (noInit == true) {
        return node85;
    }
    auto node80 = GET_SKILL_NODE(80, PhaseNode_OffsetCalculate);
    if (node80 != nullptr) node85->getVars().setVariable<float>(2, node80->getOutPosX());
    if (node80 != nullptr) node85->getVars().setVariable<float>(3, node80->getOutPosY());
    return node85;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(22091, 86) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_FALSE, 87, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_TRUE, 85, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(22091, 86) {
    auto node86 = GET_SKILL_NODE(86, PhaseNode_If);
    if (node86 == nullptr) {
        node86 = new PhaseNode_If(86, phase);
        node86->setCondition(false);
        CALL_REGISTER_SKILL_NODE(22091, 86, node86)
    }
    if (noInit == true) {
        return node86;
    }
    return node86;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(22091, 87) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_PlayEffect::TRIGGER_DONE, 88, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(22091, 87) {
    auto node87 = GET_SKILL_NODE(87, PhaseNode_PlayEffect);
    if (node87 == nullptr) {
        node87 = new PhaseNode_PlayEffect(87, phase);
        node87->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node87->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node87->setEffectID(220911);
        node87->setChangeColor(false);
        node87->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node87->getVars().reserve(3);
        node87->getVars().setVariable<float>(0, .00f);
        node87->getVars().setVariable<float>(1, .00f);
        node87->getVars().setVariable<float>(2, .00f);
        node87->setRotation(.00f);
        node87->setScale(.00f);
        CALL_REGISTER_SKILL_NODE(22091, 87, node87)
    }
    if (noInit == true) {
        return node87;
    }
    auto node80 = GET_SKILL_NODE(80, PhaseNode_OffsetCalculate);
    if (node80 != nullptr) node87->getVars().setVariable<float>(0, node80->getOutPosX());
    if (node80 != nullptr) node87->getVars().setVariable<float>(1, node80->getOutPosY());
    return node87;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(22091, 88) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnCollider>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 14, PhaseNode_SpawnCollider::FUNC_DO, &PhaseNode_SpawnCollider::Do);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_LESS, 89, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_SpawnCollider>(PhaseNode_CompareFloat::TRIGGER_LESS, 14, PhaseNode_SpawnCollider::FUNC_DO, &PhaseNode_SpawnCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(22091, 88) {
    auto node88 = GET_SKILL_NODE(88, PhaseNode_CompareFloat);
    if (node88 == nullptr) {
        node88 = new PhaseNode_CompareFloat(88, phase);
        node88->setA(.00f);
        node88->setB(.00f);
        CALL_REGISTER_SKILL_NODE(22091, 88, node88)
    }
    if (noInit == true) {
        return node88;
    }
    return node88;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22091, 89) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StopEffect>(PhaseNode_Delay::TRIGGER_DONE, 90, PhaseNode_StopEffect::FUNC_DO, &PhaseNode_StopEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(22091, 89) {
    auto node89 = GET_SKILL_NODE(89, PhaseNode_Delay);
    if (node89 == nullptr) {
        node89 = new PhaseNode_Delay(89, phase);
        node89->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(22091, 89, node89)
    }
    if (noInit == true) {
        return node89;
    }
    return node89;
}
//--------------------------------------------------------------------------------
// StopEffect
//
REGISTER_REGISTER_SKILL_NODE(22091, 90) {
}

REGISTER_CREATE_SKILL_NODE(22091, 90) {
    auto node90 = GET_SKILL_NODE(90, PhaseNode_StopEffect);
    if (node90 == nullptr) {
        node90 = new PhaseNode_StopEffect(90, phase);
        node90->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node90->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node90->setEffectID(220911);
        CALL_REGISTER_SKILL_NODE(22091, 90, node90)
    }
    if (noInit == true) {
        return node90;
    }
    return node90;
}

//--------------------------------------------------------------------------------
// SkillCreator_22091
//
class SkillCreator_22091 : public SkillCreator {
public:
    SkillCreator_22091() {}
    virtual ~SkillCreator_22091() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_22091

//--------------------------------------------------------------------------------
// SkillPhase_22091
//
class SkillPhase_22091 : public SkillPhase {
public:
    SkillPhase_22091(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_22091() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(22091, 2) // StartPhase
        CASE_CREATE_SKILL_NODE(22091, 4) // TriggerUpdate
        CASE_CREATE_SKILL_NODE(22091, 14) // SpawnCollider
        CASE_CREATE_SKILL_NODE(22091, 33) // DestroyActor
        CASE_CREATE_SKILL_NODE(22091, 35) // EndPhase
        CASE_CREATE_SKILL_NODE(22091, 38) // Detect
        CASE_CREATE_SKILL_NODE(22091, 40) // EndPhase
        CASE_CREATE_SKILL_NODE(22091, 42) // Delay
        CASE_CREATE_SKILL_NODE(22091, 56) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(22091, 57) // TriggerCheck
        CASE_CREATE_SKILL_NODE(22091, 58) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(22091, 59) // GetActorAttribute
        CASE_CREATE_SKILL_NODE(22091, 60) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(22091, 61) // CompareFloat
        CASE_CREATE_SKILL_NODE(22091, 62) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(22091, 63) // If
        CASE_CREATE_SKILL_NODE(22091, 64) // CompareFloat
        CASE_CREATE_SKILL_NODE(22091, 65) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(22091, 66) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(22091, 67) // TriggerCheck
        CASE_CREATE_SKILL_NODE(22091, 68) // TriggerCheck
        CASE_CREATE_SKILL_NODE(22091, 69) // TriggerCheck
        CASE_CREATE_SKILL_NODE(22091, 70) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(22091, 71) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(22091, 72) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(22091, 73) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(22091, 74) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(22091, 75) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(22091, 76) // Delay
        CASE_CREATE_SKILL_NODE(22091, 77) // PlaySound
        CASE_CREATE_SKILL_NODE(22091, 78) // GetLocation
        CASE_CREATE_SKILL_NODE(22091, 79) // GetRotation
        CASE_CREATE_SKILL_NODE(22091, 80) // OffsetCalculate
        CASE_CREATE_SKILL_NODE(22091, 81) // ResetCD
        CASE_CREATE_SKILL_NODE(22091, 82) // PlayAnimation
        CASE_CREATE_SKILL_NODE(22091, 83) // PlaySound
        CASE_CREATE_SKILL_NODE(22091, 84) // Delay
        CASE_CREATE_SKILL_NODE(22091, 85) // PlayEffect
        CASE_CREATE_SKILL_NODE(22091, 86) // If
        CASE_CREATE_SKILL_NODE(22091, 87) // PlayEffect
        CASE_CREATE_SKILL_NODE(22091, 88) // CompareFloat
        CASE_CREATE_SKILL_NODE(22091, 89) // Delay
        CASE_CREATE_SKILL_NODE(22091, 90) // StopEffect
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_22091

SkillLogic* SkillCreator_22091::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //创建阶段phase
    auto phase = new SkillPhase_22091(1, logic, 3);
    //设置phase执行器
    phase->setRunPhaseNode(1, 2);
    phase->setRunPhaseNode(2, 4);
    phase->setDetectPhaseNode(3, 38);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_22091::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
