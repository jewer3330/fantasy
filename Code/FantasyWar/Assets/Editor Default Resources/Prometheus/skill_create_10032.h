#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

#include "skill_psnode_addskillbuff.h"
#include "skill_psnode_endphase.h"
#include "skill_psnode_playsound.h"
#include "skill_psnode_resetcd.h"
#include "skill_psnode_startphase.h"
#include "skill_psnode_triggerupdate.h"

namespace pvp {

//变量声明
//--------------------------------------------------------------------------------
// StartPhase
//
REGISTER_REGISTER_SKILL_NODE(10032, 2) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuff>(PhaseNode_StartPhase::TRIGGER_START, 23, PhaseNode_AddSkillBuff::FUNC_ADD, &PhaseNode_AddSkillBuff::Add);
}

REGISTER_CREATE_SKILL_NODE(10032, 2) {
    auto node2 = GET_SKILL_NODE(2, PhaseNode_StartPhase);
    if (node2 == nullptr) {
        node2 = new PhaseNode_StartPhase(2, phase);
        CALL_REGISTER_SKILL_NODE(10032, 2, node2)
    }
    if (noInit == true) {
        return node2;
    }
    return node2;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(10032, 16) {
}

REGISTER_CREATE_SKILL_NODE(10032, 16) {
    auto node16 = GET_SKILL_NODE(16, PhaseNode_EndPhase);
    if (node16 == nullptr) {
        node16 = new PhaseNode_EndPhase(16, phase);
        node16->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node16->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10032, 16, node16)
    }
    if (noInit == true) {
        return node16;
    }
    return node16;
}
//--------------------------------------------------------------------------------
// AddSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10032, 23) {
    pnode->resizeTrigger(PhaseNode_AddSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_AddSkillBuff::TRIGGER_DONE, 42, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(10032, 23) {
    auto node23 = GET_SKILL_NODE(23, PhaseNode_AddSkillBuff);
    if (node23 == nullptr) {
        node23 = new PhaseNode_AddSkillBuff(23, phase);
        node23->setConfigID(0);
        node23->setConfigIDs({100321,100322});
        node23->setTarget(0U);
        node23->setAttribute({{}});
        CALL_REGISTER_SKILL_NODE(10032, 23, node23)
    }
    if (noInit == true) {
        return node23;
    }
    return node23;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10032, 33) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_PlaySound::TRIGGER_DONE, 35, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10032, 33) {
    auto node33 = GET_SKILL_NODE(33, PhaseNode_PlaySound);
    if (node33 == nullptr) {
        node33 = new PhaseNode_PlaySound(33, phase);
        node33->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node33->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node33->setSoundID("SE_Hero111_Skill_B");
        node33->setTarget(0U);
        node33->setUsePos(false);
        node33->setPosX(.00f);
        node33->setPosY(.00f);
        node33->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10032, 33, node33)
    }
    if (noInit == true) {
        return node33;
    }
    return node33;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10032, 35) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_PlaySound::TRIGGER_DONE, 16, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(10032, 35) {
    auto node35 = GET_SKILL_NODE(35, PhaseNode_PlaySound);
    if (node35 == nullptr) {
        node35 = new PhaseNode_PlaySound(35, phase);
        node35->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node35->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node35->setSoundID("VO_Hero111_Skill_B");
        node35->setTarget(0U);
        node35->setUsePos(false);
        node35->setPosX(.00f);
        node35->setPosY(.00f);
        node35->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10032, 35, node35)
    }
    if (noInit == true) {
        return node35;
    }
    return node35;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(10032, 42) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_ResetCD::TRIGGER_DONE, 33, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10032, 42) {
    auto node42 = GET_SKILL_NODE(42, PhaseNode_ResetCD);
    if (node42 == nullptr) {
        node42 = new PhaseNode_ResetCD(42, phase);
        node42->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node42->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node42->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(10032, 42, node42)
    }
    if (noInit == true) {
        return node42;
    }
    return node42;
}
//--------------------------------------------------------------------------------
// TriggerUpdate
//
REGISTER_REGISTER_SKILL_NODE(10032, 78) {
}

REGISTER_CREATE_SKILL_NODE(10032, 78) {
    auto node78 = GET_SKILL_NODE(78, PhaseNode_TriggerUpdate);
    if (node78 == nullptr) {
        node78 = new PhaseNode_TriggerUpdate(78, phase);
        CALL_REGISTER_SKILL_NODE(10032, 78, node78)
    }
    if (noInit == true) {
        return node78;
    }
    return node78;
}

//--------------------------------------------------------------------------------
// SkillCreator_10032
//
class SkillCreator_10032 : public SkillCreator {
public:
    SkillCreator_10032() {}
    virtual ~SkillCreator_10032() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_10032

//--------------------------------------------------------------------------------
// SkillPhase_10032
//
class SkillPhase_10032 : public SkillPhase {
public:
    SkillPhase_10032(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_10032() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(10032, 2) // StartPhase
        CASE_CREATE_SKILL_NODE(10032, 16) // EndPhase
        CASE_CREATE_SKILL_NODE(10032, 23) // AddSkillBuff
        CASE_CREATE_SKILL_NODE(10032, 33) // PlaySound
        CASE_CREATE_SKILL_NODE(10032, 35) // PlaySound
        CASE_CREATE_SKILL_NODE(10032, 42) // ResetCD
        CASE_CREATE_SKILL_NODE(10032, 78) // TriggerUpdate
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_10032

SkillLogic* SkillCreator_10032::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //创建阶段phase
    auto phase = new SkillPhase_10032(1, logic, 2);
    //设置phase执行器
    phase->setRunPhaseNode(1, 2);
    phase->setRunPhaseNode(2, 78);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_10032::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
