#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

#include "skill_psnode_addskillbuff.h"
#include "skill_psnode_attachto.h"
#include "skill_psnode_delay.h"
#include "skill_psnode_disable.h"
#include "skill_psnode_endphase.h"
#include "skill_psnode_getinputrotation.h"
#include "skill_psnode_getlocation.h"
#include "skill_psnode_movenewpene.h"
#include "skill_psnode_offsetcalculate.h"
#include "skill_psnode_playsound.h"
#include "skill_psnode_resetcd.h"
#include "skill_psnode_spawncollider.h"
#include "skill_psnode_startphase.h"

namespace pvp {

//变量声明
//--------------------------------------------------------------------------------
// StartPhase
//
REGISTER_REGISTER_SKILL_NODE(10271, 3) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_StartPhase::TRIGGER_START, 5, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(10271, 3) {
    auto node3 = GET_SKILL_NODE(3, PhaseNode_StartPhase);
    if (node3 == nullptr) {
        node3 = new PhaseNode_StartPhase(3, phase);
        CALL_REGISTER_SKILL_NODE(10271, 3, node3)
    }
    if (noInit == true) {
        return node3;
    }
    return node3;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(10271, 5) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Disable>(PhaseNode_ResetCD::TRIGGER_DONE, 61, PhaseNode_Disable::FUNC_DO, &PhaseNode_Disable::Do);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_ResetCD::TRIGGER_DONE, 134, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_ResetCD::TRIGGER_DONE, 153, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10271, 5) {
    auto node5 = GET_SKILL_NODE(5, PhaseNode_ResetCD);
    if (node5 == nullptr) {
        node5 = new PhaseNode_ResetCD(5, phase);
        node5->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node5->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node5->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(10271, 5, node5)
    }
    if (noInit == true) {
        return node5;
    }
    return node5;
}
//--------------------------------------------------------------------------------
// OffsetCalculate
//
REGISTER_REGISTER_SKILL_NODE(10271, 22) {
    pnode->resizeTrigger(PhaseNode_OffsetCalculate::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_MoveNewPene>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 149, PhaseNode_MoveNewPene::FUNC_DO, &PhaseNode_MoveNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(10271, 22) {
    auto node22 = GET_SKILL_NODE(22, PhaseNode_OffsetCalculate);
    if (node22 == nullptr) {
        node22 = new PhaseNode_OffsetCalculate(22, phase);
        node22->setPosZ(.00f);
        node22->setOffsetX(.00f);
        node22->setOffsetY(5.50f);
        node22->setOffsetZ(.00f);
        node22->setRotOffset(.00f);
        CALL_REGISTER_SKILL_NODE(10271, 22, node22)
    }
    if (noInit == true) {
        return node22;
    }
    auto node36 = GET_SKILL_NODE(36, PhaseNode_GetLocation);
    auto node151 = GET_SKILL_NODE(151, PhaseNode_GetInputRotation);
    if (node36 != nullptr) node22->setPosX(node36->getX());
    if (node36 != nullptr) node22->setPosY(node36->getY());
    if (node151 != nullptr) node22->setRotation(node151->getAngle());
    return node22;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10271, 25) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnCollider>(PhaseNode_Delay::TRIGGER_DONE, 125, PhaseNode_SpawnCollider::FUNC_DO, &PhaseNode_SpawnCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(10271, 25) {
    auto node25 = GET_SKILL_NODE(25, PhaseNode_Delay);
    if (node25 == nullptr) {
        node25 = new PhaseNode_Delay(25, phase);
        node25->setTime(.05f);
        CALL_REGISTER_SKILL_NODE(10271, 25, node25)
    }
    if (noInit == true) {
        return node25;
    }
    return node25;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(10271, 29) {
}

REGISTER_CREATE_SKILL_NODE(10271, 29) {
    auto node29 = GET_SKILL_NODE(29, PhaseNode_EndPhase);
    if (node29 == nullptr) {
        node29 = new PhaseNode_EndPhase(29, phase);
        node29->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node29->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10271, 29, node29)
    }
    if (noInit == true) {
        return node29;
    }
    return node29;
}
//--------------------------------------------------------------------------------
// SpawnCollider
//
REGISTER_REGISTER_SKILL_NODE(10271, 32) {
    pnode->resizeTrigger(PhaseNode_SpawnCollider::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AttachTo>(PhaseNode_SpawnCollider::TRIGGER_DONE, 34, PhaseNode_AttachTo::FUNC_DO, &PhaseNode_AttachTo::Do);
}

REGISTER_CREATE_SKILL_NODE(10271, 32) {
    auto node32 = GET_SKILL_NODE(32, PhaseNode_SpawnCollider);
    if (node32 == nullptr) {
        node32 = new PhaseNode_SpawnCollider(32, phase);
        node32->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node32->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node32->setMesh("");
        node32->setMeshScale(.00f);
        node32->setEffectID(0);
        node32->setEffectScale(.00f);
        node32->setType(PhaseNode_SpawnCollider::SpawnCollider_Type::Circle);
        node32->setTypeParams(0, .70f);
        node32->setTime(.30f);
        node32->setPosZ(.00f);
        node32->setRotation(.00f);
        node32->setreentry(false);
        node32->setCheckPeneSound(false);
        CALL_REGISTER_SKILL_NODE(10271, 32, node32)
    }
    if (noInit == true) {
        return node32;
    }
    auto node36 = GET_SKILL_NODE(36, PhaseNode_GetLocation);
    if (node36 != nullptr) node32->setPosX(node36->getX());
    if (node36 != nullptr) node32->setPosY(node36->getY());
    return node32;
}
//--------------------------------------------------------------------------------
// AttachTo
//
REGISTER_REGISTER_SKILL_NODE(10271, 34) {
    pnode->resizeTrigger(PhaseNode_AttachTo::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_OffsetCalculate>(PhaseNode_AttachTo::TRIGGER_DONE, 22, PhaseNode_OffsetCalculate::FUNC_DO, &PhaseNode_OffsetCalculate::Do);
}

REGISTER_CREATE_SKILL_NODE(10271, 34) {
    auto node34 = GET_SKILL_NODE(34, PhaseNode_AttachTo);
    if (node34 == nullptr) {
        node34 = new PhaseNode_AttachTo(34, phase);
        node34->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node34->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node34->setChild(0U);
        node34->setChangeRotation(false);
        node34->setreentry(false);
        CALL_REGISTER_SKILL_NODE(10271, 34, node34)
    }
    if (noInit == true) {
        return node34;
    }
    auto node32 = GET_SKILL_NODE(32, PhaseNode_SpawnCollider);
    if (node32 != nullptr) node34->setParent(node32->getColliderID());
    return node34;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(10271, 36) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetInputRotation>(PhaseNode_GetLocation::TRIGGER_DONE, 151, PhaseNode_GetInputRotation::FUNC_DO, &PhaseNode_GetInputRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(10271, 36) {
    auto node36 = GET_SKILL_NODE(36, PhaseNode_GetLocation);
    if (node36 == nullptr) {
        node36 = new PhaseNode_GetLocation(36, phase);
        node36->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node36->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(10271, 36, node36)
    }
    if (noInit == true) {
        return node36;
    }
    return node36;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10271, 53) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_Delay::TRIGGER_DONE, 29, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(10271, 53) {
    auto node53 = GET_SKILL_NODE(53, PhaseNode_Delay);
    if (node53 == nullptr) {
        node53 = new PhaseNode_Delay(53, phase);
        node53->setTime(.05f);
        CALL_REGISTER_SKILL_NODE(10271, 53, node53)
    }
    if (noInit == true) {
        return node53;
    }
    return node53;
}
//--------------------------------------------------------------------------------
// Disable
//
REGISTER_REGISTER_SKILL_NODE(10271, 61) {
    pnode->resizeTrigger(PhaseNode_Disable::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_Disable::TRIGGER_DONE, 36, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(10271, 61) {
    auto node61 = GET_SKILL_NODE(61, PhaseNode_Disable);
    if (node61 == nullptr) {
        node61 = new PhaseNode_Disable(61, phase);
        node61->setTarget(0U);
        node61->setMove(true);
        node61->setSkill(true);
        node61->setShoot(false);
        node61->setTime(.10f);
        node61->setRotate(true);
        CALL_REGISTER_SKILL_NODE(10271, 61, node61)
    }
    if (noInit == true) {
        return node61;
    }
    return node61;
}
//--------------------------------------------------------------------------------
// AddSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10271, 86) {
    pnode->resizeTrigger(PhaseNode_AddSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_AddSkillBuff::TRIGGER_DONE, 53, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10271, 86) {
    auto node86 = GET_SKILL_NODE(86, PhaseNode_AddSkillBuff);
    if (node86 == nullptr) {
        node86 = new PhaseNode_AddSkillBuff(86, phase);
        node86->setConfigID(102741);
        node86->setConfigIDs({});
        node86->setTarget(0U);
        node86->setAttribute({{}});
        CALL_REGISTER_SKILL_NODE(10271, 86, node86)
    }
    if (noInit == true) {
        return node86;
    }
    return node86;
}
//--------------------------------------------------------------------------------
// AddSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10271, 115) {
    pnode->resizeTrigger(PhaseNode_AddSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_AddSkillBuff::TRIGGER_DONE, 25, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10271, 115) {
    auto node115 = GET_SKILL_NODE(115, PhaseNode_AddSkillBuff);
    if (node115 == nullptr) {
        node115 = new PhaseNode_AddSkillBuff(115, phase);
        node115->setConfigID(102711);
        node115->setConfigIDs({});
        node115->setTarget(0U);
        node115->setAttribute({{}});
        CALL_REGISTER_SKILL_NODE(10271, 115, node115)
    }
    if (noInit == true) {
        return node115;
    }
    return node115;
}
//--------------------------------------------------------------------------------
// SpawnCollider
//
REGISTER_REGISTER_SKILL_NODE(10271, 125) {
    pnode->resizeTrigger(PhaseNode_SpawnCollider::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnCollider>(PhaseNode_SpawnCollider::TRIGGER_DONE, 32, PhaseNode_SpawnCollider::FUNC_DO, &PhaseNode_SpawnCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(10271, 125) {
    auto node125 = GET_SKILL_NODE(125, PhaseNode_SpawnCollider);
    if (node125 == nullptr) {
        node125 = new PhaseNode_SpawnCollider(125, phase);
        node125->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node125->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node125->setMesh("");
        node125->setMeshScale(.00f);
        node125->setEffectID(102712);
        node125->setEffectScale(1.00f);
        node125->setType(PhaseNode_SpawnCollider::SpawnCollider_Type::Circle);
        node125->setTypeParams(0, .00f);
        node125->setTime(.00f);
        node125->setPosZ(.00f);
        node125->setRotation(.00f);
        node125->setreentry(false);
        node125->setCheckPeneSound(false);
        CALL_REGISTER_SKILL_NODE(10271, 125, node125)
    }
    if (noInit == true) {
        return node125;
    }
    auto node36 = GET_SKILL_NODE(36, PhaseNode_GetLocation);
    if (node36 != nullptr) node125->setPosX(node36->getX());
    if (node36 != nullptr) node125->setPosY(node36->getY());
    return node125;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10271, 134) {
}

REGISTER_CREATE_SKILL_NODE(10271, 134) {
    auto node134 = GET_SKILL_NODE(134, PhaseNode_PlaySound);
    if (node134 == nullptr) {
        node134 = new PhaseNode_PlaySound(134, phase);
        node134->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node134->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node134->setSoundID("SE_Hero110_SkillA_P1");
        node134->setTarget(0U);
        node134->setUsePos(false);
        node134->setPosX(.00f);
        node134->setPosY(.00f);
        node134->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10271, 134, node134)
    }
    if (noInit == true) {
        return node134;
    }
    return node134;
}
//--------------------------------------------------------------------------------
// MoveNewPene
//
REGISTER_REGISTER_SKILL_NODE(10271, 149) {
    pnode->resizeTrigger(PhaseNode_MoveNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuff>(PhaseNode_MoveNewPene::TRIGGER_STARTMOVE, 86, PhaseNode_AddSkillBuff::FUNC_ADD, &PhaseNode_AddSkillBuff::Add);
}

REGISTER_CREATE_SKILL_NODE(10271, 149) {
    auto node149 = GET_SKILL_NODE(149, PhaseNode_MoveNewPene);
    if (node149 == nullptr) {
        node149 = new PhaseNode_MoveNewPene(149, phase);
        node149->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node149->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node149->setPeneType(PhaseNode_MoveNewPene::MoveNewPene_PeneType::Move);
        node149->setPeneValue(15);
        node149->setType(PhaseNode_MoveNewPene::MoveNewPene_Type::Teleport);
        node149->getVars().reserve(2);
        node149->getVars().setVariable<float>(0, .00f);
        node149->getVars().setVariable<float>(1, .00f);
        node149->setreentry(false);
        node149->setStopWhenFail(true);
        node149->setCheckFaction(PhaseNode_MoveNewPene::MoveNewPene_CheckFaction::Enemy);
        CALL_REGISTER_SKILL_NODE(10271, 149, node149)
    }
    if (noInit == true) {
        return node149;
    }
    auto node32 = GET_SKILL_NODE(32, PhaseNode_SpawnCollider);
    auto node22 = GET_SKILL_NODE(22, PhaseNode_OffsetCalculate);
    if (node32 != nullptr) node149->setTarget(node32->getColliderID());
    if (node22 != nullptr) node149->getVars().setVariable<float>(0, node22->getOutPosX());
    if (node22 != nullptr) node149->getVars().setVariable<float>(1, node22->getOutPosY());
    return node149;
}
//--------------------------------------------------------------------------------
// GetInputRotation
//
REGISTER_REGISTER_SKILL_NODE(10271, 151) {
    pnode->resizeTrigger(PhaseNode_GetInputRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuff>(PhaseNode_GetInputRotation::TRIGGER_DONE, 115, PhaseNode_AddSkillBuff::FUNC_ADD, &PhaseNode_AddSkillBuff::Add);
}

REGISTER_CREATE_SKILL_NODE(10271, 151) {
    auto node151 = GET_SKILL_NODE(151, PhaseNode_GetInputRotation);
    if (node151 == nullptr) {
        node151 = new PhaseNode_GetInputRotation(151, phase);
        node151->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        CALL_REGISTER_SKILL_NODE(10271, 151, node151)
    }
    if (noInit == true) {
        return node151;
    }
    return node151;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10271, 153) {
}

REGISTER_CREATE_SKILL_NODE(10271, 153) {
    auto node153 = GET_SKILL_NODE(153, PhaseNode_PlaySound);
    if (node153 == nullptr) {
        node153 = new PhaseNode_PlaySound(153, phase);
        node153->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node153->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node153->setSoundID("VO_Hero110_Skill_A");
        node153->setTarget(0U);
        node153->setUsePos(false);
        node153->setPosX(.00f);
        node153->setPosY(.00f);
        node153->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10271, 153, node153)
    }
    if (noInit == true) {
        return node153;
    }
    return node153;
}

//--------------------------------------------------------------------------------
// SkillCreator_10271
//
class SkillCreator_10271 : public SkillCreator {
public:
    SkillCreator_10271() {}
    virtual ~SkillCreator_10271() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_10271

//--------------------------------------------------------------------------------
// SkillPhase_10271
//
class SkillPhase_10271 : public SkillPhase {
public:
    SkillPhase_10271(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_10271() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(10271, 3) // StartPhase
        CASE_CREATE_SKILL_NODE(10271, 5) // ResetCD
        CASE_CREATE_SKILL_NODE(10271, 22) // OffsetCalculate
        CASE_CREATE_SKILL_NODE(10271, 25) // Delay
        CASE_CREATE_SKILL_NODE(10271, 29) // EndPhase
        CASE_CREATE_SKILL_NODE(10271, 32) // SpawnCollider
        CASE_CREATE_SKILL_NODE(10271, 34) // AttachTo
        CASE_CREATE_SKILL_NODE(10271, 36) // GetLocation
        CASE_CREATE_SKILL_NODE(10271, 53) // Delay
        CASE_CREATE_SKILL_NODE(10271, 61) // Disable
        CASE_CREATE_SKILL_NODE(10271, 86) // AddSkillBuff
        CASE_CREATE_SKILL_NODE(10271, 115) // AddSkillBuff
        CASE_CREATE_SKILL_NODE(10271, 125) // SpawnCollider
        CASE_CREATE_SKILL_NODE(10271, 134) // PlaySound
        CASE_CREATE_SKILL_NODE(10271, 149) // MoveNewPene
        CASE_CREATE_SKILL_NODE(10271, 151) // GetInputRotation
        CASE_CREATE_SKILL_NODE(10271, 153) // PlaySound
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_10271

SkillLogic* SkillCreator_10271::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //创建阶段phase
    auto phase = new SkillPhase_10271(1, logic, 1);
    //设置phase执行器
    phase->setRunPhaseNode(1, 3);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_10271::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
