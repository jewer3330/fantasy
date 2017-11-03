#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

#include "skill_psnode_addskillbuff.h"
#include "skill_psnode_compareint.h"
#include "skill_psnode_detect.h"
#include "skill_psnode_findskillbuff.h"
#include "skill_psnode_getbuffattribute.h"
#include "skill_psnode_if.h"
#include "skill_psnode_intoperation.h"

namespace pvp {

//变量声明
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(123, 3) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_FindSkillBuff>(PhaseNode_Detect::TRIGGER_ON, 8, PhaseNode_FindSkillBuff::FUNC_DO, &PhaseNode_FindSkillBuff::Do);
}

REGISTER_CREATE_SKILL_NODE(123, 3) {
    auto node3 = GET_SKILL_NODE(3, PhaseNode_Detect);
    if (node3 == nullptr) {
        node3 = new PhaseNode_Detect(3, phase);
        node3->setSelf(0U);
        node3->setEvent("");
        node3->setType(PhaseNode_Detect::Detect_Type::Damage);
        CALL_REGISTER_SKILL_NODE(123, 3, node3)
    }
    if (noInit == true) {
        return node3;
    }
    return node3;
}
//--------------------------------------------------------------------------------
// AddSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(123, 6) {
}

REGISTER_CREATE_SKILL_NODE(123, 6) {
    auto node6 = GET_SKILL_NODE(6, PhaseNode_AddSkillBuff);
    if (node6 == nullptr) {
        node6 = new PhaseNode_AddSkillBuff(6, phase);
        node6->setConfigID(0);
        node6->setConfigIDs({1201,1231});
        node6->setTarget(0U);
        node6->setAttribute({{}});
        CALL_REGISTER_SKILL_NODE(123, 6, node6)
    }
    if (noInit == true) {
        return node6;
    }
    return node6;
}
//--------------------------------------------------------------------------------
// FindSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(123, 8) {
    pnode->resizeTrigger(PhaseNode_FindSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_FindSkillBuff::TRIGGER_DONE, 10, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(123, 8) {
    auto node8 = GET_SKILL_NODE(8, PhaseNode_FindSkillBuff);
    if (node8 == nullptr) {
        node8 = new PhaseNode_FindSkillBuff(8, phase);
        node8->setSelfTarget(0U);
        node8->setDetectTarget(0U);
        node8->setConfigID(1201);
        CALL_REGISTER_SKILL_NODE(123, 8, node8)
    }
    if (noInit == true) {
        return node8;
    }
    return node8;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(123, 10) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetBuffAttribute>(PhaseNode_If::TRIGGER_FALSE, 11, PhaseNode_GetBuffAttribute::FUNC_DO, &PhaseNode_GetBuffAttribute::Do);
}

REGISTER_CREATE_SKILL_NODE(123, 10) {
    auto node10 = GET_SKILL_NODE(10, PhaseNode_If);
    if (node10 == nullptr) {
        node10 = new PhaseNode_If(10, phase);
        CALL_REGISTER_SKILL_NODE(123, 10, node10)
    }
    if (noInit == true) {
        return node10;
    }
    auto node8 = GET_SKILL_NODE(8, PhaseNode_FindSkillBuff);
    if (node8 != nullptr) node10->setCondition(node8->getResult());
    return node10;
}
//--------------------------------------------------------------------------------
// GetBuffAttribute
//
REGISTER_REGISTER_SKILL_NODE(123, 11) {
    pnode->resizeTrigger(PhaseNode_GetBuffAttribute::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetBuffAttribute>(PhaseNode_GetBuffAttribute::TRIGGER_DONE, 12, PhaseNode_GetBuffAttribute::FUNC_DO, &PhaseNode_GetBuffAttribute::Do);
}

REGISTER_CREATE_SKILL_NODE(123, 11) {
    auto node11 = GET_SKILL_NODE(11, PhaseNode_GetBuffAttribute);
    if (node11 == nullptr) {
        node11 = new PhaseNode_GetBuffAttribute(11, phase);
        node11->setTarget(0U);
        node11->setAttribute(44);
        CALL_REGISTER_SKILL_NODE(123, 11, node11)
    }
    if (noInit == true) {
        return node11;
    }
    return node11;
}
//--------------------------------------------------------------------------------
// GetBuffAttribute
//
REGISTER_REGISTER_SKILL_NODE(123, 12) {
    pnode->resizeTrigger(PhaseNode_GetBuffAttribute::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_IntOperation>(PhaseNode_GetBuffAttribute::TRIGGER_DONE, 13, PhaseNode_IntOperation::FUNC_OPERATION, &PhaseNode_IntOperation::Operation);
}

REGISTER_CREATE_SKILL_NODE(123, 12) {
    auto node12 = GET_SKILL_NODE(12, PhaseNode_GetBuffAttribute);
    if (node12 == nullptr) {
        node12 = new PhaseNode_GetBuffAttribute(12, phase);
        node12->setTarget(0U);
        node12->setAttribute(2);
        CALL_REGISTER_SKILL_NODE(123, 12, node12)
    }
    if (noInit == true) {
        return node12;
    }
    return node12;
}
//--------------------------------------------------------------------------------
// IntOperation
//
REGISTER_REGISTER_SKILL_NODE(123, 13) {
    pnode->resizeTrigger(PhaseNode_IntOperation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_IntOperation>(PhaseNode_IntOperation::TRIGGER_DONE, 14, PhaseNode_IntOperation::FUNC_OPERATION, &PhaseNode_IntOperation::Operation);
}

REGISTER_CREATE_SKILL_NODE(123, 13) {
    auto node13 = GET_SKILL_NODE(13, PhaseNode_IntOperation);
    if (node13 == nullptr) {
        node13 = new PhaseNode_IntOperation(13, phase);
        node13->setValue(100);
        node13->setMethod(PhaseNode_IntOperation::IntOperation_Method::Multi);
        CALL_REGISTER_SKILL_NODE(123, 13, node13)
    }
    if (noInit == true) {
        return node13;
    }
    auto node11 = GET_SKILL_NODE(11, PhaseNode_GetBuffAttribute);
    if (node11 != nullptr) node13->setBase(node11->getValue());
    return node13;
}
//--------------------------------------------------------------------------------
// IntOperation
//
REGISTER_REGISTER_SKILL_NODE(123, 14) {
    pnode->resizeTrigger(PhaseNode_IntOperation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareInt>(PhaseNode_IntOperation::TRIGGER_DONE, 15, PhaseNode_CompareInt::FUNC_COMPARE, &PhaseNode_CompareInt::Compare);
}

REGISTER_CREATE_SKILL_NODE(123, 14) {
    auto node14 = GET_SKILL_NODE(14, PhaseNode_IntOperation);
    if (node14 == nullptr) {
        node14 = new PhaseNode_IntOperation(14, phase);
        node14->setMethod(PhaseNode_IntOperation::IntOperation_Method::Divis);
        CALL_REGISTER_SKILL_NODE(123, 14, node14)
    }
    if (noInit == true) {
        return node14;
    }
    auto node13 = GET_SKILL_NODE(13, PhaseNode_IntOperation);
    auto node12 = GET_SKILL_NODE(12, PhaseNode_GetBuffAttribute);
    if (node13 != nullptr) node14->setBase(node13->getFinal());
    if (node12 != nullptr) node14->setValue(node12->getValue());
    return node14;
}
//--------------------------------------------------------------------------------
// CompareInt
//
REGISTER_REGISTER_SKILL_NODE(123, 15) {
    pnode->resizeTrigger(PhaseNode_CompareInt::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuff>(PhaseNode_CompareInt::TRIGGER_LESS, 6, PhaseNode_AddSkillBuff::FUNC_ADD, &PhaseNode_AddSkillBuff::Add);
}

REGISTER_CREATE_SKILL_NODE(123, 15) {
    auto node15 = GET_SKILL_NODE(15, PhaseNode_CompareInt);
    if (node15 == nullptr) {
        node15 = new PhaseNode_CompareInt(15, phase);
        node15->setB(40);
        CALL_REGISTER_SKILL_NODE(123, 15, node15)
    }
    if (noInit == true) {
        return node15;
    }
    auto node14 = GET_SKILL_NODE(14, PhaseNode_IntOperation);
    if (node14 != nullptr) node15->setA(node14->getFinal());
    return node15;
}

//--------------------------------------------------------------------------------
// SkillCreator_123
//
class SkillCreator_123 : public SkillCreator {
public:
    SkillCreator_123() {}
    virtual ~SkillCreator_123() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_123

//--------------------------------------------------------------------------------
// SkillPhase_123
//
class SkillPhase_123 : public SkillPhase {
public:
    SkillPhase_123(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_123() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(123, 3) // Detect
        CASE_CREATE_SKILL_NODE(123, 6) // AddSkillBuff
        CASE_CREATE_SKILL_NODE(123, 8) // FindSkillBuff
        CASE_CREATE_SKILL_NODE(123, 10) // If
        CASE_CREATE_SKILL_NODE(123, 11) // GetBuffAttribute
        CASE_CREATE_SKILL_NODE(123, 12) // GetBuffAttribute
        CASE_CREATE_SKILL_NODE(123, 13) // IntOperation
        CASE_CREATE_SKILL_NODE(123, 14) // IntOperation
        CASE_CREATE_SKILL_NODE(123, 15) // CompareInt
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_123

SkillLogic* SkillCreator_123::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //创建阶段phase
    auto phase = new SkillPhase_123(1, logic, 1);
    //设置phase执行器
    phase->setDetectPhaseNode(1, 3);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_123::getSkillExpend(int32_t& nType, int32_t& nValue) {
    nType = Skill::E_SkillExpend_PASSIVITY;
    return true;
}
} // namespace pvp
