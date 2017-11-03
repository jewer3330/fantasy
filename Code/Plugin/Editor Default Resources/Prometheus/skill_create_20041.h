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
REGISTER_REGISTER_SKILL_NODE(20041, 46) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_StartPhase::TRIGGER_START, 238, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_StartPhase::TRIGGER_START, 215, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(20041, 46) {
    auto node46 = GET_SKILL_NODE(46, PhaseNode_StartPhase);
    if (node46 == nullptr) {
        node46 = new PhaseNode_StartPhase(46, phase);
        CALL_REGISTER_SKILL_NODE(20041, 46, node46)
    }
    if (noInit == true) {
        return node46;
    }
    return node46;
}
//--------------------------------------------------------------------------------
// TriggerUpdate
//
REGISTER_REGISTER_SKILL_NODE(20041, 47) {
}

REGISTER_CREATE_SKILL_NODE(20041, 47) {
    auto node47 = GET_SKILL_NODE(47, PhaseNode_TriggerUpdate);
    if (node47 == nullptr) {
        node47 = new PhaseNode_TriggerUpdate(47, phase);
        CALL_REGISTER_SKILL_NODE(20041, 47, node47)
    }
    if (noInit == true) {
        return node47;
    }
    return node47;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(20041, 52) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_Delay::TRIGGER_DONE, 153, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(20041, 52) {
    auto node52 = GET_SKILL_NODE(52, PhaseNode_Delay);
    if (node52 == nullptr) {
        node52 = new PhaseNode_Delay(52, phase);
        node52->setTime(.70f);
        CALL_REGISTER_SKILL_NODE(20041, 52, node52)
    }
    if (noInit == true) {
        return node52;
    }
    return node52;
}
//--------------------------------------------------------------------------------
// SpawnCollider
//
REGISTER_REGISTER_SKILL_NODE(20041, 53) {
    pnode->resizeTrigger(PhaseNode_SpawnCollider::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_SpawnCollider::TRIGGER_DONE, 228, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_SpawnCollider::TRIGGER_DONE, 202, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(20041, 53) {
    auto node53 = GET_SKILL_NODE(53, PhaseNode_SpawnCollider);
    if (node53 == nullptr) {
        node53 = new PhaseNode_SpawnCollider(53, phase);
        node53->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node53->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node53->setMesh("");
        node53->setMeshScale(.00f);
        node53->setEffectID(0);
        node53->setEffectScale(.00f);
        node53->setType(PhaseNode_SpawnCollider::SpawnCollider_Type::Sector);
        node53->setTypeParams(0, 7.00f);
        node53->setTypeParams(1, 120.00f);
        node53->setTime(.30f);
        node53->setreentry(false);
        node53->setCheckPeneSound(false);
        CALL_REGISTER_SKILL_NODE(20041, 53, node53)
    }
    if (noInit == true) {
        return node53;
    }
    auto node221 = GET_SKILL_NODE(221, PhaseNode_OffsetCalculate);
    if (node221 != nullptr) node53->setPosX(node221->getOutPosX());
    if (node221 != nullptr) node53->setPosY(node221->getOutPosY());
    if (node221 != nullptr) node53->setPosZ(node221->getOutPosZ());
    if (node221 != nullptr) node53->setRotation(node221->getOutRotation());
    return node53;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(20041, 94) {
}

REGISTER_CREATE_SKILL_NODE(20041, 94) {
    auto node94 = GET_SKILL_NODE(94, PhaseNode_EndPhase);
    if (node94 == nullptr) {
        node94 = new PhaseNode_EndPhase(94, phase);
        node94->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node94->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(20041, 94, node94)
    }
    if (noInit == true) {
        return node94;
    }
    return node94;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(20041, 142) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_Detect::TRIGGER_ON, 143, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(20041, 142) {
    auto node142 = GET_SKILL_NODE(142, PhaseNode_Detect);
    if (node142 == nullptr) {
        node142 = new PhaseNode_Detect(142, phase);
        node142->setSelf(0U);
        node142->setEvent("");
        node142->setType(PhaseNode_Detect::Detect_Type::Actor_Dead);
        node142->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(20041, 142, node142)
    }
    if (noInit == true) {
        return node142;
    }
    return node142;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(20041, 143) {
}

REGISTER_CREATE_SKILL_NODE(20041, 143) {
    auto node143 = GET_SKILL_NODE(143, PhaseNode_EndPhase);
    if (node143 == nullptr) {
        node143 = new PhaseNode_EndPhase(143, phase);
        node143->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node143->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(20041, 143, node143)
    }
    if (noInit == true) {
        return node143;
    }
    return node143;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(20041, 153) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnCollider>(PhaseNode_PlaySound::TRIGGER_DONE, 53, PhaseNode_SpawnCollider::FUNC_DO, &PhaseNode_SpawnCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(20041, 153) {
    auto node153 = GET_SKILL_NODE(153, PhaseNode_PlaySound);
    if (node153 == nullptr) {
        node153 = new PhaseNode_PlaySound(153, phase);
        node153->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node153->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node153->setSoundID("SE_MON2004_Skill_C_P1");
        node153->setTarget(0U);
        node153->setUsePos(false);
        node153->setPosX(.00f);
        node153->setPosY(.00f);
        node153->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(20041, 153, node153)
    }
    if (noInit == true) {
        return node153;
    }
    return node153;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(20041, 169) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_PlaySound::TRIGGER_DONE, 219, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(20041, 169) {
    auto node169 = GET_SKILL_NODE(169, PhaseNode_PlaySound);
    if (node169 == nullptr) {
        node169 = new PhaseNode_PlaySound(169, phase);
        node169->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node169->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node169->setSoundID("VO_MON2004_Charge");
        node169->setTarget(0U);
        node169->setUsePos(false);
        node169->setPosX(.00f);
        node169->setPosY(.00f);
        node169->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(20041, 169, node169)
    }
    if (noInit == true) {
        return node169;
    }
    return node169;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(20041, 195) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 207, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 209, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(20041, 195) {
    auto node195 = GET_SKILL_NODE(195, PhaseNode_CreateTriggerNewPene);
    if (node195 == nullptr) {
        node195 = new PhaseNode_CreateTriggerNewPene(195, phase);
        node195->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::In);
        node195->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node195->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Enemy);
        node195->setOnHero(true);
        node195->setOnMinion(true);
        node195->setOnDestruct(true);
        node195->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(20041, 195, node195)
    }
    if (noInit == true) {
        return node195;
    }
    auto node53 = GET_SKILL_NODE(53, PhaseNode_SpawnCollider);
    if (node53 != nullptr) node195->setColliderID(node53->getColliderID());
    return node195;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(20041, 196) {
}

REGISTER_CREATE_SKILL_NODE(20041, 196) {
    auto node196 = GET_SKILL_NODE(196, PhaseNode_TriggerCheck);
    if (node196 == nullptr) {
        node196 = new PhaseNode_TriggerCheck(196, phase);
        auto node47 = GET_SKILL_NODE(47, PhaseNode_TriggerUpdate);
        if (node47 != nullptr) node47->addTriggerCheck(node196);
        
        CALL_REGISTER_SKILL_NODE(20041, 196, node196)
    }
    if (noInit == true) {
        return node196;
    }
    auto node205 = GET_SKILL_NODE(205, PhaseNode_CreateTriggerNewPene);
    if (node205 != nullptr) node196->setTrigger(0, node205->getTriggerID());
    return node196;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(20041, 197) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 198, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(20041, 197) {
    auto node197 = GET_SKILL_NODE(197, PhaseNode_ActorFilterNewPene);
    if (node197 == nullptr) {
        node197 = new PhaseNode_ActorFilterNewPene(197, phase);
        node197->setHero(true);
        node197->setMinion(true);
        node197->setDestruct(true);
        node197->setShield(false);
        node197->setTotalCount(0);
        node197->setPerCount(1);
        CALL_REGISTER_SKILL_NODE(20041, 197, node197)
    }
    if (noInit == true) {
        return node197;
    }
    auto node201 = GET_SKILL_NODE(201, PhaseNode_CreateTriggerNewPene);
    if (node201 != nullptr) node197->setInput(node201->getOther());
    return node197;
}
//--------------------------------------------------------------------------------
// GetActorAttribute
//
REGISTER_REGISTER_SKILL_NODE(20041, 198) {
    pnode->resizeTrigger(PhaseNode_GetActorAttribute::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 199, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 212, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 213, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 214, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
}

REGISTER_CREATE_SKILL_NODE(20041, 198) {
    auto node198 = GET_SKILL_NODE(198, PhaseNode_GetActorAttribute);
    if (node198 == nullptr) {
        node198 = new PhaseNode_GetActorAttribute(198, phase);
        node198->setTarget(0U);
        node198->setType({202});
        CALL_REGISTER_SKILL_NODE(20041, 198, node198)
    }
    if (noInit == true) {
        return node198;
    }
    return node198;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(20041, 199) {
}

REGISTER_CREATE_SKILL_NODE(20041, 199) {
    auto node199 = GET_SKILL_NODE(199, PhaseNode_AddSkillBuffs);
    if (node199 == nullptr) {
        node199 = new PhaseNode_AddSkillBuffs(199, phase);
        node199->setConfigID({13});
        CALL_REGISTER_SKILL_NODE(20041, 199, node199)
    }
    if (noInit == true) {
        return node199;
    }
    auto node197 = GET_SKILL_NODE(197, PhaseNode_ActorFilterNewPene);
    auto node198 = GET_SKILL_NODE(198, PhaseNode_GetActorAttribute);
    if (node197 != nullptr) node199->setTarget(node197->getOutput());
    if (node198 != nullptr) node199->setAttribute(node198->getAttribute());
    return node199;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(20041, 200) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 195, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_LESS, 201, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
}

REGISTER_CREATE_SKILL_NODE(20041, 200) {
    auto node200 = GET_SKILL_NODE(200, PhaseNode_CompareFloat);
    if (node200 == nullptr) {
        node200 = new PhaseNode_CompareFloat(200, phase);
        node200->setA(.00f);
        node200->setB(.00f);
        CALL_REGISTER_SKILL_NODE(20041, 200, node200)
    }
    if (noInit == true) {
        return node200;
    }
    return node200;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(20041, 201) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 206, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 197, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(20041, 201) {
    auto node201 = GET_SKILL_NODE(201, PhaseNode_CreateTriggerNewPene);
    if (node201 == nullptr) {
        node201 = new PhaseNode_CreateTriggerNewPene(201, phase);
        node201->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::Tick);
        node201->setTypeParams(0, .00f);
        node201->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node201->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Enemy);
        node201->setOnHero(true);
        node201->setOnMinion(true);
        node201->setOnDestruct(true);
        node201->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(20041, 201, node201)
    }
    if (noInit == true) {
        return node201;
    }
    auto node53 = GET_SKILL_NODE(53, PhaseNode_SpawnCollider);
    if (node53 != nullptr) node201->setColliderID(node53->getColliderID());
    return node201;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(20041, 202) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_If::TRIGGER_FALSE, 203, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_If::TRIGGER_TRUE, 200, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(20041, 202) {
    auto node202 = GET_SKILL_NODE(202, PhaseNode_If);
    if (node202 == nullptr) {
        node202 = new PhaseNode_If(202, phase);
        node202->setCondition(true);
        CALL_REGISTER_SKILL_NODE(20041, 202, node202)
    }
    if (noInit == true) {
        return node202;
    }
    return node202;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(20041, 203) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 205, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_LESS, 204, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
}

REGISTER_CREATE_SKILL_NODE(20041, 203) {
    auto node203 = GET_SKILL_NODE(203, PhaseNode_CompareFloat);
    if (node203 == nullptr) {
        node203 = new PhaseNode_CompareFloat(203, phase);
        node203->setA(.00f);
        node203->setB(.00f);
        CALL_REGISTER_SKILL_NODE(20041, 203, node203)
    }
    if (noInit == true) {
        return node203;
    }
    return node203;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(20041, 204) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 208, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 210, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(20041, 204) {
    auto node204 = GET_SKILL_NODE(204, PhaseNode_CreateTriggerNewPene);
    if (node204 == nullptr) {
        node204 = new PhaseNode_CreateTriggerNewPene(204, phase);
        node204->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::Tick);
        node204->setTypeParams(0, .00f);
        node204->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node204->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Friend);
        node204->setOnHero(true);
        node204->setOnMinion(true);
        node204->setOnDestruct(true);
        node204->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(20041, 204, node204)
    }
    if (noInit == true) {
        return node204;
    }
    auto node53 = GET_SKILL_NODE(53, PhaseNode_SpawnCollider);
    if (node53 != nullptr) node204->setColliderID(node53->getColliderID());
    return node204;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(20041, 205) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 196, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 211, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(20041, 205) {
    auto node205 = GET_SKILL_NODE(205, PhaseNode_CreateTriggerNewPene);
    if (node205 == nullptr) {
        node205 = new PhaseNode_CreateTriggerNewPene(205, phase);
        node205->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::In);
        node205->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node205->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Friend);
        node205->setOnHero(true);
        node205->setOnMinion(true);
        node205->setOnDestruct(true);
        node205->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(20041, 205, node205)
    }
    if (noInit == true) {
        return node205;
    }
    auto node53 = GET_SKILL_NODE(53, PhaseNode_SpawnCollider);
    if (node53 != nullptr) node205->setColliderID(node53->getColliderID());
    return node205;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(20041, 206) {
}

REGISTER_CREATE_SKILL_NODE(20041, 206) {
    auto node206 = GET_SKILL_NODE(206, PhaseNode_TriggerCheck);
    if (node206 == nullptr) {
        node206 = new PhaseNode_TriggerCheck(206, phase);
        auto node47 = GET_SKILL_NODE(47, PhaseNode_TriggerUpdate);
        if (node47 != nullptr) node47->addTriggerCheck(node206);
        
        CALL_REGISTER_SKILL_NODE(20041, 206, node206)
    }
    if (noInit == true) {
        return node206;
    }
    auto node201 = GET_SKILL_NODE(201, PhaseNode_CreateTriggerNewPene);
    if (node201 != nullptr) node206->setTrigger(0, node201->getTriggerID());
    return node206;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(20041, 207) {
}

REGISTER_CREATE_SKILL_NODE(20041, 207) {
    auto node207 = GET_SKILL_NODE(207, PhaseNode_TriggerCheck);
    if (node207 == nullptr) {
        node207 = new PhaseNode_TriggerCheck(207, phase);
        auto node47 = GET_SKILL_NODE(47, PhaseNode_TriggerUpdate);
        if (node47 != nullptr) node47->addTriggerCheck(node207);
        
        CALL_REGISTER_SKILL_NODE(20041, 207, node207)
    }
    if (noInit == true) {
        return node207;
    }
    auto node195 = GET_SKILL_NODE(195, PhaseNode_CreateTriggerNewPene);
    if (node195 != nullptr) node207->setTrigger(0, node195->getTriggerID());
    return node207;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(20041, 208) {
}

REGISTER_CREATE_SKILL_NODE(20041, 208) {
    auto node208 = GET_SKILL_NODE(208, PhaseNode_TriggerCheck);
    if (node208 == nullptr) {
        node208 = new PhaseNode_TriggerCheck(208, phase);
        auto node47 = GET_SKILL_NODE(47, PhaseNode_TriggerUpdate);
        if (node47 != nullptr) node47->addTriggerCheck(node208);
        
        CALL_REGISTER_SKILL_NODE(20041, 208, node208)
    }
    if (noInit == true) {
        return node208;
    }
    auto node204 = GET_SKILL_NODE(204, PhaseNode_CreateTriggerNewPene);
    if (node204 != nullptr) node208->setTrigger(0, node204->getTriggerID());
    return node208;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(20041, 209) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 198, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(20041, 209) {
    auto node209 = GET_SKILL_NODE(209, PhaseNode_ActorFilterNewPene);
    if (node209 == nullptr) {
        node209 = new PhaseNode_ActorFilterNewPene(209, phase);
        node209->setHero(true);
        node209->setMinion(true);
        node209->setDestruct(true);
        node209->setShield(false);
        node209->setTotalCount(0);
        node209->setPerCount(1);
        CALL_REGISTER_SKILL_NODE(20041, 209, node209)
    }
    if (noInit == true) {
        return node209;
    }
    auto node195 = GET_SKILL_NODE(195, PhaseNode_CreateTriggerNewPene);
    if (node195 != nullptr) node209->setInput(node195->getOther());
    return node209;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(20041, 210) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 198, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(20041, 210) {
    auto node210 = GET_SKILL_NODE(210, PhaseNode_ActorFilterNewPene);
    if (node210 == nullptr) {
        node210 = new PhaseNode_ActorFilterNewPene(210, phase);
        node210->setHero(true);
        node210->setMinion(true);
        node210->setDestruct(true);
        node210->setShield(false);
        node210->setTotalCount(0);
        node210->setPerCount(1);
        CALL_REGISTER_SKILL_NODE(20041, 210, node210)
    }
    if (noInit == true) {
        return node210;
    }
    auto node204 = GET_SKILL_NODE(204, PhaseNode_CreateTriggerNewPene);
    if (node204 != nullptr) node210->setInput(node204->getOther());
    return node210;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(20041, 211) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 198, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(20041, 211) {
    auto node211 = GET_SKILL_NODE(211, PhaseNode_ActorFilterNewPene);
    if (node211 == nullptr) {
        node211 = new PhaseNode_ActorFilterNewPene(211, phase);
        node211->setHero(true);
        node211->setMinion(true);
        node211->setDestruct(true);
        node211->setShield(false);
        node211->setTotalCount(0);
        node211->setPerCount(1);
        CALL_REGISTER_SKILL_NODE(20041, 211, node211)
    }
    if (noInit == true) {
        return node211;
    }
    auto node205 = GET_SKILL_NODE(205, PhaseNode_CreateTriggerNewPene);
    if (node205 != nullptr) node211->setInput(node205->getOther());
    return node211;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(20041, 212) {
}

REGISTER_CREATE_SKILL_NODE(20041, 212) {
    auto node212 = GET_SKILL_NODE(212, PhaseNode_AddSkillBuffs);
    if (node212 == nullptr) {
        node212 = new PhaseNode_AddSkillBuffs(212, phase);
        node212->setConfigID({13});
        CALL_REGISTER_SKILL_NODE(20041, 212, node212)
    }
    if (noInit == true) {
        return node212;
    }
    auto node209 = GET_SKILL_NODE(209, PhaseNode_ActorFilterNewPene);
    auto node198 = GET_SKILL_NODE(198, PhaseNode_GetActorAttribute);
    if (node209 != nullptr) node212->setTarget(node209->getOutput());
    if (node198 != nullptr) node212->setAttribute(node198->getAttribute());
    return node212;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(20041, 213) {
}

REGISTER_CREATE_SKILL_NODE(20041, 213) {
    auto node213 = GET_SKILL_NODE(213, PhaseNode_AddSkillBuffs);
    if (node213 == nullptr) {
        node213 = new PhaseNode_AddSkillBuffs(213, phase);
        node213->setConfigID({13});
        CALL_REGISTER_SKILL_NODE(20041, 213, node213)
    }
    if (noInit == true) {
        return node213;
    }
    auto node210 = GET_SKILL_NODE(210, PhaseNode_ActorFilterNewPene);
    auto node198 = GET_SKILL_NODE(198, PhaseNode_GetActorAttribute);
    if (node210 != nullptr) node213->setTarget(node210->getOutput());
    if (node198 != nullptr) node213->setAttribute(node198->getAttribute());
    return node213;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(20041, 214) {
}

REGISTER_CREATE_SKILL_NODE(20041, 214) {
    auto node214 = GET_SKILL_NODE(214, PhaseNode_AddSkillBuffs);
    if (node214 == nullptr) {
        node214 = new PhaseNode_AddSkillBuffs(214, phase);
        node214->setConfigID({13});
        CALL_REGISTER_SKILL_NODE(20041, 214, node214)
    }
    if (noInit == true) {
        return node214;
    }
    auto node211 = GET_SKILL_NODE(211, PhaseNode_ActorFilterNewPene);
    auto node198 = GET_SKILL_NODE(198, PhaseNode_GetActorAttribute);
    if (node211 != nullptr) node214->setTarget(node211->getOutput());
    if (node198 != nullptr) node214->setAttribute(node198->getAttribute());
    return node214;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(20041, 215) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_ResetCD::TRIGGER_DONE, 216, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(20041, 215) {
    auto node215 = GET_SKILL_NODE(215, PhaseNode_ResetCD);
    if (node215 == nullptr) {
        node215 = new PhaseNode_ResetCD(215, phase);
        node215->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node215->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node215->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(20041, 215, node215)
    }
    if (noInit == true) {
        return node215;
    }
    return node215;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(20041, 216) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_PlayAnimation::TRIGGER_DONE, 217, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(20041, 216) {
    auto node216 = GET_SKILL_NODE(216, PhaseNode_PlayAnimation);
    if (node216 == nullptr) {
        node216 = new PhaseNode_PlayAnimation(216, phase);
        node216->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node216->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node216->setTarget(0U);
        node216->setAnimation("Skill1S1");
        node216->setParameter("");
        node216->setValue(false);
        CALL_REGISTER_SKILL_NODE(20041, 216, node216)
    }
    if (noInit == true) {
        return node216;
    }
    return node216;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(20041, 217) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlaySound::TRIGGER_DONE, 218, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(20041, 217) {
    auto node217 = GET_SKILL_NODE(217, PhaseNode_PlaySound);
    if (node217 == nullptr) {
        node217 = new PhaseNode_PlaySound(217, phase);
        node217->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node217->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node217->setSoundID("SE_MON2004_Skill_C_P0");
        node217->setTarget(0U);
        node217->setUsePos(false);
        node217->setPosX(.00f);
        node217->setPosY(.00f);
        node217->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(20041, 217, node217)
    }
    if (noInit == true) {
        return node217;
    }
    return node217;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(20041, 218) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_Delay::TRIGGER_DONE, 169, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(20041, 218) {
    auto node218 = GET_SKILL_NODE(218, PhaseNode_Delay);
    if (node218 == nullptr) {
        node218 = new PhaseNode_Delay(218, phase);
        node218->setTime(.50f);
        CALL_REGISTER_SKILL_NODE(20041, 218, node218)
    }
    if (noInit == true) {
        return node218;
    }
    return node218;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(20041, 219) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetRotation>(PhaseNode_GetLocation::TRIGGER_DONE, 220, PhaseNode_GetRotation::FUNC_DO, &PhaseNode_GetRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(20041, 219) {
    auto node219 = GET_SKILL_NODE(219, PhaseNode_GetLocation);
    if (node219 == nullptr) {
        node219 = new PhaseNode_GetLocation(219, phase);
        node219->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node219->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(20041, 219, node219)
    }
    if (noInit == true) {
        return node219;
    }
    return node219;
}
//--------------------------------------------------------------------------------
// GetRotation
//
REGISTER_REGISTER_SKILL_NODE(20041, 220) {
    pnode->resizeTrigger(PhaseNode_GetRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_OffsetCalculate>(PhaseNode_GetRotation::TRIGGER_DONE, 221, PhaseNode_OffsetCalculate::FUNC_DO, &PhaseNode_OffsetCalculate::Do);
}

REGISTER_CREATE_SKILL_NODE(20041, 220) {
    auto node220 = GET_SKILL_NODE(220, PhaseNode_GetRotation);
    if (node220 == nullptr) {
        node220 = new PhaseNode_GetRotation(220, phase);
        node220->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node220->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(20041, 220, node220)
    }
    if (noInit == true) {
        return node220;
    }
    return node220;
}
//--------------------------------------------------------------------------------
// OffsetCalculate
//
REGISTER_REGISTER_SKILL_NODE(20041, 221) {
    pnode->resizeTrigger(PhaseNode_OffsetCalculate::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 223, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 233, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(20041, 221) {
    auto node221 = GET_SKILL_NODE(221, PhaseNode_OffsetCalculate);
    if (node221 == nullptr) {
        node221 = new PhaseNode_OffsetCalculate(221, phase);
        node221->setPosZ(.00f);
        node221->setOffsetX(.00f);
        node221->setOffsetY(.00f);
        node221->setOffsetZ(.00f);
        node221->setRotOffset(.00f);
        CALL_REGISTER_SKILL_NODE(20041, 221, node221)
    }
    if (noInit == true) {
        return node221;
    }
    auto node219 = GET_SKILL_NODE(219, PhaseNode_GetLocation);
    auto node220 = GET_SKILL_NODE(220, PhaseNode_GetRotation);
    if (node219 != nullptr) node221->setPosX(node219->getX());
    if (node219 != nullptr) node221->setPosY(node219->getY());
    if (node220 != nullptr) node221->setRotation(node220->getAngle());
    return node221;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(20041, 222) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_PlayEffect::TRIGGER_DONE, 225, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(20041, 222) {
    auto node222 = GET_SKILL_NODE(222, PhaseNode_PlayEffect);
    if (node222 == nullptr) {
        node222 = new PhaseNode_PlayEffect(222, phase);
        node222->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node222->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node222->setEffectID(1047);
        node222->setChangeColor(false);
        node222->setType(PhaseNode_PlayEffect::PlayEffect_Type::WithTarget);
        node222->getVars().reserve(5);
        node222->getVars().setVariable<uint64_t>(0, 0U);
        node222->getVars().setVariable<std::string>(1, "");
        node222->getVars().setVariable<float>(2, .00f);
        node222->getVars().setVariable<float>(3, .00f);
        node222->getVars().setVariable<float>(4, .00f);
        node222->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(20041, 222, node222)
    }
    if (noInit == true) {
        return node222;
    }
    auto node221 = GET_SKILL_NODE(221, PhaseNode_OffsetCalculate);
    if (node221 != nullptr) node222->getVars().setVariable<float>(2, node221->getOutPosX());
    if (node221 != nullptr) node222->getVars().setVariable<float>(3, node221->getOutPosY());
    if (node221 != nullptr) node222->getVars().setVariable<float>(4, node221->getOutPosZ());
    if (node221 != nullptr) node222->setRotation(node221->getOutRotation());
    return node222;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(20041, 223) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_FALSE, 224, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_TRUE, 222, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(20041, 223) {
    auto node223 = GET_SKILL_NODE(223, PhaseNode_If);
    if (node223 == nullptr) {
        node223 = new PhaseNode_If(223, phase);
        node223->setCondition(false);
        CALL_REGISTER_SKILL_NODE(20041, 223, node223)
    }
    if (noInit == true) {
        return node223;
    }
    return node223;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(20041, 224) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_PlayEffect::TRIGGER_DONE, 225, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(20041, 224) {
    auto node224 = GET_SKILL_NODE(224, PhaseNode_PlayEffect);
    if (node224 == nullptr) {
        node224 = new PhaseNode_PlayEffect(224, phase);
        node224->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node224->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node224->setEffectID(1047);
        node224->setChangeColor(false);
        node224->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node224->getVars().reserve(3);
        node224->getVars().setVariable<float>(0, .00f);
        node224->getVars().setVariable<float>(1, .00f);
        node224->getVars().setVariable<float>(2, .00f);
        node224->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(20041, 224, node224)
    }
    if (noInit == true) {
        return node224;
    }
    auto node221 = GET_SKILL_NODE(221, PhaseNode_OffsetCalculate);
    if (node221 != nullptr) node224->getVars().setVariable<float>(0, node221->getOutPosX());
    if (node221 != nullptr) node224->getVars().setVariable<float>(1, node221->getOutPosY());
    if (node221 != nullptr) node224->getVars().setVariable<float>(2, node221->getOutPosZ());
    if (node221 != nullptr) node224->setRotation(node221->getOutRotation());
    return node224;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(20041, 225) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 52, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_LESS, 226, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_LESS, 52, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(20041, 225) {
    auto node225 = GET_SKILL_NODE(225, PhaseNode_CompareFloat);
    if (node225 == nullptr) {
        node225 = new PhaseNode_CompareFloat(225, phase);
        node225->setA(.00f);
        node225->setB(.00f);
        CALL_REGISTER_SKILL_NODE(20041, 225, node225)
    }
    if (noInit == true) {
        return node225;
    }
    return node225;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(20041, 226) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StopEffect>(PhaseNode_Delay::TRIGGER_DONE, 227, PhaseNode_StopEffect::FUNC_DO, &PhaseNode_StopEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(20041, 226) {
    auto node226 = GET_SKILL_NODE(226, PhaseNode_Delay);
    if (node226 == nullptr) {
        node226 = new PhaseNode_Delay(226, phase);
        node226->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(20041, 226, node226)
    }
    if (noInit == true) {
        return node226;
    }
    return node226;
}
//--------------------------------------------------------------------------------
// StopEffect
//
REGISTER_REGISTER_SKILL_NODE(20041, 227) {
}

REGISTER_CREATE_SKILL_NODE(20041, 227) {
    auto node227 = GET_SKILL_NODE(227, PhaseNode_StopEffect);
    if (node227 == nullptr) {
        node227 = new PhaseNode_StopEffect(227, phase);
        node227->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node227->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node227->setEffectID(1047);
        CALL_REGISTER_SKILL_NODE(20041, 227, node227)
    }
    if (noInit == true) {
        return node227;
    }
    return node227;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(20041, 228) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_Delay::TRIGGER_DONE, 230, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(20041, 228) {
    auto node228 = GET_SKILL_NODE(228, PhaseNode_Delay);
    if (node228 == nullptr) {
        node228 = new PhaseNode_Delay(228, phase);
        node228->setTime(.90f);
        CALL_REGISTER_SKILL_NODE(20041, 228, node228)
    }
    if (noInit == true) {
        return node228;
    }
    return node228;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(20041, 229) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 94, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(20041, 229) {
    auto node229 = GET_SKILL_NODE(229, PhaseNode_SkillEndNotify);
    if (node229 == nullptr) {
        node229 = new PhaseNode_SkillEndNotify(229, phase);
        node229->setReturnType(false);
        CALL_REGISTER_SKILL_NODE(20041, 229, node229)
    }
    if (noInit == true) {
        return node229;
    }
    return node229;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(20041, 230) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_FALSE, 231, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_TRUE, 229, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
}

REGISTER_CREATE_SKILL_NODE(20041, 230) {
    auto node230 = GET_SKILL_NODE(230, PhaseNode_If);
    if (node230 == nullptr) {
        node230 = new PhaseNode_If(230, phase);
        node230->setCondition(false);
        CALL_REGISTER_SKILL_NODE(20041, 230, node230)
    }
    if (noInit == true) {
        return node230;
    }
    return node230;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(20041, 231) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 94, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(20041, 231) {
    auto node231 = GET_SKILL_NODE(231, PhaseNode_SkillEndNotify);
    if (node231 == nullptr) {
        node231 = new PhaseNode_SkillEndNotify(231, phase);
        node231->setReturnType(true);
        CALL_REGISTER_SKILL_NODE(20041, 231, node231)
    }
    if (noInit == true) {
        return node231;
    }
    return node231;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(20041, 232) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_PlayEffect::TRIGGER_DONE, 235, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(20041, 232) {
    auto node232 = GET_SKILL_NODE(232, PhaseNode_PlayEffect);
    if (node232 == nullptr) {
        node232 = new PhaseNode_PlayEffect(232, phase);
        node232->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node232->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node232->setEffectID(1051);
        node232->setChangeColor(false);
        node232->setType(PhaseNode_PlayEffect::PlayEffect_Type::WithTarget);
        node232->getVars().reserve(5);
        node232->getVars().setVariable<uint64_t>(0, 0U);
        node232->getVars().setVariable<std::string>(1, "");
        node232->getVars().setVariable<float>(2, .00f);
        node232->getVars().setVariable<float>(3, .00f);
        node232->getVars().setVariable<float>(4, .00f);
        node232->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(20041, 232, node232)
    }
    if (noInit == true) {
        return node232;
    }
    auto node221 = GET_SKILL_NODE(221, PhaseNode_OffsetCalculate);
    if (node221 != nullptr) node232->getVars().setVariable<float>(2, node221->getOutPosX());
    if (node221 != nullptr) node232->getVars().setVariable<float>(3, node221->getOutPosY());
    if (node221 != nullptr) node232->getVars().setVariable<float>(4, node221->getOutPosZ());
    if (node221 != nullptr) node232->setRotation(node221->getOutRotation());
    return node232;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(20041, 233) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_FALSE, 234, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_TRUE, 232, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(20041, 233) {
    auto node233 = GET_SKILL_NODE(233, PhaseNode_If);
    if (node233 == nullptr) {
        node233 = new PhaseNode_If(233, phase);
        node233->setCondition(false);
        CALL_REGISTER_SKILL_NODE(20041, 233, node233)
    }
    if (noInit == true) {
        return node233;
    }
    return node233;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(20041, 234) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_PlayEffect::TRIGGER_DONE, 235, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(20041, 234) {
    auto node234 = GET_SKILL_NODE(234, PhaseNode_PlayEffect);
    if (node234 == nullptr) {
        node234 = new PhaseNode_PlayEffect(234, phase);
        node234->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node234->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node234->setEffectID(1051);
        node234->setChangeColor(false);
        node234->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node234->getVars().reserve(3);
        node234->getVars().setVariable<float>(0, .00f);
        node234->getVars().setVariable<float>(1, .00f);
        node234->getVars().setVariable<float>(2, .00f);
        node234->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(20041, 234, node234)
    }
    if (noInit == true) {
        return node234;
    }
    auto node221 = GET_SKILL_NODE(221, PhaseNode_OffsetCalculate);
    if (node221 != nullptr) node234->getVars().setVariable<float>(0, node221->getOutPosX());
    if (node221 != nullptr) node234->getVars().setVariable<float>(1, node221->getOutPosY());
    if (node221 != nullptr) node234->getVars().setVariable<float>(2, node221->getOutPosZ());
    if (node221 != nullptr) node234->setRotation(node221->getOutRotation());
    return node234;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(20041, 235) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_LESS, 236, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(20041, 235) {
    auto node235 = GET_SKILL_NODE(235, PhaseNode_CompareFloat);
    if (node235 == nullptr) {
        node235 = new PhaseNode_CompareFloat(235, phase);
        node235->setA(.00f);
        node235->setB(1.00f);
        CALL_REGISTER_SKILL_NODE(20041, 235, node235)
    }
    if (noInit == true) {
        return node235;
    }
    return node235;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(20041, 236) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StopEffect>(PhaseNode_Delay::TRIGGER_DONE, 237, PhaseNode_StopEffect::FUNC_DO, &PhaseNode_StopEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(20041, 236) {
    auto node236 = GET_SKILL_NODE(236, PhaseNode_Delay);
    if (node236 == nullptr) {
        node236 = new PhaseNode_Delay(236, phase);
        node236->setTime(1.00f);
        CALL_REGISTER_SKILL_NODE(20041, 236, node236)
    }
    if (noInit == true) {
        return node236;
    }
    return node236;
}
//--------------------------------------------------------------------------------
// StopEffect
//
REGISTER_REGISTER_SKILL_NODE(20041, 237) {
}

REGISTER_CREATE_SKILL_NODE(20041, 237) {
    auto node237 = GET_SKILL_NODE(237, PhaseNode_StopEffect);
    if (node237 == nullptr) {
        node237 = new PhaseNode_StopEffect(237, phase);
        node237->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node237->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node237->setEffectID(1051);
        CALL_REGISTER_SKILL_NODE(20041, 237, node237)
    }
    if (noInit == true) {
        return node237;
    }
    return node237;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(20041, 238) {
}

REGISTER_CREATE_SKILL_NODE(20041, 238) {
    auto node238 = GET_SKILL_NODE(238, PhaseNode_RaiseEvent);
    if (node238 == nullptr) {
        node238 = new PhaseNode_RaiseEvent(238, phase);
        node238->setEvent("MonsterInterrupt");
        node238->setTarget(0U);
        node238->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node238->setTypeParams(0, 0);
        node238->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(20041, 238, node238)
    }
    if (noInit == true) {
        return node238;
    }
    return node238;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(20041, 239) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_Detect::TRIGGER_ON, 242, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(20041, 239) {
    auto node239 = GET_SKILL_NODE(239, PhaseNode_Detect);
    if (node239 == nullptr) {
        node239 = new PhaseNode_Detect(239, phase);
        node239->setSelf(0U);
        node239->setEvent("MonsterInterrupt");
        node239->setType(PhaseNode_Detect::Detect_Type::Interrupt_Skill);
        node239->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(20041, 239, node239)
    }
    if (noInit == true) {
        return node239;
    }
    return node239;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(20041, 240) {
}

REGISTER_CREATE_SKILL_NODE(20041, 240) {
    auto node240 = GET_SKILL_NODE(240, PhaseNode_EndPhase);
    if (node240 == nullptr) {
        node240 = new PhaseNode_EndPhase(240, phase);
        node240->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node240->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(20041, 240, node240)
    }
    if (noInit == true) {
        return node240;
    }
    return node240;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(20041, 242) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_Delay::TRIGGER_DONE, 244, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(20041, 242) {
    auto node242 = GET_SKILL_NODE(242, PhaseNode_Delay);
    if (node242 == nullptr) {
        node242 = new PhaseNode_Delay(242, phase);
        node242->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(20041, 242, node242)
    }
    if (noInit == true) {
        return node242;
    }
    return node242;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(20041, 243) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 240, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(20041, 243) {
    auto node243 = GET_SKILL_NODE(243, PhaseNode_SkillEndNotify);
    if (node243 == nullptr) {
        node243 = new PhaseNode_SkillEndNotify(243, phase);
        node243->setReturnType(false);
        CALL_REGISTER_SKILL_NODE(20041, 243, node243)
    }
    if (noInit == true) {
        return node243;
    }
    return node243;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(20041, 244) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_FALSE, 245, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_TRUE, 243, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
}

REGISTER_CREATE_SKILL_NODE(20041, 244) {
    auto node244 = GET_SKILL_NODE(244, PhaseNode_If);
    if (node244 == nullptr) {
        node244 = new PhaseNode_If(244, phase);
        node244->setCondition(false);
        CALL_REGISTER_SKILL_NODE(20041, 244, node244)
    }
    if (noInit == true) {
        return node244;
    }
    return node244;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(20041, 245) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 240, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(20041, 245) {
    auto node245 = GET_SKILL_NODE(245, PhaseNode_SkillEndNotify);
    if (node245 == nullptr) {
        node245 = new PhaseNode_SkillEndNotify(245, phase);
        node245->setReturnType(true);
        CALL_REGISTER_SKILL_NODE(20041, 245, node245)
    }
    if (noInit == true) {
        return node245;
    }
    return node245;
}

//--------------------------------------------------------------------------------
// SkillCreator_20041
//
class SkillCreator_20041 : public SkillCreator {
public:
    SkillCreator_20041() {}
    virtual ~SkillCreator_20041() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_20041

//--------------------------------------------------------------------------------
// SkillPhase_20041
//
class SkillPhase_20041 : public SkillPhase {
public:
    SkillPhase_20041(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_20041() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(20041, 46) // StartPhase
        CASE_CREATE_SKILL_NODE(20041, 47) // TriggerUpdate
        CASE_CREATE_SKILL_NODE(20041, 52) // Delay
        CASE_CREATE_SKILL_NODE(20041, 53) // SpawnCollider
        CASE_CREATE_SKILL_NODE(20041, 94) // EndPhase
        CASE_CREATE_SKILL_NODE(20041, 142) // Detect
        CASE_CREATE_SKILL_NODE(20041, 143) // EndPhase
        CASE_CREATE_SKILL_NODE(20041, 153) // PlaySound
        CASE_CREATE_SKILL_NODE(20041, 169) // PlaySound
        CASE_CREATE_SKILL_NODE(20041, 195) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(20041, 196) // TriggerCheck
        CASE_CREATE_SKILL_NODE(20041, 197) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(20041, 198) // GetActorAttribute
        CASE_CREATE_SKILL_NODE(20041, 199) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(20041, 200) // CompareFloat
        CASE_CREATE_SKILL_NODE(20041, 201) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(20041, 202) // If
        CASE_CREATE_SKILL_NODE(20041, 203) // CompareFloat
        CASE_CREATE_SKILL_NODE(20041, 204) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(20041, 205) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(20041, 206) // TriggerCheck
        CASE_CREATE_SKILL_NODE(20041, 207) // TriggerCheck
        CASE_CREATE_SKILL_NODE(20041, 208) // TriggerCheck
        CASE_CREATE_SKILL_NODE(20041, 209) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(20041, 210) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(20041, 211) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(20041, 212) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(20041, 213) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(20041, 214) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(20041, 215) // ResetCD
        CASE_CREATE_SKILL_NODE(20041, 216) // PlayAnimation
        CASE_CREATE_SKILL_NODE(20041, 217) // PlaySound
        CASE_CREATE_SKILL_NODE(20041, 218) // Delay
        CASE_CREATE_SKILL_NODE(20041, 219) // GetLocation
        CASE_CREATE_SKILL_NODE(20041, 220) // GetRotation
        CASE_CREATE_SKILL_NODE(20041, 221) // OffsetCalculate
        CASE_CREATE_SKILL_NODE(20041, 222) // PlayEffect
        CASE_CREATE_SKILL_NODE(20041, 223) // If
        CASE_CREATE_SKILL_NODE(20041, 224) // PlayEffect
        CASE_CREATE_SKILL_NODE(20041, 225) // CompareFloat
        CASE_CREATE_SKILL_NODE(20041, 226) // Delay
        CASE_CREATE_SKILL_NODE(20041, 227) // StopEffect
        CASE_CREATE_SKILL_NODE(20041, 228) // Delay
        CASE_CREATE_SKILL_NODE(20041, 229) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(20041, 230) // If
        CASE_CREATE_SKILL_NODE(20041, 231) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(20041, 232) // PlayEffect
        CASE_CREATE_SKILL_NODE(20041, 233) // If
        CASE_CREATE_SKILL_NODE(20041, 234) // PlayEffect
        CASE_CREATE_SKILL_NODE(20041, 235) // CompareFloat
        CASE_CREATE_SKILL_NODE(20041, 236) // Delay
        CASE_CREATE_SKILL_NODE(20041, 237) // StopEffect
        CASE_CREATE_SKILL_NODE(20041, 238) // RaiseEvent
        CASE_CREATE_SKILL_NODE(20041, 239) // Detect
        CASE_CREATE_SKILL_NODE(20041, 240) // EndPhase
        CASE_CREATE_SKILL_NODE(20041, 242) // Delay
        CASE_CREATE_SKILL_NODE(20041, 243) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(20041, 244) // If
        CASE_CREATE_SKILL_NODE(20041, 245) // SkillEndNotify
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_20041

SkillLogic* SkillCreator_20041::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //创建阶段phase
    auto phase = new SkillPhase_20041(1, logic, 3);
    //设置phase执行器
    phase->setRunPhaseNode(1, 46);
    phase->setRunPhaseNode(2, 47);
    phase->setDetectPhaseNode(3, 142);
    phase->setDetectPhaseNode(3, 239);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_20041::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
