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
REGISTER_REGISTER_SKILL_NODE(10104, 53) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_Detect::TRIGGER_ON, 54, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(10104, 53) {
    auto node53 = GET_SKILL_NODE(53, PhaseNode_Detect);
    if (node53 == nullptr) {
        node53 = new PhaseNode_Detect(53, phase);
        node53->setSelf(0U);
        node53->setEvent("");
        node53->setType(PhaseNode_Detect::Detect_Type::Cause_Damage);
        node53->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10104, 53, node53)
    }
    if (noInit == true) {
        return node53;
    }
    return node53;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(10104, 54) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ResetSkill>(PhaseNode_ResetCD::TRIGGER_DONE, 55, PhaseNode_ResetSkill::FUNC_DO, &PhaseNode_ResetSkill::Do);
}

REGISTER_CREATE_SKILL_NODE(10104, 54) {
    auto node54 = GET_SKILL_NODE(54, PhaseNode_ResetCD);
    if (node54 == nullptr) {
        node54 = new PhaseNode_ResetCD(54, phase);
        node54->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node54->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node54->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(10104, 54, node54)
    }
    if (noInit == true) {
        return node54;
    }
    return node54;
}
//--------------------------------------------------------------------------------
// ResetSkill
//
REGISTER_REGISTER_SKILL_NODE(10104, 55) {
}

REGISTER_CREATE_SKILL_NODE(10104, 55) {
    auto node55 = GET_SKILL_NODE(55, PhaseNode_ResetSkill);
    if (node55 == nullptr) {
        node55 = new PhaseNode_ResetSkill(55, phase);
        node55->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node55->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node55->setSkillID({10101});
        node55->setTime(1.00f);
        CALL_REGISTER_SKILL_NODE(10104, 55, node55)
    }
    if (noInit == true) {
        return node55;
    }
    return node55;
}

//--------------------------------------------------------------------------------
// SkillCreator_10104
//
class SkillCreator_10104 : public SkillCreator {
public:
    SkillCreator_10104() {}
    virtual ~SkillCreator_10104() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_10104

//--------------------------------------------------------------------------------
// SkillPhase_10104
//
class SkillPhase_10104 : public SkillPhase {
public:
    SkillPhase_10104(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_10104() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(10104, 53) // Detect
        CASE_CREATE_SKILL_NODE(10104, 54) // ResetCD
        CASE_CREATE_SKILL_NODE(10104, 55) // ResetSkill
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_10104

SkillLogic* SkillCreator_10104::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //创建阶段phase
    auto phase = new SkillPhase_10104(1, logic, 1);
    //设置phase执行器
    phase->setDetectPhaseNode(1, 53);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_10104::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
