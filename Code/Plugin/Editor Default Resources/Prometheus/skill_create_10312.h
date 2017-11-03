#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

#include "skill_psnode_addskillbuff.h"
#include "skill_psnode_addskillbuffs.h"
#include "skill_psnode_areacollisionnewpene.h"
#include "skill_psnode_attachto.h"
#include "skill_psnode_compareint.h"
#include "skill_psnode_delay.h"
#include "skill_psnode_detect.h"
#include "skill_psnode_distance.h"
#include "skill_psnode_endphase.h"
#include "skill_psnode_findskillbuff.h"
#include "skill_psnode_floatoperation.h"
#include "skill_psnode_for.h"
#include "skill_psnode_forcontinue.h"
#include "skill_psnode_getactorattribute.h"
#include "skill_psnode_getinputrotation.h"
#include "skill_psnode_getlinerotation.h"
#include "skill_psnode_getlocation.h"
#include "skill_psnode_getuint64svalue.h"
#include "skill_psnode_if.h"
#include "skill_psnode_int2float.h"
#include "skill_psnode_movenewpene.h"
#include "skill_psnode_playanimation.h"
#include "skill_psnode_playeffect.h"
#include "skill_psnode_playsound.h"
#include "skill_psnode_raiseevent.h"
#include "skill_psnode_removeskillbuff.h"
#include "skill_psnode_resetcd.h"
#include "skill_psnode_revisemapi32.h"
#include "skill_psnode_spawncollider.h"
#include "skill_psnode_startphase.h"
#include "skill_psnode_stopeffect.h"
#include "skill_psnode_triggerupdate.h"
#include "skill_psnode_uint64ssize.h"

namespace pvp {

//变量声明
//--------------------------------------------------------------------------------
// StartPhase
//
REGISTER_REGISTER_SKILL_NODE(10312, 3) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_StartPhase::TRIGGER_START, 137, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(10312, 3) {
    auto node3 = GET_SKILL_NODE(3, PhaseNode_StartPhase);
    if (node3 == nullptr) {
        node3 = new PhaseNode_StartPhase(3, phase);
        CALL_REGISTER_SKILL_NODE(10312, 3, node3)
    }
    if (noInit == true) {
        return node3;
    }
    return node3;
}
//--------------------------------------------------------------------------------
// TriggerUpdate
//
REGISTER_REGISTER_SKILL_NODE(10312, 5) {
}

REGISTER_CREATE_SKILL_NODE(10312, 5) {
    auto node5 = GET_SKILL_NODE(5, PhaseNode_TriggerUpdate);
    if (node5 == nullptr) {
        node5 = new PhaseNode_TriggerUpdate(5, phase);
        CALL_REGISTER_SKILL_NODE(10312, 5, node5)
    }
    if (noInit == true) {
        return node5;
    }
    return node5;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10312, 9) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_Delay::TRIGGER_DONE, 90, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10312, 9) {
    auto node9 = GET_SKILL_NODE(9, PhaseNode_Delay);
    if (node9 == nullptr) {
        node9 = new PhaseNode_Delay(9, phase);
        node9->setTime(2.00f);
        CALL_REGISTER_SKILL_NODE(10312, 9, node9)
    }
    if (noInit == true) {
        return node9;
    }
    return node9;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(10312, 14) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlayEffect::TRIGGER_DONE, 9, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10312, 14) {
    auto node14 = GET_SKILL_NODE(14, PhaseNode_PlayEffect);
    if (node14 == nullptr) {
        node14 = new PhaseNode_PlayEffect(14, phase);
        node14->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node14->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node14->setEffectID(103121);
        node14->setChangeColor(false);
        node14->setType(PhaseNode_PlayEffect::PlayEffect_Type::WithTarget);
        node14->getVars().reserve(6);
        node14->getVars().setVariable<uint64_t>(0, 0U);
        node14->getVars().setVariable<std::string>(1, "");
        node14->getVars().setVariable<float>(2, .00f);
        node14->getVars().setVariable<float>(3, .00f);
        node14->getVars().setVariable<float>(4, .00f);
        node14->getVars().setVariable<bool>(5, true);
        node14->setRotation(.00f);
        node14->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(10312, 14, node14)
    }
    if (noInit == true) {
        return node14;
    }
    return node14;
}
//--------------------------------------------------------------------------------
// GetUInt64sValue
//
REGISTER_REGISTER_SKILL_NODE(10312, 22) {
    pnode->resizeTrigger(PhaseNode_GetUInt64sValue::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_GetUInt64sValue::TRIGGER_DONE, 33, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(10312, 22) {
    auto node22 = GET_SKILL_NODE(22, PhaseNode_GetUInt64sValue);
    if (node22 == nullptr) {
        node22 = new PhaseNode_GetUInt64sValue(22, phase);
        CALL_REGISTER_SKILL_NODE(10312, 22, node22)
    }
    if (noInit == true) {
        return node22;
    }
    auto node76 = GET_SKILL_NODE(76, PhaseNode_AreaCollisionNewPene);
    auto node29 = GET_SKILL_NODE(29, PhaseNode_For);
    if (node76 != nullptr) node22->setArr(node76->getColliders());
    if (node29 != nullptr) node22->setIndex(node29->getValue());
    return node22;
}
//--------------------------------------------------------------------------------
// UInt64sSize
//
REGISTER_REGISTER_SKILL_NODE(10312, 24) {
    pnode->resizeTrigger(PhaseNode_UInt64sSize::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareInt>(PhaseNode_UInt64sSize::TRIGGER_DONE, 100, PhaseNode_CompareInt::FUNC_COMPARE, &PhaseNode_CompareInt::Compare);
    pnode->regTrigger<PhaseNode_Int2Float>(PhaseNode_UInt64sSize::TRIGGER_DONE, 134, PhaseNode_Int2Float::FUNC_DO, &PhaseNode_Int2Float::Do);
}

REGISTER_CREATE_SKILL_NODE(10312, 24) {
    auto node24 = GET_SKILL_NODE(24, PhaseNode_UInt64sSize);
    if (node24 == nullptr) {
        node24 = new PhaseNode_UInt64sSize(24, phase);
        CALL_REGISTER_SKILL_NODE(10312, 24, node24)
    }
    if (noInit == true) {
        return node24;
    }
    auto node76 = GET_SKILL_NODE(76, PhaseNode_AreaCollisionNewPene);
    if (node76 != nullptr) node24->setArr(node76->getColliders());
    return node24;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(10312, 27) {
    pnode->resizeTrigger(PhaseNode_AddSkillBuffs::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_UInt64sSize>(PhaseNode_AddSkillBuffs::TRIGGER_DONE, 24, PhaseNode_UInt64sSize::FUNC_DO, &PhaseNode_UInt64sSize::Do);
}

REGISTER_CREATE_SKILL_NODE(10312, 27) {
    auto node27 = GET_SKILL_NODE(27, PhaseNode_AddSkillBuffs);
    if (node27 == nullptr) {
        node27 = new PhaseNode_AddSkillBuffs(27, phase);
        node27->setConfigID({103121,103141});
        CALL_REGISTER_SKILL_NODE(10312, 27, node27)
    }
    if (noInit == true) {
        return node27;
    }
    auto node76 = GET_SKILL_NODE(76, PhaseNode_AreaCollisionNewPene);
    auto node140 = GET_SKILL_NODE(140, PhaseNode_GetActorAttribute);
    if (node76 != nullptr) node27->setTarget(node76->getColliders());
    if (node140 != nullptr) node27->setAttribute(node140->getAttribute());
    return node27;
}
//--------------------------------------------------------------------------------
// For
//
REGISTER_REGISTER_SKILL_NODE(10312, 29) {
    pnode->resizeTrigger(PhaseNode_For::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetUInt64sValue>(PhaseNode_For::TRIGGER_DO, 22, PhaseNode_GetUInt64sValue::FUNC_DO, &PhaseNode_GetUInt64sValue::Do);
}

REGISTER_CREATE_SKILL_NODE(10312, 29) {
    auto node29 = GET_SKILL_NODE(29, PhaseNode_For);
    if (node29 == nullptr) {
        node29 = new PhaseNode_For(29, phase);
        node29->setBegin(0);
        node29->setIncrease(1);
        CALL_REGISTER_SKILL_NODE(10312, 29, node29)
    }
    if (noInit == true) {
        return node29;
    }
    auto node24 = GET_SKILL_NODE(24, PhaseNode_UInt64sSize);
    if (node24 != nullptr) node29->setEnd(node24->getSize());
    return node29;
}
//--------------------------------------------------------------------------------
// ForContinue
//
REGISTER_REGISTER_SKILL_NODE(10312, 31) {
}

REGISTER_CREATE_SKILL_NODE(10312, 31) {
    auto node31 = GET_SKILL_NODE(31, PhaseNode_ForContinue);
    if (node31 == nullptr) {
        node31 = new PhaseNode_ForContinue(31, phase);
        CALL_REGISTER_SKILL_NODE(10312, 31, node31)
    }
    if (noInit == true) {
        return node31;
    }
    auto node29 = GET_SKILL_NODE(29, PhaseNode_For);
    if (node29 != nullptr) node31->setFID(node29->getFID());
    return node31;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(10312, 33) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuff>(PhaseNode_GetLocation::TRIGGER_DONE, 49, PhaseNode_AddSkillBuff::FUNC_ADD, &PhaseNode_AddSkillBuff::Add);
}

REGISTER_CREATE_SKILL_NODE(10312, 33) {
    auto node33 = GET_SKILL_NODE(33, PhaseNode_GetLocation);
    if (node33 == nullptr) {
        node33 = new PhaseNode_GetLocation(33, phase);
        node33->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        CALL_REGISTER_SKILL_NODE(10312, 33, node33)
    }
    if (noInit == true) {
        return node33;
    }
    auto node22 = GET_SKILL_NODE(22, PhaseNode_GetUInt64sValue);
    if (node22 != nullptr) node33->setTarget(node22->getValue());
    return node33;
}
//--------------------------------------------------------------------------------
// SpawnCollider
//
REGISTER_REGISTER_SKILL_NODE(10312, 35) {
    pnode->resizeTrigger(PhaseNode_SpawnCollider::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AttachTo>(PhaseNode_SpawnCollider::TRIGGER_DONE, 37, PhaseNode_AttachTo::FUNC_DO, &PhaseNode_AttachTo::Do);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_SpawnCollider::TRIGGER_DONE, 82, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(10312, 35) {
    auto node35 = GET_SKILL_NODE(35, PhaseNode_SpawnCollider);
    if (node35 == nullptr) {
        node35 = new PhaseNode_SpawnCollider(35, phase);
        node35->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node35->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node35->setMesh("");
        node35->setMeshScale(.00f);
        node35->setEffectID(0);
        node35->setEffectScale(.00f);
        node35->setType(PhaseNode_SpawnCollider::SpawnCollider_Type::Circle);
        node35->setTypeParams(0, 1.00f);
        node35->setTime(1.00f);
        node35->setPosZ(.00f);
        node35->setRotation(.00f);
        node35->setreentry(true);
        node35->setCheckPeneSound(false);
        CALL_REGISTER_SKILL_NODE(10312, 35, node35)
    }
    if (noInit == true) {
        return node35;
    }
    auto node33 = GET_SKILL_NODE(33, PhaseNode_GetLocation);
    if (node33 != nullptr) node35->setPosX(node33->getX());
    if (node33 != nullptr) node35->setPosY(node33->getY());
    return node35;
}
//--------------------------------------------------------------------------------
// AttachTo
//
REGISTER_REGISTER_SKILL_NODE(10312, 37) {
    pnode->resizeTrigger(PhaseNode_AttachTo::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_AttachTo::TRIGGER_DONE, 41, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(10312, 37) {
    auto node37 = GET_SKILL_NODE(37, PhaseNode_AttachTo);
    if (node37 == nullptr) {
        node37 = new PhaseNode_AttachTo(37, phase);
        node37->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node37->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node37->setChangeRotation(false);
        node37->setreentry(true);
        CALL_REGISTER_SKILL_NODE(10312, 37, node37)
    }
    if (noInit == true) {
        return node37;
    }
    auto node35 = GET_SKILL_NODE(35, PhaseNode_SpawnCollider);
    auto node22 = GET_SKILL_NODE(22, PhaseNode_GetUInt64sValue);
    if (node35 != nullptr) node37->setParent(node35->getColliderID());
    if (node22 != nullptr) node37->setChild(node22->getValue());
    return node37;
}
//--------------------------------------------------------------------------------
// GetLineRotation
//
REGISTER_REGISTER_SKILL_NODE(10312, 39) {
    pnode->resizeTrigger(PhaseNode_GetLineRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Distance>(PhaseNode_GetLineRotation::TRIGGER_DONE, 43, PhaseNode_Distance::FUNC_DO, &PhaseNode_Distance::Do);
}

REGISTER_CREATE_SKILL_NODE(10312, 39) {
    auto node39 = GET_SKILL_NODE(39, PhaseNode_GetLineRotation);
    if (node39 == nullptr) {
        node39 = new PhaseNode_GetLineRotation(39, phase);
        CALL_REGISTER_SKILL_NODE(10312, 39, node39)
    }
    if (noInit == true) {
        return node39;
    }
    auto node33 = GET_SKILL_NODE(33, PhaseNode_GetLocation);
    auto node41 = GET_SKILL_NODE(41, PhaseNode_GetLocation);
    if (node33 != nullptr) node39->setStartX(node33->getX());
    if (node33 != nullptr) node39->setStartY(node33->getY());
    if (node41 != nullptr) node39->setEndX(node41->getX());
    if (node41 != nullptr) node39->setEndY(node41->getY());
    return node39;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(10312, 41) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLineRotation>(PhaseNode_GetLocation::TRIGGER_DONE, 39, PhaseNode_GetLineRotation::FUNC_DO, &PhaseNode_GetLineRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(10312, 41) {
    auto node41 = GET_SKILL_NODE(41, PhaseNode_GetLocation);
    if (node41 == nullptr) {
        node41 = new PhaseNode_GetLocation(41, phase);
        node41->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node41->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(10312, 41, node41)
    }
    if (noInit == true) {
        return node41;
    }
    return node41;
}
//--------------------------------------------------------------------------------
// Distance
//
REGISTER_REGISTER_SKILL_NODE(10312, 43) {
    pnode->resizeTrigger(PhaseNode_Distance::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_FloatOperation>(PhaseNode_Distance::TRIGGER_DONE, 45, PhaseNode_FloatOperation::FUNC_OPERATION, &PhaseNode_FloatOperation::Operation);
}

REGISTER_CREATE_SKILL_NODE(10312, 43) {
    auto node43 = GET_SKILL_NODE(43, PhaseNode_Distance);
    if (node43 == nullptr) {
        node43 = new PhaseNode_Distance(43, phase);
        CALL_REGISTER_SKILL_NODE(10312, 43, node43)
    }
    if (noInit == true) {
        return node43;
    }
    auto node33 = GET_SKILL_NODE(33, PhaseNode_GetLocation);
    auto node41 = GET_SKILL_NODE(41, PhaseNode_GetLocation);
    if (node33 != nullptr) node43->setAX(node33->getX());
    if (node33 != nullptr) node43->setAY(node33->getY());
    if (node41 != nullptr) node43->setBX(node41->getX());
    if (node41 != nullptr) node43->setBY(node41->getY());
    return node43;
}
//--------------------------------------------------------------------------------
// FloatOperation
//
REGISTER_REGISTER_SKILL_NODE(10312, 45) {
    pnode->resizeTrigger(PhaseNode_FloatOperation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_MoveNewPene>(PhaseNode_FloatOperation::TRIGGER_DONE, 47, PhaseNode_MoveNewPene::FUNC_DO, &PhaseNode_MoveNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(10312, 45) {
    auto node45 = GET_SKILL_NODE(45, PhaseNode_FloatOperation);
    if (node45 == nullptr) {
        node45 = new PhaseNode_FloatOperation(45, phase);
        node45->setValue(1.00f);
        node45->setMethod(PhaseNode_FloatOperation::FloatOperation_Method::Sub);
        CALL_REGISTER_SKILL_NODE(10312, 45, node45)
    }
    if (noInit == true) {
        return node45;
    }
    auto node43 = GET_SKILL_NODE(43, PhaseNode_Distance);
    if (node43 != nullptr) node45->setBase(node43->getResult());
    return node45;
}
//--------------------------------------------------------------------------------
// MoveNewPene
//
REGISTER_REGISTER_SKILL_NODE(10312, 47) {
    pnode->resizeTrigger(PhaseNode_MoveNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ForContinue>(PhaseNode_MoveNewPene::TRIGGER_STARTMOVE, 31, PhaseNode_ForContinue::FUNC_DO, &PhaseNode_ForContinue::Do);
}

REGISTER_CREATE_SKILL_NODE(10312, 47) {
    auto node47 = GET_SKILL_NODE(47, PhaseNode_MoveNewPene);
    if (node47 == nullptr) {
        node47 = new PhaseNode_MoveNewPene(47, phase);
        node47->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node47->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node47->setPeneType(PhaseNode_MoveNewPene::MoveNewPene_PeneType::Move);
        node47->setPeneValue(15);
        node47->setType(PhaseNode_MoveNewPene::MoveNewPene_Type::Charge);
        node47->getVars().reserve(4);
        node47->getVars().setVariable<float>(0, 40.00f);
        node47->getVars().setVariable<float>(1, .00f);
        node47->getVars().setVariable<float>(2, .00f);
        node47->getVars().setVariable<float>(3, .00f);
        node47->setreentry(true);
        node47->setStopWhenFail(true);
        node47->setCheckFaction(PhaseNode_MoveNewPene::MoveNewPene_CheckFaction::Enemy);
        CALL_REGISTER_SKILL_NODE(10312, 47, node47)
    }
    if (noInit == true) {
        return node47;
    }
    auto node35 = GET_SKILL_NODE(35, PhaseNode_SpawnCollider);
    auto node45 = GET_SKILL_NODE(45, PhaseNode_FloatOperation);
    auto node39 = GET_SKILL_NODE(39, PhaseNode_GetLineRotation);
    if (node35 != nullptr) node47->setTarget(node35->getColliderID());
    if (node45 != nullptr) node47->getVars().setVariable<float>(1, node45->getFinal());
    if (node39 != nullptr) node47->getVars().setVariable<float>(2, node39->getRotation());
    return node47;
}
//--------------------------------------------------------------------------------
// AddSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10312, 49) {
    pnode->resizeTrigger(PhaseNode_AddSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnCollider>(PhaseNode_AddSkillBuff::TRIGGER_DONE, 35, PhaseNode_SpawnCollider::FUNC_DO, &PhaseNode_SpawnCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(10312, 49) {
    auto node49 = GET_SKILL_NODE(49, PhaseNode_AddSkillBuff);
    if (node49 == nullptr) {
        node49 = new PhaseNode_AddSkillBuff(49, phase);
        node49->setConfigID(103122);
        node49->setConfigIDs({});
        node49->setAttribute({{}});
        CALL_REGISTER_SKILL_NODE(10312, 49, node49)
    }
    if (noInit == true) {
        return node49;
    }
    auto node22 = GET_SKILL_NODE(22, PhaseNode_GetUInt64sValue);
    if (node22 != nullptr) node49->setTarget(node22->getValue());
    return node49;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(10312, 70) {
}

REGISTER_CREATE_SKILL_NODE(10312, 70) {
    auto node70 = GET_SKILL_NODE(70, PhaseNode_EndPhase);
    if (node70 == nullptr) {
        node70 = new PhaseNode_EndPhase(70, phase);
        node70->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node70->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10312, 70, node70)
    }
    if (noInit == true) {
        return node70;
    }
    return node70;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10312, 74) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_Delay::TRIGGER_DONE, 70, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(10312, 74) {
    auto node74 = GET_SKILL_NODE(74, PhaseNode_Delay);
    if (node74 == nullptr) {
        node74 = new PhaseNode_Delay(74, phase);
        node74->setTime(.20f);
        CALL_REGISTER_SKILL_NODE(10312, 74, node74)
    }
    if (noInit == true) {
        return node74;
    }
    return node74;
}
//--------------------------------------------------------------------------------
// AreaCollisionNewPene
//
REGISTER_REGISTER_SKILL_NODE(10312, 76) {
    pnode->resizeTrigger(PhaseNode_AreaCollisionNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_AreaCollisionNewPene::TRIGGER_DONE, 27, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_AreaCollisionNewPene::TRIGGER_DONE, 74, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10312, 76) {
    auto node76 = GET_SKILL_NODE(76, PhaseNode_AreaCollisionNewPene);
    if (node76 == nullptr) {
        node76 = new PhaseNode_AreaCollisionNewPene(76, phase);
        node76->setState(PhaseNode_AreaCollisionNewPene::AreaCollisionNewPene_State::Alive);
        node76->setFaction(PhaseNode_AreaCollisionNewPene::AreaCollisionNewPene_Faction::Enemy);
        node76->setOnHero(true);
        node76->setOnMinion(true);
        node76->setOnDestruct(false);
        node76->setOnShield(false);
        node76->setType(PhaseNode_AreaCollisionNewPene::AreaCollisionNewPene_Type::Circle);
        node76->setTypeParams(0, 5.00f);
        node76->setPositionZ(.00f);
        CALL_REGISTER_SKILL_NODE(10312, 76, node76)
    }
    if (noInit == true) {
        return node76;
    }
    auto node86 = GET_SKILL_NODE(86, PhaseNode_GetLocation);
    auto node108 = GET_SKILL_NODE(108, PhaseNode_GetInputRotation);
    if (node86 != nullptr) node76->setPositionX(node86->getX());
    if (node86 != nullptr) node76->setPositionY(node86->getY());
    if (node108 != nullptr) node76->setRotation(node108->getAngle());
    return node76;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10312, 78) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_Delay::TRIGGER_DONE, 80, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10312, 78) {
    auto node78 = GET_SKILL_NODE(78, PhaseNode_Delay);
    if (node78 == nullptr) {
        node78 = new PhaseNode_Delay(78, phase);
        node78->setTime(1.00f);
        CALL_REGISTER_SKILL_NODE(10312, 78, node78)
    }
    if (noInit == true) {
        return node78;
    }
    return node78;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10312, 80) {
}

REGISTER_CREATE_SKILL_NODE(10312, 80) {
    auto node80 = GET_SKILL_NODE(80, PhaseNode_PlayAnimation);
    if (node80 == nullptr) {
        node80 = new PhaseNode_PlayAnimation(80, phase);
        node80->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node80->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node80->setTarget(0U);
        node80->setAnimation("Idle");
        node80->setParameter("");
        node80->setValue(false);
        CALL_REGISTER_SKILL_NODE(10312, 80, node80)
    }
    if (noInit == true) {
        return node80;
    }
    return node80;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(10312, 82) {
}

REGISTER_CREATE_SKILL_NODE(10312, 82) {
    auto node82 = GET_SKILL_NODE(82, PhaseNode_PlayEffect);
    if (node82 == nullptr) {
        node82 = new PhaseNode_PlayEffect(82, phase);
        node82->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node82->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node82->setEffectID(103122);
        node82->setChangeColor(true);
        node82->setType(PhaseNode_PlayEffect::PlayEffect_Type::WithTarget);
        node82->getVars().reserve(5);
        node82->getVars().setVariable<uint64_t>(0, 0U);
        node82->getVars().setVariable<std::string>(1, "");
        node82->getVars().setVariable<float>(2, .00f);
        node82->getVars().setVariable<float>(3, .00f);
        node82->getVars().setVariable<float>(4, .00f);
        node82->setRotation(.00f);
        node82->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(10312, 82, node82)
    }
    if (noInit == true) {
        return node82;
    }
    auto node22 = GET_SKILL_NODE(22, PhaseNode_GetUInt64sValue);
    if (node22 != nullptr) node82->getVars().setVariable<uint64_t>(0, node22->getValue());
    return node82;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(10312, 84) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_PlayEffect::TRIGGER_DONE, 14, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(10312, 84) {
    auto node84 = GET_SKILL_NODE(84, PhaseNode_PlayEffect);
    if (node84 == nullptr) {
        node84 = new PhaseNode_PlayEffect(84, phase);
        node84->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node84->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node84->setEffectID(103123);
        node84->setChangeColor(false);
        node84->setType(PhaseNode_PlayEffect::PlayEffect_Type::WithTarget);
        node84->getVars().reserve(6);
        node84->getVars().setVariable<uint64_t>(0, 0U);
        node84->getVars().setVariable<std::string>(1, "");
        node84->getVars().setVariable<float>(2, .00f);
        node84->getVars().setVariable<float>(3, .00f);
        node84->getVars().setVariable<float>(4, .00f);
        node84->getVars().setVariable<bool>(5, false);
        node84->setRotation(.00f);
        node84->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(10312, 84, node84)
    }
    if (noInit == true) {
        return node84;
    }
    return node84;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(10312, 86) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AreaCollisionNewPene>(PhaseNode_GetLocation::TRIGGER_DONE, 102, PhaseNode_AreaCollisionNewPene::FUNC_DO, &PhaseNode_AreaCollisionNewPene::Do);
    pnode->regTrigger<PhaseNode_AreaCollisionNewPene>(PhaseNode_GetLocation::TRIGGER_DONE, 76, PhaseNode_AreaCollisionNewPene::FUNC_DO, &PhaseNode_AreaCollisionNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(10312, 86) {
    auto node86 = GET_SKILL_NODE(86, PhaseNode_GetLocation);
    if (node86 == nullptr) {
        node86 = new PhaseNode_GetLocation(86, phase);
        node86->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node86->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(10312, 86, node86)
    }
    if (noInit == true) {
        return node86;
    }
    return node86;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10312, 90) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_PlaySound::TRIGGER_DONE, 86, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(10312, 90) {
    auto node90 = GET_SKILL_NODE(90, PhaseNode_PlaySound);
    if (node90 == nullptr) {
        node90 = new PhaseNode_PlaySound(90, phase);
        node90->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node90->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node90->setSoundID("SE_Hero123_SkillB_P2");
        node90->setTarget(0U);
        node90->setUsePos(false);
        node90->setPosX(.00f);
        node90->setPosY(.00f);
        node90->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10312, 90, node90)
    }
    if (noInit == true) {
        return node90;
    }
    return node90;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10312, 94) {
}

REGISTER_CREATE_SKILL_NODE(10312, 94) {
    auto node94 = GET_SKILL_NODE(94, PhaseNode_RaiseEvent);
    if (node94 == nullptr) {
        node94 = new PhaseNode_RaiseEvent(94, phase);
        node94->setEvent("Dead");
        node94->setTarget(0U);
        node94->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node94->setTypeParams(0, 0);
        node94->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10312, 94, node94)
    }
    if (noInit == true) {
        return node94;
    }
    return node94;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10312, 96) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StopEffect>(PhaseNode_Detect::TRIGGER_ON, 98, PhaseNode_StopEffect::FUNC_DO, &PhaseNode_StopEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(10312, 96) {
    auto node96 = GET_SKILL_NODE(96, PhaseNode_Detect);
    if (node96 == nullptr) {
        node96 = new PhaseNode_Detect(96, phase);
        node96->setSelf(0U);
        node96->setEvent("");
        node96->setType(PhaseNode_Detect::Detect_Type::Actor_Dead);
        node96->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10312, 96, node96)
    }
    if (noInit == true) {
        return node96;
    }
    return node96;
}
//--------------------------------------------------------------------------------
// StopEffect
//
REGISTER_REGISTER_SKILL_NODE(10312, 98) {
    pnode->resizeTrigger(PhaseNode_StopEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_StopEffect::TRIGGER_DONE, 70, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(10312, 98) {
    auto node98 = GET_SKILL_NODE(98, PhaseNode_StopEffect);
    if (node98 == nullptr) {
        node98 = new PhaseNode_StopEffect(98, phase);
        node98->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node98->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node98->setEffectID(103123);
        CALL_REGISTER_SKILL_NODE(10312, 98, node98)
    }
    if (noInit == true) {
        return node98;
    }
    return node98;
}
//--------------------------------------------------------------------------------
// CompareInt
//
REGISTER_REGISTER_SKILL_NODE(10312, 100) {
    pnode->resizeTrigger(PhaseNode_CompareInt::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_For>(PhaseNode_CompareInt::TRIGGER_GREATER, 29, PhaseNode_For::FUNC_START, &PhaseNode_For::Start);
}

REGISTER_CREATE_SKILL_NODE(10312, 100) {
    auto node100 = GET_SKILL_NODE(100, PhaseNode_CompareInt);
    if (node100 == nullptr) {
        node100 = new PhaseNode_CompareInt(100, phase);
        node100->setB(0);
        CALL_REGISTER_SKILL_NODE(10312, 100, node100)
    }
    if (noInit == true) {
        return node100;
    }
    auto node24 = GET_SKILL_NODE(24, PhaseNode_UInt64sSize);
    if (node24 != nullptr) node100->setA(node24->getSize());
    return node100;
}
//--------------------------------------------------------------------------------
// AreaCollisionNewPene
//
REGISTER_REGISTER_SKILL_NODE(10312, 102) {
    pnode->resizeTrigger(PhaseNode_AreaCollisionNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_AreaCollisionNewPene::TRIGGER_DONE, 106, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
}

REGISTER_CREATE_SKILL_NODE(10312, 102) {
    auto node102 = GET_SKILL_NODE(102, PhaseNode_AreaCollisionNewPene);
    if (node102 == nullptr) {
        node102 = new PhaseNode_AreaCollisionNewPene(102, phase);
        node102->setState(PhaseNode_AreaCollisionNewPene::AreaCollisionNewPene_State::Alive);
        node102->setFaction(PhaseNode_AreaCollisionNewPene::AreaCollisionNewPene_Faction::Enemy);
        node102->setOnHero(false);
        node102->setOnMinion(false);
        node102->setOnDestruct(true);
        node102->setOnShield(false);
        node102->setType(PhaseNode_AreaCollisionNewPene::AreaCollisionNewPene_Type::Circle);
        node102->setTypeParams(0, 5.00f);
        node102->setPositionZ(.00f);
        node102->setRotation(.00f);
        CALL_REGISTER_SKILL_NODE(10312, 102, node102)
    }
    if (noInit == true) {
        return node102;
    }
    auto node86 = GET_SKILL_NODE(86, PhaseNode_GetLocation);
    if (node86 != nullptr) node102->setPositionX(node86->getX());
    if (node86 != nullptr) node102->setPositionY(node86->getY());
    return node102;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(10312, 106) {
}

REGISTER_CREATE_SKILL_NODE(10312, 106) {
    auto node106 = GET_SKILL_NODE(106, PhaseNode_AddSkillBuffs);
    if (node106 == nullptr) {
        node106 = new PhaseNode_AddSkillBuffs(106, phase);
        node106->setConfigID({103121});
        CALL_REGISTER_SKILL_NODE(10312, 106, node106)
    }
    if (noInit == true) {
        return node106;
    }
    auto node102 = GET_SKILL_NODE(102, PhaseNode_AreaCollisionNewPene);
    auto node140 = GET_SKILL_NODE(140, PhaseNode_GetActorAttribute);
    if (node102 != nullptr) node106->setTarget(node102->getColliders());
    if (node140 != nullptr) node106->setAttribute(node140->getAttribute());
    return node106;
}
//--------------------------------------------------------------------------------
// GetInputRotation
//
REGISTER_REGISTER_SKILL_NODE(10312, 108) {
    pnode->resizeTrigger(PhaseNode_GetInputRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_GetInputRotation::TRIGGER_DONE, 84, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(10312, 108) {
    auto node108 = GET_SKILL_NODE(108, PhaseNode_GetInputRotation);
    if (node108 == nullptr) {
        node108 = new PhaseNode_GetInputRotation(108, phase);
        node108->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        CALL_REGISTER_SKILL_NODE(10312, 108, node108)
    }
    if (noInit == true) {
        return node108;
    }
    return node108;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10312, 110) {
}

REGISTER_CREATE_SKILL_NODE(10312, 110) {
    auto node110 = GET_SKILL_NODE(110, PhaseNode_PlaySound);
    if (node110 == nullptr) {
        node110 = new PhaseNode_PlaySound(110, phase);
        node110->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node110->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node110->setSoundID("VO_Hero131_Skill_B");
        node110->setTarget(0U);
        node110->setUsePos(false);
        node110->setPosX(.00f);
        node110->setPosY(.00f);
        node110->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10312, 110, node110)
    }
    if (noInit == true) {
        return node110;
    }
    return node110;
}
//--------------------------------------------------------------------------------
// ReviseMapI32
//
REGISTER_REGISTER_SKILL_NODE(10312, 125) {
    pnode->resizeTrigger(PhaseNode_ReviseMapI32::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuff>(PhaseNode_ReviseMapI32::TRIGGER_DONE, 136, PhaseNode_AddSkillBuff::FUNC_ADD, &PhaseNode_AddSkillBuff::Add);
}

REGISTER_CREATE_SKILL_NODE(10312, 125) {
    auto node125 = GET_SKILL_NODE(125, PhaseNode_ReviseMapI32);
    if (node125 == nullptr) {
        node125 = new PhaseNode_ReviseMapI32(125, phase);
        node125->reviseValue(201, .00f);
        CALL_REGISTER_SKILL_NODE(10312, 125, node125)
    }
    if (noInit == true) {
        return node125;
    }
    auto node140 = GET_SKILL_NODE(140, PhaseNode_GetActorAttribute);
    auto node134 = GET_SKILL_NODE(134, PhaseNode_Int2Float);
    if (node140 != nullptr) node125->setInAttri(node140->getAttribute());
    if (node134 != nullptr) node125->reviseValue(201, node134->getFloat());
    return node125;
}
//--------------------------------------------------------------------------------
// Int2Float
//
REGISTER_REGISTER_SKILL_NODE(10312, 134) {
    pnode->resizeTrigger(PhaseNode_Int2Float::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ReviseMapI32>(PhaseNode_Int2Float::TRIGGER_DONE, 125, PhaseNode_ReviseMapI32::FUNC_DO, &PhaseNode_ReviseMapI32::Do);
}

REGISTER_CREATE_SKILL_NODE(10312, 134) {
    auto node134 = GET_SKILL_NODE(134, PhaseNode_Int2Float);
    if (node134 == nullptr) {
        node134 = new PhaseNode_Int2Float(134, phase);
        CALL_REGISTER_SKILL_NODE(10312, 134, node134)
    }
    if (noInit == true) {
        return node134;
    }
    auto node24 = GET_SKILL_NODE(24, PhaseNode_UInt64sSize);
    if (node24 != nullptr) node134->setInt(node24->getSize());
    return node134;
}
//--------------------------------------------------------------------------------
// AddSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10312, 136) {
}

REGISTER_CREATE_SKILL_NODE(10312, 136) {
    auto node136 = GET_SKILL_NODE(136, PhaseNode_AddSkillBuff);
    if (node136 == nullptr) {
        node136 = new PhaseNode_AddSkillBuff(136, phase);
        node136->setConfigID(0);
        node136->setConfigIDs({103123});
        node136->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(10312, 136, node136)
    }
    if (noInit == true) {
        return node136;
    }
    auto node125 = GET_SKILL_NODE(125, PhaseNode_ReviseMapI32);
    if (node125 != nullptr) node136->setAttribute(node125->getOutAttri());
    return node136;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(10312, 137) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_ResetCD::TRIGGER_DONE, 138, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10312, 137) {
    auto node137 = GET_SKILL_NODE(137, PhaseNode_ResetCD);
    if (node137 == nullptr) {
        node137 = new PhaseNode_ResetCD(137, phase);
        node137->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node137->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node137->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(10312, 137, node137)
    }
    if (noInit == true) {
        return node137;
    }
    return node137;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10312, 138) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_PlayAnimation::TRIGGER_DONE, 140, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(10312, 138) {
    auto node138 = GET_SKILL_NODE(138, PhaseNode_PlayAnimation);
    if (node138 == nullptr) {
        node138 = new PhaseNode_PlayAnimation(138, phase);
        node138->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node138->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node138->setTarget(0U);
        node138->setAnimation("");
        node138->setParameter("");
        node138->setValue(false);
        CALL_REGISTER_SKILL_NODE(10312, 138, node138)
    }
    if (noInit == true) {
        return node138;
    }
    return node138;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10312, 139) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlaySound::TRIGGER_DONE, 78, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_GetInputRotation>(PhaseNode_PlaySound::TRIGGER_DONE, 108, PhaseNode_GetInputRotation::FUNC_DO, &PhaseNode_GetInputRotation::Do);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_PlaySound::TRIGGER_DONE, 110, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_PlaySound::TRIGGER_DONE, 94, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10312, 139) {
    auto node139 = GET_SKILL_NODE(139, PhaseNode_PlaySound);
    if (node139 == nullptr) {
        node139 = new PhaseNode_PlaySound(139, phase);
        node139->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node139->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node139->setSoundID("SE_Hero123_SkillB_P1");
        node139->setTarget(0U);
        node139->setUsePos(false);
        node139->setPosX(.00f);
        node139->setPosY(.00f);
        node139->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10312, 139, node139)
    }
    if (noInit == true) {
        return node139;
    }
    return node139;
}
//--------------------------------------------------------------------------------
// GetActorAttribute
//
REGISTER_REGISTER_SKILL_NODE(10312, 140) {
    pnode->resizeTrigger(PhaseNode_GetActorAttribute::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 139, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10312, 140) {
    auto node140 = GET_SKILL_NODE(140, PhaseNode_GetActorAttribute);
    if (node140 == nullptr) {
        node140 = new PhaseNode_GetActorAttribute(140, phase);
        node140->setTarget(0U);
        node140->setType({});
        CALL_REGISTER_SKILL_NODE(10312, 140, node140)
    }
    if (noInit == true) {
        return node140;
    }
    return node140;
}

//--------------------------------------------------------------------------------
// SkillCreator_10312
//
class SkillCreator_10312 : public SkillCreator {
public:
    SkillCreator_10312() {}
    virtual ~SkillCreator_10312() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_10312

//--------------------------------------------------------------------------------
// SkillPhase_10312
//
class SkillPhase_10312 : public SkillPhase {
public:
    SkillPhase_10312(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_10312() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(10312, 3) // StartPhase
        CASE_CREATE_SKILL_NODE(10312, 5) // TriggerUpdate
        CASE_CREATE_SKILL_NODE(10312, 9) // Delay
        CASE_CREATE_SKILL_NODE(10312, 14) // PlayEffect
        CASE_CREATE_SKILL_NODE(10312, 22) // GetUInt64sValue
        CASE_CREATE_SKILL_NODE(10312, 24) // UInt64sSize
        CASE_CREATE_SKILL_NODE(10312, 27) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(10312, 29) // For
        CASE_CREATE_SKILL_NODE(10312, 31) // ForContinue
        CASE_CREATE_SKILL_NODE(10312, 33) // GetLocation
        CASE_CREATE_SKILL_NODE(10312, 35) // SpawnCollider
        CASE_CREATE_SKILL_NODE(10312, 37) // AttachTo
        CASE_CREATE_SKILL_NODE(10312, 39) // GetLineRotation
        CASE_CREATE_SKILL_NODE(10312, 41) // GetLocation
        CASE_CREATE_SKILL_NODE(10312, 43) // Distance
        CASE_CREATE_SKILL_NODE(10312, 45) // FloatOperation
        CASE_CREATE_SKILL_NODE(10312, 47) // MoveNewPene
        CASE_CREATE_SKILL_NODE(10312, 49) // AddSkillBuff
        CASE_CREATE_SKILL_NODE(10312, 70) // EndPhase
        CASE_CREATE_SKILL_NODE(10312, 74) // Delay
        CASE_CREATE_SKILL_NODE(10312, 76) // AreaCollisionNewPene
        CASE_CREATE_SKILL_NODE(10312, 78) // Delay
        CASE_CREATE_SKILL_NODE(10312, 80) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10312, 82) // PlayEffect
        CASE_CREATE_SKILL_NODE(10312, 84) // PlayEffect
        CASE_CREATE_SKILL_NODE(10312, 86) // GetLocation
        CASE_CREATE_SKILL_NODE(10312, 90) // PlaySound
        CASE_CREATE_SKILL_NODE(10312, 94) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10312, 96) // Detect
        CASE_CREATE_SKILL_NODE(10312, 98) // StopEffect
        CASE_CREATE_SKILL_NODE(10312, 100) // CompareInt
        CASE_CREATE_SKILL_NODE(10312, 102) // AreaCollisionNewPene
        CASE_CREATE_SKILL_NODE(10312, 106) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(10312, 108) // GetInputRotation
        CASE_CREATE_SKILL_NODE(10312, 110) // PlaySound
        CASE_CREATE_SKILL_NODE(10312, 125) // ReviseMapI32
        CASE_CREATE_SKILL_NODE(10312, 134) // Int2Float
        CASE_CREATE_SKILL_NODE(10312, 136) // AddSkillBuff
        CASE_CREATE_SKILL_NODE(10312, 137) // ResetCD
        CASE_CREATE_SKILL_NODE(10312, 138) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10312, 139) // PlaySound
        CASE_CREATE_SKILL_NODE(10312, 140) // GetActorAttribute
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_10312

SkillLogic* SkillCreator_10312::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //创建阶段phase
    auto phase = new SkillPhase_10312(1, logic, 3);
    //设置phase执行器
    phase->setRunPhaseNode(1, 3);
    phase->setRunPhaseNode(2, 5);
    phase->setDetectPhaseNode(3, 96);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_10312::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
