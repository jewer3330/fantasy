#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

#include "skill_psnode_actorfilternewpene.h"
#include "skill_psnode_addskillbuffs.h"
#include "skill_psnode_camerashake.h"
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
REGISTER_REGISTER_SKILL_NODE(20042, 36) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_StartPhase::TRIGGER_START, 287, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_StartPhase::TRIGGER_START, 261, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(20042, 36) {
    auto node36 = GET_SKILL_NODE(36, PhaseNode_StartPhase);
    if (node36 == nullptr) {
        node36 = new PhaseNode_StartPhase(36, phase);
        CALL_REGISTER_SKILL_NODE(20042, 36, node36)
    }
    if (noInit == true) {
        return node36;
    }
    return node36;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(20042, 42) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_Delay::TRIGGER_DONE, 176, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(20042, 42) {
    auto node42 = GET_SKILL_NODE(42, PhaseNode_Delay);
    if (node42 == nullptr) {
        node42 = new PhaseNode_Delay(42, phase);
        node42->setTime(1.10f);
        CALL_REGISTER_SKILL_NODE(20042, 42, node42)
    }
    if (noInit == true) {
        return node42;
    }
    return node42;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(20042, 45) {
}

REGISTER_CREATE_SKILL_NODE(20042, 45) {
    auto node45 = GET_SKILL_NODE(45, PhaseNode_EndPhase);
    if (node45 == nullptr) {
        node45 = new PhaseNode_EndPhase(45, phase);
        node45->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node45->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(20042, 45, node45)
    }
    if (noInit == true) {
        return node45;
    }
    return node45;
}
//--------------------------------------------------------------------------------
// TriggerUpdate
//
REGISTER_REGISTER_SKILL_NODE(20042, 52) {
}

REGISTER_CREATE_SKILL_NODE(20042, 52) {
    auto node52 = GET_SKILL_NODE(52, PhaseNode_TriggerUpdate);
    if (node52 == nullptr) {
        node52 = new PhaseNode_TriggerUpdate(52, phase);
        CALL_REGISTER_SKILL_NODE(20042, 52, node52)
    }
    if (noInit == true) {
        return node52;
    }
    return node52;
}
//--------------------------------------------------------------------------------
// SpawnCollider
//
REGISTER_REGISTER_SKILL_NODE(20042, 104) {
    pnode->resizeTrigger(PhaseNode_SpawnCollider::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_SpawnCollider::TRIGGER_DONE, 237, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_SpawnCollider::TRIGGER_DONE, 248, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(20042, 104) {
    auto node104 = GET_SKILL_NODE(104, PhaseNode_SpawnCollider);
    if (node104 == nullptr) {
        node104 = new PhaseNode_SpawnCollider(104, phase);
        node104->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node104->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node104->setMesh("");
        node104->setMeshScale(.00f);
        node104->setEffectID(0);
        node104->setEffectScale(.00f);
        node104->setType(PhaseNode_SpawnCollider::SpawnCollider_Type::Circle);
        node104->setTypeParams(0, 4.00f);
        node104->setTime(.30f);
        node104->setreentry(false);
        node104->setCheckPeneSound(false);
        CALL_REGISTER_SKILL_NODE(20042, 104, node104)
    }
    if (noInit == true) {
        return node104;
    }
    auto node270 = GET_SKILL_NODE(270, PhaseNode_OffsetCalculate);
    if (node270 != nullptr) node104->setPosX(node270->getOutPosX());
    if (node270 != nullptr) node104->setPosY(node270->getOutPosY());
    if (node270 != nullptr) node104->setPosZ(node270->getOutPosZ());
    if (node270 != nullptr) node104->setRotation(node270->getOutRotation());
    return node104;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(20042, 173) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_Detect::TRIGGER_ON, 174, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(20042, 173) {
    auto node173 = GET_SKILL_NODE(173, PhaseNode_Detect);
    if (node173 == nullptr) {
        node173 = new PhaseNode_Detect(173, phase);
        node173->setSelf(0U);
        node173->setEvent("");
        node173->setType(PhaseNode_Detect::Detect_Type::Actor_Dead);
        node173->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(20042, 173, node173)
    }
    if (noInit == true) {
        return node173;
    }
    return node173;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(20042, 174) {
}

REGISTER_CREATE_SKILL_NODE(20042, 174) {
    auto node174 = GET_SKILL_NODE(174, PhaseNode_EndPhase);
    if (node174 == nullptr) {
        node174 = new PhaseNode_EndPhase(174, phase);
        node174->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node174->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(20042, 174, node174)
    }
    if (noInit == true) {
        return node174;
    }
    return node174;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(20042, 176) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnCollider>(PhaseNode_PlaySound::TRIGGER_DONE, 104, PhaseNode_SpawnCollider::FUNC_DO, &PhaseNode_SpawnCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(20042, 176) {
    auto node176 = GET_SKILL_NODE(176, PhaseNode_PlaySound);
    if (node176 == nullptr) {
        node176 = new PhaseNode_PlaySound(176, phase);
        node176->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node176->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node176->setSoundID("SE_MON2004_Skill_B_P1");
        node176->setTarget(0U);
        node176->setUsePos(false);
        node176->setPosX(.00f);
        node176->setPosY(.00f);
        node176->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(20042, 176, node176)
    }
    if (noInit == true) {
        return node176;
    }
    return node176;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(20042, 211) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_PlaySound::TRIGGER_DONE, 265, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(20042, 211) {
    auto node211 = GET_SKILL_NODE(211, PhaseNode_PlaySound);
    if (node211 == nullptr) {
        node211 = new PhaseNode_PlaySound(211, phase);
        node211->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node211->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node211->setSoundID("VO_MON2004_Charge");
        node211->setTarget(0U);
        node211->setUsePos(false);
        node211->setPosX(.00f);
        node211->setPosY(.00f);
        node211->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(20042, 211, node211)
    }
    if (noInit == true) {
        return node211;
    }
    return node211;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(20042, 237) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CameraShake>(PhaseNode_Delay::TRIGGER_DONE, 239, PhaseNode_CameraShake::FUNC_DO, &PhaseNode_CameraShake::Do);
}

REGISTER_CREATE_SKILL_NODE(20042, 237) {
    auto node237 = GET_SKILL_NODE(237, PhaseNode_Delay);
    if (node237 == nullptr) {
        node237 = new PhaseNode_Delay(237, phase);
        node237->setTime(.10f);
        CALL_REGISTER_SKILL_NODE(20042, 237, node237)
    }
    if (noInit == true) {
        return node237;
    }
    return node237;
}
//--------------------------------------------------------------------------------
// CameraShake
//
REGISTER_REGISTER_SKILL_NODE(20042, 239) {
    pnode->resizeTrigger(PhaseNode_CameraShake::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CameraShake::TRIGGER_DONE, 283, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(20042, 239) {
    auto node239 = GET_SKILL_NODE(239, PhaseNode_CameraShake);
    if (node239 == nullptr) {
        node239 = new PhaseNode_CameraShake(239, phase);
        node239->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node239->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node239->setTarget(0U);
        node239->setFrequency(.20f);
        node239->setAmplitude(2.00f);
        node239->setDuration(.60f);
        node239->setFalloff(true);
        CALL_REGISTER_SKILL_NODE(20042, 239, node239)
    }
    if (noInit == true) {
        return node239;
    }
    return node239;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(20042, 241) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 253, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 255, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(20042, 241) {
    auto node241 = GET_SKILL_NODE(241, PhaseNode_CreateTriggerNewPene);
    if (node241 == nullptr) {
        node241 = new PhaseNode_CreateTriggerNewPene(241, phase);
        node241->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::In);
        node241->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node241->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Enemy);
        node241->setOnHero(true);
        node241->setOnMinion(true);
        node241->setOnDestruct(true);
        node241->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(20042, 241, node241)
    }
    if (noInit == true) {
        return node241;
    }
    auto node104 = GET_SKILL_NODE(104, PhaseNode_SpawnCollider);
    if (node104 != nullptr) node241->setColliderID(node104->getColliderID());
    return node241;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(20042, 242) {
}

REGISTER_CREATE_SKILL_NODE(20042, 242) {
    auto node242 = GET_SKILL_NODE(242, PhaseNode_TriggerCheck);
    if (node242 == nullptr) {
        node242 = new PhaseNode_TriggerCheck(242, phase);
        auto node52 = GET_SKILL_NODE(52, PhaseNode_TriggerUpdate);
        if (node52 != nullptr) node52->addTriggerCheck(node242);
        
        CALL_REGISTER_SKILL_NODE(20042, 242, node242)
    }
    if (noInit == true) {
        return node242;
    }
    auto node251 = GET_SKILL_NODE(251, PhaseNode_CreateTriggerNewPene);
    if (node251 != nullptr) node242->setTrigger(0, node251->getTriggerID());
    return node242;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(20042, 243) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 244, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(20042, 243) {
    auto node243 = GET_SKILL_NODE(243, PhaseNode_ActorFilterNewPene);
    if (node243 == nullptr) {
        node243 = new PhaseNode_ActorFilterNewPene(243, phase);
        node243->setHero(true);
        node243->setMinion(true);
        node243->setDestruct(true);
        node243->setShield(false);
        node243->setTotalCount(0);
        node243->setPerCount(1);
        CALL_REGISTER_SKILL_NODE(20042, 243, node243)
    }
    if (noInit == true) {
        return node243;
    }
    auto node247 = GET_SKILL_NODE(247, PhaseNode_CreateTriggerNewPene);
    if (node247 != nullptr) node243->setInput(node247->getOther());
    return node243;
}
//--------------------------------------------------------------------------------
// GetActorAttribute
//
REGISTER_REGISTER_SKILL_NODE(20042, 244) {
    pnode->resizeTrigger(PhaseNode_GetActorAttribute::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 245, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 258, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 259, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 260, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
}

REGISTER_CREATE_SKILL_NODE(20042, 244) {
    auto node244 = GET_SKILL_NODE(244, PhaseNode_GetActorAttribute);
    if (node244 == nullptr) {
        node244 = new PhaseNode_GetActorAttribute(244, phase);
        node244->setTarget(0U);
        node244->setType({202});
        CALL_REGISTER_SKILL_NODE(20042, 244, node244)
    }
    if (noInit == true) {
        return node244;
    }
    return node244;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(20042, 245) {
}

REGISTER_CREATE_SKILL_NODE(20042, 245) {
    auto node245 = GET_SKILL_NODE(245, PhaseNode_AddSkillBuffs);
    if (node245 == nullptr) {
        node245 = new PhaseNode_AddSkillBuffs(245, phase);
        node245->setConfigID({11});
        CALL_REGISTER_SKILL_NODE(20042, 245, node245)
    }
    if (noInit == true) {
        return node245;
    }
    auto node243 = GET_SKILL_NODE(243, PhaseNode_ActorFilterNewPene);
    auto node244 = GET_SKILL_NODE(244, PhaseNode_GetActorAttribute);
    if (node243 != nullptr) node245->setTarget(node243->getOutput());
    if (node244 != nullptr) node245->setAttribute(node244->getAttribute());
    return node245;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(20042, 246) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 241, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_LESS, 247, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
}

REGISTER_CREATE_SKILL_NODE(20042, 246) {
    auto node246 = GET_SKILL_NODE(246, PhaseNode_CompareFloat);
    if (node246 == nullptr) {
        node246 = new PhaseNode_CompareFloat(246, phase);
        node246->setA(.00f);
        node246->setB(.00f);
        CALL_REGISTER_SKILL_NODE(20042, 246, node246)
    }
    if (noInit == true) {
        return node246;
    }
    return node246;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(20042, 247) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 252, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 243, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(20042, 247) {
    auto node247 = GET_SKILL_NODE(247, PhaseNode_CreateTriggerNewPene);
    if (node247 == nullptr) {
        node247 = new PhaseNode_CreateTriggerNewPene(247, phase);
        node247->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::Tick);
        node247->setTypeParams(0, .00f);
        node247->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node247->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Enemy);
        node247->setOnHero(true);
        node247->setOnMinion(true);
        node247->setOnDestruct(true);
        node247->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(20042, 247, node247)
    }
    if (noInit == true) {
        return node247;
    }
    auto node104 = GET_SKILL_NODE(104, PhaseNode_SpawnCollider);
    if (node104 != nullptr) node247->setColliderID(node104->getColliderID());
    return node247;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(20042, 248) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_If::TRIGGER_FALSE, 249, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_If::TRIGGER_TRUE, 246, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(20042, 248) {
    auto node248 = GET_SKILL_NODE(248, PhaseNode_If);
    if (node248 == nullptr) {
        node248 = new PhaseNode_If(248, phase);
        node248->setCondition(true);
        CALL_REGISTER_SKILL_NODE(20042, 248, node248)
    }
    if (noInit == true) {
        return node248;
    }
    return node248;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(20042, 249) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 251, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_LESS, 250, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
}

REGISTER_CREATE_SKILL_NODE(20042, 249) {
    auto node249 = GET_SKILL_NODE(249, PhaseNode_CompareFloat);
    if (node249 == nullptr) {
        node249 = new PhaseNode_CompareFloat(249, phase);
        node249->setA(.00f);
        node249->setB(.00f);
        CALL_REGISTER_SKILL_NODE(20042, 249, node249)
    }
    if (noInit == true) {
        return node249;
    }
    return node249;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(20042, 250) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 254, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 256, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(20042, 250) {
    auto node250 = GET_SKILL_NODE(250, PhaseNode_CreateTriggerNewPene);
    if (node250 == nullptr) {
        node250 = new PhaseNode_CreateTriggerNewPene(250, phase);
        node250->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::Tick);
        node250->setTypeParams(0, .00f);
        node250->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node250->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Friend);
        node250->setOnHero(true);
        node250->setOnMinion(true);
        node250->setOnDestruct(true);
        node250->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(20042, 250, node250)
    }
    if (noInit == true) {
        return node250;
    }
    auto node104 = GET_SKILL_NODE(104, PhaseNode_SpawnCollider);
    if (node104 != nullptr) node250->setColliderID(node104->getColliderID());
    return node250;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(20042, 251) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 242, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 257, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(20042, 251) {
    auto node251 = GET_SKILL_NODE(251, PhaseNode_CreateTriggerNewPene);
    if (node251 == nullptr) {
        node251 = new PhaseNode_CreateTriggerNewPene(251, phase);
        node251->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::In);
        node251->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node251->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Friend);
        node251->setOnHero(true);
        node251->setOnMinion(true);
        node251->setOnDestruct(true);
        node251->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(20042, 251, node251)
    }
    if (noInit == true) {
        return node251;
    }
    auto node104 = GET_SKILL_NODE(104, PhaseNode_SpawnCollider);
    if (node104 != nullptr) node251->setColliderID(node104->getColliderID());
    return node251;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(20042, 252) {
}

REGISTER_CREATE_SKILL_NODE(20042, 252) {
    auto node252 = GET_SKILL_NODE(252, PhaseNode_TriggerCheck);
    if (node252 == nullptr) {
        node252 = new PhaseNode_TriggerCheck(252, phase);
        auto node52 = GET_SKILL_NODE(52, PhaseNode_TriggerUpdate);
        if (node52 != nullptr) node52->addTriggerCheck(node252);
        
        CALL_REGISTER_SKILL_NODE(20042, 252, node252)
    }
    if (noInit == true) {
        return node252;
    }
    auto node247 = GET_SKILL_NODE(247, PhaseNode_CreateTriggerNewPene);
    if (node247 != nullptr) node252->setTrigger(0, node247->getTriggerID());
    return node252;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(20042, 253) {
}

REGISTER_CREATE_SKILL_NODE(20042, 253) {
    auto node253 = GET_SKILL_NODE(253, PhaseNode_TriggerCheck);
    if (node253 == nullptr) {
        node253 = new PhaseNode_TriggerCheck(253, phase);
        auto node52 = GET_SKILL_NODE(52, PhaseNode_TriggerUpdate);
        if (node52 != nullptr) node52->addTriggerCheck(node253);
        
        CALL_REGISTER_SKILL_NODE(20042, 253, node253)
    }
    if (noInit == true) {
        return node253;
    }
    auto node241 = GET_SKILL_NODE(241, PhaseNode_CreateTriggerNewPene);
    if (node241 != nullptr) node253->setTrigger(0, node241->getTriggerID());
    return node253;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(20042, 254) {
}

REGISTER_CREATE_SKILL_NODE(20042, 254) {
    auto node254 = GET_SKILL_NODE(254, PhaseNode_TriggerCheck);
    if (node254 == nullptr) {
        node254 = new PhaseNode_TriggerCheck(254, phase);
        auto node52 = GET_SKILL_NODE(52, PhaseNode_TriggerUpdate);
        if (node52 != nullptr) node52->addTriggerCheck(node254);
        
        CALL_REGISTER_SKILL_NODE(20042, 254, node254)
    }
    if (noInit == true) {
        return node254;
    }
    auto node250 = GET_SKILL_NODE(250, PhaseNode_CreateTriggerNewPene);
    if (node250 != nullptr) node254->setTrigger(0, node250->getTriggerID());
    return node254;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(20042, 255) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 244, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(20042, 255) {
    auto node255 = GET_SKILL_NODE(255, PhaseNode_ActorFilterNewPene);
    if (node255 == nullptr) {
        node255 = new PhaseNode_ActorFilterNewPene(255, phase);
        node255->setHero(true);
        node255->setMinion(true);
        node255->setDestruct(true);
        node255->setShield(false);
        node255->setTotalCount(0);
        node255->setPerCount(1);
        CALL_REGISTER_SKILL_NODE(20042, 255, node255)
    }
    if (noInit == true) {
        return node255;
    }
    auto node241 = GET_SKILL_NODE(241, PhaseNode_CreateTriggerNewPene);
    if (node241 != nullptr) node255->setInput(node241->getOther());
    return node255;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(20042, 256) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 244, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(20042, 256) {
    auto node256 = GET_SKILL_NODE(256, PhaseNode_ActorFilterNewPene);
    if (node256 == nullptr) {
        node256 = new PhaseNode_ActorFilterNewPene(256, phase);
        node256->setHero(true);
        node256->setMinion(true);
        node256->setDestruct(true);
        node256->setShield(false);
        node256->setTotalCount(0);
        node256->setPerCount(1);
        CALL_REGISTER_SKILL_NODE(20042, 256, node256)
    }
    if (noInit == true) {
        return node256;
    }
    auto node250 = GET_SKILL_NODE(250, PhaseNode_CreateTriggerNewPene);
    if (node250 != nullptr) node256->setInput(node250->getOther());
    return node256;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(20042, 257) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 244, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(20042, 257) {
    auto node257 = GET_SKILL_NODE(257, PhaseNode_ActorFilterNewPene);
    if (node257 == nullptr) {
        node257 = new PhaseNode_ActorFilterNewPene(257, phase);
        node257->setHero(true);
        node257->setMinion(true);
        node257->setDestruct(true);
        node257->setShield(false);
        node257->setTotalCount(0);
        node257->setPerCount(1);
        CALL_REGISTER_SKILL_NODE(20042, 257, node257)
    }
    if (noInit == true) {
        return node257;
    }
    auto node251 = GET_SKILL_NODE(251, PhaseNode_CreateTriggerNewPene);
    if (node251 != nullptr) node257->setInput(node251->getOther());
    return node257;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(20042, 258) {
}

REGISTER_CREATE_SKILL_NODE(20042, 258) {
    auto node258 = GET_SKILL_NODE(258, PhaseNode_AddSkillBuffs);
    if (node258 == nullptr) {
        node258 = new PhaseNode_AddSkillBuffs(258, phase);
        node258->setConfigID({11});
        CALL_REGISTER_SKILL_NODE(20042, 258, node258)
    }
    if (noInit == true) {
        return node258;
    }
    auto node255 = GET_SKILL_NODE(255, PhaseNode_ActorFilterNewPene);
    auto node244 = GET_SKILL_NODE(244, PhaseNode_GetActorAttribute);
    if (node255 != nullptr) node258->setTarget(node255->getOutput());
    if (node244 != nullptr) node258->setAttribute(node244->getAttribute());
    return node258;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(20042, 259) {
}

REGISTER_CREATE_SKILL_NODE(20042, 259) {
    auto node259 = GET_SKILL_NODE(259, PhaseNode_AddSkillBuffs);
    if (node259 == nullptr) {
        node259 = new PhaseNode_AddSkillBuffs(259, phase);
        node259->setConfigID({11});
        CALL_REGISTER_SKILL_NODE(20042, 259, node259)
    }
    if (noInit == true) {
        return node259;
    }
    auto node256 = GET_SKILL_NODE(256, PhaseNode_ActorFilterNewPene);
    auto node244 = GET_SKILL_NODE(244, PhaseNode_GetActorAttribute);
    if (node256 != nullptr) node259->setTarget(node256->getOutput());
    if (node244 != nullptr) node259->setAttribute(node244->getAttribute());
    return node259;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(20042, 260) {
}

REGISTER_CREATE_SKILL_NODE(20042, 260) {
    auto node260 = GET_SKILL_NODE(260, PhaseNode_AddSkillBuffs);
    if (node260 == nullptr) {
        node260 = new PhaseNode_AddSkillBuffs(260, phase);
        node260->setConfigID({11});
        CALL_REGISTER_SKILL_NODE(20042, 260, node260)
    }
    if (noInit == true) {
        return node260;
    }
    auto node257 = GET_SKILL_NODE(257, PhaseNode_ActorFilterNewPene);
    auto node244 = GET_SKILL_NODE(244, PhaseNode_GetActorAttribute);
    if (node257 != nullptr) node260->setTarget(node257->getOutput());
    if (node244 != nullptr) node260->setAttribute(node244->getAttribute());
    return node260;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(20042, 261) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_ResetCD::TRIGGER_DONE, 262, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(20042, 261) {
    auto node261 = GET_SKILL_NODE(261, PhaseNode_ResetCD);
    if (node261 == nullptr) {
        node261 = new PhaseNode_ResetCD(261, phase);
        node261->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node261->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node261->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(20042, 261, node261)
    }
    if (noInit == true) {
        return node261;
    }
    return node261;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(20042, 262) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_PlayAnimation::TRIGGER_DONE, 263, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(20042, 262) {
    auto node262 = GET_SKILL_NODE(262, PhaseNode_PlayAnimation);
    if (node262 == nullptr) {
        node262 = new PhaseNode_PlayAnimation(262, phase);
        node262->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node262->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node262->setTarget(0U);
        node262->setAnimation("Skill2S1");
        node262->setParameter("");
        node262->setValue(false);
        CALL_REGISTER_SKILL_NODE(20042, 262, node262)
    }
    if (noInit == true) {
        return node262;
    }
    return node262;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(20042, 263) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlaySound::TRIGGER_DONE, 264, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(20042, 263) {
    auto node263 = GET_SKILL_NODE(263, PhaseNode_PlaySound);
    if (node263 == nullptr) {
        node263 = new PhaseNode_PlaySound(263, phase);
        node263->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node263->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node263->setSoundID("SE_MON2004_Skill_B_P0");
        node263->setTarget(0U);
        node263->setUsePos(false);
        node263->setPosX(.00f);
        node263->setPosY(.00f);
        node263->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(20042, 263, node263)
    }
    if (noInit == true) {
        return node263;
    }
    return node263;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(20042, 264) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_Delay::TRIGGER_DONE, 211, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(20042, 264) {
    auto node264 = GET_SKILL_NODE(264, PhaseNode_Delay);
    if (node264 == nullptr) {
        node264 = new PhaseNode_Delay(264, phase);
        node264->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(20042, 264, node264)
    }
    if (noInit == true) {
        return node264;
    }
    return node264;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(20042, 265) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetRotation>(PhaseNode_GetLocation::TRIGGER_DONE, 266, PhaseNode_GetRotation::FUNC_DO, &PhaseNode_GetRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(20042, 265) {
    auto node265 = GET_SKILL_NODE(265, PhaseNode_GetLocation);
    if (node265 == nullptr) {
        node265 = new PhaseNode_GetLocation(265, phase);
        node265->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node265->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(20042, 265, node265)
    }
    if (noInit == true) {
        return node265;
    }
    return node265;
}
//--------------------------------------------------------------------------------
// GetRotation
//
REGISTER_REGISTER_SKILL_NODE(20042, 266) {
    pnode->resizeTrigger(PhaseNode_GetRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_OffsetCalculate>(PhaseNode_GetRotation::TRIGGER_DONE, 267, PhaseNode_OffsetCalculate::FUNC_DO, &PhaseNode_OffsetCalculate::Do);
}

REGISTER_CREATE_SKILL_NODE(20042, 266) {
    auto node266 = GET_SKILL_NODE(266, PhaseNode_GetRotation);
    if (node266 == nullptr) {
        node266 = new PhaseNode_GetRotation(266, phase);
        node266->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node266->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(20042, 266, node266)
    }
    if (noInit == true) {
        return node266;
    }
    return node266;
}
//--------------------------------------------------------------------------------
// OffsetCalculate
//
REGISTER_REGISTER_SKILL_NODE(20042, 267) {
    pnode->resizeTrigger(PhaseNode_OffsetCalculate::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 268, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(20042, 267) {
    auto node267 = GET_SKILL_NODE(267, PhaseNode_OffsetCalculate);
    if (node267 == nullptr) {
        node267 = new PhaseNode_OffsetCalculate(267, phase);
        node267->setPosZ(.00f);
        node267->setOffsetX(.00f);
        node267->setOffsetY(2.00f);
        node267->setOffsetZ(.00f);
        node267->setRotOffset(.00f);
        CALL_REGISTER_SKILL_NODE(20042, 267, node267)
    }
    if (noInit == true) {
        return node267;
    }
    auto node265 = GET_SKILL_NODE(265, PhaseNode_GetLocation);
    auto node266 = GET_SKILL_NODE(266, PhaseNode_GetRotation);
    if (node265 != nullptr) node267->setPosX(node265->getX());
    if (node265 != nullptr) node267->setPosY(node265->getY());
    if (node266 != nullptr) node267->setRotation(node266->getAngle());
    return node267;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(20042, 268) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetRotation>(PhaseNode_GetLocation::TRIGGER_DONE, 269, PhaseNode_GetRotation::FUNC_DO, &PhaseNode_GetRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(20042, 268) {
    auto node268 = GET_SKILL_NODE(268, PhaseNode_GetLocation);
    if (node268 == nullptr) {
        node268 = new PhaseNode_GetLocation(268, phase);
        node268->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node268->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(20042, 268, node268)
    }
    if (noInit == true) {
        return node268;
    }
    return node268;
}
//--------------------------------------------------------------------------------
// GetRotation
//
REGISTER_REGISTER_SKILL_NODE(20042, 269) {
    pnode->resizeTrigger(PhaseNode_GetRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_OffsetCalculate>(PhaseNode_GetRotation::TRIGGER_DONE, 270, PhaseNode_OffsetCalculate::FUNC_DO, &PhaseNode_OffsetCalculate::Do);
}

REGISTER_CREATE_SKILL_NODE(20042, 269) {
    auto node269 = GET_SKILL_NODE(269, PhaseNode_GetRotation);
    if (node269 == nullptr) {
        node269 = new PhaseNode_GetRotation(269, phase);
        node269->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node269->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(20042, 269, node269)
    }
    if (noInit == true) {
        return node269;
    }
    return node269;
}
//--------------------------------------------------------------------------------
// OffsetCalculate
//
REGISTER_REGISTER_SKILL_NODE(20042, 270) {
    pnode->resizeTrigger(PhaseNode_OffsetCalculate::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 272, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(20042, 270) {
    auto node270 = GET_SKILL_NODE(270, PhaseNode_OffsetCalculate);
    if (node270 == nullptr) {
        node270 = new PhaseNode_OffsetCalculate(270, phase);
        node270->setPosZ(.00f);
        node270->setOffsetX(.00f);
        node270->setOffsetY(2.50f);
        node270->setOffsetZ(.20f);
        node270->setRotOffset(.00f);
        CALL_REGISTER_SKILL_NODE(20042, 270, node270)
    }
    if (noInit == true) {
        return node270;
    }
    auto node268 = GET_SKILL_NODE(268, PhaseNode_GetLocation);
    auto node269 = GET_SKILL_NODE(269, PhaseNode_GetRotation);
    if (node268 != nullptr) node270->setPosX(node268->getX());
    if (node268 != nullptr) node270->setPosY(node268->getY());
    if (node269 != nullptr) node270->setRotation(node269->getAngle());
    return node270;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(20042, 271) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_PlayEffect::TRIGGER_DONE, 274, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(20042, 271) {
    auto node271 = GET_SKILL_NODE(271, PhaseNode_PlayEffect);
    if (node271 == nullptr) {
        node271 = new PhaseNode_PlayEffect(271, phase);
        node271->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node271->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node271->setEffectID(1048);
        node271->setChangeColor(false);
        node271->setType(PhaseNode_PlayEffect::PlayEffect_Type::WithTarget);
        node271->getVars().reserve(5);
        node271->getVars().setVariable<uint64_t>(0, 0U);
        node271->getVars().setVariable<std::string>(1, "");
        node271->getVars().setVariable<float>(2, .00f);
        node271->getVars().setVariable<float>(3, .00f);
        node271->getVars().setVariable<float>(4, .00f);
        node271->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(20042, 271, node271)
    }
    if (noInit == true) {
        return node271;
    }
    auto node267 = GET_SKILL_NODE(267, PhaseNode_OffsetCalculate);
    if (node267 != nullptr) node271->getVars().setVariable<float>(2, node267->getOutPosX());
    if (node267 != nullptr) node271->getVars().setVariable<float>(3, node267->getOutPosY());
    if (node267 != nullptr) node271->getVars().setVariable<float>(4, node267->getOutPosZ());
    if (node267 != nullptr) node271->setRotation(node267->getOutRotation());
    return node271;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(20042, 272) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_FALSE, 273, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_TRUE, 271, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(20042, 272) {
    auto node272 = GET_SKILL_NODE(272, PhaseNode_If);
    if (node272 == nullptr) {
        node272 = new PhaseNode_If(272, phase);
        node272->setCondition(false);
        CALL_REGISTER_SKILL_NODE(20042, 272, node272)
    }
    if (noInit == true) {
        return node272;
    }
    return node272;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(20042, 273) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_PlayEffect::TRIGGER_DONE, 274, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(20042, 273) {
    auto node273 = GET_SKILL_NODE(273, PhaseNode_PlayEffect);
    if (node273 == nullptr) {
        node273 = new PhaseNode_PlayEffect(273, phase);
        node273->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node273->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node273->setEffectID(1048);
        node273->setChangeColor(false);
        node273->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node273->getVars().reserve(3);
        node273->getVars().setVariable<float>(0, .00f);
        node273->getVars().setVariable<float>(1, .00f);
        node273->getVars().setVariable<float>(2, .00f);
        node273->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(20042, 273, node273)
    }
    if (noInit == true) {
        return node273;
    }
    auto node267 = GET_SKILL_NODE(267, PhaseNode_OffsetCalculate);
    if (node267 != nullptr) node273->getVars().setVariable<float>(0, node267->getOutPosX());
    if (node267 != nullptr) node273->getVars().setVariable<float>(1, node267->getOutPosY());
    if (node267 != nullptr) node273->getVars().setVariable<float>(2, node267->getOutPosZ());
    if (node267 != nullptr) node273->setRotation(node267->getOutRotation());
    return node273;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(20042, 274) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 278, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_LESS, 275, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_CompareFloat::TRIGGER_LESS, 278, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(20042, 274) {
    auto node274 = GET_SKILL_NODE(274, PhaseNode_CompareFloat);
    if (node274 == nullptr) {
        node274 = new PhaseNode_CompareFloat(274, phase);
        node274->setA(.00f);
        node274->setB(.00f);
        CALL_REGISTER_SKILL_NODE(20042, 274, node274)
    }
    if (noInit == true) {
        return node274;
    }
    return node274;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(20042, 275) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StopEffect>(PhaseNode_Delay::TRIGGER_DONE, 276, PhaseNode_StopEffect::FUNC_DO, &PhaseNode_StopEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(20042, 275) {
    auto node275 = GET_SKILL_NODE(275, PhaseNode_Delay);
    if (node275 == nullptr) {
        node275 = new PhaseNode_Delay(275, phase);
        node275->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(20042, 275, node275)
    }
    if (noInit == true) {
        return node275;
    }
    return node275;
}
//--------------------------------------------------------------------------------
// StopEffect
//
REGISTER_REGISTER_SKILL_NODE(20042, 276) {
}

REGISTER_CREATE_SKILL_NODE(20042, 276) {
    auto node276 = GET_SKILL_NODE(276, PhaseNode_StopEffect);
    if (node276 == nullptr) {
        node276 = new PhaseNode_StopEffect(276, phase);
        node276->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node276->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node276->setEffectID(1048);
        CALL_REGISTER_SKILL_NODE(20042, 276, node276)
    }
    if (noInit == true) {
        return node276;
    }
    return node276;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(20042, 277) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_PlayEffect::TRIGGER_DONE, 280, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(20042, 277) {
    auto node277 = GET_SKILL_NODE(277, PhaseNode_PlayEffect);
    if (node277 == nullptr) {
        node277 = new PhaseNode_PlayEffect(277, phase);
        node277->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node277->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node277->setEffectID(1014);
        node277->setChangeColor(false);
        node277->setType(PhaseNode_PlayEffect::PlayEffect_Type::WithTarget);
        node277->getVars().reserve(5);
        node277->getVars().setVariable<uint64_t>(0, 0U);
        node277->getVars().setVariable<std::string>(1, "");
        node277->getVars().setVariable<float>(2, .00f);
        node277->getVars().setVariable<float>(3, .00f);
        node277->getVars().setVariable<float>(4, .00f);
        node277->setScale(2.50f);
        CALL_REGISTER_SKILL_NODE(20042, 277, node277)
    }
    if (noInit == true) {
        return node277;
    }
    auto node270 = GET_SKILL_NODE(270, PhaseNode_OffsetCalculate);
    if (node270 != nullptr) node277->getVars().setVariable<float>(2, node270->getOutPosX());
    if (node270 != nullptr) node277->getVars().setVariable<float>(3, node270->getOutPosY());
    if (node270 != nullptr) node277->getVars().setVariable<float>(4, node270->getOutPosZ());
    if (node270 != nullptr) node277->setRotation(node270->getOutRotation());
    return node277;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(20042, 278) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_FALSE, 279, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_TRUE, 277, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(20042, 278) {
    auto node278 = GET_SKILL_NODE(278, PhaseNode_If);
    if (node278 == nullptr) {
        node278 = new PhaseNode_If(278, phase);
        node278->setCondition(false);
        CALL_REGISTER_SKILL_NODE(20042, 278, node278)
    }
    if (noInit == true) {
        return node278;
    }
    return node278;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(20042, 279) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_PlayEffect::TRIGGER_DONE, 280, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(20042, 279) {
    auto node279 = GET_SKILL_NODE(279, PhaseNode_PlayEffect);
    if (node279 == nullptr) {
        node279 = new PhaseNode_PlayEffect(279, phase);
        node279->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node279->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node279->setEffectID(1014);
        node279->setChangeColor(false);
        node279->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node279->getVars().reserve(3);
        node279->getVars().setVariable<float>(0, .00f);
        node279->getVars().setVariable<float>(1, .00f);
        node279->getVars().setVariable<float>(2, .00f);
        node279->setScale(2.50f);
        CALL_REGISTER_SKILL_NODE(20042, 279, node279)
    }
    if (noInit == true) {
        return node279;
    }
    auto node270 = GET_SKILL_NODE(270, PhaseNode_OffsetCalculate);
    if (node270 != nullptr) node279->getVars().setVariable<float>(0, node270->getOutPosX());
    if (node270 != nullptr) node279->getVars().setVariable<float>(1, node270->getOutPosY());
    if (node270 != nullptr) node279->getVars().setVariable<float>(2, node270->getOutPosZ());
    if (node270 != nullptr) node279->setRotation(node270->getOutRotation());
    return node279;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(20042, 280) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 42, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_LESS, 281, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_LESS, 42, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(20042, 280) {
    auto node280 = GET_SKILL_NODE(280, PhaseNode_CompareFloat);
    if (node280 == nullptr) {
        node280 = new PhaseNode_CompareFloat(280, phase);
        node280->setA(.00f);
        node280->setB(1.30f);
        CALL_REGISTER_SKILL_NODE(20042, 280, node280)
    }
    if (noInit == true) {
        return node280;
    }
    return node280;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(20042, 281) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StopEffect>(PhaseNode_Delay::TRIGGER_DONE, 282, PhaseNode_StopEffect::FUNC_DO, &PhaseNode_StopEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(20042, 281) {
    auto node281 = GET_SKILL_NODE(281, PhaseNode_Delay);
    if (node281 == nullptr) {
        node281 = new PhaseNode_Delay(281, phase);
        node281->setTime(1.30f);
        CALL_REGISTER_SKILL_NODE(20042, 281, node281)
    }
    if (noInit == true) {
        return node281;
    }
    return node281;
}
//--------------------------------------------------------------------------------
// StopEffect
//
REGISTER_REGISTER_SKILL_NODE(20042, 282) {
}

REGISTER_CREATE_SKILL_NODE(20042, 282) {
    auto node282 = GET_SKILL_NODE(282, PhaseNode_StopEffect);
    if (node282 == nullptr) {
        node282 = new PhaseNode_StopEffect(282, phase);
        node282->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node282->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node282->setEffectID(1014);
        CALL_REGISTER_SKILL_NODE(20042, 282, node282)
    }
    if (noInit == true) {
        return node282;
    }
    return node282;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(20042, 283) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_Delay::TRIGGER_DONE, 285, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(20042, 283) {
    auto node283 = GET_SKILL_NODE(283, PhaseNode_Delay);
    if (node283 == nullptr) {
        node283 = new PhaseNode_Delay(283, phase);
        node283->setTime(.90f);
        CALL_REGISTER_SKILL_NODE(20042, 283, node283)
    }
    if (noInit == true) {
        return node283;
    }
    return node283;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(20042, 284) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 45, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(20042, 284) {
    auto node284 = GET_SKILL_NODE(284, PhaseNode_SkillEndNotify);
    if (node284 == nullptr) {
        node284 = new PhaseNode_SkillEndNotify(284, phase);
        node284->setReturnType(false);
        CALL_REGISTER_SKILL_NODE(20042, 284, node284)
    }
    if (noInit == true) {
        return node284;
    }
    return node284;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(20042, 285) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_FALSE, 286, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_TRUE, 284, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
}

REGISTER_CREATE_SKILL_NODE(20042, 285) {
    auto node285 = GET_SKILL_NODE(285, PhaseNode_If);
    if (node285 == nullptr) {
        node285 = new PhaseNode_If(285, phase);
        node285->setCondition(false);
        CALL_REGISTER_SKILL_NODE(20042, 285, node285)
    }
    if (noInit == true) {
        return node285;
    }
    return node285;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(20042, 286) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 45, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(20042, 286) {
    auto node286 = GET_SKILL_NODE(286, PhaseNode_SkillEndNotify);
    if (node286 == nullptr) {
        node286 = new PhaseNode_SkillEndNotify(286, phase);
        node286->setReturnType(true);
        CALL_REGISTER_SKILL_NODE(20042, 286, node286)
    }
    if (noInit == true) {
        return node286;
    }
    return node286;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(20042, 287) {
}

REGISTER_CREATE_SKILL_NODE(20042, 287) {
    auto node287 = GET_SKILL_NODE(287, PhaseNode_RaiseEvent);
    if (node287 == nullptr) {
        node287 = new PhaseNode_RaiseEvent(287, phase);
        node287->setEvent("MonsterInterrupt");
        node287->setTarget(0U);
        node287->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node287->setTypeParams(0, 0);
        node287->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(20042, 287, node287)
    }
    if (noInit == true) {
        return node287;
    }
    return node287;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(20042, 288) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_Detect::TRIGGER_ON, 291, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(20042, 288) {
    auto node288 = GET_SKILL_NODE(288, PhaseNode_Detect);
    if (node288 == nullptr) {
        node288 = new PhaseNode_Detect(288, phase);
        node288->setSelf(0U);
        node288->setEvent("MonsterInterrupt");
        node288->setType(PhaseNode_Detect::Detect_Type::Interrupt_Skill);
        node288->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(20042, 288, node288)
    }
    if (noInit == true) {
        return node288;
    }
    return node288;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(20042, 289) {
}

REGISTER_CREATE_SKILL_NODE(20042, 289) {
    auto node289 = GET_SKILL_NODE(289, PhaseNode_EndPhase);
    if (node289 == nullptr) {
        node289 = new PhaseNode_EndPhase(289, phase);
        node289->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node289->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(20042, 289, node289)
    }
    if (noInit == true) {
        return node289;
    }
    return node289;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(20042, 291) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_Delay::TRIGGER_DONE, 293, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(20042, 291) {
    auto node291 = GET_SKILL_NODE(291, PhaseNode_Delay);
    if (node291 == nullptr) {
        node291 = new PhaseNode_Delay(291, phase);
        node291->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(20042, 291, node291)
    }
    if (noInit == true) {
        return node291;
    }
    return node291;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(20042, 292) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 289, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(20042, 292) {
    auto node292 = GET_SKILL_NODE(292, PhaseNode_SkillEndNotify);
    if (node292 == nullptr) {
        node292 = new PhaseNode_SkillEndNotify(292, phase);
        node292->setReturnType(false);
        CALL_REGISTER_SKILL_NODE(20042, 292, node292)
    }
    if (noInit == true) {
        return node292;
    }
    return node292;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(20042, 293) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_FALSE, 294, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_TRUE, 292, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
}

REGISTER_CREATE_SKILL_NODE(20042, 293) {
    auto node293 = GET_SKILL_NODE(293, PhaseNode_If);
    if (node293 == nullptr) {
        node293 = new PhaseNode_If(293, phase);
        node293->setCondition(false);
        CALL_REGISTER_SKILL_NODE(20042, 293, node293)
    }
    if (noInit == true) {
        return node293;
    }
    return node293;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(20042, 294) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 289, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(20042, 294) {
    auto node294 = GET_SKILL_NODE(294, PhaseNode_SkillEndNotify);
    if (node294 == nullptr) {
        node294 = new PhaseNode_SkillEndNotify(294, phase);
        node294->setReturnType(true);
        CALL_REGISTER_SKILL_NODE(20042, 294, node294)
    }
    if (noInit == true) {
        return node294;
    }
    return node294;
}

//--------------------------------------------------------------------------------
// SkillCreator_20042
//
class SkillCreator_20042 : public SkillCreator {
public:
    SkillCreator_20042() {}
    virtual ~SkillCreator_20042() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_20042

//--------------------------------------------------------------------------------
// SkillPhase_20042
//
class SkillPhase_20042 : public SkillPhase {
public:
    SkillPhase_20042(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_20042() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(20042, 36) // StartPhase
        CASE_CREATE_SKILL_NODE(20042, 42) // Delay
        CASE_CREATE_SKILL_NODE(20042, 45) // EndPhase
        CASE_CREATE_SKILL_NODE(20042, 52) // TriggerUpdate
        CASE_CREATE_SKILL_NODE(20042, 104) // SpawnCollider
        CASE_CREATE_SKILL_NODE(20042, 173) // Detect
        CASE_CREATE_SKILL_NODE(20042, 174) // EndPhase
        CASE_CREATE_SKILL_NODE(20042, 176) // PlaySound
        CASE_CREATE_SKILL_NODE(20042, 211) // PlaySound
        CASE_CREATE_SKILL_NODE(20042, 237) // Delay
        CASE_CREATE_SKILL_NODE(20042, 239) // CameraShake
        CASE_CREATE_SKILL_NODE(20042, 241) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(20042, 242) // TriggerCheck
        CASE_CREATE_SKILL_NODE(20042, 243) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(20042, 244) // GetActorAttribute
        CASE_CREATE_SKILL_NODE(20042, 245) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(20042, 246) // CompareFloat
        CASE_CREATE_SKILL_NODE(20042, 247) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(20042, 248) // If
        CASE_CREATE_SKILL_NODE(20042, 249) // CompareFloat
        CASE_CREATE_SKILL_NODE(20042, 250) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(20042, 251) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(20042, 252) // TriggerCheck
        CASE_CREATE_SKILL_NODE(20042, 253) // TriggerCheck
        CASE_CREATE_SKILL_NODE(20042, 254) // TriggerCheck
        CASE_CREATE_SKILL_NODE(20042, 255) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(20042, 256) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(20042, 257) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(20042, 258) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(20042, 259) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(20042, 260) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(20042, 261) // ResetCD
        CASE_CREATE_SKILL_NODE(20042, 262) // PlayAnimation
        CASE_CREATE_SKILL_NODE(20042, 263) // PlaySound
        CASE_CREATE_SKILL_NODE(20042, 264) // Delay
        CASE_CREATE_SKILL_NODE(20042, 265) // GetLocation
        CASE_CREATE_SKILL_NODE(20042, 266) // GetRotation
        CASE_CREATE_SKILL_NODE(20042, 267) // OffsetCalculate
        CASE_CREATE_SKILL_NODE(20042, 268) // GetLocation
        CASE_CREATE_SKILL_NODE(20042, 269) // GetRotation
        CASE_CREATE_SKILL_NODE(20042, 270) // OffsetCalculate
        CASE_CREATE_SKILL_NODE(20042, 271) // PlayEffect
        CASE_CREATE_SKILL_NODE(20042, 272) // If
        CASE_CREATE_SKILL_NODE(20042, 273) // PlayEffect
        CASE_CREATE_SKILL_NODE(20042, 274) // CompareFloat
        CASE_CREATE_SKILL_NODE(20042, 275) // Delay
        CASE_CREATE_SKILL_NODE(20042, 276) // StopEffect
        CASE_CREATE_SKILL_NODE(20042, 277) // PlayEffect
        CASE_CREATE_SKILL_NODE(20042, 278) // If
        CASE_CREATE_SKILL_NODE(20042, 279) // PlayEffect
        CASE_CREATE_SKILL_NODE(20042, 280) // CompareFloat
        CASE_CREATE_SKILL_NODE(20042, 281) // Delay
        CASE_CREATE_SKILL_NODE(20042, 282) // StopEffect
        CASE_CREATE_SKILL_NODE(20042, 283) // Delay
        CASE_CREATE_SKILL_NODE(20042, 284) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(20042, 285) // If
        CASE_CREATE_SKILL_NODE(20042, 286) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(20042, 287) // RaiseEvent
        CASE_CREATE_SKILL_NODE(20042, 288) // Detect
        CASE_CREATE_SKILL_NODE(20042, 289) // EndPhase
        CASE_CREATE_SKILL_NODE(20042, 291) // Delay
        CASE_CREATE_SKILL_NODE(20042, 292) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(20042, 293) // If
        CASE_CREATE_SKILL_NODE(20042, 294) // SkillEndNotify
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_20042

SkillLogic* SkillCreator_20042::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //创建阶段phase
    auto phase = new SkillPhase_20042(1, logic, 3);
    //设置phase执行器
    phase->setRunPhaseNode(1, 36);
    phase->setRunPhaseNode(2, 52);
    phase->setDetectPhaseNode(3, 173);
    phase->setDetectPhaseNode(3, 288);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_20042::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
