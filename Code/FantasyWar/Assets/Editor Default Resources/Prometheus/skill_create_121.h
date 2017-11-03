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
REGISTER_REGISTER_SKILL_NODE(121, 3) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_FindSkillBuff>(PhaseNode_Detect::TRIGGER_ON, 10, PhaseNode_FindSkillBuff::FUNC_DO, &PhaseNode_FindSkillBuff::Do);
}

REGISTER_CREATE_SKILL_NODE(121, 3) {
    auto node3 = GET_SKILL_NODE(3, PhaseNode_Detect);
    if (node3 == nullptr) {
        node3 = new PhaseNode_Detect(3, phase);
        node3->setSelf(0U);
        node3->setEvent("");
        node3->setType(PhaseNode_Detect::Detect_Type::Damage);
        CALL_REGISTER_SKILL_NODE(121, 3, node3)
    }
    if (noInit == true) {
        return node3;
    }
    return node3;
}
//--------------------------------------------------------------------------------
// AddSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(121, 8) {
}

REGISTER_CREATE_SKILL_NODE(121, 8) {
    auto node8 = GET_SKILL_NODE(8, PhaseNode_AddSkillBuff);
    if (node8 == nullptr) {
        node8 = new PhaseNode_AddSkillBuff(8, phase);
        node8->setConfigID(0);
        node8->setConfigIDs({1201,1211});
        node8->setTarget(0U);
        node8->setAttribute({{}});
        CALL_REGISTER_SKILL_NODE(121, 8, node8)
    }
    if (noInit == true) {
        return node8;
    }
    return node8;
}
//--------------------------------------------------------------------------------
// FindSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(121, 10) {
    pnode->resizeTrigger(PhaseNode_FindSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_FindSkillBuff::TRIGGER_DONE, 12, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(121, 10) {
    auto node10 = GET_SKILL_NODE(10, PhaseNode_FindSkillBuff);
    if (node10 == nullptr) {
        node10 = new PhaseNode_FindSkillBuff(10, phase);
        node10->setSelfTarget(0U);
        node10->setDetectTarget(0U);
        node10->setConfigID(1201);
        CALL_REGISTER_SKILL_NODE(121, 10, node10)
    }
    if (noInit == true) {
        return node10;
    }
    return node10;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(121, 12) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetBuffAttribute>(PhaseNode_If::TRIGGER_FALSE, 14, PhaseNode_GetBuffAttribute::FUNC_DO, &PhaseNode_GetBuffAttribute::Do);
}

REGISTER_CREATE_SKILL_NODE(121, 12) {
    auto node12 = GET_SKILL_NODE(12, PhaseNode_If);
    if (node12 == nullptr) {
        node12 = new PhaseNode_If(12, phase);
        CALL_REGISTER_SKILL_NODE(121, 12, node12)
    }
    if (noInit == true) {
        return node12;
    }
    auto node10 = GET_SKILL_NODE(10, PhaseNode_FindSkillBuff);
    if (node10 != nullptr) node12->setCondition(node10->getResult());
    return node12;
}
//--------------------------------------------------------------------------------
// GetBuffAttribute
//
REGISTER_REGISTER_SKILL_NODE(121, 14) {
    pnode->resizeTrigger(PhaseNode_GetBuffAttribute::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetBuffAttribute>(PhaseNode_GetBuffAttribute::TRIGGER_DONE, 15, PhaseNode_GetBuffAttribute::FUNC_DO, &PhaseNode_GetBuffAttribute::Do);
}

REGISTER_CREATE_SKILL_NODE(121, 14) {
    auto node14 = GET_SKILL_NODE(14, PhaseNode_GetBuffAttribute);
    if (node14 == nullptr) {
        node14 = new PhaseNode_GetBuffAttribute(14, phase);
        node14->setTarget(0U);
        node14->setAttribute(44);
        CALL_REGISTER_SKILL_NODE(121, 14, node14)
    }
    if (noInit == true) {
        return node14;
    }
    return node14;
}
//--------------------------------------------------------------------------------
// GetBuffAttribute
//
REGISTER_REGISTER_SKILL_NODE(121, 15) {
    pnode->resizeTrigger(PhaseNode_GetBuffAttribute::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_IntOperation>(PhaseNode_GetBuffAttribute::TRIGGER_DONE, 16, PhaseNode_IntOperation::FUNC_OPERATION, &PhaseNode_IntOperation::Operation);
}

REGISTER_CREATE_SKILL_NODE(121, 15) {
    auto node15 = GET_SKILL_NODE(15, PhaseNode_GetBuffAttribute);
    if (node15 == nullptr) {
        node15 = new PhaseNode_GetBuffAttribute(15, phase);
        node15->setTarget(0U);
        node15->setAttribute(2);
        CALL_REGISTER_SKILL_NODE(121, 15, node15)
    }
    if (noInit == true) {
        return node15;
    }
    return node15;
}
//--------------------------------------------------------------------------------
// IntOperation
//
REGISTER_REGISTER_SKILL_NODE(121, 16) {
    pnode->resizeTrigger(PhaseNode_IntOperation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_IntOperation>(PhaseNode_IntOperation::TRIGGER_DONE, 17, PhaseNode_IntOperation::FUNC_OPERATION, &PhaseNode_IntOperation::Operation);
}

REGISTER_CREATE_SKILL_NODE(121, 16) {
    auto node16 = GET_SKILL_NODE(16, PhaseNode_IntOperation);
    if (node16 == nullptr) {
        node16 = new PhaseNode_IntOperation(16, phase);
        node16->setValue(100);
        node16->setMethod(PhaseNode_IntOperation::IntOperation_Method::Multi);
        CALL_REGISTER_SKILL_NODE(121, 16, node16)
    }
    if (noInit == true) {
        return node16;
    }
    auto node14 = GET_SKILL_NODE(14, PhaseNode_GetBuffAttribute);
    if (node14 != nullptr) node16->setBase(node14->getValue());
    return node16;
}
//--------------------------------------------------------------------------------
// IntOperation
//
REGISTER_REGISTER_SKILL_NODE(121, 17) {
    pnode->resizeTrigger(PhaseNode_IntOperation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareInt>(PhaseNode_IntOperation::TRIGGER_DONE, 18, PhaseNode_CompareInt::FUNC_COMPARE, &PhaseNode_CompareInt::Compare);
}

REGISTER_CREATE_SKILL_NODE(121, 17) {
    auto node17 = GET_SKILL_NODE(17, PhaseNode_IntOperation);
    if (node17 == nullptr) {
        node17 = new PhaseNode_IntOperation(17, phase);
        node17->setMethod(PhaseNode_IntOperation::IntOperation_Method::Divis);
        CALL_REGISTER_SKILL_NODE(121, 17, node17)
    }
    if (noInit == true) {
        return node17;
    }
    auto node16 = GET_SKILL_NODE(16, PhaseNode_IntOperation);
    auto node15 = GET_SKILL_NODE(15, PhaseNode_GetBuffAttribute);
    if (node16 != nullptr) node17->setBase(node16->getFinal());
    if (node15 != nullptr) node17->setValue(node15->getValue());
    return node17;
}
//--------------------------------------------------------------------------------
// CompareInt
//
REGISTER_REGISTER_SKILL_NODE(121, 18) {
    pnode->resizeTrigger(PhaseNode_CompareInt::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuff>(PhaseNode_CompareInt::TRIGGER_LESS, 8, PhaseNode_AddSkillBuff::FUNC_ADD, &PhaseNode_AddSkillBuff::Add);
}

REGISTER_CREATE_SKILL_NODE(121, 18) {
    auto node18 = GET_SKILL_NODE(18, PhaseNode_CompareInt);
    if (node18 == nullptr) {
        node18 = new PhaseNode_CompareInt(18, phase);
        node18->setB(40);
        CALL_REGISTER_SKILL_NODE(121, 18, node18)
    }
    if (noInit == true) {
        return node18;
    }
    auto node17 = GET_SKILL_NODE(17, PhaseNode_IntOperation);
    if (node17 != nullptr) node18->setA(node17->getFinal());
    return node18;
}

//--------------------------------------------------------------------------------
// SkillCreator_121
//
class SkillCreator_121 : public SkillCreator {
public:
    SkillCreator_121() {}
    virtual ~SkillCreator_121() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_121

//--------------------------------------------------------------------------------
// SkillPhase_121
//
class SkillPhase_121 : public SkillPhase {
public:
    SkillPhase_121(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_121() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(121, 3) // Detect
        CASE_CREATE_SKILL_NODE(121, 8) // AddSkillBuff
        CASE_CREATE_SKILL_NODE(121, 10) // FindSkillBuff
        CASE_CREATE_SKILL_NODE(121, 12) // If
        CASE_CREATE_SKILL_NODE(121, 14) // GetBuffAttribute
        CASE_CREATE_SKILL_NODE(121, 15) // GetBuffAttribute
        CASE_CREATE_SKILL_NODE(121, 16) // IntOperation
        CASE_CREATE_SKILL_NODE(121, 17) // IntOperation
        CASE_CREATE_SKILL_NODE(121, 18) // CompareInt
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_121

SkillLogic* SkillCreator_121::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //创建阶段phase
    auto phase = new SkillPhase_121(1, logic, 1);
    //设置phase执行器
    phase->setDetectPhaseNode(1, 3);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_121::getSkillExpend(int32_t& nType, int32_t& nValue) {
    nType = Skill::E_SkillExpend_PASSIVITY;
    return true;
}
} // namespace pvp
