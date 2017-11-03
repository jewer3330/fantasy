#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

#include "skill_psnode_delay.h"
#include "skill_psnode_destroycollider.h"
#include "skill_psnode_endphase.h"
#include "skill_psnode_getlocation.h"
#include "skill_psnode_getrotation.h"
#include "skill_psnode_offsetcalculate.h"
#include "skill_psnode_playanimation.h"
#include "skill_psnode_spawncollider.h"
#include "skill_psnode_startphase.h"
#include "skill_psnode_triggerupdate.h"

namespace pvp {

//变量声明
//--------------------------------------------------------------------------------
// StartPhase
//
REGISTER_REGISTER_SKILL_NODE(20073, 1) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_StartPhase::TRIGGER_START, 4, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(20073, 1) {
    auto node1 = GET_SKILL_NODE(1, PhaseNode_StartPhase);
    if (node1 == nullptr) {
        node1 = new PhaseNode_StartPhase(1, phase);
        CALL_REGISTER_SKILL_NODE(20073, 1, node1)
    }
    if (noInit == true) {
        return node1;
    }
    return node1;
}
//--------------------------------------------------------------------------------
// TriggerUpdate
//
REGISTER_REGISTER_SKILL_NODE(20073, 2) {
}

REGISTER_CREATE_SKILL_NODE(20073, 2) {
    auto node2 = GET_SKILL_NODE(2, PhaseNode_TriggerUpdate);
    if (node2 == nullptr) {
        node2 = new PhaseNode_TriggerUpdate(2, phase);
        CALL_REGISTER_SKILL_NODE(20073, 2, node2)
    }
    if (noInit == true) {
        return node2;
    }
    return node2;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(20073, 3) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_Delay::TRIGGER_DONE, 7, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(20073, 3) {
    auto node3 = GET_SKILL_NODE(3, PhaseNode_Delay);
    if (node3 == nullptr) {
        node3 = new PhaseNode_Delay(3, phase);
        node3->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(20073, 3, node3)
    }
    if (noInit == true) {
        return node3;
    }
    return node3;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(20073, 4) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetRotation>(PhaseNode_GetLocation::TRIGGER_DONE, 5, PhaseNode_GetRotation::FUNC_DO, &PhaseNode_GetRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(20073, 4) {
    auto node4 = GET_SKILL_NODE(4, PhaseNode_GetLocation);
    if (node4 == nullptr) {
        node4 = new PhaseNode_GetLocation(4, phase);
        node4->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node4->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(20073, 4, node4)
    }
    if (noInit == true) {
        return node4;
    }
    return node4;
}
//--------------------------------------------------------------------------------
// GetRotation
//
REGISTER_REGISTER_SKILL_NODE(20073, 5) {
    pnode->resizeTrigger(PhaseNode_GetRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_OffsetCalculate>(PhaseNode_GetRotation::TRIGGER_DONE, 6, PhaseNode_OffsetCalculate::FUNC_DO, &PhaseNode_OffsetCalculate::Do);
}

REGISTER_CREATE_SKILL_NODE(20073, 5) {
    auto node5 = GET_SKILL_NODE(5, PhaseNode_GetRotation);
    if (node5 == nullptr) {
        node5 = new PhaseNode_GetRotation(5, phase);
        node5->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node5->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(20073, 5, node5)
    }
    if (noInit == true) {
        return node5;
    }
    return node5;
}
//--------------------------------------------------------------------------------
// OffsetCalculate
//
REGISTER_REGISTER_SKILL_NODE(20073, 6) {
    pnode->resizeTrigger(PhaseNode_OffsetCalculate::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnCollider>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 9, PhaseNode_SpawnCollider::FUNC_DO, &PhaseNode_SpawnCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(20073, 6) {
    auto node6 = GET_SKILL_NODE(6, PhaseNode_OffsetCalculate);
    if (node6 == nullptr) {
        node6 = new PhaseNode_OffsetCalculate(6, phase);
        node6->setPosZ(.00f);
        node6->setOffsetX(.00f);
        node6->setOffsetY(7.00f);
        node6->setOffsetZ(.00f);
        node6->setRotOffset(.00f);
        CALL_REGISTER_SKILL_NODE(20073, 6, node6)
    }
    if (noInit == true) {
        return node6;
    }
    auto node4 = GET_SKILL_NODE(4, PhaseNode_GetLocation);
    auto node5 = GET_SKILL_NODE(5, PhaseNode_GetRotation);
    if (node4 != nullptr) node6->setPosX(node4->getX());
    if (node4 != nullptr) node6->setPosY(node4->getY());
    if (node5 != nullptr) node6->setRotation(node5->getAngle());
    return node6;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(20073, 7) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlayAnimation::TRIGGER_DONE, 8, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(20073, 7) {
    auto node7 = GET_SKILL_NODE(7, PhaseNode_PlayAnimation);
    if (node7 == nullptr) {
        node7 = new PhaseNode_PlayAnimation(7, phase);
        node7->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node7->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node7->setTarget(0U);
        node7->setAnimation("Skill3S1");
        node7->setParameter("");
        node7->setValue(false);
        CALL_REGISTER_SKILL_NODE(20073, 7, node7)
    }
    if (noInit == true) {
        return node7;
    }
    return node7;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(20073, 8) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnCollider>(PhaseNode_Delay::TRIGGER_DONE, 10, PhaseNode_SpawnCollider::FUNC_DO, &PhaseNode_SpawnCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(20073, 8) {
    auto node8 = GET_SKILL_NODE(8, PhaseNode_Delay);
    if (node8 == nullptr) {
        node8 = new PhaseNode_Delay(8, phase);
        node8->setTime(.80f);
        CALL_REGISTER_SKILL_NODE(20073, 8, node8)
    }
    if (noInit == true) {
        return node8;
    }
    return node8;
}
//--------------------------------------------------------------------------------
// SpawnCollider
//
REGISTER_REGISTER_SKILL_NODE(20073, 9) {
    pnode->resizeTrigger(PhaseNode_SpawnCollider::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_SpawnCollider::TRIGGER_DONE, 3, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(20073, 9) {
    auto node9 = GET_SKILL_NODE(9, PhaseNode_SpawnCollider);
    if (node9 == nullptr) {
        node9 = new PhaseNode_SpawnCollider(9, phase);
        node9->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node9->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node9->setMesh("");
        node9->setMeshScale(.00f);
        node9->setEffectID(1014);
        node9->setEffectScale(3.00f);
        node9->setType(PhaseNode_SpawnCollider::SpawnCollider_Type::Circle);
        node9->setTypeParams(0, .00f);
        node9->setTime(.00f);
        node9->setPosZ(.20f);
        node9->setreentry(false);
        node9->setCheckPeneSound(false);
        CALL_REGISTER_SKILL_NODE(20073, 9, node9)
    }
    if (noInit == true) {
        return node9;
    }
    auto node6 = GET_SKILL_NODE(6, PhaseNode_OffsetCalculate);
    if (node6 != nullptr) node9->setPosX(node6->getOutPosX());
    if (node6 != nullptr) node9->setPosY(node6->getOutPosY());
    if (node6 != nullptr) node9->setRotation(node6->getOutRotation());
    return node9;
}
//--------------------------------------------------------------------------------
// SpawnCollider
//
REGISTER_REGISTER_SKILL_NODE(20073, 10) {
}

REGISTER_CREATE_SKILL_NODE(20073, 10) {
    auto node10 = GET_SKILL_NODE(10, PhaseNode_SpawnCollider);
    if (node10 == nullptr) {
        node10 = new PhaseNode_SpawnCollider(10, phase);
        node10->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node10->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node10->setMesh("");
        node10->setMeshScale(.00f);
        node10->setEffectID(200732);
        node10->setEffectScale(1.00f);
        node10->setType(PhaseNode_SpawnCollider::SpawnCollider_Type::Circle);
        node10->setTypeParams(0, 6.00f);
        node10->setTime(.00f);
        node10->setPosZ(.00f);
        node10->setreentry(false);
        node10->setCheckPeneSound(false);
        CALL_REGISTER_SKILL_NODE(20073, 10, node10)
    }
    if (noInit == true) {
        return node10;
    }
    auto node6 = GET_SKILL_NODE(6, PhaseNode_OffsetCalculate);
    if (node6 != nullptr) node10->setPosX(node6->getOutPosX());
    if (node6 != nullptr) node10->setPosY(node6->getOutPosY());
    if (node6 != nullptr) node10->setRotation(node6->getOutRotation());
    return node10;
}

//--------------------------------------------------------------------------------
// SkillCreator_20073
//
class SkillCreator_20073 : public SkillCreator {
public:
    SkillCreator_20073() {}
    virtual ~SkillCreator_20073() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_20073

//--------------------------------------------------------------------------------
// SkillPhase_20073
//
class SkillPhase_20073 : public SkillPhase {
public:
    SkillPhase_20073(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_20073() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(20073, 1) // StartPhase
        CASE_CREATE_SKILL_NODE(20073, 2) // TriggerUpdate
        CASE_CREATE_SKILL_NODE(20073, 3) // Delay
        CASE_CREATE_SKILL_NODE(20073, 4) // GetLocation
        CASE_CREATE_SKILL_NODE(20073, 5) // GetRotation
        CASE_CREATE_SKILL_NODE(20073, 6) // OffsetCalculate
        CASE_CREATE_SKILL_NODE(20073, 7) // PlayAnimation
        CASE_CREATE_SKILL_NODE(20073, 8) // Delay
        CASE_CREATE_SKILL_NODE(20073, 9) // SpawnCollider
        CASE_CREATE_SKILL_NODE(20073, 10) // SpawnCollider
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_20073

SkillLogic* SkillCreator_20073::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //创建阶段phase
    auto phase = new SkillPhase_20073(1, logic, 2);
    //设置phase执行器
    phase->setRunPhaseNode(1, 1);
    phase->setRunPhaseNode(2, 2);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_20073::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
