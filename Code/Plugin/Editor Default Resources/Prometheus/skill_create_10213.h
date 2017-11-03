#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

#include "skill_psnode_actorfilternewpene.h"
#include "skill_psnode_addskillbuff.h"
#include "skill_psnode_addskillbuffs.h"
#include "skill_psnode_createtriggernewpene.h"
#include "skill_psnode_delay.h"
#include "skill_psnode_detect.h"
#include "skill_psnode_disable.h"
#include "skill_psnode_endphase.h"
#include "skill_psnode_getactorattribute.h"
#include "skill_psnode_getlocation.h"
#include "skill_psnode_getrotation.h"
#include "skill_psnode_if.h"
#include "skill_psnode_isinterrupttype.h"
#include "skill_psnode_playanimation.h"
#include "skill_psnode_playeffect.h"
#include "skill_psnode_playsound.h"
#include "skill_psnode_raiseevent.h"
#include "skill_psnode_resetcd.h"
#include "skill_psnode_setbool.h"
#include "skill_psnode_spawncollider.h"
#include "skill_psnode_startphase.h"
#include "skill_psnode_startpreinput.h"
#include "skill_psnode_switchtoint.h"
#include "skill_psnode_triggercheck.h"
#include "skill_psnode_triggerupdate.h"

namespace pvp {

//变量声明
uint64_t Variable_10213_102132 = 0;
uint64_t Variable_10213_InterruptAnimat = 0;
//--------------------------------------------------------------------------------
// StartPhase
//
REGISTER_REGISTER_SKILL_NODE(10213, 2) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_StartPhase::TRIGGER_START, 4, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(10213, 2) {
    auto node2 = GET_SKILL_NODE(2, PhaseNode_StartPhase);
    if (node2 == nullptr) {
        node2 = new PhaseNode_StartPhase(2, phase);
        CALL_REGISTER_SKILL_NODE(10213, 2, node2)
    }
    if (noInit == true) {
        return node2;
    }
    return node2;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(10213, 4) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_ResetCD::TRIGGER_DONE, 6, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_ResetCD::TRIGGER_DONE, 134, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_ResetCD::TRIGGER_DONE, 141, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10213, 4) {
    auto node4 = GET_SKILL_NODE(4, PhaseNode_ResetCD);
    if (node4 == nullptr) {
        node4 = new PhaseNode_ResetCD(4, phase);
        node4->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node4->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node4->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(10213, 4, node4)
    }
    if (noInit == true) {
        return node4;
    }
    return node4;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10213, 6) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuff>(PhaseNode_PlayAnimation::TRIGGER_DONE, 132, PhaseNode_AddSkillBuff::FUNC_ADD, &PhaseNode_AddSkillBuff::Add);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_PlayAnimation::TRIGGER_DONE, 136, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(10213, 6) {
    auto node6 = GET_SKILL_NODE(6, PhaseNode_PlayAnimation);
    if (node6 == nullptr) {
        node6 = new PhaseNode_PlayAnimation(6, phase);
        node6->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node6->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node6->setTarget(0U);
        node6->setAnimation("Skill3S1");
        node6->setParameter("");
        node6->setValue(false);
        CALL_REGISTER_SKILL_NODE(10213, 6, node6)
    }
    if (noInit == true) {
        return node6;
    }
    return node6;
}
//--------------------------------------------------------------------------------
// TriggerUpdate
//
REGISTER_REGISTER_SKILL_NODE(10213, 11) {
}

REGISTER_CREATE_SKILL_NODE(10213, 11) {
    auto node11 = GET_SKILL_NODE(11, PhaseNode_TriggerUpdate);
    if (node11 == nullptr) {
        node11 = new PhaseNode_TriggerUpdate(11, phase);
        CALL_REGISTER_SKILL_NODE(10213, 11, node11)
    }
    if (noInit == true) {
        return node11;
    }
    return node11;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(10213, 13) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetRotation>(PhaseNode_GetLocation::TRIGGER_DONE, 57, PhaseNode_GetRotation::FUNC_DO, &PhaseNode_GetRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(10213, 13) {
    auto node13 = GET_SKILL_NODE(13, PhaseNode_GetLocation);
    if (node13 == nullptr) {
        node13 = new PhaseNode_GetLocation(13, phase);
        node13->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node13->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(10213, 13, node13)
    }
    if (noInit == true) {
        return node13;
    }
    return node13;
}
//--------------------------------------------------------------------------------
// Disable
//
REGISTER_REGISTER_SKILL_NODE(10213, 15) {
    pnode->resizeTrigger(PhaseNode_Disable::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_Disable::TRIGGER_DONE, 101, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(10213, 15) {
    auto node15 = GET_SKILL_NODE(15, PhaseNode_Disable);
    if (node15 == nullptr) {
        node15 = new PhaseNode_Disable(15, phase);
        node15->setTarget(0U);
        node15->setMove(true);
        node15->setSkill(true);
        node15->setShoot(true);
        node15->setTime(1.10f);
        node15->setRotate(true);
        CALL_REGISTER_SKILL_NODE(10213, 15, node15)
    }
    if (noInit == true) {
        return node15;
    }
    return node15;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10213, 23) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_Delay::TRIGGER_DONE, 13, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(10213, 23) {
    auto node23 = GET_SKILL_NODE(23, PhaseNode_Delay);
    if (node23 == nullptr) {
        node23 = new PhaseNode_Delay(23, phase);
        node23->setTime(.50f);
        CALL_REGISTER_SKILL_NODE(10213, 23, node23)
    }
    if (noInit == true) {
        return node23;
    }
    return node23;
}
//--------------------------------------------------------------------------------
// SpawnCollider
//
REGISTER_REGISTER_SKILL_NODE(10213, 25) {
    pnode->resizeTrigger(PhaseNode_SpawnCollider::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_SpawnCollider::TRIGGER_DONE, 153, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_SpawnCollider::TRIGGER_DONE, 29, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10213, 25) {
    auto node25 = GET_SKILL_NODE(25, PhaseNode_SpawnCollider);
    if (node25 == nullptr) {
        node25 = new PhaseNode_SpawnCollider(25, phase);
        node25->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node25->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node25->setMesh("");
        node25->setMeshScale(.00f);
        node25->setEffectID(102132);
        node25->setEffectScale(1.00f);
        node25->setType(PhaseNode_SpawnCollider::SpawnCollider_Type::Circle);
        node25->setTypeParams(0, 11.00f);
        node25->setTime(.30f);
        node25->setPosZ(.00f);
        node25->setreentry(false);
        node25->setCheckPeneSound(false);
        CALL_REGISTER_SKILL_NODE(10213, 25, node25)
    }
    if (noInit == true) {
        return node25;
    }
    auto node13 = GET_SKILL_NODE(13, PhaseNode_GetLocation);
    auto node57 = GET_SKILL_NODE(57, PhaseNode_GetRotation);
    if (node13 != nullptr) node25->setPosX(node13->getX());
    if (node13 != nullptr) node25->setPosY(node13->getY());
    if (node57 != nullptr) node25->setRotation(node57->getAngle());
    return node25;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10213, 29) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_Delay::TRIGGER_DONE, 31, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(10213, 29) {
    auto node29 = GET_SKILL_NODE(29, PhaseNode_Delay);
    if (node29 == nullptr) {
        node29 = new PhaseNode_Delay(29, phase);
        node29->setTime(.83f);
        CALL_REGISTER_SKILL_NODE(10213, 29, node29)
    }
    if (noInit == true) {
        return node29;
    }
    return node29;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(10213, 31) {
}

REGISTER_CREATE_SKILL_NODE(10213, 31) {
    auto node31 = GET_SKILL_NODE(31, PhaseNode_EndPhase);
    if (node31 == nullptr) {
        node31 = new PhaseNode_EndPhase(31, phase);
        node31->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node31->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10213, 31, node31)
    }
    if (noInit == true) {
        return node31;
    }
    return node31;
}
//--------------------------------------------------------------------------------
// GetRotation
//
REGISTER_REGISTER_SKILL_NODE(10213, 57) {
    pnode->resizeTrigger(PhaseNode_GetRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_GetRotation::TRIGGER_DONE, 108, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10213, 57) {
    auto node57 = GET_SKILL_NODE(57, PhaseNode_GetRotation);
    if (node57 == nullptr) {
        node57 = new PhaseNode_GetRotation(57, phase);
        node57->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node57->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(10213, 57, node57)
    }
    if (noInit == true) {
        return node57;
    }
    return node57;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(10213, 91) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlayEffect::TRIGGER_DONE, 23, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10213, 91) {
    auto node91 = GET_SKILL_NODE(91, PhaseNode_PlayEffect);
    if (node91 == nullptr) {
        node91 = new PhaseNode_PlayEffect(91, phase);
        node91->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node91->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node91->setEffectID(102131);
        node91->setChangeColor(false);
        node91->setType(PhaseNode_PlayEffect::PlayEffect_Type::WithTarget);
        node91->getVars().reserve(5);
        node91->getVars().setVariable<uint64_t>(0, 0U);
        node91->getVars().setVariable<std::string>(1, "Effect");
        node91->getVars().setVariable<float>(2, .00f);
        node91->getVars().setVariable<float>(3, .00f);
        node91->getVars().setVariable<float>(4, .00f);
        node91->setRotation(.00f);
        node91->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(10213, 91, node91)
    }
    if (noInit == true) {
        return node91;
    }
    return node91;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(10213, 101) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetRotation>(PhaseNode_GetLocation::TRIGGER_DONE, 103, PhaseNode_GetRotation::FUNC_DO, &PhaseNode_GetRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(10213, 101) {
    auto node101 = GET_SKILL_NODE(101, PhaseNode_GetLocation);
    if (node101 == nullptr) {
        node101 = new PhaseNode_GetLocation(101, phase);
        node101->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node101->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(10213, 101, node101)
    }
    if (noInit == true) {
        return node101;
    }
    return node101;
}
//--------------------------------------------------------------------------------
// GetRotation
//
REGISTER_REGISTER_SKILL_NODE(10213, 103) {
    pnode->resizeTrigger(PhaseNode_GetRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_GetRotation::TRIGGER_DONE, 106, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10213, 103) {
    auto node103 = GET_SKILL_NODE(103, PhaseNode_GetRotation);
    if (node103 == nullptr) {
        node103 = new PhaseNode_GetRotation(103, phase);
        node103->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node103->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(10213, 103, node103)
    }
    if (noInit == true) {
        return node103;
    }
    return node103;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10213, 106) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_PlaySound::TRIGGER_DONE, 91, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(10213, 106) {
    auto node106 = GET_SKILL_NODE(106, PhaseNode_PlaySound);
    if (node106 == nullptr) {
        node106 = new PhaseNode_PlaySound(106, phase);
        node106->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node106->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node106->setSoundID("SE_Hero118_Skill3_P1");
        node106->setTarget(0U);
        node106->setUsePos(false);
        node106->setPosX(.00f);
        node106->setPosY(.00f);
        node106->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10213, 106, node106)
    }
    if (noInit == true) {
        return node106;
    }
    return node106;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10213, 108) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnCollider>(PhaseNode_PlaySound::TRIGGER_DONE, 25, PhaseNode_SpawnCollider::FUNC_DO, &PhaseNode_SpawnCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(10213, 108) {
    auto node108 = GET_SKILL_NODE(108, PhaseNode_PlaySound);
    if (node108 == nullptr) {
        node108 = new PhaseNode_PlaySound(108, phase);
        node108->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node108->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node108->setSoundID("SE_Hero118_Skill3_P2");
        node108->setTarget(0U);
        node108->setUsePos(false);
        node108->setPosX(.00f);
        node108->setPosY(.00f);
        node108->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10213, 108, node108)
    }
    if (noInit == true) {
        return node108;
    }
    return node108;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(10213, 118) {
}

REGISTER_CREATE_SKILL_NODE(10213, 118) {
    auto node118 = GET_SKILL_NODE(118, PhaseNode_AddSkillBuffs);
    if (node118 == nullptr) {
        node118 = new PhaseNode_AddSkillBuffs(118, phase);
        node118->setConfigID({102134,102136});
        CALL_REGISTER_SKILL_NODE(10213, 118, node118)
    }
    if (noInit == true) {
        return node118;
    }
    auto node154 = GET_SKILL_NODE(154, PhaseNode_ActorFilterNewPene);
    auto node123 = GET_SKILL_NODE(123, PhaseNode_GetActorAttribute);
    if (node154 != nullptr) node118->setTarget(node154->getOutput());
    if (node123 != nullptr) node118->setAttribute(node123->getAttribute());
    return node118;
}
//--------------------------------------------------------------------------------
// GetActorAttribute
//
REGISTER_REGISTER_SKILL_NODE(10213, 123) {
    pnode->resizeTrigger(PhaseNode_GetActorAttribute::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Disable>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 15, PhaseNode_Disable::FUNC_DO, &PhaseNode_Disable::Do);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 130, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10213, 123) {
    auto node123 = GET_SKILL_NODE(123, PhaseNode_GetActorAttribute);
    if (node123 == nullptr) {
        node123 = new PhaseNode_GetActorAttribute(123, phase);
        node123->setTarget(0U);
        node123->setType({});
        CALL_REGISTER_SKILL_NODE(10213, 123, node123)
    }
    if (noInit == true) {
        return node123;
    }
    return node123;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10213, 130) {
}

REGISTER_CREATE_SKILL_NODE(10213, 130) {
    auto node130 = GET_SKILL_NODE(130, PhaseNode_PlaySound);
    if (node130 == nullptr) {
        node130 = new PhaseNode_PlaySound(130, phase);
        node130->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node130->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node130->setSoundID("SE_Hero118_Skill3_P1");
        node130->setTarget(0U);
        node130->setUsePos(false);
        node130->setPosX(.00f);
        node130->setPosY(.00f);
        node130->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10213, 130, node130)
    }
    if (noInit == true) {
        return node130;
    }
    return node130;
}
//--------------------------------------------------------------------------------
// AddSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10213, 132) {
}

REGISTER_CREATE_SKILL_NODE(10213, 132) {
    auto node132 = GET_SKILL_NODE(132, PhaseNode_AddSkillBuff);
    if (node132 == nullptr) {
        node132 = new PhaseNode_AddSkillBuff(132, phase);
        node132->setConfigID(102139);
        node132->setConfigIDs({});
        node132->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(10213, 132, node132)
    }
    if (noInit == true) {
        return node132;
    }
    auto node136 = GET_SKILL_NODE(136, PhaseNode_GetActorAttribute);
    if (node136 != nullptr) node132->setAttribute(node136->getAttribute());
    return node132;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10213, 134) {
}

REGISTER_CREATE_SKILL_NODE(10213, 134) {
    auto node134 = GET_SKILL_NODE(134, PhaseNode_PlaySound);
    if (node134 == nullptr) {
        node134 = new PhaseNode_PlaySound(134, phase);
        node134->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node134->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node134->setSoundID("VO_Hero118_Skill_C");
        node134->setTarget(0U);
        node134->setUsePos(false);
        node134->setPosX(.00f);
        node134->setPosY(.00f);
        node134->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10213, 134, node134)
    }
    if (noInit == true) {
        return node134;
    }
    return node134;
}
//--------------------------------------------------------------------------------
// GetActorAttribute
//
REGISTER_REGISTER_SKILL_NODE(10213, 136) {
    pnode->resizeTrigger(PhaseNode_GetActorAttribute::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 123, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(10213, 136) {
    auto node136 = GET_SKILL_NODE(136, PhaseNode_GetActorAttribute);
    if (node136 == nullptr) {
        node136 = new PhaseNode_GetActorAttribute(136, phase);
        node136->setTarget(0U);
        node136->setType({});
        CALL_REGISTER_SKILL_NODE(10213, 136, node136)
    }
    if (noInit == true) {
        return node136;
    }
    return node136;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10213, 138) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_IsInterruptType>(PhaseNode_Detect::TRIGGER_ON, 144, PhaseNode_IsInterruptType::FUNC_DO, &PhaseNode_IsInterruptType::Do);
}

REGISTER_CREATE_SKILL_NODE(10213, 138) {
    auto node138 = GET_SKILL_NODE(138, PhaseNode_Detect);
    if (node138 == nullptr) {
        node138 = new PhaseNode_Detect(138, phase);
        node138->setSelf(0U);
        node138->setEvent("daduan_001");
        node138->setType(PhaseNode_Detect::Detect_Type::Interrupt_Skill);
        node138->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10213, 138, node138)
    }
    if (noInit == true) {
        return node138;
    }
    return node138;
}
//--------------------------------------------------------------------------------
// SwitchToInt
//
REGISTER_REGISTER_SKILL_NODE(10213, 139) {
    pnode->resizeTrigger(4);
    pnode->regTrigger<PhaseNode_EndPhase>(1, 31, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(10213, 139) {
    auto node139 = GET_SKILL_NODE(139, PhaseNode_SwitchToInt);
    if (node139 == nullptr) {
        node139 = new PhaseNode_SwitchToInt(139, phase);
        CALL_REGISTER_SKILL_NODE(10213, 139, node139)
    }
    if (noInit == true) {
        return node139;
    }
    auto variables = node139->getVariables();
    if (variables != nullptr) {
        node139->setSelection(variables->getVariable<int32_t>(Variable_10213_102132));
    }
    return node139;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10213, 141) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_RaiseEvent::TRIGGER_DONE, 150, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10213, 141) {
    auto node141 = GET_SKILL_NODE(141, PhaseNode_RaiseEvent);
    if (node141 == nullptr) {
        node141 = new PhaseNode_RaiseEvent(141, phase);
        node141->setEvent("daduan_001");
        node141->setTarget(0U);
        node141->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node141->setTypeParams(0, 0);
        node141->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10213, 141, node141)
    }
    if (noInit == true) {
        return node141;
    }
    return node141;
}
//--------------------------------------------------------------------------------
// StartPreInput
//
REGISTER_REGISTER_SKILL_NODE(10213, 142) {
    pnode->resizeTrigger(PhaseNode_StartPreInput::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_StartPreInput::TRIGGER_DONE, 146, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10213, 142) {
    auto node142 = GET_SKILL_NODE(142, PhaseNode_StartPreInput);
    if (node142 == nullptr) {
        node142 = new PhaseNode_StartPreInput(142, phase);
        node142->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node142->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node142->setDelayTime(.00f);
        CALL_REGISTER_SKILL_NODE(10213, 142, node142)
    }
    if (noInit == true) {
        return node142;
    }
    return node142;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(10213, 143) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_If::TRIGGER_TRUE, 145, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10213, 143) {
    auto node143 = GET_SKILL_NODE(143, PhaseNode_If);
    if (node143 == nullptr) {
        node143 = new PhaseNode_If(143, phase);
        CALL_REGISTER_SKILL_NODE(10213, 143, node143)
    }
    if (noInit == true) {
        return node143;
    }
    auto variables = node143->getVariables();
    if (variables != nullptr) {
        node143->setCondition(variables->getVariable<bool>(Variable_10213_InterruptAnimat));
    }
    return node143;
}
//--------------------------------------------------------------------------------
// IsInterruptType
//
REGISTER_REGISTER_SKILL_NODE(10213, 144) {
    pnode->resizeTrigger(PhaseNode_IsInterruptType::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SwitchToInt>(PhaseNode_IsInterruptType::TRIGGER_BUFF, 139, PhaseNode_SwitchToInt::FUNC_SWITCH, &PhaseNode_SwitchToInt::Switch);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_POSCHANGE, 143, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTAIM, 143, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTFIRE, 143, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTRELOAD, 143, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_USESKILL, 143, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(10213, 144) {
    auto node144 = GET_SKILL_NODE(144, PhaseNode_IsInterruptType);
    if (node144 == nullptr) {
        node144 = new PhaseNode_IsInterruptType(144, phase);
        node144->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node144->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10213, 144, node144)
    }
    if (noInit == true) {
        return node144;
    }
    auto node138 = GET_SKILL_NODE(138, PhaseNode_Detect);
    if (node138 != nullptr) node144->setType(node138->getVars().getVariable<int32_t>(2));
    return node144;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10213, 145) {
}

REGISTER_CREATE_SKILL_NODE(10213, 145) {
    auto node145 = GET_SKILL_NODE(145, PhaseNode_PlayAnimation);
    if (node145 == nullptr) {
        node145 = new PhaseNode_PlayAnimation(145, phase);
        node145->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node145->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node145->setTarget(0U);
        node145->setAnimation("Idle");
        node145->setParameter("");
        node145->setValue(false);
        CALL_REGISTER_SKILL_NODE(10213, 145, node145)
    }
    if (noInit == true) {
        return node145;
    }
    return node145;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10213, 146) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_Delay::TRIGGER_DONE, 149, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(10213, 146) {
    auto node146 = GET_SKILL_NODE(146, PhaseNode_Delay);
    if (node146 == nullptr) {
        node146 = new PhaseNode_Delay(146, phase);
        node146->setTime(.20f);
        CALL_REGISTER_SKILL_NODE(10213, 146, node146)
    }
    if (noInit == true) {
        return node146;
    }
    return node146;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(10213, 149) {
}

REGISTER_CREATE_SKILL_NODE(10213, 149) {
    auto node149 = GET_SKILL_NODE(149, PhaseNode_SetBool);
    if (node149 == nullptr) {
        node149 = new PhaseNode_SetBool(149, phase);
        node149->setName("InterruptAnimat");
        node149->setValue(true);
        CALL_REGISTER_SKILL_NODE(10213, 149, node149)
    }
    if (noInit == true) {
        return node149;
    }
    return node149;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10213, 150) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StartPreInput>(PhaseNode_RaiseEvent::TRIGGER_DONE, 142, PhaseNode_StartPreInput::FUNC_DO, &PhaseNode_StartPreInput::Do);
}

REGISTER_CREATE_SKILL_NODE(10213, 150) {
    auto node150 = GET_SKILL_NODE(150, PhaseNode_RaiseEvent);
    if (node150 == nullptr) {
        node150 = new PhaseNode_RaiseEvent(150, phase);
        node150->setEvent("Dead_001");
        node150->setTarget(0U);
        node150->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node150->setTypeParams(0, 0);
        node150->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10213, 150, node150)
    }
    if (noInit == true) {
        return node150;
    }
    return node150;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10213, 151) {
}

REGISTER_CREATE_SKILL_NODE(10213, 151) {
    auto node151 = GET_SKILL_NODE(151, PhaseNode_Detect);
    if (node151 == nullptr) {
        node151 = new PhaseNode_Detect(151, phase);
        node151->setSelf(0U);
        node151->setEvent("Dead_001");
        node151->setType(PhaseNode_Detect::Detect_Type::Actor_Dead);
        node151->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10213, 151, node151)
    }
    if (noInit == true) {
        return node151;
    }
    return node151;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(10213, 152) {
}

REGISTER_CREATE_SKILL_NODE(10213, 152) {
    auto node152 = GET_SKILL_NODE(152, PhaseNode_TriggerCheck);
    if (node152 == nullptr) {
        node152 = new PhaseNode_TriggerCheck(152, phase);
        auto node11 = GET_SKILL_NODE(11, PhaseNode_TriggerUpdate);
        if (node11 != nullptr) node11->addTriggerCheck(node152);
        
        CALL_REGISTER_SKILL_NODE(10213, 152, node152)
    }
    if (noInit == true) {
        return node152;
    }
    auto node153 = GET_SKILL_NODE(153, PhaseNode_CreateTriggerNewPene);
    if (node153 != nullptr) node152->setTrigger(0, node153->getTriggerID());
    return node152;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(10213, 153) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 152, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 154, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(10213, 153) {
    auto node153 = GET_SKILL_NODE(153, PhaseNode_CreateTriggerNewPene);
    if (node153 == nullptr) {
        node153 = new PhaseNode_CreateTriggerNewPene(153, phase);
        node153->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::In);
        node153->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node153->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Enemy);
        node153->setOnHero(true);
        node153->setOnMinion(true);
        node153->setOnDestruct(false);
        node153->setOnShield(true);
        CALL_REGISTER_SKILL_NODE(10213, 153, node153)
    }
    if (noInit == true) {
        return node153;
    }
    auto node25 = GET_SKILL_NODE(25, PhaseNode_SpawnCollider);
    if (node25 != nullptr) node153->setColliderID(node25->getColliderID());
    return node153;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(10213, 154) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 118, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
}

REGISTER_CREATE_SKILL_NODE(10213, 154) {
    auto node154 = GET_SKILL_NODE(154, PhaseNode_ActorFilterNewPene);
    if (node154 == nullptr) {
        node154 = new PhaseNode_ActorFilterNewPene(154, phase);
        node154->setHero(true);
        node154->setMinion(true);
        node154->setDestruct(false);
        node154->setShield(true);
        node154->setTotalCount(0);
        node154->setPerCount(1);
        CALL_REGISTER_SKILL_NODE(10213, 154, node154)
    }
    if (noInit == true) {
        return node154;
    }
    auto node153 = GET_SKILL_NODE(153, PhaseNode_CreateTriggerNewPene);
    if (node153 != nullptr) node154->setInput(node153->getOther());
    return node154;
}

//--------------------------------------------------------------------------------
// SkillCreator_10213
//
class SkillCreator_10213 : public SkillCreator {
public:
    SkillCreator_10213() {}
    virtual ~SkillCreator_10213() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_10213

//--------------------------------------------------------------------------------
// SkillPhase_10213
//
class SkillPhase_10213 : public SkillPhase {
public:
    SkillPhase_10213(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_10213() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(10213, 2) // StartPhase
        CASE_CREATE_SKILL_NODE(10213, 4) // ResetCD
        CASE_CREATE_SKILL_NODE(10213, 6) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10213, 11) // TriggerUpdate
        CASE_CREATE_SKILL_NODE(10213, 13) // GetLocation
        CASE_CREATE_SKILL_NODE(10213, 15) // Disable
        CASE_CREATE_SKILL_NODE(10213, 23) // Delay
        CASE_CREATE_SKILL_NODE(10213, 25) // SpawnCollider
        CASE_CREATE_SKILL_NODE(10213, 29) // Delay
        CASE_CREATE_SKILL_NODE(10213, 31) // EndPhase
        CASE_CREATE_SKILL_NODE(10213, 57) // GetRotation
        CASE_CREATE_SKILL_NODE(10213, 91) // PlayEffect
        CASE_CREATE_SKILL_NODE(10213, 101) // GetLocation
        CASE_CREATE_SKILL_NODE(10213, 103) // GetRotation
        CASE_CREATE_SKILL_NODE(10213, 106) // PlaySound
        CASE_CREATE_SKILL_NODE(10213, 108) // PlaySound
        CASE_CREATE_SKILL_NODE(10213, 118) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(10213, 123) // GetActorAttribute
        CASE_CREATE_SKILL_NODE(10213, 130) // PlaySound
        CASE_CREATE_SKILL_NODE(10213, 132) // AddSkillBuff
        CASE_CREATE_SKILL_NODE(10213, 134) // PlaySound
        CASE_CREATE_SKILL_NODE(10213, 136) // GetActorAttribute
        CASE_CREATE_SKILL_NODE(10213, 138) // Detect
        CASE_CREATE_SKILL_NODE(10213, 139) // SwitchToInt
        CASE_CREATE_SKILL_NODE(10213, 141) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10213, 142) // StartPreInput
        CASE_CREATE_SKILL_NODE(10213, 143) // If
        CASE_CREATE_SKILL_NODE(10213, 144) // IsInterruptType
        CASE_CREATE_SKILL_NODE(10213, 145) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10213, 146) // Delay
        CASE_CREATE_SKILL_NODE(10213, 149) // SetBool
        CASE_CREATE_SKILL_NODE(10213, 150) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10213, 151) // Detect
        CASE_CREATE_SKILL_NODE(10213, 152) // TriggerCheck
        CASE_CREATE_SKILL_NODE(10213, 153) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(10213, 154) // ActorFilterNewPene
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_10213

SkillLogic* SkillCreator_10213::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //设置变量
    Variable_10213_102132 = logic->getVariables().setVariable<int32_t>("102132", 1);
    Variable_10213_InterruptAnimat = logic->getVariables().setVariable<bool>("InterruptAnimat");
    //创建阶段phase
    auto phase = new SkillPhase_10213(1, logic, 3);
    //设置phase执行器
    phase->setRunPhaseNode(1, 2);
    phase->setRunPhaseNode(2, 11);
    phase->setDetectPhaseNode(3, 138);
    phase->setDetectPhaseNode(3, 151);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_10213::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
