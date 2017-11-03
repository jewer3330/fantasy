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
uint64_t Variable_22010_Damage = 0;
uint64_t Variable_22010_EnableDmg = 0;
uint64_t Variable_22010_Effect = 0;
//--------------------------------------------------------------------------------
// StartPhase
//
REGISTER_REGISTER_SKILL_NODE(22010, 9) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_StartPhase::TRIGGER_START, 125, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(22010, 9) {
    auto node9 = GET_SKILL_NODE(9, PhaseNode_StartPhase);
    if (node9 == nullptr) {
        node9 = new PhaseNode_StartPhase(9, phase);
        CALL_REGISTER_SKILL_NODE(22010, 9, node9)
    }
    if (noInit == true) {
        return node9;
    }
    return node9;
}
//--------------------------------------------------------------------------------
// CompareInt
//
REGISTER_REGISTER_SKILL_NODE(22010, 98) {
    pnode->resizeTrigger(PhaseNode_CompareInt::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_CompareInt::TRIGGER_EQUAL, 99, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_CompareInt::TRIGGER_GREATER, 99, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(22010, 98) {
    auto node98 = GET_SKILL_NODE(98, PhaseNode_CompareInt);
    if (node98 == nullptr) {
        node98 = new PhaseNode_CompareInt(98, phase);
        node98->setB(60);
        CALL_REGISTER_SKILL_NODE(22010, 98, node98)
    }
    if (noInit == true) {
        return node98;
    }
    auto variables = node98->getVariables();
    if (variables != nullptr) {
        node98->setA(variables->getVariable<int32_t>(Variable_22010_Damage));
    }
    return node98;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(22010, 99) {
    pnode->resizeTrigger(PhaseNode_SetBool::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetInt>(PhaseNode_SetBool::TRIGGER_DONE, 100, PhaseNode_SetInt::FUNC_SET, &PhaseNode_SetInt::Set);
}

REGISTER_CREATE_SKILL_NODE(22010, 99) {
    auto node99 = GET_SKILL_NODE(99, PhaseNode_SetBool);
    if (node99 == nullptr) {
        node99 = new PhaseNode_SetBool(99, phase);
        node99->setName("EnableDmg");
        node99->setValue(false);
        CALL_REGISTER_SKILL_NODE(22010, 99, node99)
    }
    if (noInit == true) {
        return node99;
    }
    return node99;
}
//--------------------------------------------------------------------------------
// SetInt
//
REGISTER_REGISTER_SKILL_NODE(22010, 100) {
    pnode->resizeTrigger(PhaseNode_SetInt::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_SetInt::TRIGGER_DONE, 101, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(22010, 100) {
    auto node100 = GET_SKILL_NODE(100, PhaseNode_SetInt);
    if (node100 == nullptr) {
        node100 = new PhaseNode_SetInt(100, phase);
        node100->setName("Damage");
        node100->setValue(0);
        CALL_REGISTER_SKILL_NODE(22010, 100, node100)
    }
    if (noInit == true) {
        return node100;
    }
    return node100;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(22010, 101) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuff>(PhaseNode_PlayAnimation::TRIGGER_DONE, 115, PhaseNode_AddSkillBuff::FUNC_ADD, &PhaseNode_AddSkillBuff::Add);
}

REGISTER_CREATE_SKILL_NODE(22010, 101) {
    auto node101 = GET_SKILL_NODE(101, PhaseNode_PlayAnimation);
    if (node101 == nullptr) {
        node101 = new PhaseNode_PlayAnimation(101, phase);
        node101->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node101->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node101->setTarget(0U);
        node101->setAnimation("Hurt");
        node101->setParameter("");
        node101->setValue(false);
        CALL_REGISTER_SKILL_NODE(22010, 101, node101)
    }
    if (noInit == true) {
        return node101;
    }
    return node101;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(22010, 102) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlayEffect::TRIGGER_DONE, 117, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(22010, 102) {
    auto node102 = GET_SKILL_NODE(102, PhaseNode_PlayEffect);
    if (node102 == nullptr) {
        node102 = new PhaseNode_PlayEffect(102, phase);
        node102->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node102->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node102->setEffectID(0);
        node102->setChangeColor(false);
        node102->setType(PhaseNode_PlayEffect::PlayEffect_Type::WithTarget);
        node102->getVars().reserve(5);
        node102->getVars().setVariable<uint64_t>(0, 0U);
        node102->getVars().setVariable<std::string>(1, "");
        node102->getVars().setVariable<float>(2, .00f);
        node102->getVars().setVariable<float>(3, .00f);
        node102->getVars().setVariable<float>(4, .00f);
        node102->setRotation(.00f);
        node102->setScale(.00f);
        CALL_REGISTER_SKILL_NODE(22010, 102, node102)
    }
    if (noInit == true) {
        return node102;
    }
    return node102;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22010, 103) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_Delay::TRIGGER_DONE, 104, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(22010, 103) {
    auto node103 = GET_SKILL_NODE(103, PhaseNode_Delay);
    if (node103 == nullptr) {
        node103 = new PhaseNode_Delay(103, phase);
        node103->setTime(.70f);
        CALL_REGISTER_SKILL_NODE(22010, 103, node103)
    }
    if (noInit == true) {
        return node103;
    }
    return node103;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(22010, 104) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RemoveSkillBuff>(PhaseNode_PlayAnimation::TRIGGER_DONE, 105, PhaseNode_RemoveSkillBuff::FUNC_REMOVE, &PhaseNode_RemoveSkillBuff::Remove);
}

REGISTER_CREATE_SKILL_NODE(22010, 104) {
    auto node104 = GET_SKILL_NODE(104, PhaseNode_PlayAnimation);
    if (node104 == nullptr) {
        node104 = new PhaseNode_PlayAnimation(104, phase);
        node104->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node104->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node104->setTarget(0U);
        node104->setAnimation("Idle");
        node104->setParameter("");
        node104->setValue(false);
        CALL_REGISTER_SKILL_NODE(22010, 104, node104)
    }
    if (noInit == true) {
        return node104;
    }
    return node104;
}
//--------------------------------------------------------------------------------
// RemoveSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(22010, 105) {
    pnode->resizeTrigger(PhaseNode_RemoveSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_RemoveSkillBuff::TRIGGER_DONE, 123, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(22010, 105) {
    auto node105 = GET_SKILL_NODE(105, PhaseNode_RemoveSkillBuff);
    if (node105 == nullptr) {
        node105 = new PhaseNode_RemoveSkillBuff(105, phase);
        node105->setBuffID(0U);
        node105->setBuffIDs({});
        node105->setConfigID(1);
        node105->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(22010, 105, node105)
    }
    if (noInit == true) {
        return node105;
    }
    return node105;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(22010, 106) {
}

REGISTER_CREATE_SKILL_NODE(22010, 106) {
    auto node106 = GET_SKILL_NODE(106, PhaseNode_SetBool);
    if (node106 == nullptr) {
        node106 = new PhaseNode_SetBool(106, phase);
        node106->setName("EnableDmg");
        node106->setValue(true);
        CALL_REGISTER_SKILL_NODE(22010, 106, node106)
    }
    if (noInit == true) {
        return node106;
    }
    return node106;
}
//--------------------------------------------------------------------------------
// IntOperation
//
REGISTER_REGISTER_SKILL_NODE(22010, 108) {
    pnode->resizeTrigger(PhaseNode_IntOperation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetInt>(PhaseNode_IntOperation::TRIGGER_DONE, 109, PhaseNode_SetInt::FUNC_SET, &PhaseNode_SetInt::Set);
}

REGISTER_CREATE_SKILL_NODE(22010, 108) {
    auto node108 = GET_SKILL_NODE(108, PhaseNode_IntOperation);
    if (node108 == nullptr) {
        node108 = new PhaseNode_IntOperation(108, phase);
        node108->setMethod(PhaseNode_IntOperation::IntOperation_Method::Add);
        CALL_REGISTER_SKILL_NODE(22010, 108, node108)
    }
    if (noInit == true) {
        return node108;
    }
    auto variables = node108->getVariables();
    if (variables != nullptr) {
        node108->setBase(variables->getVariable<int32_t>(Variable_22010_Damage));
    }
    auto node126 = GET_SKILL_NODE(126, PhaseNode_Detect);
    if (node126 != nullptr) node108->setValue(node126->getVars().getVariable<int32_t>(0));
    return node108;
}
//--------------------------------------------------------------------------------
// SetInt
//
REGISTER_REGISTER_SKILL_NODE(22010, 109) {
    pnode->resizeTrigger(PhaseNode_SetInt::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareInt>(PhaseNode_SetInt::TRIGGER_DONE, 98, PhaseNode_CompareInt::FUNC_COMPARE, &PhaseNode_CompareInt::Compare);
}

REGISTER_CREATE_SKILL_NODE(22010, 109) {
    auto node109 = GET_SKILL_NODE(109, PhaseNode_SetInt);
    if (node109 == nullptr) {
        node109 = new PhaseNode_SetInt(109, phase);
        node109->setName("Damage");
        CALL_REGISTER_SKILL_NODE(22010, 109, node109)
    }
    if (noInit == true) {
        return node109;
    }
    auto node108 = GET_SKILL_NODE(108, PhaseNode_IntOperation);
    if (node108 != nullptr) node109->setValue(node108->getFinal());
    return node109;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(22010, 111) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareInt>(PhaseNode_If::TRIGGER_TRUE, 116, PhaseNode_CompareInt::FUNC_COMPARE, &PhaseNode_CompareInt::Compare);
}

REGISTER_CREATE_SKILL_NODE(22010, 111) {
    auto node111 = GET_SKILL_NODE(111, PhaseNode_If);
    if (node111 == nullptr) {
        node111 = new PhaseNode_If(111, phase);
        CALL_REGISTER_SKILL_NODE(22010, 111, node111)
    }
    if (noInit == true) {
        return node111;
    }
    auto variables = node111->getVariables();
    if (variables != nullptr) {
        node111->setCondition(variables->getVariable<bool>(Variable_22010_EnableDmg));
    }
    return node111;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22010, 112) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_Delay::TRIGGER_DONE, 106, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(22010, 112) {
    auto node112 = GET_SKILL_NODE(112, PhaseNode_Delay);
    if (node112 == nullptr) {
        node112 = new PhaseNode_Delay(112, phase);
        node112->setTime(1.00f);
        CALL_REGISTER_SKILL_NODE(22010, 112, node112)
    }
    if (noInit == true) {
        return node112;
    }
    return node112;
}
//--------------------------------------------------------------------------------
// AddSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(22010, 115) {
    pnode->resizeTrigger(PhaseNode_AddSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_AddSkillBuff::TRIGGER_DONE, 103, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(22010, 115) {
    auto node115 = GET_SKILL_NODE(115, PhaseNode_AddSkillBuff);
    if (node115 == nullptr) {
        node115 = new PhaseNode_AddSkillBuff(115, phase);
        node115->setConfigID(1);
        node115->setConfigIDs({});
        node115->setTarget(0U);
        node115->setAttribute({{}});
        CALL_REGISTER_SKILL_NODE(22010, 115, node115)
    }
    if (noInit == true) {
        return node115;
    }
    return node115;
}
//--------------------------------------------------------------------------------
// CompareInt
//
REGISTER_REGISTER_SKILL_NODE(22010, 116) {
    pnode->resizeTrigger(PhaseNode_CompareInt::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_IntOperation>(PhaseNode_CompareInt::TRIGGER_EQUAL, 108, PhaseNode_IntOperation::FUNC_OPERATION, &PhaseNode_IntOperation::Operation);
    pnode->regTrigger<PhaseNode_IntOperation>(PhaseNode_CompareInt::TRIGGER_GREATER, 108, PhaseNode_IntOperation::FUNC_OPERATION, &PhaseNode_IntOperation::Operation);
}

REGISTER_CREATE_SKILL_NODE(22010, 116) {
    auto node116 = GET_SKILL_NODE(116, PhaseNode_CompareInt);
    if (node116 == nullptr) {
        node116 = new PhaseNode_CompareInt(116, phase);
        node116->setB(10);
        CALL_REGISTER_SKILL_NODE(22010, 116, node116)
    }
    if (noInit == true) {
        return node116;
    }
    auto node126 = GET_SKILL_NODE(126, PhaseNode_Detect);
    if (node126 != nullptr) node116->setA(node126->getVars().getVariable<int32_t>(0));
    return node116;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22010, 117) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_Delay::TRIGGER_DONE, 122, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(22010, 117) {
    auto node117 = GET_SKILL_NODE(117, PhaseNode_Delay);
    if (node117 == nullptr) {
        node117 = new PhaseNode_Delay(117, phase);
        node117->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(22010, 117, node117)
    }
    if (noInit == true) {
        return node117;
    }
    return node117;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(22010, 119) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_If::TRIGGER_TRUE, 121, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(22010, 119) {
    auto node119 = GET_SKILL_NODE(119, PhaseNode_If);
    if (node119 == nullptr) {
        node119 = new PhaseNode_If(119, phase);
        CALL_REGISTER_SKILL_NODE(22010, 119, node119)
    }
    if (noInit == true) {
        return node119;
    }
    auto variables = node119->getVariables();
    if (variables != nullptr) {
        node119->setCondition(variables->getVariable<bool>(Variable_22010_Effect));
    }
    return node119;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(22010, 121) {
    pnode->resizeTrigger(PhaseNode_SetBool::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_SetBool::TRIGGER_DONE, 102, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(22010, 121) {
    auto node121 = GET_SKILL_NODE(121, PhaseNode_SetBool);
    if (node121 == nullptr) {
        node121 = new PhaseNode_SetBool(121, phase);
        node121->setName("Effect");
        node121->setValue(false);
        CALL_REGISTER_SKILL_NODE(22010, 121, node121)
    }
    if (noInit == true) {
        return node121;
    }
    return node121;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(22010, 122) {
}

REGISTER_CREATE_SKILL_NODE(22010, 122) {
    auto node122 = GET_SKILL_NODE(122, PhaseNode_SetBool);
    if (node122 == nullptr) {
        node122 = new PhaseNode_SetBool(122, phase);
        node122->setName("Effect");
        node122->setValue(true);
        CALL_REGISTER_SKILL_NODE(22010, 122, node122)
    }
    if (noInit == true) {
        return node122;
    }
    return node122;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(22010, 123) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 106, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_GREATER, 112, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(22010, 123) {
    auto node123 = GET_SKILL_NODE(123, PhaseNode_CompareFloat);
    if (node123 == nullptr) {
        node123 = new PhaseNode_CompareFloat(123, phase);
        node123->setA(1.00f);
        node123->setB(.00f);
        CALL_REGISTER_SKILL_NODE(22010, 123, node123)
    }
    if (noInit == true) {
        return node123;
    }
    return node123;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(22010, 124) {
}

REGISTER_CREATE_SKILL_NODE(22010, 124) {
    auto node124 = GET_SKILL_NODE(124, PhaseNode_SkillEndNotify);
    if (node124 == nullptr) {
        node124 = new PhaseNode_SkillEndNotify(124, phase);
        node124->setReturnType(true);
        CALL_REGISTER_SKILL_NODE(22010, 124, node124)
    }
    if (noInit == true) {
        return node124;
    }
    return node124;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(22010, 125) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_RaiseEvent::TRIGGER_DONE, 124, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
}

REGISTER_CREATE_SKILL_NODE(22010, 125) {
    auto node125 = GET_SKILL_NODE(125, PhaseNode_RaiseEvent);
    if (node125 == nullptr) {
        node125 = new PhaseNode_RaiseEvent(125, phase);
        node125->setEvent("GetDamage");
        node125->setTarget(0U);
        node125->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node125->setTypeParams(0, 0);
        node125->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(22010, 125, node125)
    }
    if (noInit == true) {
        return node125;
    }
    return node125;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(22010, 126) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_Detect::TRIGGER_ON, 111, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_Detect::TRIGGER_ON, 119, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(22010, 126) {
    auto node126 = GET_SKILL_NODE(126, PhaseNode_Detect);
    if (node126 == nullptr) {
        node126 = new PhaseNode_Detect(126, phase);
        node126->setSelf(0U);
        node126->setEvent("GetDamage");
        node126->setType(PhaseNode_Detect::Detect_Type::Damage);
        node126->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(22010, 126, node126)
    }
    if (noInit == true) {
        return node126;
    }
    return node126;
}

//--------------------------------------------------------------------------------
// SkillCreator_22010
//
class SkillCreator_22010 : public SkillCreator {
public:
    SkillCreator_22010() {}
    virtual ~SkillCreator_22010() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_22010

//--------------------------------------------------------------------------------
// SkillPhase_22010
//
class SkillPhase_22010 : public SkillPhase {
public:
    SkillPhase_22010(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_22010() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(22010, 9) // StartPhase
        CASE_CREATE_SKILL_NODE(22010, 98) // CompareInt
        CASE_CREATE_SKILL_NODE(22010, 99) // SetBool
        CASE_CREATE_SKILL_NODE(22010, 100) // SetInt
        CASE_CREATE_SKILL_NODE(22010, 101) // PlayAnimation
        CASE_CREATE_SKILL_NODE(22010, 102) // PlayEffect
        CASE_CREATE_SKILL_NODE(22010, 103) // Delay
        CASE_CREATE_SKILL_NODE(22010, 104) // PlayAnimation
        CASE_CREATE_SKILL_NODE(22010, 105) // RemoveSkillBuff
        CASE_CREATE_SKILL_NODE(22010, 106) // SetBool
        CASE_CREATE_SKILL_NODE(22010, 108) // IntOperation
        CASE_CREATE_SKILL_NODE(22010, 109) // SetInt
        CASE_CREATE_SKILL_NODE(22010, 111) // If
        CASE_CREATE_SKILL_NODE(22010, 112) // Delay
        CASE_CREATE_SKILL_NODE(22010, 115) // AddSkillBuff
        CASE_CREATE_SKILL_NODE(22010, 116) // CompareInt
        CASE_CREATE_SKILL_NODE(22010, 117) // Delay
        CASE_CREATE_SKILL_NODE(22010, 119) // If
        CASE_CREATE_SKILL_NODE(22010, 121) // SetBool
        CASE_CREATE_SKILL_NODE(22010, 122) // SetBool
        CASE_CREATE_SKILL_NODE(22010, 123) // CompareFloat
        CASE_CREATE_SKILL_NODE(22010, 124) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(22010, 125) // RaiseEvent
        CASE_CREATE_SKILL_NODE(22010, 126) // Detect
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_22010

SkillLogic* SkillCreator_22010::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //设置变量
    Variable_22010_Damage = logic->getVariables().setVariable<int32_t>("Damage");
    Variable_22010_EnableDmg = logic->getVariables().setVariable<bool>("EnableDmg", true);
    Variable_22010_Effect = logic->getVariables().setVariable<bool>("Effect", true);
    //创建阶段phase
    auto phase = new SkillPhase_22010(1, logic, 2);
    //设置phase执行器
    phase->setRunPhaseNode(1, 9);
    phase->setDetectPhaseNode(2, 126);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_22010::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
