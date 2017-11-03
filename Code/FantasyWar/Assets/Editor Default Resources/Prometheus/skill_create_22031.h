#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

#include "skill_psnode_actorfilternewpene.h"
#include "skill_psnode_addskillbuff.h"
#include "skill_psnode_comparefloat.h"
#include "skill_psnode_createtriggernewpene.h"
#include "skill_psnode_delay.h"
#include "skill_psnode_detect.h"
#include "skill_psnode_disable.h"
#include "skill_psnode_distance.h"
#include "skill_psnode_endphase.h"
#include "skill_psnode_for.h"
#include "skill_psnode_forcontinue.h"
#include "skill_psnode_getlocation.h"
#include "skill_psnode_getrotation.h"
#include "skill_psnode_getuint64svalue.h"
#include "skill_psnode_if.h"
#include "skill_psnode_linechecknewpene.h"
#include "skill_psnode_offsetcalculate.h"
#include "skill_psnode_playanimation.h"
#include "skill_psnode_playeffect.h"
#include "skill_psnode_playsound.h"
#include "skill_psnode_raiseevent.h"
#include "skill_psnode_resetcd.h"
#include "skill_psnode_setfloat.h"
#include "skill_psnode_setuint64.h"
#include "skill_psnode_skillendnotify.h"
#include "skill_psnode_spawncollider.h"
#include "skill_psnode_spawnprojectile.h"
#include "skill_psnode_startphase.h"
#include "skill_psnode_stopeffect.h"
#include "skill_psnode_triggercheck.h"
#include "skill_psnode_triggerupdate.h"
#include "skill_psnode_uint64ssize.h"

namespace pvp {

//变量声明
uint64_t Variable_22031_Target = 0;
uint64_t Variable_22031_Temp = 0;
//--------------------------------------------------------------------------------
// StartPhase
//
REGISTER_REGISTER_SKILL_NODE(22031, 2) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Disable>(PhaseNode_StartPhase::TRIGGER_START, 137, PhaseNode_Disable::FUNC_DO, &PhaseNode_Disable::Do);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_StartPhase::TRIGGER_START, 185, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(22031, 2) {
    auto node2 = GET_SKILL_NODE(2, PhaseNode_StartPhase);
    if (node2 == nullptr) {
        node2 = new PhaseNode_StartPhase(2, phase);
        CALL_REGISTER_SKILL_NODE(22031, 2, node2)
    }
    if (noInit == true) {
        return node2;
    }
    return node2;
}
//--------------------------------------------------------------------------------
// TriggerUpdate
//
REGISTER_REGISTER_SKILL_NODE(22031, 4) {
}

REGISTER_CREATE_SKILL_NODE(22031, 4) {
    auto node4 = GET_SKILL_NODE(4, PhaseNode_TriggerUpdate);
    if (node4 == nullptr) {
        node4 = new PhaseNode_TriggerUpdate(4, phase);
        CALL_REGISTER_SKILL_NODE(22031, 4, node4)
    }
    if (noInit == true) {
        return node4;
    }
    return node4;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(22031, 20) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_PlayAnimation::TRIGGER_DONE, 146, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(22031, 20) {
    auto node20 = GET_SKILL_NODE(20, PhaseNode_PlayAnimation);
    if (node20 == nullptr) {
        node20 = new PhaseNode_PlayAnimation(20, phase);
        node20->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node20->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node20->setTarget(0U);
        node20->setAnimation("Skill1S2");
        node20->setParameter("");
        node20->setValue(false);
        CALL_REGISTER_SKILL_NODE(22031, 20, node20)
    }
    if (noInit == true) {
        return node20;
    }
    return node20;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22031, 22) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_Delay::TRIGGER_DONE, 132, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(22031, 22) {
    auto node22 = GET_SKILL_NODE(22, PhaseNode_Delay);
    if (node22 == nullptr) {
        node22 = new PhaseNode_Delay(22, phase);
        node22->setTime(.80f);
        CALL_REGISTER_SKILL_NODE(22031, 22, node22)
    }
    if (noInit == true) {
        return node22;
    }
    return node22;
}
//--------------------------------------------------------------------------------
// SpawnProjectile
//
REGISTER_REGISTER_SKILL_NODE(22031, 24) {
    pnode->resizeTrigger(PhaseNode_SpawnProjectile::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_SpawnProjectile::TRIGGER_DONE, 176, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(22031, 24) {
    auto node24 = GET_SKILL_NODE(24, PhaseNode_SpawnProjectile);
    if (node24 == nullptr) {
        node24 = new PhaseNode_SpawnProjectile(24, phase);
        node24->setDataId(52203);
        node24->setEndPosX(.00f);
        node24->setEndPosY(.00f);
        node24->setEndPosZ(.00f);
        node24->setMaxCount(0);
        CALL_REGISTER_SKILL_NODE(22031, 24, node24)
    }
    if (noInit == true) {
        return node24;
    }
    auto node140 = GET_SKILL_NODE(140, PhaseNode_OffsetCalculate);
    if (node140 != nullptr) node24->setPosX(node140->getOutPosX());
    if (node140 != nullptr) node24->setPosY(node140->getOutPosY());
    if (node140 != nullptr) node24->setPosZ(node140->getOutPosZ());
    if (node140 != nullptr) node24->setRotation(node140->getOutRotation());
    return node24;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22031, 31) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_Delay::TRIGGER_DONE, 52, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(22031, 31) {
    auto node31 = GET_SKILL_NODE(31, PhaseNode_Delay);
    if (node31 == nullptr) {
        node31 = new PhaseNode_Delay(31, phase);
        node31->setTime(.40f);
        CALL_REGISTER_SKILL_NODE(22031, 31, node31)
    }
    if (noInit == true) {
        return node31;
    }
    return node31;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(22031, 33) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnProjectile>(PhaseNode_PlayAnimation::TRIGGER_DONE, 24, PhaseNode_SpawnProjectile::FUNC_DO, &PhaseNode_SpawnProjectile::Do);
}

REGISTER_CREATE_SKILL_NODE(22031, 33) {
    auto node33 = GET_SKILL_NODE(33, PhaseNode_PlayAnimation);
    if (node33 == nullptr) {
        node33 = new PhaseNode_PlayAnimation(33, phase);
        node33->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node33->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node33->setTarget(0U);
        node33->setAnimation("Skill1S3");
        node33->setParameter("");
        node33->setValue(false);
        CALL_REGISTER_SKILL_NODE(22031, 33, node33)
    }
    if (noInit == true) {
        return node33;
    }
    return node33;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(22031, 37) {
}

REGISTER_CREATE_SKILL_NODE(22031, 37) {
    auto node37 = GET_SKILL_NODE(37, PhaseNode_EndPhase);
    if (node37 == nullptr) {
        node37 = new PhaseNode_EndPhase(37, phase);
        node37->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node37->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(22031, 37, node37)
    }
    if (noInit == true) {
        return node37;
    }
    return node37;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(22031, 46) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_Detect::TRIGGER_ON, 48, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(22031, 46) {
    auto node46 = GET_SKILL_NODE(46, PhaseNode_Detect);
    if (node46 == nullptr) {
        node46 = new PhaseNode_Detect(46, phase);
        node46->setSelf(0U);
        node46->setEvent("");
        node46->setType(PhaseNode_Detect::Detect_Type::Actor_Dead);
        node46->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(22031, 46, node46)
    }
    if (noInit == true) {
        return node46;
    }
    return node46;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(22031, 48) {
}

REGISTER_CREATE_SKILL_NODE(22031, 48) {
    auto node48 = GET_SKILL_NODE(48, PhaseNode_EndPhase);
    if (node48 == nullptr) {
        node48 = new PhaseNode_EndPhase(48, phase);
        node48->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node48->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(22031, 48, node48)
    }
    if (noInit == true) {
        return node48;
    }
    return node48;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(22031, 52) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlayAnimation::TRIGGER_DONE, 181, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(22031, 52) {
    auto node52 = GET_SKILL_NODE(52, PhaseNode_PlayAnimation);
    if (node52 == nullptr) {
        node52 = new PhaseNode_PlayAnimation(52, phase);
        node52->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node52->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node52->setTarget(0U);
        node52->setAnimation("Skill1S4");
        node52->setParameter("");
        node52->setValue(false);
        CALL_REGISTER_SKILL_NODE(22031, 52, node52)
    }
    if (noInit == true) {
        return node52;
    }
    return node52;
}
//--------------------------------------------------------------------------------
// SpawnCollider
//
REGISTER_REGISTER_SKILL_NODE(22031, 58) {
    pnode->resizeTrigger(PhaseNode_SpawnCollider::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_SpawnCollider::TRIGGER_DONE, 116, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_SpawnCollider::TRIGGER_DONE, 22, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(22031, 58) {
    auto node58 = GET_SKILL_NODE(58, PhaseNode_SpawnCollider);
    if (node58 == nullptr) {
        node58 = new PhaseNode_SpawnCollider(58, phase);
        node58->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node58->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node58->setMesh("");
        node58->setMeshScale(.00f);
        node58->setEffectID(0);
        node58->setEffectScale(.00f);
        node58->setType(PhaseNode_SpawnCollider::SpawnCollider_Type::Rect);
        node58->setTypeParams(0, .30f);
        node58->setTypeParams(1, 18.00f);
        node58->setTime(.80f);
        node58->setPosZ(.00f);
        node58->setreentry(false);
        node58->setCheckPeneSound(false);
        CALL_REGISTER_SKILL_NODE(22031, 58, node58)
    }
    if (noInit == true) {
        return node58;
    }
    auto node153 = GET_SKILL_NODE(153, PhaseNode_OffsetCalculate);
    if (node153 != nullptr) node58->setPosX(node153->getOutPosX());
    if (node153 != nullptr) node58->setPosY(node153->getOutPosY());
    if (node153 != nullptr) node58->setRotation(node153->getOutRotation());
    return node58;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(22031, 62) {
}

REGISTER_CREATE_SKILL_NODE(22031, 62) {
    auto node62 = GET_SKILL_NODE(62, PhaseNode_TriggerCheck);
    if (node62 == nullptr) {
        node62 = new PhaseNode_TriggerCheck(62, phase);
        auto node4 = GET_SKILL_NODE(4, PhaseNode_TriggerUpdate);
        if (node4 != nullptr) node4->addTriggerCheck(node62);
        
        CALL_REGISTER_SKILL_NODE(22031, 62, node62)
    }
    if (noInit == true) {
        return node62;
    }
    auto node116 = GET_SKILL_NODE(116, PhaseNode_CreateTriggerNewPene);
    if (node116 != nullptr) node62->setTrigger(0, node116->getTriggerID());
    return node62;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(22031, 116) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 62, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 118, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(22031, 116) {
    auto node116 = GET_SKILL_NODE(116, PhaseNode_CreateTriggerNewPene);
    if (node116 == nullptr) {
        node116 = new PhaseNode_CreateTriggerNewPene(116, phase);
        node116->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::Tick);
        node116->setTypeParams(0, .20f);
        node116->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node116->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Enemy);
        node116->setOnHero(true);
        node116->setOnMinion(true);
        node116->setOnDestruct(false);
        node116->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(22031, 116, node116)
    }
    if (noInit == true) {
        return node116;
    }
    auto node58 = GET_SKILL_NODE(58, PhaseNode_SpawnCollider);
    if (node58 != nullptr) node116->setColliderID(node58->getColliderID());
    return node116;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(22031, 118) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_LineCheckNewPene>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 121, PhaseNode_LineCheckNewPene::FUNC_DO, &PhaseNode_LineCheckNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(22031, 118) {
    auto node118 = GET_SKILL_NODE(118, PhaseNode_ActorFilterNewPene);
    if (node118 == nullptr) {
        node118 = new PhaseNode_ActorFilterNewPene(118, phase);
        node118->setHero(true);
        node118->setMinion(true);
        node118->setDestruct(false);
        node118->setShield(false);
        node118->setTotalCount(0);
        node118->setPerCount(0);
        CALL_REGISTER_SKILL_NODE(22031, 118, node118)
    }
    if (noInit == true) {
        return node118;
    }
    auto node116 = GET_SKILL_NODE(116, PhaseNode_CreateTriggerNewPene);
    if (node116 != nullptr) node118->setInput(node116->getOther());
    return node118;
}
//--------------------------------------------------------------------------------
// LineCheckNewPene
//
REGISTER_REGISTER_SKILL_NODE(22031, 121) {
    pnode->resizeTrigger(PhaseNode_LineCheckNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetUInt64sValue>(PhaseNode_LineCheckNewPene::TRIGGER_DONE, 156, PhaseNode_GetUInt64sValue::FUNC_DO, &PhaseNode_GetUInt64sValue::Do);
}

REGISTER_CREATE_SKILL_NODE(22031, 121) {
    auto node121 = GET_SKILL_NODE(121, PhaseNode_LineCheckNewPene);
    if (node121 == nullptr) {
        node121 = new PhaseNode_LineCheckNewPene(121, phase);
        node121->setPeneProjectile(11);
        CALL_REGISTER_SKILL_NODE(22031, 121, node121)
    }
    if (noInit == true) {
        return node121;
    }
    auto node118 = GET_SKILL_NODE(118, PhaseNode_ActorFilterNewPene);
    auto node140 = GET_SKILL_NODE(140, PhaseNode_OffsetCalculate);
    if (node118 != nullptr) node121->setTargets(node118->getOutput());
    if (node140 != nullptr) node121->setFromX(node140->getOutPosX());
    if (node140 != nullptr) node121->setFromY(node140->getOutPosY());
    return node121;
}
//--------------------------------------------------------------------------------
// AddSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(22031, 130) {
}

REGISTER_CREATE_SKILL_NODE(22031, 130) {
    auto node130 = GET_SKILL_NODE(130, PhaseNode_AddSkillBuff);
    if (node130 == nullptr) {
        node130 = new PhaseNode_AddSkillBuff(130, phase);
        node130->setConfigID(220312);
        node130->setConfigIDs({});
        node130->setAttribute({{}});
        CALL_REGISTER_SKILL_NODE(22031, 130, node130)
    }
    if (noInit == true) {
        return node130;
    }
    auto variables = node130->getVariables();
    if (variables != nullptr) {
        node130->setTarget(variables->getVariable<uint64_t>(Variable_22031_Target));
    }
    return node130;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(22031, 132) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_PlaySound::TRIGGER_DONE, 33, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(22031, 132) {
    auto node132 = GET_SKILL_NODE(132, PhaseNode_PlaySound);
    if (node132 == nullptr) {
        node132 = new PhaseNode_PlaySound(132, phase);
        node132->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node132->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node132->setSoundID("SE_MON2203_ATK1_P1");
        node132->setTarget(0U);
        node132->setUsePos(false);
        node132->setPosX(.00f);
        node132->setPosY(.00f);
        node132->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(22031, 132, node132)
    }
    if (noInit == true) {
        return node132;
    }
    return node132;
}
//--------------------------------------------------------------------------------
// Disable
//
REGISTER_REGISTER_SKILL_NODE(22031, 137) {
    pnode->resizeTrigger(PhaseNode_Disable::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_Disable::TRIGGER_DONE, 141, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(22031, 137) {
    auto node137 = GET_SKILL_NODE(137, PhaseNode_Disable);
    if (node137 == nullptr) {
        node137 = new PhaseNode_Disable(137, phase);
        node137->setTarget(0U);
        node137->setMove(true);
        node137->setSkill(false);
        node137->setShoot(false);
        node137->setTime(1.50f);
        node137->setRotate(false);
        CALL_REGISTER_SKILL_NODE(22031, 137, node137)
    }
    if (noInit == true) {
        return node137;
    }
    return node137;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(22031, 138) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetRotation>(PhaseNode_GetLocation::TRIGGER_DONE, 139, PhaseNode_GetRotation::FUNC_DO, &PhaseNode_GetRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(22031, 138) {
    auto node138 = GET_SKILL_NODE(138, PhaseNode_GetLocation);
    if (node138 == nullptr) {
        node138 = new PhaseNode_GetLocation(138, phase);
        node138->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node138->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(22031, 138, node138)
    }
    if (noInit == true) {
        return node138;
    }
    return node138;
}
//--------------------------------------------------------------------------------
// GetRotation
//
REGISTER_REGISTER_SKILL_NODE(22031, 139) {
    pnode->resizeTrigger(PhaseNode_GetRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_OffsetCalculate>(PhaseNode_GetRotation::TRIGGER_DONE, 140, PhaseNode_OffsetCalculate::FUNC_DO, &PhaseNode_OffsetCalculate::Do);
}

REGISTER_CREATE_SKILL_NODE(22031, 139) {
    auto node139 = GET_SKILL_NODE(139, PhaseNode_GetRotation);
    if (node139 == nullptr) {
        node139 = new PhaseNode_GetRotation(139, phase);
        node139->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node139->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(22031, 139, node139)
    }
    if (noInit == true) {
        return node139;
    }
    return node139;
}
//--------------------------------------------------------------------------------
// OffsetCalculate
//
REGISTER_REGISTER_SKILL_NODE(22031, 140) {
    pnode->resizeTrigger(PhaseNode_OffsetCalculate::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 20, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(22031, 140) {
    auto node140 = GET_SKILL_NODE(140, PhaseNode_OffsetCalculate);
    if (node140 == nullptr) {
        node140 = new PhaseNode_OffsetCalculate(140, phase);
        node140->setPosZ(.00f);
        node140->setOffsetX(.28f);
        node140->setOffsetY(2.00f);
        node140->setOffsetZ(2.50f);
        node140->setRotOffset(.00f);
        CALL_REGISTER_SKILL_NODE(22031, 140, node140)
    }
    if (noInit == true) {
        return node140;
    }
    auto node138 = GET_SKILL_NODE(138, PhaseNode_GetLocation);
    auto node139 = GET_SKILL_NODE(139, PhaseNode_GetRotation);
    if (node138 != nullptr) node140->setPosX(node138->getX());
    if (node138 != nullptr) node140->setPosY(node138->getY());
    if (node139 != nullptr) node140->setRotation(node139->getAngle());
    return node140;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(22031, 141) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_ResetCD::TRIGGER_DONE, 142, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(22031, 141) {
    auto node141 = GET_SKILL_NODE(141, PhaseNode_ResetCD);
    if (node141 == nullptr) {
        node141 = new PhaseNode_ResetCD(141, phase);
        node141->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node141->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node141->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(22031, 141, node141)
    }
    if (noInit == true) {
        return node141;
    }
    return node141;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(22031, 142) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_PlayAnimation::TRIGGER_DONE, 143, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(22031, 142) {
    auto node142 = GET_SKILL_NODE(142, PhaseNode_PlayAnimation);
    if (node142 == nullptr) {
        node142 = new PhaseNode_PlayAnimation(142, phase);
        node142->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node142->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node142->setTarget(0U);
        node142->setAnimation("Skill1S1");
        node142->setParameter("");
        node142->setValue(false);
        CALL_REGISTER_SKILL_NODE(22031, 142, node142)
    }
    if (noInit == true) {
        return node142;
    }
    return node142;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(22031, 143) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlaySound::TRIGGER_DONE, 144, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(22031, 143) {
    auto node143 = GET_SKILL_NODE(143, PhaseNode_PlaySound);
    if (node143 == nullptr) {
        node143 = new PhaseNode_PlaySound(143, phase);
        node143->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node143->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node143->setSoundID("");
        node143->setTarget(0U);
        node143->setUsePos(false);
        node143->setPosX(.00f);
        node143->setPosY(.00f);
        node143->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(22031, 143, node143)
    }
    if (noInit == true) {
        return node143;
    }
    return node143;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22031, 144) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_Delay::TRIGGER_DONE, 138, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(22031, 144) {
    auto node144 = GET_SKILL_NODE(144, PhaseNode_Delay);
    if (node144 == nullptr) {
        node144 = new PhaseNode_Delay(144, phase);
        node144->setTime(.33f);
        CALL_REGISTER_SKILL_NODE(22031, 144, node144)
    }
    if (noInit == true) {
        return node144;
    }
    return node144;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(22031, 145) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_PlayEffect::TRIGGER_DONE, 148, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(22031, 145) {
    auto node145 = GET_SKILL_NODE(145, PhaseNode_PlayEffect);
    if (node145 == nullptr) {
        node145 = new PhaseNode_PlayEffect(145, phase);
        node145->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node145->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node145->setEffectID(220317);
        node145->setChangeColor(false);
        node145->setType(PhaseNode_PlayEffect::PlayEffect_Type::WithTarget);
        node145->getVars().reserve(5);
        node145->getVars().setVariable<uint64_t>(0, 0U);
        node145->getVars().setVariable<std::string>(1, "");
        node145->getVars().setVariable<float>(2, .00f);
        node145->getVars().setVariable<float>(3, .00f);
        node145->getVars().setVariable<float>(4, .00f);
        node145->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(22031, 145, node145)
    }
    if (noInit == true) {
        return node145;
    }
    auto node140 = GET_SKILL_NODE(140, PhaseNode_OffsetCalculate);
    if (node140 != nullptr) node145->getVars().setVariable<float>(2, node140->getOutPosX());
    if (node140 != nullptr) node145->getVars().setVariable<float>(3, node140->getOutPosY());
    if (node140 != nullptr) node145->getVars().setVariable<float>(4, node140->getOutPosZ());
    if (node140 != nullptr) node145->setRotation(node140->getOutRotation());
    return node145;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(22031, 146) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_FALSE, 147, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_TRUE, 145, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(22031, 146) {
    auto node146 = GET_SKILL_NODE(146, PhaseNode_If);
    if (node146 == nullptr) {
        node146 = new PhaseNode_If(146, phase);
        node146->setCondition(false);
        CALL_REGISTER_SKILL_NODE(22031, 146, node146)
    }
    if (noInit == true) {
        return node146;
    }
    return node146;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(22031, 147) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_PlayEffect::TRIGGER_DONE, 148, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(22031, 147) {
    auto node147 = GET_SKILL_NODE(147, PhaseNode_PlayEffect);
    if (node147 == nullptr) {
        node147 = new PhaseNode_PlayEffect(147, phase);
        node147->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node147->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node147->setEffectID(220317);
        node147->setChangeColor(false);
        node147->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node147->getVars().reserve(3);
        node147->getVars().setVariable<float>(0, .00f);
        node147->getVars().setVariable<float>(1, .00f);
        node147->getVars().setVariable<float>(2, .00f);
        node147->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(22031, 147, node147)
    }
    if (noInit == true) {
        return node147;
    }
    auto node140 = GET_SKILL_NODE(140, PhaseNode_OffsetCalculate);
    if (node140 != nullptr) node147->getVars().setVariable<float>(0, node140->getOutPosX());
    if (node140 != nullptr) node147->getVars().setVariable<float>(1, node140->getOutPosY());
    if (node140 != nullptr) node147->getVars().setVariable<float>(2, node140->getOutPosZ());
    if (node140 != nullptr) node147->setRotation(node140->getOutRotation());
    return node147;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(22031, 148) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 151, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_LESS, 149, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_CompareFloat::TRIGGER_LESS, 151, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(22031, 148) {
    auto node148 = GET_SKILL_NODE(148, PhaseNode_CompareFloat);
    if (node148 == nullptr) {
        node148 = new PhaseNode_CompareFloat(148, phase);
        node148->setA(.00f);
        node148->setB(.80f);
        CALL_REGISTER_SKILL_NODE(22031, 148, node148)
    }
    if (noInit == true) {
        return node148;
    }
    return node148;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22031, 149) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StopEffect>(PhaseNode_Delay::TRIGGER_DONE, 150, PhaseNode_StopEffect::FUNC_DO, &PhaseNode_StopEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(22031, 149) {
    auto node149 = GET_SKILL_NODE(149, PhaseNode_Delay);
    if (node149 == nullptr) {
        node149 = new PhaseNode_Delay(149, phase);
        node149->setTime(.80f);
        CALL_REGISTER_SKILL_NODE(22031, 149, node149)
    }
    if (noInit == true) {
        return node149;
    }
    return node149;
}
//--------------------------------------------------------------------------------
// StopEffect
//
REGISTER_REGISTER_SKILL_NODE(22031, 150) {
}

REGISTER_CREATE_SKILL_NODE(22031, 150) {
    auto node150 = GET_SKILL_NODE(150, PhaseNode_StopEffect);
    if (node150 == nullptr) {
        node150 = new PhaseNode_StopEffect(150, phase);
        node150->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node150->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node150->setEffectID(220317);
        CALL_REGISTER_SKILL_NODE(22031, 150, node150)
    }
    if (noInit == true) {
        return node150;
    }
    return node150;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(22031, 151) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetRotation>(PhaseNode_GetLocation::TRIGGER_DONE, 152, PhaseNode_GetRotation::FUNC_DO, &PhaseNode_GetRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(22031, 151) {
    auto node151 = GET_SKILL_NODE(151, PhaseNode_GetLocation);
    if (node151 == nullptr) {
        node151 = new PhaseNode_GetLocation(151, phase);
        node151->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node151->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(22031, 151, node151)
    }
    if (noInit == true) {
        return node151;
    }
    return node151;
}
//--------------------------------------------------------------------------------
// GetRotation
//
REGISTER_REGISTER_SKILL_NODE(22031, 152) {
    pnode->resizeTrigger(PhaseNode_GetRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_OffsetCalculate>(PhaseNode_GetRotation::TRIGGER_DONE, 153, PhaseNode_OffsetCalculate::FUNC_DO, &PhaseNode_OffsetCalculate::Do);
}

REGISTER_CREATE_SKILL_NODE(22031, 152) {
    auto node152 = GET_SKILL_NODE(152, PhaseNode_GetRotation);
    if (node152 == nullptr) {
        node152 = new PhaseNode_GetRotation(152, phase);
        node152->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node152->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(22031, 152, node152)
    }
    if (noInit == true) {
        return node152;
    }
    return node152;
}
//--------------------------------------------------------------------------------
// OffsetCalculate
//
REGISTER_REGISTER_SKILL_NODE(22031, 153) {
    pnode->resizeTrigger(PhaseNode_OffsetCalculate::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnCollider>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 58, PhaseNode_SpawnCollider::FUNC_DO, &PhaseNode_SpawnCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(22031, 153) {
    auto node153 = GET_SKILL_NODE(153, PhaseNode_OffsetCalculate);
    if (node153 == nullptr) {
        node153 = new PhaseNode_OffsetCalculate(153, phase);
        node153->setPosZ(.00f);
        node153->setOffsetX(.00f);
        node153->setOffsetY(9.00f);
        node153->setOffsetZ(.00f);
        node153->setRotOffset(90.00f);
        CALL_REGISTER_SKILL_NODE(22031, 153, node153)
    }
    if (noInit == true) {
        return node153;
    }
    auto node151 = GET_SKILL_NODE(151, PhaseNode_GetLocation);
    auto node152 = GET_SKILL_NODE(152, PhaseNode_GetRotation);
    if (node151 != nullptr) node153->setPosX(node151->getX());
    if (node151 != nullptr) node153->setPosY(node151->getY());
    if (node152 != nullptr) node153->setRotation(node152->getAngle());
    return node153;
}
//--------------------------------------------------------------------------------
// UInt64sSize
//
REGISTER_REGISTER_SKILL_NODE(22031, 154) {
    pnode->resizeTrigger(PhaseNode_UInt64sSize::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_For>(PhaseNode_UInt64sSize::TRIGGER_DONE, 155, PhaseNode_For::FUNC_START, &PhaseNode_For::Start);
}

REGISTER_CREATE_SKILL_NODE(22031, 154) {
    auto node154 = GET_SKILL_NODE(154, PhaseNode_UInt64sSize);
    if (node154 == nullptr) {
        node154 = new PhaseNode_UInt64sSize(154, phase);
        CALL_REGISTER_SKILL_NODE(22031, 154, node154)
    }
    if (noInit == true) {
        return node154;
    }
    auto node121 = GET_SKILL_NODE(121, PhaseNode_LineCheckNewPene);
    if (node121 != nullptr) node154->setArr(node121->getOutput());
    return node154;
}
//--------------------------------------------------------------------------------
// For
//
REGISTER_REGISTER_SKILL_NODE(22031, 155) {
    pnode->resizeTrigger(PhaseNode_For::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetUInt64sValue>(PhaseNode_For::TRIGGER_DO, 165, PhaseNode_GetUInt64sValue::FUNC_DO, &PhaseNode_GetUInt64sValue::Do);
    pnode->regTrigger<PhaseNode_AddSkillBuff>(PhaseNode_For::TRIGGER_DONE, 130, PhaseNode_AddSkillBuff::FUNC_ADD, &PhaseNode_AddSkillBuff::Add);
}

REGISTER_CREATE_SKILL_NODE(22031, 155) {
    auto node155 = GET_SKILL_NODE(155, PhaseNode_For);
    if (node155 == nullptr) {
        node155 = new PhaseNode_For(155, phase);
        node155->setBegin(1);
        node155->setIncrease(1);
        CALL_REGISTER_SKILL_NODE(22031, 155, node155)
    }
    if (noInit == true) {
        return node155;
    }
    auto node154 = GET_SKILL_NODE(154, PhaseNode_UInt64sSize);
    if (node154 != nullptr) node155->setEnd(node154->getSize());
    return node155;
}
//--------------------------------------------------------------------------------
// GetUInt64sValue
//
REGISTER_REGISTER_SKILL_NODE(22031, 156) {
    pnode->resizeTrigger(PhaseNode_GetUInt64sValue::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetUInt64>(PhaseNode_GetUInt64sValue::TRIGGER_DONE, 158, PhaseNode_SetUInt64::FUNC_SET, &PhaseNode_SetUInt64::Set);
}

REGISTER_CREATE_SKILL_NODE(22031, 156) {
    auto node156 = GET_SKILL_NODE(156, PhaseNode_GetUInt64sValue);
    if (node156 == nullptr) {
        node156 = new PhaseNode_GetUInt64sValue(156, phase);
        node156->setIndex(0);
        CALL_REGISTER_SKILL_NODE(22031, 156, node156)
    }
    if (noInit == true) {
        return node156;
    }
    auto node121 = GET_SKILL_NODE(121, PhaseNode_LineCheckNewPene);
    if (node121 != nullptr) node156->setArr(node121->getOutput());
    return node156;
}
//--------------------------------------------------------------------------------
// SetUInt64
//
REGISTER_REGISTER_SKILL_NODE(22031, 158) {
    pnode->resizeTrigger(PhaseNode_SetUInt64::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_SetUInt64::TRIGGER_DONE, 159, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(22031, 158) {
    auto node158 = GET_SKILL_NODE(158, PhaseNode_SetUInt64);
    if (node158 == nullptr) {
        node158 = new PhaseNode_SetUInt64(158, phase);
        node158->setName("Target");
        CALL_REGISTER_SKILL_NODE(22031, 158, node158)
    }
    if (noInit == true) {
        return node158;
    }
    auto node156 = GET_SKILL_NODE(156, PhaseNode_GetUInt64sValue);
    if (node156 != nullptr) node158->setValue(node156->getValue());
    return node158;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(22031, 159) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_GetLocation::TRIGGER_DONE, 160, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(22031, 159) {
    auto node159 = GET_SKILL_NODE(159, PhaseNode_GetLocation);
    if (node159 == nullptr) {
        node159 = new PhaseNode_GetLocation(159, phase);
        node159->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node159->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(22031, 159, node159)
    }
    if (noInit == true) {
        return node159;
    }
    return node159;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(22031, 160) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Distance>(PhaseNode_GetLocation::TRIGGER_DONE, 162, PhaseNode_Distance::FUNC_DO, &PhaseNode_Distance::Do);
}

REGISTER_CREATE_SKILL_NODE(22031, 160) {
    auto node160 = GET_SKILL_NODE(160, PhaseNode_GetLocation);
    if (node160 == nullptr) {
        node160 = new PhaseNode_GetLocation(160, phase);
        node160->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        CALL_REGISTER_SKILL_NODE(22031, 160, node160)
    }
    if (noInit == true) {
        return node160;
    }
    auto variables = node160->getVariables();
    if (variables != nullptr) {
        node160->setTarget(variables->getVariable<uint64_t>(Variable_22031_Target));
    }
    return node160;
}
//--------------------------------------------------------------------------------
// Distance
//
REGISTER_REGISTER_SKILL_NODE(22031, 162) {
    pnode->resizeTrigger(PhaseNode_Distance::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetFloat>(PhaseNode_Distance::TRIGGER_DONE, 164, PhaseNode_SetFloat::FUNC_SET, &PhaseNode_SetFloat::Set);
}

REGISTER_CREATE_SKILL_NODE(22031, 162) {
    auto node162 = GET_SKILL_NODE(162, PhaseNode_Distance);
    if (node162 == nullptr) {
        node162 = new PhaseNode_Distance(162, phase);
        CALL_REGISTER_SKILL_NODE(22031, 162, node162)
    }
    if (noInit == true) {
        return node162;
    }
    auto node159 = GET_SKILL_NODE(159, PhaseNode_GetLocation);
    auto node160 = GET_SKILL_NODE(160, PhaseNode_GetLocation);
    if (node159 != nullptr) node162->setAX(node159->getX());
    if (node159 != nullptr) node162->setAY(node159->getY());
    if (node160 != nullptr) node162->setBX(node160->getX());
    if (node160 != nullptr) node162->setBY(node160->getY());
    return node162;
}
//--------------------------------------------------------------------------------
// SetFloat
//
REGISTER_REGISTER_SKILL_NODE(22031, 164) {
    pnode->resizeTrigger(PhaseNode_SetFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_UInt64sSize>(PhaseNode_SetFloat::TRIGGER_DONE, 154, PhaseNode_UInt64sSize::FUNC_DO, &PhaseNode_UInt64sSize::Do);
}

REGISTER_CREATE_SKILL_NODE(22031, 164) {
    auto node164 = GET_SKILL_NODE(164, PhaseNode_SetFloat);
    if (node164 == nullptr) {
        node164 = new PhaseNode_SetFloat(164, phase);
        node164->setName("Temp");
        CALL_REGISTER_SKILL_NODE(22031, 164, node164)
    }
    if (noInit == true) {
        return node164;
    }
    auto node162 = GET_SKILL_NODE(162, PhaseNode_Distance);
    if (node162 != nullptr) node164->setValue(node162->getResult());
    return node164;
}
//--------------------------------------------------------------------------------
// GetUInt64sValue
//
REGISTER_REGISTER_SKILL_NODE(22031, 165) {
    pnode->resizeTrigger(PhaseNode_GetUInt64sValue::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_GetUInt64sValue::TRIGGER_DONE, 166, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(22031, 165) {
    auto node165 = GET_SKILL_NODE(165, PhaseNode_GetUInt64sValue);
    if (node165 == nullptr) {
        node165 = new PhaseNode_GetUInt64sValue(165, phase);
        CALL_REGISTER_SKILL_NODE(22031, 165, node165)
    }
    if (noInit == true) {
        return node165;
    }
    auto node121 = GET_SKILL_NODE(121, PhaseNode_LineCheckNewPene);
    auto node155 = GET_SKILL_NODE(155, PhaseNode_For);
    if (node121 != nullptr) node165->setArr(node121->getOutput());
    if (node155 != nullptr) node165->setIndex(node155->getValue());
    return node165;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(22031, 166) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_GetLocation::TRIGGER_DONE, 167, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(22031, 166) {
    auto node166 = GET_SKILL_NODE(166, PhaseNode_GetLocation);
    if (node166 == nullptr) {
        node166 = new PhaseNode_GetLocation(166, phase);
        node166->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node166->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(22031, 166, node166)
    }
    if (noInit == true) {
        return node166;
    }
    return node166;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(22031, 167) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Distance>(PhaseNode_GetLocation::TRIGGER_DONE, 168, PhaseNode_Distance::FUNC_DO, &PhaseNode_Distance::Do);
}

REGISTER_CREATE_SKILL_NODE(22031, 167) {
    auto node167 = GET_SKILL_NODE(167, PhaseNode_GetLocation);
    if (node167 == nullptr) {
        node167 = new PhaseNode_GetLocation(167, phase);
        node167->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        CALL_REGISTER_SKILL_NODE(22031, 167, node167)
    }
    if (noInit == true) {
        return node167;
    }
    auto node165 = GET_SKILL_NODE(165, PhaseNode_GetUInt64sValue);
    if (node165 != nullptr) node167->setTarget(node165->getValue());
    return node167;
}
//--------------------------------------------------------------------------------
// Distance
//
REGISTER_REGISTER_SKILL_NODE(22031, 168) {
    pnode->resizeTrigger(PhaseNode_Distance::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_Distance::TRIGGER_DONE, 169, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(22031, 168) {
    auto node168 = GET_SKILL_NODE(168, PhaseNode_Distance);
    if (node168 == nullptr) {
        node168 = new PhaseNode_Distance(168, phase);
        CALL_REGISTER_SKILL_NODE(22031, 168, node168)
    }
    if (noInit == true) {
        return node168;
    }
    auto node166 = GET_SKILL_NODE(166, PhaseNode_GetLocation);
    auto node167 = GET_SKILL_NODE(167, PhaseNode_GetLocation);
    if (node166 != nullptr) node168->setAX(node166->getX());
    if (node166 != nullptr) node168->setAY(node166->getY());
    if (node167 != nullptr) node168->setBX(node167->getX());
    if (node167 != nullptr) node168->setBY(node167->getY());
    return node168;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(22031, 169) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetFloat>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 173, PhaseNode_SetFloat::FUNC_SET, &PhaseNode_SetFloat::Set);
    pnode->regTrigger<PhaseNode_SetFloat>(PhaseNode_CompareFloat::TRIGGER_GREATER, 173, PhaseNode_SetFloat::FUNC_SET, &PhaseNode_SetFloat::Set);
    pnode->regTrigger<PhaseNode_ForContinue>(PhaseNode_CompareFloat::TRIGGER_LESS, 171, PhaseNode_ForContinue::FUNC_DO, &PhaseNode_ForContinue::Do);
}

REGISTER_CREATE_SKILL_NODE(22031, 169) {
    auto node169 = GET_SKILL_NODE(169, PhaseNode_CompareFloat);
    if (node169 == nullptr) {
        node169 = new PhaseNode_CompareFloat(169, phase);
        CALL_REGISTER_SKILL_NODE(22031, 169, node169)
    }
    if (noInit == true) {
        return node169;
    }
    auto variables = node169->getVariables();
    if (variables != nullptr) {
        node169->setA(variables->getVariable<float>(Variable_22031_Temp));
    }
    auto node168 = GET_SKILL_NODE(168, PhaseNode_Distance);
    if (node168 != nullptr) node169->setB(node168->getResult());
    return node169;
}
//--------------------------------------------------------------------------------
// ForContinue
//
REGISTER_REGISTER_SKILL_NODE(22031, 171) {
}

REGISTER_CREATE_SKILL_NODE(22031, 171) {
    auto node171 = GET_SKILL_NODE(171, PhaseNode_ForContinue);
    if (node171 == nullptr) {
        node171 = new PhaseNode_ForContinue(171, phase);
        CALL_REGISTER_SKILL_NODE(22031, 171, node171)
    }
    if (noInit == true) {
        return node171;
    }
    auto node155 = GET_SKILL_NODE(155, PhaseNode_For);
    if (node155 != nullptr) node171->setFID(node155->getFID());
    return node171;
}
//--------------------------------------------------------------------------------
// SetFloat
//
REGISTER_REGISTER_SKILL_NODE(22031, 173) {
    pnode->resizeTrigger(PhaseNode_SetFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetUInt64>(PhaseNode_SetFloat::TRIGGER_DONE, 174, PhaseNode_SetUInt64::FUNC_SET, &PhaseNode_SetUInt64::Set);
}

REGISTER_CREATE_SKILL_NODE(22031, 173) {
    auto node173 = GET_SKILL_NODE(173, PhaseNode_SetFloat);
    if (node173 == nullptr) {
        node173 = new PhaseNode_SetFloat(173, phase);
        node173->setName("Temp");
        CALL_REGISTER_SKILL_NODE(22031, 173, node173)
    }
    if (noInit == true) {
        return node173;
    }
    auto node168 = GET_SKILL_NODE(168, PhaseNode_Distance);
    if (node168 != nullptr) node173->setValue(node168->getResult());
    return node173;
}
//--------------------------------------------------------------------------------
// SetUInt64
//
REGISTER_REGISTER_SKILL_NODE(22031, 174) {
    pnode->resizeTrigger(PhaseNode_SetUInt64::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ForContinue>(PhaseNode_SetUInt64::TRIGGER_DONE, 171, PhaseNode_ForContinue::FUNC_DO, &PhaseNode_ForContinue::Do);
}

REGISTER_CREATE_SKILL_NODE(22031, 174) {
    auto node174 = GET_SKILL_NODE(174, PhaseNode_SetUInt64);
    if (node174 == nullptr) {
        node174 = new PhaseNode_SetUInt64(174, phase);
        node174->setName("Target");
        CALL_REGISTER_SKILL_NODE(22031, 174, node174)
    }
    if (noInit == true) {
        return node174;
    }
    auto node165 = GET_SKILL_NODE(165, PhaseNode_GetUInt64sValue);
    if (node165 != nullptr) node174->setValue(node165->getValue());
    return node174;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(22031, 175) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_PlayEffect::TRIGGER_DONE, 178, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(22031, 175) {
    auto node175 = GET_SKILL_NODE(175, PhaseNode_PlayEffect);
    if (node175 == nullptr) {
        node175 = new PhaseNode_PlayEffect(175, phase);
        node175->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node175->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node175->setEffectID(220312);
        node175->setChangeColor(false);
        node175->setType(PhaseNode_PlayEffect::PlayEffect_Type::WithTarget);
        node175->getVars().reserve(5);
        node175->getVars().setVariable<uint64_t>(0, 0U);
        node175->getVars().setVariable<std::string>(1, "");
        node175->getVars().setVariable<float>(2, .00f);
        node175->getVars().setVariable<float>(3, .00f);
        node175->getVars().setVariable<float>(4, .00f);
        node175->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(22031, 175, node175)
    }
    if (noInit == true) {
        return node175;
    }
    auto node140 = GET_SKILL_NODE(140, PhaseNode_OffsetCalculate);
    if (node140 != nullptr) node175->getVars().setVariable<float>(2, node140->getOutPosX());
    if (node140 != nullptr) node175->getVars().setVariable<float>(3, node140->getOutPosY());
    if (node140 != nullptr) node175->getVars().setVariable<float>(4, node140->getOutPosZ());
    if (node140 != nullptr) node175->setRotation(node140->getOutRotation());
    return node175;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(22031, 176) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_FALSE, 177, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_TRUE, 175, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(22031, 176) {
    auto node176 = GET_SKILL_NODE(176, PhaseNode_If);
    if (node176 == nullptr) {
        node176 = new PhaseNode_If(176, phase);
        node176->setCondition(false);
        CALL_REGISTER_SKILL_NODE(22031, 176, node176)
    }
    if (noInit == true) {
        return node176;
    }
    return node176;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(22031, 177) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_PlayEffect::TRIGGER_DONE, 178, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(22031, 177) {
    auto node177 = GET_SKILL_NODE(177, PhaseNode_PlayEffect);
    if (node177 == nullptr) {
        node177 = new PhaseNode_PlayEffect(177, phase);
        node177->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node177->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node177->setEffectID(220312);
        node177->setChangeColor(false);
        node177->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node177->getVars().reserve(3);
        node177->getVars().setVariable<float>(0, .00f);
        node177->getVars().setVariable<float>(1, .00f);
        node177->getVars().setVariable<float>(2, .00f);
        node177->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(22031, 177, node177)
    }
    if (noInit == true) {
        return node177;
    }
    auto node140 = GET_SKILL_NODE(140, PhaseNode_OffsetCalculate);
    if (node140 != nullptr) node177->getVars().setVariable<float>(0, node140->getOutPosX());
    if (node140 != nullptr) node177->getVars().setVariable<float>(1, node140->getOutPosY());
    if (node140 != nullptr) node177->getVars().setVariable<float>(2, node140->getOutPosZ());
    if (node140 != nullptr) node177->setRotation(node140->getOutRotation());
    return node177;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(22031, 178) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 31, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_LESS, 179, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_LESS, 31, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(22031, 178) {
    auto node178 = GET_SKILL_NODE(178, PhaseNode_CompareFloat);
    if (node178 == nullptr) {
        node178 = new PhaseNode_CompareFloat(178, phase);
        node178->setA(.00f);
        node178->setB(.00f);
        CALL_REGISTER_SKILL_NODE(22031, 178, node178)
    }
    if (noInit == true) {
        return node178;
    }
    return node178;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22031, 179) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StopEffect>(PhaseNode_Delay::TRIGGER_DONE, 180, PhaseNode_StopEffect::FUNC_DO, &PhaseNode_StopEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(22031, 179) {
    auto node179 = GET_SKILL_NODE(179, PhaseNode_Delay);
    if (node179 == nullptr) {
        node179 = new PhaseNode_Delay(179, phase);
        node179->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(22031, 179, node179)
    }
    if (noInit == true) {
        return node179;
    }
    return node179;
}
//--------------------------------------------------------------------------------
// StopEffect
//
REGISTER_REGISTER_SKILL_NODE(22031, 180) {
}

REGISTER_CREATE_SKILL_NODE(22031, 180) {
    auto node180 = GET_SKILL_NODE(180, PhaseNode_StopEffect);
    if (node180 == nullptr) {
        node180 = new PhaseNode_StopEffect(180, phase);
        node180->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node180->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node180->setEffectID(220312);
        CALL_REGISTER_SKILL_NODE(22031, 180, node180)
    }
    if (noInit == true) {
        return node180;
    }
    return node180;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22031, 181) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_Delay::TRIGGER_DONE, 183, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(22031, 181) {
    auto node181 = GET_SKILL_NODE(181, PhaseNode_Delay);
    if (node181 == nullptr) {
        node181 = new PhaseNode_Delay(181, phase);
        node181->setTime(.30f);
        CALL_REGISTER_SKILL_NODE(22031, 181, node181)
    }
    if (noInit == true) {
        return node181;
    }
    return node181;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(22031, 182) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 37, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(22031, 182) {
    auto node182 = GET_SKILL_NODE(182, PhaseNode_SkillEndNotify);
    if (node182 == nullptr) {
        node182 = new PhaseNode_SkillEndNotify(182, phase);
        node182->setReturnType(false);
        CALL_REGISTER_SKILL_NODE(22031, 182, node182)
    }
    if (noInit == true) {
        return node182;
    }
    return node182;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(22031, 183) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_FALSE, 184, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_TRUE, 182, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
}

REGISTER_CREATE_SKILL_NODE(22031, 183) {
    auto node183 = GET_SKILL_NODE(183, PhaseNode_If);
    if (node183 == nullptr) {
        node183 = new PhaseNode_If(183, phase);
        node183->setCondition(false);
        CALL_REGISTER_SKILL_NODE(22031, 183, node183)
    }
    if (noInit == true) {
        return node183;
    }
    return node183;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(22031, 184) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 37, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(22031, 184) {
    auto node184 = GET_SKILL_NODE(184, PhaseNode_SkillEndNotify);
    if (node184 == nullptr) {
        node184 = new PhaseNode_SkillEndNotify(184, phase);
        node184->setReturnType(true);
        CALL_REGISTER_SKILL_NODE(22031, 184, node184)
    }
    if (noInit == true) {
        return node184;
    }
    return node184;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(22031, 185) {
}

REGISTER_CREATE_SKILL_NODE(22031, 185) {
    auto node185 = GET_SKILL_NODE(185, PhaseNode_RaiseEvent);
    if (node185 == nullptr) {
        node185 = new PhaseNode_RaiseEvent(185, phase);
        node185->setEvent("MonsterInterrupt");
        node185->setTarget(0U);
        node185->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node185->setTypeParams(0, 0);
        node185->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(22031, 185, node185)
    }
    if (noInit == true) {
        return node185;
    }
    return node185;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(22031, 186) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_Detect::TRIGGER_ON, 189, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(22031, 186) {
    auto node186 = GET_SKILL_NODE(186, PhaseNode_Detect);
    if (node186 == nullptr) {
        node186 = new PhaseNode_Detect(186, phase);
        node186->setSelf(0U);
        node186->setEvent("MonsterInterrupt");
        node186->setType(PhaseNode_Detect::Detect_Type::Interrupt_Skill);
        node186->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(22031, 186, node186)
    }
    if (noInit == true) {
        return node186;
    }
    return node186;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(22031, 187) {
}

REGISTER_CREATE_SKILL_NODE(22031, 187) {
    auto node187 = GET_SKILL_NODE(187, PhaseNode_EndPhase);
    if (node187 == nullptr) {
        node187 = new PhaseNode_EndPhase(187, phase);
        node187->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node187->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(22031, 187, node187)
    }
    if (noInit == true) {
        return node187;
    }
    return node187;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22031, 189) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_Delay::TRIGGER_DONE, 191, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(22031, 189) {
    auto node189 = GET_SKILL_NODE(189, PhaseNode_Delay);
    if (node189 == nullptr) {
        node189 = new PhaseNode_Delay(189, phase);
        node189->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(22031, 189, node189)
    }
    if (noInit == true) {
        return node189;
    }
    return node189;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(22031, 190) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 187, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(22031, 190) {
    auto node190 = GET_SKILL_NODE(190, PhaseNode_SkillEndNotify);
    if (node190 == nullptr) {
        node190 = new PhaseNode_SkillEndNotify(190, phase);
        node190->setReturnType(false);
        CALL_REGISTER_SKILL_NODE(22031, 190, node190)
    }
    if (noInit == true) {
        return node190;
    }
    return node190;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(22031, 191) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_FALSE, 192, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_TRUE, 190, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
}

REGISTER_CREATE_SKILL_NODE(22031, 191) {
    auto node191 = GET_SKILL_NODE(191, PhaseNode_If);
    if (node191 == nullptr) {
        node191 = new PhaseNode_If(191, phase);
        node191->setCondition(false);
        CALL_REGISTER_SKILL_NODE(22031, 191, node191)
    }
    if (noInit == true) {
        return node191;
    }
    return node191;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(22031, 192) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 187, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(22031, 192) {
    auto node192 = GET_SKILL_NODE(192, PhaseNode_SkillEndNotify);
    if (node192 == nullptr) {
        node192 = new PhaseNode_SkillEndNotify(192, phase);
        node192->setReturnType(true);
        CALL_REGISTER_SKILL_NODE(22031, 192, node192)
    }
    if (noInit == true) {
        return node192;
    }
    return node192;
}

//--------------------------------------------------------------------------------
// SkillCreator_22031
//
class SkillCreator_22031 : public SkillCreator {
public:
    SkillCreator_22031() {}
    virtual ~SkillCreator_22031() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_22031

//--------------------------------------------------------------------------------
// SkillPhase_22031
//
class SkillPhase_22031 : public SkillPhase {
public:
    SkillPhase_22031(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_22031() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(22031, 2) // StartPhase
        CASE_CREATE_SKILL_NODE(22031, 4) // TriggerUpdate
        CASE_CREATE_SKILL_NODE(22031, 20) // PlayAnimation
        CASE_CREATE_SKILL_NODE(22031, 22) // Delay
        CASE_CREATE_SKILL_NODE(22031, 24) // SpawnProjectile
        CASE_CREATE_SKILL_NODE(22031, 31) // Delay
        CASE_CREATE_SKILL_NODE(22031, 33) // PlayAnimation
        CASE_CREATE_SKILL_NODE(22031, 37) // EndPhase
        CASE_CREATE_SKILL_NODE(22031, 46) // Detect
        CASE_CREATE_SKILL_NODE(22031, 48) // EndPhase
        CASE_CREATE_SKILL_NODE(22031, 52) // PlayAnimation
        CASE_CREATE_SKILL_NODE(22031, 58) // SpawnCollider
        CASE_CREATE_SKILL_NODE(22031, 62) // TriggerCheck
        CASE_CREATE_SKILL_NODE(22031, 116) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(22031, 118) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(22031, 121) // LineCheckNewPene
        CASE_CREATE_SKILL_NODE(22031, 130) // AddSkillBuff
        CASE_CREATE_SKILL_NODE(22031, 132) // PlaySound
        CASE_CREATE_SKILL_NODE(22031, 137) // Disable
        CASE_CREATE_SKILL_NODE(22031, 138) // GetLocation
        CASE_CREATE_SKILL_NODE(22031, 139) // GetRotation
        CASE_CREATE_SKILL_NODE(22031, 140) // OffsetCalculate
        CASE_CREATE_SKILL_NODE(22031, 141) // ResetCD
        CASE_CREATE_SKILL_NODE(22031, 142) // PlayAnimation
        CASE_CREATE_SKILL_NODE(22031, 143) // PlaySound
        CASE_CREATE_SKILL_NODE(22031, 144) // Delay
        CASE_CREATE_SKILL_NODE(22031, 145) // PlayEffect
        CASE_CREATE_SKILL_NODE(22031, 146) // If
        CASE_CREATE_SKILL_NODE(22031, 147) // PlayEffect
        CASE_CREATE_SKILL_NODE(22031, 148) // CompareFloat
        CASE_CREATE_SKILL_NODE(22031, 149) // Delay
        CASE_CREATE_SKILL_NODE(22031, 150) // StopEffect
        CASE_CREATE_SKILL_NODE(22031, 151) // GetLocation
        CASE_CREATE_SKILL_NODE(22031, 152) // GetRotation
        CASE_CREATE_SKILL_NODE(22031, 153) // OffsetCalculate
        CASE_CREATE_SKILL_NODE(22031, 154) // UInt64sSize
        CASE_CREATE_SKILL_NODE(22031, 155) // For
        CASE_CREATE_SKILL_NODE(22031, 156) // GetUInt64sValue
        CASE_CREATE_SKILL_NODE(22031, 158) // SetUInt64
        CASE_CREATE_SKILL_NODE(22031, 159) // GetLocation
        CASE_CREATE_SKILL_NODE(22031, 160) // GetLocation
        CASE_CREATE_SKILL_NODE(22031, 162) // Distance
        CASE_CREATE_SKILL_NODE(22031, 164) // SetFloat
        CASE_CREATE_SKILL_NODE(22031, 165) // GetUInt64sValue
        CASE_CREATE_SKILL_NODE(22031, 166) // GetLocation
        CASE_CREATE_SKILL_NODE(22031, 167) // GetLocation
        CASE_CREATE_SKILL_NODE(22031, 168) // Distance
        CASE_CREATE_SKILL_NODE(22031, 169) // CompareFloat
        CASE_CREATE_SKILL_NODE(22031, 171) // ForContinue
        CASE_CREATE_SKILL_NODE(22031, 173) // SetFloat
        CASE_CREATE_SKILL_NODE(22031, 174) // SetUInt64
        CASE_CREATE_SKILL_NODE(22031, 175) // PlayEffect
        CASE_CREATE_SKILL_NODE(22031, 176) // If
        CASE_CREATE_SKILL_NODE(22031, 177) // PlayEffect
        CASE_CREATE_SKILL_NODE(22031, 178) // CompareFloat
        CASE_CREATE_SKILL_NODE(22031, 179) // Delay
        CASE_CREATE_SKILL_NODE(22031, 180) // StopEffect
        CASE_CREATE_SKILL_NODE(22031, 181) // Delay
        CASE_CREATE_SKILL_NODE(22031, 182) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(22031, 183) // If
        CASE_CREATE_SKILL_NODE(22031, 184) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(22031, 185) // RaiseEvent
        CASE_CREATE_SKILL_NODE(22031, 186) // Detect
        CASE_CREATE_SKILL_NODE(22031, 187) // EndPhase
        CASE_CREATE_SKILL_NODE(22031, 189) // Delay
        CASE_CREATE_SKILL_NODE(22031, 190) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(22031, 191) // If
        CASE_CREATE_SKILL_NODE(22031, 192) // SkillEndNotify
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_22031

SkillLogic* SkillCreator_22031::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //设置变量
    Variable_22031_Target = logic->getVariables().setVariable<uint64_t>("Target", 0U);
    Variable_22031_Temp = logic->getVariables().setVariable<float>("Temp");
    //创建阶段phase
    auto phase = new SkillPhase_22031(1, logic, 3);
    //设置phase执行器
    phase->setRunPhaseNode(1, 2);
    phase->setRunPhaseNode(2, 4);
    phase->setDetectPhaseNode(3, 46);
    phase->setDetectPhaseNode(3, 186);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_22031::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
