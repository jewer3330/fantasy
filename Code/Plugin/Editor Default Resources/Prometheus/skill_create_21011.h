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
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(21011, 14) {
}

REGISTER_CREATE_SKILL_NODE(21011, 14) {
    auto node14 = GET_SKILL_NODE(14, PhaseNode_EndPhase);
    if (node14 == nullptr) {
        node14 = new PhaseNode_EndPhase(14, phase);
        node14->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node14->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(21011, 14, node14)
    }
    if (noInit == true) {
        return node14;
    }
    return node14;
}
//--------------------------------------------------------------------------------
// TriggerUpdate
//
REGISTER_REGISTER_SKILL_NODE(21011, 23) {
}

REGISTER_CREATE_SKILL_NODE(21011, 23) {
    auto node23 = GET_SKILL_NODE(23, PhaseNode_TriggerUpdate);
    if (node23 == nullptr) {
        node23 = new PhaseNode_TriggerUpdate(23, phase);
        CALL_REGISTER_SKILL_NODE(21011, 23, node23)
    }
    if (noInit == true) {
        return node23;
    }
    return node23;
}
//--------------------------------------------------------------------------------
// StartPhase
//
REGISTER_REGISTER_SKILL_NODE(21011, 28) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_StartPhase::TRIGGER_START, 102, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_StartPhase::TRIGGER_START, 149, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_StartPhase::TRIGGER_START, 133, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(21011, 28) {
    auto node28 = GET_SKILL_NODE(28, PhaseNode_StartPhase);
    if (node28 == nullptr) {
        node28 = new PhaseNode_StartPhase(28, phase);
        CALL_REGISTER_SKILL_NODE(21011, 28, node28)
    }
    if (noInit == true) {
        return node28;
    }
    return node28;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(21011, 53) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_Detect::TRIGGER_ON, 55, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(21011, 53) {
    auto node53 = GET_SKILL_NODE(53, PhaseNode_Detect);
    if (node53 == nullptr) {
        node53 = new PhaseNode_Detect(53, phase);
        node53->setSelf(0U);
        node53->setEvent("");
        node53->setType(PhaseNode_Detect::Detect_Type::Actor_Dead);
        node53->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(21011, 53, node53)
    }
    if (noInit == true) {
        return node53;
    }
    return node53;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(21011, 55) {
}

REGISTER_CREATE_SKILL_NODE(21011, 55) {
    auto node55 = GET_SKILL_NODE(55, PhaseNode_EndPhase);
    if (node55 == nullptr) {
        node55 = new PhaseNode_EndPhase(55, phase);
        node55->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node55->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(21011, 55, node55)
    }
    if (noInit == true) {
        return node55;
    }
    return node55;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(21011, 92) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnCollider>(PhaseNode_PlaySound::TRIGGER_DONE, 93, PhaseNode_SpawnCollider::FUNC_DO, &PhaseNode_SpawnCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(21011, 92) {
    auto node92 = GET_SKILL_NODE(92, PhaseNode_PlaySound);
    if (node92 == nullptr) {
        node92 = new PhaseNode_PlaySound(92, phase);
        node92->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node92->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node92->setSoundID("SE_MON_Npc_Fighter_ATK");
        node92->setTarget(0U);
        node92->setUsePos(false);
        node92->setPosX(.00f);
        node92->setPosY(.00f);
        node92->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(21011, 92, node92)
    }
    if (noInit == true) {
        return node92;
    }
    return node92;
}
//--------------------------------------------------------------------------------
// SpawnCollider
//
REGISTER_REGISTER_SKILL_NODE(21011, 93) {
    pnode->resizeTrigger(PhaseNode_SpawnCollider::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_SpawnCollider::TRIGGER_DONE, 106, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_SpawnCollider::TRIGGER_DONE, 117, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(21011, 93) {
    auto node93 = GET_SKILL_NODE(93, PhaseNode_SpawnCollider);
    if (node93 == nullptr) {
        node93 = new PhaseNode_SpawnCollider(93, phase);
        node93->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node93->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node93->setMesh("");
        node93->setMeshScale(.00f);
        node93->setEffectID(0);
        node93->setEffectScale(.00f);
        node93->setType(PhaseNode_SpawnCollider::SpawnCollider_Type::Sector);
        node93->setTypeParams(0, 4.00f);
        node93->setTypeParams(1, 60.00f);
        node93->setTime(.30f);
        node93->setreentry(false);
        node93->setCheckPeneSound(false);
        CALL_REGISTER_SKILL_NODE(21011, 93, node93)
    }
    if (noInit == true) {
        return node93;
    }
    auto node132 = GET_SKILL_NODE(132, PhaseNode_OffsetCalculate);
    if (node132 != nullptr) node93->setPosX(node132->getOutPosX());
    if (node132 != nullptr) node93->setPosY(node132->getOutPosY());
    if (node132 != nullptr) node93->setPosZ(node132->getOutPosZ());
    if (node132 != nullptr) node93->setRotation(node132->getOutRotation());
    return node93;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(21011, 101) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_Delay::TRIGGER_DONE, 92, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(21011, 101) {
    auto node101 = GET_SKILL_NODE(101, PhaseNode_Delay);
    if (node101 == nullptr) {
        node101 = new PhaseNode_Delay(101, phase);
        node101->setTime(.30f);
        CALL_REGISTER_SKILL_NODE(21011, 101, node101)
    }
    if (noInit == true) {
        return node101;
    }
    return node101;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(21011, 102) {
}

REGISTER_CREATE_SKILL_NODE(21011, 102) {
    auto node102 = GET_SKILL_NODE(102, PhaseNode_RaiseEvent);
    if (node102 == nullptr) {
        node102 = new PhaseNode_RaiseEvent(102, phase);
        node102->setEvent("MonsterInterrupt");
        node102->setTarget(0U);
        node102->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node102->setTypeParams(0, 0);
        node102->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(21011, 102, node102)
    }
    if (noInit == true) {
        return node102;
    }
    return node102;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(21011, 103) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_Detect::TRIGGER_ON, 153, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(21011, 103) {
    auto node103 = GET_SKILL_NODE(103, PhaseNode_Detect);
    if (node103 == nullptr) {
        node103 = new PhaseNode_Detect(103, phase);
        node103->setSelf(0U);
        node103->setEvent("MonsterInterrupt");
        node103->setType(PhaseNode_Detect::Detect_Type::Interrupt_Skill);
        node103->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(21011, 103, node103)
    }
    if (noInit == true) {
        return node103;
    }
    return node103;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(21011, 104) {
}

REGISTER_CREATE_SKILL_NODE(21011, 104) {
    auto node104 = GET_SKILL_NODE(104, PhaseNode_EndPhase);
    if (node104 == nullptr) {
        node104 = new PhaseNode_EndPhase(104, phase);
        node104->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node104->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(21011, 104, node104)
    }
    if (noInit == true) {
        return node104;
    }
    return node104;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(21011, 106) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_Delay::TRIGGER_DONE, 108, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(21011, 106) {
    auto node106 = GET_SKILL_NODE(106, PhaseNode_Delay);
    if (node106 == nullptr) {
        node106 = new PhaseNode_Delay(106, phase);
        node106->setTime(.40f);
        CALL_REGISTER_SKILL_NODE(21011, 106, node106)
    }
    if (noInit == true) {
        return node106;
    }
    return node106;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(21011, 107) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 14, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(21011, 107) {
    auto node107 = GET_SKILL_NODE(107, PhaseNode_SkillEndNotify);
    if (node107 == nullptr) {
        node107 = new PhaseNode_SkillEndNotify(107, phase);
        node107->setReturnType(false);
        CALL_REGISTER_SKILL_NODE(21011, 107, node107)
    }
    if (noInit == true) {
        return node107;
    }
    return node107;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(21011, 108) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_FALSE, 109, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_TRUE, 107, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
}

REGISTER_CREATE_SKILL_NODE(21011, 108) {
    auto node108 = GET_SKILL_NODE(108, PhaseNode_If);
    if (node108 == nullptr) {
        node108 = new PhaseNode_If(108, phase);
        node108->setCondition(false);
        CALL_REGISTER_SKILL_NODE(21011, 108, node108)
    }
    if (noInit == true) {
        return node108;
    }
    return node108;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(21011, 109) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 14, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(21011, 109) {
    auto node109 = GET_SKILL_NODE(109, PhaseNode_SkillEndNotify);
    if (node109 == nullptr) {
        node109 = new PhaseNode_SkillEndNotify(109, phase);
        node109->setReturnType(true);
        CALL_REGISTER_SKILL_NODE(21011, 109, node109)
    }
    if (noInit == true) {
        return node109;
    }
    return node109;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(21011, 110) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 122, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 124, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(21011, 110) {
    auto node110 = GET_SKILL_NODE(110, PhaseNode_CreateTriggerNewPene);
    if (node110 == nullptr) {
        node110 = new PhaseNode_CreateTriggerNewPene(110, phase);
        node110->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::In);
        node110->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node110->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Enemy);
        node110->setOnHero(true);
        node110->setOnMinion(true);
        node110->setOnDestruct(true);
        node110->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(21011, 110, node110)
    }
    if (noInit == true) {
        return node110;
    }
    auto node93 = GET_SKILL_NODE(93, PhaseNode_SpawnCollider);
    if (node93 != nullptr) node110->setColliderID(node93->getColliderID());
    return node110;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(21011, 111) {
}

REGISTER_CREATE_SKILL_NODE(21011, 111) {
    auto node111 = GET_SKILL_NODE(111, PhaseNode_TriggerCheck);
    if (node111 == nullptr) {
        node111 = new PhaseNode_TriggerCheck(111, phase);
        auto node23 = GET_SKILL_NODE(23, PhaseNode_TriggerUpdate);
        if (node23 != nullptr) node23->addTriggerCheck(node111);
        
        CALL_REGISTER_SKILL_NODE(21011, 111, node111)
    }
    if (noInit == true) {
        return node111;
    }
    auto node120 = GET_SKILL_NODE(120, PhaseNode_CreateTriggerNewPene);
    if (node120 != nullptr) node111->setTrigger(0, node120->getTriggerID());
    return node111;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(21011, 112) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 113, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(21011, 112) {
    auto node112 = GET_SKILL_NODE(112, PhaseNode_ActorFilterNewPene);
    if (node112 == nullptr) {
        node112 = new PhaseNode_ActorFilterNewPene(112, phase);
        node112->setHero(true);
        node112->setMinion(true);
        node112->setDestruct(true);
        node112->setShield(false);
        node112->setTotalCount(0);
        node112->setPerCount(1);
        CALL_REGISTER_SKILL_NODE(21011, 112, node112)
    }
    if (noInit == true) {
        return node112;
    }
    auto node116 = GET_SKILL_NODE(116, PhaseNode_CreateTriggerNewPene);
    if (node116 != nullptr) node112->setInput(node116->getOther());
    return node112;
}
//--------------------------------------------------------------------------------
// GetActorAttribute
//
REGISTER_REGISTER_SKILL_NODE(21011, 113) {
    pnode->resizeTrigger(PhaseNode_GetActorAttribute::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 114, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 127, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 128, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 129, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
}

REGISTER_CREATE_SKILL_NODE(21011, 113) {
    auto node113 = GET_SKILL_NODE(113, PhaseNode_GetActorAttribute);
    if (node113 == nullptr) {
        node113 = new PhaseNode_GetActorAttribute(113, phase);
        node113->setTarget(0U);
        node113->setType({202});
        CALL_REGISTER_SKILL_NODE(21011, 113, node113)
    }
    if (noInit == true) {
        return node113;
    }
    return node113;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(21011, 114) {
}

REGISTER_CREATE_SKILL_NODE(21011, 114) {
    auto node114 = GET_SKILL_NODE(114, PhaseNode_AddSkillBuffs);
    if (node114 == nullptr) {
        node114 = new PhaseNode_AddSkillBuffs(114, phase);
        node114->setConfigID({11});
        CALL_REGISTER_SKILL_NODE(21011, 114, node114)
    }
    if (noInit == true) {
        return node114;
    }
    auto node112 = GET_SKILL_NODE(112, PhaseNode_ActorFilterNewPene);
    auto node113 = GET_SKILL_NODE(113, PhaseNode_GetActorAttribute);
    if (node112 != nullptr) node114->setTarget(node112->getOutput());
    if (node113 != nullptr) node114->setAttribute(node113->getAttribute());
    return node114;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(21011, 115) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 110, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_LESS, 116, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
}

REGISTER_CREATE_SKILL_NODE(21011, 115) {
    auto node115 = GET_SKILL_NODE(115, PhaseNode_CompareFloat);
    if (node115 == nullptr) {
        node115 = new PhaseNode_CompareFloat(115, phase);
        node115->setA(.00f);
        node115->setB(.00f);
        CALL_REGISTER_SKILL_NODE(21011, 115, node115)
    }
    if (noInit == true) {
        return node115;
    }
    return node115;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(21011, 116) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 121, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 112, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(21011, 116) {
    auto node116 = GET_SKILL_NODE(116, PhaseNode_CreateTriggerNewPene);
    if (node116 == nullptr) {
        node116 = new PhaseNode_CreateTriggerNewPene(116, phase);
        node116->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::Tick);
        node116->setTypeParams(0, .00f);
        node116->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node116->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Enemy);
        node116->setOnHero(true);
        node116->setOnMinion(true);
        node116->setOnDestruct(true);
        node116->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(21011, 116, node116)
    }
    if (noInit == true) {
        return node116;
    }
    auto node93 = GET_SKILL_NODE(93, PhaseNode_SpawnCollider);
    if (node93 != nullptr) node116->setColliderID(node93->getColliderID());
    return node116;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(21011, 117) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_If::TRIGGER_FALSE, 118, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_If::TRIGGER_TRUE, 115, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(21011, 117) {
    auto node117 = GET_SKILL_NODE(117, PhaseNode_If);
    if (node117 == nullptr) {
        node117 = new PhaseNode_If(117, phase);
        node117->setCondition(true);
        CALL_REGISTER_SKILL_NODE(21011, 117, node117)
    }
    if (noInit == true) {
        return node117;
    }
    return node117;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(21011, 118) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 120, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_LESS, 119, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
}

REGISTER_CREATE_SKILL_NODE(21011, 118) {
    auto node118 = GET_SKILL_NODE(118, PhaseNode_CompareFloat);
    if (node118 == nullptr) {
        node118 = new PhaseNode_CompareFloat(118, phase);
        node118->setA(.00f);
        node118->setB(.00f);
        CALL_REGISTER_SKILL_NODE(21011, 118, node118)
    }
    if (noInit == true) {
        return node118;
    }
    return node118;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(21011, 119) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 123, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 125, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(21011, 119) {
    auto node119 = GET_SKILL_NODE(119, PhaseNode_CreateTriggerNewPene);
    if (node119 == nullptr) {
        node119 = new PhaseNode_CreateTriggerNewPene(119, phase);
        node119->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::Tick);
        node119->setTypeParams(0, .00f);
        node119->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node119->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Friend);
        node119->setOnHero(true);
        node119->setOnMinion(true);
        node119->setOnDestruct(true);
        node119->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(21011, 119, node119)
    }
    if (noInit == true) {
        return node119;
    }
    auto node93 = GET_SKILL_NODE(93, PhaseNode_SpawnCollider);
    if (node93 != nullptr) node119->setColliderID(node93->getColliderID());
    return node119;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(21011, 120) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 111, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 126, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(21011, 120) {
    auto node120 = GET_SKILL_NODE(120, PhaseNode_CreateTriggerNewPene);
    if (node120 == nullptr) {
        node120 = new PhaseNode_CreateTriggerNewPene(120, phase);
        node120->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::In);
        node120->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node120->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Friend);
        node120->setOnHero(true);
        node120->setOnMinion(true);
        node120->setOnDestruct(true);
        node120->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(21011, 120, node120)
    }
    if (noInit == true) {
        return node120;
    }
    auto node93 = GET_SKILL_NODE(93, PhaseNode_SpawnCollider);
    if (node93 != nullptr) node120->setColliderID(node93->getColliderID());
    return node120;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(21011, 121) {
}

REGISTER_CREATE_SKILL_NODE(21011, 121) {
    auto node121 = GET_SKILL_NODE(121, PhaseNode_TriggerCheck);
    if (node121 == nullptr) {
        node121 = new PhaseNode_TriggerCheck(121, phase);
        auto node23 = GET_SKILL_NODE(23, PhaseNode_TriggerUpdate);
        if (node23 != nullptr) node23->addTriggerCheck(node121);
        
        CALL_REGISTER_SKILL_NODE(21011, 121, node121)
    }
    if (noInit == true) {
        return node121;
    }
    auto node116 = GET_SKILL_NODE(116, PhaseNode_CreateTriggerNewPene);
    if (node116 != nullptr) node121->setTrigger(0, node116->getTriggerID());
    return node121;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(21011, 122) {
}

REGISTER_CREATE_SKILL_NODE(21011, 122) {
    auto node122 = GET_SKILL_NODE(122, PhaseNode_TriggerCheck);
    if (node122 == nullptr) {
        node122 = new PhaseNode_TriggerCheck(122, phase);
        auto node23 = GET_SKILL_NODE(23, PhaseNode_TriggerUpdate);
        if (node23 != nullptr) node23->addTriggerCheck(node122);
        
        CALL_REGISTER_SKILL_NODE(21011, 122, node122)
    }
    if (noInit == true) {
        return node122;
    }
    auto node110 = GET_SKILL_NODE(110, PhaseNode_CreateTriggerNewPene);
    if (node110 != nullptr) node122->setTrigger(0, node110->getTriggerID());
    return node122;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(21011, 123) {
}

REGISTER_CREATE_SKILL_NODE(21011, 123) {
    auto node123 = GET_SKILL_NODE(123, PhaseNode_TriggerCheck);
    if (node123 == nullptr) {
        node123 = new PhaseNode_TriggerCheck(123, phase);
        auto node23 = GET_SKILL_NODE(23, PhaseNode_TriggerUpdate);
        if (node23 != nullptr) node23->addTriggerCheck(node123);
        
        CALL_REGISTER_SKILL_NODE(21011, 123, node123)
    }
    if (noInit == true) {
        return node123;
    }
    auto node119 = GET_SKILL_NODE(119, PhaseNode_CreateTriggerNewPene);
    if (node119 != nullptr) node123->setTrigger(0, node119->getTriggerID());
    return node123;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(21011, 124) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 113, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(21011, 124) {
    auto node124 = GET_SKILL_NODE(124, PhaseNode_ActorFilterNewPene);
    if (node124 == nullptr) {
        node124 = new PhaseNode_ActorFilterNewPene(124, phase);
        node124->setHero(true);
        node124->setMinion(true);
        node124->setDestruct(true);
        node124->setShield(false);
        node124->setTotalCount(0);
        node124->setPerCount(1);
        CALL_REGISTER_SKILL_NODE(21011, 124, node124)
    }
    if (noInit == true) {
        return node124;
    }
    auto node110 = GET_SKILL_NODE(110, PhaseNode_CreateTriggerNewPene);
    if (node110 != nullptr) node124->setInput(node110->getOther());
    return node124;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(21011, 125) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 113, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(21011, 125) {
    auto node125 = GET_SKILL_NODE(125, PhaseNode_ActorFilterNewPene);
    if (node125 == nullptr) {
        node125 = new PhaseNode_ActorFilterNewPene(125, phase);
        node125->setHero(true);
        node125->setMinion(true);
        node125->setDestruct(true);
        node125->setShield(false);
        node125->setTotalCount(0);
        node125->setPerCount(1);
        CALL_REGISTER_SKILL_NODE(21011, 125, node125)
    }
    if (noInit == true) {
        return node125;
    }
    auto node119 = GET_SKILL_NODE(119, PhaseNode_CreateTriggerNewPene);
    if (node119 != nullptr) node125->setInput(node119->getOther());
    return node125;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(21011, 126) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 113, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(21011, 126) {
    auto node126 = GET_SKILL_NODE(126, PhaseNode_ActorFilterNewPene);
    if (node126 == nullptr) {
        node126 = new PhaseNode_ActorFilterNewPene(126, phase);
        node126->setHero(true);
        node126->setMinion(true);
        node126->setDestruct(true);
        node126->setShield(false);
        node126->setTotalCount(0);
        node126->setPerCount(1);
        CALL_REGISTER_SKILL_NODE(21011, 126, node126)
    }
    if (noInit == true) {
        return node126;
    }
    auto node120 = GET_SKILL_NODE(120, PhaseNode_CreateTriggerNewPene);
    if (node120 != nullptr) node126->setInput(node120->getOther());
    return node126;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(21011, 127) {
}

REGISTER_CREATE_SKILL_NODE(21011, 127) {
    auto node127 = GET_SKILL_NODE(127, PhaseNode_AddSkillBuffs);
    if (node127 == nullptr) {
        node127 = new PhaseNode_AddSkillBuffs(127, phase);
        node127->setConfigID({11});
        CALL_REGISTER_SKILL_NODE(21011, 127, node127)
    }
    if (noInit == true) {
        return node127;
    }
    auto node124 = GET_SKILL_NODE(124, PhaseNode_ActorFilterNewPene);
    auto node113 = GET_SKILL_NODE(113, PhaseNode_GetActorAttribute);
    if (node124 != nullptr) node127->setTarget(node124->getOutput());
    if (node113 != nullptr) node127->setAttribute(node113->getAttribute());
    return node127;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(21011, 128) {
}

REGISTER_CREATE_SKILL_NODE(21011, 128) {
    auto node128 = GET_SKILL_NODE(128, PhaseNode_AddSkillBuffs);
    if (node128 == nullptr) {
        node128 = new PhaseNode_AddSkillBuffs(128, phase);
        node128->setConfigID({11});
        CALL_REGISTER_SKILL_NODE(21011, 128, node128)
    }
    if (noInit == true) {
        return node128;
    }
    auto node125 = GET_SKILL_NODE(125, PhaseNode_ActorFilterNewPene);
    auto node113 = GET_SKILL_NODE(113, PhaseNode_GetActorAttribute);
    if (node125 != nullptr) node128->setTarget(node125->getOutput());
    if (node113 != nullptr) node128->setAttribute(node113->getAttribute());
    return node128;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(21011, 129) {
}

REGISTER_CREATE_SKILL_NODE(21011, 129) {
    auto node129 = GET_SKILL_NODE(129, PhaseNode_AddSkillBuffs);
    if (node129 == nullptr) {
        node129 = new PhaseNode_AddSkillBuffs(129, phase);
        node129->setConfigID({11});
        CALL_REGISTER_SKILL_NODE(21011, 129, node129)
    }
    if (noInit == true) {
        return node129;
    }
    auto node126 = GET_SKILL_NODE(126, PhaseNode_ActorFilterNewPene);
    auto node113 = GET_SKILL_NODE(113, PhaseNode_GetActorAttribute);
    if (node126 != nullptr) node129->setTarget(node126->getOutput());
    if (node113 != nullptr) node129->setAttribute(node113->getAttribute());
    return node129;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(21011, 130) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetRotation>(PhaseNode_GetLocation::TRIGGER_DONE, 131, PhaseNode_GetRotation::FUNC_DO, &PhaseNode_GetRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(21011, 130) {
    auto node130 = GET_SKILL_NODE(130, PhaseNode_GetLocation);
    if (node130 == nullptr) {
        node130 = new PhaseNode_GetLocation(130, phase);
        node130->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node130->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(21011, 130, node130)
    }
    if (noInit == true) {
        return node130;
    }
    return node130;
}
//--------------------------------------------------------------------------------
// GetRotation
//
REGISTER_REGISTER_SKILL_NODE(21011, 131) {
    pnode->resizeTrigger(PhaseNode_GetRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_OffsetCalculate>(PhaseNode_GetRotation::TRIGGER_DONE, 132, PhaseNode_OffsetCalculate::FUNC_DO, &PhaseNode_OffsetCalculate::Do);
}

REGISTER_CREATE_SKILL_NODE(21011, 131) {
    auto node131 = GET_SKILL_NODE(131, PhaseNode_GetRotation);
    if (node131 == nullptr) {
        node131 = new PhaseNode_GetRotation(131, phase);
        node131->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node131->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(21011, 131, node131)
    }
    if (noInit == true) {
        return node131;
    }
    return node131;
}
//--------------------------------------------------------------------------------
// OffsetCalculate
//
REGISTER_REGISTER_SKILL_NODE(21011, 132) {
    pnode->resizeTrigger(PhaseNode_OffsetCalculate::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 138, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(21011, 132) {
    auto node132 = GET_SKILL_NODE(132, PhaseNode_OffsetCalculate);
    if (node132 == nullptr) {
        node132 = new PhaseNode_OffsetCalculate(132, phase);
        node132->setPosZ(.00f);
        node132->setOffsetX(.00f);
        node132->setOffsetY(.00f);
        node132->setOffsetZ(.00f);
        node132->setRotOffset(.00f);
        CALL_REGISTER_SKILL_NODE(21011, 132, node132)
    }
    if (noInit == true) {
        return node132;
    }
    auto node130 = GET_SKILL_NODE(130, PhaseNode_GetLocation);
    auto node131 = GET_SKILL_NODE(131, PhaseNode_GetRotation);
    if (node130 != nullptr) node132->setPosX(node130->getX());
    if (node130 != nullptr) node132->setPosY(node130->getY());
    if (node131 != nullptr) node132->setRotation(node131->getAngle());
    return node132;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(21011, 133) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_ResetCD::TRIGGER_DONE, 134, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(21011, 133) {
    auto node133 = GET_SKILL_NODE(133, PhaseNode_ResetCD);
    if (node133 == nullptr) {
        node133 = new PhaseNode_ResetCD(133, phase);
        node133->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node133->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node133->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(21011, 133, node133)
    }
    if (noInit == true) {
        return node133;
    }
    return node133;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(21011, 134) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_PlayAnimation::TRIGGER_DONE, 135, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(21011, 134) {
    auto node134 = GET_SKILL_NODE(134, PhaseNode_PlayAnimation);
    if (node134 == nullptr) {
        node134 = new PhaseNode_PlayAnimation(134, phase);
        node134->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node134->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node134->setTarget(0U);
        node134->setAnimation("Skill1S1");
        node134->setParameter("");
        node134->setValue(false);
        CALL_REGISTER_SKILL_NODE(21011, 134, node134)
    }
    if (noInit == true) {
        return node134;
    }
    return node134;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(21011, 135) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlaySound::TRIGGER_DONE, 136, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(21011, 135) {
    auto node135 = GET_SKILL_NODE(135, PhaseNode_PlaySound);
    if (node135 == nullptr) {
        node135 = new PhaseNode_PlaySound(135, phase);
        node135->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node135->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node135->setSoundID("");
        node135->setTarget(0U);
        node135->setUsePos(false);
        node135->setPosX(.00f);
        node135->setPosY(.00f);
        node135->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(21011, 135, node135)
    }
    if (noInit == true) {
        return node135;
    }
    return node135;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(21011, 136) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_Delay::TRIGGER_DONE, 130, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(21011, 136) {
    auto node136 = GET_SKILL_NODE(136, PhaseNode_Delay);
    if (node136 == nullptr) {
        node136 = new PhaseNode_Delay(136, phase);
        node136->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(21011, 136, node136)
    }
    if (noInit == true) {
        return node136;
    }
    return node136;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(21011, 137) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_PlayEffect::TRIGGER_DONE, 140, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(21011, 137) {
    auto node137 = GET_SKILL_NODE(137, PhaseNode_PlayEffect);
    if (node137 == nullptr) {
        node137 = new PhaseNode_PlayEffect(137, phase);
        node137->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node137->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node137->setEffectID(1035);
        node137->setChangeColor(false);
        node137->setType(PhaseNode_PlayEffect::PlayEffect_Type::WithTarget);
        node137->getVars().reserve(5);
        node137->getVars().setVariable<uint64_t>(0, 0U);
        node137->getVars().setVariable<std::string>(1, "");
        node137->getVars().setVariable<float>(2, .00f);
        node137->getVars().setVariable<float>(3, .00f);
        node137->getVars().setVariable<float>(4, .00f);
        node137->setScale(.00f);
        CALL_REGISTER_SKILL_NODE(21011, 137, node137)
    }
    if (noInit == true) {
        return node137;
    }
    auto node132 = GET_SKILL_NODE(132, PhaseNode_OffsetCalculate);
    if (node132 != nullptr) node137->getVars().setVariable<float>(2, node132->getOutPosX());
    if (node132 != nullptr) node137->getVars().setVariable<float>(3, node132->getOutPosY());
    if (node132 != nullptr) node137->getVars().setVariable<float>(4, node132->getOutPosZ());
    if (node132 != nullptr) node137->setRotation(node132->getOutRotation());
    return node137;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(21011, 138) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_FALSE, 139, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_TRUE, 137, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(21011, 138) {
    auto node138 = GET_SKILL_NODE(138, PhaseNode_If);
    if (node138 == nullptr) {
        node138 = new PhaseNode_If(138, phase);
        node138->setCondition(false);
        CALL_REGISTER_SKILL_NODE(21011, 138, node138)
    }
    if (noInit == true) {
        return node138;
    }
    return node138;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(21011, 139) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_PlayEffect::TRIGGER_DONE, 140, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(21011, 139) {
    auto node139 = GET_SKILL_NODE(139, PhaseNode_PlayEffect);
    if (node139 == nullptr) {
        node139 = new PhaseNode_PlayEffect(139, phase);
        node139->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node139->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node139->setEffectID(1035);
        node139->setChangeColor(false);
        node139->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node139->getVars().reserve(3);
        node139->getVars().setVariable<float>(0, .00f);
        node139->getVars().setVariable<float>(1, .00f);
        node139->getVars().setVariable<float>(2, .00f);
        node139->setScale(.00f);
        CALL_REGISTER_SKILL_NODE(21011, 139, node139)
    }
    if (noInit == true) {
        return node139;
    }
    auto node132 = GET_SKILL_NODE(132, PhaseNode_OffsetCalculate);
    if (node132 != nullptr) node139->getVars().setVariable<float>(0, node132->getOutPosX());
    if (node132 != nullptr) node139->getVars().setVariable<float>(1, node132->getOutPosY());
    if (node132 != nullptr) node139->getVars().setVariable<float>(2, node132->getOutPosZ());
    if (node132 != nullptr) node139->setRotation(node132->getOutRotation());
    return node139;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(21011, 140) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 144, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_LESS, 141, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_CompareFloat::TRIGGER_LESS, 144, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(21011, 140) {
    auto node140 = GET_SKILL_NODE(140, PhaseNode_CompareFloat);
    if (node140 == nullptr) {
        node140 = new PhaseNode_CompareFloat(140, phase);
        node140->setA(.00f);
        node140->setB(.00f);
        CALL_REGISTER_SKILL_NODE(21011, 140, node140)
    }
    if (noInit == true) {
        return node140;
    }
    return node140;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(21011, 141) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StopEffect>(PhaseNode_Delay::TRIGGER_DONE, 142, PhaseNode_StopEffect::FUNC_DO, &PhaseNode_StopEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(21011, 141) {
    auto node141 = GET_SKILL_NODE(141, PhaseNode_Delay);
    if (node141 == nullptr) {
        node141 = new PhaseNode_Delay(141, phase);
        node141->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(21011, 141, node141)
    }
    if (noInit == true) {
        return node141;
    }
    return node141;
}
//--------------------------------------------------------------------------------
// StopEffect
//
REGISTER_REGISTER_SKILL_NODE(21011, 142) {
}

REGISTER_CREATE_SKILL_NODE(21011, 142) {
    auto node142 = GET_SKILL_NODE(142, PhaseNode_StopEffect);
    if (node142 == nullptr) {
        node142 = new PhaseNode_StopEffect(142, phase);
        node142->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node142->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node142->setEffectID(1035);
        CALL_REGISTER_SKILL_NODE(21011, 142, node142)
    }
    if (noInit == true) {
        return node142;
    }
    return node142;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(21011, 143) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_PlayEffect::TRIGGER_DONE, 146, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(21011, 143) {
    auto node143 = GET_SKILL_NODE(143, PhaseNode_PlayEffect);
    if (node143 == nullptr) {
        node143 = new PhaseNode_PlayEffect(143, phase);
        node143->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node143->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node143->setEffectID(0);
        node143->setChangeColor(false);
        node143->setType(PhaseNode_PlayEffect::PlayEffect_Type::WithTarget);
        node143->getVars().reserve(5);
        node143->getVars().setVariable<uint64_t>(0, 0U);
        node143->getVars().setVariable<std::string>(1, "");
        node143->getVars().setVariable<float>(2, .00f);
        node143->getVars().setVariable<float>(3, .00f);
        node143->getVars().setVariable<float>(4, .00f);
        node143->setScale(.00f);
        CALL_REGISTER_SKILL_NODE(21011, 143, node143)
    }
    if (noInit == true) {
        return node143;
    }
    auto node132 = GET_SKILL_NODE(132, PhaseNode_OffsetCalculate);
    if (node132 != nullptr) node143->getVars().setVariable<float>(2, node132->getOutPosX());
    if (node132 != nullptr) node143->getVars().setVariable<float>(3, node132->getOutPosY());
    if (node132 != nullptr) node143->getVars().setVariable<float>(4, node132->getOutPosZ());
    if (node132 != nullptr) node143->setRotation(node132->getOutRotation());
    return node143;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(21011, 144) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_FALSE, 145, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_TRUE, 143, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(21011, 144) {
    auto node144 = GET_SKILL_NODE(144, PhaseNode_If);
    if (node144 == nullptr) {
        node144 = new PhaseNode_If(144, phase);
        node144->setCondition(false);
        CALL_REGISTER_SKILL_NODE(21011, 144, node144)
    }
    if (noInit == true) {
        return node144;
    }
    return node144;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(21011, 145) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_PlayEffect::TRIGGER_DONE, 146, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(21011, 145) {
    auto node145 = GET_SKILL_NODE(145, PhaseNode_PlayEffect);
    if (node145 == nullptr) {
        node145 = new PhaseNode_PlayEffect(145, phase);
        node145->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node145->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node145->setEffectID(0);
        node145->setChangeColor(false);
        node145->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node145->getVars().reserve(3);
        node145->getVars().setVariable<float>(0, .00f);
        node145->getVars().setVariable<float>(1, .00f);
        node145->getVars().setVariable<float>(2, .00f);
        node145->setScale(.00f);
        CALL_REGISTER_SKILL_NODE(21011, 145, node145)
    }
    if (noInit == true) {
        return node145;
    }
    auto node132 = GET_SKILL_NODE(132, PhaseNode_OffsetCalculate);
    if (node132 != nullptr) node145->getVars().setVariable<float>(0, node132->getOutPosX());
    if (node132 != nullptr) node145->getVars().setVariable<float>(1, node132->getOutPosY());
    if (node132 != nullptr) node145->getVars().setVariable<float>(2, node132->getOutPosZ());
    if (node132 != nullptr) node145->setRotation(node132->getOutRotation());
    return node145;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(21011, 146) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 101, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_LESS, 101, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_LESS, 147, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(21011, 146) {
    auto node146 = GET_SKILL_NODE(146, PhaseNode_CompareFloat);
    if (node146 == nullptr) {
        node146 = new PhaseNode_CompareFloat(146, phase);
        node146->setA(.00f);
        node146->setB(.00f);
        CALL_REGISTER_SKILL_NODE(21011, 146, node146)
    }
    if (noInit == true) {
        return node146;
    }
    return node146;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(21011, 147) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StopEffect>(PhaseNode_Delay::TRIGGER_DONE, 148, PhaseNode_StopEffect::FUNC_DO, &PhaseNode_StopEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(21011, 147) {
    auto node147 = GET_SKILL_NODE(147, PhaseNode_Delay);
    if (node147 == nullptr) {
        node147 = new PhaseNode_Delay(147, phase);
        node147->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(21011, 147, node147)
    }
    if (noInit == true) {
        return node147;
    }
    return node147;
}
//--------------------------------------------------------------------------------
// StopEffect
//
REGISTER_REGISTER_SKILL_NODE(21011, 148) {
}

REGISTER_CREATE_SKILL_NODE(21011, 148) {
    auto node148 = GET_SKILL_NODE(148, PhaseNode_StopEffect);
    if (node148 == nullptr) {
        node148 = new PhaseNode_StopEffect(148, phase);
        node148->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node148->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node148->setEffectID(0);
        CALL_REGISTER_SKILL_NODE(21011, 148, node148)
    }
    if (noInit == true) {
        return node148;
    }
    return node148;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(21011, 149) {
}

REGISTER_CREATE_SKILL_NODE(21011, 149) {
    auto node149 = GET_SKILL_NODE(149, PhaseNode_RaiseEvent);
    if (node149 == nullptr) {
        node149 = new PhaseNode_RaiseEvent(149, phase);
        node149->setEvent("MonsterInterrupt");
        node149->setTarget(0U);
        node149->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node149->setTypeParams(0, 0);
        node149->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(21011, 149, node149)
    }
    if (noInit == true) {
        return node149;
    }
    return node149;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(21011, 150) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_Detect::TRIGGER_ON, 157, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(21011, 150) {
    auto node150 = GET_SKILL_NODE(150, PhaseNode_Detect);
    if (node150 == nullptr) {
        node150 = new PhaseNode_Detect(150, phase);
        node150->setSelf(0U);
        node150->setEvent("MonsterInterrupt");
        node150->setType(PhaseNode_Detect::Detect_Type::Interrupt_Skill);
        node150->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(21011, 150, node150)
    }
    if (noInit == true) {
        return node150;
    }
    return node150;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(21011, 151) {
}

REGISTER_CREATE_SKILL_NODE(21011, 151) {
    auto node151 = GET_SKILL_NODE(151, PhaseNode_EndPhase);
    if (node151 == nullptr) {
        node151 = new PhaseNode_EndPhase(151, phase);
        node151->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node151->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(21011, 151, node151)
    }
    if (noInit == true) {
        return node151;
    }
    return node151;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(21011, 153) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_Delay::TRIGGER_DONE, 155, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(21011, 153) {
    auto node153 = GET_SKILL_NODE(153, PhaseNode_Delay);
    if (node153 == nullptr) {
        node153 = new PhaseNode_Delay(153, phase);
        node153->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(21011, 153, node153)
    }
    if (noInit == true) {
        return node153;
    }
    return node153;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(21011, 154) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 104, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(21011, 154) {
    auto node154 = GET_SKILL_NODE(154, PhaseNode_SkillEndNotify);
    if (node154 == nullptr) {
        node154 = new PhaseNode_SkillEndNotify(154, phase);
        node154->setReturnType(false);
        CALL_REGISTER_SKILL_NODE(21011, 154, node154)
    }
    if (noInit == true) {
        return node154;
    }
    return node154;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(21011, 155) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_FALSE, 156, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_TRUE, 154, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
}

REGISTER_CREATE_SKILL_NODE(21011, 155) {
    auto node155 = GET_SKILL_NODE(155, PhaseNode_If);
    if (node155 == nullptr) {
        node155 = new PhaseNode_If(155, phase);
        node155->setCondition(false);
        CALL_REGISTER_SKILL_NODE(21011, 155, node155)
    }
    if (noInit == true) {
        return node155;
    }
    return node155;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(21011, 156) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 104, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(21011, 156) {
    auto node156 = GET_SKILL_NODE(156, PhaseNode_SkillEndNotify);
    if (node156 == nullptr) {
        node156 = new PhaseNode_SkillEndNotify(156, phase);
        node156->setReturnType(true);
        CALL_REGISTER_SKILL_NODE(21011, 156, node156)
    }
    if (noInit == true) {
        return node156;
    }
    return node156;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(21011, 157) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_Delay::TRIGGER_DONE, 159, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(21011, 157) {
    auto node157 = GET_SKILL_NODE(157, PhaseNode_Delay);
    if (node157 == nullptr) {
        node157 = new PhaseNode_Delay(157, phase);
        node157->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(21011, 157, node157)
    }
    if (noInit == true) {
        return node157;
    }
    return node157;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(21011, 158) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 151, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(21011, 158) {
    auto node158 = GET_SKILL_NODE(158, PhaseNode_SkillEndNotify);
    if (node158 == nullptr) {
        node158 = new PhaseNode_SkillEndNotify(158, phase);
        node158->setReturnType(false);
        CALL_REGISTER_SKILL_NODE(21011, 158, node158)
    }
    if (noInit == true) {
        return node158;
    }
    return node158;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(21011, 159) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_FALSE, 160, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_TRUE, 158, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
}

REGISTER_CREATE_SKILL_NODE(21011, 159) {
    auto node159 = GET_SKILL_NODE(159, PhaseNode_If);
    if (node159 == nullptr) {
        node159 = new PhaseNode_If(159, phase);
        node159->setCondition(false);
        CALL_REGISTER_SKILL_NODE(21011, 159, node159)
    }
    if (noInit == true) {
        return node159;
    }
    return node159;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(21011, 160) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 151, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(21011, 160) {
    auto node160 = GET_SKILL_NODE(160, PhaseNode_SkillEndNotify);
    if (node160 == nullptr) {
        node160 = new PhaseNode_SkillEndNotify(160, phase);
        node160->setReturnType(true);
        CALL_REGISTER_SKILL_NODE(21011, 160, node160)
    }
    if (noInit == true) {
        return node160;
    }
    return node160;
}

//--------------------------------------------------------------------------------
// SkillCreator_21011
//
class SkillCreator_21011 : public SkillCreator {
public:
    SkillCreator_21011() {}
    virtual ~SkillCreator_21011() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_21011

//--------------------------------------------------------------------------------
// SkillPhase_21011
//
class SkillPhase_21011 : public SkillPhase {
public:
    SkillPhase_21011(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_21011() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(21011, 14) // EndPhase
        CASE_CREATE_SKILL_NODE(21011, 23) // TriggerUpdate
        CASE_CREATE_SKILL_NODE(21011, 28) // StartPhase
        CASE_CREATE_SKILL_NODE(21011, 53) // Detect
        CASE_CREATE_SKILL_NODE(21011, 55) // EndPhase
        CASE_CREATE_SKILL_NODE(21011, 92) // PlaySound
        CASE_CREATE_SKILL_NODE(21011, 93) // SpawnCollider
        CASE_CREATE_SKILL_NODE(21011, 101) // Delay
        CASE_CREATE_SKILL_NODE(21011, 102) // RaiseEvent
        CASE_CREATE_SKILL_NODE(21011, 103) // Detect
        CASE_CREATE_SKILL_NODE(21011, 104) // EndPhase
        CASE_CREATE_SKILL_NODE(21011, 106) // Delay
        CASE_CREATE_SKILL_NODE(21011, 107) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(21011, 108) // If
        CASE_CREATE_SKILL_NODE(21011, 109) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(21011, 110) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(21011, 111) // TriggerCheck
        CASE_CREATE_SKILL_NODE(21011, 112) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(21011, 113) // GetActorAttribute
        CASE_CREATE_SKILL_NODE(21011, 114) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(21011, 115) // CompareFloat
        CASE_CREATE_SKILL_NODE(21011, 116) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(21011, 117) // If
        CASE_CREATE_SKILL_NODE(21011, 118) // CompareFloat
        CASE_CREATE_SKILL_NODE(21011, 119) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(21011, 120) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(21011, 121) // TriggerCheck
        CASE_CREATE_SKILL_NODE(21011, 122) // TriggerCheck
        CASE_CREATE_SKILL_NODE(21011, 123) // TriggerCheck
        CASE_CREATE_SKILL_NODE(21011, 124) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(21011, 125) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(21011, 126) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(21011, 127) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(21011, 128) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(21011, 129) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(21011, 130) // GetLocation
        CASE_CREATE_SKILL_NODE(21011, 131) // GetRotation
        CASE_CREATE_SKILL_NODE(21011, 132) // OffsetCalculate
        CASE_CREATE_SKILL_NODE(21011, 133) // ResetCD
        CASE_CREATE_SKILL_NODE(21011, 134) // PlayAnimation
        CASE_CREATE_SKILL_NODE(21011, 135) // PlaySound
        CASE_CREATE_SKILL_NODE(21011, 136) // Delay
        CASE_CREATE_SKILL_NODE(21011, 137) // PlayEffect
        CASE_CREATE_SKILL_NODE(21011, 138) // If
        CASE_CREATE_SKILL_NODE(21011, 139) // PlayEffect
        CASE_CREATE_SKILL_NODE(21011, 140) // CompareFloat
        CASE_CREATE_SKILL_NODE(21011, 141) // Delay
        CASE_CREATE_SKILL_NODE(21011, 142) // StopEffect
        CASE_CREATE_SKILL_NODE(21011, 143) // PlayEffect
        CASE_CREATE_SKILL_NODE(21011, 144) // If
        CASE_CREATE_SKILL_NODE(21011, 145) // PlayEffect
        CASE_CREATE_SKILL_NODE(21011, 146) // CompareFloat
        CASE_CREATE_SKILL_NODE(21011, 147) // Delay
        CASE_CREATE_SKILL_NODE(21011, 148) // StopEffect
        CASE_CREATE_SKILL_NODE(21011, 149) // RaiseEvent
        CASE_CREATE_SKILL_NODE(21011, 150) // Detect
        CASE_CREATE_SKILL_NODE(21011, 151) // EndPhase
        CASE_CREATE_SKILL_NODE(21011, 153) // Delay
        CASE_CREATE_SKILL_NODE(21011, 154) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(21011, 155) // If
        CASE_CREATE_SKILL_NODE(21011, 156) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(21011, 157) // Delay
        CASE_CREATE_SKILL_NODE(21011, 158) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(21011, 159) // If
        CASE_CREATE_SKILL_NODE(21011, 160) // SkillEndNotify
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_21011

SkillLogic* SkillCreator_21011::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //创建阶段phase
    auto phase = new SkillPhase_21011(1, logic, 3);
    //设置phase执行器
    phase->setRunPhaseNode(1, 23);
    phase->setRunPhaseNode(2, 28);
    phase->setDetectPhaseNode(3, 53);
    phase->setDetectPhaseNode(3, 103);
    phase->setDetectPhaseNode(3, 150);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_21011::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
