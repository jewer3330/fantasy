#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

#include "skill_psnode_actorfilternewpene.h"
#include "skill_psnode_compareint.h"
#include "skill_psnode_getbuffattribute.h"
#include "skill_psnode_recordinnereffect.h"
#include "skill_psnode_turntoarray.h"
#include "skill_psnode_weapondetect.h"

namespace pvp {

//变量声明
//--------------------------------------------------------------------------------
// WeaponDetect
//
REGISTER_REGISTER_SKILL_NODE(133, 4) {
    pnode->resizeTrigger(PhaseNode_WeaponDetect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetBuffAttribute>(PhaseNode_WeaponDetect::TRIGGER_ON, 6, PhaseNode_GetBuffAttribute::FUNC_DO, &PhaseNode_GetBuffAttribute::Do);
    pnode->regTrigger<PhaseNode_TurnToArray>(PhaseNode_WeaponDetect::TRIGGER_ON, 13, PhaseNode_TurnToArray::FUNC_DO, &PhaseNode_TurnToArray::Do);
}

REGISTER_CREATE_SKILL_NODE(133, 4) {
    auto node4 = GET_SKILL_NODE(4, PhaseNode_WeaponDetect);
    if (node4 == nullptr) {
        node4 = new PhaseNode_WeaponDetect(4, phase);
        node4->setSelf(0U);
        node4->setEvent("");
        node4->setType(PhaseNode_WeaponDetect::WeaponDetect_Type::Weapon_Hit);
        CALL_REGISTER_SKILL_NODE(133, 4, node4)
    }
    if (noInit == true) {
        return node4;
    }
    return node4;
}
//--------------------------------------------------------------------------------
// GetBuffAttribute
//
REGISTER_REGISTER_SKILL_NODE(133, 6) {
    pnode->resizeTrigger(PhaseNode_GetBuffAttribute::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareInt>(PhaseNode_GetBuffAttribute::TRIGGER_DONE, 8, PhaseNode_CompareInt::FUNC_COMPARE, &PhaseNode_CompareInt::Compare);
}

REGISTER_CREATE_SKILL_NODE(133, 6) {
    auto node6 = GET_SKILL_NODE(6, PhaseNode_GetBuffAttribute);
    if (node6 == nullptr) {
        node6 = new PhaseNode_GetBuffAttribute(6, phase);
        node6->setAttribute(5);
        CALL_REGISTER_SKILL_NODE(133, 6, node6)
    }
    if (noInit == true) {
        return node6;
    }
    auto node4 = GET_SKILL_NODE(4, PhaseNode_WeaponDetect);
    if (node4 != nullptr) node6->setTarget(node4->getTypeParams(0));
    return node6;
}
//--------------------------------------------------------------------------------
// CompareInt
//
REGISTER_REGISTER_SKILL_NODE(133, 8) {
    pnode->resizeTrigger(PhaseNode_CompareInt::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RecordInnerEffect>(PhaseNode_CompareInt::TRIGGER_GREATER, 11, PhaseNode_RecordInnerEffect::FUNC_DO, &PhaseNode_RecordInnerEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(133, 8) {
    auto node8 = GET_SKILL_NODE(8, PhaseNode_CompareInt);
    if (node8 == nullptr) {
        node8 = new PhaseNode_CompareInt(8, phase);
        node8->setB(0);
        CALL_REGISTER_SKILL_NODE(133, 8, node8)
    }
    if (noInit == true) {
        return node8;
    }
    auto node6 = GET_SKILL_NODE(6, PhaseNode_GetBuffAttribute);
    if (node6 != nullptr) node8->setA(node6->getValue());
    return node8;
}
//--------------------------------------------------------------------------------
// RecordInnerEffect
//
REGISTER_REGISTER_SKILL_NODE(133, 11) {
}

REGISTER_CREATE_SKILL_NODE(133, 11) {
    auto node11 = GET_SKILL_NODE(11, PhaseNode_RecordInnerEffect);
    if (node11 == nullptr) {
        node11 = new PhaseNode_RecordInnerEffect(11, phase);
        node11->setEffect(3);
        CALL_REGISTER_SKILL_NODE(133, 11, node11)
    }
    if (noInit == true) {
        return node11;
    }
    return node11;
}
//--------------------------------------------------------------------------------
// TurnToArray
//
REGISTER_REGISTER_SKILL_NODE(133, 13) {
    pnode->resizeTrigger(PhaseNode_TurnToArray::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_TurnToArray::TRIGGER_DONE, 17, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(133, 13) {
    auto node13 = GET_SKILL_NODE(13, PhaseNode_TurnToArray);
    if (node13 == nullptr) {
        node13 = new PhaseNode_TurnToArray(13, phase);
        CALL_REGISTER_SKILL_NODE(133, 13, node13)
    }
    if (noInit == true) {
        return node13;
    }
    auto node4 = GET_SKILL_NODE(4, PhaseNode_WeaponDetect);
    if (node4 != nullptr) node13->setSingle(node4->getTypeParams(0));
    return node13;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(133, 17) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RecordInnerEffect>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 19, PhaseNode_RecordInnerEffect::FUNC_DO, &PhaseNode_RecordInnerEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(133, 17) {
    auto node17 = GET_SKILL_NODE(17, PhaseNode_ActorFilterNewPene);
    if (node17 == nullptr) {
        node17 = new PhaseNode_ActorFilterNewPene(17, phase);
        node17->setHero(false);
        node17->setMinion(false);
        node17->setDestruct(false);
        node17->setShield(true);
        node17->setTotalCount(0);
        node17->setPerCount(0);
        CALL_REGISTER_SKILL_NODE(133, 17, node17)
    }
    if (noInit == true) {
        return node17;
    }
    auto node13 = GET_SKILL_NODE(13, PhaseNode_TurnToArray);
    if (node13 != nullptr) node17->setInput(node13->getResult());
    return node17;
}
//--------------------------------------------------------------------------------
// RecordInnerEffect
//
REGISTER_REGISTER_SKILL_NODE(133, 19) {
}

REGISTER_CREATE_SKILL_NODE(133, 19) {
    auto node19 = GET_SKILL_NODE(19, PhaseNode_RecordInnerEffect);
    if (node19 == nullptr) {
        node19 = new PhaseNode_RecordInnerEffect(19, phase);
        node19->setEffect(6);
        CALL_REGISTER_SKILL_NODE(133, 19, node19)
    }
    if (noInit == true) {
        return node19;
    }
    return node19;
}

//--------------------------------------------------------------------------------
// SkillCreator_133
//
class SkillCreator_133 : public SkillCreator {
public:
    SkillCreator_133() {}
    virtual ~SkillCreator_133() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_133

//--------------------------------------------------------------------------------
// SkillPhase_133
//
class SkillPhase_133 : public SkillPhase {
public:
    SkillPhase_133(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_133() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(133, 4) // WeaponDetect
        CASE_CREATE_SKILL_NODE(133, 6) // GetBuffAttribute
        CASE_CREATE_SKILL_NODE(133, 8) // CompareInt
        CASE_CREATE_SKILL_NODE(133, 11) // RecordInnerEffect
        CASE_CREATE_SKILL_NODE(133, 13) // TurnToArray
        CASE_CREATE_SKILL_NODE(133, 17) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(133, 19) // RecordInnerEffect
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_133

SkillLogic* SkillCreator_133::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //创建阶段phase
    auto phase = new SkillPhase_133(1, logic, 1);
    //设置phase执行器
    phase->setRunPhaseNode(1, 4);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_133::getSkillExpend(int32_t& nType, int32_t& nValue) {
    nType = Skill::E_SkillExpend_PASSIVITY;
    return true;
}
} // namespace pvp
