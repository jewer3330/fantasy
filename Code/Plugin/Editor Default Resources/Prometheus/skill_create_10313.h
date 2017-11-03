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
#include "skill_psnode_triggerupdate.h"

namespace pvp {

//变量声明
uint64_t Variable_10313_CenterX = 0;
uint64_t Variable_10313_CenterY = 0;
uint64_t Variable_10313_stop = 0;
uint64_t Variable_10313_InterruptAnimat = 0;
//--------------------------------------------------------------------------------
// StartPhase
//
REGISTER_REGISTER_SKILL_NODE(10313, 3) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_StartPhase::TRIGGER_START, 121, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(10313, 3) {
    auto node3 = GET_SKILL_NODE(3, PhaseNode_StartPhase);
    if (node3 == nullptr) {
        node3 = new PhaseNode_StartPhase(3, phase);
        CALL_REGISTER_SKILL_NODE(10313, 3, node3)
    }
    if (noInit == true) {
        return node3;
    }
    return node3;
}
//--------------------------------------------------------------------------------
// TriggerUpdate
//
REGISTER_REGISTER_SKILL_NODE(10313, 5) {
}

REGISTER_CREATE_SKILL_NODE(10313, 5) {
    auto node5 = GET_SKILL_NODE(5, PhaseNode_TriggerUpdate);
    if (node5 == nullptr) {
        node5 = new PhaseNode_TriggerUpdate(5, phase);
        CALL_REGISTER_SKILL_NODE(10313, 5, node5)
    }
    if (noInit == true) {
        return node5;
    }
    return node5;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10313, 9) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_Delay::TRIGGER_DONE, 78, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(10313, 9) {
    auto node9 = GET_SKILL_NODE(9, PhaseNode_Delay);
    if (node9 == nullptr) {
        node9 = new PhaseNode_Delay(9, phase);
        node9->setTime(1.13f);
        CALL_REGISTER_SKILL_NODE(10313, 9, node9)
    }
    if (noInit == true) {
        return node9;
    }
    return node9;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10313, 13) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnProjectile>(PhaseNode_PlaySound::TRIGGER_DONE, 120, PhaseNode_SpawnProjectile::FUNC_DO, &PhaseNode_SpawnProjectile::Do);
}

REGISTER_CREATE_SKILL_NODE(10313, 13) {
    auto node13 = GET_SKILL_NODE(13, PhaseNode_PlaySound);
    if (node13 == nullptr) {
        node13 = new PhaseNode_PlaySound(13, phase);
        node13->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node13->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node13->setSoundID("SE_Hero123_SkillC_P1");
        node13->setTarget(0U);
        node13->setUsePos(false);
        node13->setPosX(.00f);
        node13->setPosY(.00f);
        node13->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10313, 13, node13)
    }
    if (noInit == true) {
        return node13;
    }
    return node13;
}
//--------------------------------------------------------------------------------
// SetInt
//
REGISTER_REGISTER_SKILL_NODE(10313, 25) {
    pnode->resizeTrigger(PhaseNode_SetInt::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_SetInt::TRIGGER_DONE, 9, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10313, 25) {
    auto node25 = GET_SKILL_NODE(25, PhaseNode_SetInt);
    if (node25 == nullptr) {
        node25 = new PhaseNode_SetInt(25, phase);
        node25->setName("stop");
        node25->setValue(2);
        CALL_REGISTER_SKILL_NODE(10313, 25, node25)
    }
    if (noInit == true) {
        return node25;
    }
    return node25;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(10313, 78) {
}

REGISTER_CREATE_SKILL_NODE(10313, 78) {
    auto node78 = GET_SKILL_NODE(78, PhaseNode_EndPhase);
    if (node78 == nullptr) {
        node78 = new PhaseNode_EndPhase(78, phase);
        node78->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node78->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10313, 78, node78)
    }
    if (noInit == true) {
        return node78;
    }
    return node78;
}
//--------------------------------------------------------------------------------
// Disable
//
REGISTER_REGISTER_SKILL_NODE(10313, 80) {
    pnode->resizeTrigger(PhaseNode_Disable::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_Disable::TRIGGER_DONE, 105, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_Disable::TRIGGER_DONE, 13, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10313, 80) {
    auto node80 = GET_SKILL_NODE(80, PhaseNode_Disable);
    if (node80 == nullptr) {
        node80 = new PhaseNode_Disable(80, phase);
        node80->setTarget(0U);
        node80->setMove(true);
        node80->setSkill(true);
        node80->setShoot(true);
        node80->setTime(.70f);
        node80->setRotate(true);
        CALL_REGISTER_SKILL_NODE(10313, 80, node80)
    }
    if (noInit == true) {
        return node80;
    }
    return node80;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(10313, 105) {
}

REGISTER_CREATE_SKILL_NODE(10313, 105) {
    auto node105 = GET_SKILL_NODE(105, PhaseNode_PlayEffect);
    if (node105 == nullptr) {
        node105 = new PhaseNode_PlayEffect(105, phase);
        node105->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node105->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node105->setEffectID(103133);
        node105->setChangeColor(true);
        node105->setType(PhaseNode_PlayEffect::PlayEffect_Type::WithTarget);
        node105->getVars().reserve(5);
        node105->getVars().setVariable<uint64_t>(0, 0U);
        node105->getVars().setVariable<std::string>(1, "");
        node105->getVars().setVariable<float>(2, .00f);
        node105->getVars().setVariable<float>(3, .00f);
        node105->getVars().setVariable<float>(4, .00f);
        node105->setRotation(.00f);
        node105->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(10313, 105, node105)
    }
    if (noInit == true) {
        return node105;
    }
    return node105;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(10313, 111) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetInputRotation>(PhaseNode_GetLocation::TRIGGER_DONE, 113, PhaseNode_GetInputRotation::FUNC_DO, &PhaseNode_GetInputRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(10313, 111) {
    auto node111 = GET_SKILL_NODE(111, PhaseNode_GetLocation);
    if (node111 == nullptr) {
        node111 = new PhaseNode_GetLocation(111, phase);
        node111->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node111->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(10313, 111, node111)
    }
    if (noInit == true) {
        return node111;
    }
    return node111;
}
//--------------------------------------------------------------------------------
// GetInputRotation
//
REGISTER_REGISTER_SKILL_NODE(10313, 113) {
    pnode->resizeTrigger(PhaseNode_GetInputRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Disable>(PhaseNode_GetInputRotation::TRIGGER_DONE, 80, PhaseNode_Disable::FUNC_DO, &PhaseNode_Disable::Do);
}

REGISTER_CREATE_SKILL_NODE(10313, 113) {
    auto node113 = GET_SKILL_NODE(113, PhaseNode_GetInputRotation);
    if (node113 == nullptr) {
        node113 = new PhaseNode_GetInputRotation(113, phase);
        node113->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        CALL_REGISTER_SKILL_NODE(10313, 113, node113)
    }
    if (noInit == true) {
        return node113;
    }
    return node113;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10313, 118) {
}

REGISTER_CREATE_SKILL_NODE(10313, 118) {
    auto node118 = GET_SKILL_NODE(118, PhaseNode_PlaySound);
    if (node118 == nullptr) {
        node118 = new PhaseNode_PlaySound(118, phase);
        node118->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node118->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node118->setSoundID("VO_Hero131_Skill_C");
        node118->setTarget(0U);
        node118->setUsePos(false);
        node118->setPosX(.00f);
        node118->setPosY(.00f);
        node118->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10313, 118, node118)
    }
    if (noInit == true) {
        return node118;
    }
    return node118;
}
//--------------------------------------------------------------------------------
// SpawnProjectile
//
REGISTER_REGISTER_SKILL_NODE(10313, 120) {
    pnode->resizeTrigger(PhaseNode_SpawnProjectile::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetInt>(PhaseNode_SpawnProjectile::TRIGGER_DONE, 25, PhaseNode_SetInt::FUNC_SET, &PhaseNode_SetInt::Set);
}

REGISTER_CREATE_SKILL_NODE(10313, 120) {
    auto node120 = GET_SKILL_NODE(120, PhaseNode_SpawnProjectile);
    if (node120 == nullptr) {
        node120 = new PhaseNode_SpawnProjectile(120, phase);
        node120->setDataId(55313);
        node120->setPosZ(.00f);
        node120->setEndPosX(.00f);
        node120->setEndPosY(.00f);
        node120->setEndPosZ(.00f);
        node120->setMaxCount(0);
        CALL_REGISTER_SKILL_NODE(10313, 120, node120)
    }
    if (noInit == true) {
        return node120;
    }
    auto node111 = GET_SKILL_NODE(111, PhaseNode_GetLocation);
    auto node113 = GET_SKILL_NODE(113, PhaseNode_GetInputRotation);
    if (node111 != nullptr) node120->setPosX(node111->getX());
    if (node111 != nullptr) node120->setPosY(node111->getY());
    if (node113 != nullptr) node120->setRotation(node113->getAngle());
    return node120;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(10313, 121) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_ResetCD::TRIGGER_DONE, 122, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10313, 121) {
    auto node121 = GET_SKILL_NODE(121, PhaseNode_ResetCD);
    if (node121 == nullptr) {
        node121 = new PhaseNode_ResetCD(121, phase);
        node121->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node121->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node121->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(10313, 121, node121)
    }
    if (noInit == true) {
        return node121;
    }
    return node121;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10313, 122) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_PlayAnimation::TRIGGER_DONE, 124, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(10313, 122) {
    auto node122 = GET_SKILL_NODE(122, PhaseNode_PlayAnimation);
    if (node122 == nullptr) {
        node122 = new PhaseNode_PlayAnimation(122, phase);
        node122->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node122->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node122->setTarget(0U);
        node122->setAnimation("Skill3S1");
        node122->setParameter("");
        node122->setValue(false);
        CALL_REGISTER_SKILL_NODE(10313, 122, node122)
    }
    if (noInit == true) {
        return node122;
    }
    return node122;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10313, 123) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_PlaySound::TRIGGER_DONE, 111, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_PlaySound::TRIGGER_DONE, 118, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_PlaySound::TRIGGER_DONE, 129, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10313, 123) {
    auto node123 = GET_SKILL_NODE(123, PhaseNode_PlaySound);
    if (node123 == nullptr) {
        node123 = new PhaseNode_PlaySound(123, phase);
        node123->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node123->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node123->setSoundID("");
        node123->setTarget(0U);
        node123->setUsePos(false);
        node123->setPosX(.00f);
        node123->setPosY(.00f);
        node123->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10313, 123, node123)
    }
    if (noInit == true) {
        return node123;
    }
    return node123;
}
//--------------------------------------------------------------------------------
// GetActorAttribute
//
REGISTER_REGISTER_SKILL_NODE(10313, 124) {
    pnode->resizeTrigger(PhaseNode_GetActorAttribute::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 123, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10313, 124) {
    auto node124 = GET_SKILL_NODE(124, PhaseNode_GetActorAttribute);
    if (node124 == nullptr) {
        node124 = new PhaseNode_GetActorAttribute(124, phase);
        node124->setTarget(0U);
        node124->setType({});
        CALL_REGISTER_SKILL_NODE(10313, 124, node124)
    }
    if (noInit == true) {
        return node124;
    }
    return node124;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10313, 126) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_IsInterruptType>(PhaseNode_Detect::TRIGGER_ON, 132, PhaseNode_IsInterruptType::FUNC_DO, &PhaseNode_IsInterruptType::Do);
}

REGISTER_CREATE_SKILL_NODE(10313, 126) {
    auto node126 = GET_SKILL_NODE(126, PhaseNode_Detect);
    if (node126 == nullptr) {
        node126 = new PhaseNode_Detect(126, phase);
        node126->setSelf(0U);
        node126->setEvent("daduan_001");
        node126->setType(PhaseNode_Detect::Detect_Type::Interrupt_Skill);
        node126->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10313, 126, node126)
    }
    if (noInit == true) {
        return node126;
    }
    return node126;
}
//--------------------------------------------------------------------------------
// SwitchToInt
//
REGISTER_REGISTER_SKILL_NODE(10313, 127) {
    pnode->resizeTrigger(4);
    pnode->regTrigger<PhaseNode_EndPhase>(1, 78, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(10313, 127) {
    auto node127 = GET_SKILL_NODE(127, PhaseNode_SwitchToInt);
    if (node127 == nullptr) {
        node127 = new PhaseNode_SwitchToInt(127, phase);
        CALL_REGISTER_SKILL_NODE(10313, 127, node127)
    }
    if (noInit == true) {
        return node127;
    }
    auto variables = node127->getVariables();
    if (variables != nullptr) {
        node127->setSelection(variables->getVariable<int32_t>(Variable_10313_stop));
    }
    return node127;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10313, 129) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_RaiseEvent::TRIGGER_DONE, 138, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10313, 129) {
    auto node129 = GET_SKILL_NODE(129, PhaseNode_RaiseEvent);
    if (node129 == nullptr) {
        node129 = new PhaseNode_RaiseEvent(129, phase);
        node129->setEvent("daduan_001");
        node129->setTarget(0U);
        node129->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node129->setTypeParams(0, 0);
        node129->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10313, 129, node129)
    }
    if (noInit == true) {
        return node129;
    }
    return node129;
}
//--------------------------------------------------------------------------------
// StartPreInput
//
REGISTER_REGISTER_SKILL_NODE(10313, 130) {
    pnode->resizeTrigger(PhaseNode_StartPreInput::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_StartPreInput::TRIGGER_DONE, 134, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10313, 130) {
    auto node130 = GET_SKILL_NODE(130, PhaseNode_StartPreInput);
    if (node130 == nullptr) {
        node130 = new PhaseNode_StartPreInput(130, phase);
        node130->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node130->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node130->setDelayTime(.00f);
        CALL_REGISTER_SKILL_NODE(10313, 130, node130)
    }
    if (noInit == true) {
        return node130;
    }
    return node130;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(10313, 131) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_If::TRIGGER_TRUE, 133, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10313, 131) {
    auto node131 = GET_SKILL_NODE(131, PhaseNode_If);
    if (node131 == nullptr) {
        node131 = new PhaseNode_If(131, phase);
        CALL_REGISTER_SKILL_NODE(10313, 131, node131)
    }
    if (noInit == true) {
        return node131;
    }
    auto variables = node131->getVariables();
    if (variables != nullptr) {
        node131->setCondition(variables->getVariable<bool>(Variable_10313_InterruptAnimat));
    }
    return node131;
}
//--------------------------------------------------------------------------------
// IsInterruptType
//
REGISTER_REGISTER_SKILL_NODE(10313, 132) {
    pnode->resizeTrigger(PhaseNode_IsInterruptType::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SwitchToInt>(PhaseNode_IsInterruptType::TRIGGER_BUFF, 127, PhaseNode_SwitchToInt::FUNC_SWITCH, &PhaseNode_SwitchToInt::Switch);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_POSCHANGE, 131, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTAIM, 131, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTFIRE, 131, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTRELOAD, 131, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_USESKILL, 131, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(10313, 132) {
    auto node132 = GET_SKILL_NODE(132, PhaseNode_IsInterruptType);
    if (node132 == nullptr) {
        node132 = new PhaseNode_IsInterruptType(132, phase);
        node132->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node132->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10313, 132, node132)
    }
    if (noInit == true) {
        return node132;
    }
    auto node126 = GET_SKILL_NODE(126, PhaseNode_Detect);
    if (node126 != nullptr) node132->setType(node126->getVars().getVariable<int32_t>(2));
    return node132;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10313, 133) {
}

REGISTER_CREATE_SKILL_NODE(10313, 133) {
    auto node133 = GET_SKILL_NODE(133, PhaseNode_PlayAnimation);
    if (node133 == nullptr) {
        node133 = new PhaseNode_PlayAnimation(133, phase);
        node133->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node133->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node133->setTarget(0U);
        node133->setAnimation("Idle");
        node133->setParameter("");
        node133->setValue(false);
        CALL_REGISTER_SKILL_NODE(10313, 133, node133)
    }
    if (noInit == true) {
        return node133;
    }
    return node133;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10313, 134) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_Delay::TRIGGER_DONE, 137, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(10313, 134) {
    auto node134 = GET_SKILL_NODE(134, PhaseNode_Delay);
    if (node134 == nullptr) {
        node134 = new PhaseNode_Delay(134, phase);
        node134->setTime(.20f);
        CALL_REGISTER_SKILL_NODE(10313, 134, node134)
    }
    if (noInit == true) {
        return node134;
    }
    return node134;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(10313, 137) {
}

REGISTER_CREATE_SKILL_NODE(10313, 137) {
    auto node137 = GET_SKILL_NODE(137, PhaseNode_SetBool);
    if (node137 == nullptr) {
        node137 = new PhaseNode_SetBool(137, phase);
        node137->setName("InterruptAnimat");
        node137->setValue(true);
        CALL_REGISTER_SKILL_NODE(10313, 137, node137)
    }
    if (noInit == true) {
        return node137;
    }
    return node137;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10313, 138) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StartPreInput>(PhaseNode_RaiseEvent::TRIGGER_DONE, 130, PhaseNode_StartPreInput::FUNC_DO, &PhaseNode_StartPreInput::Do);
}

REGISTER_CREATE_SKILL_NODE(10313, 138) {
    auto node138 = GET_SKILL_NODE(138, PhaseNode_RaiseEvent);
    if (node138 == nullptr) {
        node138 = new PhaseNode_RaiseEvent(138, phase);
        node138->setEvent("Dead_001");
        node138->setTarget(0U);
        node138->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node138->setTypeParams(0, 0);
        node138->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10313, 138, node138)
    }
    if (noInit == true) {
        return node138;
    }
    return node138;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10313, 139) {
}

REGISTER_CREATE_SKILL_NODE(10313, 139) {
    auto node139 = GET_SKILL_NODE(139, PhaseNode_Detect);
    if (node139 == nullptr) {
        node139 = new PhaseNode_Detect(139, phase);
        node139->setSelf(0U);
        node139->setEvent("Dead_001");
        node139->setType(PhaseNode_Detect::Detect_Type::Actor_Dead);
        node139->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10313, 139, node139)
    }
    if (noInit == true) {
        return node139;
    }
    return node139;
}

//--------------------------------------------------------------------------------
// SkillCreator_10313
//
class SkillCreator_10313 : public SkillCreator {
public:
    SkillCreator_10313() {}
    virtual ~SkillCreator_10313() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_10313

//--------------------------------------------------------------------------------
// SkillPhase_10313
//
class SkillPhase_10313 : public SkillPhase {
public:
    SkillPhase_10313(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_10313() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(10313, 3) // StartPhase
        CASE_CREATE_SKILL_NODE(10313, 5) // TriggerUpdate
        CASE_CREATE_SKILL_NODE(10313, 9) // Delay
        CASE_CREATE_SKILL_NODE(10313, 13) // PlaySound
        CASE_CREATE_SKILL_NODE(10313, 25) // SetInt
        CASE_CREATE_SKILL_NODE(10313, 78) // EndPhase
        CASE_CREATE_SKILL_NODE(10313, 80) // Disable
        CASE_CREATE_SKILL_NODE(10313, 105) // PlayEffect
        CASE_CREATE_SKILL_NODE(10313, 111) // GetLocation
        CASE_CREATE_SKILL_NODE(10313, 113) // GetInputRotation
        CASE_CREATE_SKILL_NODE(10313, 118) // PlaySound
        CASE_CREATE_SKILL_NODE(10313, 120) // SpawnProjectile
        CASE_CREATE_SKILL_NODE(10313, 121) // ResetCD
        CASE_CREATE_SKILL_NODE(10313, 122) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10313, 123) // PlaySound
        CASE_CREATE_SKILL_NODE(10313, 124) // GetActorAttribute
        CASE_CREATE_SKILL_NODE(10313, 126) // Detect
        CASE_CREATE_SKILL_NODE(10313, 127) // SwitchToInt
        CASE_CREATE_SKILL_NODE(10313, 129) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10313, 130) // StartPreInput
        CASE_CREATE_SKILL_NODE(10313, 131) // If
        CASE_CREATE_SKILL_NODE(10313, 132) // IsInterruptType
        CASE_CREATE_SKILL_NODE(10313, 133) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10313, 134) // Delay
        CASE_CREATE_SKILL_NODE(10313, 137) // SetBool
        CASE_CREATE_SKILL_NODE(10313, 138) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10313, 139) // Detect
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_10313

SkillLogic* SkillCreator_10313::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //设置变量
    Variable_10313_CenterX = logic->getVariables().setVariable<float>("CenterX");
    Variable_10313_CenterY = logic->getVariables().setVariable<float>("CenterY");
    Variable_10313_stop = logic->getVariables().setVariable<int32_t>("stop", 1);
    Variable_10313_InterruptAnimat = logic->getVariables().setVariable<bool>("InterruptAnimat");
    //创建阶段phase
    auto phase = new SkillPhase_10313(1, logic, 3);
    //设置phase执行器
    phase->setRunPhaseNode(1, 3);
    phase->setRunPhaseNode(2, 5);
    phase->setDetectPhaseNode(3, 126);
    phase->setDetectPhaseNode(3, 139);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_10313::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
