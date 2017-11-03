#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

#include "skill_psnode_comparefloat.h"
#include "skill_psnode_delay.h"
#include "skill_psnode_detect.h"
#include "skill_psnode_endphase.h"
#include "skill_psnode_getlocation.h"
#include "skill_psnode_getrotation.h"
#include "skill_psnode_if.h"
#include "skill_psnode_offsetcalculate.h"
#include "skill_psnode_playanimation.h"
#include "skill_psnode_playeffect.h"
#include "skill_psnode_playsound.h"
#include "skill_psnode_raiseevent.h"
#include "skill_psnode_resetcd.h"
#include "skill_psnode_skillendnotify.h"
#include "skill_psnode_spawnprojectile.h"
#include "skill_psnode_startphase.h"
#include "skill_psnode_stopeffect.h"
#include "skill_psnode_triggerupdate.h"

namespace pvp {

//变量声明
//--------------------------------------------------------------------------------
// SpawnProjectile
//
REGISTER_REGISTER_SKILL_NODE(22065, 26) {
    pnode->resizeTrigger(PhaseNode_SpawnProjectile::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnProjectile>(PhaseNode_SpawnProjectile::TRIGGER_DONE, 37, PhaseNode_SpawnProjectile::FUNC_DO, &PhaseNode_SpawnProjectile::Do);
}

REGISTER_CREATE_SKILL_NODE(22065, 26) {
    auto node26 = GET_SKILL_NODE(26, PhaseNode_SpawnProjectile);
    if (node26 == nullptr) {
        node26 = new PhaseNode_SpawnProjectile(26, phase);
        node26->setDataId(52206);
        node26->setEndPosX(.00f);
        node26->setEndPosY(.00f);
        node26->setEndPosZ(.00f);
        node26->setMaxCount(0);
        CALL_REGISTER_SKILL_NODE(22065, 26, node26)
    }
    if (noInit == true) {
        return node26;
    }
    auto node60 = GET_SKILL_NODE(60, PhaseNode_OffsetCalculate);
    if (node60 != nullptr) node26->setPosX(node60->getOutPosX());
    if (node60 != nullptr) node26->setPosY(node60->getOutPosY());
    if (node60 != nullptr) node26->setPosZ(node60->getOutPosZ());
    if (node60 != nullptr) node26->setRotation(node60->getOutRotation());
    return node26;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(22065, 28) {
}

REGISTER_CREATE_SKILL_NODE(22065, 28) {
    auto node28 = GET_SKILL_NODE(28, PhaseNode_EndPhase);
    if (node28 == nullptr) {
        node28 = new PhaseNode_EndPhase(28, phase);
        node28->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node28->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(22065, 28, node28)
    }
    if (noInit == true) {
        return node28;
    }
    return node28;
}
//--------------------------------------------------------------------------------
// StartPhase
//
REGISTER_REGISTER_SKILL_NODE(22065, 30) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_StartPhase::TRIGGER_START, 75, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_StartPhase::TRIGGER_START, 71, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_StartPhase::TRIGGER_START, 54, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(22065, 30) {
    auto node30 = GET_SKILL_NODE(30, PhaseNode_StartPhase);
    if (node30 == nullptr) {
        node30 = new PhaseNode_StartPhase(30, phase);
        CALL_REGISTER_SKILL_NODE(22065, 30, node30)
    }
    if (noInit == true) {
        return node30;
    }
    return node30;
}
//--------------------------------------------------------------------------------
// TriggerUpdate
//
REGISTER_REGISTER_SKILL_NODE(22065, 32) {
}

REGISTER_CREATE_SKILL_NODE(22065, 32) {
    auto node32 = GET_SKILL_NODE(32, PhaseNode_TriggerUpdate);
    if (node32 == nullptr) {
        node32 = new PhaseNode_TriggerUpdate(32, phase);
        CALL_REGISTER_SKILL_NODE(22065, 32, node32)
    }
    if (noInit == true) {
        return node32;
    }
    return node32;
}
//--------------------------------------------------------------------------------
// SpawnProjectile
//
REGISTER_REGISTER_SKILL_NODE(22065, 37) {
    pnode->resizeTrigger(PhaseNode_SpawnProjectile::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnProjectile>(PhaseNode_SpawnProjectile::TRIGGER_DONE, 38, PhaseNode_SpawnProjectile::FUNC_DO, &PhaseNode_SpawnProjectile::Do);
}

REGISTER_CREATE_SKILL_NODE(22065, 37) {
    auto node37 = GET_SKILL_NODE(37, PhaseNode_SpawnProjectile);
    if (node37 == nullptr) {
        node37 = new PhaseNode_SpawnProjectile(37, phase);
        node37->setDataId(52206);
        node37->setEndPosX(.00f);
        node37->setEndPosY(.00f);
        node37->setEndPosZ(.00f);
        node37->setMaxCount(0);
        CALL_REGISTER_SKILL_NODE(22065, 37, node37)
    }
    if (noInit == true) {
        return node37;
    }
    auto node60 = GET_SKILL_NODE(60, PhaseNode_OffsetCalculate);
    if (node60 != nullptr) node37->setPosX(node60->getOutPosX());
    if (node60 != nullptr) node37->setPosY(node60->getOutPosY());
    if (node60 != nullptr) node37->setPosZ(node60->getOutPosZ());
    if (node60 != nullptr) node37->setRotation(node60->getOutRotation());
    return node37;
}
//--------------------------------------------------------------------------------
// SpawnProjectile
//
REGISTER_REGISTER_SKILL_NODE(22065, 38) {
    pnode->resizeTrigger(PhaseNode_SpawnProjectile::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_SpawnProjectile::TRIGGER_DONE, 67, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(22065, 38) {
    auto node38 = GET_SKILL_NODE(38, PhaseNode_SpawnProjectile);
    if (node38 == nullptr) {
        node38 = new PhaseNode_SpawnProjectile(38, phase);
        node38->setDataId(52206);
        node38->setEndPosX(.00f);
        node38->setEndPosY(.00f);
        node38->setEndPosZ(.00f);
        node38->setMaxCount(0);
        CALL_REGISTER_SKILL_NODE(22065, 38, node38)
    }
    if (noInit == true) {
        return node38;
    }
    auto node60 = GET_SKILL_NODE(60, PhaseNode_OffsetCalculate);
    if (node60 != nullptr) node38->setPosX(node60->getOutPosX());
    if (node60 != nullptr) node38->setPosY(node60->getOutPosY());
    if (node60 != nullptr) node38->setPosZ(node60->getOutPosZ());
    if (node60 != nullptr) node38->setRotation(node60->getOutRotation());
    return node38;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(22065, 54) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_ResetCD::TRIGGER_DONE, 55, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(22065, 54) {
    auto node54 = GET_SKILL_NODE(54, PhaseNode_ResetCD);
    if (node54 == nullptr) {
        node54 = new PhaseNode_ResetCD(54, phase);
        node54->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node54->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node54->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(22065, 54, node54)
    }
    if (noInit == true) {
        return node54;
    }
    return node54;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(22065, 55) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_PlayAnimation::TRIGGER_DONE, 56, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(22065, 55) {
    auto node55 = GET_SKILL_NODE(55, PhaseNode_PlayAnimation);
    if (node55 == nullptr) {
        node55 = new PhaseNode_PlayAnimation(55, phase);
        node55->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node55->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node55->setTarget(0U);
        node55->setAnimation("Skill1S1");
        node55->setParameter("");
        node55->setValue(false);
        CALL_REGISTER_SKILL_NODE(22065, 55, node55)
    }
    if (noInit == true) {
        return node55;
    }
    return node55;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(22065, 56) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlaySound::TRIGGER_DONE, 57, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(22065, 56) {
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
        CALL_REGISTER_SKILL_NODE(22065, 56, node56)
    }
    if (noInit == true) {
        return node56;
    }
    return node56;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22065, 57) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_Delay::TRIGGER_DONE, 58, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(22065, 57) {
    auto node57 = GET_SKILL_NODE(57, PhaseNode_Delay);
    if (node57 == nullptr) {
        node57 = new PhaseNode_Delay(57, phase);
        node57->setTime(.90f);
        CALL_REGISTER_SKILL_NODE(22065, 57, node57)
    }
    if (noInit == true) {
        return node57;
    }
    return node57;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(22065, 58) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetRotation>(PhaseNode_GetLocation::TRIGGER_DONE, 59, PhaseNode_GetRotation::FUNC_DO, &PhaseNode_GetRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(22065, 58) {
    auto node58 = GET_SKILL_NODE(58, PhaseNode_GetLocation);
    if (node58 == nullptr) {
        node58 = new PhaseNode_GetLocation(58, phase);
        node58->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node58->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(22065, 58, node58)
    }
    if (noInit == true) {
        return node58;
    }
    return node58;
}
//--------------------------------------------------------------------------------
// GetRotation
//
REGISTER_REGISTER_SKILL_NODE(22065, 59) {
    pnode->resizeTrigger(PhaseNode_GetRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_OffsetCalculate>(PhaseNode_GetRotation::TRIGGER_DONE, 60, PhaseNode_OffsetCalculate::FUNC_DO, &PhaseNode_OffsetCalculate::Do);
}

REGISTER_CREATE_SKILL_NODE(22065, 59) {
    auto node59 = GET_SKILL_NODE(59, PhaseNode_GetRotation);
    if (node59 == nullptr) {
        node59 = new PhaseNode_GetRotation(59, phase);
        node59->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node59->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(22065, 59, node59)
    }
    if (noInit == true) {
        return node59;
    }
    return node59;
}
//--------------------------------------------------------------------------------
// OffsetCalculate
//
REGISTER_REGISTER_SKILL_NODE(22065, 60) {
    pnode->resizeTrigger(PhaseNode_OffsetCalculate::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 62, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(22065, 60) {
    auto node60 = GET_SKILL_NODE(60, PhaseNode_OffsetCalculate);
    if (node60 == nullptr) {
        node60 = new PhaseNode_OffsetCalculate(60, phase);
        node60->setPosZ(.00f);
        node60->setOffsetX(.93f);
        node60->setOffsetY(1.20f);
        node60->setOffsetZ(3.00f);
        node60->setRotOffset(.00f);
        CALL_REGISTER_SKILL_NODE(22065, 60, node60)
    }
    if (noInit == true) {
        return node60;
    }
    auto node58 = GET_SKILL_NODE(58, PhaseNode_GetLocation);
    auto node59 = GET_SKILL_NODE(59, PhaseNode_GetRotation);
    if (node58 != nullptr) node60->setPosX(node58->getX());
    if (node58 != nullptr) node60->setPosY(node58->getY());
    if (node59 != nullptr) node60->setRotation(node59->getAngle());
    return node60;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(22065, 61) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_PlayEffect::TRIGGER_DONE, 64, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(22065, 61) {
    auto node61 = GET_SKILL_NODE(61, PhaseNode_PlayEffect);
    if (node61 == nullptr) {
        node61 = new PhaseNode_PlayEffect(61, phase);
        node61->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node61->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node61->setEffectID(220712);
        node61->setChangeColor(false);
        node61->setType(PhaseNode_PlayEffect::PlayEffect_Type::WithTarget);
        node61->getVars().reserve(5);
        node61->getVars().setVariable<uint64_t>(0, 0U);
        node61->getVars().setVariable<std::string>(1, "");
        node61->getVars().setVariable<float>(2, .00f);
        node61->getVars().setVariable<float>(3, .00f);
        node61->getVars().setVariable<float>(4, .00f);
        node61->setScale(.00f);
        CALL_REGISTER_SKILL_NODE(22065, 61, node61)
    }
    if (noInit == true) {
        return node61;
    }
    auto node60 = GET_SKILL_NODE(60, PhaseNode_OffsetCalculate);
    if (node60 != nullptr) node61->getVars().setVariable<float>(2, node60->getOutPosX());
    if (node60 != nullptr) node61->getVars().setVariable<float>(3, node60->getOutPosY());
    if (node60 != nullptr) node61->getVars().setVariable<float>(4, node60->getOutPosZ());
    if (node60 != nullptr) node61->setRotation(node60->getOutRotation());
    return node61;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(22065, 62) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_FALSE, 63, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_TRUE, 61, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(22065, 62) {
    auto node62 = GET_SKILL_NODE(62, PhaseNode_If);
    if (node62 == nullptr) {
        node62 = new PhaseNode_If(62, phase);
        node62->setCondition(false);
        CALL_REGISTER_SKILL_NODE(22065, 62, node62)
    }
    if (noInit == true) {
        return node62;
    }
    return node62;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(22065, 63) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_PlayEffect::TRIGGER_DONE, 64, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(22065, 63) {
    auto node63 = GET_SKILL_NODE(63, PhaseNode_PlayEffect);
    if (node63 == nullptr) {
        node63 = new PhaseNode_PlayEffect(63, phase);
        node63->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node63->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node63->setEffectID(220712);
        node63->setChangeColor(false);
        node63->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node63->getVars().reserve(3);
        node63->getVars().setVariable<float>(0, .00f);
        node63->getVars().setVariable<float>(1, .00f);
        node63->getVars().setVariable<float>(2, .00f);
        node63->setScale(.00f);
        CALL_REGISTER_SKILL_NODE(22065, 63, node63)
    }
    if (noInit == true) {
        return node63;
    }
    auto node60 = GET_SKILL_NODE(60, PhaseNode_OffsetCalculate);
    if (node60 != nullptr) node63->getVars().setVariable<float>(0, node60->getOutPosX());
    if (node60 != nullptr) node63->getVars().setVariable<float>(1, node60->getOutPosY());
    if (node60 != nullptr) node63->getVars().setVariable<float>(2, node60->getOutPosZ());
    if (node60 != nullptr) node63->setRotation(node60->getOutRotation());
    return node63;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(22065, 64) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnProjectile>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 26, PhaseNode_SpawnProjectile::FUNC_DO, &PhaseNode_SpawnProjectile::Do);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_LESS, 65, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_SpawnProjectile>(PhaseNode_CompareFloat::TRIGGER_LESS, 26, PhaseNode_SpawnProjectile::FUNC_DO, &PhaseNode_SpawnProjectile::Do);
}

REGISTER_CREATE_SKILL_NODE(22065, 64) {
    auto node64 = GET_SKILL_NODE(64, PhaseNode_CompareFloat);
    if (node64 == nullptr) {
        node64 = new PhaseNode_CompareFloat(64, phase);
        node64->setA(.00f);
        node64->setB(.00f);
        CALL_REGISTER_SKILL_NODE(22065, 64, node64)
    }
    if (noInit == true) {
        return node64;
    }
    return node64;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22065, 65) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StopEffect>(PhaseNode_Delay::TRIGGER_DONE, 66, PhaseNode_StopEffect::FUNC_DO, &PhaseNode_StopEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(22065, 65) {
    auto node65 = GET_SKILL_NODE(65, PhaseNode_Delay);
    if (node65 == nullptr) {
        node65 = new PhaseNode_Delay(65, phase);
        node65->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(22065, 65, node65)
    }
    if (noInit == true) {
        return node65;
    }
    return node65;
}
//--------------------------------------------------------------------------------
// StopEffect
//
REGISTER_REGISTER_SKILL_NODE(22065, 66) {
}

REGISTER_CREATE_SKILL_NODE(22065, 66) {
    auto node66 = GET_SKILL_NODE(66, PhaseNode_StopEffect);
    if (node66 == nullptr) {
        node66 = new PhaseNode_StopEffect(66, phase);
        node66->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node66->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node66->setEffectID(220712);
        CALL_REGISTER_SKILL_NODE(22065, 66, node66)
    }
    if (noInit == true) {
        return node66;
    }
    return node66;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22065, 67) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_Delay::TRIGGER_DONE, 69, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(22065, 67) {
    auto node67 = GET_SKILL_NODE(67, PhaseNode_Delay);
    if (node67 == nullptr) {
        node67 = new PhaseNode_Delay(67, phase);
        node67->setTime(.90f);
        CALL_REGISTER_SKILL_NODE(22065, 67, node67)
    }
    if (noInit == true) {
        return node67;
    }
    return node67;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(22065, 68) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 28, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(22065, 68) {
    auto node68 = GET_SKILL_NODE(68, PhaseNode_SkillEndNotify);
    if (node68 == nullptr) {
        node68 = new PhaseNode_SkillEndNotify(68, phase);
        node68->setReturnType(false);
        CALL_REGISTER_SKILL_NODE(22065, 68, node68)
    }
    if (noInit == true) {
        return node68;
    }
    return node68;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(22065, 69) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_FALSE, 70, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_TRUE, 68, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
}

REGISTER_CREATE_SKILL_NODE(22065, 69) {
    auto node69 = GET_SKILL_NODE(69, PhaseNode_If);
    if (node69 == nullptr) {
        node69 = new PhaseNode_If(69, phase);
        node69->setCondition(false);
        CALL_REGISTER_SKILL_NODE(22065, 69, node69)
    }
    if (noInit == true) {
        return node69;
    }
    return node69;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(22065, 70) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 28, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(22065, 70) {
    auto node70 = GET_SKILL_NODE(70, PhaseNode_SkillEndNotify);
    if (node70 == nullptr) {
        node70 = new PhaseNode_SkillEndNotify(70, phase);
        node70->setReturnType(true);
        CALL_REGISTER_SKILL_NODE(22065, 70, node70)
    }
    if (noInit == true) {
        return node70;
    }
    return node70;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(22065, 71) {
}

REGISTER_CREATE_SKILL_NODE(22065, 71) {
    auto node71 = GET_SKILL_NODE(71, PhaseNode_RaiseEvent);
    if (node71 == nullptr) {
        node71 = new PhaseNode_RaiseEvent(71, phase);
        node71->setEvent("MonsterInterrupt");
        node71->setTarget(0U);
        node71->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node71->setTypeParams(0, 0);
        node71->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(22065, 71, node71)
    }
    if (noInit == true) {
        return node71;
    }
    return node71;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(22065, 72) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_Detect::TRIGGER_ON, 77, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(22065, 72) {
    auto node72 = GET_SKILL_NODE(72, PhaseNode_Detect);
    if (node72 == nullptr) {
        node72 = new PhaseNode_Detect(72, phase);
        node72->setSelf(0U);
        node72->setEvent("MonsterInterrupt");
        node72->setType(PhaseNode_Detect::Detect_Type::Interrupt_Skill);
        node72->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(22065, 72, node72)
    }
    if (noInit == true) {
        return node72;
    }
    return node72;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(22065, 73) {
}

REGISTER_CREATE_SKILL_NODE(22065, 73) {
    auto node73 = GET_SKILL_NODE(73, PhaseNode_EndPhase);
    if (node73 == nullptr) {
        node73 = new PhaseNode_EndPhase(73, phase);
        node73->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node73->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(22065, 73, node73)
    }
    if (noInit == true) {
        return node73;
    }
    return node73;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22065, 75) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_Delay::TRIGGER_DONE, 76, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(22065, 75) {
    auto node75 = GET_SKILL_NODE(75, PhaseNode_Delay);
    if (node75 == nullptr) {
        node75 = new PhaseNode_Delay(75, phase);
        node75->setTime(.90f);
        CALL_REGISTER_SKILL_NODE(22065, 75, node75)
    }
    if (noInit == true) {
        return node75;
    }
    return node75;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(22065, 76) {
}

REGISTER_CREATE_SKILL_NODE(22065, 76) {
    auto node76 = GET_SKILL_NODE(76, PhaseNode_PlaySound);
    if (node76 == nullptr) {
        node76 = new PhaseNode_PlaySound(76, phase);
        node76->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node76->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node76->setSoundID("SE_MON2207_ATK_A_P1");
        node76->setTarget(0U);
        node76->setUsePos(false);
        node76->setPosX(.00f);
        node76->setPosY(.00f);
        node76->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(22065, 76, node76)
    }
    if (noInit == true) {
        return node76;
    }
    return node76;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22065, 77) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_Delay::TRIGGER_DONE, 79, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(22065, 77) {
    auto node77 = GET_SKILL_NODE(77, PhaseNode_Delay);
    if (node77 == nullptr) {
        node77 = new PhaseNode_Delay(77, phase);
        node77->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(22065, 77, node77)
    }
    if (noInit == true) {
        return node77;
    }
    return node77;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(22065, 78) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 73, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(22065, 78) {
    auto node78 = GET_SKILL_NODE(78, PhaseNode_SkillEndNotify);
    if (node78 == nullptr) {
        node78 = new PhaseNode_SkillEndNotify(78, phase);
        node78->setReturnType(false);
        CALL_REGISTER_SKILL_NODE(22065, 78, node78)
    }
    if (noInit == true) {
        return node78;
    }
    return node78;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(22065, 79) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_FALSE, 80, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_TRUE, 78, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
}

REGISTER_CREATE_SKILL_NODE(22065, 79) {
    auto node79 = GET_SKILL_NODE(79, PhaseNode_If);
    if (node79 == nullptr) {
        node79 = new PhaseNode_If(79, phase);
        node79->setCondition(false);
        CALL_REGISTER_SKILL_NODE(22065, 79, node79)
    }
    if (noInit == true) {
        return node79;
    }
    return node79;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(22065, 80) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 73, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(22065, 80) {
    auto node80 = GET_SKILL_NODE(80, PhaseNode_SkillEndNotify);
    if (node80 == nullptr) {
        node80 = new PhaseNode_SkillEndNotify(80, phase);
        node80->setReturnType(true);
        CALL_REGISTER_SKILL_NODE(22065, 80, node80)
    }
    if (noInit == true) {
        return node80;
    }
    return node80;
}

//--------------------------------------------------------------------------------
// SkillCreator_22065
//
class SkillCreator_22065 : public SkillCreator {
public:
    SkillCreator_22065() {}
    virtual ~SkillCreator_22065() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_22065

//--------------------------------------------------------------------------------
// SkillPhase_22065
//
class SkillPhase_22065 : public SkillPhase {
public:
    SkillPhase_22065(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_22065() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(22065, 26) // SpawnProjectile
        CASE_CREATE_SKILL_NODE(22065, 28) // EndPhase
        CASE_CREATE_SKILL_NODE(22065, 30) // StartPhase
        CASE_CREATE_SKILL_NODE(22065, 32) // TriggerUpdate
        CASE_CREATE_SKILL_NODE(22065, 37) // SpawnProjectile
        CASE_CREATE_SKILL_NODE(22065, 38) // SpawnProjectile
        CASE_CREATE_SKILL_NODE(22065, 54) // ResetCD
        CASE_CREATE_SKILL_NODE(22065, 55) // PlayAnimation
        CASE_CREATE_SKILL_NODE(22065, 56) // PlaySound
        CASE_CREATE_SKILL_NODE(22065, 57) // Delay
        CASE_CREATE_SKILL_NODE(22065, 58) // GetLocation
        CASE_CREATE_SKILL_NODE(22065, 59) // GetRotation
        CASE_CREATE_SKILL_NODE(22065, 60) // OffsetCalculate
        CASE_CREATE_SKILL_NODE(22065, 61) // PlayEffect
        CASE_CREATE_SKILL_NODE(22065, 62) // If
        CASE_CREATE_SKILL_NODE(22065, 63) // PlayEffect
        CASE_CREATE_SKILL_NODE(22065, 64) // CompareFloat
        CASE_CREATE_SKILL_NODE(22065, 65) // Delay
        CASE_CREATE_SKILL_NODE(22065, 66) // StopEffect
        CASE_CREATE_SKILL_NODE(22065, 67) // Delay
        CASE_CREATE_SKILL_NODE(22065, 68) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(22065, 69) // If
        CASE_CREATE_SKILL_NODE(22065, 70) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(22065, 71) // RaiseEvent
        CASE_CREATE_SKILL_NODE(22065, 72) // Detect
        CASE_CREATE_SKILL_NODE(22065, 73) // EndPhase
        CASE_CREATE_SKILL_NODE(22065, 75) // Delay
        CASE_CREATE_SKILL_NODE(22065, 76) // PlaySound
        CASE_CREATE_SKILL_NODE(22065, 77) // Delay
        CASE_CREATE_SKILL_NODE(22065, 78) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(22065, 79) // If
        CASE_CREATE_SKILL_NODE(22065, 80) // SkillEndNotify
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_22065

SkillLogic* SkillCreator_22065::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //创建阶段phase
    auto phase = new SkillPhase_22065(1, logic, 3);
    //设置phase执行器
    phase->setRunPhaseNode(1, 30);
    phase->setRunPhaseNode(2, 32);
    phase->setDetectPhaseNode(3, 72);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_22065::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
