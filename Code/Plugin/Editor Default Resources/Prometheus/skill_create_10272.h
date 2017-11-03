#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

#include "skill_psnode_addskillbuff.h"
#include "skill_psnode_delay.h"
#include "skill_psnode_detect.h"
#include "skill_psnode_disable.h"
#include "skill_psnode_endphase.h"
#include "skill_psnode_getlocation.h"
#include "skill_psnode_if.h"
#include "skill_psnode_isinterrupttype.h"
#include "skill_psnode_playanimation.h"
#include "skill_psnode_playeffect.h"
#include "skill_psnode_playsound.h"
#include "skill_psnode_raiseevent.h"
#include "skill_psnode_removeskillbuff.h"
#include "skill_psnode_resetcd.h"
#include "skill_psnode_setbool.h"
#include "skill_psnode_startphase.h"
#include "skill_psnode_startpreinput.h"
#include "skill_psnode_switchtoint.h"

namespace pvp {

//变量声明
uint64_t Variable_10272_a1027211 = 0;
uint64_t Variable_10272_a102729 = 0;
uint64_t Variable_10272_InterruptAnimat = 0;
//--------------------------------------------------------------------------------
// StartPhase
//
REGISTER_REGISTER_SKILL_NODE(10272, 3) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuff>(PhaseNode_StartPhase::TRIGGER_START, 84, PhaseNode_AddSkillBuff::FUNC_ADD, &PhaseNode_AddSkillBuff::Add);
}

REGISTER_CREATE_SKILL_NODE(10272, 3) {
    auto node3 = GET_SKILL_NODE(3, PhaseNode_StartPhase);
    if (node3 == nullptr) {
        node3 = new PhaseNode_StartPhase(3, phase);
        CALL_REGISTER_SKILL_NODE(10272, 3, node3)
    }
    if (noInit == true) {
        return node3;
    }
    return node3;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(10272, 6) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Disable>(PhaseNode_ResetCD::TRIGGER_DONE, 19, PhaseNode_Disable::FUNC_DO, &PhaseNode_Disable::Do);
}

REGISTER_CREATE_SKILL_NODE(10272, 6) {
    auto node6 = GET_SKILL_NODE(6, PhaseNode_ResetCD);
    if (node6 == nullptr) {
        node6 = new PhaseNode_ResetCD(6, phase);
        node6->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node6->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node6->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(10272, 6, node6)
    }
    if (noInit == true) {
        return node6;
    }
    return node6;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10272, 8) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlayAnimation::TRIGGER_DONE, 11, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10272, 8) {
    auto node8 = GET_SKILL_NODE(8, PhaseNode_PlayAnimation);
    if (node8 == nullptr) {
        node8 = new PhaseNode_PlayAnimation(8, phase);
        node8->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node8->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node8->setTarget(0U);
        node8->setAnimation("Skill2S1");
        node8->setParameter("");
        node8->setValue(false);
        CALL_REGISTER_SKILL_NODE(10272, 8, node8)
    }
    if (noInit == true) {
        return node8;
    }
    return node8;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10272, 11) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_Delay::TRIGGER_DONE, 33, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10272, 11) {
    auto node11 = GET_SKILL_NODE(11, PhaseNode_Delay);
    if (node11 == nullptr) {
        node11 = new PhaseNode_Delay(11, phase);
        node11->setTime(.07f);
        CALL_REGISTER_SKILL_NODE(10272, 11, node11)
    }
    if (noInit == true) {
        return node11;
    }
    return node11;
}
//--------------------------------------------------------------------------------
// Disable
//
REGISTER_REGISTER_SKILL_NODE(10272, 19) {
    pnode->resizeTrigger(PhaseNode_Disable::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_Disable::TRIGGER_DONE, 8, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_Disable::TRIGGER_DONE, 193, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10272, 19) {
    auto node19 = GET_SKILL_NODE(19, PhaseNode_Disable);
    if (node19 == nullptr) {
        node19 = new PhaseNode_Disable(19, phase);
        node19->setTarget(0U);
        node19->setMove(true);
        node19->setSkill(true);
        node19->setShoot(true);
        node19->setTime(1.52f);
        node19->setRotate(true);
        CALL_REGISTER_SKILL_NODE(10272, 19, node19)
    }
    if (noInit == true) {
        return node19;
    }
    return node19;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10272, 31) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlayAnimation::TRIGGER_DONE, 39, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_Disable>(PhaseNode_PlayAnimation::TRIGGER_DONE, 19, PhaseNode_Disable::FUNC_CANCLE, &PhaseNode_Disable::Cancle);
}

REGISTER_CREATE_SKILL_NODE(10272, 31) {
    auto node31 = GET_SKILL_NODE(31, PhaseNode_PlayAnimation);
    if (node31 == nullptr) {
        node31 = new PhaseNode_PlayAnimation(31, phase);
        node31->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node31->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node31->setTarget(0U);
        node31->setAnimation("Skill2S4");
        node31->setParameter("");
        node31->setValue(false);
        CALL_REGISTER_SKILL_NODE(10272, 31, node31)
    }
    if (noInit == true) {
        return node31;
    }
    return node31;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10272, 33) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_PlayAnimation::TRIGGER_DONE, 282, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10272, 33) {
    auto node33 = GET_SKILL_NODE(33, PhaseNode_PlayAnimation);
    if (node33 == nullptr) {
        node33 = new PhaseNode_PlayAnimation(33, phase);
        node33->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node33->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node33->setTarget(0U);
        node33->setAnimation("Skill2S2");
        node33->setParameter("");
        node33->setValue(false);
        CALL_REGISTER_SKILL_NODE(10272, 33, node33)
    }
    if (noInit == true) {
        return node33;
    }
    return node33;
}
//--------------------------------------------------------------------------------
// RemoveSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10272, 37) {
    pnode->resizeTrigger(PhaseNode_RemoveSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RemoveSkillBuff>(PhaseNode_RemoveSkillBuff::TRIGGER_DONE, 209, PhaseNode_RemoveSkillBuff::FUNC_REMOVE, &PhaseNode_RemoveSkillBuff::Remove);
}

REGISTER_CREATE_SKILL_NODE(10272, 37) {
    auto node37 = GET_SKILL_NODE(37, PhaseNode_RemoveSkillBuff);
    if (node37 == nullptr) {
        node37 = new PhaseNode_RemoveSkillBuff(37, phase);
        node37->setBuffID(0U);
        node37->setBuffIDs({});
        node37->setConfigID(102721);
        node37->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(10272, 37, node37)
    }
    if (noInit == true) {
        return node37;
    }
    return node37;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10272, 39) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RemoveSkillBuff>(PhaseNode_Delay::TRIGGER_DONE, 37, PhaseNode_RemoveSkillBuff::FUNC_REMOVE, &PhaseNode_RemoveSkillBuff::Remove);
}

REGISTER_CREATE_SKILL_NODE(10272, 39) {
    auto node39 = GET_SKILL_NODE(39, PhaseNode_Delay);
    if (node39 == nullptr) {
        node39 = new PhaseNode_Delay(39, phase);
        node39->setTime(.13f);
        CALL_REGISTER_SKILL_NODE(10272, 39, node39)
    }
    if (noInit == true) {
        return node39;
    }
    return node39;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(10272, 42) {
}

REGISTER_CREATE_SKILL_NODE(10272, 42) {
    auto node42 = GET_SKILL_NODE(42, PhaseNode_EndPhase);
    if (node42 == nullptr) {
        node42 = new PhaseNode_EndPhase(42, phase);
        node42->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node42->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10272, 42, node42)
    }
    if (noInit == true) {
        return node42;
    }
    return node42;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10272, 44) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_Delay::TRIGGER_DONE, 53, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10272, 44) {
    auto node44 = GET_SKILL_NODE(44, PhaseNode_Delay);
    if (node44 == nullptr) {
        node44 = new PhaseNode_Delay(44, phase);
        node44->setTime(1.43f);
        CALL_REGISTER_SKILL_NODE(10272, 44, node44)
    }
    if (noInit == true) {
        return node44;
    }
    return node44;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(10272, 51) {
    pnode->resizeTrigger(PhaseNode_SetBool::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_SetBool::TRIGGER_DONE, 55, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10272, 51) {
    auto node51 = GET_SKILL_NODE(51, PhaseNode_SetBool);
    if (node51 == nullptr) {
        node51 = new PhaseNode_SetBool(51, phase);
        node51->setName("a1027211");
        node51->setValue(true);
        CALL_REGISTER_SKILL_NODE(10272, 51, node51)
    }
    if (noInit == true) {
        return node51;
    }
    return node51;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10272, 53) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_PlayAnimation::TRIGGER_DONE, 51, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(10272, 53) {
    auto node53 = GET_SKILL_NODE(53, PhaseNode_PlayAnimation);
    if (node53 == nullptr) {
        node53 = new PhaseNode_PlayAnimation(53, phase);
        node53->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node53->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node53->setTarget(0U);
        node53->setAnimation("Skill2S3");
        node53->setParameter("");
        node53->setValue(false);
        CALL_REGISTER_SKILL_NODE(10272, 53, node53)
    }
    if (noInit == true) {
        return node53;
    }
    return node53;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10272, 55) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RemoveSkillBuff>(PhaseNode_Delay::TRIGGER_DONE, 209, PhaseNode_RemoveSkillBuff::FUNC_REMOVE, &PhaseNode_RemoveSkillBuff::Remove);
}

REGISTER_CREATE_SKILL_NODE(10272, 55) {
    auto node55 = GET_SKILL_NODE(55, PhaseNode_Delay);
    if (node55 == nullptr) {
        node55 = new PhaseNode_Delay(55, phase);
        node55->setTime(.07f);
        CALL_REGISTER_SKILL_NODE(10272, 55, node55)
    }
    if (noInit == true) {
        return node55;
    }
    return node55;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(10272, 57) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_If::TRIGGER_FALSE, 155, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(10272, 57) {
    auto node57 = GET_SKILL_NODE(57, PhaseNode_If);
    if (node57 == nullptr) {
        node57 = new PhaseNode_If(57, phase);
        CALL_REGISTER_SKILL_NODE(10272, 57, node57)
    }
    if (noInit == true) {
        return node57;
    }
    auto variables = node57->getVariables();
    if (variables != nullptr) {
        node57->setCondition(variables->getVariable<bool>(Variable_10272_a1027211));
    }
    return node57;
}
//--------------------------------------------------------------------------------
// AddSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10272, 84) {
    pnode->resizeTrigger(PhaseNode_AddSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_AddSkillBuff::TRIGGER_DONE, 6, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(10272, 84) {
    auto node84 = GET_SKILL_NODE(84, PhaseNode_AddSkillBuff);
    if (node84 == nullptr) {
        node84 = new PhaseNode_AddSkillBuff(84, phase);
        node84->setConfigID(0);
        node84->setConfigIDs({102721,102741,4});
        node84->setTarget(0U);
        node84->setAttribute({{}});
        CALL_REGISTER_SKILL_NODE(10272, 84, node84)
    }
    if (noInit == true) {
        return node84;
    }
    return node84;
}
//--------------------------------------------------------------------------------
// AddSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10272, 88) {
    pnode->resizeTrigger(PhaseNode_AddSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_AddSkillBuff::TRIGGER_DONE, 31, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10272, 88) {
    auto node88 = GET_SKILL_NODE(88, PhaseNode_AddSkillBuff);
    if (node88 == nullptr) {
        node88 = new PhaseNode_AddSkillBuff(88, phase);
        node88->setConfigID(102722);
        node88->setConfigIDs({});
        node88->setTarget(0U);
        node88->setAttribute({{}});
        CALL_REGISTER_SKILL_NODE(10272, 88, node88)
    }
    if (noInit == true) {
        return node88;
    }
    return node88;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(10272, 155) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_GetLocation::TRIGGER_DONE, 277, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(10272, 155) {
    auto node155 = GET_SKILL_NODE(155, PhaseNode_GetLocation);
    if (node155 == nullptr) {
        node155 = new PhaseNode_GetLocation(155, phase);
        node155->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node155->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(10272, 155, node155)
    }
    if (noInit == true) {
        return node155;
    }
    return node155;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10272, 193) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_PlaySound::TRIGGER_DONE, 195, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10272, 193) {
    auto node193 = GET_SKILL_NODE(193, PhaseNode_PlaySound);
    if (node193 == nullptr) {
        node193 = new PhaseNode_PlaySound(193, phase);
        node193->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node193->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node193->setSoundID("SE_Hero110_SkillB_P1");
        node193->setTarget(0U);
        node193->setUsePos(false);
        node193->setPosX(.00f);
        node193->setPosY(.00f);
        node193->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10272, 193, node193)
    }
    if (noInit == true) {
        return node193;
    }
    return node193;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10272, 195) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_PlaySound::TRIGGER_DONE, 287, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10272, 195) {
    auto node195 = GET_SKILL_NODE(195, PhaseNode_PlaySound);
    if (node195 == nullptr) {
        node195 = new PhaseNode_PlaySound(195, phase);
        node195->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node195->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node195->setSoundID("VO_Hero110_Skill_B");
        node195->setTarget(0U);
        node195->setUsePos(false);
        node195->setPosX(.00f);
        node195->setPosY(.00f);
        node195->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10272, 195, node195)
    }
    if (noInit == true) {
        return node195;
    }
    return node195;
}
//--------------------------------------------------------------------------------
// RemoveSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10272, 209) {
    pnode->resizeTrigger(PhaseNode_RemoveSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_RemoveSkillBuff::TRIGGER_DONE, 42, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(10272, 209) {
    auto node209 = GET_SKILL_NODE(209, PhaseNode_RemoveSkillBuff);
    if (node209 == nullptr) {
        node209 = new PhaseNode_RemoveSkillBuff(209, phase);
        node209->setBuffID(0U);
        node209->setBuffIDs({});
        node209->setConfigID(4);
        node209->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(10272, 209, node209)
    }
    if (noInit == true) {
        return node209;
    }
    return node209;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(10272, 277) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuff>(PhaseNode_PlayEffect::TRIGGER_DONE, 88, PhaseNode_AddSkillBuff::FUNC_ADD, &PhaseNode_AddSkillBuff::Add);
}

REGISTER_CREATE_SKILL_NODE(10272, 277) {
    auto node277 = GET_SKILL_NODE(277, PhaseNode_PlayEffect);
    if (node277 == nullptr) {
        node277 = new PhaseNode_PlayEffect(277, phase);
        node277->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node277->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node277->setEffectID(102722);
        node277->setChangeColor(false);
        node277->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node277->getVars().reserve(3);
        node277->getVars().setVariable<float>(0, .00f);
        node277->getVars().setVariable<float>(1, .00f);
        node277->getVars().setVariable<float>(2, .00f);
        node277->setRotation(.00f);
        node277->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(10272, 277, node277)
    }
    if (noInit == true) {
        return node277;
    }
    auto node155 = GET_SKILL_NODE(155, PhaseNode_GetLocation);
    if (node155 != nullptr) node277->getVars().setVariable<float>(0, node155->getX());
    if (node155 != nullptr) node277->getVars().setVariable<float>(1, node155->getY());
    return node277;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10272, 280) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_Detect::TRIGGER_ON, 57, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(10272, 280) {
    auto node280 = GET_SKILL_NODE(280, PhaseNode_Detect);
    if (node280 == nullptr) {
        node280 = new PhaseNode_Detect(280, phase);
        node280->setSelf(0U);
        node280->setEvent("a1027211");
        node280->setType(PhaseNode_Detect::Detect_Type::Damage);
        node280->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10272, 280, node280)
    }
    if (noInit == true) {
        return node280;
    }
    return node280;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10272, 282) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_RaiseEvent::TRIGGER_DONE, 44, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10272, 282) {
    auto node282 = GET_SKILL_NODE(282, PhaseNode_RaiseEvent);
    if (node282 == nullptr) {
        node282 = new PhaseNode_RaiseEvent(282, phase);
        node282->setEvent("a1027211");
        node282->setTarget(0U);
        node282->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node282->setTypeParams(0, 0);
        node282->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10272, 282, node282)
    }
    if (noInit == true) {
        return node282;
    }
    return node282;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10272, 284) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_IsInterruptType>(PhaseNode_Detect::TRIGGER_ON, 290, PhaseNode_IsInterruptType::FUNC_DO, &PhaseNode_IsInterruptType::Do);
}

REGISTER_CREATE_SKILL_NODE(10272, 284) {
    auto node284 = GET_SKILL_NODE(284, PhaseNode_Detect);
    if (node284 == nullptr) {
        node284 = new PhaseNode_Detect(284, phase);
        node284->setSelf(0U);
        node284->setEvent("daduan_001");
        node284->setType(PhaseNode_Detect::Detect_Type::Interrupt_Skill);
        node284->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10272, 284, node284)
    }
    if (noInit == true) {
        return node284;
    }
    return node284;
}
//--------------------------------------------------------------------------------
// SwitchToInt
//
REGISTER_REGISTER_SKILL_NODE(10272, 285) {
}

REGISTER_CREATE_SKILL_NODE(10272, 285) {
    auto node285 = GET_SKILL_NODE(285, PhaseNode_SwitchToInt);
    if (node285 == nullptr) {
        node285 = new PhaseNode_SwitchToInt(285, phase);
        CALL_REGISTER_SKILL_NODE(10272, 285, node285)
    }
    if (noInit == true) {
        return node285;
    }
    auto variables = node285->getVariables();
    if (variables != nullptr) {
        node285->setSelection(variables->getVariable<int32_t>(Variable_10272_a102729));
    }
    return node285;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10272, 287) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_RaiseEvent::TRIGGER_DONE, 296, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10272, 287) {
    auto node287 = GET_SKILL_NODE(287, PhaseNode_RaiseEvent);
    if (node287 == nullptr) {
        node287 = new PhaseNode_RaiseEvent(287, phase);
        node287->setEvent("daduan_001");
        node287->setTarget(0U);
        node287->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node287->setTypeParams(0, 0);
        node287->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10272, 287, node287)
    }
    if (noInit == true) {
        return node287;
    }
    return node287;
}
//--------------------------------------------------------------------------------
// StartPreInput
//
REGISTER_REGISTER_SKILL_NODE(10272, 288) {
    pnode->resizeTrigger(PhaseNode_StartPreInput::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_StartPreInput::TRIGGER_DONE, 292, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10272, 288) {
    auto node288 = GET_SKILL_NODE(288, PhaseNode_StartPreInput);
    if (node288 == nullptr) {
        node288 = new PhaseNode_StartPreInput(288, phase);
        node288->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node288->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node288->setDelayTime(.00f);
        CALL_REGISTER_SKILL_NODE(10272, 288, node288)
    }
    if (noInit == true) {
        return node288;
    }
    return node288;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(10272, 289) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_If::TRIGGER_TRUE, 291, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10272, 289) {
    auto node289 = GET_SKILL_NODE(289, PhaseNode_If);
    if (node289 == nullptr) {
        node289 = new PhaseNode_If(289, phase);
        CALL_REGISTER_SKILL_NODE(10272, 289, node289)
    }
    if (noInit == true) {
        return node289;
    }
    auto variables = node289->getVariables();
    if (variables != nullptr) {
        node289->setCondition(variables->getVariable<bool>(Variable_10272_InterruptAnimat));
    }
    return node289;
}
//--------------------------------------------------------------------------------
// IsInterruptType
//
REGISTER_REGISTER_SKILL_NODE(10272, 290) {
    pnode->resizeTrigger(PhaseNode_IsInterruptType::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SwitchToInt>(PhaseNode_IsInterruptType::TRIGGER_BUFF, 285, PhaseNode_SwitchToInt::FUNC_SWITCH, &PhaseNode_SwitchToInt::Switch);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_POSCHANGE, 289, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTAIM, 289, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTFIRE, 289, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTRELOAD, 289, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_USESKILL, 289, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(10272, 290) {
    auto node290 = GET_SKILL_NODE(290, PhaseNode_IsInterruptType);
    if (node290 == nullptr) {
        node290 = new PhaseNode_IsInterruptType(290, phase);
        node290->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node290->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10272, 290, node290)
    }
    if (noInit == true) {
        return node290;
    }
    auto node284 = GET_SKILL_NODE(284, PhaseNode_Detect);
    if (node284 != nullptr) node290->setType(node284->getVars().getVariable<int32_t>(2));
    return node290;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10272, 291) {
}

REGISTER_CREATE_SKILL_NODE(10272, 291) {
    auto node291 = GET_SKILL_NODE(291, PhaseNode_PlayAnimation);
    if (node291 == nullptr) {
        node291 = new PhaseNode_PlayAnimation(291, phase);
        node291->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node291->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node291->setTarget(0U);
        node291->setAnimation("Idle");
        node291->setParameter("");
        node291->setValue(false);
        CALL_REGISTER_SKILL_NODE(10272, 291, node291)
    }
    if (noInit == true) {
        return node291;
    }
    return node291;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10272, 292) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_Delay::TRIGGER_DONE, 295, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(10272, 292) {
    auto node292 = GET_SKILL_NODE(292, PhaseNode_Delay);
    if (node292 == nullptr) {
        node292 = new PhaseNode_Delay(292, phase);
        node292->setTime(.20f);
        CALL_REGISTER_SKILL_NODE(10272, 292, node292)
    }
    if (noInit == true) {
        return node292;
    }
    return node292;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(10272, 295) {
}

REGISTER_CREATE_SKILL_NODE(10272, 295) {
    auto node295 = GET_SKILL_NODE(295, PhaseNode_SetBool);
    if (node295 == nullptr) {
        node295 = new PhaseNode_SetBool(295, phase);
        node295->setName("InterruptAnimat");
        node295->setValue(true);
        CALL_REGISTER_SKILL_NODE(10272, 295, node295)
    }
    if (noInit == true) {
        return node295;
    }
    return node295;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10272, 296) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StartPreInput>(PhaseNode_RaiseEvent::TRIGGER_DONE, 288, PhaseNode_StartPreInput::FUNC_DO, &PhaseNode_StartPreInput::Do);
}

REGISTER_CREATE_SKILL_NODE(10272, 296) {
    auto node296 = GET_SKILL_NODE(296, PhaseNode_RaiseEvent);
    if (node296 == nullptr) {
        node296 = new PhaseNode_RaiseEvent(296, phase);
        node296->setEvent("Dead_001");
        node296->setTarget(0U);
        node296->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node296->setTypeParams(0, 0);
        node296->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10272, 296, node296)
    }
    if (noInit == true) {
        return node296;
    }
    return node296;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10272, 297) {
}

REGISTER_CREATE_SKILL_NODE(10272, 297) {
    auto node297 = GET_SKILL_NODE(297, PhaseNode_Detect);
    if (node297 == nullptr) {
        node297 = new PhaseNode_Detect(297, phase);
        node297->setSelf(0U);
        node297->setEvent("Dead_001");
        node297->setType(PhaseNode_Detect::Detect_Type::Actor_Dead);
        node297->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10272, 297, node297)
    }
    if (noInit == true) {
        return node297;
    }
    return node297;
}

//--------------------------------------------------------------------------------
// SkillCreator_10272
//
class SkillCreator_10272 : public SkillCreator {
public:
    SkillCreator_10272() {}
    virtual ~SkillCreator_10272() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_10272

//--------------------------------------------------------------------------------
// SkillPhase_10272
//
class SkillPhase_10272 : public SkillPhase {
public:
    SkillPhase_10272(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_10272() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(10272, 3) // StartPhase
        CASE_CREATE_SKILL_NODE(10272, 6) // ResetCD
        CASE_CREATE_SKILL_NODE(10272, 8) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10272, 11) // Delay
        CASE_CREATE_SKILL_NODE(10272, 19) // Disable
        CASE_CREATE_SKILL_NODE(10272, 31) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10272, 33) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10272, 37) // RemoveSkillBuff
        CASE_CREATE_SKILL_NODE(10272, 39) // Delay
        CASE_CREATE_SKILL_NODE(10272, 42) // EndPhase
        CASE_CREATE_SKILL_NODE(10272, 44) // Delay
        CASE_CREATE_SKILL_NODE(10272, 51) // SetBool
        CASE_CREATE_SKILL_NODE(10272, 53) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10272, 55) // Delay
        CASE_CREATE_SKILL_NODE(10272, 57) // If
        CASE_CREATE_SKILL_NODE(10272, 84) // AddSkillBuff
        CASE_CREATE_SKILL_NODE(10272, 88) // AddSkillBuff
        CASE_CREATE_SKILL_NODE(10272, 155) // GetLocation
        CASE_CREATE_SKILL_NODE(10272, 193) // PlaySound
        CASE_CREATE_SKILL_NODE(10272, 195) // PlaySound
        CASE_CREATE_SKILL_NODE(10272, 209) // RemoveSkillBuff
        CASE_CREATE_SKILL_NODE(10272, 277) // PlayEffect
        CASE_CREATE_SKILL_NODE(10272, 280) // Detect
        CASE_CREATE_SKILL_NODE(10272, 282) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10272, 284) // Detect
        CASE_CREATE_SKILL_NODE(10272, 285) // SwitchToInt
        CASE_CREATE_SKILL_NODE(10272, 287) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10272, 288) // StartPreInput
        CASE_CREATE_SKILL_NODE(10272, 289) // If
        CASE_CREATE_SKILL_NODE(10272, 290) // IsInterruptType
        CASE_CREATE_SKILL_NODE(10272, 291) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10272, 292) // Delay
        CASE_CREATE_SKILL_NODE(10272, 295) // SetBool
        CASE_CREATE_SKILL_NODE(10272, 296) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10272, 297) // Detect
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_10272

SkillLogic* SkillCreator_10272::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //设置变量
    Variable_10272_a1027211 = logic->getVariables().setVariable<bool>("a1027211");
    Variable_10272_a102729 = logic->getVariables().setVariable<int32_t>("a102729", 1);
    Variable_10272_InterruptAnimat = logic->getVariables().setVariable<bool>("InterruptAnimat");
    //创建阶段phase
    auto phase = new SkillPhase_10272(1, logic, 2);
    //设置phase执行器
    phase->setRunPhaseNode(1, 3);
    phase->setDetectPhaseNode(2, 280);
    phase->setDetectPhaseNode(2, 284);
    phase->setDetectPhaseNode(2, 297);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_10272::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
