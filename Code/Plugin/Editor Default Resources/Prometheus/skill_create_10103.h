#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

#include "skill_psnode_addskillbuff.h"
#include "skill_psnode_delay.h"
#include "skill_psnode_detect.h"
#include "skill_psnode_disable.h"
#include "skill_psnode_endphase.h"
#include "skill_psnode_getactorattribute.h"
#include "skill_psnode_getinputlocation.h"
#include "skill_psnode_getrotation.h"
#include "skill_psnode_if.h"
#include "skill_psnode_isinterrupttype.h"
#include "skill_psnode_playanimation.h"
#include "skill_psnode_playeffect.h"
#include "skill_psnode_playsound.h"
#include "skill_psnode_raiseevent.h"
#include "skill_psnode_removeskillbuff.h"
#include "skill_psnode_resetcd.h"
#include "skill_psnode_setbool.h"
#include "skill_psnode_spawnprojectile.h"
#include "skill_psnode_startphase.h"
#include "skill_psnode_startpreinput.h"
#include "skill_psnode_switchtoint.h"

namespace pvp {

//变量声明
uint64_t Variable_10103_a101032 = 0;
uint64_t Variable_10103_InterruptAnimat = 0;
//--------------------------------------------------------------------------------
// StartPhase
//
REGISTER_REGISTER_SKILL_NODE(10103, 1) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_StartPhase::TRIGGER_START, 249, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(10103, 1) {
    auto node1 = GET_SKILL_NODE(1, PhaseNode_StartPhase);
    if (node1 == nullptr) {
        node1 = new PhaseNode_StartPhase(1, phase);
        CALL_REGISTER_SKILL_NODE(10103, 1, node1)
    }
    if (noInit == true) {
        return node1;
    }
    return node1;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10103, 6) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_Delay::TRIGGER_DONE, 239, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(10103, 6) {
    auto node6 = GET_SKILL_NODE(6, PhaseNode_Delay);
    if (node6 == nullptr) {
        node6 = new PhaseNode_Delay(6, phase);
        node6->setTime(.30f);
        CALL_REGISTER_SKILL_NODE(10103, 6, node6)
    }
    if (noInit == true) {
        return node6;
    }
    return node6;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(10103, 9) {
}

REGISTER_CREATE_SKILL_NODE(10103, 9) {
    auto node9 = GET_SKILL_NODE(9, PhaseNode_EndPhase);
    if (node9 == nullptr) {
        node9 = new PhaseNode_EndPhase(9, phase);
        node9->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node9->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10103, 9, node9)
    }
    if (noInit == true) {
        return node9;
    }
    return node9;
}
//--------------------------------------------------------------------------------
// Disable
//
REGISTER_REGISTER_SKILL_NODE(10103, 53) {
    pnode->resizeTrigger(PhaseNode_Disable::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RemoveSkillBuff>(PhaseNode_Disable::TRIGGER_DONE, 248, PhaseNode_RemoveSkillBuff::FUNC_REMOVE, &PhaseNode_RemoveSkillBuff::Remove);
}

REGISTER_CREATE_SKILL_NODE(10103, 53) {
    auto node53 = GET_SKILL_NODE(53, PhaseNode_Disable);
    if (node53 == nullptr) {
        node53 = new PhaseNode_Disable(53, phase);
        node53->setTarget(0U);
        node53->setMove(false);
        node53->setSkill(true);
        node53->setShoot(true);
        node53->setTime(.60f);
        node53->setRotate(false);
        CALL_REGISTER_SKILL_NODE(10103, 53, node53)
    }
    if (noInit == true) {
        return node53;
    }
    return node53;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10103, 54) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuff>(PhaseNode_Delay::TRIGGER_DONE, 237, PhaseNode_AddSkillBuff::FUNC_ADD, &PhaseNode_AddSkillBuff::Add);
}

REGISTER_CREATE_SKILL_NODE(10103, 54) {
    auto node54 = GET_SKILL_NODE(54, PhaseNode_Delay);
    if (node54 == nullptr) {
        node54 = new PhaseNode_Delay(54, phase);
        node54->setTime(.50f);
        CALL_REGISTER_SKILL_NODE(10103, 54, node54)
    }
    if (noInit == true) {
        return node54;
    }
    return node54;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10103, 69) {
}

REGISTER_CREATE_SKILL_NODE(10103, 69) {
    auto node69 = GET_SKILL_NODE(69, PhaseNode_PlaySound);
    if (node69 == nullptr) {
        node69 = new PhaseNode_PlaySound(69, phase);
        node69->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node69->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node69->setSoundID("SE_Hero103_Skill_C_P1");
        node69->setTarget(0U);
        node69->setUsePos(false);
        node69->setPosX(.00f);
        node69->setPosY(.00f);
        node69->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10103, 69, node69)
    }
    if (noInit == true) {
        return node69;
    }
    return node69;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(10103, 202) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_PlayEffect::TRIGGER_DONE, 227, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
    pnode->regTrigger<PhaseNode_SpawnProjectile>(PhaseNode_PlayEffect::TRIGGER_DONE, 219, PhaseNode_SpawnProjectile::FUNC_DO, &PhaseNode_SpawnProjectile::Do);
}

REGISTER_CREATE_SKILL_NODE(10103, 202) {
    auto node202 = GET_SKILL_NODE(202, PhaseNode_PlayEffect);
    if (node202 == nullptr) {
        node202 = new PhaseNode_PlayEffect(202, phase);
        node202->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node202->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node202->setEffectID(101031);
        node202->setChangeColor(true);
        node202->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node202->getVars().reserve(3);
        node202->getVars().setVariable<float>(0, .00f);
        node202->getVars().setVariable<float>(1, .00f);
        node202->getVars().setVariable<float>(2, .00f);
        node202->setRotation(.00f);
        node202->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(10103, 202, node202)
    }
    if (noInit == true) {
        return node202;
    }
    auto node230 = GET_SKILL_NODE(230, PhaseNode_GetInputLocation);
    if (node230 != nullptr) node202->getVars().setVariable<float>(0, node230->getX());
    if (node230 != nullptr) node202->getVars().setVariable<float>(1, node230->getY());
    return node202;
}
//--------------------------------------------------------------------------------
// SpawnProjectile
//
REGISTER_REGISTER_SKILL_NODE(10103, 219) {
    pnode->resizeTrigger(PhaseNode_SpawnProjectile::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_SpawnProjectile::TRIGGER_DONE, 54, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10103, 219) {
    auto node219 = GET_SKILL_NODE(219, PhaseNode_SpawnProjectile);
    if (node219 == nullptr) {
        node219 = new PhaseNode_SpawnProjectile(219, phase);
        node219->setDataId(55103);
        node219->setPosX(.00f);
        node219->setPosY(.00f);
        node219->setPosZ(.00f);
        node219->setEndPosZ(.00f);
        node219->setMaxCount(0);
        CALL_REGISTER_SKILL_NODE(10103, 219, node219)
    }
    if (noInit == true) {
        return node219;
    }
    auto node230 = GET_SKILL_NODE(230, PhaseNode_GetInputLocation);
    auto node224 = GET_SKILL_NODE(224, PhaseNode_GetRotation);
    if (node230 != nullptr) node219->setEndPosX(node230->getX());
    if (node230 != nullptr) node219->setEndPosY(node230->getY());
    if (node224 != nullptr) node219->setRotation(node224->getAngle());
    return node219;
}
//--------------------------------------------------------------------------------
// GetRotation
//
REGISTER_REGISTER_SKILL_NODE(10103, 224) {
    pnode->resizeTrigger(PhaseNode_GetRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Disable>(PhaseNode_GetRotation::TRIGGER_DONE, 53, PhaseNode_Disable::FUNC_DO, &PhaseNode_Disable::Do);
}

REGISTER_CREATE_SKILL_NODE(10103, 224) {
    auto node224 = GET_SKILL_NODE(224, PhaseNode_GetRotation);
    if (node224 == nullptr) {
        node224 = new PhaseNode_GetRotation(224, phase);
        node224->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node224->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(10103, 224, node224)
    }
    if (noInit == true) {
        return node224;
    }
    return node224;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10103, 227) {
}

REGISTER_CREATE_SKILL_NODE(10103, 227) {
    auto node227 = GET_SKILL_NODE(227, PhaseNode_PlaySound);
    if (node227 == nullptr) {
        node227 = new PhaseNode_PlaySound(227, phase);
        node227->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node227->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node227->setSoundID(" SE_Hero103_Skill_C_P1");
        node227->setTarget(0U);
        node227->setUsePos(true);
        node227->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10103, 227, node227)
    }
    if (noInit == true) {
        return node227;
    }
    auto node230 = GET_SKILL_NODE(230, PhaseNode_GetInputLocation);
    if (node230 != nullptr) node227->setPosX(node230->getX());
    if (node230 != nullptr) node227->setPosY(node230->getY());
    return node227;
}
//--------------------------------------------------------------------------------
// GetInputLocation
//
REGISTER_REGISTER_SKILL_NODE(10103, 230) {
    pnode->resizeTrigger(PhaseNode_GetInputLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetRotation>(PhaseNode_GetInputLocation::TRIGGER_DONE, 224, PhaseNode_GetRotation::FUNC_DO, &PhaseNode_GetRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(10103, 230) {
    auto node230 = GET_SKILL_NODE(230, PhaseNode_GetInputLocation);
    if (node230 == nullptr) {
        node230 = new PhaseNode_GetInputLocation(230, phase);
        node230->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        CALL_REGISTER_SKILL_NODE(10103, 230, node230)
    }
    if (noInit == true) {
        return node230;
    }
    return node230;
}
//--------------------------------------------------------------------------------
// AddSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10103, 237) {
    pnode->resizeTrigger(PhaseNode_AddSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_AddSkillBuff::TRIGGER_DONE, 9, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(10103, 237) {
    auto node237 = GET_SKILL_NODE(237, PhaseNode_AddSkillBuff);
    if (node237 == nullptr) {
        node237 = new PhaseNode_AddSkillBuff(237, phase);
        node237->setConfigID(101041);
        node237->setConfigIDs({});
        node237->setTarget(0U);
        node237->setAttribute({{}});
        CALL_REGISTER_SKILL_NODE(10103, 237, node237)
    }
    if (noInit == true) {
        return node237;
    }
    return node237;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(10103, 239) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_PlayEffect::TRIGGER_DONE, 202, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(10103, 239) {
    auto node239 = GET_SKILL_NODE(239, PhaseNode_PlayEffect);
    if (node239 == nullptr) {
        node239 = new PhaseNode_PlayEffect(239, phase);
        node239->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node239->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node239->setEffectID(101033);
        node239->setChangeColor(true);
        node239->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node239->getVars().reserve(3);
        node239->getVars().setVariable<float>(0, .00f);
        node239->getVars().setVariable<float>(1, .00f);
        node239->getVars().setVariable<float>(2, .00f);
        node239->setRotation(.00f);
        node239->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(10103, 239, node239)
    }
    if (noInit == true) {
        return node239;
    }
    auto node230 = GET_SKILL_NODE(230, PhaseNode_GetInputLocation);
    if (node230 != nullptr) node239->getVars().setVariable<float>(0, node230->getX());
    if (node230 != nullptr) node239->getVars().setVariable<float>(1, node230->getY());
    return node239;
}
//--------------------------------------------------------------------------------
// RemoveSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10103, 248) {
    pnode->resizeTrigger(PhaseNode_RemoveSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_RemoveSkillBuff::TRIGGER_DONE, 6, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10103, 248) {
    auto node248 = GET_SKILL_NODE(248, PhaseNode_RemoveSkillBuff);
    if (node248 == nullptr) {
        node248 = new PhaseNode_RemoveSkillBuff(248, phase);
        node248->setBuffID(0U);
        node248->setBuffIDs({});
        node248->setConfigID(101041);
        node248->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(10103, 248, node248)
    }
    if (noInit == true) {
        return node248;
    }
    return node248;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(10103, 249) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_ResetCD::TRIGGER_DONE, 250, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10103, 249) {
    auto node249 = GET_SKILL_NODE(249, PhaseNode_ResetCD);
    if (node249 == nullptr) {
        node249 = new PhaseNode_ResetCD(249, phase);
        node249->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node249->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node249->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(10103, 249, node249)
    }
    if (noInit == true) {
        return node249;
    }
    return node249;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10103, 250) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_PlayAnimation::TRIGGER_DONE, 252, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(10103, 250) {
    auto node250 = GET_SKILL_NODE(250, PhaseNode_PlayAnimation);
    if (node250 == nullptr) {
        node250 = new PhaseNode_PlayAnimation(250, phase);
        node250->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node250->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node250->setTarget(0U);
        node250->setAnimation("Skill3S1");
        node250->setParameter("");
        node250->setValue(false);
        CALL_REGISTER_SKILL_NODE(10103, 250, node250)
    }
    if (noInit == true) {
        return node250;
    }
    return node250;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10103, 251) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetInputLocation>(PhaseNode_PlaySound::TRIGGER_DONE, 230, PhaseNode_GetInputLocation::FUNC_DO, &PhaseNode_GetInputLocation::Do);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_PlaySound::TRIGGER_DONE, 257, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10103, 251) {
    auto node251 = GET_SKILL_NODE(251, PhaseNode_PlaySound);
    if (node251 == nullptr) {
        node251 = new PhaseNode_PlaySound(251, phase);
        node251->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node251->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node251->setSoundID("VO_Hero103_Skill_C");
        node251->setTarget(0U);
        node251->setUsePos(false);
        node251->setPosX(.00f);
        node251->setPosY(.00f);
        node251->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10103, 251, node251)
    }
    if (noInit == true) {
        return node251;
    }
    return node251;
}
//--------------------------------------------------------------------------------
// GetActorAttribute
//
REGISTER_REGISTER_SKILL_NODE(10103, 252) {
    pnode->resizeTrigger(PhaseNode_GetActorAttribute::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 251, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10103, 252) {
    auto node252 = GET_SKILL_NODE(252, PhaseNode_GetActorAttribute);
    if (node252 == nullptr) {
        node252 = new PhaseNode_GetActorAttribute(252, phase);
        node252->setTarget(0U);
        node252->setType({});
        CALL_REGISTER_SKILL_NODE(10103, 252, node252)
    }
    if (noInit == true) {
        return node252;
    }
    return node252;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10103, 254) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_IsInterruptType>(PhaseNode_Detect::TRIGGER_ON, 260, PhaseNode_IsInterruptType::FUNC_DO, &PhaseNode_IsInterruptType::Do);
}

REGISTER_CREATE_SKILL_NODE(10103, 254) {
    auto node254 = GET_SKILL_NODE(254, PhaseNode_Detect);
    if (node254 == nullptr) {
        node254 = new PhaseNode_Detect(254, phase);
        node254->setSelf(0U);
        node254->setEvent("daduan_001");
        node254->setType(PhaseNode_Detect::Detect_Type::Interrupt_Skill);
        node254->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10103, 254, node254)
    }
    if (noInit == true) {
        return node254;
    }
    return node254;
}
//--------------------------------------------------------------------------------
// SwitchToInt
//
REGISTER_REGISTER_SKILL_NODE(10103, 255) {
    pnode->resizeTrigger(4);
    pnode->regTrigger<PhaseNode_AddSkillBuff>(1, 237, PhaseNode_AddSkillBuff::FUNC_ADD, &PhaseNode_AddSkillBuff::Add);
}

REGISTER_CREATE_SKILL_NODE(10103, 255) {
    auto node255 = GET_SKILL_NODE(255, PhaseNode_SwitchToInt);
    if (node255 == nullptr) {
        node255 = new PhaseNode_SwitchToInt(255, phase);
        CALL_REGISTER_SKILL_NODE(10103, 255, node255)
    }
    if (noInit == true) {
        return node255;
    }
    auto variables = node255->getVariables();
    if (variables != nullptr) {
        node255->setSelection(variables->getVariable<int32_t>(Variable_10103_a101032));
    }
    return node255;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10103, 257) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_RaiseEvent::TRIGGER_DONE, 266, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10103, 257) {
    auto node257 = GET_SKILL_NODE(257, PhaseNode_RaiseEvent);
    if (node257 == nullptr) {
        node257 = new PhaseNode_RaiseEvent(257, phase);
        node257->setEvent("daduan_001");
        node257->setTarget(0U);
        node257->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node257->setTypeParams(0, 0);
        node257->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10103, 257, node257)
    }
    if (noInit == true) {
        return node257;
    }
    return node257;
}
//--------------------------------------------------------------------------------
// StartPreInput
//
REGISTER_REGISTER_SKILL_NODE(10103, 258) {
    pnode->resizeTrigger(PhaseNode_StartPreInput::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_StartPreInput::TRIGGER_DONE, 262, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_StartPreInput::TRIGGER_DONE, 69, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10103, 258) {
    auto node258 = GET_SKILL_NODE(258, PhaseNode_StartPreInput);
    if (node258 == nullptr) {
        node258 = new PhaseNode_StartPreInput(258, phase);
        node258->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node258->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node258->setDelayTime(.00f);
        CALL_REGISTER_SKILL_NODE(10103, 258, node258)
    }
    if (noInit == true) {
        return node258;
    }
    return node258;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(10103, 259) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_If::TRIGGER_TRUE, 261, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10103, 259) {
    auto node259 = GET_SKILL_NODE(259, PhaseNode_If);
    if (node259 == nullptr) {
        node259 = new PhaseNode_If(259, phase);
        CALL_REGISTER_SKILL_NODE(10103, 259, node259)
    }
    if (noInit == true) {
        return node259;
    }
    auto variables = node259->getVariables();
    if (variables != nullptr) {
        node259->setCondition(variables->getVariable<bool>(Variable_10103_InterruptAnimat));
    }
    return node259;
}
//--------------------------------------------------------------------------------
// IsInterruptType
//
REGISTER_REGISTER_SKILL_NODE(10103, 260) {
    pnode->resizeTrigger(PhaseNode_IsInterruptType::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SwitchToInt>(PhaseNode_IsInterruptType::TRIGGER_BUFF, 255, PhaseNode_SwitchToInt::FUNC_SWITCH, &PhaseNode_SwitchToInt::Switch);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_POSCHANGE, 259, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTAIM, 259, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTFIRE, 259, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTRELOAD, 259, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_USESKILL, 259, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(10103, 260) {
    auto node260 = GET_SKILL_NODE(260, PhaseNode_IsInterruptType);
    if (node260 == nullptr) {
        node260 = new PhaseNode_IsInterruptType(260, phase);
        node260->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node260->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10103, 260, node260)
    }
    if (noInit == true) {
        return node260;
    }
    auto node254 = GET_SKILL_NODE(254, PhaseNode_Detect);
    if (node254 != nullptr) node260->setType(node254->getVars().getVariable<int32_t>(2));
    return node260;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10103, 261) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuff>(PhaseNode_PlayAnimation::TRIGGER_DONE, 237, PhaseNode_AddSkillBuff::FUNC_ADD, &PhaseNode_AddSkillBuff::Add);
}

REGISTER_CREATE_SKILL_NODE(10103, 261) {
    auto node261 = GET_SKILL_NODE(261, PhaseNode_PlayAnimation);
    if (node261 == nullptr) {
        node261 = new PhaseNode_PlayAnimation(261, phase);
        node261->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node261->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node261->setTarget(0U);
        node261->setAnimation("Idle");
        node261->setParameter("");
        node261->setValue(false);
        CALL_REGISTER_SKILL_NODE(10103, 261, node261)
    }
    if (noInit == true) {
        return node261;
    }
    return node261;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10103, 262) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_Delay::TRIGGER_DONE, 265, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(10103, 262) {
    auto node262 = GET_SKILL_NODE(262, PhaseNode_Delay);
    if (node262 == nullptr) {
        node262 = new PhaseNode_Delay(262, phase);
        node262->setTime(.20f);
        CALL_REGISTER_SKILL_NODE(10103, 262, node262)
    }
    if (noInit == true) {
        return node262;
    }
    return node262;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(10103, 265) {
}

REGISTER_CREATE_SKILL_NODE(10103, 265) {
    auto node265 = GET_SKILL_NODE(265, PhaseNode_SetBool);
    if (node265 == nullptr) {
        node265 = new PhaseNode_SetBool(265, phase);
        node265->setName("InterruptAnimat");
        node265->setValue(true);
        CALL_REGISTER_SKILL_NODE(10103, 265, node265)
    }
    if (noInit == true) {
        return node265;
    }
    return node265;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10103, 266) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StartPreInput>(PhaseNode_RaiseEvent::TRIGGER_DONE, 258, PhaseNode_StartPreInput::FUNC_DO, &PhaseNode_StartPreInput::Do);
}

REGISTER_CREATE_SKILL_NODE(10103, 266) {
    auto node266 = GET_SKILL_NODE(266, PhaseNode_RaiseEvent);
    if (node266 == nullptr) {
        node266 = new PhaseNode_RaiseEvent(266, phase);
        node266->setEvent("Dead_001");
        node266->setTarget(0U);
        node266->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node266->setTypeParams(0, 0);
        node266->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10103, 266, node266)
    }
    if (noInit == true) {
        return node266;
    }
    return node266;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10103, 267) {
}

REGISTER_CREATE_SKILL_NODE(10103, 267) {
    auto node267 = GET_SKILL_NODE(267, PhaseNode_Detect);
    if (node267 == nullptr) {
        node267 = new PhaseNode_Detect(267, phase);
        node267->setSelf(0U);
        node267->setEvent("Dead_001");
        node267->setType(PhaseNode_Detect::Detect_Type::Actor_Dead);
        node267->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10103, 267, node267)
    }
    if (noInit == true) {
        return node267;
    }
    return node267;
}

//--------------------------------------------------------------------------------
// SkillCreator_10103
//
class SkillCreator_10103 : public SkillCreator {
public:
    SkillCreator_10103() {}
    virtual ~SkillCreator_10103() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_10103

//--------------------------------------------------------------------------------
// SkillPhase_10103
//
class SkillPhase_10103 : public SkillPhase {
public:
    SkillPhase_10103(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_10103() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(10103, 1) // StartPhase
        CASE_CREATE_SKILL_NODE(10103, 6) // Delay
        CASE_CREATE_SKILL_NODE(10103, 9) // EndPhase
        CASE_CREATE_SKILL_NODE(10103, 53) // Disable
        CASE_CREATE_SKILL_NODE(10103, 54) // Delay
        CASE_CREATE_SKILL_NODE(10103, 69) // PlaySound
        CASE_CREATE_SKILL_NODE(10103, 202) // PlayEffect
        CASE_CREATE_SKILL_NODE(10103, 219) // SpawnProjectile
        CASE_CREATE_SKILL_NODE(10103, 224) // GetRotation
        CASE_CREATE_SKILL_NODE(10103, 227) // PlaySound
        CASE_CREATE_SKILL_NODE(10103, 230) // GetInputLocation
        CASE_CREATE_SKILL_NODE(10103, 237) // AddSkillBuff
        CASE_CREATE_SKILL_NODE(10103, 239) // PlayEffect
        CASE_CREATE_SKILL_NODE(10103, 248) // RemoveSkillBuff
        CASE_CREATE_SKILL_NODE(10103, 249) // ResetCD
        CASE_CREATE_SKILL_NODE(10103, 250) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10103, 251) // PlaySound
        CASE_CREATE_SKILL_NODE(10103, 252) // GetActorAttribute
        CASE_CREATE_SKILL_NODE(10103, 254) // Detect
        CASE_CREATE_SKILL_NODE(10103, 255) // SwitchToInt
        CASE_CREATE_SKILL_NODE(10103, 257) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10103, 258) // StartPreInput
        CASE_CREATE_SKILL_NODE(10103, 259) // If
        CASE_CREATE_SKILL_NODE(10103, 260) // IsInterruptType
        CASE_CREATE_SKILL_NODE(10103, 261) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10103, 262) // Delay
        CASE_CREATE_SKILL_NODE(10103, 265) // SetBool
        CASE_CREATE_SKILL_NODE(10103, 266) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10103, 267) // Detect
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_10103

SkillLogic* SkillCreator_10103::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //设置变量
    Variable_10103_a101032 = logic->getVariables().setVariable<int32_t>("a101032", 1);
    Variable_10103_InterruptAnimat = logic->getVariables().setVariable<bool>("InterruptAnimat");
    //创建阶段phase
    auto phase = new SkillPhase_10103(1, logic, 2);
    //设置phase执行器
    phase->setRunPhaseNode(1, 1);
    phase->setDetectPhaseNode(2, 254);
    phase->setDetectPhaseNode(2, 267);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_10103::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
