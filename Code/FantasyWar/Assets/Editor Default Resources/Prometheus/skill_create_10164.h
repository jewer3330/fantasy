#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

#include "skill_psnode_addskillbuff.h"
#include "skill_psnode_detect.h"

namespace pvp {

//变量声明
//--------------------------------------------------------------------------------
// AddSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10164, 18) {
}

REGISTER_CREATE_SKILL_NODE(10164, 18) {
    auto node18 = GET_SKILL_NODE(18, PhaseNode_AddSkillBuff);
    if (node18 == nullptr) {
        node18 = new PhaseNode_AddSkillBuff(18, phase);
        node18->setConfigID(101641);
        node18->setConfigIDs({});
        node18->setTarget(0U);
        node18->setAttribute({{}});
        CALL_REGISTER_SKILL_NODE(10164, 18, node18)
    }
    if (noInit == true) {
        return node18;
    }
    return node18;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10164, 21) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuff>(PhaseNode_Detect::TRIGGER_ON, 18, PhaseNode_AddSkillBuff::FUNC_ADD, &PhaseNode_AddSkillBuff::Add);
}

REGISTER_CREATE_SKILL_NODE(10164, 21) {
    auto node21 = GET_SKILL_NODE(21, PhaseNode_Detect);
    if (node21 == nullptr) {
        node21 = new PhaseNode_Detect(21, phase);
        node21->setSelf(0U);
        node21->setEvent("");
        node21->setType(PhaseNode_Detect::Detect_Type::Actor_Spawn);
        node21->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10164, 21, node21)
    }
    if (noInit == true) {
        return node21;
    }
    return node21;
}

//--------------------------------------------------------------------------------
// SkillCreator_10164
//
class SkillCreator_10164 : public SkillCreator {
public:
    SkillCreator_10164() {}
    virtual ~SkillCreator_10164() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_10164

//--------------------------------------------------------------------------------
// SkillPhase_10164
//
class SkillPhase_10164 : public SkillPhase {
public:
    SkillPhase_10164(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_10164() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(10164, 18) // AddSkillBuff
        CASE_CREATE_SKILL_NODE(10164, 21) // Detect
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_10164

SkillLogic* SkillCreator_10164::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //创建阶段phase
    auto phase = new SkillPhase_10164(1, logic, 1);
    //设置phase执行器
    phase->setDetectPhaseNode(1, 21);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_10164::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
