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
REGISTER_REGISTER_SKILL_NODE(22063, 7) {
    pnode->resizeTrigger(PhaseNode_SpawnProjectile::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_SpawnProjectile::TRIGGER_DONE, 42, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(22063, 7) {
    auto node7 = GET_SKILL_NODE(7, PhaseNode_SpawnProjectile);
    if (node7 == nullptr) {
        node7 = new PhaseNode_SpawnProjectile(7, phase);
        node7->setDataId(52207);
        node7->setEndPosZ(.00f);
        node7->setMaxCount(0);
        CALL_REGISTER_SKILL_NODE(22063, 7, node7)
    }
    if (noInit == true) {
        return node7;
    }
    auto node41 = GET_SKILL_NODE(41, PhaseNode_OffsetCalculate);
    auto node34 = GET_SKILL_NODE(34, PhaseNode_GetLocation);
    if (node41 != nullptr) node7->setPosX(node41->getOutPosX());
    if (node41 != nullptr) node7->setPosY(node41->getOutPosY());
    if (node41 != nullptr) node7->setPosZ(node41->getOutPosZ());
    if (node34 != nullptr) node7->setEndPosX(node34->getX());
    if (node34 != nullptr) node7->setEndPosY(node34->getY());
    if (node41 != nullptr) node7->setRotation(node41->getOutRotation());
    return node7;
}
//--------------------------------------------------------------------------------
// StartPhase
//
REGISTER_REGISTER_SKILL_NODE(22063, 10) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_StartPhase::TRIGGER_START, 50, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_StartPhase::TRIGGER_START, 46, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_StartPhase::TRIGGER_START, 35, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(22063, 10) {
    auto node10 = GET_SKILL_NODE(10, PhaseNode_StartPhase);
    if (node10 == nullptr) {
        node10 = new PhaseNode_StartPhase(10, phase);
        CALL_REGISTER_SKILL_NODE(22063, 10, node10)
    }
    if (noInit == true) {
        return node10;
    }
    return node10;
}
//--------------------------------------------------------------------------------
// TriggerUpdate
//
REGISTER_REGISTER_SKILL_NODE(22063, 12) {
}

REGISTER_CREATE_SKILL_NODE(22063, 12) {
    auto node12 = GET_SKILL_NODE(12, PhaseNode_TriggerUpdate);
    if (node12 == nullptr) {
        node12 = new PhaseNode_TriggerUpdate(12, phase);
        CALL_REGISTER_SKILL_NODE(22063, 12, node12)
    }
    if (noInit == true) {
        return node12;
    }
    return node12;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(22063, 16) {
}

REGISTER_CREATE_SKILL_NODE(22063, 16) {
    auto node16 = GET_SKILL_NODE(16, PhaseNode_EndPhase);
    if (node16 == nullptr) {
        node16 = new PhaseNode_EndPhase(16, phase);
        node16->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node16->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(22063, 16, node16)
    }
    if (noInit == true) {
        return node16;
    }
    return node16;
}
//--------------------------------------------------------------------------------
// GetBBParamUInt64
//
REGISTER_REGISTER_SKILL_NODE(22063, 32) {
    pnode->resizeTrigger(PhaseNode_GetBBParamUInt64::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_GetBBParamUInt64::TRIGGER_DONE, 34, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(22063, 32) {
    auto node32 = GET_SKILL_NODE(32, PhaseNode_GetBBParamUInt64);
    if (node32 == nullptr) {
        node32 = new PhaseNode_GetBBParamUInt64(32, phase);
        node32->setBBName("AtkTarget");
        CALL_REGISTER_SKILL_NODE(22063, 32, node32)
    }
    if (noInit == true) {
        return node32;
    }
    return node32;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(22063, 34) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnProjectile>(PhaseNode_GetLocation::TRIGGER_DONE, 7, PhaseNode_SpawnProjectile::FUNC_DO, &PhaseNode_SpawnProjectile::Do);
}

REGISTER_CREATE_SKILL_NODE(22063, 34) {
    auto node34 = GET_SKILL_NODE(34, PhaseNode_GetLocation);
    if (node34 == nullptr) {
        node34 = new PhaseNode_GetLocation(34, phase);
        node34->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        CALL_REGISTER_SKILL_NODE(22063, 34, node34)
    }
    if (noInit == true) {
        return node34;
    }
    auto node32 = GET_SKILL_NODE(32, PhaseNode_GetBBParamUInt64);
    if (node32 != nullptr) node34->setTarget(node32->getValue());
    return node34;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(22063, 35) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_ResetCD::TRIGGER_DONE, 36, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(22063, 35) {
    auto node35 = GET_SKILL_NODE(35, PhaseNode_ResetCD);
    if (node35 == nullptr) {
        node35 = new PhaseNode_ResetCD(35, phase);
        node35->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node35->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node35->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(22063, 35, node35)
    }
    if (noInit == true) {
        return node35;
    }
    return node35;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(22063, 36) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_PlayAnimation::TRIGGER_DONE, 37, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(22063, 36) {
    auto node36 = GET_SKILL_NODE(36, PhaseNode_PlayAnimation);
    if (node36 == nullptr) {
        node36 = new PhaseNode_PlayAnimation(36, phase);
        node36->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node36->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node36->setTarget(0U);
        node36->setAnimation("Skill3S1");
        node36->setParameter("");
        node36->setValue(false);
        CALL_REGISTER_SKILL_NODE(22063, 36, node36)
    }
    if (noInit == true) {
        return node36;
    }
    return node36;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(22063, 37) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlaySound::TRIGGER_DONE, 38, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(22063, 37) {
    auto node37 = GET_SKILL_NODE(37, PhaseNode_PlaySound);
    if (node37 == nullptr) {
        node37 = new PhaseNode_PlaySound(37, phase);
        node37->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node37->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node37->setSoundID("");
        node37->setTarget(0U);
        node37->setUsePos(false);
        node37->setPosX(.00f);
        node37->setPosY(.00f);
        node37->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(22063, 37, node37)
    }
    if (noInit == true) {
        return node37;
    }
    return node37;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22063, 38) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_Delay::TRIGGER_DONE, 39, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(22063, 38) {
    auto node38 = GET_SKILL_NODE(38, PhaseNode_Delay);
    if (node38 == nullptr) {
        node38 = new PhaseNode_Delay(38, phase);
        node38->setTime(.90f);
        CALL_REGISTER_SKILL_NODE(22063, 38, node38)
    }
    if (noInit == true) {
        return node38;
    }
    return node38;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(22063, 39) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetRotation>(PhaseNode_GetLocation::TRIGGER_DONE, 40, PhaseNode_GetRotation::FUNC_DO, &PhaseNode_GetRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(22063, 39) {
    auto node39 = GET_SKILL_NODE(39, PhaseNode_GetLocation);
    if (node39 == nullptr) {
        node39 = new PhaseNode_GetLocation(39, phase);
        node39->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node39->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(22063, 39, node39)
    }
    if (noInit == true) {
        return node39;
    }
    return node39;
}
//--------------------------------------------------------------------------------
// GetRotation
//
REGISTER_REGISTER_SKILL_NODE(22063, 40) {
    pnode->resizeTrigger(PhaseNode_GetRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_OffsetCalculate>(PhaseNode_GetRotation::TRIGGER_DONE, 41, PhaseNode_OffsetCalculate::FUNC_DO, &PhaseNode_OffsetCalculate::Do);
}

REGISTER_CREATE_SKILL_NODE(22063, 40) {
    auto node40 = GET_SKILL_NODE(40, PhaseNode_GetRotation);
    if (node40 == nullptr) {
        node40 = new PhaseNode_GetRotation(40, phase);
        node40->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node40->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(22063, 40, node40)
    }
    if (noInit == true) {
        return node40;
    }
    return node40;
}
//--------------------------------------------------------------------------------
// OffsetCalculate
//
REGISTER_REGISTER_SKILL_NODE(22063, 41) {
    pnode->resizeTrigger(PhaseNode_OffsetCalculate::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetBBParamUInt64>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 32, PhaseNode_GetBBParamUInt64::FUNC_DO, &PhaseNode_GetBBParamUInt64::Do);
}

REGISTER_CREATE_SKILL_NODE(22063, 41) {
    auto node41 = GET_SKILL_NODE(41, PhaseNode_OffsetCalculate);
    if (node41 == nullptr) {
        node41 = new PhaseNode_OffsetCalculate(41, phase);
        node41->setPosZ(.00f);
        node41->setOffsetX(-1.69f);
        node41->setOffsetY(1.20f);
        node41->setOffsetZ(4.60f);
        node41->setRotOffset(.00f);
        CALL_REGISTER_SKILL_NODE(22063, 41, node41)
    }
    if (noInit == true) {
        return node41;
    }
    auto node39 = GET_SKILL_NODE(39, PhaseNode_GetLocation);
    auto node40 = GET_SKILL_NODE(40, PhaseNode_GetRotation);
    if (node39 != nullptr) node41->setPosX(node39->getX());
    if (node39 != nullptr) node41->setPosY(node39->getY());
    if (node40 != nullptr) node41->setRotation(node40->getAngle());
    return node41;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22063, 42) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_Delay::TRIGGER_DONE, 44, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(22063, 42) {
    auto node42 = GET_SKILL_NODE(42, PhaseNode_Delay);
    if (node42 == nullptr) {
        node42 = new PhaseNode_Delay(42, phase);
        node42->setTime(.70f);
        CALL_REGISTER_SKILL_NODE(22063, 42, node42)
    }
    if (noInit == true) {
        return node42;
    }
    return node42;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(22063, 43) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 16, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(22063, 43) {
    auto node43 = GET_SKILL_NODE(43, PhaseNode_SkillEndNotify);
    if (node43 == nullptr) {
        node43 = new PhaseNode_SkillEndNotify(43, phase);
        node43->setReturnType(false);
        CALL_REGISTER_SKILL_NODE(22063, 43, node43)
    }
    if (noInit == true) {
        return node43;
    }
    return node43;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(22063, 44) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_FALSE, 45, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_TRUE, 43, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
}

REGISTER_CREATE_SKILL_NODE(22063, 44) {
    auto node44 = GET_SKILL_NODE(44, PhaseNode_If);
    if (node44 == nullptr) {
        node44 = new PhaseNode_If(44, phase);
        node44->setCondition(false);
        CALL_REGISTER_SKILL_NODE(22063, 44, node44)
    }
    if (noInit == true) {
        return node44;
    }
    return node44;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(22063, 45) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 16, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(22063, 45) {
    auto node45 = GET_SKILL_NODE(45, PhaseNode_SkillEndNotify);
    if (node45 == nullptr) {
        node45 = new PhaseNode_SkillEndNotify(45, phase);
        node45->setReturnType(true);
        CALL_REGISTER_SKILL_NODE(22063, 45, node45)
    }
    if (noInit == true) {
        return node45;
    }
    return node45;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(22063, 46) {
}

REGISTER_CREATE_SKILL_NODE(22063, 46) {
    auto node46 = GET_SKILL_NODE(46, PhaseNode_RaiseEvent);
    if (node46 == nullptr) {
        node46 = new PhaseNode_RaiseEvent(46, phase);
        node46->setEvent("MonsterInterrupt");
        node46->setTarget(0U);
        node46->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node46->setTypeParams(0, 0);
        node46->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(22063, 46, node46)
    }
    if (noInit == true) {
        return node46;
    }
    return node46;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(22063, 47) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_Detect::TRIGGER_ON, 52, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(22063, 47) {
    auto node47 = GET_SKILL_NODE(47, PhaseNode_Detect);
    if (node47 == nullptr) {
        node47 = new PhaseNode_Detect(47, phase);
        node47->setSelf(0U);
        node47->setEvent("MonsterInterrupt");
        node47->setType(PhaseNode_Detect::Detect_Type::Interrupt_Skill);
        node47->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(22063, 47, node47)
    }
    if (noInit == true) {
        return node47;
    }
    return node47;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(22063, 48) {
}

REGISTER_CREATE_SKILL_NODE(22063, 48) {
    auto node48 = GET_SKILL_NODE(48, PhaseNode_EndPhase);
    if (node48 == nullptr) {
        node48 = new PhaseNode_EndPhase(48, phase);
        node48->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node48->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(22063, 48, node48)
    }
    if (noInit == true) {
        return node48;
    }
    return node48;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22063, 50) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_Delay::TRIGGER_DONE, 51, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(22063, 50) {
    auto node50 = GET_SKILL_NODE(50, PhaseNode_Delay);
    if (node50 == nullptr) {
        node50 = new PhaseNode_Delay(50, phase);
        node50->setTime(.90f);
        CALL_REGISTER_SKILL_NODE(22063, 50, node50)
    }
    if (noInit == true) {
        return node50;
    }
    return node50;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(22063, 51) {
}

REGISTER_CREATE_SKILL_NODE(22063, 51) {
    auto node51 = GET_SKILL_NODE(51, PhaseNode_PlaySound);
    if (node51 == nullptr) {
        node51 = new PhaseNode_PlaySound(51, phase);
        node51->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node51->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node51->setSoundID("SE_MON2207_ATK_B_P1");
        node51->setTarget(0U);
        node51->setUsePos(false);
        node51->setPosX(.00f);
        node51->setPosY(.00f);
        node51->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(22063, 51, node51)
    }
    if (noInit == true) {
        return node51;
    }
    return node51;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22063, 52) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_Delay::TRIGGER_DONE, 54, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(22063, 52) {
    auto node52 = GET_SKILL_NODE(52, PhaseNode_Delay);
    if (node52 == nullptr) {
        node52 = new PhaseNode_Delay(52, phase);
        node52->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(22063, 52, node52)
    }
    if (noInit == true) {
        return node52;
    }
    return node52;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(22063, 53) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 48, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(22063, 53) {
    auto node53 = GET_SKILL_NODE(53, PhaseNode_SkillEndNotify);
    if (node53 == nullptr) {
        node53 = new PhaseNode_SkillEndNotify(53, phase);
        node53->setReturnType(false);
        CALL_REGISTER_SKILL_NODE(22063, 53, node53)
    }
    if (noInit == true) {
        return node53;
    }
    return node53;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(22063, 54) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_FALSE, 55, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_TRUE, 53, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
}

REGISTER_CREATE_SKILL_NODE(22063, 54) {
    auto node54 = GET_SKILL_NODE(54, PhaseNode_If);
    if (node54 == nullptr) {
        node54 = new PhaseNode_If(54, phase);
        node54->setCondition(false);
        CALL_REGISTER_SKILL_NODE(22063, 54, node54)
    }
    if (noInit == true) {
        return node54;
    }
    return node54;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(22063, 55) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 48, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(22063, 55) {
    auto node55 = GET_SKILL_NODE(55, PhaseNode_SkillEndNotify);
    if (node55 == nullptr) {
        node55 = new PhaseNode_SkillEndNotify(55, phase);
        node55->setReturnType(true);
        CALL_REGISTER_SKILL_NODE(22063, 55, node55)
    }
    if (noInit == true) {
        return node55;
    }
    return node55;
}

//--------------------------------------------------------------------------------
// SkillCreator_22063
//
class SkillCreator_22063 : public SkillCreator {
public:
    SkillCreator_22063() {}
    virtual ~SkillCreator_22063() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_22063

//--------------------------------------------------------------------------------
// SkillPhase_22063
//
class SkillPhase_22063 : public SkillPhase {
public:
    SkillPhase_22063(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_22063() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(22063, 7) // SpawnProjectile
        CASE_CREATE_SKILL_NODE(22063, 10) // StartPhase
        CASE_CREATE_SKILL_NODE(22063, 12) // TriggerUpdate
        CASE_CREATE_SKILL_NODE(22063, 16) // EndPhase
        CASE_CREATE_SKILL_NODE(22063, 32) // GetBBParamUInt64
        CASE_CREATE_SKILL_NODE(22063, 34) // GetLocation
        CASE_CREATE_SKILL_NODE(22063, 35) // ResetCD
        CASE_CREATE_SKILL_NODE(22063, 36) // PlayAnimation
        CASE_CREATE_SKILL_NODE(22063, 37) // PlaySound
        CASE_CREATE_SKILL_NODE(22063, 38) // Delay
        CASE_CREATE_SKILL_NODE(22063, 39) // GetLocation
        CASE_CREATE_SKILL_NODE(22063, 40) // GetRotation
        CASE_CREATE_SKILL_NODE(22063, 41) // OffsetCalculate
        CASE_CREATE_SKILL_NODE(22063, 42) // Delay
        CASE_CREATE_SKILL_NODE(22063, 43) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(22063, 44) // If
        CASE_CREATE_SKILL_NODE(22063, 45) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(22063, 46) // RaiseEvent
        CASE_CREATE_SKILL_NODE(22063, 47) // Detect
        CASE_CREATE_SKILL_NODE(22063, 48) // EndPhase
        CASE_CREATE_SKILL_NODE(22063, 50) // Delay
        CASE_CREATE_SKILL_NODE(22063, 51) // PlaySound
        CASE_CREATE_SKILL_NODE(22063, 52) // Delay
        CASE_CREATE_SKILL_NODE(22063, 53) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(22063, 54) // If
        CASE_CREATE_SKILL_NODE(22063, 55) // SkillEndNotify
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_22063

SkillLogic* SkillCreator_22063::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //创建阶段phase
    auto phase = new SkillPhase_22063(1, logic, 3);
    //设置phase执行器
    phase->setRunPhaseNode(1, 10);
    phase->setRunPhaseNode(2, 12);
    phase->setDetectPhaseNode(3, 47);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_22063::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
