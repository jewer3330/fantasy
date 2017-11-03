#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

#include "skill_psnode_addskillbuff.h"
#include "skill_psnode_compareint.h"
#include "skill_psnode_detect.h"
#include "skill_psnode_intoperation.h"
#include "skill_psnode_playsound.h"
#include "skill_psnode_setint.h"

namespace pvp {

//变量声明
uint64_t Variable_10044_a100441 = 0;
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10044, 58) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_IntOperation>(PhaseNode_Detect::TRIGGER_ON, 80, PhaseNode_IntOperation::FUNC_OPERATION, &PhaseNode_IntOperation::Operation);
}

REGISTER_CREATE_SKILL_NODE(10044, 58) {
    auto node58 = GET_SKILL_NODE(58, PhaseNode_Detect);
    if (node58 == nullptr) {
        node58 = new PhaseNode_Detect(58, phase);
        node58->setSelf(0U);
        node58->setEvent("");
        node58->setType(PhaseNode_Detect::Detect_Type::EnegyShiled_Decrease);
        node58->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10044, 58, node58)
    }
    if (noInit == true) {
        return node58;
    }
    return node58;
}
//--------------------------------------------------------------------------------
// IntOperation
//
REGISTER_REGISTER_SKILL_NODE(10044, 80) {
    pnode->resizeTrigger(PhaseNode_IntOperation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_IntOperation>(PhaseNode_IntOperation::TRIGGER_DONE, 96, PhaseNode_IntOperation::FUNC_OPERATION, &PhaseNode_IntOperation::Operation);
}

REGISTER_CREATE_SKILL_NODE(10044, 80) {
    auto node80 = GET_SKILL_NODE(80, PhaseNode_IntOperation);
    if (node80 == nullptr) {
        node80 = new PhaseNode_IntOperation(80, phase);
        node80->setMethod(PhaseNode_IntOperation::IntOperation_Method::Add);
        CALL_REGISTER_SKILL_NODE(10044, 80, node80)
    }
    if (noInit == true) {
        return node80;
    }
    auto variables = node80->getVariables();
    if (variables != nullptr) {
        node80->setBase(variables->getVariable<int32_t>(Variable_10044_a100441));
    }
    auto node58 = GET_SKILL_NODE(58, PhaseNode_Detect);
    if (node58 != nullptr) node80->setValue(node58->getVars().getVariable<int32_t>(0));
    return node80;
}
//--------------------------------------------------------------------------------
// AddSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10044, 89) {
    pnode->resizeTrigger(PhaseNode_AddSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_AddSkillBuff::TRIGGER_DONE, 112, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10044, 89) {
    auto node89 = GET_SKILL_NODE(89, PhaseNode_AddSkillBuff);
    if (node89 == nullptr) {
        node89 = new PhaseNode_AddSkillBuff(89, phase);
        node89->setConfigID(100441);
        node89->setConfigIDs({});
        node89->setTarget(0U);
        node89->setAttribute({{}});
        CALL_REGISTER_SKILL_NODE(10044, 89, node89)
    }
    if (noInit == true) {
        return node89;
    }
    return node89;
}
//--------------------------------------------------------------------------------
// SetInt
//
REGISTER_REGISTER_SKILL_NODE(10044, 91) {
    pnode->resizeTrigger(PhaseNode_SetInt::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareInt>(PhaseNode_SetInt::TRIGGER_DONE, 98, PhaseNode_CompareInt::FUNC_COMPARE, &PhaseNode_CompareInt::Compare);
}

REGISTER_CREATE_SKILL_NODE(10044, 91) {
    auto node91 = GET_SKILL_NODE(91, PhaseNode_SetInt);
    if (node91 == nullptr) {
        node91 = new PhaseNode_SetInt(91, phase);
        node91->setName("a100441");
        CALL_REGISTER_SKILL_NODE(10044, 91, node91)
    }
    if (noInit == true) {
        return node91;
    }
    auto node80 = GET_SKILL_NODE(80, PhaseNode_IntOperation);
    if (node80 != nullptr) node91->setValue(node80->getFinal());
    return node91;
}
//--------------------------------------------------------------------------------
// IntOperation
//
REGISTER_REGISTER_SKILL_NODE(10044, 96) {
    pnode->resizeTrigger(PhaseNode_IntOperation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetInt>(PhaseNode_IntOperation::TRIGGER_DONE, 91, PhaseNode_SetInt::FUNC_SET, &PhaseNode_SetInt::Set);
}

REGISTER_CREATE_SKILL_NODE(10044, 96) {
    auto node96 = GET_SKILL_NODE(96, PhaseNode_IntOperation);
    if (node96 == nullptr) {
        node96 = new PhaseNode_IntOperation(96, phase);
        node96->setValue(5000);
        node96->setMethod(PhaseNode_IntOperation::IntOperation_Method::Divis);
        CALL_REGISTER_SKILL_NODE(10044, 96, node96)
    }
    if (noInit == true) {
        return node96;
    }
    auto node80 = GET_SKILL_NODE(80, PhaseNode_IntOperation);
    if (node80 != nullptr) node96->setBase(node80->getFinal());
    return node96;
}
//--------------------------------------------------------------------------------
// CompareInt
//
REGISTER_REGISTER_SKILL_NODE(10044, 98) {
    pnode->resizeTrigger(PhaseNode_CompareInt::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_IntOperation>(PhaseNode_CompareInt::TRIGGER_EQUAL, 105, PhaseNode_IntOperation::FUNC_OPERATION, &PhaseNode_IntOperation::Operation);
    pnode->regTrigger<PhaseNode_IntOperation>(PhaseNode_CompareInt::TRIGGER_GREATER, 105, PhaseNode_IntOperation::FUNC_OPERATION, &PhaseNode_IntOperation::Operation);
}

REGISTER_CREATE_SKILL_NODE(10044, 98) {
    auto node98 = GET_SKILL_NODE(98, PhaseNode_CompareInt);
    if (node98 == nullptr) {
        node98 = new PhaseNode_CompareInt(98, phase);
        node98->setB(1);
        CALL_REGISTER_SKILL_NODE(10044, 98, node98)
    }
    if (noInit == true) {
        return node98;
    }
    auto node96 = GET_SKILL_NODE(96, PhaseNode_IntOperation);
    if (node96 != nullptr) node98->setA(node96->getFinal());
    return node98;
}
//--------------------------------------------------------------------------------
// IntOperation
//
REGISTER_REGISTER_SKILL_NODE(10044, 105) {
    pnode->resizeTrigger(PhaseNode_IntOperation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_IntOperation>(PhaseNode_IntOperation::TRIGGER_DONE, 107, PhaseNode_IntOperation::FUNC_OPERATION, &PhaseNode_IntOperation::Operation);
}

REGISTER_CREATE_SKILL_NODE(10044, 105) {
    auto node105 = GET_SKILL_NODE(105, PhaseNode_IntOperation);
    if (node105 == nullptr) {
        node105 = new PhaseNode_IntOperation(105, phase);
        node105->setValue(5000);
        node105->setMethod(PhaseNode_IntOperation::IntOperation_Method::Multi);
        CALL_REGISTER_SKILL_NODE(10044, 105, node105)
    }
    if (noInit == true) {
        return node105;
    }
    auto node96 = GET_SKILL_NODE(96, PhaseNode_IntOperation);
    if (node96 != nullptr) node105->setBase(node96->getFinal());
    return node105;
}
//--------------------------------------------------------------------------------
// IntOperation
//
REGISTER_REGISTER_SKILL_NODE(10044, 107) {
    pnode->resizeTrigger(PhaseNode_IntOperation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetInt>(PhaseNode_IntOperation::TRIGGER_DONE, 109, PhaseNode_SetInt::FUNC_SET, &PhaseNode_SetInt::Set);
}

REGISTER_CREATE_SKILL_NODE(10044, 107) {
    auto node107 = GET_SKILL_NODE(107, PhaseNode_IntOperation);
    if (node107 == nullptr) {
        node107 = new PhaseNode_IntOperation(107, phase);
        node107->setMethod(PhaseNode_IntOperation::IntOperation_Method::Sub);
        CALL_REGISTER_SKILL_NODE(10044, 107, node107)
    }
    if (noInit == true) {
        return node107;
    }
    auto node80 = GET_SKILL_NODE(80, PhaseNode_IntOperation);
    auto node105 = GET_SKILL_NODE(105, PhaseNode_IntOperation);
    if (node80 != nullptr) node107->setBase(node80->getFinal());
    if (node105 != nullptr) node107->setValue(node105->getFinal());
    return node107;
}
//--------------------------------------------------------------------------------
// SetInt
//
REGISTER_REGISTER_SKILL_NODE(10044, 109) {
    pnode->resizeTrigger(PhaseNode_SetInt::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuff>(PhaseNode_SetInt::TRIGGER_DONE, 89, PhaseNode_AddSkillBuff::FUNC_ADD, &PhaseNode_AddSkillBuff::Add);
}

REGISTER_CREATE_SKILL_NODE(10044, 109) {
    auto node109 = GET_SKILL_NODE(109, PhaseNode_SetInt);
    if (node109 == nullptr) {
        node109 = new PhaseNode_SetInt(109, phase);
        node109->setName("a100441");
        CALL_REGISTER_SKILL_NODE(10044, 109, node109)
    }
    if (noInit == true) {
        return node109;
    }
    auto node107 = GET_SKILL_NODE(107, PhaseNode_IntOperation);
    if (node107 != nullptr) node109->setValue(node107->getFinal());
    return node109;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10044, 112) {
}

REGISTER_CREATE_SKILL_NODE(10044, 112) {
    auto node112 = GET_SKILL_NODE(112, PhaseNode_PlaySound);
    if (node112 == nullptr) {
        node112 = new PhaseNode_PlaySound(112, phase);
        node112->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node112->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node112->setSoundID("SE_Hero101_Skill_D");
        node112->setTarget(0U);
        node112->setUsePos(false);
        node112->setPosX(.00f);
        node112->setPosY(.00f);
        node112->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10044, 112, node112)
    }
    if (noInit == true) {
        return node112;
    }
    return node112;
}

//--------------------------------------------------------------------------------
// SkillCreator_10044
//
class SkillCreator_10044 : public SkillCreator {
public:
    SkillCreator_10044() {}
    virtual ~SkillCreator_10044() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_10044

//--------------------------------------------------------------------------------
// SkillPhase_10044
//
class SkillPhase_10044 : public SkillPhase {
public:
    SkillPhase_10044(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_10044() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(10044, 58) // Detect
        CASE_CREATE_SKILL_NODE(10044, 80) // IntOperation
        CASE_CREATE_SKILL_NODE(10044, 89) // AddSkillBuff
        CASE_CREATE_SKILL_NODE(10044, 91) // SetInt
        CASE_CREATE_SKILL_NODE(10044, 96) // IntOperation
        CASE_CREATE_SKILL_NODE(10044, 98) // CompareInt
        CASE_CREATE_SKILL_NODE(10044, 105) // IntOperation
        CASE_CREATE_SKILL_NODE(10044, 107) // IntOperation
        CASE_CREATE_SKILL_NODE(10044, 109) // SetInt
        CASE_CREATE_SKILL_NODE(10044, 112) // PlaySound
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_10044

SkillLogic* SkillCreator_10044::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //设置变量
    Variable_10044_a100441 = logic->getVariables().setVariable<int32_t>("a100441");
    //创建阶段phase
    auto phase = new SkillPhase_10044(1, logic, 1);
    //设置phase执行器
    phase->setDetectPhaseNode(1, 58);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_10044::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
