#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

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
uint64_t Variable_10351_a103511 = 0;
uint64_t Variable_10351_InterruptAnimat = 0;
//--------------------------------------------------------------------------------
// StartPhase
//
REGISTER_REGISTER_SKILL_NODE(10351, 4) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_StartPhase::TRIGGER_START, 55, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(10351, 4) {
    auto node4 = GET_SKILL_NODE(4, PhaseNode_StartPhase);
    if (node4 == nullptr) {
        node4 = new PhaseNode_StartPhase(4, phase);
        CALL_REGISTER_SKILL_NODE(10351, 4, node4)
    }
    if (noInit == true) {
        return node4;
    }
    return node4;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10351, 9) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_PlaySound::TRIGGER_DONE, 44, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10351, 9) {
    auto node9 = GET_SKILL_NODE(9, PhaseNode_PlaySound);
    if (node9 == nullptr) {
        node9 = new PhaseNode_PlaySound(9, phase);
        node9->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node9->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node9->setSoundID("SE_Hero114_SkillC_P2");
        node9->setTarget(0U);
        node9->setUsePos(false);
        node9->setPosX(.00f);
        node9->setPosY(.00f);
        node9->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10351, 9, node9)
    }
    if (noInit == true) {
        return node9;
    }
    return node9;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(10351, 16) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_ResetCD::TRIGGER_DONE, 18, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(10351, 16) {
    auto node16 = GET_SKILL_NODE(16, PhaseNode_ResetCD);
    if (node16 == nullptr) {
        node16 = new PhaseNode_ResetCD(16, phase);
        node16->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node16->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node16->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(10351, 16, node16)
    }
    if (noInit == true) {
        return node16;
    }
    return node16;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(10351, 18) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetInputRotation>(PhaseNode_GetLocation::TRIGGER_DONE, 30, PhaseNode_GetInputRotation::FUNC_DO, &PhaseNode_GetInputRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(10351, 18) {
    auto node18 = GET_SKILL_NODE(18, PhaseNode_GetLocation);
    if (node18 == nullptr) {
        node18 = new PhaseNode_GetLocation(18, phase);
        node18->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node18->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(10351, 18, node18)
    }
    if (noInit == true) {
        return node18;
    }
    return node18;
}
//--------------------------------------------------------------------------------
// Disable
//
REGISTER_REGISTER_SKILL_NODE(10351, 20) {
    pnode->resizeTrigger(PhaseNode_Disable::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_Disable::TRIGGER_DONE, 22, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10351, 20) {
    auto node20 = GET_SKILL_NODE(20, PhaseNode_Disable);
    if (node20 == nullptr) {
        node20 = new PhaseNode_Disable(20, phase);
        node20->setTarget(0U);
        node20->setMove(true);
        node20->setSkill(true);
        node20->setShoot(true);
        node20->setTime(.40f);
        node20->setRotate(true);
        CALL_REGISTER_SKILL_NODE(10351, 20, node20)
    }
    if (noInit == true) {
        return node20;
    }
    return node20;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10351, 22) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_OffsetCalculate>(PhaseNode_Delay::TRIGGER_DONE, 32, PhaseNode_OffsetCalculate::FUNC_DO, &PhaseNode_OffsetCalculate::Do);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_Delay::TRIGGER_DONE, 27, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(10351, 22) {
    auto node22 = GET_SKILL_NODE(22, PhaseNode_Delay);
    if (node22 == nullptr) {
        node22 = new PhaseNode_Delay(22, phase);
        node22->setTime(.12f);
        CALL_REGISTER_SKILL_NODE(10351, 22, node22)
    }
    if (noInit == true) {
        return node22;
    }
    return node22;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(10351, 27) {
}

REGISTER_CREATE_SKILL_NODE(10351, 27) {
    auto node27 = GET_SKILL_NODE(27, PhaseNode_PlayEffect);
    if (node27 == nullptr) {
        node27 = new PhaseNode_PlayEffect(27, phase);
        node27->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node27->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node27->setEffectID(103511);
        node27->setChangeColor(false);
        node27->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node27->getVars().reserve(3);
        node27->getVars().setVariable<float>(0, .00f);
        node27->getVars().setVariable<float>(1, .00f);
        node27->getVars().setVariable<float>(2, .00f);
        node27->setScale(.00f);
        CALL_REGISTER_SKILL_NODE(10351, 27, node27)
    }
    if (noInit == true) {
        return node27;
    }
    auto node18 = GET_SKILL_NODE(18, PhaseNode_GetLocation);
    auto node30 = GET_SKILL_NODE(30, PhaseNode_GetInputRotation);
    if (node18 != nullptr) node27->getVars().setVariable<float>(0, node18->getX());
    if (node18 != nullptr) node27->getVars().setVariable<float>(1, node18->getY());
    if (node30 != nullptr) node27->setRotation(node30->getAngle());
    return node27;
}
//--------------------------------------------------------------------------------
// GetInputRotation
//
REGISTER_REGISTER_SKILL_NODE(10351, 30) {
    pnode->resizeTrigger(PhaseNode_GetInputRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Disable>(PhaseNode_GetInputRotation::TRIGGER_DONE, 20, PhaseNode_Disable::FUNC_DO, &PhaseNode_Disable::Do);
}

REGISTER_CREATE_SKILL_NODE(10351, 30) {
    auto node30 = GET_SKILL_NODE(30, PhaseNode_GetInputRotation);
    if (node30 == nullptr) {
        node30 = new PhaseNode_GetInputRotation(30, phase);
        node30->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        CALL_REGISTER_SKILL_NODE(10351, 30, node30)
    }
    if (noInit == true) {
        return node30;
    }
    return node30;
}
//--------------------------------------------------------------------------------
// OffsetCalculate
//
REGISTER_REGISTER_SKILL_NODE(10351, 32) {
    pnode->resizeTrigger(PhaseNode_OffsetCalculate::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnProjectile>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 34, PhaseNode_SpawnProjectile::FUNC_DO, &PhaseNode_SpawnProjectile::Do);
}

REGISTER_CREATE_SKILL_NODE(10351, 32) {
    auto node32 = GET_SKILL_NODE(32, PhaseNode_OffsetCalculate);
    if (node32 == nullptr) {
        node32 = new PhaseNode_OffsetCalculate(32, phase);
        node32->setPosZ(.00f);
        node32->setOffsetX(.00f);
        node32->setOffsetY(.00f);
        node32->setOffsetZ(.00f);
        node32->setRotOffset(.00f);
        CALL_REGISTER_SKILL_NODE(10351, 32, node32)
    }
    if (noInit == true) {
        return node32;
    }
    auto node18 = GET_SKILL_NODE(18, PhaseNode_GetLocation);
    auto node30 = GET_SKILL_NODE(30, PhaseNode_GetInputRotation);
    if (node18 != nullptr) node32->setPosX(node18->getX());
    if (node18 != nullptr) node32->setPosY(node18->getY());
    if (node30 != nullptr) node32->setRotation(node30->getAngle());
    return node32;
}
//--------------------------------------------------------------------------------
// SpawnProjectile
//
REGISTER_REGISTER_SKILL_NODE(10351, 34) {
    pnode->resizeTrigger(PhaseNode_SpawnProjectile::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_SpawnProjectile::TRIGGER_DONE, 36, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10351, 34) {
    auto node34 = GET_SKILL_NODE(34, PhaseNode_SpawnProjectile);
    if (node34 == nullptr) {
        node34 = new PhaseNode_SpawnProjectile(34, phase);
        node34->setDataId(55351);
        node34->setEndPosX(.00f);
        node34->setEndPosY(.00f);
        node34->setEndPosZ(.00f);
        node34->setMaxCount(0);
        CALL_REGISTER_SKILL_NODE(10351, 34, node34)
    }
    if (noInit == true) {
        return node34;
    }
    auto node32 = GET_SKILL_NODE(32, PhaseNode_OffsetCalculate);
    if (node32 != nullptr) node34->setPosX(node32->getOutPosX());
    if (node32 != nullptr) node34->setPosY(node32->getOutPosY());
    if (node32 != nullptr) node34->setPosZ(node32->getOutPosZ());
    if (node32 != nullptr) node34->setRotation(node32->getOutRotation());
    return node34;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10351, 36) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_Delay::TRIGGER_DONE, 39, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(10351, 36) {
    auto node36 = GET_SKILL_NODE(36, PhaseNode_Delay);
    if (node36 == nullptr) {
        node36 = new PhaseNode_Delay(36, phase);
        node36->setTime(.50f);
        CALL_REGISTER_SKILL_NODE(10351, 36, node36)
    }
    if (noInit == true) {
        return node36;
    }
    return node36;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(10351, 39) {
}

REGISTER_CREATE_SKILL_NODE(10351, 39) {
    auto node39 = GET_SKILL_NODE(39, PhaseNode_EndPhase);
    if (node39 == nullptr) {
        node39 = new PhaseNode_EndPhase(39, phase);
        node39->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node39->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10351, 39, node39)
    }
    if (noInit == true) {
        return node39;
    }
    return node39;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10351, 41) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_IsInterruptType>(PhaseNode_Detect::TRIGGER_ON, 47, PhaseNode_IsInterruptType::FUNC_DO, &PhaseNode_IsInterruptType::Do);
}

REGISTER_CREATE_SKILL_NODE(10351, 41) {
    auto node41 = GET_SKILL_NODE(41, PhaseNode_Detect);
    if (node41 == nullptr) {
        node41 = new PhaseNode_Detect(41, phase);
        node41->setSelf(0U);
        node41->setEvent("daduan_001");
        node41->setType(PhaseNode_Detect::Detect_Type::Interrupt_Skill);
        node41->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10351, 41, node41)
    }
    if (noInit == true) {
        return node41;
    }
    return node41;
}
//--------------------------------------------------------------------------------
// SwitchToInt
//
REGISTER_REGISTER_SKILL_NODE(10351, 42) {
}

REGISTER_CREATE_SKILL_NODE(10351, 42) {
    auto node42 = GET_SKILL_NODE(42, PhaseNode_SwitchToInt);
    if (node42 == nullptr) {
        node42 = new PhaseNode_SwitchToInt(42, phase);
        CALL_REGISTER_SKILL_NODE(10351, 42, node42)
    }
    if (noInit == true) {
        return node42;
    }
    auto variables = node42->getVariables();
    if (variables != nullptr) {
        node42->setSelection(variables->getVariable<int32_t>(Variable_10351_a103511));
    }
    return node42;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10351, 44) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_RaiseEvent::TRIGGER_DONE, 53, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10351, 44) {
    auto node44 = GET_SKILL_NODE(44, PhaseNode_RaiseEvent);
    if (node44 == nullptr) {
        node44 = new PhaseNode_RaiseEvent(44, phase);
        node44->setEvent("daduan_001");
        node44->setTarget(0U);
        node44->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node44->setTypeParams(0, 0);
        node44->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10351, 44, node44)
    }
    if (noInit == true) {
        return node44;
    }
    return node44;
}
//--------------------------------------------------------------------------------
// StartPreInput
//
REGISTER_REGISTER_SKILL_NODE(10351, 45) {
    pnode->resizeTrigger(PhaseNode_StartPreInput::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_StartPreInput::TRIGGER_DONE, 49, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10351, 45) {
    auto node45 = GET_SKILL_NODE(45, PhaseNode_StartPreInput);
    if (node45 == nullptr) {
        node45 = new PhaseNode_StartPreInput(45, phase);
        node45->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node45->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node45->setDelayTime(.00f);
        CALL_REGISTER_SKILL_NODE(10351, 45, node45)
    }
    if (noInit == true) {
        return node45;
    }
    return node45;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(10351, 46) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_If::TRIGGER_TRUE, 48, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10351, 46) {
    auto node46 = GET_SKILL_NODE(46, PhaseNode_If);
    if (node46 == nullptr) {
        node46 = new PhaseNode_If(46, phase);
        CALL_REGISTER_SKILL_NODE(10351, 46, node46)
    }
    if (noInit == true) {
        return node46;
    }
    auto variables = node46->getVariables();
    if (variables != nullptr) {
        node46->setCondition(variables->getVariable<bool>(Variable_10351_InterruptAnimat));
    }
    return node46;
}
//--------------------------------------------------------------------------------
// IsInterruptType
//
REGISTER_REGISTER_SKILL_NODE(10351, 47) {
    pnode->resizeTrigger(PhaseNode_IsInterruptType::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SwitchToInt>(PhaseNode_IsInterruptType::TRIGGER_BUFF, 42, PhaseNode_SwitchToInt::FUNC_SWITCH, &PhaseNode_SwitchToInt::Switch);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_POSCHANGE, 46, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTAIM, 46, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTFIRE, 46, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTRELOAD, 46, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_USESKILL, 46, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(10351, 47) {
    auto node47 = GET_SKILL_NODE(47, PhaseNode_IsInterruptType);
    if (node47 == nullptr) {
        node47 = new PhaseNode_IsInterruptType(47, phase);
        node47->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node47->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10351, 47, node47)
    }
    if (noInit == true) {
        return node47;
    }
    auto node41 = GET_SKILL_NODE(41, PhaseNode_Detect);
    if (node41 != nullptr) node47->setType(node41->getVars().getVariable<int32_t>(2));
    return node47;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10351, 48) {
}

REGISTER_CREATE_SKILL_NODE(10351, 48) {
    auto node48 = GET_SKILL_NODE(48, PhaseNode_PlayAnimation);
    if (node48 == nullptr) {
        node48 = new PhaseNode_PlayAnimation(48, phase);
        node48->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node48->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node48->setTarget(0U);
        node48->setAnimation("Idle");
        node48->setParameter("");
        node48->setValue(false);
        CALL_REGISTER_SKILL_NODE(10351, 48, node48)
    }
    if (noInit == true) {
        return node48;
    }
    return node48;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10351, 49) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_Delay::TRIGGER_DONE, 52, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(10351, 49) {
    auto node49 = GET_SKILL_NODE(49, PhaseNode_Delay);
    if (node49 == nullptr) {
        node49 = new PhaseNode_Delay(49, phase);
        node49->setTime(.20f);
        CALL_REGISTER_SKILL_NODE(10351, 49, node49)
    }
    if (noInit == true) {
        return node49;
    }
    return node49;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(10351, 52) {
}

REGISTER_CREATE_SKILL_NODE(10351, 52) {
    auto node52 = GET_SKILL_NODE(52, PhaseNode_SetBool);
    if (node52 == nullptr) {
        node52 = new PhaseNode_SetBool(52, phase);
        node52->setName("InterruptAnimat");
        node52->setValue(true);
        CALL_REGISTER_SKILL_NODE(10351, 52, node52)
    }
    if (noInit == true) {
        return node52;
    }
    return node52;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10351, 53) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StartPreInput>(PhaseNode_RaiseEvent::TRIGGER_DONE, 45, PhaseNode_StartPreInput::FUNC_DO, &PhaseNode_StartPreInput::Do);
}

REGISTER_CREATE_SKILL_NODE(10351, 53) {
    auto node53 = GET_SKILL_NODE(53, PhaseNode_RaiseEvent);
    if (node53 == nullptr) {
        node53 = new PhaseNode_RaiseEvent(53, phase);
        node53->setEvent("Dead_001");
        node53->setTarget(0U);
        node53->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node53->setTypeParams(0, 0);
        node53->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10351, 53, node53)
    }
    if (noInit == true) {
        return node53;
    }
    return node53;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10351, 54) {
}

REGISTER_CREATE_SKILL_NODE(10351, 54) {
    auto node54 = GET_SKILL_NODE(54, PhaseNode_Detect);
    if (node54 == nullptr) {
        node54 = new PhaseNode_Detect(54, phase);
        node54->setSelf(0U);
        node54->setEvent("Dead_001");
        node54->setType(PhaseNode_Detect::Detect_Type::Actor_Dead);
        node54->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10351, 54, node54)
    }
    if (noInit == true) {
        return node54;
    }
    return node54;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(10351, 55) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_ResetCD::TRIGGER_DONE, 56, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10351, 55) {
    auto node55 = GET_SKILL_NODE(55, PhaseNode_ResetCD);
    if (node55 == nullptr) {
        node55 = new PhaseNode_ResetCD(55, phase);
        node55->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node55->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node55->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(10351, 55, node55)
    }
    if (noInit == true) {
        return node55;
    }
    return node55;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10351, 56) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_PlayAnimation::TRIGGER_DONE, 58, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(10351, 56) {
    auto node56 = GET_SKILL_NODE(56, PhaseNode_PlayAnimation);
    if (node56 == nullptr) {
        node56 = new PhaseNode_PlayAnimation(56, phase);
        node56->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node56->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node56->setTarget(0U);
        node56->setAnimation("Skill1S1");
        node56->setParameter("");
        node56->setValue(false);
        CALL_REGISTER_SKILL_NODE(10351, 56, node56)
    }
    if (noInit == true) {
        return node56;
    }
    return node56;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10351, 57) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_PlaySound::TRIGGER_DONE, 9, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_PlaySound::TRIGGER_DONE, 16, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(10351, 57) {
    auto node57 = GET_SKILL_NODE(57, PhaseNode_PlaySound);
    if (node57 == nullptr) {
        node57 = new PhaseNode_PlaySound(57, phase);
        node57->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node57->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node57->setSoundID("");
        node57->setTarget(0U);
        node57->setUsePos(false);
        node57->setPosX(.00f);
        node57->setPosY(.00f);
        node57->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10351, 57, node57)
    }
    if (noInit == true) {
        return node57;
    }
    return node57;
}
//--------------------------------------------------------------------------------
// GetActorAttribute
//
REGISTER_REGISTER_SKILL_NODE(10351, 58) {
    pnode->resizeTrigger(PhaseNode_GetActorAttribute::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 57, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10351, 58) {
    auto node58 = GET_SKILL_NODE(58, PhaseNode_GetActorAttribute);
    if (node58 == nullptr) {
        node58 = new PhaseNode_GetActorAttribute(58, phase);
        node58->setTarget(0U);
        node58->setType({});
        CALL_REGISTER_SKILL_NODE(10351, 58, node58)
    }
    if (noInit == true) {
        return node58;
    }
    return node58;
}

//--------------------------------------------------------------------------------
// SkillCreator_10351
//
class SkillCreator_10351 : public SkillCreator {
public:
    SkillCreator_10351() {}
    virtual ~SkillCreator_10351() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_10351

//--------------------------------------------------------------------------------
// SkillPhase_10351
//
class SkillPhase_10351 : public SkillPhase {
public:
    SkillPhase_10351(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_10351() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(10351, 4) // StartPhase
        CASE_CREATE_SKILL_NODE(10351, 9) // PlaySound
        CASE_CREATE_SKILL_NODE(10351, 16) // ResetCD
        CASE_CREATE_SKILL_NODE(10351, 18) // GetLocation
        CASE_CREATE_SKILL_NODE(10351, 20) // Disable
        CASE_CREATE_SKILL_NODE(10351, 22) // Delay
        CASE_CREATE_SKILL_NODE(10351, 27) // PlayEffect
        CASE_CREATE_SKILL_NODE(10351, 30) // GetInputRotation
        CASE_CREATE_SKILL_NODE(10351, 32) // OffsetCalculate
        CASE_CREATE_SKILL_NODE(10351, 34) // SpawnProjectile
        CASE_CREATE_SKILL_NODE(10351, 36) // Delay
        CASE_CREATE_SKILL_NODE(10351, 39) // EndPhase
        CASE_CREATE_SKILL_NODE(10351, 41) // Detect
        CASE_CREATE_SKILL_NODE(10351, 42) // SwitchToInt
        CASE_CREATE_SKILL_NODE(10351, 44) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10351, 45) // StartPreInput
        CASE_CREATE_SKILL_NODE(10351, 46) // If
        CASE_CREATE_SKILL_NODE(10351, 47) // IsInterruptType
        CASE_CREATE_SKILL_NODE(10351, 48) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10351, 49) // Delay
        CASE_CREATE_SKILL_NODE(10351, 52) // SetBool
        CASE_CREATE_SKILL_NODE(10351, 53) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10351, 54) // Detect
        CASE_CREATE_SKILL_NODE(10351, 55) // ResetCD
        CASE_CREATE_SKILL_NODE(10351, 56) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10351, 57) // PlaySound
        CASE_CREATE_SKILL_NODE(10351, 58) // GetActorAttribute
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_10351

SkillLogic* SkillCreator_10351::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //设置变量
    Variable_10351_a103511 = logic->getVariables().setVariable<int32_t>("a103511", 1);
    Variable_10351_InterruptAnimat = logic->getVariables().setVariable<bool>("InterruptAnimat");
    //创建阶段phase
    auto phase = new SkillPhase_10351(1, logic, 2);
    //设置phase执行器
    phase->setRunPhaseNode(1, 4);
    phase->setDetectPhaseNode(2, 41);
    phase->setDetectPhaseNode(2, 54);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_10351::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
