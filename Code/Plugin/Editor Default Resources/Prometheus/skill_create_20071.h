#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

#include "skill_psnode_addskillbuff.h"
#include "skill_psnode_addskillbuffs.h"
#include "skill_psnode_attachto.h"
#include "skill_psnode_camerashake.h"
#include "skill_psnode_delay.h"
#include "skill_psnode_destroycollider.h"
#include "skill_psnode_endphase.h"
#include "skill_psnode_getinputlocation.h"
#include "skill_psnode_getlocation.h"
#include "skill_psnode_getrotation.h"
#include "skill_psnode_offsetcalculate.h"
#include "skill_psnode_playanimation.h"
#include "skill_psnode_playsound.h"
#include "skill_psnode_removeskillbuff.h"
#include "skill_psnode_resetcd.h"
#include "skill_psnode_spawncollider.h"
#include "skill_psnode_startphase.h"
#include "skill_psnode_triggerupdate.h"

namespace pvp {

//变量声明
//--------------------------------------------------------------------------------
// StartPhase
//
REGISTER_REGISTER_SKILL_NODE(20071, 1) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_StartPhase::TRIGGER_START, 12, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(20071, 1) {
    auto node1 = GET_SKILL_NODE(1, PhaseNode_StartPhase);
    if (node1 == nullptr) {
        node1 = new PhaseNode_StartPhase(1, phase);
        CALL_REGISTER_SKILL_NODE(20071, 1, node1)
    }
    if (noInit == true) {
        return node1;
    }
    return node1;
}
//--------------------------------------------------------------------------------
// TriggerUpdate
//
REGISTER_REGISTER_SKILL_NODE(20071, 3) {
}

REGISTER_CREATE_SKILL_NODE(20071, 3) {
    auto node3 = GET_SKILL_NODE(3, PhaseNode_TriggerUpdate);
    if (node3 == nullptr) {
        node3 = new PhaseNode_TriggerUpdate(3, phase);
        CALL_REGISTER_SKILL_NODE(20071, 3, node3)
    }
    if (noInit == true) {
        return node3;
    }
    return node3;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(20071, 4) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_PlayAnimation::TRIGGER_DONE, 11, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(20071, 4) {
    auto node4 = GET_SKILL_NODE(4, PhaseNode_PlayAnimation);
    if (node4 == nullptr) {
        node4 = new PhaseNode_PlayAnimation(4, phase);
        node4->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node4->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node4->setTarget(0U);
        node4->setAnimation("Skill1S1");
        node4->setParameter("");
        node4->setValue(false);
        CALL_REGISTER_SKILL_NODE(20071, 4, node4)
    }
    if (noInit == true) {
        return node4;
    }
    return node4;
}
//--------------------------------------------------------------------------------
// SpawnCollider
//
REGISTER_REGISTER_SKILL_NODE(20071, 9) {
    pnode->resizeTrigger(PhaseNode_SpawnCollider::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CameraShake>(PhaseNode_SpawnCollider::TRIGGER_DONE, 109, PhaseNode_CameraShake::FUNC_DO, &PhaseNode_CameraShake::Do);
}

REGISTER_CREATE_SKILL_NODE(20071, 9) {
    auto node9 = GET_SKILL_NODE(9, PhaseNode_SpawnCollider);
    if (node9 == nullptr) {
        node9 = new PhaseNode_SpawnCollider(9, phase);
        node9->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node9->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node9->setMesh("");
        node9->setMeshScale(.00f);
        node9->setEffectID(1014);
        node9->setEffectScale(1.50f);
        node9->setType(PhaseNode_SpawnCollider::SpawnCollider_Type::Circle);
        node9->setTypeParams(0, .00f);
        node9->setTime(.00f);
        node9->setPosZ(.20f);
        node9->setRotation(.00f);
        node9->setreentry(false);
        node9->setCheckPeneSound(false);
        CALL_REGISTER_SKILL_NODE(20071, 9, node9)
    }
    if (noInit == true) {
        return node9;
    }
    auto node8 = GET_SKILL_NODE(8, PhaseNode_GetInputLocation);
    if (node8 != nullptr) node9->setPosX(node8->getX());
    if (node8 != nullptr) node9->setPosY(node8->getY());
    return node9;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(20071, 11) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnCollider>(PhaseNode_PlaySound::TRIGGER_DONE, 70, PhaseNode_SpawnCollider::FUNC_DO, &PhaseNode_SpawnCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(20071, 11) {
    auto node11 = GET_SKILL_NODE(11, PhaseNode_PlaySound);
    if (node11 == nullptr) {
        node11 = new PhaseNode_PlaySound(11, phase);
        node11->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node11->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node11->setSoundID("");
        node11->setTarget(0U);
        node11->setUsePos(false);
        node11->setPosX(.00f);
        node11->setPosY(.00f);
        node11->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(20071, 11, node11)
    }
    if (noInit == true) {
        return node11;
    }
    return node11;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(20071, 12) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_ResetCD::TRIGGER_DONE, 65, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(20071, 12) {
    auto node12 = GET_SKILL_NODE(12, PhaseNode_ResetCD);
    if (node12 == nullptr) {
        node12 = new PhaseNode_ResetCD(12, phase);
        node12->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node12->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node12->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(20071, 12, node12)
    }
    if (noInit == true) {
        return node12;
    }
    return node12;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(20071, 25) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_Delay::TRIGGER_DONE, 26, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(20071, 25) {
    auto node25 = GET_SKILL_NODE(25, PhaseNode_Delay);
    if (node25 == nullptr) {
        node25 = new PhaseNode_Delay(25, phase);
        node25->setTime(1.00f);
        CALL_REGISTER_SKILL_NODE(20071, 25, node25)
    }
    if (noInit == true) {
        return node25;
    }
    return node25;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(20071, 26) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnCollider>(PhaseNode_PlayAnimation::TRIGGER_DONE, 27, PhaseNode_SpawnCollider::FUNC_DO, &PhaseNode_SpawnCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(20071, 26) {
    auto node26 = GET_SKILL_NODE(26, PhaseNode_PlayAnimation);
    if (node26 == nullptr) {
        node26 = new PhaseNode_PlayAnimation(26, phase);
        node26->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node26->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node26->setTarget(0U);
        node26->setAnimation("Skill1S2");
        node26->setParameter("");
        node26->setValue(false);
        CALL_REGISTER_SKILL_NODE(20071, 26, node26)
    }
    if (noInit == true) {
        return node26;
    }
    return node26;
}
//--------------------------------------------------------------------------------
// SpawnCollider
//
REGISTER_REGISTER_SKILL_NODE(20071, 27) {
}

REGISTER_CREATE_SKILL_NODE(20071, 27) {
    auto node27 = GET_SKILL_NODE(27, PhaseNode_SpawnCollider);
    if (node27 == nullptr) {
        node27 = new PhaseNode_SpawnCollider(27, phase);
        node27->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node27->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node27->setMesh("");
        node27->setMeshScale(.00f);
        node27->setEffectID(200711);
        node27->setEffectScale(1.00f);
        node27->setType(PhaseNode_SpawnCollider::SpawnCollider_Type::Circle);
        node27->setTypeParams(0, 3.00f);
        node27->setTime(.00f);
        node27->setPosZ(.00f);
        node27->setRotation(.00f);
        node27->setreentry(false);
        node27->setCheckPeneSound(false);
        CALL_REGISTER_SKILL_NODE(20071, 27, node27)
    }
    if (noInit == true) {
        return node27;
    }
    auto node8 = GET_SKILL_NODE(8, PhaseNode_GetInputLocation);
    if (node8 != nullptr) node27->setPosX(node8->getX());
    if (node8 != nullptr) node27->setPosY(node8->getY());
    return node27;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(20071, 65) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetRotation>(PhaseNode_GetLocation::TRIGGER_DONE, 68, PhaseNode_GetRotation::FUNC_DO, &PhaseNode_GetRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(20071, 65) {
    auto node65 = GET_SKILL_NODE(65, PhaseNode_GetLocation);
    if (node65 == nullptr) {
        node65 = new PhaseNode_GetLocation(65, phase);
        node65->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node65->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(20071, 65, node65)
    }
    if (noInit == true) {
        return node65;
    }
    return node65;
}
//--------------------------------------------------------------------------------
// SpawnCollider
//
REGISTER_REGISTER_SKILL_NODE(20071, 66) {
    pnode->resizeTrigger(PhaseNode_SpawnCollider::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_SpawnCollider::TRIGGER_DONE, 142, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(20071, 66) {
    auto node66 = GET_SKILL_NODE(66, PhaseNode_SpawnCollider);
    if (node66 == nullptr) {
        node66 = new PhaseNode_SpawnCollider(66, phase);
        node66->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node66->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node66->setMesh("");
        node66->setMeshScale(.00f);
        node66->setEffectID(1014);
        node66->setEffectScale(1.50f);
        node66->setType(PhaseNode_SpawnCollider::SpawnCollider_Type::Circle);
        node66->setTypeParams(0, .00f);
        node66->setTime(.00f);
        node66->setreentry(false);
        node66->setCheckPeneSound(false);
        CALL_REGISTER_SKILL_NODE(20071, 66, node66)
    }
    if (noInit == true) {
        return node66;
    }
    auto node67 = GET_SKILL_NODE(67, PhaseNode_OffsetCalculate);
    if (node67 != nullptr) node66->setPosX(node67->getOutPosX());
    if (node67 != nullptr) node66->setPosY(node67->getOutPosY());
    if (node67 != nullptr) node66->setPosZ(node67->getOutPosZ());
    if (node67 != nullptr) node66->setRotation(node67->getOutRotation());
    return node66;
}
//--------------------------------------------------------------------------------
// OffsetCalculate
//
REGISTER_REGISTER_SKILL_NODE(20071, 67) {
    pnode->resizeTrigger(PhaseNode_OffsetCalculate::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnCollider>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 66, PhaseNode_SpawnCollider::FUNC_DO, &PhaseNode_SpawnCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(20071, 67) {
    auto node67 = GET_SKILL_NODE(67, PhaseNode_OffsetCalculate);
    if (node67 == nullptr) {
        node67 = new PhaseNode_OffsetCalculate(67, phase);
        node67->setPosZ(.00f);
        node67->setOffsetX(.00f);
        node67->setOffsetY(5.00f);
        node67->setOffsetZ(.20f);
        node67->setRotOffset(.00f);
        CALL_REGISTER_SKILL_NODE(20071, 67, node67)
    }
    if (noInit == true) {
        return node67;
    }
    auto node65 = GET_SKILL_NODE(65, PhaseNode_GetLocation);
    auto node68 = GET_SKILL_NODE(68, PhaseNode_GetRotation);
    if (node65 != nullptr) node67->setPosX(node65->getX());
    if (node65 != nullptr) node67->setPosY(node65->getY());
    if (node68 != nullptr) node67->setRotation(node68->getAngle());
    return node67;
}
//--------------------------------------------------------------------------------
// GetRotation
//
REGISTER_REGISTER_SKILL_NODE(20071, 68) {
    pnode->resizeTrigger(PhaseNode_GetRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_OffsetCalculate>(PhaseNode_GetRotation::TRIGGER_DONE, 67, PhaseNode_OffsetCalculate::FUNC_DO, &PhaseNode_OffsetCalculate::Do);
}

REGISTER_CREATE_SKILL_NODE(20071, 68) {
    auto node68 = GET_SKILL_NODE(68, PhaseNode_GetRotation);
    if (node68 == nullptr) {
        node68 = new PhaseNode_GetRotation(68, phase);
        node68->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node68->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(20071, 68, node68)
    }
    if (noInit == true) {
        return node68;
    }
    return node68;
}
//--------------------------------------------------------------------------------
// SpawnCollider
//
REGISTER_REGISTER_SKILL_NODE(20071, 70) {
}

REGISTER_CREATE_SKILL_NODE(20071, 70) {
    auto node70 = GET_SKILL_NODE(70, PhaseNode_SpawnCollider);
    if (node70 == nullptr) {
        node70 = new PhaseNode_SpawnCollider(70, phase);
        node70->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node70->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node70->setMesh("");
        node70->setMeshScale(.00f);
        node70->setEffectID(200711);
        node70->setEffectScale(1.00f);
        node70->setType(PhaseNode_SpawnCollider::SpawnCollider_Type::Circle);
        node70->setTypeParams(0, 3.00f);
        node70->setTime(.00f);
        node70->setPosZ(.00f);
        node70->setreentry(false);
        node70->setCheckPeneSound(false);
        CALL_REGISTER_SKILL_NODE(20071, 70, node70)
    }
    if (noInit == true) {
        return node70;
    }
    auto node67 = GET_SKILL_NODE(67, PhaseNode_OffsetCalculate);
    auto node68 = GET_SKILL_NODE(68, PhaseNode_GetRotation);
    if (node67 != nullptr) node70->setPosX(node67->getOutPosX());
    if (node67 != nullptr) node70->setPosY(node67->getOutPosY());
    if (node68 != nullptr) node70->setRotation(node68->getAngle());
    return node70;
}
//--------------------------------------------------------------------------------
// CameraShake
//
REGISTER_REGISTER_SKILL_NODE(20071, 109) {
    pnode->resizeTrigger(PhaseNode_CameraShake::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CameraShake::TRIGGER_DONE, 25, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(20071, 109) {
    auto node109 = GET_SKILL_NODE(109, PhaseNode_CameraShake);
    if (node109 == nullptr) {
        node109 = new PhaseNode_CameraShake(109, phase);
        node109->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node109->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node109->setTarget(0U);
        node109->setFrequency(.10f);
        node109->setAmplitude(2.00f);
        node109->setDuration(1.00f);
        node109->setFalloff(false);
        CALL_REGISTER_SKILL_NODE(20071, 109, node109)
    }
    if (noInit == true) {
        return node109;
    }
    return node109;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(20071, 142) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_Delay::TRIGGER_DONE, 4, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(20071, 142) {
    auto node142 = GET_SKILL_NODE(142, PhaseNode_Delay);
    if (node142 == nullptr) {
        node142 = new PhaseNode_Delay(142, phase);
        node142->setTime(.50f);
        CALL_REGISTER_SKILL_NODE(20071, 142, node142)
    }
    if (noInit == true) {
        return node142;
    }
    return node142;
}

//--------------------------------------------------------------------------------
// SkillCreator_20071
//
class SkillCreator_20071 : public SkillCreator {
public:
    SkillCreator_20071() {}
    virtual ~SkillCreator_20071() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_20071

//--------------------------------------------------------------------------------
// SkillPhase_20071
//
class SkillPhase_20071 : public SkillPhase {
public:
    SkillPhase_20071(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_20071() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(20071, 1) // StartPhase
        CASE_CREATE_SKILL_NODE(20071, 3) // TriggerUpdate
        CASE_CREATE_SKILL_NODE(20071, 4) // PlayAnimation
        CASE_CREATE_SKILL_NODE(20071, 9) // SpawnCollider
        CASE_CREATE_SKILL_NODE(20071, 11) // PlaySound
        CASE_CREATE_SKILL_NODE(20071, 12) // ResetCD
        CASE_CREATE_SKILL_NODE(20071, 25) // Delay
        CASE_CREATE_SKILL_NODE(20071, 26) // PlayAnimation
        CASE_CREATE_SKILL_NODE(20071, 27) // SpawnCollider
        CASE_CREATE_SKILL_NODE(20071, 65) // GetLocation
        CASE_CREATE_SKILL_NODE(20071, 66) // SpawnCollider
        CASE_CREATE_SKILL_NODE(20071, 67) // OffsetCalculate
        CASE_CREATE_SKILL_NODE(20071, 68) // GetRotation
        CASE_CREATE_SKILL_NODE(20071, 70) // SpawnCollider
        CASE_CREATE_SKILL_NODE(20071, 109) // CameraShake
        CASE_CREATE_SKILL_NODE(20071, 142) // Delay
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_20071

SkillLogic* SkillCreator_20071::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //创建阶段phase
    auto phase = new SkillPhase_20071(1, logic, 2);
    //设置phase执行器
    phase->setRunPhaseNode(1, 1);
    phase->setRunPhaseNode(2, 3);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_20071::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
