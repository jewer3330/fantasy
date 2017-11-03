#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

#include "skill_psnode_actorfilternewpene.h"
#include "skill_psnode_addskillbuffs.h"
#include "skill_psnode_attachto.h"
#include "skill_psnode_createtriggernewpene.h"
#include "skill_psnode_delay.h"
#include "skill_psnode_destroycollider.h"
#include "skill_psnode_detect.h"
#include "skill_psnode_disable.h"
#include "skill_psnode_endphase.h"
#include "skill_psnode_getactorattribute.h"
#include "skill_psnode_getinputrotation.h"
#include "skill_psnode_getlocation.h"
#include "skill_psnode_if.h"
#include "skill_psnode_isinterrupttype.h"
#include "skill_psnode_linechecknewpene.h"
#include "skill_psnode_movenewpene.h"
#include "skill_psnode_offsetcalculate.h"
#include "skill_psnode_playanimation.h"
#include "skill_psnode_playeffect.h"
#include "skill_psnode_playsound.h"
#include "skill_psnode_raiseevent.h"
#include "skill_psnode_resetcd.h"
#include "skill_psnode_setbool.h"
#include "skill_psnode_spawncollider.h"
#include "skill_psnode_startphase.h"
#include "skill_psnode_startpreinput.h"
#include "skill_psnode_switchtoint.h"
#include "skill_psnode_triggercheck.h"
#include "skill_psnode_triggerupdate.h"

namespace pvp {

//变量声明
uint64_t Variable_10141_ = 0;
uint64_t Variable_10141_InterruptAnimat = 0;
//--------------------------------------------------------------------------------
// StartPhase
//
REGISTER_REGISTER_SKILL_NODE(10141, 2) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_StartPhase::TRIGGER_START, 191, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(10141, 2) {
    auto node2 = GET_SKILL_NODE(2, PhaseNode_StartPhase);
    if (node2 == nullptr) {
        node2 = new PhaseNode_StartPhase(2, phase);
        CALL_REGISTER_SKILL_NODE(10141, 2, node2)
    }
    if (noInit == true) {
        return node2;
    }
    return node2;
}
//--------------------------------------------------------------------------------
// TriggerUpdate
//
REGISTER_REGISTER_SKILL_NODE(10141, 26) {
}

REGISTER_CREATE_SKILL_NODE(10141, 26) {
    auto node26 = GET_SKILL_NODE(26, PhaseNode_TriggerUpdate);
    if (node26 == nullptr) {
        node26 = new PhaseNode_TriggerUpdate(26, phase);
        CALL_REGISTER_SKILL_NODE(10141, 26, node26)
    }
    if (noInit == true) {
        return node26;
    }
    return node26;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(10141, 60) {
}

REGISTER_CREATE_SKILL_NODE(10141, 60) {
    auto node60 = GET_SKILL_NODE(60, PhaseNode_EndPhase);
    if (node60 == nullptr) {
        node60 = new PhaseNode_EndPhase(60, phase);
        node60->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node60->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10141, 60, node60)
    }
    if (noInit == true) {
        return node60;
    }
    return node60;
}
//--------------------------------------------------------------------------------
// MoveNewPene
//
REGISTER_REGISTER_SKILL_NODE(10141, 107) {
    pnode->resizeTrigger(PhaseNode_MoveNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_DestroyCollider>(PhaseNode_MoveNewPene::TRIGGER_DONE, 146, PhaseNode_DestroyCollider::FUNC_DO, &PhaseNode_DestroyCollider::Do);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_MoveNewPene::TRIGGER_STARTMOVE, 148, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_MoveNewPene::TRIGGER_STARTMOVE, 144, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_MoveNewPene::TRIGGER_STARTMOVE, 182, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(10141, 107) {
    auto node107 = GET_SKILL_NODE(107, PhaseNode_MoveNewPene);
    if (node107 == nullptr) {
        node107 = new PhaseNode_MoveNewPene(107, phase);
        node107->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node107->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node107->setPeneType(PhaseNode_MoveNewPene::MoveNewPene_PeneType::Move);
        node107->setPeneValue(15);
        node107->setType(PhaseNode_MoveNewPene::MoveNewPene_Type::Charge);
        node107->getVars().reserve(4);
        node107->getVars().setVariable<float>(0, 15.00f);
        node107->getVars().setVariable<float>(1, 9.00f);
        node107->getVars().setVariable<float>(2, .00f);
        node107->getVars().setVariable<float>(3, .00f);
        node107->setreentry(false);
        node107->setStopWhenFail(false);
        node107->setCheckFaction(PhaseNode_MoveNewPene::MoveNewPene_CheckFaction::Enemy);
        CALL_REGISTER_SKILL_NODE(10141, 107, node107)
    }
    if (noInit == true) {
        return node107;
    }
    auto node138 = GET_SKILL_NODE(138, PhaseNode_SpawnCollider);
    auto node142 = GET_SKILL_NODE(142, PhaseNode_GetInputRotation);
    if (node138 != nullptr) node107->setTarget(node138->getColliderID());
    if (node142 != nullptr) node107->getVars().setVariable<float>(2, node142->getAngle());
    return node107;
}
//--------------------------------------------------------------------------------
// AttachTo
//
REGISTER_REGISTER_SKILL_NODE(10141, 134) {
    pnode->resizeTrigger(PhaseNode_AttachTo::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_OffsetCalculate>(PhaseNode_AttachTo::TRIGGER_DONE, 184, PhaseNode_OffsetCalculate::FUNC_DO, &PhaseNode_OffsetCalculate::Do);
}

REGISTER_CREATE_SKILL_NODE(10141, 134) {
    auto node134 = GET_SKILL_NODE(134, PhaseNode_AttachTo);
    if (node134 == nullptr) {
        node134 = new PhaseNode_AttachTo(134, phase);
        node134->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node134->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node134->setChild(0U);
        node134->setChangeRotation(false);
        node134->setreentry(false);
        CALL_REGISTER_SKILL_NODE(10141, 134, node134)
    }
    if (noInit == true) {
        return node134;
    }
    auto node138 = GET_SKILL_NODE(138, PhaseNode_SpawnCollider);
    if (node138 != nullptr) node134->setParent(node138->getColliderID());
    return node134;
}
//--------------------------------------------------------------------------------
// SpawnCollider
//
REGISTER_REGISTER_SKILL_NODE(10141, 138) {
    pnode->resizeTrigger(PhaseNode_SpawnCollider::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AttachTo>(PhaseNode_SpawnCollider::TRIGGER_DONE, 134, PhaseNode_AttachTo::FUNC_DO, &PhaseNode_AttachTo::Do);
}

REGISTER_CREATE_SKILL_NODE(10141, 138) {
    auto node138 = GET_SKILL_NODE(138, PhaseNode_SpawnCollider);
    if (node138 == nullptr) {
        node138 = new PhaseNode_SpawnCollider(138, phase);
        node138->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node138->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node138->setMesh("");
        node138->setMeshScale(.00f);
        node138->setEffectID(0);
        node138->setEffectScale(.00f);
        node138->setType(PhaseNode_SpawnCollider::SpawnCollider_Type::Circle);
        node138->setTypeParams(0, .50f);
        node138->setTime(.00f);
        node138->setPosZ(.00f);
        node138->setreentry(false);
        node138->setCheckPeneSound(false);
        CALL_REGISTER_SKILL_NODE(10141, 138, node138)
    }
    if (noInit == true) {
        return node138;
    }
    auto node140 = GET_SKILL_NODE(140, PhaseNode_GetLocation);
    auto node142 = GET_SKILL_NODE(142, PhaseNode_GetInputRotation);
    if (node140 != nullptr) node138->setPosX(node140->getX());
    if (node140 != nullptr) node138->setPosY(node140->getY());
    if (node142 != nullptr) node138->setRotation(node142->getAngle());
    return node138;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(10141, 140) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetInputRotation>(PhaseNode_GetLocation::TRIGGER_DONE, 142, PhaseNode_GetInputRotation::FUNC_DO, &PhaseNode_GetInputRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(10141, 140) {
    auto node140 = GET_SKILL_NODE(140, PhaseNode_GetLocation);
    if (node140 == nullptr) {
        node140 = new PhaseNode_GetLocation(140, phase);
        node140->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node140->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(10141, 140, node140)
    }
    if (noInit == true) {
        return node140;
    }
    return node140;
}
//--------------------------------------------------------------------------------
// GetInputRotation
//
REGISTER_REGISTER_SKILL_NODE(10141, 142) {
    pnode->resizeTrigger(PhaseNode_GetInputRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnCollider>(PhaseNode_GetInputRotation::TRIGGER_DONE, 138, PhaseNode_SpawnCollider::FUNC_DO, &PhaseNode_SpawnCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(10141, 142) {
    auto node142 = GET_SKILL_NODE(142, PhaseNode_GetInputRotation);
    if (node142 == nullptr) {
        node142 = new PhaseNode_GetInputRotation(142, phase);
        node142->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        CALL_REGISTER_SKILL_NODE(10141, 142, node142)
    }
    if (noInit == true) {
        return node142;
    }
    return node142;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10141, 144) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_Delay::TRIGGER_DONE, 172, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10141, 144) {
    auto node144 = GET_SKILL_NODE(144, PhaseNode_Delay);
    if (node144 == nullptr) {
        node144 = new PhaseNode_Delay(144, phase);
        node144->setTime(.15f);
        CALL_REGISTER_SKILL_NODE(10141, 144, node144)
    }
    if (noInit == true) {
        return node144;
    }
    return node144;
}
//--------------------------------------------------------------------------------
// DestroyCollider
//
REGISTER_REGISTER_SKILL_NODE(10141, 146) {
    pnode->resizeTrigger(PhaseNode_DestroyCollider::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_DestroyCollider>(PhaseNode_DestroyCollider::TRIGGER_DONE, 170, PhaseNode_DestroyCollider::FUNC_DO, &PhaseNode_DestroyCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(10141, 146) {
    auto node146 = GET_SKILL_NODE(146, PhaseNode_DestroyCollider);
    if (node146 == nullptr) {
        node146 = new PhaseNode_DestroyCollider(146, phase);
        CALL_REGISTER_SKILL_NODE(10141, 146, node146)
    }
    if (noInit == true) {
        return node146;
    }
    auto node138 = GET_SKILL_NODE(138, PhaseNode_SpawnCollider);
    if (node138 != nullptr) node146->setColliderID(node138->getColliderID());
    return node146;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(10141, 148) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 150, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 190, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(10141, 148) {
    auto node148 = GET_SKILL_NODE(148, PhaseNode_CreateTriggerNewPene);
    if (node148 == nullptr) {
        node148 = new PhaseNode_CreateTriggerNewPene(148, phase);
        node148->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::In);
        node148->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node148->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Enemy);
        node148->setOnHero(true);
        node148->setOnMinion(true);
        node148->setOnDestruct(true);
        node148->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(10141, 148, node148)
    }
    if (noInit == true) {
        return node148;
    }
    auto node167 = GET_SKILL_NODE(167, PhaseNode_SpawnCollider);
    if (node167 != nullptr) node148->setColliderID(node167->getColliderID());
    return node148;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(10141, 150) {
}

REGISTER_CREATE_SKILL_NODE(10141, 150) {
    auto node150 = GET_SKILL_NODE(150, PhaseNode_TriggerCheck);
    if (node150 == nullptr) {
        node150 = new PhaseNode_TriggerCheck(150, phase);
        auto node26 = GET_SKILL_NODE(26, PhaseNode_TriggerUpdate);
        if (node26 != nullptr) node26->addTriggerCheck(node150);
        
        CALL_REGISTER_SKILL_NODE(10141, 150, node150)
    }
    if (noInit == true) {
        return node150;
    }
    auto node148 = GET_SKILL_NODE(148, PhaseNode_CreateTriggerNewPene);
    if (node148 != nullptr) node150->setTrigger(0, node148->getTriggerID());
    return node150;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(10141, 153) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 156, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
}

REGISTER_CREATE_SKILL_NODE(10141, 153) {
    auto node153 = GET_SKILL_NODE(153, PhaseNode_ActorFilterNewPene);
    if (node153 == nullptr) {
        node153 = new PhaseNode_ActorFilterNewPene(153, phase);
        node153->setHero(true);
        node153->setMinion(true);
        node153->setDestruct(true);
        node153->setShield(false);
        node153->setTotalCount(0);
        node153->setPerCount(1);
        CALL_REGISTER_SKILL_NODE(10141, 153, node153)
    }
    if (noInit == true) {
        return node153;
    }
    auto node188 = GET_SKILL_NODE(188, PhaseNode_LineCheckNewPene);
    if (node188 != nullptr) node153->setInput(node188->getOutput());
    return node153;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(10141, 156) {
}

REGISTER_CREATE_SKILL_NODE(10141, 156) {
    auto node156 = GET_SKILL_NODE(156, PhaseNode_AddSkillBuffs);
    if (node156 == nullptr) {
        node156 = new PhaseNode_AddSkillBuffs(156, phase);
        node156->setConfigID({101412,101414});
        CALL_REGISTER_SKILL_NODE(10141, 156, node156)
    }
    if (noInit == true) {
        return node156;
    }
    auto node153 = GET_SKILL_NODE(153, PhaseNode_ActorFilterNewPene);
    auto node194 = GET_SKILL_NODE(194, PhaseNode_GetActorAttribute);
    if (node153 != nullptr) node156->setTarget(node153->getOutput());
    if (node194 != nullptr) node156->setAttribute(node194->getAttribute());
    return node156;
}
//--------------------------------------------------------------------------------
// SpawnCollider
//
REGISTER_REGISTER_SKILL_NODE(10141, 167) {
    pnode->resizeTrigger(PhaseNode_SpawnCollider::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AttachTo>(PhaseNode_SpawnCollider::TRIGGER_DONE, 169, PhaseNode_AttachTo::FUNC_DO, &PhaseNode_AttachTo::Do);
}

REGISTER_CREATE_SKILL_NODE(10141, 167) {
    auto node167 = GET_SKILL_NODE(167, PhaseNode_SpawnCollider);
    if (node167 == nullptr) {
        node167 = new PhaseNode_SpawnCollider(167, phase);
        node167->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node167->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node167->setMesh("");
        node167->setMeshScale(.00f);
        node167->setEffectID(0);
        node167->setEffectScale(.00f);
        node167->setType(PhaseNode_SpawnCollider::SpawnCollider_Type::Circle);
        node167->setTypeParams(0, .75f);
        node167->setTime(.00f);
        node167->setPosZ(.00f);
        node167->setRotation(.00f);
        node167->setreentry(false);
        node167->setCheckPeneSound(false);
        CALL_REGISTER_SKILL_NODE(10141, 167, node167)
    }
    if (noInit == true) {
        return node167;
    }
    auto node184 = GET_SKILL_NODE(184, PhaseNode_OffsetCalculate);
    if (node184 != nullptr) node167->setPosX(node184->getOutPosX());
    if (node184 != nullptr) node167->setPosY(node184->getOutPosY());
    return node167;
}
//--------------------------------------------------------------------------------
// AttachTo
//
REGISTER_REGISTER_SKILL_NODE(10141, 169) {
    pnode->resizeTrigger(PhaseNode_AttachTo::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_MoveNewPene>(PhaseNode_AttachTo::TRIGGER_DONE, 107, PhaseNode_MoveNewPene::FUNC_DO, &PhaseNode_MoveNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(10141, 169) {
    auto node169 = GET_SKILL_NODE(169, PhaseNode_AttachTo);
    if (node169 == nullptr) {
        node169 = new PhaseNode_AttachTo(169, phase);
        node169->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node169->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node169->setChangeRotation(false);
        node169->setreentry(false);
        CALL_REGISTER_SKILL_NODE(10141, 169, node169)
    }
    if (noInit == true) {
        return node169;
    }
    auto node138 = GET_SKILL_NODE(138, PhaseNode_SpawnCollider);
    auto node167 = GET_SKILL_NODE(167, PhaseNode_SpawnCollider);
    if (node138 != nullptr) node169->setParent(node138->getColliderID());
    if (node167 != nullptr) node169->setChild(node167->getColliderID());
    return node169;
}
//--------------------------------------------------------------------------------
// DestroyCollider
//
REGISTER_REGISTER_SKILL_NODE(10141, 170) {
}

REGISTER_CREATE_SKILL_NODE(10141, 170) {
    auto node170 = GET_SKILL_NODE(170, PhaseNode_DestroyCollider);
    if (node170 == nullptr) {
        node170 = new PhaseNode_DestroyCollider(170, phase);
        CALL_REGISTER_SKILL_NODE(10141, 170, node170)
    }
    if (noInit == true) {
        return node170;
    }
    auto node167 = GET_SKILL_NODE(167, PhaseNode_SpawnCollider);
    if (node167 != nullptr) node170->setColliderID(node167->getColliderID());
    return node170;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10141, 172) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlayAnimation::TRIGGER_DONE, 174, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10141, 172) {
    auto node172 = GET_SKILL_NODE(172, PhaseNode_PlayAnimation);
    if (node172 == nullptr) {
        node172 = new PhaseNode_PlayAnimation(172, phase);
        node172->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node172->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node172->setTarget(0U);
        node172->setAnimation("Skill1S2");
        node172->setParameter("");
        node172->setValue(false);
        CALL_REGISTER_SKILL_NODE(10141, 172, node172)
    }
    if (noInit == true) {
        return node172;
    }
    return node172;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10141, 174) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_Delay::TRIGGER_DONE, 176, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10141, 174) {
    auto node174 = GET_SKILL_NODE(174, PhaseNode_Delay);
    if (node174 == nullptr) {
        node174 = new PhaseNode_Delay(174, phase);
        node174->setTime(.25f);
        CALL_REGISTER_SKILL_NODE(10141, 174, node174)
    }
    if (noInit == true) {
        return node174;
    }
    return node174;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10141, 176) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlayAnimation::TRIGGER_DONE, 178, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10141, 176) {
    auto node176 = GET_SKILL_NODE(176, PhaseNode_PlayAnimation);
    if (node176 == nullptr) {
        node176 = new PhaseNode_PlayAnimation(176, phase);
        node176->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node176->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node176->setTarget(0U);
        node176->setAnimation("Skill1S3");
        node176->setParameter("");
        node176->setValue(false);
        CALL_REGISTER_SKILL_NODE(10141, 176, node176)
    }
    if (noInit == true) {
        return node176;
    }
    return node176;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10141, 178) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_Delay::TRIGGER_DONE, 60, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(10141, 178) {
    auto node178 = GET_SKILL_NODE(178, PhaseNode_Delay);
    if (node178 == nullptr) {
        node178 = new PhaseNode_Delay(178, phase);
        node178->setTime(.30f);
        CALL_REGISTER_SKILL_NODE(10141, 178, node178)
    }
    if (noInit == true) {
        return node178;
    }
    return node178;
}
//--------------------------------------------------------------------------------
// Disable
//
REGISTER_REGISTER_SKILL_NODE(10141, 180) {
    pnode->resizeTrigger(PhaseNode_Disable::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_Disable::TRIGGER_DONE, 140, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_Disable::TRIGGER_DONE, 186, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_Disable::TRIGGER_DONE, 199, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10141, 180) {
    auto node180 = GET_SKILL_NODE(180, PhaseNode_Disable);
    if (node180 == nullptr) {
        node180 = new PhaseNode_Disable(180, phase);
        node180->setTarget(0U);
        node180->setMove(true);
        node180->setSkill(true);
        node180->setShoot(true);
        node180->setTime(.60f);
        node180->setRotate(true);
        CALL_REGISTER_SKILL_NODE(10141, 180, node180)
    }
    if (noInit == true) {
        return node180;
    }
    return node180;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(10141, 182) {
}

REGISTER_CREATE_SKILL_NODE(10141, 182) {
    auto node182 = GET_SKILL_NODE(182, PhaseNode_PlayEffect);
    if (node182 == nullptr) {
        node182 = new PhaseNode_PlayEffect(182, phase);
        node182->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node182->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node182->setEffectID(101413);
        node182->setChangeColor(false);
        node182->setType(PhaseNode_PlayEffect::PlayEffect_Type::WithTarget);
        node182->getVars().reserve(6);
        node182->getVars().setVariable<uint64_t>(0, 0U);
        node182->getVars().setVariable<std::string>(1, "");
        node182->getVars().setVariable<float>(2, .00f);
        node182->getVars().setVariable<float>(3, .00f);
        node182->getVars().setVariable<float>(4, .00f);
        node182->getVars().setVariable<bool>(5, false);
        node182->setRotation(.00f);
        node182->setScale(.00f);
        CALL_REGISTER_SKILL_NODE(10141, 182, node182)
    }
    if (noInit == true) {
        return node182;
    }
    return node182;
}
//--------------------------------------------------------------------------------
// OffsetCalculate
//
REGISTER_REGISTER_SKILL_NODE(10141, 184) {
    pnode->resizeTrigger(PhaseNode_OffsetCalculate::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnCollider>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 167, PhaseNode_SpawnCollider::FUNC_DO, &PhaseNode_SpawnCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(10141, 184) {
    auto node184 = GET_SKILL_NODE(184, PhaseNode_OffsetCalculate);
    if (node184 == nullptr) {
        node184 = new PhaseNode_OffsetCalculate(184, phase);
        node184->setPosZ(.00f);
        node184->setOffsetX(.00f);
        node184->setOffsetY(.50f);
        node184->setOffsetZ(.00f);
        node184->setRotOffset(.00f);
        CALL_REGISTER_SKILL_NODE(10141, 184, node184)
    }
    if (noInit == true) {
        return node184;
    }
    auto node140 = GET_SKILL_NODE(140, PhaseNode_GetLocation);
    auto node142 = GET_SKILL_NODE(142, PhaseNode_GetInputRotation);
    if (node140 != nullptr) node184->setPosX(node140->getX());
    if (node140 != nullptr) node184->setPosY(node140->getY());
    if (node142 != nullptr) node184->setRotation(node142->getAngle());
    return node184;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10141, 186) {
}

REGISTER_CREATE_SKILL_NODE(10141, 186) {
    auto node186 = GET_SKILL_NODE(186, PhaseNode_PlaySound);
    if (node186 == nullptr) {
        node186 = new PhaseNode_PlaySound(186, phase);
        node186->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node186->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node186->setSoundID("SE_Hero108_SkillA_P1");
        node186->setTarget(0U);
        node186->setUsePos(false);
        node186->setPosX(.00f);
        node186->setPosY(.00f);
        node186->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10141, 186, node186)
    }
    if (noInit == true) {
        return node186;
    }
    return node186;
}
//--------------------------------------------------------------------------------
// LineCheckNewPene
//
REGISTER_REGISTER_SKILL_NODE(10141, 188) {
    pnode->resizeTrigger(PhaseNode_LineCheckNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_LineCheckNewPene::TRIGGER_DONE, 153, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(10141, 188) {
    auto node188 = GET_SKILL_NODE(188, PhaseNode_LineCheckNewPene);
    if (node188 == nullptr) {
        node188 = new PhaseNode_LineCheckNewPene(188, phase);
        node188->setPeneProjectile(5);
        CALL_REGISTER_SKILL_NODE(10141, 188, node188)
    }
    if (noInit == true) {
        return node188;
    }
    auto node148 = GET_SKILL_NODE(148, PhaseNode_CreateTriggerNewPene);
    auto node190 = GET_SKILL_NODE(190, PhaseNode_GetLocation);
    if (node148 != nullptr) node188->setTargets(node148->getOther());
    if (node190 != nullptr) node188->setFromX(node190->getX());
    if (node190 != nullptr) node188->setFromY(node190->getY());
    return node188;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(10141, 190) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_LineCheckNewPene>(PhaseNode_GetLocation::TRIGGER_DONE, 188, PhaseNode_LineCheckNewPene::FUNC_DO, &PhaseNode_LineCheckNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(10141, 190) {
    auto node190 = GET_SKILL_NODE(190, PhaseNode_GetLocation);
    if (node190 == nullptr) {
        node190 = new PhaseNode_GetLocation(190, phase);
        node190->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node190->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(10141, 190, node190)
    }
    if (noInit == true) {
        return node190;
    }
    return node190;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(10141, 191) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_ResetCD::TRIGGER_DONE, 192, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10141, 191) {
    auto node191 = GET_SKILL_NODE(191, PhaseNode_ResetCD);
    if (node191 == nullptr) {
        node191 = new PhaseNode_ResetCD(191, phase);
        node191->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node191->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node191->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(10141, 191, node191)
    }
    if (noInit == true) {
        return node191;
    }
    return node191;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10141, 192) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_PlayAnimation::TRIGGER_DONE, 194, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(10141, 192) {
    auto node192 = GET_SKILL_NODE(192, PhaseNode_PlayAnimation);
    if (node192 == nullptr) {
        node192 = new PhaseNode_PlayAnimation(192, phase);
        node192->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node192->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node192->setTarget(0U);
        node192->setAnimation("Skill1S1");
        node192->setParameter("");
        node192->setValue(false);
        CALL_REGISTER_SKILL_NODE(10141, 192, node192)
    }
    if (noInit == true) {
        return node192;
    }
    return node192;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10141, 193) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Disable>(PhaseNode_PlaySound::TRIGGER_DONE, 180, PhaseNode_Disable::FUNC_DO, &PhaseNode_Disable::Do);
}

REGISTER_CREATE_SKILL_NODE(10141, 193) {
    auto node193 = GET_SKILL_NODE(193, PhaseNode_PlaySound);
    if (node193 == nullptr) {
        node193 = new PhaseNode_PlaySound(193, phase);
        node193->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node193->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node193->setSoundID("VO_Hero108_Skill_B");
        node193->setTarget(0U);
        node193->setUsePos(false);
        node193->setPosX(.00f);
        node193->setPosY(.00f);
        node193->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10141, 193, node193)
    }
    if (noInit == true) {
        return node193;
    }
    return node193;
}
//--------------------------------------------------------------------------------
// GetActorAttribute
//
REGISTER_REGISTER_SKILL_NODE(10141, 194) {
    pnode->resizeTrigger(PhaseNode_GetActorAttribute::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 193, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10141, 194) {
    auto node194 = GET_SKILL_NODE(194, PhaseNode_GetActorAttribute);
    if (node194 == nullptr) {
        node194 = new PhaseNode_GetActorAttribute(194, phase);
        node194->setTarget(0U);
        node194->setType({});
        CALL_REGISTER_SKILL_NODE(10141, 194, node194)
    }
    if (noInit == true) {
        return node194;
    }
    return node194;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10141, 196) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_IsInterruptType>(PhaseNode_Detect::TRIGGER_ON, 202, PhaseNode_IsInterruptType::FUNC_DO, &PhaseNode_IsInterruptType::Do);
}

REGISTER_CREATE_SKILL_NODE(10141, 196) {
    auto node196 = GET_SKILL_NODE(196, PhaseNode_Detect);
    if (node196 == nullptr) {
        node196 = new PhaseNode_Detect(196, phase);
        node196->setSelf(0U);
        node196->setEvent("daduan_001");
        node196->setType(PhaseNode_Detect::Detect_Type::Interrupt_Skill);
        node196->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10141, 196, node196)
    }
    if (noInit == true) {
        return node196;
    }
    return node196;
}
//--------------------------------------------------------------------------------
// SwitchToInt
//
REGISTER_REGISTER_SKILL_NODE(10141, 197) {
    pnode->resizeTrigger(4);
    pnode->regTrigger<PhaseNode_DestroyCollider>(1, 146, PhaseNode_DestroyCollider::FUNC_DO, &PhaseNode_DestroyCollider::Do);
    pnode->regTrigger<PhaseNode_EndPhase>(1, 60, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
    pnode->regTrigger<PhaseNode_MoveNewPene>(1, 107, PhaseNode_MoveNewPene::FUNC_STOP, &PhaseNode_MoveNewPene::Stop);
}

REGISTER_CREATE_SKILL_NODE(10141, 197) {
    auto node197 = GET_SKILL_NODE(197, PhaseNode_SwitchToInt);
    if (node197 == nullptr) {
        node197 = new PhaseNode_SwitchToInt(197, phase);
        CALL_REGISTER_SKILL_NODE(10141, 197, node197)
    }
    if (noInit == true) {
        return node197;
    }
    auto variables = node197->getVariables();
    if (variables != nullptr) {
        node197->setSelection(variables->getVariable<int32_t>(Variable_10141_));
    }
    return node197;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10141, 199) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_RaiseEvent::TRIGGER_DONE, 208, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10141, 199) {
    auto node199 = GET_SKILL_NODE(199, PhaseNode_RaiseEvent);
    if (node199 == nullptr) {
        node199 = new PhaseNode_RaiseEvent(199, phase);
        node199->setEvent("daduan_001");
        node199->setTarget(0U);
        node199->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node199->setTypeParams(0, 0);
        node199->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10141, 199, node199)
    }
    if (noInit == true) {
        return node199;
    }
    return node199;
}
//--------------------------------------------------------------------------------
// StartPreInput
//
REGISTER_REGISTER_SKILL_NODE(10141, 200) {
    pnode->resizeTrigger(PhaseNode_StartPreInput::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_StartPreInput::TRIGGER_DONE, 204, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10141, 200) {
    auto node200 = GET_SKILL_NODE(200, PhaseNode_StartPreInput);
    if (node200 == nullptr) {
        node200 = new PhaseNode_StartPreInput(200, phase);
        node200->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node200->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node200->setDelayTime(.00f);
        CALL_REGISTER_SKILL_NODE(10141, 200, node200)
    }
    if (noInit == true) {
        return node200;
    }
    return node200;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(10141, 201) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_If::TRIGGER_TRUE, 203, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10141, 201) {
    auto node201 = GET_SKILL_NODE(201, PhaseNode_If);
    if (node201 == nullptr) {
        node201 = new PhaseNode_If(201, phase);
        CALL_REGISTER_SKILL_NODE(10141, 201, node201)
    }
    if (noInit == true) {
        return node201;
    }
    auto variables = node201->getVariables();
    if (variables != nullptr) {
        node201->setCondition(variables->getVariable<bool>(Variable_10141_InterruptAnimat));
    }
    return node201;
}
//--------------------------------------------------------------------------------
// IsInterruptType
//
REGISTER_REGISTER_SKILL_NODE(10141, 202) {
    pnode->resizeTrigger(PhaseNode_IsInterruptType::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SwitchToInt>(PhaseNode_IsInterruptType::TRIGGER_BUFF, 197, PhaseNode_SwitchToInt::FUNC_SWITCH, &PhaseNode_SwitchToInt::Switch);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_POSCHANGE, 201, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTAIM, 201, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTFIRE, 201, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTRELOAD, 201, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_USESKILL, 201, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(10141, 202) {
    auto node202 = GET_SKILL_NODE(202, PhaseNode_IsInterruptType);
    if (node202 == nullptr) {
        node202 = new PhaseNode_IsInterruptType(202, phase);
        node202->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node202->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10141, 202, node202)
    }
    if (noInit == true) {
        return node202;
    }
    auto node196 = GET_SKILL_NODE(196, PhaseNode_Detect);
    if (node196 != nullptr) node202->setType(node196->getVars().getVariable<int32_t>(2));
    return node202;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10141, 203) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_PlayAnimation::TRIGGER_DONE, 60, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(10141, 203) {
    auto node203 = GET_SKILL_NODE(203, PhaseNode_PlayAnimation);
    if (node203 == nullptr) {
        node203 = new PhaseNode_PlayAnimation(203, phase);
        node203->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node203->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node203->setTarget(0U);
        node203->setAnimation("Idle");
        node203->setParameter("");
        node203->setValue(false);
        CALL_REGISTER_SKILL_NODE(10141, 203, node203)
    }
    if (noInit == true) {
        return node203;
    }
    return node203;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10141, 204) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_Delay::TRIGGER_DONE, 207, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(10141, 204) {
    auto node204 = GET_SKILL_NODE(204, PhaseNode_Delay);
    if (node204 == nullptr) {
        node204 = new PhaseNode_Delay(204, phase);
        node204->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(10141, 204, node204)
    }
    if (noInit == true) {
        return node204;
    }
    return node204;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(10141, 207) {
}

REGISTER_CREATE_SKILL_NODE(10141, 207) {
    auto node207 = GET_SKILL_NODE(207, PhaseNode_SetBool);
    if (node207 == nullptr) {
        node207 = new PhaseNode_SetBool(207, phase);
        node207->setName("InterruptAnimat");
        node207->setValue(true);
        CALL_REGISTER_SKILL_NODE(10141, 207, node207)
    }
    if (noInit == true) {
        return node207;
    }
    return node207;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10141, 208) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StartPreInput>(PhaseNode_RaiseEvent::TRIGGER_DONE, 200, PhaseNode_StartPreInput::FUNC_DO, &PhaseNode_StartPreInput::Do);
}

REGISTER_CREATE_SKILL_NODE(10141, 208) {
    auto node208 = GET_SKILL_NODE(208, PhaseNode_RaiseEvent);
    if (node208 == nullptr) {
        node208 = new PhaseNode_RaiseEvent(208, phase);
        node208->setEvent("Dead_001");
        node208->setTarget(0U);
        node208->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node208->setTypeParams(0, 0);
        node208->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10141, 208, node208)
    }
    if (noInit == true) {
        return node208;
    }
    return node208;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10141, 209) {
}

REGISTER_CREATE_SKILL_NODE(10141, 209) {
    auto node209 = GET_SKILL_NODE(209, PhaseNode_Detect);
    if (node209 == nullptr) {
        node209 = new PhaseNode_Detect(209, phase);
        node209->setSelf(0U);
        node209->setEvent("Dead_001");
        node209->setType(PhaseNode_Detect::Detect_Type::Actor_Dead);
        node209->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10141, 209, node209)
    }
    if (noInit == true) {
        return node209;
    }
    return node209;
}

//--------------------------------------------------------------------------------
// SkillCreator_10141
//
class SkillCreator_10141 : public SkillCreator {
public:
    SkillCreator_10141() {}
    virtual ~SkillCreator_10141() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_10141

//--------------------------------------------------------------------------------
// SkillPhase_10141
//
class SkillPhase_10141 : public SkillPhase {
public:
    SkillPhase_10141(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_10141() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(10141, 2) // StartPhase
        CASE_CREATE_SKILL_NODE(10141, 26) // TriggerUpdate
        CASE_CREATE_SKILL_NODE(10141, 60) // EndPhase
        CASE_CREATE_SKILL_NODE(10141, 107) // MoveNewPene
        CASE_CREATE_SKILL_NODE(10141, 134) // AttachTo
        CASE_CREATE_SKILL_NODE(10141, 138) // SpawnCollider
        CASE_CREATE_SKILL_NODE(10141, 140) // GetLocation
        CASE_CREATE_SKILL_NODE(10141, 142) // GetInputRotation
        CASE_CREATE_SKILL_NODE(10141, 144) // Delay
        CASE_CREATE_SKILL_NODE(10141, 146) // DestroyCollider
        CASE_CREATE_SKILL_NODE(10141, 148) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(10141, 150) // TriggerCheck
        CASE_CREATE_SKILL_NODE(10141, 153) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(10141, 156) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(10141, 167) // SpawnCollider
        CASE_CREATE_SKILL_NODE(10141, 169) // AttachTo
        CASE_CREATE_SKILL_NODE(10141, 170) // DestroyCollider
        CASE_CREATE_SKILL_NODE(10141, 172) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10141, 174) // Delay
        CASE_CREATE_SKILL_NODE(10141, 176) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10141, 178) // Delay
        CASE_CREATE_SKILL_NODE(10141, 180) // Disable
        CASE_CREATE_SKILL_NODE(10141, 182) // PlayEffect
        CASE_CREATE_SKILL_NODE(10141, 184) // OffsetCalculate
        CASE_CREATE_SKILL_NODE(10141, 186) // PlaySound
        CASE_CREATE_SKILL_NODE(10141, 188) // LineCheckNewPene
        CASE_CREATE_SKILL_NODE(10141, 190) // GetLocation
        CASE_CREATE_SKILL_NODE(10141, 191) // ResetCD
        CASE_CREATE_SKILL_NODE(10141, 192) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10141, 193) // PlaySound
        CASE_CREATE_SKILL_NODE(10141, 194) // GetActorAttribute
        CASE_CREATE_SKILL_NODE(10141, 196) // Detect
        CASE_CREATE_SKILL_NODE(10141, 197) // SwitchToInt
        CASE_CREATE_SKILL_NODE(10141, 199) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10141, 200) // StartPreInput
        CASE_CREATE_SKILL_NODE(10141, 201) // If
        CASE_CREATE_SKILL_NODE(10141, 202) // IsInterruptType
        CASE_CREATE_SKILL_NODE(10141, 203) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10141, 204) // Delay
        CASE_CREATE_SKILL_NODE(10141, 207) // SetBool
        CASE_CREATE_SKILL_NODE(10141, 208) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10141, 209) // Detect
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_10141

SkillLogic* SkillCreator_10141::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //设置变量
    Variable_10141_ = logic->getVariables().setVariable<int32_t>("", 1);
    Variable_10141_InterruptAnimat = logic->getVariables().setVariable<bool>("InterruptAnimat");
    //创建阶段phase
    auto phase = new SkillPhase_10141(1, logic, 3);
    //设置phase执行器
    phase->setRunPhaseNode(1, 2);
    phase->setRunPhaseNode(2, 26);
    phase->setDetectPhaseNode(3, 196);
    phase->setDetectPhaseNode(3, 209);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_10141::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
