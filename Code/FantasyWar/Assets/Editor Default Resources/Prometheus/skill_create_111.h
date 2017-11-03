#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

#include "skill_psnode_addskillbuff.h"
#include "skill_psnode_detect.h"
#include "skill_psnode_getactorattribute.h"

namespace pvp {

//变量声明
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(111, 3) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_Detect::TRIGGER_ON, 12, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(111, 3) {
    auto node3 = GET_SKILL_NODE(3, PhaseNode_Detect);
    if (node3 == nullptr) {
        node3 = new PhaseNode_Detect(3, phase);
        node3->setSelf(0U);
        node3->setEvent("");
        node3->setType(PhaseNode_Detect::Detect_Type::Divorce_Fight);
        CALL_REGISTER_SKILL_NODE(111, 3, node3)
    }
    if (noInit == true) {
        return node3;
    }
    return node3;
}
//--------------------------------------------------------------------------------
// AddSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(111, 8) {
}

REGISTER_CREATE_SKILL_NODE(111, 8) {
    auto node8 = GET_SKILL_NODE(8, PhaseNode_AddSkillBuff);
    if (node8 == nullptr) {
        node8 = new PhaseNode_AddSkillBuff(8, phase);
        node8->setConfigID(1111);
        node8->setConfigIDs({});
        node8->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(111, 8, node8)
    }
    if (noInit == true) {
        return node8;
    }
    auto node12 = GET_SKILL_NODE(12, PhaseNode_GetActorAttribute);
    if (node12 != nullptr) node8->setAttribute(node12->getAttribute());
    return node8;
}
//--------------------------------------------------------------------------------
// GetActorAttribute
//
REGISTER_REGISTER_SKILL_NODE(111, 12) {
    pnode->resizeTrigger(PhaseNode_GetActorAttribute::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuff>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 8, PhaseNode_AddSkillBuff::FUNC_ADD, &PhaseNode_AddSkillBuff::Add);
}

REGISTER_CREATE_SKILL_NODE(111, 12) {
    auto node12 = GET_SKILL_NODE(12, PhaseNode_GetActorAttribute);
    if (node12 == nullptr) {
        node12 = new PhaseNode_GetActorAttribute(12, phase);
        node12->setTarget(0U);
        node12->setType({});
        CALL_REGISTER_SKILL_NODE(111, 12, node12)
    }
    if (noInit == true) {
        return node12;
    }
    return node12;
}

//--------------------------------------------------------------------------------
// SkillCreator_111
//
class SkillCreator_111 : public SkillCreator {
public:
    SkillCreator_111() {}
    virtual ~SkillCreator_111() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_111

//--------------------------------------------------------------------------------
// SkillPhase_111
//
class SkillPhase_111 : public SkillPhase {
public:
    SkillPhase_111(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_111() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(111, 3) // Detect
        CASE_CREATE_SKILL_NODE(111, 8) // AddSkillBuff
        CASE_CREATE_SKILL_NODE(111, 12) // GetActorAttribute
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_111

SkillLogic* SkillCreator_111::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //创建阶段phase
    auto phase = new SkillPhase_111(1, logic, 1);
    //设置phase执行器
    phase->setDetectPhaseNode(1, 3);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_111::getSkillExpend(int32_t& nType, int32_t& nValue) {
    nType = Skill::E_SkillExpend_PASSIVITY;
    return true;
}
} // namespace pvp
