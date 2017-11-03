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
// StartPhase
//
REGISTER_REGISTER_SKILL_NODE(23011, 2) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_StartPhase::TRIGGER_START, 12, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(23011, 2) {
    auto node2 = GET_SKILL_NODE(2, PhaseNode_StartPhase);
    if (node2 == nullptr) {
        node2 = new PhaseNode_StartPhase(2, phase);
        CALL_REGISTER_SKILL_NODE(23011, 2, node2)
    }
    if (noInit == true) {
        return node2;
    }
    return node2;
}
//--------------------------------------------------------------------------------
// TriggerUpdate
//
REGISTER_REGISTER_SKILL_NODE(23011, 4) {
}

REGISTER_CREATE_SKILL_NODE(23011, 4) {
    auto node4 = GET_SKILL_NODE(4, PhaseNode_TriggerUpdate);
    if (node4 == nullptr) {
        node4 = new PhaseNode_TriggerUpdate(4, phase);
        CALL_REGISTER_SKILL_NODE(23011, 4, node4)
    }
    if (noInit == true) {
        return node4;
    }
    return node4;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(23011, 6) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlayAnimation::TRIGGER_DONE, 54, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlayAnimation::TRIGGER_DONE, 8, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(23011, 6) {
    auto node6 = GET_SKILL_NODE(6, PhaseNode_PlayAnimation);
    if (node6 == nullptr) {
        node6 = new PhaseNode_PlayAnimation(6, phase);
        node6->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node6->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node6->setTarget(0U);
        node6->setAnimation("Skill1S1");
        node6->setParameter("");
        node6->setValue(false);
        CALL_REGISTER_SKILL_NODE(23011, 6, node6)
    }
    if (noInit == true) {
        return node6;
    }
    return node6;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(23011, 8) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnCollider>(PhaseNode_Delay::TRIGGER_DONE, 16, PhaseNode_SpawnCollider::FUNC_DO, &PhaseNode_SpawnCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(23011, 8) {
    auto node8 = GET_SKILL_NODE(8, PhaseNode_Delay);
    if (node8 == nullptr) {
        node8 = new PhaseNode_Delay(8, phase);
        node8->setTime(.50f);
        CALL_REGISTER_SKILL_NODE(23011, 8, node8)
    }
    if (noInit == true) {
        return node8;
    }
    return node8;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(23011, 10) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetRotation>(PhaseNode_GetLocation::TRIGGER_DONE, 14, PhaseNode_GetRotation::FUNC_DO, &PhaseNode_GetRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(23011, 10) {
    auto node10 = GET_SKILL_NODE(10, PhaseNode_GetLocation);
    if (node10 == nullptr) {
        node10 = new PhaseNode_GetLocation(10, phase);
        node10->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node10->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(23011, 10, node10)
    }
    if (noInit == true) {
        return node10;
    }
    return node10;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(23011, 12) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_ResetCD::TRIGGER_DONE, 10, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(23011, 12) {
    auto node12 = GET_SKILL_NODE(12, PhaseNode_ResetCD);
    if (node12 == nullptr) {
        node12 = new PhaseNode_ResetCD(12, phase);
        node12->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node12->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node12->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(23011, 12, node12)
    }
    if (noInit == true) {
        return node12;
    }
    return node12;
}
//--------------------------------------------------------------------------------
// GetRotation
//
REGISTER_REGISTER_SKILL_NODE(23011, 14) {
    pnode->resizeTrigger(PhaseNode_GetRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_GetRotation::TRIGGER_DONE, 6, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(23011, 14) {
    auto node14 = GET_SKILL_NODE(14, PhaseNode_GetRotation);
    if (node14 == nullptr) {
        node14 = new PhaseNode_GetRotation(14, phase);
        node14->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node14->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(23011, 14, node14)
    }
    if (noInit == true) {
        return node14;
    }
    return node14;
}
//--------------------------------------------------------------------------------
// SpawnCollider
//
REGISTER_REGISTER_SKILL_NODE(23011, 16) {
    pnode->resizeTrigger(PhaseNode_SpawnCollider::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnCollider>(PhaseNode_SpawnCollider::TRIGGER_DONE, 18, PhaseNode_SpawnCollider::FUNC_DO, &PhaseNode_SpawnCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(23011, 16) {
    auto node16 = GET_SKILL_NODE(16, PhaseNode_SpawnCollider);
    if (node16 == nullptr) {
        node16 = new PhaseNode_SpawnCollider(16, phase);
        node16->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node16->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node16->setMesh("");
        node16->setMeshScale(.00f);
        node16->setEffectID(230111);
        node16->setEffectScale(1.00f);
        node16->setType(PhaseNode_SpawnCollider::SpawnCollider_Type::Circle);
        node16->setTypeParams(0, .00f);
        node16->setTime(.00f);
        node16->setPosZ(.00f);
        node16->setreentry(false);
        node16->setCheckPeneSound(false);
        CALL_REGISTER_SKILL_NODE(23011, 16, node16)
    }
    if (noInit == true) {
        return node16;
    }
    auto node10 = GET_SKILL_NODE(10, PhaseNode_GetLocation);
    auto node14 = GET_SKILL_NODE(14, PhaseNode_GetRotation);
    if (node10 != nullptr) node16->setPosX(node10->getX());
    if (node10 != nullptr) node16->setPosY(node10->getY());
    if (node14 != nullptr) node16->setRotation(node14->getAngle());
    return node16;
}
//--------------------------------------------------------------------------------
// SpawnCollider
//
REGISTER_REGISTER_SKILL_NODE(23011, 18) {
    pnode->resizeTrigger(PhaseNode_SpawnCollider::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_SpawnCollider::TRIGGER_DONE, 30, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_SpawnCollider::TRIGGER_DONE, 64, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(23011, 18) {
    auto node18 = GET_SKILL_NODE(18, PhaseNode_SpawnCollider);
    if (node18 == nullptr) {
        node18 = new PhaseNode_SpawnCollider(18, phase);
        node18->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node18->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node18->setMesh("");
        node18->setMeshScale(.00f);
        node18->setEffectID(0);
        node18->setEffectScale(.00f);
        node18->setType(PhaseNode_SpawnCollider::SpawnCollider_Type::Sector);
        node18->setTypeParams(0, 3.50f);
        node18->setTypeParams(1, 120.00f);
        node18->setTime(.60f);
        node18->setPosZ(.00f);
        node18->setreentry(false);
        node18->setCheckPeneSound(false);
        CALL_REGISTER_SKILL_NODE(23011, 18, node18)
    }
    if (noInit == true) {
        return node18;
    }
    auto node10 = GET_SKILL_NODE(10, PhaseNode_GetLocation);
    auto node14 = GET_SKILL_NODE(14, PhaseNode_GetRotation);
    if (node10 != nullptr) node18->setPosX(node10->getX());
    if (node10 != nullptr) node18->setPosY(node10->getY());
    if (node14 != nullptr) node18->setRotation(node14->getAngle());
    return node18;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(23011, 30) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_Delay::TRIGGER_DONE, 32, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(23011, 30) {
    auto node30 = GET_SKILL_NODE(30, PhaseNode_Delay);
    if (node30 == nullptr) {
        node30 = new PhaseNode_Delay(30, phase);
        node30->setTime(.60f);
        CALL_REGISTER_SKILL_NODE(23011, 30, node30)
    }
    if (noInit == true) {
        return node30;
    }
    return node30;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(23011, 32) {
}

REGISTER_CREATE_SKILL_NODE(23011, 32) {
    auto node32 = GET_SKILL_NODE(32, PhaseNode_EndPhase);
    if (node32 == nullptr) {
        node32 = new PhaseNode_EndPhase(32, phase);
        node32->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node32->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(23011, 32, node32)
    }
    if (noInit == true) {
        return node32;
    }
    return node32;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(23011, 34) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_Detect::TRIGGER_ON, 36, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(23011, 34) {
    auto node34 = GET_SKILL_NODE(34, PhaseNode_Detect);
    if (node34 == nullptr) {
        node34 = new PhaseNode_Detect(34, phase);
        node34->setSelf(0U);
        node34->setEvent("");
        node34->setType(PhaseNode_Detect::Detect_Type::Actor_Dead);
        node34->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(23011, 34, node34)
    }
    if (noInit == true) {
        return node34;
    }
    return node34;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(23011, 36) {
}

REGISTER_CREATE_SKILL_NODE(23011, 36) {
    auto node36 = GET_SKILL_NODE(36, PhaseNode_EndPhase);
    if (node36 == nullptr) {
        node36 = new PhaseNode_EndPhase(36, phase);
        node36->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node36->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(23011, 36, node36)
    }
    if (noInit == true) {
        return node36;
    }
    return node36;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(23011, 38) {
}

REGISTER_CREATE_SKILL_NODE(23011, 38) {
    auto node38 = GET_SKILL_NODE(38, PhaseNode_PlaySound);
    if (node38 == nullptr) {
        node38 = new PhaseNode_PlaySound(38, phase);
        node38->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node38->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node38->setSoundID("SE_MON2301_ATK_A");
        node38->setTarget(0U);
        node38->setUsePos(false);
        node38->setPosX(.00f);
        node38->setPosY(.00f);
        node38->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(23011, 38, node38)
    }
    if (noInit == true) {
        return node38;
    }
    return node38;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(23011, 54) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_Delay::TRIGGER_DONE, 38, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(23011, 54) {
    auto node54 = GET_SKILL_NODE(54, PhaseNode_Delay);
    if (node54 == nullptr) {
        node54 = new PhaseNode_Delay(54, phase);
        node54->setTime(.15f);
        CALL_REGISTER_SKILL_NODE(23011, 54, node54)
    }
    if (noInit == true) {
        return node54;
    }
    return node54;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(23011, 57) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 69, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 71, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(23011, 57) {
    auto node57 = GET_SKILL_NODE(57, PhaseNode_CreateTriggerNewPene);
    if (node57 == nullptr) {
        node57 = new PhaseNode_CreateTriggerNewPene(57, phase);
        node57->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::In);
        node57->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node57->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Enemy);
        node57->setOnHero(true);
        node57->setOnMinion(true);
        node57->setOnDestruct(true);
        node57->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(23011, 57, node57)
    }
    if (noInit == true) {
        return node57;
    }
    auto node18 = GET_SKILL_NODE(18, PhaseNode_SpawnCollider);
    if (node18 != nullptr) node57->setColliderID(node18->getColliderID());
    return node57;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(23011, 58) {
}

REGISTER_CREATE_SKILL_NODE(23011, 58) {
    auto node58 = GET_SKILL_NODE(58, PhaseNode_TriggerCheck);
    if (node58 == nullptr) {
        node58 = new PhaseNode_TriggerCheck(58, phase);
        auto node4 = GET_SKILL_NODE(4, PhaseNode_TriggerUpdate);
        if (node4 != nullptr) node4->addTriggerCheck(node58);
        
        CALL_REGISTER_SKILL_NODE(23011, 58, node58)
    }
    if (noInit == true) {
        return node58;
    }
    auto node67 = GET_SKILL_NODE(67, PhaseNode_CreateTriggerNewPene);
    if (node67 != nullptr) node58->setTrigger(0, node67->getTriggerID());
    return node58;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(23011, 59) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 60, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(23011, 59) {
    auto node59 = GET_SKILL_NODE(59, PhaseNode_ActorFilterNewPene);
    if (node59 == nullptr) {
        node59 = new PhaseNode_ActorFilterNewPene(59, phase);
        node59->setHero(true);
        node59->setMinion(true);
        node59->setDestruct(true);
        node59->setShield(false);
        node59->setTotalCount(0);
        node59->setPerCount(1);
        CALL_REGISTER_SKILL_NODE(23011, 59, node59)
    }
    if (noInit == true) {
        return node59;
    }
    auto node63 = GET_SKILL_NODE(63, PhaseNode_CreateTriggerNewPene);
    if (node63 != nullptr) node59->setInput(node63->getOther());
    return node59;
}
//--------------------------------------------------------------------------------
// GetActorAttribute
//
REGISTER_REGISTER_SKILL_NODE(23011, 60) {
    pnode->resizeTrigger(PhaseNode_GetActorAttribute::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 61, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 74, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 75, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 76, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
}

REGISTER_CREATE_SKILL_NODE(23011, 60) {
    auto node60 = GET_SKILL_NODE(60, PhaseNode_GetActorAttribute);
    if (node60 == nullptr) {
        node60 = new PhaseNode_GetActorAttribute(60, phase);
        node60->setTarget(0U);
        node60->setType({202});
        CALL_REGISTER_SKILL_NODE(23011, 60, node60)
    }
    if (noInit == true) {
        return node60;
    }
    return node60;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(23011, 61) {
}

REGISTER_CREATE_SKILL_NODE(23011, 61) {
    auto node61 = GET_SKILL_NODE(61, PhaseNode_AddSkillBuffs);
    if (node61 == nullptr) {
        node61 = new PhaseNode_AddSkillBuffs(61, phase);
        node61->setConfigID({11});
        CALL_REGISTER_SKILL_NODE(23011, 61, node61)
    }
    if (noInit == true) {
        return node61;
    }
    auto node59 = GET_SKILL_NODE(59, PhaseNode_ActorFilterNewPene);
    auto node60 = GET_SKILL_NODE(60, PhaseNode_GetActorAttribute);
    if (node59 != nullptr) node61->setTarget(node59->getOutput());
    if (node60 != nullptr) node61->setAttribute(node60->getAttribute());
    return node61;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(23011, 62) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 57, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_LESS, 63, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
}

REGISTER_CREATE_SKILL_NODE(23011, 62) {
    auto node62 = GET_SKILL_NODE(62, PhaseNode_CompareFloat);
    if (node62 == nullptr) {
        node62 = new PhaseNode_CompareFloat(62, phase);
        node62->setA(.00f);
        node62->setB(.00f);
        CALL_REGISTER_SKILL_NODE(23011, 62, node62)
    }
    if (noInit == true) {
        return node62;
    }
    return node62;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(23011, 63) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 68, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 59, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(23011, 63) {
    auto node63 = GET_SKILL_NODE(63, PhaseNode_CreateTriggerNewPene);
    if (node63 == nullptr) {
        node63 = new PhaseNode_CreateTriggerNewPene(63, phase);
        node63->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::Tick);
        node63->setTypeParams(0, .00f);
        node63->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node63->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Enemy);
        node63->setOnHero(true);
        node63->setOnMinion(true);
        node63->setOnDestruct(true);
        node63->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(23011, 63, node63)
    }
    if (noInit == true) {
        return node63;
    }
    auto node18 = GET_SKILL_NODE(18, PhaseNode_SpawnCollider);
    if (node18 != nullptr) node63->setColliderID(node18->getColliderID());
    return node63;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(23011, 64) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_If::TRIGGER_FALSE, 65, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_If::TRIGGER_TRUE, 62, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(23011, 64) {
    auto node64 = GET_SKILL_NODE(64, PhaseNode_If);
    if (node64 == nullptr) {
        node64 = new PhaseNode_If(64, phase);
        node64->setCondition(false);
        CALL_REGISTER_SKILL_NODE(23011, 64, node64)
    }
    if (noInit == true) {
        return node64;
    }
    return node64;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(23011, 65) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 67, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_LESS, 66, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
}

REGISTER_CREATE_SKILL_NODE(23011, 65) {
    auto node65 = GET_SKILL_NODE(65, PhaseNode_CompareFloat);
    if (node65 == nullptr) {
        node65 = new PhaseNode_CompareFloat(65, phase);
        node65->setA(.00f);
        node65->setB(.00f);
        CALL_REGISTER_SKILL_NODE(23011, 65, node65)
    }
    if (noInit == true) {
        return node65;
    }
    return node65;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(23011, 66) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 70, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 72, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(23011, 66) {
    auto node66 = GET_SKILL_NODE(66, PhaseNode_CreateTriggerNewPene);
    if (node66 == nullptr) {
        node66 = new PhaseNode_CreateTriggerNewPene(66, phase);
        node66->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::Tick);
        node66->setTypeParams(0, .00f);
        node66->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node66->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Friend);
        node66->setOnHero(true);
        node66->setOnMinion(true);
        node66->setOnDestruct(true);
        node66->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(23011, 66, node66)
    }
    if (noInit == true) {
        return node66;
    }
    auto node18 = GET_SKILL_NODE(18, PhaseNode_SpawnCollider);
    if (node18 != nullptr) node66->setColliderID(node18->getColliderID());
    return node66;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(23011, 67) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 58, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 73, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(23011, 67) {
    auto node67 = GET_SKILL_NODE(67, PhaseNode_CreateTriggerNewPene);
    if (node67 == nullptr) {
        node67 = new PhaseNode_CreateTriggerNewPene(67, phase);
        node67->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::In);
        node67->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node67->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Friend);
        node67->setOnHero(true);
        node67->setOnMinion(true);
        node67->setOnDestruct(true);
        node67->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(23011, 67, node67)
    }
    if (noInit == true) {
        return node67;
    }
    auto node18 = GET_SKILL_NODE(18, PhaseNode_SpawnCollider);
    if (node18 != nullptr) node67->setColliderID(node18->getColliderID());
    return node67;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(23011, 68) {
}

REGISTER_CREATE_SKILL_NODE(23011, 68) {
    auto node68 = GET_SKILL_NODE(68, PhaseNode_TriggerCheck);
    if (node68 == nullptr) {
        node68 = new PhaseNode_TriggerCheck(68, phase);
        auto node4 = GET_SKILL_NODE(4, PhaseNode_TriggerUpdate);
        if (node4 != nullptr) node4->addTriggerCheck(node68);
        
        CALL_REGISTER_SKILL_NODE(23011, 68, node68)
    }
    if (noInit == true) {
        return node68;
    }
    auto node63 = GET_SKILL_NODE(63, PhaseNode_CreateTriggerNewPene);
    if (node63 != nullptr) node68->setTrigger(0, node63->getTriggerID());
    return node68;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(23011, 69) {
}

REGISTER_CREATE_SKILL_NODE(23011, 69) {
    auto node69 = GET_SKILL_NODE(69, PhaseNode_TriggerCheck);
    if (node69 == nullptr) {
        node69 = new PhaseNode_TriggerCheck(69, phase);
        auto node4 = GET_SKILL_NODE(4, PhaseNode_TriggerUpdate);
        if (node4 != nullptr) node4->addTriggerCheck(node69);
        
        CALL_REGISTER_SKILL_NODE(23011, 69, node69)
    }
    if (noInit == true) {
        return node69;
    }
    auto node57 = GET_SKILL_NODE(57, PhaseNode_CreateTriggerNewPene);
    if (node57 != nullptr) node69->setTrigger(0, node57->getTriggerID());
    return node69;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(23011, 70) {
}

REGISTER_CREATE_SKILL_NODE(23011, 70) {
    auto node70 = GET_SKILL_NODE(70, PhaseNode_TriggerCheck);
    if (node70 == nullptr) {
        node70 = new PhaseNode_TriggerCheck(70, phase);
        auto node4 = GET_SKILL_NODE(4, PhaseNode_TriggerUpdate);
        if (node4 != nullptr) node4->addTriggerCheck(node70);
        
        CALL_REGISTER_SKILL_NODE(23011, 70, node70)
    }
    if (noInit == true) {
        return node70;
    }
    auto node66 = GET_SKILL_NODE(66, PhaseNode_CreateTriggerNewPene);
    if (node66 != nullptr) node70->setTrigger(0, node66->getTriggerID());
    return node70;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(23011, 71) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 60, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(23011, 71) {
    auto node71 = GET_SKILL_NODE(71, PhaseNode_ActorFilterNewPene);
    if (node71 == nullptr) {
        node71 = new PhaseNode_ActorFilterNewPene(71, phase);
        node71->setHero(true);
        node71->setMinion(true);
        node71->setDestruct(true);
        node71->setShield(false);
        node71->setTotalCount(0);
        node71->setPerCount(1);
        CALL_REGISTER_SKILL_NODE(23011, 71, node71)
    }
    if (noInit == true) {
        return node71;
    }
    auto node57 = GET_SKILL_NODE(57, PhaseNode_CreateTriggerNewPene);
    if (node57 != nullptr) node71->setInput(node57->getOther());
    return node71;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(23011, 72) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 60, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(23011, 72) {
    auto node72 = GET_SKILL_NODE(72, PhaseNode_ActorFilterNewPene);
    if (node72 == nullptr) {
        node72 = new PhaseNode_ActorFilterNewPene(72, phase);
        node72->setHero(true);
        node72->setMinion(true);
        node72->setDestruct(true);
        node72->setShield(false);
        node72->setTotalCount(0);
        node72->setPerCount(1);
        CALL_REGISTER_SKILL_NODE(23011, 72, node72)
    }
    if (noInit == true) {
        return node72;
    }
    auto node66 = GET_SKILL_NODE(66, PhaseNode_CreateTriggerNewPene);
    if (node66 != nullptr) node72->setInput(node66->getOther());
    return node72;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(23011, 73) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 60, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(23011, 73) {
    auto node73 = GET_SKILL_NODE(73, PhaseNode_ActorFilterNewPene);
    if (node73 == nullptr) {
        node73 = new PhaseNode_ActorFilterNewPene(73, phase);
        node73->setHero(true);
        node73->setMinion(true);
        node73->setDestruct(true);
        node73->setShield(false);
        node73->setTotalCount(0);
        node73->setPerCount(1);
        CALL_REGISTER_SKILL_NODE(23011, 73, node73)
    }
    if (noInit == true) {
        return node73;
    }
    auto node67 = GET_SKILL_NODE(67, PhaseNode_CreateTriggerNewPene);
    if (node67 != nullptr) node73->setInput(node67->getOther());
    return node73;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(23011, 74) {
}

REGISTER_CREATE_SKILL_NODE(23011, 74) {
    auto node74 = GET_SKILL_NODE(74, PhaseNode_AddSkillBuffs);
    if (node74 == nullptr) {
        node74 = new PhaseNode_AddSkillBuffs(74, phase);
        node74->setConfigID({11});
        CALL_REGISTER_SKILL_NODE(23011, 74, node74)
    }
    if (noInit == true) {
        return node74;
    }
    auto node71 = GET_SKILL_NODE(71, PhaseNode_ActorFilterNewPene);
    auto node60 = GET_SKILL_NODE(60, PhaseNode_GetActorAttribute);
    if (node71 != nullptr) node74->setTarget(node71->getOutput());
    if (node60 != nullptr) node74->setAttribute(node60->getAttribute());
    return node74;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(23011, 75) {
}

REGISTER_CREATE_SKILL_NODE(23011, 75) {
    auto node75 = GET_SKILL_NODE(75, PhaseNode_AddSkillBuffs);
    if (node75 == nullptr) {
        node75 = new PhaseNode_AddSkillBuffs(75, phase);
        node75->setConfigID({11});
        CALL_REGISTER_SKILL_NODE(23011, 75, node75)
    }
    if (noInit == true) {
        return node75;
    }
    auto node72 = GET_SKILL_NODE(72, PhaseNode_ActorFilterNewPene);
    auto node60 = GET_SKILL_NODE(60, PhaseNode_GetActorAttribute);
    if (node72 != nullptr) node75->setTarget(node72->getOutput());
    if (node60 != nullptr) node75->setAttribute(node60->getAttribute());
    return node75;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(23011, 76) {
}

REGISTER_CREATE_SKILL_NODE(23011, 76) {
    auto node76 = GET_SKILL_NODE(76, PhaseNode_AddSkillBuffs);
    if (node76 == nullptr) {
        node76 = new PhaseNode_AddSkillBuffs(76, phase);
        node76->setConfigID({11});
        CALL_REGISTER_SKILL_NODE(23011, 76, node76)
    }
    if (noInit == true) {
        return node76;
    }
    auto node73 = GET_SKILL_NODE(73, PhaseNode_ActorFilterNewPene);
    auto node60 = GET_SKILL_NODE(60, PhaseNode_GetActorAttribute);
    if (node73 != nullptr) node76->setTarget(node73->getOutput());
    if (node60 != nullptr) node76->setAttribute(node60->getAttribute());
    return node76;
}

//--------------------------------------------------------------------------------
// SkillCreator_23011
//
class SkillCreator_23011 : public SkillCreator {
public:
    SkillCreator_23011() {}
    virtual ~SkillCreator_23011() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_23011

//--------------------------------------------------------------------------------
// SkillPhase_23011
//
class SkillPhase_23011 : public SkillPhase {
public:
    SkillPhase_23011(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_23011() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(23011, 2) // StartPhase
        CASE_CREATE_SKILL_NODE(23011, 4) // TriggerUpdate
        CASE_CREATE_SKILL_NODE(23011, 6) // PlayAnimation
        CASE_CREATE_SKILL_NODE(23011, 8) // Delay
        CASE_CREATE_SKILL_NODE(23011, 10) // GetLocation
        CASE_CREATE_SKILL_NODE(23011, 12) // ResetCD
        CASE_CREATE_SKILL_NODE(23011, 14) // GetRotation
        CASE_CREATE_SKILL_NODE(23011, 16) // SpawnCollider
        CASE_CREATE_SKILL_NODE(23011, 18) // SpawnCollider
        CASE_CREATE_SKILL_NODE(23011, 30) // Delay
        CASE_CREATE_SKILL_NODE(23011, 32) // EndPhase
        CASE_CREATE_SKILL_NODE(23011, 34) // Detect
        CASE_CREATE_SKILL_NODE(23011, 36) // EndPhase
        CASE_CREATE_SKILL_NODE(23011, 38) // PlaySound
        CASE_CREATE_SKILL_NODE(23011, 54) // Delay
        CASE_CREATE_SKILL_NODE(23011, 57) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(23011, 58) // TriggerCheck
        CASE_CREATE_SKILL_NODE(23011, 59) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(23011, 60) // GetActorAttribute
        CASE_CREATE_SKILL_NODE(23011, 61) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(23011, 62) // CompareFloat
        CASE_CREATE_SKILL_NODE(23011, 63) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(23011, 64) // If
        CASE_CREATE_SKILL_NODE(23011, 65) // CompareFloat
        CASE_CREATE_SKILL_NODE(23011, 66) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(23011, 67) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(23011, 68) // TriggerCheck
        CASE_CREATE_SKILL_NODE(23011, 69) // TriggerCheck
        CASE_CREATE_SKILL_NODE(23011, 70) // TriggerCheck
        CASE_CREATE_SKILL_NODE(23011, 71) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(23011, 72) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(23011, 73) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(23011, 74) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(23011, 75) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(23011, 76) // AddSkillBuffs
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_23011

SkillLogic* SkillCreator_23011::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //创建阶段phase
    auto phase = new SkillPhase_23011(1, logic, 3);
    //设置phase执行器
    phase->setRunPhaseNode(1, 2);
    phase->setRunPhaseNode(2, 4);
    phase->setDetectPhaseNode(3, 34);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_23011::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
