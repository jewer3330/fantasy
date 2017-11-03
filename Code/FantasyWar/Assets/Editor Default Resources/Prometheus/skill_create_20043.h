#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

#include "skill_psnode_actorfilternewpene.h"
#include "skill_psnode_addskillbuff.h"
#include "skill_psnode_addskillbuffs.h"
#include "skill_psnode_attachto.h"
#include "skill_psnode_camerashake.h"
#include "skill_psnode_comparefloat.h"
#include "skill_psnode_createtriggernewpene.h"
#include "skill_psnode_delay.h"
#include "skill_psnode_destroycollider.h"
#include "skill_psnode_detect.h"
#include "skill_psnode_endphase.h"
#include "skill_psnode_getactorattribute.h"
#include "skill_psnode_getlocation.h"
#include "skill_psnode_getrotation.h"
#include "skill_psnode_if.h"
#include "skill_psnode_movenewpene.h"
#include "skill_psnode_offsetcalculate.h"
#include "skill_psnode_playanimation.h"
#include "skill_psnode_playeffect.h"
#include "skill_psnode_playsound.h"
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
REGISTER_REGISTER_SKILL_NODE(20043, 1) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_StartPhase::TRIGGER_START, 634, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(20043, 1) {
    auto node1 = GET_SKILL_NODE(1, PhaseNode_StartPhase);
    if (node1 == nullptr) {
        node1 = new PhaseNode_StartPhase(1, phase);
        CALL_REGISTER_SKILL_NODE(20043, 1, node1)
    }
    if (noInit == true) {
        return node1;
    }
    return node1;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(20043, 2) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnCollider>(PhaseNode_Delay::TRIGGER_DONE, 9, PhaseNode_SpawnCollider::FUNC_DO, &PhaseNode_SpawnCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(20043, 2) {
    auto node2 = GET_SKILL_NODE(2, PhaseNode_Delay);
    if (node2 == nullptr) {
        node2 = new PhaseNode_Delay(2, phase);
        node2->setTime(.60f);
        CALL_REGISTER_SKILL_NODE(20043, 2, node2)
    }
    if (noInit == true) {
        return node2;
    }
    return node2;
}
//--------------------------------------------------------------------------------
// TriggerUpdate
//
REGISTER_REGISTER_SKILL_NODE(20043, 3) {
}

REGISTER_CREATE_SKILL_NODE(20043, 3) {
    auto node3 = GET_SKILL_NODE(3, PhaseNode_TriggerUpdate);
    if (node3 == nullptr) {
        node3 = new PhaseNode_TriggerUpdate(3, phase);
        CALL_REGISTER_SKILL_NODE(20043, 3, node3)
    }
    if (noInit == true) {
        return node3;
    }
    return node3;
}
//--------------------------------------------------------------------------------
// SpawnCollider
//
REGISTER_REGISTER_SKILL_NODE(20043, 9) {
    pnode->resizeTrigger(PhaseNode_SpawnCollider::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_SpawnCollider::TRIGGER_DONE, 621, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_SpawnCollider::TRIGGER_DONE, 679, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(20043, 9) {
    auto node9 = GET_SKILL_NODE(9, PhaseNode_SpawnCollider);
    if (node9 == nullptr) {
        node9 = new PhaseNode_SpawnCollider(9, phase);
        node9->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node9->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node9->setMesh("");
        node9->setMeshScale(.00f);
        node9->setEffectID(0);
        node9->setEffectScale(.00f);
        node9->setType(PhaseNode_SpawnCollider::SpawnCollider_Type::Rect);
        node9->setTypeParams(0, 4.00f);
        node9->setTypeParams(1, 3.00f);
        node9->setTime(.00f);
        node9->setPosZ(.00f);
        node9->setreentry(false);
        node9->setCheckPeneSound(false);
        CALL_REGISTER_SKILL_NODE(20043, 9, node9)
    }
    if (noInit == true) {
        return node9;
    }
    auto node640 = GET_SKILL_NODE(640, PhaseNode_OffsetCalculate);
    if (node640 != nullptr) node9->setPosX(node640->getOutPosX());
    if (node640 != nullptr) node9->setPosY(node640->getOutPosY());
    if (node640 != nullptr) node9->setRotation(node640->getOutRotation());
    return node9;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(20043, 14) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlayAnimation::TRIGGER_DONE, 656, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(20043, 14) {
    auto node14 = GET_SKILL_NODE(14, PhaseNode_PlayAnimation);
    if (node14 == nullptr) {
        node14 = new PhaseNode_PlayAnimation(14, phase);
        node14->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node14->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node14->setTarget(0U);
        node14->setAnimation("Skill3S3");
        node14->setParameter("");
        node14->setValue(false);
        CALL_REGISTER_SKILL_NODE(20043, 14, node14)
    }
    if (noInit == true) {
        return node14;
    }
    return node14;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(20043, 15) {
}

REGISTER_CREATE_SKILL_NODE(20043, 15) {
    auto node15 = GET_SKILL_NODE(15, PhaseNode_EndPhase);
    if (node15 == nullptr) {
        node15 = new PhaseNode_EndPhase(15, phase);
        node15->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node15->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(20043, 15, node15)
    }
    if (noInit == true) {
        return node15;
    }
    return node15;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(20043, 87) {
}

REGISTER_CREATE_SKILL_NODE(20043, 87) {
    auto node87 = GET_SKILL_NODE(87, PhaseNode_EndPhase);
    if (node87 == nullptr) {
        node87 = new PhaseNode_EndPhase(87, phase);
        node87->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node87->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(20043, 87, node87)
    }
    if (noInit == true) {
        return node87;
    }
    return node87;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(20043, 88) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_Detect::TRIGGER_ON, 87, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(20043, 88) {
    auto node88 = GET_SKILL_NODE(88, PhaseNode_Detect);
    if (node88 == nullptr) {
        node88 = new PhaseNode_Detect(88, phase);
        node88->setSelf(0U);
        node88->setEvent("");
        node88->setType(PhaseNode_Detect::Detect_Type::Actor_Dead);
        node88->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(20043, 88, node88)
    }
    if (noInit == true) {
        return node88;
    }
    return node88;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(20043, 148) {
}

REGISTER_CREATE_SKILL_NODE(20043, 148) {
    auto node148 = GET_SKILL_NODE(148, PhaseNode_EndPhase);
    if (node148 == nullptr) {
        node148 = new PhaseNode_EndPhase(148, phase);
        node148->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node148->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(20043, 148, node148)
    }
    if (noInit == true) {
        return node148;
    }
    return node148;
}
//--------------------------------------------------------------------------------
// DestroyCollider
//
REGISTER_REGISTER_SKILL_NODE(20043, 248) {
    pnode->resizeTrigger(PhaseNode_DestroyCollider::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_DestroyCollider::TRIGGER_DONE, 14, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(20043, 248) {
    auto node248 = GET_SKILL_NODE(248, PhaseNode_DestroyCollider);
    if (node248 == nullptr) {
        node248 = new PhaseNode_DestroyCollider(248, phase);
        CALL_REGISTER_SKILL_NODE(20043, 248, node248)
    }
    if (noInit == true) {
        return node248;
    }
    auto node9 = GET_SKILL_NODE(9, PhaseNode_SpawnCollider);
    if (node9 != nullptr) node248->setColliderID(node9->getColliderID());
    return node248;
}
//--------------------------------------------------------------------------------
// AddSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(20043, 446) {
    pnode->resizeTrigger(PhaseNode_AddSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_AddSkillBuff::TRIGGER_DONE, 512, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(20043, 446) {
    auto node446 = GET_SKILL_NODE(446, PhaseNode_AddSkillBuff);
    if (node446 == nullptr) {
        node446 = new PhaseNode_AddSkillBuff(446, phase);
        node446->setConfigID(200433);
        node446->setConfigIDs({});
        node446->setTarget(0U);
        node446->setAttribute({{}});
        CALL_REGISTER_SKILL_NODE(20043, 446, node446)
    }
    if (noInit == true) {
        return node446;
    }
    return node446;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(20043, 512) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_PlaySound::TRIGGER_DONE, 660, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(20043, 512) {
    auto node512 = GET_SKILL_NODE(512, PhaseNode_PlaySound);
    if (node512 == nullptr) {
        node512 = new PhaseNode_PlaySound(512, phase);
        node512->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node512->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node512->setSoundID("SE_MON2004_Skill_A_P2");
        node512->setTarget(0U);
        node512->setUsePos(false);
        node512->setPosX(.00f);
        node512->setPosY(.00f);
        node512->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(20043, 512, node512)
    }
    if (noInit == true) {
        return node512;
    }
    return node512;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(20043, 539) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_PlaySound::TRIGGER_DONE, 638, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(20043, 539) {
    auto node539 = GET_SKILL_NODE(539, PhaseNode_PlaySound);
    if (node539 == nullptr) {
        node539 = new PhaseNode_PlaySound(539, phase);
        node539->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node539->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node539->setSoundID("VO_MON2004_Charge");
        node539->setTarget(0U);
        node539->setUsePos(false);
        node539->setPosX(.00f);
        node539->setPosY(.00f);
        node539->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(20043, 539, node539)
    }
    if (noInit == true) {
        return node539;
    }
    return node539;
}
//--------------------------------------------------------------------------------
// CameraShake
//
REGISTER_REGISTER_SKILL_NODE(20043, 602) {
    pnode->resizeTrigger(PhaseNode_CameraShake::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CameraShake::TRIGGER_DONE, 669, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(20043, 602) {
    auto node602 = GET_SKILL_NODE(602, PhaseNode_CameraShake);
    if (node602 == nullptr) {
        node602 = new PhaseNode_CameraShake(602, phase);
        node602->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node602->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node602->setTarget(0U);
        node602->setFrequency(.20f);
        node602->setAmplitude(2.00f);
        node602->setDuration(1.00f);
        node602->setFalloff(true);
        CALL_REGISTER_SKILL_NODE(20043, 602, node602)
    }
    if (noInit == true) {
        return node602;
    }
    return node602;
}
//--------------------------------------------------------------------------------
// StopSound
//
REGISTER_REGISTER_SKILL_NODE(20043, 607) {
    pnode->resizeTrigger(PhaseNode_StopSound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StopSound>(PhaseNode_StopSound::TRIGGER_DONE, 609, PhaseNode_StopSound::FUNC_STOP, &PhaseNode_StopSound::Stop);
}

REGISTER_CREATE_SKILL_NODE(20043, 607) {
    auto node607 = GET_SKILL_NODE(607, PhaseNode_StopSound);
    if (node607 == nullptr) {
        node607 = new PhaseNode_StopSound(607, phase);
        node607->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node607->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node607->setSoundID("VO_MON2004_Charge");
        CALL_REGISTER_SKILL_NODE(20043, 607, node607)
    }
    if (noInit == true) {
        return node607;
    }
    return node607;
}
//--------------------------------------------------------------------------------
// StopSound
//
REGISTER_REGISTER_SKILL_NODE(20043, 609) {
    pnode->resizeTrigger(PhaseNode_StopSound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_StopSound::TRIGGER_DONE, 611, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(20043, 609) {
    auto node609 = GET_SKILL_NODE(609, PhaseNode_StopSound);
    if (node609 == nullptr) {
        node609 = new PhaseNode_StopSound(609, phase);
        node609->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node609->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node609->setSoundID("SE_MON2004_Skill_A_P0");
        CALL_REGISTER_SKILL_NODE(20043, 609, node609)
    }
    if (noInit == true) {
        return node609;
    }
    return node609;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(20043, 611) {
}

REGISTER_CREATE_SKILL_NODE(20043, 611) {
    auto node611 = GET_SKILL_NODE(611, PhaseNode_EndPhase);
    if (node611 == nullptr) {
        node611 = new PhaseNode_EndPhase(611, phase);
        node611->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node611->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(20043, 611, node611)
    }
    if (noInit == true) {
        return node611;
    }
    return node611;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(20043, 613) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StopSound>(PhaseNode_Detect::TRIGGER_ON, 607, PhaseNode_StopSound::FUNC_STOP, &PhaseNode_StopSound::Stop);
}

REGISTER_CREATE_SKILL_NODE(20043, 613) {
    auto node613 = GET_SKILL_NODE(613, PhaseNode_Detect);
    if (node613 == nullptr) {
        node613 = new PhaseNode_Detect(613, phase);
        node613->setSelf(0U);
        node613->setEvent("");
        node613->setType(PhaseNode_Detect::Detect_Type::Interrupt_Skill);
        node613->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(20043, 613, node613)
    }
    if (noInit == true) {
        return node613;
    }
    return node613;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(20043, 614) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 626, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 628, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(20043, 614) {
    auto node614 = GET_SKILL_NODE(614, PhaseNode_CreateTriggerNewPene);
    if (node614 == nullptr) {
        node614 = new PhaseNode_CreateTriggerNewPene(614, phase);
        node614->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::In);
        node614->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node614->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Enemy);
        node614->setOnHero(true);
        node614->setOnMinion(false);
        node614->setOnDestruct(false);
        node614->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(20043, 614, node614)
    }
    if (noInit == true) {
        return node614;
    }
    auto node9 = GET_SKILL_NODE(9, PhaseNode_SpawnCollider);
    if (node9 != nullptr) node614->setColliderID(node9->getColliderID());
    return node614;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(20043, 615) {
}

REGISTER_CREATE_SKILL_NODE(20043, 615) {
    auto node615 = GET_SKILL_NODE(615, PhaseNode_TriggerCheck);
    if (node615 == nullptr) {
        node615 = new PhaseNode_TriggerCheck(615, phase);
        auto node3 = GET_SKILL_NODE(3, PhaseNode_TriggerUpdate);
        if (node3 != nullptr) node3->addTriggerCheck(node615);
        
        CALL_REGISTER_SKILL_NODE(20043, 615, node615)
    }
    if (noInit == true) {
        return node615;
    }
    auto node624 = GET_SKILL_NODE(624, PhaseNode_CreateTriggerNewPene);
    if (node624 != nullptr) node615->setTrigger(0, node624->getTriggerID());
    return node615;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(20043, 616) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 617, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(20043, 616) {
    auto node616 = GET_SKILL_NODE(616, PhaseNode_ActorFilterNewPene);
    if (node616 == nullptr) {
        node616 = new PhaseNode_ActorFilterNewPene(616, phase);
        node616->setHero(true);
        node616->setMinion(false);
        node616->setDestruct(false);
        node616->setShield(false);
        node616->setTotalCount(0);
        node616->setPerCount(1);
        CALL_REGISTER_SKILL_NODE(20043, 616, node616)
    }
    if (noInit == true) {
        return node616;
    }
    auto node620 = GET_SKILL_NODE(620, PhaseNode_CreateTriggerNewPene);
    if (node620 != nullptr) node616->setInput(node620->getOther());
    return node616;
}
//--------------------------------------------------------------------------------
// GetActorAttribute
//
REGISTER_REGISTER_SKILL_NODE(20043, 617) {
    pnode->resizeTrigger(PhaseNode_GetActorAttribute::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 618, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 631, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 632, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 633, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
}

REGISTER_CREATE_SKILL_NODE(20043, 617) {
    auto node617 = GET_SKILL_NODE(617, PhaseNode_GetActorAttribute);
    if (node617 == nullptr) {
        node617 = new PhaseNode_GetActorAttribute(617, phase);
        node617->setTarget(0U);
        node617->setType({202});
        CALL_REGISTER_SKILL_NODE(20043, 617, node617)
    }
    if (noInit == true) {
        return node617;
    }
    return node617;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(20043, 618) {
}

REGISTER_CREATE_SKILL_NODE(20043, 618) {
    auto node618 = GET_SKILL_NODE(618, PhaseNode_AddSkillBuffs);
    if (node618 == nullptr) {
        node618 = new PhaseNode_AddSkillBuffs(618, phase);
        node618->setConfigID({200432,15});
        CALL_REGISTER_SKILL_NODE(20043, 618, node618)
    }
    if (noInit == true) {
        return node618;
    }
    auto node616 = GET_SKILL_NODE(616, PhaseNode_ActorFilterNewPene);
    auto node617 = GET_SKILL_NODE(617, PhaseNode_GetActorAttribute);
    if (node616 != nullptr) node618->setTarget(node616->getOutput());
    if (node617 != nullptr) node618->setAttribute(node617->getAttribute());
    return node618;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(20043, 619) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 614, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_LESS, 620, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
}

REGISTER_CREATE_SKILL_NODE(20043, 619) {
    auto node619 = GET_SKILL_NODE(619, PhaseNode_CompareFloat);
    if (node619 == nullptr) {
        node619 = new PhaseNode_CompareFloat(619, phase);
        node619->setA(.00f);
        node619->setB(.00f);
        CALL_REGISTER_SKILL_NODE(20043, 619, node619)
    }
    if (noInit == true) {
        return node619;
    }
    return node619;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(20043, 620) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 625, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 616, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(20043, 620) {
    auto node620 = GET_SKILL_NODE(620, PhaseNode_CreateTriggerNewPene);
    if (node620 == nullptr) {
        node620 = new PhaseNode_CreateTriggerNewPene(620, phase);
        node620->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::Tick);
        node620->setTypeParams(0, .00f);
        node620->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node620->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Enemy);
        node620->setOnHero(true);
        node620->setOnMinion(false);
        node620->setOnDestruct(false);
        node620->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(20043, 620, node620)
    }
    if (noInit == true) {
        return node620;
    }
    auto node9 = GET_SKILL_NODE(9, PhaseNode_SpawnCollider);
    if (node9 != nullptr) node620->setColliderID(node9->getColliderID());
    return node620;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(20043, 621) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_If::TRIGGER_FALSE, 622, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_If::TRIGGER_TRUE, 619, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(20043, 621) {
    auto node621 = GET_SKILL_NODE(621, PhaseNode_If);
    if (node621 == nullptr) {
        node621 = new PhaseNode_If(621, phase);
        node621->setCondition(true);
        CALL_REGISTER_SKILL_NODE(20043, 621, node621)
    }
    if (noInit == true) {
        return node621;
    }
    return node621;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(20043, 622) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 624, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_LESS, 623, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
}

REGISTER_CREATE_SKILL_NODE(20043, 622) {
    auto node622 = GET_SKILL_NODE(622, PhaseNode_CompareFloat);
    if (node622 == nullptr) {
        node622 = new PhaseNode_CompareFloat(622, phase);
        node622->setA(.00f);
        node622->setB(.00f);
        CALL_REGISTER_SKILL_NODE(20043, 622, node622)
    }
    if (noInit == true) {
        return node622;
    }
    return node622;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(20043, 623) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 627, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 629, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(20043, 623) {
    auto node623 = GET_SKILL_NODE(623, PhaseNode_CreateTriggerNewPene);
    if (node623 == nullptr) {
        node623 = new PhaseNode_CreateTriggerNewPene(623, phase);
        node623->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::Tick);
        node623->setTypeParams(0, .00f);
        node623->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node623->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Friend);
        node623->setOnHero(true);
        node623->setOnMinion(false);
        node623->setOnDestruct(false);
        node623->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(20043, 623, node623)
    }
    if (noInit == true) {
        return node623;
    }
    auto node9 = GET_SKILL_NODE(9, PhaseNode_SpawnCollider);
    if (node9 != nullptr) node623->setColliderID(node9->getColliderID());
    return node623;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(20043, 624) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 615, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 630, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(20043, 624) {
    auto node624 = GET_SKILL_NODE(624, PhaseNode_CreateTriggerNewPene);
    if (node624 == nullptr) {
        node624 = new PhaseNode_CreateTriggerNewPene(624, phase);
        node624->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::In);
        node624->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node624->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Friend);
        node624->setOnHero(true);
        node624->setOnMinion(false);
        node624->setOnDestruct(false);
        node624->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(20043, 624, node624)
    }
    if (noInit == true) {
        return node624;
    }
    auto node9 = GET_SKILL_NODE(9, PhaseNode_SpawnCollider);
    if (node9 != nullptr) node624->setColliderID(node9->getColliderID());
    return node624;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(20043, 625) {
}

REGISTER_CREATE_SKILL_NODE(20043, 625) {
    auto node625 = GET_SKILL_NODE(625, PhaseNode_TriggerCheck);
    if (node625 == nullptr) {
        node625 = new PhaseNode_TriggerCheck(625, phase);
        auto node3 = GET_SKILL_NODE(3, PhaseNode_TriggerUpdate);
        if (node3 != nullptr) node3->addTriggerCheck(node625);
        
        CALL_REGISTER_SKILL_NODE(20043, 625, node625)
    }
    if (noInit == true) {
        return node625;
    }
    auto node620 = GET_SKILL_NODE(620, PhaseNode_CreateTriggerNewPene);
    if (node620 != nullptr) node625->setTrigger(0, node620->getTriggerID());
    return node625;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(20043, 626) {
}

REGISTER_CREATE_SKILL_NODE(20043, 626) {
    auto node626 = GET_SKILL_NODE(626, PhaseNode_TriggerCheck);
    if (node626 == nullptr) {
        node626 = new PhaseNode_TriggerCheck(626, phase);
        auto node3 = GET_SKILL_NODE(3, PhaseNode_TriggerUpdate);
        if (node3 != nullptr) node3->addTriggerCheck(node626);
        
        CALL_REGISTER_SKILL_NODE(20043, 626, node626)
    }
    if (noInit == true) {
        return node626;
    }
    auto node614 = GET_SKILL_NODE(614, PhaseNode_CreateTriggerNewPene);
    if (node614 != nullptr) node626->setTrigger(0, node614->getTriggerID());
    return node626;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(20043, 627) {
}

REGISTER_CREATE_SKILL_NODE(20043, 627) {
    auto node627 = GET_SKILL_NODE(627, PhaseNode_TriggerCheck);
    if (node627 == nullptr) {
        node627 = new PhaseNode_TriggerCheck(627, phase);
        auto node3 = GET_SKILL_NODE(3, PhaseNode_TriggerUpdate);
        if (node3 != nullptr) node3->addTriggerCheck(node627);
        
        CALL_REGISTER_SKILL_NODE(20043, 627, node627)
    }
    if (noInit == true) {
        return node627;
    }
    auto node623 = GET_SKILL_NODE(623, PhaseNode_CreateTriggerNewPene);
    if (node623 != nullptr) node627->setTrigger(0, node623->getTriggerID());
    return node627;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(20043, 628) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 617, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(20043, 628) {
    auto node628 = GET_SKILL_NODE(628, PhaseNode_ActorFilterNewPene);
    if (node628 == nullptr) {
        node628 = new PhaseNode_ActorFilterNewPene(628, phase);
        node628->setHero(true);
        node628->setMinion(false);
        node628->setDestruct(false);
        node628->setShield(false);
        node628->setTotalCount(0);
        node628->setPerCount(1);
        CALL_REGISTER_SKILL_NODE(20043, 628, node628)
    }
    if (noInit == true) {
        return node628;
    }
    auto node614 = GET_SKILL_NODE(614, PhaseNode_CreateTriggerNewPene);
    if (node614 != nullptr) node628->setInput(node614->getOther());
    return node628;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(20043, 629) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 617, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(20043, 629) {
    auto node629 = GET_SKILL_NODE(629, PhaseNode_ActorFilterNewPene);
    if (node629 == nullptr) {
        node629 = new PhaseNode_ActorFilterNewPene(629, phase);
        node629->setHero(true);
        node629->setMinion(false);
        node629->setDestruct(false);
        node629->setShield(false);
        node629->setTotalCount(0);
        node629->setPerCount(1);
        CALL_REGISTER_SKILL_NODE(20043, 629, node629)
    }
    if (noInit == true) {
        return node629;
    }
    auto node623 = GET_SKILL_NODE(623, PhaseNode_CreateTriggerNewPene);
    if (node623 != nullptr) node629->setInput(node623->getOther());
    return node629;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(20043, 630) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 617, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(20043, 630) {
    auto node630 = GET_SKILL_NODE(630, PhaseNode_ActorFilterNewPene);
    if (node630 == nullptr) {
        node630 = new PhaseNode_ActorFilterNewPene(630, phase);
        node630->setHero(true);
        node630->setMinion(false);
        node630->setDestruct(false);
        node630->setShield(false);
        node630->setTotalCount(0);
        node630->setPerCount(1);
        CALL_REGISTER_SKILL_NODE(20043, 630, node630)
    }
    if (noInit == true) {
        return node630;
    }
    auto node624 = GET_SKILL_NODE(624, PhaseNode_CreateTriggerNewPene);
    if (node624 != nullptr) node630->setInput(node624->getOther());
    return node630;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(20043, 631) {
}

REGISTER_CREATE_SKILL_NODE(20043, 631) {
    auto node631 = GET_SKILL_NODE(631, PhaseNode_AddSkillBuffs);
    if (node631 == nullptr) {
        node631 = new PhaseNode_AddSkillBuffs(631, phase);
        node631->setConfigID({200432,15});
        CALL_REGISTER_SKILL_NODE(20043, 631, node631)
    }
    if (noInit == true) {
        return node631;
    }
    auto node628 = GET_SKILL_NODE(628, PhaseNode_ActorFilterNewPene);
    auto node617 = GET_SKILL_NODE(617, PhaseNode_GetActorAttribute);
    if (node628 != nullptr) node631->setTarget(node628->getOutput());
    if (node617 != nullptr) node631->setAttribute(node617->getAttribute());
    return node631;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(20043, 632) {
}

REGISTER_CREATE_SKILL_NODE(20043, 632) {
    auto node632 = GET_SKILL_NODE(632, PhaseNode_AddSkillBuffs);
    if (node632 == nullptr) {
        node632 = new PhaseNode_AddSkillBuffs(632, phase);
        node632->setConfigID({200432,15});
        CALL_REGISTER_SKILL_NODE(20043, 632, node632)
    }
    if (noInit == true) {
        return node632;
    }
    auto node629 = GET_SKILL_NODE(629, PhaseNode_ActorFilterNewPene);
    auto node617 = GET_SKILL_NODE(617, PhaseNode_GetActorAttribute);
    if (node629 != nullptr) node632->setTarget(node629->getOutput());
    if (node617 != nullptr) node632->setAttribute(node617->getAttribute());
    return node632;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(20043, 633) {
}

REGISTER_CREATE_SKILL_NODE(20043, 633) {
    auto node633 = GET_SKILL_NODE(633, PhaseNode_AddSkillBuffs);
    if (node633 == nullptr) {
        node633 = new PhaseNode_AddSkillBuffs(633, phase);
        node633->setConfigID({200432,15});
        CALL_REGISTER_SKILL_NODE(20043, 633, node633)
    }
    if (noInit == true) {
        return node633;
    }
    auto node630 = GET_SKILL_NODE(630, PhaseNode_ActorFilterNewPene);
    auto node617 = GET_SKILL_NODE(617, PhaseNode_GetActorAttribute);
    if (node630 != nullptr) node633->setTarget(node630->getOutput());
    if (node617 != nullptr) node633->setAttribute(node617->getAttribute());
    return node633;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(20043, 634) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_ResetCD::TRIGGER_DONE, 635, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(20043, 634) {
    auto node634 = GET_SKILL_NODE(634, PhaseNode_ResetCD);
    if (node634 == nullptr) {
        node634 = new PhaseNode_ResetCD(634, phase);
        node634->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node634->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node634->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(20043, 634, node634)
    }
    if (noInit == true) {
        return node634;
    }
    return node634;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(20043, 635) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_PlayAnimation::TRIGGER_DONE, 636, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(20043, 635) {
    auto node635 = GET_SKILL_NODE(635, PhaseNode_PlayAnimation);
    if (node635 == nullptr) {
        node635 = new PhaseNode_PlayAnimation(635, phase);
        node635->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node635->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node635->setTarget(0U);
        node635->setAnimation("Skill3S1");
        node635->setParameter("");
        node635->setValue(false);
        CALL_REGISTER_SKILL_NODE(20043, 635, node635)
    }
    if (noInit == true) {
        return node635;
    }
    return node635;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(20043, 636) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlaySound::TRIGGER_DONE, 637, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(20043, 636) {
    auto node636 = GET_SKILL_NODE(636, PhaseNode_PlaySound);
    if (node636 == nullptr) {
        node636 = new PhaseNode_PlaySound(636, phase);
        node636->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node636->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node636->setSoundID("SE_MON2004_Skill_A_P0");
        node636->setTarget(0U);
        node636->setUsePos(false);
        node636->setPosX(.00f);
        node636->setPosY(.00f);
        node636->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(20043, 636, node636)
    }
    if (noInit == true) {
        return node636;
    }
    return node636;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(20043, 637) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_Delay::TRIGGER_DONE, 539, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(20043, 637) {
    auto node637 = GET_SKILL_NODE(637, PhaseNode_Delay);
    if (node637 == nullptr) {
        node637 = new PhaseNode_Delay(637, phase);
        node637->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(20043, 637, node637)
    }
    if (noInit == true) {
        return node637;
    }
    return node637;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(20043, 638) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetRotation>(PhaseNode_GetLocation::TRIGGER_DONE, 639, PhaseNode_GetRotation::FUNC_DO, &PhaseNode_GetRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(20043, 638) {
    auto node638 = GET_SKILL_NODE(638, PhaseNode_GetLocation);
    if (node638 == nullptr) {
        node638 = new PhaseNode_GetLocation(638, phase);
        node638->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node638->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(20043, 638, node638)
    }
    if (noInit == true) {
        return node638;
    }
    return node638;
}
//--------------------------------------------------------------------------------
// GetRotation
//
REGISTER_REGISTER_SKILL_NODE(20043, 639) {
    pnode->resizeTrigger(PhaseNode_GetRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_OffsetCalculate>(PhaseNode_GetRotation::TRIGGER_DONE, 640, PhaseNode_OffsetCalculate::FUNC_DO, &PhaseNode_OffsetCalculate::Do);
}

REGISTER_CREATE_SKILL_NODE(20043, 639) {
    auto node639 = GET_SKILL_NODE(639, PhaseNode_GetRotation);
    if (node639 == nullptr) {
        node639 = new PhaseNode_GetRotation(639, phase);
        node639->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node639->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(20043, 639, node639)
    }
    if (noInit == true) {
        return node639;
    }
    return node639;
}
//--------------------------------------------------------------------------------
// OffsetCalculate
//
REGISTER_REGISTER_SKILL_NODE(20043, 640) {
    pnode->resizeTrigger(PhaseNode_OffsetCalculate::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 641, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(20043, 640) {
    auto node640 = GET_SKILL_NODE(640, PhaseNode_OffsetCalculate);
    if (node640 == nullptr) {
        node640 = new PhaseNode_OffsetCalculate(640, phase);
        node640->setPosZ(.00f);
        node640->setOffsetX(.00f);
        node640->setOffsetY(2.00f);
        node640->setOffsetZ(.00f);
        node640->setRotOffset(.00f);
        CALL_REGISTER_SKILL_NODE(20043, 640, node640)
    }
    if (noInit == true) {
        return node640;
    }
    auto node638 = GET_SKILL_NODE(638, PhaseNode_GetLocation);
    auto node639 = GET_SKILL_NODE(639, PhaseNode_GetRotation);
    if (node638 != nullptr) node640->setPosX(node638->getX());
    if (node638 != nullptr) node640->setPosY(node638->getY());
    if (node639 != nullptr) node640->setRotation(node639->getAngle());
    return node640;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(20043, 641) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetRotation>(PhaseNode_GetLocation::TRIGGER_DONE, 642, PhaseNode_GetRotation::FUNC_DO, &PhaseNode_GetRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(20043, 641) {
    auto node641 = GET_SKILL_NODE(641, PhaseNode_GetLocation);
    if (node641 == nullptr) {
        node641 = new PhaseNode_GetLocation(641, phase);
        node641->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node641->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(20043, 641, node641)
    }
    if (noInit == true) {
        return node641;
    }
    return node641;
}
//--------------------------------------------------------------------------------
// GetRotation
//
REGISTER_REGISTER_SKILL_NODE(20043, 642) {
    pnode->resizeTrigger(PhaseNode_GetRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_OffsetCalculate>(PhaseNode_GetRotation::TRIGGER_DONE, 643, PhaseNode_OffsetCalculate::FUNC_DO, &PhaseNode_OffsetCalculate::Do);
}

REGISTER_CREATE_SKILL_NODE(20043, 642) {
    auto node642 = GET_SKILL_NODE(642, PhaseNode_GetRotation);
    if (node642 == nullptr) {
        node642 = new PhaseNode_GetRotation(642, phase);
        node642->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node642->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(20043, 642, node642)
    }
    if (noInit == true) {
        return node642;
    }
    return node642;
}
//--------------------------------------------------------------------------------
// OffsetCalculate
//
REGISTER_REGISTER_SKILL_NODE(20043, 643) {
    pnode->resizeTrigger(PhaseNode_OffsetCalculate::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 645, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(20043, 643) {
    auto node643 = GET_SKILL_NODE(643, PhaseNode_OffsetCalculate);
    if (node643 == nullptr) {
        node643 = new PhaseNode_OffsetCalculate(643, phase);
        node643->setPosZ(.00f);
        node643->setOffsetX(.00f);
        node643->setOffsetY(.00f);
        node643->setOffsetZ(.00f);
        node643->setRotOffset(.00f);
        CALL_REGISTER_SKILL_NODE(20043, 643, node643)
    }
    if (noInit == true) {
        return node643;
    }
    auto node641 = GET_SKILL_NODE(641, PhaseNode_GetLocation);
    auto node642 = GET_SKILL_NODE(642, PhaseNode_GetRotation);
    if (node641 != nullptr) node643->setPosX(node641->getX());
    if (node641 != nullptr) node643->setPosY(node641->getY());
    if (node642 != nullptr) node643->setRotation(node642->getAngle());
    return node643;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(20043, 644) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_PlayEffect::TRIGGER_DONE, 647, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(20043, 644) {
    auto node644 = GET_SKILL_NODE(644, PhaseNode_PlayEffect);
    if (node644 == nullptr) {
        node644 = new PhaseNode_PlayEffect(644, phase);
        node644->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node644->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node644->setEffectID(1022);
        node644->setChangeColor(false);
        node644->setType(PhaseNode_PlayEffect::PlayEffect_Type::WithTarget);
        node644->getVars().reserve(5);
        node644->getVars().setVariable<uint64_t>(0, 0U);
        node644->getVars().setVariable<std::string>(1, "");
        node644->getVars().setVariable<float>(2, .00f);
        node644->getVars().setVariable<float>(3, .00f);
        node644->getVars().setVariable<float>(4, .00f);
        node644->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(20043, 644, node644)
    }
    if (noInit == true) {
        return node644;
    }
    auto node643 = GET_SKILL_NODE(643, PhaseNode_OffsetCalculate);
    if (node643 != nullptr) node644->getVars().setVariable<float>(2, node643->getOutPosX());
    if (node643 != nullptr) node644->getVars().setVariable<float>(3, node643->getOutPosY());
    if (node643 != nullptr) node644->getVars().setVariable<float>(4, node643->getOutPosZ());
    if (node643 != nullptr) node644->setRotation(node643->getOutRotation());
    return node644;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(20043, 645) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_FALSE, 646, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_TRUE, 644, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(20043, 645) {
    auto node645 = GET_SKILL_NODE(645, PhaseNode_If);
    if (node645 == nullptr) {
        node645 = new PhaseNode_If(645, phase);
        node645->setCondition(false);
        CALL_REGISTER_SKILL_NODE(20043, 645, node645)
    }
    if (noInit == true) {
        return node645;
    }
    return node645;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(20043, 646) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_PlayEffect::TRIGGER_DONE, 647, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(20043, 646) {
    auto node646 = GET_SKILL_NODE(646, PhaseNode_PlayEffect);
    if (node646 == nullptr) {
        node646 = new PhaseNode_PlayEffect(646, phase);
        node646->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node646->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node646->setEffectID(1022);
        node646->setChangeColor(false);
        node646->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node646->getVars().reserve(3);
        node646->getVars().setVariable<float>(0, .00f);
        node646->getVars().setVariable<float>(1, .00f);
        node646->getVars().setVariable<float>(2, .00f);
        node646->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(20043, 646, node646)
    }
    if (noInit == true) {
        return node646;
    }
    auto node643 = GET_SKILL_NODE(643, PhaseNode_OffsetCalculate);
    if (node643 != nullptr) node646->getVars().setVariable<float>(0, node643->getOutPosX());
    if (node643 != nullptr) node646->getVars().setVariable<float>(1, node643->getOutPosY());
    if (node643 != nullptr) node646->getVars().setVariable<float>(2, node643->getOutPosZ());
    if (node643 != nullptr) node646->setRotation(node643->getOutRotation());
    return node646;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(20043, 647) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 2, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_LESS, 2, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_LESS, 648, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(20043, 647) {
    auto node647 = GET_SKILL_NODE(647, PhaseNode_CompareFloat);
    if (node647 == nullptr) {
        node647 = new PhaseNode_CompareFloat(647, phase);
        node647->setA(.00f);
        node647->setB(.60f);
        CALL_REGISTER_SKILL_NODE(20043, 647, node647)
    }
    if (noInit == true) {
        return node647;
    }
    return node647;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(20043, 648) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StopEffect>(PhaseNode_Delay::TRIGGER_DONE, 649, PhaseNode_StopEffect::FUNC_DO, &PhaseNode_StopEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(20043, 648) {
    auto node648 = GET_SKILL_NODE(648, PhaseNode_Delay);
    if (node648 == nullptr) {
        node648 = new PhaseNode_Delay(648, phase);
        node648->setTime(.60f);
        CALL_REGISTER_SKILL_NODE(20043, 648, node648)
    }
    if (noInit == true) {
        return node648;
    }
    return node648;
}
//--------------------------------------------------------------------------------
// StopEffect
//
REGISTER_REGISTER_SKILL_NODE(20043, 649) {
}

REGISTER_CREATE_SKILL_NODE(20043, 649) {
    auto node649 = GET_SKILL_NODE(649, PhaseNode_StopEffect);
    if (node649 == nullptr) {
        node649 = new PhaseNode_StopEffect(649, phase);
        node649->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node649->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node649->setEffectID(1022);
        CALL_REGISTER_SKILL_NODE(20043, 649, node649)
    }
    if (noInit == true) {
        return node649;
    }
    return node649;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(20043, 650) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_PlayEffect::TRIGGER_DONE, 653, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(20043, 650) {
    auto node650 = GET_SKILL_NODE(650, PhaseNode_PlayEffect);
    if (node650 == nullptr) {
        node650 = new PhaseNode_PlayEffect(650, phase);
        node650->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node650->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node650->setEffectID(1021);
        node650->setChangeColor(false);
        node650->setType(PhaseNode_PlayEffect::PlayEffect_Type::WithTarget);
        node650->getVars().reserve(5);
        node650->getVars().setVariable<uint64_t>(0, 0U);
        node650->getVars().setVariable<std::string>(1, "");
        node650->getVars().setVariable<float>(2, .00f);
        node650->getVars().setVariable<float>(3, .00f);
        node650->getVars().setVariable<float>(4, .00f);
        node650->setRotation(.00f);
        node650->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(20043, 650, node650)
    }
    if (noInit == true) {
        return node650;
    }
    auto node9 = GET_SKILL_NODE(9, PhaseNode_SpawnCollider);
    if (node9 != nullptr) node650->getVars().setVariable<uint64_t>(0, node9->getColliderID());
    return node650;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(20043, 651) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_FALSE, 652, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_TRUE, 650, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(20043, 651) {
    auto node651 = GET_SKILL_NODE(651, PhaseNode_If);
    if (node651 == nullptr) {
        node651 = new PhaseNode_If(651, phase);
        node651->setCondition(true);
        CALL_REGISTER_SKILL_NODE(20043, 651, node651)
    }
    if (noInit == true) {
        return node651;
    }
    return node651;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(20043, 652) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_PlayEffect::TRIGGER_DONE, 653, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(20043, 652) {
    auto node652 = GET_SKILL_NODE(652, PhaseNode_PlayEffect);
    if (node652 == nullptr) {
        node652 = new PhaseNode_PlayEffect(652, phase);
        node652->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node652->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node652->setEffectID(1021);
        node652->setChangeColor(false);
        node652->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node652->getVars().reserve(3);
        node652->getVars().setVariable<float>(0, .00f);
        node652->getVars().setVariable<float>(1, .00f);
        node652->getVars().setVariable<float>(2, .00f);
        node652->setRotation(.00f);
        node652->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(20043, 652, node652)
    }
    if (noInit == true) {
        return node652;
    }
    return node652;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(20043, 653) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_LESS, 654, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(20043, 653) {
    auto node653 = GET_SKILL_NODE(653, PhaseNode_CompareFloat);
    if (node653 == nullptr) {
        node653 = new PhaseNode_CompareFloat(653, phase);
        node653->setA(.00f);
        node653->setB(.00f);
        CALL_REGISTER_SKILL_NODE(20043, 653, node653)
    }
    if (noInit == true) {
        return node653;
    }
    return node653;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(20043, 654) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StopEffect>(PhaseNode_Delay::TRIGGER_DONE, 655, PhaseNode_StopEffect::FUNC_DO, &PhaseNode_StopEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(20043, 654) {
    auto node654 = GET_SKILL_NODE(654, PhaseNode_Delay);
    if (node654 == nullptr) {
        node654 = new PhaseNode_Delay(654, phase);
        node654->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(20043, 654, node654)
    }
    if (noInit == true) {
        return node654;
    }
    return node654;
}
//--------------------------------------------------------------------------------
// StopEffect
//
REGISTER_REGISTER_SKILL_NODE(20043, 655) {
}

REGISTER_CREATE_SKILL_NODE(20043, 655) {
    auto node655 = GET_SKILL_NODE(655, PhaseNode_StopEffect);
    if (node655 == nullptr) {
        node655 = new PhaseNode_StopEffect(655, phase);
        node655->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node655->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node655->setEffectID(1021);
        CALL_REGISTER_SKILL_NODE(20043, 655, node655)
    }
    if (noInit == true) {
        return node655;
    }
    return node655;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(20043, 656) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_Delay::TRIGGER_DONE, 658, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(20043, 656) {
    auto node656 = GET_SKILL_NODE(656, PhaseNode_Delay);
    if (node656 == nullptr) {
        node656 = new PhaseNode_Delay(656, phase);
        node656->setTime(.20f);
        CALL_REGISTER_SKILL_NODE(20043, 656, node656)
    }
    if (noInit == true) {
        return node656;
    }
    return node656;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(20043, 657) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 15, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(20043, 657) {
    auto node657 = GET_SKILL_NODE(657, PhaseNode_SkillEndNotify);
    if (node657 == nullptr) {
        node657 = new PhaseNode_SkillEndNotify(657, phase);
        node657->setReturnType(false);
        CALL_REGISTER_SKILL_NODE(20043, 657, node657)
    }
    if (noInit == true) {
        return node657;
    }
    return node657;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(20043, 658) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_FALSE, 659, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_TRUE, 657, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
}

REGISTER_CREATE_SKILL_NODE(20043, 658) {
    auto node658 = GET_SKILL_NODE(658, PhaseNode_If);
    if (node658 == nullptr) {
        node658 = new PhaseNode_If(658, phase);
        node658->setCondition(false);
        CALL_REGISTER_SKILL_NODE(20043, 658, node658)
    }
    if (noInit == true) {
        return node658;
    }
    return node658;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(20043, 659) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 15, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(20043, 659) {
    auto node659 = GET_SKILL_NODE(659, PhaseNode_SkillEndNotify);
    if (node659 == nullptr) {
        node659 = new PhaseNode_SkillEndNotify(659, phase);
        node659->setReturnType(true);
        CALL_REGISTER_SKILL_NODE(20043, 659, node659)
    }
    if (noInit == true) {
        return node659;
    }
    return node659;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(20043, 660) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetRotation>(PhaseNode_GetLocation::TRIGGER_DONE, 661, PhaseNode_GetRotation::FUNC_DO, &PhaseNode_GetRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(20043, 660) {
    auto node660 = GET_SKILL_NODE(660, PhaseNode_GetLocation);
    if (node660 == nullptr) {
        node660 = new PhaseNode_GetLocation(660, phase);
        node660->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node660->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(20043, 660, node660)
    }
    if (noInit == true) {
        return node660;
    }
    return node660;
}
//--------------------------------------------------------------------------------
// GetRotation
//
REGISTER_REGISTER_SKILL_NODE(20043, 661) {
    pnode->resizeTrigger(PhaseNode_GetRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_OffsetCalculate>(PhaseNode_GetRotation::TRIGGER_DONE, 662, PhaseNode_OffsetCalculate::FUNC_DO, &PhaseNode_OffsetCalculate::Do);
}

REGISTER_CREATE_SKILL_NODE(20043, 661) {
    auto node661 = GET_SKILL_NODE(661, PhaseNode_GetRotation);
    if (node661 == nullptr) {
        node661 = new PhaseNode_GetRotation(661, phase);
        node661->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node661->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(20043, 661, node661)
    }
    if (noInit == true) {
        return node661;
    }
    return node661;
}
//--------------------------------------------------------------------------------
// OffsetCalculate
//
REGISTER_REGISTER_SKILL_NODE(20043, 662) {
    pnode->resizeTrigger(PhaseNode_OffsetCalculate::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 664, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(20043, 662) {
    auto node662 = GET_SKILL_NODE(662, PhaseNode_OffsetCalculate);
    if (node662 == nullptr) {
        node662 = new PhaseNode_OffsetCalculate(662, phase);
        node662->setPosZ(.00f);
        node662->setOffsetX(.00f);
        node662->setOffsetY(2.00f);
        node662->setOffsetZ(.00f);
        node662->setRotOffset(.00f);
        CALL_REGISTER_SKILL_NODE(20043, 662, node662)
    }
    if (noInit == true) {
        return node662;
    }
    auto node660 = GET_SKILL_NODE(660, PhaseNode_GetLocation);
    auto node661 = GET_SKILL_NODE(661, PhaseNode_GetRotation);
    if (node660 != nullptr) node662->setPosX(node660->getX());
    if (node660 != nullptr) node662->setPosY(node660->getY());
    if (node661 != nullptr) node662->setRotation(node661->getAngle());
    return node662;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(20043, 663) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_PlayEffect::TRIGGER_DONE, 666, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(20043, 663) {
    auto node663 = GET_SKILL_NODE(663, PhaseNode_PlayEffect);
    if (node663 == nullptr) {
        node663 = new PhaseNode_PlayEffect(663, phase);
        node663->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node663->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node663->setEffectID(1049);
        node663->setChangeColor(false);
        node663->setType(PhaseNode_PlayEffect::PlayEffect_Type::WithTarget);
        node663->getVars().reserve(5);
        node663->getVars().setVariable<uint64_t>(0, 0U);
        node663->getVars().setVariable<std::string>(1, "");
        node663->getVars().setVariable<float>(2, .00f);
        node663->getVars().setVariable<float>(3, .00f);
        node663->getVars().setVariable<float>(4, .00f);
        node663->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(20043, 663, node663)
    }
    if (noInit == true) {
        return node663;
    }
    auto node662 = GET_SKILL_NODE(662, PhaseNode_OffsetCalculate);
    if (node662 != nullptr) node663->getVars().setVariable<float>(2, node662->getOutPosX());
    if (node662 != nullptr) node663->getVars().setVariable<float>(3, node662->getOutPosY());
    if (node662 != nullptr) node663->getVars().setVariable<float>(4, node662->getOutPosZ());
    if (node662 != nullptr) node663->setRotation(node662->getOutRotation());
    return node663;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(20043, 664) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_FALSE, 665, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_TRUE, 663, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(20043, 664) {
    auto node664 = GET_SKILL_NODE(664, PhaseNode_If);
    if (node664 == nullptr) {
        node664 = new PhaseNode_If(664, phase);
        node664->setCondition(false);
        CALL_REGISTER_SKILL_NODE(20043, 664, node664)
    }
    if (noInit == true) {
        return node664;
    }
    return node664;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(20043, 665) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_PlayEffect::TRIGGER_DONE, 666, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(20043, 665) {
    auto node665 = GET_SKILL_NODE(665, PhaseNode_PlayEffect);
    if (node665 == nullptr) {
        node665 = new PhaseNode_PlayEffect(665, phase);
        node665->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node665->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node665->setEffectID(1049);
        node665->setChangeColor(false);
        node665->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node665->getVars().reserve(3);
        node665->getVars().setVariable<float>(0, .00f);
        node665->getVars().setVariable<float>(1, .00f);
        node665->getVars().setVariable<float>(2, .00f);
        node665->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(20043, 665, node665)
    }
    if (noInit == true) {
        return node665;
    }
    auto node662 = GET_SKILL_NODE(662, PhaseNode_OffsetCalculate);
    if (node662 != nullptr) node665->getVars().setVariable<float>(0, node662->getOutPosX());
    if (node662 != nullptr) node665->getVars().setVariable<float>(1, node662->getOutPosY());
    if (node662 != nullptr) node665->getVars().setVariable<float>(2, node662->getOutPosZ());
    if (node662 != nullptr) node665->setRotation(node662->getOutRotation());
    return node665;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(20043, 666) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CameraShake>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 602, PhaseNode_CameraShake::FUNC_DO, &PhaseNode_CameraShake::Do);
    pnode->regTrigger<PhaseNode_CameraShake>(PhaseNode_CompareFloat::TRIGGER_LESS, 602, PhaseNode_CameraShake::FUNC_DO, &PhaseNode_CameraShake::Do);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_LESS, 667, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(20043, 666) {
    auto node666 = GET_SKILL_NODE(666, PhaseNode_CompareFloat);
    if (node666 == nullptr) {
        node666 = new PhaseNode_CompareFloat(666, phase);
        node666->setA(.00f);
        node666->setB(.00f);
        CALL_REGISTER_SKILL_NODE(20043, 666, node666)
    }
    if (noInit == true) {
        return node666;
    }
    return node666;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(20043, 667) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StopEffect>(PhaseNode_Delay::TRIGGER_DONE, 668, PhaseNode_StopEffect::FUNC_DO, &PhaseNode_StopEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(20043, 667) {
    auto node667 = GET_SKILL_NODE(667, PhaseNode_Delay);
    if (node667 == nullptr) {
        node667 = new PhaseNode_Delay(667, phase);
        node667->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(20043, 667, node667)
    }
    if (noInit == true) {
        return node667;
    }
    return node667;
}
//--------------------------------------------------------------------------------
// StopEffect
//
REGISTER_REGISTER_SKILL_NODE(20043, 668) {
}

REGISTER_CREATE_SKILL_NODE(20043, 668) {
    auto node668 = GET_SKILL_NODE(668, PhaseNode_StopEffect);
    if (node668 == nullptr) {
        node668 = new PhaseNode_StopEffect(668, phase);
        node668->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node668->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node668->setEffectID(1049);
        CALL_REGISTER_SKILL_NODE(20043, 668, node668)
    }
    if (noInit == true) {
        return node668;
    }
    return node668;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(20043, 669) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_Delay::TRIGGER_DONE, 671, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(20043, 669) {
    auto node669 = GET_SKILL_NODE(669, PhaseNode_Delay);
    if (node669 == nullptr) {
        node669 = new PhaseNode_Delay(669, phase);
        node669->setTime(3.00f);
        CALL_REGISTER_SKILL_NODE(20043, 669, node669)
    }
    if (noInit == true) {
        return node669;
    }
    return node669;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(20043, 670) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 148, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(20043, 670) {
    auto node670 = GET_SKILL_NODE(670, PhaseNode_SkillEndNotify);
    if (node670 == nullptr) {
        node670 = new PhaseNode_SkillEndNotify(670, phase);
        node670->setReturnType(false);
        CALL_REGISTER_SKILL_NODE(20043, 670, node670)
    }
    if (noInit == true) {
        return node670;
    }
    return node670;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(20043, 671) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_FALSE, 672, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_TRUE, 670, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
}

REGISTER_CREATE_SKILL_NODE(20043, 671) {
    auto node671 = GET_SKILL_NODE(671, PhaseNode_If);
    if (node671 == nullptr) {
        node671 = new PhaseNode_If(671, phase);
        node671->setCondition(false);
        CALL_REGISTER_SKILL_NODE(20043, 671, node671)
    }
    if (noInit == true) {
        return node671;
    }
    return node671;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(20043, 672) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 148, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(20043, 672) {
    auto node672 = GET_SKILL_NODE(672, PhaseNode_SkillEndNotify);
    if (node672 == nullptr) {
        node672 = new PhaseNode_SkillEndNotify(672, phase);
        node672->setReturnType(true);
        CALL_REGISTER_SKILL_NODE(20043, 672, node672)
    }
    if (noInit == true) {
        return node672;
    }
    return node672;
}
//--------------------------------------------------------------------------------
// AttachTo
//
REGISTER_REGISTER_SKILL_NODE(20043, 673) {
    pnode->resizeTrigger(PhaseNode_AttachTo::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_MoveNewPene>(PhaseNode_AttachTo::TRIGGER_DONE, 677, PhaseNode_MoveNewPene::FUNC_DO, &PhaseNode_MoveNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(20043, 673) {
    auto node673 = GET_SKILL_NODE(673, PhaseNode_AttachTo);
    if (node673 == nullptr) {
        node673 = new PhaseNode_AttachTo(673, phase);
        node673->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node673->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node673->setChild(0U);
        node673->setChangeRotation(true);
        node673->setreentry(false);
        CALL_REGISTER_SKILL_NODE(20043, 673, node673)
    }
    if (noInit == true) {
        return node673;
    }
    auto node9 = GET_SKILL_NODE(9, PhaseNode_SpawnCollider);
    if (node9 != nullptr) node673->setParent(node9->getColliderID());
    return node673;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(20043, 675) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_PlayAnimation::TRIGGER_DONE, 676, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(20043, 675) {
    auto node675 = GET_SKILL_NODE(675, PhaseNode_PlayAnimation);
    if (node675 == nullptr) {
        node675 = new PhaseNode_PlayAnimation(675, phase);
        node675->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node675->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node675->setTarget(0U);
        node675->setAnimation("Skill3S2");
        node675->setParameter("");
        node675->setValue(false);
        CALL_REGISTER_SKILL_NODE(20043, 675, node675)
    }
    if (noInit == true) {
        return node675;
    }
    return node675;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(20043, 676) {
}

REGISTER_CREATE_SKILL_NODE(20043, 676) {
    auto node676 = GET_SKILL_NODE(676, PhaseNode_PlaySound);
    if (node676 == nullptr) {
        node676 = new PhaseNode_PlaySound(676, phase);
        node676->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node676->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node676->setSoundID("SE_MON2004_Skill_A_P1");
        node676->setTarget(0U);
        node676->setUsePos(false);
        node676->setPosX(.00f);
        node676->setPosY(.00f);
        node676->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(20043, 676, node676)
    }
    if (noInit == true) {
        return node676;
    }
    return node676;
}
//--------------------------------------------------------------------------------
// MoveNewPene
//
REGISTER_REGISTER_SKILL_NODE(20043, 677) {
    pnode->resizeTrigger(PhaseNode_MoveNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuff>(PhaseNode_MoveNewPene::TRIGGER_BLOCKBYWALL, 446, PhaseNode_AddSkillBuff::FUNC_ADD, &PhaseNode_AddSkillBuff::Add);
    pnode->regTrigger<PhaseNode_DestroyCollider>(PhaseNode_MoveNewPene::TRIGGER_BLOCKBYWALL, 248, PhaseNode_DestroyCollider::FUNC_DO, &PhaseNode_DestroyCollider::Do);
    pnode->regTrigger<PhaseNode_DestroyCollider>(PhaseNode_MoveNewPene::TRIGGER_DONE, 248, PhaseNode_DestroyCollider::FUNC_DO, &PhaseNode_DestroyCollider::Do);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_MoveNewPene::TRIGGER_STARTMOVE, 651, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_MoveNewPene::TRIGGER_STARTMOVE, 675, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(20043, 677) {
    auto node677 = GET_SKILL_NODE(677, PhaseNode_MoveNewPene);
    if (node677 == nullptr) {
        node677 = new PhaseNode_MoveNewPene(677, phase);
        node677->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node677->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node677->setPeneType(PhaseNode_MoveNewPene::MoveNewPene_PeneType::Move);
        node677->setPeneValue(0);
        node677->setType(PhaseNode_MoveNewPene::MoveNewPene_Type::Charge);
        node677->getVars().reserve(4);
        node677->getVars().setVariable<float>(0, 18.00f);
        node677->getVars().setVariable<float>(1, 18.00f);
        node677->getVars().setVariable<float>(2, .00f);
        node677->getVars().setVariable<float>(3, .00f);
        node677->setreentry(false);
        node677->setStopWhenFail(true);
        node677->setCheckFaction(PhaseNode_MoveNewPene::MoveNewPene_CheckFaction::Enemy);
        CALL_REGISTER_SKILL_NODE(20043, 677, node677)
    }
    if (noInit == true) {
        return node677;
    }
    auto node9 = GET_SKILL_NODE(9, PhaseNode_SpawnCollider);
    auto node640 = GET_SKILL_NODE(640, PhaseNode_OffsetCalculate);
    if (node9 != nullptr) node677->setTarget(node9->getColliderID());
    if (node640 != nullptr) node677->getVars().setVariable<float>(2, node640->getOutRotation());
    return node677;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(20043, 678) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_PlayEffect::TRIGGER_DONE, 681, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(20043, 678) {
    auto node678 = GET_SKILL_NODE(678, PhaseNode_PlayEffect);
    if (node678 == nullptr) {
        node678 = new PhaseNode_PlayEffect(678, phase);
        node678->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node678->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node678->setEffectID(0);
        node678->setChangeColor(false);
        node678->setType(PhaseNode_PlayEffect::PlayEffect_Type::WithTarget);
        node678->getVars().reserve(5);
        node678->getVars().setVariable<uint64_t>(0, 0U);
        node678->getVars().setVariable<std::string>(1, "");
        node678->getVars().setVariable<float>(2, .00f);
        node678->getVars().setVariable<float>(3, .00f);
        node678->getVars().setVariable<float>(4, .00f);
        node678->setScale(.00f);
        CALL_REGISTER_SKILL_NODE(20043, 678, node678)
    }
    if (noInit == true) {
        return node678;
    }
    auto node9 = GET_SKILL_NODE(9, PhaseNode_SpawnCollider);
    auto node640 = GET_SKILL_NODE(640, PhaseNode_OffsetCalculate);
    if (node9 != nullptr) node678->getVars().setVariable<uint64_t>(0, node9->getColliderID());
    if (node640 != nullptr) node678->setRotation(node640->getOutRotation());
    return node678;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(20043, 679) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_FALSE, 680, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_TRUE, 678, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(20043, 679) {
    auto node679 = GET_SKILL_NODE(679, PhaseNode_If);
    if (node679 == nullptr) {
        node679 = new PhaseNode_If(679, phase);
        node679->setCondition(false);
        CALL_REGISTER_SKILL_NODE(20043, 679, node679)
    }
    if (noInit == true) {
        return node679;
    }
    return node679;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(20043, 680) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_PlayEffect::TRIGGER_DONE, 681, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(20043, 680) {
    auto node680 = GET_SKILL_NODE(680, PhaseNode_PlayEffect);
    if (node680 == nullptr) {
        node680 = new PhaseNode_PlayEffect(680, phase);
        node680->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node680->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node680->setEffectID(0);
        node680->setChangeColor(false);
        node680->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node680->getVars().reserve(3);
        node680->getVars().setVariable<float>(0, .00f);
        node680->getVars().setVariable<float>(1, .00f);
        node680->getVars().setVariable<float>(2, .00f);
        node680->setScale(.00f);
        CALL_REGISTER_SKILL_NODE(20043, 680, node680)
    }
    if (noInit == true) {
        return node680;
    }
    auto node640 = GET_SKILL_NODE(640, PhaseNode_OffsetCalculate);
    if (node640 != nullptr) node680->setRotation(node640->getOutRotation());
    return node680;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(20043, 681) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AttachTo>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 673, PhaseNode_AttachTo::FUNC_DO, &PhaseNode_AttachTo::Do);
    pnode->regTrigger<PhaseNode_AttachTo>(PhaseNode_CompareFloat::TRIGGER_LESS, 673, PhaseNode_AttachTo::FUNC_DO, &PhaseNode_AttachTo::Do);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_LESS, 682, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(20043, 681) {
    auto node681 = GET_SKILL_NODE(681, PhaseNode_CompareFloat);
    if (node681 == nullptr) {
        node681 = new PhaseNode_CompareFloat(681, phase);
        node681->setA(.00f);
        node681->setB(.00f);
        CALL_REGISTER_SKILL_NODE(20043, 681, node681)
    }
    if (noInit == true) {
        return node681;
    }
    return node681;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(20043, 682) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StopEffect>(PhaseNode_Delay::TRIGGER_DONE, 683, PhaseNode_StopEffect::FUNC_DO, &PhaseNode_StopEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(20043, 682) {
    auto node682 = GET_SKILL_NODE(682, PhaseNode_Delay);
    if (node682 == nullptr) {
        node682 = new PhaseNode_Delay(682, phase);
        node682->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(20043, 682, node682)
    }
    if (noInit == true) {
        return node682;
    }
    return node682;
}
//--------------------------------------------------------------------------------
// StopEffect
//
REGISTER_REGISTER_SKILL_NODE(20043, 683) {
}

REGISTER_CREATE_SKILL_NODE(20043, 683) {
    auto node683 = GET_SKILL_NODE(683, PhaseNode_StopEffect);
    if (node683 == nullptr) {
        node683 = new PhaseNode_StopEffect(683, phase);
        node683->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node683->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node683->setEffectID(0);
        CALL_REGISTER_SKILL_NODE(20043, 683, node683)
    }
    if (noInit == true) {
        return node683;
    }
    return node683;
}

//--------------------------------------------------------------------------------
// SkillCreator_20043
//
class SkillCreator_20043 : public SkillCreator {
public:
    SkillCreator_20043() {}
    virtual ~SkillCreator_20043() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_20043

//--------------------------------------------------------------------------------
// SkillPhase_20043
//
class SkillPhase_20043 : public SkillPhase {
public:
    SkillPhase_20043(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_20043() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(20043, 1) // StartPhase
        CASE_CREATE_SKILL_NODE(20043, 2) // Delay
        CASE_CREATE_SKILL_NODE(20043, 3) // TriggerUpdate
        CASE_CREATE_SKILL_NODE(20043, 9) // SpawnCollider
        CASE_CREATE_SKILL_NODE(20043, 14) // PlayAnimation
        CASE_CREATE_SKILL_NODE(20043, 15) // EndPhase
        CASE_CREATE_SKILL_NODE(20043, 87) // EndPhase
        CASE_CREATE_SKILL_NODE(20043, 88) // Detect
        CASE_CREATE_SKILL_NODE(20043, 148) // EndPhase
        CASE_CREATE_SKILL_NODE(20043, 248) // DestroyCollider
        CASE_CREATE_SKILL_NODE(20043, 446) // AddSkillBuff
        CASE_CREATE_SKILL_NODE(20043, 512) // PlaySound
        CASE_CREATE_SKILL_NODE(20043, 539) // PlaySound
        CASE_CREATE_SKILL_NODE(20043, 602) // CameraShake
        CASE_CREATE_SKILL_NODE(20043, 607) // StopSound
        CASE_CREATE_SKILL_NODE(20043, 609) // StopSound
        CASE_CREATE_SKILL_NODE(20043, 611) // EndPhase
        CASE_CREATE_SKILL_NODE(20043, 613) // Detect
        CASE_CREATE_SKILL_NODE(20043, 614) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(20043, 615) // TriggerCheck
        CASE_CREATE_SKILL_NODE(20043, 616) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(20043, 617) // GetActorAttribute
        CASE_CREATE_SKILL_NODE(20043, 618) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(20043, 619) // CompareFloat
        CASE_CREATE_SKILL_NODE(20043, 620) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(20043, 621) // If
        CASE_CREATE_SKILL_NODE(20043, 622) // CompareFloat
        CASE_CREATE_SKILL_NODE(20043, 623) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(20043, 624) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(20043, 625) // TriggerCheck
        CASE_CREATE_SKILL_NODE(20043, 626) // TriggerCheck
        CASE_CREATE_SKILL_NODE(20043, 627) // TriggerCheck
        CASE_CREATE_SKILL_NODE(20043, 628) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(20043, 629) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(20043, 630) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(20043, 631) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(20043, 632) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(20043, 633) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(20043, 634) // ResetCD
        CASE_CREATE_SKILL_NODE(20043, 635) // PlayAnimation
        CASE_CREATE_SKILL_NODE(20043, 636) // PlaySound
        CASE_CREATE_SKILL_NODE(20043, 637) // Delay
        CASE_CREATE_SKILL_NODE(20043, 638) // GetLocation
        CASE_CREATE_SKILL_NODE(20043, 639) // GetRotation
        CASE_CREATE_SKILL_NODE(20043, 640) // OffsetCalculate
        CASE_CREATE_SKILL_NODE(20043, 641) // GetLocation
        CASE_CREATE_SKILL_NODE(20043, 642) // GetRotation
        CASE_CREATE_SKILL_NODE(20043, 643) // OffsetCalculate
        CASE_CREATE_SKILL_NODE(20043, 644) // PlayEffect
        CASE_CREATE_SKILL_NODE(20043, 645) // If
        CASE_CREATE_SKILL_NODE(20043, 646) // PlayEffect
        CASE_CREATE_SKILL_NODE(20043, 647) // CompareFloat
        CASE_CREATE_SKILL_NODE(20043, 648) // Delay
        CASE_CREATE_SKILL_NODE(20043, 649) // StopEffect
        CASE_CREATE_SKILL_NODE(20043, 650) // PlayEffect
        CASE_CREATE_SKILL_NODE(20043, 651) // If
        CASE_CREATE_SKILL_NODE(20043, 652) // PlayEffect
        CASE_CREATE_SKILL_NODE(20043, 653) // CompareFloat
        CASE_CREATE_SKILL_NODE(20043, 654) // Delay
        CASE_CREATE_SKILL_NODE(20043, 655) // StopEffect
        CASE_CREATE_SKILL_NODE(20043, 656) // Delay
        CASE_CREATE_SKILL_NODE(20043, 657) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(20043, 658) // If
        CASE_CREATE_SKILL_NODE(20043, 659) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(20043, 660) // GetLocation
        CASE_CREATE_SKILL_NODE(20043, 661) // GetRotation
        CASE_CREATE_SKILL_NODE(20043, 662) // OffsetCalculate
        CASE_CREATE_SKILL_NODE(20043, 663) // PlayEffect
        CASE_CREATE_SKILL_NODE(20043, 664) // If
        CASE_CREATE_SKILL_NODE(20043, 665) // PlayEffect
        CASE_CREATE_SKILL_NODE(20043, 666) // CompareFloat
        CASE_CREATE_SKILL_NODE(20043, 667) // Delay
        CASE_CREATE_SKILL_NODE(20043, 668) // StopEffect
        CASE_CREATE_SKILL_NODE(20043, 669) // Delay
        CASE_CREATE_SKILL_NODE(20043, 670) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(20043, 671) // If
        CASE_CREATE_SKILL_NODE(20043, 672) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(20043, 673) // AttachTo
        CASE_CREATE_SKILL_NODE(20043, 675) // PlayAnimation
        CASE_CREATE_SKILL_NODE(20043, 676) // PlaySound
        CASE_CREATE_SKILL_NODE(20043, 677) // MoveNewPene
        CASE_CREATE_SKILL_NODE(20043, 678) // PlayEffect
        CASE_CREATE_SKILL_NODE(20043, 679) // If
        CASE_CREATE_SKILL_NODE(20043, 680) // PlayEffect
        CASE_CREATE_SKILL_NODE(20043, 681) // CompareFloat
        CASE_CREATE_SKILL_NODE(20043, 682) // Delay
        CASE_CREATE_SKILL_NODE(20043, 683) // StopEffect
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_20043

SkillLogic* SkillCreator_20043::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //创建阶段phase
    auto phase = new SkillPhase_20043(1, logic, 3);
    //设置phase执行器
    phase->setRunPhaseNode(1, 1);
    phase->setRunPhaseNode(2, 3);
    phase->setDetectPhaseNode(3, 88);
    phase->setDetectPhaseNode(3, 613);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_20043::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
