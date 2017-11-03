#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

#include "skill_psnode_addskillbuff.h"
#include "skill_psnode_delay.h"
#include "skill_psnode_endphase.h"
#include "skill_psnode_getbbparamuint64.h"
#include "skill_psnode_playanimation.h"
#include "skill_psnode_resetcd.h"
#include "skill_psnode_startphase.h"
#include "skill_psnode_triggerupdate.h"

namespace pvp {

//变量声明
//--------------------------------------------------------------------------------
// StartPhase
//
REGISTER_REGISTER_SKILL_NODE(23022, 2) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_StartPhase::TRIGGER_START, 6, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(23022, 2) {
    auto node2 = GET_SKILL_NODE(2, PhaseNode_StartPhase);
    if (node2 == nullptr) {
        node2 = new PhaseNode_StartPhase(2, phase);
        CALL_REGISTER_SKILL_NODE(23022, 2, node2)
    }
    if (noInit == true) {
        return node2;
    }
    return node2;
}
//--------------------------------------------------------------------------------
// TriggerUpdate
//
REGISTER_REGISTER_SKILL_NODE(23022, 4) {
}

REGISTER_CREATE_SKILL_NODE(23022, 4) {
    auto node4 = GET_SKILL_NODE(4, PhaseNode_TriggerUpdate);
    if (node4 == nullptr) {
        node4 = new PhaseNode_TriggerUpdate(4, phase);
        CALL_REGISTER_SKILL_NODE(23022, 4, node4)
    }
    if (noInit == true) {
        return node4;
    }
    return node4;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(23022, 6) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_ResetCD::TRIGGER_DONE, 8, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(23022, 6) {
    auto node6 = GET_SKILL_NODE(6, PhaseNode_ResetCD);
    if (node6 == nullptr) {
        node6 = new PhaseNode_ResetCD(6, phase);
        node6->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node6->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node6->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(23022, 6, node6)
    }
    if (noInit == true) {
        return node6;
    }
    return node6;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(23022, 8) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlayAnimation::TRIGGER_DONE, 10, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(23022, 8) {
    auto node8 = GET_SKILL_NODE(8, PhaseNode_PlayAnimation);
    if (node8 == nullptr) {
        node8 = new PhaseNode_PlayAnimation(8, phase);
        node8->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node8->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node8->setTarget(0U);
        node8->setAnimation("Skill2S1");
        node8->setParameter("");
        node8->setValue(false);
        CALL_REGISTER_SKILL_NODE(23022, 8, node8)
    }
    if (noInit == true) {
        return node8;
    }
    return node8;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(23022, 10) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetBBParamUInt64>(PhaseNode_Delay::TRIGGER_DONE, 12, PhaseNode_GetBBParamUInt64::FUNC_DO, &PhaseNode_GetBBParamUInt64::Do);
}

REGISTER_CREATE_SKILL_NODE(23022, 10) {
    auto node10 = GET_SKILL_NODE(10, PhaseNode_Delay);
    if (node10 == nullptr) {
        node10 = new PhaseNode_Delay(10, phase);
        node10->setTime(.66f);
        CALL_REGISTER_SKILL_NODE(23022, 10, node10)
    }
    if (noInit == true) {
        return node10;
    }
    return node10;
}
//--------------------------------------------------------------------------------
// GetBBParamUInt64
//
REGISTER_REGISTER_SKILL_NODE(23022, 12) {
    pnode->resizeTrigger(PhaseNode_GetBBParamUInt64::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuff>(PhaseNode_GetBBParamUInt64::TRIGGER_DONE, 14, PhaseNode_AddSkillBuff::FUNC_ADD, &PhaseNode_AddSkillBuff::Add);
}

REGISTER_CREATE_SKILL_NODE(23022, 12) {
    auto node12 = GET_SKILL_NODE(12, PhaseNode_GetBBParamUInt64);
    if (node12 == nullptr) {
        node12 = new PhaseNode_GetBBParamUInt64(12, phase);
        node12->setBBName("AllyTarget");
        CALL_REGISTER_SKILL_NODE(23022, 12, node12)
    }
    if (noInit == true) {
        return node12;
    }
    return node12;
}
//--------------------------------------------------------------------------------
// AddSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(23022, 14) {
    pnode->resizeTrigger(PhaseNode_AddSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_AddSkillBuff::TRIGGER_DONE, 16, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(23022, 14) {
    auto node14 = GET_SKILL_NODE(14, PhaseNode_AddSkillBuff);
    if (node14 == nullptr) {
        node14 = new PhaseNode_AddSkillBuff(14, phase);
        node14->setConfigID(230221);
        node14->setConfigIDs({});
        node14->setAttribute({{}});
        CALL_REGISTER_SKILL_NODE(23022, 14, node14)
    }
    if (noInit == true) {
        return node14;
    }
    auto node12 = GET_SKILL_NODE(12, PhaseNode_GetBBParamUInt64);
    if (node12 != nullptr) node14->setTarget(node12->getValue());
    return node14;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(23022, 16) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_Delay::TRIGGER_DONE, 18, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(23022, 16) {
    auto node16 = GET_SKILL_NODE(16, PhaseNode_Delay);
    if (node16 == nullptr) {
        node16 = new PhaseNode_Delay(16, phase);
        node16->setTime(.34f);
        CALL_REGISTER_SKILL_NODE(23022, 16, node16)
    }
    if (noInit == true) {
        return node16;
    }
    return node16;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(23022, 18) {
}

REGISTER_CREATE_SKILL_NODE(23022, 18) {
    auto node18 = GET_SKILL_NODE(18, PhaseNode_EndPhase);
    if (node18 == nullptr) {
        node18 = new PhaseNode_EndPhase(18, phase);
        node18->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node18->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(23022, 18, node18)
    }
    if (noInit == true) {
        return node18;
    }
    return node18;
}

//--------------------------------------------------------------------------------
// SkillCreator_23022
//
class SkillCreator_23022 : public SkillCreator {
public:
    SkillCreator_23022() {}
    virtual ~SkillCreator_23022() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_23022

//--------------------------------------------------------------------------------
// SkillPhase_23022
//
class SkillPhase_23022 : public SkillPhase {
public:
    SkillPhase_23022(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_23022() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(23022, 2) // StartPhase
        CASE_CREATE_SKILL_NODE(23022, 4) // TriggerUpdate
        CASE_CREATE_SKILL_NODE(23022, 6) // ResetCD
        CASE_CREATE_SKILL_NODE(23022, 8) // PlayAnimation
        CASE_CREATE_SKILL_NODE(23022, 10) // Delay
        CASE_CREATE_SKILL_NODE(23022, 12) // GetBBParamUInt64
        CASE_CREATE_SKILL_NODE(23022, 14) // AddSkillBuff
        CASE_CREATE_SKILL_NODE(23022, 16) // Delay
        CASE_CREATE_SKILL_NODE(23022, 18) // EndPhase
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_23022

SkillLogic* SkillCreator_23022::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //创建阶段phase
    auto phase = new SkillPhase_23022(1, logic, 2);
    //设置phase执行器
    phase->setRunPhaseNode(1, 2);
    phase->setRunPhaseNode(2, 4);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_23022::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
