#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

#include "skill_psnode_actorfilternewpene.h"
#include "skill_psnode_addskillbuff.h"
#include "skill_psnode_addskillbuffs.h"
#include "skill_psnode_attachto.h"
#include "skill_psnode_createtriggernewpene.h"
#include "skill_psnode_delay.h"
#include "skill_psnode_detect.h"
#include "skill_psnode_disable.h"
#include "skill_psnode_endphase.h"
#include "skill_psnode_getactorattribute.h"
#include "skill_psnode_getlocation.h"
#include "skill_psnode_getself.h"
#include "skill_psnode_if.h"
#include "skill_psnode_isinterrupttype.h"
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
uint64_t Variable_10022_a100222 = 0;
uint64_t Variable_10022_InterruptAnimat = 0;
//--------------------------------------------------------------------------------
// StartPhase
//
REGISTER_REGISTER_SKILL_NODE(10022, 2) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_StartPhase::TRIGGER_START, 152, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(10022, 2) {
    auto node2 = GET_SKILL_NODE(2, PhaseNode_StartPhase);
    if (node2 == nullptr) {
        node2 = new PhaseNode_StartPhase(2, phase);
        CALL_REGISTER_SKILL_NODE(10022, 2, node2)
    }
    if (noInit == true) {
        return node2;
    }
    return node2;
}
//--------------------------------------------------------------------------------
// TriggerUpdate
//
REGISTER_REGISTER_SKILL_NODE(10022, 10) {
}

REGISTER_CREATE_SKILL_NODE(10022, 10) {
    auto node10 = GET_SKILL_NODE(10, PhaseNode_TriggerUpdate);
    if (node10 == nullptr) {
        node10 = new PhaseNode_TriggerUpdate(10, phase);
        CALL_REGISTER_SKILL_NODE(10022, 10, node10)
    }
    if (noInit == true) {
        return node10;
    }
    return node10;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(10022, 12) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_GetLocation::TRIGGER_DONE, 111, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
    pnode->regTrigger<PhaseNode_SpawnCollider>(PhaseNode_GetLocation::TRIGGER_DONE, 23, PhaseNode_SpawnCollider::FUNC_DO, &PhaseNode_SpawnCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(10022, 12) {
    auto node12 = GET_SKILL_NODE(12, PhaseNode_GetLocation);
    if (node12 == nullptr) {
        node12 = new PhaseNode_GetLocation(12, phase);
        node12->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node12->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(10022, 12, node12)
    }
    if (noInit == true) {
        return node12;
    }
    return node12;
}
//--------------------------------------------------------------------------------
// Disable
//
REGISTER_REGISTER_SKILL_NODE(10022, 14) {
    pnode->resizeTrigger(PhaseNode_Disable::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuff>(PhaseNode_Disable::TRIGGER_DONE, 143, PhaseNode_AddSkillBuff::FUNC_ADD, &PhaseNode_AddSkillBuff::Add);
}

REGISTER_CREATE_SKILL_NODE(10022, 14) {
    auto node14 = GET_SKILL_NODE(14, PhaseNode_Disable);
    if (node14 == nullptr) {
        node14 = new PhaseNode_Disable(14, phase);
        node14->setTarget(0U);
        node14->setMove(false);
        node14->setSkill(true);
        node14->setShoot(true);
        node14->setTime(.56f);
        node14->setRotate(false);
        CALL_REGISTER_SKILL_NODE(10022, 14, node14)
    }
    if (noInit == true) {
        return node14;
    }
    return node14;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10022, 16) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_Delay::TRIGGER_DONE, 12, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(10022, 16) {
    auto node16 = GET_SKILL_NODE(16, PhaseNode_Delay);
    if (node16 == nullptr) {
        node16 = new PhaseNode_Delay(16, phase);
        node16->setTime(.20f);
        CALL_REGISTER_SKILL_NODE(10022, 16, node16)
    }
    if (noInit == true) {
        return node16;
    }
    return node16;
}
//--------------------------------------------------------------------------------
// SpawnCollider
//
REGISTER_REGISTER_SKILL_NODE(10022, 23) {
    pnode->resizeTrigger(PhaseNode_SpawnCollider::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_SpawnCollider::TRIGGER_DONE, 115, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
    pnode->regTrigger<PhaseNode_GetSelf>(PhaseNode_SpawnCollider::TRIGGER_DONE, 151, PhaseNode_GetSelf::FUNC_DO, &PhaseNode_GetSelf::Do);
}

REGISTER_CREATE_SKILL_NODE(10022, 23) {
    auto node23 = GET_SKILL_NODE(23, PhaseNode_SpawnCollider);
    if (node23 == nullptr) {
        node23 = new PhaseNode_SpawnCollider(23, phase);
        node23->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node23->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node23->setMesh("");
        node23->setMeshScale(.00f);
        node23->setEffectID(100222);
        node23->setEffectScale(1.00f);
        node23->setType(PhaseNode_SpawnCollider::SpawnCollider_Type::Circle);
        node23->setTypeParams(0, 6.00f);
        node23->setTime(5.00f);
        node23->setPosZ(.00f);
        node23->setRotation(.00f);
        node23->setreentry(true);
        node23->setCheckPeneSound(false);
        CALL_REGISTER_SKILL_NODE(10022, 23, node23)
    }
    if (noInit == true) {
        return node23;
    }
    auto node12 = GET_SKILL_NODE(12, PhaseNode_GetLocation);
    if (node12 != nullptr) node23->setPosX(node12->getX());
    if (node12 != nullptr) node23->setPosY(node12->getY());
    return node23;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10022, 25) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_Delay::TRIGGER_DONE, 27, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10022, 25) {
    auto node25 = GET_SKILL_NODE(25, PhaseNode_Delay);
    if (node25 == nullptr) {
        node25 = new PhaseNode_Delay(25, phase);
        node25->setTime(.50f);
        CALL_REGISTER_SKILL_NODE(10022, 25, node25)
    }
    if (noInit == true) {
        return node25;
    }
    return node25;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10022, 27) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlayAnimation::TRIGGER_DONE, 37, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10022, 27) {
    auto node27 = GET_SKILL_NODE(27, PhaseNode_PlayAnimation);
    if (node27 == nullptr) {
        node27 = new PhaseNode_PlayAnimation(27, phase);
        node27->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node27->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node27->setTarget(0U);
        node27->setAnimation("Idle");
        node27->setParameter("SkillArmBusy");
        node27->setValue(false);
        CALL_REGISTER_SKILL_NODE(10022, 27, node27)
    }
    if (noInit == true) {
        return node27;
    }
    return node27;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10022, 37) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_Delay::TRIGGER_DONE, 39, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(10022, 37) {
    auto node37 = GET_SKILL_NODE(37, PhaseNode_Delay);
    if (node37 == nullptr) {
        node37 = new PhaseNode_Delay(37, phase);
        node37->setTime(5.60f);
        CALL_REGISTER_SKILL_NODE(10022, 37, node37)
    }
    if (noInit == true) {
        return node37;
    }
    return node37;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(10022, 39) {
}

REGISTER_CREATE_SKILL_NODE(10022, 39) {
    auto node39 = GET_SKILL_NODE(39, PhaseNode_EndPhase);
    if (node39 == nullptr) {
        node39 = new PhaseNode_EndPhase(39, phase);
        node39->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node39->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10022, 39, node39)
    }
    if (noInit == true) {
        return node39;
    }
    return node39;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10022, 76) {
}

REGISTER_CREATE_SKILL_NODE(10022, 76) {
    auto node76 = GET_SKILL_NODE(76, PhaseNode_PlaySound);
    if (node76 == nullptr) {
        node76 = new PhaseNode_PlaySound(76, phase);
        node76->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node76->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node76->setSoundID("SE_Hero112_SkillB_P1");
        node76->setTarget(0U);
        node76->setUsePos(false);
        node76->setPosX(.00f);
        node76->setPosY(.00f);
        node76->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10022, 76, node76)
    }
    if (noInit == true) {
        return node76;
    }
    return node76;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(10022, 107) {
}

REGISTER_CREATE_SKILL_NODE(10022, 107) {
    auto node107 = GET_SKILL_NODE(107, PhaseNode_AddSkillBuffs);
    if (node107 == nullptr) {
        node107 = new PhaseNode_AddSkillBuffs(107, phase);
        node107->setConfigID({100221});
        CALL_REGISTER_SKILL_NODE(10022, 107, node107)
    }
    if (noInit == true) {
        return node107;
    }
    auto node121 = GET_SKILL_NODE(121, PhaseNode_ActorFilterNewPene);
    auto node155 = GET_SKILL_NODE(155, PhaseNode_GetActorAttribute);
    if (node121 != nullptr) node107->setTarget(node121->getOutput());
    if (node155 != nullptr) node107->setAttribute(node155->getAttribute());
    return node107;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(10022, 111) {
}

REGISTER_CREATE_SKILL_NODE(10022, 111) {
    auto node111 = GET_SKILL_NODE(111, PhaseNode_PlayEffect);
    if (node111 == nullptr) {
        node111 = new PhaseNode_PlayEffect(111, phase);
        node111->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node111->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node111->setEffectID(100221);
        node111->setChangeColor(true);
        node111->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node111->getVars().reserve(3);
        node111->getVars().setVariable<float>(0, .00f);
        node111->getVars().setVariable<float>(1, .00f);
        node111->getVars().setVariable<float>(2, .00f);
        node111->setRotation(.00f);
        node111->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(10022, 111, node111)
    }
    if (noInit == true) {
        return node111;
    }
    auto node12 = GET_SKILL_NODE(12, PhaseNode_GetLocation);
    if (node12 != nullptr) node111->getVars().setVariable<float>(0, node12->getX());
    if (node12 != nullptr) node111->getVars().setVariable<float>(1, node12->getY());
    return node111;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(10022, 115) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 117, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 121, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(10022, 115) {
    auto node115 = GET_SKILL_NODE(115, PhaseNode_CreateTriggerNewPene);
    if (node115 == nullptr) {
        node115 = new PhaseNode_CreateTriggerNewPene(115, phase);
        node115->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::Tick);
        node115->setTypeParams(0, .50f);
        node115->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node115->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Friend);
        node115->setOnHero(true);
        node115->setOnMinion(true);
        node115->setOnDestruct(false);
        node115->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(10022, 115, node115)
    }
    if (noInit == true) {
        return node115;
    }
    auto node23 = GET_SKILL_NODE(23, PhaseNode_SpawnCollider);
    if (node23 != nullptr) node115->setColliderID(node23->getColliderID());
    return node115;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(10022, 117) {
}

REGISTER_CREATE_SKILL_NODE(10022, 117) {
    auto node117 = GET_SKILL_NODE(117, PhaseNode_TriggerCheck);
    if (node117 == nullptr) {
        node117 = new PhaseNode_TriggerCheck(117, phase);
        auto node10 = GET_SKILL_NODE(10, PhaseNode_TriggerUpdate);
        if (node10 != nullptr) node10->addTriggerCheck(node117);
        
        CALL_REGISTER_SKILL_NODE(10022, 117, node117)
    }
    if (noInit == true) {
        return node117;
    }
    auto node115 = GET_SKILL_NODE(115, PhaseNode_CreateTriggerNewPene);
    if (node115 != nullptr) node117->setTrigger(0, node115->getTriggerID());
    return node117;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(10022, 121) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 107, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
}

REGISTER_CREATE_SKILL_NODE(10022, 121) {
    auto node121 = GET_SKILL_NODE(121, PhaseNode_ActorFilterNewPene);
    if (node121 == nullptr) {
        node121 = new PhaseNode_ActorFilterNewPene(121, phase);
        node121->setHero(true);
        node121->setMinion(true);
        node121->setDestruct(false);
        node121->setShield(false);
        node121->setTotalCount(0);
        node121->setPerCount(0);
        CALL_REGISTER_SKILL_NODE(10022, 121, node121)
    }
    if (noInit == true) {
        return node121;
    }
    auto node115 = GET_SKILL_NODE(115, PhaseNode_CreateTriggerNewPene);
    if (node115 != nullptr) node121->setInput(node115->getOther());
    return node121;
}
//--------------------------------------------------------------------------------
// AddSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10022, 143) {
    pnode->resizeTrigger(PhaseNode_AddSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_AddSkillBuff::TRIGGER_DONE, 16, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10022, 143) {
    auto node143 = GET_SKILL_NODE(143, PhaseNode_AddSkillBuff);
    if (node143 == nullptr) {
        node143 = new PhaseNode_AddSkillBuff(143, phase);
        node143->setConfigID(100222);
        node143->setConfigIDs({});
        node143->setTarget(0U);
        node143->setAttribute({{}});
        CALL_REGISTER_SKILL_NODE(10022, 143, node143)
    }
    if (noInit == true) {
        return node143;
    }
    return node143;
}
//--------------------------------------------------------------------------------
// AttachTo
//
REGISTER_REGISTER_SKILL_NODE(10022, 149) {
    pnode->resizeTrigger(PhaseNode_AttachTo::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_AttachTo::TRIGGER_DONE, 25, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10022, 149) {
    auto node149 = GET_SKILL_NODE(149, PhaseNode_AttachTo);
    if (node149 == nullptr) {
        node149 = new PhaseNode_AttachTo(149, phase);
        node149->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node149->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node149->setChangeRotation(false);
        node149->setreentry(false);
        CALL_REGISTER_SKILL_NODE(10022, 149, node149)
    }
    if (noInit == true) {
        return node149;
    }
    auto node151 = GET_SKILL_NODE(151, PhaseNode_GetSelf);
    auto node23 = GET_SKILL_NODE(23, PhaseNode_SpawnCollider);
    if (node151 != nullptr) node149->setParent(node151->getTarget());
    if (node23 != nullptr) node149->setChild(node23->getColliderID());
    return node149;
}
//--------------------------------------------------------------------------------
// GetSelf
//
REGISTER_REGISTER_SKILL_NODE(10022, 151) {
    pnode->resizeTrigger(PhaseNode_GetSelf::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AttachTo>(PhaseNode_GetSelf::TRIGGER_DONE, 149, PhaseNode_AttachTo::FUNC_DO, &PhaseNode_AttachTo::Do);
}

REGISTER_CREATE_SKILL_NODE(10022, 151) {
    auto node151 = GET_SKILL_NODE(151, PhaseNode_GetSelf);
    if (node151 == nullptr) {
        node151 = new PhaseNode_GetSelf(151, phase);
        CALL_REGISTER_SKILL_NODE(10022, 151, node151)
    }
    if (noInit == true) {
        return node151;
    }
    return node151;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(10022, 152) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_ResetCD::TRIGGER_DONE, 153, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10022, 152) {
    auto node152 = GET_SKILL_NODE(152, PhaseNode_ResetCD);
    if (node152 == nullptr) {
        node152 = new PhaseNode_ResetCD(152, phase);
        node152->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node152->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node152->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(10022, 152, node152)
    }
    if (noInit == true) {
        return node152;
    }
    return node152;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10022, 153) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_PlayAnimation::TRIGGER_DONE, 155, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(10022, 153) {
    auto node153 = GET_SKILL_NODE(153, PhaseNode_PlayAnimation);
    if (node153 == nullptr) {
        node153 = new PhaseNode_PlayAnimation(153, phase);
        node153->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node153->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node153->setTarget(0U);
        node153->setAnimation("Skill2S1");
        node153->setParameter("SkillArmBusy");
        node153->setValue(true);
        CALL_REGISTER_SKILL_NODE(10022, 153, node153)
    }
    if (noInit == true) {
        return node153;
    }
    return node153;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10022, 154) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Disable>(PhaseNode_PlaySound::TRIGGER_DONE, 14, PhaseNode_Disable::FUNC_DO, &PhaseNode_Disable::Do);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_PlaySound::TRIGGER_DONE, 160, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10022, 154) {
    auto node154 = GET_SKILL_NODE(154, PhaseNode_PlaySound);
    if (node154 == nullptr) {
        node154 = new PhaseNode_PlaySound(154, phase);
        node154->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node154->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node154->setSoundID("VO_Hero112_Skill_B");
        node154->setTarget(0U);
        node154->setUsePos(false);
        node154->setPosX(.00f);
        node154->setPosY(.00f);
        node154->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10022, 154, node154)
    }
    if (noInit == true) {
        return node154;
    }
    return node154;
}
//--------------------------------------------------------------------------------
// GetActorAttribute
//
REGISTER_REGISTER_SKILL_NODE(10022, 155) {
    pnode->resizeTrigger(PhaseNode_GetActorAttribute::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 154, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10022, 155) {
    auto node155 = GET_SKILL_NODE(155, PhaseNode_GetActorAttribute);
    if (node155 == nullptr) {
        node155 = new PhaseNode_GetActorAttribute(155, phase);
        node155->setTarget(0U);
        node155->setType({});
        CALL_REGISTER_SKILL_NODE(10022, 155, node155)
    }
    if (noInit == true) {
        return node155;
    }
    return node155;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10022, 157) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_IsInterruptType>(PhaseNode_Detect::TRIGGER_ON, 163, PhaseNode_IsInterruptType::FUNC_DO, &PhaseNode_IsInterruptType::Do);
}

REGISTER_CREATE_SKILL_NODE(10022, 157) {
    auto node157 = GET_SKILL_NODE(157, PhaseNode_Detect);
    if (node157 == nullptr) {
        node157 = new PhaseNode_Detect(157, phase);
        node157->setSelf(0U);
        node157->setEvent("daduan_001");
        node157->setType(PhaseNode_Detect::Detect_Type::Interrupt_Skill);
        node157->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10022, 157, node157)
    }
    if (noInit == true) {
        return node157;
    }
    return node157;
}
//--------------------------------------------------------------------------------
// SwitchToInt
//
REGISTER_REGISTER_SKILL_NODE(10022, 158) {
}

REGISTER_CREATE_SKILL_NODE(10022, 158) {
    auto node158 = GET_SKILL_NODE(158, PhaseNode_SwitchToInt);
    if (node158 == nullptr) {
        node158 = new PhaseNode_SwitchToInt(158, phase);
        CALL_REGISTER_SKILL_NODE(10022, 158, node158)
    }
    if (noInit == true) {
        return node158;
    }
    auto variables = node158->getVariables();
    if (variables != nullptr) {
        node158->setSelection(variables->getVariable<int32_t>(Variable_10022_a100222));
    }
    return node158;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10022, 160) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_RaiseEvent::TRIGGER_DONE, 169, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10022, 160) {
    auto node160 = GET_SKILL_NODE(160, PhaseNode_RaiseEvent);
    if (node160 == nullptr) {
        node160 = new PhaseNode_RaiseEvent(160, phase);
        node160->setEvent("daduan_001");
        node160->setTarget(0U);
        node160->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node160->setTypeParams(0, 0);
        node160->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10022, 160, node160)
    }
    if (noInit == true) {
        return node160;
    }
    return node160;
}
//--------------------------------------------------------------------------------
// StartPreInput
//
REGISTER_REGISTER_SKILL_NODE(10022, 161) {
    pnode->resizeTrigger(PhaseNode_StartPreInput::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_StartPreInput::TRIGGER_DONE, 165, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_StartPreInput::TRIGGER_DONE, 76, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10022, 161) {
    auto node161 = GET_SKILL_NODE(161, PhaseNode_StartPreInput);
    if (node161 == nullptr) {
        node161 = new PhaseNode_StartPreInput(161, phase);
        node161->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node161->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node161->setDelayTime(.00f);
        CALL_REGISTER_SKILL_NODE(10022, 161, node161)
    }
    if (noInit == true) {
        return node161;
    }
    return node161;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(10022, 162) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_If::TRIGGER_TRUE, 164, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10022, 162) {
    auto node162 = GET_SKILL_NODE(162, PhaseNode_If);
    if (node162 == nullptr) {
        node162 = new PhaseNode_If(162, phase);
        CALL_REGISTER_SKILL_NODE(10022, 162, node162)
    }
    if (noInit == true) {
        return node162;
    }
    auto variables = node162->getVariables();
    if (variables != nullptr) {
        node162->setCondition(variables->getVariable<bool>(Variable_10022_InterruptAnimat));
    }
    return node162;
}
//--------------------------------------------------------------------------------
// IsInterruptType
//
REGISTER_REGISTER_SKILL_NODE(10022, 163) {
    pnode->resizeTrigger(PhaseNode_IsInterruptType::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SwitchToInt>(PhaseNode_IsInterruptType::TRIGGER_BUFF, 158, PhaseNode_SwitchToInt::FUNC_SWITCH, &PhaseNode_SwitchToInt::Switch);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_POSCHANGE, 162, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTAIM, 162, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTFIRE, 162, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTRELOAD, 162, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_USESKILL, 162, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(10022, 163) {
    auto node163 = GET_SKILL_NODE(163, PhaseNode_IsInterruptType);
    if (node163 == nullptr) {
        node163 = new PhaseNode_IsInterruptType(163, phase);
        node163->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node163->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10022, 163, node163)
    }
    if (noInit == true) {
        return node163;
    }
    auto node157 = GET_SKILL_NODE(157, PhaseNode_Detect);
    if (node157 != nullptr) node163->setType(node157->getVars().getVariable<int32_t>(2));
    return node163;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10022, 164) {
}

REGISTER_CREATE_SKILL_NODE(10022, 164) {
    auto node164 = GET_SKILL_NODE(164, PhaseNode_PlayAnimation);
    if (node164 == nullptr) {
        node164 = new PhaseNode_PlayAnimation(164, phase);
        node164->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node164->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node164->setTarget(0U);
        node164->setAnimation("Idle");
        node164->setParameter("");
        node164->setValue(false);
        CALL_REGISTER_SKILL_NODE(10022, 164, node164)
    }
    if (noInit == true) {
        return node164;
    }
    return node164;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10022, 165) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_Delay::TRIGGER_DONE, 168, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(10022, 165) {
    auto node165 = GET_SKILL_NODE(165, PhaseNode_Delay);
    if (node165 == nullptr) {
        node165 = new PhaseNode_Delay(165, phase);
        node165->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(10022, 165, node165)
    }
    if (noInit == true) {
        return node165;
    }
    return node165;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(10022, 168) {
}

REGISTER_CREATE_SKILL_NODE(10022, 168) {
    auto node168 = GET_SKILL_NODE(168, PhaseNode_SetBool);
    if (node168 == nullptr) {
        node168 = new PhaseNode_SetBool(168, phase);
        node168->setName("InterruptAnimat");
        node168->setValue(true);
        CALL_REGISTER_SKILL_NODE(10022, 168, node168)
    }
    if (noInit == true) {
        return node168;
    }
    return node168;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10022, 169) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StartPreInput>(PhaseNode_RaiseEvent::TRIGGER_DONE, 161, PhaseNode_StartPreInput::FUNC_DO, &PhaseNode_StartPreInput::Do);
}

REGISTER_CREATE_SKILL_NODE(10022, 169) {
    auto node169 = GET_SKILL_NODE(169, PhaseNode_RaiseEvent);
    if (node169 == nullptr) {
        node169 = new PhaseNode_RaiseEvent(169, phase);
        node169->setEvent("Dead_001");
        node169->setTarget(0U);
        node169->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node169->setTypeParams(0, 0);
        node169->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10022, 169, node169)
    }
    if (noInit == true) {
        return node169;
    }
    return node169;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10022, 170) {
}

REGISTER_CREATE_SKILL_NODE(10022, 170) {
    auto node170 = GET_SKILL_NODE(170, PhaseNode_Detect);
    if (node170 == nullptr) {
        node170 = new PhaseNode_Detect(170, phase);
        node170->setSelf(0U);
        node170->setEvent("Dead_001");
        node170->setType(PhaseNode_Detect::Detect_Type::Actor_Dead);
        node170->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10022, 170, node170)
    }
    if (noInit == true) {
        return node170;
    }
    return node170;
}

//--------------------------------------------------------------------------------
// SkillCreator_10022
//
class SkillCreator_10022 : public SkillCreator {
public:
    SkillCreator_10022() {}
    virtual ~SkillCreator_10022() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_10022

//--------------------------------------------------------------------------------
// SkillPhase_10022
//
class SkillPhase_10022 : public SkillPhase {
public:
    SkillPhase_10022(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_10022() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(10022, 2) // StartPhase
        CASE_CREATE_SKILL_NODE(10022, 10) // TriggerUpdate
        CASE_CREATE_SKILL_NODE(10022, 12) // GetLocation
        CASE_CREATE_SKILL_NODE(10022, 14) // Disable
        CASE_CREATE_SKILL_NODE(10022, 16) // Delay
        CASE_CREATE_SKILL_NODE(10022, 23) // SpawnCollider
        CASE_CREATE_SKILL_NODE(10022, 25) // Delay
        CASE_CREATE_SKILL_NODE(10022, 27) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10022, 37) // Delay
        CASE_CREATE_SKILL_NODE(10022, 39) // EndPhase
        CASE_CREATE_SKILL_NODE(10022, 76) // PlaySound
        CASE_CREATE_SKILL_NODE(10022, 107) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(10022, 111) // PlayEffect
        CASE_CREATE_SKILL_NODE(10022, 115) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(10022, 117) // TriggerCheck
        CASE_CREATE_SKILL_NODE(10022, 121) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(10022, 143) // AddSkillBuff
        CASE_CREATE_SKILL_NODE(10022, 149) // AttachTo
        CASE_CREATE_SKILL_NODE(10022, 151) // GetSelf
        CASE_CREATE_SKILL_NODE(10022, 152) // ResetCD
        CASE_CREATE_SKILL_NODE(10022, 153) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10022, 154) // PlaySound
        CASE_CREATE_SKILL_NODE(10022, 155) // GetActorAttribute
        CASE_CREATE_SKILL_NODE(10022, 157) // Detect
        CASE_CREATE_SKILL_NODE(10022, 158) // SwitchToInt
        CASE_CREATE_SKILL_NODE(10022, 160) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10022, 161) // StartPreInput
        CASE_CREATE_SKILL_NODE(10022, 162) // If
        CASE_CREATE_SKILL_NODE(10022, 163) // IsInterruptType
        CASE_CREATE_SKILL_NODE(10022, 164) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10022, 165) // Delay
        CASE_CREATE_SKILL_NODE(10022, 168) // SetBool
        CASE_CREATE_SKILL_NODE(10022, 169) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10022, 170) // Detect
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_10022

SkillLogic* SkillCreator_10022::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //设置变量
    Variable_10022_a100222 = logic->getVariables().setVariable<int32_t>("a100222", 1);
    Variable_10022_InterruptAnimat = logic->getVariables().setVariable<bool>("InterruptAnimat");
    //创建阶段phase
    auto phase = new SkillPhase_10022(1, logic, 3);
    //设置phase执行器
    phase->setRunPhaseNode(1, 2);
    phase->setRunPhaseNode(2, 10);
    phase->setDetectPhaseNode(3, 157);
    phase->setDetectPhaseNode(3, 170);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_10022::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
