#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

#include "skill_psnode_actorselect.h"
#include "skill_psnode_addskillbuff.h"
#include "skill_psnode_compareint.h"
#include "skill_psnode_destroyactor.h"
#include "skill_psnode_detect.h"
#include "skill_psnode_getuint64svalue.h"
#include "skill_psnode_uint64ssize.h"

namespace pvp {

//变量声明
//--------------------------------------------------------------------------------
// AddSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10105, 9) {
}

REGISTER_CREATE_SKILL_NODE(10105, 9) {
    auto node9 = GET_SKILL_NODE(9, PhaseNode_AddSkillBuff);
    if (node9 == nullptr) {
        node9 = new PhaseNode_AddSkillBuff(9, phase);
        node9->setConfigID(101041);
        node9->setConfigIDs({});
        node9->setTarget(0U);
        node9->setAttribute({{}});
        CALL_REGISTER_SKILL_NODE(10105, 9, node9)
    }
    if (noInit == true) {
        return node9;
    }
    return node9;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10105, 10) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuff>(PhaseNode_Detect::TRIGGER_ON, 9, PhaseNode_AddSkillBuff::FUNC_ADD, &PhaseNode_AddSkillBuff::Add);
}

REGISTER_CREATE_SKILL_NODE(10105, 10) {
    auto node10 = GET_SKILL_NODE(10, PhaseNode_Detect);
    if (node10 == nullptr) {
        node10 = new PhaseNode_Detect(10, phase);
        node10->setSelf(0U);
        node10->setEvent("");
        node10->setType(PhaseNode_Detect::Detect_Type::Actor_Spawn);
        node10->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10105, 10, node10)
    }
    if (noInit == true) {
        return node10;
    }
    return node10;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10105, 11) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ActorSelect>(PhaseNode_Detect::TRIGGER_ON, 12, PhaseNode_ActorSelect::FUNC_DO, &PhaseNode_ActorSelect::Do);
}

REGISTER_CREATE_SKILL_NODE(10105, 11) {
    auto node11 = GET_SKILL_NODE(11, PhaseNode_Detect);
    if (node11 == nullptr) {
        node11 = new PhaseNode_Detect(11, phase);
        node11->setSelf(0U);
        node11->setEvent("");
        node11->setType(PhaseNode_Detect::Detect_Type::Actor_Dead);
        node11->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10105, 11, node11)
    }
    if (noInit == true) {
        return node11;
    }
    return node11;
}
//--------------------------------------------------------------------------------
// ActorSelect
//
REGISTER_REGISTER_SKILL_NODE(10105, 12) {
    pnode->resizeTrigger(PhaseNode_ActorSelect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_UInt64sSize>(PhaseNode_ActorSelect::TRIGGER_DONE, 13, PhaseNode_UInt64sSize::FUNC_DO, &PhaseNode_UInt64sSize::Do);
}

REGISTER_CREATE_SKILL_NODE(10105, 12) {
    auto node12 = GET_SKILL_NODE(12, PhaseNode_ActorSelect);
    if (node12 == nullptr) {
        node12 = new PhaseNode_ActorSelect(12, phase);
        node12->setTarget(0U);
        node12->setConfigID(4011);
        CALL_REGISTER_SKILL_NODE(10105, 12, node12)
    }
    if (noInit == true) {
        return node12;
    }
    return node12;
}
//--------------------------------------------------------------------------------
// UInt64sSize
//
REGISTER_REGISTER_SKILL_NODE(10105, 13) {
    pnode->resizeTrigger(PhaseNode_UInt64sSize::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareInt>(PhaseNode_UInt64sSize::TRIGGER_DONE, 14, PhaseNode_CompareInt::FUNC_COMPARE, &PhaseNode_CompareInt::Compare);
}

REGISTER_CREATE_SKILL_NODE(10105, 13) {
    auto node13 = GET_SKILL_NODE(13, PhaseNode_UInt64sSize);
    if (node13 == nullptr) {
        node13 = new PhaseNode_UInt64sSize(13, phase);
        CALL_REGISTER_SKILL_NODE(10105, 13, node13)
    }
    if (noInit == true) {
        return node13;
    }
    auto node12 = GET_SKILL_NODE(12, PhaseNode_ActorSelect);
    if (node12 != nullptr) node13->setArr(node12->getTargets());
    return node13;
}
//--------------------------------------------------------------------------------
// CompareInt
//
REGISTER_REGISTER_SKILL_NODE(10105, 14) {
    pnode->resizeTrigger(PhaseNode_CompareInt::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetUInt64sValue>(PhaseNode_CompareInt::TRIGGER_GREATER, 16, PhaseNode_GetUInt64sValue::FUNC_DO, &PhaseNode_GetUInt64sValue::Do);
}

REGISTER_CREATE_SKILL_NODE(10105, 14) {
    auto node14 = GET_SKILL_NODE(14, PhaseNode_CompareInt);
    if (node14 == nullptr) {
        node14 = new PhaseNode_CompareInt(14, phase);
        node14->setB(0);
        CALL_REGISTER_SKILL_NODE(10105, 14, node14)
    }
    if (noInit == true) {
        return node14;
    }
    auto node13 = GET_SKILL_NODE(13, PhaseNode_UInt64sSize);
    if (node13 != nullptr) node14->setA(node13->getSize());
    return node14;
}
//--------------------------------------------------------------------------------
// DestroyActor
//
REGISTER_REGISTER_SKILL_NODE(10105, 15) {
}

REGISTER_CREATE_SKILL_NODE(10105, 15) {
    auto node15 = GET_SKILL_NODE(15, PhaseNode_DestroyActor);
    if (node15 == nullptr) {
        node15 = new PhaseNode_DestroyActor(15, phase);
        CALL_REGISTER_SKILL_NODE(10105, 15, node15)
    }
    if (noInit == true) {
        return node15;
    }
    auto node16 = GET_SKILL_NODE(16, PhaseNode_GetUInt64sValue);
    if (node16 != nullptr) node15->setActorID(node16->getValue());
    return node15;
}
//--------------------------------------------------------------------------------
// GetUInt64sValue
//
REGISTER_REGISTER_SKILL_NODE(10105, 16) {
    pnode->resizeTrigger(PhaseNode_GetUInt64sValue::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_DestroyActor>(PhaseNode_GetUInt64sValue::TRIGGER_DONE, 15, PhaseNode_DestroyActor::FUNC_DO, &PhaseNode_DestroyActor::Do);
}

REGISTER_CREATE_SKILL_NODE(10105, 16) {
    auto node16 = GET_SKILL_NODE(16, PhaseNode_GetUInt64sValue);
    if (node16 == nullptr) {
        node16 = new PhaseNode_GetUInt64sValue(16, phase);
        node16->setIndex(0);
        CALL_REGISTER_SKILL_NODE(10105, 16, node16)
    }
    if (noInit == true) {
        return node16;
    }
    auto node12 = GET_SKILL_NODE(12, PhaseNode_ActorSelect);
    if (node12 != nullptr) node16->setArr(node12->getTargets());
    return node16;
}

//--------------------------------------------------------------------------------
// SkillCreator_10105
//
class SkillCreator_10105 : public SkillCreator {
public:
    SkillCreator_10105() {}
    virtual ~SkillCreator_10105() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_10105

//--------------------------------------------------------------------------------
// SkillPhase_10105
//
class SkillPhase_10105 : public SkillPhase {
public:
    SkillPhase_10105(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_10105() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(10105, 9) // AddSkillBuff
        CASE_CREATE_SKILL_NODE(10105, 10) // Detect
        CASE_CREATE_SKILL_NODE(10105, 11) // Detect
        CASE_CREATE_SKILL_NODE(10105, 12) // ActorSelect
        CASE_CREATE_SKILL_NODE(10105, 13) // UInt64sSize
        CASE_CREATE_SKILL_NODE(10105, 14) // CompareInt
        CASE_CREATE_SKILL_NODE(10105, 15) // DestroyActor
        CASE_CREATE_SKILL_NODE(10105, 16) // GetUInt64sValue
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_10105

SkillLogic* SkillCreator_10105::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //创建阶段phase
    auto phase = new SkillPhase_10105(1, logic, 1);
    //设置phase执行器
    phase->setDetectPhaseNode(1, 10);
    phase->setDetectPhaseNode(1, 11);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_10105::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
