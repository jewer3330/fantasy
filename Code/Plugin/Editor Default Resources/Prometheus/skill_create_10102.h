#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

#include "skill_psnode_actorselect.h"
#include "skill_psnode_comparefloat.h"
#include "skill_psnode_compareint.h"
#include "skill_psnode_delay.h"
#include "skill_psnode_detect.h"
#include "skill_psnode_disable.h"
#include "skill_psnode_distance.h"
#include "skill_psnode_endphase.h"
#include "skill_psnode_getactorattribute.h"
#include "skill_psnode_getinputlocation.h"
#include "skill_psnode_getlinerotation.h"
#include "skill_psnode_getlocation.h"
#include "skill_psnode_getuint64svalue.h"
#include "skill_psnode_if.h"
#include "skill_psnode_isinterrupttype.h"
#include "skill_psnode_offsetcalculate.h"
#include "skill_psnode_playanimation.h"
#include "skill_psnode_playeffect.h"
#include "skill_psnode_playsound.h"
#include "skill_psnode_raiseevent.h"
#include "skill_psnode_resetcd.h"
#include "skill_psnode_setbool.h"
#include "skill_psnode_setint.h"
#include "skill_psnode_setrotation.h"
#include "skill_psnode_spawnprojectile.h"
#include "skill_psnode_startphase.h"
#include "skill_psnode_startpreinput.h"
#include "skill_psnode_switchtoint.h"
#include "skill_psnode_triggerupdate.h"
#include "skill_psnode_uint64ssize.h"

namespace pvp {

//变量声明
uint64_t Variable_10102_a101022 = 0;
uint64_t Variable_10102_InterruptAnimat = 0;
//--------------------------------------------------------------------------------
// StartPhase
//
REGISTER_REGISTER_SKILL_NODE(10102, 1) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_StartPhase::TRIGGER_START, 2, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10102, 1) {
    auto node1 = GET_SKILL_NODE(1, PhaseNode_StartPhase);
    if (node1 == nullptr) {
        node1 = new PhaseNode_StartPhase(1, phase);
        CALL_REGISTER_SKILL_NODE(10102, 1, node1)
    }
    if (noInit == true) {
        return node1;
    }
    return node1;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10102, 2) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_PlayAnimation::TRIGGER_DONE, 98, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_PlayAnimation::TRIGGER_DONE, 31, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10102, 2) {
    auto node2 = GET_SKILL_NODE(2, PhaseNode_PlayAnimation);
    if (node2 == nullptr) {
        node2 = new PhaseNode_PlayAnimation(2, phase);
        node2->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node2->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node2->setTarget(0U);
        node2->setAnimation("Skill2S1");
        node2->setParameter("");
        node2->setValue(false);
        CALL_REGISTER_SKILL_NODE(10102, 2, node2)
    }
    if (noInit == true) {
        return node2;
    }
    return node2;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(10102, 3) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_ResetCD::TRIGGER_DONE, 58, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_ResetCD::TRIGGER_DONE, 274, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10102, 3) {
    auto node3 = GET_SKILL_NODE(3, PhaseNode_ResetCD);
    if (node3 == nullptr) {
        node3 = new PhaseNode_ResetCD(3, phase);
        node3->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node3->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node3->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(10102, 3, node3)
    }
    if (noInit == true) {
        return node3;
    }
    return node3;
}
//--------------------------------------------------------------------------------
// ActorSelect
//
REGISTER_REGISTER_SKILL_NODE(10102, 7) {
    pnode->resizeTrigger(PhaseNode_ActorSelect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_UInt64sSize>(PhaseNode_ActorSelect::TRIGGER_DONE, 214, PhaseNode_UInt64sSize::FUNC_DO, &PhaseNode_UInt64sSize::Do);
}

REGISTER_CREATE_SKILL_NODE(10102, 7) {
    auto node7 = GET_SKILL_NODE(7, PhaseNode_ActorSelect);
    if (node7 == nullptr) {
        node7 = new PhaseNode_ActorSelect(7, phase);
        node7->setTarget(0U);
        node7->setConfigID(4011);
        CALL_REGISTER_SKILL_NODE(10102, 7, node7)
    }
    if (noInit == true) {
        return node7;
    }
    return node7;
}
//--------------------------------------------------------------------------------
// Disable
//
REGISTER_REGISTER_SKILL_NODE(10102, 23) {
    pnode->resizeTrigger(PhaseNode_Disable::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_Disable::TRIGGER_DONE, 3, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(10102, 23) {
    auto node23 = GET_SKILL_NODE(23, PhaseNode_Disable);
    if (node23 == nullptr) {
        node23 = new PhaseNode_Disable(23, phase);
        node23->setTarget(0U);
        node23->setMove(true);
        node23->setSkill(true);
        node23->setShoot(true);
        node23->setTime(.30f);
        node23->setRotate(true);
        CALL_REGISTER_SKILL_NODE(10102, 23, node23)
    }
    if (noInit == true) {
        return node23;
    }
    return node23;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10102, 31) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_PlaySound::TRIGGER_DONE, 33, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10102, 31) {
    auto node31 = GET_SKILL_NODE(31, PhaseNode_PlaySound);
    if (node31 == nullptr) {
        node31 = new PhaseNode_PlaySound(31, phase);
        node31->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node31->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node31->setSoundID("SE_Hero103_Skill_B");
        node31->setTarget(0U);
        node31->setUsePos(false);
        node31->setPosX(.00f);
        node31->setPosY(.00f);
        node31->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10102, 31, node31)
    }
    if (noInit == true) {
        return node31;
    }
    return node31;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10102, 33) {
}

REGISTER_CREATE_SKILL_NODE(10102, 33) {
    auto node33 = GET_SKILL_NODE(33, PhaseNode_PlaySound);
    if (node33 == nullptr) {
        node33 = new PhaseNode_PlaySound(33, phase);
        node33->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node33->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node33->setSoundID("VO_Hero103_Skill_B");
        node33->setTarget(0U);
        node33->setUsePos(false);
        node33->setPosX(.00f);
        node33->setPosY(.00f);
        node33->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10102, 33, node33)
    }
    if (noInit == true) {
        return node33;
    }
    return node33;
}
//--------------------------------------------------------------------------------
// TriggerUpdate
//
REGISTER_REGISTER_SKILL_NODE(10102, 44) {
}

REGISTER_CREATE_SKILL_NODE(10102, 44) {
    auto node44 = GET_SKILL_NODE(44, PhaseNode_TriggerUpdate);
    if (node44 == nullptr) {
        node44 = new PhaseNode_TriggerUpdate(44, phase);
        CALL_REGISTER_SKILL_NODE(10102, 44, node44)
    }
    if (noInit == true) {
        return node44;
    }
    return node44;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10102, 53) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ActorSelect>(PhaseNode_Delay::TRIGGER_DONE, 7, PhaseNode_ActorSelect::FUNC_DO, &PhaseNode_ActorSelect::Do);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_Delay::TRIGGER_DONE, 229, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(10102, 53) {
    auto node53 = GET_SKILL_NODE(53, PhaseNode_Delay);
    if (node53 == nullptr) {
        node53 = new PhaseNode_Delay(53, phase);
        node53->setTime(.20f);
        CALL_REGISTER_SKILL_NODE(10102, 53, node53)
    }
    if (noInit == true) {
        return node53;
    }
    return node53;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(10102, 58) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetInputLocation>(PhaseNode_GetLocation::TRIGGER_DONE, 74, PhaseNode_GetInputLocation::FUNC_DO, &PhaseNode_GetInputLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(10102, 58) {
    auto node58 = GET_SKILL_NODE(58, PhaseNode_GetLocation);
    if (node58 == nullptr) {
        node58 = new PhaseNode_GetLocation(58, phase);
        node58->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node58->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(10102, 58, node58)
    }
    if (noInit == true) {
        return node58;
    }
    return node58;
}
//--------------------------------------------------------------------------------
// GetInputLocation
//
REGISTER_REGISTER_SKILL_NODE(10102, 74) {
    pnode->resizeTrigger(PhaseNode_GetInputLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLineRotation>(PhaseNode_GetInputLocation::TRIGGER_DONE, 104, PhaseNode_GetLineRotation::FUNC_DO, &PhaseNode_GetLineRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(10102, 74) {
    auto node74 = GET_SKILL_NODE(74, PhaseNode_GetInputLocation);
    if (node74 == nullptr) {
        node74 = new PhaseNode_GetInputLocation(74, phase);
        node74->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        CALL_REGISTER_SKILL_NODE(10102, 74, node74)
    }
    if (noInit == true) {
        return node74;
    }
    return node74;
}
//--------------------------------------------------------------------------------
// GetActorAttribute
//
REGISTER_REGISTER_SKILL_NODE(10102, 98) {
    pnode->resizeTrigger(PhaseNode_GetActorAttribute::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Disable>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 23, PhaseNode_Disable::FUNC_DO, &PhaseNode_Disable::Do);
}

REGISTER_CREATE_SKILL_NODE(10102, 98) {
    auto node98 = GET_SKILL_NODE(98, PhaseNode_GetActorAttribute);
    if (node98 == nullptr) {
        node98 = new PhaseNode_GetActorAttribute(98, phase);
        node98->setTarget(0U);
        node98->setType({});
        CALL_REGISTER_SKILL_NODE(10102, 98, node98)
    }
    if (noInit == true) {
        return node98;
    }
    return node98;
}
//--------------------------------------------------------------------------------
// GetLineRotation
//
REGISTER_REGISTER_SKILL_NODE(10102, 104) {
    pnode->resizeTrigger(PhaseNode_GetLineRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_OffsetCalculate>(PhaseNode_GetLineRotation::TRIGGER_DONE, 267, PhaseNode_OffsetCalculate::FUNC_DO, &PhaseNode_OffsetCalculate::Do);
}

REGISTER_CREATE_SKILL_NODE(10102, 104) {
    auto node104 = GET_SKILL_NODE(104, PhaseNode_GetLineRotation);
    if (node104 == nullptr) {
        node104 = new PhaseNode_GetLineRotation(104, phase);
        CALL_REGISTER_SKILL_NODE(10102, 104, node104)
    }
    if (noInit == true) {
        return node104;
    }
    auto node58 = GET_SKILL_NODE(58, PhaseNode_GetLocation);
    auto node74 = GET_SKILL_NODE(74, PhaseNode_GetInputLocation);
    if (node58 != nullptr) node104->setStartX(node58->getX());
    if (node58 != nullptr) node104->setStartY(node58->getY());
    if (node74 != nullptr) node104->setEndX(node74->getX());
    if (node74 != nullptr) node104->setEndY(node74->getY());
    return node104;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(10102, 106) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Distance>(PhaseNode_GetLocation::TRIGGER_DONE, 156, PhaseNode_Distance::FUNC_DO, &PhaseNode_Distance::Do);
}

REGISTER_CREATE_SKILL_NODE(10102, 106) {
    auto node106 = GET_SKILL_NODE(106, PhaseNode_GetLocation);
    if (node106 == nullptr) {
        node106 = new PhaseNode_GetLocation(106, phase);
        node106->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        CALL_REGISTER_SKILL_NODE(10102, 106, node106)
    }
    if (noInit == true) {
        return node106;
    }
    auto node113 = GET_SKILL_NODE(113, PhaseNode_GetUInt64sValue);
    if (node113 != nullptr) node106->setTarget(node113->getValue());
    return node106;
}
//--------------------------------------------------------------------------------
// GetUInt64sValue
//
REGISTER_REGISTER_SKILL_NODE(10102, 113) {
    pnode->resizeTrigger(PhaseNode_GetUInt64sValue::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Disable>(PhaseNode_GetUInt64sValue::TRIGGER_DONE, 176, PhaseNode_Disable::FUNC_DO, &PhaseNode_Disable::Do);
}

REGISTER_CREATE_SKILL_NODE(10102, 113) {
    auto node113 = GET_SKILL_NODE(113, PhaseNode_GetUInt64sValue);
    if (node113 == nullptr) {
        node113 = new PhaseNode_GetUInt64sValue(113, phase);
        node113->setIndex(0);
        CALL_REGISTER_SKILL_NODE(10102, 113, node113)
    }
    if (noInit == true) {
        return node113;
    }
    auto node7 = GET_SKILL_NODE(7, PhaseNode_ActorSelect);
    if (node7 != nullptr) node113->setArr(node7->getTargets());
    return node113;
}
//--------------------------------------------------------------------------------
// GetLineRotation
//
REGISTER_REGISTER_SKILL_NODE(10102, 118) {
    pnode->resizeTrigger(PhaseNode_GetLineRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_GetLineRotation::TRIGGER_DONE, 149, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(10102, 118) {
    auto node118 = GET_SKILL_NODE(118, PhaseNode_GetLineRotation);
    if (node118 == nullptr) {
        node118 = new PhaseNode_GetLineRotation(118, phase);
        CALL_REGISTER_SKILL_NODE(10102, 118, node118)
    }
    if (noInit == true) {
        return node118;
    }
    auto node106 = GET_SKILL_NODE(106, PhaseNode_GetLocation);
    auto node74 = GET_SKILL_NODE(74, PhaseNode_GetInputLocation);
    if (node106 != nullptr) node118->setStartX(node106->getX());
    if (node106 != nullptr) node118->setStartY(node106->getY());
    if (node74 != nullptr) node118->setEndX(node74->getX());
    if (node74 != nullptr) node118->setEndY(node74->getY());
    return node118;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(10102, 149) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetRotation>(PhaseNode_CompareFloat::TRIGGER_LESS, 174, PhaseNode_SetRotation::FUNC_DO, &PhaseNode_SetRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(10102, 149) {
    auto node149 = GET_SKILL_NODE(149, PhaseNode_CompareFloat);
    if (node149 == nullptr) {
        node149 = new PhaseNode_CompareFloat(149, phase);
        node149->setB(18.00f);
        CALL_REGISTER_SKILL_NODE(10102, 149, node149)
    }
    if (noInit == true) {
        return node149;
    }
    auto node156 = GET_SKILL_NODE(156, PhaseNode_Distance);
    if (node156 != nullptr) node149->setA(node156->getResult());
    return node149;
}
//--------------------------------------------------------------------------------
// Distance
//
REGISTER_REGISTER_SKILL_NODE(10102, 156) {
    pnode->resizeTrigger(PhaseNode_Distance::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLineRotation>(PhaseNode_Distance::TRIGGER_DONE, 118, PhaseNode_GetLineRotation::FUNC_DO, &PhaseNode_GetLineRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(10102, 156) {
    auto node156 = GET_SKILL_NODE(156, PhaseNode_Distance);
    if (node156 == nullptr) {
        node156 = new PhaseNode_Distance(156, phase);
        CALL_REGISTER_SKILL_NODE(10102, 156, node156)
    }
    if (noInit == true) {
        return node156;
    }
    auto node58 = GET_SKILL_NODE(58, PhaseNode_GetLocation);
    auto node106 = GET_SKILL_NODE(106, PhaseNode_GetLocation);
    if (node58 != nullptr) node156->setAX(node58->getX());
    if (node58 != nullptr) node156->setAY(node58->getY());
    if (node106 != nullptr) node156->setBX(node106->getX());
    if (node106 != nullptr) node156->setBY(node106->getY());
    return node156;
}
//--------------------------------------------------------------------------------
// SetRotation
//
REGISTER_REGISTER_SKILL_NODE(10102, 174) {
    pnode->resizeTrigger(PhaseNode_SetRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_OffsetCalculate>(PhaseNode_SetRotation::TRIGGER_DONE, 269, PhaseNode_OffsetCalculate::FUNC_DO, &PhaseNode_OffsetCalculate::Do);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_SetRotation::TRIGGER_DONE, 231, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(10102, 174) {
    auto node174 = GET_SKILL_NODE(174, PhaseNode_SetRotation);
    if (node174 == nullptr) {
        node174 = new PhaseNode_SetRotation(174, phase);
        node174->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node174->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10102, 174, node174)
    }
    if (noInit == true) {
        return node174;
    }
    auto node113 = GET_SKILL_NODE(113, PhaseNode_GetUInt64sValue);
    auto node118 = GET_SKILL_NODE(118, PhaseNode_GetLineRotation);
    if (node113 != nullptr) node174->setTarget(node113->getValue());
    if (node118 != nullptr) node174->setAngle(node118->getRotation());
    return node174;
}
//--------------------------------------------------------------------------------
// Disable
//
REGISTER_REGISTER_SKILL_NODE(10102, 176) {
    pnode->resizeTrigger(PhaseNode_Disable::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_Disable::TRIGGER_DONE, 106, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(10102, 176) {
    auto node176 = GET_SKILL_NODE(176, PhaseNode_Disable);
    if (node176 == nullptr) {
        node176 = new PhaseNode_Disable(176, phase);
        node176->setMove(true);
        node176->setSkill(true);
        node176->setShoot(true);
        node176->setTime(.50f);
        node176->setRotate(false);
        CALL_REGISTER_SKILL_NODE(10102, 176, node176)
    }
    if (noInit == true) {
        return node176;
    }
    auto node113 = GET_SKILL_NODE(113, PhaseNode_GetUInt64sValue);
    if (node113 != nullptr) node176->setTarget(node113->getValue());
    return node176;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10102, 189) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_Delay::TRIGGER_DONE, 191, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(10102, 189) {
    auto node189 = GET_SKILL_NODE(189, PhaseNode_Delay);
    if (node189 == nullptr) {
        node189 = new PhaseNode_Delay(189, phase);
        node189->setTime(1.00f);
        CALL_REGISTER_SKILL_NODE(10102, 189, node189)
    }
    if (noInit == true) {
        return node189;
    }
    return node189;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(10102, 191) {
}

REGISTER_CREATE_SKILL_NODE(10102, 191) {
    auto node191 = GET_SKILL_NODE(191, PhaseNode_EndPhase);
    if (node191 == nullptr) {
        node191 = new PhaseNode_EndPhase(191, phase);
        node191->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node191->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10102, 191, node191)
    }
    if (noInit == true) {
        return node191;
    }
    return node191;
}
//--------------------------------------------------------------------------------
// UInt64sSize
//
REGISTER_REGISTER_SKILL_NODE(10102, 214) {
    pnode->resizeTrigger(PhaseNode_UInt64sSize::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareInt>(PhaseNode_UInt64sSize::TRIGGER_DONE, 216, PhaseNode_CompareInt::FUNC_COMPARE, &PhaseNode_CompareInt::Compare);
}

REGISTER_CREATE_SKILL_NODE(10102, 214) {
    auto node214 = GET_SKILL_NODE(214, PhaseNode_UInt64sSize);
    if (node214 == nullptr) {
        node214 = new PhaseNode_UInt64sSize(214, phase);
        CALL_REGISTER_SKILL_NODE(10102, 214, node214)
    }
    if (noInit == true) {
        return node214;
    }
    auto node7 = GET_SKILL_NODE(7, PhaseNode_ActorSelect);
    if (node7 != nullptr) node214->setArr(node7->getTargets());
    return node214;
}
//--------------------------------------------------------------------------------
// CompareInt
//
REGISTER_REGISTER_SKILL_NODE(10102, 216) {
    pnode->resizeTrigger(PhaseNode_CompareInt::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetUInt64sValue>(PhaseNode_CompareInt::TRIGGER_GREATER, 113, PhaseNode_GetUInt64sValue::FUNC_DO, &PhaseNode_GetUInt64sValue::Do);
}

REGISTER_CREATE_SKILL_NODE(10102, 216) {
    auto node216 = GET_SKILL_NODE(216, PhaseNode_CompareInt);
    if (node216 == nullptr) {
        node216 = new PhaseNode_CompareInt(216, phase);
        node216->setB(0);
        CALL_REGISTER_SKILL_NODE(10102, 216, node216)
    }
    if (noInit == true) {
        return node216;
    }
    auto node214 = GET_SKILL_NODE(214, PhaseNode_UInt64sSize);
    if (node214 != nullptr) node216->setA(node214->getSize());
    return node216;
}
//--------------------------------------------------------------------------------
// SetInt
//
REGISTER_REGISTER_SKILL_NODE(10102, 219) {
}

REGISTER_CREATE_SKILL_NODE(10102, 219) {
    auto node219 = GET_SKILL_NODE(219, PhaseNode_SetInt);
    if (node219 == nullptr) {
        node219 = new PhaseNode_SetInt(219, phase);
        node219->setName("a101022");
        node219->setValue(2);
        CALL_REGISTER_SKILL_NODE(10102, 219, node219)
    }
    if (noInit == true) {
        return node219;
    }
    return node219;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(10102, 229) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_PlayEffect::TRIGGER_DONE, 254, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10102, 229) {
    auto node229 = GET_SKILL_NODE(229, PhaseNode_PlayEffect);
    if (node229 == nullptr) {
        node229 = new PhaseNode_PlayEffect(229, phase);
        node229->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node229->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node229->setEffectID(101032);
        node229->setChangeColor(true);
        node229->setType(PhaseNode_PlayEffect::PlayEffect_Type::WithTarget);
        node229->getVars().reserve(5);
        node229->getVars().setVariable<uint64_t>(0, 0U);
        node229->getVars().setVariable<std::string>(1, "Muzzle");
        node229->getVars().setVariable<float>(2, .00f);
        node229->getVars().setVariable<float>(3, .00f);
        node229->getVars().setVariable<float>(4, .00f);
        node229->setRotation(.00f);
        node229->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(10102, 229, node229)
    }
    if (noInit == true) {
        return node229;
    }
    return node229;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(10102, 231) {
}

REGISTER_CREATE_SKILL_NODE(10102, 231) {
    auto node231 = GET_SKILL_NODE(231, PhaseNode_PlayEffect);
    if (node231 == nullptr) {
        node231 = new PhaseNode_PlayEffect(231, phase);
        node231->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node231->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node231->setEffectID(101034);
        node231->setChangeColor(true);
        node231->setType(PhaseNode_PlayEffect::PlayEffect_Type::WithTarget);
        node231->getVars().reserve(5);
        node231->getVars().setVariable<uint64_t>(0, 0U);
        node231->getVars().setVariable<std::string>(1, "Effect");
        node231->getVars().setVariable<float>(2, .00f);
        node231->getVars().setVariable<float>(3, .00f);
        node231->getVars().setVariable<float>(4, .00f);
        node231->setRotation(.00f);
        node231->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(10102, 231, node231)
    }
    if (noInit == true) {
        return node231;
    }
    auto node113 = GET_SKILL_NODE(113, PhaseNode_GetUInt64sValue);
    if (node113 != nullptr) node231->getVars().setVariable<uint64_t>(0, node113->getValue());
    return node231;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10102, 254) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnProjectile>(PhaseNode_PlaySound::TRIGGER_DONE, 263, PhaseNode_SpawnProjectile::FUNC_DO, &PhaseNode_SpawnProjectile::Do);
}

REGISTER_CREATE_SKILL_NODE(10102, 254) {
    auto node254 = GET_SKILL_NODE(254, PhaseNode_PlaySound);
    if (node254 == nullptr) {
        node254 = new PhaseNode_PlaySound(254, phase);
        node254->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node254->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node254->setSoundID("SE_Hero103_Skill_B_P1");
        node254->setTarget(0U);
        node254->setUsePos(false);
        node254->setPosX(.00f);
        node254->setPosY(.00f);
        node254->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10102, 254, node254)
    }
    if (noInit == true) {
        return node254;
    }
    return node254;
}
//--------------------------------------------------------------------------------
// SpawnProjectile
//
REGISTER_REGISTER_SKILL_NODE(10102, 263) {
    pnode->resizeTrigger(PhaseNode_SpawnProjectile::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_SpawnProjectile::TRIGGER_DONE, 189, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_SetInt>(PhaseNode_SpawnProjectile::TRIGGER_DONE, 219, PhaseNode_SetInt::FUNC_SET, &PhaseNode_SetInt::Set);
}

REGISTER_CREATE_SKILL_NODE(10102, 263) {
    auto node263 = GET_SKILL_NODE(263, PhaseNode_SpawnProjectile);
    if (node263 == nullptr) {
        node263 = new PhaseNode_SpawnProjectile(263, phase);
        node263->setDataId(55101);
        node263->setEndPosZ(.00f);
        node263->setMaxCount(0);
        CALL_REGISTER_SKILL_NODE(10102, 263, node263)
    }
    if (noInit == true) {
        return node263;
    }
    auto node267 = GET_SKILL_NODE(267, PhaseNode_OffsetCalculate);
    auto node74 = GET_SKILL_NODE(74, PhaseNode_GetInputLocation);
    auto node104 = GET_SKILL_NODE(104, PhaseNode_GetLineRotation);
    if (node267 != nullptr) node263->setPosX(node267->getOutPosX());
    if (node267 != nullptr) node263->setPosY(node267->getOutPosY());
    if (node267 != nullptr) node263->setPosZ(node267->getOutPosZ());
    if (node74 != nullptr) node263->setEndPosX(node74->getX());
    if (node74 != nullptr) node263->setEndPosY(node74->getY());
    if (node104 != nullptr) node263->setRotation(node104->getRotation());
    return node263;
}
//--------------------------------------------------------------------------------
// SpawnProjectile
//
REGISTER_REGISTER_SKILL_NODE(10102, 265) {
}

REGISTER_CREATE_SKILL_NODE(10102, 265) {
    auto node265 = GET_SKILL_NODE(265, PhaseNode_SpawnProjectile);
    if (node265 == nullptr) {
        node265 = new PhaseNode_SpawnProjectile(265, phase);
        node265->setDataId(55101);
        node265->setMaxCount(0);
        CALL_REGISTER_SKILL_NODE(10102, 265, node265)
    }
    if (noInit == true) {
        return node265;
    }
    auto node269 = GET_SKILL_NODE(269, PhaseNode_OffsetCalculate);
    auto node74 = GET_SKILL_NODE(74, PhaseNode_GetInputLocation);
    if (node269 != nullptr) node265->setPosX(node269->getOutPosX());
    if (node269 != nullptr) node265->setPosY(node269->getOutPosY());
    if (node269 != nullptr) node265->setPosZ(node269->getOutPosZ());
    if (node74 != nullptr) node265->setEndPosX(node74->getX());
    if (node74 != nullptr) node265->setEndPosY(node74->getY());
    if (node269 != nullptr) node265->setEndPosZ(node269->getOutPosZ());
    if (node269 != nullptr) node265->setRotation(node269->getOutRotation());
    return node265;
}
//--------------------------------------------------------------------------------
// OffsetCalculate
//
REGISTER_REGISTER_SKILL_NODE(10102, 267) {
    pnode->resizeTrigger(PhaseNode_OffsetCalculate::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 53, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10102, 267) {
    auto node267 = GET_SKILL_NODE(267, PhaseNode_OffsetCalculate);
    if (node267 == nullptr) {
        node267 = new PhaseNode_OffsetCalculate(267, phase);
        node267->setPosZ(.00f);
        node267->setOffsetX(.00f);
        node267->setOffsetY(.30f);
        node267->setOffsetZ(.90f);
        node267->setRotOffset(.00f);
        CALL_REGISTER_SKILL_NODE(10102, 267, node267)
    }
    if (noInit == true) {
        return node267;
    }
    auto node58 = GET_SKILL_NODE(58, PhaseNode_GetLocation);
    auto node104 = GET_SKILL_NODE(104, PhaseNode_GetLineRotation);
    if (node58 != nullptr) node267->setPosX(node58->getX());
    if (node58 != nullptr) node267->setPosY(node58->getY());
    if (node104 != nullptr) node267->setRotation(node104->getRotation());
    return node267;
}
//--------------------------------------------------------------------------------
// OffsetCalculate
//
REGISTER_REGISTER_SKILL_NODE(10102, 269) {
    pnode->resizeTrigger(PhaseNode_OffsetCalculate::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnProjectile>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 265, PhaseNode_SpawnProjectile::FUNC_DO, &PhaseNode_SpawnProjectile::Do);
}

REGISTER_CREATE_SKILL_NODE(10102, 269) {
    auto node269 = GET_SKILL_NODE(269, PhaseNode_OffsetCalculate);
    if (node269 == nullptr) {
        node269 = new PhaseNode_OffsetCalculate(269, phase);
        node269->setPosZ(.00f);
        node269->setOffsetX(.00f);
        node269->setOffsetY(1.00f);
        node269->setOffsetZ(.60f);
        node269->setRotOffset(.00f);
        CALL_REGISTER_SKILL_NODE(10102, 269, node269)
    }
    if (noInit == true) {
        return node269;
    }
    auto node106 = GET_SKILL_NODE(106, PhaseNode_GetLocation);
    auto node118 = GET_SKILL_NODE(118, PhaseNode_GetLineRotation);
    if (node106 != nullptr) node269->setPosX(node106->getX());
    if (node106 != nullptr) node269->setPosY(node106->getY());
    if (node118 != nullptr) node269->setRotation(node118->getRotation());
    return node269;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10102, 271) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_IsInterruptType>(PhaseNode_Detect::TRIGGER_ON, 277, PhaseNode_IsInterruptType::FUNC_DO, &PhaseNode_IsInterruptType::Do);
}

REGISTER_CREATE_SKILL_NODE(10102, 271) {
    auto node271 = GET_SKILL_NODE(271, PhaseNode_Detect);
    if (node271 == nullptr) {
        node271 = new PhaseNode_Detect(271, phase);
        node271->setSelf(0U);
        node271->setEvent("daduan_001");
        node271->setType(PhaseNode_Detect::Detect_Type::Interrupt_Skill);
        node271->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10102, 271, node271)
    }
    if (noInit == true) {
        return node271;
    }
    return node271;
}
//--------------------------------------------------------------------------------
// SwitchToInt
//
REGISTER_REGISTER_SKILL_NODE(10102, 272) {
    pnode->resizeTrigger(4);
    pnode->regTrigger<PhaseNode_EndPhase>(1, 191, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(10102, 272) {
    auto node272 = GET_SKILL_NODE(272, PhaseNode_SwitchToInt);
    if (node272 == nullptr) {
        node272 = new PhaseNode_SwitchToInt(272, phase);
        CALL_REGISTER_SKILL_NODE(10102, 272, node272)
    }
    if (noInit == true) {
        return node272;
    }
    auto variables = node272->getVariables();
    if (variables != nullptr) {
        node272->setSelection(variables->getVariable<int32_t>(Variable_10102_a101022));
    }
    return node272;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10102, 274) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_RaiseEvent::TRIGGER_DONE, 283, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10102, 274) {
    auto node274 = GET_SKILL_NODE(274, PhaseNode_RaiseEvent);
    if (node274 == nullptr) {
        node274 = new PhaseNode_RaiseEvent(274, phase);
        node274->setEvent("daduan_001");
        node274->setTarget(0U);
        node274->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node274->setTypeParams(0, 0);
        node274->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10102, 274, node274)
    }
    if (noInit == true) {
        return node274;
    }
    return node274;
}
//--------------------------------------------------------------------------------
// StartPreInput
//
REGISTER_REGISTER_SKILL_NODE(10102, 275) {
    pnode->resizeTrigger(PhaseNode_StartPreInput::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_StartPreInput::TRIGGER_DONE, 279, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10102, 275) {
    auto node275 = GET_SKILL_NODE(275, PhaseNode_StartPreInput);
    if (node275 == nullptr) {
        node275 = new PhaseNode_StartPreInput(275, phase);
        node275->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node275->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node275->setDelayTime(.00f);
        CALL_REGISTER_SKILL_NODE(10102, 275, node275)
    }
    if (noInit == true) {
        return node275;
    }
    return node275;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(10102, 276) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_If::TRIGGER_TRUE, 278, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10102, 276) {
    auto node276 = GET_SKILL_NODE(276, PhaseNode_If);
    if (node276 == nullptr) {
        node276 = new PhaseNode_If(276, phase);
        CALL_REGISTER_SKILL_NODE(10102, 276, node276)
    }
    if (noInit == true) {
        return node276;
    }
    auto variables = node276->getVariables();
    if (variables != nullptr) {
        node276->setCondition(variables->getVariable<bool>(Variable_10102_InterruptAnimat));
    }
    return node276;
}
//--------------------------------------------------------------------------------
// IsInterruptType
//
REGISTER_REGISTER_SKILL_NODE(10102, 277) {
    pnode->resizeTrigger(PhaseNode_IsInterruptType::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SwitchToInt>(PhaseNode_IsInterruptType::TRIGGER_BUFF, 272, PhaseNode_SwitchToInt::FUNC_SWITCH, &PhaseNode_SwitchToInt::Switch);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_POSCHANGE, 276, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTAIM, 276, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTFIRE, 276, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTRELOAD, 276, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_USESKILL, 276, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(10102, 277) {
    auto node277 = GET_SKILL_NODE(277, PhaseNode_IsInterruptType);
    if (node277 == nullptr) {
        node277 = new PhaseNode_IsInterruptType(277, phase);
        node277->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node277->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10102, 277, node277)
    }
    if (noInit == true) {
        return node277;
    }
    auto node271 = GET_SKILL_NODE(271, PhaseNode_Detect);
    if (node271 != nullptr) node277->setType(node271->getVars().getVariable<int32_t>(2));
    return node277;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10102, 278) {
}

REGISTER_CREATE_SKILL_NODE(10102, 278) {
    auto node278 = GET_SKILL_NODE(278, PhaseNode_PlayAnimation);
    if (node278 == nullptr) {
        node278 = new PhaseNode_PlayAnimation(278, phase);
        node278->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node278->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node278->setTarget(0U);
        node278->setAnimation("Idle");
        node278->setParameter("");
        node278->setValue(false);
        CALL_REGISTER_SKILL_NODE(10102, 278, node278)
    }
    if (noInit == true) {
        return node278;
    }
    return node278;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10102, 279) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_Delay::TRIGGER_DONE, 282, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(10102, 279) {
    auto node279 = GET_SKILL_NODE(279, PhaseNode_Delay);
    if (node279 == nullptr) {
        node279 = new PhaseNode_Delay(279, phase);
        node279->setTime(.20f);
        CALL_REGISTER_SKILL_NODE(10102, 279, node279)
    }
    if (noInit == true) {
        return node279;
    }
    return node279;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(10102, 282) {
}

REGISTER_CREATE_SKILL_NODE(10102, 282) {
    auto node282 = GET_SKILL_NODE(282, PhaseNode_SetBool);
    if (node282 == nullptr) {
        node282 = new PhaseNode_SetBool(282, phase);
        node282->setName("InterruptAnimat");
        node282->setValue(true);
        CALL_REGISTER_SKILL_NODE(10102, 282, node282)
    }
    if (noInit == true) {
        return node282;
    }
    return node282;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10102, 283) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StartPreInput>(PhaseNode_RaiseEvent::TRIGGER_DONE, 275, PhaseNode_StartPreInput::FUNC_DO, &PhaseNode_StartPreInput::Do);
}

REGISTER_CREATE_SKILL_NODE(10102, 283) {
    auto node283 = GET_SKILL_NODE(283, PhaseNode_RaiseEvent);
    if (node283 == nullptr) {
        node283 = new PhaseNode_RaiseEvent(283, phase);
        node283->setEvent("Dead_001");
        node283->setTarget(0U);
        node283->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node283->setTypeParams(0, 0);
        node283->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10102, 283, node283)
    }
    if (noInit == true) {
        return node283;
    }
    return node283;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10102, 284) {
}

REGISTER_CREATE_SKILL_NODE(10102, 284) {
    auto node284 = GET_SKILL_NODE(284, PhaseNode_Detect);
    if (node284 == nullptr) {
        node284 = new PhaseNode_Detect(284, phase);
        node284->setSelf(0U);
        node284->setEvent("Dead_001");
        node284->setType(PhaseNode_Detect::Detect_Type::Actor_Dead);
        node284->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10102, 284, node284)
    }
    if (noInit == true) {
        return node284;
    }
    return node284;
}

//--------------------------------------------------------------------------------
// SkillCreator_10102
//
class SkillCreator_10102 : public SkillCreator {
public:
    SkillCreator_10102() {}
    virtual ~SkillCreator_10102() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_10102

//--------------------------------------------------------------------------------
// SkillPhase_10102
//
class SkillPhase_10102 : public SkillPhase {
public:
    SkillPhase_10102(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_10102() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(10102, 1) // StartPhase
        CASE_CREATE_SKILL_NODE(10102, 2) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10102, 3) // ResetCD
        CASE_CREATE_SKILL_NODE(10102, 7) // ActorSelect
        CASE_CREATE_SKILL_NODE(10102, 23) // Disable
        CASE_CREATE_SKILL_NODE(10102, 31) // PlaySound
        CASE_CREATE_SKILL_NODE(10102, 33) // PlaySound
        CASE_CREATE_SKILL_NODE(10102, 44) // TriggerUpdate
        CASE_CREATE_SKILL_NODE(10102, 53) // Delay
        CASE_CREATE_SKILL_NODE(10102, 58) // GetLocation
        CASE_CREATE_SKILL_NODE(10102, 74) // GetInputLocation
        CASE_CREATE_SKILL_NODE(10102, 98) // GetActorAttribute
        CASE_CREATE_SKILL_NODE(10102, 104) // GetLineRotation
        CASE_CREATE_SKILL_NODE(10102, 106) // GetLocation
        CASE_CREATE_SKILL_NODE(10102, 113) // GetUInt64sValue
        CASE_CREATE_SKILL_NODE(10102, 118) // GetLineRotation
        CASE_CREATE_SKILL_NODE(10102, 149) // CompareFloat
        CASE_CREATE_SKILL_NODE(10102, 156) // Distance
        CASE_CREATE_SKILL_NODE(10102, 174) // SetRotation
        CASE_CREATE_SKILL_NODE(10102, 176) // Disable
        CASE_CREATE_SKILL_NODE(10102, 189) // Delay
        CASE_CREATE_SKILL_NODE(10102, 191) // EndPhase
        CASE_CREATE_SKILL_NODE(10102, 214) // UInt64sSize
        CASE_CREATE_SKILL_NODE(10102, 216) // CompareInt
        CASE_CREATE_SKILL_NODE(10102, 219) // SetInt
        CASE_CREATE_SKILL_NODE(10102, 229) // PlayEffect
        CASE_CREATE_SKILL_NODE(10102, 231) // PlayEffect
        CASE_CREATE_SKILL_NODE(10102, 254) // PlaySound
        CASE_CREATE_SKILL_NODE(10102, 263) // SpawnProjectile
        CASE_CREATE_SKILL_NODE(10102, 265) // SpawnProjectile
        CASE_CREATE_SKILL_NODE(10102, 267) // OffsetCalculate
        CASE_CREATE_SKILL_NODE(10102, 269) // OffsetCalculate
        CASE_CREATE_SKILL_NODE(10102, 271) // Detect
        CASE_CREATE_SKILL_NODE(10102, 272) // SwitchToInt
        CASE_CREATE_SKILL_NODE(10102, 274) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10102, 275) // StartPreInput
        CASE_CREATE_SKILL_NODE(10102, 276) // If
        CASE_CREATE_SKILL_NODE(10102, 277) // IsInterruptType
        CASE_CREATE_SKILL_NODE(10102, 278) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10102, 279) // Delay
        CASE_CREATE_SKILL_NODE(10102, 282) // SetBool
        CASE_CREATE_SKILL_NODE(10102, 283) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10102, 284) // Detect
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_10102

SkillLogic* SkillCreator_10102::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //设置变量
    Variable_10102_a101022 = logic->getVariables().setVariable<int32_t>("a101022", 1);
    Variable_10102_InterruptAnimat = logic->getVariables().setVariable<bool>("InterruptAnimat");
    //创建阶段phase
    auto phase = new SkillPhase_10102(1, logic, 3);
    //设置phase执行器
    phase->setRunPhaseNode(1, 1);
    phase->setRunPhaseNode(2, 44);
    phase->setDetectPhaseNode(3, 271);
    phase->setDetectPhaseNode(3, 284);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_10102::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
