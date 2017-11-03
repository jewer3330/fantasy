#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

#include "skill_psnode_addskillbuff.h"
#include "skill_psnode_endphase.h"
#include "skill_psnode_skillendnotify.h"
#include "skill_psnode_startphase.h"
#include "skill_psnode_triggerupdate.h"

namespace pvp {

//变量声明
//--------------------------------------------------------------------------------
// StartPhase
//
REGISTER_REGISTER_SKILL_NODE(15032, 3) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuff>(PhaseNode_StartPhase::TRIGGER_START, 37, PhaseNode_AddSkillBuff::FUNC_ADD, &PhaseNode_AddSkillBuff::Add);
}

REGISTER_CREATE_SKILL_NODE(15032, 3) {
    auto node3 = GET_SKILL_NODE(3, PhaseNode_StartPhase);
    if (node3 == nullptr) {
        node3 = new PhaseNode_StartPhase(3, phase);
        CALL_REGISTER_SKILL_NODE(15032, 3, node3)
    }
    if (noInit == true) {
        return node3;
    }
    return node3;
}
//--------------------------------------------------------------------------------
// TriggerUpdate
//
REGISTER_REGISTER_SKILL_NODE(15032, 7) {
}

REGISTER_CREATE_SKILL_NODE(15032, 7) {
    auto node7 = GET_SKILL_NODE(7, PhaseNode_TriggerUpdate);
    if (node7 == nullptr) {
        node7 = new PhaseNode_TriggerUpdate(7, phase);
        CALL_REGISTER_SKILL_NODE(15032, 7, node7)
    }
    if (noInit == true) {
        return node7;
    }
    return node7;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(15032, 18) {
}

REGISTER_CREATE_SKILL_NODE(15032, 18) {
    auto node18 = GET_SKILL_NODE(18, PhaseNode_EndPhase);
    if (node18 == nullptr) {
        node18 = new PhaseNode_EndPhase(18, phase);
        node18->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node18->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(15032, 18, node18)
    }
    if (noInit == true) {
        return node18;
    }
    return node18;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(15032, 22) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 18, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(15032, 22) {
    auto node22 = GET_SKILL_NODE(22, PhaseNode_SkillEndNotify);
    if (node22 == nullptr) {
        node22 = new PhaseNode_SkillEndNotify(22, phase);
        node22->setReturnType(true);
        CALL_REGISTER_SKILL_NODE(15032, 22, node22)
    }
    if (noInit == true) {
        return node22;
    }
    return node22;
}
//--------------------------------------------------------------------------------
// AddSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(15032, 37) {
    pnode->resizeTrigger(PhaseNode_AddSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_AddSkillBuff::TRIGGER_DONE, 22, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
}

REGISTER_CREATE_SKILL_NODE(15032, 37) {
    auto node37 = GET_SKILL_NODE(37, PhaseNode_AddSkillBuff);
    if (node37 == nullptr) {
        node37 = new PhaseNode_AddSkillBuff(37, phase);
        node37->setConfigID(4);
        node37->setConfigIDs({});
        node37->setTarget(0U);
        node37->setAttribute({{}});
        CALL_REGISTER_SKILL_NODE(15032, 37, node37)
    }
    if (noInit == true) {
        return node37;
    }
    return node37;
}

//--------------------------------------------------------------------------------
// SkillCreator_15032
//
class SkillCreator_15032 : public SkillCreator {
public:
    SkillCreator_15032() {}
    virtual ~SkillCreator_15032() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_15032

//--------------------------------------------------------------------------------
// SkillPhase_15032
//
class SkillPhase_15032 : public SkillPhase {
public:
    SkillPhase_15032(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_15032() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(15032, 3) // StartPhase
        CASE_CREATE_SKILL_NODE(15032, 7) // TriggerUpdate
        CASE_CREATE_SKILL_NODE(15032, 18) // EndPhase
        CASE_CREATE_SKILL_NODE(15032, 22) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(15032, 37) // AddSkillBuff
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_15032

SkillLogic* SkillCreator_15032::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //创建阶段phase
    auto phase = new SkillPhase_15032(1, logic, 2);
    //设置phase执行器
    phase->setRunPhaseNode(1, 3);
    phase->setRunPhaseNode(2, 7);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_15032::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
