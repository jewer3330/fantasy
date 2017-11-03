#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

#include "skill_psnode_addskillbuff.h"
#include "skill_psnode_addskillbuffs.h"
#include "skill_psnode_cameraoffset.h"
#include "skill_psnode_delay.h"
#include "skill_psnode_detect.h"
#include "skill_psnode_disable.h"
#include "skill_psnode_endphase.h"
#include "skill_psnode_getactorattribute.h"
#include "skill_psnode_getallobject.h"
#include "skill_psnode_getlocation.h"
#include "skill_psnode_if.h"
#include "skill_psnode_isinterrupttype.h"
#include "skill_psnode_playanimation.h"
#include "skill_psnode_playeffect.h"
#include "skill_psnode_playsound.h"
#include "skill_psnode_playuieffect.h"
#include "skill_psnode_raiseevent.h"
#include "skill_psnode_resetcd.h"
#include "skill_psnode_setbool.h"
#include "skill_psnode_startphase.h"
#include "skill_psnode_startpreinput.h"
#include "skill_psnode_switchtoint.h"
#include "skill_psnode_switchweapon.h"
#include "skill_psnode_triggerupdate.h"

namespace pvp {

//变量声明
uint64_t Variable_10073_a100732 = 0;
uint64_t Variable_10073_InterruptAnimat = 0;
//--------------------------------------------------------------------------------
// StartPhase
//
REGISTER_REGISTER_SKILL_NODE(10073, 1) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_StartPhase::TRIGGER_START, 607, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(10073, 1) {
    auto node1 = GET_SKILL_NODE(1, PhaseNode_StartPhase);
    if (node1 == nullptr) {
        node1 = new PhaseNode_StartPhase(1, phase);
        CALL_REGISTER_SKILL_NODE(10073, 1, node1)
    }
    if (noInit == true) {
        return node1;
    }
    return node1;
}
//--------------------------------------------------------------------------------
// TriggerUpdate
//
REGISTER_REGISTER_SKILL_NODE(10073, 52) {
}

REGISTER_CREATE_SKILL_NODE(10073, 52) {
    auto node52 = GET_SKILL_NODE(52, PhaseNode_TriggerUpdate);
    if (node52 == nullptr) {
        node52 = new PhaseNode_TriggerUpdate(52, phase);
        CALL_REGISTER_SKILL_NODE(10073, 52, node52)
    }
    if (noInit == true) {
        return node52;
    }
    return node52;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(10073, 60) {
}

REGISTER_CREATE_SKILL_NODE(10073, 60) {
    auto node60 = GET_SKILL_NODE(60, PhaseNode_EndPhase);
    if (node60 == nullptr) {
        node60 = new PhaseNode_EndPhase(60, phase);
        node60->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node60->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10073, 60, node60)
    }
    if (noInit == true) {
        return node60;
    }
    return node60;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10073, 241) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_Detect::TRIGGER_ON, 437, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(10073, 241) {
    auto node241 = GET_SKILL_NODE(241, PhaseNode_Detect);
    if (node241 == nullptr) {
        node241 = new PhaseNode_Detect(241, phase);
        node241->setSelf(0U);
        node241->setEvent("10073Dead");
        node241->setType(PhaseNode_Detect::Detect_Type::Actor_Dead);
        node241->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10073, 241, node241)
    }
    if (noInit == true) {
        return node241;
    }
    return node241;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(10073, 437) {
}

REGISTER_CREATE_SKILL_NODE(10073, 437) {
    auto node437 = GET_SKILL_NODE(437, PhaseNode_EndPhase);
    if (node437 == nullptr) {
        node437 = new PhaseNode_EndPhase(437, phase);
        node437->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node437->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10073, 437, node437)
    }
    if (noInit == true) {
        return node437;
    }
    return node437;
}
//--------------------------------------------------------------------------------
// AddSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10073, 535) {
    pnode->resizeTrigger(PhaseNode_AddSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CameraOffset>(PhaseNode_AddSkillBuff::TRIGGER_DONE, 537, PhaseNode_CameraOffset::FUNC_DO, &PhaseNode_CameraOffset::Do);
}

REGISTER_CREATE_SKILL_NODE(10073, 535) {
    auto node535 = GET_SKILL_NODE(535, PhaseNode_AddSkillBuff);
    if (node535 == nullptr) {
        node535 = new PhaseNode_AddSkillBuff(535, phase);
        node535->setConfigID(100731);
        node535->setConfigIDs({});
        node535->setTarget(0U);
        node535->setAttribute({{}});
        CALL_REGISTER_SKILL_NODE(10073, 535, node535)
    }
    if (noInit == true) {
        return node535;
    }
    return node535;
}
//--------------------------------------------------------------------------------
// CameraOffset
//
REGISTER_REGISTER_SKILL_NODE(10073, 537) {
    pnode->resizeTrigger(PhaseNode_CameraOffset::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetAllObject>(PhaseNode_CameraOffset::TRIGGER_DONE, 555, PhaseNode_GetAllObject::FUNC_DO, &PhaseNode_GetAllObject::Do);
}

REGISTER_CREATE_SKILL_NODE(10073, 537) {
    auto node537 = GET_SKILL_NODE(537, PhaseNode_CameraOffset);
    if (node537 == nullptr) {
        node537 = new PhaseNode_CameraOffset(537, phase);
        node537->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node537->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node537->setOffsetX(.00f);
        node537->setOffsetY(-8.00f);
        node537->setOffsetZ(12.00f);
        node537->setSpeed(2.00f);
        CALL_REGISTER_SKILL_NODE(10073, 537, node537)
    }
    if (noInit == true) {
        return node537;
    }
    return node537;
}
//--------------------------------------------------------------------------------
// CameraOffset
//
REGISTER_REGISTER_SKILL_NODE(10073, 547) {
    pnode->resizeTrigger(PhaseNode_CameraOffset::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_CameraOffset::TRIGGER_DONE, 60, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(10073, 547) {
    auto node547 = GET_SKILL_NODE(547, PhaseNode_CameraOffset);
    if (node547 == nullptr) {
        node547 = new PhaseNode_CameraOffset(547, phase);
        node547->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node547->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node547->setOffsetX(.00f);
        node547->setOffsetY(.00f);
        node547->setOffsetZ(.00f);
        node547->setSpeed(2.00f);
        CALL_REGISTER_SKILL_NODE(10073, 547, node547)
    }
    if (noInit == true) {
        return node547;
    }
    return node547;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(10073, 553) {
    pnode->resizeTrigger(PhaseNode_AddSkillBuffs::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_AddSkillBuffs::TRIGGER_DONE, 595, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10073, 553) {
    auto node553 = GET_SKILL_NODE(553, PhaseNode_AddSkillBuffs);
    if (node553 == nullptr) {
        node553 = new PhaseNode_AddSkillBuffs(553, phase);
        node553->setConfigID({100732});
        node553->setAttribute({{}});
        CALL_REGISTER_SKILL_NODE(10073, 553, node553)
    }
    if (noInit == true) {
        return node553;
    }
    auto node555 = GET_SKILL_NODE(555, PhaseNode_GetAllObject);
    if (node555 != nullptr) node553->setTarget(node555->getOutPut());
    return node553;
}
//--------------------------------------------------------------------------------
// GetAllObject
//
REGISTER_REGISTER_SKILL_NODE(10073, 555) {
    pnode->resizeTrigger(PhaseNode_GetAllObject::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetAllObject::TRIGGER_DONE, 553, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
}

REGISTER_CREATE_SKILL_NODE(10073, 555) {
    auto node555 = GET_SKILL_NODE(555, PhaseNode_GetAllObject);
    if (node555 == nullptr) {
        node555 = new PhaseNode_GetAllObject(555, phase);
        node555->setState(PhaseNode_GetAllObject::GetAllObject_State::StateAll);
        node555->setCheckFaction(PhaseNode_GetAllObject::GetAllObject_CheckFaction::Enemy);
        node555->setOnHero(true);
        node555->setOnMinion(false);
        node555->setOnDestruct(false);
        CALL_REGISTER_SKILL_NODE(10073, 555, node555)
    }
    if (noInit == true) {
        return node555;
    }
    return node555;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(10073, 557) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_PlayEffect::TRIGGER_DONE, 563, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(10073, 557) {
    auto node557 = GET_SKILL_NODE(557, PhaseNode_PlayEffect);
    if (node557 == nullptr) {
        node557 = new PhaseNode_PlayEffect(557, phase);
        node557->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node557->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node557->setEffectID(100702);
        node557->setChangeColor(true);
        node557->setType(PhaseNode_PlayEffect::PlayEffect_Type::WithTarget);
        node557->getVars().reserve(5);
        node557->getVars().setVariable<uint64_t>(0, 0U);
        node557->getVars().setVariable<std::string>(1, "");
        node557->getVars().setVariable<float>(2, .00f);
        node557->getVars().setVariable<float>(3, .00f);
        node557->getVars().setVariable<float>(4, .00f);
        node557->setRotation(.00f);
        node557->setScale(.00f);
        CALL_REGISTER_SKILL_NODE(10073, 557, node557)
    }
    if (noInit == true) {
        return node557;
    }
    return node557;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(10073, 563) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_PlayEffect::TRIGGER_DONE, 599, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(10073, 563) {
    auto node563 = GET_SKILL_NODE(563, PhaseNode_PlayEffect);
    if (node563 == nullptr) {
        node563 = new PhaseNode_PlayEffect(563, phase);
        node563->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node563->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node563->setEffectID(100731);
        node563->setChangeColor(true);
        node563->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node563->getVars().reserve(3);
        node563->getVars().setVariable<float>(0, .00f);
        node563->getVars().setVariable<float>(1, .00f);
        node563->getVars().setVariable<float>(2, .00f);
        node563->setRotation(.00f);
        node563->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(10073, 563, node563)
    }
    if (noInit == true) {
        return node563;
    }
    auto node604 = GET_SKILL_NODE(604, PhaseNode_GetLocation);
    if (node604 != nullptr) node563->getVars().setVariable<float>(0, node604->getX());
    if (node604 != nullptr) node563->getVars().setVariable<float>(1, node604->getY());
    return node563;
}
//--------------------------------------------------------------------------------
// SwitchWeapon
//
REGISTER_REGISTER_SKILL_NODE(10073, 567) {
    pnode->resizeTrigger(PhaseNode_SwitchWeapon::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_SwitchWeapon::TRIGGER_DONE, 597, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10073, 567) {
    auto node567 = GET_SKILL_NODE(567, PhaseNode_SwitchWeapon);
    if (node567 == nullptr) {
        node567 = new PhaseNode_SwitchWeapon(567, phase);
        node567->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node567->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node567->setTarget(0U);
        node567->setTime(10.00f);
        node567->setShots(0);
        node567->setWeaponID(10075);
        node567->setSaveMag(false);
        CALL_REGISTER_SKILL_NODE(10073, 567, node567)
    }
    if (noInit == true) {
        return node567;
    }
    return node567;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10073, 572) {
}

REGISTER_CREATE_SKILL_NODE(10073, 572) {
    auto node572 = GET_SKILL_NODE(572, PhaseNode_PlaySound);
    if (node572 == nullptr) {
        node572 = new PhaseNode_PlaySound(572, phase);
        node572->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node572->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node572->setSoundID("SE_Hero104_SkillB_P1");
        node572->setTarget(0U);
        node572->setUsePos(false);
        node572->setPosX(.00f);
        node572->setPosY(.00f);
        node572->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10073, 572, node572)
    }
    if (noInit == true) {
        return node572;
    }
    return node572;
}
//--------------------------------------------------------------------------------
// Disable
//
REGISTER_REGISTER_SKILL_NODE(10073, 575) {
    pnode->resizeTrigger(PhaseNode_Disable::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_Disable::TRIGGER_CANCEL, 580, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_Disable::TRIGGER_DONE, 615, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10073, 575) {
    auto node575 = GET_SKILL_NODE(575, PhaseNode_Disable);
    if (node575 == nullptr) {
        node575 = new PhaseNode_Disable(575, phase);
        node575->setTarget(0U);
        node575->setMove(true);
        node575->setSkill(true);
        node575->setShoot(true);
        node575->setTime(.70f);
        node575->setRotate(true);
        CALL_REGISTER_SKILL_NODE(10073, 575, node575)
    }
    if (noInit == true) {
        return node575;
    }
    return node575;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10073, 577) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Disable>(PhaseNode_Delay::TRIGGER_DONE, 575, PhaseNode_Disable::FUNC_CANCLE, &PhaseNode_Disable::Cancle);
}

REGISTER_CREATE_SKILL_NODE(10073, 577) {
    auto node577 = GET_SKILL_NODE(577, PhaseNode_Delay);
    if (node577 == nullptr) {
        node577 = new PhaseNode_Delay(577, phase);
        node577->setTime(.50f);
        CALL_REGISTER_SKILL_NODE(10073, 577, node577)
    }
    if (noInit == true) {
        return node577;
    }
    return node577;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10073, 580) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SwitchWeapon>(PhaseNode_PlayAnimation::TRIGGER_DONE, 567, PhaseNode_SwitchWeapon::FUNC_DO, &PhaseNode_SwitchWeapon::Do);
}

REGISTER_CREATE_SKILL_NODE(10073, 580) {
    auto node580 = GET_SKILL_NODE(580, PhaseNode_PlayAnimation);
    if (node580 == nullptr) {
        node580 = new PhaseNode_PlayAnimation(580, phase);
        node580->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node580->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node580->setTarget(0U);
        node580->setAnimation("Idle");
        node580->setParameter("");
        node580->setValue(false);
        CALL_REGISTER_SKILL_NODE(10073, 580, node580)
    }
    if (noInit == true) {
        return node580;
    }
    return node580;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10073, 595) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_Delay::TRIGGER_DONE, 557, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(10073, 595) {
    auto node595 = GET_SKILL_NODE(595, PhaseNode_Delay);
    if (node595 == nullptr) {
        node595 = new PhaseNode_Delay(595, phase);
        node595->setTime(.16f);
        CALL_REGISTER_SKILL_NODE(10073, 595, node595)
    }
    if (noInit == true) {
        return node595;
    }
    return node595;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10073, 597) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CameraOffset>(PhaseNode_Delay::TRIGGER_DONE, 547, PhaseNode_CameraOffset::FUNC_DO, &PhaseNode_CameraOffset::Do);
}

REGISTER_CREATE_SKILL_NODE(10073, 597) {
    auto node597 = GET_SKILL_NODE(597, PhaseNode_Delay);
    if (node597 == nullptr) {
        node597 = new PhaseNode_Delay(597, phase);
        node597->setTime(10.00f);
        CALL_REGISTER_SKILL_NODE(10073, 597, node597)
    }
    if (noInit == true) {
        return node597;
    }
    return node597;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(10073, 599) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_PlayEffect::TRIGGER_DONE, 602, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(10073, 599) {
    auto node599 = GET_SKILL_NODE(599, PhaseNode_PlayEffect);
    if (node599 == nullptr) {
        node599 = new PhaseNode_PlayEffect(599, phase);
        node599->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node599->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node599->setEffectID(100733);
        node599->setChangeColor(false);
        node599->setType(PhaseNode_PlayEffect::PlayEffect_Type::WithTarget);
        node599->getVars().reserve(6);
        node599->getVars().setVariable<uint64_t>(0, 0U);
        node599->getVars().setVariable<std::string>(1, "Bone_Weapon");
        node599->getVars().setVariable<float>(2, .00f);
        node599->getVars().setVariable<float>(3, .00f);
        node599->getVars().setVariable<float>(4, .00f);
        node599->getVars().setVariable<bool>(5, false);
        node599->setRotation(.00f);
        node599->setScale(.00f);
        CALL_REGISTER_SKILL_NODE(10073, 599, node599)
    }
    if (noInit == true) {
        return node599;
    }
    return node599;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(10073, 602) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlayEffect::TRIGGER_DONE, 577, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10073, 602) {
    auto node602 = GET_SKILL_NODE(602, PhaseNode_PlayEffect);
    if (node602 == nullptr) {
        node602 = new PhaseNode_PlayEffect(602, phase);
        node602->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node602->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node602->setEffectID(100734);
        node602->setChangeColor(false);
        node602->setType(PhaseNode_PlayEffect::PlayEffect_Type::WithTarget);
        node602->getVars().reserve(6);
        node602->getVars().setVariable<uint64_t>(0, 0U);
        node602->getVars().setVariable<std::string>(1, "");
        node602->getVars().setVariable<float>(2, .00f);
        node602->getVars().setVariable<float>(3, .00f);
        node602->getVars().setVariable<float>(4, .00f);
        node602->getVars().setVariable<bool>(5, true);
        node602->setRotation(.00f);
        node602->setScale(.00f);
        CALL_REGISTER_SKILL_NODE(10073, 602, node602)
    }
    if (noInit == true) {
        return node602;
    }
    return node602;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(10073, 604) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Disable>(PhaseNode_GetLocation::TRIGGER_DONE, 575, PhaseNode_Disable::FUNC_DO, &PhaseNode_Disable::Do);
}

REGISTER_CREATE_SKILL_NODE(10073, 604) {
    auto node604 = GET_SKILL_NODE(604, PhaseNode_GetLocation);
    if (node604 == nullptr) {
        node604 = new PhaseNode_GetLocation(604, phase);
        node604->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node604->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(10073, 604, node604)
    }
    if (noInit == true) {
        return node604;
    }
    return node604;
}
//--------------------------------------------------------------------------------
// PlayUIEffect
//
REGISTER_REGISTER_SKILL_NODE(10073, 606) {
    pnode->resizeTrigger(PhaseNode_PlayUIEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuff>(PhaseNode_PlayUIEffect::TRIGGER_DONE, 535, PhaseNode_AddSkillBuff::FUNC_ADD, &PhaseNode_AddSkillBuff::Add);
}

REGISTER_CREATE_SKILL_NODE(10073, 606) {
    auto node606 = GET_SKILL_NODE(606, PhaseNode_PlayUIEffect);
    if (node606 == nullptr) {
        node606 = new PhaseNode_PlayUIEffect(606, phase);
        node606->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node606->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node606->setTime(10.00f);
        node606->setType(2);
        CALL_REGISTER_SKILL_NODE(10073, 606, node606)
    }
    if (noInit == true) {
        return node606;
    }
    return node606;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(10073, 607) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_ResetCD::TRIGGER_DONE, 608, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10073, 607) {
    auto node607 = GET_SKILL_NODE(607, PhaseNode_ResetCD);
    if (node607 == nullptr) {
        node607 = new PhaseNode_ResetCD(607, phase);
        node607->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node607->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node607->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(10073, 607, node607)
    }
    if (noInit == true) {
        return node607;
    }
    return node607;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10073, 608) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_PlayAnimation::TRIGGER_DONE, 610, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(10073, 608) {
    auto node608 = GET_SKILL_NODE(608, PhaseNode_PlayAnimation);
    if (node608 == nullptr) {
        node608 = new PhaseNode_PlayAnimation(608, phase);
        node608->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node608->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node608->setTarget(0U);
        node608->setAnimation("Skill3S1");
        node608->setParameter("");
        node608->setValue(false);
        CALL_REGISTER_SKILL_NODE(10073, 608, node608)
    }
    if (noInit == true) {
        return node608;
    }
    return node608;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10073, 609) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_PlaySound::TRIGGER_DONE, 604, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_PlaySound::TRIGGER_DONE, 572, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10073, 609) {
    auto node609 = GET_SKILL_NODE(609, PhaseNode_PlaySound);
    if (node609 == nullptr) {
        node609 = new PhaseNode_PlaySound(609, phase);
        node609->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node609->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node609->setSoundID("VO_Hero104_Skill_B");
        node609->setTarget(0U);
        node609->setUsePos(false);
        node609->setPosX(.00f);
        node609->setPosY(.00f);
        node609->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10073, 609, node609)
    }
    if (noInit == true) {
        return node609;
    }
    return node609;
}
//--------------------------------------------------------------------------------
// GetActorAttribute
//
REGISTER_REGISTER_SKILL_NODE(10073, 610) {
    pnode->resizeTrigger(PhaseNode_GetActorAttribute::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 609, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10073, 610) {
    auto node610 = GET_SKILL_NODE(610, PhaseNode_GetActorAttribute);
    if (node610 == nullptr) {
        node610 = new PhaseNode_GetActorAttribute(610, phase);
        node610->setTarget(0U);
        node610->setType({});
        CALL_REGISTER_SKILL_NODE(10073, 610, node610)
    }
    if (noInit == true) {
        return node610;
    }
    return node610;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10073, 612) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_IsInterruptType>(PhaseNode_Detect::TRIGGER_ON, 618, PhaseNode_IsInterruptType::FUNC_DO, &PhaseNode_IsInterruptType::Do);
}

REGISTER_CREATE_SKILL_NODE(10073, 612) {
    auto node612 = GET_SKILL_NODE(612, PhaseNode_Detect);
    if (node612 == nullptr) {
        node612 = new PhaseNode_Detect(612, phase);
        node612->setSelf(0U);
        node612->setEvent("daduan_001");
        node612->setType(PhaseNode_Detect::Detect_Type::Interrupt_Skill);
        node612->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10073, 612, node612)
    }
    if (noInit == true) {
        return node612;
    }
    return node612;
}
//--------------------------------------------------------------------------------
// SwitchToInt
//
REGISTER_REGISTER_SKILL_NODE(10073, 613) {
}

REGISTER_CREATE_SKILL_NODE(10073, 613) {
    auto node613 = GET_SKILL_NODE(613, PhaseNode_SwitchToInt);
    if (node613 == nullptr) {
        node613 = new PhaseNode_SwitchToInt(613, phase);
        CALL_REGISTER_SKILL_NODE(10073, 613, node613)
    }
    if (noInit == true) {
        return node613;
    }
    auto variables = node613->getVariables();
    if (variables != nullptr) {
        node613->setSelection(variables->getVariable<int32_t>(Variable_10073_a100732));
    }
    return node613;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10073, 615) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_RaiseEvent::TRIGGER_DONE, 624, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10073, 615) {
    auto node615 = GET_SKILL_NODE(615, PhaseNode_RaiseEvent);
    if (node615 == nullptr) {
        node615 = new PhaseNode_RaiseEvent(615, phase);
        node615->setEvent("daduan_001");
        node615->setTarget(0U);
        node615->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node615->setTypeParams(0, 0);
        node615->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10073, 615, node615)
    }
    if (noInit == true) {
        return node615;
    }
    return node615;
}
//--------------------------------------------------------------------------------
// StartPreInput
//
REGISTER_REGISTER_SKILL_NODE(10073, 616) {
    pnode->resizeTrigger(PhaseNode_StartPreInput::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_StartPreInput::TRIGGER_DONE, 620, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_PlayUIEffect>(PhaseNode_StartPreInput::TRIGGER_DONE, 606, PhaseNode_PlayUIEffect::FUNC_DO, &PhaseNode_PlayUIEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(10073, 616) {
    auto node616 = GET_SKILL_NODE(616, PhaseNode_StartPreInput);
    if (node616 == nullptr) {
        node616 = new PhaseNode_StartPreInput(616, phase);
        node616->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node616->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node616->setDelayTime(.00f);
        CALL_REGISTER_SKILL_NODE(10073, 616, node616)
    }
    if (noInit == true) {
        return node616;
    }
    return node616;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(10073, 617) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_If::TRIGGER_TRUE, 619, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10073, 617) {
    auto node617 = GET_SKILL_NODE(617, PhaseNode_If);
    if (node617 == nullptr) {
        node617 = new PhaseNode_If(617, phase);
        CALL_REGISTER_SKILL_NODE(10073, 617, node617)
    }
    if (noInit == true) {
        return node617;
    }
    auto variables = node617->getVariables();
    if (variables != nullptr) {
        node617->setCondition(variables->getVariable<bool>(Variable_10073_InterruptAnimat));
    }
    return node617;
}
//--------------------------------------------------------------------------------
// IsInterruptType
//
REGISTER_REGISTER_SKILL_NODE(10073, 618) {
    pnode->resizeTrigger(PhaseNode_IsInterruptType::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SwitchToInt>(PhaseNode_IsInterruptType::TRIGGER_BUFF, 613, PhaseNode_SwitchToInt::FUNC_SWITCH, &PhaseNode_SwitchToInt::Switch);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_POSCHANGE, 617, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTAIM, 617, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTFIRE, 617, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTRELOAD, 617, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_USESKILL, 617, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(10073, 618) {
    auto node618 = GET_SKILL_NODE(618, PhaseNode_IsInterruptType);
    if (node618 == nullptr) {
        node618 = new PhaseNode_IsInterruptType(618, phase);
        node618->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node618->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10073, 618, node618)
    }
    if (noInit == true) {
        return node618;
    }
    auto node612 = GET_SKILL_NODE(612, PhaseNode_Detect);
    if (node612 != nullptr) node618->setType(node612->getVars().getVariable<int32_t>(2));
    return node618;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10073, 619) {
}

REGISTER_CREATE_SKILL_NODE(10073, 619) {
    auto node619 = GET_SKILL_NODE(619, PhaseNode_PlayAnimation);
    if (node619 == nullptr) {
        node619 = new PhaseNode_PlayAnimation(619, phase);
        node619->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node619->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node619->setTarget(0U);
        node619->setAnimation("Idle");
        node619->setParameter("");
        node619->setValue(false);
        CALL_REGISTER_SKILL_NODE(10073, 619, node619)
    }
    if (noInit == true) {
        return node619;
    }
    return node619;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10073, 620) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_Delay::TRIGGER_DONE, 623, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(10073, 620) {
    auto node620 = GET_SKILL_NODE(620, PhaseNode_Delay);
    if (node620 == nullptr) {
        node620 = new PhaseNode_Delay(620, phase);
        node620->setTime(.30f);
        CALL_REGISTER_SKILL_NODE(10073, 620, node620)
    }
    if (noInit == true) {
        return node620;
    }
    return node620;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(10073, 623) {
}

REGISTER_CREATE_SKILL_NODE(10073, 623) {
    auto node623 = GET_SKILL_NODE(623, PhaseNode_SetBool);
    if (node623 == nullptr) {
        node623 = new PhaseNode_SetBool(623, phase);
        node623->setName("InterruptAnimat");
        node623->setValue(true);
        CALL_REGISTER_SKILL_NODE(10073, 623, node623)
    }
    if (noInit == true) {
        return node623;
    }
    return node623;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10073, 624) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StartPreInput>(PhaseNode_RaiseEvent::TRIGGER_DONE, 616, PhaseNode_StartPreInput::FUNC_DO, &PhaseNode_StartPreInput::Do);
}

REGISTER_CREATE_SKILL_NODE(10073, 624) {
    auto node624 = GET_SKILL_NODE(624, PhaseNode_RaiseEvent);
    if (node624 == nullptr) {
        node624 = new PhaseNode_RaiseEvent(624, phase);
        node624->setEvent("Dead_001");
        node624->setTarget(0U);
        node624->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node624->setTypeParams(0, 0);
        node624->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10073, 624, node624)
    }
    if (noInit == true) {
        return node624;
    }
    return node624;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10073, 625) {
}

REGISTER_CREATE_SKILL_NODE(10073, 625) {
    auto node625 = GET_SKILL_NODE(625, PhaseNode_Detect);
    if (node625 == nullptr) {
        node625 = new PhaseNode_Detect(625, phase);
        node625->setSelf(0U);
        node625->setEvent("Dead_001");
        node625->setType(PhaseNode_Detect::Detect_Type::Actor_Dead);
        node625->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10073, 625, node625)
    }
    if (noInit == true) {
        return node625;
    }
    return node625;
}

//--------------------------------------------------------------------------------
// SkillCreator_10073
//
class SkillCreator_10073 : public SkillCreator {
public:
    SkillCreator_10073() {}
    virtual ~SkillCreator_10073() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_10073

//--------------------------------------------------------------------------------
// SkillPhase_10073
//
class SkillPhase_10073 : public SkillPhase {
public:
    SkillPhase_10073(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_10073() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(10073, 1) // StartPhase
        CASE_CREATE_SKILL_NODE(10073, 52) // TriggerUpdate
        CASE_CREATE_SKILL_NODE(10073, 60) // EndPhase
        CASE_CREATE_SKILL_NODE(10073, 241) // Detect
        CASE_CREATE_SKILL_NODE(10073, 437) // EndPhase
        CASE_CREATE_SKILL_NODE(10073, 535) // AddSkillBuff
        CASE_CREATE_SKILL_NODE(10073, 537) // CameraOffset
        CASE_CREATE_SKILL_NODE(10073, 547) // CameraOffset
        CASE_CREATE_SKILL_NODE(10073, 553) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(10073, 555) // GetAllObject
        CASE_CREATE_SKILL_NODE(10073, 557) // PlayEffect
        CASE_CREATE_SKILL_NODE(10073, 563) // PlayEffect
        CASE_CREATE_SKILL_NODE(10073, 567) // SwitchWeapon
        CASE_CREATE_SKILL_NODE(10073, 572) // PlaySound
        CASE_CREATE_SKILL_NODE(10073, 575) // Disable
        CASE_CREATE_SKILL_NODE(10073, 577) // Delay
        CASE_CREATE_SKILL_NODE(10073, 580) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10073, 595) // Delay
        CASE_CREATE_SKILL_NODE(10073, 597) // Delay
        CASE_CREATE_SKILL_NODE(10073, 599) // PlayEffect
        CASE_CREATE_SKILL_NODE(10073, 602) // PlayEffect
        CASE_CREATE_SKILL_NODE(10073, 604) // GetLocation
        CASE_CREATE_SKILL_NODE(10073, 606) // PlayUIEffect
        CASE_CREATE_SKILL_NODE(10073, 607) // ResetCD
        CASE_CREATE_SKILL_NODE(10073, 608) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10073, 609) // PlaySound
        CASE_CREATE_SKILL_NODE(10073, 610) // GetActorAttribute
        CASE_CREATE_SKILL_NODE(10073, 612) // Detect
        CASE_CREATE_SKILL_NODE(10073, 613) // SwitchToInt
        CASE_CREATE_SKILL_NODE(10073, 615) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10073, 616) // StartPreInput
        CASE_CREATE_SKILL_NODE(10073, 617) // If
        CASE_CREATE_SKILL_NODE(10073, 618) // IsInterruptType
        CASE_CREATE_SKILL_NODE(10073, 619) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10073, 620) // Delay
        CASE_CREATE_SKILL_NODE(10073, 623) // SetBool
        CASE_CREATE_SKILL_NODE(10073, 624) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10073, 625) // Detect
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_10073

SkillLogic* SkillCreator_10073::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //设置变量
    Variable_10073_a100732 = logic->getVariables().setVariable<int32_t>("a100732", 1);
    Variable_10073_InterruptAnimat = logic->getVariables().setVariable<bool>("InterruptAnimat");
    //创建阶段phase
    auto phase = new SkillPhase_10073(1, logic, 3);
    //设置phase执行器
    phase->setRunPhaseNode(1, 1);
    phase->setRunPhaseNode(2, 52);
    phase->setDetectPhaseNode(3, 241);
    phase->setDetectPhaseNode(3, 612);
    phase->setDetectPhaseNode(3, 625);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_10073::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
