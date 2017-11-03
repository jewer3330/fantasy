#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

#include "skill_psnode_addskillbuff.h"
#include "skill_psnode_compareint.h"
#include "skill_psnode_detect.h"
#include "skill_psnode_playsound.h"
#include "skill_psnode_resetskill.h"

namespace pvp {

//变量声明
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10344, 6) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ResetSkill>(PhaseNode_Detect::TRIGGER_ON, 8, PhaseNode_ResetSkill::FUNC_DO, &PhaseNode_ResetSkill::Do);
}

REGISTER_CREATE_SKILL_NODE(10344, 6) {
    auto node6 = GET_SKILL_NODE(6, PhaseNode_Detect);
    if (node6 == nullptr) {
        node6 = new PhaseNode_Detect(6, phase);
        node6->setSelf(0U);
        node6->setEvent("");
        node6->setType(PhaseNode_Detect::Detect_Type::Assistant_Kill);
        node6->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10344, 6, node6)
    }
    if (noInit == true) {
        return node6;
    }
    return node6;
}
//--------------------------------------------------------------------------------
// ResetSkill
//
REGISTER_REGISTER_SKILL_NODE(10344, 8) {
    pnode->resizeTrigger(PhaseNode_ResetSkill::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_ResetSkill::TRIGGER_DONE, 10, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10344, 8) {
    auto node8 = GET_SKILL_NODE(8, PhaseNode_ResetSkill);
    if (node8 == nullptr) {
        node8 = new PhaseNode_ResetSkill(8, phase);
        node8->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node8->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node8->setSkillID({10342});
        node8->setTime(15.00f);
        CALL_REGISTER_SKILL_NODE(10344, 8, node8)
    }
    if (noInit == true) {
        return node8;
    }
    return node8;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10344, 10) {
}

REGISTER_CREATE_SKILL_NODE(10344, 10) {
    auto node10 = GET_SKILL_NODE(10, PhaseNode_PlaySound);
    if (node10 == nullptr) {
        node10 = new PhaseNode_PlaySound(10, phase);
        node10->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node10->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node10->setSoundID("SE_Hero134_SkillD");
        node10->setTarget(0U);
        node10->setUsePos(false);
        node10->setPosX(.00f);
        node10->setPosY(.00f);
        node10->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10344, 10, node10)
    }
    if (noInit == true) {
        return node10;
    }
    return node10;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10344, 12) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareInt>(PhaseNode_Detect::TRIGGER_ON, 17, PhaseNode_CompareInt::FUNC_COMPARE, &PhaseNode_CompareInt::Compare);
    pnode->regTrigger<PhaseNode_ResetSkill>(PhaseNode_Detect::TRIGGER_ON, 8, PhaseNode_ResetSkill::FUNC_DO, &PhaseNode_ResetSkill::Do);
}

REGISTER_CREATE_SKILL_NODE(10344, 12) {
    auto node12 = GET_SKILL_NODE(12, PhaseNode_Detect);
    if (node12 == nullptr) {
        node12 = new PhaseNode_Detect(12, phase);
        node12->setSelf(0U);
        node12->setEvent("");
        node12->setType(PhaseNode_Detect::Detect_Type::Kill_Target);
        node12->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10344, 12, node12)
    }
    if (noInit == true) {
        return node12;
    }
    return node12;
}
//--------------------------------------------------------------------------------
// CompareInt
//
REGISTER_REGISTER_SKILL_NODE(10344, 17) {
    pnode->resizeTrigger(PhaseNode_CompareInt::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuff>(PhaseNode_CompareInt::TRIGGER_EQUAL, 22, PhaseNode_AddSkillBuff::FUNC_ADD, &PhaseNode_AddSkillBuff::Add);
}

REGISTER_CREATE_SKILL_NODE(10344, 17) {
    auto node17 = GET_SKILL_NODE(17, PhaseNode_CompareInt);
    if (node17 == nullptr) {
        node17 = new PhaseNode_CompareInt(17, phase);
        node17->setA(10343);
        CALL_REGISTER_SKILL_NODE(10344, 17, node17)
    }
    if (noInit == true) {
        return node17;
    }
    auto node12 = GET_SKILL_NODE(12, PhaseNode_Detect);
    if (node12 != nullptr) node17->setB(node12->getVars().getVariable<int32_t>(2));
    return node17;
}
//--------------------------------------------------------------------------------
// AddSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10344, 22) {
}

REGISTER_CREATE_SKILL_NODE(10344, 22) {
    auto node22 = GET_SKILL_NODE(22, PhaseNode_AddSkillBuff);
    if (node22 == nullptr) {
        node22 = new PhaseNode_AddSkillBuff(22, phase);
        node22->setConfigID(103441);
        node22->setConfigIDs({});
        node22->setTarget(0U);
        node22->setAttribute({{}});
        CALL_REGISTER_SKILL_NODE(10344, 22, node22)
    }
    if (noInit == true) {
        return node22;
    }
    return node22;
}

//--------------------------------------------------------------------------------
// SkillCreator_10344
//
class SkillCreator_10344 : public SkillCreator {
public:
    SkillCreator_10344() {}
    virtual ~SkillCreator_10344() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_10344

//--------------------------------------------------------------------------------
// SkillPhase_10344
//
class SkillPhase_10344 : public SkillPhase {
public:
    SkillPhase_10344(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_10344() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(10344, 6) // Detect
        CASE_CREATE_SKILL_NODE(10344, 8) // ResetSkill
        CASE_CREATE_SKILL_NODE(10344, 10) // PlaySound
        CASE_CREATE_SKILL_NODE(10344, 12) // Detect
        CASE_CREATE_SKILL_NODE(10344, 17) // CompareInt
        CASE_CREATE_SKILL_NODE(10344, 22) // AddSkillBuff
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_10344

SkillLogic* SkillCreator_10344::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //创建阶段phase
    auto phase = new SkillPhase_10344(1, logic, 1);
    //设置phase执行器
    phase->setDetectPhaseNode(1, 6);
    phase->setDetectPhaseNode(1, 12);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_10344::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
