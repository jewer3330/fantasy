#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

#include "skill_psnode_delay.h"
#include "skill_psnode_detect.h"
#include "skill_psnode_disable.h"
#include "skill_psnode_endphase.h"
#include "skill_psnode_getactorattribute.h"
#include "skill_psnode_getinputlocation.h"
#include "skill_psnode_getlocation.h"
#include "skill_psnode_getrotation.h"
#include "skill_psnode_if.h"
#include "skill_psnode_isinterrupttype.h"
#include "skill_psnode_offsetcalculate.h"
#include "skill_psnode_playanimation.h"
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
uint64_t Variable_10112_a101122 = 0;
uint64_t Variable_10112_InterruptAnimat = 0;
//--------------------------------------------------------------------------------
// StartPhase
//
REGISTER_REGISTER_SKILL_NODE(10112, 1) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_StartPhase::TRIGGER_START, 144, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(10112, 1) {
    auto node1 = GET_SKILL_NODE(1, PhaseNode_StartPhase);
    if (node1 == nullptr) {
        node1 = new PhaseNode_StartPhase(1, phase);
        CALL_REGISTER_SKILL_NODE(10112, 1, node1)
    }
    if (noInit == true) {
        return node1;
    }
    return node1;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(10112, 11) {
}

REGISTER_CREATE_SKILL_NODE(10112, 11) {
    auto node11 = GET_SKILL_NODE(11, PhaseNode_EndPhase);
    if (node11 == nullptr) {
        node11 = new PhaseNode_EndPhase(11, phase);
        node11->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node11->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10112, 11, node11)
    }
    if (noInit == true) {
        return node11;
    }
    return node11;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10112, 16) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetRotation>(PhaseNode_Delay::TRIGGER_DONE, 139, PhaseNode_GetRotation::FUNC_DO, &PhaseNode_GetRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(10112, 16) {
    auto node16 = GET_SKILL_NODE(16, PhaseNode_Delay);
    if (node16 == nullptr) {
        node16 = new PhaseNode_Delay(16, phase);
        node16->setTime(.11f);
        CALL_REGISTER_SKILL_NODE(10112, 16, node16)
    }
    if (noInit == true) {
        return node16;
    }
    return node16;
}
//--------------------------------------------------------------------------------
// OffsetCalculate
//
REGISTER_REGISTER_SKILL_NODE(10112, 27) {
    pnode->resizeTrigger(PhaseNode_OffsetCalculate::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnProjectile>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 137, PhaseNode_SpawnProjectile::FUNC_DO, &PhaseNode_SpawnProjectile::Do);
}

REGISTER_CREATE_SKILL_NODE(10112, 27) {
    auto node27 = GET_SKILL_NODE(27, PhaseNode_OffsetCalculate);
    if (node27 == nullptr) {
        node27 = new PhaseNode_OffsetCalculate(27, phase);
        node27->setPosZ(1.40f);
        node27->setOffsetX(.00f);
        node27->setOffsetY(.50f);
        node27->setOffsetZ(.00f);
        node27->setRotOffset(.00f);
        CALL_REGISTER_SKILL_NODE(10112, 27, node27)
    }
    if (noInit == true) {
        return node27;
    }
    auto node141 = GET_SKILL_NODE(141, PhaseNode_GetLocation);
    auto node139 = GET_SKILL_NODE(139, PhaseNode_GetRotation);
    if (node141 != nullptr) node27->setPosX(node141->getX());
    if (node141 != nullptr) node27->setPosY(node141->getY());
    if (node139 != nullptr) node27->setRotation(node139->getAngle());
    return node27;
}
//--------------------------------------------------------------------------------
// Disable
//
REGISTER_REGISTER_SKILL_NODE(10112, 36) {
    pnode->resizeTrigger(PhaseNode_Disable::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_Disable::TRIGGER_DONE, 152, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10112, 36) {
    auto node36 = GET_SKILL_NODE(36, PhaseNode_Disable);
    if (node36 == nullptr) {
        node36 = new PhaseNode_Disable(36, phase);
        node36->setTarget(0U);
        node36->setMove(true);
        node36->setSkill(true);
        node36->setShoot(true);
        node36->setTime(.40f);
        node36->setRotate(true);
        CALL_REGISTER_SKILL_NODE(10112, 36, node36)
    }
    if (noInit == true) {
        return node36;
    }
    return node36;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10112, 55) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlaySound::TRIGGER_DONE, 92, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10112, 55) {
    auto node55 = GET_SKILL_NODE(55, PhaseNode_PlaySound);
    if (node55 == nullptr) {
        node55 = new PhaseNode_PlaySound(55, phase);
        node55->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node55->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node55->setSoundID("SE_Hero102_Skill_B_P1");
        node55->setTarget(0U);
        node55->setUsePos(false);
        node55->setPosX(.00f);
        node55->setPosY(.00f);
        node55->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10112, 55, node55)
    }
    if (noInit == true) {
        return node55;
    }
    return node55;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10112, 92) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_Delay::TRIGGER_DONE, 11, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(10112, 92) {
    auto node92 = GET_SKILL_NODE(92, PhaseNode_Delay);
    if (node92 == nullptr) {
        node92 = new PhaseNode_Delay(92, phase);
        node92->setTime(.49f);
        CALL_REGISTER_SKILL_NODE(10112, 92, node92)
    }
    if (noInit == true) {
        return node92;
    }
    return node92;
}
//--------------------------------------------------------------------------------
// SpawnProjectile
//
REGISTER_REGISTER_SKILL_NODE(10112, 137) {
    pnode->resizeTrigger(PhaseNode_SpawnProjectile::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_SpawnProjectile::TRIGGER_DONE, 55, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10112, 137) {
    auto node137 = GET_SKILL_NODE(137, PhaseNode_SpawnProjectile);
    if (node137 == nullptr) {
        node137 = new PhaseNode_SpawnProjectile(137, phase);
        node137->setDataId(55112);
        node137->setEndPosZ(.00f);
        node137->setMaxCount(0);
        CALL_REGISTER_SKILL_NODE(10112, 137, node137)
    }
    if (noInit == true) {
        return node137;
    }
    auto node27 = GET_SKILL_NODE(27, PhaseNode_OffsetCalculate);
    auto node143 = GET_SKILL_NODE(143, PhaseNode_GetInputLocation);
    if (node27 != nullptr) node137->setPosX(node27->getOutPosX());
    if (node27 != nullptr) node137->setPosY(node27->getOutPosY());
    if (node27 != nullptr) node137->setPosZ(node27->getOutPosZ());
    if (node143 != nullptr) node137->setEndPosX(node143->getX());
    if (node143 != nullptr) node137->setEndPosY(node143->getY());
    if (node27 != nullptr) node137->setRotation(node27->getOutRotation());
    return node137;
}
//--------------------------------------------------------------------------------
// GetRotation
//
REGISTER_REGISTER_SKILL_NODE(10112, 139) {
    pnode->resizeTrigger(PhaseNode_GetRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_OffsetCalculate>(PhaseNode_GetRotation::TRIGGER_DONE, 27, PhaseNode_OffsetCalculate::FUNC_DO, &PhaseNode_OffsetCalculate::Do);
}

REGISTER_CREATE_SKILL_NODE(10112, 139) {
    auto node139 = GET_SKILL_NODE(139, PhaseNode_GetRotation);
    if (node139 == nullptr) {
        node139 = new PhaseNode_GetRotation(139, phase);
        node139->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node139->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(10112, 139, node139)
    }
    if (noInit == true) {
        return node139;
    }
    return node139;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(10112, 141) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetInputLocation>(PhaseNode_GetLocation::TRIGGER_DONE, 143, PhaseNode_GetInputLocation::FUNC_DO, &PhaseNode_GetInputLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(10112, 141) {
    auto node141 = GET_SKILL_NODE(141, PhaseNode_GetLocation);
    if (node141 == nullptr) {
        node141 = new PhaseNode_GetLocation(141, phase);
        node141->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node141->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(10112, 141, node141)
    }
    if (noInit == true) {
        return node141;
    }
    return node141;
}
//--------------------------------------------------------------------------------
// GetInputLocation
//
REGISTER_REGISTER_SKILL_NODE(10112, 143) {
    pnode->resizeTrigger(PhaseNode_GetInputLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Disable>(PhaseNode_GetInputLocation::TRIGGER_DONE, 36, PhaseNode_Disable::FUNC_DO, &PhaseNode_Disable::Do);
}

REGISTER_CREATE_SKILL_NODE(10112, 143) {
    auto node143 = GET_SKILL_NODE(143, PhaseNode_GetInputLocation);
    if (node143 == nullptr) {
        node143 = new PhaseNode_GetInputLocation(143, phase);
        node143->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        CALL_REGISTER_SKILL_NODE(10112, 143, node143)
    }
    if (noInit == true) {
        return node143;
    }
    return node143;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(10112, 144) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_ResetCD::TRIGGER_DONE, 145, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10112, 144) {
    auto node144 = GET_SKILL_NODE(144, PhaseNode_ResetCD);
    if (node144 == nullptr) {
        node144 = new PhaseNode_ResetCD(144, phase);
        node144->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node144->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node144->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(10112, 144, node144)
    }
    if (noInit == true) {
        return node144;
    }
    return node144;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10112, 145) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_PlayAnimation::TRIGGER_DONE, 147, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(10112, 145) {
    auto node145 = GET_SKILL_NODE(145, PhaseNode_PlayAnimation);
    if (node145 == nullptr) {
        node145 = new PhaseNode_PlayAnimation(145, phase);
        node145->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node145->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node145->setTarget(0U);
        node145->setAnimation("Skill2S1");
        node145->setParameter("");
        node145->setValue(false);
        CALL_REGISTER_SKILL_NODE(10112, 145, node145)
    }
    if (noInit == true) {
        return node145;
    }
    return node145;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10112, 146) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_PlaySound::TRIGGER_DONE, 141, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(10112, 146) {
    auto node146 = GET_SKILL_NODE(146, PhaseNode_PlaySound);
    if (node146 == nullptr) {
        node146 = new PhaseNode_PlaySound(146, phase);
        node146->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node146->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node146->setSoundID("VO_Hero102_Skill_B");
        node146->setTarget(0U);
        node146->setUsePos(false);
        node146->setPosX(.00f);
        node146->setPosY(.00f);
        node146->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10112, 146, node146)
    }
    if (noInit == true) {
        return node146;
    }
    return node146;
}
//--------------------------------------------------------------------------------
// GetActorAttribute
//
REGISTER_REGISTER_SKILL_NODE(10112, 147) {
    pnode->resizeTrigger(PhaseNode_GetActorAttribute::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 146, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10112, 147) {
    auto node147 = GET_SKILL_NODE(147, PhaseNode_GetActorAttribute);
    if (node147 == nullptr) {
        node147 = new PhaseNode_GetActorAttribute(147, phase);
        node147->setTarget(0U);
        node147->setType({});
        CALL_REGISTER_SKILL_NODE(10112, 147, node147)
    }
    if (noInit == true) {
        return node147;
    }
    return node147;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10112, 149) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_IsInterruptType>(PhaseNode_Detect::TRIGGER_ON, 155, PhaseNode_IsInterruptType::FUNC_DO, &PhaseNode_IsInterruptType::Do);
}

REGISTER_CREATE_SKILL_NODE(10112, 149) {
    auto node149 = GET_SKILL_NODE(149, PhaseNode_Detect);
    if (node149 == nullptr) {
        node149 = new PhaseNode_Detect(149, phase);
        node149->setSelf(0U);
        node149->setEvent("daduan_001");
        node149->setType(PhaseNode_Detect::Detect_Type::Interrupt_Skill);
        node149->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10112, 149, node149)
    }
    if (noInit == true) {
        return node149;
    }
    return node149;
}
//--------------------------------------------------------------------------------
// SwitchToInt
//
REGISTER_REGISTER_SKILL_NODE(10112, 150) {
    pnode->resizeTrigger(4);
    pnode->regTrigger<PhaseNode_EndPhase>(1, 11, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(10112, 150) {
    auto node150 = GET_SKILL_NODE(150, PhaseNode_SwitchToInt);
    if (node150 == nullptr) {
        node150 = new PhaseNode_SwitchToInt(150, phase);
        CALL_REGISTER_SKILL_NODE(10112, 150, node150)
    }
    if (noInit == true) {
        return node150;
    }
    auto variables = node150->getVariables();
    if (variables != nullptr) {
        node150->setSelection(variables->getVariable<int32_t>(Variable_10112_a101122));
    }
    return node150;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10112, 152) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_RaiseEvent::TRIGGER_DONE, 161, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10112, 152) {
    auto node152 = GET_SKILL_NODE(152, PhaseNode_RaiseEvent);
    if (node152 == nullptr) {
        node152 = new PhaseNode_RaiseEvent(152, phase);
        node152->setEvent("daduan_001");
        node152->setTarget(0U);
        node152->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node152->setTypeParams(0, 0);
        node152->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10112, 152, node152)
    }
    if (noInit == true) {
        return node152;
    }
    return node152;
}
//--------------------------------------------------------------------------------
// StartPreInput
//
REGISTER_REGISTER_SKILL_NODE(10112, 153) {
    pnode->resizeTrigger(PhaseNode_StartPreInput::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_StartPreInput::TRIGGER_DONE, 157, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_StartPreInput::TRIGGER_DONE, 16, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10112, 153) {
    auto node153 = GET_SKILL_NODE(153, PhaseNode_StartPreInput);
    if (node153 == nullptr) {
        node153 = new PhaseNode_StartPreInput(153, phase);
        node153->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node153->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node153->setDelayTime(.00f);
        CALL_REGISTER_SKILL_NODE(10112, 153, node153)
    }
    if (noInit == true) {
        return node153;
    }
    return node153;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(10112, 154) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_If::TRIGGER_TRUE, 156, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10112, 154) {
    auto node154 = GET_SKILL_NODE(154, PhaseNode_If);
    if (node154 == nullptr) {
        node154 = new PhaseNode_If(154, phase);
        CALL_REGISTER_SKILL_NODE(10112, 154, node154)
    }
    if (noInit == true) {
        return node154;
    }
    auto variables = node154->getVariables();
    if (variables != nullptr) {
        node154->setCondition(variables->getVariable<bool>(Variable_10112_InterruptAnimat));
    }
    return node154;
}
//--------------------------------------------------------------------------------
// IsInterruptType
//
REGISTER_REGISTER_SKILL_NODE(10112, 155) {
    pnode->resizeTrigger(PhaseNode_IsInterruptType::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SwitchToInt>(PhaseNode_IsInterruptType::TRIGGER_BUFF, 150, PhaseNode_SwitchToInt::FUNC_SWITCH, &PhaseNode_SwitchToInt::Switch);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_POSCHANGE, 154, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTAIM, 154, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTFIRE, 154, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTRELOAD, 154, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_USESKILL, 154, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(10112, 155) {
    auto node155 = GET_SKILL_NODE(155, PhaseNode_IsInterruptType);
    if (node155 == nullptr) {
        node155 = new PhaseNode_IsInterruptType(155, phase);
        node155->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node155->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10112, 155, node155)
    }
    if (noInit == true) {
        return node155;
    }
    auto node149 = GET_SKILL_NODE(149, PhaseNode_Detect);
    if (node149 != nullptr) node155->setType(node149->getVars().getVariable<int32_t>(2));
    return node155;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10112, 156) {
}

REGISTER_CREATE_SKILL_NODE(10112, 156) {
    auto node156 = GET_SKILL_NODE(156, PhaseNode_PlayAnimation);
    if (node156 == nullptr) {
        node156 = new PhaseNode_PlayAnimation(156, phase);
        node156->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node156->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node156->setTarget(0U);
        node156->setAnimation("Idle");
        node156->setParameter("");
        node156->setValue(false);
        CALL_REGISTER_SKILL_NODE(10112, 156, node156)
    }
    if (noInit == true) {
        return node156;
    }
    return node156;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10112, 157) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_Delay::TRIGGER_DONE, 160, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(10112, 157) {
    auto node157 = GET_SKILL_NODE(157, PhaseNode_Delay);
    if (node157 == nullptr) {
        node157 = new PhaseNode_Delay(157, phase);
        node157->setTime(.20f);
        CALL_REGISTER_SKILL_NODE(10112, 157, node157)
    }
    if (noInit == true) {
        return node157;
    }
    return node157;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(10112, 160) {
}

REGISTER_CREATE_SKILL_NODE(10112, 160) {
    auto node160 = GET_SKILL_NODE(160, PhaseNode_SetBool);
    if (node160 == nullptr) {
        node160 = new PhaseNode_SetBool(160, phase);
        node160->setName("InterruptAnimat");
        node160->setValue(true);
        CALL_REGISTER_SKILL_NODE(10112, 160, node160)
    }
    if (noInit == true) {
        return node160;
    }
    return node160;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10112, 161) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StartPreInput>(PhaseNode_RaiseEvent::TRIGGER_DONE, 153, PhaseNode_StartPreInput::FUNC_DO, &PhaseNode_StartPreInput::Do);
}

REGISTER_CREATE_SKILL_NODE(10112, 161) {
    auto node161 = GET_SKILL_NODE(161, PhaseNode_RaiseEvent);
    if (node161 == nullptr) {
        node161 = new PhaseNode_RaiseEvent(161, phase);
        node161->setEvent("Dead_001");
        node161->setTarget(0U);
        node161->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node161->setTypeParams(0, 0);
        node161->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10112, 161, node161)
    }
    if (noInit == true) {
        return node161;
    }
    return node161;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10112, 162) {
}

REGISTER_CREATE_SKILL_NODE(10112, 162) {
    auto node162 = GET_SKILL_NODE(162, PhaseNode_Detect);
    if (node162 == nullptr) {
        node162 = new PhaseNode_Detect(162, phase);
        node162->setSelf(0U);
        node162->setEvent("Dead_001");
        node162->setType(PhaseNode_Detect::Detect_Type::Actor_Dead);
        node162->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10112, 162, node162)
    }
    if (noInit == true) {
        return node162;
    }
    return node162;
}

//--------------------------------------------------------------------------------
// SkillCreator_10112
//
class SkillCreator_10112 : public SkillCreator {
public:
    SkillCreator_10112() {}
    virtual ~SkillCreator_10112() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_10112

//--------------------------------------------------------------------------------
// SkillPhase_10112
//
class SkillPhase_10112 : public SkillPhase {
public:
    SkillPhase_10112(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_10112() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(10112, 1) // StartPhase
        CASE_CREATE_SKILL_NODE(10112, 11) // EndPhase
        CASE_CREATE_SKILL_NODE(10112, 16) // Delay
        CASE_CREATE_SKILL_NODE(10112, 27) // OffsetCalculate
        CASE_CREATE_SKILL_NODE(10112, 36) // Disable
        CASE_CREATE_SKILL_NODE(10112, 55) // PlaySound
        CASE_CREATE_SKILL_NODE(10112, 92) // Delay
        CASE_CREATE_SKILL_NODE(10112, 137) // SpawnProjectile
        CASE_CREATE_SKILL_NODE(10112, 139) // GetRotation
        CASE_CREATE_SKILL_NODE(10112, 141) // GetLocation
        CASE_CREATE_SKILL_NODE(10112, 143) // GetInputLocation
        CASE_CREATE_SKILL_NODE(10112, 144) // ResetCD
        CASE_CREATE_SKILL_NODE(10112, 145) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10112, 146) // PlaySound
        CASE_CREATE_SKILL_NODE(10112, 147) // GetActorAttribute
        CASE_CREATE_SKILL_NODE(10112, 149) // Detect
        CASE_CREATE_SKILL_NODE(10112, 150) // SwitchToInt
        CASE_CREATE_SKILL_NODE(10112, 152) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10112, 153) // StartPreInput
        CASE_CREATE_SKILL_NODE(10112, 154) // If
        CASE_CREATE_SKILL_NODE(10112, 155) // IsInterruptType
        CASE_CREATE_SKILL_NODE(10112, 156) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10112, 157) // Delay
        CASE_CREATE_SKILL_NODE(10112, 160) // SetBool
        CASE_CREATE_SKILL_NODE(10112, 161) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10112, 162) // Detect
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_10112

SkillLogic* SkillCreator_10112::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //设置变量
    Variable_10112_a101122 = logic->getVariables().setVariable<int32_t>("a101122", 1);
    Variable_10112_InterruptAnimat = logic->getVariables().setVariable<bool>("InterruptAnimat");
    //创建阶段phase
    auto phase = new SkillPhase_10112(1, logic, 2);
    //设置phase执行器
    phase->setRunPhaseNode(1, 1);
    phase->setDetectPhaseNode(2, 149);
    phase->setDetectPhaseNode(2, 162);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_10112::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
