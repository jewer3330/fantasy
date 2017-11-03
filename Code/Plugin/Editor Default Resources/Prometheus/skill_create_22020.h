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
uint64_t Variable_22020_Damage = 0;
uint64_t Variable_22020_EnableDmg = 0;
uint64_t Variable_22020_Effect = 0;
//--------------------------------------------------------------------------------
// StartPhase
//
REGISTER_REGISTER_SKILL_NODE(22020, 25) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_StartPhase::TRIGGER_START, 54, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(22020, 25) {
    auto node25 = GET_SKILL_NODE(25, PhaseNode_StartPhase);
    if (node25 == nullptr) {
        node25 = new PhaseNode_StartPhase(25, phase);
        CALL_REGISTER_SKILL_NODE(22020, 25, node25)
    }
    if (noInit == true) {
        return node25;
    }
    return node25;
}
//--------------------------------------------------------------------------------
// CompareInt
//
REGISTER_REGISTER_SKILL_NODE(22020, 27) {
    pnode->resizeTrigger(PhaseNode_CompareInt::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_CompareInt::TRIGGER_EQUAL, 28, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_CompareInt::TRIGGER_GREATER, 28, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(22020, 27) {
    auto node27 = GET_SKILL_NODE(27, PhaseNode_CompareInt);
    if (node27 == nullptr) {
        node27 = new PhaseNode_CompareInt(27, phase);
        node27->setB(60);
        CALL_REGISTER_SKILL_NODE(22020, 27, node27)
    }
    if (noInit == true) {
        return node27;
    }
    auto variables = node27->getVariables();
    if (variables != nullptr) {
        node27->setA(variables->getVariable<int32_t>(Variable_22020_Damage));
    }
    return node27;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(22020, 28) {
    pnode->resizeTrigger(PhaseNode_SetBool::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetInt>(PhaseNode_SetBool::TRIGGER_DONE, 29, PhaseNode_SetInt::FUNC_SET, &PhaseNode_SetInt::Set);
}

REGISTER_CREATE_SKILL_NODE(22020, 28) {
    auto node28 = GET_SKILL_NODE(28, PhaseNode_SetBool);
    if (node28 == nullptr) {
        node28 = new PhaseNode_SetBool(28, phase);
        node28->setName("EnableDmg");
        node28->setValue(false);
        CALL_REGISTER_SKILL_NODE(22020, 28, node28)
    }
    if (noInit == true) {
        return node28;
    }
    return node28;
}
//--------------------------------------------------------------------------------
// SetInt
//
REGISTER_REGISTER_SKILL_NODE(22020, 29) {
    pnode->resizeTrigger(PhaseNode_SetInt::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_SetInt::TRIGGER_DONE, 30, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(22020, 29) {
    auto node29 = GET_SKILL_NODE(29, PhaseNode_SetInt);
    if (node29 == nullptr) {
        node29 = new PhaseNode_SetInt(29, phase);
        node29->setName("Damage");
        node29->setValue(0);
        CALL_REGISTER_SKILL_NODE(22020, 29, node29)
    }
    if (noInit == true) {
        return node29;
    }
    return node29;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(22020, 30) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuff>(PhaseNode_PlayAnimation::TRIGGER_DONE, 44, PhaseNode_AddSkillBuff::FUNC_ADD, &PhaseNode_AddSkillBuff::Add);
}

REGISTER_CREATE_SKILL_NODE(22020, 30) {
    auto node30 = GET_SKILL_NODE(30, PhaseNode_PlayAnimation);
    if (node30 == nullptr) {
        node30 = new PhaseNode_PlayAnimation(30, phase);
        node30->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node30->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node30->setTarget(0U);
        node30->setAnimation("Hurt");
        node30->setParameter("");
        node30->setValue(false);
        CALL_REGISTER_SKILL_NODE(22020, 30, node30)
    }
    if (noInit == true) {
        return node30;
    }
    return node30;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(22020, 31) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlayEffect::TRIGGER_DONE, 46, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(22020, 31) {
    auto node31 = GET_SKILL_NODE(31, PhaseNode_PlayEffect);
    if (node31 == nullptr) {
        node31 = new PhaseNode_PlayEffect(31, phase);
        node31->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node31->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node31->setEffectID(0);
        node31->setChangeColor(false);
        node31->setType(PhaseNode_PlayEffect::PlayEffect_Type::WithTarget);
        node31->getVars().reserve(5);
        node31->getVars().setVariable<uint64_t>(0, 0U);
        node31->getVars().setVariable<std::string>(1, "");
        node31->getVars().setVariable<float>(2, .00f);
        node31->getVars().setVariable<float>(3, .00f);
        node31->getVars().setVariable<float>(4, .00f);
        node31->setRotation(.00f);
        node31->setScale(.00f);
        CALL_REGISTER_SKILL_NODE(22020, 31, node31)
    }
    if (noInit == true) {
        return node31;
    }
    return node31;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22020, 32) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_Delay::TRIGGER_DONE, 33, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(22020, 32) {
    auto node32 = GET_SKILL_NODE(32, PhaseNode_Delay);
    if (node32 == nullptr) {
        node32 = new PhaseNode_Delay(32, phase);
        node32->setTime(.67f);
        CALL_REGISTER_SKILL_NODE(22020, 32, node32)
    }
    if (noInit == true) {
        return node32;
    }
    return node32;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(22020, 33) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RemoveSkillBuff>(PhaseNode_PlayAnimation::TRIGGER_DONE, 34, PhaseNode_RemoveSkillBuff::FUNC_REMOVE, &PhaseNode_RemoveSkillBuff::Remove);
}

REGISTER_CREATE_SKILL_NODE(22020, 33) {
    auto node33 = GET_SKILL_NODE(33, PhaseNode_PlayAnimation);
    if (node33 == nullptr) {
        node33 = new PhaseNode_PlayAnimation(33, phase);
        node33->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node33->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node33->setTarget(0U);
        node33->setAnimation("Idle");
        node33->setParameter("");
        node33->setValue(false);
        CALL_REGISTER_SKILL_NODE(22020, 33, node33)
    }
    if (noInit == true) {
        return node33;
    }
    return node33;
}
//--------------------------------------------------------------------------------
// RemoveSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(22020, 34) {
    pnode->resizeTrigger(PhaseNode_RemoveSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_RemoveSkillBuff::TRIGGER_DONE, 52, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(22020, 34) {
    auto node34 = GET_SKILL_NODE(34, PhaseNode_RemoveSkillBuff);
    if (node34 == nullptr) {
        node34 = new PhaseNode_RemoveSkillBuff(34, phase);
        node34->setBuffID(0U);
        node34->setBuffIDs({});
        node34->setConfigID(1);
        node34->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(22020, 34, node34)
    }
    if (noInit == true) {
        return node34;
    }
    return node34;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(22020, 35) {
}

REGISTER_CREATE_SKILL_NODE(22020, 35) {
    auto node35 = GET_SKILL_NODE(35, PhaseNode_SetBool);
    if (node35 == nullptr) {
        node35 = new PhaseNode_SetBool(35, phase);
        node35->setName("EnableDmg");
        node35->setValue(true);
        CALL_REGISTER_SKILL_NODE(22020, 35, node35)
    }
    if (noInit == true) {
        return node35;
    }
    return node35;
}
//--------------------------------------------------------------------------------
// IntOperation
//
REGISTER_REGISTER_SKILL_NODE(22020, 37) {
    pnode->resizeTrigger(PhaseNode_IntOperation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetInt>(PhaseNode_IntOperation::TRIGGER_DONE, 38, PhaseNode_SetInt::FUNC_SET, &PhaseNode_SetInt::Set);
}

REGISTER_CREATE_SKILL_NODE(22020, 37) {
    auto node37 = GET_SKILL_NODE(37, PhaseNode_IntOperation);
    if (node37 == nullptr) {
        node37 = new PhaseNode_IntOperation(37, phase);
        node37->setMethod(PhaseNode_IntOperation::IntOperation_Method::Add);
        CALL_REGISTER_SKILL_NODE(22020, 37, node37)
    }
    if (noInit == true) {
        return node37;
    }
    auto variables = node37->getVariables();
    if (variables != nullptr) {
        node37->setBase(variables->getVariable<int32_t>(Variable_22020_Damage));
    }
    auto node55 = GET_SKILL_NODE(55, PhaseNode_Detect);
    if (node55 != nullptr) node37->setValue(node55->getVars().getVariable<int32_t>(0));
    return node37;
}
//--------------------------------------------------------------------------------
// SetInt
//
REGISTER_REGISTER_SKILL_NODE(22020, 38) {
    pnode->resizeTrigger(PhaseNode_SetInt::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareInt>(PhaseNode_SetInt::TRIGGER_DONE, 27, PhaseNode_CompareInt::FUNC_COMPARE, &PhaseNode_CompareInt::Compare);
}

REGISTER_CREATE_SKILL_NODE(22020, 38) {
    auto node38 = GET_SKILL_NODE(38, PhaseNode_SetInt);
    if (node38 == nullptr) {
        node38 = new PhaseNode_SetInt(38, phase);
        node38->setName("Damage");
        CALL_REGISTER_SKILL_NODE(22020, 38, node38)
    }
    if (noInit == true) {
        return node38;
    }
    auto node37 = GET_SKILL_NODE(37, PhaseNode_IntOperation);
    if (node37 != nullptr) node38->setValue(node37->getFinal());
    return node38;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(22020, 40) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareInt>(PhaseNode_If::TRIGGER_TRUE, 45, PhaseNode_CompareInt::FUNC_COMPARE, &PhaseNode_CompareInt::Compare);
}

REGISTER_CREATE_SKILL_NODE(22020, 40) {
    auto node40 = GET_SKILL_NODE(40, PhaseNode_If);
    if (node40 == nullptr) {
        node40 = new PhaseNode_If(40, phase);
        CALL_REGISTER_SKILL_NODE(22020, 40, node40)
    }
    if (noInit == true) {
        return node40;
    }
    auto variables = node40->getVariables();
    if (variables != nullptr) {
        node40->setCondition(variables->getVariable<bool>(Variable_22020_EnableDmg));
    }
    return node40;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22020, 41) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_Delay::TRIGGER_DONE, 35, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(22020, 41) {
    auto node41 = GET_SKILL_NODE(41, PhaseNode_Delay);
    if (node41 == nullptr) {
        node41 = new PhaseNode_Delay(41, phase);
        node41->setTime(1.00f);
        CALL_REGISTER_SKILL_NODE(22020, 41, node41)
    }
    if (noInit == true) {
        return node41;
    }
    return node41;
}
//--------------------------------------------------------------------------------
// AddSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(22020, 44) {
    pnode->resizeTrigger(PhaseNode_AddSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_AddSkillBuff::TRIGGER_DONE, 32, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(22020, 44) {
    auto node44 = GET_SKILL_NODE(44, PhaseNode_AddSkillBuff);
    if (node44 == nullptr) {
        node44 = new PhaseNode_AddSkillBuff(44, phase);
        node44->setConfigID(1);
        node44->setConfigIDs({});
        node44->setTarget(0U);
        node44->setAttribute({{}});
        CALL_REGISTER_SKILL_NODE(22020, 44, node44)
    }
    if (noInit == true) {
        return node44;
    }
    return node44;
}
//--------------------------------------------------------------------------------
// CompareInt
//
REGISTER_REGISTER_SKILL_NODE(22020, 45) {
    pnode->resizeTrigger(PhaseNode_CompareInt::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_IntOperation>(PhaseNode_CompareInt::TRIGGER_EQUAL, 37, PhaseNode_IntOperation::FUNC_OPERATION, &PhaseNode_IntOperation::Operation);
    pnode->regTrigger<PhaseNode_IntOperation>(PhaseNode_CompareInt::TRIGGER_GREATER, 37, PhaseNode_IntOperation::FUNC_OPERATION, &PhaseNode_IntOperation::Operation);
}

REGISTER_CREATE_SKILL_NODE(22020, 45) {
    auto node45 = GET_SKILL_NODE(45, PhaseNode_CompareInt);
    if (node45 == nullptr) {
        node45 = new PhaseNode_CompareInt(45, phase);
        node45->setB(10);
        CALL_REGISTER_SKILL_NODE(22020, 45, node45)
    }
    if (noInit == true) {
        return node45;
    }
    auto node55 = GET_SKILL_NODE(55, PhaseNode_Detect);
    if (node55 != nullptr) node45->setA(node55->getVars().getVariable<int32_t>(0));
    return node45;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22020, 46) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_Delay::TRIGGER_DONE, 51, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(22020, 46) {
    auto node46 = GET_SKILL_NODE(46, PhaseNode_Delay);
    if (node46 == nullptr) {
        node46 = new PhaseNode_Delay(46, phase);
        node46->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(22020, 46, node46)
    }
    if (noInit == true) {
        return node46;
    }
    return node46;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(22020, 48) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_If::TRIGGER_TRUE, 50, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(22020, 48) {
    auto node48 = GET_SKILL_NODE(48, PhaseNode_If);
    if (node48 == nullptr) {
        node48 = new PhaseNode_If(48, phase);
        CALL_REGISTER_SKILL_NODE(22020, 48, node48)
    }
    if (noInit == true) {
        return node48;
    }
    auto variables = node48->getVariables();
    if (variables != nullptr) {
        node48->setCondition(variables->getVariable<bool>(Variable_22020_Effect));
    }
    return node48;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(22020, 50) {
    pnode->resizeTrigger(PhaseNode_SetBool::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_SetBool::TRIGGER_DONE, 31, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(22020, 50) {
    auto node50 = GET_SKILL_NODE(50, PhaseNode_SetBool);
    if (node50 == nullptr) {
        node50 = new PhaseNode_SetBool(50, phase);
        node50->setName("Effect");
        node50->setValue(false);
        CALL_REGISTER_SKILL_NODE(22020, 50, node50)
    }
    if (noInit == true) {
        return node50;
    }
    return node50;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(22020, 51) {
}

REGISTER_CREATE_SKILL_NODE(22020, 51) {
    auto node51 = GET_SKILL_NODE(51, PhaseNode_SetBool);
    if (node51 == nullptr) {
        node51 = new PhaseNode_SetBool(51, phase);
        node51->setName("Effect");
        node51->setValue(true);
        CALL_REGISTER_SKILL_NODE(22020, 51, node51)
    }
    if (noInit == true) {
        return node51;
    }
    return node51;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(22020, 52) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 35, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_GREATER, 41, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(22020, 52) {
    auto node52 = GET_SKILL_NODE(52, PhaseNode_CompareFloat);
    if (node52 == nullptr) {
        node52 = new PhaseNode_CompareFloat(52, phase);
        node52->setA(1.00f);
        node52->setB(.00f);
        CALL_REGISTER_SKILL_NODE(22020, 52, node52)
    }
    if (noInit == true) {
        return node52;
    }
    return node52;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(22020, 53) {
}

REGISTER_CREATE_SKILL_NODE(22020, 53) {
    auto node53 = GET_SKILL_NODE(53, PhaseNode_SkillEndNotify);
    if (node53 == nullptr) {
        node53 = new PhaseNode_SkillEndNotify(53, phase);
        node53->setReturnType(true);
        CALL_REGISTER_SKILL_NODE(22020, 53, node53)
    }
    if (noInit == true) {
        return node53;
    }
    return node53;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(22020, 54) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_RaiseEvent::TRIGGER_DONE, 53, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
}

REGISTER_CREATE_SKILL_NODE(22020, 54) {
    auto node54 = GET_SKILL_NODE(54, PhaseNode_RaiseEvent);
    if (node54 == nullptr) {
        node54 = new PhaseNode_RaiseEvent(54, phase);
        node54->setEvent("GetDamage");
        node54->setTarget(0U);
        node54->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node54->setTypeParams(0, 0);
        node54->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(22020, 54, node54)
    }
    if (noInit == true) {
        return node54;
    }
    return node54;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(22020, 55) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_Detect::TRIGGER_ON, 40, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_Detect::TRIGGER_ON, 48, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(22020, 55) {
    auto node55 = GET_SKILL_NODE(55, PhaseNode_Detect);
    if (node55 == nullptr) {
        node55 = new PhaseNode_Detect(55, phase);
        node55->setSelf(0U);
        node55->setEvent("GetDamage");
        node55->setType(PhaseNode_Detect::Detect_Type::Damage);
        node55->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(22020, 55, node55)
    }
    if (noInit == true) {
        return node55;
    }
    return node55;
}

//--------------------------------------------------------------------------------
// SkillCreator_22020
//
class SkillCreator_22020 : public SkillCreator {
public:
    SkillCreator_22020() {}
    virtual ~SkillCreator_22020() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_22020

//--------------------------------------------------------------------------------
// SkillPhase_22020
//
class SkillPhase_22020 : public SkillPhase {
public:
    SkillPhase_22020(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_22020() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(22020, 25) // StartPhase
        CASE_CREATE_SKILL_NODE(22020, 27) // CompareInt
        CASE_CREATE_SKILL_NODE(22020, 28) // SetBool
        CASE_CREATE_SKILL_NODE(22020, 29) // SetInt
        CASE_CREATE_SKILL_NODE(22020, 30) // PlayAnimation
        CASE_CREATE_SKILL_NODE(22020, 31) // PlayEffect
        CASE_CREATE_SKILL_NODE(22020, 32) // Delay
        CASE_CREATE_SKILL_NODE(22020, 33) // PlayAnimation
        CASE_CREATE_SKILL_NODE(22020, 34) // RemoveSkillBuff
        CASE_CREATE_SKILL_NODE(22020, 35) // SetBool
        CASE_CREATE_SKILL_NODE(22020, 37) // IntOperation
        CASE_CREATE_SKILL_NODE(22020, 38) // SetInt
        CASE_CREATE_SKILL_NODE(22020, 40) // If
        CASE_CREATE_SKILL_NODE(22020, 41) // Delay
        CASE_CREATE_SKILL_NODE(22020, 44) // AddSkillBuff
        CASE_CREATE_SKILL_NODE(22020, 45) // CompareInt
        CASE_CREATE_SKILL_NODE(22020, 46) // Delay
        CASE_CREATE_SKILL_NODE(22020, 48) // If
        CASE_CREATE_SKILL_NODE(22020, 50) // SetBool
        CASE_CREATE_SKILL_NODE(22020, 51) // SetBool
        CASE_CREATE_SKILL_NODE(22020, 52) // CompareFloat
        CASE_CREATE_SKILL_NODE(22020, 53) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(22020, 54) // RaiseEvent
        CASE_CREATE_SKILL_NODE(22020, 55) // Detect
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_22020

SkillLogic* SkillCreator_22020::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //设置变量
    Variable_22020_Damage = logic->getVariables().setVariable<int32_t>("Damage");
    Variable_22020_EnableDmg = logic->getVariables().setVariable<bool>("EnableDmg", true);
    Variable_22020_Effect = logic->getVariables().setVariable<bool>("Effect", true);
    //创建阶段phase
    auto phase = new SkillPhase_22020(1, logic, 2);
    //设置phase执行器
    phase->setRunPhaseNode(1, 25);
    phase->setDetectPhaseNode(2, 55);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_22020::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
