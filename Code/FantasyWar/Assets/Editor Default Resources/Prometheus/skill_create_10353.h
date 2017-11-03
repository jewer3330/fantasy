#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

#include "skill_psnode_addskillbuff.h"
#include "skill_psnode_addskillbuffs.h"
#include "skill_psnode_areacollisionnewpene.h"
#include "skill_psnode_attachto.h"
#include "skill_psnode_comparefloat.h"
#include "skill_psnode_delay.h"
#include "skill_psnode_destroycollider.h"
#include "skill_psnode_detect.h"
#include "skill_psnode_disable.h"
#include "skill_psnode_distance.h"
#include "skill_psnode_endphase.h"
#include "skill_psnode_findskillbuff.h"
#include "skill_psnode_floatoperation.h"
#include "skill_psnode_getactorattribute.h"
#include "skill_psnode_getinputlocation.h"
#include "skill_psnode_getlinerotation.h"
#include "skill_psnode_getlocation.h"
#include "skill_psnode_getuint64svalue.h"
#include "skill_psnode_if.h"
#include "skill_psnode_isinterrupttype.h"
#include "skill_psnode_linechecknewpene.h"
#include "skill_psnode_movenewpene.h"
#include "skill_psnode_offsetcalculate.h"
#include "skill_psnode_playanimation.h"
#include "skill_psnode_playeffect.h"
#include "skill_psnode_playsound.h"
#include "skill_psnode_raiseevent.h"
#include "skill_psnode_removeskillbuff.h"
#include "skill_psnode_resetcd.h"
#include "skill_psnode_setbool.h"
#include "skill_psnode_spawncollider.h"
#include "skill_psnode_startphase.h"
#include "skill_psnode_startpreinput.h"
#include "skill_psnode_stopeffect.h"
#include "skill_psnode_switchtoint.h"

namespace pvp {

//变量声明
uint64_t Variable_10353_a103539 = 0;
uint64_t Variable_10353_InterruptAnimat = 0;
//--------------------------------------------------------------------------------
// StartPhase
//
REGISTER_REGISTER_SKILL_NODE(10353, 4) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_StartPhase::TRIGGER_START, 124, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(10353, 4) {
    auto node4 = GET_SKILL_NODE(4, PhaseNode_StartPhase);
    if (node4 == nullptr) {
        node4 = new PhaseNode_StartPhase(4, phase);
        CALL_REGISTER_SKILL_NODE(10353, 4, node4)
    }
    if (noInit == true) {
        return node4;
    }
    return node4;
}
//--------------------------------------------------------------------------------
// AddSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10353, 7) {
    pnode->resizeTrigger(PhaseNode_AddSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuff>(PhaseNode_AddSkillBuff::TRIGGER_DONE, 121, PhaseNode_AddSkillBuff::FUNC_ADD, &PhaseNode_AddSkillBuff::Add);
    pnode->regTrigger<PhaseNode_Disable>(PhaseNode_AddSkillBuff::TRIGGER_DONE, 9, PhaseNode_Disable::FUNC_DO, &PhaseNode_Disable::Do);
}

REGISTER_CREATE_SKILL_NODE(10353, 7) {
    auto node7 = GET_SKILL_NODE(7, PhaseNode_AddSkillBuff);
    if (node7 == nullptr) {
        node7 = new PhaseNode_AddSkillBuff(7, phase);
        node7->setConfigID(103540);
        node7->setConfigIDs({});
        node7->setTarget(0U);
        node7->setAttribute({{}});
        CALL_REGISTER_SKILL_NODE(10353, 7, node7)
    }
    if (noInit == true) {
        return node7;
    }
    return node7;
}
//--------------------------------------------------------------------------------
// Disable
//
REGISTER_REGISTER_SKILL_NODE(10353, 9) {
    pnode->resizeTrigger(PhaseNode_Disable::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_Disable::TRIGGER_DONE, 17, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(10353, 9) {
    auto node9 = GET_SKILL_NODE(9, PhaseNode_Disable);
    if (node9 == nullptr) {
        node9 = new PhaseNode_Disable(9, phase);
        node9->setTarget(0U);
        node9->setMove(true);
        node9->setSkill(true);
        node9->setShoot(true);
        node9->setTime(2.77f);
        node9->setRotate(true);
        CALL_REGISTER_SKILL_NODE(10353, 9, node9)
    }
    if (noInit == true) {
        return node9;
    }
    return node9;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10353, 13) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Distance>(PhaseNode_Delay::TRIGGER_DONE, 15, PhaseNode_Distance::FUNC_DO, &PhaseNode_Distance::Do);
}

REGISTER_CREATE_SKILL_NODE(10353, 13) {
    auto node13 = GET_SKILL_NODE(13, PhaseNode_Delay);
    if (node13 == nullptr) {
        node13 = new PhaseNode_Delay(13, phase);
        node13->setTime(.16f);
        CALL_REGISTER_SKILL_NODE(10353, 13, node13)
    }
    if (noInit == true) {
        return node13;
    }
    return node13;
}
//--------------------------------------------------------------------------------
// Distance
//
REGISTER_REGISTER_SKILL_NODE(10353, 15) {
    pnode->resizeTrigger(PhaseNode_Distance::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLineRotation>(PhaseNode_Distance::TRIGGER_DONE, 31, PhaseNode_GetLineRotation::FUNC_DO, &PhaseNode_GetLineRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(10353, 15) {
    auto node15 = GET_SKILL_NODE(15, PhaseNode_Distance);
    if (node15 == nullptr) {
        node15 = new PhaseNode_Distance(15, phase);
        CALL_REGISTER_SKILL_NODE(10353, 15, node15)
    }
    if (noInit == true) {
        return node15;
    }
    auto node17 = GET_SKILL_NODE(17, PhaseNode_GetLocation);
    auto node19 = GET_SKILL_NODE(19, PhaseNode_GetInputLocation);
    if (node17 != nullptr) node15->setAX(node17->getX());
    if (node17 != nullptr) node15->setAY(node17->getY());
    if (node19 != nullptr) node15->setBX(node19->getX());
    if (node19 != nullptr) node15->setBY(node19->getY());
    return node15;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(10353, 17) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetInputLocation>(PhaseNode_GetLocation::TRIGGER_DONE, 19, PhaseNode_GetInputLocation::FUNC_DO, &PhaseNode_GetInputLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(10353, 17) {
    auto node17 = GET_SKILL_NODE(17, PhaseNode_GetLocation);
    if (node17 == nullptr) {
        node17 = new PhaseNode_GetLocation(17, phase);
        node17->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node17->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(10353, 17, node17)
    }
    if (noInit == true) {
        return node17;
    }
    return node17;
}
//--------------------------------------------------------------------------------
// GetInputLocation
//
REGISTER_REGISTER_SKILL_NODE(10353, 19) {
    pnode->resizeTrigger(PhaseNode_GetInputLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_GetInputLocation::TRIGGER_DONE, 13, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10353, 19) {
    auto node19 = GET_SKILL_NODE(19, PhaseNode_GetInputLocation);
    if (node19 == nullptr) {
        node19 = new PhaseNode_GetInputLocation(19, phase);
        node19->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        CALL_REGISTER_SKILL_NODE(10353, 19, node19)
    }
    if (noInit == true) {
        return node19;
    }
    return node19;
}
//--------------------------------------------------------------------------------
// GetLineRotation
//
REGISTER_REGISTER_SKILL_NODE(10353, 31) {
    pnode->resizeTrigger(PhaseNode_GetLineRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_FloatOperation>(PhaseNode_GetLineRotation::TRIGGER_DONE, 33, PhaseNode_FloatOperation::FUNC_OPERATION, &PhaseNode_FloatOperation::Operation);
}

REGISTER_CREATE_SKILL_NODE(10353, 31) {
    auto node31 = GET_SKILL_NODE(31, PhaseNode_GetLineRotation);
    if (node31 == nullptr) {
        node31 = new PhaseNode_GetLineRotation(31, phase);
        CALL_REGISTER_SKILL_NODE(10353, 31, node31)
    }
    if (noInit == true) {
        return node31;
    }
    auto node17 = GET_SKILL_NODE(17, PhaseNode_GetLocation);
    auto node19 = GET_SKILL_NODE(19, PhaseNode_GetInputLocation);
    if (node17 != nullptr) node31->setStartX(node17->getX());
    if (node17 != nullptr) node31->setStartY(node17->getY());
    if (node19 != nullptr) node31->setEndX(node19->getX());
    if (node19 != nullptr) node31->setEndY(node19->getY());
    return node31;
}
//--------------------------------------------------------------------------------
// FloatOperation
//
REGISTER_REGISTER_SKILL_NODE(10353, 33) {
    pnode->resizeTrigger(PhaseNode_FloatOperation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_FloatOperation::TRIGGER_DONE, 35, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(10353, 33) {
    auto node33 = GET_SKILL_NODE(33, PhaseNode_FloatOperation);
    if (node33 == nullptr) {
        node33 = new PhaseNode_FloatOperation(33, phase);
        node33->setValue(.40f);
        node33->setMethod(PhaseNode_FloatOperation::FloatOperation_Method::Divis);
        CALL_REGISTER_SKILL_NODE(10353, 33, node33)
    }
    if (noInit == true) {
        return node33;
    }
    auto node15 = GET_SKILL_NODE(15, PhaseNode_Distance);
    if (node15 != nullptr) node33->setBase(node15->getResult());
    return node33;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(10353, 35) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 37, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
    pnode->regTrigger<PhaseNode_SpawnCollider>(PhaseNode_CompareFloat::TRIGGER_GREATER, 39, PhaseNode_SpawnCollider::FUNC_DO, &PhaseNode_SpawnCollider::Do);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_CompareFloat::TRIGGER_LESS, 37, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(10353, 35) {
    auto node35 = GET_SKILL_NODE(35, PhaseNode_CompareFloat);
    if (node35 == nullptr) {
        node35 = new PhaseNode_CompareFloat(35, phase);
        node35->setB(.00f);
        CALL_REGISTER_SKILL_NODE(10353, 35, node35)
    }
    if (noInit == true) {
        return node35;
    }
    auto node15 = GET_SKILL_NODE(15, PhaseNode_Distance);
    if (node15 != nullptr) node35->setA(node15->getResult());
    return node35;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(10353, 37) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_DestroyCollider>(PhaseNode_GetLocation::TRIGGER_DONE, 45, PhaseNode_DestroyCollider::FUNC_DO, &PhaseNode_DestroyCollider::Do);
    pnode->regTrigger<PhaseNode_OffsetCalculate>(PhaseNode_GetLocation::TRIGGER_DONE, 119, PhaseNode_OffsetCalculate::FUNC_DO, &PhaseNode_OffsetCalculate::Do);
}

REGISTER_CREATE_SKILL_NODE(10353, 37) {
    auto node37 = GET_SKILL_NODE(37, PhaseNode_GetLocation);
    if (node37 == nullptr) {
        node37 = new PhaseNode_GetLocation(37, phase);
        node37->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        CALL_REGISTER_SKILL_NODE(10353, 37, node37)
    }
    if (noInit == true) {
        return node37;
    }
    auto node39 = GET_SKILL_NODE(39, PhaseNode_SpawnCollider);
    if (node39 != nullptr) node37->setTarget(node39->getColliderID());
    return node37;
}
//--------------------------------------------------------------------------------
// SpawnCollider
//
REGISTER_REGISTER_SKILL_NODE(10353, 39) {
    pnode->resizeTrigger(PhaseNode_SpawnCollider::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AttachTo>(PhaseNode_SpawnCollider::TRIGGER_DONE, 41, PhaseNode_AttachTo::FUNC_DO, &PhaseNode_AttachTo::Do);
}

REGISTER_CREATE_SKILL_NODE(10353, 39) {
    auto node39 = GET_SKILL_NODE(39, PhaseNode_SpawnCollider);
    if (node39 == nullptr) {
        node39 = new PhaseNode_SpawnCollider(39, phase);
        node39->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node39->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node39->setMesh("");
        node39->setMeshScale(.00f);
        node39->setEffectID(0);
        node39->setEffectScale(-.13f);
        node39->setType(PhaseNode_SpawnCollider::SpawnCollider_Type::Circle);
        node39->setTypeParams(0, .00f);
        node39->setTime(.00f);
        node39->setPosZ(.00f);
        node39->setreentry(false);
        node39->setCheckPeneSound(false);
        CALL_REGISTER_SKILL_NODE(10353, 39, node39)
    }
    if (noInit == true) {
        return node39;
    }
    auto node17 = GET_SKILL_NODE(17, PhaseNode_GetLocation);
    auto node31 = GET_SKILL_NODE(31, PhaseNode_GetLineRotation);
    if (node17 != nullptr) node39->setPosX(node17->getX());
    if (node17 != nullptr) node39->setPosY(node17->getY());
    if (node31 != nullptr) node39->setRotation(node31->getRotation());
    return node39;
}
//--------------------------------------------------------------------------------
// AttachTo
//
REGISTER_REGISTER_SKILL_NODE(10353, 41) {
    pnode->resizeTrigger(PhaseNode_AttachTo::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_MoveNewPene>(PhaseNode_AttachTo::TRIGGER_DONE, 43, PhaseNode_MoveNewPene::FUNC_DO, &PhaseNode_MoveNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(10353, 41) {
    auto node41 = GET_SKILL_NODE(41, PhaseNode_AttachTo);
    if (node41 == nullptr) {
        node41 = new PhaseNode_AttachTo(41, phase);
        node41->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node41->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node41->setChild(0U);
        node41->setChangeRotation(true);
        node41->setreentry(false);
        CALL_REGISTER_SKILL_NODE(10353, 41, node41)
    }
    if (noInit == true) {
        return node41;
    }
    auto node39 = GET_SKILL_NODE(39, PhaseNode_SpawnCollider);
    if (node39 != nullptr) node41->setParent(node39->getColliderID());
    return node41;
}
//--------------------------------------------------------------------------------
// MoveNewPene
//
REGISTER_REGISTER_SKILL_NODE(10353, 43) {
    pnode->resizeTrigger(PhaseNode_MoveNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_MoveNewPene::TRIGGER_BLOCKBYWALL, 37, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_MoveNewPene::TRIGGER_DONE, 37, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(10353, 43) {
    auto node43 = GET_SKILL_NODE(43, PhaseNode_MoveNewPene);
    if (node43 == nullptr) {
        node43 = new PhaseNode_MoveNewPene(43, phase);
        node43->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node43->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node43->setPeneType(PhaseNode_MoveNewPene::MoveNewPene_PeneType::Move);
        node43->setPeneValue(30);
        node43->setType(PhaseNode_MoveNewPene::MoveNewPene_Type::Charge);
        node43->getVars().reserve(4);
        node43->getVars().setVariable<float>(0, .00f);
        node43->getVars().setVariable<float>(1, .00f);
        node43->getVars().setVariable<float>(2, .00f);
        node43->getVars().setVariable<float>(3, .00f);
        node43->setreentry(false);
        node43->setStopWhenFail(true);
        node43->setCheckFaction(PhaseNode_MoveNewPene::MoveNewPene_CheckFaction::Enemy);
        CALL_REGISTER_SKILL_NODE(10353, 43, node43)
    }
    if (noInit == true) {
        return node43;
    }
    auto node39 = GET_SKILL_NODE(39, PhaseNode_SpawnCollider);
    auto node33 = GET_SKILL_NODE(33, PhaseNode_FloatOperation);
    auto node15 = GET_SKILL_NODE(15, PhaseNode_Distance);
    auto node31 = GET_SKILL_NODE(31, PhaseNode_GetLineRotation);
    if (node39 != nullptr) node43->setTarget(node39->getColliderID());
    if (node33 != nullptr) node43->getVars().setVariable<float>(0, node33->getFinal());
    if (node15 != nullptr) node43->getVars().setVariable<float>(1, node15->getResult());
    if (node31 != nullptr) node43->getVars().setVariable<float>(2, node31->getRotation());
    return node43;
}
//--------------------------------------------------------------------------------
// DestroyCollider
//
REGISTER_REGISTER_SKILL_NODE(10353, 45) {
    pnode->resizeTrigger(PhaseNode_DestroyCollider::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RemoveSkillBuff>(PhaseNode_DestroyCollider::TRIGGER_DONE, 123, PhaseNode_RemoveSkillBuff::FUNC_REMOVE, &PhaseNode_RemoveSkillBuff::Remove);
    pnode->regTrigger<PhaseNode_StopEffect>(PhaseNode_DestroyCollider::TRIGGER_DONE, 51, PhaseNode_StopEffect::FUNC_DO, &PhaseNode_StopEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(10353, 45) {
    auto node45 = GET_SKILL_NODE(45, PhaseNode_DestroyCollider);
    if (node45 == nullptr) {
        node45 = new PhaseNode_DestroyCollider(45, phase);
        CALL_REGISTER_SKILL_NODE(10353, 45, node45)
    }
    if (noInit == true) {
        return node45;
    }
    auto node39 = GET_SKILL_NODE(39, PhaseNode_SpawnCollider);
    if (node39 != nullptr) node45->setColliderID(node39->getColliderID());
    return node45;
}
//--------------------------------------------------------------------------------
// StopEffect
//
REGISTER_REGISTER_SKILL_NODE(10353, 51) {
}

REGISTER_CREATE_SKILL_NODE(10353, 51) {
    auto node51 = GET_SKILL_NODE(51, PhaseNode_StopEffect);
    if (node51 == nullptr) {
        node51 = new PhaseNode_StopEffect(51, phase);
        node51->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node51->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node51->setEffectID(103540);
        CALL_REGISTER_SKILL_NODE(10353, 51, node51)
    }
    if (noInit == true) {
        return node51;
    }
    return node51;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10353, 53) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_Delay::TRIGGER_DONE, 55, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(10353, 53) {
    auto node53 = GET_SKILL_NODE(53, PhaseNode_Delay);
    if (node53 == nullptr) {
        node53 = new PhaseNode_Delay(53, phase);
        node53->setTime(2.78f);
        CALL_REGISTER_SKILL_NODE(10353, 53, node53)
    }
    if (noInit == true) {
        return node53;
    }
    return node53;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(10353, 55) {
}

REGISTER_CREATE_SKILL_NODE(10353, 55) {
    auto node55 = GET_SKILL_NODE(55, PhaseNode_EndPhase);
    if (node55 == nullptr) {
        node55 = new PhaseNode_EndPhase(55, phase);
        node55->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node55->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10353, 55, node55)
    }
    if (noInit == true) {
        return node55;
    }
    return node55;
}
//--------------------------------------------------------------------------------
// AreaCollisionNewPene
//
REGISTER_REGISTER_SKILL_NODE(10353, 57) {
    pnode->resizeTrigger(PhaseNode_AreaCollisionNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetUInt64sValue>(PhaseNode_AreaCollisionNewPene::TRIGGER_DONE, 93, PhaseNode_GetUInt64sValue::FUNC_DO, &PhaseNode_GetUInt64sValue::Do);
    pnode->regTrigger<PhaseNode_LineCheckNewPene>(PhaseNode_AreaCollisionNewPene::TRIGGER_DONE, 59, PhaseNode_LineCheckNewPene::FUNC_DO, &PhaseNode_LineCheckNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(10353, 57) {
    auto node57 = GET_SKILL_NODE(57, PhaseNode_AreaCollisionNewPene);
    if (node57 == nullptr) {
        node57 = new PhaseNode_AreaCollisionNewPene(57, phase);
        node57->setState(PhaseNode_AreaCollisionNewPene::AreaCollisionNewPene_State::Alive);
        node57->setFaction(PhaseNode_AreaCollisionNewPene::AreaCollisionNewPene_Faction::Enemy);
        node57->setOnHero(true);
        node57->setOnMinion(true);
        node57->setOnDestruct(true);
        node57->setOnShield(false);
        node57->setType(PhaseNode_AreaCollisionNewPene::AreaCollisionNewPene_Type::Circle);
        node57->setTypeParams(0, 5.00f);
        node57->setPositionZ(.00f);
        node57->setRotation(.00f);
        CALL_REGISTER_SKILL_NODE(10353, 57, node57)
    }
    if (noInit == true) {
        return node57;
    }
    auto node119 = GET_SKILL_NODE(119, PhaseNode_OffsetCalculate);
    if (node119 != nullptr) node57->setPositionX(node119->getOutPosX());
    if (node119 != nullptr) node57->setPositionY(node119->getOutPosY());
    return node57;
}
//--------------------------------------------------------------------------------
// LineCheckNewPene
//
REGISTER_REGISTER_SKILL_NODE(10353, 59) {
    pnode->resizeTrigger(PhaseNode_LineCheckNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_LineCheckNewPene::TRIGGER_DONE, 63, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
}

REGISTER_CREATE_SKILL_NODE(10353, 59) {
    auto node59 = GET_SKILL_NODE(59, PhaseNode_LineCheckNewPene);
    if (node59 == nullptr) {
        node59 = new PhaseNode_LineCheckNewPene(59, phase);
        node59->setFromX(.00f);
        node59->setFromY(.00f);
        node59->setPeneProjectile(15);
        CALL_REGISTER_SKILL_NODE(10353, 59, node59)
    }
    if (noInit == true) {
        return node59;
    }
    auto node57 = GET_SKILL_NODE(57, PhaseNode_AreaCollisionNewPene);
    if (node57 != nullptr) node59->setTargets(node57->getColliders());
    return node59;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(10353, 63) {
}

REGISTER_CREATE_SKILL_NODE(10353, 63) {
    auto node63 = GET_SKILL_NODE(63, PhaseNode_AddSkillBuffs);
    if (node63 == nullptr) {
        node63 = new PhaseNode_AddSkillBuffs(63, phase);
        node63->setConfigID({103531});
        CALL_REGISTER_SKILL_NODE(10353, 63, node63)
    }
    if (noInit == true) {
        return node63;
    }
    auto node59 = GET_SKILL_NODE(59, PhaseNode_LineCheckNewPene);
    auto node127 = GET_SKILL_NODE(127, PhaseNode_GetActorAttribute);
    if (node59 != nullptr) node63->setTarget(node59->getOutput());
    if (node127 != nullptr) node63->setAttribute(node127->getAttribute());
    return node63;
}
//--------------------------------------------------------------------------------
// AreaCollisionNewPene
//
REGISTER_REGISTER_SKILL_NODE(10353, 64) {
    pnode->resizeTrigger(PhaseNode_AreaCollisionNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_LineCheckNewPene>(PhaseNode_AreaCollisionNewPene::TRIGGER_DONE, 65, PhaseNode_LineCheckNewPene::FUNC_DO, &PhaseNode_LineCheckNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(10353, 64) {
    auto node64 = GET_SKILL_NODE(64, PhaseNode_AreaCollisionNewPene);
    if (node64 == nullptr) {
        node64 = new PhaseNode_AreaCollisionNewPene(64, phase);
        node64->setState(PhaseNode_AreaCollisionNewPene::AreaCollisionNewPene_State::Alive);
        node64->setFaction(PhaseNode_AreaCollisionNewPene::AreaCollisionNewPene_Faction::Enemy);
        node64->setOnHero(true);
        node64->setOnMinion(true);
        node64->setOnDestruct(true);
        node64->setOnShield(false);
        node64->setType(PhaseNode_AreaCollisionNewPene::AreaCollisionNewPene_Type::Circle);
        node64->setTypeParams(0, 8.00f);
        node64->setPositionZ(.00f);
        node64->setRotation(.00f);
        CALL_REGISTER_SKILL_NODE(10353, 64, node64)
    }
    if (noInit == true) {
        return node64;
    }
    auto node119 = GET_SKILL_NODE(119, PhaseNode_OffsetCalculate);
    if (node119 != nullptr) node64->setPositionX(node119->getOutPosX());
    if (node119 != nullptr) node64->setPositionY(node119->getOutPosY());
    return node64;
}
//--------------------------------------------------------------------------------
// LineCheckNewPene
//
REGISTER_REGISTER_SKILL_NODE(10353, 65) {
    pnode->resizeTrigger(PhaseNode_LineCheckNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_LineCheckNewPene::TRIGGER_DONE, 109, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
    pnode->regTrigger<PhaseNode_GetUInt64sValue>(PhaseNode_LineCheckNewPene::TRIGGER_DONE, 97, PhaseNode_GetUInt64sValue::FUNC_DO, &PhaseNode_GetUInt64sValue::Do);
}

REGISTER_CREATE_SKILL_NODE(10353, 65) {
    auto node65 = GET_SKILL_NODE(65, PhaseNode_LineCheckNewPene);
    if (node65 == nullptr) {
        node65 = new PhaseNode_LineCheckNewPene(65, phase);
        node65->setFromX(.00f);
        node65->setFromY(.00f);
        node65->setPeneProjectile(15);
        CALL_REGISTER_SKILL_NODE(10353, 65, node65)
    }
    if (noInit == true) {
        return node65;
    }
    auto node64 = GET_SKILL_NODE(64, PhaseNode_AreaCollisionNewPene);
    if (node64 != nullptr) node65->setTargets(node64->getColliders());
    return node65;
}
//--------------------------------------------------------------------------------
// AreaCollisionNewPene
//
REGISTER_REGISTER_SKILL_NODE(10353, 67) {
    pnode->resizeTrigger(PhaseNode_AreaCollisionNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_LineCheckNewPene>(PhaseNode_AreaCollisionNewPene::TRIGGER_DONE, 68, PhaseNode_LineCheckNewPene::FUNC_DO, &PhaseNode_LineCheckNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(10353, 67) {
    auto node67 = GET_SKILL_NODE(67, PhaseNode_AreaCollisionNewPene);
    if (node67 == nullptr) {
        node67 = new PhaseNode_AreaCollisionNewPene(67, phase);
        node67->setState(PhaseNode_AreaCollisionNewPene::AreaCollisionNewPene_State::Alive);
        node67->setFaction(PhaseNode_AreaCollisionNewPene::AreaCollisionNewPene_Faction::Enemy);
        node67->setOnHero(true);
        node67->setOnMinion(true);
        node67->setOnDestruct(true);
        node67->setOnShield(false);
        node67->setType(PhaseNode_AreaCollisionNewPene::AreaCollisionNewPene_Type::Circle);
        node67->setTypeParams(0, 6.50f);
        node67->setPositionZ(.00f);
        node67->setRotation(.00f);
        CALL_REGISTER_SKILL_NODE(10353, 67, node67)
    }
    if (noInit == true) {
        return node67;
    }
    auto node119 = GET_SKILL_NODE(119, PhaseNode_OffsetCalculate);
    if (node119 != nullptr) node67->setPositionX(node119->getOutPosX());
    if (node119 != nullptr) node67->setPositionY(node119->getOutPosY());
    return node67;
}
//--------------------------------------------------------------------------------
// LineCheckNewPene
//
REGISTER_REGISTER_SKILL_NODE(10353, 68) {
    pnode->resizeTrigger(PhaseNode_LineCheckNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_LineCheckNewPene::TRIGGER_DONE, 69, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
    pnode->regTrigger<PhaseNode_GetUInt64sValue>(PhaseNode_LineCheckNewPene::TRIGGER_DONE, 96, PhaseNode_GetUInt64sValue::FUNC_DO, &PhaseNode_GetUInt64sValue::Do);
}

REGISTER_CREATE_SKILL_NODE(10353, 68) {
    auto node68 = GET_SKILL_NODE(68, PhaseNode_LineCheckNewPene);
    if (node68 == nullptr) {
        node68 = new PhaseNode_LineCheckNewPene(68, phase);
        node68->setFromX(.00f);
        node68->setFromY(.00f);
        node68->setPeneProjectile(15);
        CALL_REGISTER_SKILL_NODE(10353, 68, node68)
    }
    if (noInit == true) {
        return node68;
    }
    auto node67 = GET_SKILL_NODE(67, PhaseNode_AreaCollisionNewPene);
    if (node67 != nullptr) node68->setTargets(node67->getColliders());
    return node68;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(10353, 69) {
}

REGISTER_CREATE_SKILL_NODE(10353, 69) {
    auto node69 = GET_SKILL_NODE(69, PhaseNode_AddSkillBuffs);
    if (node69 == nullptr) {
        node69 = new PhaseNode_AddSkillBuffs(69, phase);
        node69->setConfigID({103532});
        CALL_REGISTER_SKILL_NODE(10353, 69, node69)
    }
    if (noInit == true) {
        return node69;
    }
    auto node68 = GET_SKILL_NODE(68, PhaseNode_LineCheckNewPene);
    auto node127 = GET_SKILL_NODE(127, PhaseNode_GetActorAttribute);
    if (node68 != nullptr) node69->setTarget(node68->getOutput());
    if (node127 != nullptr) node69->setAttribute(node127->getAttribute());
    return node69;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10353, 84) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AreaCollisionNewPene>(PhaseNode_Delay::TRIGGER_DONE, 57, PhaseNode_AreaCollisionNewPene::FUNC_DO, &PhaseNode_AreaCollisionNewPene::Do);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_Delay::TRIGGER_DONE, 88, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(10353, 84) {
    auto node84 = GET_SKILL_NODE(84, PhaseNode_Delay);
    if (node84 == nullptr) {
        node84 = new PhaseNode_Delay(84, phase);
        node84->setTime(.07f);
        CALL_REGISTER_SKILL_NODE(10353, 84, node84)
    }
    if (noInit == true) {
        return node84;
    }
    return node84;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10353, 85) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AreaCollisionNewPene>(PhaseNode_Delay::TRIGGER_DONE, 67, PhaseNode_AreaCollisionNewPene::FUNC_DO, &PhaseNode_AreaCollisionNewPene::Do);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_Delay::TRIGGER_DONE, 89, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(10353, 85) {
    auto node85 = GET_SKILL_NODE(85, PhaseNode_Delay);
    if (node85 == nullptr) {
        node85 = new PhaseNode_Delay(85, phase);
        node85->setTime(.57f);
        CALL_REGISTER_SKILL_NODE(10353, 85, node85)
    }
    if (noInit == true) {
        return node85;
    }
    return node85;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10353, 86) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AreaCollisionNewPene>(PhaseNode_Delay::TRIGGER_DONE, 64, PhaseNode_AreaCollisionNewPene::FUNC_DO, &PhaseNode_AreaCollisionNewPene::Do);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_Delay::TRIGGER_DONE, 90, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(10353, 86) {
    auto node86 = GET_SKILL_NODE(86, PhaseNode_Delay);
    if (node86 == nullptr) {
        node86 = new PhaseNode_Delay(86, phase);
        node86->setTime(1.37f);
        CALL_REGISTER_SKILL_NODE(10353, 86, node86)
    }
    if (noInit == true) {
        return node86;
    }
    return node86;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(10353, 88) {
}

REGISTER_CREATE_SKILL_NODE(10353, 88) {
    auto node88 = GET_SKILL_NODE(88, PhaseNode_PlayEffect);
    if (node88 == nullptr) {
        node88 = new PhaseNode_PlayEffect(88, phase);
        node88->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node88->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node88->setEffectID(103531);
        node88->setChangeColor(false);
        node88->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node88->getVars().reserve(3);
        node88->getVars().setVariable<float>(0, .00f);
        node88->getVars().setVariable<float>(1, .00f);
        node88->getVars().setVariable<float>(2, .00f);
        node88->setRotation(.00f);
        node88->setScale(.00f);
        CALL_REGISTER_SKILL_NODE(10353, 88, node88)
    }
    if (noInit == true) {
        return node88;
    }
    auto node119 = GET_SKILL_NODE(119, PhaseNode_OffsetCalculate);
    if (node119 != nullptr) node88->getVars().setVariable<float>(0, node119->getOutPosX());
    if (node119 != nullptr) node88->getVars().setVariable<float>(1, node119->getOutPosY());
    return node88;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(10353, 89) {
}

REGISTER_CREATE_SKILL_NODE(10353, 89) {
    auto node89 = GET_SKILL_NODE(89, PhaseNode_PlayEffect);
    if (node89 == nullptr) {
        node89 = new PhaseNode_PlayEffect(89, phase);
        node89->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node89->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node89->setEffectID(103534);
        node89->setChangeColor(false);
        node89->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node89->getVars().reserve(3);
        node89->getVars().setVariable<float>(0, .00f);
        node89->getVars().setVariable<float>(1, .00f);
        node89->getVars().setVariable<float>(2, .00f);
        node89->setRotation(.00f);
        node89->setScale(.00f);
        CALL_REGISTER_SKILL_NODE(10353, 89, node89)
    }
    if (noInit == true) {
        return node89;
    }
    auto node119 = GET_SKILL_NODE(119, PhaseNode_OffsetCalculate);
    if (node119 != nullptr) node89->getVars().setVariable<float>(0, node119->getOutPosX());
    if (node119 != nullptr) node89->getVars().setVariable<float>(1, node119->getOutPosY());
    return node89;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(10353, 90) {
}

REGISTER_CREATE_SKILL_NODE(10353, 90) {
    auto node90 = GET_SKILL_NODE(90, PhaseNode_PlayEffect);
    if (node90 == nullptr) {
        node90 = new PhaseNode_PlayEffect(90, phase);
        node90->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node90->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node90->setEffectID(103535);
        node90->setChangeColor(false);
        node90->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node90->getVars().reserve(3);
        node90->getVars().setVariable<float>(0, .00f);
        node90->getVars().setVariable<float>(1, .00f);
        node90->getVars().setVariable<float>(2, .00f);
        node90->setRotation(.00f);
        node90->setScale(.00f);
        CALL_REGISTER_SKILL_NODE(10353, 90, node90)
    }
    if (noInit == true) {
        return node90;
    }
    auto node119 = GET_SKILL_NODE(119, PhaseNode_OffsetCalculate);
    if (node119 != nullptr) node90->getVars().setVariable<float>(0, node119->getOutPosX());
    if (node119 != nullptr) node90->getVars().setVariable<float>(1, node119->getOutPosY());
    return node90;
}
//--------------------------------------------------------------------------------
// GetUInt64sValue
//
REGISTER_REGISTER_SKILL_NODE(10353, 93) {
    pnode->resizeTrigger(PhaseNode_GetUInt64sValue::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_FindSkillBuff>(PhaseNode_GetUInt64sValue::TRIGGER_DONE, 105, PhaseNode_FindSkillBuff::FUNC_DO, &PhaseNode_FindSkillBuff::Do);
}

REGISTER_CREATE_SKILL_NODE(10353, 93) {
    auto node93 = GET_SKILL_NODE(93, PhaseNode_GetUInt64sValue);
    if (node93 == nullptr) {
        node93 = new PhaseNode_GetUInt64sValue(93, phase);
        node93->setIndex(0);
        CALL_REGISTER_SKILL_NODE(10353, 93, node93)
    }
    if (noInit == true) {
        return node93;
    }
    auto node59 = GET_SKILL_NODE(59, PhaseNode_LineCheckNewPene);
    if (node59 != nullptr) node93->setArr(node59->getOutput());
    return node93;
}
//--------------------------------------------------------------------------------
// GetUInt64sValue
//
REGISTER_REGISTER_SKILL_NODE(10353, 96) {
    pnode->resizeTrigger(PhaseNode_GetUInt64sValue::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_FindSkillBuff>(PhaseNode_GetUInt64sValue::TRIGGER_DONE, 106, PhaseNode_FindSkillBuff::FUNC_DO, &PhaseNode_FindSkillBuff::Do);
}

REGISTER_CREATE_SKILL_NODE(10353, 96) {
    auto node96 = GET_SKILL_NODE(96, PhaseNode_GetUInt64sValue);
    if (node96 == nullptr) {
        node96 = new PhaseNode_GetUInt64sValue(96, phase);
        node96->setIndex(0);
        CALL_REGISTER_SKILL_NODE(10353, 96, node96)
    }
    if (noInit == true) {
        return node96;
    }
    auto node68 = GET_SKILL_NODE(68, PhaseNode_LineCheckNewPene);
    if (node68 != nullptr) node96->setArr(node68->getOutput());
    return node96;
}
//--------------------------------------------------------------------------------
// GetUInt64sValue
//
REGISTER_REGISTER_SKILL_NODE(10353, 97) {
    pnode->resizeTrigger(PhaseNode_GetUInt64sValue::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_FindSkillBuff>(PhaseNode_GetUInt64sValue::TRIGGER_DONE, 107, PhaseNode_FindSkillBuff::FUNC_DO, &PhaseNode_FindSkillBuff::Do);
}

REGISTER_CREATE_SKILL_NODE(10353, 97) {
    auto node97 = GET_SKILL_NODE(97, PhaseNode_GetUInt64sValue);
    if (node97 == nullptr) {
        node97 = new PhaseNode_GetUInt64sValue(97, phase);
        node97->setIndex(0);
        CALL_REGISTER_SKILL_NODE(10353, 97, node97)
    }
    if (noInit == true) {
        return node97;
    }
    auto node65 = GET_SKILL_NODE(65, PhaseNode_LineCheckNewPene);
    if (node65 != nullptr) node97->setArr(node65->getOutput());
    return node97;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(10353, 99) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuff>(PhaseNode_If::TRIGGER_TRUE, 113, PhaseNode_AddSkillBuff::FUNC_ADD, &PhaseNode_AddSkillBuff::Add);
}

REGISTER_CREATE_SKILL_NODE(10353, 99) {
    auto node99 = GET_SKILL_NODE(99, PhaseNode_If);
    if (node99 == nullptr) {
        node99 = new PhaseNode_If(99, phase);
        CALL_REGISTER_SKILL_NODE(10353, 99, node99)
    }
    if (noInit == true) {
        return node99;
    }
    auto node105 = GET_SKILL_NODE(105, PhaseNode_FindSkillBuff);
    if (node105 != nullptr) node99->setCondition(node105->getResult());
    return node99;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(10353, 102) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuff>(PhaseNode_If::TRIGGER_TRUE, 114, PhaseNode_AddSkillBuff::FUNC_ADD, &PhaseNode_AddSkillBuff::Add);
}

REGISTER_CREATE_SKILL_NODE(10353, 102) {
    auto node102 = GET_SKILL_NODE(102, PhaseNode_If);
    if (node102 == nullptr) {
        node102 = new PhaseNode_If(102, phase);
        CALL_REGISTER_SKILL_NODE(10353, 102, node102)
    }
    if (noInit == true) {
        return node102;
    }
    auto node106 = GET_SKILL_NODE(106, PhaseNode_FindSkillBuff);
    if (node106 != nullptr) node102->setCondition(node106->getResult());
    return node102;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(10353, 103) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuff>(PhaseNode_If::TRIGGER_TRUE, 115, PhaseNode_AddSkillBuff::FUNC_ADD, &PhaseNode_AddSkillBuff::Add);
}

REGISTER_CREATE_SKILL_NODE(10353, 103) {
    auto node103 = GET_SKILL_NODE(103, PhaseNode_If);
    if (node103 == nullptr) {
        node103 = new PhaseNode_If(103, phase);
        CALL_REGISTER_SKILL_NODE(10353, 103, node103)
    }
    if (noInit == true) {
        return node103;
    }
    auto node107 = GET_SKILL_NODE(107, PhaseNode_FindSkillBuff);
    if (node107 != nullptr) node103->setCondition(node107->getResult());
    return node103;
}
//--------------------------------------------------------------------------------
// FindSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10353, 105) {
    pnode->resizeTrigger(PhaseNode_FindSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_FindSkillBuff::TRIGGER_DONE, 99, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(10353, 105) {
    auto node105 = GET_SKILL_NODE(105, PhaseNode_FindSkillBuff);
    if (node105 == nullptr) {
        node105 = new PhaseNode_FindSkillBuff(105, phase);
        node105->setSelfTarget(0U);
        node105->setConfigID(103502);
        CALL_REGISTER_SKILL_NODE(10353, 105, node105)
    }
    if (noInit == true) {
        return node105;
    }
    auto node93 = GET_SKILL_NODE(93, PhaseNode_GetUInt64sValue);
    if (node93 != nullptr) node105->setDetectTarget(node93->getValue());
    return node105;
}
//--------------------------------------------------------------------------------
// FindSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10353, 106) {
    pnode->resizeTrigger(PhaseNode_FindSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_FindSkillBuff::TRIGGER_DONE, 102, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(10353, 106) {
    auto node106 = GET_SKILL_NODE(106, PhaseNode_FindSkillBuff);
    if (node106 == nullptr) {
        node106 = new PhaseNode_FindSkillBuff(106, phase);
        node106->setSelfTarget(0U);
        node106->setConfigID(103502);
        CALL_REGISTER_SKILL_NODE(10353, 106, node106)
    }
    if (noInit == true) {
        return node106;
    }
    auto node96 = GET_SKILL_NODE(96, PhaseNode_GetUInt64sValue);
    if (node96 != nullptr) node106->setDetectTarget(node96->getValue());
    return node106;
}
//--------------------------------------------------------------------------------
// FindSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10353, 107) {
    pnode->resizeTrigger(PhaseNode_FindSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_FindSkillBuff::TRIGGER_DONE, 103, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(10353, 107) {
    auto node107 = GET_SKILL_NODE(107, PhaseNode_FindSkillBuff);
    if (node107 == nullptr) {
        node107 = new PhaseNode_FindSkillBuff(107, phase);
        node107->setSelfTarget(0U);
        node107->setConfigID(103502);
        CALL_REGISTER_SKILL_NODE(10353, 107, node107)
    }
    if (noInit == true) {
        return node107;
    }
    auto node97 = GET_SKILL_NODE(97, PhaseNode_GetUInt64sValue);
    if (node97 != nullptr) node107->setDetectTarget(node97->getValue());
    return node107;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(10353, 109) {
}

REGISTER_CREATE_SKILL_NODE(10353, 109) {
    auto node109 = GET_SKILL_NODE(109, PhaseNode_AddSkillBuffs);
    if (node109 == nullptr) {
        node109 = new PhaseNode_AddSkillBuffs(109, phase);
        node109->setConfigID({103536,103533});
        CALL_REGISTER_SKILL_NODE(10353, 109, node109)
    }
    if (noInit == true) {
        return node109;
    }
    auto node65 = GET_SKILL_NODE(65, PhaseNode_LineCheckNewPene);
    auto node127 = GET_SKILL_NODE(127, PhaseNode_GetActorAttribute);
    if (node65 != nullptr) node109->setTarget(node65->getOutput());
    if (node127 != nullptr) node109->setAttribute(node127->getAttribute());
    return node109;
}
//--------------------------------------------------------------------------------
// AddSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10353, 113) {
}

REGISTER_CREATE_SKILL_NODE(10353, 113) {
    auto node113 = GET_SKILL_NODE(113, PhaseNode_AddSkillBuff);
    if (node113 == nullptr) {
        node113 = new PhaseNode_AddSkillBuff(113, phase);
        node113->setConfigID(103537);
        node113->setConfigIDs({});
        CALL_REGISTER_SKILL_NODE(10353, 113, node113)
    }
    if (noInit == true) {
        return node113;
    }
    auto node93 = GET_SKILL_NODE(93, PhaseNode_GetUInt64sValue);
    auto node127 = GET_SKILL_NODE(127, PhaseNode_GetActorAttribute);
    if (node93 != nullptr) node113->setTarget(node93->getValue());
    if (node127 != nullptr) node113->setAttribute(node127->getAttribute());
    return node113;
}
//--------------------------------------------------------------------------------
// AddSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10353, 114) {
}

REGISTER_CREATE_SKILL_NODE(10353, 114) {
    auto node114 = GET_SKILL_NODE(114, PhaseNode_AddSkillBuff);
    if (node114 == nullptr) {
        node114 = new PhaseNode_AddSkillBuff(114, phase);
        node114->setConfigID(103538);
        node114->setConfigIDs({});
        CALL_REGISTER_SKILL_NODE(10353, 114, node114)
    }
    if (noInit == true) {
        return node114;
    }
    auto node96 = GET_SKILL_NODE(96, PhaseNode_GetUInt64sValue);
    auto node127 = GET_SKILL_NODE(127, PhaseNode_GetActorAttribute);
    if (node96 != nullptr) node114->setTarget(node96->getValue());
    if (node127 != nullptr) node114->setAttribute(node127->getAttribute());
    return node114;
}
//--------------------------------------------------------------------------------
// AddSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10353, 115) {
}

REGISTER_CREATE_SKILL_NODE(10353, 115) {
    auto node115 = GET_SKILL_NODE(115, PhaseNode_AddSkillBuff);
    if (node115 == nullptr) {
        node115 = new PhaseNode_AddSkillBuff(115, phase);
        node115->setConfigID(103539);
        node115->setConfigIDs({});
        CALL_REGISTER_SKILL_NODE(10353, 115, node115)
    }
    if (noInit == true) {
        return node115;
    }
    auto node97 = GET_SKILL_NODE(97, PhaseNode_GetUInt64sValue);
    auto node127 = GET_SKILL_NODE(127, PhaseNode_GetActorAttribute);
    if (node97 != nullptr) node115->setTarget(node97->getValue());
    if (node127 != nullptr) node115->setAttribute(node127->getAttribute());
    return node115;
}
//--------------------------------------------------------------------------------
// OffsetCalculate
//
REGISTER_REGISTER_SKILL_NODE(10353, 119) {
    pnode->resizeTrigger(PhaseNode_OffsetCalculate::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 53, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 84, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 85, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 86, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10353, 119) {
    auto node119 = GET_SKILL_NODE(119, PhaseNode_OffsetCalculate);
    if (node119 == nullptr) {
        node119 = new PhaseNode_OffsetCalculate(119, phase);
        node119->setPosZ(.00f);
        node119->setOffsetX(.00f);
        node119->setOffsetY(.00f);
        node119->setOffsetZ(.00f);
        node119->setRotation(.00f);
        node119->setRotOffset(.00f);
        CALL_REGISTER_SKILL_NODE(10353, 119, node119)
    }
    if (noInit == true) {
        return node119;
    }
    auto node37 = GET_SKILL_NODE(37, PhaseNode_GetLocation);
    if (node37 != nullptr) node119->setPosX(node37->getX());
    if (node37 != nullptr) node119->setPosY(node37->getY());
    return node119;
}
//--------------------------------------------------------------------------------
// AddSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10353, 121) {
}

REGISTER_CREATE_SKILL_NODE(10353, 121) {
    auto node121 = GET_SKILL_NODE(121, PhaseNode_AddSkillBuff);
    if (node121 == nullptr) {
        node121 = new PhaseNode_AddSkillBuff(121, phase);
        node121->setConfigID(103542);
        node121->setConfigIDs({});
        node121->setTarget(0U);
        node121->setAttribute({{}});
        CALL_REGISTER_SKILL_NODE(10353, 121, node121)
    }
    if (noInit == true) {
        return node121;
    }
    return node121;
}
//--------------------------------------------------------------------------------
// RemoveSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10353, 123) {
}

REGISTER_CREATE_SKILL_NODE(10353, 123) {
    auto node123 = GET_SKILL_NODE(123, PhaseNode_RemoveSkillBuff);
    if (node123 == nullptr) {
        node123 = new PhaseNode_RemoveSkillBuff(123, phase);
        node123->setBuffID(0U);
        node123->setBuffIDs({});
        node123->setConfigID(103542);
        node123->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(10353, 123, node123)
    }
    if (noInit == true) {
        return node123;
    }
    return node123;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(10353, 124) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_ResetCD::TRIGGER_DONE, 125, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10353, 124) {
    auto node124 = GET_SKILL_NODE(124, PhaseNode_ResetCD);
    if (node124 == nullptr) {
        node124 = new PhaseNode_ResetCD(124, phase);
        node124->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node124->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node124->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(10353, 124, node124)
    }
    if (noInit == true) {
        return node124;
    }
    return node124;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10353, 125) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_PlayAnimation::TRIGGER_DONE, 127, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(10353, 125) {
    auto node125 = GET_SKILL_NODE(125, PhaseNode_PlayAnimation);
    if (node125 == nullptr) {
        node125 = new PhaseNode_PlayAnimation(125, phase);
        node125->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node125->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node125->setTarget(0U);
        node125->setAnimation("Skill3S1");
        node125->setParameter("");
        node125->setValue(false);
        CALL_REGISTER_SKILL_NODE(10353, 125, node125)
    }
    if (noInit == true) {
        return node125;
    }
    return node125;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10353, 126) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuff>(PhaseNode_PlaySound::TRIGGER_DONE, 7, PhaseNode_AddSkillBuff::FUNC_ADD, &PhaseNode_AddSkillBuff::Add);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_PlaySound::TRIGGER_DONE, 132, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10353, 126) {
    auto node126 = GET_SKILL_NODE(126, PhaseNode_PlaySound);
    if (node126 == nullptr) {
        node126 = new PhaseNode_PlaySound(126, phase);
        node126->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node126->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node126->setSoundID("");
        node126->setTarget(0U);
        node126->setUsePos(false);
        node126->setPosX(.00f);
        node126->setPosY(.00f);
        node126->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10353, 126, node126)
    }
    if (noInit == true) {
        return node126;
    }
    return node126;
}
//--------------------------------------------------------------------------------
// GetActorAttribute
//
REGISTER_REGISTER_SKILL_NODE(10353, 127) {
    pnode->resizeTrigger(PhaseNode_GetActorAttribute::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 126, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10353, 127) {
    auto node127 = GET_SKILL_NODE(127, PhaseNode_GetActorAttribute);
    if (node127 == nullptr) {
        node127 = new PhaseNode_GetActorAttribute(127, phase);
        node127->setTarget(0U);
        node127->setType({});
        CALL_REGISTER_SKILL_NODE(10353, 127, node127)
    }
    if (noInit == true) {
        return node127;
    }
    return node127;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10353, 129) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_IsInterruptType>(PhaseNode_Detect::TRIGGER_ON, 135, PhaseNode_IsInterruptType::FUNC_DO, &PhaseNode_IsInterruptType::Do);
}

REGISTER_CREATE_SKILL_NODE(10353, 129) {
    auto node129 = GET_SKILL_NODE(129, PhaseNode_Detect);
    if (node129 == nullptr) {
        node129 = new PhaseNode_Detect(129, phase);
        node129->setSelf(0U);
        node129->setEvent("daduan_001");
        node129->setType(PhaseNode_Detect::Detect_Type::Interrupt_Skill);
        node129->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10353, 129, node129)
    }
    if (noInit == true) {
        return node129;
    }
    return node129;
}
//--------------------------------------------------------------------------------
// SwitchToInt
//
REGISTER_REGISTER_SKILL_NODE(10353, 130) {
}

REGISTER_CREATE_SKILL_NODE(10353, 130) {
    auto node130 = GET_SKILL_NODE(130, PhaseNode_SwitchToInt);
    if (node130 == nullptr) {
        node130 = new PhaseNode_SwitchToInt(130, phase);
        CALL_REGISTER_SKILL_NODE(10353, 130, node130)
    }
    if (noInit == true) {
        return node130;
    }
    auto variables = node130->getVariables();
    if (variables != nullptr) {
        node130->setSelection(variables->getVariable<int32_t>(Variable_10353_a103539));
    }
    return node130;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10353, 132) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_RaiseEvent::TRIGGER_DONE, 141, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10353, 132) {
    auto node132 = GET_SKILL_NODE(132, PhaseNode_RaiseEvent);
    if (node132 == nullptr) {
        node132 = new PhaseNode_RaiseEvent(132, phase);
        node132->setEvent("daduan_001");
        node132->setTarget(0U);
        node132->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node132->setTypeParams(0, 0);
        node132->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10353, 132, node132)
    }
    if (noInit == true) {
        return node132;
    }
    return node132;
}
//--------------------------------------------------------------------------------
// StartPreInput
//
REGISTER_REGISTER_SKILL_NODE(10353, 133) {
    pnode->resizeTrigger(PhaseNode_StartPreInput::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_StartPreInput::TRIGGER_DONE, 137, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10353, 133) {
    auto node133 = GET_SKILL_NODE(133, PhaseNode_StartPreInput);
    if (node133 == nullptr) {
        node133 = new PhaseNode_StartPreInput(133, phase);
        node133->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node133->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node133->setDelayTime(.00f);
        CALL_REGISTER_SKILL_NODE(10353, 133, node133)
    }
    if (noInit == true) {
        return node133;
    }
    return node133;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(10353, 134) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_If::TRIGGER_TRUE, 136, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10353, 134) {
    auto node134 = GET_SKILL_NODE(134, PhaseNode_If);
    if (node134 == nullptr) {
        node134 = new PhaseNode_If(134, phase);
        CALL_REGISTER_SKILL_NODE(10353, 134, node134)
    }
    if (noInit == true) {
        return node134;
    }
    auto variables = node134->getVariables();
    if (variables != nullptr) {
        node134->setCondition(variables->getVariable<bool>(Variable_10353_InterruptAnimat));
    }
    return node134;
}
//--------------------------------------------------------------------------------
// IsInterruptType
//
REGISTER_REGISTER_SKILL_NODE(10353, 135) {
    pnode->resizeTrigger(PhaseNode_IsInterruptType::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SwitchToInt>(PhaseNode_IsInterruptType::TRIGGER_BUFF, 130, PhaseNode_SwitchToInt::FUNC_SWITCH, &PhaseNode_SwitchToInt::Switch);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_POSCHANGE, 134, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTAIM, 134, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTFIRE, 134, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTRELOAD, 134, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_USESKILL, 134, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(10353, 135) {
    auto node135 = GET_SKILL_NODE(135, PhaseNode_IsInterruptType);
    if (node135 == nullptr) {
        node135 = new PhaseNode_IsInterruptType(135, phase);
        node135->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node135->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10353, 135, node135)
    }
    if (noInit == true) {
        return node135;
    }
    auto node129 = GET_SKILL_NODE(129, PhaseNode_Detect);
    if (node129 != nullptr) node135->setType(node129->getVars().getVariable<int32_t>(2));
    return node135;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10353, 136) {
}

REGISTER_CREATE_SKILL_NODE(10353, 136) {
    auto node136 = GET_SKILL_NODE(136, PhaseNode_PlayAnimation);
    if (node136 == nullptr) {
        node136 = new PhaseNode_PlayAnimation(136, phase);
        node136->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node136->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node136->setTarget(0U);
        node136->setAnimation("Idle");
        node136->setParameter("");
        node136->setValue(false);
        CALL_REGISTER_SKILL_NODE(10353, 136, node136)
    }
    if (noInit == true) {
        return node136;
    }
    return node136;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10353, 137) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_Delay::TRIGGER_DONE, 140, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(10353, 137) {
    auto node137 = GET_SKILL_NODE(137, PhaseNode_Delay);
    if (node137 == nullptr) {
        node137 = new PhaseNode_Delay(137, phase);
        node137->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(10353, 137, node137)
    }
    if (noInit == true) {
        return node137;
    }
    return node137;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(10353, 140) {
}

REGISTER_CREATE_SKILL_NODE(10353, 140) {
    auto node140 = GET_SKILL_NODE(140, PhaseNode_SetBool);
    if (node140 == nullptr) {
        node140 = new PhaseNode_SetBool(140, phase);
        node140->setName("InterruptAnimat");
        node140->setValue(true);
        CALL_REGISTER_SKILL_NODE(10353, 140, node140)
    }
    if (noInit == true) {
        return node140;
    }
    return node140;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10353, 141) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StartPreInput>(PhaseNode_RaiseEvent::TRIGGER_DONE, 133, PhaseNode_StartPreInput::FUNC_DO, &PhaseNode_StartPreInput::Do);
}

REGISTER_CREATE_SKILL_NODE(10353, 141) {
    auto node141 = GET_SKILL_NODE(141, PhaseNode_RaiseEvent);
    if (node141 == nullptr) {
        node141 = new PhaseNode_RaiseEvent(141, phase);
        node141->setEvent("Dead_001");
        node141->setTarget(0U);
        node141->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node141->setTypeParams(0, 0);
        node141->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10353, 141, node141)
    }
    if (noInit == true) {
        return node141;
    }
    return node141;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10353, 142) {
}

REGISTER_CREATE_SKILL_NODE(10353, 142) {
    auto node142 = GET_SKILL_NODE(142, PhaseNode_Detect);
    if (node142 == nullptr) {
        node142 = new PhaseNode_Detect(142, phase);
        node142->setSelf(0U);
        node142->setEvent("Dead_001");
        node142->setType(PhaseNode_Detect::Detect_Type::Actor_Dead);
        node142->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10353, 142, node142)
    }
    if (noInit == true) {
        return node142;
    }
    return node142;
}

//--------------------------------------------------------------------------------
// SkillCreator_10353
//
class SkillCreator_10353 : public SkillCreator {
public:
    SkillCreator_10353() {}
    virtual ~SkillCreator_10353() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_10353

//--------------------------------------------------------------------------------
// SkillPhase_10353
//
class SkillPhase_10353 : public SkillPhase {
public:
    SkillPhase_10353(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_10353() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(10353, 4) // StartPhase
        CASE_CREATE_SKILL_NODE(10353, 7) // AddSkillBuff
        CASE_CREATE_SKILL_NODE(10353, 9) // Disable
        CASE_CREATE_SKILL_NODE(10353, 13) // Delay
        CASE_CREATE_SKILL_NODE(10353, 15) // Distance
        CASE_CREATE_SKILL_NODE(10353, 17) // GetLocation
        CASE_CREATE_SKILL_NODE(10353, 19) // GetInputLocation
        CASE_CREATE_SKILL_NODE(10353, 31) // GetLineRotation
        CASE_CREATE_SKILL_NODE(10353, 33) // FloatOperation
        CASE_CREATE_SKILL_NODE(10353, 35) // CompareFloat
        CASE_CREATE_SKILL_NODE(10353, 37) // GetLocation
        CASE_CREATE_SKILL_NODE(10353, 39) // SpawnCollider
        CASE_CREATE_SKILL_NODE(10353, 41) // AttachTo
        CASE_CREATE_SKILL_NODE(10353, 43) // MoveNewPene
        CASE_CREATE_SKILL_NODE(10353, 45) // DestroyCollider
        CASE_CREATE_SKILL_NODE(10353, 51) // StopEffect
        CASE_CREATE_SKILL_NODE(10353, 53) // Delay
        CASE_CREATE_SKILL_NODE(10353, 55) // EndPhase
        CASE_CREATE_SKILL_NODE(10353, 57) // AreaCollisionNewPene
        CASE_CREATE_SKILL_NODE(10353, 59) // LineCheckNewPene
        CASE_CREATE_SKILL_NODE(10353, 63) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(10353, 64) // AreaCollisionNewPene
        CASE_CREATE_SKILL_NODE(10353, 65) // LineCheckNewPene
        CASE_CREATE_SKILL_NODE(10353, 67) // AreaCollisionNewPene
        CASE_CREATE_SKILL_NODE(10353, 68) // LineCheckNewPene
        CASE_CREATE_SKILL_NODE(10353, 69) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(10353, 84) // Delay
        CASE_CREATE_SKILL_NODE(10353, 85) // Delay
        CASE_CREATE_SKILL_NODE(10353, 86) // Delay
        CASE_CREATE_SKILL_NODE(10353, 88) // PlayEffect
        CASE_CREATE_SKILL_NODE(10353, 89) // PlayEffect
        CASE_CREATE_SKILL_NODE(10353, 90) // PlayEffect
        CASE_CREATE_SKILL_NODE(10353, 93) // GetUInt64sValue
        CASE_CREATE_SKILL_NODE(10353, 96) // GetUInt64sValue
        CASE_CREATE_SKILL_NODE(10353, 97) // GetUInt64sValue
        CASE_CREATE_SKILL_NODE(10353, 99) // If
        CASE_CREATE_SKILL_NODE(10353, 102) // If
        CASE_CREATE_SKILL_NODE(10353, 103) // If
        CASE_CREATE_SKILL_NODE(10353, 105) // FindSkillBuff
        CASE_CREATE_SKILL_NODE(10353, 106) // FindSkillBuff
        CASE_CREATE_SKILL_NODE(10353, 107) // FindSkillBuff
        CASE_CREATE_SKILL_NODE(10353, 109) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(10353, 113) // AddSkillBuff
        CASE_CREATE_SKILL_NODE(10353, 114) // AddSkillBuff
        CASE_CREATE_SKILL_NODE(10353, 115) // AddSkillBuff
        CASE_CREATE_SKILL_NODE(10353, 119) // OffsetCalculate
        CASE_CREATE_SKILL_NODE(10353, 121) // AddSkillBuff
        CASE_CREATE_SKILL_NODE(10353, 123) // RemoveSkillBuff
        CASE_CREATE_SKILL_NODE(10353, 124) // ResetCD
        CASE_CREATE_SKILL_NODE(10353, 125) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10353, 126) // PlaySound
        CASE_CREATE_SKILL_NODE(10353, 127) // GetActorAttribute
        CASE_CREATE_SKILL_NODE(10353, 129) // Detect
        CASE_CREATE_SKILL_NODE(10353, 130) // SwitchToInt
        CASE_CREATE_SKILL_NODE(10353, 132) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10353, 133) // StartPreInput
        CASE_CREATE_SKILL_NODE(10353, 134) // If
        CASE_CREATE_SKILL_NODE(10353, 135) // IsInterruptType
        CASE_CREATE_SKILL_NODE(10353, 136) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10353, 137) // Delay
        CASE_CREATE_SKILL_NODE(10353, 140) // SetBool
        CASE_CREATE_SKILL_NODE(10353, 141) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10353, 142) // Detect
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_10353

SkillLogic* SkillCreator_10353::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //设置变量
    Variable_10353_a103539 = logic->getVariables().setVariable<int32_t>("a103539", 1);
    Variable_10353_InterruptAnimat = logic->getVariables().setVariable<bool>("InterruptAnimat");
    //创建阶段phase
    auto phase = new SkillPhase_10353(1, logic, 2);
    //设置phase执行器
    phase->setRunPhaseNode(1, 4);
    phase->setDetectPhaseNode(2, 129);
    phase->setDetectPhaseNode(2, 142);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_10353::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
