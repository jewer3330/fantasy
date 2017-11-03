#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

#include "skill_psnode_actorfilternewpene.h"
#include "skill_psnode_addskillbuff.h"
#include "skill_psnode_addskillbuffs.h"
#include "skill_psnode_cameraxyzshake.h"
#include "skill_psnode_createtriggernewpene.h"
#include "skill_psnode_delay.h"
#include "skill_psnode_detect.h"
#include "skill_psnode_disable.h"
#include "skill_psnode_endphase.h"
#include "skill_psnode_getactorattribute.h"
#include "skill_psnode_getinputrotation.h"
#include "skill_psnode_getlocation.h"
#include "skill_psnode_if.h"
#include "skill_psnode_isinterrupttype.h"
#include "skill_psnode_linechecknewpene.h"
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
#include "skill_psnode_stopsound.h"
#include "skill_psnode_switchtoint.h"
#include "skill_psnode_triggercheck.h"
#include "skill_psnode_triggerupdate.h"

namespace pvp {

//变量声明
uint64_t Variable_10283_a102832 = 0;
uint64_t Variable_10283_InterruptAnimat = 0;
//--------------------------------------------------------------------------------
// StartPhase
//
REGISTER_REGISTER_SKILL_NODE(10283, 2) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_StartPhase::TRIGGER_START, 311, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(10283, 2) {
    auto node2 = GET_SKILL_NODE(2, PhaseNode_StartPhase);
    if (node2 == nullptr) {
        node2 = new PhaseNode_StartPhase(2, phase);
        CALL_REGISTER_SKILL_NODE(10283, 2, node2)
    }
    if (noInit == true) {
        return node2;
    }
    return node2;
}
//--------------------------------------------------------------------------------
// Disable
//
REGISTER_REGISTER_SKILL_NODE(10283, 4) {
    pnode->resizeTrigger(PhaseNode_Disable::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_Disable::TRIGGER_DONE, 10, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10283, 4) {
    auto node4 = GET_SKILL_NODE(4, PhaseNode_Disable);
    if (node4 == nullptr) {
        node4 = new PhaseNode_Disable(4, phase);
        node4->setTarget(0U);
        node4->setMove(true);
        node4->setSkill(true);
        node4->setShoot(true);
        node4->setTime(1.00f);
        node4->setRotate(true);
        CALL_REGISTER_SKILL_NODE(10283, 4, node4)
    }
    if (noInit == true) {
        return node4;
    }
    return node4;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10283, 10) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_Delay::TRIGGER_DONE, 200, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(10283, 10) {
    auto node10 = GET_SKILL_NODE(10, PhaseNode_Delay);
    if (node10 == nullptr) {
        node10 = new PhaseNode_Delay(10, phase);
        node10->setTime(.23f);
        CALL_REGISTER_SKILL_NODE(10283, 10, node10)
    }
    if (noInit == true) {
        return node10;
    }
    return node10;
}
//--------------------------------------------------------------------------------
// SpawnCollider
//
REGISTER_REGISTER_SKILL_NODE(10283, 22) {
    pnode->resizeTrigger(PhaseNode_SpawnCollider::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CameraXYZShake>(PhaseNode_SpawnCollider::TRIGGER_DONE, 310, PhaseNode_CameraXYZShake::FUNC_DO, &PhaseNode_CameraXYZShake::Do);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_SpawnCollider::TRIGGER_DONE, 316, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
}

REGISTER_CREATE_SKILL_NODE(10283, 22) {
    auto node22 = GET_SKILL_NODE(22, PhaseNode_SpawnCollider);
    if (node22 == nullptr) {
        node22 = new PhaseNode_SpawnCollider(22, phase);
        node22->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node22->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node22->setMesh("");
        node22->setMeshScale(.00f);
        node22->setEffectID(0);
        node22->setEffectScale(1.00f);
        node22->setType(PhaseNode_SpawnCollider::SpawnCollider_Type::Sector);
        node22->setTypeParams(0, 12.00f);
        node22->setTypeParams(1, 60.00f);
        node22->setTime(3.00f);
        node22->setPosZ(.00f);
        node22->setreentry(false);
        node22->setCheckPeneSound(false);
        CALL_REGISTER_SKILL_NODE(10283, 22, node22)
    }
    if (noInit == true) {
        return node22;
    }
    auto node306 = GET_SKILL_NODE(306, PhaseNode_GetLocation);
    auto node308 = GET_SKILL_NODE(308, PhaseNode_GetInputRotation);
    if (node306 != nullptr) node22->setPosX(node306->getX());
    if (node306 != nullptr) node22->setPosY(node306->getY());
    if (node308 != nullptr) node22->setRotation(node308->getAngle());
    return node22;
}
//--------------------------------------------------------------------------------
// TriggerUpdate
//
REGISTER_REGISTER_SKILL_NODE(10283, 36) {
}

REGISTER_CREATE_SKILL_NODE(10283, 36) {
    auto node36 = GET_SKILL_NODE(36, PhaseNode_TriggerUpdate);
    if (node36 == nullptr) {
        node36 = new PhaseNode_TriggerUpdate(36, phase);
        CALL_REGISTER_SKILL_NODE(10283, 36, node36)
    }
    if (noInit == true) {
        return node36;
    }
    return node36;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(10283, 49) {
}

REGISTER_CREATE_SKILL_NODE(10283, 49) {
    auto node49 = GET_SKILL_NODE(49, PhaseNode_EndPhase);
    if (node49 == nullptr) {
        node49 = new PhaseNode_EndPhase(49, phase);
        node49->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node49->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10283, 49, node49)
    }
    if (noInit == true) {
        return node49;
    }
    return node49;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(10283, 167) {
}

REGISTER_CREATE_SKILL_NODE(10283, 167) {
    auto node167 = GET_SKILL_NODE(167, PhaseNode_AddSkillBuffs);
    if (node167 == nullptr) {
        node167 = new PhaseNode_AddSkillBuffs(167, phase);
        node167->setConfigID({102831,102832,102834});
        CALL_REGISTER_SKILL_NODE(10283, 167, node167)
    }
    if (noInit == true) {
        return node167;
    }
    auto node304 = GET_SKILL_NODE(304, PhaseNode_LineCheckNewPene);
    auto node314 = GET_SKILL_NODE(314, PhaseNode_GetActorAttribute);
    if (node304 != nullptr) node167->setTarget(node304->getOutput());
    if (node314 != nullptr) node167->setAttribute(node314->getAttribute());
    return node167;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10283, 171) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_Delay::TRIGGER_DONE, 186, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10283, 171) {
    auto node171 = GET_SKILL_NODE(171, PhaseNode_Delay);
    if (node171 == nullptr) {
        node171 = new PhaseNode_Delay(171, phase);
        node171->setTime(3.06f);
        CALL_REGISTER_SKILL_NODE(10283, 171, node171)
    }
    if (noInit == true) {
        return node171;
    }
    return node171;
}
//--------------------------------------------------------------------------------
// AddSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10283, 183) {
    pnode->resizeTrigger(PhaseNode_AddSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnCollider>(PhaseNode_AddSkillBuff::TRIGGER_DONE, 22, PhaseNode_SpawnCollider::FUNC_DO, &PhaseNode_SpawnCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(10283, 183) {
    auto node183 = GET_SKILL_NODE(183, PhaseNode_AddSkillBuff);
    if (node183 == nullptr) {
        node183 = new PhaseNode_AddSkillBuff(183, phase);
        node183->setConfigID(102833);
        node183->setConfigIDs({});
        node183->setTarget(0U);
        node183->setAttribute({{}});
        CALL_REGISTER_SKILL_NODE(10283, 183, node183)
    }
    if (noInit == true) {
        return node183;
    }
    return node183;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10283, 186) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlayAnimation::TRIGGER_DONE, 192, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10283, 186) {
    auto node186 = GET_SKILL_NODE(186, PhaseNode_PlayAnimation);
    if (node186 == nullptr) {
        node186 = new PhaseNode_PlayAnimation(186, phase);
        node186->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node186->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node186->setTarget(0U);
        node186->setAnimation("Skill3S3");
        node186->setParameter("");
        node186->setValue(false);
        CALL_REGISTER_SKILL_NODE(10283, 186, node186)
    }
    if (noInit == true) {
        return node186;
    }
    return node186;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10283, 188) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuff>(PhaseNode_PlayAnimation::TRIGGER_DONE, 183, PhaseNode_AddSkillBuff::FUNC_ADD, &PhaseNode_AddSkillBuff::Add);
}

REGISTER_CREATE_SKILL_NODE(10283, 188) {
    auto node188 = GET_SKILL_NODE(188, PhaseNode_PlayAnimation);
    if (node188 == nullptr) {
        node188 = new PhaseNode_PlayAnimation(188, phase);
        node188->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node188->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node188->setTarget(0U);
        node188->setAnimation("Skill3S2");
        node188->setParameter("");
        node188->setValue(false);
        CALL_REGISTER_SKILL_NODE(10283, 188, node188)
    }
    if (noInit == true) {
        return node188;
    }
    return node188;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10283, 192) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_Delay::TRIGGER_DONE, 49, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(10283, 192) {
    auto node192 = GET_SKILL_NODE(192, PhaseNode_Delay);
    if (node192 == nullptr) {
        node192 = new PhaseNode_Delay(192, phase);
        node192->setTime(1.00f);
        CALL_REGISTER_SKILL_NODE(10283, 192, node192)
    }
    if (noInit == true) {
        return node192;
    }
    return node192;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(10283, 200) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_PlayEffect::TRIGGER_DONE, 230, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_PlayEffect::TRIGGER_DONE, 212, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10283, 200) {
    auto node200 = GET_SKILL_NODE(200, PhaseNode_PlayEffect);
    if (node200 == nullptr) {
        node200 = new PhaseNode_PlayEffect(200, phase);
        node200->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node200->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node200->setEffectID(102837);
        node200->setChangeColor(false);
        node200->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node200->getVars().reserve(3);
        node200->getVars().setVariable<float>(0, .00f);
        node200->getVars().setVariable<float>(1, .00f);
        node200->getVars().setVariable<float>(2, .00f);
        node200->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(10283, 200, node200)
    }
    if (noInit == true) {
        return node200;
    }
    auto node306 = GET_SKILL_NODE(306, PhaseNode_GetLocation);
    auto node308 = GET_SKILL_NODE(308, PhaseNode_GetInputRotation);
    if (node306 != nullptr) node200->getVars().setVariable<float>(0, node306->getX());
    if (node306 != nullptr) node200->getVars().setVariable<float>(1, node306->getY());
    if (node308 != nullptr) node200->setRotation(node308->getAngle());
    return node200;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10283, 212) {
}

REGISTER_CREATE_SKILL_NODE(10283, 212) {
    auto node212 = GET_SKILL_NODE(212, PhaseNode_PlaySound);
    if (node212 == nullptr) {
        node212 = new PhaseNode_PlaySound(212, phase);
        node212->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node212->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node212->setSoundID("SE_Hero107_SkillC_P1");
        node212->setTarget(0U);
        node212->setUsePos(false);
        node212->setPosX(.00f);
        node212->setPosY(.00f);
        node212->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10283, 212, node212)
    }
    if (noInit == true) {
        return node212;
    }
    return node212;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(10283, 230) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_PlayEffect::TRIGGER_DONE, 188, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10283, 230) {
    auto node230 = GET_SKILL_NODE(230, PhaseNode_PlayEffect);
    if (node230 == nullptr) {
        node230 = new PhaseNode_PlayEffect(230, phase);
        node230->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node230->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node230->setEffectID(102835);
        node230->setChangeColor(false);
        node230->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node230->getVars().reserve(3);
        node230->getVars().setVariable<float>(0, .00f);
        node230->getVars().setVariable<float>(1, .00f);
        node230->getVars().setVariable<float>(2, .00f);
        node230->setScale(.00f);
        CALL_REGISTER_SKILL_NODE(10283, 230, node230)
    }
    if (noInit == true) {
        return node230;
    }
    auto node306 = GET_SKILL_NODE(306, PhaseNode_GetLocation);
    auto node308 = GET_SKILL_NODE(308, PhaseNode_GetInputRotation);
    if (node306 != nullptr) node230->getVars().setVariable<float>(0, node306->getX());
    if (node306 != nullptr) node230->getVars().setVariable<float>(1, node306->getY());
    if (node308 != nullptr) node230->setRotation(node308->getAngle());
    return node230;
}
//--------------------------------------------------------------------------------
// StopEffect
//
REGISTER_REGISTER_SKILL_NODE(10283, 233) {
    pnode->resizeTrigger(PhaseNode_StopEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StopEffect>(PhaseNode_StopEffect::TRIGGER_DONE, 235, PhaseNode_StopEffect::FUNC_DO, &PhaseNode_StopEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(10283, 233) {
    auto node233 = GET_SKILL_NODE(233, PhaseNode_StopEffect);
    if (node233 == nullptr) {
        node233 = new PhaseNode_StopEffect(233, phase);
        node233->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node233->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node233->setEffectID(102835);
        CALL_REGISTER_SKILL_NODE(10283, 233, node233)
    }
    if (noInit == true) {
        return node233;
    }
    return node233;
}
//--------------------------------------------------------------------------------
// StopEffect
//
REGISTER_REGISTER_SKILL_NODE(10283, 235) {
    pnode->resizeTrigger(PhaseNode_StopEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CameraXYZShake>(PhaseNode_StopEffect::TRIGGER_DONE, 310, PhaseNode_CameraXYZShake::FUNC_STOP, &PhaseNode_CameraXYZShake::Stop);
    pnode->regTrigger<PhaseNode_StopSound>(PhaseNode_StopEffect::TRIGGER_DONE, 237, PhaseNode_StopSound::FUNC_STOP, &PhaseNode_StopSound::Stop);
}

REGISTER_CREATE_SKILL_NODE(10283, 235) {
    auto node235 = GET_SKILL_NODE(235, PhaseNode_StopEffect);
    if (node235 == nullptr) {
        node235 = new PhaseNode_StopEffect(235, phase);
        node235->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node235->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node235->setEffectID(102837);
        CALL_REGISTER_SKILL_NODE(10283, 235, node235)
    }
    if (noInit == true) {
        return node235;
    }
    return node235;
}
//--------------------------------------------------------------------------------
// StopSound
//
REGISTER_REGISTER_SKILL_NODE(10283, 237) {
    pnode->resizeTrigger(PhaseNode_StopSound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_StopSound::TRIGGER_DONE, 49, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(10283, 237) {
    auto node237 = GET_SKILL_NODE(237, PhaseNode_StopSound);
    if (node237 == nullptr) {
        node237 = new PhaseNode_StopSound(237, phase);
        node237->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node237->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node237->setSoundID("SE_Hero107_SkillC_P1");
        CALL_REGISTER_SKILL_NODE(10283, 237, node237)
    }
    if (noInit == true) {
        return node237;
    }
    return node237;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10283, 297) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StopEffect>(PhaseNode_Detect::TRIGGER_ON, 233, PhaseNode_StopEffect::FUNC_DO, &PhaseNode_StopEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(10283, 297) {
    auto node297 = GET_SKILL_NODE(297, PhaseNode_Detect);
    if (node297 == nullptr) {
        node297 = new PhaseNode_Detect(297, phase);
        node297->setSelf(0U);
        node297->setEvent("dead");
        node297->setType(PhaseNode_Detect::Detect_Type::Actor_Dead);
        node297->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10283, 297, node297)
    }
    if (noInit == true) {
        return node297;
    }
    return node297;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10283, 302) {
}

REGISTER_CREATE_SKILL_NODE(10283, 302) {
    auto node302 = GET_SKILL_NODE(302, PhaseNode_RaiseEvent);
    if (node302 == nullptr) {
        node302 = new PhaseNode_RaiseEvent(302, phase);
        node302->setEvent("dead");
        node302->setTarget(0U);
        node302->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node302->setTypeParams(0, 0);
        node302->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10283, 302, node302)
    }
    if (noInit == true) {
        return node302;
    }
    return node302;
}
//--------------------------------------------------------------------------------
// LineCheckNewPene
//
REGISTER_REGISTER_SKILL_NODE(10283, 304) {
    pnode->resizeTrigger(PhaseNode_LineCheckNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_LineCheckNewPene::TRIGGER_DONE, 167, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
}

REGISTER_CREATE_SKILL_NODE(10283, 304) {
    auto node304 = GET_SKILL_NODE(304, PhaseNode_LineCheckNewPene);
    if (node304 == nullptr) {
        node304 = new PhaseNode_LineCheckNewPene(304, phase);
        node304->setPeneProjectile(35);
        CALL_REGISTER_SKILL_NODE(10283, 304, node304)
    }
    if (noInit == true) {
        return node304;
    }
    auto node317 = GET_SKILL_NODE(317, PhaseNode_ActorFilterNewPene);
    auto node306 = GET_SKILL_NODE(306, PhaseNode_GetLocation);
    if (node317 != nullptr) node304->setTargets(node317->getOutput());
    if (node306 != nullptr) node304->setFromX(node306->getX());
    if (node306 != nullptr) node304->setFromY(node306->getY());
    return node304;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(10283, 306) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetInputRotation>(PhaseNode_GetLocation::TRIGGER_DONE, 308, PhaseNode_GetInputRotation::FUNC_DO, &PhaseNode_GetInputRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(10283, 306) {
    auto node306 = GET_SKILL_NODE(306, PhaseNode_GetLocation);
    if (node306 == nullptr) {
        node306 = new PhaseNode_GetLocation(306, phase);
        node306->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node306->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(10283, 306, node306)
    }
    if (noInit == true) {
        return node306;
    }
    return node306;
}
//--------------------------------------------------------------------------------
// GetInputRotation
//
REGISTER_REGISTER_SKILL_NODE(10283, 308) {
    pnode->resizeTrigger(PhaseNode_GetInputRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Disable>(PhaseNode_GetInputRotation::TRIGGER_DONE, 4, PhaseNode_Disable::FUNC_DO, &PhaseNode_Disable::Do);
}

REGISTER_CREATE_SKILL_NODE(10283, 308) {
    auto node308 = GET_SKILL_NODE(308, PhaseNode_GetInputRotation);
    if (node308 == nullptr) {
        node308 = new PhaseNode_GetInputRotation(308, phase);
        node308->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        CALL_REGISTER_SKILL_NODE(10283, 308, node308)
    }
    if (noInit == true) {
        return node308;
    }
    return node308;
}
//--------------------------------------------------------------------------------
// CameraXYZShake
//
REGISTER_REGISTER_SKILL_NODE(10283, 310) {
    pnode->resizeTrigger(PhaseNode_CameraXYZShake::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CameraXYZShake::TRIGGER_DONE, 171, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10283, 310) {
    auto node310 = GET_SKILL_NODE(310, PhaseNode_CameraXYZShake);
    if (node310 == nullptr) {
        node310 = new PhaseNode_CameraXYZShake(310, phase);
        node310->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node310->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node310->setShakeStyle(1);
        node310->setTarget(0U);
        node310->setX(.10f);
        node310->setY(.05f);
        node310->setZ(.10f);
        node310->setDuration(2.63f);
        node310->setTimes(35);
        CALL_REGISTER_SKILL_NODE(10283, 310, node310)
    }
    if (noInit == true) {
        return node310;
    }
    return node310;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(10283, 311) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_ResetCD::TRIGGER_DONE, 312, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10283, 311) {
    auto node311 = GET_SKILL_NODE(311, PhaseNode_ResetCD);
    if (node311 == nullptr) {
        node311 = new PhaseNode_ResetCD(311, phase);
        node311->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node311->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node311->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(10283, 311, node311)
    }
    if (noInit == true) {
        return node311;
    }
    return node311;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10283, 312) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_PlayAnimation::TRIGGER_DONE, 314, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(10283, 312) {
    auto node312 = GET_SKILL_NODE(312, PhaseNode_PlayAnimation);
    if (node312 == nullptr) {
        node312 = new PhaseNode_PlayAnimation(312, phase);
        node312->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node312->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node312->setTarget(0U);
        node312->setAnimation("Skill3S1");
        node312->setParameter("");
        node312->setValue(false);
        CALL_REGISTER_SKILL_NODE(10283, 312, node312)
    }
    if (noInit == true) {
        return node312;
    }
    return node312;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10283, 313) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_PlaySound::TRIGGER_DONE, 306, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_PlaySound::TRIGGER_DONE, 322, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10283, 313) {
    auto node313 = GET_SKILL_NODE(313, PhaseNode_PlaySound);
    if (node313 == nullptr) {
        node313 = new PhaseNode_PlaySound(313, phase);
        node313->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node313->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node313->setSoundID("VO_Hero107_Skill_C");
        node313->setTarget(0U);
        node313->setUsePos(false);
        node313->setPosX(.00f);
        node313->setPosY(.00f);
        node313->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10283, 313, node313)
    }
    if (noInit == true) {
        return node313;
    }
    return node313;
}
//--------------------------------------------------------------------------------
// GetActorAttribute
//
REGISTER_REGISTER_SKILL_NODE(10283, 314) {
    pnode->resizeTrigger(PhaseNode_GetActorAttribute::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 313, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10283, 314) {
    auto node314 = GET_SKILL_NODE(314, PhaseNode_GetActorAttribute);
    if (node314 == nullptr) {
        node314 = new PhaseNode_GetActorAttribute(314, phase);
        node314->setTarget(0U);
        node314->setType({});
        CALL_REGISTER_SKILL_NODE(10283, 314, node314)
    }
    if (noInit == true) {
        return node314;
    }
    return node314;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(10283, 315) {
}

REGISTER_CREATE_SKILL_NODE(10283, 315) {
    auto node315 = GET_SKILL_NODE(315, PhaseNode_TriggerCheck);
    if (node315 == nullptr) {
        node315 = new PhaseNode_TriggerCheck(315, phase);
        auto node36 = GET_SKILL_NODE(36, PhaseNode_TriggerUpdate);
        if (node36 != nullptr) node36->addTriggerCheck(node315);
        
        CALL_REGISTER_SKILL_NODE(10283, 315, node315)
    }
    if (noInit == true) {
        return node315;
    }
    auto node316 = GET_SKILL_NODE(316, PhaseNode_CreateTriggerNewPene);
    if (node316 != nullptr) node315->setTrigger(0, node316->getTriggerID());
    return node315;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(10283, 316) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 315, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 317, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(10283, 316) {
    auto node316 = GET_SKILL_NODE(316, PhaseNode_CreateTriggerNewPene);
    if (node316 == nullptr) {
        node316 = new PhaseNode_CreateTriggerNewPene(316, phase);
        node316->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::Tick);
        node316->setTypeParams(0, .25f);
        node316->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node316->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Enemy);
        node316->setOnHero(true);
        node316->setOnMinion(true);
        node316->setOnDestruct(true);
        node316->setOnShield(true);
        CALL_REGISTER_SKILL_NODE(10283, 316, node316)
    }
    if (noInit == true) {
        return node316;
    }
    auto node22 = GET_SKILL_NODE(22, PhaseNode_SpawnCollider);
    if (node22 != nullptr) node316->setColliderID(node22->getColliderID());
    return node316;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(10283, 317) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_LineCheckNewPene>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 304, PhaseNode_LineCheckNewPene::FUNC_DO, &PhaseNode_LineCheckNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(10283, 317) {
    auto node317 = GET_SKILL_NODE(317, PhaseNode_ActorFilterNewPene);
    if (node317 == nullptr) {
        node317 = new PhaseNode_ActorFilterNewPene(317, phase);
        node317->setHero(true);
        node317->setMinion(true);
        node317->setDestruct(true);
        node317->setShield(true);
        node317->setTotalCount(0);
        node317->setPerCount(0);
        CALL_REGISTER_SKILL_NODE(10283, 317, node317)
    }
    if (noInit == true) {
        return node317;
    }
    auto node316 = GET_SKILL_NODE(316, PhaseNode_CreateTriggerNewPene);
    if (node316 != nullptr) node317->setInput(node316->getOther());
    return node317;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10283, 319) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_IsInterruptType>(PhaseNode_Detect::TRIGGER_ON, 325, PhaseNode_IsInterruptType::FUNC_DO, &PhaseNode_IsInterruptType::Do);
}

REGISTER_CREATE_SKILL_NODE(10283, 319) {
    auto node319 = GET_SKILL_NODE(319, PhaseNode_Detect);
    if (node319 == nullptr) {
        node319 = new PhaseNode_Detect(319, phase);
        node319->setSelf(0U);
        node319->setEvent("daduan_001");
        node319->setType(PhaseNode_Detect::Detect_Type::Interrupt_Skill);
        node319->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10283, 319, node319)
    }
    if (noInit == true) {
        return node319;
    }
    return node319;
}
//--------------------------------------------------------------------------------
// SwitchToInt
//
REGISTER_REGISTER_SKILL_NODE(10283, 320) {
    pnode->resizeTrigger(4);
    pnode->regTrigger<PhaseNode_StopEffect>(1, 233, PhaseNode_StopEffect::FUNC_DO, &PhaseNode_StopEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(10283, 320) {
    auto node320 = GET_SKILL_NODE(320, PhaseNode_SwitchToInt);
    if (node320 == nullptr) {
        node320 = new PhaseNode_SwitchToInt(320, phase);
        CALL_REGISTER_SKILL_NODE(10283, 320, node320)
    }
    if (noInit == true) {
        return node320;
    }
    auto variables = node320->getVariables();
    if (variables != nullptr) {
        node320->setSelection(variables->getVariable<int32_t>(Variable_10283_a102832));
    }
    return node320;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10283, 322) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_RaiseEvent::TRIGGER_DONE, 331, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10283, 322) {
    auto node322 = GET_SKILL_NODE(322, PhaseNode_RaiseEvent);
    if (node322 == nullptr) {
        node322 = new PhaseNode_RaiseEvent(322, phase);
        node322->setEvent("daduan_001");
        node322->setTarget(0U);
        node322->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node322->setTypeParams(0, 0);
        node322->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10283, 322, node322)
    }
    if (noInit == true) {
        return node322;
    }
    return node322;
}
//--------------------------------------------------------------------------------
// StartPreInput
//
REGISTER_REGISTER_SKILL_NODE(10283, 323) {
    pnode->resizeTrigger(PhaseNode_StartPreInput::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_StartPreInput::TRIGGER_DONE, 327, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_StartPreInput::TRIGGER_DONE, 302, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10283, 323) {
    auto node323 = GET_SKILL_NODE(323, PhaseNode_StartPreInput);
    if (node323 == nullptr) {
        node323 = new PhaseNode_StartPreInput(323, phase);
        node323->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node323->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node323->setDelayTime(1.00f);
        CALL_REGISTER_SKILL_NODE(10283, 323, node323)
    }
    if (noInit == true) {
        return node323;
    }
    return node323;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(10283, 324) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_If::TRIGGER_TRUE, 326, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10283, 324) {
    auto node324 = GET_SKILL_NODE(324, PhaseNode_If);
    if (node324 == nullptr) {
        node324 = new PhaseNode_If(324, phase);
        CALL_REGISTER_SKILL_NODE(10283, 324, node324)
    }
    if (noInit == true) {
        return node324;
    }
    auto variables = node324->getVariables();
    if (variables != nullptr) {
        node324->setCondition(variables->getVariable<bool>(Variable_10283_InterruptAnimat));
    }
    return node324;
}
//--------------------------------------------------------------------------------
// IsInterruptType
//
REGISTER_REGISTER_SKILL_NODE(10283, 325) {
    pnode->resizeTrigger(PhaseNode_IsInterruptType::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SwitchToInt>(PhaseNode_IsInterruptType::TRIGGER_BUFF, 320, PhaseNode_SwitchToInt::FUNC_SWITCH, &PhaseNode_SwitchToInt::Switch);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_POSCHANGE, 324, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTAIM, 324, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTFIRE, 324, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTRELOAD, 324, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_USESKILL, 324, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(10283, 325) {
    auto node325 = GET_SKILL_NODE(325, PhaseNode_IsInterruptType);
    if (node325 == nullptr) {
        node325 = new PhaseNode_IsInterruptType(325, phase);
        node325->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node325->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10283, 325, node325)
    }
    if (noInit == true) {
        return node325;
    }
    auto node319 = GET_SKILL_NODE(319, PhaseNode_Detect);
    if (node319 != nullptr) node325->setType(node319->getVars().getVariable<int32_t>(2));
    return node325;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10283, 326) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StopEffect>(PhaseNode_PlayAnimation::TRIGGER_DONE, 233, PhaseNode_StopEffect::FUNC_DO, &PhaseNode_StopEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(10283, 326) {
    auto node326 = GET_SKILL_NODE(326, PhaseNode_PlayAnimation);
    if (node326 == nullptr) {
        node326 = new PhaseNode_PlayAnimation(326, phase);
        node326->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node326->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node326->setTarget(0U);
        node326->setAnimation("Idle");
        node326->setParameter("");
        node326->setValue(false);
        CALL_REGISTER_SKILL_NODE(10283, 326, node326)
    }
    if (noInit == true) {
        return node326;
    }
    return node326;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10283, 327) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_Delay::TRIGGER_DONE, 330, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(10283, 327) {
    auto node327 = GET_SKILL_NODE(327, PhaseNode_Delay);
    if (node327 == nullptr) {
        node327 = new PhaseNode_Delay(327, phase);
        node327->setTime(1.00f);
        CALL_REGISTER_SKILL_NODE(10283, 327, node327)
    }
    if (noInit == true) {
        return node327;
    }
    return node327;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(10283, 330) {
}

REGISTER_CREATE_SKILL_NODE(10283, 330) {
    auto node330 = GET_SKILL_NODE(330, PhaseNode_SetBool);
    if (node330 == nullptr) {
        node330 = new PhaseNode_SetBool(330, phase);
        node330->setName("InterruptAnimat");
        node330->setValue(true);
        CALL_REGISTER_SKILL_NODE(10283, 330, node330)
    }
    if (noInit == true) {
        return node330;
    }
    return node330;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10283, 331) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StartPreInput>(PhaseNode_RaiseEvent::TRIGGER_DONE, 323, PhaseNode_StartPreInput::FUNC_DO, &PhaseNode_StartPreInput::Do);
}

REGISTER_CREATE_SKILL_NODE(10283, 331) {
    auto node331 = GET_SKILL_NODE(331, PhaseNode_RaiseEvent);
    if (node331 == nullptr) {
        node331 = new PhaseNode_RaiseEvent(331, phase);
        node331->setEvent("Dead_001");
        node331->setTarget(0U);
        node331->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node331->setTypeParams(0, 0);
        node331->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10283, 331, node331)
    }
    if (noInit == true) {
        return node331;
    }
    return node331;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10283, 332) {
}

REGISTER_CREATE_SKILL_NODE(10283, 332) {
    auto node332 = GET_SKILL_NODE(332, PhaseNode_Detect);
    if (node332 == nullptr) {
        node332 = new PhaseNode_Detect(332, phase);
        node332->setSelf(0U);
        node332->setEvent("Dead_001");
        node332->setType(PhaseNode_Detect::Detect_Type::Actor_Dead);
        node332->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10283, 332, node332)
    }
    if (noInit == true) {
        return node332;
    }
    return node332;
}

//--------------------------------------------------------------------------------
// SkillCreator_10283
//
class SkillCreator_10283 : public SkillCreator {
public:
    SkillCreator_10283() {}
    virtual ~SkillCreator_10283() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_10283

//--------------------------------------------------------------------------------
// SkillPhase_10283
//
class SkillPhase_10283 : public SkillPhase {
public:
    SkillPhase_10283(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_10283() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(10283, 2) // StartPhase
        CASE_CREATE_SKILL_NODE(10283, 4) // Disable
        CASE_CREATE_SKILL_NODE(10283, 10) // Delay
        CASE_CREATE_SKILL_NODE(10283, 22) // SpawnCollider
        CASE_CREATE_SKILL_NODE(10283, 36) // TriggerUpdate
        CASE_CREATE_SKILL_NODE(10283, 49) // EndPhase
        CASE_CREATE_SKILL_NODE(10283, 167) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(10283, 171) // Delay
        CASE_CREATE_SKILL_NODE(10283, 183) // AddSkillBuff
        CASE_CREATE_SKILL_NODE(10283, 186) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10283, 188) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10283, 192) // Delay
        CASE_CREATE_SKILL_NODE(10283, 200) // PlayEffect
        CASE_CREATE_SKILL_NODE(10283, 212) // PlaySound
        CASE_CREATE_SKILL_NODE(10283, 230) // PlayEffect
        CASE_CREATE_SKILL_NODE(10283, 233) // StopEffect
        CASE_CREATE_SKILL_NODE(10283, 235) // StopEffect
        CASE_CREATE_SKILL_NODE(10283, 237) // StopSound
        CASE_CREATE_SKILL_NODE(10283, 297) // Detect
        CASE_CREATE_SKILL_NODE(10283, 302) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10283, 304) // LineCheckNewPene
        CASE_CREATE_SKILL_NODE(10283, 306) // GetLocation
        CASE_CREATE_SKILL_NODE(10283, 308) // GetInputRotation
        CASE_CREATE_SKILL_NODE(10283, 310) // CameraXYZShake
        CASE_CREATE_SKILL_NODE(10283, 311) // ResetCD
        CASE_CREATE_SKILL_NODE(10283, 312) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10283, 313) // PlaySound
        CASE_CREATE_SKILL_NODE(10283, 314) // GetActorAttribute
        CASE_CREATE_SKILL_NODE(10283, 315) // TriggerCheck
        CASE_CREATE_SKILL_NODE(10283, 316) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(10283, 317) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(10283, 319) // Detect
        CASE_CREATE_SKILL_NODE(10283, 320) // SwitchToInt
        CASE_CREATE_SKILL_NODE(10283, 322) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10283, 323) // StartPreInput
        CASE_CREATE_SKILL_NODE(10283, 324) // If
        CASE_CREATE_SKILL_NODE(10283, 325) // IsInterruptType
        CASE_CREATE_SKILL_NODE(10283, 326) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10283, 327) // Delay
        CASE_CREATE_SKILL_NODE(10283, 330) // SetBool
        CASE_CREATE_SKILL_NODE(10283, 331) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10283, 332) // Detect
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_10283

SkillLogic* SkillCreator_10283::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //设置变量
    Variable_10283_a102832 = logic->getVariables().setVariable<int32_t>("a102832", 1);
    Variable_10283_InterruptAnimat = logic->getVariables().setVariable<bool>("InterruptAnimat");
    //创建阶段phase
    auto phase = new SkillPhase_10283(1, logic, 3);
    //设置phase执行器
    phase->setRunPhaseNode(1, 2);
    phase->setRunPhaseNode(2, 36);
    phase->setDetectPhaseNode(3, 297);
    phase->setDetectPhaseNode(3, 319);
    phase->setDetectPhaseNode(3, 332);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_10283::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
