#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

#include "skill_psnode_delay.h"
#include "skill_psnode_detect.h"
#include "skill_psnode_endphase.h"
#include "skill_psnode_floatoperation.h"
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
#include "skill_psnode_triggerupdate.h"

namespace pvp {

//变量声明
//--------------------------------------------------------------------------------
// StartPhase
//
REGISTER_REGISTER_SKILL_NODE(21062, 2) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_StartPhase::TRIGGER_START, 178, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_StartPhase::TRIGGER_START, 171, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(21062, 2) {
    auto node2 = GET_SKILL_NODE(2, PhaseNode_StartPhase);
    if (node2 == nullptr) {
        node2 = new PhaseNode_StartPhase(2, phase);
        CALL_REGISTER_SKILL_NODE(21062, 2, node2)
    }
    if (noInit == true) {
        return node2;
    }
    return node2;
}
//--------------------------------------------------------------------------------
// TriggerUpdate
//
REGISTER_REGISTER_SKILL_NODE(21062, 4) {
}

REGISTER_CREATE_SKILL_NODE(21062, 4) {
    auto node4 = GET_SKILL_NODE(4, PhaseNode_TriggerUpdate);
    if (node4 == nullptr) {
        node4 = new PhaseNode_TriggerUpdate(4, phase);
        CALL_REGISTER_SKILL_NODE(21062, 4, node4)
    }
    if (noInit == true) {
        return node4;
    }
    return node4;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(21062, 28) {
}

REGISTER_CREATE_SKILL_NODE(21062, 28) {
    auto node28 = GET_SKILL_NODE(28, PhaseNode_EndPhase);
    if (node28 == nullptr) {
        node28 = new PhaseNode_EndPhase(28, phase);
        node28->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node28->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(21062, 28, node28)
    }
    if (noInit == true) {
        return node28;
    }
    return node28;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(21062, 30) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_Delay::TRIGGER_DONE, 62, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(21062, 30) {
    auto node30 = GET_SKILL_NODE(30, PhaseNode_Delay);
    if (node30 == nullptr) {
        node30 = new PhaseNode_Delay(30, phase);
        node30->setTime(1.00f);
        CALL_REGISTER_SKILL_NODE(21062, 30, node30)
    }
    if (noInit == true) {
        return node30;
    }
    return node30;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(21062, 62) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlayAnimation::TRIGGER_DONE, 67, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(21062, 62) {
    auto node62 = GET_SKILL_NODE(62, PhaseNode_PlayAnimation);
    if (node62 == nullptr) {
        node62 = new PhaseNode_PlayAnimation(62, phase);
        node62->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node62->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node62->setTarget(0U);
        node62->setAnimation("Skill2S2");
        node62->setParameter("");
        node62->setValue(false);
        CALL_REGISTER_SKILL_NODE(21062, 62, node62)
    }
    if (noInit == true) {
        return node62;
    }
    return node62;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(21062, 64) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlayAnimation::TRIGGER_DONE, 167, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(21062, 64) {
    auto node64 = GET_SKILL_NODE(64, PhaseNode_PlayAnimation);
    if (node64 == nullptr) {
        node64 = new PhaseNode_PlayAnimation(64, phase);
        node64->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node64->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node64->setTarget(0U);
        node64->setAnimation("Skill2S3");
        node64->setParameter("");
        node64->setValue(false);
        CALL_REGISTER_SKILL_NODE(21062, 64, node64)
    }
    if (noInit == true) {
        return node64;
    }
    return node64;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(21062, 67) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_FloatOperation>(PhaseNode_Delay::TRIGGER_DONE, 102, PhaseNode_FloatOperation::FUNC_OPERATION, &PhaseNode_FloatOperation::Operation);
}

REGISTER_CREATE_SKILL_NODE(21062, 67) {
    auto node67 = GET_SKILL_NODE(67, PhaseNode_Delay);
    if (node67 == nullptr) {
        node67 = new PhaseNode_Delay(67, phase);
        node67->setTime(.20f);
        CALL_REGISTER_SKILL_NODE(21062, 67, node67)
    }
    if (noInit == true) {
        return node67;
    }
    return node67;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(21062, 71) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_Delay::TRIGGER_DONE, 64, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(21062, 71) {
    auto node71 = GET_SKILL_NODE(71, PhaseNode_Delay);
    if (node71 == nullptr) {
        node71 = new PhaseNode_Delay(71, phase);
        node71->setTime(.20f);
        CALL_REGISTER_SKILL_NODE(21062, 71, node71)
    }
    if (noInit == true) {
        return node71;
    }
    return node71;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(21062, 79) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_Detect::TRIGGER_ON, 81, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(21062, 79) {
    auto node79 = GET_SKILL_NODE(79, PhaseNode_Detect);
    if (node79 == nullptr) {
        node79 = new PhaseNode_Detect(79, phase);
        node79->setSelf(0U);
        node79->setEvent("");
        node79->setType(PhaseNode_Detect::Detect_Type::Actor_Dead);
        node79->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(21062, 79, node79)
    }
    if (noInit == true) {
        return node79;
    }
    return node79;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(21062, 81) {
}

REGISTER_CREATE_SKILL_NODE(21062, 81) {
    auto node81 = GET_SKILL_NODE(81, PhaseNode_EndPhase);
    if (node81 == nullptr) {
        node81 = new PhaseNode_EndPhase(81, phase);
        node81->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node81->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(21062, 81, node81)
    }
    if (noInit == true) {
        return node81;
    }
    return node81;
}
//--------------------------------------------------------------------------------
// FloatOperation
//
REGISTER_REGISTER_SKILL_NODE(21062, 102) {
    pnode->resizeTrigger(PhaseNode_FloatOperation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_FloatOperation>(PhaseNode_FloatOperation::TRIGGER_DONE, 104, PhaseNode_FloatOperation::FUNC_OPERATION, &PhaseNode_FloatOperation::Operation);
}

REGISTER_CREATE_SKILL_NODE(21062, 102) {
    auto node102 = GET_SKILL_NODE(102, PhaseNode_FloatOperation);
    if (node102 == nullptr) {
        node102 = new PhaseNode_FloatOperation(102, phase);
        node102->setValue(30.00f);
        node102->setMethod(PhaseNode_FloatOperation::FloatOperation_Method::Add);
        CALL_REGISTER_SKILL_NODE(21062, 102, node102)
    }
    if (noInit == true) {
        return node102;
    }
    auto node177 = GET_SKILL_NODE(177, PhaseNode_OffsetCalculate);
    if (node177 != nullptr) node102->setBase(node177->getOutRotation());
    return node102;
}
//--------------------------------------------------------------------------------
// FloatOperation
//
REGISTER_REGISTER_SKILL_NODE(21062, 104) {
    pnode->resizeTrigger(PhaseNode_FloatOperation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnProjectile>(PhaseNode_FloatOperation::TRIGGER_DONE, 106, PhaseNode_SpawnProjectile::FUNC_DO, &PhaseNode_SpawnProjectile::Do);
}

REGISTER_CREATE_SKILL_NODE(21062, 104) {
    auto node104 = GET_SKILL_NODE(104, PhaseNode_FloatOperation);
    if (node104 == nullptr) {
        node104 = new PhaseNode_FloatOperation(104, phase);
        node104->setValue(30.00f);
        node104->setMethod(PhaseNode_FloatOperation::FloatOperation_Method::Sub);
        CALL_REGISTER_SKILL_NODE(21062, 104, node104)
    }
    if (noInit == true) {
        return node104;
    }
    auto node177 = GET_SKILL_NODE(177, PhaseNode_OffsetCalculate);
    if (node177 != nullptr) node104->setBase(node177->getOutRotation());
    return node104;
}
//--------------------------------------------------------------------------------
// SpawnProjectile
//
REGISTER_REGISTER_SKILL_NODE(21062, 106) {
    pnode->resizeTrigger(PhaseNode_SpawnProjectile::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_SpawnProjectile::TRIGGER_DONE, 137, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(21062, 106) {
    auto node106 = GET_SKILL_NODE(106, PhaseNode_SpawnProjectile);
    if (node106 == nullptr) {
        node106 = new PhaseNode_SpawnProjectile(106, phase);
        node106->setDataId(52106);
        node106->setEndPosX(.00f);
        node106->setEndPosY(.00f);
        node106->setEndPosZ(.00f);
        node106->setMaxCount(0);
        CALL_REGISTER_SKILL_NODE(21062, 106, node106)
    }
    if (noInit == true) {
        return node106;
    }
    auto node177 = GET_SKILL_NODE(177, PhaseNode_OffsetCalculate);
    auto node102 = GET_SKILL_NODE(102, PhaseNode_FloatOperation);
    if (node177 != nullptr) node106->setPosX(node177->getOutPosX());
    if (node177 != nullptr) node106->setPosY(node177->getOutPosY());
    if (node177 != nullptr) node106->setPosZ(node177->getOutPosZ());
    if (node102 != nullptr) node106->setRotation(node102->getFinal());
    return node106;
}
//--------------------------------------------------------------------------------
// SpawnProjectile
//
REGISTER_REGISTER_SKILL_NODE(21062, 107) {
    pnode->resizeTrigger(PhaseNode_SpawnProjectile::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_SpawnProjectile::TRIGGER_DONE, 71, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(21062, 107) {
    auto node107 = GET_SKILL_NODE(107, PhaseNode_SpawnProjectile);
    if (node107 == nullptr) {
        node107 = new PhaseNode_SpawnProjectile(107, phase);
        node107->setDataId(52106);
        node107->setEndPosX(.00f);
        node107->setEndPosY(.00f);
        node107->setEndPosZ(.00f);
        node107->setMaxCount(0);
        CALL_REGISTER_SKILL_NODE(21062, 107, node107)
    }
    if (noInit == true) {
        return node107;
    }
    auto node177 = GET_SKILL_NODE(177, PhaseNode_OffsetCalculate);
    auto node104 = GET_SKILL_NODE(104, PhaseNode_FloatOperation);
    if (node177 != nullptr) node107->setPosX(node177->getOutPosX());
    if (node177 != nullptr) node107->setPosY(node177->getOutPosY());
    if (node177 != nullptr) node107->setPosZ(node177->getOutPosZ());
    if (node104 != nullptr) node107->setRotation(node104->getFinal());
    return node107;
}
//--------------------------------------------------------------------------------
// SpawnProjectile
//
REGISTER_REGISTER_SKILL_NODE(21062, 123) {
    pnode->resizeTrigger(PhaseNode_SpawnProjectile::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnProjectile>(PhaseNode_SpawnProjectile::TRIGGER_DONE, 107, PhaseNode_SpawnProjectile::FUNC_DO, &PhaseNode_SpawnProjectile::Do);
}

REGISTER_CREATE_SKILL_NODE(21062, 123) {
    auto node123 = GET_SKILL_NODE(123, PhaseNode_SpawnProjectile);
    if (node123 == nullptr) {
        node123 = new PhaseNode_SpawnProjectile(123, phase);
        node123->setDataId(52106);
        node123->setEndPosX(.00f);
        node123->setEndPosY(.00f);
        node123->setEndPosZ(.00f);
        node123->setMaxCount(0);
        CALL_REGISTER_SKILL_NODE(21062, 123, node123)
    }
    if (noInit == true) {
        return node123;
    }
    auto node177 = GET_SKILL_NODE(177, PhaseNode_OffsetCalculate);
    if (node177 != nullptr) node123->setPosX(node177->getOutPosX());
    if (node177 != nullptr) node123->setPosY(node177->getOutPosY());
    if (node177 != nullptr) node123->setPosZ(node177->getOutPosZ());
    if (node177 != nullptr) node123->setRotation(node177->getOutRotation());
    return node123;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(21062, 137) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnProjectile>(PhaseNode_PlaySound::TRIGGER_DONE, 123, PhaseNode_SpawnProjectile::FUNC_DO, &PhaseNode_SpawnProjectile::Do);
}

REGISTER_CREATE_SKILL_NODE(21062, 137) {
    auto node137 = GET_SKILL_NODE(137, PhaseNode_PlaySound);
    if (node137 == nullptr) {
        node137 = new PhaseNode_PlaySound(137, phase);
        node137->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node137->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node137->setSoundID("SE_Boss2106_ATK3_P2");
        node137->setTarget(0U);
        node137->setUsePos(false);
        node137->setPosX(.00f);
        node137->setPosY(.00f);
        node137->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(21062, 137, node137)
    }
    if (noInit == true) {
        return node137;
    }
    return node137;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(21062, 166) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_PlayEffect::TRIGGER_DONE, 175, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(21062, 166) {
    auto node166 = GET_SKILL_NODE(166, PhaseNode_PlayEffect);
    if (node166 == nullptr) {
        node166 = new PhaseNode_PlayEffect(166, phase);
        node166->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node166->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node166->setEffectID(210621);
        node166->setChangeColor(false);
        node166->setType(PhaseNode_PlayEffect::PlayEffect_Type::WithTarget);
        node166->getVars().reserve(6);
        node166->getVars().setVariable<uint64_t>(0, 0U);
        node166->getVars().setVariable<std::string>(1, "Bone001");
        node166->getVars().setVariable<float>(2, .00f);
        node166->getVars().setVariable<float>(3, .00f);
        node166->getVars().setVariable<float>(4, .00f);
        node166->getVars().setVariable<bool>(5, false);
        node166->setRotation(.00f);
        node166->setScale(.00f);
        CALL_REGISTER_SKILL_NODE(21062, 166, node166)
    }
    if (noInit == true) {
        return node166;
    }
    return node166;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(21062, 167) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_Delay::TRIGGER_DONE, 169, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(21062, 167) {
    auto node167 = GET_SKILL_NODE(167, PhaseNode_Delay);
    if (node167 == nullptr) {
        node167 = new PhaseNode_Delay(167, phase);
        node167->setTime(.30f);
        CALL_REGISTER_SKILL_NODE(21062, 167, node167)
    }
    if (noInit == true) {
        return node167;
    }
    return node167;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(21062, 168) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 28, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(21062, 168) {
    auto node168 = GET_SKILL_NODE(168, PhaseNode_SkillEndNotify);
    if (node168 == nullptr) {
        node168 = new PhaseNode_SkillEndNotify(168, phase);
        node168->setReturnType(false);
        CALL_REGISTER_SKILL_NODE(21062, 168, node168)
    }
    if (noInit == true) {
        return node168;
    }
    return node168;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(21062, 169) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_FALSE, 170, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_TRUE, 168, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
}

REGISTER_CREATE_SKILL_NODE(21062, 169) {
    auto node169 = GET_SKILL_NODE(169, PhaseNode_If);
    if (node169 == nullptr) {
        node169 = new PhaseNode_If(169, phase);
        node169->setCondition(false);
        CALL_REGISTER_SKILL_NODE(21062, 169, node169)
    }
    if (noInit == true) {
        return node169;
    }
    return node169;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(21062, 170) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 28, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(21062, 170) {
    auto node170 = GET_SKILL_NODE(170, PhaseNode_SkillEndNotify);
    if (node170 == nullptr) {
        node170 = new PhaseNode_SkillEndNotify(170, phase);
        node170->setReturnType(true);
        CALL_REGISTER_SKILL_NODE(21062, 170, node170)
    }
    if (noInit == true) {
        return node170;
    }
    return node170;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(21062, 171) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_ResetCD::TRIGGER_DONE, 172, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(21062, 171) {
    auto node171 = GET_SKILL_NODE(171, PhaseNode_ResetCD);
    if (node171 == nullptr) {
        node171 = new PhaseNode_ResetCD(171, phase);
        node171->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node171->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node171->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(21062, 171, node171)
    }
    if (noInit == true) {
        return node171;
    }
    return node171;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(21062, 172) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_PlayAnimation::TRIGGER_DONE, 173, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(21062, 172) {
    auto node172 = GET_SKILL_NODE(172, PhaseNode_PlayAnimation);
    if (node172 == nullptr) {
        node172 = new PhaseNode_PlayAnimation(172, phase);
        node172->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node172->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node172->setTarget(0U);
        node172->setAnimation("Skill2S1");
        node172->setParameter("");
        node172->setValue(false);
        CALL_REGISTER_SKILL_NODE(21062, 172, node172)
    }
    if (noInit == true) {
        return node172;
    }
    return node172;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(21062, 173) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlaySound::TRIGGER_DONE, 174, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(21062, 173) {
    auto node173 = GET_SKILL_NODE(173, PhaseNode_PlaySound);
    if (node173 == nullptr) {
        node173 = new PhaseNode_PlaySound(173, phase);
        node173->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node173->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node173->setSoundID("SE_Boss2106_ATK3_P1");
        node173->setTarget(0U);
        node173->setUsePos(false);
        node173->setPosX(.00f);
        node173->setPosY(.00f);
        node173->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(21062, 173, node173)
    }
    if (noInit == true) {
        return node173;
    }
    return node173;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(21062, 174) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_Delay::TRIGGER_DONE, 166, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(21062, 174) {
    auto node174 = GET_SKILL_NODE(174, PhaseNode_Delay);
    if (node174 == nullptr) {
        node174 = new PhaseNode_Delay(174, phase);
        node174->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(21062, 174, node174)
    }
    if (noInit == true) {
        return node174;
    }
    return node174;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(21062, 175) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetRotation>(PhaseNode_GetLocation::TRIGGER_DONE, 176, PhaseNode_GetRotation::FUNC_DO, &PhaseNode_GetRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(21062, 175) {
    auto node175 = GET_SKILL_NODE(175, PhaseNode_GetLocation);
    if (node175 == nullptr) {
        node175 = new PhaseNode_GetLocation(175, phase);
        node175->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node175->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(21062, 175, node175)
    }
    if (noInit == true) {
        return node175;
    }
    return node175;
}
//--------------------------------------------------------------------------------
// GetRotation
//
REGISTER_REGISTER_SKILL_NODE(21062, 176) {
    pnode->resizeTrigger(PhaseNode_GetRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_OffsetCalculate>(PhaseNode_GetRotation::TRIGGER_DONE, 177, PhaseNode_OffsetCalculate::FUNC_DO, &PhaseNode_OffsetCalculate::Do);
}

REGISTER_CREATE_SKILL_NODE(21062, 176) {
    auto node176 = GET_SKILL_NODE(176, PhaseNode_GetRotation);
    if (node176 == nullptr) {
        node176 = new PhaseNode_GetRotation(176, phase);
        node176->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node176->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(21062, 176, node176)
    }
    if (noInit == true) {
        return node176;
    }
    return node176;
}
//--------------------------------------------------------------------------------
// OffsetCalculate
//
REGISTER_REGISTER_SKILL_NODE(21062, 177) {
    pnode->resizeTrigger(PhaseNode_OffsetCalculate::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 30, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(21062, 177) {
    auto node177 = GET_SKILL_NODE(177, PhaseNode_OffsetCalculate);
    if (node177 == nullptr) {
        node177 = new PhaseNode_OffsetCalculate(177, phase);
        node177->setPosZ(.00f);
        node177->setOffsetX(2.50f);
        node177->setOffsetY(2.60f);
        node177->setOffsetZ(2.40f);
        node177->setRotOffset(.00f);
        CALL_REGISTER_SKILL_NODE(21062, 177, node177)
    }
    if (noInit == true) {
        return node177;
    }
    auto node175 = GET_SKILL_NODE(175, PhaseNode_GetLocation);
    auto node176 = GET_SKILL_NODE(176, PhaseNode_GetRotation);
    if (node175 != nullptr) node177->setPosX(node175->getX());
    if (node175 != nullptr) node177->setPosY(node175->getY());
    if (node176 != nullptr) node177->setRotation(node176->getAngle());
    return node177;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(21062, 178) {
}

REGISTER_CREATE_SKILL_NODE(21062, 178) {
    auto node178 = GET_SKILL_NODE(178, PhaseNode_RaiseEvent);
    if (node178 == nullptr) {
        node178 = new PhaseNode_RaiseEvent(178, phase);
        node178->setEvent("MonsterInterrupt");
        node178->setTarget(0U);
        node178->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node178->setTypeParams(0, 0);
        node178->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(21062, 178, node178)
    }
    if (noInit == true) {
        return node178;
    }
    return node178;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(21062, 179) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_Detect::TRIGGER_ON, 182, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(21062, 179) {
    auto node179 = GET_SKILL_NODE(179, PhaseNode_Detect);
    if (node179 == nullptr) {
        node179 = new PhaseNode_Detect(179, phase);
        node179->setSelf(0U);
        node179->setEvent("MonsterInterrupt");
        node179->setType(PhaseNode_Detect::Detect_Type::Interrupt_Skill);
        node179->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(21062, 179, node179)
    }
    if (noInit == true) {
        return node179;
    }
    return node179;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(21062, 180) {
}

REGISTER_CREATE_SKILL_NODE(21062, 180) {
    auto node180 = GET_SKILL_NODE(180, PhaseNode_EndPhase);
    if (node180 == nullptr) {
        node180 = new PhaseNode_EndPhase(180, phase);
        node180->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node180->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(21062, 180, node180)
    }
    if (noInit == true) {
        return node180;
    }
    return node180;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(21062, 182) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_Delay::TRIGGER_DONE, 184, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(21062, 182) {
    auto node182 = GET_SKILL_NODE(182, PhaseNode_Delay);
    if (node182 == nullptr) {
        node182 = new PhaseNode_Delay(182, phase);
        node182->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(21062, 182, node182)
    }
    if (noInit == true) {
        return node182;
    }
    return node182;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(21062, 183) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 180, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(21062, 183) {
    auto node183 = GET_SKILL_NODE(183, PhaseNode_SkillEndNotify);
    if (node183 == nullptr) {
        node183 = new PhaseNode_SkillEndNotify(183, phase);
        node183->setReturnType(false);
        CALL_REGISTER_SKILL_NODE(21062, 183, node183)
    }
    if (noInit == true) {
        return node183;
    }
    return node183;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(21062, 184) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_FALSE, 185, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_TRUE, 183, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
}

REGISTER_CREATE_SKILL_NODE(21062, 184) {
    auto node184 = GET_SKILL_NODE(184, PhaseNode_If);
    if (node184 == nullptr) {
        node184 = new PhaseNode_If(184, phase);
        node184->setCondition(false);
        CALL_REGISTER_SKILL_NODE(21062, 184, node184)
    }
    if (noInit == true) {
        return node184;
    }
    return node184;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(21062, 185) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 180, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(21062, 185) {
    auto node185 = GET_SKILL_NODE(185, PhaseNode_SkillEndNotify);
    if (node185 == nullptr) {
        node185 = new PhaseNode_SkillEndNotify(185, phase);
        node185->setReturnType(true);
        CALL_REGISTER_SKILL_NODE(21062, 185, node185)
    }
    if (noInit == true) {
        return node185;
    }
    return node185;
}

//--------------------------------------------------------------------------------
// SkillCreator_21062
//
class SkillCreator_21062 : public SkillCreator {
public:
    SkillCreator_21062() {}
    virtual ~SkillCreator_21062() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_21062

//--------------------------------------------------------------------------------
// SkillPhase_21062
//
class SkillPhase_21062 : public SkillPhase {
public:
    SkillPhase_21062(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_21062() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(21062, 2) // StartPhase
        CASE_CREATE_SKILL_NODE(21062, 4) // TriggerUpdate
        CASE_CREATE_SKILL_NODE(21062, 28) // EndPhase
        CASE_CREATE_SKILL_NODE(21062, 30) // Delay
        CASE_CREATE_SKILL_NODE(21062, 62) // PlayAnimation
        CASE_CREATE_SKILL_NODE(21062, 64) // PlayAnimation
        CASE_CREATE_SKILL_NODE(21062, 67) // Delay
        CASE_CREATE_SKILL_NODE(21062, 71) // Delay
        CASE_CREATE_SKILL_NODE(21062, 79) // Detect
        CASE_CREATE_SKILL_NODE(21062, 81) // EndPhase
        CASE_CREATE_SKILL_NODE(21062, 102) // FloatOperation
        CASE_CREATE_SKILL_NODE(21062, 104) // FloatOperation
        CASE_CREATE_SKILL_NODE(21062, 106) // SpawnProjectile
        CASE_CREATE_SKILL_NODE(21062, 107) // SpawnProjectile
        CASE_CREATE_SKILL_NODE(21062, 123) // SpawnProjectile
        CASE_CREATE_SKILL_NODE(21062, 137) // PlaySound
        CASE_CREATE_SKILL_NODE(21062, 166) // PlayEffect
        CASE_CREATE_SKILL_NODE(21062, 167) // Delay
        CASE_CREATE_SKILL_NODE(21062, 168) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(21062, 169) // If
        CASE_CREATE_SKILL_NODE(21062, 170) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(21062, 171) // ResetCD
        CASE_CREATE_SKILL_NODE(21062, 172) // PlayAnimation
        CASE_CREATE_SKILL_NODE(21062, 173) // PlaySound
        CASE_CREATE_SKILL_NODE(21062, 174) // Delay
        CASE_CREATE_SKILL_NODE(21062, 175) // GetLocation
        CASE_CREATE_SKILL_NODE(21062, 176) // GetRotation
        CASE_CREATE_SKILL_NODE(21062, 177) // OffsetCalculate
        CASE_CREATE_SKILL_NODE(21062, 178) // RaiseEvent
        CASE_CREATE_SKILL_NODE(21062, 179) // Detect
        CASE_CREATE_SKILL_NODE(21062, 180) // EndPhase
        CASE_CREATE_SKILL_NODE(21062, 182) // Delay
        CASE_CREATE_SKILL_NODE(21062, 183) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(21062, 184) // If
        CASE_CREATE_SKILL_NODE(21062, 185) // SkillEndNotify
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_21062

SkillLogic* SkillCreator_21062::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //创建阶段phase
    auto phase = new SkillPhase_21062(1, logic, 3);
    //设置phase执行器
    phase->setRunPhaseNode(1, 2);
    phase->setRunPhaseNode(2, 4);
    phase->setDetectPhaseNode(3, 79);
    phase->setDetectPhaseNode(3, 179);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_21062::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
