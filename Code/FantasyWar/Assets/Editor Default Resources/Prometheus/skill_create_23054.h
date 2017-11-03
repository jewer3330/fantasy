#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

#include "skill_psnode_actorfilternewpene.h"
#include "skill_psnode_addskillbuffs.h"
#include "skill_psnode_createtriggernewpene.h"
#include "skill_psnode_delay.h"
#include "skill_psnode_detect.h"
#include "skill_psnode_disable.h"
#include "skill_psnode_endphase.h"
#include "skill_psnode_getactorattribute.h"
#include "skill_psnode_getlocation.h"
#include "skill_psnode_playanimation.h"
#include "skill_psnode_playeffect.h"
#include "skill_psnode_raiseevent.h"
#include "skill_psnode_resetcd.h"
#include "skill_psnode_setlocation.h"
#include "skill_psnode_setuint64.h"
#include "skill_psnode_spawncollider.h"
#include "skill_psnode_startphase.h"
#include "skill_psnode_triggercheck.h"
#include "skill_psnode_triggerupdate.h"

namespace pvp {

//变量声明
uint64_t Variable_23054_BladeStorm = 0;
//--------------------------------------------------------------------------------
// StartPhase
//
REGISTER_REGISTER_SKILL_NODE(23054, 2) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_StartPhase::TRIGGER_START, 6, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(23054, 2) {
    auto node2 = GET_SKILL_NODE(2, PhaseNode_StartPhase);
    if (node2 == nullptr) {
        node2 = new PhaseNode_StartPhase(2, phase);
        CALL_REGISTER_SKILL_NODE(23054, 2, node2)
    }
    if (noInit == true) {
        return node2;
    }
    return node2;
}
//--------------------------------------------------------------------------------
// TriggerUpdate
//
REGISTER_REGISTER_SKILL_NODE(23054, 4) {
}

REGISTER_CREATE_SKILL_NODE(23054, 4) {
    auto node4 = GET_SKILL_NODE(4, PhaseNode_TriggerUpdate);
    if (node4 == nullptr) {
        node4 = new PhaseNode_TriggerUpdate(4, phase);
        CALL_REGISTER_SKILL_NODE(23054, 4, node4)
    }
    if (noInit == true) {
        return node4;
    }
    return node4;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(23054, 6) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_ResetCD::TRIGGER_DONE, 8, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(23054, 6) {
    auto node6 = GET_SKILL_NODE(6, PhaseNode_ResetCD);
    if (node6 == nullptr) {
        node6 = new PhaseNode_ResetCD(6, phase);
        node6->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node6->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node6->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(23054, 6, node6)
    }
    if (noInit == true) {
        return node6;
    }
    return node6;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(23054, 8) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_GetLocation::TRIGGER_DONE, 85, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(23054, 8) {
    auto node8 = GET_SKILL_NODE(8, PhaseNode_GetLocation);
    if (node8 == nullptr) {
        node8 = new PhaseNode_GetLocation(8, phase);
        node8->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node8->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(23054, 8, node8)
    }
    if (noInit == true) {
        return node8;
    }
    return node8;
}
//--------------------------------------------------------------------------------
// SpawnCollider
//
REGISTER_REGISTER_SKILL_NODE(23054, 12) {
    pnode->resizeTrigger(PhaseNode_SpawnCollider::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_SpawnCollider::TRIGGER_DONE, 49, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_SetUInt64>(PhaseNode_SpawnCollider::TRIGGER_DONE, 17, PhaseNode_SetUInt64::FUNC_SET, &PhaseNode_SetUInt64::Set);
}

REGISTER_CREATE_SKILL_NODE(23054, 12) {
    auto node12 = GET_SKILL_NODE(12, PhaseNode_SpawnCollider);
    if (node12 == nullptr) {
        node12 = new PhaseNode_SpawnCollider(12, phase);
        node12->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node12->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node12->setMesh("");
        node12->setMeshScale(.00f);
        node12->setEffectID(0);
        node12->setEffectScale(.00f);
        node12->setType(PhaseNode_SpawnCollider::SpawnCollider_Type::Circle);
        node12->setTypeParams(0, 5.00f);
        node12->setTime(3.00f);
        node12->setPosZ(.00f);
        node12->setRotation(.00f);
        node12->setreentry(false);
        node12->setCheckPeneSound(false);
        CALL_REGISTER_SKILL_NODE(23054, 12, node12)
    }
    if (noInit == true) {
        return node12;
    }
    auto node8 = GET_SKILL_NODE(8, PhaseNode_GetLocation);
    if (node8 != nullptr) node12->setPosX(node8->getX());
    if (node8 != nullptr) node12->setPosY(node8->getY());
    return node12;
}
//--------------------------------------------------------------------------------
// SetUInt64
//
REGISTER_REGISTER_SKILL_NODE(23054, 17) {
    pnode->resizeTrigger(PhaseNode_SetUInt64::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_SetUInt64::TRIGGER_DONE, 91, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(23054, 17) {
    auto node17 = GET_SKILL_NODE(17, PhaseNode_SetUInt64);
    if (node17 == nullptr) {
        node17 = new PhaseNode_SetUInt64(17, phase);
        node17->setName("BladeStorm");
        CALL_REGISTER_SKILL_NODE(23054, 17, node17)
    }
    if (noInit == true) {
        return node17;
    }
    auto node12 = GET_SKILL_NODE(12, PhaseNode_SpawnCollider);
    if (node12 != nullptr) node17->setValue(node12->getColliderID());
    return node17;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(23054, 25) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetLocation>(PhaseNode_Detect::TRIGGER_ON, 27, PhaseNode_SetLocation::FUNC_DO, &PhaseNode_SetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(23054, 25) {
    auto node25 = GET_SKILL_NODE(25, PhaseNode_Detect);
    if (node25 == nullptr) {
        node25 = new PhaseNode_Detect(25, phase);
        node25->setSelf(0U);
        node25->setEvent("BladeStorm");
        node25->setType(PhaseNode_Detect::Detect_Type::Actor_POS);
        node25->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(23054, 25, node25)
    }
    if (noInit == true) {
        return node25;
    }
    return node25;
}
//--------------------------------------------------------------------------------
// SetLocation
//
REGISTER_REGISTER_SKILL_NODE(23054, 27) {
}

REGISTER_CREATE_SKILL_NODE(23054, 27) {
    auto node27 = GET_SKILL_NODE(27, PhaseNode_SetLocation);
    if (node27 == nullptr) {
        node27 = new PhaseNode_SetLocation(27, phase);
        node27->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node27->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(23054, 27, node27)
    }
    if (noInit == true) {
        return node27;
    }
    auto variables = node27->getVariables();
    if (variables != nullptr) {
        node27->setTarget(variables->getVariable<uint64_t>(Variable_23054_BladeStorm));
    }
    auto node25 = GET_SKILL_NODE(25, PhaseNode_Detect);
    if (node25 != nullptr) node27->setX(node25->getVars().getVariable<float>(0));
    if (node25 != nullptr) node27->setY(node25->getVars().getVariable<float>(1));
    if (node25 != nullptr) node27->setVX(node25->getVars().getVariable<float>(2));
    if (node25 != nullptr) node27->setVY(node25->getVars().getVariable<float>(3));
    return node27;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(23054, 31) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlayAnimation::TRIGGER_DONE, 33, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(23054, 31) {
    auto node31 = GET_SKILL_NODE(31, PhaseNode_PlayAnimation);
    if (node31 == nullptr) {
        node31 = new PhaseNode_PlayAnimation(31, phase);
        node31->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node31->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node31->setTarget(0U);
        node31->setAnimation("Skill4S1");
        node31->setParameter("");
        node31->setValue(false);
        CALL_REGISTER_SKILL_NODE(23054, 31, node31)
    }
    if (noInit == true) {
        return node31;
    }
    return node31;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(23054, 33) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnCollider>(PhaseNode_Delay::TRIGGER_DONE, 12, PhaseNode_SpawnCollider::FUNC_DO, &PhaseNode_SpawnCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(23054, 33) {
    auto node33 = GET_SKILL_NODE(33, PhaseNode_Delay);
    if (node33 == nullptr) {
        node33 = new PhaseNode_Delay(33, phase);
        node33->setTime(.40f);
        CALL_REGISTER_SKILL_NODE(23054, 33, node33)
    }
    if (noInit == true) {
        return node33;
    }
    return node33;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(23054, 37) {
}

REGISTER_CREATE_SKILL_NODE(23054, 37) {
    auto node37 = GET_SKILL_NODE(37, PhaseNode_TriggerCheck);
    if (node37 == nullptr) {
        node37 = new PhaseNode_TriggerCheck(37, phase);
        auto node4 = GET_SKILL_NODE(4, PhaseNode_TriggerUpdate);
        if (node4 != nullptr) node4->addTriggerCheck(node37);
        
        CALL_REGISTER_SKILL_NODE(23054, 37, node37)
    }
    if (noInit == true) {
        return node37;
    }
    auto node87 = GET_SKILL_NODE(87, PhaseNode_CreateTriggerNewPene);
    if (node87 != nullptr) node37->setTrigger(0, node87->getTriggerID());
    return node37;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(23054, 46) {
}

REGISTER_CREATE_SKILL_NODE(23054, 46) {
    auto node46 = GET_SKILL_NODE(46, PhaseNode_AddSkillBuffs);
    if (node46 == nullptr) {
        node46 = new PhaseNode_AddSkillBuffs(46, phase);
        node46->setConfigID({12});
        CALL_REGISTER_SKILL_NODE(23054, 46, node46)
    }
    if (noInit == true) {
        return node46;
    }
    auto node89 = GET_SKILL_NODE(89, PhaseNode_ActorFilterNewPene);
    auto node76 = GET_SKILL_NODE(76, PhaseNode_GetActorAttribute);
    if (node89 != nullptr) node46->setTarget(node89->getOutput());
    if (node76 != nullptr) node46->setAttribute(node76->getAttribute());
    return node46;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(23054, 49) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Disable>(PhaseNode_Delay::TRIGGER_DONE, 58, PhaseNode_Disable::FUNC_DO, &PhaseNode_Disable::Do);
}

REGISTER_CREATE_SKILL_NODE(23054, 49) {
    auto node49 = GET_SKILL_NODE(49, PhaseNode_Delay);
    if (node49 == nullptr) {
        node49 = new PhaseNode_Delay(49, phase);
        node49->setTime(3.00f);
        CALL_REGISTER_SKILL_NODE(23054, 49, node49)
    }
    if (noInit == true) {
        return node49;
    }
    return node49;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(23054, 51) {
}

REGISTER_CREATE_SKILL_NODE(23054, 51) {
    auto node51 = GET_SKILL_NODE(51, PhaseNode_EndPhase);
    if (node51 == nullptr) {
        node51 = new PhaseNode_EndPhase(51, phase);
        node51->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node51->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(23054, 51, node51)
    }
    if (noInit == true) {
        return node51;
    }
    return node51;
}
//--------------------------------------------------------------------------------
// Disable
//
REGISTER_REGISTER_SKILL_NODE(23054, 58) {
    pnode->resizeTrigger(PhaseNode_Disable::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_Disable::TRIGGER_DONE, 60, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(23054, 58) {
    auto node58 = GET_SKILL_NODE(58, PhaseNode_Disable);
    if (node58 == nullptr) {
        node58 = new PhaseNode_Disable(58, phase);
        node58->setTarget(0U);
        node58->setMove(true);
        node58->setSkill(false);
        node58->setShoot(false);
        node58->setTime(.80f);
        node58->setRotate(false);
        CALL_REGISTER_SKILL_NODE(23054, 58, node58)
    }
    if (noInit == true) {
        return node58;
    }
    return node58;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(23054, 60) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_Delay::TRIGGER_DONE, 51, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(23054, 60) {
    auto node60 = GET_SKILL_NODE(60, PhaseNode_Delay);
    if (node60 == nullptr) {
        node60 = new PhaseNode_Delay(60, phase);
        node60->setTime(.80f);
        CALL_REGISTER_SKILL_NODE(23054, 60, node60)
    }
    if (noInit == true) {
        return node60;
    }
    return node60;
}
//--------------------------------------------------------------------------------
// GetActorAttribute
//
REGISTER_REGISTER_SKILL_NODE(23054, 76) {
    pnode->resizeTrigger(PhaseNode_GetActorAttribute::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 46, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
}

REGISTER_CREATE_SKILL_NODE(23054, 76) {
    auto node76 = GET_SKILL_NODE(76, PhaseNode_GetActorAttribute);
    if (node76 == nullptr) {
        node76 = new PhaseNode_GetActorAttribute(76, phase);
        node76->setTarget(0U);
        node76->setType({});
        CALL_REGISTER_SKILL_NODE(23054, 76, node76)
    }
    if (noInit == true) {
        return node76;
    }
    return node76;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(23054, 85) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_PlayEffect::TRIGGER_DONE, 31, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(23054, 85) {
    auto node85 = GET_SKILL_NODE(85, PhaseNode_PlayEffect);
    if (node85 == nullptr) {
        node85 = new PhaseNode_PlayEffect(85, phase);
        node85->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node85->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node85->setEffectID(230541);
        node85->setChangeColor(false);
        node85->setType(PhaseNode_PlayEffect::PlayEffect_Type::WithTarget);
        node85->getVars().reserve(5);
        node85->getVars().setVariable<uint64_t>(0, 0U);
        node85->getVars().setVariable<std::string>(1, "");
        node85->getVars().setVariable<float>(2, .00f);
        node85->getVars().setVariable<float>(3, .00f);
        node85->getVars().setVariable<float>(4, .00f);
        node85->setRotation(.00f);
        node85->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(23054, 85, node85)
    }
    if (noInit == true) {
        return node85;
    }
    return node85;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(23054, 87) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 37, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 89, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(23054, 87) {
    auto node87 = GET_SKILL_NODE(87, PhaseNode_CreateTriggerNewPene);
    if (node87 == nullptr) {
        node87 = new PhaseNode_CreateTriggerNewPene(87, phase);
        node87->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::Tick);
        node87->setTypeParams(0, .30f);
        node87->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node87->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Enemy);
        node87->setOnHero(true);
        node87->setOnMinion(true);
        node87->setOnDestruct(true);
        node87->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(23054, 87, node87)
    }
    if (noInit == true) {
        return node87;
    }
    auto node12 = GET_SKILL_NODE(12, PhaseNode_SpawnCollider);
    if (node12 != nullptr) node87->setColliderID(node12->getColliderID());
    return node87;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(23054, 89) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 76, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(23054, 89) {
    auto node89 = GET_SKILL_NODE(89, PhaseNode_ActorFilterNewPene);
    if (node89 == nullptr) {
        node89 = new PhaseNode_ActorFilterNewPene(89, phase);
        node89->setHero(true);
        node89->setMinion(true);
        node89->setDestruct(true);
        node89->setShield(false);
        node89->setTotalCount(0);
        node89->setPerCount(0);
        CALL_REGISTER_SKILL_NODE(23054, 89, node89)
    }
    if (noInit == true) {
        return node89;
    }
    auto node87 = GET_SKILL_NODE(87, PhaseNode_CreateTriggerNewPene);
    if (node87 != nullptr) node89->setInput(node87->getOther());
    return node89;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(23054, 91) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_RaiseEvent::TRIGGER_DONE, 87, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
}

REGISTER_CREATE_SKILL_NODE(23054, 91) {
    auto node91 = GET_SKILL_NODE(91, PhaseNode_RaiseEvent);
    if (node91 == nullptr) {
        node91 = new PhaseNode_RaiseEvent(91, phase);
        node91->setEvent("FollowCaster");
        node91->setTarget(0U);
        node91->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node91->setTypeParams(0, 0);
        node91->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(23054, 91, node91)
    }
    if (noInit == true) {
        return node91;
    }
    return node91;
}

//--------------------------------------------------------------------------------
// SkillCreator_23054
//
class SkillCreator_23054 : public SkillCreator {
public:
    SkillCreator_23054() {}
    virtual ~SkillCreator_23054() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_23054

//--------------------------------------------------------------------------------
// SkillPhase_23054
//
class SkillPhase_23054 : public SkillPhase {
public:
    SkillPhase_23054(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_23054() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(23054, 2) // StartPhase
        CASE_CREATE_SKILL_NODE(23054, 4) // TriggerUpdate
        CASE_CREATE_SKILL_NODE(23054, 6) // ResetCD
        CASE_CREATE_SKILL_NODE(23054, 8) // GetLocation
        CASE_CREATE_SKILL_NODE(23054, 12) // SpawnCollider
        CASE_CREATE_SKILL_NODE(23054, 17) // SetUInt64
        CASE_CREATE_SKILL_NODE(23054, 25) // Detect
        CASE_CREATE_SKILL_NODE(23054, 27) // SetLocation
        CASE_CREATE_SKILL_NODE(23054, 31) // PlayAnimation
        CASE_CREATE_SKILL_NODE(23054, 33) // Delay
        CASE_CREATE_SKILL_NODE(23054, 37) // TriggerCheck
        CASE_CREATE_SKILL_NODE(23054, 46) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(23054, 49) // Delay
        CASE_CREATE_SKILL_NODE(23054, 51) // EndPhase
        CASE_CREATE_SKILL_NODE(23054, 58) // Disable
        CASE_CREATE_SKILL_NODE(23054, 60) // Delay
        CASE_CREATE_SKILL_NODE(23054, 76) // GetActorAttribute
        CASE_CREATE_SKILL_NODE(23054, 85) // PlayEffect
        CASE_CREATE_SKILL_NODE(23054, 87) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(23054, 89) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(23054, 91) // RaiseEvent
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_23054

SkillLogic* SkillCreator_23054::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //设置变量
    Variable_23054_BladeStorm = logic->getVariables().setVariable<uint64_t>("BladeStorm", 0U);
    //创建阶段phase
    auto phase = new SkillPhase_23054(1, logic, 3);
    //设置phase执行器
    phase->setRunPhaseNode(1, 2);
    phase->setRunPhaseNode(2, 4);
    phase->setDetectPhaseNode(3, 25);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_23054::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
