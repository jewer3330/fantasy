#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

#include "skill_psnode_actorfilternewpene.h"
#include "skill_psnode_addskillbuff.h"
#include "skill_psnode_attachto.h"
#include "skill_psnode_cameraxyzshake.h"
#include "skill_psnode_createtriggernewpene.h"
#include "skill_psnode_delay.h"
#include "skill_psnode_destroycollider.h"
#include "skill_psnode_detect.h"
#include "skill_psnode_distance.h"
#include "skill_psnode_endphase.h"
#include "skill_psnode_floatoperation.h"
#include "skill_psnode_getactorattribute.h"
#include "skill_psnode_getinputrotation.h"
#include "skill_psnode_getlocation.h"
#include "skill_psnode_getrotation.h"
#include "skill_psnode_getuint64svalue.h"
#include "skill_psnode_if.h"
#include "skill_psnode_isinterrupttype.h"
#include "skill_psnode_movenewpene.h"
#include "skill_psnode_offsetcalculate.h"
#include "skill_psnode_playanimation.h"
#include "skill_psnode_playeffect.h"
#include "skill_psnode_playsound.h"
#include "skill_psnode_raiseevent.h"
#include "skill_psnode_removeskillbuff.h"
#include "skill_psnode_resetcd.h"
#include "skill_psnode_revisemapi32.h"
#include "skill_psnode_setbool.h"
#include "skill_psnode_setfloat.h"
#include "skill_psnode_setuint64.h"
#include "skill_psnode_spawncollider.h"
#include "skill_psnode_startphase.h"
#include "skill_psnode_startpreinput.h"
#include "skill_psnode_switchtoint.h"
#include "skill_psnode_triggercheck.h"
#include "skill_psnode_triggerupdate.h"

namespace pvp {

//变量声明
uint64_t Variable_10311_hit = 0;
uint64_t Variable_10311_enemy = 0;
uint64_t Variable_10311_EndX = 0;
uint64_t Variable_10311_EndY = 0;
uint64_t Variable_10311_stop = 0;
uint64_t Variable_10311_InterruptAnimat = 0;
//--------------------------------------------------------------------------------
// TriggerUpdate
//
REGISTER_REGISTER_SKILL_NODE(10311, 3) {
}

REGISTER_CREATE_SKILL_NODE(10311, 3) {
    auto node3 = GET_SKILL_NODE(3, PhaseNode_TriggerUpdate);
    if (node3 == nullptr) {
        node3 = new PhaseNode_TriggerUpdate(3, phase);
        CALL_REGISTER_SKILL_NODE(10311, 3, node3)
    }
    if (noInit == true) {
        return node3;
    }
    return node3;
}
//--------------------------------------------------------------------------------
// StartPhase
//
REGISTER_REGISTER_SKILL_NODE(10311, 5) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_StartPhase::TRIGGER_START, 531, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(10311, 5) {
    auto node5 = GET_SKILL_NODE(5, PhaseNode_StartPhase);
    if (node5 == nullptr) {
        node5 = new PhaseNode_StartPhase(5, phase);
        CALL_REGISTER_SKILL_NODE(10311, 5, node5)
    }
    if (noInit == true) {
        return node5;
    }
    return node5;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(10311, 210) {
}

REGISTER_CREATE_SKILL_NODE(10311, 210) {
    auto node210 = GET_SKILL_NODE(210, PhaseNode_EndPhase);
    if (node210 == nullptr) {
        node210 = new PhaseNode_EndPhase(210, phase);
        node210->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node210->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10311, 210, node210)
    }
    if (noInit == true) {
        return node210;
    }
    return node210;
}
//--------------------------------------------------------------------------------
// AddSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10311, 266) {
    pnode->resizeTrigger(PhaseNode_AddSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_AddSkillBuff::TRIGGER_DONE, 296, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10311, 266) {
    auto node266 = GET_SKILL_NODE(266, PhaseNode_AddSkillBuff);
    if (node266 == nullptr) {
        node266 = new PhaseNode_AddSkillBuff(266, phase);
        node266->setConfigID(103151);
        node266->setConfigIDs({});
        node266->setTarget(0U);
        node266->setAttribute({{}});
        CALL_REGISTER_SKILL_NODE(10311, 266, node266)
    }
    if (noInit == true) {
        return node266;
    }
    return node266;
}
//--------------------------------------------------------------------------------
// RemoveSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10311, 270) {
    pnode->resizeTrigger(PhaseNode_RemoveSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_RemoveSkillBuff::TRIGGER_DONE, 383, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10311, 270) {
    auto node270 = GET_SKILL_NODE(270, PhaseNode_RemoveSkillBuff);
    if (node270 == nullptr) {
        node270 = new PhaseNode_RemoveSkillBuff(270, phase);
        node270->setBuffID(0U);
        node270->setBuffIDs({});
        node270->setConfigID(103151);
        node270->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(10311, 270, node270)
    }
    if (noInit == true) {
        return node270;
    }
    return node270;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(10311, 272) {
}

REGISTER_CREATE_SKILL_NODE(10311, 272) {
    auto node272 = GET_SKILL_NODE(272, PhaseNode_EndPhase);
    if (node272 == nullptr) {
        node272 = new PhaseNode_EndPhase(272, phase);
        node272->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node272->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10311, 272, node272)
    }
    if (noInit == true) {
        return node272;
    }
    return node272;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10311, 296) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_Delay::TRIGGER_DONE, 302, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10311, 296) {
    auto node296 = GET_SKILL_NODE(296, PhaseNode_Delay);
    if (node296 == nullptr) {
        node296 = new PhaseNode_Delay(296, phase);
        node296->setTime(.15f);
        CALL_REGISTER_SKILL_NODE(10311, 296, node296)
    }
    if (noInit == true) {
        return node296;
    }
    return node296;
}
//--------------------------------------------------------------------------------
// OffsetCalculate
//
REGISTER_REGISTER_SKILL_NODE(10311, 300) {
    pnode->resizeTrigger(PhaseNode_OffsetCalculate::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnCollider>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 304, PhaseNode_SpawnCollider::FUNC_DO, &PhaseNode_SpawnCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(10311, 300) {
    auto node300 = GET_SKILL_NODE(300, PhaseNode_OffsetCalculate);
    if (node300 == nullptr) {
        node300 = new PhaseNode_OffsetCalculate(300, phase);
        node300->setPosZ(.00f);
        node300->setOffsetX(.00f);
        node300->setOffsetY(.50f);
        node300->setOffsetZ(.00f);
        node300->setRotOffset(.00f);
        CALL_REGISTER_SKILL_NODE(10311, 300, node300)
    }
    if (noInit == true) {
        return node300;
    }
    auto node474 = GET_SKILL_NODE(474, PhaseNode_GetLocation);
    auto node477 = GET_SKILL_NODE(477, PhaseNode_GetInputRotation);
    if (node474 != nullptr) node300->setPosX(node474->getX());
    if (node474 != nullptr) node300->setPosY(node474->getY());
    if (node477 != nullptr) node300->setRotation(node477->getAngle());
    return node300;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10311, 302) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_OffsetCalculate>(PhaseNode_PlaySound::TRIGGER_DONE, 300, PhaseNode_OffsetCalculate::FUNC_DO, &PhaseNode_OffsetCalculate::Do);
}

REGISTER_CREATE_SKILL_NODE(10311, 302) {
    auto node302 = GET_SKILL_NODE(302, PhaseNode_PlaySound);
    if (node302 == nullptr) {
        node302 = new PhaseNode_PlaySound(302, phase);
        node302->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node302->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node302->setSoundID("SE_Hero123_SkillA_P1");
        node302->setTarget(0U);
        node302->setUsePos(false);
        node302->setPosX(.00f);
        node302->setPosY(.00f);
        node302->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10311, 302, node302)
    }
    if (noInit == true) {
        return node302;
    }
    return node302;
}
//--------------------------------------------------------------------------------
// SpawnCollider
//
REGISTER_REGISTER_SKILL_NODE(10311, 304) {
    pnode->resizeTrigger(PhaseNode_SpawnCollider::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CameraXYZShake>(PhaseNode_SpawnCollider::TRIGGER_DONE, 468, PhaseNode_CameraXYZShake::FUNC_DO, &PhaseNode_CameraXYZShake::Do);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_SpawnCollider::TRIGGER_DONE, 536, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_SpawnCollider::TRIGGER_DONE, 415, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_MoveNewPene>(PhaseNode_SpawnCollider::TRIGGER_DONE, 324, PhaseNode_MoveNewPene::FUNC_DO, &PhaseNode_MoveNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(10311, 304) {
    auto node304 = GET_SKILL_NODE(304, PhaseNode_SpawnCollider);
    if (node304 == nullptr) {
        node304 = new PhaseNode_SpawnCollider(304, phase);
        node304->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node304->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node304->setMesh("");
        node304->setMeshScale(.00f);
        node304->setEffectID(103111);
        node304->setEffectScale(1.00f);
        node304->setType(PhaseNode_SpawnCollider::SpawnCollider_Type::Circle);
        node304->setTypeParams(0, 1.00f);
        node304->setTime(2.00f);
        node304->setreentry(false);
        node304->setCheckPeneSound(false);
        CALL_REGISTER_SKILL_NODE(10311, 304, node304)
    }
    if (noInit == true) {
        return node304;
    }
    auto node300 = GET_SKILL_NODE(300, PhaseNode_OffsetCalculate);
    auto node477 = GET_SKILL_NODE(477, PhaseNode_GetInputRotation);
    if (node300 != nullptr) node304->setPosX(node300->getOutPosX());
    if (node300 != nullptr) node304->setPosY(node300->getOutPosY());
    if (node300 != nullptr) node304->setPosZ(node300->getOutPosZ());
    if (node477 != nullptr) node304->setRotation(node477->getAngle());
    return node304;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(10311, 311) {
    pnode->resizeTrigger(PhaseNode_SetBool::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuff>(PhaseNode_SetBool::TRIGGER_DONE, 322, PhaseNode_AddSkillBuff::FUNC_ADD, &PhaseNode_AddSkillBuff::Add);
}

REGISTER_CREATE_SKILL_NODE(10311, 311) {
    auto node311 = GET_SKILL_NODE(311, PhaseNode_SetBool);
    if (node311 == nullptr) {
        node311 = new PhaseNode_SetBool(311, phase);
        node311->setName("hit");
        node311->setValue(true);
        CALL_REGISTER_SKILL_NODE(10311, 311, node311)
    }
    if (noInit == true) {
        return node311;
    }
    return node311;
}
//--------------------------------------------------------------------------------
// GetUInt64sValue
//
REGISTER_REGISTER_SKILL_NODE(10311, 313) {
    pnode->resizeTrigger(PhaseNode_GetUInt64sValue::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetUInt64>(PhaseNode_GetUInt64sValue::TRIGGER_DONE, 318, PhaseNode_SetUInt64::FUNC_SET, &PhaseNode_SetUInt64::Set);
}

REGISTER_CREATE_SKILL_NODE(10311, 313) {
    auto node313 = GET_SKILL_NODE(313, PhaseNode_GetUInt64sValue);
    if (node313 == nullptr) {
        node313 = new PhaseNode_GetUInt64sValue(313, phase);
        node313->setIndex(0);
        CALL_REGISTER_SKILL_NODE(10311, 313, node313)
    }
    if (noInit == true) {
        return node313;
    }
    auto node537 = GET_SKILL_NODE(537, PhaseNode_ActorFilterNewPene);
    if (node537 != nullptr) node313->setArr(node537->getOutput());
    return node313;
}
//--------------------------------------------------------------------------------
// SetUInt64
//
REGISTER_REGISTER_SKILL_NODE(10311, 318) {
    pnode->resizeTrigger(PhaseNode_SetUInt64::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_SetUInt64::TRIGGER_DONE, 311, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(10311, 318) {
    auto node318 = GET_SKILL_NODE(318, PhaseNode_SetUInt64);
    if (node318 == nullptr) {
        node318 = new PhaseNode_SetUInt64(318, phase);
        node318->setName("enemy");
        CALL_REGISTER_SKILL_NODE(10311, 318, node318)
    }
    if (noInit == true) {
        return node318;
    }
    auto node313 = GET_SKILL_NODE(313, PhaseNode_GetUInt64sValue);
    if (node313 != nullptr) node318->setValue(node313->getValue());
    return node318;
}
//--------------------------------------------------------------------------------
// AddSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10311, 322) {
    pnode->resizeTrigger(PhaseNode_AddSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_AddSkillBuff::TRIGGER_DONE, 462, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
    pnode->regTrigger<PhaseNode_ReviseMapI32>(PhaseNode_AddSkillBuff::TRIGGER_DONE, 515, PhaseNode_ReviseMapI32::FUNC_DO, &PhaseNode_ReviseMapI32::Do);
}

REGISTER_CREATE_SKILL_NODE(10311, 322) {
    auto node322 = GET_SKILL_NODE(322, PhaseNode_AddSkillBuff);
    if (node322 == nullptr) {
        node322 = new PhaseNode_AddSkillBuff(322, phase);
        node322->setConfigID(0);
        node322->setConfigIDs({103111,103112,103141});
        CALL_REGISTER_SKILL_NODE(10311, 322, node322)
    }
    if (noInit == true) {
        return node322;
    }
    auto node313 = GET_SKILL_NODE(313, PhaseNode_GetUInt64sValue);
    auto node534 = GET_SKILL_NODE(534, PhaseNode_GetActorAttribute);
    if (node313 != nullptr) node322->setTarget(node313->getValue());
    if (node534 != nullptr) node322->setAttribute(node534->getAttribute());
    return node322;
}
//--------------------------------------------------------------------------------
// MoveNewPene
//
REGISTER_REGISTER_SKILL_NODE(10311, 324) {
    pnode->resizeTrigger(PhaseNode_MoveNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuff>(PhaseNode_MoveNewPene::TRIGGER_BLOCKBYSHIELD, 472, PhaseNode_AddSkillBuff::FUNC_ADD, &PhaseNode_AddSkillBuff::Add);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_MoveNewPene::TRIGGER_BLOCKBYWALL, 441, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_MoveNewPene::TRIGGER_DONE, 436, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(10311, 324) {
    auto node324 = GET_SKILL_NODE(324, PhaseNode_MoveNewPene);
    if (node324 == nullptr) {
        node324 = new PhaseNode_MoveNewPene(324, phase);
        node324->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node324->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node324->setPeneType(PhaseNode_MoveNewPene::MoveNewPene_PeneType::Projectile);
        node324->setPeneValue(15);
        node324->setType(PhaseNode_MoveNewPene::MoveNewPene_Type::Charge);
        node324->getVars().reserve(4);
        node324->getVars().setVariable<float>(0, 40.00f);
        node324->getVars().setVariable<float>(1, 14.00f);
        node324->getVars().setVariable<float>(2, .00f);
        node324->getVars().setVariable<float>(3, .00f);
        node324->setreentry(false);
        node324->setStopWhenFail(true);
        node324->setCheckFaction(PhaseNode_MoveNewPene::MoveNewPene_CheckFaction::Enemy);
        CALL_REGISTER_SKILL_NODE(10311, 324, node324)
    }
    if (noInit == true) {
        return node324;
    }
    auto node304 = GET_SKILL_NODE(304, PhaseNode_SpawnCollider);
    auto node477 = GET_SKILL_NODE(477, PhaseNode_GetInputRotation);
    if (node304 != nullptr) node324->setTarget(node304->getColliderID());
    if (node477 != nullptr) node324->getVars().setVariable<float>(2, node477->getAngle());
    return node324;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10311, 326) {
}

REGISTER_CREATE_SKILL_NODE(10311, 326) {
    auto node326 = GET_SKILL_NODE(326, PhaseNode_PlayAnimation);
    if (node326 == nullptr) {
        node326 = new PhaseNode_PlayAnimation(326, phase);
        node326->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node326->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node326->setTarget(0U);
        node326->setAnimation("Skill1S2");
        node326->setParameter("");
        node326->setValue(false);
        CALL_REGISTER_SKILL_NODE(10311, 326, node326)
    }
    if (noInit == true) {
        return node326;
    }
    return node326;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(10311, 328) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_If::TRIGGER_FALSE, 465, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_If::TRIGGER_TRUE, 345, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10311, 328) {
    auto node328 = GET_SKILL_NODE(328, PhaseNode_If);
    if (node328 == nullptr) {
        node328 = new PhaseNode_If(328, phase);
        CALL_REGISTER_SKILL_NODE(10311, 328, node328)
    }
    if (noInit == true) {
        return node328;
    }
    auto variables = node328->getVariables();
    if (variables != nullptr) {
        node328->setCondition(variables->getVariable<bool>(Variable_10311_hit));
    }
    return node328;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10311, 341) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_Delay::TRIGGER_DONE, 347, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10311, 341) {
    auto node341 = GET_SKILL_NODE(341, PhaseNode_Delay);
    if (node341 == nullptr) {
        node341 = new PhaseNode_Delay(341, phase);
        node341->setTime(.06f);
        CALL_REGISTER_SKILL_NODE(10311, 341, node341)
    }
    if (noInit == true) {
        return node341;
    }
    return node341;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(10311, 343) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_GetLocation::TRIGGER_DONE, 387, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(10311, 343) {
    auto node343 = GET_SKILL_NODE(343, PhaseNode_GetLocation);
    if (node343 == nullptr) {
        node343 = new PhaseNode_GetLocation(343, phase);
        node343->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        CALL_REGISTER_SKILL_NODE(10311, 343, node343)
    }
    if (noInit == true) {
        return node343;
    }
    auto node304 = GET_SKILL_NODE(304, PhaseNode_SpawnCollider);
    if (node304 != nullptr) node343->setTarget(node304->getColliderID());
    return node343;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10311, 345) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CameraXYZShake>(PhaseNode_PlayAnimation::TRIGGER_DONE, 470, PhaseNode_CameraXYZShake::FUNC_DO, &PhaseNode_CameraXYZShake::Do);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlayAnimation::TRIGGER_DONE, 341, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10311, 345) {
    auto node345 = GET_SKILL_NODE(345, PhaseNode_PlayAnimation);
    if (node345 == nullptr) {
        node345 = new PhaseNode_PlayAnimation(345, phase);
        node345->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node345->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node345->setTarget(0U);
        node345->setAnimation("Skill1S3");
        node345->setParameter("");
        node345->setValue(false);
        CALL_REGISTER_SKILL_NODE(10311, 345, node345)
    }
    if (noInit == true) {
        return node345;
    }
    return node345;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10311, 347) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_PlaySound::TRIGGER_DONE, 361, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(10311, 347) {
    auto node347 = GET_SKILL_NODE(347, PhaseNode_PlaySound);
    if (node347 == nullptr) {
        node347 = new PhaseNode_PlaySound(347, phase);
        node347->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node347->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node347->setSoundID("SE_Hero123_SkillA_P3");
        node347->setTarget(0U);
        node347->setUsePos(false);
        node347->setPosX(.00f);
        node347->setPosY(.00f);
        node347->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10311, 347, node347)
    }
    if (noInit == true) {
        return node347;
    }
    return node347;
}
//--------------------------------------------------------------------------------
// SpawnCollider
//
REGISTER_REGISTER_SKILL_NODE(10311, 349) {
    pnode->resizeTrigger(PhaseNode_SpawnCollider::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AttachTo>(PhaseNode_SpawnCollider::TRIGGER_DONE, 355, PhaseNode_AttachTo::FUNC_DO, &PhaseNode_AttachTo::Do);
}

REGISTER_CREATE_SKILL_NODE(10311, 349) {
    auto node349 = GET_SKILL_NODE(349, PhaseNode_SpawnCollider);
    if (node349 == nullptr) {
        node349 = new PhaseNode_SpawnCollider(349, phase);
        node349->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node349->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node349->setMesh("");
        node349->setMeshScale(.00f);
        node349->setEffectID(0);
        node349->setEffectScale(.00f);
        node349->setType(PhaseNode_SpawnCollider::SpawnCollider_Type::Circle);
        node349->setTypeParams(0, .50f);
        node349->setTime(1.00f);
        node349->setPosZ(.00f);
        node349->setreentry(false);
        node349->setCheckPeneSound(false);
        CALL_REGISTER_SKILL_NODE(10311, 349, node349)
    }
    if (noInit == true) {
        return node349;
    }
    auto node353 = GET_SKILL_NODE(353, PhaseNode_GetLocation);
    auto node477 = GET_SKILL_NODE(477, PhaseNode_GetInputRotation);
    if (node353 != nullptr) node349->setPosX(node353->getX());
    if (node353 != nullptr) node349->setPosY(node353->getY());
    if (node477 != nullptr) node349->setRotation(node477->getAngle());
    return node349;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(10311, 353) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_GetLocation::TRIGGER_DONE, 447, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(10311, 353) {
    auto node353 = GET_SKILL_NODE(353, PhaseNode_GetLocation);
    if (node353 == nullptr) {
        node353 = new PhaseNode_GetLocation(353, phase);
        node353->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node353->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(10311, 353, node353)
    }
    if (noInit == true) {
        return node353;
    }
    return node353;
}
//--------------------------------------------------------------------------------
// AttachTo
//
REGISTER_REGISTER_SKILL_NODE(10311, 355) {
    pnode->resizeTrigger(PhaseNode_AttachTo::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_MoveNewPene>(PhaseNode_AttachTo::TRIGGER_DONE, 371, PhaseNode_MoveNewPene::FUNC_DO, &PhaseNode_MoveNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(10311, 355) {
    auto node355 = GET_SKILL_NODE(355, PhaseNode_AttachTo);
    if (node355 == nullptr) {
        node355 = new PhaseNode_AttachTo(355, phase);
        node355->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node355->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node355->setChild(0U);
        node355->setChangeRotation(false);
        node355->setreentry(false);
        CALL_REGISTER_SKILL_NODE(10311, 355, node355)
    }
    if (noInit == true) {
        return node355;
    }
    auto node349 = GET_SKILL_NODE(349, PhaseNode_SpawnCollider);
    if (node349 != nullptr) node355->setParent(node349->getColliderID());
    return node355;
}
//--------------------------------------------------------------------------------
// Distance
//
REGISTER_REGISTER_SKILL_NODE(10311, 357) {
    pnode->resizeTrigger(PhaseNode_Distance::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_FloatOperation>(PhaseNode_Distance::TRIGGER_DONE, 375, PhaseNode_FloatOperation::FUNC_OPERATION, &PhaseNode_FloatOperation::Operation);
}

REGISTER_CREATE_SKILL_NODE(10311, 357) {
    auto node357 = GET_SKILL_NODE(357, PhaseNode_Distance);
    if (node357 == nullptr) {
        node357 = new PhaseNode_Distance(357, phase);
        CALL_REGISTER_SKILL_NODE(10311, 357, node357)
    }
    if (noInit == true) {
        return node357;
    }
    auto variables = node357->getVariables();
    if (variables != nullptr) {
        node357->setAX(variables->getVariable<float>(Variable_10311_EndX));
        node357->setAY(variables->getVariable<float>(Variable_10311_EndY));
    }
    auto node361 = GET_SKILL_NODE(361, PhaseNode_GetLocation);
    if (node361 != nullptr) node357->setBX(node361->getX());
    if (node361 != nullptr) node357->setBY(node361->getY());
    return node357;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(10311, 361) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Distance>(PhaseNode_GetLocation::TRIGGER_DONE, 357, PhaseNode_Distance::FUNC_DO, &PhaseNode_Distance::Do);
}

REGISTER_CREATE_SKILL_NODE(10311, 361) {
    auto node361 = GET_SKILL_NODE(361, PhaseNode_GetLocation);
    if (node361 == nullptr) {
        node361 = new PhaseNode_GetLocation(361, phase);
        node361->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node361->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(10311, 361, node361)
    }
    if (noInit == true) {
        return node361;
    }
    return node361;
}
//--------------------------------------------------------------------------------
// MoveNewPene
//
REGISTER_REGISTER_SKILL_NODE(10311, 371) {
    pnode->resizeTrigger(PhaseNode_MoveNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_DestroyCollider>(PhaseNode_MoveNewPene::TRIGGER_BLOCKBYWALL, 373, PhaseNode_DestroyCollider::FUNC_DO, &PhaseNode_DestroyCollider::Do);
    pnode->regTrigger<PhaseNode_DestroyCollider>(PhaseNode_MoveNewPene::TRIGGER_DONE, 373, PhaseNode_DestroyCollider::FUNC_DO, &PhaseNode_DestroyCollider::Do);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_MoveNewPene::TRIGGER_STARTMOVE, 419, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10311, 371) {
    auto node371 = GET_SKILL_NODE(371, PhaseNode_MoveNewPene);
    if (node371 == nullptr) {
        node371 = new PhaseNode_MoveNewPene(371, phase);
        node371->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node371->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node371->setPeneType(PhaseNode_MoveNewPene::MoveNewPene_PeneType::Move);
        node371->setPeneValue(15);
        node371->setType(PhaseNode_MoveNewPene::MoveNewPene_Type::Charge);
        node371->getVars().reserve(4);
        node371->getVars().setVariable<float>(0, 40.00f);
        node371->getVars().setVariable<float>(1, .00f);
        node371->getVars().setVariable<float>(2, .00f);
        node371->getVars().setVariable<float>(3, .00f);
        node371->setreentry(false);
        node371->setStopWhenFail(true);
        node371->setCheckFaction(PhaseNode_MoveNewPene::MoveNewPene_CheckFaction::Enemy);
        CALL_REGISTER_SKILL_NODE(10311, 371, node371)
    }
    if (noInit == true) {
        return node371;
    }
    auto node349 = GET_SKILL_NODE(349, PhaseNode_SpawnCollider);
    auto node375 = GET_SKILL_NODE(375, PhaseNode_FloatOperation);
    auto node477 = GET_SKILL_NODE(477, PhaseNode_GetInputRotation);
    if (node349 != nullptr) node371->setTarget(node349->getColliderID());
    if (node375 != nullptr) node371->getVars().setVariable<float>(1, node375->getFinal());
    if (node477 != nullptr) node371->getVars().setVariable<float>(2, node477->getAngle());
    return node371;
}
//--------------------------------------------------------------------------------
// DestroyCollider
//
REGISTER_REGISTER_SKILL_NODE(10311, 373) {
    pnode->resizeTrigger(PhaseNode_DestroyCollider::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_DestroyCollider::TRIGGER_DONE, 381, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10311, 373) {
    auto node373 = GET_SKILL_NODE(373, PhaseNode_DestroyCollider);
    if (node373 == nullptr) {
        node373 = new PhaseNode_DestroyCollider(373, phase);
        CALL_REGISTER_SKILL_NODE(10311, 373, node373)
    }
    if (noInit == true) {
        return node373;
    }
    auto node349 = GET_SKILL_NODE(349, PhaseNode_SpawnCollider);
    if (node349 != nullptr) node373->setColliderID(node349->getColliderID());
    return node373;
}
//--------------------------------------------------------------------------------
// FloatOperation
//
REGISTER_REGISTER_SKILL_NODE(10311, 375) {
    pnode->resizeTrigger(PhaseNode_FloatOperation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_FloatOperation::TRIGGER_DONE, 353, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(10311, 375) {
    auto node375 = GET_SKILL_NODE(375, PhaseNode_FloatOperation);
    if (node375 == nullptr) {
        node375 = new PhaseNode_FloatOperation(375, phase);
        node375->setValue(1.00f);
        node375->setMethod(PhaseNode_FloatOperation::FloatOperation_Method::Sub);
        CALL_REGISTER_SKILL_NODE(10311, 375, node375)
    }
    if (noInit == true) {
        return node375;
    }
    auto node357 = GET_SKILL_NODE(357, PhaseNode_Distance);
    if (node357 != nullptr) node375->setBase(node357->getResult());
    return node375;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10311, 381) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlayAnimation::TRIGGER_DONE, 456, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10311, 381) {
    auto node381 = GET_SKILL_NODE(381, PhaseNode_PlayAnimation);
    if (node381 == nullptr) {
        node381 = new PhaseNode_PlayAnimation(381, phase);
        node381->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node381->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node381->setTarget(0U);
        node381->setAnimation("Skill1S5");
        node381->setParameter("");
        node381->setValue(false);
        CALL_REGISTER_SKILL_NODE(10311, 381, node381)
    }
    if (noInit == true) {
        return node381;
    }
    return node381;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10311, 383) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_Delay::TRIGGER_DONE, 210, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(10311, 383) {
    auto node383 = GET_SKILL_NODE(383, PhaseNode_Delay);
    if (node383 == nullptr) {
        node383 = new PhaseNode_Delay(383, phase);
        node383->setTime(.20f);
        CALL_REGISTER_SKILL_NODE(10311, 383, node383)
    }
    if (noInit == true) {
        return node383;
    }
    return node383;
}
//--------------------------------------------------------------------------------
// Distance
//
REGISTER_REGISTER_SKILL_NODE(10311, 385) {
    pnode->resizeTrigger(PhaseNode_Distance::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_OffsetCalculate>(PhaseNode_Distance::TRIGGER_DONE, 438, PhaseNode_OffsetCalculate::FUNC_DO, &PhaseNode_OffsetCalculate::Do);
}

REGISTER_CREATE_SKILL_NODE(10311, 385) {
    auto node385 = GET_SKILL_NODE(385, PhaseNode_Distance);
    if (node385 == nullptr) {
        node385 = new PhaseNode_Distance(385, phase);
        CALL_REGISTER_SKILL_NODE(10311, 385, node385)
    }
    if (noInit == true) {
        return node385;
    }
    auto node343 = GET_SKILL_NODE(343, PhaseNode_GetLocation);
    auto node387 = GET_SKILL_NODE(387, PhaseNode_GetLocation);
    if (node343 != nullptr) node385->setAX(node343->getX());
    if (node343 != nullptr) node385->setAY(node343->getY());
    if (node387 != nullptr) node385->setBX(node387->getX());
    if (node387 != nullptr) node385->setBY(node387->getY());
    return node385;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(10311, 387) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Distance>(PhaseNode_GetLocation::TRIGGER_DONE, 385, PhaseNode_Distance::FUNC_DO, &PhaseNode_Distance::Do);
}

REGISTER_CREATE_SKILL_NODE(10311, 387) {
    auto node387 = GET_SKILL_NODE(387, PhaseNode_GetLocation);
    if (node387 == nullptr) {
        node387 = new PhaseNode_GetLocation(387, phase);
        node387->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node387->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(10311, 387, node387)
    }
    if (noInit == true) {
        return node387;
    }
    return node387;
}
//--------------------------------------------------------------------------------
// SpawnCollider
//
REGISTER_REGISTER_SKILL_NODE(10311, 390) {
    pnode->resizeTrigger(PhaseNode_SpawnCollider::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_DestroyCollider>(PhaseNode_SpawnCollider::TRIGGER_DONE, 392, PhaseNode_DestroyCollider::FUNC_DO, &PhaseNode_DestroyCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(10311, 390) {
    auto node390 = GET_SKILL_NODE(390, PhaseNode_SpawnCollider);
    if (node390 == nullptr) {
        node390 = new PhaseNode_SpawnCollider(390, phase);
        node390->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node390->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node390->setMesh("");
        node390->setMeshScale(.00f);
        node390->setEffectID(103111);
        node390->setEffectScale(1.00f);
        node390->setType(PhaseNode_SpawnCollider::SpawnCollider_Type::Circle);
        node390->setTypeParams(0, .50f);
        node390->setTime(2.00f);
        node390->setreentry(false);
        node390->setCheckPeneSound(false);
        CALL_REGISTER_SKILL_NODE(10311, 390, node390)
    }
    if (noInit == true) {
        return node390;
    }
    auto node438 = GET_SKILL_NODE(438, PhaseNode_OffsetCalculate);
    auto node477 = GET_SKILL_NODE(477, PhaseNode_GetInputRotation);
    if (node438 != nullptr) node390->setPosX(node438->getOutPosX());
    if (node438 != nullptr) node390->setPosY(node438->getOutPosY());
    if (node438 != nullptr) node390->setPosZ(node438->getOutPosZ());
    if (node477 != nullptr) node390->setRotation(node477->getAngle());
    return node390;
}
//--------------------------------------------------------------------------------
// DestroyCollider
//
REGISTER_REGISTER_SKILL_NODE(10311, 392) {
    pnode->resizeTrigger(PhaseNode_DestroyCollider::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetRotation>(PhaseNode_DestroyCollider::TRIGGER_DONE, 396, PhaseNode_GetRotation::FUNC_DO, &PhaseNode_GetRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(10311, 392) {
    auto node392 = GET_SKILL_NODE(392, PhaseNode_DestroyCollider);
    if (node392 == nullptr) {
        node392 = new PhaseNode_DestroyCollider(392, phase);
        CALL_REGISTER_SKILL_NODE(10311, 392, node392)
    }
    if (noInit == true) {
        return node392;
    }
    auto node304 = GET_SKILL_NODE(304, PhaseNode_SpawnCollider);
    if (node304 != nullptr) node392->setColliderID(node304->getColliderID());
    return node392;
}
//--------------------------------------------------------------------------------
// MoveNewPene
//
REGISTER_REGISTER_SKILL_NODE(10311, 394) {
    pnode->resizeTrigger(PhaseNode_MoveNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_DestroyCollider>(PhaseNode_MoveNewPene::TRIGGER_DONE, 398, PhaseNode_DestroyCollider::FUNC_DO, &PhaseNode_DestroyCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(10311, 394) {
    auto node394 = GET_SKILL_NODE(394, PhaseNode_MoveNewPene);
    if (node394 == nullptr) {
        node394 = new PhaseNode_MoveNewPene(394, phase);
        node394->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node394->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node394->setPeneType(PhaseNode_MoveNewPene::MoveNewPene_PeneType::Projectile);
        node394->setPeneValue(15);
        node394->setType(PhaseNode_MoveNewPene::MoveNewPene_Type::Charge);
        node394->getVars().reserve(4);
        node394->getVars().setVariable<float>(0, 50.00f);
        node394->getVars().setVariable<float>(1, .00f);
        node394->getVars().setVariable<float>(2, .00f);
        node394->getVars().setVariable<float>(3, 180.00f);
        node394->setreentry(false);
        node394->setStopWhenFail(false);
        node394->setCheckFaction(PhaseNode_MoveNewPene::MoveNewPene_CheckFaction::Enemy);
        CALL_REGISTER_SKILL_NODE(10311, 394, node394)
    }
    if (noInit == true) {
        return node394;
    }
    auto node390 = GET_SKILL_NODE(390, PhaseNode_SpawnCollider);
    auto node385 = GET_SKILL_NODE(385, PhaseNode_Distance);
    auto node396 = GET_SKILL_NODE(396, PhaseNode_GetRotation);
    if (node390 != nullptr) node394->setTarget(node390->getColliderID());
    if (node385 != nullptr) node394->getVars().setVariable<float>(1, node385->getResult());
    if (node396 != nullptr) node394->getVars().setVariable<float>(2, node396->getAngle());
    return node394;
}
//--------------------------------------------------------------------------------
// GetRotation
//
REGISTER_REGISTER_SKILL_NODE(10311, 396) {
    pnode->resizeTrigger(PhaseNode_GetRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_MoveNewPene>(PhaseNode_GetRotation::TRIGGER_DONE, 394, PhaseNode_MoveNewPene::FUNC_DO, &PhaseNode_MoveNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(10311, 396) {
    auto node396 = GET_SKILL_NODE(396, PhaseNode_GetRotation);
    if (node396 == nullptr) {
        node396 = new PhaseNode_GetRotation(396, phase);
        node396->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node396->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(10311, 396, node396)
    }
    if (noInit == true) {
        return node396;
    }
    return node396;
}
//--------------------------------------------------------------------------------
// DestroyCollider
//
REGISTER_REGISTER_SKILL_NODE(10311, 398) {
    pnode->resizeTrigger(PhaseNode_DestroyCollider::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_DestroyCollider::TRIGGER_DONE, 400, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10311, 398) {
    auto node398 = GET_SKILL_NODE(398, PhaseNode_DestroyCollider);
    if (node398 == nullptr) {
        node398 = new PhaseNode_DestroyCollider(398, phase);
        CALL_REGISTER_SKILL_NODE(10311, 398, node398)
    }
    if (noInit == true) {
        return node398;
    }
    auto node390 = GET_SKILL_NODE(390, PhaseNode_SpawnCollider);
    if (node390 != nullptr) node398->setColliderID(node390->getColliderID());
    return node398;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10311, 400) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlayAnimation::TRIGGER_DONE, 458, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10311, 400) {
    auto node400 = GET_SKILL_NODE(400, PhaseNode_PlayAnimation);
    if (node400 == nullptr) {
        node400 = new PhaseNode_PlayAnimation(400, phase);
        node400->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node400->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node400->setTarget(0U);
        node400->setAnimation("Skill1S6");
        node400->setParameter("");
        node400->setValue(false);
        CALL_REGISTER_SKILL_NODE(10311, 400, node400)
    }
    if (noInit == true) {
        return node400;
    }
    return node400;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10311, 402) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_Delay::TRIGGER_DONE, 210, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(10311, 402) {
    auto node402 = GET_SKILL_NODE(402, PhaseNode_Delay);
    if (node402 == nullptr) {
        node402 = new PhaseNode_Delay(402, phase);
        node402->setTime(.16f);
        CALL_REGISTER_SKILL_NODE(10311, 402, node402)
    }
    if (noInit == true) {
        return node402;
    }
    return node402;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10311, 415) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_Delay::TRIGGER_DONE, 326, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10311, 415) {
    auto node415 = GET_SKILL_NODE(415, PhaseNode_Delay);
    if (node415 == nullptr) {
        node415 = new PhaseNode_Delay(415, phase);
        node415->setTime(.15f);
        CALL_REGISTER_SKILL_NODE(10311, 415, node415)
    }
    if (noInit == true) {
        return node415;
    }
    return node415;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10311, 419) {
}

REGISTER_CREATE_SKILL_NODE(10311, 419) {
    auto node419 = GET_SKILL_NODE(419, PhaseNode_PlayAnimation);
    if (node419 == nullptr) {
        node419 = new PhaseNode_PlayAnimation(419, phase);
        node419->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node419->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node419->setTarget(0U);
        node419->setAnimation("Skill1S4");
        node419->setParameter("");
        node419->setValue(false);
        CALL_REGISTER_SKILL_NODE(10311, 419, node419)
    }
    if (noInit == true) {
        return node419;
    }
    return node419;
}
//--------------------------------------------------------------------------------
// SetFloat
//
REGISTER_REGISTER_SKILL_NODE(10311, 428) {
    pnode->resizeTrigger(PhaseNode_SetFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetFloat>(PhaseNode_SetFloat::TRIGGER_DONE, 430, PhaseNode_SetFloat::FUNC_SET, &PhaseNode_SetFloat::Set);
}

REGISTER_CREATE_SKILL_NODE(10311, 428) {
    auto node428 = GET_SKILL_NODE(428, PhaseNode_SetFloat);
    if (node428 == nullptr) {
        node428 = new PhaseNode_SetFloat(428, phase);
        node428->setName("EndX");
        CALL_REGISTER_SKILL_NODE(10311, 428, node428)
    }
    if (noInit == true) {
        return node428;
    }
    auto node436 = GET_SKILL_NODE(436, PhaseNode_GetLocation);
    if (node436 != nullptr) node428->setValue(node436->getX());
    return node428;
}
//--------------------------------------------------------------------------------
// SetFloat
//
REGISTER_REGISTER_SKILL_NODE(10311, 430) {
    pnode->resizeTrigger(PhaseNode_SetFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_SetFloat::TRIGGER_DONE, 328, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(10311, 430) {
    auto node430 = GET_SKILL_NODE(430, PhaseNode_SetFloat);
    if (node430 == nullptr) {
        node430 = new PhaseNode_SetFloat(430, phase);
        node430->setName("EndY");
        CALL_REGISTER_SKILL_NODE(10311, 430, node430)
    }
    if (noInit == true) {
        return node430;
    }
    auto node436 = GET_SKILL_NODE(436, PhaseNode_GetLocation);
    if (node436 != nullptr) node430->setValue(node436->getY());
    return node430;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(10311, 436) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetFloat>(PhaseNode_GetLocation::TRIGGER_DONE, 428, PhaseNode_SetFloat::FUNC_SET, &PhaseNode_SetFloat::Set);
}

REGISTER_CREATE_SKILL_NODE(10311, 436) {
    auto node436 = GET_SKILL_NODE(436, PhaseNode_GetLocation);
    if (node436 == nullptr) {
        node436 = new PhaseNode_GetLocation(436, phase);
        node436->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        CALL_REGISTER_SKILL_NODE(10311, 436, node436)
    }
    if (noInit == true) {
        return node436;
    }
    auto node304 = GET_SKILL_NODE(304, PhaseNode_SpawnCollider);
    if (node304 != nullptr) node436->setTarget(node304->getColliderID());
    return node436;
}
//--------------------------------------------------------------------------------
// OffsetCalculate
//
REGISTER_REGISTER_SKILL_NODE(10311, 438) {
    pnode->resizeTrigger(PhaseNode_OffsetCalculate::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnCollider>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 390, PhaseNode_SpawnCollider::FUNC_DO, &PhaseNode_SpawnCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(10311, 438) {
    auto node438 = GET_SKILL_NODE(438, PhaseNode_OffsetCalculate);
    if (node438 == nullptr) {
        node438 = new PhaseNode_OffsetCalculate(438, phase);
        node438->setPosZ(.00f);
        node438->setOffsetX(.00f);
        node438->setOffsetY(.00f);
        node438->setOffsetZ(.00f);
        node438->setRotation(.00f);
        node438->setRotOffset(.00f);
        CALL_REGISTER_SKILL_NODE(10311, 438, node438)
    }
    if (noInit == true) {
        return node438;
    }
    auto node343 = GET_SKILL_NODE(343, PhaseNode_GetLocation);
    if (node343 != nullptr) node438->setPosX(node343->getX());
    if (node343 != nullptr) node438->setPosY(node343->getY());
    return node438;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(10311, 441) {
    pnode->resizeTrigger(PhaseNode_SetBool::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_SetBool::TRIGGER_DONE, 436, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(10311, 441) {
    auto node441 = GET_SKILL_NODE(441, PhaseNode_SetBool);
    if (node441 == nullptr) {
        node441 = new PhaseNode_SetBool(441, phase);
        node441->setName("hit");
        node441->setValue(true);
        CALL_REGISTER_SKILL_NODE(10311, 441, node441)
    }
    if (noInit == true) {
        return node441;
    }
    return node441;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(10311, 443) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_MoveNewPene>(PhaseNode_PlayEffect::TRIGGER_DONE, 324, PhaseNode_MoveNewPene::FUNC_STOP, &PhaseNode_MoveNewPene::Stop);
}

REGISTER_CREATE_SKILL_NODE(10311, 443) {
    auto node443 = GET_SKILL_NODE(443, PhaseNode_PlayEffect);
    if (node443 == nullptr) {
        node443 = new PhaseNode_PlayEffect(443, phase);
        node443->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node443->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node443->setEffectID(103113);
        node443->setChangeColor(true);
        node443->setType(PhaseNode_PlayEffect::PlayEffect_Type::WithTarget);
        node443->getVars().reserve(5);
        node443->getVars().setVariable<uint64_t>(0, 0U);
        node443->getVars().setVariable<std::string>(1, "");
        node443->getVars().setVariable<float>(2, .00f);
        node443->getVars().setVariable<float>(3, .00f);
        node443->getVars().setVariable<float>(4, .00f);
        node443->setRotation(.00f);
        node443->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(10311, 443, node443)
    }
    if (noInit == true) {
        return node443;
    }
    auto node313 = GET_SKILL_NODE(313, PhaseNode_GetUInt64sValue);
    if (node313 != nullptr) node443->getVars().setVariable<uint64_t>(0, node313->getValue());
    return node443;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(10311, 447) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnCollider>(PhaseNode_PlayEffect::TRIGGER_DONE, 349, PhaseNode_SpawnCollider::FUNC_DO, &PhaseNode_SpawnCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(10311, 447) {
    auto node447 = GET_SKILL_NODE(447, PhaseNode_PlayEffect);
    if (node447 == nullptr) {
        node447 = new PhaseNode_PlayEffect(447, phase);
        node447->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node447->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node447->setEffectID(103115);
        node447->setChangeColor(true);
        node447->setType(PhaseNode_PlayEffect::PlayEffect_Type::WithTarget);
        node447->getVars().reserve(5);
        node447->getVars().setVariable<uint64_t>(0, 0U);
        node447->getVars().setVariable<std::string>(1, "");
        node447->getVars().setVariable<float>(2, .00f);
        node447->getVars().setVariable<float>(3, .00f);
        node447->getVars().setVariable<float>(4, .00f);
        node447->setRotation(.00f);
        node447->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(10311, 447, node447)
    }
    if (noInit == true) {
        return node447;
    }
    return node447;
}
//--------------------------------------------------------------------------------
// RemoveSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10311, 454) {
    pnode->resizeTrigger(PhaseNode_RemoveSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_RemoveSkillBuff::TRIGGER_DONE, 402, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10311, 454) {
    auto node454 = GET_SKILL_NODE(454, PhaseNode_RemoveSkillBuff);
    if (node454 == nullptr) {
        node454 = new PhaseNode_RemoveSkillBuff(454, phase);
        node454->setBuffID(0U);
        node454->setBuffIDs({});
        node454->setConfigID(103151);
        node454->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(10311, 454, node454)
    }
    if (noInit == true) {
        return node454;
    }
    return node454;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10311, 456) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RemoveSkillBuff>(PhaseNode_Delay::TRIGGER_DONE, 270, PhaseNode_RemoveSkillBuff::FUNC_REMOVE, &PhaseNode_RemoveSkillBuff::Remove);
}

REGISTER_CREATE_SKILL_NODE(10311, 456) {
    auto node456 = GET_SKILL_NODE(456, PhaseNode_Delay);
    if (node456 == nullptr) {
        node456 = new PhaseNode_Delay(456, phase);
        node456->setTime(.10f);
        CALL_REGISTER_SKILL_NODE(10311, 456, node456)
    }
    if (noInit == true) {
        return node456;
    }
    return node456;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10311, 458) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RemoveSkillBuff>(PhaseNode_Delay::TRIGGER_DONE, 454, PhaseNode_RemoveSkillBuff::FUNC_REMOVE, &PhaseNode_RemoveSkillBuff::Remove);
}

REGISTER_CREATE_SKILL_NODE(10311, 458) {
    auto node458 = GET_SKILL_NODE(458, PhaseNode_Delay);
    if (node458 == nullptr) {
        node458 = new PhaseNode_Delay(458, phase);
        node458->setTime(.10f);
        CALL_REGISTER_SKILL_NODE(10311, 458, node458)
    }
    if (noInit == true) {
        return node458;
    }
    return node458;
}
//--------------------------------------------------------------------------------
// RemoveSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10311, 460) {
    pnode->resizeTrigger(PhaseNode_RemoveSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_RemoveSkillBuff::TRIGGER_DONE, 272, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(10311, 460) {
    auto node460 = GET_SKILL_NODE(460, PhaseNode_RemoveSkillBuff);
    if (node460 == nullptr) {
        node460 = new PhaseNode_RemoveSkillBuff(460, phase);
        node460->setBuffID(0U);
        node460->setBuffIDs({});
        node460->setConfigID(103151);
        node460->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(10311, 460, node460)
    }
    if (noInit == true) {
        return node460;
    }
    return node460;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10311, 462) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_PlaySound::TRIGGER_DONE, 443, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(10311, 462) {
    auto node462 = GET_SKILL_NODE(462, PhaseNode_PlaySound);
    if (node462 == nullptr) {
        node462 = new PhaseNode_PlaySound(462, phase);
        node462->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node462->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node462->setSoundID("SE_Hero123_SkillA_P2");
        node462->setUsePos(false);
        node462->setPosX(.00f);
        node462->setPosY(.00f);
        node462->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10311, 462, node462)
    }
    if (noInit == true) {
        return node462;
    }
    auto node313 = GET_SKILL_NODE(313, PhaseNode_GetUInt64sValue);
    if (node313 != nullptr) node462->setTarget(node313->getValue());
    return node462;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10311, 465) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_PlaySound::TRIGGER_DONE, 343, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(10311, 465) {
    auto node465 = GET_SKILL_NODE(465, PhaseNode_PlaySound);
    if (node465 == nullptr) {
        node465 = new PhaseNode_PlaySound(465, phase);
        node465->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node465->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node465->setSoundID("SE_Hero123_SkillA_P4");
        node465->setTarget(0U);
        node465->setUsePos(false);
        node465->setPosX(.00f);
        node465->setPosY(.00f);
        node465->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10311, 465, node465)
    }
    if (noInit == true) {
        return node465;
    }
    return node465;
}
//--------------------------------------------------------------------------------
// CameraXYZShake
//
REGISTER_REGISTER_SKILL_NODE(10311, 468) {
}

REGISTER_CREATE_SKILL_NODE(10311, 468) {
    auto node468 = GET_SKILL_NODE(468, PhaseNode_CameraXYZShake);
    if (node468 == nullptr) {
        node468 = new PhaseNode_CameraXYZShake(468, phase);
        node468->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node468->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node468->setShakeStyle(0);
        node468->setTarget(0U);
        node468->setX(.20f);
        node468->setY(.20f);
        node468->setZ(.20f);
        node468->setDuration(.05f);
        node468->setTimes(2);
        CALL_REGISTER_SKILL_NODE(10311, 468, node468)
    }
    if (noInit == true) {
        return node468;
    }
    return node468;
}
//--------------------------------------------------------------------------------
// CameraXYZShake
//
REGISTER_REGISTER_SKILL_NODE(10311, 470) {
}

REGISTER_CREATE_SKILL_NODE(10311, 470) {
    auto node470 = GET_SKILL_NODE(470, PhaseNode_CameraXYZShake);
    if (node470 == nullptr) {
        node470 = new PhaseNode_CameraXYZShake(470, phase);
        node470->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node470->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node470->setShakeStyle(0);
        node470->setTarget(0U);
        node470->setX(.20f);
        node470->setY(.20f);
        node470->setZ(.20f);
        node470->setDuration(.05f);
        node470->setTimes(2);
        CALL_REGISTER_SKILL_NODE(10311, 470, node470)
    }
    if (noInit == true) {
        return node470;
    }
    return node470;
}
//--------------------------------------------------------------------------------
// AddSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10311, 472) {
    pnode->resizeTrigger(PhaseNode_AddSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_AddSkillBuff::TRIGGER_DONE, 465, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10311, 472) {
    auto node472 = GET_SKILL_NODE(472, PhaseNode_AddSkillBuff);
    if (node472 == nullptr) {
        node472 = new PhaseNode_AddSkillBuff(472, phase);
        node472->setConfigID(103112);
        node472->setConfigIDs({});
        CALL_REGISTER_SKILL_NODE(10311, 472, node472)
    }
    if (noInit == true) {
        return node472;
    }
    auto node324 = GET_SKILL_NODE(324, PhaseNode_MoveNewPene);
    auto node534 = GET_SKILL_NODE(534, PhaseNode_GetActorAttribute);
    if (node324 != nullptr) node472->setTarget(node324->getStopTarget());
    if (node534 != nullptr) node472->setAttribute(node534->getAttribute());
    return node472;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(10311, 474) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetInputRotation>(PhaseNode_GetLocation::TRIGGER_DONE, 477, PhaseNode_GetInputRotation::FUNC_DO, &PhaseNode_GetInputRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(10311, 474) {
    auto node474 = GET_SKILL_NODE(474, PhaseNode_GetLocation);
    if (node474 == nullptr) {
        node474 = new PhaseNode_GetLocation(474, phase);
        node474->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node474->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(10311, 474, node474)
    }
    if (noInit == true) {
        return node474;
    }
    return node474;
}
//--------------------------------------------------------------------------------
// GetInputRotation
//
REGISTER_REGISTER_SKILL_NODE(10311, 477) {
    pnode->resizeTrigger(PhaseNode_GetInputRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuff>(PhaseNode_GetInputRotation::TRIGGER_DONE, 266, PhaseNode_AddSkillBuff::FUNC_ADD, &PhaseNode_AddSkillBuff::Add);
}

REGISTER_CREATE_SKILL_NODE(10311, 477) {
    auto node477 = GET_SKILL_NODE(477, PhaseNode_GetInputRotation);
    if (node477 == nullptr) {
        node477 = new PhaseNode_GetInputRotation(477, phase);
        node477->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        CALL_REGISTER_SKILL_NODE(10311, 477, node477)
    }
    if (noInit == true) {
        return node477;
    }
    return node477;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10311, 479) {
}

REGISTER_CREATE_SKILL_NODE(10311, 479) {
    auto node479 = GET_SKILL_NODE(479, PhaseNode_PlaySound);
    if (node479 == nullptr) {
        node479 = new PhaseNode_PlaySound(479, phase);
        node479->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node479->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node479->setSoundID("VO_Hero131_Skill_A");
        node479->setTarget(0U);
        node479->setUsePos(false);
        node479->setPosX(.00f);
        node479->setPosY(.00f);
        node479->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10311, 479, node479)
    }
    if (noInit == true) {
        return node479;
    }
    return node479;
}
//--------------------------------------------------------------------------------
// AddSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10311, 514) {
}

REGISTER_CREATE_SKILL_NODE(10311, 514) {
    auto node514 = GET_SKILL_NODE(514, PhaseNode_AddSkillBuff);
    if (node514 == nullptr) {
        node514 = new PhaseNode_AddSkillBuff(514, phase);
        node514->setConfigID(0);
        node514->setConfigIDs({103123});
        node514->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(10311, 514, node514)
    }
    if (noInit == true) {
        return node514;
    }
    auto node515 = GET_SKILL_NODE(515, PhaseNode_ReviseMapI32);
    if (node515 != nullptr) node514->setAttribute(node515->getOutAttri());
    return node514;
}
//--------------------------------------------------------------------------------
// ReviseMapI32
//
REGISTER_REGISTER_SKILL_NODE(10311, 515) {
    pnode->resizeTrigger(PhaseNode_ReviseMapI32::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuff>(PhaseNode_ReviseMapI32::TRIGGER_DONE, 514, PhaseNode_AddSkillBuff::FUNC_ADD, &PhaseNode_AddSkillBuff::Add);
}

REGISTER_CREATE_SKILL_NODE(10311, 515) {
    auto node515 = GET_SKILL_NODE(515, PhaseNode_ReviseMapI32);
    if (node515 == nullptr) {
        node515 = new PhaseNode_ReviseMapI32(515, phase);
        node515->reviseValue(201, 1.00f);
        CALL_REGISTER_SKILL_NODE(10311, 515, node515)
    }
    if (noInit == true) {
        return node515;
    }
    auto node534 = GET_SKILL_NODE(534, PhaseNode_GetActorAttribute);
    if (node534 != nullptr) node515->setInAttri(node534->getAttribute());
    return node515;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10311, 517) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_IsInterruptType>(PhaseNode_Detect::TRIGGER_ON, 523, PhaseNode_IsInterruptType::FUNC_DO, &PhaseNode_IsInterruptType::Do);
}

REGISTER_CREATE_SKILL_NODE(10311, 517) {
    auto node517 = GET_SKILL_NODE(517, PhaseNode_Detect);
    if (node517 == nullptr) {
        node517 = new PhaseNode_Detect(517, phase);
        node517->setSelf(0U);
        node517->setEvent("daduan_001");
        node517->setType(PhaseNode_Detect::Detect_Type::Interrupt_Skill);
        node517->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10311, 517, node517)
    }
    if (noInit == true) {
        return node517;
    }
    return node517;
}
//--------------------------------------------------------------------------------
// SwitchToInt
//
REGISTER_REGISTER_SKILL_NODE(10311, 518) {
    pnode->resizeTrigger(4);
    pnode->regTrigger<PhaseNode_RemoveSkillBuff>(1, 460, PhaseNode_RemoveSkillBuff::FUNC_REMOVE, &PhaseNode_RemoveSkillBuff::Remove);
}

REGISTER_CREATE_SKILL_NODE(10311, 518) {
    auto node518 = GET_SKILL_NODE(518, PhaseNode_SwitchToInt);
    if (node518 == nullptr) {
        node518 = new PhaseNode_SwitchToInt(518, phase);
        CALL_REGISTER_SKILL_NODE(10311, 518, node518)
    }
    if (noInit == true) {
        return node518;
    }
    auto variables = node518->getVariables();
    if (variables != nullptr) {
        node518->setSelection(variables->getVariable<int32_t>(Variable_10311_stop));
    }
    return node518;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10311, 520) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_RaiseEvent::TRIGGER_DONE, 529, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10311, 520) {
    auto node520 = GET_SKILL_NODE(520, PhaseNode_RaiseEvent);
    if (node520 == nullptr) {
        node520 = new PhaseNode_RaiseEvent(520, phase);
        node520->setEvent("daduan_001");
        node520->setTarget(0U);
        node520->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node520->setTypeParams(0, 0);
        node520->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10311, 520, node520)
    }
    if (noInit == true) {
        return node520;
    }
    return node520;
}
//--------------------------------------------------------------------------------
// StartPreInput
//
REGISTER_REGISTER_SKILL_NODE(10311, 521) {
    pnode->resizeTrigger(PhaseNode_StartPreInput::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_StartPreInput::TRIGGER_DONE, 525, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10311, 521) {
    auto node521 = GET_SKILL_NODE(521, PhaseNode_StartPreInput);
    if (node521 == nullptr) {
        node521 = new PhaseNode_StartPreInput(521, phase);
        node521->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node521->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node521->setDelayTime(.00f);
        CALL_REGISTER_SKILL_NODE(10311, 521, node521)
    }
    if (noInit == true) {
        return node521;
    }
    return node521;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(10311, 522) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_If::TRIGGER_TRUE, 524, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10311, 522) {
    auto node522 = GET_SKILL_NODE(522, PhaseNode_If);
    if (node522 == nullptr) {
        node522 = new PhaseNode_If(522, phase);
        CALL_REGISTER_SKILL_NODE(10311, 522, node522)
    }
    if (noInit == true) {
        return node522;
    }
    auto variables = node522->getVariables();
    if (variables != nullptr) {
        node522->setCondition(variables->getVariable<bool>(Variable_10311_InterruptAnimat));
    }
    return node522;
}
//--------------------------------------------------------------------------------
// IsInterruptType
//
REGISTER_REGISTER_SKILL_NODE(10311, 523) {
    pnode->resizeTrigger(PhaseNode_IsInterruptType::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SwitchToInt>(PhaseNode_IsInterruptType::TRIGGER_BUFF, 518, PhaseNode_SwitchToInt::FUNC_SWITCH, &PhaseNode_SwitchToInt::Switch);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_POSCHANGE, 522, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTAIM, 522, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTFIRE, 522, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTRELOAD, 522, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_USESKILL, 522, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(10311, 523) {
    auto node523 = GET_SKILL_NODE(523, PhaseNode_IsInterruptType);
    if (node523 == nullptr) {
        node523 = new PhaseNode_IsInterruptType(523, phase);
        node523->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node523->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10311, 523, node523)
    }
    if (noInit == true) {
        return node523;
    }
    auto node517 = GET_SKILL_NODE(517, PhaseNode_Detect);
    if (node517 != nullptr) node523->setType(node517->getVars().getVariable<int32_t>(2));
    return node523;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10311, 524) {
}

REGISTER_CREATE_SKILL_NODE(10311, 524) {
    auto node524 = GET_SKILL_NODE(524, PhaseNode_PlayAnimation);
    if (node524 == nullptr) {
        node524 = new PhaseNode_PlayAnimation(524, phase);
        node524->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node524->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node524->setTarget(0U);
        node524->setAnimation("Idle");
        node524->setParameter("");
        node524->setValue(false);
        CALL_REGISTER_SKILL_NODE(10311, 524, node524)
    }
    if (noInit == true) {
        return node524;
    }
    return node524;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10311, 525) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_Delay::TRIGGER_DONE, 528, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(10311, 525) {
    auto node525 = GET_SKILL_NODE(525, PhaseNode_Delay);
    if (node525 == nullptr) {
        node525 = new PhaseNode_Delay(525, phase);
        node525->setTime(.20f);
        CALL_REGISTER_SKILL_NODE(10311, 525, node525)
    }
    if (noInit == true) {
        return node525;
    }
    return node525;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(10311, 528) {
}

REGISTER_CREATE_SKILL_NODE(10311, 528) {
    auto node528 = GET_SKILL_NODE(528, PhaseNode_SetBool);
    if (node528 == nullptr) {
        node528 = new PhaseNode_SetBool(528, phase);
        node528->setName("InterruptAnimat");
        node528->setValue(true);
        CALL_REGISTER_SKILL_NODE(10311, 528, node528)
    }
    if (noInit == true) {
        return node528;
    }
    return node528;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10311, 529) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StartPreInput>(PhaseNode_RaiseEvent::TRIGGER_DONE, 521, PhaseNode_StartPreInput::FUNC_DO, &PhaseNode_StartPreInput::Do);
}

REGISTER_CREATE_SKILL_NODE(10311, 529) {
    auto node529 = GET_SKILL_NODE(529, PhaseNode_RaiseEvent);
    if (node529 == nullptr) {
        node529 = new PhaseNode_RaiseEvent(529, phase);
        node529->setEvent("Dead_001");
        node529->setTarget(0U);
        node529->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node529->setTypeParams(0, 0);
        node529->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10311, 529, node529)
    }
    if (noInit == true) {
        return node529;
    }
    return node529;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10311, 530) {
}

REGISTER_CREATE_SKILL_NODE(10311, 530) {
    auto node530 = GET_SKILL_NODE(530, PhaseNode_Detect);
    if (node530 == nullptr) {
        node530 = new PhaseNode_Detect(530, phase);
        node530->setSelf(0U);
        node530->setEvent("Dead_001");
        node530->setType(PhaseNode_Detect::Detect_Type::Actor_Dead);
        node530->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10311, 530, node530)
    }
    if (noInit == true) {
        return node530;
    }
    return node530;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(10311, 531) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_ResetCD::TRIGGER_DONE, 532, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10311, 531) {
    auto node531 = GET_SKILL_NODE(531, PhaseNode_ResetCD);
    if (node531 == nullptr) {
        node531 = new PhaseNode_ResetCD(531, phase);
        node531->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node531->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node531->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(10311, 531, node531)
    }
    if (noInit == true) {
        return node531;
    }
    return node531;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10311, 532) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_PlayAnimation::TRIGGER_DONE, 534, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(10311, 532) {
    auto node532 = GET_SKILL_NODE(532, PhaseNode_PlayAnimation);
    if (node532 == nullptr) {
        node532 = new PhaseNode_PlayAnimation(532, phase);
        node532->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node532->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node532->setTarget(0U);
        node532->setAnimation("Skill1S1");
        node532->setParameter("");
        node532->setValue(false);
        CALL_REGISTER_SKILL_NODE(10311, 532, node532)
    }
    if (noInit == true) {
        return node532;
    }
    return node532;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10311, 533) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_PlaySound::TRIGGER_DONE, 474, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_PlaySound::TRIGGER_DONE, 479, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_PlaySound::TRIGGER_DONE, 520, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10311, 533) {
    auto node533 = GET_SKILL_NODE(533, PhaseNode_PlaySound);
    if (node533 == nullptr) {
        node533 = new PhaseNode_PlaySound(533, phase);
        node533->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node533->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node533->setSoundID("");
        node533->setTarget(0U);
        node533->setUsePos(false);
        node533->setPosX(.00f);
        node533->setPosY(.00f);
        node533->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10311, 533, node533)
    }
    if (noInit == true) {
        return node533;
    }
    return node533;
}
//--------------------------------------------------------------------------------
// GetActorAttribute
//
REGISTER_REGISTER_SKILL_NODE(10311, 534) {
    pnode->resizeTrigger(PhaseNode_GetActorAttribute::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 533, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10311, 534) {
    auto node534 = GET_SKILL_NODE(534, PhaseNode_GetActorAttribute);
    if (node534 == nullptr) {
        node534 = new PhaseNode_GetActorAttribute(534, phase);
        node534->setTarget(0U);
        node534->setType({});
        CALL_REGISTER_SKILL_NODE(10311, 534, node534)
    }
    if (noInit == true) {
        return node534;
    }
    return node534;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(10311, 535) {
}

REGISTER_CREATE_SKILL_NODE(10311, 535) {
    auto node535 = GET_SKILL_NODE(535, PhaseNode_TriggerCheck);
    if (node535 == nullptr) {
        node535 = new PhaseNode_TriggerCheck(535, phase);
        auto node3 = GET_SKILL_NODE(3, PhaseNode_TriggerUpdate);
        if (node3 != nullptr) node3->addTriggerCheck(node535);
        
        CALL_REGISTER_SKILL_NODE(10311, 535, node535)
    }
    if (noInit == true) {
        return node535;
    }
    auto node536 = GET_SKILL_NODE(536, PhaseNode_CreateTriggerNewPene);
    if (node536 != nullptr) node535->setTrigger(0, node536->getTriggerID());
    return node535;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(10311, 536) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 535, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 537, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(10311, 536) {
    auto node536 = GET_SKILL_NODE(536, PhaseNode_CreateTriggerNewPene);
    if (node536 == nullptr) {
        node536 = new PhaseNode_CreateTriggerNewPene(536, phase);
        node536->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::In);
        node536->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node536->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Enemy);
        node536->setOnHero(true);
        node536->setOnMinion(true);
        node536->setOnDestruct(true);
        node536->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(10311, 536, node536)
    }
    if (noInit == true) {
        return node536;
    }
    auto node304 = GET_SKILL_NODE(304, PhaseNode_SpawnCollider);
    if (node304 != nullptr) node536->setColliderID(node304->getColliderID());
    return node536;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(10311, 537) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetUInt64sValue>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 313, PhaseNode_GetUInt64sValue::FUNC_DO, &PhaseNode_GetUInt64sValue::Do);
}

REGISTER_CREATE_SKILL_NODE(10311, 537) {
    auto node537 = GET_SKILL_NODE(537, PhaseNode_ActorFilterNewPene);
    if (node537 == nullptr) {
        node537 = new PhaseNode_ActorFilterNewPene(537, phase);
        node537->setHero(true);
        node537->setMinion(true);
        node537->setDestruct(true);
        node537->setShield(false);
        node537->setTotalCount(1);
        node537->setPerCount(0);
        CALL_REGISTER_SKILL_NODE(10311, 537, node537)
    }
    if (noInit == true) {
        return node537;
    }
    auto node536 = GET_SKILL_NODE(536, PhaseNode_CreateTriggerNewPene);
    if (node536 != nullptr) node537->setInput(node536->getOther());
    return node537;
}

//--------------------------------------------------------------------------------
// SkillCreator_10311
//
class SkillCreator_10311 : public SkillCreator {
public:
    SkillCreator_10311() {}
    virtual ~SkillCreator_10311() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_10311

//--------------------------------------------------------------------------------
// SkillPhase_10311
//
class SkillPhase_10311 : public SkillPhase {
public:
    SkillPhase_10311(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_10311() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(10311, 3) // TriggerUpdate
        CASE_CREATE_SKILL_NODE(10311, 5) // StartPhase
        CASE_CREATE_SKILL_NODE(10311, 210) // EndPhase
        CASE_CREATE_SKILL_NODE(10311, 266) // AddSkillBuff
        CASE_CREATE_SKILL_NODE(10311, 270) // RemoveSkillBuff
        CASE_CREATE_SKILL_NODE(10311, 272) // EndPhase
        CASE_CREATE_SKILL_NODE(10311, 296) // Delay
        CASE_CREATE_SKILL_NODE(10311, 300) // OffsetCalculate
        CASE_CREATE_SKILL_NODE(10311, 302) // PlaySound
        CASE_CREATE_SKILL_NODE(10311, 304) // SpawnCollider
        CASE_CREATE_SKILL_NODE(10311, 311) // SetBool
        CASE_CREATE_SKILL_NODE(10311, 313) // GetUInt64sValue
        CASE_CREATE_SKILL_NODE(10311, 318) // SetUInt64
        CASE_CREATE_SKILL_NODE(10311, 322) // AddSkillBuff
        CASE_CREATE_SKILL_NODE(10311, 324) // MoveNewPene
        CASE_CREATE_SKILL_NODE(10311, 326) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10311, 328) // If
        CASE_CREATE_SKILL_NODE(10311, 341) // Delay
        CASE_CREATE_SKILL_NODE(10311, 343) // GetLocation
        CASE_CREATE_SKILL_NODE(10311, 345) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10311, 347) // PlaySound
        CASE_CREATE_SKILL_NODE(10311, 349) // SpawnCollider
        CASE_CREATE_SKILL_NODE(10311, 353) // GetLocation
        CASE_CREATE_SKILL_NODE(10311, 355) // AttachTo
        CASE_CREATE_SKILL_NODE(10311, 357) // Distance
        CASE_CREATE_SKILL_NODE(10311, 361) // GetLocation
        CASE_CREATE_SKILL_NODE(10311, 371) // MoveNewPene
        CASE_CREATE_SKILL_NODE(10311, 373) // DestroyCollider
        CASE_CREATE_SKILL_NODE(10311, 375) // FloatOperation
        CASE_CREATE_SKILL_NODE(10311, 381) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10311, 383) // Delay
        CASE_CREATE_SKILL_NODE(10311, 385) // Distance
        CASE_CREATE_SKILL_NODE(10311, 387) // GetLocation
        CASE_CREATE_SKILL_NODE(10311, 390) // SpawnCollider
        CASE_CREATE_SKILL_NODE(10311, 392) // DestroyCollider
        CASE_CREATE_SKILL_NODE(10311, 394) // MoveNewPene
        CASE_CREATE_SKILL_NODE(10311, 396) // GetRotation
        CASE_CREATE_SKILL_NODE(10311, 398) // DestroyCollider
        CASE_CREATE_SKILL_NODE(10311, 400) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10311, 402) // Delay
        CASE_CREATE_SKILL_NODE(10311, 415) // Delay
        CASE_CREATE_SKILL_NODE(10311, 419) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10311, 428) // SetFloat
        CASE_CREATE_SKILL_NODE(10311, 430) // SetFloat
        CASE_CREATE_SKILL_NODE(10311, 436) // GetLocation
        CASE_CREATE_SKILL_NODE(10311, 438) // OffsetCalculate
        CASE_CREATE_SKILL_NODE(10311, 441) // SetBool
        CASE_CREATE_SKILL_NODE(10311, 443) // PlayEffect
        CASE_CREATE_SKILL_NODE(10311, 447) // PlayEffect
        CASE_CREATE_SKILL_NODE(10311, 454) // RemoveSkillBuff
        CASE_CREATE_SKILL_NODE(10311, 456) // Delay
        CASE_CREATE_SKILL_NODE(10311, 458) // Delay
        CASE_CREATE_SKILL_NODE(10311, 460) // RemoveSkillBuff
        CASE_CREATE_SKILL_NODE(10311, 462) // PlaySound
        CASE_CREATE_SKILL_NODE(10311, 465) // PlaySound
        CASE_CREATE_SKILL_NODE(10311, 468) // CameraXYZShake
        CASE_CREATE_SKILL_NODE(10311, 470) // CameraXYZShake
        CASE_CREATE_SKILL_NODE(10311, 472) // AddSkillBuff
        CASE_CREATE_SKILL_NODE(10311, 474) // GetLocation
        CASE_CREATE_SKILL_NODE(10311, 477) // GetInputRotation
        CASE_CREATE_SKILL_NODE(10311, 479) // PlaySound
        CASE_CREATE_SKILL_NODE(10311, 514) // AddSkillBuff
        CASE_CREATE_SKILL_NODE(10311, 515) // ReviseMapI32
        CASE_CREATE_SKILL_NODE(10311, 517) // Detect
        CASE_CREATE_SKILL_NODE(10311, 518) // SwitchToInt
        CASE_CREATE_SKILL_NODE(10311, 520) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10311, 521) // StartPreInput
        CASE_CREATE_SKILL_NODE(10311, 522) // If
        CASE_CREATE_SKILL_NODE(10311, 523) // IsInterruptType
        CASE_CREATE_SKILL_NODE(10311, 524) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10311, 525) // Delay
        CASE_CREATE_SKILL_NODE(10311, 528) // SetBool
        CASE_CREATE_SKILL_NODE(10311, 529) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10311, 530) // Detect
        CASE_CREATE_SKILL_NODE(10311, 531) // ResetCD
        CASE_CREATE_SKILL_NODE(10311, 532) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10311, 533) // PlaySound
        CASE_CREATE_SKILL_NODE(10311, 534) // GetActorAttribute
        CASE_CREATE_SKILL_NODE(10311, 535) // TriggerCheck
        CASE_CREATE_SKILL_NODE(10311, 536) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(10311, 537) // ActorFilterNewPene
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_10311

SkillLogic* SkillCreator_10311::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //设置变量
    Variable_10311_hit = logic->getVariables().setVariable<bool>("hit");
    Variable_10311_enemy = logic->getVariables().setVariable<uint64_t>("enemy", 0U);
    Variable_10311_EndX = logic->getVariables().setVariable<float>("EndX");
    Variable_10311_EndY = logic->getVariables().setVariable<float>("EndY");
    Variable_10311_stop = logic->getVariables().setVariable<int32_t>("stop", 1);
    Variable_10311_InterruptAnimat = logic->getVariables().setVariable<bool>("InterruptAnimat");
    //创建阶段phase
    auto phase = new SkillPhase_10311(1, logic, 3);
    //设置phase执行器
    phase->setRunPhaseNode(1, 3);
    phase->setRunPhaseNode(2, 5);
    phase->setDetectPhaseNode(3, 517);
    phase->setDetectPhaseNode(3, 530);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_10311::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
