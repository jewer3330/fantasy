#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

#include "skill_psnode_detect.h"
#include "skill_psnode_resetcd.h"
#include "skill_psnode_resetskill.h"

namespace pvp {

//变量声明
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10134, 3) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_Detect::TRIGGER_ON, 5, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(10134, 3) {
    auto node3 = GET_SKILL_NODE(3, PhaseNode_Detect);
    if (node3 == nullptr) {
        node3 = new PhaseNode_Detect(3, phase);
        node3->setSelf(0U);
        node3->setEvent("");
        node3->setType(PhaseNode_Detect::Detect_Type::Cause_Damage);
        node3->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10134, 3, node3)
    }
    if (noInit == true) {
        return node3;
    }
    return node3;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(10134, 5) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ResetSkill>(PhaseNode_ResetCD::TRIGGER_DONE, 8, PhaseNode_ResetSkill::FUNC_DO, &PhaseNode_ResetSkill::Do);
}

REGISTER_CREATE_SKILL_NODE(10134, 5) {
    auto node5 = GET_SKILL_NODE(5, PhaseNode_ResetCD);
    if (node5 == nullptr) {
        node5 = new PhaseNode_ResetCD(5, phase);
        node5->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node5->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node5->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(10134, 5, node5)
    }
    if (noInit == true) {
        return node5;
    }
    return node5;
}
//--------------------------------------------------------------------------------
// ResetSkill
//
REGISTER_REGISTER_SKILL_NODE(10134, 8) {
}

REGISTER_CREATE_SKILL_NODE(10134, 8) {
    auto node8 = GET_SKILL_NODE(8, PhaseNode_ResetSkill);
    if (node8 == nullptr) {
        node8 = new PhaseNode_ResetSkill(8, phase);
        node8->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node8->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node8->setSkillID({10132});
        node8->setTime(1.00f);
        CALL_REGISTER_SKILL_NODE(10134, 8, node8)
    }
    if (noInit == true) {
        return node8;
    }
    return node8;
}

//--------------------------------------------------------------------------------
// SkillCreator_10134
//
class SkillCreator_10134 : public SkillCreator {
public:
    SkillCreator_10134() {}
    virtual ~SkillCreator_10134() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_10134

//--------------------------------------------------------------------------------
// SkillPhase_10134
//
class SkillPhase_10134 : public SkillPhase {
public:
    SkillPhase_10134(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_10134() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(10134, 3) // Detect
        CASE_CREATE_SKILL_NODE(10134, 5) // ResetCD
        CASE_CREATE_SKILL_NODE(10134, 8) // ResetSkill
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_10134

SkillLogic* SkillCreator_10134::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //创建阶段phase
    auto phase = new SkillPhase_10134(1, logic, 1);
    //设置phase执行器
    phase->setDetectPhaseNode(1, 3);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_10134::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
