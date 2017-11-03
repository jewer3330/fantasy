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
REGISTER_REGISTER_SKILL_NODE(10354, 3) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuff>(PhaseNode_Detect::TRIGGER_ON, 29, PhaseNode_AddSkillBuff::FUNC_ADD, &PhaseNode_AddSkillBuff::Add);
}

REGISTER_CREATE_SKILL_NODE(10354, 3) {
    auto node3 = GET_SKILL_NODE(3, PhaseNode_Detect);
    if (node3 == nullptr) {
        node3 = new PhaseNode_Detect(3, phase);
        node3->setSelf(0U);
        node3->setEvent("");
        node3->setType(PhaseNode_Detect::Detect_Type::Marking);
        node3->setMarkID(4);
        CALL_REGISTER_SKILL_NODE(10354, 3, node3)
    }
    if (noInit == true) {
        return node3;
    }
    return node3;
}
//--------------------------------------------------------------------------------
// AddSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10354, 29) {
}

REGISTER_CREATE_SKILL_NODE(10354, 29) {
    auto node29 = GET_SKILL_NODE(29, PhaseNode_AddSkillBuff);
    if (node29 == nullptr) {
        node29 = new PhaseNode_AddSkillBuff(29, phase);
        node29->setConfigID(103502);
        node29->setConfigIDs({});
        node29->setAttribute({{}});
        CALL_REGISTER_SKILL_NODE(10354, 29, node29)
    }
    if (noInit == true) {
        return node29;
    }
    auto node3 = GET_SKILL_NODE(3, PhaseNode_Detect);
    if (node3 != nullptr) node29->setTarget(node3->getVars().getVariable<uint64_t>(0));
    return node29;
}

//--------------------------------------------------------------------------------
// SkillCreator_10354
//
class SkillCreator_10354 : public SkillCreator {
public:
    SkillCreator_10354() {}
    virtual ~SkillCreator_10354() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_10354

//--------------------------------------------------------------------------------
// SkillPhase_10354
//
class SkillPhase_10354 : public SkillPhase {
public:
    SkillPhase_10354(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_10354() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(10354, 3) // Detect
        CASE_CREATE_SKILL_NODE(10354, 29) // AddSkillBuff
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_10354

SkillLogic* SkillCreator_10354::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //创建阶段phase
    auto phase = new SkillPhase_10354(1, logic, 1);
    //设置phase执行器
    phase->setDetectPhaseNode(1, 3);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_10354::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
