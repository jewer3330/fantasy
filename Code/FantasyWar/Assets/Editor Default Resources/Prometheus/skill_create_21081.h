#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

#include "skill_psnode_actorfilternewpene.h"
#include "skill_psnode_addskillbuff.h"
#include "skill_psnode_addskillbuffs.h"
#include "skill_psnode_attachto.h"
#include "skill_psnode_compareint.h"
#include "skill_psnode_createtriggernewpene.h"
#include "skill_psnode_delay.h"
#include "skill_psnode_destroycollider.h"
#include "skill_psnode_detect.h"
#include "skill_psnode_endphase.h"
#include "skill_psnode_for.h"
#include "skill_psnode_forcontinue.h"
#include "skill_psnode_getlocation.h"
#include "skill_psnode_getrotation.h"
#include "skill_psnode_getuint64svalue.h"
#include "skill_psnode_if.h"
#include "skill_psnode_movenewpene.h"
#include "skill_psnode_offsetcalculate.h"
#include "skill_psnode_playanimation.h"
#include "skill_psnode_playsound.h"
#include "skill_psnode_raiseevent.h"
#include "skill_psnode_removeskillbuff.h"
#include "skill_psnode_resetcd.h"
#include "skill_psnode_setint.h"
#include "skill_psnode_setuint64s.h"
#include "skill_psnode_skillendnotify.h"
#include "skill_psnode_spawncollider.h"
#include "skill_psnode_startphase.h"
#include "skill_psnode_stopsound.h"
#include "skill_psnode_triggercheck.h"
#include "skill_psnode_triggerupdate.h"
#include "skill_psnode_uint64ssize.h"

namespace pvp {

//变量声明
uint64_t Variable_21081_Targets = 0;
uint64_t Variable_21081_TargetSize = 0;
//--------------------------------------------------------------------------------
// StartPhase
//
REGISTER_REGISTER_SKILL_NODE(21081, 1) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_StartPhase::TRIGGER_START, 355, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_StartPhase::TRIGGER_START, 11, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(21081, 1) {
    auto node1 = GET_SKILL_NODE(1, PhaseNode_StartPhase);
    if (node1 == nullptr) {
        node1 = new PhaseNode_StartPhase(1, phase);
        CALL_REGISTER_SKILL_NODE(21081, 1, node1)
    }
    if (noInit == true) {
        return node1;
    }
    return node1;
}
//--------------------------------------------------------------------------------
// TriggerUpdate
//
REGISTER_REGISTER_SKILL_NODE(21081, 2) {
}

REGISTER_CREATE_SKILL_NODE(21081, 2) {
    auto node2 = GET_SKILL_NODE(2, PhaseNode_TriggerUpdate);
    if (node2 == nullptr) {
        node2 = new PhaseNode_TriggerUpdate(2, phase);
        CALL_REGISTER_SKILL_NODE(21081, 2, node2)
    }
    if (noInit == true) {
        return node2;
    }
    return node2;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(21081, 4) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetRotation>(PhaseNode_GetLocation::TRIGGER_DONE, 5, PhaseNode_GetRotation::FUNC_DO, &PhaseNode_GetRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(21081, 4) {
    auto node4 = GET_SKILL_NODE(4, PhaseNode_GetLocation);
    if (node4 == nullptr) {
        node4 = new PhaseNode_GetLocation(4, phase);
        node4->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node4->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(21081, 4, node4)
    }
    if (noInit == true) {
        return node4;
    }
    return node4;
}
//--------------------------------------------------------------------------------
// GetRotation
//
REGISTER_REGISTER_SKILL_NODE(21081, 5) {
    pnode->resizeTrigger(PhaseNode_GetRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuff>(PhaseNode_GetRotation::TRIGGER_DONE, 293, PhaseNode_AddSkillBuff::FUNC_ADD, &PhaseNode_AddSkillBuff::Add);
}

REGISTER_CREATE_SKILL_NODE(21081, 5) {
    auto node5 = GET_SKILL_NODE(5, PhaseNode_GetRotation);
    if (node5 == nullptr) {
        node5 = new PhaseNode_GetRotation(5, phase);
        node5->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node5->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(21081, 5, node5)
    }
    if (noInit == true) {
        return node5;
    }
    return node5;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(21081, 11) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_ResetCD::TRIGGER_DONE, 4, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(21081, 11) {
    auto node11 = GET_SKILL_NODE(11, PhaseNode_ResetCD);
    if (node11 == nullptr) {
        node11 = new PhaseNode_ResetCD(11, phase);
        node11->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node11->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node11->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(21081, 11, node11)
    }
    if (noInit == true) {
        return node11;
    }
    return node11;
}
//--------------------------------------------------------------------------------
// SpawnCollider
//
REGISTER_REGISTER_SKILL_NODE(21081, 12) {
    pnode->resizeTrigger(PhaseNode_SpawnCollider::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_SpawnCollider::TRIGGER_DONE, 15, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(21081, 12) {
    auto node12 = GET_SKILL_NODE(12, PhaseNode_SpawnCollider);
    if (node12 == nullptr) {
        node12 = new PhaseNode_SpawnCollider(12, phase);
        node12->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node12->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node12->setMesh("");
        node12->setMeshScale(.00f);
        node12->setEffectID(210811);
        node12->setEffectScale(1.00f);
        node12->setType(PhaseNode_SpawnCollider::SpawnCollider_Type::Circle);
        node12->setTypeParams(0, .00f);
        node12->setTime(.00f);
        node12->setPosZ(.00f);
        node12->setreentry(false);
        node12->setCheckPeneSound(false);
        CALL_REGISTER_SKILL_NODE(21081, 12, node12)
    }
    if (noInit == true) {
        return node12;
    }
    auto node4 = GET_SKILL_NODE(4, PhaseNode_GetLocation);
    auto node5 = GET_SKILL_NODE(5, PhaseNode_GetRotation);
    if (node4 != nullptr) node12->setPosX(node4->getX());
    if (node4 != nullptr) node12->setPosY(node4->getY());
    if (node5 != nullptr) node12->setRotation(node5->getAngle());
    return node12;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(21081, 15) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_PlayAnimation::TRIGGER_DONE, 209, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(21081, 15) {
    auto node15 = GET_SKILL_NODE(15, PhaseNode_PlayAnimation);
    if (node15 == nullptr) {
        node15 = new PhaseNode_PlayAnimation(15, phase);
        node15->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node15->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node15->setAnimation("Skill1S1");
        node15->setParameter("");
        node15->setValue(false);
        CALL_REGISTER_SKILL_NODE(21081, 15, node15)
    }
    if (noInit == true) {
        return node15;
    }
    auto node12 = GET_SKILL_NODE(12, PhaseNode_SpawnCollider);
    if (node12 != nullptr) node15->setTarget(node12->getColliderID());
    return node15;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(21081, 16) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_OffsetCalculate>(PhaseNode_Delay::TRIGGER_DONE, 18, PhaseNode_OffsetCalculate::FUNC_DO, &PhaseNode_OffsetCalculate::Do);
}

REGISTER_CREATE_SKILL_NODE(21081, 16) {
    auto node16 = GET_SKILL_NODE(16, PhaseNode_Delay);
    if (node16 == nullptr) {
        node16 = new PhaseNode_Delay(16, phase);
        node16->setTime(.40f);
        CALL_REGISTER_SKILL_NODE(21081, 16, node16)
    }
    if (noInit == true) {
        return node16;
    }
    return node16;
}
//--------------------------------------------------------------------------------
// SpawnCollider
//
REGISTER_REGISTER_SKILL_NODE(21081, 17) {
    pnode->resizeTrigger(PhaseNode_SpawnCollider::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AttachTo>(PhaseNode_SpawnCollider::TRIGGER_DONE, 19, PhaseNode_AttachTo::FUNC_DO, &PhaseNode_AttachTo::Do);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_SpawnCollider::TRIGGER_DONE, 349, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
}

REGISTER_CREATE_SKILL_NODE(21081, 17) {
    auto node17 = GET_SKILL_NODE(17, PhaseNode_SpawnCollider);
    if (node17 == nullptr) {
        node17 = new PhaseNode_SpawnCollider(17, phase);
        node17->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node17->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node17->setMesh("");
        node17->setMeshScale(.00f);
        node17->setEffectID(210812);
        node17->setEffectScale(1.00f);
        node17->setType(PhaseNode_SpawnCollider::SpawnCollider_Type::Rect);
        node17->setTypeParams(0, 3.00f);
        node17->setTypeParams(1, 1.00f);
        node17->setTime(.00f);
        node17->setPosZ(.00f);
        node17->setreentry(false);
        node17->setCheckPeneSound(false);
        CALL_REGISTER_SKILL_NODE(21081, 17, node17)
    }
    if (noInit == true) {
        return node17;
    }
    auto node18 = GET_SKILL_NODE(18, PhaseNode_OffsetCalculate);
    if (node18 != nullptr) node17->setPosX(node18->getOutPosX());
    if (node18 != nullptr) node17->setPosY(node18->getOutPosY());
    if (node18 != nullptr) node17->setRotation(node18->getOutRotation());
    return node17;
}
//--------------------------------------------------------------------------------
// OffsetCalculate
//
REGISTER_REGISTER_SKILL_NODE(21081, 18) {
    pnode->resizeTrigger(PhaseNode_OffsetCalculate::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 21, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
    pnode->regTrigger<PhaseNode_SpawnCollider>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 17, PhaseNode_SpawnCollider::FUNC_DO, &PhaseNode_SpawnCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(21081, 18) {
    auto node18 = GET_SKILL_NODE(18, PhaseNode_OffsetCalculate);
    if (node18 == nullptr) {
        node18 = new PhaseNode_OffsetCalculate(18, phase);
        node18->setPosZ(.00f);
        node18->setOffsetX(.00f);
        node18->setOffsetY(1.00f);
        node18->setOffsetZ(.00f);
        node18->setRotOffset(.00f);
        CALL_REGISTER_SKILL_NODE(21081, 18, node18)
    }
    if (noInit == true) {
        return node18;
    }
    auto node4 = GET_SKILL_NODE(4, PhaseNode_GetLocation);
    auto node5 = GET_SKILL_NODE(5, PhaseNode_GetRotation);
    if (node4 != nullptr) node18->setPosX(node4->getX());
    if (node4 != nullptr) node18->setPosY(node4->getY());
    if (node5 != nullptr) node18->setRotation(node5->getAngle());
    return node18;
}
//--------------------------------------------------------------------------------
// AttachTo
//
REGISTER_REGISTER_SKILL_NODE(21081, 19) {
    pnode->resizeTrigger(PhaseNode_AttachTo::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_MoveNewPene>(PhaseNode_AttachTo::TRIGGER_DONE, 345, PhaseNode_MoveNewPene::FUNC_DO, &PhaseNode_MoveNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(21081, 19) {
    auto node19 = GET_SKILL_NODE(19, PhaseNode_AttachTo);
    if (node19 == nullptr) {
        node19 = new PhaseNode_AttachTo(19, phase);
        node19->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node19->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node19->setChild(0U);
        node19->setChangeRotation(true);
        node19->setreentry(false);
        CALL_REGISTER_SKILL_NODE(21081, 19, node19)
    }
    if (noInit == true) {
        return node19;
    }
    auto node17 = GET_SKILL_NODE(17, PhaseNode_SpawnCollider);
    if (node17 != nullptr) node19->setParent(node17->getColliderID());
    return node19;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(21081, 21) {
}

REGISTER_CREATE_SKILL_NODE(21081, 21) {
    auto node21 = GET_SKILL_NODE(21, PhaseNode_PlayAnimation);
    if (node21 == nullptr) {
        node21 = new PhaseNode_PlayAnimation(21, phase);
        node21->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node21->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node21->setTarget(0U);
        node21->setAnimation("Skill1S2");
        node21->setParameter("");
        node21->setValue(false);
        CALL_REGISTER_SKILL_NODE(21081, 21, node21)
    }
    if (noInit == true) {
        return node21;
    }
    return node21;
}
//--------------------------------------------------------------------------------
// DestroyCollider
//
REGISTER_REGISTER_SKILL_NODE(21081, 23) {
    pnode->resizeTrigger(PhaseNode_DestroyCollider::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_For>(PhaseNode_DestroyCollider::TRIGGER_DONE, 113, PhaseNode_For::FUNC_START, &PhaseNode_For::Start);
}

REGISTER_CREATE_SKILL_NODE(21081, 23) {
    auto node23 = GET_SKILL_NODE(23, PhaseNode_DestroyCollider);
    if (node23 == nullptr) {
        node23 = new PhaseNode_DestroyCollider(23, phase);
        CALL_REGISTER_SKILL_NODE(21081, 23, node23)
    }
    if (noInit == true) {
        return node23;
    }
    auto node17 = GET_SKILL_NODE(17, PhaseNode_SpawnCollider);
    if (node17 != nullptr) node23->setColliderID(node17->getColliderID());
    return node23;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(21081, 24) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlayAnimation::TRIGGER_DONE, 25, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_PlayAnimation::TRIGGER_DONE, 216, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(21081, 24) {
    auto node24 = GET_SKILL_NODE(24, PhaseNode_PlayAnimation);
    if (node24 == nullptr) {
        node24 = new PhaseNode_PlayAnimation(24, phase);
        node24->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node24->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node24->setTarget(0U);
        node24->setAnimation("Skill1S3");
        node24->setParameter("");
        node24->setValue(false);
        CALL_REGISTER_SKILL_NODE(21081, 24, node24)
    }
    if (noInit == true) {
        return node24;
    }
    return node24;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(21081, 25) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RemoveSkillBuff>(PhaseNode_Delay::TRIGGER_DONE, 295, PhaseNode_RemoveSkillBuff::FUNC_REMOVE, &PhaseNode_RemoveSkillBuff::Remove);
}

REGISTER_CREATE_SKILL_NODE(21081, 25) {
    auto node25 = GET_SKILL_NODE(25, PhaseNode_Delay);
    if (node25 == nullptr) {
        node25 = new PhaseNode_Delay(25, phase);
        node25->setTime(.50f);
        CALL_REGISTER_SKILL_NODE(21081, 25, node25)
    }
    if (noInit == true) {
        return node25;
    }
    return node25;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(21081, 26) {
}

REGISTER_CREATE_SKILL_NODE(21081, 26) {
    auto node26 = GET_SKILL_NODE(26, PhaseNode_EndPhase);
    if (node26 == nullptr) {
        node26 = new PhaseNode_EndPhase(26, phase);
        node26->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node26->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(21081, 26, node26)
    }
    if (noInit == true) {
        return node26;
    }
    return node26;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(21081, 28) {
}

REGISTER_CREATE_SKILL_NODE(21081, 28) {
    auto node28 = GET_SKILL_NODE(28, PhaseNode_TriggerCheck);
    if (node28 == nullptr) {
        node28 = new PhaseNode_TriggerCheck(28, phase);
        auto node2 = GET_SKILL_NODE(2, PhaseNode_TriggerUpdate);
        if (node2 != nullptr) node2->addTriggerCheck(node28);
        
        CALL_REGISTER_SKILL_NODE(21081, 28, node28)
    }
    if (noInit == true) {
        return node28;
    }
    auto node349 = GET_SKILL_NODE(349, PhaseNode_CreateTriggerNewPene);
    if (node349 != nullptr) node28->setTrigger(0, node349->getTriggerID());
    return node28;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(21081, 32) {
}

REGISTER_CREATE_SKILL_NODE(21081, 32) {
    auto node32 = GET_SKILL_NODE(32, PhaseNode_AddSkillBuffs);
    if (node32 == nullptr) {
        node32 = new PhaseNode_AddSkillBuffs(32, phase);
        node32->setConfigID({210811});
        node32->setAttribute({{}});
        CALL_REGISTER_SKILL_NODE(21081, 32, node32)
    }
    if (noInit == true) {
        return node32;
    }
    auto node351 = GET_SKILL_NODE(351, PhaseNode_ActorFilterNewPene);
    if (node351 != nullptr) node32->setTarget(node351->getOutput());
    return node32;
}
//--------------------------------------------------------------------------------
// AttachTo
//
REGISTER_REGISTER_SKILL_NODE(21081, 46) {
    pnode->resizeTrigger(PhaseNode_AttachTo::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuff>(PhaseNode_AttachTo::TRIGGER_DONE, 108, PhaseNode_AddSkillBuff::FUNC_ADD, &PhaseNode_AddSkillBuff::Add);
}

REGISTER_CREATE_SKILL_NODE(21081, 46) {
    auto node46 = GET_SKILL_NODE(46, PhaseNode_AttachTo);
    if (node46 == nullptr) {
        node46 = new PhaseNode_AttachTo(46, phase);
        node46->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node46->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node46->setChangeRotation(false);
        node46->setreentry(true);
        CALL_REGISTER_SKILL_NODE(21081, 46, node46)
    }
    if (noInit == true) {
        return node46;
    }
    auto node17 = GET_SKILL_NODE(17, PhaseNode_SpawnCollider);
    auto node55 = GET_SKILL_NODE(55, PhaseNode_GetUInt64sValue);
    if (node17 != nullptr) node46->setParent(node17->getColliderID());
    if (node55 != nullptr) node46->setChild(node55->getValue());
    return node46;
}
//--------------------------------------------------------------------------------
// GetUInt64sValue
//
REGISTER_REGISTER_SKILL_NODE(21081, 55) {
    pnode->resizeTrigger(PhaseNode_GetUInt64sValue::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AttachTo>(PhaseNode_GetUInt64sValue::TRIGGER_DONE, 46, PhaseNode_AttachTo::FUNC_DO, &PhaseNode_AttachTo::Do);
}

REGISTER_CREATE_SKILL_NODE(21081, 55) {
    auto node55 = GET_SKILL_NODE(55, PhaseNode_GetUInt64sValue);
    if (node55 == nullptr) {
        node55 = new PhaseNode_GetUInt64sValue(55, phase);
        CALL_REGISTER_SKILL_NODE(21081, 55, node55)
    }
    if (noInit == true) {
        return node55;
    }
    auto node351 = GET_SKILL_NODE(351, PhaseNode_ActorFilterNewPene);
    auto node69 = GET_SKILL_NODE(69, PhaseNode_For);
    if (node351 != nullptr) node55->setArr(node351->getOutput());
    if (node69 != nullptr) node55->setIndex(node69->getValue());
    return node55;
}
//--------------------------------------------------------------------------------
// UInt64sSize
//
REGISTER_REGISTER_SKILL_NODE(21081, 68) {
    pnode->resizeTrigger(PhaseNode_UInt64sSize::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_For>(PhaseNode_UInt64sSize::TRIGGER_DONE, 69, PhaseNode_For::FUNC_START, &PhaseNode_For::Start);
    pnode->regTrigger<PhaseNode_SetInt>(PhaseNode_UInt64sSize::TRIGGER_DONE, 111, PhaseNode_SetInt::FUNC_SET, &PhaseNode_SetInt::Set);
}

REGISTER_CREATE_SKILL_NODE(21081, 68) {
    auto node68 = GET_SKILL_NODE(68, PhaseNode_UInt64sSize);
    if (node68 == nullptr) {
        node68 = new PhaseNode_UInt64sSize(68, phase);
        CALL_REGISTER_SKILL_NODE(21081, 68, node68)
    }
    if (noInit == true) {
        return node68;
    }
    auto node351 = GET_SKILL_NODE(351, PhaseNode_ActorFilterNewPene);
    if (node351 != nullptr) node68->setArr(node351->getOutput());
    return node68;
}
//--------------------------------------------------------------------------------
// For
//
REGISTER_REGISTER_SKILL_NODE(21081, 69) {
    pnode->resizeTrigger(PhaseNode_For::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetUInt64sValue>(PhaseNode_For::TRIGGER_DO, 55, PhaseNode_GetUInt64sValue::FUNC_DO, &PhaseNode_GetUInt64sValue::Do);
}

REGISTER_CREATE_SKILL_NODE(21081, 69) {
    auto node69 = GET_SKILL_NODE(69, PhaseNode_For);
    if (node69 == nullptr) {
        node69 = new PhaseNode_For(69, phase);
        node69->setBegin(0);
        node69->setIncrease(1);
        CALL_REGISTER_SKILL_NODE(21081, 69, node69)
    }
    if (noInit == true) {
        return node69;
    }
    auto node68 = GET_SKILL_NODE(68, PhaseNode_UInt64sSize);
    if (node68 != nullptr) node69->setEnd(node68->getSize());
    return node69;
}
//--------------------------------------------------------------------------------
// ForContinue
//
REGISTER_REGISTER_SKILL_NODE(21081, 70) {
}

REGISTER_CREATE_SKILL_NODE(21081, 70) {
    auto node70 = GET_SKILL_NODE(70, PhaseNode_ForContinue);
    if (node70 == nullptr) {
        node70 = new PhaseNode_ForContinue(70, phase);
        CALL_REGISTER_SKILL_NODE(21081, 70, node70)
    }
    if (noInit == true) {
        return node70;
    }
    auto node69 = GET_SKILL_NODE(69, PhaseNode_For);
    if (node69 != nullptr) node70->setFID(node69->getFID());
    return node70;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(21081, 76) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareInt>(PhaseNode_Detect::TRIGGER_ON, 157, PhaseNode_CompareInt::FUNC_COMPARE, &PhaseNode_CompareInt::Compare);
    pnode->regTrigger<PhaseNode_StopSound>(PhaseNode_Detect::TRIGGER_ON, 218, PhaseNode_StopSound::FUNC_STOP, &PhaseNode_StopSound::Stop);
}

REGISTER_CREATE_SKILL_NODE(21081, 76) {
    auto node76 = GET_SKILL_NODE(76, PhaseNode_Detect);
    if (node76 == nullptr) {
        node76 = new PhaseNode_Detect(76, phase);
        node76->setSelf(0U);
        node76->setEvent("");
        node76->setType(PhaseNode_Detect::Detect_Type::Actor_Dead);
        node76->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(21081, 76, node76)
    }
    if (noInit == true) {
        return node76;
    }
    return node76;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(21081, 77) {
}

REGISTER_CREATE_SKILL_NODE(21081, 77) {
    auto node77 = GET_SKILL_NODE(77, PhaseNode_EndPhase);
    if (node77 == nullptr) {
        node77 = new PhaseNode_EndPhase(77, phase);
        node77->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node77->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(21081, 77, node77)
    }
    if (noInit == true) {
        return node77;
    }
    return node77;
}
//--------------------------------------------------------------------------------
// SetUInt64s
//
REGISTER_REGISTER_SKILL_NODE(21081, 106) {
}

REGISTER_CREATE_SKILL_NODE(21081, 106) {
    auto node106 = GET_SKILL_NODE(106, PhaseNode_SetUInt64s);
    if (node106 == nullptr) {
        node106 = new PhaseNode_SetUInt64s(106, phase);
        node106->setName("Targets");
        CALL_REGISTER_SKILL_NODE(21081, 106, node106)
    }
    if (noInit == true) {
        return node106;
    }
    auto node351 = GET_SKILL_NODE(351, PhaseNode_ActorFilterNewPene);
    if (node351 != nullptr) node106->setValue(node351->getOutput());
    return node106;
}
//--------------------------------------------------------------------------------
// AddSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(21081, 108) {
    pnode->resizeTrigger(PhaseNode_AddSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ForContinue>(PhaseNode_AddSkillBuff::TRIGGER_DONE, 70, PhaseNode_ForContinue::FUNC_DO, &PhaseNode_ForContinue::Do);
}

REGISTER_CREATE_SKILL_NODE(21081, 108) {
    auto node108 = GET_SKILL_NODE(108, PhaseNode_AddSkillBuff);
    if (node108 == nullptr) {
        node108 = new PhaseNode_AddSkillBuff(108, phase);
        node108->setConfigID(1);
        node108->setConfigIDs({});
        node108->setAttribute({{}});
        CALL_REGISTER_SKILL_NODE(21081, 108, node108)
    }
    if (noInit == true) {
        return node108;
    }
    auto node55 = GET_SKILL_NODE(55, PhaseNode_GetUInt64sValue);
    if (node55 != nullptr) node108->setTarget(node55->getValue());
    return node108;
}
//--------------------------------------------------------------------------------
// SetInt
//
REGISTER_REGISTER_SKILL_NODE(21081, 111) {
}

REGISTER_CREATE_SKILL_NODE(21081, 111) {
    auto node111 = GET_SKILL_NODE(111, PhaseNode_SetInt);
    if (node111 == nullptr) {
        node111 = new PhaseNode_SetInt(111, phase);
        node111->setName("TargetSize");
        CALL_REGISTER_SKILL_NODE(21081, 111, node111)
    }
    if (noInit == true) {
        return node111;
    }
    auto node68 = GET_SKILL_NODE(68, PhaseNode_UInt64sSize);
    if (node68 != nullptr) node111->setValue(node68->getSize());
    return node111;
}
//--------------------------------------------------------------------------------
// For
//
REGISTER_REGISTER_SKILL_NODE(21081, 113) {
    pnode->resizeTrigger(PhaseNode_For::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetUInt64sValue>(PhaseNode_For::TRIGGER_DO, 115, PhaseNode_GetUInt64sValue::FUNC_DO, &PhaseNode_GetUInt64sValue::Do);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_For::TRIGGER_DONE, 24, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(21081, 113) {
    auto node113 = GET_SKILL_NODE(113, PhaseNode_For);
    if (node113 == nullptr) {
        node113 = new PhaseNode_For(113, phase);
        node113->setBegin(0);
        node113->setIncrease(1);
        CALL_REGISTER_SKILL_NODE(21081, 113, node113)
    }
    if (noInit == true) {
        return node113;
    }
    auto variables = node113->getVariables();
    if (variables != nullptr) {
        node113->setEnd(variables->getVariable<int32_t>(Variable_21081_TargetSize));
    }
    return node113;
}
//--------------------------------------------------------------------------------
// GetUInt64sValue
//
REGISTER_REGISTER_SKILL_NODE(21081, 115) {
    pnode->resizeTrigger(PhaseNode_GetUInt64sValue::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RemoveSkillBuff>(PhaseNode_GetUInt64sValue::TRIGGER_DONE, 116, PhaseNode_RemoveSkillBuff::FUNC_REMOVE, &PhaseNode_RemoveSkillBuff::Remove);
}

REGISTER_CREATE_SKILL_NODE(21081, 115) {
    auto node115 = GET_SKILL_NODE(115, PhaseNode_GetUInt64sValue);
    if (node115 == nullptr) {
        node115 = new PhaseNode_GetUInt64sValue(115, phase);
        CALL_REGISTER_SKILL_NODE(21081, 115, node115)
    }
    if (noInit == true) {
        return node115;
    }
    auto variables = node115->getVariables();
    if (variables != nullptr) {
        node115->setArr(variables->getVariable<UINT64s>(Variable_21081_Targets));
    }
    auto node113 = GET_SKILL_NODE(113, PhaseNode_For);
    if (node113 != nullptr) node115->setIndex(node113->getValue());
    return node115;
}
//--------------------------------------------------------------------------------
// RemoveSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(21081, 116) {
    pnode->resizeTrigger(PhaseNode_RemoveSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ForContinue>(PhaseNode_RemoveSkillBuff::TRIGGER_DONE, 117, PhaseNode_ForContinue::FUNC_DO, &PhaseNode_ForContinue::Do);
}

REGISTER_CREATE_SKILL_NODE(21081, 116) {
    auto node116 = GET_SKILL_NODE(116, PhaseNode_RemoveSkillBuff);
    if (node116 == nullptr) {
        node116 = new PhaseNode_RemoveSkillBuff(116, phase);
        node116->setBuffID(0U);
        node116->setBuffIDs({});
        node116->setConfigID(1);
        CALL_REGISTER_SKILL_NODE(21081, 116, node116)
    }
    if (noInit == true) {
        return node116;
    }
    auto node115 = GET_SKILL_NODE(115, PhaseNode_GetUInt64sValue);
    if (node115 != nullptr) node116->setTarget(node115->getValue());
    return node116;
}
//--------------------------------------------------------------------------------
// ForContinue
//
REGISTER_REGISTER_SKILL_NODE(21081, 117) {
}

REGISTER_CREATE_SKILL_NODE(21081, 117) {
    auto node117 = GET_SKILL_NODE(117, PhaseNode_ForContinue);
    if (node117 == nullptr) {
        node117 = new PhaseNode_ForContinue(117, phase);
        CALL_REGISTER_SKILL_NODE(21081, 117, node117)
    }
    if (noInit == true) {
        return node117;
    }
    auto node113 = GET_SKILL_NODE(113, PhaseNode_For);
    if (node113 != nullptr) node117->setFID(node113->getFID());
    return node117;
}
//--------------------------------------------------------------------------------
// DestroyCollider
//
REGISTER_REGISTER_SKILL_NODE(21081, 125) {
    pnode->resizeTrigger(PhaseNode_DestroyCollider::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_DestroyCollider::TRIGGER_DONE, 211, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(21081, 125) {
    auto node125 = GET_SKILL_NODE(125, PhaseNode_DestroyCollider);
    if (node125 == nullptr) {
        node125 = new PhaseNode_DestroyCollider(125, phase);
        CALL_REGISTER_SKILL_NODE(21081, 125, node125)
    }
    if (noInit == true) {
        return node125;
    }
    auto node12 = GET_SKILL_NODE(12, PhaseNode_SpawnCollider);
    if (node12 != nullptr) node125->setColliderID(node12->getColliderID());
    return node125;
}
//--------------------------------------------------------------------------------
// CompareInt
//
REGISTER_REGISTER_SKILL_NODE(21081, 157) {
    pnode->resizeTrigger(PhaseNode_CompareInt::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_CompareInt::TRIGGER_EQUAL, 77, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
    pnode->regTrigger<PhaseNode_For>(PhaseNode_CompareInt::TRIGGER_GREATER, 159, PhaseNode_For::FUNC_START, &PhaseNode_For::Start);
}

REGISTER_CREATE_SKILL_NODE(21081, 157) {
    auto node157 = GET_SKILL_NODE(157, PhaseNode_CompareInt);
    if (node157 == nullptr) {
        node157 = new PhaseNode_CompareInt(157, phase);
        node157->setB(0);
        CALL_REGISTER_SKILL_NODE(21081, 157, node157)
    }
    if (noInit == true) {
        return node157;
    }
    auto variables = node157->getVariables();
    if (variables != nullptr) {
        node157->setA(variables->getVariable<int32_t>(Variable_21081_TargetSize));
    }
    return node157;
}
//--------------------------------------------------------------------------------
// For
//
REGISTER_REGISTER_SKILL_NODE(21081, 159) {
    pnode->resizeTrigger(PhaseNode_For::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetUInt64sValue>(PhaseNode_For::TRIGGER_DO, 161, PhaseNode_GetUInt64sValue::FUNC_DO, &PhaseNode_GetUInt64sValue::Do);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_For::TRIGGER_DONE, 77, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(21081, 159) {
    auto node159 = GET_SKILL_NODE(159, PhaseNode_For);
    if (node159 == nullptr) {
        node159 = new PhaseNode_For(159, phase);
        node159->setBegin(0);
        node159->setIncrease(1);
        CALL_REGISTER_SKILL_NODE(21081, 159, node159)
    }
    if (noInit == true) {
        return node159;
    }
    auto variables = node159->getVariables();
    if (variables != nullptr) {
        node159->setEnd(variables->getVariable<int32_t>(Variable_21081_TargetSize));
    }
    return node159;
}
//--------------------------------------------------------------------------------
// GetUInt64sValue
//
REGISTER_REGISTER_SKILL_NODE(21081, 161) {
    pnode->resizeTrigger(PhaseNode_GetUInt64sValue::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RemoveSkillBuff>(PhaseNode_GetUInt64sValue::TRIGGER_DONE, 162, PhaseNode_RemoveSkillBuff::FUNC_REMOVE, &PhaseNode_RemoveSkillBuff::Remove);
}

REGISTER_CREATE_SKILL_NODE(21081, 161) {
    auto node161 = GET_SKILL_NODE(161, PhaseNode_GetUInt64sValue);
    if (node161 == nullptr) {
        node161 = new PhaseNode_GetUInt64sValue(161, phase);
        CALL_REGISTER_SKILL_NODE(21081, 161, node161)
    }
    if (noInit == true) {
        return node161;
    }
    auto variables = node161->getVariables();
    if (variables != nullptr) {
        node161->setArr(variables->getVariable<UINT64s>(Variable_21081_Targets));
    }
    auto node159 = GET_SKILL_NODE(159, PhaseNode_For);
    if (node159 != nullptr) node161->setIndex(node159->getValue());
    return node161;
}
//--------------------------------------------------------------------------------
// RemoveSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(21081, 162) {
    pnode->resizeTrigger(PhaseNode_RemoveSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ForContinue>(PhaseNode_RemoveSkillBuff::TRIGGER_DONE, 163, PhaseNode_ForContinue::FUNC_DO, &PhaseNode_ForContinue::Do);
}

REGISTER_CREATE_SKILL_NODE(21081, 162) {
    auto node162 = GET_SKILL_NODE(162, PhaseNode_RemoveSkillBuff);
    if (node162 == nullptr) {
        node162 = new PhaseNode_RemoveSkillBuff(162, phase);
        node162->setBuffID(0U);
        node162->setBuffIDs({});
        node162->setConfigID(1);
        CALL_REGISTER_SKILL_NODE(21081, 162, node162)
    }
    if (noInit == true) {
        return node162;
    }
    auto node161 = GET_SKILL_NODE(161, PhaseNode_GetUInt64sValue);
    if (node161 != nullptr) node162->setTarget(node161->getValue());
    return node162;
}
//--------------------------------------------------------------------------------
// ForContinue
//
REGISTER_REGISTER_SKILL_NODE(21081, 163) {
}

REGISTER_CREATE_SKILL_NODE(21081, 163) {
    auto node163 = GET_SKILL_NODE(163, PhaseNode_ForContinue);
    if (node163 == nullptr) {
        node163 = new PhaseNode_ForContinue(163, phase);
        CALL_REGISTER_SKILL_NODE(21081, 163, node163)
    }
    if (noInit == true) {
        return node163;
    }
    auto node159 = GET_SKILL_NODE(159, PhaseNode_For);
    if (node159 != nullptr) node163->setFID(node159->getFID());
    return node163;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(21081, 209) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlaySound::TRIGGER_DONE, 16, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(21081, 209) {
    auto node209 = GET_SKILL_NODE(209, PhaseNode_PlaySound);
    if (node209 == nullptr) {
        node209 = new PhaseNode_PlaySound(209, phase);
        node209->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node209->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node209->setSoundID("SE_MON2108_ATK_P1");
        node209->setTarget(0U);
        node209->setUsePos(false);
        node209->setPosX(.00f);
        node209->setPosY(.00f);
        node209->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(21081, 209, node209)
    }
    if (noInit == true) {
        return node209;
    }
    return node209;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(21081, 211) {
}

REGISTER_CREATE_SKILL_NODE(21081, 211) {
    auto node211 = GET_SKILL_NODE(211, PhaseNode_PlaySound);
    if (node211 == nullptr) {
        node211 = new PhaseNode_PlaySound(211, phase);
        node211->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node211->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node211->setSoundID("SE_MON2108_ATK_P2");
        node211->setTarget(0U);
        node211->setUsePos(false);
        node211->setPosX(.00f);
        node211->setPosY(.00f);
        node211->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(21081, 211, node211)
    }
    if (noInit == true) {
        return node211;
    }
    return node211;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(21081, 216) {
}

REGISTER_CREATE_SKILL_NODE(21081, 216) {
    auto node216 = GET_SKILL_NODE(216, PhaseNode_PlaySound);
    if (node216 == nullptr) {
        node216 = new PhaseNode_PlaySound(216, phase);
        node216->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node216->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node216->setSoundID("SE_MON2108_ATK_P3");
        node216->setTarget(0U);
        node216->setUsePos(false);
        node216->setPosX(.00f);
        node216->setPosY(.00f);
        node216->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(21081, 216, node216)
    }
    if (noInit == true) {
        return node216;
    }
    return node216;
}
//--------------------------------------------------------------------------------
// StopSound
//
REGISTER_REGISTER_SKILL_NODE(21081, 218) {
    pnode->resizeTrigger(PhaseNode_StopSound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StopSound>(PhaseNode_StopSound::TRIGGER_DONE, 220, PhaseNode_StopSound::FUNC_STOP, &PhaseNode_StopSound::Stop);
}

REGISTER_CREATE_SKILL_NODE(21081, 218) {
    auto node218 = GET_SKILL_NODE(218, PhaseNode_StopSound);
    if (node218 == nullptr) {
        node218 = new PhaseNode_StopSound(218, phase);
        node218->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node218->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node218->setSoundID("SE_MON2108_ATK_P1 ");
        CALL_REGISTER_SKILL_NODE(21081, 218, node218)
    }
    if (noInit == true) {
        return node218;
    }
    return node218;
}
//--------------------------------------------------------------------------------
// StopSound
//
REGISTER_REGISTER_SKILL_NODE(21081, 220) {
    pnode->resizeTrigger(PhaseNode_StopSound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StopSound>(PhaseNode_StopSound::TRIGGER_DONE, 222, PhaseNode_StopSound::FUNC_STOP, &PhaseNode_StopSound::Stop);
}

REGISTER_CREATE_SKILL_NODE(21081, 220) {
    auto node220 = GET_SKILL_NODE(220, PhaseNode_StopSound);
    if (node220 == nullptr) {
        node220 = new PhaseNode_StopSound(220, phase);
        node220->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node220->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node220->setSoundID("SE_MON2108_ATK_P2");
        CALL_REGISTER_SKILL_NODE(21081, 220, node220)
    }
    if (noInit == true) {
        return node220;
    }
    return node220;
}
//--------------------------------------------------------------------------------
// StopSound
//
REGISTER_REGISTER_SKILL_NODE(21081, 222) {
}

REGISTER_CREATE_SKILL_NODE(21081, 222) {
    auto node222 = GET_SKILL_NODE(222, PhaseNode_StopSound);
    if (node222 == nullptr) {
        node222 = new PhaseNode_StopSound(222, phase);
        node222->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node222->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node222->setSoundID("SE_MON2108_ATK_P3");
        CALL_REGISTER_SKILL_NODE(21081, 222, node222)
    }
    if (noInit == true) {
        return node222;
    }
    return node222;
}
//--------------------------------------------------------------------------------
// AddSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(21081, 293) {
    pnode->resizeTrigger(PhaseNode_AddSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnCollider>(PhaseNode_AddSkillBuff::TRIGGER_DONE, 12, PhaseNode_SpawnCollider::FUNC_DO, &PhaseNode_SpawnCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(21081, 293) {
    auto node293 = GET_SKILL_NODE(293, PhaseNode_AddSkillBuff);
    if (node293 == nullptr) {
        node293 = new PhaseNode_AddSkillBuff(293, phase);
        node293->setConfigID(1);
        node293->setConfigIDs({});
        node293->setTarget(0U);
        node293->setAttribute({{}});
        CALL_REGISTER_SKILL_NODE(21081, 293, node293)
    }
    if (noInit == true) {
        return node293;
    }
    return node293;
}
//--------------------------------------------------------------------------------
// RemoveSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(21081, 295) {
    pnode->resizeTrigger(PhaseNode_RemoveSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_RemoveSkillBuff::TRIGGER_DONE, 26, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(21081, 295) {
    auto node295 = GET_SKILL_NODE(295, PhaseNode_RemoveSkillBuff);
    if (node295 == nullptr) {
        node295 = new PhaseNode_RemoveSkillBuff(295, phase);
        node295->setBuffID(0U);
        node295->setBuffIDs({});
        node295->setConfigID(0);
        node295->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(21081, 295, node295)
    }
    if (noInit == true) {
        return node295;
    }
    return node295;
}
//--------------------------------------------------------------------------------
// MoveNewPene
//
REGISTER_REGISTER_SKILL_NODE(21081, 345) {
    pnode->resizeTrigger(PhaseNode_MoveNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_DestroyCollider>(PhaseNode_MoveNewPene::TRIGGER_BLOCKBYWALL, 23, PhaseNode_DestroyCollider::FUNC_DO, &PhaseNode_DestroyCollider::Do);
    pnode->regTrigger<PhaseNode_DestroyCollider>(PhaseNode_MoveNewPene::TRIGGER_DONE, 23, PhaseNode_DestroyCollider::FUNC_DO, &PhaseNode_DestroyCollider::Do);
    pnode->regTrigger<PhaseNode_DestroyCollider>(PhaseNode_MoveNewPene::TRIGGER_STARTMOVE, 125, PhaseNode_DestroyCollider::FUNC_DO, &PhaseNode_DestroyCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(21081, 345) {
    auto node345 = GET_SKILL_NODE(345, PhaseNode_MoveNewPene);
    if (node345 == nullptr) {
        node345 = new PhaseNode_MoveNewPene(345, phase);
        node345->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node345->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node345->setPeneType(PhaseNode_MoveNewPene::MoveNewPene_PeneType::Move);
        node345->setPeneValue(0);
        node345->setType(PhaseNode_MoveNewPene::MoveNewPene_Type::Charge);
        node345->getVars().reserve(4);
        node345->getVars().setVariable<float>(0, 12.00f);
        node345->getVars().setVariable<float>(1, 12.00f);
        node345->getVars().setVariable<float>(2, .00f);
        node345->getVars().setVariable<float>(3, .00f);
        node345->setreentry(false);
        node345->setStopWhenFail(true);
        node345->setCheckFaction(PhaseNode_MoveNewPene::MoveNewPene_CheckFaction::Enemy);
        CALL_REGISTER_SKILL_NODE(21081, 345, node345)
    }
    if (noInit == true) {
        return node345;
    }
    auto node17 = GET_SKILL_NODE(17, PhaseNode_SpawnCollider);
    auto node5 = GET_SKILL_NODE(5, PhaseNode_GetRotation);
    if (node17 != nullptr) node345->setTarget(node17->getColliderID());
    if (node5 != nullptr) node345->getVars().setVariable<float>(2, node5->getAngle());
    return node345;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(21081, 349) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 28, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 351, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(21081, 349) {
    auto node349 = GET_SKILL_NODE(349, PhaseNode_CreateTriggerNewPene);
    if (node349 == nullptr) {
        node349 = new PhaseNode_CreateTriggerNewPene(349, phase);
        node349->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::In);
        node349->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node349->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Enemy);
        node349->setOnHero(true);
        node349->setOnMinion(true);
        node349->setOnDestruct(true);
        node349->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(21081, 349, node349)
    }
    if (noInit == true) {
        return node349;
    }
    auto node17 = GET_SKILL_NODE(17, PhaseNode_SpawnCollider);
    if (node17 != nullptr) node349->setColliderID(node17->getColliderID());
    return node349;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(21081, 351) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 32, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
    pnode->regTrigger<PhaseNode_SetUInt64s>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 106, PhaseNode_SetUInt64s::FUNC_SET, &PhaseNode_SetUInt64s::Set);
    pnode->regTrigger<PhaseNode_UInt64sSize>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 68, PhaseNode_UInt64sSize::FUNC_DO, &PhaseNode_UInt64sSize::Do);
}

REGISTER_CREATE_SKILL_NODE(21081, 351) {
    auto node351 = GET_SKILL_NODE(351, PhaseNode_ActorFilterNewPene);
    if (node351 == nullptr) {
        node351 = new PhaseNode_ActorFilterNewPene(351, phase);
        node351->setHero(true);
        node351->setMinion(true);
        node351->setDestruct(true);
        node351->setShield(false);
        node351->setTotalCount(0);
        node351->setPerCount(1);
        CALL_REGISTER_SKILL_NODE(21081, 351, node351)
    }
    if (noInit == true) {
        return node351;
    }
    auto node349 = GET_SKILL_NODE(349, PhaseNode_CreateTriggerNewPene);
    if (node349 != nullptr) node351->setInput(node349->getOther());
    return node351;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(21081, 355) {
}

REGISTER_CREATE_SKILL_NODE(21081, 355) {
    auto node355 = GET_SKILL_NODE(355, PhaseNode_RaiseEvent);
    if (node355 == nullptr) {
        node355 = new PhaseNode_RaiseEvent(355, phase);
        node355->setEvent("MonsterInterrupt");
        node355->setTarget(0U);
        node355->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node355->setTypeParams(0, 0);
        node355->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(21081, 355, node355)
    }
    if (noInit == true) {
        return node355;
    }
    return node355;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(21081, 356) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_Detect::TRIGGER_ON, 359, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(21081, 356) {
    auto node356 = GET_SKILL_NODE(356, PhaseNode_Detect);
    if (node356 == nullptr) {
        node356 = new PhaseNode_Detect(356, phase);
        node356->setSelf(0U);
        node356->setEvent("MonsterInterrupt");
        node356->setType(PhaseNode_Detect::Detect_Type::Interrupt_Skill);
        node356->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(21081, 356, node356)
    }
    if (noInit == true) {
        return node356;
    }
    return node356;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(21081, 357) {
}

REGISTER_CREATE_SKILL_NODE(21081, 357) {
    auto node357 = GET_SKILL_NODE(357, PhaseNode_EndPhase);
    if (node357 == nullptr) {
        node357 = new PhaseNode_EndPhase(357, phase);
        node357->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node357->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(21081, 357, node357)
    }
    if (noInit == true) {
        return node357;
    }
    return node357;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(21081, 359) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_Delay::TRIGGER_DONE, 361, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(21081, 359) {
    auto node359 = GET_SKILL_NODE(359, PhaseNode_Delay);
    if (node359 == nullptr) {
        node359 = new PhaseNode_Delay(359, phase);
        node359->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(21081, 359, node359)
    }
    if (noInit == true) {
        return node359;
    }
    return node359;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(21081, 360) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 357, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(21081, 360) {
    auto node360 = GET_SKILL_NODE(360, PhaseNode_SkillEndNotify);
    if (node360 == nullptr) {
        node360 = new PhaseNode_SkillEndNotify(360, phase);
        node360->setReturnType(false);
        CALL_REGISTER_SKILL_NODE(21081, 360, node360)
    }
    if (noInit == true) {
        return node360;
    }
    return node360;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(21081, 361) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_FALSE, 362, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_TRUE, 360, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
}

REGISTER_CREATE_SKILL_NODE(21081, 361) {
    auto node361 = GET_SKILL_NODE(361, PhaseNode_If);
    if (node361 == nullptr) {
        node361 = new PhaseNode_If(361, phase);
        node361->setCondition(false);
        CALL_REGISTER_SKILL_NODE(21081, 361, node361)
    }
    if (noInit == true) {
        return node361;
    }
    return node361;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(21081, 362) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 357, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(21081, 362) {
    auto node362 = GET_SKILL_NODE(362, PhaseNode_SkillEndNotify);
    if (node362 == nullptr) {
        node362 = new PhaseNode_SkillEndNotify(362, phase);
        node362->setReturnType(true);
        CALL_REGISTER_SKILL_NODE(21081, 362, node362)
    }
    if (noInit == true) {
        return node362;
    }
    return node362;
}

//--------------------------------------------------------------------------------
// SkillCreator_21081
//
class SkillCreator_21081 : public SkillCreator {
public:
    SkillCreator_21081() {}
    virtual ~SkillCreator_21081() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_21081

//--------------------------------------------------------------------------------
// SkillPhase_21081
//
class SkillPhase_21081 : public SkillPhase {
public:
    SkillPhase_21081(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_21081() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(21081, 1) // StartPhase
        CASE_CREATE_SKILL_NODE(21081, 2) // TriggerUpdate
        CASE_CREATE_SKILL_NODE(21081, 4) // GetLocation
        CASE_CREATE_SKILL_NODE(21081, 5) // GetRotation
        CASE_CREATE_SKILL_NODE(21081, 11) // ResetCD
        CASE_CREATE_SKILL_NODE(21081, 12) // SpawnCollider
        CASE_CREATE_SKILL_NODE(21081, 15) // PlayAnimation
        CASE_CREATE_SKILL_NODE(21081, 16) // Delay
        CASE_CREATE_SKILL_NODE(21081, 17) // SpawnCollider
        CASE_CREATE_SKILL_NODE(21081, 18) // OffsetCalculate
        CASE_CREATE_SKILL_NODE(21081, 19) // AttachTo
        CASE_CREATE_SKILL_NODE(21081, 21) // PlayAnimation
        CASE_CREATE_SKILL_NODE(21081, 23) // DestroyCollider
        CASE_CREATE_SKILL_NODE(21081, 24) // PlayAnimation
        CASE_CREATE_SKILL_NODE(21081, 25) // Delay
        CASE_CREATE_SKILL_NODE(21081, 26) // EndPhase
        CASE_CREATE_SKILL_NODE(21081, 28) // TriggerCheck
        CASE_CREATE_SKILL_NODE(21081, 32) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(21081, 46) // AttachTo
        CASE_CREATE_SKILL_NODE(21081, 55) // GetUInt64sValue
        CASE_CREATE_SKILL_NODE(21081, 68) // UInt64sSize
        CASE_CREATE_SKILL_NODE(21081, 69) // For
        CASE_CREATE_SKILL_NODE(21081, 70) // ForContinue
        CASE_CREATE_SKILL_NODE(21081, 76) // Detect
        CASE_CREATE_SKILL_NODE(21081, 77) // EndPhase
        CASE_CREATE_SKILL_NODE(21081, 106) // SetUInt64s
        CASE_CREATE_SKILL_NODE(21081, 108) // AddSkillBuff
        CASE_CREATE_SKILL_NODE(21081, 111) // SetInt
        CASE_CREATE_SKILL_NODE(21081, 113) // For
        CASE_CREATE_SKILL_NODE(21081, 115) // GetUInt64sValue
        CASE_CREATE_SKILL_NODE(21081, 116) // RemoveSkillBuff
        CASE_CREATE_SKILL_NODE(21081, 117) // ForContinue
        CASE_CREATE_SKILL_NODE(21081, 125) // DestroyCollider
        CASE_CREATE_SKILL_NODE(21081, 157) // CompareInt
        CASE_CREATE_SKILL_NODE(21081, 159) // For
        CASE_CREATE_SKILL_NODE(21081, 161) // GetUInt64sValue
        CASE_CREATE_SKILL_NODE(21081, 162) // RemoveSkillBuff
        CASE_CREATE_SKILL_NODE(21081, 163) // ForContinue
        CASE_CREATE_SKILL_NODE(21081, 209) // PlaySound
        CASE_CREATE_SKILL_NODE(21081, 211) // PlaySound
        CASE_CREATE_SKILL_NODE(21081, 216) // PlaySound
        CASE_CREATE_SKILL_NODE(21081, 218) // StopSound
        CASE_CREATE_SKILL_NODE(21081, 220) // StopSound
        CASE_CREATE_SKILL_NODE(21081, 222) // StopSound
        CASE_CREATE_SKILL_NODE(21081, 293) // AddSkillBuff
        CASE_CREATE_SKILL_NODE(21081, 295) // RemoveSkillBuff
        CASE_CREATE_SKILL_NODE(21081, 345) // MoveNewPene
        CASE_CREATE_SKILL_NODE(21081, 349) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(21081, 351) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(21081, 355) // RaiseEvent
        CASE_CREATE_SKILL_NODE(21081, 356) // Detect
        CASE_CREATE_SKILL_NODE(21081, 357) // EndPhase
        CASE_CREATE_SKILL_NODE(21081, 359) // Delay
        CASE_CREATE_SKILL_NODE(21081, 360) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(21081, 361) // If
        CASE_CREATE_SKILL_NODE(21081, 362) // SkillEndNotify
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_21081

SkillLogic* SkillCreator_21081::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //设置变量
    Variable_21081_Targets = logic->getVariables().setVariable<UINT64s>("Targets");
    Variable_21081_TargetSize = logic->getVariables().setVariable<int32_t>("TargetSize");
    //创建阶段phase
    auto phase = new SkillPhase_21081(1, logic, 3);
    //设置phase执行器
    phase->setRunPhaseNode(1, 1);
    phase->setRunPhaseNode(2, 2);
    phase->setDetectPhaseNode(3, 76);
    phase->setDetectPhaseNode(3, 356);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_21081::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
