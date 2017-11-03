#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

#include "skill_psnode_addskillbuff.h"
#include "skill_psnode_detect.h"
#include "skill_psnode_playsound.h"
#include "skill_psnode_resetskill.h"

namespace pvp {

//变量声明
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10034, 2) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ResetSkill>(PhaseNode_Detect::TRIGGER_ON, 66, PhaseNode_ResetSkill::FUNC_DO, &PhaseNode_ResetSkill::Do);
}

REGISTER_CREATE_SKILL_NODE(10034, 2) {
    auto node2 = GET_SKILL_NODE(2, PhaseNode_Detect);
    if (node2 == nullptr) {
        node2 = new PhaseNode_Detect(2, phase);
        node2->setSelf(0U);
        node2->setEvent("");
        node2->setType(PhaseNode_Detect::Detect_Type::Kill_Target);
        node2->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10034, 2, node2)
    }
    if (noInit == true) {
        return node2;
    }
    return node2;
}
//--------------------------------------------------------------------------------
// AddSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10034, 5) {
    pnode->resizeTrigger(PhaseNode_AddSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_AddSkillBuff::TRIGGER_DONE, 7, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10034, 5) {
    auto node5 = GET_SKILL_NODE(5, PhaseNode_AddSkillBuff);
    if (node5 == nullptr) {
        node5 = new PhaseNode_AddSkillBuff(5, phase);
        node5->setConfigID(100341);
        node5->setConfigIDs({});
        node5->setTarget(0U);
        node5->setAttribute({{}});
        CALL_REGISTER_SKILL_NODE(10034, 5, node5)
    }
    if (noInit == true) {
        return node5;
    }
    return node5;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10034, 7) {
}

REGISTER_CREATE_SKILL_NODE(10034, 7) {
    auto node7 = GET_SKILL_NODE(7, PhaseNode_PlaySound);
    if (node7 == nullptr) {
        node7 = new PhaseNode_PlaySound(7, phase);
        node7->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node7->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node7->setSoundID("SE_Hero111_ATK_P2");
        node7->setTarget(0U);
        node7->setUsePos(false);
        node7->setPosX(.00f);
        node7->setPosY(.00f);
        node7->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10034, 7, node7)
    }
    if (noInit == true) {
        return node7;
    }
    return node7;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10034, 64) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ResetSkill>(PhaseNode_Detect::TRIGGER_ON, 66, PhaseNode_ResetSkill::FUNC_DO, &PhaseNode_ResetSkill::Do);
}

REGISTER_CREATE_SKILL_NODE(10034, 64) {
    auto node64 = GET_SKILL_NODE(64, PhaseNode_Detect);
    if (node64 == nullptr) {
        node64 = new PhaseNode_Detect(64, phase);
        node64->setSelf(0U);
        node64->setEvent("");
        node64->setType(PhaseNode_Detect::Detect_Type::Assistant_Kill);
        node64->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10034, 64, node64)
    }
    if (noInit == true) {
        return node64;
    }
    return node64;
}
//--------------------------------------------------------------------------------
// ResetSkill
//
REGISTER_REGISTER_SKILL_NODE(10034, 66) {
    pnode->resizeTrigger(PhaseNode_ResetSkill::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuff>(PhaseNode_ResetSkill::TRIGGER_DONE, 5, PhaseNode_AddSkillBuff::FUNC_ADD, &PhaseNode_AddSkillBuff::Add);
}

REGISTER_CREATE_SKILL_NODE(10034, 66) {
    auto node66 = GET_SKILL_NODE(66, PhaseNode_ResetSkill);
    if (node66 == nullptr) {
        node66 = new PhaseNode_ResetSkill(66, phase);
        node66->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node66->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node66->setSkillID({10032});
        node66->setTime(2.00f);
        CALL_REGISTER_SKILL_NODE(10034, 66, node66)
    }
    if (noInit == true) {
        return node66;
    }
    return node66;
}

//--------------------------------------------------------------------------------
// SkillCreator_10034
//
class SkillCreator_10034 : public SkillCreator {
public:
    SkillCreator_10034() {}
    virtual ~SkillCreator_10034() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_10034

//--------------------------------------------------------------------------------
// SkillPhase_10034
//
class SkillPhase_10034 : public SkillPhase {
public:
    SkillPhase_10034(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_10034() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(10034, 2) // Detect
        CASE_CREATE_SKILL_NODE(10034, 5) // AddSkillBuff
        CASE_CREATE_SKILL_NODE(10034, 7) // PlaySound
        CASE_CREATE_SKILL_NODE(10034, 64) // Detect
        CASE_CREATE_SKILL_NODE(10034, 66) // ResetSkill
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_10034

SkillLogic* SkillCreator_10034::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //创建阶段phase
    auto phase = new SkillPhase_10034(1, logic, 1);
    //设置phase执行器
    phase->setDetectPhaseNode(1, 2);
    phase->setDetectPhaseNode(1, 64);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_10034::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
