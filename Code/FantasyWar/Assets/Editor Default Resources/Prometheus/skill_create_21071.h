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
REGISTER_REGISTER_SKILL_NODE(21071, 1) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_StartPhase::TRIGGER_START, 202, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_StartPhase::TRIGGER_START, 179, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(21071, 1) {
    auto node1 = GET_SKILL_NODE(1, PhaseNode_StartPhase);
    if (node1 == nullptr) {
        node1 = new PhaseNode_StartPhase(1, phase);
        CALL_REGISTER_SKILL_NODE(21071, 1, node1)
    }
    if (noInit == true) {
        return node1;
    }
    return node1;
}
//--------------------------------------------------------------------------------
// TriggerUpdate
//
REGISTER_REGISTER_SKILL_NODE(21071, 2) {
}

REGISTER_CREATE_SKILL_NODE(21071, 2) {
    auto node2 = GET_SKILL_NODE(2, PhaseNode_TriggerUpdate);
    if (node2 == nullptr) {
        node2 = new PhaseNode_TriggerUpdate(2, phase);
        CALL_REGISTER_SKILL_NODE(21071, 2, node2)
    }
    if (noInit == true) {
        return node2;
    }
    return node2;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(21071, 7) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlayAnimation::TRIGGER_DONE, 14, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(21071, 7) {
    auto node7 = GET_SKILL_NODE(7, PhaseNode_PlayAnimation);
    if (node7 == nullptr) {
        node7 = new PhaseNode_PlayAnimation(7, phase);
        node7->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node7->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node7->setTarget(0U);
        node7->setAnimation("Skill1S1");
        node7->setParameter("");
        node7->setValue(false);
        CALL_REGISTER_SKILL_NODE(21071, 7, node7)
    }
    if (noInit == true) {
        return node7;
    }
    return node7;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(21071, 11) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_Delay::TRIGGER_DONE, 7, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(21071, 11) {
    auto node11 = GET_SKILL_NODE(11, PhaseNode_Delay);
    if (node11 == nullptr) {
        node11 = new PhaseNode_Delay(11, phase);
        node11->setTime(.30f);
        CALL_REGISTER_SKILL_NODE(21071, 11, node11)
    }
    if (noInit == true) {
        return node11;
    }
    return node11;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(21071, 14) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_Delay::TRIGGER_DONE, 189, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(21071, 14) {
    auto node14 = GET_SKILL_NODE(14, PhaseNode_Delay);
    if (node14 == nullptr) {
        node14 = new PhaseNode_Delay(14, phase);
        node14->setTime(.70f);
        CALL_REGISTER_SKILL_NODE(21071, 14, node14)
    }
    if (noInit == true) {
        return node14;
    }
    return node14;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(21071, 16) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_Detect::TRIGGER_ON, 103, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(21071, 16) {
    auto node16 = GET_SKILL_NODE(16, PhaseNode_Detect);
    if (node16 == nullptr) {
        node16 = new PhaseNode_Detect(16, phase);
        node16->setSelf(0U);
        node16->setEvent("");
        node16->setType(PhaseNode_Detect::Detect_Type::Actor_Dead);
        node16->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(21071, 16, node16)
    }
    if (noInit == true) {
        return node16;
    }
    return node16;
}
//--------------------------------------------------------------------------------
// SpawnCollider
//
REGISTER_REGISTER_SKILL_NODE(21071, 26) {
    pnode->resizeTrigger(PhaseNode_SpawnCollider::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_SpawnCollider::TRIGGER_DONE, 198, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_SpawnCollider::TRIGGER_DONE, 157, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(21071, 26) {
    auto node26 = GET_SKILL_NODE(26, PhaseNode_SpawnCollider);
    if (node26 == nullptr) {
        node26 = new PhaseNode_SpawnCollider(26, phase);
        node26->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node26->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node26->setMesh("");
        node26->setMeshScale(.00f);
        node26->setEffectID(0);
        node26->setEffectScale(.00f);
        node26->setType(PhaseNode_SpawnCollider::SpawnCollider_Type::Circle);
        node26->setTypeParams(0, 3.00f);
        node26->setTime(.20f);
        node26->setPosZ(.00f);
        node26->setRotation(.00f);
        node26->setreentry(false);
        node26->setCheckPeneSound(false);
        CALL_REGISTER_SKILL_NODE(21071, 26, node26)
    }
    if (noInit == true) {
        return node26;
    }
    auto node191 = GET_SKILL_NODE(191, PhaseNode_OffsetCalculate);
    if (node191 != nullptr) node26->setPosX(node191->getOutPosX());
    if (node191 != nullptr) node26->setPosY(node191->getOutPosY());
    return node26;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(21071, 28) {
}

REGISTER_CREATE_SKILL_NODE(21071, 28) {
    auto node28 = GET_SKILL_NODE(28, PhaseNode_EndPhase);
    if (node28 == nullptr) {
        node28 = new PhaseNode_EndPhase(28, phase);
        node28->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node28->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(21071, 28, node28)
    }
    if (noInit == true) {
        return node28;
    }
    return node28;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(21071, 103) {
}

REGISTER_CREATE_SKILL_NODE(21071, 103) {
    auto node103 = GET_SKILL_NODE(103, PhaseNode_EndPhase);
    if (node103 == nullptr) {
        node103 = new PhaseNode_EndPhase(103, phase);
        node103->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node103->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(21071, 103, node103)
    }
    if (noInit == true) {
        return node103;
    }
    return node103;
}
//--------------------------------------------------------------------------------
// DestroyActor
//
REGISTER_REGISTER_SKILL_NODE(21071, 148) {
    pnode->resizeTrigger(PhaseNode_DestroyActor::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_DestroyActor::TRIGGER_DONE, 28, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(21071, 148) {
    auto node148 = GET_SKILL_NODE(148, PhaseNode_DestroyActor);
    if (node148 == nullptr) {
        node148 = new PhaseNode_DestroyActor(148, phase);
        node148->setActorID(0U);
        CALL_REGISTER_SKILL_NODE(21071, 148, node148)
    }
    if (noInit == true) {
        return node148;
    }
    return node148;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(21071, 150) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 162, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 164, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(21071, 150) {
    auto node150 = GET_SKILL_NODE(150, PhaseNode_CreateTriggerNewPene);
    if (node150 == nullptr) {
        node150 = new PhaseNode_CreateTriggerNewPene(150, phase);
        node150->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::In);
        node150->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node150->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Enemy);
        node150->setOnHero(true);
        node150->setOnMinion(true);
        node150->setOnDestruct(true);
        node150->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(21071, 150, node150)
    }
    if (noInit == true) {
        return node150;
    }
    auto node26 = GET_SKILL_NODE(26, PhaseNode_SpawnCollider);
    if (node26 != nullptr) node150->setColliderID(node26->getColliderID());
    return node150;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(21071, 151) {
}

REGISTER_CREATE_SKILL_NODE(21071, 151) {
    auto node151 = GET_SKILL_NODE(151, PhaseNode_TriggerCheck);
    if (node151 == nullptr) {
        node151 = new PhaseNode_TriggerCheck(151, phase);
        auto node2 = GET_SKILL_NODE(2, PhaseNode_TriggerUpdate);
        if (node2 != nullptr) node2->addTriggerCheck(node151);
        
        CALL_REGISTER_SKILL_NODE(21071, 151, node151)
    }
    if (noInit == true) {
        return node151;
    }
    auto node160 = GET_SKILL_NODE(160, PhaseNode_CreateTriggerNewPene);
    if (node160 != nullptr) node151->setTrigger(0, node160->getTriggerID());
    return node151;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(21071, 152) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 153, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(21071, 152) {
    auto node152 = GET_SKILL_NODE(152, PhaseNode_ActorFilterNewPene);
    if (node152 == nullptr) {
        node152 = new PhaseNode_ActorFilterNewPene(152, phase);
        node152->setHero(true);
        node152->setMinion(true);
        node152->setDestruct(true);
        node152->setShield(false);
        node152->setTotalCount(0);
        node152->setPerCount(1);
        CALL_REGISTER_SKILL_NODE(21071, 152, node152)
    }
    if (noInit == true) {
        return node152;
    }
    auto node156 = GET_SKILL_NODE(156, PhaseNode_CreateTriggerNewPene);
    if (node156 != nullptr) node152->setInput(node156->getOther());
    return node152;
}
//--------------------------------------------------------------------------------
// GetActorAttribute
//
REGISTER_REGISTER_SKILL_NODE(21071, 153) {
    pnode->resizeTrigger(PhaseNode_GetActorAttribute::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 154, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 167, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 168, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 169, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
}

REGISTER_CREATE_SKILL_NODE(21071, 153) {
    auto node153 = GET_SKILL_NODE(153, PhaseNode_GetActorAttribute);
    if (node153 == nullptr) {
        node153 = new PhaseNode_GetActorAttribute(153, phase);
        node153->setTarget(0U);
        node153->setType({202});
        CALL_REGISTER_SKILL_NODE(21071, 153, node153)
    }
    if (noInit == true) {
        return node153;
    }
    return node153;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(21071, 154) {
}

REGISTER_CREATE_SKILL_NODE(21071, 154) {
    auto node154 = GET_SKILL_NODE(154, PhaseNode_AddSkillBuffs);
    if (node154 == nullptr) {
        node154 = new PhaseNode_AddSkillBuffs(154, phase);
        node154->setConfigID({11});
        CALL_REGISTER_SKILL_NODE(21071, 154, node154)
    }
    if (noInit == true) {
        return node154;
    }
    auto node152 = GET_SKILL_NODE(152, PhaseNode_ActorFilterNewPene);
    auto node153 = GET_SKILL_NODE(153, PhaseNode_GetActorAttribute);
    if (node152 != nullptr) node154->setTarget(node152->getOutput());
    if (node153 != nullptr) node154->setAttribute(node153->getAttribute());
    return node154;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(21071, 155) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 150, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_LESS, 156, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
}

REGISTER_CREATE_SKILL_NODE(21071, 155) {
    auto node155 = GET_SKILL_NODE(155, PhaseNode_CompareFloat);
    if (node155 == nullptr) {
        node155 = new PhaseNode_CompareFloat(155, phase);
        node155->setA(.00f);
        node155->setB(.00f);
        CALL_REGISTER_SKILL_NODE(21071, 155, node155)
    }
    if (noInit == true) {
        return node155;
    }
    return node155;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(21071, 156) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 161, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 152, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(21071, 156) {
    auto node156 = GET_SKILL_NODE(156, PhaseNode_CreateTriggerNewPene);
    if (node156 == nullptr) {
        node156 = new PhaseNode_CreateTriggerNewPene(156, phase);
        node156->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::Tick);
        node156->setTypeParams(0, .00f);
        node156->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node156->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Enemy);
        node156->setOnHero(true);
        node156->setOnMinion(true);
        node156->setOnDestruct(true);
        node156->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(21071, 156, node156)
    }
    if (noInit == true) {
        return node156;
    }
    auto node26 = GET_SKILL_NODE(26, PhaseNode_SpawnCollider);
    if (node26 != nullptr) node156->setColliderID(node26->getColliderID());
    return node156;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(21071, 157) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_If::TRIGGER_FALSE, 158, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_If::TRIGGER_TRUE, 155, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(21071, 157) {
    auto node157 = GET_SKILL_NODE(157, PhaseNode_If);
    if (node157 == nullptr) {
        node157 = new PhaseNode_If(157, phase);
        node157->setCondition(false);
        CALL_REGISTER_SKILL_NODE(21071, 157, node157)
    }
    if (noInit == true) {
        return node157;
    }
    return node157;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(21071, 158) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 160, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_LESS, 159, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
}

REGISTER_CREATE_SKILL_NODE(21071, 158) {
    auto node158 = GET_SKILL_NODE(158, PhaseNode_CompareFloat);
    if (node158 == nullptr) {
        node158 = new PhaseNode_CompareFloat(158, phase);
        node158->setA(.00f);
        node158->setB(.00f);
        CALL_REGISTER_SKILL_NODE(21071, 158, node158)
    }
    if (noInit == true) {
        return node158;
    }
    return node158;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(21071, 159) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 163, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 165, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(21071, 159) {
    auto node159 = GET_SKILL_NODE(159, PhaseNode_CreateTriggerNewPene);
    if (node159 == nullptr) {
        node159 = new PhaseNode_CreateTriggerNewPene(159, phase);
        node159->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::Tick);
        node159->setTypeParams(0, .00f);
        node159->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node159->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Friend);
        node159->setOnHero(true);
        node159->setOnMinion(true);
        node159->setOnDestruct(true);
        node159->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(21071, 159, node159)
    }
    if (noInit == true) {
        return node159;
    }
    auto node26 = GET_SKILL_NODE(26, PhaseNode_SpawnCollider);
    if (node26 != nullptr) node159->setColliderID(node26->getColliderID());
    return node159;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(21071, 160) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 151, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 166, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(21071, 160) {
    auto node160 = GET_SKILL_NODE(160, PhaseNode_CreateTriggerNewPene);
    if (node160 == nullptr) {
        node160 = new PhaseNode_CreateTriggerNewPene(160, phase);
        node160->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::In);
        node160->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node160->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Friend);
        node160->setOnHero(true);
        node160->setOnMinion(true);
        node160->setOnDestruct(true);
        node160->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(21071, 160, node160)
    }
    if (noInit == true) {
        return node160;
    }
    auto node26 = GET_SKILL_NODE(26, PhaseNode_SpawnCollider);
    if (node26 != nullptr) node160->setColliderID(node26->getColliderID());
    return node160;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(21071, 161) {
}

REGISTER_CREATE_SKILL_NODE(21071, 161) {
    auto node161 = GET_SKILL_NODE(161, PhaseNode_TriggerCheck);
    if (node161 == nullptr) {
        node161 = new PhaseNode_TriggerCheck(161, phase);
        auto node2 = GET_SKILL_NODE(2, PhaseNode_TriggerUpdate);
        if (node2 != nullptr) node2->addTriggerCheck(node161);
        
        CALL_REGISTER_SKILL_NODE(21071, 161, node161)
    }
    if (noInit == true) {
        return node161;
    }
    auto node156 = GET_SKILL_NODE(156, PhaseNode_CreateTriggerNewPene);
    if (node156 != nullptr) node161->setTrigger(0, node156->getTriggerID());
    return node161;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(21071, 162) {
}

REGISTER_CREATE_SKILL_NODE(21071, 162) {
    auto node162 = GET_SKILL_NODE(162, PhaseNode_TriggerCheck);
    if (node162 == nullptr) {
        node162 = new PhaseNode_TriggerCheck(162, phase);
        auto node2 = GET_SKILL_NODE(2, PhaseNode_TriggerUpdate);
        if (node2 != nullptr) node2->addTriggerCheck(node162);
        
        CALL_REGISTER_SKILL_NODE(21071, 162, node162)
    }
    if (noInit == true) {
        return node162;
    }
    auto node150 = GET_SKILL_NODE(150, PhaseNode_CreateTriggerNewPene);
    if (node150 != nullptr) node162->setTrigger(0, node150->getTriggerID());
    return node162;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(21071, 163) {
}

REGISTER_CREATE_SKILL_NODE(21071, 163) {
    auto node163 = GET_SKILL_NODE(163, PhaseNode_TriggerCheck);
    if (node163 == nullptr) {
        node163 = new PhaseNode_TriggerCheck(163, phase);
        auto node2 = GET_SKILL_NODE(2, PhaseNode_TriggerUpdate);
        if (node2 != nullptr) node2->addTriggerCheck(node163);
        
        CALL_REGISTER_SKILL_NODE(21071, 163, node163)
    }
    if (noInit == true) {
        return node163;
    }
    auto node159 = GET_SKILL_NODE(159, PhaseNode_CreateTriggerNewPene);
    if (node159 != nullptr) node163->setTrigger(0, node159->getTriggerID());
    return node163;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(21071, 164) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 153, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(21071, 164) {
    auto node164 = GET_SKILL_NODE(164, PhaseNode_ActorFilterNewPene);
    if (node164 == nullptr) {
        node164 = new PhaseNode_ActorFilterNewPene(164, phase);
        node164->setHero(true);
        node164->setMinion(true);
        node164->setDestruct(true);
        node164->setShield(false);
        node164->setTotalCount(0);
        node164->setPerCount(1);
        CALL_REGISTER_SKILL_NODE(21071, 164, node164)
    }
    if (noInit == true) {
        return node164;
    }
    auto node150 = GET_SKILL_NODE(150, PhaseNode_CreateTriggerNewPene);
    if (node150 != nullptr) node164->setInput(node150->getOther());
    return node164;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(21071, 165) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 153, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(21071, 165) {
    auto node165 = GET_SKILL_NODE(165, PhaseNode_ActorFilterNewPene);
    if (node165 == nullptr) {
        node165 = new PhaseNode_ActorFilterNewPene(165, phase);
        node165->setHero(true);
        node165->setMinion(true);
        node165->setDestruct(true);
        node165->setShield(false);
        node165->setTotalCount(0);
        node165->setPerCount(1);
        CALL_REGISTER_SKILL_NODE(21071, 165, node165)
    }
    if (noInit == true) {
        return node165;
    }
    auto node159 = GET_SKILL_NODE(159, PhaseNode_CreateTriggerNewPene);
    if (node159 != nullptr) node165->setInput(node159->getOther());
    return node165;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(21071, 166) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 153, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(21071, 166) {
    auto node166 = GET_SKILL_NODE(166, PhaseNode_ActorFilterNewPene);
    if (node166 == nullptr) {
        node166 = new PhaseNode_ActorFilterNewPene(166, phase);
        node166->setHero(true);
        node166->setMinion(true);
        node166->setDestruct(true);
        node166->setShield(false);
        node166->setTotalCount(0);
        node166->setPerCount(1);
        CALL_REGISTER_SKILL_NODE(21071, 166, node166)
    }
    if (noInit == true) {
        return node166;
    }
    auto node160 = GET_SKILL_NODE(160, PhaseNode_CreateTriggerNewPene);
    if (node160 != nullptr) node166->setInput(node160->getOther());
    return node166;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(21071, 167) {
}

REGISTER_CREATE_SKILL_NODE(21071, 167) {
    auto node167 = GET_SKILL_NODE(167, PhaseNode_AddSkillBuffs);
    if (node167 == nullptr) {
        node167 = new PhaseNode_AddSkillBuffs(167, phase);
        node167->setConfigID({11});
        CALL_REGISTER_SKILL_NODE(21071, 167, node167)
    }
    if (noInit == true) {
        return node167;
    }
    auto node164 = GET_SKILL_NODE(164, PhaseNode_ActorFilterNewPene);
    auto node153 = GET_SKILL_NODE(153, PhaseNode_GetActorAttribute);
    if (node164 != nullptr) node167->setTarget(node164->getOutput());
    if (node153 != nullptr) node167->setAttribute(node153->getAttribute());
    return node167;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(21071, 168) {
}

REGISTER_CREATE_SKILL_NODE(21071, 168) {
    auto node168 = GET_SKILL_NODE(168, PhaseNode_AddSkillBuffs);
    if (node168 == nullptr) {
        node168 = new PhaseNode_AddSkillBuffs(168, phase);
        node168->setConfigID({11});
        CALL_REGISTER_SKILL_NODE(21071, 168, node168)
    }
    if (noInit == true) {
        return node168;
    }
    auto node165 = GET_SKILL_NODE(165, PhaseNode_ActorFilterNewPene);
    auto node153 = GET_SKILL_NODE(153, PhaseNode_GetActorAttribute);
    if (node165 != nullptr) node168->setTarget(node165->getOutput());
    if (node153 != nullptr) node168->setAttribute(node153->getAttribute());
    return node168;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(21071, 169) {
}

REGISTER_CREATE_SKILL_NODE(21071, 169) {
    auto node169 = GET_SKILL_NODE(169, PhaseNode_AddSkillBuffs);
    if (node169 == nullptr) {
        node169 = new PhaseNode_AddSkillBuffs(169, phase);
        node169->setConfigID({11});
        CALL_REGISTER_SKILL_NODE(21071, 169, node169)
    }
    if (noInit == true) {
        return node169;
    }
    auto node166 = GET_SKILL_NODE(166, PhaseNode_ActorFilterNewPene);
    auto node153 = GET_SKILL_NODE(153, PhaseNode_GetActorAttribute);
    if (node166 != nullptr) node169->setTarget(node166->getOutput());
    if (node153 != nullptr) node169->setAttribute(node153->getAttribute());
    return node169;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(21071, 170) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetRotation>(PhaseNode_GetLocation::TRIGGER_DONE, 171, PhaseNode_GetRotation::FUNC_DO, &PhaseNode_GetRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(21071, 170) {
    auto node170 = GET_SKILL_NODE(170, PhaseNode_GetLocation);
    if (node170 == nullptr) {
        node170 = new PhaseNode_GetLocation(170, phase);
        node170->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node170->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(21071, 170, node170)
    }
    if (noInit == true) {
        return node170;
    }
    return node170;
}
//--------------------------------------------------------------------------------
// GetRotation
//
REGISTER_REGISTER_SKILL_NODE(21071, 171) {
    pnode->resizeTrigger(PhaseNode_GetRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_OffsetCalculate>(PhaseNode_GetRotation::TRIGGER_DONE, 172, PhaseNode_OffsetCalculate::FUNC_DO, &PhaseNode_OffsetCalculate::Do);
}

REGISTER_CREATE_SKILL_NODE(21071, 171) {
    auto node171 = GET_SKILL_NODE(171, PhaseNode_GetRotation);
    if (node171 == nullptr) {
        node171 = new PhaseNode_GetRotation(171, phase);
        node171->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node171->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(21071, 171, node171)
    }
    if (noInit == true) {
        return node171;
    }
    return node171;
}
//--------------------------------------------------------------------------------
// OffsetCalculate
//
REGISTER_REGISTER_SKILL_NODE(21071, 172) {
    pnode->resizeTrigger(PhaseNode_OffsetCalculate::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 174, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(21071, 172) {
    auto node172 = GET_SKILL_NODE(172, PhaseNode_OffsetCalculate);
    if (node172 == nullptr) {
        node172 = new PhaseNode_OffsetCalculate(172, phase);
        node172->setPosZ(.00f);
        node172->setOffsetX(.00f);
        node172->setOffsetY(.00f);
        node172->setOffsetZ(.20f);
        node172->setRotOffset(.00f);
        CALL_REGISTER_SKILL_NODE(21071, 172, node172)
    }
    if (noInit == true) {
        return node172;
    }
    auto node170 = GET_SKILL_NODE(170, PhaseNode_GetLocation);
    auto node171 = GET_SKILL_NODE(171, PhaseNode_GetRotation);
    if (node170 != nullptr) node172->setPosX(node170->getX());
    if (node170 != nullptr) node172->setPosY(node170->getY());
    if (node171 != nullptr) node172->setRotation(node171->getAngle());
    return node172;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(21071, 173) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_PlayEffect::TRIGGER_DONE, 176, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(21071, 173) {
    auto node173 = GET_SKILL_NODE(173, PhaseNode_PlayEffect);
    if (node173 == nullptr) {
        node173 = new PhaseNode_PlayEffect(173, phase);
        node173->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node173->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node173->setEffectID(1014);
        node173->setChangeColor(false);
        node173->setType(PhaseNode_PlayEffect::PlayEffect_Type::WithTarget);
        node173->getVars().reserve(5);
        node173->getVars().setVariable<uint64_t>(0, 0U);
        node173->getVars().setVariable<std::string>(1, "");
        node173->getVars().setVariable<float>(2, .00f);
        node173->getVars().setVariable<float>(3, .00f);
        node173->getVars().setVariable<float>(4, .00f);
        node173->setRotation(.00f);
        node173->setScale(1.50f);
        CALL_REGISTER_SKILL_NODE(21071, 173, node173)
    }
    if (noInit == true) {
        return node173;
    }
    auto node172 = GET_SKILL_NODE(172, PhaseNode_OffsetCalculate);
    if (node172 != nullptr) node173->getVars().setVariable<float>(2, node172->getOutPosX());
    if (node172 != nullptr) node173->getVars().setVariable<float>(3, node172->getOutPosY());
    if (node172 != nullptr) node173->getVars().setVariable<float>(4, node172->getOutPosZ());
    return node173;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(21071, 174) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_FALSE, 175, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_TRUE, 173, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(21071, 174) {
    auto node174 = GET_SKILL_NODE(174, PhaseNode_If);
    if (node174 == nullptr) {
        node174 = new PhaseNode_If(174, phase);
        node174->setCondition(false);
        CALL_REGISTER_SKILL_NODE(21071, 174, node174)
    }
    if (noInit == true) {
        return node174;
    }
    return node174;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(21071, 175) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_PlayEffect::TRIGGER_DONE, 176, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(21071, 175) {
    auto node175 = GET_SKILL_NODE(175, PhaseNode_PlayEffect);
    if (node175 == nullptr) {
        node175 = new PhaseNode_PlayEffect(175, phase);
        node175->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node175->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node175->setEffectID(1014);
        node175->setChangeColor(false);
        node175->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node175->getVars().reserve(3);
        node175->getVars().setVariable<float>(0, .00f);
        node175->getVars().setVariable<float>(1, .00f);
        node175->getVars().setVariable<float>(2, .00f);
        node175->setRotation(.00f);
        node175->setScale(1.50f);
        CALL_REGISTER_SKILL_NODE(21071, 175, node175)
    }
    if (noInit == true) {
        return node175;
    }
    auto node172 = GET_SKILL_NODE(172, PhaseNode_OffsetCalculate);
    if (node172 != nullptr) node175->getVars().setVariable<float>(0, node172->getOutPosX());
    if (node172 != nullptr) node175->getVars().setVariable<float>(1, node172->getOutPosY());
    if (node172 != nullptr) node175->getVars().setVariable<float>(2, node172->getOutPosZ());
    return node175;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(21071, 176) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 184, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_LESS, 177, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_CompareFloat::TRIGGER_LESS, 184, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(21071, 176) {
    auto node176 = GET_SKILL_NODE(176, PhaseNode_CompareFloat);
    if (node176 == nullptr) {
        node176 = new PhaseNode_CompareFloat(176, phase);
        node176->setA(.00f);
        node176->setB(1.00f);
        CALL_REGISTER_SKILL_NODE(21071, 176, node176)
    }
    if (noInit == true) {
        return node176;
    }
    return node176;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(21071, 177) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StopEffect>(PhaseNode_Delay::TRIGGER_DONE, 178, PhaseNode_StopEffect::FUNC_DO, &PhaseNode_StopEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(21071, 177) {
    auto node177 = GET_SKILL_NODE(177, PhaseNode_Delay);
    if (node177 == nullptr) {
        node177 = new PhaseNode_Delay(177, phase);
        node177->setTime(1.00f);
        CALL_REGISTER_SKILL_NODE(21071, 177, node177)
    }
    if (noInit == true) {
        return node177;
    }
    return node177;
}
//--------------------------------------------------------------------------------
// StopEffect
//
REGISTER_REGISTER_SKILL_NODE(21071, 178) {
}

REGISTER_CREATE_SKILL_NODE(21071, 178) {
    auto node178 = GET_SKILL_NODE(178, PhaseNode_StopEffect);
    if (node178 == nullptr) {
        node178 = new PhaseNode_StopEffect(178, phase);
        node178->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node178->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node178->setEffectID(1014);
        CALL_REGISTER_SKILL_NODE(21071, 178, node178)
    }
    if (noInit == true) {
        return node178;
    }
    return node178;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(21071, 179) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_ResetCD::TRIGGER_DONE, 180, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(21071, 179) {
    auto node179 = GET_SKILL_NODE(179, PhaseNode_ResetCD);
    if (node179 == nullptr) {
        node179 = new PhaseNode_ResetCD(179, phase);
        node179->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node179->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node179->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(21071, 179, node179)
    }
    if (noInit == true) {
        return node179;
    }
    return node179;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(21071, 180) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_PlayAnimation::TRIGGER_DONE, 181, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(21071, 180) {
    auto node180 = GET_SKILL_NODE(180, PhaseNode_PlayAnimation);
    if (node180 == nullptr) {
        node180 = new PhaseNode_PlayAnimation(180, phase);
        node180->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node180->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node180->setTarget(0U);
        node180->setAnimation("");
        node180->setParameter("");
        node180->setValue(false);
        CALL_REGISTER_SKILL_NODE(21071, 180, node180)
    }
    if (noInit == true) {
        return node180;
    }
    return node180;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(21071, 181) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlaySound::TRIGGER_DONE, 182, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(21071, 181) {
    auto node181 = GET_SKILL_NODE(181, PhaseNode_PlaySound);
    if (node181 == nullptr) {
        node181 = new PhaseNode_PlaySound(181, phase);
        node181->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node181->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node181->setSoundID("");
        node181->setTarget(0U);
        node181->setUsePos(false);
        node181->setPosX(.00f);
        node181->setPosY(.00f);
        node181->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(21071, 181, node181)
    }
    if (noInit == true) {
        return node181;
    }
    return node181;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(21071, 182) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_Delay::TRIGGER_DONE, 170, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(21071, 182) {
    auto node182 = GET_SKILL_NODE(182, PhaseNode_Delay);
    if (node182 == nullptr) {
        node182 = new PhaseNode_Delay(182, phase);
        node182->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(21071, 182, node182)
    }
    if (noInit == true) {
        return node182;
    }
    return node182;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(21071, 183) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_PlayEffect::TRIGGER_DONE, 186, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(21071, 183) {
    auto node183 = GET_SKILL_NODE(183, PhaseNode_PlayEffect);
    if (node183 == nullptr) {
        node183 = new PhaseNode_PlayEffect(183, phase);
        node183->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node183->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node183->setEffectID(210711);
        node183->setChangeColor(false);
        node183->setType(PhaseNode_PlayEffect::PlayEffect_Type::WithTarget);
        node183->getVars().reserve(5);
        node183->getVars().setVariable<uint64_t>(0, 0U);
        node183->getVars().setVariable<std::string>(1, "");
        node183->getVars().setVariable<float>(2, .00f);
        node183->getVars().setVariable<float>(3, .00f);
        node183->getVars().setVariable<float>(4, .00f);
        node183->setRotation(.00f);
        node183->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(21071, 183, node183)
    }
    if (noInit == true) {
        return node183;
    }
    auto node172 = GET_SKILL_NODE(172, PhaseNode_OffsetCalculate);
    if (node172 != nullptr) node183->getVars().setVariable<float>(2, node172->getOutPosX());
    if (node172 != nullptr) node183->getVars().setVariable<float>(3, node172->getOutPosY());
    return node183;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(21071, 184) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_FALSE, 185, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_TRUE, 183, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(21071, 184) {
    auto node184 = GET_SKILL_NODE(184, PhaseNode_If);
    if (node184 == nullptr) {
        node184 = new PhaseNode_If(184, phase);
        node184->setCondition(false);
        CALL_REGISTER_SKILL_NODE(21071, 184, node184)
    }
    if (noInit == true) {
        return node184;
    }
    return node184;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(21071, 185) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_PlayEffect::TRIGGER_DONE, 186, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(21071, 185) {
    auto node185 = GET_SKILL_NODE(185, PhaseNode_PlayEffect);
    if (node185 == nullptr) {
        node185 = new PhaseNode_PlayEffect(185, phase);
        node185->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node185->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node185->setEffectID(210711);
        node185->setChangeColor(false);
        node185->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node185->getVars().reserve(3);
        node185->getVars().setVariable<float>(0, .00f);
        node185->getVars().setVariable<float>(1, .00f);
        node185->getVars().setVariable<float>(2, .00f);
        node185->setRotation(.00f);
        node185->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(21071, 185, node185)
    }
    if (noInit == true) {
        return node185;
    }
    auto node172 = GET_SKILL_NODE(172, PhaseNode_OffsetCalculate);
    if (node172 != nullptr) node185->getVars().setVariable<float>(0, node172->getOutPosX());
    if (node172 != nullptr) node185->getVars().setVariable<float>(1, node172->getOutPosY());
    return node185;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(21071, 186) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 11, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_LESS, 11, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_LESS, 187, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(21071, 186) {
    auto node186 = GET_SKILL_NODE(186, PhaseNode_CompareFloat);
    if (node186 == nullptr) {
        node186 = new PhaseNode_CompareFloat(186, phase);
        node186->setA(.00f);
        node186->setB(.00f);
        CALL_REGISTER_SKILL_NODE(21071, 186, node186)
    }
    if (noInit == true) {
        return node186;
    }
    return node186;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(21071, 187) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StopEffect>(PhaseNode_Delay::TRIGGER_DONE, 188, PhaseNode_StopEffect::FUNC_DO, &PhaseNode_StopEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(21071, 187) {
    auto node187 = GET_SKILL_NODE(187, PhaseNode_Delay);
    if (node187 == nullptr) {
        node187 = new PhaseNode_Delay(187, phase);
        node187->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(21071, 187, node187)
    }
    if (noInit == true) {
        return node187;
    }
    return node187;
}
//--------------------------------------------------------------------------------
// StopEffect
//
REGISTER_REGISTER_SKILL_NODE(21071, 188) {
}

REGISTER_CREATE_SKILL_NODE(21071, 188) {
    auto node188 = GET_SKILL_NODE(188, PhaseNode_StopEffect);
    if (node188 == nullptr) {
        node188 = new PhaseNode_StopEffect(188, phase);
        node188->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node188->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node188->setEffectID(210711);
        CALL_REGISTER_SKILL_NODE(21071, 188, node188)
    }
    if (noInit == true) {
        return node188;
    }
    return node188;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(21071, 189) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetRotation>(PhaseNode_GetLocation::TRIGGER_DONE, 190, PhaseNode_GetRotation::FUNC_DO, &PhaseNode_GetRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(21071, 189) {
    auto node189 = GET_SKILL_NODE(189, PhaseNode_GetLocation);
    if (node189 == nullptr) {
        node189 = new PhaseNode_GetLocation(189, phase);
        node189->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node189->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(21071, 189, node189)
    }
    if (noInit == true) {
        return node189;
    }
    return node189;
}
//--------------------------------------------------------------------------------
// GetRotation
//
REGISTER_REGISTER_SKILL_NODE(21071, 190) {
    pnode->resizeTrigger(PhaseNode_GetRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_OffsetCalculate>(PhaseNode_GetRotation::TRIGGER_DONE, 191, PhaseNode_OffsetCalculate::FUNC_DO, &PhaseNode_OffsetCalculate::Do);
}

REGISTER_CREATE_SKILL_NODE(21071, 190) {
    auto node190 = GET_SKILL_NODE(190, PhaseNode_GetRotation);
    if (node190 == nullptr) {
        node190 = new PhaseNode_GetRotation(190, phase);
        node190->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node190->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(21071, 190, node190)
    }
    if (noInit == true) {
        return node190;
    }
    return node190;
}
//--------------------------------------------------------------------------------
// OffsetCalculate
//
REGISTER_REGISTER_SKILL_NODE(21071, 191) {
    pnode->resizeTrigger(PhaseNode_OffsetCalculate::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 193, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(21071, 191) {
    auto node191 = GET_SKILL_NODE(191, PhaseNode_OffsetCalculate);
    if (node191 == nullptr) {
        node191 = new PhaseNode_OffsetCalculate(191, phase);
        node191->setPosZ(.00f);
        node191->setOffsetX(.00f);
        node191->setOffsetY(.00f);
        node191->setOffsetZ(.00f);
        node191->setRotOffset(.00f);
        CALL_REGISTER_SKILL_NODE(21071, 191, node191)
    }
    if (noInit == true) {
        return node191;
    }
    auto node189 = GET_SKILL_NODE(189, PhaseNode_GetLocation);
    auto node190 = GET_SKILL_NODE(190, PhaseNode_GetRotation);
    if (node189 != nullptr) node191->setPosX(node189->getX());
    if (node189 != nullptr) node191->setPosY(node189->getY());
    if (node190 != nullptr) node191->setRotation(node190->getAngle());
    return node191;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(21071, 192) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_PlayEffect::TRIGGER_DONE, 195, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(21071, 192) {
    auto node192 = GET_SKILL_NODE(192, PhaseNode_PlayEffect);
    if (node192 == nullptr) {
        node192 = new PhaseNode_PlayEffect(192, phase);
        node192->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node192->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node192->setEffectID(210712);
        node192->setChangeColor(false);
        node192->setType(PhaseNode_PlayEffect::PlayEffect_Type::WithTarget);
        node192->getVars().reserve(5);
        node192->getVars().setVariable<uint64_t>(0, 0U);
        node192->getVars().setVariable<std::string>(1, "");
        node192->getVars().setVariable<float>(2, .00f);
        node192->getVars().setVariable<float>(3, .00f);
        node192->getVars().setVariable<float>(4, .00f);
        node192->setRotation(.00f);
        node192->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(21071, 192, node192)
    }
    if (noInit == true) {
        return node192;
    }
    auto node191 = GET_SKILL_NODE(191, PhaseNode_OffsetCalculate);
    if (node191 != nullptr) node192->getVars().setVariable<float>(2, node191->getOutPosX());
    if (node191 != nullptr) node192->getVars().setVariable<float>(3, node191->getOutPosY());
    return node192;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(21071, 193) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_FALSE, 194, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_TRUE, 192, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(21071, 193) {
    auto node193 = GET_SKILL_NODE(193, PhaseNode_If);
    if (node193 == nullptr) {
        node193 = new PhaseNode_If(193, phase);
        node193->setCondition(false);
        CALL_REGISTER_SKILL_NODE(21071, 193, node193)
    }
    if (noInit == true) {
        return node193;
    }
    return node193;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(21071, 194) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_PlayEffect::TRIGGER_DONE, 195, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(21071, 194) {
    auto node194 = GET_SKILL_NODE(194, PhaseNode_PlayEffect);
    if (node194 == nullptr) {
        node194 = new PhaseNode_PlayEffect(194, phase);
        node194->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node194->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node194->setEffectID(210712);
        node194->setChangeColor(false);
        node194->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node194->getVars().reserve(3);
        node194->getVars().setVariable<float>(0, .00f);
        node194->getVars().setVariable<float>(1, .00f);
        node194->getVars().setVariable<float>(2, .00f);
        node194->setRotation(.00f);
        node194->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(21071, 194, node194)
    }
    if (noInit == true) {
        return node194;
    }
    auto node191 = GET_SKILL_NODE(191, PhaseNode_OffsetCalculate);
    if (node191 != nullptr) node194->getVars().setVariable<float>(0, node191->getOutPosX());
    if (node191 != nullptr) node194->getVars().setVariable<float>(1, node191->getOutPosY());
    return node194;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(21071, 195) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnCollider>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 26, PhaseNode_SpawnCollider::FUNC_DO, &PhaseNode_SpawnCollider::Do);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_LESS, 196, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_SpawnCollider>(PhaseNode_CompareFloat::TRIGGER_LESS, 26, PhaseNode_SpawnCollider::FUNC_DO, &PhaseNode_SpawnCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(21071, 195) {
    auto node195 = GET_SKILL_NODE(195, PhaseNode_CompareFloat);
    if (node195 == nullptr) {
        node195 = new PhaseNode_CompareFloat(195, phase);
        node195->setA(.00f);
        node195->setB(.00f);
        CALL_REGISTER_SKILL_NODE(21071, 195, node195)
    }
    if (noInit == true) {
        return node195;
    }
    return node195;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(21071, 196) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StopEffect>(PhaseNode_Delay::TRIGGER_DONE, 197, PhaseNode_StopEffect::FUNC_DO, &PhaseNode_StopEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(21071, 196) {
    auto node196 = GET_SKILL_NODE(196, PhaseNode_Delay);
    if (node196 == nullptr) {
        node196 = new PhaseNode_Delay(196, phase);
        node196->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(21071, 196, node196)
    }
    if (noInit == true) {
        return node196;
    }
    return node196;
}
//--------------------------------------------------------------------------------
// StopEffect
//
REGISTER_REGISTER_SKILL_NODE(21071, 197) {
}

REGISTER_CREATE_SKILL_NODE(21071, 197) {
    auto node197 = GET_SKILL_NODE(197, PhaseNode_StopEffect);
    if (node197 == nullptr) {
        node197 = new PhaseNode_StopEffect(197, phase);
        node197->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node197->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node197->setEffectID(210712);
        CALL_REGISTER_SKILL_NODE(21071, 197, node197)
    }
    if (noInit == true) {
        return node197;
    }
    return node197;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(21071, 198) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_Delay::TRIGGER_DONE, 200, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(21071, 198) {
    auto node198 = GET_SKILL_NODE(198, PhaseNode_Delay);
    if (node198 == nullptr) {
        node198 = new PhaseNode_Delay(198, phase);
        node198->setTime(.20f);
        CALL_REGISTER_SKILL_NODE(21071, 198, node198)
    }
    if (noInit == true) {
        return node198;
    }
    return node198;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(21071, 199) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_DestroyActor>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 148, PhaseNode_DestroyActor::FUNC_DO, &PhaseNode_DestroyActor::Do);
}

REGISTER_CREATE_SKILL_NODE(21071, 199) {
    auto node199 = GET_SKILL_NODE(199, PhaseNode_SkillEndNotify);
    if (node199 == nullptr) {
        node199 = new PhaseNode_SkillEndNotify(199, phase);
        node199->setReturnType(false);
        CALL_REGISTER_SKILL_NODE(21071, 199, node199)
    }
    if (noInit == true) {
        return node199;
    }
    return node199;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(21071, 200) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_FALSE, 201, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_TRUE, 199, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
}

REGISTER_CREATE_SKILL_NODE(21071, 200) {
    auto node200 = GET_SKILL_NODE(200, PhaseNode_If);
    if (node200 == nullptr) {
        node200 = new PhaseNode_If(200, phase);
        node200->setCondition(false);
        CALL_REGISTER_SKILL_NODE(21071, 200, node200)
    }
    if (noInit == true) {
        return node200;
    }
    return node200;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(21071, 201) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_DestroyActor>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 148, PhaseNode_DestroyActor::FUNC_DO, &PhaseNode_DestroyActor::Do);
}

REGISTER_CREATE_SKILL_NODE(21071, 201) {
    auto node201 = GET_SKILL_NODE(201, PhaseNode_SkillEndNotify);
    if (node201 == nullptr) {
        node201 = new PhaseNode_SkillEndNotify(201, phase);
        node201->setReturnType(true);
        CALL_REGISTER_SKILL_NODE(21071, 201, node201)
    }
    if (noInit == true) {
        return node201;
    }
    return node201;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(21071, 202) {
}

REGISTER_CREATE_SKILL_NODE(21071, 202) {
    auto node202 = GET_SKILL_NODE(202, PhaseNode_RaiseEvent);
    if (node202 == nullptr) {
        node202 = new PhaseNode_RaiseEvent(202, phase);
        node202->setEvent("MonsterInterrupt");
        node202->setTarget(0U);
        node202->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node202->setTypeParams(0, 0);
        node202->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(21071, 202, node202)
    }
    if (noInit == true) {
        return node202;
    }
    return node202;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(21071, 203) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_Detect::TRIGGER_ON, 206, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(21071, 203) {
    auto node203 = GET_SKILL_NODE(203, PhaseNode_Detect);
    if (node203 == nullptr) {
        node203 = new PhaseNode_Detect(203, phase);
        node203->setSelf(0U);
        node203->setEvent("MonsterInterrupt");
        node203->setType(PhaseNode_Detect::Detect_Type::Interrupt_Skill);
        node203->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(21071, 203, node203)
    }
    if (noInit == true) {
        return node203;
    }
    return node203;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(21071, 204) {
}

REGISTER_CREATE_SKILL_NODE(21071, 204) {
    auto node204 = GET_SKILL_NODE(204, PhaseNode_EndPhase);
    if (node204 == nullptr) {
        node204 = new PhaseNode_EndPhase(204, phase);
        node204->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node204->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(21071, 204, node204)
    }
    if (noInit == true) {
        return node204;
    }
    return node204;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(21071, 206) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_Delay::TRIGGER_DONE, 208, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(21071, 206) {
    auto node206 = GET_SKILL_NODE(206, PhaseNode_Delay);
    if (node206 == nullptr) {
        node206 = new PhaseNode_Delay(206, phase);
        node206->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(21071, 206, node206)
    }
    if (noInit == true) {
        return node206;
    }
    return node206;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(21071, 207) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 204, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(21071, 207) {
    auto node207 = GET_SKILL_NODE(207, PhaseNode_SkillEndNotify);
    if (node207 == nullptr) {
        node207 = new PhaseNode_SkillEndNotify(207, phase);
        node207->setReturnType(false);
        CALL_REGISTER_SKILL_NODE(21071, 207, node207)
    }
    if (noInit == true) {
        return node207;
    }
    return node207;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(21071, 208) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_FALSE, 209, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_TRUE, 207, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
}

REGISTER_CREATE_SKILL_NODE(21071, 208) {
    auto node208 = GET_SKILL_NODE(208, PhaseNode_If);
    if (node208 == nullptr) {
        node208 = new PhaseNode_If(208, phase);
        node208->setCondition(false);
        CALL_REGISTER_SKILL_NODE(21071, 208, node208)
    }
    if (noInit == true) {
        return node208;
    }
    return node208;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(21071, 209) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 204, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(21071, 209) {
    auto node209 = GET_SKILL_NODE(209, PhaseNode_SkillEndNotify);
    if (node209 == nullptr) {
        node209 = new PhaseNode_SkillEndNotify(209, phase);
        node209->setReturnType(true);
        CALL_REGISTER_SKILL_NODE(21071, 209, node209)
    }
    if (noInit == true) {
        return node209;
    }
    return node209;
}

//--------------------------------------------------------------------------------
// SkillCreator_21071
//
class SkillCreator_21071 : public SkillCreator {
public:
    SkillCreator_21071() {}
    virtual ~SkillCreator_21071() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_21071

//--------------------------------------------------------------------------------
// SkillPhase_21071
//
class SkillPhase_21071 : public SkillPhase {
public:
    SkillPhase_21071(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_21071() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(21071, 1) // StartPhase
        CASE_CREATE_SKILL_NODE(21071, 2) // TriggerUpdate
        CASE_CREATE_SKILL_NODE(21071, 7) // PlayAnimation
        CASE_CREATE_SKILL_NODE(21071, 11) // Delay
        CASE_CREATE_SKILL_NODE(21071, 14) // Delay
        CASE_CREATE_SKILL_NODE(21071, 16) // Detect
        CASE_CREATE_SKILL_NODE(21071, 26) // SpawnCollider
        CASE_CREATE_SKILL_NODE(21071, 28) // EndPhase
        CASE_CREATE_SKILL_NODE(21071, 103) // EndPhase
        CASE_CREATE_SKILL_NODE(21071, 148) // DestroyActor
        CASE_CREATE_SKILL_NODE(21071, 150) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(21071, 151) // TriggerCheck
        CASE_CREATE_SKILL_NODE(21071, 152) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(21071, 153) // GetActorAttribute
        CASE_CREATE_SKILL_NODE(21071, 154) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(21071, 155) // CompareFloat
        CASE_CREATE_SKILL_NODE(21071, 156) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(21071, 157) // If
        CASE_CREATE_SKILL_NODE(21071, 158) // CompareFloat
        CASE_CREATE_SKILL_NODE(21071, 159) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(21071, 160) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(21071, 161) // TriggerCheck
        CASE_CREATE_SKILL_NODE(21071, 162) // TriggerCheck
        CASE_CREATE_SKILL_NODE(21071, 163) // TriggerCheck
        CASE_CREATE_SKILL_NODE(21071, 164) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(21071, 165) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(21071, 166) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(21071, 167) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(21071, 168) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(21071, 169) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(21071, 170) // GetLocation
        CASE_CREATE_SKILL_NODE(21071, 171) // GetRotation
        CASE_CREATE_SKILL_NODE(21071, 172) // OffsetCalculate
        CASE_CREATE_SKILL_NODE(21071, 173) // PlayEffect
        CASE_CREATE_SKILL_NODE(21071, 174) // If
        CASE_CREATE_SKILL_NODE(21071, 175) // PlayEffect
        CASE_CREATE_SKILL_NODE(21071, 176) // CompareFloat
        CASE_CREATE_SKILL_NODE(21071, 177) // Delay
        CASE_CREATE_SKILL_NODE(21071, 178) // StopEffect
        CASE_CREATE_SKILL_NODE(21071, 179) // ResetCD
        CASE_CREATE_SKILL_NODE(21071, 180) // PlayAnimation
        CASE_CREATE_SKILL_NODE(21071, 181) // PlaySound
        CASE_CREATE_SKILL_NODE(21071, 182) // Delay
        CASE_CREATE_SKILL_NODE(21071, 183) // PlayEffect
        CASE_CREATE_SKILL_NODE(21071, 184) // If
        CASE_CREATE_SKILL_NODE(21071, 185) // PlayEffect
        CASE_CREATE_SKILL_NODE(21071, 186) // CompareFloat
        CASE_CREATE_SKILL_NODE(21071, 187) // Delay
        CASE_CREATE_SKILL_NODE(21071, 188) // StopEffect
        CASE_CREATE_SKILL_NODE(21071, 189) // GetLocation
        CASE_CREATE_SKILL_NODE(21071, 190) // GetRotation
        CASE_CREATE_SKILL_NODE(21071, 191) // OffsetCalculate
        CASE_CREATE_SKILL_NODE(21071, 192) // PlayEffect
        CASE_CREATE_SKILL_NODE(21071, 193) // If
        CASE_CREATE_SKILL_NODE(21071, 194) // PlayEffect
        CASE_CREATE_SKILL_NODE(21071, 195) // CompareFloat
        CASE_CREATE_SKILL_NODE(21071, 196) // Delay
        CASE_CREATE_SKILL_NODE(21071, 197) // StopEffect
        CASE_CREATE_SKILL_NODE(21071, 198) // Delay
        CASE_CREATE_SKILL_NODE(21071, 199) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(21071, 200) // If
        CASE_CREATE_SKILL_NODE(21071, 201) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(21071, 202) // RaiseEvent
        CASE_CREATE_SKILL_NODE(21071, 203) // Detect
        CASE_CREATE_SKILL_NODE(21071, 204) // EndPhase
        CASE_CREATE_SKILL_NODE(21071, 206) // Delay
        CASE_CREATE_SKILL_NODE(21071, 207) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(21071, 208) // If
        CASE_CREATE_SKILL_NODE(21071, 209) // SkillEndNotify
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_21071

SkillLogic* SkillCreator_21071::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //创建阶段phase
    auto phase = new SkillPhase_21071(1, logic, 3);
    //设置phase执行器
    phase->setRunPhaseNode(1, 1);
    phase->setRunPhaseNode(2, 2);
    phase->setDetectPhaseNode(3, 16);
    phase->setDetectPhaseNode(3, 203);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_21071::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
