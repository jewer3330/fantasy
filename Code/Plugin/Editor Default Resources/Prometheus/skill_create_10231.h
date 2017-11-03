#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

#include "skill_psnode_addskillbuff.h"
#include "skill_psnode_attachto.h"
#include "skill_psnode_delay.h"
#include "skill_psnode_destroycollider.h"
#include "skill_psnode_detect.h"
#include "skill_psnode_disable.h"
#include "skill_psnode_endphase.h"
#include "skill_psnode_getactorattribute.h"
#include "skill_psnode_getinputrotation.h"
#include "skill_psnode_getlocation.h"
#include "skill_psnode_if.h"
#include "skill_psnode_isinterrupttype.h"
#include "skill_psnode_movenewpene.h"
#include "skill_psnode_playanimation.h"
#include "skill_psnode_playsound.h"
#include "skill_psnode_raiseevent.h"
#include "skill_psnode_resetcd.h"
#include "skill_psnode_setbool.h"
#include "skill_psnode_spawncollider.h"
#include "skill_psnode_startphase.h"
#include "skill_psnode_startpreinput.h"
#include "skill_psnode_switchtoint.h"

namespace pvp {

//变量声明
uint64_t Variable_10231_a102312 = 0;
uint64_t Variable_10231_InterruptAnimat = 0;
//--------------------------------------------------------------------------------
// StartPhase
//
REGISTER_REGISTER_SKILL_NODE(10231, 1) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_StartPhase::TRIGGER_START, 277, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(10231, 1) {
    auto node1 = GET_SKILL_NODE(1, PhaseNode_StartPhase);
    if (node1 == nullptr) {
        node1 = new PhaseNode_StartPhase(1, phase);
        CALL_REGISTER_SKILL_NODE(10231, 1, node1)
    }
    if (noInit == true) {
        return node1;
    }
    return node1;
}
//--------------------------------------------------------------------------------
// SpawnCollider
//
REGISTER_REGISTER_SKILL_NODE(10231, 6) {
    pnode->resizeTrigger(PhaseNode_SpawnCollider::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AttachTo>(PhaseNode_SpawnCollider::TRIGGER_DONE, 10, PhaseNode_AttachTo::FUNC_DO, &PhaseNode_AttachTo::Do);
}

REGISTER_CREATE_SKILL_NODE(10231, 6) {
    auto node6 = GET_SKILL_NODE(6, PhaseNode_SpawnCollider);
    if (node6 == nullptr) {
        node6 = new PhaseNode_SpawnCollider(6, phase);
        node6->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node6->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node6->setMesh("");
        node6->setMeshScale(.00f);
        node6->setEffectID(102301);
        node6->setEffectScale(1.00f);
        node6->setType(PhaseNode_SpawnCollider::SpawnCollider_Type::Circle);
        node6->setTypeParams(0, .50f);
        node6->setTime(.50f);
        node6->setPosZ(.00f);
        node6->setreentry(true);
        node6->setCheckPeneSound(false);
        CALL_REGISTER_SKILL_NODE(10231, 6, node6)
    }
    if (noInit == true) {
        return node6;
    }
    auto node272 = GET_SKILL_NODE(272, PhaseNode_GetLocation);
    auto node274 = GET_SKILL_NODE(274, PhaseNode_GetInputRotation);
    if (node272 != nullptr) node6->setPosX(node272->getX());
    if (node272 != nullptr) node6->setPosY(node272->getY());
    if (node274 != nullptr) node6->setRotation(node274->getAngle());
    return node6;
}
//--------------------------------------------------------------------------------
// AttachTo
//
REGISTER_REGISTER_SKILL_NODE(10231, 10) {
    pnode->resizeTrigger(PhaseNode_AttachTo::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_MoveNewPene>(PhaseNode_AttachTo::TRIGGER_DONE, 166, PhaseNode_MoveNewPene::FUNC_DO, &PhaseNode_MoveNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(10231, 10) {
    auto node10 = GET_SKILL_NODE(10, PhaseNode_AttachTo);
    if (node10 == nullptr) {
        node10 = new PhaseNode_AttachTo(10, phase);
        node10->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node10->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node10->setChild(0U);
        node10->setChangeRotation(true);
        node10->setreentry(false);
        CALL_REGISTER_SKILL_NODE(10231, 10, node10)
    }
    if (noInit == true) {
        return node10;
    }
    auto node6 = GET_SKILL_NODE(6, PhaseNode_SpawnCollider);
    if (node6 != nullptr) node10->setParent(node6->getColliderID());
    return node10;
}
//--------------------------------------------------------------------------------
// Disable
//
REGISTER_REGISTER_SKILL_NODE(10231, 117) {
    pnode->resizeTrigger(PhaseNode_Disable::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuff>(PhaseNode_Disable::TRIGGER_DONE, 374, PhaseNode_AddSkillBuff::FUNC_ADD, &PhaseNode_AddSkillBuff::Add);
}

REGISTER_CREATE_SKILL_NODE(10231, 117) {
    auto node117 = GET_SKILL_NODE(117, PhaseNode_Disable);
    if (node117 == nullptr) {
        node117 = new PhaseNode_Disable(117, phase);
        node117->setTarget(0U);
        node117->setMove(true);
        node117->setSkill(true);
        node117->setShoot(true);
        node117->setTime(.42f);
        node117->setRotate(true);
        CALL_REGISTER_SKILL_NODE(10231, 117, node117)
    }
    if (noInit == true) {
        return node117;
    }
    return node117;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10231, 142) {
}

REGISTER_CREATE_SKILL_NODE(10231, 142) {
    auto node142 = GET_SKILL_NODE(142, PhaseNode_PlaySound);
    if (node142 == nullptr) {
        node142 = new PhaseNode_PlaySound(142, phase);
        node142->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node142->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node142->setSoundID("SE_Hero106_SkillA_P1");
        node142->setTarget(0U);
        node142->setUsePos(false);
        node142->setPosX(.00f);
        node142->setPosY(.00f);
        node142->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10231, 142, node142)
    }
    if (noInit == true) {
        return node142;
    }
    return node142;
}
//--------------------------------------------------------------------------------
// MoveNewPene
//
REGISTER_REGISTER_SKILL_NODE(10231, 166) {
    pnode->resizeTrigger(PhaseNode_MoveNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_DestroyCollider>(PhaseNode_MoveNewPene::TRIGGER_BLOCKBYSHIELD, 169, PhaseNode_DestroyCollider::FUNC_DO, &PhaseNode_DestroyCollider::Do);
    pnode->regTrigger<PhaseNode_DestroyCollider>(PhaseNode_MoveNewPene::TRIGGER_BLOCKBYWALL, 169, PhaseNode_DestroyCollider::FUNC_DO, &PhaseNode_DestroyCollider::Do);
    pnode->regTrigger<PhaseNode_DestroyCollider>(PhaseNode_MoveNewPene::TRIGGER_DONE, 169, PhaseNode_DestroyCollider::FUNC_DO, &PhaseNode_DestroyCollider::Do);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_MoveNewPene::TRIGGER_STARTMOVE, 357, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10231, 166) {
    auto node166 = GET_SKILL_NODE(166, PhaseNode_MoveNewPene);
    if (node166 == nullptr) {
        node166 = new PhaseNode_MoveNewPene(166, phase);
        node166->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node166->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node166->setPeneType(PhaseNode_MoveNewPene::MoveNewPene_PeneType::Move);
        node166->setPeneValue(15);
        node166->setType(PhaseNode_MoveNewPene::MoveNewPene_Type::Charge);
        node166->getVars().reserve(4);
        node166->getVars().setVariable<float>(0, 15.00f);
        node166->getVars().setVariable<float>(1, 6.00f);
        node166->getVars().setVariable<float>(2, .00f);
        node166->getVars().setVariable<float>(3, .00f);
        node166->setreentry(false);
        node166->setStopWhenFail(false);
        node166->setCheckFaction(PhaseNode_MoveNewPene::MoveNewPene_CheckFaction::Enemy);
        CALL_REGISTER_SKILL_NODE(10231, 166, node166)
    }
    if (noInit == true) {
        return node166;
    }
    auto node6 = GET_SKILL_NODE(6, PhaseNode_SpawnCollider);
    auto node274 = GET_SKILL_NODE(274, PhaseNode_GetInputRotation);
    if (node6 != nullptr) node166->setTarget(node6->getColliderID());
    if (node274 != nullptr) node166->getVars().setVariable<float>(2, node274->getAngle());
    return node166;
}
//--------------------------------------------------------------------------------
// DestroyCollider
//
REGISTER_REGISTER_SKILL_NODE(10231, 169) {
}

REGISTER_CREATE_SKILL_NODE(10231, 169) {
    auto node169 = GET_SKILL_NODE(169, PhaseNode_DestroyCollider);
    if (node169 == nullptr) {
        node169 = new PhaseNode_DestroyCollider(169, phase);
        CALL_REGISTER_SKILL_NODE(10231, 169, node169)
    }
    if (noInit == true) {
        return node169;
    }
    auto node6 = GET_SKILL_NODE(6, PhaseNode_SpawnCollider);
    if (node6 != nullptr) node169->setColliderID(node6->getColliderID());
    return node169;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10231, 263) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Disable>(PhaseNode_PlayAnimation::TRIGGER_DONE, 117, PhaseNode_Disable::FUNC_DO, &PhaseNode_Disable::Do);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_PlayAnimation::TRIGGER_DONE, 270, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10231, 263) {
    auto node263 = GET_SKILL_NODE(263, PhaseNode_PlayAnimation);
    if (node263 == nullptr) {
        node263 = new PhaseNode_PlayAnimation(263, phase);
        node263->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node263->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node263->setTarget(0U);
        node263->setAnimation("Skill1S1");
        node263->setParameter("");
        node263->setValue(false);
        CALL_REGISTER_SKILL_NODE(10231, 263, node263)
    }
    if (noInit == true) {
        return node263;
    }
    return node263;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10231, 270) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_PlaySound::TRIGGER_DONE, 379, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10231, 270) {
    auto node270 = GET_SKILL_NODE(270, PhaseNode_PlaySound);
    if (node270 == nullptr) {
        node270 = new PhaseNode_PlaySound(270, phase);
        node270->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node270->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node270->setSoundID("VO_Hero123_Skill_A");
        node270->setTarget(0U);
        node270->setUsePos(true);
        node270->setPosX(.00f);
        node270->setPosY(.00f);
        node270->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10231, 270, node270)
    }
    if (noInit == true) {
        return node270;
    }
    return node270;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(10231, 272) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_GetLocation::TRIGGER_DONE, 263, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10231, 272) {
    auto node272 = GET_SKILL_NODE(272, PhaseNode_GetLocation);
    if (node272 == nullptr) {
        node272 = new PhaseNode_GetLocation(272, phase);
        node272->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node272->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(10231, 272, node272)
    }
    if (noInit == true) {
        return node272;
    }
    return node272;
}
//--------------------------------------------------------------------------------
// GetInputRotation
//
REGISTER_REGISTER_SKILL_NODE(10231, 274) {
    pnode->resizeTrigger(PhaseNode_GetInputRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_GetInputRotation::TRIGGER_DONE, 272, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(10231, 274) {
    auto node274 = GET_SKILL_NODE(274, PhaseNode_GetInputRotation);
    if (node274 == nullptr) {
        node274 = new PhaseNode_GetInputRotation(274, phase);
        node274->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        CALL_REGISTER_SKILL_NODE(10231, 274, node274)
    }
    if (noInit == true) {
        return node274;
    }
    return node274;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(10231, 277) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ResetCD::TRIGGER_DONE, 367, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(10231, 277) {
    auto node277 = GET_SKILL_NODE(277, PhaseNode_ResetCD);
    if (node277 == nullptr) {
        node277 = new PhaseNode_ResetCD(277, phase);
        node277->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node277->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node277->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(10231, 277, node277)
    }
    if (noInit == true) {
        return node277;
    }
    return node277;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(10231, 338) {
}

REGISTER_CREATE_SKILL_NODE(10231, 338) {
    auto node338 = GET_SKILL_NODE(338, PhaseNode_EndPhase);
    if (node338 == nullptr) {
        node338 = new PhaseNode_EndPhase(338, phase);
        node338->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node338->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10231, 338, node338)
    }
    if (noInit == true) {
        return node338;
    }
    return node338;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10231, 357) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_Delay::TRIGGER_DONE, 338, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(10231, 357) {
    auto node357 = GET_SKILL_NODE(357, PhaseNode_Delay);
    if (node357 == nullptr) {
        node357 = new PhaseNode_Delay(357, phase);
        node357->setTime(.80f);
        CALL_REGISTER_SKILL_NODE(10231, 357, node357)
    }
    if (noInit == true) {
        return node357;
    }
    return node357;
}
//--------------------------------------------------------------------------------
// GetActorAttribute
//
REGISTER_REGISTER_SKILL_NODE(10231, 367) {
    pnode->resizeTrigger(PhaseNode_GetActorAttribute::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetInputRotation>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 274, PhaseNode_GetInputRotation::FUNC_DO, &PhaseNode_GetInputRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(10231, 367) {
    auto node367 = GET_SKILL_NODE(367, PhaseNode_GetActorAttribute);
    if (node367 == nullptr) {
        node367 = new PhaseNode_GetActorAttribute(367, phase);
        node367->setTarget(0U);
        node367->setType({});
        CALL_REGISTER_SKILL_NODE(10231, 367, node367)
    }
    if (noInit == true) {
        return node367;
    }
    return node367;
}
//--------------------------------------------------------------------------------
// AddSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10231, 374) {
    pnode->resizeTrigger(PhaseNode_AddSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnCollider>(PhaseNode_AddSkillBuff::TRIGGER_DONE, 6, PhaseNode_SpawnCollider::FUNC_DO, &PhaseNode_SpawnCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(10231, 374) {
    auto node374 = GET_SKILL_NODE(374, PhaseNode_AddSkillBuff);
    if (node374 == nullptr) {
        node374 = new PhaseNode_AddSkillBuff(374, phase);
        node374->setConfigID(102311);
        node374->setConfigIDs({});
        node374->setTarget(0U);
        node374->setAttribute({{}});
        CALL_REGISTER_SKILL_NODE(10231, 374, node374)
    }
    if (noInit == true) {
        return node374;
    }
    return node374;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10231, 376) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_IsInterruptType>(PhaseNode_Detect::TRIGGER_ON, 382, PhaseNode_IsInterruptType::FUNC_DO, &PhaseNode_IsInterruptType::Do);
}

REGISTER_CREATE_SKILL_NODE(10231, 376) {
    auto node376 = GET_SKILL_NODE(376, PhaseNode_Detect);
    if (node376 == nullptr) {
        node376 = new PhaseNode_Detect(376, phase);
        node376->setSelf(0U);
        node376->setEvent("daduan_001");
        node376->setType(PhaseNode_Detect::Detect_Type::Interrupt_Skill);
        node376->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10231, 376, node376)
    }
    if (noInit == true) {
        return node376;
    }
    return node376;
}
//--------------------------------------------------------------------------------
// SwitchToInt
//
REGISTER_REGISTER_SKILL_NODE(10231, 377) {
    pnode->resizeTrigger(4);
    pnode->regTrigger<PhaseNode_EndPhase>(1, 338, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
    pnode->regTrigger<PhaseNode_MoveNewPene>(1, 166, PhaseNode_MoveNewPene::FUNC_STOP, &PhaseNode_MoveNewPene::Stop);
}

REGISTER_CREATE_SKILL_NODE(10231, 377) {
    auto node377 = GET_SKILL_NODE(377, PhaseNode_SwitchToInt);
    if (node377 == nullptr) {
        node377 = new PhaseNode_SwitchToInt(377, phase);
        CALL_REGISTER_SKILL_NODE(10231, 377, node377)
    }
    if (noInit == true) {
        return node377;
    }
    auto variables = node377->getVariables();
    if (variables != nullptr) {
        node377->setSelection(variables->getVariable<int32_t>(Variable_10231_a102312));
    }
    return node377;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10231, 379) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_RaiseEvent::TRIGGER_DONE, 388, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10231, 379) {
    auto node379 = GET_SKILL_NODE(379, PhaseNode_RaiseEvent);
    if (node379 == nullptr) {
        node379 = new PhaseNode_RaiseEvent(379, phase);
        node379->setEvent("daduan_001");
        node379->setTarget(0U);
        node379->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node379->setTypeParams(0, 0);
        node379->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10231, 379, node379)
    }
    if (noInit == true) {
        return node379;
    }
    return node379;
}
//--------------------------------------------------------------------------------
// StartPreInput
//
REGISTER_REGISTER_SKILL_NODE(10231, 380) {
    pnode->resizeTrigger(PhaseNode_StartPreInput::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_StartPreInput::TRIGGER_DONE, 384, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_StartPreInput::TRIGGER_DONE, 142, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10231, 380) {
    auto node380 = GET_SKILL_NODE(380, PhaseNode_StartPreInput);
    if (node380 == nullptr) {
        node380 = new PhaseNode_StartPreInput(380, phase);
        node380->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node380->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node380->setDelayTime(.00f);
        CALL_REGISTER_SKILL_NODE(10231, 380, node380)
    }
    if (noInit == true) {
        return node380;
    }
    return node380;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(10231, 381) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_If::TRIGGER_TRUE, 383, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10231, 381) {
    auto node381 = GET_SKILL_NODE(381, PhaseNode_If);
    if (node381 == nullptr) {
        node381 = new PhaseNode_If(381, phase);
        CALL_REGISTER_SKILL_NODE(10231, 381, node381)
    }
    if (noInit == true) {
        return node381;
    }
    auto variables = node381->getVariables();
    if (variables != nullptr) {
        node381->setCondition(variables->getVariable<bool>(Variable_10231_InterruptAnimat));
    }
    return node381;
}
//--------------------------------------------------------------------------------
// IsInterruptType
//
REGISTER_REGISTER_SKILL_NODE(10231, 382) {
    pnode->resizeTrigger(PhaseNode_IsInterruptType::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SwitchToInt>(PhaseNode_IsInterruptType::TRIGGER_BUFF, 377, PhaseNode_SwitchToInt::FUNC_SWITCH, &PhaseNode_SwitchToInt::Switch);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_POSCHANGE, 381, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTAIM, 381, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTFIRE, 381, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTRELOAD, 381, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_USESKILL, 381, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(10231, 382) {
    auto node382 = GET_SKILL_NODE(382, PhaseNode_IsInterruptType);
    if (node382 == nullptr) {
        node382 = new PhaseNode_IsInterruptType(382, phase);
        node382->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node382->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10231, 382, node382)
    }
    if (noInit == true) {
        return node382;
    }
    auto node376 = GET_SKILL_NODE(376, PhaseNode_Detect);
    if (node376 != nullptr) node382->setType(node376->getVars().getVariable<int32_t>(2));
    return node382;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10231, 383) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_PlayAnimation::TRIGGER_DONE, 338, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(10231, 383) {
    auto node383 = GET_SKILL_NODE(383, PhaseNode_PlayAnimation);
    if (node383 == nullptr) {
        node383 = new PhaseNode_PlayAnimation(383, phase);
        node383->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node383->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node383->setTarget(0U);
        node383->setAnimation("Idle");
        node383->setParameter("");
        node383->setValue(false);
        CALL_REGISTER_SKILL_NODE(10231, 383, node383)
    }
    if (noInit == true) {
        return node383;
    }
    return node383;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10231, 384) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_Delay::TRIGGER_DONE, 387, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(10231, 384) {
    auto node384 = GET_SKILL_NODE(384, PhaseNode_Delay);
    if (node384 == nullptr) {
        node384 = new PhaseNode_Delay(384, phase);
        node384->setTime(.10f);
        CALL_REGISTER_SKILL_NODE(10231, 384, node384)
    }
    if (noInit == true) {
        return node384;
    }
    return node384;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(10231, 387) {
}

REGISTER_CREATE_SKILL_NODE(10231, 387) {
    auto node387 = GET_SKILL_NODE(387, PhaseNode_SetBool);
    if (node387 == nullptr) {
        node387 = new PhaseNode_SetBool(387, phase);
        node387->setName("InterruptAnimat");
        node387->setValue(true);
        CALL_REGISTER_SKILL_NODE(10231, 387, node387)
    }
    if (noInit == true) {
        return node387;
    }
    return node387;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10231, 388) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StartPreInput>(PhaseNode_RaiseEvent::TRIGGER_DONE, 380, PhaseNode_StartPreInput::FUNC_DO, &PhaseNode_StartPreInput::Do);
}

REGISTER_CREATE_SKILL_NODE(10231, 388) {
    auto node388 = GET_SKILL_NODE(388, PhaseNode_RaiseEvent);
    if (node388 == nullptr) {
        node388 = new PhaseNode_RaiseEvent(388, phase);
        node388->setEvent("Dead_001");
        node388->setTarget(0U);
        node388->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node388->setTypeParams(0, 0);
        node388->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10231, 388, node388)
    }
    if (noInit == true) {
        return node388;
    }
    return node388;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10231, 389) {
}

REGISTER_CREATE_SKILL_NODE(10231, 389) {
    auto node389 = GET_SKILL_NODE(389, PhaseNode_Detect);
    if (node389 == nullptr) {
        node389 = new PhaseNode_Detect(389, phase);
        node389->setSelf(0U);
        node389->setEvent("Dead_001");
        node389->setType(PhaseNode_Detect::Detect_Type::Actor_Dead);
        node389->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10231, 389, node389)
    }
    if (noInit == true) {
        return node389;
    }
    return node389;
}

//--------------------------------------------------------------------------------
// SkillCreator_10231
//
class SkillCreator_10231 : public SkillCreator {
public:
    SkillCreator_10231() {}
    virtual ~SkillCreator_10231() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_10231

//--------------------------------------------------------------------------------
// SkillPhase_10231
//
class SkillPhase_10231 : public SkillPhase {
public:
    SkillPhase_10231(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_10231() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(10231, 1) // StartPhase
        CASE_CREATE_SKILL_NODE(10231, 6) // SpawnCollider
        CASE_CREATE_SKILL_NODE(10231, 10) // AttachTo
        CASE_CREATE_SKILL_NODE(10231, 117) // Disable
        CASE_CREATE_SKILL_NODE(10231, 142) // PlaySound
        CASE_CREATE_SKILL_NODE(10231, 166) // MoveNewPene
        CASE_CREATE_SKILL_NODE(10231, 169) // DestroyCollider
        CASE_CREATE_SKILL_NODE(10231, 263) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10231, 270) // PlaySound
        CASE_CREATE_SKILL_NODE(10231, 272) // GetLocation
        CASE_CREATE_SKILL_NODE(10231, 274) // GetInputRotation
        CASE_CREATE_SKILL_NODE(10231, 277) // ResetCD
        CASE_CREATE_SKILL_NODE(10231, 338) // EndPhase
        CASE_CREATE_SKILL_NODE(10231, 357) // Delay
        CASE_CREATE_SKILL_NODE(10231, 367) // GetActorAttribute
        CASE_CREATE_SKILL_NODE(10231, 374) // AddSkillBuff
        CASE_CREATE_SKILL_NODE(10231, 376) // Detect
        CASE_CREATE_SKILL_NODE(10231, 377) // SwitchToInt
        CASE_CREATE_SKILL_NODE(10231, 379) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10231, 380) // StartPreInput
        CASE_CREATE_SKILL_NODE(10231, 381) // If
        CASE_CREATE_SKILL_NODE(10231, 382) // IsInterruptType
        CASE_CREATE_SKILL_NODE(10231, 383) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10231, 384) // Delay
        CASE_CREATE_SKILL_NODE(10231, 387) // SetBool
        CASE_CREATE_SKILL_NODE(10231, 388) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10231, 389) // Detect
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_10231

SkillLogic* SkillCreator_10231::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //设置变量
    Variable_10231_a102312 = logic->getVariables().setVariable<int32_t>("a102312", 1);
    Variable_10231_InterruptAnimat = logic->getVariables().setVariable<bool>("InterruptAnimat");
    //创建阶段phase
    auto phase = new SkillPhase_10231(1, logic, 2);
    //设置phase执行器
    phase->setRunPhaseNode(1, 1);
    phase->setDetectPhaseNode(2, 376);
    phase->setDetectPhaseNode(2, 389);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_10231::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
