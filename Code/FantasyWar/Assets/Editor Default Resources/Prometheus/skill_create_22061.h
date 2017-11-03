#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

#include "skill_psnode_comparefloat.h"
#include "skill_psnode_delay.h"
#include "skill_psnode_detect.h"
#include "skill_psnode_endphase.h"
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
#include "skill_psnode_spawnprojectile.h"
#include "skill_psnode_startphase.h"
#include "skill_psnode_stopeffect.h"
#include "skill_psnode_triggerupdate.h"

namespace pvp {

//变量声明
//--------------------------------------------------------------------------------
// StartPhase
//
REGISTER_REGISTER_SKILL_NODE(22061, 2) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_StartPhase::TRIGGER_START, 56, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_StartPhase::TRIGGER_START, 46, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_StartPhase::TRIGGER_START, 35, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(22061, 2) {
    auto node2 = GET_SKILL_NODE(2, PhaseNode_StartPhase);
    if (node2 == nullptr) {
        node2 = new PhaseNode_StartPhase(2, phase);
        CALL_REGISTER_SKILL_NODE(22061, 2, node2)
    }
    if (noInit == true) {
        return node2;
    }
    return node2;
}
//--------------------------------------------------------------------------------
// TriggerUpdate
//
REGISTER_REGISTER_SKILL_NODE(22061, 4) {
}

REGISTER_CREATE_SKILL_NODE(22061, 4) {
    auto node4 = GET_SKILL_NODE(4, PhaseNode_TriggerUpdate);
    if (node4 == nullptr) {
        node4 = new PhaseNode_TriggerUpdate(4, phase);
        CALL_REGISTER_SKILL_NODE(22061, 4, node4)
    }
    if (noInit == true) {
        return node4;
    }
    return node4;
}
//--------------------------------------------------------------------------------
// SpawnProjectile
//
REGISTER_REGISTER_SKILL_NODE(22061, 20) {
    pnode->resizeTrigger(PhaseNode_SpawnProjectile::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_SpawnProjectile::TRIGGER_DONE, 42, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(22061, 20) {
    auto node20 = GET_SKILL_NODE(20, PhaseNode_SpawnProjectile);
    if (node20 == nullptr) {
        node20 = new PhaseNode_SpawnProjectile(20, phase);
        node20->setDataId(52206);
        node20->setEndPosX(.00f);
        node20->setEndPosY(.00f);
        node20->setEndPosZ(.00f);
        node20->setMaxCount(0);
        CALL_REGISTER_SKILL_NODE(22061, 20, node20)
    }
    if (noInit == true) {
        return node20;
    }
    auto node41 = GET_SKILL_NODE(41, PhaseNode_OffsetCalculate);
    if (node41 != nullptr) node20->setPosX(node41->getOutPosX());
    if (node41 != nullptr) node20->setPosY(node41->getOutPosY());
    if (node41 != nullptr) node20->setPosZ(node41->getOutPosZ());
    if (node41 != nullptr) node20->setRotation(node41->getOutRotation());
    return node20;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(22061, 24) {
}

REGISTER_CREATE_SKILL_NODE(22061, 24) {
    auto node24 = GET_SKILL_NODE(24, PhaseNode_EndPhase);
    if (node24 == nullptr) {
        node24 = new PhaseNode_EndPhase(24, phase);
        node24->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node24->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(22061, 24, node24)
    }
    if (noInit == true) {
        return node24;
    }
    return node24;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(22061, 35) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_ResetCD::TRIGGER_DONE, 36, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(22061, 35) {
    auto node35 = GET_SKILL_NODE(35, PhaseNode_ResetCD);
    if (node35 == nullptr) {
        node35 = new PhaseNode_ResetCD(35, phase);
        node35->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node35->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node35->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(22061, 35, node35)
    }
    if (noInit == true) {
        return node35;
    }
    return node35;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(22061, 36) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_PlayAnimation::TRIGGER_DONE, 37, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(22061, 36) {
    auto node36 = GET_SKILL_NODE(36, PhaseNode_PlayAnimation);
    if (node36 == nullptr) {
        node36 = new PhaseNode_PlayAnimation(36, phase);
        node36->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node36->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node36->setTarget(0U);
        node36->setAnimation("Skill1S1");
        node36->setParameter("");
        node36->setValue(false);
        CALL_REGISTER_SKILL_NODE(22061, 36, node36)
    }
    if (noInit == true) {
        return node36;
    }
    return node36;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(22061, 37) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlaySound::TRIGGER_DONE, 38, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(22061, 37) {
    auto node37 = GET_SKILL_NODE(37, PhaseNode_PlaySound);
    if (node37 == nullptr) {
        node37 = new PhaseNode_PlaySound(37, phase);
        node37->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node37->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node37->setSoundID("");
        node37->setTarget(0U);
        node37->setUsePos(false);
        node37->setPosX(.00f);
        node37->setPosY(.00f);
        node37->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(22061, 37, node37)
    }
    if (noInit == true) {
        return node37;
    }
    return node37;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22061, 38) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_Delay::TRIGGER_DONE, 39, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(22061, 38) {
    auto node38 = GET_SKILL_NODE(38, PhaseNode_Delay);
    if (node38 == nullptr) {
        node38 = new PhaseNode_Delay(38, phase);
        node38->setTime(.90f);
        CALL_REGISTER_SKILL_NODE(22061, 38, node38)
    }
    if (noInit == true) {
        return node38;
    }
    return node38;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(22061, 39) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetRotation>(PhaseNode_GetLocation::TRIGGER_DONE, 40, PhaseNode_GetRotation::FUNC_DO, &PhaseNode_GetRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(22061, 39) {
    auto node39 = GET_SKILL_NODE(39, PhaseNode_GetLocation);
    if (node39 == nullptr) {
        node39 = new PhaseNode_GetLocation(39, phase);
        node39->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node39->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(22061, 39, node39)
    }
    if (noInit == true) {
        return node39;
    }
    return node39;
}
//--------------------------------------------------------------------------------
// GetRotation
//
REGISTER_REGISTER_SKILL_NODE(22061, 40) {
    pnode->resizeTrigger(PhaseNode_GetRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_OffsetCalculate>(PhaseNode_GetRotation::TRIGGER_DONE, 41, PhaseNode_OffsetCalculate::FUNC_DO, &PhaseNode_OffsetCalculate::Do);
}

REGISTER_CREATE_SKILL_NODE(22061, 40) {
    auto node40 = GET_SKILL_NODE(40, PhaseNode_GetRotation);
    if (node40 == nullptr) {
        node40 = new PhaseNode_GetRotation(40, phase);
        node40->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node40->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(22061, 40, node40)
    }
    if (noInit == true) {
        return node40;
    }
    return node40;
}
//--------------------------------------------------------------------------------
// OffsetCalculate
//
REGISTER_REGISTER_SKILL_NODE(22061, 41) {
    pnode->resizeTrigger(PhaseNode_OffsetCalculate::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 51, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(22061, 41) {
    auto node41 = GET_SKILL_NODE(41, PhaseNode_OffsetCalculate);
    if (node41 == nullptr) {
        node41 = new PhaseNode_OffsetCalculate(41, phase);
        node41->setPosZ(.00f);
        node41->setOffsetX(.93f);
        node41->setOffsetY(1.20f);
        node41->setOffsetZ(3.00f);
        node41->setRotOffset(.00f);
        CALL_REGISTER_SKILL_NODE(22061, 41, node41)
    }
    if (noInit == true) {
        return node41;
    }
    auto node39 = GET_SKILL_NODE(39, PhaseNode_GetLocation);
    auto node40 = GET_SKILL_NODE(40, PhaseNode_GetRotation);
    if (node39 != nullptr) node41->setPosX(node39->getX());
    if (node39 != nullptr) node41->setPosY(node39->getY());
    if (node40 != nullptr) node41->setRotation(node40->getAngle());
    return node41;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22061, 42) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_Delay::TRIGGER_DONE, 44, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(22061, 42) {
    auto node42 = GET_SKILL_NODE(42, PhaseNode_Delay);
    if (node42 == nullptr) {
        node42 = new PhaseNode_Delay(42, phase);
        node42->setTime(.90f);
        CALL_REGISTER_SKILL_NODE(22061, 42, node42)
    }
    if (noInit == true) {
        return node42;
    }
    return node42;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(22061, 43) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 24, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(22061, 43) {
    auto node43 = GET_SKILL_NODE(43, PhaseNode_SkillEndNotify);
    if (node43 == nullptr) {
        node43 = new PhaseNode_SkillEndNotify(43, phase);
        node43->setReturnType(false);
        CALL_REGISTER_SKILL_NODE(22061, 43, node43)
    }
    if (noInit == true) {
        return node43;
    }
    return node43;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(22061, 44) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_FALSE, 45, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_TRUE, 43, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
}

REGISTER_CREATE_SKILL_NODE(22061, 44) {
    auto node44 = GET_SKILL_NODE(44, PhaseNode_If);
    if (node44 == nullptr) {
        node44 = new PhaseNode_If(44, phase);
        node44->setCondition(false);
        CALL_REGISTER_SKILL_NODE(22061, 44, node44)
    }
    if (noInit == true) {
        return node44;
    }
    return node44;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(22061, 45) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 24, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(22061, 45) {
    auto node45 = GET_SKILL_NODE(45, PhaseNode_SkillEndNotify);
    if (node45 == nullptr) {
        node45 = new PhaseNode_SkillEndNotify(45, phase);
        node45->setReturnType(true);
        CALL_REGISTER_SKILL_NODE(22061, 45, node45)
    }
    if (noInit == true) {
        return node45;
    }
    return node45;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(22061, 46) {
}

REGISTER_CREATE_SKILL_NODE(22061, 46) {
    auto node46 = GET_SKILL_NODE(46, PhaseNode_RaiseEvent);
    if (node46 == nullptr) {
        node46 = new PhaseNode_RaiseEvent(46, phase);
        node46->setEvent("MonsterInterrupt");
        node46->setTarget(0U);
        node46->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node46->setTypeParams(0, 0);
        node46->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(22061, 46, node46)
    }
    if (noInit == true) {
        return node46;
    }
    return node46;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(22061, 47) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_Detect::TRIGGER_ON, 58, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(22061, 47) {
    auto node47 = GET_SKILL_NODE(47, PhaseNode_Detect);
    if (node47 == nullptr) {
        node47 = new PhaseNode_Detect(47, phase);
        node47->setSelf(0U);
        node47->setEvent("MonsterInterrupt");
        node47->setType(PhaseNode_Detect::Detect_Type::Interrupt_Skill);
        node47->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(22061, 47, node47)
    }
    if (noInit == true) {
        return node47;
    }
    return node47;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(22061, 48) {
}

REGISTER_CREATE_SKILL_NODE(22061, 48) {
    auto node48 = GET_SKILL_NODE(48, PhaseNode_EndPhase);
    if (node48 == nullptr) {
        node48 = new PhaseNode_EndPhase(48, phase);
        node48->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node48->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(22061, 48, node48)
    }
    if (noInit == true) {
        return node48;
    }
    return node48;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(22061, 50) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_PlayEffect::TRIGGER_DONE, 53, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(22061, 50) {
    auto node50 = GET_SKILL_NODE(50, PhaseNode_PlayEffect);
    if (node50 == nullptr) {
        node50 = new PhaseNode_PlayEffect(50, phase);
        node50->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node50->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node50->setEffectID(220712);
        node50->setChangeColor(false);
        node50->setType(PhaseNode_PlayEffect::PlayEffect_Type::WithTarget);
        node50->getVars().reserve(5);
        node50->getVars().setVariable<uint64_t>(0, 0U);
        node50->getVars().setVariable<std::string>(1, "");
        node50->getVars().setVariable<float>(2, .00f);
        node50->getVars().setVariable<float>(3, .00f);
        node50->getVars().setVariable<float>(4, .00f);
        node50->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(22061, 50, node50)
    }
    if (noInit == true) {
        return node50;
    }
    auto node41 = GET_SKILL_NODE(41, PhaseNode_OffsetCalculate);
    if (node41 != nullptr) node50->getVars().setVariable<float>(2, node41->getOutPosX());
    if (node41 != nullptr) node50->getVars().setVariable<float>(3, node41->getOutPosY());
    if (node41 != nullptr) node50->getVars().setVariable<float>(4, node41->getOutPosZ());
    if (node41 != nullptr) node50->setRotation(node41->getOutRotation());
    return node50;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(22061, 51) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_FALSE, 52, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_TRUE, 50, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(22061, 51) {
    auto node51 = GET_SKILL_NODE(51, PhaseNode_If);
    if (node51 == nullptr) {
        node51 = new PhaseNode_If(51, phase);
        node51->setCondition(false);
        CALL_REGISTER_SKILL_NODE(22061, 51, node51)
    }
    if (noInit == true) {
        return node51;
    }
    return node51;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(22061, 52) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_PlayEffect::TRIGGER_DONE, 53, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(22061, 52) {
    auto node52 = GET_SKILL_NODE(52, PhaseNode_PlayEffect);
    if (node52 == nullptr) {
        node52 = new PhaseNode_PlayEffect(52, phase);
        node52->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node52->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node52->setEffectID(220712);
        node52->setChangeColor(false);
        node52->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node52->getVars().reserve(3);
        node52->getVars().setVariable<float>(0, .00f);
        node52->getVars().setVariable<float>(1, .00f);
        node52->getVars().setVariable<float>(2, .00f);
        node52->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(22061, 52, node52)
    }
    if (noInit == true) {
        return node52;
    }
    auto node41 = GET_SKILL_NODE(41, PhaseNode_OffsetCalculate);
    if (node41 != nullptr) node52->getVars().setVariable<float>(0, node41->getOutPosX());
    if (node41 != nullptr) node52->getVars().setVariable<float>(1, node41->getOutPosY());
    if (node41 != nullptr) node52->getVars().setVariable<float>(2, node41->getOutPosZ());
    if (node41 != nullptr) node52->setRotation(node41->getOutRotation());
    return node52;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(22061, 53) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnProjectile>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 20, PhaseNode_SpawnProjectile::FUNC_DO, &PhaseNode_SpawnProjectile::Do);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_LESS, 54, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_SpawnProjectile>(PhaseNode_CompareFloat::TRIGGER_LESS, 20, PhaseNode_SpawnProjectile::FUNC_DO, &PhaseNode_SpawnProjectile::Do);
}

REGISTER_CREATE_SKILL_NODE(22061, 53) {
    auto node53 = GET_SKILL_NODE(53, PhaseNode_CompareFloat);
    if (node53 == nullptr) {
        node53 = new PhaseNode_CompareFloat(53, phase);
        node53->setA(.00f);
        node53->setB(.00f);
        CALL_REGISTER_SKILL_NODE(22061, 53, node53)
    }
    if (noInit == true) {
        return node53;
    }
    return node53;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22061, 54) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StopEffect>(PhaseNode_Delay::TRIGGER_DONE, 55, PhaseNode_StopEffect::FUNC_DO, &PhaseNode_StopEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(22061, 54) {
    auto node54 = GET_SKILL_NODE(54, PhaseNode_Delay);
    if (node54 == nullptr) {
        node54 = new PhaseNode_Delay(54, phase);
        node54->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(22061, 54, node54)
    }
    if (noInit == true) {
        return node54;
    }
    return node54;
}
//--------------------------------------------------------------------------------
// StopEffect
//
REGISTER_REGISTER_SKILL_NODE(22061, 55) {
}

REGISTER_CREATE_SKILL_NODE(22061, 55) {
    auto node55 = GET_SKILL_NODE(55, PhaseNode_StopEffect);
    if (node55 == nullptr) {
        node55 = new PhaseNode_StopEffect(55, phase);
        node55->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node55->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node55->setEffectID(220712);
        CALL_REGISTER_SKILL_NODE(22061, 55, node55)
    }
    if (noInit == true) {
        return node55;
    }
    return node55;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22061, 56) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_Delay::TRIGGER_DONE, 57, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(22061, 56) {
    auto node56 = GET_SKILL_NODE(56, PhaseNode_Delay);
    if (node56 == nullptr) {
        node56 = new PhaseNode_Delay(56, phase);
        node56->setTime(.90f);
        CALL_REGISTER_SKILL_NODE(22061, 56, node56)
    }
    if (noInit == true) {
        return node56;
    }
    return node56;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(22061, 57) {
}

REGISTER_CREATE_SKILL_NODE(22061, 57) {
    auto node57 = GET_SKILL_NODE(57, PhaseNode_PlaySound);
    if (node57 == nullptr) {
        node57 = new PhaseNode_PlaySound(57, phase);
        node57->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node57->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node57->setSoundID("SE_MON2207_ATK_A_P1");
        node57->setTarget(0U);
        node57->setUsePos(false);
        node57->setPosX(.00f);
        node57->setPosY(.00f);
        node57->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(22061, 57, node57)
    }
    if (noInit == true) {
        return node57;
    }
    return node57;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22061, 58) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_Delay::TRIGGER_DONE, 60, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(22061, 58) {
    auto node58 = GET_SKILL_NODE(58, PhaseNode_Delay);
    if (node58 == nullptr) {
        node58 = new PhaseNode_Delay(58, phase);
        node58->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(22061, 58, node58)
    }
    if (noInit == true) {
        return node58;
    }
    return node58;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(22061, 59) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 48, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(22061, 59) {
    auto node59 = GET_SKILL_NODE(59, PhaseNode_SkillEndNotify);
    if (node59 == nullptr) {
        node59 = new PhaseNode_SkillEndNotify(59, phase);
        node59->setReturnType(false);
        CALL_REGISTER_SKILL_NODE(22061, 59, node59)
    }
    if (noInit == true) {
        return node59;
    }
    return node59;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(22061, 60) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_FALSE, 61, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_TRUE, 59, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
}

REGISTER_CREATE_SKILL_NODE(22061, 60) {
    auto node60 = GET_SKILL_NODE(60, PhaseNode_If);
    if (node60 == nullptr) {
        node60 = new PhaseNode_If(60, phase);
        node60->setCondition(false);
        CALL_REGISTER_SKILL_NODE(22061, 60, node60)
    }
    if (noInit == true) {
        return node60;
    }
    return node60;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(22061, 61) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 48, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(22061, 61) {
    auto node61 = GET_SKILL_NODE(61, PhaseNode_SkillEndNotify);
    if (node61 == nullptr) {
        node61 = new PhaseNode_SkillEndNotify(61, phase);
        node61->setReturnType(true);
        CALL_REGISTER_SKILL_NODE(22061, 61, node61)
    }
    if (noInit == true) {
        return node61;
    }
    return node61;
}

//--------------------------------------------------------------------------------
// SkillCreator_22061
//
class SkillCreator_22061 : public SkillCreator {
public:
    SkillCreator_22061() {}
    virtual ~SkillCreator_22061() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_22061

//--------------------------------------------------------------------------------
// SkillPhase_22061
//
class SkillPhase_22061 : public SkillPhase {
public:
    SkillPhase_22061(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_22061() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(22061, 2) // StartPhase
        CASE_CREATE_SKILL_NODE(22061, 4) // TriggerUpdate
        CASE_CREATE_SKILL_NODE(22061, 20) // SpawnProjectile
        CASE_CREATE_SKILL_NODE(22061, 24) // EndPhase
        CASE_CREATE_SKILL_NODE(22061, 35) // ResetCD
        CASE_CREATE_SKILL_NODE(22061, 36) // PlayAnimation
        CASE_CREATE_SKILL_NODE(22061, 37) // PlaySound
        CASE_CREATE_SKILL_NODE(22061, 38) // Delay
        CASE_CREATE_SKILL_NODE(22061, 39) // GetLocation
        CASE_CREATE_SKILL_NODE(22061, 40) // GetRotation
        CASE_CREATE_SKILL_NODE(22061, 41) // OffsetCalculate
        CASE_CREATE_SKILL_NODE(22061, 42) // Delay
        CASE_CREATE_SKILL_NODE(22061, 43) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(22061, 44) // If
        CASE_CREATE_SKILL_NODE(22061, 45) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(22061, 46) // RaiseEvent
        CASE_CREATE_SKILL_NODE(22061, 47) // Detect
        CASE_CREATE_SKILL_NODE(22061, 48) // EndPhase
        CASE_CREATE_SKILL_NODE(22061, 50) // PlayEffect
        CASE_CREATE_SKILL_NODE(22061, 51) // If
        CASE_CREATE_SKILL_NODE(22061, 52) // PlayEffect
        CASE_CREATE_SKILL_NODE(22061, 53) // CompareFloat
        CASE_CREATE_SKILL_NODE(22061, 54) // Delay
        CASE_CREATE_SKILL_NODE(22061, 55) // StopEffect
        CASE_CREATE_SKILL_NODE(22061, 56) // Delay
        CASE_CREATE_SKILL_NODE(22061, 57) // PlaySound
        CASE_CREATE_SKILL_NODE(22061, 58) // Delay
        CASE_CREATE_SKILL_NODE(22061, 59) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(22061, 60) // If
        CASE_CREATE_SKILL_NODE(22061, 61) // SkillEndNotify
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_22061

SkillLogic* SkillCreator_22061::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //创建阶段phase
    auto phase = new SkillPhase_22061(1, logic, 3);
    //设置phase执行器
    phase->setRunPhaseNode(1, 2);
    phase->setRunPhaseNode(2, 4);
    phase->setDetectPhaseNode(3, 47);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_22061::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
