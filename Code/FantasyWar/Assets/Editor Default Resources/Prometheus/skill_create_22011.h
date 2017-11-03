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
REGISTER_REGISTER_SKILL_NODE(22011, 1) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_StartPhase::TRIGGER_START, 113, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_StartPhase::TRIGGER_START, 115, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_StartPhase::TRIGGER_START, 109, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_StartPhase::TRIGGER_START, 102, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(22011, 1) {
    auto node1 = GET_SKILL_NODE(1, PhaseNode_StartPhase);
    if (node1 == nullptr) {
        node1 = new PhaseNode_StartPhase(1, phase);
        CALL_REGISTER_SKILL_NODE(22011, 1, node1)
    }
    if (noInit == true) {
        return node1;
    }
    return node1;
}
//--------------------------------------------------------------------------------
// TriggerUpdate
//
REGISTER_REGISTER_SKILL_NODE(22011, 2) {
}

REGISTER_CREATE_SKILL_NODE(22011, 2) {
    auto node2 = GET_SKILL_NODE(2, PhaseNode_TriggerUpdate);
    if (node2 == nullptr) {
        node2 = new PhaseNode_TriggerUpdate(2, phase);
        CALL_REGISTER_SKILL_NODE(22011, 2, node2)
    }
    if (noInit == true) {
        return node2;
    }
    return node2;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22011, 7) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_Delay::TRIGGER_DONE, 93, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(22011, 7) {
    auto node7 = GET_SKILL_NODE(7, PhaseNode_Delay);
    if (node7 == nullptr) {
        node7 = new PhaseNode_Delay(7, phase);
        node7->setTime(.50f);
        CALL_REGISTER_SKILL_NODE(22011, 7, node7)
    }
    if (noInit == true) {
        return node7;
    }
    return node7;
}
//--------------------------------------------------------------------------------
// SpawnCollider
//
REGISTER_REGISTER_SKILL_NODE(22011, 8) {
    pnode->resizeTrigger(PhaseNode_SpawnCollider::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_SpawnCollider::TRIGGER_DONE, 76, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_SpawnCollider::TRIGGER_DONE, 65, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(22011, 8) {
    auto node8 = GET_SKILL_NODE(8, PhaseNode_SpawnCollider);
    if (node8 == nullptr) {
        node8 = new PhaseNode_SpawnCollider(8, phase);
        node8->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node8->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node8->setMesh("");
        node8->setMeshScale(.00f);
        node8->setEffectID(0);
        node8->setEffectScale(.00f);
        node8->setType(PhaseNode_SpawnCollider::SpawnCollider_Type::Circle);
        node8->setTypeParams(0, 2.00f);
        node8->setTime(.30f);
        node8->setPosZ(.00f);
        node8->setreentry(false);
        node8->setCheckPeneSound(false);
        CALL_REGISTER_SKILL_NODE(22011, 8, node8)
    }
    if (noInit == true) {
        return node8;
    }
    auto node95 = GET_SKILL_NODE(95, PhaseNode_OffsetCalculate);
    if (node95 != nullptr) node8->setPosX(node95->getOutPosX());
    if (node95 != nullptr) node8->setPosY(node95->getOutPosY());
    if (node95 != nullptr) node8->setRotation(node95->getOutRotation());
    return node8;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(22011, 20) {
}

REGISTER_CREATE_SKILL_NODE(22011, 20) {
    auto node20 = GET_SKILL_NODE(20, PhaseNode_EndPhase);
    if (node20 == nullptr) {
        node20 = new PhaseNode_EndPhase(20, phase);
        node20->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node20->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(22011, 20, node20)
    }
    if (noInit == true) {
        return node20;
    }
    return node20;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(22011, 32) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_Detect::TRIGGER_ON, 38, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(22011, 32) {
    auto node32 = GET_SKILL_NODE(32, PhaseNode_Detect);
    if (node32 == nullptr) {
        node32 = new PhaseNode_Detect(32, phase);
        node32->setSelf(0U);
        node32->setEvent("");
        node32->setType(PhaseNode_Detect::Detect_Type::Actor_Dead);
        node32->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(22011, 32, node32)
    }
    if (noInit == true) {
        return node32;
    }
    return node32;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(22011, 38) {
}

REGISTER_CREATE_SKILL_NODE(22011, 38) {
    auto node38 = GET_SKILL_NODE(38, PhaseNode_EndPhase);
    if (node38 == nullptr) {
        node38 = new PhaseNode_EndPhase(38, phase);
        node38->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node38->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(22011, 38, node38)
    }
    if (noInit == true) {
        return node38;
    }
    return node38;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(22011, 65) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlaySound::TRIGGER_DONE, 89, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(22011, 65) {
    auto node65 = GET_SKILL_NODE(65, PhaseNode_PlaySound);
    if (node65 == nullptr) {
        node65 = new PhaseNode_PlaySound(65, phase);
        node65->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node65->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node65->setSoundID("SE_MON2201_ATK2_P2");
        node65->setTarget(0U);
        node65->setUsePos(false);
        node65->setPosX(.00f);
        node65->setPosY(.00f);
        node65->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(22011, 65, node65)
    }
    if (noInit == true) {
        return node65;
    }
    return node65;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(22011, 69) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 81, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 83, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(22011, 69) {
    auto node69 = GET_SKILL_NODE(69, PhaseNode_CreateTriggerNewPene);
    if (node69 == nullptr) {
        node69 = new PhaseNode_CreateTriggerNewPene(69, phase);
        node69->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::In);
        node69->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node69->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Enemy);
        node69->setOnHero(true);
        node69->setOnMinion(true);
        node69->setOnDestruct(true);
        node69->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(22011, 69, node69)
    }
    if (noInit == true) {
        return node69;
    }
    auto node8 = GET_SKILL_NODE(8, PhaseNode_SpawnCollider);
    if (node8 != nullptr) node69->setColliderID(node8->getColliderID());
    return node69;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(22011, 70) {
}

REGISTER_CREATE_SKILL_NODE(22011, 70) {
    auto node70 = GET_SKILL_NODE(70, PhaseNode_TriggerCheck);
    if (node70 == nullptr) {
        node70 = new PhaseNode_TriggerCheck(70, phase);
        auto node2 = GET_SKILL_NODE(2, PhaseNode_TriggerUpdate);
        if (node2 != nullptr) node2->addTriggerCheck(node70);
        
        CALL_REGISTER_SKILL_NODE(22011, 70, node70)
    }
    if (noInit == true) {
        return node70;
    }
    auto node79 = GET_SKILL_NODE(79, PhaseNode_CreateTriggerNewPene);
    if (node79 != nullptr) node70->setTrigger(0, node79->getTriggerID());
    return node70;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(22011, 71) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 72, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(22011, 71) {
    auto node71 = GET_SKILL_NODE(71, PhaseNode_ActorFilterNewPene);
    if (node71 == nullptr) {
        node71 = new PhaseNode_ActorFilterNewPene(71, phase);
        node71->setHero(true);
        node71->setMinion(true);
        node71->setDestruct(true);
        node71->setShield(false);
        node71->setTotalCount(0);
        node71->setPerCount(1);
        CALL_REGISTER_SKILL_NODE(22011, 71, node71)
    }
    if (noInit == true) {
        return node71;
    }
    auto node75 = GET_SKILL_NODE(75, PhaseNode_CreateTriggerNewPene);
    if (node75 != nullptr) node71->setInput(node75->getOther());
    return node71;
}
//--------------------------------------------------------------------------------
// GetActorAttribute
//
REGISTER_REGISTER_SKILL_NODE(22011, 72) {
    pnode->resizeTrigger(PhaseNode_GetActorAttribute::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 73, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 86, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 87, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 88, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
}

REGISTER_CREATE_SKILL_NODE(22011, 72) {
    auto node72 = GET_SKILL_NODE(72, PhaseNode_GetActorAttribute);
    if (node72 == nullptr) {
        node72 = new PhaseNode_GetActorAttribute(72, phase);
        node72->setTarget(0U);
        node72->setType({202});
        CALL_REGISTER_SKILL_NODE(22011, 72, node72)
    }
    if (noInit == true) {
        return node72;
    }
    return node72;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(22011, 73) {
}

REGISTER_CREATE_SKILL_NODE(22011, 73) {
    auto node73 = GET_SKILL_NODE(73, PhaseNode_AddSkillBuffs);
    if (node73 == nullptr) {
        node73 = new PhaseNode_AddSkillBuffs(73, phase);
        node73->setConfigID({11});
        CALL_REGISTER_SKILL_NODE(22011, 73, node73)
    }
    if (noInit == true) {
        return node73;
    }
    auto node71 = GET_SKILL_NODE(71, PhaseNode_ActorFilterNewPene);
    auto node72 = GET_SKILL_NODE(72, PhaseNode_GetActorAttribute);
    if (node71 != nullptr) node73->setTarget(node71->getOutput());
    if (node72 != nullptr) node73->setAttribute(node72->getAttribute());
    return node73;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(22011, 74) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 69, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_LESS, 75, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
}

REGISTER_CREATE_SKILL_NODE(22011, 74) {
    auto node74 = GET_SKILL_NODE(74, PhaseNode_CompareFloat);
    if (node74 == nullptr) {
        node74 = new PhaseNode_CompareFloat(74, phase);
        node74->setA(.00f);
        node74->setB(.00f);
        CALL_REGISTER_SKILL_NODE(22011, 74, node74)
    }
    if (noInit == true) {
        return node74;
    }
    return node74;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(22011, 75) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 80, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 71, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(22011, 75) {
    auto node75 = GET_SKILL_NODE(75, PhaseNode_CreateTriggerNewPene);
    if (node75 == nullptr) {
        node75 = new PhaseNode_CreateTriggerNewPene(75, phase);
        node75->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::Tick);
        node75->setTypeParams(0, .00f);
        node75->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node75->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Enemy);
        node75->setOnHero(true);
        node75->setOnMinion(true);
        node75->setOnDestruct(true);
        node75->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(22011, 75, node75)
    }
    if (noInit == true) {
        return node75;
    }
    auto node8 = GET_SKILL_NODE(8, PhaseNode_SpawnCollider);
    if (node8 != nullptr) node75->setColliderID(node8->getColliderID());
    return node75;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(22011, 76) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_If::TRIGGER_FALSE, 77, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_If::TRIGGER_TRUE, 74, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(22011, 76) {
    auto node76 = GET_SKILL_NODE(76, PhaseNode_If);
    if (node76 == nullptr) {
        node76 = new PhaseNode_If(76, phase);
        node76->setCondition(true);
        CALL_REGISTER_SKILL_NODE(22011, 76, node76)
    }
    if (noInit == true) {
        return node76;
    }
    return node76;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(22011, 77) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 79, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_LESS, 78, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
}

REGISTER_CREATE_SKILL_NODE(22011, 77) {
    auto node77 = GET_SKILL_NODE(77, PhaseNode_CompareFloat);
    if (node77 == nullptr) {
        node77 = new PhaseNode_CompareFloat(77, phase);
        node77->setA(.00f);
        node77->setB(.00f);
        CALL_REGISTER_SKILL_NODE(22011, 77, node77)
    }
    if (noInit == true) {
        return node77;
    }
    return node77;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(22011, 78) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 82, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 84, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(22011, 78) {
    auto node78 = GET_SKILL_NODE(78, PhaseNode_CreateTriggerNewPene);
    if (node78 == nullptr) {
        node78 = new PhaseNode_CreateTriggerNewPene(78, phase);
        node78->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::Tick);
        node78->setTypeParams(0, .00f);
        node78->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node78->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Friend);
        node78->setOnHero(true);
        node78->setOnMinion(true);
        node78->setOnDestruct(true);
        node78->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(22011, 78, node78)
    }
    if (noInit == true) {
        return node78;
    }
    auto node8 = GET_SKILL_NODE(8, PhaseNode_SpawnCollider);
    if (node8 != nullptr) node78->setColliderID(node8->getColliderID());
    return node78;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(22011, 79) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 70, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 85, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(22011, 79) {
    auto node79 = GET_SKILL_NODE(79, PhaseNode_CreateTriggerNewPene);
    if (node79 == nullptr) {
        node79 = new PhaseNode_CreateTriggerNewPene(79, phase);
        node79->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::In);
        node79->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node79->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Friend);
        node79->setOnHero(true);
        node79->setOnMinion(true);
        node79->setOnDestruct(true);
        node79->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(22011, 79, node79)
    }
    if (noInit == true) {
        return node79;
    }
    auto node8 = GET_SKILL_NODE(8, PhaseNode_SpawnCollider);
    if (node8 != nullptr) node79->setColliderID(node8->getColliderID());
    return node79;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(22011, 80) {
}

REGISTER_CREATE_SKILL_NODE(22011, 80) {
    auto node80 = GET_SKILL_NODE(80, PhaseNode_TriggerCheck);
    if (node80 == nullptr) {
        node80 = new PhaseNode_TriggerCheck(80, phase);
        auto node2 = GET_SKILL_NODE(2, PhaseNode_TriggerUpdate);
        if (node2 != nullptr) node2->addTriggerCheck(node80);
        
        CALL_REGISTER_SKILL_NODE(22011, 80, node80)
    }
    if (noInit == true) {
        return node80;
    }
    auto node75 = GET_SKILL_NODE(75, PhaseNode_CreateTriggerNewPene);
    if (node75 != nullptr) node80->setTrigger(0, node75->getTriggerID());
    return node80;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(22011, 81) {
}

REGISTER_CREATE_SKILL_NODE(22011, 81) {
    auto node81 = GET_SKILL_NODE(81, PhaseNode_TriggerCheck);
    if (node81 == nullptr) {
        node81 = new PhaseNode_TriggerCheck(81, phase);
        auto node2 = GET_SKILL_NODE(2, PhaseNode_TriggerUpdate);
        if (node2 != nullptr) node2->addTriggerCheck(node81);
        
        CALL_REGISTER_SKILL_NODE(22011, 81, node81)
    }
    if (noInit == true) {
        return node81;
    }
    auto node69 = GET_SKILL_NODE(69, PhaseNode_CreateTriggerNewPene);
    if (node69 != nullptr) node81->setTrigger(0, node69->getTriggerID());
    return node81;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(22011, 82) {
}

REGISTER_CREATE_SKILL_NODE(22011, 82) {
    auto node82 = GET_SKILL_NODE(82, PhaseNode_TriggerCheck);
    if (node82 == nullptr) {
        node82 = new PhaseNode_TriggerCheck(82, phase);
        auto node2 = GET_SKILL_NODE(2, PhaseNode_TriggerUpdate);
        if (node2 != nullptr) node2->addTriggerCheck(node82);
        
        CALL_REGISTER_SKILL_NODE(22011, 82, node82)
    }
    if (noInit == true) {
        return node82;
    }
    auto node78 = GET_SKILL_NODE(78, PhaseNode_CreateTriggerNewPene);
    if (node78 != nullptr) node82->setTrigger(0, node78->getTriggerID());
    return node82;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(22011, 83) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 72, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(22011, 83) {
    auto node83 = GET_SKILL_NODE(83, PhaseNode_ActorFilterNewPene);
    if (node83 == nullptr) {
        node83 = new PhaseNode_ActorFilterNewPene(83, phase);
        node83->setHero(true);
        node83->setMinion(true);
        node83->setDestruct(true);
        node83->setShield(false);
        node83->setTotalCount(0);
        node83->setPerCount(1);
        CALL_REGISTER_SKILL_NODE(22011, 83, node83)
    }
    if (noInit == true) {
        return node83;
    }
    auto node69 = GET_SKILL_NODE(69, PhaseNode_CreateTriggerNewPene);
    if (node69 != nullptr) node83->setInput(node69->getOther());
    return node83;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(22011, 84) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 72, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(22011, 84) {
    auto node84 = GET_SKILL_NODE(84, PhaseNode_ActorFilterNewPene);
    if (node84 == nullptr) {
        node84 = new PhaseNode_ActorFilterNewPene(84, phase);
        node84->setHero(true);
        node84->setMinion(true);
        node84->setDestruct(true);
        node84->setShield(false);
        node84->setTotalCount(0);
        node84->setPerCount(1);
        CALL_REGISTER_SKILL_NODE(22011, 84, node84)
    }
    if (noInit == true) {
        return node84;
    }
    auto node78 = GET_SKILL_NODE(78, PhaseNode_CreateTriggerNewPene);
    if (node78 != nullptr) node84->setInput(node78->getOther());
    return node84;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(22011, 85) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 72, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(22011, 85) {
    auto node85 = GET_SKILL_NODE(85, PhaseNode_ActorFilterNewPene);
    if (node85 == nullptr) {
        node85 = new PhaseNode_ActorFilterNewPene(85, phase);
        node85->setHero(true);
        node85->setMinion(true);
        node85->setDestruct(true);
        node85->setShield(false);
        node85->setTotalCount(0);
        node85->setPerCount(1);
        CALL_REGISTER_SKILL_NODE(22011, 85, node85)
    }
    if (noInit == true) {
        return node85;
    }
    auto node79 = GET_SKILL_NODE(79, PhaseNode_CreateTriggerNewPene);
    if (node79 != nullptr) node85->setInput(node79->getOther());
    return node85;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(22011, 86) {
}

REGISTER_CREATE_SKILL_NODE(22011, 86) {
    auto node86 = GET_SKILL_NODE(86, PhaseNode_AddSkillBuffs);
    if (node86 == nullptr) {
        node86 = new PhaseNode_AddSkillBuffs(86, phase);
        node86->setConfigID({11});
        CALL_REGISTER_SKILL_NODE(22011, 86, node86)
    }
    if (noInit == true) {
        return node86;
    }
    auto node83 = GET_SKILL_NODE(83, PhaseNode_ActorFilterNewPene);
    auto node72 = GET_SKILL_NODE(72, PhaseNode_GetActorAttribute);
    if (node83 != nullptr) node86->setTarget(node83->getOutput());
    if (node72 != nullptr) node86->setAttribute(node72->getAttribute());
    return node86;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(22011, 87) {
}

REGISTER_CREATE_SKILL_NODE(22011, 87) {
    auto node87 = GET_SKILL_NODE(87, PhaseNode_AddSkillBuffs);
    if (node87 == nullptr) {
        node87 = new PhaseNode_AddSkillBuffs(87, phase);
        node87->setConfigID({11});
        CALL_REGISTER_SKILL_NODE(22011, 87, node87)
    }
    if (noInit == true) {
        return node87;
    }
    auto node84 = GET_SKILL_NODE(84, PhaseNode_ActorFilterNewPene);
    auto node72 = GET_SKILL_NODE(72, PhaseNode_GetActorAttribute);
    if (node84 != nullptr) node87->setTarget(node84->getOutput());
    if (node72 != nullptr) node87->setAttribute(node72->getAttribute());
    return node87;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(22011, 88) {
}

REGISTER_CREATE_SKILL_NODE(22011, 88) {
    auto node88 = GET_SKILL_NODE(88, PhaseNode_AddSkillBuffs);
    if (node88 == nullptr) {
        node88 = new PhaseNode_AddSkillBuffs(88, phase);
        node88->setConfigID({11});
        CALL_REGISTER_SKILL_NODE(22011, 88, node88)
    }
    if (noInit == true) {
        return node88;
    }
    auto node85 = GET_SKILL_NODE(85, PhaseNode_ActorFilterNewPene);
    auto node72 = GET_SKILL_NODE(72, PhaseNode_GetActorAttribute);
    if (node85 != nullptr) node88->setTarget(node85->getOutput());
    if (node72 != nullptr) node88->setAttribute(node72->getAttribute());
    return node88;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22011, 89) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_Delay::TRIGGER_DONE, 91, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(22011, 89) {
    auto node89 = GET_SKILL_NODE(89, PhaseNode_Delay);
    if (node89 == nullptr) {
        node89 = new PhaseNode_Delay(89, phase);
        node89->setTime(.80f);
        CALL_REGISTER_SKILL_NODE(22011, 89, node89)
    }
    if (noInit == true) {
        return node89;
    }
    return node89;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(22011, 90) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 20, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(22011, 90) {
    auto node90 = GET_SKILL_NODE(90, PhaseNode_SkillEndNotify);
    if (node90 == nullptr) {
        node90 = new PhaseNode_SkillEndNotify(90, phase);
        node90->setReturnType(false);
        CALL_REGISTER_SKILL_NODE(22011, 90, node90)
    }
    if (noInit == true) {
        return node90;
    }
    return node90;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(22011, 91) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_FALSE, 92, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_TRUE, 90, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
}

REGISTER_CREATE_SKILL_NODE(22011, 91) {
    auto node91 = GET_SKILL_NODE(91, PhaseNode_If);
    if (node91 == nullptr) {
        node91 = new PhaseNode_If(91, phase);
        node91->setCondition(false);
        CALL_REGISTER_SKILL_NODE(22011, 91, node91)
    }
    if (noInit == true) {
        return node91;
    }
    return node91;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(22011, 92) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 20, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(22011, 92) {
    auto node92 = GET_SKILL_NODE(92, PhaseNode_SkillEndNotify);
    if (node92 == nullptr) {
        node92 = new PhaseNode_SkillEndNotify(92, phase);
        node92->setReturnType(true);
        CALL_REGISTER_SKILL_NODE(22011, 92, node92)
    }
    if (noInit == true) {
        return node92;
    }
    return node92;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(22011, 93) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetRotation>(PhaseNode_GetLocation::TRIGGER_DONE, 94, PhaseNode_GetRotation::FUNC_DO, &PhaseNode_GetRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(22011, 93) {
    auto node93 = GET_SKILL_NODE(93, PhaseNode_GetLocation);
    if (node93 == nullptr) {
        node93 = new PhaseNode_GetLocation(93, phase);
        node93->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node93->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(22011, 93, node93)
    }
    if (noInit == true) {
        return node93;
    }
    return node93;
}
//--------------------------------------------------------------------------------
// GetRotation
//
REGISTER_REGISTER_SKILL_NODE(22011, 94) {
    pnode->resizeTrigger(PhaseNode_GetRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_OffsetCalculate>(PhaseNode_GetRotation::TRIGGER_DONE, 95, PhaseNode_OffsetCalculate::FUNC_DO, &PhaseNode_OffsetCalculate::Do);
}

REGISTER_CREATE_SKILL_NODE(22011, 94) {
    auto node94 = GET_SKILL_NODE(94, PhaseNode_GetRotation);
    if (node94 == nullptr) {
        node94 = new PhaseNode_GetRotation(94, phase);
        node94->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node94->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(22011, 94, node94)
    }
    if (noInit == true) {
        return node94;
    }
    return node94;
}
//--------------------------------------------------------------------------------
// OffsetCalculate
//
REGISTER_REGISTER_SKILL_NODE(22011, 95) {
    pnode->resizeTrigger(PhaseNode_OffsetCalculate::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnCollider>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 8, PhaseNode_SpawnCollider::FUNC_DO, &PhaseNode_SpawnCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(22011, 95) {
    auto node95 = GET_SKILL_NODE(95, PhaseNode_OffsetCalculate);
    if (node95 == nullptr) {
        node95 = new PhaseNode_OffsetCalculate(95, phase);
        node95->setPosZ(.00f);
        node95->setOffsetX(.00f);
        node95->setOffsetY(2.00f);
        node95->setOffsetZ(.00f);
        node95->setRotOffset(.00f);
        CALL_REGISTER_SKILL_NODE(22011, 95, node95)
    }
    if (noInit == true) {
        return node95;
    }
    auto node93 = GET_SKILL_NODE(93, PhaseNode_GetLocation);
    auto node94 = GET_SKILL_NODE(94, PhaseNode_GetRotation);
    if (node93 != nullptr) node95->setPosX(node93->getX());
    if (node93 != nullptr) node95->setPosY(node93->getY());
    if (node94 != nullptr) node95->setRotation(node94->getAngle());
    return node95;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(22011, 96) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_PlayEffect::TRIGGER_DONE, 99, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(22011, 96) {
    auto node96 = GET_SKILL_NODE(96, PhaseNode_PlayEffect);
    if (node96 == nullptr) {
        node96 = new PhaseNode_PlayEffect(96, phase);
        node96->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node96->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node96->setEffectID(220111);
        node96->setChangeColor(false);
        node96->setType(PhaseNode_PlayEffect::PlayEffect_Type::WithTarget);
        node96->getVars().reserve(5);
        node96->getVars().setVariable<uint64_t>(0, 0U);
        node96->getVars().setVariable<std::string>(1, "");
        node96->getVars().setVariable<float>(2, .00f);
        node96->getVars().setVariable<float>(3, .00f);
        node96->getVars().setVariable<float>(4, .00f);
        node96->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(22011, 96, node96)
    }
    if (noInit == true) {
        return node96;
    }
    auto node108 = GET_SKILL_NODE(108, PhaseNode_OffsetCalculate);
    if (node108 != nullptr) node96->getVars().setVariable<float>(2, node108->getOutPosX());
    if (node108 != nullptr) node96->getVars().setVariable<float>(3, node108->getOutPosY());
    if (node108 != nullptr) node96->getVars().setVariable<float>(4, node108->getOutPosZ());
    if (node108 != nullptr) node96->setRotation(node108->getOutRotation());
    return node96;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(22011, 97) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_FALSE, 98, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_TRUE, 96, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(22011, 97) {
    auto node97 = GET_SKILL_NODE(97, PhaseNode_If);
    if (node97 == nullptr) {
        node97 = new PhaseNode_If(97, phase);
        node97->setCondition(false);
        CALL_REGISTER_SKILL_NODE(22011, 97, node97)
    }
    if (noInit == true) {
        return node97;
    }
    return node97;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(22011, 98) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_PlayEffect::TRIGGER_DONE, 99, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(22011, 98) {
    auto node98 = GET_SKILL_NODE(98, PhaseNode_PlayEffect);
    if (node98 == nullptr) {
        node98 = new PhaseNode_PlayEffect(98, phase);
        node98->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node98->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node98->setEffectID(220111);
        node98->setChangeColor(false);
        node98->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node98->getVars().reserve(3);
        node98->getVars().setVariable<float>(0, .00f);
        node98->getVars().setVariable<float>(1, .00f);
        node98->getVars().setVariable<float>(2, .00f);
        node98->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(22011, 98, node98)
    }
    if (noInit == true) {
        return node98;
    }
    auto node108 = GET_SKILL_NODE(108, PhaseNode_OffsetCalculate);
    if (node108 != nullptr) node98->getVars().setVariable<float>(0, node108->getOutPosX());
    if (node108 != nullptr) node98->getVars().setVariable<float>(1, node108->getOutPosY());
    if (node108 != nullptr) node98->getVars().setVariable<float>(2, node108->getOutPosZ());
    if (node108 != nullptr) node98->setRotation(node108->getOutRotation());
    return node98;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(22011, 99) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 7, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_LESS, 100, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_LESS, 7, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(22011, 99) {
    auto node99 = GET_SKILL_NODE(99, PhaseNode_CompareFloat);
    if (node99 == nullptr) {
        node99 = new PhaseNode_CompareFloat(99, phase);
        node99->setA(.00f);
        node99->setB(.00f);
        CALL_REGISTER_SKILL_NODE(22011, 99, node99)
    }
    if (noInit == true) {
        return node99;
    }
    return node99;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22011, 100) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StopEffect>(PhaseNode_Delay::TRIGGER_DONE, 101, PhaseNode_StopEffect::FUNC_DO, &PhaseNode_StopEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(22011, 100) {
    auto node100 = GET_SKILL_NODE(100, PhaseNode_Delay);
    if (node100 == nullptr) {
        node100 = new PhaseNode_Delay(100, phase);
        node100->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(22011, 100, node100)
    }
    if (noInit == true) {
        return node100;
    }
    return node100;
}
//--------------------------------------------------------------------------------
// StopEffect
//
REGISTER_REGISTER_SKILL_NODE(22011, 101) {
}

REGISTER_CREATE_SKILL_NODE(22011, 101) {
    auto node101 = GET_SKILL_NODE(101, PhaseNode_StopEffect);
    if (node101 == nullptr) {
        node101 = new PhaseNode_StopEffect(101, phase);
        node101->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node101->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node101->setEffectID(220111);
        CALL_REGISTER_SKILL_NODE(22011, 101, node101)
    }
    if (noInit == true) {
        return node101;
    }
    return node101;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(22011, 102) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_ResetCD::TRIGGER_DONE, 103, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(22011, 102) {
    auto node102 = GET_SKILL_NODE(102, PhaseNode_ResetCD);
    if (node102 == nullptr) {
        node102 = new PhaseNode_ResetCD(102, phase);
        node102->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node102->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node102->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(22011, 102, node102)
    }
    if (noInit == true) {
        return node102;
    }
    return node102;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(22011, 103) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_PlayAnimation::TRIGGER_DONE, 104, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(22011, 103) {
    auto node103 = GET_SKILL_NODE(103, PhaseNode_PlayAnimation);
    if (node103 == nullptr) {
        node103 = new PhaseNode_PlayAnimation(103, phase);
        node103->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node103->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node103->setTarget(0U);
        node103->setAnimation("Skill1S1");
        node103->setParameter("");
        node103->setValue(false);
        CALL_REGISTER_SKILL_NODE(22011, 103, node103)
    }
    if (noInit == true) {
        return node103;
    }
    return node103;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(22011, 104) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlaySound::TRIGGER_DONE, 105, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(22011, 104) {
    auto node104 = GET_SKILL_NODE(104, PhaseNode_PlaySound);
    if (node104 == nullptr) {
        node104 = new PhaseNode_PlaySound(104, phase);
        node104->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node104->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node104->setSoundID("");
        node104->setTarget(0U);
        node104->setUsePos(false);
        node104->setPosX(.00f);
        node104->setPosY(.00f);
        node104->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(22011, 104, node104)
    }
    if (noInit == true) {
        return node104;
    }
    return node104;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22011, 105) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_Delay::TRIGGER_DONE, 106, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(22011, 105) {
    auto node105 = GET_SKILL_NODE(105, PhaseNode_Delay);
    if (node105 == nullptr) {
        node105 = new PhaseNode_Delay(105, phase);
        node105->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(22011, 105, node105)
    }
    if (noInit == true) {
        return node105;
    }
    return node105;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(22011, 106) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetRotation>(PhaseNode_GetLocation::TRIGGER_DONE, 107, PhaseNode_GetRotation::FUNC_DO, &PhaseNode_GetRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(22011, 106) {
    auto node106 = GET_SKILL_NODE(106, PhaseNode_GetLocation);
    if (node106 == nullptr) {
        node106 = new PhaseNode_GetLocation(106, phase);
        node106->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node106->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(22011, 106, node106)
    }
    if (noInit == true) {
        return node106;
    }
    return node106;
}
//--------------------------------------------------------------------------------
// GetRotation
//
REGISTER_REGISTER_SKILL_NODE(22011, 107) {
    pnode->resizeTrigger(PhaseNode_GetRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_OffsetCalculate>(PhaseNode_GetRotation::TRIGGER_DONE, 108, PhaseNode_OffsetCalculate::FUNC_DO, &PhaseNode_OffsetCalculate::Do);
}

REGISTER_CREATE_SKILL_NODE(22011, 107) {
    auto node107 = GET_SKILL_NODE(107, PhaseNode_GetRotation);
    if (node107 == nullptr) {
        node107 = new PhaseNode_GetRotation(107, phase);
        node107->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node107->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(22011, 107, node107)
    }
    if (noInit == true) {
        return node107;
    }
    return node107;
}
//--------------------------------------------------------------------------------
// OffsetCalculate
//
REGISTER_REGISTER_SKILL_NODE(22011, 108) {
    pnode->resizeTrigger(PhaseNode_OffsetCalculate::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 97, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(22011, 108) {
    auto node108 = GET_SKILL_NODE(108, PhaseNode_OffsetCalculate);
    if (node108 == nullptr) {
        node108 = new PhaseNode_OffsetCalculate(108, phase);
        node108->setPosZ(.00f);
        node108->setOffsetX(.00f);
        node108->setOffsetY(.00f);
        node108->setOffsetZ(.00f);
        node108->setRotOffset(.00f);
        CALL_REGISTER_SKILL_NODE(22011, 108, node108)
    }
    if (noInit == true) {
        return node108;
    }
    auto node106 = GET_SKILL_NODE(106, PhaseNode_GetLocation);
    auto node107 = GET_SKILL_NODE(107, PhaseNode_GetRotation);
    if (node106 != nullptr) node108->setPosX(node106->getX());
    if (node106 != nullptr) node108->setPosY(node106->getY());
    if (node107 != nullptr) node108->setRotation(node107->getAngle());
    return node108;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(22011, 109) {
}

REGISTER_CREATE_SKILL_NODE(22011, 109) {
    auto node109 = GET_SKILL_NODE(109, PhaseNode_RaiseEvent);
    if (node109 == nullptr) {
        node109 = new PhaseNode_RaiseEvent(109, phase);
        node109->setEvent("MonsterInterrupt");
        node109->setTarget(0U);
        node109->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node109->setTypeParams(0, 0);
        node109->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(22011, 109, node109)
    }
    if (noInit == true) {
        return node109;
    }
    return node109;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(22011, 110) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_Detect::TRIGGER_ON, 117, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(22011, 110) {
    auto node110 = GET_SKILL_NODE(110, PhaseNode_Detect);
    if (node110 == nullptr) {
        node110 = new PhaseNode_Detect(110, phase);
        node110->setSelf(0U);
        node110->setEvent("MonsterInterrupt");
        node110->setType(PhaseNode_Detect::Detect_Type::Interrupt_Skill);
        node110->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(22011, 110, node110)
    }
    if (noInit == true) {
        return node110;
    }
    return node110;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(22011, 111) {
}

REGISTER_CREATE_SKILL_NODE(22011, 111) {
    auto node111 = GET_SKILL_NODE(111, PhaseNode_EndPhase);
    if (node111 == nullptr) {
        node111 = new PhaseNode_EndPhase(111, phase);
        node111->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node111->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(22011, 111, node111)
    }
    if (noInit == true) {
        return node111;
    }
    return node111;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22011, 113) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_Delay::TRIGGER_DONE, 114, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(22011, 113) {
    auto node113 = GET_SKILL_NODE(113, PhaseNode_Delay);
    if (node113 == nullptr) {
        node113 = new PhaseNode_Delay(113, phase);
        node113->setTime(.20f);
        CALL_REGISTER_SKILL_NODE(22011, 113, node113)
    }
    if (noInit == true) {
        return node113;
    }
    return node113;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(22011, 114) {
}

REGISTER_CREATE_SKILL_NODE(22011, 114) {
    auto node114 = GET_SKILL_NODE(114, PhaseNode_PlaySound);
    if (node114 == nullptr) {
        node114 = new PhaseNode_PlaySound(114, phase);
        node114->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node114->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node114->setSoundID("SE_MON2201_ATK2_P1");
        node114->setTarget(0U);
        node114->setUsePos(false);
        node114->setPosX(.00f);
        node114->setPosY(.00f);
        node114->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(22011, 114, node114)
    }
    if (noInit == true) {
        return node114;
    }
    return node114;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22011, 115) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_Delay::TRIGGER_DONE, 116, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(22011, 115) {
    auto node115 = GET_SKILL_NODE(115, PhaseNode_Delay);
    if (node115 == nullptr) {
        node115 = new PhaseNode_Delay(115, phase);
        node115->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(22011, 115, node115)
    }
    if (noInit == true) {
        return node115;
    }
    return node115;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(22011, 116) {
}

REGISTER_CREATE_SKILL_NODE(22011, 116) {
    auto node116 = GET_SKILL_NODE(116, PhaseNode_PlaySound);
    if (node116 == nullptr) {
        node116 = new PhaseNode_PlaySound(116, phase);
        node116->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node116->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node116->setSoundID("VO_MON2201_ATK");
        node116->setTarget(0U);
        node116->setUsePos(false);
        node116->setPosX(.00f);
        node116->setPosY(.00f);
        node116->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(22011, 116, node116)
    }
    if (noInit == true) {
        return node116;
    }
    return node116;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22011, 117) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_Delay::TRIGGER_DONE, 119, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(22011, 117) {
    auto node117 = GET_SKILL_NODE(117, PhaseNode_Delay);
    if (node117 == nullptr) {
        node117 = new PhaseNode_Delay(117, phase);
        node117->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(22011, 117, node117)
    }
    if (noInit == true) {
        return node117;
    }
    return node117;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(22011, 118) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 111, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(22011, 118) {
    auto node118 = GET_SKILL_NODE(118, PhaseNode_SkillEndNotify);
    if (node118 == nullptr) {
        node118 = new PhaseNode_SkillEndNotify(118, phase);
        node118->setReturnType(false);
        CALL_REGISTER_SKILL_NODE(22011, 118, node118)
    }
    if (noInit == true) {
        return node118;
    }
    return node118;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(22011, 119) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_FALSE, 120, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_TRUE, 118, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
}

REGISTER_CREATE_SKILL_NODE(22011, 119) {
    auto node119 = GET_SKILL_NODE(119, PhaseNode_If);
    if (node119 == nullptr) {
        node119 = new PhaseNode_If(119, phase);
        node119->setCondition(false);
        CALL_REGISTER_SKILL_NODE(22011, 119, node119)
    }
    if (noInit == true) {
        return node119;
    }
    return node119;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(22011, 120) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 111, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(22011, 120) {
    auto node120 = GET_SKILL_NODE(120, PhaseNode_SkillEndNotify);
    if (node120 == nullptr) {
        node120 = new PhaseNode_SkillEndNotify(120, phase);
        node120->setReturnType(true);
        CALL_REGISTER_SKILL_NODE(22011, 120, node120)
    }
    if (noInit == true) {
        return node120;
    }
    return node120;
}

//--------------------------------------------------------------------------------
// SkillCreator_22011
//
class SkillCreator_22011 : public SkillCreator {
public:
    SkillCreator_22011() {}
    virtual ~SkillCreator_22011() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_22011

//--------------------------------------------------------------------------------
// SkillPhase_22011
//
class SkillPhase_22011 : public SkillPhase {
public:
    SkillPhase_22011(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_22011() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(22011, 1) // StartPhase
        CASE_CREATE_SKILL_NODE(22011, 2) // TriggerUpdate
        CASE_CREATE_SKILL_NODE(22011, 7) // Delay
        CASE_CREATE_SKILL_NODE(22011, 8) // SpawnCollider
        CASE_CREATE_SKILL_NODE(22011, 20) // EndPhase
        CASE_CREATE_SKILL_NODE(22011, 32) // Detect
        CASE_CREATE_SKILL_NODE(22011, 38) // EndPhase
        CASE_CREATE_SKILL_NODE(22011, 65) // PlaySound
        CASE_CREATE_SKILL_NODE(22011, 69) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(22011, 70) // TriggerCheck
        CASE_CREATE_SKILL_NODE(22011, 71) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(22011, 72) // GetActorAttribute
        CASE_CREATE_SKILL_NODE(22011, 73) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(22011, 74) // CompareFloat
        CASE_CREATE_SKILL_NODE(22011, 75) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(22011, 76) // If
        CASE_CREATE_SKILL_NODE(22011, 77) // CompareFloat
        CASE_CREATE_SKILL_NODE(22011, 78) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(22011, 79) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(22011, 80) // TriggerCheck
        CASE_CREATE_SKILL_NODE(22011, 81) // TriggerCheck
        CASE_CREATE_SKILL_NODE(22011, 82) // TriggerCheck
        CASE_CREATE_SKILL_NODE(22011, 83) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(22011, 84) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(22011, 85) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(22011, 86) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(22011, 87) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(22011, 88) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(22011, 89) // Delay
        CASE_CREATE_SKILL_NODE(22011, 90) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(22011, 91) // If
        CASE_CREATE_SKILL_NODE(22011, 92) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(22011, 93) // GetLocation
        CASE_CREATE_SKILL_NODE(22011, 94) // GetRotation
        CASE_CREATE_SKILL_NODE(22011, 95) // OffsetCalculate
        CASE_CREATE_SKILL_NODE(22011, 96) // PlayEffect
        CASE_CREATE_SKILL_NODE(22011, 97) // If
        CASE_CREATE_SKILL_NODE(22011, 98) // PlayEffect
        CASE_CREATE_SKILL_NODE(22011, 99) // CompareFloat
        CASE_CREATE_SKILL_NODE(22011, 100) // Delay
        CASE_CREATE_SKILL_NODE(22011, 101) // StopEffect
        CASE_CREATE_SKILL_NODE(22011, 102) // ResetCD
        CASE_CREATE_SKILL_NODE(22011, 103) // PlayAnimation
        CASE_CREATE_SKILL_NODE(22011, 104) // PlaySound
        CASE_CREATE_SKILL_NODE(22011, 105) // Delay
        CASE_CREATE_SKILL_NODE(22011, 106) // GetLocation
        CASE_CREATE_SKILL_NODE(22011, 107) // GetRotation
        CASE_CREATE_SKILL_NODE(22011, 108) // OffsetCalculate
        CASE_CREATE_SKILL_NODE(22011, 109) // RaiseEvent
        CASE_CREATE_SKILL_NODE(22011, 110) // Detect
        CASE_CREATE_SKILL_NODE(22011, 111) // EndPhase
        CASE_CREATE_SKILL_NODE(22011, 113) // Delay
        CASE_CREATE_SKILL_NODE(22011, 114) // PlaySound
        CASE_CREATE_SKILL_NODE(22011, 115) // Delay
        CASE_CREATE_SKILL_NODE(22011, 116) // PlaySound
        CASE_CREATE_SKILL_NODE(22011, 117) // Delay
        CASE_CREATE_SKILL_NODE(22011, 118) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(22011, 119) // If
        CASE_CREATE_SKILL_NODE(22011, 120) // SkillEndNotify
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_22011

SkillLogic* SkillCreator_22011::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //创建阶段phase
    auto phase = new SkillPhase_22011(1, logic, 3);
    //设置phase执行器
    phase->setRunPhaseNode(1, 1);
    phase->setRunPhaseNode(2, 2);
    phase->setDetectPhaseNode(3, 32);
    phase->setDetectPhaseNode(3, 110);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_22011::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
