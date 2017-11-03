#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

#include "skill_psnode_delay.h"
#include "skill_psnode_endphase.h"
#include "skill_psnode_floatoperation.h"
#include "skill_psnode_getlocation.h"
#include "skill_psnode_getrotation.h"
#include "skill_psnode_offsetcalculate.h"
#include "skill_psnode_playanimation.h"
#include "skill_psnode_resetcd.h"
#include "skill_psnode_spawnprojectile.h"
#include "skill_psnode_startphase.h"
#include "skill_psnode_triggerupdate.h"

namespace pvp {

//变量声明
//--------------------------------------------------------------------------------
// StartPhase
//
REGISTER_REGISTER_SKILL_NODE(23052, 2) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_StartPhase::TRIGGER_START, 6, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(23052, 2) {
    auto node2 = GET_SKILL_NODE(2, PhaseNode_StartPhase);
    if (node2 == nullptr) {
        node2 = new PhaseNode_StartPhase(2, phase);
        CALL_REGISTER_SKILL_NODE(23052, 2, node2)
    }
    if (noInit == true) {
        return node2;
    }
    return node2;
}
//--------------------------------------------------------------------------------
// TriggerUpdate
//
REGISTER_REGISTER_SKILL_NODE(23052, 4) {
}

REGISTER_CREATE_SKILL_NODE(23052, 4) {
    auto node4 = GET_SKILL_NODE(4, PhaseNode_TriggerUpdate);
    if (node4 == nullptr) {
        node4 = new PhaseNode_TriggerUpdate(4, phase);
        CALL_REGISTER_SKILL_NODE(23052, 4, node4)
    }
    if (noInit == true) {
        return node4;
    }
    return node4;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(23052, 6) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_ResetCD::TRIGGER_DONE, 8, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(23052, 6) {
    auto node6 = GET_SKILL_NODE(6, PhaseNode_ResetCD);
    if (node6 == nullptr) {
        node6 = new PhaseNode_ResetCD(6, phase);
        node6->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node6->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node6->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(23052, 6, node6)
    }
    if (noInit == true) {
        return node6;
    }
    return node6;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(23052, 8) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetRotation>(PhaseNode_GetLocation::TRIGGER_DONE, 10, PhaseNode_GetRotation::FUNC_DO, &PhaseNode_GetRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(23052, 8) {
    auto node8 = GET_SKILL_NODE(8, PhaseNode_GetLocation);
    if (node8 == nullptr) {
        node8 = new PhaseNode_GetLocation(8, phase);
        node8->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node8->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(23052, 8, node8)
    }
    if (noInit == true) {
        return node8;
    }
    return node8;
}
//--------------------------------------------------------------------------------
// GetRotation
//
REGISTER_REGISTER_SKILL_NODE(23052, 10) {
    pnode->resizeTrigger(PhaseNode_GetRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_OffsetCalculate>(PhaseNode_GetRotation::TRIGGER_DONE, 12, PhaseNode_OffsetCalculate::FUNC_DO, &PhaseNode_OffsetCalculate::Do);
}

REGISTER_CREATE_SKILL_NODE(23052, 10) {
    auto node10 = GET_SKILL_NODE(10, PhaseNode_GetRotation);
    if (node10 == nullptr) {
        node10 = new PhaseNode_GetRotation(10, phase);
        node10->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node10->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(23052, 10, node10)
    }
    if (noInit == true) {
        return node10;
    }
    return node10;
}
//--------------------------------------------------------------------------------
// OffsetCalculate
//
REGISTER_REGISTER_SKILL_NODE(23052, 12) {
    pnode->resizeTrigger(PhaseNode_OffsetCalculate::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 16, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(23052, 12) {
    auto node12 = GET_SKILL_NODE(12, PhaseNode_OffsetCalculate);
    if (node12 == nullptr) {
        node12 = new PhaseNode_OffsetCalculate(12, phase);
        node12->setPosZ(.00f);
        node12->setOffsetX(-.80f);
        node12->setOffsetY(3.00f);
        node12->setOffsetZ(2.50f);
        node12->setRotOffset(.00f);
        CALL_REGISTER_SKILL_NODE(23052, 12, node12)
    }
    if (noInit == true) {
        return node12;
    }
    auto node8 = GET_SKILL_NODE(8, PhaseNode_GetLocation);
    auto node10 = GET_SKILL_NODE(10, PhaseNode_GetRotation);
    if (node8 != nullptr) node12->setPosX(node8->getX());
    if (node8 != nullptr) node12->setPosY(node8->getY());
    if (node10 != nullptr) node12->setRotation(node10->getAngle());
    return node12;
}
//--------------------------------------------------------------------------------
// SpawnProjectile
//
REGISTER_REGISTER_SKILL_NODE(23052, 14) {
    pnode->resizeTrigger(PhaseNode_SpawnProjectile::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_SpawnProjectile::TRIGGER_DONE, 25, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(23052, 14) {
    auto node14 = GET_SKILL_NODE(14, PhaseNode_SpawnProjectile);
    if (node14 == nullptr) {
        node14 = new PhaseNode_SpawnProjectile(14, phase);
        node14->setDataId(52506);
        node14->setEndPosX(.00f);
        node14->setEndPosY(.00f);
        node14->setEndPosZ(.00f);
        node14->setMaxCount(0);
        CALL_REGISTER_SKILL_NODE(23052, 14, node14)
    }
    if (noInit == true) {
        return node14;
    }
    auto node12 = GET_SKILL_NODE(12, PhaseNode_OffsetCalculate);
    auto node28 = GET_SKILL_NODE(28, PhaseNode_FloatOperation);
    if (node12 != nullptr) node14->setPosX(node12->getOutPosX());
    if (node12 != nullptr) node14->setPosY(node12->getOutPosY());
    if (node12 != nullptr) node14->setPosZ(node12->getOutPosZ());
    if (node28 != nullptr) node14->setRotation(node28->getFinal());
    return node14;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(23052, 16) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlayAnimation::TRIGGER_DONE, 18, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(23052, 16) {
    auto node16 = GET_SKILL_NODE(16, PhaseNode_PlayAnimation);
    if (node16 == nullptr) {
        node16 = new PhaseNode_PlayAnimation(16, phase);
        node16->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node16->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node16->setTarget(0U);
        node16->setAnimation("Skill2S1");
        node16->setParameter("");
        node16->setValue(false);
        CALL_REGISTER_SKILL_NODE(23052, 16, node16)
    }
    if (noInit == true) {
        return node16;
    }
    return node16;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(23052, 18) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_FloatOperation>(PhaseNode_Delay::TRIGGER_DONE, 28, PhaseNode_FloatOperation::FUNC_OPERATION, &PhaseNode_FloatOperation::Operation);
}

REGISTER_CREATE_SKILL_NODE(23052, 18) {
    auto node18 = GET_SKILL_NODE(18, PhaseNode_Delay);
    if (node18 == nullptr) {
        node18 = new PhaseNode_Delay(18, phase);
        node18->setTime(.35f);
        CALL_REGISTER_SKILL_NODE(23052, 18, node18)
    }
    if (noInit == true) {
        return node18;
    }
    return node18;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(23052, 20) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_Delay::TRIGGER_DONE, 22, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(23052, 20) {
    auto node20 = GET_SKILL_NODE(20, PhaseNode_Delay);
    if (node20 == nullptr) {
        node20 = new PhaseNode_Delay(20, phase);
        node20->setTime(.45f);
        CALL_REGISTER_SKILL_NODE(23052, 20, node20)
    }
    if (noInit == true) {
        return node20;
    }
    return node20;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(23052, 22) {
}

REGISTER_CREATE_SKILL_NODE(23052, 22) {
    auto node22 = GET_SKILL_NODE(22, PhaseNode_EndPhase);
    if (node22 == nullptr) {
        node22 = new PhaseNode_EndPhase(22, phase);
        node22->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node22->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(23052, 22, node22)
    }
    if (noInit == true) {
        return node22;
    }
    return node22;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(23052, 25) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnProjectile>(PhaseNode_Delay::TRIGGER_DONE, 30, PhaseNode_SpawnProjectile::FUNC_DO, &PhaseNode_SpawnProjectile::Do);
}

REGISTER_CREATE_SKILL_NODE(23052, 25) {
    auto node25 = GET_SKILL_NODE(25, PhaseNode_Delay);
    if (node25 == nullptr) {
        node25 = new PhaseNode_Delay(25, phase);
        node25->setTime(.10f);
        CALL_REGISTER_SKILL_NODE(23052, 25, node25)
    }
    if (noInit == true) {
        return node25;
    }
    return node25;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(23052, 26) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnProjectile>(PhaseNode_Delay::TRIGGER_DONE, 31, PhaseNode_SpawnProjectile::FUNC_DO, &PhaseNode_SpawnProjectile::Do);
}

REGISTER_CREATE_SKILL_NODE(23052, 26) {
    auto node26 = GET_SKILL_NODE(26, PhaseNode_Delay);
    if (node26 == nullptr) {
        node26 = new PhaseNode_Delay(26, phase);
        node26->setTime(.10f);
        CALL_REGISTER_SKILL_NODE(23052, 26, node26)
    }
    if (noInit == true) {
        return node26;
    }
    return node26;
}
//--------------------------------------------------------------------------------
// FloatOperation
//
REGISTER_REGISTER_SKILL_NODE(23052, 28) {
    pnode->resizeTrigger(PhaseNode_FloatOperation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnProjectile>(PhaseNode_FloatOperation::TRIGGER_DONE, 14, PhaseNode_SpawnProjectile::FUNC_DO, &PhaseNode_SpawnProjectile::Do);
}

REGISTER_CREATE_SKILL_NODE(23052, 28) {
    auto node28 = GET_SKILL_NODE(28, PhaseNode_FloatOperation);
    if (node28 == nullptr) {
        node28 = new PhaseNode_FloatOperation(28, phase);
        node28->setValue(35.00f);
        node28->setMethod(PhaseNode_FloatOperation::FloatOperation_Method::Add);
        CALL_REGISTER_SKILL_NODE(23052, 28, node28)
    }
    if (noInit == true) {
        return node28;
    }
    auto node12 = GET_SKILL_NODE(12, PhaseNode_OffsetCalculate);
    if (node12 != nullptr) node28->setBase(node12->getOutRotation());
    return node28;
}
//--------------------------------------------------------------------------------
// FloatOperation
//
REGISTER_REGISTER_SKILL_NODE(23052, 29) {
    pnode->resizeTrigger(PhaseNode_FloatOperation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_FloatOperation::TRIGGER_DONE, 26, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(23052, 29) {
    auto node29 = GET_SKILL_NODE(29, PhaseNode_FloatOperation);
    if (node29 == nullptr) {
        node29 = new PhaseNode_FloatOperation(29, phase);
        node29->setValue(35.00f);
        node29->setMethod(PhaseNode_FloatOperation::FloatOperation_Method::Sub);
        CALL_REGISTER_SKILL_NODE(23052, 29, node29)
    }
    if (noInit == true) {
        return node29;
    }
    auto node12 = GET_SKILL_NODE(12, PhaseNode_OffsetCalculate);
    if (node12 != nullptr) node29->setBase(node12->getOutRotation());
    return node29;
}
//--------------------------------------------------------------------------------
// SpawnProjectile
//
REGISTER_REGISTER_SKILL_NODE(23052, 30) {
    pnode->resizeTrigger(PhaseNode_SpawnProjectile::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_FloatOperation>(PhaseNode_SpawnProjectile::TRIGGER_DONE, 29, PhaseNode_FloatOperation::FUNC_OPERATION, &PhaseNode_FloatOperation::Operation);
}

REGISTER_CREATE_SKILL_NODE(23052, 30) {
    auto node30 = GET_SKILL_NODE(30, PhaseNode_SpawnProjectile);
    if (node30 == nullptr) {
        node30 = new PhaseNode_SpawnProjectile(30, phase);
        node30->setDataId(52506);
        node30->setEndPosX(.00f);
        node30->setEndPosY(.00f);
        node30->setEndPosZ(.00f);
        node30->setMaxCount(0);
        CALL_REGISTER_SKILL_NODE(23052, 30, node30)
    }
    if (noInit == true) {
        return node30;
    }
    auto node12 = GET_SKILL_NODE(12, PhaseNode_OffsetCalculate);
    if (node12 != nullptr) node30->setPosX(node12->getOutPosX());
    if (node12 != nullptr) node30->setPosY(node12->getOutPosY());
    if (node12 != nullptr) node30->setPosZ(node12->getOutPosZ());
    if (node12 != nullptr) node30->setRotation(node12->getOutRotation());
    return node30;
}
//--------------------------------------------------------------------------------
// SpawnProjectile
//
REGISTER_REGISTER_SKILL_NODE(23052, 31) {
    pnode->resizeTrigger(PhaseNode_SpawnProjectile::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_SpawnProjectile::TRIGGER_DONE, 20, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(23052, 31) {
    auto node31 = GET_SKILL_NODE(31, PhaseNode_SpawnProjectile);
    if (node31 == nullptr) {
        node31 = new PhaseNode_SpawnProjectile(31, phase);
        node31->setDataId(52506);
        node31->setEndPosX(.00f);
        node31->setEndPosY(.00f);
        node31->setEndPosZ(.00f);
        node31->setMaxCount(0);
        CALL_REGISTER_SKILL_NODE(23052, 31, node31)
    }
    if (noInit == true) {
        return node31;
    }
    auto node12 = GET_SKILL_NODE(12, PhaseNode_OffsetCalculate);
    auto node29 = GET_SKILL_NODE(29, PhaseNode_FloatOperation);
    if (node12 != nullptr) node31->setPosX(node12->getOutPosX());
    if (node12 != nullptr) node31->setPosY(node12->getOutPosY());
    if (node12 != nullptr) node31->setPosZ(node12->getOutPosZ());
    if (node29 != nullptr) node31->setRotation(node29->getFinal());
    return node31;
}

//--------------------------------------------------------------------------------
// SkillCreator_23052
//
class SkillCreator_23052 : public SkillCreator {
public:
    SkillCreator_23052() {}
    virtual ~SkillCreator_23052() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_23052

//--------------------------------------------------------------------------------
// SkillPhase_23052
//
class SkillPhase_23052 : public SkillPhase {
public:
    SkillPhase_23052(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_23052() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(23052, 2) // StartPhase
        CASE_CREATE_SKILL_NODE(23052, 4) // TriggerUpdate
        CASE_CREATE_SKILL_NODE(23052, 6) // ResetCD
        CASE_CREATE_SKILL_NODE(23052, 8) // GetLocation
        CASE_CREATE_SKILL_NODE(23052, 10) // GetRotation
        CASE_CREATE_SKILL_NODE(23052, 12) // OffsetCalculate
        CASE_CREATE_SKILL_NODE(23052, 14) // SpawnProjectile
        CASE_CREATE_SKILL_NODE(23052, 16) // PlayAnimation
        CASE_CREATE_SKILL_NODE(23052, 18) // Delay
        CASE_CREATE_SKILL_NODE(23052, 20) // Delay
        CASE_CREATE_SKILL_NODE(23052, 22) // EndPhase
        CASE_CREATE_SKILL_NODE(23052, 25) // Delay
        CASE_CREATE_SKILL_NODE(23052, 26) // Delay
        CASE_CREATE_SKILL_NODE(23052, 28) // FloatOperation
        CASE_CREATE_SKILL_NODE(23052, 29) // FloatOperation
        CASE_CREATE_SKILL_NODE(23052, 30) // SpawnProjectile
        CASE_CREATE_SKILL_NODE(23052, 31) // SpawnProjectile
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_23052

SkillLogic* SkillCreator_23052::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //创建阶段phase
    auto phase = new SkillPhase_23052(1, logic, 2);
    //设置phase执行器
    phase->setRunPhaseNode(1, 2);
    phase->setRunPhaseNode(2, 4);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_23052::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
