#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

#include "skill_psnode_comparefloat.h"
#include "skill_psnode_delay.h"
#include "skill_psnode_destroyactor.h"
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
REGISTER_REGISTER_SKILL_NODE(20051, 6) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_StartPhase::TRIGGER_START, 281, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_StartPhase::TRIGGER_START, 261, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(20051, 6) {
    auto node6 = GET_SKILL_NODE(6, PhaseNode_StartPhase);
    if (node6 == nullptr) {
        node6 = new PhaseNode_StartPhase(6, phase);
        CALL_REGISTER_SKILL_NODE(20051, 6, node6)
    }
    if (noInit == true) {
        return node6;
    }
    return node6;
}
//--------------------------------------------------------------------------------
// TriggerUpdate
//
REGISTER_REGISTER_SKILL_NODE(20051, 8) {
}

REGISTER_CREATE_SKILL_NODE(20051, 8) {
    auto node8 = GET_SKILL_NODE(8, PhaseNode_TriggerUpdate);
    if (node8 == nullptr) {
        node8 = new PhaseNode_TriggerUpdate(8, phase);
        CALL_REGISTER_SKILL_NODE(20051, 8, node8)
    }
    if (noInit == true) {
        return node8;
    }
    return node8;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(20051, 247) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_Delay::TRIGGER_DONE, 265, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(20051, 247) {
    auto node247 = GET_SKILL_NODE(247, PhaseNode_Delay);
    if (node247 == nullptr) {
        node247 = new PhaseNode_Delay(247, phase);
        node247->setTime(.50f);
        CALL_REGISTER_SKILL_NODE(20051, 247, node247)
    }
    if (noInit == true) {
        return node247;
    }
    return node247;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(20051, 248) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnProjectile>(PhaseNode_Delay::TRIGGER_DONE, 258, PhaseNode_SpawnProjectile::FUNC_DO, &PhaseNode_SpawnProjectile::Do);
}

REGISTER_CREATE_SKILL_NODE(20051, 248) {
    auto node248 = GET_SKILL_NODE(248, PhaseNode_Delay);
    if (node248 == nullptr) {
        node248 = new PhaseNode_Delay(248, phase);
        node248->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(20051, 248, node248)
    }
    if (noInit == true) {
        return node248;
    }
    return node248;
}
//--------------------------------------------------------------------------------
// DestroyActor
//
REGISTER_REGISTER_SKILL_NODE(20051, 249) {
    pnode->resizeTrigger(PhaseNode_DestroyActor::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_DestroyActor::TRIGGER_DONE, 268, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(20051, 249) {
    auto node249 = GET_SKILL_NODE(249, PhaseNode_DestroyActor);
    if (node249 == nullptr) {
        node249 = new PhaseNode_DestroyActor(249, phase);
        node249->setActorID(0U);
        CALL_REGISTER_SKILL_NODE(20051, 249, node249)
    }
    if (noInit == true) {
        return node249;
    }
    return node249;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(20051, 250) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlaySound::TRIGGER_DONE, 248, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(20051, 250) {
    auto node250 = GET_SKILL_NODE(250, PhaseNode_PlaySound);
    if (node250 == nullptr) {
        node250 = new PhaseNode_PlaySound(250, phase);
        node250->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node250->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node250->setSoundID("");
        node250->setTarget(0U);
        node250->setUsePos(false);
        node250->setPosX(.00f);
        node250->setPosY(.00f);
        node250->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(20051, 250, node250)
    }
    if (noInit == true) {
        return node250;
    }
    return node250;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(20051, 251) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_Detect::TRIGGER_ON, 252, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(20051, 251) {
    auto node251 = GET_SKILL_NODE(251, PhaseNode_Detect);
    if (node251 == nullptr) {
        node251 = new PhaseNode_Detect(251, phase);
        node251->setSelf(0U);
        node251->setEvent("");
        node251->setType(PhaseNode_Detect::Detect_Type::Actor_Dead);
        node251->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(20051, 251, node251)
    }
    if (noInit == true) {
        return node251;
    }
    return node251;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(20051, 252) {
}

REGISTER_CREATE_SKILL_NODE(20051, 252) {
    auto node252 = GET_SKILL_NODE(252, PhaseNode_EndPhase);
    if (node252 == nullptr) {
        node252 = new PhaseNode_EndPhase(252, phase);
        node252->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node252->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(20051, 252, node252)
    }
    if (noInit == true) {
        return node252;
    }
    return node252;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(20051, 253) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_Delay::TRIGGER_DONE, 278, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(20051, 253) {
    auto node253 = GET_SKILL_NODE(253, PhaseNode_Delay);
    if (node253 == nullptr) {
        node253 = new PhaseNode_Delay(253, phase);
        node253->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(20051, 253, node253)
    }
    if (noInit == true) {
        return node253;
    }
    return node253;
}
//--------------------------------------------------------------------------------
// SpawnProjectile
//
REGISTER_REGISTER_SKILL_NODE(20051, 258) {
    pnode->resizeTrigger(PhaseNode_SpawnProjectile::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_DestroyActor>(PhaseNode_SpawnProjectile::TRIGGER_DONE, 249, PhaseNode_DestroyActor::FUNC_DO, &PhaseNode_DestroyActor::Do);
}

REGISTER_CREATE_SKILL_NODE(20051, 258) {
    auto node258 = GET_SKILL_NODE(258, PhaseNode_SpawnProjectile);
    if (node258 == nullptr) {
        node258 = new PhaseNode_SpawnProjectile(258, phase);
        node258->setDataId(52005);
        node258->setEndPosX(.00f);
        node258->setEndPosY(.00f);
        node258->setEndPosZ(.00f);
        node258->setMaxCount(0);
        CALL_REGISTER_SKILL_NODE(20051, 258, node258)
    }
    if (noInit == true) {
        return node258;
    }
    auto node267 = GET_SKILL_NODE(267, PhaseNode_OffsetCalculate);
    if (node267 != nullptr) node258->setPosX(node267->getOutPosX());
    if (node267 != nullptr) node258->setPosY(node267->getOutPosY());
    if (node267 != nullptr) node258->setPosZ(node267->getOutPosZ());
    if (node267 != nullptr) node258->setRotation(node267->getOutRotation());
    return node258;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(20051, 261) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_ResetCD::TRIGGER_DONE, 262, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(20051, 261) {
    auto node261 = GET_SKILL_NODE(261, PhaseNode_ResetCD);
    if (node261 == nullptr) {
        node261 = new PhaseNode_ResetCD(261, phase);
        node261->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node261->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node261->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(20051, 261, node261)
    }
    if (noInit == true) {
        return node261;
    }
    return node261;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(20051, 262) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_PlayAnimation::TRIGGER_DONE, 263, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(20051, 262) {
    auto node262 = GET_SKILL_NODE(262, PhaseNode_PlayAnimation);
    if (node262 == nullptr) {
        node262 = new PhaseNode_PlayAnimation(262, phase);
        node262->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node262->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node262->setTarget(0U);
        node262->setAnimation("Skill1S1");
        node262->setParameter("");
        node262->setValue(false);
        CALL_REGISTER_SKILL_NODE(20051, 262, node262)
    }
    if (noInit == true) {
        return node262;
    }
    return node262;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(20051, 263) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlaySound::TRIGGER_DONE, 264, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(20051, 263) {
    auto node263 = GET_SKILL_NODE(263, PhaseNode_PlaySound);
    if (node263 == nullptr) {
        node263 = new PhaseNode_PlaySound(263, phase);
        node263->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node263->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node263->setSoundID("");
        node263->setTarget(0U);
        node263->setUsePos(false);
        node263->setPosX(.00f);
        node263->setPosY(.00f);
        node263->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(20051, 263, node263)
    }
    if (noInit == true) {
        return node263;
    }
    return node263;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(20051, 264) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_Delay::TRIGGER_DONE, 247, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_Delay::TRIGGER_DONE, 253, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(20051, 264) {
    auto node264 = GET_SKILL_NODE(264, PhaseNode_Delay);
    if (node264 == nullptr) {
        node264 = new PhaseNode_Delay(264, phase);
        node264->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(20051, 264, node264)
    }
    if (noInit == true) {
        return node264;
    }
    return node264;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(20051, 265) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetRotation>(PhaseNode_GetLocation::TRIGGER_DONE, 266, PhaseNode_GetRotation::FUNC_DO, &PhaseNode_GetRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(20051, 265) {
    auto node265 = GET_SKILL_NODE(265, PhaseNode_GetLocation);
    if (node265 == nullptr) {
        node265 = new PhaseNode_GetLocation(265, phase);
        node265->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node265->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(20051, 265, node265)
    }
    if (noInit == true) {
        return node265;
    }
    return node265;
}
//--------------------------------------------------------------------------------
// GetRotation
//
REGISTER_REGISTER_SKILL_NODE(20051, 266) {
    pnode->resizeTrigger(PhaseNode_GetRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_OffsetCalculate>(PhaseNode_GetRotation::TRIGGER_DONE, 267, PhaseNode_OffsetCalculate::FUNC_DO, &PhaseNode_OffsetCalculate::Do);
}

REGISTER_CREATE_SKILL_NODE(20051, 266) {
    auto node266 = GET_SKILL_NODE(266, PhaseNode_GetRotation);
    if (node266 == nullptr) {
        node266 = new PhaseNode_GetRotation(266, phase);
        node266->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node266->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(20051, 266, node266)
    }
    if (noInit == true) {
        return node266;
    }
    return node266;
}
//--------------------------------------------------------------------------------
// OffsetCalculate
//
REGISTER_REGISTER_SKILL_NODE(20051, 267) {
    pnode->resizeTrigger(PhaseNode_OffsetCalculate::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 250, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(20051, 267) {
    auto node267 = GET_SKILL_NODE(267, PhaseNode_OffsetCalculate);
    if (node267 == nullptr) {
        node267 = new PhaseNode_OffsetCalculate(267, phase);
        node267->setPosZ(.00f);
        node267->setOffsetX(.00f);
        node267->setOffsetY(.00f);
        node267->setOffsetZ(.00f);
        node267->setRotOffset(.00f);
        CALL_REGISTER_SKILL_NODE(20051, 267, node267)
    }
    if (noInit == true) {
        return node267;
    }
    auto node265 = GET_SKILL_NODE(265, PhaseNode_GetLocation);
    auto node266 = GET_SKILL_NODE(266, PhaseNode_GetRotation);
    if (node265 != nullptr) node267->setPosX(node265->getX());
    if (node265 != nullptr) node267->setPosY(node265->getY());
    if (node266 != nullptr) node267->setRotation(node266->getAngle());
    return node267;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(20051, 268) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_Delay::TRIGGER_DONE, 270, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(20051, 268) {
    auto node268 = GET_SKILL_NODE(268, PhaseNode_Delay);
    if (node268 == nullptr) {
        node268 = new PhaseNode_Delay(268, phase);
        node268->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(20051, 268, node268)
    }
    if (noInit == true) {
        return node268;
    }
    return node268;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(20051, 269) {
}

REGISTER_CREATE_SKILL_NODE(20051, 269) {
    auto node269 = GET_SKILL_NODE(269, PhaseNode_SkillEndNotify);
    if (node269 == nullptr) {
        node269 = new PhaseNode_SkillEndNotify(269, phase);
        node269->setReturnType(false);
        CALL_REGISTER_SKILL_NODE(20051, 269, node269)
    }
    if (noInit == true) {
        return node269;
    }
    return node269;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(20051, 270) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_FALSE, 271, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_TRUE, 269, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
}

REGISTER_CREATE_SKILL_NODE(20051, 270) {
    auto node270 = GET_SKILL_NODE(270, PhaseNode_If);
    if (node270 == nullptr) {
        node270 = new PhaseNode_If(270, phase);
        node270->setCondition(false);
        CALL_REGISTER_SKILL_NODE(20051, 270, node270)
    }
    if (noInit == true) {
        return node270;
    }
    return node270;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(20051, 271) {
}

REGISTER_CREATE_SKILL_NODE(20051, 271) {
    auto node271 = GET_SKILL_NODE(271, PhaseNode_SkillEndNotify);
    if (node271 == nullptr) {
        node271 = new PhaseNode_SkillEndNotify(271, phase);
        node271->setReturnType(true);
        CALL_REGISTER_SKILL_NODE(20051, 271, node271)
    }
    if (noInit == true) {
        return node271;
    }
    return node271;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(20051, 272) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_PlayEffect::TRIGGER_DONE, 275, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(20051, 272) {
    auto node272 = GET_SKILL_NODE(272, PhaseNode_PlayEffect);
    if (node272 == nullptr) {
        node272 = new PhaseNode_PlayEffect(272, phase);
        node272->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node272->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node272->setEffectID(1014);
        node272->setChangeColor(false);
        node272->setType(PhaseNode_PlayEffect::PlayEffect_Type::WithTarget);
        node272->getVars().reserve(5);
        node272->getVars().setVariable<uint64_t>(0, 0U);
        node272->getVars().setVariable<std::string>(1, "");
        node272->getVars().setVariable<float>(2, .00f);
        node272->getVars().setVariable<float>(3, .00f);
        node272->getVars().setVariable<float>(4, .00f);
        node272->setScale(1.50f);
        CALL_REGISTER_SKILL_NODE(20051, 272, node272)
    }
    if (noInit == true) {
        return node272;
    }
    auto node280 = GET_SKILL_NODE(280, PhaseNode_OffsetCalculate);
    if (node280 != nullptr) node272->getVars().setVariable<float>(2, node280->getOutPosX());
    if (node280 != nullptr) node272->getVars().setVariable<float>(3, node280->getOutPosY());
    if (node280 != nullptr) node272->getVars().setVariable<float>(4, node280->getOutPosZ());
    if (node280 != nullptr) node272->setRotation(node280->getOutRotation());
    return node272;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(20051, 273) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_FALSE, 274, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_TRUE, 272, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(20051, 273) {
    auto node273 = GET_SKILL_NODE(273, PhaseNode_If);
    if (node273 == nullptr) {
        node273 = new PhaseNode_If(273, phase);
        node273->setCondition(false);
        CALL_REGISTER_SKILL_NODE(20051, 273, node273)
    }
    if (noInit == true) {
        return node273;
    }
    return node273;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(20051, 274) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_PlayEffect::TRIGGER_DONE, 275, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(20051, 274) {
    auto node274 = GET_SKILL_NODE(274, PhaseNode_PlayEffect);
    if (node274 == nullptr) {
        node274 = new PhaseNode_PlayEffect(274, phase);
        node274->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node274->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node274->setEffectID(1014);
        node274->setChangeColor(false);
        node274->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node274->getVars().reserve(3);
        node274->getVars().setVariable<float>(0, .00f);
        node274->getVars().setVariable<float>(1, .00f);
        node274->getVars().setVariable<float>(2, .00f);
        node274->setScale(1.50f);
        CALL_REGISTER_SKILL_NODE(20051, 274, node274)
    }
    if (noInit == true) {
        return node274;
    }
    auto node280 = GET_SKILL_NODE(280, PhaseNode_OffsetCalculate);
    if (node280 != nullptr) node274->getVars().setVariable<float>(0, node280->getOutPosX());
    if (node280 != nullptr) node274->getVars().setVariable<float>(1, node280->getOutPosY());
    if (node280 != nullptr) node274->getVars().setVariable<float>(2, node280->getOutPosZ());
    if (node280 != nullptr) node274->setRotation(node280->getOutRotation());
    return node274;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(20051, 275) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_LESS, 276, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(20051, 275) {
    auto node275 = GET_SKILL_NODE(275, PhaseNode_CompareFloat);
    if (node275 == nullptr) {
        node275 = new PhaseNode_CompareFloat(275, phase);
        node275->setA(.00f);
        node275->setB(.50f);
        CALL_REGISTER_SKILL_NODE(20051, 275, node275)
    }
    if (noInit == true) {
        return node275;
    }
    return node275;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(20051, 276) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StopEffect>(PhaseNode_Delay::TRIGGER_DONE, 277, PhaseNode_StopEffect::FUNC_DO, &PhaseNode_StopEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(20051, 276) {
    auto node276 = GET_SKILL_NODE(276, PhaseNode_Delay);
    if (node276 == nullptr) {
        node276 = new PhaseNode_Delay(276, phase);
        node276->setTime(.50f);
        CALL_REGISTER_SKILL_NODE(20051, 276, node276)
    }
    if (noInit == true) {
        return node276;
    }
    return node276;
}
//--------------------------------------------------------------------------------
// StopEffect
//
REGISTER_REGISTER_SKILL_NODE(20051, 277) {
}

REGISTER_CREATE_SKILL_NODE(20051, 277) {
    auto node277 = GET_SKILL_NODE(277, PhaseNode_StopEffect);
    if (node277 == nullptr) {
        node277 = new PhaseNode_StopEffect(277, phase);
        node277->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node277->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node277->setEffectID(1014);
        CALL_REGISTER_SKILL_NODE(20051, 277, node277)
    }
    if (noInit == true) {
        return node277;
    }
    return node277;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(20051, 278) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetRotation>(PhaseNode_GetLocation::TRIGGER_DONE, 279, PhaseNode_GetRotation::FUNC_DO, &PhaseNode_GetRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(20051, 278) {
    auto node278 = GET_SKILL_NODE(278, PhaseNode_GetLocation);
    if (node278 == nullptr) {
        node278 = new PhaseNode_GetLocation(278, phase);
        node278->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node278->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(20051, 278, node278)
    }
    if (noInit == true) {
        return node278;
    }
    return node278;
}
//--------------------------------------------------------------------------------
// GetRotation
//
REGISTER_REGISTER_SKILL_NODE(20051, 279) {
    pnode->resizeTrigger(PhaseNode_GetRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_OffsetCalculate>(PhaseNode_GetRotation::TRIGGER_DONE, 280, PhaseNode_OffsetCalculate::FUNC_DO, &PhaseNode_OffsetCalculate::Do);
}

REGISTER_CREATE_SKILL_NODE(20051, 279) {
    auto node279 = GET_SKILL_NODE(279, PhaseNode_GetRotation);
    if (node279 == nullptr) {
        node279 = new PhaseNode_GetRotation(279, phase);
        node279->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node279->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(20051, 279, node279)
    }
    if (noInit == true) {
        return node279;
    }
    return node279;
}
//--------------------------------------------------------------------------------
// OffsetCalculate
//
REGISTER_REGISTER_SKILL_NODE(20051, 280) {
    pnode->resizeTrigger(PhaseNode_OffsetCalculate::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 273, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(20051, 280) {
    auto node280 = GET_SKILL_NODE(280, PhaseNode_OffsetCalculate);
    if (node280 == nullptr) {
        node280 = new PhaseNode_OffsetCalculate(280, phase);
        node280->setPosZ(.00f);
        node280->setOffsetX(.00f);
        node280->setOffsetY(.00f);
        node280->setOffsetZ(.00f);
        node280->setRotOffset(.00f);
        CALL_REGISTER_SKILL_NODE(20051, 280, node280)
    }
    if (noInit == true) {
        return node280;
    }
    auto node278 = GET_SKILL_NODE(278, PhaseNode_GetLocation);
    auto node279 = GET_SKILL_NODE(279, PhaseNode_GetRotation);
    if (node278 != nullptr) node280->setPosX(node278->getX());
    if (node278 != nullptr) node280->setPosY(node278->getY());
    if (node279 != nullptr) node280->setRotation(node279->getAngle());
    return node280;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(20051, 281) {
}

REGISTER_CREATE_SKILL_NODE(20051, 281) {
    auto node281 = GET_SKILL_NODE(281, PhaseNode_RaiseEvent);
    if (node281 == nullptr) {
        node281 = new PhaseNode_RaiseEvent(281, phase);
        node281->setEvent("MonsterInterrupt");
        node281->setTarget(0U);
        node281->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node281->setTypeParams(0, 0);
        node281->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(20051, 281, node281)
    }
    if (noInit == true) {
        return node281;
    }
    return node281;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(20051, 282) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_Detect::TRIGGER_ON, 285, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(20051, 282) {
    auto node282 = GET_SKILL_NODE(282, PhaseNode_Detect);
    if (node282 == nullptr) {
        node282 = new PhaseNode_Detect(282, phase);
        node282->setSelf(0U);
        node282->setEvent("MonsterInterrupt");
        node282->setType(PhaseNode_Detect::Detect_Type::Interrupt_Skill);
        node282->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(20051, 282, node282)
    }
    if (noInit == true) {
        return node282;
    }
    return node282;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(20051, 283) {
}

REGISTER_CREATE_SKILL_NODE(20051, 283) {
    auto node283 = GET_SKILL_NODE(283, PhaseNode_EndPhase);
    if (node283 == nullptr) {
        node283 = new PhaseNode_EndPhase(283, phase);
        node283->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node283->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(20051, 283, node283)
    }
    if (noInit == true) {
        return node283;
    }
    return node283;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(20051, 285) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_Delay::TRIGGER_DONE, 287, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(20051, 285) {
    auto node285 = GET_SKILL_NODE(285, PhaseNode_Delay);
    if (node285 == nullptr) {
        node285 = new PhaseNode_Delay(285, phase);
        node285->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(20051, 285, node285)
    }
    if (noInit == true) {
        return node285;
    }
    return node285;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(20051, 286) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 283, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(20051, 286) {
    auto node286 = GET_SKILL_NODE(286, PhaseNode_SkillEndNotify);
    if (node286 == nullptr) {
        node286 = new PhaseNode_SkillEndNotify(286, phase);
        node286->setReturnType(false);
        CALL_REGISTER_SKILL_NODE(20051, 286, node286)
    }
    if (noInit == true) {
        return node286;
    }
    return node286;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(20051, 287) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_FALSE, 288, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_TRUE, 286, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
}

REGISTER_CREATE_SKILL_NODE(20051, 287) {
    auto node287 = GET_SKILL_NODE(287, PhaseNode_If);
    if (node287 == nullptr) {
        node287 = new PhaseNode_If(287, phase);
        node287->setCondition(false);
        CALL_REGISTER_SKILL_NODE(20051, 287, node287)
    }
    if (noInit == true) {
        return node287;
    }
    return node287;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(20051, 288) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 283, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(20051, 288) {
    auto node288 = GET_SKILL_NODE(288, PhaseNode_SkillEndNotify);
    if (node288 == nullptr) {
        node288 = new PhaseNode_SkillEndNotify(288, phase);
        node288->setReturnType(true);
        CALL_REGISTER_SKILL_NODE(20051, 288, node288)
    }
    if (noInit == true) {
        return node288;
    }
    return node288;
}

//--------------------------------------------------------------------------------
// SkillCreator_20051
//
class SkillCreator_20051 : public SkillCreator {
public:
    SkillCreator_20051() {}
    virtual ~SkillCreator_20051() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_20051

//--------------------------------------------------------------------------------
// SkillPhase_20051
//
class SkillPhase_20051 : public SkillPhase {
public:
    SkillPhase_20051(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_20051() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(20051, 6) // StartPhase
        CASE_CREATE_SKILL_NODE(20051, 8) // TriggerUpdate
        CASE_CREATE_SKILL_NODE(20051, 247) // Delay
        CASE_CREATE_SKILL_NODE(20051, 248) // Delay
        CASE_CREATE_SKILL_NODE(20051, 249) // DestroyActor
        CASE_CREATE_SKILL_NODE(20051, 250) // PlaySound
        CASE_CREATE_SKILL_NODE(20051, 251) // Detect
        CASE_CREATE_SKILL_NODE(20051, 252) // EndPhase
        CASE_CREATE_SKILL_NODE(20051, 253) // Delay
        CASE_CREATE_SKILL_NODE(20051, 258) // SpawnProjectile
        CASE_CREATE_SKILL_NODE(20051, 261) // ResetCD
        CASE_CREATE_SKILL_NODE(20051, 262) // PlayAnimation
        CASE_CREATE_SKILL_NODE(20051, 263) // PlaySound
        CASE_CREATE_SKILL_NODE(20051, 264) // Delay
        CASE_CREATE_SKILL_NODE(20051, 265) // GetLocation
        CASE_CREATE_SKILL_NODE(20051, 266) // GetRotation
        CASE_CREATE_SKILL_NODE(20051, 267) // OffsetCalculate
        CASE_CREATE_SKILL_NODE(20051, 268) // Delay
        CASE_CREATE_SKILL_NODE(20051, 269) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(20051, 270) // If
        CASE_CREATE_SKILL_NODE(20051, 271) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(20051, 272) // PlayEffect
        CASE_CREATE_SKILL_NODE(20051, 273) // If
        CASE_CREATE_SKILL_NODE(20051, 274) // PlayEffect
        CASE_CREATE_SKILL_NODE(20051, 275) // CompareFloat
        CASE_CREATE_SKILL_NODE(20051, 276) // Delay
        CASE_CREATE_SKILL_NODE(20051, 277) // StopEffect
        CASE_CREATE_SKILL_NODE(20051, 278) // GetLocation
        CASE_CREATE_SKILL_NODE(20051, 279) // GetRotation
        CASE_CREATE_SKILL_NODE(20051, 280) // OffsetCalculate
        CASE_CREATE_SKILL_NODE(20051, 281) // RaiseEvent
        CASE_CREATE_SKILL_NODE(20051, 282) // Detect
        CASE_CREATE_SKILL_NODE(20051, 283) // EndPhase
        CASE_CREATE_SKILL_NODE(20051, 285) // Delay
        CASE_CREATE_SKILL_NODE(20051, 286) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(20051, 287) // If
        CASE_CREATE_SKILL_NODE(20051, 288) // SkillEndNotify
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_20051

SkillLogic* SkillCreator_20051::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //创建阶段phase
    auto phase = new SkillPhase_20051(1, logic, 3);
    //设置phase执行器
    phase->setRunPhaseNode(1, 6);
    phase->setRunPhaseNode(2, 8);
    phase->setDetectPhaseNode(3, 251);
    phase->setDetectPhaseNode(3, 282);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_20051::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
