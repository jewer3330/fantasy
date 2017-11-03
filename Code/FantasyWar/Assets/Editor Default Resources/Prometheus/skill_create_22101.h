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
REGISTER_REGISTER_SKILL_NODE(22101, 3) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_StartPhase::TRIGGER_START, 93, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_StartPhase::TRIGGER_START, 33, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(22101, 3) {
    auto node3 = GET_SKILL_NODE(3, PhaseNode_StartPhase);
    if (node3 == nullptr) {
        node3 = new PhaseNode_StartPhase(3, phase);
        CALL_REGISTER_SKILL_NODE(22101, 3, node3)
    }
    if (noInit == true) {
        return node3;
    }
    return node3;
}
//--------------------------------------------------------------------------------
// TriggerUpdate
//
REGISTER_REGISTER_SKILL_NODE(22101, 7) {
}

REGISTER_CREATE_SKILL_NODE(22101, 7) {
    auto node7 = GET_SKILL_NODE(7, PhaseNode_TriggerUpdate);
    if (node7 == nullptr) {
        node7 = new PhaseNode_TriggerUpdate(7, phase);
        CALL_REGISTER_SKILL_NODE(22101, 7, node7)
    }
    if (noInit == true) {
        return node7;
    }
    return node7;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22101, 10) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_Delay::TRIGGER_DONE, 12, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(22101, 10) {
    auto node10 = GET_SKILL_NODE(10, PhaseNode_Delay);
    if (node10 == nullptr) {
        node10 = new PhaseNode_Delay(10, phase);
        node10->setTime(.40f);
        CALL_REGISTER_SKILL_NODE(22101, 10, node10)
    }
    if (noInit == true) {
        return node10;
    }
    return node10;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(22101, 12) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlayAnimation::TRIGGER_DONE, 14, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_PlayAnimation::TRIGGER_DONE, 65, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(22101, 12) {
    auto node12 = GET_SKILL_NODE(12, PhaseNode_PlayAnimation);
    if (node12 == nullptr) {
        node12 = new PhaseNode_PlayAnimation(12, phase);
        node12->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node12->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node12->setTarget(0U);
        node12->setAnimation("Skill1S2");
        node12->setParameter("");
        node12->setValue(false);
        CALL_REGISTER_SKILL_NODE(22101, 12, node12)
    }
    if (noInit == true) {
        return node12;
    }
    return node12;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22101, 14) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_Delay::TRIGGER_DONE, 16, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(22101, 14) {
    auto node14 = GET_SKILL_NODE(14, PhaseNode_Delay);
    if (node14 == nullptr) {
        node14 = new PhaseNode_Delay(14, phase);
        node14->setTime(4.00f);
        CALL_REGISTER_SKILL_NODE(22101, 14, node14)
    }
    if (noInit == true) {
        return node14;
    }
    return node14;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(22101, 16) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlayAnimation::TRIGGER_DONE, 40, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(22101, 16) {
    auto node16 = GET_SKILL_NODE(16, PhaseNode_PlayAnimation);
    if (node16 == nullptr) {
        node16 = new PhaseNode_PlayAnimation(16, phase);
        node16->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node16->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node16->setTarget(0U);
        node16->setAnimation("Skill1S3");
        node16->setParameter("");
        node16->setValue(false);
        CALL_REGISTER_SKILL_NODE(22101, 16, node16)
    }
    if (noInit == true) {
        return node16;
    }
    return node16;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(22101, 21) {
}

REGISTER_CREATE_SKILL_NODE(22101, 21) {
    auto node21 = GET_SKILL_NODE(21, PhaseNode_EndPhase);
    if (node21 == nullptr) {
        node21 = new PhaseNode_EndPhase(21, phase);
        node21->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node21->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(22101, 21, node21)
    }
    if (noInit == true) {
        return node21;
    }
    return node21;
}
//--------------------------------------------------------------------------------
// SpawnCollider
//
REGISTER_REGISTER_SKILL_NODE(22101, 23) {
    pnode->resizeTrigger(PhaseNode_SpawnCollider::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_SpawnCollider::TRIGGER_DONE, 51, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(22101, 23) {
    auto node23 = GET_SKILL_NODE(23, PhaseNode_SpawnCollider);
    if (node23 == nullptr) {
        node23 = new PhaseNode_SpawnCollider(23, phase);
        node23->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node23->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node23->setMesh("");
        node23->setMeshScale(.00f);
        node23->setEffectID(0);
        node23->setEffectScale(.00f);
        node23->setType(PhaseNode_SpawnCollider::SpawnCollider_Type::Sector);
        node23->setTypeParams(0, 10.00f);
        node23->setTypeParams(1, 30.00f);
        node23->setTime(4.00f);
        node23->setreentry(false);
        node23->setCheckPeneSound(false);
        CALL_REGISTER_SKILL_NODE(22101, 23, node23)
    }
    if (noInit == true) {
        return node23;
    }
    auto node72 = GET_SKILL_NODE(72, PhaseNode_OffsetCalculate);
    if (node72 != nullptr) node23->setPosX(node72->getOutPosX());
    if (node72 != nullptr) node23->setPosY(node72->getOutPosY());
    if (node72 != nullptr) node23->setPosZ(node72->getOutPosZ());
    if (node72 != nullptr) node23->setRotation(node72->getOutRotation());
    return node23;
}
//--------------------------------------------------------------------------------
// SpawnCollider
//
REGISTER_REGISTER_SKILL_NODE(22101, 30) {
    pnode->resizeTrigger(PhaseNode_SpawnCollider::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_SpawnCollider::TRIGGER_DONE, 80, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(22101, 30) {
    auto node30 = GET_SKILL_NODE(30, PhaseNode_SpawnCollider);
    if (node30 == nullptr) {
        node30 = new PhaseNode_SpawnCollider(30, phase);
        node30->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node30->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node30->setMesh("");
        node30->setMeshScale(.00f);
        node30->setEffectID(0);
        node30->setEffectScale(.00f);
        node30->setType(PhaseNode_SpawnCollider::SpawnCollider_Type::Sector);
        node30->setTypeParams(0, 10.00f);
        node30->setTypeParams(1, 30.00f);
        node30->setTime(4.00f);
        node30->setreentry(false);
        node30->setCheckPeneSound(false);
        CALL_REGISTER_SKILL_NODE(22101, 30, node30)
    }
    if (noInit == true) {
        return node30;
    }
    auto node72 = GET_SKILL_NODE(72, PhaseNode_OffsetCalculate);
    if (node72 != nullptr) node30->setPosX(node72->getOutPosX());
    if (node72 != nullptr) node30->setPosY(node72->getOutPosY());
    if (node72 != nullptr) node30->setPosZ(node72->getOutPosZ());
    if (node72 != nullptr) node30->setRotation(node72->getOutRotation());
    return node30;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(22101, 33) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_ResetCD::TRIGGER_DONE, 34, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(22101, 33) {
    auto node33 = GET_SKILL_NODE(33, PhaseNode_ResetCD);
    if (node33 == nullptr) {
        node33 = new PhaseNode_ResetCD(33, phase);
        node33->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node33->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node33->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(22101, 33, node33)
    }
    if (noInit == true) {
        return node33;
    }
    return node33;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(22101, 34) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_PlayAnimation::TRIGGER_DONE, 35, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(22101, 34) {
    auto node34 = GET_SKILL_NODE(34, PhaseNode_PlayAnimation);
    if (node34 == nullptr) {
        node34 = new PhaseNode_PlayAnimation(34, phase);
        node34->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node34->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node34->setTarget(0U);
        node34->setAnimation("Skill1S1");
        node34->setParameter("");
        node34->setValue(false);
        CALL_REGISTER_SKILL_NODE(22101, 34, node34)
    }
    if (noInit == true) {
        return node34;
    }
    return node34;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(22101, 35) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlaySound::TRIGGER_DONE, 36, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(22101, 35) {
    auto node35 = GET_SKILL_NODE(35, PhaseNode_PlaySound);
    if (node35 == nullptr) {
        node35 = new PhaseNode_PlaySound(35, phase);
        node35->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node35->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node35->setSoundID("");
        node35->setTarget(0U);
        node35->setUsePos(false);
        node35->setPosX(.00f);
        node35->setPosY(.00f);
        node35->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(22101, 35, node35)
    }
    if (noInit == true) {
        return node35;
    }
    return node35;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22101, 36) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_Delay::TRIGGER_DONE, 37, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(22101, 36) {
    auto node36 = GET_SKILL_NODE(36, PhaseNode_Delay);
    if (node36 == nullptr) {
        node36 = new PhaseNode_Delay(36, phase);
        node36->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(22101, 36, node36)
    }
    if (noInit == true) {
        return node36;
    }
    return node36;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(22101, 37) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetRotation>(PhaseNode_GetLocation::TRIGGER_DONE, 38, PhaseNode_GetRotation::FUNC_DO, &PhaseNode_GetRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(22101, 37) {
    auto node37 = GET_SKILL_NODE(37, PhaseNode_GetLocation);
    if (node37 == nullptr) {
        node37 = new PhaseNode_GetLocation(37, phase);
        node37->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node37->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(22101, 37, node37)
    }
    if (noInit == true) {
        return node37;
    }
    return node37;
}
//--------------------------------------------------------------------------------
// GetRotation
//
REGISTER_REGISTER_SKILL_NODE(22101, 38) {
    pnode->resizeTrigger(PhaseNode_GetRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_OffsetCalculate>(PhaseNode_GetRotation::TRIGGER_DONE, 39, PhaseNode_OffsetCalculate::FUNC_DO, &PhaseNode_OffsetCalculate::Do);
}

REGISTER_CREATE_SKILL_NODE(22101, 38) {
    auto node38 = GET_SKILL_NODE(38, PhaseNode_GetRotation);
    if (node38 == nullptr) {
        node38 = new PhaseNode_GetRotation(38, phase);
        node38->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node38->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(22101, 38, node38)
    }
    if (noInit == true) {
        return node38;
    }
    return node38;
}
//--------------------------------------------------------------------------------
// OffsetCalculate
//
REGISTER_REGISTER_SKILL_NODE(22101, 39) {
    pnode->resizeTrigger(PhaseNode_OffsetCalculate::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 70, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(22101, 39) {
    auto node39 = GET_SKILL_NODE(39, PhaseNode_OffsetCalculate);
    if (node39 == nullptr) {
        node39 = new PhaseNode_OffsetCalculate(39, phase);
        node39->setPosZ(.00f);
        node39->setOffsetX(.40f);
        node39->setOffsetY(3.80f);
        node39->setOffsetZ(1.80f);
        node39->setRotOffset(.00f);
        CALL_REGISTER_SKILL_NODE(22101, 39, node39)
    }
    if (noInit == true) {
        return node39;
    }
    auto node37 = GET_SKILL_NODE(37, PhaseNode_GetLocation);
    auto node38 = GET_SKILL_NODE(38, PhaseNode_GetRotation);
    if (node37 != nullptr) node39->setPosX(node37->getX());
    if (node37 != nullptr) node39->setPosY(node37->getY());
    if (node38 != nullptr) node39->setRotation(node38->getAngle());
    return node39;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22101, 40) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_Delay::TRIGGER_DONE, 42, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(22101, 40) {
    auto node40 = GET_SKILL_NODE(40, PhaseNode_Delay);
    if (node40 == nullptr) {
        node40 = new PhaseNode_Delay(40, phase);
        node40->setTime(.40f);
        CALL_REGISTER_SKILL_NODE(22101, 40, node40)
    }
    if (noInit == true) {
        return node40;
    }
    return node40;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(22101, 41) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 21, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(22101, 41) {
    auto node41 = GET_SKILL_NODE(41, PhaseNode_SkillEndNotify);
    if (node41 == nullptr) {
        node41 = new PhaseNode_SkillEndNotify(41, phase);
        node41->setReturnType(false);
        CALL_REGISTER_SKILL_NODE(22101, 41, node41)
    }
    if (noInit == true) {
        return node41;
    }
    return node41;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(22101, 42) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_FALSE, 43, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_TRUE, 41, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
}

REGISTER_CREATE_SKILL_NODE(22101, 42) {
    auto node42 = GET_SKILL_NODE(42, PhaseNode_If);
    if (node42 == nullptr) {
        node42 = new PhaseNode_If(42, phase);
        node42->setCondition(false);
        CALL_REGISTER_SKILL_NODE(22101, 42, node42)
    }
    if (noInit == true) {
        return node42;
    }
    return node42;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(22101, 43) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 21, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(22101, 43) {
    auto node43 = GET_SKILL_NODE(43, PhaseNode_SkillEndNotify);
    if (node43 == nullptr) {
        node43 = new PhaseNode_SkillEndNotify(43, phase);
        node43->setReturnType(true);
        CALL_REGISTER_SKILL_NODE(22101, 43, node43)
    }
    if (noInit == true) {
        return node43;
    }
    return node43;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(22101, 44) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 56, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 58, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(22101, 44) {
    auto node44 = GET_SKILL_NODE(44, PhaseNode_CreateTriggerNewPene);
    if (node44 == nullptr) {
        node44 = new PhaseNode_CreateTriggerNewPene(44, phase);
        node44->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::In);
        node44->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node44->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Enemy);
        node44->setOnHero(true);
        node44->setOnMinion(true);
        node44->setOnDestruct(false);
        node44->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(22101, 44, node44)
    }
    if (noInit == true) {
        return node44;
    }
    auto node23 = GET_SKILL_NODE(23, PhaseNode_SpawnCollider);
    if (node23 != nullptr) node44->setColliderID(node23->getColliderID());
    return node44;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(22101, 45) {
}

REGISTER_CREATE_SKILL_NODE(22101, 45) {
    auto node45 = GET_SKILL_NODE(45, PhaseNode_TriggerCheck);
    if (node45 == nullptr) {
        node45 = new PhaseNode_TriggerCheck(45, phase);
        auto node7 = GET_SKILL_NODE(7, PhaseNode_TriggerUpdate);
        if (node7 != nullptr) node7->addTriggerCheck(node45);
        
        CALL_REGISTER_SKILL_NODE(22101, 45, node45)
    }
    if (noInit == true) {
        return node45;
    }
    auto node54 = GET_SKILL_NODE(54, PhaseNode_CreateTriggerNewPene);
    if (node54 != nullptr) node45->setTrigger(0, node54->getTriggerID());
    return node45;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(22101, 46) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 47, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(22101, 46) {
    auto node46 = GET_SKILL_NODE(46, PhaseNode_ActorFilterNewPene);
    if (node46 == nullptr) {
        node46 = new PhaseNode_ActorFilterNewPene(46, phase);
        node46->setHero(true);
        node46->setMinion(true);
        node46->setDestruct(false);
        node46->setShield(false);
        node46->setTotalCount(0);
        node46->setPerCount(0);
        CALL_REGISTER_SKILL_NODE(22101, 46, node46)
    }
    if (noInit == true) {
        return node46;
    }
    auto node50 = GET_SKILL_NODE(50, PhaseNode_CreateTriggerNewPene);
    if (node50 != nullptr) node46->setInput(node50->getOther());
    return node46;
}
//--------------------------------------------------------------------------------
// GetActorAttribute
//
REGISTER_REGISTER_SKILL_NODE(22101, 47) {
    pnode->resizeTrigger(PhaseNode_GetActorAttribute::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 48, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 61, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 62, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 63, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
}

REGISTER_CREATE_SKILL_NODE(22101, 47) {
    auto node47 = GET_SKILL_NODE(47, PhaseNode_GetActorAttribute);
    if (node47 == nullptr) {
        node47 = new PhaseNode_GetActorAttribute(47, phase);
        node47->setTarget(0U);
        node47->setType({202});
        CALL_REGISTER_SKILL_NODE(22101, 47, node47)
    }
    if (noInit == true) {
        return node47;
    }
    return node47;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(22101, 48) {
}

REGISTER_CREATE_SKILL_NODE(22101, 48) {
    auto node48 = GET_SKILL_NODE(48, PhaseNode_AddSkillBuffs);
    if (node48 == nullptr) {
        node48 = new PhaseNode_AddSkillBuffs(48, phase);
        node48->setConfigID({19});
        CALL_REGISTER_SKILL_NODE(22101, 48, node48)
    }
    if (noInit == true) {
        return node48;
    }
    auto node46 = GET_SKILL_NODE(46, PhaseNode_ActorFilterNewPene);
    auto node47 = GET_SKILL_NODE(47, PhaseNode_GetActorAttribute);
    if (node46 != nullptr) node48->setTarget(node46->getOutput());
    if (node47 != nullptr) node48->setAttribute(node47->getAttribute());
    return node48;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(22101, 49) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 44, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_LESS, 50, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
}

REGISTER_CREATE_SKILL_NODE(22101, 49) {
    auto node49 = GET_SKILL_NODE(49, PhaseNode_CompareFloat);
    if (node49 == nullptr) {
        node49 = new PhaseNode_CompareFloat(49, phase);
        node49->setA(.00f);
        node49->setB(.20f);
        CALL_REGISTER_SKILL_NODE(22101, 49, node49)
    }
    if (noInit == true) {
        return node49;
    }
    return node49;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(22101, 50) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 55, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 46, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(22101, 50) {
    auto node50 = GET_SKILL_NODE(50, PhaseNode_CreateTriggerNewPene);
    if (node50 == nullptr) {
        node50 = new PhaseNode_CreateTriggerNewPene(50, phase);
        node50->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::Tick);
        node50->setTypeParams(0, .20f);
        node50->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node50->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Enemy);
        node50->setOnHero(true);
        node50->setOnMinion(true);
        node50->setOnDestruct(false);
        node50->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(22101, 50, node50)
    }
    if (noInit == true) {
        return node50;
    }
    auto node23 = GET_SKILL_NODE(23, PhaseNode_SpawnCollider);
    if (node23 != nullptr) node50->setColliderID(node23->getColliderID());
    return node50;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(22101, 51) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_If::TRIGGER_FALSE, 52, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_If::TRIGGER_TRUE, 49, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(22101, 51) {
    auto node51 = GET_SKILL_NODE(51, PhaseNode_If);
    if (node51 == nullptr) {
        node51 = new PhaseNode_If(51, phase);
        node51->setCondition(true);
        CALL_REGISTER_SKILL_NODE(22101, 51, node51)
    }
    if (noInit == true) {
        return node51;
    }
    return node51;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(22101, 52) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 54, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_LESS, 53, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
}

REGISTER_CREATE_SKILL_NODE(22101, 52) {
    auto node52 = GET_SKILL_NODE(52, PhaseNode_CompareFloat);
    if (node52 == nullptr) {
        node52 = new PhaseNode_CompareFloat(52, phase);
        node52->setA(.00f);
        node52->setB(.20f);
        CALL_REGISTER_SKILL_NODE(22101, 52, node52)
    }
    if (noInit == true) {
        return node52;
    }
    return node52;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(22101, 53) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 57, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 59, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(22101, 53) {
    auto node53 = GET_SKILL_NODE(53, PhaseNode_CreateTriggerNewPene);
    if (node53 == nullptr) {
        node53 = new PhaseNode_CreateTriggerNewPene(53, phase);
        node53->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::Tick);
        node53->setTypeParams(0, .20f);
        node53->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node53->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Friend);
        node53->setOnHero(true);
        node53->setOnMinion(true);
        node53->setOnDestruct(false);
        node53->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(22101, 53, node53)
    }
    if (noInit == true) {
        return node53;
    }
    auto node23 = GET_SKILL_NODE(23, PhaseNode_SpawnCollider);
    if (node23 != nullptr) node53->setColliderID(node23->getColliderID());
    return node53;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(22101, 54) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 45, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 60, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(22101, 54) {
    auto node54 = GET_SKILL_NODE(54, PhaseNode_CreateTriggerNewPene);
    if (node54 == nullptr) {
        node54 = new PhaseNode_CreateTriggerNewPene(54, phase);
        node54->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::In);
        node54->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node54->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Friend);
        node54->setOnHero(true);
        node54->setOnMinion(true);
        node54->setOnDestruct(false);
        node54->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(22101, 54, node54)
    }
    if (noInit == true) {
        return node54;
    }
    auto node23 = GET_SKILL_NODE(23, PhaseNode_SpawnCollider);
    if (node23 != nullptr) node54->setColliderID(node23->getColliderID());
    return node54;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(22101, 55) {
}

REGISTER_CREATE_SKILL_NODE(22101, 55) {
    auto node55 = GET_SKILL_NODE(55, PhaseNode_TriggerCheck);
    if (node55 == nullptr) {
        node55 = new PhaseNode_TriggerCheck(55, phase);
        auto node7 = GET_SKILL_NODE(7, PhaseNode_TriggerUpdate);
        if (node7 != nullptr) node7->addTriggerCheck(node55);
        
        CALL_REGISTER_SKILL_NODE(22101, 55, node55)
    }
    if (noInit == true) {
        return node55;
    }
    auto node50 = GET_SKILL_NODE(50, PhaseNode_CreateTriggerNewPene);
    if (node50 != nullptr) node55->setTrigger(0, node50->getTriggerID());
    return node55;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(22101, 56) {
}

REGISTER_CREATE_SKILL_NODE(22101, 56) {
    auto node56 = GET_SKILL_NODE(56, PhaseNode_TriggerCheck);
    if (node56 == nullptr) {
        node56 = new PhaseNode_TriggerCheck(56, phase);
        auto node7 = GET_SKILL_NODE(7, PhaseNode_TriggerUpdate);
        if (node7 != nullptr) node7->addTriggerCheck(node56);
        
        CALL_REGISTER_SKILL_NODE(22101, 56, node56)
    }
    if (noInit == true) {
        return node56;
    }
    auto node44 = GET_SKILL_NODE(44, PhaseNode_CreateTriggerNewPene);
    if (node44 != nullptr) node56->setTrigger(0, node44->getTriggerID());
    return node56;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(22101, 57) {
}

REGISTER_CREATE_SKILL_NODE(22101, 57) {
    auto node57 = GET_SKILL_NODE(57, PhaseNode_TriggerCheck);
    if (node57 == nullptr) {
        node57 = new PhaseNode_TriggerCheck(57, phase);
        auto node7 = GET_SKILL_NODE(7, PhaseNode_TriggerUpdate);
        if (node7 != nullptr) node7->addTriggerCheck(node57);
        
        CALL_REGISTER_SKILL_NODE(22101, 57, node57)
    }
    if (noInit == true) {
        return node57;
    }
    auto node53 = GET_SKILL_NODE(53, PhaseNode_CreateTriggerNewPene);
    if (node53 != nullptr) node57->setTrigger(0, node53->getTriggerID());
    return node57;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(22101, 58) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 47, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(22101, 58) {
    auto node58 = GET_SKILL_NODE(58, PhaseNode_ActorFilterNewPene);
    if (node58 == nullptr) {
        node58 = new PhaseNode_ActorFilterNewPene(58, phase);
        node58->setHero(true);
        node58->setMinion(true);
        node58->setDestruct(false);
        node58->setShield(false);
        node58->setTotalCount(0);
        node58->setPerCount(0);
        CALL_REGISTER_SKILL_NODE(22101, 58, node58)
    }
    if (noInit == true) {
        return node58;
    }
    auto node44 = GET_SKILL_NODE(44, PhaseNode_CreateTriggerNewPene);
    if (node44 != nullptr) node58->setInput(node44->getOther());
    return node58;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(22101, 59) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 47, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(22101, 59) {
    auto node59 = GET_SKILL_NODE(59, PhaseNode_ActorFilterNewPene);
    if (node59 == nullptr) {
        node59 = new PhaseNode_ActorFilterNewPene(59, phase);
        node59->setHero(true);
        node59->setMinion(true);
        node59->setDestruct(false);
        node59->setShield(false);
        node59->setTotalCount(0);
        node59->setPerCount(0);
        CALL_REGISTER_SKILL_NODE(22101, 59, node59)
    }
    if (noInit == true) {
        return node59;
    }
    auto node53 = GET_SKILL_NODE(53, PhaseNode_CreateTriggerNewPene);
    if (node53 != nullptr) node59->setInput(node53->getOther());
    return node59;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(22101, 60) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 47, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(22101, 60) {
    auto node60 = GET_SKILL_NODE(60, PhaseNode_ActorFilterNewPene);
    if (node60 == nullptr) {
        node60 = new PhaseNode_ActorFilterNewPene(60, phase);
        node60->setHero(true);
        node60->setMinion(true);
        node60->setDestruct(false);
        node60->setShield(false);
        node60->setTotalCount(0);
        node60->setPerCount(0);
        CALL_REGISTER_SKILL_NODE(22101, 60, node60)
    }
    if (noInit == true) {
        return node60;
    }
    auto node54 = GET_SKILL_NODE(54, PhaseNode_CreateTriggerNewPene);
    if (node54 != nullptr) node60->setInput(node54->getOther());
    return node60;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(22101, 61) {
}

REGISTER_CREATE_SKILL_NODE(22101, 61) {
    auto node61 = GET_SKILL_NODE(61, PhaseNode_AddSkillBuffs);
    if (node61 == nullptr) {
        node61 = new PhaseNode_AddSkillBuffs(61, phase);
        node61->setConfigID({19});
        CALL_REGISTER_SKILL_NODE(22101, 61, node61)
    }
    if (noInit == true) {
        return node61;
    }
    auto node58 = GET_SKILL_NODE(58, PhaseNode_ActorFilterNewPene);
    auto node47 = GET_SKILL_NODE(47, PhaseNode_GetActorAttribute);
    if (node58 != nullptr) node61->setTarget(node58->getOutput());
    if (node47 != nullptr) node61->setAttribute(node47->getAttribute());
    return node61;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(22101, 62) {
}

REGISTER_CREATE_SKILL_NODE(22101, 62) {
    auto node62 = GET_SKILL_NODE(62, PhaseNode_AddSkillBuffs);
    if (node62 == nullptr) {
        node62 = new PhaseNode_AddSkillBuffs(62, phase);
        node62->setConfigID({19});
        CALL_REGISTER_SKILL_NODE(22101, 62, node62)
    }
    if (noInit == true) {
        return node62;
    }
    auto node59 = GET_SKILL_NODE(59, PhaseNode_ActorFilterNewPene);
    auto node47 = GET_SKILL_NODE(47, PhaseNode_GetActorAttribute);
    if (node59 != nullptr) node62->setTarget(node59->getOutput());
    if (node47 != nullptr) node62->setAttribute(node47->getAttribute());
    return node62;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(22101, 63) {
}

REGISTER_CREATE_SKILL_NODE(22101, 63) {
    auto node63 = GET_SKILL_NODE(63, PhaseNode_AddSkillBuffs);
    if (node63 == nullptr) {
        node63 = new PhaseNode_AddSkillBuffs(63, phase);
        node63->setConfigID({19});
        CALL_REGISTER_SKILL_NODE(22101, 63, node63)
    }
    if (noInit == true) {
        return node63;
    }
    auto node60 = GET_SKILL_NODE(60, PhaseNode_ActorFilterNewPene);
    auto node47 = GET_SKILL_NODE(47, PhaseNode_GetActorAttribute);
    if (node60 != nullptr) node63->setTarget(node60->getOutput());
    if (node47 != nullptr) node63->setAttribute(node47->getAttribute());
    return node63;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(22101, 64) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_PlayEffect::TRIGGER_DONE, 67, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(22101, 64) {
    auto node64 = GET_SKILL_NODE(64, PhaseNode_PlayEffect);
    if (node64 == nullptr) {
        node64 = new PhaseNode_PlayEffect(64, phase);
        node64->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node64->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node64->setEffectID(221011);
        node64->setChangeColor(false);
        node64->setType(PhaseNode_PlayEffect::PlayEffect_Type::WithTarget);
        node64->getVars().reserve(5);
        node64->getVars().setVariable<uint64_t>(0, 0U);
        node64->getVars().setVariable<std::string>(1, "Muzzle");
        node64->getVars().setVariable<float>(2, .00f);
        node64->getVars().setVariable<float>(3, .00f);
        node64->getVars().setVariable<float>(4, .00f);
        node64->setRotation(.00f);
        node64->setScale(.00f);
        CALL_REGISTER_SKILL_NODE(22101, 64, node64)
    }
    if (noInit == true) {
        return node64;
    }
    return node64;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(22101, 65) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_FALSE, 66, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_TRUE, 64, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(22101, 65) {
    auto node65 = GET_SKILL_NODE(65, PhaseNode_If);
    if (node65 == nullptr) {
        node65 = new PhaseNode_If(65, phase);
        node65->setCondition(true);
        CALL_REGISTER_SKILL_NODE(22101, 65, node65)
    }
    if (noInit == true) {
        return node65;
    }
    return node65;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(22101, 66) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_PlayEffect::TRIGGER_DONE, 67, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(22101, 66) {
    auto node66 = GET_SKILL_NODE(66, PhaseNode_PlayEffect);
    if (node66 == nullptr) {
        node66 = new PhaseNode_PlayEffect(66, phase);
        node66->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node66->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node66->setEffectID(221011);
        node66->setChangeColor(false);
        node66->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node66->getVars().reserve(3);
        node66->getVars().setVariable<float>(0, .00f);
        node66->getVars().setVariable<float>(1, .00f);
        node66->getVars().setVariable<float>(2, .00f);
        node66->setRotation(.00f);
        node66->setScale(.00f);
        CALL_REGISTER_SKILL_NODE(22101, 66, node66)
    }
    if (noInit == true) {
        return node66;
    }
    return node66;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(22101, 67) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnCollider>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 23, PhaseNode_SpawnCollider::FUNC_DO, &PhaseNode_SpawnCollider::Do);
    pnode->regTrigger<PhaseNode_SpawnCollider>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 30, PhaseNode_SpawnCollider::FUNC_DO, &PhaseNode_SpawnCollider::Do);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_LESS, 68, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_SpawnCollider>(PhaseNode_CompareFloat::TRIGGER_LESS, 23, PhaseNode_SpawnCollider::FUNC_DO, &PhaseNode_SpawnCollider::Do);
    pnode->regTrigger<PhaseNode_SpawnCollider>(PhaseNode_CompareFloat::TRIGGER_LESS, 30, PhaseNode_SpawnCollider::FUNC_DO, &PhaseNode_SpawnCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(22101, 67) {
    auto node67 = GET_SKILL_NODE(67, PhaseNode_CompareFloat);
    if (node67 == nullptr) {
        node67 = new PhaseNode_CompareFloat(67, phase);
        node67->setA(.00f);
        node67->setB(4.00f);
        CALL_REGISTER_SKILL_NODE(22101, 67, node67)
    }
    if (noInit == true) {
        return node67;
    }
    return node67;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22101, 68) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StopEffect>(PhaseNode_Delay::TRIGGER_DONE, 69, PhaseNode_StopEffect::FUNC_DO, &PhaseNode_StopEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(22101, 68) {
    auto node68 = GET_SKILL_NODE(68, PhaseNode_Delay);
    if (node68 == nullptr) {
        node68 = new PhaseNode_Delay(68, phase);
        node68->setTime(4.00f);
        CALL_REGISTER_SKILL_NODE(22101, 68, node68)
    }
    if (noInit == true) {
        return node68;
    }
    return node68;
}
//--------------------------------------------------------------------------------
// StopEffect
//
REGISTER_REGISTER_SKILL_NODE(22101, 69) {
}

REGISTER_CREATE_SKILL_NODE(22101, 69) {
    auto node69 = GET_SKILL_NODE(69, PhaseNode_StopEffect);
    if (node69 == nullptr) {
        node69 = new PhaseNode_StopEffect(69, phase);
        node69->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node69->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node69->setEffectID(221011);
        CALL_REGISTER_SKILL_NODE(22101, 69, node69)
    }
    if (noInit == true) {
        return node69;
    }
    return node69;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(22101, 70) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetRotation>(PhaseNode_GetLocation::TRIGGER_DONE, 71, PhaseNode_GetRotation::FUNC_DO, &PhaseNode_GetRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(22101, 70) {
    auto node70 = GET_SKILL_NODE(70, PhaseNode_GetLocation);
    if (node70 == nullptr) {
        node70 = new PhaseNode_GetLocation(70, phase);
        node70->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node70->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(22101, 70, node70)
    }
    if (noInit == true) {
        return node70;
    }
    return node70;
}
//--------------------------------------------------------------------------------
// GetRotation
//
REGISTER_REGISTER_SKILL_NODE(22101, 71) {
    pnode->resizeTrigger(PhaseNode_GetRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_OffsetCalculate>(PhaseNode_GetRotation::TRIGGER_DONE, 72, PhaseNode_OffsetCalculate::FUNC_DO, &PhaseNode_OffsetCalculate::Do);
}

REGISTER_CREATE_SKILL_NODE(22101, 71) {
    auto node71 = GET_SKILL_NODE(71, PhaseNode_GetRotation);
    if (node71 == nullptr) {
        node71 = new PhaseNode_GetRotation(71, phase);
        node71->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node71->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(22101, 71, node71)
    }
    if (noInit == true) {
        return node71;
    }
    return node71;
}
//--------------------------------------------------------------------------------
// OffsetCalculate
//
REGISTER_REGISTER_SKILL_NODE(22101, 72) {
    pnode->resizeTrigger(PhaseNode_OffsetCalculate::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 10, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(22101, 72) {
    auto node72 = GET_SKILL_NODE(72, PhaseNode_OffsetCalculate);
    if (node72 == nullptr) {
        node72 = new PhaseNode_OffsetCalculate(72, phase);
        node72->setPosZ(.00f);
        node72->setOffsetX(.00f);
        node72->setOffsetY(.00f);
        node72->setOffsetZ(.00f);
        node72->setRotOffset(.00f);
        CALL_REGISTER_SKILL_NODE(22101, 72, node72)
    }
    if (noInit == true) {
        return node72;
    }
    auto node70 = GET_SKILL_NODE(70, PhaseNode_GetLocation);
    auto node71 = GET_SKILL_NODE(71, PhaseNode_GetRotation);
    if (node70 != nullptr) node72->setPosX(node70->getX());
    if (node70 != nullptr) node72->setPosY(node70->getY());
    if (node71 != nullptr) node72->setRotation(node71->getAngle());
    return node72;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(22101, 73) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 85, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 87, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(22101, 73) {
    auto node73 = GET_SKILL_NODE(73, PhaseNode_CreateTriggerNewPene);
    if (node73 == nullptr) {
        node73 = new PhaseNode_CreateTriggerNewPene(73, phase);
        node73->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::In);
        node73->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node73->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Enemy);
        node73->setOnHero(true);
        node73->setOnMinion(true);
        node73->setOnDestruct(false);
        node73->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(22101, 73, node73)
    }
    if (noInit == true) {
        return node73;
    }
    auto node30 = GET_SKILL_NODE(30, PhaseNode_SpawnCollider);
    if (node30 != nullptr) node73->setColliderID(node30->getColliderID());
    return node73;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(22101, 74) {
}

REGISTER_CREATE_SKILL_NODE(22101, 74) {
    auto node74 = GET_SKILL_NODE(74, PhaseNode_TriggerCheck);
    if (node74 == nullptr) {
        node74 = new PhaseNode_TriggerCheck(74, phase);
        auto node7 = GET_SKILL_NODE(7, PhaseNode_TriggerUpdate);
        if (node7 != nullptr) node7->addTriggerCheck(node74);
        
        CALL_REGISTER_SKILL_NODE(22101, 74, node74)
    }
    if (noInit == true) {
        return node74;
    }
    auto node83 = GET_SKILL_NODE(83, PhaseNode_CreateTriggerNewPene);
    if (node83 != nullptr) node74->setTrigger(0, node83->getTriggerID());
    return node74;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(22101, 75) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 76, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(22101, 75) {
    auto node75 = GET_SKILL_NODE(75, PhaseNode_ActorFilterNewPene);
    if (node75 == nullptr) {
        node75 = new PhaseNode_ActorFilterNewPene(75, phase);
        node75->setHero(true);
        node75->setMinion(true);
        node75->setDestruct(false);
        node75->setShield(false);
        node75->setTotalCount(0);
        node75->setPerCount(0);
        CALL_REGISTER_SKILL_NODE(22101, 75, node75)
    }
    if (noInit == true) {
        return node75;
    }
    auto node79 = GET_SKILL_NODE(79, PhaseNode_CreateTriggerNewPene);
    if (node79 != nullptr) node75->setInput(node79->getOther());
    return node75;
}
//--------------------------------------------------------------------------------
// GetActorAttribute
//
REGISTER_REGISTER_SKILL_NODE(22101, 76) {
    pnode->resizeTrigger(PhaseNode_GetActorAttribute::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 77, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 90, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 91, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 92, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
}

REGISTER_CREATE_SKILL_NODE(22101, 76) {
    auto node76 = GET_SKILL_NODE(76, PhaseNode_GetActorAttribute);
    if (node76 == nullptr) {
        node76 = new PhaseNode_GetActorAttribute(76, phase);
        node76->setTarget(0U);
        node76->setType({202});
        CALL_REGISTER_SKILL_NODE(22101, 76, node76)
    }
    if (noInit == true) {
        return node76;
    }
    return node76;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(22101, 77) {
}

REGISTER_CREATE_SKILL_NODE(22101, 77) {
    auto node77 = GET_SKILL_NODE(77, PhaseNode_AddSkillBuffs);
    if (node77 == nullptr) {
        node77 = new PhaseNode_AddSkillBuffs(77, phase);
        node77->setConfigID({220411});
        CALL_REGISTER_SKILL_NODE(22101, 77, node77)
    }
    if (noInit == true) {
        return node77;
    }
    auto node75 = GET_SKILL_NODE(75, PhaseNode_ActorFilterNewPene);
    auto node76 = GET_SKILL_NODE(76, PhaseNode_GetActorAttribute);
    if (node75 != nullptr) node77->setTarget(node75->getOutput());
    if (node76 != nullptr) node77->setAttribute(node76->getAttribute());
    return node77;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(22101, 78) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 73, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_LESS, 79, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
}

REGISTER_CREATE_SKILL_NODE(22101, 78) {
    auto node78 = GET_SKILL_NODE(78, PhaseNode_CompareFloat);
    if (node78 == nullptr) {
        node78 = new PhaseNode_CompareFloat(78, phase);
        node78->setA(.00f);
        node78->setB(.20f);
        CALL_REGISTER_SKILL_NODE(22101, 78, node78)
    }
    if (noInit == true) {
        return node78;
    }
    return node78;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(22101, 79) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 84, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 75, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(22101, 79) {
    auto node79 = GET_SKILL_NODE(79, PhaseNode_CreateTriggerNewPene);
    if (node79 == nullptr) {
        node79 = new PhaseNode_CreateTriggerNewPene(79, phase);
        node79->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::Tick);
        node79->setTypeParams(0, .20f);
        node79->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node79->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Enemy);
        node79->setOnHero(true);
        node79->setOnMinion(true);
        node79->setOnDestruct(false);
        node79->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(22101, 79, node79)
    }
    if (noInit == true) {
        return node79;
    }
    auto node30 = GET_SKILL_NODE(30, PhaseNode_SpawnCollider);
    if (node30 != nullptr) node79->setColliderID(node30->getColliderID());
    return node79;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(22101, 80) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_If::TRIGGER_FALSE, 81, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_If::TRIGGER_TRUE, 78, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(22101, 80) {
    auto node80 = GET_SKILL_NODE(80, PhaseNode_If);
    if (node80 == nullptr) {
        node80 = new PhaseNode_If(80, phase);
        node80->setCondition(true);
        CALL_REGISTER_SKILL_NODE(22101, 80, node80)
    }
    if (noInit == true) {
        return node80;
    }
    return node80;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(22101, 81) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 83, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_LESS, 82, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
}

REGISTER_CREATE_SKILL_NODE(22101, 81) {
    auto node81 = GET_SKILL_NODE(81, PhaseNode_CompareFloat);
    if (node81 == nullptr) {
        node81 = new PhaseNode_CompareFloat(81, phase);
        node81->setA(.00f);
        node81->setB(.20f);
        CALL_REGISTER_SKILL_NODE(22101, 81, node81)
    }
    if (noInit == true) {
        return node81;
    }
    return node81;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(22101, 82) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 86, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 88, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(22101, 82) {
    auto node82 = GET_SKILL_NODE(82, PhaseNode_CreateTriggerNewPene);
    if (node82 == nullptr) {
        node82 = new PhaseNode_CreateTriggerNewPene(82, phase);
        node82->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::Tick);
        node82->setTypeParams(0, .20f);
        node82->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node82->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Friend);
        node82->setOnHero(true);
        node82->setOnMinion(true);
        node82->setOnDestruct(false);
        node82->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(22101, 82, node82)
    }
    if (noInit == true) {
        return node82;
    }
    auto node30 = GET_SKILL_NODE(30, PhaseNode_SpawnCollider);
    if (node30 != nullptr) node82->setColliderID(node30->getColliderID());
    return node82;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(22101, 83) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 74, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 89, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(22101, 83) {
    auto node83 = GET_SKILL_NODE(83, PhaseNode_CreateTriggerNewPene);
    if (node83 == nullptr) {
        node83 = new PhaseNode_CreateTriggerNewPene(83, phase);
        node83->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::In);
        node83->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node83->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Friend);
        node83->setOnHero(true);
        node83->setOnMinion(true);
        node83->setOnDestruct(false);
        node83->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(22101, 83, node83)
    }
    if (noInit == true) {
        return node83;
    }
    auto node30 = GET_SKILL_NODE(30, PhaseNode_SpawnCollider);
    if (node30 != nullptr) node83->setColliderID(node30->getColliderID());
    return node83;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(22101, 84) {
}

REGISTER_CREATE_SKILL_NODE(22101, 84) {
    auto node84 = GET_SKILL_NODE(84, PhaseNode_TriggerCheck);
    if (node84 == nullptr) {
        node84 = new PhaseNode_TriggerCheck(84, phase);
        auto node7 = GET_SKILL_NODE(7, PhaseNode_TriggerUpdate);
        if (node7 != nullptr) node7->addTriggerCheck(node84);
        
        CALL_REGISTER_SKILL_NODE(22101, 84, node84)
    }
    if (noInit == true) {
        return node84;
    }
    auto node79 = GET_SKILL_NODE(79, PhaseNode_CreateTriggerNewPene);
    if (node79 != nullptr) node84->setTrigger(0, node79->getTriggerID());
    return node84;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(22101, 85) {
}

REGISTER_CREATE_SKILL_NODE(22101, 85) {
    auto node85 = GET_SKILL_NODE(85, PhaseNode_TriggerCheck);
    if (node85 == nullptr) {
        node85 = new PhaseNode_TriggerCheck(85, phase);
        auto node7 = GET_SKILL_NODE(7, PhaseNode_TriggerUpdate);
        if (node7 != nullptr) node7->addTriggerCheck(node85);
        
        CALL_REGISTER_SKILL_NODE(22101, 85, node85)
    }
    if (noInit == true) {
        return node85;
    }
    auto node73 = GET_SKILL_NODE(73, PhaseNode_CreateTriggerNewPene);
    if (node73 != nullptr) node85->setTrigger(0, node73->getTriggerID());
    return node85;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(22101, 86) {
}

REGISTER_CREATE_SKILL_NODE(22101, 86) {
    auto node86 = GET_SKILL_NODE(86, PhaseNode_TriggerCheck);
    if (node86 == nullptr) {
        node86 = new PhaseNode_TriggerCheck(86, phase);
        auto node7 = GET_SKILL_NODE(7, PhaseNode_TriggerUpdate);
        if (node7 != nullptr) node7->addTriggerCheck(node86);
        
        CALL_REGISTER_SKILL_NODE(22101, 86, node86)
    }
    if (noInit == true) {
        return node86;
    }
    auto node82 = GET_SKILL_NODE(82, PhaseNode_CreateTriggerNewPene);
    if (node82 != nullptr) node86->setTrigger(0, node82->getTriggerID());
    return node86;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(22101, 87) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 76, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(22101, 87) {
    auto node87 = GET_SKILL_NODE(87, PhaseNode_ActorFilterNewPene);
    if (node87 == nullptr) {
        node87 = new PhaseNode_ActorFilterNewPene(87, phase);
        node87->setHero(true);
        node87->setMinion(true);
        node87->setDestruct(false);
        node87->setShield(false);
        node87->setTotalCount(0);
        node87->setPerCount(0);
        CALL_REGISTER_SKILL_NODE(22101, 87, node87)
    }
    if (noInit == true) {
        return node87;
    }
    auto node73 = GET_SKILL_NODE(73, PhaseNode_CreateTriggerNewPene);
    if (node73 != nullptr) node87->setInput(node73->getOther());
    return node87;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(22101, 88) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 76, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(22101, 88) {
    auto node88 = GET_SKILL_NODE(88, PhaseNode_ActorFilterNewPene);
    if (node88 == nullptr) {
        node88 = new PhaseNode_ActorFilterNewPene(88, phase);
        node88->setHero(true);
        node88->setMinion(true);
        node88->setDestruct(false);
        node88->setShield(false);
        node88->setTotalCount(0);
        node88->setPerCount(0);
        CALL_REGISTER_SKILL_NODE(22101, 88, node88)
    }
    if (noInit == true) {
        return node88;
    }
    auto node82 = GET_SKILL_NODE(82, PhaseNode_CreateTriggerNewPene);
    if (node82 != nullptr) node88->setInput(node82->getOther());
    return node88;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(22101, 89) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 76, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(22101, 89) {
    auto node89 = GET_SKILL_NODE(89, PhaseNode_ActorFilterNewPene);
    if (node89 == nullptr) {
        node89 = new PhaseNode_ActorFilterNewPene(89, phase);
        node89->setHero(true);
        node89->setMinion(true);
        node89->setDestruct(false);
        node89->setShield(false);
        node89->setTotalCount(0);
        node89->setPerCount(0);
        CALL_REGISTER_SKILL_NODE(22101, 89, node89)
    }
    if (noInit == true) {
        return node89;
    }
    auto node83 = GET_SKILL_NODE(83, PhaseNode_CreateTriggerNewPene);
    if (node83 != nullptr) node89->setInput(node83->getOther());
    return node89;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(22101, 90) {
}

REGISTER_CREATE_SKILL_NODE(22101, 90) {
    auto node90 = GET_SKILL_NODE(90, PhaseNode_AddSkillBuffs);
    if (node90 == nullptr) {
        node90 = new PhaseNode_AddSkillBuffs(90, phase);
        node90->setConfigID({220411});
        CALL_REGISTER_SKILL_NODE(22101, 90, node90)
    }
    if (noInit == true) {
        return node90;
    }
    auto node87 = GET_SKILL_NODE(87, PhaseNode_ActorFilterNewPene);
    auto node76 = GET_SKILL_NODE(76, PhaseNode_GetActorAttribute);
    if (node87 != nullptr) node90->setTarget(node87->getOutput());
    if (node76 != nullptr) node90->setAttribute(node76->getAttribute());
    return node90;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(22101, 91) {
}

REGISTER_CREATE_SKILL_NODE(22101, 91) {
    auto node91 = GET_SKILL_NODE(91, PhaseNode_AddSkillBuffs);
    if (node91 == nullptr) {
        node91 = new PhaseNode_AddSkillBuffs(91, phase);
        node91->setConfigID({220411});
        CALL_REGISTER_SKILL_NODE(22101, 91, node91)
    }
    if (noInit == true) {
        return node91;
    }
    auto node88 = GET_SKILL_NODE(88, PhaseNode_ActorFilterNewPene);
    auto node76 = GET_SKILL_NODE(76, PhaseNode_GetActorAttribute);
    if (node88 != nullptr) node91->setTarget(node88->getOutput());
    if (node76 != nullptr) node91->setAttribute(node76->getAttribute());
    return node91;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(22101, 92) {
}

REGISTER_CREATE_SKILL_NODE(22101, 92) {
    auto node92 = GET_SKILL_NODE(92, PhaseNode_AddSkillBuffs);
    if (node92 == nullptr) {
        node92 = new PhaseNode_AddSkillBuffs(92, phase);
        node92->setConfigID({220411});
        CALL_REGISTER_SKILL_NODE(22101, 92, node92)
    }
    if (noInit == true) {
        return node92;
    }
    auto node89 = GET_SKILL_NODE(89, PhaseNode_ActorFilterNewPene);
    auto node76 = GET_SKILL_NODE(76, PhaseNode_GetActorAttribute);
    if (node89 != nullptr) node92->setTarget(node89->getOutput());
    if (node76 != nullptr) node92->setAttribute(node76->getAttribute());
    return node92;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(22101, 93) {
}

REGISTER_CREATE_SKILL_NODE(22101, 93) {
    auto node93 = GET_SKILL_NODE(93, PhaseNode_RaiseEvent);
    if (node93 == nullptr) {
        node93 = new PhaseNode_RaiseEvent(93, phase);
        node93->setEvent("MonsterInterrupt");
        node93->setTarget(0U);
        node93->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node93->setTypeParams(0, 0);
        node93->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(22101, 93, node93)
    }
    if (noInit == true) {
        return node93;
    }
    return node93;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(22101, 94) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_Detect::TRIGGER_ON, 97, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(22101, 94) {
    auto node94 = GET_SKILL_NODE(94, PhaseNode_Detect);
    if (node94 == nullptr) {
        node94 = new PhaseNode_Detect(94, phase);
        node94->setSelf(0U);
        node94->setEvent("MonsterInterrupt");
        node94->setType(PhaseNode_Detect::Detect_Type::Interrupt_Skill);
        node94->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(22101, 94, node94)
    }
    if (noInit == true) {
        return node94;
    }
    return node94;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(22101, 95) {
}

REGISTER_CREATE_SKILL_NODE(22101, 95) {
    auto node95 = GET_SKILL_NODE(95, PhaseNode_EndPhase);
    if (node95 == nullptr) {
        node95 = new PhaseNode_EndPhase(95, phase);
        node95->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node95->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(22101, 95, node95)
    }
    if (noInit == true) {
        return node95;
    }
    return node95;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22101, 97) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_Delay::TRIGGER_DONE, 99, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(22101, 97) {
    auto node97 = GET_SKILL_NODE(97, PhaseNode_Delay);
    if (node97 == nullptr) {
        node97 = new PhaseNode_Delay(97, phase);
        node97->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(22101, 97, node97)
    }
    if (noInit == true) {
        return node97;
    }
    return node97;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(22101, 98) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 95, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(22101, 98) {
    auto node98 = GET_SKILL_NODE(98, PhaseNode_SkillEndNotify);
    if (node98 == nullptr) {
        node98 = new PhaseNode_SkillEndNotify(98, phase);
        node98->setReturnType(false);
        CALL_REGISTER_SKILL_NODE(22101, 98, node98)
    }
    if (noInit == true) {
        return node98;
    }
    return node98;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(22101, 99) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_FALSE, 100, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_TRUE, 98, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
}

REGISTER_CREATE_SKILL_NODE(22101, 99) {
    auto node99 = GET_SKILL_NODE(99, PhaseNode_If);
    if (node99 == nullptr) {
        node99 = new PhaseNode_If(99, phase);
        node99->setCondition(false);
        CALL_REGISTER_SKILL_NODE(22101, 99, node99)
    }
    if (noInit == true) {
        return node99;
    }
    return node99;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(22101, 100) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 95, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(22101, 100) {
    auto node100 = GET_SKILL_NODE(100, PhaseNode_SkillEndNotify);
    if (node100 == nullptr) {
        node100 = new PhaseNode_SkillEndNotify(100, phase);
        node100->setReturnType(true);
        CALL_REGISTER_SKILL_NODE(22101, 100, node100)
    }
    if (noInit == true) {
        return node100;
    }
    return node100;
}

//--------------------------------------------------------------------------------
// SkillCreator_22101
//
class SkillCreator_22101 : public SkillCreator {
public:
    SkillCreator_22101() {}
    virtual ~SkillCreator_22101() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_22101

//--------------------------------------------------------------------------------
// SkillPhase_22101
//
class SkillPhase_22101 : public SkillPhase {
public:
    SkillPhase_22101(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_22101() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(22101, 3) // StartPhase
        CASE_CREATE_SKILL_NODE(22101, 7) // TriggerUpdate
        CASE_CREATE_SKILL_NODE(22101, 10) // Delay
        CASE_CREATE_SKILL_NODE(22101, 12) // PlayAnimation
        CASE_CREATE_SKILL_NODE(22101, 14) // Delay
        CASE_CREATE_SKILL_NODE(22101, 16) // PlayAnimation
        CASE_CREATE_SKILL_NODE(22101, 21) // EndPhase
        CASE_CREATE_SKILL_NODE(22101, 23) // SpawnCollider
        CASE_CREATE_SKILL_NODE(22101, 30) // SpawnCollider
        CASE_CREATE_SKILL_NODE(22101, 33) // ResetCD
        CASE_CREATE_SKILL_NODE(22101, 34) // PlayAnimation
        CASE_CREATE_SKILL_NODE(22101, 35) // PlaySound
        CASE_CREATE_SKILL_NODE(22101, 36) // Delay
        CASE_CREATE_SKILL_NODE(22101, 37) // GetLocation
        CASE_CREATE_SKILL_NODE(22101, 38) // GetRotation
        CASE_CREATE_SKILL_NODE(22101, 39) // OffsetCalculate
        CASE_CREATE_SKILL_NODE(22101, 40) // Delay
        CASE_CREATE_SKILL_NODE(22101, 41) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(22101, 42) // If
        CASE_CREATE_SKILL_NODE(22101, 43) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(22101, 44) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(22101, 45) // TriggerCheck
        CASE_CREATE_SKILL_NODE(22101, 46) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(22101, 47) // GetActorAttribute
        CASE_CREATE_SKILL_NODE(22101, 48) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(22101, 49) // CompareFloat
        CASE_CREATE_SKILL_NODE(22101, 50) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(22101, 51) // If
        CASE_CREATE_SKILL_NODE(22101, 52) // CompareFloat
        CASE_CREATE_SKILL_NODE(22101, 53) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(22101, 54) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(22101, 55) // TriggerCheck
        CASE_CREATE_SKILL_NODE(22101, 56) // TriggerCheck
        CASE_CREATE_SKILL_NODE(22101, 57) // TriggerCheck
        CASE_CREATE_SKILL_NODE(22101, 58) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(22101, 59) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(22101, 60) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(22101, 61) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(22101, 62) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(22101, 63) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(22101, 64) // PlayEffect
        CASE_CREATE_SKILL_NODE(22101, 65) // If
        CASE_CREATE_SKILL_NODE(22101, 66) // PlayEffect
        CASE_CREATE_SKILL_NODE(22101, 67) // CompareFloat
        CASE_CREATE_SKILL_NODE(22101, 68) // Delay
        CASE_CREATE_SKILL_NODE(22101, 69) // StopEffect
        CASE_CREATE_SKILL_NODE(22101, 70) // GetLocation
        CASE_CREATE_SKILL_NODE(22101, 71) // GetRotation
        CASE_CREATE_SKILL_NODE(22101, 72) // OffsetCalculate
        CASE_CREATE_SKILL_NODE(22101, 73) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(22101, 74) // TriggerCheck
        CASE_CREATE_SKILL_NODE(22101, 75) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(22101, 76) // GetActorAttribute
        CASE_CREATE_SKILL_NODE(22101, 77) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(22101, 78) // CompareFloat
        CASE_CREATE_SKILL_NODE(22101, 79) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(22101, 80) // If
        CASE_CREATE_SKILL_NODE(22101, 81) // CompareFloat
        CASE_CREATE_SKILL_NODE(22101, 82) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(22101, 83) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(22101, 84) // TriggerCheck
        CASE_CREATE_SKILL_NODE(22101, 85) // TriggerCheck
        CASE_CREATE_SKILL_NODE(22101, 86) // TriggerCheck
        CASE_CREATE_SKILL_NODE(22101, 87) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(22101, 88) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(22101, 89) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(22101, 90) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(22101, 91) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(22101, 92) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(22101, 93) // RaiseEvent
        CASE_CREATE_SKILL_NODE(22101, 94) // Detect
        CASE_CREATE_SKILL_NODE(22101, 95) // EndPhase
        CASE_CREATE_SKILL_NODE(22101, 97) // Delay
        CASE_CREATE_SKILL_NODE(22101, 98) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(22101, 99) // If
        CASE_CREATE_SKILL_NODE(22101, 100) // SkillEndNotify
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_22101

SkillLogic* SkillCreator_22101::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //创建阶段phase
    auto phase = new SkillPhase_22101(1, logic, 3);
    //设置phase执行器
    phase->setRunPhaseNode(1, 3);
    phase->setRunPhaseNode(2, 7);
    phase->setDetectPhaseNode(3, 94);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_22101::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
