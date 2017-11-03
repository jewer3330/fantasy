#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

#include "skill_psnode_delay.h"
#include "skill_psnode_endphase.h"
#include "skill_psnode_getlocation.h"
#include "skill_psnode_getrotation.h"
#include "skill_psnode_offsetcalculate.h"
#include "skill_psnode_playanimation.h"
#include "skill_psnode_resetcd.h"
#include "skill_psnode_spawnprojectile.h"
#include "skill_psnode_startphase.h"
#include "skill_psnode_triggerupdate.h"

namespace pvp {

//变量声明
//--------------------------------------------------------------------------------
// StartPhase
//
REGISTER_REGISTER_SKILL_NODE(23051, 2) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_StartPhase::TRIGGER_START, 9, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(23051, 2) {
    auto node2 = GET_SKILL_NODE(2, PhaseNode_StartPhase);
    if (node2 == nullptr) {
        node2 = new PhaseNode_StartPhase(2, phase);
        CALL_REGISTER_SKILL_NODE(23051, 2, node2)
    }
    if (noInit == true) {
        return node2;
    }
    return node2;
}
//--------------------------------------------------------------------------------
// TriggerUpdate
//
REGISTER_REGISTER_SKILL_NODE(23051, 7) {
}

REGISTER_CREATE_SKILL_NODE(23051, 7) {
    auto node7 = GET_SKILL_NODE(7, PhaseNode_TriggerUpdate);
    if (node7 == nullptr) {
        node7 = new PhaseNode_TriggerUpdate(7, phase);
        CALL_REGISTER_SKILL_NODE(23051, 7, node7)
    }
    if (noInit == true) {
        return node7;
    }
    return node7;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(23051, 9) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_ResetCD::TRIGGER_DONE, 11, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(23051, 9) {
    auto node9 = GET_SKILL_NODE(9, PhaseNode_ResetCD);
    if (node9 == nullptr) {
        node9 = new PhaseNode_ResetCD(9, phase);
        node9->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node9->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node9->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(23051, 9, node9)
    }
    if (noInit == true) {
        return node9;
    }
    return node9;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(23051, 11) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetRotation>(PhaseNode_GetLocation::TRIGGER_DONE, 13, PhaseNode_GetRotation::FUNC_DO, &PhaseNode_GetRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(23051, 11) {
    auto node11 = GET_SKILL_NODE(11, PhaseNode_GetLocation);
    if (node11 == nullptr) {
        node11 = new PhaseNode_GetLocation(11, phase);
        node11->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node11->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(23051, 11, node11)
    }
    if (noInit == true) {
        return node11;
    }
    return node11;
}
//--------------------------------------------------------------------------------
// GetRotation
//
REGISTER_REGISTER_SKILL_NODE(23051, 13) {
    pnode->resizeTrigger(PhaseNode_GetRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_OffsetCalculate>(PhaseNode_GetRotation::TRIGGER_DONE, 15, PhaseNode_OffsetCalculate::FUNC_DO, &PhaseNode_OffsetCalculate::Do);
}

REGISTER_CREATE_SKILL_NODE(23051, 13) {
    auto node13 = GET_SKILL_NODE(13, PhaseNode_GetRotation);
    if (node13 == nullptr) {
        node13 = new PhaseNode_GetRotation(13, phase);
        node13->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node13->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(23051, 13, node13)
    }
    if (noInit == true) {
        return node13;
    }
    return node13;
}
//--------------------------------------------------------------------------------
// OffsetCalculate
//
REGISTER_REGISTER_SKILL_NODE(23051, 15) {
    pnode->resizeTrigger(PhaseNode_OffsetCalculate::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 17, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(23051, 15) {
    auto node15 = GET_SKILL_NODE(15, PhaseNode_OffsetCalculate);
    if (node15 == nullptr) {
        node15 = new PhaseNode_OffsetCalculate(15, phase);
        node15->setPosZ(.00f);
        node15->setOffsetX(.00f);
        node15->setOffsetY(1.00f);
        node15->setOffsetZ(.00f);
        node15->setRotOffset(.00f);
        CALL_REGISTER_SKILL_NODE(23051, 15, node15)
    }
    if (noInit == true) {
        return node15;
    }
    auto node11 = GET_SKILL_NODE(11, PhaseNode_GetLocation);
    auto node13 = GET_SKILL_NODE(13, PhaseNode_GetRotation);
    if (node11 != nullptr) node15->setPosX(node11->getX());
    if (node11 != nullptr) node15->setPosY(node11->getY());
    if (node13 != nullptr) node15->setRotation(node13->getAngle());
    return node15;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(23051, 17) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlayAnimation::TRIGGER_DONE, 23, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(23051, 17) {
    auto node17 = GET_SKILL_NODE(17, PhaseNode_PlayAnimation);
    if (node17 == nullptr) {
        node17 = new PhaseNode_PlayAnimation(17, phase);
        node17->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node17->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node17->setTarget(0U);
        node17->setAnimation("Skill1S1");
        node17->setParameter("");
        node17->setValue(false);
        CALL_REGISTER_SKILL_NODE(23051, 17, node17)
    }
    if (noInit == true) {
        return node17;
    }
    return node17;
}
//--------------------------------------------------------------------------------
// SpawnProjectile
//
REGISTER_REGISTER_SKILL_NODE(23051, 19) {
    pnode->resizeTrigger(PhaseNode_SpawnProjectile::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_SpawnProjectile::TRIGGER_DONE, 27, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(23051, 19) {
    auto node19 = GET_SKILL_NODE(19, PhaseNode_SpawnProjectile);
    if (node19 == nullptr) {
        node19 = new PhaseNode_SpawnProjectile(19, phase);
        node19->setDataId(52505);
        node19->setEndPosX(.00f);
        node19->setEndPosY(.00f);
        node19->setEndPosZ(.00f);
        node19->setMaxCount(0);
        CALL_REGISTER_SKILL_NODE(23051, 19, node19)
    }
    if (noInit == true) {
        return node19;
    }
    auto node15 = GET_SKILL_NODE(15, PhaseNode_OffsetCalculate);
    if (node15 != nullptr) node19->setPosX(node15->getOutPosX());
    if (node15 != nullptr) node19->setPosY(node15->getOutPosY());
    if (node15 != nullptr) node19->setPosZ(node15->getOutPosZ());
    if (node15 != nullptr) node19->setRotation(node15->getOutRotation());
    return node19;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(23051, 23) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnProjectile>(PhaseNode_Delay::TRIGGER_DONE, 19, PhaseNode_SpawnProjectile::FUNC_DO, &PhaseNode_SpawnProjectile::Do);
}

REGISTER_CREATE_SKILL_NODE(23051, 23) {
    auto node23 = GET_SKILL_NODE(23, PhaseNode_Delay);
    if (node23 == nullptr) {
        node23 = new PhaseNode_Delay(23, phase);
        node23->setTime(1.20f);
        CALL_REGISTER_SKILL_NODE(23051, 23, node23)
    }
    if (noInit == true) {
        return node23;
    }
    return node23;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(23051, 27) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_Delay::TRIGGER_DONE, 29, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(23051, 27) {
    auto node27 = GET_SKILL_NODE(27, PhaseNode_Delay);
    if (node27 == nullptr) {
        node27 = new PhaseNode_Delay(27, phase);
        node27->setTime(1.40f);
        CALL_REGISTER_SKILL_NODE(23051, 27, node27)
    }
    if (noInit == true) {
        return node27;
    }
    return node27;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(23051, 29) {
}

REGISTER_CREATE_SKILL_NODE(23051, 29) {
    auto node29 = GET_SKILL_NODE(29, PhaseNode_EndPhase);
    if (node29 == nullptr) {
        node29 = new PhaseNode_EndPhase(29, phase);
        node29->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node29->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(23051, 29, node29)
    }
    if (noInit == true) {
        return node29;
    }
    return node29;
}

//--------------------------------------------------------------------------------
// SkillCreator_23051
//
class SkillCreator_23051 : public SkillCreator {
public:
    SkillCreator_23051() {}
    virtual ~SkillCreator_23051() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_23051

//--------------------------------------------------------------------------------
// SkillPhase_23051
//
class SkillPhase_23051 : public SkillPhase {
public:
    SkillPhase_23051(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_23051() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(23051, 2) // StartPhase
        CASE_CREATE_SKILL_NODE(23051, 7) // TriggerUpdate
        CASE_CREATE_SKILL_NODE(23051, 9) // ResetCD
        CASE_CREATE_SKILL_NODE(23051, 11) // GetLocation
        CASE_CREATE_SKILL_NODE(23051, 13) // GetRotation
        CASE_CREATE_SKILL_NODE(23051, 15) // OffsetCalculate
        CASE_CREATE_SKILL_NODE(23051, 17) // PlayAnimation
        CASE_CREATE_SKILL_NODE(23051, 19) // SpawnProjectile
        CASE_CREATE_SKILL_NODE(23051, 23) // Delay
        CASE_CREATE_SKILL_NODE(23051, 27) // Delay
        CASE_CREATE_SKILL_NODE(23051, 29) // EndPhase
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_23051

SkillLogic* SkillCreator_23051::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //创建阶段phase
    auto phase = new SkillPhase_23051(1, logic, 2);
    //设置phase执行器
    phase->setRunPhaseNode(1, 2);
    phase->setRunPhaseNode(2, 7);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_23051::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
