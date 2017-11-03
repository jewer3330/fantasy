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
uint64_t Variable_20030_Damage = 0;
uint64_t Variable_20030_EnableDmg = 0;
uint64_t Variable_20030_Effect = 0;
//--------------------------------------------------------------------------------
// StartPhase
//
REGISTER_REGISTER_SKILL_NODE(20030, 6) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_StartPhase::TRIGGER_START, 35, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(20030, 6) {
    auto node6 = GET_SKILL_NODE(6, PhaseNode_StartPhase);
    if (node6 == nullptr) {
        node6 = new PhaseNode_StartPhase(6, phase);
        CALL_REGISTER_SKILL_NODE(20030, 6, node6)
    }
    if (noInit == true) {
        return node6;
    }
    return node6;
}
//--------------------------------------------------------------------------------
// CompareInt
//
REGISTER_REGISTER_SKILL_NODE(20030, 8) {
    pnode->resizeTrigger(PhaseNode_CompareInt::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_CompareInt::TRIGGER_EQUAL, 9, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_CompareInt::TRIGGER_GREATER, 9, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(20030, 8) {
    auto node8 = GET_SKILL_NODE(8, PhaseNode_CompareInt);
    if (node8 == nullptr) {
        node8 = new PhaseNode_CompareInt(8, phase);
        node8->setB(12);
        CALL_REGISTER_SKILL_NODE(20030, 8, node8)
    }
    if (noInit == true) {
        return node8;
    }
    auto variables = node8->getVariables();
    if (variables != nullptr) {
        node8->setA(variables->getVariable<int32_t>(Variable_20030_Damage));
    }
    return node8;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(20030, 9) {
    pnode->resizeTrigger(PhaseNode_SetBool::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetInt>(PhaseNode_SetBool::TRIGGER_DONE, 10, PhaseNode_SetInt::FUNC_SET, &PhaseNode_SetInt::Set);
}

REGISTER_CREATE_SKILL_NODE(20030, 9) {
    auto node9 = GET_SKILL_NODE(9, PhaseNode_SetBool);
    if (node9 == nullptr) {
        node9 = new PhaseNode_SetBool(9, phase);
        node9->setName("EnableDmg");
        node9->setValue(false);
        CALL_REGISTER_SKILL_NODE(20030, 9, node9)
    }
    if (noInit == true) {
        return node9;
    }
    return node9;
}
//--------------------------------------------------------------------------------
// SetInt
//
REGISTER_REGISTER_SKILL_NODE(20030, 10) {
    pnode->resizeTrigger(PhaseNode_SetInt::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_SetInt::TRIGGER_DONE, 11, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(20030, 10) {
    auto node10 = GET_SKILL_NODE(10, PhaseNode_SetInt);
    if (node10 == nullptr) {
        node10 = new PhaseNode_SetInt(10, phase);
        node10->setName("Damage");
        node10->setValue(0);
        CALL_REGISTER_SKILL_NODE(20030, 10, node10)
    }
    if (noInit == true) {
        return node10;
    }
    return node10;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(20030, 11) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuff>(PhaseNode_PlayAnimation::TRIGGER_DONE, 25, PhaseNode_AddSkillBuff::FUNC_ADD, &PhaseNode_AddSkillBuff::Add);
}

REGISTER_CREATE_SKILL_NODE(20030, 11) {
    auto node11 = GET_SKILL_NODE(11, PhaseNode_PlayAnimation);
    if (node11 == nullptr) {
        node11 = new PhaseNode_PlayAnimation(11, phase);
        node11->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node11->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node11->setTarget(0U);
        node11->setAnimation("Hurt");
        node11->setParameter("");
        node11->setValue(false);
        CALL_REGISTER_SKILL_NODE(20030, 11, node11)
    }
    if (noInit == true) {
        return node11;
    }
    return node11;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(20030, 12) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlayEffect::TRIGGER_DONE, 27, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(20030, 12) {
    auto node12 = GET_SKILL_NODE(12, PhaseNode_PlayEffect);
    if (node12 == nullptr) {
        node12 = new PhaseNode_PlayEffect(12, phase);
        node12->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node12->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node12->setEffectID(1002);
        node12->setChangeColor(false);
        node12->setType(PhaseNode_PlayEffect::PlayEffect_Type::WithTarget);
        node12->getVars().reserve(5);
        node12->getVars().setVariable<uint64_t>(0, 0U);
        node12->getVars().setVariable<std::string>(1, "");
        node12->getVars().setVariable<float>(2, .00f);
        node12->getVars().setVariable<float>(3, .00f);
        node12->getVars().setVariable<float>(4, .00f);
        node12->setRotation(.00f);
        node12->setScale(.00f);
        CALL_REGISTER_SKILL_NODE(20030, 12, node12)
    }
    if (noInit == true) {
        return node12;
    }
    return node12;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(20030, 13) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_Delay::TRIGGER_DONE, 14, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(20030, 13) {
    auto node13 = GET_SKILL_NODE(13, PhaseNode_Delay);
    if (node13 == nullptr) {
        node13 = new PhaseNode_Delay(13, phase);
        node13->setTime(.70f);
        CALL_REGISTER_SKILL_NODE(20030, 13, node13)
    }
    if (noInit == true) {
        return node13;
    }
    return node13;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(20030, 14) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RemoveSkillBuff>(PhaseNode_PlayAnimation::TRIGGER_DONE, 15, PhaseNode_RemoveSkillBuff::FUNC_REMOVE, &PhaseNode_RemoveSkillBuff::Remove);
}

REGISTER_CREATE_SKILL_NODE(20030, 14) {
    auto node14 = GET_SKILL_NODE(14, PhaseNode_PlayAnimation);
    if (node14 == nullptr) {
        node14 = new PhaseNode_PlayAnimation(14, phase);
        node14->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node14->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node14->setTarget(0U);
        node14->setAnimation("Idle");
        node14->setParameter("");
        node14->setValue(false);
        CALL_REGISTER_SKILL_NODE(20030, 14, node14)
    }
    if (noInit == true) {
        return node14;
    }
    return node14;
}
//--------------------------------------------------------------------------------
// RemoveSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(20030, 15) {
    pnode->resizeTrigger(PhaseNode_RemoveSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_RemoveSkillBuff::TRIGGER_DONE, 33, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(20030, 15) {
    auto node15 = GET_SKILL_NODE(15, PhaseNode_RemoveSkillBuff);
    if (node15 == nullptr) {
        node15 = new PhaseNode_RemoveSkillBuff(15, phase);
        node15->setBuffID(0U);
        node15->setBuffIDs({});
        node15->setConfigID(1);
        node15->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(20030, 15, node15)
    }
    if (noInit == true) {
        return node15;
    }
    return node15;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(20030, 16) {
}

REGISTER_CREATE_SKILL_NODE(20030, 16) {
    auto node16 = GET_SKILL_NODE(16, PhaseNode_SetBool);
    if (node16 == nullptr) {
        node16 = new PhaseNode_SetBool(16, phase);
        node16->setName("EnableDmg");
        node16->setValue(true);
        CALL_REGISTER_SKILL_NODE(20030, 16, node16)
    }
    if (noInit == true) {
        return node16;
    }
    return node16;
}
//--------------------------------------------------------------------------------
// IntOperation
//
REGISTER_REGISTER_SKILL_NODE(20030, 18) {
    pnode->resizeTrigger(PhaseNode_IntOperation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetInt>(PhaseNode_IntOperation::TRIGGER_DONE, 19, PhaseNode_SetInt::FUNC_SET, &PhaseNode_SetInt::Set);
}

REGISTER_CREATE_SKILL_NODE(20030, 18) {
    auto node18 = GET_SKILL_NODE(18, PhaseNode_IntOperation);
    if (node18 == nullptr) {
        node18 = new PhaseNode_IntOperation(18, phase);
        node18->setMethod(PhaseNode_IntOperation::IntOperation_Method::Add);
        CALL_REGISTER_SKILL_NODE(20030, 18, node18)
    }
    if (noInit == true) {
        return node18;
    }
    auto variables = node18->getVariables();
    if (variables != nullptr) {
        node18->setBase(variables->getVariable<int32_t>(Variable_20030_Damage));
    }
    auto node36 = GET_SKILL_NODE(36, PhaseNode_Detect);
    if (node36 != nullptr) node18->setValue(node36->getVars().getVariable<int32_t>(0));
    return node18;
}
//--------------------------------------------------------------------------------
// SetInt
//
REGISTER_REGISTER_SKILL_NODE(20030, 19) {
    pnode->resizeTrigger(PhaseNode_SetInt::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareInt>(PhaseNode_SetInt::TRIGGER_DONE, 8, PhaseNode_CompareInt::FUNC_COMPARE, &PhaseNode_CompareInt::Compare);
}

REGISTER_CREATE_SKILL_NODE(20030, 19) {
    auto node19 = GET_SKILL_NODE(19, PhaseNode_SetInt);
    if (node19 == nullptr) {
        node19 = new PhaseNode_SetInt(19, phase);
        node19->setName("Damage");
        CALL_REGISTER_SKILL_NODE(20030, 19, node19)
    }
    if (noInit == true) {
        return node19;
    }
    auto node18 = GET_SKILL_NODE(18, PhaseNode_IntOperation);
    if (node18 != nullptr) node19->setValue(node18->getFinal());
    return node19;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(20030, 21) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareInt>(PhaseNode_If::TRIGGER_TRUE, 26, PhaseNode_CompareInt::FUNC_COMPARE, &PhaseNode_CompareInt::Compare);
}

REGISTER_CREATE_SKILL_NODE(20030, 21) {
    auto node21 = GET_SKILL_NODE(21, PhaseNode_If);
    if (node21 == nullptr) {
        node21 = new PhaseNode_If(21, phase);
        CALL_REGISTER_SKILL_NODE(20030, 21, node21)
    }
    if (noInit == true) {
        return node21;
    }
    auto variables = node21->getVariables();
    if (variables != nullptr) {
        node21->setCondition(variables->getVariable<bool>(Variable_20030_EnableDmg));
    }
    return node21;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(20030, 22) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_Delay::TRIGGER_DONE, 16, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(20030, 22) {
    auto node22 = GET_SKILL_NODE(22, PhaseNode_Delay);
    if (node22 == nullptr) {
        node22 = new PhaseNode_Delay(22, phase);
        node22->setTime(1.00f);
        CALL_REGISTER_SKILL_NODE(20030, 22, node22)
    }
    if (noInit == true) {
        return node22;
    }
    return node22;
}
//--------------------------------------------------------------------------------
// AddSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(20030, 25) {
    pnode->resizeTrigger(PhaseNode_AddSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_AddSkillBuff::TRIGGER_DONE, 13, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(20030, 25) {
    auto node25 = GET_SKILL_NODE(25, PhaseNode_AddSkillBuff);
    if (node25 == nullptr) {
        node25 = new PhaseNode_AddSkillBuff(25, phase);
        node25->setConfigID(1);
        node25->setConfigIDs({});
        node25->setTarget(0U);
        node25->setAttribute({{}});
        CALL_REGISTER_SKILL_NODE(20030, 25, node25)
    }
    if (noInit == true) {
        return node25;
    }
    return node25;
}
//--------------------------------------------------------------------------------
// CompareInt
//
REGISTER_REGISTER_SKILL_NODE(20030, 26) {
    pnode->resizeTrigger(PhaseNode_CompareInt::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_IntOperation>(PhaseNode_CompareInt::TRIGGER_EQUAL, 18, PhaseNode_IntOperation::FUNC_OPERATION, &PhaseNode_IntOperation::Operation);
    pnode->regTrigger<PhaseNode_IntOperation>(PhaseNode_CompareInt::TRIGGER_GREATER, 18, PhaseNode_IntOperation::FUNC_OPERATION, &PhaseNode_IntOperation::Operation);
}

REGISTER_CREATE_SKILL_NODE(20030, 26) {
    auto node26 = GET_SKILL_NODE(26, PhaseNode_CompareInt);
    if (node26 == nullptr) {
        node26 = new PhaseNode_CompareInt(26, phase);
        node26->setB(8);
        CALL_REGISTER_SKILL_NODE(20030, 26, node26)
    }
    if (noInit == true) {
        return node26;
    }
    auto node36 = GET_SKILL_NODE(36, PhaseNode_Detect);
    if (node36 != nullptr) node26->setA(node36->getVars().getVariable<int32_t>(0));
    return node26;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(20030, 27) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_Delay::TRIGGER_DONE, 32, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(20030, 27) {
    auto node27 = GET_SKILL_NODE(27, PhaseNode_Delay);
    if (node27 == nullptr) {
        node27 = new PhaseNode_Delay(27, phase);
        node27->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(20030, 27, node27)
    }
    if (noInit == true) {
        return node27;
    }
    return node27;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(20030, 29) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_If::TRIGGER_TRUE, 31, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(20030, 29) {
    auto node29 = GET_SKILL_NODE(29, PhaseNode_If);
    if (node29 == nullptr) {
        node29 = new PhaseNode_If(29, phase);
        CALL_REGISTER_SKILL_NODE(20030, 29, node29)
    }
    if (noInit == true) {
        return node29;
    }
    auto variables = node29->getVariables();
    if (variables != nullptr) {
        node29->setCondition(variables->getVariable<bool>(Variable_20030_Effect));
    }
    return node29;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(20030, 31) {
    pnode->resizeTrigger(PhaseNode_SetBool::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_SetBool::TRIGGER_DONE, 12, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(20030, 31) {
    auto node31 = GET_SKILL_NODE(31, PhaseNode_SetBool);
    if (node31 == nullptr) {
        node31 = new PhaseNode_SetBool(31, phase);
        node31->setName("Effect");
        node31->setValue(false);
        CALL_REGISTER_SKILL_NODE(20030, 31, node31)
    }
    if (noInit == true) {
        return node31;
    }
    return node31;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(20030, 32) {
}

REGISTER_CREATE_SKILL_NODE(20030, 32) {
    auto node32 = GET_SKILL_NODE(32, PhaseNode_SetBool);
    if (node32 == nullptr) {
        node32 = new PhaseNode_SetBool(32, phase);
        node32->setName("Effect");
        node32->setValue(true);
        CALL_REGISTER_SKILL_NODE(20030, 32, node32)
    }
    if (noInit == true) {
        return node32;
    }
    return node32;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(20030, 33) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 16, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_GREATER, 22, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(20030, 33) {
    auto node33 = GET_SKILL_NODE(33, PhaseNode_CompareFloat);
    if (node33 == nullptr) {
        node33 = new PhaseNode_CompareFloat(33, phase);
        node33->setA(1.00f);
        node33->setB(.00f);
        CALL_REGISTER_SKILL_NODE(20030, 33, node33)
    }
    if (noInit == true) {
        return node33;
    }
    return node33;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(20030, 34) {
}

REGISTER_CREATE_SKILL_NODE(20030, 34) {
    auto node34 = GET_SKILL_NODE(34, PhaseNode_SkillEndNotify);
    if (node34 == nullptr) {
        node34 = new PhaseNode_SkillEndNotify(34, phase);
        node34->setReturnType(true);
        CALL_REGISTER_SKILL_NODE(20030, 34, node34)
    }
    if (noInit == true) {
        return node34;
    }
    return node34;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(20030, 35) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_RaiseEvent::TRIGGER_DONE, 34, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
}

REGISTER_CREATE_SKILL_NODE(20030, 35) {
    auto node35 = GET_SKILL_NODE(35, PhaseNode_RaiseEvent);
    if (node35 == nullptr) {
        node35 = new PhaseNode_RaiseEvent(35, phase);
        node35->setEvent("GetDamage");
        node35->setTarget(0U);
        node35->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node35->setTypeParams(0, 0);
        node35->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(20030, 35, node35)
    }
    if (noInit == true) {
        return node35;
    }
    return node35;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(20030, 36) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_Detect::TRIGGER_ON, 21, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_Detect::TRIGGER_ON, 29, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(20030, 36) {
    auto node36 = GET_SKILL_NODE(36, PhaseNode_Detect);
    if (node36 == nullptr) {
        node36 = new PhaseNode_Detect(36, phase);
        node36->setSelf(0U);
        node36->setEvent("GetDamage");
        node36->setType(PhaseNode_Detect::Detect_Type::Damage);
        node36->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(20030, 36, node36)
    }
    if (noInit == true) {
        return node36;
    }
    return node36;
}

//--------------------------------------------------------------------------------
// SkillCreator_20030
//
class SkillCreator_20030 : public SkillCreator {
public:
    SkillCreator_20030() {}
    virtual ~SkillCreator_20030() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_20030

//--------------------------------------------------------------------------------
// SkillPhase_20030
//
class SkillPhase_20030 : public SkillPhase {
public:
    SkillPhase_20030(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_20030() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(20030, 6) // StartPhase
        CASE_CREATE_SKILL_NODE(20030, 8) // CompareInt
        CASE_CREATE_SKILL_NODE(20030, 9) // SetBool
        CASE_CREATE_SKILL_NODE(20030, 10) // SetInt
        CASE_CREATE_SKILL_NODE(20030, 11) // PlayAnimation
        CASE_CREATE_SKILL_NODE(20030, 12) // PlayEffect
        CASE_CREATE_SKILL_NODE(20030, 13) // Delay
        CASE_CREATE_SKILL_NODE(20030, 14) // PlayAnimation
        CASE_CREATE_SKILL_NODE(20030, 15) // RemoveSkillBuff
        CASE_CREATE_SKILL_NODE(20030, 16) // SetBool
        CASE_CREATE_SKILL_NODE(20030, 18) // IntOperation
        CASE_CREATE_SKILL_NODE(20030, 19) // SetInt
        CASE_CREATE_SKILL_NODE(20030, 21) // If
        CASE_CREATE_SKILL_NODE(20030, 22) // Delay
        CASE_CREATE_SKILL_NODE(20030, 25) // AddSkillBuff
        CASE_CREATE_SKILL_NODE(20030, 26) // CompareInt
        CASE_CREATE_SKILL_NODE(20030, 27) // Delay
        CASE_CREATE_SKILL_NODE(20030, 29) // If
        CASE_CREATE_SKILL_NODE(20030, 31) // SetBool
        CASE_CREATE_SKILL_NODE(20030, 32) // SetBool
        CASE_CREATE_SKILL_NODE(20030, 33) // CompareFloat
        CASE_CREATE_SKILL_NODE(20030, 34) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(20030, 35) // RaiseEvent
        CASE_CREATE_SKILL_NODE(20030, 36) // Detect
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_20030

SkillLogic* SkillCreator_20030::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //设置变量
    Variable_20030_Damage = logic->getVariables().setVariable<int32_t>("Damage");
    Variable_20030_EnableDmg = logic->getVariables().setVariable<bool>("EnableDmg", true);
    Variable_20030_Effect = logic->getVariables().setVariable<bool>("Effect", true);
    //创建阶段phase
    auto phase = new SkillPhase_20030(1, logic, 2);
    //设置phase执行器
    phase->setRunPhaseNode(1, 6);
    phase->setDetectPhaseNode(2, 36);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_20030::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
