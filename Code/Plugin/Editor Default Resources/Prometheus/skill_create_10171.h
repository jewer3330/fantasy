#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

#include "skill_psnode_delay.h"
#include "skill_psnode_detect.h"
#include "skill_psnode_disable.h"
#include "skill_psnode_endphase.h"
#include "skill_psnode_for.h"
#include "skill_psnode_forcontinue.h"
#include "skill_psnode_getactorattribute.h"
#include "skill_psnode_getinputrotation.h"
#include "skill_psnode_getlocation.h"
#include "skill_psnode_if.h"
#include "skill_psnode_int2float.h"
#include "skill_psnode_intoperation.h"
#include "skill_psnode_isinterrupttype.h"
#include "skill_psnode_offsetcalculate.h"
#include "skill_psnode_playanimation.h"
#include "skill_psnode_playeffect.h"
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
uint64_t Variable_10171_a101712 = 0;
uint64_t Variable_10171_InterruptAnimat = 0;
//--------------------------------------------------------------------------------
// StartPhase
//
REGISTER_REGISTER_SKILL_NODE(10171, 4) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Disable>(PhaseNode_StartPhase::TRIGGER_START, 17, PhaseNode_Disable::FUNC_DO, &PhaseNode_Disable::Do);
}

REGISTER_CREATE_SKILL_NODE(10171, 4) {
    auto node4 = GET_SKILL_NODE(4, PhaseNode_StartPhase);
    if (node4 == nullptr) {
        node4 = new PhaseNode_StartPhase(4, phase);
        CALL_REGISTER_SKILL_NODE(10171, 4, node4)
    }
    if (noInit == true) {
        return node4;
    }
    return node4;
}
//--------------------------------------------------------------------------------
// GetInputRotation
//
REGISTER_REGISTER_SKILL_NODE(10171, 11) {
    pnode->resizeTrigger(PhaseNode_GetInputRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_GetInputRotation::TRIGGER_DONE, 19, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(10171, 11) {
    auto node11 = GET_SKILL_NODE(11, PhaseNode_GetInputRotation);
    if (node11 == nullptr) {
        node11 = new PhaseNode_GetInputRotation(11, phase);
        node11->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        CALL_REGISTER_SKILL_NODE(10171, 11, node11)
    }
    if (noInit == true) {
        return node11;
    }
    return node11;
}
//--------------------------------------------------------------------------------
// SpawnProjectile
//
REGISTER_REGISTER_SKILL_NODE(10171, 13) {
    pnode->resizeTrigger(PhaseNode_SpawnProjectile::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ForContinue>(PhaseNode_SpawnProjectile::TRIGGER_DONE, 47, PhaseNode_ForContinue::FUNC_DO, &PhaseNode_ForContinue::Do);
}

REGISTER_CREATE_SKILL_NODE(10171, 13) {
    auto node13 = GET_SKILL_NODE(13, PhaseNode_SpawnProjectile);
    if (node13 == nullptr) {
        node13 = new PhaseNode_SpawnProjectile(13, phase);
        node13->setDataId(55171);
        node13->setEndPosX(.00f);
        node13->setEndPosY(.00f);
        node13->setEndPosZ(.00f);
        node13->setMaxCount(0);
        CALL_REGISTER_SKILL_NODE(10171, 13, node13)
    }
    if (noInit == true) {
        return node13;
    }
    auto node21 = GET_SKILL_NODE(21, PhaseNode_OffsetCalculate);
    if (node21 != nullptr) node13->setPosX(node21->getOutPosX());
    if (node21 != nullptr) node13->setPosY(node21->getOutPosY());
    if (node21 != nullptr) node13->setPosZ(node21->getOutPosZ());
    if (node21 != nullptr) node13->setRotation(node21->getOutRotation());
    return node13;
}
//--------------------------------------------------------------------------------
// Disable
//
REGISTER_REGISTER_SKILL_NODE(10171, 17) {
    pnode->resizeTrigger(PhaseNode_Disable::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_Disable::TRIGGER_DONE, 54, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(10171, 17) {
    auto node17 = GET_SKILL_NODE(17, PhaseNode_Disable);
    if (node17 == nullptr) {
        node17 = new PhaseNode_Disable(17, phase);
        node17->setTarget(0U);
        node17->setMove(true);
        node17->setSkill(true);
        node17->setShoot(true);
        node17->setTime(.58f);
        node17->setRotate(true);
        CALL_REGISTER_SKILL_NODE(10171, 17, node17)
    }
    if (noInit == true) {
        return node17;
    }
    return node17;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(10171, 19) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_For>(PhaseNode_GetLocation::TRIGGER_DONE, 39, PhaseNode_For::FUNC_START, &PhaseNode_For::Start);
    pnode->regTrigger<PhaseNode_OffsetCalculate>(PhaseNode_GetLocation::TRIGGER_DONE, 51, PhaseNode_OffsetCalculate::FUNC_DO, &PhaseNode_OffsetCalculate::Do);
}

REGISTER_CREATE_SKILL_NODE(10171, 19) {
    auto node19 = GET_SKILL_NODE(19, PhaseNode_GetLocation);
    if (node19 == nullptr) {
        node19 = new PhaseNode_GetLocation(19, phase);
        node19->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node19->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(10171, 19, node19)
    }
    if (noInit == true) {
        return node19;
    }
    return node19;
}
//--------------------------------------------------------------------------------
// OffsetCalculate
//
REGISTER_REGISTER_SKILL_NODE(10171, 21) {
    pnode->resizeTrigger(PhaseNode_OffsetCalculate::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnProjectile>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 13, PhaseNode_SpawnProjectile::FUNC_DO, &PhaseNode_SpawnProjectile::Do);
}

REGISTER_CREATE_SKILL_NODE(10171, 21) {
    auto node21 = GET_SKILL_NODE(21, PhaseNode_OffsetCalculate);
    if (node21 == nullptr) {
        node21 = new PhaseNode_OffsetCalculate(21, phase);
        node21->setPosZ(2.25f);
        node21->setOffsetX(.10f);
        node21->setOffsetY(.50f);
        node21->setOffsetZ(.00f);
        CALL_REGISTER_SKILL_NODE(10171, 21, node21)
    }
    if (noInit == true) {
        return node21;
    }
    auto node19 = GET_SKILL_NODE(19, PhaseNode_GetLocation);
    auto node11 = GET_SKILL_NODE(11, PhaseNode_GetInputRotation);
    auto node45 = GET_SKILL_NODE(45, PhaseNode_Int2Float);
    if (node19 != nullptr) node21->setPosX(node19->getX());
    if (node19 != nullptr) node21->setPosY(node19->getY());
    if (node11 != nullptr) node21->setRotation(node11->getAngle());
    if (node45 != nullptr) node21->setRotOffset(node45->getFloat());
    return node21;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10171, 23) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetInputRotation>(PhaseNode_Delay::TRIGGER_DONE, 11, PhaseNode_GetInputRotation::FUNC_DO, &PhaseNode_GetInputRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(10171, 23) {
    auto node23 = GET_SKILL_NODE(23, PhaseNode_Delay);
    if (node23 == nullptr) {
        node23 = new PhaseNode_Delay(23, phase);
        node23->setTime(.21f);
        CALL_REGISTER_SKILL_NODE(10171, 23, node23)
    }
    if (noInit == true) {
        return node23;
    }
    return node23;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(10171, 25) {
}

REGISTER_CREATE_SKILL_NODE(10171, 25) {
    auto node25 = GET_SKILL_NODE(25, PhaseNode_EndPhase);
    if (node25 == nullptr) {
        node25 = new PhaseNode_EndPhase(25, phase);
        node25->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node25->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10171, 25, node25)
    }
    if (noInit == true) {
        return node25;
    }
    return node25;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10171, 27) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_Delay::TRIGGER_DONE, 25, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(10171, 27) {
    auto node27 = GET_SKILL_NODE(27, PhaseNode_Delay);
    if (node27 == nullptr) {
        node27 = new PhaseNode_Delay(27, phase);
        node27->setTime(.42f);
        CALL_REGISTER_SKILL_NODE(10171, 27, node27)
    }
    if (noInit == true) {
        return node27;
    }
    return node27;
}
//--------------------------------------------------------------------------------
// For
//
REGISTER_REGISTER_SKILL_NODE(10171, 39) {
    pnode->resizeTrigger(PhaseNode_For::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_IntOperation>(PhaseNode_For::TRIGGER_DO, 43, PhaseNode_IntOperation::FUNC_OPERATION, &PhaseNode_IntOperation::Operation);
}

REGISTER_CREATE_SKILL_NODE(10171, 39) {
    auto node39 = GET_SKILL_NODE(39, PhaseNode_For);
    if (node39 == nullptr) {
        node39 = new PhaseNode_For(39, phase);
        node39->setBegin(-1);
        node39->setIncrease(1);
        node39->setEnd(2);
        CALL_REGISTER_SKILL_NODE(10171, 39, node39)
    }
    if (noInit == true) {
        return node39;
    }
    return node39;
}
//--------------------------------------------------------------------------------
// IntOperation
//
REGISTER_REGISTER_SKILL_NODE(10171, 43) {
    pnode->resizeTrigger(PhaseNode_IntOperation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Int2Float>(PhaseNode_IntOperation::TRIGGER_DONE, 45, PhaseNode_Int2Float::FUNC_DO, &PhaseNode_Int2Float::Do);
}

REGISTER_CREATE_SKILL_NODE(10171, 43) {
    auto node43 = GET_SKILL_NODE(43, PhaseNode_IntOperation);
    if (node43 == nullptr) {
        node43 = new PhaseNode_IntOperation(43, phase);
        node43->setBase(15);
        node43->setMethod(PhaseNode_IntOperation::IntOperation_Method::Multi);
        CALL_REGISTER_SKILL_NODE(10171, 43, node43)
    }
    if (noInit == true) {
        return node43;
    }
    auto node39 = GET_SKILL_NODE(39, PhaseNode_For);
    if (node39 != nullptr) node43->setValue(node39->getValue());
    return node43;
}
//--------------------------------------------------------------------------------
// Int2Float
//
REGISTER_REGISTER_SKILL_NODE(10171, 45) {
    pnode->resizeTrigger(PhaseNode_Int2Float::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_OffsetCalculate>(PhaseNode_Int2Float::TRIGGER_DONE, 21, PhaseNode_OffsetCalculate::FUNC_DO, &PhaseNode_OffsetCalculate::Do);
}

REGISTER_CREATE_SKILL_NODE(10171, 45) {
    auto node45 = GET_SKILL_NODE(45, PhaseNode_Int2Float);
    if (node45 == nullptr) {
        node45 = new PhaseNode_Int2Float(45, phase);
        CALL_REGISTER_SKILL_NODE(10171, 45, node45)
    }
    if (noInit == true) {
        return node45;
    }
    auto node43 = GET_SKILL_NODE(43, PhaseNode_IntOperation);
    if (node43 != nullptr) node45->setInt(node43->getFinal());
    return node45;
}
//--------------------------------------------------------------------------------
// ForContinue
//
REGISTER_REGISTER_SKILL_NODE(10171, 47) {
}

REGISTER_CREATE_SKILL_NODE(10171, 47) {
    auto node47 = GET_SKILL_NODE(47, PhaseNode_ForContinue);
    if (node47 == nullptr) {
        node47 = new PhaseNode_ForContinue(47, phase);
        CALL_REGISTER_SKILL_NODE(10171, 47, node47)
    }
    if (noInit == true) {
        return node47;
    }
    auto node39 = GET_SKILL_NODE(39, PhaseNode_For);
    if (node39 != nullptr) node47->setFID(node39->getFID());
    return node47;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(10171, 49) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlayEffect::TRIGGER_DONE, 27, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10171, 49) {
    auto node49 = GET_SKILL_NODE(49, PhaseNode_PlayEffect);
    if (node49 == nullptr) {
        node49 = new PhaseNode_PlayEffect(49, phase);
        node49->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node49->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node49->setEffectID(101711);
        node49->setChangeColor(false);
        node49->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node49->getVars().reserve(3);
        node49->getVars().setVariable<float>(0, .00f);
        node49->getVars().setVariable<float>(1, .00f);
        node49->getVars().setVariable<float>(2, .00f);
        node49->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(10171, 49, node49)
    }
    if (noInit == true) {
        return node49;
    }
    auto node51 = GET_SKILL_NODE(51, PhaseNode_OffsetCalculate);
    auto node11 = GET_SKILL_NODE(11, PhaseNode_GetInputRotation);
    if (node51 != nullptr) node49->getVars().setVariable<float>(0, node51->getOutPosX());
    if (node51 != nullptr) node49->getVars().setVariable<float>(1, node51->getOutPosY());
    if (node51 != nullptr) node49->getVars().setVariable<float>(2, node51->getOutPosZ());
    if (node11 != nullptr) node49->setRotation(node11->getAngle());
    return node49;
}
//--------------------------------------------------------------------------------
// OffsetCalculate
//
REGISTER_REGISTER_SKILL_NODE(10171, 51) {
    pnode->resizeTrigger(PhaseNode_OffsetCalculate::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 49, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(10171, 51) {
    auto node51 = GET_SKILL_NODE(51, PhaseNode_OffsetCalculate);
    if (node51 == nullptr) {
        node51 = new PhaseNode_OffsetCalculate(51, phase);
        node51->setPosZ(2.25f);
        node51->setOffsetX(.29f);
        node51->setOffsetY(1.45f);
        node51->setOffsetZ(.00f);
        node51->setRotOffset(.00f);
        CALL_REGISTER_SKILL_NODE(10171, 51, node51)
    }
    if (noInit == true) {
        return node51;
    }
    auto node19 = GET_SKILL_NODE(19, PhaseNode_GetLocation);
    auto node11 = GET_SKILL_NODE(11, PhaseNode_GetInputRotation);
    if (node19 != nullptr) node51->setPosX(node19->getX());
    if (node19 != nullptr) node51->setPosY(node19->getY());
    if (node11 != nullptr) node51->setRotation(node11->getAngle());
    return node51;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10171, 53) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_PlaySound::TRIGGER_DONE, 62, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10171, 53) {
    auto node53 = GET_SKILL_NODE(53, PhaseNode_PlaySound);
    if (node53 == nullptr) {
        node53 = new PhaseNode_PlaySound(53, phase);
        node53->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node53->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node53->setSoundID("SE_Hero114_SkillA");
        node53->setTarget(0U);
        node53->setUsePos(false);
        node53->setPosX(.00f);
        node53->setPosY(.00f);
        node53->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10171, 53, node53)
    }
    if (noInit == true) {
        return node53;
    }
    return node53;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(10171, 54) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_ResetCD::TRIGGER_DONE, 55, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10171, 54) {
    auto node54 = GET_SKILL_NODE(54, PhaseNode_ResetCD);
    if (node54 == nullptr) {
        node54 = new PhaseNode_ResetCD(54, phase);
        node54->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node54->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node54->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(10171, 54, node54)
    }
    if (noInit == true) {
        return node54;
    }
    return node54;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10171, 55) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_PlayAnimation::TRIGGER_DONE, 57, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(10171, 55) {
    auto node55 = GET_SKILL_NODE(55, PhaseNode_PlayAnimation);
    if (node55 == nullptr) {
        node55 = new PhaseNode_PlayAnimation(55, phase);
        node55->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node55->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node55->setTarget(0U);
        node55->setAnimation("Skill1S1");
        node55->setParameter("");
        node55->setValue(false);
        CALL_REGISTER_SKILL_NODE(10171, 55, node55)
    }
    if (noInit == true) {
        return node55;
    }
    return node55;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10171, 56) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_PlaySound::TRIGGER_DONE, 53, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10171, 56) {
    auto node56 = GET_SKILL_NODE(56, PhaseNode_PlaySound);
    if (node56 == nullptr) {
        node56 = new PhaseNode_PlaySound(56, phase);
        node56->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node56->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node56->setSoundID("");
        node56->setTarget(0U);
        node56->setUsePos(false);
        node56->setPosX(.00f);
        node56->setPosY(.00f);
        node56->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10171, 56, node56)
    }
    if (noInit == true) {
        return node56;
    }
    return node56;
}
//--------------------------------------------------------------------------------
// GetActorAttribute
//
REGISTER_REGISTER_SKILL_NODE(10171, 57) {
    pnode->resizeTrigger(PhaseNode_GetActorAttribute::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 56, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10171, 57) {
    auto node57 = GET_SKILL_NODE(57, PhaseNode_GetActorAttribute);
    if (node57 == nullptr) {
        node57 = new PhaseNode_GetActorAttribute(57, phase);
        node57->setTarget(0U);
        node57->setType({});
        CALL_REGISTER_SKILL_NODE(10171, 57, node57)
    }
    if (noInit == true) {
        return node57;
    }
    return node57;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10171, 59) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_IsInterruptType>(PhaseNode_Detect::TRIGGER_ON, 65, PhaseNode_IsInterruptType::FUNC_DO, &PhaseNode_IsInterruptType::Do);
}

REGISTER_CREATE_SKILL_NODE(10171, 59) {
    auto node59 = GET_SKILL_NODE(59, PhaseNode_Detect);
    if (node59 == nullptr) {
        node59 = new PhaseNode_Detect(59, phase);
        node59->setSelf(0U);
        node59->setEvent("daduan_001");
        node59->setType(PhaseNode_Detect::Detect_Type::Interrupt_Skill);
        node59->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10171, 59, node59)
    }
    if (noInit == true) {
        return node59;
    }
    return node59;
}
//--------------------------------------------------------------------------------
// SwitchToInt
//
REGISTER_REGISTER_SKILL_NODE(10171, 60) {
    pnode->resizeTrigger(4);
    pnode->regTrigger<PhaseNode_EndPhase>(1, 25, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(10171, 60) {
    auto node60 = GET_SKILL_NODE(60, PhaseNode_SwitchToInt);
    if (node60 == nullptr) {
        node60 = new PhaseNode_SwitchToInt(60, phase);
        CALL_REGISTER_SKILL_NODE(10171, 60, node60)
    }
    if (noInit == true) {
        return node60;
    }
    auto variables = node60->getVariables();
    if (variables != nullptr) {
        node60->setSelection(variables->getVariable<int32_t>(Variable_10171_a101712));
    }
    return node60;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10171, 62) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_RaiseEvent::TRIGGER_DONE, 71, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10171, 62) {
    auto node62 = GET_SKILL_NODE(62, PhaseNode_RaiseEvent);
    if (node62 == nullptr) {
        node62 = new PhaseNode_RaiseEvent(62, phase);
        node62->setEvent("daduan_001");
        node62->setTarget(0U);
        node62->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node62->setTypeParams(0, 0);
        node62->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10171, 62, node62)
    }
    if (noInit == true) {
        return node62;
    }
    return node62;
}
//--------------------------------------------------------------------------------
// StartPreInput
//
REGISTER_REGISTER_SKILL_NODE(10171, 63) {
    pnode->resizeTrigger(PhaseNode_StartPreInput::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_StartPreInput::TRIGGER_DONE, 23, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_StartPreInput::TRIGGER_DONE, 67, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10171, 63) {
    auto node63 = GET_SKILL_NODE(63, PhaseNode_StartPreInput);
    if (node63 == nullptr) {
        node63 = new PhaseNode_StartPreInput(63, phase);
        node63->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node63->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node63->setDelayTime(.00f);
        CALL_REGISTER_SKILL_NODE(10171, 63, node63)
    }
    if (noInit == true) {
        return node63;
    }
    return node63;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(10171, 64) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_If::TRIGGER_TRUE, 66, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10171, 64) {
    auto node64 = GET_SKILL_NODE(64, PhaseNode_If);
    if (node64 == nullptr) {
        node64 = new PhaseNode_If(64, phase);
        CALL_REGISTER_SKILL_NODE(10171, 64, node64)
    }
    if (noInit == true) {
        return node64;
    }
    auto variables = node64->getVariables();
    if (variables != nullptr) {
        node64->setCondition(variables->getVariable<bool>(Variable_10171_InterruptAnimat));
    }
    return node64;
}
//--------------------------------------------------------------------------------
// IsInterruptType
//
REGISTER_REGISTER_SKILL_NODE(10171, 65) {
    pnode->resizeTrigger(PhaseNode_IsInterruptType::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SwitchToInt>(PhaseNode_IsInterruptType::TRIGGER_BUFF, 60, PhaseNode_SwitchToInt::FUNC_SWITCH, &PhaseNode_SwitchToInt::Switch);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_POSCHANGE, 64, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTAIM, 64, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTFIRE, 64, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTRELOAD, 64, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_USESKILL, 64, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(10171, 65) {
    auto node65 = GET_SKILL_NODE(65, PhaseNode_IsInterruptType);
    if (node65 == nullptr) {
        node65 = new PhaseNode_IsInterruptType(65, phase);
        node65->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node65->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10171, 65, node65)
    }
    if (noInit == true) {
        return node65;
    }
    auto node59 = GET_SKILL_NODE(59, PhaseNode_Detect);
    if (node59 != nullptr) node65->setType(node59->getVars().getVariable<int32_t>(2));
    return node65;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10171, 66) {
}

REGISTER_CREATE_SKILL_NODE(10171, 66) {
    auto node66 = GET_SKILL_NODE(66, PhaseNode_PlayAnimation);
    if (node66 == nullptr) {
        node66 = new PhaseNode_PlayAnimation(66, phase);
        node66->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node66->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node66->setTarget(0U);
        node66->setAnimation("Idle");
        node66->setParameter("");
        node66->setValue(false);
        CALL_REGISTER_SKILL_NODE(10171, 66, node66)
    }
    if (noInit == true) {
        return node66;
    }
    return node66;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10171, 67) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_Delay::TRIGGER_DONE, 70, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(10171, 67) {
    auto node67 = GET_SKILL_NODE(67, PhaseNode_Delay);
    if (node67 == nullptr) {
        node67 = new PhaseNode_Delay(67, phase);
        node67->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(10171, 67, node67)
    }
    if (noInit == true) {
        return node67;
    }
    return node67;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(10171, 70) {
}

REGISTER_CREATE_SKILL_NODE(10171, 70) {
    auto node70 = GET_SKILL_NODE(70, PhaseNode_SetBool);
    if (node70 == nullptr) {
        node70 = new PhaseNode_SetBool(70, phase);
        node70->setName("InterruptAnimat");
        node70->setValue(true);
        CALL_REGISTER_SKILL_NODE(10171, 70, node70)
    }
    if (noInit == true) {
        return node70;
    }
    return node70;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10171, 71) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StartPreInput>(PhaseNode_RaiseEvent::TRIGGER_DONE, 63, PhaseNode_StartPreInput::FUNC_DO, &PhaseNode_StartPreInput::Do);
}

REGISTER_CREATE_SKILL_NODE(10171, 71) {
    auto node71 = GET_SKILL_NODE(71, PhaseNode_RaiseEvent);
    if (node71 == nullptr) {
        node71 = new PhaseNode_RaiseEvent(71, phase);
        node71->setEvent("Dead_001");
        node71->setTarget(0U);
        node71->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node71->setTypeParams(0, 0);
        node71->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10171, 71, node71)
    }
    if (noInit == true) {
        return node71;
    }
    return node71;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10171, 72) {
}

REGISTER_CREATE_SKILL_NODE(10171, 72) {
    auto node72 = GET_SKILL_NODE(72, PhaseNode_Detect);
    if (node72 == nullptr) {
        node72 = new PhaseNode_Detect(72, phase);
        node72->setSelf(0U);
        node72->setEvent("Dead_001");
        node72->setType(PhaseNode_Detect::Detect_Type::Actor_Dead);
        node72->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10171, 72, node72)
    }
    if (noInit == true) {
        return node72;
    }
    return node72;
}

//--------------------------------------------------------------------------------
// SkillCreator_10171
//
class SkillCreator_10171 : public SkillCreator {
public:
    SkillCreator_10171() {}
    virtual ~SkillCreator_10171() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_10171

//--------------------------------------------------------------------------------
// SkillPhase_10171
//
class SkillPhase_10171 : public SkillPhase {
public:
    SkillPhase_10171(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_10171() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(10171, 4) // StartPhase
        CASE_CREATE_SKILL_NODE(10171, 11) // GetInputRotation
        CASE_CREATE_SKILL_NODE(10171, 13) // SpawnProjectile
        CASE_CREATE_SKILL_NODE(10171, 17) // Disable
        CASE_CREATE_SKILL_NODE(10171, 19) // GetLocation
        CASE_CREATE_SKILL_NODE(10171, 21) // OffsetCalculate
        CASE_CREATE_SKILL_NODE(10171, 23) // Delay
        CASE_CREATE_SKILL_NODE(10171, 25) // EndPhase
        CASE_CREATE_SKILL_NODE(10171, 27) // Delay
        CASE_CREATE_SKILL_NODE(10171, 39) // For
        CASE_CREATE_SKILL_NODE(10171, 43) // IntOperation
        CASE_CREATE_SKILL_NODE(10171, 45) // Int2Float
        CASE_CREATE_SKILL_NODE(10171, 47) // ForContinue
        CASE_CREATE_SKILL_NODE(10171, 49) // PlayEffect
        CASE_CREATE_SKILL_NODE(10171, 51) // OffsetCalculate
        CASE_CREATE_SKILL_NODE(10171, 53) // PlaySound
        CASE_CREATE_SKILL_NODE(10171, 54) // ResetCD
        CASE_CREATE_SKILL_NODE(10171, 55) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10171, 56) // PlaySound
        CASE_CREATE_SKILL_NODE(10171, 57) // GetActorAttribute
        CASE_CREATE_SKILL_NODE(10171, 59) // Detect
        CASE_CREATE_SKILL_NODE(10171, 60) // SwitchToInt
        CASE_CREATE_SKILL_NODE(10171, 62) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10171, 63) // StartPreInput
        CASE_CREATE_SKILL_NODE(10171, 64) // If
        CASE_CREATE_SKILL_NODE(10171, 65) // IsInterruptType
        CASE_CREATE_SKILL_NODE(10171, 66) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10171, 67) // Delay
        CASE_CREATE_SKILL_NODE(10171, 70) // SetBool
        CASE_CREATE_SKILL_NODE(10171, 71) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10171, 72) // Detect
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_10171

SkillLogic* SkillCreator_10171::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //设置变量
    Variable_10171_a101712 = logic->getVariables().setVariable<int32_t>("a101712", 1);
    Variable_10171_InterruptAnimat = logic->getVariables().setVariable<bool>("InterruptAnimat");
    //创建阶段phase
    auto phase = new SkillPhase_10171(1, logic, 2);
    //设置phase执行器
    phase->setRunPhaseNode(1, 4);
    phase->setDetectPhaseNode(2, 59);
    phase->setDetectPhaseNode(2, 72);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_10171::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
