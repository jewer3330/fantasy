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
REGISTER_REGISTER_SKILL_NODE(23031, 2) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_StartPhase::TRIGGER_START, 6, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(23031, 2) {
    auto node2 = GET_SKILL_NODE(2, PhaseNode_StartPhase);
    if (node2 == nullptr) {
        node2 = new PhaseNode_StartPhase(2, phase);
        CALL_REGISTER_SKILL_NODE(23031, 2, node2)
    }
    if (noInit == true) {
        return node2;
    }
    return node2;
}
//--------------------------------------------------------------------------------
// TriggerUpdate
//
REGISTER_REGISTER_SKILL_NODE(23031, 4) {
}

REGISTER_CREATE_SKILL_NODE(23031, 4) {
    auto node4 = GET_SKILL_NODE(4, PhaseNode_TriggerUpdate);
    if (node4 == nullptr) {
        node4 = new PhaseNode_TriggerUpdate(4, phase);
        CALL_REGISTER_SKILL_NODE(23031, 4, node4)
    }
    if (noInit == true) {
        return node4;
    }
    return node4;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(23031, 6) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_ResetCD::TRIGGER_DONE, 9, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(23031, 6) {
    auto node6 = GET_SKILL_NODE(6, PhaseNode_ResetCD);
    if (node6 == nullptr) {
        node6 = new PhaseNode_ResetCD(6, phase);
        node6->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node6->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node6->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(23031, 6, node6)
    }
    if (noInit == true) {
        return node6;
    }
    return node6;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(23031, 9) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetRotation>(PhaseNode_GetLocation::TRIGGER_DONE, 11, PhaseNode_GetRotation::FUNC_DO, &PhaseNode_GetRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(23031, 9) {
    auto node9 = GET_SKILL_NODE(9, PhaseNode_GetLocation);
    if (node9 == nullptr) {
        node9 = new PhaseNode_GetLocation(9, phase);
        node9->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node9->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(23031, 9, node9)
    }
    if (noInit == true) {
        return node9;
    }
    return node9;
}
//--------------------------------------------------------------------------------
// GetRotation
//
REGISTER_REGISTER_SKILL_NODE(23031, 11) {
    pnode->resizeTrigger(PhaseNode_GetRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_GetRotation::TRIGGER_DONE, 13, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(23031, 11) {
    auto node11 = GET_SKILL_NODE(11, PhaseNode_GetRotation);
    if (node11 == nullptr) {
        node11 = new PhaseNode_GetRotation(11, phase);
        node11->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node11->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(23031, 11, node11)
    }
    if (noInit == true) {
        return node11;
    }
    return node11;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(23031, 13) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlayAnimation::TRIGGER_DONE, 16, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_PlayAnimation::TRIGGER_DONE, 43, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(23031, 13) {
    auto node13 = GET_SKILL_NODE(13, PhaseNode_PlayAnimation);
    if (node13 == nullptr) {
        node13 = new PhaseNode_PlayAnimation(13, phase);
        node13->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node13->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node13->setTarget(0U);
        node13->setAnimation("Skill1S1");
        node13->setParameter("");
        node13->setValue(false);
        CALL_REGISTER_SKILL_NODE(23031, 13, node13)
    }
    if (noInit == true) {
        return node13;
    }
    return node13;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(23031, 16) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnCollider>(PhaseNode_Delay::TRIGGER_DONE, 18, PhaseNode_SpawnCollider::FUNC_DO, &PhaseNode_SpawnCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(23031, 16) {
    auto node16 = GET_SKILL_NODE(16, PhaseNode_Delay);
    if (node16 == nullptr) {
        node16 = new PhaseNode_Delay(16, phase);
        node16->setTime(.50f);
        CALL_REGISTER_SKILL_NODE(23031, 16, node16)
    }
    if (noInit == true) {
        return node16;
    }
    return node16;
}
//--------------------------------------------------------------------------------
// SpawnCollider
//
REGISTER_REGISTER_SKILL_NODE(23031, 18) {
    pnode->resizeTrigger(PhaseNode_SpawnCollider::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_SpawnCollider::TRIGGER_DONE, 31, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_SpawnCollider>(PhaseNode_SpawnCollider::TRIGGER_DONE, 20, PhaseNode_SpawnCollider::FUNC_DO, &PhaseNode_SpawnCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(23031, 18) {
    auto node18 = GET_SKILL_NODE(18, PhaseNode_SpawnCollider);
    if (node18 == nullptr) {
        node18 = new PhaseNode_SpawnCollider(18, phase);
        node18->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node18->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node18->setMesh("");
        node18->setMeshScale(.00f);
        node18->setEffectID(230321);
        node18->setEffectScale(1.00f);
        node18->setType(PhaseNode_SpawnCollider::SpawnCollider_Type::Circle);
        node18->setTypeParams(0, .00f);
        node18->setTime(.00f);
        node18->setPosZ(.00f);
        node18->setreentry(false);
        node18->setCheckPeneSound(false);
        CALL_REGISTER_SKILL_NODE(23031, 18, node18)
    }
    if (noInit == true) {
        return node18;
    }
    auto node9 = GET_SKILL_NODE(9, PhaseNode_GetLocation);
    auto node11 = GET_SKILL_NODE(11, PhaseNode_GetRotation);
    if (node9 != nullptr) node18->setPosX(node9->getX());
    if (node9 != nullptr) node18->setPosY(node9->getY());
    if (node11 != nullptr) node18->setRotation(node11->getAngle());
    return node18;
}
//--------------------------------------------------------------------------------
// SpawnCollider
//
REGISTER_REGISTER_SKILL_NODE(23031, 20) {
    pnode->resizeTrigger(PhaseNode_SpawnCollider::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_SpawnCollider::TRIGGER_DONE, 62, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(23031, 20) {
    auto node20 = GET_SKILL_NODE(20, PhaseNode_SpawnCollider);
    if (node20 == nullptr) {
        node20 = new PhaseNode_SpawnCollider(20, phase);
        node20->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node20->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node20->setMesh("");
        node20->setMeshScale(.00f);
        node20->setEffectID(0);
        node20->setEffectScale(.00f);
        node20->setType(PhaseNode_SpawnCollider::SpawnCollider_Type::Circle);
        node20->setTypeParams(0, 4.00f);
        node20->setTime(.40f);
        node20->setPosZ(.00f);
        node20->setreentry(false);
        node20->setCheckPeneSound(false);
        CALL_REGISTER_SKILL_NODE(23031, 20, node20)
    }
    if (noInit == true) {
        return node20;
    }
    auto node9 = GET_SKILL_NODE(9, PhaseNode_GetLocation);
    auto node11 = GET_SKILL_NODE(11, PhaseNode_GetRotation);
    if (node9 != nullptr) node20->setPosX(node9->getX());
    if (node9 != nullptr) node20->setPosY(node9->getY());
    if (node11 != nullptr) node20->setRotation(node11->getAngle());
    return node20;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(23031, 31) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_Delay::TRIGGER_DONE, 33, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(23031, 31) {
    auto node31 = GET_SKILL_NODE(31, PhaseNode_Delay);
    if (node31 == nullptr) {
        node31 = new PhaseNode_Delay(31, phase);
        node31->setTime(.70f);
        CALL_REGISTER_SKILL_NODE(23031, 31, node31)
    }
    if (noInit == true) {
        return node31;
    }
    return node31;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(23031, 33) {
}

REGISTER_CREATE_SKILL_NODE(23031, 33) {
    auto node33 = GET_SKILL_NODE(33, PhaseNode_EndPhase);
    if (node33 == nullptr) {
        node33 = new PhaseNode_EndPhase(33, phase);
        node33->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node33->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(23031, 33, node33)
    }
    if (noInit == true) {
        return node33;
    }
    return node33;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(23031, 35) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_Detect::TRIGGER_ON, 37, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(23031, 35) {
    auto node35 = GET_SKILL_NODE(35, PhaseNode_Detect);
    if (node35 == nullptr) {
        node35 = new PhaseNode_Detect(35, phase);
        node35->setSelf(0U);
        node35->setEvent("");
        node35->setType(PhaseNode_Detect::Detect_Type::Actor_Dead);
        node35->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(23031, 35, node35)
    }
    if (noInit == true) {
        return node35;
    }
    return node35;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(23031, 37) {
}

REGISTER_CREATE_SKILL_NODE(23031, 37) {
    auto node37 = GET_SKILL_NODE(37, PhaseNode_EndPhase);
    if (node37 == nullptr) {
        node37 = new PhaseNode_EndPhase(37, phase);
        node37->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node37->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(23031, 37, node37)
    }
    if (noInit == true) {
        return node37;
    }
    return node37;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(23031, 43) {
}

REGISTER_CREATE_SKILL_NODE(23031, 43) {
    auto node43 = GET_SKILL_NODE(43, PhaseNode_PlaySound);
    if (node43 == nullptr) {
        node43 = new PhaseNode_PlaySound(43, phase);
        node43->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node43->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node43->setSoundID("SE_MON2303_ATK2_P1");
        node43->setTarget(0U);
        node43->setUsePos(false);
        node43->setPosX(.00f);
        node43->setPosY(.00f);
        node43->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(23031, 43, node43)
    }
    if (noInit == true) {
        return node43;
    }
    return node43;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(23031, 55) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 67, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 69, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(23031, 55) {
    auto node55 = GET_SKILL_NODE(55, PhaseNode_CreateTriggerNewPene);
    if (node55 == nullptr) {
        node55 = new PhaseNode_CreateTriggerNewPene(55, phase);
        node55->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::In);
        node55->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node55->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Enemy);
        node55->setOnHero(true);
        node55->setOnMinion(true);
        node55->setOnDestruct(true);
        node55->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(23031, 55, node55)
    }
    if (noInit == true) {
        return node55;
    }
    auto node20 = GET_SKILL_NODE(20, PhaseNode_SpawnCollider);
    if (node20 != nullptr) node55->setColliderID(node20->getColliderID());
    return node55;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(23031, 56) {
}

REGISTER_CREATE_SKILL_NODE(23031, 56) {
    auto node56 = GET_SKILL_NODE(56, PhaseNode_TriggerCheck);
    if (node56 == nullptr) {
        node56 = new PhaseNode_TriggerCheck(56, phase);
        auto node4 = GET_SKILL_NODE(4, PhaseNode_TriggerUpdate);
        if (node4 != nullptr) node4->addTriggerCheck(node56);
        
        CALL_REGISTER_SKILL_NODE(23031, 56, node56)
    }
    if (noInit == true) {
        return node56;
    }
    auto node65 = GET_SKILL_NODE(65, PhaseNode_CreateTriggerNewPene);
    if (node65 != nullptr) node56->setTrigger(0, node65->getTriggerID());
    return node56;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(23031, 57) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 58, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(23031, 57) {
    auto node57 = GET_SKILL_NODE(57, PhaseNode_ActorFilterNewPene);
    if (node57 == nullptr) {
        node57 = new PhaseNode_ActorFilterNewPene(57, phase);
        node57->setHero(true);
        node57->setMinion(true);
        node57->setDestruct(true);
        node57->setShield(false);
        node57->setTotalCount(0);
        node57->setPerCount(1);
        CALL_REGISTER_SKILL_NODE(23031, 57, node57)
    }
    if (noInit == true) {
        return node57;
    }
    auto node61 = GET_SKILL_NODE(61, PhaseNode_CreateTriggerNewPene);
    if (node61 != nullptr) node57->setInput(node61->getOther());
    return node57;
}
//--------------------------------------------------------------------------------
// GetActorAttribute
//
REGISTER_REGISTER_SKILL_NODE(23031, 58) {
    pnode->resizeTrigger(PhaseNode_GetActorAttribute::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 59, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 72, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 73, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 74, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
}

REGISTER_CREATE_SKILL_NODE(23031, 58) {
    auto node58 = GET_SKILL_NODE(58, PhaseNode_GetActorAttribute);
    if (node58 == nullptr) {
        node58 = new PhaseNode_GetActorAttribute(58, phase);
        node58->setTarget(0U);
        node58->setType({202});
        CALL_REGISTER_SKILL_NODE(23031, 58, node58)
    }
    if (noInit == true) {
        return node58;
    }
    return node58;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(23031, 59) {
}

REGISTER_CREATE_SKILL_NODE(23031, 59) {
    auto node59 = GET_SKILL_NODE(59, PhaseNode_AddSkillBuffs);
    if (node59 == nullptr) {
        node59 = new PhaseNode_AddSkillBuffs(59, phase);
        node59->setConfigID({230321});
        CALL_REGISTER_SKILL_NODE(23031, 59, node59)
    }
    if (noInit == true) {
        return node59;
    }
    auto node57 = GET_SKILL_NODE(57, PhaseNode_ActorFilterNewPene);
    auto node58 = GET_SKILL_NODE(58, PhaseNode_GetActorAttribute);
    if (node57 != nullptr) node59->setTarget(node57->getOutput());
    if (node58 != nullptr) node59->setAttribute(node58->getAttribute());
    return node59;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(23031, 60) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 55, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_LESS, 61, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
}

REGISTER_CREATE_SKILL_NODE(23031, 60) {
    auto node60 = GET_SKILL_NODE(60, PhaseNode_CompareFloat);
    if (node60 == nullptr) {
        node60 = new PhaseNode_CompareFloat(60, phase);
        node60->setA(.00f);
        node60->setB(.00f);
        CALL_REGISTER_SKILL_NODE(23031, 60, node60)
    }
    if (noInit == true) {
        return node60;
    }
    return node60;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(23031, 61) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 66, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 57, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(23031, 61) {
    auto node61 = GET_SKILL_NODE(61, PhaseNode_CreateTriggerNewPene);
    if (node61 == nullptr) {
        node61 = new PhaseNode_CreateTriggerNewPene(61, phase);
        node61->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::Tick);
        node61->setTypeParams(0, .00f);
        node61->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node61->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Enemy);
        node61->setOnHero(true);
        node61->setOnMinion(true);
        node61->setOnDestruct(true);
        node61->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(23031, 61, node61)
    }
    if (noInit == true) {
        return node61;
    }
    auto node20 = GET_SKILL_NODE(20, PhaseNode_SpawnCollider);
    if (node20 != nullptr) node61->setColliderID(node20->getColliderID());
    return node61;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(23031, 62) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_If::TRIGGER_FALSE, 63, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_If::TRIGGER_TRUE, 60, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(23031, 62) {
    auto node62 = GET_SKILL_NODE(62, PhaseNode_If);
    if (node62 == nullptr) {
        node62 = new PhaseNode_If(62, phase);
        node62->setCondition(false);
        CALL_REGISTER_SKILL_NODE(23031, 62, node62)
    }
    if (noInit == true) {
        return node62;
    }
    return node62;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(23031, 63) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 65, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_LESS, 64, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
}

REGISTER_CREATE_SKILL_NODE(23031, 63) {
    auto node63 = GET_SKILL_NODE(63, PhaseNode_CompareFloat);
    if (node63 == nullptr) {
        node63 = new PhaseNode_CompareFloat(63, phase);
        node63->setA(.00f);
        node63->setB(.00f);
        CALL_REGISTER_SKILL_NODE(23031, 63, node63)
    }
    if (noInit == true) {
        return node63;
    }
    return node63;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(23031, 64) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 68, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 70, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(23031, 64) {
    auto node64 = GET_SKILL_NODE(64, PhaseNode_CreateTriggerNewPene);
    if (node64 == nullptr) {
        node64 = new PhaseNode_CreateTriggerNewPene(64, phase);
        node64->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::Tick);
        node64->setTypeParams(0, .00f);
        node64->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node64->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Friend);
        node64->setOnHero(true);
        node64->setOnMinion(true);
        node64->setOnDestruct(true);
        node64->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(23031, 64, node64)
    }
    if (noInit == true) {
        return node64;
    }
    auto node20 = GET_SKILL_NODE(20, PhaseNode_SpawnCollider);
    if (node20 != nullptr) node64->setColliderID(node20->getColliderID());
    return node64;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(23031, 65) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 56, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 71, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(23031, 65) {
    auto node65 = GET_SKILL_NODE(65, PhaseNode_CreateTriggerNewPene);
    if (node65 == nullptr) {
        node65 = new PhaseNode_CreateTriggerNewPene(65, phase);
        node65->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::In);
        node65->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node65->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Friend);
        node65->setOnHero(true);
        node65->setOnMinion(true);
        node65->setOnDestruct(true);
        node65->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(23031, 65, node65)
    }
    if (noInit == true) {
        return node65;
    }
    auto node20 = GET_SKILL_NODE(20, PhaseNode_SpawnCollider);
    if (node20 != nullptr) node65->setColliderID(node20->getColliderID());
    return node65;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(23031, 66) {
}

REGISTER_CREATE_SKILL_NODE(23031, 66) {
    auto node66 = GET_SKILL_NODE(66, PhaseNode_TriggerCheck);
    if (node66 == nullptr) {
        node66 = new PhaseNode_TriggerCheck(66, phase);
        auto node4 = GET_SKILL_NODE(4, PhaseNode_TriggerUpdate);
        if (node4 != nullptr) node4->addTriggerCheck(node66);
        
        CALL_REGISTER_SKILL_NODE(23031, 66, node66)
    }
    if (noInit == true) {
        return node66;
    }
    auto node61 = GET_SKILL_NODE(61, PhaseNode_CreateTriggerNewPene);
    if (node61 != nullptr) node66->setTrigger(0, node61->getTriggerID());
    return node66;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(23031, 67) {
}

REGISTER_CREATE_SKILL_NODE(23031, 67) {
    auto node67 = GET_SKILL_NODE(67, PhaseNode_TriggerCheck);
    if (node67 == nullptr) {
        node67 = new PhaseNode_TriggerCheck(67, phase);
        auto node4 = GET_SKILL_NODE(4, PhaseNode_TriggerUpdate);
        if (node4 != nullptr) node4->addTriggerCheck(node67);
        
        CALL_REGISTER_SKILL_NODE(23031, 67, node67)
    }
    if (noInit == true) {
        return node67;
    }
    auto node55 = GET_SKILL_NODE(55, PhaseNode_CreateTriggerNewPene);
    if (node55 != nullptr) node67->setTrigger(0, node55->getTriggerID());
    return node67;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(23031, 68) {
}

REGISTER_CREATE_SKILL_NODE(23031, 68) {
    auto node68 = GET_SKILL_NODE(68, PhaseNode_TriggerCheck);
    if (node68 == nullptr) {
        node68 = new PhaseNode_TriggerCheck(68, phase);
        auto node4 = GET_SKILL_NODE(4, PhaseNode_TriggerUpdate);
        if (node4 != nullptr) node4->addTriggerCheck(node68);
        
        CALL_REGISTER_SKILL_NODE(23031, 68, node68)
    }
    if (noInit == true) {
        return node68;
    }
    auto node64 = GET_SKILL_NODE(64, PhaseNode_CreateTriggerNewPene);
    if (node64 != nullptr) node68->setTrigger(0, node64->getTriggerID());
    return node68;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(23031, 69) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 58, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(23031, 69) {
    auto node69 = GET_SKILL_NODE(69, PhaseNode_ActorFilterNewPene);
    if (node69 == nullptr) {
        node69 = new PhaseNode_ActorFilterNewPene(69, phase);
        node69->setHero(true);
        node69->setMinion(true);
        node69->setDestruct(true);
        node69->setShield(false);
        node69->setTotalCount(0);
        node69->setPerCount(1);
        CALL_REGISTER_SKILL_NODE(23031, 69, node69)
    }
    if (noInit == true) {
        return node69;
    }
    auto node55 = GET_SKILL_NODE(55, PhaseNode_CreateTriggerNewPene);
    if (node55 != nullptr) node69->setInput(node55->getOther());
    return node69;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(23031, 70) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 58, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(23031, 70) {
    auto node70 = GET_SKILL_NODE(70, PhaseNode_ActorFilterNewPene);
    if (node70 == nullptr) {
        node70 = new PhaseNode_ActorFilterNewPene(70, phase);
        node70->setHero(true);
        node70->setMinion(true);
        node70->setDestruct(true);
        node70->setShield(false);
        node70->setTotalCount(0);
        node70->setPerCount(1);
        CALL_REGISTER_SKILL_NODE(23031, 70, node70)
    }
    if (noInit == true) {
        return node70;
    }
    auto node64 = GET_SKILL_NODE(64, PhaseNode_CreateTriggerNewPene);
    if (node64 != nullptr) node70->setInput(node64->getOther());
    return node70;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(23031, 71) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 58, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(23031, 71) {
    auto node71 = GET_SKILL_NODE(71, PhaseNode_ActorFilterNewPene);
    if (node71 == nullptr) {
        node71 = new PhaseNode_ActorFilterNewPene(71, phase);
        node71->setHero(true);
        node71->setMinion(true);
        node71->setDestruct(true);
        node71->setShield(false);
        node71->setTotalCount(0);
        node71->setPerCount(1);
        CALL_REGISTER_SKILL_NODE(23031, 71, node71)
    }
    if (noInit == true) {
        return node71;
    }
    auto node65 = GET_SKILL_NODE(65, PhaseNode_CreateTriggerNewPene);
    if (node65 != nullptr) node71->setInput(node65->getOther());
    return node71;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(23031, 72) {
}

REGISTER_CREATE_SKILL_NODE(23031, 72) {
    auto node72 = GET_SKILL_NODE(72, PhaseNode_AddSkillBuffs);
    if (node72 == nullptr) {
        node72 = new PhaseNode_AddSkillBuffs(72, phase);
        node72->setConfigID({230321});
        CALL_REGISTER_SKILL_NODE(23031, 72, node72)
    }
    if (noInit == true) {
        return node72;
    }
    auto node69 = GET_SKILL_NODE(69, PhaseNode_ActorFilterNewPene);
    auto node58 = GET_SKILL_NODE(58, PhaseNode_GetActorAttribute);
    if (node69 != nullptr) node72->setTarget(node69->getOutput());
    if (node58 != nullptr) node72->setAttribute(node58->getAttribute());
    return node72;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(23031, 73) {
}

REGISTER_CREATE_SKILL_NODE(23031, 73) {
    auto node73 = GET_SKILL_NODE(73, PhaseNode_AddSkillBuffs);
    if (node73 == nullptr) {
        node73 = new PhaseNode_AddSkillBuffs(73, phase);
        node73->setConfigID({230321});
        CALL_REGISTER_SKILL_NODE(23031, 73, node73)
    }
    if (noInit == true) {
        return node73;
    }
    auto node70 = GET_SKILL_NODE(70, PhaseNode_ActorFilterNewPene);
    auto node58 = GET_SKILL_NODE(58, PhaseNode_GetActorAttribute);
    if (node70 != nullptr) node73->setTarget(node70->getOutput());
    if (node58 != nullptr) node73->setAttribute(node58->getAttribute());
    return node73;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(23031, 74) {
}

REGISTER_CREATE_SKILL_NODE(23031, 74) {
    auto node74 = GET_SKILL_NODE(74, PhaseNode_AddSkillBuffs);
    if (node74 == nullptr) {
        node74 = new PhaseNode_AddSkillBuffs(74, phase);
        node74->setConfigID({230321});
        CALL_REGISTER_SKILL_NODE(23031, 74, node74)
    }
    if (noInit == true) {
        return node74;
    }
    auto node71 = GET_SKILL_NODE(71, PhaseNode_ActorFilterNewPene);
    auto node58 = GET_SKILL_NODE(58, PhaseNode_GetActorAttribute);
    if (node71 != nullptr) node74->setTarget(node71->getOutput());
    if (node58 != nullptr) node74->setAttribute(node58->getAttribute());
    return node74;
}

//--------------------------------------------------------------------------------
// SkillCreator_23031
//
class SkillCreator_23031 : public SkillCreator {
public:
    SkillCreator_23031() {}
    virtual ~SkillCreator_23031() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_23031

//--------------------------------------------------------------------------------
// SkillPhase_23031
//
class SkillPhase_23031 : public SkillPhase {
public:
    SkillPhase_23031(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_23031() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(23031, 2) // StartPhase
        CASE_CREATE_SKILL_NODE(23031, 4) // TriggerUpdate
        CASE_CREATE_SKILL_NODE(23031, 6) // ResetCD
        CASE_CREATE_SKILL_NODE(23031, 9) // GetLocation
        CASE_CREATE_SKILL_NODE(23031, 11) // GetRotation
        CASE_CREATE_SKILL_NODE(23031, 13) // PlayAnimation
        CASE_CREATE_SKILL_NODE(23031, 16) // Delay
        CASE_CREATE_SKILL_NODE(23031, 18) // SpawnCollider
        CASE_CREATE_SKILL_NODE(23031, 20) // SpawnCollider
        CASE_CREATE_SKILL_NODE(23031, 31) // Delay
        CASE_CREATE_SKILL_NODE(23031, 33) // EndPhase
        CASE_CREATE_SKILL_NODE(23031, 35) // Detect
        CASE_CREATE_SKILL_NODE(23031, 37) // EndPhase
        CASE_CREATE_SKILL_NODE(23031, 43) // PlaySound
        CASE_CREATE_SKILL_NODE(23031, 55) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(23031, 56) // TriggerCheck
        CASE_CREATE_SKILL_NODE(23031, 57) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(23031, 58) // GetActorAttribute
        CASE_CREATE_SKILL_NODE(23031, 59) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(23031, 60) // CompareFloat
        CASE_CREATE_SKILL_NODE(23031, 61) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(23031, 62) // If
        CASE_CREATE_SKILL_NODE(23031, 63) // CompareFloat
        CASE_CREATE_SKILL_NODE(23031, 64) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(23031, 65) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(23031, 66) // TriggerCheck
        CASE_CREATE_SKILL_NODE(23031, 67) // TriggerCheck
        CASE_CREATE_SKILL_NODE(23031, 68) // TriggerCheck
        CASE_CREATE_SKILL_NODE(23031, 69) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(23031, 70) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(23031, 71) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(23031, 72) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(23031, 73) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(23031, 74) // AddSkillBuffs
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_23031

SkillLogic* SkillCreator_23031::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //创建阶段phase
    auto phase = new SkillPhase_23031(1, logic, 3);
    //设置phase执行器
    phase->setRunPhaseNode(1, 2);
    phase->setRunPhaseNode(2, 4);
    phase->setDetectPhaseNode(3, 35);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_23031::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
