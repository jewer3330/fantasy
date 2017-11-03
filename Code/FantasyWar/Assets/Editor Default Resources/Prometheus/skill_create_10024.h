#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

#include "skill_psnode_addskillbuff.h"
#include "skill_psnode_detect.h"
#include "skill_psnode_if.h"
#include "skill_psnode_removeskillbuff.h"
#include "skill_psnode_setbool.h"
#include "skill_psnode_timedown.h"

namespace pvp {

//变量声明
uint64_t Variable_10024_a100241 = 0;
//--------------------------------------------------------------------------------
// TimeDown
//
REGISTER_REGISTER_SKILL_NODE(10024, 2) {
    pnode->resizeTrigger(PhaseNode_TimeDown::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuff>(PhaseNode_TimeDown::TRIGGER_DONE, 62, PhaseNode_AddSkillBuff::FUNC_ADD, &PhaseNode_AddSkillBuff::Add);
}

REGISTER_CREATE_SKILL_NODE(10024, 2) {
    auto node2 = GET_SKILL_NODE(2, PhaseNode_TimeDown);
    if (node2 == nullptr) {
        node2 = new PhaseNode_TimeDown(2, phase);
        node2->setTime(3.00f);
        node2->setNum(0);
        node2->setIsImmediateFirst(false);
        CALL_REGISTER_SKILL_NODE(10024, 2, node2)
    }
    if (noInit == true) {
        return node2;
    }
    return node2;
}
//--------------------------------------------------------------------------------
// RemoveSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10024, 10) {
    pnode->resizeTrigger(PhaseNode_RemoveSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_RemoveSkillBuff::TRIGGER_DONE, 44, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(10024, 10) {
    auto node10 = GET_SKILL_NODE(10, PhaseNode_RemoveSkillBuff);
    if (node10 == nullptr) {
        node10 = new PhaseNode_RemoveSkillBuff(10, phase);
        node10->setBuffID(0U);
        node10->setBuffIDs({});
        node10->setConfigID(100241);
        node10->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(10024, 10, node10)
    }
    if (noInit == true) {
        return node10;
    }
    return node10;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10024, 13) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TimeDown>(PhaseNode_Detect::TRIGGER_ON, 2, PhaseNode_TimeDown::FUNC_DO, &PhaseNode_TimeDown::Do);
}

REGISTER_CREATE_SKILL_NODE(10024, 13) {
    auto node13 = GET_SKILL_NODE(13, PhaseNode_Detect);
    if (node13 == nullptr) {
        node13 = new PhaseNode_Detect(13, phase);
        node13->setSelf(0U);
        node13->setEvent("");
        node13->setType(PhaseNode_Detect::Detect_Type::Actor_Spawn);
        node13->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10024, 13, node13)
    }
    if (noInit == true) {
        return node13;
    }
    return node13;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(10024, 19) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RemoveSkillBuff>(PhaseNode_If::TRIGGER_TRUE, 10, PhaseNode_RemoveSkillBuff::FUNC_REMOVE, &PhaseNode_RemoveSkillBuff::Remove);
}

REGISTER_CREATE_SKILL_NODE(10024, 19) {
    auto node19 = GET_SKILL_NODE(19, PhaseNode_If);
    if (node19 == nullptr) {
        node19 = new PhaseNode_If(19, phase);
        CALL_REGISTER_SKILL_NODE(10024, 19, node19)
    }
    if (noInit == true) {
        return node19;
    }
    auto variables = node19->getVariables();
    if (variables != nullptr) {
        node19->setCondition(variables->getVariable<bool>(Variable_10024_a100241));
    }
    return node19;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(10024, 23) {
}

REGISTER_CREATE_SKILL_NODE(10024, 23) {
    auto node23 = GET_SKILL_NODE(23, PhaseNode_SetBool);
    if (node23 == nullptr) {
        node23 = new PhaseNode_SetBool(23, phase);
        node23->setName("a100241");
        node23->setValue(true);
        CALL_REGISTER_SKILL_NODE(10024, 23, node23)
    }
    if (noInit == true) {
        return node23;
    }
    return node23;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(10024, 44) {
}

REGISTER_CREATE_SKILL_NODE(10024, 44) {
    auto node44 = GET_SKILL_NODE(44, PhaseNode_SetBool);
    if (node44 == nullptr) {
        node44 = new PhaseNode_SetBool(44, phase);
        node44->setName("a100241");
        node44->setValue(false);
        CALL_REGISTER_SKILL_NODE(10024, 44, node44)
    }
    if (noInit == true) {
        return node44;
    }
    return node44;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10024, 50) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_Detect::TRIGGER_ON, 19, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_TimeDown>(PhaseNode_Detect::TRIGGER_ON, 2, PhaseNode_TimeDown::FUNC_CANCEL, &PhaseNode_TimeDown::Cancel);
}

REGISTER_CREATE_SKILL_NODE(10024, 50) {
    auto node50 = GET_SKILL_NODE(50, PhaseNode_Detect);
    if (node50 == nullptr) {
        node50 = new PhaseNode_Detect(50, phase);
        node50->setSelf(0U);
        node50->setEvent("");
        node50->setType(PhaseNode_Detect::Detect_Type::Actor_Dead);
        node50->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10024, 50, node50)
    }
    if (noInit == true) {
        return node50;
    }
    return node50;
}
//--------------------------------------------------------------------------------
// AddSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10024, 62) {
    pnode->resizeTrigger(PhaseNode_AddSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_AddSkillBuff::TRIGGER_DONE, 23, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(10024, 62) {
    auto node62 = GET_SKILL_NODE(62, PhaseNode_AddSkillBuff);
    if (node62 == nullptr) {
        node62 = new PhaseNode_AddSkillBuff(62, phase);
        node62->setConfigID(100241);
        node62->setConfigIDs({});
        node62->setTarget(0U);
        node62->setAttribute({{}});
        CALL_REGISTER_SKILL_NODE(10024, 62, node62)
    }
    if (noInit == true) {
        return node62;
    }
    return node62;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10024, 64) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_Detect::TRIGGER_ON, 19, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_TimeDown>(PhaseNode_Detect::TRIGGER_ON, 2, PhaseNode_TimeDown::FUNC_DO, &PhaseNode_TimeDown::Do);
}

REGISTER_CREATE_SKILL_NODE(10024, 64) {
    auto node64 = GET_SKILL_NODE(64, PhaseNode_Detect);
    if (node64 == nullptr) {
        node64 = new PhaseNode_Detect(64, phase);
        node64->setSelf(0U);
        node64->setEvent("");
        node64->setType(PhaseNode_Detect::Detect_Type::Damage);
        node64->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10024, 64, node64)
    }
    if (noInit == true) {
        return node64;
    }
    return node64;
}

//--------------------------------------------------------------------------------
// SkillCreator_10024
//
class SkillCreator_10024 : public SkillCreator {
public:
    SkillCreator_10024() {}
    virtual ~SkillCreator_10024() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_10024

//--------------------------------------------------------------------------------
// SkillPhase_10024
//
class SkillPhase_10024 : public SkillPhase {
public:
    SkillPhase_10024(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_10024() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(10024, 2) // TimeDown
        CASE_CREATE_SKILL_NODE(10024, 10) // RemoveSkillBuff
        CASE_CREATE_SKILL_NODE(10024, 13) // Detect
        CASE_CREATE_SKILL_NODE(10024, 19) // If
        CASE_CREATE_SKILL_NODE(10024, 23) // SetBool
        CASE_CREATE_SKILL_NODE(10024, 44) // SetBool
        CASE_CREATE_SKILL_NODE(10024, 50) // Detect
        CASE_CREATE_SKILL_NODE(10024, 62) // AddSkillBuff
        CASE_CREATE_SKILL_NODE(10024, 64) // Detect
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_10024

SkillLogic* SkillCreator_10024::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //设置变量
    Variable_10024_a100241 = logic->getVariables().setVariable<bool>("a100241");
    //创建阶段phase
    auto phase = new SkillPhase_10024(1, logic, 1);
    //设置phase执行器
    phase->setDetectPhaseNode(1, 13);
    phase->setDetectPhaseNode(1, 50);
    phase->setDetectPhaseNode(1, 64);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_10024::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
