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
#include "skill_psnode_playanimation.h"
#include "skill_psnode_playsound.h"
#include "skill_psnode_resetcd.h"
#include "skill_psnode_spawncollider.h"
#include "skill_psnode_startphase.h"
#include "skill_psnode_triggercheck.h"
#include "skill_psnode_triggerupdate.h"

namespace pvp {

//变量声明
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(23012, 1) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlayAnimation::TRIGGER_DONE, 2, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_PlayAnimation::TRIGGER_DONE, 35, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(23012, 1) {
    auto node1 = GET_SKILL_NODE(1, PhaseNode_PlayAnimation);
    if (node1 == nullptr) {
        node1 = new PhaseNode_PlayAnimation(1, phase);
        node1->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node1->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node1->setTarget(0U);
        node1->setAnimation("Skill2S1");
        node1->setParameter("");
        node1->setValue(false);
        CALL_REGISTER_SKILL_NODE(23012, 1, node1)
    }
    if (noInit == true) {
        return node1;
    }
    return node1;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(23012, 2) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnCollider>(PhaseNode_Delay::TRIGGER_DONE, 3, PhaseNode_SpawnCollider::FUNC_DO, &PhaseNode_SpawnCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(23012, 2) {
    auto node2 = GET_SKILL_NODE(2, PhaseNode_Delay);
    if (node2 == nullptr) {
        node2 = new PhaseNode_Delay(2, phase);
        node2->setTime(.70f);
        CALL_REGISTER_SKILL_NODE(23012, 2, node2)
    }
    if (noInit == true) {
        return node2;
    }
    return node2;
}
//--------------------------------------------------------------------------------
// SpawnCollider
//
REGISTER_REGISTER_SKILL_NODE(23012, 3) {
    pnode->resizeTrigger(PhaseNode_SpawnCollider::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnCollider>(PhaseNode_SpawnCollider::TRIGGER_DONE, 4, PhaseNode_SpawnCollider::FUNC_DO, &PhaseNode_SpawnCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(23012, 3) {
    auto node3 = GET_SKILL_NODE(3, PhaseNode_SpawnCollider);
    if (node3 == nullptr) {
        node3 = new PhaseNode_SpawnCollider(3, phase);
        node3->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node3->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node3->setMesh("");
        node3->setMeshScale(.00f);
        node3->setEffectID(230121);
        node3->setEffectScale(1.00f);
        node3->setType(PhaseNode_SpawnCollider::SpawnCollider_Type::Circle);
        node3->setTypeParams(0, .00f);
        node3->setTime(.00f);
        node3->setPosZ(.00f);
        node3->setreentry(false);
        node3->setCheckPeneSound(false);
        CALL_REGISTER_SKILL_NODE(23012, 3, node3)
    }
    if (noInit == true) {
        return node3;
    }
    auto node11 = GET_SKILL_NODE(11, PhaseNode_GetLocation);
    auto node12 = GET_SKILL_NODE(12, PhaseNode_GetRotation);
    if (node11 != nullptr) node3->setPosX(node11->getX());
    if (node11 != nullptr) node3->setPosY(node11->getY());
    if (node12 != nullptr) node3->setRotation(node12->getAngle());
    return node3;
}
//--------------------------------------------------------------------------------
// SpawnCollider
//
REGISTER_REGISTER_SKILL_NODE(23012, 4) {
    pnode->resizeTrigger(PhaseNode_SpawnCollider::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_SpawnCollider::TRIGGER_DONE, 9, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_SpawnCollider::TRIGGER_DONE, 55, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(23012, 4) {
    auto node4 = GET_SKILL_NODE(4, PhaseNode_SpawnCollider);
    if (node4 == nullptr) {
        node4 = new PhaseNode_SpawnCollider(4, phase);
        node4->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node4->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node4->setMesh("");
        node4->setMeshScale(.00f);
        node4->setEffectID(0);
        node4->setEffectScale(.00f);
        node4->setType(PhaseNode_SpawnCollider::SpawnCollider_Type::Sector);
        node4->setTypeParams(0, 2.50f);
        node4->setTypeParams(1, 120.00f);
        node4->setTime(.60f);
        node4->setPosZ(.00f);
        node4->setreentry(false);
        node4->setCheckPeneSound(false);
        CALL_REGISTER_SKILL_NODE(23012, 4, node4)
    }
    if (noInit == true) {
        return node4;
    }
    auto node11 = GET_SKILL_NODE(11, PhaseNode_GetLocation);
    auto node12 = GET_SKILL_NODE(12, PhaseNode_GetRotation);
    if (node11 != nullptr) node4->setPosX(node11->getX());
    if (node11 != nullptr) node4->setPosY(node11->getY());
    if (node12 != nullptr) node4->setRotation(node12->getAngle());
    return node4;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(23012, 9) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_Delay::TRIGGER_DONE, 10, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(23012, 9) {
    auto node9 = GET_SKILL_NODE(9, PhaseNode_Delay);
    if (node9 == nullptr) {
        node9 = new PhaseNode_Delay(9, phase);
        node9->setTime(.60f);
        CALL_REGISTER_SKILL_NODE(23012, 9, node9)
    }
    if (noInit == true) {
        return node9;
    }
    return node9;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(23012, 10) {
}

REGISTER_CREATE_SKILL_NODE(23012, 10) {
    auto node10 = GET_SKILL_NODE(10, PhaseNode_EndPhase);
    if (node10 == nullptr) {
        node10 = new PhaseNode_EndPhase(10, phase);
        node10->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node10->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(23012, 10, node10)
    }
    if (noInit == true) {
        return node10;
    }
    return node10;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(23012, 11) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetRotation>(PhaseNode_GetLocation::TRIGGER_DONE, 12, PhaseNode_GetRotation::FUNC_DO, &PhaseNode_GetRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(23012, 11) {
    auto node11 = GET_SKILL_NODE(11, PhaseNode_GetLocation);
    if (node11 == nullptr) {
        node11 = new PhaseNode_GetLocation(11, phase);
        node11->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node11->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(23012, 11, node11)
    }
    if (noInit == true) {
        return node11;
    }
    return node11;
}
//--------------------------------------------------------------------------------
// GetRotation
//
REGISTER_REGISTER_SKILL_NODE(23012, 12) {
    pnode->resizeTrigger(PhaseNode_GetRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_GetRotation::TRIGGER_DONE, 1, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(23012, 12) {
    auto node12 = GET_SKILL_NODE(12, PhaseNode_GetRotation);
    if (node12 == nullptr) {
        node12 = new PhaseNode_GetRotation(12, phase);
        node12->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node12->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(23012, 12, node12)
    }
    if (noInit == true) {
        return node12;
    }
    return node12;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(23012, 13) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_Detect::TRIGGER_ON, 14, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(23012, 13) {
    auto node13 = GET_SKILL_NODE(13, PhaseNode_Detect);
    if (node13 == nullptr) {
        node13 = new PhaseNode_Detect(13, phase);
        node13->setSelf(0U);
        node13->setEvent("");
        node13->setType(PhaseNode_Detect::Detect_Type::Actor_Dead);
        node13->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(23012, 13, node13)
    }
    if (noInit == true) {
        return node13;
    }
    return node13;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(23012, 14) {
}

REGISTER_CREATE_SKILL_NODE(23012, 14) {
    auto node14 = GET_SKILL_NODE(14, PhaseNode_EndPhase);
    if (node14 == nullptr) {
        node14 = new PhaseNode_EndPhase(14, phase);
        node14->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node14->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(23012, 14, node14)
    }
    if (noInit == true) {
        return node14;
    }
    return node14;
}
//--------------------------------------------------------------------------------
// StartPhase
//
REGISTER_REGISTER_SKILL_NODE(23012, 16) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_StartPhase::TRIGGER_START, 20, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(23012, 16) {
    auto node16 = GET_SKILL_NODE(16, PhaseNode_StartPhase);
    if (node16 == nullptr) {
        node16 = new PhaseNode_StartPhase(16, phase);
        CALL_REGISTER_SKILL_NODE(23012, 16, node16)
    }
    if (noInit == true) {
        return node16;
    }
    return node16;
}
//--------------------------------------------------------------------------------
// TriggerUpdate
//
REGISTER_REGISTER_SKILL_NODE(23012, 18) {
}

REGISTER_CREATE_SKILL_NODE(23012, 18) {
    auto node18 = GET_SKILL_NODE(18, PhaseNode_TriggerUpdate);
    if (node18 == nullptr) {
        node18 = new PhaseNode_TriggerUpdate(18, phase);
        CALL_REGISTER_SKILL_NODE(23012, 18, node18)
    }
    if (noInit == true) {
        return node18;
    }
    return node18;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(23012, 20) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_ResetCD::TRIGGER_DONE, 11, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(23012, 20) {
    auto node20 = GET_SKILL_NODE(20, PhaseNode_ResetCD);
    if (node20 == nullptr) {
        node20 = new PhaseNode_ResetCD(20, phase);
        node20->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node20->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node20->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(23012, 20, node20)
    }
    if (noInit == true) {
        return node20;
    }
    return node20;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(23012, 35) {
}

REGISTER_CREATE_SKILL_NODE(23012, 35) {
    auto node35 = GET_SKILL_NODE(35, PhaseNode_PlaySound);
    if (node35 == nullptr) {
        node35 = new PhaseNode_PlaySound(35, phase);
        node35->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node35->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node35->setSoundID("SE_MON2301_ATK_B");
        node35->setTarget(0U);
        node35->setUsePos(false);
        node35->setPosX(.00f);
        node35->setPosY(.00f);
        node35->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(23012, 35, node35)
    }
    if (noInit == true) {
        return node35;
    }
    return node35;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(23012, 48) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 60, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 62, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(23012, 48) {
    auto node48 = GET_SKILL_NODE(48, PhaseNode_CreateTriggerNewPene);
    if (node48 == nullptr) {
        node48 = new PhaseNode_CreateTriggerNewPene(48, phase);
        node48->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::In);
        node48->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node48->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Enemy);
        node48->setOnHero(true);
        node48->setOnMinion(true);
        node48->setOnDestruct(true);
        node48->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(23012, 48, node48)
    }
    if (noInit == true) {
        return node48;
    }
    auto node4 = GET_SKILL_NODE(4, PhaseNode_SpawnCollider);
    if (node4 != nullptr) node48->setColliderID(node4->getColliderID());
    return node48;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(23012, 49) {
}

REGISTER_CREATE_SKILL_NODE(23012, 49) {
    auto node49 = GET_SKILL_NODE(49, PhaseNode_TriggerCheck);
    if (node49 == nullptr) {
        node49 = new PhaseNode_TriggerCheck(49, phase);
        auto node18 = GET_SKILL_NODE(18, PhaseNode_TriggerUpdate);
        if (node18 != nullptr) node18->addTriggerCheck(node49);
        
        CALL_REGISTER_SKILL_NODE(23012, 49, node49)
    }
    if (noInit == true) {
        return node49;
    }
    auto node58 = GET_SKILL_NODE(58, PhaseNode_CreateTriggerNewPene);
    if (node58 != nullptr) node49->setTrigger(0, node58->getTriggerID());
    return node49;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(23012, 50) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 51, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(23012, 50) {
    auto node50 = GET_SKILL_NODE(50, PhaseNode_ActorFilterNewPene);
    if (node50 == nullptr) {
        node50 = new PhaseNode_ActorFilterNewPene(50, phase);
        node50->setHero(true);
        node50->setMinion(true);
        node50->setDestruct(true);
        node50->setShield(false);
        node50->setTotalCount(0);
        node50->setPerCount(1);
        CALL_REGISTER_SKILL_NODE(23012, 50, node50)
    }
    if (noInit == true) {
        return node50;
    }
    auto node54 = GET_SKILL_NODE(54, PhaseNode_CreateTriggerNewPene);
    if (node54 != nullptr) node50->setInput(node54->getOther());
    return node50;
}
//--------------------------------------------------------------------------------
// GetActorAttribute
//
REGISTER_REGISTER_SKILL_NODE(23012, 51) {
    pnode->resizeTrigger(PhaseNode_GetActorAttribute::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 52, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 65, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 66, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 67, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
}

REGISTER_CREATE_SKILL_NODE(23012, 51) {
    auto node51 = GET_SKILL_NODE(51, PhaseNode_GetActorAttribute);
    if (node51 == nullptr) {
        node51 = new PhaseNode_GetActorAttribute(51, phase);
        node51->setTarget(0U);
        node51->setType({202});
        CALL_REGISTER_SKILL_NODE(23012, 51, node51)
    }
    if (noInit == true) {
        return node51;
    }
    return node51;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(23012, 52) {
}

REGISTER_CREATE_SKILL_NODE(23012, 52) {
    auto node52 = GET_SKILL_NODE(52, PhaseNode_AddSkillBuffs);
    if (node52 == nullptr) {
        node52 = new PhaseNode_AddSkillBuffs(52, phase);
        node52->setConfigID({230121});
        CALL_REGISTER_SKILL_NODE(23012, 52, node52)
    }
    if (noInit == true) {
        return node52;
    }
    auto node50 = GET_SKILL_NODE(50, PhaseNode_ActorFilterNewPene);
    auto node51 = GET_SKILL_NODE(51, PhaseNode_GetActorAttribute);
    if (node50 != nullptr) node52->setTarget(node50->getOutput());
    if (node51 != nullptr) node52->setAttribute(node51->getAttribute());
    return node52;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(23012, 53) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 48, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_LESS, 54, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
}

REGISTER_CREATE_SKILL_NODE(23012, 53) {
    auto node53 = GET_SKILL_NODE(53, PhaseNode_CompareFloat);
    if (node53 == nullptr) {
        node53 = new PhaseNode_CompareFloat(53, phase);
        node53->setA(.00f);
        node53->setB(.00f);
        CALL_REGISTER_SKILL_NODE(23012, 53, node53)
    }
    if (noInit == true) {
        return node53;
    }
    return node53;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(23012, 54) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 59, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 50, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(23012, 54) {
    auto node54 = GET_SKILL_NODE(54, PhaseNode_CreateTriggerNewPene);
    if (node54 == nullptr) {
        node54 = new PhaseNode_CreateTriggerNewPene(54, phase);
        node54->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::Tick);
        node54->setTypeParams(0, .00f);
        node54->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node54->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Enemy);
        node54->setOnHero(true);
        node54->setOnMinion(true);
        node54->setOnDestruct(true);
        node54->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(23012, 54, node54)
    }
    if (noInit == true) {
        return node54;
    }
    auto node4 = GET_SKILL_NODE(4, PhaseNode_SpawnCollider);
    if (node4 != nullptr) node54->setColliderID(node4->getColliderID());
    return node54;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(23012, 55) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_If::TRIGGER_FALSE, 56, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_If::TRIGGER_TRUE, 53, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(23012, 55) {
    auto node55 = GET_SKILL_NODE(55, PhaseNode_If);
    if (node55 == nullptr) {
        node55 = new PhaseNode_If(55, phase);
        node55->setCondition(false);
        CALL_REGISTER_SKILL_NODE(23012, 55, node55)
    }
    if (noInit == true) {
        return node55;
    }
    return node55;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(23012, 56) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 58, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_LESS, 57, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
}

REGISTER_CREATE_SKILL_NODE(23012, 56) {
    auto node56 = GET_SKILL_NODE(56, PhaseNode_CompareFloat);
    if (node56 == nullptr) {
        node56 = new PhaseNode_CompareFloat(56, phase);
        node56->setA(.00f);
        node56->setB(.00f);
        CALL_REGISTER_SKILL_NODE(23012, 56, node56)
    }
    if (noInit == true) {
        return node56;
    }
    return node56;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(23012, 57) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 61, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 63, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(23012, 57) {
    auto node57 = GET_SKILL_NODE(57, PhaseNode_CreateTriggerNewPene);
    if (node57 == nullptr) {
        node57 = new PhaseNode_CreateTriggerNewPene(57, phase);
        node57->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::Tick);
        node57->setTypeParams(0, .00f);
        node57->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node57->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Friend);
        node57->setOnHero(true);
        node57->setOnMinion(true);
        node57->setOnDestruct(true);
        node57->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(23012, 57, node57)
    }
    if (noInit == true) {
        return node57;
    }
    auto node4 = GET_SKILL_NODE(4, PhaseNode_SpawnCollider);
    if (node4 != nullptr) node57->setColliderID(node4->getColliderID());
    return node57;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(23012, 58) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 49, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 64, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(23012, 58) {
    auto node58 = GET_SKILL_NODE(58, PhaseNode_CreateTriggerNewPene);
    if (node58 == nullptr) {
        node58 = new PhaseNode_CreateTriggerNewPene(58, phase);
        node58->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::In);
        node58->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node58->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Friend);
        node58->setOnHero(true);
        node58->setOnMinion(true);
        node58->setOnDestruct(true);
        node58->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(23012, 58, node58)
    }
    if (noInit == true) {
        return node58;
    }
    auto node4 = GET_SKILL_NODE(4, PhaseNode_SpawnCollider);
    if (node4 != nullptr) node58->setColliderID(node4->getColliderID());
    return node58;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(23012, 59) {
}

REGISTER_CREATE_SKILL_NODE(23012, 59) {
    auto node59 = GET_SKILL_NODE(59, PhaseNode_TriggerCheck);
    if (node59 == nullptr) {
        node59 = new PhaseNode_TriggerCheck(59, phase);
        auto node18 = GET_SKILL_NODE(18, PhaseNode_TriggerUpdate);
        if (node18 != nullptr) node18->addTriggerCheck(node59);
        
        CALL_REGISTER_SKILL_NODE(23012, 59, node59)
    }
    if (noInit == true) {
        return node59;
    }
    auto node54 = GET_SKILL_NODE(54, PhaseNode_CreateTriggerNewPene);
    if (node54 != nullptr) node59->setTrigger(0, node54->getTriggerID());
    return node59;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(23012, 60) {
}

REGISTER_CREATE_SKILL_NODE(23012, 60) {
    auto node60 = GET_SKILL_NODE(60, PhaseNode_TriggerCheck);
    if (node60 == nullptr) {
        node60 = new PhaseNode_TriggerCheck(60, phase);
        auto node18 = GET_SKILL_NODE(18, PhaseNode_TriggerUpdate);
        if (node18 != nullptr) node18->addTriggerCheck(node60);
        
        CALL_REGISTER_SKILL_NODE(23012, 60, node60)
    }
    if (noInit == true) {
        return node60;
    }
    auto node48 = GET_SKILL_NODE(48, PhaseNode_CreateTriggerNewPene);
    if (node48 != nullptr) node60->setTrigger(0, node48->getTriggerID());
    return node60;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(23012, 61) {
}

REGISTER_CREATE_SKILL_NODE(23012, 61) {
    auto node61 = GET_SKILL_NODE(61, PhaseNode_TriggerCheck);
    if (node61 == nullptr) {
        node61 = new PhaseNode_TriggerCheck(61, phase);
        auto node18 = GET_SKILL_NODE(18, PhaseNode_TriggerUpdate);
        if (node18 != nullptr) node18->addTriggerCheck(node61);
        
        CALL_REGISTER_SKILL_NODE(23012, 61, node61)
    }
    if (noInit == true) {
        return node61;
    }
    auto node57 = GET_SKILL_NODE(57, PhaseNode_CreateTriggerNewPene);
    if (node57 != nullptr) node61->setTrigger(0, node57->getTriggerID());
    return node61;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(23012, 62) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 51, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(23012, 62) {
    auto node62 = GET_SKILL_NODE(62, PhaseNode_ActorFilterNewPene);
    if (node62 == nullptr) {
        node62 = new PhaseNode_ActorFilterNewPene(62, phase);
        node62->setHero(true);
        node62->setMinion(true);
        node62->setDestruct(true);
        node62->setShield(false);
        node62->setTotalCount(0);
        node62->setPerCount(1);
        CALL_REGISTER_SKILL_NODE(23012, 62, node62)
    }
    if (noInit == true) {
        return node62;
    }
    auto node48 = GET_SKILL_NODE(48, PhaseNode_CreateTriggerNewPene);
    if (node48 != nullptr) node62->setInput(node48->getOther());
    return node62;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(23012, 63) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 51, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(23012, 63) {
    auto node63 = GET_SKILL_NODE(63, PhaseNode_ActorFilterNewPene);
    if (node63 == nullptr) {
        node63 = new PhaseNode_ActorFilterNewPene(63, phase);
        node63->setHero(true);
        node63->setMinion(true);
        node63->setDestruct(true);
        node63->setShield(false);
        node63->setTotalCount(0);
        node63->setPerCount(1);
        CALL_REGISTER_SKILL_NODE(23012, 63, node63)
    }
    if (noInit == true) {
        return node63;
    }
    auto node57 = GET_SKILL_NODE(57, PhaseNode_CreateTriggerNewPene);
    if (node57 != nullptr) node63->setInput(node57->getOther());
    return node63;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(23012, 64) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 51, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(23012, 64) {
    auto node64 = GET_SKILL_NODE(64, PhaseNode_ActorFilterNewPene);
    if (node64 == nullptr) {
        node64 = new PhaseNode_ActorFilterNewPene(64, phase);
        node64->setHero(true);
        node64->setMinion(true);
        node64->setDestruct(true);
        node64->setShield(false);
        node64->setTotalCount(0);
        node64->setPerCount(1);
        CALL_REGISTER_SKILL_NODE(23012, 64, node64)
    }
    if (noInit == true) {
        return node64;
    }
    auto node58 = GET_SKILL_NODE(58, PhaseNode_CreateTriggerNewPene);
    if (node58 != nullptr) node64->setInput(node58->getOther());
    return node64;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(23012, 65) {
}

REGISTER_CREATE_SKILL_NODE(23012, 65) {
    auto node65 = GET_SKILL_NODE(65, PhaseNode_AddSkillBuffs);
    if (node65 == nullptr) {
        node65 = new PhaseNode_AddSkillBuffs(65, phase);
        node65->setConfigID({230121});
        CALL_REGISTER_SKILL_NODE(23012, 65, node65)
    }
    if (noInit == true) {
        return node65;
    }
    auto node62 = GET_SKILL_NODE(62, PhaseNode_ActorFilterNewPene);
    auto node51 = GET_SKILL_NODE(51, PhaseNode_GetActorAttribute);
    if (node62 != nullptr) node65->setTarget(node62->getOutput());
    if (node51 != nullptr) node65->setAttribute(node51->getAttribute());
    return node65;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(23012, 66) {
}

REGISTER_CREATE_SKILL_NODE(23012, 66) {
    auto node66 = GET_SKILL_NODE(66, PhaseNode_AddSkillBuffs);
    if (node66 == nullptr) {
        node66 = new PhaseNode_AddSkillBuffs(66, phase);
        node66->setConfigID({230121});
        CALL_REGISTER_SKILL_NODE(23012, 66, node66)
    }
    if (noInit == true) {
        return node66;
    }
    auto node63 = GET_SKILL_NODE(63, PhaseNode_ActorFilterNewPene);
    auto node51 = GET_SKILL_NODE(51, PhaseNode_GetActorAttribute);
    if (node63 != nullptr) node66->setTarget(node63->getOutput());
    if (node51 != nullptr) node66->setAttribute(node51->getAttribute());
    return node66;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(23012, 67) {
}

REGISTER_CREATE_SKILL_NODE(23012, 67) {
    auto node67 = GET_SKILL_NODE(67, PhaseNode_AddSkillBuffs);
    if (node67 == nullptr) {
        node67 = new PhaseNode_AddSkillBuffs(67, phase);
        node67->setConfigID({230121});
        CALL_REGISTER_SKILL_NODE(23012, 67, node67)
    }
    if (noInit == true) {
        return node67;
    }
    auto node64 = GET_SKILL_NODE(64, PhaseNode_ActorFilterNewPene);
    auto node51 = GET_SKILL_NODE(51, PhaseNode_GetActorAttribute);
    if (node64 != nullptr) node67->setTarget(node64->getOutput());
    if (node51 != nullptr) node67->setAttribute(node51->getAttribute());
    return node67;
}

//--------------------------------------------------------------------------------
// SkillCreator_23012
//
class SkillCreator_23012 : public SkillCreator {
public:
    SkillCreator_23012() {}
    virtual ~SkillCreator_23012() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_23012

//--------------------------------------------------------------------------------
// SkillPhase_23012
//
class SkillPhase_23012 : public SkillPhase {
public:
    SkillPhase_23012(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_23012() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(23012, 1) // PlayAnimation
        CASE_CREATE_SKILL_NODE(23012, 2) // Delay
        CASE_CREATE_SKILL_NODE(23012, 3) // SpawnCollider
        CASE_CREATE_SKILL_NODE(23012, 4) // SpawnCollider
        CASE_CREATE_SKILL_NODE(23012, 9) // Delay
        CASE_CREATE_SKILL_NODE(23012, 10) // EndPhase
        CASE_CREATE_SKILL_NODE(23012, 11) // GetLocation
        CASE_CREATE_SKILL_NODE(23012, 12) // GetRotation
        CASE_CREATE_SKILL_NODE(23012, 13) // Detect
        CASE_CREATE_SKILL_NODE(23012, 14) // EndPhase
        CASE_CREATE_SKILL_NODE(23012, 16) // StartPhase
        CASE_CREATE_SKILL_NODE(23012, 18) // TriggerUpdate
        CASE_CREATE_SKILL_NODE(23012, 20) // ResetCD
        CASE_CREATE_SKILL_NODE(23012, 35) // PlaySound
        CASE_CREATE_SKILL_NODE(23012, 48) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(23012, 49) // TriggerCheck
        CASE_CREATE_SKILL_NODE(23012, 50) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(23012, 51) // GetActorAttribute
        CASE_CREATE_SKILL_NODE(23012, 52) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(23012, 53) // CompareFloat
        CASE_CREATE_SKILL_NODE(23012, 54) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(23012, 55) // If
        CASE_CREATE_SKILL_NODE(23012, 56) // CompareFloat
        CASE_CREATE_SKILL_NODE(23012, 57) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(23012, 58) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(23012, 59) // TriggerCheck
        CASE_CREATE_SKILL_NODE(23012, 60) // TriggerCheck
        CASE_CREATE_SKILL_NODE(23012, 61) // TriggerCheck
        CASE_CREATE_SKILL_NODE(23012, 62) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(23012, 63) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(23012, 64) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(23012, 65) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(23012, 66) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(23012, 67) // AddSkillBuffs
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_23012

SkillLogic* SkillCreator_23012::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //创建阶段phase
    auto phase = new SkillPhase_23012(1, logic, 3);
    //设置phase执行器
    phase->setDetectPhaseNode(1, 13);
    phase->setRunPhaseNode(2, 16);
    phase->setRunPhaseNode(3, 18);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_23012::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
