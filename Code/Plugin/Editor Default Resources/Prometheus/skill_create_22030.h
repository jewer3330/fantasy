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
uint64_t Variable_22030_Damage = 0;
uint64_t Variable_22030_EnableDmg = 0;
uint64_t Variable_22030_Effect = 0;
//--------------------------------------------------------------------------------
// StartPhase
//
REGISTER_REGISTER_SKILL_NODE(22030, 19) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_StartPhase::TRIGGER_START, 48, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(22030, 19) {
    auto node19 = GET_SKILL_NODE(19, PhaseNode_StartPhase);
    if (node19 == nullptr) {
        node19 = new PhaseNode_StartPhase(19, phase);
        CALL_REGISTER_SKILL_NODE(22030, 19, node19)
    }
    if (noInit == true) {
        return node19;
    }
    return node19;
}
//--------------------------------------------------------------------------------
// CompareInt
//
REGISTER_REGISTER_SKILL_NODE(22030, 21) {
    pnode->resizeTrigger(PhaseNode_CompareInt::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_CompareInt::TRIGGER_EQUAL, 22, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_CompareInt::TRIGGER_GREATER, 22, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(22030, 21) {
    auto node21 = GET_SKILL_NODE(21, PhaseNode_CompareInt);
    if (node21 == nullptr) {
        node21 = new PhaseNode_CompareInt(21, phase);
        node21->setB(60);
        CALL_REGISTER_SKILL_NODE(22030, 21, node21)
    }
    if (noInit == true) {
        return node21;
    }
    auto variables = node21->getVariables();
    if (variables != nullptr) {
        node21->setA(variables->getVariable<int32_t>(Variable_22030_Damage));
    }
    return node21;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(22030, 22) {
    pnode->resizeTrigger(PhaseNode_SetBool::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetInt>(PhaseNode_SetBool::TRIGGER_DONE, 23, PhaseNode_SetInt::FUNC_SET, &PhaseNode_SetInt::Set);
}

REGISTER_CREATE_SKILL_NODE(22030, 22) {
    auto node22 = GET_SKILL_NODE(22, PhaseNode_SetBool);
    if (node22 == nullptr) {
        node22 = new PhaseNode_SetBool(22, phase);
        node22->setName("EnableDmg");
        node22->setValue(false);
        CALL_REGISTER_SKILL_NODE(22030, 22, node22)
    }
    if (noInit == true) {
        return node22;
    }
    return node22;
}
//--------------------------------------------------------------------------------
// SetInt
//
REGISTER_REGISTER_SKILL_NODE(22030, 23) {
    pnode->resizeTrigger(PhaseNode_SetInt::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_SetInt::TRIGGER_DONE, 24, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(22030, 23) {
    auto node23 = GET_SKILL_NODE(23, PhaseNode_SetInt);
    if (node23 == nullptr) {
        node23 = new PhaseNode_SetInt(23, phase);
        node23->setName("Damage");
        node23->setValue(0);
        CALL_REGISTER_SKILL_NODE(22030, 23, node23)
    }
    if (noInit == true) {
        return node23;
    }
    return node23;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(22030, 24) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuff>(PhaseNode_PlayAnimation::TRIGGER_DONE, 38, PhaseNode_AddSkillBuff::FUNC_ADD, &PhaseNode_AddSkillBuff::Add);
}

REGISTER_CREATE_SKILL_NODE(22030, 24) {
    auto node24 = GET_SKILL_NODE(24, PhaseNode_PlayAnimation);
    if (node24 == nullptr) {
        node24 = new PhaseNode_PlayAnimation(24, phase);
        node24->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node24->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node24->setTarget(0U);
        node24->setAnimation("Hurt");
        node24->setParameter("");
        node24->setValue(false);
        CALL_REGISTER_SKILL_NODE(22030, 24, node24)
    }
    if (noInit == true) {
        return node24;
    }
    return node24;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(22030, 25) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlayEffect::TRIGGER_DONE, 40, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(22030, 25) {
    auto node25 = GET_SKILL_NODE(25, PhaseNode_PlayEffect);
    if (node25 == nullptr) {
        node25 = new PhaseNode_PlayEffect(25, phase);
        node25->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node25->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node25->setEffectID(0);
        node25->setChangeColor(false);
        node25->setType(PhaseNode_PlayEffect::PlayEffect_Type::WithTarget);
        node25->getVars().reserve(5);
        node25->getVars().setVariable<uint64_t>(0, 0U);
        node25->getVars().setVariable<std::string>(1, "");
        node25->getVars().setVariable<float>(2, .00f);
        node25->getVars().setVariable<float>(3, .00f);
        node25->getVars().setVariable<float>(4, .00f);
        node25->setRotation(.00f);
        node25->setScale(.00f);
        CALL_REGISTER_SKILL_NODE(22030, 25, node25)
    }
    if (noInit == true) {
        return node25;
    }
    return node25;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22030, 26) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_Delay::TRIGGER_DONE, 27, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(22030, 26) {
    auto node26 = GET_SKILL_NODE(26, PhaseNode_Delay);
    if (node26 == nullptr) {
        node26 = new PhaseNode_Delay(26, phase);
        node26->setTime(.60f);
        CALL_REGISTER_SKILL_NODE(22030, 26, node26)
    }
    if (noInit == true) {
        return node26;
    }
    return node26;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(22030, 27) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RemoveSkillBuff>(PhaseNode_PlayAnimation::TRIGGER_DONE, 28, PhaseNode_RemoveSkillBuff::FUNC_REMOVE, &PhaseNode_RemoveSkillBuff::Remove);
}

REGISTER_CREATE_SKILL_NODE(22030, 27) {
    auto node27 = GET_SKILL_NODE(27, PhaseNode_PlayAnimation);
    if (node27 == nullptr) {
        node27 = new PhaseNode_PlayAnimation(27, phase);
        node27->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node27->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node27->setTarget(0U);
        node27->setAnimation("Idle");
        node27->setParameter("");
        node27->setValue(false);
        CALL_REGISTER_SKILL_NODE(22030, 27, node27)
    }
    if (noInit == true) {
        return node27;
    }
    return node27;
}
//--------------------------------------------------------------------------------
// RemoveSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(22030, 28) {
    pnode->resizeTrigger(PhaseNode_RemoveSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_RemoveSkillBuff::TRIGGER_DONE, 46, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(22030, 28) {
    auto node28 = GET_SKILL_NODE(28, PhaseNode_RemoveSkillBuff);
    if (node28 == nullptr) {
        node28 = new PhaseNode_RemoveSkillBuff(28, phase);
        node28->setBuffID(0U);
        node28->setBuffIDs({});
        node28->setConfigID(1);
        node28->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(22030, 28, node28)
    }
    if (noInit == true) {
        return node28;
    }
    return node28;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(22030, 29) {
}

REGISTER_CREATE_SKILL_NODE(22030, 29) {
    auto node29 = GET_SKILL_NODE(29, PhaseNode_SetBool);
    if (node29 == nullptr) {
        node29 = new PhaseNode_SetBool(29, phase);
        node29->setName("EnableDmg");
        node29->setValue(true);
        CALL_REGISTER_SKILL_NODE(22030, 29, node29)
    }
    if (noInit == true) {
        return node29;
    }
    return node29;
}
//--------------------------------------------------------------------------------
// IntOperation
//
REGISTER_REGISTER_SKILL_NODE(22030, 31) {
    pnode->resizeTrigger(PhaseNode_IntOperation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetInt>(PhaseNode_IntOperation::TRIGGER_DONE, 32, PhaseNode_SetInt::FUNC_SET, &PhaseNode_SetInt::Set);
}

REGISTER_CREATE_SKILL_NODE(22030, 31) {
    auto node31 = GET_SKILL_NODE(31, PhaseNode_IntOperation);
    if (node31 == nullptr) {
        node31 = new PhaseNode_IntOperation(31, phase);
        node31->setMethod(PhaseNode_IntOperation::IntOperation_Method::Add);
        CALL_REGISTER_SKILL_NODE(22030, 31, node31)
    }
    if (noInit == true) {
        return node31;
    }
    auto variables = node31->getVariables();
    if (variables != nullptr) {
        node31->setBase(variables->getVariable<int32_t>(Variable_22030_Damage));
    }
    auto node49 = GET_SKILL_NODE(49, PhaseNode_Detect);
    if (node49 != nullptr) node31->setValue(node49->getVars().getVariable<int32_t>(0));
    return node31;
}
//--------------------------------------------------------------------------------
// SetInt
//
REGISTER_REGISTER_SKILL_NODE(22030, 32) {
    pnode->resizeTrigger(PhaseNode_SetInt::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareInt>(PhaseNode_SetInt::TRIGGER_DONE, 21, PhaseNode_CompareInt::FUNC_COMPARE, &PhaseNode_CompareInt::Compare);
}

REGISTER_CREATE_SKILL_NODE(22030, 32) {
    auto node32 = GET_SKILL_NODE(32, PhaseNode_SetInt);
    if (node32 == nullptr) {
        node32 = new PhaseNode_SetInt(32, phase);
        node32->setName("Damage");
        CALL_REGISTER_SKILL_NODE(22030, 32, node32)
    }
    if (noInit == true) {
        return node32;
    }
    auto node31 = GET_SKILL_NODE(31, PhaseNode_IntOperation);
    if (node31 != nullptr) node32->setValue(node31->getFinal());
    return node32;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(22030, 34) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareInt>(PhaseNode_If::TRIGGER_TRUE, 39, PhaseNode_CompareInt::FUNC_COMPARE, &PhaseNode_CompareInt::Compare);
}

REGISTER_CREATE_SKILL_NODE(22030, 34) {
    auto node34 = GET_SKILL_NODE(34, PhaseNode_If);
    if (node34 == nullptr) {
        node34 = new PhaseNode_If(34, phase);
        CALL_REGISTER_SKILL_NODE(22030, 34, node34)
    }
    if (noInit == true) {
        return node34;
    }
    auto variables = node34->getVariables();
    if (variables != nullptr) {
        node34->setCondition(variables->getVariable<bool>(Variable_22030_EnableDmg));
    }
    return node34;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22030, 35) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_Delay::TRIGGER_DONE, 29, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(22030, 35) {
    auto node35 = GET_SKILL_NODE(35, PhaseNode_Delay);
    if (node35 == nullptr) {
        node35 = new PhaseNode_Delay(35, phase);
        node35->setTime(1.00f);
        CALL_REGISTER_SKILL_NODE(22030, 35, node35)
    }
    if (noInit == true) {
        return node35;
    }
    return node35;
}
//--------------------------------------------------------------------------------
// AddSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(22030, 38) {
    pnode->resizeTrigger(PhaseNode_AddSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_AddSkillBuff::TRIGGER_DONE, 26, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(22030, 38) {
    auto node38 = GET_SKILL_NODE(38, PhaseNode_AddSkillBuff);
    if (node38 == nullptr) {
        node38 = new PhaseNode_AddSkillBuff(38, phase);
        node38->setConfigID(1);
        node38->setConfigIDs({});
        node38->setTarget(0U);
        node38->setAttribute({{}});
        CALL_REGISTER_SKILL_NODE(22030, 38, node38)
    }
    if (noInit == true) {
        return node38;
    }
    return node38;
}
//--------------------------------------------------------------------------------
// CompareInt
//
REGISTER_REGISTER_SKILL_NODE(22030, 39) {
    pnode->resizeTrigger(PhaseNode_CompareInt::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_IntOperation>(PhaseNode_CompareInt::TRIGGER_EQUAL, 31, PhaseNode_IntOperation::FUNC_OPERATION, &PhaseNode_IntOperation::Operation);
    pnode->regTrigger<PhaseNode_IntOperation>(PhaseNode_CompareInt::TRIGGER_GREATER, 31, PhaseNode_IntOperation::FUNC_OPERATION, &PhaseNode_IntOperation::Operation);
}

REGISTER_CREATE_SKILL_NODE(22030, 39) {
    auto node39 = GET_SKILL_NODE(39, PhaseNode_CompareInt);
    if (node39 == nullptr) {
        node39 = new PhaseNode_CompareInt(39, phase);
        node39->setB(10);
        CALL_REGISTER_SKILL_NODE(22030, 39, node39)
    }
    if (noInit == true) {
        return node39;
    }
    auto node49 = GET_SKILL_NODE(49, PhaseNode_Detect);
    if (node49 != nullptr) node39->setA(node49->getVars().getVariable<int32_t>(0));
    return node39;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22030, 40) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_Delay::TRIGGER_DONE, 45, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(22030, 40) {
    auto node40 = GET_SKILL_NODE(40, PhaseNode_Delay);
    if (node40 == nullptr) {
        node40 = new PhaseNode_Delay(40, phase);
        node40->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(22030, 40, node40)
    }
    if (noInit == true) {
        return node40;
    }
    return node40;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(22030, 42) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_If::TRIGGER_TRUE, 44, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(22030, 42) {
    auto node42 = GET_SKILL_NODE(42, PhaseNode_If);
    if (node42 == nullptr) {
        node42 = new PhaseNode_If(42, phase);
        CALL_REGISTER_SKILL_NODE(22030, 42, node42)
    }
    if (noInit == true) {
        return node42;
    }
    auto variables = node42->getVariables();
    if (variables != nullptr) {
        node42->setCondition(variables->getVariable<bool>(Variable_22030_Effect));
    }
    return node42;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(22030, 44) {
    pnode->resizeTrigger(PhaseNode_SetBool::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_SetBool::TRIGGER_DONE, 25, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(22030, 44) {
    auto node44 = GET_SKILL_NODE(44, PhaseNode_SetBool);
    if (node44 == nullptr) {
        node44 = new PhaseNode_SetBool(44, phase);
        node44->setName("Effect");
        node44->setValue(false);
        CALL_REGISTER_SKILL_NODE(22030, 44, node44)
    }
    if (noInit == true) {
        return node44;
    }
    return node44;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(22030, 45) {
}

REGISTER_CREATE_SKILL_NODE(22030, 45) {
    auto node45 = GET_SKILL_NODE(45, PhaseNode_SetBool);
    if (node45 == nullptr) {
        node45 = new PhaseNode_SetBool(45, phase);
        node45->setName("Effect");
        node45->setValue(true);
        CALL_REGISTER_SKILL_NODE(22030, 45, node45)
    }
    if (noInit == true) {
        return node45;
    }
    return node45;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(22030, 46) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 29, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_GREATER, 35, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(22030, 46) {
    auto node46 = GET_SKILL_NODE(46, PhaseNode_CompareFloat);
    if (node46 == nullptr) {
        node46 = new PhaseNode_CompareFloat(46, phase);
        node46->setA(1.00f);
        node46->setB(.00f);
        CALL_REGISTER_SKILL_NODE(22030, 46, node46)
    }
    if (noInit == true) {
        return node46;
    }
    return node46;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(22030, 47) {
}

REGISTER_CREATE_SKILL_NODE(22030, 47) {
    auto node47 = GET_SKILL_NODE(47, PhaseNode_SkillEndNotify);
    if (node47 == nullptr) {
        node47 = new PhaseNode_SkillEndNotify(47, phase);
        node47->setReturnType(true);
        CALL_REGISTER_SKILL_NODE(22030, 47, node47)
    }
    if (noInit == true) {
        return node47;
    }
    return node47;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(22030, 48) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_RaiseEvent::TRIGGER_DONE, 47, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
}

REGISTER_CREATE_SKILL_NODE(22030, 48) {
    auto node48 = GET_SKILL_NODE(48, PhaseNode_RaiseEvent);
    if (node48 == nullptr) {
        node48 = new PhaseNode_RaiseEvent(48, phase);
        node48->setEvent("GetDamage");
        node48->setTarget(0U);
        node48->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node48->setTypeParams(0, 0);
        node48->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(22030, 48, node48)
    }
    if (noInit == true) {
        return node48;
    }
    return node48;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(22030, 49) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_Detect::TRIGGER_ON, 34, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_Detect::TRIGGER_ON, 42, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(22030, 49) {
    auto node49 = GET_SKILL_NODE(49, PhaseNode_Detect);
    if (node49 == nullptr) {
        node49 = new PhaseNode_Detect(49, phase);
        node49->setSelf(0U);
        node49->setEvent("GetDamage");
        node49->setType(PhaseNode_Detect::Detect_Type::Damage);
        node49->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(22030, 49, node49)
    }
    if (noInit == true) {
        return node49;
    }
    return node49;
}

//--------------------------------------------------------------------------------
// SkillCreator_22030
//
class SkillCreator_22030 : public SkillCreator {
public:
    SkillCreator_22030() {}
    virtual ~SkillCreator_22030() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_22030

//--------------------------------------------------------------------------------
// SkillPhase_22030
//
class SkillPhase_22030 : public SkillPhase {
public:
    SkillPhase_22030(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_22030() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(22030, 19) // StartPhase
        CASE_CREATE_SKILL_NODE(22030, 21) // CompareInt
        CASE_CREATE_SKILL_NODE(22030, 22) // SetBool
        CASE_CREATE_SKILL_NODE(22030, 23) // SetInt
        CASE_CREATE_SKILL_NODE(22030, 24) // PlayAnimation
        CASE_CREATE_SKILL_NODE(22030, 25) // PlayEffect
        CASE_CREATE_SKILL_NODE(22030, 26) // Delay
        CASE_CREATE_SKILL_NODE(22030, 27) // PlayAnimation
        CASE_CREATE_SKILL_NODE(22030, 28) // RemoveSkillBuff
        CASE_CREATE_SKILL_NODE(22030, 29) // SetBool
        CASE_CREATE_SKILL_NODE(22030, 31) // IntOperation
        CASE_CREATE_SKILL_NODE(22030, 32) // SetInt
        CASE_CREATE_SKILL_NODE(22030, 34) // If
        CASE_CREATE_SKILL_NODE(22030, 35) // Delay
        CASE_CREATE_SKILL_NODE(22030, 38) // AddSkillBuff
        CASE_CREATE_SKILL_NODE(22030, 39) // CompareInt
        CASE_CREATE_SKILL_NODE(22030, 40) // Delay
        CASE_CREATE_SKILL_NODE(22030, 42) // If
        CASE_CREATE_SKILL_NODE(22030, 44) // SetBool
        CASE_CREATE_SKILL_NODE(22030, 45) // SetBool
        CASE_CREATE_SKILL_NODE(22030, 46) // CompareFloat
        CASE_CREATE_SKILL_NODE(22030, 47) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(22030, 48) // RaiseEvent
        CASE_CREATE_SKILL_NODE(22030, 49) // Detect
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_22030

SkillLogic* SkillCreator_22030::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //设置变量
    Variable_22030_Damage = logic->getVariables().setVariable<int32_t>("Damage");
    Variable_22030_EnableDmg = logic->getVariables().setVariable<bool>("EnableDmg", true);
    Variable_22030_Effect = logic->getVariables().setVariable<bool>("Effect", true);
    //创建阶段phase
    auto phase = new SkillPhase_22030(1, logic, 2);
    //设置phase执行器
    phase->setRunPhaseNode(1, 19);
    phase->setDetectPhaseNode(2, 49);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_22030::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
