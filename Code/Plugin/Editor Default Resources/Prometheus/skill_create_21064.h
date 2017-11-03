#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

#include "skill_psnode_camerashake.h"
#include "skill_psnode_skillendnotify.h"
#include "skill_psnode_startphase.h"

namespace pvp {

//变量声明
//--------------------------------------------------------------------------------
// StartPhase
//
REGISTER_REGISTER_SKILL_NODE(21064, 2) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CameraShake>(PhaseNode_StartPhase::TRIGGER_START, 4, PhaseNode_CameraShake::FUNC_DO, &PhaseNode_CameraShake::Do);
}

REGISTER_CREATE_SKILL_NODE(21064, 2) {
    auto node2 = GET_SKILL_NODE(2, PhaseNode_StartPhase);
    if (node2 == nullptr) {
        node2 = new PhaseNode_StartPhase(2, phase);
        CALL_REGISTER_SKILL_NODE(21064, 2, node2)
    }
    if (noInit == true) {
        return node2;
    }
    return node2;
}
//--------------------------------------------------------------------------------
// CameraShake
//
REGISTER_REGISTER_SKILL_NODE(21064, 4) {
    pnode->resizeTrigger(PhaseNode_CameraShake::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_CameraShake::TRIGGER_DONE, 8, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
}

REGISTER_CREATE_SKILL_NODE(21064, 4) {
    auto node4 = GET_SKILL_NODE(4, PhaseNode_CameraShake);
    if (node4 == nullptr) {
        node4 = new PhaseNode_CameraShake(4, phase);
        node4->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node4->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node4->setTarget(0U);
        node4->setFrequency(.05f);
        node4->setAmplitude(2.00f);
        node4->setDuration(.15f);
        node4->setFalloff(true);
        CALL_REGISTER_SKILL_NODE(21064, 4, node4)
    }
    if (noInit == true) {
        return node4;
    }
    return node4;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(21064, 8) {
}

REGISTER_CREATE_SKILL_NODE(21064, 8) {
    auto node8 = GET_SKILL_NODE(8, PhaseNode_SkillEndNotify);
    if (node8 == nullptr) {
        node8 = new PhaseNode_SkillEndNotify(8, phase);
        node8->setReturnType(true);
        CALL_REGISTER_SKILL_NODE(21064, 8, node8)
    }
    if (noInit == true) {
        return node8;
    }
    return node8;
}

//--------------------------------------------------------------------------------
// SkillCreator_21064
//
class SkillCreator_21064 : public SkillCreator {
public:
    SkillCreator_21064() {}
    virtual ~SkillCreator_21064() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_21064

//--------------------------------------------------------------------------------
// SkillPhase_21064
//
class SkillPhase_21064 : public SkillPhase {
public:
    SkillPhase_21064(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_21064() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(21064, 2) // StartPhase
        CASE_CREATE_SKILL_NODE(21064, 4) // CameraShake
        CASE_CREATE_SKILL_NODE(21064, 8) // SkillEndNotify
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_21064

SkillLogic* SkillCreator_21064::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //创建阶段phase
    auto phase = new SkillPhase_21064(1, logic, 1);
    //设置phase执行器
    phase->setRunPhaseNode(1, 2);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_21064::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
