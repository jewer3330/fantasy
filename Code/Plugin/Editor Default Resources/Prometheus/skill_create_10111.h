#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

#include "skill_psnode_actorfilternewpene.h"
#include "skill_psnode_addskillbuff.h"
#include "skill_psnode_addskillbuffs.h"
#include "skill_psnode_attachto.h"
#include "skill_psnode_cameraxyzshake.h"
#include "skill_psnode_createtriggernewpene.h"
#include "skill_psnode_delay.h"
#include "skill_psnode_detect.h"
#include "skill_psnode_disable.h"
#include "skill_psnode_endphase.h"
#include "skill_psnode_for.h"
#include "skill_psnode_forcontinue.h"
#include "skill_psnode_getactorattribute.h"
#include "skill_psnode_getinputrotation.h"
#include "skill_psnode_getlocation.h"
#include "skill_psnode_getuint64svalue.h"
#include "skill_psnode_if.h"
#include "skill_psnode_isinterrupttype.h"
#include "skill_psnode_linechecknewpene.h"
#include "skill_psnode_movenewpene.h"
#include "skill_psnode_offsetcalculate.h"
#include "skill_psnode_playanimation.h"
#include "skill_psnode_playsound.h"
#include "skill_psnode_raiseevent.h"
#include "skill_psnode_resetcd.h"
#include "skill_psnode_setbool.h"
#include "skill_psnode_setint.h"
#include "skill_psnode_spawncollider.h"
#include "skill_psnode_startphase.h"
#include "skill_psnode_startpreinput.h"
#include "skill_psnode_switchtoint.h"
#include "skill_psnode_triggercheck.h"
#include "skill_psnode_triggerupdate.h"
#include "skill_psnode_uint64ssize.h"

namespace pvp {

//变量声明
uint64_t Variable_10111_a101112 = 0;
uint64_t Variable_10111_InterruptAnimat = 0;
//--------------------------------------------------------------------------------
// StartPhase
//
REGISTER_REGISTER_SKILL_NODE(10111, 1) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_StartPhase::TRIGGER_START, 453, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(10111, 1) {
    auto node1 = GET_SKILL_NODE(1, PhaseNode_StartPhase);
    if (node1 == nullptr) {
        node1 = new PhaseNode_StartPhase(1, phase);
        CALL_REGISTER_SKILL_NODE(10111, 1, node1)
    }
    if (noInit == true) {
        return node1;
    }
    return node1;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10111, 8) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_OffsetCalculate>(PhaseNode_Delay::TRIGGER_DONE, 180, PhaseNode_OffsetCalculate::FUNC_DO, &PhaseNode_OffsetCalculate::Do);
    pnode->regTrigger<PhaseNode_SetInt>(PhaseNode_Delay::TRIGGER_DONE, 436, PhaseNode_SetInt::FUNC_SET, &PhaseNode_SetInt::Set);
}

REGISTER_CREATE_SKILL_NODE(10111, 8) {
    auto node8 = GET_SKILL_NODE(8, PhaseNode_Delay);
    if (node8 == nullptr) {
        node8 = new PhaseNode_Delay(8, phase);
        node8->setTime(.10f);
        CALL_REGISTER_SKILL_NODE(10111, 8, node8)
    }
    if (noInit == true) {
        return node8;
    }
    return node8;
}
//--------------------------------------------------------------------------------
// TriggerUpdate
//
REGISTER_REGISTER_SKILL_NODE(10111, 9) {
}

REGISTER_CREATE_SKILL_NODE(10111, 9) {
    auto node9 = GET_SKILL_NODE(9, PhaseNode_TriggerUpdate);
    if (node9 == nullptr) {
        node9 = new PhaseNode_TriggerUpdate(9, phase);
        CALL_REGISTER_SKILL_NODE(10111, 9, node9)
    }
    if (noInit == true) {
        return node9;
    }
    return node9;
}
//--------------------------------------------------------------------------------
// SpawnCollider
//
REGISTER_REGISTER_SKILL_NODE(10111, 12) {
    pnode->resizeTrigger(PhaseNode_SpawnCollider::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AttachTo>(PhaseNode_SpawnCollider::TRIGGER_DONE, 13, PhaseNode_AttachTo::FUNC_DO, &PhaseNode_AttachTo::Do);
    pnode->regTrigger<PhaseNode_CameraXYZShake>(PhaseNode_SpawnCollider::TRIGGER_DONE, 443, PhaseNode_CameraXYZShake::FUNC_DO, &PhaseNode_CameraXYZShake::Do);
}

REGISTER_CREATE_SKILL_NODE(10111, 12) {
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
        node12->setTypeParams(0, .50f);
        node12->setTime(1.00f);
        node12->setreentry(false);
        node12->setCheckPeneSound(false);
        CALL_REGISTER_SKILL_NODE(10111, 12, node12)
    }
    if (noInit == true) {
        return node12;
    }
    auto node180 = GET_SKILL_NODE(180, PhaseNode_OffsetCalculate);
    if (node180 != nullptr) node12->setPosX(node180->getOutPosX());
    if (node180 != nullptr) node12->setPosY(node180->getOutPosY());
    if (node180 != nullptr) node12->setPosZ(node180->getOutPosZ());
    if (node180 != nullptr) node12->setRotation(node180->getOutRotation());
    return node12;
}
//--------------------------------------------------------------------------------
// AttachTo
//
REGISTER_REGISTER_SKILL_NODE(10111, 13) {
    pnode->resizeTrigger(PhaseNode_AttachTo::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_MoveNewPene>(PhaseNode_AttachTo::TRIGGER_DONE, 383, PhaseNode_MoveNewPene::FUNC_DO, &PhaseNode_MoveNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(10111, 13) {
    auto node13 = GET_SKILL_NODE(13, PhaseNode_AttachTo);
    if (node13 == nullptr) {
        node13 = new PhaseNode_AttachTo(13, phase);
        node13->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node13->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node13->setChild(0U);
        node13->setChangeRotation(true);
        node13->setreentry(false);
        CALL_REGISTER_SKILL_NODE(10111, 13, node13)
    }
    if (noInit == true) {
        return node13;
    }
    auto node12 = GET_SKILL_NODE(12, PhaseNode_SpawnCollider);
    if (node12 != nullptr) node13->setParent(node12->getColliderID());
    return node13;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(10111, 15) {
}

REGISTER_CREATE_SKILL_NODE(10111, 15) {
    auto node15 = GET_SKILL_NODE(15, PhaseNode_EndPhase);
    if (node15 == nullptr) {
        node15 = new PhaseNode_EndPhase(15, phase);
        node15->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node15->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10111, 15, node15)
    }
    if (noInit == true) {
        return node15;
    }
    return node15;
}
//--------------------------------------------------------------------------------
// SpawnCollider
//
REGISTER_REGISTER_SKILL_NODE(10111, 20) {
    pnode->resizeTrigger(PhaseNode_SpawnCollider::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_SpawnCollider::TRIGGER_DONE, 451, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
}

REGISTER_CREATE_SKILL_NODE(10111, 20) {
    auto node20 = GET_SKILL_NODE(20, PhaseNode_SpawnCollider);
    if (node20 == nullptr) {
        node20 = new PhaseNode_SpawnCollider(20, phase);
        node20->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node20->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node20->setMesh("");
        node20->setMeshScale(.00f);
        node20->setEffectID(101111);
        node20->setEffectScale(1.00f);
        node20->setType(PhaseNode_SpawnCollider::SpawnCollider_Type::Circle);
        node20->setTypeParams(0, 3.00f);
        node20->setTime(.30f);
        node20->setPosZ(.00f);
        node20->setreentry(false);
        node20->setCheckPeneSound(false);
        CALL_REGISTER_SKILL_NODE(10111, 20, node20)
    }
    if (noInit == true) {
        return node20;
    }
    auto node445 = GET_SKILL_NODE(445, PhaseNode_GetLocation);
    auto node447 = GET_SKILL_NODE(447, PhaseNode_GetInputRotation);
    if (node445 != nullptr) node20->setPosX(node445->getX());
    if (node445 != nullptr) node20->setPosY(node445->getY());
    if (node447 != nullptr) node20->setRotation(node447->getAngle());
    return node20;
}
//--------------------------------------------------------------------------------
// For
//
REGISTER_REGISTER_SKILL_NODE(10111, 154) {
    pnode->resizeTrigger(PhaseNode_For::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetUInt64sValue>(PhaseNode_For::TRIGGER_DO, 156, PhaseNode_GetUInt64sValue::FUNC_DO, &PhaseNode_GetUInt64sValue::Do);
}

REGISTER_CREATE_SKILL_NODE(10111, 154) {
    auto node154 = GET_SKILL_NODE(154, PhaseNode_For);
    if (node154 == nullptr) {
        node154 = new PhaseNode_For(154, phase);
        node154->setBegin(0);
        node154->setIncrease(1);
        CALL_REGISTER_SKILL_NODE(10111, 154, node154)
    }
    if (noInit == true) {
        return node154;
    }
    auto node155 = GET_SKILL_NODE(155, PhaseNode_UInt64sSize);
    if (node155 != nullptr) node154->setEnd(node155->getSize());
    return node154;
}
//--------------------------------------------------------------------------------
// UInt64sSize
//
REGISTER_REGISTER_SKILL_NODE(10111, 155) {
    pnode->resizeTrigger(PhaseNode_UInt64sSize::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_For>(PhaseNode_UInt64sSize::TRIGGER_DONE, 154, PhaseNode_For::FUNC_START, &PhaseNode_For::Start);
}

REGISTER_CREATE_SKILL_NODE(10111, 155) {
    auto node155 = GET_SKILL_NODE(155, PhaseNode_UInt64sSize);
    if (node155 == nullptr) {
        node155 = new PhaseNode_UInt64sSize(155, phase);
        CALL_REGISTER_SKILL_NODE(10111, 155, node155)
    }
    if (noInit == true) {
        return node155;
    }
    auto node389 = GET_SKILL_NODE(389, PhaseNode_LineCheckNewPene);
    if (node389 != nullptr) node155->setArr(node389->getOutput());
    return node155;
}
//--------------------------------------------------------------------------------
// GetUInt64sValue
//
REGISTER_REGISTER_SKILL_NODE(10111, 156) {
    pnode->resizeTrigger(PhaseNode_GetUInt64sValue::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_GetUInt64sValue::TRIGGER_DONE, 157, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(10111, 156) {
    auto node156 = GET_SKILL_NODE(156, PhaseNode_GetUInt64sValue);
    if (node156 == nullptr) {
        node156 = new PhaseNode_GetUInt64sValue(156, phase);
        CALL_REGISTER_SKILL_NODE(10111, 156, node156)
    }
    if (noInit == true) {
        return node156;
    }
    auto node389 = GET_SKILL_NODE(389, PhaseNode_LineCheckNewPene);
    auto node154 = GET_SKILL_NODE(154, PhaseNode_For);
    if (node389 != nullptr) node156->setArr(node389->getOutput());
    if (node154 != nullptr) node156->setIndex(node154->getValue());
    return node156;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(10111, 157) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnCollider>(PhaseNode_GetLocation::TRIGGER_DONE, 158, PhaseNode_SpawnCollider::FUNC_DO, &PhaseNode_SpawnCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(10111, 157) {
    auto node157 = GET_SKILL_NODE(157, PhaseNode_GetLocation);
    if (node157 == nullptr) {
        node157 = new PhaseNode_GetLocation(157, phase);
        node157->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        CALL_REGISTER_SKILL_NODE(10111, 157, node157)
    }
    if (noInit == true) {
        return node157;
    }
    auto node156 = GET_SKILL_NODE(156, PhaseNode_GetUInt64sValue);
    if (node156 != nullptr) node157->setTarget(node156->getValue());
    return node157;
}
//--------------------------------------------------------------------------------
// SpawnCollider
//
REGISTER_REGISTER_SKILL_NODE(10111, 158) {
    pnode->resizeTrigger(PhaseNode_SpawnCollider::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AttachTo>(PhaseNode_SpawnCollider::TRIGGER_DONE, 160, PhaseNode_AttachTo::FUNC_DO, &PhaseNode_AttachTo::Do);
}

REGISTER_CREATE_SKILL_NODE(10111, 158) {
    auto node158 = GET_SKILL_NODE(158, PhaseNode_SpawnCollider);
    if (node158 == nullptr) {
        node158 = new PhaseNode_SpawnCollider(158, phase);
        node158->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node158->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node158->setMesh("");
        node158->setMeshScale(.00f);
        node158->setEffectID(0);
        node158->setEffectScale(.00f);
        node158->setType(PhaseNode_SpawnCollider::SpawnCollider_Type::Circle);
        node158->setTypeParams(0, .50f);
        node158->setTime(.70f);
        node158->setPosZ(.00f);
        node158->setRotation(.00f);
        node158->setreentry(true);
        node158->setCheckPeneSound(false);
        CALL_REGISTER_SKILL_NODE(10111, 158, node158)
    }
    if (noInit == true) {
        return node158;
    }
    auto node157 = GET_SKILL_NODE(157, PhaseNode_GetLocation);
    if (node157 != nullptr) node158->setPosX(node157->getX());
    if (node157 != nullptr) node158->setPosY(node157->getY());
    return node158;
}
//--------------------------------------------------------------------------------
// AttachTo
//
REGISTER_REGISTER_SKILL_NODE(10111, 160) {
    pnode->resizeTrigger(PhaseNode_AttachTo::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_MoveNewPene>(PhaseNode_AttachTo::TRIGGER_DONE, 386, PhaseNode_MoveNewPene::FUNC_DO, &PhaseNode_MoveNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(10111, 160) {
    auto node160 = GET_SKILL_NODE(160, PhaseNode_AttachTo);
    if (node160 == nullptr) {
        node160 = new PhaseNode_AttachTo(160, phase);
        node160->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node160->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node160->setChangeRotation(false);
        node160->setreentry(true);
        CALL_REGISTER_SKILL_NODE(10111, 160, node160)
    }
    if (noInit == true) {
        return node160;
    }
    auto node158 = GET_SKILL_NODE(158, PhaseNode_SpawnCollider);
    auto node156 = GET_SKILL_NODE(156, PhaseNode_GetUInt64sValue);
    if (node158 != nullptr) node160->setParent(node158->getColliderID());
    if (node156 != nullptr) node160->setChild(node156->getValue());
    return node160;
}
//--------------------------------------------------------------------------------
// ForContinue
//
REGISTER_REGISTER_SKILL_NODE(10111, 161) {
}

REGISTER_CREATE_SKILL_NODE(10111, 161) {
    auto node161 = GET_SKILL_NODE(161, PhaseNode_ForContinue);
    if (node161 == nullptr) {
        node161 = new PhaseNode_ForContinue(161, phase);
        CALL_REGISTER_SKILL_NODE(10111, 161, node161)
    }
    if (noInit == true) {
        return node161;
    }
    auto node154 = GET_SKILL_NODE(154, PhaseNode_For);
    if (node154 != nullptr) node161->setFID(node154->getFID());
    return node161;
}
//--------------------------------------------------------------------------------
// OffsetCalculate
//
REGISTER_REGISTER_SKILL_NODE(10111, 180) {
    pnode->resizeTrigger(PhaseNode_OffsetCalculate::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnCollider>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 12, PhaseNode_SpawnCollider::FUNC_DO, &PhaseNode_SpawnCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(10111, 180) {
    auto node180 = GET_SKILL_NODE(180, PhaseNode_OffsetCalculate);
    if (node180 == nullptr) {
        node180 = new PhaseNode_OffsetCalculate(180, phase);
        node180->setPosZ(.00f);
        node180->setOffsetX(.00f);
        node180->setOffsetY(-.50f);
        node180->setOffsetZ(.00f);
        node180->setRotOffset(.00f);
        CALL_REGISTER_SKILL_NODE(10111, 180, node180)
    }
    if (noInit == true) {
        return node180;
    }
    auto node445 = GET_SKILL_NODE(445, PhaseNode_GetLocation);
    auto node447 = GET_SKILL_NODE(447, PhaseNode_GetInputRotation);
    if (node445 != nullptr) node180->setPosX(node445->getX());
    if (node445 != nullptr) node180->setPosY(node445->getY());
    if (node447 != nullptr) node180->setRotation(node447->getAngle());
    return node180;
}
//--------------------------------------------------------------------------------
// Disable
//
REGISTER_REGISTER_SKILL_NODE(10111, 199) {
    pnode->resizeTrigger(PhaseNode_Disable::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_Disable::TRIGGER_DONE, 461, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10111, 199) {
    auto node199 = GET_SKILL_NODE(199, PhaseNode_Disable);
    if (node199 == nullptr) {
        node199 = new PhaseNode_Disable(199, phase);
        node199->setTarget(0U);
        node199->setMove(true);
        node199->setSkill(true);
        node199->setShoot(true);
        node199->setTime(.90f);
        node199->setRotate(true);
        CALL_REGISTER_SKILL_NODE(10111, 199, node199)
    }
    if (noInit == true) {
        return node199;
    }
    return node199;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10111, 221) {
}

REGISTER_CREATE_SKILL_NODE(10111, 221) {
    auto node221 = GET_SKILL_NODE(221, PhaseNode_PlaySound);
    if (node221 == nullptr) {
        node221 = new PhaseNode_PlaySound(221, phase);
        node221->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node221->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node221->setSoundID("SE_Hero102_Skill_A");
        node221->setTarget(0U);
        node221->setUsePos(false);
        node221->setPosX(.00f);
        node221->setPosY(.00f);
        node221->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10111, 221, node221)
    }
    if (noInit == true) {
        return node221;
    }
    return node221;
}
//--------------------------------------------------------------------------------
// AddSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10111, 354) {
    pnode->resizeTrigger(PhaseNode_AddSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnCollider>(PhaseNode_AddSkillBuff::TRIGGER_DONE, 20, PhaseNode_SpawnCollider::FUNC_DO, &PhaseNode_SpawnCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(10111, 354) {
    auto node354 = GET_SKILL_NODE(354, PhaseNode_AddSkillBuff);
    if (node354 == nullptr) {
        node354 = new PhaseNode_AddSkillBuff(354, phase);
        node354->setConfigID(101112);
        node354->setConfigIDs({});
        node354->setTarget(0U);
        node354->setAttribute({{}});
        CALL_REGISTER_SKILL_NODE(10111, 354, node354)
    }
    if (noInit == true) {
        return node354;
    }
    return node354;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(10111, 356) {
}

REGISTER_CREATE_SKILL_NODE(10111, 356) {
    auto node356 = GET_SKILL_NODE(356, PhaseNode_AddSkillBuffs);
    if (node356 == nullptr) {
        node356 = new PhaseNode_AddSkillBuffs(356, phase);
        node356->setConfigID({101111,101113});
        CALL_REGISTER_SKILL_NODE(10111, 356, node356)
    }
    if (noInit == true) {
        return node356;
    }
    auto node389 = GET_SKILL_NODE(389, PhaseNode_LineCheckNewPene);
    auto node456 = GET_SKILL_NODE(456, PhaseNode_GetActorAttribute);
    if (node389 != nullptr) node356->setTarget(node389->getOutput());
    if (node456 != nullptr) node356->setAttribute(node456->getAttribute());
    return node356;
}
//--------------------------------------------------------------------------------
// MoveNewPene
//
REGISTER_REGISTER_SKILL_NODE(10111, 383) {
    pnode->resizeTrigger(PhaseNode_MoveNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_MoveNewPene::TRIGGER_DONE, 449, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_AddSkillBuff>(PhaseNode_MoveNewPene::TRIGGER_STARTMOVE, 354, PhaseNode_AddSkillBuff::FUNC_ADD, &PhaseNode_AddSkillBuff::Add);
}

REGISTER_CREATE_SKILL_NODE(10111, 383) {
    auto node383 = GET_SKILL_NODE(383, PhaseNode_MoveNewPene);
    if (node383 == nullptr) {
        node383 = new PhaseNode_MoveNewPene(383, phase);
        node383->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node383->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node383->setPeneType(PhaseNode_MoveNewPene::MoveNewPene_PeneType::Move);
        node383->setPeneValue(25);
        node383->setType(PhaseNode_MoveNewPene::MoveNewPene_Type::Charge);
        node383->getVars().reserve(4);
        node383->getVars().setVariable<float>(0, 12.00f);
        node383->getVars().setVariable<float>(1, 8.40f);
        node383->getVars().setVariable<float>(2, .00f);
        node383->getVars().setVariable<float>(3, 180.00f);
        node383->setreentry(false);
        node383->setStopWhenFail(false);
        node383->setCheckFaction(PhaseNode_MoveNewPene::MoveNewPene_CheckFaction::Enemy);
        CALL_REGISTER_SKILL_NODE(10111, 383, node383)
    }
    if (noInit == true) {
        return node383;
    }
    auto node12 = GET_SKILL_NODE(12, PhaseNode_SpawnCollider);
    auto node447 = GET_SKILL_NODE(447, PhaseNode_GetInputRotation);
    if (node12 != nullptr) node383->setTarget(node12->getColliderID());
    if (node447 != nullptr) node383->getVars().setVariable<float>(2, node447->getAngle());
    return node383;
}
//--------------------------------------------------------------------------------
// MoveNewPene
//
REGISTER_REGISTER_SKILL_NODE(10111, 386) {
    pnode->resizeTrigger(PhaseNode_MoveNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ForContinue>(PhaseNode_MoveNewPene::TRIGGER_STARTMOVE, 161, PhaseNode_ForContinue::FUNC_DO, &PhaseNode_ForContinue::Do);
}

REGISTER_CREATE_SKILL_NODE(10111, 386) {
    auto node386 = GET_SKILL_NODE(386, PhaseNode_MoveNewPene);
    if (node386 == nullptr) {
        node386 = new PhaseNode_MoveNewPene(386, phase);
        node386->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node386->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node386->setPeneType(PhaseNode_MoveNewPene::MoveNewPene_PeneType::Move);
        node386->setPeneValue(5);
        node386->setType(PhaseNode_MoveNewPene::MoveNewPene_Type::Charge);
        node386->getVars().reserve(4);
        node386->getVars().setVariable<float>(0, 8.00f);
        node386->getVars().setVariable<float>(1, 5.60f);
        node386->getVars().setVariable<float>(2, .00f);
        node386->getVars().setVariable<float>(3, .00f);
        node386->setreentry(true);
        node386->setStopWhenFail(true);
        node386->setCheckFaction(PhaseNode_MoveNewPene::MoveNewPene_CheckFaction::Enemy);
        CALL_REGISTER_SKILL_NODE(10111, 386, node386)
    }
    if (noInit == true) {
        return node386;
    }
    auto node158 = GET_SKILL_NODE(158, PhaseNode_SpawnCollider);
    auto node447 = GET_SKILL_NODE(447, PhaseNode_GetInputRotation);
    if (node158 != nullptr) node386->setTarget(node158->getColliderID());
    if (node447 != nullptr) node386->getVars().setVariable<float>(2, node447->getAngle());
    return node386;
}
//--------------------------------------------------------------------------------
// LineCheckNewPene
//
REGISTER_REGISTER_SKILL_NODE(10111, 389) {
    pnode->resizeTrigger(PhaseNode_LineCheckNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_LineCheckNewPene::TRIGGER_DONE, 356, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
    pnode->regTrigger<PhaseNode_UInt64sSize>(PhaseNode_LineCheckNewPene::TRIGGER_DONE, 155, PhaseNode_UInt64sSize::FUNC_DO, &PhaseNode_UInt64sSize::Do);
}

REGISTER_CREATE_SKILL_NODE(10111, 389) {
    auto node389 = GET_SKILL_NODE(389, PhaseNode_LineCheckNewPene);
    if (node389 == nullptr) {
        node389 = new PhaseNode_LineCheckNewPene(389, phase);
        node389->setPeneProjectile(15);
        CALL_REGISTER_SKILL_NODE(10111, 389, node389)
    }
    if (noInit == true) {
        return node389;
    }
    auto node452 = GET_SKILL_NODE(452, PhaseNode_ActorFilterNewPene);
    auto node445 = GET_SKILL_NODE(445, PhaseNode_GetLocation);
    if (node452 != nullptr) node389->setTargets(node452->getOutput());
    if (node445 != nullptr) node389->setFromX(node445->getX());
    if (node445 != nullptr) node389->setFromY(node445->getY());
    return node389;
}
//--------------------------------------------------------------------------------
// SetInt
//
REGISTER_REGISTER_SKILL_NODE(10111, 436) {
}

REGISTER_CREATE_SKILL_NODE(10111, 436) {
    auto node436 = GET_SKILL_NODE(436, PhaseNode_SetInt);
    if (node436 == nullptr) {
        node436 = new PhaseNode_SetInt(436, phase);
        node436->setName("a101112");
        node436->setValue(2);
        CALL_REGISTER_SKILL_NODE(10111, 436, node436)
    }
    if (noInit == true) {
        return node436;
    }
    return node436;
}
//--------------------------------------------------------------------------------
// CameraXYZShake
//
REGISTER_REGISTER_SKILL_NODE(10111, 443) {
}

REGISTER_CREATE_SKILL_NODE(10111, 443) {
    auto node443 = GET_SKILL_NODE(443, PhaseNode_CameraXYZShake);
    if (node443 == nullptr) {
        node443 = new PhaseNode_CameraXYZShake(443, phase);
        node443->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node443->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node443->setShakeStyle(0);
        node443->setTarget(0U);
        node443->setX(.30f);
        node443->setY(.20f);
        node443->setZ(.30f);
        node443->setDuration(.10f);
        node443->setTimes(3);
        CALL_REGISTER_SKILL_NODE(10111, 443, node443)
    }
    if (noInit == true) {
        return node443;
    }
    return node443;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(10111, 445) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetInputRotation>(PhaseNode_GetLocation::TRIGGER_DONE, 447, PhaseNode_GetInputRotation::FUNC_DO, &PhaseNode_GetInputRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(10111, 445) {
    auto node445 = GET_SKILL_NODE(445, PhaseNode_GetLocation);
    if (node445 == nullptr) {
        node445 = new PhaseNode_GetLocation(445, phase);
        node445->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node445->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(10111, 445, node445)
    }
    if (noInit == true) {
        return node445;
    }
    return node445;
}
//--------------------------------------------------------------------------------
// GetInputRotation
//
REGISTER_REGISTER_SKILL_NODE(10111, 447) {
    pnode->resizeTrigger(PhaseNode_GetInputRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Disable>(PhaseNode_GetInputRotation::TRIGGER_DONE, 199, PhaseNode_Disable::FUNC_DO, &PhaseNode_Disable::Do);
}

REGISTER_CREATE_SKILL_NODE(10111, 447) {
    auto node447 = GET_SKILL_NODE(447, PhaseNode_GetInputRotation);
    if (node447 == nullptr) {
        node447 = new PhaseNode_GetInputRotation(447, phase);
        node447->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        CALL_REGISTER_SKILL_NODE(10111, 447, node447)
    }
    if (noInit == true) {
        return node447;
    }
    return node447;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10111, 449) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_Delay::TRIGGER_DONE, 15, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(10111, 449) {
    auto node449 = GET_SKILL_NODE(449, PhaseNode_Delay);
    if (node449 == nullptr) {
        node449 = new PhaseNode_Delay(449, phase);
        node449->setTime(.20f);
        CALL_REGISTER_SKILL_NODE(10111, 449, node449)
    }
    if (noInit == true) {
        return node449;
    }
    return node449;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(10111, 450) {
}

REGISTER_CREATE_SKILL_NODE(10111, 450) {
    auto node450 = GET_SKILL_NODE(450, PhaseNode_TriggerCheck);
    if (node450 == nullptr) {
        node450 = new PhaseNode_TriggerCheck(450, phase);
        auto node9 = GET_SKILL_NODE(9, PhaseNode_TriggerUpdate);
        if (node9 != nullptr) node9->addTriggerCheck(node450);
        
        CALL_REGISTER_SKILL_NODE(10111, 450, node450)
    }
    if (noInit == true) {
        return node450;
    }
    auto node451 = GET_SKILL_NODE(451, PhaseNode_CreateTriggerNewPene);
    if (node451 != nullptr) node450->setTrigger(0, node451->getTriggerID());
    return node450;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(10111, 451) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 450, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 452, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(10111, 451) {
    auto node451 = GET_SKILL_NODE(451, PhaseNode_CreateTriggerNewPene);
    if (node451 == nullptr) {
        node451 = new PhaseNode_CreateTriggerNewPene(451, phase);
        node451->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::In);
        node451->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node451->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Enemy);
        node451->setOnHero(true);
        node451->setOnMinion(true);
        node451->setOnDestruct(true);
        node451->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(10111, 451, node451)
    }
    if (noInit == true) {
        return node451;
    }
    auto node20 = GET_SKILL_NODE(20, PhaseNode_SpawnCollider);
    if (node20 != nullptr) node451->setColliderID(node20->getColliderID());
    return node451;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(10111, 452) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_LineCheckNewPene>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 389, PhaseNode_LineCheckNewPene::FUNC_DO, &PhaseNode_LineCheckNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(10111, 452) {
    auto node452 = GET_SKILL_NODE(452, PhaseNode_ActorFilterNewPene);
    if (node452 == nullptr) {
        node452 = new PhaseNode_ActorFilterNewPene(452, phase);
        node452->setHero(true);
        node452->setMinion(true);
        node452->setDestruct(true);
        node452->setShield(false);
        node452->setTotalCount(0);
        node452->setPerCount(1);
        CALL_REGISTER_SKILL_NODE(10111, 452, node452)
    }
    if (noInit == true) {
        return node452;
    }
    auto node451 = GET_SKILL_NODE(451, PhaseNode_CreateTriggerNewPene);
    if (node451 != nullptr) node452->setInput(node451->getOther());
    return node452;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(10111, 453) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_ResetCD::TRIGGER_DONE, 454, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10111, 453) {
    auto node453 = GET_SKILL_NODE(453, PhaseNode_ResetCD);
    if (node453 == nullptr) {
        node453 = new PhaseNode_ResetCD(453, phase);
        node453->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node453->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node453->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(10111, 453, node453)
    }
    if (noInit == true) {
        return node453;
    }
    return node453;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10111, 454) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_PlayAnimation::TRIGGER_DONE, 456, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(10111, 454) {
    auto node454 = GET_SKILL_NODE(454, PhaseNode_PlayAnimation);
    if (node454 == nullptr) {
        node454 = new PhaseNode_PlayAnimation(454, phase);
        node454->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node454->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node454->setTarget(0U);
        node454->setAnimation("Skill1S1");
        node454->setParameter("");
        node454->setValue(false);
        CALL_REGISTER_SKILL_NODE(10111, 454, node454)
    }
    if (noInit == true) {
        return node454;
    }
    return node454;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10111, 455) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_PlaySound::TRIGGER_DONE, 445, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_PlaySound::TRIGGER_DONE, 221, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10111, 455) {
    auto node455 = GET_SKILL_NODE(455, PhaseNode_PlaySound);
    if (node455 == nullptr) {
        node455 = new PhaseNode_PlaySound(455, phase);
        node455->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node455->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node455->setSoundID("VO_Hero102_Skill_A");
        node455->setTarget(0U);
        node455->setUsePos(false);
        node455->setPosX(.00f);
        node455->setPosY(.00f);
        node455->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10111, 455, node455)
    }
    if (noInit == true) {
        return node455;
    }
    return node455;
}
//--------------------------------------------------------------------------------
// GetActorAttribute
//
REGISTER_REGISTER_SKILL_NODE(10111, 456) {
    pnode->resizeTrigger(PhaseNode_GetActorAttribute::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 455, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10111, 456) {
    auto node456 = GET_SKILL_NODE(456, PhaseNode_GetActorAttribute);
    if (node456 == nullptr) {
        node456 = new PhaseNode_GetActorAttribute(456, phase);
        node456->setTarget(0U);
        node456->setType({});
        CALL_REGISTER_SKILL_NODE(10111, 456, node456)
    }
    if (noInit == true) {
        return node456;
    }
    return node456;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10111, 458) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_IsInterruptType>(PhaseNode_Detect::TRIGGER_ON, 464, PhaseNode_IsInterruptType::FUNC_DO, &PhaseNode_IsInterruptType::Do);
}

REGISTER_CREATE_SKILL_NODE(10111, 458) {
    auto node458 = GET_SKILL_NODE(458, PhaseNode_Detect);
    if (node458 == nullptr) {
        node458 = new PhaseNode_Detect(458, phase);
        node458->setSelf(0U);
        node458->setEvent("daduan_001");
        node458->setType(PhaseNode_Detect::Detect_Type::Interrupt_Skill);
        node458->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10111, 458, node458)
    }
    if (noInit == true) {
        return node458;
    }
    return node458;
}
//--------------------------------------------------------------------------------
// SwitchToInt
//
REGISTER_REGISTER_SKILL_NODE(10111, 459) {
    pnode->resizeTrigger(4);
    pnode->regTrigger<PhaseNode_EndPhase>(1, 15, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(10111, 459) {
    auto node459 = GET_SKILL_NODE(459, PhaseNode_SwitchToInt);
    if (node459 == nullptr) {
        node459 = new PhaseNode_SwitchToInt(459, phase);
        CALL_REGISTER_SKILL_NODE(10111, 459, node459)
    }
    if (noInit == true) {
        return node459;
    }
    auto variables = node459->getVariables();
    if (variables != nullptr) {
        node459->setSelection(variables->getVariable<int32_t>(Variable_10111_a101112));
    }
    return node459;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10111, 461) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_RaiseEvent::TRIGGER_DONE, 470, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10111, 461) {
    auto node461 = GET_SKILL_NODE(461, PhaseNode_RaiseEvent);
    if (node461 == nullptr) {
        node461 = new PhaseNode_RaiseEvent(461, phase);
        node461->setEvent("daduan_001");
        node461->setTarget(0U);
        node461->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node461->setTypeParams(0, 0);
        node461->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10111, 461, node461)
    }
    if (noInit == true) {
        return node461;
    }
    return node461;
}
//--------------------------------------------------------------------------------
// StartPreInput
//
REGISTER_REGISTER_SKILL_NODE(10111, 462) {
    pnode->resizeTrigger(PhaseNode_StartPreInput::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_StartPreInput::TRIGGER_DONE, 466, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_StartPreInput::TRIGGER_DONE, 8, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10111, 462) {
    auto node462 = GET_SKILL_NODE(462, PhaseNode_StartPreInput);
    if (node462 == nullptr) {
        node462 = new PhaseNode_StartPreInput(462, phase);
        node462->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node462->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node462->setDelayTime(.00f);
        CALL_REGISTER_SKILL_NODE(10111, 462, node462)
    }
    if (noInit == true) {
        return node462;
    }
    return node462;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(10111, 463) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_If::TRIGGER_TRUE, 465, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10111, 463) {
    auto node463 = GET_SKILL_NODE(463, PhaseNode_If);
    if (node463 == nullptr) {
        node463 = new PhaseNode_If(463, phase);
        CALL_REGISTER_SKILL_NODE(10111, 463, node463)
    }
    if (noInit == true) {
        return node463;
    }
    auto variables = node463->getVariables();
    if (variables != nullptr) {
        node463->setCondition(variables->getVariable<bool>(Variable_10111_InterruptAnimat));
    }
    return node463;
}
//--------------------------------------------------------------------------------
// IsInterruptType
//
REGISTER_REGISTER_SKILL_NODE(10111, 464) {
    pnode->resizeTrigger(PhaseNode_IsInterruptType::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SwitchToInt>(PhaseNode_IsInterruptType::TRIGGER_BUFF, 459, PhaseNode_SwitchToInt::FUNC_SWITCH, &PhaseNode_SwitchToInt::Switch);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_POSCHANGE, 463, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTAIM, 463, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTFIRE, 463, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTRELOAD, 463, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_USESKILL, 463, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(10111, 464) {
    auto node464 = GET_SKILL_NODE(464, PhaseNode_IsInterruptType);
    if (node464 == nullptr) {
        node464 = new PhaseNode_IsInterruptType(464, phase);
        node464->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node464->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10111, 464, node464)
    }
    if (noInit == true) {
        return node464;
    }
    auto node458 = GET_SKILL_NODE(458, PhaseNode_Detect);
    if (node458 != nullptr) node464->setType(node458->getVars().getVariable<int32_t>(2));
    return node464;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10111, 465) {
}

REGISTER_CREATE_SKILL_NODE(10111, 465) {
    auto node465 = GET_SKILL_NODE(465, PhaseNode_PlayAnimation);
    if (node465 == nullptr) {
        node465 = new PhaseNode_PlayAnimation(465, phase);
        node465->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node465->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node465->setTarget(0U);
        node465->setAnimation("Idle");
        node465->setParameter("");
        node465->setValue(false);
        CALL_REGISTER_SKILL_NODE(10111, 465, node465)
    }
    if (noInit == true) {
        return node465;
    }
    return node465;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10111, 466) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_Delay::TRIGGER_DONE, 469, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(10111, 466) {
    auto node466 = GET_SKILL_NODE(466, PhaseNode_Delay);
    if (node466 == nullptr) {
        node466 = new PhaseNode_Delay(466, phase);
        node466->setTime(.20f);
        CALL_REGISTER_SKILL_NODE(10111, 466, node466)
    }
    if (noInit == true) {
        return node466;
    }
    return node466;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(10111, 469) {
}

REGISTER_CREATE_SKILL_NODE(10111, 469) {
    auto node469 = GET_SKILL_NODE(469, PhaseNode_SetBool);
    if (node469 == nullptr) {
        node469 = new PhaseNode_SetBool(469, phase);
        node469->setName("InterruptAnimat");
        node469->setValue(true);
        CALL_REGISTER_SKILL_NODE(10111, 469, node469)
    }
    if (noInit == true) {
        return node469;
    }
    return node469;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10111, 470) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StartPreInput>(PhaseNode_RaiseEvent::TRIGGER_DONE, 462, PhaseNode_StartPreInput::FUNC_DO, &PhaseNode_StartPreInput::Do);
}

REGISTER_CREATE_SKILL_NODE(10111, 470) {
    auto node470 = GET_SKILL_NODE(470, PhaseNode_RaiseEvent);
    if (node470 == nullptr) {
        node470 = new PhaseNode_RaiseEvent(470, phase);
        node470->setEvent("Dead_001");
        node470->setTarget(0U);
        node470->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node470->setTypeParams(0, 0);
        node470->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10111, 470, node470)
    }
    if (noInit == true) {
        return node470;
    }
    return node470;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10111, 471) {
}

REGISTER_CREATE_SKILL_NODE(10111, 471) {
    auto node471 = GET_SKILL_NODE(471, PhaseNode_Detect);
    if (node471 == nullptr) {
        node471 = new PhaseNode_Detect(471, phase);
        node471->setSelf(0U);
        node471->setEvent("Dead_001");
        node471->setType(PhaseNode_Detect::Detect_Type::Actor_Dead);
        node471->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10111, 471, node471)
    }
    if (noInit == true) {
        return node471;
    }
    return node471;
}

//--------------------------------------------------------------------------------
// SkillCreator_10111
//
class SkillCreator_10111 : public SkillCreator {
public:
    SkillCreator_10111() {}
    virtual ~SkillCreator_10111() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_10111

//--------------------------------------------------------------------------------
// SkillPhase_10111
//
class SkillPhase_10111 : public SkillPhase {
public:
    SkillPhase_10111(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_10111() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(10111, 1) // StartPhase
        CASE_CREATE_SKILL_NODE(10111, 8) // Delay
        CASE_CREATE_SKILL_NODE(10111, 9) // TriggerUpdate
        CASE_CREATE_SKILL_NODE(10111, 12) // SpawnCollider
        CASE_CREATE_SKILL_NODE(10111, 13) // AttachTo
        CASE_CREATE_SKILL_NODE(10111, 15) // EndPhase
        CASE_CREATE_SKILL_NODE(10111, 20) // SpawnCollider
        CASE_CREATE_SKILL_NODE(10111, 154) // For
        CASE_CREATE_SKILL_NODE(10111, 155) // UInt64sSize
        CASE_CREATE_SKILL_NODE(10111, 156) // GetUInt64sValue
        CASE_CREATE_SKILL_NODE(10111, 157) // GetLocation
        CASE_CREATE_SKILL_NODE(10111, 158) // SpawnCollider
        CASE_CREATE_SKILL_NODE(10111, 160) // AttachTo
        CASE_CREATE_SKILL_NODE(10111, 161) // ForContinue
        CASE_CREATE_SKILL_NODE(10111, 180) // OffsetCalculate
        CASE_CREATE_SKILL_NODE(10111, 199) // Disable
        CASE_CREATE_SKILL_NODE(10111, 221) // PlaySound
        CASE_CREATE_SKILL_NODE(10111, 354) // AddSkillBuff
        CASE_CREATE_SKILL_NODE(10111, 356) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(10111, 383) // MoveNewPene
        CASE_CREATE_SKILL_NODE(10111, 386) // MoveNewPene
        CASE_CREATE_SKILL_NODE(10111, 389) // LineCheckNewPene
        CASE_CREATE_SKILL_NODE(10111, 436) // SetInt
        CASE_CREATE_SKILL_NODE(10111, 443) // CameraXYZShake
        CASE_CREATE_SKILL_NODE(10111, 445) // GetLocation
        CASE_CREATE_SKILL_NODE(10111, 447) // GetInputRotation
        CASE_CREATE_SKILL_NODE(10111, 449) // Delay
        CASE_CREATE_SKILL_NODE(10111, 450) // TriggerCheck
        CASE_CREATE_SKILL_NODE(10111, 451) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(10111, 452) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(10111, 453) // ResetCD
        CASE_CREATE_SKILL_NODE(10111, 454) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10111, 455) // PlaySound
        CASE_CREATE_SKILL_NODE(10111, 456) // GetActorAttribute
        CASE_CREATE_SKILL_NODE(10111, 458) // Detect
        CASE_CREATE_SKILL_NODE(10111, 459) // SwitchToInt
        CASE_CREATE_SKILL_NODE(10111, 461) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10111, 462) // StartPreInput
        CASE_CREATE_SKILL_NODE(10111, 463) // If
        CASE_CREATE_SKILL_NODE(10111, 464) // IsInterruptType
        CASE_CREATE_SKILL_NODE(10111, 465) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10111, 466) // Delay
        CASE_CREATE_SKILL_NODE(10111, 469) // SetBool
        CASE_CREATE_SKILL_NODE(10111, 470) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10111, 471) // Detect
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_10111

SkillLogic* SkillCreator_10111::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //设置变量
    Variable_10111_a101112 = logic->getVariables().setVariable<int32_t>("a101112", 1);
    Variable_10111_InterruptAnimat = logic->getVariables().setVariable<bool>("InterruptAnimat");
    //创建阶段phase
    auto phase = new SkillPhase_10111(1, logic, 3);
    //设置phase执行器
    phase->setRunPhaseNode(1, 1);
    phase->setRunPhaseNode(2, 9);
    phase->setDetectPhaseNode(3, 458);
    phase->setDetectPhaseNode(3, 471);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_10111::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
