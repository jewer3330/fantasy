#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

#include "skill_psnode_cameraxyzshake.h"
#include "skill_psnode_delay.h"
#include "skill_psnode_detect.h"
#include "skill_psnode_disable.h"
#include "skill_psnode_endphase.h"
#include "skill_psnode_getactorattribute.h"
#include "skill_psnode_getinputrotation.h"
#include "skill_psnode_getlocation.h"
#include "skill_psnode_if.h"
#include "skill_psnode_isinterrupttype.h"
#include "skill_psnode_offsetcalculate.h"
#include "skill_psnode_playanimation.h"
#include "skill_psnode_playeffect.h"
#include "skill_psnode_playsound.h"
#include "skill_psnode_raiseevent.h"
#include "skill_psnode_resetcd.h"
#include "skill_psnode_setbool.h"
#include "skill_psnode_spawnprojectile.h"
#include "skill_psnode_startphase.h"
#include "skill_psnode_startpreinput.h"
#include "skill_psnode_switchtoint.h"

namespace pvp {

//变量声明
uint64_t Variable_10113_101132 = 0;
uint64_t Variable_10113_InterruptAnimat = 0;
//--------------------------------------------------------------------------------
// StartPhase
//
REGISTER_REGISTER_SKILL_NODE(10113, 1) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Disable>(PhaseNode_StartPhase::TRIGGER_START, 449, PhaseNode_Disable::FUNC_DO, &PhaseNode_Disable::Do);
}

REGISTER_CREATE_SKILL_NODE(10113, 1) {
    auto node1 = GET_SKILL_NODE(1, PhaseNode_StartPhase);
    if (node1 == nullptr) {
        node1 = new PhaseNode_StartPhase(1, phase);
        CALL_REGISTER_SKILL_NODE(10113, 1, node1)
    }
    if (noInit == true) {
        return node1;
    }
    return node1;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10113, 29) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_Delay::TRIGGER_DONE, 30, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(10113, 29) {
    auto node29 = GET_SKILL_NODE(29, PhaseNode_Delay);
    if (node29 == nullptr) {
        node29 = new PhaseNode_Delay(29, phase);
        node29->setTime(.80f);
        CALL_REGISTER_SKILL_NODE(10113, 29, node29)
    }
    if (noInit == true) {
        return node29;
    }
    return node29;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(10113, 30) {
}

REGISTER_CREATE_SKILL_NODE(10113, 30) {
    auto node30 = GET_SKILL_NODE(30, PhaseNode_EndPhase);
    if (node30 == nullptr) {
        node30 = new PhaseNode_EndPhase(30, phase);
        node30->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node30->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10113, 30, node30)
    }
    if (noInit == true) {
        return node30;
    }
    return node30;
}
//--------------------------------------------------------------------------------
// OffsetCalculate
//
REGISTER_REGISTER_SKILL_NODE(10113, 75) {
    pnode->resizeTrigger(PhaseNode_OffsetCalculate::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 229, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
    pnode->regTrigger<PhaseNode_SpawnProjectile>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 429, PhaseNode_SpawnProjectile::FUNC_DO, &PhaseNode_SpawnProjectile::Do);
}

REGISTER_CREATE_SKILL_NODE(10113, 75) {
    auto node75 = GET_SKILL_NODE(75, PhaseNode_OffsetCalculate);
    if (node75 == nullptr) {
        node75 = new PhaseNode_OffsetCalculate(75, phase);
        node75->setPosZ(.00f);
        node75->setOffsetX(.00f);
        node75->setOffsetY(.50f);
        node75->setOffsetZ(1.60f);
        node75->setRotOffset(.00f);
        CALL_REGISTER_SKILL_NODE(10113, 75, node75)
    }
    if (noInit == true) {
        return node75;
    }
    auto node431 = GET_SKILL_NODE(431, PhaseNode_GetLocation);
    auto node433 = GET_SKILL_NODE(433, PhaseNode_GetInputRotation);
    if (node431 != nullptr) node75->setPosX(node431->getX());
    if (node431 != nullptr) node75->setPosY(node431->getY());
    if (node433 != nullptr) node75->setRotation(node433->getAngle());
    return node75;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10113, 225) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_PlaySound::TRIGGER_DONE, 421, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(10113, 225) {
    auto node225 = GET_SKILL_NODE(225, PhaseNode_PlaySound);
    if (node225 == nullptr) {
        node225 = new PhaseNode_PlaySound(225, phase);
        node225->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node225->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node225->setSoundID("SE_Hero102_Skill_C_P1");
        node225->setTarget(0U);
        node225->setUsePos(false);
        node225->setPosX(.00f);
        node225->setPosY(.00f);
        node225->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10113, 225, node225)
    }
    if (noInit == true) {
        return node225;
    }
    return node225;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10113, 229) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CameraXYZShake>(PhaseNode_PlaySound::TRIGGER_DONE, 425, PhaseNode_CameraXYZShake::FUNC_DO, &PhaseNode_CameraXYZShake::Do);
}

REGISTER_CREATE_SKILL_NODE(10113, 229) {
    auto node229 = GET_SKILL_NODE(229, PhaseNode_PlaySound);
    if (node229 == nullptr) {
        node229 = new PhaseNode_PlaySound(229, phase);
        node229->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node229->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node229->setSoundID("SE_Hero102_Skill_C_P2");
        node229->setTarget(0U);
        node229->setUsePos(false);
        node229->setPosX(.00f);
        node229->setPosY(.00f);
        node229->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10113, 229, node229)
    }
    if (noInit == true) {
        return node229;
    }
    return node229;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(10113, 421) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_PlayEffect::TRIGGER_DONE, 423, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(10113, 421) {
    auto node421 = GET_SKILL_NODE(421, PhaseNode_PlayEffect);
    if (node421 == nullptr) {
        node421 = new PhaseNode_PlayEffect(421, phase);
        node421->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node421->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node421->setEffectID(101131);
        node421->setChangeColor(false);
        node421->setType(PhaseNode_PlayEffect::PlayEffect_Type::WithTarget);
        node421->getVars().reserve(5);
        node421->getVars().setVariable<uint64_t>(0, 0U);
        node421->getVars().setVariable<std::string>(1, "Effect");
        node421->getVars().setVariable<float>(2, .00f);
        node421->getVars().setVariable<float>(3, .00f);
        node421->getVars().setVariable<float>(4, .00f);
        node421->setRotation(.00f);
        node421->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(10113, 421, node421)
    }
    if (noInit == true) {
        return node421;
    }
    return node421;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(10113, 423) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlayEffect::TRIGGER_DONE, 459, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10113, 423) {
    auto node423 = GET_SKILL_NODE(423, PhaseNode_PlayEffect);
    if (node423 == nullptr) {
        node423 = new PhaseNode_PlayEffect(423, phase);
        node423->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node423->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node423->setEffectID(101134);
        node423->setChangeColor(false);
        node423->setType(PhaseNode_PlayEffect::PlayEffect_Type::WithTarget);
        node423->getVars().reserve(5);
        node423->getVars().setVariable<uint64_t>(0, 0U);
        node423->getVars().setVariable<std::string>(1, "");
        node423->getVars().setVariable<float>(2, .00f);
        node423->getVars().setVariable<float>(3, .00f);
        node423->getVars().setVariable<float>(4, .00f);
        node423->setRotation(.00f);
        node423->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(10113, 423, node423)
    }
    if (noInit == true) {
        return node423;
    }
    return node423;
}
//--------------------------------------------------------------------------------
// CameraXYZShake
//
REGISTER_REGISTER_SKILL_NODE(10113, 425) {
}

REGISTER_CREATE_SKILL_NODE(10113, 425) {
    auto node425 = GET_SKILL_NODE(425, PhaseNode_CameraXYZShake);
    if (node425 == nullptr) {
        node425 = new PhaseNode_CameraXYZShake(425, phase);
        node425->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node425->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node425->setShakeStyle(0);
        node425->setTarget(0U);
        node425->setX(.25f);
        node425->setY(.25f);
        node425->setZ(.25f);
        node425->setDuration(.10f);
        node425->setTimes(1);
        CALL_REGISTER_SKILL_NODE(10113, 425, node425)
    }
    if (noInit == true) {
        return node425;
    }
    return node425;
}
//--------------------------------------------------------------------------------
// SpawnProjectile
//
REGISTER_REGISTER_SKILL_NODE(10113, 429) {
    pnode->resizeTrigger(PhaseNode_SpawnProjectile::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_SpawnProjectile::TRIGGER_DONE, 29, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10113, 429) {
    auto node429 = GET_SKILL_NODE(429, PhaseNode_SpawnProjectile);
    if (node429 == nullptr) {
        node429 = new PhaseNode_SpawnProjectile(429, phase);
        node429->setDataId(55113);
        node429->setEndPosX(.00f);
        node429->setEndPosY(.00f);
        node429->setEndPosZ(.00f);
        node429->setMaxCount(0);
        CALL_REGISTER_SKILL_NODE(10113, 429, node429)
    }
    if (noInit == true) {
        return node429;
    }
    auto node75 = GET_SKILL_NODE(75, PhaseNode_OffsetCalculate);
    if (node75 != nullptr) node429->setPosX(node75->getOutPosX());
    if (node75 != nullptr) node429->setPosY(node75->getOutPosY());
    if (node75 != nullptr) node429->setPosZ(node75->getOutPosZ());
    if (node75 != nullptr) node429->setRotation(node75->getOutRotation());
    return node429;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(10113, 431) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetInputRotation>(PhaseNode_GetLocation::TRIGGER_DONE, 433, PhaseNode_GetInputRotation::FUNC_DO, &PhaseNode_GetInputRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(10113, 431) {
    auto node431 = GET_SKILL_NODE(431, PhaseNode_GetLocation);
    if (node431 == nullptr) {
        node431 = new PhaseNode_GetLocation(431, phase);
        node431->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node431->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(10113, 431, node431)
    }
    if (noInit == true) {
        return node431;
    }
    return node431;
}
//--------------------------------------------------------------------------------
// GetInputRotation
//
REGISTER_REGISTER_SKILL_NODE(10113, 433) {
    pnode->resizeTrigger(PhaseNode_GetInputRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_OffsetCalculate>(PhaseNode_GetInputRotation::TRIGGER_DONE, 75, PhaseNode_OffsetCalculate::FUNC_DO, &PhaseNode_OffsetCalculate::Do);
}

REGISTER_CREATE_SKILL_NODE(10113, 433) {
    auto node433 = GET_SKILL_NODE(433, PhaseNode_GetInputRotation);
    if (node433 == nullptr) {
        node433 = new PhaseNode_GetInputRotation(433, phase);
        node433->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        CALL_REGISTER_SKILL_NODE(10113, 433, node433)
    }
    if (noInit == true) {
        return node433;
    }
    return node433;
}
//--------------------------------------------------------------------------------
// Disable
//
REGISTER_REGISTER_SKILL_NODE(10113, 449) {
    pnode->resizeTrigger(PhaseNode_Disable::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_Disable::TRIGGER_DONE, 468, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10113, 449) {
    auto node449 = GET_SKILL_NODE(449, PhaseNode_Disable);
    if (node449 == nullptr) {
        node449 = new PhaseNode_Disable(449, phase);
        node449->setTarget(0U);
        node449->setMove(true);
        node449->setSkill(true);
        node449->setShoot(true);
        node449->setTime(1.33f);
        node449->setRotate(true);
        CALL_REGISTER_SKILL_NODE(10113, 449, node449)
    }
    if (noInit == true) {
        return node449;
    }
    return node449;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10113, 459) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_Delay::TRIGGER_DONE, 431, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(10113, 459) {
    auto node459 = GET_SKILL_NODE(459, PhaseNode_Delay);
    if (node459 == nullptr) {
        node459 = new PhaseNode_Delay(459, phase);
        node459->setTime(.72f);
        CALL_REGISTER_SKILL_NODE(10113, 459, node459)
    }
    if (noInit == true) {
        return node459;
    }
    return node459;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(10113, 460) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_ResetCD::TRIGGER_DONE, 461, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10113, 460) {
    auto node460 = GET_SKILL_NODE(460, PhaseNode_ResetCD);
    if (node460 == nullptr) {
        node460 = new PhaseNode_ResetCD(460, phase);
        node460->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node460->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node460->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(10113, 460, node460)
    }
    if (noInit == true) {
        return node460;
    }
    return node460;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10113, 461) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_PlayAnimation::TRIGGER_DONE, 463, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(10113, 461) {
    auto node461 = GET_SKILL_NODE(461, PhaseNode_PlayAnimation);
    if (node461 == nullptr) {
        node461 = new PhaseNode_PlayAnimation(461, phase);
        node461->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node461->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node461->setTarget(0U);
        node461->setAnimation("Skill3S1");
        node461->setParameter("");
        node461->setValue(false);
        CALL_REGISTER_SKILL_NODE(10113, 461, node461)
    }
    if (noInit == true) {
        return node461;
    }
    return node461;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10113, 462) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_PlaySound::TRIGGER_DONE, 225, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10113, 462) {
    auto node462 = GET_SKILL_NODE(462, PhaseNode_PlaySound);
    if (node462 == nullptr) {
        node462 = new PhaseNode_PlaySound(462, phase);
        node462->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node462->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node462->setSoundID("VO_Hero102_Skill_C");
        node462->setTarget(0U);
        node462->setUsePos(false);
        node462->setPosX(.00f);
        node462->setPosY(.00f);
        node462->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10113, 462, node462)
    }
    if (noInit == true) {
        return node462;
    }
    return node462;
}
//--------------------------------------------------------------------------------
// GetActorAttribute
//
REGISTER_REGISTER_SKILL_NODE(10113, 463) {
    pnode->resizeTrigger(PhaseNode_GetActorAttribute::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 462, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10113, 463) {
    auto node463 = GET_SKILL_NODE(463, PhaseNode_GetActorAttribute);
    if (node463 == nullptr) {
        node463 = new PhaseNode_GetActorAttribute(463, phase);
        node463->setTarget(0U);
        node463->setType({});
        CALL_REGISTER_SKILL_NODE(10113, 463, node463)
    }
    if (noInit == true) {
        return node463;
    }
    return node463;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10113, 465) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_IsInterruptType>(PhaseNode_Detect::TRIGGER_ON, 471, PhaseNode_IsInterruptType::FUNC_DO, &PhaseNode_IsInterruptType::Do);
}

REGISTER_CREATE_SKILL_NODE(10113, 465) {
    auto node465 = GET_SKILL_NODE(465, PhaseNode_Detect);
    if (node465 == nullptr) {
        node465 = new PhaseNode_Detect(465, phase);
        node465->setSelf(0U);
        node465->setEvent("daduan_001");
        node465->setType(PhaseNode_Detect::Detect_Type::Interrupt_Skill);
        node465->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10113, 465, node465)
    }
    if (noInit == true) {
        return node465;
    }
    return node465;
}
//--------------------------------------------------------------------------------
// SwitchToInt
//
REGISTER_REGISTER_SKILL_NODE(10113, 466) {
    pnode->resizeTrigger(4);
    pnode->regTrigger<PhaseNode_EndPhase>(1, 30, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(10113, 466) {
    auto node466 = GET_SKILL_NODE(466, PhaseNode_SwitchToInt);
    if (node466 == nullptr) {
        node466 = new PhaseNode_SwitchToInt(466, phase);
        CALL_REGISTER_SKILL_NODE(10113, 466, node466)
    }
    if (noInit == true) {
        return node466;
    }
    auto variables = node466->getVariables();
    if (variables != nullptr) {
        node466->setSelection(variables->getVariable<int32_t>(Variable_10113_101132));
    }
    return node466;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10113, 468) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_RaiseEvent::TRIGGER_DONE, 477, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10113, 468) {
    auto node468 = GET_SKILL_NODE(468, PhaseNode_RaiseEvent);
    if (node468 == nullptr) {
        node468 = new PhaseNode_RaiseEvent(468, phase);
        node468->setEvent("daduan_001");
        node468->setTarget(0U);
        node468->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node468->setTypeParams(0, 0);
        node468->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10113, 468, node468)
    }
    if (noInit == true) {
        return node468;
    }
    return node468;
}
//--------------------------------------------------------------------------------
// StartPreInput
//
REGISTER_REGISTER_SKILL_NODE(10113, 469) {
    pnode->resizeTrigger(PhaseNode_StartPreInput::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_StartPreInput::TRIGGER_DONE, 473, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_StartPreInput::TRIGGER_DONE, 460, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(10113, 469) {
    auto node469 = GET_SKILL_NODE(469, PhaseNode_StartPreInput);
    if (node469 == nullptr) {
        node469 = new PhaseNode_StartPreInput(469, phase);
        node469->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node469->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node469->setDelayTime(.20f);
        CALL_REGISTER_SKILL_NODE(10113, 469, node469)
    }
    if (noInit == true) {
        return node469;
    }
    return node469;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(10113, 470) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_If::TRIGGER_TRUE, 472, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10113, 470) {
    auto node470 = GET_SKILL_NODE(470, PhaseNode_If);
    if (node470 == nullptr) {
        node470 = new PhaseNode_If(470, phase);
        CALL_REGISTER_SKILL_NODE(10113, 470, node470)
    }
    if (noInit == true) {
        return node470;
    }
    auto variables = node470->getVariables();
    if (variables != nullptr) {
        node470->setCondition(variables->getVariable<bool>(Variable_10113_InterruptAnimat));
    }
    return node470;
}
//--------------------------------------------------------------------------------
// IsInterruptType
//
REGISTER_REGISTER_SKILL_NODE(10113, 471) {
    pnode->resizeTrigger(PhaseNode_IsInterruptType::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SwitchToInt>(PhaseNode_IsInterruptType::TRIGGER_BUFF, 466, PhaseNode_SwitchToInt::FUNC_SWITCH, &PhaseNode_SwitchToInt::Switch);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_POSCHANGE, 470, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTAIM, 470, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTFIRE, 470, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTRELOAD, 470, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_USESKILL, 470, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(10113, 471) {
    auto node471 = GET_SKILL_NODE(471, PhaseNode_IsInterruptType);
    if (node471 == nullptr) {
        node471 = new PhaseNode_IsInterruptType(471, phase);
        node471->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node471->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10113, 471, node471)
    }
    if (noInit == true) {
        return node471;
    }
    auto node465 = GET_SKILL_NODE(465, PhaseNode_Detect);
    if (node465 != nullptr) node471->setType(node465->getVars().getVariable<int32_t>(2));
    return node471;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10113, 472) {
}

REGISTER_CREATE_SKILL_NODE(10113, 472) {
    auto node472 = GET_SKILL_NODE(472, PhaseNode_PlayAnimation);
    if (node472 == nullptr) {
        node472 = new PhaseNode_PlayAnimation(472, phase);
        node472->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node472->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node472->setTarget(0U);
        node472->setAnimation("Idle");
        node472->setParameter("");
        node472->setValue(false);
        CALL_REGISTER_SKILL_NODE(10113, 472, node472)
    }
    if (noInit == true) {
        return node472;
    }
    return node472;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10113, 473) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_Delay::TRIGGER_DONE, 476, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(10113, 473) {
    auto node473 = GET_SKILL_NODE(473, PhaseNode_Delay);
    if (node473 == nullptr) {
        node473 = new PhaseNode_Delay(473, phase);
        node473->setTime(.20f);
        CALL_REGISTER_SKILL_NODE(10113, 473, node473)
    }
    if (noInit == true) {
        return node473;
    }
    return node473;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(10113, 476) {
}

REGISTER_CREATE_SKILL_NODE(10113, 476) {
    auto node476 = GET_SKILL_NODE(476, PhaseNode_SetBool);
    if (node476 == nullptr) {
        node476 = new PhaseNode_SetBool(476, phase);
        node476->setName("InterruptAnimat");
        node476->setValue(true);
        CALL_REGISTER_SKILL_NODE(10113, 476, node476)
    }
    if (noInit == true) {
        return node476;
    }
    return node476;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10113, 477) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StartPreInput>(PhaseNode_RaiseEvent::TRIGGER_DONE, 469, PhaseNode_StartPreInput::FUNC_DO, &PhaseNode_StartPreInput::Do);
}

REGISTER_CREATE_SKILL_NODE(10113, 477) {
    auto node477 = GET_SKILL_NODE(477, PhaseNode_RaiseEvent);
    if (node477 == nullptr) {
        node477 = new PhaseNode_RaiseEvent(477, phase);
        node477->setEvent("Dead_001");
        node477->setTarget(0U);
        node477->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node477->setTypeParams(0, 0);
        node477->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10113, 477, node477)
    }
    if (noInit == true) {
        return node477;
    }
    return node477;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10113, 478) {
}

REGISTER_CREATE_SKILL_NODE(10113, 478) {
    auto node478 = GET_SKILL_NODE(478, PhaseNode_Detect);
    if (node478 == nullptr) {
        node478 = new PhaseNode_Detect(478, phase);
        node478->setSelf(0U);
        node478->setEvent("Dead_001");
        node478->setType(PhaseNode_Detect::Detect_Type::Actor_Dead);
        node478->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10113, 478, node478)
    }
    if (noInit == true) {
        return node478;
    }
    return node478;
}

//--------------------------------------------------------------------------------
// SkillCreator_10113
//
class SkillCreator_10113 : public SkillCreator {
public:
    SkillCreator_10113() {}
    virtual ~SkillCreator_10113() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_10113

//--------------------------------------------------------------------------------
// SkillPhase_10113
//
class SkillPhase_10113 : public SkillPhase {
public:
    SkillPhase_10113(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_10113() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(10113, 1) // StartPhase
        CASE_CREATE_SKILL_NODE(10113, 29) // Delay
        CASE_CREATE_SKILL_NODE(10113, 30) // EndPhase
        CASE_CREATE_SKILL_NODE(10113, 75) // OffsetCalculate
        CASE_CREATE_SKILL_NODE(10113, 225) // PlaySound
        CASE_CREATE_SKILL_NODE(10113, 229) // PlaySound
        CASE_CREATE_SKILL_NODE(10113, 421) // PlayEffect
        CASE_CREATE_SKILL_NODE(10113, 423) // PlayEffect
        CASE_CREATE_SKILL_NODE(10113, 425) // CameraXYZShake
        CASE_CREATE_SKILL_NODE(10113, 429) // SpawnProjectile
        CASE_CREATE_SKILL_NODE(10113, 431) // GetLocation
        CASE_CREATE_SKILL_NODE(10113, 433) // GetInputRotation
        CASE_CREATE_SKILL_NODE(10113, 449) // Disable
        CASE_CREATE_SKILL_NODE(10113, 459) // Delay
        CASE_CREATE_SKILL_NODE(10113, 460) // ResetCD
        CASE_CREATE_SKILL_NODE(10113, 461) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10113, 462) // PlaySound
        CASE_CREATE_SKILL_NODE(10113, 463) // GetActorAttribute
        CASE_CREATE_SKILL_NODE(10113, 465) // Detect
        CASE_CREATE_SKILL_NODE(10113, 466) // SwitchToInt
        CASE_CREATE_SKILL_NODE(10113, 468) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10113, 469) // StartPreInput
        CASE_CREATE_SKILL_NODE(10113, 470) // If
        CASE_CREATE_SKILL_NODE(10113, 471) // IsInterruptType
        CASE_CREATE_SKILL_NODE(10113, 472) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10113, 473) // Delay
        CASE_CREATE_SKILL_NODE(10113, 476) // SetBool
        CASE_CREATE_SKILL_NODE(10113, 477) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10113, 478) // Detect
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_10113

SkillLogic* SkillCreator_10113::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //设置变量
    Variable_10113_101132 = logic->getVariables().setVariable<int32_t>("101132", 1);
    Variable_10113_InterruptAnimat = logic->getVariables().setVariable<bool>("InterruptAnimat");
    //创建阶段phase
    auto phase = new SkillPhase_10113(1, logic, 2);
    //设置phase执行器
    phase->setRunPhaseNode(1, 1);
    phase->setDetectPhaseNode(2, 465);
    phase->setDetectPhaseNode(2, 478);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_10113::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
