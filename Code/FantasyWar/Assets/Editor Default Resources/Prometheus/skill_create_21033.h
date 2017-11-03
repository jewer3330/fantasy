#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

#include "skill_psnode_addskillbuff.h"
#include "skill_psnode_delay.h"
#include "skill_psnode_detect.h"
#include "skill_psnode_if.h"
#include "skill_psnode_playanimation.h"
#include "skill_psnode_playeffect.h"
#include "skill_psnode_raiseevent.h"
#include "skill_psnode_setbool.h"
#include "skill_psnode_skillendnotify.h"
#include "skill_psnode_startphase.h"

namespace pvp {

//变量声明
uint64_t Variable_21033_EffectEnable = 0;
//--------------------------------------------------------------------------------
// StartPhase
//
REGISTER_REGISTER_SKILL_NODE(21033, 5) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_StartPhase::TRIGGER_START, 7, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(21033, 5) {
    auto node5 = GET_SKILL_NODE(5, PhaseNode_StartPhase);
    if (node5 == nullptr) {
        node5 = new PhaseNode_StartPhase(5, phase);
        CALL_REGISTER_SKILL_NODE(21033, 5, node5)
    }
    if (noInit == true) {
        return node5;
    }
    return node5;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(21033, 7) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuff>(PhaseNode_PlayAnimation::TRIGGER_DONE, 14, PhaseNode_AddSkillBuff::FUNC_ADD, &PhaseNode_AddSkillBuff::Add);
}

REGISTER_CREATE_SKILL_NODE(21033, 7) {
    auto node7 = GET_SKILL_NODE(7, PhaseNode_PlayAnimation);
    if (node7 == nullptr) {
        node7 = new PhaseNode_PlayAnimation(7, phase);
        node7->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node7->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node7->setTarget(0U);
        node7->setAnimation("Skill2S1");
        node7->setParameter("");
        node7->setValue(false);
        CALL_REGISTER_SKILL_NODE(21033, 7, node7)
    }
    if (noInit == true) {
        return node7;
    }
    return node7;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(21033, 10) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_Delay::TRIGGER_DONE, 12, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(21033, 10) {
    auto node10 = GET_SKILL_NODE(10, PhaseNode_Delay);
    if (node10 == nullptr) {
        node10 = new PhaseNode_Delay(10, phase);
        node10->setTime(1.00f);
        CALL_REGISTER_SKILL_NODE(21033, 10, node10)
    }
    if (noInit == true) {
        return node10;
    }
    return node10;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(21033, 12) {
}

REGISTER_CREATE_SKILL_NODE(21033, 12) {
    auto node12 = GET_SKILL_NODE(12, PhaseNode_PlayAnimation);
    if (node12 == nullptr) {
        node12 = new PhaseNode_PlayAnimation(12, phase);
        node12->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node12->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node12->setTarget(0U);
        node12->setAnimation("Idle");
        node12->setParameter("");
        node12->setValue(false);
        CALL_REGISTER_SKILL_NODE(21033, 12, node12)
    }
    if (noInit == true) {
        return node12;
    }
    return node12;
}
//--------------------------------------------------------------------------------
// AddSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(21033, 14) {
    pnode->resizeTrigger(PhaseNode_AddSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_AddSkillBuff::TRIGGER_DONE, 23, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(21033, 14) {
    auto node14 = GET_SKILL_NODE(14, PhaseNode_AddSkillBuff);
    if (node14 == nullptr) {
        node14 = new PhaseNode_AddSkillBuff(14, phase);
        node14->setConfigID(4);
        node14->setConfigIDs({});
        node14->setTarget(0U);
        node14->setAttribute({{}});
        CALL_REGISTER_SKILL_NODE(21033, 14, node14)
    }
    if (noInit == true) {
        return node14;
    }
    return node14;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(21033, 15) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlayEffect::TRIGGER_DONE, 20, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(21033, 15) {
    auto node15 = GET_SKILL_NODE(15, PhaseNode_PlayEffect);
    if (node15 == nullptr) {
        node15 = new PhaseNode_PlayEffect(15, phase);
        node15->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node15->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node15->setEffectID(210000);
        node15->setChangeColor(false);
        node15->setType(PhaseNode_PlayEffect::PlayEffect_Type::WithTarget);
        node15->getVars().reserve(5);
        node15->getVars().setVariable<uint64_t>(0, 0U);
        node15->getVars().setVariable<std::string>(1, "Hit");
        node15->getVars().setVariable<float>(2, .00f);
        node15->getVars().setVariable<float>(3, .00f);
        node15->getVars().setVariable<float>(4, .00f);
        node15->setRotation(.00f);
        node15->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(21033, 15, node15)
    }
    if (noInit == true) {
        return node15;
    }
    return node15;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(21033, 17) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_If::TRIGGER_TRUE, 19, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(21033, 17) {
    auto node17 = GET_SKILL_NODE(17, PhaseNode_If);
    if (node17 == nullptr) {
        node17 = new PhaseNode_If(17, phase);
        CALL_REGISTER_SKILL_NODE(21033, 17, node17)
    }
    if (noInit == true) {
        return node17;
    }
    auto variables = node17->getVariables();
    if (variables != nullptr) {
        node17->setCondition(variables->getVariable<bool>(Variable_21033_EffectEnable));
    }
    return node17;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(21033, 19) {
    pnode->resizeTrigger(PhaseNode_SetBool::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_SetBool::TRIGGER_DONE, 15, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(21033, 19) {
    auto node19 = GET_SKILL_NODE(19, PhaseNode_SetBool);
    if (node19 == nullptr) {
        node19 = new PhaseNode_SetBool(19, phase);
        node19->setName("EffectEnable");
        node19->setValue(false);
        CALL_REGISTER_SKILL_NODE(21033, 19, node19)
    }
    if (noInit == true) {
        return node19;
    }
    return node19;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(21033, 20) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_Delay::TRIGGER_DONE, 21, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(21033, 20) {
    auto node20 = GET_SKILL_NODE(20, PhaseNode_Delay);
    if (node20 == nullptr) {
        node20 = new PhaseNode_Delay(20, phase);
        node20->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(21033, 20, node20)
    }
    if (noInit == true) {
        return node20;
    }
    return node20;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(21033, 21) {
}

REGISTER_CREATE_SKILL_NODE(21033, 21) {
    auto node21 = GET_SKILL_NODE(21, PhaseNode_SetBool);
    if (node21 == nullptr) {
        node21 = new PhaseNode_SetBool(21, phase);
        node21->setName("EffectEnable");
        node21->setValue(true);
        CALL_REGISTER_SKILL_NODE(21033, 21, node21)
    }
    if (noInit == true) {
        return node21;
    }
    return node21;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(21033, 22) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 10, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(21033, 22) {
    auto node22 = GET_SKILL_NODE(22, PhaseNode_SkillEndNotify);
    if (node22 == nullptr) {
        node22 = new PhaseNode_SkillEndNotify(22, phase);
        node22->setReturnType(true);
        CALL_REGISTER_SKILL_NODE(21033, 22, node22)
    }
    if (noInit == true) {
        return node22;
    }
    return node22;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(21033, 23) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_RaiseEvent::TRIGGER_DONE, 22, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
}

REGISTER_CREATE_SKILL_NODE(21033, 23) {
    auto node23 = GET_SKILL_NODE(23, PhaseNode_RaiseEvent);
    if (node23 == nullptr) {
        node23 = new PhaseNode_RaiseEvent(23, phase);
        node23->setEvent("GetDamage");
        node23->setTarget(0U);
        node23->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node23->setTypeParams(0, 0);
        node23->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(21033, 23, node23)
    }
    if (noInit == true) {
        return node23;
    }
    return node23;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(21033, 24) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_Detect::TRIGGER_ON, 17, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(21033, 24) {
    auto node24 = GET_SKILL_NODE(24, PhaseNode_Detect);
    if (node24 == nullptr) {
        node24 = new PhaseNode_Detect(24, phase);
        node24->setSelf(0U);
        node24->setEvent("GetDamage");
        node24->setType(PhaseNode_Detect::Detect_Type::Damage);
        node24->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(21033, 24, node24)
    }
    if (noInit == true) {
        return node24;
    }
    return node24;
}

//--------------------------------------------------------------------------------
// SkillCreator_21033
//
class SkillCreator_21033 : public SkillCreator {
public:
    SkillCreator_21033() {}
    virtual ~SkillCreator_21033() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_21033

//--------------------------------------------------------------------------------
// SkillPhase_21033
//
class SkillPhase_21033 : public SkillPhase {
public:
    SkillPhase_21033(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_21033() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(21033, 5) // StartPhase
        CASE_CREATE_SKILL_NODE(21033, 7) // PlayAnimation
        CASE_CREATE_SKILL_NODE(21033, 10) // Delay
        CASE_CREATE_SKILL_NODE(21033, 12) // PlayAnimation
        CASE_CREATE_SKILL_NODE(21033, 14) // AddSkillBuff
        CASE_CREATE_SKILL_NODE(21033, 15) // PlayEffect
        CASE_CREATE_SKILL_NODE(21033, 17) // If
        CASE_CREATE_SKILL_NODE(21033, 19) // SetBool
        CASE_CREATE_SKILL_NODE(21033, 20) // Delay
        CASE_CREATE_SKILL_NODE(21033, 21) // SetBool
        CASE_CREATE_SKILL_NODE(21033, 22) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(21033, 23) // RaiseEvent
        CASE_CREATE_SKILL_NODE(21033, 24) // Detect
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_21033

SkillLogic* SkillCreator_21033::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //设置变量
    Variable_21033_EffectEnable = logic->getVariables().setVariable<bool>("EffectEnable", true);
    //创建阶段phase
    auto phase = new SkillPhase_21033(1, logic, 2);
    //设置phase执行器
    phase->setRunPhaseNode(1, 5);
    phase->setDetectPhaseNode(2, 24);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_21033::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
