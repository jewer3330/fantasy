#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

#include "skill_psnode_addskillbuff.h"
#include "skill_psnode_delay.h"
#include "skill_psnode_detect.h"
#include "skill_psnode_endphase.h"
#include "skill_psnode_for.h"
#include "skill_psnode_forcontinue.h"
#include "skill_psnode_if.h"
#include "skill_psnode_isinterrupttype.h"
#include "skill_psnode_playanimation.h"
#include "skill_psnode_playeffect.h"
#include "skill_psnode_playsound.h"
#include "skill_psnode_raiseevent.h"
#include "skill_psnode_removeskillbuff.h"
#include "skill_psnode_resetcd.h"
#include "skill_psnode_setint.h"
#include "skill_psnode_skillendnotify.h"
#include "skill_psnode_startphase.h"
#include "skill_psnode_stopsound.h"
#include "skill_psnode_switchtoint.h"
#include "skill_psnode_triggerupdate.h"

namespace pvp {

//变量声明
uint64_t Variable_22064_Step = 0;
//--------------------------------------------------------------------------------
// StartPhase
//
REGISTER_REGISTER_SKILL_NODE(22064, 2) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_StartPhase::TRIGGER_START, 93, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_StartPhase::TRIGGER_START, 85, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(22064, 2) {
    auto node2 = GET_SKILL_NODE(2, PhaseNode_StartPhase);
    if (node2 == nullptr) {
        node2 = new PhaseNode_StartPhase(2, phase);
        CALL_REGISTER_SKILL_NODE(22064, 2, node2)
    }
    if (noInit == true) {
        return node2;
    }
    return node2;
}
//--------------------------------------------------------------------------------
// TriggerUpdate
//
REGISTER_REGISTER_SKILL_NODE(22064, 4) {
}

REGISTER_CREATE_SKILL_NODE(22064, 4) {
    auto node4 = GET_SKILL_NODE(4, PhaseNode_TriggerUpdate);
    if (node4 == nullptr) {
        node4 = new PhaseNode_TriggerUpdate(4, phase);
        CALL_REGISTER_SKILL_NODE(22064, 4, node4)
    }
    if (noInit == true) {
        return node4;
    }
    return node4;
}
//--------------------------------------------------------------------------------
// AddSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(22064, 14) {
    pnode->resizeTrigger(PhaseNode_AddSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_AddSkillBuff::TRIGGER_DONE, 84, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(22064, 14) {
    auto node14 = GET_SKILL_NODE(14, PhaseNode_AddSkillBuff);
    if (node14 == nullptr) {
        node14 = new PhaseNode_AddSkillBuff(14, phase);
        node14->setConfigID(220741);
        node14->setConfigIDs({});
        node14->setTarget(0U);
        node14->setAttribute({{}});
        CALL_REGISTER_SKILL_NODE(22064, 14, node14)
    }
    if (noInit == true) {
        return node14;
    }
    return node14;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(22064, 18) {
}

REGISTER_CREATE_SKILL_NODE(22064, 18) {
    auto node18 = GET_SKILL_NODE(18, PhaseNode_EndPhase);
    if (node18 == nullptr) {
        node18 = new PhaseNode_EndPhase(18, phase);
        node18->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node18->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(22064, 18, node18)
    }
    if (noInit == true) {
        return node18;
    }
    return node18;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(22064, 21) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlayAnimation::TRIGGER_DONE, 100, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_For>(PhaseNode_PlayAnimation::TRIGGER_DONE, 29, PhaseNode_For::FUNC_START, &PhaseNode_For::Start);
}

REGISTER_CREATE_SKILL_NODE(22064, 21) {
    auto node21 = GET_SKILL_NODE(21, PhaseNode_PlayAnimation);
    if (node21 == nullptr) {
        node21 = new PhaseNode_PlayAnimation(21, phase);
        node21->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node21->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node21->setTarget(0U);
        node21->setAnimation("Skill4S2");
        node21->setParameter("");
        node21->setValue(false);
        CALL_REGISTER_SKILL_NODE(22064, 21, node21)
    }
    if (noInit == true) {
        return node21;
    }
    return node21;
}
//--------------------------------------------------------------------------------
// For
//
REGISTER_REGISTER_SKILL_NODE(22064, 29) {
    pnode->resizeTrigger(PhaseNode_For::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuff>(PhaseNode_For::TRIGGER_DO, 14, PhaseNode_AddSkillBuff::FUNC_ADD, &PhaseNode_AddSkillBuff::Add);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_For::TRIGGER_DONE, 38, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(22064, 29) {
    auto node29 = GET_SKILL_NODE(29, PhaseNode_For);
    if (node29 == nullptr) {
        node29 = new PhaseNode_For(29, phase);
        node29->setBegin(0);
        node29->setIncrease(1);
        node29->setEnd(6);
        CALL_REGISTER_SKILL_NODE(22064, 29, node29)
    }
    if (noInit == true) {
        return node29;
    }
    return node29;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22064, 34) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ForContinue>(PhaseNode_Delay::TRIGGER_DONE, 36, PhaseNode_ForContinue::FUNC_DO, &PhaseNode_ForContinue::Do);
}

REGISTER_CREATE_SKILL_NODE(22064, 34) {
    auto node34 = GET_SKILL_NODE(34, PhaseNode_Delay);
    if (node34 == nullptr) {
        node34 = new PhaseNode_Delay(34, phase);
        node34->setTime(.50f);
        CALL_REGISTER_SKILL_NODE(22064, 34, node34)
    }
    if (noInit == true) {
        return node34;
    }
    return node34;
}
//--------------------------------------------------------------------------------
// ForContinue
//
REGISTER_REGISTER_SKILL_NODE(22064, 36) {
}

REGISTER_CREATE_SKILL_NODE(22064, 36) {
    auto node36 = GET_SKILL_NODE(36, PhaseNode_ForContinue);
    if (node36 == nullptr) {
        node36 = new PhaseNode_ForContinue(36, phase);
        CALL_REGISTER_SKILL_NODE(22064, 36, node36)
    }
    if (noInit == true) {
        return node36;
    }
    auto node29 = GET_SKILL_NODE(29, PhaseNode_For);
    if (node29 != nullptr) node36->setFID(node29->getFID());
    return node36;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(22064, 38) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlayAnimation::TRIGGER_DONE, 89, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(22064, 38) {
    auto node38 = GET_SKILL_NODE(38, PhaseNode_PlayAnimation);
    if (node38 == nullptr) {
        node38 = new PhaseNode_PlayAnimation(38, phase);
        node38->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node38->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node38->setTarget(0U);
        node38->setAnimation("Skill4S3");
        node38->setParameter("");
        node38->setValue(false);
        CALL_REGISTER_SKILL_NODE(22064, 38, node38)
    }
    if (noInit == true) {
        return node38;
    }
    return node38;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(22064, 40) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_Detect::TRIGGER_ON, 42, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(22064, 40) {
    auto node40 = GET_SKILL_NODE(40, PhaseNode_Detect);
    if (node40 == nullptr) {
        node40 = new PhaseNode_Detect(40, phase);
        node40->setSelf(0U);
        node40->setEvent("");
        node40->setType(PhaseNode_Detect::Detect_Type::Actor_Dead);
        node40->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(22064, 40, node40)
    }
    if (noInit == true) {
        return node40;
    }
    return node40;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(22064, 42) {
}

REGISTER_CREATE_SKILL_NODE(22064, 42) {
    auto node42 = GET_SKILL_NODE(42, PhaseNode_EndPhase);
    if (node42 == nullptr) {
        node42 = new PhaseNode_EndPhase(42, phase);
        node42->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node42->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(22064, 42, node42)
    }
    if (noInit == true) {
        return node42;
    }
    return node42;
}
//--------------------------------------------------------------------------------
// RemoveSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(22064, 75) {
    pnode->resizeTrigger(PhaseNode_RemoveSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RemoveSkillBuff>(PhaseNode_RemoveSkillBuff::TRIGGER_DONE, 77, PhaseNode_RemoveSkillBuff::FUNC_REMOVE, &PhaseNode_RemoveSkillBuff::Remove);
}

REGISTER_CREATE_SKILL_NODE(22064, 75) {
    auto node75 = GET_SKILL_NODE(75, PhaseNode_RemoveSkillBuff);
    if (node75 == nullptr) {
        node75 = new PhaseNode_RemoveSkillBuff(75, phase);
        node75->setBuffID(0U);
        node75->setBuffIDs({});
        node75->setConfigID(0);
        node75->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(22064, 75, node75)
    }
    if (noInit == true) {
        return node75;
    }
    return node75;
}
//--------------------------------------------------------------------------------
// RemoveSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(22064, 77) {
    pnode->resizeTrigger(PhaseNode_RemoveSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_RemoveSkillBuff::TRIGGER_DONE, 79, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(22064, 77) {
    auto node77 = GET_SKILL_NODE(77, PhaseNode_RemoveSkillBuff);
    if (node77 == nullptr) {
        node77 = new PhaseNode_RemoveSkillBuff(77, phase);
        node77->setBuffID(0U);
        node77->setBuffIDs({});
        node77->setConfigID(0);
        node77->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(22064, 77, node77)
    }
    if (noInit == true) {
        return node77;
    }
    return node77;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(22064, 79) {
}

REGISTER_CREATE_SKILL_NODE(22064, 79) {
    auto node79 = GET_SKILL_NODE(79, PhaseNode_EndPhase);
    if (node79 == nullptr) {
        node79 = new PhaseNode_EndPhase(79, phase);
        node79->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node79->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(22064, 79, node79)
    }
    if (noInit == true) {
        return node79;
    }
    return node79;
}
//--------------------------------------------------------------------------------
// StopSound
//
REGISTER_REGISTER_SKILL_NODE(22064, 82) {
    pnode->resizeTrigger(PhaseNode_StopSound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RemoveSkillBuff>(PhaseNode_StopSound::TRIGGER_DONE, 75, PhaseNode_RemoveSkillBuff::FUNC_REMOVE, &PhaseNode_RemoveSkillBuff::Remove);
}

REGISTER_CREATE_SKILL_NODE(22064, 82) {
    auto node82 = GET_SKILL_NODE(82, PhaseNode_StopSound);
    if (node82 == nullptr) {
        node82 = new PhaseNode_StopSound(82, phase);
        node82->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node82->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node82->setSoundID("  SE_MON2207_Skill");
        CALL_REGISTER_SKILL_NODE(22064, 82, node82)
    }
    if (noInit == true) {
        return node82;
    }
    return node82;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(22064, 84) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetInt>(PhaseNode_PlayEffect::TRIGGER_DONE, 99, PhaseNode_SetInt::FUNC_SET, &PhaseNode_SetInt::Set);
}

REGISTER_CREATE_SKILL_NODE(22064, 84) {
    auto node84 = GET_SKILL_NODE(84, PhaseNode_PlayEffect);
    if (node84 == nullptr) {
        node84 = new PhaseNode_PlayEffect(84, phase);
        node84->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node84->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node84->setEffectID(220741);
        node84->setChangeColor(false);
        node84->setType(PhaseNode_PlayEffect::PlayEffect_Type::WithTarget);
        node84->getVars().reserve(6);
        node84->getVars().setVariable<uint64_t>(0, 0U);
        node84->getVars().setVariable<std::string>(1, "Bip001 Head");
        node84->getVars().setVariable<float>(2, .00f);
        node84->getVars().setVariable<float>(3, .00f);
        node84->getVars().setVariable<float>(4, .00f);
        node84->getVars().setVariable<bool>(5, false);
        node84->setRotation(.00f);
        node84->setScale(.00f);
        CALL_REGISTER_SKILL_NODE(22064, 84, node84)
    }
    if (noInit == true) {
        return node84;
    }
    return node84;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(22064, 85) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_ResetCD::TRIGGER_DONE, 86, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(22064, 85) {
    auto node85 = GET_SKILL_NODE(85, PhaseNode_ResetCD);
    if (node85 == nullptr) {
        node85 = new PhaseNode_ResetCD(85, phase);
        node85->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node85->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node85->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(22064, 85, node85)
    }
    if (noInit == true) {
        return node85;
    }
    return node85;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(22064, 86) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_PlayAnimation::TRIGGER_DONE, 87, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(22064, 86) {
    auto node86 = GET_SKILL_NODE(86, PhaseNode_PlayAnimation);
    if (node86 == nullptr) {
        node86 = new PhaseNode_PlayAnimation(86, phase);
        node86->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node86->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node86->setTarget(0U);
        node86->setAnimation("Skill4S1");
        node86->setParameter("");
        node86->setValue(false);
        CALL_REGISTER_SKILL_NODE(22064, 86, node86)
    }
    if (noInit == true) {
        return node86;
    }
    return node86;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(22064, 87) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlaySound::TRIGGER_DONE, 88, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(22064, 87) {
    auto node87 = GET_SKILL_NODE(87, PhaseNode_PlaySound);
    if (node87 == nullptr) {
        node87 = new PhaseNode_PlaySound(87, phase);
        node87->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node87->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node87->setSoundID("");
        node87->setTarget(0U);
        node87->setUsePos(false);
        node87->setPosX(.00f);
        node87->setPosY(.00f);
        node87->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(22064, 87, node87)
    }
    if (noInit == true) {
        return node87;
    }
    return node87;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22064, 88) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_Delay::TRIGGER_DONE, 21, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(22064, 88) {
    auto node88 = GET_SKILL_NODE(88, PhaseNode_Delay);
    if (node88 == nullptr) {
        node88 = new PhaseNode_Delay(88, phase);
        node88->setTime(.40f);
        CALL_REGISTER_SKILL_NODE(22064, 88, node88)
    }
    if (noInit == true) {
        return node88;
    }
    return node88;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22064, 89) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_Delay::TRIGGER_DONE, 91, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(22064, 89) {
    auto node89 = GET_SKILL_NODE(89, PhaseNode_Delay);
    if (node89 == nullptr) {
        node89 = new PhaseNode_Delay(89, phase);
        node89->setTime(.30f);
        CALL_REGISTER_SKILL_NODE(22064, 89, node89)
    }
    if (noInit == true) {
        return node89;
    }
    return node89;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(22064, 90) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 18, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(22064, 90) {
    auto node90 = GET_SKILL_NODE(90, PhaseNode_SkillEndNotify);
    if (node90 == nullptr) {
        node90 = new PhaseNode_SkillEndNotify(90, phase);
        node90->setReturnType(false);
        CALL_REGISTER_SKILL_NODE(22064, 90, node90)
    }
    if (noInit == true) {
        return node90;
    }
    return node90;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(22064, 91) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_FALSE, 92, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_TRUE, 90, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
}

REGISTER_CREATE_SKILL_NODE(22064, 91) {
    auto node91 = GET_SKILL_NODE(91, PhaseNode_If);
    if (node91 == nullptr) {
        node91 = new PhaseNode_If(91, phase);
        node91->setCondition(false);
        CALL_REGISTER_SKILL_NODE(22064, 91, node91)
    }
    if (noInit == true) {
        return node91;
    }
    return node91;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(22064, 92) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 18, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(22064, 92) {
    auto node92 = GET_SKILL_NODE(92, PhaseNode_SkillEndNotify);
    if (node92 == nullptr) {
        node92 = new PhaseNode_SkillEndNotify(92, phase);
        node92->setReturnType(true);
        CALL_REGISTER_SKILL_NODE(22064, 92, node92)
    }
    if (noInit == true) {
        return node92;
    }
    return node92;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(22064, 93) {
}

REGISTER_CREATE_SKILL_NODE(22064, 93) {
    auto node93 = GET_SKILL_NODE(93, PhaseNode_RaiseEvent);
    if (node93 == nullptr) {
        node93 = new PhaseNode_RaiseEvent(93, phase);
        node93->setEvent("20064");
        node93->setTarget(0U);
        node93->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node93->setTypeParams(0, 0);
        node93->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(22064, 93, node93)
    }
    if (noInit == true) {
        return node93;
    }
    return node93;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(22064, 94) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_IsInterruptType>(PhaseNode_Detect::TRIGGER_ON, 95, PhaseNode_IsInterruptType::FUNC_DO, &PhaseNode_IsInterruptType::Do);
    pnode->regTrigger<PhaseNode_SwitchToInt>(PhaseNode_Detect::TRIGGER_ON, 98, PhaseNode_SwitchToInt::FUNC_SWITCH, &PhaseNode_SwitchToInt::Switch);
}

REGISTER_CREATE_SKILL_NODE(22064, 94) {
    auto node94 = GET_SKILL_NODE(94, PhaseNode_Detect);
    if (node94 == nullptr) {
        node94 = new PhaseNode_Detect(94, phase);
        node94->setSelf(0U);
        node94->setEvent("20064");
        node94->setType(PhaseNode_Detect::Detect_Type::Interrupt_Skill);
        node94->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(22064, 94, node94)
    }
    if (noInit == true) {
        return node94;
    }
    return node94;
}
//--------------------------------------------------------------------------------
// IsInterruptType
//
REGISTER_REGISTER_SKILL_NODE(22064, 95) {
}

REGISTER_CREATE_SKILL_NODE(22064, 95) {
    auto node95 = GET_SKILL_NODE(95, PhaseNode_IsInterruptType);
    if (node95 == nullptr) {
        node95 = new PhaseNode_IsInterruptType(95, phase);
        node95->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node95->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(22064, 95, node95)
    }
    if (noInit == true) {
        return node95;
    }
    auto node94 = GET_SKILL_NODE(94, PhaseNode_Detect);
    if (node94 != nullptr) node95->setType(node94->getVars().getVariable<int32_t>(2));
    return node95;
}
//--------------------------------------------------------------------------------
// SwitchToInt
//
REGISTER_REGISTER_SKILL_NODE(22064, 98) {
    pnode->resizeTrigger(4);
    pnode->regTrigger<PhaseNode_StopSound>(1, 82, PhaseNode_StopSound::FUNC_STOP, &PhaseNode_StopSound::Stop);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SwitchToInt::TRIGGER_DEFAULT, 79, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(22064, 98) {
    auto node98 = GET_SKILL_NODE(98, PhaseNode_SwitchToInt);
    if (node98 == nullptr) {
        node98 = new PhaseNode_SwitchToInt(98, phase);
        CALL_REGISTER_SKILL_NODE(22064, 98, node98)
    }
    if (noInit == true) {
        return node98;
    }
    auto variables = node98->getVariables();
    if (variables != nullptr) {
        node98->setSelection(variables->getVariable<int32_t>(Variable_22064_Step));
    }
    return node98;
}
//--------------------------------------------------------------------------------
// SetInt
//
REGISTER_REGISTER_SKILL_NODE(22064, 99) {
    pnode->resizeTrigger(PhaseNode_SetInt::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_SetInt::TRIGGER_DONE, 34, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(22064, 99) {
    auto node99 = GET_SKILL_NODE(99, PhaseNode_SetInt);
    if (node99 == nullptr) {
        node99 = new PhaseNode_SetInt(99, phase);
        node99->setName("Step");
        node99->setValue(1);
        CALL_REGISTER_SKILL_NODE(22064, 99, node99)
    }
    if (noInit == true) {
        return node99;
    }
    return node99;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22064, 100) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_Delay::TRIGGER_DONE, 101, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(22064, 100) {
    auto node100 = GET_SKILL_NODE(100, PhaseNode_Delay);
    if (node100 == nullptr) {
        node100 = new PhaseNode_Delay(100, phase);
        node100->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(22064, 100, node100)
    }
    if (noInit == true) {
        return node100;
    }
    return node100;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(22064, 101) {
}

REGISTER_CREATE_SKILL_NODE(22064, 101) {
    auto node101 = GET_SKILL_NODE(101, PhaseNode_PlaySound);
    if (node101 == nullptr) {
        node101 = new PhaseNode_PlaySound(101, phase);
        node101->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node101->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node101->setSoundID("SE_MON2207_Skill");
        node101->setTarget(0U);
        node101->setUsePos(false);
        node101->setPosX(.00f);
        node101->setPosY(.00f);
        node101->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(22064, 101, node101)
    }
    if (noInit == true) {
        return node101;
    }
    return node101;
}

//--------------------------------------------------------------------------------
// SkillCreator_22064
//
class SkillCreator_22064 : public SkillCreator {
public:
    SkillCreator_22064() {}
    virtual ~SkillCreator_22064() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_22064

//--------------------------------------------------------------------------------
// SkillPhase_22064
//
class SkillPhase_22064 : public SkillPhase {
public:
    SkillPhase_22064(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_22064() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(22064, 2) // StartPhase
        CASE_CREATE_SKILL_NODE(22064, 4) // TriggerUpdate
        CASE_CREATE_SKILL_NODE(22064, 14) // AddSkillBuff
        CASE_CREATE_SKILL_NODE(22064, 18) // EndPhase
        CASE_CREATE_SKILL_NODE(22064, 21) // PlayAnimation
        CASE_CREATE_SKILL_NODE(22064, 29) // For
        CASE_CREATE_SKILL_NODE(22064, 34) // Delay
        CASE_CREATE_SKILL_NODE(22064, 36) // ForContinue
        CASE_CREATE_SKILL_NODE(22064, 38) // PlayAnimation
        CASE_CREATE_SKILL_NODE(22064, 40) // Detect
        CASE_CREATE_SKILL_NODE(22064, 42) // EndPhase
        CASE_CREATE_SKILL_NODE(22064, 75) // RemoveSkillBuff
        CASE_CREATE_SKILL_NODE(22064, 77) // RemoveSkillBuff
        CASE_CREATE_SKILL_NODE(22064, 79) // EndPhase
        CASE_CREATE_SKILL_NODE(22064, 82) // StopSound
        CASE_CREATE_SKILL_NODE(22064, 84) // PlayEffect
        CASE_CREATE_SKILL_NODE(22064, 85) // ResetCD
        CASE_CREATE_SKILL_NODE(22064, 86) // PlayAnimation
        CASE_CREATE_SKILL_NODE(22064, 87) // PlaySound
        CASE_CREATE_SKILL_NODE(22064, 88) // Delay
        CASE_CREATE_SKILL_NODE(22064, 89) // Delay
        CASE_CREATE_SKILL_NODE(22064, 90) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(22064, 91) // If
        CASE_CREATE_SKILL_NODE(22064, 92) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(22064, 93) // RaiseEvent
        CASE_CREATE_SKILL_NODE(22064, 94) // Detect
        CASE_CREATE_SKILL_NODE(22064, 95) // IsInterruptType
        CASE_CREATE_SKILL_NODE(22064, 98) // SwitchToInt
        CASE_CREATE_SKILL_NODE(22064, 99) // SetInt
        CASE_CREATE_SKILL_NODE(22064, 100) // Delay
        CASE_CREATE_SKILL_NODE(22064, 101) // PlaySound
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_22064

SkillLogic* SkillCreator_22064::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //设置变量
    Variable_22064_Step = logic->getVariables().setVariable<int32_t>("Step");
    //创建阶段phase
    auto phase = new SkillPhase_22064(1, logic, 3);
    //设置phase执行器
    phase->setRunPhaseNode(1, 2);
    phase->setRunPhaseNode(2, 4);
    phase->setDetectPhaseNode(3, 40);
    phase->setDetectPhaseNode(3, 94);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_22064::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
