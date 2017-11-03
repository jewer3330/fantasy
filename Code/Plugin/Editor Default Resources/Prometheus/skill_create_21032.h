#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

#include "skill_psnode_delay.h"
#include "skill_psnode_detect.h"
#include "skill_psnode_endphase.h"
#include "skill_psnode_if.h"
#include "skill_psnode_playanimation.h"
#include "skill_psnode_skillendnotify.h"
#include "skill_psnode_startphase.h"

namespace pvp {

//变量声明
//--------------------------------------------------------------------------------
// StartPhase
//
REGISTER_REGISTER_SKILL_NODE(21032, 2) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_StartPhase::TRIGGER_START, 4, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(21032, 2) {
    auto node2 = GET_SKILL_NODE(2, PhaseNode_StartPhase);
    if (node2 == nullptr) {
        node2 = new PhaseNode_StartPhase(2, phase);
        CALL_REGISTER_SKILL_NODE(21032, 2, node2)
    }
    if (noInit == true) {
        return node2;
    }
    return node2;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(21032, 4) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlayAnimation::TRIGGER_DONE, 16, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(21032, 4) {
    auto node4 = GET_SKILL_NODE(4, PhaseNode_PlayAnimation);
    if (node4 == nullptr) {
        node4 = new PhaseNode_PlayAnimation(4, phase);
        node4->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node4->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node4->setTarget(0U);
        node4->setAnimation("Skill2S1");
        node4->setParameter("");
        node4->setValue(false);
        CALL_REGISTER_SKILL_NODE(21032, 4, node4)
    }
    if (noInit == true) {
        return node4;
    }
    return node4;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(21032, 8) {
}

REGISTER_CREATE_SKILL_NODE(21032, 8) {
    auto node8 = GET_SKILL_NODE(8, PhaseNode_EndPhase);
    if (node8 == nullptr) {
        node8 = new PhaseNode_EndPhase(8, phase);
        node8->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node8->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(21032, 8, node8)
    }
    if (noInit == true) {
        return node8;
    }
    return node8;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(21032, 12) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_Detect::TRIGGER_ON, 14, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(21032, 12) {
    auto node12 = GET_SKILL_NODE(12, PhaseNode_Detect);
    if (node12 == nullptr) {
        node12 = new PhaseNode_Detect(12, phase);
        node12->setSelf(0U);
        node12->setEvent("");
        node12->setType(PhaseNode_Detect::Detect_Type::Actor_Dead);
        node12->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(21032, 12, node12)
    }
    if (noInit == true) {
        return node12;
    }
    return node12;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(21032, 14) {
}

REGISTER_CREATE_SKILL_NODE(21032, 14) {
    auto node14 = GET_SKILL_NODE(14, PhaseNode_EndPhase);
    if (node14 == nullptr) {
        node14 = new PhaseNode_EndPhase(14, phase);
        node14->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node14->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(21032, 14, node14)
    }
    if (noInit == true) {
        return node14;
    }
    return node14;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(21032, 16) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_Delay::TRIGGER_DONE, 18, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(21032, 16) {
    auto node16 = GET_SKILL_NODE(16, PhaseNode_Delay);
    if (node16 == nullptr) {
        node16 = new PhaseNode_Delay(16, phase);
        node16->setTime(2.50f);
        CALL_REGISTER_SKILL_NODE(21032, 16, node16)
    }
    if (noInit == true) {
        return node16;
    }
    return node16;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(21032, 17) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 8, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(21032, 17) {
    auto node17 = GET_SKILL_NODE(17, PhaseNode_SkillEndNotify);
    if (node17 == nullptr) {
        node17 = new PhaseNode_SkillEndNotify(17, phase);
        node17->setReturnType(false);
        CALL_REGISTER_SKILL_NODE(21032, 17, node17)
    }
    if (noInit == true) {
        return node17;
    }
    return node17;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(21032, 18) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_FALSE, 19, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_TRUE, 17, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
}

REGISTER_CREATE_SKILL_NODE(21032, 18) {
    auto node18 = GET_SKILL_NODE(18, PhaseNode_If);
    if (node18 == nullptr) {
        node18 = new PhaseNode_If(18, phase);
        node18->setCondition(false);
        CALL_REGISTER_SKILL_NODE(21032, 18, node18)
    }
    if (noInit == true) {
        return node18;
    }
    return node18;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(21032, 19) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 8, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(21032, 19) {
    auto node19 = GET_SKILL_NODE(19, PhaseNode_SkillEndNotify);
    if (node19 == nullptr) {
        node19 = new PhaseNode_SkillEndNotify(19, phase);
        node19->setReturnType(true);
        CALL_REGISTER_SKILL_NODE(21032, 19, node19)
    }
    if (noInit == true) {
        return node19;
    }
    return node19;
}

//--------------------------------------------------------------------------------
// SkillCreator_21032
//
class SkillCreator_21032 : public SkillCreator {
public:
    SkillCreator_21032() {}
    virtual ~SkillCreator_21032() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_21032

//--------------------------------------------------------------------------------
// SkillPhase_21032
//
class SkillPhase_21032 : public SkillPhase {
public:
    SkillPhase_21032(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_21032() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(21032, 2) // StartPhase
        CASE_CREATE_SKILL_NODE(21032, 4) // PlayAnimation
        CASE_CREATE_SKILL_NODE(21032, 8) // EndPhase
        CASE_CREATE_SKILL_NODE(21032, 12) // Detect
        CASE_CREATE_SKILL_NODE(21032, 14) // EndPhase
        CASE_CREATE_SKILL_NODE(21032, 16) // Delay
        CASE_CREATE_SKILL_NODE(21032, 17) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(21032, 18) // If
        CASE_CREATE_SKILL_NODE(21032, 19) // SkillEndNotify
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_21032

SkillLogic* SkillCreator_21032::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //创建阶段phase
    auto phase = new SkillPhase_21032(1, logic, 2);
    //设置phase执行器
    phase->setRunPhaseNode(1, 2);
    phase->setDetectPhaseNode(2, 12);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_21032::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
