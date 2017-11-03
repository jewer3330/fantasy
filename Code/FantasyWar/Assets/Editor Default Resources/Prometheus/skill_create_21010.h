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
uint64_t Variable_21010_Damage = 0;
uint64_t Variable_21010_EnableDmg = 0;
uint64_t Variable_21010_Effect = 0;
//--------------------------------------------------------------------------------
// StartPhase
//
REGISTER_REGISTER_SKILL_NODE(21010, 11) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_StartPhase::TRIGGER_START, 40, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(21010, 11) {
    auto node11 = GET_SKILL_NODE(11, PhaseNode_StartPhase);
    if (node11 == nullptr) {
        node11 = new PhaseNode_StartPhase(11, phase);
        CALL_REGISTER_SKILL_NODE(21010, 11, node11)
    }
    if (noInit == true) {
        return node11;
    }
    return node11;
}
//--------------------------------------------------------------------------------
// CompareInt
//
REGISTER_REGISTER_SKILL_NODE(21010, 13) {
    pnode->resizeTrigger(PhaseNode_CompareInt::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_CompareInt::TRIGGER_EQUAL, 14, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_CompareInt::TRIGGER_GREATER, 14, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(21010, 13) {
    auto node13 = GET_SKILL_NODE(13, PhaseNode_CompareInt);
    if (node13 == nullptr) {
        node13 = new PhaseNode_CompareInt(13, phase);
        node13->setB(20);
        CALL_REGISTER_SKILL_NODE(21010, 13, node13)
    }
    if (noInit == true) {
        return node13;
    }
    auto variables = node13->getVariables();
    if (variables != nullptr) {
        node13->setA(variables->getVariable<int32_t>(Variable_21010_Damage));
    }
    return node13;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(21010, 14) {
    pnode->resizeTrigger(PhaseNode_SetBool::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetInt>(PhaseNode_SetBool::TRIGGER_DONE, 15, PhaseNode_SetInt::FUNC_SET, &PhaseNode_SetInt::Set);
}

REGISTER_CREATE_SKILL_NODE(21010, 14) {
    auto node14 = GET_SKILL_NODE(14, PhaseNode_SetBool);
    if (node14 == nullptr) {
        node14 = new PhaseNode_SetBool(14, phase);
        node14->setName("EnableDmg");
        node14->setValue(false);
        CALL_REGISTER_SKILL_NODE(21010, 14, node14)
    }
    if (noInit == true) {
        return node14;
    }
    return node14;
}
//--------------------------------------------------------------------------------
// SetInt
//
REGISTER_REGISTER_SKILL_NODE(21010, 15) {
    pnode->resizeTrigger(PhaseNode_SetInt::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_SetInt::TRIGGER_DONE, 16, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(21010, 15) {
    auto node15 = GET_SKILL_NODE(15, PhaseNode_SetInt);
    if (node15 == nullptr) {
        node15 = new PhaseNode_SetInt(15, phase);
        node15->setName("Damage");
        node15->setValue(0);
        CALL_REGISTER_SKILL_NODE(21010, 15, node15)
    }
    if (noInit == true) {
        return node15;
    }
    return node15;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(21010, 16) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuff>(PhaseNode_PlayAnimation::TRIGGER_DONE, 30, PhaseNode_AddSkillBuff::FUNC_ADD, &PhaseNode_AddSkillBuff::Add);
}

REGISTER_CREATE_SKILL_NODE(21010, 16) {
    auto node16 = GET_SKILL_NODE(16, PhaseNode_PlayAnimation);
    if (node16 == nullptr) {
        node16 = new PhaseNode_PlayAnimation(16, phase);
        node16->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node16->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node16->setTarget(0U);
        node16->setAnimation("Hurt");
        node16->setParameter("");
        node16->setValue(false);
        CALL_REGISTER_SKILL_NODE(21010, 16, node16)
    }
    if (noInit == true) {
        return node16;
    }
    return node16;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(21010, 17) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlayEffect::TRIGGER_DONE, 32, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(21010, 17) {
    auto node17 = GET_SKILL_NODE(17, PhaseNode_PlayEffect);
    if (node17 == nullptr) {
        node17 = new PhaseNode_PlayEffect(17, phase);
        node17->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node17->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node17->setEffectID(210000);
        node17->setChangeColor(false);
        node17->setType(PhaseNode_PlayEffect::PlayEffect_Type::WithTarget);
        node17->getVars().reserve(5);
        node17->getVars().setVariable<uint64_t>(0, 0U);
        node17->getVars().setVariable<std::string>(1, "Hit");
        node17->getVars().setVariable<float>(2, .00f);
        node17->getVars().setVariable<float>(3, .00f);
        node17->getVars().setVariable<float>(4, .00f);
        node17->setRotation(.00f);
        node17->setScale(.00f);
        CALL_REGISTER_SKILL_NODE(21010, 17, node17)
    }
    if (noInit == true) {
        return node17;
    }
    return node17;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(21010, 18) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_Delay::TRIGGER_DONE, 19, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(21010, 18) {
    auto node18 = GET_SKILL_NODE(18, PhaseNode_Delay);
    if (node18 == nullptr) {
        node18 = new PhaseNode_Delay(18, phase);
        node18->setTime(.50f);
        CALL_REGISTER_SKILL_NODE(21010, 18, node18)
    }
    if (noInit == true) {
        return node18;
    }
    return node18;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(21010, 19) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RemoveSkillBuff>(PhaseNode_PlayAnimation::TRIGGER_DONE, 20, PhaseNode_RemoveSkillBuff::FUNC_REMOVE, &PhaseNode_RemoveSkillBuff::Remove);
}

REGISTER_CREATE_SKILL_NODE(21010, 19) {
    auto node19 = GET_SKILL_NODE(19, PhaseNode_PlayAnimation);
    if (node19 == nullptr) {
        node19 = new PhaseNode_PlayAnimation(19, phase);
        node19->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node19->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node19->setTarget(0U);
        node19->setAnimation("Idle");
        node19->setParameter("");
        node19->setValue(false);
        CALL_REGISTER_SKILL_NODE(21010, 19, node19)
    }
    if (noInit == true) {
        return node19;
    }
    return node19;
}
//--------------------------------------------------------------------------------
// RemoveSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(21010, 20) {
    pnode->resizeTrigger(PhaseNode_RemoveSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_RemoveSkillBuff::TRIGGER_DONE, 38, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(21010, 20) {
    auto node20 = GET_SKILL_NODE(20, PhaseNode_RemoveSkillBuff);
    if (node20 == nullptr) {
        node20 = new PhaseNode_RemoveSkillBuff(20, phase);
        node20->setBuffID(0U);
        node20->setBuffIDs({});
        node20->setConfigID(1);
        node20->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(21010, 20, node20)
    }
    if (noInit == true) {
        return node20;
    }
    return node20;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(21010, 21) {
}

REGISTER_CREATE_SKILL_NODE(21010, 21) {
    auto node21 = GET_SKILL_NODE(21, PhaseNode_SetBool);
    if (node21 == nullptr) {
        node21 = new PhaseNode_SetBool(21, phase);
        node21->setName("EnableDmg");
        node21->setValue(true);
        CALL_REGISTER_SKILL_NODE(21010, 21, node21)
    }
    if (noInit == true) {
        return node21;
    }
    return node21;
}
//--------------------------------------------------------------------------------
// IntOperation
//
REGISTER_REGISTER_SKILL_NODE(21010, 23) {
    pnode->resizeTrigger(PhaseNode_IntOperation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetInt>(PhaseNode_IntOperation::TRIGGER_DONE, 24, PhaseNode_SetInt::FUNC_SET, &PhaseNode_SetInt::Set);
}

REGISTER_CREATE_SKILL_NODE(21010, 23) {
    auto node23 = GET_SKILL_NODE(23, PhaseNode_IntOperation);
    if (node23 == nullptr) {
        node23 = new PhaseNode_IntOperation(23, phase);
        node23->setMethod(PhaseNode_IntOperation::IntOperation_Method::Add);
        CALL_REGISTER_SKILL_NODE(21010, 23, node23)
    }
    if (noInit == true) {
        return node23;
    }
    auto variables = node23->getVariables();
    if (variables != nullptr) {
        node23->setBase(variables->getVariable<int32_t>(Variable_21010_Damage));
    }
    auto node41 = GET_SKILL_NODE(41, PhaseNode_Detect);
    if (node41 != nullptr) node23->setValue(node41->getVars().getVariable<int32_t>(0));
    return node23;
}
//--------------------------------------------------------------------------------
// SetInt
//
REGISTER_REGISTER_SKILL_NODE(21010, 24) {
    pnode->resizeTrigger(PhaseNode_SetInt::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareInt>(PhaseNode_SetInt::TRIGGER_DONE, 13, PhaseNode_CompareInt::FUNC_COMPARE, &PhaseNode_CompareInt::Compare);
}

REGISTER_CREATE_SKILL_NODE(21010, 24) {
    auto node24 = GET_SKILL_NODE(24, PhaseNode_SetInt);
    if (node24 == nullptr) {
        node24 = new PhaseNode_SetInt(24, phase);
        node24->setName("Damage");
        CALL_REGISTER_SKILL_NODE(21010, 24, node24)
    }
    if (noInit == true) {
        return node24;
    }
    auto node23 = GET_SKILL_NODE(23, PhaseNode_IntOperation);
    if (node23 != nullptr) node24->setValue(node23->getFinal());
    return node24;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(21010, 26) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareInt>(PhaseNode_If::TRIGGER_TRUE, 31, PhaseNode_CompareInt::FUNC_COMPARE, &PhaseNode_CompareInt::Compare);
}

REGISTER_CREATE_SKILL_NODE(21010, 26) {
    auto node26 = GET_SKILL_NODE(26, PhaseNode_If);
    if (node26 == nullptr) {
        node26 = new PhaseNode_If(26, phase);
        CALL_REGISTER_SKILL_NODE(21010, 26, node26)
    }
    if (noInit == true) {
        return node26;
    }
    auto variables = node26->getVariables();
    if (variables != nullptr) {
        node26->setCondition(variables->getVariable<bool>(Variable_21010_EnableDmg));
    }
    return node26;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(21010, 27) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_Delay::TRIGGER_DONE, 21, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(21010, 27) {
    auto node27 = GET_SKILL_NODE(27, PhaseNode_Delay);
    if (node27 == nullptr) {
        node27 = new PhaseNode_Delay(27, phase);
        node27->setTime(.20f);
        CALL_REGISTER_SKILL_NODE(21010, 27, node27)
    }
    if (noInit == true) {
        return node27;
    }
    return node27;
}
//--------------------------------------------------------------------------------
// AddSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(21010, 30) {
    pnode->resizeTrigger(PhaseNode_AddSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_AddSkillBuff::TRIGGER_DONE, 18, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(21010, 30) {
    auto node30 = GET_SKILL_NODE(30, PhaseNode_AddSkillBuff);
    if (node30 == nullptr) {
        node30 = new PhaseNode_AddSkillBuff(30, phase);
        node30->setConfigID(1);
        node30->setConfigIDs({});
        node30->setTarget(0U);
        node30->setAttribute({{}});
        CALL_REGISTER_SKILL_NODE(21010, 30, node30)
    }
    if (noInit == true) {
        return node30;
    }
    return node30;
}
//--------------------------------------------------------------------------------
// CompareInt
//
REGISTER_REGISTER_SKILL_NODE(21010, 31) {
    pnode->resizeTrigger(PhaseNode_CompareInt::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_IntOperation>(PhaseNode_CompareInt::TRIGGER_EQUAL, 23, PhaseNode_IntOperation::FUNC_OPERATION, &PhaseNode_IntOperation::Operation);
    pnode->regTrigger<PhaseNode_IntOperation>(PhaseNode_CompareInt::TRIGGER_GREATER, 23, PhaseNode_IntOperation::FUNC_OPERATION, &PhaseNode_IntOperation::Operation);
}

REGISTER_CREATE_SKILL_NODE(21010, 31) {
    auto node31 = GET_SKILL_NODE(31, PhaseNode_CompareInt);
    if (node31 == nullptr) {
        node31 = new PhaseNode_CompareInt(31, phase);
        node31->setB(5);
        CALL_REGISTER_SKILL_NODE(21010, 31, node31)
    }
    if (noInit == true) {
        return node31;
    }
    auto node41 = GET_SKILL_NODE(41, PhaseNode_Detect);
    if (node41 != nullptr) node31->setA(node41->getVars().getVariable<int32_t>(0));
    return node31;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(21010, 32) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_Delay::TRIGGER_DONE, 37, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(21010, 32) {
    auto node32 = GET_SKILL_NODE(32, PhaseNode_Delay);
    if (node32 == nullptr) {
        node32 = new PhaseNode_Delay(32, phase);
        node32->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(21010, 32, node32)
    }
    if (noInit == true) {
        return node32;
    }
    return node32;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(21010, 34) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_If::TRIGGER_TRUE, 36, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(21010, 34) {
    auto node34 = GET_SKILL_NODE(34, PhaseNode_If);
    if (node34 == nullptr) {
        node34 = new PhaseNode_If(34, phase);
        CALL_REGISTER_SKILL_NODE(21010, 34, node34)
    }
    if (noInit == true) {
        return node34;
    }
    auto variables = node34->getVariables();
    if (variables != nullptr) {
        node34->setCondition(variables->getVariable<bool>(Variable_21010_Effect));
    }
    return node34;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(21010, 36) {
    pnode->resizeTrigger(PhaseNode_SetBool::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_SetBool::TRIGGER_DONE, 17, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(21010, 36) {
    auto node36 = GET_SKILL_NODE(36, PhaseNode_SetBool);
    if (node36 == nullptr) {
        node36 = new PhaseNode_SetBool(36, phase);
        node36->setName("Effect");
        node36->setValue(false);
        CALL_REGISTER_SKILL_NODE(21010, 36, node36)
    }
    if (noInit == true) {
        return node36;
    }
    return node36;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(21010, 37) {
}

REGISTER_CREATE_SKILL_NODE(21010, 37) {
    auto node37 = GET_SKILL_NODE(37, PhaseNode_SetBool);
    if (node37 == nullptr) {
        node37 = new PhaseNode_SetBool(37, phase);
        node37->setName("Effect");
        node37->setValue(true);
        CALL_REGISTER_SKILL_NODE(21010, 37, node37)
    }
    if (noInit == true) {
        return node37;
    }
    return node37;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(21010, 38) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 21, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_GREATER, 27, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(21010, 38) {
    auto node38 = GET_SKILL_NODE(38, PhaseNode_CompareFloat);
    if (node38 == nullptr) {
        node38 = new PhaseNode_CompareFloat(38, phase);
        node38->setA(.20f);
        node38->setB(.00f);
        CALL_REGISTER_SKILL_NODE(21010, 38, node38)
    }
    if (noInit == true) {
        return node38;
    }
    return node38;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(21010, 39) {
}

REGISTER_CREATE_SKILL_NODE(21010, 39) {
    auto node39 = GET_SKILL_NODE(39, PhaseNode_SkillEndNotify);
    if (node39 == nullptr) {
        node39 = new PhaseNode_SkillEndNotify(39, phase);
        node39->setReturnType(true);
        CALL_REGISTER_SKILL_NODE(21010, 39, node39)
    }
    if (noInit == true) {
        return node39;
    }
    return node39;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(21010, 40) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_RaiseEvent::TRIGGER_DONE, 39, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
}

REGISTER_CREATE_SKILL_NODE(21010, 40) {
    auto node40 = GET_SKILL_NODE(40, PhaseNode_RaiseEvent);
    if (node40 == nullptr) {
        node40 = new PhaseNode_RaiseEvent(40, phase);
        node40->setEvent("GetDamage");
        node40->setTarget(0U);
        node40->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node40->setTypeParams(0, 0);
        node40->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(21010, 40, node40)
    }
    if (noInit == true) {
        return node40;
    }
    return node40;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(21010, 41) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_Detect::TRIGGER_ON, 26, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_Detect::TRIGGER_ON, 34, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(21010, 41) {
    auto node41 = GET_SKILL_NODE(41, PhaseNode_Detect);
    if (node41 == nullptr) {
        node41 = new PhaseNode_Detect(41, phase);
        node41->setSelf(0U);
        node41->setEvent("GetDamage");
        node41->setType(PhaseNode_Detect::Detect_Type::Damage);
        node41->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(21010, 41, node41)
    }
    if (noInit == true) {
        return node41;
    }
    return node41;
}

//--------------------------------------------------------------------------------
// SkillCreator_21010
//
class SkillCreator_21010 : public SkillCreator {
public:
    SkillCreator_21010() {}
    virtual ~SkillCreator_21010() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_21010

//--------------------------------------------------------------------------------
// SkillPhase_21010
//
class SkillPhase_21010 : public SkillPhase {
public:
    SkillPhase_21010(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_21010() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(21010, 11) // StartPhase
        CASE_CREATE_SKILL_NODE(21010, 13) // CompareInt
        CASE_CREATE_SKILL_NODE(21010, 14) // SetBool
        CASE_CREATE_SKILL_NODE(21010, 15) // SetInt
        CASE_CREATE_SKILL_NODE(21010, 16) // PlayAnimation
        CASE_CREATE_SKILL_NODE(21010, 17) // PlayEffect
        CASE_CREATE_SKILL_NODE(21010, 18) // Delay
        CASE_CREATE_SKILL_NODE(21010, 19) // PlayAnimation
        CASE_CREATE_SKILL_NODE(21010, 20) // RemoveSkillBuff
        CASE_CREATE_SKILL_NODE(21010, 21) // SetBool
        CASE_CREATE_SKILL_NODE(21010, 23) // IntOperation
        CASE_CREATE_SKILL_NODE(21010, 24) // SetInt
        CASE_CREATE_SKILL_NODE(21010, 26) // If
        CASE_CREATE_SKILL_NODE(21010, 27) // Delay
        CASE_CREATE_SKILL_NODE(21010, 30) // AddSkillBuff
        CASE_CREATE_SKILL_NODE(21010, 31) // CompareInt
        CASE_CREATE_SKILL_NODE(21010, 32) // Delay
        CASE_CREATE_SKILL_NODE(21010, 34) // If
        CASE_CREATE_SKILL_NODE(21010, 36) // SetBool
        CASE_CREATE_SKILL_NODE(21010, 37) // SetBool
        CASE_CREATE_SKILL_NODE(21010, 38) // CompareFloat
        CASE_CREATE_SKILL_NODE(21010, 39) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(21010, 40) // RaiseEvent
        CASE_CREATE_SKILL_NODE(21010, 41) // Detect
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_21010

SkillLogic* SkillCreator_21010::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //设置变量
    Variable_21010_Damage = logic->getVariables().setVariable<int32_t>("Damage");
    Variable_21010_EnableDmg = logic->getVariables().setVariable<bool>("EnableDmg", true);
    Variable_21010_Effect = logic->getVariables().setVariable<bool>("Effect", true);
    //创建阶段phase
    auto phase = new SkillPhase_21010(1, logic, 2);
    //设置phase执行器
    phase->setRunPhaseNode(1, 11);
    phase->setDetectPhaseNode(2, 41);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_21010::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
