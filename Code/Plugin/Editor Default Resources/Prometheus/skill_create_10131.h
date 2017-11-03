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
uint64_t Variable_10131_a101311 = 0;
uint64_t Variable_10131_InterruptAnimat = 0;
//--------------------------------------------------------------------------------
// StartPhase
//
REGISTER_REGISTER_SKILL_NODE(10131, 1) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_StartPhase::TRIGGER_START, 418, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(10131, 1) {
    auto node1 = GET_SKILL_NODE(1, PhaseNode_StartPhase);
    if (node1 == nullptr) {
        node1 = new PhaseNode_StartPhase(1, phase);
        CALL_REGISTER_SKILL_NODE(10131, 1, node1)
    }
    if (noInit == true) {
        return node1;
    }
    return node1;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(10131, 21) {
}

REGISTER_CREATE_SKILL_NODE(10131, 21) {
    auto node21 = GET_SKILL_NODE(21, PhaseNode_EndPhase);
    if (node21 == nullptr) {
        node21 = new PhaseNode_EndPhase(21, phase);
        node21->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node21->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10131, 21, node21)
    }
    if (noInit == true) {
        return node21;
    }
    return node21;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10131, 37) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_OffsetCalculate>(PhaseNode_Delay::TRIGGER_DONE, 104, PhaseNode_OffsetCalculate::FUNC_DO, &PhaseNode_OffsetCalculate::Do);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_Delay::TRIGGER_DONE, 361, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_Delay::TRIGGER_DONE, 204, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10131, 37) {
    auto node37 = GET_SKILL_NODE(37, PhaseNode_Delay);
    if (node37 == nullptr) {
        node37 = new PhaseNode_Delay(37, phase);
        node37->setTime(.12f);
        CALL_REGISTER_SKILL_NODE(10131, 37, node37)
    }
    if (noInit == true) {
        return node37;
    }
    return node37;
}
//--------------------------------------------------------------------------------
// OffsetCalculate
//
REGISTER_REGISTER_SKILL_NODE(10131, 104) {
    pnode->resizeTrigger(PhaseNode_OffsetCalculate::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnProjectile>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 365, PhaseNode_SpawnProjectile::FUNC_DO, &PhaseNode_SpawnProjectile::Do);
}

REGISTER_CREATE_SKILL_NODE(10131, 104) {
    auto node104 = GET_SKILL_NODE(104, PhaseNode_OffsetCalculate);
    if (node104 == nullptr) {
        node104 = new PhaseNode_OffsetCalculate(104, phase);
        node104->setPosZ(.00f);
        node104->setOffsetX(.00f);
        node104->setOffsetY(.50f);
        node104->setOffsetZ(1.20f);
        node104->setRotOffset(.00f);
        CALL_REGISTER_SKILL_NODE(10131, 104, node104)
    }
    if (noInit == true) {
        return node104;
    }
    auto node400 = GET_SKILL_NODE(400, PhaseNode_GetLocation);
    auto node402 = GET_SKILL_NODE(402, PhaseNode_GetInputRotation);
    if (node400 != nullptr) node104->setPosX(node400->getX());
    if (node400 != nullptr) node104->setPosY(node400->getY());
    if (node402 != nullptr) node104->setRotation(node402->getAngle());
    return node104;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10131, 204) {
}

REGISTER_CREATE_SKILL_NODE(10131, 204) {
    auto node204 = GET_SKILL_NODE(204, PhaseNode_PlaySound);
    if (node204 == nullptr) {
        node204 = new PhaseNode_PlaySound(204, phase);
        node204->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node204->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node204->setSoundID("SE_Hero105_SkillA_P1");
        node204->setTarget(0U);
        node204->setUsePos(false);
        node204->setPosX(.00f);
        node204->setPosY(.00f);
        node204->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10131, 204, node204)
    }
    if (noInit == true) {
        return node204;
    }
    return node204;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(10131, 361) {
}

REGISTER_CREATE_SKILL_NODE(10131, 361) {
    auto node361 = GET_SKILL_NODE(361, PhaseNode_PlayEffect);
    if (node361 == nullptr) {
        node361 = new PhaseNode_PlayEffect(361, phase);
        node361->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node361->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node361->setEffectID(101303);
        node361->setChangeColor(false);
        node361->setType(PhaseNode_PlayEffect::PlayEffect_Type::WithTarget);
        node361->getVars().reserve(5);
        node361->getVars().setVariable<uint64_t>(0, 0U);
        node361->getVars().setVariable<std::string>(1, "Effect");
        node361->getVars().setVariable<float>(2, .00f);
        node361->getVars().setVariable<float>(3, .00f);
        node361->getVars().setVariable<float>(4, .00f);
        node361->setRotation(.00f);
        node361->setScale(.00f);
        CALL_REGISTER_SKILL_NODE(10131, 361, node361)
    }
    if (noInit == true) {
        return node361;
    }
    return node361;
}
//--------------------------------------------------------------------------------
// SpawnProjectile
//
REGISTER_REGISTER_SKILL_NODE(10131, 365) {
    pnode->resizeTrigger(PhaseNode_SpawnProjectile::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuff>(PhaseNode_SpawnProjectile::TRIGGER_DONE, 387, PhaseNode_AddSkillBuff::FUNC_ADD, &PhaseNode_AddSkillBuff::Add);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_SpawnProjectile::TRIGGER_DONE, 396, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10131, 365) {
    auto node365 = GET_SKILL_NODE(365, PhaseNode_SpawnProjectile);
    if (node365 == nullptr) {
        node365 = new PhaseNode_SpawnProjectile(365, phase);
        node365->setDataId(55131);
        node365->setEndPosX(.00f);
        node365->setEndPosY(.00f);
        node365->setEndPosZ(.00f);
        node365->setMaxCount(0);
        CALL_REGISTER_SKILL_NODE(10131, 365, node365)
    }
    if (noInit == true) {
        return node365;
    }
    auto node104 = GET_SKILL_NODE(104, PhaseNode_OffsetCalculate);
    if (node104 != nullptr) node365->setPosX(node104->getOutPosX());
    if (node104 != nullptr) node365->setPosY(node104->getOutPosY());
    if (node104 != nullptr) node365->setPosZ(node104->getOutPosZ());
    if (node104 != nullptr) node365->setRotation(node104->getOutRotation());
    return node365;
}
//--------------------------------------------------------------------------------
// Disable
//
REGISTER_REGISTER_SKILL_NODE(10131, 384) {
    pnode->resizeTrigger(PhaseNode_Disable::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_Disable::TRIGGER_DONE, 37, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10131, 384) {
    auto node384 = GET_SKILL_NODE(384, PhaseNode_Disable);
    if (node384 == nullptr) {
        node384 = new PhaseNode_Disable(384, phase);
        node384->setTarget(0U);
        node384->setMove(false);
        node384->setSkill(true);
        node384->setShoot(true);
        node384->setTime(.40f);
        node384->setRotate(true);
        CALL_REGISTER_SKILL_NODE(10131, 384, node384)
    }
    if (noInit == true) {
        return node384;
    }
    return node384;
}
//--------------------------------------------------------------------------------
// AddSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10131, 387) {
}

REGISTER_CREATE_SKILL_NODE(10131, 387) {
    auto node387 = GET_SKILL_NODE(387, PhaseNode_AddSkillBuff);
    if (node387 == nullptr) {
        node387 = new PhaseNode_AddSkillBuff(387, phase);
        node387->setConfigID(101312);
        node387->setConfigIDs({});
        node387->setTarget(0U);
        node387->setAttribute({{}});
        CALL_REGISTER_SKILL_NODE(10131, 387, node387)
    }
    if (noInit == true) {
        return node387;
    }
    return node387;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10131, 392) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_PlaySound::TRIGGER_DONE, 407, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10131, 392) {
    auto node392 = GET_SKILL_NODE(392, PhaseNode_PlaySound);
    if (node392 == nullptr) {
        node392 = new PhaseNode_PlaySound(392, phase);
        node392->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node392->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node392->setSoundID("VO_Hero105_Skill_A");
        node392->setTarget(0U);
        node392->setUsePos(false);
        node392->setPosX(.00f);
        node392->setPosY(.00f);
        node392->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10131, 392, node392)
    }
    if (noInit == true) {
        return node392;
    }
    return node392;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10131, 396) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_Delay::TRIGGER_DONE, 21, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(10131, 396) {
    auto node396 = GET_SKILL_NODE(396, PhaseNode_Delay);
    if (node396 == nullptr) {
        node396 = new PhaseNode_Delay(396, phase);
        node396->setTime(.58f);
        CALL_REGISTER_SKILL_NODE(10131, 396, node396)
    }
    if (noInit == true) {
        return node396;
    }
    return node396;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(10131, 400) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetInputRotation>(PhaseNode_GetLocation::TRIGGER_DONE, 402, PhaseNode_GetInputRotation::FUNC_DO, &PhaseNode_GetInputRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(10131, 400) {
    auto node400 = GET_SKILL_NODE(400, PhaseNode_GetLocation);
    if (node400 == nullptr) {
        node400 = new PhaseNode_GetLocation(400, phase);
        node400->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node400->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(10131, 400, node400)
    }
    if (noInit == true) {
        return node400;
    }
    return node400;
}
//--------------------------------------------------------------------------------
// GetInputRotation
//
REGISTER_REGISTER_SKILL_NODE(10131, 402) {
    pnode->resizeTrigger(PhaseNode_GetInputRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Disable>(PhaseNode_GetInputRotation::TRIGGER_DONE, 384, PhaseNode_Disable::FUNC_DO, &PhaseNode_Disable::Do);
}

REGISTER_CREATE_SKILL_NODE(10131, 402) {
    auto node402 = GET_SKILL_NODE(402, PhaseNode_GetInputRotation);
    if (node402 == nullptr) {
        node402 = new PhaseNode_GetInputRotation(402, phase);
        node402->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        CALL_REGISTER_SKILL_NODE(10131, 402, node402)
    }
    if (noInit == true) {
        return node402;
    }
    return node402;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10131, 404) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_IsInterruptType>(PhaseNode_Detect::TRIGGER_ON, 410, PhaseNode_IsInterruptType::FUNC_DO, &PhaseNode_IsInterruptType::Do);
}

REGISTER_CREATE_SKILL_NODE(10131, 404) {
    auto node404 = GET_SKILL_NODE(404, PhaseNode_Detect);
    if (node404 == nullptr) {
        node404 = new PhaseNode_Detect(404, phase);
        node404->setSelf(0U);
        node404->setEvent("daduan_001");
        node404->setType(PhaseNode_Detect::Detect_Type::Interrupt_Skill);
        node404->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10131, 404, node404)
    }
    if (noInit == true) {
        return node404;
    }
    return node404;
}
//--------------------------------------------------------------------------------
// SwitchToInt
//
REGISTER_REGISTER_SKILL_NODE(10131, 405) {
}

REGISTER_CREATE_SKILL_NODE(10131, 405) {
    auto node405 = GET_SKILL_NODE(405, PhaseNode_SwitchToInt);
    if (node405 == nullptr) {
        node405 = new PhaseNode_SwitchToInt(405, phase);
        CALL_REGISTER_SKILL_NODE(10131, 405, node405)
    }
    if (noInit == true) {
        return node405;
    }
    auto variables = node405->getVariables();
    if (variables != nullptr) {
        node405->setSelection(variables->getVariable<int32_t>(Variable_10131_a101311));
    }
    return node405;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10131, 407) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_RaiseEvent::TRIGGER_DONE, 416, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10131, 407) {
    auto node407 = GET_SKILL_NODE(407, PhaseNode_RaiseEvent);
    if (node407 == nullptr) {
        node407 = new PhaseNode_RaiseEvent(407, phase);
        node407->setEvent("daduan_001");
        node407->setTarget(0U);
        node407->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node407->setTypeParams(0, 0);
        node407->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10131, 407, node407)
    }
    if (noInit == true) {
        return node407;
    }
    return node407;
}
//--------------------------------------------------------------------------------
// StartPreInput
//
REGISTER_REGISTER_SKILL_NODE(10131, 408) {
    pnode->resizeTrigger(PhaseNode_StartPreInput::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_StartPreInput::TRIGGER_DONE, 412, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10131, 408) {
    auto node408 = GET_SKILL_NODE(408, PhaseNode_StartPreInput);
    if (node408 == nullptr) {
        node408 = new PhaseNode_StartPreInput(408, phase);
        node408->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node408->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node408->setDelayTime(.00f);
        CALL_REGISTER_SKILL_NODE(10131, 408, node408)
    }
    if (noInit == true) {
        return node408;
    }
    return node408;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(10131, 409) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_If::TRIGGER_TRUE, 411, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10131, 409) {
    auto node409 = GET_SKILL_NODE(409, PhaseNode_If);
    if (node409 == nullptr) {
        node409 = new PhaseNode_If(409, phase);
        CALL_REGISTER_SKILL_NODE(10131, 409, node409)
    }
    if (noInit == true) {
        return node409;
    }
    auto variables = node409->getVariables();
    if (variables != nullptr) {
        node409->setCondition(variables->getVariable<bool>(Variable_10131_InterruptAnimat));
    }
    return node409;
}
//--------------------------------------------------------------------------------
// IsInterruptType
//
REGISTER_REGISTER_SKILL_NODE(10131, 410) {
    pnode->resizeTrigger(PhaseNode_IsInterruptType::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SwitchToInt>(PhaseNode_IsInterruptType::TRIGGER_BUFF, 405, PhaseNode_SwitchToInt::FUNC_SWITCH, &PhaseNode_SwitchToInt::Switch);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_POSCHANGE, 409, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTAIM, 409, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTFIRE, 409, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTRELOAD, 409, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_USESKILL, 409, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(10131, 410) {
    auto node410 = GET_SKILL_NODE(410, PhaseNode_IsInterruptType);
    if (node410 == nullptr) {
        node410 = new PhaseNode_IsInterruptType(410, phase);
        node410->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node410->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10131, 410, node410)
    }
    if (noInit == true) {
        return node410;
    }
    auto node404 = GET_SKILL_NODE(404, PhaseNode_Detect);
    if (node404 != nullptr) node410->setType(node404->getVars().getVariable<int32_t>(2));
    return node410;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10131, 411) {
}

REGISTER_CREATE_SKILL_NODE(10131, 411) {
    auto node411 = GET_SKILL_NODE(411, PhaseNode_PlayAnimation);
    if (node411 == nullptr) {
        node411 = new PhaseNode_PlayAnimation(411, phase);
        node411->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node411->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node411->setTarget(0U);
        node411->setAnimation("Idle");
        node411->setParameter("");
        node411->setValue(false);
        CALL_REGISTER_SKILL_NODE(10131, 411, node411)
    }
    if (noInit == true) {
        return node411;
    }
    return node411;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10131, 412) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_Delay::TRIGGER_DONE, 415, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(10131, 412) {
    auto node412 = GET_SKILL_NODE(412, PhaseNode_Delay);
    if (node412 == nullptr) {
        node412 = new PhaseNode_Delay(412, phase);
        node412->setTime(.20f);
        CALL_REGISTER_SKILL_NODE(10131, 412, node412)
    }
    if (noInit == true) {
        return node412;
    }
    return node412;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(10131, 415) {
}

REGISTER_CREATE_SKILL_NODE(10131, 415) {
    auto node415 = GET_SKILL_NODE(415, PhaseNode_SetBool);
    if (node415 == nullptr) {
        node415 = new PhaseNode_SetBool(415, phase);
        node415->setName("InterruptAnimat");
        node415->setValue(true);
        CALL_REGISTER_SKILL_NODE(10131, 415, node415)
    }
    if (noInit == true) {
        return node415;
    }
    return node415;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10131, 416) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StartPreInput>(PhaseNode_RaiseEvent::TRIGGER_DONE, 408, PhaseNode_StartPreInput::FUNC_DO, &PhaseNode_StartPreInput::Do);
}

REGISTER_CREATE_SKILL_NODE(10131, 416) {
    auto node416 = GET_SKILL_NODE(416, PhaseNode_RaiseEvent);
    if (node416 == nullptr) {
        node416 = new PhaseNode_RaiseEvent(416, phase);
        node416->setEvent("Dead_001");
        node416->setTarget(0U);
        node416->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node416->setTypeParams(0, 0);
        node416->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10131, 416, node416)
    }
    if (noInit == true) {
        return node416;
    }
    return node416;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10131, 417) {
}

REGISTER_CREATE_SKILL_NODE(10131, 417) {
    auto node417 = GET_SKILL_NODE(417, PhaseNode_Detect);
    if (node417 == nullptr) {
        node417 = new PhaseNode_Detect(417, phase);
        node417->setSelf(0U);
        node417->setEvent("Dead_001");
        node417->setType(PhaseNode_Detect::Detect_Type::Actor_Dead);
        node417->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10131, 417, node417)
    }
    if (noInit == true) {
        return node417;
    }
    return node417;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(10131, 418) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_ResetCD::TRIGGER_DONE, 419, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10131, 418) {
    auto node418 = GET_SKILL_NODE(418, PhaseNode_ResetCD);
    if (node418 == nullptr) {
        node418 = new PhaseNode_ResetCD(418, phase);
        node418->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node418->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node418->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(10131, 418, node418)
    }
    if (noInit == true) {
        return node418;
    }
    return node418;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10131, 419) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_PlayAnimation::TRIGGER_DONE, 421, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(10131, 419) {
    auto node419 = GET_SKILL_NODE(419, PhaseNode_PlayAnimation);
    if (node419 == nullptr) {
        node419 = new PhaseNode_PlayAnimation(419, phase);
        node419->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node419->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node419->setTarget(0U);
        node419->setAnimation("Skill1S1");
        node419->setParameter("SkillArmBusy");
        node419->setValue(true);
        CALL_REGISTER_SKILL_NODE(10131, 419, node419)
    }
    if (noInit == true) {
        return node419;
    }
    return node419;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10131, 420) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_PlaySound::TRIGGER_DONE, 400, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_PlaySound::TRIGGER_DONE, 392, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10131, 420) {
    auto node420 = GET_SKILL_NODE(420, PhaseNode_PlaySound);
    if (node420 == nullptr) {
        node420 = new PhaseNode_PlaySound(420, phase);
        node420->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node420->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node420->setSoundID("");
        node420->setTarget(0U);
        node420->setUsePos(false);
        node420->setPosX(.00f);
        node420->setPosY(.00f);
        node420->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10131, 420, node420)
    }
    if (noInit == true) {
        return node420;
    }
    return node420;
}
//--------------------------------------------------------------------------------
// GetActorAttribute
//
REGISTER_REGISTER_SKILL_NODE(10131, 421) {
    pnode->resizeTrigger(PhaseNode_GetActorAttribute::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 420, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10131, 421) {
    auto node421 = GET_SKILL_NODE(421, PhaseNode_GetActorAttribute);
    if (node421 == nullptr) {
        node421 = new PhaseNode_GetActorAttribute(421, phase);
        node421->setTarget(0U);
        node421->setType({});
        CALL_REGISTER_SKILL_NODE(10131, 421, node421)
    }
    if (noInit == true) {
        return node421;
    }
    return node421;
}

//--------------------------------------------------------------------------------
// SkillCreator_10131
//
class SkillCreator_10131 : public SkillCreator {
public:
    SkillCreator_10131() {}
    virtual ~SkillCreator_10131() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_10131

//--------------------------------------------------------------------------------
// SkillPhase_10131
//
class SkillPhase_10131 : public SkillPhase {
public:
    SkillPhase_10131(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_10131() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(10131, 1) // StartPhase
        CASE_CREATE_SKILL_NODE(10131, 21) // EndPhase
        CASE_CREATE_SKILL_NODE(10131, 37) // Delay
        CASE_CREATE_SKILL_NODE(10131, 104) // OffsetCalculate
        CASE_CREATE_SKILL_NODE(10131, 204) // PlaySound
        CASE_CREATE_SKILL_NODE(10131, 361) // PlayEffect
        CASE_CREATE_SKILL_NODE(10131, 365) // SpawnProjectile
        CASE_CREATE_SKILL_NODE(10131, 384) // Disable
        CASE_CREATE_SKILL_NODE(10131, 387) // AddSkillBuff
        CASE_CREATE_SKILL_NODE(10131, 392) // PlaySound
        CASE_CREATE_SKILL_NODE(10131, 396) // Delay
        CASE_CREATE_SKILL_NODE(10131, 400) // GetLocation
        CASE_CREATE_SKILL_NODE(10131, 402) // GetInputRotation
        CASE_CREATE_SKILL_NODE(10131, 404) // Detect
        CASE_CREATE_SKILL_NODE(10131, 405) // SwitchToInt
        CASE_CREATE_SKILL_NODE(10131, 407) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10131, 408) // StartPreInput
        CASE_CREATE_SKILL_NODE(10131, 409) // If
        CASE_CREATE_SKILL_NODE(10131, 410) // IsInterruptType
        CASE_CREATE_SKILL_NODE(10131, 411) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10131, 412) // Delay
        CASE_CREATE_SKILL_NODE(10131, 415) // SetBool
        CASE_CREATE_SKILL_NODE(10131, 416) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10131, 417) // Detect
        CASE_CREATE_SKILL_NODE(10131, 418) // ResetCD
        CASE_CREATE_SKILL_NODE(10131, 419) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10131, 420) // PlaySound
        CASE_CREATE_SKILL_NODE(10131, 421) // GetActorAttribute
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_10131

SkillLogic* SkillCreator_10131::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //设置变量
    Variable_10131_a101311 = logic->getVariables().setVariable<int32_t>("a101311", 1);
    Variable_10131_InterruptAnimat = logic->getVariables().setVariable<bool>("InterruptAnimat");
    //创建阶段phase
    auto phase = new SkillPhase_10131(1, logic, 2);
    //设置phase执行器
    phase->setRunPhaseNode(1, 1);
    phase->setDetectPhaseNode(2, 404);
    phase->setDetectPhaseNode(2, 417);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_10131::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
