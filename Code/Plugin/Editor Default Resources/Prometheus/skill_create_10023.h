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
#include "skill_psnode_getactorattribute.h"
#include "skill_psnode_getlocation.h"
#include "skill_psnode_if.h"
#include "skill_psnode_isinterrupttype.h"
#include "skill_psnode_playanimation.h"
#include "skill_psnode_playeffect.h"
#include "skill_psnode_playsound.h"
#include "skill_psnode_raiseevent.h"
#include "skill_psnode_resetcd.h"
#include "skill_psnode_setbool.h"
#include "skill_psnode_startphase.h"
#include "skill_psnode_startpreinput.h"
#include "skill_psnode_switchtoint.h"

namespace pvp {

//变量声明
uint64_t Variable_10023_a100232 = 0;
uint64_t Variable_10023_InterruptAnimat = 0;
//--------------------------------------------------------------------------------
// StartPhase
//
REGISTER_REGISTER_SKILL_NODE(10023, 2) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_StartPhase::TRIGGER_START, 119, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(10023, 2) {
    auto node2 = GET_SKILL_NODE(2, PhaseNode_StartPhase);
    if (node2 == nullptr) {
        node2 = new PhaseNode_StartPhase(2, phase);
        CALL_REGISTER_SKILL_NODE(10023, 2, node2)
    }
    if (noInit == true) {
        return node2;
    }
    return node2;
}
//--------------------------------------------------------------------------------
// Disable
//
REGISTER_REGISTER_SKILL_NODE(10023, 10) {
    pnode->resizeTrigger(PhaseNode_Disable::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_Disable::TRIGGER_DONE, 14, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10023, 10) {
    auto node10 = GET_SKILL_NODE(10, PhaseNode_Disable);
    if (node10 == nullptr) {
        node10 = new PhaseNode_Disable(10, phase);
        node10->setTarget(0U);
        node10->setMove(true);
        node10->setSkill(true);
        node10->setShoot(true);
        node10->setTime(.85f);
        node10->setRotate(true);
        CALL_REGISTER_SKILL_NODE(10023, 10, node10)
    }
    if (noInit == true) {
        return node10;
    }
    return node10;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10023, 14) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AreaCollisionNewPene>(PhaseNode_Delay::TRIGGER_DONE, 115, PhaseNode_AreaCollisionNewPene::FUNC_DO, &PhaseNode_AreaCollisionNewPene::Do);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_Delay::TRIGGER_DONE, 38, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_Delay::TRIGGER_DONE, 96, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(10023, 14) {
    auto node14 = GET_SKILL_NODE(14, PhaseNode_Delay);
    if (node14 == nullptr) {
        node14 = new PhaseNode_Delay(14, phase);
        node14->setTime(.10f);
        CALL_REGISTER_SKILL_NODE(10023, 14, node14)
    }
    if (noInit == true) {
        return node14;
    }
    return node14;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10023, 38) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_Delay::TRIGGER_DONE, 40, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(10023, 38) {
    auto node38 = GET_SKILL_NODE(38, PhaseNode_Delay);
    if (node38 == nullptr) {
        node38 = new PhaseNode_Delay(38, phase);
        node38->setTime(.96f);
        CALL_REGISTER_SKILL_NODE(10023, 38, node38)
    }
    if (noInit == true) {
        return node38;
    }
    return node38;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(10023, 40) {
}

REGISTER_CREATE_SKILL_NODE(10023, 40) {
    auto node40 = GET_SKILL_NODE(40, PhaseNode_EndPhase);
    if (node40 == nullptr) {
        node40 = new PhaseNode_EndPhase(40, phase);
        node40->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node40->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10023, 40, node40)
    }
    if (noInit == true) {
        return node40;
    }
    return node40;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10023, 63) {
}

REGISTER_CREATE_SKILL_NODE(10023, 63) {
    auto node63 = GET_SKILL_NODE(63, PhaseNode_PlaySound);
    if (node63 == nullptr) {
        node63 = new PhaseNode_PlaySound(63, phase);
        node63->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node63->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node63->setSoundID("SE_Hero112_SkillC_P1");
        node63->setTarget(0U);
        node63->setUsePos(false);
        node63->setPosX(.00f);
        node63->setPosY(.00f);
        node63->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10023, 63, node63)
    }
    if (noInit == true) {
        return node63;
    }
    return node63;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(10023, 93) {
}

REGISTER_CREATE_SKILL_NODE(10023, 93) {
    auto node93 = GET_SKILL_NODE(93, PhaseNode_AddSkillBuffs);
    if (node93 == nullptr) {
        node93 = new PhaseNode_AddSkillBuffs(93, phase);
        node93->setConfigID({100231});
        node93->setAttribute({{}});
        CALL_REGISTER_SKILL_NODE(10023, 93, node93)
    }
    if (noInit == true) {
        return node93;
    }
    auto node115 = GET_SKILL_NODE(115, PhaseNode_AreaCollisionNewPene);
    if (node115 != nullptr) node93->setTarget(node115->getColliders());
    return node93;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(10023, 96) {
}

REGISTER_CREATE_SKILL_NODE(10023, 96) {
    auto node96 = GET_SKILL_NODE(96, PhaseNode_PlayEffect);
    if (node96 == nullptr) {
        node96 = new PhaseNode_PlayEffect(96, phase);
        node96->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node96->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node96->setEffectID(100231);
        node96->setChangeColor(false);
        node96->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node96->getVars().reserve(3);
        node96->getVars().setVariable<float>(0, .00f);
        node96->getVars().setVariable<float>(1, .00f);
        node96->getVars().setVariable<float>(2, .00f);
        node96->setRotation(.00f);
        node96->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(10023, 96, node96)
    }
    if (noInit == true) {
        return node96;
    }
    auto node111 = GET_SKILL_NODE(111, PhaseNode_GetLocation);
    if (node111 != nullptr) node96->getVars().setVariable<float>(0, node111->getX());
    if (node111 != nullptr) node96->getVars().setVariable<float>(1, node111->getY());
    return node96;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(10023, 111) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuff>(PhaseNode_GetLocation::TRIGGER_DONE, 117, PhaseNode_AddSkillBuff::FUNC_ADD, &PhaseNode_AddSkillBuff::Add);
    pnode->regTrigger<PhaseNode_Disable>(PhaseNode_GetLocation::TRIGGER_DONE, 10, PhaseNode_Disable::FUNC_DO, &PhaseNode_Disable::Do);
}

REGISTER_CREATE_SKILL_NODE(10023, 111) {
    auto node111 = GET_SKILL_NODE(111, PhaseNode_GetLocation);
    if (node111 == nullptr) {
        node111 = new PhaseNode_GetLocation(111, phase);
        node111->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node111->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(10023, 111, node111)
    }
    if (noInit == true) {
        return node111;
    }
    return node111;
}
//--------------------------------------------------------------------------------
// AreaCollisionNewPene
//
REGISTER_REGISTER_SKILL_NODE(10023, 115) {
    pnode->resizeTrigger(PhaseNode_AreaCollisionNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_AreaCollisionNewPene::TRIGGER_DONE, 93, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
}

REGISTER_CREATE_SKILL_NODE(10023, 115) {
    auto node115 = GET_SKILL_NODE(115, PhaseNode_AreaCollisionNewPene);
    if (node115 == nullptr) {
        node115 = new PhaseNode_AreaCollisionNewPene(115, phase);
        node115->setState(PhaseNode_AreaCollisionNewPene::AreaCollisionNewPene_State::Dead);
        node115->setFaction(PhaseNode_AreaCollisionNewPene::AreaCollisionNewPene_Faction::Friend);
        node115->setOnHero(true);
        node115->setOnMinion(false);
        node115->setOnDestruct(false);
        node115->setOnShield(false);
        node115->setType(PhaseNode_AreaCollisionNewPene::AreaCollisionNewPene_Type::Circle);
        node115->setTypeParams(0, 18.00f);
        node115->setPositionZ(.00f);
        node115->setRotation(.00f);
        CALL_REGISTER_SKILL_NODE(10023, 115, node115)
    }
    if (noInit == true) {
        return node115;
    }
    auto node111 = GET_SKILL_NODE(111, PhaseNode_GetLocation);
    if (node111 != nullptr) node115->setPositionX(node111->getX());
    if (node111 != nullptr) node115->setPositionY(node111->getY());
    return node115;
}
//--------------------------------------------------------------------------------
// AddSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10023, 117) {
}

REGISTER_CREATE_SKILL_NODE(10023, 117) {
    auto node117 = GET_SKILL_NODE(117, PhaseNode_AddSkillBuff);
    if (node117 == nullptr) {
        node117 = new PhaseNode_AddSkillBuff(117, phase);
        node117->setConfigID(100233);
        node117->setConfigIDs({});
        node117->setTarget(0U);
        node117->setAttribute({{}});
        CALL_REGISTER_SKILL_NODE(10023, 117, node117)
    }
    if (noInit == true) {
        return node117;
    }
    return node117;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(10023, 119) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_ResetCD::TRIGGER_DONE, 120, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10023, 119) {
    auto node119 = GET_SKILL_NODE(119, PhaseNode_ResetCD);
    if (node119 == nullptr) {
        node119 = new PhaseNode_ResetCD(119, phase);
        node119->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node119->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node119->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(10023, 119, node119)
    }
    if (noInit == true) {
        return node119;
    }
    return node119;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10023, 120) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_PlayAnimation::TRIGGER_DONE, 122, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(10023, 120) {
    auto node120 = GET_SKILL_NODE(120, PhaseNode_PlayAnimation);
    if (node120 == nullptr) {
        node120 = new PhaseNode_PlayAnimation(120, phase);
        node120->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node120->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node120->setTarget(0U);
        node120->setAnimation("Skill3S1");
        node120->setParameter("");
        node120->setValue(false);
        CALL_REGISTER_SKILL_NODE(10023, 120, node120)
    }
    if (noInit == true) {
        return node120;
    }
    return node120;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10023, 121) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_PlaySound::TRIGGER_DONE, 111, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_PlaySound::TRIGGER_DONE, 127, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10023, 121) {
    auto node121 = GET_SKILL_NODE(121, PhaseNode_PlaySound);
    if (node121 == nullptr) {
        node121 = new PhaseNode_PlaySound(121, phase);
        node121->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node121->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node121->setSoundID("VO_Hero112_Skill_C");
        node121->setTarget(0U);
        node121->setUsePos(false);
        node121->setPosX(.00f);
        node121->setPosY(.00f);
        node121->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10023, 121, node121)
    }
    if (noInit == true) {
        return node121;
    }
    return node121;
}
//--------------------------------------------------------------------------------
// GetActorAttribute
//
REGISTER_REGISTER_SKILL_NODE(10023, 122) {
    pnode->resizeTrigger(PhaseNode_GetActorAttribute::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 121, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10023, 122) {
    auto node122 = GET_SKILL_NODE(122, PhaseNode_GetActorAttribute);
    if (node122 == nullptr) {
        node122 = new PhaseNode_GetActorAttribute(122, phase);
        node122->setTarget(0U);
        node122->setType({});
        CALL_REGISTER_SKILL_NODE(10023, 122, node122)
    }
    if (noInit == true) {
        return node122;
    }
    return node122;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10023, 124) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_IsInterruptType>(PhaseNode_Detect::TRIGGER_ON, 130, PhaseNode_IsInterruptType::FUNC_DO, &PhaseNode_IsInterruptType::Do);
}

REGISTER_CREATE_SKILL_NODE(10023, 124) {
    auto node124 = GET_SKILL_NODE(124, PhaseNode_Detect);
    if (node124 == nullptr) {
        node124 = new PhaseNode_Detect(124, phase);
        node124->setSelf(0U);
        node124->setEvent("daduan_001");
        node124->setType(PhaseNode_Detect::Detect_Type::Interrupt_Skill);
        node124->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10023, 124, node124)
    }
    if (noInit == true) {
        return node124;
    }
    return node124;
}
//--------------------------------------------------------------------------------
// SwitchToInt
//
REGISTER_REGISTER_SKILL_NODE(10023, 125) {
}

REGISTER_CREATE_SKILL_NODE(10023, 125) {
    auto node125 = GET_SKILL_NODE(125, PhaseNode_SwitchToInt);
    if (node125 == nullptr) {
        node125 = new PhaseNode_SwitchToInt(125, phase);
        CALL_REGISTER_SKILL_NODE(10023, 125, node125)
    }
    if (noInit == true) {
        return node125;
    }
    auto variables = node125->getVariables();
    if (variables != nullptr) {
        node125->setSelection(variables->getVariable<int32_t>(Variable_10023_a100232));
    }
    return node125;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10023, 127) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_RaiseEvent::TRIGGER_DONE, 136, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10023, 127) {
    auto node127 = GET_SKILL_NODE(127, PhaseNode_RaiseEvent);
    if (node127 == nullptr) {
        node127 = new PhaseNode_RaiseEvent(127, phase);
        node127->setEvent("daduan_001");
        node127->setTarget(0U);
        node127->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node127->setTypeParams(0, 0);
        node127->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10023, 127, node127)
    }
    if (noInit == true) {
        return node127;
    }
    return node127;
}
//--------------------------------------------------------------------------------
// StartPreInput
//
REGISTER_REGISTER_SKILL_NODE(10023, 128) {
    pnode->resizeTrigger(PhaseNode_StartPreInput::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_StartPreInput::TRIGGER_DONE, 132, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_StartPreInput::TRIGGER_DONE, 63, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10023, 128) {
    auto node128 = GET_SKILL_NODE(128, PhaseNode_StartPreInput);
    if (node128 == nullptr) {
        node128 = new PhaseNode_StartPreInput(128, phase);
        node128->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node128->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node128->setDelayTime(.00f);
        CALL_REGISTER_SKILL_NODE(10023, 128, node128)
    }
    if (noInit == true) {
        return node128;
    }
    return node128;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(10023, 129) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_If::TRIGGER_TRUE, 131, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10023, 129) {
    auto node129 = GET_SKILL_NODE(129, PhaseNode_If);
    if (node129 == nullptr) {
        node129 = new PhaseNode_If(129, phase);
        CALL_REGISTER_SKILL_NODE(10023, 129, node129)
    }
    if (noInit == true) {
        return node129;
    }
    auto variables = node129->getVariables();
    if (variables != nullptr) {
        node129->setCondition(variables->getVariable<bool>(Variable_10023_InterruptAnimat));
    }
    return node129;
}
//--------------------------------------------------------------------------------
// IsInterruptType
//
REGISTER_REGISTER_SKILL_NODE(10023, 130) {
    pnode->resizeTrigger(PhaseNode_IsInterruptType::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SwitchToInt>(PhaseNode_IsInterruptType::TRIGGER_BUFF, 125, PhaseNode_SwitchToInt::FUNC_SWITCH, &PhaseNode_SwitchToInt::Switch);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_POSCHANGE, 129, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTAIM, 129, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTFIRE, 129, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTRELOAD, 129, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_USESKILL, 129, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(10023, 130) {
    auto node130 = GET_SKILL_NODE(130, PhaseNode_IsInterruptType);
    if (node130 == nullptr) {
        node130 = new PhaseNode_IsInterruptType(130, phase);
        node130->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node130->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10023, 130, node130)
    }
    if (noInit == true) {
        return node130;
    }
    auto node124 = GET_SKILL_NODE(124, PhaseNode_Detect);
    if (node124 != nullptr) node130->setType(node124->getVars().getVariable<int32_t>(2));
    return node130;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10023, 131) {
}

REGISTER_CREATE_SKILL_NODE(10023, 131) {
    auto node131 = GET_SKILL_NODE(131, PhaseNode_PlayAnimation);
    if (node131 == nullptr) {
        node131 = new PhaseNode_PlayAnimation(131, phase);
        node131->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node131->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node131->setTarget(0U);
        node131->setAnimation("Idle");
        node131->setParameter("");
        node131->setValue(false);
        CALL_REGISTER_SKILL_NODE(10023, 131, node131)
    }
    if (noInit == true) {
        return node131;
    }
    return node131;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10023, 132) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_Delay::TRIGGER_DONE, 135, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(10023, 132) {
    auto node132 = GET_SKILL_NODE(132, PhaseNode_Delay);
    if (node132 == nullptr) {
        node132 = new PhaseNode_Delay(132, phase);
        node132->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(10023, 132, node132)
    }
    if (noInit == true) {
        return node132;
    }
    return node132;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(10023, 135) {
}

REGISTER_CREATE_SKILL_NODE(10023, 135) {
    auto node135 = GET_SKILL_NODE(135, PhaseNode_SetBool);
    if (node135 == nullptr) {
        node135 = new PhaseNode_SetBool(135, phase);
        node135->setName("InterruptAnimat");
        node135->setValue(true);
        CALL_REGISTER_SKILL_NODE(10023, 135, node135)
    }
    if (noInit == true) {
        return node135;
    }
    return node135;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10023, 136) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StartPreInput>(PhaseNode_RaiseEvent::TRIGGER_DONE, 128, PhaseNode_StartPreInput::FUNC_DO, &PhaseNode_StartPreInput::Do);
}

REGISTER_CREATE_SKILL_NODE(10023, 136) {
    auto node136 = GET_SKILL_NODE(136, PhaseNode_RaiseEvent);
    if (node136 == nullptr) {
        node136 = new PhaseNode_RaiseEvent(136, phase);
        node136->setEvent("Dead_001");
        node136->setTarget(0U);
        node136->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node136->setTypeParams(0, 0);
        node136->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10023, 136, node136)
    }
    if (noInit == true) {
        return node136;
    }
    return node136;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10023, 137) {
}

REGISTER_CREATE_SKILL_NODE(10023, 137) {
    auto node137 = GET_SKILL_NODE(137, PhaseNode_Detect);
    if (node137 == nullptr) {
        node137 = new PhaseNode_Detect(137, phase);
        node137->setSelf(0U);
        node137->setEvent("Dead_001");
        node137->setType(PhaseNode_Detect::Detect_Type::Actor_Dead);
        node137->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10023, 137, node137)
    }
    if (noInit == true) {
        return node137;
    }
    return node137;
}

//--------------------------------------------------------------------------------
// SkillCreator_10023
//
class SkillCreator_10023 : public SkillCreator {
public:
    SkillCreator_10023() {}
    virtual ~SkillCreator_10023() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_10023

//--------------------------------------------------------------------------------
// SkillPhase_10023
//
class SkillPhase_10023 : public SkillPhase {
public:
    SkillPhase_10023(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_10023() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(10023, 2) // StartPhase
        CASE_CREATE_SKILL_NODE(10023, 10) // Disable
        CASE_CREATE_SKILL_NODE(10023, 14) // Delay
        CASE_CREATE_SKILL_NODE(10023, 38) // Delay
        CASE_CREATE_SKILL_NODE(10023, 40) // EndPhase
        CASE_CREATE_SKILL_NODE(10023, 63) // PlaySound
        CASE_CREATE_SKILL_NODE(10023, 93) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(10023, 96) // PlayEffect
        CASE_CREATE_SKILL_NODE(10023, 111) // GetLocation
        CASE_CREATE_SKILL_NODE(10023, 115) // AreaCollisionNewPene
        CASE_CREATE_SKILL_NODE(10023, 117) // AddSkillBuff
        CASE_CREATE_SKILL_NODE(10023, 119) // ResetCD
        CASE_CREATE_SKILL_NODE(10023, 120) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10023, 121) // PlaySound
        CASE_CREATE_SKILL_NODE(10023, 122) // GetActorAttribute
        CASE_CREATE_SKILL_NODE(10023, 124) // Detect
        CASE_CREATE_SKILL_NODE(10023, 125) // SwitchToInt
        CASE_CREATE_SKILL_NODE(10023, 127) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10023, 128) // StartPreInput
        CASE_CREATE_SKILL_NODE(10023, 129) // If
        CASE_CREATE_SKILL_NODE(10023, 130) // IsInterruptType
        CASE_CREATE_SKILL_NODE(10023, 131) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10023, 132) // Delay
        CASE_CREATE_SKILL_NODE(10023, 135) // SetBool
        CASE_CREATE_SKILL_NODE(10023, 136) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10023, 137) // Detect
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_10023

SkillLogic* SkillCreator_10023::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //设置变量
    Variable_10023_a100232 = logic->getVariables().setVariable<int32_t>("a100232", 1);
    Variable_10023_InterruptAnimat = logic->getVariables().setVariable<bool>("InterruptAnimat");
    //创建阶段phase
    auto phase = new SkillPhase_10023(1, logic, 2);
    //设置phase执行器
    phase->setRunPhaseNode(1, 2);
    phase->setDetectPhaseNode(2, 124);
    phase->setDetectPhaseNode(2, 137);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_10023::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
