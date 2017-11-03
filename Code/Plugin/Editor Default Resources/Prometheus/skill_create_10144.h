#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

#include "skill_psnode_detect.h"
#include "skill_psnode_resetskill.h"

namespace pvp {

//变量声明
//--------------------------------------------------------------------------------
// ResetSkill
//
REGISTER_REGISTER_SKILL_NODE(10144, 6) {
}

REGISTER_CREATE_SKILL_NODE(10144, 6) {
    auto node6 = GET_SKILL_NODE(6, PhaseNode_ResetSkill);
    if (node6 == nullptr) {
        node6 = new PhaseNode_ResetSkill(6, phase);
        node6->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node6->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node6->setSkillID({10141});
        node6->setTime(15.00f);
        CALL_REGISTER_SKILL_NODE(10144, 6, node6)
    }
    if (noInit == true) {
        return node6;
    }
    return node6;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10144, 8) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ResetSkill>(PhaseNode_Detect::TRIGGER_ON, 6, PhaseNode_ResetSkill::FUNC_DO, &PhaseNode_ResetSkill::Do);
}

REGISTER_CREATE_SKILL_NODE(10144, 8) {
    auto node8 = GET_SKILL_NODE(8, PhaseNode_Detect);
    if (node8 == nullptr) {
        node8 = new PhaseNode_Detect(8, phase);
        node8->setSelf(0U);
        node8->setEvent("");
        node8->setType(PhaseNode_Detect::Detect_Type::Kill_Target);
        node8->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10144, 8, node8)
    }
    if (noInit == true) {
        return node8;
    }
    return node8;
}

//--------------------------------------------------------------------------------
// SkillCreator_10144
//
class SkillCreator_10144 : public SkillCreator {
public:
    SkillCreator_10144() {}
    virtual ~SkillCreator_10144() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_10144

//--------------------------------------------------------------------------------
// SkillPhase_10144
//
class SkillPhase_10144 : public SkillPhase {
public:
    SkillPhase_10144(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_10144() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(10144, 6) // ResetSkill
        CASE_CREATE_SKILL_NODE(10144, 8) // Detect
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_10144

SkillLogic* SkillCreator_10144::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //创建阶段phase
    auto phase = new SkillPhase_10144(1, logic, 1);
    //设置phase执行器
    phase->setDetectPhaseNode(1, 8);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_10144::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
