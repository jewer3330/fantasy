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
REGISTER_REGISTER_SKILL_NODE(20031, 1) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_StartPhase::TRIGGER_START, 172, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_StartPhase::TRIGGER_START, 156, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(20031, 1) {
    auto node1 = GET_SKILL_NODE(1, PhaseNode_StartPhase);
    if (node1 == nullptr) {
        node1 = new PhaseNode_StartPhase(1, phase);
        CALL_REGISTER_SKILL_NODE(20031, 1, node1)
    }
    if (noInit == true) {
        return node1;
    }
    return node1;
}
//--------------------------------------------------------------------------------
// TriggerUpdate
//
REGISTER_REGISTER_SKILL_NODE(20031, 5) {
}

REGISTER_CREATE_SKILL_NODE(20031, 5) {
    auto node5 = GET_SKILL_NODE(5, PhaseNode_TriggerUpdate);
    if (node5 == nullptr) {
        node5 = new PhaseNode_TriggerUpdate(5, phase);
        CALL_REGISTER_SKILL_NODE(20031, 5, node5)
    }
    if (noInit == true) {
        return node5;
    }
    return node5;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(20031, 30) {
}

REGISTER_CREATE_SKILL_NODE(20031, 30) {
    auto node30 = GET_SKILL_NODE(30, PhaseNode_EndPhase);
    if (node30 == nullptr) {
        node30 = new PhaseNode_EndPhase(30, phase);
        node30->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node30->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(20031, 30, node30)
    }
    if (noInit == true) {
        return node30;
    }
    return node30;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(20031, 119) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnCollider>(PhaseNode_PlaySound::TRIGGER_DONE, 120, PhaseNode_SpawnCollider::FUNC_DO, &PhaseNode_SpawnCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(20031, 119) {
    auto node119 = GET_SKILL_NODE(119, PhaseNode_PlaySound);
    if (node119 == nullptr) {
        node119 = new PhaseNode_PlaySound(119, phase);
        node119->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node119->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node119->setSoundID("SE_MON_Npc_Zerg_ATK");
        node119->setTarget(0U);
        node119->setUsePos(false);
        node119->setPosX(.00f);
        node119->setPosY(.00f);
        node119->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(20031, 119, node119)
    }
    if (noInit == true) {
        return node119;
    }
    return node119;
}
//--------------------------------------------------------------------------------
// SpawnCollider
//
REGISTER_REGISTER_SKILL_NODE(20031, 120) {
    pnode->resizeTrigger(PhaseNode_SpawnCollider::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_SpawnCollider::TRIGGER_DONE, 129, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_SpawnCollider::TRIGGER_DONE, 140, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(20031, 120) {
    auto node120 = GET_SKILL_NODE(120, PhaseNode_SpawnCollider);
    if (node120 == nullptr) {
        node120 = new PhaseNode_SpawnCollider(120, phase);
        node120->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node120->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node120->setMesh("");
        node120->setMeshScale(.00f);
        node120->setEffectID(0);
        node120->setEffectScale(.00f);
        node120->setType(PhaseNode_SpawnCollider::SpawnCollider_Type::Sector);
        node120->setTypeParams(0, 4.00f);
        node120->setTypeParams(1, 60.00f);
        node120->setTime(.30f);
        node120->setreentry(false);
        node120->setCheckPeneSound(false);
        CALL_REGISTER_SKILL_NODE(20031, 120, node120)
    }
    if (noInit == true) {
        return node120;
    }
    auto node155 = GET_SKILL_NODE(155, PhaseNode_OffsetCalculate);
    if (node155 != nullptr) node120->setPosX(node155->getOutPosX());
    if (node155 != nullptr) node120->setPosY(node155->getOutPosY());
    if (node155 != nullptr) node120->setPosZ(node155->getOutPosZ());
    if (node155 != nullptr) node120->setRotation(node155->getOutRotation());
    return node120;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(20031, 128) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_Delay::TRIGGER_DONE, 119, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(20031, 128) {
    auto node128 = GET_SKILL_NODE(128, PhaseNode_Delay);
    if (node128 == nullptr) {
        node128 = new PhaseNode_Delay(128, phase);
        node128->setTime(.40f);
        CALL_REGISTER_SKILL_NODE(20031, 128, node128)
    }
    if (noInit == true) {
        return node128;
    }
    return node128;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(20031, 129) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_Delay::TRIGGER_DONE, 131, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(20031, 129) {
    auto node129 = GET_SKILL_NODE(129, PhaseNode_Delay);
    if (node129 == nullptr) {
        node129 = new PhaseNode_Delay(129, phase);
        node129->setTime(.40f);
        CALL_REGISTER_SKILL_NODE(20031, 129, node129)
    }
    if (noInit == true) {
        return node129;
    }
    return node129;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(20031, 130) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 30, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(20031, 130) {
    auto node130 = GET_SKILL_NODE(130, PhaseNode_SkillEndNotify);
    if (node130 == nullptr) {
        node130 = new PhaseNode_SkillEndNotify(130, phase);
        node130->setReturnType(false);
        CALL_REGISTER_SKILL_NODE(20031, 130, node130)
    }
    if (noInit == true) {
        return node130;
    }
    return node130;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(20031, 131) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_FALSE, 132, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_TRUE, 130, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
}

REGISTER_CREATE_SKILL_NODE(20031, 131) {
    auto node131 = GET_SKILL_NODE(131, PhaseNode_If);
    if (node131 == nullptr) {
        node131 = new PhaseNode_If(131, phase);
        node131->setCondition(false);
        CALL_REGISTER_SKILL_NODE(20031, 131, node131)
    }
    if (noInit == true) {
        return node131;
    }
    return node131;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(20031, 132) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 30, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(20031, 132) {
    auto node132 = GET_SKILL_NODE(132, PhaseNode_SkillEndNotify);
    if (node132 == nullptr) {
        node132 = new PhaseNode_SkillEndNotify(132, phase);
        node132->setReturnType(true);
        CALL_REGISTER_SKILL_NODE(20031, 132, node132)
    }
    if (noInit == true) {
        return node132;
    }
    return node132;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(20031, 133) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 145, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 147, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(20031, 133) {
    auto node133 = GET_SKILL_NODE(133, PhaseNode_CreateTriggerNewPene);
    if (node133 == nullptr) {
        node133 = new PhaseNode_CreateTriggerNewPene(133, phase);
        node133->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::In);
        node133->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node133->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Enemy);
        node133->setOnHero(true);
        node133->setOnMinion(true);
        node133->setOnDestruct(true);
        node133->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(20031, 133, node133)
    }
    if (noInit == true) {
        return node133;
    }
    auto node120 = GET_SKILL_NODE(120, PhaseNode_SpawnCollider);
    if (node120 != nullptr) node133->setColliderID(node120->getColliderID());
    return node133;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(20031, 134) {
}

REGISTER_CREATE_SKILL_NODE(20031, 134) {
    auto node134 = GET_SKILL_NODE(134, PhaseNode_TriggerCheck);
    if (node134 == nullptr) {
        node134 = new PhaseNode_TriggerCheck(134, phase);
        auto node5 = GET_SKILL_NODE(5, PhaseNode_TriggerUpdate);
        if (node5 != nullptr) node5->addTriggerCheck(node134);
        
        CALL_REGISTER_SKILL_NODE(20031, 134, node134)
    }
    if (noInit == true) {
        return node134;
    }
    auto node143 = GET_SKILL_NODE(143, PhaseNode_CreateTriggerNewPene);
    if (node143 != nullptr) node134->setTrigger(0, node143->getTriggerID());
    return node134;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(20031, 135) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 136, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(20031, 135) {
    auto node135 = GET_SKILL_NODE(135, PhaseNode_ActorFilterNewPene);
    if (node135 == nullptr) {
        node135 = new PhaseNode_ActorFilterNewPene(135, phase);
        node135->setHero(true);
        node135->setMinion(true);
        node135->setDestruct(true);
        node135->setShield(false);
        node135->setTotalCount(0);
        node135->setPerCount(1);
        CALL_REGISTER_SKILL_NODE(20031, 135, node135)
    }
    if (noInit == true) {
        return node135;
    }
    auto node139 = GET_SKILL_NODE(139, PhaseNode_CreateTriggerNewPene);
    if (node139 != nullptr) node135->setInput(node139->getOther());
    return node135;
}
//--------------------------------------------------------------------------------
// GetActorAttribute
//
REGISTER_REGISTER_SKILL_NODE(20031, 136) {
    pnode->resizeTrigger(PhaseNode_GetActorAttribute::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 137, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 150, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 151, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 152, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
}

REGISTER_CREATE_SKILL_NODE(20031, 136) {
    auto node136 = GET_SKILL_NODE(136, PhaseNode_GetActorAttribute);
    if (node136 == nullptr) {
        node136 = new PhaseNode_GetActorAttribute(136, phase);
        node136->setTarget(0U);
        node136->setType({202});
        CALL_REGISTER_SKILL_NODE(20031, 136, node136)
    }
    if (noInit == true) {
        return node136;
    }
    return node136;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(20031, 137) {
}

REGISTER_CREATE_SKILL_NODE(20031, 137) {
    auto node137 = GET_SKILL_NODE(137, PhaseNode_AddSkillBuffs);
    if (node137 == nullptr) {
        node137 = new PhaseNode_AddSkillBuffs(137, phase);
        node137->setConfigID({11});
        CALL_REGISTER_SKILL_NODE(20031, 137, node137)
    }
    if (noInit == true) {
        return node137;
    }
    auto node135 = GET_SKILL_NODE(135, PhaseNode_ActorFilterNewPene);
    auto node136 = GET_SKILL_NODE(136, PhaseNode_GetActorAttribute);
    if (node135 != nullptr) node137->setTarget(node135->getOutput());
    if (node136 != nullptr) node137->setAttribute(node136->getAttribute());
    return node137;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(20031, 138) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 133, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_LESS, 139, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
}

REGISTER_CREATE_SKILL_NODE(20031, 138) {
    auto node138 = GET_SKILL_NODE(138, PhaseNode_CompareFloat);
    if (node138 == nullptr) {
        node138 = new PhaseNode_CompareFloat(138, phase);
        node138->setA(.00f);
        node138->setB(.00f);
        CALL_REGISTER_SKILL_NODE(20031, 138, node138)
    }
    if (noInit == true) {
        return node138;
    }
    return node138;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(20031, 139) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 144, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 135, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(20031, 139) {
    auto node139 = GET_SKILL_NODE(139, PhaseNode_CreateTriggerNewPene);
    if (node139 == nullptr) {
        node139 = new PhaseNode_CreateTriggerNewPene(139, phase);
        node139->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::Tick);
        node139->setTypeParams(0, .00f);
        node139->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node139->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Enemy);
        node139->setOnHero(true);
        node139->setOnMinion(true);
        node139->setOnDestruct(true);
        node139->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(20031, 139, node139)
    }
    if (noInit == true) {
        return node139;
    }
    auto node120 = GET_SKILL_NODE(120, PhaseNode_SpawnCollider);
    if (node120 != nullptr) node139->setColliderID(node120->getColliderID());
    return node139;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(20031, 140) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_If::TRIGGER_FALSE, 141, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_If::TRIGGER_TRUE, 138, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(20031, 140) {
    auto node140 = GET_SKILL_NODE(140, PhaseNode_If);
    if (node140 == nullptr) {
        node140 = new PhaseNode_If(140, phase);
        node140->setCondition(true);
        CALL_REGISTER_SKILL_NODE(20031, 140, node140)
    }
    if (noInit == true) {
        return node140;
    }
    return node140;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(20031, 141) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 143, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_LESS, 142, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
}

REGISTER_CREATE_SKILL_NODE(20031, 141) {
    auto node141 = GET_SKILL_NODE(141, PhaseNode_CompareFloat);
    if (node141 == nullptr) {
        node141 = new PhaseNode_CompareFloat(141, phase);
        node141->setA(.00f);
        node141->setB(.00f);
        CALL_REGISTER_SKILL_NODE(20031, 141, node141)
    }
    if (noInit == true) {
        return node141;
    }
    return node141;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(20031, 142) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 146, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 148, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(20031, 142) {
    auto node142 = GET_SKILL_NODE(142, PhaseNode_CreateTriggerNewPene);
    if (node142 == nullptr) {
        node142 = new PhaseNode_CreateTriggerNewPene(142, phase);
        node142->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::Tick);
        node142->setTypeParams(0, .00f);
        node142->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node142->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Friend);
        node142->setOnHero(true);
        node142->setOnMinion(true);
        node142->setOnDestruct(true);
        node142->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(20031, 142, node142)
    }
    if (noInit == true) {
        return node142;
    }
    auto node120 = GET_SKILL_NODE(120, PhaseNode_SpawnCollider);
    if (node120 != nullptr) node142->setColliderID(node120->getColliderID());
    return node142;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(20031, 143) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 134, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 149, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(20031, 143) {
    auto node143 = GET_SKILL_NODE(143, PhaseNode_CreateTriggerNewPene);
    if (node143 == nullptr) {
        node143 = new PhaseNode_CreateTriggerNewPene(143, phase);
        node143->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::In);
        node143->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node143->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Friend);
        node143->setOnHero(true);
        node143->setOnMinion(true);
        node143->setOnDestruct(true);
        node143->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(20031, 143, node143)
    }
    if (noInit == true) {
        return node143;
    }
    auto node120 = GET_SKILL_NODE(120, PhaseNode_SpawnCollider);
    if (node120 != nullptr) node143->setColliderID(node120->getColliderID());
    return node143;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(20031, 144) {
}

REGISTER_CREATE_SKILL_NODE(20031, 144) {
    auto node144 = GET_SKILL_NODE(144, PhaseNode_TriggerCheck);
    if (node144 == nullptr) {
        node144 = new PhaseNode_TriggerCheck(144, phase);
        auto node5 = GET_SKILL_NODE(5, PhaseNode_TriggerUpdate);
        if (node5 != nullptr) node5->addTriggerCheck(node144);
        
        CALL_REGISTER_SKILL_NODE(20031, 144, node144)
    }
    if (noInit == true) {
        return node144;
    }
    auto node139 = GET_SKILL_NODE(139, PhaseNode_CreateTriggerNewPene);
    if (node139 != nullptr) node144->setTrigger(0, node139->getTriggerID());
    return node144;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(20031, 145) {
}

REGISTER_CREATE_SKILL_NODE(20031, 145) {
    auto node145 = GET_SKILL_NODE(145, PhaseNode_TriggerCheck);
    if (node145 == nullptr) {
        node145 = new PhaseNode_TriggerCheck(145, phase);
        auto node5 = GET_SKILL_NODE(5, PhaseNode_TriggerUpdate);
        if (node5 != nullptr) node5->addTriggerCheck(node145);
        
        CALL_REGISTER_SKILL_NODE(20031, 145, node145)
    }
    if (noInit == true) {
        return node145;
    }
    auto node133 = GET_SKILL_NODE(133, PhaseNode_CreateTriggerNewPene);
    if (node133 != nullptr) node145->setTrigger(0, node133->getTriggerID());
    return node145;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(20031, 146) {
}

REGISTER_CREATE_SKILL_NODE(20031, 146) {
    auto node146 = GET_SKILL_NODE(146, PhaseNode_TriggerCheck);
    if (node146 == nullptr) {
        node146 = new PhaseNode_TriggerCheck(146, phase);
        auto node5 = GET_SKILL_NODE(5, PhaseNode_TriggerUpdate);
        if (node5 != nullptr) node5->addTriggerCheck(node146);
        
        CALL_REGISTER_SKILL_NODE(20031, 146, node146)
    }
    if (noInit == true) {
        return node146;
    }
    auto node142 = GET_SKILL_NODE(142, PhaseNode_CreateTriggerNewPene);
    if (node142 != nullptr) node146->setTrigger(0, node142->getTriggerID());
    return node146;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(20031, 147) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 136, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(20031, 147) {
    auto node147 = GET_SKILL_NODE(147, PhaseNode_ActorFilterNewPene);
    if (node147 == nullptr) {
        node147 = new PhaseNode_ActorFilterNewPene(147, phase);
        node147->setHero(true);
        node147->setMinion(true);
        node147->setDestruct(true);
        node147->setShield(false);
        node147->setTotalCount(0);
        node147->setPerCount(1);
        CALL_REGISTER_SKILL_NODE(20031, 147, node147)
    }
    if (noInit == true) {
        return node147;
    }
    auto node133 = GET_SKILL_NODE(133, PhaseNode_CreateTriggerNewPene);
    if (node133 != nullptr) node147->setInput(node133->getOther());
    return node147;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(20031, 148) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 136, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(20031, 148) {
    auto node148 = GET_SKILL_NODE(148, PhaseNode_ActorFilterNewPene);
    if (node148 == nullptr) {
        node148 = new PhaseNode_ActorFilterNewPene(148, phase);
        node148->setHero(true);
        node148->setMinion(true);
        node148->setDestruct(true);
        node148->setShield(false);
        node148->setTotalCount(0);
        node148->setPerCount(1);
        CALL_REGISTER_SKILL_NODE(20031, 148, node148)
    }
    if (noInit == true) {
        return node148;
    }
    auto node142 = GET_SKILL_NODE(142, PhaseNode_CreateTriggerNewPene);
    if (node142 != nullptr) node148->setInput(node142->getOther());
    return node148;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(20031, 149) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 136, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(20031, 149) {
    auto node149 = GET_SKILL_NODE(149, PhaseNode_ActorFilterNewPene);
    if (node149 == nullptr) {
        node149 = new PhaseNode_ActorFilterNewPene(149, phase);
        node149->setHero(true);
        node149->setMinion(true);
        node149->setDestruct(true);
        node149->setShield(false);
        node149->setTotalCount(0);
        node149->setPerCount(1);
        CALL_REGISTER_SKILL_NODE(20031, 149, node149)
    }
    if (noInit == true) {
        return node149;
    }
    auto node143 = GET_SKILL_NODE(143, PhaseNode_CreateTriggerNewPene);
    if (node143 != nullptr) node149->setInput(node143->getOther());
    return node149;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(20031, 150) {
}

REGISTER_CREATE_SKILL_NODE(20031, 150) {
    auto node150 = GET_SKILL_NODE(150, PhaseNode_AddSkillBuffs);
    if (node150 == nullptr) {
        node150 = new PhaseNode_AddSkillBuffs(150, phase);
        node150->setConfigID({11});
        CALL_REGISTER_SKILL_NODE(20031, 150, node150)
    }
    if (noInit == true) {
        return node150;
    }
    auto node147 = GET_SKILL_NODE(147, PhaseNode_ActorFilterNewPene);
    auto node136 = GET_SKILL_NODE(136, PhaseNode_GetActorAttribute);
    if (node147 != nullptr) node150->setTarget(node147->getOutput());
    if (node136 != nullptr) node150->setAttribute(node136->getAttribute());
    return node150;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(20031, 151) {
}

REGISTER_CREATE_SKILL_NODE(20031, 151) {
    auto node151 = GET_SKILL_NODE(151, PhaseNode_AddSkillBuffs);
    if (node151 == nullptr) {
        node151 = new PhaseNode_AddSkillBuffs(151, phase);
        node151->setConfigID({11});
        CALL_REGISTER_SKILL_NODE(20031, 151, node151)
    }
    if (noInit == true) {
        return node151;
    }
    auto node148 = GET_SKILL_NODE(148, PhaseNode_ActorFilterNewPene);
    auto node136 = GET_SKILL_NODE(136, PhaseNode_GetActorAttribute);
    if (node148 != nullptr) node151->setTarget(node148->getOutput());
    if (node136 != nullptr) node151->setAttribute(node136->getAttribute());
    return node151;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(20031, 152) {
}

REGISTER_CREATE_SKILL_NODE(20031, 152) {
    auto node152 = GET_SKILL_NODE(152, PhaseNode_AddSkillBuffs);
    if (node152 == nullptr) {
        node152 = new PhaseNode_AddSkillBuffs(152, phase);
        node152->setConfigID({11});
        CALL_REGISTER_SKILL_NODE(20031, 152, node152)
    }
    if (noInit == true) {
        return node152;
    }
    auto node149 = GET_SKILL_NODE(149, PhaseNode_ActorFilterNewPene);
    auto node136 = GET_SKILL_NODE(136, PhaseNode_GetActorAttribute);
    if (node149 != nullptr) node152->setTarget(node149->getOutput());
    if (node136 != nullptr) node152->setAttribute(node136->getAttribute());
    return node152;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(20031, 153) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetRotation>(PhaseNode_GetLocation::TRIGGER_DONE, 154, PhaseNode_GetRotation::FUNC_DO, &PhaseNode_GetRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(20031, 153) {
    auto node153 = GET_SKILL_NODE(153, PhaseNode_GetLocation);
    if (node153 == nullptr) {
        node153 = new PhaseNode_GetLocation(153, phase);
        node153->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node153->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(20031, 153, node153)
    }
    if (noInit == true) {
        return node153;
    }
    return node153;
}
//--------------------------------------------------------------------------------
// GetRotation
//
REGISTER_REGISTER_SKILL_NODE(20031, 154) {
    pnode->resizeTrigger(PhaseNode_GetRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_OffsetCalculate>(PhaseNode_GetRotation::TRIGGER_DONE, 155, PhaseNode_OffsetCalculate::FUNC_DO, &PhaseNode_OffsetCalculate::Do);
}

REGISTER_CREATE_SKILL_NODE(20031, 154) {
    auto node154 = GET_SKILL_NODE(154, PhaseNode_GetRotation);
    if (node154 == nullptr) {
        node154 = new PhaseNode_GetRotation(154, phase);
        node154->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node154->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(20031, 154, node154)
    }
    if (noInit == true) {
        return node154;
    }
    return node154;
}
//--------------------------------------------------------------------------------
// OffsetCalculate
//
REGISTER_REGISTER_SKILL_NODE(20031, 155) {
    pnode->resizeTrigger(PhaseNode_OffsetCalculate::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 161, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(20031, 155) {
    auto node155 = GET_SKILL_NODE(155, PhaseNode_OffsetCalculate);
    if (node155 == nullptr) {
        node155 = new PhaseNode_OffsetCalculate(155, phase);
        node155->setPosZ(.00f);
        node155->setOffsetX(.00f);
        node155->setOffsetY(.00f);
        node155->setOffsetZ(.00f);
        node155->setRotOffset(.00f);
        CALL_REGISTER_SKILL_NODE(20031, 155, node155)
    }
    if (noInit == true) {
        return node155;
    }
    auto node153 = GET_SKILL_NODE(153, PhaseNode_GetLocation);
    auto node154 = GET_SKILL_NODE(154, PhaseNode_GetRotation);
    if (node153 != nullptr) node155->setPosX(node153->getX());
    if (node153 != nullptr) node155->setPosY(node153->getY());
    if (node154 != nullptr) node155->setRotation(node154->getAngle());
    return node155;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(20031, 156) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_ResetCD::TRIGGER_DONE, 157, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(20031, 156) {
    auto node156 = GET_SKILL_NODE(156, PhaseNode_ResetCD);
    if (node156 == nullptr) {
        node156 = new PhaseNode_ResetCD(156, phase);
        node156->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node156->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node156->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(20031, 156, node156)
    }
    if (noInit == true) {
        return node156;
    }
    return node156;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(20031, 157) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_PlayAnimation::TRIGGER_DONE, 158, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(20031, 157) {
    auto node157 = GET_SKILL_NODE(157, PhaseNode_PlayAnimation);
    if (node157 == nullptr) {
        node157 = new PhaseNode_PlayAnimation(157, phase);
        node157->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node157->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node157->setTarget(0U);
        node157->setAnimation("Skill1S1");
        node157->setParameter("");
        node157->setValue(false);
        CALL_REGISTER_SKILL_NODE(20031, 157, node157)
    }
    if (noInit == true) {
        return node157;
    }
    return node157;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(20031, 158) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlaySound::TRIGGER_DONE, 159, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(20031, 158) {
    auto node158 = GET_SKILL_NODE(158, PhaseNode_PlaySound);
    if (node158 == nullptr) {
        node158 = new PhaseNode_PlaySound(158, phase);
        node158->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node158->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node158->setSoundID("");
        node158->setTarget(0U);
        node158->setUsePos(false);
        node158->setPosX(.00f);
        node158->setPosY(.00f);
        node158->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(20031, 158, node158)
    }
    if (noInit == true) {
        return node158;
    }
    return node158;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(20031, 159) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_Delay::TRIGGER_DONE, 153, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(20031, 159) {
    auto node159 = GET_SKILL_NODE(159, PhaseNode_Delay);
    if (node159 == nullptr) {
        node159 = new PhaseNode_Delay(159, phase);
        node159->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(20031, 159, node159)
    }
    if (noInit == true) {
        return node159;
    }
    return node159;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(20031, 160) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_PlayEffect::TRIGGER_DONE, 163, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(20031, 160) {
    auto node160 = GET_SKILL_NODE(160, PhaseNode_PlayEffect);
    if (node160 == nullptr) {
        node160 = new PhaseNode_PlayEffect(160, phase);
        node160->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node160->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node160->setEffectID(0);
        node160->setChangeColor(false);
        node160->setType(PhaseNode_PlayEffect::PlayEffect_Type::WithTarget);
        node160->getVars().reserve(5);
        node160->getVars().setVariable<uint64_t>(0, 0U);
        node160->getVars().setVariable<std::string>(1, "");
        node160->getVars().setVariable<float>(2, .00f);
        node160->getVars().setVariable<float>(3, .00f);
        node160->getVars().setVariable<float>(4, .00f);
        node160->setScale(.00f);
        CALL_REGISTER_SKILL_NODE(20031, 160, node160)
    }
    if (noInit == true) {
        return node160;
    }
    auto node155 = GET_SKILL_NODE(155, PhaseNode_OffsetCalculate);
    if (node155 != nullptr) node160->getVars().setVariable<float>(2, node155->getOutPosX());
    if (node155 != nullptr) node160->getVars().setVariable<float>(3, node155->getOutPosY());
    if (node155 != nullptr) node160->getVars().setVariable<float>(4, node155->getOutPosZ());
    if (node155 != nullptr) node160->setRotation(node155->getOutRotation());
    return node160;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(20031, 161) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_FALSE, 162, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_TRUE, 160, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(20031, 161) {
    auto node161 = GET_SKILL_NODE(161, PhaseNode_If);
    if (node161 == nullptr) {
        node161 = new PhaseNode_If(161, phase);
        node161->setCondition(false);
        CALL_REGISTER_SKILL_NODE(20031, 161, node161)
    }
    if (noInit == true) {
        return node161;
    }
    return node161;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(20031, 162) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_PlayEffect::TRIGGER_DONE, 163, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(20031, 162) {
    auto node162 = GET_SKILL_NODE(162, PhaseNode_PlayEffect);
    if (node162 == nullptr) {
        node162 = new PhaseNode_PlayEffect(162, phase);
        node162->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node162->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node162->setEffectID(0);
        node162->setChangeColor(false);
        node162->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node162->getVars().reserve(3);
        node162->getVars().setVariable<float>(0, .00f);
        node162->getVars().setVariable<float>(1, .00f);
        node162->getVars().setVariable<float>(2, .00f);
        node162->setScale(.00f);
        CALL_REGISTER_SKILL_NODE(20031, 162, node162)
    }
    if (noInit == true) {
        return node162;
    }
    auto node155 = GET_SKILL_NODE(155, PhaseNode_OffsetCalculate);
    if (node155 != nullptr) node162->getVars().setVariable<float>(0, node155->getOutPosX());
    if (node155 != nullptr) node162->getVars().setVariable<float>(1, node155->getOutPosY());
    if (node155 != nullptr) node162->getVars().setVariable<float>(2, node155->getOutPosZ());
    if (node155 != nullptr) node162->setRotation(node155->getOutRotation());
    return node162;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(20031, 163) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 167, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_LESS, 164, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_CompareFloat::TRIGGER_LESS, 167, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(20031, 163) {
    auto node163 = GET_SKILL_NODE(163, PhaseNode_CompareFloat);
    if (node163 == nullptr) {
        node163 = new PhaseNode_CompareFloat(163, phase);
        node163->setA(.00f);
        node163->setB(.00f);
        CALL_REGISTER_SKILL_NODE(20031, 163, node163)
    }
    if (noInit == true) {
        return node163;
    }
    return node163;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(20031, 164) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StopEffect>(PhaseNode_Delay::TRIGGER_DONE, 165, PhaseNode_StopEffect::FUNC_DO, &PhaseNode_StopEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(20031, 164) {
    auto node164 = GET_SKILL_NODE(164, PhaseNode_Delay);
    if (node164 == nullptr) {
        node164 = new PhaseNode_Delay(164, phase);
        node164->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(20031, 164, node164)
    }
    if (noInit == true) {
        return node164;
    }
    return node164;
}
//--------------------------------------------------------------------------------
// StopEffect
//
REGISTER_REGISTER_SKILL_NODE(20031, 165) {
}

REGISTER_CREATE_SKILL_NODE(20031, 165) {
    auto node165 = GET_SKILL_NODE(165, PhaseNode_StopEffect);
    if (node165 == nullptr) {
        node165 = new PhaseNode_StopEffect(165, phase);
        node165->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node165->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node165->setEffectID(0);
        CALL_REGISTER_SKILL_NODE(20031, 165, node165)
    }
    if (noInit == true) {
        return node165;
    }
    return node165;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(20031, 166) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_PlayEffect::TRIGGER_DONE, 169, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(20031, 166) {
    auto node166 = GET_SKILL_NODE(166, PhaseNode_PlayEffect);
    if (node166 == nullptr) {
        node166 = new PhaseNode_PlayEffect(166, phase);
        node166->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node166->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node166->setEffectID(0);
        node166->setChangeColor(false);
        node166->setType(PhaseNode_PlayEffect::PlayEffect_Type::WithTarget);
        node166->getVars().reserve(5);
        node166->getVars().setVariable<uint64_t>(0, 0U);
        node166->getVars().setVariable<std::string>(1, "");
        node166->getVars().setVariable<float>(2, .00f);
        node166->getVars().setVariable<float>(3, .00f);
        node166->getVars().setVariable<float>(4, .00f);
        node166->setScale(.00f);
        CALL_REGISTER_SKILL_NODE(20031, 166, node166)
    }
    if (noInit == true) {
        return node166;
    }
    auto node155 = GET_SKILL_NODE(155, PhaseNode_OffsetCalculate);
    if (node155 != nullptr) node166->getVars().setVariable<float>(2, node155->getOutPosX());
    if (node155 != nullptr) node166->getVars().setVariable<float>(3, node155->getOutPosY());
    if (node155 != nullptr) node166->getVars().setVariable<float>(4, node155->getOutPosZ());
    if (node155 != nullptr) node166->setRotation(node155->getOutRotation());
    return node166;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(20031, 167) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_FALSE, 168, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_TRUE, 166, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(20031, 167) {
    auto node167 = GET_SKILL_NODE(167, PhaseNode_If);
    if (node167 == nullptr) {
        node167 = new PhaseNode_If(167, phase);
        node167->setCondition(false);
        CALL_REGISTER_SKILL_NODE(20031, 167, node167)
    }
    if (noInit == true) {
        return node167;
    }
    return node167;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(20031, 168) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_PlayEffect::TRIGGER_DONE, 169, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(20031, 168) {
    auto node168 = GET_SKILL_NODE(168, PhaseNode_PlayEffect);
    if (node168 == nullptr) {
        node168 = new PhaseNode_PlayEffect(168, phase);
        node168->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node168->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node168->setEffectID(0);
        node168->setChangeColor(false);
        node168->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node168->getVars().reserve(3);
        node168->getVars().setVariable<float>(0, .00f);
        node168->getVars().setVariable<float>(1, .00f);
        node168->getVars().setVariable<float>(2, .00f);
        node168->setScale(.00f);
        CALL_REGISTER_SKILL_NODE(20031, 168, node168)
    }
    if (noInit == true) {
        return node168;
    }
    auto node155 = GET_SKILL_NODE(155, PhaseNode_OffsetCalculate);
    if (node155 != nullptr) node168->getVars().setVariable<float>(0, node155->getOutPosX());
    if (node155 != nullptr) node168->getVars().setVariable<float>(1, node155->getOutPosY());
    if (node155 != nullptr) node168->getVars().setVariable<float>(2, node155->getOutPosZ());
    if (node155 != nullptr) node168->setRotation(node155->getOutRotation());
    return node168;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(20031, 169) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 128, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_LESS, 128, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_LESS, 170, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(20031, 169) {
    auto node169 = GET_SKILL_NODE(169, PhaseNode_CompareFloat);
    if (node169 == nullptr) {
        node169 = new PhaseNode_CompareFloat(169, phase);
        node169->setA(.00f);
        node169->setB(.00f);
        CALL_REGISTER_SKILL_NODE(20031, 169, node169)
    }
    if (noInit == true) {
        return node169;
    }
    return node169;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(20031, 170) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StopEffect>(PhaseNode_Delay::TRIGGER_DONE, 171, PhaseNode_StopEffect::FUNC_DO, &PhaseNode_StopEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(20031, 170) {
    auto node170 = GET_SKILL_NODE(170, PhaseNode_Delay);
    if (node170 == nullptr) {
        node170 = new PhaseNode_Delay(170, phase);
        node170->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(20031, 170, node170)
    }
    if (noInit == true) {
        return node170;
    }
    return node170;
}
//--------------------------------------------------------------------------------
// StopEffect
//
REGISTER_REGISTER_SKILL_NODE(20031, 171) {
}

REGISTER_CREATE_SKILL_NODE(20031, 171) {
    auto node171 = GET_SKILL_NODE(171, PhaseNode_StopEffect);
    if (node171 == nullptr) {
        node171 = new PhaseNode_StopEffect(171, phase);
        node171->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node171->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node171->setEffectID(0);
        CALL_REGISTER_SKILL_NODE(20031, 171, node171)
    }
    if (noInit == true) {
        return node171;
    }
    return node171;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(20031, 172) {
}

REGISTER_CREATE_SKILL_NODE(20031, 172) {
    auto node172 = GET_SKILL_NODE(172, PhaseNode_RaiseEvent);
    if (node172 == nullptr) {
        node172 = new PhaseNode_RaiseEvent(172, phase);
        node172->setEvent("MonsterInterrupt");
        node172->setTarget(0U);
        node172->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node172->setTypeParams(0, 0);
        node172->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(20031, 172, node172)
    }
    if (noInit == true) {
        return node172;
    }
    return node172;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(20031, 173) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_Detect::TRIGGER_ON, 176, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(20031, 173) {
    auto node173 = GET_SKILL_NODE(173, PhaseNode_Detect);
    if (node173 == nullptr) {
        node173 = new PhaseNode_Detect(173, phase);
        node173->setSelf(0U);
        node173->setEvent("MonsterInterrupt");
        node173->setType(PhaseNode_Detect::Detect_Type::Interrupt_Skill);
        node173->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(20031, 173, node173)
    }
    if (noInit == true) {
        return node173;
    }
    return node173;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(20031, 174) {
}

REGISTER_CREATE_SKILL_NODE(20031, 174) {
    auto node174 = GET_SKILL_NODE(174, PhaseNode_EndPhase);
    if (node174 == nullptr) {
        node174 = new PhaseNode_EndPhase(174, phase);
        node174->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node174->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(20031, 174, node174)
    }
    if (noInit == true) {
        return node174;
    }
    return node174;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(20031, 176) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_Delay::TRIGGER_DONE, 178, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(20031, 176) {
    auto node176 = GET_SKILL_NODE(176, PhaseNode_Delay);
    if (node176 == nullptr) {
        node176 = new PhaseNode_Delay(176, phase);
        node176->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(20031, 176, node176)
    }
    if (noInit == true) {
        return node176;
    }
    return node176;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(20031, 177) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 174, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(20031, 177) {
    auto node177 = GET_SKILL_NODE(177, PhaseNode_SkillEndNotify);
    if (node177 == nullptr) {
        node177 = new PhaseNode_SkillEndNotify(177, phase);
        node177->setReturnType(false);
        CALL_REGISTER_SKILL_NODE(20031, 177, node177)
    }
    if (noInit == true) {
        return node177;
    }
    return node177;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(20031, 178) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_FALSE, 179, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_TRUE, 177, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
}

REGISTER_CREATE_SKILL_NODE(20031, 178) {
    auto node178 = GET_SKILL_NODE(178, PhaseNode_If);
    if (node178 == nullptr) {
        node178 = new PhaseNode_If(178, phase);
        node178->setCondition(false);
        CALL_REGISTER_SKILL_NODE(20031, 178, node178)
    }
    if (noInit == true) {
        return node178;
    }
    return node178;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(20031, 179) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 174, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(20031, 179) {
    auto node179 = GET_SKILL_NODE(179, PhaseNode_SkillEndNotify);
    if (node179 == nullptr) {
        node179 = new PhaseNode_SkillEndNotify(179, phase);
        node179->setReturnType(true);
        CALL_REGISTER_SKILL_NODE(20031, 179, node179)
    }
    if (noInit == true) {
        return node179;
    }
    return node179;
}

//--------------------------------------------------------------------------------
// SkillCreator_20031
//
class SkillCreator_20031 : public SkillCreator {
public:
    SkillCreator_20031() {}
    virtual ~SkillCreator_20031() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_20031

//--------------------------------------------------------------------------------
// SkillPhase_20031
//
class SkillPhase_20031 : public SkillPhase {
public:
    SkillPhase_20031(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_20031() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(20031, 1) // StartPhase
        CASE_CREATE_SKILL_NODE(20031, 5) // TriggerUpdate
        CASE_CREATE_SKILL_NODE(20031, 30) // EndPhase
        CASE_CREATE_SKILL_NODE(20031, 119) // PlaySound
        CASE_CREATE_SKILL_NODE(20031, 120) // SpawnCollider
        CASE_CREATE_SKILL_NODE(20031, 128) // Delay
        CASE_CREATE_SKILL_NODE(20031, 129) // Delay
        CASE_CREATE_SKILL_NODE(20031, 130) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(20031, 131) // If
        CASE_CREATE_SKILL_NODE(20031, 132) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(20031, 133) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(20031, 134) // TriggerCheck
        CASE_CREATE_SKILL_NODE(20031, 135) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(20031, 136) // GetActorAttribute
        CASE_CREATE_SKILL_NODE(20031, 137) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(20031, 138) // CompareFloat
        CASE_CREATE_SKILL_NODE(20031, 139) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(20031, 140) // If
        CASE_CREATE_SKILL_NODE(20031, 141) // CompareFloat
        CASE_CREATE_SKILL_NODE(20031, 142) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(20031, 143) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(20031, 144) // TriggerCheck
        CASE_CREATE_SKILL_NODE(20031, 145) // TriggerCheck
        CASE_CREATE_SKILL_NODE(20031, 146) // TriggerCheck
        CASE_CREATE_SKILL_NODE(20031, 147) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(20031, 148) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(20031, 149) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(20031, 150) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(20031, 151) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(20031, 152) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(20031, 153) // GetLocation
        CASE_CREATE_SKILL_NODE(20031, 154) // GetRotation
        CASE_CREATE_SKILL_NODE(20031, 155) // OffsetCalculate
        CASE_CREATE_SKILL_NODE(20031, 156) // ResetCD
        CASE_CREATE_SKILL_NODE(20031, 157) // PlayAnimation
        CASE_CREATE_SKILL_NODE(20031, 158) // PlaySound
        CASE_CREATE_SKILL_NODE(20031, 159) // Delay
        CASE_CREATE_SKILL_NODE(20031, 160) // PlayEffect
        CASE_CREATE_SKILL_NODE(20031, 161) // If
        CASE_CREATE_SKILL_NODE(20031, 162) // PlayEffect
        CASE_CREATE_SKILL_NODE(20031, 163) // CompareFloat
        CASE_CREATE_SKILL_NODE(20031, 164) // Delay
        CASE_CREATE_SKILL_NODE(20031, 165) // StopEffect
        CASE_CREATE_SKILL_NODE(20031, 166) // PlayEffect
        CASE_CREATE_SKILL_NODE(20031, 167) // If
        CASE_CREATE_SKILL_NODE(20031, 168) // PlayEffect
        CASE_CREATE_SKILL_NODE(20031, 169) // CompareFloat
        CASE_CREATE_SKILL_NODE(20031, 170) // Delay
        CASE_CREATE_SKILL_NODE(20031, 171) // StopEffect
        CASE_CREATE_SKILL_NODE(20031, 172) // RaiseEvent
        CASE_CREATE_SKILL_NODE(20031, 173) // Detect
        CASE_CREATE_SKILL_NODE(20031, 174) // EndPhase
        CASE_CREATE_SKILL_NODE(20031, 176) // Delay
        CASE_CREATE_SKILL_NODE(20031, 177) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(20031, 178) // If
        CASE_CREATE_SKILL_NODE(20031, 179) // SkillEndNotify
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_20031

SkillLogic* SkillCreator_20031::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //创建阶段phase
    auto phase = new SkillPhase_20031(1, logic, 3);
    //设置phase执行器
    phase->setRunPhaseNode(1, 1);
    phase->setRunPhaseNode(2, 5);
    phase->setDetectPhaseNode(3, 173);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_20031::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
