#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

#include "skill_psnode_addskillbuff.h"
#include "skill_psnode_attachto.h"
#include "skill_psnode_cameraxyzshake.h"
#include "skill_psnode_delay.h"
#include "skill_psnode_destroycollider.h"
#include "skill_psnode_detect.h"
#include "skill_psnode_disable.h"
#include "skill_psnode_endphase.h"
#include "skill_psnode_getactorattribute.h"
#include "skill_psnode_getinputobject.h"
#include "skill_psnode_getlinerotation.h"
#include "skill_psnode_getlocation.h"
#include "skill_psnode_if.h"
#include "skill_psnode_isinterrupttype.h"
#include "skill_psnode_movenewpene.h"
#include "skill_psnode_offsetcalculate.h"
#include "skill_psnode_playanimation.h"
#include "skill_psnode_playeffect.h"
#include "skill_psnode_playsound.h"
#include "skill_psnode_raiseevent.h"
#include "skill_psnode_resetcd.h"
#include "skill_psnode_setbool.h"
#include "skill_psnode_setint.h"
#include "skill_psnode_setrotation.h"
#include "skill_psnode_spawncollider.h"
#include "skill_psnode_startphase.h"
#include "skill_psnode_startpreinput.h"
#include "skill_psnode_switchtoint.h"
#include "skill_psnode_triggerupdate.h"

namespace pvp {

//变量声明
uint64_t Variable_10342_Break = 0;
uint64_t Variable_10342_InterruptAnimat = 0;
//--------------------------------------------------------------------------------
// StartPhase
//
REGISTER_REGISTER_SKILL_NODE(10342, 5) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_StartPhase::TRIGGER_START, 117, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(10342, 5) {
    auto node5 = GET_SKILL_NODE(5, PhaseNode_StartPhase);
    if (node5 == nullptr) {
        node5 = new PhaseNode_StartPhase(5, phase);
        CALL_REGISTER_SKILL_NODE(10342, 5, node5)
    }
    if (noInit == true) {
        return node5;
    }
    return node5;
}
//--------------------------------------------------------------------------------
// Disable
//
REGISTER_REGISTER_SKILL_NODE(10342, 9) {
    pnode->resizeTrigger(PhaseNode_Disable::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuff>(PhaseNode_Disable::TRIGGER_DONE, 61, PhaseNode_AddSkillBuff::FUNC_ADD, &PhaseNode_AddSkillBuff::Add);
}

REGISTER_CREATE_SKILL_NODE(10342, 9) {
    auto node9 = GET_SKILL_NODE(9, PhaseNode_Disable);
    if (node9 == nullptr) {
        node9 = new PhaseNode_Disable(9, phase);
        node9->setTarget(0U);
        node9->setMove(true);
        node9->setSkill(true);
        node9->setShoot(true);
        node9->setTime(.50f);
        node9->setRotate(true);
        CALL_REGISTER_SKILL_NODE(10342, 9, node9)
    }
    if (noInit == true) {
        return node9;
    }
    return node9;
}
//--------------------------------------------------------------------------------
// SpawnCollider
//
REGISTER_REGISTER_SKILL_NODE(10342, 12) {
    pnode->resizeTrigger(PhaseNode_SpawnCollider::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AttachTo>(PhaseNode_SpawnCollider::TRIGGER_DONE, 24, PhaseNode_AttachTo::FUNC_DO, &PhaseNode_AttachTo::Do);
}

REGISTER_CREATE_SKILL_NODE(10342, 12) {
    auto node12 = GET_SKILL_NODE(12, PhaseNode_SpawnCollider);
    if (node12 == nullptr) {
        node12 = new PhaseNode_SpawnCollider(12, phase);
        node12->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node12->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node12->setMesh("");
        node12->setMeshScale(1.00f);
        node12->setEffectID(0);
        node12->setEffectScale(.00f);
        node12->setType(PhaseNode_SpawnCollider::SpawnCollider_Type::Circle);
        node12->setTypeParams(0, 2.00f);
        node12->setTime(.00f);
        node12->setPosZ(.00f);
        node12->setRotation(.00f);
        node12->setreentry(false);
        node12->setCheckPeneSound(false);
        CALL_REGISTER_SKILL_NODE(10342, 12, node12)
    }
    if (noInit == true) {
        return node12;
    }
    auto node26 = GET_SKILL_NODE(26, PhaseNode_GetLocation);
    if (node26 != nullptr) node12->setPosX(node26->getX());
    if (node26 != nullptr) node12->setPosY(node26->getY());
    return node12;
}
//--------------------------------------------------------------------------------
// MoveNewPene
//
REGISTER_REGISTER_SKILL_NODE(10342, 22) {
    pnode->resizeTrigger(PhaseNode_MoveNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetRotation>(PhaseNode_MoveNewPene::TRIGGER_BLOCKBYWALL, 80, PhaseNode_SetRotation::FUNC_DO, &PhaseNode_SetRotation::Do);
    pnode->regTrigger<PhaseNode_SetRotation>(PhaseNode_MoveNewPene::TRIGGER_DONE, 80, PhaseNode_SetRotation::FUNC_DO, &PhaseNode_SetRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(10342, 22) {
    auto node22 = GET_SKILL_NODE(22, PhaseNode_MoveNewPene);
    if (node22 == nullptr) {
        node22 = new PhaseNode_MoveNewPene(22, phase);
        node22->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node22->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node22->setPeneType(PhaseNode_MoveNewPene::MoveNewPene_PeneType::Move);
        node22->setPeneValue(25);
        node22->setType(PhaseNode_MoveNewPene::MoveNewPene_Type::Teleport);
        node22->getVars().reserve(2);
        node22->getVars().setVariable<float>(0, .00f);
        node22->getVars().setVariable<float>(1, .00f);
        node22->setreentry(false);
        node22->setStopWhenFail(true);
        node22->setCheckFaction(PhaseNode_MoveNewPene::MoveNewPene_CheckFaction::Enemy);
        CALL_REGISTER_SKILL_NODE(10342, 22, node22)
    }
    if (noInit == true) {
        return node22;
    }
    auto node12 = GET_SKILL_NODE(12, PhaseNode_SpawnCollider);
    auto node95 = GET_SKILL_NODE(95, PhaseNode_OffsetCalculate);
    if (node12 != nullptr) node22->setTarget(node12->getColliderID());
    if (node95 != nullptr) node22->getVars().setVariable<float>(0, node95->getOutPosX());
    if (node95 != nullptr) node22->getVars().setVariable<float>(1, node95->getOutPosY());
    return node22;
}
//--------------------------------------------------------------------------------
// AttachTo
//
REGISTER_REGISTER_SKILL_NODE(10342, 24) {
    pnode->resizeTrigger(PhaseNode_AttachTo::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_AttachTo::TRIGGER_DONE, 69, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10342, 24) {
    auto node24 = GET_SKILL_NODE(24, PhaseNode_AttachTo);
    if (node24 == nullptr) {
        node24 = new PhaseNode_AttachTo(24, phase);
        node24->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node24->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node24->setChild(0U);
        node24->setChangeRotation(false);
        node24->setreentry(false);
        CALL_REGISTER_SKILL_NODE(10342, 24, node24)
    }
    if (noInit == true) {
        return node24;
    }
    auto node12 = GET_SKILL_NODE(12, PhaseNode_SpawnCollider);
    if (node12 != nullptr) node24->setParent(node12->getColliderID());
    return node24;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(10342, 26) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetInputObject>(PhaseNode_GetLocation::TRIGGER_DONE, 107, PhaseNode_GetInputObject::FUNC_DO, &PhaseNode_GetInputObject::Do);
}

REGISTER_CREATE_SKILL_NODE(10342, 26) {
    auto node26 = GET_SKILL_NODE(26, PhaseNode_GetLocation);
    if (node26 == nullptr) {
        node26 = new PhaseNode_GetLocation(26, phase);
        node26->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node26->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(10342, 26, node26)
    }
    if (noInit == true) {
        return node26;
    }
    return node26;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10342, 49) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CameraXYZShake>(PhaseNode_PlayAnimation::TRIGGER_DONE, 116, PhaseNode_CameraXYZShake::FUNC_DO, &PhaseNode_CameraXYZShake::Do);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlayAnimation::TRIGGER_DONE, 51, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10342, 49) {
    auto node49 = GET_SKILL_NODE(49, PhaseNode_PlayAnimation);
    if (node49 == nullptr) {
        node49 = new PhaseNode_PlayAnimation(49, phase);
        node49->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node49->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node49->setTarget(0U);
        node49->setAnimation("Skill2S2");
        node49->setParameter("");
        node49->setValue(false);
        CALL_REGISTER_SKILL_NODE(10342, 49, node49)
    }
    if (noInit == true) {
        return node49;
    }
    return node49;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10342, 51) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_Delay::TRIGGER_DONE, 55, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(10342, 51) {
    auto node51 = GET_SKILL_NODE(51, PhaseNode_Delay);
    if (node51 == nullptr) {
        node51 = new PhaseNode_Delay(51, phase);
        node51->setTime(.80f);
        CALL_REGISTER_SKILL_NODE(10342, 51, node51)
    }
    if (noInit == true) {
        return node51;
    }
    return node51;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(10342, 55) {
}

REGISTER_CREATE_SKILL_NODE(10342, 55) {
    auto node55 = GET_SKILL_NODE(55, PhaseNode_EndPhase);
    if (node55 == nullptr) {
        node55 = new PhaseNode_EndPhase(55, phase);
        node55->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node55->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10342, 55, node55)
    }
    if (noInit == true) {
        return node55;
    }
    return node55;
}
//--------------------------------------------------------------------------------
// AddSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10342, 61) {
    pnode->resizeTrigger(PhaseNode_AddSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_AddSkillBuff::TRIGGER_DONE, 125, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10342, 61) {
    auto node61 = GET_SKILL_NODE(61, PhaseNode_AddSkillBuff);
    if (node61 == nullptr) {
        node61 = new PhaseNode_AddSkillBuff(61, phase);
        node61->setConfigID(103401);
        node61->setConfigIDs({});
        node61->setTarget(0U);
        node61->setAttribute({{}});
        CALL_REGISTER_SKILL_NODE(10342, 61, node61)
    }
    if (noInit == true) {
        return node61;
    }
    return node61;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10342, 69) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetInt>(PhaseNode_Delay::TRIGGER_DONE, 76, PhaseNode_SetInt::FUNC_SET, &PhaseNode_SetInt::Set);
}

REGISTER_CREATE_SKILL_NODE(10342, 69) {
    auto node69 = GET_SKILL_NODE(69, PhaseNode_Delay);
    if (node69 == nullptr) {
        node69 = new PhaseNode_Delay(69, phase);
        node69->setTime(.20f);
        CALL_REGISTER_SKILL_NODE(10342, 69, node69)
    }
    if (noInit == true) {
        return node69;
    }
    return node69;
}
//--------------------------------------------------------------------------------
// SetInt
//
REGISTER_REGISTER_SKILL_NODE(10342, 76) {
    pnode->resizeTrigger(PhaseNode_SetInt::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_MoveNewPene>(PhaseNode_SetInt::TRIGGER_DONE, 22, PhaseNode_MoveNewPene::FUNC_DO, &PhaseNode_MoveNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(10342, 76) {
    auto node76 = GET_SKILL_NODE(76, PhaseNode_SetInt);
    if (node76 == nullptr) {
        node76 = new PhaseNode_SetInt(76, phase);
        node76->setName("Break");
        node76->setValue(2);
        CALL_REGISTER_SKILL_NODE(10342, 76, node76)
    }
    if (noInit == true) {
        return node76;
    }
    return node76;
}
//--------------------------------------------------------------------------------
// TriggerUpdate
//
REGISTER_REGISTER_SKILL_NODE(10342, 78) {
}

REGISTER_CREATE_SKILL_NODE(10342, 78) {
    auto node78 = GET_SKILL_NODE(78, PhaseNode_TriggerUpdate);
    if (node78 == nullptr) {
        node78 = new PhaseNode_TriggerUpdate(78, phase);
        CALL_REGISTER_SKILL_NODE(10342, 78, node78)
    }
    if (noInit == true) {
        return node78;
    }
    return node78;
}
//--------------------------------------------------------------------------------
// SetRotation
//
REGISTER_REGISTER_SKILL_NODE(10342, 80) {
    pnode->resizeTrigger(PhaseNode_SetRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_DestroyCollider>(PhaseNode_SetRotation::TRIGGER_DONE, 93, PhaseNode_DestroyCollider::FUNC_DO, &PhaseNode_DestroyCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(10342, 80) {
    auto node80 = GET_SKILL_NODE(80, PhaseNode_SetRotation);
    if (node80 == nullptr) {
        node80 = new PhaseNode_SetRotation(80, phase);
        node80->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node80->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node80->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(10342, 80, node80)
    }
    if (noInit == true) {
        return node80;
    }
    auto node84 = GET_SKILL_NODE(84, PhaseNode_GetLineRotation);
    if (node84 != nullptr) node80->setAngle(node84->getRotation());
    return node80;
}
//--------------------------------------------------------------------------------
// GetLineRotation
//
REGISTER_REGISTER_SKILL_NODE(10342, 84) {
    pnode->resizeTrigger(PhaseNode_GetLineRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_OffsetCalculate>(PhaseNode_GetLineRotation::TRIGGER_DONE, 95, PhaseNode_OffsetCalculate::FUNC_DO, &PhaseNode_OffsetCalculate::Do);
}

REGISTER_CREATE_SKILL_NODE(10342, 84) {
    auto node84 = GET_SKILL_NODE(84, PhaseNode_GetLineRotation);
    if (node84 == nullptr) {
        node84 = new PhaseNode_GetLineRotation(84, phase);
        CALL_REGISTER_SKILL_NODE(10342, 84, node84)
    }
    if (noInit == true) {
        return node84;
    }
    auto node109 = GET_SKILL_NODE(109, PhaseNode_GetLocation);
    auto node26 = GET_SKILL_NODE(26, PhaseNode_GetLocation);
    if (node109 != nullptr) node84->setStartX(node109->getX());
    if (node109 != nullptr) node84->setStartY(node109->getY());
    if (node26 != nullptr) node84->setEndX(node26->getX());
    if (node26 != nullptr) node84->setEndY(node26->getY());
    return node84;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(10342, 88) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_OffsetCalculate>(PhaseNode_GetLocation::TRIGGER_DONE, 90, PhaseNode_OffsetCalculate::FUNC_DO, &PhaseNode_OffsetCalculate::Do);
}

REGISTER_CREATE_SKILL_NODE(10342, 88) {
    auto node88 = GET_SKILL_NODE(88, PhaseNode_GetLocation);
    if (node88 == nullptr) {
        node88 = new PhaseNode_GetLocation(88, phase);
        node88->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node88->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(10342, 88, node88)
    }
    if (noInit == true) {
        return node88;
    }
    return node88;
}
//--------------------------------------------------------------------------------
// OffsetCalculate
//
REGISTER_REGISTER_SKILL_NODE(10342, 90) {
    pnode->resizeTrigger(PhaseNode_OffsetCalculate::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 103, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(10342, 90) {
    auto node90 = GET_SKILL_NODE(90, PhaseNode_OffsetCalculate);
    if (node90 == nullptr) {
        node90 = new PhaseNode_OffsetCalculate(90, phase);
        node90->setPosZ(.00f);
        node90->setOffsetX(.00f);
        node90->setOffsetY(2.00f);
        node90->setOffsetZ(.00f);
        node90->setRotOffset(.00f);
        CALL_REGISTER_SKILL_NODE(10342, 90, node90)
    }
    if (noInit == true) {
        return node90;
    }
    auto node88 = GET_SKILL_NODE(88, PhaseNode_GetLocation);
    auto node84 = GET_SKILL_NODE(84, PhaseNode_GetLineRotation);
    if (node88 != nullptr) node90->setPosX(node88->getX());
    if (node88 != nullptr) node90->setPosY(node88->getY());
    if (node84 != nullptr) node90->setRotation(node84->getRotation());
    return node90;
}
//--------------------------------------------------------------------------------
// DestroyCollider
//
REGISTER_REGISTER_SKILL_NODE(10342, 93) {
    pnode->resizeTrigger(PhaseNode_DestroyCollider::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_DestroyCollider::TRIGGER_DONE, 112, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10342, 93) {
    auto node93 = GET_SKILL_NODE(93, PhaseNode_DestroyCollider);
    if (node93 == nullptr) {
        node93 = new PhaseNode_DestroyCollider(93, phase);
        CALL_REGISTER_SKILL_NODE(10342, 93, node93)
    }
    if (noInit == true) {
        return node93;
    }
    auto node12 = GET_SKILL_NODE(12, PhaseNode_SpawnCollider);
    if (node12 != nullptr) node93->setColliderID(node12->getColliderID());
    return node93;
}
//--------------------------------------------------------------------------------
// OffsetCalculate
//
REGISTER_REGISTER_SKILL_NODE(10342, 95) {
    pnode->resizeTrigger(PhaseNode_OffsetCalculate::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 97, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(10342, 95) {
    auto node95 = GET_SKILL_NODE(95, PhaseNode_OffsetCalculate);
    if (node95 == nullptr) {
        node95 = new PhaseNode_OffsetCalculate(95, phase);
        node95->setPosZ(.00f);
        node95->setOffsetX(.00f);
        node95->setOffsetY(-2.00f);
        node95->setOffsetZ(.00f);
        node95->setRotOffset(180.00f);
        CALL_REGISTER_SKILL_NODE(10342, 95, node95)
    }
    if (noInit == true) {
        return node95;
    }
    auto node109 = GET_SKILL_NODE(109, PhaseNode_GetLocation);
    auto node84 = GET_SKILL_NODE(84, PhaseNode_GetLineRotation);
    if (node109 != nullptr) node95->setPosX(node109->getX());
    if (node109 != nullptr) node95->setPosY(node109->getY());
    if (node84 != nullptr) node95->setRotation(node84->getRotation());
    return node95;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(10342, 97) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_PlayEffect::TRIGGER_DONE, 105, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(10342, 97) {
    auto node97 = GET_SKILL_NODE(97, PhaseNode_PlayEffect);
    if (node97 == nullptr) {
        node97 = new PhaseNode_PlayEffect(97, phase);
        node97->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node97->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node97->setEffectID(103421);
        node97->setChangeColor(false);
        node97->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node97->getVars().reserve(3);
        node97->getVars().setVariable<float>(0, .00f);
        node97->getVars().setVariable<float>(1, .00f);
        node97->getVars().setVariable<float>(2, .00f);
        node97->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(10342, 97, node97)
    }
    if (noInit == true) {
        return node97;
    }
    auto node26 = GET_SKILL_NODE(26, PhaseNode_GetLocation);
    auto node95 = GET_SKILL_NODE(95, PhaseNode_OffsetCalculate);
    if (node26 != nullptr) node97->getVars().setVariable<float>(0, node26->getX());
    if (node26 != nullptr) node97->getVars().setVariable<float>(1, node26->getY());
    if (node95 != nullptr) node97->setRotation(node95->getOutRotation());
    return node97;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(10342, 103) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuff>(PhaseNode_PlayEffect::TRIGGER_DONE, 114, PhaseNode_AddSkillBuff::FUNC_ADD, &PhaseNode_AddSkillBuff::Add);
}

REGISTER_CREATE_SKILL_NODE(10342, 103) {
    auto node103 = GET_SKILL_NODE(103, PhaseNode_PlayEffect);
    if (node103 == nullptr) {
        node103 = new PhaseNode_PlayEffect(103, phase);
        node103->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node103->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node103->setEffectID(103423);
        node103->setChangeColor(false);
        node103->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node103->getVars().reserve(3);
        node103->getVars().setVariable<float>(0, .00f);
        node103->getVars().setVariable<float>(1, .00f);
        node103->getVars().setVariable<float>(2, .00f);
        node103->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(10342, 103, node103)
    }
    if (noInit == true) {
        return node103;
    }
    auto node90 = GET_SKILL_NODE(90, PhaseNode_OffsetCalculate);
    if (node90 != nullptr) node103->getVars().setVariable<float>(0, node90->getOutPosX());
    if (node90 != nullptr) node103->getVars().setVariable<float>(1, node90->getOutPosY());
    if (node90 != nullptr) node103->setRotation(node90->getOutRotation());
    return node103;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(10342, 105) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnCollider>(PhaseNode_PlayEffect::TRIGGER_DONE, 12, PhaseNode_SpawnCollider::FUNC_DO, &PhaseNode_SpawnCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(10342, 105) {
    auto node105 = GET_SKILL_NODE(105, PhaseNode_PlayEffect);
    if (node105 == nullptr) {
        node105 = new PhaseNode_PlayEffect(105, phase);
        node105->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node105->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node105->setEffectID(103422);
        node105->setChangeColor(false);
        node105->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node105->getVars().reserve(3);
        node105->getVars().setVariable<float>(0, .00f);
        node105->getVars().setVariable<float>(1, .00f);
        node105->getVars().setVariable<float>(2, .00f);
        node105->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(10342, 105, node105)
    }
    if (noInit == true) {
        return node105;
    }
    auto node26 = GET_SKILL_NODE(26, PhaseNode_GetLocation);
    auto node95 = GET_SKILL_NODE(95, PhaseNode_OffsetCalculate);
    if (node26 != nullptr) node105->getVars().setVariable<float>(0, node26->getX());
    if (node26 != nullptr) node105->getVars().setVariable<float>(1, node26->getY());
    if (node95 != nullptr) node105->setRotation(node95->getOutRotation());
    return node105;
}
//--------------------------------------------------------------------------------
// GetInputObject
//
REGISTER_REGISTER_SKILL_NODE(10342, 107) {
    pnode->resizeTrigger(PhaseNode_GetInputObject::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_GetInputObject::TRIGGER_DONE, 109, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(10342, 107) {
    auto node107 = GET_SKILL_NODE(107, PhaseNode_GetInputObject);
    if (node107 == nullptr) {
        node107 = new PhaseNode_GetInputObject(107, phase);
        node107->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        CALL_REGISTER_SKILL_NODE(10342, 107, node107)
    }
    if (noInit == true) {
        return node107;
    }
    return node107;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(10342, 109) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLineRotation>(PhaseNode_GetLocation::TRIGGER_DONE, 84, PhaseNode_GetLineRotation::FUNC_DO, &PhaseNode_GetLineRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(10342, 109) {
    auto node109 = GET_SKILL_NODE(109, PhaseNode_GetLocation);
    if (node109 == nullptr) {
        node109 = new PhaseNode_GetLocation(109, phase);
        node109->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        CALL_REGISTER_SKILL_NODE(10342, 109, node109)
    }
    if (noInit == true) {
        return node109;
    }
    auto node107 = GET_SKILL_NODE(107, PhaseNode_GetInputObject);
    if (node107 != nullptr) node109->setTarget(node107->getSceneObjId());
    return node109;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10342, 112) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_PlaySound::TRIGGER_DONE, 49, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10342, 112) {
    auto node112 = GET_SKILL_NODE(112, PhaseNode_PlaySound);
    if (node112 == nullptr) {
        node112 = new PhaseNode_PlaySound(112, phase);
        node112->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node112->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node112->setSoundID("SE_Hero134_SkillB_P2");
        node112->setTarget(0U);
        node112->setUsePos(false);
        node112->setPosX(.00f);
        node112->setPosY(.00f);
        node112->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10342, 112, node112)
    }
    if (noInit == true) {
        return node112;
    }
    return node112;
}
//--------------------------------------------------------------------------------
// AddSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10342, 114) {
}

REGISTER_CREATE_SKILL_NODE(10342, 114) {
    auto node114 = GET_SKILL_NODE(114, PhaseNode_AddSkillBuff);
    if (node114 == nullptr) {
        node114 = new PhaseNode_AddSkillBuff(114, phase);
        node114->setConfigID(103421);
        node114->setConfigIDs({});
        CALL_REGISTER_SKILL_NODE(10342, 114, node114)
    }
    if (noInit == true) {
        return node114;
    }
    auto node107 = GET_SKILL_NODE(107, PhaseNode_GetInputObject);
    auto node120 = GET_SKILL_NODE(120, PhaseNode_GetActorAttribute);
    if (node107 != nullptr) node114->setTarget(node107->getSceneObjId());
    if (node120 != nullptr) node114->setAttribute(node120->getAttribute());
    return node114;
}
//--------------------------------------------------------------------------------
// CameraXYZShake
//
REGISTER_REGISTER_SKILL_NODE(10342, 116) {
    pnode->resizeTrigger(PhaseNode_CameraXYZShake::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_CameraXYZShake::TRIGGER_DONE, 88, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(10342, 116) {
    auto node116 = GET_SKILL_NODE(116, PhaseNode_CameraXYZShake);
    if (node116 == nullptr) {
        node116 = new PhaseNode_CameraXYZShake(116, phase);
        node116->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node116->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node116->setShakeStyle(0);
        node116->setTarget(0U);
        node116->setX(.10f);
        node116->setY(.10f);
        node116->setZ(.10f);
        node116->setDuration(.15f);
        node116->setTimes(3);
        CALL_REGISTER_SKILL_NODE(10342, 116, node116)
    }
    if (noInit == true) {
        return node116;
    }
    return node116;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(10342, 117) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_ResetCD::TRIGGER_DONE, 118, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10342, 117) {
    auto node117 = GET_SKILL_NODE(117, PhaseNode_ResetCD);
    if (node117 == nullptr) {
        node117 = new PhaseNode_ResetCD(117, phase);
        node117->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node117->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node117->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(10342, 117, node117)
    }
    if (noInit == true) {
        return node117;
    }
    return node117;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10342, 118) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_PlayAnimation::TRIGGER_DONE, 120, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(10342, 118) {
    auto node118 = GET_SKILL_NODE(118, PhaseNode_PlayAnimation);
    if (node118 == nullptr) {
        node118 = new PhaseNode_PlayAnimation(118, phase);
        node118->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node118->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node118->setTarget(0U);
        node118->setAnimation("Skill2S1");
        node118->setParameter("");
        node118->setValue(false);
        CALL_REGISTER_SKILL_NODE(10342, 118, node118)
    }
    if (noInit == true) {
        return node118;
    }
    return node118;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10342, 119) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Disable>(PhaseNode_PlaySound::TRIGGER_DONE, 9, PhaseNode_Disable::FUNC_DO, &PhaseNode_Disable::Do);
}

REGISTER_CREATE_SKILL_NODE(10342, 119) {
    auto node119 = GET_SKILL_NODE(119, PhaseNode_PlaySound);
    if (node119 == nullptr) {
        node119 = new PhaseNode_PlaySound(119, phase);
        node119->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node119->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node119->setSoundID("SE_Hero134_SkillB_P1");
        node119->setTarget(0U);
        node119->setUsePos(false);
        node119->setPosX(.00f);
        node119->setPosY(.00f);
        node119->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10342, 119, node119)
    }
    if (noInit == true) {
        return node119;
    }
    return node119;
}
//--------------------------------------------------------------------------------
// GetActorAttribute
//
REGISTER_REGISTER_SKILL_NODE(10342, 120) {
    pnode->resizeTrigger(PhaseNode_GetActorAttribute::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 119, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10342, 120) {
    auto node120 = GET_SKILL_NODE(120, PhaseNode_GetActorAttribute);
    if (node120 == nullptr) {
        node120 = new PhaseNode_GetActorAttribute(120, phase);
        node120->setTarget(0U);
        node120->setType({});
        CALL_REGISTER_SKILL_NODE(10342, 120, node120)
    }
    if (noInit == true) {
        return node120;
    }
    return node120;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10342, 122) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_IsInterruptType>(PhaseNode_Detect::TRIGGER_ON, 128, PhaseNode_IsInterruptType::FUNC_DO, &PhaseNode_IsInterruptType::Do);
}

REGISTER_CREATE_SKILL_NODE(10342, 122) {
    auto node122 = GET_SKILL_NODE(122, PhaseNode_Detect);
    if (node122 == nullptr) {
        node122 = new PhaseNode_Detect(122, phase);
        node122->setSelf(0U);
        node122->setEvent("daduan_001");
        node122->setType(PhaseNode_Detect::Detect_Type::Interrupt_Skill);
        node122->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10342, 122, node122)
    }
    if (noInit == true) {
        return node122;
    }
    return node122;
}
//--------------------------------------------------------------------------------
// SwitchToInt
//
REGISTER_REGISTER_SKILL_NODE(10342, 123) {
    pnode->resizeTrigger(4);
    pnode->regTrigger<PhaseNode_EndPhase>(1, 55, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(10342, 123) {
    auto node123 = GET_SKILL_NODE(123, PhaseNode_SwitchToInt);
    if (node123 == nullptr) {
        node123 = new PhaseNode_SwitchToInt(123, phase);
        CALL_REGISTER_SKILL_NODE(10342, 123, node123)
    }
    if (noInit == true) {
        return node123;
    }
    auto variables = node123->getVariables();
    if (variables != nullptr) {
        node123->setSelection(variables->getVariable<int32_t>(Variable_10342_Break));
    }
    return node123;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10342, 125) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_RaiseEvent::TRIGGER_DONE, 134, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10342, 125) {
    auto node125 = GET_SKILL_NODE(125, PhaseNode_RaiseEvent);
    if (node125 == nullptr) {
        node125 = new PhaseNode_RaiseEvent(125, phase);
        node125->setEvent("daduan_001");
        node125->setTarget(0U);
        node125->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node125->setTypeParams(0, 0);
        node125->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10342, 125, node125)
    }
    if (noInit == true) {
        return node125;
    }
    return node125;
}
//--------------------------------------------------------------------------------
// StartPreInput
//
REGISTER_REGISTER_SKILL_NODE(10342, 126) {
    pnode->resizeTrigger(PhaseNode_StartPreInput::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_StartPreInput::TRIGGER_DONE, 130, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_StartPreInput::TRIGGER_DONE, 26, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(10342, 126) {
    auto node126 = GET_SKILL_NODE(126, PhaseNode_StartPreInput);
    if (node126 == nullptr) {
        node126 = new PhaseNode_StartPreInput(126, phase);
        node126->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node126->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node126->setDelayTime(.00f);
        CALL_REGISTER_SKILL_NODE(10342, 126, node126)
    }
    if (noInit == true) {
        return node126;
    }
    return node126;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(10342, 127) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_If::TRIGGER_TRUE, 129, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10342, 127) {
    auto node127 = GET_SKILL_NODE(127, PhaseNode_If);
    if (node127 == nullptr) {
        node127 = new PhaseNode_If(127, phase);
        CALL_REGISTER_SKILL_NODE(10342, 127, node127)
    }
    if (noInit == true) {
        return node127;
    }
    auto variables = node127->getVariables();
    if (variables != nullptr) {
        node127->setCondition(variables->getVariable<bool>(Variable_10342_InterruptAnimat));
    }
    return node127;
}
//--------------------------------------------------------------------------------
// IsInterruptType
//
REGISTER_REGISTER_SKILL_NODE(10342, 128) {
    pnode->resizeTrigger(PhaseNode_IsInterruptType::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SwitchToInt>(PhaseNode_IsInterruptType::TRIGGER_BUFF, 123, PhaseNode_SwitchToInt::FUNC_SWITCH, &PhaseNode_SwitchToInt::Switch);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_POSCHANGE, 127, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTAIM, 127, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTFIRE, 127, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTRELOAD, 127, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_USESKILL, 127, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(10342, 128) {
    auto node128 = GET_SKILL_NODE(128, PhaseNode_IsInterruptType);
    if (node128 == nullptr) {
        node128 = new PhaseNode_IsInterruptType(128, phase);
        node128->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node128->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10342, 128, node128)
    }
    if (noInit == true) {
        return node128;
    }
    auto node122 = GET_SKILL_NODE(122, PhaseNode_Detect);
    if (node122 != nullptr) node128->setType(node122->getVars().getVariable<int32_t>(2));
    return node128;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10342, 129) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_PlayAnimation::TRIGGER_DONE, 55, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(10342, 129) {
    auto node129 = GET_SKILL_NODE(129, PhaseNode_PlayAnimation);
    if (node129 == nullptr) {
        node129 = new PhaseNode_PlayAnimation(129, phase);
        node129->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node129->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node129->setTarget(0U);
        node129->setAnimation("Idle");
        node129->setParameter("");
        node129->setValue(false);
        CALL_REGISTER_SKILL_NODE(10342, 129, node129)
    }
    if (noInit == true) {
        return node129;
    }
    return node129;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10342, 130) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_Delay::TRIGGER_DONE, 133, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(10342, 130) {
    auto node130 = GET_SKILL_NODE(130, PhaseNode_Delay);
    if (node130 == nullptr) {
        node130 = new PhaseNode_Delay(130, phase);
        node130->setTime(.20f);
        CALL_REGISTER_SKILL_NODE(10342, 130, node130)
    }
    if (noInit == true) {
        return node130;
    }
    return node130;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(10342, 133) {
}

REGISTER_CREATE_SKILL_NODE(10342, 133) {
    auto node133 = GET_SKILL_NODE(133, PhaseNode_SetBool);
    if (node133 == nullptr) {
        node133 = new PhaseNode_SetBool(133, phase);
        node133->setName("InterruptAnimat");
        node133->setValue(true);
        CALL_REGISTER_SKILL_NODE(10342, 133, node133)
    }
    if (noInit == true) {
        return node133;
    }
    return node133;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10342, 134) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StartPreInput>(PhaseNode_RaiseEvent::TRIGGER_DONE, 126, PhaseNode_StartPreInput::FUNC_DO, &PhaseNode_StartPreInput::Do);
}

REGISTER_CREATE_SKILL_NODE(10342, 134) {
    auto node134 = GET_SKILL_NODE(134, PhaseNode_RaiseEvent);
    if (node134 == nullptr) {
        node134 = new PhaseNode_RaiseEvent(134, phase);
        node134->setEvent("Dead_001");
        node134->setTarget(0U);
        node134->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node134->setTypeParams(0, 0);
        node134->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10342, 134, node134)
    }
    if (noInit == true) {
        return node134;
    }
    return node134;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10342, 135) {
}

REGISTER_CREATE_SKILL_NODE(10342, 135) {
    auto node135 = GET_SKILL_NODE(135, PhaseNode_Detect);
    if (node135 == nullptr) {
        node135 = new PhaseNode_Detect(135, phase);
        node135->setSelf(0U);
        node135->setEvent("Dead_001");
        node135->setType(PhaseNode_Detect::Detect_Type::Actor_Dead);
        node135->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10342, 135, node135)
    }
    if (noInit == true) {
        return node135;
    }
    return node135;
}

//--------------------------------------------------------------------------------
// SkillCreator_10342
//
class SkillCreator_10342 : public SkillCreator {
public:
    SkillCreator_10342() {}
    virtual ~SkillCreator_10342() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_10342

//--------------------------------------------------------------------------------
// SkillPhase_10342
//
class SkillPhase_10342 : public SkillPhase {
public:
    SkillPhase_10342(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_10342() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(10342, 5) // StartPhase
        CASE_CREATE_SKILL_NODE(10342, 9) // Disable
        CASE_CREATE_SKILL_NODE(10342, 12) // SpawnCollider
        CASE_CREATE_SKILL_NODE(10342, 22) // MoveNewPene
        CASE_CREATE_SKILL_NODE(10342, 24) // AttachTo
        CASE_CREATE_SKILL_NODE(10342, 26) // GetLocation
        CASE_CREATE_SKILL_NODE(10342, 49) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10342, 51) // Delay
        CASE_CREATE_SKILL_NODE(10342, 55) // EndPhase
        CASE_CREATE_SKILL_NODE(10342, 61) // AddSkillBuff
        CASE_CREATE_SKILL_NODE(10342, 69) // Delay
        CASE_CREATE_SKILL_NODE(10342, 76) // SetInt
        CASE_CREATE_SKILL_NODE(10342, 78) // TriggerUpdate
        CASE_CREATE_SKILL_NODE(10342, 80) // SetRotation
        CASE_CREATE_SKILL_NODE(10342, 84) // GetLineRotation
        CASE_CREATE_SKILL_NODE(10342, 88) // GetLocation
        CASE_CREATE_SKILL_NODE(10342, 90) // OffsetCalculate
        CASE_CREATE_SKILL_NODE(10342, 93) // DestroyCollider
        CASE_CREATE_SKILL_NODE(10342, 95) // OffsetCalculate
        CASE_CREATE_SKILL_NODE(10342, 97) // PlayEffect
        CASE_CREATE_SKILL_NODE(10342, 103) // PlayEffect
        CASE_CREATE_SKILL_NODE(10342, 105) // PlayEffect
        CASE_CREATE_SKILL_NODE(10342, 107) // GetInputObject
        CASE_CREATE_SKILL_NODE(10342, 109) // GetLocation
        CASE_CREATE_SKILL_NODE(10342, 112) // PlaySound
        CASE_CREATE_SKILL_NODE(10342, 114) // AddSkillBuff
        CASE_CREATE_SKILL_NODE(10342, 116) // CameraXYZShake
        CASE_CREATE_SKILL_NODE(10342, 117) // ResetCD
        CASE_CREATE_SKILL_NODE(10342, 118) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10342, 119) // PlaySound
        CASE_CREATE_SKILL_NODE(10342, 120) // GetActorAttribute
        CASE_CREATE_SKILL_NODE(10342, 122) // Detect
        CASE_CREATE_SKILL_NODE(10342, 123) // SwitchToInt
        CASE_CREATE_SKILL_NODE(10342, 125) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10342, 126) // StartPreInput
        CASE_CREATE_SKILL_NODE(10342, 127) // If
        CASE_CREATE_SKILL_NODE(10342, 128) // IsInterruptType
        CASE_CREATE_SKILL_NODE(10342, 129) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10342, 130) // Delay
        CASE_CREATE_SKILL_NODE(10342, 133) // SetBool
        CASE_CREATE_SKILL_NODE(10342, 134) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10342, 135) // Detect
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_10342

SkillLogic* SkillCreator_10342::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //设置变量
    Variable_10342_Break = logic->getVariables().setVariable<int32_t>("Break", 1);
    Variable_10342_InterruptAnimat = logic->getVariables().setVariable<bool>("InterruptAnimat");
    //创建阶段phase
    auto phase = new SkillPhase_10342(1, logic, 3);
    //设置phase执行器
    phase->setRunPhaseNode(1, 5);
    phase->setRunPhaseNode(2, 78);
    phase->setDetectPhaseNode(3, 122);
    phase->setDetectPhaseNode(3, 135);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_10342::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
