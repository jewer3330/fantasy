#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

#include "skill_psnode_addskillbuff.h"
#include "skill_psnode_addskillbuffs.h"
#include "skill_psnode_areacollisionnewpene.h"
#include "skill_psnode_attachto.h"
#include "skill_psnode_confirmphase.h"
#include "skill_psnode_delay.h"
#include "skill_psnode_detect.h"
#include "skill_psnode_disable.h"
#include "skill_psnode_endflow.h"
#include "skill_psnode_endphase.h"
#include "skill_psnode_getactorattribute.h"
#include "skill_psnode_getinputlocation.h"
#include "skill_psnode_getlocation.h"
#include "skill_psnode_if.h"
#include "skill_psnode_isinterrupttype.h"
#include "skill_psnode_linechecknewpene.h"
#include "skill_psnode_movenewpene.h"
#include "skill_psnode_playanimation.h"
#include "skill_psnode_playeffect.h"
#include "skill_psnode_playsound.h"
#include "skill_psnode_raiseevent.h"
#include "skill_psnode_removeskillbuff.h"
#include "skill_psnode_resetcd.h"
#include "skill_psnode_resetskill.h"
#include "skill_psnode_setbool.h"
#include "skill_psnode_spawncollider.h"
#include "skill_psnode_startphase.h"
#include "skill_psnode_startpreinput.h"
#include "skill_psnode_switchtoint.h"

namespace pvp {

//变量声明
uint64_t Variable_10233_anxia = 0;
uint64_t Variable_10233_a102332 = 0;
uint64_t Variable_10233_InterruptAnimat = 0;
//--------------------------------------------------------------------------------
// StartPhase
//
REGISTER_REGISTER_SKILL_NODE(10233, 1) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_StartPhase::TRIGGER_START, 885, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(10233, 1) {
    auto node1 = GET_SKILL_NODE(1, PhaseNode_StartPhase);
    if (node1 == nullptr) {
        node1 = new PhaseNode_StartPhase(1, phase);
        CALL_REGISTER_SKILL_NODE(10233, 1, node1)
    }
    if (noInit == true) {
        return node1;
    }
    return node1;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10233, 391) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_PlaySound::TRIGGER_DONE, 830, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10233, 391) {
    auto node391 = GET_SKILL_NODE(391, PhaseNode_PlaySound);
    if (node391 == nullptr) {
        node391 = new PhaseNode_PlaySound(391, phase);
        node391->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node391->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node391->setSoundID("SE_Hero106_SkillC_P1");
        node391->setTarget(0U);
        node391->setUsePos(false);
        node391->setPosX(.00f);
        node391->setPosY(.00f);
        node391->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10233, 391, node391)
    }
    if (noInit == true) {
        return node391;
    }
    return node391;
}
//--------------------------------------------------------------------------------
// ConfirmPhase
//
REGISTER_REGISTER_SKILL_NODE(10233, 719) {
    pnode->resizeTrigger(PhaseNode_ConfirmPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_ConfirmPhase::TRIGGER_CONFIRM, 838, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(10233, 719) {
    auto node719 = GET_SKILL_NODE(719, PhaseNode_ConfirmPhase);
    if (node719 == nullptr) {
        node719 = new PhaseNode_ConfirmPhase(719, phase);
        CALL_REGISTER_SKILL_NODE(10233, 719, node719)
    }
    if (noInit == true) {
        return node719;
    }
    return node719;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10233, 731) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ResetSkill>(PhaseNode_PlayAnimation::TRIGGER_DONE, 820, PhaseNode_ResetSkill::FUNC_DO, &PhaseNode_ResetSkill::Do);
}

REGISTER_CREATE_SKILL_NODE(10233, 731) {
    auto node731 = GET_SKILL_NODE(731, PhaseNode_PlayAnimation);
    if (node731 == nullptr) {
        node731 = new PhaseNode_PlayAnimation(731, phase);
        node731->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node731->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node731->setTarget(0U);
        node731->setAnimation("Skill3S3");
        node731->setParameter("");
        node731->setValue(false);
        CALL_REGISTER_SKILL_NODE(10233, 731, node731)
    }
    if (noInit == true) {
        return node731;
    }
    return node731;
}
//--------------------------------------------------------------------------------
// AddSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10233, 735) {
    pnode->resizeTrigger(PhaseNode_AddSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_AddSkillBuff::TRIGGER_DONE, 773, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10233, 735) {
    auto node735 = GET_SKILL_NODE(735, PhaseNode_AddSkillBuff);
    if (node735 == nullptr) {
        node735 = new PhaseNode_AddSkillBuff(735, phase);
        node735->setConfigID(0);
        node735->setConfigIDs({102334,102335});
        node735->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(10233, 735, node735)
    }
    if (noInit == true) {
        return node735;
    }
    auto node888 = GET_SKILL_NODE(888, PhaseNode_GetActorAttribute);
    if (node888 != nullptr) node735->setAttribute(node888->getAttribute());
    return node735;
}
//--------------------------------------------------------------------------------
// Disable
//
REGISTER_REGISTER_SKILL_NODE(10233, 738) {
    pnode->resizeTrigger(PhaseNode_Disable::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_Disable::TRIGGER_DONE, 753, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(10233, 738) {
    auto node738 = GET_SKILL_NODE(738, PhaseNode_Disable);
    if (node738 == nullptr) {
        node738 = new PhaseNode_Disable(738, phase);
        node738->setTarget(0U);
        node738->setMove(true);
        node738->setSkill(true);
        node738->setShoot(true);
        node738->setTime(1.00f);
        node738->setRotate(true);
        CALL_REGISTER_SKILL_NODE(10233, 738, node738)
    }
    if (noInit == true) {
        return node738;
    }
    return node738;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(10233, 746) {
}

REGISTER_CREATE_SKILL_NODE(10233, 746) {
    auto node746 = GET_SKILL_NODE(746, PhaseNode_EndPhase);
    if (node746 == nullptr) {
        node746 = new PhaseNode_EndPhase(746, phase);
        node746->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node746->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10233, 746, node746)
    }
    if (noInit == true) {
        return node746;
    }
    return node746;
}
//--------------------------------------------------------------------------------
// SpawnCollider
//
REGISTER_REGISTER_SKILL_NODE(10233, 749) {
    pnode->resizeTrigger(PhaseNode_SpawnCollider::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AttachTo>(PhaseNode_SpawnCollider::TRIGGER_DONE, 787, PhaseNode_AttachTo::FUNC_DO, &PhaseNode_AttachTo::Do);
}

REGISTER_CREATE_SKILL_NODE(10233, 749) {
    auto node749 = GET_SKILL_NODE(749, PhaseNode_SpawnCollider);
    if (node749 == nullptr) {
        node749 = new PhaseNode_SpawnCollider(749, phase);
        node749->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node749->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node749->setMesh("");
        node749->setMeshScale(1.00f);
        node749->setEffectID(0);
        node749->setEffectScale(.00f);
        node749->setType(PhaseNode_SpawnCollider::SpawnCollider_Type::Circle);
        node749->setTypeParams(0, .60f);
        node749->setTime(1.00f);
        node749->setPosZ(.00f);
        node749->setRotation(.00f);
        node749->setreentry(false);
        node749->setCheckPeneSound(true);
        CALL_REGISTER_SKILL_NODE(10233, 749, node749)
    }
    if (noInit == true) {
        return node749;
    }
    auto node753 = GET_SKILL_NODE(753, PhaseNode_GetLocation);
    if (node753 != nullptr) node749->setPosX(node753->getX());
    if (node753 != nullptr) node749->setPosY(node753->getY());
    return node749;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(10233, 753) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetInputLocation>(PhaseNode_GetLocation::TRIGGER_DONE, 780, PhaseNode_GetInputLocation::FUNC_DO, &PhaseNode_GetInputLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(10233, 753) {
    auto node753 = GET_SKILL_NODE(753, PhaseNode_GetLocation);
    if (node753 == nullptr) {
        node753 = new PhaseNode_GetLocation(753, phase);
        node753->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node753->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(10233, 753, node753)
    }
    if (noInit == true) {
        return node753;
    }
    return node753;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(10233, 758) {
}

REGISTER_CREATE_SKILL_NODE(10233, 758) {
    auto node758 = GET_SKILL_NODE(758, PhaseNode_AddSkillBuffs);
    if (node758 == nullptr) {
        node758 = new PhaseNode_AddSkillBuffs(758, phase);
        node758->setConfigID({102336,102322});
        CALL_REGISTER_SKILL_NODE(10233, 758, node758)
    }
    if (noInit == true) {
        return node758;
    }
    auto node884 = GET_SKILL_NODE(884, PhaseNode_LineCheckNewPene);
    auto node888 = GET_SKILL_NODE(888, PhaseNode_GetActorAttribute);
    if (node884 != nullptr) node758->setTarget(node884->getOutput());
    if (node888 != nullptr) node758->setAttribute(node888->getAttribute());
    return node758;
}
//--------------------------------------------------------------------------------
// EndFlow
//
REGISTER_REGISTER_SKILL_NODE(10233, 767) {
}

REGISTER_CREATE_SKILL_NODE(10233, 767) {
    auto node767 = GET_SKILL_NODE(767, PhaseNode_EndFlow);
    if (node767 == nullptr) {
        node767 = new PhaseNode_EndFlow(767, phase);
        CALL_REGISTER_SKILL_NODE(10233, 767, node767)
    }
    if (noInit == true) {
        return node767;
    }
    return node767;
}
//--------------------------------------------------------------------------------
// Disable
//
REGISTER_REGISTER_SKILL_NODE(10233, 769) {
    pnode->resizeTrigger(PhaseNode_Disable::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_Disable::TRIGGER_DONE, 809, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(10233, 769) {
    auto node769 = GET_SKILL_NODE(769, PhaseNode_Disable);
    if (node769 == nullptr) {
        node769 = new PhaseNode_Disable(769, phase);
        node769->setTarget(0U);
        node769->setMove(true);
        node769->setSkill(true);
        node769->setShoot(true);
        node769->setTime(5.00f);
        node769->setRotate(true);
        CALL_REGISTER_SKILL_NODE(10233, 769, node769)
    }
    if (noInit == true) {
        return node769;
    }
    return node769;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10233, 773) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_Delay::TRIGGER_DONE, 777, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10233, 773) {
    auto node773 = GET_SKILL_NODE(773, PhaseNode_Delay);
    if (node773 == nullptr) {
        node773 = new PhaseNode_Delay(773, phase);
        node773->setTime(.43f);
        CALL_REGISTER_SKILL_NODE(10233, 773, node773)
    }
    if (noInit == true) {
        return node773;
    }
    return node773;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10233, 777) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlayAnimation::TRIGGER_DONE, 844, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_EndFlow>(PhaseNode_PlayAnimation::TRIGGER_DONE, 767, PhaseNode_EndFlow::FUNC_DO, &PhaseNode_EndFlow::Do);
}

REGISTER_CREATE_SKILL_NODE(10233, 777) {
    auto node777 = GET_SKILL_NODE(777, PhaseNode_PlayAnimation);
    if (node777 == nullptr) {
        node777 = new PhaseNode_PlayAnimation(777, phase);
        node777->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node777->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node777->setTarget(0U);
        node777->setAnimation("Skill3S2");
        node777->setParameter("");
        node777->setValue(false);
        CALL_REGISTER_SKILL_NODE(10233, 777, node777)
    }
    if (noInit == true) {
        return node777;
    }
    return node777;
}
//--------------------------------------------------------------------------------
// GetInputLocation
//
REGISTER_REGISTER_SKILL_NODE(10233, 780) {
    pnode->resizeTrigger(PhaseNode_GetInputLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_GetInputLocation::TRIGGER_DONE, 872, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(10233, 780) {
    auto node780 = GET_SKILL_NODE(780, PhaseNode_GetInputLocation);
    if (node780 == nullptr) {
        node780 = new PhaseNode_GetInputLocation(780, phase);
        node780->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        CALL_REGISTER_SKILL_NODE(10233, 780, node780)
    }
    if (noInit == true) {
        return node780;
    }
    return node780;
}
//--------------------------------------------------------------------------------
// MoveNewPene
//
REGISTER_REGISTER_SKILL_NODE(10233, 785) {
    pnode->resizeTrigger(PhaseNode_MoveNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_MoveNewPene::TRIGGER_BLOCKBYWALL, 731, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_MoveNewPene::TRIGGER_DONE, 731, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10233, 785) {
    auto node785 = GET_SKILL_NODE(785, PhaseNode_MoveNewPene);
    if (node785 == nullptr) {
        node785 = new PhaseNode_MoveNewPene(785, phase);
        node785->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node785->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node785->setPeneType(PhaseNode_MoveNewPene::MoveNewPene_PeneType::Move);
        node785->setPeneValue(25);
        node785->setType(PhaseNode_MoveNewPene::MoveNewPene_Type::Teleport);
        node785->getVars().reserve(2);
        node785->getVars().setVariable<float>(0, .00f);
        node785->getVars().setVariable<float>(1, .00f);
        node785->setreentry(false);
        node785->setStopWhenFail(true);
        node785->setCheckFaction(PhaseNode_MoveNewPene::MoveNewPene_CheckFaction::Enemy);
        CALL_REGISTER_SKILL_NODE(10233, 785, node785)
    }
    if (noInit == true) {
        return node785;
    }
    auto node749 = GET_SKILL_NODE(749, PhaseNode_SpawnCollider);
    auto node780 = GET_SKILL_NODE(780, PhaseNode_GetInputLocation);
    if (node749 != nullptr) node785->setTarget(node749->getColliderID());
    if (node780 != nullptr) node785->getVars().setVariable<float>(0, node780->getX());
    if (node780 != nullptr) node785->getVars().setVariable<float>(1, node780->getY());
    return node785;
}
//--------------------------------------------------------------------------------
// AttachTo
//
REGISTER_REGISTER_SKILL_NODE(10233, 787) {
    pnode->resizeTrigger(PhaseNode_AttachTo::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_MoveNewPene>(PhaseNode_AttachTo::TRIGGER_DONE, 785, PhaseNode_MoveNewPene::FUNC_DO, &PhaseNode_MoveNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(10233, 787) {
    auto node787 = GET_SKILL_NODE(787, PhaseNode_AttachTo);
    if (node787 == nullptr) {
        node787 = new PhaseNode_AttachTo(787, phase);
        node787->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node787->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node787->setChild(0U);
        node787->setChangeRotation(false);
        node787->setreentry(false);
        CALL_REGISTER_SKILL_NODE(10233, 787, node787)
    }
    if (noInit == true) {
        return node787;
    }
    auto node749 = GET_SKILL_NODE(749, PhaseNode_SpawnCollider);
    if (node749 != nullptr) node787->setParent(node749->getColliderID());
    return node787;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(10233, 809) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuff>(PhaseNode_PlayEffect::TRIGGER_DONE, 735, PhaseNode_AddSkillBuff::FUNC_ADD, &PhaseNode_AddSkillBuff::Add);
}

REGISTER_CREATE_SKILL_NODE(10233, 809) {
    auto node809 = GET_SKILL_NODE(809, PhaseNode_PlayEffect);
    if (node809 == nullptr) {
        node809 = new PhaseNode_PlayEffect(809, phase);
        node809->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node809->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node809->setEffectID(102331);
        node809->setChangeColor(true);
        node809->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node809->getVars().reserve(3);
        node809->getVars().setVariable<float>(0, .00f);
        node809->getVars().setVariable<float>(1, .00f);
        node809->getVars().setVariable<float>(2, .00f);
        node809->setRotation(.00f);
        node809->setScale(.00f);
        CALL_REGISTER_SKILL_NODE(10233, 809, node809)
    }
    if (noInit == true) {
        return node809;
    }
    auto node812 = GET_SKILL_NODE(812, PhaseNode_GetLocation);
    if (node812 != nullptr) node809->getVars().setVariable<float>(0, node812->getX());
    if (node812 != nullptr) node809->getVars().setVariable<float>(1, node812->getY());
    return node809;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(10233, 812) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Disable>(PhaseNode_GetLocation::TRIGGER_DONE, 769, PhaseNode_Disable::FUNC_DO, &PhaseNode_Disable::Do);
}

REGISTER_CREATE_SKILL_NODE(10233, 812) {
    auto node812 = GET_SKILL_NODE(812, PhaseNode_GetLocation);
    if (node812 == nullptr) {
        node812 = new PhaseNode_GetLocation(812, phase);
        node812->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node812->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(10233, 812, node812)
    }
    if (noInit == true) {
        return node812;
    }
    return node812;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(10233, 814) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlayEffect::TRIGGER_DONE, 852, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10233, 814) {
    auto node814 = GET_SKILL_NODE(814, PhaseNode_PlayEffect);
    if (node814 == nullptr) {
        node814 = new PhaseNode_PlayEffect(814, phase);
        node814->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node814->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node814->setEffectID(102333);
        node814->setChangeColor(true);
        node814->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node814->getVars().reserve(3);
        node814->getVars().setVariable<float>(0, .00f);
        node814->getVars().setVariable<float>(1, .00f);
        node814->getVars().setVariable<float>(2, .00f);
        node814->setRotation(.00f);
        node814->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(10233, 814, node814)
    }
    if (noInit == true) {
        return node814;
    }
    auto node828 = GET_SKILL_NODE(828, PhaseNode_GetLocation);
    if (node828 != nullptr) node814->getVars().setVariable<float>(0, node828->getX());
    if (node828 != nullptr) node814->getVars().setVariable<float>(1, node828->getY());
    return node814;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(10233, 816) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_PlayEffect::TRIGGER_DONE, 814, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(10233, 816) {
    auto node816 = GET_SKILL_NODE(816, PhaseNode_PlayEffect);
    if (node816 == nullptr) {
        node816 = new PhaseNode_PlayEffect(816, phase);
        node816->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node816->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node816->setEffectID(102332);
        node816->setChangeColor(true);
        node816->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node816->getVars().reserve(3);
        node816->getVars().setVariable<float>(0, .00f);
        node816->getVars().setVariable<float>(1, .00f);
        node816->getVars().setVariable<float>(2, .00f);
        node816->setRotation(.00f);
        node816->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(10233, 816, node816)
    }
    if (noInit == true) {
        return node816;
    }
    auto node828 = GET_SKILL_NODE(828, PhaseNode_GetLocation);
    if (node828 != nullptr) node816->getVars().setVariable<float>(0, node828->getX());
    if (node828 != nullptr) node816->getVars().setVariable<float>(1, node828->getY());
    return node816;
}
//--------------------------------------------------------------------------------
// ResetSkill
//
REGISTER_REGISTER_SKILL_NODE(10233, 820) {
    pnode->resizeTrigger(PhaseNode_ResetSkill::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_ResetSkill::TRIGGER_DONE, 828, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(10233, 820) {
    auto node820 = GET_SKILL_NODE(820, PhaseNode_ResetSkill);
    if (node820 == nullptr) {
        node820 = new PhaseNode_ResetSkill(820, phase);
        node820->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node820->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node820->setSkillID({10231});
        node820->setTime(20.00f);
        CALL_REGISTER_SKILL_NODE(10233, 820, node820)
    }
    if (noInit == true) {
        return node820;
    }
    return node820;
}
//--------------------------------------------------------------------------------
// RemoveSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10233, 824) {
    pnode->resizeTrigger(PhaseNode_RemoveSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RemoveSkillBuff>(PhaseNode_RemoveSkillBuff::TRIGGER_DONE, 826, PhaseNode_RemoveSkillBuff::FUNC_REMOVE, &PhaseNode_RemoveSkillBuff::Remove);
}

REGISTER_CREATE_SKILL_NODE(10233, 824) {
    auto node824 = GET_SKILL_NODE(824, PhaseNode_RemoveSkillBuff);
    if (node824 == nullptr) {
        node824 = new PhaseNode_RemoveSkillBuff(824, phase);
        node824->setBuffID(0U);
        node824->setBuffIDs({});
        node824->setConfigID(102334);
        node824->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(10233, 824, node824)
    }
    if (noInit == true) {
        return node824;
    }
    return node824;
}
//--------------------------------------------------------------------------------
// RemoveSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10233, 826) {
    pnode->resizeTrigger(PhaseNode_RemoveSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AreaCollisionNewPene>(PhaseNode_RemoveSkillBuff::TRIGGER_DONE, 848, PhaseNode_AreaCollisionNewPene::FUNC_DO, &PhaseNode_AreaCollisionNewPene::Do);
    pnode->regTrigger<PhaseNode_RemoveSkillBuff>(PhaseNode_RemoveSkillBuff::TRIGGER_DONE, 859, PhaseNode_RemoveSkillBuff::FUNC_REMOVE, &PhaseNode_RemoveSkillBuff::Remove);
}

REGISTER_CREATE_SKILL_NODE(10233, 826) {
    auto node826 = GET_SKILL_NODE(826, PhaseNode_RemoveSkillBuff);
    if (node826 == nullptr) {
        node826 = new PhaseNode_RemoveSkillBuff(826, phase);
        node826->setBuffID(0U);
        node826->setBuffIDs({});
        node826->setConfigID(102335);
        node826->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(10233, 826, node826)
    }
    if (noInit == true) {
        return node826;
    }
    return node826;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(10233, 828) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_GetLocation::TRIGGER_DONE, 832, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10233, 828) {
    auto node828 = GET_SKILL_NODE(828, PhaseNode_GetLocation);
    if (node828 == nullptr) {
        node828 = new PhaseNode_GetLocation(828, phase);
        node828->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        CALL_REGISTER_SKILL_NODE(10233, 828, node828)
    }
    if (noInit == true) {
        return node828;
    }
    auto node749 = GET_SKILL_NODE(749, PhaseNode_SpawnCollider);
    if (node749 != nullptr) node828->setTarget(node749->getColliderID());
    return node828;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10233, 830) {
}

REGISTER_CREATE_SKILL_NODE(10233, 830) {
    auto node830 = GET_SKILL_NODE(830, PhaseNode_PlaySound);
    if (node830 == nullptr) {
        node830 = new PhaseNode_PlaySound(830, phase);
        node830->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node830->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node830->setSoundID("SE_Hero106_SkillC_P1");
        node830->setTarget(0U);
        node830->setUsePos(false);
        node830->setPosX(.00f);
        node830->setPosY(.00f);
        node830->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10233, 830, node830)
    }
    if (noInit == true) {
        return node830;
    }
    return node830;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10233, 832) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_PlaySound::TRIGGER_DONE, 816, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(10233, 832) {
    auto node832 = GET_SKILL_NODE(832, PhaseNode_PlaySound);
    if (node832 == nullptr) {
        node832 = new PhaseNode_PlaySound(832, phase);
        node832->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node832->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node832->setSoundID("SE_Hero106_SkillC_P2");
        node832->setTarget(0U);
        node832->setUsePos(false);
        node832->setPosX(.00f);
        node832->setPosY(.00f);
        node832->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10233, 832, node832)
    }
    if (noInit == true) {
        return node832;
    }
    return node832;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(10233, 838) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_If::TRIGGER_FALSE, 746, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
    pnode->regTrigger<PhaseNode_Disable>(PhaseNode_If::TRIGGER_TRUE, 738, PhaseNode_Disable::FUNC_DO, &PhaseNode_Disable::Do);
}

REGISTER_CREATE_SKILL_NODE(10233, 838) {
    auto node838 = GET_SKILL_NODE(838, PhaseNode_If);
    if (node838 == nullptr) {
        node838 = new PhaseNode_If(838, phase);
        CALL_REGISTER_SKILL_NODE(10233, 838, node838)
    }
    if (noInit == true) {
        return node838;
    }
    auto variables = node838->getVariables();
    if (variables != nullptr) {
        node838->setCondition(variables->getVariable<bool>(Variable_10233_anxia));
    }
    return node838;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10233, 844) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_Delay::TRIGGER_DONE, 846, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(10233, 844) {
    auto node844 = GET_SKILL_NODE(844, PhaseNode_Delay);
    if (node844 == nullptr) {
        node844 = new PhaseNode_Delay(844, phase);
        node844->setTime(4.57f);
        CALL_REGISTER_SKILL_NODE(10233, 844, node844)
    }
    if (noInit == true) {
        return node844;
    }
    return node844;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(10233, 846) {
    pnode->resizeTrigger(PhaseNode_SetBool::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Disable>(PhaseNode_SetBool::TRIGGER_DONE, 850, PhaseNode_Disable::FUNC_DO, &PhaseNode_Disable::Do);
}

REGISTER_CREATE_SKILL_NODE(10233, 846) {
    auto node846 = GET_SKILL_NODE(846, PhaseNode_SetBool);
    if (node846 == nullptr) {
        node846 = new PhaseNode_SetBool(846, phase);
        node846->setName("anxia");
        node846->setValue(false);
        CALL_REGISTER_SKILL_NODE(10233, 846, node846)
    }
    if (noInit == true) {
        return node846;
    }
    return node846;
}
//--------------------------------------------------------------------------------
// AreaCollisionNewPene
//
REGISTER_REGISTER_SKILL_NODE(10233, 848) {
    pnode->resizeTrigger(PhaseNode_AreaCollisionNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_LineCheckNewPene>(PhaseNode_AreaCollisionNewPene::TRIGGER_DONE, 884, PhaseNode_LineCheckNewPene::FUNC_DO, &PhaseNode_LineCheckNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(10233, 848) {
    auto node848 = GET_SKILL_NODE(848, PhaseNode_AreaCollisionNewPene);
    if (node848 == nullptr) {
        node848 = new PhaseNode_AreaCollisionNewPene(848, phase);
        node848->setState(PhaseNode_AreaCollisionNewPene::AreaCollisionNewPene_State::Alive);
        node848->setFaction(PhaseNode_AreaCollisionNewPene::AreaCollisionNewPene_Faction::Enemy);
        node848->setOnHero(true);
        node848->setOnMinion(true);
        node848->setOnDestruct(true);
        node848->setOnShield(true);
        node848->setType(PhaseNode_AreaCollisionNewPene::AreaCollisionNewPene_Type::Circle);
        node848->setTypeParams(0, 5.00f);
        node848->setPositionZ(.00f);
        node848->setRotation(.00f);
        CALL_REGISTER_SKILL_NODE(10233, 848, node848)
    }
    if (noInit == true) {
        return node848;
    }
    auto node828 = GET_SKILL_NODE(828, PhaseNode_GetLocation);
    if (node828 != nullptr) node848->setPositionX(node828->getX());
    if (node828 != nullptr) node848->setPositionY(node828->getY());
    return node848;
}
//--------------------------------------------------------------------------------
// Disable
//
REGISTER_REGISTER_SKILL_NODE(10233, 850) {
    pnode->resizeTrigger(PhaseNode_Disable::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_Disable::TRIGGER_DONE, 880, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(10233, 850) {
    auto node850 = GET_SKILL_NODE(850, PhaseNode_Disable);
    if (node850 == nullptr) {
        node850 = new PhaseNode_Disable(850, phase);
        node850->setTarget(0U);
        node850->setMove(true);
        node850->setSkill(true);
        node850->setShoot(true);
        node850->setTime(1.00f);
        node850->setRotate(true);
        CALL_REGISTER_SKILL_NODE(10233, 850, node850)
    }
    if (noInit == true) {
        return node850;
    }
    return node850;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10233, 852) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RemoveSkillBuff>(PhaseNode_Delay::TRIGGER_DONE, 824, PhaseNode_RemoveSkillBuff::FUNC_REMOVE, &PhaseNode_RemoveSkillBuff::Remove);
}

REGISTER_CREATE_SKILL_NODE(10233, 852) {
    auto node852 = GET_SKILL_NODE(852, PhaseNode_Delay);
    if (node852 == nullptr) {
        node852 = new PhaseNode_Delay(852, phase);
        node852->setTime(.20f);
        CALL_REGISTER_SKILL_NODE(10233, 852, node852)
    }
    if (noInit == true) {
        return node852;
    }
    return node852;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10233, 854) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_Delay::TRIGGER_DONE, 746, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(10233, 854) {
    auto node854 = GET_SKILL_NODE(854, PhaseNode_Delay);
    if (node854 == nullptr) {
        node854 = new PhaseNode_Delay(854, phase);
        node854->setTime(.30f);
        CALL_REGISTER_SKILL_NODE(10233, 854, node854)
    }
    if (noInit == true) {
        return node854;
    }
    return node854;
}
//--------------------------------------------------------------------------------
// AddSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10233, 856) {
    pnode->resizeTrigger(PhaseNode_AddSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_AddSkillBuff::TRIGGER_DONE, 812, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(10233, 856) {
    auto node856 = GET_SKILL_NODE(856, PhaseNode_AddSkillBuff);
    if (node856 == nullptr) {
        node856 = new PhaseNode_AddSkillBuff(856, phase);
        node856->setConfigID(102337);
        node856->setConfigIDs({});
        node856->setTarget(0U);
        node856->setAttribute({{}});
        CALL_REGISTER_SKILL_NODE(10233, 856, node856)
    }
    if (noInit == true) {
        return node856;
    }
    return node856;
}
//--------------------------------------------------------------------------------
// RemoveSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10233, 859) {
    pnode->resizeTrigger(PhaseNode_RemoveSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_RemoveSkillBuff::TRIGGER_DONE, 854, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10233, 859) {
    auto node859 = GET_SKILL_NODE(859, PhaseNode_RemoveSkillBuff);
    if (node859 == nullptr) {
        node859 = new PhaseNode_RemoveSkillBuff(859, phase);
        node859->setBuffID(0U);
        node859->setBuffIDs({});
        node859->setConfigID(102337);
        node859->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(10233, 859, node859)
    }
    if (noInit == true) {
        return node859;
    }
    return node859;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10233, 870) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnCollider>(PhaseNode_Delay::TRIGGER_DONE, 749, PhaseNode_SpawnCollider::FUNC_DO, &PhaseNode_SpawnCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(10233, 870) {
    auto node870 = GET_SKILL_NODE(870, PhaseNode_Delay);
    if (node870 == nullptr) {
        node870 = new PhaseNode_Delay(870, phase);
        node870->setTime(.50f);
        CALL_REGISTER_SKILL_NODE(10233, 870, node870)
    }
    if (noInit == true) {
        return node870;
    }
    return node870;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(10233, 872) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlayEffect::TRIGGER_DONE, 870, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10233, 872) {
    auto node872 = GET_SKILL_NODE(872, PhaseNode_PlayEffect);
    if (node872 == nullptr) {
        node872 = new PhaseNode_PlayEffect(872, phase);
        node872->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node872->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node872->setEffectID(102334);
        node872->setChangeColor(false);
        node872->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node872->getVars().reserve(3);
        node872->getVars().setVariable<float>(0, .00f);
        node872->getVars().setVariable<float>(1, .00f);
        node872->getVars().setVariable<float>(2, 1.50f);
        node872->setRotation(.00f);
        node872->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(10233, 872, node872)
    }
    if (noInit == true) {
        return node872;
    }
    auto node780 = GET_SKILL_NODE(780, PhaseNode_GetInputLocation);
    if (node780 != nullptr) node872->getVars().setVariable<float>(0, node780->getX());
    if (node780 != nullptr) node872->getVars().setVariable<float>(1, node780->getY());
    return node872;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(10233, 880) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlayEffect::TRIGGER_DONE, 882, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10233, 880) {
    auto node880 = GET_SKILL_NODE(880, PhaseNode_PlayEffect);
    if (node880 == nullptr) {
        node880 = new PhaseNode_PlayEffect(880, phase);
        node880->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node880->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node880->setEffectID(102334);
        node880->setChangeColor(false);
        node880->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node880->getVars().reserve(3);
        node880->getVars().setVariable<float>(0, .00f);
        node880->getVars().setVariable<float>(1, .00f);
        node880->getVars().setVariable<float>(2, 1.50f);
        node880->setRotation(.00f);
        node880->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(10233, 880, node880)
    }
    if (noInit == true) {
        return node880;
    }
    auto node812 = GET_SKILL_NODE(812, PhaseNode_GetLocation);
    if (node812 != nullptr) node880->getVars().setVariable<float>(0, node812->getX());
    if (node812 != nullptr) node880->getVars().setVariable<float>(1, node812->getY());
    return node880;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10233, 882) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_Delay::TRIGGER_DONE, 731, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10233, 882) {
    auto node882 = GET_SKILL_NODE(882, PhaseNode_Delay);
    if (node882 == nullptr) {
        node882 = new PhaseNode_Delay(882, phase);
        node882->setTime(.50f);
        CALL_REGISTER_SKILL_NODE(10233, 882, node882)
    }
    if (noInit == true) {
        return node882;
    }
    return node882;
}
//--------------------------------------------------------------------------------
// LineCheckNewPene
//
REGISTER_REGISTER_SKILL_NODE(10233, 884) {
    pnode->resizeTrigger(PhaseNode_LineCheckNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_LineCheckNewPene::TRIGGER_DONE, 758, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
}

REGISTER_CREATE_SKILL_NODE(10233, 884) {
    auto node884 = GET_SKILL_NODE(884, PhaseNode_LineCheckNewPene);
    if (node884 == nullptr) {
        node884 = new PhaseNode_LineCheckNewPene(884, phase);
        node884->setPeneProjectile(25);
        CALL_REGISTER_SKILL_NODE(10233, 884, node884)
    }
    if (noInit == true) {
        return node884;
    }
    auto node848 = GET_SKILL_NODE(848, PhaseNode_AreaCollisionNewPene);
    auto node828 = GET_SKILL_NODE(828, PhaseNode_GetLocation);
    if (node848 != nullptr) node884->setTargets(node848->getColliders());
    if (node828 != nullptr) node884->setFromX(node828->getX());
    if (node828 != nullptr) node884->setFromY(node828->getY());
    return node884;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(10233, 885) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_ResetCD::TRIGGER_DONE, 886, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10233, 885) {
    auto node885 = GET_SKILL_NODE(885, PhaseNode_ResetCD);
    if (node885 == nullptr) {
        node885 = new PhaseNode_ResetCD(885, phase);
        node885->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node885->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node885->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(10233, 885, node885)
    }
    if (noInit == true) {
        return node885;
    }
    return node885;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10233, 886) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_PlayAnimation::TRIGGER_DONE, 888, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(10233, 886) {
    auto node886 = GET_SKILL_NODE(886, PhaseNode_PlayAnimation);
    if (node886 == nullptr) {
        node886 = new PhaseNode_PlayAnimation(886, phase);
        node886->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node886->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node886->setTarget(0U);
        node886->setAnimation("Skill3S1");
        node886->setParameter("");
        node886->setValue(true);
        CALL_REGISTER_SKILL_NODE(10233, 886, node886)
    }
    if (noInit == true) {
        return node886;
    }
    return node886;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10233, 887) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuff>(PhaseNode_PlaySound::TRIGGER_DONE, 856, PhaseNode_AddSkillBuff::FUNC_ADD, &PhaseNode_AddSkillBuff::Add);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_PlaySound::TRIGGER_DONE, 893, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10233, 887) {
    auto node887 = GET_SKILL_NODE(887, PhaseNode_PlaySound);
    if (node887 == nullptr) {
        node887 = new PhaseNode_PlaySound(887, phase);
        node887->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node887->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node887->setSoundID("VO_Hero123_Skill_C");
        node887->setTarget(0U);
        node887->setUsePos(false);
        node887->setPosX(.00f);
        node887->setPosY(.00f);
        node887->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10233, 887, node887)
    }
    if (noInit == true) {
        return node887;
    }
    return node887;
}
//--------------------------------------------------------------------------------
// GetActorAttribute
//
REGISTER_REGISTER_SKILL_NODE(10233, 888) {
    pnode->resizeTrigger(PhaseNode_GetActorAttribute::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 887, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10233, 888) {
    auto node888 = GET_SKILL_NODE(888, PhaseNode_GetActorAttribute);
    if (node888 == nullptr) {
        node888 = new PhaseNode_GetActorAttribute(888, phase);
        node888->setTarget(0U);
        node888->setType({});
        CALL_REGISTER_SKILL_NODE(10233, 888, node888)
    }
    if (noInit == true) {
        return node888;
    }
    return node888;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10233, 890) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_IsInterruptType>(PhaseNode_Detect::TRIGGER_ON, 896, PhaseNode_IsInterruptType::FUNC_DO, &PhaseNode_IsInterruptType::Do);
}

REGISTER_CREATE_SKILL_NODE(10233, 890) {
    auto node890 = GET_SKILL_NODE(890, PhaseNode_Detect);
    if (node890 == nullptr) {
        node890 = new PhaseNode_Detect(890, phase);
        node890->setSelf(0U);
        node890->setEvent("daduan_001");
        node890->setType(PhaseNode_Detect::Detect_Type::Interrupt_Skill);
        node890->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10233, 890, node890)
    }
    if (noInit == true) {
        return node890;
    }
    return node890;
}
//--------------------------------------------------------------------------------
// SwitchToInt
//
REGISTER_REGISTER_SKILL_NODE(10233, 891) {
}

REGISTER_CREATE_SKILL_NODE(10233, 891) {
    auto node891 = GET_SKILL_NODE(891, PhaseNode_SwitchToInt);
    if (node891 == nullptr) {
        node891 = new PhaseNode_SwitchToInt(891, phase);
        CALL_REGISTER_SKILL_NODE(10233, 891, node891)
    }
    if (noInit == true) {
        return node891;
    }
    auto variables = node891->getVariables();
    if (variables != nullptr) {
        node891->setSelection(variables->getVariable<int32_t>(Variable_10233_a102332));
    }
    return node891;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10233, 893) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_RaiseEvent::TRIGGER_DONE, 902, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10233, 893) {
    auto node893 = GET_SKILL_NODE(893, PhaseNode_RaiseEvent);
    if (node893 == nullptr) {
        node893 = new PhaseNode_RaiseEvent(893, phase);
        node893->setEvent("daduan_001");
        node893->setTarget(0U);
        node893->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node893->setTypeParams(0, 0);
        node893->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10233, 893, node893)
    }
    if (noInit == true) {
        return node893;
    }
    return node893;
}
//--------------------------------------------------------------------------------
// StartPreInput
//
REGISTER_REGISTER_SKILL_NODE(10233, 894) {
    pnode->resizeTrigger(PhaseNode_StartPreInput::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_StartPreInput::TRIGGER_DONE, 898, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_StartPreInput::TRIGGER_DONE, 391, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10233, 894) {
    auto node894 = GET_SKILL_NODE(894, PhaseNode_StartPreInput);
    if (node894 == nullptr) {
        node894 = new PhaseNode_StartPreInput(894, phase);
        node894->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node894->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node894->setDelayTime(.00f);
        CALL_REGISTER_SKILL_NODE(10233, 894, node894)
    }
    if (noInit == true) {
        return node894;
    }
    return node894;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(10233, 895) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_If::TRIGGER_TRUE, 897, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10233, 895) {
    auto node895 = GET_SKILL_NODE(895, PhaseNode_If);
    if (node895 == nullptr) {
        node895 = new PhaseNode_If(895, phase);
        CALL_REGISTER_SKILL_NODE(10233, 895, node895)
    }
    if (noInit == true) {
        return node895;
    }
    auto variables = node895->getVariables();
    if (variables != nullptr) {
        node895->setCondition(variables->getVariable<bool>(Variable_10233_InterruptAnimat));
    }
    return node895;
}
//--------------------------------------------------------------------------------
// IsInterruptType
//
REGISTER_REGISTER_SKILL_NODE(10233, 896) {
    pnode->resizeTrigger(PhaseNode_IsInterruptType::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SwitchToInt>(PhaseNode_IsInterruptType::TRIGGER_BUFF, 891, PhaseNode_SwitchToInt::FUNC_SWITCH, &PhaseNode_SwitchToInt::Switch);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_POSCHANGE, 895, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTAIM, 895, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTFIRE, 895, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTRELOAD, 895, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_USESKILL, 895, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(10233, 896) {
    auto node896 = GET_SKILL_NODE(896, PhaseNode_IsInterruptType);
    if (node896 == nullptr) {
        node896 = new PhaseNode_IsInterruptType(896, phase);
        node896->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node896->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10233, 896, node896)
    }
    if (noInit == true) {
        return node896;
    }
    auto node890 = GET_SKILL_NODE(890, PhaseNode_Detect);
    if (node890 != nullptr) node896->setType(node890->getVars().getVariable<int32_t>(2));
    return node896;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10233, 897) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_PlayAnimation::TRIGGER_DONE, 746, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(10233, 897) {
    auto node897 = GET_SKILL_NODE(897, PhaseNode_PlayAnimation);
    if (node897 == nullptr) {
        node897 = new PhaseNode_PlayAnimation(897, phase);
        node897->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node897->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node897->setTarget(0U);
        node897->setAnimation("Idle");
        node897->setParameter("");
        node897->setValue(false);
        CALL_REGISTER_SKILL_NODE(10233, 897, node897)
    }
    if (noInit == true) {
        return node897;
    }
    return node897;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10233, 898) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_Delay::TRIGGER_DONE, 901, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(10233, 898) {
    auto node898 = GET_SKILL_NODE(898, PhaseNode_Delay);
    if (node898 == nullptr) {
        node898 = new PhaseNode_Delay(898, phase);
        node898->setTime(.20f);
        CALL_REGISTER_SKILL_NODE(10233, 898, node898)
    }
    if (noInit == true) {
        return node898;
    }
    return node898;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(10233, 901) {
}

REGISTER_CREATE_SKILL_NODE(10233, 901) {
    auto node901 = GET_SKILL_NODE(901, PhaseNode_SetBool);
    if (node901 == nullptr) {
        node901 = new PhaseNode_SetBool(901, phase);
        node901->setName("InterruptAnimat");
        node901->setValue(true);
        CALL_REGISTER_SKILL_NODE(10233, 901, node901)
    }
    if (noInit == true) {
        return node901;
    }
    return node901;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10233, 902) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StartPreInput>(PhaseNode_RaiseEvent::TRIGGER_DONE, 894, PhaseNode_StartPreInput::FUNC_DO, &PhaseNode_StartPreInput::Do);
}

REGISTER_CREATE_SKILL_NODE(10233, 902) {
    auto node902 = GET_SKILL_NODE(902, PhaseNode_RaiseEvent);
    if (node902 == nullptr) {
        node902 = new PhaseNode_RaiseEvent(902, phase);
        node902->setEvent("Dead_001");
        node902->setTarget(0U);
        node902->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node902->setTypeParams(0, 0);
        node902->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10233, 902, node902)
    }
    if (noInit == true) {
        return node902;
    }
    return node902;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10233, 903) {
}

REGISTER_CREATE_SKILL_NODE(10233, 903) {
    auto node903 = GET_SKILL_NODE(903, PhaseNode_Detect);
    if (node903 == nullptr) {
        node903 = new PhaseNode_Detect(903, phase);
        node903->setSelf(0U);
        node903->setEvent("Dead_001");
        node903->setType(PhaseNode_Detect::Detect_Type::Actor_Dead);
        node903->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10233, 903, node903)
    }
    if (noInit == true) {
        return node903;
    }
    return node903;
}

//--------------------------------------------------------------------------------
// SkillCreator_10233
//
class SkillCreator_10233 : public SkillCreator {
public:
    SkillCreator_10233() {}
    virtual ~SkillCreator_10233() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_10233

//--------------------------------------------------------------------------------
// SkillPhase_10233
//
class SkillPhase_10233 : public SkillPhase {
public:
    SkillPhase_10233(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_10233() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(10233, 1) // StartPhase
        CASE_CREATE_SKILL_NODE(10233, 391) // PlaySound
        CASE_CREATE_SKILL_NODE(10233, 719) // ConfirmPhase
        CASE_CREATE_SKILL_NODE(10233, 731) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10233, 735) // AddSkillBuff
        CASE_CREATE_SKILL_NODE(10233, 738) // Disable
        CASE_CREATE_SKILL_NODE(10233, 746) // EndPhase
        CASE_CREATE_SKILL_NODE(10233, 749) // SpawnCollider
        CASE_CREATE_SKILL_NODE(10233, 753) // GetLocation
        CASE_CREATE_SKILL_NODE(10233, 758) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(10233, 767) // EndFlow
        CASE_CREATE_SKILL_NODE(10233, 769) // Disable
        CASE_CREATE_SKILL_NODE(10233, 773) // Delay
        CASE_CREATE_SKILL_NODE(10233, 777) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10233, 780) // GetInputLocation
        CASE_CREATE_SKILL_NODE(10233, 785) // MoveNewPene
        CASE_CREATE_SKILL_NODE(10233, 787) // AttachTo
        CASE_CREATE_SKILL_NODE(10233, 809) // PlayEffect
        CASE_CREATE_SKILL_NODE(10233, 812) // GetLocation
        CASE_CREATE_SKILL_NODE(10233, 814) // PlayEffect
        CASE_CREATE_SKILL_NODE(10233, 816) // PlayEffect
        CASE_CREATE_SKILL_NODE(10233, 820) // ResetSkill
        CASE_CREATE_SKILL_NODE(10233, 824) // RemoveSkillBuff
        CASE_CREATE_SKILL_NODE(10233, 826) // RemoveSkillBuff
        CASE_CREATE_SKILL_NODE(10233, 828) // GetLocation
        CASE_CREATE_SKILL_NODE(10233, 830) // PlaySound
        CASE_CREATE_SKILL_NODE(10233, 832) // PlaySound
        CASE_CREATE_SKILL_NODE(10233, 838) // If
        CASE_CREATE_SKILL_NODE(10233, 844) // Delay
        CASE_CREATE_SKILL_NODE(10233, 846) // SetBool
        CASE_CREATE_SKILL_NODE(10233, 848) // AreaCollisionNewPene
        CASE_CREATE_SKILL_NODE(10233, 850) // Disable
        CASE_CREATE_SKILL_NODE(10233, 852) // Delay
        CASE_CREATE_SKILL_NODE(10233, 854) // Delay
        CASE_CREATE_SKILL_NODE(10233, 856) // AddSkillBuff
        CASE_CREATE_SKILL_NODE(10233, 859) // RemoveSkillBuff
        CASE_CREATE_SKILL_NODE(10233, 870) // Delay
        CASE_CREATE_SKILL_NODE(10233, 872) // PlayEffect
        CASE_CREATE_SKILL_NODE(10233, 880) // PlayEffect
        CASE_CREATE_SKILL_NODE(10233, 882) // Delay
        CASE_CREATE_SKILL_NODE(10233, 884) // LineCheckNewPene
        CASE_CREATE_SKILL_NODE(10233, 885) // ResetCD
        CASE_CREATE_SKILL_NODE(10233, 886) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10233, 887) // PlaySound
        CASE_CREATE_SKILL_NODE(10233, 888) // GetActorAttribute
        CASE_CREATE_SKILL_NODE(10233, 890) // Detect
        CASE_CREATE_SKILL_NODE(10233, 891) // SwitchToInt
        CASE_CREATE_SKILL_NODE(10233, 893) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10233, 894) // StartPreInput
        CASE_CREATE_SKILL_NODE(10233, 895) // If
        CASE_CREATE_SKILL_NODE(10233, 896) // IsInterruptType
        CASE_CREATE_SKILL_NODE(10233, 897) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10233, 898) // Delay
        CASE_CREATE_SKILL_NODE(10233, 901) // SetBool
        CASE_CREATE_SKILL_NODE(10233, 902) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10233, 903) // Detect
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_10233

SkillLogic* SkillCreator_10233::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //设置变量
    Variable_10233_anxia = logic->getVariables().setVariable<bool>("anxia", true);
    Variable_10233_a102332 = logic->getVariables().setVariable<int32_t>("a102332", 1);
    Variable_10233_InterruptAnimat = logic->getVariables().setVariable<bool>("InterruptAnimat");
    //创建阶段phase
    auto phase = new SkillPhase_10233(1, logic, 3);
    //设置phase执行器
    phase->setRunPhaseNode(1, 1);
    phase->addConfirmPhaseNode(2, 719);
    phase->setDetectPhaseNode(3, 890);
    phase->setDetectPhaseNode(3, 903);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_10233::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
