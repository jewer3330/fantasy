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
REGISTER_REGISTER_SKILL_NODE(103, 3) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuff>(PhaseNode_Detect::TRIGGER_ON, 5, PhaseNode_AddSkillBuff::FUNC_ADD, &PhaseNode_AddSkillBuff::Add);
}

REGISTER_CREATE_SKILL_NODE(103, 3) {
    auto node3 = GET_SKILL_NODE(3, PhaseNode_Detect);
    if (node3 == nullptr) {
        node3 = new PhaseNode_Detect(3, phase);
        node3->setSelf(0U);
        node3->setEvent("");
        node3->setType(PhaseNode_Detect::Detect_Type::Assistant_Kill);
        CALL_REGISTER_SKILL_NODE(103, 3, node3)
    }
    if (noInit == true) {
        return node3;
    }
    return node3;
}
//--------------------------------------------------------------------------------
// AddSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(103, 5) {
}

REGISTER_CREATE_SKILL_NODE(103, 5) {
    auto node5 = GET_SKILL_NODE(5, PhaseNode_AddSkillBuff);
    if (node5 == nullptr) {
        node5 = new PhaseNode_AddSkillBuff(5, phase);
        node5->setConfigID(1031);
        node5->setConfigIDs({});
        node5->setTarget(0U);
        node5->setAttribute({{}});
        CALL_REGISTER_SKILL_NODE(103, 5, node5)
    }
    if (noInit == true) {
        return node5;
    }
    return node5;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(103, 7) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuff>(PhaseNode_Detect::TRIGGER_ON, 5, PhaseNode_AddSkillBuff::FUNC_ADD, &PhaseNode_AddSkillBuff::Add);
}

REGISTER_CREATE_SKILL_NODE(103, 7) {
    auto node7 = GET_SKILL_NODE(7, PhaseNode_Detect);
    if (node7 == nullptr) {
        node7 = new PhaseNode_Detect(7, phase);
        node7->setSelf(0U);
        node7->setEvent("");
        node7->setType(PhaseNode_Detect::Detect_Type::Kill_Target);
        CALL_REGISTER_SKILL_NODE(103, 7, node7)
    }
    if (noInit == true) {
        return node7;
    }
    return node7;
}

//--------------------------------------------------------------------------------
// SkillCreator_103
//
class SkillCreator_103 : public SkillCreator {
public:
    SkillCreator_103() {}
    virtual ~SkillCreator_103() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_103

//--------------------------------------------------------------------------------
// SkillPhase_103
//
class SkillPhase_103 : public SkillPhase {
public:
    SkillPhase_103(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_103() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(103, 3) // Detect
        CASE_CREATE_SKILL_NODE(103, 5) // AddSkillBuff
        CASE_CREATE_SKILL_NODE(103, 7) // Detect
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_103

SkillLogic* SkillCreator_103::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //创建阶段phase
    auto phase = new SkillPhase_103(1, logic, 1);
    //设置phase执行器
    phase->setDetectPhaseNode(1, 3);
    phase->setDetectPhaseNode(1, 7);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_103::getSkillExpend(int32_t& nType, int32_t& nValue) {
    nType = Skill::E_SkillExpend_PASSIVITY;
    return true;
}
} // namespace pvp
