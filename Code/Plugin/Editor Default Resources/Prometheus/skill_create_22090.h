#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

#include "skill_psnode_delay.h"
#include "skill_psnode_endphase.h"
#include "skill_psnode_if.h"
#include "skill_psnode_skillendnotify.h"
#include "skill_psnode_startphase.h"
#include "skill_psnode_triggerupdate.h"

namespace pvp {

//变量声明
//--------------------------------------------------------------------------------
// StartPhase
//
REGISTER_REGISTER_SKILL_NODE(22090, 3) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_StartPhase::TRIGGER_START, 10, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(22090, 3) {
    auto node3 = GET_SKILL_NODE(3, PhaseNode_StartPhase);
    if (node3 == nullptr) {
        node3 = new PhaseNode_StartPhase(3, phase);
        CALL_REGISTER_SKILL_NODE(22090, 3, node3)
    }
    if (noInit == true) {
        return node3;
    }
    return node3;
}
//--------------------------------------------------------------------------------
// TriggerUpdate
//
REGISTER_REGISTER_SKILL_NODE(22090, 5) {
}

REGISTER_CREATE_SKILL_NODE(22090, 5) {
    auto node5 = GET_SKILL_NODE(5, PhaseNode_TriggerUpdate);
    if (node5 == nullptr) {
        node5 = new PhaseNode_TriggerUpdate(5, phase);
        CALL_REGISTER_SKILL_NODE(22090, 5, node5)
    }
    if (noInit == true) {
        return node5;
    }
    return node5;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(22090, 9) {
}

REGISTER_CREATE_SKILL_NODE(22090, 9) {
    auto node9 = GET_SKILL_NODE(9, PhaseNode_EndPhase);
    if (node9 == nullptr) {
        node9 = new PhaseNode_EndPhase(9, phase);
        node9->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node9->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(22090, 9, node9)
    }
    if (noInit == true) {
        return node9;
    }
    return node9;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22090, 10) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_Delay::TRIGGER_DONE, 12, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(22090, 10) {
    auto node10 = GET_SKILL_NODE(10, PhaseNode_Delay);
    if (node10 == nullptr) {
        node10 = new PhaseNode_Delay(10, phase);
        node10->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(22090, 10, node10)
    }
    if (noInit == true) {
        return node10;
    }
    return node10;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(22090, 11) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 9, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(22090, 11) {
    auto node11 = GET_SKILL_NODE(11, PhaseNode_SkillEndNotify);
    if (node11 == nullptr) {
        node11 = new PhaseNode_SkillEndNotify(11, phase);
        node11->setReturnType(false);
        CALL_REGISTER_SKILL_NODE(22090, 11, node11)
    }
    if (noInit == true) {
        return node11;
    }
    return node11;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(22090, 12) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_FALSE, 13, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_TRUE, 11, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
}

REGISTER_CREATE_SKILL_NODE(22090, 12) {
    auto node12 = GET_SKILL_NODE(12, PhaseNode_If);
    if (node12 == nullptr) {
        node12 = new PhaseNode_If(12, phase);
        node12->setCondition(false);
        CALL_REGISTER_SKILL_NODE(22090, 12, node12)
    }
    if (noInit == true) {
        return node12;
    }
    return node12;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(22090, 13) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 9, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(22090, 13) {
    auto node13 = GET_SKILL_NODE(13, PhaseNode_SkillEndNotify);
    if (node13 == nullptr) {
        node13 = new PhaseNode_SkillEndNotify(13, phase);
        node13->setReturnType(true);
        CALL_REGISTER_SKILL_NODE(22090, 13, node13)
    }
    if (noInit == true) {
        return node13;
    }
    return node13;
}

//--------------------------------------------------------------------------------
// SkillCreator_22090
//
class SkillCreator_22090 : public SkillCreator {
public:
    SkillCreator_22090() {}
    virtual ~SkillCreator_22090() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_22090

//--------------------------------------------------------------------------------
// SkillPhase_22090
//
class SkillPhase_22090 : public SkillPhase {
public:
    SkillPhase_22090(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_22090() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(22090, 3) // StartPhase
        CASE_CREATE_SKILL_NODE(22090, 5) // TriggerUpdate
        CASE_CREATE_SKILL_NODE(22090, 9) // EndPhase
        CASE_CREATE_SKILL_NODE(22090, 10) // Delay
        CASE_CREATE_SKILL_NODE(22090, 11) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(22090, 12) // If
        CASE_CREATE_SKILL_NODE(22090, 13) // SkillEndNotify
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_22090

SkillLogic* SkillCreator_22090::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //创建阶段phase
    auto phase = new SkillPhase_22090(1, logic, 2);
    //设置phase执行器
    phase->setRunPhaseNode(1, 3);
    phase->setRunPhaseNode(2, 5);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_22090::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
