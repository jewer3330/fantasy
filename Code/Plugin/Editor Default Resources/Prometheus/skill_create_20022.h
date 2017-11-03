#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

#include "skill_psnode_addskillbuff.h"
#include "skill_psnode_delay.h"
#include "skill_psnode_detect.h"
#include "skill_psnode_endphase.h"
#include "skill_psnode_getlocation.h"
#include "skill_psnode_playanimation.h"
#include "skill_psnode_removeskillbuff.h"
#include "skill_psnode_resetcd.h"
#include "skill_psnode_skillendnotify.h"
#include "skill_psnode_spawncollider.h"
#include "skill_psnode_startphase.h"

namespace pvp {

//变量声明
//--------------------------------------------------------------------------------
// StartPhase
//
REGISTER_REGISTER_SKILL_NODE(20022, 1) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_StartPhase::TRIGGER_START, 2, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(20022, 1) {
    auto node1 = GET_SKILL_NODE(1, PhaseNode_StartPhase);
    if (node1 == nullptr) {
        node1 = new PhaseNode_StartPhase(1, phase);
        CALL_REGISTER_SKILL_NODE(20022, 1, node1)
    }
    if (noInit == true) {
        return node1;
    }
    return node1;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(20022, 2) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_ResetCD::TRIGGER_DONE, 3, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(20022, 2) {
    auto node2 = GET_SKILL_NODE(2, PhaseNode_ResetCD);
    if (node2 == nullptr) {
        node2 = new PhaseNode_ResetCD(2, phase);
        node2->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node2->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node2->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(20022, 2, node2)
    }
    if (noInit == true) {
        return node2;
    }
    return node2;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(20022, 3) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlayAnimation::TRIGGER_DONE, 6, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(20022, 3) {
    auto node3 = GET_SKILL_NODE(3, PhaseNode_PlayAnimation);
    if (node3 == nullptr) {
        node3 = new PhaseNode_PlayAnimation(3, phase);
        node3->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node3->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node3->setTarget(0U);
        node3->setAnimation("Skill2S1");
        node3->setParameter("");
        node3->setValue(false);
        CALL_REGISTER_SKILL_NODE(20022, 3, node3)
    }
    if (noInit == true) {
        return node3;
    }
    return node3;
}
//--------------------------------------------------------------------------------
// AddSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(20022, 4) {
    pnode->resizeTrigger(PhaseNode_AddSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_AddSkillBuff::TRIGGER_DONE, 5, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(20022, 4) {
    auto node4 = GET_SKILL_NODE(4, PhaseNode_AddSkillBuff);
    if (node4 == nullptr) {
        node4 = new PhaseNode_AddSkillBuff(4, phase);
        node4->setConfigID(200221);
        node4->setConfigIDs({});
        node4->setTarget(0U);
        node4->setAttribute({{}});
        CALL_REGISTER_SKILL_NODE(20022, 4, node4)
    }
    if (noInit == true) {
        return node4;
    }
    return node4;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(20022, 5) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlayAnimation::TRIGGER_DONE, 7, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(20022, 5) {
    auto node5 = GET_SKILL_NODE(5, PhaseNode_PlayAnimation);
    if (node5 == nullptr) {
        node5 = new PhaseNode_PlayAnimation(5, phase);
        node5->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node5->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node5->setTarget(0U);
        node5->setAnimation("ToSkill2S2");
        node5->setParameter("");
        node5->setValue(false);
        CALL_REGISTER_SKILL_NODE(20022, 5, node5)
    }
    if (noInit == true) {
        return node5;
    }
    return node5;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(20022, 6) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_Delay::TRIGGER_DONE, 15, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(20022, 6) {
    auto node6 = GET_SKILL_NODE(6, PhaseNode_Delay);
    if (node6 == nullptr) {
        node6 = new PhaseNode_Delay(6, phase);
        node6->setTime(.40f);
        CALL_REGISTER_SKILL_NODE(20022, 6, node6)
    }
    if (noInit == true) {
        return node6;
    }
    return node6;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(20022, 7) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RemoveSkillBuff>(PhaseNode_Delay::TRIGGER_DONE, 8, PhaseNode_RemoveSkillBuff::FUNC_REMOVE, &PhaseNode_RemoveSkillBuff::Remove);
}

REGISTER_CREATE_SKILL_NODE(20022, 7) {
    auto node7 = GET_SKILL_NODE(7, PhaseNode_Delay);
    if (node7 == nullptr) {
        node7 = new PhaseNode_Delay(7, phase);
        node7->setTime(3.00f);
        CALL_REGISTER_SKILL_NODE(20022, 7, node7)
    }
    if (noInit == true) {
        return node7;
    }
    return node7;
}
//--------------------------------------------------------------------------------
// RemoveSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(20022, 8) {
    pnode->resizeTrigger(PhaseNode_RemoveSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_RemoveSkillBuff::TRIGGER_DONE, 10, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(20022, 8) {
    auto node8 = GET_SKILL_NODE(8, PhaseNode_RemoveSkillBuff);
    if (node8 == nullptr) {
        node8 = new PhaseNode_RemoveSkillBuff(8, phase);
        node8->setBuffID(0U);
        node8->setBuffIDs({});
        node8->setConfigID(200221);
        node8->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(20022, 8, node8)
    }
    if (noInit == true) {
        return node8;
    }
    return node8;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(20022, 9) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_Delay::TRIGGER_DONE, 27, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
}

REGISTER_CREATE_SKILL_NODE(20022, 9) {
    auto node9 = GET_SKILL_NODE(9, PhaseNode_Delay);
    if (node9 == nullptr) {
        node9 = new PhaseNode_Delay(9, phase);
        node9->setTime(.40f);
        CALL_REGISTER_SKILL_NODE(20022, 9, node9)
    }
    if (noInit == true) {
        return node9;
    }
    return node9;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(20022, 10) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlayAnimation::TRIGGER_DONE, 9, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(20022, 10) {
    auto node10 = GET_SKILL_NODE(10, PhaseNode_PlayAnimation);
    if (node10 == nullptr) {
        node10 = new PhaseNode_PlayAnimation(10, phase);
        node10->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node10->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node10->setTarget(0U);
        node10->setAnimation("ToSkill2S3");
        node10->setParameter("");
        node10->setValue(false);
        CALL_REGISTER_SKILL_NODE(20022, 10, node10)
    }
    if (noInit == true) {
        return node10;
    }
    return node10;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(20022, 11) {
}

REGISTER_CREATE_SKILL_NODE(20022, 11) {
    auto node11 = GET_SKILL_NODE(11, PhaseNode_EndPhase);
    if (node11 == nullptr) {
        node11 = new PhaseNode_EndPhase(11, phase);
        node11->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node11->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(20022, 11, node11)
    }
    if (noInit == true) {
        return node11;
    }
    return node11;
}
//--------------------------------------------------------------------------------
// SpawnCollider
//
REGISTER_REGISTER_SKILL_NODE(20022, 14) {
    pnode->resizeTrigger(PhaseNode_SpawnCollider::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuff>(PhaseNode_SpawnCollider::TRIGGER_DONE, 4, PhaseNode_AddSkillBuff::FUNC_ADD, &PhaseNode_AddSkillBuff::Add);
}

REGISTER_CREATE_SKILL_NODE(20022, 14) {
    auto node14 = GET_SKILL_NODE(14, PhaseNode_SpawnCollider);
    if (node14 == nullptr) {
        node14 = new PhaseNode_SpawnCollider(14, phase);
        node14->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node14->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node14->setMesh("");
        node14->setMeshScale(.00f);
        node14->setEffectID(1104);
        node14->setEffectScale(1.00f);
        node14->setType(PhaseNode_SpawnCollider::SpawnCollider_Type::Circle);
        node14->setTypeParams(0, .10f);
        node14->setTime(.00f);
        node14->setPosZ(.00f);
        node14->setRotation(.00f);
        node14->setreentry(false);
        node14->setCheckPeneSound(false);
        CALL_REGISTER_SKILL_NODE(20022, 14, node14)
    }
    if (noInit == true) {
        return node14;
    }
    auto node15 = GET_SKILL_NODE(15, PhaseNode_GetLocation);
    if (node15 != nullptr) node14->setPosX(node15->getX());
    if (node15 != nullptr) node14->setPosY(node15->getY());
    return node14;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(20022, 15) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnCollider>(PhaseNode_GetLocation::TRIGGER_DONE, 14, PhaseNode_SpawnCollider::FUNC_DO, &PhaseNode_SpawnCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(20022, 15) {
    auto node15 = GET_SKILL_NODE(15, PhaseNode_GetLocation);
    if (node15 == nullptr) {
        node15 = new PhaseNode_GetLocation(15, phase);
        node15->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node15->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(20022, 15, node15)
    }
    if (noInit == true) {
        return node15;
    }
    return node15;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(20022, 24) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_Detect::TRIGGER_ON, 25, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(20022, 24) {
    auto node24 = GET_SKILL_NODE(24, PhaseNode_Detect);
    if (node24 == nullptr) {
        node24 = new PhaseNode_Detect(24, phase);
        node24->setSelf(0U);
        node24->setEvent("");
        node24->setType(PhaseNode_Detect::Detect_Type::Actor_Dead);
        node24->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(20022, 24, node24)
    }
    if (noInit == true) {
        return node24;
    }
    return node24;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(20022, 25) {
}

REGISTER_CREATE_SKILL_NODE(20022, 25) {
    auto node25 = GET_SKILL_NODE(25, PhaseNode_EndPhase);
    if (node25 == nullptr) {
        node25 = new PhaseNode_EndPhase(25, phase);
        node25->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node25->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(20022, 25, node25)
    }
    if (noInit == true) {
        return node25;
    }
    return node25;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(20022, 27) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 11, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(20022, 27) {
    auto node27 = GET_SKILL_NODE(27, PhaseNode_SkillEndNotify);
    if (node27 == nullptr) {
        node27 = new PhaseNode_SkillEndNotify(27, phase);
        node27->setReturnType(true);
        CALL_REGISTER_SKILL_NODE(20022, 27, node27)
    }
    if (noInit == true) {
        return node27;
    }
    return node27;
}

//--------------------------------------------------------------------------------
// SkillCreator_20022
//
class SkillCreator_20022 : public SkillCreator {
public:
    SkillCreator_20022() {}
    virtual ~SkillCreator_20022() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_20022

//--------------------------------------------------------------------------------
// SkillPhase_20022
//
class SkillPhase_20022 : public SkillPhase {
public:
    SkillPhase_20022(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_20022() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(20022, 1) // StartPhase
        CASE_CREATE_SKILL_NODE(20022, 2) // ResetCD
        CASE_CREATE_SKILL_NODE(20022, 3) // PlayAnimation
        CASE_CREATE_SKILL_NODE(20022, 4) // AddSkillBuff
        CASE_CREATE_SKILL_NODE(20022, 5) // PlayAnimation
        CASE_CREATE_SKILL_NODE(20022, 6) // Delay
        CASE_CREATE_SKILL_NODE(20022, 7) // Delay
        CASE_CREATE_SKILL_NODE(20022, 8) // RemoveSkillBuff
        CASE_CREATE_SKILL_NODE(20022, 9) // Delay
        CASE_CREATE_SKILL_NODE(20022, 10) // PlayAnimation
        CASE_CREATE_SKILL_NODE(20022, 11) // EndPhase
        CASE_CREATE_SKILL_NODE(20022, 14) // SpawnCollider
        CASE_CREATE_SKILL_NODE(20022, 15) // GetLocation
        CASE_CREATE_SKILL_NODE(20022, 24) // Detect
        CASE_CREATE_SKILL_NODE(20022, 25) // EndPhase
        CASE_CREATE_SKILL_NODE(20022, 27) // SkillEndNotify
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_20022

SkillLogic* SkillCreator_20022::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //创建阶段phase
    auto phase = new SkillPhase_20022(1, logic, 2);
    //设置phase执行器
    phase->setRunPhaseNode(1, 1);
    phase->setDetectPhaseNode(2, 24);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_20022::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
