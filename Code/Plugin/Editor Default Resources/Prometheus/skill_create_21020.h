#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

#include "skill_psnode_delay.h"
#include "skill_psnode_detect.h"
#include "skill_psnode_if.h"
#include "skill_psnode_playeffect.h"
#include "skill_psnode_raiseevent.h"
#include "skill_psnode_setbool.h"
#include "skill_psnode_skillendnotify.h"
#include "skill_psnode_startphase.h"

namespace pvp {

//变量声明
uint64_t Variable_21020_EffectEnable = 0;
//--------------------------------------------------------------------------------
// StartPhase
//
REGISTER_REGISTER_SKILL_NODE(21020, 5) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_StartPhase::TRIGGER_START, 18, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(21020, 5) {
    auto node5 = GET_SKILL_NODE(5, PhaseNode_StartPhase);
    if (node5 == nullptr) {
        node5 = new PhaseNode_StartPhase(5, phase);
        CALL_REGISTER_SKILL_NODE(21020, 5, node5)
    }
    if (noInit == true) {
        return node5;
    }
    return node5;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(21020, 10) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlayEffect::TRIGGER_DONE, 15, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(21020, 10) {
    auto node10 = GET_SKILL_NODE(10, PhaseNode_PlayEffect);
    if (node10 == nullptr) {
        node10 = new PhaseNode_PlayEffect(10, phase);
        node10->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node10->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node10->setEffectID(210000);
        node10->setChangeColor(false);
        node10->setType(PhaseNode_PlayEffect::PlayEffect_Type::WithTarget);
        node10->getVars().reserve(5);
        node10->getVars().setVariable<uint64_t>(0, 0U);
        node10->getVars().setVariable<std::string>(1, "Hit");
        node10->getVars().setVariable<float>(2, .00f);
        node10->getVars().setVariable<float>(3, .00f);
        node10->getVars().setVariable<float>(4, .00f);
        node10->setRotation(.00f);
        node10->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(21020, 10, node10)
    }
    if (noInit == true) {
        return node10;
    }
    return node10;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(21020, 12) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_If::TRIGGER_TRUE, 14, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(21020, 12) {
    auto node12 = GET_SKILL_NODE(12, PhaseNode_If);
    if (node12 == nullptr) {
        node12 = new PhaseNode_If(12, phase);
        CALL_REGISTER_SKILL_NODE(21020, 12, node12)
    }
    if (noInit == true) {
        return node12;
    }
    auto variables = node12->getVariables();
    if (variables != nullptr) {
        node12->setCondition(variables->getVariable<bool>(Variable_21020_EffectEnable));
    }
    return node12;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(21020, 14) {
    pnode->resizeTrigger(PhaseNode_SetBool::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_SetBool::TRIGGER_DONE, 10, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(21020, 14) {
    auto node14 = GET_SKILL_NODE(14, PhaseNode_SetBool);
    if (node14 == nullptr) {
        node14 = new PhaseNode_SetBool(14, phase);
        node14->setName("EffectEnable");
        node14->setValue(false);
        CALL_REGISTER_SKILL_NODE(21020, 14, node14)
    }
    if (noInit == true) {
        return node14;
    }
    return node14;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(21020, 15) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_Delay::TRIGGER_DONE, 16, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(21020, 15) {
    auto node15 = GET_SKILL_NODE(15, PhaseNode_Delay);
    if (node15 == nullptr) {
        node15 = new PhaseNode_Delay(15, phase);
        node15->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(21020, 15, node15)
    }
    if (noInit == true) {
        return node15;
    }
    return node15;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(21020, 16) {
}

REGISTER_CREATE_SKILL_NODE(21020, 16) {
    auto node16 = GET_SKILL_NODE(16, PhaseNode_SetBool);
    if (node16 == nullptr) {
        node16 = new PhaseNode_SetBool(16, phase);
        node16->setName("EffectEnable");
        node16->setValue(true);
        CALL_REGISTER_SKILL_NODE(21020, 16, node16)
    }
    if (noInit == true) {
        return node16;
    }
    return node16;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(21020, 17) {
}

REGISTER_CREATE_SKILL_NODE(21020, 17) {
    auto node17 = GET_SKILL_NODE(17, PhaseNode_SkillEndNotify);
    if (node17 == nullptr) {
        node17 = new PhaseNode_SkillEndNotify(17, phase);
        node17->setReturnType(true);
        CALL_REGISTER_SKILL_NODE(21020, 17, node17)
    }
    if (noInit == true) {
        return node17;
    }
    return node17;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(21020, 18) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_RaiseEvent::TRIGGER_DONE, 17, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
}

REGISTER_CREATE_SKILL_NODE(21020, 18) {
    auto node18 = GET_SKILL_NODE(18, PhaseNode_RaiseEvent);
    if (node18 == nullptr) {
        node18 = new PhaseNode_RaiseEvent(18, phase);
        node18->setEvent("GetDamage");
        node18->setTarget(0U);
        node18->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node18->setTypeParams(0, 0);
        node18->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(21020, 18, node18)
    }
    if (noInit == true) {
        return node18;
    }
    return node18;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(21020, 19) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_Detect::TRIGGER_ON, 12, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(21020, 19) {
    auto node19 = GET_SKILL_NODE(19, PhaseNode_Detect);
    if (node19 == nullptr) {
        node19 = new PhaseNode_Detect(19, phase);
        node19->setSelf(0U);
        node19->setEvent("GetDamage");
        node19->setType(PhaseNode_Detect::Detect_Type::Damage);
        node19->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(21020, 19, node19)
    }
    if (noInit == true) {
        return node19;
    }
    return node19;
}

//--------------------------------------------------------------------------------
// SkillCreator_21020
//
class SkillCreator_21020 : public SkillCreator {
public:
    SkillCreator_21020() {}
    virtual ~SkillCreator_21020() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_21020

//--------------------------------------------------------------------------------
// SkillPhase_21020
//
class SkillPhase_21020 : public SkillPhase {
public:
    SkillPhase_21020(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_21020() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(21020, 5) // StartPhase
        CASE_CREATE_SKILL_NODE(21020, 10) // PlayEffect
        CASE_CREATE_SKILL_NODE(21020, 12) // If
        CASE_CREATE_SKILL_NODE(21020, 14) // SetBool
        CASE_CREATE_SKILL_NODE(21020, 15) // Delay
        CASE_CREATE_SKILL_NODE(21020, 16) // SetBool
        CASE_CREATE_SKILL_NODE(21020, 17) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(21020, 18) // RaiseEvent
        CASE_CREATE_SKILL_NODE(21020, 19) // Detect
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_21020

SkillLogic* SkillCreator_21020::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //设置变量
    Variable_21020_EffectEnable = logic->getVariables().setVariable<bool>("EffectEnable", true);
    //创建阶段phase
    auto phase = new SkillPhase_21020(1, logic, 2);
    //设置phase执行器
    phase->setRunPhaseNode(1, 5);
    phase->setDetectPhaseNode(2, 19);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_21020::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
