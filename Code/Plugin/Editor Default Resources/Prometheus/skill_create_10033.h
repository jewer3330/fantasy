#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

#include "skill_psnode_addskillbuff.h"
#include "skill_psnode_addskillbuffs.h"
#include "skill_psnode_areacollisionnewpene.h"
#include "skill_psnode_attachto.h"
#include "skill_psnode_cameraoffset.h"
#include "skill_psnode_cameraxyzshake.h"
#include "skill_psnode_comparefloat.h"
#include "skill_psnode_delay.h"
#include "skill_psnode_destroycollider.h"
#include "skill_psnode_detect.h"
#include "skill_psnode_disable.h"
#include "skill_psnode_distance.h"
#include "skill_psnode_endphase.h"
#include "skill_psnode_floatoperation.h"
#include "skill_psnode_getactorattribute.h"
#include "skill_psnode_getinputlocation.h"
#include "skill_psnode_getlinerotation.h"
#include "skill_psnode_getlocation.h"
#include "skill_psnode_if.h"
#include "skill_psnode_isinterrupttype.h"
#include "skill_psnode_linechecknewpene.h"
#include "skill_psnode_movenewpene.h"
#include "skill_psnode_playanimation.h"
#include "skill_psnode_playeffect.h"
#include "skill_psnode_playsound.h"
#include "skill_psnode_raiseevent.h"
#include "skill_psnode_resetcd.h"
#include "skill_psnode_setbool.h"
#include "skill_psnode_spawncollider.h"
#include "skill_psnode_startphase.h"
#include "skill_psnode_startpreinput.h"
#include "skill_psnode_stopeffect.h"
#include "skill_psnode_switchtoint.h"

namespace pvp {

//变量声明
uint64_t Variable_10033_a100339 = 0;
uint64_t Variable_10033_InterruptAnimat = 0;
//--------------------------------------------------------------------------------
// StartPhase
//
REGISTER_REGISTER_SKILL_NODE(10033, 2) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_StartPhase::TRIGGER_START, 434, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(10033, 2) {
    auto node2 = GET_SKILL_NODE(2, PhaseNode_StartPhase);
    if (node2 == nullptr) {
        node2 = new PhaseNode_StartPhase(2, phase);
        CALL_REGISTER_SKILL_NODE(10033, 2, node2)
    }
    if (noInit == true) {
        return node2;
    }
    return node2;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10033, 288) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuff>(PhaseNode_Delay::TRIGGER_DONE, 423, PhaseNode_AddSkillBuff::FUNC_ADD, &PhaseNode_AddSkillBuff::Add);
}

REGISTER_CREATE_SKILL_NODE(10033, 288) {
    auto node288 = GET_SKILL_NODE(288, PhaseNode_Delay);
    if (node288 == nullptr) {
        node288 = new PhaseNode_Delay(288, phase);
        node288->setTime(.50f);
        CALL_REGISTER_SKILL_NODE(10033, 288, node288)
    }
    if (noInit == true) {
        return node288;
    }
    return node288;
}
//--------------------------------------------------------------------------------
// MoveNewPene
//
REGISTER_REGISTER_SKILL_NODE(10033, 304) {
    pnode->resizeTrigger(PhaseNode_MoveNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_MoveNewPene::TRIGGER_BLOCKBYWALL, 342, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_MoveNewPene::TRIGGER_DONE, 342, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(10033, 304) {
    auto node304 = GET_SKILL_NODE(304, PhaseNode_MoveNewPene);
    if (node304 == nullptr) {
        node304 = new PhaseNode_MoveNewPene(304, phase);
        node304->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node304->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node304->setPeneType(PhaseNode_MoveNewPene::MoveNewPene_PeneType::Move);
        node304->setPeneValue(25);
        node304->setType(PhaseNode_MoveNewPene::MoveNewPene_Type::Charge);
        node304->getVars().reserve(4);
        node304->getVars().setVariable<float>(0, .00f);
        node304->getVars().setVariable<float>(1, .00f);
        node304->getVars().setVariable<float>(2, .00f);
        node304->getVars().setVariable<float>(3, .00f);
        node304->setreentry(false);
        node304->setStopWhenFail(true);
        node304->setCheckFaction(PhaseNode_MoveNewPene::MoveNewPene_CheckFaction::Enemy);
        CALL_REGISTER_SKILL_NODE(10033, 304, node304)
    }
    if (noInit == true) {
        return node304;
    }
    auto node318 = GET_SKILL_NODE(318, PhaseNode_SpawnCollider);
    auto node350 = GET_SKILL_NODE(350, PhaseNode_FloatOperation);
    auto node335 = GET_SKILL_NODE(335, PhaseNode_Distance);
    auto node337 = GET_SKILL_NODE(337, PhaseNode_GetLineRotation);
    if (node318 != nullptr) node304->setTarget(node318->getColliderID());
    if (node350 != nullptr) node304->getVars().setVariable<float>(0, node350->getFinal());
    if (node335 != nullptr) node304->getVars().setVariable<float>(1, node335->getResult());
    if (node337 != nullptr) node304->getVars().setVariable<float>(2, node337->getRotation());
    return node304;
}
//--------------------------------------------------------------------------------
// Disable
//
REGISTER_REGISTER_SKILL_NODE(10033, 310) {
    pnode->resizeTrigger(PhaseNode_Disable::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_Disable::TRIGGER_DONE, 417, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(10033, 310) {
    auto node310 = GET_SKILL_NODE(310, PhaseNode_Disable);
    if (node310 == nullptr) {
        node310 = new PhaseNode_Disable(310, phase);
        node310->setTarget(0U);
        node310->setMove(true);
        node310->setSkill(true);
        node310->setShoot(true);
        node310->setTime(1.60f);
        node310->setRotate(true);
        CALL_REGISTER_SKILL_NODE(10033, 310, node310)
    }
    if (noInit == true) {
        return node310;
    }
    return node310;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(10033, 316) {
}

REGISTER_CREATE_SKILL_NODE(10033, 316) {
    auto node316 = GET_SKILL_NODE(316, PhaseNode_EndPhase);
    if (node316 == nullptr) {
        node316 = new PhaseNode_EndPhase(316, phase);
        node316->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node316->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10033, 316, node316)
    }
    if (noInit == true) {
        return node316;
    }
    return node316;
}
//--------------------------------------------------------------------------------
// SpawnCollider
//
REGISTER_REGISTER_SKILL_NODE(10033, 318) {
    pnode->resizeTrigger(PhaseNode_SpawnCollider::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AttachTo>(PhaseNode_SpawnCollider::TRIGGER_DONE, 332, PhaseNode_AttachTo::FUNC_DO, &PhaseNode_AttachTo::Do);
}

REGISTER_CREATE_SKILL_NODE(10033, 318) {
    auto node318 = GET_SKILL_NODE(318, PhaseNode_SpawnCollider);
    if (node318 == nullptr) {
        node318 = new PhaseNode_SpawnCollider(318, phase);
        node318->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node318->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node318->setMesh("");
        node318->setMeshScale(.00f);
        node318->setEffectID(0);
        node318->setEffectScale(.00f);
        node318->setType(PhaseNode_SpawnCollider::SpawnCollider_Type::Circle);
        node318->setTypeParams(0, .00f);
        node318->setTime(.00f);
        node318->setPosZ(.00f);
        node318->setreentry(false);
        node318->setCheckPeneSound(false);
        CALL_REGISTER_SKILL_NODE(10033, 318, node318)
    }
    if (noInit == true) {
        return node318;
    }
    auto node417 = GET_SKILL_NODE(417, PhaseNode_GetLocation);
    auto node337 = GET_SKILL_NODE(337, PhaseNode_GetLineRotation);
    if (node417 != nullptr) node318->setPosX(node417->getX());
    if (node417 != nullptr) node318->setPosY(node417->getY());
    if (node337 != nullptr) node318->setRotation(node337->getRotation());
    return node318;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(10033, 327) {
}

REGISTER_CREATE_SKILL_NODE(10033, 327) {
    auto node327 = GET_SKILL_NODE(327, PhaseNode_AddSkillBuffs);
    if (node327 == nullptr) {
        node327 = new PhaseNode_AddSkillBuffs(327, phase);
        node327->setConfigID({100332,100334});
        CALL_REGISTER_SKILL_NODE(10033, 327, node327)
    }
    if (noInit == true) {
        return node327;
    }
    auto node427 = GET_SKILL_NODE(427, PhaseNode_LineCheckNewPene);
    auto node437 = GET_SKILL_NODE(437, PhaseNode_GetActorAttribute);
    if (node427 != nullptr) node327->setTarget(node427->getOutput());
    if (node437 != nullptr) node327->setAttribute(node437->getAttribute());
    return node327;
}
//--------------------------------------------------------------------------------
// AttachTo
//
REGISTER_REGISTER_SKILL_NODE(10033, 332) {
    pnode->resizeTrigger(PhaseNode_AttachTo::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_MoveNewPene>(PhaseNode_AttachTo::TRIGGER_DONE, 304, PhaseNode_MoveNewPene::FUNC_DO, &PhaseNode_MoveNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(10033, 332) {
    auto node332 = GET_SKILL_NODE(332, PhaseNode_AttachTo);
    if (node332 == nullptr) {
        node332 = new PhaseNode_AttachTo(332, phase);
        node332->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node332->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node332->setChild(0U);
        node332->setChangeRotation(true);
        node332->setreentry(false);
        CALL_REGISTER_SKILL_NODE(10033, 332, node332)
    }
    if (noInit == true) {
        return node332;
    }
    auto node318 = GET_SKILL_NODE(318, PhaseNode_SpawnCollider);
    if (node318 != nullptr) node332->setParent(node318->getColliderID());
    return node332;
}
//--------------------------------------------------------------------------------
// Distance
//
REGISTER_REGISTER_SKILL_NODE(10033, 335) {
    pnode->resizeTrigger(PhaseNode_Distance::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLineRotation>(PhaseNode_Distance::TRIGGER_DONE, 337, PhaseNode_GetLineRotation::FUNC_DO, &PhaseNode_GetLineRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(10033, 335) {
    auto node335 = GET_SKILL_NODE(335, PhaseNode_Distance);
    if (node335 == nullptr) {
        node335 = new PhaseNode_Distance(335, phase);
        CALL_REGISTER_SKILL_NODE(10033, 335, node335)
    }
    if (noInit == true) {
        return node335;
    }
    auto node417 = GET_SKILL_NODE(417, PhaseNode_GetLocation);
    auto node419 = GET_SKILL_NODE(419, PhaseNode_GetInputLocation);
    if (node417 != nullptr) node335->setAX(node417->getX());
    if (node417 != nullptr) node335->setAY(node417->getY());
    if (node419 != nullptr) node335->setBX(node419->getX());
    if (node419 != nullptr) node335->setBY(node419->getY());
    return node335;
}
//--------------------------------------------------------------------------------
// GetLineRotation
//
REGISTER_REGISTER_SKILL_NODE(10033, 337) {
    pnode->resizeTrigger(PhaseNode_GetLineRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_FloatOperation>(PhaseNode_GetLineRotation::TRIGGER_DONE, 350, PhaseNode_FloatOperation::FUNC_OPERATION, &PhaseNode_FloatOperation::Operation);
}

REGISTER_CREATE_SKILL_NODE(10033, 337) {
    auto node337 = GET_SKILL_NODE(337, PhaseNode_GetLineRotation);
    if (node337 == nullptr) {
        node337 = new PhaseNode_GetLineRotation(337, phase);
        CALL_REGISTER_SKILL_NODE(10033, 337, node337)
    }
    if (noInit == true) {
        return node337;
    }
    auto node417 = GET_SKILL_NODE(417, PhaseNode_GetLocation);
    auto node419 = GET_SKILL_NODE(419, PhaseNode_GetInputLocation);
    if (node417 != nullptr) node337->setStartX(node417->getX());
    if (node417 != nullptr) node337->setStartY(node417->getY());
    if (node419 != nullptr) node337->setEndX(node419->getX());
    if (node419 != nullptr) node337->setEndY(node419->getY());
    return node337;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(10033, 342) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AreaCollisionNewPene>(PhaseNode_GetLocation::TRIGGER_DONE, 410, PhaseNode_AreaCollisionNewPene::FUNC_DO, &PhaseNode_AreaCollisionNewPene::Do);
    pnode->regTrigger<PhaseNode_AreaCollisionNewPene>(PhaseNode_GetLocation::TRIGGER_DONE, 411, PhaseNode_AreaCollisionNewPene::FUNC_DO, &PhaseNode_AreaCollisionNewPene::Do);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_GetLocation::TRIGGER_DONE, 391, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_DestroyCollider>(PhaseNode_GetLocation::TRIGGER_DONE, 431, PhaseNode_DestroyCollider::FUNC_DO, &PhaseNode_DestroyCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(10033, 342) {
    auto node342 = GET_SKILL_NODE(342, PhaseNode_GetLocation);
    if (node342 == nullptr) {
        node342 = new PhaseNode_GetLocation(342, phase);
        node342->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        CALL_REGISTER_SKILL_NODE(10033, 342, node342)
    }
    if (noInit == true) {
        return node342;
    }
    auto node318 = GET_SKILL_NODE(318, PhaseNode_SpawnCollider);
    if (node318 != nullptr) node342->setTarget(node318->getColliderID());
    return node342;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10033, 346) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_Delay::TRIGGER_DONE, 316, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(10033, 346) {
    auto node346 = GET_SKILL_NODE(346, PhaseNode_Delay);
    if (node346 == nullptr) {
        node346 = new PhaseNode_Delay(346, phase);
        node346->setTime(1.00f);
        CALL_REGISTER_SKILL_NODE(10033, 346, node346)
    }
    if (noInit == true) {
        return node346;
    }
    return node346;
}
//--------------------------------------------------------------------------------
// FloatOperation
//
REGISTER_REGISTER_SKILL_NODE(10033, 350) {
    pnode->resizeTrigger(PhaseNode_FloatOperation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_FloatOperation::TRIGGER_DONE, 359, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(10033, 350) {
    auto node350 = GET_SKILL_NODE(350, PhaseNode_FloatOperation);
    if (node350 == nullptr) {
        node350 = new PhaseNode_FloatOperation(350, phase);
        node350->setValue(5.00f);
        node350->setMethod(PhaseNode_FloatOperation::FloatOperation_Method::Multi);
        CALL_REGISTER_SKILL_NODE(10033, 350, node350)
    }
    if (noInit == true) {
        return node350;
    }
    auto node335 = GET_SKILL_NODE(335, PhaseNode_Distance);
    if (node335 != nullptr) node350->setBase(node335->getResult());
    return node350;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(10033, 359) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 342, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
    pnode->regTrigger<PhaseNode_SpawnCollider>(PhaseNode_CompareFloat::TRIGGER_GREATER, 318, PhaseNode_SpawnCollider::FUNC_DO, &PhaseNode_SpawnCollider::Do);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_CompareFloat::TRIGGER_LESS, 342, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(10033, 359) {
    auto node359 = GET_SKILL_NODE(359, PhaseNode_CompareFloat);
    if (node359 == nullptr) {
        node359 = new PhaseNode_CompareFloat(359, phase);
        node359->setB(.00f);
        CALL_REGISTER_SKILL_NODE(10033, 359, node359)
    }
    if (noInit == true) {
        return node359;
    }
    auto node335 = GET_SKILL_NODE(335, PhaseNode_Distance);
    if (node335 != nullptr) node359->setA(node335->getResult());
    return node359;
}
//--------------------------------------------------------------------------------
// AddSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10033, 367) {
    pnode->resizeTrigger(PhaseNode_AddSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Disable>(PhaseNode_AddSkillBuff::TRIGGER_DONE, 310, PhaseNode_Disable::FUNC_DO, &PhaseNode_Disable::Do);
}

REGISTER_CREATE_SKILL_NODE(10033, 367) {
    auto node367 = GET_SKILL_NODE(367, PhaseNode_AddSkillBuff);
    if (node367 == nullptr) {
        node367 = new PhaseNode_AddSkillBuff(367, phase);
        node367->setConfigID(100333);
        node367->setConfigIDs({});
        node367->setTarget(0U);
        node367->setAttribute({{}});
        CALL_REGISTER_SKILL_NODE(10033, 367, node367)
    }
    if (noInit == true) {
        return node367;
    }
    return node367;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(10033, 369) {
}

REGISTER_CREATE_SKILL_NODE(10033, 369) {
    auto node369 = GET_SKILL_NODE(369, PhaseNode_AddSkillBuffs);
    if (node369 == nullptr) {
        node369 = new PhaseNode_AddSkillBuffs(369, phase);
        node369->setConfigID({100331,100335});
        CALL_REGISTER_SKILL_NODE(10033, 369, node369)
    }
    if (noInit == true) {
        return node369;
    }
    auto node425 = GET_SKILL_NODE(425, PhaseNode_LineCheckNewPene);
    auto node437 = GET_SKILL_NODE(437, PhaseNode_GetActorAttribute);
    if (node425 != nullptr) node369->setTarget(node425->getOutput());
    if (node437 != nullptr) node369->setAttribute(node437->getAttribute());
    return node369;
}
//--------------------------------------------------------------------------------
// CameraOffset
//
REGISTER_REGISTER_SKILL_NODE(10033, 389) {
    pnode->resizeTrigger(PhaseNode_CameraOffset::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLineRotation>(PhaseNode_CameraOffset::TRIGGER_DONE, 433, PhaseNode_GetLineRotation::FUNC_DO, &PhaseNode_GetLineRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(10033, 389) {
    auto node389 = GET_SKILL_NODE(389, PhaseNode_CameraOffset);
    if (node389 == nullptr) {
        node389 = new PhaseNode_CameraOffset(389, phase);
        node389->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node389->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node389->setOffsetX(.00f);
        node389->setOffsetY(-8.00f);
        node389->setOffsetZ(12.00f);
        node389->setSpeed(3.00f);
        CALL_REGISTER_SKILL_NODE(10033, 389, node389)
    }
    if (noInit == true) {
        return node389;
    }
    return node389;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10033, 391) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CameraOffset>(PhaseNode_Delay::TRIGGER_DONE, 393, PhaseNode_CameraOffset::FUNC_DO, &PhaseNode_CameraOffset::Do);
}

REGISTER_CREATE_SKILL_NODE(10033, 391) {
    auto node391 = GET_SKILL_NODE(391, PhaseNode_Delay);
    if (node391 == nullptr) {
        node391 = new PhaseNode_Delay(391, phase);
        node391->setTime(.15f);
        CALL_REGISTER_SKILL_NODE(10033, 391, node391)
    }
    if (noInit == true) {
        return node391;
    }
    return node391;
}
//--------------------------------------------------------------------------------
// CameraOffset
//
REGISTER_REGISTER_SKILL_NODE(10033, 393) {
    pnode->resizeTrigger(PhaseNode_CameraOffset::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CameraOffset::TRIGGER_DONE, 346, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10033, 393) {
    auto node393 = GET_SKILL_NODE(393, PhaseNode_CameraOffset);
    if (node393 == nullptr) {
        node393 = new PhaseNode_CameraOffset(393, phase);
        node393->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node393->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node393->setOffsetX(.00f);
        node393->setOffsetY(.00f);
        node393->setOffsetZ(.00f);
        node393->setSpeed(6.00f);
        CALL_REGISTER_SKILL_NODE(10033, 393, node393)
    }
    if (noInit == true) {
        return node393;
    }
    return node393;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(10033, 397) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlayEffect::TRIGGER_DONE, 400, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10033, 397) {
    auto node397 = GET_SKILL_NODE(397, PhaseNode_PlayEffect);
    if (node397 == nullptr) {
        node397 = new PhaseNode_PlayEffect(397, phase);
        node397->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node397->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node397->setEffectID(100334);
        node397->setChangeColor(true);
        node397->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node397->getVars().reserve(3);
        node397->getVars().setVariable<float>(0, .00f);
        node397->getVars().setVariable<float>(1, .00f);
        node397->getVars().setVariable<float>(2, 1.50f);
        node397->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(10033, 397, node397)
    }
    if (noInit == true) {
        return node397;
    }
    auto node419 = GET_SKILL_NODE(419, PhaseNode_GetInputLocation);
    auto node433 = GET_SKILL_NODE(433, PhaseNode_GetLineRotation);
    if (node419 != nullptr) node397->getVars().setVariable<float>(0, node419->getX());
    if (node419 != nullptr) node397->getVars().setVariable<float>(1, node419->getY());
    if (node433 != nullptr) node397->setRotation(node433->getRotation());
    return node397;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10033, 400) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StopEffect>(PhaseNode_Delay::TRIGGER_DONE, 402, PhaseNode_StopEffect::FUNC_DO, &PhaseNode_StopEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(10033, 400) {
    auto node400 = GET_SKILL_NODE(400, PhaseNode_Delay);
    if (node400 == nullptr) {
        node400 = new PhaseNode_Delay(400, phase);
        node400->setTime(1.00f);
        CALL_REGISTER_SKILL_NODE(10033, 400, node400)
    }
    if (noInit == true) {
        return node400;
    }
    return node400;
}
//--------------------------------------------------------------------------------
// StopEffect
//
REGISTER_REGISTER_SKILL_NODE(10033, 402) {
}

REGISTER_CREATE_SKILL_NODE(10033, 402) {
    auto node402 = GET_SKILL_NODE(402, PhaseNode_StopEffect);
    if (node402 == nullptr) {
        node402 = new PhaseNode_StopEffect(402, phase);
        node402->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node402->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node402->setEffectID(100334);
        CALL_REGISTER_SKILL_NODE(10033, 402, node402)
    }
    if (noInit == true) {
        return node402;
    }
    return node402;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10033, 404) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CameraXYZShake>(PhaseNode_PlaySound::TRIGGER_DONE, 406, PhaseNode_CameraXYZShake::FUNC_DO, &PhaseNode_CameraXYZShake::Do);
}

REGISTER_CREATE_SKILL_NODE(10033, 404) {
    auto node404 = GET_SKILL_NODE(404, PhaseNode_PlaySound);
    if (node404 == nullptr) {
        node404 = new PhaseNode_PlaySound(404, phase);
        node404->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node404->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node404->setSoundID("SE_Hero111_Skill_C_P2");
        node404->setTarget(0U);
        node404->setUsePos(false);
        node404->setPosX(.00f);
        node404->setPosY(.00f);
        node404->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10033, 404, node404)
    }
    if (noInit == true) {
        return node404;
    }
    return node404;
}
//--------------------------------------------------------------------------------
// CameraXYZShake
//
REGISTER_REGISTER_SKILL_NODE(10033, 406) {
}

REGISTER_CREATE_SKILL_NODE(10033, 406) {
    auto node406 = GET_SKILL_NODE(406, PhaseNode_CameraXYZShake);
    if (node406 == nullptr) {
        node406 = new PhaseNode_CameraXYZShake(406, phase);
        node406->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node406->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node406->setShakeStyle(0);
        node406->setTarget(0U);
        node406->setX(.20f);
        node406->setY(.30f);
        node406->setZ(.10f);
        node406->setDuration(.20f);
        node406->setTimes(5);
        CALL_REGISTER_SKILL_NODE(10033, 406, node406)
    }
    if (noInit == true) {
        return node406;
    }
    return node406;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(10033, 408) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_PlayEffect::TRIGGER_DONE, 404, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10033, 408) {
    auto node408 = GET_SKILL_NODE(408, PhaseNode_PlayEffect);
    if (node408 == nullptr) {
        node408 = new PhaseNode_PlayEffect(408, phase);
        node408->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node408->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node408->setEffectID(100333);
        node408->setChangeColor(false);
        node408->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node408->getVars().reserve(3);
        node408->getVars().setVariable<float>(0, .00f);
        node408->getVars().setVariable<float>(1, .00f);
        node408->getVars().setVariable<float>(2, .00f);
        node408->setRotation(.00f);
        node408->setScale(.00f);
        CALL_REGISTER_SKILL_NODE(10033, 408, node408)
    }
    if (noInit == true) {
        return node408;
    }
    auto node342 = GET_SKILL_NODE(342, PhaseNode_GetLocation);
    if (node342 != nullptr) node408->getVars().setVariable<float>(0, node342->getX());
    if (node342 != nullptr) node408->getVars().setVariable<float>(1, node342->getY());
    return node408;
}
//--------------------------------------------------------------------------------
// AreaCollisionNewPene
//
REGISTER_REGISTER_SKILL_NODE(10033, 410) {
    pnode->resizeTrigger(PhaseNode_AreaCollisionNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_LineCheckNewPene>(PhaseNode_AreaCollisionNewPene::TRIGGER_DONE, 425, PhaseNode_LineCheckNewPene::FUNC_DO, &PhaseNode_LineCheckNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(10033, 410) {
    auto node410 = GET_SKILL_NODE(410, PhaseNode_AreaCollisionNewPene);
    if (node410 == nullptr) {
        node410 = new PhaseNode_AreaCollisionNewPene(410, phase);
        node410->setState(PhaseNode_AreaCollisionNewPene::AreaCollisionNewPene_State::Alive);
        node410->setFaction(PhaseNode_AreaCollisionNewPene::AreaCollisionNewPene_Faction::Enemy);
        node410->setOnHero(true);
        node410->setOnMinion(true);
        node410->setOnDestruct(true);
        node410->setOnShield(false);
        node410->setType(PhaseNode_AreaCollisionNewPene::AreaCollisionNewPene_Type::Circle);
        node410->setTypeParams(0, 6.00f);
        node410->setPositionZ(.00f);
        node410->setRotation(.00f);
        CALL_REGISTER_SKILL_NODE(10033, 410, node410)
    }
    if (noInit == true) {
        return node410;
    }
    auto node342 = GET_SKILL_NODE(342, PhaseNode_GetLocation);
    if (node342 != nullptr) node410->setPositionX(node342->getX());
    if (node342 != nullptr) node410->setPositionY(node342->getY());
    return node410;
}
//--------------------------------------------------------------------------------
// AreaCollisionNewPene
//
REGISTER_REGISTER_SKILL_NODE(10033, 411) {
    pnode->resizeTrigger(PhaseNode_AreaCollisionNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_LineCheckNewPene>(PhaseNode_AreaCollisionNewPene::TRIGGER_DONE, 427, PhaseNode_LineCheckNewPene::FUNC_DO, &PhaseNode_LineCheckNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(10033, 411) {
    auto node411 = GET_SKILL_NODE(411, PhaseNode_AreaCollisionNewPene);
    if (node411 == nullptr) {
        node411 = new PhaseNode_AreaCollisionNewPene(411, phase);
        node411->setState(PhaseNode_AreaCollisionNewPene::AreaCollisionNewPene_State::Alive);
        node411->setFaction(PhaseNode_AreaCollisionNewPene::AreaCollisionNewPene_Faction::Enemy);
        node411->setOnHero(true);
        node411->setOnMinion(true);
        node411->setOnDestruct(true);
        node411->setOnShield(false);
        node411->setType(PhaseNode_AreaCollisionNewPene::AreaCollisionNewPene_Type::Circle);
        node411->setTypeParams(0, 3.00f);
        node411->setPositionZ(.00f);
        node411->setRotation(.00f);
        CALL_REGISTER_SKILL_NODE(10033, 411, node411)
    }
    if (noInit == true) {
        return node411;
    }
    auto node342 = GET_SKILL_NODE(342, PhaseNode_GetLocation);
    if (node342 != nullptr) node411->setPositionX(node342->getX());
    if (node342 != nullptr) node411->setPositionY(node342->getY());
    return node411;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10033, 415) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Distance>(PhaseNode_Delay::TRIGGER_DONE, 335, PhaseNode_Distance::FUNC_DO, &PhaseNode_Distance::Do);
}

REGISTER_CREATE_SKILL_NODE(10033, 415) {
    auto node415 = GET_SKILL_NODE(415, PhaseNode_Delay);
    if (node415 == nullptr) {
        node415 = new PhaseNode_Delay(415, phase);
        node415->setTime(.20f);
        CALL_REGISTER_SKILL_NODE(10033, 415, node415)
    }
    if (noInit == true) {
        return node415;
    }
    return node415;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(10033, 417) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetInputLocation>(PhaseNode_GetLocation::TRIGGER_DONE, 419, PhaseNode_GetInputLocation::FUNC_DO, &PhaseNode_GetInputLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(10033, 417) {
    auto node417 = GET_SKILL_NODE(417, PhaseNode_GetLocation);
    if (node417 == nullptr) {
        node417 = new PhaseNode_GetLocation(417, phase);
        node417->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node417->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(10033, 417, node417)
    }
    if (noInit == true) {
        return node417;
    }
    return node417;
}
//--------------------------------------------------------------------------------
// GetInputLocation
//
REGISTER_REGISTER_SKILL_NODE(10033, 419) {
    pnode->resizeTrigger(PhaseNode_GetInputLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CameraOffset>(PhaseNode_GetInputLocation::TRIGGER_DONE, 389, PhaseNode_CameraOffset::FUNC_DO, &PhaseNode_CameraOffset::Do);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_GetInputLocation::TRIGGER_DONE, 288, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10033, 419) {
    auto node419 = GET_SKILL_NODE(419, PhaseNode_GetInputLocation);
    if (node419 == nullptr) {
        node419 = new PhaseNode_GetInputLocation(419, phase);
        node419->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        CALL_REGISTER_SKILL_NODE(10033, 419, node419)
    }
    if (noInit == true) {
        return node419;
    }
    return node419;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10033, 421) {
}

REGISTER_CREATE_SKILL_NODE(10033, 421) {
    auto node421 = GET_SKILL_NODE(421, PhaseNode_PlaySound);
    if (node421 == nullptr) {
        node421 = new PhaseNode_PlaySound(421, phase);
        node421->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node421->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node421->setSoundID("VO_Hero111_Skill_C");
        node421->setTarget(0U);
        node421->setUsePos(false);
        node421->setPosX(.00f);
        node421->setPosY(.00f);
        node421->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10033, 421, node421)
    }
    if (noInit == true) {
        return node421;
    }
    return node421;
}
//--------------------------------------------------------------------------------
// AddSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10033, 423) {
    pnode->resizeTrigger(PhaseNode_AddSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_AddSkillBuff::TRIGGER_DONE, 415, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10033, 423) {
    auto node423 = GET_SKILL_NODE(423, PhaseNode_AddSkillBuff);
    if (node423 == nullptr) {
        node423 = new PhaseNode_AddSkillBuff(423, phase);
        node423->setConfigID(100336);
        node423->setConfigIDs({});
        node423->setTarget(0U);
        node423->setAttribute({{}});
        CALL_REGISTER_SKILL_NODE(10033, 423, node423)
    }
    if (noInit == true) {
        return node423;
    }
    return node423;
}
//--------------------------------------------------------------------------------
// LineCheckNewPene
//
REGISTER_REGISTER_SKILL_NODE(10033, 425) {
    pnode->resizeTrigger(PhaseNode_LineCheckNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_LineCheckNewPene::TRIGGER_DONE, 369, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
}

REGISTER_CREATE_SKILL_NODE(10033, 425) {
    auto node425 = GET_SKILL_NODE(425, PhaseNode_LineCheckNewPene);
    if (node425 == nullptr) {
        node425 = new PhaseNode_LineCheckNewPene(425, phase);
        node425->setPeneProjectile(15);
        CALL_REGISTER_SKILL_NODE(10033, 425, node425)
    }
    if (noInit == true) {
        return node425;
    }
    auto node410 = GET_SKILL_NODE(410, PhaseNode_AreaCollisionNewPene);
    auto node342 = GET_SKILL_NODE(342, PhaseNode_GetLocation);
    if (node410 != nullptr) node425->setTargets(node410->getColliders());
    if (node342 != nullptr) node425->setFromX(node342->getX());
    if (node342 != nullptr) node425->setFromY(node342->getY());
    return node425;
}
//--------------------------------------------------------------------------------
// LineCheckNewPene
//
REGISTER_REGISTER_SKILL_NODE(10033, 427) {
    pnode->resizeTrigger(PhaseNode_LineCheckNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_LineCheckNewPene::TRIGGER_DONE, 327, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
}

REGISTER_CREATE_SKILL_NODE(10033, 427) {
    auto node427 = GET_SKILL_NODE(427, PhaseNode_LineCheckNewPene);
    if (node427 == nullptr) {
        node427 = new PhaseNode_LineCheckNewPene(427, phase);
        node427->setPeneProjectile(15);
        CALL_REGISTER_SKILL_NODE(10033, 427, node427)
    }
    if (noInit == true) {
        return node427;
    }
    auto node411 = GET_SKILL_NODE(411, PhaseNode_AreaCollisionNewPene);
    auto node342 = GET_SKILL_NODE(342, PhaseNode_GetLocation);
    if (node411 != nullptr) node427->setTargets(node411->getColliders());
    if (node342 != nullptr) node427->setFromX(node342->getX());
    if (node342 != nullptr) node427->setFromY(node342->getY());
    return node427;
}
//--------------------------------------------------------------------------------
// DestroyCollider
//
REGISTER_REGISTER_SKILL_NODE(10033, 431) {
    pnode->resizeTrigger(PhaseNode_DestroyCollider::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_DestroyCollider::TRIGGER_DONE, 408, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(10033, 431) {
    auto node431 = GET_SKILL_NODE(431, PhaseNode_DestroyCollider);
    if (node431 == nullptr) {
        node431 = new PhaseNode_DestroyCollider(431, phase);
        CALL_REGISTER_SKILL_NODE(10033, 431, node431)
    }
    if (noInit == true) {
        return node431;
    }
    auto node318 = GET_SKILL_NODE(318, PhaseNode_SpawnCollider);
    if (node318 != nullptr) node431->setColliderID(node318->getColliderID());
    return node431;
}
//--------------------------------------------------------------------------------
// GetLineRotation
//
REGISTER_REGISTER_SKILL_NODE(10033, 433) {
    pnode->resizeTrigger(PhaseNode_GetLineRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_GetLineRotation::TRIGGER_DONE, 397, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(10033, 433) {
    auto node433 = GET_SKILL_NODE(433, PhaseNode_GetLineRotation);
    if (node433 == nullptr) {
        node433 = new PhaseNode_GetLineRotation(433, phase);
        CALL_REGISTER_SKILL_NODE(10033, 433, node433)
    }
    if (noInit == true) {
        return node433;
    }
    auto node417 = GET_SKILL_NODE(417, PhaseNode_GetLocation);
    auto node419 = GET_SKILL_NODE(419, PhaseNode_GetInputLocation);
    if (node417 != nullptr) node433->setStartX(node417->getX());
    if (node417 != nullptr) node433->setStartY(node417->getY());
    if (node419 != nullptr) node433->setEndX(node419->getX());
    if (node419 != nullptr) node433->setEndY(node419->getY());
    return node433;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(10033, 434) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_ResetCD::TRIGGER_DONE, 435, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10033, 434) {
    auto node434 = GET_SKILL_NODE(434, PhaseNode_ResetCD);
    if (node434 == nullptr) {
        node434 = new PhaseNode_ResetCD(434, phase);
        node434->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node434->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node434->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(10033, 434, node434)
    }
    if (noInit == true) {
        return node434;
    }
    return node434;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10033, 435) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_PlayAnimation::TRIGGER_DONE, 437, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(10033, 435) {
    auto node435 = GET_SKILL_NODE(435, PhaseNode_PlayAnimation);
    if (node435 == nullptr) {
        node435 = new PhaseNode_PlayAnimation(435, phase);
        node435->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node435->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node435->setTarget(0U);
        node435->setAnimation("Skill3S1");
        node435->setParameter("");
        node435->setValue(false);
        CALL_REGISTER_SKILL_NODE(10033, 435, node435)
    }
    if (noInit == true) {
        return node435;
    }
    return node435;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10033, 436) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuff>(PhaseNode_PlaySound::TRIGGER_DONE, 367, PhaseNode_AddSkillBuff::FUNC_ADD, &PhaseNode_AddSkillBuff::Add);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_PlaySound::TRIGGER_DONE, 442, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10033, 436) {
    auto node436 = GET_SKILL_NODE(436, PhaseNode_PlaySound);
    if (node436 == nullptr) {
        node436 = new PhaseNode_PlaySound(436, phase);
        node436->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node436->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node436->setSoundID("SE_Hero111_Skill_C_P1");
        node436->setTarget(0U);
        node436->setUsePos(false);
        node436->setPosX(.00f);
        node436->setPosY(.00f);
        node436->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10033, 436, node436)
    }
    if (noInit == true) {
        return node436;
    }
    return node436;
}
//--------------------------------------------------------------------------------
// GetActorAttribute
//
REGISTER_REGISTER_SKILL_NODE(10033, 437) {
    pnode->resizeTrigger(PhaseNode_GetActorAttribute::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 436, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10033, 437) {
    auto node437 = GET_SKILL_NODE(437, PhaseNode_GetActorAttribute);
    if (node437 == nullptr) {
        node437 = new PhaseNode_GetActorAttribute(437, phase);
        node437->setTarget(0U);
        node437->setType({});
        CALL_REGISTER_SKILL_NODE(10033, 437, node437)
    }
    if (noInit == true) {
        return node437;
    }
    return node437;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10033, 439) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_IsInterruptType>(PhaseNode_Detect::TRIGGER_ON, 445, PhaseNode_IsInterruptType::FUNC_DO, &PhaseNode_IsInterruptType::Do);
}

REGISTER_CREATE_SKILL_NODE(10033, 439) {
    auto node439 = GET_SKILL_NODE(439, PhaseNode_Detect);
    if (node439 == nullptr) {
        node439 = new PhaseNode_Detect(439, phase);
        node439->setSelf(0U);
        node439->setEvent("daduan_001");
        node439->setType(PhaseNode_Detect::Detect_Type::Interrupt_Skill);
        node439->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10033, 439, node439)
    }
    if (noInit == true) {
        return node439;
    }
    return node439;
}
//--------------------------------------------------------------------------------
// SwitchToInt
//
REGISTER_REGISTER_SKILL_NODE(10033, 440) {
}

REGISTER_CREATE_SKILL_NODE(10033, 440) {
    auto node440 = GET_SKILL_NODE(440, PhaseNode_SwitchToInt);
    if (node440 == nullptr) {
        node440 = new PhaseNode_SwitchToInt(440, phase);
        CALL_REGISTER_SKILL_NODE(10033, 440, node440)
    }
    if (noInit == true) {
        return node440;
    }
    auto variables = node440->getVariables();
    if (variables != nullptr) {
        node440->setSelection(variables->getVariable<int32_t>(Variable_10033_a100339));
    }
    return node440;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10033, 442) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_RaiseEvent::TRIGGER_DONE, 451, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10033, 442) {
    auto node442 = GET_SKILL_NODE(442, PhaseNode_RaiseEvent);
    if (node442 == nullptr) {
        node442 = new PhaseNode_RaiseEvent(442, phase);
        node442->setEvent("daduan_001");
        node442->setTarget(0U);
        node442->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node442->setTypeParams(0, 0);
        node442->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10033, 442, node442)
    }
    if (noInit == true) {
        return node442;
    }
    return node442;
}
//--------------------------------------------------------------------------------
// StartPreInput
//
REGISTER_REGISTER_SKILL_NODE(10033, 443) {
    pnode->resizeTrigger(PhaseNode_StartPreInput::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_StartPreInput::TRIGGER_DONE, 447, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_StartPreInput::TRIGGER_DONE, 421, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10033, 443) {
    auto node443 = GET_SKILL_NODE(443, PhaseNode_StartPreInput);
    if (node443 == nullptr) {
        node443 = new PhaseNode_StartPreInput(443, phase);
        node443->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node443->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node443->setDelayTime(.00f);
        CALL_REGISTER_SKILL_NODE(10033, 443, node443)
    }
    if (noInit == true) {
        return node443;
    }
    return node443;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(10033, 444) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_If::TRIGGER_TRUE, 446, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10033, 444) {
    auto node444 = GET_SKILL_NODE(444, PhaseNode_If);
    if (node444 == nullptr) {
        node444 = new PhaseNode_If(444, phase);
        CALL_REGISTER_SKILL_NODE(10033, 444, node444)
    }
    if (noInit == true) {
        return node444;
    }
    auto variables = node444->getVariables();
    if (variables != nullptr) {
        node444->setCondition(variables->getVariable<bool>(Variable_10033_InterruptAnimat));
    }
    return node444;
}
//--------------------------------------------------------------------------------
// IsInterruptType
//
REGISTER_REGISTER_SKILL_NODE(10033, 445) {
    pnode->resizeTrigger(PhaseNode_IsInterruptType::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SwitchToInt>(PhaseNode_IsInterruptType::TRIGGER_BUFF, 440, PhaseNode_SwitchToInt::FUNC_SWITCH, &PhaseNode_SwitchToInt::Switch);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_POSCHANGE, 444, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTAIM, 444, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTFIRE, 444, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTRELOAD, 444, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_USESKILL, 444, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(10033, 445) {
    auto node445 = GET_SKILL_NODE(445, PhaseNode_IsInterruptType);
    if (node445 == nullptr) {
        node445 = new PhaseNode_IsInterruptType(445, phase);
        node445->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node445->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10033, 445, node445)
    }
    if (noInit == true) {
        return node445;
    }
    auto node439 = GET_SKILL_NODE(439, PhaseNode_Detect);
    if (node439 != nullptr) node445->setType(node439->getVars().getVariable<int32_t>(2));
    return node445;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10033, 446) {
}

REGISTER_CREATE_SKILL_NODE(10033, 446) {
    auto node446 = GET_SKILL_NODE(446, PhaseNode_PlayAnimation);
    if (node446 == nullptr) {
        node446 = new PhaseNode_PlayAnimation(446, phase);
        node446->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node446->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node446->setTarget(0U);
        node446->setAnimation("Idle");
        node446->setParameter("");
        node446->setValue(false);
        CALL_REGISTER_SKILL_NODE(10033, 446, node446)
    }
    if (noInit == true) {
        return node446;
    }
    return node446;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10033, 447) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_Delay::TRIGGER_DONE, 450, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(10033, 447) {
    auto node447 = GET_SKILL_NODE(447, PhaseNode_Delay);
    if (node447 == nullptr) {
        node447 = new PhaseNode_Delay(447, phase);
        node447->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(10033, 447, node447)
    }
    if (noInit == true) {
        return node447;
    }
    return node447;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(10033, 450) {
}

REGISTER_CREATE_SKILL_NODE(10033, 450) {
    auto node450 = GET_SKILL_NODE(450, PhaseNode_SetBool);
    if (node450 == nullptr) {
        node450 = new PhaseNode_SetBool(450, phase);
        node450->setName("InterruptAnimat");
        node450->setValue(true);
        CALL_REGISTER_SKILL_NODE(10033, 450, node450)
    }
    if (noInit == true) {
        return node450;
    }
    return node450;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10033, 451) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StartPreInput>(PhaseNode_RaiseEvent::TRIGGER_DONE, 443, PhaseNode_StartPreInput::FUNC_DO, &PhaseNode_StartPreInput::Do);
}

REGISTER_CREATE_SKILL_NODE(10033, 451) {
    auto node451 = GET_SKILL_NODE(451, PhaseNode_RaiseEvent);
    if (node451 == nullptr) {
        node451 = new PhaseNode_RaiseEvent(451, phase);
        node451->setEvent("Dead_001");
        node451->setTarget(0U);
        node451->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node451->setTypeParams(0, 0);
        node451->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10033, 451, node451)
    }
    if (noInit == true) {
        return node451;
    }
    return node451;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10033, 452) {
}

REGISTER_CREATE_SKILL_NODE(10033, 452) {
    auto node452 = GET_SKILL_NODE(452, PhaseNode_Detect);
    if (node452 == nullptr) {
        node452 = new PhaseNode_Detect(452, phase);
        node452->setSelf(0U);
        node452->setEvent("Dead_001");
        node452->setType(PhaseNode_Detect::Detect_Type::Actor_Dead);
        node452->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10033, 452, node452)
    }
    if (noInit == true) {
        return node452;
    }
    return node452;
}

//--------------------------------------------------------------------------------
// SkillCreator_10033
//
class SkillCreator_10033 : public SkillCreator {
public:
    SkillCreator_10033() {}
    virtual ~SkillCreator_10033() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_10033

//--------------------------------------------------------------------------------
// SkillPhase_10033
//
class SkillPhase_10033 : public SkillPhase {
public:
    SkillPhase_10033(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_10033() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(10033, 2) // StartPhase
        CASE_CREATE_SKILL_NODE(10033, 288) // Delay
        CASE_CREATE_SKILL_NODE(10033, 304) // MoveNewPene
        CASE_CREATE_SKILL_NODE(10033, 310) // Disable
        CASE_CREATE_SKILL_NODE(10033, 316) // EndPhase
        CASE_CREATE_SKILL_NODE(10033, 318) // SpawnCollider
        CASE_CREATE_SKILL_NODE(10033, 327) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(10033, 332) // AttachTo
        CASE_CREATE_SKILL_NODE(10033, 335) // Distance
        CASE_CREATE_SKILL_NODE(10033, 337) // GetLineRotation
        CASE_CREATE_SKILL_NODE(10033, 342) // GetLocation
        CASE_CREATE_SKILL_NODE(10033, 346) // Delay
        CASE_CREATE_SKILL_NODE(10033, 350) // FloatOperation
        CASE_CREATE_SKILL_NODE(10033, 359) // CompareFloat
        CASE_CREATE_SKILL_NODE(10033, 367) // AddSkillBuff
        CASE_CREATE_SKILL_NODE(10033, 369) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(10033, 389) // CameraOffset
        CASE_CREATE_SKILL_NODE(10033, 391) // Delay
        CASE_CREATE_SKILL_NODE(10033, 393) // CameraOffset
        CASE_CREATE_SKILL_NODE(10033, 397) // PlayEffect
        CASE_CREATE_SKILL_NODE(10033, 400) // Delay
        CASE_CREATE_SKILL_NODE(10033, 402) // StopEffect
        CASE_CREATE_SKILL_NODE(10033, 404) // PlaySound
        CASE_CREATE_SKILL_NODE(10033, 406) // CameraXYZShake
        CASE_CREATE_SKILL_NODE(10033, 408) // PlayEffect
        CASE_CREATE_SKILL_NODE(10033, 410) // AreaCollisionNewPene
        CASE_CREATE_SKILL_NODE(10033, 411) // AreaCollisionNewPene
        CASE_CREATE_SKILL_NODE(10033, 415) // Delay
        CASE_CREATE_SKILL_NODE(10033, 417) // GetLocation
        CASE_CREATE_SKILL_NODE(10033, 419) // GetInputLocation
        CASE_CREATE_SKILL_NODE(10033, 421) // PlaySound
        CASE_CREATE_SKILL_NODE(10033, 423) // AddSkillBuff
        CASE_CREATE_SKILL_NODE(10033, 425) // LineCheckNewPene
        CASE_CREATE_SKILL_NODE(10033, 427) // LineCheckNewPene
        CASE_CREATE_SKILL_NODE(10033, 431) // DestroyCollider
        CASE_CREATE_SKILL_NODE(10033, 433) // GetLineRotation
        CASE_CREATE_SKILL_NODE(10033, 434) // ResetCD
        CASE_CREATE_SKILL_NODE(10033, 435) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10033, 436) // PlaySound
        CASE_CREATE_SKILL_NODE(10033, 437) // GetActorAttribute
        CASE_CREATE_SKILL_NODE(10033, 439) // Detect
        CASE_CREATE_SKILL_NODE(10033, 440) // SwitchToInt
        CASE_CREATE_SKILL_NODE(10033, 442) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10033, 443) // StartPreInput
        CASE_CREATE_SKILL_NODE(10033, 444) // If
        CASE_CREATE_SKILL_NODE(10033, 445) // IsInterruptType
        CASE_CREATE_SKILL_NODE(10033, 446) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10033, 447) // Delay
        CASE_CREATE_SKILL_NODE(10033, 450) // SetBool
        CASE_CREATE_SKILL_NODE(10033, 451) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10033, 452) // Detect
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_10033

SkillLogic* SkillCreator_10033::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //设置变量
    Variable_10033_a100339 = logic->getVariables().setVariable<int32_t>("a100339", 1);
    Variable_10033_InterruptAnimat = logic->getVariables().setVariable<bool>("InterruptAnimat");
    //创建阶段phase
    auto phase = new SkillPhase_10033(1, logic, 2);
    //设置phase执行器
    phase->setRunPhaseNode(1, 2);
    phase->setDetectPhaseNode(2, 439);
    phase->setDetectPhaseNode(2, 452);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_10033::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
