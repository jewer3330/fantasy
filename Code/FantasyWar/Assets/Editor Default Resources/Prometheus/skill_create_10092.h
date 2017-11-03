#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

#include "skill_psnode_addskillbuff.h"
#include "skill_psnode_cameraxyzshake.h"
#include "skill_psnode_delay.h"
#include "skill_psnode_detect.h"
#include "skill_psnode_disable.h"
#include "skill_psnode_endphase.h"
#include "skill_psnode_getinputrotation.h"
#include "skill_psnode_getlocation.h"
#include "skill_psnode_if.h"
#include "skill_psnode_isinterrupttype.h"
#include "skill_psnode_offsetcalculate.h"
#include "skill_psnode_playanimation.h"
#include "skill_psnode_playeffect.h"
#include "skill_psnode_playsound.h"
#include "skill_psnode_playuieffect.h"
#include "skill_psnode_raiseevent.h"
#include "skill_psnode_removeskillbuff.h"
#include "skill_psnode_resetcd.h"
#include "skill_psnode_setbool.h"
#include "skill_psnode_setfloat.h"
#include "skill_psnode_spawnprojectile.h"
#include "skill_psnode_startphase.h"
#include "skill_psnode_startpreinput.h"
#include "skill_psnode_stopeffect.h"
#include "skill_psnode_switchtoint.h"
#include "skill_psnode_timedown.h"

namespace pvp {

//变量声明
uint64_t Variable_10092_a100923 = 0;
uint64_t Variable_10092_100922 = 0;
uint64_t Variable_10092_InterruptAnimat = 0;
//--------------------------------------------------------------------------------
// StartPhase
//
REGISTER_REGISTER_SKILL_NODE(10092, 2) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_StartPhase::TRIGGER_START, 601, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10092, 2) {
    auto node2 = GET_SKILL_NODE(2, PhaseNode_StartPhase);
    if (node2 == nullptr) {
        node2 = new PhaseNode_StartPhase(2, phase);
        CALL_REGISTER_SKILL_NODE(10092, 2, node2)
    }
    if (noInit == true) {
        return node2;
    }
    return node2;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(10092, 108) {
}

REGISTER_CREATE_SKILL_NODE(10092, 108) {
    auto node108 = GET_SKILL_NODE(108, PhaseNode_EndPhase);
    if (node108 == nullptr) {
        node108 = new PhaseNode_EndPhase(108, phase);
        node108->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node108->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10092, 108, node108)
    }
    if (noInit == true) {
        return node108;
    }
    return node108;
}
//--------------------------------------------------------------------------------
// Disable
//
REGISTER_REGISTER_SKILL_NODE(10092, 543) {
    pnode->resizeTrigger(PhaseNode_Disable::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_Disable::TRIGGER_DONE, 552, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_GetInputRotation>(PhaseNode_Disable::TRIGGER_DONE, 644, PhaseNode_GetInputRotation::FUNC_DO, &PhaseNode_GetInputRotation::Do);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_Disable::TRIGGER_DONE, 640, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
    pnode->regTrigger<PhaseNode_PlayUIEffect>(PhaseNode_Disable::TRIGGER_DONE, 608, PhaseNode_PlayUIEffect::FUNC_DO, &PhaseNode_PlayUIEffect::Do);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_Disable::TRIGGER_DONE, 652, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10092, 543) {
    auto node543 = GET_SKILL_NODE(543, PhaseNode_Disable);
    if (node543 == nullptr) {
        node543 = new PhaseNode_Disable(543, phase);
        node543->setTarget(0U);
        node543->setMove(false);
        node543->setSkill(true);
        node543->setShoot(true);
        node543->setTime(2.20f);
        node543->setRotate(false);
        CALL_REGISTER_SKILL_NODE(10092, 543, node543)
    }
    if (noInit == true) {
        return node543;
    }
    return node543;
}
//--------------------------------------------------------------------------------
// SpawnProjectile
//
REGISTER_REGISTER_SKILL_NODE(10092, 548) {
}

REGISTER_CREATE_SKILL_NODE(10092, 548) {
    auto node548 = GET_SKILL_NODE(548, PhaseNode_SpawnProjectile);
    if (node548 == nullptr) {
        node548 = new PhaseNode_SpawnProjectile(548, phase);
        node548->setDataId(55092);
        node548->setEndPosX(.00f);
        node548->setEndPosY(.00f);
        node548->setEndPosZ(.00f);
        node548->setMaxCount(0);
        CALL_REGISTER_SKILL_NODE(10092, 548, node548)
    }
    if (noInit == true) {
        return node548;
    }
    auto node565 = GET_SKILL_NODE(565, PhaseNode_OffsetCalculate);
    if (node565 != nullptr) node548->setPosX(node565->getOutPosX());
    if (node565 != nullptr) node548->setPosY(node565->getOutPosY());
    if (node565 != nullptr) node548->setPosZ(node565->getOutPosZ());
    if (node565 != nullptr) node548->setRotation(node565->getOutRotation());
    return node548;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10092, 552) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_Delay::TRIGGER_DONE, 625, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_Delay::TRIGGER_DONE, 604, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
    pnode->regTrigger<PhaseNode_StopEffect>(PhaseNode_Delay::TRIGGER_DONE, 642, PhaseNode_StopEffect::FUNC_DO, &PhaseNode_StopEffect::Do);
    pnode->regTrigger<PhaseNode_TimeDown>(PhaseNode_Delay::TRIGGER_DONE, 582, PhaseNode_TimeDown::FUNC_DO, &PhaseNode_TimeDown::Do);
}

REGISTER_CREATE_SKILL_NODE(10092, 552) {
    auto node552 = GET_SKILL_NODE(552, PhaseNode_Delay);
    if (node552 == nullptr) {
        node552 = new PhaseNode_Delay(552, phase);
        node552->setTime(.50f);
        CALL_REGISTER_SKILL_NODE(10092, 552, node552)
    }
    if (noInit == true) {
        return node552;
    }
    return node552;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(10092, 561) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_OffsetCalculate>(PhaseNode_GetLocation::TRIGGER_DONE, 565, PhaseNode_OffsetCalculate::FUNC_DO, &PhaseNode_OffsetCalculate::Do);
}

REGISTER_CREATE_SKILL_NODE(10092, 561) {
    auto node561 = GET_SKILL_NODE(561, PhaseNode_GetLocation);
    if (node561 == nullptr) {
        node561 = new PhaseNode_GetLocation(561, phase);
        node561->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node561->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(10092, 561, node561)
    }
    if (noInit == true) {
        return node561;
    }
    return node561;
}
//--------------------------------------------------------------------------------
// OffsetCalculate
//
REGISTER_REGISTER_SKILL_NODE(10092, 565) {
    pnode->resizeTrigger(PhaseNode_OffsetCalculate::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 578, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(10092, 565) {
    auto node565 = GET_SKILL_NODE(565, PhaseNode_OffsetCalculate);
    if (node565 == nullptr) {
        node565 = new PhaseNode_OffsetCalculate(565, phase);
        node565->setPosZ(.00f);
        node565->setOffsetX(.00f);
        node565->setOffsetY(.50f);
        node565->setOffsetZ(2.20f);
        node565->setRotOffset(.00f);
        CALL_REGISTER_SKILL_NODE(10092, 565, node565)
    }
    if (noInit == true) {
        return node565;
    }
    auto variables = node565->getVariables();
    if (variables != nullptr) {
        node565->setRotation(variables->getVariable<float>(Variable_10092_a100923));
    }
    auto node561 = GET_SKILL_NODE(561, PhaseNode_GetLocation);
    if (node561 != nullptr) node565->setPosX(node561->getX());
    if (node561 != nullptr) node565->setPosY(node561->getY());
    return node565;
}
//--------------------------------------------------------------------------------
// AddSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10092, 572) {
}

REGISTER_CREATE_SKILL_NODE(10092, 572) {
    auto node572 = GET_SKILL_NODE(572, PhaseNode_AddSkillBuff);
    if (node572 == nullptr) {
        node572 = new PhaseNode_AddSkillBuff(572, phase);
        node572->setConfigID(100922);
        node572->setConfigIDs({});
        node572->setTarget(0U);
        node572->setAttribute({{}});
        CALL_REGISTER_SKILL_NODE(10092, 572, node572)
    }
    if (noInit == true) {
        return node572;
    }
    return node572;
}
//--------------------------------------------------------------------------------
// RemoveSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10092, 576) {
    pnode->resizeTrigger(PhaseNode_RemoveSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_RemoveSkillBuff::TRIGGER_DONE, 606, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(10092, 576) {
    auto node576 = GET_SKILL_NODE(576, PhaseNode_RemoveSkillBuff);
    if (node576 == nullptr) {
        node576 = new PhaseNode_RemoveSkillBuff(576, phase);
        node576->setBuffID(0U);
        node576->setBuffIDs({});
        node576->setConfigID(100922);
        node576->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(10092, 576, node576)
    }
    if (noInit == true) {
        return node576;
    }
    return node576;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(10092, 578) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnProjectile>(PhaseNode_PlayEffect::TRIGGER_DONE, 548, PhaseNode_SpawnProjectile::FUNC_DO, &PhaseNode_SpawnProjectile::Do);
}

REGISTER_CREATE_SKILL_NODE(10092, 578) {
    auto node578 = GET_SKILL_NODE(578, PhaseNode_PlayEffect);
    if (node578 == nullptr) {
        node578 = new PhaseNode_PlayEffect(578, phase);
        node578->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node578->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node578->setEffectID(100926);
        node578->setChangeColor(true);
        node578->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node578->getVars().reserve(3);
        node578->getVars().setVariable<float>(0, .00f);
        node578->getVars().setVariable<float>(1, .00f);
        node578->getVars().setVariable<float>(2, .00f);
        node578->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(10092, 578, node578)
    }
    if (noInit == true) {
        return node578;
    }
    auto node565 = GET_SKILL_NODE(565, PhaseNode_OffsetCalculate);
    if (node565 != nullptr) node578->getVars().setVariable<float>(0, node565->getOutPosX());
    if (node565 != nullptr) node578->getVars().setVariable<float>(1, node565->getOutPosY());
    if (node565 != nullptr) node578->getVars().setVariable<float>(2, node565->getOutPosZ());
    if (node565 != nullptr) node578->setRotation(node565->getOutRotation());
    return node578;
}
//--------------------------------------------------------------------------------
// StopEffect
//
REGISTER_REGISTER_SKILL_NODE(10092, 580) {
    pnode->resizeTrigger(PhaseNode_StopEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RemoveSkillBuff>(PhaseNode_StopEffect::TRIGGER_DONE, 576, PhaseNode_RemoveSkillBuff::FUNC_REMOVE, &PhaseNode_RemoveSkillBuff::Remove);
}

REGISTER_CREATE_SKILL_NODE(10092, 580) {
    auto node580 = GET_SKILL_NODE(580, PhaseNode_StopEffect);
    if (node580 == nullptr) {
        node580 = new PhaseNode_StopEffect(580, phase);
        node580->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node580->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node580->setEffectID(100926);
        CALL_REGISTER_SKILL_NODE(10092, 580, node580)
    }
    if (noInit == true) {
        return node580;
    }
    return node580;
}
//--------------------------------------------------------------------------------
// TimeDown
//
REGISTER_REGISTER_SKILL_NODE(10092, 582) {
    pnode->resizeTrigger(PhaseNode_TimeDown::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CameraXYZShake>(PhaseNode_TimeDown::TRIGGER_DONE, 628, PhaseNode_CameraXYZShake::FUNC_DO, &PhaseNode_CameraXYZShake::Do);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_TimeDown::TRIGGER_DONE, 561, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(10092, 582) {
    auto node582 = GET_SKILL_NODE(582, PhaseNode_TimeDown);
    if (node582 == nullptr) {
        node582 = new PhaseNode_TimeDown(582, phase);
        node582->setTime(.20f);
        node582->setNum(9);
        node582->setIsImmediateFirst(true);
        CALL_REGISTER_SKILL_NODE(10092, 582, node582)
    }
    if (noInit == true) {
        return node582;
    }
    return node582;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10092, 587) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuff>(PhaseNode_RaiseEvent::TRIGGER_DONE, 572, PhaseNode_AddSkillBuff::FUNC_ADD, &PhaseNode_AddSkillBuff::Add);
}

REGISTER_CREATE_SKILL_NODE(10092, 587) {
    auto node587 = GET_SKILL_NODE(587, PhaseNode_RaiseEvent);
    if (node587 == nullptr) {
        node587 = new PhaseNode_RaiseEvent(587, phase);
        node587->setEvent("09POS");
        node587->setTarget(0U);
        node587->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node587->setTypeParams(0, 0);
        node587->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10092, 587, node587)
    }
    if (noInit == true) {
        return node587;
    }
    return node587;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10092, 590) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetFloat>(PhaseNode_Detect::TRIGGER_ON, 593, PhaseNode_SetFloat::FUNC_SET, &PhaseNode_SetFloat::Set);
}

REGISTER_CREATE_SKILL_NODE(10092, 590) {
    auto node590 = GET_SKILL_NODE(590, PhaseNode_Detect);
    if (node590 == nullptr) {
        node590 = new PhaseNode_Detect(590, phase);
        node590->setSelf(0U);
        node590->setEvent("");
        node590->setType(PhaseNode_Detect::Detect_Type::Actor_POS);
        node590->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10092, 590, node590)
    }
    if (noInit == true) {
        return node590;
    }
    return node590;
}
//--------------------------------------------------------------------------------
// SetFloat
//
REGISTER_REGISTER_SKILL_NODE(10092, 593) {
}

REGISTER_CREATE_SKILL_NODE(10092, 593) {
    auto node593 = GET_SKILL_NODE(593, PhaseNode_SetFloat);
    if (node593 == nullptr) {
        node593 = new PhaseNode_SetFloat(593, phase);
        node593->setName("a100923");
        CALL_REGISTER_SKILL_NODE(10092, 593, node593)
    }
    if (noInit == true) {
        return node593;
    }
    auto node590 = GET_SKILL_NODE(590, PhaseNode_Detect);
    if (node590 != nullptr) node593->setValue(node590->getVars().getVariable<float>(4));
    return node593;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10092, 601) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Disable>(PhaseNode_PlayAnimation::TRIGGER_DONE, 543, PhaseNode_Disable::FUNC_DO, &PhaseNode_Disable::Do);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_PlayAnimation::TRIGGER_DONE, 634, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10092, 601) {
    auto node601 = GET_SKILL_NODE(601, PhaseNode_PlayAnimation);
    if (node601 == nullptr) {
        node601 = new PhaseNode_PlayAnimation(601, phase);
        node601->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node601->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node601->setTarget(0U);
        node601->setAnimation("Skill2S1");
        node601->setParameter("SkillArmBusy");
        node601->setValue(true);
        CALL_REGISTER_SKILL_NODE(10092, 601, node601)
    }
    if (noInit == true) {
        return node601;
    }
    return node601;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10092, 604) {
}

REGISTER_CREATE_SKILL_NODE(10092, 604) {
    auto node604 = GET_SKILL_NODE(604, PhaseNode_PlaySound);
    if (node604 == nullptr) {
        node604 = new PhaseNode_PlaySound(604, phase);
        node604->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node604->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node604->setSoundID("SE_Hero109_Skill_B");
        node604->setTarget(0U);
        node604->setUsePos(false);
        node604->setPosX(.00f);
        node604->setPosY(.00f);
        node604->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10092, 604, node604)
    }
    if (noInit == true) {
        return node604;
    }
    return node604;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(10092, 606) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RemoveSkillBuff>(PhaseNode_ResetCD::TRIGGER_DONE, 632, PhaseNode_RemoveSkillBuff::FUNC_REMOVE, &PhaseNode_RemoveSkillBuff::Remove);
}

REGISTER_CREATE_SKILL_NODE(10092, 606) {
    auto node606 = GET_SKILL_NODE(606, PhaseNode_ResetCD);
    if (node606 == nullptr) {
        node606 = new PhaseNode_ResetCD(606, phase);
        node606->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node606->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node606->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(10092, 606, node606)
    }
    if (noInit == true) {
        return node606;
    }
    return node606;
}
//--------------------------------------------------------------------------------
// PlayUIEffect
//
REGISTER_REGISTER_SKILL_NODE(10092, 608) {
}

REGISTER_CREATE_SKILL_NODE(10092, 608) {
    auto node608 = GET_SKILL_NODE(608, PhaseNode_PlayUIEffect);
    if (node608 == nullptr) {
        node608 = new PhaseNode_PlayUIEffect(608, phase);
        node608->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node608->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node608->setTime(2.20f);
        node608->setType(2);
        CALL_REGISTER_SKILL_NODE(10092, 608, node608)
    }
    if (noInit == true) {
        return node608;
    }
    return node608;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10092, 625) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_Delay::TRIGGER_DONE, 606, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(10092, 625) {
    auto node625 = GET_SKILL_NODE(625, PhaseNode_Delay);
    if (node625 == nullptr) {
        node625 = new PhaseNode_Delay(625, phase);
        node625->setTime(1.60f);
        CALL_REGISTER_SKILL_NODE(10092, 625, node625)
    }
    if (noInit == true) {
        return node625;
    }
    return node625;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10092, 627) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_Delay::TRIGGER_DONE, 108, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(10092, 627) {
    auto node627 = GET_SKILL_NODE(627, PhaseNode_Delay);
    if (node627 == nullptr) {
        node627 = new PhaseNode_Delay(627, phase);
        node627->setTime(.30f);
        CALL_REGISTER_SKILL_NODE(10092, 627, node627)
    }
    if (noInit == true) {
        return node627;
    }
    return node627;
}
//--------------------------------------------------------------------------------
// CameraXYZShake
//
REGISTER_REGISTER_SKILL_NODE(10092, 628) {
}

REGISTER_CREATE_SKILL_NODE(10092, 628) {
    auto node628 = GET_SKILL_NODE(628, PhaseNode_CameraXYZShake);
    if (node628 == nullptr) {
        node628 = new PhaseNode_CameraXYZShake(628, phase);
        node628->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node628->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node628->setShakeStyle(0);
        node628->setTarget(0U);
        node628->setX(.05f);
        node628->setY(.05f);
        node628->setZ(.05f);
        node628->setDuration(.20f);
        node628->setTimes(2);
        CALL_REGISTER_SKILL_NODE(10092, 628, node628)
    }
    if (noInit == true) {
        return node628;
    }
    return node628;
}
//--------------------------------------------------------------------------------
// RemoveSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10092, 632) {
    pnode->resizeTrigger(PhaseNode_RemoveSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_RemoveSkillBuff::TRIGGER_DONE, 638, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(10092, 632) {
    auto node632 = GET_SKILL_NODE(632, PhaseNode_RemoveSkillBuff);
    if (node632 == nullptr) {
        node632 = new PhaseNode_RemoveSkillBuff(632, phase);
        node632->setBuffID(0U);
        node632->setBuffIDs({});
        node632->setConfigID(100941);
        node632->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(10092, 632, node632)
    }
    if (noInit == true) {
        return node632;
    }
    return node632;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10092, 634) {
}

REGISTER_CREATE_SKILL_NODE(10092, 634) {
    auto node634 = GET_SKILL_NODE(634, PhaseNode_RaiseEvent);
    if (node634 == nullptr) {
        node634 = new PhaseNode_RaiseEvent(634, phase);
        node634->setEvent("Dead");
        node634->setTarget(0U);
        node634->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node634->setTypeParams(0, 0);
        node634->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10092, 634, node634)
    }
    if (noInit == true) {
        return node634;
    }
    return node634;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10092, 636) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_Detect::TRIGGER_ON, 606, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(10092, 636) {
    auto node636 = GET_SKILL_NODE(636, PhaseNode_Detect);
    if (node636 == nullptr) {
        node636 = new PhaseNode_Detect(636, phase);
        node636->setSelf(0U);
        node636->setEvent("Dead");
        node636->setType(PhaseNode_Detect::Detect_Type::Actor_Dead);
        node636->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10092, 636, node636)
    }
    if (noInit == true) {
        return node636;
    }
    return node636;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(10092, 638) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlayEffect::TRIGGER_DONE, 627, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10092, 638) {
    auto node638 = GET_SKILL_NODE(638, PhaseNode_PlayEffect);
    if (node638 == nullptr) {
        node638 = new PhaseNode_PlayEffect(638, phase);
        node638->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node638->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node638->setEffectID(100947);
        node638->setChangeColor(true);
        node638->setType(PhaseNode_PlayEffect::PlayEffect_Type::WithTarget);
        node638->getVars().reserve(6);
        node638->getVars().setVariable<uint64_t>(0, 0U);
        node638->getVars().setVariable<std::string>(1, "");
        node638->getVars().setVariable<float>(2, .00f);
        node638->getVars().setVariable<float>(3, .00f);
        node638->getVars().setVariable<float>(4, .00f);
        node638->getVars().setVariable<bool>(5, false);
        node638->setRotation(.00f);
        node638->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(10092, 638, node638)
    }
    if (noInit == true) {
        return node638;
    }
    return node638;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(10092, 640) {
}

REGISTER_CREATE_SKILL_NODE(10092, 640) {
    auto node640 = GET_SKILL_NODE(640, PhaseNode_PlayEffect);
    if (node640 == nullptr) {
        node640 = new PhaseNode_PlayEffect(640, phase);
        node640->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node640->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node640->setEffectID(1063);
        node640->setChangeColor(false);
        node640->setType(PhaseNode_PlayEffect::PlayEffect_Type::WithTarget);
        node640->getVars().reserve(6);
        node640->getVars().setVariable<uint64_t>(0, 0U);
        node640->getVars().setVariable<std::string>(1, "Weapon_R");
        node640->getVars().setVariable<float>(2, .00f);
        node640->getVars().setVariable<float>(3, .00f);
        node640->getVars().setVariable<float>(4, .00f);
        node640->getVars().setVariable<bool>(5, false);
        node640->setRotation(.00f);
        node640->setScale(.00f);
        CALL_REGISTER_SKILL_NODE(10092, 640, node640)
    }
    if (noInit == true) {
        return node640;
    }
    return node640;
}
//--------------------------------------------------------------------------------
// StopEffect
//
REGISTER_REGISTER_SKILL_NODE(10092, 642) {
}

REGISTER_CREATE_SKILL_NODE(10092, 642) {
    auto node642 = GET_SKILL_NODE(642, PhaseNode_StopEffect);
    if (node642 == nullptr) {
        node642 = new PhaseNode_StopEffect(642, phase);
        node642->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node642->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node642->setEffectID(1063);
        CALL_REGISTER_SKILL_NODE(10092, 642, node642)
    }
    if (noInit == true) {
        return node642;
    }
    return node642;
}
//--------------------------------------------------------------------------------
// GetInputRotation
//
REGISTER_REGISTER_SKILL_NODE(10092, 644) {
    pnode->resizeTrigger(PhaseNode_GetInputRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetFloat>(PhaseNode_GetInputRotation::TRIGGER_DONE, 647, PhaseNode_SetFloat::FUNC_SET, &PhaseNode_SetFloat::Set);
}

REGISTER_CREATE_SKILL_NODE(10092, 644) {
    auto node644 = GET_SKILL_NODE(644, PhaseNode_GetInputRotation);
    if (node644 == nullptr) {
        node644 = new PhaseNode_GetInputRotation(644, phase);
        node644->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        CALL_REGISTER_SKILL_NODE(10092, 644, node644)
    }
    if (noInit == true) {
        return node644;
    }
    return node644;
}
//--------------------------------------------------------------------------------
// SetFloat
//
REGISTER_REGISTER_SKILL_NODE(10092, 647) {
    pnode->resizeTrigger(PhaseNode_SetFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_SetFloat::TRIGGER_DONE, 587, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10092, 647) {
    auto node647 = GET_SKILL_NODE(647, PhaseNode_SetFloat);
    if (node647 == nullptr) {
        node647 = new PhaseNode_SetFloat(647, phase);
        node647->setName("a100923");
        CALL_REGISTER_SKILL_NODE(10092, 647, node647)
    }
    if (noInit == true) {
        return node647;
    }
    auto node644 = GET_SKILL_NODE(644, PhaseNode_GetInputRotation);
    if (node644 != nullptr) node647->setValue(node644->getAngle());
    return node647;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10092, 649) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_IsInterruptType>(PhaseNode_Detect::TRIGGER_ON, 655, PhaseNode_IsInterruptType::FUNC_DO, &PhaseNode_IsInterruptType::Do);
}

REGISTER_CREATE_SKILL_NODE(10092, 649) {
    auto node649 = GET_SKILL_NODE(649, PhaseNode_Detect);
    if (node649 == nullptr) {
        node649 = new PhaseNode_Detect(649, phase);
        node649->setSelf(0U);
        node649->setEvent("daduan_001");
        node649->setType(PhaseNode_Detect::Detect_Type::Interrupt_Skill);
        node649->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10092, 649, node649)
    }
    if (noInit == true) {
        return node649;
    }
    return node649;
}
//--------------------------------------------------------------------------------
// SwitchToInt
//
REGISTER_REGISTER_SKILL_NODE(10092, 650) {
    pnode->resizeTrigger(4);
    pnode->regTrigger<PhaseNode_StopEffect>(1, 580, PhaseNode_StopEffect::FUNC_DO, &PhaseNode_StopEffect::Do);
    pnode->regTrigger<PhaseNode_StopEffect>(1, 642, PhaseNode_StopEffect::FUNC_DO, &PhaseNode_StopEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(10092, 650) {
    auto node650 = GET_SKILL_NODE(650, PhaseNode_SwitchToInt);
    if (node650 == nullptr) {
        node650 = new PhaseNode_SwitchToInt(650, phase);
        CALL_REGISTER_SKILL_NODE(10092, 650, node650)
    }
    if (noInit == true) {
        return node650;
    }
    auto variables = node650->getVariables();
    if (variables != nullptr) {
        node650->setSelection(variables->getVariable<int32_t>(Variable_10092_100922));
    }
    return node650;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10092, 652) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_RaiseEvent::TRIGGER_DONE, 661, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10092, 652) {
    auto node652 = GET_SKILL_NODE(652, PhaseNode_RaiseEvent);
    if (node652 == nullptr) {
        node652 = new PhaseNode_RaiseEvent(652, phase);
        node652->setEvent("daduan_001");
        node652->setTarget(0U);
        node652->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node652->setTypeParams(0, 0);
        node652->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10092, 652, node652)
    }
    if (noInit == true) {
        return node652;
    }
    return node652;
}
//--------------------------------------------------------------------------------
// StartPreInput
//
REGISTER_REGISTER_SKILL_NODE(10092, 653) {
    pnode->resizeTrigger(PhaseNode_StartPreInput::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_StartPreInput::TRIGGER_DONE, 657, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10092, 653) {
    auto node653 = GET_SKILL_NODE(653, PhaseNode_StartPreInput);
    if (node653 == nullptr) {
        node653 = new PhaseNode_StartPreInput(653, phase);
        node653->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node653->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node653->setDelayTime(.00f);
        CALL_REGISTER_SKILL_NODE(10092, 653, node653)
    }
    if (noInit == true) {
        return node653;
    }
    return node653;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(10092, 654) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_If::TRIGGER_TRUE, 656, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10092, 654) {
    auto node654 = GET_SKILL_NODE(654, PhaseNode_If);
    if (node654 == nullptr) {
        node654 = new PhaseNode_If(654, phase);
        CALL_REGISTER_SKILL_NODE(10092, 654, node654)
    }
    if (noInit == true) {
        return node654;
    }
    auto variables = node654->getVariables();
    if (variables != nullptr) {
        node654->setCondition(variables->getVariable<bool>(Variable_10092_InterruptAnimat));
    }
    return node654;
}
//--------------------------------------------------------------------------------
// IsInterruptType
//
REGISTER_REGISTER_SKILL_NODE(10092, 655) {
    pnode->resizeTrigger(PhaseNode_IsInterruptType::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SwitchToInt>(PhaseNode_IsInterruptType::TRIGGER_BUFF, 650, PhaseNode_SwitchToInt::FUNC_SWITCH, &PhaseNode_SwitchToInt::Switch);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_POSCHANGE, 654, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTAIM, 654, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTFIRE, 654, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTRELOAD, 654, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_USESKILL, 654, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(10092, 655) {
    auto node655 = GET_SKILL_NODE(655, PhaseNode_IsInterruptType);
    if (node655 == nullptr) {
        node655 = new PhaseNode_IsInterruptType(655, phase);
        node655->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node655->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10092, 655, node655)
    }
    if (noInit == true) {
        return node655;
    }
    auto node649 = GET_SKILL_NODE(649, PhaseNode_Detect);
    if (node649 != nullptr) node655->setType(node649->getVars().getVariable<int32_t>(2));
    return node655;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10092, 656) {
}

REGISTER_CREATE_SKILL_NODE(10092, 656) {
    auto node656 = GET_SKILL_NODE(656, PhaseNode_PlayAnimation);
    if (node656 == nullptr) {
        node656 = new PhaseNode_PlayAnimation(656, phase);
        node656->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node656->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node656->setTarget(0U);
        node656->setAnimation("Idle");
        node656->setParameter("");
        node656->setValue(false);
        CALL_REGISTER_SKILL_NODE(10092, 656, node656)
    }
    if (noInit == true) {
        return node656;
    }
    return node656;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10092, 657) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_Delay::TRIGGER_DONE, 660, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(10092, 657) {
    auto node657 = GET_SKILL_NODE(657, PhaseNode_Delay);
    if (node657 == nullptr) {
        node657 = new PhaseNode_Delay(657, phase);
        node657->setTime(.20f);
        CALL_REGISTER_SKILL_NODE(10092, 657, node657)
    }
    if (noInit == true) {
        return node657;
    }
    return node657;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(10092, 660) {
}

REGISTER_CREATE_SKILL_NODE(10092, 660) {
    auto node660 = GET_SKILL_NODE(660, PhaseNode_SetBool);
    if (node660 == nullptr) {
        node660 = new PhaseNode_SetBool(660, phase);
        node660->setName("InterruptAnimat");
        node660->setValue(true);
        CALL_REGISTER_SKILL_NODE(10092, 660, node660)
    }
    if (noInit == true) {
        return node660;
    }
    return node660;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10092, 661) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StartPreInput>(PhaseNode_RaiseEvent::TRIGGER_DONE, 653, PhaseNode_StartPreInput::FUNC_DO, &PhaseNode_StartPreInput::Do);
}

REGISTER_CREATE_SKILL_NODE(10092, 661) {
    auto node661 = GET_SKILL_NODE(661, PhaseNode_RaiseEvent);
    if (node661 == nullptr) {
        node661 = new PhaseNode_RaiseEvent(661, phase);
        node661->setEvent("Dead_001");
        node661->setTarget(0U);
        node661->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node661->setTypeParams(0, 0);
        node661->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10092, 661, node661)
    }
    if (noInit == true) {
        return node661;
    }
    return node661;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10092, 662) {
}

REGISTER_CREATE_SKILL_NODE(10092, 662) {
    auto node662 = GET_SKILL_NODE(662, PhaseNode_Detect);
    if (node662 == nullptr) {
        node662 = new PhaseNode_Detect(662, phase);
        node662->setSelf(0U);
        node662->setEvent("Dead_001");
        node662->setType(PhaseNode_Detect::Detect_Type::Actor_Dead);
        node662->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10092, 662, node662)
    }
    if (noInit == true) {
        return node662;
    }
    return node662;
}

//--------------------------------------------------------------------------------
// SkillCreator_10092
//
class SkillCreator_10092 : public SkillCreator {
public:
    SkillCreator_10092() {}
    virtual ~SkillCreator_10092() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_10092

//--------------------------------------------------------------------------------
// SkillPhase_10092
//
class SkillPhase_10092 : public SkillPhase {
public:
    SkillPhase_10092(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_10092() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(10092, 2) // StartPhase
        CASE_CREATE_SKILL_NODE(10092, 108) // EndPhase
        CASE_CREATE_SKILL_NODE(10092, 543) // Disable
        CASE_CREATE_SKILL_NODE(10092, 548) // SpawnProjectile
        CASE_CREATE_SKILL_NODE(10092, 552) // Delay
        CASE_CREATE_SKILL_NODE(10092, 561) // GetLocation
        CASE_CREATE_SKILL_NODE(10092, 565) // OffsetCalculate
        CASE_CREATE_SKILL_NODE(10092, 572) // AddSkillBuff
        CASE_CREATE_SKILL_NODE(10092, 576) // RemoveSkillBuff
        CASE_CREATE_SKILL_NODE(10092, 578) // PlayEffect
        CASE_CREATE_SKILL_NODE(10092, 580) // StopEffect
        CASE_CREATE_SKILL_NODE(10092, 582) // TimeDown
        CASE_CREATE_SKILL_NODE(10092, 587) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10092, 590) // Detect
        CASE_CREATE_SKILL_NODE(10092, 593) // SetFloat
        CASE_CREATE_SKILL_NODE(10092, 601) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10092, 604) // PlaySound
        CASE_CREATE_SKILL_NODE(10092, 606) // ResetCD
        CASE_CREATE_SKILL_NODE(10092, 608) // PlayUIEffect
        CASE_CREATE_SKILL_NODE(10092, 625) // Delay
        CASE_CREATE_SKILL_NODE(10092, 627) // Delay
        CASE_CREATE_SKILL_NODE(10092, 628) // CameraXYZShake
        CASE_CREATE_SKILL_NODE(10092, 632) // RemoveSkillBuff
        CASE_CREATE_SKILL_NODE(10092, 634) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10092, 636) // Detect
        CASE_CREATE_SKILL_NODE(10092, 638) // PlayEffect
        CASE_CREATE_SKILL_NODE(10092, 640) // PlayEffect
        CASE_CREATE_SKILL_NODE(10092, 642) // StopEffect
        CASE_CREATE_SKILL_NODE(10092, 644) // GetInputRotation
        CASE_CREATE_SKILL_NODE(10092, 647) // SetFloat
        CASE_CREATE_SKILL_NODE(10092, 649) // Detect
        CASE_CREATE_SKILL_NODE(10092, 650) // SwitchToInt
        CASE_CREATE_SKILL_NODE(10092, 652) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10092, 653) // StartPreInput
        CASE_CREATE_SKILL_NODE(10092, 654) // If
        CASE_CREATE_SKILL_NODE(10092, 655) // IsInterruptType
        CASE_CREATE_SKILL_NODE(10092, 656) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10092, 657) // Delay
        CASE_CREATE_SKILL_NODE(10092, 660) // SetBool
        CASE_CREATE_SKILL_NODE(10092, 661) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10092, 662) // Detect
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_10092

SkillLogic* SkillCreator_10092::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //设置变量
    Variable_10092_a100923 = logic->getVariables().setVariable<float>("a100923");
    Variable_10092_100922 = logic->getVariables().setVariable<int32_t>("100922", 1);
    Variable_10092_InterruptAnimat = logic->getVariables().setVariable<bool>("InterruptAnimat");
    //创建阶段phase
    auto phase = new SkillPhase_10092(1, logic, 2);
    //设置phase执行器
    phase->setRunPhaseNode(1, 2);
    phase->setDetectPhaseNode(2, 590);
    phase->setDetectPhaseNode(2, 636);
    phase->setDetectPhaseNode(2, 649);
    phase->setDetectPhaseNode(2, 662);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_10092::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
