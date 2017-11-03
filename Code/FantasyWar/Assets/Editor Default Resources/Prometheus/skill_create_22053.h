#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

#include "skill_psnode_actorfilternewpene.h"
#include "skill_psnode_addskillbuffs.h"
#include "skill_psnode_attachto.h"
#include "skill_psnode_createtriggernewpene.h"
#include "skill_psnode_delay.h"
#include "skill_psnode_endphase.h"
#include "skill_psnode_getlocation.h"
#include "skill_psnode_getrotation.h"
#include "skill_psnode_getself.h"
#include "skill_psnode_offsetcalculate.h"
#include "skill_psnode_skillendnotify.h"
#include "skill_psnode_spawncollider.h"
#include "skill_psnode_startphase.h"
#include "skill_psnode_triggercheck.h"
#include "skill_psnode_triggerupdate.h"

namespace pvp {

//变量声明
//--------------------------------------------------------------------------------
// StartPhase
//
REGISTER_REGISTER_SKILL_NODE(22053, 3) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_StartPhase::TRIGGER_START, 33, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(22053, 3) {
    auto node3 = GET_SKILL_NODE(3, PhaseNode_StartPhase);
    if (node3 == nullptr) {
        node3 = new PhaseNode_StartPhase(3, phase);
        CALL_REGISTER_SKILL_NODE(22053, 3, node3)
    }
    if (noInit == true) {
        return node3;
    }
    return node3;
}
//--------------------------------------------------------------------------------
// TriggerUpdate
//
REGISTER_REGISTER_SKILL_NODE(22053, 5) {
}

REGISTER_CREATE_SKILL_NODE(22053, 5) {
    auto node5 = GET_SKILL_NODE(5, PhaseNode_TriggerUpdate);
    if (node5 == nullptr) {
        node5 = new PhaseNode_TriggerUpdate(5, phase);
        CALL_REGISTER_SKILL_NODE(22053, 5, node5)
    }
    if (noInit == true) {
        return node5;
    }
    return node5;
}
//--------------------------------------------------------------------------------
// SpawnCollider
//
REGISTER_REGISTER_SKILL_NODE(22053, 9) {
    pnode->resizeTrigger(PhaseNode_SpawnCollider::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_SpawnCollider::TRIGGER_DONE, 15, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
    pnode->regTrigger<PhaseNode_GetSelf>(PhaseNode_SpawnCollider::TRIGGER_DONE, 28, PhaseNode_GetSelf::FUNC_DO, &PhaseNode_GetSelf::Do);
}

REGISTER_CREATE_SKILL_NODE(22053, 9) {
    auto node9 = GET_SKILL_NODE(9, PhaseNode_SpawnCollider);
    if (node9 == nullptr) {
        node9 = new PhaseNode_SpawnCollider(9, phase);
        node9->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node9->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node9->setMesh("");
        node9->setMeshScale(.00f);
        node9->setEffectID(1014);
        node9->setEffectScale(2.50f);
        node9->setType(PhaseNode_SpawnCollider::SpawnCollider_Type::Circle);
        node9->setTypeParams(0, 5.00f);
        node9->setTime(16.00f);
        node9->setreentry(false);
        node9->setCheckPeneSound(false);
        CALL_REGISTER_SKILL_NODE(22053, 9, node9)
    }
    if (noInit == true) {
        return node9;
    }
    auto node35 = GET_SKILL_NODE(35, PhaseNode_OffsetCalculate);
    if (node35 != nullptr) node9->setPosX(node35->getOutPosX());
    if (node35 != nullptr) node9->setPosY(node35->getOutPosY());
    if (node35 != nullptr) node9->setPosZ(node35->getOutPosZ());
    if (node35 != nullptr) node9->setRotation(node35->getOutRotation());
    return node9;
}
//--------------------------------------------------------------------------------
// AttachTo
//
REGISTER_REGISTER_SKILL_NODE(22053, 11) {
    pnode->resizeTrigger(PhaseNode_AttachTo::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_AttachTo::TRIGGER_DONE, 26, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
}

REGISTER_CREATE_SKILL_NODE(22053, 11) {
    auto node11 = GET_SKILL_NODE(11, PhaseNode_AttachTo);
    if (node11 == nullptr) {
        node11 = new PhaseNode_AttachTo(11, phase);
        node11->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node11->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node11->setChangeRotation(false);
        node11->setreentry(false);
        CALL_REGISTER_SKILL_NODE(22053, 11, node11)
    }
    if (noInit == true) {
        return node11;
    }
    auto node28 = GET_SKILL_NODE(28, PhaseNode_GetSelf);
    auto node9 = GET_SKILL_NODE(9, PhaseNode_SpawnCollider);
    if (node28 != nullptr) node11->setParent(node28->getTarget());
    if (node9 != nullptr) node11->setChild(node9->getColliderID());
    return node11;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(22053, 15) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 19, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 22, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(22053, 15) {
    auto node15 = GET_SKILL_NODE(15, PhaseNode_CreateTriggerNewPene);
    if (node15 == nullptr) {
        node15 = new PhaseNode_CreateTriggerNewPene(15, phase);
        node15->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::Tick);
        node15->setTypeParams(0, .20f);
        node15->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node15->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Friend);
        node15->setOnHero(false);
        node15->setOnMinion(true);
        node15->setOnDestruct(false);
        node15->setOnShield(true);
        CALL_REGISTER_SKILL_NODE(22053, 15, node15)
    }
    if (noInit == true) {
        return node15;
    }
    auto node9 = GET_SKILL_NODE(9, PhaseNode_SpawnCollider);
    if (node9 != nullptr) node15->setColliderID(node9->getColliderID());
    return node15;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(22053, 19) {
}

REGISTER_CREATE_SKILL_NODE(22053, 19) {
    auto node19 = GET_SKILL_NODE(19, PhaseNode_TriggerCheck);
    if (node19 == nullptr) {
        node19 = new PhaseNode_TriggerCheck(19, phase);
        auto node5 = GET_SKILL_NODE(5, PhaseNode_TriggerUpdate);
        if (node5 != nullptr) node5->addTriggerCheck(node19);
        
        CALL_REGISTER_SKILL_NODE(22053, 19, node19)
    }
    if (noInit == true) {
        return node19;
    }
    auto node15 = GET_SKILL_NODE(15, PhaseNode_CreateTriggerNewPene);
    if (node15 != nullptr) node19->setTrigger(0, node15->getTriggerID());
    return node19;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(22053, 22) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 24, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
}

REGISTER_CREATE_SKILL_NODE(22053, 22) {
    auto node22 = GET_SKILL_NODE(22, PhaseNode_ActorFilterNewPene);
    if (node22 == nullptr) {
        node22 = new PhaseNode_ActorFilterNewPene(22, phase);
        node22->setHero(false);
        node22->setMinion(true);
        node22->setDestruct(false);
        node22->setShield(true);
        node22->setTotalCount(0);
        node22->setPerCount(0);
        CALL_REGISTER_SKILL_NODE(22053, 22, node22)
    }
    if (noInit == true) {
        return node22;
    }
    auto node15 = GET_SKILL_NODE(15, PhaseNode_CreateTriggerNewPene);
    if (node15 != nullptr) node22->setInput(node15->getOther());
    return node22;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(22053, 24) {
}

REGISTER_CREATE_SKILL_NODE(22053, 24) {
    auto node24 = GET_SKILL_NODE(24, PhaseNode_AddSkillBuffs);
    if (node24 == nullptr) {
        node24 = new PhaseNode_AddSkillBuffs(24, phase);
        node24->setConfigID({220623});
        node24->setAttribute({{}});
        CALL_REGISTER_SKILL_NODE(22053, 24, node24)
    }
    if (noInit == true) {
        return node24;
    }
    auto node22 = GET_SKILL_NODE(22, PhaseNode_ActorFilterNewPene);
    if (node22 != nullptr) node24->setTarget(node22->getOutput());
    return node24;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(22053, 26) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 30, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(22053, 26) {
    auto node26 = GET_SKILL_NODE(26, PhaseNode_SkillEndNotify);
    if (node26 == nullptr) {
        node26 = new PhaseNode_SkillEndNotify(26, phase);
        node26->setReturnType(true);
        CALL_REGISTER_SKILL_NODE(22053, 26, node26)
    }
    if (noInit == true) {
        return node26;
    }
    return node26;
}
//--------------------------------------------------------------------------------
// GetSelf
//
REGISTER_REGISTER_SKILL_NODE(22053, 28) {
    pnode->resizeTrigger(PhaseNode_GetSelf::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AttachTo>(PhaseNode_GetSelf::TRIGGER_DONE, 11, PhaseNode_AttachTo::FUNC_DO, &PhaseNode_AttachTo::Do);
}

REGISTER_CREATE_SKILL_NODE(22053, 28) {
    auto node28 = GET_SKILL_NODE(28, PhaseNode_GetSelf);
    if (node28 == nullptr) {
        node28 = new PhaseNode_GetSelf(28, phase);
        CALL_REGISTER_SKILL_NODE(22053, 28, node28)
    }
    if (noInit == true) {
        return node28;
    }
    return node28;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22053, 30) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_Delay::TRIGGER_DONE, 32, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(22053, 30) {
    auto node30 = GET_SKILL_NODE(30, PhaseNode_Delay);
    if (node30 == nullptr) {
        node30 = new PhaseNode_Delay(30, phase);
        node30->setTime(16.00f);
        CALL_REGISTER_SKILL_NODE(22053, 30, node30)
    }
    if (noInit == true) {
        return node30;
    }
    return node30;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(22053, 32) {
}

REGISTER_CREATE_SKILL_NODE(22053, 32) {
    auto node32 = GET_SKILL_NODE(32, PhaseNode_EndPhase);
    if (node32 == nullptr) {
        node32 = new PhaseNode_EndPhase(32, phase);
        node32->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node32->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(22053, 32, node32)
    }
    if (noInit == true) {
        return node32;
    }
    return node32;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(22053, 33) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetRotation>(PhaseNode_GetLocation::TRIGGER_DONE, 34, PhaseNode_GetRotation::FUNC_DO, &PhaseNode_GetRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(22053, 33) {
    auto node33 = GET_SKILL_NODE(33, PhaseNode_GetLocation);
    if (node33 == nullptr) {
        node33 = new PhaseNode_GetLocation(33, phase);
        node33->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node33->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(22053, 33, node33)
    }
    if (noInit == true) {
        return node33;
    }
    return node33;
}
//--------------------------------------------------------------------------------
// GetRotation
//
REGISTER_REGISTER_SKILL_NODE(22053, 34) {
    pnode->resizeTrigger(PhaseNode_GetRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_OffsetCalculate>(PhaseNode_GetRotation::TRIGGER_DONE, 35, PhaseNode_OffsetCalculate::FUNC_DO, &PhaseNode_OffsetCalculate::Do);
}

REGISTER_CREATE_SKILL_NODE(22053, 34) {
    auto node34 = GET_SKILL_NODE(34, PhaseNode_GetRotation);
    if (node34 == nullptr) {
        node34 = new PhaseNode_GetRotation(34, phase);
        node34->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node34->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(22053, 34, node34)
    }
    if (noInit == true) {
        return node34;
    }
    return node34;
}
//--------------------------------------------------------------------------------
// OffsetCalculate
//
REGISTER_REGISTER_SKILL_NODE(22053, 35) {
    pnode->resizeTrigger(PhaseNode_OffsetCalculate::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnCollider>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 9, PhaseNode_SpawnCollider::FUNC_DO, &PhaseNode_SpawnCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(22053, 35) {
    auto node35 = GET_SKILL_NODE(35, PhaseNode_OffsetCalculate);
    if (node35 == nullptr) {
        node35 = new PhaseNode_OffsetCalculate(35, phase);
        node35->setPosZ(.00f);
        node35->setOffsetX(.00f);
        node35->setOffsetY(.00f);
        node35->setOffsetZ(.00f);
        node35->setRotOffset(.00f);
        CALL_REGISTER_SKILL_NODE(22053, 35, node35)
    }
    if (noInit == true) {
        return node35;
    }
    auto node33 = GET_SKILL_NODE(33, PhaseNode_GetLocation);
    auto node34 = GET_SKILL_NODE(34, PhaseNode_GetRotation);
    if (node33 != nullptr) node35->setPosX(node33->getX());
    if (node33 != nullptr) node35->setPosY(node33->getY());
    if (node34 != nullptr) node35->setRotation(node34->getAngle());
    return node35;
}

//--------------------------------------------------------------------------------
// SkillCreator_22053
//
class SkillCreator_22053 : public SkillCreator {
public:
    SkillCreator_22053() {}
    virtual ~SkillCreator_22053() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_22053

//--------------------------------------------------------------------------------
// SkillPhase_22053
//
class SkillPhase_22053 : public SkillPhase {
public:
    SkillPhase_22053(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_22053() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(22053, 3) // StartPhase
        CASE_CREATE_SKILL_NODE(22053, 5) // TriggerUpdate
        CASE_CREATE_SKILL_NODE(22053, 9) // SpawnCollider
        CASE_CREATE_SKILL_NODE(22053, 11) // AttachTo
        CASE_CREATE_SKILL_NODE(22053, 15) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(22053, 19) // TriggerCheck
        CASE_CREATE_SKILL_NODE(22053, 22) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(22053, 24) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(22053, 26) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(22053, 28) // GetSelf
        CASE_CREATE_SKILL_NODE(22053, 30) // Delay
        CASE_CREATE_SKILL_NODE(22053, 32) // EndPhase
        CASE_CREATE_SKILL_NODE(22053, 33) // GetLocation
        CASE_CREATE_SKILL_NODE(22053, 34) // GetRotation
        CASE_CREATE_SKILL_NODE(22053, 35) // OffsetCalculate
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_22053

SkillLogic* SkillCreator_22053::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //创建阶段phase
    auto phase = new SkillPhase_22053(1, logic, 2);
    //设置phase执行器
    phase->setRunPhaseNode(1, 3);
    phase->setRunPhaseNode(2, 5);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_22053::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
