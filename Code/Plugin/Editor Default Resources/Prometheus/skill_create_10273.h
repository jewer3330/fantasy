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
uint64_t Variable_10273_a102739 = 0;
uint64_t Variable_10273_InterruptAnimat = 0;
//--------------------------------------------------------------------------------
// StartPhase
//
REGISTER_REGISTER_SKILL_NODE(10273, 2) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Disable>(PhaseNode_StartPhase::TRIGGER_START, 533, PhaseNode_Disable::FUNC_DO, &PhaseNode_Disable::Do);
}

REGISTER_CREATE_SKILL_NODE(10273, 2) {
    auto node2 = GET_SKILL_NODE(2, PhaseNode_StartPhase);
    if (node2 == nullptr) {
        node2 = new PhaseNode_StartPhase(2, phase);
        CALL_REGISTER_SKILL_NODE(10273, 2, node2)
    }
    if (noInit == true) {
        return node2;
    }
    return node2;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10273, 15) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_Delay::TRIGGER_DONE, 635, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(10273, 15) {
    auto node15 = GET_SKILL_NODE(15, PhaseNode_Delay);
    if (node15 == nullptr) {
        node15 = new PhaseNode_Delay(15, phase);
        node15->setTime(.20f);
        CALL_REGISTER_SKILL_NODE(10273, 15, node15)
    }
    if (noInit == true) {
        return node15;
    }
    return node15;
}
//--------------------------------------------------------------------------------
// OffsetCalculate
//
REGISTER_REGISTER_SKILL_NODE(10273, 21) {
    pnode->resizeTrigger(PhaseNode_OffsetCalculate::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnProjectile>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 625, PhaseNode_SpawnProjectile::FUNC_DO, &PhaseNode_SpawnProjectile::Do);
}

REGISTER_CREATE_SKILL_NODE(10273, 21) {
    auto node21 = GET_SKILL_NODE(21, PhaseNode_OffsetCalculate);
    if (node21 == nullptr) {
        node21 = new PhaseNode_OffsetCalculate(21, phase);
        node21->setPosZ(.00f);
        node21->setOffsetX(.00f);
        node21->setOffsetY(.50f);
        node21->setOffsetZ(3.00f);
        node21->setRotOffset(.00f);
        CALL_REGISTER_SKILL_NODE(10273, 21, node21)
    }
    if (noInit == true) {
        return node21;
    }
    auto node635 = GET_SKILL_NODE(635, PhaseNode_GetLocation);
    auto node640 = GET_SKILL_NODE(640, PhaseNode_GetInputRotation);
    if (node635 != nullptr) node21->setPosX(node635->getX());
    if (node635 != nullptr) node21->setPosY(node635->getY());
    if (node640 != nullptr) node21->setRotation(node640->getAngle());
    return node21;
}
//--------------------------------------------------------------------------------
// AddSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10273, 431) {
    pnode->resizeTrigger(PhaseNode_AddSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_OffsetCalculate>(PhaseNode_AddSkillBuff::TRIGGER_DONE, 21, PhaseNode_OffsetCalculate::FUNC_DO, &PhaseNode_OffsetCalculate::Do);
}

REGISTER_CREATE_SKILL_NODE(10273, 431) {
    auto node431 = GET_SKILL_NODE(431, PhaseNode_AddSkillBuff);
    if (node431 == nullptr) {
        node431 = new PhaseNode_AddSkillBuff(431, phase);
        node431->setConfigID(102741);
        node431->setConfigIDs({});
        node431->setTarget(0U);
        node431->setAttribute({{}});
        CALL_REGISTER_SKILL_NODE(10273, 431, node431)
    }
    if (noInit == true) {
        return node431;
    }
    return node431;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10273, 477) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_PlaySound::TRIGGER_DONE, 642, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10273, 477) {
    auto node477 = GET_SKILL_NODE(477, PhaseNode_PlaySound);
    if (node477 == nullptr) {
        node477 = new PhaseNode_PlaySound(477, phase);
        node477->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node477->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node477->setSoundID("SE_Hero110_SkillC_P1");
        node477->setTarget(0U);
        node477->setUsePos(false);
        node477->setPosX(.00f);
        node477->setPosY(.00f);
        node477->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10273, 477, node477)
    }
    if (noInit == true) {
        return node477;
    }
    return node477;
}
//--------------------------------------------------------------------------------
// Disable
//
REGISTER_REGISTER_SKILL_NODE(10273, 533) {
    pnode->resizeTrigger(PhaseNode_Disable::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_Disable::TRIGGER_DONE, 645, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(10273, 533) {
    auto node533 = GET_SKILL_NODE(533, PhaseNode_Disable);
    if (node533 == nullptr) {
        node533 = new PhaseNode_Disable(533, phase);
        node533->setTarget(0U);
        node533->setMove(false);
        node533->setSkill(true);
        node533->setShoot(true);
        node533->setTime(.50f);
        node533->setRotate(true);
        CALL_REGISTER_SKILL_NODE(10273, 533, node533)
    }
    if (noInit == true) {
        return node533;
    }
    return node533;
}
//--------------------------------------------------------------------------------
// SpawnProjectile
//
REGISTER_REGISTER_SKILL_NODE(10273, 625) {
    pnode->resizeTrigger(PhaseNode_SpawnProjectile::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_SpawnProjectile::TRIGGER_DONE, 631, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10273, 625) {
    auto node625 = GET_SKILL_NODE(625, PhaseNode_SpawnProjectile);
    if (node625 == nullptr) {
        node625 = new PhaseNode_SpawnProjectile(625, phase);
        node625->setDataId(55273);
        node625->setEndPosX(.00f);
        node625->setEndPosY(.00f);
        node625->setEndPosZ(.00f);
        node625->setMaxCount(0);
        CALL_REGISTER_SKILL_NODE(10273, 625, node625)
    }
    if (noInit == true) {
        return node625;
    }
    auto node21 = GET_SKILL_NODE(21, PhaseNode_OffsetCalculate);
    if (node21 != nullptr) node625->setPosX(node21->getOutPosX());
    if (node21 != nullptr) node625->setPosY(node21->getOutPosY());
    if (node21 != nullptr) node625->setPosZ(node21->getOutPosZ());
    if (node21 != nullptr) node625->setRotation(node21->getOutRotation());
    return node625;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(10273, 629) {
}

REGISTER_CREATE_SKILL_NODE(10273, 629) {
    auto node629 = GET_SKILL_NODE(629, PhaseNode_EndPhase);
    if (node629 == nullptr) {
        node629 = new PhaseNode_EndPhase(629, phase);
        node629->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node629->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10273, 629, node629)
    }
    if (noInit == true) {
        return node629;
    }
    return node629;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10273, 631) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_Delay::TRIGGER_DONE, 629, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(10273, 631) {
    auto node631 = GET_SKILL_NODE(631, PhaseNode_Delay);
    if (node631 == nullptr) {
        node631 = new PhaseNode_Delay(631, phase);
        node631->setTime(.50f);
        CALL_REGISTER_SKILL_NODE(10273, 631, node631)
    }
    if (noInit == true) {
        return node631;
    }
    return node631;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(10273, 635) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetInputRotation>(PhaseNode_GetLocation::TRIGGER_DONE, 640, PhaseNode_GetInputRotation::FUNC_DO, &PhaseNode_GetInputRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(10273, 635) {
    auto node635 = GET_SKILL_NODE(635, PhaseNode_GetLocation);
    if (node635 == nullptr) {
        node635 = new PhaseNode_GetLocation(635, phase);
        node635->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node635->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(10273, 635, node635)
    }
    if (noInit == true) {
        return node635;
    }
    return node635;
}
//--------------------------------------------------------------------------------
// GetInputRotation
//
REGISTER_REGISTER_SKILL_NODE(10273, 640) {
    pnode->resizeTrigger(PhaseNode_GetInputRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuff>(PhaseNode_GetInputRotation::TRIGGER_DONE, 431, PhaseNode_AddSkillBuff::FUNC_ADD, &PhaseNode_AddSkillBuff::Add);
}

REGISTER_CREATE_SKILL_NODE(10273, 640) {
    auto node640 = GET_SKILL_NODE(640, PhaseNode_GetInputRotation);
    if (node640 == nullptr) {
        node640 = new PhaseNode_GetInputRotation(640, phase);
        node640->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        CALL_REGISTER_SKILL_NODE(10273, 640, node640)
    }
    if (noInit == true) {
        return node640;
    }
    return node640;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10273, 642) {
}

REGISTER_CREATE_SKILL_NODE(10273, 642) {
    auto node642 = GET_SKILL_NODE(642, PhaseNode_PlaySound);
    if (node642 == nullptr) {
        node642 = new PhaseNode_PlaySound(642, phase);
        node642->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node642->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node642->setSoundID("VO_Hero_Skill_C");
        node642->setTarget(0U);
        node642->setUsePos(false);
        node642->setPosX(.00f);
        node642->setPosY(.00f);
        node642->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10273, 642, node642)
    }
    if (noInit == true) {
        return node642;
    }
    return node642;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(10273, 645) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_ResetCD::TRIGGER_DONE, 646, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10273, 645) {
    auto node645 = GET_SKILL_NODE(645, PhaseNode_ResetCD);
    if (node645 == nullptr) {
        node645 = new PhaseNode_ResetCD(645, phase);
        node645->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node645->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node645->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(10273, 645, node645)
    }
    if (noInit == true) {
        return node645;
    }
    return node645;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10273, 646) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_PlayAnimation::TRIGGER_DONE, 648, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(10273, 646) {
    auto node646 = GET_SKILL_NODE(646, PhaseNode_PlayAnimation);
    if (node646 == nullptr) {
        node646 = new PhaseNode_PlayAnimation(646, phase);
        node646->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node646->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node646->setTarget(0U);
        node646->setAnimation("Skill3S1");
        node646->setParameter("");
        node646->setValue(false);
        CALL_REGISTER_SKILL_NODE(10273, 646, node646)
    }
    if (noInit == true) {
        return node646;
    }
    return node646;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10273, 647) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlaySound::TRIGGER_DONE, 15, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_PlaySound::TRIGGER_DONE, 477, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_PlaySound::TRIGGER_DONE, 653, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10273, 647) {
    auto node647 = GET_SKILL_NODE(647, PhaseNode_PlaySound);
    if (node647 == nullptr) {
        node647 = new PhaseNode_PlaySound(647, phase);
        node647->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node647->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node647->setSoundID("VO_Hero110_Skill_C");
        node647->setTarget(0U);
        node647->setUsePos(false);
        node647->setPosX(.00f);
        node647->setPosY(.00f);
        node647->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10273, 647, node647)
    }
    if (noInit == true) {
        return node647;
    }
    return node647;
}
//--------------------------------------------------------------------------------
// GetActorAttribute
//
REGISTER_REGISTER_SKILL_NODE(10273, 648) {
    pnode->resizeTrigger(PhaseNode_GetActorAttribute::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 647, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10273, 648) {
    auto node648 = GET_SKILL_NODE(648, PhaseNode_GetActorAttribute);
    if (node648 == nullptr) {
        node648 = new PhaseNode_GetActorAttribute(648, phase);
        node648->setTarget(0U);
        node648->setType({});
        CALL_REGISTER_SKILL_NODE(10273, 648, node648)
    }
    if (noInit == true) {
        return node648;
    }
    return node648;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10273, 650) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_IsInterruptType>(PhaseNode_Detect::TRIGGER_ON, 656, PhaseNode_IsInterruptType::FUNC_DO, &PhaseNode_IsInterruptType::Do);
}

REGISTER_CREATE_SKILL_NODE(10273, 650) {
    auto node650 = GET_SKILL_NODE(650, PhaseNode_Detect);
    if (node650 == nullptr) {
        node650 = new PhaseNode_Detect(650, phase);
        node650->setSelf(0U);
        node650->setEvent("daduan_001");
        node650->setType(PhaseNode_Detect::Detect_Type::Interrupt_Skill);
        node650->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10273, 650, node650)
    }
    if (noInit == true) {
        return node650;
    }
    return node650;
}
//--------------------------------------------------------------------------------
// SwitchToInt
//
REGISTER_REGISTER_SKILL_NODE(10273, 651) {
    pnode->resizeTrigger(4);
    pnode->regTrigger<PhaseNode_EndPhase>(1, 629, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(10273, 651) {
    auto node651 = GET_SKILL_NODE(651, PhaseNode_SwitchToInt);
    if (node651 == nullptr) {
        node651 = new PhaseNode_SwitchToInt(651, phase);
        CALL_REGISTER_SKILL_NODE(10273, 651, node651)
    }
    if (noInit == true) {
        return node651;
    }
    auto variables = node651->getVariables();
    if (variables != nullptr) {
        node651->setSelection(variables->getVariable<int32_t>(Variable_10273_a102739));
    }
    return node651;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10273, 653) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_RaiseEvent::TRIGGER_DONE, 662, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10273, 653) {
    auto node653 = GET_SKILL_NODE(653, PhaseNode_RaiseEvent);
    if (node653 == nullptr) {
        node653 = new PhaseNode_RaiseEvent(653, phase);
        node653->setEvent("daduan_001");
        node653->setTarget(0U);
        node653->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node653->setTypeParams(0, 0);
        node653->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10273, 653, node653)
    }
    if (noInit == true) {
        return node653;
    }
    return node653;
}
//--------------------------------------------------------------------------------
// StartPreInput
//
REGISTER_REGISTER_SKILL_NODE(10273, 654) {
    pnode->resizeTrigger(PhaseNode_StartPreInput::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_StartPreInput::TRIGGER_DONE, 658, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10273, 654) {
    auto node654 = GET_SKILL_NODE(654, PhaseNode_StartPreInput);
    if (node654 == nullptr) {
        node654 = new PhaseNode_StartPreInput(654, phase);
        node654->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node654->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node654->setDelayTime(.00f);
        CALL_REGISTER_SKILL_NODE(10273, 654, node654)
    }
    if (noInit == true) {
        return node654;
    }
    return node654;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(10273, 655) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_If::TRIGGER_TRUE, 657, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10273, 655) {
    auto node655 = GET_SKILL_NODE(655, PhaseNode_If);
    if (node655 == nullptr) {
        node655 = new PhaseNode_If(655, phase);
        CALL_REGISTER_SKILL_NODE(10273, 655, node655)
    }
    if (noInit == true) {
        return node655;
    }
    auto variables = node655->getVariables();
    if (variables != nullptr) {
        node655->setCondition(variables->getVariable<bool>(Variable_10273_InterruptAnimat));
    }
    return node655;
}
//--------------------------------------------------------------------------------
// IsInterruptType
//
REGISTER_REGISTER_SKILL_NODE(10273, 656) {
    pnode->resizeTrigger(PhaseNode_IsInterruptType::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SwitchToInt>(PhaseNode_IsInterruptType::TRIGGER_BUFF, 651, PhaseNode_SwitchToInt::FUNC_SWITCH, &PhaseNode_SwitchToInt::Switch);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_POSCHANGE, 655, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTAIM, 655, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTFIRE, 655, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTRELOAD, 655, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_USESKILL, 655, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(10273, 656) {
    auto node656 = GET_SKILL_NODE(656, PhaseNode_IsInterruptType);
    if (node656 == nullptr) {
        node656 = new PhaseNode_IsInterruptType(656, phase);
        node656->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node656->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10273, 656, node656)
    }
    if (noInit == true) {
        return node656;
    }
    auto node650 = GET_SKILL_NODE(650, PhaseNode_Detect);
    if (node650 != nullptr) node656->setType(node650->getVars().getVariable<int32_t>(2));
    return node656;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10273, 657) {
}

REGISTER_CREATE_SKILL_NODE(10273, 657) {
    auto node657 = GET_SKILL_NODE(657, PhaseNode_PlayAnimation);
    if (node657 == nullptr) {
        node657 = new PhaseNode_PlayAnimation(657, phase);
        node657->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node657->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node657->setTarget(0U);
        node657->setAnimation("Idle");
        node657->setParameter("");
        node657->setValue(false);
        CALL_REGISTER_SKILL_NODE(10273, 657, node657)
    }
    if (noInit == true) {
        return node657;
    }
    return node657;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10273, 658) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_Delay::TRIGGER_DONE, 661, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(10273, 658) {
    auto node658 = GET_SKILL_NODE(658, PhaseNode_Delay);
    if (node658 == nullptr) {
        node658 = new PhaseNode_Delay(658, phase);
        node658->setTime(.55f);
        CALL_REGISTER_SKILL_NODE(10273, 658, node658)
    }
    if (noInit == true) {
        return node658;
    }
    return node658;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(10273, 661) {
}

REGISTER_CREATE_SKILL_NODE(10273, 661) {
    auto node661 = GET_SKILL_NODE(661, PhaseNode_SetBool);
    if (node661 == nullptr) {
        node661 = new PhaseNode_SetBool(661, phase);
        node661->setName("InterruptAnimat");
        node661->setValue(true);
        CALL_REGISTER_SKILL_NODE(10273, 661, node661)
    }
    if (noInit == true) {
        return node661;
    }
    return node661;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10273, 662) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StartPreInput>(PhaseNode_RaiseEvent::TRIGGER_DONE, 654, PhaseNode_StartPreInput::FUNC_DO, &PhaseNode_StartPreInput::Do);
}

REGISTER_CREATE_SKILL_NODE(10273, 662) {
    auto node662 = GET_SKILL_NODE(662, PhaseNode_RaiseEvent);
    if (node662 == nullptr) {
        node662 = new PhaseNode_RaiseEvent(662, phase);
        node662->setEvent("Dead_001");
        node662->setTarget(0U);
        node662->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node662->setTypeParams(0, 0);
        node662->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10273, 662, node662)
    }
    if (noInit == true) {
        return node662;
    }
    return node662;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10273, 663) {
}

REGISTER_CREATE_SKILL_NODE(10273, 663) {
    auto node663 = GET_SKILL_NODE(663, PhaseNode_Detect);
    if (node663 == nullptr) {
        node663 = new PhaseNode_Detect(663, phase);
        node663->setSelf(0U);
        node663->setEvent("Dead_001");
        node663->setType(PhaseNode_Detect::Detect_Type::Actor_Dead);
        node663->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10273, 663, node663)
    }
    if (noInit == true) {
        return node663;
    }
    return node663;
}

//--------------------------------------------------------------------------------
// SkillCreator_10273
//
class SkillCreator_10273 : public SkillCreator {
public:
    SkillCreator_10273() {}
    virtual ~SkillCreator_10273() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_10273

//--------------------------------------------------------------------------------
// SkillPhase_10273
//
class SkillPhase_10273 : public SkillPhase {
public:
    SkillPhase_10273(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_10273() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(10273, 2) // StartPhase
        CASE_CREATE_SKILL_NODE(10273, 15) // Delay
        CASE_CREATE_SKILL_NODE(10273, 21) // OffsetCalculate
        CASE_CREATE_SKILL_NODE(10273, 431) // AddSkillBuff
        CASE_CREATE_SKILL_NODE(10273, 477) // PlaySound
        CASE_CREATE_SKILL_NODE(10273, 533) // Disable
        CASE_CREATE_SKILL_NODE(10273, 625) // SpawnProjectile
        CASE_CREATE_SKILL_NODE(10273, 629) // EndPhase
        CASE_CREATE_SKILL_NODE(10273, 631) // Delay
        CASE_CREATE_SKILL_NODE(10273, 635) // GetLocation
        CASE_CREATE_SKILL_NODE(10273, 640) // GetInputRotation
        CASE_CREATE_SKILL_NODE(10273, 642) // PlaySound
        CASE_CREATE_SKILL_NODE(10273, 645) // ResetCD
        CASE_CREATE_SKILL_NODE(10273, 646) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10273, 647) // PlaySound
        CASE_CREATE_SKILL_NODE(10273, 648) // GetActorAttribute
        CASE_CREATE_SKILL_NODE(10273, 650) // Detect
        CASE_CREATE_SKILL_NODE(10273, 651) // SwitchToInt
        CASE_CREATE_SKILL_NODE(10273, 653) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10273, 654) // StartPreInput
        CASE_CREATE_SKILL_NODE(10273, 655) // If
        CASE_CREATE_SKILL_NODE(10273, 656) // IsInterruptType
        CASE_CREATE_SKILL_NODE(10273, 657) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10273, 658) // Delay
        CASE_CREATE_SKILL_NODE(10273, 661) // SetBool
        CASE_CREATE_SKILL_NODE(10273, 662) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10273, 663) // Detect
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_10273

SkillLogic* SkillCreator_10273::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //设置变量
    Variable_10273_a102739 = logic->getVariables().setVariable<int32_t>("a102739", 1);
    Variable_10273_InterruptAnimat = logic->getVariables().setVariable<bool>("InterruptAnimat");
    //创建阶段phase
    auto phase = new SkillPhase_10273(1, logic, 2);
    //设置phase执行器
    phase->setRunPhaseNode(1, 2);
    phase->setDetectPhaseNode(2, 650);
    phase->setDetectPhaseNode(2, 663);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_10273::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
