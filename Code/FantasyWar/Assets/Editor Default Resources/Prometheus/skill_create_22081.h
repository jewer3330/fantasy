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
REGISTER_REGISTER_SKILL_NODE(22081, 2) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_StartPhase::TRIGGER_START, 106, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_StartPhase::TRIGGER_START, 108, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_StartPhase::TRIGGER_START, 102, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_StartPhase::TRIGGER_START, 86, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(22081, 2) {
    auto node2 = GET_SKILL_NODE(2, PhaseNode_StartPhase);
    if (node2 == nullptr) {
        node2 = new PhaseNode_StartPhase(2, phase);
        CALL_REGISTER_SKILL_NODE(22081, 2, node2)
    }
    if (noInit == true) {
        return node2;
    }
    return node2;
}
//--------------------------------------------------------------------------------
// TriggerUpdate
//
REGISTER_REGISTER_SKILL_NODE(22081, 4) {
}

REGISTER_CREATE_SKILL_NODE(22081, 4) {
    auto node4 = GET_SKILL_NODE(4, PhaseNode_TriggerUpdate);
    if (node4 == nullptr) {
        node4 = new PhaseNode_TriggerUpdate(4, phase);
        CALL_REGISTER_SKILL_NODE(22081, 4, node4)
    }
    if (noInit == true) {
        return node4;
    }
    return node4;
}
//--------------------------------------------------------------------------------
// SpawnCollider
//
REGISTER_REGISTER_SKILL_NODE(22081, 24) {
    pnode->resizeTrigger(PhaseNode_SpawnCollider::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_SpawnCollider::TRIGGER_DONE, 69, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_SpawnCollider::TRIGGER_DONE, 61, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(22081, 24) {
    auto node24 = GET_SKILL_NODE(24, PhaseNode_SpawnCollider);
    if (node24 == nullptr) {
        node24 = new PhaseNode_SpawnCollider(24, phase);
        node24->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node24->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node24->setMesh("");
        node24->setMeshScale(.00f);
        node24->setEffectID(0);
        node24->setEffectScale(.00f);
        node24->setType(PhaseNode_SpawnCollider::SpawnCollider_Type::Circle);
        node24->setTypeParams(0, 2.00f);
        node24->setTime(.30f);
        node24->setreentry(false);
        node24->setCheckPeneSound(false);
        CALL_REGISTER_SKILL_NODE(22081, 24, node24)
    }
    if (noInit == true) {
        return node24;
    }
    auto node101 = GET_SKILL_NODE(101, PhaseNode_OffsetCalculate);
    if (node101 != nullptr) node24->setPosX(node101->getOutPosX());
    if (node101 != nullptr) node24->setPosY(node101->getOutPosY());
    if (node101 != nullptr) node24->setPosZ(node101->getOutPosZ());
    if (node101 != nullptr) node24->setRotation(node101->getOutRotation());
    return node24;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(22081, 39) {
}

REGISTER_CREATE_SKILL_NODE(22081, 39) {
    auto node39 = GET_SKILL_NODE(39, PhaseNode_EndPhase);
    if (node39 == nullptr) {
        node39 = new PhaseNode_EndPhase(39, phase);
        node39->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node39->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(22081, 39, node39)
    }
    if (noInit == true) {
        return node39;
    }
    return node39;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(22081, 46) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_Detect::TRIGGER_ON, 48, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(22081, 46) {
    auto node46 = GET_SKILL_NODE(46, PhaseNode_Detect);
    if (node46 == nullptr) {
        node46 = new PhaseNode_Detect(46, phase);
        node46->setSelf(0U);
        node46->setEvent("");
        node46->setType(PhaseNode_Detect::Detect_Type::Actor_Dead);
        node46->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(22081, 46, node46)
    }
    if (noInit == true) {
        return node46;
    }
    return node46;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(22081, 48) {
}

REGISTER_CREATE_SKILL_NODE(22081, 48) {
    auto node48 = GET_SKILL_NODE(48, PhaseNode_EndPhase);
    if (node48 == nullptr) {
        node48 = new PhaseNode_EndPhase(48, phase);
        node48->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node48->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(22081, 48, node48)
    }
    if (noInit == true) {
        return node48;
    }
    return node48;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22081, 56) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_Delay::TRIGGER_DONE, 99, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(22081, 56) {
    auto node56 = GET_SKILL_NODE(56, PhaseNode_Delay);
    if (node56 == nullptr) {
        node56 = new PhaseNode_Delay(56, phase);
        node56->setTime(.50f);
        CALL_REGISTER_SKILL_NODE(22081, 56, node56)
    }
    if (noInit == true) {
        return node56;
    }
    return node56;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(22081, 61) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlaySound::TRIGGER_DONE, 82, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(22081, 61) {
    auto node61 = GET_SKILL_NODE(61, PhaseNode_PlaySound);
    if (node61 == nullptr) {
        node61 = new PhaseNode_PlaySound(61, phase);
        node61->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node61->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node61->setSoundID("SE_MON2201_ATK2_P2");
        node61->setTarget(0U);
        node61->setUsePos(false);
        node61->setPosX(.00f);
        node61->setPosY(.00f);
        node61->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(22081, 61, node61)
    }
    if (noInit == true) {
        return node61;
    }
    return node61;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(22081, 62) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 74, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 76, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(22081, 62) {
    auto node62 = GET_SKILL_NODE(62, PhaseNode_CreateTriggerNewPene);
    if (node62 == nullptr) {
        node62 = new PhaseNode_CreateTriggerNewPene(62, phase);
        node62->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::In);
        node62->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node62->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Enemy);
        node62->setOnHero(true);
        node62->setOnMinion(true);
        node62->setOnDestruct(true);
        node62->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(22081, 62, node62)
    }
    if (noInit == true) {
        return node62;
    }
    auto node24 = GET_SKILL_NODE(24, PhaseNode_SpawnCollider);
    if (node24 != nullptr) node62->setColliderID(node24->getColliderID());
    return node62;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(22081, 63) {
}

REGISTER_CREATE_SKILL_NODE(22081, 63) {
    auto node63 = GET_SKILL_NODE(63, PhaseNode_TriggerCheck);
    if (node63 == nullptr) {
        node63 = new PhaseNode_TriggerCheck(63, phase);
        auto node4 = GET_SKILL_NODE(4, PhaseNode_TriggerUpdate);
        if (node4 != nullptr) node4->addTriggerCheck(node63);
        
        CALL_REGISTER_SKILL_NODE(22081, 63, node63)
    }
    if (noInit == true) {
        return node63;
    }
    auto node72 = GET_SKILL_NODE(72, PhaseNode_CreateTriggerNewPene);
    if (node72 != nullptr) node63->setTrigger(0, node72->getTriggerID());
    return node63;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(22081, 64) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 65, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(22081, 64) {
    auto node64 = GET_SKILL_NODE(64, PhaseNode_ActorFilterNewPene);
    if (node64 == nullptr) {
        node64 = new PhaseNode_ActorFilterNewPene(64, phase);
        node64->setHero(true);
        node64->setMinion(true);
        node64->setDestruct(true);
        node64->setShield(false);
        node64->setTotalCount(0);
        node64->setPerCount(1);
        CALL_REGISTER_SKILL_NODE(22081, 64, node64)
    }
    if (noInit == true) {
        return node64;
    }
    auto node68 = GET_SKILL_NODE(68, PhaseNode_CreateTriggerNewPene);
    if (node68 != nullptr) node64->setInput(node68->getOther());
    return node64;
}
//--------------------------------------------------------------------------------
// GetActorAttribute
//
REGISTER_REGISTER_SKILL_NODE(22081, 65) {
    pnode->resizeTrigger(PhaseNode_GetActorAttribute::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 66, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 79, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 80, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 81, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
}

REGISTER_CREATE_SKILL_NODE(22081, 65) {
    auto node65 = GET_SKILL_NODE(65, PhaseNode_GetActorAttribute);
    if (node65 == nullptr) {
        node65 = new PhaseNode_GetActorAttribute(65, phase);
        node65->setTarget(0U);
        node65->setType({202});
        CALL_REGISTER_SKILL_NODE(22081, 65, node65)
    }
    if (noInit == true) {
        return node65;
    }
    return node65;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(22081, 66) {
}

REGISTER_CREATE_SKILL_NODE(22081, 66) {
    auto node66 = GET_SKILL_NODE(66, PhaseNode_AddSkillBuffs);
    if (node66 == nullptr) {
        node66 = new PhaseNode_AddSkillBuffs(66, phase);
        node66->setConfigID({11});
        CALL_REGISTER_SKILL_NODE(22081, 66, node66)
    }
    if (noInit == true) {
        return node66;
    }
    auto node64 = GET_SKILL_NODE(64, PhaseNode_ActorFilterNewPene);
    auto node65 = GET_SKILL_NODE(65, PhaseNode_GetActorAttribute);
    if (node64 != nullptr) node66->setTarget(node64->getOutput());
    if (node65 != nullptr) node66->setAttribute(node65->getAttribute());
    return node66;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(22081, 67) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 62, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_LESS, 68, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
}

REGISTER_CREATE_SKILL_NODE(22081, 67) {
    auto node67 = GET_SKILL_NODE(67, PhaseNode_CompareFloat);
    if (node67 == nullptr) {
        node67 = new PhaseNode_CompareFloat(67, phase);
        node67->setA(.00f);
        node67->setB(.00f);
        CALL_REGISTER_SKILL_NODE(22081, 67, node67)
    }
    if (noInit == true) {
        return node67;
    }
    return node67;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(22081, 68) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 73, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 64, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(22081, 68) {
    auto node68 = GET_SKILL_NODE(68, PhaseNode_CreateTriggerNewPene);
    if (node68 == nullptr) {
        node68 = new PhaseNode_CreateTriggerNewPene(68, phase);
        node68->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::Tick);
        node68->setTypeParams(0, .00f);
        node68->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node68->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Enemy);
        node68->setOnHero(true);
        node68->setOnMinion(true);
        node68->setOnDestruct(true);
        node68->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(22081, 68, node68)
    }
    if (noInit == true) {
        return node68;
    }
    auto node24 = GET_SKILL_NODE(24, PhaseNode_SpawnCollider);
    if (node24 != nullptr) node68->setColliderID(node24->getColliderID());
    return node68;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(22081, 69) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_If::TRIGGER_FALSE, 70, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_If::TRIGGER_TRUE, 67, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(22081, 69) {
    auto node69 = GET_SKILL_NODE(69, PhaseNode_If);
    if (node69 == nullptr) {
        node69 = new PhaseNode_If(69, phase);
        node69->setCondition(true);
        CALL_REGISTER_SKILL_NODE(22081, 69, node69)
    }
    if (noInit == true) {
        return node69;
    }
    return node69;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(22081, 70) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 72, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_LESS, 71, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
}

REGISTER_CREATE_SKILL_NODE(22081, 70) {
    auto node70 = GET_SKILL_NODE(70, PhaseNode_CompareFloat);
    if (node70 == nullptr) {
        node70 = new PhaseNode_CompareFloat(70, phase);
        node70->setA(.00f);
        node70->setB(.00f);
        CALL_REGISTER_SKILL_NODE(22081, 70, node70)
    }
    if (noInit == true) {
        return node70;
    }
    return node70;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(22081, 71) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 75, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 77, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(22081, 71) {
    auto node71 = GET_SKILL_NODE(71, PhaseNode_CreateTriggerNewPene);
    if (node71 == nullptr) {
        node71 = new PhaseNode_CreateTriggerNewPene(71, phase);
        node71->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::Tick);
        node71->setTypeParams(0, .00f);
        node71->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node71->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Friend);
        node71->setOnHero(true);
        node71->setOnMinion(true);
        node71->setOnDestruct(true);
        node71->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(22081, 71, node71)
    }
    if (noInit == true) {
        return node71;
    }
    auto node24 = GET_SKILL_NODE(24, PhaseNode_SpawnCollider);
    if (node24 != nullptr) node71->setColliderID(node24->getColliderID());
    return node71;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(22081, 72) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 63, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 78, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(22081, 72) {
    auto node72 = GET_SKILL_NODE(72, PhaseNode_CreateTriggerNewPene);
    if (node72 == nullptr) {
        node72 = new PhaseNode_CreateTriggerNewPene(72, phase);
        node72->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::In);
        node72->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node72->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Friend);
        node72->setOnHero(true);
        node72->setOnMinion(true);
        node72->setOnDestruct(true);
        node72->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(22081, 72, node72)
    }
    if (noInit == true) {
        return node72;
    }
    auto node24 = GET_SKILL_NODE(24, PhaseNode_SpawnCollider);
    if (node24 != nullptr) node72->setColliderID(node24->getColliderID());
    return node72;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(22081, 73) {
}

REGISTER_CREATE_SKILL_NODE(22081, 73) {
    auto node73 = GET_SKILL_NODE(73, PhaseNode_TriggerCheck);
    if (node73 == nullptr) {
        node73 = new PhaseNode_TriggerCheck(73, phase);
        auto node4 = GET_SKILL_NODE(4, PhaseNode_TriggerUpdate);
        if (node4 != nullptr) node4->addTriggerCheck(node73);
        
        CALL_REGISTER_SKILL_NODE(22081, 73, node73)
    }
    if (noInit == true) {
        return node73;
    }
    auto node68 = GET_SKILL_NODE(68, PhaseNode_CreateTriggerNewPene);
    if (node68 != nullptr) node73->setTrigger(0, node68->getTriggerID());
    return node73;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(22081, 74) {
}

REGISTER_CREATE_SKILL_NODE(22081, 74) {
    auto node74 = GET_SKILL_NODE(74, PhaseNode_TriggerCheck);
    if (node74 == nullptr) {
        node74 = new PhaseNode_TriggerCheck(74, phase);
        auto node4 = GET_SKILL_NODE(4, PhaseNode_TriggerUpdate);
        if (node4 != nullptr) node4->addTriggerCheck(node74);
        
        CALL_REGISTER_SKILL_NODE(22081, 74, node74)
    }
    if (noInit == true) {
        return node74;
    }
    auto node62 = GET_SKILL_NODE(62, PhaseNode_CreateTriggerNewPene);
    if (node62 != nullptr) node74->setTrigger(0, node62->getTriggerID());
    return node74;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(22081, 75) {
}

REGISTER_CREATE_SKILL_NODE(22081, 75) {
    auto node75 = GET_SKILL_NODE(75, PhaseNode_TriggerCheck);
    if (node75 == nullptr) {
        node75 = new PhaseNode_TriggerCheck(75, phase);
        auto node4 = GET_SKILL_NODE(4, PhaseNode_TriggerUpdate);
        if (node4 != nullptr) node4->addTriggerCheck(node75);
        
        CALL_REGISTER_SKILL_NODE(22081, 75, node75)
    }
    if (noInit == true) {
        return node75;
    }
    auto node71 = GET_SKILL_NODE(71, PhaseNode_CreateTriggerNewPene);
    if (node71 != nullptr) node75->setTrigger(0, node71->getTriggerID());
    return node75;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(22081, 76) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 65, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(22081, 76) {
    auto node76 = GET_SKILL_NODE(76, PhaseNode_ActorFilterNewPene);
    if (node76 == nullptr) {
        node76 = new PhaseNode_ActorFilterNewPene(76, phase);
        node76->setHero(true);
        node76->setMinion(true);
        node76->setDestruct(true);
        node76->setShield(false);
        node76->setTotalCount(0);
        node76->setPerCount(1);
        CALL_REGISTER_SKILL_NODE(22081, 76, node76)
    }
    if (noInit == true) {
        return node76;
    }
    auto node62 = GET_SKILL_NODE(62, PhaseNode_CreateTriggerNewPene);
    if (node62 != nullptr) node76->setInput(node62->getOther());
    return node76;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(22081, 77) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 65, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(22081, 77) {
    auto node77 = GET_SKILL_NODE(77, PhaseNode_ActorFilterNewPene);
    if (node77 == nullptr) {
        node77 = new PhaseNode_ActorFilterNewPene(77, phase);
        node77->setHero(true);
        node77->setMinion(true);
        node77->setDestruct(true);
        node77->setShield(false);
        node77->setTotalCount(0);
        node77->setPerCount(1);
        CALL_REGISTER_SKILL_NODE(22081, 77, node77)
    }
    if (noInit == true) {
        return node77;
    }
    auto node71 = GET_SKILL_NODE(71, PhaseNode_CreateTriggerNewPene);
    if (node71 != nullptr) node77->setInput(node71->getOther());
    return node77;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(22081, 78) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 65, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(22081, 78) {
    auto node78 = GET_SKILL_NODE(78, PhaseNode_ActorFilterNewPene);
    if (node78 == nullptr) {
        node78 = new PhaseNode_ActorFilterNewPene(78, phase);
        node78->setHero(true);
        node78->setMinion(true);
        node78->setDestruct(true);
        node78->setShield(false);
        node78->setTotalCount(0);
        node78->setPerCount(1);
        CALL_REGISTER_SKILL_NODE(22081, 78, node78)
    }
    if (noInit == true) {
        return node78;
    }
    auto node72 = GET_SKILL_NODE(72, PhaseNode_CreateTriggerNewPene);
    if (node72 != nullptr) node78->setInput(node72->getOther());
    return node78;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(22081, 79) {
}

REGISTER_CREATE_SKILL_NODE(22081, 79) {
    auto node79 = GET_SKILL_NODE(79, PhaseNode_AddSkillBuffs);
    if (node79 == nullptr) {
        node79 = new PhaseNode_AddSkillBuffs(79, phase);
        node79->setConfigID({11});
        CALL_REGISTER_SKILL_NODE(22081, 79, node79)
    }
    if (noInit == true) {
        return node79;
    }
    auto node76 = GET_SKILL_NODE(76, PhaseNode_ActorFilterNewPene);
    auto node65 = GET_SKILL_NODE(65, PhaseNode_GetActorAttribute);
    if (node76 != nullptr) node79->setTarget(node76->getOutput());
    if (node65 != nullptr) node79->setAttribute(node65->getAttribute());
    return node79;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(22081, 80) {
}

REGISTER_CREATE_SKILL_NODE(22081, 80) {
    auto node80 = GET_SKILL_NODE(80, PhaseNode_AddSkillBuffs);
    if (node80 == nullptr) {
        node80 = new PhaseNode_AddSkillBuffs(80, phase);
        node80->setConfigID({11});
        CALL_REGISTER_SKILL_NODE(22081, 80, node80)
    }
    if (noInit == true) {
        return node80;
    }
    auto node77 = GET_SKILL_NODE(77, PhaseNode_ActorFilterNewPene);
    auto node65 = GET_SKILL_NODE(65, PhaseNode_GetActorAttribute);
    if (node77 != nullptr) node80->setTarget(node77->getOutput());
    if (node65 != nullptr) node80->setAttribute(node65->getAttribute());
    return node80;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(22081, 81) {
}

REGISTER_CREATE_SKILL_NODE(22081, 81) {
    auto node81 = GET_SKILL_NODE(81, PhaseNode_AddSkillBuffs);
    if (node81 == nullptr) {
        node81 = new PhaseNode_AddSkillBuffs(81, phase);
        node81->setConfigID({11});
        CALL_REGISTER_SKILL_NODE(22081, 81, node81)
    }
    if (noInit == true) {
        return node81;
    }
    auto node78 = GET_SKILL_NODE(78, PhaseNode_ActorFilterNewPene);
    auto node65 = GET_SKILL_NODE(65, PhaseNode_GetActorAttribute);
    if (node78 != nullptr) node81->setTarget(node78->getOutput());
    if (node65 != nullptr) node81->setAttribute(node65->getAttribute());
    return node81;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22081, 82) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_Delay::TRIGGER_DONE, 84, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(22081, 82) {
    auto node82 = GET_SKILL_NODE(82, PhaseNode_Delay);
    if (node82 == nullptr) {
        node82 = new PhaseNode_Delay(82, phase);
        node82->setTime(.80f);
        CALL_REGISTER_SKILL_NODE(22081, 82, node82)
    }
    if (noInit == true) {
        return node82;
    }
    return node82;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(22081, 83) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 39, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(22081, 83) {
    auto node83 = GET_SKILL_NODE(83, PhaseNode_SkillEndNotify);
    if (node83 == nullptr) {
        node83 = new PhaseNode_SkillEndNotify(83, phase);
        node83->setReturnType(false);
        CALL_REGISTER_SKILL_NODE(22081, 83, node83)
    }
    if (noInit == true) {
        return node83;
    }
    return node83;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(22081, 84) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_FALSE, 85, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_TRUE, 83, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
}

REGISTER_CREATE_SKILL_NODE(22081, 84) {
    auto node84 = GET_SKILL_NODE(84, PhaseNode_If);
    if (node84 == nullptr) {
        node84 = new PhaseNode_If(84, phase);
        node84->setCondition(false);
        CALL_REGISTER_SKILL_NODE(22081, 84, node84)
    }
    if (noInit == true) {
        return node84;
    }
    return node84;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(22081, 85) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 39, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(22081, 85) {
    auto node85 = GET_SKILL_NODE(85, PhaseNode_SkillEndNotify);
    if (node85 == nullptr) {
        node85 = new PhaseNode_SkillEndNotify(85, phase);
        node85->setReturnType(true);
        CALL_REGISTER_SKILL_NODE(22081, 85, node85)
    }
    if (noInit == true) {
        return node85;
    }
    return node85;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(22081, 86) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_ResetCD::TRIGGER_DONE, 87, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(22081, 86) {
    auto node86 = GET_SKILL_NODE(86, PhaseNode_ResetCD);
    if (node86 == nullptr) {
        node86 = new PhaseNode_ResetCD(86, phase);
        node86->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node86->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node86->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(22081, 86, node86)
    }
    if (noInit == true) {
        return node86;
    }
    return node86;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(22081, 87) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_PlayAnimation::TRIGGER_DONE, 88, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(22081, 87) {
    auto node87 = GET_SKILL_NODE(87, PhaseNode_PlayAnimation);
    if (node87 == nullptr) {
        node87 = new PhaseNode_PlayAnimation(87, phase);
        node87->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node87->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node87->setTarget(0U);
        node87->setAnimation("Skill1S1");
        node87->setParameter("");
        node87->setValue(false);
        CALL_REGISTER_SKILL_NODE(22081, 87, node87)
    }
    if (noInit == true) {
        return node87;
    }
    return node87;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(22081, 88) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlaySound::TRIGGER_DONE, 89, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(22081, 88) {
    auto node88 = GET_SKILL_NODE(88, PhaseNode_PlaySound);
    if (node88 == nullptr) {
        node88 = new PhaseNode_PlaySound(88, phase);
        node88->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node88->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node88->setSoundID("");
        node88->setTarget(0U);
        node88->setUsePos(false);
        node88->setPosX(.00f);
        node88->setPosY(.00f);
        node88->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(22081, 88, node88)
    }
    if (noInit == true) {
        return node88;
    }
    return node88;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22081, 89) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_Delay::TRIGGER_DONE, 90, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(22081, 89) {
    auto node89 = GET_SKILL_NODE(89, PhaseNode_Delay);
    if (node89 == nullptr) {
        node89 = new PhaseNode_Delay(89, phase);
        node89->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(22081, 89, node89)
    }
    if (noInit == true) {
        return node89;
    }
    return node89;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(22081, 90) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetRotation>(PhaseNode_GetLocation::TRIGGER_DONE, 91, PhaseNode_GetRotation::FUNC_DO, &PhaseNode_GetRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(22081, 90) {
    auto node90 = GET_SKILL_NODE(90, PhaseNode_GetLocation);
    if (node90 == nullptr) {
        node90 = new PhaseNode_GetLocation(90, phase);
        node90->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node90->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(22081, 90, node90)
    }
    if (noInit == true) {
        return node90;
    }
    return node90;
}
//--------------------------------------------------------------------------------
// GetRotation
//
REGISTER_REGISTER_SKILL_NODE(22081, 91) {
    pnode->resizeTrigger(PhaseNode_GetRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_OffsetCalculate>(PhaseNode_GetRotation::TRIGGER_DONE, 92, PhaseNode_OffsetCalculate::FUNC_DO, &PhaseNode_OffsetCalculate::Do);
}

REGISTER_CREATE_SKILL_NODE(22081, 91) {
    auto node91 = GET_SKILL_NODE(91, PhaseNode_GetRotation);
    if (node91 == nullptr) {
        node91 = new PhaseNode_GetRotation(91, phase);
        node91->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node91->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(22081, 91, node91)
    }
    if (noInit == true) {
        return node91;
    }
    return node91;
}
//--------------------------------------------------------------------------------
// OffsetCalculate
//
REGISTER_REGISTER_SKILL_NODE(22081, 92) {
    pnode->resizeTrigger(PhaseNode_OffsetCalculate::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 94, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(22081, 92) {
    auto node92 = GET_SKILL_NODE(92, PhaseNode_OffsetCalculate);
    if (node92 == nullptr) {
        node92 = new PhaseNode_OffsetCalculate(92, phase);
        node92->setPosZ(.00f);
        node92->setOffsetX(.00f);
        node92->setOffsetY(.00f);
        node92->setOffsetZ(.00f);
        node92->setRotOffset(.00f);
        CALL_REGISTER_SKILL_NODE(22081, 92, node92)
    }
    if (noInit == true) {
        return node92;
    }
    auto node90 = GET_SKILL_NODE(90, PhaseNode_GetLocation);
    auto node91 = GET_SKILL_NODE(91, PhaseNode_GetRotation);
    if (node90 != nullptr) node92->setPosX(node90->getX());
    if (node90 != nullptr) node92->setPosY(node90->getY());
    if (node91 != nullptr) node92->setRotation(node91->getAngle());
    return node92;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(22081, 93) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_PlayEffect::TRIGGER_DONE, 96, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(22081, 93) {
    auto node93 = GET_SKILL_NODE(93, PhaseNode_PlayEffect);
    if (node93 == nullptr) {
        node93 = new PhaseNode_PlayEffect(93, phase);
        node93->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node93->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node93->setEffectID(220111);
        node93->setChangeColor(false);
        node93->setType(PhaseNode_PlayEffect::PlayEffect_Type::WithTarget);
        node93->getVars().reserve(5);
        node93->getVars().setVariable<uint64_t>(0, 0U);
        node93->getVars().setVariable<std::string>(1, "");
        node93->getVars().setVariable<float>(2, .00f);
        node93->getVars().setVariable<float>(3, .00f);
        node93->getVars().setVariable<float>(4, .00f);
        node93->setScale(.00f);
        CALL_REGISTER_SKILL_NODE(22081, 93, node93)
    }
    if (noInit == true) {
        return node93;
    }
    auto node92 = GET_SKILL_NODE(92, PhaseNode_OffsetCalculate);
    if (node92 != nullptr) node93->getVars().setVariable<float>(2, node92->getOutPosX());
    if (node92 != nullptr) node93->getVars().setVariable<float>(3, node92->getOutPosY());
    if (node92 != nullptr) node93->setRotation(node92->getOutRotation());
    return node93;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(22081, 94) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_FALSE, 95, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_TRUE, 93, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(22081, 94) {
    auto node94 = GET_SKILL_NODE(94, PhaseNode_If);
    if (node94 == nullptr) {
        node94 = new PhaseNode_If(94, phase);
        node94->setCondition(false);
        CALL_REGISTER_SKILL_NODE(22081, 94, node94)
    }
    if (noInit == true) {
        return node94;
    }
    return node94;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(22081, 95) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_PlayEffect::TRIGGER_DONE, 96, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(22081, 95) {
    auto node95 = GET_SKILL_NODE(95, PhaseNode_PlayEffect);
    if (node95 == nullptr) {
        node95 = new PhaseNode_PlayEffect(95, phase);
        node95->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node95->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node95->setEffectID(220111);
        node95->setChangeColor(false);
        node95->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node95->getVars().reserve(3);
        node95->getVars().setVariable<float>(0, .00f);
        node95->getVars().setVariable<float>(1, .00f);
        node95->getVars().setVariable<float>(2, .00f);
        node95->setScale(.00f);
        CALL_REGISTER_SKILL_NODE(22081, 95, node95)
    }
    if (noInit == true) {
        return node95;
    }
    auto node92 = GET_SKILL_NODE(92, PhaseNode_OffsetCalculate);
    if (node92 != nullptr) node95->getVars().setVariable<float>(0, node92->getOutPosX());
    if (node92 != nullptr) node95->getVars().setVariable<float>(1, node92->getOutPosY());
    if (node92 != nullptr) node95->setRotation(node92->getOutRotation());
    return node95;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(22081, 96) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 56, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_LESS, 56, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_LESS, 97, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(22081, 96) {
    auto node96 = GET_SKILL_NODE(96, PhaseNode_CompareFloat);
    if (node96 == nullptr) {
        node96 = new PhaseNode_CompareFloat(96, phase);
        node96->setA(.00f);
        node96->setB(.00f);
        CALL_REGISTER_SKILL_NODE(22081, 96, node96)
    }
    if (noInit == true) {
        return node96;
    }
    return node96;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22081, 97) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StopEffect>(PhaseNode_Delay::TRIGGER_DONE, 98, PhaseNode_StopEffect::FUNC_DO, &PhaseNode_StopEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(22081, 97) {
    auto node97 = GET_SKILL_NODE(97, PhaseNode_Delay);
    if (node97 == nullptr) {
        node97 = new PhaseNode_Delay(97, phase);
        node97->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(22081, 97, node97)
    }
    if (noInit == true) {
        return node97;
    }
    return node97;
}
//--------------------------------------------------------------------------------
// StopEffect
//
REGISTER_REGISTER_SKILL_NODE(22081, 98) {
}

REGISTER_CREATE_SKILL_NODE(22081, 98) {
    auto node98 = GET_SKILL_NODE(98, PhaseNode_StopEffect);
    if (node98 == nullptr) {
        node98 = new PhaseNode_StopEffect(98, phase);
        node98->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node98->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node98->setEffectID(220111);
        CALL_REGISTER_SKILL_NODE(22081, 98, node98)
    }
    if (noInit == true) {
        return node98;
    }
    return node98;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(22081, 99) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetRotation>(PhaseNode_GetLocation::TRIGGER_DONE, 100, PhaseNode_GetRotation::FUNC_DO, &PhaseNode_GetRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(22081, 99) {
    auto node99 = GET_SKILL_NODE(99, PhaseNode_GetLocation);
    if (node99 == nullptr) {
        node99 = new PhaseNode_GetLocation(99, phase);
        node99->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node99->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(22081, 99, node99)
    }
    if (noInit == true) {
        return node99;
    }
    return node99;
}
//--------------------------------------------------------------------------------
// GetRotation
//
REGISTER_REGISTER_SKILL_NODE(22081, 100) {
    pnode->resizeTrigger(PhaseNode_GetRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_OffsetCalculate>(PhaseNode_GetRotation::TRIGGER_DONE, 101, PhaseNode_OffsetCalculate::FUNC_DO, &PhaseNode_OffsetCalculate::Do);
}

REGISTER_CREATE_SKILL_NODE(22081, 100) {
    auto node100 = GET_SKILL_NODE(100, PhaseNode_GetRotation);
    if (node100 == nullptr) {
        node100 = new PhaseNode_GetRotation(100, phase);
        node100->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node100->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(22081, 100, node100)
    }
    if (noInit == true) {
        return node100;
    }
    return node100;
}
//--------------------------------------------------------------------------------
// OffsetCalculate
//
REGISTER_REGISTER_SKILL_NODE(22081, 101) {
    pnode->resizeTrigger(PhaseNode_OffsetCalculate::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnCollider>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 24, PhaseNode_SpawnCollider::FUNC_DO, &PhaseNode_SpawnCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(22081, 101) {
    auto node101 = GET_SKILL_NODE(101, PhaseNode_OffsetCalculate);
    if (node101 == nullptr) {
        node101 = new PhaseNode_OffsetCalculate(101, phase);
        node101->setPosZ(.00f);
        node101->setOffsetX(.00f);
        node101->setOffsetY(2.00f);
        node101->setOffsetZ(.00f);
        node101->setRotOffset(.00f);
        CALL_REGISTER_SKILL_NODE(22081, 101, node101)
    }
    if (noInit == true) {
        return node101;
    }
    auto node99 = GET_SKILL_NODE(99, PhaseNode_GetLocation);
    auto node100 = GET_SKILL_NODE(100, PhaseNode_GetRotation);
    if (node99 != nullptr) node101->setPosX(node99->getX());
    if (node99 != nullptr) node101->setPosY(node99->getY());
    if (node100 != nullptr) node101->setRotation(node100->getAngle());
    return node101;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(22081, 102) {
}

REGISTER_CREATE_SKILL_NODE(22081, 102) {
    auto node102 = GET_SKILL_NODE(102, PhaseNode_RaiseEvent);
    if (node102 == nullptr) {
        node102 = new PhaseNode_RaiseEvent(102, phase);
        node102->setEvent("MonsterInterrupt");
        node102->setTarget(0U);
        node102->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node102->setTypeParams(0, 0);
        node102->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(22081, 102, node102)
    }
    if (noInit == true) {
        return node102;
    }
    return node102;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(22081, 103) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_Detect::TRIGGER_ON, 110, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(22081, 103) {
    auto node103 = GET_SKILL_NODE(103, PhaseNode_Detect);
    if (node103 == nullptr) {
        node103 = new PhaseNode_Detect(103, phase);
        node103->setSelf(0U);
        node103->setEvent("MonsterInterrupt");
        node103->setType(PhaseNode_Detect::Detect_Type::Interrupt_Skill);
        node103->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(22081, 103, node103)
    }
    if (noInit == true) {
        return node103;
    }
    return node103;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(22081, 104) {
}

REGISTER_CREATE_SKILL_NODE(22081, 104) {
    auto node104 = GET_SKILL_NODE(104, PhaseNode_EndPhase);
    if (node104 == nullptr) {
        node104 = new PhaseNode_EndPhase(104, phase);
        node104->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node104->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(22081, 104, node104)
    }
    if (noInit == true) {
        return node104;
    }
    return node104;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22081, 106) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_Delay::TRIGGER_DONE, 107, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(22081, 106) {
    auto node106 = GET_SKILL_NODE(106, PhaseNode_Delay);
    if (node106 == nullptr) {
        node106 = new PhaseNode_Delay(106, phase);
        node106->setTime(.20f);
        CALL_REGISTER_SKILL_NODE(22081, 106, node106)
    }
    if (noInit == true) {
        return node106;
    }
    return node106;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(22081, 107) {
}

REGISTER_CREATE_SKILL_NODE(22081, 107) {
    auto node107 = GET_SKILL_NODE(107, PhaseNode_PlaySound);
    if (node107 == nullptr) {
        node107 = new PhaseNode_PlaySound(107, phase);
        node107->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node107->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node107->setSoundID("SE_MON2201_ATK2_P1");
        node107->setTarget(0U);
        node107->setUsePos(false);
        node107->setPosX(.00f);
        node107->setPosY(.00f);
        node107->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(22081, 107, node107)
    }
    if (noInit == true) {
        return node107;
    }
    return node107;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22081, 108) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_Delay::TRIGGER_DONE, 109, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(22081, 108) {
    auto node108 = GET_SKILL_NODE(108, PhaseNode_Delay);
    if (node108 == nullptr) {
        node108 = new PhaseNode_Delay(108, phase);
        node108->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(22081, 108, node108)
    }
    if (noInit == true) {
        return node108;
    }
    return node108;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(22081, 109) {
}

REGISTER_CREATE_SKILL_NODE(22081, 109) {
    auto node109 = GET_SKILL_NODE(109, PhaseNode_PlaySound);
    if (node109 == nullptr) {
        node109 = new PhaseNode_PlaySound(109, phase);
        node109->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node109->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node109->setSoundID("VO_MON2201_ATK");
        node109->setTarget(0U);
        node109->setUsePos(false);
        node109->setPosX(.00f);
        node109->setPosY(.00f);
        node109->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(22081, 109, node109)
    }
    if (noInit == true) {
        return node109;
    }
    return node109;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22081, 110) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_Delay::TRIGGER_DONE, 112, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(22081, 110) {
    auto node110 = GET_SKILL_NODE(110, PhaseNode_Delay);
    if (node110 == nullptr) {
        node110 = new PhaseNode_Delay(110, phase);
        node110->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(22081, 110, node110)
    }
    if (noInit == true) {
        return node110;
    }
    return node110;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(22081, 111) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 104, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(22081, 111) {
    auto node111 = GET_SKILL_NODE(111, PhaseNode_SkillEndNotify);
    if (node111 == nullptr) {
        node111 = new PhaseNode_SkillEndNotify(111, phase);
        node111->setReturnType(false);
        CALL_REGISTER_SKILL_NODE(22081, 111, node111)
    }
    if (noInit == true) {
        return node111;
    }
    return node111;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(22081, 112) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_FALSE, 113, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_TRUE, 111, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
}

REGISTER_CREATE_SKILL_NODE(22081, 112) {
    auto node112 = GET_SKILL_NODE(112, PhaseNode_If);
    if (node112 == nullptr) {
        node112 = new PhaseNode_If(112, phase);
        node112->setCondition(false);
        CALL_REGISTER_SKILL_NODE(22081, 112, node112)
    }
    if (noInit == true) {
        return node112;
    }
    return node112;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(22081, 113) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 104, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(22081, 113) {
    auto node113 = GET_SKILL_NODE(113, PhaseNode_SkillEndNotify);
    if (node113 == nullptr) {
        node113 = new PhaseNode_SkillEndNotify(113, phase);
        node113->setReturnType(true);
        CALL_REGISTER_SKILL_NODE(22081, 113, node113)
    }
    if (noInit == true) {
        return node113;
    }
    return node113;
}

//--------------------------------------------------------------------------------
// SkillCreator_22081
//
class SkillCreator_22081 : public SkillCreator {
public:
    SkillCreator_22081() {}
    virtual ~SkillCreator_22081() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_22081

//--------------------------------------------------------------------------------
// SkillPhase_22081
//
class SkillPhase_22081 : public SkillPhase {
public:
    SkillPhase_22081(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_22081() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(22081, 2) // StartPhase
        CASE_CREATE_SKILL_NODE(22081, 4) // TriggerUpdate
        CASE_CREATE_SKILL_NODE(22081, 24) // SpawnCollider
        CASE_CREATE_SKILL_NODE(22081, 39) // EndPhase
        CASE_CREATE_SKILL_NODE(22081, 46) // Detect
        CASE_CREATE_SKILL_NODE(22081, 48) // EndPhase
        CASE_CREATE_SKILL_NODE(22081, 56) // Delay
        CASE_CREATE_SKILL_NODE(22081, 61) // PlaySound
        CASE_CREATE_SKILL_NODE(22081, 62) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(22081, 63) // TriggerCheck
        CASE_CREATE_SKILL_NODE(22081, 64) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(22081, 65) // GetActorAttribute
        CASE_CREATE_SKILL_NODE(22081, 66) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(22081, 67) // CompareFloat
        CASE_CREATE_SKILL_NODE(22081, 68) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(22081, 69) // If
        CASE_CREATE_SKILL_NODE(22081, 70) // CompareFloat
        CASE_CREATE_SKILL_NODE(22081, 71) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(22081, 72) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(22081, 73) // TriggerCheck
        CASE_CREATE_SKILL_NODE(22081, 74) // TriggerCheck
        CASE_CREATE_SKILL_NODE(22081, 75) // TriggerCheck
        CASE_CREATE_SKILL_NODE(22081, 76) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(22081, 77) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(22081, 78) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(22081, 79) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(22081, 80) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(22081, 81) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(22081, 82) // Delay
        CASE_CREATE_SKILL_NODE(22081, 83) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(22081, 84) // If
        CASE_CREATE_SKILL_NODE(22081, 85) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(22081, 86) // ResetCD
        CASE_CREATE_SKILL_NODE(22081, 87) // PlayAnimation
        CASE_CREATE_SKILL_NODE(22081, 88) // PlaySound
        CASE_CREATE_SKILL_NODE(22081, 89) // Delay
        CASE_CREATE_SKILL_NODE(22081, 90) // GetLocation
        CASE_CREATE_SKILL_NODE(22081, 91) // GetRotation
        CASE_CREATE_SKILL_NODE(22081, 92) // OffsetCalculate
        CASE_CREATE_SKILL_NODE(22081, 93) // PlayEffect
        CASE_CREATE_SKILL_NODE(22081, 94) // If
        CASE_CREATE_SKILL_NODE(22081, 95) // PlayEffect
        CASE_CREATE_SKILL_NODE(22081, 96) // CompareFloat
        CASE_CREATE_SKILL_NODE(22081, 97) // Delay
        CASE_CREATE_SKILL_NODE(22081, 98) // StopEffect
        CASE_CREATE_SKILL_NODE(22081, 99) // GetLocation
        CASE_CREATE_SKILL_NODE(22081, 100) // GetRotation
        CASE_CREATE_SKILL_NODE(22081, 101) // OffsetCalculate
        CASE_CREATE_SKILL_NODE(22081, 102) // RaiseEvent
        CASE_CREATE_SKILL_NODE(22081, 103) // Detect
        CASE_CREATE_SKILL_NODE(22081, 104) // EndPhase
        CASE_CREATE_SKILL_NODE(22081, 106) // Delay
        CASE_CREATE_SKILL_NODE(22081, 107) // PlaySound
        CASE_CREATE_SKILL_NODE(22081, 108) // Delay
        CASE_CREATE_SKILL_NODE(22081, 109) // PlaySound
        CASE_CREATE_SKILL_NODE(22081, 110) // Delay
        CASE_CREATE_SKILL_NODE(22081, 111) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(22081, 112) // If
        CASE_CREATE_SKILL_NODE(22081, 113) // SkillEndNotify
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_22081

SkillLogic* SkillCreator_22081::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //创建阶段phase
    auto phase = new SkillPhase_22081(1, logic, 3);
    //设置phase执行器
    phase->setRunPhaseNode(1, 2);
    phase->setRunPhaseNode(2, 4);
    phase->setDetectPhaseNode(3, 46);
    phase->setDetectPhaseNode(3, 103);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_22081::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
