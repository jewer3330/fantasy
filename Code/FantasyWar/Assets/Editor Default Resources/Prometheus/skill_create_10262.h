#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

#include "skill_psnode_addskillbuff.h"
#include "skill_psnode_addskillbuffs.h"
#include "skill_psnode_areacollisionnewpene.h"
#include "skill_psnode_delay.h"
#include "skill_psnode_detect.h"
#include "skill_psnode_disable.h"
#include "skill_psnode_endphase.h"
#include "skill_psnode_filterself.h"
#include "skill_psnode_getinputrotation.h"
#include "skill_psnode_getlocation.h"
#include "skill_psnode_if.h"
#include "skill_psnode_isinterrupttype.h"
#include "skill_psnode_linechecknewpene.h"
#include "skill_psnode_playanimation.h"
#include "skill_psnode_playeffect.h"
#include "skill_psnode_playsound.h"
#include "skill_psnode_raiseevent.h"
#include "skill_psnode_resetcd.h"
#include "skill_psnode_setbool.h"
#include "skill_psnode_startphase.h"
#include "skill_psnode_startpreinput.h"
#include "skill_psnode_stopeffect.h"
#include "skill_psnode_switchtoint.h"
#include "skill_psnode_triggerupdate.h"

namespace pvp {

//变量声明
uint64_t Variable_10262_102622 = 0;
uint64_t Variable_10262_InterruptAnimat = 0;
//--------------------------------------------------------------------------------
// StartPhase
//
REGISTER_REGISTER_SKILL_NODE(10262, 4) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_StartPhase::TRIGGER_START, 8, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(10262, 4) {
    auto node4 = GET_SKILL_NODE(4, PhaseNode_StartPhase);
    if (node4 == nullptr) {
        node4 = new PhaseNode_StartPhase(4, phase);
        CALL_REGISTER_SKILL_NODE(10262, 4, node4)
    }
    if (noInit == true) {
        return node4;
    }
    return node4;
}
//--------------------------------------------------------------------------------
// TriggerUpdate
//
REGISTER_REGISTER_SKILL_NODE(10262, 6) {
}

REGISTER_CREATE_SKILL_NODE(10262, 6) {
    auto node6 = GET_SKILL_NODE(6, PhaseNode_TriggerUpdate);
    if (node6 == nullptr) {
        node6 = new PhaseNode_TriggerUpdate(6, phase);
        CALL_REGISTER_SKILL_NODE(10262, 6, node6)
    }
    if (noInit == true) {
        return node6;
    }
    return node6;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(10262, 8) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Disable>(PhaseNode_ResetCD::TRIGGER_DONE, 10, PhaseNode_Disable::FUNC_DO, &PhaseNode_Disable::Do);
}

REGISTER_CREATE_SKILL_NODE(10262, 8) {
    auto node8 = GET_SKILL_NODE(8, PhaseNode_ResetCD);
    if (node8 == nullptr) {
        node8 = new PhaseNode_ResetCD(8, phase);
        node8->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node8->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node8->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(10262, 8, node8)
    }
    if (noInit == true) {
        return node8;
    }
    return node8;
}
//--------------------------------------------------------------------------------
// Disable
//
REGISTER_REGISTER_SKILL_NODE(10262, 10) {
    pnode->resizeTrigger(PhaseNode_Disable::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_Disable::TRIGGER_DONE, 12, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_Disable::TRIGGER_DONE, 99, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_Disable::TRIGGER_DONE, 108, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10262, 10) {
    auto node10 = GET_SKILL_NODE(10, PhaseNode_Disable);
    if (node10 == nullptr) {
        node10 = new PhaseNode_Disable(10, phase);
        node10->setTarget(0U);
        node10->setMove(true);
        node10->setSkill(true);
        node10->setShoot(true);
        node10->setTime(.80f);
        node10->setRotate(true);
        CALL_REGISTER_SKILL_NODE(10262, 10, node10)
    }
    if (noInit == true) {
        return node10;
    }
    return node10;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10262, 12) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_PlayAnimation::TRIGGER_DONE, 69, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_PlayAnimation::TRIGGER_DONE, 52, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_PlayAnimation::TRIGGER_DONE, 16, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10262, 12) {
    auto node12 = GET_SKILL_NODE(12, PhaseNode_PlayAnimation);
    if (node12 == nullptr) {
        node12 = new PhaseNode_PlayAnimation(12, phase);
        node12->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node12->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node12->setTarget(0U);
        node12->setAnimation("Skill2S1");
        node12->setParameter("SkillArmBusy");
        node12->setValue(true);
        CALL_REGISTER_SKILL_NODE(10262, 12, node12)
    }
    if (noInit == true) {
        return node12;
    }
    return node12;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10262, 16) {
}

REGISTER_CREATE_SKILL_NODE(10262, 16) {
    auto node16 = GET_SKILL_NODE(16, PhaseNode_PlaySound);
    if (node16 == nullptr) {
        node16 = new PhaseNode_PlaySound(16, phase);
        node16->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node16->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node16->setSoundID("SE_Hero119_Skill_B_P1");
        node16->setTarget(0U);
        node16->setUsePos(false);
        node16->setPosX(.00f);
        node16->setPosY(.00f);
        node16->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10262, 16, node16)
    }
    if (noInit == true) {
        return node16;
    }
    return node16;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10262, 18) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuff>(PhaseNode_Delay::TRIGGER_DONE, 54, PhaseNode_AddSkillBuff::FUNC_ADD, &PhaseNode_AddSkillBuff::Add);
    pnode->regTrigger<PhaseNode_AreaCollisionNewPene>(PhaseNode_Delay::TRIGGER_DONE, 90, PhaseNode_AreaCollisionNewPene::FUNC_DO, &PhaseNode_AreaCollisionNewPene::Do);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_Delay::TRIGGER_DONE, 39, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10262, 18) {
    auto node18 = GET_SKILL_NODE(18, PhaseNode_Delay);
    if (node18 == nullptr) {
        node18 = new PhaseNode_Delay(18, phase);
        node18->setTime(.30f);
        CALL_REGISTER_SKILL_NODE(10262, 18, node18)
    }
    if (noInit == true) {
        return node18;
    }
    return node18;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10262, 39) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_Delay::TRIGGER_DONE, 41, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(10262, 39) {
    auto node39 = GET_SKILL_NODE(39, PhaseNode_Delay);
    if (node39 == nullptr) {
        node39 = new PhaseNode_Delay(39, phase);
        node39->setTime(.70f);
        CALL_REGISTER_SKILL_NODE(10262, 39, node39)
    }
    if (noInit == true) {
        return node39;
    }
    return node39;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(10262, 41) {
}

REGISTER_CREATE_SKILL_NODE(10262, 41) {
    auto node41 = GET_SKILL_NODE(41, PhaseNode_EndPhase);
    if (node41 == nullptr) {
        node41 = new PhaseNode_EndPhase(41, phase);
        node41->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node41->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10262, 41, node41)
    }
    if (noInit == true) {
        return node41;
    }
    return node41;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(10262, 52) {
}

REGISTER_CREATE_SKILL_NODE(10262, 52) {
    auto node52 = GET_SKILL_NODE(52, PhaseNode_PlayEffect);
    if (node52 == nullptr) {
        node52 = new PhaseNode_PlayEffect(52, phase);
        node52->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node52->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node52->setEffectID(102623);
        node52->setChangeColor(true);
        node52->setType(PhaseNode_PlayEffect::PlayEffect_Type::WithTarget);
        node52->getVars().reserve(5);
        node52->getVars().setVariable<uint64_t>(0, 0U);
        node52->getVars().setVariable<std::string>(1, "Effect");
        node52->getVars().setVariable<float>(2, .00f);
        node52->getVars().setVariable<float>(3, .00f);
        node52->getVars().setVariable<float>(4, .00f);
        node52->setRotation(.00f);
        node52->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(10262, 52, node52)
    }
    if (noInit == true) {
        return node52;
    }
    return node52;
}
//--------------------------------------------------------------------------------
// AddSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10262, 54) {
    pnode->resizeTrigger(PhaseNode_AddSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_AddSkillBuff::TRIGGER_DONE, 94, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10262, 54) {
    auto node54 = GET_SKILL_NODE(54, PhaseNode_AddSkillBuff);
    if (node54 == nullptr) {
        node54 = new PhaseNode_AddSkillBuff(54, phase);
        node54->setConfigID(0);
        node54->setConfigIDs({102623,4});
        node54->setTarget(0U);
        node54->setAttribute({{}});
        CALL_REGISTER_SKILL_NODE(10262, 54, node54)
    }
    if (noInit == true) {
        return node54;
    }
    return node54;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(10262, 61) {
}

REGISTER_CREATE_SKILL_NODE(10262, 61) {
    auto node61 = GET_SKILL_NODE(61, PhaseNode_EndPhase);
    if (node61 == nullptr) {
        node61 = new PhaseNode_EndPhase(61, phase);
        node61->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node61->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10262, 61, node61)
    }
    if (noInit == true) {
        return node61;
    }
    return node61;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(10262, 69) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetInputRotation>(PhaseNode_GetLocation::TRIGGER_DONE, 82, PhaseNode_GetInputRotation::FUNC_DO, &PhaseNode_GetInputRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(10262, 69) {
    auto node69 = GET_SKILL_NODE(69, PhaseNode_GetLocation);
    if (node69 == nullptr) {
        node69 = new PhaseNode_GetLocation(69, phase);
        node69->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node69->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(10262, 69, node69)
    }
    if (noInit == true) {
        return node69;
    }
    return node69;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(10262, 80) {
}

REGISTER_CREATE_SKILL_NODE(10262, 80) {
    auto node80 = GET_SKILL_NODE(80, PhaseNode_AddSkillBuffs);
    if (node80 == nullptr) {
        node80 = new PhaseNode_AddSkillBuffs(80, phase);
        node80->setConfigID({102621,4});
        node80->setAttribute({{}});
        CALL_REGISTER_SKILL_NODE(10262, 80, node80)
    }
    if (noInit == true) {
        return node80;
    }
    auto node101 = GET_SKILL_NODE(101, PhaseNode_LineCheckNewPene);
    if (node101 != nullptr) node80->setTarget(node101->getOutput());
    return node80;
}
//--------------------------------------------------------------------------------
// GetInputRotation
//
REGISTER_REGISTER_SKILL_NODE(10262, 82) {
    pnode->resizeTrigger(PhaseNode_GetInputRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_GetInputRotation::TRIGGER_DONE, 92, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(10262, 82) {
    auto node82 = GET_SKILL_NODE(82, PhaseNode_GetInputRotation);
    if (node82 == nullptr) {
        node82 = new PhaseNode_GetInputRotation(82, phase);
        node82->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        CALL_REGISTER_SKILL_NODE(10262, 82, node82)
    }
    if (noInit == true) {
        return node82;
    }
    return node82;
}
//--------------------------------------------------------------------------------
// FilterSelf
//
REGISTER_REGISTER_SKILL_NODE(10262, 84) {
    pnode->resizeTrigger(PhaseNode_FilterSelf::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_LineCheckNewPene>(PhaseNode_FilterSelf::TRIGGER_HAVESELF, 101, PhaseNode_LineCheckNewPene::FUNC_DO, &PhaseNode_LineCheckNewPene::Do);
    pnode->regTrigger<PhaseNode_LineCheckNewPene>(PhaseNode_FilterSelf::TRIGGER_NOSELF, 101, PhaseNode_LineCheckNewPene::FUNC_DO, &PhaseNode_LineCheckNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(10262, 84) {
    auto node84 = GET_SKILL_NODE(84, PhaseNode_FilterSelf);
    if (node84 == nullptr) {
        node84 = new PhaseNode_FilterSelf(84, phase);
        CALL_REGISTER_SKILL_NODE(10262, 84, node84)
    }
    if (noInit == true) {
        return node84;
    }
    auto node90 = GET_SKILL_NODE(90, PhaseNode_AreaCollisionNewPene);
    if (node90 != nullptr) node84->setTargets(node90->getColliders());
    return node84;
}
//--------------------------------------------------------------------------------
// AreaCollisionNewPene
//
REGISTER_REGISTER_SKILL_NODE(10262, 90) {
    pnode->resizeTrigger(PhaseNode_AreaCollisionNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_FilterSelf>(PhaseNode_AreaCollisionNewPene::TRIGGER_DONE, 84, PhaseNode_FilterSelf::FUNC_DO, &PhaseNode_FilterSelf::Do);
}

REGISTER_CREATE_SKILL_NODE(10262, 90) {
    auto node90 = GET_SKILL_NODE(90, PhaseNode_AreaCollisionNewPene);
    if (node90 == nullptr) {
        node90 = new PhaseNode_AreaCollisionNewPene(90, phase);
        node90->setState(PhaseNode_AreaCollisionNewPene::AreaCollisionNewPene_State::Alive);
        node90->setFaction(PhaseNode_AreaCollisionNewPene::AreaCollisionNewPene_Faction::Friend);
        node90->setOnHero(true);
        node90->setOnMinion(false);
        node90->setOnDestruct(false);
        node90->setOnShield(false);
        node90->setType(PhaseNode_AreaCollisionNewPene::AreaCollisionNewPene_Type::Rect);
        node90->setTypeParams(0, 9.50f);
        node90->setTypeParams(1, 4.00f);
        node90->setPositionZ(.00f);
        CALL_REGISTER_SKILL_NODE(10262, 90, node90)
    }
    if (noInit == true) {
        return node90;
    }
    auto node69 = GET_SKILL_NODE(69, PhaseNode_GetLocation);
    auto node82 = GET_SKILL_NODE(82, PhaseNode_GetInputRotation);
    if (node69 != nullptr) node90->setPositionX(node69->getX());
    if (node69 != nullptr) node90->setPositionY(node69->getY());
    if (node82 != nullptr) node90->setRotation(node82->getAngle());
    return node90;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(10262, 92) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlayEffect::TRIGGER_DONE, 18, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10262, 92) {
    auto node92 = GET_SKILL_NODE(92, PhaseNode_PlayEffect);
    if (node92 == nullptr) {
        node92 = new PhaseNode_PlayEffect(92, phase);
        node92->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node92->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node92->setEffectID(102625);
        node92->setChangeColor(true);
        node92->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node92->getVars().reserve(3);
        node92->getVars().setVariable<float>(0, .00f);
        node92->getVars().setVariable<float>(1, .00f);
        node92->getVars().setVariable<float>(2, .00f);
        node92->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(10262, 92, node92)
    }
    if (noInit == true) {
        return node92;
    }
    auto node69 = GET_SKILL_NODE(69, PhaseNode_GetLocation);
    auto node82 = GET_SKILL_NODE(82, PhaseNode_GetInputRotation);
    if (node69 != nullptr) node92->getVars().setVariable<float>(0, node69->getX());
    if (node69 != nullptr) node92->getVars().setVariable<float>(1, node69->getY());
    if (node82 != nullptr) node92->setRotation(node82->getAngle());
    return node92;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10262, 94) {
}

REGISTER_CREATE_SKILL_NODE(10262, 94) {
    auto node94 = GET_SKILL_NODE(94, PhaseNode_PlaySound);
    if (node94 == nullptr) {
        node94 = new PhaseNode_PlaySound(94, phase);
        node94->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node94->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node94->setSoundID("SE_Hero119_Skill_B_P2");
        node94->setTarget(0U);
        node94->setUsePos(false);
        node94->setPosX(.00f);
        node94->setPosY(.00f);
        node94->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10262, 94, node94)
    }
    if (noInit == true) {
        return node94;
    }
    return node94;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10262, 99) {
}

REGISTER_CREATE_SKILL_NODE(10262, 99) {
    auto node99 = GET_SKILL_NODE(99, PhaseNode_PlaySound);
    if (node99 == nullptr) {
        node99 = new PhaseNode_PlaySound(99, phase);
        node99->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node99->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node99->setSoundID("VO_Hero119_Skill_B");
        node99->setTarget(0U);
        node99->setUsePos(false);
        node99->setPosX(.00f);
        node99->setPosY(.00f);
        node99->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10262, 99, node99)
    }
    if (noInit == true) {
        return node99;
    }
    return node99;
}
//--------------------------------------------------------------------------------
// LineCheckNewPene
//
REGISTER_REGISTER_SKILL_NODE(10262, 101) {
    pnode->resizeTrigger(PhaseNode_LineCheckNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_LineCheckNewPene::TRIGGER_DONE, 80, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
}

REGISTER_CREATE_SKILL_NODE(10262, 101) {
    auto node101 = GET_SKILL_NODE(101, PhaseNode_LineCheckNewPene);
    if (node101 == nullptr) {
        node101 = new PhaseNode_LineCheckNewPene(101, phase);
        node101->setPeneProjectile(15);
        CALL_REGISTER_SKILL_NODE(10262, 101, node101)
    }
    if (noInit == true) {
        return node101;
    }
    auto node84 = GET_SKILL_NODE(84, PhaseNode_FilterSelf);
    auto node69 = GET_SKILL_NODE(69, PhaseNode_GetLocation);
    if (node84 != nullptr) node101->setTargets(node84->getOtherTargets());
    if (node69 != nullptr) node101->setFromX(node69->getX());
    if (node69 != nullptr) node101->setFromY(node69->getY());
    return node101;
}
//--------------------------------------------------------------------------------
// StopEffect
//
REGISTER_REGISTER_SKILL_NODE(10262, 103) {
    pnode->resizeTrigger(PhaseNode_StopEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_StopEffect::TRIGGER_DONE, 61, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(10262, 103) {
    auto node103 = GET_SKILL_NODE(103, PhaseNode_StopEffect);
    if (node103 == nullptr) {
        node103 = new PhaseNode_StopEffect(103, phase);
        node103->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node103->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node103->setEffectID(102625);
        CALL_REGISTER_SKILL_NODE(10262, 103, node103)
    }
    if (noInit == true) {
        return node103;
    }
    return node103;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10262, 105) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_IsInterruptType>(PhaseNode_Detect::TRIGGER_ON, 111, PhaseNode_IsInterruptType::FUNC_DO, &PhaseNode_IsInterruptType::Do);
}

REGISTER_CREATE_SKILL_NODE(10262, 105) {
    auto node105 = GET_SKILL_NODE(105, PhaseNode_Detect);
    if (node105 == nullptr) {
        node105 = new PhaseNode_Detect(105, phase);
        node105->setSelf(0U);
        node105->setEvent("daduan_001");
        node105->setType(PhaseNode_Detect::Detect_Type::Interrupt_Skill);
        node105->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10262, 105, node105)
    }
    if (noInit == true) {
        return node105;
    }
    return node105;
}
//--------------------------------------------------------------------------------
// SwitchToInt
//
REGISTER_REGISTER_SKILL_NODE(10262, 106) {
    pnode->resizeTrigger(4);
    pnode->regTrigger<PhaseNode_StopEffect>(1, 103, PhaseNode_StopEffect::FUNC_DO, &PhaseNode_StopEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(10262, 106) {
    auto node106 = GET_SKILL_NODE(106, PhaseNode_SwitchToInt);
    if (node106 == nullptr) {
        node106 = new PhaseNode_SwitchToInt(106, phase);
        CALL_REGISTER_SKILL_NODE(10262, 106, node106)
    }
    if (noInit == true) {
        return node106;
    }
    auto variables = node106->getVariables();
    if (variables != nullptr) {
        node106->setSelection(variables->getVariable<int32_t>(Variable_10262_102622));
    }
    return node106;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10262, 108) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_RaiseEvent::TRIGGER_DONE, 117, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10262, 108) {
    auto node108 = GET_SKILL_NODE(108, PhaseNode_RaiseEvent);
    if (node108 == nullptr) {
        node108 = new PhaseNode_RaiseEvent(108, phase);
        node108->setEvent("daduan_001");
        node108->setTarget(0U);
        node108->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node108->setTypeParams(0, 0);
        node108->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10262, 108, node108)
    }
    if (noInit == true) {
        return node108;
    }
    return node108;
}
//--------------------------------------------------------------------------------
// StartPreInput
//
REGISTER_REGISTER_SKILL_NODE(10262, 109) {
    pnode->resizeTrigger(PhaseNode_StartPreInput::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_StartPreInput::TRIGGER_DONE, 113, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10262, 109) {
    auto node109 = GET_SKILL_NODE(109, PhaseNode_StartPreInput);
    if (node109 == nullptr) {
        node109 = new PhaseNode_StartPreInput(109, phase);
        node109->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node109->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node109->setDelayTime(.00f);
        CALL_REGISTER_SKILL_NODE(10262, 109, node109)
    }
    if (noInit == true) {
        return node109;
    }
    return node109;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(10262, 110) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_If::TRIGGER_TRUE, 112, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10262, 110) {
    auto node110 = GET_SKILL_NODE(110, PhaseNode_If);
    if (node110 == nullptr) {
        node110 = new PhaseNode_If(110, phase);
        CALL_REGISTER_SKILL_NODE(10262, 110, node110)
    }
    if (noInit == true) {
        return node110;
    }
    auto variables = node110->getVariables();
    if (variables != nullptr) {
        node110->setCondition(variables->getVariable<bool>(Variable_10262_InterruptAnimat));
    }
    return node110;
}
//--------------------------------------------------------------------------------
// IsInterruptType
//
REGISTER_REGISTER_SKILL_NODE(10262, 111) {
    pnode->resizeTrigger(PhaseNode_IsInterruptType::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SwitchToInt>(PhaseNode_IsInterruptType::TRIGGER_BUFF, 106, PhaseNode_SwitchToInt::FUNC_SWITCH, &PhaseNode_SwitchToInt::Switch);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_POSCHANGE, 110, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTAIM, 110, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTFIRE, 110, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTRELOAD, 110, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_USESKILL, 110, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(10262, 111) {
    auto node111 = GET_SKILL_NODE(111, PhaseNode_IsInterruptType);
    if (node111 == nullptr) {
        node111 = new PhaseNode_IsInterruptType(111, phase);
        node111->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node111->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10262, 111, node111)
    }
    if (noInit == true) {
        return node111;
    }
    auto node105 = GET_SKILL_NODE(105, PhaseNode_Detect);
    if (node105 != nullptr) node111->setType(node105->getVars().getVariable<int32_t>(2));
    return node111;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10262, 112) {
}

REGISTER_CREATE_SKILL_NODE(10262, 112) {
    auto node112 = GET_SKILL_NODE(112, PhaseNode_PlayAnimation);
    if (node112 == nullptr) {
        node112 = new PhaseNode_PlayAnimation(112, phase);
        node112->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node112->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node112->setTarget(0U);
        node112->setAnimation("Idle");
        node112->setParameter("");
        node112->setValue(false);
        CALL_REGISTER_SKILL_NODE(10262, 112, node112)
    }
    if (noInit == true) {
        return node112;
    }
    return node112;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10262, 113) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_Delay::TRIGGER_DONE, 116, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(10262, 113) {
    auto node113 = GET_SKILL_NODE(113, PhaseNode_Delay);
    if (node113 == nullptr) {
        node113 = new PhaseNode_Delay(113, phase);
        node113->setTime(.20f);
        CALL_REGISTER_SKILL_NODE(10262, 113, node113)
    }
    if (noInit == true) {
        return node113;
    }
    return node113;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(10262, 116) {
}

REGISTER_CREATE_SKILL_NODE(10262, 116) {
    auto node116 = GET_SKILL_NODE(116, PhaseNode_SetBool);
    if (node116 == nullptr) {
        node116 = new PhaseNode_SetBool(116, phase);
        node116->setName("InterruptAnimat");
        node116->setValue(true);
        CALL_REGISTER_SKILL_NODE(10262, 116, node116)
    }
    if (noInit == true) {
        return node116;
    }
    return node116;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10262, 117) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StartPreInput>(PhaseNode_RaiseEvent::TRIGGER_DONE, 109, PhaseNode_StartPreInput::FUNC_DO, &PhaseNode_StartPreInput::Do);
}

REGISTER_CREATE_SKILL_NODE(10262, 117) {
    auto node117 = GET_SKILL_NODE(117, PhaseNode_RaiseEvent);
    if (node117 == nullptr) {
        node117 = new PhaseNode_RaiseEvent(117, phase);
        node117->setEvent("Dead_001");
        node117->setTarget(0U);
        node117->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node117->setTypeParams(0, 0);
        node117->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10262, 117, node117)
    }
    if (noInit == true) {
        return node117;
    }
    return node117;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10262, 118) {
}

REGISTER_CREATE_SKILL_NODE(10262, 118) {
    auto node118 = GET_SKILL_NODE(118, PhaseNode_Detect);
    if (node118 == nullptr) {
        node118 = new PhaseNode_Detect(118, phase);
        node118->setSelf(0U);
        node118->setEvent("Dead_001");
        node118->setType(PhaseNode_Detect::Detect_Type::Actor_Dead);
        node118->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10262, 118, node118)
    }
    if (noInit == true) {
        return node118;
    }
    return node118;
}

//--------------------------------------------------------------------------------
// SkillCreator_10262
//
class SkillCreator_10262 : public SkillCreator {
public:
    SkillCreator_10262() {}
    virtual ~SkillCreator_10262() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_10262

//--------------------------------------------------------------------------------
// SkillPhase_10262
//
class SkillPhase_10262 : public SkillPhase {
public:
    SkillPhase_10262(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_10262() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(10262, 4) // StartPhase
        CASE_CREATE_SKILL_NODE(10262, 6) // TriggerUpdate
        CASE_CREATE_SKILL_NODE(10262, 8) // ResetCD
        CASE_CREATE_SKILL_NODE(10262, 10) // Disable
        CASE_CREATE_SKILL_NODE(10262, 12) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10262, 16) // PlaySound
        CASE_CREATE_SKILL_NODE(10262, 18) // Delay
        CASE_CREATE_SKILL_NODE(10262, 39) // Delay
        CASE_CREATE_SKILL_NODE(10262, 41) // EndPhase
        CASE_CREATE_SKILL_NODE(10262, 52) // PlayEffect
        CASE_CREATE_SKILL_NODE(10262, 54) // AddSkillBuff
        CASE_CREATE_SKILL_NODE(10262, 61) // EndPhase
        CASE_CREATE_SKILL_NODE(10262, 69) // GetLocation
        CASE_CREATE_SKILL_NODE(10262, 80) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(10262, 82) // GetInputRotation
        CASE_CREATE_SKILL_NODE(10262, 84) // FilterSelf
        CASE_CREATE_SKILL_NODE(10262, 90) // AreaCollisionNewPene
        CASE_CREATE_SKILL_NODE(10262, 92) // PlayEffect
        CASE_CREATE_SKILL_NODE(10262, 94) // PlaySound
        CASE_CREATE_SKILL_NODE(10262, 99) // PlaySound
        CASE_CREATE_SKILL_NODE(10262, 101) // LineCheckNewPene
        CASE_CREATE_SKILL_NODE(10262, 103) // StopEffect
        CASE_CREATE_SKILL_NODE(10262, 105) // Detect
        CASE_CREATE_SKILL_NODE(10262, 106) // SwitchToInt
        CASE_CREATE_SKILL_NODE(10262, 108) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10262, 109) // StartPreInput
        CASE_CREATE_SKILL_NODE(10262, 110) // If
        CASE_CREATE_SKILL_NODE(10262, 111) // IsInterruptType
        CASE_CREATE_SKILL_NODE(10262, 112) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10262, 113) // Delay
        CASE_CREATE_SKILL_NODE(10262, 116) // SetBool
        CASE_CREATE_SKILL_NODE(10262, 117) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10262, 118) // Detect
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_10262

SkillLogic* SkillCreator_10262::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //设置变量
    Variable_10262_102622 = logic->getVariables().setVariable<int32_t>("102622", 1);
    Variable_10262_InterruptAnimat = logic->getVariables().setVariable<bool>("InterruptAnimat");
    //创建阶段phase
    auto phase = new SkillPhase_10262(1, logic, 3);
    //设置phase执行器
    phase->setRunPhaseNode(1, 4);
    phase->setRunPhaseNode(2, 6);
    phase->setDetectPhaseNode(3, 105);
    phase->setDetectPhaseNode(3, 118);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_10262::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
