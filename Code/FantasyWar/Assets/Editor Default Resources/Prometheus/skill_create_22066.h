#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

#include "skill_psnode_delay.h"
#include "skill_psnode_detect.h"
#include "skill_psnode_endphase.h"
#include "skill_psnode_getbbparamuint64.h"
#include "skill_psnode_getlocation.h"
#include "skill_psnode_getrotation.h"
#include "skill_psnode_if.h"
#include "skill_psnode_offsetcalculate.h"
#include "skill_psnode_playanimation.h"
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
// SpawnProjectile
//
REGISTER_REGISTER_SKILL_NODE(22066, 6) {
    pnode->resizeTrigger(PhaseNode_SpawnProjectile::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnProjectile>(PhaseNode_SpawnProjectile::TRIGGER_DONE, 16, PhaseNode_SpawnProjectile::FUNC_DO, &PhaseNode_SpawnProjectile::Do);
}

REGISTER_CREATE_SKILL_NODE(22066, 6) {
    auto node6 = GET_SKILL_NODE(6, PhaseNode_SpawnProjectile);
    if (node6 == nullptr) {
        node6 = new PhaseNode_SpawnProjectile(6, phase);
        node6->setDataId(52207);
        node6->setEndPosZ(.00f);
        node6->setMaxCount(0);
        CALL_REGISTER_SKILL_NODE(22066, 6, node6)
    }
    if (noInit == true) {
        return node6;
    }
    auto node45 = GET_SKILL_NODE(45, PhaseNode_OffsetCalculate);
    auto node38 = GET_SKILL_NODE(38, PhaseNode_GetLocation);
    if (node45 != nullptr) node6->setPosX(node45->getOutPosX());
    if (node45 != nullptr) node6->setPosY(node45->getOutPosY());
    if (node45 != nullptr) node6->setPosZ(node45->getOutPosZ());
    if (node38 != nullptr) node6->setEndPosX(node38->getX());
    if (node38 != nullptr) node6->setEndPosY(node38->getY());
    if (node45 != nullptr) node6->setRotation(node45->getOutRotation());
    return node6;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(22066, 8) {
}

REGISTER_CREATE_SKILL_NODE(22066, 8) {
    auto node8 = GET_SKILL_NODE(8, PhaseNode_EndPhase);
    if (node8 == nullptr) {
        node8 = new PhaseNode_EndPhase(8, phase);
        node8->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node8->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(22066, 8, node8)
    }
    if (noInit == true) {
        return node8;
    }
    return node8;
}
//--------------------------------------------------------------------------------
// StartPhase
//
REGISTER_REGISTER_SKILL_NODE(22066, 10) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_StartPhase::TRIGGER_START, 54, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_StartPhase::TRIGGER_START, 50, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_StartPhase::TRIGGER_START, 39, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(22066, 10) {
    auto node10 = GET_SKILL_NODE(10, PhaseNode_StartPhase);
    if (node10 == nullptr) {
        node10 = new PhaseNode_StartPhase(10, phase);
        CALL_REGISTER_SKILL_NODE(22066, 10, node10)
    }
    if (noInit == true) {
        return node10;
    }
    return node10;
}
//--------------------------------------------------------------------------------
// TriggerUpdate
//
REGISTER_REGISTER_SKILL_NODE(22066, 12) {
}

REGISTER_CREATE_SKILL_NODE(22066, 12) {
    auto node12 = GET_SKILL_NODE(12, PhaseNode_TriggerUpdate);
    if (node12 == nullptr) {
        node12 = new PhaseNode_TriggerUpdate(12, phase);
        CALL_REGISTER_SKILL_NODE(22066, 12, node12)
    }
    if (noInit == true) {
        return node12;
    }
    return node12;
}
//--------------------------------------------------------------------------------
// SpawnProjectile
//
REGISTER_REGISTER_SKILL_NODE(22066, 16) {
    pnode->resizeTrigger(PhaseNode_SpawnProjectile::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_SpawnProjectile::TRIGGER_DONE, 46, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(22066, 16) {
    auto node16 = GET_SKILL_NODE(16, PhaseNode_SpawnProjectile);
    if (node16 == nullptr) {
        node16 = new PhaseNode_SpawnProjectile(16, phase);
        node16->setDataId(52208);
        node16->setEndPosZ(.00f);
        node16->setMaxCount(0);
        CALL_REGISTER_SKILL_NODE(22066, 16, node16)
    }
    if (noInit == true) {
        return node16;
    }
    auto node45 = GET_SKILL_NODE(45, PhaseNode_OffsetCalculate);
    auto node38 = GET_SKILL_NODE(38, PhaseNode_GetLocation);
    if (node45 != nullptr) node16->setPosX(node45->getOutPosX());
    if (node45 != nullptr) node16->setPosY(node45->getOutPosY());
    if (node45 != nullptr) node16->setPosZ(node45->getOutPosZ());
    if (node38 != nullptr) node16->setEndPosX(node38->getX());
    if (node38 != nullptr) node16->setEndPosY(node38->getY());
    if (node45 != nullptr) node16->setRotation(node45->getOutRotation());
    return node16;
}
//--------------------------------------------------------------------------------
// GetBBParamUInt64
//
REGISTER_REGISTER_SKILL_NODE(22066, 36) {
    pnode->resizeTrigger(PhaseNode_GetBBParamUInt64::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_GetBBParamUInt64::TRIGGER_DONE, 38, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(22066, 36) {
    auto node36 = GET_SKILL_NODE(36, PhaseNode_GetBBParamUInt64);
    if (node36 == nullptr) {
        node36 = new PhaseNode_GetBBParamUInt64(36, phase);
        node36->setBBName("AtkTarget");
        CALL_REGISTER_SKILL_NODE(22066, 36, node36)
    }
    if (noInit == true) {
        return node36;
    }
    return node36;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(22066, 38) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnProjectile>(PhaseNode_GetLocation::TRIGGER_DONE, 6, PhaseNode_SpawnProjectile::FUNC_DO, &PhaseNode_SpawnProjectile::Do);
}

REGISTER_CREATE_SKILL_NODE(22066, 38) {
    auto node38 = GET_SKILL_NODE(38, PhaseNode_GetLocation);
    if (node38 == nullptr) {
        node38 = new PhaseNode_GetLocation(38, phase);
        node38->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        CALL_REGISTER_SKILL_NODE(22066, 38, node38)
    }
    if (noInit == true) {
        return node38;
    }
    auto node36 = GET_SKILL_NODE(36, PhaseNode_GetBBParamUInt64);
    if (node36 != nullptr) node38->setTarget(node36->getValue());
    return node38;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(22066, 39) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_ResetCD::TRIGGER_DONE, 40, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(22066, 39) {
    auto node39 = GET_SKILL_NODE(39, PhaseNode_ResetCD);
    if (node39 == nullptr) {
        node39 = new PhaseNode_ResetCD(39, phase);
        node39->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node39->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node39->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(22066, 39, node39)
    }
    if (noInit == true) {
        return node39;
    }
    return node39;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(22066, 40) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_PlayAnimation::TRIGGER_DONE, 41, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(22066, 40) {
    auto node40 = GET_SKILL_NODE(40, PhaseNode_PlayAnimation);
    if (node40 == nullptr) {
        node40 = new PhaseNode_PlayAnimation(40, phase);
        node40->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node40->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node40->setTarget(0U);
        node40->setAnimation("Skill3S1");
        node40->setParameter("");
        node40->setValue(false);
        CALL_REGISTER_SKILL_NODE(22066, 40, node40)
    }
    if (noInit == true) {
        return node40;
    }
    return node40;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(22066, 41) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlaySound::TRIGGER_DONE, 42, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(22066, 41) {
    auto node41 = GET_SKILL_NODE(41, PhaseNode_PlaySound);
    if (node41 == nullptr) {
        node41 = new PhaseNode_PlaySound(41, phase);
        node41->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node41->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node41->setSoundID("");
        node41->setTarget(0U);
        node41->setUsePos(false);
        node41->setPosX(.00f);
        node41->setPosY(.00f);
        node41->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(22066, 41, node41)
    }
    if (noInit == true) {
        return node41;
    }
    return node41;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22066, 42) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_Delay::TRIGGER_DONE, 43, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(22066, 42) {
    auto node42 = GET_SKILL_NODE(42, PhaseNode_Delay);
    if (node42 == nullptr) {
        node42 = new PhaseNode_Delay(42, phase);
        node42->setTime(.90f);
        CALL_REGISTER_SKILL_NODE(22066, 42, node42)
    }
    if (noInit == true) {
        return node42;
    }
    return node42;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(22066, 43) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetRotation>(PhaseNode_GetLocation::TRIGGER_DONE, 44, PhaseNode_GetRotation::FUNC_DO, &PhaseNode_GetRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(22066, 43) {
    auto node43 = GET_SKILL_NODE(43, PhaseNode_GetLocation);
    if (node43 == nullptr) {
        node43 = new PhaseNode_GetLocation(43, phase);
        node43->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node43->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(22066, 43, node43)
    }
    if (noInit == true) {
        return node43;
    }
    return node43;
}
//--------------------------------------------------------------------------------
// GetRotation
//
REGISTER_REGISTER_SKILL_NODE(22066, 44) {
    pnode->resizeTrigger(PhaseNode_GetRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_OffsetCalculate>(PhaseNode_GetRotation::TRIGGER_DONE, 45, PhaseNode_OffsetCalculate::FUNC_DO, &PhaseNode_OffsetCalculate::Do);
}

REGISTER_CREATE_SKILL_NODE(22066, 44) {
    auto node44 = GET_SKILL_NODE(44, PhaseNode_GetRotation);
    if (node44 == nullptr) {
        node44 = new PhaseNode_GetRotation(44, phase);
        node44->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node44->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(22066, 44, node44)
    }
    if (noInit == true) {
        return node44;
    }
    return node44;
}
//--------------------------------------------------------------------------------
// OffsetCalculate
//
REGISTER_REGISTER_SKILL_NODE(22066, 45) {
    pnode->resizeTrigger(PhaseNode_OffsetCalculate::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetBBParamUInt64>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 36, PhaseNode_GetBBParamUInt64::FUNC_DO, &PhaseNode_GetBBParamUInt64::Do);
}

REGISTER_CREATE_SKILL_NODE(22066, 45) {
    auto node45 = GET_SKILL_NODE(45, PhaseNode_OffsetCalculate);
    if (node45 == nullptr) {
        node45 = new PhaseNode_OffsetCalculate(45, phase);
        node45->setPosZ(.00f);
        node45->setOffsetX(-1.69f);
        node45->setOffsetY(1.20f);
        node45->setOffsetZ(4.60f);
        node45->setRotOffset(.00f);
        CALL_REGISTER_SKILL_NODE(22066, 45, node45)
    }
    if (noInit == true) {
        return node45;
    }
    auto node43 = GET_SKILL_NODE(43, PhaseNode_GetLocation);
    auto node44 = GET_SKILL_NODE(44, PhaseNode_GetRotation);
    if (node43 != nullptr) node45->setPosX(node43->getX());
    if (node43 != nullptr) node45->setPosY(node43->getY());
    if (node44 != nullptr) node45->setRotation(node44->getAngle());
    return node45;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22066, 46) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_Delay::TRIGGER_DONE, 48, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(22066, 46) {
    auto node46 = GET_SKILL_NODE(46, PhaseNode_Delay);
    if (node46 == nullptr) {
        node46 = new PhaseNode_Delay(46, phase);
        node46->setTime(.70f);
        CALL_REGISTER_SKILL_NODE(22066, 46, node46)
    }
    if (noInit == true) {
        return node46;
    }
    return node46;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(22066, 47) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 8, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(22066, 47) {
    auto node47 = GET_SKILL_NODE(47, PhaseNode_SkillEndNotify);
    if (node47 == nullptr) {
        node47 = new PhaseNode_SkillEndNotify(47, phase);
        node47->setReturnType(false);
        CALL_REGISTER_SKILL_NODE(22066, 47, node47)
    }
    if (noInit == true) {
        return node47;
    }
    return node47;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(22066, 48) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_FALSE, 49, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_TRUE, 47, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
}

REGISTER_CREATE_SKILL_NODE(22066, 48) {
    auto node48 = GET_SKILL_NODE(48, PhaseNode_If);
    if (node48 == nullptr) {
        node48 = new PhaseNode_If(48, phase);
        node48->setCondition(false);
        CALL_REGISTER_SKILL_NODE(22066, 48, node48)
    }
    if (noInit == true) {
        return node48;
    }
    return node48;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(22066, 49) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 8, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(22066, 49) {
    auto node49 = GET_SKILL_NODE(49, PhaseNode_SkillEndNotify);
    if (node49 == nullptr) {
        node49 = new PhaseNode_SkillEndNotify(49, phase);
        node49->setReturnType(true);
        CALL_REGISTER_SKILL_NODE(22066, 49, node49)
    }
    if (noInit == true) {
        return node49;
    }
    return node49;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(22066, 50) {
}

REGISTER_CREATE_SKILL_NODE(22066, 50) {
    auto node50 = GET_SKILL_NODE(50, PhaseNode_RaiseEvent);
    if (node50 == nullptr) {
        node50 = new PhaseNode_RaiseEvent(50, phase);
        node50->setEvent("MonsterInterrupt");
        node50->setTarget(0U);
        node50->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node50->setTypeParams(0, 0);
        node50->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(22066, 50, node50)
    }
    if (noInit == true) {
        return node50;
    }
    return node50;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(22066, 51) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_Detect::TRIGGER_ON, 56, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(22066, 51) {
    auto node51 = GET_SKILL_NODE(51, PhaseNode_Detect);
    if (node51 == nullptr) {
        node51 = new PhaseNode_Detect(51, phase);
        node51->setSelf(0U);
        node51->setEvent("MonsterInterrupt");
        node51->setType(PhaseNode_Detect::Detect_Type::Interrupt_Skill);
        node51->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(22066, 51, node51)
    }
    if (noInit == true) {
        return node51;
    }
    return node51;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(22066, 52) {
}

REGISTER_CREATE_SKILL_NODE(22066, 52) {
    auto node52 = GET_SKILL_NODE(52, PhaseNode_EndPhase);
    if (node52 == nullptr) {
        node52 = new PhaseNode_EndPhase(52, phase);
        node52->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node52->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(22066, 52, node52)
    }
    if (noInit == true) {
        return node52;
    }
    return node52;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22066, 54) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_Delay::TRIGGER_DONE, 55, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(22066, 54) {
    auto node54 = GET_SKILL_NODE(54, PhaseNode_Delay);
    if (node54 == nullptr) {
        node54 = new PhaseNode_Delay(54, phase);
        node54->setTime(.90f);
        CALL_REGISTER_SKILL_NODE(22066, 54, node54)
    }
    if (noInit == true) {
        return node54;
    }
    return node54;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(22066, 55) {
}

REGISTER_CREATE_SKILL_NODE(22066, 55) {
    auto node55 = GET_SKILL_NODE(55, PhaseNode_PlaySound);
    if (node55 == nullptr) {
        node55 = new PhaseNode_PlaySound(55, phase);
        node55->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node55->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node55->setSoundID("SE_MON2207_ATK_B_P1");
        node55->setTarget(0U);
        node55->setUsePos(false);
        node55->setPosX(.00f);
        node55->setPosY(.00f);
        node55->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(22066, 55, node55)
    }
    if (noInit == true) {
        return node55;
    }
    return node55;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22066, 56) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_Delay::TRIGGER_DONE, 58, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(22066, 56) {
    auto node56 = GET_SKILL_NODE(56, PhaseNode_Delay);
    if (node56 == nullptr) {
        node56 = new PhaseNode_Delay(56, phase);
        node56->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(22066, 56, node56)
    }
    if (noInit == true) {
        return node56;
    }
    return node56;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(22066, 57) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 52, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(22066, 57) {
    auto node57 = GET_SKILL_NODE(57, PhaseNode_SkillEndNotify);
    if (node57 == nullptr) {
        node57 = new PhaseNode_SkillEndNotify(57, phase);
        node57->setReturnType(false);
        CALL_REGISTER_SKILL_NODE(22066, 57, node57)
    }
    if (noInit == true) {
        return node57;
    }
    return node57;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(22066, 58) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_FALSE, 59, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_TRUE, 57, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
}

REGISTER_CREATE_SKILL_NODE(22066, 58) {
    auto node58 = GET_SKILL_NODE(58, PhaseNode_If);
    if (node58 == nullptr) {
        node58 = new PhaseNode_If(58, phase);
        node58->setCondition(false);
        CALL_REGISTER_SKILL_NODE(22066, 58, node58)
    }
    if (noInit == true) {
        return node58;
    }
    return node58;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(22066, 59) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 52, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(22066, 59) {
    auto node59 = GET_SKILL_NODE(59, PhaseNode_SkillEndNotify);
    if (node59 == nullptr) {
        node59 = new PhaseNode_SkillEndNotify(59, phase);
        node59->setReturnType(true);
        CALL_REGISTER_SKILL_NODE(22066, 59, node59)
    }
    if (noInit == true) {
        return node59;
    }
    return node59;
}

//--------------------------------------------------------------------------------
// SkillCreator_22066
//
class SkillCreator_22066 : public SkillCreator {
public:
    SkillCreator_22066() {}
    virtual ~SkillCreator_22066() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_22066

//--------------------------------------------------------------------------------
// SkillPhase_22066
//
class SkillPhase_22066 : public SkillPhase {
public:
    SkillPhase_22066(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_22066() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(22066, 6) // SpawnProjectile
        CASE_CREATE_SKILL_NODE(22066, 8) // EndPhase
        CASE_CREATE_SKILL_NODE(22066, 10) // StartPhase
        CASE_CREATE_SKILL_NODE(22066, 12) // TriggerUpdate
        CASE_CREATE_SKILL_NODE(22066, 16) // SpawnProjectile
        CASE_CREATE_SKILL_NODE(22066, 36) // GetBBParamUInt64
        CASE_CREATE_SKILL_NODE(22066, 38) // GetLocation
        CASE_CREATE_SKILL_NODE(22066, 39) // ResetCD
        CASE_CREATE_SKILL_NODE(22066, 40) // PlayAnimation
        CASE_CREATE_SKILL_NODE(22066, 41) // PlaySound
        CASE_CREATE_SKILL_NODE(22066, 42) // Delay
        CASE_CREATE_SKILL_NODE(22066, 43) // GetLocation
        CASE_CREATE_SKILL_NODE(22066, 44) // GetRotation
        CASE_CREATE_SKILL_NODE(22066, 45) // OffsetCalculate
        CASE_CREATE_SKILL_NODE(22066, 46) // Delay
        CASE_CREATE_SKILL_NODE(22066, 47) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(22066, 48) // If
        CASE_CREATE_SKILL_NODE(22066, 49) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(22066, 50) // RaiseEvent
        CASE_CREATE_SKILL_NODE(22066, 51) // Detect
        CASE_CREATE_SKILL_NODE(22066, 52) // EndPhase
        CASE_CREATE_SKILL_NODE(22066, 54) // Delay
        CASE_CREATE_SKILL_NODE(22066, 55) // PlaySound
        CASE_CREATE_SKILL_NODE(22066, 56) // Delay
        CASE_CREATE_SKILL_NODE(22066, 57) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(22066, 58) // If
        CASE_CREATE_SKILL_NODE(22066, 59) // SkillEndNotify
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_22066

SkillLogic* SkillCreator_22066::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //创建阶段phase
    auto phase = new SkillPhase_22066(1, logic, 3);
    //设置phase执行器
    phase->setRunPhaseNode(1, 10);
    phase->setRunPhaseNode(2, 12);
    phase->setDetectPhaseNode(3, 51);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_22066::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
