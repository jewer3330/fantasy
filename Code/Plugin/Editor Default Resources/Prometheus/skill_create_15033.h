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
REGISTER_REGISTER_SKILL_NODE(15033, 38) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_StartPhase::TRIGGER_START, 41, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(15033, 38) {
    auto node38 = GET_SKILL_NODE(38, PhaseNode_StartPhase);
    if (node38 == nullptr) {
        node38 = new PhaseNode_StartPhase(38, phase);
        CALL_REGISTER_SKILL_NODE(15033, 38, node38)
    }
    if (noInit == true) {
        return node38;
    }
    return node38;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(15033, 39) {
}

REGISTER_CREATE_SKILL_NODE(15033, 39) {
    auto node39 = GET_SKILL_NODE(39, PhaseNode_EndPhase);
    if (node39 == nullptr) {
        node39 = new PhaseNode_EndPhase(39, phase);
        node39->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node39->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(15033, 39, node39)
    }
    if (noInit == true) {
        return node39;
    }
    return node39;
}
//--------------------------------------------------------------------------------
// TriggerUpdate
//
REGISTER_REGISTER_SKILL_NODE(15033, 40) {
}

REGISTER_CREATE_SKILL_NODE(15033, 40) {
    auto node40 = GET_SKILL_NODE(40, PhaseNode_TriggerUpdate);
    if (node40 == nullptr) {
        node40 = new PhaseNode_TriggerUpdate(40, phase);
        CALL_REGISTER_SKILL_NODE(15033, 40, node40)
    }
    if (noInit == true) {
        return node40;
    }
    return node40;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(15033, 41) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_ResetCD::TRIGGER_DONE, 42, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(15033, 41) {
    auto node41 = GET_SKILL_NODE(41, PhaseNode_ResetCD);
    if (node41 == nullptr) {
        node41 = new PhaseNode_ResetCD(41, phase);
        node41->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node41->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node41->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(15033, 41, node41)
    }
    if (noInit == true) {
        return node41;
    }
    return node41;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(15033, 42) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetRotation>(PhaseNode_GetLocation::TRIGGER_DONE, 43, PhaseNode_GetRotation::FUNC_DO, &PhaseNode_GetRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(15033, 42) {
    auto node42 = GET_SKILL_NODE(42, PhaseNode_GetLocation);
    if (node42 == nullptr) {
        node42 = new PhaseNode_GetLocation(42, phase);
        node42->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node42->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(15033, 42, node42)
    }
    if (noInit == true) {
        return node42;
    }
    return node42;
}
//--------------------------------------------------------------------------------
// GetRotation
//
REGISTER_REGISTER_SKILL_NODE(15033, 43) {
    pnode->resizeTrigger(PhaseNode_GetRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetBBParamUInt64>(PhaseNode_GetRotation::TRIGGER_DONE, 51, PhaseNode_GetBBParamUInt64::FUNC_DO, &PhaseNode_GetBBParamUInt64::Do);
}

REGISTER_CREATE_SKILL_NODE(15033, 43) {
    auto node43 = GET_SKILL_NODE(43, PhaseNode_GetRotation);
    if (node43 == nullptr) {
        node43 = new PhaseNode_GetRotation(43, phase);
        node43->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node43->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(15033, 43, node43)
    }
    if (noInit == true) {
        return node43;
    }
    return node43;
}
//--------------------------------------------------------------------------------
// OffsetCalculate
//
REGISTER_REGISTER_SKILL_NODE(15033, 44) {
    pnode->resizeTrigger(PhaseNode_OffsetCalculate::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 45, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(15033, 44) {
    auto node44 = GET_SKILL_NODE(44, PhaseNode_OffsetCalculate);
    if (node44 == nullptr) {
        node44 = new PhaseNode_OffsetCalculate(44, phase);
        node44->setPosZ(.00f);
        node44->setOffsetX(.00f);
        node44->setOffsetY(1.10f);
        node44->setOffsetZ(1.74f);
        node44->setRotOffset(.00f);
        CALL_REGISTER_SKILL_NODE(15033, 44, node44)
    }
    if (noInit == true) {
        return node44;
    }
    auto node42 = GET_SKILL_NODE(42, PhaseNode_GetLocation);
    auto node53 = GET_SKILL_NODE(53, PhaseNode_GetLineRotation);
    if (node42 != nullptr) node44->setPosX(node42->getX());
    if (node42 != nullptr) node44->setPosY(node42->getY());
    if (node53 != nullptr) node44->setRotation(node53->getRotation());
    return node44;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(15033, 45) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_PlayAnimation::TRIGGER_DONE, 61, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(15033, 45) {
    auto node45 = GET_SKILL_NODE(45, PhaseNode_PlayAnimation);
    if (node45 == nullptr) {
        node45 = new PhaseNode_PlayAnimation(45, phase);
        node45->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node45->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node45->setTarget(0U);
        node45->setAnimation("Skill3S1");
        node45->setParameter("");
        node45->setValue(false);
        CALL_REGISTER_SKILL_NODE(15033, 45, node45)
    }
    if (noInit == true) {
        return node45;
    }
    return node45;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(15033, 46) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_Delay::TRIGGER_DONE, 48, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(15033, 46) {
    auto node46 = GET_SKILL_NODE(46, PhaseNode_Delay);
    if (node46 == nullptr) {
        node46 = new PhaseNode_Delay(46, phase);
        node46->setTime(.35f);
        CALL_REGISTER_SKILL_NODE(15033, 46, node46)
    }
    if (noInit == true) {
        return node46;
    }
    return node46;
}
//--------------------------------------------------------------------------------
// SpawnProjectile
//
REGISTER_REGISTER_SKILL_NODE(15033, 47) {
    pnode->resizeTrigger(PhaseNode_SpawnProjectile::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_SpawnProjectile::TRIGGER_DONE, 57, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(15033, 47) {
    auto node47 = GET_SKILL_NODE(47, PhaseNode_SpawnProjectile);
    if (node47 == nullptr) {
        node47 = new PhaseNode_SpawnProjectile(47, phase);
        node47->setDataId(51504);
        node47->setEndPosX(.00f);
        node47->setEndPosY(.00f);
        node47->setEndPosZ(.00f);
        node47->setMaxCount(0);
        CALL_REGISTER_SKILL_NODE(15033, 47, node47)
    }
    if (noInit == true) {
        return node47;
    }
    auto node42 = GET_SKILL_NODE(42, PhaseNode_GetLocation);
    auto node44 = GET_SKILL_NODE(44, PhaseNode_OffsetCalculate);
    if (node42 != nullptr) node47->setPosX(node42->getX());
    if (node42 != nullptr) node47->setPosY(node42->getY());
    if (node44 != nullptr) node47->setPosZ(node44->getOutPosZ());
    if (node44 != nullptr) node47->setRotation(node44->getOutRotation());
    return node47;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(15033, 48) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnProjectile>(PhaseNode_PlaySound::TRIGGER_DONE, 47, PhaseNode_SpawnProjectile::FUNC_DO, &PhaseNode_SpawnProjectile::Do);
}

REGISTER_CREATE_SKILL_NODE(15033, 48) {
    auto node48 = GET_SKILL_NODE(48, PhaseNode_PlaySound);
    if (node48 == nullptr) {
        node48 = new PhaseNode_PlaySound(48, phase);
        node48->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node48->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node48->setSoundID("SE_Hero103_Skill_A_P2C");
        node48->setTarget(0U);
        node48->setUsePos(false);
        node48->setPosX(.00f);
        node48->setPosY(.00f);
        node48->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(15033, 48, node48)
    }
    if (noInit == true) {
        return node48;
    }
    return node48;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(15033, 49) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 39, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(15033, 49) {
    auto node49 = GET_SKILL_NODE(49, PhaseNode_SkillEndNotify);
    if (node49 == nullptr) {
        node49 = new PhaseNode_SkillEndNotify(49, phase);
        node49->setReturnType(true);
        CALL_REGISTER_SKILL_NODE(15033, 49, node49)
    }
    if (noInit == true) {
        return node49;
    }
    return node49;
}
//--------------------------------------------------------------------------------
// GetBBParamUInt64
//
REGISTER_REGISTER_SKILL_NODE(15033, 51) {
    pnode->resizeTrigger(PhaseNode_GetBBParamUInt64::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_GetBBParamUInt64::TRIGGER_DONE, 52, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(15033, 51) {
    auto node51 = GET_SKILL_NODE(51, PhaseNode_GetBBParamUInt64);
    if (node51 == nullptr) {
        node51 = new PhaseNode_GetBBParamUInt64(51, phase);
        node51->setBBName("AtkTarget");
        CALL_REGISTER_SKILL_NODE(15033, 51, node51)
    }
    if (noInit == true) {
        return node51;
    }
    return node51;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(15033, 52) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLineRotation>(PhaseNode_GetLocation::TRIGGER_DONE, 53, PhaseNode_GetLineRotation::FUNC_DO, &PhaseNode_GetLineRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(15033, 52) {
    auto node52 = GET_SKILL_NODE(52, PhaseNode_GetLocation);
    if (node52 == nullptr) {
        node52 = new PhaseNode_GetLocation(52, phase);
        node52->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        CALL_REGISTER_SKILL_NODE(15033, 52, node52)
    }
    if (noInit == true) {
        return node52;
    }
    auto node51 = GET_SKILL_NODE(51, PhaseNode_GetBBParamUInt64);
    if (node51 != nullptr) node52->setTarget(node51->getValue());
    return node52;
}
//--------------------------------------------------------------------------------
// GetLineRotation
//
REGISTER_REGISTER_SKILL_NODE(15033, 53) {
    pnode->resizeTrigger(PhaseNode_GetLineRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnCollider>(PhaseNode_GetLineRotation::TRIGGER_DONE, 54, PhaseNode_SpawnCollider::FUNC_DO, &PhaseNode_SpawnCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(15033, 53) {
    auto node53 = GET_SKILL_NODE(53, PhaseNode_GetLineRotation);
    if (node53 == nullptr) {
        node53 = new PhaseNode_GetLineRotation(53, phase);
        CALL_REGISTER_SKILL_NODE(15033, 53, node53)
    }
    if (noInit == true) {
        return node53;
    }
    auto node42 = GET_SKILL_NODE(42, PhaseNode_GetLocation);
    auto node52 = GET_SKILL_NODE(52, PhaseNode_GetLocation);
    if (node42 != nullptr) node53->setStartX(node42->getX());
    if (node42 != nullptr) node53->setStartY(node42->getY());
    if (node52 != nullptr) node53->setEndX(node52->getX());
    if (node52 != nullptr) node53->setEndY(node52->getY());
    return node53;
}
//--------------------------------------------------------------------------------
// SpawnCollider
//
REGISTER_REGISTER_SKILL_NODE(15033, 54) {
    pnode->resizeTrigger(PhaseNode_SpawnCollider::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AttachTo>(PhaseNode_SpawnCollider::TRIGGER_DONE, 55, PhaseNode_AttachTo::FUNC_DO, &PhaseNode_AttachTo::Do);
}

REGISTER_CREATE_SKILL_NODE(15033, 54) {
    auto node54 = GET_SKILL_NODE(54, PhaseNode_SpawnCollider);
    if (node54 == nullptr) {
        node54 = new PhaseNode_SpawnCollider(54, phase);
        node54->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node54->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node54->setMesh("");
        node54->setMeshScale(.00f);
        node54->setEffectID(0);
        node54->setEffectScale(.00f);
        node54->setType(PhaseNode_SpawnCollider::SpawnCollider_Type::Circle);
        node54->setTypeParams(0, .00f);
        node54->setTime(.20f);
        node54->setPosZ(.00f);
        node54->setreentry(false);
        node54->setCheckPeneSound(false);
        CALL_REGISTER_SKILL_NODE(15033, 54, node54)
    }
    if (noInit == true) {
        return node54;
    }
    auto node42 = GET_SKILL_NODE(42, PhaseNode_GetLocation);
    auto node53 = GET_SKILL_NODE(53, PhaseNode_GetLineRotation);
    if (node42 != nullptr) node54->setPosX(node42->getX());
    if (node42 != nullptr) node54->setPosY(node42->getY());
    if (node53 != nullptr) node54->setRotation(node53->getRotation());
    return node54;
}
//--------------------------------------------------------------------------------
// AttachTo
//
REGISTER_REGISTER_SKILL_NODE(15033, 55) {
    pnode->resizeTrigger(PhaseNode_AttachTo::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_OffsetCalculate>(PhaseNode_AttachTo::TRIGGER_DONE, 44, PhaseNode_OffsetCalculate::FUNC_DO, &PhaseNode_OffsetCalculate::Do);
}

REGISTER_CREATE_SKILL_NODE(15033, 55) {
    auto node55 = GET_SKILL_NODE(55, PhaseNode_AttachTo);
    if (node55 == nullptr) {
        node55 = new PhaseNode_AttachTo(55, phase);
        node55->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node55->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node55->setChild(0U);
        node55->setChangeRotation(true);
        node55->setreentry(false);
        CALL_REGISTER_SKILL_NODE(15033, 55, node55)
    }
    if (noInit == true) {
        return node55;
    }
    auto node54 = GET_SKILL_NODE(54, PhaseNode_SpawnCollider);
    if (node54 != nullptr) node55->setParent(node54->getColliderID());
    return node55;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(15033, 57) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_Delay::TRIGGER_DONE, 49, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
}

REGISTER_CREATE_SKILL_NODE(15033, 57) {
    auto node57 = GET_SKILL_NODE(57, PhaseNode_Delay);
    if (node57 == nullptr) {
        node57 = new PhaseNode_Delay(57, phase);
        node57->setTime(.35f);
        CALL_REGISTER_SKILL_NODE(15033, 57, node57)
    }
    if (noInit == true) {
        return node57;
    }
    return node57;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(15033, 59) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlaySound::TRIGGER_DONE, 46, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(15033, 59) {
    auto node59 = GET_SKILL_NODE(59, PhaseNode_PlaySound);
    if (node59 == nullptr) {
        node59 = new PhaseNode_PlaySound(59, phase);
        node59->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node59->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node59->setSoundID("SE_Hero103_Skill_A_P2B");
        node59->setTarget(0U);
        node59->setUsePos(false);
        node59->setPosX(.00f);
        node59->setPosY(.00f);
        node59->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(15033, 59, node59)
    }
    if (noInit == true) {
        return node59;
    }
    return node59;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(15033, 60) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_PlayEffect::TRIGGER_DONE, 63, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(15033, 60) {
    auto node60 = GET_SKILL_NODE(60, PhaseNode_PlayEffect);
    if (node60 == nullptr) {
        node60 = new PhaseNode_PlayEffect(60, phase);
        node60->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node60->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node60->setEffectID(101050);
        node60->setChangeColor(true);
        node60->setType(PhaseNode_PlayEffect::PlayEffect_Type::WithTarget);
        node60->getVars().reserve(5);
        node60->getVars().setVariable<uint64_t>(0, 0U);
        node60->getVars().setVariable<std::string>(1, "");
        node60->getVars().setVariable<float>(2, .00f);
        node60->getVars().setVariable<float>(3, .00f);
        node60->getVars().setVariable<float>(4, .00f);
        node60->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(15033, 60, node60)
    }
    if (noInit == true) {
        return node60;
    }
    auto node42 = GET_SKILL_NODE(42, PhaseNode_GetLocation);
    auto node43 = GET_SKILL_NODE(43, PhaseNode_GetRotation);
    if (node42 != nullptr) node60->getVars().setVariable<float>(2, node42->getX());
    if (node42 != nullptr) node60->getVars().setVariable<float>(3, node42->getY());
    if (node43 != nullptr) node60->setRotation(node43->getAngle());
    return node60;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(15033, 61) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_FALSE, 62, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_TRUE, 60, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(15033, 61) {
    auto node61 = GET_SKILL_NODE(61, PhaseNode_If);
    if (node61 == nullptr) {
        node61 = new PhaseNode_If(61, phase);
        node61->setCondition(false);
        CALL_REGISTER_SKILL_NODE(15033, 61, node61)
    }
    if (noInit == true) {
        return node61;
    }
    return node61;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(15033, 62) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_PlayEffect::TRIGGER_DONE, 63, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(15033, 62) {
    auto node62 = GET_SKILL_NODE(62, PhaseNode_PlayEffect);
    if (node62 == nullptr) {
        node62 = new PhaseNode_PlayEffect(62, phase);
        node62->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node62->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node62->setEffectID(101050);
        node62->setChangeColor(true);
        node62->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node62->getVars().reserve(3);
        node62->getVars().setVariable<float>(0, .00f);
        node62->getVars().setVariable<float>(1, .00f);
        node62->getVars().setVariable<float>(2, .00f);
        node62->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(15033, 62, node62)
    }
    if (noInit == true) {
        return node62;
    }
    auto node42 = GET_SKILL_NODE(42, PhaseNode_GetLocation);
    auto node43 = GET_SKILL_NODE(43, PhaseNode_GetRotation);
    if (node42 != nullptr) node62->getVars().setVariable<float>(0, node42->getX());
    if (node42 != nullptr) node62->getVars().setVariable<float>(1, node42->getY());
    if (node43 != nullptr) node62->setRotation(node43->getAngle());
    return node62;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(15033, 63) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 59, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_LESS, 64, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_CompareFloat::TRIGGER_LESS, 59, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(15033, 63) {
    auto node63 = GET_SKILL_NODE(63, PhaseNode_CompareFloat);
    if (node63 == nullptr) {
        node63 = new PhaseNode_CompareFloat(63, phase);
        node63->setA(.00f);
        node63->setB(.00f);
        CALL_REGISTER_SKILL_NODE(15033, 63, node63)
    }
    if (noInit == true) {
        return node63;
    }
    return node63;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(15033, 64) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StopEffect>(PhaseNode_Delay::TRIGGER_DONE, 65, PhaseNode_StopEffect::FUNC_DO, &PhaseNode_StopEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(15033, 64) {
    auto node64 = GET_SKILL_NODE(64, PhaseNode_Delay);
    if (node64 == nullptr) {
        node64 = new PhaseNode_Delay(64, phase);
        node64->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(15033, 64, node64)
    }
    if (noInit == true) {
        return node64;
    }
    return node64;
}
//--------------------------------------------------------------------------------
// StopEffect
//
REGISTER_REGISTER_SKILL_NODE(15033, 65) {
}

REGISTER_CREATE_SKILL_NODE(15033, 65) {
    auto node65 = GET_SKILL_NODE(65, PhaseNode_StopEffect);
    if (node65 == nullptr) {
        node65 = new PhaseNode_StopEffect(65, phase);
        node65->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node65->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node65->setEffectID(101050);
        CALL_REGISTER_SKILL_NODE(15033, 65, node65)
    }
    if (noInit == true) {
        return node65;
    }
    return node65;
}

//--------------------------------------------------------------------------------
// SkillCreator_15033
//
class SkillCreator_15033 : public SkillCreator {
public:
    SkillCreator_15033() {}
    virtual ~SkillCreator_15033() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_15033

//--------------------------------------------------------------------------------
// SkillPhase_15033
//
class SkillPhase_15033 : public SkillPhase {
public:
    SkillPhase_15033(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_15033() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(15033, 38) // StartPhase
        CASE_CREATE_SKILL_NODE(15033, 39) // EndPhase
        CASE_CREATE_SKILL_NODE(15033, 40) // TriggerUpdate
        CASE_CREATE_SKILL_NODE(15033, 41) // ResetCD
        CASE_CREATE_SKILL_NODE(15033, 42) // GetLocation
        CASE_CREATE_SKILL_NODE(15033, 43) // GetRotation
        CASE_CREATE_SKILL_NODE(15033, 44) // OffsetCalculate
        CASE_CREATE_SKILL_NODE(15033, 45) // PlayAnimation
        CASE_CREATE_SKILL_NODE(15033, 46) // Delay
        CASE_CREATE_SKILL_NODE(15033, 47) // SpawnProjectile
        CASE_CREATE_SKILL_NODE(15033, 48) // PlaySound
        CASE_CREATE_SKILL_NODE(15033, 49) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(15033, 51) // GetBBParamUInt64
        CASE_CREATE_SKILL_NODE(15033, 52) // GetLocation
        CASE_CREATE_SKILL_NODE(15033, 53) // GetLineRotation
        CASE_CREATE_SKILL_NODE(15033, 54) // SpawnCollider
        CASE_CREATE_SKILL_NODE(15033, 55) // AttachTo
        CASE_CREATE_SKILL_NODE(15033, 57) // Delay
        CASE_CREATE_SKILL_NODE(15033, 59) // PlaySound
        CASE_CREATE_SKILL_NODE(15033, 60) // PlayEffect
        CASE_CREATE_SKILL_NODE(15033, 61) // If
        CASE_CREATE_SKILL_NODE(15033, 62) // PlayEffect
        CASE_CREATE_SKILL_NODE(15033, 63) // CompareFloat
        CASE_CREATE_SKILL_NODE(15033, 64) // Delay
        CASE_CREATE_SKILL_NODE(15033, 65) // StopEffect
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_15033

SkillLogic* SkillCreator_15033::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //创建阶段phase
    auto phase = new SkillPhase_15033(1, logic, 2);
    //设置phase执行器
    phase->setRunPhaseNode(1, 38);
    phase->setRunPhaseNode(2, 40);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_15033::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
