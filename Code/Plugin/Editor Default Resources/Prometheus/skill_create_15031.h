#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

#include "skill_psnode_attachto.h"
#include "skill_psnode_comparefloat.h"
#include "skill_psnode_delay.h"
#include "skill_psnode_endphase.h"
#include "skill_psnode_getbbparamuint64.h"
#include "skill_psnode_getlinerotation.h"
#include "skill_psnode_getlocation.h"
#include "skill_psnode_getrotation.h"
#include "skill_psnode_if.h"
#include "skill_psnode_offsetcalculate.h"
#include "skill_psnode_playanimation.h"
#include "skill_psnode_playeffect.h"
#include "skill_psnode_playsound.h"
#include "skill_psnode_resetcd.h"
#include "skill_psnode_skillendnotify.h"
#include "skill_psnode_spawncollider.h"
#include "skill_psnode_spawnprojectile.h"
#include "skill_psnode_startphase.h"
#include "skill_psnode_stopeffect.h"
#include "skill_psnode_triggerupdate.h"

namespace pvp {

//变量声明
//--------------------------------------------------------------------------------
// StartPhase
//
REGISTER_REGISTER_SKILL_NODE(15031, 1) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_StartPhase::TRIGGER_START, 6, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(15031, 1) {
    auto node1 = GET_SKILL_NODE(1, PhaseNode_StartPhase);
    if (node1 == nullptr) {
        node1 = new PhaseNode_StartPhase(1, phase);
        CALL_REGISTER_SKILL_NODE(15031, 1, node1)
    }
    if (noInit == true) {
        return node1;
    }
    return node1;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(15031, 2) {
}

REGISTER_CREATE_SKILL_NODE(15031, 2) {
    auto node2 = GET_SKILL_NODE(2, PhaseNode_EndPhase);
    if (node2 == nullptr) {
        node2 = new PhaseNode_EndPhase(2, phase);
        node2->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node2->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(15031, 2, node2)
    }
    if (noInit == true) {
        return node2;
    }
    return node2;
}
//--------------------------------------------------------------------------------
// TriggerUpdate
//
REGISTER_REGISTER_SKILL_NODE(15031, 4) {
}

REGISTER_CREATE_SKILL_NODE(15031, 4) {
    auto node4 = GET_SKILL_NODE(4, PhaseNode_TriggerUpdate);
    if (node4 == nullptr) {
        node4 = new PhaseNode_TriggerUpdate(4, phase);
        CALL_REGISTER_SKILL_NODE(15031, 4, node4)
    }
    if (noInit == true) {
        return node4;
    }
    return node4;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(15031, 6) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_ResetCD::TRIGGER_DONE, 8, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(15031, 6) {
    auto node6 = GET_SKILL_NODE(6, PhaseNode_ResetCD);
    if (node6 == nullptr) {
        node6 = new PhaseNode_ResetCD(6, phase);
        node6->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node6->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node6->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(15031, 6, node6)
    }
    if (noInit == true) {
        return node6;
    }
    return node6;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(15031, 8) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetRotation>(PhaseNode_GetLocation::TRIGGER_DONE, 10, PhaseNode_GetRotation::FUNC_DO, &PhaseNode_GetRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(15031, 8) {
    auto node8 = GET_SKILL_NODE(8, PhaseNode_GetLocation);
    if (node8 == nullptr) {
        node8 = new PhaseNode_GetLocation(8, phase);
        node8->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node8->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(15031, 8, node8)
    }
    if (noInit == true) {
        return node8;
    }
    return node8;
}
//--------------------------------------------------------------------------------
// GetRotation
//
REGISTER_REGISTER_SKILL_NODE(15031, 10) {
    pnode->resizeTrigger(PhaseNode_GetRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetBBParamUInt64>(PhaseNode_GetRotation::TRIGGER_DONE, 28, PhaseNode_GetBBParamUInt64::FUNC_DO, &PhaseNode_GetBBParamUInt64::Do);
}

REGISTER_CREATE_SKILL_NODE(15031, 10) {
    auto node10 = GET_SKILL_NODE(10, PhaseNode_GetRotation);
    if (node10 == nullptr) {
        node10 = new PhaseNode_GetRotation(10, phase);
        node10->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node10->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(15031, 10, node10)
    }
    if (noInit == true) {
        return node10;
    }
    return node10;
}
//--------------------------------------------------------------------------------
// OffsetCalculate
//
REGISTER_REGISTER_SKILL_NODE(15031, 12) {
    pnode->resizeTrigger(PhaseNode_OffsetCalculate::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 14, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(15031, 12) {
    auto node12 = GET_SKILL_NODE(12, PhaseNode_OffsetCalculate);
    if (node12 == nullptr) {
        node12 = new PhaseNode_OffsetCalculate(12, phase);
        node12->setPosZ(.00f);
        node12->setOffsetX(.00f);
        node12->setOffsetY(1.10f);
        node12->setOffsetZ(1.74f);
        node12->setRotOffset(.00f);
        CALL_REGISTER_SKILL_NODE(15031, 12, node12)
    }
    if (noInit == true) {
        return node12;
    }
    auto node8 = GET_SKILL_NODE(8, PhaseNode_GetLocation);
    auto node32 = GET_SKILL_NODE(32, PhaseNode_GetLineRotation);
    if (node8 != nullptr) node12->setPosX(node8->getX());
    if (node8 != nullptr) node12->setPosY(node8->getY());
    if (node32 != nullptr) node12->setRotation(node32->getRotation());
    return node12;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(15031, 14) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlayAnimation::TRIGGER_DONE, 16, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_PlayAnimation::TRIGGER_DONE, 38, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(15031, 14) {
    auto node14 = GET_SKILL_NODE(14, PhaseNode_PlayAnimation);
    if (node14 == nullptr) {
        node14 = new PhaseNode_PlayAnimation(14, phase);
        node14->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node14->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node14->setTarget(0U);
        node14->setAnimation("Skill1S1");
        node14->setParameter("");
        node14->setValue(false);
        CALL_REGISTER_SKILL_NODE(15031, 14, node14)
    }
    if (noInit == true) {
        return node14;
    }
    return node14;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(15031, 16) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_Delay::TRIGGER_DONE, 25, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
}

REGISTER_CREATE_SKILL_NODE(15031, 16) {
    auto node16 = GET_SKILL_NODE(16, PhaseNode_Delay);
    if (node16 == nullptr) {
        node16 = new PhaseNode_Delay(16, phase);
        node16->setTime(.20f);
        CALL_REGISTER_SKILL_NODE(15031, 16, node16)
    }
    if (noInit == true) {
        return node16;
    }
    return node16;
}
//--------------------------------------------------------------------------------
// SpawnProjectile
//
REGISTER_REGISTER_SKILL_NODE(15031, 20) {
}

REGISTER_CREATE_SKILL_NODE(15031, 20) {
    auto node20 = GET_SKILL_NODE(20, PhaseNode_SpawnProjectile);
    if (node20 == nullptr) {
        node20 = new PhaseNode_SpawnProjectile(20, phase);
        node20->setDataId(51503);
        node20->setPosZ(.00f);
        node20->setEndPosX(.00f);
        node20->setEndPosY(.00f);
        node20->setMaxCount(0);
        CALL_REGISTER_SKILL_NODE(15031, 20, node20)
    }
    if (noInit == true) {
        return node20;
    }
    auto node8 = GET_SKILL_NODE(8, PhaseNode_GetLocation);
    auto node12 = GET_SKILL_NODE(12, PhaseNode_OffsetCalculate);
    if (node8 != nullptr) node20->setPosX(node8->getX());
    if (node8 != nullptr) node20->setPosY(node8->getY());
    if (node12 != nullptr) node20->setEndPosZ(node12->getOutPosZ());
    if (node12 != nullptr) node20->setRotation(node12->getOutRotation());
    return node20;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(15031, 22) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnProjectile>(PhaseNode_PlaySound::TRIGGER_DONE, 20, PhaseNode_SpawnProjectile::FUNC_DO, &PhaseNode_SpawnProjectile::Do);
}

REGISTER_CREATE_SKILL_NODE(15031, 22) {
    auto node22 = GET_SKILL_NODE(22, PhaseNode_PlaySound);
    if (node22 == nullptr) {
        node22 = new PhaseNode_PlaySound(22, phase);
        node22->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node22->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node22->setSoundID("SE_Hero103_Skill_A_P2");
        node22->setTarget(0U);
        node22->setUsePos(false);
        node22->setPosX(.00f);
        node22->setPosY(.00f);
        node22->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(15031, 22, node22)
    }
    if (noInit == true) {
        return node22;
    }
    return node22;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(15031, 25) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 2, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(15031, 25) {
    auto node25 = GET_SKILL_NODE(25, PhaseNode_SkillEndNotify);
    if (node25 == nullptr) {
        node25 = new PhaseNode_SkillEndNotify(25, phase);
        node25->setReturnType(true);
        CALL_REGISTER_SKILL_NODE(15031, 25, node25)
    }
    if (noInit == true) {
        return node25;
    }
    return node25;
}
//--------------------------------------------------------------------------------
// GetBBParamUInt64
//
REGISTER_REGISTER_SKILL_NODE(15031, 28) {
    pnode->resizeTrigger(PhaseNode_GetBBParamUInt64::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_GetBBParamUInt64::TRIGGER_DONE, 30, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(15031, 28) {
    auto node28 = GET_SKILL_NODE(28, PhaseNode_GetBBParamUInt64);
    if (node28 == nullptr) {
        node28 = new PhaseNode_GetBBParamUInt64(28, phase);
        node28->setBBName("AtkTarget");
        CALL_REGISTER_SKILL_NODE(15031, 28, node28)
    }
    if (noInit == true) {
        return node28;
    }
    return node28;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(15031, 30) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLineRotation>(PhaseNode_GetLocation::TRIGGER_DONE, 32, PhaseNode_GetLineRotation::FUNC_DO, &PhaseNode_GetLineRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(15031, 30) {
    auto node30 = GET_SKILL_NODE(30, PhaseNode_GetLocation);
    if (node30 == nullptr) {
        node30 = new PhaseNode_GetLocation(30, phase);
        node30->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        CALL_REGISTER_SKILL_NODE(15031, 30, node30)
    }
    if (noInit == true) {
        return node30;
    }
    auto node28 = GET_SKILL_NODE(28, PhaseNode_GetBBParamUInt64);
    if (node28 != nullptr) node30->setTarget(node28->getValue());
    return node30;
}
//--------------------------------------------------------------------------------
// GetLineRotation
//
REGISTER_REGISTER_SKILL_NODE(15031, 32) {
    pnode->resizeTrigger(PhaseNode_GetLineRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnCollider>(PhaseNode_GetLineRotation::TRIGGER_DONE, 34, PhaseNode_SpawnCollider::FUNC_DO, &PhaseNode_SpawnCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(15031, 32) {
    auto node32 = GET_SKILL_NODE(32, PhaseNode_GetLineRotation);
    if (node32 == nullptr) {
        node32 = new PhaseNode_GetLineRotation(32, phase);
        CALL_REGISTER_SKILL_NODE(15031, 32, node32)
    }
    if (noInit == true) {
        return node32;
    }
    auto node8 = GET_SKILL_NODE(8, PhaseNode_GetLocation);
    auto node30 = GET_SKILL_NODE(30, PhaseNode_GetLocation);
    if (node8 != nullptr) node32->setStartX(node8->getX());
    if (node8 != nullptr) node32->setStartY(node8->getY());
    if (node30 != nullptr) node32->setEndX(node30->getX());
    if (node30 != nullptr) node32->setEndY(node30->getY());
    return node32;
}
//--------------------------------------------------------------------------------
// SpawnCollider
//
REGISTER_REGISTER_SKILL_NODE(15031, 34) {
    pnode->resizeTrigger(PhaseNode_SpawnCollider::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AttachTo>(PhaseNode_SpawnCollider::TRIGGER_DONE, 36, PhaseNode_AttachTo::FUNC_DO, &PhaseNode_AttachTo::Do);
}

REGISTER_CREATE_SKILL_NODE(15031, 34) {
    auto node34 = GET_SKILL_NODE(34, PhaseNode_SpawnCollider);
    if (node34 == nullptr) {
        node34 = new PhaseNode_SpawnCollider(34, phase);
        node34->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node34->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node34->setMesh("");
        node34->setMeshScale(.00f);
        node34->setEffectID(0);
        node34->setEffectScale(.00f);
        node34->setType(PhaseNode_SpawnCollider::SpawnCollider_Type::Circle);
        node34->setTypeParams(0, .00f);
        node34->setTime(.20f);
        node34->setPosZ(.00f);
        node34->setreentry(false);
        node34->setCheckPeneSound(false);
        CALL_REGISTER_SKILL_NODE(15031, 34, node34)
    }
    if (noInit == true) {
        return node34;
    }
    auto node8 = GET_SKILL_NODE(8, PhaseNode_GetLocation);
    auto node32 = GET_SKILL_NODE(32, PhaseNode_GetLineRotation);
    if (node8 != nullptr) node34->setPosX(node8->getX());
    if (node8 != nullptr) node34->setPosY(node8->getY());
    if (node32 != nullptr) node34->setRotation(node32->getRotation());
    return node34;
}
//--------------------------------------------------------------------------------
// AttachTo
//
REGISTER_REGISTER_SKILL_NODE(15031, 36) {
    pnode->resizeTrigger(PhaseNode_AttachTo::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_OffsetCalculate>(PhaseNode_AttachTo::TRIGGER_DONE, 12, PhaseNode_OffsetCalculate::FUNC_DO, &PhaseNode_OffsetCalculate::Do);
}

REGISTER_CREATE_SKILL_NODE(15031, 36) {
    auto node36 = GET_SKILL_NODE(36, PhaseNode_AttachTo);
    if (node36 == nullptr) {
        node36 = new PhaseNode_AttachTo(36, phase);
        node36->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node36->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node36->setChild(0U);
        node36->setChangeRotation(true);
        node36->setreentry(false);
        CALL_REGISTER_SKILL_NODE(15031, 36, node36)
    }
    if (noInit == true) {
        return node36;
    }
    auto node34 = GET_SKILL_NODE(34, PhaseNode_SpawnCollider);
    if (node34 != nullptr) node36->setParent(node34->getColliderID());
    return node36;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(15031, 37) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_PlayEffect::TRIGGER_DONE, 40, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(15031, 37) {
    auto node37 = GET_SKILL_NODE(37, PhaseNode_PlayEffect);
    if (node37 == nullptr) {
        node37 = new PhaseNode_PlayEffect(37, phase);
        node37->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node37->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node37->setEffectID(101043);
        node37->setChangeColor(true);
        node37->setType(PhaseNode_PlayEffect::PlayEffect_Type::WithTarget);
        node37->getVars().reserve(5);
        node37->getVars().setVariable<uint64_t>(0, 0U);
        node37->getVars().setVariable<std::string>(1, "");
        node37->getVars().setVariable<float>(2, .00f);
        node37->getVars().setVariable<float>(3, .00f);
        node37->getVars().setVariable<float>(4, .00f);
        node37->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(15031, 37, node37)
    }
    if (noInit == true) {
        return node37;
    }
    auto node8 = GET_SKILL_NODE(8, PhaseNode_GetLocation);
    auto node10 = GET_SKILL_NODE(10, PhaseNode_GetRotation);
    if (node8 != nullptr) node37->getVars().setVariable<float>(2, node8->getX());
    if (node8 != nullptr) node37->getVars().setVariable<float>(3, node8->getY());
    if (node10 != nullptr) node37->setRotation(node10->getAngle());
    return node37;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(15031, 38) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_FALSE, 39, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_TRUE, 37, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(15031, 38) {
    auto node38 = GET_SKILL_NODE(38, PhaseNode_If);
    if (node38 == nullptr) {
        node38 = new PhaseNode_If(38, phase);
        node38->setCondition(false);
        CALL_REGISTER_SKILL_NODE(15031, 38, node38)
    }
    if (noInit == true) {
        return node38;
    }
    return node38;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(15031, 39) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_PlayEffect::TRIGGER_DONE, 40, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(15031, 39) {
    auto node39 = GET_SKILL_NODE(39, PhaseNode_PlayEffect);
    if (node39 == nullptr) {
        node39 = new PhaseNode_PlayEffect(39, phase);
        node39->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node39->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node39->setEffectID(101043);
        node39->setChangeColor(true);
        node39->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node39->getVars().reserve(3);
        node39->getVars().setVariable<float>(0, .00f);
        node39->getVars().setVariable<float>(1, .00f);
        node39->getVars().setVariable<float>(2, .00f);
        node39->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(15031, 39, node39)
    }
    if (noInit == true) {
        return node39;
    }
    auto node8 = GET_SKILL_NODE(8, PhaseNode_GetLocation);
    auto node10 = GET_SKILL_NODE(10, PhaseNode_GetRotation);
    if (node8 != nullptr) node39->getVars().setVariable<float>(0, node8->getX());
    if (node8 != nullptr) node39->getVars().setVariable<float>(1, node8->getY());
    if (node10 != nullptr) node39->setRotation(node10->getAngle());
    return node39;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(15031, 40) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 22, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_LESS, 41, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_CompareFloat::TRIGGER_LESS, 22, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(15031, 40) {
    auto node40 = GET_SKILL_NODE(40, PhaseNode_CompareFloat);
    if (node40 == nullptr) {
        node40 = new PhaseNode_CompareFloat(40, phase);
        node40->setA(.00f);
        node40->setB(.00f);
        CALL_REGISTER_SKILL_NODE(15031, 40, node40)
    }
    if (noInit == true) {
        return node40;
    }
    return node40;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(15031, 41) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StopEffect>(PhaseNode_Delay::TRIGGER_DONE, 42, PhaseNode_StopEffect::FUNC_DO, &PhaseNode_StopEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(15031, 41) {
    auto node41 = GET_SKILL_NODE(41, PhaseNode_Delay);
    if (node41 == nullptr) {
        node41 = new PhaseNode_Delay(41, phase);
        node41->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(15031, 41, node41)
    }
    if (noInit == true) {
        return node41;
    }
    return node41;
}
//--------------------------------------------------------------------------------
// StopEffect
//
REGISTER_REGISTER_SKILL_NODE(15031, 42) {
}

REGISTER_CREATE_SKILL_NODE(15031, 42) {
    auto node42 = GET_SKILL_NODE(42, PhaseNode_StopEffect);
    if (node42 == nullptr) {
        node42 = new PhaseNode_StopEffect(42, phase);
        node42->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node42->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node42->setEffectID(101043);
        CALL_REGISTER_SKILL_NODE(15031, 42, node42)
    }
    if (noInit == true) {
        return node42;
    }
    return node42;
}

//--------------------------------------------------------------------------------
// SkillCreator_15031
//
class SkillCreator_15031 : public SkillCreator {
public:
    SkillCreator_15031() {}
    virtual ~SkillCreator_15031() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_15031

//--------------------------------------------------------------------------------
// SkillPhase_15031
//
class SkillPhase_15031 : public SkillPhase {
public:
    SkillPhase_15031(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_15031() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(15031, 1) // StartPhase
        CASE_CREATE_SKILL_NODE(15031, 2) // EndPhase
        CASE_CREATE_SKILL_NODE(15031, 4) // TriggerUpdate
        CASE_CREATE_SKILL_NODE(15031, 6) // ResetCD
        CASE_CREATE_SKILL_NODE(15031, 8) // GetLocation
        CASE_CREATE_SKILL_NODE(15031, 10) // GetRotation
        CASE_CREATE_SKILL_NODE(15031, 12) // OffsetCalculate
        CASE_CREATE_SKILL_NODE(15031, 14) // PlayAnimation
        CASE_CREATE_SKILL_NODE(15031, 16) // Delay
        CASE_CREATE_SKILL_NODE(15031, 20) // SpawnProjectile
        CASE_CREATE_SKILL_NODE(15031, 22) // PlaySound
        CASE_CREATE_SKILL_NODE(15031, 25) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(15031, 28) // GetBBParamUInt64
        CASE_CREATE_SKILL_NODE(15031, 30) // GetLocation
        CASE_CREATE_SKILL_NODE(15031, 32) // GetLineRotation
        CASE_CREATE_SKILL_NODE(15031, 34) // SpawnCollider
        CASE_CREATE_SKILL_NODE(15031, 36) // AttachTo
        CASE_CREATE_SKILL_NODE(15031, 37) // PlayEffect
        CASE_CREATE_SKILL_NODE(15031, 38) // If
        CASE_CREATE_SKILL_NODE(15031, 39) // PlayEffect
        CASE_CREATE_SKILL_NODE(15031, 40) // CompareFloat
        CASE_CREATE_SKILL_NODE(15031, 41) // Delay
        CASE_CREATE_SKILL_NODE(15031, 42) // StopEffect
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_15031

SkillLogic* SkillCreator_15031::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //创建阶段phase
    auto phase = new SkillPhase_15031(1, logic, 2);
    //设置phase执行器
    phase->setRunPhaseNode(1, 1);
    phase->setRunPhaseNode(2, 4);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_15031::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
