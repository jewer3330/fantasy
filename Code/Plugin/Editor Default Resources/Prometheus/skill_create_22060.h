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
uint64_t Variable_22060_Damage = 0;
uint64_t Variable_22060_EnableDmg = 0;
uint64_t Variable_22060_Effect = 0;
//--------------------------------------------------------------------------------
// StartPhase
//
REGISTER_REGISTER_SKILL_NODE(22060, 12) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_StartPhase::TRIGGER_START, 41, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(22060, 12) {
    auto node12 = GET_SKILL_NODE(12, PhaseNode_StartPhase);
    if (node12 == nullptr) {
        node12 = new PhaseNode_StartPhase(12, phase);
        CALL_REGISTER_SKILL_NODE(22060, 12, node12)
    }
    if (noInit == true) {
        return node12;
    }
    return node12;
}
//--------------------------------------------------------------------------------
// CompareInt
//
REGISTER_REGISTER_SKILL_NODE(22060, 14) {
    pnode->resizeTrigger(PhaseNode_CompareInt::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_CompareInt::TRIGGER_EQUAL, 15, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_CompareInt::TRIGGER_GREATER, 15, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(22060, 14) {
    auto node14 = GET_SKILL_NODE(14, PhaseNode_CompareInt);
    if (node14 == nullptr) {
        node14 = new PhaseNode_CompareInt(14, phase);
        node14->setB(120);
        CALL_REGISTER_SKILL_NODE(22060, 14, node14)
    }
    if (noInit == true) {
        return node14;
    }
    auto variables = node14->getVariables();
    if (variables != nullptr) {
        node14->setA(variables->getVariable<int32_t>(Variable_22060_Damage));
    }
    return node14;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(22060, 15) {
    pnode->resizeTrigger(PhaseNode_SetBool::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetInt>(PhaseNode_SetBool::TRIGGER_DONE, 16, PhaseNode_SetInt::FUNC_SET, &PhaseNode_SetInt::Set);
}

REGISTER_CREATE_SKILL_NODE(22060, 15) {
    auto node15 = GET_SKILL_NODE(15, PhaseNode_SetBool);
    if (node15 == nullptr) {
        node15 = new PhaseNode_SetBool(15, phase);
        node15->setName("EnableDmg");
        node15->setValue(false);
        CALL_REGISTER_SKILL_NODE(22060, 15, node15)
    }
    if (noInit == true) {
        return node15;
    }
    return node15;
}
//--------------------------------------------------------------------------------
// SetInt
//
REGISTER_REGISTER_SKILL_NODE(22060, 16) {
    pnode->resizeTrigger(PhaseNode_SetInt::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_SetInt::TRIGGER_DONE, 17, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(22060, 16) {
    auto node16 = GET_SKILL_NODE(16, PhaseNode_SetInt);
    if (node16 == nullptr) {
        node16 = new PhaseNode_SetInt(16, phase);
        node16->setName("Damage");
        node16->setValue(0);
        CALL_REGISTER_SKILL_NODE(22060, 16, node16)
    }
    if (noInit == true) {
        return node16;
    }
    return node16;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(22060, 17) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuff>(PhaseNode_PlayAnimation::TRIGGER_DONE, 31, PhaseNode_AddSkillBuff::FUNC_ADD, &PhaseNode_AddSkillBuff::Add);
}

REGISTER_CREATE_SKILL_NODE(22060, 17) {
    auto node17 = GET_SKILL_NODE(17, PhaseNode_PlayAnimation);
    if (node17 == nullptr) {
        node17 = new PhaseNode_PlayAnimation(17, phase);
        node17->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node17->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node17->setTarget(0U);
        node17->setAnimation("Hurt");
        node17->setParameter("");
        node17->setValue(false);
        CALL_REGISTER_SKILL_NODE(22060, 17, node17)
    }
    if (noInit == true) {
        return node17;
    }
    return node17;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(22060, 18) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlayEffect::TRIGGER_DONE, 33, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(22060, 18) {
    auto node18 = GET_SKILL_NODE(18, PhaseNode_PlayEffect);
    if (node18 == nullptr) {
        node18 = new PhaseNode_PlayEffect(18, phase);
        node18->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node18->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node18->setEffectID(0);
        node18->setChangeColor(false);
        node18->setType(PhaseNode_PlayEffect::PlayEffect_Type::WithTarget);
        node18->getVars().reserve(5);
        node18->getVars().setVariable<uint64_t>(0, 0U);
        node18->getVars().setVariable<std::string>(1, "");
        node18->getVars().setVariable<float>(2, .00f);
        node18->getVars().setVariable<float>(3, .00f);
        node18->getVars().setVariable<float>(4, .00f);
        node18->setRotation(.00f);
        node18->setScale(.00f);
        CALL_REGISTER_SKILL_NODE(22060, 18, node18)
    }
    if (noInit == true) {
        return node18;
    }
    return node18;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22060, 19) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_Delay::TRIGGER_DONE, 20, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(22060, 19) {
    auto node19 = GET_SKILL_NODE(19, PhaseNode_Delay);
    if (node19 == nullptr) {
        node19 = new PhaseNode_Delay(19, phase);
        node19->setTime(.67f);
        CALL_REGISTER_SKILL_NODE(22060, 19, node19)
    }
    if (noInit == true) {
        return node19;
    }
    return node19;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(22060, 20) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RemoveSkillBuff>(PhaseNode_PlayAnimation::TRIGGER_DONE, 21, PhaseNode_RemoveSkillBuff::FUNC_REMOVE, &PhaseNode_RemoveSkillBuff::Remove);
}

REGISTER_CREATE_SKILL_NODE(22060, 20) {
    auto node20 = GET_SKILL_NODE(20, PhaseNode_PlayAnimation);
    if (node20 == nullptr) {
        node20 = new PhaseNode_PlayAnimation(20, phase);
        node20->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node20->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node20->setTarget(0U);
        node20->setAnimation("Idle");
        node20->setParameter("");
        node20->setValue(false);
        CALL_REGISTER_SKILL_NODE(22060, 20, node20)
    }
    if (noInit == true) {
        return node20;
    }
    return node20;
}
//--------------------------------------------------------------------------------
// RemoveSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(22060, 21) {
    pnode->resizeTrigger(PhaseNode_RemoveSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_RemoveSkillBuff::TRIGGER_DONE, 39, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(22060, 21) {
    auto node21 = GET_SKILL_NODE(21, PhaseNode_RemoveSkillBuff);
    if (node21 == nullptr) {
        node21 = new PhaseNode_RemoveSkillBuff(21, phase);
        node21->setBuffID(0U);
        node21->setBuffIDs({});
        node21->setConfigID(1);
        node21->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(22060, 21, node21)
    }
    if (noInit == true) {
        return node21;
    }
    return node21;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(22060, 22) {
}

REGISTER_CREATE_SKILL_NODE(22060, 22) {
    auto node22 = GET_SKILL_NODE(22, PhaseNode_SetBool);
    if (node22 == nullptr) {
        node22 = new PhaseNode_SetBool(22, phase);
        node22->setName("EnableDmg");
        node22->setValue(true);
        CALL_REGISTER_SKILL_NODE(22060, 22, node22)
    }
    if (noInit == true) {
        return node22;
    }
    return node22;
}
//--------------------------------------------------------------------------------
// IntOperation
//
REGISTER_REGISTER_SKILL_NODE(22060, 24) {
    pnode->resizeTrigger(PhaseNode_IntOperation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetInt>(PhaseNode_IntOperation::TRIGGER_DONE, 25, PhaseNode_SetInt::FUNC_SET, &PhaseNode_SetInt::Set);
}

REGISTER_CREATE_SKILL_NODE(22060, 24) {
    auto node24 = GET_SKILL_NODE(24, PhaseNode_IntOperation);
    if (node24 == nullptr) {
        node24 = new PhaseNode_IntOperation(24, phase);
        node24->setMethod(PhaseNode_IntOperation::IntOperation_Method::Add);
        CALL_REGISTER_SKILL_NODE(22060, 24, node24)
    }
    if (noInit == true) {
        return node24;
    }
    auto variables = node24->getVariables();
    if (variables != nullptr) {
        node24->setBase(variables->getVariable<int32_t>(Variable_22060_Damage));
    }
    auto node42 = GET_SKILL_NODE(42, PhaseNode_Detect);
    if (node42 != nullptr) node24->setValue(node42->getVars().getVariable<int32_t>(0));
    return node24;
}
//--------------------------------------------------------------------------------
// SetInt
//
REGISTER_REGISTER_SKILL_NODE(22060, 25) {
    pnode->resizeTrigger(PhaseNode_SetInt::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareInt>(PhaseNode_SetInt::TRIGGER_DONE, 14, PhaseNode_CompareInt::FUNC_COMPARE, &PhaseNode_CompareInt::Compare);
}

REGISTER_CREATE_SKILL_NODE(22060, 25) {
    auto node25 = GET_SKILL_NODE(25, PhaseNode_SetInt);
    if (node25 == nullptr) {
        node25 = new PhaseNode_SetInt(25, phase);
        node25->setName("Damage");
        CALL_REGISTER_SKILL_NODE(22060, 25, node25)
    }
    if (noInit == true) {
        return node25;
    }
    auto node24 = GET_SKILL_NODE(24, PhaseNode_IntOperation);
    if (node24 != nullptr) node25->setValue(node24->getFinal());
    return node25;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(22060, 27) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareInt>(PhaseNode_If::TRIGGER_TRUE, 32, PhaseNode_CompareInt::FUNC_COMPARE, &PhaseNode_CompareInt::Compare);
}

REGISTER_CREATE_SKILL_NODE(22060, 27) {
    auto node27 = GET_SKILL_NODE(27, PhaseNode_If);
    if (node27 == nullptr) {
        node27 = new PhaseNode_If(27, phase);
        CALL_REGISTER_SKILL_NODE(22060, 27, node27)
    }
    if (noInit == true) {
        return node27;
    }
    auto variables = node27->getVariables();
    if (variables != nullptr) {
        node27->setCondition(variables->getVariable<bool>(Variable_22060_EnableDmg));
    }
    return node27;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22060, 28) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_Delay::TRIGGER_DONE, 22, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(22060, 28) {
    auto node28 = GET_SKILL_NODE(28, PhaseNode_Delay);
    if (node28 == nullptr) {
        node28 = new PhaseNode_Delay(28, phase);
        node28->setTime(1.00f);
        CALL_REGISTER_SKILL_NODE(22060, 28, node28)
    }
    if (noInit == true) {
        return node28;
    }
    return node28;
}
//--------------------------------------------------------------------------------
// AddSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(22060, 31) {
    pnode->resizeTrigger(PhaseNode_AddSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_AddSkillBuff::TRIGGER_DONE, 19, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(22060, 31) {
    auto node31 = GET_SKILL_NODE(31, PhaseNode_AddSkillBuff);
    if (node31 == nullptr) {
        node31 = new PhaseNode_AddSkillBuff(31, phase);
        node31->setConfigID(1);
        node31->setConfigIDs({});
        node31->setTarget(0U);
        node31->setAttribute({{}});
        CALL_REGISTER_SKILL_NODE(22060, 31, node31)
    }
    if (noInit == true) {
        return node31;
    }
    return node31;
}
//--------------------------------------------------------------------------------
// CompareInt
//
REGISTER_REGISTER_SKILL_NODE(22060, 32) {
    pnode->resizeTrigger(PhaseNode_CompareInt::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_IntOperation>(PhaseNode_CompareInt::TRIGGER_EQUAL, 24, PhaseNode_IntOperation::FUNC_OPERATION, &PhaseNode_IntOperation::Operation);
    pnode->regTrigger<PhaseNode_IntOperation>(PhaseNode_CompareInt::TRIGGER_GREATER, 24, PhaseNode_IntOperation::FUNC_OPERATION, &PhaseNode_IntOperation::Operation);
}

REGISTER_CREATE_SKILL_NODE(22060, 32) {
    auto node32 = GET_SKILL_NODE(32, PhaseNode_CompareInt);
    if (node32 == nullptr) {
        node32 = new PhaseNode_CompareInt(32, phase);
        node32->setB(20);
        CALL_REGISTER_SKILL_NODE(22060, 32, node32)
    }
    if (noInit == true) {
        return node32;
    }
    auto node42 = GET_SKILL_NODE(42, PhaseNode_Detect);
    if (node42 != nullptr) node32->setA(node42->getVars().getVariable<int32_t>(0));
    return node32;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22060, 33) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_Delay::TRIGGER_DONE, 38, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(22060, 33) {
    auto node33 = GET_SKILL_NODE(33, PhaseNode_Delay);
    if (node33 == nullptr) {
        node33 = new PhaseNode_Delay(33, phase);
        node33->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(22060, 33, node33)
    }
    if (noInit == true) {
        return node33;
    }
    return node33;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(22060, 35) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_If::TRIGGER_TRUE, 37, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(22060, 35) {
    auto node35 = GET_SKILL_NODE(35, PhaseNode_If);
    if (node35 == nullptr) {
        node35 = new PhaseNode_If(35, phase);
        CALL_REGISTER_SKILL_NODE(22060, 35, node35)
    }
    if (noInit == true) {
        return node35;
    }
    auto variables = node35->getVariables();
    if (variables != nullptr) {
        node35->setCondition(variables->getVariable<bool>(Variable_22060_Effect));
    }
    return node35;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(22060, 37) {
    pnode->resizeTrigger(PhaseNode_SetBool::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_SetBool::TRIGGER_DONE, 18, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(22060, 37) {
    auto node37 = GET_SKILL_NODE(37, PhaseNode_SetBool);
    if (node37 == nullptr) {
        node37 = new PhaseNode_SetBool(37, phase);
        node37->setName("Effect");
        node37->setValue(false);
        CALL_REGISTER_SKILL_NODE(22060, 37, node37)
    }
    if (noInit == true) {
        return node37;
    }
    return node37;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(22060, 38) {
}

REGISTER_CREATE_SKILL_NODE(22060, 38) {
    auto node38 = GET_SKILL_NODE(38, PhaseNode_SetBool);
    if (node38 == nullptr) {
        node38 = new PhaseNode_SetBool(38, phase);
        node38->setName("Effect");
        node38->setValue(true);
        CALL_REGISTER_SKILL_NODE(22060, 38, node38)
    }
    if (noInit == true) {
        return node38;
    }
    return node38;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(22060, 39) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 22, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_GREATER, 28, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(22060, 39) {
    auto node39 = GET_SKILL_NODE(39, PhaseNode_CompareFloat);
    if (node39 == nullptr) {
        node39 = new PhaseNode_CompareFloat(39, phase);
        node39->setA(1.00f);
        node39->setB(.00f);
        CALL_REGISTER_SKILL_NODE(22060, 39, node39)
    }
    if (noInit == true) {
        return node39;
    }
    return node39;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(22060, 40) {
}

REGISTER_CREATE_SKILL_NODE(22060, 40) {
    auto node40 = GET_SKILL_NODE(40, PhaseNode_SkillEndNotify);
    if (node40 == nullptr) {
        node40 = new PhaseNode_SkillEndNotify(40, phase);
        node40->setReturnType(true);
        CALL_REGISTER_SKILL_NODE(22060, 40, node40)
    }
    if (noInit == true) {
        return node40;
    }
    return node40;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(22060, 41) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_RaiseEvent::TRIGGER_DONE, 40, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
}

REGISTER_CREATE_SKILL_NODE(22060, 41) {
    auto node41 = GET_SKILL_NODE(41, PhaseNode_RaiseEvent);
    if (node41 == nullptr) {
        node41 = new PhaseNode_RaiseEvent(41, phase);
        node41->setEvent("GetDamage");
        node41->setTarget(0U);
        node41->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node41->setTypeParams(0, 0);
        node41->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(22060, 41, node41)
    }
    if (noInit == true) {
        return node41;
    }
    return node41;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(22060, 42) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_Detect::TRIGGER_ON, 27, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_Detect::TRIGGER_ON, 35, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(22060, 42) {
    auto node42 = GET_SKILL_NODE(42, PhaseNode_Detect);
    if (node42 == nullptr) {
        node42 = new PhaseNode_Detect(42, phase);
        node42->setSelf(0U);
        node42->setEvent("GetDamage");
        node42->setType(PhaseNode_Detect::Detect_Type::Damage);
        node42->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(22060, 42, node42)
    }
    if (noInit == true) {
        return node42;
    }
    return node42;
}

//--------------------------------------------------------------------------------
// SkillCreator_22060
//
class SkillCreator_22060 : public SkillCreator {
public:
    SkillCreator_22060() {}
    virtual ~SkillCreator_22060() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_22060

//--------------------------------------------------------------------------------
// SkillPhase_22060
//
class SkillPhase_22060 : public SkillPhase {
public:
    SkillPhase_22060(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_22060() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(22060, 12) // StartPhase
        CASE_CREATE_SKILL_NODE(22060, 14) // CompareInt
        CASE_CREATE_SKILL_NODE(22060, 15) // SetBool
        CASE_CREATE_SKILL_NODE(22060, 16) // SetInt
        CASE_CREATE_SKILL_NODE(22060, 17) // PlayAnimation
        CASE_CREATE_SKILL_NODE(22060, 18) // PlayEffect
        CASE_CREATE_SKILL_NODE(22060, 19) // Delay
        CASE_CREATE_SKILL_NODE(22060, 20) // PlayAnimation
        CASE_CREATE_SKILL_NODE(22060, 21) // RemoveSkillBuff
        CASE_CREATE_SKILL_NODE(22060, 22) // SetBool
        CASE_CREATE_SKILL_NODE(22060, 24) // IntOperation
        CASE_CREATE_SKILL_NODE(22060, 25) // SetInt
        CASE_CREATE_SKILL_NODE(22060, 27) // If
        CASE_CREATE_SKILL_NODE(22060, 28) // Delay
        CASE_CREATE_SKILL_NODE(22060, 31) // AddSkillBuff
        CASE_CREATE_SKILL_NODE(22060, 32) // CompareInt
        CASE_CREATE_SKILL_NODE(22060, 33) // Delay
        CASE_CREATE_SKILL_NODE(22060, 35) // If
        CASE_CREATE_SKILL_NODE(22060, 37) // SetBool
        CASE_CREATE_SKILL_NODE(22060, 38) // SetBool
        CASE_CREATE_SKILL_NODE(22060, 39) // CompareFloat
        CASE_CREATE_SKILL_NODE(22060, 40) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(22060, 41) // RaiseEvent
        CASE_CREATE_SKILL_NODE(22060, 42) // Detect
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_22060

SkillLogic* SkillCreator_22060::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //设置变量
    Variable_22060_Damage = logic->getVariables().setVariable<int32_t>("Damage");
    Variable_22060_EnableDmg = logic->getVariables().setVariable<bool>("EnableDmg", true);
    Variable_22060_Effect = logic->getVariables().setVariable<bool>("Effect", true);
    //创建阶段phase
    auto phase = new SkillPhase_22060(1, logic, 2);
    //设置phase执行器
    phase->setRunPhaseNode(1, 12);
    phase->setDetectPhaseNode(2, 42);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_22060::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
