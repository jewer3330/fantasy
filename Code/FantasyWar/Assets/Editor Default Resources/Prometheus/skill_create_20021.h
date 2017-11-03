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
REGISTER_REGISTER_SKILL_NODE(20021, 2) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_StartPhase::TRIGGER_START, 131, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_StartPhase::TRIGGER_START, 115, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(20021, 2) {
    auto node2 = GET_SKILL_NODE(2, PhaseNode_StartPhase);
    if (node2 == nullptr) {
        node2 = new PhaseNode_StartPhase(2, phase);
        CALL_REGISTER_SKILL_NODE(20021, 2, node2)
    }
    if (noInit == true) {
        return node2;
    }
    return node2;
}
//--------------------------------------------------------------------------------
// TriggerUpdate
//
REGISTER_REGISTER_SKILL_NODE(20021, 5) {
}

REGISTER_CREATE_SKILL_NODE(20021, 5) {
    auto node5 = GET_SKILL_NODE(5, PhaseNode_TriggerUpdate);
    if (node5 == nullptr) {
        node5 = new PhaseNode_TriggerUpdate(5, phase);
        CALL_REGISTER_SKILL_NODE(20021, 5, node5)
    }
    if (noInit == true) {
        return node5;
    }
    return node5;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(20021, 14) {
}

REGISTER_CREATE_SKILL_NODE(20021, 14) {
    auto node14 = GET_SKILL_NODE(14, PhaseNode_EndPhase);
    if (node14 == nullptr) {
        node14 = new PhaseNode_EndPhase(14, phase);
        node14->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node14->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(20021, 14, node14)
    }
    if (noInit == true) {
        return node14;
    }
    return node14;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(20021, 78) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnCollider>(PhaseNode_PlaySound::TRIGGER_DONE, 79, PhaseNode_SpawnCollider::FUNC_DO, &PhaseNode_SpawnCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(20021, 78) {
    auto node78 = GET_SKILL_NODE(78, PhaseNode_PlaySound);
    if (node78 == nullptr) {
        node78 = new PhaseNode_PlaySound(78, phase);
        node78->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node78->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node78->setSoundID("");
        node78->setTarget(0U);
        node78->setUsePos(false);
        node78->setPosX(.00f);
        node78->setPosY(.00f);
        node78->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(20021, 78, node78)
    }
    if (noInit == true) {
        return node78;
    }
    return node78;
}
//--------------------------------------------------------------------------------
// SpawnCollider
//
REGISTER_REGISTER_SKILL_NODE(20021, 79) {
    pnode->resizeTrigger(PhaseNode_SpawnCollider::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_SpawnCollider::TRIGGER_DONE, 88, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_SpawnCollider::TRIGGER_DONE, 99, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(20021, 79) {
    auto node79 = GET_SKILL_NODE(79, PhaseNode_SpawnCollider);
    if (node79 == nullptr) {
        node79 = new PhaseNode_SpawnCollider(79, phase);
        node79->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node79->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node79->setMesh("");
        node79->setMeshScale(.00f);
        node79->setEffectID(0);
        node79->setEffectScale(.00f);
        node79->setType(PhaseNode_SpawnCollider::SpawnCollider_Type::Sector);
        node79->setTypeParams(0, 3.00f);
        node79->setTypeParams(1, 60.00f);
        node79->setTime(.30f);
        node79->setreentry(false);
        node79->setCheckPeneSound(false);
        CALL_REGISTER_SKILL_NODE(20021, 79, node79)
    }
    if (noInit == true) {
        return node79;
    }
    auto node114 = GET_SKILL_NODE(114, PhaseNode_OffsetCalculate);
    if (node114 != nullptr) node79->setPosX(node114->getOutPosX());
    if (node114 != nullptr) node79->setPosY(node114->getOutPosY());
    if (node114 != nullptr) node79->setPosZ(node114->getOutPosZ());
    if (node114 != nullptr) node79->setRotation(node114->getOutRotation());
    return node79;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(20021, 87) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_Delay::TRIGGER_DONE, 78, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(20021, 87) {
    auto node87 = GET_SKILL_NODE(87, PhaseNode_Delay);
    if (node87 == nullptr) {
        node87 = new PhaseNode_Delay(87, phase);
        node87->setTime(.20f);
        CALL_REGISTER_SKILL_NODE(20021, 87, node87)
    }
    if (noInit == true) {
        return node87;
    }
    return node87;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(20021, 88) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_Delay::TRIGGER_DONE, 90, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(20021, 88) {
    auto node88 = GET_SKILL_NODE(88, PhaseNode_Delay);
    if (node88 == nullptr) {
        node88 = new PhaseNode_Delay(88, phase);
        node88->setTime(.60f);
        CALL_REGISTER_SKILL_NODE(20021, 88, node88)
    }
    if (noInit == true) {
        return node88;
    }
    return node88;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(20021, 89) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 14, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(20021, 89) {
    auto node89 = GET_SKILL_NODE(89, PhaseNode_SkillEndNotify);
    if (node89 == nullptr) {
        node89 = new PhaseNode_SkillEndNotify(89, phase);
        node89->setReturnType(false);
        CALL_REGISTER_SKILL_NODE(20021, 89, node89)
    }
    if (noInit == true) {
        return node89;
    }
    return node89;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(20021, 90) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_FALSE, 91, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_TRUE, 89, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
}

REGISTER_CREATE_SKILL_NODE(20021, 90) {
    auto node90 = GET_SKILL_NODE(90, PhaseNode_If);
    if (node90 == nullptr) {
        node90 = new PhaseNode_If(90, phase);
        node90->setCondition(false);
        CALL_REGISTER_SKILL_NODE(20021, 90, node90)
    }
    if (noInit == true) {
        return node90;
    }
    return node90;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(20021, 91) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 14, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(20021, 91) {
    auto node91 = GET_SKILL_NODE(91, PhaseNode_SkillEndNotify);
    if (node91 == nullptr) {
        node91 = new PhaseNode_SkillEndNotify(91, phase);
        node91->setReturnType(true);
        CALL_REGISTER_SKILL_NODE(20021, 91, node91)
    }
    if (noInit == true) {
        return node91;
    }
    return node91;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(20021, 92) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 104, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 106, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(20021, 92) {
    auto node92 = GET_SKILL_NODE(92, PhaseNode_CreateTriggerNewPene);
    if (node92 == nullptr) {
        node92 = new PhaseNode_CreateTriggerNewPene(92, phase);
        node92->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::In);
        node92->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node92->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Enemy);
        node92->setOnHero(true);
        node92->setOnMinion(true);
        node92->setOnDestruct(true);
        node92->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(20021, 92, node92)
    }
    if (noInit == true) {
        return node92;
    }
    auto node79 = GET_SKILL_NODE(79, PhaseNode_SpawnCollider);
    if (node79 != nullptr) node92->setColliderID(node79->getColliderID());
    return node92;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(20021, 93) {
}

REGISTER_CREATE_SKILL_NODE(20021, 93) {
    auto node93 = GET_SKILL_NODE(93, PhaseNode_TriggerCheck);
    if (node93 == nullptr) {
        node93 = new PhaseNode_TriggerCheck(93, phase);
        auto node5 = GET_SKILL_NODE(5, PhaseNode_TriggerUpdate);
        if (node5 != nullptr) node5->addTriggerCheck(node93);
        
        CALL_REGISTER_SKILL_NODE(20021, 93, node93)
    }
    if (noInit == true) {
        return node93;
    }
    auto node102 = GET_SKILL_NODE(102, PhaseNode_CreateTriggerNewPene);
    if (node102 != nullptr) node93->setTrigger(0, node102->getTriggerID());
    return node93;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(20021, 94) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 95, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(20021, 94) {
    auto node94 = GET_SKILL_NODE(94, PhaseNode_ActorFilterNewPene);
    if (node94 == nullptr) {
        node94 = new PhaseNode_ActorFilterNewPene(94, phase);
        node94->setHero(true);
        node94->setMinion(true);
        node94->setDestruct(true);
        node94->setShield(false);
        node94->setTotalCount(0);
        node94->setPerCount(1);
        CALL_REGISTER_SKILL_NODE(20021, 94, node94)
    }
    if (noInit == true) {
        return node94;
    }
    auto node98 = GET_SKILL_NODE(98, PhaseNode_CreateTriggerNewPene);
    if (node98 != nullptr) node94->setInput(node98->getOther());
    return node94;
}
//--------------------------------------------------------------------------------
// GetActorAttribute
//
REGISTER_REGISTER_SKILL_NODE(20021, 95) {
    pnode->resizeTrigger(PhaseNode_GetActorAttribute::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 109, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 110, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 111, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 96, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
}

REGISTER_CREATE_SKILL_NODE(20021, 95) {
    auto node95 = GET_SKILL_NODE(95, PhaseNode_GetActorAttribute);
    if (node95 == nullptr) {
        node95 = new PhaseNode_GetActorAttribute(95, phase);
        node95->setTarget(0U);
        node95->setType({202});
        CALL_REGISTER_SKILL_NODE(20021, 95, node95)
    }
    if (noInit == true) {
        return node95;
    }
    return node95;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(20021, 96) {
}

REGISTER_CREATE_SKILL_NODE(20021, 96) {
    auto node96 = GET_SKILL_NODE(96, PhaseNode_AddSkillBuffs);
    if (node96 == nullptr) {
        node96 = new PhaseNode_AddSkillBuffs(96, phase);
        node96->setConfigID({11});
        CALL_REGISTER_SKILL_NODE(20021, 96, node96)
    }
    if (noInit == true) {
        return node96;
    }
    auto node94 = GET_SKILL_NODE(94, PhaseNode_ActorFilterNewPene);
    auto node95 = GET_SKILL_NODE(95, PhaseNode_GetActorAttribute);
    if (node94 != nullptr) node96->setTarget(node94->getOutput());
    if (node95 != nullptr) node96->setAttribute(node95->getAttribute());
    return node96;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(20021, 97) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 92, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_LESS, 98, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
}

REGISTER_CREATE_SKILL_NODE(20021, 97) {
    auto node97 = GET_SKILL_NODE(97, PhaseNode_CompareFloat);
    if (node97 == nullptr) {
        node97 = new PhaseNode_CompareFloat(97, phase);
        node97->setA(.00f);
        node97->setB(.00f);
        CALL_REGISTER_SKILL_NODE(20021, 97, node97)
    }
    if (noInit == true) {
        return node97;
    }
    return node97;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(20021, 98) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 103, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 94, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(20021, 98) {
    auto node98 = GET_SKILL_NODE(98, PhaseNode_CreateTriggerNewPene);
    if (node98 == nullptr) {
        node98 = new PhaseNode_CreateTriggerNewPene(98, phase);
        node98->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::Tick);
        node98->setTypeParams(0, .00f);
        node98->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node98->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Enemy);
        node98->setOnHero(true);
        node98->setOnMinion(true);
        node98->setOnDestruct(true);
        node98->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(20021, 98, node98)
    }
    if (noInit == true) {
        return node98;
    }
    auto node79 = GET_SKILL_NODE(79, PhaseNode_SpawnCollider);
    if (node79 != nullptr) node98->setColliderID(node79->getColliderID());
    return node98;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(20021, 99) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_If::TRIGGER_FALSE, 100, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_If::TRIGGER_TRUE, 97, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(20021, 99) {
    auto node99 = GET_SKILL_NODE(99, PhaseNode_If);
    if (node99 == nullptr) {
        node99 = new PhaseNode_If(99, phase);
        node99->setCondition(true);
        CALL_REGISTER_SKILL_NODE(20021, 99, node99)
    }
    if (noInit == true) {
        return node99;
    }
    return node99;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(20021, 100) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 102, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_LESS, 101, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
}

REGISTER_CREATE_SKILL_NODE(20021, 100) {
    auto node100 = GET_SKILL_NODE(100, PhaseNode_CompareFloat);
    if (node100 == nullptr) {
        node100 = new PhaseNode_CompareFloat(100, phase);
        node100->setA(.00f);
        node100->setB(.00f);
        CALL_REGISTER_SKILL_NODE(20021, 100, node100)
    }
    if (noInit == true) {
        return node100;
    }
    return node100;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(20021, 101) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 105, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 107, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(20021, 101) {
    auto node101 = GET_SKILL_NODE(101, PhaseNode_CreateTriggerNewPene);
    if (node101 == nullptr) {
        node101 = new PhaseNode_CreateTriggerNewPene(101, phase);
        node101->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::Tick);
        node101->setTypeParams(0, .00f);
        node101->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node101->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Friend);
        node101->setOnHero(true);
        node101->setOnMinion(true);
        node101->setOnDestruct(true);
        node101->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(20021, 101, node101)
    }
    if (noInit == true) {
        return node101;
    }
    auto node79 = GET_SKILL_NODE(79, PhaseNode_SpawnCollider);
    if (node79 != nullptr) node101->setColliderID(node79->getColliderID());
    return node101;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(20021, 102) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 93, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 108, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(20021, 102) {
    auto node102 = GET_SKILL_NODE(102, PhaseNode_CreateTriggerNewPene);
    if (node102 == nullptr) {
        node102 = new PhaseNode_CreateTriggerNewPene(102, phase);
        node102->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::In);
        node102->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node102->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Friend);
        node102->setOnHero(true);
        node102->setOnMinion(true);
        node102->setOnDestruct(true);
        node102->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(20021, 102, node102)
    }
    if (noInit == true) {
        return node102;
    }
    auto node79 = GET_SKILL_NODE(79, PhaseNode_SpawnCollider);
    if (node79 != nullptr) node102->setColliderID(node79->getColliderID());
    return node102;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(20021, 103) {
}

REGISTER_CREATE_SKILL_NODE(20021, 103) {
    auto node103 = GET_SKILL_NODE(103, PhaseNode_TriggerCheck);
    if (node103 == nullptr) {
        node103 = new PhaseNode_TriggerCheck(103, phase);
        auto node5 = GET_SKILL_NODE(5, PhaseNode_TriggerUpdate);
        if (node5 != nullptr) node5->addTriggerCheck(node103);
        
        CALL_REGISTER_SKILL_NODE(20021, 103, node103)
    }
    if (noInit == true) {
        return node103;
    }
    auto node98 = GET_SKILL_NODE(98, PhaseNode_CreateTriggerNewPene);
    if (node98 != nullptr) node103->setTrigger(0, node98->getTriggerID());
    return node103;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(20021, 104) {
}

REGISTER_CREATE_SKILL_NODE(20021, 104) {
    auto node104 = GET_SKILL_NODE(104, PhaseNode_TriggerCheck);
    if (node104 == nullptr) {
        node104 = new PhaseNode_TriggerCheck(104, phase);
        auto node5 = GET_SKILL_NODE(5, PhaseNode_TriggerUpdate);
        if (node5 != nullptr) node5->addTriggerCheck(node104);
        
        CALL_REGISTER_SKILL_NODE(20021, 104, node104)
    }
    if (noInit == true) {
        return node104;
    }
    auto node92 = GET_SKILL_NODE(92, PhaseNode_CreateTriggerNewPene);
    if (node92 != nullptr) node104->setTrigger(0, node92->getTriggerID());
    return node104;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(20021, 105) {
}

REGISTER_CREATE_SKILL_NODE(20021, 105) {
    auto node105 = GET_SKILL_NODE(105, PhaseNode_TriggerCheck);
    if (node105 == nullptr) {
        node105 = new PhaseNode_TriggerCheck(105, phase);
        auto node5 = GET_SKILL_NODE(5, PhaseNode_TriggerUpdate);
        if (node5 != nullptr) node5->addTriggerCheck(node105);
        
        CALL_REGISTER_SKILL_NODE(20021, 105, node105)
    }
    if (noInit == true) {
        return node105;
    }
    auto node101 = GET_SKILL_NODE(101, PhaseNode_CreateTriggerNewPene);
    if (node101 != nullptr) node105->setTrigger(0, node101->getTriggerID());
    return node105;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(20021, 106) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 95, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(20021, 106) {
    auto node106 = GET_SKILL_NODE(106, PhaseNode_ActorFilterNewPene);
    if (node106 == nullptr) {
        node106 = new PhaseNode_ActorFilterNewPene(106, phase);
        node106->setHero(true);
        node106->setMinion(true);
        node106->setDestruct(true);
        node106->setShield(false);
        node106->setTotalCount(0);
        node106->setPerCount(1);
        CALL_REGISTER_SKILL_NODE(20021, 106, node106)
    }
    if (noInit == true) {
        return node106;
    }
    auto node92 = GET_SKILL_NODE(92, PhaseNode_CreateTriggerNewPene);
    if (node92 != nullptr) node106->setInput(node92->getOther());
    return node106;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(20021, 107) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 95, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(20021, 107) {
    auto node107 = GET_SKILL_NODE(107, PhaseNode_ActorFilterNewPene);
    if (node107 == nullptr) {
        node107 = new PhaseNode_ActorFilterNewPene(107, phase);
        node107->setHero(true);
        node107->setMinion(true);
        node107->setDestruct(true);
        node107->setShield(false);
        node107->setTotalCount(0);
        node107->setPerCount(1);
        CALL_REGISTER_SKILL_NODE(20021, 107, node107)
    }
    if (noInit == true) {
        return node107;
    }
    auto node101 = GET_SKILL_NODE(101, PhaseNode_CreateTriggerNewPene);
    if (node101 != nullptr) node107->setInput(node101->getOther());
    return node107;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(20021, 108) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 95, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(20021, 108) {
    auto node108 = GET_SKILL_NODE(108, PhaseNode_ActorFilterNewPene);
    if (node108 == nullptr) {
        node108 = new PhaseNode_ActorFilterNewPene(108, phase);
        node108->setHero(true);
        node108->setMinion(true);
        node108->setDestruct(true);
        node108->setShield(false);
        node108->setTotalCount(0);
        node108->setPerCount(1);
        CALL_REGISTER_SKILL_NODE(20021, 108, node108)
    }
    if (noInit == true) {
        return node108;
    }
    auto node102 = GET_SKILL_NODE(102, PhaseNode_CreateTriggerNewPene);
    if (node102 != nullptr) node108->setInput(node102->getOther());
    return node108;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(20021, 109) {
}

REGISTER_CREATE_SKILL_NODE(20021, 109) {
    auto node109 = GET_SKILL_NODE(109, PhaseNode_AddSkillBuffs);
    if (node109 == nullptr) {
        node109 = new PhaseNode_AddSkillBuffs(109, phase);
        node109->setConfigID({11});
        CALL_REGISTER_SKILL_NODE(20021, 109, node109)
    }
    if (noInit == true) {
        return node109;
    }
    auto node106 = GET_SKILL_NODE(106, PhaseNode_ActorFilterNewPene);
    auto node95 = GET_SKILL_NODE(95, PhaseNode_GetActorAttribute);
    if (node106 != nullptr) node109->setTarget(node106->getOutput());
    if (node95 != nullptr) node109->setAttribute(node95->getAttribute());
    return node109;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(20021, 110) {
}

REGISTER_CREATE_SKILL_NODE(20021, 110) {
    auto node110 = GET_SKILL_NODE(110, PhaseNode_AddSkillBuffs);
    if (node110 == nullptr) {
        node110 = new PhaseNode_AddSkillBuffs(110, phase);
        node110->setConfigID({11});
        CALL_REGISTER_SKILL_NODE(20021, 110, node110)
    }
    if (noInit == true) {
        return node110;
    }
    auto node107 = GET_SKILL_NODE(107, PhaseNode_ActorFilterNewPene);
    auto node95 = GET_SKILL_NODE(95, PhaseNode_GetActorAttribute);
    if (node107 != nullptr) node110->setTarget(node107->getOutput());
    if (node95 != nullptr) node110->setAttribute(node95->getAttribute());
    return node110;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(20021, 111) {
}

REGISTER_CREATE_SKILL_NODE(20021, 111) {
    auto node111 = GET_SKILL_NODE(111, PhaseNode_AddSkillBuffs);
    if (node111 == nullptr) {
        node111 = new PhaseNode_AddSkillBuffs(111, phase);
        node111->setConfigID({11});
        CALL_REGISTER_SKILL_NODE(20021, 111, node111)
    }
    if (noInit == true) {
        return node111;
    }
    auto node108 = GET_SKILL_NODE(108, PhaseNode_ActorFilterNewPene);
    auto node95 = GET_SKILL_NODE(95, PhaseNode_GetActorAttribute);
    if (node108 != nullptr) node111->setTarget(node108->getOutput());
    if (node95 != nullptr) node111->setAttribute(node95->getAttribute());
    return node111;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(20021, 112) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetRotation>(PhaseNode_GetLocation::TRIGGER_DONE, 113, PhaseNode_GetRotation::FUNC_DO, &PhaseNode_GetRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(20021, 112) {
    auto node112 = GET_SKILL_NODE(112, PhaseNode_GetLocation);
    if (node112 == nullptr) {
        node112 = new PhaseNode_GetLocation(112, phase);
        node112->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node112->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(20021, 112, node112)
    }
    if (noInit == true) {
        return node112;
    }
    return node112;
}
//--------------------------------------------------------------------------------
// GetRotation
//
REGISTER_REGISTER_SKILL_NODE(20021, 113) {
    pnode->resizeTrigger(PhaseNode_GetRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_OffsetCalculate>(PhaseNode_GetRotation::TRIGGER_DONE, 114, PhaseNode_OffsetCalculate::FUNC_DO, &PhaseNode_OffsetCalculate::Do);
}

REGISTER_CREATE_SKILL_NODE(20021, 113) {
    auto node113 = GET_SKILL_NODE(113, PhaseNode_GetRotation);
    if (node113 == nullptr) {
        node113 = new PhaseNode_GetRotation(113, phase);
        node113->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node113->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(20021, 113, node113)
    }
    if (noInit == true) {
        return node113;
    }
    return node113;
}
//--------------------------------------------------------------------------------
// OffsetCalculate
//
REGISTER_REGISTER_SKILL_NODE(20021, 114) {
    pnode->resizeTrigger(PhaseNode_OffsetCalculate::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 120, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(20021, 114) {
    auto node114 = GET_SKILL_NODE(114, PhaseNode_OffsetCalculate);
    if (node114 == nullptr) {
        node114 = new PhaseNode_OffsetCalculate(114, phase);
        node114->setPosZ(.00f);
        node114->setOffsetX(.00f);
        node114->setOffsetY(.00f);
        node114->setOffsetZ(.00f);
        node114->setRotOffset(.00f);
        CALL_REGISTER_SKILL_NODE(20021, 114, node114)
    }
    if (noInit == true) {
        return node114;
    }
    auto node112 = GET_SKILL_NODE(112, PhaseNode_GetLocation);
    auto node113 = GET_SKILL_NODE(113, PhaseNode_GetRotation);
    if (node112 != nullptr) node114->setPosX(node112->getX());
    if (node112 != nullptr) node114->setPosY(node112->getY());
    if (node113 != nullptr) node114->setRotation(node113->getAngle());
    return node114;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(20021, 115) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_ResetCD::TRIGGER_DONE, 116, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(20021, 115) {
    auto node115 = GET_SKILL_NODE(115, PhaseNode_ResetCD);
    if (node115 == nullptr) {
        node115 = new PhaseNode_ResetCD(115, phase);
        node115->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node115->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node115->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(20021, 115, node115)
    }
    if (noInit == true) {
        return node115;
    }
    return node115;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(20021, 116) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_PlayAnimation::TRIGGER_DONE, 117, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(20021, 116) {
    auto node116 = GET_SKILL_NODE(116, PhaseNode_PlayAnimation);
    if (node116 == nullptr) {
        node116 = new PhaseNode_PlayAnimation(116, phase);
        node116->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node116->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node116->setTarget(0U);
        node116->setAnimation("Skill1S1");
        node116->setParameter("");
        node116->setValue(false);
        CALL_REGISTER_SKILL_NODE(20021, 116, node116)
    }
    if (noInit == true) {
        return node116;
    }
    return node116;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(20021, 117) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlaySound::TRIGGER_DONE, 118, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(20021, 117) {
    auto node117 = GET_SKILL_NODE(117, PhaseNode_PlaySound);
    if (node117 == nullptr) {
        node117 = new PhaseNode_PlaySound(117, phase);
        node117->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node117->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node117->setSoundID("SE_MON_Npc_Zerg_ATK");
        node117->setTarget(0U);
        node117->setUsePos(false);
        node117->setPosX(.00f);
        node117->setPosY(.00f);
        node117->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(20021, 117, node117)
    }
    if (noInit == true) {
        return node117;
    }
    return node117;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(20021, 118) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_Delay::TRIGGER_DONE, 112, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(20021, 118) {
    auto node118 = GET_SKILL_NODE(118, PhaseNode_Delay);
    if (node118 == nullptr) {
        node118 = new PhaseNode_Delay(118, phase);
        node118->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(20021, 118, node118)
    }
    if (noInit == true) {
        return node118;
    }
    return node118;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(20021, 119) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_PlayEffect::TRIGGER_DONE, 122, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(20021, 119) {
    auto node119 = GET_SKILL_NODE(119, PhaseNode_PlayEffect);
    if (node119 == nullptr) {
        node119 = new PhaseNode_PlayEffect(119, phase);
        node119->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node119->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node119->setEffectID(0);
        node119->setChangeColor(false);
        node119->setType(PhaseNode_PlayEffect::PlayEffect_Type::WithTarget);
        node119->getVars().reserve(5);
        node119->getVars().setVariable<uint64_t>(0, 0U);
        node119->getVars().setVariable<std::string>(1, "");
        node119->getVars().setVariable<float>(2, .00f);
        node119->getVars().setVariable<float>(3, .00f);
        node119->getVars().setVariable<float>(4, .00f);
        node119->setScale(.00f);
        CALL_REGISTER_SKILL_NODE(20021, 119, node119)
    }
    if (noInit == true) {
        return node119;
    }
    auto node114 = GET_SKILL_NODE(114, PhaseNode_OffsetCalculate);
    if (node114 != nullptr) node119->getVars().setVariable<float>(2, node114->getOutPosX());
    if (node114 != nullptr) node119->getVars().setVariable<float>(3, node114->getOutPosY());
    if (node114 != nullptr) node119->getVars().setVariable<float>(4, node114->getOutPosZ());
    if (node114 != nullptr) node119->setRotation(node114->getOutRotation());
    return node119;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(20021, 120) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_FALSE, 121, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_TRUE, 119, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(20021, 120) {
    auto node120 = GET_SKILL_NODE(120, PhaseNode_If);
    if (node120 == nullptr) {
        node120 = new PhaseNode_If(120, phase);
        node120->setCondition(false);
        CALL_REGISTER_SKILL_NODE(20021, 120, node120)
    }
    if (noInit == true) {
        return node120;
    }
    return node120;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(20021, 121) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_PlayEffect::TRIGGER_DONE, 122, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(20021, 121) {
    auto node121 = GET_SKILL_NODE(121, PhaseNode_PlayEffect);
    if (node121 == nullptr) {
        node121 = new PhaseNode_PlayEffect(121, phase);
        node121->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node121->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node121->setEffectID(0);
        node121->setChangeColor(false);
        node121->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node121->getVars().reserve(3);
        node121->getVars().setVariable<float>(0, .00f);
        node121->getVars().setVariable<float>(1, .00f);
        node121->getVars().setVariable<float>(2, .00f);
        node121->setScale(.00f);
        CALL_REGISTER_SKILL_NODE(20021, 121, node121)
    }
    if (noInit == true) {
        return node121;
    }
    auto node114 = GET_SKILL_NODE(114, PhaseNode_OffsetCalculate);
    if (node114 != nullptr) node121->getVars().setVariable<float>(0, node114->getOutPosX());
    if (node114 != nullptr) node121->getVars().setVariable<float>(1, node114->getOutPosY());
    if (node114 != nullptr) node121->getVars().setVariable<float>(2, node114->getOutPosZ());
    if (node114 != nullptr) node121->setRotation(node114->getOutRotation());
    return node121;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(20021, 122) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 126, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_LESS, 123, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_CompareFloat::TRIGGER_LESS, 126, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(20021, 122) {
    auto node122 = GET_SKILL_NODE(122, PhaseNode_CompareFloat);
    if (node122 == nullptr) {
        node122 = new PhaseNode_CompareFloat(122, phase);
        node122->setA(.00f);
        node122->setB(.00f);
        CALL_REGISTER_SKILL_NODE(20021, 122, node122)
    }
    if (noInit == true) {
        return node122;
    }
    return node122;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(20021, 123) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StopEffect>(PhaseNode_Delay::TRIGGER_DONE, 124, PhaseNode_StopEffect::FUNC_DO, &PhaseNode_StopEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(20021, 123) {
    auto node123 = GET_SKILL_NODE(123, PhaseNode_Delay);
    if (node123 == nullptr) {
        node123 = new PhaseNode_Delay(123, phase);
        node123->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(20021, 123, node123)
    }
    if (noInit == true) {
        return node123;
    }
    return node123;
}
//--------------------------------------------------------------------------------
// StopEffect
//
REGISTER_REGISTER_SKILL_NODE(20021, 124) {
}

REGISTER_CREATE_SKILL_NODE(20021, 124) {
    auto node124 = GET_SKILL_NODE(124, PhaseNode_StopEffect);
    if (node124 == nullptr) {
        node124 = new PhaseNode_StopEffect(124, phase);
        node124->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node124->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node124->setEffectID(0);
        CALL_REGISTER_SKILL_NODE(20021, 124, node124)
    }
    if (noInit == true) {
        return node124;
    }
    return node124;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(20021, 125) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_PlayEffect::TRIGGER_DONE, 128, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(20021, 125) {
    auto node125 = GET_SKILL_NODE(125, PhaseNode_PlayEffect);
    if (node125 == nullptr) {
        node125 = new PhaseNode_PlayEffect(125, phase);
        node125->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node125->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node125->setEffectID(0);
        node125->setChangeColor(false);
        node125->setType(PhaseNode_PlayEffect::PlayEffect_Type::WithTarget);
        node125->getVars().reserve(5);
        node125->getVars().setVariable<uint64_t>(0, 0U);
        node125->getVars().setVariable<std::string>(1, "");
        node125->getVars().setVariable<float>(2, .00f);
        node125->getVars().setVariable<float>(3, .00f);
        node125->getVars().setVariable<float>(4, .00f);
        node125->setScale(.00f);
        CALL_REGISTER_SKILL_NODE(20021, 125, node125)
    }
    if (noInit == true) {
        return node125;
    }
    auto node114 = GET_SKILL_NODE(114, PhaseNode_OffsetCalculate);
    if (node114 != nullptr) node125->getVars().setVariable<float>(2, node114->getOutPosX());
    if (node114 != nullptr) node125->getVars().setVariable<float>(3, node114->getOutPosY());
    if (node114 != nullptr) node125->getVars().setVariable<float>(4, node114->getOutPosZ());
    if (node114 != nullptr) node125->setRotation(node114->getOutRotation());
    return node125;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(20021, 126) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_FALSE, 127, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_TRUE, 125, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(20021, 126) {
    auto node126 = GET_SKILL_NODE(126, PhaseNode_If);
    if (node126 == nullptr) {
        node126 = new PhaseNode_If(126, phase);
        node126->setCondition(false);
        CALL_REGISTER_SKILL_NODE(20021, 126, node126)
    }
    if (noInit == true) {
        return node126;
    }
    return node126;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(20021, 127) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_PlayEffect::TRIGGER_DONE, 128, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(20021, 127) {
    auto node127 = GET_SKILL_NODE(127, PhaseNode_PlayEffect);
    if (node127 == nullptr) {
        node127 = new PhaseNode_PlayEffect(127, phase);
        node127->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node127->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node127->setEffectID(0);
        node127->setChangeColor(false);
        node127->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node127->getVars().reserve(3);
        node127->getVars().setVariable<float>(0, .00f);
        node127->getVars().setVariable<float>(1, .00f);
        node127->getVars().setVariable<float>(2, .00f);
        node127->setScale(.00f);
        CALL_REGISTER_SKILL_NODE(20021, 127, node127)
    }
    if (noInit == true) {
        return node127;
    }
    auto node114 = GET_SKILL_NODE(114, PhaseNode_OffsetCalculate);
    if (node114 != nullptr) node127->getVars().setVariable<float>(0, node114->getOutPosX());
    if (node114 != nullptr) node127->getVars().setVariable<float>(1, node114->getOutPosY());
    if (node114 != nullptr) node127->getVars().setVariable<float>(2, node114->getOutPosZ());
    if (node114 != nullptr) node127->setRotation(node114->getOutRotation());
    return node127;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(20021, 128) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 87, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_LESS, 129, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_LESS, 87, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(20021, 128) {
    auto node128 = GET_SKILL_NODE(128, PhaseNode_CompareFloat);
    if (node128 == nullptr) {
        node128 = new PhaseNode_CompareFloat(128, phase);
        node128->setA(.00f);
        node128->setB(.00f);
        CALL_REGISTER_SKILL_NODE(20021, 128, node128)
    }
    if (noInit == true) {
        return node128;
    }
    return node128;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(20021, 129) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StopEffect>(PhaseNode_Delay::TRIGGER_DONE, 130, PhaseNode_StopEffect::FUNC_DO, &PhaseNode_StopEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(20021, 129) {
    auto node129 = GET_SKILL_NODE(129, PhaseNode_Delay);
    if (node129 == nullptr) {
        node129 = new PhaseNode_Delay(129, phase);
        node129->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(20021, 129, node129)
    }
    if (noInit == true) {
        return node129;
    }
    return node129;
}
//--------------------------------------------------------------------------------
// StopEffect
//
REGISTER_REGISTER_SKILL_NODE(20021, 130) {
}

REGISTER_CREATE_SKILL_NODE(20021, 130) {
    auto node130 = GET_SKILL_NODE(130, PhaseNode_StopEffect);
    if (node130 == nullptr) {
        node130 = new PhaseNode_StopEffect(130, phase);
        node130->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node130->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node130->setEffectID(0);
        CALL_REGISTER_SKILL_NODE(20021, 130, node130)
    }
    if (noInit == true) {
        return node130;
    }
    return node130;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(20021, 131) {
}

REGISTER_CREATE_SKILL_NODE(20021, 131) {
    auto node131 = GET_SKILL_NODE(131, PhaseNode_RaiseEvent);
    if (node131 == nullptr) {
        node131 = new PhaseNode_RaiseEvent(131, phase);
        node131->setEvent("MonsterInterrupt");
        node131->setTarget(0U);
        node131->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node131->setTypeParams(0, 0);
        node131->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(20021, 131, node131)
    }
    if (noInit == true) {
        return node131;
    }
    return node131;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(20021, 132) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_Detect::TRIGGER_ON, 135, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(20021, 132) {
    auto node132 = GET_SKILL_NODE(132, PhaseNode_Detect);
    if (node132 == nullptr) {
        node132 = new PhaseNode_Detect(132, phase);
        node132->setSelf(0U);
        node132->setEvent("MonsterInterrupt");
        node132->setType(PhaseNode_Detect::Detect_Type::Interrupt_Skill);
        node132->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(20021, 132, node132)
    }
    if (noInit == true) {
        return node132;
    }
    return node132;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(20021, 133) {
}

REGISTER_CREATE_SKILL_NODE(20021, 133) {
    auto node133 = GET_SKILL_NODE(133, PhaseNode_EndPhase);
    if (node133 == nullptr) {
        node133 = new PhaseNode_EndPhase(133, phase);
        node133->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node133->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(20021, 133, node133)
    }
    if (noInit == true) {
        return node133;
    }
    return node133;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(20021, 135) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_Delay::TRIGGER_DONE, 137, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(20021, 135) {
    auto node135 = GET_SKILL_NODE(135, PhaseNode_Delay);
    if (node135 == nullptr) {
        node135 = new PhaseNode_Delay(135, phase);
        node135->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(20021, 135, node135)
    }
    if (noInit == true) {
        return node135;
    }
    return node135;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(20021, 136) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 133, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(20021, 136) {
    auto node136 = GET_SKILL_NODE(136, PhaseNode_SkillEndNotify);
    if (node136 == nullptr) {
        node136 = new PhaseNode_SkillEndNotify(136, phase);
        node136->setReturnType(false);
        CALL_REGISTER_SKILL_NODE(20021, 136, node136)
    }
    if (noInit == true) {
        return node136;
    }
    return node136;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(20021, 137) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_FALSE, 138, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_TRUE, 136, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
}

REGISTER_CREATE_SKILL_NODE(20021, 137) {
    auto node137 = GET_SKILL_NODE(137, PhaseNode_If);
    if (node137 == nullptr) {
        node137 = new PhaseNode_If(137, phase);
        node137->setCondition(false);
        CALL_REGISTER_SKILL_NODE(20021, 137, node137)
    }
    if (noInit == true) {
        return node137;
    }
    return node137;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(20021, 138) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 133, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(20021, 138) {
    auto node138 = GET_SKILL_NODE(138, PhaseNode_SkillEndNotify);
    if (node138 == nullptr) {
        node138 = new PhaseNode_SkillEndNotify(138, phase);
        node138->setReturnType(true);
        CALL_REGISTER_SKILL_NODE(20021, 138, node138)
    }
    if (noInit == true) {
        return node138;
    }
    return node138;
}

//--------------------------------------------------------------------------------
// SkillCreator_20021
//
class SkillCreator_20021 : public SkillCreator {
public:
    SkillCreator_20021() {}
    virtual ~SkillCreator_20021() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_20021

//--------------------------------------------------------------------------------
// SkillPhase_20021
//
class SkillPhase_20021 : public SkillPhase {
public:
    SkillPhase_20021(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_20021() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(20021, 2) // StartPhase
        CASE_CREATE_SKILL_NODE(20021, 5) // TriggerUpdate
        CASE_CREATE_SKILL_NODE(20021, 14) // EndPhase
        CASE_CREATE_SKILL_NODE(20021, 78) // PlaySound
        CASE_CREATE_SKILL_NODE(20021, 79) // SpawnCollider
        CASE_CREATE_SKILL_NODE(20021, 87) // Delay
        CASE_CREATE_SKILL_NODE(20021, 88) // Delay
        CASE_CREATE_SKILL_NODE(20021, 89) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(20021, 90) // If
        CASE_CREATE_SKILL_NODE(20021, 91) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(20021, 92) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(20021, 93) // TriggerCheck
        CASE_CREATE_SKILL_NODE(20021, 94) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(20021, 95) // GetActorAttribute
        CASE_CREATE_SKILL_NODE(20021, 96) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(20021, 97) // CompareFloat
        CASE_CREATE_SKILL_NODE(20021, 98) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(20021, 99) // If
        CASE_CREATE_SKILL_NODE(20021, 100) // CompareFloat
        CASE_CREATE_SKILL_NODE(20021, 101) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(20021, 102) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(20021, 103) // TriggerCheck
        CASE_CREATE_SKILL_NODE(20021, 104) // TriggerCheck
        CASE_CREATE_SKILL_NODE(20021, 105) // TriggerCheck
        CASE_CREATE_SKILL_NODE(20021, 106) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(20021, 107) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(20021, 108) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(20021, 109) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(20021, 110) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(20021, 111) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(20021, 112) // GetLocation
        CASE_CREATE_SKILL_NODE(20021, 113) // GetRotation
        CASE_CREATE_SKILL_NODE(20021, 114) // OffsetCalculate
        CASE_CREATE_SKILL_NODE(20021, 115) // ResetCD
        CASE_CREATE_SKILL_NODE(20021, 116) // PlayAnimation
        CASE_CREATE_SKILL_NODE(20021, 117) // PlaySound
        CASE_CREATE_SKILL_NODE(20021, 118) // Delay
        CASE_CREATE_SKILL_NODE(20021, 119) // PlayEffect
        CASE_CREATE_SKILL_NODE(20021, 120) // If
        CASE_CREATE_SKILL_NODE(20021, 121) // PlayEffect
        CASE_CREATE_SKILL_NODE(20021, 122) // CompareFloat
        CASE_CREATE_SKILL_NODE(20021, 123) // Delay
        CASE_CREATE_SKILL_NODE(20021, 124) // StopEffect
        CASE_CREATE_SKILL_NODE(20021, 125) // PlayEffect
        CASE_CREATE_SKILL_NODE(20021, 126) // If
        CASE_CREATE_SKILL_NODE(20021, 127) // PlayEffect
        CASE_CREATE_SKILL_NODE(20021, 128) // CompareFloat
        CASE_CREATE_SKILL_NODE(20021, 129) // Delay
        CASE_CREATE_SKILL_NODE(20021, 130) // StopEffect
        CASE_CREATE_SKILL_NODE(20021, 131) // RaiseEvent
        CASE_CREATE_SKILL_NODE(20021, 132) // Detect
        CASE_CREATE_SKILL_NODE(20021, 133) // EndPhase
        CASE_CREATE_SKILL_NODE(20021, 135) // Delay
        CASE_CREATE_SKILL_NODE(20021, 136) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(20021, 137) // If
        CASE_CREATE_SKILL_NODE(20021, 138) // SkillEndNotify
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_20021

SkillLogic* SkillCreator_20021::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //创建阶段phase
    auto phase = new SkillPhase_20021(1, logic, 3);
    //设置phase执行器
    phase->setRunPhaseNode(1, 2);
    phase->setRunPhaseNode(2, 5);
    phase->setDetectPhaseNode(3, 132);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_20021::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
