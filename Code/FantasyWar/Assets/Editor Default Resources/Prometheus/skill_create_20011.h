#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

#include "skill_psnode_comparefloat.h"
#include "skill_psnode_delay.h"
#include "skill_psnode_detect.h"
#include "skill_psnode_endphase.h"
#include "skill_psnode_getbbparamuint64.h"
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
REGISTER_REGISTER_SKILL_NODE(20011, 1) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_StartPhase::TRIGGER_START, 505, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_StartPhase::TRIGGER_START, 488, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(20011, 1) {
    auto node1 = GET_SKILL_NODE(1, PhaseNode_StartPhase);
    if (node1 == nullptr) {
        node1 = new PhaseNode_StartPhase(1, phase);
        CALL_REGISTER_SKILL_NODE(20011, 1, node1)
    }
    if (noInit == true) {
        return node1;
    }
    return node1;
}
//--------------------------------------------------------------------------------
// TriggerUpdate
//
REGISTER_REGISTER_SKILL_NODE(20011, 5) {
}

REGISTER_CREATE_SKILL_NODE(20011, 5) {
    auto node5 = GET_SKILL_NODE(5, PhaseNode_TriggerUpdate);
    if (node5 == nullptr) {
        node5 = new PhaseNode_TriggerUpdate(5, phase);
        CALL_REGISTER_SKILL_NODE(20011, 5, node5)
    }
    if (noInit == true) {
        return node5;
    }
    return node5;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(20011, 52) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_Detect::TRIGGER_ON, 53, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(20011, 52) {
    auto node52 = GET_SKILL_NODE(52, PhaseNode_Detect);
    if (node52 == nullptr) {
        node52 = new PhaseNode_Detect(52, phase);
        node52->setSelf(0U);
        node52->setEvent("");
        node52->setType(PhaseNode_Detect::Detect_Type::Actor_Dead);
        node52->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(20011, 52, node52)
    }
    if (noInit == true) {
        return node52;
    }
    return node52;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(20011, 53) {
}

REGISTER_CREATE_SKILL_NODE(20011, 53) {
    auto node53 = GET_SKILL_NODE(53, PhaseNode_EndPhase);
    if (node53 == nullptr) {
        node53 = new PhaseNode_EndPhase(53, phase);
        node53->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node53->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(20011, 53, node53)
    }
    if (noInit == true) {
        return node53;
    }
    return node53;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(20011, 462) {
}

REGISTER_CREATE_SKILL_NODE(20011, 462) {
    auto node462 = GET_SKILL_NODE(462, PhaseNode_EndPhase);
    if (node462 == nullptr) {
        node462 = new PhaseNode_EndPhase(462, phase);
        node462->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node462->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(20011, 462, node462)
    }
    if (noInit == true) {
        return node462;
    }
    return node462;
}
//--------------------------------------------------------------------------------
// SpawnProjectile
//
REGISTER_REGISTER_SKILL_NODE(20011, 480) {
    pnode->resizeTrigger(PhaseNode_SpawnProjectile::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_SpawnProjectile::TRIGGER_DONE, 501, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(20011, 480) {
    auto node480 = GET_SKILL_NODE(480, PhaseNode_SpawnProjectile);
    if (node480 == nullptr) {
        node480 = new PhaseNode_SpawnProjectile(480, phase);
        node480->setDataId(52001);
        node480->setEndPosZ(.00f);
        node480->setMaxCount(0);
        CALL_REGISTER_SKILL_NODE(20011, 480, node480)
    }
    if (noInit == true) {
        return node480;
    }
    auto node494 = GET_SKILL_NODE(494, PhaseNode_OffsetCalculate);
    auto node487 = GET_SKILL_NODE(487, PhaseNode_GetLocation);
    if (node494 != nullptr) node480->setPosX(node494->getOutPosX());
    if (node494 != nullptr) node480->setPosY(node494->getOutPosY());
    if (node494 != nullptr) node480->setPosZ(node494->getOutPosZ());
    if (node487 != nullptr) node480->setEndPosX(node487->getX());
    if (node487 != nullptr) node480->setEndPosY(node487->getY());
    if (node494 != nullptr) node480->setRotation(node494->getOutRotation());
    return node480;
}
//--------------------------------------------------------------------------------
// GetBBParamUInt64
//
REGISTER_REGISTER_SKILL_NODE(20011, 486) {
    pnode->resizeTrigger(PhaseNode_GetBBParamUInt64::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_GetBBParamUInt64::TRIGGER_DONE, 487, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(20011, 486) {
    auto node486 = GET_SKILL_NODE(486, PhaseNode_GetBBParamUInt64);
    if (node486 == nullptr) {
        node486 = new PhaseNode_GetBBParamUInt64(486, phase);
        node486->setBBName("AtkTarget");
        CALL_REGISTER_SKILL_NODE(20011, 486, node486)
    }
    if (noInit == true) {
        return node486;
    }
    return node486;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(20011, 487) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnProjectile>(PhaseNode_GetLocation::TRIGGER_DONE, 480, PhaseNode_SpawnProjectile::FUNC_DO, &PhaseNode_SpawnProjectile::Do);
}

REGISTER_CREATE_SKILL_NODE(20011, 487) {
    auto node487 = GET_SKILL_NODE(487, PhaseNode_GetLocation);
    if (node487 == nullptr) {
        node487 = new PhaseNode_GetLocation(487, phase);
        node487->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        CALL_REGISTER_SKILL_NODE(20011, 487, node487)
    }
    if (noInit == true) {
        return node487;
    }
    auto node486 = GET_SKILL_NODE(486, PhaseNode_GetBBParamUInt64);
    if (node486 != nullptr) node487->setTarget(node486->getValue());
    return node487;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(20011, 488) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_ResetCD::TRIGGER_DONE, 489, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(20011, 488) {
    auto node488 = GET_SKILL_NODE(488, PhaseNode_ResetCD);
    if (node488 == nullptr) {
        node488 = new PhaseNode_ResetCD(488, phase);
        node488->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node488->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node488->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(20011, 488, node488)
    }
    if (noInit == true) {
        return node488;
    }
    return node488;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(20011, 489) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_PlayAnimation::TRIGGER_DONE, 490, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(20011, 489) {
    auto node489 = GET_SKILL_NODE(489, PhaseNode_PlayAnimation);
    if (node489 == nullptr) {
        node489 = new PhaseNode_PlayAnimation(489, phase);
        node489->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node489->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node489->setTarget(0U);
        node489->setAnimation("Skill1S1");
        node489->setParameter("");
        node489->setValue(false);
        CALL_REGISTER_SKILL_NODE(20011, 489, node489)
    }
    if (noInit == true) {
        return node489;
    }
    return node489;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(20011, 490) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlaySound::TRIGGER_DONE, 491, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(20011, 490) {
    auto node490 = GET_SKILL_NODE(490, PhaseNode_PlaySound);
    if (node490 == nullptr) {
        node490 = new PhaseNode_PlaySound(490, phase);
        node490->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node490->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node490->setSoundID("SE_MON_PenShiZhe_ATK_P1");
        node490->setTarget(0U);
        node490->setUsePos(false);
        node490->setPosX(.00f);
        node490->setPosY(.00f);
        node490->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(20011, 490, node490)
    }
    if (noInit == true) {
        return node490;
    }
    return node490;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(20011, 491) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_Delay::TRIGGER_DONE, 492, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(20011, 491) {
    auto node491 = GET_SKILL_NODE(491, PhaseNode_Delay);
    if (node491 == nullptr) {
        node491 = new PhaseNode_Delay(491, phase);
        node491->setTime(.30f);
        CALL_REGISTER_SKILL_NODE(20011, 491, node491)
    }
    if (noInit == true) {
        return node491;
    }
    return node491;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(20011, 492) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetRotation>(PhaseNode_GetLocation::TRIGGER_DONE, 493, PhaseNode_GetRotation::FUNC_DO, &PhaseNode_GetRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(20011, 492) {
    auto node492 = GET_SKILL_NODE(492, PhaseNode_GetLocation);
    if (node492 == nullptr) {
        node492 = new PhaseNode_GetLocation(492, phase);
        node492->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node492->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(20011, 492, node492)
    }
    if (noInit == true) {
        return node492;
    }
    return node492;
}
//--------------------------------------------------------------------------------
// GetRotation
//
REGISTER_REGISTER_SKILL_NODE(20011, 493) {
    pnode->resizeTrigger(PhaseNode_GetRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_OffsetCalculate>(PhaseNode_GetRotation::TRIGGER_DONE, 494, PhaseNode_OffsetCalculate::FUNC_DO, &PhaseNode_OffsetCalculate::Do);
}

REGISTER_CREATE_SKILL_NODE(20011, 493) {
    auto node493 = GET_SKILL_NODE(493, PhaseNode_GetRotation);
    if (node493 == nullptr) {
        node493 = new PhaseNode_GetRotation(493, phase);
        node493->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node493->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(20011, 493, node493)
    }
    if (noInit == true) {
        return node493;
    }
    return node493;
}
//--------------------------------------------------------------------------------
// OffsetCalculate
//
REGISTER_REGISTER_SKILL_NODE(20011, 494) {
    pnode->resizeTrigger(PhaseNode_OffsetCalculate::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 496, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(20011, 494) {
    auto node494 = GET_SKILL_NODE(494, PhaseNode_OffsetCalculate);
    if (node494 == nullptr) {
        node494 = new PhaseNode_OffsetCalculate(494, phase);
        node494->setPosZ(.00f);
        node494->setOffsetX(.00f);
        node494->setOffsetY(.50f);
        node494->setOffsetZ(1.60f);
        node494->setRotOffset(.00f);
        CALL_REGISTER_SKILL_NODE(20011, 494, node494)
    }
    if (noInit == true) {
        return node494;
    }
    auto node492 = GET_SKILL_NODE(492, PhaseNode_GetLocation);
    auto node493 = GET_SKILL_NODE(493, PhaseNode_GetRotation);
    if (node492 != nullptr) node494->setPosX(node492->getX());
    if (node492 != nullptr) node494->setPosY(node492->getY());
    if (node493 != nullptr) node494->setRotation(node493->getAngle());
    return node494;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(20011, 495) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_PlayEffect::TRIGGER_DONE, 498, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(20011, 495) {
    auto node495 = GET_SKILL_NODE(495, PhaseNode_PlayEffect);
    if (node495 == nullptr) {
        node495 = new PhaseNode_PlayEffect(495, phase);
        node495->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node495->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node495->setEffectID(0);
        node495->setChangeColor(false);
        node495->setType(PhaseNode_PlayEffect::PlayEffect_Type::WithTarget);
        node495->getVars().reserve(5);
        node495->getVars().setVariable<uint64_t>(0, 0U);
        node495->getVars().setVariable<std::string>(1, "");
        node495->getVars().setVariable<float>(2, .00f);
        node495->getVars().setVariable<float>(3, .00f);
        node495->getVars().setVariable<float>(4, .00f);
        node495->setScale(.00f);
        CALL_REGISTER_SKILL_NODE(20011, 495, node495)
    }
    if (noInit == true) {
        return node495;
    }
    auto node494 = GET_SKILL_NODE(494, PhaseNode_OffsetCalculate);
    if (node494 != nullptr) node495->getVars().setVariable<float>(2, node494->getOutPosX());
    if (node494 != nullptr) node495->getVars().setVariable<float>(3, node494->getOutPosY());
    if (node494 != nullptr) node495->getVars().setVariable<float>(4, node494->getOutPosZ());
    if (node494 != nullptr) node495->setRotation(node494->getOutRotation());
    return node495;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(20011, 496) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_FALSE, 497, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_TRUE, 495, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(20011, 496) {
    auto node496 = GET_SKILL_NODE(496, PhaseNode_If);
    if (node496 == nullptr) {
        node496 = new PhaseNode_If(496, phase);
        node496->setCondition(false);
        CALL_REGISTER_SKILL_NODE(20011, 496, node496)
    }
    if (noInit == true) {
        return node496;
    }
    return node496;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(20011, 497) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_PlayEffect::TRIGGER_DONE, 498, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(20011, 497) {
    auto node497 = GET_SKILL_NODE(497, PhaseNode_PlayEffect);
    if (node497 == nullptr) {
        node497 = new PhaseNode_PlayEffect(497, phase);
        node497->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node497->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node497->setEffectID(0);
        node497->setChangeColor(false);
        node497->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node497->getVars().reserve(3);
        node497->getVars().setVariable<float>(0, .00f);
        node497->getVars().setVariable<float>(1, .00f);
        node497->getVars().setVariable<float>(2, .00f);
        node497->setScale(.00f);
        CALL_REGISTER_SKILL_NODE(20011, 497, node497)
    }
    if (noInit == true) {
        return node497;
    }
    auto node494 = GET_SKILL_NODE(494, PhaseNode_OffsetCalculate);
    if (node494 != nullptr) node497->getVars().setVariable<float>(0, node494->getOutPosX());
    if (node494 != nullptr) node497->getVars().setVariable<float>(1, node494->getOutPosY());
    if (node494 != nullptr) node497->getVars().setVariable<float>(2, node494->getOutPosZ());
    if (node494 != nullptr) node497->setRotation(node494->getOutRotation());
    return node497;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(20011, 498) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetBBParamUInt64>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 486, PhaseNode_GetBBParamUInt64::FUNC_DO, &PhaseNode_GetBBParamUInt64::Do);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_LESS, 499, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_GetBBParamUInt64>(PhaseNode_CompareFloat::TRIGGER_LESS, 486, PhaseNode_GetBBParamUInt64::FUNC_DO, &PhaseNode_GetBBParamUInt64::Do);
}

REGISTER_CREATE_SKILL_NODE(20011, 498) {
    auto node498 = GET_SKILL_NODE(498, PhaseNode_CompareFloat);
    if (node498 == nullptr) {
        node498 = new PhaseNode_CompareFloat(498, phase);
        node498->setA(.00f);
        node498->setB(.00f);
        CALL_REGISTER_SKILL_NODE(20011, 498, node498)
    }
    if (noInit == true) {
        return node498;
    }
    return node498;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(20011, 499) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StopEffect>(PhaseNode_Delay::TRIGGER_DONE, 500, PhaseNode_StopEffect::FUNC_DO, &PhaseNode_StopEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(20011, 499) {
    auto node499 = GET_SKILL_NODE(499, PhaseNode_Delay);
    if (node499 == nullptr) {
        node499 = new PhaseNode_Delay(499, phase);
        node499->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(20011, 499, node499)
    }
    if (noInit == true) {
        return node499;
    }
    return node499;
}
//--------------------------------------------------------------------------------
// StopEffect
//
REGISTER_REGISTER_SKILL_NODE(20011, 500) {
}

REGISTER_CREATE_SKILL_NODE(20011, 500) {
    auto node500 = GET_SKILL_NODE(500, PhaseNode_StopEffect);
    if (node500 == nullptr) {
        node500 = new PhaseNode_StopEffect(500, phase);
        node500->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node500->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node500->setEffectID(0);
        CALL_REGISTER_SKILL_NODE(20011, 500, node500)
    }
    if (noInit == true) {
        return node500;
    }
    return node500;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(20011, 501) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_Delay::TRIGGER_DONE, 503, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(20011, 501) {
    auto node501 = GET_SKILL_NODE(501, PhaseNode_Delay);
    if (node501 == nullptr) {
        node501 = new PhaseNode_Delay(501, phase);
        node501->setTime(.50f);
        CALL_REGISTER_SKILL_NODE(20011, 501, node501)
    }
    if (noInit == true) {
        return node501;
    }
    return node501;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(20011, 502) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 462, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(20011, 502) {
    auto node502 = GET_SKILL_NODE(502, PhaseNode_SkillEndNotify);
    if (node502 == nullptr) {
        node502 = new PhaseNode_SkillEndNotify(502, phase);
        node502->setReturnType(false);
        CALL_REGISTER_SKILL_NODE(20011, 502, node502)
    }
    if (noInit == true) {
        return node502;
    }
    return node502;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(20011, 503) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_FALSE, 504, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_TRUE, 502, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
}

REGISTER_CREATE_SKILL_NODE(20011, 503) {
    auto node503 = GET_SKILL_NODE(503, PhaseNode_If);
    if (node503 == nullptr) {
        node503 = new PhaseNode_If(503, phase);
        node503->setCondition(false);
        CALL_REGISTER_SKILL_NODE(20011, 503, node503)
    }
    if (noInit == true) {
        return node503;
    }
    return node503;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(20011, 504) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 462, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(20011, 504) {
    auto node504 = GET_SKILL_NODE(504, PhaseNode_SkillEndNotify);
    if (node504 == nullptr) {
        node504 = new PhaseNode_SkillEndNotify(504, phase);
        node504->setReturnType(true);
        CALL_REGISTER_SKILL_NODE(20011, 504, node504)
    }
    if (noInit == true) {
        return node504;
    }
    return node504;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(20011, 505) {
}

REGISTER_CREATE_SKILL_NODE(20011, 505) {
    auto node505 = GET_SKILL_NODE(505, PhaseNode_RaiseEvent);
    if (node505 == nullptr) {
        node505 = new PhaseNode_RaiseEvent(505, phase);
        node505->setEvent("MonsterInterrupt");
        node505->setTarget(0U);
        node505->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node505->setTypeParams(0, 0);
        node505->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(20011, 505, node505)
    }
    if (noInit == true) {
        return node505;
    }
    return node505;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(20011, 506) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_Detect::TRIGGER_ON, 509, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(20011, 506) {
    auto node506 = GET_SKILL_NODE(506, PhaseNode_Detect);
    if (node506 == nullptr) {
        node506 = new PhaseNode_Detect(506, phase);
        node506->setSelf(0U);
        node506->setEvent("MonsterInterrupt");
        node506->setType(PhaseNode_Detect::Detect_Type::Interrupt_Skill);
        node506->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(20011, 506, node506)
    }
    if (noInit == true) {
        return node506;
    }
    return node506;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(20011, 507) {
}

REGISTER_CREATE_SKILL_NODE(20011, 507) {
    auto node507 = GET_SKILL_NODE(507, PhaseNode_EndPhase);
    if (node507 == nullptr) {
        node507 = new PhaseNode_EndPhase(507, phase);
        node507->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node507->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(20011, 507, node507)
    }
    if (noInit == true) {
        return node507;
    }
    return node507;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(20011, 509) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_Delay::TRIGGER_DONE, 511, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(20011, 509) {
    auto node509 = GET_SKILL_NODE(509, PhaseNode_Delay);
    if (node509 == nullptr) {
        node509 = new PhaseNode_Delay(509, phase);
        node509->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(20011, 509, node509)
    }
    if (noInit == true) {
        return node509;
    }
    return node509;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(20011, 510) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 507, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(20011, 510) {
    auto node510 = GET_SKILL_NODE(510, PhaseNode_SkillEndNotify);
    if (node510 == nullptr) {
        node510 = new PhaseNode_SkillEndNotify(510, phase);
        node510->setReturnType(false);
        CALL_REGISTER_SKILL_NODE(20011, 510, node510)
    }
    if (noInit == true) {
        return node510;
    }
    return node510;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(20011, 511) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_FALSE, 512, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_TRUE, 510, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
}

REGISTER_CREATE_SKILL_NODE(20011, 511) {
    auto node511 = GET_SKILL_NODE(511, PhaseNode_If);
    if (node511 == nullptr) {
        node511 = new PhaseNode_If(511, phase);
        node511->setCondition(false);
        CALL_REGISTER_SKILL_NODE(20011, 511, node511)
    }
    if (noInit == true) {
        return node511;
    }
    return node511;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(20011, 512) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 507, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(20011, 512) {
    auto node512 = GET_SKILL_NODE(512, PhaseNode_SkillEndNotify);
    if (node512 == nullptr) {
        node512 = new PhaseNode_SkillEndNotify(512, phase);
        node512->setReturnType(true);
        CALL_REGISTER_SKILL_NODE(20011, 512, node512)
    }
    if (noInit == true) {
        return node512;
    }
    return node512;
}

//--------------------------------------------------------------------------------
// SkillCreator_20011
//
class SkillCreator_20011 : public SkillCreator {
public:
    SkillCreator_20011() {}
    virtual ~SkillCreator_20011() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_20011

//--------------------------------------------------------------------------------
// SkillPhase_20011
//
class SkillPhase_20011 : public SkillPhase {
public:
    SkillPhase_20011(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_20011() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(20011, 1) // StartPhase
        CASE_CREATE_SKILL_NODE(20011, 5) // TriggerUpdate
        CASE_CREATE_SKILL_NODE(20011, 52) // Detect
        CASE_CREATE_SKILL_NODE(20011, 53) // EndPhase
        CASE_CREATE_SKILL_NODE(20011, 462) // EndPhase
        CASE_CREATE_SKILL_NODE(20011, 480) // SpawnProjectile
        CASE_CREATE_SKILL_NODE(20011, 486) // GetBBParamUInt64
        CASE_CREATE_SKILL_NODE(20011, 487) // GetLocation
        CASE_CREATE_SKILL_NODE(20011, 488) // ResetCD
        CASE_CREATE_SKILL_NODE(20011, 489) // PlayAnimation
        CASE_CREATE_SKILL_NODE(20011, 490) // PlaySound
        CASE_CREATE_SKILL_NODE(20011, 491) // Delay
        CASE_CREATE_SKILL_NODE(20011, 492) // GetLocation
        CASE_CREATE_SKILL_NODE(20011, 493) // GetRotation
        CASE_CREATE_SKILL_NODE(20011, 494) // OffsetCalculate
        CASE_CREATE_SKILL_NODE(20011, 495) // PlayEffect
        CASE_CREATE_SKILL_NODE(20011, 496) // If
        CASE_CREATE_SKILL_NODE(20011, 497) // PlayEffect
        CASE_CREATE_SKILL_NODE(20011, 498) // CompareFloat
        CASE_CREATE_SKILL_NODE(20011, 499) // Delay
        CASE_CREATE_SKILL_NODE(20011, 500) // StopEffect
        CASE_CREATE_SKILL_NODE(20011, 501) // Delay
        CASE_CREATE_SKILL_NODE(20011, 502) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(20011, 503) // If
        CASE_CREATE_SKILL_NODE(20011, 504) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(20011, 505) // RaiseEvent
        CASE_CREATE_SKILL_NODE(20011, 506) // Detect
        CASE_CREATE_SKILL_NODE(20011, 507) // EndPhase
        CASE_CREATE_SKILL_NODE(20011, 509) // Delay
        CASE_CREATE_SKILL_NODE(20011, 510) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(20011, 511) // If
        CASE_CREATE_SKILL_NODE(20011, 512) // SkillEndNotify
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_20011

SkillLogic* SkillCreator_20011::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //创建阶段phase
    auto phase = new SkillPhase_20011(1, logic, 3);
    //设置phase执行器
    phase->setRunPhaseNode(1, 1);
    phase->setRunPhaseNode(2, 5);
    phase->setDetectPhaseNode(3, 52);
    phase->setDetectPhaseNode(3, 506);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_20011::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
