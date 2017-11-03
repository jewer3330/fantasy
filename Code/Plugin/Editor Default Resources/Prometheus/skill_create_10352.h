#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

#include "skill_psnode_delay.h"
#include "skill_psnode_detect.h"
#include "skill_psnode_disable.h"
#include "skill_psnode_endphase.h"
#include "skill_psnode_getinputlocation.h"
#include "skill_psnode_getlinerotation.h"
#include "skill_psnode_getlocation.h"
#include "skill_psnode_if.h"
#include "skill_psnode_isinterrupttype.h"
#include "skill_psnode_offsetcalculate.h"
#include "skill_psnode_playanimation.h"
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
uint64_t Variable_10352_103521 = 0;
uint64_t Variable_10352_InterruptAnimat = 0;
//--------------------------------------------------------------------------------
// TriggerUpdate
//
REGISTER_REGISTER_SKILL_NODE(10352, 3) {
}

REGISTER_CREATE_SKILL_NODE(10352, 3) {
    auto node3 = GET_SKILL_NODE(3, PhaseNode_TriggerUpdate);
    if (node3 == nullptr) {
        node3 = new PhaseNode_TriggerUpdate(3, phase);
        CALL_REGISTER_SKILL_NODE(10352, 3, node3)
    }
    if (noInit == true) {
        return node3;
    }
    return node3;
}
//--------------------------------------------------------------------------------
// StartPhase
//
REGISTER_REGISTER_SKILL_NODE(10352, 5) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_StartPhase::TRIGGER_START, 7, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(10352, 5) {
    auto node5 = GET_SKILL_NODE(5, PhaseNode_StartPhase);
    if (node5 == nullptr) {
        node5 = new PhaseNode_StartPhase(5, phase);
        CALL_REGISTER_SKILL_NODE(10352, 5, node5)
    }
    if (noInit == true) {
        return node5;
    }
    return node5;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(10352, 7) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_ResetCD::TRIGGER_DONE, 9, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10352, 7) {
    auto node7 = GET_SKILL_NODE(7, PhaseNode_ResetCD);
    if (node7 == nullptr) {
        node7 = new PhaseNode_ResetCD(7, phase);
        node7->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node7->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node7->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(10352, 7, node7)
    }
    if (noInit == true) {
        return node7;
    }
    return node7;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10352, 9) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Disable>(PhaseNode_PlayAnimation::TRIGGER_DONE, 11, PhaseNode_Disable::FUNC_DO, &PhaseNode_Disable::Do);
}

REGISTER_CREATE_SKILL_NODE(10352, 9) {
    auto node9 = GET_SKILL_NODE(9, PhaseNode_PlayAnimation);
    if (node9 == nullptr) {
        node9 = new PhaseNode_PlayAnimation(9, phase);
        node9->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node9->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node9->setTarget(0U);
        node9->setAnimation("Skill2S1");
        node9->setParameter("SkillArmBusy");
        node9->setValue(true);
        CALL_REGISTER_SKILL_NODE(10352, 9, node9)
    }
    if (noInit == true) {
        return node9;
    }
    return node9;
}
//--------------------------------------------------------------------------------
// Disable
//
REGISTER_REGISTER_SKILL_NODE(10352, 11) {
    pnode->resizeTrigger(PhaseNode_Disable::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_Disable::TRIGGER_DONE, 22, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_Disable::TRIGGER_DONE, 52, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
    pnode->regTrigger<PhaseNode_SetInt>(PhaseNode_Disable::TRIGGER_DONE, 39, PhaseNode_SetInt::FUNC_SET, &PhaseNode_SetInt::Set);
}

REGISTER_CREATE_SKILL_NODE(10352, 11) {
    auto node11 = GET_SKILL_NODE(11, PhaseNode_Disable);
    if (node11 == nullptr) {
        node11 = new PhaseNode_Disable(11, phase);
        node11->setTarget(0U);
        node11->setMove(true);
        node11->setSkill(true);
        node11->setShoot(true);
        node11->setTime(.50f);
        node11->setRotate(true);
        CALL_REGISTER_SKILL_NODE(10352, 11, node11)
    }
    if (noInit == true) {
        return node11;
    }
    return node11;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(10352, 18) {
}

REGISTER_CREATE_SKILL_NODE(10352, 18) {
    auto node18 = GET_SKILL_NODE(18, PhaseNode_EndPhase);
    if (node18 == nullptr) {
        node18 = new PhaseNode_EndPhase(18, phase);
        node18->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node18->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10352, 18, node18)
    }
    if (noInit == true) {
        return node18;
    }
    return node18;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10352, 22) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_Delay::TRIGGER_DONE, 26, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(10352, 22) {
    auto node22 = GET_SKILL_NODE(22, PhaseNode_Delay);
    if (node22 == nullptr) {
        node22 = new PhaseNode_Delay(22, phase);
        node22->setTime(.23f);
        CALL_REGISTER_SKILL_NODE(10352, 22, node22)
    }
    if (noInit == true) {
        return node22;
    }
    return node22;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(10352, 26) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetInputLocation>(PhaseNode_GetLocation::TRIGGER_DONE, 28, PhaseNode_GetInputLocation::FUNC_DO, &PhaseNode_GetInputLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(10352, 26) {
    auto node26 = GET_SKILL_NODE(26, PhaseNode_GetLocation);
    if (node26 == nullptr) {
        node26 = new PhaseNode_GetLocation(26, phase);
        node26->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node26->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(10352, 26, node26)
    }
    if (noInit == true) {
        return node26;
    }
    return node26;
}
//--------------------------------------------------------------------------------
// GetInputLocation
//
REGISTER_REGISTER_SKILL_NODE(10352, 28) {
    pnode->resizeTrigger(PhaseNode_GetInputLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLineRotation>(PhaseNode_GetInputLocation::TRIGGER_DONE, 47, PhaseNode_GetLineRotation::FUNC_DO, &PhaseNode_GetLineRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(10352, 28) {
    auto node28 = GET_SKILL_NODE(28, PhaseNode_GetInputLocation);
    if (node28 == nullptr) {
        node28 = new PhaseNode_GetInputLocation(28, phase);
        node28->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        CALL_REGISTER_SKILL_NODE(10352, 28, node28)
    }
    if (noInit == true) {
        return node28;
    }
    return node28;
}
//--------------------------------------------------------------------------------
// OffsetCalculate
//
REGISTER_REGISTER_SKILL_NODE(10352, 30) {
    pnode->resizeTrigger(PhaseNode_OffsetCalculate::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnProjectile>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 32, PhaseNode_SpawnProjectile::FUNC_DO, &PhaseNode_SpawnProjectile::Do);
}

REGISTER_CREATE_SKILL_NODE(10352, 30) {
    auto node30 = GET_SKILL_NODE(30, PhaseNode_OffsetCalculate);
    if (node30 == nullptr) {
        node30 = new PhaseNode_OffsetCalculate(30, phase);
        node30->setPosZ(.00f);
        node30->setOffsetX(.00f);
        node30->setOffsetY(.00f);
        node30->setOffsetZ(5.00f);
        node30->setRotOffset(.00f);
        CALL_REGISTER_SKILL_NODE(10352, 30, node30)
    }
    if (noInit == true) {
        return node30;
    }
    auto node26 = GET_SKILL_NODE(26, PhaseNode_GetLocation);
    auto node47 = GET_SKILL_NODE(47, PhaseNode_GetLineRotation);
    if (node26 != nullptr) node30->setPosX(node26->getX());
    if (node26 != nullptr) node30->setPosY(node26->getY());
    if (node47 != nullptr) node30->setRotation(node47->getRotation());
    return node30;
}
//--------------------------------------------------------------------------------
// SpawnProjectile
//
REGISTER_REGISTER_SKILL_NODE(10352, 32) {
    pnode->resizeTrigger(PhaseNode_SpawnProjectile::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_SpawnProjectile::TRIGGER_DONE, 34, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10352, 32) {
    auto node32 = GET_SKILL_NODE(32, PhaseNode_SpawnProjectile);
    if (node32 == nullptr) {
        node32 = new PhaseNode_SpawnProjectile(32, phase);
        node32->setDataId(55352);
        node32->setPosZ(.00f);
        node32->setEndPosZ(.00f);
        node32->setMaxCount(0);
        CALL_REGISTER_SKILL_NODE(10352, 32, node32)
    }
    if (noInit == true) {
        return node32;
    }
    auto node30 = GET_SKILL_NODE(30, PhaseNode_OffsetCalculate);
    auto node28 = GET_SKILL_NODE(28, PhaseNode_GetInputLocation);
    if (node30 != nullptr) node32->setPosX(node30->getOutPosX());
    if (node30 != nullptr) node32->setPosY(node30->getOutPosY());
    if (node28 != nullptr) node32->setEndPosX(node28->getX());
    if (node28 != nullptr) node32->setEndPosY(node28->getY());
    if (node30 != nullptr) node32->setRotation(node30->getOutRotation());
    return node32;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10352, 34) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_Delay::TRIGGER_DONE, 37, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(10352, 34) {
    auto node34 = GET_SKILL_NODE(34, PhaseNode_Delay);
    if (node34 == nullptr) {
        node34 = new PhaseNode_Delay(34, phase);
        node34->setTime(.47f);
        CALL_REGISTER_SKILL_NODE(10352, 34, node34)
    }
    if (noInit == true) {
        return node34;
    }
    return node34;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(10352, 37) {
}

REGISTER_CREATE_SKILL_NODE(10352, 37) {
    auto node37 = GET_SKILL_NODE(37, PhaseNode_EndPhase);
    if (node37 == nullptr) {
        node37 = new PhaseNode_EndPhase(37, phase);
        node37->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node37->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10352, 37, node37)
    }
    if (noInit == true) {
        return node37;
    }
    return node37;
}
//--------------------------------------------------------------------------------
// SetInt
//
REGISTER_REGISTER_SKILL_NODE(10352, 39) {
}

REGISTER_CREATE_SKILL_NODE(10352, 39) {
    auto node39 = GET_SKILL_NODE(39, PhaseNode_SetInt);
    if (node39 == nullptr) {
        node39 = new PhaseNode_SetInt(39, phase);
        node39->setName("103521");
        node39->setValue(2);
        CALL_REGISTER_SKILL_NODE(10352, 39, node39)
    }
    if (noInit == true) {
        return node39;
    }
    return node39;
}
//--------------------------------------------------------------------------------
// GetLineRotation
//
REGISTER_REGISTER_SKILL_NODE(10352, 47) {
    pnode->resizeTrigger(PhaseNode_GetLineRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_OffsetCalculate>(PhaseNode_GetLineRotation::TRIGGER_DONE, 30, PhaseNode_OffsetCalculate::FUNC_DO, &PhaseNode_OffsetCalculate::Do);
}

REGISTER_CREATE_SKILL_NODE(10352, 47) {
    auto node47 = GET_SKILL_NODE(47, PhaseNode_GetLineRotation);
    if (node47 == nullptr) {
        node47 = new PhaseNode_GetLineRotation(47, phase);
        CALL_REGISTER_SKILL_NODE(10352, 47, node47)
    }
    if (noInit == true) {
        return node47;
    }
    auto node26 = GET_SKILL_NODE(26, PhaseNode_GetLocation);
    auto node28 = GET_SKILL_NODE(28, PhaseNode_GetInputLocation);
    if (node26 != nullptr) node47->setStartX(node26->getX());
    if (node26 != nullptr) node47->setStartY(node26->getY());
    if (node28 != nullptr) node47->setEndX(node28->getX());
    if (node28 != nullptr) node47->setEndY(node28->getY());
    return node47;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10352, 49) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_IsInterruptType>(PhaseNode_Detect::TRIGGER_ON, 55, PhaseNode_IsInterruptType::FUNC_DO, &PhaseNode_IsInterruptType::Do);
}

REGISTER_CREATE_SKILL_NODE(10352, 49) {
    auto node49 = GET_SKILL_NODE(49, PhaseNode_Detect);
    if (node49 == nullptr) {
        node49 = new PhaseNode_Detect(49, phase);
        node49->setSelf(0U);
        node49->setEvent("daduan_001");
        node49->setType(PhaseNode_Detect::Detect_Type::Interrupt_Skill);
        node49->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10352, 49, node49)
    }
    if (noInit == true) {
        return node49;
    }
    return node49;
}
//--------------------------------------------------------------------------------
// SwitchToInt
//
REGISTER_REGISTER_SKILL_NODE(10352, 50) {
    pnode->resizeTrigger(4);
    pnode->regTrigger<PhaseNode_EndPhase>(1, 18, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(10352, 50) {
    auto node50 = GET_SKILL_NODE(50, PhaseNode_SwitchToInt);
    if (node50 == nullptr) {
        node50 = new PhaseNode_SwitchToInt(50, phase);
        CALL_REGISTER_SKILL_NODE(10352, 50, node50)
    }
    if (noInit == true) {
        return node50;
    }
    auto variables = node50->getVariables();
    if (variables != nullptr) {
        node50->setSelection(variables->getVariable<int32_t>(Variable_10352_103521));
    }
    return node50;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10352, 52) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_RaiseEvent::TRIGGER_DONE, 61, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10352, 52) {
    auto node52 = GET_SKILL_NODE(52, PhaseNode_RaiseEvent);
    if (node52 == nullptr) {
        node52 = new PhaseNode_RaiseEvent(52, phase);
        node52->setEvent("daduan_001");
        node52->setTarget(0U);
        node52->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node52->setTypeParams(0, 0);
        node52->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10352, 52, node52)
    }
    if (noInit == true) {
        return node52;
    }
    return node52;
}
//--------------------------------------------------------------------------------
// StartPreInput
//
REGISTER_REGISTER_SKILL_NODE(10352, 53) {
    pnode->resizeTrigger(PhaseNode_StartPreInput::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_StartPreInput::TRIGGER_DONE, 57, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10352, 53) {
    auto node53 = GET_SKILL_NODE(53, PhaseNode_StartPreInput);
    if (node53 == nullptr) {
        node53 = new PhaseNode_StartPreInput(53, phase);
        node53->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node53->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node53->setDelayTime(.00f);
        CALL_REGISTER_SKILL_NODE(10352, 53, node53)
    }
    if (noInit == true) {
        return node53;
    }
    return node53;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(10352, 54) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_If::TRIGGER_TRUE, 56, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10352, 54) {
    auto node54 = GET_SKILL_NODE(54, PhaseNode_If);
    if (node54 == nullptr) {
        node54 = new PhaseNode_If(54, phase);
        CALL_REGISTER_SKILL_NODE(10352, 54, node54)
    }
    if (noInit == true) {
        return node54;
    }
    auto variables = node54->getVariables();
    if (variables != nullptr) {
        node54->setCondition(variables->getVariable<bool>(Variable_10352_InterruptAnimat));
    }
    return node54;
}
//--------------------------------------------------------------------------------
// IsInterruptType
//
REGISTER_REGISTER_SKILL_NODE(10352, 55) {
    pnode->resizeTrigger(PhaseNode_IsInterruptType::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SwitchToInt>(PhaseNode_IsInterruptType::TRIGGER_BUFF, 50, PhaseNode_SwitchToInt::FUNC_SWITCH, &PhaseNode_SwitchToInt::Switch);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_POSCHANGE, 54, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTAIM, 54, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTFIRE, 54, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTRELOAD, 54, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_USESKILL, 54, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(10352, 55) {
    auto node55 = GET_SKILL_NODE(55, PhaseNode_IsInterruptType);
    if (node55 == nullptr) {
        node55 = new PhaseNode_IsInterruptType(55, phase);
        node55->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node55->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10352, 55, node55)
    }
    if (noInit == true) {
        return node55;
    }
    auto node49 = GET_SKILL_NODE(49, PhaseNode_Detect);
    if (node49 != nullptr) node55->setType(node49->getVars().getVariable<int32_t>(2));
    return node55;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10352, 56) {
}

REGISTER_CREATE_SKILL_NODE(10352, 56) {
    auto node56 = GET_SKILL_NODE(56, PhaseNode_PlayAnimation);
    if (node56 == nullptr) {
        node56 = new PhaseNode_PlayAnimation(56, phase);
        node56->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node56->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node56->setTarget(0U);
        node56->setAnimation("Idle");
        node56->setParameter("");
        node56->setValue(false);
        CALL_REGISTER_SKILL_NODE(10352, 56, node56)
    }
    if (noInit == true) {
        return node56;
    }
    return node56;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10352, 57) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_Delay::TRIGGER_DONE, 60, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(10352, 57) {
    auto node57 = GET_SKILL_NODE(57, PhaseNode_Delay);
    if (node57 == nullptr) {
        node57 = new PhaseNode_Delay(57, phase);
        node57->setTime(.20f);
        CALL_REGISTER_SKILL_NODE(10352, 57, node57)
    }
    if (noInit == true) {
        return node57;
    }
    return node57;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(10352, 60) {
}

REGISTER_CREATE_SKILL_NODE(10352, 60) {
    auto node60 = GET_SKILL_NODE(60, PhaseNode_SetBool);
    if (node60 == nullptr) {
        node60 = new PhaseNode_SetBool(60, phase);
        node60->setName("InterruptAnimat");
        node60->setValue(true);
        CALL_REGISTER_SKILL_NODE(10352, 60, node60)
    }
    if (noInit == true) {
        return node60;
    }
    return node60;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10352, 61) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StartPreInput>(PhaseNode_RaiseEvent::TRIGGER_DONE, 53, PhaseNode_StartPreInput::FUNC_DO, &PhaseNode_StartPreInput::Do);
}

REGISTER_CREATE_SKILL_NODE(10352, 61) {
    auto node61 = GET_SKILL_NODE(61, PhaseNode_RaiseEvent);
    if (node61 == nullptr) {
        node61 = new PhaseNode_RaiseEvent(61, phase);
        node61->setEvent("Dead_001");
        node61->setTarget(0U);
        node61->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node61->setTypeParams(0, 0);
        node61->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10352, 61, node61)
    }
    if (noInit == true) {
        return node61;
    }
    return node61;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10352, 62) {
}

REGISTER_CREATE_SKILL_NODE(10352, 62) {
    auto node62 = GET_SKILL_NODE(62, PhaseNode_Detect);
    if (node62 == nullptr) {
        node62 = new PhaseNode_Detect(62, phase);
        node62->setSelf(0U);
        node62->setEvent("Dead_001");
        node62->setType(PhaseNode_Detect::Detect_Type::Actor_Dead);
        node62->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10352, 62, node62)
    }
    if (noInit == true) {
        return node62;
    }
    return node62;
}

//--------------------------------------------------------------------------------
// SkillCreator_10352
//
class SkillCreator_10352 : public SkillCreator {
public:
    SkillCreator_10352() {}
    virtual ~SkillCreator_10352() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_10352

//--------------------------------------------------------------------------------
// SkillPhase_10352
//
class SkillPhase_10352 : public SkillPhase {
public:
    SkillPhase_10352(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_10352() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(10352, 3) // TriggerUpdate
        CASE_CREATE_SKILL_NODE(10352, 5) // StartPhase
        CASE_CREATE_SKILL_NODE(10352, 7) // ResetCD
        CASE_CREATE_SKILL_NODE(10352, 9) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10352, 11) // Disable
        CASE_CREATE_SKILL_NODE(10352, 18) // EndPhase
        CASE_CREATE_SKILL_NODE(10352, 22) // Delay
        CASE_CREATE_SKILL_NODE(10352, 26) // GetLocation
        CASE_CREATE_SKILL_NODE(10352, 28) // GetInputLocation
        CASE_CREATE_SKILL_NODE(10352, 30) // OffsetCalculate
        CASE_CREATE_SKILL_NODE(10352, 32) // SpawnProjectile
        CASE_CREATE_SKILL_NODE(10352, 34) // Delay
        CASE_CREATE_SKILL_NODE(10352, 37) // EndPhase
        CASE_CREATE_SKILL_NODE(10352, 39) // SetInt
        CASE_CREATE_SKILL_NODE(10352, 47) // GetLineRotation
        CASE_CREATE_SKILL_NODE(10352, 49) // Detect
        CASE_CREATE_SKILL_NODE(10352, 50) // SwitchToInt
        CASE_CREATE_SKILL_NODE(10352, 52) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10352, 53) // StartPreInput
        CASE_CREATE_SKILL_NODE(10352, 54) // If
        CASE_CREATE_SKILL_NODE(10352, 55) // IsInterruptType
        CASE_CREATE_SKILL_NODE(10352, 56) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10352, 57) // Delay
        CASE_CREATE_SKILL_NODE(10352, 60) // SetBool
        CASE_CREATE_SKILL_NODE(10352, 61) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10352, 62) // Detect
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_10352

SkillLogic* SkillCreator_10352::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //设置变量
    Variable_10352_103521 = logic->getVariables().setVariable<int32_t>("103521", 1);
    Variable_10352_InterruptAnimat = logic->getVariables().setVariable<bool>("InterruptAnimat");
    //创建阶段phase
    auto phase = new SkillPhase_10352(1, logic, 3);
    //设置phase执行器
    phase->setRunPhaseNode(1, 3);
    phase->setRunPhaseNode(2, 5);
    phase->setDetectPhaseNode(3, 49);
    phase->setDetectPhaseNode(3, 62);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_10352::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
