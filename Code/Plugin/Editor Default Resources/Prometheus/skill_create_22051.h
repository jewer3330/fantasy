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
REGISTER_REGISTER_SKILL_NODE(22051, 2) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_StartPhase::TRIGGER_START, 169, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_StartPhase::TRIGGER_START, 165, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_StartPhase::TRIGGER_START, 139, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(22051, 2) {
    auto node2 = GET_SKILL_NODE(2, PhaseNode_StartPhase);
    if (node2 == nullptr) {
        node2 = new PhaseNode_StartPhase(2, phase);
        CALL_REGISTER_SKILL_NODE(22051, 2, node2)
    }
    if (noInit == true) {
        return node2;
    }
    return node2;
}
//--------------------------------------------------------------------------------
// TriggerUpdate
//
REGISTER_REGISTER_SKILL_NODE(22051, 4) {
}

REGISTER_CREATE_SKILL_NODE(22051, 4) {
    auto node4 = GET_SKILL_NODE(4, PhaseNode_TriggerUpdate);
    if (node4 == nullptr) {
        node4 = new PhaseNode_TriggerUpdate(4, phase);
        CALL_REGISTER_SKILL_NODE(22051, 4, node4)
    }
    if (noInit == true) {
        return node4;
    }
    return node4;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(22051, 12) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_PlayAnimation::TRIGGER_DONE, 152, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(22051, 12) {
    auto node12 = GET_SKILL_NODE(12, PhaseNode_PlayAnimation);
    if (node12 == nullptr) {
        node12 = new PhaseNode_PlayAnimation(12, phase);
        node12->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node12->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node12->setTarget(0U);
        node12->setAnimation("Skill1S1");
        node12->setParameter("");
        node12->setValue(false);
        CALL_REGISTER_SKILL_NODE(22051, 12, node12)
    }
    if (noInit == true) {
        return node12;
    }
    return node12;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22051, 14) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnCollider>(PhaseNode_Delay::TRIGGER_DONE, 20, PhaseNode_SpawnCollider::FUNC_DO, &PhaseNode_SpawnCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(22051, 14) {
    auto node14 = GET_SKILL_NODE(14, PhaseNode_Delay);
    if (node14 == nullptr) {
        node14 = new PhaseNode_Delay(14, phase);
        node14->setTime(.65f);
        CALL_REGISTER_SKILL_NODE(22051, 14, node14)
    }
    if (noInit == true) {
        return node14;
    }
    return node14;
}
//--------------------------------------------------------------------------------
// SpawnCollider
//
REGISTER_REGISTER_SKILL_NODE(22051, 20) {
    pnode->resizeTrigger(PhaseNode_SpawnCollider::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_SpawnCollider::TRIGGER_DONE, 161, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_SpawnCollider::TRIGGER_DONE, 126, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(22051, 20) {
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
        node20->setTypeParams(0, 3.00f);
        node20->setTime(.30f);
        node20->setreentry(false);
        node20->setCheckPeneSound(false);
        CALL_REGISTER_SKILL_NODE(22051, 20, node20)
    }
    if (noInit == true) {
        return node20;
    }
    auto node145 = GET_SKILL_NODE(145, PhaseNode_OffsetCalculate);
    if (node145 != nullptr) node20->setPosX(node145->getOutPosX());
    if (node145 != nullptr) node20->setPosY(node145->getOutPosY());
    if (node145 != nullptr) node20->setPosZ(node145->getOutPosZ());
    if (node145 != nullptr) node20->setRotation(node145->getOutRotation());
    return node20;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(22051, 37) {
}

REGISTER_CREATE_SKILL_NODE(22051, 37) {
    auto node37 = GET_SKILL_NODE(37, PhaseNode_EndPhase);
    if (node37 == nullptr) {
        node37 = new PhaseNode_EndPhase(37, phase);
        node37->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node37->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(22051, 37, node37)
    }
    if (noInit == true) {
        return node37;
    }
    return node37;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(22051, 45) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_Detect::TRIGGER_ON, 47, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(22051, 45) {
    auto node45 = GET_SKILL_NODE(45, PhaseNode_Detect);
    if (node45 == nullptr) {
        node45 = new PhaseNode_Detect(45, phase);
        node45->setSelf(0U);
        node45->setEvent("");
        node45->setType(PhaseNode_Detect::Detect_Type::Actor_Dead);
        node45->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(22051, 45, node45)
    }
    if (noInit == true) {
        return node45;
    }
    return node45;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(22051, 47) {
}

REGISTER_CREATE_SKILL_NODE(22051, 47) {
    auto node47 = GET_SKILL_NODE(47, PhaseNode_EndPhase);
    if (node47 == nullptr) {
        node47 = new PhaseNode_EndPhase(47, phase);
        node47->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node47->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(22051, 47, node47)
    }
    if (noInit == true) {
        return node47;
    }
    return node47;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22051, 68) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_Delay::TRIGGER_DONE, 12, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(22051, 68) {
    auto node68 = GET_SKILL_NODE(68, PhaseNode_Delay);
    if (node68 == nullptr) {
        node68 = new PhaseNode_Delay(68, phase);
        node68->setTime(.80f);
        CALL_REGISTER_SKILL_NODE(22051, 68, node68)
    }
    if (noInit == true) {
        return node68;
    }
    return node68;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(22051, 119) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 131, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 133, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(22051, 119) {
    auto node119 = GET_SKILL_NODE(119, PhaseNode_CreateTriggerNewPene);
    if (node119 == nullptr) {
        node119 = new PhaseNode_CreateTriggerNewPene(119, phase);
        node119->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::In);
        node119->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node119->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Enemy);
        node119->setOnHero(true);
        node119->setOnMinion(true);
        node119->setOnDestruct(false);
        node119->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(22051, 119, node119)
    }
    if (noInit == true) {
        return node119;
    }
    auto node20 = GET_SKILL_NODE(20, PhaseNode_SpawnCollider);
    if (node20 != nullptr) node119->setColliderID(node20->getColliderID());
    return node119;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(22051, 120) {
}

REGISTER_CREATE_SKILL_NODE(22051, 120) {
    auto node120 = GET_SKILL_NODE(120, PhaseNode_TriggerCheck);
    if (node120 == nullptr) {
        node120 = new PhaseNode_TriggerCheck(120, phase);
        auto node4 = GET_SKILL_NODE(4, PhaseNode_TriggerUpdate);
        if (node4 != nullptr) node4->addTriggerCheck(node120);
        
        CALL_REGISTER_SKILL_NODE(22051, 120, node120)
    }
    if (noInit == true) {
        return node120;
    }
    auto node129 = GET_SKILL_NODE(129, PhaseNode_CreateTriggerNewPene);
    if (node129 != nullptr) node120->setTrigger(0, node129->getTriggerID());
    return node120;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(22051, 121) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 122, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(22051, 121) {
    auto node121 = GET_SKILL_NODE(121, PhaseNode_ActorFilterNewPene);
    if (node121 == nullptr) {
        node121 = new PhaseNode_ActorFilterNewPene(121, phase);
        node121->setHero(true);
        node121->setMinion(true);
        node121->setDestruct(false);
        node121->setShield(false);
        node121->setTotalCount(0);
        node121->setPerCount(1);
        CALL_REGISTER_SKILL_NODE(22051, 121, node121)
    }
    if (noInit == true) {
        return node121;
    }
    auto node125 = GET_SKILL_NODE(125, PhaseNode_CreateTriggerNewPene);
    if (node125 != nullptr) node121->setInput(node125->getOther());
    return node121;
}
//--------------------------------------------------------------------------------
// GetActorAttribute
//
REGISTER_REGISTER_SKILL_NODE(22051, 122) {
    pnode->resizeTrigger(PhaseNode_GetActorAttribute::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 123, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 136, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 137, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 138, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
}

REGISTER_CREATE_SKILL_NODE(22051, 122) {
    auto node122 = GET_SKILL_NODE(122, PhaseNode_GetActorAttribute);
    if (node122 == nullptr) {
        node122 = new PhaseNode_GetActorAttribute(122, phase);
        node122->setTarget(0U);
        node122->setType({202});
        CALL_REGISTER_SKILL_NODE(22051, 122, node122)
    }
    if (noInit == true) {
        return node122;
    }
    return node122;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(22051, 123) {
}

REGISTER_CREATE_SKILL_NODE(22051, 123) {
    auto node123 = GET_SKILL_NODE(123, PhaseNode_AddSkillBuffs);
    if (node123 == nullptr) {
        node123 = new PhaseNode_AddSkillBuffs(123, phase);
        node123->setConfigID({13,220622});
        CALL_REGISTER_SKILL_NODE(22051, 123, node123)
    }
    if (noInit == true) {
        return node123;
    }
    auto node121 = GET_SKILL_NODE(121, PhaseNode_ActorFilterNewPene);
    auto node122 = GET_SKILL_NODE(122, PhaseNode_GetActorAttribute);
    if (node121 != nullptr) node123->setTarget(node121->getOutput());
    if (node122 != nullptr) node123->setAttribute(node122->getAttribute());
    return node123;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(22051, 124) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 119, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_LESS, 125, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
}

REGISTER_CREATE_SKILL_NODE(22051, 124) {
    auto node124 = GET_SKILL_NODE(124, PhaseNode_CompareFloat);
    if (node124 == nullptr) {
        node124 = new PhaseNode_CompareFloat(124, phase);
        node124->setA(.00f);
        node124->setB(.00f);
        CALL_REGISTER_SKILL_NODE(22051, 124, node124)
    }
    if (noInit == true) {
        return node124;
    }
    return node124;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(22051, 125) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 130, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 121, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(22051, 125) {
    auto node125 = GET_SKILL_NODE(125, PhaseNode_CreateTriggerNewPene);
    if (node125 == nullptr) {
        node125 = new PhaseNode_CreateTriggerNewPene(125, phase);
        node125->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::Tick);
        node125->setTypeParams(0, .00f);
        node125->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node125->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Enemy);
        node125->setOnHero(true);
        node125->setOnMinion(true);
        node125->setOnDestruct(false);
        node125->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(22051, 125, node125)
    }
    if (noInit == true) {
        return node125;
    }
    auto node20 = GET_SKILL_NODE(20, PhaseNode_SpawnCollider);
    if (node20 != nullptr) node125->setColliderID(node20->getColliderID());
    return node125;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(22051, 126) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_If::TRIGGER_FALSE, 127, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_If::TRIGGER_TRUE, 124, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(22051, 126) {
    auto node126 = GET_SKILL_NODE(126, PhaseNode_If);
    if (node126 == nullptr) {
        node126 = new PhaseNode_If(126, phase);
        node126->setCondition(true);
        CALL_REGISTER_SKILL_NODE(22051, 126, node126)
    }
    if (noInit == true) {
        return node126;
    }
    return node126;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(22051, 127) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 129, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_LESS, 128, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
}

REGISTER_CREATE_SKILL_NODE(22051, 127) {
    auto node127 = GET_SKILL_NODE(127, PhaseNode_CompareFloat);
    if (node127 == nullptr) {
        node127 = new PhaseNode_CompareFloat(127, phase);
        node127->setA(.00f);
        node127->setB(.00f);
        CALL_REGISTER_SKILL_NODE(22051, 127, node127)
    }
    if (noInit == true) {
        return node127;
    }
    return node127;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(22051, 128) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 132, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 134, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(22051, 128) {
    auto node128 = GET_SKILL_NODE(128, PhaseNode_CreateTriggerNewPene);
    if (node128 == nullptr) {
        node128 = new PhaseNode_CreateTriggerNewPene(128, phase);
        node128->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::Tick);
        node128->setTypeParams(0, .00f);
        node128->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node128->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Friend);
        node128->setOnHero(true);
        node128->setOnMinion(true);
        node128->setOnDestruct(false);
        node128->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(22051, 128, node128)
    }
    if (noInit == true) {
        return node128;
    }
    auto node20 = GET_SKILL_NODE(20, PhaseNode_SpawnCollider);
    if (node20 != nullptr) node128->setColliderID(node20->getColliderID());
    return node128;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(22051, 129) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 120, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 135, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(22051, 129) {
    auto node129 = GET_SKILL_NODE(129, PhaseNode_CreateTriggerNewPene);
    if (node129 == nullptr) {
        node129 = new PhaseNode_CreateTriggerNewPene(129, phase);
        node129->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::In);
        node129->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node129->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Friend);
        node129->setOnHero(true);
        node129->setOnMinion(true);
        node129->setOnDestruct(false);
        node129->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(22051, 129, node129)
    }
    if (noInit == true) {
        return node129;
    }
    auto node20 = GET_SKILL_NODE(20, PhaseNode_SpawnCollider);
    if (node20 != nullptr) node129->setColliderID(node20->getColliderID());
    return node129;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(22051, 130) {
}

REGISTER_CREATE_SKILL_NODE(22051, 130) {
    auto node130 = GET_SKILL_NODE(130, PhaseNode_TriggerCheck);
    if (node130 == nullptr) {
        node130 = new PhaseNode_TriggerCheck(130, phase);
        auto node4 = GET_SKILL_NODE(4, PhaseNode_TriggerUpdate);
        if (node4 != nullptr) node4->addTriggerCheck(node130);
        
        CALL_REGISTER_SKILL_NODE(22051, 130, node130)
    }
    if (noInit == true) {
        return node130;
    }
    auto node125 = GET_SKILL_NODE(125, PhaseNode_CreateTriggerNewPene);
    if (node125 != nullptr) node130->setTrigger(0, node125->getTriggerID());
    return node130;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(22051, 131) {
}

REGISTER_CREATE_SKILL_NODE(22051, 131) {
    auto node131 = GET_SKILL_NODE(131, PhaseNode_TriggerCheck);
    if (node131 == nullptr) {
        node131 = new PhaseNode_TriggerCheck(131, phase);
        auto node4 = GET_SKILL_NODE(4, PhaseNode_TriggerUpdate);
        if (node4 != nullptr) node4->addTriggerCheck(node131);
        
        CALL_REGISTER_SKILL_NODE(22051, 131, node131)
    }
    if (noInit == true) {
        return node131;
    }
    auto node119 = GET_SKILL_NODE(119, PhaseNode_CreateTriggerNewPene);
    if (node119 != nullptr) node131->setTrigger(0, node119->getTriggerID());
    return node131;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(22051, 132) {
}

REGISTER_CREATE_SKILL_NODE(22051, 132) {
    auto node132 = GET_SKILL_NODE(132, PhaseNode_TriggerCheck);
    if (node132 == nullptr) {
        node132 = new PhaseNode_TriggerCheck(132, phase);
        auto node4 = GET_SKILL_NODE(4, PhaseNode_TriggerUpdate);
        if (node4 != nullptr) node4->addTriggerCheck(node132);
        
        CALL_REGISTER_SKILL_NODE(22051, 132, node132)
    }
    if (noInit == true) {
        return node132;
    }
    auto node128 = GET_SKILL_NODE(128, PhaseNode_CreateTriggerNewPene);
    if (node128 != nullptr) node132->setTrigger(0, node128->getTriggerID());
    return node132;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(22051, 133) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 122, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(22051, 133) {
    auto node133 = GET_SKILL_NODE(133, PhaseNode_ActorFilterNewPene);
    if (node133 == nullptr) {
        node133 = new PhaseNode_ActorFilterNewPene(133, phase);
        node133->setHero(true);
        node133->setMinion(true);
        node133->setDestruct(false);
        node133->setShield(false);
        node133->setTotalCount(0);
        node133->setPerCount(1);
        CALL_REGISTER_SKILL_NODE(22051, 133, node133)
    }
    if (noInit == true) {
        return node133;
    }
    auto node119 = GET_SKILL_NODE(119, PhaseNode_CreateTriggerNewPene);
    if (node119 != nullptr) node133->setInput(node119->getOther());
    return node133;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(22051, 134) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 122, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(22051, 134) {
    auto node134 = GET_SKILL_NODE(134, PhaseNode_ActorFilterNewPene);
    if (node134 == nullptr) {
        node134 = new PhaseNode_ActorFilterNewPene(134, phase);
        node134->setHero(true);
        node134->setMinion(true);
        node134->setDestruct(false);
        node134->setShield(false);
        node134->setTotalCount(0);
        node134->setPerCount(1);
        CALL_REGISTER_SKILL_NODE(22051, 134, node134)
    }
    if (noInit == true) {
        return node134;
    }
    auto node128 = GET_SKILL_NODE(128, PhaseNode_CreateTriggerNewPene);
    if (node128 != nullptr) node134->setInput(node128->getOther());
    return node134;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(22051, 135) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 122, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(22051, 135) {
    auto node135 = GET_SKILL_NODE(135, PhaseNode_ActorFilterNewPene);
    if (node135 == nullptr) {
        node135 = new PhaseNode_ActorFilterNewPene(135, phase);
        node135->setHero(true);
        node135->setMinion(true);
        node135->setDestruct(false);
        node135->setShield(false);
        node135->setTotalCount(0);
        node135->setPerCount(1);
        CALL_REGISTER_SKILL_NODE(22051, 135, node135)
    }
    if (noInit == true) {
        return node135;
    }
    auto node129 = GET_SKILL_NODE(129, PhaseNode_CreateTriggerNewPene);
    if (node129 != nullptr) node135->setInput(node129->getOther());
    return node135;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(22051, 136) {
}

REGISTER_CREATE_SKILL_NODE(22051, 136) {
    auto node136 = GET_SKILL_NODE(136, PhaseNode_AddSkillBuffs);
    if (node136 == nullptr) {
        node136 = new PhaseNode_AddSkillBuffs(136, phase);
        node136->setConfigID({13,220622});
        CALL_REGISTER_SKILL_NODE(22051, 136, node136)
    }
    if (noInit == true) {
        return node136;
    }
    auto node133 = GET_SKILL_NODE(133, PhaseNode_ActorFilterNewPene);
    auto node122 = GET_SKILL_NODE(122, PhaseNode_GetActorAttribute);
    if (node133 != nullptr) node136->setTarget(node133->getOutput());
    if (node122 != nullptr) node136->setAttribute(node122->getAttribute());
    return node136;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(22051, 137) {
}

REGISTER_CREATE_SKILL_NODE(22051, 137) {
    auto node137 = GET_SKILL_NODE(137, PhaseNode_AddSkillBuffs);
    if (node137 == nullptr) {
        node137 = new PhaseNode_AddSkillBuffs(137, phase);
        node137->setConfigID({13,220622});
        CALL_REGISTER_SKILL_NODE(22051, 137, node137)
    }
    if (noInit == true) {
        return node137;
    }
    auto node134 = GET_SKILL_NODE(134, PhaseNode_ActorFilterNewPene);
    auto node122 = GET_SKILL_NODE(122, PhaseNode_GetActorAttribute);
    if (node134 != nullptr) node137->setTarget(node134->getOutput());
    if (node122 != nullptr) node137->setAttribute(node122->getAttribute());
    return node137;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(22051, 138) {
}

REGISTER_CREATE_SKILL_NODE(22051, 138) {
    auto node138 = GET_SKILL_NODE(138, PhaseNode_AddSkillBuffs);
    if (node138 == nullptr) {
        node138 = new PhaseNode_AddSkillBuffs(138, phase);
        node138->setConfigID({13,220622});
        CALL_REGISTER_SKILL_NODE(22051, 138, node138)
    }
    if (noInit == true) {
        return node138;
    }
    auto node135 = GET_SKILL_NODE(135, PhaseNode_ActorFilterNewPene);
    auto node122 = GET_SKILL_NODE(122, PhaseNode_GetActorAttribute);
    if (node135 != nullptr) node138->setTarget(node135->getOutput());
    if (node122 != nullptr) node138->setAttribute(node122->getAttribute());
    return node138;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(22051, 139) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_ResetCD::TRIGGER_DONE, 140, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(22051, 139) {
    auto node139 = GET_SKILL_NODE(139, PhaseNode_ResetCD);
    if (node139 == nullptr) {
        node139 = new PhaseNode_ResetCD(139, phase);
        node139->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node139->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node139->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(22051, 139, node139)
    }
    if (noInit == true) {
        return node139;
    }
    return node139;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(22051, 140) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_PlayAnimation::TRIGGER_DONE, 141, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(22051, 140) {
    auto node140 = GET_SKILL_NODE(140, PhaseNode_PlayAnimation);
    if (node140 == nullptr) {
        node140 = new PhaseNode_PlayAnimation(140, phase);
        node140->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node140->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node140->setTarget(0U);
        node140->setAnimation("Skill1S2");
        node140->setParameter("");
        node140->setValue(false);
        CALL_REGISTER_SKILL_NODE(22051, 140, node140)
    }
    if (noInit == true) {
        return node140;
    }
    return node140;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(22051, 141) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlaySound::TRIGGER_DONE, 142, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(22051, 141) {
    auto node141 = GET_SKILL_NODE(141, PhaseNode_PlaySound);
    if (node141 == nullptr) {
        node141 = new PhaseNode_PlaySound(141, phase);
        node141->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node141->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node141->setSoundID("VO_MON2206_ATK");
        node141->setTarget(0U);
        node141->setUsePos(false);
        node141->setPosX(.00f);
        node141->setPosY(.00f);
        node141->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(22051, 141, node141)
    }
    if (noInit == true) {
        return node141;
    }
    return node141;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22051, 142) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_Delay::TRIGGER_DONE, 143, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(22051, 142) {
    auto node142 = GET_SKILL_NODE(142, PhaseNode_Delay);
    if (node142 == nullptr) {
        node142 = new PhaseNode_Delay(142, phase);
        node142->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(22051, 142, node142)
    }
    if (noInit == true) {
        return node142;
    }
    return node142;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(22051, 143) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetRotation>(PhaseNode_GetLocation::TRIGGER_DONE, 144, PhaseNode_GetRotation::FUNC_DO, &PhaseNode_GetRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(22051, 143) {
    auto node143 = GET_SKILL_NODE(143, PhaseNode_GetLocation);
    if (node143 == nullptr) {
        node143 = new PhaseNode_GetLocation(143, phase);
        node143->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node143->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(22051, 143, node143)
    }
    if (noInit == true) {
        return node143;
    }
    return node143;
}
//--------------------------------------------------------------------------------
// GetRotation
//
REGISTER_REGISTER_SKILL_NODE(22051, 144) {
    pnode->resizeTrigger(PhaseNode_GetRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_OffsetCalculate>(PhaseNode_GetRotation::TRIGGER_DONE, 145, PhaseNode_OffsetCalculate::FUNC_DO, &PhaseNode_OffsetCalculate::Do);
}

REGISTER_CREATE_SKILL_NODE(22051, 144) {
    auto node144 = GET_SKILL_NODE(144, PhaseNode_GetRotation);
    if (node144 == nullptr) {
        node144 = new PhaseNode_GetRotation(144, phase);
        node144->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node144->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(22051, 144, node144)
    }
    if (noInit == true) {
        return node144;
    }
    return node144;
}
//--------------------------------------------------------------------------------
// OffsetCalculate
//
REGISTER_REGISTER_SKILL_NODE(22051, 145) {
    pnode->resizeTrigger(PhaseNode_OffsetCalculate::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 147, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(22051, 145) {
    auto node145 = GET_SKILL_NODE(145, PhaseNode_OffsetCalculate);
    if (node145 == nullptr) {
        node145 = new PhaseNode_OffsetCalculate(145, phase);
        node145->setPosZ(.00f);
        node145->setOffsetX(.00f);
        node145->setOffsetY(3.00f);
        node145->setOffsetZ(.00f);
        node145->setRotOffset(.00f);
        CALL_REGISTER_SKILL_NODE(22051, 145, node145)
    }
    if (noInit == true) {
        return node145;
    }
    auto node143 = GET_SKILL_NODE(143, PhaseNode_GetLocation);
    auto node144 = GET_SKILL_NODE(144, PhaseNode_GetRotation);
    if (node143 != nullptr) node145->setPosX(node143->getX());
    if (node143 != nullptr) node145->setPosY(node143->getY());
    if (node144 != nullptr) node145->setRotation(node144->getAngle());
    return node145;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(22051, 146) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_PlayEffect::TRIGGER_DONE, 149, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(22051, 146) {
    auto node146 = GET_SKILL_NODE(146, PhaseNode_PlayEffect);
    if (node146 == nullptr) {
        node146 = new PhaseNode_PlayEffect(146, phase);
        node146->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node146->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node146->setEffectID(1014);
        node146->setChangeColor(false);
        node146->setType(PhaseNode_PlayEffect::PlayEffect_Type::WithTarget);
        node146->getVars().reserve(5);
        node146->getVars().setVariable<uint64_t>(0, 0U);
        node146->getVars().setVariable<std::string>(1, "");
        node146->getVars().setVariable<float>(2, .00f);
        node146->getVars().setVariable<float>(3, .00f);
        node146->getVars().setVariable<float>(4, .20f);
        node146->setScale(1.50f);
        CALL_REGISTER_SKILL_NODE(22051, 146, node146)
    }
    if (noInit == true) {
        return node146;
    }
    auto node145 = GET_SKILL_NODE(145, PhaseNode_OffsetCalculate);
    if (node145 != nullptr) node146->getVars().setVariable<float>(2, node145->getOutPosX());
    if (node145 != nullptr) node146->getVars().setVariable<float>(3, node145->getOutPosY());
    if (node145 != nullptr) node146->setRotation(node145->getOutRotation());
    return node146;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(22051, 147) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_FALSE, 148, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_TRUE, 146, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(22051, 147) {
    auto node147 = GET_SKILL_NODE(147, PhaseNode_If);
    if (node147 == nullptr) {
        node147 = new PhaseNode_If(147, phase);
        node147->setCondition(false);
        CALL_REGISTER_SKILL_NODE(22051, 147, node147)
    }
    if (noInit == true) {
        return node147;
    }
    return node147;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(22051, 148) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_PlayEffect::TRIGGER_DONE, 149, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(22051, 148) {
    auto node148 = GET_SKILL_NODE(148, PhaseNode_PlayEffect);
    if (node148 == nullptr) {
        node148 = new PhaseNode_PlayEffect(148, phase);
        node148->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node148->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node148->setEffectID(1014);
        node148->setChangeColor(false);
        node148->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node148->getVars().reserve(3);
        node148->getVars().setVariable<float>(0, .00f);
        node148->getVars().setVariable<float>(1, .00f);
        node148->getVars().setVariable<float>(2, .20f);
        node148->setScale(1.50f);
        CALL_REGISTER_SKILL_NODE(22051, 148, node148)
    }
    if (noInit == true) {
        return node148;
    }
    auto node145 = GET_SKILL_NODE(145, PhaseNode_OffsetCalculate);
    if (node145 != nullptr) node148->getVars().setVariable<float>(0, node145->getOutPosX());
    if (node145 != nullptr) node148->getVars().setVariable<float>(1, node145->getOutPosY());
    if (node145 != nullptr) node148->setRotation(node145->getOutRotation());
    return node148;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(22051, 149) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 68, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_LESS, 150, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_LESS, 68, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(22051, 149) {
    auto node149 = GET_SKILL_NODE(149, PhaseNode_CompareFloat);
    if (node149 == nullptr) {
        node149 = new PhaseNode_CompareFloat(149, phase);
        node149->setA(.00f);
        node149->setB(1.45f);
        CALL_REGISTER_SKILL_NODE(22051, 149, node149)
    }
    if (noInit == true) {
        return node149;
    }
    return node149;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22051, 150) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StopEffect>(PhaseNode_Delay::TRIGGER_DONE, 151, PhaseNode_StopEffect::FUNC_DO, &PhaseNode_StopEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(22051, 150) {
    auto node150 = GET_SKILL_NODE(150, PhaseNode_Delay);
    if (node150 == nullptr) {
        node150 = new PhaseNode_Delay(150, phase);
        node150->setTime(1.45f);
        CALL_REGISTER_SKILL_NODE(22051, 150, node150)
    }
    if (noInit == true) {
        return node150;
    }
    return node150;
}
//--------------------------------------------------------------------------------
// StopEffect
//
REGISTER_REGISTER_SKILL_NODE(22051, 151) {
}

REGISTER_CREATE_SKILL_NODE(22051, 151) {
    auto node151 = GET_SKILL_NODE(151, PhaseNode_StopEffect);
    if (node151 == nullptr) {
        node151 = new PhaseNode_StopEffect(151, phase);
        node151->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node151->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node151->setEffectID(1014);
        CALL_REGISTER_SKILL_NODE(22051, 151, node151)
    }
    if (noInit == true) {
        return node151;
    }
    return node151;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(22051, 152) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetRotation>(PhaseNode_GetLocation::TRIGGER_DONE, 153, PhaseNode_GetRotation::FUNC_DO, &PhaseNode_GetRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(22051, 152) {
    auto node152 = GET_SKILL_NODE(152, PhaseNode_GetLocation);
    if (node152 == nullptr) {
        node152 = new PhaseNode_GetLocation(152, phase);
        node152->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node152->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(22051, 152, node152)
    }
    if (noInit == true) {
        return node152;
    }
    return node152;
}
//--------------------------------------------------------------------------------
// GetRotation
//
REGISTER_REGISTER_SKILL_NODE(22051, 153) {
    pnode->resizeTrigger(PhaseNode_GetRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_OffsetCalculate>(PhaseNode_GetRotation::TRIGGER_DONE, 154, PhaseNode_OffsetCalculate::FUNC_DO, &PhaseNode_OffsetCalculate::Do);
}

REGISTER_CREATE_SKILL_NODE(22051, 153) {
    auto node153 = GET_SKILL_NODE(153, PhaseNode_GetRotation);
    if (node153 == nullptr) {
        node153 = new PhaseNode_GetRotation(153, phase);
        node153->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node153->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(22051, 153, node153)
    }
    if (noInit == true) {
        return node153;
    }
    return node153;
}
//--------------------------------------------------------------------------------
// OffsetCalculate
//
REGISTER_REGISTER_SKILL_NODE(22051, 154) {
    pnode->resizeTrigger(PhaseNode_OffsetCalculate::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 156, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(22051, 154) {
    auto node154 = GET_SKILL_NODE(154, PhaseNode_OffsetCalculate);
    if (node154 == nullptr) {
        node154 = new PhaseNode_OffsetCalculate(154, phase);
        node154->setPosZ(.00f);
        node154->setOffsetX(.00f);
        node154->setOffsetY(.00f);
        node154->setOffsetZ(.00f);
        node154->setRotOffset(.00f);
        CALL_REGISTER_SKILL_NODE(22051, 154, node154)
    }
    if (noInit == true) {
        return node154;
    }
    auto node152 = GET_SKILL_NODE(152, PhaseNode_GetLocation);
    auto node153 = GET_SKILL_NODE(153, PhaseNode_GetRotation);
    if (node152 != nullptr) node154->setPosX(node152->getX());
    if (node152 != nullptr) node154->setPosY(node152->getY());
    if (node153 != nullptr) node154->setRotation(node153->getAngle());
    return node154;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(22051, 155) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_PlayEffect::TRIGGER_DONE, 158, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(22051, 155) {
    auto node155 = GET_SKILL_NODE(155, PhaseNode_PlayEffect);
    if (node155 == nullptr) {
        node155 = new PhaseNode_PlayEffect(155, phase);
        node155->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node155->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node155->setEffectID(220611);
        node155->setChangeColor(false);
        node155->setType(PhaseNode_PlayEffect::PlayEffect_Type::WithTarget);
        node155->getVars().reserve(5);
        node155->getVars().setVariable<uint64_t>(0, 0U);
        node155->getVars().setVariable<std::string>(1, "");
        node155->getVars().setVariable<float>(2, .00f);
        node155->getVars().setVariable<float>(3, .00f);
        node155->getVars().setVariable<float>(4, .00f);
        node155->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(22051, 155, node155)
    }
    if (noInit == true) {
        return node155;
    }
    auto node154 = GET_SKILL_NODE(154, PhaseNode_OffsetCalculate);
    if (node154 != nullptr) node155->getVars().setVariable<float>(2, node154->getOutPosX());
    if (node154 != nullptr) node155->getVars().setVariable<float>(3, node154->getOutPosY());
    if (node154 != nullptr) node155->getVars().setVariable<float>(4, node154->getOutPosZ());
    if (node154 != nullptr) node155->setRotation(node154->getOutRotation());
    return node155;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(22051, 156) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_FALSE, 157, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_TRUE, 155, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(22051, 156) {
    auto node156 = GET_SKILL_NODE(156, PhaseNode_If);
    if (node156 == nullptr) {
        node156 = new PhaseNode_If(156, phase);
        node156->setCondition(false);
        CALL_REGISTER_SKILL_NODE(22051, 156, node156)
    }
    if (noInit == true) {
        return node156;
    }
    return node156;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(22051, 157) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_PlayEffect::TRIGGER_DONE, 158, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(22051, 157) {
    auto node157 = GET_SKILL_NODE(157, PhaseNode_PlayEffect);
    if (node157 == nullptr) {
        node157 = new PhaseNode_PlayEffect(157, phase);
        node157->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node157->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node157->setEffectID(220611);
        node157->setChangeColor(false);
        node157->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node157->getVars().reserve(3);
        node157->getVars().setVariable<float>(0, .00f);
        node157->getVars().setVariable<float>(1, .00f);
        node157->getVars().setVariable<float>(2, .00f);
        node157->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(22051, 157, node157)
    }
    if (noInit == true) {
        return node157;
    }
    auto node154 = GET_SKILL_NODE(154, PhaseNode_OffsetCalculate);
    if (node154 != nullptr) node157->getVars().setVariable<float>(0, node154->getOutPosX());
    if (node154 != nullptr) node157->getVars().setVariable<float>(1, node154->getOutPosY());
    if (node154 != nullptr) node157->getVars().setVariable<float>(2, node154->getOutPosZ());
    if (node154 != nullptr) node157->setRotation(node154->getOutRotation());
    return node157;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(22051, 158) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 14, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_LESS, 14, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_LESS, 159, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(22051, 158) {
    auto node158 = GET_SKILL_NODE(158, PhaseNode_CompareFloat);
    if (node158 == nullptr) {
        node158 = new PhaseNode_CompareFloat(158, phase);
        node158->setA(.00f);
        node158->setB(.00f);
        CALL_REGISTER_SKILL_NODE(22051, 158, node158)
    }
    if (noInit == true) {
        return node158;
    }
    return node158;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22051, 159) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StopEffect>(PhaseNode_Delay::TRIGGER_DONE, 160, PhaseNode_StopEffect::FUNC_DO, &PhaseNode_StopEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(22051, 159) {
    auto node159 = GET_SKILL_NODE(159, PhaseNode_Delay);
    if (node159 == nullptr) {
        node159 = new PhaseNode_Delay(159, phase);
        node159->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(22051, 159, node159)
    }
    if (noInit == true) {
        return node159;
    }
    return node159;
}
//--------------------------------------------------------------------------------
// StopEffect
//
REGISTER_REGISTER_SKILL_NODE(22051, 160) {
}

REGISTER_CREATE_SKILL_NODE(22051, 160) {
    auto node160 = GET_SKILL_NODE(160, PhaseNode_StopEffect);
    if (node160 == nullptr) {
        node160 = new PhaseNode_StopEffect(160, phase);
        node160->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node160->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node160->setEffectID(220611);
        CALL_REGISTER_SKILL_NODE(22051, 160, node160)
    }
    if (noInit == true) {
        return node160;
    }
    return node160;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22051, 161) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_Delay::TRIGGER_DONE, 163, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(22051, 161) {
    auto node161 = GET_SKILL_NODE(161, PhaseNode_Delay);
    if (node161 == nullptr) {
        node161 = new PhaseNode_Delay(161, phase);
        node161->setTime(1.00f);
        CALL_REGISTER_SKILL_NODE(22051, 161, node161)
    }
    if (noInit == true) {
        return node161;
    }
    return node161;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(22051, 162) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 37, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(22051, 162) {
    auto node162 = GET_SKILL_NODE(162, PhaseNode_SkillEndNotify);
    if (node162 == nullptr) {
        node162 = new PhaseNode_SkillEndNotify(162, phase);
        node162->setReturnType(false);
        CALL_REGISTER_SKILL_NODE(22051, 162, node162)
    }
    if (noInit == true) {
        return node162;
    }
    return node162;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(22051, 163) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_FALSE, 164, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_TRUE, 162, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
}

REGISTER_CREATE_SKILL_NODE(22051, 163) {
    auto node163 = GET_SKILL_NODE(163, PhaseNode_If);
    if (node163 == nullptr) {
        node163 = new PhaseNode_If(163, phase);
        node163->setCondition(false);
        CALL_REGISTER_SKILL_NODE(22051, 163, node163)
    }
    if (noInit == true) {
        return node163;
    }
    return node163;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(22051, 164) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 37, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(22051, 164) {
    auto node164 = GET_SKILL_NODE(164, PhaseNode_SkillEndNotify);
    if (node164 == nullptr) {
        node164 = new PhaseNode_SkillEndNotify(164, phase);
        node164->setReturnType(true);
        CALL_REGISTER_SKILL_NODE(22051, 164, node164)
    }
    if (noInit == true) {
        return node164;
    }
    return node164;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(22051, 165) {
}

REGISTER_CREATE_SKILL_NODE(22051, 165) {
    auto node165 = GET_SKILL_NODE(165, PhaseNode_RaiseEvent);
    if (node165 == nullptr) {
        node165 = new PhaseNode_RaiseEvent(165, phase);
        node165->setEvent("MonsterInterrupt");
        node165->setTarget(0U);
        node165->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node165->setTypeParams(0, 0);
        node165->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(22051, 165, node165)
    }
    if (noInit == true) {
        return node165;
    }
    return node165;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(22051, 166) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_Detect::TRIGGER_ON, 171, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(22051, 166) {
    auto node166 = GET_SKILL_NODE(166, PhaseNode_Detect);
    if (node166 == nullptr) {
        node166 = new PhaseNode_Detect(166, phase);
        node166->setSelf(0U);
        node166->setEvent("MonsterInterrupt");
        node166->setType(PhaseNode_Detect::Detect_Type::Interrupt_Skill);
        node166->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(22051, 166, node166)
    }
    if (noInit == true) {
        return node166;
    }
    return node166;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(22051, 167) {
}

REGISTER_CREATE_SKILL_NODE(22051, 167) {
    auto node167 = GET_SKILL_NODE(167, PhaseNode_EndPhase);
    if (node167 == nullptr) {
        node167 = new PhaseNode_EndPhase(167, phase);
        node167->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node167->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(22051, 167, node167)
    }
    if (noInit == true) {
        return node167;
    }
    return node167;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22051, 169) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_Delay::TRIGGER_DONE, 170, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(22051, 169) {
    auto node169 = GET_SKILL_NODE(169, PhaseNode_Delay);
    if (node169 == nullptr) {
        node169 = new PhaseNode_Delay(169, phase);
        node169->setTime(1.20f);
        CALL_REGISTER_SKILL_NODE(22051, 169, node169)
    }
    if (noInit == true) {
        return node169;
    }
    return node169;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(22051, 170) {
}

REGISTER_CREATE_SKILL_NODE(22051, 170) {
    auto node170 = GET_SKILL_NODE(170, PhaseNode_PlaySound);
    if (node170 == nullptr) {
        node170 = new PhaseNode_PlaySound(170, phase);
        node170->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node170->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node170->setSoundID("SE_MON2206_ATK_B");
        node170->setTarget(0U);
        node170->setUsePos(false);
        node170->setPosX(.00f);
        node170->setPosY(.00f);
        node170->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(22051, 170, node170)
    }
    if (noInit == true) {
        return node170;
    }
    return node170;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22051, 171) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_Delay::TRIGGER_DONE, 173, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(22051, 171) {
    auto node171 = GET_SKILL_NODE(171, PhaseNode_Delay);
    if (node171 == nullptr) {
        node171 = new PhaseNode_Delay(171, phase);
        node171->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(22051, 171, node171)
    }
    if (noInit == true) {
        return node171;
    }
    return node171;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(22051, 172) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 167, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(22051, 172) {
    auto node172 = GET_SKILL_NODE(172, PhaseNode_SkillEndNotify);
    if (node172 == nullptr) {
        node172 = new PhaseNode_SkillEndNotify(172, phase);
        node172->setReturnType(false);
        CALL_REGISTER_SKILL_NODE(22051, 172, node172)
    }
    if (noInit == true) {
        return node172;
    }
    return node172;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(22051, 173) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_FALSE, 174, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_TRUE, 172, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
}

REGISTER_CREATE_SKILL_NODE(22051, 173) {
    auto node173 = GET_SKILL_NODE(173, PhaseNode_If);
    if (node173 == nullptr) {
        node173 = new PhaseNode_If(173, phase);
        node173->setCondition(false);
        CALL_REGISTER_SKILL_NODE(22051, 173, node173)
    }
    if (noInit == true) {
        return node173;
    }
    return node173;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(22051, 174) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 167, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(22051, 174) {
    auto node174 = GET_SKILL_NODE(174, PhaseNode_SkillEndNotify);
    if (node174 == nullptr) {
        node174 = new PhaseNode_SkillEndNotify(174, phase);
        node174->setReturnType(true);
        CALL_REGISTER_SKILL_NODE(22051, 174, node174)
    }
    if (noInit == true) {
        return node174;
    }
    return node174;
}

//--------------------------------------------------------------------------------
// SkillCreator_22051
//
class SkillCreator_22051 : public SkillCreator {
public:
    SkillCreator_22051() {}
    virtual ~SkillCreator_22051() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_22051

//--------------------------------------------------------------------------------
// SkillPhase_22051
//
class SkillPhase_22051 : public SkillPhase {
public:
    SkillPhase_22051(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_22051() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(22051, 2) // StartPhase
        CASE_CREATE_SKILL_NODE(22051, 4) // TriggerUpdate
        CASE_CREATE_SKILL_NODE(22051, 12) // PlayAnimation
        CASE_CREATE_SKILL_NODE(22051, 14) // Delay
        CASE_CREATE_SKILL_NODE(22051, 20) // SpawnCollider
        CASE_CREATE_SKILL_NODE(22051, 37) // EndPhase
        CASE_CREATE_SKILL_NODE(22051, 45) // Detect
        CASE_CREATE_SKILL_NODE(22051, 47) // EndPhase
        CASE_CREATE_SKILL_NODE(22051, 68) // Delay
        CASE_CREATE_SKILL_NODE(22051, 119) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(22051, 120) // TriggerCheck
        CASE_CREATE_SKILL_NODE(22051, 121) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(22051, 122) // GetActorAttribute
        CASE_CREATE_SKILL_NODE(22051, 123) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(22051, 124) // CompareFloat
        CASE_CREATE_SKILL_NODE(22051, 125) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(22051, 126) // If
        CASE_CREATE_SKILL_NODE(22051, 127) // CompareFloat
        CASE_CREATE_SKILL_NODE(22051, 128) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(22051, 129) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(22051, 130) // TriggerCheck
        CASE_CREATE_SKILL_NODE(22051, 131) // TriggerCheck
        CASE_CREATE_SKILL_NODE(22051, 132) // TriggerCheck
        CASE_CREATE_SKILL_NODE(22051, 133) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(22051, 134) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(22051, 135) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(22051, 136) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(22051, 137) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(22051, 138) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(22051, 139) // ResetCD
        CASE_CREATE_SKILL_NODE(22051, 140) // PlayAnimation
        CASE_CREATE_SKILL_NODE(22051, 141) // PlaySound
        CASE_CREATE_SKILL_NODE(22051, 142) // Delay
        CASE_CREATE_SKILL_NODE(22051, 143) // GetLocation
        CASE_CREATE_SKILL_NODE(22051, 144) // GetRotation
        CASE_CREATE_SKILL_NODE(22051, 145) // OffsetCalculate
        CASE_CREATE_SKILL_NODE(22051, 146) // PlayEffect
        CASE_CREATE_SKILL_NODE(22051, 147) // If
        CASE_CREATE_SKILL_NODE(22051, 148) // PlayEffect
        CASE_CREATE_SKILL_NODE(22051, 149) // CompareFloat
        CASE_CREATE_SKILL_NODE(22051, 150) // Delay
        CASE_CREATE_SKILL_NODE(22051, 151) // StopEffect
        CASE_CREATE_SKILL_NODE(22051, 152) // GetLocation
        CASE_CREATE_SKILL_NODE(22051, 153) // GetRotation
        CASE_CREATE_SKILL_NODE(22051, 154) // OffsetCalculate
        CASE_CREATE_SKILL_NODE(22051, 155) // PlayEffect
        CASE_CREATE_SKILL_NODE(22051, 156) // If
        CASE_CREATE_SKILL_NODE(22051, 157) // PlayEffect
        CASE_CREATE_SKILL_NODE(22051, 158) // CompareFloat
        CASE_CREATE_SKILL_NODE(22051, 159) // Delay
        CASE_CREATE_SKILL_NODE(22051, 160) // StopEffect
        CASE_CREATE_SKILL_NODE(22051, 161) // Delay
        CASE_CREATE_SKILL_NODE(22051, 162) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(22051, 163) // If
        CASE_CREATE_SKILL_NODE(22051, 164) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(22051, 165) // RaiseEvent
        CASE_CREATE_SKILL_NODE(22051, 166) // Detect
        CASE_CREATE_SKILL_NODE(22051, 167) // EndPhase
        CASE_CREATE_SKILL_NODE(22051, 169) // Delay
        CASE_CREATE_SKILL_NODE(22051, 170) // PlaySound
        CASE_CREATE_SKILL_NODE(22051, 171) // Delay
        CASE_CREATE_SKILL_NODE(22051, 172) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(22051, 173) // If
        CASE_CREATE_SKILL_NODE(22051, 174) // SkillEndNotify
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_22051

SkillLogic* SkillCreator_22051::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //创建阶段phase
    auto phase = new SkillPhase_22051(1, logic, 3);
    //设置phase执行器
    phase->setRunPhaseNode(1, 2);
    phase->setRunPhaseNode(2, 4);
    phase->setDetectPhaseNode(3, 45);
    phase->setDetectPhaseNode(3, 166);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_22051::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
