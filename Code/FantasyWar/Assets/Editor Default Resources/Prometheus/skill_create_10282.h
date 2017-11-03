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
#include "skill_psnode_playanimation.h"
#include "skill_psnode_playeffect.h"
#include "skill_psnode_playsound.h"
#include "skill_psnode_raiseevent.h"
#include "skill_psnode_resetcd.h"
#include "skill_psnode_setbool.h"
#include "skill_psnode_setint.h"
#include "skill_psnode_spawnprojectile.h"
#include "skill_psnode_startphase.h"
#include "skill_psnode_startpreinput.h"
#include "skill_psnode_switchtoint.h"

namespace pvp {

//变量声明
uint64_t Variable_10282_a102822 = 0;
uint64_t Variable_10282_InterruptAnimat = 0;
//--------------------------------------------------------------------------------
// StartPhase
//
REGISTER_REGISTER_SKILL_NODE(10282, 4) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_StartPhase::TRIGGER_START, 149, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(10282, 4) {
    auto node4 = GET_SKILL_NODE(4, PhaseNode_StartPhase);
    if (node4 == nullptr) {
        node4 = new PhaseNode_StartPhase(4, phase);
        CALL_REGISTER_SKILL_NODE(10282, 4, node4)
    }
    if (noInit == true) {
        return node4;
    }
    return node4;
}
//--------------------------------------------------------------------------------
// Disable
//
REGISTER_REGISTER_SKILL_NODE(10282, 11) {
    pnode->resizeTrigger(PhaseNode_Disable::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_Disable::TRIGGER_DONE, 77, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(10282, 11) {
    auto node11 = GET_SKILL_NODE(11, PhaseNode_Disable);
    if (node11 == nullptr) {
        node11 = new PhaseNode_Disable(11, phase);
        node11->setTarget(0U);
        node11->setMove(true);
        node11->setSkill(true);
        node11->setShoot(true);
        node11->setTime(.50f);
        node11->setRotate(true);
        CALL_REGISTER_SKILL_NODE(10282, 11, node11)
    }
    if (noInit == true) {
        return node11;
    }
    return node11;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(10282, 15) {
}

REGISTER_CREATE_SKILL_NODE(10282, 15) {
    auto node15 = GET_SKILL_NODE(15, PhaseNode_EndPhase);
    if (node15 == nullptr) {
        node15 = new PhaseNode_EndPhase(15, phase);
        node15->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node15->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10282, 15, node15)
    }
    if (noInit == true) {
        return node15;
    }
    return node15;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10282, 20) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CameraXYZShake>(PhaseNode_Delay::TRIGGER_DONE, 142, PhaseNode_CameraXYZShake::FUNC_DO, &PhaseNode_CameraXYZShake::Do);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_Delay::TRIGGER_DONE, 105, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
    pnode->regTrigger<PhaseNode_SpawnProjectile>(PhaseNode_Delay::TRIGGER_DONE, 140, PhaseNode_SpawnProjectile::FUNC_DO, &PhaseNode_SpawnProjectile::Do);
}

REGISTER_CREATE_SKILL_NODE(10282, 20) {
    auto node20 = GET_SKILL_NODE(20, PhaseNode_Delay);
    if (node20 == nullptr) {
        node20 = new PhaseNode_Delay(20, phase);
        node20->setTime(.20f);
        CALL_REGISTER_SKILL_NODE(10282, 20, node20)
    }
    if (noInit == true) {
        return node20;
    }
    return node20;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10282, 46) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_Delay::TRIGGER_DONE, 15, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(10282, 46) {
    auto node46 = GET_SKILL_NODE(46, PhaseNode_Delay);
    if (node46 == nullptr) {
        node46 = new PhaseNode_Delay(46, phase);
        node46->setTime(.50f);
        CALL_REGISTER_SKILL_NODE(10282, 46, node46)
    }
    if (noInit == true) {
        return node46;
    }
    return node46;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(10282, 77) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlayEffect::TRIGGER_DONE, 20, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10282, 77) {
    auto node77 = GET_SKILL_NODE(77, PhaseNode_PlayEffect);
    if (node77 == nullptr) {
        node77 = new PhaseNode_PlayEffect(77, phase);
        node77->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node77->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node77->setEffectID(102822);
        node77->setChangeColor(false);
        node77->setType(PhaseNode_PlayEffect::PlayEffect_Type::WithTarget);
        node77->getVars().reserve(5);
        node77->getVars().setVariable<uint64_t>(0, 0U);
        node77->getVars().setVariable<std::string>(1, "Bip001 R Hand");
        node77->getVars().setVariable<float>(2, .00f);
        node77->getVars().setVariable<float>(3, .00f);
        node77->getVars().setVariable<float>(4, .00f);
        node77->setRotation(.00f);
        node77->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(10282, 77, node77)
    }
    if (noInit == true) {
        return node77;
    }
    return node77;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10282, 105) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetInt>(PhaseNode_PlaySound::TRIGGER_DONE, 126, PhaseNode_SetInt::FUNC_SET, &PhaseNode_SetInt::Set);
}

REGISTER_CREATE_SKILL_NODE(10282, 105) {
    auto node105 = GET_SKILL_NODE(105, PhaseNode_PlaySound);
    if (node105 == nullptr) {
        node105 = new PhaseNode_PlaySound(105, phase);
        node105->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node105->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node105->setSoundID("SE_Hero107_SkillB_P1");
        node105->setTarget(0U);
        node105->setUsePos(false);
        node105->setPosX(.00f);
        node105->setPosY(.00f);
        node105->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10282, 105, node105)
    }
    if (noInit == true) {
        return node105;
    }
    return node105;
}
//--------------------------------------------------------------------------------
// SetInt
//
REGISTER_REGISTER_SKILL_NODE(10282, 126) {
}

REGISTER_CREATE_SKILL_NODE(10282, 126) {
    auto node126 = GET_SKILL_NODE(126, PhaseNode_SetInt);
    if (node126 == nullptr) {
        node126 = new PhaseNode_SetInt(126, phase);
        node126->setName("a102822");
        node126->setValue(2);
        CALL_REGISTER_SKILL_NODE(10282, 126, node126)
    }
    if (noInit == true) {
        return node126;
    }
    return node126;
}
//--------------------------------------------------------------------------------
// SpawnProjectile
//
REGISTER_REGISTER_SKILL_NODE(10282, 140) {
    pnode->resizeTrigger(PhaseNode_SpawnProjectile::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_SpawnProjectile::TRIGGER_DONE, 46, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10282, 140) {
    auto node140 = GET_SKILL_NODE(140, PhaseNode_SpawnProjectile);
    if (node140 == nullptr) {
        node140 = new PhaseNode_SpawnProjectile(140, phase);
        node140->setDataId(55281);
        node140->setPosZ(.00f);
        node140->setEndPosX(.00f);
        node140->setEndPosY(.00f);
        node140->setEndPosZ(.00f);
        node140->setMaxCount(0);
        CALL_REGISTER_SKILL_NODE(10282, 140, node140)
    }
    if (noInit == true) {
        return node140;
    }
    auto node146 = GET_SKILL_NODE(146, PhaseNode_GetLocation);
    auto node148 = GET_SKILL_NODE(148, PhaseNode_GetInputRotation);
    if (node146 != nullptr) node140->setPosX(node146->getX());
    if (node146 != nullptr) node140->setPosY(node146->getY());
    if (node148 != nullptr) node140->setRotation(node148->getAngle());
    return node140;
}
//--------------------------------------------------------------------------------
// CameraXYZShake
//
REGISTER_REGISTER_SKILL_NODE(10282, 142) {
}

REGISTER_CREATE_SKILL_NODE(10282, 142) {
    auto node142 = GET_SKILL_NODE(142, PhaseNode_CameraXYZShake);
    if (node142 == nullptr) {
        node142 = new PhaseNode_CameraXYZShake(142, phase);
        node142->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node142->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node142->setShakeStyle(1);
        node142->setTarget(0U);
        node142->setX(.10f);
        node142->setY(.10f);
        node142->setZ(.10f);
        node142->setDuration(.10f);
        node142->setTimes(1);
        CALL_REGISTER_SKILL_NODE(10282, 142, node142)
    }
    if (noInit == true) {
        return node142;
    }
    return node142;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(10282, 146) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetInputRotation>(PhaseNode_GetLocation::TRIGGER_DONE, 148, PhaseNode_GetInputRotation::FUNC_DO, &PhaseNode_GetInputRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(10282, 146) {
    auto node146 = GET_SKILL_NODE(146, PhaseNode_GetLocation);
    if (node146 == nullptr) {
        node146 = new PhaseNode_GetLocation(146, phase);
        node146->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node146->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(10282, 146, node146)
    }
    if (noInit == true) {
        return node146;
    }
    return node146;
}
//--------------------------------------------------------------------------------
// GetInputRotation
//
REGISTER_REGISTER_SKILL_NODE(10282, 148) {
    pnode->resizeTrigger(PhaseNode_GetInputRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Disable>(PhaseNode_GetInputRotation::TRIGGER_DONE, 11, PhaseNode_Disable::FUNC_DO, &PhaseNode_Disable::Do);
}

REGISTER_CREATE_SKILL_NODE(10282, 148) {
    auto node148 = GET_SKILL_NODE(148, PhaseNode_GetInputRotation);
    if (node148 == nullptr) {
        node148 = new PhaseNode_GetInputRotation(148, phase);
        node148->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        CALL_REGISTER_SKILL_NODE(10282, 148, node148)
    }
    if (noInit == true) {
        return node148;
    }
    return node148;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(10282, 149) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_ResetCD::TRIGGER_DONE, 150, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10282, 149) {
    auto node149 = GET_SKILL_NODE(149, PhaseNode_ResetCD);
    if (node149 == nullptr) {
        node149 = new PhaseNode_ResetCD(149, phase);
        node149->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node149->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node149->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(10282, 149, node149)
    }
    if (noInit == true) {
        return node149;
    }
    return node149;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10282, 150) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_PlayAnimation::TRIGGER_DONE, 152, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(10282, 150) {
    auto node150 = GET_SKILL_NODE(150, PhaseNode_PlayAnimation);
    if (node150 == nullptr) {
        node150 = new PhaseNode_PlayAnimation(150, phase);
        node150->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node150->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node150->setTarget(0U);
        node150->setAnimation("Skill2S1");
        node150->setParameter("");
        node150->setValue(false);
        CALL_REGISTER_SKILL_NODE(10282, 150, node150)
    }
    if (noInit == true) {
        return node150;
    }
    return node150;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10282, 151) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_PlaySound::TRIGGER_DONE, 146, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_PlaySound::TRIGGER_DONE, 157, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10282, 151) {
    auto node151 = GET_SKILL_NODE(151, PhaseNode_PlaySound);
    if (node151 == nullptr) {
        node151 = new PhaseNode_PlaySound(151, phase);
        node151->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node151->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node151->setSoundID("");
        node151->setTarget(0U);
        node151->setUsePos(false);
        node151->setPosX(.00f);
        node151->setPosY(.00f);
        node151->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10282, 151, node151)
    }
    if (noInit == true) {
        return node151;
    }
    return node151;
}
//--------------------------------------------------------------------------------
// GetActorAttribute
//
REGISTER_REGISTER_SKILL_NODE(10282, 152) {
    pnode->resizeTrigger(PhaseNode_GetActorAttribute::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 151, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10282, 152) {
    auto node152 = GET_SKILL_NODE(152, PhaseNode_GetActorAttribute);
    if (node152 == nullptr) {
        node152 = new PhaseNode_GetActorAttribute(152, phase);
        node152->setTarget(0U);
        node152->setType({});
        CALL_REGISTER_SKILL_NODE(10282, 152, node152)
    }
    if (noInit == true) {
        return node152;
    }
    return node152;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10282, 154) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_IsInterruptType>(PhaseNode_Detect::TRIGGER_ON, 160, PhaseNode_IsInterruptType::FUNC_DO, &PhaseNode_IsInterruptType::Do);
}

REGISTER_CREATE_SKILL_NODE(10282, 154) {
    auto node154 = GET_SKILL_NODE(154, PhaseNode_Detect);
    if (node154 == nullptr) {
        node154 = new PhaseNode_Detect(154, phase);
        node154->setSelf(0U);
        node154->setEvent("daduan_001");
        node154->setType(PhaseNode_Detect::Detect_Type::Interrupt_Skill);
        node154->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10282, 154, node154)
    }
    if (noInit == true) {
        return node154;
    }
    return node154;
}
//--------------------------------------------------------------------------------
// SwitchToInt
//
REGISTER_REGISTER_SKILL_NODE(10282, 155) {
    pnode->resizeTrigger(4);
    pnode->regTrigger<PhaseNode_EndPhase>(1, 15, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(10282, 155) {
    auto node155 = GET_SKILL_NODE(155, PhaseNode_SwitchToInt);
    if (node155 == nullptr) {
        node155 = new PhaseNode_SwitchToInt(155, phase);
        CALL_REGISTER_SKILL_NODE(10282, 155, node155)
    }
    if (noInit == true) {
        return node155;
    }
    auto variables = node155->getVariables();
    if (variables != nullptr) {
        node155->setSelection(variables->getVariable<int32_t>(Variable_10282_a102822));
    }
    return node155;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10282, 157) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_RaiseEvent::TRIGGER_DONE, 166, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10282, 157) {
    auto node157 = GET_SKILL_NODE(157, PhaseNode_RaiseEvent);
    if (node157 == nullptr) {
        node157 = new PhaseNode_RaiseEvent(157, phase);
        node157->setEvent("daduan_001");
        node157->setTarget(0U);
        node157->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node157->setTypeParams(0, 0);
        node157->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10282, 157, node157)
    }
    if (noInit == true) {
        return node157;
    }
    return node157;
}
//--------------------------------------------------------------------------------
// StartPreInput
//
REGISTER_REGISTER_SKILL_NODE(10282, 158) {
    pnode->resizeTrigger(PhaseNode_StartPreInput::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_StartPreInput::TRIGGER_DONE, 162, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10282, 158) {
    auto node158 = GET_SKILL_NODE(158, PhaseNode_StartPreInput);
    if (node158 == nullptr) {
        node158 = new PhaseNode_StartPreInput(158, phase);
        node158->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node158->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node158->setDelayTime(.00f);
        CALL_REGISTER_SKILL_NODE(10282, 158, node158)
    }
    if (noInit == true) {
        return node158;
    }
    return node158;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(10282, 159) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_If::TRIGGER_TRUE, 161, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10282, 159) {
    auto node159 = GET_SKILL_NODE(159, PhaseNode_If);
    if (node159 == nullptr) {
        node159 = new PhaseNode_If(159, phase);
        CALL_REGISTER_SKILL_NODE(10282, 159, node159)
    }
    if (noInit == true) {
        return node159;
    }
    auto variables = node159->getVariables();
    if (variables != nullptr) {
        node159->setCondition(variables->getVariable<bool>(Variable_10282_InterruptAnimat));
    }
    return node159;
}
//--------------------------------------------------------------------------------
// IsInterruptType
//
REGISTER_REGISTER_SKILL_NODE(10282, 160) {
    pnode->resizeTrigger(PhaseNode_IsInterruptType::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SwitchToInt>(PhaseNode_IsInterruptType::TRIGGER_BUFF, 155, PhaseNode_SwitchToInt::FUNC_SWITCH, &PhaseNode_SwitchToInt::Switch);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_POSCHANGE, 159, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTAIM, 159, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTFIRE, 159, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTRELOAD, 159, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_USESKILL, 159, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(10282, 160) {
    auto node160 = GET_SKILL_NODE(160, PhaseNode_IsInterruptType);
    if (node160 == nullptr) {
        node160 = new PhaseNode_IsInterruptType(160, phase);
        node160->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node160->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10282, 160, node160)
    }
    if (noInit == true) {
        return node160;
    }
    auto node154 = GET_SKILL_NODE(154, PhaseNode_Detect);
    if (node154 != nullptr) node160->setType(node154->getVars().getVariable<int32_t>(2));
    return node160;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10282, 161) {
}

REGISTER_CREATE_SKILL_NODE(10282, 161) {
    auto node161 = GET_SKILL_NODE(161, PhaseNode_PlayAnimation);
    if (node161 == nullptr) {
        node161 = new PhaseNode_PlayAnimation(161, phase);
        node161->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node161->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node161->setTarget(0U);
        node161->setAnimation("Idle");
        node161->setParameter("");
        node161->setValue(false);
        CALL_REGISTER_SKILL_NODE(10282, 161, node161)
    }
    if (noInit == true) {
        return node161;
    }
    return node161;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10282, 162) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_Delay::TRIGGER_DONE, 165, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(10282, 162) {
    auto node162 = GET_SKILL_NODE(162, PhaseNode_Delay);
    if (node162 == nullptr) {
        node162 = new PhaseNode_Delay(162, phase);
        node162->setTime(.20f);
        CALL_REGISTER_SKILL_NODE(10282, 162, node162)
    }
    if (noInit == true) {
        return node162;
    }
    return node162;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(10282, 165) {
}

REGISTER_CREATE_SKILL_NODE(10282, 165) {
    auto node165 = GET_SKILL_NODE(165, PhaseNode_SetBool);
    if (node165 == nullptr) {
        node165 = new PhaseNode_SetBool(165, phase);
        node165->setName("InterruptAnimat");
        node165->setValue(true);
        CALL_REGISTER_SKILL_NODE(10282, 165, node165)
    }
    if (noInit == true) {
        return node165;
    }
    return node165;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10282, 166) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StartPreInput>(PhaseNode_RaiseEvent::TRIGGER_DONE, 158, PhaseNode_StartPreInput::FUNC_DO, &PhaseNode_StartPreInput::Do);
}

REGISTER_CREATE_SKILL_NODE(10282, 166) {
    auto node166 = GET_SKILL_NODE(166, PhaseNode_RaiseEvent);
    if (node166 == nullptr) {
        node166 = new PhaseNode_RaiseEvent(166, phase);
        node166->setEvent("Dead_001");
        node166->setTarget(0U);
        node166->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node166->setTypeParams(0, 0);
        node166->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10282, 166, node166)
    }
    if (noInit == true) {
        return node166;
    }
    return node166;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10282, 167) {
}

REGISTER_CREATE_SKILL_NODE(10282, 167) {
    auto node167 = GET_SKILL_NODE(167, PhaseNode_Detect);
    if (node167 == nullptr) {
        node167 = new PhaseNode_Detect(167, phase);
        node167->setSelf(0U);
        node167->setEvent("Dead_001");
        node167->setType(PhaseNode_Detect::Detect_Type::Actor_Dead);
        node167->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10282, 167, node167)
    }
    if (noInit == true) {
        return node167;
    }
    return node167;
}

//--------------------------------------------------------------------------------
// SkillCreator_10282
//
class SkillCreator_10282 : public SkillCreator {
public:
    SkillCreator_10282() {}
    virtual ~SkillCreator_10282() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_10282

//--------------------------------------------------------------------------------
// SkillPhase_10282
//
class SkillPhase_10282 : public SkillPhase {
public:
    SkillPhase_10282(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_10282() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(10282, 4) // StartPhase
        CASE_CREATE_SKILL_NODE(10282, 11) // Disable
        CASE_CREATE_SKILL_NODE(10282, 15) // EndPhase
        CASE_CREATE_SKILL_NODE(10282, 20) // Delay
        CASE_CREATE_SKILL_NODE(10282, 46) // Delay
        CASE_CREATE_SKILL_NODE(10282, 77) // PlayEffect
        CASE_CREATE_SKILL_NODE(10282, 105) // PlaySound
        CASE_CREATE_SKILL_NODE(10282, 126) // SetInt
        CASE_CREATE_SKILL_NODE(10282, 140) // SpawnProjectile
        CASE_CREATE_SKILL_NODE(10282, 142) // CameraXYZShake
        CASE_CREATE_SKILL_NODE(10282, 146) // GetLocation
        CASE_CREATE_SKILL_NODE(10282, 148) // GetInputRotation
        CASE_CREATE_SKILL_NODE(10282, 149) // ResetCD
        CASE_CREATE_SKILL_NODE(10282, 150) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10282, 151) // PlaySound
        CASE_CREATE_SKILL_NODE(10282, 152) // GetActorAttribute
        CASE_CREATE_SKILL_NODE(10282, 154) // Detect
        CASE_CREATE_SKILL_NODE(10282, 155) // SwitchToInt
        CASE_CREATE_SKILL_NODE(10282, 157) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10282, 158) // StartPreInput
        CASE_CREATE_SKILL_NODE(10282, 159) // If
        CASE_CREATE_SKILL_NODE(10282, 160) // IsInterruptType
        CASE_CREATE_SKILL_NODE(10282, 161) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10282, 162) // Delay
        CASE_CREATE_SKILL_NODE(10282, 165) // SetBool
        CASE_CREATE_SKILL_NODE(10282, 166) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10282, 167) // Detect
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_10282

SkillLogic* SkillCreator_10282::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //设置变量
    Variable_10282_a102822 = logic->getVariables().setVariable<int32_t>("a102822", 1);
    Variable_10282_InterruptAnimat = logic->getVariables().setVariable<bool>("InterruptAnimat");
    //创建阶段phase
    auto phase = new SkillPhase_10282(1, logic, 2);
    //设置phase执行器
    phase->setRunPhaseNode(1, 4);
    phase->setDetectPhaseNode(2, 154);
    phase->setDetectPhaseNode(2, 167);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_10282::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
