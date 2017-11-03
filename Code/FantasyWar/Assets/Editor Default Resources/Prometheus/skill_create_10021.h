#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

#include "skill_psnode_actorfilternewpene.h"
#include "skill_psnode_addskillbuffs.h"
#include "skill_psnode_areacollisionnewpene.h"
#include "skill_psnode_confirmphase.h"
#include "skill_psnode_createtriggernewpene.h"
#include "skill_psnode_delay.h"
#include "skill_psnode_destroycollider.h"
#include "skill_psnode_detect.h"
#include "skill_psnode_disable.h"
#include "skill_psnode_endphase.h"
#include "skill_psnode_getactorattribute.h"
#include "skill_psnode_getinputlocation.h"
#include "skill_psnode_if.h"
#include "skill_psnode_isinterrupttype.h"
#include "skill_psnode_playanimation.h"
#include "skill_psnode_playeffect.h"
#include "skill_psnode_playsound.h"
#include "skill_psnode_raiseevent.h"
#include "skill_psnode_resetcd.h"
#include "skill_psnode_setbool.h"
#include "skill_psnode_setint.h"
#include "skill_psnode_spawncollider.h"
#include "skill_psnode_startphase.h"
#include "skill_psnode_startpreinput.h"
#include "skill_psnode_stopeffect.h"
#include "skill_psnode_switchtoint.h"
#include "skill_psnode_triggercheck.h"
#include "skill_psnode_triggerupdate.h"

namespace pvp {

//变量声明
uint64_t Variable_10021_second = 0;
uint64_t Variable_10021_a100212 = 0;
uint64_t Variable_10021_InterruptAnimat = 0;
//--------------------------------------------------------------------------------
// StartPhase
//
REGISTER_REGISTER_SKILL_NODE(10021, 2) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_StartPhase::TRIGGER_START, 223, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10021, 2) {
    auto node2 = GET_SKILL_NODE(2, PhaseNode_StartPhase);
    if (node2 == nullptr) {
        node2 = new PhaseNode_StartPhase(2, phase);
        CALL_REGISTER_SKILL_NODE(10021, 2, node2)
    }
    if (noInit == true) {
        return node2;
    }
    return node2;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10021, 6) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetInputLocation>(PhaseNode_Delay::TRIGGER_DONE, 186, PhaseNode_GetInputLocation::FUNC_DO, &PhaseNode_GetInputLocation::Do);
    pnode->regTrigger<PhaseNode_SetInt>(PhaseNode_Delay::TRIGGER_DONE, 195, PhaseNode_SetInt::FUNC_SET, &PhaseNode_SetInt::Set);
}

REGISTER_CREATE_SKILL_NODE(10021, 6) {
    auto node6 = GET_SKILL_NODE(6, PhaseNode_Delay);
    if (node6 == nullptr) {
        node6 = new PhaseNode_Delay(6, phase);
        node6->setTime(.20f);
        CALL_REGISTER_SKILL_NODE(10021, 6, node6)
    }
    if (noInit == true) {
        return node6;
    }
    return node6;
}
//--------------------------------------------------------------------------------
// Disable
//
REGISTER_REGISTER_SKILL_NODE(10021, 16) {
    pnode->resizeTrigger(PhaseNode_Disable::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_Disable::TRIGGER_DONE, 6, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10021, 16) {
    auto node16 = GET_SKILL_NODE(16, PhaseNode_Disable);
    if (node16 == nullptr) {
        node16 = new PhaseNode_Disable(16, phase);
        node16->setTarget(0U);
        node16->setMove(false);
        node16->setSkill(true);
        node16->setShoot(true);
        node16->setTime(.45f);
        node16->setRotate(false);
        CALL_REGISTER_SKILL_NODE(10021, 16, node16)
    }
    if (noInit == true) {
        return node16;
    }
    return node16;
}
//--------------------------------------------------------------------------------
// TriggerUpdate
//
REGISTER_REGISTER_SKILL_NODE(10021, 25) {
}

REGISTER_CREATE_SKILL_NODE(10021, 25) {
    auto node25 = GET_SKILL_NODE(25, PhaseNode_TriggerUpdate);
    if (node25 == nullptr) {
        node25 = new PhaseNode_TriggerUpdate(25, phase);
        CALL_REGISTER_SKILL_NODE(10021, 25, node25)
    }
    if (noInit == true) {
        return node25;
    }
    return node25;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10021, 36) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_Delay::TRIGGER_DONE, 38, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10021, 36) {
    auto node36 = GET_SKILL_NODE(36, PhaseNode_Delay);
    if (node36 == nullptr) {
        node36 = new PhaseNode_Delay(36, phase);
        node36->setTime(.50f);
        CALL_REGISTER_SKILL_NODE(10021, 36, node36)
    }
    if (noInit == true) {
        return node36;
    }
    return node36;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10021, 38) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlayAnimation::TRIGGER_DONE, 41, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10021, 38) {
    auto node38 = GET_SKILL_NODE(38, PhaseNode_PlayAnimation);
    if (node38 == nullptr) {
        node38 = new PhaseNode_PlayAnimation(38, phase);
        node38->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node38->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node38->setTarget(0U);
        node38->setAnimation("Idle");
        node38->setParameter("SkillArmBusy");
        node38->setValue(false);
        CALL_REGISTER_SKILL_NODE(10021, 38, node38)
    }
    if (noInit == true) {
        return node38;
    }
    return node38;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10021, 41) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_Delay::TRIGGER_DONE, 251, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(10021, 41) {
    auto node41 = GET_SKILL_NODE(41, PhaseNode_Delay);
    if (node41 == nullptr) {
        node41 = new PhaseNode_Delay(41, phase);
        node41->setTime(4.50f);
        CALL_REGISTER_SKILL_NODE(10021, 41, node41)
    }
    if (noInit == true) {
        return node41;
    }
    return node41;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(10021, 43) {
}

REGISTER_CREATE_SKILL_NODE(10021, 43) {
    auto node43 = GET_SKILL_NODE(43, PhaseNode_EndPhase);
    if (node43 == nullptr) {
        node43 = new PhaseNode_EndPhase(43, phase);
        node43->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node43->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10021, 43, node43)
    }
    if (noInit == true) {
        return node43;
    }
    return node43;
}
//--------------------------------------------------------------------------------
// SpawnCollider
//
REGISTER_REGISTER_SKILL_NODE(10021, 69) {
    pnode->resizeTrigger(PhaseNode_SpawnCollider::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_SpawnCollider::TRIGGER_DONE, 136, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_SpawnCollider::TRIGGER_DONE, 36, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10021, 69) {
    auto node69 = GET_SKILL_NODE(69, PhaseNode_SpawnCollider);
    if (node69 == nullptr) {
        node69 = new PhaseNode_SpawnCollider(69, phase);
        node69->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node69->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node69->setMesh("");
        node69->setMeshScale(.00f);
        node69->setEffectID(0);
        node69->setEffectScale(1.00f);
        node69->setType(PhaseNode_SpawnCollider::SpawnCollider_Type::Circle);
        node69->setTypeParams(0, 6.00f);
        node69->setTime(5.00f);
        node69->setPosZ(.00f);
        node69->setRotation(.00f);
        node69->setreentry(false);
        node69->setCheckPeneSound(false);
        CALL_REGISTER_SKILL_NODE(10021, 69, node69)
    }
    if (noInit == true) {
        return node69;
    }
    auto node186 = GET_SKILL_NODE(186, PhaseNode_GetInputLocation);
    if (node186 != nullptr) node69->setPosX(node186->getX());
    if (node186 != nullptr) node69->setPosY(node186->getY());
    return node69;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10021, 94) {
}

REGISTER_CREATE_SKILL_NODE(10021, 94) {
    auto node94 = GET_SKILL_NODE(94, PhaseNode_PlaySound);
    if (node94 == nullptr) {
        node94 = new PhaseNode_PlaySound(94, phase);
        node94->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node94->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node94->setSoundID("SE_Hero112_SkillA_P1");
        node94->setTarget(0U);
        node94->setUsePos(false);
        node94->setPosX(.00f);
        node94->setPosY(.00f);
        node94->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10021, 94, node94)
    }
    if (noInit == true) {
        return node94;
    }
    return node94;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(10021, 128) {
}

REGISTER_CREATE_SKILL_NODE(10021, 128) {
    auto node128 = GET_SKILL_NODE(128, PhaseNode_AddSkillBuffs);
    if (node128 == nullptr) {
        node128 = new PhaseNode_AddSkillBuffs(128, phase);
        node128->setConfigID({100211});
        CALL_REGISTER_SKILL_NODE(10021, 128, node128)
    }
    if (noInit == true) {
        return node128;
    }
    auto node138 = GET_SKILL_NODE(138, PhaseNode_ActorFilterNewPene);
    auto node227 = GET_SKILL_NODE(227, PhaseNode_GetActorAttribute);
    if (node138 != nullptr) node128->setTarget(node138->getOutput());
    if (node227 != nullptr) node128->setAttribute(node227->getAttribute());
    return node128;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(10021, 134) {
}

REGISTER_CREATE_SKILL_NODE(10021, 134) {
    auto node134 = GET_SKILL_NODE(134, PhaseNode_PlayEffect);
    if (node134 == nullptr) {
        node134 = new PhaseNode_PlayEffect(134, phase);
        node134->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node134->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node134->setEffectID(100211);
        node134->setChangeColor(true);
        node134->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node134->getVars().reserve(3);
        node134->getVars().setVariable<float>(0, .00f);
        node134->getVars().setVariable<float>(1, .00f);
        node134->getVars().setVariable<float>(2, .00f);
        node134->setRotation(.00f);
        node134->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(10021, 134, node134)
    }
    if (noInit == true) {
        return node134;
    }
    auto node186 = GET_SKILL_NODE(186, PhaseNode_GetInputLocation);
    if (node186 != nullptr) node134->getVars().setVariable<float>(0, node186->getX());
    if (node186 != nullptr) node134->getVars().setVariable<float>(1, node186->getY());
    return node134;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(10021, 136) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 140, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 138, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(10021, 136) {
    auto node136 = GET_SKILL_NODE(136, PhaseNode_CreateTriggerNewPene);
    if (node136 == nullptr) {
        node136 = new PhaseNode_CreateTriggerNewPene(136, phase);
        node136->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::Tick);
        node136->setTypeParams(0, .50f);
        node136->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node136->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Friend);
        node136->setOnHero(true);
        node136->setOnMinion(true);
        node136->setOnDestruct(false);
        node136->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(10021, 136, node136)
    }
    if (noInit == true) {
        return node136;
    }
    auto node69 = GET_SKILL_NODE(69, PhaseNode_SpawnCollider);
    if (node69 != nullptr) node136->setColliderID(node69->getColliderID());
    return node136;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(10021, 138) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 128, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
}

REGISTER_CREATE_SKILL_NODE(10021, 138) {
    auto node138 = GET_SKILL_NODE(138, PhaseNode_ActorFilterNewPene);
    if (node138 == nullptr) {
        node138 = new PhaseNode_ActorFilterNewPene(138, phase);
        node138->setHero(true);
        node138->setMinion(true);
        node138->setDestruct(false);
        node138->setShield(false);
        node138->setTotalCount(0);
        node138->setPerCount(0);
        CALL_REGISTER_SKILL_NODE(10021, 138, node138)
    }
    if (noInit == true) {
        return node138;
    }
    auto node136 = GET_SKILL_NODE(136, PhaseNode_CreateTriggerNewPene);
    if (node136 != nullptr) node138->setInput(node136->getOther());
    return node138;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(10021, 140) {
}

REGISTER_CREATE_SKILL_NODE(10021, 140) {
    auto node140 = GET_SKILL_NODE(140, PhaseNode_TriggerCheck);
    if (node140 == nullptr) {
        node140 = new PhaseNode_TriggerCheck(140, phase);
        auto node25 = GET_SKILL_NODE(25, PhaseNode_TriggerUpdate);
        if (node25 != nullptr) node25->addTriggerCheck(node140);
        
        CALL_REGISTER_SKILL_NODE(10021, 140, node140)
    }
    if (noInit == true) {
        return node140;
    }
    auto node136 = GET_SKILL_NODE(136, PhaseNode_CreateTriggerNewPene);
    if (node136 != nullptr) node140->setTrigger(0, node136->getTriggerID());
    return node140;
}
//--------------------------------------------------------------------------------
// ConfirmPhase
//
REGISTER_REGISTER_SKILL_NODE(10021, 142) {
    pnode->resizeTrigger(PhaseNode_ConfirmPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_ConfirmPhase::TRIGGER_CONFIRM, 232, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(10021, 142) {
    auto node142 = GET_SKILL_NODE(142, PhaseNode_ConfirmPhase);
    if (node142 == nullptr) {
        node142 = new PhaseNode_ConfirmPhase(142, phase);
        CALL_REGISTER_SKILL_NODE(10021, 142, node142)
    }
    if (noInit == true) {
        return node142;
    }
    return node142;
}
//--------------------------------------------------------------------------------
// DestroyCollider
//
REGISTER_REGISTER_SKILL_NODE(10021, 154) {
    pnode->resizeTrigger(PhaseNode_DestroyCollider::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AreaCollisionNewPene>(PhaseNode_DestroyCollider::TRIGGER_DONE, 238, PhaseNode_AreaCollisionNewPene::FUNC_DO, &PhaseNode_AreaCollisionNewPene::Do);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_DestroyCollider::TRIGGER_DONE, 220, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10021, 154) {
    auto node154 = GET_SKILL_NODE(154, PhaseNode_DestroyCollider);
    if (node154 == nullptr) {
        node154 = new PhaseNode_DestroyCollider(154, phase);
        CALL_REGISTER_SKILL_NODE(10021, 154, node154)
    }
    if (noInit == true) {
        return node154;
    }
    auto node69 = GET_SKILL_NODE(69, PhaseNode_SpawnCollider);
    if (node69 != nullptr) node154->setColliderID(node69->getColliderID());
    return node154;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(10021, 179) {
}

REGISTER_CREATE_SKILL_NODE(10021, 179) {
    auto node179 = GET_SKILL_NODE(179, PhaseNode_AddSkillBuffs);
    if (node179 == nullptr) {
        node179 = new PhaseNode_AddSkillBuffs(179, phase);
        node179->setConfigID({100212});
        CALL_REGISTER_SKILL_NODE(10021, 179, node179)
    }
    if (noInit == true) {
        return node179;
    }
    auto node238 = GET_SKILL_NODE(238, PhaseNode_AreaCollisionNewPene);
    auto node227 = GET_SKILL_NODE(227, PhaseNode_GetActorAttribute);
    if (node238 != nullptr) node179->setTarget(node238->getColliders());
    if (node227 != nullptr) node179->setAttribute(node227->getAttribute());
    return node179;
}
//--------------------------------------------------------------------------------
// GetInputLocation
//
REGISTER_REGISTER_SKILL_NODE(10021, 186) {
    pnode->resizeTrigger(PhaseNode_GetInputLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_GetInputLocation::TRIGGER_DONE, 134, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_GetInputLocation::TRIGGER_DONE, 214, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
    pnode->regTrigger<PhaseNode_SpawnCollider>(PhaseNode_GetInputLocation::TRIGGER_DONE, 69, PhaseNode_SpawnCollider::FUNC_DO, &PhaseNode_SpawnCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(10021, 186) {
    auto node186 = GET_SKILL_NODE(186, PhaseNode_GetInputLocation);
    if (node186 == nullptr) {
        node186 = new PhaseNode_GetInputLocation(186, phase);
        node186->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        CALL_REGISTER_SKILL_NODE(10021, 186, node186)
    }
    if (noInit == true) {
        return node186;
    }
    return node186;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10021, 188) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Disable>(PhaseNode_PlayAnimation::TRIGGER_DONE, 190, PhaseNode_Disable::FUNC_DO, &PhaseNode_Disable::Do);
}

REGISTER_CREATE_SKILL_NODE(10021, 188) {
    auto node188 = GET_SKILL_NODE(188, PhaseNode_PlayAnimation);
    if (node188 == nullptr) {
        node188 = new PhaseNode_PlayAnimation(188, phase);
        node188->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node188->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node188->setTarget(0U);
        node188->setAnimation("Skill1S1");
        node188->setParameter("SkillArmBusy");
        node188->setValue(true);
        CALL_REGISTER_SKILL_NODE(10021, 188, node188)
    }
    if (noInit == true) {
        return node188;
    }
    return node188;
}
//--------------------------------------------------------------------------------
// Disable
//
REGISTER_REGISTER_SKILL_NODE(10021, 190) {
    pnode->resizeTrigger(PhaseNode_Disable::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_Disable::TRIGGER_DONE, 192, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10021, 190) {
    auto node190 = GET_SKILL_NODE(190, PhaseNode_Disable);
    if (node190 == nullptr) {
        node190 = new PhaseNode_Disable(190, phase);
        node190->setTarget(0U);
        node190->setMove(false);
        node190->setSkill(true);
        node190->setShoot(true);
        node190->setTime(.45f);
        node190->setRotate(false);
        CALL_REGISTER_SKILL_NODE(10021, 190, node190)
    }
    if (noInit == true) {
        return node190;
    }
    return node190;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10021, 192) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_DestroyCollider>(PhaseNode_Delay::TRIGGER_DONE, 154, PhaseNode_DestroyCollider::FUNC_DO, &PhaseNode_DestroyCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(10021, 192) {
    auto node192 = GET_SKILL_NODE(192, PhaseNode_Delay);
    if (node192 == nullptr) {
        node192 = new PhaseNode_Delay(192, phase);
        node192->setTime(.20f);
        CALL_REGISTER_SKILL_NODE(10021, 192, node192)
    }
    if (noInit == true) {
        return node192;
    }
    return node192;
}
//--------------------------------------------------------------------------------
// SetInt
//
REGISTER_REGISTER_SKILL_NODE(10021, 195) {
}

REGISTER_CREATE_SKILL_NODE(10021, 195) {
    auto node195 = GET_SKILL_NODE(195, PhaseNode_SetInt);
    if (node195 == nullptr) {
        node195 = new PhaseNode_SetInt(195, phase);
        node195->setName("a100212");
        node195->setValue(2);
        CALL_REGISTER_SKILL_NODE(10021, 195, node195)
    }
    if (noInit == true) {
        return node195;
    }
    return node195;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(10021, 214) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlayEffect::TRIGGER_DONE, 36, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10021, 214) {
    auto node214 = GET_SKILL_NODE(214, PhaseNode_PlayEffect);
    if (node214 == nullptr) {
        node214 = new PhaseNode_PlayEffect(214, phase);
        node214->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node214->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node214->setEffectID(100212);
        node214->setChangeColor(true);
        node214->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node214->getVars().reserve(3);
        node214->getVars().setVariable<float>(0, .00f);
        node214->getVars().setVariable<float>(1, .00f);
        node214->getVars().setVariable<float>(2, .00f);
        node214->setRotation(.00f);
        node214->setScale(.00f);
        CALL_REGISTER_SKILL_NODE(10021, 214, node214)
    }
    if (noInit == true) {
        return node214;
    }
    auto node186 = GET_SKILL_NODE(186, PhaseNode_GetInputLocation);
    if (node186 != nullptr) node214->getVars().setVariable<float>(0, node186->getX());
    if (node186 != nullptr) node214->getVars().setVariable<float>(1, node186->getY());
    return node214;
}
//--------------------------------------------------------------------------------
// StopEffect
//
REGISTER_REGISTER_SKILL_NODE(10021, 216) {
    pnode->resizeTrigger(PhaseNode_StopEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_StopEffect::TRIGGER_DONE, 236, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10021, 216) {
    auto node216 = GET_SKILL_NODE(216, PhaseNode_StopEffect);
    if (node216 == nullptr) {
        node216 = new PhaseNode_StopEffect(216, phase);
        node216->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node216->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node216->setEffectID(100212);
        CALL_REGISTER_SKILL_NODE(10021, 216, node216)
    }
    if (noInit == true) {
        return node216;
    }
    return node216;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10021, 220) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_PlaySound::TRIGGER_DONE, 240, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(10021, 220) {
    auto node220 = GET_SKILL_NODE(220, PhaseNode_PlaySound);
    if (node220 == nullptr) {
        node220 = new PhaseNode_PlaySound(220, phase);
        node220->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node220->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node220->setSoundID("SE_Hero112_SkillA_P2");
        node220->setTarget(0U);
        node220->setUsePos(false);
        node220->setPosX(.00f);
        node220->setPosY(.00f);
        node220->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10021, 220, node220)
    }
    if (noInit == true) {
        return node220;
    }
    return node220;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10021, 223) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Disable>(PhaseNode_PlayAnimation::TRIGGER_DONE, 16, PhaseNode_Disable::FUNC_DO, &PhaseNode_Disable::Do);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_PlayAnimation::TRIGGER_DONE, 227, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(10021, 223) {
    auto node223 = GET_SKILL_NODE(223, PhaseNode_PlayAnimation);
    if (node223 == nullptr) {
        node223 = new PhaseNode_PlayAnimation(223, phase);
        node223->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node223->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node223->setTarget(0U);
        node223->setAnimation("Skill1S1");
        node223->setParameter("SkillArmBusy");
        node223->setValue(true);
        CALL_REGISTER_SKILL_NODE(10021, 223, node223)
    }
    if (noInit == true) {
        return node223;
    }
    return node223;
}
//--------------------------------------------------------------------------------
// GetActorAttribute
//
REGISTER_REGISTER_SKILL_NODE(10021, 227) {
    pnode->resizeTrigger(PhaseNode_GetActorAttribute::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 229, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10021, 227) {
    auto node227 = GET_SKILL_NODE(227, PhaseNode_GetActorAttribute);
    if (node227 == nullptr) {
        node227 = new PhaseNode_GetActorAttribute(227, phase);
        node227->setTarget(0U);
        node227->setType({});
        CALL_REGISTER_SKILL_NODE(10021, 227, node227)
    }
    if (noInit == true) {
        return node227;
    }
    return node227;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10021, 229) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_PlaySound::TRIGGER_DONE, 256, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10021, 229) {
    auto node229 = GET_SKILL_NODE(229, PhaseNode_PlaySound);
    if (node229 == nullptr) {
        node229 = new PhaseNode_PlaySound(229, phase);
        node229->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node229->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node229->setSoundID("VO_Hero112_Skill_A");
        node229->setTarget(0U);
        node229->setUsePos(false);
        node229->setPosX(.00f);
        node229->setPosY(.00f);
        node229->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10021, 229, node229)
    }
    if (noInit == true) {
        return node229;
    }
    return node229;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(10021, 232) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_ResetCD::TRIGGER_DONE, 242, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(10021, 232) {
    auto node232 = GET_SKILL_NODE(232, PhaseNode_ResetCD);
    if (node232 == nullptr) {
        node232 = new PhaseNode_ResetCD(232, phase);
        node232->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node232->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node232->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(10021, 232, node232)
    }
    if (noInit == true) {
        return node232;
    }
    return node232;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(10021, 234) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_ResetCD::TRIGGER_DONE, 43, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(10021, 234) {
    auto node234 = GET_SKILL_NODE(234, PhaseNode_ResetCD);
    if (node234 == nullptr) {
        node234 = new PhaseNode_ResetCD(234, phase);
        node234->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node234->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node234->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(10021, 234, node234)
    }
    if (noInit == true) {
        return node234;
    }
    return node234;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10021, 236) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_Delay::TRIGGER_DONE, 43, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(10021, 236) {
    auto node236 = GET_SKILL_NODE(236, PhaseNode_Delay);
    if (node236 == nullptr) {
        node236 = new PhaseNode_Delay(236, phase);
        node236->setTime(.50f);
        CALL_REGISTER_SKILL_NODE(10021, 236, node236)
    }
    if (noInit == true) {
        return node236;
    }
    return node236;
}
//--------------------------------------------------------------------------------
// AreaCollisionNewPene
//
REGISTER_REGISTER_SKILL_NODE(10021, 238) {
    pnode->resizeTrigger(PhaseNode_AreaCollisionNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_AreaCollisionNewPene::TRIGGER_DONE, 179, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
}

REGISTER_CREATE_SKILL_NODE(10021, 238) {
    auto node238 = GET_SKILL_NODE(238, PhaseNode_AreaCollisionNewPene);
    if (node238 == nullptr) {
        node238 = new PhaseNode_AreaCollisionNewPene(238, phase);
        node238->setState(PhaseNode_AreaCollisionNewPene::AreaCollisionNewPene_State::Alive);
        node238->setFaction(PhaseNode_AreaCollisionNewPene::AreaCollisionNewPene_Faction::Friend);
        node238->setOnHero(true);
        node238->setOnMinion(true);
        node238->setOnDestruct(false);
        node238->setOnShield(false);
        node238->setType(PhaseNode_AreaCollisionNewPene::AreaCollisionNewPene_Type::Circle);
        node238->setTypeParams(0, 6.00f);
        node238->setPositionZ(.00f);
        node238->setRotation(.00f);
        CALL_REGISTER_SKILL_NODE(10021, 238, node238)
    }
    if (noInit == true) {
        return node238;
    }
    auto node186 = GET_SKILL_NODE(186, PhaseNode_GetInputLocation);
    if (node186 != nullptr) node238->setPositionX(node186->getX());
    if (node186 != nullptr) node238->setPositionY(node186->getY());
    return node238;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(10021, 240) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StopEffect>(PhaseNode_PlayEffect::TRIGGER_DONE, 216, PhaseNode_StopEffect::FUNC_DO, &PhaseNode_StopEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(10021, 240) {
    auto node240 = GET_SKILL_NODE(240, PhaseNode_PlayEffect);
    if (node240 == nullptr) {
        node240 = new PhaseNode_PlayEffect(240, phase);
        node240->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node240->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node240->setEffectID(100214);
        node240->setChangeColor(false);
        node240->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node240->getVars().reserve(3);
        node240->getVars().setVariable<float>(0, .00f);
        node240->getVars().setVariable<float>(1, .00f);
        node240->getVars().setVariable<float>(2, .00f);
        node240->setRotation(.00f);
        node240->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(10021, 240, node240)
    }
    if (noInit == true) {
        return node240;
    }
    auto node186 = GET_SKILL_NODE(186, PhaseNode_GetInputLocation);
    if (node186 != nullptr) node240->getVars().setVariable<float>(0, node186->getX());
    if (node186 != nullptr) node240->getVars().setVariable<float>(1, node186->getY());
    return node240;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(10021, 242) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_DestroyCollider>(PhaseNode_If::TRIGGER_FALSE, 154, PhaseNode_DestroyCollider::FUNC_DO, &PhaseNode_DestroyCollider::Do);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_If::TRIGGER_TRUE, 188, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10021, 242) {
    auto node242 = GET_SKILL_NODE(242, PhaseNode_If);
    if (node242 == nullptr) {
        node242 = new PhaseNode_If(242, phase);
        CALL_REGISTER_SKILL_NODE(10021, 242, node242)
    }
    if (noInit == true) {
        return node242;
    }
    auto variables = node242->getVariables();
    if (variables != nullptr) {
        node242->setCondition(variables->getVariable<bool>(Variable_10021_second));
    }
    return node242;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(10021, 251) {
    pnode->resizeTrigger(PhaseNode_SetBool::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_SetBool::TRIGGER_DONE, 232, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(10021, 251) {
    auto node251 = GET_SKILL_NODE(251, PhaseNode_SetBool);
    if (node251 == nullptr) {
        node251 = new PhaseNode_SetBool(251, phase);
        node251->setName("second");
        node251->setValue(false);
        CALL_REGISTER_SKILL_NODE(10021, 251, node251)
    }
    if (noInit == true) {
        return node251;
    }
    return node251;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10021, 253) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_IsInterruptType>(PhaseNode_Detect::TRIGGER_ON, 259, PhaseNode_IsInterruptType::FUNC_DO, &PhaseNode_IsInterruptType::Do);
}

REGISTER_CREATE_SKILL_NODE(10021, 253) {
    auto node253 = GET_SKILL_NODE(253, PhaseNode_Detect);
    if (node253 == nullptr) {
        node253 = new PhaseNode_Detect(253, phase);
        node253->setSelf(0U);
        node253->setEvent("daduan_001");
        node253->setType(PhaseNode_Detect::Detect_Type::Interrupt_Skill);
        node253->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10021, 253, node253)
    }
    if (noInit == true) {
        return node253;
    }
    return node253;
}
//--------------------------------------------------------------------------------
// SwitchToInt
//
REGISTER_REGISTER_SKILL_NODE(10021, 254) {
    pnode->resizeTrigger(4);
    pnode->regTrigger<PhaseNode_ResetCD>(1, 234, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(10021, 254) {
    auto node254 = GET_SKILL_NODE(254, PhaseNode_SwitchToInt);
    if (node254 == nullptr) {
        node254 = new PhaseNode_SwitchToInt(254, phase);
        CALL_REGISTER_SKILL_NODE(10021, 254, node254)
    }
    if (noInit == true) {
        return node254;
    }
    auto variables = node254->getVariables();
    if (variables != nullptr) {
        node254->setSelection(variables->getVariable<int32_t>(Variable_10021_a100212));
    }
    return node254;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10021, 256) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_RaiseEvent::TRIGGER_DONE, 265, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10021, 256) {
    auto node256 = GET_SKILL_NODE(256, PhaseNode_RaiseEvent);
    if (node256 == nullptr) {
        node256 = new PhaseNode_RaiseEvent(256, phase);
        node256->setEvent("daduan_001");
        node256->setTarget(0U);
        node256->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node256->setTypeParams(0, 0);
        node256->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10021, 256, node256)
    }
    if (noInit == true) {
        return node256;
    }
    return node256;
}
//--------------------------------------------------------------------------------
// StartPreInput
//
REGISTER_REGISTER_SKILL_NODE(10021, 257) {
    pnode->resizeTrigger(PhaseNode_StartPreInput::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_StartPreInput::TRIGGER_DONE, 261, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_StartPreInput::TRIGGER_DONE, 94, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10021, 257) {
    auto node257 = GET_SKILL_NODE(257, PhaseNode_StartPreInput);
    if (node257 == nullptr) {
        node257 = new PhaseNode_StartPreInput(257, phase);
        node257->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node257->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node257->setDelayTime(.00f);
        CALL_REGISTER_SKILL_NODE(10021, 257, node257)
    }
    if (noInit == true) {
        return node257;
    }
    return node257;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(10021, 258) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_If::TRIGGER_TRUE, 260, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10021, 258) {
    auto node258 = GET_SKILL_NODE(258, PhaseNode_If);
    if (node258 == nullptr) {
        node258 = new PhaseNode_If(258, phase);
        CALL_REGISTER_SKILL_NODE(10021, 258, node258)
    }
    if (noInit == true) {
        return node258;
    }
    auto variables = node258->getVariables();
    if (variables != nullptr) {
        node258->setCondition(variables->getVariable<bool>(Variable_10021_InterruptAnimat));
    }
    return node258;
}
//--------------------------------------------------------------------------------
// IsInterruptType
//
REGISTER_REGISTER_SKILL_NODE(10021, 259) {
    pnode->resizeTrigger(PhaseNode_IsInterruptType::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SwitchToInt>(PhaseNode_IsInterruptType::TRIGGER_BUFF, 254, PhaseNode_SwitchToInt::FUNC_SWITCH, &PhaseNode_SwitchToInt::Switch);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_POSCHANGE, 258, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTAIM, 258, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTFIRE, 258, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTRELOAD, 258, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_USESKILL, 258, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(10021, 259) {
    auto node259 = GET_SKILL_NODE(259, PhaseNode_IsInterruptType);
    if (node259 == nullptr) {
        node259 = new PhaseNode_IsInterruptType(259, phase);
        node259->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node259->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10021, 259, node259)
    }
    if (noInit == true) {
        return node259;
    }
    auto node253 = GET_SKILL_NODE(253, PhaseNode_Detect);
    if (node253 != nullptr) node259->setType(node253->getVars().getVariable<int32_t>(2));
    return node259;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10021, 260) {
}

REGISTER_CREATE_SKILL_NODE(10021, 260) {
    auto node260 = GET_SKILL_NODE(260, PhaseNode_PlayAnimation);
    if (node260 == nullptr) {
        node260 = new PhaseNode_PlayAnimation(260, phase);
        node260->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node260->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node260->setTarget(0U);
        node260->setAnimation("Idle");
        node260->setParameter("");
        node260->setValue(false);
        CALL_REGISTER_SKILL_NODE(10021, 260, node260)
    }
    if (noInit == true) {
        return node260;
    }
    return node260;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10021, 261) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_Delay::TRIGGER_DONE, 264, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(10021, 261) {
    auto node261 = GET_SKILL_NODE(261, PhaseNode_Delay);
    if (node261 == nullptr) {
        node261 = new PhaseNode_Delay(261, phase);
        node261->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(10021, 261, node261)
    }
    if (noInit == true) {
        return node261;
    }
    return node261;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(10021, 264) {
}

REGISTER_CREATE_SKILL_NODE(10021, 264) {
    auto node264 = GET_SKILL_NODE(264, PhaseNode_SetBool);
    if (node264 == nullptr) {
        node264 = new PhaseNode_SetBool(264, phase);
        node264->setName("InterruptAnimat");
        node264->setValue(true);
        CALL_REGISTER_SKILL_NODE(10021, 264, node264)
    }
    if (noInit == true) {
        return node264;
    }
    return node264;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10021, 265) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StartPreInput>(PhaseNode_RaiseEvent::TRIGGER_DONE, 257, PhaseNode_StartPreInput::FUNC_DO, &PhaseNode_StartPreInput::Do);
}

REGISTER_CREATE_SKILL_NODE(10021, 265) {
    auto node265 = GET_SKILL_NODE(265, PhaseNode_RaiseEvent);
    if (node265 == nullptr) {
        node265 = new PhaseNode_RaiseEvent(265, phase);
        node265->setEvent("Dead_001");
        node265->setTarget(0U);
        node265->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node265->setTypeParams(0, 0);
        node265->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10021, 265, node265)
    }
    if (noInit == true) {
        return node265;
    }
    return node265;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10021, 266) {
}

REGISTER_CREATE_SKILL_NODE(10021, 266) {
    auto node266 = GET_SKILL_NODE(266, PhaseNode_Detect);
    if (node266 == nullptr) {
        node266 = new PhaseNode_Detect(266, phase);
        node266->setSelf(0U);
        node266->setEvent("Dead_001");
        node266->setType(PhaseNode_Detect::Detect_Type::Actor_Dead);
        node266->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10021, 266, node266)
    }
    if (noInit == true) {
        return node266;
    }
    return node266;
}

//--------------------------------------------------------------------------------
// SkillCreator_10021
//
class SkillCreator_10021 : public SkillCreator {
public:
    SkillCreator_10021() {}
    virtual ~SkillCreator_10021() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_10021

//--------------------------------------------------------------------------------
// SkillPhase_10021
//
class SkillPhase_10021 : public SkillPhase {
public:
    SkillPhase_10021(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_10021() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(10021, 2) // StartPhase
        CASE_CREATE_SKILL_NODE(10021, 6) // Delay
        CASE_CREATE_SKILL_NODE(10021, 16) // Disable
        CASE_CREATE_SKILL_NODE(10021, 25) // TriggerUpdate
        CASE_CREATE_SKILL_NODE(10021, 36) // Delay
        CASE_CREATE_SKILL_NODE(10021, 38) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10021, 41) // Delay
        CASE_CREATE_SKILL_NODE(10021, 43) // EndPhase
        CASE_CREATE_SKILL_NODE(10021, 69) // SpawnCollider
        CASE_CREATE_SKILL_NODE(10021, 94) // PlaySound
        CASE_CREATE_SKILL_NODE(10021, 128) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(10021, 134) // PlayEffect
        CASE_CREATE_SKILL_NODE(10021, 136) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(10021, 138) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(10021, 140) // TriggerCheck
        CASE_CREATE_SKILL_NODE(10021, 142) // ConfirmPhase
        CASE_CREATE_SKILL_NODE(10021, 154) // DestroyCollider
        CASE_CREATE_SKILL_NODE(10021, 179) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(10021, 186) // GetInputLocation
        CASE_CREATE_SKILL_NODE(10021, 188) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10021, 190) // Disable
        CASE_CREATE_SKILL_NODE(10021, 192) // Delay
        CASE_CREATE_SKILL_NODE(10021, 195) // SetInt
        CASE_CREATE_SKILL_NODE(10021, 214) // PlayEffect
        CASE_CREATE_SKILL_NODE(10021, 216) // StopEffect
        CASE_CREATE_SKILL_NODE(10021, 220) // PlaySound
        CASE_CREATE_SKILL_NODE(10021, 223) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10021, 227) // GetActorAttribute
        CASE_CREATE_SKILL_NODE(10021, 229) // PlaySound
        CASE_CREATE_SKILL_NODE(10021, 232) // ResetCD
        CASE_CREATE_SKILL_NODE(10021, 234) // ResetCD
        CASE_CREATE_SKILL_NODE(10021, 236) // Delay
        CASE_CREATE_SKILL_NODE(10021, 238) // AreaCollisionNewPene
        CASE_CREATE_SKILL_NODE(10021, 240) // PlayEffect
        CASE_CREATE_SKILL_NODE(10021, 242) // If
        CASE_CREATE_SKILL_NODE(10021, 251) // SetBool
        CASE_CREATE_SKILL_NODE(10021, 253) // Detect
        CASE_CREATE_SKILL_NODE(10021, 254) // SwitchToInt
        CASE_CREATE_SKILL_NODE(10021, 256) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10021, 257) // StartPreInput
        CASE_CREATE_SKILL_NODE(10021, 258) // If
        CASE_CREATE_SKILL_NODE(10021, 259) // IsInterruptType
        CASE_CREATE_SKILL_NODE(10021, 260) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10021, 261) // Delay
        CASE_CREATE_SKILL_NODE(10021, 264) // SetBool
        CASE_CREATE_SKILL_NODE(10021, 265) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10021, 266) // Detect
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_10021

SkillLogic* SkillCreator_10021::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //设置变量
    Variable_10021_second = logic->getVariables().setVariable<bool>("second", true);
    Variable_10021_a100212 = logic->getVariables().setVariable<int32_t>("a100212", 1);
    Variable_10021_InterruptAnimat = logic->getVariables().setVariable<bool>("InterruptAnimat");
    //创建阶段phase
    auto phase = new SkillPhase_10021(1, logic, 4);
    //设置phase执行器
    phase->setRunPhaseNode(1, 2);
    phase->setRunPhaseNode(2, 25);
    phase->addConfirmPhaseNode(3, 142);
    phase->setDetectPhaseNode(4, 253);
    phase->setDetectPhaseNode(4, 266);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_10021::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
