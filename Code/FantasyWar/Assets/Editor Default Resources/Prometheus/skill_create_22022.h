#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

#include "skill_psnode_actorfilternewpene.h"
#include "skill_psnode_addskillbuffs.h"
#include "skill_psnode_comparefloat.h"
#include "skill_psnode_createtriggernewpene.h"
#include "skill_psnode_delay.h"
#include "skill_psnode_detect.h"
#include "skill_psnode_endphase.h"
#include "skill_psnode_getactorattribute.h"
#include "skill_psnode_getlocation.h"
#include "skill_psnode_getrotation.h"
#include "skill_psnode_if.h"
#include "skill_psnode_offsetcalculate.h"
#include "skill_psnode_playanimation.h"
#include "skill_psnode_playeffect.h"
#include "skill_psnode_playsound.h"
#include "skill_psnode_raiseevent.h"
#include "skill_psnode_resetcd.h"
#include "skill_psnode_setlocation.h"
#include "skill_psnode_setuint64.h"
#include "skill_psnode_skillendnotify.h"
#include "skill_psnode_spawncollider.h"
#include "skill_psnode_startphase.h"
#include "skill_psnode_stopeffect.h"
#include "skill_psnode_stopsound.h"
#include "skill_psnode_triggercheck.h"
#include "skill_psnode_triggerupdate.h"

namespace pvp {

//变量声明
uint64_t Variable_22022_Gas = 0;
//--------------------------------------------------------------------------------
// StartPhase
//
REGISTER_REGISTER_SKILL_NODE(22022, 1) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_StartPhase::TRIGGER_START, 322, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_StartPhase::TRIGGER_START, 318, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_StartPhase::TRIGGER_START, 285, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(22022, 1) {
    auto node1 = GET_SKILL_NODE(1, PhaseNode_StartPhase);
    if (node1 == nullptr) {
        node1 = new PhaseNode_StartPhase(1, phase);
        CALL_REGISTER_SKILL_NODE(22022, 1, node1)
    }
    if (noInit == true) {
        return node1;
    }
    return node1;
}
//--------------------------------------------------------------------------------
// TriggerUpdate
//
REGISTER_REGISTER_SKILL_NODE(22022, 2) {
}

REGISTER_CREATE_SKILL_NODE(22022, 2) {
    auto node2 = GET_SKILL_NODE(2, PhaseNode_TriggerUpdate);
    if (node2 == nullptr) {
        node2 = new PhaseNode_TriggerUpdate(2, phase);
        CALL_REGISTER_SKILL_NODE(22022, 2, node2)
    }
    if (noInit == true) {
        return node2;
    }
    return node2;
}
//--------------------------------------------------------------------------------
// SpawnCollider
//
REGISTER_REGISTER_SKILL_NODE(22022, 5) {
    pnode->resizeTrigger(PhaseNode_SpawnCollider::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_SpawnCollider::TRIGGER_DONE, 305, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_SpawnCollider::TRIGGER_DONE, 247, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
    pnode->regTrigger<PhaseNode_SetUInt64>(PhaseNode_SpawnCollider::TRIGGER_DONE, 46, PhaseNode_SetUInt64::FUNC_SET, &PhaseNode_SetUInt64::Set);
}

REGISTER_CREATE_SKILL_NODE(22022, 5) {
    auto node5 = GET_SKILL_NODE(5, PhaseNode_SpawnCollider);
    if (node5 == nullptr) {
        node5 = new PhaseNode_SpawnCollider(5, phase);
        node5->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node5->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node5->setMesh("");
        node5->setMeshScale(.00f);
        node5->setEffectID(220222);
        node5->setEffectScale(1.00f);
        node5->setType(PhaseNode_SpawnCollider::SpawnCollider_Type::Circle);
        node5->setTypeParams(0, 3.00f);
        node5->setTime(.00f);
        node5->setPosZ(.00f);
        node5->setRotation(.00f);
        node5->setreentry(false);
        node5->setCheckPeneSound(false);
        CALL_REGISTER_SKILL_NODE(22022, 5, node5)
    }
    if (noInit == true) {
        return node5;
    }
    auto node297 = GET_SKILL_NODE(297, PhaseNode_OffsetCalculate);
    if (node297 != nullptr) node5->setPosX(node297->getOutPosX());
    if (node297 != nullptr) node5->setPosY(node297->getOutPosY());
    return node5;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(22022, 43) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetLocation>(PhaseNode_Detect::TRIGGER_ON, 44, PhaseNode_SetLocation::FUNC_DO, &PhaseNode_SetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(22022, 43) {
    auto node43 = GET_SKILL_NODE(43, PhaseNode_Detect);
    if (node43 == nullptr) {
        node43 = new PhaseNode_Detect(43, phase);
        node43->setSelf(0U);
        node43->setEvent("FollowActor");
        node43->setType(PhaseNode_Detect::Detect_Type::Actor_POS);
        node43->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(22022, 43, node43)
    }
    if (noInit == true) {
        return node43;
    }
    return node43;
}
//--------------------------------------------------------------------------------
// SetLocation
//
REGISTER_REGISTER_SKILL_NODE(22022, 44) {
}

REGISTER_CREATE_SKILL_NODE(22022, 44) {
    auto node44 = GET_SKILL_NODE(44, PhaseNode_SetLocation);
    if (node44 == nullptr) {
        node44 = new PhaseNode_SetLocation(44, phase);
        node44->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node44->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(22022, 44, node44)
    }
    if (noInit == true) {
        return node44;
    }
    auto variables = node44->getVariables();
    if (variables != nullptr) {
        node44->setTarget(variables->getVariable<uint64_t>(Variable_22022_Gas));
    }
    auto node43 = GET_SKILL_NODE(43, PhaseNode_Detect);
    if (node43 != nullptr) node44->setX(node43->getVars().getVariable<float>(0));
    if (node43 != nullptr) node44->setY(node43->getVars().getVariable<float>(1));
    if (node43 != nullptr) node44->setVX(node43->getVars().getVariable<float>(2));
    if (node43 != nullptr) node44->setVY(node43->getVars().getVariable<float>(3));
    return node44;
}
//--------------------------------------------------------------------------------
// SetUInt64
//
REGISTER_REGISTER_SKILL_NODE(22022, 46) {
    pnode->resizeTrigger(PhaseNode_SetUInt64::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_SetUInt64::TRIGGER_DONE, 284, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(22022, 46) {
    auto node46 = GET_SKILL_NODE(46, PhaseNode_SetUInt64);
    if (node46 == nullptr) {
        node46 = new PhaseNode_SetUInt64(46, phase);
        node46->setName("Gas");
        CALL_REGISTER_SKILL_NODE(22022, 46, node46)
    }
    if (noInit == true) {
        return node46;
    }
    auto node5 = GET_SKILL_NODE(5, PhaseNode_SpawnCollider);
    if (node5 != nullptr) node46->setValue(node5->getColliderID());
    return node46;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22022, 73) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_Delay::TRIGGER_DONE, 295, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(22022, 73) {
    auto node73 = GET_SKILL_NODE(73, PhaseNode_Delay);
    if (node73 == nullptr) {
        node73 = new PhaseNode_Delay(73, phase);
        node73->setTime(1.50f);
        CALL_REGISTER_SKILL_NODE(22022, 73, node73)
    }
    if (noInit == true) {
        return node73;
    }
    return node73;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(22022, 240) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StopSound>(PhaseNode_Detect::TRIGGER_ON, 280, PhaseNode_StopSound::FUNC_STOP, &PhaseNode_StopSound::Stop);
}

REGISTER_CREATE_SKILL_NODE(22022, 240) {
    auto node240 = GET_SKILL_NODE(240, PhaseNode_Detect);
    if (node240 == nullptr) {
        node240 = new PhaseNode_Detect(240, phase);
        node240->setSelf(0U);
        node240->setEvent("");
        node240->setType(PhaseNode_Detect::Detect_Type::Actor_Dead);
        node240->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(22022, 240, node240)
    }
    if (noInit == true) {
        return node240;
    }
    return node240;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(22022, 242) {
}

REGISTER_CREATE_SKILL_NODE(22022, 242) {
    auto node242 = GET_SKILL_NODE(242, PhaseNode_EndPhase);
    if (node242 == nullptr) {
        node242 = new PhaseNode_EndPhase(242, phase);
        node242->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node242->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(22022, 242, node242)
    }
    if (noInit == true) {
        return node242;
    }
    return node242;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(22022, 247) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_PlayAnimation::TRIGGER_DONE, 268, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
}

REGISTER_CREATE_SKILL_NODE(22022, 247) {
    auto node247 = GET_SKILL_NODE(247, PhaseNode_PlayAnimation);
    if (node247 == nullptr) {
        node247 = new PhaseNode_PlayAnimation(247, phase);
        node247->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node247->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node247->setTarget(0U);
        node247->setAnimation("Idle");
        node247->setParameter("");
        node247->setValue(false);
        CALL_REGISTER_SKILL_NODE(22022, 247, node247)
    }
    if (noInit == true) {
        return node247;
    }
    return node247;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(22022, 268) {
}

REGISTER_CREATE_SKILL_NODE(22022, 268) {
    auto node268 = GET_SKILL_NODE(268, PhaseNode_SkillEndNotify);
    if (node268 == nullptr) {
        node268 = new PhaseNode_SkillEndNotify(268, phase);
        node268->setReturnType(true);
        CALL_REGISTER_SKILL_NODE(22022, 268, node268)
    }
    if (noInit == true) {
        return node268;
    }
    return node268;
}
//--------------------------------------------------------------------------------
// StopSound
//
REGISTER_REGISTER_SKILL_NODE(22022, 280) {
    pnode->resizeTrigger(PhaseNode_StopSound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StopSound>(PhaseNode_StopSound::TRIGGER_DONE, 282, PhaseNode_StopSound::FUNC_STOP, &PhaseNode_StopSound::Stop);
}

REGISTER_CREATE_SKILL_NODE(22022, 280) {
    auto node280 = GET_SKILL_NODE(280, PhaseNode_StopSound);
    if (node280 == nullptr) {
        node280 = new PhaseNode_StopSound(280, phase);
        node280->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node280->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node280->setSoundID("SE_MON2202_ATK2_P1");
        CALL_REGISTER_SKILL_NODE(22022, 280, node280)
    }
    if (noInit == true) {
        return node280;
    }
    return node280;
}
//--------------------------------------------------------------------------------
// StopSound
//
REGISTER_REGISTER_SKILL_NODE(22022, 282) {
    pnode->resizeTrigger(PhaseNode_StopSound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_StopSound::TRIGGER_DONE, 242, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(22022, 282) {
    auto node282 = GET_SKILL_NODE(282, PhaseNode_StopSound);
    if (node282 == nullptr) {
        node282 = new PhaseNode_StopSound(282, phase);
        node282->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node282->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node282->setSoundID("VO_MON2202_ATK2");
        CALL_REGISTER_SKILL_NODE(22022, 282, node282)
    }
    if (noInit == true) {
        return node282;
    }
    return node282;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(22022, 284) {
}

REGISTER_CREATE_SKILL_NODE(22022, 284) {
    auto node284 = GET_SKILL_NODE(284, PhaseNode_RaiseEvent);
    if (node284 == nullptr) {
        node284 = new PhaseNode_RaiseEvent(284, phase);
        node284->setEvent("FollowActor");
        node284->setTarget(0U);
        node284->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node284->setTypeParams(0, 0);
        node284->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(22022, 284, node284)
    }
    if (noInit == true) {
        return node284;
    }
    return node284;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(22022, 285) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_ResetCD::TRIGGER_DONE, 286, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(22022, 285) {
    auto node285 = GET_SKILL_NODE(285, PhaseNode_ResetCD);
    if (node285 == nullptr) {
        node285 = new PhaseNode_ResetCD(285, phase);
        node285->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node285->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node285->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(22022, 285, node285)
    }
    if (noInit == true) {
        return node285;
    }
    return node285;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(22022, 286) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_PlayAnimation::TRIGGER_DONE, 287, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(22022, 286) {
    auto node286 = GET_SKILL_NODE(286, PhaseNode_PlayAnimation);
    if (node286 == nullptr) {
        node286 = new PhaseNode_PlayAnimation(286, phase);
        node286->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node286->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node286->setTarget(0U);
        node286->setAnimation("Skill2S1");
        node286->setParameter("");
        node286->setValue(false);
        CALL_REGISTER_SKILL_NODE(22022, 286, node286)
    }
    if (noInit == true) {
        return node286;
    }
    return node286;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(22022, 287) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlaySound::TRIGGER_DONE, 288, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(22022, 287) {
    auto node287 = GET_SKILL_NODE(287, PhaseNode_PlaySound);
    if (node287 == nullptr) {
        node287 = new PhaseNode_PlaySound(287, phase);
        node287->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node287->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node287->setSoundID("SE_MON2202_ATK2_P1");
        node287->setTarget(0U);
        node287->setUsePos(false);
        node287->setPosX(.00f);
        node287->setPosY(.00f);
        node287->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(22022, 287, node287)
    }
    if (noInit == true) {
        return node287;
    }
    return node287;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22022, 288) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_Delay::TRIGGER_DONE, 290, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(22022, 288) {
    auto node288 = GET_SKILL_NODE(288, PhaseNode_Delay);
    if (node288 == nullptr) {
        node288 = new PhaseNode_Delay(288, phase);
        node288->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(22022, 288, node288)
    }
    if (noInit == true) {
        return node288;
    }
    return node288;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(22022, 289) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_PlayEffect::TRIGGER_DONE, 292, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(22022, 289) {
    auto node289 = GET_SKILL_NODE(289, PhaseNode_PlayEffect);
    if (node289 == nullptr) {
        node289 = new PhaseNode_PlayEffect(289, phase);
        node289->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node289->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node289->setEffectID(220221);
        node289->setChangeColor(false);
        node289->setType(PhaseNode_PlayEffect::PlayEffect_Type::WithTarget);
        node289->getVars().reserve(5);
        node289->getVars().setVariable<uint64_t>(0, 0U);
        node289->getVars().setVariable<std::string>(1, "Bone001");
        node289->getVars().setVariable<float>(2, .00f);
        node289->getVars().setVariable<float>(3, .00f);
        node289->getVars().setVariable<float>(4, .00f);
        node289->setRotation(.00f);
        node289->setScale(.00f);
        CALL_REGISTER_SKILL_NODE(22022, 289, node289)
    }
    if (noInit == true) {
        return node289;
    }
    return node289;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(22022, 290) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_FALSE, 291, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_TRUE, 289, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(22022, 290) {
    auto node290 = GET_SKILL_NODE(290, PhaseNode_If);
    if (node290 == nullptr) {
        node290 = new PhaseNode_If(290, phase);
        node290->setCondition(true);
        CALL_REGISTER_SKILL_NODE(22022, 290, node290)
    }
    if (noInit == true) {
        return node290;
    }
    return node290;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(22022, 291) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_PlayEffect::TRIGGER_DONE, 292, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(22022, 291) {
    auto node291 = GET_SKILL_NODE(291, PhaseNode_PlayEffect);
    if (node291 == nullptr) {
        node291 = new PhaseNode_PlayEffect(291, phase);
        node291->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node291->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node291->setEffectID(220221);
        node291->setChangeColor(false);
        node291->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node291->getVars().reserve(3);
        node291->getVars().setVariable<float>(0, .00f);
        node291->getVars().setVariable<float>(1, .00f);
        node291->getVars().setVariable<float>(2, .00f);
        node291->setRotation(.00f);
        node291->setScale(.00f);
        CALL_REGISTER_SKILL_NODE(22022, 291, node291)
    }
    if (noInit == true) {
        return node291;
    }
    return node291;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(22022, 292) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 73, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_LESS, 293, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_LESS, 73, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(22022, 292) {
    auto node292 = GET_SKILL_NODE(292, PhaseNode_CompareFloat);
    if (node292 == nullptr) {
        node292 = new PhaseNode_CompareFloat(292, phase);
        node292->setA(.00f);
        node292->setB(.00f);
        CALL_REGISTER_SKILL_NODE(22022, 292, node292)
    }
    if (noInit == true) {
        return node292;
    }
    return node292;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22022, 293) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StopEffect>(PhaseNode_Delay::TRIGGER_DONE, 294, PhaseNode_StopEffect::FUNC_DO, &PhaseNode_StopEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(22022, 293) {
    auto node293 = GET_SKILL_NODE(293, PhaseNode_Delay);
    if (node293 == nullptr) {
        node293 = new PhaseNode_Delay(293, phase);
        node293->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(22022, 293, node293)
    }
    if (noInit == true) {
        return node293;
    }
    return node293;
}
//--------------------------------------------------------------------------------
// StopEffect
//
REGISTER_REGISTER_SKILL_NODE(22022, 294) {
}

REGISTER_CREATE_SKILL_NODE(22022, 294) {
    auto node294 = GET_SKILL_NODE(294, PhaseNode_StopEffect);
    if (node294 == nullptr) {
        node294 = new PhaseNode_StopEffect(294, phase);
        node294->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node294->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node294->setEffectID(220221);
        CALL_REGISTER_SKILL_NODE(22022, 294, node294)
    }
    if (noInit == true) {
        return node294;
    }
    return node294;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(22022, 295) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetRotation>(PhaseNode_GetLocation::TRIGGER_DONE, 296, PhaseNode_GetRotation::FUNC_DO, &PhaseNode_GetRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(22022, 295) {
    auto node295 = GET_SKILL_NODE(295, PhaseNode_GetLocation);
    if (node295 == nullptr) {
        node295 = new PhaseNode_GetLocation(295, phase);
        node295->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node295->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(22022, 295, node295)
    }
    if (noInit == true) {
        return node295;
    }
    return node295;
}
//--------------------------------------------------------------------------------
// GetRotation
//
REGISTER_REGISTER_SKILL_NODE(22022, 296) {
    pnode->resizeTrigger(PhaseNode_GetRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_OffsetCalculate>(PhaseNode_GetRotation::TRIGGER_DONE, 297, PhaseNode_OffsetCalculate::FUNC_DO, &PhaseNode_OffsetCalculate::Do);
}

REGISTER_CREATE_SKILL_NODE(22022, 296) {
    auto node296 = GET_SKILL_NODE(296, PhaseNode_GetRotation);
    if (node296 == nullptr) {
        node296 = new PhaseNode_GetRotation(296, phase);
        node296->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node296->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(22022, 296, node296)
    }
    if (noInit == true) {
        return node296;
    }
    return node296;
}
//--------------------------------------------------------------------------------
// OffsetCalculate
//
REGISTER_REGISTER_SKILL_NODE(22022, 297) {
    pnode->resizeTrigger(PhaseNode_OffsetCalculate::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnCollider>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 5, PhaseNode_SpawnCollider::FUNC_DO, &PhaseNode_SpawnCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(22022, 297) {
    auto node297 = GET_SKILL_NODE(297, PhaseNode_OffsetCalculate);
    if (node297 == nullptr) {
        node297 = new PhaseNode_OffsetCalculate(297, phase);
        node297->setPosZ(.00f);
        node297->setOffsetX(.00f);
        node297->setOffsetY(.00f);
        node297->setOffsetZ(.00f);
        node297->setRotOffset(.00f);
        CALL_REGISTER_SKILL_NODE(22022, 297, node297)
    }
    if (noInit == true) {
        return node297;
    }
    auto node295 = GET_SKILL_NODE(295, PhaseNode_GetLocation);
    auto node296 = GET_SKILL_NODE(296, PhaseNode_GetRotation);
    if (node295 != nullptr) node297->setPosX(node295->getX());
    if (node295 != nullptr) node297->setPosY(node295->getY());
    if (node296 != nullptr) node297->setRotation(node296->getAngle());
    return node297;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(22022, 298) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 310, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 312, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(22022, 298) {
    auto node298 = GET_SKILL_NODE(298, PhaseNode_CreateTriggerNewPene);
    if (node298 == nullptr) {
        node298 = new PhaseNode_CreateTriggerNewPene(298, phase);
        node298->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::In);
        node298->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node298->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Enemy);
        node298->setOnHero(true);
        node298->setOnMinion(true);
        node298->setOnDestruct(true);
        node298->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(22022, 298, node298)
    }
    if (noInit == true) {
        return node298;
    }
    auto node5 = GET_SKILL_NODE(5, PhaseNode_SpawnCollider);
    if (node5 != nullptr) node298->setColliderID(node5->getColliderID());
    return node298;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(22022, 299) {
}

REGISTER_CREATE_SKILL_NODE(22022, 299) {
    auto node299 = GET_SKILL_NODE(299, PhaseNode_TriggerCheck);
    if (node299 == nullptr) {
        node299 = new PhaseNode_TriggerCheck(299, phase);
        auto node2 = GET_SKILL_NODE(2, PhaseNode_TriggerUpdate);
        if (node2 != nullptr) node2->addTriggerCheck(node299);
        
        CALL_REGISTER_SKILL_NODE(22022, 299, node299)
    }
    if (noInit == true) {
        return node299;
    }
    auto node308 = GET_SKILL_NODE(308, PhaseNode_CreateTriggerNewPene);
    if (node308 != nullptr) node299->setTrigger(0, node308->getTriggerID());
    return node299;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(22022, 300) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 301, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(22022, 300) {
    auto node300 = GET_SKILL_NODE(300, PhaseNode_ActorFilterNewPene);
    if (node300 == nullptr) {
        node300 = new PhaseNode_ActorFilterNewPene(300, phase);
        node300->setHero(true);
        node300->setMinion(true);
        node300->setDestruct(true);
        node300->setShield(false);
        node300->setTotalCount(0);
        node300->setPerCount(0);
        CALL_REGISTER_SKILL_NODE(22022, 300, node300)
    }
    if (noInit == true) {
        return node300;
    }
    auto node304 = GET_SKILL_NODE(304, PhaseNode_CreateTriggerNewPene);
    if (node304 != nullptr) node300->setInput(node304->getOther());
    return node300;
}
//--------------------------------------------------------------------------------
// GetActorAttribute
//
REGISTER_REGISTER_SKILL_NODE(22022, 301) {
    pnode->resizeTrigger(PhaseNode_GetActorAttribute::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 302, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 315, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 316, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 317, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
}

REGISTER_CREATE_SKILL_NODE(22022, 301) {
    auto node301 = GET_SKILL_NODE(301, PhaseNode_GetActorAttribute);
    if (node301 == nullptr) {
        node301 = new PhaseNode_GetActorAttribute(301, phase);
        node301->setTarget(0U);
        node301->setType({202});
        CALL_REGISTER_SKILL_NODE(22022, 301, node301)
    }
    if (noInit == true) {
        return node301;
    }
    return node301;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(22022, 302) {
}

REGISTER_CREATE_SKILL_NODE(22022, 302) {
    auto node302 = GET_SKILL_NODE(302, PhaseNode_AddSkillBuffs);
    if (node302 == nullptr) {
        node302 = new PhaseNode_AddSkillBuffs(302, phase);
        node302->setConfigID({11});
        CALL_REGISTER_SKILL_NODE(22022, 302, node302)
    }
    if (noInit == true) {
        return node302;
    }
    auto node300 = GET_SKILL_NODE(300, PhaseNode_ActorFilterNewPene);
    auto node301 = GET_SKILL_NODE(301, PhaseNode_GetActorAttribute);
    if (node300 != nullptr) node302->setTarget(node300->getOutput());
    if (node301 != nullptr) node302->setAttribute(node301->getAttribute());
    return node302;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(22022, 303) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 298, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_LESS, 304, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
}

REGISTER_CREATE_SKILL_NODE(22022, 303) {
    auto node303 = GET_SKILL_NODE(303, PhaseNode_CompareFloat);
    if (node303 == nullptr) {
        node303 = new PhaseNode_CompareFloat(303, phase);
        node303->setA(.00f);
        node303->setB(.30f);
        CALL_REGISTER_SKILL_NODE(22022, 303, node303)
    }
    if (noInit == true) {
        return node303;
    }
    return node303;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(22022, 304) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 309, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 300, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(22022, 304) {
    auto node304 = GET_SKILL_NODE(304, PhaseNode_CreateTriggerNewPene);
    if (node304 == nullptr) {
        node304 = new PhaseNode_CreateTriggerNewPene(304, phase);
        node304->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::Tick);
        node304->setTypeParams(0, .30f);
        node304->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node304->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Enemy);
        node304->setOnHero(true);
        node304->setOnMinion(true);
        node304->setOnDestruct(true);
        node304->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(22022, 304, node304)
    }
    if (noInit == true) {
        return node304;
    }
    auto node5 = GET_SKILL_NODE(5, PhaseNode_SpawnCollider);
    if (node5 != nullptr) node304->setColliderID(node5->getColliderID());
    return node304;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(22022, 305) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_If::TRIGGER_FALSE, 306, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_If::TRIGGER_TRUE, 303, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(22022, 305) {
    auto node305 = GET_SKILL_NODE(305, PhaseNode_If);
    if (node305 == nullptr) {
        node305 = new PhaseNode_If(305, phase);
        node305->setCondition(true);
        CALL_REGISTER_SKILL_NODE(22022, 305, node305)
    }
    if (noInit == true) {
        return node305;
    }
    return node305;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(22022, 306) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 308, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_LESS, 307, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
}

REGISTER_CREATE_SKILL_NODE(22022, 306) {
    auto node306 = GET_SKILL_NODE(306, PhaseNode_CompareFloat);
    if (node306 == nullptr) {
        node306 = new PhaseNode_CompareFloat(306, phase);
        node306->setA(.00f);
        node306->setB(.30f);
        CALL_REGISTER_SKILL_NODE(22022, 306, node306)
    }
    if (noInit == true) {
        return node306;
    }
    return node306;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(22022, 307) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 311, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 313, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(22022, 307) {
    auto node307 = GET_SKILL_NODE(307, PhaseNode_CreateTriggerNewPene);
    if (node307 == nullptr) {
        node307 = new PhaseNode_CreateTriggerNewPene(307, phase);
        node307->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::Tick);
        node307->setTypeParams(0, .30f);
        node307->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node307->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Friend);
        node307->setOnHero(true);
        node307->setOnMinion(true);
        node307->setOnDestruct(true);
        node307->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(22022, 307, node307)
    }
    if (noInit == true) {
        return node307;
    }
    auto node5 = GET_SKILL_NODE(5, PhaseNode_SpawnCollider);
    if (node5 != nullptr) node307->setColliderID(node5->getColliderID());
    return node307;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(22022, 308) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 299, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 314, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(22022, 308) {
    auto node308 = GET_SKILL_NODE(308, PhaseNode_CreateTriggerNewPene);
    if (node308 == nullptr) {
        node308 = new PhaseNode_CreateTriggerNewPene(308, phase);
        node308->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::In);
        node308->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node308->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Friend);
        node308->setOnHero(true);
        node308->setOnMinion(true);
        node308->setOnDestruct(true);
        node308->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(22022, 308, node308)
    }
    if (noInit == true) {
        return node308;
    }
    auto node5 = GET_SKILL_NODE(5, PhaseNode_SpawnCollider);
    if (node5 != nullptr) node308->setColliderID(node5->getColliderID());
    return node308;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(22022, 309) {
}

REGISTER_CREATE_SKILL_NODE(22022, 309) {
    auto node309 = GET_SKILL_NODE(309, PhaseNode_TriggerCheck);
    if (node309 == nullptr) {
        node309 = new PhaseNode_TriggerCheck(309, phase);
        auto node2 = GET_SKILL_NODE(2, PhaseNode_TriggerUpdate);
        if (node2 != nullptr) node2->addTriggerCheck(node309);
        
        CALL_REGISTER_SKILL_NODE(22022, 309, node309)
    }
    if (noInit == true) {
        return node309;
    }
    auto node304 = GET_SKILL_NODE(304, PhaseNode_CreateTriggerNewPene);
    if (node304 != nullptr) node309->setTrigger(0, node304->getTriggerID());
    return node309;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(22022, 310) {
}

REGISTER_CREATE_SKILL_NODE(22022, 310) {
    auto node310 = GET_SKILL_NODE(310, PhaseNode_TriggerCheck);
    if (node310 == nullptr) {
        node310 = new PhaseNode_TriggerCheck(310, phase);
        auto node2 = GET_SKILL_NODE(2, PhaseNode_TriggerUpdate);
        if (node2 != nullptr) node2->addTriggerCheck(node310);
        
        CALL_REGISTER_SKILL_NODE(22022, 310, node310)
    }
    if (noInit == true) {
        return node310;
    }
    auto node298 = GET_SKILL_NODE(298, PhaseNode_CreateTriggerNewPene);
    if (node298 != nullptr) node310->setTrigger(0, node298->getTriggerID());
    return node310;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(22022, 311) {
}

REGISTER_CREATE_SKILL_NODE(22022, 311) {
    auto node311 = GET_SKILL_NODE(311, PhaseNode_TriggerCheck);
    if (node311 == nullptr) {
        node311 = new PhaseNode_TriggerCheck(311, phase);
        auto node2 = GET_SKILL_NODE(2, PhaseNode_TriggerUpdate);
        if (node2 != nullptr) node2->addTriggerCheck(node311);
        
        CALL_REGISTER_SKILL_NODE(22022, 311, node311)
    }
    if (noInit == true) {
        return node311;
    }
    auto node307 = GET_SKILL_NODE(307, PhaseNode_CreateTriggerNewPene);
    if (node307 != nullptr) node311->setTrigger(0, node307->getTriggerID());
    return node311;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(22022, 312) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 301, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(22022, 312) {
    auto node312 = GET_SKILL_NODE(312, PhaseNode_ActorFilterNewPene);
    if (node312 == nullptr) {
        node312 = new PhaseNode_ActorFilterNewPene(312, phase);
        node312->setHero(true);
        node312->setMinion(true);
        node312->setDestruct(true);
        node312->setShield(false);
        node312->setTotalCount(0);
        node312->setPerCount(0);
        CALL_REGISTER_SKILL_NODE(22022, 312, node312)
    }
    if (noInit == true) {
        return node312;
    }
    auto node298 = GET_SKILL_NODE(298, PhaseNode_CreateTriggerNewPene);
    if (node298 != nullptr) node312->setInput(node298->getOther());
    return node312;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(22022, 313) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 301, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(22022, 313) {
    auto node313 = GET_SKILL_NODE(313, PhaseNode_ActorFilterNewPene);
    if (node313 == nullptr) {
        node313 = new PhaseNode_ActorFilterNewPene(313, phase);
        node313->setHero(true);
        node313->setMinion(true);
        node313->setDestruct(true);
        node313->setShield(false);
        node313->setTotalCount(0);
        node313->setPerCount(0);
        CALL_REGISTER_SKILL_NODE(22022, 313, node313)
    }
    if (noInit == true) {
        return node313;
    }
    auto node307 = GET_SKILL_NODE(307, PhaseNode_CreateTriggerNewPene);
    if (node307 != nullptr) node313->setInput(node307->getOther());
    return node313;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(22022, 314) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 301, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(22022, 314) {
    auto node314 = GET_SKILL_NODE(314, PhaseNode_ActorFilterNewPene);
    if (node314 == nullptr) {
        node314 = new PhaseNode_ActorFilterNewPene(314, phase);
        node314->setHero(true);
        node314->setMinion(true);
        node314->setDestruct(true);
        node314->setShield(false);
        node314->setTotalCount(0);
        node314->setPerCount(0);
        CALL_REGISTER_SKILL_NODE(22022, 314, node314)
    }
    if (noInit == true) {
        return node314;
    }
    auto node308 = GET_SKILL_NODE(308, PhaseNode_CreateTriggerNewPene);
    if (node308 != nullptr) node314->setInput(node308->getOther());
    return node314;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(22022, 315) {
}

REGISTER_CREATE_SKILL_NODE(22022, 315) {
    auto node315 = GET_SKILL_NODE(315, PhaseNode_AddSkillBuffs);
    if (node315 == nullptr) {
        node315 = new PhaseNode_AddSkillBuffs(315, phase);
        node315->setConfigID({11});
        CALL_REGISTER_SKILL_NODE(22022, 315, node315)
    }
    if (noInit == true) {
        return node315;
    }
    auto node312 = GET_SKILL_NODE(312, PhaseNode_ActorFilterNewPene);
    auto node301 = GET_SKILL_NODE(301, PhaseNode_GetActorAttribute);
    if (node312 != nullptr) node315->setTarget(node312->getOutput());
    if (node301 != nullptr) node315->setAttribute(node301->getAttribute());
    return node315;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(22022, 316) {
}

REGISTER_CREATE_SKILL_NODE(22022, 316) {
    auto node316 = GET_SKILL_NODE(316, PhaseNode_AddSkillBuffs);
    if (node316 == nullptr) {
        node316 = new PhaseNode_AddSkillBuffs(316, phase);
        node316->setConfigID({11});
        CALL_REGISTER_SKILL_NODE(22022, 316, node316)
    }
    if (noInit == true) {
        return node316;
    }
    auto node313 = GET_SKILL_NODE(313, PhaseNode_ActorFilterNewPene);
    auto node301 = GET_SKILL_NODE(301, PhaseNode_GetActorAttribute);
    if (node313 != nullptr) node316->setTarget(node313->getOutput());
    if (node301 != nullptr) node316->setAttribute(node301->getAttribute());
    return node316;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(22022, 317) {
}

REGISTER_CREATE_SKILL_NODE(22022, 317) {
    auto node317 = GET_SKILL_NODE(317, PhaseNode_AddSkillBuffs);
    if (node317 == nullptr) {
        node317 = new PhaseNode_AddSkillBuffs(317, phase);
        node317->setConfigID({11});
        CALL_REGISTER_SKILL_NODE(22022, 317, node317)
    }
    if (noInit == true) {
        return node317;
    }
    auto node314 = GET_SKILL_NODE(314, PhaseNode_ActorFilterNewPene);
    auto node301 = GET_SKILL_NODE(301, PhaseNode_GetActorAttribute);
    if (node314 != nullptr) node317->setTarget(node314->getOutput());
    if (node301 != nullptr) node317->setAttribute(node301->getAttribute());
    return node317;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(22022, 318) {
}

REGISTER_CREATE_SKILL_NODE(22022, 318) {
    auto node318 = GET_SKILL_NODE(318, PhaseNode_RaiseEvent);
    if (node318 == nullptr) {
        node318 = new PhaseNode_RaiseEvent(318, phase);
        node318->setEvent("MonsterInterrupt");
        node318->setTarget(0U);
        node318->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node318->setTypeParams(0, 0);
        node318->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(22022, 318, node318)
    }
    if (noInit == true) {
        return node318;
    }
    return node318;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(22022, 319) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_Detect::TRIGGER_ON, 324, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(22022, 319) {
    auto node319 = GET_SKILL_NODE(319, PhaseNode_Detect);
    if (node319 == nullptr) {
        node319 = new PhaseNode_Detect(319, phase);
        node319->setSelf(0U);
        node319->setEvent("MonsterInterrupt");
        node319->setType(PhaseNode_Detect::Detect_Type::Interrupt_Skill);
        node319->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(22022, 319, node319)
    }
    if (noInit == true) {
        return node319;
    }
    return node319;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(22022, 320) {
}

REGISTER_CREATE_SKILL_NODE(22022, 320) {
    auto node320 = GET_SKILL_NODE(320, PhaseNode_EndPhase);
    if (node320 == nullptr) {
        node320 = new PhaseNode_EndPhase(320, phase);
        node320->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node320->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(22022, 320, node320)
    }
    if (noInit == true) {
        return node320;
    }
    return node320;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22022, 322) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_Delay::TRIGGER_DONE, 323, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(22022, 322) {
    auto node322 = GET_SKILL_NODE(322, PhaseNode_Delay);
    if (node322 == nullptr) {
        node322 = new PhaseNode_Delay(322, phase);
        node322->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(22022, 322, node322)
    }
    if (noInit == true) {
        return node322;
    }
    return node322;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(22022, 323) {
}

REGISTER_CREATE_SKILL_NODE(22022, 323) {
    auto node323 = GET_SKILL_NODE(323, PhaseNode_PlaySound);
    if (node323 == nullptr) {
        node323 = new PhaseNode_PlaySound(323, phase);
        node323->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node323->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node323->setSoundID("VO_MON2202_ATK2");
        node323->setTarget(0U);
        node323->setUsePos(false);
        node323->setPosX(.00f);
        node323->setPosY(.00f);
        node323->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(22022, 323, node323)
    }
    if (noInit == true) {
        return node323;
    }
    return node323;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22022, 324) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_Delay::TRIGGER_DONE, 326, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(22022, 324) {
    auto node324 = GET_SKILL_NODE(324, PhaseNode_Delay);
    if (node324 == nullptr) {
        node324 = new PhaseNode_Delay(324, phase);
        node324->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(22022, 324, node324)
    }
    if (noInit == true) {
        return node324;
    }
    return node324;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(22022, 325) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 320, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(22022, 325) {
    auto node325 = GET_SKILL_NODE(325, PhaseNode_SkillEndNotify);
    if (node325 == nullptr) {
        node325 = new PhaseNode_SkillEndNotify(325, phase);
        node325->setReturnType(false);
        CALL_REGISTER_SKILL_NODE(22022, 325, node325)
    }
    if (noInit == true) {
        return node325;
    }
    return node325;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(22022, 326) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_FALSE, 327, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_TRUE, 325, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
}

REGISTER_CREATE_SKILL_NODE(22022, 326) {
    auto node326 = GET_SKILL_NODE(326, PhaseNode_If);
    if (node326 == nullptr) {
        node326 = new PhaseNode_If(326, phase);
        node326->setCondition(false);
        CALL_REGISTER_SKILL_NODE(22022, 326, node326)
    }
    if (noInit == true) {
        return node326;
    }
    return node326;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(22022, 327) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 320, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(22022, 327) {
    auto node327 = GET_SKILL_NODE(327, PhaseNode_SkillEndNotify);
    if (node327 == nullptr) {
        node327 = new PhaseNode_SkillEndNotify(327, phase);
        node327->setReturnType(true);
        CALL_REGISTER_SKILL_NODE(22022, 327, node327)
    }
    if (noInit == true) {
        return node327;
    }
    return node327;
}

//--------------------------------------------------------------------------------
// SkillCreator_22022
//
class SkillCreator_22022 : public SkillCreator {
public:
    SkillCreator_22022() {}
    virtual ~SkillCreator_22022() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_22022

//--------------------------------------------------------------------------------
// SkillPhase_22022
//
class SkillPhase_22022 : public SkillPhase {
public:
    SkillPhase_22022(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_22022() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(22022, 1) // StartPhase
        CASE_CREATE_SKILL_NODE(22022, 2) // TriggerUpdate
        CASE_CREATE_SKILL_NODE(22022, 5) // SpawnCollider
        CASE_CREATE_SKILL_NODE(22022, 43) // Detect
        CASE_CREATE_SKILL_NODE(22022, 44) // SetLocation
        CASE_CREATE_SKILL_NODE(22022, 46) // SetUInt64
        CASE_CREATE_SKILL_NODE(22022, 73) // Delay
        CASE_CREATE_SKILL_NODE(22022, 240) // Detect
        CASE_CREATE_SKILL_NODE(22022, 242) // EndPhase
        CASE_CREATE_SKILL_NODE(22022, 247) // PlayAnimation
        CASE_CREATE_SKILL_NODE(22022, 268) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(22022, 280) // StopSound
        CASE_CREATE_SKILL_NODE(22022, 282) // StopSound
        CASE_CREATE_SKILL_NODE(22022, 284) // RaiseEvent
        CASE_CREATE_SKILL_NODE(22022, 285) // ResetCD
        CASE_CREATE_SKILL_NODE(22022, 286) // PlayAnimation
        CASE_CREATE_SKILL_NODE(22022, 287) // PlaySound
        CASE_CREATE_SKILL_NODE(22022, 288) // Delay
        CASE_CREATE_SKILL_NODE(22022, 289) // PlayEffect
        CASE_CREATE_SKILL_NODE(22022, 290) // If
        CASE_CREATE_SKILL_NODE(22022, 291) // PlayEffect
        CASE_CREATE_SKILL_NODE(22022, 292) // CompareFloat
        CASE_CREATE_SKILL_NODE(22022, 293) // Delay
        CASE_CREATE_SKILL_NODE(22022, 294) // StopEffect
        CASE_CREATE_SKILL_NODE(22022, 295) // GetLocation
        CASE_CREATE_SKILL_NODE(22022, 296) // GetRotation
        CASE_CREATE_SKILL_NODE(22022, 297) // OffsetCalculate
        CASE_CREATE_SKILL_NODE(22022, 298) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(22022, 299) // TriggerCheck
        CASE_CREATE_SKILL_NODE(22022, 300) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(22022, 301) // GetActorAttribute
        CASE_CREATE_SKILL_NODE(22022, 302) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(22022, 303) // CompareFloat
        CASE_CREATE_SKILL_NODE(22022, 304) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(22022, 305) // If
        CASE_CREATE_SKILL_NODE(22022, 306) // CompareFloat
        CASE_CREATE_SKILL_NODE(22022, 307) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(22022, 308) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(22022, 309) // TriggerCheck
        CASE_CREATE_SKILL_NODE(22022, 310) // TriggerCheck
        CASE_CREATE_SKILL_NODE(22022, 311) // TriggerCheck
        CASE_CREATE_SKILL_NODE(22022, 312) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(22022, 313) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(22022, 314) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(22022, 315) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(22022, 316) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(22022, 317) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(22022, 318) // RaiseEvent
        CASE_CREATE_SKILL_NODE(22022, 319) // Detect
        CASE_CREATE_SKILL_NODE(22022, 320) // EndPhase
        CASE_CREATE_SKILL_NODE(22022, 322) // Delay
        CASE_CREATE_SKILL_NODE(22022, 323) // PlaySound
        CASE_CREATE_SKILL_NODE(22022, 324) // Delay
        CASE_CREATE_SKILL_NODE(22022, 325) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(22022, 326) // If
        CASE_CREATE_SKILL_NODE(22022, 327) // SkillEndNotify
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_22022

SkillLogic* SkillCreator_22022::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //设置变量
    Variable_22022_Gas = logic->getVariables().setVariable<uint64_t>("Gas", 0U);
    //创建阶段phase
    auto phase = new SkillPhase_22022(1, logic, 3);
    //设置phase执行器
    phase->setRunPhaseNode(1, 1);
    phase->setRunPhaseNode(2, 2);
    phase->setDetectPhaseNode(3, 43);
    phase->setDetectPhaseNode(3, 240);
    phase->setDetectPhaseNode(3, 319);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_22022::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
