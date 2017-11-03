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
REGISTER_REGISTER_SKILL_NODE(122, 3) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_FindSkillBuff>(PhaseNode_Detect::TRIGGER_ON, 11, PhaseNode_FindSkillBuff::FUNC_DO, &PhaseNode_FindSkillBuff::Do);
}

REGISTER_CREATE_SKILL_NODE(122, 3) {
    auto node3 = GET_SKILL_NODE(3, PhaseNode_Detect);
    if (node3 == nullptr) {
        node3 = new PhaseNode_Detect(3, phase);
        node3->setSelf(0U);
        node3->setEvent("");
        node3->setType(PhaseNode_Detect::Detect_Type::Damage);
        CALL_REGISTER_SKILL_NODE(122, 3, node3)
    }
    if (noInit == true) {
        return node3;
    }
    return node3;
}
//--------------------------------------------------------------------------------
// AddSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(122, 8) {
}

REGISTER_CREATE_SKILL_NODE(122, 8) {
    auto node8 = GET_SKILL_NODE(8, PhaseNode_AddSkillBuff);
    if (node8 == nullptr) {
        node8 = new PhaseNode_AddSkillBuff(8, phase);
        node8->setConfigID(0);
        node8->setConfigIDs({1201,1221});
        node8->setTarget(0U);
        node8->setAttribute({{}});
        CALL_REGISTER_SKILL_NODE(122, 8, node8)
    }
    if (noInit == true) {
        return node8;
    }
    return node8;
}
//--------------------------------------------------------------------------------
// FindSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(122, 11) {
    pnode->resizeTrigger(PhaseNode_FindSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_FindSkillBuff::TRIGGER_DONE, 13, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(122, 11) {
    auto node11 = GET_SKILL_NODE(11, PhaseNode_FindSkillBuff);
    if (node11 == nullptr) {
        node11 = new PhaseNode_FindSkillBuff(11, phase);
        node11->setSelfTarget(0U);
        node11->setDetectTarget(0U);
        node11->setConfigID(1201);
        CALL_REGISTER_SKILL_NODE(122, 11, node11)
    }
    if (noInit == true) {
        return node11;
    }
    return node11;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(122, 13) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetBuffAttribute>(PhaseNode_If::TRIGGER_FALSE, 15, PhaseNode_GetBuffAttribute::FUNC_DO, &PhaseNode_GetBuffAttribute::Do);
}

REGISTER_CREATE_SKILL_NODE(122, 13) {
    auto node13 = GET_SKILL_NODE(13, PhaseNode_If);
    if (node13 == nullptr) {
        node13 = new PhaseNode_If(13, phase);
        CALL_REGISTER_SKILL_NODE(122, 13, node13)
    }
    if (noInit == true) {
        return node13;
    }
    auto node11 = GET_SKILL_NODE(11, PhaseNode_FindSkillBuff);
    if (node11 != nullptr) node13->setCondition(node11->getResult());
    return node13;
}
//--------------------------------------------------------------------------------
// GetBuffAttribute
//
REGISTER_REGISTER_SKILL_NODE(122, 15) {
    pnode->resizeTrigger(PhaseNode_GetBuffAttribute::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetBuffAttribute>(PhaseNode_GetBuffAttribute::TRIGGER_DONE, 16, PhaseNode_GetBuffAttribute::FUNC_DO, &PhaseNode_GetBuffAttribute::Do);
}

REGISTER_CREATE_SKILL_NODE(122, 15) {
    auto node15 = GET_SKILL_NODE(15, PhaseNode_GetBuffAttribute);
    if (node15 == nullptr) {
        node15 = new PhaseNode_GetBuffAttribute(15, phase);
        node15->setTarget(0U);
        node15->setAttribute(44);
        CALL_REGISTER_SKILL_NODE(122, 15, node15)
    }
    if (noInit == true) {
        return node15;
    }
    return node15;
}
//--------------------------------------------------------------------------------
// GetBuffAttribute
//
REGISTER_REGISTER_SKILL_NODE(122, 16) {
    pnode->resizeTrigger(PhaseNode_GetBuffAttribute::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_IntOperation>(PhaseNode_GetBuffAttribute::TRIGGER_DONE, 17, PhaseNode_IntOperation::FUNC_OPERATION, &PhaseNode_IntOperation::Operation);
}

REGISTER_CREATE_SKILL_NODE(122, 16) {
    auto node16 = GET_SKILL_NODE(16, PhaseNode_GetBuffAttribute);
    if (node16 == nullptr) {
        node16 = new PhaseNode_GetBuffAttribute(16, phase);
        node16->setTarget(0U);
        node16->setAttribute(2);
        CALL_REGISTER_SKILL_NODE(122, 16, node16)
    }
    if (noInit == true) {
        return node16;
    }
    return node16;
}
//--------------------------------------------------------------------------------
// IntOperation
//
REGISTER_REGISTER_SKILL_NODE(122, 17) {
    pnode->resizeTrigger(PhaseNode_IntOperation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_IntOperation>(PhaseNode_IntOperation::TRIGGER_DONE, 18, PhaseNode_IntOperation::FUNC_OPERATION, &PhaseNode_IntOperation::Operation);
}

REGISTER_CREATE_SKILL_NODE(122, 17) {
    auto node17 = GET_SKILL_NODE(17, PhaseNode_IntOperation);
    if (node17 == nullptr) {
        node17 = new PhaseNode_IntOperation(17, phase);
        node17->setValue(100);
        node17->setMethod(PhaseNode_IntOperation::IntOperation_Method::Multi);
        CALL_REGISTER_SKILL_NODE(122, 17, node17)
    }
    if (noInit == true) {
        return node17;
    }
    auto node15 = GET_SKILL_NODE(15, PhaseNode_GetBuffAttribute);
    if (node15 != nullptr) node17->setBase(node15->getValue());
    return node17;
}
//--------------------------------------------------------------------------------
// IntOperation
//
REGISTER_REGISTER_SKILL_NODE(122, 18) {
    pnode->resizeTrigger(PhaseNode_IntOperation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareInt>(PhaseNode_IntOperation::TRIGGER_DONE, 19, PhaseNode_CompareInt::FUNC_COMPARE, &PhaseNode_CompareInt::Compare);
}

REGISTER_CREATE_SKILL_NODE(122, 18) {
    auto node18 = GET_SKILL_NODE(18, PhaseNode_IntOperation);
    if (node18 == nullptr) {
        node18 = new PhaseNode_IntOperation(18, phase);
        node18->setMethod(PhaseNode_IntOperation::IntOperation_Method::Divis);
        CALL_REGISTER_SKILL_NODE(122, 18, node18)
    }
    if (noInit == true) {
        return node18;
    }
    auto node17 = GET_SKILL_NODE(17, PhaseNode_IntOperation);
    auto node16 = GET_SKILL_NODE(16, PhaseNode_GetBuffAttribute);
    if (node17 != nullptr) node18->setBase(node17->getFinal());
    if (node16 != nullptr) node18->setValue(node16->getValue());
    return node18;
}
//--------------------------------------------------------------------------------
// CompareInt
//
REGISTER_REGISTER_SKILL_NODE(122, 19) {
    pnode->resizeTrigger(PhaseNode_CompareInt::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuff>(PhaseNode_CompareInt::TRIGGER_LESS, 8, PhaseNode_AddSkillBuff::FUNC_ADD, &PhaseNode_AddSkillBuff::Add);
}

REGISTER_CREATE_SKILL_NODE(122, 19) {
    auto node19 = GET_SKILL_NODE(19, PhaseNode_CompareInt);
    if (node19 == nullptr) {
        node19 = new PhaseNode_CompareInt(19, phase);
        node19->setB(40);
        CALL_REGISTER_SKILL_NODE(122, 19, node19)
    }
    if (noInit == true) {
        return node19;
    }
    auto node18 = GET_SKILL_NODE(18, PhaseNode_IntOperation);
    if (node18 != nullptr) node19->setA(node18->getFinal());
    return node19;
}

//--------------------------------------------------------------------------------
// SkillCreator_122
//
class SkillCreator_122 : public SkillCreator {
public:
    SkillCreator_122() {}
    virtual ~SkillCreator_122() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_122

//--------------------------------------------------------------------------------
// SkillPhase_122
//
class SkillPhase_122 : public SkillPhase {
public:
    SkillPhase_122(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_122() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(122, 3) // Detect
        CASE_CREATE_SKILL_NODE(122, 8) // AddSkillBuff
        CASE_CREATE_SKILL_NODE(122, 11) // FindSkillBuff
        CASE_CREATE_SKILL_NODE(122, 13) // If
        CASE_CREATE_SKILL_NODE(122, 15) // GetBuffAttribute
        CASE_CREATE_SKILL_NODE(122, 16) // GetBuffAttribute
        CASE_CREATE_SKILL_NODE(122, 17) // IntOperation
        CASE_CREATE_SKILL_NODE(122, 18) // IntOperation
        CASE_CREATE_SKILL_NODE(122, 19) // CompareInt
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_122

SkillLogic* SkillCreator_122::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //创建阶段phase
    auto phase = new SkillPhase_122(1, logic, 1);
    //设置phase执行器
    phase->setDetectPhaseNode(1, 3);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_122::getSkillExpend(int32_t& nType, int32_t& nValue) {
    nType = Skill::E_SkillExpend_PASSIVITY;
    return true;
}
} // namespace pvp
