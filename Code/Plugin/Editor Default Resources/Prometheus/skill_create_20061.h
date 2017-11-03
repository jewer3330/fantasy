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
REGISTER_REGISTER_SKILL_NODE(20061, 1) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_StartPhase::TRIGGER_START, 140, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_StartPhase::TRIGGER_START, 120, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(20061, 1) {
    auto node1 = GET_SKILL_NODE(1, PhaseNode_StartPhase);
    if (node1 == nullptr) {
        node1 = new PhaseNode_StartPhase(1, phase);
        CALL_REGISTER_SKILL_NODE(20061, 1, node1)
    }
    if (noInit == true) {
        return node1;
    }
    return node1;
}
//--------------------------------------------------------------------------------
// TriggerUpdate
//
REGISTER_REGISTER_SKILL_NODE(20061, 4) {
}

REGISTER_CREATE_SKILL_NODE(20061, 4) {
    auto node4 = GET_SKILL_NODE(4, PhaseNode_TriggerUpdate);
    if (node4 == nullptr) {
        node4 = new PhaseNode_TriggerUpdate(4, phase);
        CALL_REGISTER_SKILL_NODE(20061, 4, node4)
    }
    if (noInit == true) {
        return node4;
    }
    return node4;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(20061, 5) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_Delay::TRIGGER_DONE, 74, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(20061, 5) {
    auto node5 = GET_SKILL_NODE(5, PhaseNode_Delay);
    if (node5 == nullptr) {
        node5 = new PhaseNode_Delay(5, phase);
        node5->setTime(1.00f);
        CALL_REGISTER_SKILL_NODE(20061, 5, node5)
    }
    if (noInit == true) {
        return node5;
    }
    return node5;
}
//--------------------------------------------------------------------------------
// SpawnCollider
//
REGISTER_REGISTER_SKILL_NODE(20061, 8) {
    pnode->resizeTrigger(PhaseNode_SpawnCollider::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_SpawnCollider::TRIGGER_DONE, 127, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_SpawnCollider::TRIGGER_DONE, 107, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(20061, 8) {
    auto node8 = GET_SKILL_NODE(8, PhaseNode_SpawnCollider);
    if (node8 == nullptr) {
        node8 = new PhaseNode_SpawnCollider(8, phase);
        node8->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node8->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node8->setMesh("");
        node8->setMeshScale(.00f);
        node8->setEffectID(0);
        node8->setEffectScale(.00f);
        node8->setType(PhaseNode_SpawnCollider::SpawnCollider_Type::Rect);
        node8->setTypeParams(0, 3.00f);
        node8->setTypeParams(1, 8.00f);
        node8->setTime(.30f);
        node8->setPosZ(.00f);
        node8->setreentry(false);
        node8->setCheckPeneSound(false);
        CALL_REGISTER_SKILL_NODE(20061, 8, node8)
    }
    if (noInit == true) {
        return node8;
    }
    auto node139 = GET_SKILL_NODE(139, PhaseNode_OffsetCalculate);
    if (node139 != nullptr) node8->setPosX(node139->getOutPosX());
    if (node139 != nullptr) node8->setPosY(node139->getOutPosY());
    if (node139 != nullptr) node8->setRotation(node139->getOutRotation());
    return node8;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(20061, 14) {
}

REGISTER_CREATE_SKILL_NODE(20061, 14) {
    auto node14 = GET_SKILL_NODE(14, PhaseNode_EndPhase);
    if (node14 == nullptr) {
        node14 = new PhaseNode_EndPhase(14, phase);
        node14->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node14->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(20061, 14, node14)
    }
    if (noInit == true) {
        return node14;
    }
    return node14;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(20061, 52) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_Detect::TRIGGER_ON, 53, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(20061, 52) {
    auto node52 = GET_SKILL_NODE(52, PhaseNode_Detect);
    if (node52 == nullptr) {
        node52 = new PhaseNode_Detect(52, phase);
        node52->setSelf(0U);
        node52->setEvent("");
        node52->setType(PhaseNode_Detect::Detect_Type::Actor_Dead);
        node52->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(20061, 52, node52)
    }
    if (noInit == true) {
        return node52;
    }
    return node52;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(20061, 53) {
}

REGISTER_CREATE_SKILL_NODE(20061, 53) {
    auto node53 = GET_SKILL_NODE(53, PhaseNode_EndPhase);
    if (node53 == nullptr) {
        node53 = new PhaseNode_EndPhase(53, phase);
        node53->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node53->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(20061, 53, node53)
    }
    if (noInit == true) {
        return node53;
    }
    return node53;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(20061, 74) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_PlaySound::TRIGGER_DONE, 132, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(20061, 74) {
    auto node74 = GET_SKILL_NODE(74, PhaseNode_PlaySound);
    if (node74 == nullptr) {
        node74 = new PhaseNode_PlaySound(74, phase);
        node74->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node74->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node74->setSoundID("SE_MON_LieShaZhe_ATK_A_P1");
        node74->setTarget(0U);
        node74->setUsePos(false);
        node74->setPosX(.00f);
        node74->setPosY(.00f);
        node74->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(20061, 74, node74)
    }
    if (noInit == true) {
        return node74;
    }
    return node74;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(20061, 100) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 112, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 114, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(20061, 100) {
    auto node100 = GET_SKILL_NODE(100, PhaseNode_CreateTriggerNewPene);
    if (node100 == nullptr) {
        node100 = new PhaseNode_CreateTriggerNewPene(100, phase);
        node100->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::In);
        node100->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node100->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Enemy);
        node100->setOnHero(true);
        node100->setOnMinion(true);
        node100->setOnDestruct(true);
        node100->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(20061, 100, node100)
    }
    if (noInit == true) {
        return node100;
    }
    auto node8 = GET_SKILL_NODE(8, PhaseNode_SpawnCollider);
    if (node8 != nullptr) node100->setColliderID(node8->getColliderID());
    return node100;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(20061, 101) {
}

REGISTER_CREATE_SKILL_NODE(20061, 101) {
    auto node101 = GET_SKILL_NODE(101, PhaseNode_TriggerCheck);
    if (node101 == nullptr) {
        node101 = new PhaseNode_TriggerCheck(101, phase);
        auto node4 = GET_SKILL_NODE(4, PhaseNode_TriggerUpdate);
        if (node4 != nullptr) node4->addTriggerCheck(node101);
        
        CALL_REGISTER_SKILL_NODE(20061, 101, node101)
    }
    if (noInit == true) {
        return node101;
    }
    auto node110 = GET_SKILL_NODE(110, PhaseNode_CreateTriggerNewPene);
    if (node110 != nullptr) node101->setTrigger(0, node110->getTriggerID());
    return node101;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(20061, 102) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 103, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(20061, 102) {
    auto node102 = GET_SKILL_NODE(102, PhaseNode_ActorFilterNewPene);
    if (node102 == nullptr) {
        node102 = new PhaseNode_ActorFilterNewPene(102, phase);
        node102->setHero(true);
        node102->setMinion(true);
        node102->setDestruct(true);
        node102->setShield(false);
        node102->setTotalCount(0);
        node102->setPerCount(1);
        CALL_REGISTER_SKILL_NODE(20061, 102, node102)
    }
    if (noInit == true) {
        return node102;
    }
    auto node106 = GET_SKILL_NODE(106, PhaseNode_CreateTriggerNewPene);
    if (node106 != nullptr) node102->setInput(node106->getOther());
    return node102;
}
//--------------------------------------------------------------------------------
// GetActorAttribute
//
REGISTER_REGISTER_SKILL_NODE(20061, 103) {
    pnode->resizeTrigger(PhaseNode_GetActorAttribute::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 104, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 117, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 118, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 119, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
}

REGISTER_CREATE_SKILL_NODE(20061, 103) {
    auto node103 = GET_SKILL_NODE(103, PhaseNode_GetActorAttribute);
    if (node103 == nullptr) {
        node103 = new PhaseNode_GetActorAttribute(103, phase);
        node103->setTarget(0U);
        node103->setType({202});
        CALL_REGISTER_SKILL_NODE(20061, 103, node103)
    }
    if (noInit == true) {
        return node103;
    }
    return node103;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(20061, 104) {
}

REGISTER_CREATE_SKILL_NODE(20061, 104) {
    auto node104 = GET_SKILL_NODE(104, PhaseNode_AddSkillBuffs);
    if (node104 == nullptr) {
        node104 = new PhaseNode_AddSkillBuffs(104, phase);
        node104->setConfigID({11});
        CALL_REGISTER_SKILL_NODE(20061, 104, node104)
    }
    if (noInit == true) {
        return node104;
    }
    auto node102 = GET_SKILL_NODE(102, PhaseNode_ActorFilterNewPene);
    auto node103 = GET_SKILL_NODE(103, PhaseNode_GetActorAttribute);
    if (node102 != nullptr) node104->setTarget(node102->getOutput());
    if (node103 != nullptr) node104->setAttribute(node103->getAttribute());
    return node104;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(20061, 105) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 100, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_LESS, 106, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
}

REGISTER_CREATE_SKILL_NODE(20061, 105) {
    auto node105 = GET_SKILL_NODE(105, PhaseNode_CompareFloat);
    if (node105 == nullptr) {
        node105 = new PhaseNode_CompareFloat(105, phase);
        node105->setA(.00f);
        node105->setB(.00f);
        CALL_REGISTER_SKILL_NODE(20061, 105, node105)
    }
    if (noInit == true) {
        return node105;
    }
    return node105;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(20061, 106) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 111, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 102, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(20061, 106) {
    auto node106 = GET_SKILL_NODE(106, PhaseNode_CreateTriggerNewPene);
    if (node106 == nullptr) {
        node106 = new PhaseNode_CreateTriggerNewPene(106, phase);
        node106->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::Tick);
        node106->setTypeParams(0, .00f);
        node106->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node106->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Enemy);
        node106->setOnHero(true);
        node106->setOnMinion(true);
        node106->setOnDestruct(true);
        node106->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(20061, 106, node106)
    }
    if (noInit == true) {
        return node106;
    }
    auto node8 = GET_SKILL_NODE(8, PhaseNode_SpawnCollider);
    if (node8 != nullptr) node106->setColliderID(node8->getColliderID());
    return node106;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(20061, 107) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_If::TRIGGER_FALSE, 108, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_If::TRIGGER_TRUE, 105, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(20061, 107) {
    auto node107 = GET_SKILL_NODE(107, PhaseNode_If);
    if (node107 == nullptr) {
        node107 = new PhaseNode_If(107, phase);
        node107->setCondition(true);
        CALL_REGISTER_SKILL_NODE(20061, 107, node107)
    }
    if (noInit == true) {
        return node107;
    }
    return node107;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(20061, 108) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 110, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_LESS, 109, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
}

REGISTER_CREATE_SKILL_NODE(20061, 108) {
    auto node108 = GET_SKILL_NODE(108, PhaseNode_CompareFloat);
    if (node108 == nullptr) {
        node108 = new PhaseNode_CompareFloat(108, phase);
        node108->setA(.00f);
        node108->setB(.00f);
        CALL_REGISTER_SKILL_NODE(20061, 108, node108)
    }
    if (noInit == true) {
        return node108;
    }
    return node108;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(20061, 109) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 113, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 115, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(20061, 109) {
    auto node109 = GET_SKILL_NODE(109, PhaseNode_CreateTriggerNewPene);
    if (node109 == nullptr) {
        node109 = new PhaseNode_CreateTriggerNewPene(109, phase);
        node109->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::Tick);
        node109->setTypeParams(0, .00f);
        node109->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node109->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Friend);
        node109->setOnHero(true);
        node109->setOnMinion(true);
        node109->setOnDestruct(true);
        node109->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(20061, 109, node109)
    }
    if (noInit == true) {
        return node109;
    }
    auto node8 = GET_SKILL_NODE(8, PhaseNode_SpawnCollider);
    if (node8 != nullptr) node109->setColliderID(node8->getColliderID());
    return node109;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(20061, 110) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 101, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 116, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(20061, 110) {
    auto node110 = GET_SKILL_NODE(110, PhaseNode_CreateTriggerNewPene);
    if (node110 == nullptr) {
        node110 = new PhaseNode_CreateTriggerNewPene(110, phase);
        node110->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::In);
        node110->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node110->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Friend);
        node110->setOnHero(true);
        node110->setOnMinion(true);
        node110->setOnDestruct(true);
        node110->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(20061, 110, node110)
    }
    if (noInit == true) {
        return node110;
    }
    auto node8 = GET_SKILL_NODE(8, PhaseNode_SpawnCollider);
    if (node8 != nullptr) node110->setColliderID(node8->getColliderID());
    return node110;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(20061, 111) {
}

REGISTER_CREATE_SKILL_NODE(20061, 111) {
    auto node111 = GET_SKILL_NODE(111, PhaseNode_TriggerCheck);
    if (node111 == nullptr) {
        node111 = new PhaseNode_TriggerCheck(111, phase);
        auto node4 = GET_SKILL_NODE(4, PhaseNode_TriggerUpdate);
        if (node4 != nullptr) node4->addTriggerCheck(node111);
        
        CALL_REGISTER_SKILL_NODE(20061, 111, node111)
    }
    if (noInit == true) {
        return node111;
    }
    auto node106 = GET_SKILL_NODE(106, PhaseNode_CreateTriggerNewPene);
    if (node106 != nullptr) node111->setTrigger(0, node106->getTriggerID());
    return node111;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(20061, 112) {
}

REGISTER_CREATE_SKILL_NODE(20061, 112) {
    auto node112 = GET_SKILL_NODE(112, PhaseNode_TriggerCheck);
    if (node112 == nullptr) {
        node112 = new PhaseNode_TriggerCheck(112, phase);
        auto node4 = GET_SKILL_NODE(4, PhaseNode_TriggerUpdate);
        if (node4 != nullptr) node4->addTriggerCheck(node112);
        
        CALL_REGISTER_SKILL_NODE(20061, 112, node112)
    }
    if (noInit == true) {
        return node112;
    }
    auto node100 = GET_SKILL_NODE(100, PhaseNode_CreateTriggerNewPene);
    if (node100 != nullptr) node112->setTrigger(0, node100->getTriggerID());
    return node112;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(20061, 113) {
}

REGISTER_CREATE_SKILL_NODE(20061, 113) {
    auto node113 = GET_SKILL_NODE(113, PhaseNode_TriggerCheck);
    if (node113 == nullptr) {
        node113 = new PhaseNode_TriggerCheck(113, phase);
        auto node4 = GET_SKILL_NODE(4, PhaseNode_TriggerUpdate);
        if (node4 != nullptr) node4->addTriggerCheck(node113);
        
        CALL_REGISTER_SKILL_NODE(20061, 113, node113)
    }
    if (noInit == true) {
        return node113;
    }
    auto node109 = GET_SKILL_NODE(109, PhaseNode_CreateTriggerNewPene);
    if (node109 != nullptr) node113->setTrigger(0, node109->getTriggerID());
    return node113;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(20061, 114) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 103, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(20061, 114) {
    auto node114 = GET_SKILL_NODE(114, PhaseNode_ActorFilterNewPene);
    if (node114 == nullptr) {
        node114 = new PhaseNode_ActorFilterNewPene(114, phase);
        node114->setHero(true);
        node114->setMinion(true);
        node114->setDestruct(true);
        node114->setShield(false);
        node114->setTotalCount(0);
        node114->setPerCount(1);
        CALL_REGISTER_SKILL_NODE(20061, 114, node114)
    }
    if (noInit == true) {
        return node114;
    }
    auto node100 = GET_SKILL_NODE(100, PhaseNode_CreateTriggerNewPene);
    if (node100 != nullptr) node114->setInput(node100->getOther());
    return node114;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(20061, 115) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 103, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(20061, 115) {
    auto node115 = GET_SKILL_NODE(115, PhaseNode_ActorFilterNewPene);
    if (node115 == nullptr) {
        node115 = new PhaseNode_ActorFilterNewPene(115, phase);
        node115->setHero(true);
        node115->setMinion(true);
        node115->setDestruct(true);
        node115->setShield(false);
        node115->setTotalCount(0);
        node115->setPerCount(1);
        CALL_REGISTER_SKILL_NODE(20061, 115, node115)
    }
    if (noInit == true) {
        return node115;
    }
    auto node109 = GET_SKILL_NODE(109, PhaseNode_CreateTriggerNewPene);
    if (node109 != nullptr) node115->setInput(node109->getOther());
    return node115;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(20061, 116) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 103, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(20061, 116) {
    auto node116 = GET_SKILL_NODE(116, PhaseNode_ActorFilterNewPene);
    if (node116 == nullptr) {
        node116 = new PhaseNode_ActorFilterNewPene(116, phase);
        node116->setHero(true);
        node116->setMinion(true);
        node116->setDestruct(true);
        node116->setShield(false);
        node116->setTotalCount(0);
        node116->setPerCount(1);
        CALL_REGISTER_SKILL_NODE(20061, 116, node116)
    }
    if (noInit == true) {
        return node116;
    }
    auto node110 = GET_SKILL_NODE(110, PhaseNode_CreateTriggerNewPene);
    if (node110 != nullptr) node116->setInput(node110->getOther());
    return node116;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(20061, 117) {
}

REGISTER_CREATE_SKILL_NODE(20061, 117) {
    auto node117 = GET_SKILL_NODE(117, PhaseNode_AddSkillBuffs);
    if (node117 == nullptr) {
        node117 = new PhaseNode_AddSkillBuffs(117, phase);
        node117->setConfigID({11});
        CALL_REGISTER_SKILL_NODE(20061, 117, node117)
    }
    if (noInit == true) {
        return node117;
    }
    auto node114 = GET_SKILL_NODE(114, PhaseNode_ActorFilterNewPene);
    auto node103 = GET_SKILL_NODE(103, PhaseNode_GetActorAttribute);
    if (node114 != nullptr) node117->setTarget(node114->getOutput());
    if (node103 != nullptr) node117->setAttribute(node103->getAttribute());
    return node117;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(20061, 118) {
}

REGISTER_CREATE_SKILL_NODE(20061, 118) {
    auto node118 = GET_SKILL_NODE(118, PhaseNode_AddSkillBuffs);
    if (node118 == nullptr) {
        node118 = new PhaseNode_AddSkillBuffs(118, phase);
        node118->setConfigID({11});
        CALL_REGISTER_SKILL_NODE(20061, 118, node118)
    }
    if (noInit == true) {
        return node118;
    }
    auto node115 = GET_SKILL_NODE(115, PhaseNode_ActorFilterNewPene);
    auto node103 = GET_SKILL_NODE(103, PhaseNode_GetActorAttribute);
    if (node115 != nullptr) node118->setTarget(node115->getOutput());
    if (node103 != nullptr) node118->setAttribute(node103->getAttribute());
    return node118;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(20061, 119) {
}

REGISTER_CREATE_SKILL_NODE(20061, 119) {
    auto node119 = GET_SKILL_NODE(119, PhaseNode_AddSkillBuffs);
    if (node119 == nullptr) {
        node119 = new PhaseNode_AddSkillBuffs(119, phase);
        node119->setConfigID({11});
        CALL_REGISTER_SKILL_NODE(20061, 119, node119)
    }
    if (noInit == true) {
        return node119;
    }
    auto node116 = GET_SKILL_NODE(116, PhaseNode_ActorFilterNewPene);
    auto node103 = GET_SKILL_NODE(103, PhaseNode_GetActorAttribute);
    if (node116 != nullptr) node119->setTarget(node116->getOutput());
    if (node103 != nullptr) node119->setAttribute(node103->getAttribute());
    return node119;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(20061, 120) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_ResetCD::TRIGGER_DONE, 121, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(20061, 120) {
    auto node120 = GET_SKILL_NODE(120, PhaseNode_ResetCD);
    if (node120 == nullptr) {
        node120 = new PhaseNode_ResetCD(120, phase);
        node120->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node120->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node120->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(20061, 120, node120)
    }
    if (noInit == true) {
        return node120;
    }
    return node120;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(20061, 121) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_PlayAnimation::TRIGGER_DONE, 122, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(20061, 121) {
    auto node121 = GET_SKILL_NODE(121, PhaseNode_PlayAnimation);
    if (node121 == nullptr) {
        node121 = new PhaseNode_PlayAnimation(121, phase);
        node121->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node121->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node121->setTarget(0U);
        node121->setAnimation("Skill1S1");
        node121->setParameter("");
        node121->setValue(false);
        CALL_REGISTER_SKILL_NODE(20061, 121, node121)
    }
    if (noInit == true) {
        return node121;
    }
    return node121;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(20061, 122) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlaySound::TRIGGER_DONE, 123, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(20061, 122) {
    auto node122 = GET_SKILL_NODE(122, PhaseNode_PlaySound);
    if (node122 == nullptr) {
        node122 = new PhaseNode_PlaySound(122, phase);
        node122->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node122->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node122->setSoundID("SE_MON_LieShaZhe_ATK_A_P0");
        node122->setTarget(0U);
        node122->setUsePos(false);
        node122->setPosX(.00f);
        node122->setPosY(.00f);
        node122->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(20061, 122, node122)
    }
    if (noInit == true) {
        return node122;
    }
    return node122;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(20061, 123) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_Delay::TRIGGER_DONE, 124, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(20061, 123) {
    auto node123 = GET_SKILL_NODE(123, PhaseNode_Delay);
    if (node123 == nullptr) {
        node123 = new PhaseNode_Delay(123, phase);
        node123->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(20061, 123, node123)
    }
    if (noInit == true) {
        return node123;
    }
    return node123;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(20061, 124) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetRotation>(PhaseNode_GetLocation::TRIGGER_DONE, 125, PhaseNode_GetRotation::FUNC_DO, &PhaseNode_GetRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(20061, 124) {
    auto node124 = GET_SKILL_NODE(124, PhaseNode_GetLocation);
    if (node124 == nullptr) {
        node124 = new PhaseNode_GetLocation(124, phase);
        node124->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node124->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(20061, 124, node124)
    }
    if (noInit == true) {
        return node124;
    }
    return node124;
}
//--------------------------------------------------------------------------------
// GetRotation
//
REGISTER_REGISTER_SKILL_NODE(20061, 125) {
    pnode->resizeTrigger(PhaseNode_GetRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_OffsetCalculate>(PhaseNode_GetRotation::TRIGGER_DONE, 126, PhaseNode_OffsetCalculate::FUNC_DO, &PhaseNode_OffsetCalculate::Do);
}

REGISTER_CREATE_SKILL_NODE(20061, 125) {
    auto node125 = GET_SKILL_NODE(125, PhaseNode_GetRotation);
    if (node125 == nullptr) {
        node125 = new PhaseNode_GetRotation(125, phase);
        node125->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node125->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(20061, 125, node125)
    }
    if (noInit == true) {
        return node125;
    }
    return node125;
}
//--------------------------------------------------------------------------------
// OffsetCalculate
//
REGISTER_REGISTER_SKILL_NODE(20061, 126) {
    pnode->resizeTrigger(PhaseNode_OffsetCalculate::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 137, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(20061, 126) {
    auto node126 = GET_SKILL_NODE(126, PhaseNode_OffsetCalculate);
    if (node126 == nullptr) {
        node126 = new PhaseNode_OffsetCalculate(126, phase);
        node126->setPosZ(.00f);
        node126->setOffsetX(.00f);
        node126->setOffsetY(1.50f);
        node126->setOffsetZ(.00f);
        node126->setRotOffset(.00f);
        CALL_REGISTER_SKILL_NODE(20061, 126, node126)
    }
    if (noInit == true) {
        return node126;
    }
    auto node124 = GET_SKILL_NODE(124, PhaseNode_GetLocation);
    auto node125 = GET_SKILL_NODE(125, PhaseNode_GetRotation);
    if (node124 != nullptr) node126->setPosX(node124->getX());
    if (node124 != nullptr) node126->setPosY(node124->getY());
    if (node125 != nullptr) node126->setRotation(node125->getAngle());
    return node126;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(20061, 127) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_Delay::TRIGGER_DONE, 129, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(20061, 127) {
    auto node127 = GET_SKILL_NODE(127, PhaseNode_Delay);
    if (node127 == nullptr) {
        node127 = new PhaseNode_Delay(127, phase);
        node127->setTime(.30f);
        CALL_REGISTER_SKILL_NODE(20061, 127, node127)
    }
    if (noInit == true) {
        return node127;
    }
    return node127;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(20061, 128) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 14, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(20061, 128) {
    auto node128 = GET_SKILL_NODE(128, PhaseNode_SkillEndNotify);
    if (node128 == nullptr) {
        node128 = new PhaseNode_SkillEndNotify(128, phase);
        node128->setReturnType(false);
        CALL_REGISTER_SKILL_NODE(20061, 128, node128)
    }
    if (noInit == true) {
        return node128;
    }
    return node128;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(20061, 129) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_FALSE, 130, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_TRUE, 128, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
}

REGISTER_CREATE_SKILL_NODE(20061, 129) {
    auto node129 = GET_SKILL_NODE(129, PhaseNode_If);
    if (node129 == nullptr) {
        node129 = new PhaseNode_If(129, phase);
        node129->setCondition(false);
        CALL_REGISTER_SKILL_NODE(20061, 129, node129)
    }
    if (noInit == true) {
        return node129;
    }
    return node129;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(20061, 130) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 14, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(20061, 130) {
    auto node130 = GET_SKILL_NODE(130, PhaseNode_SkillEndNotify);
    if (node130 == nullptr) {
        node130 = new PhaseNode_SkillEndNotify(130, phase);
        node130->setReturnType(true);
        CALL_REGISTER_SKILL_NODE(20061, 130, node130)
    }
    if (noInit == true) {
        return node130;
    }
    return node130;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(20061, 131) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_PlayEffect::TRIGGER_DONE, 134, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(20061, 131) {
    auto node131 = GET_SKILL_NODE(131, PhaseNode_PlayEffect);
    if (node131 == nullptr) {
        node131 = new PhaseNode_PlayEffect(131, phase);
        node131->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node131->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node131->setEffectID(1015);
        node131->setChangeColor(false);
        node131->setType(PhaseNode_PlayEffect::PlayEffect_Type::WithTarget);
        node131->getVars().reserve(5);
        node131->getVars().setVariable<uint64_t>(0, 0U);
        node131->getVars().setVariable<std::string>(1, "");
        node131->getVars().setVariable<float>(2, .00f);
        node131->getVars().setVariable<float>(3, .00f);
        node131->getVars().setVariable<float>(4, .00f);
        node131->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(20061, 131, node131)
    }
    if (noInit == true) {
        return node131;
    }
    auto node126 = GET_SKILL_NODE(126, PhaseNode_OffsetCalculate);
    if (node126 != nullptr) node131->getVars().setVariable<float>(2, node126->getOutPosX());
    if (node126 != nullptr) node131->getVars().setVariable<float>(3, node126->getOutPosY());
    if (node126 != nullptr) node131->getVars().setVariable<float>(4, node126->getOutPosZ());
    if (node126 != nullptr) node131->setRotation(node126->getOutRotation());
    return node131;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(20061, 132) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_FALSE, 133, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_TRUE, 131, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(20061, 132) {
    auto node132 = GET_SKILL_NODE(132, PhaseNode_If);
    if (node132 == nullptr) {
        node132 = new PhaseNode_If(132, phase);
        node132->setCondition(false);
        CALL_REGISTER_SKILL_NODE(20061, 132, node132)
    }
    if (noInit == true) {
        return node132;
    }
    return node132;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(20061, 133) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_PlayEffect::TRIGGER_DONE, 134, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(20061, 133) {
    auto node133 = GET_SKILL_NODE(133, PhaseNode_PlayEffect);
    if (node133 == nullptr) {
        node133 = new PhaseNode_PlayEffect(133, phase);
        node133->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node133->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node133->setEffectID(1015);
        node133->setChangeColor(false);
        node133->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node133->getVars().reserve(3);
        node133->getVars().setVariable<float>(0, .00f);
        node133->getVars().setVariable<float>(1, .00f);
        node133->getVars().setVariable<float>(2, .00f);
        node133->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(20061, 133, node133)
    }
    if (noInit == true) {
        return node133;
    }
    auto node126 = GET_SKILL_NODE(126, PhaseNode_OffsetCalculate);
    if (node126 != nullptr) node133->getVars().setVariable<float>(0, node126->getOutPosX());
    if (node126 != nullptr) node133->getVars().setVariable<float>(1, node126->getOutPosY());
    if (node126 != nullptr) node133->getVars().setVariable<float>(2, node126->getOutPosZ());
    if (node126 != nullptr) node133->setRotation(node126->getOutRotation());
    return node133;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(20061, 134) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnCollider>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 8, PhaseNode_SpawnCollider::FUNC_DO, &PhaseNode_SpawnCollider::Do);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_LESS, 135, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_SpawnCollider>(PhaseNode_CompareFloat::TRIGGER_LESS, 8, PhaseNode_SpawnCollider::FUNC_DO, &PhaseNode_SpawnCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(20061, 134) {
    auto node134 = GET_SKILL_NODE(134, PhaseNode_CompareFloat);
    if (node134 == nullptr) {
        node134 = new PhaseNode_CompareFloat(134, phase);
        node134->setA(.00f);
        node134->setB(.00f);
        CALL_REGISTER_SKILL_NODE(20061, 134, node134)
    }
    if (noInit == true) {
        return node134;
    }
    return node134;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(20061, 135) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StopEffect>(PhaseNode_Delay::TRIGGER_DONE, 136, PhaseNode_StopEffect::FUNC_DO, &PhaseNode_StopEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(20061, 135) {
    auto node135 = GET_SKILL_NODE(135, PhaseNode_Delay);
    if (node135 == nullptr) {
        node135 = new PhaseNode_Delay(135, phase);
        node135->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(20061, 135, node135)
    }
    if (noInit == true) {
        return node135;
    }
    return node135;
}
//--------------------------------------------------------------------------------
// StopEffect
//
REGISTER_REGISTER_SKILL_NODE(20061, 136) {
}

REGISTER_CREATE_SKILL_NODE(20061, 136) {
    auto node136 = GET_SKILL_NODE(136, PhaseNode_StopEffect);
    if (node136 == nullptr) {
        node136 = new PhaseNode_StopEffect(136, phase);
        node136->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node136->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node136->setEffectID(1015);
        CALL_REGISTER_SKILL_NODE(20061, 136, node136)
    }
    if (noInit == true) {
        return node136;
    }
    return node136;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(20061, 137) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetRotation>(PhaseNode_GetLocation::TRIGGER_DONE, 138, PhaseNode_GetRotation::FUNC_DO, &PhaseNode_GetRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(20061, 137) {
    auto node137 = GET_SKILL_NODE(137, PhaseNode_GetLocation);
    if (node137 == nullptr) {
        node137 = new PhaseNode_GetLocation(137, phase);
        node137->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node137->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(20061, 137, node137)
    }
    if (noInit == true) {
        return node137;
    }
    return node137;
}
//--------------------------------------------------------------------------------
// GetRotation
//
REGISTER_REGISTER_SKILL_NODE(20061, 138) {
    pnode->resizeTrigger(PhaseNode_GetRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_OffsetCalculate>(PhaseNode_GetRotation::TRIGGER_DONE, 139, PhaseNode_OffsetCalculate::FUNC_DO, &PhaseNode_OffsetCalculate::Do);
}

REGISTER_CREATE_SKILL_NODE(20061, 138) {
    auto node138 = GET_SKILL_NODE(138, PhaseNode_GetRotation);
    if (node138 == nullptr) {
        node138 = new PhaseNode_GetRotation(138, phase);
        node138->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node138->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(20061, 138, node138)
    }
    if (noInit == true) {
        return node138;
    }
    return node138;
}
//--------------------------------------------------------------------------------
// OffsetCalculate
//
REGISTER_REGISTER_SKILL_NODE(20061, 139) {
    pnode->resizeTrigger(PhaseNode_OffsetCalculate::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 5, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(20061, 139) {
    auto node139 = GET_SKILL_NODE(139, PhaseNode_OffsetCalculate);
    if (node139 == nullptr) {
        node139 = new PhaseNode_OffsetCalculate(139, phase);
        node139->setPosZ(.00f);
        node139->setOffsetX(.00f);
        node139->setOffsetY(5.50f);
        node139->setOffsetZ(.00f);
        node139->setRotOffset(.00f);
        CALL_REGISTER_SKILL_NODE(20061, 139, node139)
    }
    if (noInit == true) {
        return node139;
    }
    auto node137 = GET_SKILL_NODE(137, PhaseNode_GetLocation);
    auto node138 = GET_SKILL_NODE(138, PhaseNode_GetRotation);
    if (node137 != nullptr) node139->setPosX(node137->getX());
    if (node137 != nullptr) node139->setPosY(node137->getY());
    if (node138 != nullptr) node139->setRotation(node138->getAngle());
    return node139;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(20061, 140) {
}

REGISTER_CREATE_SKILL_NODE(20061, 140) {
    auto node140 = GET_SKILL_NODE(140, PhaseNode_RaiseEvent);
    if (node140 == nullptr) {
        node140 = new PhaseNode_RaiseEvent(140, phase);
        node140->setEvent("MonsterInterrupt");
        node140->setTarget(0U);
        node140->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node140->setTypeParams(0, 0);
        node140->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(20061, 140, node140)
    }
    if (noInit == true) {
        return node140;
    }
    return node140;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(20061, 141) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_Detect::TRIGGER_ON, 144, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(20061, 141) {
    auto node141 = GET_SKILL_NODE(141, PhaseNode_Detect);
    if (node141 == nullptr) {
        node141 = new PhaseNode_Detect(141, phase);
        node141->setSelf(0U);
        node141->setEvent("MonsterInterrupt");
        node141->setType(PhaseNode_Detect::Detect_Type::Interrupt_Skill);
        node141->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(20061, 141, node141)
    }
    if (noInit == true) {
        return node141;
    }
    return node141;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(20061, 142) {
}

REGISTER_CREATE_SKILL_NODE(20061, 142) {
    auto node142 = GET_SKILL_NODE(142, PhaseNode_EndPhase);
    if (node142 == nullptr) {
        node142 = new PhaseNode_EndPhase(142, phase);
        node142->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node142->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(20061, 142, node142)
    }
    if (noInit == true) {
        return node142;
    }
    return node142;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(20061, 144) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_Delay::TRIGGER_DONE, 146, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(20061, 144) {
    auto node144 = GET_SKILL_NODE(144, PhaseNode_Delay);
    if (node144 == nullptr) {
        node144 = new PhaseNode_Delay(144, phase);
        node144->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(20061, 144, node144)
    }
    if (noInit == true) {
        return node144;
    }
    return node144;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(20061, 145) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 142, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(20061, 145) {
    auto node145 = GET_SKILL_NODE(145, PhaseNode_SkillEndNotify);
    if (node145 == nullptr) {
        node145 = new PhaseNode_SkillEndNotify(145, phase);
        node145->setReturnType(false);
        CALL_REGISTER_SKILL_NODE(20061, 145, node145)
    }
    if (noInit == true) {
        return node145;
    }
    return node145;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(20061, 146) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_FALSE, 147, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_TRUE, 145, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
}

REGISTER_CREATE_SKILL_NODE(20061, 146) {
    auto node146 = GET_SKILL_NODE(146, PhaseNode_If);
    if (node146 == nullptr) {
        node146 = new PhaseNode_If(146, phase);
        node146->setCondition(false);
        CALL_REGISTER_SKILL_NODE(20061, 146, node146)
    }
    if (noInit == true) {
        return node146;
    }
    return node146;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(20061, 147) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 142, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(20061, 147) {
    auto node147 = GET_SKILL_NODE(147, PhaseNode_SkillEndNotify);
    if (node147 == nullptr) {
        node147 = new PhaseNode_SkillEndNotify(147, phase);
        node147->setReturnType(true);
        CALL_REGISTER_SKILL_NODE(20061, 147, node147)
    }
    if (noInit == true) {
        return node147;
    }
    return node147;
}

//--------------------------------------------------------------------------------
// SkillCreator_20061
//
class SkillCreator_20061 : public SkillCreator {
public:
    SkillCreator_20061() {}
    virtual ~SkillCreator_20061() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_20061

//--------------------------------------------------------------------------------
// SkillPhase_20061
//
class SkillPhase_20061 : public SkillPhase {
public:
    SkillPhase_20061(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_20061() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(20061, 1) // StartPhase
        CASE_CREATE_SKILL_NODE(20061, 4) // TriggerUpdate
        CASE_CREATE_SKILL_NODE(20061, 5) // Delay
        CASE_CREATE_SKILL_NODE(20061, 8) // SpawnCollider
        CASE_CREATE_SKILL_NODE(20061, 14) // EndPhase
        CASE_CREATE_SKILL_NODE(20061, 52) // Detect
        CASE_CREATE_SKILL_NODE(20061, 53) // EndPhase
        CASE_CREATE_SKILL_NODE(20061, 74) // PlaySound
        CASE_CREATE_SKILL_NODE(20061, 100) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(20061, 101) // TriggerCheck
        CASE_CREATE_SKILL_NODE(20061, 102) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(20061, 103) // GetActorAttribute
        CASE_CREATE_SKILL_NODE(20061, 104) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(20061, 105) // CompareFloat
        CASE_CREATE_SKILL_NODE(20061, 106) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(20061, 107) // If
        CASE_CREATE_SKILL_NODE(20061, 108) // CompareFloat
        CASE_CREATE_SKILL_NODE(20061, 109) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(20061, 110) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(20061, 111) // TriggerCheck
        CASE_CREATE_SKILL_NODE(20061, 112) // TriggerCheck
        CASE_CREATE_SKILL_NODE(20061, 113) // TriggerCheck
        CASE_CREATE_SKILL_NODE(20061, 114) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(20061, 115) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(20061, 116) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(20061, 117) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(20061, 118) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(20061, 119) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(20061, 120) // ResetCD
        CASE_CREATE_SKILL_NODE(20061, 121) // PlayAnimation
        CASE_CREATE_SKILL_NODE(20061, 122) // PlaySound
        CASE_CREATE_SKILL_NODE(20061, 123) // Delay
        CASE_CREATE_SKILL_NODE(20061, 124) // GetLocation
        CASE_CREATE_SKILL_NODE(20061, 125) // GetRotation
        CASE_CREATE_SKILL_NODE(20061, 126) // OffsetCalculate
        CASE_CREATE_SKILL_NODE(20061, 127) // Delay
        CASE_CREATE_SKILL_NODE(20061, 128) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(20061, 129) // If
        CASE_CREATE_SKILL_NODE(20061, 130) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(20061, 131) // PlayEffect
        CASE_CREATE_SKILL_NODE(20061, 132) // If
        CASE_CREATE_SKILL_NODE(20061, 133) // PlayEffect
        CASE_CREATE_SKILL_NODE(20061, 134) // CompareFloat
        CASE_CREATE_SKILL_NODE(20061, 135) // Delay
        CASE_CREATE_SKILL_NODE(20061, 136) // StopEffect
        CASE_CREATE_SKILL_NODE(20061, 137) // GetLocation
        CASE_CREATE_SKILL_NODE(20061, 138) // GetRotation
        CASE_CREATE_SKILL_NODE(20061, 139) // OffsetCalculate
        CASE_CREATE_SKILL_NODE(20061, 140) // RaiseEvent
        CASE_CREATE_SKILL_NODE(20061, 141) // Detect
        CASE_CREATE_SKILL_NODE(20061, 142) // EndPhase
        CASE_CREATE_SKILL_NODE(20061, 144) // Delay
        CASE_CREATE_SKILL_NODE(20061, 145) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(20061, 146) // If
        CASE_CREATE_SKILL_NODE(20061, 147) // SkillEndNotify
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_20061

SkillLogic* SkillCreator_20061::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //创建阶段phase
    auto phase = new SkillPhase_20061(1, logic, 3);
    //设置phase执行器
    phase->setRunPhaseNode(1, 1);
    phase->setRunPhaseNode(2, 4);
    phase->setDetectPhaseNode(3, 52);
    phase->setDetectPhaseNode(3, 141);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_20061::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
