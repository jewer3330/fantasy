#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

#include "skill_psnode_addskillbuffs.h"
#include "skill_psnode_areacollisionnewpene.h"
#include "skill_psnode_compareint.h"
#include "skill_psnode_costbuffattribute.h"
#include "skill_psnode_delay.h"
#include "skill_psnode_detect.h"
#include "skill_psnode_disable.h"
#include "skill_psnode_endphase.h"
#include "skill_psnode_getactorattribute.h"
#include "skill_psnode_getbuffattribute.h"
#include "skill_psnode_getinputrotation.h"
#include "skill_psnode_getlocation.h"
#include "skill_psnode_if.h"
#include "skill_psnode_isinterrupttype.h"
#include "skill_psnode_playanimation.h"
#include "skill_psnode_playeffect.h"
#include "skill_psnode_playsound.h"
#include "skill_psnode_raiseevent.h"
#include "skill_psnode_resetcd.h"
#include "skill_psnode_setbool.h"
#include "skill_psnode_setint.h"
#include "skill_psnode_startphase.h"
#include "skill_psnode_startpreinput.h"
#include "skill_psnode_switchtoint.h"

namespace pvp {

//变量声明
uint64_t Variable_10161_HaveEnergy = 0;
uint64_t Variable_10161_stop = 0;
uint64_t Variable_10161_InterruptAnimat = 0;
//--------------------------------------------------------------------------------
// StartPhase
//
REGISTER_REGISTER_SKILL_NODE(10161, 5) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_StartPhase::TRIGGER_START, 93, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(10161, 5) {
    auto node5 = GET_SKILL_NODE(5, PhaseNode_StartPhase);
    if (node5 == nullptr) {
        node5 = new PhaseNode_StartPhase(5, phase);
        CALL_REGISTER_SKILL_NODE(10161, 5, node5)
    }
    if (noInit == true) {
        return node5;
    }
    return node5;
}
//--------------------------------------------------------------------------------
// Disable
//
REGISTER_REGISTER_SKILL_NODE(10161, 14) {
    pnode->resizeTrigger(PhaseNode_Disable::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_Disable::TRIGGER_DONE, 29, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_GetBuffAttribute>(PhaseNode_Disable::TRIGGER_DONE, 57, PhaseNode_GetBuffAttribute::FUNC_DO, &PhaseNode_GetBuffAttribute::Do);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_Disable::TRIGGER_DONE, 101, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10161, 14) {
    auto node14 = GET_SKILL_NODE(14, PhaseNode_Disable);
    if (node14 == nullptr) {
        node14 = new PhaseNode_Disable(14, phase);
        node14->setTarget(0U);
        node14->setMove(true);
        node14->setSkill(true);
        node14->setShoot(true);
        node14->setTime(.70f);
        node14->setRotate(true);
        CALL_REGISTER_SKILL_NODE(10161, 14, node14)
    }
    if (noInit == true) {
        return node14;
    }
    return node14;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10161, 29) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_Delay::TRIGGER_DONE, 36, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(10161, 29) {
    auto node29 = GET_SKILL_NODE(29, PhaseNode_Delay);
    if (node29 == nullptr) {
        node29 = new PhaseNode_Delay(29, phase);
        node29->setTime(1.10f);
        CALL_REGISTER_SKILL_NODE(10161, 29, node29)
    }
    if (noInit == true) {
        return node29;
    }
    return node29;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(10161, 31) {
    pnode->resizeTrigger(PhaseNode_AddSkillBuffs::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_AddSkillBuffs::TRIGGER_DONE, 53, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(10161, 31) {
    auto node31 = GET_SKILL_NODE(31, PhaseNode_AddSkillBuffs);
    if (node31 == nullptr) {
        node31 = new PhaseNode_AddSkillBuffs(31, phase);
        node31->setConfigID({101611,101612});
        CALL_REGISTER_SKILL_NODE(10161, 31, node31)
    }
    if (noInit == true) {
        return node31;
    }
    auto node50 = GET_SKILL_NODE(50, PhaseNode_AreaCollisionNewPene);
    auto node96 = GET_SKILL_NODE(96, PhaseNode_GetActorAttribute);
    if (node50 != nullptr) node31->setTarget(node50->getColliders());
    if (node96 != nullptr) node31->setAttribute(node96->getAttribute());
    return node31;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10161, 34) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetInt>(PhaseNode_Delay::TRIGGER_DONE, 40, PhaseNode_SetInt::FUNC_SET, &PhaseNode_SetInt::Set);
}

REGISTER_CREATE_SKILL_NODE(10161, 34) {
    auto node34 = GET_SKILL_NODE(34, PhaseNode_Delay);
    if (node34 == nullptr) {
        node34 = new PhaseNode_Delay(34, phase);
        node34->setTime(.35f);
        CALL_REGISTER_SKILL_NODE(10161, 34, node34)
    }
    if (noInit == true) {
        return node34;
    }
    return node34;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(10161, 36) {
}

REGISTER_CREATE_SKILL_NODE(10161, 36) {
    auto node36 = GET_SKILL_NODE(36, PhaseNode_EndPhase);
    if (node36 == nullptr) {
        node36 = new PhaseNode_EndPhase(36, phase);
        node36->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node36->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10161, 36, node36)
    }
    if (noInit == true) {
        return node36;
    }
    return node36;
}
//--------------------------------------------------------------------------------
// SetInt
//
REGISTER_REGISTER_SKILL_NODE(10161, 40) {
    pnode->resizeTrigger(PhaseNode_SetInt::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_SetInt::TRIGGER_DONE, 92, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10161, 40) {
    auto node40 = GET_SKILL_NODE(40, PhaseNode_SetInt);
    if (node40 == nullptr) {
        node40 = new PhaseNode_SetInt(40, phase);
        node40->setName("stop");
        node40->setValue(2);
        CALL_REGISTER_SKILL_NODE(10161, 40, node40)
    }
    if (noInit == true) {
        return node40;
    }
    return node40;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(10161, 46) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetInputRotation>(PhaseNode_GetLocation::TRIGGER_DONE, 48, PhaseNode_GetInputRotation::FUNC_DO, &PhaseNode_GetInputRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(10161, 46) {
    auto node46 = GET_SKILL_NODE(46, PhaseNode_GetLocation);
    if (node46 == nullptr) {
        node46 = new PhaseNode_GetLocation(46, phase);
        node46->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node46->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(10161, 46, node46)
    }
    if (noInit == true) {
        return node46;
    }
    return node46;
}
//--------------------------------------------------------------------------------
// GetInputRotation
//
REGISTER_REGISTER_SKILL_NODE(10161, 48) {
    pnode->resizeTrigger(PhaseNode_GetInputRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_GetInputRotation::TRIGGER_DONE, 90, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10161, 48) {
    auto node48 = GET_SKILL_NODE(48, PhaseNode_GetInputRotation);
    if (node48 == nullptr) {
        node48 = new PhaseNode_GetInputRotation(48, phase);
        node48->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        CALL_REGISTER_SKILL_NODE(10161, 48, node48)
    }
    if (noInit == true) {
        return node48;
    }
    return node48;
}
//--------------------------------------------------------------------------------
// AreaCollisionNewPene
//
REGISTER_REGISTER_SKILL_NODE(10161, 50) {
    pnode->resizeTrigger(PhaseNode_AreaCollisionNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_AreaCollisionNewPene::TRIGGER_DONE, 74, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_AreaCollisionNewPene::TRIGGER_NONE, 86, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(10161, 50) {
    auto node50 = GET_SKILL_NODE(50, PhaseNode_AreaCollisionNewPene);
    if (node50 == nullptr) {
        node50 = new PhaseNode_AreaCollisionNewPene(50, phase);
        node50->setState(PhaseNode_AreaCollisionNewPene::AreaCollisionNewPene_State::Alive);
        node50->setFaction(PhaseNode_AreaCollisionNewPene::AreaCollisionNewPene_Faction::Enemy);
        node50->setOnHero(true);
        node50->setOnMinion(true);
        node50->setOnDestruct(false);
        node50->setOnShield(false);
        node50->setType(PhaseNode_AreaCollisionNewPene::AreaCollisionNewPene_Type::Rect);
        node50->setTypeParams(0, 17.00f);
        node50->setTypeParams(1, 3.00f);
        node50->setPositionZ(.00f);
        CALL_REGISTER_SKILL_NODE(10161, 50, node50)
    }
    if (noInit == true) {
        return node50;
    }
    auto node46 = GET_SKILL_NODE(46, PhaseNode_GetLocation);
    auto node48 = GET_SKILL_NODE(48, PhaseNode_GetInputRotation);
    if (node46 != nullptr) node50->setPositionX(node46->getX());
    if (node46 != nullptr) node50->setPositionY(node46->getY());
    if (node48 != nullptr) node50->setRotation(node48->getAngle());
    return node50;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(10161, 53) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_PlayEffect::TRIGGER_DONE, 55, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(10161, 53) {
    auto node53 = GET_SKILL_NODE(53, PhaseNode_PlayEffect);
    if (node53 == nullptr) {
        node53 = new PhaseNode_PlayEffect(53, phase);
        node53->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node53->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node53->setEffectID(101612);
        node53->setChangeColor(true);
        node53->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node53->getVars().reserve(3);
        node53->getVars().setVariable<float>(0, .00f);
        node53->getVars().setVariable<float>(1, .00f);
        node53->getVars().setVariable<float>(2, .00f);
        node53->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(10161, 53, node53)
    }
    if (noInit == true) {
        return node53;
    }
    auto node46 = GET_SKILL_NODE(46, PhaseNode_GetLocation);
    auto node48 = GET_SKILL_NODE(48, PhaseNode_GetInputRotation);
    if (node46 != nullptr) node53->getVars().setVariable<float>(0, node46->getX());
    if (node46 != nullptr) node53->getVars().setVariable<float>(1, node46->getY());
    if (node48 != nullptr) node53->setRotation(node48->getAngle());
    return node53;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(10161, 55) {
}

REGISTER_CREATE_SKILL_NODE(10161, 55) {
    auto node55 = GET_SKILL_NODE(55, PhaseNode_PlayEffect);
    if (node55 == nullptr) {
        node55 = new PhaseNode_PlayEffect(55, phase);
        node55->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node55->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node55->setEffectID(101613);
        node55->setChangeColor(true);
        node55->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node55->getVars().reserve(3);
        node55->getVars().setVariable<float>(0, .00f);
        node55->getVars().setVariable<float>(1, .00f);
        node55->getVars().setVariable<float>(2, .00f);
        node55->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(10161, 55, node55)
    }
    if (noInit == true) {
        return node55;
    }
    auto node46 = GET_SKILL_NODE(46, PhaseNode_GetLocation);
    auto node48 = GET_SKILL_NODE(48, PhaseNode_GetInputRotation);
    if (node46 != nullptr) node55->getVars().setVariable<float>(0, node46->getX());
    if (node46 != nullptr) node55->getVars().setVariable<float>(1, node46->getY());
    if (node48 != nullptr) node55->setRotation(node48->getAngle());
    return node55;
}
//--------------------------------------------------------------------------------
// GetBuffAttribute
//
REGISTER_REGISTER_SKILL_NODE(10161, 57) {
    pnode->resizeTrigger(PhaseNode_GetBuffAttribute::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareInt>(PhaseNode_GetBuffAttribute::TRIGGER_DONE, 63, PhaseNode_CompareInt::FUNC_COMPARE, &PhaseNode_CompareInt::Compare);
}

REGISTER_CREATE_SKILL_NODE(10161, 57) {
    auto node57 = GET_SKILL_NODE(57, PhaseNode_GetBuffAttribute);
    if (node57 == nullptr) {
        node57 = new PhaseNode_GetBuffAttribute(57, phase);
        node57->setTarget(0U);
        node57->setAttribute(45);
        CALL_REGISTER_SKILL_NODE(10161, 57, node57)
    }
    if (noInit == true) {
        return node57;
    }
    return node57;
}
//--------------------------------------------------------------------------------
// CompareInt
//
REGISTER_REGISTER_SKILL_NODE(10161, 63) {
    pnode->resizeTrigger(PhaseNode_CompareInt::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CostBuffAttribute>(PhaseNode_CompareInt::TRIGGER_EQUAL, 65, PhaseNode_CostBuffAttribute::FUNC_DO, &PhaseNode_CostBuffAttribute::Do);
    pnode->regTrigger<PhaseNode_CostBuffAttribute>(PhaseNode_CompareInt::TRIGGER_GREATER, 65, PhaseNode_CostBuffAttribute::FUNC_DO, &PhaseNode_CostBuffAttribute::Do);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_CompareInt::TRIGGER_LESS, 46, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(10161, 63) {
    auto node63 = GET_SKILL_NODE(63, PhaseNode_CompareInt);
    if (node63 == nullptr) {
        node63 = new PhaseNode_CompareInt(63, phase);
        node63->setB(5000);
        CALL_REGISTER_SKILL_NODE(10161, 63, node63)
    }
    if (noInit == true) {
        return node63;
    }
    auto node57 = GET_SKILL_NODE(57, PhaseNode_GetBuffAttribute);
    if (node57 != nullptr) node63->setA(node57->getValue());
    return node63;
}
//--------------------------------------------------------------------------------
// CostBuffAttribute
//
REGISTER_REGISTER_SKILL_NODE(10161, 65) {
    pnode->resizeTrigger(PhaseNode_CostBuffAttribute::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_CostBuffAttribute::TRIGGER_DONE, 72, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(10161, 65) {
    auto node65 = GET_SKILL_NODE(65, PhaseNode_CostBuffAttribute);
    if (node65 == nullptr) {
        node65 = new PhaseNode_CostBuffAttribute(65, phase);
        node65->setTarget(0U);
        node65->setAttribute(45);
        node65->setValue(5000);
        CALL_REGISTER_SKILL_NODE(10161, 65, node65)
    }
    if (noInit == true) {
        return node65;
    }
    return node65;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(10161, 72) {
    pnode->resizeTrigger(PhaseNode_SetBool::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_SetBool::TRIGGER_DONE, 46, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(10161, 72) {
    auto node72 = GET_SKILL_NODE(72, PhaseNode_SetBool);
    if (node72 == nullptr) {
        node72 = new PhaseNode_SetBool(72, phase);
        node72->setName("HaveEnergy");
        node72->setValue(true);
        CALL_REGISTER_SKILL_NODE(10161, 72, node72)
    }
    if (noInit == true) {
        return node72;
    }
    return node72;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(10161, 74) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_If::TRIGGER_FALSE, 31, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_If::TRIGGER_TRUE, 80, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
}

REGISTER_CREATE_SKILL_NODE(10161, 74) {
    auto node74 = GET_SKILL_NODE(74, PhaseNode_If);
    if (node74 == nullptr) {
        node74 = new PhaseNode_If(74, phase);
        CALL_REGISTER_SKILL_NODE(10161, 74, node74)
    }
    if (noInit == true) {
        return node74;
    }
    auto variables = node74->getVariables();
    if (variables != nullptr) {
        node74->setCondition(variables->getVariable<bool>(Variable_10161_HaveEnergy));
    }
    return node74;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(10161, 80) {
    pnode->resizeTrigger(PhaseNode_AddSkillBuffs::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_AddSkillBuffs::TRIGGER_DONE, 82, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(10161, 80) {
    auto node80 = GET_SKILL_NODE(80, PhaseNode_AddSkillBuffs);
    if (node80 == nullptr) {
        node80 = new PhaseNode_AddSkillBuffs(80, phase);
        node80->setConfigID({101611,101613});
        CALL_REGISTER_SKILL_NODE(10161, 80, node80)
    }
    if (noInit == true) {
        return node80;
    }
    auto node50 = GET_SKILL_NODE(50, PhaseNode_AreaCollisionNewPene);
    auto node96 = GET_SKILL_NODE(96, PhaseNode_GetActorAttribute);
    if (node50 != nullptr) node80->setTarget(node50->getColliders());
    if (node96 != nullptr) node80->setAttribute(node96->getAttribute());
    return node80;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(10161, 82) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_PlayEffect::TRIGGER_DONE, 84, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(10161, 82) {
    auto node82 = GET_SKILL_NODE(82, PhaseNode_PlayEffect);
    if (node82 == nullptr) {
        node82 = new PhaseNode_PlayEffect(82, phase);
        node82->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node82->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node82->setEffectID(101614);
        node82->setChangeColor(true);
        node82->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node82->getVars().reserve(3);
        node82->getVars().setVariable<float>(0, .00f);
        node82->getVars().setVariable<float>(1, .00f);
        node82->getVars().setVariable<float>(2, .00f);
        node82->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(10161, 82, node82)
    }
    if (noInit == true) {
        return node82;
    }
    auto node46 = GET_SKILL_NODE(46, PhaseNode_GetLocation);
    auto node48 = GET_SKILL_NODE(48, PhaseNode_GetInputRotation);
    if (node46 != nullptr) node82->getVars().setVariable<float>(0, node46->getX());
    if (node46 != nullptr) node82->getVars().setVariable<float>(1, node46->getY());
    if (node48 != nullptr) node82->setRotation(node48->getAngle());
    return node82;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(10161, 84) {
}

REGISTER_CREATE_SKILL_NODE(10161, 84) {
    auto node84 = GET_SKILL_NODE(84, PhaseNode_PlayEffect);
    if (node84 == nullptr) {
        node84 = new PhaseNode_PlayEffect(84, phase);
        node84->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node84->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node84->setEffectID(101615);
        node84->setChangeColor(true);
        node84->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node84->getVars().reserve(3);
        node84->getVars().setVariable<float>(0, .00f);
        node84->getVars().setVariable<float>(1, .00f);
        node84->getVars().setVariable<float>(2, .00f);
        node84->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(10161, 84, node84)
    }
    if (noInit == true) {
        return node84;
    }
    auto node46 = GET_SKILL_NODE(46, PhaseNode_GetLocation);
    auto node48 = GET_SKILL_NODE(48, PhaseNode_GetInputRotation);
    if (node46 != nullptr) node84->getVars().setVariable<float>(0, node46->getX());
    if (node46 != nullptr) node84->getVars().setVariable<float>(1, node46->getY());
    if (node48 != nullptr) node84->setRotation(node48->getAngle());
    return node84;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(10161, 86) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_FALSE, 53, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_TRUE, 82, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(10161, 86) {
    auto node86 = GET_SKILL_NODE(86, PhaseNode_If);
    if (node86 == nullptr) {
        node86 = new PhaseNode_If(86, phase);
        CALL_REGISTER_SKILL_NODE(10161, 86, node86)
    }
    if (noInit == true) {
        return node86;
    }
    auto variables = node86->getVariables();
    if (variables != nullptr) {
        node86->setCondition(variables->getVariable<bool>(Variable_10161_HaveEnergy));
    }
    return node86;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10161, 90) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlaySound::TRIGGER_DONE, 34, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10161, 90) {
    auto node90 = GET_SKILL_NODE(90, PhaseNode_PlaySound);
    if (node90 == nullptr) {
        node90 = new PhaseNode_PlaySound(90, phase);
        node90->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node90->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node90->setSoundID("SE_Hero135_SkillA_P1");
        node90->setTarget(0U);
        node90->setUsePos(false);
        node90->setPosX(.00f);
        node90->setPosY(.00f);
        node90->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10161, 90, node90)
    }
    if (noInit == true) {
        return node90;
    }
    return node90;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10161, 92) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AreaCollisionNewPene>(PhaseNode_PlaySound::TRIGGER_DONE, 50, PhaseNode_AreaCollisionNewPene::FUNC_DO, &PhaseNode_AreaCollisionNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(10161, 92) {
    auto node92 = GET_SKILL_NODE(92, PhaseNode_PlaySound);
    if (node92 == nullptr) {
        node92 = new PhaseNode_PlaySound(92, phase);
        node92->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node92->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node92->setSoundID("SE_Hero135_SkillA_P2");
        node92->setTarget(0U);
        node92->setUsePos(false);
        node92->setPosX(.00f);
        node92->setPosY(.00f);
        node92->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10161, 92, node92)
    }
    if (noInit == true) {
        return node92;
    }
    return node92;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(10161, 93) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_ResetCD::TRIGGER_DONE, 94, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10161, 93) {
    auto node93 = GET_SKILL_NODE(93, PhaseNode_ResetCD);
    if (node93 == nullptr) {
        node93 = new PhaseNode_ResetCD(93, phase);
        node93->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node93->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node93->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(10161, 93, node93)
    }
    if (noInit == true) {
        return node93;
    }
    return node93;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10161, 94) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_PlayAnimation::TRIGGER_DONE, 96, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(10161, 94) {
    auto node94 = GET_SKILL_NODE(94, PhaseNode_PlayAnimation);
    if (node94 == nullptr) {
        node94 = new PhaseNode_PlayAnimation(94, phase);
        node94->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node94->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node94->setTarget(0U);
        node94->setAnimation("Skill1S1");
        node94->setParameter("attack");
        node94->setValue(false);
        CALL_REGISTER_SKILL_NODE(10161, 94, node94)
    }
    if (noInit == true) {
        return node94;
    }
    return node94;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10161, 95) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Disable>(PhaseNode_PlaySound::TRIGGER_DONE, 14, PhaseNode_Disable::FUNC_DO, &PhaseNode_Disable::Do);
}

REGISTER_CREATE_SKILL_NODE(10161, 95) {
    auto node95 = GET_SKILL_NODE(95, PhaseNode_PlaySound);
    if (node95 == nullptr) {
        node95 = new PhaseNode_PlaySound(95, phase);
        node95->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node95->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node95->setSoundID("");
        node95->setTarget(0U);
        node95->setUsePos(false);
        node95->setPosX(.00f);
        node95->setPosY(.00f);
        node95->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10161, 95, node95)
    }
    if (noInit == true) {
        return node95;
    }
    return node95;
}
//--------------------------------------------------------------------------------
// GetActorAttribute
//
REGISTER_REGISTER_SKILL_NODE(10161, 96) {
    pnode->resizeTrigger(PhaseNode_GetActorAttribute::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 95, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10161, 96) {
    auto node96 = GET_SKILL_NODE(96, PhaseNode_GetActorAttribute);
    if (node96 == nullptr) {
        node96 = new PhaseNode_GetActorAttribute(96, phase);
        node96->setTarget(0U);
        node96->setType({});
        CALL_REGISTER_SKILL_NODE(10161, 96, node96)
    }
    if (noInit == true) {
        return node96;
    }
    return node96;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10161, 98) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_IsInterruptType>(PhaseNode_Detect::TRIGGER_ON, 104, PhaseNode_IsInterruptType::FUNC_DO, &PhaseNode_IsInterruptType::Do);
}

REGISTER_CREATE_SKILL_NODE(10161, 98) {
    auto node98 = GET_SKILL_NODE(98, PhaseNode_Detect);
    if (node98 == nullptr) {
        node98 = new PhaseNode_Detect(98, phase);
        node98->setSelf(0U);
        node98->setEvent("daduan_001");
        node98->setType(PhaseNode_Detect::Detect_Type::Interrupt_Skill);
        node98->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10161, 98, node98)
    }
    if (noInit == true) {
        return node98;
    }
    return node98;
}
//--------------------------------------------------------------------------------
// SwitchToInt
//
REGISTER_REGISTER_SKILL_NODE(10161, 99) {
    pnode->resizeTrigger(4);
    pnode->regTrigger<PhaseNode_EndPhase>(1, 36, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(10161, 99) {
    auto node99 = GET_SKILL_NODE(99, PhaseNode_SwitchToInt);
    if (node99 == nullptr) {
        node99 = new PhaseNode_SwitchToInt(99, phase);
        CALL_REGISTER_SKILL_NODE(10161, 99, node99)
    }
    if (noInit == true) {
        return node99;
    }
    auto variables = node99->getVariables();
    if (variables != nullptr) {
        node99->setSelection(variables->getVariable<int32_t>(Variable_10161_stop));
    }
    return node99;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10161, 101) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_RaiseEvent::TRIGGER_DONE, 110, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10161, 101) {
    auto node101 = GET_SKILL_NODE(101, PhaseNode_RaiseEvent);
    if (node101 == nullptr) {
        node101 = new PhaseNode_RaiseEvent(101, phase);
        node101->setEvent("daduan_001");
        node101->setTarget(0U);
        node101->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node101->setTypeParams(0, 0);
        node101->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10161, 101, node101)
    }
    if (noInit == true) {
        return node101;
    }
    return node101;
}
//--------------------------------------------------------------------------------
// StartPreInput
//
REGISTER_REGISTER_SKILL_NODE(10161, 102) {
    pnode->resizeTrigger(PhaseNode_StartPreInput::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_StartPreInput::TRIGGER_DONE, 106, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10161, 102) {
    auto node102 = GET_SKILL_NODE(102, PhaseNode_StartPreInput);
    if (node102 == nullptr) {
        node102 = new PhaseNode_StartPreInput(102, phase);
        node102->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node102->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node102->setDelayTime(.00f);
        CALL_REGISTER_SKILL_NODE(10161, 102, node102)
    }
    if (noInit == true) {
        return node102;
    }
    return node102;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(10161, 103) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_If::TRIGGER_TRUE, 105, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10161, 103) {
    auto node103 = GET_SKILL_NODE(103, PhaseNode_If);
    if (node103 == nullptr) {
        node103 = new PhaseNode_If(103, phase);
        CALL_REGISTER_SKILL_NODE(10161, 103, node103)
    }
    if (noInit == true) {
        return node103;
    }
    auto variables = node103->getVariables();
    if (variables != nullptr) {
        node103->setCondition(variables->getVariable<bool>(Variable_10161_InterruptAnimat));
    }
    return node103;
}
//--------------------------------------------------------------------------------
// IsInterruptType
//
REGISTER_REGISTER_SKILL_NODE(10161, 104) {
    pnode->resizeTrigger(PhaseNode_IsInterruptType::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SwitchToInt>(PhaseNode_IsInterruptType::TRIGGER_BUFF, 99, PhaseNode_SwitchToInt::FUNC_SWITCH, &PhaseNode_SwitchToInt::Switch);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_POSCHANGE, 103, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTAIM, 103, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTFIRE, 103, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTRELOAD, 103, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_USESKILL, 103, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(10161, 104) {
    auto node104 = GET_SKILL_NODE(104, PhaseNode_IsInterruptType);
    if (node104 == nullptr) {
        node104 = new PhaseNode_IsInterruptType(104, phase);
        node104->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node104->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10161, 104, node104)
    }
    if (noInit == true) {
        return node104;
    }
    auto node98 = GET_SKILL_NODE(98, PhaseNode_Detect);
    if (node98 != nullptr) node104->setType(node98->getVars().getVariable<int32_t>(2));
    return node104;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10161, 105) {
}

REGISTER_CREATE_SKILL_NODE(10161, 105) {
    auto node105 = GET_SKILL_NODE(105, PhaseNode_PlayAnimation);
    if (node105 == nullptr) {
        node105 = new PhaseNode_PlayAnimation(105, phase);
        node105->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node105->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node105->setTarget(0U);
        node105->setAnimation("Idle");
        node105->setParameter("");
        node105->setValue(false);
        CALL_REGISTER_SKILL_NODE(10161, 105, node105)
    }
    if (noInit == true) {
        return node105;
    }
    return node105;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10161, 106) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_Delay::TRIGGER_DONE, 109, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(10161, 106) {
    auto node106 = GET_SKILL_NODE(106, PhaseNode_Delay);
    if (node106 == nullptr) {
        node106 = new PhaseNode_Delay(106, phase);
        node106->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(10161, 106, node106)
    }
    if (noInit == true) {
        return node106;
    }
    return node106;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(10161, 109) {
}

REGISTER_CREATE_SKILL_NODE(10161, 109) {
    auto node109 = GET_SKILL_NODE(109, PhaseNode_SetBool);
    if (node109 == nullptr) {
        node109 = new PhaseNode_SetBool(109, phase);
        node109->setName("InterruptAnimat");
        node109->setValue(true);
        CALL_REGISTER_SKILL_NODE(10161, 109, node109)
    }
    if (noInit == true) {
        return node109;
    }
    return node109;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10161, 110) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StartPreInput>(PhaseNode_RaiseEvent::TRIGGER_DONE, 102, PhaseNode_StartPreInput::FUNC_DO, &PhaseNode_StartPreInput::Do);
}

REGISTER_CREATE_SKILL_NODE(10161, 110) {
    auto node110 = GET_SKILL_NODE(110, PhaseNode_RaiseEvent);
    if (node110 == nullptr) {
        node110 = new PhaseNode_RaiseEvent(110, phase);
        node110->setEvent("Dead_001");
        node110->setTarget(0U);
        node110->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node110->setTypeParams(0, 0);
        node110->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10161, 110, node110)
    }
    if (noInit == true) {
        return node110;
    }
    return node110;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10161, 111) {
}

REGISTER_CREATE_SKILL_NODE(10161, 111) {
    auto node111 = GET_SKILL_NODE(111, PhaseNode_Detect);
    if (node111 == nullptr) {
        node111 = new PhaseNode_Detect(111, phase);
        node111->setSelf(0U);
        node111->setEvent("Dead_001");
        node111->setType(PhaseNode_Detect::Detect_Type::Actor_Dead);
        node111->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10161, 111, node111)
    }
    if (noInit == true) {
        return node111;
    }
    return node111;
}

//--------------------------------------------------------------------------------
// SkillCreator_10161
//
class SkillCreator_10161 : public SkillCreator {
public:
    SkillCreator_10161() {}
    virtual ~SkillCreator_10161() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_10161

//--------------------------------------------------------------------------------
// SkillPhase_10161
//
class SkillPhase_10161 : public SkillPhase {
public:
    SkillPhase_10161(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_10161() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(10161, 5) // StartPhase
        CASE_CREATE_SKILL_NODE(10161, 14) // Disable
        CASE_CREATE_SKILL_NODE(10161, 29) // Delay
        CASE_CREATE_SKILL_NODE(10161, 31) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(10161, 34) // Delay
        CASE_CREATE_SKILL_NODE(10161, 36) // EndPhase
        CASE_CREATE_SKILL_NODE(10161, 40) // SetInt
        CASE_CREATE_SKILL_NODE(10161, 46) // GetLocation
        CASE_CREATE_SKILL_NODE(10161, 48) // GetInputRotation
        CASE_CREATE_SKILL_NODE(10161, 50) // AreaCollisionNewPene
        CASE_CREATE_SKILL_NODE(10161, 53) // PlayEffect
        CASE_CREATE_SKILL_NODE(10161, 55) // PlayEffect
        CASE_CREATE_SKILL_NODE(10161, 57) // GetBuffAttribute
        CASE_CREATE_SKILL_NODE(10161, 63) // CompareInt
        CASE_CREATE_SKILL_NODE(10161, 65) // CostBuffAttribute
        CASE_CREATE_SKILL_NODE(10161, 72) // SetBool
        CASE_CREATE_SKILL_NODE(10161, 74) // If
        CASE_CREATE_SKILL_NODE(10161, 80) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(10161, 82) // PlayEffect
        CASE_CREATE_SKILL_NODE(10161, 84) // PlayEffect
        CASE_CREATE_SKILL_NODE(10161, 86) // If
        CASE_CREATE_SKILL_NODE(10161, 90) // PlaySound
        CASE_CREATE_SKILL_NODE(10161, 92) // PlaySound
        CASE_CREATE_SKILL_NODE(10161, 93) // ResetCD
        CASE_CREATE_SKILL_NODE(10161, 94) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10161, 95) // PlaySound
        CASE_CREATE_SKILL_NODE(10161, 96) // GetActorAttribute
        CASE_CREATE_SKILL_NODE(10161, 98) // Detect
        CASE_CREATE_SKILL_NODE(10161, 99) // SwitchToInt
        CASE_CREATE_SKILL_NODE(10161, 101) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10161, 102) // StartPreInput
        CASE_CREATE_SKILL_NODE(10161, 103) // If
        CASE_CREATE_SKILL_NODE(10161, 104) // IsInterruptType
        CASE_CREATE_SKILL_NODE(10161, 105) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10161, 106) // Delay
        CASE_CREATE_SKILL_NODE(10161, 109) // SetBool
        CASE_CREATE_SKILL_NODE(10161, 110) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10161, 111) // Detect
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_10161

SkillLogic* SkillCreator_10161::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //设置变量
    Variable_10161_HaveEnergy = logic->getVariables().setVariable<bool>("HaveEnergy");
    Variable_10161_stop = logic->getVariables().setVariable<int32_t>("stop", 1);
    Variable_10161_InterruptAnimat = logic->getVariables().setVariable<bool>("InterruptAnimat");
    //创建阶段phase
    auto phase = new SkillPhase_10161(1, logic, 2);
    //设置phase执行器
    phase->setRunPhaseNode(1, 5);
    phase->setDetectPhaseNode(2, 98);
    phase->setDetectPhaseNode(2, 111);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_10161::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
