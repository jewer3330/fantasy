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
#include "skill_psnode_if.h"
#include "skill_psnode_isinterrupttype.h"
#include "skill_psnode_playanimation.h"
#include "skill_psnode_playsound.h"
#include "skill_psnode_playuieffect.h"
#include "skill_psnode_raiseevent.h"
#include "skill_psnode_resetcd.h"
#include "skill_psnode_setbool.h"
#include "skill_psnode_setint.h"
#include "skill_psnode_startphase.h"
#include "skill_psnode_startpreinput.h"
#include "skill_psnode_switchtoint.h"
#include "skill_psnode_switchweapon.h"

namespace pvp {

//变量声明
uint64_t Variable_10133_SwitchDone = 0;
uint64_t Variable_10133_InterruptAnimat = 0;
//--------------------------------------------------------------------------------
// StartPhase
//
REGISTER_REGISTER_SKILL_NODE(10133, 1) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_StartPhase::TRIGGER_START, 3, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(10133, 1) {
    auto node1 = GET_SKILL_NODE(1, PhaseNode_StartPhase);
    if (node1 == nullptr) {
        node1 = new PhaseNode_StartPhase(1, phase);
        CALL_REGISTER_SKILL_NODE(10133, 1, node1)
    }
    if (noInit == true) {
        return node1;
    }
    return node1;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(10133, 2) {
}

REGISTER_CREATE_SKILL_NODE(10133, 2) {
    auto node2 = GET_SKILL_NODE(2, PhaseNode_EndPhase);
    if (node2 == nullptr) {
        node2 = new PhaseNode_EndPhase(2, phase);
        node2->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node2->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10133, 2, node2)
    }
    if (noInit == true) {
        return node2;
    }
    return node2;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(10133, 3) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_ResetCD::TRIGGER_DONE, 112, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10133, 3) {
    auto node3 = GET_SKILL_NODE(3, PhaseNode_ResetCD);
    if (node3 == nullptr) {
        node3 = new PhaseNode_ResetCD(3, phase);
        node3->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node3->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node3->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(10133, 3, node3)
    }
    if (noInit == true) {
        return node3;
    }
    return node3;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10133, 4) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Disable>(PhaseNode_PlayAnimation::TRIGGER_DONE, 22, PhaseNode_Disable::FUNC_DO, &PhaseNode_Disable::Do);
}

REGISTER_CREATE_SKILL_NODE(10133, 4) {
    auto node4 = GET_SKILL_NODE(4, PhaseNode_PlayAnimation);
    if (node4 == nullptr) {
        node4 = new PhaseNode_PlayAnimation(4, phase);
        node4->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node4->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node4->setTarget(0U);
        node4->setAnimation("Skill3S1");
        node4->setParameter("SkillArmBusy");
        node4->setValue(true);
        CALL_REGISTER_SKILL_NODE(10133, 4, node4)
    }
    if (noInit == true) {
        return node4;
    }
    return node4;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10133, 7) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetInt>(PhaseNode_Delay::TRIGGER_DONE, 105, PhaseNode_SetInt::FUNC_SET, &PhaseNode_SetInt::Set);
}

REGISTER_CREATE_SKILL_NODE(10133, 7) {
    auto node7 = GET_SKILL_NODE(7, PhaseNode_Delay);
    if (node7 == nullptr) {
        node7 = new PhaseNode_Delay(7, phase);
        node7->setTime(.30f);
        CALL_REGISTER_SKILL_NODE(10133, 7, node7)
    }
    if (noInit == true) {
        return node7;
    }
    return node7;
}
//--------------------------------------------------------------------------------
// SwitchWeapon
//
REGISTER_REGISTER_SKILL_NODE(10133, 9) {
    pnode->resizeTrigger(PhaseNode_SwitchWeapon::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CameraXYZShake>(PhaseNode_SwitchWeapon::TRIGGER_DONE, 80, PhaseNode_CameraXYZShake::FUNC_DO, &PhaseNode_CameraXYZShake::Do);
}

REGISTER_CREATE_SKILL_NODE(10133, 9) {
    auto node9 = GET_SKILL_NODE(9, PhaseNode_SwitchWeapon);
    if (node9 == nullptr) {
        node9 = new PhaseNode_SwitchWeapon(9, phase);
        node9->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node9->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node9->setTarget(0U);
        node9->setTime(10.00f);
        node9->setShots(0);
        node9->setWeaponID(10135);
        node9->setSaveMag(false);
        CALL_REGISTER_SKILL_NODE(10133, 9, node9)
    }
    if (noInit == true) {
        return node9;
    }
    return node9;
}
//--------------------------------------------------------------------------------
// Disable
//
REGISTER_REGISTER_SKILL_NODE(10133, 22) {
    pnode->resizeTrigger(PhaseNode_Disable::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayUIEffect>(PhaseNode_Disable::TRIGGER_DONE, 107, PhaseNode_PlayUIEffect::FUNC_DO, &PhaseNode_PlayUIEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(10133, 22) {
    auto node22 = GET_SKILL_NODE(22, PhaseNode_Disable);
    if (node22 == nullptr) {
        node22 = new PhaseNode_Disable(22, phase);
        node22->setTarget(0U);
        node22->setMove(false);
        node22->setSkill(true);
        node22->setShoot(true);
        node22->setTime(.50f);
        node22->setRotate(false);
        CALL_REGISTER_SKILL_NODE(10133, 22, node22)
    }
    if (noInit == true) {
        return node22;
    }
    return node22;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10133, 33) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_PlaySound::TRIGGER_DONE, 35, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10133, 33) {
    auto node33 = GET_SKILL_NODE(33, PhaseNode_PlaySound);
    if (node33 == nullptr) {
        node33 = new PhaseNode_PlaySound(33, phase);
        node33->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node33->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node33->setSoundID("VO_Hero105_Skill_C");
        node33->setTarget(0U);
        node33->setUsePos(false);
        node33->setPosX(.00f);
        node33->setPosY(.00f);
        node33->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10133, 33, node33)
    }
    if (noInit == true) {
        return node33;
    }
    return node33;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10133, 35) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlaySound::TRIGGER_DONE, 7, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10133, 35) {
    auto node35 = GET_SKILL_NODE(35, PhaseNode_PlaySound);
    if (node35 == nullptr) {
        node35 = new PhaseNode_PlaySound(35, phase);
        node35->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node35->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node35->setSoundID("SE_Hero105_SkillC_P1");
        node35->setTarget(0U);
        node35->setUsePos(false);
        node35->setPosX(.00f);
        node35->setPosY(.00f);
        node35->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10133, 35, node35)
    }
    if (noInit == true) {
        return node35;
    }
    return node35;
}
//--------------------------------------------------------------------------------
// CameraXYZShake
//
REGISTER_REGISTER_SKILL_NODE(10133, 80) {
    pnode->resizeTrigger(PhaseNode_CameraXYZShake::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CameraXYZShake::TRIGGER_DONE, 92, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10133, 80) {
    auto node80 = GET_SKILL_NODE(80, PhaseNode_CameraXYZShake);
    if (node80 == nullptr) {
        node80 = new PhaseNode_CameraXYZShake(80, phase);
        node80->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node80->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node80->setShakeStyle(0);
        node80->setTarget(0U);
        node80->setX(.30f);
        node80->setY(.20f);
        node80->setZ(.30f);
        node80->setDuration(.10f);
        node80->setTimes(2);
        CALL_REGISTER_SKILL_NODE(10133, 80, node80)
    }
    if (noInit == true) {
        return node80;
    }
    return node80;
}
//--------------------------------------------------------------------------------
// AddSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10133, 84) {
    pnode->resizeTrigger(PhaseNode_AddSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SwitchWeapon>(PhaseNode_AddSkillBuff::TRIGGER_DONE, 9, PhaseNode_SwitchWeapon::FUNC_DO, &PhaseNode_SwitchWeapon::Do);
}

REGISTER_CREATE_SKILL_NODE(10133, 84) {
    auto node84 = GET_SKILL_NODE(84, PhaseNode_AddSkillBuff);
    if (node84 == nullptr) {
        node84 = new PhaseNode_AddSkillBuff(84, phase);
        node84->setConfigID(101331);
        node84->setConfigIDs({});
        node84->setTarget(0U);
        node84->setAttribute({{}});
        CALL_REGISTER_SKILL_NODE(10133, 84, node84)
    }
    if (noInit == true) {
        return node84;
    }
    return node84;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10133, 92) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_Delay::TRIGGER_DONE, 2, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(10133, 92) {
    auto node92 = GET_SKILL_NODE(92, PhaseNode_Delay);
    if (node92 == nullptr) {
        node92 = new PhaseNode_Delay(92, phase);
        node92->setTime(.46f);
        CALL_REGISTER_SKILL_NODE(10133, 92, node92)
    }
    if (noInit == true) {
        return node92;
    }
    return node92;
}
//--------------------------------------------------------------------------------
// SetInt
//
REGISTER_REGISTER_SKILL_NODE(10133, 105) {
    pnode->resizeTrigger(PhaseNode_SetInt::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuff>(PhaseNode_SetInt::TRIGGER_DONE, 84, PhaseNode_AddSkillBuff::FUNC_ADD, &PhaseNode_AddSkillBuff::Add);
}

REGISTER_CREATE_SKILL_NODE(10133, 105) {
    auto node105 = GET_SKILL_NODE(105, PhaseNode_SetInt);
    if (node105 == nullptr) {
        node105 = new PhaseNode_SetInt(105, phase);
        node105->setName("SwitchDone");
        node105->setValue(2);
        CALL_REGISTER_SKILL_NODE(10133, 105, node105)
    }
    if (noInit == true) {
        return node105;
    }
    return node105;
}
//--------------------------------------------------------------------------------
// PlayUIEffect
//
REGISTER_REGISTER_SKILL_NODE(10133, 107) {
    pnode->resizeTrigger(PhaseNode_PlayUIEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_PlayUIEffect::TRIGGER_DONE, 33, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10133, 107) {
    auto node107 = GET_SKILL_NODE(107, PhaseNode_PlayUIEffect);
    if (node107 == nullptr) {
        node107 = new PhaseNode_PlayUIEffect(107, phase);
        node107->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node107->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node107->setTime(10.00f);
        node107->setType(2);
        CALL_REGISTER_SKILL_NODE(10133, 107, node107)
    }
    if (noInit == true) {
        return node107;
    }
    return node107;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10133, 109) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_IsInterruptType>(PhaseNode_Detect::TRIGGER_ON, 115, PhaseNode_IsInterruptType::FUNC_DO, &PhaseNode_IsInterruptType::Do);
}

REGISTER_CREATE_SKILL_NODE(10133, 109) {
    auto node109 = GET_SKILL_NODE(109, PhaseNode_Detect);
    if (node109 == nullptr) {
        node109 = new PhaseNode_Detect(109, phase);
        node109->setSelf(0U);
        node109->setEvent("daduan_001");
        node109->setType(PhaseNode_Detect::Detect_Type::Interrupt_Skill);
        node109->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10133, 109, node109)
    }
    if (noInit == true) {
        return node109;
    }
    return node109;
}
//--------------------------------------------------------------------------------
// SwitchToInt
//
REGISTER_REGISTER_SKILL_NODE(10133, 110) {
    pnode->resizeTrigger(4);
    pnode->regTrigger<PhaseNode_EndPhase>(1, 2, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(10133, 110) {
    auto node110 = GET_SKILL_NODE(110, PhaseNode_SwitchToInt);
    if (node110 == nullptr) {
        node110 = new PhaseNode_SwitchToInt(110, phase);
        CALL_REGISTER_SKILL_NODE(10133, 110, node110)
    }
    if (noInit == true) {
        return node110;
    }
    auto variables = node110->getVariables();
    if (variables != nullptr) {
        node110->setSelection(variables->getVariable<int32_t>(Variable_10133_SwitchDone));
    }
    return node110;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10133, 112) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_RaiseEvent::TRIGGER_DONE, 121, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10133, 112) {
    auto node112 = GET_SKILL_NODE(112, PhaseNode_RaiseEvent);
    if (node112 == nullptr) {
        node112 = new PhaseNode_RaiseEvent(112, phase);
        node112->setEvent("daduan_001");
        node112->setTarget(0U);
        node112->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node112->setTypeParams(0, 0);
        node112->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10133, 112, node112)
    }
    if (noInit == true) {
        return node112;
    }
    return node112;
}
//--------------------------------------------------------------------------------
// StartPreInput
//
REGISTER_REGISTER_SKILL_NODE(10133, 113) {
    pnode->resizeTrigger(PhaseNode_StartPreInput::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_StartPreInput::TRIGGER_DONE, 117, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_StartPreInput::TRIGGER_DONE, 4, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10133, 113) {
    auto node113 = GET_SKILL_NODE(113, PhaseNode_StartPreInput);
    if (node113 == nullptr) {
        node113 = new PhaseNode_StartPreInput(113, phase);
        node113->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node113->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node113->setDelayTime(.00f);
        CALL_REGISTER_SKILL_NODE(10133, 113, node113)
    }
    if (noInit == true) {
        return node113;
    }
    return node113;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(10133, 114) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_If::TRIGGER_TRUE, 116, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10133, 114) {
    auto node114 = GET_SKILL_NODE(114, PhaseNode_If);
    if (node114 == nullptr) {
        node114 = new PhaseNode_If(114, phase);
        CALL_REGISTER_SKILL_NODE(10133, 114, node114)
    }
    if (noInit == true) {
        return node114;
    }
    auto variables = node114->getVariables();
    if (variables != nullptr) {
        node114->setCondition(variables->getVariable<bool>(Variable_10133_InterruptAnimat));
    }
    return node114;
}
//--------------------------------------------------------------------------------
// IsInterruptType
//
REGISTER_REGISTER_SKILL_NODE(10133, 115) {
    pnode->resizeTrigger(PhaseNode_IsInterruptType::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SwitchToInt>(PhaseNode_IsInterruptType::TRIGGER_BUFF, 110, PhaseNode_SwitchToInt::FUNC_SWITCH, &PhaseNode_SwitchToInt::Switch);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_POSCHANGE, 114, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTAIM, 114, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTFIRE, 114, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTRELOAD, 114, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_USESKILL, 114, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(10133, 115) {
    auto node115 = GET_SKILL_NODE(115, PhaseNode_IsInterruptType);
    if (node115 == nullptr) {
        node115 = new PhaseNode_IsInterruptType(115, phase);
        node115->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node115->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10133, 115, node115)
    }
    if (noInit == true) {
        return node115;
    }
    auto node109 = GET_SKILL_NODE(109, PhaseNode_Detect);
    if (node109 != nullptr) node115->setType(node109->getVars().getVariable<int32_t>(2));
    return node115;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10133, 116) {
}

REGISTER_CREATE_SKILL_NODE(10133, 116) {
    auto node116 = GET_SKILL_NODE(116, PhaseNode_PlayAnimation);
    if (node116 == nullptr) {
        node116 = new PhaseNode_PlayAnimation(116, phase);
        node116->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node116->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node116->setTarget(0U);
        node116->setAnimation("Idle");
        node116->setParameter("");
        node116->setValue(false);
        CALL_REGISTER_SKILL_NODE(10133, 116, node116)
    }
    if (noInit == true) {
        return node116;
    }
    return node116;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10133, 117) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_Delay::TRIGGER_DONE, 120, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(10133, 117) {
    auto node117 = GET_SKILL_NODE(117, PhaseNode_Delay);
    if (node117 == nullptr) {
        node117 = new PhaseNode_Delay(117, phase);
        node117->setTime(.20f);
        CALL_REGISTER_SKILL_NODE(10133, 117, node117)
    }
    if (noInit == true) {
        return node117;
    }
    return node117;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(10133, 120) {
}

REGISTER_CREATE_SKILL_NODE(10133, 120) {
    auto node120 = GET_SKILL_NODE(120, PhaseNode_SetBool);
    if (node120 == nullptr) {
        node120 = new PhaseNode_SetBool(120, phase);
        node120->setName("InterruptAnimat");
        node120->setValue(true);
        CALL_REGISTER_SKILL_NODE(10133, 120, node120)
    }
    if (noInit == true) {
        return node120;
    }
    return node120;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10133, 121) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StartPreInput>(PhaseNode_RaiseEvent::TRIGGER_DONE, 113, PhaseNode_StartPreInput::FUNC_DO, &PhaseNode_StartPreInput::Do);
}

REGISTER_CREATE_SKILL_NODE(10133, 121) {
    auto node121 = GET_SKILL_NODE(121, PhaseNode_RaiseEvent);
    if (node121 == nullptr) {
        node121 = new PhaseNode_RaiseEvent(121, phase);
        node121->setEvent("Dead_001");
        node121->setTarget(0U);
        node121->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node121->setTypeParams(0, 0);
        node121->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10133, 121, node121)
    }
    if (noInit == true) {
        return node121;
    }
    return node121;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10133, 122) {
}

REGISTER_CREATE_SKILL_NODE(10133, 122) {
    auto node122 = GET_SKILL_NODE(122, PhaseNode_Detect);
    if (node122 == nullptr) {
        node122 = new PhaseNode_Detect(122, phase);
        node122->setSelf(0U);
        node122->setEvent("Dead_001");
        node122->setType(PhaseNode_Detect::Detect_Type::Actor_Dead);
        node122->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10133, 122, node122)
    }
    if (noInit == true) {
        return node122;
    }
    return node122;
}

//--------------------------------------------------------------------------------
// SkillCreator_10133
//
class SkillCreator_10133 : public SkillCreator {
public:
    SkillCreator_10133() {}
    virtual ~SkillCreator_10133() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_10133

//--------------------------------------------------------------------------------
// SkillPhase_10133
//
class SkillPhase_10133 : public SkillPhase {
public:
    SkillPhase_10133(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_10133() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(10133, 1) // StartPhase
        CASE_CREATE_SKILL_NODE(10133, 2) // EndPhase
        CASE_CREATE_SKILL_NODE(10133, 3) // ResetCD
        CASE_CREATE_SKILL_NODE(10133, 4) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10133, 7) // Delay
        CASE_CREATE_SKILL_NODE(10133, 9) // SwitchWeapon
        CASE_CREATE_SKILL_NODE(10133, 22) // Disable
        CASE_CREATE_SKILL_NODE(10133, 33) // PlaySound
        CASE_CREATE_SKILL_NODE(10133, 35) // PlaySound
        CASE_CREATE_SKILL_NODE(10133, 80) // CameraXYZShake
        CASE_CREATE_SKILL_NODE(10133, 84) // AddSkillBuff
        CASE_CREATE_SKILL_NODE(10133, 92) // Delay
        CASE_CREATE_SKILL_NODE(10133, 105) // SetInt
        CASE_CREATE_SKILL_NODE(10133, 107) // PlayUIEffect
        CASE_CREATE_SKILL_NODE(10133, 109) // Detect
        CASE_CREATE_SKILL_NODE(10133, 110) // SwitchToInt
        CASE_CREATE_SKILL_NODE(10133, 112) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10133, 113) // StartPreInput
        CASE_CREATE_SKILL_NODE(10133, 114) // If
        CASE_CREATE_SKILL_NODE(10133, 115) // IsInterruptType
        CASE_CREATE_SKILL_NODE(10133, 116) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10133, 117) // Delay
        CASE_CREATE_SKILL_NODE(10133, 120) // SetBool
        CASE_CREATE_SKILL_NODE(10133, 121) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10133, 122) // Detect
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_10133

SkillLogic* SkillCreator_10133::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //设置变量
    Variable_10133_SwitchDone = logic->getVariables().setVariable<int32_t>("SwitchDone", 1);
    Variable_10133_InterruptAnimat = logic->getVariables().setVariable<bool>("InterruptAnimat");
    //创建阶段phase
    auto phase = new SkillPhase_10133(1, logic, 2);
    //设置phase执行器
    phase->setRunPhaseNode(1, 1);
    phase->setDetectPhaseNode(2, 109);
    phase->setDetectPhaseNode(2, 122);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_10133::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
