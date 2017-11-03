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
REGISTER_REGISTER_SKILL_NODE(22012, 1) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_StartPhase::TRIGGER_START, 83, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_StartPhase::TRIGGER_START, 85, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_StartPhase::TRIGGER_START, 130, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_StartPhase::TRIGGER_START, 114, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(22012, 1) {
    auto node1 = GET_SKILL_NODE(1, PhaseNode_StartPhase);
    if (node1 == nullptr) {
        node1 = new PhaseNode_StartPhase(1, phase);
        CALL_REGISTER_SKILL_NODE(22012, 1, node1)
    }
    if (noInit == true) {
        return node1;
    }
    return node1;
}
//--------------------------------------------------------------------------------
// TriggerUpdate
//
REGISTER_REGISTER_SKILL_NODE(22012, 2) {
}

REGISTER_CREATE_SKILL_NODE(22012, 2) {
    auto node2 = GET_SKILL_NODE(2, PhaseNode_TriggerUpdate);
    if (node2 == nullptr) {
        node2 = new PhaseNode_TriggerUpdate(2, phase);
        CALL_REGISTER_SKILL_NODE(22012, 2, node2)
    }
    if (noInit == true) {
        return node2;
    }
    return node2;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(22012, 19) {
}

REGISTER_CREATE_SKILL_NODE(22012, 19) {
    auto node19 = GET_SKILL_NODE(19, PhaseNode_EndPhase);
    if (node19 == nullptr) {
        node19 = new PhaseNode_EndPhase(19, phase);
        node19->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node19->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(22012, 19, node19)
    }
    if (noInit == true) {
        return node19;
    }
    return node19;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(22012, 73) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnCollider>(PhaseNode_PlaySound::TRIGGER_DONE, 74, PhaseNode_SpawnCollider::FUNC_DO, &PhaseNode_SpawnCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(22012, 73) {
    auto node73 = GET_SKILL_NODE(73, PhaseNode_PlaySound);
    if (node73 == nullptr) {
        node73 = new PhaseNode_PlaySound(73, phase);
        node73->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node73->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node73->setSoundID("");
        node73->setTarget(0U);
        node73->setUsePos(false);
        node73->setPosX(.00f);
        node73->setPosY(.00f);
        node73->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(22012, 73, node73)
    }
    if (noInit == true) {
        return node73;
    }
    return node73;
}
//--------------------------------------------------------------------------------
// SpawnCollider
//
REGISTER_REGISTER_SKILL_NODE(22012, 74) {
    pnode->resizeTrigger(PhaseNode_SpawnCollider::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_SpawnCollider::TRIGGER_DONE, 87, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_SpawnCollider::TRIGGER_DONE, 98, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(22012, 74) {
    auto node74 = GET_SKILL_NODE(74, PhaseNode_SpawnCollider);
    if (node74 == nullptr) {
        node74 = new PhaseNode_SpawnCollider(74, phase);
        node74->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node74->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node74->setMesh("");
        node74->setMeshScale(.00f);
        node74->setEffectID(0);
        node74->setEffectScale(.00f);
        node74->setType(PhaseNode_SpawnCollider::SpawnCollider_Type::Sector);
        node74->setTypeParams(0, 4.00f);
        node74->setTypeParams(1, 120.00f);
        node74->setTime(.30f);
        node74->setreentry(false);
        node74->setCheckPeneSound(false);
        CALL_REGISTER_SKILL_NODE(22012, 74, node74)
    }
    if (noInit == true) {
        return node74;
    }
    auto node113 = GET_SKILL_NODE(113, PhaseNode_OffsetCalculate);
    if (node113 != nullptr) node74->setPosX(node113->getOutPosX());
    if (node113 != nullptr) node74->setPosY(node113->getOutPosY());
    if (node113 != nullptr) node74->setPosZ(node113->getOutPosZ());
    if (node113 != nullptr) node74->setRotation(node113->getOutRotation());
    return node74;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22012, 82) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_Delay::TRIGGER_DONE, 73, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(22012, 82) {
    auto node82 = GET_SKILL_NODE(82, PhaseNode_Delay);
    if (node82 == nullptr) {
        node82 = new PhaseNode_Delay(82, phase);
        node82->setTime(.60f);
        CALL_REGISTER_SKILL_NODE(22012, 82, node82)
    }
    if (noInit == true) {
        return node82;
    }
    return node82;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22012, 83) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_Delay::TRIGGER_DONE, 84, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(22012, 83) {
    auto node83 = GET_SKILL_NODE(83, PhaseNode_Delay);
    if (node83 == nullptr) {
        node83 = new PhaseNode_Delay(83, phase);
        node83->setTime(.50f);
        CALL_REGISTER_SKILL_NODE(22012, 83, node83)
    }
    if (noInit == true) {
        return node83;
    }
    return node83;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(22012, 84) {
}

REGISTER_CREATE_SKILL_NODE(22012, 84) {
    auto node84 = GET_SKILL_NODE(84, PhaseNode_PlaySound);
    if (node84 == nullptr) {
        node84 = new PhaseNode_PlaySound(84, phase);
        node84->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node84->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node84->setSoundID("SE_MON2201_ATK1_P1");
        node84->setTarget(0U);
        node84->setUsePos(false);
        node84->setPosX(.00f);
        node84->setPosY(.00f);
        node84->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(22012, 84, node84)
    }
    if (noInit == true) {
        return node84;
    }
    return node84;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22012, 85) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_Delay::TRIGGER_DONE, 86, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(22012, 85) {
    auto node85 = GET_SKILL_NODE(85, PhaseNode_Delay);
    if (node85 == nullptr) {
        node85 = new PhaseNode_Delay(85, phase);
        node85->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(22012, 85, node85)
    }
    if (noInit == true) {
        return node85;
    }
    return node85;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(22012, 86) {
}

REGISTER_CREATE_SKILL_NODE(22012, 86) {
    auto node86 = GET_SKILL_NODE(86, PhaseNode_PlaySound);
    if (node86 == nullptr) {
        node86 = new PhaseNode_PlaySound(86, phase);
        node86->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node86->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node86->setSoundID("VO_MON2201_ATK");
        node86->setTarget(0U);
        node86->setUsePos(false);
        node86->setPosX(.00f);
        node86->setPosY(.00f);
        node86->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(22012, 86, node86)
    }
    if (noInit == true) {
        return node86;
    }
    return node86;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22012, 87) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_Delay::TRIGGER_DONE, 89, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(22012, 87) {
    auto node87 = GET_SKILL_NODE(87, PhaseNode_Delay);
    if (node87 == nullptr) {
        node87 = new PhaseNode_Delay(87, phase);
        node87->setTime(.70f);
        CALL_REGISTER_SKILL_NODE(22012, 87, node87)
    }
    if (noInit == true) {
        return node87;
    }
    return node87;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(22012, 88) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 19, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(22012, 88) {
    auto node88 = GET_SKILL_NODE(88, PhaseNode_SkillEndNotify);
    if (node88 == nullptr) {
        node88 = new PhaseNode_SkillEndNotify(88, phase);
        node88->setReturnType(false);
        CALL_REGISTER_SKILL_NODE(22012, 88, node88)
    }
    if (noInit == true) {
        return node88;
    }
    return node88;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(22012, 89) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_FALSE, 90, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_TRUE, 88, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
}

REGISTER_CREATE_SKILL_NODE(22012, 89) {
    auto node89 = GET_SKILL_NODE(89, PhaseNode_If);
    if (node89 == nullptr) {
        node89 = new PhaseNode_If(89, phase);
        node89->setCondition(false);
        CALL_REGISTER_SKILL_NODE(22012, 89, node89)
    }
    if (noInit == true) {
        return node89;
    }
    return node89;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(22012, 90) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 19, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(22012, 90) {
    auto node90 = GET_SKILL_NODE(90, PhaseNode_SkillEndNotify);
    if (node90 == nullptr) {
        node90 = new PhaseNode_SkillEndNotify(90, phase);
        node90->setReturnType(true);
        CALL_REGISTER_SKILL_NODE(22012, 90, node90)
    }
    if (noInit == true) {
        return node90;
    }
    return node90;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(22012, 91) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 103, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 105, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(22012, 91) {
    auto node91 = GET_SKILL_NODE(91, PhaseNode_CreateTriggerNewPene);
    if (node91 == nullptr) {
        node91 = new PhaseNode_CreateTriggerNewPene(91, phase);
        node91->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::In);
        node91->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node91->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Enemy);
        node91->setOnHero(true);
        node91->setOnMinion(true);
        node91->setOnDestruct(true);
        node91->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(22012, 91, node91)
    }
    if (noInit == true) {
        return node91;
    }
    auto node74 = GET_SKILL_NODE(74, PhaseNode_SpawnCollider);
    if (node74 != nullptr) node91->setColliderID(node74->getColliderID());
    return node91;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(22012, 92) {
}

REGISTER_CREATE_SKILL_NODE(22012, 92) {
    auto node92 = GET_SKILL_NODE(92, PhaseNode_TriggerCheck);
    if (node92 == nullptr) {
        node92 = new PhaseNode_TriggerCheck(92, phase);
        auto node2 = GET_SKILL_NODE(2, PhaseNode_TriggerUpdate);
        if (node2 != nullptr) node2->addTriggerCheck(node92);
        
        CALL_REGISTER_SKILL_NODE(22012, 92, node92)
    }
    if (noInit == true) {
        return node92;
    }
    auto node101 = GET_SKILL_NODE(101, PhaseNode_CreateTriggerNewPene);
    if (node101 != nullptr) node92->setTrigger(0, node101->getTriggerID());
    return node92;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(22012, 93) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 94, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(22012, 93) {
    auto node93 = GET_SKILL_NODE(93, PhaseNode_ActorFilterNewPene);
    if (node93 == nullptr) {
        node93 = new PhaseNode_ActorFilterNewPene(93, phase);
        node93->setHero(true);
        node93->setMinion(true);
        node93->setDestruct(true);
        node93->setShield(false);
        node93->setTotalCount(0);
        node93->setPerCount(1);
        CALL_REGISTER_SKILL_NODE(22012, 93, node93)
    }
    if (noInit == true) {
        return node93;
    }
    auto node97 = GET_SKILL_NODE(97, PhaseNode_CreateTriggerNewPene);
    if (node97 != nullptr) node93->setInput(node97->getOther());
    return node93;
}
//--------------------------------------------------------------------------------
// GetActorAttribute
//
REGISTER_REGISTER_SKILL_NODE(22012, 94) {
    pnode->resizeTrigger(PhaseNode_GetActorAttribute::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 108, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 109, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 110, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 95, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
}

REGISTER_CREATE_SKILL_NODE(22012, 94) {
    auto node94 = GET_SKILL_NODE(94, PhaseNode_GetActorAttribute);
    if (node94 == nullptr) {
        node94 = new PhaseNode_GetActorAttribute(94, phase);
        node94->setTarget(0U);
        node94->setType({202});
        CALL_REGISTER_SKILL_NODE(22012, 94, node94)
    }
    if (noInit == true) {
        return node94;
    }
    return node94;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(22012, 95) {
}

REGISTER_CREATE_SKILL_NODE(22012, 95) {
    auto node95 = GET_SKILL_NODE(95, PhaseNode_AddSkillBuffs);
    if (node95 == nullptr) {
        node95 = new PhaseNode_AddSkillBuffs(95, phase);
        node95->setConfigID({11});
        CALL_REGISTER_SKILL_NODE(22012, 95, node95)
    }
    if (noInit == true) {
        return node95;
    }
    auto node93 = GET_SKILL_NODE(93, PhaseNode_ActorFilterNewPene);
    auto node94 = GET_SKILL_NODE(94, PhaseNode_GetActorAttribute);
    if (node93 != nullptr) node95->setTarget(node93->getOutput());
    if (node94 != nullptr) node95->setAttribute(node94->getAttribute());
    return node95;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(22012, 96) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 91, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_LESS, 97, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
}

REGISTER_CREATE_SKILL_NODE(22012, 96) {
    auto node96 = GET_SKILL_NODE(96, PhaseNode_CompareFloat);
    if (node96 == nullptr) {
        node96 = new PhaseNode_CompareFloat(96, phase);
        node96->setA(.00f);
        node96->setB(.00f);
        CALL_REGISTER_SKILL_NODE(22012, 96, node96)
    }
    if (noInit == true) {
        return node96;
    }
    return node96;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(22012, 97) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 102, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 93, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(22012, 97) {
    auto node97 = GET_SKILL_NODE(97, PhaseNode_CreateTriggerNewPene);
    if (node97 == nullptr) {
        node97 = new PhaseNode_CreateTriggerNewPene(97, phase);
        node97->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::Tick);
        node97->setTypeParams(0, .00f);
        node97->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node97->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Enemy);
        node97->setOnHero(true);
        node97->setOnMinion(true);
        node97->setOnDestruct(true);
        node97->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(22012, 97, node97)
    }
    if (noInit == true) {
        return node97;
    }
    auto node74 = GET_SKILL_NODE(74, PhaseNode_SpawnCollider);
    if (node74 != nullptr) node97->setColliderID(node74->getColliderID());
    return node97;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(22012, 98) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_If::TRIGGER_FALSE, 99, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_If::TRIGGER_TRUE, 96, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(22012, 98) {
    auto node98 = GET_SKILL_NODE(98, PhaseNode_If);
    if (node98 == nullptr) {
        node98 = new PhaseNode_If(98, phase);
        node98->setCondition(true);
        CALL_REGISTER_SKILL_NODE(22012, 98, node98)
    }
    if (noInit == true) {
        return node98;
    }
    return node98;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(22012, 99) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 101, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_LESS, 100, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
}

REGISTER_CREATE_SKILL_NODE(22012, 99) {
    auto node99 = GET_SKILL_NODE(99, PhaseNode_CompareFloat);
    if (node99 == nullptr) {
        node99 = new PhaseNode_CompareFloat(99, phase);
        node99->setA(.00f);
        node99->setB(.00f);
        CALL_REGISTER_SKILL_NODE(22012, 99, node99)
    }
    if (noInit == true) {
        return node99;
    }
    return node99;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(22012, 100) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 104, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 106, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(22012, 100) {
    auto node100 = GET_SKILL_NODE(100, PhaseNode_CreateTriggerNewPene);
    if (node100 == nullptr) {
        node100 = new PhaseNode_CreateTriggerNewPene(100, phase);
        node100->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::Tick);
        node100->setTypeParams(0, .00f);
        node100->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node100->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Friend);
        node100->setOnHero(true);
        node100->setOnMinion(true);
        node100->setOnDestruct(true);
        node100->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(22012, 100, node100)
    }
    if (noInit == true) {
        return node100;
    }
    auto node74 = GET_SKILL_NODE(74, PhaseNode_SpawnCollider);
    if (node74 != nullptr) node100->setColliderID(node74->getColliderID());
    return node100;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(22012, 101) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 92, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 107, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(22012, 101) {
    auto node101 = GET_SKILL_NODE(101, PhaseNode_CreateTriggerNewPene);
    if (node101 == nullptr) {
        node101 = new PhaseNode_CreateTriggerNewPene(101, phase);
        node101->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::In);
        node101->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node101->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Friend);
        node101->setOnHero(true);
        node101->setOnMinion(true);
        node101->setOnDestruct(true);
        node101->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(22012, 101, node101)
    }
    if (noInit == true) {
        return node101;
    }
    auto node74 = GET_SKILL_NODE(74, PhaseNode_SpawnCollider);
    if (node74 != nullptr) node101->setColliderID(node74->getColliderID());
    return node101;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(22012, 102) {
}

REGISTER_CREATE_SKILL_NODE(22012, 102) {
    auto node102 = GET_SKILL_NODE(102, PhaseNode_TriggerCheck);
    if (node102 == nullptr) {
        node102 = new PhaseNode_TriggerCheck(102, phase);
        auto node2 = GET_SKILL_NODE(2, PhaseNode_TriggerUpdate);
        if (node2 != nullptr) node2->addTriggerCheck(node102);
        
        CALL_REGISTER_SKILL_NODE(22012, 102, node102)
    }
    if (noInit == true) {
        return node102;
    }
    auto node97 = GET_SKILL_NODE(97, PhaseNode_CreateTriggerNewPene);
    if (node97 != nullptr) node102->setTrigger(0, node97->getTriggerID());
    return node102;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(22012, 103) {
}

REGISTER_CREATE_SKILL_NODE(22012, 103) {
    auto node103 = GET_SKILL_NODE(103, PhaseNode_TriggerCheck);
    if (node103 == nullptr) {
        node103 = new PhaseNode_TriggerCheck(103, phase);
        auto node2 = GET_SKILL_NODE(2, PhaseNode_TriggerUpdate);
        if (node2 != nullptr) node2->addTriggerCheck(node103);
        
        CALL_REGISTER_SKILL_NODE(22012, 103, node103)
    }
    if (noInit == true) {
        return node103;
    }
    auto node91 = GET_SKILL_NODE(91, PhaseNode_CreateTriggerNewPene);
    if (node91 != nullptr) node103->setTrigger(0, node91->getTriggerID());
    return node103;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(22012, 104) {
}

REGISTER_CREATE_SKILL_NODE(22012, 104) {
    auto node104 = GET_SKILL_NODE(104, PhaseNode_TriggerCheck);
    if (node104 == nullptr) {
        node104 = new PhaseNode_TriggerCheck(104, phase);
        auto node2 = GET_SKILL_NODE(2, PhaseNode_TriggerUpdate);
        if (node2 != nullptr) node2->addTriggerCheck(node104);
        
        CALL_REGISTER_SKILL_NODE(22012, 104, node104)
    }
    if (noInit == true) {
        return node104;
    }
    auto node100 = GET_SKILL_NODE(100, PhaseNode_CreateTriggerNewPene);
    if (node100 != nullptr) node104->setTrigger(0, node100->getTriggerID());
    return node104;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(22012, 105) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 94, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(22012, 105) {
    auto node105 = GET_SKILL_NODE(105, PhaseNode_ActorFilterNewPene);
    if (node105 == nullptr) {
        node105 = new PhaseNode_ActorFilterNewPene(105, phase);
        node105->setHero(true);
        node105->setMinion(true);
        node105->setDestruct(true);
        node105->setShield(false);
        node105->setTotalCount(0);
        node105->setPerCount(1);
        CALL_REGISTER_SKILL_NODE(22012, 105, node105)
    }
    if (noInit == true) {
        return node105;
    }
    auto node91 = GET_SKILL_NODE(91, PhaseNode_CreateTriggerNewPene);
    if (node91 != nullptr) node105->setInput(node91->getOther());
    return node105;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(22012, 106) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 94, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(22012, 106) {
    auto node106 = GET_SKILL_NODE(106, PhaseNode_ActorFilterNewPene);
    if (node106 == nullptr) {
        node106 = new PhaseNode_ActorFilterNewPene(106, phase);
        node106->setHero(true);
        node106->setMinion(true);
        node106->setDestruct(true);
        node106->setShield(false);
        node106->setTotalCount(0);
        node106->setPerCount(1);
        CALL_REGISTER_SKILL_NODE(22012, 106, node106)
    }
    if (noInit == true) {
        return node106;
    }
    auto node100 = GET_SKILL_NODE(100, PhaseNode_CreateTriggerNewPene);
    if (node100 != nullptr) node106->setInput(node100->getOther());
    return node106;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(22012, 107) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 94, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(22012, 107) {
    auto node107 = GET_SKILL_NODE(107, PhaseNode_ActorFilterNewPene);
    if (node107 == nullptr) {
        node107 = new PhaseNode_ActorFilterNewPene(107, phase);
        node107->setHero(true);
        node107->setMinion(true);
        node107->setDestruct(true);
        node107->setShield(false);
        node107->setTotalCount(0);
        node107->setPerCount(1);
        CALL_REGISTER_SKILL_NODE(22012, 107, node107)
    }
    if (noInit == true) {
        return node107;
    }
    auto node101 = GET_SKILL_NODE(101, PhaseNode_CreateTriggerNewPene);
    if (node101 != nullptr) node107->setInput(node101->getOther());
    return node107;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(22012, 108) {
}

REGISTER_CREATE_SKILL_NODE(22012, 108) {
    auto node108 = GET_SKILL_NODE(108, PhaseNode_AddSkillBuffs);
    if (node108 == nullptr) {
        node108 = new PhaseNode_AddSkillBuffs(108, phase);
        node108->setConfigID({11});
        CALL_REGISTER_SKILL_NODE(22012, 108, node108)
    }
    if (noInit == true) {
        return node108;
    }
    auto node105 = GET_SKILL_NODE(105, PhaseNode_ActorFilterNewPene);
    auto node94 = GET_SKILL_NODE(94, PhaseNode_GetActorAttribute);
    if (node105 != nullptr) node108->setTarget(node105->getOutput());
    if (node94 != nullptr) node108->setAttribute(node94->getAttribute());
    return node108;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(22012, 109) {
}

REGISTER_CREATE_SKILL_NODE(22012, 109) {
    auto node109 = GET_SKILL_NODE(109, PhaseNode_AddSkillBuffs);
    if (node109 == nullptr) {
        node109 = new PhaseNode_AddSkillBuffs(109, phase);
        node109->setConfigID({11});
        CALL_REGISTER_SKILL_NODE(22012, 109, node109)
    }
    if (noInit == true) {
        return node109;
    }
    auto node106 = GET_SKILL_NODE(106, PhaseNode_ActorFilterNewPene);
    auto node94 = GET_SKILL_NODE(94, PhaseNode_GetActorAttribute);
    if (node106 != nullptr) node109->setTarget(node106->getOutput());
    if (node94 != nullptr) node109->setAttribute(node94->getAttribute());
    return node109;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(22012, 110) {
}

REGISTER_CREATE_SKILL_NODE(22012, 110) {
    auto node110 = GET_SKILL_NODE(110, PhaseNode_AddSkillBuffs);
    if (node110 == nullptr) {
        node110 = new PhaseNode_AddSkillBuffs(110, phase);
        node110->setConfigID({11});
        CALL_REGISTER_SKILL_NODE(22012, 110, node110)
    }
    if (noInit == true) {
        return node110;
    }
    auto node107 = GET_SKILL_NODE(107, PhaseNode_ActorFilterNewPene);
    auto node94 = GET_SKILL_NODE(94, PhaseNode_GetActorAttribute);
    if (node107 != nullptr) node110->setTarget(node107->getOutput());
    if (node94 != nullptr) node110->setAttribute(node94->getAttribute());
    return node110;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(22012, 111) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetRotation>(PhaseNode_GetLocation::TRIGGER_DONE, 112, PhaseNode_GetRotation::FUNC_DO, &PhaseNode_GetRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(22012, 111) {
    auto node111 = GET_SKILL_NODE(111, PhaseNode_GetLocation);
    if (node111 == nullptr) {
        node111 = new PhaseNode_GetLocation(111, phase);
        node111->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node111->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(22012, 111, node111)
    }
    if (noInit == true) {
        return node111;
    }
    return node111;
}
//--------------------------------------------------------------------------------
// GetRotation
//
REGISTER_REGISTER_SKILL_NODE(22012, 112) {
    pnode->resizeTrigger(PhaseNode_GetRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_OffsetCalculate>(PhaseNode_GetRotation::TRIGGER_DONE, 113, PhaseNode_OffsetCalculate::FUNC_DO, &PhaseNode_OffsetCalculate::Do);
}

REGISTER_CREATE_SKILL_NODE(22012, 112) {
    auto node112 = GET_SKILL_NODE(112, PhaseNode_GetRotation);
    if (node112 == nullptr) {
        node112 = new PhaseNode_GetRotation(112, phase);
        node112->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node112->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(22012, 112, node112)
    }
    if (noInit == true) {
        return node112;
    }
    return node112;
}
//--------------------------------------------------------------------------------
// OffsetCalculate
//
REGISTER_REGISTER_SKILL_NODE(22012, 113) {
    pnode->resizeTrigger(PhaseNode_OffsetCalculate::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 119, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(22012, 113) {
    auto node113 = GET_SKILL_NODE(113, PhaseNode_OffsetCalculate);
    if (node113 == nullptr) {
        node113 = new PhaseNode_OffsetCalculate(113, phase);
        node113->setPosZ(.00f);
        node113->setOffsetX(.00f);
        node113->setOffsetY(.00f);
        node113->setOffsetZ(.00f);
        node113->setRotOffset(.00f);
        CALL_REGISTER_SKILL_NODE(22012, 113, node113)
    }
    if (noInit == true) {
        return node113;
    }
    auto node111 = GET_SKILL_NODE(111, PhaseNode_GetLocation);
    auto node112 = GET_SKILL_NODE(112, PhaseNode_GetRotation);
    if (node111 != nullptr) node113->setPosX(node111->getX());
    if (node111 != nullptr) node113->setPosY(node111->getY());
    if (node112 != nullptr) node113->setRotation(node112->getAngle());
    return node113;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(22012, 114) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_ResetCD::TRIGGER_DONE, 115, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(22012, 114) {
    auto node114 = GET_SKILL_NODE(114, PhaseNode_ResetCD);
    if (node114 == nullptr) {
        node114 = new PhaseNode_ResetCD(114, phase);
        node114->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node114->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node114->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(22012, 114, node114)
    }
    if (noInit == true) {
        return node114;
    }
    return node114;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(22012, 115) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_PlayAnimation::TRIGGER_DONE, 116, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(22012, 115) {
    auto node115 = GET_SKILL_NODE(115, PhaseNode_PlayAnimation);
    if (node115 == nullptr) {
        node115 = new PhaseNode_PlayAnimation(115, phase);
        node115->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node115->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node115->setTarget(0U);
        node115->setAnimation("Skill2S1");
        node115->setParameter("");
        node115->setValue(false);
        CALL_REGISTER_SKILL_NODE(22012, 115, node115)
    }
    if (noInit == true) {
        return node115;
    }
    return node115;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(22012, 116) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlaySound::TRIGGER_DONE, 117, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(22012, 116) {
    auto node116 = GET_SKILL_NODE(116, PhaseNode_PlaySound);
    if (node116 == nullptr) {
        node116 = new PhaseNode_PlaySound(116, phase);
        node116->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node116->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node116->setSoundID("");
        node116->setTarget(0U);
        node116->setUsePos(false);
        node116->setPosX(.00f);
        node116->setPosY(.00f);
        node116->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(22012, 116, node116)
    }
    if (noInit == true) {
        return node116;
    }
    return node116;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22012, 117) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_Delay::TRIGGER_DONE, 111, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(22012, 117) {
    auto node117 = GET_SKILL_NODE(117, PhaseNode_Delay);
    if (node117 == nullptr) {
        node117 = new PhaseNode_Delay(117, phase);
        node117->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(22012, 117, node117)
    }
    if (noInit == true) {
        return node117;
    }
    return node117;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(22012, 118) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_PlayEffect::TRIGGER_DONE, 121, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(22012, 118) {
    auto node118 = GET_SKILL_NODE(118, PhaseNode_PlayEffect);
    if (node118 == nullptr) {
        node118 = new PhaseNode_PlayEffect(118, phase);
        node118->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node118->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node118->setEffectID(220121);
        node118->setChangeColor(false);
        node118->setType(PhaseNode_PlayEffect::PlayEffect_Type::WithTarget);
        node118->getVars().reserve(5);
        node118->getVars().setVariable<uint64_t>(0, 0U);
        node118->getVars().setVariable<std::string>(1, "");
        node118->getVars().setVariable<float>(2, .00f);
        node118->getVars().setVariable<float>(3, .00f);
        node118->getVars().setVariable<float>(4, .00f);
        node118->setScale(.00f);
        CALL_REGISTER_SKILL_NODE(22012, 118, node118)
    }
    if (noInit == true) {
        return node118;
    }
    auto node113 = GET_SKILL_NODE(113, PhaseNode_OffsetCalculate);
    if (node113 != nullptr) node118->getVars().setVariable<float>(2, node113->getOutPosX());
    if (node113 != nullptr) node118->getVars().setVariable<float>(3, node113->getOutPosY());
    if (node113 != nullptr) node118->getVars().setVariable<float>(4, node113->getOutPosZ());
    if (node113 != nullptr) node118->setRotation(node113->getOutRotation());
    return node118;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(22012, 119) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_FALSE, 120, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_TRUE, 118, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(22012, 119) {
    auto node119 = GET_SKILL_NODE(119, PhaseNode_If);
    if (node119 == nullptr) {
        node119 = new PhaseNode_If(119, phase);
        node119->setCondition(false);
        CALL_REGISTER_SKILL_NODE(22012, 119, node119)
    }
    if (noInit == true) {
        return node119;
    }
    return node119;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(22012, 120) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_PlayEffect::TRIGGER_DONE, 121, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(22012, 120) {
    auto node120 = GET_SKILL_NODE(120, PhaseNode_PlayEffect);
    if (node120 == nullptr) {
        node120 = new PhaseNode_PlayEffect(120, phase);
        node120->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node120->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node120->setEffectID(220121);
        node120->setChangeColor(false);
        node120->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node120->getVars().reserve(3);
        node120->getVars().setVariable<float>(0, .00f);
        node120->getVars().setVariable<float>(1, .00f);
        node120->getVars().setVariable<float>(2, .00f);
        node120->setScale(.00f);
        CALL_REGISTER_SKILL_NODE(22012, 120, node120)
    }
    if (noInit == true) {
        return node120;
    }
    auto node113 = GET_SKILL_NODE(113, PhaseNode_OffsetCalculate);
    if (node113 != nullptr) node120->getVars().setVariable<float>(0, node113->getOutPosX());
    if (node113 != nullptr) node120->getVars().setVariable<float>(1, node113->getOutPosY());
    if (node113 != nullptr) node120->getVars().setVariable<float>(2, node113->getOutPosZ());
    if (node113 != nullptr) node120->setRotation(node113->getOutRotation());
    return node120;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(22012, 121) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 125, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_LESS, 122, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_CompareFloat::TRIGGER_LESS, 125, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(22012, 121) {
    auto node121 = GET_SKILL_NODE(121, PhaseNode_CompareFloat);
    if (node121 == nullptr) {
        node121 = new PhaseNode_CompareFloat(121, phase);
        node121->setA(.00f);
        node121->setB(.00f);
        CALL_REGISTER_SKILL_NODE(22012, 121, node121)
    }
    if (noInit == true) {
        return node121;
    }
    return node121;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22012, 122) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StopEffect>(PhaseNode_Delay::TRIGGER_DONE, 123, PhaseNode_StopEffect::FUNC_DO, &PhaseNode_StopEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(22012, 122) {
    auto node122 = GET_SKILL_NODE(122, PhaseNode_Delay);
    if (node122 == nullptr) {
        node122 = new PhaseNode_Delay(122, phase);
        node122->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(22012, 122, node122)
    }
    if (noInit == true) {
        return node122;
    }
    return node122;
}
//--------------------------------------------------------------------------------
// StopEffect
//
REGISTER_REGISTER_SKILL_NODE(22012, 123) {
}

REGISTER_CREATE_SKILL_NODE(22012, 123) {
    auto node123 = GET_SKILL_NODE(123, PhaseNode_StopEffect);
    if (node123 == nullptr) {
        node123 = new PhaseNode_StopEffect(123, phase);
        node123->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node123->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node123->setEffectID(220121);
        CALL_REGISTER_SKILL_NODE(22012, 123, node123)
    }
    if (noInit == true) {
        return node123;
    }
    return node123;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(22012, 124) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_PlayEffect::TRIGGER_DONE, 127, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(22012, 124) {
    auto node124 = GET_SKILL_NODE(124, PhaseNode_PlayEffect);
    if (node124 == nullptr) {
        node124 = new PhaseNode_PlayEffect(124, phase);
        node124->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node124->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node124->setEffectID(0);
        node124->setChangeColor(false);
        node124->setType(PhaseNode_PlayEffect::PlayEffect_Type::WithTarget);
        node124->getVars().reserve(5);
        node124->getVars().setVariable<uint64_t>(0, 0U);
        node124->getVars().setVariable<std::string>(1, "");
        node124->getVars().setVariable<float>(2, .00f);
        node124->getVars().setVariable<float>(3, .00f);
        node124->getVars().setVariable<float>(4, .00f);
        node124->setScale(.00f);
        CALL_REGISTER_SKILL_NODE(22012, 124, node124)
    }
    if (noInit == true) {
        return node124;
    }
    auto node113 = GET_SKILL_NODE(113, PhaseNode_OffsetCalculate);
    if (node113 != nullptr) node124->getVars().setVariable<float>(2, node113->getOutPosX());
    if (node113 != nullptr) node124->getVars().setVariable<float>(3, node113->getOutPosY());
    if (node113 != nullptr) node124->getVars().setVariable<float>(4, node113->getOutPosZ());
    if (node113 != nullptr) node124->setRotation(node113->getOutRotation());
    return node124;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(22012, 125) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_FALSE, 126, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_TRUE, 124, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(22012, 125) {
    auto node125 = GET_SKILL_NODE(125, PhaseNode_If);
    if (node125 == nullptr) {
        node125 = new PhaseNode_If(125, phase);
        node125->setCondition(false);
        CALL_REGISTER_SKILL_NODE(22012, 125, node125)
    }
    if (noInit == true) {
        return node125;
    }
    return node125;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(22012, 126) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_PlayEffect::TRIGGER_DONE, 127, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(22012, 126) {
    auto node126 = GET_SKILL_NODE(126, PhaseNode_PlayEffect);
    if (node126 == nullptr) {
        node126 = new PhaseNode_PlayEffect(126, phase);
        node126->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node126->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node126->setEffectID(0);
        node126->setChangeColor(false);
        node126->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node126->getVars().reserve(3);
        node126->getVars().setVariable<float>(0, .00f);
        node126->getVars().setVariable<float>(1, .00f);
        node126->getVars().setVariable<float>(2, .00f);
        node126->setScale(.00f);
        CALL_REGISTER_SKILL_NODE(22012, 126, node126)
    }
    if (noInit == true) {
        return node126;
    }
    auto node113 = GET_SKILL_NODE(113, PhaseNode_OffsetCalculate);
    if (node113 != nullptr) node126->getVars().setVariable<float>(0, node113->getOutPosX());
    if (node113 != nullptr) node126->getVars().setVariable<float>(1, node113->getOutPosY());
    if (node113 != nullptr) node126->getVars().setVariable<float>(2, node113->getOutPosZ());
    if (node113 != nullptr) node126->setRotation(node113->getOutRotation());
    return node126;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(22012, 127) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 82, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_LESS, 128, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_LESS, 82, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(22012, 127) {
    auto node127 = GET_SKILL_NODE(127, PhaseNode_CompareFloat);
    if (node127 == nullptr) {
        node127 = new PhaseNode_CompareFloat(127, phase);
        node127->setA(.00f);
        node127->setB(.00f);
        CALL_REGISTER_SKILL_NODE(22012, 127, node127)
    }
    if (noInit == true) {
        return node127;
    }
    return node127;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22012, 128) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StopEffect>(PhaseNode_Delay::TRIGGER_DONE, 129, PhaseNode_StopEffect::FUNC_DO, &PhaseNode_StopEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(22012, 128) {
    auto node128 = GET_SKILL_NODE(128, PhaseNode_Delay);
    if (node128 == nullptr) {
        node128 = new PhaseNode_Delay(128, phase);
        node128->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(22012, 128, node128)
    }
    if (noInit == true) {
        return node128;
    }
    return node128;
}
//--------------------------------------------------------------------------------
// StopEffect
//
REGISTER_REGISTER_SKILL_NODE(22012, 129) {
}

REGISTER_CREATE_SKILL_NODE(22012, 129) {
    auto node129 = GET_SKILL_NODE(129, PhaseNode_StopEffect);
    if (node129 == nullptr) {
        node129 = new PhaseNode_StopEffect(129, phase);
        node129->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node129->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node129->setEffectID(0);
        CALL_REGISTER_SKILL_NODE(22012, 129, node129)
    }
    if (noInit == true) {
        return node129;
    }
    return node129;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(22012, 130) {
}

REGISTER_CREATE_SKILL_NODE(22012, 130) {
    auto node130 = GET_SKILL_NODE(130, PhaseNode_RaiseEvent);
    if (node130 == nullptr) {
        node130 = new PhaseNode_RaiseEvent(130, phase);
        node130->setEvent("MonsterInterrupt");
        node130->setTarget(0U);
        node130->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node130->setTypeParams(0, 0);
        node130->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(22012, 130, node130)
    }
    if (noInit == true) {
        return node130;
    }
    return node130;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(22012, 131) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_Detect::TRIGGER_ON, 134, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(22012, 131) {
    auto node131 = GET_SKILL_NODE(131, PhaseNode_Detect);
    if (node131 == nullptr) {
        node131 = new PhaseNode_Detect(131, phase);
        node131->setSelf(0U);
        node131->setEvent("MonsterInterrupt");
        node131->setType(PhaseNode_Detect::Detect_Type::Interrupt_Skill);
        node131->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(22012, 131, node131)
    }
    if (noInit == true) {
        return node131;
    }
    return node131;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(22012, 132) {
}

REGISTER_CREATE_SKILL_NODE(22012, 132) {
    auto node132 = GET_SKILL_NODE(132, PhaseNode_EndPhase);
    if (node132 == nullptr) {
        node132 = new PhaseNode_EndPhase(132, phase);
        node132->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node132->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(22012, 132, node132)
    }
    if (noInit == true) {
        return node132;
    }
    return node132;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22012, 134) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_Delay::TRIGGER_DONE, 136, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(22012, 134) {
    auto node134 = GET_SKILL_NODE(134, PhaseNode_Delay);
    if (node134 == nullptr) {
        node134 = new PhaseNode_Delay(134, phase);
        node134->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(22012, 134, node134)
    }
    if (noInit == true) {
        return node134;
    }
    return node134;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(22012, 135) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 132, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(22012, 135) {
    auto node135 = GET_SKILL_NODE(135, PhaseNode_SkillEndNotify);
    if (node135 == nullptr) {
        node135 = new PhaseNode_SkillEndNotify(135, phase);
        node135->setReturnType(false);
        CALL_REGISTER_SKILL_NODE(22012, 135, node135)
    }
    if (noInit == true) {
        return node135;
    }
    return node135;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(22012, 136) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_FALSE, 137, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_TRUE, 135, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
}

REGISTER_CREATE_SKILL_NODE(22012, 136) {
    auto node136 = GET_SKILL_NODE(136, PhaseNode_If);
    if (node136 == nullptr) {
        node136 = new PhaseNode_If(136, phase);
        node136->setCondition(false);
        CALL_REGISTER_SKILL_NODE(22012, 136, node136)
    }
    if (noInit == true) {
        return node136;
    }
    return node136;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(22012, 137) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 132, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(22012, 137) {
    auto node137 = GET_SKILL_NODE(137, PhaseNode_SkillEndNotify);
    if (node137 == nullptr) {
        node137 = new PhaseNode_SkillEndNotify(137, phase);
        node137->setReturnType(true);
        CALL_REGISTER_SKILL_NODE(22012, 137, node137)
    }
    if (noInit == true) {
        return node137;
    }
    return node137;
}

//--------------------------------------------------------------------------------
// SkillCreator_22012
//
class SkillCreator_22012 : public SkillCreator {
public:
    SkillCreator_22012() {}
    virtual ~SkillCreator_22012() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_22012

//--------------------------------------------------------------------------------
// SkillPhase_22012
//
class SkillPhase_22012 : public SkillPhase {
public:
    SkillPhase_22012(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_22012() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(22012, 1) // StartPhase
        CASE_CREATE_SKILL_NODE(22012, 2) // TriggerUpdate
        CASE_CREATE_SKILL_NODE(22012, 19) // EndPhase
        CASE_CREATE_SKILL_NODE(22012, 73) // PlaySound
        CASE_CREATE_SKILL_NODE(22012, 74) // SpawnCollider
        CASE_CREATE_SKILL_NODE(22012, 82) // Delay
        CASE_CREATE_SKILL_NODE(22012, 83) // Delay
        CASE_CREATE_SKILL_NODE(22012, 84) // PlaySound
        CASE_CREATE_SKILL_NODE(22012, 85) // Delay
        CASE_CREATE_SKILL_NODE(22012, 86) // PlaySound
        CASE_CREATE_SKILL_NODE(22012, 87) // Delay
        CASE_CREATE_SKILL_NODE(22012, 88) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(22012, 89) // If
        CASE_CREATE_SKILL_NODE(22012, 90) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(22012, 91) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(22012, 92) // TriggerCheck
        CASE_CREATE_SKILL_NODE(22012, 93) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(22012, 94) // GetActorAttribute
        CASE_CREATE_SKILL_NODE(22012, 95) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(22012, 96) // CompareFloat
        CASE_CREATE_SKILL_NODE(22012, 97) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(22012, 98) // If
        CASE_CREATE_SKILL_NODE(22012, 99) // CompareFloat
        CASE_CREATE_SKILL_NODE(22012, 100) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(22012, 101) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(22012, 102) // TriggerCheck
        CASE_CREATE_SKILL_NODE(22012, 103) // TriggerCheck
        CASE_CREATE_SKILL_NODE(22012, 104) // TriggerCheck
        CASE_CREATE_SKILL_NODE(22012, 105) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(22012, 106) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(22012, 107) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(22012, 108) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(22012, 109) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(22012, 110) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(22012, 111) // GetLocation
        CASE_CREATE_SKILL_NODE(22012, 112) // GetRotation
        CASE_CREATE_SKILL_NODE(22012, 113) // OffsetCalculate
        CASE_CREATE_SKILL_NODE(22012, 114) // ResetCD
        CASE_CREATE_SKILL_NODE(22012, 115) // PlayAnimation
        CASE_CREATE_SKILL_NODE(22012, 116) // PlaySound
        CASE_CREATE_SKILL_NODE(22012, 117) // Delay
        CASE_CREATE_SKILL_NODE(22012, 118) // PlayEffect
        CASE_CREATE_SKILL_NODE(22012, 119) // If
        CASE_CREATE_SKILL_NODE(22012, 120) // PlayEffect
        CASE_CREATE_SKILL_NODE(22012, 121) // CompareFloat
        CASE_CREATE_SKILL_NODE(22012, 122) // Delay
        CASE_CREATE_SKILL_NODE(22012, 123) // StopEffect
        CASE_CREATE_SKILL_NODE(22012, 124) // PlayEffect
        CASE_CREATE_SKILL_NODE(22012, 125) // If
        CASE_CREATE_SKILL_NODE(22012, 126) // PlayEffect
        CASE_CREATE_SKILL_NODE(22012, 127) // CompareFloat
        CASE_CREATE_SKILL_NODE(22012, 128) // Delay
        CASE_CREATE_SKILL_NODE(22012, 129) // StopEffect
        CASE_CREATE_SKILL_NODE(22012, 130) // RaiseEvent
        CASE_CREATE_SKILL_NODE(22012, 131) // Detect
        CASE_CREATE_SKILL_NODE(22012, 132) // EndPhase
        CASE_CREATE_SKILL_NODE(22012, 134) // Delay
        CASE_CREATE_SKILL_NODE(22012, 135) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(22012, 136) // If
        CASE_CREATE_SKILL_NODE(22012, 137) // SkillEndNotify
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_22012

SkillLogic* SkillCreator_22012::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //创建阶段phase
    auto phase = new SkillPhase_22012(1, logic, 3);
    //设置phase执行器
    phase->setRunPhaseNode(1, 1);
    phase->setRunPhaseNode(2, 2);
    phase->setDetectPhaseNode(3, 131);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_22012::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
