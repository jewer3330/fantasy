#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

#include "skill_psnode_attachto.h"
#include "skill_psnode_delay.h"
#include "skill_psnode_endphase.h"
#include "skill_psnode_getbbparamuint64.h"
#include "skill_psnode_getlinerotation.h"
#include "skill_psnode_getlocation.h"
#include "skill_psnode_getrotation.h"
#include "skill_psnode_movenewpene.h"
#include "skill_psnode_offsetcalculate.h"
#include "skill_psnode_playanimation.h"
#include "skill_psnode_playeffect.h"
#include "skill_psnode_resetcd.h"
#include "skill_psnode_spawncollider.h"
#include "skill_psnode_startphase.h"
#include "skill_psnode_triggerupdate.h"

namespace pvp {

//变量声明
//--------------------------------------------------------------------------------
// StartPhase
//
REGISTER_REGISTER_SKILL_NODE(23053, 2) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_StartPhase::TRIGGER_START, 6, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(23053, 2) {
    auto node2 = GET_SKILL_NODE(2, PhaseNode_StartPhase);
    if (node2 == nullptr) {
        node2 = new PhaseNode_StartPhase(2, phase);
        CALL_REGISTER_SKILL_NODE(23053, 2, node2)
    }
    if (noInit == true) {
        return node2;
    }
    return node2;
}
//--------------------------------------------------------------------------------
// TriggerUpdate
//
REGISTER_REGISTER_SKILL_NODE(23053, 4) {
}

REGISTER_CREATE_SKILL_NODE(23053, 4) {
    auto node4 = GET_SKILL_NODE(4, PhaseNode_TriggerUpdate);
    if (node4 == nullptr) {
        node4 = new PhaseNode_TriggerUpdate(4, phase);
        CALL_REGISTER_SKILL_NODE(23053, 4, node4)
    }
    if (noInit == true) {
        return node4;
    }
    return node4;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(23053, 6) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_ResetCD::TRIGGER_DONE, 8, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(23053, 6) {
    auto node6 = GET_SKILL_NODE(6, PhaseNode_ResetCD);
    if (node6 == nullptr) {
        node6 = new PhaseNode_ResetCD(6, phase);
        node6->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node6->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node6->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(23053, 6, node6)
    }
    if (noInit == true) {
        return node6;
    }
    return node6;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(23053, 8) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetRotation>(PhaseNode_GetLocation::TRIGGER_DONE, 10, PhaseNode_GetRotation::FUNC_DO, &PhaseNode_GetRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(23053, 8) {
    auto node8 = GET_SKILL_NODE(8, PhaseNode_GetLocation);
    if (node8 == nullptr) {
        node8 = new PhaseNode_GetLocation(8, phase);
        node8->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node8->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(23053, 8, node8)
    }
    if (noInit == true) {
        return node8;
    }
    return node8;
}
//--------------------------------------------------------------------------------
// GetRotation
//
REGISTER_REGISTER_SKILL_NODE(23053, 10) {
    pnode->resizeTrigger(PhaseNode_GetRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_OffsetCalculate>(PhaseNode_GetRotation::TRIGGER_DONE, 12, PhaseNode_OffsetCalculate::FUNC_DO, &PhaseNode_OffsetCalculate::Do);
}

REGISTER_CREATE_SKILL_NODE(23053, 10) {
    auto node10 = GET_SKILL_NODE(10, PhaseNode_GetRotation);
    if (node10 == nullptr) {
        node10 = new PhaseNode_GetRotation(10, phase);
        node10->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node10->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(23053, 10, node10)
    }
    if (noInit == true) {
        return node10;
    }
    return node10;
}
//--------------------------------------------------------------------------------
// OffsetCalculate
//
REGISTER_REGISTER_SKILL_NODE(23053, 12) {
    pnode->resizeTrigger(PhaseNode_OffsetCalculate::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 14, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(23053, 12) {
    auto node12 = GET_SKILL_NODE(12, PhaseNode_OffsetCalculate);
    if (node12 == nullptr) {
        node12 = new PhaseNode_OffsetCalculate(12, phase);
        node12->setPosZ(.00f);
        node12->setOffsetX(.00f);
        node12->setOffsetY(.00f);
        node12->setOffsetZ(.00f);
        node12->setRotOffset(.00f);
        CALL_REGISTER_SKILL_NODE(23053, 12, node12)
    }
    if (noInit == true) {
        return node12;
    }
    auto node8 = GET_SKILL_NODE(8, PhaseNode_GetLocation);
    auto node10 = GET_SKILL_NODE(10, PhaseNode_GetRotation);
    if (node8 != nullptr) node12->setPosX(node8->getX());
    if (node8 != nullptr) node12->setPosY(node8->getY());
    if (node10 != nullptr) node12->setRotation(node10->getAngle());
    return node12;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(23053, 14) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_PlayEffect::TRIGGER_DONE, 16, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(23053, 14) {
    auto node14 = GET_SKILL_NODE(14, PhaseNode_PlayEffect);
    if (node14 == nullptr) {
        node14 = new PhaseNode_PlayEffect(14, phase);
        node14->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node14->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node14->setEffectID(230531);
        node14->setChangeColor(false);
        node14->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node14->getVars().reserve(3);
        node14->getVars().setVariable<float>(0, .00f);
        node14->getVars().setVariable<float>(1, .00f);
        node14->getVars().setVariable<float>(2, .00f);
        node14->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(23053, 14, node14)
    }
    if (noInit == true) {
        return node14;
    }
    auto node12 = GET_SKILL_NODE(12, PhaseNode_OffsetCalculate);
    if (node12 != nullptr) node14->getVars().setVariable<float>(0, node12->getOutPosX());
    if (node12 != nullptr) node14->getVars().setVariable<float>(1, node12->getOutPosY());
    if (node12 != nullptr) node14->getVars().setVariable<float>(2, node12->getOutPosZ());
    if (node12 != nullptr) node14->setRotation(node12->getOutRotation());
    return node14;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(23053, 16) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlayAnimation::TRIGGER_DONE, 18, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(23053, 16) {
    auto node16 = GET_SKILL_NODE(16, PhaseNode_PlayAnimation);
    if (node16 == nullptr) {
        node16 = new PhaseNode_PlayAnimation(16, phase);
        node16->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node16->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node16->setTarget(0U);
        node16->setAnimation("Skill3S1");
        node16->setParameter("");
        node16->setValue(false);
        CALL_REGISTER_SKILL_NODE(23053, 16, node16)
    }
    if (noInit == true) {
        return node16;
    }
    return node16;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(23053, 18) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_Delay::TRIGGER_DONE, 20, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(23053, 18) {
    auto node18 = GET_SKILL_NODE(18, PhaseNode_Delay);
    if (node18 == nullptr) {
        node18 = new PhaseNode_Delay(18, phase);
        node18->setTime(1.10f);
        CALL_REGISTER_SKILL_NODE(23053, 18, node18)
    }
    if (noInit == true) {
        return node18;
    }
    return node18;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(23053, 20) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlayEffect::TRIGGER_DONE, 28, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(23053, 20) {
    auto node20 = GET_SKILL_NODE(20, PhaseNode_PlayEffect);
    if (node20 == nullptr) {
        node20 = new PhaseNode_PlayEffect(20, phase);
        node20->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node20->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node20->setEffectID(230532);
        node20->setChangeColor(false);
        node20->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node20->getVars().reserve(3);
        node20->getVars().setVariable<float>(0, .00f);
        node20->getVars().setVariable<float>(1, .00f);
        node20->getVars().setVariable<float>(2, .00f);
        node20->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(23053, 20, node20)
    }
    if (noInit == true) {
        return node20;
    }
    auto node12 = GET_SKILL_NODE(12, PhaseNode_OffsetCalculate);
    if (node12 != nullptr) node20->getVars().setVariable<float>(0, node12->getOutPosX());
    if (node12 != nullptr) node20->getVars().setVariable<float>(1, node12->getOutPosY());
    if (node12 != nullptr) node20->getVars().setVariable<float>(2, node12->getOutPosZ());
    if (node12 != nullptr) node20->setRotation(node12->getOutRotation());
    return node20;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(23053, 28) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetBBParamUInt64>(PhaseNode_Delay::TRIGGER_DONE, 97, PhaseNode_GetBBParamUInt64::FUNC_DO, &PhaseNode_GetBBParamUInt64::Do);
}

REGISTER_CREATE_SKILL_NODE(23053, 28) {
    auto node28 = GET_SKILL_NODE(28, PhaseNode_Delay);
    if (node28 == nullptr) {
        node28 = new PhaseNode_Delay(28, phase);
        node28->setTime(.40f);
        CALL_REGISTER_SKILL_NODE(23053, 28, node28)
    }
    if (noInit == true) {
        return node28;
    }
    return node28;
}
//--------------------------------------------------------------------------------
// OffsetCalculate
//
REGISTER_REGISTER_SKILL_NODE(23053, 35) {
    pnode->resizeTrigger(PhaseNode_OffsetCalculate::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_MoveNewPene>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 163, PhaseNode_MoveNewPene::FUNC_DO, &PhaseNode_MoveNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(23053, 35) {
    auto node35 = GET_SKILL_NODE(35, PhaseNode_OffsetCalculate);
    if (node35 == nullptr) {
        node35 = new PhaseNode_OffsetCalculate(35, phase);
        node35->setPosZ(.00f);
        node35->setOffsetX(.00f);
        node35->setOffsetY(3.00f);
        node35->setOffsetZ(.00f);
        node35->setRotOffset(180.00f);
        CALL_REGISTER_SKILL_NODE(23053, 35, node35)
    }
    if (noInit == true) {
        return node35;
    }
    auto node99 = GET_SKILL_NODE(99, PhaseNode_GetLocation);
    auto node45 = GET_SKILL_NODE(45, PhaseNode_GetLineRotation);
    if (node99 != nullptr) node35->setPosX(node99->getX());
    if (node99 != nullptr) node35->setPosY(node99->getY());
    if (node45 != nullptr) node35->setRotation(node45->getRotation());
    return node35;
}
//--------------------------------------------------------------------------------
// GetLineRotation
//
REGISTER_REGISTER_SKILL_NODE(23053, 45) {
    pnode->resizeTrigger(PhaseNode_GetLineRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnCollider>(PhaseNode_GetLineRotation::TRIGGER_DONE, 59, PhaseNode_SpawnCollider::FUNC_DO, &PhaseNode_SpawnCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(23053, 45) {
    auto node45 = GET_SKILL_NODE(45, PhaseNode_GetLineRotation);
    if (node45 == nullptr) {
        node45 = new PhaseNode_GetLineRotation(45, phase);
        CALL_REGISTER_SKILL_NODE(23053, 45, node45)
    }
    if (noInit == true) {
        return node45;
    }
    auto node8 = GET_SKILL_NODE(8, PhaseNode_GetLocation);
    auto node99 = GET_SKILL_NODE(99, PhaseNode_GetLocation);
    if (node8 != nullptr) node45->setStartX(node8->getX());
    if (node8 != nullptr) node45->setStartY(node8->getY());
    if (node99 != nullptr) node45->setEndX(node99->getX());
    if (node99 != nullptr) node45->setEndY(node99->getY());
    return node45;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(23053, 50) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_PlayAnimation::TRIGGER_DONE, 153, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(23053, 50) {
    auto node50 = GET_SKILL_NODE(50, PhaseNode_PlayAnimation);
    if (node50 == nullptr) {
        node50 = new PhaseNode_PlayAnimation(50, phase);
        node50->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node50->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node50->setTarget(0U);
        node50->setAnimation("Skill3S2");
        node50->setParameter("");
        node50->setValue(false);
        CALL_REGISTER_SKILL_NODE(23053, 50, node50)
    }
    if (noInit == true) {
        return node50;
    }
    return node50;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(23053, 52) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_Delay::TRIGGER_DONE, 54, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(23053, 52) {
    auto node52 = GET_SKILL_NODE(52, PhaseNode_Delay);
    if (node52 == nullptr) {
        node52 = new PhaseNode_Delay(52, phase);
        node52->setTime(1.70f);
        CALL_REGISTER_SKILL_NODE(23053, 52, node52)
    }
    if (noInit == true) {
        return node52;
    }
    return node52;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(23053, 54) {
}

REGISTER_CREATE_SKILL_NODE(23053, 54) {
    auto node54 = GET_SKILL_NODE(54, PhaseNode_EndPhase);
    if (node54 == nullptr) {
        node54 = new PhaseNode_EndPhase(54, phase);
        node54->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node54->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(23053, 54, node54)
    }
    if (noInit == true) {
        return node54;
    }
    return node54;
}
//--------------------------------------------------------------------------------
// SpawnCollider
//
REGISTER_REGISTER_SKILL_NODE(23053, 59) {
    pnode->resizeTrigger(PhaseNode_SpawnCollider::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_OffsetCalculate>(PhaseNode_SpawnCollider::TRIGGER_DONE, 35, PhaseNode_OffsetCalculate::FUNC_DO, &PhaseNode_OffsetCalculate::Do);
}

REGISTER_CREATE_SKILL_NODE(23053, 59) {
    auto node59 = GET_SKILL_NODE(59, PhaseNode_SpawnCollider);
    if (node59 == nullptr) {
        node59 = new PhaseNode_SpawnCollider(59, phase);
        node59->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node59->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node59->setMesh("");
        node59->setMeshScale(.00f);
        node59->setEffectID(0);
        node59->setEffectScale(.00f);
        node59->setType(PhaseNode_SpawnCollider::SpawnCollider_Type::Circle);
        node59->setTypeParams(0, .00f);
        node59->setTime(.00f);
        node59->setPosZ(.00f);
        node59->setreentry(false);
        node59->setCheckPeneSound(false);
        CALL_REGISTER_SKILL_NODE(23053, 59, node59)
    }
    if (noInit == true) {
        return node59;
    }
    auto node99 = GET_SKILL_NODE(99, PhaseNode_GetLocation);
    auto node10 = GET_SKILL_NODE(10, PhaseNode_GetRotation);
    if (node99 != nullptr) node59->setPosX(node99->getX());
    if (node99 != nullptr) node59->setPosY(node99->getY());
    if (node10 != nullptr) node59->setRotation(node10->getAngle());
    return node59;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(23053, 63) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_MoveNewPene>(PhaseNode_GetLocation::TRIGGER_DONE, 165, PhaseNode_MoveNewPene::FUNC_DO, &PhaseNode_MoveNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(23053, 63) {
    auto node63 = GET_SKILL_NODE(63, PhaseNode_GetLocation);
    if (node63 == nullptr) {
        node63 = new PhaseNode_GetLocation(63, phase);
        node63->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        CALL_REGISTER_SKILL_NODE(23053, 63, node63)
    }
    if (noInit == true) {
        return node63;
    }
    auto node59 = GET_SKILL_NODE(59, PhaseNode_SpawnCollider);
    if (node59 != nullptr) node63->setTarget(node59->getColliderID());
    return node63;
}
//--------------------------------------------------------------------------------
// SpawnCollider
//
REGISTER_REGISTER_SKILL_NODE(23053, 65) {
    pnode->resizeTrigger(PhaseNode_SpawnCollider::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AttachTo>(PhaseNode_SpawnCollider::TRIGGER_DONE, 67, PhaseNode_AttachTo::FUNC_DO, &PhaseNode_AttachTo::Do);
}

REGISTER_CREATE_SKILL_NODE(23053, 65) {
    auto node65 = GET_SKILL_NODE(65, PhaseNode_SpawnCollider);
    if (node65 == nullptr) {
        node65 = new PhaseNode_SpawnCollider(65, phase);
        node65->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node65->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node65->setMesh("");
        node65->setMeshScale(.00f);
        node65->setEffectID(0);
        node65->setEffectScale(.00f);
        node65->setType(PhaseNode_SpawnCollider::SpawnCollider_Type::Circle);
        node65->setTypeParams(0, .00f);
        node65->setTime(.00f);
        node65->setPosZ(.00f);
        node65->setreentry(false);
        node65->setCheckPeneSound(false);
        CALL_REGISTER_SKILL_NODE(23053, 65, node65)
    }
    if (noInit == true) {
        return node65;
    }
    auto node8 = GET_SKILL_NODE(8, PhaseNode_GetLocation);
    auto node35 = GET_SKILL_NODE(35, PhaseNode_OffsetCalculate);
    if (node8 != nullptr) node65->setPosX(node8->getX());
    if (node8 != nullptr) node65->setPosY(node8->getY());
    if (node35 != nullptr) node65->setRotation(node35->getOutRotation());
    return node65;
}
//--------------------------------------------------------------------------------
// AttachTo
//
REGISTER_REGISTER_SKILL_NODE(23053, 67) {
    pnode->resizeTrigger(PhaseNode_AttachTo::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_AttachTo::TRIGGER_DONE, 63, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(23053, 67) {
    auto node67 = GET_SKILL_NODE(67, PhaseNode_AttachTo);
    if (node67 == nullptr) {
        node67 = new PhaseNode_AttachTo(67, phase);
        node67->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node67->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node67->setChild(0U);
        node67->setChangeRotation(true);
        node67->setreentry(false);
        CALL_REGISTER_SKILL_NODE(23053, 67, node67)
    }
    if (noInit == true) {
        return node67;
    }
    auto node65 = GET_SKILL_NODE(65, PhaseNode_SpawnCollider);
    if (node65 != nullptr) node67->setParent(node65->getColliderID());
    return node67;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(23053, 83) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLineRotation>(PhaseNode_Delay::TRIGGER_DONE, 45, PhaseNode_GetLineRotation::FUNC_DO, &PhaseNode_GetLineRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(23053, 83) {
    auto node83 = GET_SKILL_NODE(83, PhaseNode_Delay);
    if (node83 == nullptr) {
        node83 = new PhaseNode_Delay(83, phase);
        node83->setTime(1.00f);
        CALL_REGISTER_SKILL_NODE(23053, 83, node83)
    }
    if (noInit == true) {
        return node83;
    }
    return node83;
}
//--------------------------------------------------------------------------------
// GetBBParamUInt64
//
REGISTER_REGISTER_SKILL_NODE(23053, 97) {
    pnode->resizeTrigger(PhaseNode_GetBBParamUInt64::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_GetBBParamUInt64::TRIGGER_DONE, 99, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(23053, 97) {
    auto node97 = GET_SKILL_NODE(97, PhaseNode_GetBBParamUInt64);
    if (node97 == nullptr) {
        node97 = new PhaseNode_GetBBParamUInt64(97, phase);
        node97->setBBName("AtkTarget");
        CALL_REGISTER_SKILL_NODE(23053, 97, node97)
    }
    if (noInit == true) {
        return node97;
    }
    return node97;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(23053, 99) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_GetLocation::TRIGGER_DONE, 83, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(23053, 99) {
    auto node99 = GET_SKILL_NODE(99, PhaseNode_GetLocation);
    if (node99 == nullptr) {
        node99 = new PhaseNode_GetLocation(99, phase);
        node99->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        CALL_REGISTER_SKILL_NODE(23053, 99, node99)
    }
    if (noInit == true) {
        return node99;
    }
    auto node97 = GET_SKILL_NODE(97, PhaseNode_GetBBParamUInt64);
    if (node97 != nullptr) node99->setTarget(node97->getValue());
    return node99;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(23053, 153) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetRotation>(PhaseNode_GetLocation::TRIGGER_DONE, 157, PhaseNode_GetRotation::FUNC_DO, &PhaseNode_GetRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(23053, 153) {
    auto node153 = GET_SKILL_NODE(153, PhaseNode_GetLocation);
    if (node153 == nullptr) {
        node153 = new PhaseNode_GetLocation(153, phase);
        node153->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        CALL_REGISTER_SKILL_NODE(23053, 153, node153)
    }
    if (noInit == true) {
        return node153;
    }
    auto node65 = GET_SKILL_NODE(65, PhaseNode_SpawnCollider);
    if (node65 != nullptr) node153->setTarget(node65->getColliderID());
    return node153;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(23053, 155) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlayEffect::TRIGGER_DONE, 52, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(23053, 155) {
    auto node155 = GET_SKILL_NODE(155, PhaseNode_PlayEffect);
    if (node155 == nullptr) {
        node155 = new PhaseNode_PlayEffect(155, phase);
        node155->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node155->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node155->setEffectID(230533);
        node155->setChangeColor(false);
        node155->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node155->getVars().reserve(3);
        node155->getVars().setVariable<float>(0, .00f);
        node155->getVars().setVariable<float>(1, .00f);
        node155->getVars().setVariable<float>(2, .00f);
        node155->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(23053, 155, node155)
    }
    if (noInit == true) {
        return node155;
    }
    auto node153 = GET_SKILL_NODE(153, PhaseNode_GetLocation);
    auto node157 = GET_SKILL_NODE(157, PhaseNode_GetRotation);
    if (node153 != nullptr) node155->getVars().setVariable<float>(0, node153->getX());
    if (node153 != nullptr) node155->getVars().setVariable<float>(1, node153->getY());
    if (node157 != nullptr) node155->setRotation(node157->getAngle());
    return node155;
}
//--------------------------------------------------------------------------------
// GetRotation
//
REGISTER_REGISTER_SKILL_NODE(23053, 157) {
    pnode->resizeTrigger(PhaseNode_GetRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_GetRotation::TRIGGER_DONE, 155, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(23053, 157) {
    auto node157 = GET_SKILL_NODE(157, PhaseNode_GetRotation);
    if (node157 == nullptr) {
        node157 = new PhaseNode_GetRotation(157, phase);
        node157->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        CALL_REGISTER_SKILL_NODE(23053, 157, node157)
    }
    if (noInit == true) {
        return node157;
    }
    auto node65 = GET_SKILL_NODE(65, PhaseNode_SpawnCollider);
    if (node65 != nullptr) node157->setTarget(node65->getColliderID());
    return node157;
}
//--------------------------------------------------------------------------------
// MoveNewPene
//
REGISTER_REGISTER_SKILL_NODE(23053, 163) {
    pnode->resizeTrigger(PhaseNode_MoveNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnCollider>(PhaseNode_MoveNewPene::TRIGGER_DONE, 65, PhaseNode_SpawnCollider::FUNC_DO, &PhaseNode_SpawnCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(23053, 163) {
    auto node163 = GET_SKILL_NODE(163, PhaseNode_MoveNewPene);
    if (node163 == nullptr) {
        node163 = new PhaseNode_MoveNewPene(163, phase);
        node163->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node163->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node163->setPeneType(PhaseNode_MoveNewPene::MoveNewPene_PeneType::Move);
        node163->setPeneValue(0);
        node163->setType(PhaseNode_MoveNewPene::MoveNewPene_Type::Teleport);
        node163->getVars().reserve(2);
        node163->getVars().setVariable<float>(0, .00f);
        node163->getVars().setVariable<float>(1, .00f);
        node163->setreentry(false);
        node163->setStopWhenFail(true);
        node163->setCheckFaction(PhaseNode_MoveNewPene::MoveNewPene_CheckFaction::Enemy);
        CALL_REGISTER_SKILL_NODE(23053, 163, node163)
    }
    if (noInit == true) {
        return node163;
    }
    auto node59 = GET_SKILL_NODE(59, PhaseNode_SpawnCollider);
    auto node35 = GET_SKILL_NODE(35, PhaseNode_OffsetCalculate);
    if (node59 != nullptr) node163->setTarget(node59->getColliderID());
    if (node35 != nullptr) node163->getVars().setVariable<float>(0, node35->getOutPosX());
    if (node35 != nullptr) node163->getVars().setVariable<float>(1, node35->getOutPosY());
    return node163;
}
//--------------------------------------------------------------------------------
// MoveNewPene
//
REGISTER_REGISTER_SKILL_NODE(23053, 165) {
    pnode->resizeTrigger(PhaseNode_MoveNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_MoveNewPene::TRIGGER_DONE, 50, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(23053, 165) {
    auto node165 = GET_SKILL_NODE(165, PhaseNode_MoveNewPene);
    if (node165 == nullptr) {
        node165 = new PhaseNode_MoveNewPene(165, phase);
        node165->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node165->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node165->setPeneType(PhaseNode_MoveNewPene::MoveNewPene_PeneType::Move);
        node165->setPeneValue(30);
        node165->setType(PhaseNode_MoveNewPene::MoveNewPene_Type::Teleport);
        node165->getVars().reserve(2);
        node165->getVars().setVariable<float>(0, .00f);
        node165->getVars().setVariable<float>(1, .00f);
        node165->setreentry(false);
        node165->setStopWhenFail(true);
        node165->setCheckFaction(PhaseNode_MoveNewPene::MoveNewPene_CheckFaction::Enemy);
        CALL_REGISTER_SKILL_NODE(23053, 165, node165)
    }
    if (noInit == true) {
        return node165;
    }
    auto node65 = GET_SKILL_NODE(65, PhaseNode_SpawnCollider);
    auto node63 = GET_SKILL_NODE(63, PhaseNode_GetLocation);
    if (node65 != nullptr) node165->setTarget(node65->getColliderID());
    if (node63 != nullptr) node165->getVars().setVariable<float>(0, node63->getX());
    if (node63 != nullptr) node165->getVars().setVariable<float>(1, node63->getY());
    return node165;
}

//--------------------------------------------------------------------------------
// SkillCreator_23053
//
class SkillCreator_23053 : public SkillCreator {
public:
    SkillCreator_23053() {}
    virtual ~SkillCreator_23053() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_23053

//--------------------------------------------------------------------------------
// SkillPhase_23053
//
class SkillPhase_23053 : public SkillPhase {
public:
    SkillPhase_23053(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_23053() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(23053, 2) // StartPhase
        CASE_CREATE_SKILL_NODE(23053, 4) // TriggerUpdate
        CASE_CREATE_SKILL_NODE(23053, 6) // ResetCD
        CASE_CREATE_SKILL_NODE(23053, 8) // GetLocation
        CASE_CREATE_SKILL_NODE(23053, 10) // GetRotation
        CASE_CREATE_SKILL_NODE(23053, 12) // OffsetCalculate
        CASE_CREATE_SKILL_NODE(23053, 14) // PlayEffect
        CASE_CREATE_SKILL_NODE(23053, 16) // PlayAnimation
        CASE_CREATE_SKILL_NODE(23053, 18) // Delay
        CASE_CREATE_SKILL_NODE(23053, 20) // PlayEffect
        CASE_CREATE_SKILL_NODE(23053, 28) // Delay
        CASE_CREATE_SKILL_NODE(23053, 35) // OffsetCalculate
        CASE_CREATE_SKILL_NODE(23053, 45) // GetLineRotation
        CASE_CREATE_SKILL_NODE(23053, 50) // PlayAnimation
        CASE_CREATE_SKILL_NODE(23053, 52) // Delay
        CASE_CREATE_SKILL_NODE(23053, 54) // EndPhase
        CASE_CREATE_SKILL_NODE(23053, 59) // SpawnCollider
        CASE_CREATE_SKILL_NODE(23053, 63) // GetLocation
        CASE_CREATE_SKILL_NODE(23053, 65) // SpawnCollider
        CASE_CREATE_SKILL_NODE(23053, 67) // AttachTo
        CASE_CREATE_SKILL_NODE(23053, 83) // Delay
        CASE_CREATE_SKILL_NODE(23053, 97) // GetBBParamUInt64
        CASE_CREATE_SKILL_NODE(23053, 99) // GetLocation
        CASE_CREATE_SKILL_NODE(23053, 153) // GetLocation
        CASE_CREATE_SKILL_NODE(23053, 155) // PlayEffect
        CASE_CREATE_SKILL_NODE(23053, 157) // GetRotation
        CASE_CREATE_SKILL_NODE(23053, 163) // MoveNewPene
        CASE_CREATE_SKILL_NODE(23053, 165) // MoveNewPene
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_23053

SkillLogic* SkillCreator_23053::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //创建阶段phase
    auto phase = new SkillPhase_23053(1, logic, 2);
    //设置phase执行器
    phase->setRunPhaseNode(1, 2);
    phase->setRunPhaseNode(2, 4);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_23053::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
