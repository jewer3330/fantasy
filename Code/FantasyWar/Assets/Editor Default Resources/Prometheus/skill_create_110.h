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
REGISTER_REGISTER_SKILL_NODE(110, 3) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_Detect::TRIGGER_ON, 9, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(110, 3) {
    auto node3 = GET_SKILL_NODE(3, PhaseNode_Detect);
    if (node3 == nullptr) {
        node3 = new PhaseNode_Detect(3, phase);
        node3->setSelf(0U);
        node3->setEvent("");
        node3->setType(PhaseNode_Detect::Detect_Type::Divorce_Fight);
        CALL_REGISTER_SKILL_NODE(110, 3, node3)
    }
    if (noInit == true) {
        return node3;
    }
    return node3;
}
//--------------------------------------------------------------------------------
// AddSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(110, 5) {
}

REGISTER_CREATE_SKILL_NODE(110, 5) {
    auto node5 = GET_SKILL_NODE(5, PhaseNode_AddSkillBuff);
    if (node5 == nullptr) {
        node5 = new PhaseNode_AddSkillBuff(5, phase);
        node5->setConfigID(1101);
        node5->setConfigIDs({});
        node5->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(110, 5, node5)
    }
    if (noInit == true) {
        return node5;
    }
    auto node9 = GET_SKILL_NODE(9, PhaseNode_GetActorAttribute);
    if (node9 != nullptr) node5->setAttribute(node9->getAttribute());
    return node5;
}
//--------------------------------------------------------------------------------
// GetActorAttribute
//
REGISTER_REGISTER_SKILL_NODE(110, 9) {
    pnode->resizeTrigger(PhaseNode_GetActorAttribute::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuff>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 5, PhaseNode_AddSkillBuff::FUNC_ADD, &PhaseNode_AddSkillBuff::Add);
}

REGISTER_CREATE_SKILL_NODE(110, 9) {
    auto node9 = GET_SKILL_NODE(9, PhaseNode_GetActorAttribute);
    if (node9 == nullptr) {
        node9 = new PhaseNode_GetActorAttribute(9, phase);
        node9->setTarget(0U);
        node9->setType({});
        CALL_REGISTER_SKILL_NODE(110, 9, node9)
    }
    if (noInit == true) {
        return node9;
    }
    return node9;
}

//--------------------------------------------------------------------------------
// SkillCreator_110
//
class SkillCreator_110 : public SkillCreator {
public:
    SkillCreator_110() {}
    virtual ~SkillCreator_110() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_110

//--------------------------------------------------------------------------------
// SkillPhase_110
//
class SkillPhase_110 : public SkillPhase {
public:
    SkillPhase_110(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_110() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(110, 3) // Detect
        CASE_CREATE_SKILL_NODE(110, 5) // AddSkillBuff
        CASE_CREATE_SKILL_NODE(110, 9) // GetActorAttribute
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_110

SkillLogic* SkillCreator_110::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //创建阶段phase
    auto phase = new SkillPhase_110(1, logic, 1);
    //设置phase执行器
    phase->setDetectPhaseNode(1, 3);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_110::getSkillExpend(int32_t& nType, int32_t& nValue) {
    nType = Skill::E_SkillExpend_PASSIVITY;
    return true;
}
} // namespace pvp
