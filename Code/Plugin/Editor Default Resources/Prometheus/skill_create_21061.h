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
REGISTER_REGISTER_SKILL_NODE(21061, 2) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_StartPhase::TRIGGER_START, 131, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_StartPhase::TRIGGER_START, 150, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(21061, 2) {
    auto node2 = GET_SKILL_NODE(2, PhaseNode_StartPhase);
    if (node2 == nullptr) {
        node2 = new PhaseNode_StartPhase(2, phase);
        CALL_REGISTER_SKILL_NODE(21061, 2, node2)
    }
    if (noInit == true) {
        return node2;
    }
    return node2;
}
//--------------------------------------------------------------------------------
// TriggerUpdate
//
REGISTER_REGISTER_SKILL_NODE(21061, 4) {
}

REGISTER_CREATE_SKILL_NODE(21061, 4) {
    auto node4 = GET_SKILL_NODE(4, PhaseNode_TriggerUpdate);
    if (node4 == nullptr) {
        node4 = new PhaseNode_TriggerUpdate(4, phase);
        CALL_REGISTER_SKILL_NODE(21061, 4, node4)
    }
    if (noInit == true) {
        return node4;
    }
    return node4;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(21061, 6) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_Delay::TRIGGER_DONE, 127, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(21061, 6) {
    auto node6 = GET_SKILL_NODE(6, PhaseNode_Delay);
    if (node6 == nullptr) {
        node6 = new PhaseNode_Delay(6, phase);
        node6->setTime(.50f);
        CALL_REGISTER_SKILL_NODE(21061, 6, node6)
    }
    if (noInit == true) {
        return node6;
    }
    return node6;
}
//--------------------------------------------------------------------------------
// SpawnCollider
//
REGISTER_REGISTER_SKILL_NODE(21061, 17) {
    pnode->resizeTrigger(PhaseNode_SpawnCollider::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_SpawnCollider::TRIGGER_DONE, 114, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(21061, 17) {
    auto node17 = GET_SKILL_NODE(17, PhaseNode_SpawnCollider);
    if (node17 == nullptr) {
        node17 = new PhaseNode_SpawnCollider(17, phase);
        node17->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node17->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node17->setMesh("");
        node17->setMeshScale(.00f);
        node17->setEffectID(0);
        node17->setEffectScale(.00f);
        node17->setType(PhaseNode_SpawnCollider::SpawnCollider_Type::Circle);
        node17->setTypeParams(0, 5.00f);
        node17->setTime(.40f);
        node17->setPosZ(.00f);
        node17->setRotation(.00f);
        node17->setreentry(false);
        node17->setCheckPeneSound(false);
        CALL_REGISTER_SKILL_NODE(21061, 17, node17)
    }
    if (noInit == true) {
        return node17;
    }
    auto node133 = GET_SKILL_NODE(133, PhaseNode_OffsetCalculate);
    if (node133 != nullptr) node17->setPosX(node133->getOutPosX());
    if (node133 != nullptr) node17->setPosY(node133->getOutPosY());
    return node17;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(21061, 28) {
}

REGISTER_CREATE_SKILL_NODE(21061, 28) {
    auto node28 = GET_SKILL_NODE(28, PhaseNode_EndPhase);
    if (node28 == nullptr) {
        node28 = new PhaseNode_EndPhase(28, phase);
        node28->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node28->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(21061, 28, node28)
    }
    if (noInit == true) {
        return node28;
    }
    return node28;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(21061, 32) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnCollider>(PhaseNode_Delay::TRIGGER_DONE, 17, PhaseNode_SpawnCollider::FUNC_DO, &PhaseNode_SpawnCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(21061, 32) {
    auto node32 = GET_SKILL_NODE(32, PhaseNode_Delay);
    if (node32 == nullptr) {
        node32 = new PhaseNode_Delay(32, phase);
        node32->setTime(.20f);
        CALL_REGISTER_SKILL_NODE(21061, 32, node32)
    }
    if (noInit == true) {
        return node32;
    }
    return node32;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(21061, 41) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_Detect::TRIGGER_ON, 43, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(21061, 41) {
    auto node41 = GET_SKILL_NODE(41, PhaseNode_Detect);
    if (node41 == nullptr) {
        node41 = new PhaseNode_Detect(41, phase);
        node41->setSelf(0U);
        node41->setEvent("");
        node41->setType(PhaseNode_Detect::Detect_Type::Actor_Dead);
        node41->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(21061, 41, node41)
    }
    if (noInit == true) {
        return node41;
    }
    return node41;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(21061, 43) {
}

REGISTER_CREATE_SKILL_NODE(21061, 43) {
    auto node43 = GET_SKILL_NODE(43, PhaseNode_EndPhase);
    if (node43 == nullptr) {
        node43 = new PhaseNode_EndPhase(43, phase);
        node43->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node43->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(21061, 43, node43)
    }
    if (noInit == true) {
        return node43;
    }
    return node43;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(21061, 107) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 119, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 121, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(21061, 107) {
    auto node107 = GET_SKILL_NODE(107, PhaseNode_CreateTriggerNewPene);
    if (node107 == nullptr) {
        node107 = new PhaseNode_CreateTriggerNewPene(107, phase);
        node107->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::In);
        node107->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node107->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Enemy);
        node107->setOnHero(true);
        node107->setOnMinion(true);
        node107->setOnDestruct(true);
        node107->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(21061, 107, node107)
    }
    if (noInit == true) {
        return node107;
    }
    auto node17 = GET_SKILL_NODE(17, PhaseNode_SpawnCollider);
    if (node17 != nullptr) node107->setColliderID(node17->getColliderID());
    return node107;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(21061, 108) {
}

REGISTER_CREATE_SKILL_NODE(21061, 108) {
    auto node108 = GET_SKILL_NODE(108, PhaseNode_TriggerCheck);
    if (node108 == nullptr) {
        node108 = new PhaseNode_TriggerCheck(108, phase);
        auto node4 = GET_SKILL_NODE(4, PhaseNode_TriggerUpdate);
        if (node4 != nullptr) node4->addTriggerCheck(node108);
        
        CALL_REGISTER_SKILL_NODE(21061, 108, node108)
    }
    if (noInit == true) {
        return node108;
    }
    auto node117 = GET_SKILL_NODE(117, PhaseNode_CreateTriggerNewPene);
    if (node117 != nullptr) node108->setTrigger(0, node117->getTriggerID());
    return node108;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(21061, 109) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 110, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(21061, 109) {
    auto node109 = GET_SKILL_NODE(109, PhaseNode_ActorFilterNewPene);
    if (node109 == nullptr) {
        node109 = new PhaseNode_ActorFilterNewPene(109, phase);
        node109->setHero(true);
        node109->setMinion(true);
        node109->setDestruct(true);
        node109->setShield(false);
        node109->setTotalCount(0);
        node109->setPerCount(1);
        CALL_REGISTER_SKILL_NODE(21061, 109, node109)
    }
    if (noInit == true) {
        return node109;
    }
    auto node113 = GET_SKILL_NODE(113, PhaseNode_CreateTriggerNewPene);
    if (node113 != nullptr) node109->setInput(node113->getOther());
    return node109;
}
//--------------------------------------------------------------------------------
// GetActorAttribute
//
REGISTER_REGISTER_SKILL_NODE(21061, 110) {
    pnode->resizeTrigger(PhaseNode_GetActorAttribute::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 111, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 124, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 125, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 126, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
}

REGISTER_CREATE_SKILL_NODE(21061, 110) {
    auto node110 = GET_SKILL_NODE(110, PhaseNode_GetActorAttribute);
    if (node110 == nullptr) {
        node110 = new PhaseNode_GetActorAttribute(110, phase);
        node110->setTarget(0U);
        node110->setType({202});
        CALL_REGISTER_SKILL_NODE(21061, 110, node110)
    }
    if (noInit == true) {
        return node110;
    }
    return node110;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(21061, 111) {
}

REGISTER_CREATE_SKILL_NODE(21061, 111) {
    auto node111 = GET_SKILL_NODE(111, PhaseNode_AddSkillBuffs);
    if (node111 == nullptr) {
        node111 = new PhaseNode_AddSkillBuffs(111, phase);
        node111->setConfigID({11});
        CALL_REGISTER_SKILL_NODE(21061, 111, node111)
    }
    if (noInit == true) {
        return node111;
    }
    auto node109 = GET_SKILL_NODE(109, PhaseNode_ActorFilterNewPene);
    auto node110 = GET_SKILL_NODE(110, PhaseNode_GetActorAttribute);
    if (node109 != nullptr) node111->setTarget(node109->getOutput());
    if (node110 != nullptr) node111->setAttribute(node110->getAttribute());
    return node111;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(21061, 112) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 107, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_LESS, 113, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
}

REGISTER_CREATE_SKILL_NODE(21061, 112) {
    auto node112 = GET_SKILL_NODE(112, PhaseNode_CompareFloat);
    if (node112 == nullptr) {
        node112 = new PhaseNode_CompareFloat(112, phase);
        node112->setA(.00f);
        node112->setB(.00f);
        CALL_REGISTER_SKILL_NODE(21061, 112, node112)
    }
    if (noInit == true) {
        return node112;
    }
    return node112;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(21061, 113) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 118, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 109, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(21061, 113) {
    auto node113 = GET_SKILL_NODE(113, PhaseNode_CreateTriggerNewPene);
    if (node113 == nullptr) {
        node113 = new PhaseNode_CreateTriggerNewPene(113, phase);
        node113->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::Tick);
        node113->setTypeParams(0, .00f);
        node113->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node113->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Enemy);
        node113->setOnHero(true);
        node113->setOnMinion(true);
        node113->setOnDestruct(true);
        node113->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(21061, 113, node113)
    }
    if (noInit == true) {
        return node113;
    }
    auto node17 = GET_SKILL_NODE(17, PhaseNode_SpawnCollider);
    if (node17 != nullptr) node113->setColliderID(node17->getColliderID());
    return node113;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(21061, 114) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_If::TRIGGER_FALSE, 115, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_If::TRIGGER_TRUE, 112, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(21061, 114) {
    auto node114 = GET_SKILL_NODE(114, PhaseNode_If);
    if (node114 == nullptr) {
        node114 = new PhaseNode_If(114, phase);
        node114->setCondition(true);
        CALL_REGISTER_SKILL_NODE(21061, 114, node114)
    }
    if (noInit == true) {
        return node114;
    }
    return node114;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(21061, 115) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 117, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_LESS, 116, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
}

REGISTER_CREATE_SKILL_NODE(21061, 115) {
    auto node115 = GET_SKILL_NODE(115, PhaseNode_CompareFloat);
    if (node115 == nullptr) {
        node115 = new PhaseNode_CompareFloat(115, phase);
        node115->setA(.00f);
        node115->setB(.00f);
        CALL_REGISTER_SKILL_NODE(21061, 115, node115)
    }
    if (noInit == true) {
        return node115;
    }
    return node115;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(21061, 116) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 120, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 122, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(21061, 116) {
    auto node116 = GET_SKILL_NODE(116, PhaseNode_CreateTriggerNewPene);
    if (node116 == nullptr) {
        node116 = new PhaseNode_CreateTriggerNewPene(116, phase);
        node116->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::Tick);
        node116->setTypeParams(0, .00f);
        node116->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node116->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Friend);
        node116->setOnHero(true);
        node116->setOnMinion(true);
        node116->setOnDestruct(true);
        node116->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(21061, 116, node116)
    }
    if (noInit == true) {
        return node116;
    }
    auto node17 = GET_SKILL_NODE(17, PhaseNode_SpawnCollider);
    if (node17 != nullptr) node116->setColliderID(node17->getColliderID());
    return node116;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(21061, 117) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 108, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 123, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(21061, 117) {
    auto node117 = GET_SKILL_NODE(117, PhaseNode_CreateTriggerNewPene);
    if (node117 == nullptr) {
        node117 = new PhaseNode_CreateTriggerNewPene(117, phase);
        node117->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::In);
        node117->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node117->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Friend);
        node117->setOnHero(true);
        node117->setOnMinion(true);
        node117->setOnDestruct(true);
        node117->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(21061, 117, node117)
    }
    if (noInit == true) {
        return node117;
    }
    auto node17 = GET_SKILL_NODE(17, PhaseNode_SpawnCollider);
    if (node17 != nullptr) node117->setColliderID(node17->getColliderID());
    return node117;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(21061, 118) {
}

REGISTER_CREATE_SKILL_NODE(21061, 118) {
    auto node118 = GET_SKILL_NODE(118, PhaseNode_TriggerCheck);
    if (node118 == nullptr) {
        node118 = new PhaseNode_TriggerCheck(118, phase);
        auto node4 = GET_SKILL_NODE(4, PhaseNode_TriggerUpdate);
        if (node4 != nullptr) node4->addTriggerCheck(node118);
        
        CALL_REGISTER_SKILL_NODE(21061, 118, node118)
    }
    if (noInit == true) {
        return node118;
    }
    auto node113 = GET_SKILL_NODE(113, PhaseNode_CreateTriggerNewPene);
    if (node113 != nullptr) node118->setTrigger(0, node113->getTriggerID());
    return node118;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(21061, 119) {
}

REGISTER_CREATE_SKILL_NODE(21061, 119) {
    auto node119 = GET_SKILL_NODE(119, PhaseNode_TriggerCheck);
    if (node119 == nullptr) {
        node119 = new PhaseNode_TriggerCheck(119, phase);
        auto node4 = GET_SKILL_NODE(4, PhaseNode_TriggerUpdate);
        if (node4 != nullptr) node4->addTriggerCheck(node119);
        
        CALL_REGISTER_SKILL_NODE(21061, 119, node119)
    }
    if (noInit == true) {
        return node119;
    }
    auto node107 = GET_SKILL_NODE(107, PhaseNode_CreateTriggerNewPene);
    if (node107 != nullptr) node119->setTrigger(0, node107->getTriggerID());
    return node119;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(21061, 120) {
}

REGISTER_CREATE_SKILL_NODE(21061, 120) {
    auto node120 = GET_SKILL_NODE(120, PhaseNode_TriggerCheck);
    if (node120 == nullptr) {
        node120 = new PhaseNode_TriggerCheck(120, phase);
        auto node4 = GET_SKILL_NODE(4, PhaseNode_TriggerUpdate);
        if (node4 != nullptr) node4->addTriggerCheck(node120);
        
        CALL_REGISTER_SKILL_NODE(21061, 120, node120)
    }
    if (noInit == true) {
        return node120;
    }
    auto node116 = GET_SKILL_NODE(116, PhaseNode_CreateTriggerNewPene);
    if (node116 != nullptr) node120->setTrigger(0, node116->getTriggerID());
    return node120;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(21061, 121) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 110, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(21061, 121) {
    auto node121 = GET_SKILL_NODE(121, PhaseNode_ActorFilterNewPene);
    if (node121 == nullptr) {
        node121 = new PhaseNode_ActorFilterNewPene(121, phase);
        node121->setHero(true);
        node121->setMinion(true);
        node121->setDestruct(true);
        node121->setShield(false);
        node121->setTotalCount(0);
        node121->setPerCount(1);
        CALL_REGISTER_SKILL_NODE(21061, 121, node121)
    }
    if (noInit == true) {
        return node121;
    }
    auto node107 = GET_SKILL_NODE(107, PhaseNode_CreateTriggerNewPene);
    if (node107 != nullptr) node121->setInput(node107->getOther());
    return node121;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(21061, 122) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 110, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(21061, 122) {
    auto node122 = GET_SKILL_NODE(122, PhaseNode_ActorFilterNewPene);
    if (node122 == nullptr) {
        node122 = new PhaseNode_ActorFilterNewPene(122, phase);
        node122->setHero(true);
        node122->setMinion(true);
        node122->setDestruct(true);
        node122->setShield(false);
        node122->setTotalCount(0);
        node122->setPerCount(1);
        CALL_REGISTER_SKILL_NODE(21061, 122, node122)
    }
    if (noInit == true) {
        return node122;
    }
    auto node116 = GET_SKILL_NODE(116, PhaseNode_CreateTriggerNewPene);
    if (node116 != nullptr) node122->setInput(node116->getOther());
    return node122;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(21061, 123) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 110, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(21061, 123) {
    auto node123 = GET_SKILL_NODE(123, PhaseNode_ActorFilterNewPene);
    if (node123 == nullptr) {
        node123 = new PhaseNode_ActorFilterNewPene(123, phase);
        node123->setHero(true);
        node123->setMinion(true);
        node123->setDestruct(true);
        node123->setShield(false);
        node123->setTotalCount(0);
        node123->setPerCount(1);
        CALL_REGISTER_SKILL_NODE(21061, 123, node123)
    }
    if (noInit == true) {
        return node123;
    }
    auto node117 = GET_SKILL_NODE(117, PhaseNode_CreateTriggerNewPene);
    if (node117 != nullptr) node123->setInput(node117->getOther());
    return node123;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(21061, 124) {
}

REGISTER_CREATE_SKILL_NODE(21061, 124) {
    auto node124 = GET_SKILL_NODE(124, PhaseNode_AddSkillBuffs);
    if (node124 == nullptr) {
        node124 = new PhaseNode_AddSkillBuffs(124, phase);
        node124->setConfigID({11});
        CALL_REGISTER_SKILL_NODE(21061, 124, node124)
    }
    if (noInit == true) {
        return node124;
    }
    auto node121 = GET_SKILL_NODE(121, PhaseNode_ActorFilterNewPene);
    auto node110 = GET_SKILL_NODE(110, PhaseNode_GetActorAttribute);
    if (node121 != nullptr) node124->setTarget(node121->getOutput());
    if (node110 != nullptr) node124->setAttribute(node110->getAttribute());
    return node124;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(21061, 125) {
}

REGISTER_CREATE_SKILL_NODE(21061, 125) {
    auto node125 = GET_SKILL_NODE(125, PhaseNode_AddSkillBuffs);
    if (node125 == nullptr) {
        node125 = new PhaseNode_AddSkillBuffs(125, phase);
        node125->setConfigID({11});
        CALL_REGISTER_SKILL_NODE(21061, 125, node125)
    }
    if (noInit == true) {
        return node125;
    }
    auto node122 = GET_SKILL_NODE(122, PhaseNode_ActorFilterNewPene);
    auto node110 = GET_SKILL_NODE(110, PhaseNode_GetActorAttribute);
    if (node122 != nullptr) node125->setTarget(node122->getOutput());
    if (node110 != nullptr) node125->setAttribute(node110->getAttribute());
    return node125;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(21061, 126) {
}

REGISTER_CREATE_SKILL_NODE(21061, 126) {
    auto node126 = GET_SKILL_NODE(126, PhaseNode_AddSkillBuffs);
    if (node126 == nullptr) {
        node126 = new PhaseNode_AddSkillBuffs(126, phase);
        node126->setConfigID({11});
        CALL_REGISTER_SKILL_NODE(21061, 126, node126)
    }
    if (noInit == true) {
        return node126;
    }
    auto node123 = GET_SKILL_NODE(123, PhaseNode_ActorFilterNewPene);
    auto node110 = GET_SKILL_NODE(110, PhaseNode_GetActorAttribute);
    if (node123 != nullptr) node126->setTarget(node123->getOutput());
    if (node110 != nullptr) node126->setAttribute(node110->getAttribute());
    return node126;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(21061, 127) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_ResetCD::TRIGGER_DONE, 128, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(21061, 127) {
    auto node127 = GET_SKILL_NODE(127, PhaseNode_ResetCD);
    if (node127 == nullptr) {
        node127 = new PhaseNode_ResetCD(127, phase);
        node127->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node127->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node127->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(21061, 127, node127)
    }
    if (noInit == true) {
        return node127;
    }
    return node127;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(21061, 128) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_PlayAnimation::TRIGGER_DONE, 129, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(21061, 128) {
    auto node128 = GET_SKILL_NODE(128, PhaseNode_PlayAnimation);
    if (node128 == nullptr) {
        node128 = new PhaseNode_PlayAnimation(128, phase);
        node128->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node128->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node128->setTarget(0U);
        node128->setAnimation("Skill1S1");
        node128->setParameter("");
        node128->setValue(false);
        CALL_REGISTER_SKILL_NODE(21061, 128, node128)
    }
    if (noInit == true) {
        return node128;
    }
    return node128;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(21061, 129) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlaySound::TRIGGER_DONE, 130, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(21061, 129) {
    auto node129 = GET_SKILL_NODE(129, PhaseNode_PlaySound);
    if (node129 == nullptr) {
        node129 = new PhaseNode_PlaySound(129, phase);
        node129->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node129->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node129->setSoundID("SE_Boss2106_ATK1");
        node129->setTarget(0U);
        node129->setUsePos(false);
        node129->setPosX(.00f);
        node129->setPosY(.00f);
        node129->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(21061, 129, node129)
    }
    if (noInit == true) {
        return node129;
    }
    return node129;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(21061, 130) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_Delay::TRIGGER_DONE, 141, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(21061, 130) {
    auto node130 = GET_SKILL_NODE(130, PhaseNode_Delay);
    if (node130 == nullptr) {
        node130 = new PhaseNode_Delay(130, phase);
        node130->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(21061, 130, node130)
    }
    if (noInit == true) {
        return node130;
    }
    return node130;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(21061, 131) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetRotation>(PhaseNode_GetLocation::TRIGGER_DONE, 132, PhaseNode_GetRotation::FUNC_DO, &PhaseNode_GetRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(21061, 131) {
    auto node131 = GET_SKILL_NODE(131, PhaseNode_GetLocation);
    if (node131 == nullptr) {
        node131 = new PhaseNode_GetLocation(131, phase);
        node131->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node131->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(21061, 131, node131)
    }
    if (noInit == true) {
        return node131;
    }
    return node131;
}
//--------------------------------------------------------------------------------
// GetRotation
//
REGISTER_REGISTER_SKILL_NODE(21061, 132) {
    pnode->resizeTrigger(PhaseNode_GetRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_OffsetCalculate>(PhaseNode_GetRotation::TRIGGER_DONE, 133, PhaseNode_OffsetCalculate::FUNC_DO, &PhaseNode_OffsetCalculate::Do);
}

REGISTER_CREATE_SKILL_NODE(21061, 132) {
    auto node132 = GET_SKILL_NODE(132, PhaseNode_GetRotation);
    if (node132 == nullptr) {
        node132 = new PhaseNode_GetRotation(132, phase);
        node132->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node132->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(21061, 132, node132)
    }
    if (noInit == true) {
        return node132;
    }
    return node132;
}
//--------------------------------------------------------------------------------
// OffsetCalculate
//
REGISTER_REGISTER_SKILL_NODE(21061, 133) {
    pnode->resizeTrigger(PhaseNode_OffsetCalculate::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 135, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(21061, 133) {
    auto node133 = GET_SKILL_NODE(133, PhaseNode_OffsetCalculate);
    if (node133 == nullptr) {
        node133 = new PhaseNode_OffsetCalculate(133, phase);
        node133->setPosZ(.00f);
        node133->setOffsetX(.00f);
        node133->setOffsetY(.00f);
        node133->setOffsetZ(.00f);
        node133->setRotOffset(.00f);
        CALL_REGISTER_SKILL_NODE(21061, 133, node133)
    }
    if (noInit == true) {
        return node133;
    }
    auto node131 = GET_SKILL_NODE(131, PhaseNode_GetLocation);
    auto node132 = GET_SKILL_NODE(132, PhaseNode_GetRotation);
    if (node131 != nullptr) node133->setPosX(node131->getX());
    if (node131 != nullptr) node133->setPosY(node131->getY());
    if (node132 != nullptr) node133->setRotation(node132->getAngle());
    return node133;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(21061, 134) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_PlayEffect::TRIGGER_DONE, 137, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(21061, 134) {
    auto node134 = GET_SKILL_NODE(134, PhaseNode_PlayEffect);
    if (node134 == nullptr) {
        node134 = new PhaseNode_PlayEffect(134, phase);
        node134->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node134->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node134->setEffectID(1014);
        node134->setChangeColor(false);
        node134->setType(PhaseNode_PlayEffect::PlayEffect_Type::WithTarget);
        node134->getVars().reserve(5);
        node134->getVars().setVariable<uint64_t>(0, 0U);
        node134->getVars().setVariable<std::string>(1, "");
        node134->getVars().setVariable<float>(2, .00f);
        node134->getVars().setVariable<float>(3, .00f);
        node134->getVars().setVariable<float>(4, .00f);
        node134->setRotation(.00f);
        node134->setScale(2.50f);
        CALL_REGISTER_SKILL_NODE(21061, 134, node134)
    }
    if (noInit == true) {
        return node134;
    }
    auto node133 = GET_SKILL_NODE(133, PhaseNode_OffsetCalculate);
    if (node133 != nullptr) node134->getVars().setVariable<float>(2, node133->getOutPosX());
    if (node133 != nullptr) node134->getVars().setVariable<float>(3, node133->getOutPosY());
    return node134;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(21061, 135) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_FALSE, 136, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_TRUE, 134, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(21061, 135) {
    auto node135 = GET_SKILL_NODE(135, PhaseNode_If);
    if (node135 == nullptr) {
        node135 = new PhaseNode_If(135, phase);
        node135->setCondition(false);
        CALL_REGISTER_SKILL_NODE(21061, 135, node135)
    }
    if (noInit == true) {
        return node135;
    }
    return node135;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(21061, 136) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_PlayEffect::TRIGGER_DONE, 137, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(21061, 136) {
    auto node136 = GET_SKILL_NODE(136, PhaseNode_PlayEffect);
    if (node136 == nullptr) {
        node136 = new PhaseNode_PlayEffect(136, phase);
        node136->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node136->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node136->setEffectID(1014);
        node136->setChangeColor(false);
        node136->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node136->getVars().reserve(3);
        node136->getVars().setVariable<float>(0, .00f);
        node136->getVars().setVariable<float>(1, .00f);
        node136->getVars().setVariable<float>(2, .00f);
        node136->setRotation(.00f);
        node136->setScale(2.50f);
        CALL_REGISTER_SKILL_NODE(21061, 136, node136)
    }
    if (noInit == true) {
        return node136;
    }
    auto node133 = GET_SKILL_NODE(133, PhaseNode_OffsetCalculate);
    if (node133 != nullptr) node136->getVars().setVariable<float>(0, node133->getOutPosX());
    if (node133 != nullptr) node136->getVars().setVariable<float>(1, node133->getOutPosY());
    return node136;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(21061, 137) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 6, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_LESS, 138, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_LESS, 6, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(21061, 137) {
    auto node137 = GET_SKILL_NODE(137, PhaseNode_CompareFloat);
    if (node137 == nullptr) {
        node137 = new PhaseNode_CompareFloat(137, phase);
        node137->setA(.00f);
        node137->setB(.70f);
        CALL_REGISTER_SKILL_NODE(21061, 137, node137)
    }
    if (noInit == true) {
        return node137;
    }
    return node137;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(21061, 138) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StopEffect>(PhaseNode_Delay::TRIGGER_DONE, 139, PhaseNode_StopEffect::FUNC_DO, &PhaseNode_StopEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(21061, 138) {
    auto node138 = GET_SKILL_NODE(138, PhaseNode_Delay);
    if (node138 == nullptr) {
        node138 = new PhaseNode_Delay(138, phase);
        node138->setTime(.70f);
        CALL_REGISTER_SKILL_NODE(21061, 138, node138)
    }
    if (noInit == true) {
        return node138;
    }
    return node138;
}
//--------------------------------------------------------------------------------
// StopEffect
//
REGISTER_REGISTER_SKILL_NODE(21061, 139) {
}

REGISTER_CREATE_SKILL_NODE(21061, 139) {
    auto node139 = GET_SKILL_NODE(139, PhaseNode_StopEffect);
    if (node139 == nullptr) {
        node139 = new PhaseNode_StopEffect(139, phase);
        node139->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node139->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node139->setEffectID(1014);
        CALL_REGISTER_SKILL_NODE(21061, 139, node139)
    }
    if (noInit == true) {
        return node139;
    }
    return node139;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(21061, 140) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_PlayEffect::TRIGGER_DONE, 143, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(21061, 140) {
    auto node140 = GET_SKILL_NODE(140, PhaseNode_PlayEffect);
    if (node140 == nullptr) {
        node140 = new PhaseNode_PlayEffect(140, phase);
        node140->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node140->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node140->setEffectID(210611);
        node140->setChangeColor(false);
        node140->setType(PhaseNode_PlayEffect::PlayEffect_Type::WithTarget);
        node140->getVars().reserve(5);
        node140->getVars().setVariable<uint64_t>(0, 0U);
        node140->getVars().setVariable<std::string>(1, "");
        node140->getVars().setVariable<float>(2, .00f);
        node140->getVars().setVariable<float>(3, .00f);
        node140->getVars().setVariable<float>(4, .00f);
        node140->setRotation(.00f);
        node140->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(21061, 140, node140)
    }
    if (noInit == true) {
        return node140;
    }
    auto node133 = GET_SKILL_NODE(133, PhaseNode_OffsetCalculate);
    if (node133 != nullptr) node140->getVars().setVariable<float>(2, node133->getOutPosX());
    if (node133 != nullptr) node140->getVars().setVariable<float>(3, node133->getOutPosY());
    return node140;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(21061, 141) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_FALSE, 142, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_TRUE, 140, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(21061, 141) {
    auto node141 = GET_SKILL_NODE(141, PhaseNode_If);
    if (node141 == nullptr) {
        node141 = new PhaseNode_If(141, phase);
        node141->setCondition(false);
        CALL_REGISTER_SKILL_NODE(21061, 141, node141)
    }
    if (noInit == true) {
        return node141;
    }
    return node141;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(21061, 142) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_PlayEffect::TRIGGER_DONE, 143, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(21061, 142) {
    auto node142 = GET_SKILL_NODE(142, PhaseNode_PlayEffect);
    if (node142 == nullptr) {
        node142 = new PhaseNode_PlayEffect(142, phase);
        node142->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node142->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node142->setEffectID(210611);
        node142->setChangeColor(false);
        node142->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node142->getVars().reserve(3);
        node142->getVars().setVariable<float>(0, .00f);
        node142->getVars().setVariable<float>(1, .00f);
        node142->getVars().setVariable<float>(2, .00f);
        node142->setRotation(.00f);
        node142->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(21061, 142, node142)
    }
    if (noInit == true) {
        return node142;
    }
    auto node133 = GET_SKILL_NODE(133, PhaseNode_OffsetCalculate);
    if (node133 != nullptr) node142->getVars().setVariable<float>(0, node133->getOutPosX());
    if (node133 != nullptr) node142->getVars().setVariable<float>(1, node133->getOutPosY());
    return node142;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(21061, 143) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 146, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 32, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_LESS, 144, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_LESS, 146, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_LESS, 32, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(21061, 143) {
    auto node143 = GET_SKILL_NODE(143, PhaseNode_CompareFloat);
    if (node143 == nullptr) {
        node143 = new PhaseNode_CompareFloat(143, phase);
        node143->setA(.00f);
        node143->setB(.00f);
        CALL_REGISTER_SKILL_NODE(21061, 143, node143)
    }
    if (noInit == true) {
        return node143;
    }
    return node143;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(21061, 144) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StopEffect>(PhaseNode_Delay::TRIGGER_DONE, 145, PhaseNode_StopEffect::FUNC_DO, &PhaseNode_StopEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(21061, 144) {
    auto node144 = GET_SKILL_NODE(144, PhaseNode_Delay);
    if (node144 == nullptr) {
        node144 = new PhaseNode_Delay(144, phase);
        node144->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(21061, 144, node144)
    }
    if (noInit == true) {
        return node144;
    }
    return node144;
}
//--------------------------------------------------------------------------------
// StopEffect
//
REGISTER_REGISTER_SKILL_NODE(21061, 145) {
}

REGISTER_CREATE_SKILL_NODE(21061, 145) {
    auto node145 = GET_SKILL_NODE(145, PhaseNode_StopEffect);
    if (node145 == nullptr) {
        node145 = new PhaseNode_StopEffect(145, phase);
        node145->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node145->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node145->setEffectID(210611);
        CALL_REGISTER_SKILL_NODE(21061, 145, node145)
    }
    if (noInit == true) {
        return node145;
    }
    return node145;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(21061, 146) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_Delay::TRIGGER_DONE, 148, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(21061, 146) {
    auto node146 = GET_SKILL_NODE(146, PhaseNode_Delay);
    if (node146 == nullptr) {
        node146 = new PhaseNode_Delay(146, phase);
        node146->setTime(1.30f);
        CALL_REGISTER_SKILL_NODE(21061, 146, node146)
    }
    if (noInit == true) {
        return node146;
    }
    return node146;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(21061, 147) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 28, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(21061, 147) {
    auto node147 = GET_SKILL_NODE(147, PhaseNode_SkillEndNotify);
    if (node147 == nullptr) {
        node147 = new PhaseNode_SkillEndNotify(147, phase);
        node147->setReturnType(false);
        CALL_REGISTER_SKILL_NODE(21061, 147, node147)
    }
    if (noInit == true) {
        return node147;
    }
    return node147;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(21061, 148) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_FALSE, 149, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_TRUE, 147, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
}

REGISTER_CREATE_SKILL_NODE(21061, 148) {
    auto node148 = GET_SKILL_NODE(148, PhaseNode_If);
    if (node148 == nullptr) {
        node148 = new PhaseNode_If(148, phase);
        node148->setCondition(false);
        CALL_REGISTER_SKILL_NODE(21061, 148, node148)
    }
    if (noInit == true) {
        return node148;
    }
    return node148;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(21061, 149) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 28, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(21061, 149) {
    auto node149 = GET_SKILL_NODE(149, PhaseNode_SkillEndNotify);
    if (node149 == nullptr) {
        node149 = new PhaseNode_SkillEndNotify(149, phase);
        node149->setReturnType(true);
        CALL_REGISTER_SKILL_NODE(21061, 149, node149)
    }
    if (noInit == true) {
        return node149;
    }
    return node149;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(21061, 150) {
}

REGISTER_CREATE_SKILL_NODE(21061, 150) {
    auto node150 = GET_SKILL_NODE(150, PhaseNode_RaiseEvent);
    if (node150 == nullptr) {
        node150 = new PhaseNode_RaiseEvent(150, phase);
        node150->setEvent("MonsterInterrupt");
        node150->setTarget(0U);
        node150->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node150->setTypeParams(0, 0);
        node150->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(21061, 150, node150)
    }
    if (noInit == true) {
        return node150;
    }
    return node150;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(21061, 151) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_Detect::TRIGGER_ON, 154, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(21061, 151) {
    auto node151 = GET_SKILL_NODE(151, PhaseNode_Detect);
    if (node151 == nullptr) {
        node151 = new PhaseNode_Detect(151, phase);
        node151->setSelf(0U);
        node151->setEvent("MonsterInterrupt");
        node151->setType(PhaseNode_Detect::Detect_Type::Interrupt_Skill);
        node151->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(21061, 151, node151)
    }
    if (noInit == true) {
        return node151;
    }
    return node151;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(21061, 152) {
}

REGISTER_CREATE_SKILL_NODE(21061, 152) {
    auto node152 = GET_SKILL_NODE(152, PhaseNode_EndPhase);
    if (node152 == nullptr) {
        node152 = new PhaseNode_EndPhase(152, phase);
        node152->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node152->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(21061, 152, node152)
    }
    if (noInit == true) {
        return node152;
    }
    return node152;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(21061, 154) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_Delay::TRIGGER_DONE, 156, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(21061, 154) {
    auto node154 = GET_SKILL_NODE(154, PhaseNode_Delay);
    if (node154 == nullptr) {
        node154 = new PhaseNode_Delay(154, phase);
        node154->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(21061, 154, node154)
    }
    if (noInit == true) {
        return node154;
    }
    return node154;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(21061, 155) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 152, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(21061, 155) {
    auto node155 = GET_SKILL_NODE(155, PhaseNode_SkillEndNotify);
    if (node155 == nullptr) {
        node155 = new PhaseNode_SkillEndNotify(155, phase);
        node155->setReturnType(false);
        CALL_REGISTER_SKILL_NODE(21061, 155, node155)
    }
    if (noInit == true) {
        return node155;
    }
    return node155;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(21061, 156) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_FALSE, 157, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_TRUE, 155, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
}

REGISTER_CREATE_SKILL_NODE(21061, 156) {
    auto node156 = GET_SKILL_NODE(156, PhaseNode_If);
    if (node156 == nullptr) {
        node156 = new PhaseNode_If(156, phase);
        node156->setCondition(false);
        CALL_REGISTER_SKILL_NODE(21061, 156, node156)
    }
    if (noInit == true) {
        return node156;
    }
    return node156;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(21061, 157) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 152, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(21061, 157) {
    auto node157 = GET_SKILL_NODE(157, PhaseNode_SkillEndNotify);
    if (node157 == nullptr) {
        node157 = new PhaseNode_SkillEndNotify(157, phase);
        node157->setReturnType(true);
        CALL_REGISTER_SKILL_NODE(21061, 157, node157)
    }
    if (noInit == true) {
        return node157;
    }
    return node157;
}

//--------------------------------------------------------------------------------
// SkillCreator_21061
//
class SkillCreator_21061 : public SkillCreator {
public:
    SkillCreator_21061() {}
    virtual ~SkillCreator_21061() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_21061

//--------------------------------------------------------------------------------
// SkillPhase_21061
//
class SkillPhase_21061 : public SkillPhase {
public:
    SkillPhase_21061(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_21061() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(21061, 2) // StartPhase
        CASE_CREATE_SKILL_NODE(21061, 4) // TriggerUpdate
        CASE_CREATE_SKILL_NODE(21061, 6) // Delay
        CASE_CREATE_SKILL_NODE(21061, 17) // SpawnCollider
        CASE_CREATE_SKILL_NODE(21061, 28) // EndPhase
        CASE_CREATE_SKILL_NODE(21061, 32) // Delay
        CASE_CREATE_SKILL_NODE(21061, 41) // Detect
        CASE_CREATE_SKILL_NODE(21061, 43) // EndPhase
        CASE_CREATE_SKILL_NODE(21061, 107) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(21061, 108) // TriggerCheck
        CASE_CREATE_SKILL_NODE(21061, 109) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(21061, 110) // GetActorAttribute
        CASE_CREATE_SKILL_NODE(21061, 111) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(21061, 112) // CompareFloat
        CASE_CREATE_SKILL_NODE(21061, 113) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(21061, 114) // If
        CASE_CREATE_SKILL_NODE(21061, 115) // CompareFloat
        CASE_CREATE_SKILL_NODE(21061, 116) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(21061, 117) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(21061, 118) // TriggerCheck
        CASE_CREATE_SKILL_NODE(21061, 119) // TriggerCheck
        CASE_CREATE_SKILL_NODE(21061, 120) // TriggerCheck
        CASE_CREATE_SKILL_NODE(21061, 121) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(21061, 122) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(21061, 123) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(21061, 124) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(21061, 125) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(21061, 126) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(21061, 127) // ResetCD
        CASE_CREATE_SKILL_NODE(21061, 128) // PlayAnimation
        CASE_CREATE_SKILL_NODE(21061, 129) // PlaySound
        CASE_CREATE_SKILL_NODE(21061, 130) // Delay
        CASE_CREATE_SKILL_NODE(21061, 131) // GetLocation
        CASE_CREATE_SKILL_NODE(21061, 132) // GetRotation
        CASE_CREATE_SKILL_NODE(21061, 133) // OffsetCalculate
        CASE_CREATE_SKILL_NODE(21061, 134) // PlayEffect
        CASE_CREATE_SKILL_NODE(21061, 135) // If
        CASE_CREATE_SKILL_NODE(21061, 136) // PlayEffect
        CASE_CREATE_SKILL_NODE(21061, 137) // CompareFloat
        CASE_CREATE_SKILL_NODE(21061, 138) // Delay
        CASE_CREATE_SKILL_NODE(21061, 139) // StopEffect
        CASE_CREATE_SKILL_NODE(21061, 140) // PlayEffect
        CASE_CREATE_SKILL_NODE(21061, 141) // If
        CASE_CREATE_SKILL_NODE(21061, 142) // PlayEffect
        CASE_CREATE_SKILL_NODE(21061, 143) // CompareFloat
        CASE_CREATE_SKILL_NODE(21061, 144) // Delay
        CASE_CREATE_SKILL_NODE(21061, 145) // StopEffect
        CASE_CREATE_SKILL_NODE(21061, 146) // Delay
        CASE_CREATE_SKILL_NODE(21061, 147) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(21061, 148) // If
        CASE_CREATE_SKILL_NODE(21061, 149) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(21061, 150) // RaiseEvent
        CASE_CREATE_SKILL_NODE(21061, 151) // Detect
        CASE_CREATE_SKILL_NODE(21061, 152) // EndPhase
        CASE_CREATE_SKILL_NODE(21061, 154) // Delay
        CASE_CREATE_SKILL_NODE(21061, 155) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(21061, 156) // If
        CASE_CREATE_SKILL_NODE(21061, 157) // SkillEndNotify
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_21061

SkillLogic* SkillCreator_21061::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //创建阶段phase
    auto phase = new SkillPhase_21061(1, logic, 3);
    //设置phase执行器
    phase->setRunPhaseNode(1, 2);
    phase->setRunPhaseNode(2, 4);
    phase->setDetectPhaseNode(3, 41);
    phase->setDetectPhaseNode(3, 151);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_21061::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
