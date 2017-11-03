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
// StartPhase
//
REGISTER_REGISTER_SKILL_NODE(22103, 3) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_StartPhase::TRIGGER_START, 35, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_StartPhase::TRIGGER_START, 24, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(22103, 3) {
    auto node3 = GET_SKILL_NODE(3, PhaseNode_StartPhase);
    if (node3 == nullptr) {
        node3 = new PhaseNode_StartPhase(3, phase);
        CALL_REGISTER_SKILL_NODE(22103, 3, node3)
    }
    if (noInit == true) {
        return node3;
    }
    return node3;
}
//--------------------------------------------------------------------------------
// TriggerUpdate
//
REGISTER_REGISTER_SKILL_NODE(22103, 5) {
}

REGISTER_CREATE_SKILL_NODE(22103, 5) {
    auto node5 = GET_SKILL_NODE(5, PhaseNode_TriggerUpdate);
    if (node5 == nullptr) {
        node5 = new PhaseNode_TriggerUpdate(5, phase);
        CALL_REGISTER_SKILL_NODE(22103, 5, node5)
    }
    if (noInit == true) {
        return node5;
    }
    return node5;
}
//--------------------------------------------------------------------------------
// GetBBParamUInt64
//
REGISTER_REGISTER_SKILL_NODE(22103, 8) {
    pnode->resizeTrigger(PhaseNode_GetBBParamUInt64::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_GetBBParamUInt64::TRIGGER_DONE, 10, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(22103, 8) {
    auto node8 = GET_SKILL_NODE(8, PhaseNode_GetBBParamUInt64);
    if (node8 == nullptr) {
        node8 = new PhaseNode_GetBBParamUInt64(8, phase);
        node8->setBBName("AtkTarget");
        CALL_REGISTER_SKILL_NODE(22103, 8, node8)
    }
    if (noInit == true) {
        return node8;
    }
    return node8;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(22103, 10) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_GetLocation::TRIGGER_DONE, 12, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(22103, 10) {
    auto node10 = GET_SKILL_NODE(10, PhaseNode_GetLocation);
    if (node10 == nullptr) {
        node10 = new PhaseNode_GetLocation(10, phase);
        node10->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        CALL_REGISTER_SKILL_NODE(22103, 10, node10)
    }
    if (noInit == true) {
        return node10;
    }
    auto node8 = GET_SKILL_NODE(8, PhaseNode_GetBBParamUInt64);
    if (node8 != nullptr) node10->setTarget(node8->getValue());
    return node10;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22103, 12) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_Delay::TRIGGER_DONE, 28, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(22103, 12) {
    auto node12 = GET_SKILL_NODE(12, PhaseNode_Delay);
    if (node12 == nullptr) {
        node12 = new PhaseNode_Delay(12, phase);
        node12->setTime(.68f);
        CALL_REGISTER_SKILL_NODE(22103, 12, node12)
    }
    if (noInit == true) {
        return node12;
    }
    return node12;
}
//--------------------------------------------------------------------------------
// SpawnProjectile
//
REGISTER_REGISTER_SKILL_NODE(22103, 16) {
    pnode->resizeTrigger(PhaseNode_SpawnProjectile::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_SpawnProjectile::TRIGGER_DONE, 31, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(22103, 16) {
    auto node16 = GET_SKILL_NODE(16, PhaseNode_SpawnProjectile);
    if (node16 == nullptr) {
        node16 = new PhaseNode_SpawnProjectile(16, phase);
        node16->setDataId(52210);
        node16->setEndPosZ(.00f);
        node16->setMaxCount(0);
        CALL_REGISTER_SKILL_NODE(22103, 16, node16)
    }
    if (noInit == true) {
        return node16;
    }
    auto node30 = GET_SKILL_NODE(30, PhaseNode_OffsetCalculate);
    auto node10 = GET_SKILL_NODE(10, PhaseNode_GetLocation);
    if (node30 != nullptr) node16->setPosX(node30->getOutPosX());
    if (node30 != nullptr) node16->setPosY(node30->getOutPosY());
    if (node30 != nullptr) node16->setPosZ(node30->getOutPosZ());
    if (node10 != nullptr) node16->setEndPosX(node10->getX());
    if (node10 != nullptr) node16->setEndPosY(node10->getY());
    if (node30 != nullptr) node16->setRotation(node30->getOutRotation());
    return node16;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(22103, 22) {
}

REGISTER_CREATE_SKILL_NODE(22103, 22) {
    auto node22 = GET_SKILL_NODE(22, PhaseNode_EndPhase);
    if (node22 == nullptr) {
        node22 = new PhaseNode_EndPhase(22, phase);
        node22->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node22->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(22103, 22, node22)
    }
    if (noInit == true) {
        return node22;
    }
    return node22;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(22103, 24) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_ResetCD::TRIGGER_DONE, 25, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(22103, 24) {
    auto node24 = GET_SKILL_NODE(24, PhaseNode_ResetCD);
    if (node24 == nullptr) {
        node24 = new PhaseNode_ResetCD(24, phase);
        node24->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node24->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node24->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(22103, 24, node24)
    }
    if (noInit == true) {
        return node24;
    }
    return node24;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(22103, 25) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_PlayAnimation::TRIGGER_DONE, 26, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(22103, 25) {
    auto node25 = GET_SKILL_NODE(25, PhaseNode_PlayAnimation);
    if (node25 == nullptr) {
        node25 = new PhaseNode_PlayAnimation(25, phase);
        node25->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node25->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node25->setTarget(0U);
        node25->setAnimation("Skill3S1");
        node25->setParameter("");
        node25->setValue(false);
        CALL_REGISTER_SKILL_NODE(22103, 25, node25)
    }
    if (noInit == true) {
        return node25;
    }
    return node25;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(22103, 26) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlaySound::TRIGGER_DONE, 27, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(22103, 26) {
    auto node26 = GET_SKILL_NODE(26, PhaseNode_PlaySound);
    if (node26 == nullptr) {
        node26 = new PhaseNode_PlaySound(26, phase);
        node26->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node26->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node26->setSoundID("");
        node26->setTarget(0U);
        node26->setUsePos(false);
        node26->setPosX(.00f);
        node26->setPosY(.00f);
        node26->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(22103, 26, node26)
    }
    if (noInit == true) {
        return node26;
    }
    return node26;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22103, 27) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetBBParamUInt64>(PhaseNode_Delay::TRIGGER_DONE, 8, PhaseNode_GetBBParamUInt64::FUNC_DO, &PhaseNode_GetBBParamUInt64::Do);
}

REGISTER_CREATE_SKILL_NODE(22103, 27) {
    auto node27 = GET_SKILL_NODE(27, PhaseNode_Delay);
    if (node27 == nullptr) {
        node27 = new PhaseNode_Delay(27, phase);
        node27->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(22103, 27, node27)
    }
    if (noInit == true) {
        return node27;
    }
    return node27;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(22103, 28) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetRotation>(PhaseNode_GetLocation::TRIGGER_DONE, 29, PhaseNode_GetRotation::FUNC_DO, &PhaseNode_GetRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(22103, 28) {
    auto node28 = GET_SKILL_NODE(28, PhaseNode_GetLocation);
    if (node28 == nullptr) {
        node28 = new PhaseNode_GetLocation(28, phase);
        node28->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node28->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(22103, 28, node28)
    }
    if (noInit == true) {
        return node28;
    }
    return node28;
}
//--------------------------------------------------------------------------------
// GetRotation
//
REGISTER_REGISTER_SKILL_NODE(22103, 29) {
    pnode->resizeTrigger(PhaseNode_GetRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_OffsetCalculate>(PhaseNode_GetRotation::TRIGGER_DONE, 30, PhaseNode_OffsetCalculate::FUNC_DO, &PhaseNode_OffsetCalculate::Do);
}

REGISTER_CREATE_SKILL_NODE(22103, 29) {
    auto node29 = GET_SKILL_NODE(29, PhaseNode_GetRotation);
    if (node29 == nullptr) {
        node29 = new PhaseNode_GetRotation(29, phase);
        node29->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node29->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(22103, 29, node29)
    }
    if (noInit == true) {
        return node29;
    }
    return node29;
}
//--------------------------------------------------------------------------------
// OffsetCalculate
//
REGISTER_REGISTER_SKILL_NODE(22103, 30) {
    pnode->resizeTrigger(PhaseNode_OffsetCalculate::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnProjectile>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 16, PhaseNode_SpawnProjectile::FUNC_DO, &PhaseNode_SpawnProjectile::Do);
}

REGISTER_CREATE_SKILL_NODE(22103, 30) {
    auto node30 = GET_SKILL_NODE(30, PhaseNode_OffsetCalculate);
    if (node30 == nullptr) {
        node30 = new PhaseNode_OffsetCalculate(30, phase);
        node30->setPosZ(.00f);
        node30->setOffsetX(.20f);
        node30->setOffsetY(2.50f);
        node30->setOffsetZ(3.50f);
        node30->setRotOffset(.00f);
        CALL_REGISTER_SKILL_NODE(22103, 30, node30)
    }
    if (noInit == true) {
        return node30;
    }
    auto node28 = GET_SKILL_NODE(28, PhaseNode_GetLocation);
    auto node29 = GET_SKILL_NODE(29, PhaseNode_GetRotation);
    if (node28 != nullptr) node30->setPosX(node28->getX());
    if (node28 != nullptr) node30->setPosY(node28->getY());
    if (node29 != nullptr) node30->setRotation(node29->getAngle());
    return node30;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22103, 31) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_Delay::TRIGGER_DONE, 33, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(22103, 31) {
    auto node31 = GET_SKILL_NODE(31, PhaseNode_Delay);
    if (node31 == nullptr) {
        node31 = new PhaseNode_Delay(31, phase);
        node31->setTime(.83f);
        CALL_REGISTER_SKILL_NODE(22103, 31, node31)
    }
    if (noInit == true) {
        return node31;
    }
    return node31;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(22103, 32) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 22, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(22103, 32) {
    auto node32 = GET_SKILL_NODE(32, PhaseNode_SkillEndNotify);
    if (node32 == nullptr) {
        node32 = new PhaseNode_SkillEndNotify(32, phase);
        node32->setReturnType(false);
        CALL_REGISTER_SKILL_NODE(22103, 32, node32)
    }
    if (noInit == true) {
        return node32;
    }
    return node32;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(22103, 33) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_FALSE, 34, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_TRUE, 32, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
}

REGISTER_CREATE_SKILL_NODE(22103, 33) {
    auto node33 = GET_SKILL_NODE(33, PhaseNode_If);
    if (node33 == nullptr) {
        node33 = new PhaseNode_If(33, phase);
        node33->setCondition(false);
        CALL_REGISTER_SKILL_NODE(22103, 33, node33)
    }
    if (noInit == true) {
        return node33;
    }
    return node33;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(22103, 34) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 22, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(22103, 34) {
    auto node34 = GET_SKILL_NODE(34, PhaseNode_SkillEndNotify);
    if (node34 == nullptr) {
        node34 = new PhaseNode_SkillEndNotify(34, phase);
        node34->setReturnType(true);
        CALL_REGISTER_SKILL_NODE(22103, 34, node34)
    }
    if (noInit == true) {
        return node34;
    }
    return node34;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(22103, 35) {
}

REGISTER_CREATE_SKILL_NODE(22103, 35) {
    auto node35 = GET_SKILL_NODE(35, PhaseNode_RaiseEvent);
    if (node35 == nullptr) {
        node35 = new PhaseNode_RaiseEvent(35, phase);
        node35->setEvent("MonsterInterrupt");
        node35->setTarget(0U);
        node35->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node35->setTypeParams(0, 0);
        node35->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(22103, 35, node35)
    }
    if (noInit == true) {
        return node35;
    }
    return node35;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(22103, 36) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_Detect::TRIGGER_ON, 39, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(22103, 36) {
    auto node36 = GET_SKILL_NODE(36, PhaseNode_Detect);
    if (node36 == nullptr) {
        node36 = new PhaseNode_Detect(36, phase);
        node36->setSelf(0U);
        node36->setEvent("MonsterInterrupt");
        node36->setType(PhaseNode_Detect::Detect_Type::Interrupt_Skill);
        node36->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(22103, 36, node36)
    }
    if (noInit == true) {
        return node36;
    }
    return node36;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(22103, 37) {
}

REGISTER_CREATE_SKILL_NODE(22103, 37) {
    auto node37 = GET_SKILL_NODE(37, PhaseNode_EndPhase);
    if (node37 == nullptr) {
        node37 = new PhaseNode_EndPhase(37, phase);
        node37->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node37->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(22103, 37, node37)
    }
    if (noInit == true) {
        return node37;
    }
    return node37;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22103, 39) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_Delay::TRIGGER_DONE, 41, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(22103, 39) {
    auto node39 = GET_SKILL_NODE(39, PhaseNode_Delay);
    if (node39 == nullptr) {
        node39 = new PhaseNode_Delay(39, phase);
        node39->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(22103, 39, node39)
    }
    if (noInit == true) {
        return node39;
    }
    return node39;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(22103, 40) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 37, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(22103, 40) {
    auto node40 = GET_SKILL_NODE(40, PhaseNode_SkillEndNotify);
    if (node40 == nullptr) {
        node40 = new PhaseNode_SkillEndNotify(40, phase);
        node40->setReturnType(false);
        CALL_REGISTER_SKILL_NODE(22103, 40, node40)
    }
    if (noInit == true) {
        return node40;
    }
    return node40;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(22103, 41) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_FALSE, 42, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_TRUE, 40, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
}

REGISTER_CREATE_SKILL_NODE(22103, 41) {
    auto node41 = GET_SKILL_NODE(41, PhaseNode_If);
    if (node41 == nullptr) {
        node41 = new PhaseNode_If(41, phase);
        node41->setCondition(false);
        CALL_REGISTER_SKILL_NODE(22103, 41, node41)
    }
    if (noInit == true) {
        return node41;
    }
    return node41;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(22103, 42) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 37, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(22103, 42) {
    auto node42 = GET_SKILL_NODE(42, PhaseNode_SkillEndNotify);
    if (node42 == nullptr) {
        node42 = new PhaseNode_SkillEndNotify(42, phase);
        node42->setReturnType(true);
        CALL_REGISTER_SKILL_NODE(22103, 42, node42)
    }
    if (noInit == true) {
        return node42;
    }
    return node42;
}

//--------------------------------------------------------------------------------
// SkillCreator_22103
//
class SkillCreator_22103 : public SkillCreator {
public:
    SkillCreator_22103() {}
    virtual ~SkillCreator_22103() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_22103

//--------------------------------------------------------------------------------
// SkillPhase_22103
//
class SkillPhase_22103 : public SkillPhase {
public:
    SkillPhase_22103(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_22103() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(22103, 3) // StartPhase
        CASE_CREATE_SKILL_NODE(22103, 5) // TriggerUpdate
        CASE_CREATE_SKILL_NODE(22103, 8) // GetBBParamUInt64
        CASE_CREATE_SKILL_NODE(22103, 10) // GetLocation
        CASE_CREATE_SKILL_NODE(22103, 12) // Delay
        CASE_CREATE_SKILL_NODE(22103, 16) // SpawnProjectile
        CASE_CREATE_SKILL_NODE(22103, 22) // EndPhase
        CASE_CREATE_SKILL_NODE(22103, 24) // ResetCD
        CASE_CREATE_SKILL_NODE(22103, 25) // PlayAnimation
        CASE_CREATE_SKILL_NODE(22103, 26) // PlaySound
        CASE_CREATE_SKILL_NODE(22103, 27) // Delay
        CASE_CREATE_SKILL_NODE(22103, 28) // GetLocation
        CASE_CREATE_SKILL_NODE(22103, 29) // GetRotation
        CASE_CREATE_SKILL_NODE(22103, 30) // OffsetCalculate
        CASE_CREATE_SKILL_NODE(22103, 31) // Delay
        CASE_CREATE_SKILL_NODE(22103, 32) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(22103, 33) // If
        CASE_CREATE_SKILL_NODE(22103, 34) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(22103, 35) // RaiseEvent
        CASE_CREATE_SKILL_NODE(22103, 36) // Detect
        CASE_CREATE_SKILL_NODE(22103, 37) // EndPhase
        CASE_CREATE_SKILL_NODE(22103, 39) // Delay
        CASE_CREATE_SKILL_NODE(22103, 40) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(22103, 41) // If
        CASE_CREATE_SKILL_NODE(22103, 42) // SkillEndNotify
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_22103

SkillLogic* SkillCreator_22103::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //创建阶段phase
    auto phase = new SkillPhase_22103(1, logic, 3);
    //设置phase执行器
    phase->setRunPhaseNode(1, 3);
    phase->setRunPhaseNode(2, 5);
    phase->setDetectPhaseNode(3, 36);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_22103::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
