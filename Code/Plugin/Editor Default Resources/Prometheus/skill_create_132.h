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
REGISTER_REGISTER_SKILL_NODE(132, 3) {
    pnode->resizeTrigger(PhaseNode_WeaponDetect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetBuffAttribute>(PhaseNode_WeaponDetect::TRIGGER_ON, 5, PhaseNode_GetBuffAttribute::FUNC_DO, &PhaseNode_GetBuffAttribute::Do);
    pnode->regTrigger<PhaseNode_TurnToArray>(PhaseNode_WeaponDetect::TRIGGER_ON, 11, PhaseNode_TurnToArray::FUNC_DO, &PhaseNode_TurnToArray::Do);
}

REGISTER_CREATE_SKILL_NODE(132, 3) {
    auto node3 = GET_SKILL_NODE(3, PhaseNode_WeaponDetect);
    if (node3 == nullptr) {
        node3 = new PhaseNode_WeaponDetect(3, phase);
        node3->setSelf(0U);
        node3->setEvent("");
        node3->setType(PhaseNode_WeaponDetect::WeaponDetect_Type::Weapon_Hit);
        CALL_REGISTER_SKILL_NODE(132, 3, node3)
    }
    if (noInit == true) {
        return node3;
    }
    return node3;
}
//--------------------------------------------------------------------------------
// GetBuffAttribute
//
REGISTER_REGISTER_SKILL_NODE(132, 5) {
    pnode->resizeTrigger(PhaseNode_GetBuffAttribute::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareInt>(PhaseNode_GetBuffAttribute::TRIGGER_DONE, 7, PhaseNode_CompareInt::FUNC_COMPARE, &PhaseNode_CompareInt::Compare);
}

REGISTER_CREATE_SKILL_NODE(132, 5) {
    auto node5 = GET_SKILL_NODE(5, PhaseNode_GetBuffAttribute);
    if (node5 == nullptr) {
        node5 = new PhaseNode_GetBuffAttribute(5, phase);
        node5->setAttribute(5);
        CALL_REGISTER_SKILL_NODE(132, 5, node5)
    }
    if (noInit == true) {
        return node5;
    }
    auto node3 = GET_SKILL_NODE(3, PhaseNode_WeaponDetect);
    if (node3 != nullptr) node5->setTarget(node3->getTypeParams(0));
    return node5;
}
//--------------------------------------------------------------------------------
// CompareInt
//
REGISTER_REGISTER_SKILL_NODE(132, 7) {
    pnode->resizeTrigger(PhaseNode_CompareInt::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RecordInnerEffect>(PhaseNode_CompareInt::TRIGGER_GREATER, 9, PhaseNode_RecordInnerEffect::FUNC_DO, &PhaseNode_RecordInnerEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(132, 7) {
    auto node7 = GET_SKILL_NODE(7, PhaseNode_CompareInt);
    if (node7 == nullptr) {
        node7 = new PhaseNode_CompareInt(7, phase);
        node7->setB(0);
        CALL_REGISTER_SKILL_NODE(132, 7, node7)
    }
    if (noInit == true) {
        return node7;
    }
    auto node5 = GET_SKILL_NODE(5, PhaseNode_GetBuffAttribute);
    if (node5 != nullptr) node7->setA(node5->getValue());
    return node7;
}
//--------------------------------------------------------------------------------
// RecordInnerEffect
//
REGISTER_REGISTER_SKILL_NODE(132, 9) {
}

REGISTER_CREATE_SKILL_NODE(132, 9) {
    auto node9 = GET_SKILL_NODE(9, PhaseNode_RecordInnerEffect);
    if (node9 == nullptr) {
        node9 = new PhaseNode_RecordInnerEffect(9, phase);
        node9->setEffect(2);
        CALL_REGISTER_SKILL_NODE(132, 9, node9)
    }
    if (noInit == true) {
        return node9;
    }
    return node9;
}
//--------------------------------------------------------------------------------
// TurnToArray
//
REGISTER_REGISTER_SKILL_NODE(132, 11) {
    pnode->resizeTrigger(PhaseNode_TurnToArray::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_TurnToArray::TRIGGER_DONE, 14, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(132, 11) {
    auto node11 = GET_SKILL_NODE(11, PhaseNode_TurnToArray);
    if (node11 == nullptr) {
        node11 = new PhaseNode_TurnToArray(11, phase);
        CALL_REGISTER_SKILL_NODE(132, 11, node11)
    }
    if (noInit == true) {
        return node11;
    }
    auto node3 = GET_SKILL_NODE(3, PhaseNode_WeaponDetect);
    if (node3 != nullptr) node11->setSingle(node3->getTypeParams(0));
    return node11;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(132, 14) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RecordInnerEffect>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 17, PhaseNode_RecordInnerEffect::FUNC_DO, &PhaseNode_RecordInnerEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(132, 14) {
    auto node14 = GET_SKILL_NODE(14, PhaseNode_ActorFilterNewPene);
    if (node14 == nullptr) {
        node14 = new PhaseNode_ActorFilterNewPene(14, phase);
        node14->setHero(false);
        node14->setMinion(false);
        node14->setDestruct(false);
        node14->setShield(true);
        node14->setTotalCount(0);
        node14->setPerCount(0);
        CALL_REGISTER_SKILL_NODE(132, 14, node14)
    }
    if (noInit == true) {
        return node14;
    }
    auto node11 = GET_SKILL_NODE(11, PhaseNode_TurnToArray);
    if (node11 != nullptr) node14->setInput(node11->getResult());
    return node14;
}
//--------------------------------------------------------------------------------
// RecordInnerEffect
//
REGISTER_REGISTER_SKILL_NODE(132, 17) {
}

REGISTER_CREATE_SKILL_NODE(132, 17) {
    auto node17 = GET_SKILL_NODE(17, PhaseNode_RecordInnerEffect);
    if (node17 == nullptr) {
        node17 = new PhaseNode_RecordInnerEffect(17, phase);
        node17->setEffect(5);
        CALL_REGISTER_SKILL_NODE(132, 17, node17)
    }
    if (noInit == true) {
        return node17;
    }
    return node17;
}

//--------------------------------------------------------------------------------
// SkillCreator_132
//
class SkillCreator_132 : public SkillCreator {
public:
    SkillCreator_132() {}
    virtual ~SkillCreator_132() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_132

//--------------------------------------------------------------------------------
// SkillPhase_132
//
class SkillPhase_132 : public SkillPhase {
public:
    SkillPhase_132(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_132() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(132, 3) // WeaponDetect
        CASE_CREATE_SKILL_NODE(132, 5) // GetBuffAttribute
        CASE_CREATE_SKILL_NODE(132, 7) // CompareInt
        CASE_CREATE_SKILL_NODE(132, 9) // RecordInnerEffect
        CASE_CREATE_SKILL_NODE(132, 11) // TurnToArray
        CASE_CREATE_SKILL_NODE(132, 14) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(132, 17) // RecordInnerEffect
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_132

SkillLogic* SkillCreator_132::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //创建阶段phase
    auto phase = new SkillPhase_132(1, logic, 1);
    //设置phase执行器
    phase->setRunPhaseNode(1, 3);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_132::getSkillExpend(int32_t& nType, int32_t& nValue) {
    nType = Skill::E_SkillExpend_PASSIVITY;
    return true;
}
} // namespace pvp
