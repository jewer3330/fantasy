#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

#include "skill_psnode_delay.h"
#include "skill_psnode_detect.h"
#include "skill_psnode_endphase.h"
#include "skill_psnode_getlocation.h"
#include "skill_psnode_getrotation.h"
#include "skill_psnode_offsetcalculate.h"
#include "skill_psnode_playanimation.h"
#include "skill_psnode_playsound.h"
#include "skill_psnode_resetcd.h"
#include "skill_psnode_spawncollider.h"
#include "skill_psnode_spawnprojectile.h"
#include "skill_psnode_startphase.h"
#include "skill_psnode_triggerupdate.h"

namespace pvp {

//变量声明
//--------------------------------------------------------------------------------
// StartPhase
//
REGISTER_REGISTER_SKILL_NODE(23021, 4) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_StartPhase::TRIGGER_START, 8, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(23021, 4) {
    auto node4 = GET_SKILL_NODE(4, PhaseNode_StartPhase);
    if (node4 == nullptr) {
        node4 = new PhaseNode_StartPhase(4, phase);
        CALL_REGISTER_SKILL_NODE(23021, 4, node4)
    }
    if (noInit == true) {
        return node4;
    }
    return node4;
}
//--------------------------------------------------------------------------------
// TriggerUpdate
//
REGISTER_REGISTER_SKILL_NODE(23021, 6) {
}

REGISTER_CREATE_SKILL_NODE(23021, 6) {
    auto node6 = GET_SKILL_NODE(6, PhaseNode_TriggerUpdate);
    if (node6 == nullptr) {
        node6 = new PhaseNode_TriggerUpdate(6, phase);
        CALL_REGISTER_SKILL_NODE(23021, 6, node6)
    }
    if (noInit == true) {
        return node6;
    }
    return node6;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(23021, 8) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_ResetCD::TRIGGER_DONE, 10, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(23021, 8) {
    auto node8 = GET_SKILL_NODE(8, PhaseNode_ResetCD);
    if (node8 == nullptr) {
        node8 = new PhaseNode_ResetCD(8, phase);
        node8->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node8->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node8->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(23021, 8, node8)
    }
    if (noInit == true) {
        return node8;
    }
    return node8;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(23021, 10) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetRotation>(PhaseNode_GetLocation::TRIGGER_DONE, 12, PhaseNode_GetRotation::FUNC_DO, &PhaseNode_GetRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(23021, 10) {
    auto node10 = GET_SKILL_NODE(10, PhaseNode_GetLocation);
    if (node10 == nullptr) {
        node10 = new PhaseNode_GetLocation(10, phase);
        node10->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node10->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(23021, 10, node10)
    }
    if (noInit == true) {
        return node10;
    }
    return node10;
}
//--------------------------------------------------------------------------------
// GetRotation
//
REGISTER_REGISTER_SKILL_NODE(23021, 12) {
    pnode->resizeTrigger(PhaseNode_GetRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_GetRotation::TRIGGER_DONE, 14, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(23021, 12) {
    auto node12 = GET_SKILL_NODE(12, PhaseNode_GetRotation);
    if (node12 == nullptr) {
        node12 = new PhaseNode_GetRotation(12, phase);
        node12->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node12->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(23021, 12, node12)
    }
    if (noInit == true) {
        return node12;
    }
    return node12;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(23021, 14) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlayAnimation::TRIGGER_DONE, 16, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_PlayAnimation::TRIGGER_DONE, 39, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(23021, 14) {
    auto node14 = GET_SKILL_NODE(14, PhaseNode_PlayAnimation);
    if (node14 == nullptr) {
        node14 = new PhaseNode_PlayAnimation(14, phase);
        node14->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node14->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node14->setTarget(0U);
        node14->setAnimation("Skill1S1");
        node14->setParameter("");
        node14->setValue(false);
        CALL_REGISTER_SKILL_NODE(23021, 14, node14)
    }
    if (noInit == true) {
        return node14;
    }
    return node14;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(23021, 16) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnCollider>(PhaseNode_Delay::TRIGGER_DONE, 30, PhaseNode_SpawnCollider::FUNC_DO, &PhaseNode_SpawnCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(23021, 16) {
    auto node16 = GET_SKILL_NODE(16, PhaseNode_Delay);
    if (node16 == nullptr) {
        node16 = new PhaseNode_Delay(16, phase);
        node16->setTime(.90f);
        CALL_REGISTER_SKILL_NODE(23021, 16, node16)
    }
    if (noInit == true) {
        return node16;
    }
    return node16;
}
//--------------------------------------------------------------------------------
// OffsetCalculate
//
REGISTER_REGISTER_SKILL_NODE(23021, 18) {
    pnode->resizeTrigger(PhaseNode_OffsetCalculate::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnProjectile>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 20, PhaseNode_SpawnProjectile::FUNC_DO, &PhaseNode_SpawnProjectile::Do);
}

REGISTER_CREATE_SKILL_NODE(23021, 18) {
    auto node18 = GET_SKILL_NODE(18, PhaseNode_OffsetCalculate);
    if (node18 == nullptr) {
        node18 = new PhaseNode_OffsetCalculate(18, phase);
        node18->setPosZ(.00f);
        node18->setOffsetX(.10f);
        node18->setOffsetY(4.00f);
        node18->setOffsetZ(2.00f);
        node18->setRotOffset(.00f);
        CALL_REGISTER_SKILL_NODE(23021, 18, node18)
    }
    if (noInit == true) {
        return node18;
    }
    auto node10 = GET_SKILL_NODE(10, PhaseNode_GetLocation);
    auto node12 = GET_SKILL_NODE(12, PhaseNode_GetRotation);
    if (node10 != nullptr) node18->setPosX(node10->getX());
    if (node10 != nullptr) node18->setPosY(node10->getY());
    if (node12 != nullptr) node18->setRotation(node12->getAngle());
    return node18;
}
//--------------------------------------------------------------------------------
// SpawnProjectile
//
REGISTER_REGISTER_SKILL_NODE(23021, 20) {
    pnode->resizeTrigger(PhaseNode_SpawnProjectile::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_SpawnProjectile::TRIGGER_DONE, 22, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(23021, 20) {
    auto node20 = GET_SKILL_NODE(20, PhaseNode_SpawnProjectile);
    if (node20 == nullptr) {
        node20 = new PhaseNode_SpawnProjectile(20, phase);
        node20->setDataId(52302);
        node20->setEndPosX(.00f);
        node20->setEndPosY(.00f);
        node20->setEndPosZ(.00f);
        node20->setMaxCount(0);
        CALL_REGISTER_SKILL_NODE(23021, 20, node20)
    }
    if (noInit == true) {
        return node20;
    }
    auto node18 = GET_SKILL_NODE(18, PhaseNode_OffsetCalculate);
    if (node18 != nullptr) node20->setPosX(node18->getOutPosX());
    if (node18 != nullptr) node20->setPosY(node18->getOutPosY());
    if (node18 != nullptr) node20->setPosZ(node18->getOutPosZ());
    if (node18 != nullptr) node20->setRotation(node18->getOutRotation());
    return node20;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(23021, 22) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_Delay::TRIGGER_DONE, 24, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(23021, 22) {
    auto node22 = GET_SKILL_NODE(22, PhaseNode_Delay);
    if (node22 == nullptr) {
        node22 = new PhaseNode_Delay(22, phase);
        node22->setTime(.50f);
        CALL_REGISTER_SKILL_NODE(23021, 22, node22)
    }
    if (noInit == true) {
        return node22;
    }
    return node22;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(23021, 24) {
}

REGISTER_CREATE_SKILL_NODE(23021, 24) {
    auto node24 = GET_SKILL_NODE(24, PhaseNode_EndPhase);
    if (node24 == nullptr) {
        node24 = new PhaseNode_EndPhase(24, phase);
        node24->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node24->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(23021, 24, node24)
    }
    if (noInit == true) {
        return node24;
    }
    return node24;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(23021, 26) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_Detect::TRIGGER_ON, 28, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(23021, 26) {
    auto node26 = GET_SKILL_NODE(26, PhaseNode_Detect);
    if (node26 == nullptr) {
        node26 = new PhaseNode_Detect(26, phase);
        node26->setSelf(0U);
        node26->setEvent("");
        node26->setType(PhaseNode_Detect::Detect_Type::Actor_Dead);
        node26->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(23021, 26, node26)
    }
    if (noInit == true) {
        return node26;
    }
    return node26;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(23021, 28) {
}

REGISTER_CREATE_SKILL_NODE(23021, 28) {
    auto node28 = GET_SKILL_NODE(28, PhaseNode_EndPhase);
    if (node28 == nullptr) {
        node28 = new PhaseNode_EndPhase(28, phase);
        node28->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node28->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(23021, 28, node28)
    }
    if (noInit == true) {
        return node28;
    }
    return node28;
}
//--------------------------------------------------------------------------------
// SpawnCollider
//
REGISTER_REGISTER_SKILL_NODE(23021, 30) {
    pnode->resizeTrigger(PhaseNode_SpawnCollider::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_OffsetCalculate>(PhaseNode_SpawnCollider::TRIGGER_DONE, 18, PhaseNode_OffsetCalculate::FUNC_DO, &PhaseNode_OffsetCalculate::Do);
}

REGISTER_CREATE_SKILL_NODE(23021, 30) {
    auto node30 = GET_SKILL_NODE(30, PhaseNode_SpawnCollider);
    if (node30 == nullptr) {
        node30 = new PhaseNode_SpawnCollider(30, phase);
        node30->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node30->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node30->setMesh("");
        node30->setMeshScale(.00f);
        node30->setEffectID(230213);
        node30->setEffectScale(1.00f);
        node30->setType(PhaseNode_SpawnCollider::SpawnCollider_Type::Circle);
        node30->setTypeParams(0, .00f);
        node30->setTime(.00f);
        node30->setPosZ(.00f);
        node30->setreentry(false);
        node30->setCheckPeneSound(false);
        CALL_REGISTER_SKILL_NODE(23021, 30, node30)
    }
    if (noInit == true) {
        return node30;
    }
    auto node10 = GET_SKILL_NODE(10, PhaseNode_GetLocation);
    auto node12 = GET_SKILL_NODE(12, PhaseNode_GetRotation);
    if (node10 != nullptr) node30->setPosX(node10->getX());
    if (node10 != nullptr) node30->setPosY(node10->getY());
    if (node12 != nullptr) node30->setRotation(node12->getAngle());
    return node30;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(23021, 39) {
}

REGISTER_CREATE_SKILL_NODE(23021, 39) {
    auto node39 = GET_SKILL_NODE(39, PhaseNode_PlaySound);
    if (node39 == nullptr) {
        node39 = new PhaseNode_PlaySound(39, phase);
        node39->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node39->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node39->setSoundID("SE_MON2302_ATK_P1");
        node39->setTarget(0U);
        node39->setUsePos(false);
        node39->setPosX(.00f);
        node39->setPosY(.00f);
        node39->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(23021, 39, node39)
    }
    if (noInit == true) {
        return node39;
    }
    return node39;
}

//--------------------------------------------------------------------------------
// SkillCreator_23021
//
class SkillCreator_23021 : public SkillCreator {
public:
    SkillCreator_23021() {}
    virtual ~SkillCreator_23021() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_23021

//--------------------------------------------------------------------------------
// SkillPhase_23021
//
class SkillPhase_23021 : public SkillPhase {
public:
    SkillPhase_23021(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_23021() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(23021, 4) // StartPhase
        CASE_CREATE_SKILL_NODE(23021, 6) // TriggerUpdate
        CASE_CREATE_SKILL_NODE(23021, 8) // ResetCD
        CASE_CREATE_SKILL_NODE(23021, 10) // GetLocation
        CASE_CREATE_SKILL_NODE(23021, 12) // GetRotation
        CASE_CREATE_SKILL_NODE(23021, 14) // PlayAnimation
        CASE_CREATE_SKILL_NODE(23021, 16) // Delay
        CASE_CREATE_SKILL_NODE(23021, 18) // OffsetCalculate
        CASE_CREATE_SKILL_NODE(23021, 20) // SpawnProjectile
        CASE_CREATE_SKILL_NODE(23021, 22) // Delay
        CASE_CREATE_SKILL_NODE(23021, 24) // EndPhase
        CASE_CREATE_SKILL_NODE(23021, 26) // Detect
        CASE_CREATE_SKILL_NODE(23021, 28) // EndPhase
        CASE_CREATE_SKILL_NODE(23021, 30) // SpawnCollider
        CASE_CREATE_SKILL_NODE(23021, 39) // PlaySound
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_23021

SkillLogic* SkillCreator_23021::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //创建阶段phase
    auto phase = new SkillPhase_23021(1, logic, 3);
    //设置phase执行器
    phase->setRunPhaseNode(1, 4);
    phase->setRunPhaseNode(2, 6);
    phase->setDetectPhaseNode(3, 26);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_23021::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
