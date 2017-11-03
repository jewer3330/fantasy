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
#include "skill_psnode_getrotation.h"
#include "skill_psnode_if.h"
#include "skill_psnode_isinterrupttype.h"
#include "skill_psnode_playanimation.h"
#include "skill_psnode_playeffect.h"
#include "skill_psnode_playsound.h"
#include "skill_psnode_raiseevent.h"
#include "skill_psnode_resetcd.h"
#include "skill_psnode_resetskill.h"
#include "skill_psnode_setbool.h"
#include "skill_psnode_setint.h"
#include "skill_psnode_spawnprojectile.h"
#include "skill_psnode_startphase.h"
#include "skill_psnode_startpreinput.h"
#include "skill_psnode_stopeffect.h"
#include "skill_psnode_stopsound.h"
#include "skill_psnode_switchtoint.h"
#include "skill_psnode_triggerupdate.h"

namespace pvp {

//变量声明
uint64_t Variable_10143_101432 = 0;
uint64_t Variable_10143_InterruptAnimat = 0;
//--------------------------------------------------------------------------------
// StartPhase
//
REGISTER_REGISTER_SKILL_NODE(10143, 3) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_StartPhase::TRIGGER_START, 575, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(10143, 3) {
    auto node3 = GET_SKILL_NODE(3, PhaseNode_StartPhase);
    if (node3 == nullptr) {
        node3 = new PhaseNode_StartPhase(3, phase);
        CALL_REGISTER_SKILL_NODE(10143, 3, node3)
    }
    if (noInit == true) {
        return node3;
    }
    return node3;
}
//--------------------------------------------------------------------------------
// TriggerUpdate
//
REGISTER_REGISTER_SKILL_NODE(10143, 39) {
}

REGISTER_CREATE_SKILL_NODE(10143, 39) {
    auto node39 = GET_SKILL_NODE(39, PhaseNode_TriggerUpdate);
    if (node39 == nullptr) {
        node39 = new PhaseNode_TriggerUpdate(39, phase);
        CALL_REGISTER_SKILL_NODE(10143, 39, node39)
    }
    if (noInit == true) {
        return node39;
    }
    return node39;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(10143, 575) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Disable>(PhaseNode_ResetCD::TRIGGER_DONE, 577, PhaseNode_Disable::FUNC_DO, &PhaseNode_Disable::Do);
}

REGISTER_CREATE_SKILL_NODE(10143, 575) {
    auto node575 = GET_SKILL_NODE(575, PhaseNode_ResetCD);
    if (node575 == nullptr) {
        node575 = new PhaseNode_ResetCD(575, phase);
        node575->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node575->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node575->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(10143, 575, node575)
    }
    if (noInit == true) {
        return node575;
    }
    return node575;
}
//--------------------------------------------------------------------------------
// Disable
//
REGISTER_REGISTER_SKILL_NODE(10143, 577) {
    pnode->resizeTrigger(PhaseNode_Disable::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_Disable::TRIGGER_DONE, 579, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_Disable::TRIGGER_DONE, 633, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_Disable::TRIGGER_DONE, 657, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10143, 577) {
    auto node577 = GET_SKILL_NODE(577, PhaseNode_Disable);
    if (node577 == nullptr) {
        node577 = new PhaseNode_Disable(577, phase);
        node577->setTarget(0U);
        node577->setMove(true);
        node577->setSkill(true);
        node577->setShoot(true);
        node577->setTime(.85f);
        node577->setRotate(true);
        CALL_REGISTER_SKILL_NODE(10143, 577, node577)
    }
    if (noInit == true) {
        return node577;
    }
    return node577;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10143, 579) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_PlayAnimation::TRIGGER_DONE, 589, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(10143, 579) {
    auto node579 = GET_SKILL_NODE(579, PhaseNode_PlayAnimation);
    if (node579 == nullptr) {
        node579 = new PhaseNode_PlayAnimation(579, phase);
        node579->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node579->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node579->setTarget(0U);
        node579->setAnimation("Skill3S1");
        node579->setParameter("");
        node579->setValue(false);
        CALL_REGISTER_SKILL_NODE(10143, 579, node579)
    }
    if (noInit == true) {
        return node579;
    }
    return node579;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10143, 585) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ResetSkill>(PhaseNode_Delay::TRIGGER_DONE, 646, PhaseNode_ResetSkill::FUNC_DO, &PhaseNode_ResetSkill::Do);
    pnode->regTrigger<PhaseNode_SetInt>(PhaseNode_Delay::TRIGGER_DONE, 640, PhaseNode_SetInt::FUNC_SET, &PhaseNode_SetInt::Set);
}

REGISTER_CREATE_SKILL_NODE(10143, 585) {
    auto node585 = GET_SKILL_NODE(585, PhaseNode_Delay);
    if (node585 == nullptr) {
        node585 = new PhaseNode_Delay(585, phase);
        node585->setTime(.60f);
        CALL_REGISTER_SKILL_NODE(10143, 585, node585)
    }
    if (noInit == true) {
        return node585;
    }
    return node585;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(10143, 587) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlayEffect::TRIGGER_DONE, 585, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_PlayEffect::TRIGGER_DONE, 629, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10143, 587) {
    auto node587 = GET_SKILL_NODE(587, PhaseNode_PlayEffect);
    if (node587 == nullptr) {
        node587 = new PhaseNode_PlayEffect(587, phase);
        node587->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node587->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node587->setEffectID(101436);
        node587->setChangeColor(true);
        node587->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node587->getVars().reserve(3);
        node587->getVars().setVariable<float>(0, .00f);
        node587->getVars().setVariable<float>(1, .00f);
        node587->getVars().setVariable<float>(2, .00f);
        node587->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(10143, 587, node587)
    }
    if (noInit == true) {
        return node587;
    }
    auto node589 = GET_SKILL_NODE(589, PhaseNode_GetLocation);
    auto node591 = GET_SKILL_NODE(591, PhaseNode_GetRotation);
    if (node589 != nullptr) node587->getVars().setVariable<float>(0, node589->getX());
    if (node589 != nullptr) node587->getVars().setVariable<float>(1, node589->getY());
    if (node591 != nullptr) node587->setRotation(node591->getAngle());
    return node587;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(10143, 589) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetRotation>(PhaseNode_GetLocation::TRIGGER_DONE, 591, PhaseNode_GetRotation::FUNC_DO, &PhaseNode_GetRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(10143, 589) {
    auto node589 = GET_SKILL_NODE(589, PhaseNode_GetLocation);
    if (node589 == nullptr) {
        node589 = new PhaseNode_GetLocation(589, phase);
        node589->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node589->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(10143, 589, node589)
    }
    if (noInit == true) {
        return node589;
    }
    return node589;
}
//--------------------------------------------------------------------------------
// GetRotation
//
REGISTER_REGISTER_SKILL_NODE(10143, 591) {
    pnode->resizeTrigger(PhaseNode_GetRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_GetRotation::TRIGGER_DONE, 587, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(10143, 591) {
    auto node591 = GET_SKILL_NODE(591, PhaseNode_GetRotation);
    if (node591 == nullptr) {
        node591 = new PhaseNode_GetRotation(591, phase);
        node591->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node591->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(10143, 591, node591)
    }
    if (noInit == true) {
        return node591;
    }
    return node591;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10143, 605) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_Delay::TRIGGER_DONE, 609, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(10143, 605) {
    auto node605 = GET_SKILL_NODE(605, PhaseNode_Delay);
    if (node605 == nullptr) {
        node605 = new PhaseNode_Delay(605, phase);
        node605->setTime(.40f);
        CALL_REGISTER_SKILL_NODE(10143, 605, node605)
    }
    if (noInit == true) {
        return node605;
    }
    return node605;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(10143, 609) {
}

REGISTER_CREATE_SKILL_NODE(10143, 609) {
    auto node609 = GET_SKILL_NODE(609, PhaseNode_EndPhase);
    if (node609 == nullptr) {
        node609 = new PhaseNode_EndPhase(609, phase);
        node609->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node609->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10143, 609, node609)
    }
    if (noInit == true) {
        return node609;
    }
    return node609;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10143, 629) {
}

REGISTER_CREATE_SKILL_NODE(10143, 629) {
    auto node629 = GET_SKILL_NODE(629, PhaseNode_PlaySound);
    if (node629 == nullptr) {
        node629 = new PhaseNode_PlaySound(629, phase);
        node629->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node629->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node629->setSoundID("SE_Hero108_SkillC_P1");
        node629->setTarget(0U);
        node629->setUsePos(false);
        node629->setPosX(.00f);
        node629->setPosY(.00f);
        node629->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10143, 629, node629)
    }
    if (noInit == true) {
        return node629;
    }
    return node629;
}
//--------------------------------------------------------------------------------
// SpawnProjectile
//
REGISTER_REGISTER_SKILL_NODE(10143, 631) {
    pnode->resizeTrigger(PhaseNode_SpawnProjectile::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_SpawnProjectile::TRIGGER_DONE, 605, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10143, 631) {
    auto node631 = GET_SKILL_NODE(631, PhaseNode_SpawnProjectile);
    if (node631 == nullptr) {
        node631 = new PhaseNode_SpawnProjectile(631, phase);
        node631->setDataId(55143);
        node631->setPosZ(.00f);
        node631->setEndPosX(.00f);
        node631->setEndPosY(.00f);
        node631->setEndPosZ(.00f);
        node631->setMaxCount(0);
        CALL_REGISTER_SKILL_NODE(10143, 631, node631)
    }
    if (noInit == true) {
        return node631;
    }
    auto node589 = GET_SKILL_NODE(589, PhaseNode_GetLocation);
    auto node591 = GET_SKILL_NODE(591, PhaseNode_GetRotation);
    if (node589 != nullptr) node631->setPosX(node589->getX());
    if (node589 != nullptr) node631->setPosY(node589->getY());
    if (node591 != nullptr) node631->setRotation(node591->getAngle());
    return node631;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10143, 633) {
}

REGISTER_CREATE_SKILL_NODE(10143, 633) {
    auto node633 = GET_SKILL_NODE(633, PhaseNode_PlaySound);
    if (node633 == nullptr) {
        node633 = new PhaseNode_PlaySound(633, phase);
        node633->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node633->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node633->setSoundID("VO_Hero108_Skill_C");
        node633->setTarget(0U);
        node633->setUsePos(false);
        node633->setPosX(.00f);
        node633->setPosY(.00f);
        node633->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10143, 633, node633)
    }
    if (noInit == true) {
        return node633;
    }
    return node633;
}
//--------------------------------------------------------------------------------
// SetInt
//
REGISTER_REGISTER_SKILL_NODE(10143, 640) {
}

REGISTER_CREATE_SKILL_NODE(10143, 640) {
    auto node640 = GET_SKILL_NODE(640, PhaseNode_SetInt);
    if (node640 == nullptr) {
        node640 = new PhaseNode_SetInt(640, phase);
        node640->setName("101432");
        node640->setValue(2);
        CALL_REGISTER_SKILL_NODE(10143, 640, node640)
    }
    if (noInit == true) {
        return node640;
    }
    return node640;
}
//--------------------------------------------------------------------------------
// AddSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10143, 642) {
    pnode->resizeTrigger(PhaseNode_AddSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnProjectile>(PhaseNode_AddSkillBuff::TRIGGER_DONE, 631, PhaseNode_SpawnProjectile::FUNC_DO, &PhaseNode_SpawnProjectile::Do);
}

REGISTER_CREATE_SKILL_NODE(10143, 642) {
    auto node642 = GET_SKILL_NODE(642, PhaseNode_AddSkillBuff);
    if (node642 == nullptr) {
        node642 = new PhaseNode_AddSkillBuff(642, phase);
        node642->setConfigID(101451);
        node642->setConfigIDs({});
        node642->setTarget(0U);
        node642->setAttribute({{}});
        CALL_REGISTER_SKILL_NODE(10143, 642, node642)
    }
    if (noInit == true) {
        return node642;
    }
    return node642;
}
//--------------------------------------------------------------------------------
// ResetSkill
//
REGISTER_REGISTER_SKILL_NODE(10143, 646) {
    pnode->resizeTrigger(PhaseNode_ResetSkill::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ResetSkill>(PhaseNode_ResetSkill::TRIGGER_DONE, 648, PhaseNode_ResetSkill::FUNC_DO, &PhaseNode_ResetSkill::Do);
}

REGISTER_CREATE_SKILL_NODE(10143, 646) {
    auto node646 = GET_SKILL_NODE(646, PhaseNode_ResetSkill);
    if (node646 == nullptr) {
        node646 = new PhaseNode_ResetSkill(646, phase);
        node646->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node646->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node646->setSkillID({10141});
        node646->setTime(15.00f);
        CALL_REGISTER_SKILL_NODE(10143, 646, node646)
    }
    if (noInit == true) {
        return node646;
    }
    return node646;
}
//--------------------------------------------------------------------------------
// ResetSkill
//
REGISTER_REGISTER_SKILL_NODE(10143, 648) {
    pnode->resizeTrigger(PhaseNode_ResetSkill::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuff>(PhaseNode_ResetSkill::TRIGGER_DONE, 642, PhaseNode_AddSkillBuff::FUNC_ADD, &PhaseNode_AddSkillBuff::Add);
}

REGISTER_CREATE_SKILL_NODE(10143, 648) {
    auto node648 = GET_SKILL_NODE(648, PhaseNode_ResetSkill);
    if (node648 == nullptr) {
        node648 = new PhaseNode_ResetSkill(648, phase);
        node648->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node648->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node648->setSkillID({10142});
        node648->setTime(15.00f);
        CALL_REGISTER_SKILL_NODE(10143, 648, node648)
    }
    if (noInit == true) {
        return node648;
    }
    return node648;
}
//--------------------------------------------------------------------------------
// StopEffect
//
REGISTER_REGISTER_SKILL_NODE(10143, 650) {
    pnode->resizeTrigger(PhaseNode_StopEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_StopEffect::TRIGGER_DONE, 609, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(10143, 650) {
    auto node650 = GET_SKILL_NODE(650, PhaseNode_StopEffect);
    if (node650 == nullptr) {
        node650 = new PhaseNode_StopEffect(650, phase);
        node650->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node650->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node650->setEffectID(101436);
        CALL_REGISTER_SKILL_NODE(10143, 650, node650)
    }
    if (noInit == true) {
        return node650;
    }
    return node650;
}
//--------------------------------------------------------------------------------
// StopSound
//
REGISTER_REGISTER_SKILL_NODE(10143, 652) {
    pnode->resizeTrigger(PhaseNode_StopSound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StopEffect>(PhaseNode_StopSound::TRIGGER_DONE, 650, PhaseNode_StopEffect::FUNC_DO, &PhaseNode_StopEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(10143, 652) {
    auto node652 = GET_SKILL_NODE(652, PhaseNode_StopSound);
    if (node652 == nullptr) {
        node652 = new PhaseNode_StopSound(652, phase);
        node652->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node652->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node652->setSoundID("SE_Hero108_SkillC_P1");
        CALL_REGISTER_SKILL_NODE(10143, 652, node652)
    }
    if (noInit == true) {
        return node652;
    }
    return node652;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10143, 654) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_IsInterruptType>(PhaseNode_Detect::TRIGGER_ON, 660, PhaseNode_IsInterruptType::FUNC_DO, &PhaseNode_IsInterruptType::Do);
}

REGISTER_CREATE_SKILL_NODE(10143, 654) {
    auto node654 = GET_SKILL_NODE(654, PhaseNode_Detect);
    if (node654 == nullptr) {
        node654 = new PhaseNode_Detect(654, phase);
        node654->setSelf(0U);
        node654->setEvent("daduan_001");
        node654->setType(PhaseNode_Detect::Detect_Type::Interrupt_Skill);
        node654->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10143, 654, node654)
    }
    if (noInit == true) {
        return node654;
    }
    return node654;
}
//--------------------------------------------------------------------------------
// SwitchToInt
//
REGISTER_REGISTER_SKILL_NODE(10143, 655) {
    pnode->resizeTrigger(4);
    pnode->regTrigger<PhaseNode_StopSound>(1, 652, PhaseNode_StopSound::FUNC_STOP, &PhaseNode_StopSound::Stop);
}

REGISTER_CREATE_SKILL_NODE(10143, 655) {
    auto node655 = GET_SKILL_NODE(655, PhaseNode_SwitchToInt);
    if (node655 == nullptr) {
        node655 = new PhaseNode_SwitchToInt(655, phase);
        CALL_REGISTER_SKILL_NODE(10143, 655, node655)
    }
    if (noInit == true) {
        return node655;
    }
    auto variables = node655->getVariables();
    if (variables != nullptr) {
        node655->setSelection(variables->getVariable<int32_t>(Variable_10143_101432));
    }
    return node655;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10143, 657) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_RaiseEvent::TRIGGER_DONE, 666, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10143, 657) {
    auto node657 = GET_SKILL_NODE(657, PhaseNode_RaiseEvent);
    if (node657 == nullptr) {
        node657 = new PhaseNode_RaiseEvent(657, phase);
        node657->setEvent("daduan_001");
        node657->setTarget(0U);
        node657->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node657->setTypeParams(0, 0);
        node657->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10143, 657, node657)
    }
    if (noInit == true) {
        return node657;
    }
    return node657;
}
//--------------------------------------------------------------------------------
// StartPreInput
//
REGISTER_REGISTER_SKILL_NODE(10143, 658) {
    pnode->resizeTrigger(PhaseNode_StartPreInput::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_StartPreInput::TRIGGER_DONE, 662, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10143, 658) {
    auto node658 = GET_SKILL_NODE(658, PhaseNode_StartPreInput);
    if (node658 == nullptr) {
        node658 = new PhaseNode_StartPreInput(658, phase);
        node658->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node658->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node658->setDelayTime(.00f);
        CALL_REGISTER_SKILL_NODE(10143, 658, node658)
    }
    if (noInit == true) {
        return node658;
    }
    return node658;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(10143, 659) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_If::TRIGGER_TRUE, 661, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10143, 659) {
    auto node659 = GET_SKILL_NODE(659, PhaseNode_If);
    if (node659 == nullptr) {
        node659 = new PhaseNode_If(659, phase);
        CALL_REGISTER_SKILL_NODE(10143, 659, node659)
    }
    if (noInit == true) {
        return node659;
    }
    auto variables = node659->getVariables();
    if (variables != nullptr) {
        node659->setCondition(variables->getVariable<bool>(Variable_10143_InterruptAnimat));
    }
    return node659;
}
//--------------------------------------------------------------------------------
// IsInterruptType
//
REGISTER_REGISTER_SKILL_NODE(10143, 660) {
    pnode->resizeTrigger(PhaseNode_IsInterruptType::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SwitchToInt>(PhaseNode_IsInterruptType::TRIGGER_BUFF, 655, PhaseNode_SwitchToInt::FUNC_SWITCH, &PhaseNode_SwitchToInt::Switch);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_POSCHANGE, 659, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTAIM, 659, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTFIRE, 659, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTRELOAD, 659, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_USESKILL, 659, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(10143, 660) {
    auto node660 = GET_SKILL_NODE(660, PhaseNode_IsInterruptType);
    if (node660 == nullptr) {
        node660 = new PhaseNode_IsInterruptType(660, phase);
        node660->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node660->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10143, 660, node660)
    }
    if (noInit == true) {
        return node660;
    }
    auto node654 = GET_SKILL_NODE(654, PhaseNode_Detect);
    if (node654 != nullptr) node660->setType(node654->getVars().getVariable<int32_t>(2));
    return node660;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10143, 661) {
}

REGISTER_CREATE_SKILL_NODE(10143, 661) {
    auto node661 = GET_SKILL_NODE(661, PhaseNode_PlayAnimation);
    if (node661 == nullptr) {
        node661 = new PhaseNode_PlayAnimation(661, phase);
        node661->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node661->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node661->setTarget(0U);
        node661->setAnimation("Idle");
        node661->setParameter("");
        node661->setValue(false);
        CALL_REGISTER_SKILL_NODE(10143, 661, node661)
    }
    if (noInit == true) {
        return node661;
    }
    return node661;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10143, 662) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_Delay::TRIGGER_DONE, 665, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(10143, 662) {
    auto node662 = GET_SKILL_NODE(662, PhaseNode_Delay);
    if (node662 == nullptr) {
        node662 = new PhaseNode_Delay(662, phase);
        node662->setTime(.20f);
        CALL_REGISTER_SKILL_NODE(10143, 662, node662)
    }
    if (noInit == true) {
        return node662;
    }
    return node662;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(10143, 665) {
}

REGISTER_CREATE_SKILL_NODE(10143, 665) {
    auto node665 = GET_SKILL_NODE(665, PhaseNode_SetBool);
    if (node665 == nullptr) {
        node665 = new PhaseNode_SetBool(665, phase);
        node665->setName("InterruptAnimat");
        node665->setValue(true);
        CALL_REGISTER_SKILL_NODE(10143, 665, node665)
    }
    if (noInit == true) {
        return node665;
    }
    return node665;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10143, 666) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StartPreInput>(PhaseNode_RaiseEvent::TRIGGER_DONE, 658, PhaseNode_StartPreInput::FUNC_DO, &PhaseNode_StartPreInput::Do);
}

REGISTER_CREATE_SKILL_NODE(10143, 666) {
    auto node666 = GET_SKILL_NODE(666, PhaseNode_RaiseEvent);
    if (node666 == nullptr) {
        node666 = new PhaseNode_RaiseEvent(666, phase);
        node666->setEvent("Dead_001");
        node666->setTarget(0U);
        node666->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node666->setTypeParams(0, 0);
        node666->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10143, 666, node666)
    }
    if (noInit == true) {
        return node666;
    }
    return node666;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10143, 667) {
}

REGISTER_CREATE_SKILL_NODE(10143, 667) {
    auto node667 = GET_SKILL_NODE(667, PhaseNode_Detect);
    if (node667 == nullptr) {
        node667 = new PhaseNode_Detect(667, phase);
        node667->setSelf(0U);
        node667->setEvent("Dead_001");
        node667->setType(PhaseNode_Detect::Detect_Type::Actor_Dead);
        node667->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10143, 667, node667)
    }
    if (noInit == true) {
        return node667;
    }
    return node667;
}

//--------------------------------------------------------------------------------
// SkillCreator_10143
//
class SkillCreator_10143 : public SkillCreator {
public:
    SkillCreator_10143() {}
    virtual ~SkillCreator_10143() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_10143

//--------------------------------------------------------------------------------
// SkillPhase_10143
//
class SkillPhase_10143 : public SkillPhase {
public:
    SkillPhase_10143(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_10143() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(10143, 3) // StartPhase
        CASE_CREATE_SKILL_NODE(10143, 39) // TriggerUpdate
        CASE_CREATE_SKILL_NODE(10143, 575) // ResetCD
        CASE_CREATE_SKILL_NODE(10143, 577) // Disable
        CASE_CREATE_SKILL_NODE(10143, 579) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10143, 585) // Delay
        CASE_CREATE_SKILL_NODE(10143, 587) // PlayEffect
        CASE_CREATE_SKILL_NODE(10143, 589) // GetLocation
        CASE_CREATE_SKILL_NODE(10143, 591) // GetRotation
        CASE_CREATE_SKILL_NODE(10143, 605) // Delay
        CASE_CREATE_SKILL_NODE(10143, 609) // EndPhase
        CASE_CREATE_SKILL_NODE(10143, 629) // PlaySound
        CASE_CREATE_SKILL_NODE(10143, 631) // SpawnProjectile
        CASE_CREATE_SKILL_NODE(10143, 633) // PlaySound
        CASE_CREATE_SKILL_NODE(10143, 640) // SetInt
        CASE_CREATE_SKILL_NODE(10143, 642) // AddSkillBuff
        CASE_CREATE_SKILL_NODE(10143, 646) // ResetSkill
        CASE_CREATE_SKILL_NODE(10143, 648) // ResetSkill
        CASE_CREATE_SKILL_NODE(10143, 650) // StopEffect
        CASE_CREATE_SKILL_NODE(10143, 652) // StopSound
        CASE_CREATE_SKILL_NODE(10143, 654) // Detect
        CASE_CREATE_SKILL_NODE(10143, 655) // SwitchToInt
        CASE_CREATE_SKILL_NODE(10143, 657) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10143, 658) // StartPreInput
        CASE_CREATE_SKILL_NODE(10143, 659) // If
        CASE_CREATE_SKILL_NODE(10143, 660) // IsInterruptType
        CASE_CREATE_SKILL_NODE(10143, 661) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10143, 662) // Delay
        CASE_CREATE_SKILL_NODE(10143, 665) // SetBool
        CASE_CREATE_SKILL_NODE(10143, 666) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10143, 667) // Detect
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_10143

SkillLogic* SkillCreator_10143::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //设置变量
    Variable_10143_101432 = logic->getVariables().setVariable<int32_t>("101432", 1);
    Variable_10143_InterruptAnimat = logic->getVariables().setVariable<bool>("InterruptAnimat");
    //创建阶段phase
    auto phase = new SkillPhase_10143(1, logic, 3);
    //设置phase执行器
    phase->setRunPhaseNode(1, 3);
    phase->setRunPhaseNode(2, 39);
    phase->setDetectPhaseNode(3, 654);
    phase->setDetectPhaseNode(3, 667);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_10143::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
