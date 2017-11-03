#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

#include "skill_psnode_delay.h"
#include "skill_psnode_disable.h"
#include "skill_psnode_endphase.h"
#include "skill_psnode_getinputlocation.h"
#include "skill_psnode_playanimation.h"
#include "skill_psnode_playsound.h"
#include "skill_psnode_resetcd.h"
#include "skill_psnode_spawnprojectile.h"
#include "skill_psnode_startphase.h"

namespace pvp {

//变量声明
//--------------------------------------------------------------------------------
// StartPhase
//
REGISTER_REGISTER_SKILL_NODE(10163, 3) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_StartPhase::TRIGGER_START, 21, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(10163, 3) {
    auto node3 = GET_SKILL_NODE(3, PhaseNode_StartPhase);
    if (node3 == nullptr) {
        node3 = new PhaseNode_StartPhase(3, phase);
        CALL_REGISTER_SKILL_NODE(10163, 3, node3)
    }
    if (noInit == true) {
        return node3;
    }
    return node3;
}
//--------------------------------------------------------------------------------
// Disable
//
REGISTER_REGISTER_SKILL_NODE(10163, 7) {
    pnode->resizeTrigger(PhaseNode_Disable::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_Disable::TRIGGER_DONE, 23, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10163, 7) {
    auto node7 = GET_SKILL_NODE(7, PhaseNode_Disable);
    if (node7 == nullptr) {
        node7 = new PhaseNode_Disable(7, phase);
        node7->setTarget(0U);
        node7->setMove(true);
        node7->setSkill(true);
        node7->setShoot(true);
        node7->setTime(1.13f);
        node7->setRotate(true);
        CALL_REGISTER_SKILL_NODE(10163, 7, node7)
    }
    if (noInit == true) {
        return node7;
    }
    return node7;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10163, 9) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_Delay::TRIGGER_DONE, 11, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(10163, 9) {
    auto node9 = GET_SKILL_NODE(9, PhaseNode_Delay);
    if (node9 == nullptr) {
        node9 = new PhaseNode_Delay(9, phase);
        node9->setTime(1.26f);
        CALL_REGISTER_SKILL_NODE(10163, 9, node9)
    }
    if (noInit == true) {
        return node9;
    }
    return node9;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(10163, 11) {
}

REGISTER_CREATE_SKILL_NODE(10163, 11) {
    auto node11 = GET_SKILL_NODE(11, PhaseNode_EndPhase);
    if (node11 == nullptr) {
        node11 = new PhaseNode_EndPhase(11, phase);
        node11->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node11->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10163, 11, node11)
    }
    if (noInit == true) {
        return node11;
    }
    return node11;
}
//--------------------------------------------------------------------------------
// SpawnProjectile
//
REGISTER_REGISTER_SKILL_NODE(10163, 13) {
}

REGISTER_CREATE_SKILL_NODE(10163, 13) {
    auto node13 = GET_SKILL_NODE(13, PhaseNode_SpawnProjectile);
    if (node13 == nullptr) {
        node13 = new PhaseNode_SpawnProjectile(13, phase);
        node13->setDataId(55163);
        node13->setPosX(.00f);
        node13->setPosY(.00f);
        node13->setPosZ(.00f);
        node13->setEndPosZ(.00f);
        node13->setRotation(.00f);
        node13->setMaxCount(0);
        CALL_REGISTER_SKILL_NODE(10163, 13, node13)
    }
    if (noInit == true) {
        return node13;
    }
    auto node17 = GET_SKILL_NODE(17, PhaseNode_GetInputLocation);
    if (node17 != nullptr) node13->setEndPosX(node17->getX());
    if (node17 != nullptr) node13->setEndPosY(node17->getY());
    return node13;
}
//--------------------------------------------------------------------------------
// GetInputLocation
//
REGISTER_REGISTER_SKILL_NODE(10163, 17) {
    pnode->resizeTrigger(PhaseNode_GetInputLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_GetInputLocation::TRIGGER_DONE, 28, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10163, 17) {
    auto node17 = GET_SKILL_NODE(17, PhaseNode_GetInputLocation);
    if (node17 == nullptr) {
        node17 = new PhaseNode_GetInputLocation(17, phase);
        node17->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        CALL_REGISTER_SKILL_NODE(10163, 17, node17)
    }
    if (noInit == true) {
        return node17;
    }
    return node17;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(10163, 21) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Disable>(PhaseNode_ResetCD::TRIGGER_DONE, 7, PhaseNode_Disable::FUNC_DO, &PhaseNode_Disable::Do);
}

REGISTER_CREATE_SKILL_NODE(10163, 21) {
    auto node21 = GET_SKILL_NODE(21, PhaseNode_ResetCD);
    if (node21 == nullptr) {
        node21 = new PhaseNode_ResetCD(21, phase);
        node21->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node21->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node21->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(10163, 21, node21)
    }
    if (noInit == true) {
        return node21;
    }
    return node21;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10163, 23) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_PlayAnimation::TRIGGER_DONE, 26, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10163, 23) {
    auto node23 = GET_SKILL_NODE(23, PhaseNode_PlayAnimation);
    if (node23 == nullptr) {
        node23 = new PhaseNode_PlayAnimation(23, phase);
        node23->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node23->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node23->setTarget(0U);
        node23->setAnimation("Skill3S1");
        node23->setParameter("SkillArmBusy");
        node23->setValue(true);
        CALL_REGISTER_SKILL_NODE(10163, 23, node23)
    }
    if (noInit == true) {
        return node23;
    }
    return node23;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10163, 26) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlaySound::TRIGGER_DONE, 9, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_GetInputLocation>(PhaseNode_PlaySound::TRIGGER_DONE, 17, PhaseNode_GetInputLocation::FUNC_DO, &PhaseNode_GetInputLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(10163, 26) {
    auto node26 = GET_SKILL_NODE(26, PhaseNode_PlaySound);
    if (node26 == nullptr) {
        node26 = new PhaseNode_PlaySound(26, phase);
        node26->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node26->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node26->setSoundID("");
        node26->setTarget(0U);
        node26->setUsePos(false);
        node26->setPosX(.00f);
        node26->setPosY(.00f);
        node26->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10163, 26, node26)
    }
    if (noInit == true) {
        return node26;
    }
    return node26;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10163, 28) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnProjectile>(PhaseNode_Delay::TRIGGER_DONE, 13, PhaseNode_SpawnProjectile::FUNC_DO, &PhaseNode_SpawnProjectile::Do);
}

REGISTER_CREATE_SKILL_NODE(10163, 28) {
    auto node28 = GET_SKILL_NODE(28, PhaseNode_Delay);
    if (node28 == nullptr) {
        node28 = new PhaseNode_Delay(28, phase);
        node28->setTime(.30f);
        CALL_REGISTER_SKILL_NODE(10163, 28, node28)
    }
    if (noInit == true) {
        return node28;
    }
    return node28;
}

//--------------------------------------------------------------------------------
// SkillCreator_10163
//
class SkillCreator_10163 : public SkillCreator {
public:
    SkillCreator_10163() {}
    virtual ~SkillCreator_10163() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_10163

//--------------------------------------------------------------------------------
// SkillPhase_10163
//
class SkillPhase_10163 : public SkillPhase {
public:
    SkillPhase_10163(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_10163() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(10163, 3) // StartPhase
        CASE_CREATE_SKILL_NODE(10163, 7) // Disable
        CASE_CREATE_SKILL_NODE(10163, 9) // Delay
        CASE_CREATE_SKILL_NODE(10163, 11) // EndPhase
        CASE_CREATE_SKILL_NODE(10163, 13) // SpawnProjectile
        CASE_CREATE_SKILL_NODE(10163, 17) // GetInputLocation
        CASE_CREATE_SKILL_NODE(10163, 21) // ResetCD
        CASE_CREATE_SKILL_NODE(10163, 23) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10163, 26) // PlaySound
        CASE_CREATE_SKILL_NODE(10163, 28) // Delay
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_10163

SkillLogic* SkillCreator_10163::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //创建阶段phase
    auto phase = new SkillPhase_10163(1, logic, 1);
    //设置phase执行器
    phase->setRunPhaseNode(1, 3);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_10163::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
