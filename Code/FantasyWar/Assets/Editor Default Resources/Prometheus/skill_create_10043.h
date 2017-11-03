#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

#include "skill_psnode_addskillbuffs.h"
#include "skill_psnode_areacollisionnewpene.h"
#include "skill_psnode_cameraxyzshake.h"
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
#include "skill_psnode_startphase.h"
#include "skill_psnode_startpreinput.h"
#include "skill_psnode_stopeffect.h"
#include "skill_psnode_switchtoint.h"
#include "skill_psnode_triggerupdate.h"

namespace pvp {

//变量声明
uint64_t Variable_10043_a100432 = 0;
uint64_t Variable_10043_InterruptAnimat = 0;
//--------------------------------------------------------------------------------
// StartPhase
//
REGISTER_REGISTER_SKILL_NODE(10043, 1) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_StartPhase::TRIGGER_START, 331, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(10043, 1) {
    auto node1 = GET_SKILL_NODE(1, PhaseNode_StartPhase);
    if (node1 == nullptr) {
        node1 = new PhaseNode_StartPhase(1, phase);
        CALL_REGISTER_SKILL_NODE(10043, 1, node1)
    }
    if (noInit == true) {
        return node1;
    }
    return node1;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10043, 14) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AreaCollisionNewPene>(PhaseNode_Delay::TRIGGER_DONE, 324, PhaseNode_AreaCollisionNewPene::FUNC_DO, &PhaseNode_AreaCollisionNewPene::Do);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_Delay::TRIGGER_DONE, 144, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10043, 14) {
    auto node14 = GET_SKILL_NODE(14, PhaseNode_Delay);
    if (node14 == nullptr) {
        node14 = new PhaseNode_Delay(14, phase);
        node14->setTime(.42f);
        CALL_REGISTER_SKILL_NODE(10043, 14, node14)
    }
    if (noInit == true) {
        return node14;
    }
    return node14;
}
//--------------------------------------------------------------------------------
// TriggerUpdate
//
REGISTER_REGISTER_SKILL_NODE(10043, 18) {
}

REGISTER_CREATE_SKILL_NODE(10043, 18) {
    auto node18 = GET_SKILL_NODE(18, PhaseNode_TriggerUpdate);
    if (node18 == nullptr) {
        node18 = new PhaseNode_TriggerUpdate(18, phase);
        CALL_REGISTER_SKILL_NODE(10043, 18, node18)
    }
    if (noInit == true) {
        return node18;
    }
    return node18;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(10043, 37) {
}

REGISTER_CREATE_SKILL_NODE(10043, 37) {
    auto node37 = GET_SKILL_NODE(37, PhaseNode_EndPhase);
    if (node37 == nullptr) {
        node37 = new PhaseNode_EndPhase(37, phase);
        node37->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node37->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10043, 37, node37)
    }
    if (noInit == true) {
        return node37;
    }
    return node37;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10043, 64) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_Delay::TRIGGER_DONE, 37, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(10043, 64) {
    auto node64 = GET_SKILL_NODE(64, PhaseNode_Delay);
    if (node64 == nullptr) {
        node64 = new PhaseNode_Delay(64, phase);
        node64->setTime(.68f);
        CALL_REGISTER_SKILL_NODE(10043, 64, node64)
    }
    if (noInit == true) {
        return node64;
    }
    return node64;
}
//--------------------------------------------------------------------------------
// Disable
//
REGISTER_REGISTER_SKILL_NODE(10043, 122) {
    pnode->resizeTrigger(PhaseNode_Disable::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_Disable::TRIGGER_DONE, 339, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10043, 122) {
    auto node122 = GET_SKILL_NODE(122, PhaseNode_Disable);
    if (node122 == nullptr) {
        node122 = new PhaseNode_Disable(122, phase);
        node122->setTarget(0U);
        node122->setMove(true);
        node122->setSkill(true);
        node122->setShoot(true);
        node122->setTime(.90f);
        node122->setRotate(true);
        CALL_REGISTER_SKILL_NODE(10043, 122, node122)
    }
    if (noInit == true) {
        return node122;
    }
    return node122;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10043, 139) {
}

REGISTER_CREATE_SKILL_NODE(10043, 139) {
    auto node139 = GET_SKILL_NODE(139, PhaseNode_PlaySound);
    if (node139 == nullptr) {
        node139 = new PhaseNode_PlaySound(139, phase);
        node139->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node139->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node139->setSoundID("SE_Hero101_Skill_C_P1");
        node139->setTarget(0U);
        node139->setUsePos(false);
        node139->setPosX(.00f);
        node139->setPosY(.00f);
        node139->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10043, 139, node139)
    }
    if (noInit == true) {
        return node139;
    }
    return node139;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10043, 144) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CameraXYZShake>(PhaseNode_PlaySound::TRIGGER_DONE, 318, PhaseNode_CameraXYZShake::FUNC_DO, &PhaseNode_CameraXYZShake::Do);
}

REGISTER_CREATE_SKILL_NODE(10043, 144) {
    auto node144 = GET_SKILL_NODE(144, PhaseNode_PlaySound);
    if (node144 == nullptr) {
        node144 = new PhaseNode_PlaySound(144, phase);
        node144->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node144->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node144->setSoundID("SE_Hero101_Skill_C_P2");
        node144->setTarget(0U);
        node144->setUsePos(false);
        node144->setPosX(.00f);
        node144->setPosY(.00f);
        node144->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10043, 144, node144)
    }
    if (noInit == true) {
        return node144;
    }
    return node144;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(10043, 280) {
}

REGISTER_CREATE_SKILL_NODE(10043, 280) {
    auto node280 = GET_SKILL_NODE(280, PhaseNode_AddSkillBuffs);
    if (node280 == nullptr) {
        node280 = new PhaseNode_AddSkillBuffs(280, phase);
        node280->setConfigID({100431,100432});
        CALL_REGISTER_SKILL_NODE(10043, 280, node280)
    }
    if (noInit == true) {
        return node280;
    }
    auto node307 = GET_SKILL_NODE(307, PhaseNode_LineCheckNewPene);
    auto node334 = GET_SKILL_NODE(334, PhaseNode_GetActorAttribute);
    if (node307 != nullptr) node280->setTarget(node307->getOutput());
    if (node334 != nullptr) node280->setAttribute(node334->getAttribute());
    return node280;
}
//--------------------------------------------------------------------------------
// LineCheckNewPene
//
REGISTER_REGISTER_SKILL_NODE(10043, 307) {
    pnode->resizeTrigger(PhaseNode_LineCheckNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_LineCheckNewPene::TRIGGER_DONE, 280, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
}

REGISTER_CREATE_SKILL_NODE(10043, 307) {
    auto node307 = GET_SKILL_NODE(307, PhaseNode_LineCheckNewPene);
    if (node307 == nullptr) {
        node307 = new PhaseNode_LineCheckNewPene(307, phase);
        node307->setPeneProjectile(15);
        CALL_REGISTER_SKILL_NODE(10043, 307, node307)
    }
    if (noInit == true) {
        return node307;
    }
    auto node324 = GET_SKILL_NODE(324, PhaseNode_AreaCollisionNewPene);
    auto node320 = GET_SKILL_NODE(320, PhaseNode_GetLocation);
    if (node324 != nullptr) node307->setTargets(node324->getColliders());
    if (node320 != nullptr) node307->setFromX(node320->getX());
    if (node320 != nullptr) node307->setFromY(node320->getY());
    return node307;
}
//--------------------------------------------------------------------------------
// CameraXYZShake
//
REGISTER_REGISTER_SKILL_NODE(10043, 318) {
    pnode->resizeTrigger(PhaseNode_CameraXYZShake::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CameraXYZShake::TRIGGER_DONE, 64, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10043, 318) {
    auto node318 = GET_SKILL_NODE(318, PhaseNode_CameraXYZShake);
    if (node318 == nullptr) {
        node318 = new PhaseNode_CameraXYZShake(318, phase);
        node318->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node318->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node318->setShakeStyle(1);
        node318->setTarget(0U);
        node318->setX(.30f);
        node318->setY(.30f);
        node318->setZ(.30f);
        node318->setDuration(.25f);
        node318->setTimes(3);
        CALL_REGISTER_SKILL_NODE(10043, 318, node318)
    }
    if (noInit == true) {
        return node318;
    }
    return node318;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(10043, 320) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetInputRotation>(PhaseNode_GetLocation::TRIGGER_DONE, 322, PhaseNode_GetInputRotation::FUNC_DO, &PhaseNode_GetInputRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(10043, 320) {
    auto node320 = GET_SKILL_NODE(320, PhaseNode_GetLocation);
    if (node320 == nullptr) {
        node320 = new PhaseNode_GetLocation(320, phase);
        node320->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node320->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(10043, 320, node320)
    }
    if (noInit == true) {
        return node320;
    }
    return node320;
}
//--------------------------------------------------------------------------------
// GetInputRotation
//
REGISTER_REGISTER_SKILL_NODE(10043, 322) {
    pnode->resizeTrigger(PhaseNode_GetInputRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Disable>(PhaseNode_GetInputRotation::TRIGGER_DONE, 122, PhaseNode_Disable::FUNC_DO, &PhaseNode_Disable::Do);
}

REGISTER_CREATE_SKILL_NODE(10043, 322) {
    auto node322 = GET_SKILL_NODE(322, PhaseNode_GetInputRotation);
    if (node322 == nullptr) {
        node322 = new PhaseNode_GetInputRotation(322, phase);
        node322->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        CALL_REGISTER_SKILL_NODE(10043, 322, node322)
    }
    if (noInit == true) {
        return node322;
    }
    return node322;
}
//--------------------------------------------------------------------------------
// AreaCollisionNewPene
//
REGISTER_REGISTER_SKILL_NODE(10043, 324) {
    pnode->resizeTrigger(PhaseNode_AreaCollisionNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_LineCheckNewPene>(PhaseNode_AreaCollisionNewPene::TRIGGER_DONE, 307, PhaseNode_LineCheckNewPene::FUNC_DO, &PhaseNode_LineCheckNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(10043, 324) {
    auto node324 = GET_SKILL_NODE(324, PhaseNode_AreaCollisionNewPene);
    if (node324 == nullptr) {
        node324 = new PhaseNode_AreaCollisionNewPene(324, phase);
        node324->setState(PhaseNode_AreaCollisionNewPene::AreaCollisionNewPene_State::Alive);
        node324->setFaction(PhaseNode_AreaCollisionNewPene::AreaCollisionNewPene_Faction::Enemy);
        node324->setOnHero(true);
        node324->setOnMinion(true);
        node324->setOnDestruct(true);
        node324->setOnShield(false);
        node324->setType(PhaseNode_AreaCollisionNewPene::AreaCollisionNewPene_Type::Rect);
        node324->setTypeParams(0, 12.00f);
        node324->setTypeParams(1, 8.00f);
        node324->setPositionZ(.00f);
        CALL_REGISTER_SKILL_NODE(10043, 324, node324)
    }
    if (noInit == true) {
        return node324;
    }
    auto node320 = GET_SKILL_NODE(320, PhaseNode_GetLocation);
    auto node322 = GET_SKILL_NODE(322, PhaseNode_GetInputRotation);
    if (node320 != nullptr) node324->setPositionX(node320->getX());
    if (node320 != nullptr) node324->setPositionY(node320->getY());
    if (node322 != nullptr) node324->setRotation(node322->getAngle());
    return node324;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(10043, 326) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_PlayEffect::TRIGGER_DONE, 330, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(10043, 326) {
    auto node326 = GET_SKILL_NODE(326, PhaseNode_PlayEffect);
    if (node326 == nullptr) {
        node326 = new PhaseNode_PlayEffect(326, phase);
        node326->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node326->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node326->setEffectID(100431);
        node326->setChangeColor(false);
        node326->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node326->getVars().reserve(3);
        node326->getVars().setVariable<float>(0, .00f);
        node326->getVars().setVariable<float>(1, .00f);
        node326->getVars().setVariable<float>(2, .00f);
        node326->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(10043, 326, node326)
    }
    if (noInit == true) {
        return node326;
    }
    auto node320 = GET_SKILL_NODE(320, PhaseNode_GetLocation);
    auto node322 = GET_SKILL_NODE(322, PhaseNode_GetInputRotation);
    if (node320 != nullptr) node326->getVars().setVariable<float>(0, node320->getX());
    if (node320 != nullptr) node326->getVars().setVariable<float>(1, node320->getY());
    if (node322 != nullptr) node326->setRotation(node322->getAngle());
    return node326;
}
//--------------------------------------------------------------------------------
// StopEffect
//
REGISTER_REGISTER_SKILL_NODE(10043, 328) {
    pnode->resizeTrigger(PhaseNode_StopEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_StopEffect::TRIGGER_DONE, 37, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(10043, 328) {
    auto node328 = GET_SKILL_NODE(328, PhaseNode_StopEffect);
    if (node328 == nullptr) {
        node328 = new PhaseNode_StopEffect(328, phase);
        node328->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node328->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node328->setEffectID(100431);
        CALL_REGISTER_SKILL_NODE(10043, 328, node328)
    }
    if (noInit == true) {
        return node328;
    }
    return node328;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(10043, 330) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlayEffect::TRIGGER_DONE, 14, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10043, 330) {
    auto node330 = GET_SKILL_NODE(330, PhaseNode_PlayEffect);
    if (node330 == nullptr) {
        node330 = new PhaseNode_PlayEffect(330, phase);
        node330->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node330->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node330->setEffectID(100432);
        node330->setChangeColor(false);
        node330->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node330->getVars().reserve(3);
        node330->getVars().setVariable<float>(0, .00f);
        node330->getVars().setVariable<float>(1, .00f);
        node330->getVars().setVariable<float>(2, .00f);
        node330->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(10043, 330, node330)
    }
    if (noInit == true) {
        return node330;
    }
    auto node320 = GET_SKILL_NODE(320, PhaseNode_GetLocation);
    auto node322 = GET_SKILL_NODE(322, PhaseNode_GetInputRotation);
    if (node320 != nullptr) node330->getVars().setVariable<float>(0, node320->getX());
    if (node320 != nullptr) node330->getVars().setVariable<float>(1, node320->getY());
    if (node322 != nullptr) node330->setRotation(node322->getAngle());
    return node330;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(10043, 331) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_ResetCD::TRIGGER_DONE, 332, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10043, 331) {
    auto node331 = GET_SKILL_NODE(331, PhaseNode_ResetCD);
    if (node331 == nullptr) {
        node331 = new PhaseNode_ResetCD(331, phase);
        node331->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node331->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node331->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(10043, 331, node331)
    }
    if (noInit == true) {
        return node331;
    }
    return node331;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10043, 332) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_PlayAnimation::TRIGGER_DONE, 334, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(10043, 332) {
    auto node332 = GET_SKILL_NODE(332, PhaseNode_PlayAnimation);
    if (node332 == nullptr) {
        node332 = new PhaseNode_PlayAnimation(332, phase);
        node332->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node332->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node332->setTarget(0U);
        node332->setAnimation("Skill3S1");
        node332->setParameter("");
        node332->setValue(false);
        CALL_REGISTER_SKILL_NODE(10043, 332, node332)
    }
    if (noInit == true) {
        return node332;
    }
    return node332;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10043, 333) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_PlaySound::TRIGGER_DONE, 320, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_PlaySound::TRIGGER_DONE, 139, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10043, 333) {
    auto node333 = GET_SKILL_NODE(333, PhaseNode_PlaySound);
    if (node333 == nullptr) {
        node333 = new PhaseNode_PlaySound(333, phase);
        node333->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node333->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node333->setSoundID("VO_Hero101_Skill_C");
        node333->setTarget(0U);
        node333->setUsePos(false);
        node333->setPosX(.00f);
        node333->setPosY(.00f);
        node333->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10043, 333, node333)
    }
    if (noInit == true) {
        return node333;
    }
    return node333;
}
//--------------------------------------------------------------------------------
// GetActorAttribute
//
REGISTER_REGISTER_SKILL_NODE(10043, 334) {
    pnode->resizeTrigger(PhaseNode_GetActorAttribute::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 333, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10043, 334) {
    auto node334 = GET_SKILL_NODE(334, PhaseNode_GetActorAttribute);
    if (node334 == nullptr) {
        node334 = new PhaseNode_GetActorAttribute(334, phase);
        node334->setTarget(0U);
        node334->setType({});
        CALL_REGISTER_SKILL_NODE(10043, 334, node334)
    }
    if (noInit == true) {
        return node334;
    }
    return node334;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10043, 336) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_IsInterruptType>(PhaseNode_Detect::TRIGGER_ON, 342, PhaseNode_IsInterruptType::FUNC_DO, &PhaseNode_IsInterruptType::Do);
}

REGISTER_CREATE_SKILL_NODE(10043, 336) {
    auto node336 = GET_SKILL_NODE(336, PhaseNode_Detect);
    if (node336 == nullptr) {
        node336 = new PhaseNode_Detect(336, phase);
        node336->setSelf(0U);
        node336->setEvent("daduan_001");
        node336->setType(PhaseNode_Detect::Detect_Type::Interrupt_Skill);
        node336->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10043, 336, node336)
    }
    if (noInit == true) {
        return node336;
    }
    return node336;
}
//--------------------------------------------------------------------------------
// SwitchToInt
//
REGISTER_REGISTER_SKILL_NODE(10043, 337) {
    pnode->resizeTrigger(4);
    pnode->regTrigger<PhaseNode_StopEffect>(1, 328, PhaseNode_StopEffect::FUNC_DO, &PhaseNode_StopEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(10043, 337) {
    auto node337 = GET_SKILL_NODE(337, PhaseNode_SwitchToInt);
    if (node337 == nullptr) {
        node337 = new PhaseNode_SwitchToInt(337, phase);
        CALL_REGISTER_SKILL_NODE(10043, 337, node337)
    }
    if (noInit == true) {
        return node337;
    }
    auto variables = node337->getVariables();
    if (variables != nullptr) {
        node337->setSelection(variables->getVariable<int32_t>(Variable_10043_a100432));
    }
    return node337;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10043, 339) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_RaiseEvent::TRIGGER_DONE, 348, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10043, 339) {
    auto node339 = GET_SKILL_NODE(339, PhaseNode_RaiseEvent);
    if (node339 == nullptr) {
        node339 = new PhaseNode_RaiseEvent(339, phase);
        node339->setEvent("daduan_001");
        node339->setTarget(0U);
        node339->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node339->setTypeParams(0, 0);
        node339->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10043, 339, node339)
    }
    if (noInit == true) {
        return node339;
    }
    return node339;
}
//--------------------------------------------------------------------------------
// StartPreInput
//
REGISTER_REGISTER_SKILL_NODE(10043, 340) {
    pnode->resizeTrigger(PhaseNode_StartPreInput::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_StartPreInput::TRIGGER_DONE, 344, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_StartPreInput::TRIGGER_DONE, 326, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(10043, 340) {
    auto node340 = GET_SKILL_NODE(340, PhaseNode_StartPreInput);
    if (node340 == nullptr) {
        node340 = new PhaseNode_StartPreInput(340, phase);
        node340->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node340->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node340->setDelayTime(.00f);
        CALL_REGISTER_SKILL_NODE(10043, 340, node340)
    }
    if (noInit == true) {
        return node340;
    }
    return node340;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(10043, 341) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_If::TRIGGER_TRUE, 343, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10043, 341) {
    auto node341 = GET_SKILL_NODE(341, PhaseNode_If);
    if (node341 == nullptr) {
        node341 = new PhaseNode_If(341, phase);
        CALL_REGISTER_SKILL_NODE(10043, 341, node341)
    }
    if (noInit == true) {
        return node341;
    }
    auto variables = node341->getVariables();
    if (variables != nullptr) {
        node341->setCondition(variables->getVariable<bool>(Variable_10043_InterruptAnimat));
    }
    return node341;
}
//--------------------------------------------------------------------------------
// IsInterruptType
//
REGISTER_REGISTER_SKILL_NODE(10043, 342) {
    pnode->resizeTrigger(PhaseNode_IsInterruptType::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SwitchToInt>(PhaseNode_IsInterruptType::TRIGGER_BUFF, 337, PhaseNode_SwitchToInt::FUNC_SWITCH, &PhaseNode_SwitchToInt::Switch);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_POSCHANGE, 341, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTAIM, 341, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTFIRE, 341, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTRELOAD, 341, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_USESKILL, 341, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(10043, 342) {
    auto node342 = GET_SKILL_NODE(342, PhaseNode_IsInterruptType);
    if (node342 == nullptr) {
        node342 = new PhaseNode_IsInterruptType(342, phase);
        node342->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node342->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10043, 342, node342)
    }
    if (noInit == true) {
        return node342;
    }
    auto node336 = GET_SKILL_NODE(336, PhaseNode_Detect);
    if (node336 != nullptr) node342->setType(node336->getVars().getVariable<int32_t>(2));
    return node342;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10043, 343) {
}

REGISTER_CREATE_SKILL_NODE(10043, 343) {
    auto node343 = GET_SKILL_NODE(343, PhaseNode_PlayAnimation);
    if (node343 == nullptr) {
        node343 = new PhaseNode_PlayAnimation(343, phase);
        node343->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node343->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node343->setTarget(0U);
        node343->setAnimation("Idle");
        node343->setParameter("");
        node343->setValue(false);
        CALL_REGISTER_SKILL_NODE(10043, 343, node343)
    }
    if (noInit == true) {
        return node343;
    }
    return node343;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10043, 344) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_Delay::TRIGGER_DONE, 347, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(10043, 344) {
    auto node344 = GET_SKILL_NODE(344, PhaseNode_Delay);
    if (node344 == nullptr) {
        node344 = new PhaseNode_Delay(344, phase);
        node344->setTime(.20f);
        CALL_REGISTER_SKILL_NODE(10043, 344, node344)
    }
    if (noInit == true) {
        return node344;
    }
    return node344;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(10043, 347) {
}

REGISTER_CREATE_SKILL_NODE(10043, 347) {
    auto node347 = GET_SKILL_NODE(347, PhaseNode_SetBool);
    if (node347 == nullptr) {
        node347 = new PhaseNode_SetBool(347, phase);
        node347->setName("InterruptAnimat");
        node347->setValue(true);
        CALL_REGISTER_SKILL_NODE(10043, 347, node347)
    }
    if (noInit == true) {
        return node347;
    }
    return node347;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10043, 348) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StartPreInput>(PhaseNode_RaiseEvent::TRIGGER_DONE, 340, PhaseNode_StartPreInput::FUNC_DO, &PhaseNode_StartPreInput::Do);
}

REGISTER_CREATE_SKILL_NODE(10043, 348) {
    auto node348 = GET_SKILL_NODE(348, PhaseNode_RaiseEvent);
    if (node348 == nullptr) {
        node348 = new PhaseNode_RaiseEvent(348, phase);
        node348->setEvent("Dead_001");
        node348->setTarget(0U);
        node348->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node348->setTypeParams(0, 0);
        node348->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10043, 348, node348)
    }
    if (noInit == true) {
        return node348;
    }
    return node348;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10043, 349) {
}

REGISTER_CREATE_SKILL_NODE(10043, 349) {
    auto node349 = GET_SKILL_NODE(349, PhaseNode_Detect);
    if (node349 == nullptr) {
        node349 = new PhaseNode_Detect(349, phase);
        node349->setSelf(0U);
        node349->setEvent("Dead_001");
        node349->setType(PhaseNode_Detect::Detect_Type::Actor_Dead);
        node349->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10043, 349, node349)
    }
    if (noInit == true) {
        return node349;
    }
    return node349;
}

//--------------------------------------------------------------------------------
// SkillCreator_10043
//
class SkillCreator_10043 : public SkillCreator {
public:
    SkillCreator_10043() {}
    virtual ~SkillCreator_10043() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_10043

//--------------------------------------------------------------------------------
// SkillPhase_10043
//
class SkillPhase_10043 : public SkillPhase {
public:
    SkillPhase_10043(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_10043() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(10043, 1) // StartPhase
        CASE_CREATE_SKILL_NODE(10043, 14) // Delay
        CASE_CREATE_SKILL_NODE(10043, 18) // TriggerUpdate
        CASE_CREATE_SKILL_NODE(10043, 37) // EndPhase
        CASE_CREATE_SKILL_NODE(10043, 64) // Delay
        CASE_CREATE_SKILL_NODE(10043, 122) // Disable
        CASE_CREATE_SKILL_NODE(10043, 139) // PlaySound
        CASE_CREATE_SKILL_NODE(10043, 144) // PlaySound
        CASE_CREATE_SKILL_NODE(10043, 280) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(10043, 307) // LineCheckNewPene
        CASE_CREATE_SKILL_NODE(10043, 318) // CameraXYZShake
        CASE_CREATE_SKILL_NODE(10043, 320) // GetLocation
        CASE_CREATE_SKILL_NODE(10043, 322) // GetInputRotation
        CASE_CREATE_SKILL_NODE(10043, 324) // AreaCollisionNewPene
        CASE_CREATE_SKILL_NODE(10043, 326) // PlayEffect
        CASE_CREATE_SKILL_NODE(10043, 328) // StopEffect
        CASE_CREATE_SKILL_NODE(10043, 330) // PlayEffect
        CASE_CREATE_SKILL_NODE(10043, 331) // ResetCD
        CASE_CREATE_SKILL_NODE(10043, 332) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10043, 333) // PlaySound
        CASE_CREATE_SKILL_NODE(10043, 334) // GetActorAttribute
        CASE_CREATE_SKILL_NODE(10043, 336) // Detect
        CASE_CREATE_SKILL_NODE(10043, 337) // SwitchToInt
        CASE_CREATE_SKILL_NODE(10043, 339) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10043, 340) // StartPreInput
        CASE_CREATE_SKILL_NODE(10043, 341) // If
        CASE_CREATE_SKILL_NODE(10043, 342) // IsInterruptType
        CASE_CREATE_SKILL_NODE(10043, 343) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10043, 344) // Delay
        CASE_CREATE_SKILL_NODE(10043, 347) // SetBool
        CASE_CREATE_SKILL_NODE(10043, 348) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10043, 349) // Detect
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_10043

SkillLogic* SkillCreator_10043::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //设置变量
    Variable_10043_a100432 = logic->getVariables().setVariable<int32_t>("a100432", 1);
    Variable_10043_InterruptAnimat = logic->getVariables().setVariable<bool>("InterruptAnimat");
    //创建阶段phase
    auto phase = new SkillPhase_10043(1, logic, 3);
    //设置phase执行器
    phase->setRunPhaseNode(1, 1);
    phase->setRunPhaseNode(2, 18);
    phase->setDetectPhaseNode(3, 336);
    phase->setDetectPhaseNode(3, 349);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_10043::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
