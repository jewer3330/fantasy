#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

#include "skill_psnode_actorfilternewpene.h"
#include "skill_psnode_addskillbuff.h"
#include "skill_psnode_addskillbuffs.h"
#include "skill_psnode_attachto.h"
#include "skill_psnode_createtriggernewpene.h"
#include "skill_psnode_delay.h"
#include "skill_psnode_destroycollider.h"
#include "skill_psnode_detect.h"
#include "skill_psnode_disable.h"
#include "skill_psnode_endphase.h"
#include "skill_psnode_filterself.h"
#include "skill_psnode_getactorattribute.h"
#include "skill_psnode_getinputlocation.h"
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
#include "skill_psnode_removeskillbuff.h"
#include "skill_psnode_resetcd.h"
#include "skill_psnode_setbool.h"
#include "skill_psnode_setint.h"
#include "skill_psnode_spawncollider.h"
#include "skill_psnode_startphase.h"
#include "skill_psnode_startpreinput.h"
#include "skill_psnode_switchtoint.h"
#include "skill_psnode_triggercheck.h"
#include "skill_psnode_triggerupdate.h"

namespace pvp {

//变量声明
uint64_t Variable_10212_102122 = 0;
uint64_t Variable_10212_InterruptAnimat = 0;
//--------------------------------------------------------------------------------
// StartPhase
//
REGISTER_REGISTER_SKILL_NODE(10212, 2) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_StartPhase::TRIGGER_START, 4, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(10212, 2) {
    auto node2 = GET_SKILL_NODE(2, PhaseNode_StartPhase);
    if (node2 == nullptr) {
        node2 = new PhaseNode_StartPhase(2, phase);
        CALL_REGISTER_SKILL_NODE(10212, 2, node2)
    }
    if (noInit == true) {
        return node2;
    }
    return node2;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(10212, 4) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_ResetCD::TRIGGER_DONE, 6, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10212, 4) {
    auto node4 = GET_SKILL_NODE(4, PhaseNode_ResetCD);
    if (node4 == nullptr) {
        node4 = new PhaseNode_ResetCD(4, phase);
        node4->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node4->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node4->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(10212, 4, node4)
    }
    if (noInit == true) {
        return node4;
    }
    return node4;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10212, 6) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_PlayAnimation::TRIGGER_DONE, 246, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_PlayAnimation::TRIGGER_DONE, 289, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10212, 6) {
    auto node6 = GET_SKILL_NODE(6, PhaseNode_PlayAnimation);
    if (node6 == nullptr) {
        node6 = new PhaseNode_PlayAnimation(6, phase);
        node6->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node6->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node6->setTarget(0U);
        node6->setAnimation("Skill2S1");
        node6->setParameter("SkillArmBusy");
        node6->setValue(true);
        CALL_REGISTER_SKILL_NODE(10212, 6, node6)
    }
    if (noInit == true) {
        return node6;
    }
    return node6;
}
//--------------------------------------------------------------------------------
// Disable
//
REGISTER_REGISTER_SKILL_NODE(10212, 20) {
    pnode->resizeTrigger(PhaseNode_Disable::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_Disable::TRIGGER_DONE, 23, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_Disable::TRIGGER_DONE, 253, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10212, 20) {
    auto node20 = GET_SKILL_NODE(20, PhaseNode_Disable);
    if (node20 == nullptr) {
        node20 = new PhaseNode_Disable(20, phase);
        node20->setTarget(0U);
        node20->setMove(false);
        node20->setSkill(true);
        node20->setShoot(true);
        node20->setTime(.50f);
        node20->setRotate(true);
        CALL_REGISTER_SKILL_NODE(10212, 20, node20)
    }
    if (noInit == true) {
        return node20;
    }
    return node20;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10212, 23) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_Delay::TRIGGER_DONE, 103, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(10212, 23) {
    auto node23 = GET_SKILL_NODE(23, PhaseNode_Delay);
    if (node23 == nullptr) {
        node23 = new PhaseNode_Delay(23, phase);
        node23->setTime(.20f);
        CALL_REGISTER_SKILL_NODE(10212, 23, node23)
    }
    if (noInit == true) {
        return node23;
    }
    return node23;
}
//--------------------------------------------------------------------------------
// SpawnCollider
//
REGISTER_REGISTER_SKILL_NODE(10212, 25) {
    pnode->resizeTrigger(PhaseNode_SpawnCollider::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnCollider>(PhaseNode_SpawnCollider::TRIGGER_DONE, 259, PhaseNode_SpawnCollider::FUNC_DO, &PhaseNode_SpawnCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(10212, 25) {
    auto node25 = GET_SKILL_NODE(25, PhaseNode_SpawnCollider);
    if (node25 == nullptr) {
        node25 = new PhaseNode_SpawnCollider(25, phase);
        node25->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node25->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node25->setMesh("");
        node25->setMeshScale(.00f);
        node25->setEffectID(0);
        node25->setEffectScale(.00f);
        node25->setType(PhaseNode_SpawnCollider::SpawnCollider_Type::Circle);
        node25->setTypeParams(0, .20f);
        node25->setTime(.00f);
        node25->setreentry(false);
        node25->setCheckPeneSound(true);
        CALL_REGISTER_SKILL_NODE(10212, 25, node25)
    }
    if (noInit == true) {
        return node25;
    }
    auto node80 = GET_SKILL_NODE(80, PhaseNode_OffsetCalculate);
    if (node80 != nullptr) node25->setPosX(node80->getOutPosX());
    if (node80 != nullptr) node25->setPosY(node80->getOutPosY());
    if (node80 != nullptr) node25->setPosZ(node80->getOutPosZ());
    if (node80 != nullptr) node25->setRotation(node80->getOutRotation());
    return node25;
}
//--------------------------------------------------------------------------------
// SpawnCollider
//
REGISTER_REGISTER_SKILL_NODE(10212, 34) {
    pnode->resizeTrigger(PhaseNode_SpawnCollider::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_SpawnCollider::TRIGGER_DONE, 283, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_SpawnCollider::TRIGGER_DONE, 239, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_SpawnCollider::TRIGGER_DONE, 142, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
    pnode->regTrigger<PhaseNode_SpawnCollider>(PhaseNode_SpawnCollider::TRIGGER_DONE, 158, PhaseNode_SpawnCollider::FUNC_DO, &PhaseNode_SpawnCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(10212, 34) {
    auto node34 = GET_SKILL_NODE(34, PhaseNode_SpawnCollider);
    if (node34 == nullptr) {
        node34 = new PhaseNode_SpawnCollider(34, phase);
        node34->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node34->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node34->setMesh("");
        node34->setMeshScale(.00f);
        node34->setEffectID(102123);
        node34->setEffectScale(1.00f);
        node34->setType(PhaseNode_SpawnCollider::SpawnCollider_Type::Circle);
        node34->setTypeParams(0, 5.00f);
        node34->setTime(5.00f);
        node34->setPosZ(.00f);
        node34->setRotation(.00f);
        node34->setreentry(false);
        node34->setCheckPeneSound(false);
        CALL_REGISTER_SKILL_NODE(10212, 34, node34)
    }
    if (noInit == true) {
        return node34;
    }
    auto node84 = GET_SKILL_NODE(84, PhaseNode_GetLocation);
    if (node84 != nullptr) node34->setPosX(node84->getX());
    if (node84 != nullptr) node34->setPosY(node84->getY());
    return node34;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(10212, 41) {
}

REGISTER_CREATE_SKILL_NODE(10212, 41) {
    auto node41 = GET_SKILL_NODE(41, PhaseNode_AddSkillBuffs);
    if (node41 == nullptr) {
        node41 = new PhaseNode_AddSkillBuffs(41, phase);
        node41->setConfigID({102122,102123,102138});
        CALL_REGISTER_SKILL_NODE(10212, 41, node41)
    }
    if (noInit == true) {
        return node41;
    }
    auto node284 = GET_SKILL_NODE(284, PhaseNode_ActorFilterNewPene);
    auto node246 = GET_SKILL_NODE(246, PhaseNode_GetActorAttribute);
    if (node284 != nullptr) node41->setTarget(node284->getOutput());
    if (node246 != nullptr) node41->setAttribute(node246->getAttribute());
    return node41;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10212, 50) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RemoveSkillBuff>(PhaseNode_Delay::TRIGGER_DONE, 235, PhaseNode_RemoveSkillBuff::FUNC_REMOVE, &PhaseNode_RemoveSkillBuff::Remove);
}

REGISTER_CREATE_SKILL_NODE(10212, 50) {
    auto node50 = GET_SKILL_NODE(50, PhaseNode_Delay);
    if (node50 == nullptr) {
        node50 = new PhaseNode_Delay(50, phase);
        node50->setTime(5.00f);
        CALL_REGISTER_SKILL_NODE(10212, 50, node50)
    }
    if (noInit == true) {
        return node50;
    }
    return node50;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(10212, 54) {
}

REGISTER_CREATE_SKILL_NODE(10212, 54) {
    auto node54 = GET_SKILL_NODE(54, PhaseNode_EndPhase);
    if (node54 == nullptr) {
        node54 = new PhaseNode_EndPhase(54, phase);
        node54->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node54->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10212, 54, node54)
    }
    if (noInit == true) {
        return node54;
    }
    return node54;
}
//--------------------------------------------------------------------------------
// TriggerUpdate
//
REGISTER_REGISTER_SKILL_NODE(10212, 56) {
}

REGISTER_CREATE_SKILL_NODE(10212, 56) {
    auto node56 = GET_SKILL_NODE(56, PhaseNode_TriggerUpdate);
    if (node56 == nullptr) {
        node56 = new PhaseNode_TriggerUpdate(56, phase);
        CALL_REGISTER_SKILL_NODE(10212, 56, node56)
    }
    if (noInit == true) {
        return node56;
    }
    return node56;
}
//--------------------------------------------------------------------------------
// OffsetCalculate
//
REGISTER_REGISTER_SKILL_NODE(10212, 80) {
    pnode->resizeTrigger(PhaseNode_OffsetCalculate::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnCollider>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 25, PhaseNode_SpawnCollider::FUNC_DO, &PhaseNode_SpawnCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(10212, 80) {
    auto node80 = GET_SKILL_NODE(80, PhaseNode_OffsetCalculate);
    if (node80 == nullptr) {
        node80 = new PhaseNode_OffsetCalculate(80, phase);
        node80->setPosZ(.00f);
        node80->setOffsetX(.00f);
        node80->setOffsetY(1.30f);
        node80->setOffsetZ(2.30f);
        node80->setRotOffset(.00f);
        CALL_REGISTER_SKILL_NODE(10212, 80, node80)
    }
    if (noInit == true) {
        return node80;
    }
    auto node103 = GET_SKILL_NODE(103, PhaseNode_GetLocation);
    auto node281 = GET_SKILL_NODE(281, PhaseNode_GetLineRotation);
    if (node103 != nullptr) node80->setPosX(node103->getX());
    if (node103 != nullptr) node80->setPosY(node103->getY());
    if (node281 != nullptr) node80->setRotation(node281->getRotation());
    return node80;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(10212, 84) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_DestroyCollider>(PhaseNode_GetLocation::TRIGGER_DONE, 87, PhaseNode_DestroyCollider::FUNC_DO, &PhaseNode_DestroyCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(10212, 84) {
    auto node84 = GET_SKILL_NODE(84, PhaseNode_GetLocation);
    if (node84 == nullptr) {
        node84 = new PhaseNode_GetLocation(84, phase);
        node84->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        CALL_REGISTER_SKILL_NODE(10212, 84, node84)
    }
    if (noInit == true) {
        return node84;
    }
    auto node25 = GET_SKILL_NODE(25, PhaseNode_SpawnCollider);
    if (node25 != nullptr) node84->setTarget(node25->getColliderID());
    return node84;
}
//--------------------------------------------------------------------------------
// DestroyCollider
//
REGISTER_REGISTER_SKILL_NODE(10212, 87) {
    pnode->resizeTrigger(PhaseNode_DestroyCollider::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_DestroyCollider>(PhaseNode_DestroyCollider::TRIGGER_DONE, 266, PhaseNode_DestroyCollider::FUNC_DO, &PhaseNode_DestroyCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(10212, 87) {
    auto node87 = GET_SKILL_NODE(87, PhaseNode_DestroyCollider);
    if (node87 == nullptr) {
        node87 = new PhaseNode_DestroyCollider(87, phase);
        CALL_REGISTER_SKILL_NODE(10212, 87, node87)
    }
    if (noInit == true) {
        return node87;
    }
    auto node25 = GET_SKILL_NODE(25, PhaseNode_SpawnCollider);
    if (node25 != nullptr) node87->setColliderID(node25->getColliderID());
    return node87;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(10212, 103) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetInputLocation>(PhaseNode_GetLocation::TRIGGER_DONE, 279, PhaseNode_GetInputLocation::FUNC_DO, &PhaseNode_GetInputLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(10212, 103) {
    auto node103 = GET_SKILL_NODE(103, PhaseNode_GetLocation);
    if (node103 == nullptr) {
        node103 = new PhaseNode_GetLocation(103, phase);
        node103->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node103->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(10212, 103, node103)
    }
    if (noInit == true) {
        return node103;
    }
    return node103;
}
//--------------------------------------------------------------------------------
// MoveNewPene
//
REGISTER_REGISTER_SKILL_NODE(10212, 128) {
    pnode->resizeTrigger(PhaseNode_MoveNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_MoveNewPene::TRIGGER_BLOCKBYSHIELD, 84, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_MoveNewPene::TRIGGER_BLOCKBYWALL, 84, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_MoveNewPene::TRIGGER_DONE, 84, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_MoveNewPene::TRIGGER_STARTMOVE, 273, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10212, 128) {
    auto node128 = GET_SKILL_NODE(128, PhaseNode_MoveNewPene);
    if (node128 == nullptr) {
        node128 = new PhaseNode_MoveNewPene(128, phase);
        node128->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node128->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node128->setPeneType(PhaseNode_MoveNewPene::MoveNewPene_PeneType::Projectile);
        node128->setPeneValue(25);
        node128->setType(PhaseNode_MoveNewPene::MoveNewPene_Type::Jump);
        node128->getVars().reserve(4);
        node128->getVars().setVariable<float>(0, .00f);
        node128->getVars().setVariable<float>(1, .00f);
        node128->getVars().setVariable<float>(2, 3.00f);
        node128->getVars().setVariable<float>(3, .30f);
        node128->setreentry(false);
        node128->setStopWhenFail(true);
        node128->setCheckFaction(PhaseNode_MoveNewPene::MoveNewPene_CheckFaction::Enemy);
        CALL_REGISTER_SKILL_NODE(10212, 128, node128)
    }
    if (noInit == true) {
        return node128;
    }
    auto node25 = GET_SKILL_NODE(25, PhaseNode_SpawnCollider);
    auto node279 = GET_SKILL_NODE(279, PhaseNode_GetInputLocation);
    if (node25 != nullptr) node128->setTarget(node25->getColliderID());
    if (node279 != nullptr) node128->getVars().setVariable<float>(0, node279->getX());
    if (node279 != nullptr) node128->getVars().setVariable<float>(1, node279->getY());
    return node128;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(10212, 130) {
}

REGISTER_CREATE_SKILL_NODE(10212, 130) {
    auto node130 = GET_SKILL_NODE(130, PhaseNode_PlayEffect);
    if (node130 == nullptr) {
        node130 = new PhaseNode_PlayEffect(130, phase);
        node130->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node130->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node130->setEffectID(102121);
        node130->setChangeColor(false);
        node130->setType(PhaseNode_PlayEffect::PlayEffect_Type::WithTarget);
        node130->getVars().reserve(5);
        node130->getVars().setVariable<uint64_t>(0, 0U);
        node130->getVars().setVariable<std::string>(1, "Effect");
        node130->getVars().setVariable<float>(2, .00f);
        node130->getVars().setVariable<float>(3, .00f);
        node130->getVars().setVariable<float>(4, .00f);
        node130->setRotation(.00f);
        node130->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(10212, 130, node130)
    }
    if (noInit == true) {
        return node130;
    }
    return node130;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10212, 138) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_PlaySound::TRIGGER_DONE, 130, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(10212, 138) {
    auto node138 = GET_SKILL_NODE(138, PhaseNode_PlaySound);
    if (node138 == nullptr) {
        node138 = new PhaseNode_PlaySound(138, phase);
        node138->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node138->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node138->setSoundID("SE_Hero118_Skill2_P1_1");
        node138->setTarget(0U);
        node138->setUsePos(false);
        node138->setPosX(.00f);
        node138->setPosY(.00f);
        node138->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10212, 138, node138)
    }
    if (noInit == true) {
        return node138;
    }
    return node138;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10212, 142) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlaySound::TRIGGER_DONE, 50, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10212, 142) {
    auto node142 = GET_SKILL_NODE(142, PhaseNode_PlaySound);
    if (node142 == nullptr) {
        node142 = new PhaseNode_PlaySound(142, phase);
        node142->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node142->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node142->setSoundID("SE_Hero118_Skill2_P2_1");
        node142->setTarget(0U);
        node142->setUsePos(false);
        node142->setPosX(.00f);
        node142->setPosY(.00f);
        node142->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10212, 142, node142)
    }
    if (noInit == true) {
        return node142;
    }
    return node142;
}
//--------------------------------------------------------------------------------
// SpawnCollider
//
REGISTER_REGISTER_SKILL_NODE(10212, 158) {
    pnode->resizeTrigger(PhaseNode_SpawnCollider::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_SpawnCollider::TRIGGER_DONE, 161, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_SpawnCollider::TRIGGER_DONE, 178, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_SpawnCollider::TRIGGER_DONE, 186, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_SpawnCollider::TRIGGER_DONE, 226, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10212, 158) {
    auto node158 = GET_SKILL_NODE(158, PhaseNode_SpawnCollider);
    if (node158 == nullptr) {
        node158 = new PhaseNode_SpawnCollider(158, phase);
        node158->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node158->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node158->setMesh("");
        node158->setMeshScale(.00f);
        node158->setEffectID(0);
        node158->setEffectScale(1.00f);
        node158->setType(PhaseNode_SpawnCollider::SpawnCollider_Type::Circle);
        node158->setTypeParams(0, 5.00f);
        node158->setTime(5.00f);
        node158->setPosZ(.00f);
        node158->setRotation(.00f);
        node158->setreentry(false);
        node158->setCheckPeneSound(false);
        CALL_REGISTER_SKILL_NODE(10212, 158, node158)
    }
    if (noInit == true) {
        return node158;
    }
    auto node84 = GET_SKILL_NODE(84, PhaseNode_GetLocation);
    if (node84 != nullptr) node158->setPosX(node84->getX());
    if (node84 != nullptr) node158->setPosY(node84->getY());
    return node158;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(10212, 161) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 163, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_FilterSelf>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 242, PhaseNode_FilterSelf::FUNC_DO, &PhaseNode_FilterSelf::Do);
}

REGISTER_CREATE_SKILL_NODE(10212, 161) {
    auto node161 = GET_SKILL_NODE(161, PhaseNode_CreateTriggerNewPene);
    if (node161 == nullptr) {
        node161 = new PhaseNode_CreateTriggerNewPene(161, phase);
        node161->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::Tick);
        node161->setTypeParams(0, .25f);
        node161->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node161->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Friend);
        node161->setOnHero(true);
        node161->setOnMinion(false);
        node161->setOnDestruct(false);
        node161->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(10212, 161, node161)
    }
    if (noInit == true) {
        return node161;
    }
    auto node158 = GET_SKILL_NODE(158, PhaseNode_SpawnCollider);
    if (node158 != nullptr) node161->setColliderID(node158->getColliderID());
    return node161;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(10212, 163) {
}

REGISTER_CREATE_SKILL_NODE(10212, 163) {
    auto node163 = GET_SKILL_NODE(163, PhaseNode_TriggerCheck);
    if (node163 == nullptr) {
        node163 = new PhaseNode_TriggerCheck(163, phase);
        auto node56 = GET_SKILL_NODE(56, PhaseNode_TriggerUpdate);
        if (node56 != nullptr) node56->addTriggerCheck(node163);
        
        CALL_REGISTER_SKILL_NODE(10212, 163, node163)
    }
    if (noInit == true) {
        return node163;
    }
    auto node161 = GET_SKILL_NODE(161, PhaseNode_CreateTriggerNewPene);
    if (node161 != nullptr) node163->setTrigger(0, node161->getTriggerID());
    return node163;
}
//--------------------------------------------------------------------------------
// AddSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10212, 168) {
}

REGISTER_CREATE_SKILL_NODE(10212, 168) {
    auto node168 = GET_SKILL_NODE(168, PhaseNode_AddSkillBuff);
    if (node168 == nullptr) {
        node168 = new PhaseNode_AddSkillBuff(168, phase);
        node168->setConfigID(0);
        node168->setConfigIDs({102124,102126,102142});
        CALL_REGISTER_SKILL_NODE(10212, 168, node168)
    }
    if (noInit == true) {
        return node168;
    }
    auto node242 = GET_SKILL_NODE(242, PhaseNode_FilterSelf);
    auto node246 = GET_SKILL_NODE(246, PhaseNode_GetActorAttribute);
    if (node242 != nullptr) node168->setTarget(node242->getSelfTarget());
    if (node246 != nullptr) node168->setAttribute(node246->getAttribute());
    return node168;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10212, 178) {
}

REGISTER_CREATE_SKILL_NODE(10212, 178) {
    auto node178 = GET_SKILL_NODE(178, PhaseNode_RaiseEvent);
    if (node178 == nullptr) {
        node178 = new PhaseNode_RaiseEvent(178, phase);
        node178->setEvent("211");
        node178->setTarget(0U);
        node178->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node178->setTypeParams(0, 0);
        node178->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10212, 178, node178)
    }
    if (noInit == true) {
        return node178;
    }
    return node178;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10212, 181) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuff>(PhaseNode_Detect::TRIGGER_ON, 218, PhaseNode_AddSkillBuff::FUNC_ADD, &PhaseNode_AddSkillBuff::Add);
}

REGISTER_CREATE_SKILL_NODE(10212, 181) {
    auto node181 = GET_SKILL_NODE(181, PhaseNode_Detect);
    if (node181 == nullptr) {
        node181 = new PhaseNode_Detect(181, phase);
        node181->setSelf(0U);
        node181->setEvent("211");
        node181->setType(PhaseNode_Detect::Detect_Type::Start_Skill);
        node181->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10212, 181, node181)
    }
    if (noInit == true) {
        return node181;
    }
    return node181;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10212, 183) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuff>(PhaseNode_Detect::TRIGGER_ON, 215, PhaseNode_AddSkillBuff::FUNC_ADD, &PhaseNode_AddSkillBuff::Add);
}

REGISTER_CREATE_SKILL_NODE(10212, 183) {
    auto node183 = GET_SKILL_NODE(183, PhaseNode_Detect);
    if (node183 == nullptr) {
        node183 = new PhaseNode_Detect(183, phase);
        node183->setSelf(0U);
        node183->setEvent("212");
        node183->setType(PhaseNode_Detect::Detect_Type::Start_Fire);
        node183->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10212, 183, node183)
    }
    if (noInit == true) {
        return node183;
    }
    return node183;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10212, 186) {
}

REGISTER_CREATE_SKILL_NODE(10212, 186) {
    auto node186 = GET_SKILL_NODE(186, PhaseNode_RaiseEvent);
    if (node186 == nullptr) {
        node186 = new PhaseNode_RaiseEvent(186, phase);
        node186->setEvent("212");
        node186->setTarget(0U);
        node186->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node186->setTypeParams(0, 0);
        node186->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10212, 186, node186)
    }
    if (noInit == true) {
        return node186;
    }
    return node186;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10212, 205) {
}

REGISTER_CREATE_SKILL_NODE(10212, 205) {
    auto node205 = GET_SKILL_NODE(205, PhaseNode_PlayAnimation);
    if (node205 == nullptr) {
        node205 = new PhaseNode_PlayAnimation(205, phase);
        node205->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node205->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node205->setTarget(0U);
        node205->setAnimation("");
        node205->setParameter("Run2");
        node205->setValue(true);
        CALL_REGISTER_SKILL_NODE(10212, 205, node205)
    }
    if (noInit == true) {
        return node205;
    }
    return node205;
}
//--------------------------------------------------------------------------------
// AddSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10212, 215) {
}

REGISTER_CREATE_SKILL_NODE(10212, 215) {
    auto node215 = GET_SKILL_NODE(215, PhaseNode_AddSkillBuff);
    if (node215 == nullptr) {
        node215 = new PhaseNode_AddSkillBuff(215, phase);
        node215->setConfigID(102129);
        node215->setConfigIDs({});
        node215->setTarget(0U);
        node215->setAttribute({{}});
        CALL_REGISTER_SKILL_NODE(10212, 215, node215)
    }
    if (noInit == true) {
        return node215;
    }
    return node215;
}
//--------------------------------------------------------------------------------
// AddSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10212, 218) {
}

REGISTER_CREATE_SKILL_NODE(10212, 218) {
    auto node218 = GET_SKILL_NODE(218, PhaseNode_AddSkillBuff);
    if (node218 == nullptr) {
        node218 = new PhaseNode_AddSkillBuff(218, phase);
        node218->setConfigID(102128);
        node218->setConfigIDs({});
        node218->setTarget(0U);
        node218->setAttribute({{}});
        CALL_REGISTER_SKILL_NODE(10212, 218, node218)
    }
    if (noInit == true) {
        return node218;
    }
    return node218;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10212, 223) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RemoveSkillBuff>(PhaseNode_Detect::TRIGGER_ON, 228, PhaseNode_RemoveSkillBuff::FUNC_REMOVE, &PhaseNode_RemoveSkillBuff::Remove);
}

REGISTER_CREATE_SKILL_NODE(10212, 223) {
    auto node223 = GET_SKILL_NODE(223, PhaseNode_Detect);
    if (node223 == nullptr) {
        node223 = new PhaseNode_Detect(223, phase);
        node223->setSelf(0U);
        node223->setEvent("213");
        node223->setType(PhaseNode_Detect::Detect_Type::Hold_Fire);
        node223->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10212, 223, node223)
    }
    if (noInit == true) {
        return node223;
    }
    return node223;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10212, 226) {
}

REGISTER_CREATE_SKILL_NODE(10212, 226) {
    auto node226 = GET_SKILL_NODE(226, PhaseNode_RaiseEvent);
    if (node226 == nullptr) {
        node226 = new PhaseNode_RaiseEvent(226, phase);
        node226->setEvent("213");
        node226->setTarget(0U);
        node226->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node226->setTypeParams(0, 0);
        node226->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10212, 226, node226)
    }
    if (noInit == true) {
        return node226;
    }
    return node226;
}
//--------------------------------------------------------------------------------
// RemoveSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10212, 228) {
    pnode->resizeTrigger(PhaseNode_RemoveSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuff>(PhaseNode_RemoveSkillBuff::TRIGGER_DONE, 218, PhaseNode_AddSkillBuff::FUNC_ADD, &PhaseNode_AddSkillBuff::Add);
}

REGISTER_CREATE_SKILL_NODE(10212, 228) {
    auto node228 = GET_SKILL_NODE(228, PhaseNode_RemoveSkillBuff);
    if (node228 == nullptr) {
        node228 = new PhaseNode_RemoveSkillBuff(228, phase);
        node228->setBuffID(0U);
        node228->setBuffIDs({});
        node228->setConfigID(102129);
        node228->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(10212, 228, node228)
    }
    if (noInit == true) {
        return node228;
    }
    return node228;
}
//--------------------------------------------------------------------------------
// RemoveSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10212, 235) {
    pnode->resizeTrigger(PhaseNode_RemoveSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RemoveSkillBuff>(PhaseNode_RemoveSkillBuff::TRIGGER_DONE, 237, PhaseNode_RemoveSkillBuff::FUNC_REMOVE, &PhaseNode_RemoveSkillBuff::Remove);
}

REGISTER_CREATE_SKILL_NODE(10212, 235) {
    auto node235 = GET_SKILL_NODE(235, PhaseNode_RemoveSkillBuff);
    if (node235 == nullptr) {
        node235 = new PhaseNode_RemoveSkillBuff(235, phase);
        node235->setBuffID(0U);
        node235->setBuffIDs({});
        node235->setConfigID(102128);
        node235->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(10212, 235, node235)
    }
    if (noInit == true) {
        return node235;
    }
    return node235;
}
//--------------------------------------------------------------------------------
// RemoveSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10212, 237) {
    pnode->resizeTrigger(PhaseNode_RemoveSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_RemoveSkillBuff::TRIGGER_DONE, 54, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(10212, 237) {
    auto node237 = GET_SKILL_NODE(237, PhaseNode_RemoveSkillBuff);
    if (node237 == nullptr) {
        node237 = new PhaseNode_RemoveSkillBuff(237, phase);
        node237->setBuffID(0U);
        node237->setBuffIDs({});
        node237->setConfigID(102129);
        node237->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(10212, 237, node237)
    }
    if (noInit == true) {
        return node237;
    }
    return node237;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(10212, 239) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_PlayEffect::TRIGGER_DONE, 255, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10212, 239) {
    auto node239 = GET_SKILL_NODE(239, PhaseNode_PlayEffect);
    if (node239 == nullptr) {
        node239 = new PhaseNode_PlayEffect(239, phase);
        node239->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node239->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node239->setEffectID(102125);
        node239->setChangeColor(true);
        node239->setType(PhaseNode_PlayEffect::PlayEffect_Type::WithTarget);
        node239->getVars().reserve(5);
        node239->getVars().setVariable<uint64_t>(0, 0U);
        node239->getVars().setVariable<std::string>(1, "");
        node239->getVars().setVariable<float>(2, .00f);
        node239->getVars().setVariable<float>(3, .00f);
        node239->getVars().setVariable<float>(4, .00f);
        node239->setRotation(.00f);
        node239->setScale(.00f);
        CALL_REGISTER_SKILL_NODE(10212, 239, node239)
    }
    if (noInit == true) {
        return node239;
    }
    auto node34 = GET_SKILL_NODE(34, PhaseNode_SpawnCollider);
    if (node34 != nullptr) node239->getVars().setVariable<uint64_t>(0, node34->getColliderID());
    return node239;
}
//--------------------------------------------------------------------------------
// FilterSelf
//
REGISTER_REGISTER_SKILL_NODE(10212, 242) {
    pnode->resizeTrigger(PhaseNode_FilterSelf::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuff>(PhaseNode_FilterSelf::TRIGGER_HAVESELF, 168, PhaseNode_AddSkillBuff::FUNC_ADD, &PhaseNode_AddSkillBuff::Add);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_FilterSelf::TRIGGER_HAVESELF, 205, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10212, 242) {
    auto node242 = GET_SKILL_NODE(242, PhaseNode_FilterSelf);
    if (node242 == nullptr) {
        node242 = new PhaseNode_FilterSelf(242, phase);
        CALL_REGISTER_SKILL_NODE(10212, 242, node242)
    }
    if (noInit == true) {
        return node242;
    }
    auto node161 = GET_SKILL_NODE(161, PhaseNode_CreateTriggerNewPene);
    if (node161 != nullptr) node242->setTargets(node161->getOther());
    return node242;
}
//--------------------------------------------------------------------------------
// GetActorAttribute
//
REGISTER_REGISTER_SKILL_NODE(10212, 246) {
    pnode->resizeTrigger(PhaseNode_GetActorAttribute::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Disable>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 20, PhaseNode_Disable::FUNC_DO, &PhaseNode_Disable::Do);
}

REGISTER_CREATE_SKILL_NODE(10212, 246) {
    auto node246 = GET_SKILL_NODE(246, PhaseNode_GetActorAttribute);
    if (node246 == nullptr) {
        node246 = new PhaseNode_GetActorAttribute(246, phase);
        node246->setTarget(0U);
        node246->setType({});
        CALL_REGISTER_SKILL_NODE(10212, 246, node246)
    }
    if (noInit == true) {
        return node246;
    }
    return node246;
}
//--------------------------------------------------------------------------------
// SetInt
//
REGISTER_REGISTER_SKILL_NODE(10212, 248) {
}

REGISTER_CREATE_SKILL_NODE(10212, 248) {
    auto node248 = GET_SKILL_NODE(248, PhaseNode_SetInt);
    if (node248 == nullptr) {
        node248 = new PhaseNode_SetInt(248, phase);
        node248->setName("102122");
        node248->setValue(2);
        CALL_REGISTER_SKILL_NODE(10212, 248, node248)
    }
    if (noInit == true) {
        return node248;
    }
    return node248;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10212, 253) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_PlaySound::TRIGGER_DONE, 257, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10212, 253) {
    auto node253 = GET_SKILL_NODE(253, PhaseNode_PlaySound);
    if (node253 == nullptr) {
        node253 = new PhaseNode_PlaySound(253, phase);
        node253->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node253->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node253->setSoundID("SE_Hero118_Skill2_P1");
        node253->setTarget(0U);
        node253->setUsePos(false);
        node253->setPosX(.00f);
        node253->setPosY(.00f);
        node253->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10212, 253, node253)
    }
    if (noInit == true) {
        return node253;
    }
    return node253;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10212, 255) {
}

REGISTER_CREATE_SKILL_NODE(10212, 255) {
    auto node255 = GET_SKILL_NODE(255, PhaseNode_PlaySound);
    if (node255 == nullptr) {
        node255 = new PhaseNode_PlaySound(255, phase);
        node255->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node255->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node255->setSoundID("SE_Hero118_Skill2_P2");
        node255->setTarget(0U);
        node255->setUsePos(false);
        node255->setPosX(.00f);
        node255->setPosY(.00f);
        node255->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10212, 255, node255)
    }
    if (noInit == true) {
        return node255;
    }
    return node255;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10212, 257) {
}

REGISTER_CREATE_SKILL_NODE(10212, 257) {
    auto node257 = GET_SKILL_NODE(257, PhaseNode_PlaySound);
    if (node257 == nullptr) {
        node257 = new PhaseNode_PlaySound(257, phase);
        node257->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node257->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node257->setSoundID("VO_Hero118_Skill_B");
        node257->setTarget(0U);
        node257->setUsePos(false);
        node257->setPosX(.00f);
        node257->setPosY(.00f);
        node257->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10212, 257, node257)
    }
    if (noInit == true) {
        return node257;
    }
    return node257;
}
//--------------------------------------------------------------------------------
// SpawnCollider
//
REGISTER_REGISTER_SKILL_NODE(10212, 259) {
    pnode->resizeTrigger(PhaseNode_SpawnCollider::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AttachTo>(PhaseNode_SpawnCollider::TRIGGER_DONE, 262, PhaseNode_AttachTo::FUNC_DO, &PhaseNode_AttachTo::Do);
}

REGISTER_CREATE_SKILL_NODE(10212, 259) {
    auto node259 = GET_SKILL_NODE(259, PhaseNode_SpawnCollider);
    if (node259 == nullptr) {
        node259 = new PhaseNode_SpawnCollider(259, phase);
        node259->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node259->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node259->setMesh("");
        node259->setMeshScale(.00f);
        node259->setEffectID(102122);
        node259->setEffectScale(1.00f);
        node259->setType(PhaseNode_SpawnCollider::SpawnCollider_Type::Circle);
        node259->setTypeParams(0, 1.00f);
        node259->setTime(.00f);
        node259->setreentry(false);
        node259->setCheckPeneSound(true);
        CALL_REGISTER_SKILL_NODE(10212, 259, node259)
    }
    if (noInit == true) {
        return node259;
    }
    auto node264 = GET_SKILL_NODE(264, PhaseNode_OffsetCalculate);
    if (node264 != nullptr) node259->setPosX(node264->getOutPosX());
    if (node264 != nullptr) node259->setPosY(node264->getOutPosY());
    if (node264 != nullptr) node259->setPosZ(node264->getOutPosZ());
    if (node264 != nullptr) node259->setRotation(node264->getOutRotation());
    return node259;
}
//--------------------------------------------------------------------------------
// AttachTo
//
REGISTER_REGISTER_SKILL_NODE(10212, 262) {
    pnode->resizeTrigger(PhaseNode_AttachTo::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_MoveNewPene>(PhaseNode_AttachTo::TRIGGER_DONE, 128, PhaseNode_MoveNewPene::FUNC_DO, &PhaseNode_MoveNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(10212, 262) {
    auto node262 = GET_SKILL_NODE(262, PhaseNode_AttachTo);
    if (node262 == nullptr) {
        node262 = new PhaseNode_AttachTo(262, phase);
        node262->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node262->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node262->setChangeRotation(false);
        node262->setreentry(false);
        CALL_REGISTER_SKILL_NODE(10212, 262, node262)
    }
    if (noInit == true) {
        return node262;
    }
    auto node25 = GET_SKILL_NODE(25, PhaseNode_SpawnCollider);
    auto node259 = GET_SKILL_NODE(259, PhaseNode_SpawnCollider);
    if (node25 != nullptr) node262->setParent(node25->getColliderID());
    if (node259 != nullptr) node262->setChild(node259->getColliderID());
    return node262;
}
//--------------------------------------------------------------------------------
// OffsetCalculate
//
REGISTER_REGISTER_SKILL_NODE(10212, 264) {
    pnode->resizeTrigger(PhaseNode_OffsetCalculate::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_OffsetCalculate>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 80, PhaseNode_OffsetCalculate::FUNC_DO, &PhaseNode_OffsetCalculate::Do);
}

REGISTER_CREATE_SKILL_NODE(10212, 264) {
    auto node264 = GET_SKILL_NODE(264, PhaseNode_OffsetCalculate);
    if (node264 == nullptr) {
        node264 = new PhaseNode_OffsetCalculate(264, phase);
        node264->setPosZ(.00f);
        node264->setOffsetX(.00f);
        node264->setOffsetY(1.40f);
        node264->setOffsetZ(2.30f);
        node264->setRotOffset(.00f);
        CALL_REGISTER_SKILL_NODE(10212, 264, node264)
    }
    if (noInit == true) {
        return node264;
    }
    auto node103 = GET_SKILL_NODE(103, PhaseNode_GetLocation);
    auto node281 = GET_SKILL_NODE(281, PhaseNode_GetLineRotation);
    if (node103 != nullptr) node264->setPosX(node103->getX());
    if (node103 != nullptr) node264->setPosY(node103->getY());
    if (node281 != nullptr) node264->setRotation(node281->getRotation());
    return node264;
}
//--------------------------------------------------------------------------------
// DestroyCollider
//
REGISTER_REGISTER_SKILL_NODE(10212, 266) {
    pnode->resizeTrigger(PhaseNode_DestroyCollider::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnCollider>(PhaseNode_DestroyCollider::TRIGGER_DONE, 34, PhaseNode_SpawnCollider::FUNC_DO, &PhaseNode_SpawnCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(10212, 266) {
    auto node266 = GET_SKILL_NODE(266, PhaseNode_DestroyCollider);
    if (node266 == nullptr) {
        node266 = new PhaseNode_DestroyCollider(266, phase);
        CALL_REGISTER_SKILL_NODE(10212, 266, node266)
    }
    if (noInit == true) {
        return node266;
    }
    auto node259 = GET_SKILL_NODE(259, PhaseNode_SpawnCollider);
    if (node259 != nullptr) node266->setColliderID(node259->getColliderID());
    return node266;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10212, 270) {
}

REGISTER_CREATE_SKILL_NODE(10212, 270) {
    auto node270 = GET_SKILL_NODE(270, PhaseNode_PlayAnimation);
    if (node270 == nullptr) {
        node270 = new PhaseNode_PlayAnimation(270, phase);
        node270->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node270->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node270->setTarget(0U);
        node270->setAnimation("Idle");
        node270->setParameter("SkillArmBusy");
        node270->setValue(false);
        CALL_REGISTER_SKILL_NODE(10212, 270, node270)
    }
    if (noInit == true) {
        return node270;
    }
    return node270;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10212, 273) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_Delay::TRIGGER_DONE, 270, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10212, 273) {
    auto node273 = GET_SKILL_NODE(273, PhaseNode_Delay);
    if (node273 == nullptr) {
        node273 = new PhaseNode_Delay(273, phase);
        node273->setTime(.37f);
        CALL_REGISTER_SKILL_NODE(10212, 273, node273)
    }
    if (noInit == true) {
        return node273;
    }
    return node273;
}
//--------------------------------------------------------------------------------
// GetInputLocation
//
REGISTER_REGISTER_SKILL_NODE(10212, 279) {
    pnode->resizeTrigger(PhaseNode_GetInputLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLineRotation>(PhaseNode_GetInputLocation::TRIGGER_DONE, 281, PhaseNode_GetLineRotation::FUNC_DO, &PhaseNode_GetLineRotation::Do);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_GetInputLocation::TRIGGER_DONE, 138, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
    pnode->regTrigger<PhaseNode_SetInt>(PhaseNode_GetInputLocation::TRIGGER_DONE, 248, PhaseNode_SetInt::FUNC_SET, &PhaseNode_SetInt::Set);
}

REGISTER_CREATE_SKILL_NODE(10212, 279) {
    auto node279 = GET_SKILL_NODE(279, PhaseNode_GetInputLocation);
    if (node279 == nullptr) {
        node279 = new PhaseNode_GetInputLocation(279, phase);
        node279->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        CALL_REGISTER_SKILL_NODE(10212, 279, node279)
    }
    if (noInit == true) {
        return node279;
    }
    return node279;
}
//--------------------------------------------------------------------------------
// GetLineRotation
//
REGISTER_REGISTER_SKILL_NODE(10212, 281) {
    pnode->resizeTrigger(PhaseNode_GetLineRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_OffsetCalculate>(PhaseNode_GetLineRotation::TRIGGER_DONE, 264, PhaseNode_OffsetCalculate::FUNC_DO, &PhaseNode_OffsetCalculate::Do);
}

REGISTER_CREATE_SKILL_NODE(10212, 281) {
    auto node281 = GET_SKILL_NODE(281, PhaseNode_GetLineRotation);
    if (node281 == nullptr) {
        node281 = new PhaseNode_GetLineRotation(281, phase);
        CALL_REGISTER_SKILL_NODE(10212, 281, node281)
    }
    if (noInit == true) {
        return node281;
    }
    auto node103 = GET_SKILL_NODE(103, PhaseNode_GetLocation);
    auto node279 = GET_SKILL_NODE(279, PhaseNode_GetInputLocation);
    if (node103 != nullptr) node281->setStartX(node103->getX());
    if (node103 != nullptr) node281->setStartY(node103->getY());
    if (node279 != nullptr) node281->setEndX(node279->getX());
    if (node279 != nullptr) node281->setEndY(node279->getY());
    return node281;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(10212, 282) {
}

REGISTER_CREATE_SKILL_NODE(10212, 282) {
    auto node282 = GET_SKILL_NODE(282, PhaseNode_TriggerCheck);
    if (node282 == nullptr) {
        node282 = new PhaseNode_TriggerCheck(282, phase);
        auto node56 = GET_SKILL_NODE(56, PhaseNode_TriggerUpdate);
        if (node56 != nullptr) node56->addTriggerCheck(node282);
        
        CALL_REGISTER_SKILL_NODE(10212, 282, node282)
    }
    if (noInit == true) {
        return node282;
    }
    auto node283 = GET_SKILL_NODE(283, PhaseNode_CreateTriggerNewPene);
    if (node283 != nullptr) node282->setTrigger(0, node283->getTriggerID());
    return node282;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(10212, 283) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 282, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 284, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(10212, 283) {
    auto node283 = GET_SKILL_NODE(283, PhaseNode_CreateTriggerNewPene);
    if (node283 == nullptr) {
        node283 = new PhaseNode_CreateTriggerNewPene(283, phase);
        node283->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::Tick);
        node283->setTypeParams(0, .25f);
        node283->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node283->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Enemy);
        node283->setOnHero(true);
        node283->setOnMinion(true);
        node283->setOnDestruct(true);
        node283->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(10212, 283, node283)
    }
    if (noInit == true) {
        return node283;
    }
    auto node34 = GET_SKILL_NODE(34, PhaseNode_SpawnCollider);
    if (node34 != nullptr) node283->setColliderID(node34->getColliderID());
    return node283;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(10212, 284) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 41, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
}

REGISTER_CREATE_SKILL_NODE(10212, 284) {
    auto node284 = GET_SKILL_NODE(284, PhaseNode_ActorFilterNewPene);
    if (node284 == nullptr) {
        node284 = new PhaseNode_ActorFilterNewPene(284, phase);
        node284->setHero(true);
        node284->setMinion(true);
        node284->setDestruct(true);
        node284->setShield(false);
        node284->setTotalCount(0);
        node284->setPerCount(0);
        CALL_REGISTER_SKILL_NODE(10212, 284, node284)
    }
    if (noInit == true) {
        return node284;
    }
    auto node283 = GET_SKILL_NODE(283, PhaseNode_CreateTriggerNewPene);
    if (node283 != nullptr) node284->setInput(node283->getOther());
    return node284;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10212, 286) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_IsInterruptType>(PhaseNode_Detect::TRIGGER_ON, 292, PhaseNode_IsInterruptType::FUNC_DO, &PhaseNode_IsInterruptType::Do);
}

REGISTER_CREATE_SKILL_NODE(10212, 286) {
    auto node286 = GET_SKILL_NODE(286, PhaseNode_Detect);
    if (node286 == nullptr) {
        node286 = new PhaseNode_Detect(286, phase);
        node286->setSelf(0U);
        node286->setEvent("daduan_001");
        node286->setType(PhaseNode_Detect::Detect_Type::Interrupt_Skill);
        node286->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10212, 286, node286)
    }
    if (noInit == true) {
        return node286;
    }
    return node286;
}
//--------------------------------------------------------------------------------
// SwitchToInt
//
REGISTER_REGISTER_SKILL_NODE(10212, 287) {
    pnode->resizeTrigger(4);
    pnode->regTrigger<PhaseNode_EndPhase>(1, 54, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(10212, 287) {
    auto node287 = GET_SKILL_NODE(287, PhaseNode_SwitchToInt);
    if (node287 == nullptr) {
        node287 = new PhaseNode_SwitchToInt(287, phase);
        CALL_REGISTER_SKILL_NODE(10212, 287, node287)
    }
    if (noInit == true) {
        return node287;
    }
    auto variables = node287->getVariables();
    if (variables != nullptr) {
        node287->setSelection(variables->getVariable<int32_t>(Variable_10212_102122));
    }
    return node287;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10212, 289) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_RaiseEvent::TRIGGER_DONE, 298, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10212, 289) {
    auto node289 = GET_SKILL_NODE(289, PhaseNode_RaiseEvent);
    if (node289 == nullptr) {
        node289 = new PhaseNode_RaiseEvent(289, phase);
        node289->setEvent("daduan_001");
        node289->setTarget(0U);
        node289->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node289->setTypeParams(0, 0);
        node289->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10212, 289, node289)
    }
    if (noInit == true) {
        return node289;
    }
    return node289;
}
//--------------------------------------------------------------------------------
// StartPreInput
//
REGISTER_REGISTER_SKILL_NODE(10212, 290) {
    pnode->resizeTrigger(PhaseNode_StartPreInput::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_StartPreInput::TRIGGER_DONE, 294, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10212, 290) {
    auto node290 = GET_SKILL_NODE(290, PhaseNode_StartPreInput);
    if (node290 == nullptr) {
        node290 = new PhaseNode_StartPreInput(290, phase);
        node290->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node290->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node290->setDelayTime(.00f);
        CALL_REGISTER_SKILL_NODE(10212, 290, node290)
    }
    if (noInit == true) {
        return node290;
    }
    return node290;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(10212, 291) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_If::TRIGGER_TRUE, 293, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10212, 291) {
    auto node291 = GET_SKILL_NODE(291, PhaseNode_If);
    if (node291 == nullptr) {
        node291 = new PhaseNode_If(291, phase);
        CALL_REGISTER_SKILL_NODE(10212, 291, node291)
    }
    if (noInit == true) {
        return node291;
    }
    auto variables = node291->getVariables();
    if (variables != nullptr) {
        node291->setCondition(variables->getVariable<bool>(Variable_10212_InterruptAnimat));
    }
    return node291;
}
//--------------------------------------------------------------------------------
// IsInterruptType
//
REGISTER_REGISTER_SKILL_NODE(10212, 292) {
    pnode->resizeTrigger(PhaseNode_IsInterruptType::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SwitchToInt>(PhaseNode_IsInterruptType::TRIGGER_BUFF, 287, PhaseNode_SwitchToInt::FUNC_SWITCH, &PhaseNode_SwitchToInt::Switch);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_POSCHANGE, 291, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTAIM, 291, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTFIRE, 291, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTRELOAD, 291, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_USESKILL, 291, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(10212, 292) {
    auto node292 = GET_SKILL_NODE(292, PhaseNode_IsInterruptType);
    if (node292 == nullptr) {
        node292 = new PhaseNode_IsInterruptType(292, phase);
        node292->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node292->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10212, 292, node292)
    }
    if (noInit == true) {
        return node292;
    }
    auto node286 = GET_SKILL_NODE(286, PhaseNode_Detect);
    if (node286 != nullptr) node292->setType(node286->getVars().getVariable<int32_t>(2));
    return node292;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10212, 293) {
}

REGISTER_CREATE_SKILL_NODE(10212, 293) {
    auto node293 = GET_SKILL_NODE(293, PhaseNode_PlayAnimation);
    if (node293 == nullptr) {
        node293 = new PhaseNode_PlayAnimation(293, phase);
        node293->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node293->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node293->setTarget(0U);
        node293->setAnimation("Idle");
        node293->setParameter("");
        node293->setValue(false);
        CALL_REGISTER_SKILL_NODE(10212, 293, node293)
    }
    if (noInit == true) {
        return node293;
    }
    return node293;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10212, 294) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_Delay::TRIGGER_DONE, 297, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(10212, 294) {
    auto node294 = GET_SKILL_NODE(294, PhaseNode_Delay);
    if (node294 == nullptr) {
        node294 = new PhaseNode_Delay(294, phase);
        node294->setTime(.50f);
        CALL_REGISTER_SKILL_NODE(10212, 294, node294)
    }
    if (noInit == true) {
        return node294;
    }
    return node294;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(10212, 297) {
}

REGISTER_CREATE_SKILL_NODE(10212, 297) {
    auto node297 = GET_SKILL_NODE(297, PhaseNode_SetBool);
    if (node297 == nullptr) {
        node297 = new PhaseNode_SetBool(297, phase);
        node297->setName("InterruptAnimat");
        node297->setValue(true);
        CALL_REGISTER_SKILL_NODE(10212, 297, node297)
    }
    if (noInit == true) {
        return node297;
    }
    return node297;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10212, 298) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StartPreInput>(PhaseNode_RaiseEvent::TRIGGER_DONE, 290, PhaseNode_StartPreInput::FUNC_DO, &PhaseNode_StartPreInput::Do);
}

REGISTER_CREATE_SKILL_NODE(10212, 298) {
    auto node298 = GET_SKILL_NODE(298, PhaseNode_RaiseEvent);
    if (node298 == nullptr) {
        node298 = new PhaseNode_RaiseEvent(298, phase);
        node298->setEvent("Dead_001");
        node298->setTarget(0U);
        node298->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node298->setTypeParams(0, 0);
        node298->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10212, 298, node298)
    }
    if (noInit == true) {
        return node298;
    }
    return node298;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10212, 299) {
}

REGISTER_CREATE_SKILL_NODE(10212, 299) {
    auto node299 = GET_SKILL_NODE(299, PhaseNode_Detect);
    if (node299 == nullptr) {
        node299 = new PhaseNode_Detect(299, phase);
        node299->setSelf(0U);
        node299->setEvent("Dead_001");
        node299->setType(PhaseNode_Detect::Detect_Type::Actor_Dead);
        node299->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10212, 299, node299)
    }
    if (noInit == true) {
        return node299;
    }
    return node299;
}

//--------------------------------------------------------------------------------
// SkillCreator_10212
//
class SkillCreator_10212 : public SkillCreator {
public:
    SkillCreator_10212() {}
    virtual ~SkillCreator_10212() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_10212

//--------------------------------------------------------------------------------
// SkillPhase_10212
//
class SkillPhase_10212 : public SkillPhase {
public:
    SkillPhase_10212(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_10212() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(10212, 2) // StartPhase
        CASE_CREATE_SKILL_NODE(10212, 4) // ResetCD
        CASE_CREATE_SKILL_NODE(10212, 6) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10212, 20) // Disable
        CASE_CREATE_SKILL_NODE(10212, 23) // Delay
        CASE_CREATE_SKILL_NODE(10212, 25) // SpawnCollider
        CASE_CREATE_SKILL_NODE(10212, 34) // SpawnCollider
        CASE_CREATE_SKILL_NODE(10212, 41) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(10212, 50) // Delay
        CASE_CREATE_SKILL_NODE(10212, 54) // EndPhase
        CASE_CREATE_SKILL_NODE(10212, 56) // TriggerUpdate
        CASE_CREATE_SKILL_NODE(10212, 80) // OffsetCalculate
        CASE_CREATE_SKILL_NODE(10212, 84) // GetLocation
        CASE_CREATE_SKILL_NODE(10212, 87) // DestroyCollider
        CASE_CREATE_SKILL_NODE(10212, 103) // GetLocation
        CASE_CREATE_SKILL_NODE(10212, 128) // MoveNewPene
        CASE_CREATE_SKILL_NODE(10212, 130) // PlayEffect
        CASE_CREATE_SKILL_NODE(10212, 138) // PlaySound
        CASE_CREATE_SKILL_NODE(10212, 142) // PlaySound
        CASE_CREATE_SKILL_NODE(10212, 158) // SpawnCollider
        CASE_CREATE_SKILL_NODE(10212, 161) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(10212, 163) // TriggerCheck
        CASE_CREATE_SKILL_NODE(10212, 168) // AddSkillBuff
        CASE_CREATE_SKILL_NODE(10212, 178) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10212, 181) // Detect
        CASE_CREATE_SKILL_NODE(10212, 183) // Detect
        CASE_CREATE_SKILL_NODE(10212, 186) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10212, 205) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10212, 215) // AddSkillBuff
        CASE_CREATE_SKILL_NODE(10212, 218) // AddSkillBuff
        CASE_CREATE_SKILL_NODE(10212, 223) // Detect
        CASE_CREATE_SKILL_NODE(10212, 226) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10212, 228) // RemoveSkillBuff
        CASE_CREATE_SKILL_NODE(10212, 235) // RemoveSkillBuff
        CASE_CREATE_SKILL_NODE(10212, 237) // RemoveSkillBuff
        CASE_CREATE_SKILL_NODE(10212, 239) // PlayEffect
        CASE_CREATE_SKILL_NODE(10212, 242) // FilterSelf
        CASE_CREATE_SKILL_NODE(10212, 246) // GetActorAttribute
        CASE_CREATE_SKILL_NODE(10212, 248) // SetInt
        CASE_CREATE_SKILL_NODE(10212, 253) // PlaySound
        CASE_CREATE_SKILL_NODE(10212, 255) // PlaySound
        CASE_CREATE_SKILL_NODE(10212, 257) // PlaySound
        CASE_CREATE_SKILL_NODE(10212, 259) // SpawnCollider
        CASE_CREATE_SKILL_NODE(10212, 262) // AttachTo
        CASE_CREATE_SKILL_NODE(10212, 264) // OffsetCalculate
        CASE_CREATE_SKILL_NODE(10212, 266) // DestroyCollider
        CASE_CREATE_SKILL_NODE(10212, 270) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10212, 273) // Delay
        CASE_CREATE_SKILL_NODE(10212, 279) // GetInputLocation
        CASE_CREATE_SKILL_NODE(10212, 281) // GetLineRotation
        CASE_CREATE_SKILL_NODE(10212, 282) // TriggerCheck
        CASE_CREATE_SKILL_NODE(10212, 283) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(10212, 284) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(10212, 286) // Detect
        CASE_CREATE_SKILL_NODE(10212, 287) // SwitchToInt
        CASE_CREATE_SKILL_NODE(10212, 289) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10212, 290) // StartPreInput
        CASE_CREATE_SKILL_NODE(10212, 291) // If
        CASE_CREATE_SKILL_NODE(10212, 292) // IsInterruptType
        CASE_CREATE_SKILL_NODE(10212, 293) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10212, 294) // Delay
        CASE_CREATE_SKILL_NODE(10212, 297) // SetBool
        CASE_CREATE_SKILL_NODE(10212, 298) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10212, 299) // Detect
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_10212

SkillLogic* SkillCreator_10212::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //设置变量
    Variable_10212_102122 = logic->getVariables().setVariable<int32_t>("102122", 1);
    Variable_10212_InterruptAnimat = logic->getVariables().setVariable<bool>("InterruptAnimat");
    //创建阶段phase
    auto phase = new SkillPhase_10212(1, logic, 3);
    //设置phase执行器
    phase->setRunPhaseNode(1, 2);
    phase->setRunPhaseNode(2, 56);
    phase->setDetectPhaseNode(3, 181);
    phase->setDetectPhaseNode(3, 183);
    phase->setDetectPhaseNode(3, 223);
    phase->setDetectPhaseNode(3, 286);
    phase->setDetectPhaseNode(3, 299);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_10212::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
