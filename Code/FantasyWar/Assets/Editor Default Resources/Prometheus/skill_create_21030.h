#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

#include "skill_psnode_addskillbuff.h"
#include "skill_psnode_delay.h"
#include "skill_psnode_endphase.h"
#include "skill_psnode_if.h"
#include "skill_psnode_skillendnotify.h"
#include "skill_psnode_startphase.h"

namespace pvp {

//变量声明
//--------------------------------------------------------------------------------
// StartPhase
//
REGISTER_REGISTER_SKILL_NODE(21030, 2) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuff>(PhaseNode_StartPhase::TRIGGER_START, 4, PhaseNode_AddSkillBuff::FUNC_ADD, &PhaseNode_AddSkillBuff::Add);
}

REGISTER_CREATE_SKILL_NODE(21030, 2) {
    auto node2 = GET_SKILL_NODE(2, PhaseNode_StartPhase);
    if (node2 == nullptr) {
        node2 = new PhaseNode_StartPhase(2, phase);
        CALL_REGISTER_SKILL_NODE(21030, 2, node2)
    }
    if (noInit == true) {
        return node2;
    }
    return node2;
}
//--------------------------------------------------------------------------------
// AddSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(21030, 4) {
    pnode->resizeTrigger(PhaseNode_AddSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_AddSkillBuff::TRIGGER_DONE, 11, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(21030, 4) {
    auto node4 = GET_SKILL_NODE(4, PhaseNode_AddSkillBuff);
    if (node4 == nullptr) {
        node4 = new PhaseNode_AddSkillBuff(4, phase);
        node4->setConfigID(210301);
        node4->setConfigIDs({});
        node4->setTarget(0U);
        node4->setAttribute({{}});
        CALL_REGISTER_SKILL_NODE(21030, 4, node4)
    }
    if (noInit == true) {
        return node4;
    }
    return node4;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(21030, 6) {
}

REGISTER_CREATE_SKILL_NODE(21030, 6) {
    auto node6 = GET_SKILL_NODE(6, PhaseNode_EndPhase);
    if (node6 == nullptr) {
        node6 = new PhaseNode_EndPhase(6, phase);
        node6->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node6->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(21030, 6, node6)
    }
    if (noInit == true) {
        return node6;
    }
    return node6;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(21030, 11) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_Delay::TRIGGER_DONE, 13, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(21030, 11) {
    auto node11 = GET_SKILL_NODE(11, PhaseNode_Delay);
    if (node11 == nullptr) {
        node11 = new PhaseNode_Delay(11, phase);
        node11->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(21030, 11, node11)
    }
    if (noInit == true) {
        return node11;
    }
    return node11;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(21030, 12) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 6, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(21030, 12) {
    auto node12 = GET_SKILL_NODE(12, PhaseNode_SkillEndNotify);
    if (node12 == nullptr) {
        node12 = new PhaseNode_SkillEndNotify(12, phase);
        node12->setReturnType(false);
        CALL_REGISTER_SKILL_NODE(21030, 12, node12)
    }
    if (noInit == true) {
        return node12;
    }
    return node12;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(21030, 13) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_FALSE, 14, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_TRUE, 12, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
}

REGISTER_CREATE_SKILL_NODE(21030, 13) {
    auto node13 = GET_SKILL_NODE(13, PhaseNode_If);
    if (node13 == nullptr) {
        node13 = new PhaseNode_If(13, phase);
        node13->setCondition(false);
        CALL_REGISTER_SKILL_NODE(21030, 13, node13)
    }
    if (noInit == true) {
        return node13;
    }
    return node13;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(21030, 14) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 6, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(21030, 14) {
    auto node14 = GET_SKILL_NODE(14, PhaseNode_SkillEndNotify);
    if (node14 == nullptr) {
        node14 = new PhaseNode_SkillEndNotify(14, phase);
        node14->setReturnType(true);
        CALL_REGISTER_SKILL_NODE(21030, 14, node14)
    }
    if (noInit == true) {
        return node14;
    }
    return node14;
}

//--------------------------------------------------------------------------------
// SkillCreator_21030
//
class SkillCreator_21030 : public SkillCreator {
public:
    SkillCreator_21030() {}
    virtual ~SkillCreator_21030() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_21030

//--------------------------------------------------------------------------------
// SkillPhase_21030
//
class SkillPhase_21030 : public SkillPhase {
public:
    SkillPhase_21030(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_21030() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(21030, 2) // StartPhase
        CASE_CREATE_SKILL_NODE(21030, 4) // AddSkillBuff
        CASE_CREATE_SKILL_NODE(21030, 6) // EndPhase
        CASE_CREATE_SKILL_NODE(21030, 11) // Delay
        CASE_CREATE_SKILL_NODE(21030, 12) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(21030, 13) // If
        CASE_CREATE_SKILL_NODE(21030, 14) // SkillEndNotify
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_21030

SkillLogic* SkillCreator_21030::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //创建阶段phase
    auto phase = new SkillPhase_21030(1, logic, 1);
    //设置phase执行器
    phase->setRunPhaseNode(1, 2);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_21030::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
