#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

#include "skill_psnode_addskillbuff.h"
#include "skill_psnode_detect.h"
#include "skill_psnode_getactorattribute.h"
#include "skill_psnode_removeskillbuff.h"

namespace pvp {

//变量声明
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(112, 3) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_Detect::TRIGGER_ON, 25, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(112, 3) {
    auto node3 = GET_SKILL_NODE(3, PhaseNode_Detect);
    if (node3 == nullptr) {
        node3 = new PhaseNode_Detect(3, phase);
        node3->setSelf(0U);
        node3->setEvent("");
        node3->setType(PhaseNode_Detect::Detect_Type::Divorce_Fight);
        CALL_REGISTER_SKILL_NODE(112, 3, node3)
    }
    if (noInit == true) {
        return node3;
    }
    return node3;
}
//--------------------------------------------------------------------------------
// AddSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(112, 5) {
    pnode->resizeTrigger(PhaseNode_AddSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RemoveSkillBuff>(PhaseNode_AddSkillBuff::TRIGGER_DONE, 23, PhaseNode_RemoveSkillBuff::FUNC_REMOVE, &PhaseNode_RemoveSkillBuff::Remove);
}

REGISTER_CREATE_SKILL_NODE(112, 5) {
    auto node5 = GET_SKILL_NODE(5, PhaseNode_AddSkillBuff);
    if (node5 == nullptr) {
        node5 = new PhaseNode_AddSkillBuff(5, phase);
        node5->setConfigID(1121);
        node5->setConfigIDs({});
        node5->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(112, 5, node5)
    }
    if (noInit == true) {
        return node5;
    }
    auto node25 = GET_SKILL_NODE(25, PhaseNode_GetActorAttribute);
    if (node25 != nullptr) node5->setAttribute(node25->getAttribute());
    return node5;
}
//--------------------------------------------------------------------------------
// RemoveSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(112, 23) {
}

REGISTER_CREATE_SKILL_NODE(112, 23) {
    auto node23 = GET_SKILL_NODE(23, PhaseNode_RemoveSkillBuff);
    if (node23 == nullptr) {
        node23 = new PhaseNode_RemoveSkillBuff(23, phase);
        node23->setBuffID(0U);
        node23->setBuffIDs({});
        node23->setConfigID(1111);
        node23->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(112, 23, node23)
    }
    if (noInit == true) {
        return node23;
    }
    return node23;
}
//--------------------------------------------------------------------------------
// GetActorAttribute
//
REGISTER_REGISTER_SKILL_NODE(112, 25) {
    pnode->resizeTrigger(PhaseNode_GetActorAttribute::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuff>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 5, PhaseNode_AddSkillBuff::FUNC_ADD, &PhaseNode_AddSkillBuff::Add);
}

REGISTER_CREATE_SKILL_NODE(112, 25) {
    auto node25 = GET_SKILL_NODE(25, PhaseNode_GetActorAttribute);
    if (node25 == nullptr) {
        node25 = new PhaseNode_GetActorAttribute(25, phase);
        node25->setTarget(0U);
        node25->setType({});
        CALL_REGISTER_SKILL_NODE(112, 25, node25)
    }
    if (noInit == true) {
        return node25;
    }
    return node25;
}

//--------------------------------------------------------------------------------
// SkillCreator_112
//
class SkillCreator_112 : public SkillCreator {
public:
    SkillCreator_112() {}
    virtual ~SkillCreator_112() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_112

//--------------------------------------------------------------------------------
// SkillPhase_112
//
class SkillPhase_112 : public SkillPhase {
public:
    SkillPhase_112(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_112() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(112, 3) // Detect
        CASE_CREATE_SKILL_NODE(112, 5) // AddSkillBuff
        CASE_CREATE_SKILL_NODE(112, 23) // RemoveSkillBuff
        CASE_CREATE_SKILL_NODE(112, 25) // GetActorAttribute
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_112

SkillLogic* SkillCreator_112::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //创建阶段phase
    auto phase = new SkillPhase_112(1, logic, 1);
    //设置phase执行器
    phase->setDetectPhaseNode(1, 3);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_112::getSkillExpend(int32_t& nType, int32_t& nValue) {
    nType = Skill::E_SkillExpend_PASSIVITY;
    return true;
}
} // namespace pvp
