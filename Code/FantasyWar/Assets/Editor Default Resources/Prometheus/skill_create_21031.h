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
REGISTER_REGISTER_SKILL_NODE(21031, 2) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_StartPhase::TRIGGER_START, 52, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_StartPhase::TRIGGER_START, 44, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(21031, 2) {
    auto node2 = GET_SKILL_NODE(2, PhaseNode_StartPhase);
    if (node2 == nullptr) {
        node2 = new PhaseNode_StartPhase(2, phase);
        CALL_REGISTER_SKILL_NODE(21031, 2, node2)
    }
    if (noInit == true) {
        return node2;
    }
    return node2;
}
//--------------------------------------------------------------------------------
// TriggerUpdate
//
REGISTER_REGISTER_SKILL_NODE(21031, 4) {
}

REGISTER_CREATE_SKILL_NODE(21031, 4) {
    auto node4 = GET_SKILL_NODE(4, PhaseNode_TriggerUpdate);
    if (node4 == nullptr) {
        node4 = new PhaseNode_TriggerUpdate(4, phase);
        CALL_REGISTER_SKILL_NODE(21031, 4, node4)
    }
    if (noInit == true) {
        return node4;
    }
    return node4;
}
//--------------------------------------------------------------------------------
// SpawnProjectile
//
REGISTER_REGISTER_SKILL_NODE(21031, 18) {
    pnode->resizeTrigger(PhaseNode_SpawnProjectile::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_SpawnProjectile::TRIGGER_DONE, 48, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(21031, 18) {
    auto node18 = GET_SKILL_NODE(18, PhaseNode_SpawnProjectile);
    if (node18 == nullptr) {
        node18 = new PhaseNode_SpawnProjectile(18, phase);
        node18->setDataId(52103);
        node18->setEndPosX(.00f);
        node18->setEndPosY(.00f);
        node18->setEndPosZ(.00f);
        node18->setMaxCount(0);
        CALL_REGISTER_SKILL_NODE(21031, 18, node18)
    }
    if (noInit == true) {
        return node18;
    }
    auto node43 = GET_SKILL_NODE(43, PhaseNode_OffsetCalculate);
    if (node43 != nullptr) node18->setPosX(node43->getOutPosX());
    if (node43 != nullptr) node18->setPosY(node43->getOutPosY());
    if (node43 != nullptr) node18->setPosZ(node43->getOutPosZ());
    if (node43 != nullptr) node18->setRotation(node43->getOutRotation());
    return node18;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(21031, 20) {
}

REGISTER_CREATE_SKILL_NODE(21031, 20) {
    auto node20 = GET_SKILL_NODE(20, PhaseNode_EndPhase);
    if (node20 == nullptr) {
        node20 = new PhaseNode_EndPhase(20, phase);
        node20->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node20->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(21031, 20, node20)
    }
    if (noInit == true) {
        return node20;
    }
    return node20;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(21031, 27) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_Detect::TRIGGER_ON, 29, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(21031, 27) {
    auto node27 = GET_SKILL_NODE(27, PhaseNode_Detect);
    if (node27 == nullptr) {
        node27 = new PhaseNode_Detect(27, phase);
        node27->setSelf(0U);
        node27->setEvent("");
        node27->setType(PhaseNode_Detect::Detect_Type::Actor_Dead);
        node27->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(21031, 27, node27)
    }
    if (noInit == true) {
        return node27;
    }
    return node27;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(21031, 29) {
}

REGISTER_CREATE_SKILL_NODE(21031, 29) {
    auto node29 = GET_SKILL_NODE(29, PhaseNode_EndPhase);
    if (node29 == nullptr) {
        node29 = new PhaseNode_EndPhase(29, phase);
        node29->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node29->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(21031, 29, node29)
    }
    if (noInit == true) {
        return node29;
    }
    return node29;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(21031, 35) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_PlayEffect::TRIGGER_DONE, 38, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(21031, 35) {
    auto node35 = GET_SKILL_NODE(35, PhaseNode_PlayEffect);
    if (node35 == nullptr) {
        node35 = new PhaseNode_PlayEffect(35, phase);
        node35->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node35->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node35->setEffectID(210312);
        node35->setChangeColor(false);
        node35->setType(PhaseNode_PlayEffect::PlayEffect_Type::WithTarget);
        node35->getVars().reserve(5);
        node35->getVars().setVariable<uint64_t>(0, 0U);
        node35->getVars().setVariable<std::string>(1, "");
        node35->getVars().setVariable<float>(2, .00f);
        node35->getVars().setVariable<float>(3, .00f);
        node35->getVars().setVariable<float>(4, .00f);
        node35->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(21031, 35, node35)
    }
    if (noInit == true) {
        return node35;
    }
    auto node43 = GET_SKILL_NODE(43, PhaseNode_OffsetCalculate);
    if (node43 != nullptr) node35->getVars().setVariable<float>(2, node43->getOutPosX());
    if (node43 != nullptr) node35->getVars().setVariable<float>(3, node43->getOutPosY());
    if (node43 != nullptr) node35->getVars().setVariable<float>(4, node43->getOutPosZ());
    if (node43 != nullptr) node35->setRotation(node43->getOutRotation());
    return node35;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(21031, 36) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_FALSE, 37, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_TRUE, 35, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(21031, 36) {
    auto node36 = GET_SKILL_NODE(36, PhaseNode_If);
    if (node36 == nullptr) {
        node36 = new PhaseNode_If(36, phase);
        node36->setCondition(false);
        CALL_REGISTER_SKILL_NODE(21031, 36, node36)
    }
    if (noInit == true) {
        return node36;
    }
    return node36;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(21031, 37) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_PlayEffect::TRIGGER_DONE, 38, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(21031, 37) {
    auto node37 = GET_SKILL_NODE(37, PhaseNode_PlayEffect);
    if (node37 == nullptr) {
        node37 = new PhaseNode_PlayEffect(37, phase);
        node37->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node37->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node37->setEffectID(210312);
        node37->setChangeColor(false);
        node37->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node37->getVars().reserve(3);
        node37->getVars().setVariable<float>(0, .00f);
        node37->getVars().setVariable<float>(1, .00f);
        node37->getVars().setVariable<float>(2, .00f);
        node37->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(21031, 37, node37)
    }
    if (noInit == true) {
        return node37;
    }
    auto node43 = GET_SKILL_NODE(43, PhaseNode_OffsetCalculate);
    if (node43 != nullptr) node37->getVars().setVariable<float>(0, node43->getOutPosX());
    if (node43 != nullptr) node37->getVars().setVariable<float>(1, node43->getOutPosY());
    if (node43 != nullptr) node37->getVars().setVariable<float>(2, node43->getOutPosZ());
    if (node43 != nullptr) node37->setRotation(node43->getOutRotation());
    return node37;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(21031, 38) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnProjectile>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 18, PhaseNode_SpawnProjectile::FUNC_DO, &PhaseNode_SpawnProjectile::Do);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_LESS, 39, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_SpawnProjectile>(PhaseNode_CompareFloat::TRIGGER_LESS, 18, PhaseNode_SpawnProjectile::FUNC_DO, &PhaseNode_SpawnProjectile::Do);
}

REGISTER_CREATE_SKILL_NODE(21031, 38) {
    auto node38 = GET_SKILL_NODE(38, PhaseNode_CompareFloat);
    if (node38 == nullptr) {
        node38 = new PhaseNode_CompareFloat(38, phase);
        node38->setA(.00f);
        node38->setB(.00f);
        CALL_REGISTER_SKILL_NODE(21031, 38, node38)
    }
    if (noInit == true) {
        return node38;
    }
    return node38;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(21031, 39) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StopEffect>(PhaseNode_Delay::TRIGGER_DONE, 40, PhaseNode_StopEffect::FUNC_DO, &PhaseNode_StopEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(21031, 39) {
    auto node39 = GET_SKILL_NODE(39, PhaseNode_Delay);
    if (node39 == nullptr) {
        node39 = new PhaseNode_Delay(39, phase);
        node39->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(21031, 39, node39)
    }
    if (noInit == true) {
        return node39;
    }
    return node39;
}
//--------------------------------------------------------------------------------
// StopEffect
//
REGISTER_REGISTER_SKILL_NODE(21031, 40) {
}

REGISTER_CREATE_SKILL_NODE(21031, 40) {
    auto node40 = GET_SKILL_NODE(40, PhaseNode_StopEffect);
    if (node40 == nullptr) {
        node40 = new PhaseNode_StopEffect(40, phase);
        node40->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node40->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node40->setEffectID(210312);
        CALL_REGISTER_SKILL_NODE(21031, 40, node40)
    }
    if (noInit == true) {
        return node40;
    }
    return node40;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(21031, 41) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetRotation>(PhaseNode_GetLocation::TRIGGER_DONE, 42, PhaseNode_GetRotation::FUNC_DO, &PhaseNode_GetRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(21031, 41) {
    auto node41 = GET_SKILL_NODE(41, PhaseNode_GetLocation);
    if (node41 == nullptr) {
        node41 = new PhaseNode_GetLocation(41, phase);
        node41->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node41->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(21031, 41, node41)
    }
    if (noInit == true) {
        return node41;
    }
    return node41;
}
//--------------------------------------------------------------------------------
// GetRotation
//
REGISTER_REGISTER_SKILL_NODE(21031, 42) {
    pnode->resizeTrigger(PhaseNode_GetRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_OffsetCalculate>(PhaseNode_GetRotation::TRIGGER_DONE, 43, PhaseNode_OffsetCalculate::FUNC_DO, &PhaseNode_OffsetCalculate::Do);
}

REGISTER_CREATE_SKILL_NODE(21031, 42) {
    auto node42 = GET_SKILL_NODE(42, PhaseNode_GetRotation);
    if (node42 == nullptr) {
        node42 = new PhaseNode_GetRotation(42, phase);
        node42->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node42->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(21031, 42, node42)
    }
    if (noInit == true) {
        return node42;
    }
    return node42;
}
//--------------------------------------------------------------------------------
// OffsetCalculate
//
REGISTER_REGISTER_SKILL_NODE(21031, 43) {
    pnode->resizeTrigger(PhaseNode_OffsetCalculate::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 36, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(21031, 43) {
    auto node43 = GET_SKILL_NODE(43, PhaseNode_OffsetCalculate);
    if (node43 == nullptr) {
        node43 = new PhaseNode_OffsetCalculate(43, phase);
        node43->setPosZ(.00f);
        node43->setOffsetX(.00f);
        node43->setOffsetY(1.20f);
        node43->setOffsetZ(1.60f);
        node43->setRotOffset(.00f);
        CALL_REGISTER_SKILL_NODE(21031, 43, node43)
    }
    if (noInit == true) {
        return node43;
    }
    auto node41 = GET_SKILL_NODE(41, PhaseNode_GetLocation);
    auto node42 = GET_SKILL_NODE(42, PhaseNode_GetRotation);
    if (node41 != nullptr) node43->setPosX(node41->getX());
    if (node41 != nullptr) node43->setPosY(node41->getY());
    if (node42 != nullptr) node43->setRotation(node42->getAngle());
    return node43;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(21031, 44) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_ResetCD::TRIGGER_DONE, 45, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(21031, 44) {
    auto node44 = GET_SKILL_NODE(44, PhaseNode_ResetCD);
    if (node44 == nullptr) {
        node44 = new PhaseNode_ResetCD(44, phase);
        node44->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node44->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node44->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(21031, 44, node44)
    }
    if (noInit == true) {
        return node44;
    }
    return node44;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(21031, 45) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_PlayAnimation::TRIGGER_DONE, 46, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(21031, 45) {
    auto node45 = GET_SKILL_NODE(45, PhaseNode_PlayAnimation);
    if (node45 == nullptr) {
        node45 = new PhaseNode_PlayAnimation(45, phase);
        node45->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node45->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node45->setTarget(0U);
        node45->setAnimation("Skill1S1");
        node45->setParameter("");
        node45->setValue(false);
        CALL_REGISTER_SKILL_NODE(21031, 45, node45)
    }
    if (noInit == true) {
        return node45;
    }
    return node45;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(21031, 46) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlaySound::TRIGGER_DONE, 47, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(21031, 46) {
    auto node46 = GET_SKILL_NODE(46, PhaseNode_PlaySound);
    if (node46 == nullptr) {
        node46 = new PhaseNode_PlaySound(46, phase);
        node46->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node46->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node46->setSoundID("SE_MON2103_ATK");
        node46->setTarget(0U);
        node46->setUsePos(false);
        node46->setPosX(.00f);
        node46->setPosY(.00f);
        node46->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(21031, 46, node46)
    }
    if (noInit == true) {
        return node46;
    }
    return node46;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(21031, 47) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_Delay::TRIGGER_DONE, 41, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(21031, 47) {
    auto node47 = GET_SKILL_NODE(47, PhaseNode_Delay);
    if (node47 == nullptr) {
        node47 = new PhaseNode_Delay(47, phase);
        node47->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(21031, 47, node47)
    }
    if (noInit == true) {
        return node47;
    }
    return node47;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(21031, 48) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_Delay::TRIGGER_DONE, 50, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(21031, 48) {
    auto node48 = GET_SKILL_NODE(48, PhaseNode_Delay);
    if (node48 == nullptr) {
        node48 = new PhaseNode_Delay(48, phase);
        node48->setTime(.20f);
        CALL_REGISTER_SKILL_NODE(21031, 48, node48)
    }
    if (noInit == true) {
        return node48;
    }
    return node48;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(21031, 49) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 20, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(21031, 49) {
    auto node49 = GET_SKILL_NODE(49, PhaseNode_SkillEndNotify);
    if (node49 == nullptr) {
        node49 = new PhaseNode_SkillEndNotify(49, phase);
        node49->setReturnType(false);
        CALL_REGISTER_SKILL_NODE(21031, 49, node49)
    }
    if (noInit == true) {
        return node49;
    }
    return node49;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(21031, 50) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_FALSE, 51, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_TRUE, 49, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
}

REGISTER_CREATE_SKILL_NODE(21031, 50) {
    auto node50 = GET_SKILL_NODE(50, PhaseNode_If);
    if (node50 == nullptr) {
        node50 = new PhaseNode_If(50, phase);
        node50->setCondition(false);
        CALL_REGISTER_SKILL_NODE(21031, 50, node50)
    }
    if (noInit == true) {
        return node50;
    }
    return node50;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(21031, 51) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 20, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(21031, 51) {
    auto node51 = GET_SKILL_NODE(51, PhaseNode_SkillEndNotify);
    if (node51 == nullptr) {
        node51 = new PhaseNode_SkillEndNotify(51, phase);
        node51->setReturnType(true);
        CALL_REGISTER_SKILL_NODE(21031, 51, node51)
    }
    if (noInit == true) {
        return node51;
    }
    return node51;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(21031, 52) {
}

REGISTER_CREATE_SKILL_NODE(21031, 52) {
    auto node52 = GET_SKILL_NODE(52, PhaseNode_RaiseEvent);
    if (node52 == nullptr) {
        node52 = new PhaseNode_RaiseEvent(52, phase);
        node52->setEvent("MonsterInterrupt");
        node52->setTarget(0U);
        node52->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node52->setTypeParams(0, 0);
        node52->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(21031, 52, node52)
    }
    if (noInit == true) {
        return node52;
    }
    return node52;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(21031, 53) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_Detect::TRIGGER_ON, 56, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(21031, 53) {
    auto node53 = GET_SKILL_NODE(53, PhaseNode_Detect);
    if (node53 == nullptr) {
        node53 = new PhaseNode_Detect(53, phase);
        node53->setSelf(0U);
        node53->setEvent("MonsterInterrupt");
        node53->setType(PhaseNode_Detect::Detect_Type::Interrupt_Skill);
        node53->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(21031, 53, node53)
    }
    if (noInit == true) {
        return node53;
    }
    return node53;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(21031, 54) {
}

REGISTER_CREATE_SKILL_NODE(21031, 54) {
    auto node54 = GET_SKILL_NODE(54, PhaseNode_EndPhase);
    if (node54 == nullptr) {
        node54 = new PhaseNode_EndPhase(54, phase);
        node54->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node54->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(21031, 54, node54)
    }
    if (noInit == true) {
        return node54;
    }
    return node54;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(21031, 56) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_Delay::TRIGGER_DONE, 58, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(21031, 56) {
    auto node56 = GET_SKILL_NODE(56, PhaseNode_Delay);
    if (node56 == nullptr) {
        node56 = new PhaseNode_Delay(56, phase);
        node56->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(21031, 56, node56)
    }
    if (noInit == true) {
        return node56;
    }
    return node56;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(21031, 57) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 54, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(21031, 57) {
    auto node57 = GET_SKILL_NODE(57, PhaseNode_SkillEndNotify);
    if (node57 == nullptr) {
        node57 = new PhaseNode_SkillEndNotify(57, phase);
        node57->setReturnType(false);
        CALL_REGISTER_SKILL_NODE(21031, 57, node57)
    }
    if (noInit == true) {
        return node57;
    }
    return node57;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(21031, 58) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_FALSE, 59, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_TRUE, 57, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
}

REGISTER_CREATE_SKILL_NODE(21031, 58) {
    auto node58 = GET_SKILL_NODE(58, PhaseNode_If);
    if (node58 == nullptr) {
        node58 = new PhaseNode_If(58, phase);
        node58->setCondition(false);
        CALL_REGISTER_SKILL_NODE(21031, 58, node58)
    }
    if (noInit == true) {
        return node58;
    }
    return node58;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(21031, 59) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 54, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(21031, 59) {
    auto node59 = GET_SKILL_NODE(59, PhaseNode_SkillEndNotify);
    if (node59 == nullptr) {
        node59 = new PhaseNode_SkillEndNotify(59, phase);
        node59->setReturnType(true);
        CALL_REGISTER_SKILL_NODE(21031, 59, node59)
    }
    if (noInit == true) {
        return node59;
    }
    return node59;
}

//--------------------------------------------------------------------------------
// SkillCreator_21031
//
class SkillCreator_21031 : public SkillCreator {
public:
    SkillCreator_21031() {}
    virtual ~SkillCreator_21031() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_21031

//--------------------------------------------------------------------------------
// SkillPhase_21031
//
class SkillPhase_21031 : public SkillPhase {
public:
    SkillPhase_21031(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_21031() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(21031, 2) // StartPhase
        CASE_CREATE_SKILL_NODE(21031, 4) // TriggerUpdate
        CASE_CREATE_SKILL_NODE(21031, 18) // SpawnProjectile
        CASE_CREATE_SKILL_NODE(21031, 20) // EndPhase
        CASE_CREATE_SKILL_NODE(21031, 27) // Detect
        CASE_CREATE_SKILL_NODE(21031, 29) // EndPhase
        CASE_CREATE_SKILL_NODE(21031, 35) // PlayEffect
        CASE_CREATE_SKILL_NODE(21031, 36) // If
        CASE_CREATE_SKILL_NODE(21031, 37) // PlayEffect
        CASE_CREATE_SKILL_NODE(21031, 38) // CompareFloat
        CASE_CREATE_SKILL_NODE(21031, 39) // Delay
        CASE_CREATE_SKILL_NODE(21031, 40) // StopEffect
        CASE_CREATE_SKILL_NODE(21031, 41) // GetLocation
        CASE_CREATE_SKILL_NODE(21031, 42) // GetRotation
        CASE_CREATE_SKILL_NODE(21031, 43) // OffsetCalculate
        CASE_CREATE_SKILL_NODE(21031, 44) // ResetCD
        CASE_CREATE_SKILL_NODE(21031, 45) // PlayAnimation
        CASE_CREATE_SKILL_NODE(21031, 46) // PlaySound
        CASE_CREATE_SKILL_NODE(21031, 47) // Delay
        CASE_CREATE_SKILL_NODE(21031, 48) // Delay
        CASE_CREATE_SKILL_NODE(21031, 49) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(21031, 50) // If
        CASE_CREATE_SKILL_NODE(21031, 51) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(21031, 52) // RaiseEvent
        CASE_CREATE_SKILL_NODE(21031, 53) // Detect
        CASE_CREATE_SKILL_NODE(21031, 54) // EndPhase
        CASE_CREATE_SKILL_NODE(21031, 56) // Delay
        CASE_CREATE_SKILL_NODE(21031, 57) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(21031, 58) // If
        CASE_CREATE_SKILL_NODE(21031, 59) // SkillEndNotify
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_21031

SkillLogic* SkillCreator_21031::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //创建阶段phase
    auto phase = new SkillPhase_21031(1, logic, 3);
    //设置phase执行器
    phase->setRunPhaseNode(1, 2);
    phase->setRunPhaseNode(2, 4);
    phase->setDetectPhaseNode(3, 27);
    phase->setDetectPhaseNode(3, 53);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_21031::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
