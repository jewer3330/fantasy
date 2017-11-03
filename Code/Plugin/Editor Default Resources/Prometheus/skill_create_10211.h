#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

#include "skill_psnode_actorfilternewpene.h"
#include "skill_psnode_addskillbuffs.h"
#include "skill_psnode_attachto.h"
#include "skill_psnode_createtriggernewpene.h"
#include "skill_psnode_delay.h"
#include "skill_psnode_destroycollider.h"
#include "skill_psnode_detect.h"
#include "skill_psnode_disable.h"
#include "skill_psnode_endphase.h"
#include "skill_psnode_findskillbuff.h"
#include "skill_psnode_getactorattribute.h"
#include "skill_psnode_getinputrotation.h"
#include "skill_psnode_getlocation.h"
#include "skill_psnode_if.h"
#include "skill_psnode_isinterrupttype.h"
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
#include "skill_psnode_switchtoint.h"
#include "skill_psnode_triggercheck.h"
#include "skill_psnode_triggerupdate.h"

namespace pvp {

//变量声明
uint64_t Variable_10211_102113 = 0;
uint64_t Variable_10211_102112 = 0;
uint64_t Variable_10211_InterruptAnimat = 0;
//--------------------------------------------------------------------------------
// StartPhase
//
REGISTER_REGISTER_SKILL_NODE(10211, 4) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_StartPhase::TRIGGER_START, 286, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(10211, 4) {
    auto node4 = GET_SKILL_NODE(4, PhaseNode_StartPhase);
    if (node4 == nullptr) {
        node4 = new PhaseNode_StartPhase(4, phase);
        CALL_REGISTER_SKILL_NODE(10211, 4, node4)
    }
    if (noInit == true) {
        return node4;
    }
    return node4;
}
//--------------------------------------------------------------------------------
// TriggerUpdate
//
REGISTER_REGISTER_SKILL_NODE(10211, 6) {
}

REGISTER_CREATE_SKILL_NODE(10211, 6) {
    auto node6 = GET_SKILL_NODE(6, PhaseNode_TriggerUpdate);
    if (node6 == nullptr) {
        node6 = new PhaseNode_TriggerUpdate(6, phase);
        CALL_REGISTER_SKILL_NODE(10211, 6, node6)
    }
    if (noInit == true) {
        return node6;
    }
    return node6;
}
//--------------------------------------------------------------------------------
// Disable
//
REGISTER_REGISTER_SKILL_NODE(10211, 17) {
    pnode->resizeTrigger(PhaseNode_Disable::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_Disable::TRIGGER_DONE, 285, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_FindSkillBuff>(PhaseNode_Disable::TRIGGER_DONE, 231, PhaseNode_FindSkillBuff::FUNC_DO, &PhaseNode_FindSkillBuff::Do);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_Disable::TRIGGER_DONE, 278, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10211, 17) {
    auto node17 = GET_SKILL_NODE(17, PhaseNode_Disable);
    if (node17 == nullptr) {
        node17 = new PhaseNode_Disable(17, phase);
        node17->setTarget(0U);
        node17->setMove(true);
        node17->setSkill(true);
        node17->setShoot(true);
        node17->setTime(.70f);
        node17->setRotate(true);
        CALL_REGISTER_SKILL_NODE(10211, 17, node17)
    }
    if (noInit == true) {
        return node17;
    }
    return node17;
}
//--------------------------------------------------------------------------------
// SpawnCollider
//
REGISTER_REGISTER_SKILL_NODE(10211, 40) {
    pnode->resizeTrigger(PhaseNode_SpawnCollider::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AttachTo>(PhaseNode_SpawnCollider::TRIGGER_DONE, 274, PhaseNode_AttachTo::FUNC_DO, &PhaseNode_AttachTo::Do);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_SpawnCollider::TRIGGER_DONE, 291, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
}

REGISTER_CREATE_SKILL_NODE(10211, 40) {
    auto node40 = GET_SKILL_NODE(40, PhaseNode_SpawnCollider);
    if (node40 == nullptr) {
        node40 = new PhaseNode_SpawnCollider(40, phase);
        node40->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node40->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node40->setMesh("");
        node40->setMeshScale(.00f);
        node40->setEffectID(0);
        node40->setEffectScale(.00f);
        node40->setType(PhaseNode_SpawnCollider::SpawnCollider_Type::Circle);
        node40->setTypeParams(0, 2.00f);
        node40->setTime(.60f);
        node40->setPosZ(.00f);
        node40->setreentry(true);
        node40->setCheckPeneSound(false);
        CALL_REGISTER_SKILL_NODE(10211, 40, node40)
    }
    if (noInit == true) {
        return node40;
    }
    auto node281 = GET_SKILL_NODE(281, PhaseNode_GetLocation);
    auto node283 = GET_SKILL_NODE(283, PhaseNode_GetInputRotation);
    if (node281 != nullptr) node40->setPosX(node281->getX());
    if (node281 != nullptr) node40->setPosY(node281->getY());
    if (node283 != nullptr) node40->setRotation(node283->getAngle());
    return node40;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(10211, 58) {
}

REGISTER_CREATE_SKILL_NODE(10211, 58) {
    auto node58 = GET_SKILL_NODE(58, PhaseNode_EndPhase);
    if (node58 == nullptr) {
        node58 = new PhaseNode_EndPhase(58, phase);
        node58->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node58->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10211, 58, node58)
    }
    if (noInit == true) {
        return node58;
    }
    return node58;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10211, 179) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_Delay::TRIGGER_DONE, 58, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(10211, 179) {
    auto node179 = GET_SKILL_NODE(179, PhaseNode_Delay);
    if (node179 == nullptr) {
        node179 = new PhaseNode_Delay(179, phase);
        node179->setTime(.65f);
        CALL_REGISTER_SKILL_NODE(10211, 179, node179)
    }
    if (noInit == true) {
        return node179;
    }
    return node179;
}
//--------------------------------------------------------------------------------
// SpawnCollider
//
REGISTER_REGISTER_SKILL_NODE(10211, 209) {
    pnode->resizeTrigger(PhaseNode_SpawnCollider::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AttachTo>(PhaseNode_SpawnCollider::TRIGGER_DONE, 211, PhaseNode_AttachTo::FUNC_DO, &PhaseNode_AttachTo::Do);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_SpawnCollider::TRIGGER_DONE, 179, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10211, 209) {
    auto node209 = GET_SKILL_NODE(209, PhaseNode_SpawnCollider);
    if (node209 == nullptr) {
        node209 = new PhaseNode_SpawnCollider(209, phase);
        node209->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node209->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node209->setMesh("");
        node209->setMeshScale(.00f);
        node209->setEffectID(0);
        node209->setEffectScale(.00f);
        node209->setType(PhaseNode_SpawnCollider::SpawnCollider_Type::Circle);
        node209->setTypeParams(0, .50f);
        node209->setTime(.70f);
        node209->setPosZ(.00f);
        node209->setreentry(true);
        node209->setCheckPeneSound(false);
        CALL_REGISTER_SKILL_NODE(10211, 209, node209)
    }
    if (noInit == true) {
        return node209;
    }
    auto node281 = GET_SKILL_NODE(281, PhaseNode_GetLocation);
    auto node283 = GET_SKILL_NODE(283, PhaseNode_GetInputRotation);
    if (node281 != nullptr) node209->setPosX(node281->getX());
    if (node281 != nullptr) node209->setPosY(node281->getY());
    if (node283 != nullptr) node209->setRotation(node283->getAngle());
    return node209;
}
//--------------------------------------------------------------------------------
// AttachTo
//
REGISTER_REGISTER_SKILL_NODE(10211, 211) {
    pnode->resizeTrigger(PhaseNode_AttachTo::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnCollider>(PhaseNode_AttachTo::TRIGGER_DONE, 40, PhaseNode_SpawnCollider::FUNC_DO, &PhaseNode_SpawnCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(10211, 211) {
    auto node211 = GET_SKILL_NODE(211, PhaseNode_AttachTo);
    if (node211 == nullptr) {
        node211 = new PhaseNode_AttachTo(211, phase);
        node211->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node211->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node211->setChild(0U);
        node211->setChangeRotation(true);
        node211->setreentry(false);
        CALL_REGISTER_SKILL_NODE(10211, 211, node211)
    }
    if (noInit == true) {
        return node211;
    }
    auto node209 = GET_SKILL_NODE(209, PhaseNode_SpawnCollider);
    if (node209 != nullptr) node211->setParent(node209->getColliderID());
    return node211;
}
//--------------------------------------------------------------------------------
// MoveNewPene
//
REGISTER_REGISTER_SKILL_NODE(10211, 213) {
    pnode->resizeTrigger(PhaseNode_MoveNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_DestroyCollider>(PhaseNode_MoveNewPene::TRIGGER_BLOCKBYSHIELD, 215, PhaseNode_DestroyCollider::FUNC_DO, &PhaseNode_DestroyCollider::Do);
    pnode->regTrigger<PhaseNode_DestroyCollider>(PhaseNode_MoveNewPene::TRIGGER_BLOCKBYWALL, 215, PhaseNode_DestroyCollider::FUNC_DO, &PhaseNode_DestroyCollider::Do);
    pnode->regTrigger<PhaseNode_DestroyCollider>(PhaseNode_MoveNewPene::TRIGGER_DONE, 215, PhaseNode_DestroyCollider::FUNC_DO, &PhaseNode_DestroyCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(10211, 213) {
    auto node213 = GET_SKILL_NODE(213, PhaseNode_MoveNewPene);
    if (node213 == nullptr) {
        node213 = new PhaseNode_MoveNewPene(213, phase);
        node213->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node213->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node213->setPeneType(PhaseNode_MoveNewPene::MoveNewPene_PeneType::Move);
        node213->setPeneValue(15);
        node213->setType(PhaseNode_MoveNewPene::MoveNewPene_Type::Charge);
        node213->getVars().reserve(4);
        node213->getVars().setVariable<float>(0, 25.00f);
        node213->getVars().setVariable<float>(1, 10.00f);
        node213->getVars().setVariable<float>(2, .00f);
        node213->getVars().setVariable<float>(3, .00f);
        node213->setreentry(false);
        node213->setStopWhenFail(false);
        node213->setCheckFaction(PhaseNode_MoveNewPene::MoveNewPene_CheckFaction::Enemy);
        CALL_REGISTER_SKILL_NODE(10211, 213, node213)
    }
    if (noInit == true) {
        return node213;
    }
    auto node209 = GET_SKILL_NODE(209, PhaseNode_SpawnCollider);
    auto node283 = GET_SKILL_NODE(283, PhaseNode_GetInputRotation);
    if (node209 != nullptr) node213->setTarget(node209->getColliderID());
    if (node283 != nullptr) node213->getVars().setVariable<float>(2, node283->getAngle());
    return node213;
}
//--------------------------------------------------------------------------------
// DestroyCollider
//
REGISTER_REGISTER_SKILL_NODE(10211, 215) {
}

REGISTER_CREATE_SKILL_NODE(10211, 215) {
    auto node215 = GET_SKILL_NODE(215, PhaseNode_DestroyCollider);
    if (node215 == nullptr) {
        node215 = new PhaseNode_DestroyCollider(215, phase);
        CALL_REGISTER_SKILL_NODE(10211, 215, node215)
    }
    if (noInit == true) {
        return node215;
    }
    auto node209 = GET_SKILL_NODE(209, PhaseNode_SpawnCollider);
    if (node209 != nullptr) node215->setColliderID(node209->getColliderID());
    return node215;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(10211, 228) {
}

REGISTER_CREATE_SKILL_NODE(10211, 228) {
    auto node228 = GET_SKILL_NODE(228, PhaseNode_AddSkillBuffs);
    if (node228 == nullptr) {
        node228 = new PhaseNode_AddSkillBuffs(228, phase);
        node228->setConfigID({102112});
        CALL_REGISTER_SKILL_NODE(10211, 228, node228)
    }
    if (noInit == true) {
        return node228;
    }
    auto node292 = GET_SKILL_NODE(292, PhaseNode_ActorFilterNewPene);
    auto node289 = GET_SKILL_NODE(289, PhaseNode_GetActorAttribute);
    if (node292 != nullptr) node228->setTarget(node292->getOutput());
    if (node289 != nullptr) node228->setAttribute(node289->getAttribute());
    return node228;
}
//--------------------------------------------------------------------------------
// FindSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10211, 231) {
    pnode->resizeTrigger(PhaseNode_FindSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_FindSkillBuff>(PhaseNode_FindSkillBuff::TRIGGER_DONE, 253, PhaseNode_FindSkillBuff::FUNC_DO, &PhaseNode_FindSkillBuff::Do);
}

REGISTER_CREATE_SKILL_NODE(10211, 231) {
    auto node231 = GET_SKILL_NODE(231, PhaseNode_FindSkillBuff);
    if (node231 == nullptr) {
        node231 = new PhaseNode_FindSkillBuff(231, phase);
        node231->setSelfTarget(0U);
        node231->setDetectTarget(0U);
        node231->setConfigID(102142);
        CALL_REGISTER_SKILL_NODE(10211, 231, node231)
    }
    if (noInit == true) {
        return node231;
    }
    return node231;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(10211, 233) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_If::TRIGGER_FALSE, 256, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_If::TRIGGER_TRUE, 264, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(10211, 233) {
    auto node233 = GET_SKILL_NODE(233, PhaseNode_If);
    if (node233 == nullptr) {
        node233 = new PhaseNode_If(233, phase);
        CALL_REGISTER_SKILL_NODE(10211, 233, node233)
    }
    if (noInit == true) {
        return node233;
    }
    auto node231 = GET_SKILL_NODE(231, PhaseNode_FindSkillBuff);
    if (node231 != nullptr) node233->setCondition(node231->getResult());
    return node233;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(10211, 241) {
}

REGISTER_CREATE_SKILL_NODE(10211, 241) {
    auto node241 = GET_SKILL_NODE(241, PhaseNode_PlayEffect);
    if (node241 == nullptr) {
        node241 = new PhaseNode_PlayEffect(241, phase);
        node241->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node241->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node241->setEffectID(102113);
        node241->setChangeColor(false);
        node241->setType(PhaseNode_PlayEffect::PlayEffect_Type::WithTarget);
        node241->getVars().reserve(5);
        node241->getVars().setVariable<uint64_t>(0, 0U);
        node241->getVars().setVariable<std::string>(1, "");
        node241->getVars().setVariable<float>(2, .00f);
        node241->getVars().setVariable<float>(3, .00f);
        node241->getVars().setVariable<float>(4, .00f);
        node241->setRotation(.00f);
        node241->setScale(.00f);
        CALL_REGISTER_SKILL_NODE(10211, 241, node241)
    }
    if (noInit == true) {
        return node241;
    }
    return node241;
}
//--------------------------------------------------------------------------------
// FindSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10211, 253) {
    pnode->resizeTrigger(PhaseNode_FindSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_FindSkillBuff::TRIGGER_DONE, 233, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(10211, 253) {
    auto node253 = GET_SKILL_NODE(253, PhaseNode_FindSkillBuff);
    if (node253 == nullptr) {
        node253 = new PhaseNode_FindSkillBuff(253, phase);
        node253->setSelfTarget(0U);
        node253->setDetectTarget(0U);
        node253->setConfigID(102141);
        CALL_REGISTER_SKILL_NODE(10211, 253, node253)
    }
    if (noInit == true) {
        return node253;
    }
    return node253;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(10211, 256) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_If::TRIGGER_TRUE, 264, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(10211, 256) {
    auto node256 = GET_SKILL_NODE(256, PhaseNode_If);
    if (node256 == nullptr) {
        node256 = new PhaseNode_If(256, phase);
        CALL_REGISTER_SKILL_NODE(10211, 256, node256)
    }
    if (noInit == true) {
        return node256;
    }
    auto node253 = GET_SKILL_NODE(253, PhaseNode_FindSkillBuff);
    if (node253 != nullptr) node256->setCondition(node253->getResult());
    return node256;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(10211, 264) {
}

REGISTER_CREATE_SKILL_NODE(10211, 264) {
    auto node264 = GET_SKILL_NODE(264, PhaseNode_SetBool);
    if (node264 == nullptr) {
        node264 = new PhaseNode_SetBool(264, phase);
        node264->setName("102113");
        node264->setValue(true);
        CALL_REGISTER_SKILL_NODE(10211, 264, node264)
    }
    if (noInit == true) {
        return node264;
    }
    return node264;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(10211, 267) {
}

REGISTER_CREATE_SKILL_NODE(10211, 267) {
    auto node267 = GET_SKILL_NODE(267, PhaseNode_AddSkillBuffs);
    if (node267 == nullptr) {
        node267 = new PhaseNode_AddSkillBuffs(267, phase);
        node267->setConfigID({102114});
        node267->setAttribute({{}});
        CALL_REGISTER_SKILL_NODE(10211, 267, node267)
    }
    if (noInit == true) {
        return node267;
    }
    auto node292 = GET_SKILL_NODE(292, PhaseNode_ActorFilterNewPene);
    if (node292 != nullptr) node267->setTarget(node292->getOutput());
    return node267;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(10211, 270) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_If::TRIGGER_TRUE, 267, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
}

REGISTER_CREATE_SKILL_NODE(10211, 270) {
    auto node270 = GET_SKILL_NODE(270, PhaseNode_If);
    if (node270 == nullptr) {
        node270 = new PhaseNode_If(270, phase);
        CALL_REGISTER_SKILL_NODE(10211, 270, node270)
    }
    if (noInit == true) {
        return node270;
    }
    auto variables = node270->getVariables();
    if (variables != nullptr) {
        node270->setCondition(variables->getVariable<bool>(Variable_10211_102113));
    }
    return node270;
}
//--------------------------------------------------------------------------------
// AttachTo
//
REGISTER_REGISTER_SKILL_NODE(10211, 274) {
    pnode->resizeTrigger(PhaseNode_AttachTo::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_MoveNewPene>(PhaseNode_AttachTo::TRIGGER_DONE, 213, PhaseNode_MoveNewPene::FUNC_DO, &PhaseNode_MoveNewPene::Do);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_AttachTo::TRIGGER_DONE, 241, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(10211, 274) {
    auto node274 = GET_SKILL_NODE(274, PhaseNode_AttachTo);
    if (node274 == nullptr) {
        node274 = new PhaseNode_AttachTo(274, phase);
        node274->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node274->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node274->setChangeRotation(false);
        node274->setreentry(false);
        CALL_REGISTER_SKILL_NODE(10211, 274, node274)
    }
    if (noInit == true) {
        return node274;
    }
    auto node209 = GET_SKILL_NODE(209, PhaseNode_SpawnCollider);
    auto node40 = GET_SKILL_NODE(40, PhaseNode_SpawnCollider);
    if (node209 != nullptr) node274->setParent(node209->getColliderID());
    if (node40 != nullptr) node274->setChild(node40->getColliderID());
    return node274;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10211, 278) {
}

REGISTER_CREATE_SKILL_NODE(10211, 278) {
    auto node278 = GET_SKILL_NODE(278, PhaseNode_PlaySound);
    if (node278 == nullptr) {
        node278 = new PhaseNode_PlaySound(278, phase);
        node278->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node278->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node278->setSoundID("SE_Hero118_Skill1_P1");
        node278->setTarget(0U);
        node278->setUsePos(false);
        node278->setPosX(.00f);
        node278->setPosY(.00f);
        node278->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10211, 278, node278)
    }
    if (noInit == true) {
        return node278;
    }
    return node278;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(10211, 281) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetInputRotation>(PhaseNode_GetLocation::TRIGGER_DONE, 283, PhaseNode_GetInputRotation::FUNC_DO, &PhaseNode_GetInputRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(10211, 281) {
    auto node281 = GET_SKILL_NODE(281, PhaseNode_GetLocation);
    if (node281 == nullptr) {
        node281 = new PhaseNode_GetLocation(281, phase);
        node281->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node281->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(10211, 281, node281)
    }
    if (noInit == true) {
        return node281;
    }
    return node281;
}
//--------------------------------------------------------------------------------
// GetInputRotation
//
REGISTER_REGISTER_SKILL_NODE(10211, 283) {
    pnode->resizeTrigger(PhaseNode_GetInputRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Disable>(PhaseNode_GetInputRotation::TRIGGER_DONE, 17, PhaseNode_Disable::FUNC_DO, &PhaseNode_Disable::Do);
}

REGISTER_CREATE_SKILL_NODE(10211, 283) {
    auto node283 = GET_SKILL_NODE(283, PhaseNode_GetInputRotation);
    if (node283 == nullptr) {
        node283 = new PhaseNode_GetInputRotation(283, phase);
        node283->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        CALL_REGISTER_SKILL_NODE(10211, 283, node283)
    }
    if (noInit == true) {
        return node283;
    }
    return node283;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10211, 285) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnCollider>(PhaseNode_Delay::TRIGGER_DONE, 209, PhaseNode_SpawnCollider::FUNC_DO, &PhaseNode_SpawnCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(10211, 285) {
    auto node285 = GET_SKILL_NODE(285, PhaseNode_Delay);
    if (node285 == nullptr) {
        node285 = new PhaseNode_Delay(285, phase);
        node285->setTime(.15f);
        CALL_REGISTER_SKILL_NODE(10211, 285, node285)
    }
    if (noInit == true) {
        return node285;
    }
    return node285;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(10211, 286) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_ResetCD::TRIGGER_DONE, 287, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10211, 286) {
    auto node286 = GET_SKILL_NODE(286, PhaseNode_ResetCD);
    if (node286 == nullptr) {
        node286 = new PhaseNode_ResetCD(286, phase);
        node286->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node286->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node286->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(10211, 286, node286)
    }
    if (noInit == true) {
        return node286;
    }
    return node286;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10211, 287) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_PlayAnimation::TRIGGER_DONE, 289, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(10211, 287) {
    auto node287 = GET_SKILL_NODE(287, PhaseNode_PlayAnimation);
    if (node287 == nullptr) {
        node287 = new PhaseNode_PlayAnimation(287, phase);
        node287->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node287->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node287->setTarget(0U);
        node287->setAnimation("Skill1S1");
        node287->setParameter("");
        node287->setValue(false);
        CALL_REGISTER_SKILL_NODE(10211, 287, node287)
    }
    if (noInit == true) {
        return node287;
    }
    return node287;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10211, 288) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_PlaySound::TRIGGER_DONE, 281, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_PlaySound::TRIGGER_DONE, 297, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10211, 288) {
    auto node288 = GET_SKILL_NODE(288, PhaseNode_PlaySound);
    if (node288 == nullptr) {
        node288 = new PhaseNode_PlaySound(288, phase);
        node288->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node288->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node288->setSoundID("VO_Hero118_Skill_A");
        node288->setTarget(0U);
        node288->setUsePos(false);
        node288->setPosX(.00f);
        node288->setPosY(.00f);
        node288->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10211, 288, node288)
    }
    if (noInit == true) {
        return node288;
    }
    return node288;
}
//--------------------------------------------------------------------------------
// GetActorAttribute
//
REGISTER_REGISTER_SKILL_NODE(10211, 289) {
    pnode->resizeTrigger(PhaseNode_GetActorAttribute::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 288, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10211, 289) {
    auto node289 = GET_SKILL_NODE(289, PhaseNode_GetActorAttribute);
    if (node289 == nullptr) {
        node289 = new PhaseNode_GetActorAttribute(289, phase);
        node289->setTarget(0U);
        node289->setType({});
        CALL_REGISTER_SKILL_NODE(10211, 289, node289)
    }
    if (noInit == true) {
        return node289;
    }
    return node289;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(10211, 290) {
}

REGISTER_CREATE_SKILL_NODE(10211, 290) {
    auto node290 = GET_SKILL_NODE(290, PhaseNode_TriggerCheck);
    if (node290 == nullptr) {
        node290 = new PhaseNode_TriggerCheck(290, phase);
        auto node6 = GET_SKILL_NODE(6, PhaseNode_TriggerUpdate);
        if (node6 != nullptr) node6->addTriggerCheck(node290);
        
        CALL_REGISTER_SKILL_NODE(10211, 290, node290)
    }
    if (noInit == true) {
        return node290;
    }
    auto node291 = GET_SKILL_NODE(291, PhaseNode_CreateTriggerNewPene);
    if (node291 != nullptr) node290->setTrigger(0, node291->getTriggerID());
    return node290;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(10211, 291) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 290, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 292, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(10211, 291) {
    auto node291 = GET_SKILL_NODE(291, PhaseNode_CreateTriggerNewPene);
    if (node291 == nullptr) {
        node291 = new PhaseNode_CreateTriggerNewPene(291, phase);
        node291->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::In);
        node291->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node291->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Enemy);
        node291->setOnHero(true);
        node291->setOnMinion(true);
        node291->setOnDestruct(true);
        node291->setOnShield(true);
        CALL_REGISTER_SKILL_NODE(10211, 291, node291)
    }
    if (noInit == true) {
        return node291;
    }
    auto node40 = GET_SKILL_NODE(40, PhaseNode_SpawnCollider);
    if (node40 != nullptr) node291->setColliderID(node40->getColliderID());
    return node291;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(10211, 292) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 228, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 270, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(10211, 292) {
    auto node292 = GET_SKILL_NODE(292, PhaseNode_ActorFilterNewPene);
    if (node292 == nullptr) {
        node292 = new PhaseNode_ActorFilterNewPene(292, phase);
        node292->setHero(true);
        node292->setMinion(true);
        node292->setDestruct(true);
        node292->setShield(true);
        node292->setTotalCount(0);
        node292->setPerCount(1);
        CALL_REGISTER_SKILL_NODE(10211, 292, node292)
    }
    if (noInit == true) {
        return node292;
    }
    auto node291 = GET_SKILL_NODE(291, PhaseNode_CreateTriggerNewPene);
    if (node291 != nullptr) node292->setInput(node291->getOther());
    return node292;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10211, 294) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_IsInterruptType>(PhaseNode_Detect::TRIGGER_ON, 300, PhaseNode_IsInterruptType::FUNC_DO, &PhaseNode_IsInterruptType::Do);
}

REGISTER_CREATE_SKILL_NODE(10211, 294) {
    auto node294 = GET_SKILL_NODE(294, PhaseNode_Detect);
    if (node294 == nullptr) {
        node294 = new PhaseNode_Detect(294, phase);
        node294->setSelf(0U);
        node294->setEvent("daduan_001");
        node294->setType(PhaseNode_Detect::Detect_Type::Interrupt_Skill);
        node294->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10211, 294, node294)
    }
    if (noInit == true) {
        return node294;
    }
    return node294;
}
//--------------------------------------------------------------------------------
// SwitchToInt
//
REGISTER_REGISTER_SKILL_NODE(10211, 295) {
    pnode->resizeTrigger(4);
    pnode->regTrigger<PhaseNode_EndPhase>(1, 58, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
    pnode->regTrigger<PhaseNode_MoveNewPene>(1, 213, PhaseNode_MoveNewPene::FUNC_STOP, &PhaseNode_MoveNewPene::Stop);
}

REGISTER_CREATE_SKILL_NODE(10211, 295) {
    auto node295 = GET_SKILL_NODE(295, PhaseNode_SwitchToInt);
    if (node295 == nullptr) {
        node295 = new PhaseNode_SwitchToInt(295, phase);
        CALL_REGISTER_SKILL_NODE(10211, 295, node295)
    }
    if (noInit == true) {
        return node295;
    }
    auto variables = node295->getVariables();
    if (variables != nullptr) {
        node295->setSelection(variables->getVariable<int32_t>(Variable_10211_102112));
    }
    return node295;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10211, 297) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_RaiseEvent::TRIGGER_DONE, 306, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10211, 297) {
    auto node297 = GET_SKILL_NODE(297, PhaseNode_RaiseEvent);
    if (node297 == nullptr) {
        node297 = new PhaseNode_RaiseEvent(297, phase);
        node297->setEvent("daduan_001");
        node297->setTarget(0U);
        node297->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node297->setTypeParams(0, 0);
        node297->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10211, 297, node297)
    }
    if (noInit == true) {
        return node297;
    }
    return node297;
}
//--------------------------------------------------------------------------------
// StartPreInput
//
REGISTER_REGISTER_SKILL_NODE(10211, 298) {
    pnode->resizeTrigger(PhaseNode_StartPreInput::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_StartPreInput::TRIGGER_DONE, 302, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10211, 298) {
    auto node298 = GET_SKILL_NODE(298, PhaseNode_StartPreInput);
    if (node298 == nullptr) {
        node298 = new PhaseNode_StartPreInput(298, phase);
        node298->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node298->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node298->setDelayTime(.00f);
        CALL_REGISTER_SKILL_NODE(10211, 298, node298)
    }
    if (noInit == true) {
        return node298;
    }
    return node298;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(10211, 299) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_If::TRIGGER_TRUE, 301, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10211, 299) {
    auto node299 = GET_SKILL_NODE(299, PhaseNode_If);
    if (node299 == nullptr) {
        node299 = new PhaseNode_If(299, phase);
        CALL_REGISTER_SKILL_NODE(10211, 299, node299)
    }
    if (noInit == true) {
        return node299;
    }
    auto variables = node299->getVariables();
    if (variables != nullptr) {
        node299->setCondition(variables->getVariable<bool>(Variable_10211_InterruptAnimat));
    }
    return node299;
}
//--------------------------------------------------------------------------------
// IsInterruptType
//
REGISTER_REGISTER_SKILL_NODE(10211, 300) {
    pnode->resizeTrigger(PhaseNode_IsInterruptType::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SwitchToInt>(PhaseNode_IsInterruptType::TRIGGER_BUFF, 295, PhaseNode_SwitchToInt::FUNC_SWITCH, &PhaseNode_SwitchToInt::Switch);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_POSCHANGE, 299, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTAIM, 299, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTFIRE, 299, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTRELOAD, 299, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_USESKILL, 299, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(10211, 300) {
    auto node300 = GET_SKILL_NODE(300, PhaseNode_IsInterruptType);
    if (node300 == nullptr) {
        node300 = new PhaseNode_IsInterruptType(300, phase);
        node300->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node300->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10211, 300, node300)
    }
    if (noInit == true) {
        return node300;
    }
    auto node294 = GET_SKILL_NODE(294, PhaseNode_Detect);
    if (node294 != nullptr) node300->setType(node294->getVars().getVariable<int32_t>(2));
    return node300;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10211, 301) {
}

REGISTER_CREATE_SKILL_NODE(10211, 301) {
    auto node301 = GET_SKILL_NODE(301, PhaseNode_PlayAnimation);
    if (node301 == nullptr) {
        node301 = new PhaseNode_PlayAnimation(301, phase);
        node301->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node301->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node301->setTarget(0U);
        node301->setAnimation("Idle");
        node301->setParameter("");
        node301->setValue(false);
        CALL_REGISTER_SKILL_NODE(10211, 301, node301)
    }
    if (noInit == true) {
        return node301;
    }
    return node301;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10211, 302) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_Delay::TRIGGER_DONE, 305, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(10211, 302) {
    auto node302 = GET_SKILL_NODE(302, PhaseNode_Delay);
    if (node302 == nullptr) {
        node302 = new PhaseNode_Delay(302, phase);
        node302->setTime(.20f);
        CALL_REGISTER_SKILL_NODE(10211, 302, node302)
    }
    if (noInit == true) {
        return node302;
    }
    return node302;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(10211, 305) {
}

REGISTER_CREATE_SKILL_NODE(10211, 305) {
    auto node305 = GET_SKILL_NODE(305, PhaseNode_SetBool);
    if (node305 == nullptr) {
        node305 = new PhaseNode_SetBool(305, phase);
        node305->setName("InterruptAnimat");
        node305->setValue(true);
        CALL_REGISTER_SKILL_NODE(10211, 305, node305)
    }
    if (noInit == true) {
        return node305;
    }
    return node305;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10211, 306) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StartPreInput>(PhaseNode_RaiseEvent::TRIGGER_DONE, 298, PhaseNode_StartPreInput::FUNC_DO, &PhaseNode_StartPreInput::Do);
}

REGISTER_CREATE_SKILL_NODE(10211, 306) {
    auto node306 = GET_SKILL_NODE(306, PhaseNode_RaiseEvent);
    if (node306 == nullptr) {
        node306 = new PhaseNode_RaiseEvent(306, phase);
        node306->setEvent("Dead_001");
        node306->setTarget(0U);
        node306->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node306->setTypeParams(0, 0);
        node306->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10211, 306, node306)
    }
    if (noInit == true) {
        return node306;
    }
    return node306;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10211, 307) {
}

REGISTER_CREATE_SKILL_NODE(10211, 307) {
    auto node307 = GET_SKILL_NODE(307, PhaseNode_Detect);
    if (node307 == nullptr) {
        node307 = new PhaseNode_Detect(307, phase);
        node307->setSelf(0U);
        node307->setEvent("Dead_001");
        node307->setType(PhaseNode_Detect::Detect_Type::Actor_Dead);
        node307->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10211, 307, node307)
    }
    if (noInit == true) {
        return node307;
    }
    return node307;
}

//--------------------------------------------------------------------------------
// SkillCreator_10211
//
class SkillCreator_10211 : public SkillCreator {
public:
    SkillCreator_10211() {}
    virtual ~SkillCreator_10211() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_10211

//--------------------------------------------------------------------------------
// SkillPhase_10211
//
class SkillPhase_10211 : public SkillPhase {
public:
    SkillPhase_10211(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_10211() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(10211, 4) // StartPhase
        CASE_CREATE_SKILL_NODE(10211, 6) // TriggerUpdate
        CASE_CREATE_SKILL_NODE(10211, 17) // Disable
        CASE_CREATE_SKILL_NODE(10211, 40) // SpawnCollider
        CASE_CREATE_SKILL_NODE(10211, 58) // EndPhase
        CASE_CREATE_SKILL_NODE(10211, 179) // Delay
        CASE_CREATE_SKILL_NODE(10211, 209) // SpawnCollider
        CASE_CREATE_SKILL_NODE(10211, 211) // AttachTo
        CASE_CREATE_SKILL_NODE(10211, 213) // MoveNewPene
        CASE_CREATE_SKILL_NODE(10211, 215) // DestroyCollider
        CASE_CREATE_SKILL_NODE(10211, 228) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(10211, 231) // FindSkillBuff
        CASE_CREATE_SKILL_NODE(10211, 233) // If
        CASE_CREATE_SKILL_NODE(10211, 241) // PlayEffect
        CASE_CREATE_SKILL_NODE(10211, 253) // FindSkillBuff
        CASE_CREATE_SKILL_NODE(10211, 256) // If
        CASE_CREATE_SKILL_NODE(10211, 264) // SetBool
        CASE_CREATE_SKILL_NODE(10211, 267) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(10211, 270) // If
        CASE_CREATE_SKILL_NODE(10211, 274) // AttachTo
        CASE_CREATE_SKILL_NODE(10211, 278) // PlaySound
        CASE_CREATE_SKILL_NODE(10211, 281) // GetLocation
        CASE_CREATE_SKILL_NODE(10211, 283) // GetInputRotation
        CASE_CREATE_SKILL_NODE(10211, 285) // Delay
        CASE_CREATE_SKILL_NODE(10211, 286) // ResetCD
        CASE_CREATE_SKILL_NODE(10211, 287) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10211, 288) // PlaySound
        CASE_CREATE_SKILL_NODE(10211, 289) // GetActorAttribute
        CASE_CREATE_SKILL_NODE(10211, 290) // TriggerCheck
        CASE_CREATE_SKILL_NODE(10211, 291) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(10211, 292) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(10211, 294) // Detect
        CASE_CREATE_SKILL_NODE(10211, 295) // SwitchToInt
        CASE_CREATE_SKILL_NODE(10211, 297) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10211, 298) // StartPreInput
        CASE_CREATE_SKILL_NODE(10211, 299) // If
        CASE_CREATE_SKILL_NODE(10211, 300) // IsInterruptType
        CASE_CREATE_SKILL_NODE(10211, 301) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10211, 302) // Delay
        CASE_CREATE_SKILL_NODE(10211, 305) // SetBool
        CASE_CREATE_SKILL_NODE(10211, 306) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10211, 307) // Detect
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_10211

SkillLogic* SkillCreator_10211::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //设置变量
    Variable_10211_102113 = logic->getVariables().setVariable<bool>("102113");
    Variable_10211_102112 = logic->getVariables().setVariable<int32_t>("102112", 1);
    Variable_10211_InterruptAnimat = logic->getVariables().setVariable<bool>("InterruptAnimat");
    //创建阶段phase
    auto phase = new SkillPhase_10211(1, logic, 3);
    //设置phase执行器
    phase->setRunPhaseNode(1, 4);
    phase->setRunPhaseNode(2, 6);
    phase->setDetectPhaseNode(3, 294);
    phase->setDetectPhaseNode(3, 307);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_10211::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
