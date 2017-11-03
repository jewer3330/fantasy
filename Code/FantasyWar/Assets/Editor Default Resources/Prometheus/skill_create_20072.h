#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

#include "skill_psnode_delay.h"
#include "skill_psnode_distance.h"
#include "skill_psnode_endphase.h"
#include "skill_psnode_floatoperation.h"
#include "skill_psnode_getinputlocation.h"
#include "skill_psnode_getlocation.h"
#include "skill_psnode_getrotation.h"
#include "skill_psnode_offsetcalculate.h"
#include "skill_psnode_playanimation.h"
#include "skill_psnode_resetcd.h"
#include "skill_psnode_spawncollider.h"
#include "skill_psnode_startphase.h"
#include "skill_psnode_triggerupdate.h"

namespace pvp {

//变量声明
//--------------------------------------------------------------------------------
// StartPhase
//
REGISTER_REGISTER_SKILL_NODE(20072, 1) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_StartPhase::TRIGGER_START, 3, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(20072, 1) {
    auto node1 = GET_SKILL_NODE(1, PhaseNode_StartPhase);
    if (node1 == nullptr) {
        node1 = new PhaseNode_StartPhase(1, phase);
        CALL_REGISTER_SKILL_NODE(20072, 1, node1)
    }
    if (noInit == true) {
        return node1;
    }
    return node1;
}
//--------------------------------------------------------------------------------
// TriggerUpdate
//
REGISTER_REGISTER_SKILL_NODE(20072, 2) {
}

REGISTER_CREATE_SKILL_NODE(20072, 2) {
    auto node2 = GET_SKILL_NODE(2, PhaseNode_TriggerUpdate);
    if (node2 == nullptr) {
        node2 = new PhaseNode_TriggerUpdate(2, phase);
        CALL_REGISTER_SKILL_NODE(20072, 2, node2)
    }
    if (noInit == true) {
        return node2;
    }
    return node2;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(20072, 3) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_ResetCD::TRIGGER_DONE, 4, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(20072, 3) {
    auto node3 = GET_SKILL_NODE(3, PhaseNode_ResetCD);
    if (node3 == nullptr) {
        node3 = new PhaseNode_ResetCD(3, phase);
        node3->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node3->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node3->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(20072, 3, node3)
    }
    if (noInit == true) {
        return node3;
    }
    return node3;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(20072, 4) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetRotation>(PhaseNode_GetLocation::TRIGGER_DONE, 5, PhaseNode_GetRotation::FUNC_DO, &PhaseNode_GetRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(20072, 4) {
    auto node4 = GET_SKILL_NODE(4, PhaseNode_GetLocation);
    if (node4 == nullptr) {
        node4 = new PhaseNode_GetLocation(4, phase);
        node4->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node4->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(20072, 4, node4)
    }
    if (noInit == true) {
        return node4;
    }
    return node4;
}
//--------------------------------------------------------------------------------
// GetRotation
//
REGISTER_REGISTER_SKILL_NODE(20072, 5) {
    pnode->resizeTrigger(PhaseNode_GetRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_GetRotation::TRIGGER_DONE, 6, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(20072, 5) {
    auto node5 = GET_SKILL_NODE(5, PhaseNode_GetRotation);
    if (node5 == nullptr) {
        node5 = new PhaseNode_GetRotation(5, phase);
        node5->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node5->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(20072, 5, node5)
    }
    if (noInit == true) {
        return node5;
    }
    return node5;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(20072, 6) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_OffsetCalculate>(PhaseNode_PlayAnimation::TRIGGER_DONE, 8, PhaseNode_OffsetCalculate::FUNC_DO, &PhaseNode_OffsetCalculate::Do);
}

REGISTER_CREATE_SKILL_NODE(20072, 6) {
    auto node6 = GET_SKILL_NODE(6, PhaseNode_PlayAnimation);
    if (node6 == nullptr) {
        node6 = new PhaseNode_PlayAnimation(6, phase);
        node6->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node6->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node6->setTarget(0U);
        node6->setAnimation("Skill2S1");
        node6->setParameter("");
        node6->setValue(false);
        CALL_REGISTER_SKILL_NODE(20072, 6, node6)
    }
    if (noInit == true) {
        return node6;
    }
    return node6;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(20072, 7) {
}

REGISTER_CREATE_SKILL_NODE(20072, 7) {
    auto node7 = GET_SKILL_NODE(7, PhaseNode_Delay);
    if (node7 == nullptr) {
        node7 = new PhaseNode_Delay(7, phase);
        node7->setTime(.70f);
        CALL_REGISTER_SKILL_NODE(20072, 7, node7)
    }
    if (noInit == true) {
        return node7;
    }
    return node7;
}
//--------------------------------------------------------------------------------
// OffsetCalculate
//
REGISTER_REGISTER_SKILL_NODE(20072, 8) {
    pnode->resizeTrigger(PhaseNode_OffsetCalculate::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetInputLocation>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 9, PhaseNode_GetInputLocation::FUNC_DO, &PhaseNode_GetInputLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(20072, 8) {
    auto node8 = GET_SKILL_NODE(8, PhaseNode_OffsetCalculate);
    if (node8 == nullptr) {
        node8 = new PhaseNode_OffsetCalculate(8, phase);
        node8->setPosZ(.00f);
        node8->setOffsetX(1.00f);
        node8->setOffsetY(5.00f);
        node8->setOffsetZ(7.00f);
        node8->setRotOffset(.00f);
        CALL_REGISTER_SKILL_NODE(20072, 8, node8)
    }
    if (noInit == true) {
        return node8;
    }
    auto node4 = GET_SKILL_NODE(4, PhaseNode_GetLocation);
    auto node5 = GET_SKILL_NODE(5, PhaseNode_GetRotation);
    if (node4 != nullptr) node8->setPosX(node4->getX());
    if (node4 != nullptr) node8->setPosY(node4->getY());
    if (node5 != nullptr) node8->setRotation(node5->getAngle());
    return node8;
}
//--------------------------------------------------------------------------------
// GetInputLocation
//
REGISTER_REGISTER_SKILL_NODE(20072, 9) {
    pnode->resizeTrigger(PhaseNode_GetInputLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Distance>(PhaseNode_GetInputLocation::TRIGGER_DONE, 16, PhaseNode_Distance::FUNC_DO, &PhaseNode_Distance::Do);
    pnode->regTrigger<PhaseNode_SpawnCollider>(PhaseNode_GetInputLocation::TRIGGER_DONE, 45, PhaseNode_SpawnCollider::FUNC_DO, &PhaseNode_SpawnCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(20072, 9) {
    auto node9 = GET_SKILL_NODE(9, PhaseNode_GetInputLocation);
    if (node9 == nullptr) {
        node9 = new PhaseNode_GetInputLocation(9, phase);
        node9->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        CALL_REGISTER_SKILL_NODE(20072, 9, node9)
    }
    if (noInit == true) {
        return node9;
    }
    return node9;
}
//--------------------------------------------------------------------------------
// Distance
//
REGISTER_REGISTER_SKILL_NODE(20072, 16) {
    pnode->resizeTrigger(PhaseNode_Distance::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_FloatOperation>(PhaseNode_Distance::TRIGGER_DONE, 146, PhaseNode_FloatOperation::FUNC_OPERATION, &PhaseNode_FloatOperation::Operation);
}

REGISTER_CREATE_SKILL_NODE(20072, 16) {
    auto node16 = GET_SKILL_NODE(16, PhaseNode_Distance);
    if (node16 == nullptr) {
        node16 = new PhaseNode_Distance(16, phase);
        CALL_REGISTER_SKILL_NODE(20072, 16, node16)
    }
    if (noInit == true) {
        return node16;
    }
    auto node4 = GET_SKILL_NODE(4, PhaseNode_GetLocation);
    auto node9 = GET_SKILL_NODE(9, PhaseNode_GetInputLocation);
    if (node4 != nullptr) node16->setAX(node4->getX());
    if (node4 != nullptr) node16->setAY(node4->getY());
    if (node9 != nullptr) node16->setBX(node9->getX());
    if (node9 != nullptr) node16->setBY(node9->getY());
    return node16;
}
//--------------------------------------------------------------------------------
// OffsetCalculate
//
REGISTER_REGISTER_SKILL_NODE(20072, 17) {
    pnode->resizeTrigger(PhaseNode_OffsetCalculate::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_OffsetCalculate>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 18, PhaseNode_OffsetCalculate::FUNC_DO, &PhaseNode_OffsetCalculate::Do);
    pnode->regTrigger<PhaseNode_SpawnCollider>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 40, PhaseNode_SpawnCollider::FUNC_DO, &PhaseNode_SpawnCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(20072, 17) {
    auto node17 = GET_SKILL_NODE(17, PhaseNode_OffsetCalculate);
    if (node17 == nullptr) {
        node17 = new PhaseNode_OffsetCalculate(17, phase);
        node17->setPosZ(.00f);
        node17->setOffsetX(.00f);
        node17->setOffsetZ(.00f);
        node17->setRotOffset(.00f);
        CALL_REGISTER_SKILL_NODE(20072, 17, node17)
    }
    if (noInit == true) {
        return node17;
    }
    auto node4 = GET_SKILL_NODE(4, PhaseNode_GetLocation);
    auto node16 = GET_SKILL_NODE(16, PhaseNode_Distance);
    auto node146 = GET_SKILL_NODE(146, PhaseNode_FloatOperation);
    if (node4 != nullptr) node17->setPosX(node4->getX());
    if (node4 != nullptr) node17->setPosY(node4->getY());
    if (node16 != nullptr) node17->setOffsetY(node16->getResult());
    if (node146 != nullptr) node17->setRotation(node146->getFinal());
    return node17;
}
//--------------------------------------------------------------------------------
// OffsetCalculate
//
REGISTER_REGISTER_SKILL_NODE(20072, 18) {
    pnode->resizeTrigger(PhaseNode_OffsetCalculate::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 7, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_SpawnCollider>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 237, PhaseNode_SpawnCollider::FUNC_DO, &PhaseNode_SpawnCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(20072, 18) {
    auto node18 = GET_SKILL_NODE(18, PhaseNode_OffsetCalculate);
    if (node18 == nullptr) {
        node18 = new PhaseNode_OffsetCalculate(18, phase);
        node18->setPosZ(.00f);
        node18->setOffsetX(.00f);
        node18->setOffsetZ(.00f);
        node18->setRotOffset(.00f);
        CALL_REGISTER_SKILL_NODE(20072, 18, node18)
    }
    if (noInit == true) {
        return node18;
    }
    auto node4 = GET_SKILL_NODE(4, PhaseNode_GetLocation);
    auto node16 = GET_SKILL_NODE(16, PhaseNode_Distance);
    auto node179 = GET_SKILL_NODE(179, PhaseNode_FloatOperation);
    if (node4 != nullptr) node18->setPosX(node4->getX());
    if (node4 != nullptr) node18->setPosY(node4->getY());
    if (node16 != nullptr) node18->setOffsetY(node16->getResult());
    if (node179 != nullptr) node18->setRotation(node179->getFinal());
    return node18;
}
//--------------------------------------------------------------------------------
// SpawnCollider
//
REGISTER_REGISTER_SKILL_NODE(20072, 40) {
}

REGISTER_CREATE_SKILL_NODE(20072, 40) {
    auto node40 = GET_SKILL_NODE(40, PhaseNode_SpawnCollider);
    if (node40 == nullptr) {
        node40 = new PhaseNode_SpawnCollider(40, phase);
        node40->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node40->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node40->setMesh("");
        node40->setMeshScale(.00f);
        node40->setEffectID(1014);
        node40->setEffectScale(1.00f);
        node40->setType(PhaseNode_SpawnCollider::SpawnCollider_Type::Circle);
        node40->setTypeParams(0, .00f);
        node40->setTime(.00f);
        node40->setPosZ(.20f);
        node40->setRotation(.00f);
        node40->setreentry(false);
        node40->setCheckPeneSound(false);
        CALL_REGISTER_SKILL_NODE(20072, 40, node40)
    }
    if (noInit == true) {
        return node40;
    }
    auto node17 = GET_SKILL_NODE(17, PhaseNode_OffsetCalculate);
    if (node17 != nullptr) node40->setPosX(node17->getOutPosX());
    if (node17 != nullptr) node40->setPosY(node17->getOutPosY());
    return node40;
}
//--------------------------------------------------------------------------------
// SpawnCollider
//
REGISTER_REGISTER_SKILL_NODE(20072, 45) {
}

REGISTER_CREATE_SKILL_NODE(20072, 45) {
    auto node45 = GET_SKILL_NODE(45, PhaseNode_SpawnCollider);
    if (node45 == nullptr) {
        node45 = new PhaseNode_SpawnCollider(45, phase);
        node45->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node45->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node45->setMesh("");
        node45->setMeshScale(.00f);
        node45->setEffectID(1014);
        node45->setEffectScale(1.00f);
        node45->setType(PhaseNode_SpawnCollider::SpawnCollider_Type::Circle);
        node45->setTypeParams(0, .00f);
        node45->setTime(.00f);
        node45->setPosZ(.20f);
        node45->setRotation(.00f);
        node45->setreentry(false);
        node45->setCheckPeneSound(false);
        CALL_REGISTER_SKILL_NODE(20072, 45, node45)
    }
    if (noInit == true) {
        return node45;
    }
    auto node9 = GET_SKILL_NODE(9, PhaseNode_GetInputLocation);
    if (node9 != nullptr) node45->setPosX(node9->getX());
    if (node9 != nullptr) node45->setPosY(node9->getY());
    return node45;
}
//--------------------------------------------------------------------------------
// FloatOperation
//
REGISTER_REGISTER_SKILL_NODE(20072, 146) {
    pnode->resizeTrigger(PhaseNode_FloatOperation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_FloatOperation>(PhaseNode_FloatOperation::TRIGGER_DONE, 179, PhaseNode_FloatOperation::FUNC_OPERATION, &PhaseNode_FloatOperation::Operation);
}

REGISTER_CREATE_SKILL_NODE(20072, 146) {
    auto node146 = GET_SKILL_NODE(146, PhaseNode_FloatOperation);
    if (node146 == nullptr) {
        node146 = new PhaseNode_FloatOperation(146, phase);
        node146->setValue(30.00f);
        node146->setMethod(PhaseNode_FloatOperation::FloatOperation_Method::Add);
        CALL_REGISTER_SKILL_NODE(20072, 146, node146)
    }
    if (noInit == true) {
        return node146;
    }
    auto node5 = GET_SKILL_NODE(5, PhaseNode_GetRotation);
    if (node5 != nullptr) node146->setBase(node5->getAngle());
    return node146;
}
//--------------------------------------------------------------------------------
// FloatOperation
//
REGISTER_REGISTER_SKILL_NODE(20072, 179) {
    pnode->resizeTrigger(PhaseNode_FloatOperation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_OffsetCalculate>(PhaseNode_FloatOperation::TRIGGER_DONE, 17, PhaseNode_OffsetCalculate::FUNC_DO, &PhaseNode_OffsetCalculate::Do);
}

REGISTER_CREATE_SKILL_NODE(20072, 179) {
    auto node179 = GET_SKILL_NODE(179, PhaseNode_FloatOperation);
    if (node179 == nullptr) {
        node179 = new PhaseNode_FloatOperation(179, phase);
        node179->setValue(30.00f);
        node179->setMethod(PhaseNode_FloatOperation::FloatOperation_Method::Sub);
        CALL_REGISTER_SKILL_NODE(20072, 179, node179)
    }
    if (noInit == true) {
        return node179;
    }
    auto node5 = GET_SKILL_NODE(5, PhaseNode_GetRotation);
    if (node5 != nullptr) node179->setBase(node5->getAngle());
    return node179;
}
//--------------------------------------------------------------------------------
// SpawnCollider
//
REGISTER_REGISTER_SKILL_NODE(20072, 237) {
}

REGISTER_CREATE_SKILL_NODE(20072, 237) {
    auto node237 = GET_SKILL_NODE(237, PhaseNode_SpawnCollider);
    if (node237 == nullptr) {
        node237 = new PhaseNode_SpawnCollider(237, phase);
        node237->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node237->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node237->setMesh("");
        node237->setMeshScale(.00f);
        node237->setEffectID(1014);
        node237->setEffectScale(1.00f);
        node237->setType(PhaseNode_SpawnCollider::SpawnCollider_Type::Circle);
        node237->setTypeParams(0, .00f);
        node237->setTime(.00f);
        node237->setPosZ(.20f);
        node237->setRotation(.00f);
        node237->setreentry(false);
        node237->setCheckPeneSound(false);
        CALL_REGISTER_SKILL_NODE(20072, 237, node237)
    }
    if (noInit == true) {
        return node237;
    }
    auto node18 = GET_SKILL_NODE(18, PhaseNode_OffsetCalculate);
    if (node18 != nullptr) node237->setPosX(node18->getOutPosX());
    if (node18 != nullptr) node237->setPosY(node18->getOutPosY());
    return node237;
}

//--------------------------------------------------------------------------------
// SkillCreator_20072
//
class SkillCreator_20072 : public SkillCreator {
public:
    SkillCreator_20072() {}
    virtual ~SkillCreator_20072() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_20072

//--------------------------------------------------------------------------------
// SkillPhase_20072
//
class SkillPhase_20072 : public SkillPhase {
public:
    SkillPhase_20072(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_20072() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(20072, 1) // StartPhase
        CASE_CREATE_SKILL_NODE(20072, 2) // TriggerUpdate
        CASE_CREATE_SKILL_NODE(20072, 3) // ResetCD
        CASE_CREATE_SKILL_NODE(20072, 4) // GetLocation
        CASE_CREATE_SKILL_NODE(20072, 5) // GetRotation
        CASE_CREATE_SKILL_NODE(20072, 6) // PlayAnimation
        CASE_CREATE_SKILL_NODE(20072, 7) // Delay
        CASE_CREATE_SKILL_NODE(20072, 8) // OffsetCalculate
        CASE_CREATE_SKILL_NODE(20072, 9) // GetInputLocation
        CASE_CREATE_SKILL_NODE(20072, 16) // Distance
        CASE_CREATE_SKILL_NODE(20072, 17) // OffsetCalculate
        CASE_CREATE_SKILL_NODE(20072, 18) // OffsetCalculate
        CASE_CREATE_SKILL_NODE(20072, 40) // SpawnCollider
        CASE_CREATE_SKILL_NODE(20072, 45) // SpawnCollider
        CASE_CREATE_SKILL_NODE(20072, 146) // FloatOperation
        CASE_CREATE_SKILL_NODE(20072, 179) // FloatOperation
        CASE_CREATE_SKILL_NODE(20072, 237) // SpawnCollider
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_20072

SkillLogic* SkillCreator_20072::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //创建阶段phase
    auto phase = new SkillPhase_20072(1, logic, 2);
    //设置phase执行器
    phase->setRunPhaseNode(1, 1);
    phase->setRunPhaseNode(2, 2);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_20072::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
