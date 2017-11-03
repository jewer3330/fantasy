#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

#include "skill_psnode_addskillbuff.h"
#include "skill_psnode_camerashake.h"
#include "skill_psnode_comparefloat.h"
#include "skill_psnode_compareint.h"
#include "skill_psnode_delay.h"
#include "skill_psnode_detect.h"
#include "skill_psnode_getlocation.h"
#include "skill_psnode_getrotation.h"
#include "skill_psnode_if.h"
#include "skill_psnode_intoperation.h"
#include "skill_psnode_playanimation.h"
#include "skill_psnode_playeffect.h"
#include "skill_psnode_playsound.h"
#include "skill_psnode_raiseevent.h"
#include "skill_psnode_removeskillbuff.h"
#include "skill_psnode_setbool.h"
#include "skill_psnode_setint.h"
#include "skill_psnode_skillendnotify.h"
#include "skill_psnode_startphase.h"

namespace pvp {

//变量声明
uint64_t Variable_20040_Damage = 0;
uint64_t Variable_20040_EnableDmg = 0;
uint64_t Variable_20040_Effect = 0;
//--------------------------------------------------------------------------------
// StartPhase
//
REGISTER_REGISTER_SKILL_NODE(20040, 2) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_StartPhase::TRIGGER_START, 4, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(20040, 2) {
    auto node2 = GET_SKILL_NODE(2, PhaseNode_StartPhase);
    if (node2 == nullptr) {
        node2 = new PhaseNode_StartPhase(2, phase);
        CALL_REGISTER_SKILL_NODE(20040, 2, node2)
    }
    if (noInit == true) {
        return node2;
    }
    return node2;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(20040, 4) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_PlayAnimation::TRIGGER_DONE, 6, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(20040, 4) {
    auto node4 = GET_SKILL_NODE(4, PhaseNode_PlayAnimation);
    if (node4 == nullptr) {
        node4 = new PhaseNode_PlayAnimation(4, phase);
        node4->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node4->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node4->setTarget(0U);
        node4->setAnimation("Skill4S1");
        node4->setParameter("");
        node4->setValue(false);
        CALL_REGISTER_SKILL_NODE(20040, 4, node4)
    }
    if (noInit == true) {
        return node4;
    }
    return node4;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(20040, 6) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetRotation>(PhaseNode_GetLocation::TRIGGER_DONE, 8, PhaseNode_GetRotation::FUNC_DO, &PhaseNode_GetRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(20040, 6) {
    auto node6 = GET_SKILL_NODE(6, PhaseNode_GetLocation);
    if (node6 == nullptr) {
        node6 = new PhaseNode_GetLocation(6, phase);
        node6->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node6->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(20040, 6, node6)
    }
    if (noInit == true) {
        return node6;
    }
    return node6;
}
//--------------------------------------------------------------------------------
// GetRotation
//
REGISTER_REGISTER_SKILL_NODE(20040, 8) {
    pnode->resizeTrigger(PhaseNode_GetRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_GetRotation::TRIGGER_DONE, 28, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(20040, 8) {
    auto node8 = GET_SKILL_NODE(8, PhaseNode_GetRotation);
    if (node8 == nullptr) {
        node8 = new PhaseNode_GetRotation(8, phase);
        node8->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node8->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(20040, 8, node8)
    }
    if (noInit == true) {
        return node8;
    }
    return node8;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(20040, 16) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_Delay::TRIGGER_DONE, 36, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(20040, 16) {
    auto node16 = GET_SKILL_NODE(16, PhaseNode_Delay);
    if (node16 == nullptr) {
        node16 = new PhaseNode_Delay(16, phase);
        node16->setTime(1.35f);
        CALL_REGISTER_SKILL_NODE(20040, 16, node16)
    }
    if (noInit == true) {
        return node16;
    }
    return node16;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(20040, 24) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlaySound::TRIGGER_DONE, 16, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(20040, 24) {
    auto node24 = GET_SKILL_NODE(24, PhaseNode_PlaySound);
    if (node24 == nullptr) {
        node24 = new PhaseNode_PlaySound(24, phase);
        node24->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node24->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node24->setSoundID("VO_MON2004_Birth");
        node24->setTarget(0U);
        node24->setUsePos(false);
        node24->setPosX(.00f);
        node24->setPosY(.00f);
        node24->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(20040, 24, node24)
    }
    if (noInit == true) {
        return node24;
    }
    return node24;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(20040, 28) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlayEffect::TRIGGER_DONE, 30, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(20040, 28) {
    auto node28 = GET_SKILL_NODE(28, PhaseNode_PlayEffect);
    if (node28 == nullptr) {
        node28 = new PhaseNode_PlayEffect(28, phase);
        node28->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node28->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node28->setEffectID(1023);
        node28->setChangeColor(false);
        node28->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node28->getVars().reserve(3);
        node28->getVars().setVariable<float>(0, .00f);
        node28->getVars().setVariable<float>(1, .00f);
        node28->getVars().setVariable<float>(2, .00f);
        node28->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(20040, 28, node28)
    }
    if (noInit == true) {
        return node28;
    }
    auto node6 = GET_SKILL_NODE(6, PhaseNode_GetLocation);
    auto node8 = GET_SKILL_NODE(8, PhaseNode_GetRotation);
    if (node6 != nullptr) node28->getVars().setVariable<float>(0, node6->getX());
    if (node6 != nullptr) node28->getVars().setVariable<float>(1, node6->getY());
    if (node8 != nullptr) node28->setRotation(node8->getAngle());
    return node28;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(20040, 30) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CameraShake>(PhaseNode_Delay::TRIGGER_DONE, 42, PhaseNode_CameraShake::FUNC_DO, &PhaseNode_CameraShake::Do);
}

REGISTER_CREATE_SKILL_NODE(20040, 30) {
    auto node30 = GET_SKILL_NODE(30, PhaseNode_Delay);
    if (node30 == nullptr) {
        node30 = new PhaseNode_Delay(30, phase);
        node30->setTime(.45f);
        CALL_REGISTER_SKILL_NODE(20040, 30, node30)
    }
    if (noInit == true) {
        return node30;
    }
    return node30;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(20040, 36) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_PlayAnimation::TRIGGER_DONE, 71, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(20040, 36) {
    auto node36 = GET_SKILL_NODE(36, PhaseNode_PlayAnimation);
    if (node36 == nullptr) {
        node36 = new PhaseNode_PlayAnimation(36, phase);
        node36->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node36->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node36->setTarget(0U);
        node36->setAnimation("Idle");
        node36->setParameter("");
        node36->setValue(false);
        CALL_REGISTER_SKILL_NODE(20040, 36, node36)
    }
    if (noInit == true) {
        return node36;
    }
    return node36;
}
//--------------------------------------------------------------------------------
// CameraShake
//
REGISTER_REGISTER_SKILL_NODE(20040, 42) {
    pnode->resizeTrigger(PhaseNode_CameraShake::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_CameraShake::TRIGGER_DONE, 24, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(20040, 42) {
    auto node42 = GET_SKILL_NODE(42, PhaseNode_CameraShake);
    if (node42 == nullptr) {
        node42 = new PhaseNode_CameraShake(42, phase);
        node42->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node42->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node42->setTarget(0U);
        node42->setFrequency(.15f);
        node42->setAmplitude(4.00f);
        node42->setDuration(.90f);
        node42->setFalloff(true);
        CALL_REGISTER_SKILL_NODE(20040, 42, node42)
    }
    if (noInit == true) {
        return node42;
    }
    return node42;
}
//--------------------------------------------------------------------------------
// CompareInt
//
REGISTER_REGISTER_SKILL_NODE(20040, 44) {
    pnode->resizeTrigger(PhaseNode_CompareInt::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_CompareInt::TRIGGER_EQUAL, 45, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_CompareInt::TRIGGER_GREATER, 45, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(20040, 44) {
    auto node44 = GET_SKILL_NODE(44, PhaseNode_CompareInt);
    if (node44 == nullptr) {
        node44 = new PhaseNode_CompareInt(44, phase);
        node44->setB(60);
        CALL_REGISTER_SKILL_NODE(20040, 44, node44)
    }
    if (noInit == true) {
        return node44;
    }
    auto variables = node44->getVariables();
    if (variables != nullptr) {
        node44->setA(variables->getVariable<int32_t>(Variable_20040_Damage));
    }
    return node44;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(20040, 45) {
    pnode->resizeTrigger(PhaseNode_SetBool::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetInt>(PhaseNode_SetBool::TRIGGER_DONE, 46, PhaseNode_SetInt::FUNC_SET, &PhaseNode_SetInt::Set);
}

REGISTER_CREATE_SKILL_NODE(20040, 45) {
    auto node45 = GET_SKILL_NODE(45, PhaseNode_SetBool);
    if (node45 == nullptr) {
        node45 = new PhaseNode_SetBool(45, phase);
        node45->setName("EnableDmg");
        node45->setValue(false);
        CALL_REGISTER_SKILL_NODE(20040, 45, node45)
    }
    if (noInit == true) {
        return node45;
    }
    return node45;
}
//--------------------------------------------------------------------------------
// SetInt
//
REGISTER_REGISTER_SKILL_NODE(20040, 46) {
    pnode->resizeTrigger(PhaseNode_SetInt::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_SetInt::TRIGGER_DONE, 47, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(20040, 46) {
    auto node46 = GET_SKILL_NODE(46, PhaseNode_SetInt);
    if (node46 == nullptr) {
        node46 = new PhaseNode_SetInt(46, phase);
        node46->setName("Damage");
        node46->setValue(0);
        CALL_REGISTER_SKILL_NODE(20040, 46, node46)
    }
    if (noInit == true) {
        return node46;
    }
    return node46;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(20040, 47) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuff>(PhaseNode_PlayAnimation::TRIGGER_DONE, 61, PhaseNode_AddSkillBuff::FUNC_ADD, &PhaseNode_AddSkillBuff::Add);
}

REGISTER_CREATE_SKILL_NODE(20040, 47) {
    auto node47 = GET_SKILL_NODE(47, PhaseNode_PlayAnimation);
    if (node47 == nullptr) {
        node47 = new PhaseNode_PlayAnimation(47, phase);
        node47->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node47->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node47->setTarget(0U);
        node47->setAnimation("Hurt");
        node47->setParameter("");
        node47->setValue(false);
        CALL_REGISTER_SKILL_NODE(20040, 47, node47)
    }
    if (noInit == true) {
        return node47;
    }
    return node47;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(20040, 48) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlayEffect::TRIGGER_DONE, 63, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(20040, 48) {
    auto node48 = GET_SKILL_NODE(48, PhaseNode_PlayEffect);
    if (node48 == nullptr) {
        node48 = new PhaseNode_PlayEffect(48, phase);
        node48->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node48->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node48->setEffectID(0);
        node48->setChangeColor(false);
        node48->setType(PhaseNode_PlayEffect::PlayEffect_Type::WithTarget);
        node48->getVars().reserve(5);
        node48->getVars().setVariable<uint64_t>(0, 0U);
        node48->getVars().setVariable<std::string>(1, "");
        node48->getVars().setVariable<float>(2, .00f);
        node48->getVars().setVariable<float>(3, .00f);
        node48->getVars().setVariable<float>(4, .00f);
        node48->setRotation(.00f);
        node48->setScale(.00f);
        CALL_REGISTER_SKILL_NODE(20040, 48, node48)
    }
    if (noInit == true) {
        return node48;
    }
    return node48;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(20040, 49) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_Delay::TRIGGER_DONE, 50, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(20040, 49) {
    auto node49 = GET_SKILL_NODE(49, PhaseNode_Delay);
    if (node49 == nullptr) {
        node49 = new PhaseNode_Delay(49, phase);
        node49->setTime(.67f);
        CALL_REGISTER_SKILL_NODE(20040, 49, node49)
    }
    if (noInit == true) {
        return node49;
    }
    return node49;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(20040, 50) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RemoveSkillBuff>(PhaseNode_PlayAnimation::TRIGGER_DONE, 51, PhaseNode_RemoveSkillBuff::FUNC_REMOVE, &PhaseNode_RemoveSkillBuff::Remove);
}

REGISTER_CREATE_SKILL_NODE(20040, 50) {
    auto node50 = GET_SKILL_NODE(50, PhaseNode_PlayAnimation);
    if (node50 == nullptr) {
        node50 = new PhaseNode_PlayAnimation(50, phase);
        node50->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node50->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node50->setTarget(0U);
        node50->setAnimation("Idle");
        node50->setParameter("");
        node50->setValue(false);
        CALL_REGISTER_SKILL_NODE(20040, 50, node50)
    }
    if (noInit == true) {
        return node50;
    }
    return node50;
}
//--------------------------------------------------------------------------------
// RemoveSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(20040, 51) {
    pnode->resizeTrigger(PhaseNode_RemoveSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_RemoveSkillBuff::TRIGGER_DONE, 69, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(20040, 51) {
    auto node51 = GET_SKILL_NODE(51, PhaseNode_RemoveSkillBuff);
    if (node51 == nullptr) {
        node51 = new PhaseNode_RemoveSkillBuff(51, phase);
        node51->setBuffID(0U);
        node51->setBuffIDs({});
        node51->setConfigID(1);
        node51->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(20040, 51, node51)
    }
    if (noInit == true) {
        return node51;
    }
    return node51;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(20040, 52) {
}

REGISTER_CREATE_SKILL_NODE(20040, 52) {
    auto node52 = GET_SKILL_NODE(52, PhaseNode_SetBool);
    if (node52 == nullptr) {
        node52 = new PhaseNode_SetBool(52, phase);
        node52->setName("EnableDmg");
        node52->setValue(true);
        CALL_REGISTER_SKILL_NODE(20040, 52, node52)
    }
    if (noInit == true) {
        return node52;
    }
    return node52;
}
//--------------------------------------------------------------------------------
// IntOperation
//
REGISTER_REGISTER_SKILL_NODE(20040, 54) {
    pnode->resizeTrigger(PhaseNode_IntOperation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetInt>(PhaseNode_IntOperation::TRIGGER_DONE, 55, PhaseNode_SetInt::FUNC_SET, &PhaseNode_SetInt::Set);
}

REGISTER_CREATE_SKILL_NODE(20040, 54) {
    auto node54 = GET_SKILL_NODE(54, PhaseNode_IntOperation);
    if (node54 == nullptr) {
        node54 = new PhaseNode_IntOperation(54, phase);
        node54->setMethod(PhaseNode_IntOperation::IntOperation_Method::Add);
        CALL_REGISTER_SKILL_NODE(20040, 54, node54)
    }
    if (noInit == true) {
        return node54;
    }
    auto variables = node54->getVariables();
    if (variables != nullptr) {
        node54->setBase(variables->getVariable<int32_t>(Variable_20040_Damage));
    }
    auto node72 = GET_SKILL_NODE(72, PhaseNode_Detect);
    if (node72 != nullptr) node54->setValue(node72->getVars().getVariable<int32_t>(0));
    return node54;
}
//--------------------------------------------------------------------------------
// SetInt
//
REGISTER_REGISTER_SKILL_NODE(20040, 55) {
    pnode->resizeTrigger(PhaseNode_SetInt::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareInt>(PhaseNode_SetInt::TRIGGER_DONE, 44, PhaseNode_CompareInt::FUNC_COMPARE, &PhaseNode_CompareInt::Compare);
}

REGISTER_CREATE_SKILL_NODE(20040, 55) {
    auto node55 = GET_SKILL_NODE(55, PhaseNode_SetInt);
    if (node55 == nullptr) {
        node55 = new PhaseNode_SetInt(55, phase);
        node55->setName("Damage");
        CALL_REGISTER_SKILL_NODE(20040, 55, node55)
    }
    if (noInit == true) {
        return node55;
    }
    auto node54 = GET_SKILL_NODE(54, PhaseNode_IntOperation);
    if (node54 != nullptr) node55->setValue(node54->getFinal());
    return node55;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(20040, 57) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareInt>(PhaseNode_If::TRIGGER_TRUE, 62, PhaseNode_CompareInt::FUNC_COMPARE, &PhaseNode_CompareInt::Compare);
}

REGISTER_CREATE_SKILL_NODE(20040, 57) {
    auto node57 = GET_SKILL_NODE(57, PhaseNode_If);
    if (node57 == nullptr) {
        node57 = new PhaseNode_If(57, phase);
        CALL_REGISTER_SKILL_NODE(20040, 57, node57)
    }
    if (noInit == true) {
        return node57;
    }
    auto variables = node57->getVariables();
    if (variables != nullptr) {
        node57->setCondition(variables->getVariable<bool>(Variable_20040_EnableDmg));
    }
    return node57;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(20040, 58) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_Delay::TRIGGER_DONE, 52, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(20040, 58) {
    auto node58 = GET_SKILL_NODE(58, PhaseNode_Delay);
    if (node58 == nullptr) {
        node58 = new PhaseNode_Delay(58, phase);
        node58->setTime(1.00f);
        CALL_REGISTER_SKILL_NODE(20040, 58, node58)
    }
    if (noInit == true) {
        return node58;
    }
    return node58;
}
//--------------------------------------------------------------------------------
// AddSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(20040, 61) {
    pnode->resizeTrigger(PhaseNode_AddSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_AddSkillBuff::TRIGGER_DONE, 49, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(20040, 61) {
    auto node61 = GET_SKILL_NODE(61, PhaseNode_AddSkillBuff);
    if (node61 == nullptr) {
        node61 = new PhaseNode_AddSkillBuff(61, phase);
        node61->setConfigID(1);
        node61->setConfigIDs({});
        node61->setTarget(0U);
        node61->setAttribute({{}});
        CALL_REGISTER_SKILL_NODE(20040, 61, node61)
    }
    if (noInit == true) {
        return node61;
    }
    return node61;
}
//--------------------------------------------------------------------------------
// CompareInt
//
REGISTER_REGISTER_SKILL_NODE(20040, 62) {
    pnode->resizeTrigger(PhaseNode_CompareInt::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_IntOperation>(PhaseNode_CompareInt::TRIGGER_EQUAL, 54, PhaseNode_IntOperation::FUNC_OPERATION, &PhaseNode_IntOperation::Operation);
    pnode->regTrigger<PhaseNode_IntOperation>(PhaseNode_CompareInt::TRIGGER_GREATER, 54, PhaseNode_IntOperation::FUNC_OPERATION, &PhaseNode_IntOperation::Operation);
}

REGISTER_CREATE_SKILL_NODE(20040, 62) {
    auto node62 = GET_SKILL_NODE(62, PhaseNode_CompareInt);
    if (node62 == nullptr) {
        node62 = new PhaseNode_CompareInt(62, phase);
        node62->setB(10);
        CALL_REGISTER_SKILL_NODE(20040, 62, node62)
    }
    if (noInit == true) {
        return node62;
    }
    auto node72 = GET_SKILL_NODE(72, PhaseNode_Detect);
    if (node72 != nullptr) node62->setA(node72->getVars().getVariable<int32_t>(0));
    return node62;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(20040, 63) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_Delay::TRIGGER_DONE, 68, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(20040, 63) {
    auto node63 = GET_SKILL_NODE(63, PhaseNode_Delay);
    if (node63 == nullptr) {
        node63 = new PhaseNode_Delay(63, phase);
        node63->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(20040, 63, node63)
    }
    if (noInit == true) {
        return node63;
    }
    return node63;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(20040, 65) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_If::TRIGGER_TRUE, 67, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(20040, 65) {
    auto node65 = GET_SKILL_NODE(65, PhaseNode_If);
    if (node65 == nullptr) {
        node65 = new PhaseNode_If(65, phase);
        CALL_REGISTER_SKILL_NODE(20040, 65, node65)
    }
    if (noInit == true) {
        return node65;
    }
    auto variables = node65->getVariables();
    if (variables != nullptr) {
        node65->setCondition(variables->getVariable<bool>(Variable_20040_Effect));
    }
    return node65;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(20040, 67) {
    pnode->resizeTrigger(PhaseNode_SetBool::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_SetBool::TRIGGER_DONE, 48, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(20040, 67) {
    auto node67 = GET_SKILL_NODE(67, PhaseNode_SetBool);
    if (node67 == nullptr) {
        node67 = new PhaseNode_SetBool(67, phase);
        node67->setName("Effect");
        node67->setValue(false);
        CALL_REGISTER_SKILL_NODE(20040, 67, node67)
    }
    if (noInit == true) {
        return node67;
    }
    return node67;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(20040, 68) {
}

REGISTER_CREATE_SKILL_NODE(20040, 68) {
    auto node68 = GET_SKILL_NODE(68, PhaseNode_SetBool);
    if (node68 == nullptr) {
        node68 = new PhaseNode_SetBool(68, phase);
        node68->setName("Effect");
        node68->setValue(true);
        CALL_REGISTER_SKILL_NODE(20040, 68, node68)
    }
    if (noInit == true) {
        return node68;
    }
    return node68;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(20040, 69) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 52, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_GREATER, 58, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(20040, 69) {
    auto node69 = GET_SKILL_NODE(69, PhaseNode_CompareFloat);
    if (node69 == nullptr) {
        node69 = new PhaseNode_CompareFloat(69, phase);
        node69->setA(1.00f);
        node69->setB(.00f);
        CALL_REGISTER_SKILL_NODE(20040, 69, node69)
    }
    if (noInit == true) {
        return node69;
    }
    return node69;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(20040, 70) {
}

REGISTER_CREATE_SKILL_NODE(20040, 70) {
    auto node70 = GET_SKILL_NODE(70, PhaseNode_SkillEndNotify);
    if (node70 == nullptr) {
        node70 = new PhaseNode_SkillEndNotify(70, phase);
        node70->setReturnType(true);
        CALL_REGISTER_SKILL_NODE(20040, 70, node70)
    }
    if (noInit == true) {
        return node70;
    }
    return node70;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(20040, 71) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_RaiseEvent::TRIGGER_DONE, 70, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
}

REGISTER_CREATE_SKILL_NODE(20040, 71) {
    auto node71 = GET_SKILL_NODE(71, PhaseNode_RaiseEvent);
    if (node71 == nullptr) {
        node71 = new PhaseNode_RaiseEvent(71, phase);
        node71->setEvent("GetDamage");
        node71->setTarget(0U);
        node71->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node71->setTypeParams(0, 0);
        node71->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(20040, 71, node71)
    }
    if (noInit == true) {
        return node71;
    }
    return node71;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(20040, 72) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_Detect::TRIGGER_ON, 57, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_Detect::TRIGGER_ON, 65, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(20040, 72) {
    auto node72 = GET_SKILL_NODE(72, PhaseNode_Detect);
    if (node72 == nullptr) {
        node72 = new PhaseNode_Detect(72, phase);
        node72->setSelf(0U);
        node72->setEvent("GetDamage");
        node72->setType(PhaseNode_Detect::Detect_Type::Damage);
        node72->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(20040, 72, node72)
    }
    if (noInit == true) {
        return node72;
    }
    return node72;
}

//--------------------------------------------------------------------------------
// SkillCreator_20040
//
class SkillCreator_20040 : public SkillCreator {
public:
    SkillCreator_20040() {}
    virtual ~SkillCreator_20040() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_20040

//--------------------------------------------------------------------------------
// SkillPhase_20040
//
class SkillPhase_20040 : public SkillPhase {
public:
    SkillPhase_20040(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_20040() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(20040, 2) // StartPhase
        CASE_CREATE_SKILL_NODE(20040, 4) // PlayAnimation
        CASE_CREATE_SKILL_NODE(20040, 6) // GetLocation
        CASE_CREATE_SKILL_NODE(20040, 8) // GetRotation
        CASE_CREATE_SKILL_NODE(20040, 16) // Delay
        CASE_CREATE_SKILL_NODE(20040, 24) // PlaySound
        CASE_CREATE_SKILL_NODE(20040, 28) // PlayEffect
        CASE_CREATE_SKILL_NODE(20040, 30) // Delay
        CASE_CREATE_SKILL_NODE(20040, 36) // PlayAnimation
        CASE_CREATE_SKILL_NODE(20040, 42) // CameraShake
        CASE_CREATE_SKILL_NODE(20040, 44) // CompareInt
        CASE_CREATE_SKILL_NODE(20040, 45) // SetBool
        CASE_CREATE_SKILL_NODE(20040, 46) // SetInt
        CASE_CREATE_SKILL_NODE(20040, 47) // PlayAnimation
        CASE_CREATE_SKILL_NODE(20040, 48) // PlayEffect
        CASE_CREATE_SKILL_NODE(20040, 49) // Delay
        CASE_CREATE_SKILL_NODE(20040, 50) // PlayAnimation
        CASE_CREATE_SKILL_NODE(20040, 51) // RemoveSkillBuff
        CASE_CREATE_SKILL_NODE(20040, 52) // SetBool
        CASE_CREATE_SKILL_NODE(20040, 54) // IntOperation
        CASE_CREATE_SKILL_NODE(20040, 55) // SetInt
        CASE_CREATE_SKILL_NODE(20040, 57) // If
        CASE_CREATE_SKILL_NODE(20040, 58) // Delay
        CASE_CREATE_SKILL_NODE(20040, 61) // AddSkillBuff
        CASE_CREATE_SKILL_NODE(20040, 62) // CompareInt
        CASE_CREATE_SKILL_NODE(20040, 63) // Delay
        CASE_CREATE_SKILL_NODE(20040, 65) // If
        CASE_CREATE_SKILL_NODE(20040, 67) // SetBool
        CASE_CREATE_SKILL_NODE(20040, 68) // SetBool
        CASE_CREATE_SKILL_NODE(20040, 69) // CompareFloat
        CASE_CREATE_SKILL_NODE(20040, 70) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(20040, 71) // RaiseEvent
        CASE_CREATE_SKILL_NODE(20040, 72) // Detect
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_20040

SkillLogic* SkillCreator_20040::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //设置变量
    Variable_20040_Damage = logic->getVariables().setVariable<int32_t>("Damage");
    Variable_20040_EnableDmg = logic->getVariables().setVariable<bool>("EnableDmg", true);
    Variable_20040_Effect = logic->getVariables().setVariable<bool>("Effect", true);
    //创建阶段phase
    auto phase = new SkillPhase_20040(1, logic, 2);
    //设置phase执行器
    phase->setRunPhaseNode(1, 2);
    phase->setDetectPhaseNode(2, 72);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_20040::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
