#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

#include "skill_psnode_comparefloat.h"
#include "skill_psnode_delay.h"
#include "skill_psnode_detect.h"
#include "skill_psnode_endphase.h"
#include "skill_psnode_for.h"
#include "skill_psnode_forcontinue.h"
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
REGISTER_REGISTER_SKILL_NODE(21063, 2) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_StartPhase::TRIGGER_START, 303, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_StartPhase::TRIGGER_START, 286, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(21063, 2) {
    auto node2 = GET_SKILL_NODE(2, PhaseNode_StartPhase);
    if (node2 == nullptr) {
        node2 = new PhaseNode_StartPhase(2, phase);
        CALL_REGISTER_SKILL_NODE(21063, 2, node2)
    }
    if (noInit == true) {
        return node2;
    }
    return node2;
}
//--------------------------------------------------------------------------------
// TriggerUpdate
//
REGISTER_REGISTER_SKILL_NODE(21063, 4) {
}

REGISTER_CREATE_SKILL_NODE(21063, 4) {
    auto node4 = GET_SKILL_NODE(4, PhaseNode_TriggerUpdate);
    if (node4 == nullptr) {
        node4 = new PhaseNode_TriggerUpdate(4, phase);
        CALL_REGISTER_SKILL_NODE(21063, 4, node4)
    }
    if (noInit == true) {
        return node4;
    }
    return node4;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(21063, 23) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_Delay::TRIGGER_DONE, 290, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(21063, 23) {
    auto node23 = GET_SKILL_NODE(23, PhaseNode_Delay);
    if (node23 == nullptr) {
        node23 = new PhaseNode_Delay(23, phase);
        node23->setTime(.50f);
        CALL_REGISTER_SKILL_NODE(21063, 23, node23)
    }
    if (noInit == true) {
        return node23;
    }
    return node23;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(21063, 46) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_PlayAnimation::TRIGGER_DONE, 261, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(21063, 46) {
    auto node46 = GET_SKILL_NODE(46, PhaseNode_PlayAnimation);
    if (node46 == nullptr) {
        node46 = new PhaseNode_PlayAnimation(46, phase);
        node46->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node46->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node46->setTarget(0U);
        node46->setAnimation("Skill3S2");
        node46->setParameter("");
        node46->setValue(false);
        CALL_REGISTER_SKILL_NODE(21063, 46, node46)
    }
    if (noInit == true) {
        return node46;
    }
    return node46;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(21063, 48) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ForContinue>(PhaseNode_Delay::TRIGGER_DONE, 50, PhaseNode_ForContinue::FUNC_DO, &PhaseNode_ForContinue::Do);
}

REGISTER_CREATE_SKILL_NODE(21063, 48) {
    auto node48 = GET_SKILL_NODE(48, PhaseNode_Delay);
    if (node48 == nullptr) {
        node48 = new PhaseNode_Delay(48, phase);
        node48->setTime(.60f);
        CALL_REGISTER_SKILL_NODE(21063, 48, node48)
    }
    if (noInit == true) {
        return node48;
    }
    return node48;
}
//--------------------------------------------------------------------------------
// ForContinue
//
REGISTER_REGISTER_SKILL_NODE(21063, 50) {
}

REGISTER_CREATE_SKILL_NODE(21063, 50) {
    auto node50 = GET_SKILL_NODE(50, PhaseNode_ForContinue);
    if (node50 == nullptr) {
        node50 = new PhaseNode_ForContinue(50, phase);
        CALL_REGISTER_SKILL_NODE(21063, 50, node50)
    }
    if (noInit == true) {
        return node50;
    }
    auto node219 = GET_SKILL_NODE(219, PhaseNode_For);
    if (node219 != nullptr) node50->setFID(node219->getFID());
    return node50;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(21063, 54) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlayAnimation::TRIGGER_DONE, 299, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(21063, 54) {
    auto node54 = GET_SKILL_NODE(54, PhaseNode_PlayAnimation);
    if (node54 == nullptr) {
        node54 = new PhaseNode_PlayAnimation(54, phase);
        node54->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node54->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node54->setTarget(0U);
        node54->setAnimation("Skill3S3");
        node54->setParameter("");
        node54->setValue(false);
        CALL_REGISTER_SKILL_NODE(21063, 54, node54)
    }
    if (noInit == true) {
        return node54;
    }
    return node54;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(21063, 58) {
}

REGISTER_CREATE_SKILL_NODE(21063, 58) {
    auto node58 = GET_SKILL_NODE(58, PhaseNode_EndPhase);
    if (node58 == nullptr) {
        node58 = new PhaseNode_EndPhase(58, phase);
        node58->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node58->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(21063, 58, node58)
    }
    if (noInit == true) {
        return node58;
    }
    return node58;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(21063, 60) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_Detect::TRIGGER_ON, 62, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(21063, 60) {
    auto node60 = GET_SKILL_NODE(60, PhaseNode_Detect);
    if (node60 == nullptr) {
        node60 = new PhaseNode_Detect(60, phase);
        node60->setSelf(0U);
        node60->setEvent("");
        node60->setType(PhaseNode_Detect::Detect_Type::Actor_Dead);
        node60->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(21063, 60, node60)
    }
    if (noInit == true) {
        return node60;
    }
    return node60;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(21063, 62) {
}

REGISTER_CREATE_SKILL_NODE(21063, 62) {
    auto node62 = GET_SKILL_NODE(62, PhaseNode_EndPhase);
    if (node62 == nullptr) {
        node62 = new PhaseNode_EndPhase(62, phase);
        node62->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node62->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(21063, 62, node62)
    }
    if (noInit == true) {
        return node62;
    }
    return node62;
}
//--------------------------------------------------------------------------------
// SpawnProjectile
//
REGISTER_REGISTER_SKILL_NODE(21063, 217) {
    pnode->resizeTrigger(PhaseNode_SpawnProjectile::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_SpawnProjectile::TRIGGER_DONE, 48, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(21063, 217) {
    auto node217 = GET_SKILL_NODE(217, PhaseNode_SpawnProjectile);
    if (node217 == nullptr) {
        node217 = new PhaseNode_SpawnProjectile(217, phase);
        node217->setDataId(52107);
        node217->setEndPosZ(.00f);
        node217->setMaxCount(0);
        CALL_REGISTER_SKILL_NODE(21063, 217, node217)
    }
    if (noInit == true) {
        return node217;
    }
    auto node292 = GET_SKILL_NODE(292, PhaseNode_OffsetCalculate);
    auto node285 = GET_SKILL_NODE(285, PhaseNode_GetLocation);
    if (node292 != nullptr) node217->setPosX(node292->getOutPosX());
    if (node292 != nullptr) node217->setPosY(node292->getOutPosY());
    if (node292 != nullptr) node217->setPosZ(node292->getOutPosZ());
    if (node285 != nullptr) node217->setEndPosX(node285->getX());
    if (node285 != nullptr) node217->setEndPosY(node285->getY());
    if (node292 != nullptr) node217->setRotation(node292->getOutRotation());
    return node217;
}
//--------------------------------------------------------------------------------
// For
//
REGISTER_REGISTER_SKILL_NODE(21063, 219) {
    pnode->resizeTrigger(PhaseNode_For::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_For::TRIGGER_DO, 273, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_For::TRIGGER_DONE, 54, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(21063, 219) {
    auto node219 = GET_SKILL_NODE(219, PhaseNode_For);
    if (node219 == nullptr) {
        node219 = new PhaseNode_For(219, phase);
        node219->setBegin(0);
        node219->setIncrease(1);
        node219->setEnd(3);
        CALL_REGISTER_SKILL_NODE(21063, 219, node219)
    }
    if (noInit == true) {
        return node219;
    }
    return node219;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(21063, 240) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnProjectile>(PhaseNode_Delay::TRIGGER_DONE, 217, PhaseNode_SpawnProjectile::FUNC_DO, &PhaseNode_SpawnProjectile::Do);
}

REGISTER_CREATE_SKILL_NODE(21063, 240) {
    auto node240 = GET_SKILL_NODE(240, PhaseNode_Delay);
    if (node240 == nullptr) {
        node240 = new PhaseNode_Delay(240, phase);
        node240->setTime(.20f);
        CALL_REGISTER_SKILL_NODE(21063, 240, node240)
    }
    if (noInit == true) {
        return node240;
    }
    return node240;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(21063, 261) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_PlaySound::TRIGGER_DONE, 294, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(21063, 261) {
    auto node261 = GET_SKILL_NODE(261, PhaseNode_PlaySound);
    if (node261 == nullptr) {
        node261 = new PhaseNode_PlaySound(261, phase);
        node261->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node261->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node261->setSoundID("SE_Boss2106_ATK2");
        node261->setTarget(0U);
        node261->setUsePos(false);
        node261->setPosX(.00f);
        node261->setPosY(.00f);
        node261->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(21063, 261, node261)
    }
    if (noInit == true) {
        return node261;
    }
    return node261;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(21063, 273) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_PlayAnimation::TRIGGER_DONE, 46, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(21063, 273) {
    auto node273 = GET_SKILL_NODE(273, PhaseNode_PlayAnimation);
    if (node273 == nullptr) {
        node273 = new PhaseNode_PlayAnimation(273, phase);
        node273->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node273->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node273->setTarget(0U);
        node273->setAnimation("Idle");
        node273->setParameter("");
        node273->setValue(false);
        CALL_REGISTER_SKILL_NODE(21063, 273, node273)
    }
    if (noInit == true) {
        return node273;
    }
    return node273;
}
//--------------------------------------------------------------------------------
// GetBBParamUInt64
//
REGISTER_REGISTER_SKILL_NODE(21063, 283) {
    pnode->resizeTrigger(PhaseNode_GetBBParamUInt64::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_GetBBParamUInt64::TRIGGER_DONE, 285, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(21063, 283) {
    auto node283 = GET_SKILL_NODE(283, PhaseNode_GetBBParamUInt64);
    if (node283 == nullptr) {
        node283 = new PhaseNode_GetBBParamUInt64(283, phase);
        node283->setBBName("AtkTarget");
        CALL_REGISTER_SKILL_NODE(21063, 283, node283)
    }
    if (noInit == true) {
        return node283;
    }
    return node283;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(21063, 285) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_GetLocation::TRIGGER_DONE, 240, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(21063, 285) {
    auto node285 = GET_SKILL_NODE(285, PhaseNode_GetLocation);
    if (node285 == nullptr) {
        node285 = new PhaseNode_GetLocation(285, phase);
        node285->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        CALL_REGISTER_SKILL_NODE(21063, 285, node285)
    }
    if (noInit == true) {
        return node285;
    }
    auto node283 = GET_SKILL_NODE(283, PhaseNode_GetBBParamUInt64);
    if (node283 != nullptr) node285->setTarget(node283->getValue());
    return node285;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(21063, 286) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_ResetCD::TRIGGER_DONE, 287, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(21063, 286) {
    auto node286 = GET_SKILL_NODE(286, PhaseNode_ResetCD);
    if (node286 == nullptr) {
        node286 = new PhaseNode_ResetCD(286, phase);
        node286->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node286->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node286->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(21063, 286, node286)
    }
    if (noInit == true) {
        return node286;
    }
    return node286;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(21063, 287) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_PlayAnimation::TRIGGER_DONE, 288, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(21063, 287) {
    auto node287 = GET_SKILL_NODE(287, PhaseNode_PlayAnimation);
    if (node287 == nullptr) {
        node287 = new PhaseNode_PlayAnimation(287, phase);
        node287->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node287->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node287->setTarget(0U);
        node287->setAnimation("Skill3S1");
        node287->setParameter("");
        node287->setValue(false);
        CALL_REGISTER_SKILL_NODE(21063, 287, node287)
    }
    if (noInit == true) {
        return node287;
    }
    return node287;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(21063, 288) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlaySound::TRIGGER_DONE, 289, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(21063, 288) {
    auto node288 = GET_SKILL_NODE(288, PhaseNode_PlaySound);
    if (node288 == nullptr) {
        node288 = new PhaseNode_PlaySound(288, phase);
        node288->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node288->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node288->setSoundID("");
        node288->setTarget(0U);
        node288->setUsePos(false);
        node288->setPosX(.00f);
        node288->setPosY(.00f);
        node288->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(21063, 288, node288)
    }
    if (noInit == true) {
        return node288;
    }
    return node288;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(21063, 289) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_Delay::TRIGGER_DONE, 23, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(21063, 289) {
    auto node289 = GET_SKILL_NODE(289, PhaseNode_Delay);
    if (node289 == nullptr) {
        node289 = new PhaseNode_Delay(289, phase);
        node289->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(21063, 289, node289)
    }
    if (noInit == true) {
        return node289;
    }
    return node289;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(21063, 290) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetRotation>(PhaseNode_GetLocation::TRIGGER_DONE, 291, PhaseNode_GetRotation::FUNC_DO, &PhaseNode_GetRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(21063, 290) {
    auto node290 = GET_SKILL_NODE(290, PhaseNode_GetLocation);
    if (node290 == nullptr) {
        node290 = new PhaseNode_GetLocation(290, phase);
        node290->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node290->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(21063, 290, node290)
    }
    if (noInit == true) {
        return node290;
    }
    return node290;
}
//--------------------------------------------------------------------------------
// GetRotation
//
REGISTER_REGISTER_SKILL_NODE(21063, 291) {
    pnode->resizeTrigger(PhaseNode_GetRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_OffsetCalculate>(PhaseNode_GetRotation::TRIGGER_DONE, 292, PhaseNode_OffsetCalculate::FUNC_DO, &PhaseNode_OffsetCalculate::Do);
}

REGISTER_CREATE_SKILL_NODE(21063, 291) {
    auto node291 = GET_SKILL_NODE(291, PhaseNode_GetRotation);
    if (node291 == nullptr) {
        node291 = new PhaseNode_GetRotation(291, phase);
        node291->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node291->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(21063, 291, node291)
    }
    if (noInit == true) {
        return node291;
    }
    return node291;
}
//--------------------------------------------------------------------------------
// OffsetCalculate
//
REGISTER_REGISTER_SKILL_NODE(21063, 292) {
    pnode->resizeTrigger(PhaseNode_OffsetCalculate::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_For>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 219, PhaseNode_For::FUNC_START, &PhaseNode_For::Start);
}

REGISTER_CREATE_SKILL_NODE(21063, 292) {
    auto node292 = GET_SKILL_NODE(292, PhaseNode_OffsetCalculate);
    if (node292 == nullptr) {
        node292 = new PhaseNode_OffsetCalculate(292, phase);
        node292->setPosZ(.00f);
        node292->setOffsetX(.90f);
        node292->setOffsetY(-.50f);
        node292->setOffsetZ(3.20f);
        node292->setRotOffset(.00f);
        CALL_REGISTER_SKILL_NODE(21063, 292, node292)
    }
    if (noInit == true) {
        return node292;
    }
    auto node290 = GET_SKILL_NODE(290, PhaseNode_GetLocation);
    auto node291 = GET_SKILL_NODE(291, PhaseNode_GetRotation);
    if (node290 != nullptr) node292->setPosX(node290->getX());
    if (node290 != nullptr) node292->setPosY(node290->getY());
    if (node291 != nullptr) node292->setRotation(node291->getAngle());
    return node292;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(21063, 293) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_PlayEffect::TRIGGER_DONE, 296, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(21063, 293) {
    auto node293 = GET_SKILL_NODE(293, PhaseNode_PlayEffect);
    if (node293 == nullptr) {
        node293 = new PhaseNode_PlayEffect(293, phase);
        node293->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node293->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node293->setEffectID(210631);
        node293->setChangeColor(false);
        node293->setType(PhaseNode_PlayEffect::PlayEffect_Type::WithTarget);
        node293->getVars().reserve(5);
        node293->getVars().setVariable<uint64_t>(0, 0U);
        node293->getVars().setVariable<std::string>(1, "");
        node293->getVars().setVariable<float>(2, .00f);
        node293->getVars().setVariable<float>(3, .00f);
        node293->getVars().setVariable<float>(4, .00f);
        node293->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(21063, 293, node293)
    }
    if (noInit == true) {
        return node293;
    }
    auto node292 = GET_SKILL_NODE(292, PhaseNode_OffsetCalculate);
    if (node292 != nullptr) node293->getVars().setVariable<float>(2, node292->getOutPosX());
    if (node292 != nullptr) node293->getVars().setVariable<float>(3, node292->getOutPosY());
    if (node292 != nullptr) node293->setRotation(node292->getOutRotation());
    return node293;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(21063, 294) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_FALSE, 295, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_TRUE, 293, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(21063, 294) {
    auto node294 = GET_SKILL_NODE(294, PhaseNode_If);
    if (node294 == nullptr) {
        node294 = new PhaseNode_If(294, phase);
        node294->setCondition(false);
        CALL_REGISTER_SKILL_NODE(21063, 294, node294)
    }
    if (noInit == true) {
        return node294;
    }
    return node294;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(21063, 295) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_PlayEffect::TRIGGER_DONE, 296, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(21063, 295) {
    auto node295 = GET_SKILL_NODE(295, PhaseNode_PlayEffect);
    if (node295 == nullptr) {
        node295 = new PhaseNode_PlayEffect(295, phase);
        node295->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node295->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node295->setEffectID(210631);
        node295->setChangeColor(false);
        node295->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node295->getVars().reserve(3);
        node295->getVars().setVariable<float>(0, .00f);
        node295->getVars().setVariable<float>(1, .00f);
        node295->getVars().setVariable<float>(2, .00f);
        node295->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(21063, 295, node295)
    }
    if (noInit == true) {
        return node295;
    }
    auto node292 = GET_SKILL_NODE(292, PhaseNode_OffsetCalculate);
    if (node292 != nullptr) node295->getVars().setVariable<float>(0, node292->getOutPosX());
    if (node292 != nullptr) node295->getVars().setVariable<float>(1, node292->getOutPosY());
    if (node292 != nullptr) node295->setRotation(node292->getOutRotation());
    return node295;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(21063, 296) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetBBParamUInt64>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 283, PhaseNode_GetBBParamUInt64::FUNC_DO, &PhaseNode_GetBBParamUInt64::Do);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_LESS, 297, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_GetBBParamUInt64>(PhaseNode_CompareFloat::TRIGGER_LESS, 283, PhaseNode_GetBBParamUInt64::FUNC_DO, &PhaseNode_GetBBParamUInt64::Do);
}

REGISTER_CREATE_SKILL_NODE(21063, 296) {
    auto node296 = GET_SKILL_NODE(296, PhaseNode_CompareFloat);
    if (node296 == nullptr) {
        node296 = new PhaseNode_CompareFloat(296, phase);
        node296->setA(.00f);
        node296->setB(.00f);
        CALL_REGISTER_SKILL_NODE(21063, 296, node296)
    }
    if (noInit == true) {
        return node296;
    }
    return node296;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(21063, 297) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StopEffect>(PhaseNode_Delay::TRIGGER_DONE, 298, PhaseNode_StopEffect::FUNC_DO, &PhaseNode_StopEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(21063, 297) {
    auto node297 = GET_SKILL_NODE(297, PhaseNode_Delay);
    if (node297 == nullptr) {
        node297 = new PhaseNode_Delay(297, phase);
        node297->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(21063, 297, node297)
    }
    if (noInit == true) {
        return node297;
    }
    return node297;
}
//--------------------------------------------------------------------------------
// StopEffect
//
REGISTER_REGISTER_SKILL_NODE(21063, 298) {
}

REGISTER_CREATE_SKILL_NODE(21063, 298) {
    auto node298 = GET_SKILL_NODE(298, PhaseNode_StopEffect);
    if (node298 == nullptr) {
        node298 = new PhaseNode_StopEffect(298, phase);
        node298->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node298->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node298->setEffectID(210631);
        CALL_REGISTER_SKILL_NODE(21063, 298, node298)
    }
    if (noInit == true) {
        return node298;
    }
    return node298;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(21063, 299) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_Delay::TRIGGER_DONE, 301, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(21063, 299) {
    auto node299 = GET_SKILL_NODE(299, PhaseNode_Delay);
    if (node299 == nullptr) {
        node299 = new PhaseNode_Delay(299, phase);
        node299->setTime(.50f);
        CALL_REGISTER_SKILL_NODE(21063, 299, node299)
    }
    if (noInit == true) {
        return node299;
    }
    return node299;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(21063, 300) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 58, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(21063, 300) {
    auto node300 = GET_SKILL_NODE(300, PhaseNode_SkillEndNotify);
    if (node300 == nullptr) {
        node300 = new PhaseNode_SkillEndNotify(300, phase);
        node300->setReturnType(false);
        CALL_REGISTER_SKILL_NODE(21063, 300, node300)
    }
    if (noInit == true) {
        return node300;
    }
    return node300;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(21063, 301) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_FALSE, 302, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_TRUE, 300, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
}

REGISTER_CREATE_SKILL_NODE(21063, 301) {
    auto node301 = GET_SKILL_NODE(301, PhaseNode_If);
    if (node301 == nullptr) {
        node301 = new PhaseNode_If(301, phase);
        node301->setCondition(false);
        CALL_REGISTER_SKILL_NODE(21063, 301, node301)
    }
    if (noInit == true) {
        return node301;
    }
    return node301;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(21063, 302) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 58, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(21063, 302) {
    auto node302 = GET_SKILL_NODE(302, PhaseNode_SkillEndNotify);
    if (node302 == nullptr) {
        node302 = new PhaseNode_SkillEndNotify(302, phase);
        node302->setReturnType(true);
        CALL_REGISTER_SKILL_NODE(21063, 302, node302)
    }
    if (noInit == true) {
        return node302;
    }
    return node302;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(21063, 303) {
}

REGISTER_CREATE_SKILL_NODE(21063, 303) {
    auto node303 = GET_SKILL_NODE(303, PhaseNode_RaiseEvent);
    if (node303 == nullptr) {
        node303 = new PhaseNode_RaiseEvent(303, phase);
        node303->setEvent("MonsterInterrupt");
        node303->setTarget(0U);
        node303->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node303->setTypeParams(0, 0);
        node303->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(21063, 303, node303)
    }
    if (noInit == true) {
        return node303;
    }
    return node303;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(21063, 304) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_Detect::TRIGGER_ON, 307, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(21063, 304) {
    auto node304 = GET_SKILL_NODE(304, PhaseNode_Detect);
    if (node304 == nullptr) {
        node304 = new PhaseNode_Detect(304, phase);
        node304->setSelf(0U);
        node304->setEvent("MonsterInterrupt");
        node304->setType(PhaseNode_Detect::Detect_Type::Interrupt_Skill);
        node304->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(21063, 304, node304)
    }
    if (noInit == true) {
        return node304;
    }
    return node304;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(21063, 305) {
}

REGISTER_CREATE_SKILL_NODE(21063, 305) {
    auto node305 = GET_SKILL_NODE(305, PhaseNode_EndPhase);
    if (node305 == nullptr) {
        node305 = new PhaseNode_EndPhase(305, phase);
        node305->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node305->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(21063, 305, node305)
    }
    if (noInit == true) {
        return node305;
    }
    return node305;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(21063, 307) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_Delay::TRIGGER_DONE, 309, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(21063, 307) {
    auto node307 = GET_SKILL_NODE(307, PhaseNode_Delay);
    if (node307 == nullptr) {
        node307 = new PhaseNode_Delay(307, phase);
        node307->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(21063, 307, node307)
    }
    if (noInit == true) {
        return node307;
    }
    return node307;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(21063, 308) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 305, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(21063, 308) {
    auto node308 = GET_SKILL_NODE(308, PhaseNode_SkillEndNotify);
    if (node308 == nullptr) {
        node308 = new PhaseNode_SkillEndNotify(308, phase);
        node308->setReturnType(false);
        CALL_REGISTER_SKILL_NODE(21063, 308, node308)
    }
    if (noInit == true) {
        return node308;
    }
    return node308;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(21063, 309) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_FALSE, 310, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_TRUE, 308, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
}

REGISTER_CREATE_SKILL_NODE(21063, 309) {
    auto node309 = GET_SKILL_NODE(309, PhaseNode_If);
    if (node309 == nullptr) {
        node309 = new PhaseNode_If(309, phase);
        node309->setCondition(false);
        CALL_REGISTER_SKILL_NODE(21063, 309, node309)
    }
    if (noInit == true) {
        return node309;
    }
    return node309;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(21063, 310) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 305, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(21063, 310) {
    auto node310 = GET_SKILL_NODE(310, PhaseNode_SkillEndNotify);
    if (node310 == nullptr) {
        node310 = new PhaseNode_SkillEndNotify(310, phase);
        node310->setReturnType(true);
        CALL_REGISTER_SKILL_NODE(21063, 310, node310)
    }
    if (noInit == true) {
        return node310;
    }
    return node310;
}

//--------------------------------------------------------------------------------
// SkillCreator_21063
//
class SkillCreator_21063 : public SkillCreator {
public:
    SkillCreator_21063() {}
    virtual ~SkillCreator_21063() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_21063

//--------------------------------------------------------------------------------
// SkillPhase_21063
//
class SkillPhase_21063 : public SkillPhase {
public:
    SkillPhase_21063(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_21063() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(21063, 2) // StartPhase
        CASE_CREATE_SKILL_NODE(21063, 4) // TriggerUpdate
        CASE_CREATE_SKILL_NODE(21063, 23) // Delay
        CASE_CREATE_SKILL_NODE(21063, 46) // PlayAnimation
        CASE_CREATE_SKILL_NODE(21063, 48) // Delay
        CASE_CREATE_SKILL_NODE(21063, 50) // ForContinue
        CASE_CREATE_SKILL_NODE(21063, 54) // PlayAnimation
        CASE_CREATE_SKILL_NODE(21063, 58) // EndPhase
        CASE_CREATE_SKILL_NODE(21063, 60) // Detect
        CASE_CREATE_SKILL_NODE(21063, 62) // EndPhase
        CASE_CREATE_SKILL_NODE(21063, 217) // SpawnProjectile
        CASE_CREATE_SKILL_NODE(21063, 219) // For
        CASE_CREATE_SKILL_NODE(21063, 240) // Delay
        CASE_CREATE_SKILL_NODE(21063, 261) // PlaySound
        CASE_CREATE_SKILL_NODE(21063, 273) // PlayAnimation
        CASE_CREATE_SKILL_NODE(21063, 283) // GetBBParamUInt64
        CASE_CREATE_SKILL_NODE(21063, 285) // GetLocation
        CASE_CREATE_SKILL_NODE(21063, 286) // ResetCD
        CASE_CREATE_SKILL_NODE(21063, 287) // PlayAnimation
        CASE_CREATE_SKILL_NODE(21063, 288) // PlaySound
        CASE_CREATE_SKILL_NODE(21063, 289) // Delay
        CASE_CREATE_SKILL_NODE(21063, 290) // GetLocation
        CASE_CREATE_SKILL_NODE(21063, 291) // GetRotation
        CASE_CREATE_SKILL_NODE(21063, 292) // OffsetCalculate
        CASE_CREATE_SKILL_NODE(21063, 293) // PlayEffect
        CASE_CREATE_SKILL_NODE(21063, 294) // If
        CASE_CREATE_SKILL_NODE(21063, 295) // PlayEffect
        CASE_CREATE_SKILL_NODE(21063, 296) // CompareFloat
        CASE_CREATE_SKILL_NODE(21063, 297) // Delay
        CASE_CREATE_SKILL_NODE(21063, 298) // StopEffect
        CASE_CREATE_SKILL_NODE(21063, 299) // Delay
        CASE_CREATE_SKILL_NODE(21063, 300) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(21063, 301) // If
        CASE_CREATE_SKILL_NODE(21063, 302) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(21063, 303) // RaiseEvent
        CASE_CREATE_SKILL_NODE(21063, 304) // Detect
        CASE_CREATE_SKILL_NODE(21063, 305) // EndPhase
        CASE_CREATE_SKILL_NODE(21063, 307) // Delay
        CASE_CREATE_SKILL_NODE(21063, 308) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(21063, 309) // If
        CASE_CREATE_SKILL_NODE(21063, 310) // SkillEndNotify
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_21063

SkillLogic* SkillCreator_21063::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //创建阶段phase
    auto phase = new SkillPhase_21063(1, logic, 3);
    //设置phase执行器
    phase->setRunPhaseNode(1, 2);
    phase->setRunPhaseNode(2, 4);
    phase->setDetectPhaseNode(3, 60);
    phase->setDetectPhaseNode(3, 304);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_21063::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
