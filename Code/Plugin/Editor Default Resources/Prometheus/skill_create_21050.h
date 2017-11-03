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
uint64_t Variable_21050_Damage = 0;
uint64_t Variable_21050_EnableDmg = 0;
uint64_t Variable_21050_Effect = 0;
//--------------------------------------------------------------------------------
// StartPhase
//
REGISTER_REGISTER_SKILL_NODE(21050, 5) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_StartPhase::TRIGGER_START, 39, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(21050, 5) {
    auto node5 = GET_SKILL_NODE(5, PhaseNode_StartPhase);
    if (node5 == nullptr) {
        node5 = new PhaseNode_StartPhase(5, phase);
        CALL_REGISTER_SKILL_NODE(21050, 5, node5)
    }
    if (noInit == true) {
        return node5;
    }
    return node5;
}
//--------------------------------------------------------------------------------
// CompareInt
//
REGISTER_REGISTER_SKILL_NODE(21050, 12) {
    pnode->resizeTrigger(PhaseNode_CompareInt::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_CompareInt::TRIGGER_EQUAL, 13, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_CompareInt::TRIGGER_GREATER, 13, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(21050, 12) {
    auto node12 = GET_SKILL_NODE(12, PhaseNode_CompareInt);
    if (node12 == nullptr) {
        node12 = new PhaseNode_CompareInt(12, phase);
        node12->setB(60);
        CALL_REGISTER_SKILL_NODE(21050, 12, node12)
    }
    if (noInit == true) {
        return node12;
    }
    auto variables = node12->getVariables();
    if (variables != nullptr) {
        node12->setA(variables->getVariable<int32_t>(Variable_21050_Damage));
    }
    return node12;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(21050, 13) {
    pnode->resizeTrigger(PhaseNode_SetBool::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetInt>(PhaseNode_SetBool::TRIGGER_DONE, 14, PhaseNode_SetInt::FUNC_SET, &PhaseNode_SetInt::Set);
}

REGISTER_CREATE_SKILL_NODE(21050, 13) {
    auto node13 = GET_SKILL_NODE(13, PhaseNode_SetBool);
    if (node13 == nullptr) {
        node13 = new PhaseNode_SetBool(13, phase);
        node13->setName("EnableDmg");
        node13->setValue(false);
        CALL_REGISTER_SKILL_NODE(21050, 13, node13)
    }
    if (noInit == true) {
        return node13;
    }
    return node13;
}
//--------------------------------------------------------------------------------
// SetInt
//
REGISTER_REGISTER_SKILL_NODE(21050, 14) {
    pnode->resizeTrigger(PhaseNode_SetInt::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_SetInt::TRIGGER_DONE, 15, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(21050, 14) {
    auto node14 = GET_SKILL_NODE(14, PhaseNode_SetInt);
    if (node14 == nullptr) {
        node14 = new PhaseNode_SetInt(14, phase);
        node14->setName("Damage");
        node14->setValue(0);
        CALL_REGISTER_SKILL_NODE(21050, 14, node14)
    }
    if (noInit == true) {
        return node14;
    }
    return node14;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(21050, 15) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuff>(PhaseNode_PlayAnimation::TRIGGER_DONE, 29, PhaseNode_AddSkillBuff::FUNC_ADD, &PhaseNode_AddSkillBuff::Add);
}

REGISTER_CREATE_SKILL_NODE(21050, 15) {
    auto node15 = GET_SKILL_NODE(15, PhaseNode_PlayAnimation);
    if (node15 == nullptr) {
        node15 = new PhaseNode_PlayAnimation(15, phase);
        node15->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node15->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node15->setTarget(0U);
        node15->setAnimation("Hurt");
        node15->setParameter("");
        node15->setValue(false);
        CALL_REGISTER_SKILL_NODE(21050, 15, node15)
    }
    if (noInit == true) {
        return node15;
    }
    return node15;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(21050, 16) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlayEffect::TRIGGER_DONE, 31, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(21050, 16) {
    auto node16 = GET_SKILL_NODE(16, PhaseNode_PlayEffect);
    if (node16 == nullptr) {
        node16 = new PhaseNode_PlayEffect(16, phase);
        node16->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node16->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node16->setEffectID(210000);
        node16->setChangeColor(false);
        node16->setType(PhaseNode_PlayEffect::PlayEffect_Type::WithTarget);
        node16->getVars().reserve(5);
        node16->getVars().setVariable<uint64_t>(0, 0U);
        node16->getVars().setVariable<std::string>(1, "Hit");
        node16->getVars().setVariable<float>(2, .00f);
        node16->getVars().setVariable<float>(3, .00f);
        node16->getVars().setVariable<float>(4, .00f);
        node16->setRotation(.00f);
        node16->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(21050, 16, node16)
    }
    if (noInit == true) {
        return node16;
    }
    return node16;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(21050, 17) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_Delay::TRIGGER_DONE, 18, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(21050, 17) {
    auto node17 = GET_SKILL_NODE(17, PhaseNode_Delay);
    if (node17 == nullptr) {
        node17 = new PhaseNode_Delay(17, phase);
        node17->setTime(.50f);
        CALL_REGISTER_SKILL_NODE(21050, 17, node17)
    }
    if (noInit == true) {
        return node17;
    }
    return node17;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(21050, 18) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RemoveSkillBuff>(PhaseNode_PlayAnimation::TRIGGER_DONE, 19, PhaseNode_RemoveSkillBuff::FUNC_REMOVE, &PhaseNode_RemoveSkillBuff::Remove);
}

REGISTER_CREATE_SKILL_NODE(21050, 18) {
    auto node18 = GET_SKILL_NODE(18, PhaseNode_PlayAnimation);
    if (node18 == nullptr) {
        node18 = new PhaseNode_PlayAnimation(18, phase);
        node18->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node18->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node18->setTarget(0U);
        node18->setAnimation("Idle");
        node18->setParameter("");
        node18->setValue(false);
        CALL_REGISTER_SKILL_NODE(21050, 18, node18)
    }
    if (noInit == true) {
        return node18;
    }
    return node18;
}
//--------------------------------------------------------------------------------
// RemoveSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(21050, 19) {
    pnode->resizeTrigger(PhaseNode_RemoveSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_RemoveSkillBuff::TRIGGER_DONE, 37, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(21050, 19) {
    auto node19 = GET_SKILL_NODE(19, PhaseNode_RemoveSkillBuff);
    if (node19 == nullptr) {
        node19 = new PhaseNode_RemoveSkillBuff(19, phase);
        node19->setBuffID(0U);
        node19->setBuffIDs({});
        node19->setConfigID(1);
        node19->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(21050, 19, node19)
    }
    if (noInit == true) {
        return node19;
    }
    return node19;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(21050, 20) {
}

REGISTER_CREATE_SKILL_NODE(21050, 20) {
    auto node20 = GET_SKILL_NODE(20, PhaseNode_SetBool);
    if (node20 == nullptr) {
        node20 = new PhaseNode_SetBool(20, phase);
        node20->setName("EnableDmg");
        node20->setValue(true);
        CALL_REGISTER_SKILL_NODE(21050, 20, node20)
    }
    if (noInit == true) {
        return node20;
    }
    return node20;
}
//--------------------------------------------------------------------------------
// IntOperation
//
REGISTER_REGISTER_SKILL_NODE(21050, 22) {
    pnode->resizeTrigger(PhaseNode_IntOperation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetInt>(PhaseNode_IntOperation::TRIGGER_DONE, 23, PhaseNode_SetInt::FUNC_SET, &PhaseNode_SetInt::Set);
}

REGISTER_CREATE_SKILL_NODE(21050, 22) {
    auto node22 = GET_SKILL_NODE(22, PhaseNode_IntOperation);
    if (node22 == nullptr) {
        node22 = new PhaseNode_IntOperation(22, phase);
        node22->setMethod(PhaseNode_IntOperation::IntOperation_Method::Add);
        CALL_REGISTER_SKILL_NODE(21050, 22, node22)
    }
    if (noInit == true) {
        return node22;
    }
    auto variables = node22->getVariables();
    if (variables != nullptr) {
        node22->setBase(variables->getVariable<int32_t>(Variable_21050_Damage));
    }
    auto node40 = GET_SKILL_NODE(40, PhaseNode_Detect);
    if (node40 != nullptr) node22->setValue(node40->getVars().getVariable<int32_t>(0));
    return node22;
}
//--------------------------------------------------------------------------------
// SetInt
//
REGISTER_REGISTER_SKILL_NODE(21050, 23) {
    pnode->resizeTrigger(PhaseNode_SetInt::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareInt>(PhaseNode_SetInt::TRIGGER_DONE, 12, PhaseNode_CompareInt::FUNC_COMPARE, &PhaseNode_CompareInt::Compare);
}

REGISTER_CREATE_SKILL_NODE(21050, 23) {
    auto node23 = GET_SKILL_NODE(23, PhaseNode_SetInt);
    if (node23 == nullptr) {
        node23 = new PhaseNode_SetInt(23, phase);
        node23->setName("Damage");
        CALL_REGISTER_SKILL_NODE(21050, 23, node23)
    }
    if (noInit == true) {
        return node23;
    }
    auto node22 = GET_SKILL_NODE(22, PhaseNode_IntOperation);
    if (node22 != nullptr) node23->setValue(node22->getFinal());
    return node23;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(21050, 25) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareInt>(PhaseNode_If::TRIGGER_TRUE, 30, PhaseNode_CompareInt::FUNC_COMPARE, &PhaseNode_CompareInt::Compare);
}

REGISTER_CREATE_SKILL_NODE(21050, 25) {
    auto node25 = GET_SKILL_NODE(25, PhaseNode_If);
    if (node25 == nullptr) {
        node25 = new PhaseNode_If(25, phase);
        CALL_REGISTER_SKILL_NODE(21050, 25, node25)
    }
    if (noInit == true) {
        return node25;
    }
    auto variables = node25->getVariables();
    if (variables != nullptr) {
        node25->setCondition(variables->getVariable<bool>(Variable_21050_EnableDmg));
    }
    return node25;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(21050, 26) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_Delay::TRIGGER_DONE, 20, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(21050, 26) {
    auto node26 = GET_SKILL_NODE(26, PhaseNode_Delay);
    if (node26 == nullptr) {
        node26 = new PhaseNode_Delay(26, phase);
        node26->setTime(1.00f);
        CALL_REGISTER_SKILL_NODE(21050, 26, node26)
    }
    if (noInit == true) {
        return node26;
    }
    return node26;
}
//--------------------------------------------------------------------------------
// AddSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(21050, 29) {
    pnode->resizeTrigger(PhaseNode_AddSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_AddSkillBuff::TRIGGER_DONE, 17, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(21050, 29) {
    auto node29 = GET_SKILL_NODE(29, PhaseNode_AddSkillBuff);
    if (node29 == nullptr) {
        node29 = new PhaseNode_AddSkillBuff(29, phase);
        node29->setConfigID(1);
        node29->setConfigIDs({});
        node29->setTarget(0U);
        node29->setAttribute({{}});
        CALL_REGISTER_SKILL_NODE(21050, 29, node29)
    }
    if (noInit == true) {
        return node29;
    }
    return node29;
}
//--------------------------------------------------------------------------------
// CompareInt
//
REGISTER_REGISTER_SKILL_NODE(21050, 30) {
    pnode->resizeTrigger(PhaseNode_CompareInt::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_IntOperation>(PhaseNode_CompareInt::TRIGGER_EQUAL, 22, PhaseNode_IntOperation::FUNC_OPERATION, &PhaseNode_IntOperation::Operation);
    pnode->regTrigger<PhaseNode_IntOperation>(PhaseNode_CompareInt::TRIGGER_GREATER, 22, PhaseNode_IntOperation::FUNC_OPERATION, &PhaseNode_IntOperation::Operation);
}

REGISTER_CREATE_SKILL_NODE(21050, 30) {
    auto node30 = GET_SKILL_NODE(30, PhaseNode_CompareInt);
    if (node30 == nullptr) {
        node30 = new PhaseNode_CompareInt(30, phase);
        node30->setB(10);
        CALL_REGISTER_SKILL_NODE(21050, 30, node30)
    }
    if (noInit == true) {
        return node30;
    }
    auto node40 = GET_SKILL_NODE(40, PhaseNode_Detect);
    if (node40 != nullptr) node30->setA(node40->getVars().getVariable<int32_t>(0));
    return node30;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(21050, 31) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_Delay::TRIGGER_DONE, 36, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(21050, 31) {
    auto node31 = GET_SKILL_NODE(31, PhaseNode_Delay);
    if (node31 == nullptr) {
        node31 = new PhaseNode_Delay(31, phase);
        node31->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(21050, 31, node31)
    }
    if (noInit == true) {
        return node31;
    }
    return node31;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(21050, 33) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_If::TRIGGER_TRUE, 35, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(21050, 33) {
    auto node33 = GET_SKILL_NODE(33, PhaseNode_If);
    if (node33 == nullptr) {
        node33 = new PhaseNode_If(33, phase);
        CALL_REGISTER_SKILL_NODE(21050, 33, node33)
    }
    if (noInit == true) {
        return node33;
    }
    auto variables = node33->getVariables();
    if (variables != nullptr) {
        node33->setCondition(variables->getVariable<bool>(Variable_21050_Effect));
    }
    return node33;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(21050, 35) {
    pnode->resizeTrigger(PhaseNode_SetBool::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_SetBool::TRIGGER_DONE, 16, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(21050, 35) {
    auto node35 = GET_SKILL_NODE(35, PhaseNode_SetBool);
    if (node35 == nullptr) {
        node35 = new PhaseNode_SetBool(35, phase);
        node35->setName("Effect");
        node35->setValue(false);
        CALL_REGISTER_SKILL_NODE(21050, 35, node35)
    }
    if (noInit == true) {
        return node35;
    }
    return node35;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(21050, 36) {
}

REGISTER_CREATE_SKILL_NODE(21050, 36) {
    auto node36 = GET_SKILL_NODE(36, PhaseNode_SetBool);
    if (node36 == nullptr) {
        node36 = new PhaseNode_SetBool(36, phase);
        node36->setName("Effect");
        node36->setValue(true);
        CALL_REGISTER_SKILL_NODE(21050, 36, node36)
    }
    if (noInit == true) {
        return node36;
    }
    return node36;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(21050, 37) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 20, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_GREATER, 26, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(21050, 37) {
    auto node37 = GET_SKILL_NODE(37, PhaseNode_CompareFloat);
    if (node37 == nullptr) {
        node37 = new PhaseNode_CompareFloat(37, phase);
        node37->setA(1.00f);
        node37->setB(.00f);
        CALL_REGISTER_SKILL_NODE(21050, 37, node37)
    }
    if (noInit == true) {
        return node37;
    }
    return node37;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(21050, 38) {
}

REGISTER_CREATE_SKILL_NODE(21050, 38) {
    auto node38 = GET_SKILL_NODE(38, PhaseNode_SkillEndNotify);
    if (node38 == nullptr) {
        node38 = new PhaseNode_SkillEndNotify(38, phase);
        node38->setReturnType(true);
        CALL_REGISTER_SKILL_NODE(21050, 38, node38)
    }
    if (noInit == true) {
        return node38;
    }
    return node38;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(21050, 39) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_RaiseEvent::TRIGGER_DONE, 38, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
}

REGISTER_CREATE_SKILL_NODE(21050, 39) {
    auto node39 = GET_SKILL_NODE(39, PhaseNode_RaiseEvent);
    if (node39 == nullptr) {
        node39 = new PhaseNode_RaiseEvent(39, phase);
        node39->setEvent("GetDamage");
        node39->setTarget(0U);
        node39->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node39->setTypeParams(0, 0);
        node39->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(21050, 39, node39)
    }
    if (noInit == true) {
        return node39;
    }
    return node39;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(21050, 40) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_Detect::TRIGGER_ON, 25, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_Detect::TRIGGER_ON, 33, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(21050, 40) {
    auto node40 = GET_SKILL_NODE(40, PhaseNode_Detect);
    if (node40 == nullptr) {
        node40 = new PhaseNode_Detect(40, phase);
        node40->setSelf(0U);
        node40->setEvent("GetDamage");
        node40->setType(PhaseNode_Detect::Detect_Type::Damage);
        node40->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(21050, 40, node40)
    }
    if (noInit == true) {
        return node40;
    }
    return node40;
}

//--------------------------------------------------------------------------------
// SkillCreator_21050
//
class SkillCreator_21050 : public SkillCreator {
public:
    SkillCreator_21050() {}
    virtual ~SkillCreator_21050() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_21050

//--------------------------------------------------------------------------------
// SkillPhase_21050
//
class SkillPhase_21050 : public SkillPhase {
public:
    SkillPhase_21050(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_21050() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(21050, 5) // StartPhase
        CASE_CREATE_SKILL_NODE(21050, 12) // CompareInt
        CASE_CREATE_SKILL_NODE(21050, 13) // SetBool
        CASE_CREATE_SKILL_NODE(21050, 14) // SetInt
        CASE_CREATE_SKILL_NODE(21050, 15) // PlayAnimation
        CASE_CREATE_SKILL_NODE(21050, 16) // PlayEffect
        CASE_CREATE_SKILL_NODE(21050, 17) // Delay
        CASE_CREATE_SKILL_NODE(21050, 18) // PlayAnimation
        CASE_CREATE_SKILL_NODE(21050, 19) // RemoveSkillBuff
        CASE_CREATE_SKILL_NODE(21050, 20) // SetBool
        CASE_CREATE_SKILL_NODE(21050, 22) // IntOperation
        CASE_CREATE_SKILL_NODE(21050, 23) // SetInt
        CASE_CREATE_SKILL_NODE(21050, 25) // If
        CASE_CREATE_SKILL_NODE(21050, 26) // Delay
        CASE_CREATE_SKILL_NODE(21050, 29) // AddSkillBuff
        CASE_CREATE_SKILL_NODE(21050, 30) // CompareInt
        CASE_CREATE_SKILL_NODE(21050, 31) // Delay
        CASE_CREATE_SKILL_NODE(21050, 33) // If
        CASE_CREATE_SKILL_NODE(21050, 35) // SetBool
        CASE_CREATE_SKILL_NODE(21050, 36) // SetBool
        CASE_CREATE_SKILL_NODE(21050, 37) // CompareFloat
        CASE_CREATE_SKILL_NODE(21050, 38) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(21050, 39) // RaiseEvent
        CASE_CREATE_SKILL_NODE(21050, 40) // Detect
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_21050

SkillLogic* SkillCreator_21050::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //设置变量
    Variable_21050_Damage = logic->getVariables().setVariable<int32_t>("Damage");
    Variable_21050_EnableDmg = logic->getVariables().setVariable<bool>("EnableDmg", true);
    Variable_21050_Effect = logic->getVariables().setVariable<bool>("Effect", true);
    //创建阶段phase
    auto phase = new SkillPhase_21050(1, logic, 2);
    //设置phase执行器
    phase->setRunPhaseNode(1, 5);
    phase->setDetectPhaseNode(2, 40);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_21050::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
