#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

#include "skill_psnode_actorfilternewpene.h"
#include "skill_psnode_addskillbuffs.h"
#include "skill_psnode_comparefloat.h"
#include "skill_psnode_createtriggernewpene.h"
#include "skill_psnode_delay.h"
#include "skill_psnode_detect.h"
#include "skill_psnode_endphase.h"
#include "skill_psnode_getactorattribute.h"
#include "skill_psnode_getlocation.h"
#include "skill_psnode_getrotation.h"
#include "skill_psnode_if.h"
#include "skill_psnode_offsetcalculate.h"
#include "skill_psnode_playanimation.h"
#include "skill_psnode_playeffect.h"
#include "skill_psnode_playsound.h"
#include "skill_psnode_raiseevent.h"
#include "skill_psnode_resetcd.h"
#include "skill_psnode_skillendnotify.h"
#include "skill_psnode_spawncollider.h"
#include "skill_psnode_startphase.h"
#include "skill_psnode_stopeffect.h"
#include "skill_psnode_stopsound.h"
#include "skill_psnode_triggercheck.h"
#include "skill_psnode_triggerupdate.h"

namespace pvp {

//变量声明
//--------------------------------------------------------------------------------
// StartPhase
//
REGISTER_REGISTER_SKILL_NODE(22021, 1) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_StartPhase::TRIGGER_START, 149, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_StartPhase::TRIGGER_START, 145, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_StartPhase::TRIGGER_START, 96, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(22021, 1) {
    auto node1 = GET_SKILL_NODE(1, PhaseNode_StartPhase);
    if (node1 == nullptr) {
        node1 = new PhaseNode_StartPhase(1, phase);
        CALL_REGISTER_SKILL_NODE(22021, 1, node1)
    }
    if (noInit == true) {
        return node1;
    }
    return node1;
}
//--------------------------------------------------------------------------------
// TriggerUpdate
//
REGISTER_REGISTER_SKILL_NODE(22021, 2) {
}

REGISTER_CREATE_SKILL_NODE(22021, 2) {
    auto node2 = GET_SKILL_NODE(2, PhaseNode_TriggerUpdate);
    if (node2 == nullptr) {
        node2 = new PhaseNode_TriggerUpdate(2, phase);
        CALL_REGISTER_SKILL_NODE(22021, 2, node2)
    }
    if (noInit == true) {
        return node2;
    }
    return node2;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22021, 9) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_Delay::TRIGGER_DONE, 100, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(22021, 9) {
    auto node9 = GET_SKILL_NODE(9, PhaseNode_Delay);
    if (node9 == nullptr) {
        node9 = new PhaseNode_Delay(9, phase);
        node9->setTime(.50f);
        CALL_REGISTER_SKILL_NODE(22021, 9, node9)
    }
    if (noInit == true) {
        return node9;
    }
    return node9;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(22021, 13) {
}

REGISTER_CREATE_SKILL_NODE(22021, 13) {
    auto node13 = GET_SKILL_NODE(13, PhaseNode_EndPhase);
    if (node13 == nullptr) {
        node13 = new PhaseNode_EndPhase(13, phase);
        node13->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node13->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(22021, 13, node13)
    }
    if (noInit == true) {
        return node13;
    }
    return node13;
}
//--------------------------------------------------------------------------------
// SpawnCollider
//
REGISTER_REGISTER_SKILL_NODE(22021, 17) {
    pnode->resizeTrigger(PhaseNode_SpawnCollider::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_SpawnCollider::TRIGGER_DONE, 141, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_SpawnCollider::TRIGGER_DONE, 128, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(22021, 17) {
    auto node17 = GET_SKILL_NODE(17, PhaseNode_SpawnCollider);
    if (node17 == nullptr) {
        node17 = new PhaseNode_SpawnCollider(17, phase);
        node17->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node17->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node17->setMesh("");
        node17->setMeshScale(.00f);
        node17->setEffectID(0);
        node17->setEffectScale(.00f);
        node17->setType(PhaseNode_SpawnCollider::SpawnCollider_Type::Rect);
        node17->setTypeParams(0, 1.50f);
        node17->setTypeParams(1, 4.00f);
        node17->setTime(1.00f);
        node17->setPosZ(.00f);
        node17->setreentry(true);
        node17->setCheckPeneSound(false);
        CALL_REGISTER_SKILL_NODE(22021, 17, node17)
    }
    if (noInit == true) {
        return node17;
    }
    auto node108 = GET_SKILL_NODE(108, PhaseNode_OffsetCalculate);
    if (node108 != nullptr) node17->setPosX(node108->getOutPosX());
    if (node108 != nullptr) node17->setPosY(node108->getOutPosY());
    if (node108 != nullptr) node17->setRotation(node108->getOutRotation());
    return node17;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(22021, 54) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StopSound>(PhaseNode_Detect::TRIGGER_ON, 93, PhaseNode_StopSound::FUNC_STOP, &PhaseNode_StopSound::Stop);
}

REGISTER_CREATE_SKILL_NODE(22021, 54) {
    auto node54 = GET_SKILL_NODE(54, PhaseNode_Detect);
    if (node54 == nullptr) {
        node54 = new PhaseNode_Detect(54, phase);
        node54->setSelf(0U);
        node54->setEvent("");
        node54->setType(PhaseNode_Detect::Detect_Type::Actor_Dead);
        node54->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(22021, 54, node54)
    }
    if (noInit == true) {
        return node54;
    }
    return node54;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(22021, 56) {
}

REGISTER_CREATE_SKILL_NODE(22021, 56) {
    auto node56 = GET_SKILL_NODE(56, PhaseNode_EndPhase);
    if (node56 == nullptr) {
        node56 = new PhaseNode_EndPhase(56, phase);
        node56->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node56->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(22021, 56, node56)
    }
    if (noInit == true) {
        return node56;
    }
    return node56;
}
//--------------------------------------------------------------------------------
// StopSound
//
REGISTER_REGISTER_SKILL_NODE(22021, 93) {
    pnode->resizeTrigger(PhaseNode_StopSound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StopSound>(PhaseNode_StopSound::TRIGGER_DONE, 95, PhaseNode_StopSound::FUNC_STOP, &PhaseNode_StopSound::Stop);
}

REGISTER_CREATE_SKILL_NODE(22021, 93) {
    auto node93 = GET_SKILL_NODE(93, PhaseNode_StopSound);
    if (node93 == nullptr) {
        node93 = new PhaseNode_StopSound(93, phase);
        node93->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node93->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node93->setSoundID("VO_MON2202_ATK1");
        CALL_REGISTER_SKILL_NODE(22021, 93, node93)
    }
    if (noInit == true) {
        return node93;
    }
    return node93;
}
//--------------------------------------------------------------------------------
// StopSound
//
REGISTER_REGISTER_SKILL_NODE(22021, 95) {
    pnode->resizeTrigger(PhaseNode_StopSound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_StopSound::TRIGGER_DONE, 56, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(22021, 95) {
    auto node95 = GET_SKILL_NODE(95, PhaseNode_StopSound);
    if (node95 == nullptr) {
        node95 = new PhaseNode_StopSound(95, phase);
        node95->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node95->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node95->setSoundID("SE_MON2202_ATK1_P1");
        CALL_REGISTER_SKILL_NODE(22021, 95, node95)
    }
    if (noInit == true) {
        return node95;
    }
    return node95;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(22021, 96) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_ResetCD::TRIGGER_DONE, 97, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(22021, 96) {
    auto node96 = GET_SKILL_NODE(96, PhaseNode_ResetCD);
    if (node96 == nullptr) {
        node96 = new PhaseNode_ResetCD(96, phase);
        node96->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node96->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node96->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(22021, 96, node96)
    }
    if (noInit == true) {
        return node96;
    }
    return node96;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(22021, 97) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_PlayAnimation::TRIGGER_DONE, 98, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(22021, 97) {
    auto node97 = GET_SKILL_NODE(97, PhaseNode_PlayAnimation);
    if (node97 == nullptr) {
        node97 = new PhaseNode_PlayAnimation(97, phase);
        node97->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node97->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node97->setTarget(0U);
        node97->setAnimation("Skill1S1");
        node97->setParameter("");
        node97->setValue(false);
        CALL_REGISTER_SKILL_NODE(22021, 97, node97)
    }
    if (noInit == true) {
        return node97;
    }
    return node97;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(22021, 98) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlaySound::TRIGGER_DONE, 99, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(22021, 98) {
    auto node98 = GET_SKILL_NODE(98, PhaseNode_PlaySound);
    if (node98 == nullptr) {
        node98 = new PhaseNode_PlaySound(98, phase);
        node98->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node98->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node98->setSoundID("SE_MON2202_ATK1_P1");
        node98->setTarget(0U);
        node98->setUsePos(false);
        node98->setPosX(.00f);
        node98->setPosY(.00f);
        node98->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(22021, 98, node98)
    }
    if (noInit == true) {
        return node98;
    }
    return node98;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22021, 99) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_Delay::TRIGGER_DONE, 9, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(22021, 99) {
    auto node99 = GET_SKILL_NODE(99, PhaseNode_Delay);
    if (node99 == nullptr) {
        node99 = new PhaseNode_Delay(99, phase);
        node99->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(22021, 99, node99)
    }
    if (noInit == true) {
        return node99;
    }
    return node99;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(22021, 100) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetRotation>(PhaseNode_GetLocation::TRIGGER_DONE, 101, PhaseNode_GetRotation::FUNC_DO, &PhaseNode_GetRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(22021, 100) {
    auto node100 = GET_SKILL_NODE(100, PhaseNode_GetLocation);
    if (node100 == nullptr) {
        node100 = new PhaseNode_GetLocation(100, phase);
        node100->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node100->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(22021, 100, node100)
    }
    if (noInit == true) {
        return node100;
    }
    return node100;
}
//--------------------------------------------------------------------------------
// GetRotation
//
REGISTER_REGISTER_SKILL_NODE(22021, 101) {
    pnode->resizeTrigger(PhaseNode_GetRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_OffsetCalculate>(PhaseNode_GetRotation::TRIGGER_DONE, 102, PhaseNode_OffsetCalculate::FUNC_DO, &PhaseNode_OffsetCalculate::Do);
}

REGISTER_CREATE_SKILL_NODE(22021, 101) {
    auto node101 = GET_SKILL_NODE(101, PhaseNode_GetRotation);
    if (node101 == nullptr) {
        node101 = new PhaseNode_GetRotation(101, phase);
        node101->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node101->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(22021, 101, node101)
    }
    if (noInit == true) {
        return node101;
    }
    return node101;
}
//--------------------------------------------------------------------------------
// OffsetCalculate
//
REGISTER_REGISTER_SKILL_NODE(22021, 102) {
    pnode->resizeTrigger(PhaseNode_OffsetCalculate::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 103, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(22021, 102) {
    auto node102 = GET_SKILL_NODE(102, PhaseNode_OffsetCalculate);
    if (node102 == nullptr) {
        node102 = new PhaseNode_OffsetCalculate(102, phase);
        node102->setPosZ(.00f);
        node102->setOffsetX(.50f);
        node102->setOffsetY(1.10f);
        node102->setOffsetZ(2.40f);
        node102->setRotOffset(.00f);
        CALL_REGISTER_SKILL_NODE(22021, 102, node102)
    }
    if (noInit == true) {
        return node102;
    }
    auto node100 = GET_SKILL_NODE(100, PhaseNode_GetLocation);
    auto node101 = GET_SKILL_NODE(101, PhaseNode_GetRotation);
    if (node100 != nullptr) node102->setPosX(node100->getX());
    if (node100 != nullptr) node102->setPosY(node100->getY());
    if (node101 != nullptr) node102->setRotation(node101->getAngle());
    return node102;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(22021, 103) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetRotation>(PhaseNode_GetLocation::TRIGGER_DONE, 104, PhaseNode_GetRotation::FUNC_DO, &PhaseNode_GetRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(22021, 103) {
    auto node103 = GET_SKILL_NODE(103, PhaseNode_GetLocation);
    if (node103 == nullptr) {
        node103 = new PhaseNode_GetLocation(103, phase);
        node103->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node103->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(22021, 103, node103)
    }
    if (noInit == true) {
        return node103;
    }
    return node103;
}
//--------------------------------------------------------------------------------
// GetRotation
//
REGISTER_REGISTER_SKILL_NODE(22021, 104) {
    pnode->resizeTrigger(PhaseNode_GetRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_OffsetCalculate>(PhaseNode_GetRotation::TRIGGER_DONE, 105, PhaseNode_OffsetCalculate::FUNC_DO, &PhaseNode_OffsetCalculate::Do);
}

REGISTER_CREATE_SKILL_NODE(22021, 104) {
    auto node104 = GET_SKILL_NODE(104, PhaseNode_GetRotation);
    if (node104 == nullptr) {
        node104 = new PhaseNode_GetRotation(104, phase);
        node104->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node104->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(22021, 104, node104)
    }
    if (noInit == true) {
        return node104;
    }
    return node104;
}
//--------------------------------------------------------------------------------
// OffsetCalculate
//
REGISTER_REGISTER_SKILL_NODE(22021, 105) {
    pnode->resizeTrigger(PhaseNode_OffsetCalculate::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 106, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(22021, 105) {
    auto node105 = GET_SKILL_NODE(105, PhaseNode_OffsetCalculate);
    if (node105 == nullptr) {
        node105 = new PhaseNode_OffsetCalculate(105, phase);
        node105->setPosZ(.00f);
        node105->setOffsetX(-.40f);
        node105->setOffsetY(1.10f);
        node105->setOffsetZ(2.40f);
        node105->setRotOffset(.00f);
        CALL_REGISTER_SKILL_NODE(22021, 105, node105)
    }
    if (noInit == true) {
        return node105;
    }
    auto node103 = GET_SKILL_NODE(103, PhaseNode_GetLocation);
    auto node104 = GET_SKILL_NODE(104, PhaseNode_GetRotation);
    if (node103 != nullptr) node105->setPosX(node103->getX());
    if (node103 != nullptr) node105->setPosY(node103->getY());
    if (node104 != nullptr) node105->setRotation(node104->getAngle());
    return node105;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(22021, 106) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetRotation>(PhaseNode_GetLocation::TRIGGER_DONE, 107, PhaseNode_GetRotation::FUNC_DO, &PhaseNode_GetRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(22021, 106) {
    auto node106 = GET_SKILL_NODE(106, PhaseNode_GetLocation);
    if (node106 == nullptr) {
        node106 = new PhaseNode_GetLocation(106, phase);
        node106->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node106->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(22021, 106, node106)
    }
    if (noInit == true) {
        return node106;
    }
    return node106;
}
//--------------------------------------------------------------------------------
// GetRotation
//
REGISTER_REGISTER_SKILL_NODE(22021, 107) {
    pnode->resizeTrigger(PhaseNode_GetRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_OffsetCalculate>(PhaseNode_GetRotation::TRIGGER_DONE, 108, PhaseNode_OffsetCalculate::FUNC_DO, &PhaseNode_OffsetCalculate::Do);
}

REGISTER_CREATE_SKILL_NODE(22021, 107) {
    auto node107 = GET_SKILL_NODE(107, PhaseNode_GetRotation);
    if (node107 == nullptr) {
        node107 = new PhaseNode_GetRotation(107, phase);
        node107->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node107->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(22021, 107, node107)
    }
    if (noInit == true) {
        return node107;
    }
    return node107;
}
//--------------------------------------------------------------------------------
// OffsetCalculate
//
REGISTER_REGISTER_SKILL_NODE(22021, 108) {
    pnode->resizeTrigger(PhaseNode_OffsetCalculate::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 110, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(22021, 108) {
    auto node108 = GET_SKILL_NODE(108, PhaseNode_OffsetCalculate);
    if (node108 == nullptr) {
        node108 = new PhaseNode_OffsetCalculate(108, phase);
        node108->setPosZ(.00f);
        node108->setOffsetX(.00f);
        node108->setOffsetY(3.00f);
        node108->setOffsetZ(.00f);
        node108->setRotOffset(.00f);
        CALL_REGISTER_SKILL_NODE(22021, 108, node108)
    }
    if (noInit == true) {
        return node108;
    }
    auto node106 = GET_SKILL_NODE(106, PhaseNode_GetLocation);
    auto node107 = GET_SKILL_NODE(107, PhaseNode_GetRotation);
    if (node106 != nullptr) node108->setPosX(node106->getX());
    if (node106 != nullptr) node108->setPosY(node106->getY());
    if (node107 != nullptr) node108->setRotation(node107->getAngle());
    return node108;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(22021, 109) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_PlayEffect::TRIGGER_DONE, 112, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(22021, 109) {
    auto node109 = GET_SKILL_NODE(109, PhaseNode_PlayEffect);
    if (node109 == nullptr) {
        node109 = new PhaseNode_PlayEffect(109, phase);
        node109->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node109->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node109->setEffectID(220211);
        node109->setChangeColor(false);
        node109->setType(PhaseNode_PlayEffect::PlayEffect_Type::WithTarget);
        node109->getVars().reserve(5);
        node109->getVars().setVariable<uint64_t>(0, 0U);
        node109->getVars().setVariable<std::string>(1, "Muzzle02");
        node109->getVars().setVariable<float>(2, .00f);
        node109->getVars().setVariable<float>(3, .00f);
        node109->getVars().setVariable<float>(4, .00f);
        node109->setRotation(.00f);
        node109->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(22021, 109, node109)
    }
    if (noInit == true) {
        return node109;
    }
    return node109;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(22021, 110) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_FALSE, 111, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_TRUE, 109, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(22021, 110) {
    auto node110 = GET_SKILL_NODE(110, PhaseNode_If);
    if (node110 == nullptr) {
        node110 = new PhaseNode_If(110, phase);
        node110->setCondition(true);
        CALL_REGISTER_SKILL_NODE(22021, 110, node110)
    }
    if (noInit == true) {
        return node110;
    }
    return node110;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(22021, 111) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_PlayEffect::TRIGGER_DONE, 112, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(22021, 111) {
    auto node111 = GET_SKILL_NODE(111, PhaseNode_PlayEffect);
    if (node111 == nullptr) {
        node111 = new PhaseNode_PlayEffect(111, phase);
        node111->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node111->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node111->setEffectID(220211);
        node111->setChangeColor(false);
        node111->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node111->getVars().reserve(3);
        node111->getVars().setVariable<float>(0, .00f);
        node111->getVars().setVariable<float>(1, .00f);
        node111->getVars().setVariable<float>(2, .00f);
        node111->setRotation(.00f);
        node111->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(22021, 111, node111)
    }
    if (noInit == true) {
        return node111;
    }
    return node111;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(22021, 112) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 116, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_LESS, 113, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_CompareFloat::TRIGGER_LESS, 116, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(22021, 112) {
    auto node112 = GET_SKILL_NODE(112, PhaseNode_CompareFloat);
    if (node112 == nullptr) {
        node112 = new PhaseNode_CompareFloat(112, phase);
        node112->setA(.00f);
        node112->setB(.00f);
        CALL_REGISTER_SKILL_NODE(22021, 112, node112)
    }
    if (noInit == true) {
        return node112;
    }
    return node112;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22021, 113) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StopEffect>(PhaseNode_Delay::TRIGGER_DONE, 114, PhaseNode_StopEffect::FUNC_DO, &PhaseNode_StopEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(22021, 113) {
    auto node113 = GET_SKILL_NODE(113, PhaseNode_Delay);
    if (node113 == nullptr) {
        node113 = new PhaseNode_Delay(113, phase);
        node113->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(22021, 113, node113)
    }
    if (noInit == true) {
        return node113;
    }
    return node113;
}
//--------------------------------------------------------------------------------
// StopEffect
//
REGISTER_REGISTER_SKILL_NODE(22021, 114) {
}

REGISTER_CREATE_SKILL_NODE(22021, 114) {
    auto node114 = GET_SKILL_NODE(114, PhaseNode_StopEffect);
    if (node114 == nullptr) {
        node114 = new PhaseNode_StopEffect(114, phase);
        node114->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node114->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node114->setEffectID(220211);
        CALL_REGISTER_SKILL_NODE(22021, 114, node114)
    }
    if (noInit == true) {
        return node114;
    }
    return node114;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(22021, 115) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_PlayEffect::TRIGGER_DONE, 118, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(22021, 115) {
    auto node115 = GET_SKILL_NODE(115, PhaseNode_PlayEffect);
    if (node115 == nullptr) {
        node115 = new PhaseNode_PlayEffect(115, phase);
        node115->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node115->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node115->setEffectID(220211);
        node115->setChangeColor(false);
        node115->setType(PhaseNode_PlayEffect::PlayEffect_Type::WithTarget);
        node115->getVars().reserve(5);
        node115->getVars().setVariable<uint64_t>(0, 0U);
        node115->getVars().setVariable<std::string>(1, "Muzzle");
        node115->getVars().setVariable<float>(2, .00f);
        node115->getVars().setVariable<float>(3, .00f);
        node115->getVars().setVariable<float>(4, .00f);
        node115->setRotation(.00f);
        node115->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(22021, 115, node115)
    }
    if (noInit == true) {
        return node115;
    }
    return node115;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(22021, 116) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_FALSE, 117, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_TRUE, 115, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(22021, 116) {
    auto node116 = GET_SKILL_NODE(116, PhaseNode_If);
    if (node116 == nullptr) {
        node116 = new PhaseNode_If(116, phase);
        node116->setCondition(true);
        CALL_REGISTER_SKILL_NODE(22021, 116, node116)
    }
    if (noInit == true) {
        return node116;
    }
    return node116;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(22021, 117) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_PlayEffect::TRIGGER_DONE, 118, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(22021, 117) {
    auto node117 = GET_SKILL_NODE(117, PhaseNode_PlayEffect);
    if (node117 == nullptr) {
        node117 = new PhaseNode_PlayEffect(117, phase);
        node117->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node117->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node117->setEffectID(220211);
        node117->setChangeColor(false);
        node117->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node117->getVars().reserve(3);
        node117->getVars().setVariable<float>(0, .00f);
        node117->getVars().setVariable<float>(1, .00f);
        node117->getVars().setVariable<float>(2, .00f);
        node117->setRotation(.00f);
        node117->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(22021, 117, node117)
    }
    if (noInit == true) {
        return node117;
    }
    return node117;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(22021, 118) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnCollider>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 17, PhaseNode_SpawnCollider::FUNC_DO, &PhaseNode_SpawnCollider::Do);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_LESS, 119, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_SpawnCollider>(PhaseNode_CompareFloat::TRIGGER_LESS, 17, PhaseNode_SpawnCollider::FUNC_DO, &PhaseNode_SpawnCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(22021, 118) {
    auto node118 = GET_SKILL_NODE(118, PhaseNode_CompareFloat);
    if (node118 == nullptr) {
        node118 = new PhaseNode_CompareFloat(118, phase);
        node118->setA(.00f);
        node118->setB(.00f);
        CALL_REGISTER_SKILL_NODE(22021, 118, node118)
    }
    if (noInit == true) {
        return node118;
    }
    return node118;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22021, 119) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StopEffect>(PhaseNode_Delay::TRIGGER_DONE, 120, PhaseNode_StopEffect::FUNC_DO, &PhaseNode_StopEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(22021, 119) {
    auto node119 = GET_SKILL_NODE(119, PhaseNode_Delay);
    if (node119 == nullptr) {
        node119 = new PhaseNode_Delay(119, phase);
        node119->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(22021, 119, node119)
    }
    if (noInit == true) {
        return node119;
    }
    return node119;
}
//--------------------------------------------------------------------------------
// StopEffect
//
REGISTER_REGISTER_SKILL_NODE(22021, 120) {
}

REGISTER_CREATE_SKILL_NODE(22021, 120) {
    auto node120 = GET_SKILL_NODE(120, PhaseNode_StopEffect);
    if (node120 == nullptr) {
        node120 = new PhaseNode_StopEffect(120, phase);
        node120->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node120->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node120->setEffectID(220211);
        CALL_REGISTER_SKILL_NODE(22021, 120, node120)
    }
    if (noInit == true) {
        return node120;
    }
    return node120;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(22021, 121) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 133, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 135, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(22021, 121) {
    auto node121 = GET_SKILL_NODE(121, PhaseNode_CreateTriggerNewPene);
    if (node121 == nullptr) {
        node121 = new PhaseNode_CreateTriggerNewPene(121, phase);
        node121->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::In);
        node121->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node121->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Enemy);
        node121->setOnHero(true);
        node121->setOnMinion(true);
        node121->setOnDestruct(true);
        node121->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(22021, 121, node121)
    }
    if (noInit == true) {
        return node121;
    }
    auto node17 = GET_SKILL_NODE(17, PhaseNode_SpawnCollider);
    if (node17 != nullptr) node121->setColliderID(node17->getColliderID());
    return node121;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(22021, 122) {
}

REGISTER_CREATE_SKILL_NODE(22021, 122) {
    auto node122 = GET_SKILL_NODE(122, PhaseNode_TriggerCheck);
    if (node122 == nullptr) {
        node122 = new PhaseNode_TriggerCheck(122, phase);
        auto node2 = GET_SKILL_NODE(2, PhaseNode_TriggerUpdate);
        if (node2 != nullptr) node2->addTriggerCheck(node122);
        
        CALL_REGISTER_SKILL_NODE(22021, 122, node122)
    }
    if (noInit == true) {
        return node122;
    }
    auto node131 = GET_SKILL_NODE(131, PhaseNode_CreateTriggerNewPene);
    if (node131 != nullptr) node122->setTrigger(0, node131->getTriggerID());
    return node122;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(22021, 123) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 124, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(22021, 123) {
    auto node123 = GET_SKILL_NODE(123, PhaseNode_ActorFilterNewPene);
    if (node123 == nullptr) {
        node123 = new PhaseNode_ActorFilterNewPene(123, phase);
        node123->setHero(true);
        node123->setMinion(true);
        node123->setDestruct(true);
        node123->setShield(false);
        node123->setTotalCount(0);
        node123->setPerCount(0);
        CALL_REGISTER_SKILL_NODE(22021, 123, node123)
    }
    if (noInit == true) {
        return node123;
    }
    auto node127 = GET_SKILL_NODE(127, PhaseNode_CreateTriggerNewPene);
    if (node127 != nullptr) node123->setInput(node127->getOther());
    return node123;
}
//--------------------------------------------------------------------------------
// GetActorAttribute
//
REGISTER_REGISTER_SKILL_NODE(22021, 124) {
    pnode->resizeTrigger(PhaseNode_GetActorAttribute::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 125, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 138, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 139, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 140, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
}

REGISTER_CREATE_SKILL_NODE(22021, 124) {
    auto node124 = GET_SKILL_NODE(124, PhaseNode_GetActorAttribute);
    if (node124 == nullptr) {
        node124 = new PhaseNode_GetActorAttribute(124, phase);
        node124->setTarget(0U);
        node124->setType({202});
        CALL_REGISTER_SKILL_NODE(22021, 124, node124)
    }
    if (noInit == true) {
        return node124;
    }
    return node124;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(22021, 125) {
}

REGISTER_CREATE_SKILL_NODE(22021, 125) {
    auto node125 = GET_SKILL_NODE(125, PhaseNode_AddSkillBuffs);
    if (node125 == nullptr) {
        node125 = new PhaseNode_AddSkillBuffs(125, phase);
        node125->setConfigID({13});
        CALL_REGISTER_SKILL_NODE(22021, 125, node125)
    }
    if (noInit == true) {
        return node125;
    }
    auto node123 = GET_SKILL_NODE(123, PhaseNode_ActorFilterNewPene);
    auto node124 = GET_SKILL_NODE(124, PhaseNode_GetActorAttribute);
    if (node123 != nullptr) node125->setTarget(node123->getOutput());
    if (node124 != nullptr) node125->setAttribute(node124->getAttribute());
    return node125;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(22021, 126) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 121, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_LESS, 127, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
}

REGISTER_CREATE_SKILL_NODE(22021, 126) {
    auto node126 = GET_SKILL_NODE(126, PhaseNode_CompareFloat);
    if (node126 == nullptr) {
        node126 = new PhaseNode_CompareFloat(126, phase);
        node126->setA(.00f);
        node126->setB(.20f);
        CALL_REGISTER_SKILL_NODE(22021, 126, node126)
    }
    if (noInit == true) {
        return node126;
    }
    return node126;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(22021, 127) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 132, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 123, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(22021, 127) {
    auto node127 = GET_SKILL_NODE(127, PhaseNode_CreateTriggerNewPene);
    if (node127 == nullptr) {
        node127 = new PhaseNode_CreateTriggerNewPene(127, phase);
        node127->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::Tick);
        node127->setTypeParams(0, .20f);
        node127->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node127->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Enemy);
        node127->setOnHero(true);
        node127->setOnMinion(true);
        node127->setOnDestruct(true);
        node127->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(22021, 127, node127)
    }
    if (noInit == true) {
        return node127;
    }
    auto node17 = GET_SKILL_NODE(17, PhaseNode_SpawnCollider);
    if (node17 != nullptr) node127->setColliderID(node17->getColliderID());
    return node127;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(22021, 128) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_If::TRIGGER_FALSE, 129, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_If::TRIGGER_TRUE, 126, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(22021, 128) {
    auto node128 = GET_SKILL_NODE(128, PhaseNode_If);
    if (node128 == nullptr) {
        node128 = new PhaseNode_If(128, phase);
        node128->setCondition(true);
        CALL_REGISTER_SKILL_NODE(22021, 128, node128)
    }
    if (noInit == true) {
        return node128;
    }
    return node128;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(22021, 129) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 131, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_LESS, 130, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
}

REGISTER_CREATE_SKILL_NODE(22021, 129) {
    auto node129 = GET_SKILL_NODE(129, PhaseNode_CompareFloat);
    if (node129 == nullptr) {
        node129 = new PhaseNode_CompareFloat(129, phase);
        node129->setA(.00f);
        node129->setB(.20f);
        CALL_REGISTER_SKILL_NODE(22021, 129, node129)
    }
    if (noInit == true) {
        return node129;
    }
    return node129;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(22021, 130) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 134, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 136, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(22021, 130) {
    auto node130 = GET_SKILL_NODE(130, PhaseNode_CreateTriggerNewPene);
    if (node130 == nullptr) {
        node130 = new PhaseNode_CreateTriggerNewPene(130, phase);
        node130->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::Tick);
        node130->setTypeParams(0, .20f);
        node130->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node130->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Friend);
        node130->setOnHero(true);
        node130->setOnMinion(true);
        node130->setOnDestruct(true);
        node130->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(22021, 130, node130)
    }
    if (noInit == true) {
        return node130;
    }
    auto node17 = GET_SKILL_NODE(17, PhaseNode_SpawnCollider);
    if (node17 != nullptr) node130->setColliderID(node17->getColliderID());
    return node130;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(22021, 131) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 122, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 137, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(22021, 131) {
    auto node131 = GET_SKILL_NODE(131, PhaseNode_CreateTriggerNewPene);
    if (node131 == nullptr) {
        node131 = new PhaseNode_CreateTriggerNewPene(131, phase);
        node131->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::In);
        node131->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node131->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Friend);
        node131->setOnHero(true);
        node131->setOnMinion(true);
        node131->setOnDestruct(true);
        node131->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(22021, 131, node131)
    }
    if (noInit == true) {
        return node131;
    }
    auto node17 = GET_SKILL_NODE(17, PhaseNode_SpawnCollider);
    if (node17 != nullptr) node131->setColliderID(node17->getColliderID());
    return node131;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(22021, 132) {
}

REGISTER_CREATE_SKILL_NODE(22021, 132) {
    auto node132 = GET_SKILL_NODE(132, PhaseNode_TriggerCheck);
    if (node132 == nullptr) {
        node132 = new PhaseNode_TriggerCheck(132, phase);
        auto node2 = GET_SKILL_NODE(2, PhaseNode_TriggerUpdate);
        if (node2 != nullptr) node2->addTriggerCheck(node132);
        
        CALL_REGISTER_SKILL_NODE(22021, 132, node132)
    }
    if (noInit == true) {
        return node132;
    }
    auto node127 = GET_SKILL_NODE(127, PhaseNode_CreateTriggerNewPene);
    if (node127 != nullptr) node132->setTrigger(0, node127->getTriggerID());
    return node132;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(22021, 133) {
}

REGISTER_CREATE_SKILL_NODE(22021, 133) {
    auto node133 = GET_SKILL_NODE(133, PhaseNode_TriggerCheck);
    if (node133 == nullptr) {
        node133 = new PhaseNode_TriggerCheck(133, phase);
        auto node2 = GET_SKILL_NODE(2, PhaseNode_TriggerUpdate);
        if (node2 != nullptr) node2->addTriggerCheck(node133);
        
        CALL_REGISTER_SKILL_NODE(22021, 133, node133)
    }
    if (noInit == true) {
        return node133;
    }
    auto node121 = GET_SKILL_NODE(121, PhaseNode_CreateTriggerNewPene);
    if (node121 != nullptr) node133->setTrigger(0, node121->getTriggerID());
    return node133;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(22021, 134) {
}

REGISTER_CREATE_SKILL_NODE(22021, 134) {
    auto node134 = GET_SKILL_NODE(134, PhaseNode_TriggerCheck);
    if (node134 == nullptr) {
        node134 = new PhaseNode_TriggerCheck(134, phase);
        auto node2 = GET_SKILL_NODE(2, PhaseNode_TriggerUpdate);
        if (node2 != nullptr) node2->addTriggerCheck(node134);
        
        CALL_REGISTER_SKILL_NODE(22021, 134, node134)
    }
    if (noInit == true) {
        return node134;
    }
    auto node130 = GET_SKILL_NODE(130, PhaseNode_CreateTriggerNewPene);
    if (node130 != nullptr) node134->setTrigger(0, node130->getTriggerID());
    return node134;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(22021, 135) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 124, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(22021, 135) {
    auto node135 = GET_SKILL_NODE(135, PhaseNode_ActorFilterNewPene);
    if (node135 == nullptr) {
        node135 = new PhaseNode_ActorFilterNewPene(135, phase);
        node135->setHero(true);
        node135->setMinion(true);
        node135->setDestruct(true);
        node135->setShield(false);
        node135->setTotalCount(0);
        node135->setPerCount(0);
        CALL_REGISTER_SKILL_NODE(22021, 135, node135)
    }
    if (noInit == true) {
        return node135;
    }
    auto node121 = GET_SKILL_NODE(121, PhaseNode_CreateTriggerNewPene);
    if (node121 != nullptr) node135->setInput(node121->getOther());
    return node135;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(22021, 136) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 124, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(22021, 136) {
    auto node136 = GET_SKILL_NODE(136, PhaseNode_ActorFilterNewPene);
    if (node136 == nullptr) {
        node136 = new PhaseNode_ActorFilterNewPene(136, phase);
        node136->setHero(true);
        node136->setMinion(true);
        node136->setDestruct(true);
        node136->setShield(false);
        node136->setTotalCount(0);
        node136->setPerCount(0);
        CALL_REGISTER_SKILL_NODE(22021, 136, node136)
    }
    if (noInit == true) {
        return node136;
    }
    auto node130 = GET_SKILL_NODE(130, PhaseNode_CreateTriggerNewPene);
    if (node130 != nullptr) node136->setInput(node130->getOther());
    return node136;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(22021, 137) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 124, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(22021, 137) {
    auto node137 = GET_SKILL_NODE(137, PhaseNode_ActorFilterNewPene);
    if (node137 == nullptr) {
        node137 = new PhaseNode_ActorFilterNewPene(137, phase);
        node137->setHero(true);
        node137->setMinion(true);
        node137->setDestruct(true);
        node137->setShield(false);
        node137->setTotalCount(0);
        node137->setPerCount(0);
        CALL_REGISTER_SKILL_NODE(22021, 137, node137)
    }
    if (noInit == true) {
        return node137;
    }
    auto node131 = GET_SKILL_NODE(131, PhaseNode_CreateTriggerNewPene);
    if (node131 != nullptr) node137->setInput(node131->getOther());
    return node137;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(22021, 138) {
}

REGISTER_CREATE_SKILL_NODE(22021, 138) {
    auto node138 = GET_SKILL_NODE(138, PhaseNode_AddSkillBuffs);
    if (node138 == nullptr) {
        node138 = new PhaseNode_AddSkillBuffs(138, phase);
        node138->setConfigID({13});
        CALL_REGISTER_SKILL_NODE(22021, 138, node138)
    }
    if (noInit == true) {
        return node138;
    }
    auto node135 = GET_SKILL_NODE(135, PhaseNode_ActorFilterNewPene);
    auto node124 = GET_SKILL_NODE(124, PhaseNode_GetActorAttribute);
    if (node135 != nullptr) node138->setTarget(node135->getOutput());
    if (node124 != nullptr) node138->setAttribute(node124->getAttribute());
    return node138;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(22021, 139) {
}

REGISTER_CREATE_SKILL_NODE(22021, 139) {
    auto node139 = GET_SKILL_NODE(139, PhaseNode_AddSkillBuffs);
    if (node139 == nullptr) {
        node139 = new PhaseNode_AddSkillBuffs(139, phase);
        node139->setConfigID({13});
        CALL_REGISTER_SKILL_NODE(22021, 139, node139)
    }
    if (noInit == true) {
        return node139;
    }
    auto node136 = GET_SKILL_NODE(136, PhaseNode_ActorFilterNewPene);
    auto node124 = GET_SKILL_NODE(124, PhaseNode_GetActorAttribute);
    if (node136 != nullptr) node139->setTarget(node136->getOutput());
    if (node124 != nullptr) node139->setAttribute(node124->getAttribute());
    return node139;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(22021, 140) {
}

REGISTER_CREATE_SKILL_NODE(22021, 140) {
    auto node140 = GET_SKILL_NODE(140, PhaseNode_AddSkillBuffs);
    if (node140 == nullptr) {
        node140 = new PhaseNode_AddSkillBuffs(140, phase);
        node140->setConfigID({13});
        CALL_REGISTER_SKILL_NODE(22021, 140, node140)
    }
    if (noInit == true) {
        return node140;
    }
    auto node137 = GET_SKILL_NODE(137, PhaseNode_ActorFilterNewPene);
    auto node124 = GET_SKILL_NODE(124, PhaseNode_GetActorAttribute);
    if (node137 != nullptr) node140->setTarget(node137->getOutput());
    if (node124 != nullptr) node140->setAttribute(node124->getAttribute());
    return node140;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22021, 141) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_Delay::TRIGGER_DONE, 143, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(22021, 141) {
    auto node141 = GET_SKILL_NODE(141, PhaseNode_Delay);
    if (node141 == nullptr) {
        node141 = new PhaseNode_Delay(141, phase);
        node141->setTime(1.10f);
        CALL_REGISTER_SKILL_NODE(22021, 141, node141)
    }
    if (noInit == true) {
        return node141;
    }
    return node141;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(22021, 142) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 13, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(22021, 142) {
    auto node142 = GET_SKILL_NODE(142, PhaseNode_SkillEndNotify);
    if (node142 == nullptr) {
        node142 = new PhaseNode_SkillEndNotify(142, phase);
        node142->setReturnType(false);
        CALL_REGISTER_SKILL_NODE(22021, 142, node142)
    }
    if (noInit == true) {
        return node142;
    }
    return node142;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(22021, 143) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_FALSE, 144, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_TRUE, 142, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
}

REGISTER_CREATE_SKILL_NODE(22021, 143) {
    auto node143 = GET_SKILL_NODE(143, PhaseNode_If);
    if (node143 == nullptr) {
        node143 = new PhaseNode_If(143, phase);
        node143->setCondition(false);
        CALL_REGISTER_SKILL_NODE(22021, 143, node143)
    }
    if (noInit == true) {
        return node143;
    }
    return node143;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(22021, 144) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 13, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(22021, 144) {
    auto node144 = GET_SKILL_NODE(144, PhaseNode_SkillEndNotify);
    if (node144 == nullptr) {
        node144 = new PhaseNode_SkillEndNotify(144, phase);
        node144->setReturnType(true);
        CALL_REGISTER_SKILL_NODE(22021, 144, node144)
    }
    if (noInit == true) {
        return node144;
    }
    return node144;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(22021, 145) {
}

REGISTER_CREATE_SKILL_NODE(22021, 145) {
    auto node145 = GET_SKILL_NODE(145, PhaseNode_RaiseEvent);
    if (node145 == nullptr) {
        node145 = new PhaseNode_RaiseEvent(145, phase);
        node145->setEvent("MonsterInterrupt");
        node145->setTarget(0U);
        node145->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node145->setTypeParams(0, 0);
        node145->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(22021, 145, node145)
    }
    if (noInit == true) {
        return node145;
    }
    return node145;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(22021, 146) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_Detect::TRIGGER_ON, 151, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(22021, 146) {
    auto node146 = GET_SKILL_NODE(146, PhaseNode_Detect);
    if (node146 == nullptr) {
        node146 = new PhaseNode_Detect(146, phase);
        node146->setSelf(0U);
        node146->setEvent("MonsterInterrupt");
        node146->setType(PhaseNode_Detect::Detect_Type::Interrupt_Skill);
        node146->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(22021, 146, node146)
    }
    if (noInit == true) {
        return node146;
    }
    return node146;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(22021, 147) {
}

REGISTER_CREATE_SKILL_NODE(22021, 147) {
    auto node147 = GET_SKILL_NODE(147, PhaseNode_EndPhase);
    if (node147 == nullptr) {
        node147 = new PhaseNode_EndPhase(147, phase);
        node147->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node147->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(22021, 147, node147)
    }
    if (noInit == true) {
        return node147;
    }
    return node147;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22021, 149) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_Delay::TRIGGER_DONE, 150, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(22021, 149) {
    auto node149 = GET_SKILL_NODE(149, PhaseNode_Delay);
    if (node149 == nullptr) {
        node149 = new PhaseNode_Delay(149, phase);
        node149->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(22021, 149, node149)
    }
    if (noInit == true) {
        return node149;
    }
    return node149;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(22021, 150) {
}

REGISTER_CREATE_SKILL_NODE(22021, 150) {
    auto node150 = GET_SKILL_NODE(150, PhaseNode_PlaySound);
    if (node150 == nullptr) {
        node150 = new PhaseNode_PlaySound(150, phase);
        node150->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node150->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node150->setSoundID("VO_MON2202_ATK1");
        node150->setTarget(0U);
        node150->setUsePos(false);
        node150->setPosX(.00f);
        node150->setPosY(.00f);
        node150->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(22021, 150, node150)
    }
    if (noInit == true) {
        return node150;
    }
    return node150;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22021, 151) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_Delay::TRIGGER_DONE, 153, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(22021, 151) {
    auto node151 = GET_SKILL_NODE(151, PhaseNode_Delay);
    if (node151 == nullptr) {
        node151 = new PhaseNode_Delay(151, phase);
        node151->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(22021, 151, node151)
    }
    if (noInit == true) {
        return node151;
    }
    return node151;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(22021, 152) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 147, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(22021, 152) {
    auto node152 = GET_SKILL_NODE(152, PhaseNode_SkillEndNotify);
    if (node152 == nullptr) {
        node152 = new PhaseNode_SkillEndNotify(152, phase);
        node152->setReturnType(false);
        CALL_REGISTER_SKILL_NODE(22021, 152, node152)
    }
    if (noInit == true) {
        return node152;
    }
    return node152;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(22021, 153) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_FALSE, 154, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_TRUE, 152, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
}

REGISTER_CREATE_SKILL_NODE(22021, 153) {
    auto node153 = GET_SKILL_NODE(153, PhaseNode_If);
    if (node153 == nullptr) {
        node153 = new PhaseNode_If(153, phase);
        node153->setCondition(false);
        CALL_REGISTER_SKILL_NODE(22021, 153, node153)
    }
    if (noInit == true) {
        return node153;
    }
    return node153;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(22021, 154) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 147, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(22021, 154) {
    auto node154 = GET_SKILL_NODE(154, PhaseNode_SkillEndNotify);
    if (node154 == nullptr) {
        node154 = new PhaseNode_SkillEndNotify(154, phase);
        node154->setReturnType(true);
        CALL_REGISTER_SKILL_NODE(22021, 154, node154)
    }
    if (noInit == true) {
        return node154;
    }
    return node154;
}

//--------------------------------------------------------------------------------
// SkillCreator_22021
//
class SkillCreator_22021 : public SkillCreator {
public:
    SkillCreator_22021() {}
    virtual ~SkillCreator_22021() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_22021

//--------------------------------------------------------------------------------
// SkillPhase_22021
//
class SkillPhase_22021 : public SkillPhase {
public:
    SkillPhase_22021(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_22021() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(22021, 1) // StartPhase
        CASE_CREATE_SKILL_NODE(22021, 2) // TriggerUpdate
        CASE_CREATE_SKILL_NODE(22021, 9) // Delay
        CASE_CREATE_SKILL_NODE(22021, 13) // EndPhase
        CASE_CREATE_SKILL_NODE(22021, 17) // SpawnCollider
        CASE_CREATE_SKILL_NODE(22021, 54) // Detect
        CASE_CREATE_SKILL_NODE(22021, 56) // EndPhase
        CASE_CREATE_SKILL_NODE(22021, 93) // StopSound
        CASE_CREATE_SKILL_NODE(22021, 95) // StopSound
        CASE_CREATE_SKILL_NODE(22021, 96) // ResetCD
        CASE_CREATE_SKILL_NODE(22021, 97) // PlayAnimation
        CASE_CREATE_SKILL_NODE(22021, 98) // PlaySound
        CASE_CREATE_SKILL_NODE(22021, 99) // Delay
        CASE_CREATE_SKILL_NODE(22021, 100) // GetLocation
        CASE_CREATE_SKILL_NODE(22021, 101) // GetRotation
        CASE_CREATE_SKILL_NODE(22021, 102) // OffsetCalculate
        CASE_CREATE_SKILL_NODE(22021, 103) // GetLocation
        CASE_CREATE_SKILL_NODE(22021, 104) // GetRotation
        CASE_CREATE_SKILL_NODE(22021, 105) // OffsetCalculate
        CASE_CREATE_SKILL_NODE(22021, 106) // GetLocation
        CASE_CREATE_SKILL_NODE(22021, 107) // GetRotation
        CASE_CREATE_SKILL_NODE(22021, 108) // OffsetCalculate
        CASE_CREATE_SKILL_NODE(22021, 109) // PlayEffect
        CASE_CREATE_SKILL_NODE(22021, 110) // If
        CASE_CREATE_SKILL_NODE(22021, 111) // PlayEffect
        CASE_CREATE_SKILL_NODE(22021, 112) // CompareFloat
        CASE_CREATE_SKILL_NODE(22021, 113) // Delay
        CASE_CREATE_SKILL_NODE(22021, 114) // StopEffect
        CASE_CREATE_SKILL_NODE(22021, 115) // PlayEffect
        CASE_CREATE_SKILL_NODE(22021, 116) // If
        CASE_CREATE_SKILL_NODE(22021, 117) // PlayEffect
        CASE_CREATE_SKILL_NODE(22021, 118) // CompareFloat
        CASE_CREATE_SKILL_NODE(22021, 119) // Delay
        CASE_CREATE_SKILL_NODE(22021, 120) // StopEffect
        CASE_CREATE_SKILL_NODE(22021, 121) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(22021, 122) // TriggerCheck
        CASE_CREATE_SKILL_NODE(22021, 123) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(22021, 124) // GetActorAttribute
        CASE_CREATE_SKILL_NODE(22021, 125) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(22021, 126) // CompareFloat
        CASE_CREATE_SKILL_NODE(22021, 127) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(22021, 128) // If
        CASE_CREATE_SKILL_NODE(22021, 129) // CompareFloat
        CASE_CREATE_SKILL_NODE(22021, 130) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(22021, 131) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(22021, 132) // TriggerCheck
        CASE_CREATE_SKILL_NODE(22021, 133) // TriggerCheck
        CASE_CREATE_SKILL_NODE(22021, 134) // TriggerCheck
        CASE_CREATE_SKILL_NODE(22021, 135) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(22021, 136) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(22021, 137) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(22021, 138) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(22021, 139) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(22021, 140) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(22021, 141) // Delay
        CASE_CREATE_SKILL_NODE(22021, 142) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(22021, 143) // If
        CASE_CREATE_SKILL_NODE(22021, 144) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(22021, 145) // RaiseEvent
        CASE_CREATE_SKILL_NODE(22021, 146) // Detect
        CASE_CREATE_SKILL_NODE(22021, 147) // EndPhase
        CASE_CREATE_SKILL_NODE(22021, 149) // Delay
        CASE_CREATE_SKILL_NODE(22021, 150) // PlaySound
        CASE_CREATE_SKILL_NODE(22021, 151) // Delay
        CASE_CREATE_SKILL_NODE(22021, 152) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(22021, 153) // If
        CASE_CREATE_SKILL_NODE(22021, 154) // SkillEndNotify
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_22021

SkillLogic* SkillCreator_22021::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //创建阶段phase
    auto phase = new SkillPhase_22021(1, logic, 3);
    //设置phase执行器
    phase->setRunPhaseNode(1, 1);
    phase->setRunPhaseNode(2, 2);
    phase->setDetectPhaseNode(3, 54);
    phase->setDetectPhaseNode(3, 146);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_22021::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
