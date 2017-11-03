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
#include "skill_psnode_playanimation.h"
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
uint64_t Variable_10341_Break = 0;
uint64_t Variable_10341_InterruptAnimat = 0;
//--------------------------------------------------------------------------------
// StartPhase
//
REGISTER_REGISTER_SKILL_NODE(10341, 3) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_StartPhase::TRIGGER_START, 50, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(10341, 3) {
    auto node3 = GET_SKILL_NODE(3, PhaseNode_StartPhase);
    if (node3 == nullptr) {
        node3 = new PhaseNode_StartPhase(3, phase);
        CALL_REGISTER_SKILL_NODE(10341, 3, node3)
    }
    if (noInit == true) {
        return node3;
    }
    return node3;
}
//--------------------------------------------------------------------------------
// Disable
//
REGISTER_REGISTER_SKILL_NODE(10341, 7) {
    pnode->resizeTrigger(PhaseNode_Disable::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuff>(PhaseNode_Disable::TRIGGER_DONE, 34, PhaseNode_AddSkillBuff::FUNC_ADD, &PhaseNode_AddSkillBuff::Add);
}

REGISTER_CREATE_SKILL_NODE(10341, 7) {
    auto node7 = GET_SKILL_NODE(7, PhaseNode_Disable);
    if (node7 == nullptr) {
        node7 = new PhaseNode_Disable(7, phase);
        node7->setTarget(0U);
        node7->setMove(false);
        node7->setSkill(true);
        node7->setShoot(true);
        node7->setTime(.40f);
        node7->setRotate(true);
        CALL_REGISTER_SKILL_NODE(10341, 7, node7)
    }
    if (noInit == true) {
        return node7;
    }
    return node7;
}
//--------------------------------------------------------------------------------
// SpawnProjectile
//
REGISTER_REGISTER_SKILL_NODE(10341, 9) {
    pnode->resizeTrigger(PhaseNode_SpawnProjectile::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_SpawnProjectile::TRIGGER_DONE, 19, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10341, 9) {
    auto node9 = GET_SKILL_NODE(9, PhaseNode_SpawnProjectile);
    if (node9 == nullptr) {
        node9 = new PhaseNode_SpawnProjectile(9, phase);
        node9->setDataId(55341);
        node9->setPosZ(.00f);
        node9->setEndPosX(.00f);
        node9->setEndPosY(.00f);
        node9->setEndPosZ(.00f);
        node9->setMaxCount(0);
        CALL_REGISTER_SKILL_NODE(10341, 9, node9)
    }
    if (noInit == true) {
        return node9;
    }
    auto node13 = GET_SKILL_NODE(13, PhaseNode_GetLocation);
    auto node17 = GET_SKILL_NODE(17, PhaseNode_GetInputRotation);
    if (node13 != nullptr) node9->setPosX(node13->getX());
    if (node13 != nullptr) node9->setPosY(node13->getY());
    if (node17 != nullptr) node9->setRotation(node17->getAngle());
    return node9;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10341, 11) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetInt>(PhaseNode_Delay::TRIGGER_DONE, 27, PhaseNode_SetInt::FUNC_SET, &PhaseNode_SetInt::Set);
}

REGISTER_CREATE_SKILL_NODE(10341, 11) {
    auto node11 = GET_SKILL_NODE(11, PhaseNode_Delay);
    if (node11 == nullptr) {
        node11 = new PhaseNode_Delay(11, phase);
        node11->setTime(.25f);
        CALL_REGISTER_SKILL_NODE(10341, 11, node11)
    }
    if (noInit == true) {
        return node11;
    }
    return node11;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(10341, 13) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetInputRotation>(PhaseNode_GetLocation::TRIGGER_DONE, 17, PhaseNode_GetInputRotation::FUNC_DO, &PhaseNode_GetInputRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(10341, 13) {
    auto node13 = GET_SKILL_NODE(13, PhaseNode_GetLocation);
    if (node13 == nullptr) {
        node13 = new PhaseNode_GetLocation(13, phase);
        node13->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node13->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(10341, 13, node13)
    }
    if (noInit == true) {
        return node13;
    }
    return node13;
}
//--------------------------------------------------------------------------------
// GetInputRotation
//
REGISTER_REGISTER_SKILL_NODE(10341, 17) {
    pnode->resizeTrigger(PhaseNode_GetInputRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_GetInputRotation::TRIGGER_DONE, 32, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10341, 17) {
    auto node17 = GET_SKILL_NODE(17, PhaseNode_GetInputRotation);
    if (node17 == nullptr) {
        node17 = new PhaseNode_GetInputRotation(17, phase);
        node17->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        CALL_REGISTER_SKILL_NODE(10341, 17, node17)
    }
    if (noInit == true) {
        return node17;
    }
    return node17;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10341, 19) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_Delay::TRIGGER_DONE, 21, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(10341, 19) {
    auto node19 = GET_SKILL_NODE(19, PhaseNode_Delay);
    if (node19 == nullptr) {
        node19 = new PhaseNode_Delay(19, phase);
        node19->setTime(.55f);
        CALL_REGISTER_SKILL_NODE(10341, 19, node19)
    }
    if (noInit == true) {
        return node19;
    }
    return node19;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(10341, 21) {
}

REGISTER_CREATE_SKILL_NODE(10341, 21) {
    auto node21 = GET_SKILL_NODE(21, PhaseNode_EndPhase);
    if (node21 == nullptr) {
        node21 = new PhaseNode_EndPhase(21, phase);
        node21->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node21->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10341, 21, node21)
    }
    if (noInit == true) {
        return node21;
    }
    return node21;
}
//--------------------------------------------------------------------------------
// SetInt
//
REGISTER_REGISTER_SKILL_NODE(10341, 27) {
    pnode->resizeTrigger(PhaseNode_SetInt::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_SetInt::TRIGGER_DONE, 13, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(10341, 27) {
    auto node27 = GET_SKILL_NODE(27, PhaseNode_SetInt);
    if (node27 == nullptr) {
        node27 = new PhaseNode_SetInt(27, phase);
        node27->setName("Break");
        node27->setValue(2);
        CALL_REGISTER_SKILL_NODE(10341, 27, node27)
    }
    if (noInit == true) {
        return node27;
    }
    return node27;
}
//--------------------------------------------------------------------------------
// TriggerUpdate
//
REGISTER_REGISTER_SKILL_NODE(10341, 29) {
}

REGISTER_CREATE_SKILL_NODE(10341, 29) {
    auto node29 = GET_SKILL_NODE(29, PhaseNode_TriggerUpdate);
    if (node29 == nullptr) {
        node29 = new PhaseNode_TriggerUpdate(29, phase);
        CALL_REGISTER_SKILL_NODE(10341, 29, node29)
    }
    if (noInit == true) {
        return node29;
    }
    return node29;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10341, 32) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnProjectile>(PhaseNode_PlaySound::TRIGGER_DONE, 9, PhaseNode_SpawnProjectile::FUNC_DO, &PhaseNode_SpawnProjectile::Do);
}

REGISTER_CREATE_SKILL_NODE(10341, 32) {
    auto node32 = GET_SKILL_NODE(32, PhaseNode_PlaySound);
    if (node32 == nullptr) {
        node32 = new PhaseNode_PlaySound(32, phase);
        node32->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node32->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node32->setSoundID("SE_Hero134_SkillA");
        node32->setTarget(0U);
        node32->setUsePos(false);
        node32->setPosX(.00f);
        node32->setPosY(.00f);
        node32->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10341, 32, node32)
    }
    if (noInit == true) {
        return node32;
    }
    return node32;
}
//--------------------------------------------------------------------------------
// AddSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10341, 34) {
    pnode->resizeTrigger(PhaseNode_AddSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_AddSkillBuff::TRIGGER_DONE, 39, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10341, 34) {
    auto node34 = GET_SKILL_NODE(34, PhaseNode_AddSkillBuff);
    if (node34 == nullptr) {
        node34 = new PhaseNode_AddSkillBuff(34, phase);
        node34->setConfigID(103401);
        node34->setConfigIDs({});
        node34->setTarget(0U);
        node34->setAttribute({{}});
        CALL_REGISTER_SKILL_NODE(10341, 34, node34)
    }
    if (noInit == true) {
        return node34;
    }
    return node34;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10341, 36) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_IsInterruptType>(PhaseNode_Detect::TRIGGER_ON, 42, PhaseNode_IsInterruptType::FUNC_DO, &PhaseNode_IsInterruptType::Do);
}

REGISTER_CREATE_SKILL_NODE(10341, 36) {
    auto node36 = GET_SKILL_NODE(36, PhaseNode_Detect);
    if (node36 == nullptr) {
        node36 = new PhaseNode_Detect(36, phase);
        node36->setSelf(0U);
        node36->setEvent("daduan_001");
        node36->setType(PhaseNode_Detect::Detect_Type::Interrupt_Skill);
        node36->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10341, 36, node36)
    }
    if (noInit == true) {
        return node36;
    }
    return node36;
}
//--------------------------------------------------------------------------------
// SwitchToInt
//
REGISTER_REGISTER_SKILL_NODE(10341, 37) {
    pnode->resizeTrigger(4);
    pnode->regTrigger<PhaseNode_EndPhase>(1, 21, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(10341, 37) {
    auto node37 = GET_SKILL_NODE(37, PhaseNode_SwitchToInt);
    if (node37 == nullptr) {
        node37 = new PhaseNode_SwitchToInt(37, phase);
        CALL_REGISTER_SKILL_NODE(10341, 37, node37)
    }
    if (noInit == true) {
        return node37;
    }
    auto variables = node37->getVariables();
    if (variables != nullptr) {
        node37->setSelection(variables->getVariable<int32_t>(Variable_10341_Break));
    }
    return node37;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10341, 39) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_RaiseEvent::TRIGGER_DONE, 48, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10341, 39) {
    auto node39 = GET_SKILL_NODE(39, PhaseNode_RaiseEvent);
    if (node39 == nullptr) {
        node39 = new PhaseNode_RaiseEvent(39, phase);
        node39->setEvent("daduan_001");
        node39->setTarget(0U);
        node39->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node39->setTypeParams(0, 0);
        node39->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10341, 39, node39)
    }
    if (noInit == true) {
        return node39;
    }
    return node39;
}
//--------------------------------------------------------------------------------
// StartPreInput
//
REGISTER_REGISTER_SKILL_NODE(10341, 40) {
    pnode->resizeTrigger(PhaseNode_StartPreInput::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_StartPreInput::TRIGGER_DONE, 11, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_StartPreInput::TRIGGER_DONE, 44, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10341, 40) {
    auto node40 = GET_SKILL_NODE(40, PhaseNode_StartPreInput);
    if (node40 == nullptr) {
        node40 = new PhaseNode_StartPreInput(40, phase);
        node40->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node40->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node40->setDelayTime(.00f);
        CALL_REGISTER_SKILL_NODE(10341, 40, node40)
    }
    if (noInit == true) {
        return node40;
    }
    return node40;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(10341, 41) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_If::TRIGGER_TRUE, 43, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10341, 41) {
    auto node41 = GET_SKILL_NODE(41, PhaseNode_If);
    if (node41 == nullptr) {
        node41 = new PhaseNode_If(41, phase);
        CALL_REGISTER_SKILL_NODE(10341, 41, node41)
    }
    if (noInit == true) {
        return node41;
    }
    auto variables = node41->getVariables();
    if (variables != nullptr) {
        node41->setCondition(variables->getVariable<bool>(Variable_10341_InterruptAnimat));
    }
    return node41;
}
//--------------------------------------------------------------------------------
// IsInterruptType
//
REGISTER_REGISTER_SKILL_NODE(10341, 42) {
    pnode->resizeTrigger(PhaseNode_IsInterruptType::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SwitchToInt>(PhaseNode_IsInterruptType::TRIGGER_BUFF, 37, PhaseNode_SwitchToInt::FUNC_SWITCH, &PhaseNode_SwitchToInt::Switch);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_POSCHANGE, 41, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTAIM, 41, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTFIRE, 41, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTRELOAD, 41, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_USESKILL, 41, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(10341, 42) {
    auto node42 = GET_SKILL_NODE(42, PhaseNode_IsInterruptType);
    if (node42 == nullptr) {
        node42 = new PhaseNode_IsInterruptType(42, phase);
        node42->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node42->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10341, 42, node42)
    }
    if (noInit == true) {
        return node42;
    }
    auto node36 = GET_SKILL_NODE(36, PhaseNode_Detect);
    if (node36 != nullptr) node42->setType(node36->getVars().getVariable<int32_t>(2));
    return node42;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10341, 43) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_PlayAnimation::TRIGGER_DONE, 21, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(10341, 43) {
    auto node43 = GET_SKILL_NODE(43, PhaseNode_PlayAnimation);
    if (node43 == nullptr) {
        node43 = new PhaseNode_PlayAnimation(43, phase);
        node43->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node43->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node43->setTarget(0U);
        node43->setAnimation("Idle");
        node43->setParameter("");
        node43->setValue(false);
        CALL_REGISTER_SKILL_NODE(10341, 43, node43)
    }
    if (noInit == true) {
        return node43;
    }
    return node43;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10341, 44) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_Delay::TRIGGER_DONE, 47, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(10341, 44) {
    auto node44 = GET_SKILL_NODE(44, PhaseNode_Delay);
    if (node44 == nullptr) {
        node44 = new PhaseNode_Delay(44, phase);
        node44->setTime(.40f);
        CALL_REGISTER_SKILL_NODE(10341, 44, node44)
    }
    if (noInit == true) {
        return node44;
    }
    return node44;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(10341, 47) {
}

REGISTER_CREATE_SKILL_NODE(10341, 47) {
    auto node47 = GET_SKILL_NODE(47, PhaseNode_SetBool);
    if (node47 == nullptr) {
        node47 = new PhaseNode_SetBool(47, phase);
        node47->setName("InterruptAnimat");
        node47->setValue(true);
        CALL_REGISTER_SKILL_NODE(10341, 47, node47)
    }
    if (noInit == true) {
        return node47;
    }
    return node47;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10341, 48) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StartPreInput>(PhaseNode_RaiseEvent::TRIGGER_DONE, 40, PhaseNode_StartPreInput::FUNC_DO, &PhaseNode_StartPreInput::Do);
}

REGISTER_CREATE_SKILL_NODE(10341, 48) {
    auto node48 = GET_SKILL_NODE(48, PhaseNode_RaiseEvent);
    if (node48 == nullptr) {
        node48 = new PhaseNode_RaiseEvent(48, phase);
        node48->setEvent("Dead_001");
        node48->setTarget(0U);
        node48->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node48->setTypeParams(0, 0);
        node48->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10341, 48, node48)
    }
    if (noInit == true) {
        return node48;
    }
    return node48;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10341, 49) {
}

REGISTER_CREATE_SKILL_NODE(10341, 49) {
    auto node49 = GET_SKILL_NODE(49, PhaseNode_Detect);
    if (node49 == nullptr) {
        node49 = new PhaseNode_Detect(49, phase);
        node49->setSelf(0U);
        node49->setEvent("Dead_001");
        node49->setType(PhaseNode_Detect::Detect_Type::Actor_Dead);
        node49->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10341, 49, node49)
    }
    if (noInit == true) {
        return node49;
    }
    return node49;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(10341, 50) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_ResetCD::TRIGGER_DONE, 51, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10341, 50) {
    auto node50 = GET_SKILL_NODE(50, PhaseNode_ResetCD);
    if (node50 == nullptr) {
        node50 = new PhaseNode_ResetCD(50, phase);
        node50->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node50->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node50->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(10341, 50, node50)
    }
    if (noInit == true) {
        return node50;
    }
    return node50;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10341, 51) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_PlayAnimation::TRIGGER_DONE, 53, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(10341, 51) {
    auto node51 = GET_SKILL_NODE(51, PhaseNode_PlayAnimation);
    if (node51 == nullptr) {
        node51 = new PhaseNode_PlayAnimation(51, phase);
        node51->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node51->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node51->setTarget(0U);
        node51->setAnimation("Skill1S1");
        node51->setParameter("SkillArmBusy");
        node51->setValue(true);
        CALL_REGISTER_SKILL_NODE(10341, 51, node51)
    }
    if (noInit == true) {
        return node51;
    }
    return node51;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10341, 52) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Disable>(PhaseNode_PlaySound::TRIGGER_DONE, 7, PhaseNode_Disable::FUNC_DO, &PhaseNode_Disable::Do);
}

REGISTER_CREATE_SKILL_NODE(10341, 52) {
    auto node52 = GET_SKILL_NODE(52, PhaseNode_PlaySound);
    if (node52 == nullptr) {
        node52 = new PhaseNode_PlaySound(52, phase);
        node52->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node52->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node52->setSoundID("");
        node52->setTarget(0U);
        node52->setUsePos(false);
        node52->setPosX(.00f);
        node52->setPosY(.00f);
        node52->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10341, 52, node52)
    }
    if (noInit == true) {
        return node52;
    }
    return node52;
}
//--------------------------------------------------------------------------------
// GetActorAttribute
//
REGISTER_REGISTER_SKILL_NODE(10341, 53) {
    pnode->resizeTrigger(PhaseNode_GetActorAttribute::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 52, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10341, 53) {
    auto node53 = GET_SKILL_NODE(53, PhaseNode_GetActorAttribute);
    if (node53 == nullptr) {
        node53 = new PhaseNode_GetActorAttribute(53, phase);
        node53->setTarget(0U);
        node53->setType({});
        CALL_REGISTER_SKILL_NODE(10341, 53, node53)
    }
    if (noInit == true) {
        return node53;
    }
    return node53;
}

//--------------------------------------------------------------------------------
// SkillCreator_10341
//
class SkillCreator_10341 : public SkillCreator {
public:
    SkillCreator_10341() {}
    virtual ~SkillCreator_10341() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_10341

//--------------------------------------------------------------------------------
// SkillPhase_10341
//
class SkillPhase_10341 : public SkillPhase {
public:
    SkillPhase_10341(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_10341() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(10341, 3) // StartPhase
        CASE_CREATE_SKILL_NODE(10341, 7) // Disable
        CASE_CREATE_SKILL_NODE(10341, 9) // SpawnProjectile
        CASE_CREATE_SKILL_NODE(10341, 11) // Delay
        CASE_CREATE_SKILL_NODE(10341, 13) // GetLocation
        CASE_CREATE_SKILL_NODE(10341, 17) // GetInputRotation
        CASE_CREATE_SKILL_NODE(10341, 19) // Delay
        CASE_CREATE_SKILL_NODE(10341, 21) // EndPhase
        CASE_CREATE_SKILL_NODE(10341, 27) // SetInt
        CASE_CREATE_SKILL_NODE(10341, 29) // TriggerUpdate
        CASE_CREATE_SKILL_NODE(10341, 32) // PlaySound
        CASE_CREATE_SKILL_NODE(10341, 34) // AddSkillBuff
        CASE_CREATE_SKILL_NODE(10341, 36) // Detect
        CASE_CREATE_SKILL_NODE(10341, 37) // SwitchToInt
        CASE_CREATE_SKILL_NODE(10341, 39) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10341, 40) // StartPreInput
        CASE_CREATE_SKILL_NODE(10341, 41) // If
        CASE_CREATE_SKILL_NODE(10341, 42) // IsInterruptType
        CASE_CREATE_SKILL_NODE(10341, 43) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10341, 44) // Delay
        CASE_CREATE_SKILL_NODE(10341, 47) // SetBool
        CASE_CREATE_SKILL_NODE(10341, 48) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10341, 49) // Detect
        CASE_CREATE_SKILL_NODE(10341, 50) // ResetCD
        CASE_CREATE_SKILL_NODE(10341, 51) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10341, 52) // PlaySound
        CASE_CREATE_SKILL_NODE(10341, 53) // GetActorAttribute
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_10341

SkillLogic* SkillCreator_10341::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //设置变量
    Variable_10341_Break = logic->getVariables().setVariable<int32_t>("Break", 1);
    Variable_10341_InterruptAnimat = logic->getVariables().setVariable<bool>("InterruptAnimat");
    //创建阶段phase
    auto phase = new SkillPhase_10341(1, logic, 3);
    //设置phase执行器
    phase->setRunPhaseNode(1, 3);
    phase->setRunPhaseNode(2, 29);
    phase->setDetectPhaseNode(3, 36);
    phase->setDetectPhaseNode(3, 49);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_10341::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
