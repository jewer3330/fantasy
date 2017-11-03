#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

#include "skill_psnode_addskillbuff.h"
#include "skill_psnode_detect.h"

namespace pvp {

//变量声明
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(102, 4) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuff>(PhaseNode_Detect::TRIGGER_ON, 6, PhaseNode_AddSkillBuff::FUNC_ADD, &PhaseNode_AddSkillBuff::Add);
}

REGISTER_CREATE_SKILL_NODE(102, 4) {
    auto node4 = GET_SKILL_NODE(4, PhaseNode_Detect);
    if (node4 == nullptr) {
        node4 = new PhaseNode_Detect(4, phase);
        node4->setSelf(0U);
        node4->setEvent("");
        node4->setType(PhaseNode_Detect::Detect_Type::Assistant_Kill);
        CALL_REGISTER_SKILL_NODE(102, 4, node4)
    }
    if (noInit == true) {
        return node4;
    }
    return node4;
}
//--------------------------------------------------------------------------------
// AddSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(102, 6) {
}

REGISTER_CREATE_SKILL_NODE(102, 6) {
    auto node6 = GET_SKILL_NODE(6, PhaseNode_AddSkillBuff);
    if (node6 == nullptr) {
        node6 = new PhaseNode_AddSkillBuff(6, phase);
        node6->setConfigID(1021);
        node6->setConfigIDs({});
        node6->setTarget(0U);
        node6->setAttribute({{}});
        CALL_REGISTER_SKILL_NODE(102, 6, node6)
    }
    if (noInit == true) {
        return node6;
    }
    return node6;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(102, 8) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuff>(PhaseNode_Detect::TRIGGER_ON, 6, PhaseNode_AddSkillBuff::FUNC_ADD, &PhaseNode_AddSkillBuff::Add);
}

REGISTER_CREATE_SKILL_NODE(102, 8) {
    auto node8 = GET_SKILL_NODE(8, PhaseNode_Detect);
    if (node8 == nullptr) {
        node8 = new PhaseNode_Detect(8, phase);
        node8->setSelf(0U);
        node8->setEvent("");
        node8->setType(PhaseNode_Detect::Detect_Type::Kill_Target);
        CALL_REGISTER_SKILL_NODE(102, 8, node8)
    }
    if (noInit == true) {
        return node8;
    }
    return node8;
}

//--------------------------------------------------------------------------------
// SkillCreator_102
//
class SkillCreator_102 : public SkillCreator {
public:
    SkillCreator_102() {}
    virtual ~SkillCreator_102() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_102

//--------------------------------------------------------------------------------
// SkillPhase_102
//
class SkillPhase_102 : public SkillPhase {
public:
    SkillPhase_102(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_102() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(102, 4) // Detect
        CASE_CREATE_SKILL_NODE(102, 6) // AddSkillBuff
        CASE_CREATE_SKILL_NODE(102, 8) // Detect
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_102

SkillLogic* SkillCreator_102::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //创建阶段phase
    auto phase = new SkillPhase_102(1, logic, 1);
    //设置phase执行器
    phase->setDetectPhaseNode(1, 4);
    phase->setDetectPhaseNode(1, 8);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_102::getSkillExpend(int32_t& nType, int32_t& nValue) {
    nType = Skill::E_SkillExpend_PASSIVITY;
    return true;
}
} // namespace pvp
