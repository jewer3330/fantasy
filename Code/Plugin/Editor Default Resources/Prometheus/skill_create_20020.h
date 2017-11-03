#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

#include "skill_psnode_addskillbuff.h"
#include "skill_psnode_comparefloat.h"
#include "skill_psnode_compareint.h"
#include "skill_psnode_delay.h"
#include "skill_psnode_detect.h"
#include "skill_psnode_if.h"
#include "skill_psnode_intoperation.h"
#include "skill_psnode_playanimation.h"
#include "skill_psnode_playeffect.h"
#include "skill_psnode_raiseevent.h"
#include "skill_psnode_removeskillbuff.h"
#include "skill_psnode_setbool.h"
#include "skill_psnode_setint.h"
#include "skill_psnode_skillendnotify.h"
#include "skill_psnode_startphase.h"

namespace pvp {

//变量声明
uint64_t Variable_20020_Damage = 0;
uint64_t Variable_20020_EnableDmg = 0;
uint64_t Variable_20020_Effect = 0;
//--------------------------------------------------------------------------------
// StartPhase
//
REGISTER_REGISTER_SKILL_NODE(20020, 4) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_StartPhase::TRIGGER_START, 33, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(20020, 4) {
    auto node4 = GET_SKILL_NODE(4, PhaseNode_StartPhase);
    if (node4 == nullptr) {
        node4 = new PhaseNode_StartPhase(4, phase);
        CALL_REGISTER_SKILL_NODE(20020, 4, node4)
    }
    if (noInit == true) {
        return node4;
    }
    return node4;
}
//--------------------------------------------------------------------------------
// CompareInt
//
REGISTER_REGISTER_SKILL_NODE(20020, 6) {
    pnode->resizeTrigger(PhaseNode_CompareInt::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_CompareInt::TRIGGER_EQUAL, 7, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_CompareInt::TRIGGER_GREATER, 7, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(20020, 6) {
    auto node6 = GET_SKILL_NODE(6, PhaseNode_CompareInt);
    if (node6 == nullptr) {
        node6 = new PhaseNode_CompareInt(6, phase);
        node6->setB(12);
        CALL_REGISTER_SKILL_NODE(20020, 6, node6)
    }
    if (noInit == true) {
        return node6;
    }
    auto variables = node6->getVariables();
    if (variables != nullptr) {
        node6->setA(variables->getVariable<int32_t>(Variable_20020_Damage));
    }
    return node6;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(20020, 7) {
    pnode->resizeTrigger(PhaseNode_SetBool::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetInt>(PhaseNode_SetBool::TRIGGER_DONE, 8, PhaseNode_SetInt::FUNC_SET, &PhaseNode_SetInt::Set);
}

REGISTER_CREATE_SKILL_NODE(20020, 7) {
    auto node7 = GET_SKILL_NODE(7, PhaseNode_SetBool);
    if (node7 == nullptr) {
        node7 = new PhaseNode_SetBool(7, phase);
        node7->setName("EnableDmg");
        node7->setValue(false);
        CALL_REGISTER_SKILL_NODE(20020, 7, node7)
    }
    if (noInit == true) {
        return node7;
    }
    return node7;
}
//--------------------------------------------------------------------------------
// SetInt
//
REGISTER_REGISTER_SKILL_NODE(20020, 8) {
    pnode->resizeTrigger(PhaseNode_SetInt::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_SetInt::TRIGGER_DONE, 9, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(20020, 8) {
    auto node8 = GET_SKILL_NODE(8, PhaseNode_SetInt);
    if (node8 == nullptr) {
        node8 = new PhaseNode_SetInt(8, phase);
        node8->setName("Damage");
        node8->setValue(0);
        CALL_REGISTER_SKILL_NODE(20020, 8, node8)
    }
    if (noInit == true) {
        return node8;
    }
    return node8;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(20020, 9) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuff>(PhaseNode_PlayAnimation::TRIGGER_DONE, 23, PhaseNode_AddSkillBuff::FUNC_ADD, &PhaseNode_AddSkillBuff::Add);
}

REGISTER_CREATE_SKILL_NODE(20020, 9) {
    auto node9 = GET_SKILL_NODE(9, PhaseNode_PlayAnimation);
    if (node9 == nullptr) {
        node9 = new PhaseNode_PlayAnimation(9, phase);
        node9->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node9->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node9->setTarget(0U);
        node9->setAnimation("Hurt");
        node9->setParameter("");
        node9->setValue(false);
        CALL_REGISTER_SKILL_NODE(20020, 9, node9)
    }
    if (noInit == true) {
        return node9;
    }
    return node9;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(20020, 10) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlayEffect::TRIGGER_DONE, 25, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(20020, 10) {
    auto node10 = GET_SKILL_NODE(10, PhaseNode_PlayEffect);
    if (node10 == nullptr) {
        node10 = new PhaseNode_PlayEffect(10, phase);
        node10->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node10->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node10->setEffectID(0);
        node10->setChangeColor(false);
        node10->setType(PhaseNode_PlayEffect::PlayEffect_Type::WithTarget);
        node10->getVars().reserve(5);
        node10->getVars().setVariable<uint64_t>(0, 0U);
        node10->getVars().setVariable<std::string>(1, "");
        node10->getVars().setVariable<float>(2, .00f);
        node10->getVars().setVariable<float>(3, .00f);
        node10->getVars().setVariable<float>(4, .00f);
        node10->setRotation(.00f);
        node10->setScale(.00f);
        CALL_REGISTER_SKILL_NODE(20020, 10, node10)
    }
    if (noInit == true) {
        return node10;
    }
    return node10;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(20020, 11) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_Delay::TRIGGER_DONE, 12, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(20020, 11) {
    auto node11 = GET_SKILL_NODE(11, PhaseNode_Delay);
    if (node11 == nullptr) {
        node11 = new PhaseNode_Delay(11, phase);
        node11->setTime(.70f);
        CALL_REGISTER_SKILL_NODE(20020, 11, node11)
    }
    if (noInit == true) {
        return node11;
    }
    return node11;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(20020, 12) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RemoveSkillBuff>(PhaseNode_PlayAnimation::TRIGGER_DONE, 13, PhaseNode_RemoveSkillBuff::FUNC_REMOVE, &PhaseNode_RemoveSkillBuff::Remove);
}

REGISTER_CREATE_SKILL_NODE(20020, 12) {
    auto node12 = GET_SKILL_NODE(12, PhaseNode_PlayAnimation);
    if (node12 == nullptr) {
        node12 = new PhaseNode_PlayAnimation(12, phase);
        node12->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node12->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node12->setTarget(0U);
        node12->setAnimation("Idle");
        node12->setParameter("");
        node12->setValue(false);
        CALL_REGISTER_SKILL_NODE(20020, 12, node12)
    }
    if (noInit == true) {
        return node12;
    }
    return node12;
}
//--------------------------------------------------------------------------------
// RemoveSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(20020, 13) {
    pnode->resizeTrigger(PhaseNode_RemoveSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_RemoveSkillBuff::TRIGGER_DONE, 31, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(20020, 13) {
    auto node13 = GET_SKILL_NODE(13, PhaseNode_RemoveSkillBuff);
    if (node13 == nullptr) {
        node13 = new PhaseNode_RemoveSkillBuff(13, phase);
        node13->setBuffID(0U);
        node13->setBuffIDs({});
        node13->setConfigID(1);
        node13->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(20020, 13, node13)
    }
    if (noInit == true) {
        return node13;
    }
    return node13;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(20020, 14) {
}

REGISTER_CREATE_SKILL_NODE(20020, 14) {
    auto node14 = GET_SKILL_NODE(14, PhaseNode_SetBool);
    if (node14 == nullptr) {
        node14 = new PhaseNode_SetBool(14, phase);
        node14->setName("EnableDmg");
        node14->setValue(true);
        CALL_REGISTER_SKILL_NODE(20020, 14, node14)
    }
    if (noInit == true) {
        return node14;
    }
    return node14;
}
//--------------------------------------------------------------------------------
// IntOperation
//
REGISTER_REGISTER_SKILL_NODE(20020, 16) {
    pnode->resizeTrigger(PhaseNode_IntOperation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetInt>(PhaseNode_IntOperation::TRIGGER_DONE, 17, PhaseNode_SetInt::FUNC_SET, &PhaseNode_SetInt::Set);
}

REGISTER_CREATE_SKILL_NODE(20020, 16) {
    auto node16 = GET_SKILL_NODE(16, PhaseNode_IntOperation);
    if (node16 == nullptr) {
        node16 = new PhaseNode_IntOperation(16, phase);
        node16->setMethod(PhaseNode_IntOperation::IntOperation_Method::Add);
        CALL_REGISTER_SKILL_NODE(20020, 16, node16)
    }
    if (noInit == true) {
        return node16;
    }
    auto variables = node16->getVariables();
    if (variables != nullptr) {
        node16->setBase(variables->getVariable<int32_t>(Variable_20020_Damage));
    }
    auto node34 = GET_SKILL_NODE(34, PhaseNode_Detect);
    if (node34 != nullptr) node16->setValue(node34->getVars().getVariable<int32_t>(0));
    return node16;
}
//--------------------------------------------------------------------------------
// SetInt
//
REGISTER_REGISTER_SKILL_NODE(20020, 17) {
    pnode->resizeTrigger(PhaseNode_SetInt::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareInt>(PhaseNode_SetInt::TRIGGER_DONE, 6, PhaseNode_CompareInt::FUNC_COMPARE, &PhaseNode_CompareInt::Compare);
}

REGISTER_CREATE_SKILL_NODE(20020, 17) {
    auto node17 = GET_SKILL_NODE(17, PhaseNode_SetInt);
    if (node17 == nullptr) {
        node17 = new PhaseNode_SetInt(17, phase);
        node17->setName("Damage");
        CALL_REGISTER_SKILL_NODE(20020, 17, node17)
    }
    if (noInit == true) {
        return node17;
    }
    auto node16 = GET_SKILL_NODE(16, PhaseNode_IntOperation);
    if (node16 != nullptr) node17->setValue(node16->getFinal());
    return node17;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(20020, 19) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareInt>(PhaseNode_If::TRIGGER_TRUE, 24, PhaseNode_CompareInt::FUNC_COMPARE, &PhaseNode_CompareInt::Compare);
}

REGISTER_CREATE_SKILL_NODE(20020, 19) {
    auto node19 = GET_SKILL_NODE(19, PhaseNode_If);
    if (node19 == nullptr) {
        node19 = new PhaseNode_If(19, phase);
        CALL_REGISTER_SKILL_NODE(20020, 19, node19)
    }
    if (noInit == true) {
        return node19;
    }
    auto variables = node19->getVariables();
    if (variables != nullptr) {
        node19->setCondition(variables->getVariable<bool>(Variable_20020_EnableDmg));
    }
    return node19;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(20020, 20) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_Delay::TRIGGER_DONE, 14, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(20020, 20) {
    auto node20 = GET_SKILL_NODE(20, PhaseNode_Delay);
    if (node20 == nullptr) {
        node20 = new PhaseNode_Delay(20, phase);
        node20->setTime(1.00f);
        CALL_REGISTER_SKILL_NODE(20020, 20, node20)
    }
    if (noInit == true) {
        return node20;
    }
    return node20;
}
//--------------------------------------------------------------------------------
// AddSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(20020, 23) {
    pnode->resizeTrigger(PhaseNode_AddSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_AddSkillBuff::TRIGGER_DONE, 11, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(20020, 23) {
    auto node23 = GET_SKILL_NODE(23, PhaseNode_AddSkillBuff);
    if (node23 == nullptr) {
        node23 = new PhaseNode_AddSkillBuff(23, phase);
        node23->setConfigID(1);
        node23->setConfigIDs({});
        node23->setTarget(0U);
        node23->setAttribute({{}});
        CALL_REGISTER_SKILL_NODE(20020, 23, node23)
    }
    if (noInit == true) {
        return node23;
    }
    return node23;
}
//--------------------------------------------------------------------------------
// CompareInt
//
REGISTER_REGISTER_SKILL_NODE(20020, 24) {
    pnode->resizeTrigger(PhaseNode_CompareInt::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_IntOperation>(PhaseNode_CompareInt::TRIGGER_EQUAL, 16, PhaseNode_IntOperation::FUNC_OPERATION, &PhaseNode_IntOperation::Operation);
    pnode->regTrigger<PhaseNode_IntOperation>(PhaseNode_CompareInt::TRIGGER_GREATER, 16, PhaseNode_IntOperation::FUNC_OPERATION, &PhaseNode_IntOperation::Operation);
}

REGISTER_CREATE_SKILL_NODE(20020, 24) {
    auto node24 = GET_SKILL_NODE(24, PhaseNode_CompareInt);
    if (node24 == nullptr) {
        node24 = new PhaseNode_CompareInt(24, phase);
        node24->setB(8);
        CALL_REGISTER_SKILL_NODE(20020, 24, node24)
    }
    if (noInit == true) {
        return node24;
    }
    auto node34 = GET_SKILL_NODE(34, PhaseNode_Detect);
    if (node34 != nullptr) node24->setA(node34->getVars().getVariable<int32_t>(0));
    return node24;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(20020, 25) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_Delay::TRIGGER_DONE, 30, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(20020, 25) {
    auto node25 = GET_SKILL_NODE(25, PhaseNode_Delay);
    if (node25 == nullptr) {
        node25 = new PhaseNode_Delay(25, phase);
        node25->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(20020, 25, node25)
    }
    if (noInit == true) {
        return node25;
    }
    return node25;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(20020, 27) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_If::TRIGGER_TRUE, 29, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(20020, 27) {
    auto node27 = GET_SKILL_NODE(27, PhaseNode_If);
    if (node27 == nullptr) {
        node27 = new PhaseNode_If(27, phase);
        CALL_REGISTER_SKILL_NODE(20020, 27, node27)
    }
    if (noInit == true) {
        return node27;
    }
    auto variables = node27->getVariables();
    if (variables != nullptr) {
        node27->setCondition(variables->getVariable<bool>(Variable_20020_Effect));
    }
    return node27;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(20020, 29) {
    pnode->resizeTrigger(PhaseNode_SetBool::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_SetBool::TRIGGER_DONE, 10, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(20020, 29) {
    auto node29 = GET_SKILL_NODE(29, PhaseNode_SetBool);
    if (node29 == nullptr) {
        node29 = new PhaseNode_SetBool(29, phase);
        node29->setName("Effect");
        node29->setValue(false);
        CALL_REGISTER_SKILL_NODE(20020, 29, node29)
    }
    if (noInit == true) {
        return node29;
    }
    return node29;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(20020, 30) {
}

REGISTER_CREATE_SKILL_NODE(20020, 30) {
    auto node30 = GET_SKILL_NODE(30, PhaseNode_SetBool);
    if (node30 == nullptr) {
        node30 = new PhaseNode_SetBool(30, phase);
        node30->setName("Effect");
        node30->setValue(true);
        CALL_REGISTER_SKILL_NODE(20020, 30, node30)
    }
    if (noInit == true) {
        return node30;
    }
    return node30;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(20020, 31) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 14, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_GREATER, 20, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(20020, 31) {
    auto node31 = GET_SKILL_NODE(31, PhaseNode_CompareFloat);
    if (node31 == nullptr) {
        node31 = new PhaseNode_CompareFloat(31, phase);
        node31->setA(1.00f);
        node31->setB(.00f);
        CALL_REGISTER_SKILL_NODE(20020, 31, node31)
    }
    if (noInit == true) {
        return node31;
    }
    return node31;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(20020, 32) {
}

REGISTER_CREATE_SKILL_NODE(20020, 32) {
    auto node32 = GET_SKILL_NODE(32, PhaseNode_SkillEndNotify);
    if (node32 == nullptr) {
        node32 = new PhaseNode_SkillEndNotify(32, phase);
        node32->setReturnType(true);
        CALL_REGISTER_SKILL_NODE(20020, 32, node32)
    }
    if (noInit == true) {
        return node32;
    }
    return node32;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(20020, 33) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_RaiseEvent::TRIGGER_DONE, 32, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
}

REGISTER_CREATE_SKILL_NODE(20020, 33) {
    auto node33 = GET_SKILL_NODE(33, PhaseNode_RaiseEvent);
    if (node33 == nullptr) {
        node33 = new PhaseNode_RaiseEvent(33, phase);
        node33->setEvent("GetDamage");
        node33->setTarget(0U);
        node33->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node33->setTypeParams(0, 0);
        node33->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(20020, 33, node33)
    }
    if (noInit == true) {
        return node33;
    }
    return node33;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(20020, 34) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_Detect::TRIGGER_ON, 19, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_Detect::TRIGGER_ON, 27, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(20020, 34) {
    auto node34 = GET_SKILL_NODE(34, PhaseNode_Detect);
    if (node34 == nullptr) {
        node34 = new PhaseNode_Detect(34, phase);
        node34->setSelf(0U);
        node34->setEvent("GetDamage");
        node34->setType(PhaseNode_Detect::Detect_Type::Damage);
        node34->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(20020, 34, node34)
    }
    if (noInit == true) {
        return node34;
    }
    return node34;
}

//--------------------------------------------------------------------------------
// SkillCreator_20020
//
class SkillCreator_20020 : public SkillCreator {
public:
    SkillCreator_20020() {}
    virtual ~SkillCreator_20020() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_20020

//--------------------------------------------------------------------------------
// SkillPhase_20020
//
class SkillPhase_20020 : public SkillPhase {
public:
    SkillPhase_20020(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_20020() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(20020, 4) // StartPhase
        CASE_CREATE_SKILL_NODE(20020, 6) // CompareInt
        CASE_CREATE_SKILL_NODE(20020, 7) // SetBool
        CASE_CREATE_SKILL_NODE(20020, 8) // SetInt
        CASE_CREATE_SKILL_NODE(20020, 9) // PlayAnimation
        CASE_CREATE_SKILL_NODE(20020, 10) // PlayEffect
        CASE_CREATE_SKILL_NODE(20020, 11) // Delay
        CASE_CREATE_SKILL_NODE(20020, 12) // PlayAnimation
        CASE_CREATE_SKILL_NODE(20020, 13) // RemoveSkillBuff
        CASE_CREATE_SKILL_NODE(20020, 14) // SetBool
        CASE_CREATE_SKILL_NODE(20020, 16) // IntOperation
        CASE_CREATE_SKILL_NODE(20020, 17) // SetInt
        CASE_CREATE_SKILL_NODE(20020, 19) // If
        CASE_CREATE_SKILL_NODE(20020, 20) // Delay
        CASE_CREATE_SKILL_NODE(20020, 23) // AddSkillBuff
        CASE_CREATE_SKILL_NODE(20020, 24) // CompareInt
        CASE_CREATE_SKILL_NODE(20020, 25) // Delay
        CASE_CREATE_SKILL_NODE(20020, 27) // If
        CASE_CREATE_SKILL_NODE(20020, 29) // SetBool
        CASE_CREATE_SKILL_NODE(20020, 30) // SetBool
        CASE_CREATE_SKILL_NODE(20020, 31) // CompareFloat
        CASE_CREATE_SKILL_NODE(20020, 32) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(20020, 33) // RaiseEvent
        CASE_CREATE_SKILL_NODE(20020, 34) // Detect
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_20020

SkillLogic* SkillCreator_20020::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //设置变量
    Variable_20020_Damage = logic->getVariables().setVariable<int32_t>("Damage");
    Variable_20020_EnableDmg = logic->getVariables().setVariable<bool>("EnableDmg", true);
    Variable_20020_Effect = logic->getVariables().setVariable<bool>("Effect", true);
    //创建阶段phase
    auto phase = new SkillPhase_20020(1, logic, 2);
    //设置phase执行器
    phase->setRunPhaseNode(1, 4);
    phase->setDetectPhaseNode(2, 34);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_20020::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
