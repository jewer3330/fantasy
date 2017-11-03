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
uint64_t Variable_20060_Damage = 0;
uint64_t Variable_20060_EnableDmg = 0;
uint64_t Variable_20060_Effect = 0;
//--------------------------------------------------------------------------------
// StartPhase
//
REGISTER_REGISTER_SKILL_NODE(20060, 7) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_StartPhase::TRIGGER_START, 36, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(20060, 7) {
    auto node7 = GET_SKILL_NODE(7, PhaseNode_StartPhase);
    if (node7 == nullptr) {
        node7 = new PhaseNode_StartPhase(7, phase);
        CALL_REGISTER_SKILL_NODE(20060, 7, node7)
    }
    if (noInit == true) {
        return node7;
    }
    return node7;
}
//--------------------------------------------------------------------------------
// CompareInt
//
REGISTER_REGISTER_SKILL_NODE(20060, 9) {
    pnode->resizeTrigger(PhaseNode_CompareInt::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_CompareInt::TRIGGER_EQUAL, 10, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_CompareInt::TRIGGER_GREATER, 10, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(20060, 9) {
    auto node9 = GET_SKILL_NODE(9, PhaseNode_CompareInt);
    if (node9 == nullptr) {
        node9 = new PhaseNode_CompareInt(9, phase);
        node9->setB(20);
        CALL_REGISTER_SKILL_NODE(20060, 9, node9)
    }
    if (noInit == true) {
        return node9;
    }
    auto variables = node9->getVariables();
    if (variables != nullptr) {
        node9->setA(variables->getVariable<int32_t>(Variable_20060_Damage));
    }
    return node9;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(20060, 10) {
    pnode->resizeTrigger(PhaseNode_SetBool::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetInt>(PhaseNode_SetBool::TRIGGER_DONE, 11, PhaseNode_SetInt::FUNC_SET, &PhaseNode_SetInt::Set);
}

REGISTER_CREATE_SKILL_NODE(20060, 10) {
    auto node10 = GET_SKILL_NODE(10, PhaseNode_SetBool);
    if (node10 == nullptr) {
        node10 = new PhaseNode_SetBool(10, phase);
        node10->setName("EnableDmg");
        node10->setValue(false);
        CALL_REGISTER_SKILL_NODE(20060, 10, node10)
    }
    if (noInit == true) {
        return node10;
    }
    return node10;
}
//--------------------------------------------------------------------------------
// SetInt
//
REGISTER_REGISTER_SKILL_NODE(20060, 11) {
    pnode->resizeTrigger(PhaseNode_SetInt::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_SetInt::TRIGGER_DONE, 12, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(20060, 11) {
    auto node11 = GET_SKILL_NODE(11, PhaseNode_SetInt);
    if (node11 == nullptr) {
        node11 = new PhaseNode_SetInt(11, phase);
        node11->setName("Damage");
        node11->setValue(0);
        CALL_REGISTER_SKILL_NODE(20060, 11, node11)
    }
    if (noInit == true) {
        return node11;
    }
    return node11;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(20060, 12) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuff>(PhaseNode_PlayAnimation::TRIGGER_DONE, 26, PhaseNode_AddSkillBuff::FUNC_ADD, &PhaseNode_AddSkillBuff::Add);
}

REGISTER_CREATE_SKILL_NODE(20060, 12) {
    auto node12 = GET_SKILL_NODE(12, PhaseNode_PlayAnimation);
    if (node12 == nullptr) {
        node12 = new PhaseNode_PlayAnimation(12, phase);
        node12->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node12->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node12->setTarget(0U);
        node12->setAnimation("Hurt");
        node12->setParameter("");
        node12->setValue(false);
        CALL_REGISTER_SKILL_NODE(20060, 12, node12)
    }
    if (noInit == true) {
        return node12;
    }
    return node12;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(20060, 13) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlayEffect::TRIGGER_DONE, 28, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(20060, 13) {
    auto node13 = GET_SKILL_NODE(13, PhaseNode_PlayEffect);
    if (node13 == nullptr) {
        node13 = new PhaseNode_PlayEffect(13, phase);
        node13->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node13->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node13->setEffectID(0);
        node13->setChangeColor(false);
        node13->setType(PhaseNode_PlayEffect::PlayEffect_Type::WithTarget);
        node13->getVars().reserve(5);
        node13->getVars().setVariable<uint64_t>(0, 0U);
        node13->getVars().setVariable<std::string>(1, "");
        node13->getVars().setVariable<float>(2, .00f);
        node13->getVars().setVariable<float>(3, .00f);
        node13->getVars().setVariable<float>(4, .00f);
        node13->setRotation(.00f);
        node13->setScale(.00f);
        CALL_REGISTER_SKILL_NODE(20060, 13, node13)
    }
    if (noInit == true) {
        return node13;
    }
    return node13;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(20060, 14) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_Delay::TRIGGER_DONE, 15, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(20060, 14) {
    auto node14 = GET_SKILL_NODE(14, PhaseNode_Delay);
    if (node14 == nullptr) {
        node14 = new PhaseNode_Delay(14, phase);
        node14->setTime(.54f);
        CALL_REGISTER_SKILL_NODE(20060, 14, node14)
    }
    if (noInit == true) {
        return node14;
    }
    return node14;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(20060, 15) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RemoveSkillBuff>(PhaseNode_PlayAnimation::TRIGGER_DONE, 16, PhaseNode_RemoveSkillBuff::FUNC_REMOVE, &PhaseNode_RemoveSkillBuff::Remove);
}

REGISTER_CREATE_SKILL_NODE(20060, 15) {
    auto node15 = GET_SKILL_NODE(15, PhaseNode_PlayAnimation);
    if (node15 == nullptr) {
        node15 = new PhaseNode_PlayAnimation(15, phase);
        node15->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node15->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node15->setTarget(0U);
        node15->setAnimation("Idle");
        node15->setParameter("");
        node15->setValue(false);
        CALL_REGISTER_SKILL_NODE(20060, 15, node15)
    }
    if (noInit == true) {
        return node15;
    }
    return node15;
}
//--------------------------------------------------------------------------------
// RemoveSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(20060, 16) {
    pnode->resizeTrigger(PhaseNode_RemoveSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_RemoveSkillBuff::TRIGGER_DONE, 34, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(20060, 16) {
    auto node16 = GET_SKILL_NODE(16, PhaseNode_RemoveSkillBuff);
    if (node16 == nullptr) {
        node16 = new PhaseNode_RemoveSkillBuff(16, phase);
        node16->setBuffID(0U);
        node16->setBuffIDs({});
        node16->setConfigID(1);
        node16->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(20060, 16, node16)
    }
    if (noInit == true) {
        return node16;
    }
    return node16;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(20060, 17) {
}

REGISTER_CREATE_SKILL_NODE(20060, 17) {
    auto node17 = GET_SKILL_NODE(17, PhaseNode_SetBool);
    if (node17 == nullptr) {
        node17 = new PhaseNode_SetBool(17, phase);
        node17->setName("EnableDmg");
        node17->setValue(true);
        CALL_REGISTER_SKILL_NODE(20060, 17, node17)
    }
    if (noInit == true) {
        return node17;
    }
    return node17;
}
//--------------------------------------------------------------------------------
// IntOperation
//
REGISTER_REGISTER_SKILL_NODE(20060, 19) {
    pnode->resizeTrigger(PhaseNode_IntOperation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetInt>(PhaseNode_IntOperation::TRIGGER_DONE, 20, PhaseNode_SetInt::FUNC_SET, &PhaseNode_SetInt::Set);
}

REGISTER_CREATE_SKILL_NODE(20060, 19) {
    auto node19 = GET_SKILL_NODE(19, PhaseNode_IntOperation);
    if (node19 == nullptr) {
        node19 = new PhaseNode_IntOperation(19, phase);
        node19->setMethod(PhaseNode_IntOperation::IntOperation_Method::Add);
        CALL_REGISTER_SKILL_NODE(20060, 19, node19)
    }
    if (noInit == true) {
        return node19;
    }
    auto variables = node19->getVariables();
    if (variables != nullptr) {
        node19->setBase(variables->getVariable<int32_t>(Variable_20060_Damage));
    }
    auto node37 = GET_SKILL_NODE(37, PhaseNode_Detect);
    if (node37 != nullptr) node19->setValue(node37->getVars().getVariable<int32_t>(0));
    return node19;
}
//--------------------------------------------------------------------------------
// SetInt
//
REGISTER_REGISTER_SKILL_NODE(20060, 20) {
    pnode->resizeTrigger(PhaseNode_SetInt::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareInt>(PhaseNode_SetInt::TRIGGER_DONE, 9, PhaseNode_CompareInt::FUNC_COMPARE, &PhaseNode_CompareInt::Compare);
}

REGISTER_CREATE_SKILL_NODE(20060, 20) {
    auto node20 = GET_SKILL_NODE(20, PhaseNode_SetInt);
    if (node20 == nullptr) {
        node20 = new PhaseNode_SetInt(20, phase);
        node20->setName("Damage");
        CALL_REGISTER_SKILL_NODE(20060, 20, node20)
    }
    if (noInit == true) {
        return node20;
    }
    auto node19 = GET_SKILL_NODE(19, PhaseNode_IntOperation);
    if (node19 != nullptr) node20->setValue(node19->getFinal());
    return node20;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(20060, 22) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareInt>(PhaseNode_If::TRIGGER_TRUE, 27, PhaseNode_CompareInt::FUNC_COMPARE, &PhaseNode_CompareInt::Compare);
}

REGISTER_CREATE_SKILL_NODE(20060, 22) {
    auto node22 = GET_SKILL_NODE(22, PhaseNode_If);
    if (node22 == nullptr) {
        node22 = new PhaseNode_If(22, phase);
        CALL_REGISTER_SKILL_NODE(20060, 22, node22)
    }
    if (noInit == true) {
        return node22;
    }
    auto variables = node22->getVariables();
    if (variables != nullptr) {
        node22->setCondition(variables->getVariable<bool>(Variable_20060_EnableDmg));
    }
    return node22;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(20060, 23) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_Delay::TRIGGER_DONE, 17, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(20060, 23) {
    auto node23 = GET_SKILL_NODE(23, PhaseNode_Delay);
    if (node23 == nullptr) {
        node23 = new PhaseNode_Delay(23, phase);
        node23->setTime(1.00f);
        CALL_REGISTER_SKILL_NODE(20060, 23, node23)
    }
    if (noInit == true) {
        return node23;
    }
    return node23;
}
//--------------------------------------------------------------------------------
// AddSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(20060, 26) {
    pnode->resizeTrigger(PhaseNode_AddSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_AddSkillBuff::TRIGGER_DONE, 14, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(20060, 26) {
    auto node26 = GET_SKILL_NODE(26, PhaseNode_AddSkillBuff);
    if (node26 == nullptr) {
        node26 = new PhaseNode_AddSkillBuff(26, phase);
        node26->setConfigID(1);
        node26->setConfigIDs({});
        node26->setTarget(0U);
        node26->setAttribute({{}});
        CALL_REGISTER_SKILL_NODE(20060, 26, node26)
    }
    if (noInit == true) {
        return node26;
    }
    return node26;
}
//--------------------------------------------------------------------------------
// CompareInt
//
REGISTER_REGISTER_SKILL_NODE(20060, 27) {
    pnode->resizeTrigger(PhaseNode_CompareInt::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_IntOperation>(PhaseNode_CompareInt::TRIGGER_EQUAL, 19, PhaseNode_IntOperation::FUNC_OPERATION, &PhaseNode_IntOperation::Operation);
    pnode->regTrigger<PhaseNode_IntOperation>(PhaseNode_CompareInt::TRIGGER_GREATER, 19, PhaseNode_IntOperation::FUNC_OPERATION, &PhaseNode_IntOperation::Operation);
}

REGISTER_CREATE_SKILL_NODE(20060, 27) {
    auto node27 = GET_SKILL_NODE(27, PhaseNode_CompareInt);
    if (node27 == nullptr) {
        node27 = new PhaseNode_CompareInt(27, phase);
        node27->setB(8);
        CALL_REGISTER_SKILL_NODE(20060, 27, node27)
    }
    if (noInit == true) {
        return node27;
    }
    auto node37 = GET_SKILL_NODE(37, PhaseNode_Detect);
    if (node37 != nullptr) node27->setA(node37->getVars().getVariable<int32_t>(0));
    return node27;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(20060, 28) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_Delay::TRIGGER_DONE, 33, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(20060, 28) {
    auto node28 = GET_SKILL_NODE(28, PhaseNode_Delay);
    if (node28 == nullptr) {
        node28 = new PhaseNode_Delay(28, phase);
        node28->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(20060, 28, node28)
    }
    if (noInit == true) {
        return node28;
    }
    return node28;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(20060, 30) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_If::TRIGGER_TRUE, 32, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(20060, 30) {
    auto node30 = GET_SKILL_NODE(30, PhaseNode_If);
    if (node30 == nullptr) {
        node30 = new PhaseNode_If(30, phase);
        CALL_REGISTER_SKILL_NODE(20060, 30, node30)
    }
    if (noInit == true) {
        return node30;
    }
    auto variables = node30->getVariables();
    if (variables != nullptr) {
        node30->setCondition(variables->getVariable<bool>(Variable_20060_Effect));
    }
    return node30;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(20060, 32) {
    pnode->resizeTrigger(PhaseNode_SetBool::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_SetBool::TRIGGER_DONE, 13, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(20060, 32) {
    auto node32 = GET_SKILL_NODE(32, PhaseNode_SetBool);
    if (node32 == nullptr) {
        node32 = new PhaseNode_SetBool(32, phase);
        node32->setName("Effect");
        node32->setValue(false);
        CALL_REGISTER_SKILL_NODE(20060, 32, node32)
    }
    if (noInit == true) {
        return node32;
    }
    return node32;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(20060, 33) {
}

REGISTER_CREATE_SKILL_NODE(20060, 33) {
    auto node33 = GET_SKILL_NODE(33, PhaseNode_SetBool);
    if (node33 == nullptr) {
        node33 = new PhaseNode_SetBool(33, phase);
        node33->setName("Effect");
        node33->setValue(true);
        CALL_REGISTER_SKILL_NODE(20060, 33, node33)
    }
    if (noInit == true) {
        return node33;
    }
    return node33;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(20060, 34) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 17, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_GREATER, 23, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(20060, 34) {
    auto node34 = GET_SKILL_NODE(34, PhaseNode_CompareFloat);
    if (node34 == nullptr) {
        node34 = new PhaseNode_CompareFloat(34, phase);
        node34->setA(1.00f);
        node34->setB(.00f);
        CALL_REGISTER_SKILL_NODE(20060, 34, node34)
    }
    if (noInit == true) {
        return node34;
    }
    return node34;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(20060, 35) {
}

REGISTER_CREATE_SKILL_NODE(20060, 35) {
    auto node35 = GET_SKILL_NODE(35, PhaseNode_SkillEndNotify);
    if (node35 == nullptr) {
        node35 = new PhaseNode_SkillEndNotify(35, phase);
        node35->setReturnType(true);
        CALL_REGISTER_SKILL_NODE(20060, 35, node35)
    }
    if (noInit == true) {
        return node35;
    }
    return node35;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(20060, 36) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_RaiseEvent::TRIGGER_DONE, 35, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
}

REGISTER_CREATE_SKILL_NODE(20060, 36) {
    auto node36 = GET_SKILL_NODE(36, PhaseNode_RaiseEvent);
    if (node36 == nullptr) {
        node36 = new PhaseNode_RaiseEvent(36, phase);
        node36->setEvent("GetDamage");
        node36->setTarget(0U);
        node36->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node36->setTypeParams(0, 0);
        node36->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(20060, 36, node36)
    }
    if (noInit == true) {
        return node36;
    }
    return node36;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(20060, 37) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_Detect::TRIGGER_ON, 22, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_Detect::TRIGGER_ON, 30, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(20060, 37) {
    auto node37 = GET_SKILL_NODE(37, PhaseNode_Detect);
    if (node37 == nullptr) {
        node37 = new PhaseNode_Detect(37, phase);
        node37->setSelf(0U);
        node37->setEvent("GetDamage");
        node37->setType(PhaseNode_Detect::Detect_Type::Damage);
        node37->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(20060, 37, node37)
    }
    if (noInit == true) {
        return node37;
    }
    return node37;
}

//--------------------------------------------------------------------------------
// SkillCreator_20060
//
class SkillCreator_20060 : public SkillCreator {
public:
    SkillCreator_20060() {}
    virtual ~SkillCreator_20060() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_20060

//--------------------------------------------------------------------------------
// SkillPhase_20060
//
class SkillPhase_20060 : public SkillPhase {
public:
    SkillPhase_20060(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_20060() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(20060, 7) // StartPhase
        CASE_CREATE_SKILL_NODE(20060, 9) // CompareInt
        CASE_CREATE_SKILL_NODE(20060, 10) // SetBool
        CASE_CREATE_SKILL_NODE(20060, 11) // SetInt
        CASE_CREATE_SKILL_NODE(20060, 12) // PlayAnimation
        CASE_CREATE_SKILL_NODE(20060, 13) // PlayEffect
        CASE_CREATE_SKILL_NODE(20060, 14) // Delay
        CASE_CREATE_SKILL_NODE(20060, 15) // PlayAnimation
        CASE_CREATE_SKILL_NODE(20060, 16) // RemoveSkillBuff
        CASE_CREATE_SKILL_NODE(20060, 17) // SetBool
        CASE_CREATE_SKILL_NODE(20060, 19) // IntOperation
        CASE_CREATE_SKILL_NODE(20060, 20) // SetInt
        CASE_CREATE_SKILL_NODE(20060, 22) // If
        CASE_CREATE_SKILL_NODE(20060, 23) // Delay
        CASE_CREATE_SKILL_NODE(20060, 26) // AddSkillBuff
        CASE_CREATE_SKILL_NODE(20060, 27) // CompareInt
        CASE_CREATE_SKILL_NODE(20060, 28) // Delay
        CASE_CREATE_SKILL_NODE(20060, 30) // If
        CASE_CREATE_SKILL_NODE(20060, 32) // SetBool
        CASE_CREATE_SKILL_NODE(20060, 33) // SetBool
        CASE_CREATE_SKILL_NODE(20060, 34) // CompareFloat
        CASE_CREATE_SKILL_NODE(20060, 35) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(20060, 36) // RaiseEvent
        CASE_CREATE_SKILL_NODE(20060, 37) // Detect
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_20060

SkillLogic* SkillCreator_20060::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //设置变量
    Variable_20060_Damage = logic->getVariables().setVariable<int32_t>("Damage");
    Variable_20060_EnableDmg = logic->getVariables().setVariable<bool>("EnableDmg", true);
    Variable_20060_Effect = logic->getVariables().setVariable<bool>("Effect", true);
    //创建阶段phase
    auto phase = new SkillPhase_20060(1, logic, 2);
    //设置phase执行器
    phase->setRunPhaseNode(1, 7);
    phase->setDetectPhaseNode(2, 37);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_20060::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
