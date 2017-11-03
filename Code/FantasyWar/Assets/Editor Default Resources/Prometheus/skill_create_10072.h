#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

#include "skill_psnode_addskillbuffs.h"
#include "skill_psnode_areacollisionnewpene.h"
#include "skill_psnode_cameraoffset.h"
#include "skill_psnode_cameraxyzshake.h"
#include "skill_psnode_cancelphase.h"
#include "skill_psnode_compareint.h"
#include "skill_psnode_confirmphase.h"
#include "skill_psnode_delay.h"
#include "skill_psnode_detect.h"
#include "skill_psnode_disable.h"
#include "skill_psnode_endphase.h"
#include "skill_psnode_findskillbuff.h"
#include "skill_psnode_getactorattribute.h"
#include "skill_psnode_getinputrotation.h"
#include "skill_psnode_getlocation.h"
#include "skill_psnode_if.h"
#include "skill_psnode_int2float.h"
#include "skill_psnode_intoperation.h"
#include "skill_psnode_isinterrupttype.h"
#include "skill_psnode_offsetcalculate.h"
#include "skill_psnode_playanimation.h"
#include "skill_psnode_playeffect.h"
#include "skill_psnode_playsound.h"
#include "skill_psnode_playuieffect.h"
#include "skill_psnode_raiseevent.h"
#include "skill_psnode_resetcd.h"
#include "skill_psnode_revisemapi32.h"
#include "skill_psnode_setbool.h"
#include "skill_psnode_setint.h"
#include "skill_psnode_startphase.h"
#include "skill_psnode_startpreinput.h"
#include "skill_psnode_stopeffect.h"
#include "skill_psnode_switchtoint.h"
#include "skill_psnode_timedown.h"

namespace pvp {

//变量声明
uint64_t Variable_10072_miaozhunNum = 0;
uint64_t Variable_10072_a100722 = 0;
uint64_t Variable_10072_InterruptAnimat = 0;
//--------------------------------------------------------------------------------
// StartPhase
//
REGISTER_REGISTER_SKILL_NODE(10072, 1) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayUIEffect>(PhaseNode_StartPhase::TRIGGER_START, 287, PhaseNode_PlayUIEffect::FUNC_DO, &PhaseNode_PlayUIEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(10072, 1) {
    auto node1 = GET_SKILL_NODE(1, PhaseNode_StartPhase);
    if (node1 == nullptr) {
        node1 = new PhaseNode_StartPhase(1, phase);
        CALL_REGISTER_SKILL_NODE(10072, 1, node1)
    }
    if (noInit == true) {
        return node1;
    }
    return node1;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10072, 23) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CameraOffset>(PhaseNode_Delay::TRIGGER_DONE, 231, PhaseNode_CameraOffset::FUNC_DO, &PhaseNode_CameraOffset::Do);
}

REGISTER_CREATE_SKILL_NODE(10072, 23) {
    auto node23 = GET_SKILL_NODE(23, PhaseNode_Delay);
    if (node23 == nullptr) {
        node23 = new PhaseNode_Delay(23, phase);
        node23->setTime(.76f);
        CALL_REGISTER_SKILL_NODE(10072, 23, node23)
    }
    if (noInit == true) {
        return node23;
    }
    return node23;
}
//--------------------------------------------------------------------------------
// Disable
//
REGISTER_REGISTER_SKILL_NODE(10072, 49) {
    pnode->resizeTrigger(PhaseNode_Disable::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_Disable::TRIGGER_DONE, 114, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(10072, 49) {
    auto node49 = GET_SKILL_NODE(49, PhaseNode_Disable);
    if (node49 == nullptr) {
        node49 = new PhaseNode_Disable(49, phase);
        node49->setTarget(0U);
        node49->setMove(true);
        node49->setSkill(true);
        node49->setShoot(true);
        node49->setTime(.75f);
        node49->setRotate(true);
        CALL_REGISTER_SKILL_NODE(10072, 49, node49)
    }
    if (noInit == true) {
        return node49;
    }
    return node49;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10072, 71) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Disable>(PhaseNode_PlaySound::TRIGGER_DONE, 49, PhaseNode_Disable::FUNC_DO, &PhaseNode_Disable::Do);
}

REGISTER_CREATE_SKILL_NODE(10072, 71) {
    auto node71 = GET_SKILL_NODE(71, PhaseNode_PlaySound);
    if (node71 == nullptr) {
        node71 = new PhaseNode_PlaySound(71, phase);
        node71->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node71->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node71->setSoundID("SE_Hero104_SkillC_P1");
        node71->setTarget(0U);
        node71->setUsePos(false);
        node71->setPosX(.00f);
        node71->setPosY(.00f);
        node71->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10072, 71, node71)
    }
    if (noInit == true) {
        return node71;
    }
    return node71;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(10072, 76) {
}

REGISTER_CREATE_SKILL_NODE(10072, 76) {
    auto node76 = GET_SKILL_NODE(76, PhaseNode_AddSkillBuffs);
    if (node76 == nullptr) {
        node76 = new PhaseNode_AddSkillBuffs(76, phase);
        node76->setConfigID({100721});
        CALL_REGISTER_SKILL_NODE(10072, 76, node76)
    }
    if (noInit == true) {
        return node76;
    }
    auto node233 = GET_SKILL_NODE(233, PhaseNode_AreaCollisionNewPene);
    auto node241 = GET_SKILL_NODE(241, PhaseNode_ReviseMapI32);
    if (node233 != nullptr) node76->setTarget(node233->getColliders());
    if (node241 != nullptr) node76->setAttribute(node241->getOutAttri());
    return node76;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(10072, 96) {
}

REGISTER_CREATE_SKILL_NODE(10072, 96) {
    auto node96 = GET_SKILL_NODE(96, PhaseNode_EndPhase);
    if (node96 == nullptr) {
        node96 = new PhaseNode_EndPhase(96, phase);
        node96->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node96->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10072, 96, node96)
    }
    if (noInit == true) {
        return node96;
    }
    return node96;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(10072, 100) {
}

REGISTER_CREATE_SKILL_NODE(10072, 100) {
    auto node100 = GET_SKILL_NODE(100, PhaseNode_PlayEffect);
    if (node100 == nullptr) {
        node100 = new PhaseNode_PlayEffect(100, phase);
        node100->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node100->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node100->setEffectID(100722);
        node100->setChangeColor(true);
        node100->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node100->getVars().reserve(3);
        node100->getVars().setVariable<float>(0, .00f);
        node100->getVars().setVariable<float>(1, .00f);
        node100->getVars().setVariable<float>(2, .00f);
        node100->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(10072, 100, node100)
    }
    if (noInit == true) {
        return node100;
    }
    auto node103 = GET_SKILL_NODE(103, PhaseNode_OffsetCalculate);
    if (node103 != nullptr) node100->getVars().setVariable<float>(0, node103->getOutPosX());
    if (node103 != nullptr) node100->getVars().setVariable<float>(1, node103->getOutPosY());
    if (node103 != nullptr) node100->getVars().setVariable<float>(2, node103->getOutPosZ());
    if (node103 != nullptr) node100->setRotation(node103->getOutRotation());
    return node100;
}
//--------------------------------------------------------------------------------
// OffsetCalculate
//
REGISTER_REGISTER_SKILL_NODE(10072, 103) {
    pnode->resizeTrigger(PhaseNode_OffsetCalculate::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 100, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 109, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(10072, 103) {
    auto node103 = GET_SKILL_NODE(103, PhaseNode_OffsetCalculate);
    if (node103 == nullptr) {
        node103 = new PhaseNode_OffsetCalculate(103, phase);
        node103->setPosZ(.00f);
        node103->setOffsetX(.00f);
        node103->setOffsetY(1.60f);
        node103->setOffsetZ(2.20f);
        node103->setRotOffset(.00f);
        CALL_REGISTER_SKILL_NODE(10072, 103, node103)
    }
    if (noInit == true) {
        return node103;
    }
    auto node197 = GET_SKILL_NODE(197, PhaseNode_GetLocation);
    auto node179 = GET_SKILL_NODE(179, PhaseNode_GetInputRotation);
    if (node197 != nullptr) node103->setPosX(node197->getX());
    if (node197 != nullptr) node103->setPosY(node197->getY());
    if (node179 != nullptr) node103->setRotation(node179->getAngle());
    return node103;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(10072, 109) {
}

REGISTER_CREATE_SKILL_NODE(10072, 109) {
    auto node109 = GET_SKILL_NODE(109, PhaseNode_PlayEffect);
    if (node109 == nullptr) {
        node109 = new PhaseNode_PlayEffect(109, phase);
        node109->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node109->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node109->setEffectID(100721);
        node109->setChangeColor(true);
        node109->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node109->getVars().reserve(3);
        node109->getVars().setVariable<float>(0, .00f);
        node109->getVars().setVariable<float>(1, .00f);
        node109->getVars().setVariable<float>(2, .00f);
        node109->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(10072, 109, node109)
    }
    if (noInit == true) {
        return node109;
    }
    auto node103 = GET_SKILL_NODE(103, PhaseNode_OffsetCalculate);
    if (node103 != nullptr) node109->getVars().setVariable<float>(0, node103->getOutPosX());
    if (node103 != nullptr) node109->getVars().setVariable<float>(1, node103->getOutPosY());
    if (node103 != nullptr) node109->getVars().setVariable<float>(2, node103->getOutPosZ());
    if (node103 != nullptr) node109->setRotation(node103->getOutRotation());
    return node109;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10072, 110) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CameraXYZShake>(PhaseNode_PlaySound::TRIGGER_DONE, 118, PhaseNode_CameraXYZShake::FUNC_DO, &PhaseNode_CameraXYZShake::Do);
}

REGISTER_CREATE_SKILL_NODE(10072, 110) {
    auto node110 = GET_SKILL_NODE(110, PhaseNode_PlaySound);
    if (node110 == nullptr) {
        node110 = new PhaseNode_PlaySound(110, phase);
        node110->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node110->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node110->setSoundID("SE_Hero104_SkillC_P2");
        node110->setTarget(0U);
        node110->setUsePos(false);
        node110->setPosX(.00f);
        node110->setPosY(.00f);
        node110->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10072, 110, node110)
    }
    if (noInit == true) {
        return node110;
    }
    return node110;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10072, 112) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AreaCollisionNewPene>(PhaseNode_Delay::TRIGGER_DONE, 233, PhaseNode_AreaCollisionNewPene::FUNC_DO, &PhaseNode_AreaCollisionNewPene::Do);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_Delay::TRIGGER_DONE, 110, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10072, 112) {
    auto node112 = GET_SKILL_NODE(112, PhaseNode_Delay);
    if (node112 == nullptr) {
        node112 = new PhaseNode_Delay(112, phase);
        node112->setTime(.10f);
        CALL_REGISTER_SKILL_NODE(10072, 112, node112)
    }
    if (noInit == true) {
        return node112;
    }
    return node112;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(10072, 114) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlayEffect::TRIGGER_DONE, 112, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_OffsetCalculate>(PhaseNode_PlayEffect::TRIGGER_DONE, 103, PhaseNode_OffsetCalculate::FUNC_DO, &PhaseNode_OffsetCalculate::Do);
}

REGISTER_CREATE_SKILL_NODE(10072, 114) {
    auto node114 = GET_SKILL_NODE(114, PhaseNode_PlayEffect);
    if (node114 == nullptr) {
        node114 = new PhaseNode_PlayEffect(114, phase);
        node114->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node114->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node114->setEffectID(100703);
        node114->setChangeColor(true);
        node114->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node114->getVars().reserve(3);
        node114->getVars().setVariable<float>(0, .00f);
        node114->getVars().setVariable<float>(1, .00f);
        node114->getVars().setVariable<float>(2, .00f);
        node114->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(10072, 114, node114)
    }
    if (noInit == true) {
        return node114;
    }
    auto node197 = GET_SKILL_NODE(197, PhaseNode_GetLocation);
    auto node179 = GET_SKILL_NODE(179, PhaseNode_GetInputRotation);
    if (node197 != nullptr) node114->getVars().setVariable<float>(0, node197->getX());
    if (node197 != nullptr) node114->getVars().setVariable<float>(1, node197->getY());
    if (node179 != nullptr) node114->setRotation(node179->getAngle());
    return node114;
}
//--------------------------------------------------------------------------------
// CameraXYZShake
//
REGISTER_REGISTER_SKILL_NODE(10072, 118) {
    pnode->resizeTrigger(PhaseNode_CameraXYZShake::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CameraXYZShake::TRIGGER_DONE, 23, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10072, 118) {
    auto node118 = GET_SKILL_NODE(118, PhaseNode_CameraXYZShake);
    if (node118 == nullptr) {
        node118 = new PhaseNode_CameraXYZShake(118, phase);
        node118->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node118->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node118->setShakeStyle(0);
        node118->setTarget(0U);
        node118->setX(.20f);
        node118->setY(.20f);
        node118->setZ(.20f);
        node118->setDuration(.15f);
        node118->setTimes(3);
        CALL_REGISTER_SKILL_NODE(10072, 118, node118)
    }
    if (noInit == true) {
        return node118;
    }
    return node118;
}
//--------------------------------------------------------------------------------
// Disable
//
REGISTER_REGISTER_SKILL_NODE(10072, 140) {
    pnode->resizeTrigger(PhaseNode_Disable::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_Disable::TRIGGER_CANCEL, 208, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_Disable::TRIGGER_DONE, 292, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10072, 140) {
    auto node140 = GET_SKILL_NODE(140, PhaseNode_Disable);
    if (node140 == nullptr) {
        node140 = new PhaseNode_Disable(140, phase);
        node140->setTarget(0U);
        node140->setMove(true);
        node140->setSkill(true);
        node140->setShoot(true);
        node140->setTime(.00f);
        node140->setRotate(false);
        CALL_REGISTER_SKILL_NODE(10072, 140, node140)
    }
    if (noInit == true) {
        return node140;
    }
    return node140;
}
//--------------------------------------------------------------------------------
// ConfirmPhase
//
REGISTER_REGISTER_SKILL_NODE(10072, 170) {
    pnode->resizeTrigger(PhaseNode_ConfirmPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Disable>(PhaseNode_ConfirmPhase::TRIGGER_CONFIRM, 140, PhaseNode_Disable::FUNC_CANCLE, &PhaseNode_Disable::Cancle);
    pnode->regTrigger<PhaseNode_TimeDown>(PhaseNode_ConfirmPhase::TRIGGER_CONFIRM, 255, PhaseNode_TimeDown::FUNC_CANCEL, &PhaseNode_TimeDown::Cancel);
}

REGISTER_CREATE_SKILL_NODE(10072, 170) {
    auto node170 = GET_SKILL_NODE(170, PhaseNode_ConfirmPhase);
    if (node170 == nullptr) {
        node170 = new PhaseNode_ConfirmPhase(170, phase);
        CALL_REGISTER_SKILL_NODE(10072, 170, node170)
    }
    if (noInit == true) {
        return node170;
    }
    return node170;
}
//--------------------------------------------------------------------------------
// GetInputRotation
//
REGISTER_REGISTER_SKILL_NODE(10072, 179) {
    pnode->resizeTrigger(PhaseNode_GetInputRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_GetInputRotation::TRIGGER_DONE, 197, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(10072, 179) {
    auto node179 = GET_SKILL_NODE(179, PhaseNode_GetInputRotation);
    if (node179 == nullptr) {
        node179 = new PhaseNode_GetInputRotation(179, phase);
        node179->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        CALL_REGISTER_SKILL_NODE(10072, 179, node179)
    }
    if (noInit == true) {
        return node179;
    }
    return node179;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10072, 181) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_PlayAnimation::TRIGGER_DONE, 71, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10072, 181) {
    auto node181 = GET_SKILL_NODE(181, PhaseNode_PlayAnimation);
    if (node181 == nullptr) {
        node181 = new PhaseNode_PlayAnimation(181, phase);
        node181->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node181->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node181->setTarget(0U);
        node181->setAnimation("Skill2S2");
        node181->setParameter("SkillArmBusy");
        node181->setValue(false);
        CALL_REGISTER_SKILL_NODE(10072, 181, node181)
    }
    if (noInit == true) {
        return node181;
    }
    return node181;
}
//--------------------------------------------------------------------------------
// CameraOffset
//
REGISTER_REGISTER_SKILL_NODE(10072, 185) {
}

REGISTER_CREATE_SKILL_NODE(10072, 185) {
    auto node185 = GET_SKILL_NODE(185, PhaseNode_CameraOffset);
    if (node185 == nullptr) {
        node185 = new PhaseNode_CameraOffset(185, phase);
        node185->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node185->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node185->setOffsetX(.00f);
        node185->setOffsetY(-8.00f);
        node185->setOffsetZ(12.00f);
        node185->setSpeed(4.00f);
        CALL_REGISTER_SKILL_NODE(10072, 185, node185)
    }
    if (noInit == true) {
        return node185;
    }
    return node185;
}
//--------------------------------------------------------------------------------
// FindSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10072, 189) {
    pnode->resizeTrigger(PhaseNode_FindSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_FindSkillBuff::TRIGGER_DONE, 191, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(10072, 189) {
    auto node189 = GET_SKILL_NODE(189, PhaseNode_FindSkillBuff);
    if (node189 == nullptr) {
        node189 = new PhaseNode_FindSkillBuff(189, phase);
        node189->setSelfTarget(0U);
        node189->setDetectTarget(0U);
        node189->setConfigID(100731);
        CALL_REGISTER_SKILL_NODE(10072, 189, node189)
    }
    if (noInit == true) {
        return node189;
    }
    return node189;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(10072, 191) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CameraOffset>(PhaseNode_If::TRIGGER_FALSE, 185, PhaseNode_CameraOffset::FUNC_DO, &PhaseNode_CameraOffset::Do);
}

REGISTER_CREATE_SKILL_NODE(10072, 191) {
    auto node191 = GET_SKILL_NODE(191, PhaseNode_If);
    if (node191 == nullptr) {
        node191 = new PhaseNode_If(191, phase);
        CALL_REGISTER_SKILL_NODE(10072, 191, node191)
    }
    if (noInit == true) {
        return node191;
    }
    auto node189 = GET_SKILL_NODE(189, PhaseNode_FindSkillBuff);
    if (node189 != nullptr) node191->setCondition(node189->getResult());
    return node191;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(10072, 197) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_GetLocation::TRIGGER_DONE, 181, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10072, 197) {
    auto node197 = GET_SKILL_NODE(197, PhaseNode_GetLocation);
    if (node197 == nullptr) {
        node197 = new PhaseNode_GetLocation(197, phase);
        node197->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node197->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(10072, 197, node197)
    }
    if (noInit == true) {
        return node197;
    }
    return node197;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10072, 199) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlayAnimation::TRIGGER_DONE, 220, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_PlayAnimation::TRIGGER_DONE, 203, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(10072, 199) {
    auto node199 = GET_SKILL_NODE(199, PhaseNode_PlayAnimation);
    if (node199 == nullptr) {
        node199 = new PhaseNode_PlayAnimation(199, phase);
        node199->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node199->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node199->setTarget(0U);
        node199->setAnimation("Skill2S1");
        node199->setParameter("SkillArmBusy");
        node199->setValue(true);
        CALL_REGISTER_SKILL_NODE(10072, 199, node199)
    }
    if (noInit == true) {
        return node199;
    }
    return node199;
}
//--------------------------------------------------------------------------------
// GetActorAttribute
//
REGISTER_REGISTER_SKILL_NODE(10072, 203) {
    pnode->resizeTrigger(PhaseNode_GetActorAttribute::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 205, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10072, 203) {
    auto node203 = GET_SKILL_NODE(203, PhaseNode_GetActorAttribute);
    if (node203 == nullptr) {
        node203 = new PhaseNode_GetActorAttribute(203, phase);
        node203->setTarget(0U);
        node203->setType({});
        CALL_REGISTER_SKILL_NODE(10072, 203, node203)
    }
    if (noInit == true) {
        return node203;
    }
    return node203;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10072, 205) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlaySound::TRIGGER_DONE, 235, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_TimeDown>(PhaseNode_PlaySound::TRIGGER_DONE, 255, PhaseNode_TimeDown::FUNC_DO, &PhaseNode_TimeDown::Do);
}

REGISTER_CREATE_SKILL_NODE(10072, 205) {
    auto node205 = GET_SKILL_NODE(205, PhaseNode_PlaySound);
    if (node205 == nullptr) {
        node205 = new PhaseNode_PlaySound(205, phase);
        node205->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node205->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node205->setSoundID("VO_Hero104_Skill_C");
        node205->setTarget(0U);
        node205->setUsePos(false);
        node205->setPosX(.00f);
        node205->setPosY(.00f);
        node205->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10072, 205, node205)
    }
    if (noInit == true) {
        return node205;
    }
    return node205;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(10072, 208) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StopEffect>(PhaseNode_ResetCD::TRIGGER_DONE, 280, PhaseNode_StopEffect::FUNC_DO, &PhaseNode_StopEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(10072, 208) {
    auto node208 = GET_SKILL_NODE(208, PhaseNode_ResetCD);
    if (node208 == nullptr) {
        node208 = new PhaseNode_ResetCD(208, phase);
        node208->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node208->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node208->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(10072, 208, node208)
    }
    if (noInit == true) {
        return node208;
    }
    return node208;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(10072, 215) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CameraOffset>(PhaseNode_ResetCD::TRIGGER_DONE, 231, PhaseNode_CameraOffset::FUNC_DO, &PhaseNode_CameraOffset::Do);
}

REGISTER_CREATE_SKILL_NODE(10072, 215) {
    auto node215 = GET_SKILL_NODE(215, PhaseNode_ResetCD);
    if (node215 == nullptr) {
        node215 = new PhaseNode_ResetCD(215, phase);
        node215->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node215->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node215->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(10072, 215, node215)
    }
    if (noInit == true) {
        return node215;
    }
    return node215;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10072, 220) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_Delay::TRIGGER_DONE, 222, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10072, 220) {
    auto node220 = GET_SKILL_NODE(220, PhaseNode_Delay);
    if (node220 == nullptr) {
        node220 = new PhaseNode_Delay(220, phase);
        node220->setTime(.30f);
        CALL_REGISTER_SKILL_NODE(10072, 220, node220)
    }
    if (noInit == true) {
        return node220;
    }
    return node220;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10072, 222) {
}

REGISTER_CREATE_SKILL_NODE(10072, 222) {
    auto node222 = GET_SKILL_NODE(222, PhaseNode_PlayAnimation);
    if (node222 == nullptr) {
        node222 = new PhaseNode_PlayAnimation(222, phase);
        node222->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node222->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node222->setTarget(0U);
        node222->setAnimation("Skill2S3");
        node222->setParameter("SkillArmBusy");
        node222->setValue(true);
        CALL_REGISTER_SKILL_NODE(10072, 222, node222)
    }
    if (noInit == true) {
        return node222;
    }
    return node222;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(10072, 225) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StopEffect>(PhaseNode_PlayEffect::TRIGGER_DONE, 284, PhaseNode_StopEffect::FUNC_DO, &PhaseNode_StopEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(10072, 225) {
    auto node225 = GET_SKILL_NODE(225, PhaseNode_PlayEffect);
    if (node225 == nullptr) {
        node225 = new PhaseNode_PlayEffect(225, phase);
        node225->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node225->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node225->setEffectID(1063);
        node225->setChangeColor(false);
        node225->setType(PhaseNode_PlayEffect::PlayEffect_Type::WithTarget);
        node225->getVars().reserve(6);
        node225->getVars().setVariable<uint64_t>(0, 0U);
        node225->getVars().setVariable<std::string>(1, "Effect");
        node225->getVars().setVariable<float>(2, .00f);
        node225->getVars().setVariable<float>(3, .00f);
        node225->getVars().setVariable<float>(4, .00f);
        node225->getVars().setVariable<bool>(5, false);
        node225->setRotation(.00f);
        node225->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(10072, 225, node225)
    }
    if (noInit == true) {
        return node225;
    }
    return node225;
}
//--------------------------------------------------------------------------------
// StopEffect
//
REGISTER_REGISTER_SKILL_NODE(10072, 227) {
    pnode->resizeTrigger(PhaseNode_StopEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetInputRotation>(PhaseNode_StopEffect::TRIGGER_DONE, 179, PhaseNode_GetInputRotation::FUNC_DO, &PhaseNode_GetInputRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(10072, 227) {
    auto node227 = GET_SKILL_NODE(227, PhaseNode_StopEffect);
    if (node227 == nullptr) {
        node227 = new PhaseNode_StopEffect(227, phase);
        node227->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node227->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node227->setEffectID(1063);
        CALL_REGISTER_SKILL_NODE(10072, 227, node227)
    }
    if (noInit == true) {
        return node227;
    }
    return node227;
}
//--------------------------------------------------------------------------------
// CancelPhase
//
REGISTER_REGISTER_SKILL_NODE(10072, 229) {
    pnode->resizeTrigger(PhaseNode_CancelPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CameraOffset>(PhaseNode_CancelPhase::TRIGGER_CANCEL, 231, PhaseNode_CameraOffset::FUNC_DO, &PhaseNode_CameraOffset::Do);
}

REGISTER_CREATE_SKILL_NODE(10072, 229) {
    auto node229 = GET_SKILL_NODE(229, PhaseNode_CancelPhase);
    if (node229 == nullptr) {
        node229 = new PhaseNode_CancelPhase(229, phase);
        CALL_REGISTER_SKILL_NODE(10072, 229, node229)
    }
    if (noInit == true) {
        return node229;
    }
    return node229;
}
//--------------------------------------------------------------------------------
// CameraOffset
//
REGISTER_REGISTER_SKILL_NODE(10072, 231) {
    pnode->resizeTrigger(PhaseNode_CameraOffset::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_CameraOffset::TRIGGER_DONE, 96, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(10072, 231) {
    auto node231 = GET_SKILL_NODE(231, PhaseNode_CameraOffset);
    if (node231 == nullptr) {
        node231 = new PhaseNode_CameraOffset(231, phase);
        node231->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node231->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node231->setOffsetX(.00f);
        node231->setOffsetY(.00f);
        node231->setOffsetZ(.00f);
        node231->setSpeed(2.00f);
        CALL_REGISTER_SKILL_NODE(10072, 231, node231)
    }
    if (noInit == true) {
        return node231;
    }
    return node231;
}
//--------------------------------------------------------------------------------
// AreaCollisionNewPene
//
REGISTER_REGISTER_SKILL_NODE(10072, 233) {
    pnode->resizeTrigger(PhaseNode_AreaCollisionNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Int2Float>(PhaseNode_AreaCollisionNewPene::TRIGGER_DONE, 269, PhaseNode_Int2Float::FUNC_DO, &PhaseNode_Int2Float::Do);
}

REGISTER_CREATE_SKILL_NODE(10072, 233) {
    auto node233 = GET_SKILL_NODE(233, PhaseNode_AreaCollisionNewPene);
    if (node233 == nullptr) {
        node233 = new PhaseNode_AreaCollisionNewPene(233, phase);
        node233->setState(PhaseNode_AreaCollisionNewPene::AreaCollisionNewPene_State::Alive);
        node233->setFaction(PhaseNode_AreaCollisionNewPene::AreaCollisionNewPene_Faction::Enemy);
        node233->setOnHero(true);
        node233->setOnMinion(true);
        node233->setOnDestruct(true);
        node233->setOnShield(true);
        node233->setType(PhaseNode_AreaCollisionNewPene::AreaCollisionNewPene_Type::Rect);
        node233->setTypeParams(0, 22.00f);
        node233->setTypeParams(1, 2.00f);
        node233->setPositionZ(.00f);
        CALL_REGISTER_SKILL_NODE(10072, 233, node233)
    }
    if (noInit == true) {
        return node233;
    }
    auto node197 = GET_SKILL_NODE(197, PhaseNode_GetLocation);
    auto node179 = GET_SKILL_NODE(179, PhaseNode_GetInputRotation);
    if (node197 != nullptr) node233->setPositionX(node197->getX());
    if (node197 != nullptr) node233->setPositionY(node197->getY());
    if (node179 != nullptr) node233->setRotation(node179->getAngle());
    return node233;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10072, 235) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_FindSkillBuff>(PhaseNode_Delay::TRIGGER_DONE, 189, PhaseNode_FindSkillBuff::FUNC_DO, &PhaseNode_FindSkillBuff::Do);
}

REGISTER_CREATE_SKILL_NODE(10072, 235) {
    auto node235 = GET_SKILL_NODE(235, PhaseNode_Delay);
    if (node235 == nullptr) {
        node235 = new PhaseNode_Delay(235, phase);
        node235->setTime(.10f);
        CALL_REGISTER_SKILL_NODE(10072, 235, node235)
    }
    if (noInit == true) {
        return node235;
    }
    return node235;
}
//--------------------------------------------------------------------------------
// ReviseMapI32
//
REGISTER_REGISTER_SKILL_NODE(10072, 241) {
    pnode->resizeTrigger(PhaseNode_ReviseMapI32::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_ReviseMapI32::TRIGGER_DONE, 76, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
}

REGISTER_CREATE_SKILL_NODE(10072, 241) {
    auto node241 = GET_SKILL_NODE(241, PhaseNode_ReviseMapI32);
    if (node241 == nullptr) {
        node241 = new PhaseNode_ReviseMapI32(241, phase);
        node241->reviseValue(201, .00f);
        CALL_REGISTER_SKILL_NODE(10072, 241, node241)
    }
    if (noInit == true) {
        return node241;
    }
    auto node203 = GET_SKILL_NODE(203, PhaseNode_GetActorAttribute);
    auto node269 = GET_SKILL_NODE(269, PhaseNode_Int2Float);
    if (node203 != nullptr) node241->setInAttri(node203->getAttribute());
    if (node269 != nullptr) node241->reviseValue(201, node269->getFloat());
    return node241;
}
//--------------------------------------------------------------------------------
// TimeDown
//
REGISTER_REGISTER_SKILL_NODE(10072, 255) {
    pnode->resizeTrigger(PhaseNode_TimeDown::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_IntOperation>(PhaseNode_TimeDown::TRIGGER_DONE, 261, PhaseNode_IntOperation::FUNC_OPERATION, &PhaseNode_IntOperation::Operation);
}

REGISTER_CREATE_SKILL_NODE(10072, 255) {
    auto node255 = GET_SKILL_NODE(255, PhaseNode_TimeDown);
    if (node255 == nullptr) {
        node255 = new PhaseNode_TimeDown(255, phase);
        node255->setTime(.30f);
        node255->setNum(5);
        node255->setIsImmediateFirst(false);
        CALL_REGISTER_SKILL_NODE(10072, 255, node255)
    }
    if (noInit == true) {
        return node255;
    }
    return node255;
}
//--------------------------------------------------------------------------------
// IntOperation
//
REGISTER_REGISTER_SKILL_NODE(10072, 261) {
    pnode->resizeTrigger(PhaseNode_IntOperation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetInt>(PhaseNode_IntOperation::TRIGGER_DONE, 265, PhaseNode_SetInt::FUNC_SET, &PhaseNode_SetInt::Set);
}

REGISTER_CREATE_SKILL_NODE(10072, 261) {
    auto node261 = GET_SKILL_NODE(261, PhaseNode_IntOperation);
    if (node261 == nullptr) {
        node261 = new PhaseNode_IntOperation(261, phase);
        node261->setValue(1);
        node261->setMethod(PhaseNode_IntOperation::IntOperation_Method::Add);
        CALL_REGISTER_SKILL_NODE(10072, 261, node261)
    }
    if (noInit == true) {
        return node261;
    }
    auto variables = node261->getVariables();
    if (variables != nullptr) {
        node261->setBase(variables->getVariable<int32_t>(Variable_10072_miaozhunNum));
    }
    return node261;
}
//--------------------------------------------------------------------------------
// SetInt
//
REGISTER_REGISTER_SKILL_NODE(10072, 265) {
    pnode->resizeTrigger(PhaseNode_SetInt::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareInt>(PhaseNode_SetInt::TRIGGER_DONE, 282, PhaseNode_CompareInt::FUNC_COMPARE, &PhaseNode_CompareInt::Compare);
}

REGISTER_CREATE_SKILL_NODE(10072, 265) {
    auto node265 = GET_SKILL_NODE(265, PhaseNode_SetInt);
    if (node265 == nullptr) {
        node265 = new PhaseNode_SetInt(265, phase);
        node265->setName("miaozhunNum");
        CALL_REGISTER_SKILL_NODE(10072, 265, node265)
    }
    if (noInit == true) {
        return node265;
    }
    auto node261 = GET_SKILL_NODE(261, PhaseNode_IntOperation);
    if (node261 != nullptr) node265->setValue(node261->getFinal());
    return node265;
}
//--------------------------------------------------------------------------------
// Int2Float
//
REGISTER_REGISTER_SKILL_NODE(10072, 269) {
    pnode->resizeTrigger(PhaseNode_Int2Float::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ReviseMapI32>(PhaseNode_Int2Float::TRIGGER_DONE, 241, PhaseNode_ReviseMapI32::FUNC_DO, &PhaseNode_ReviseMapI32::Do);
}

REGISTER_CREATE_SKILL_NODE(10072, 269) {
    auto node269 = GET_SKILL_NODE(269, PhaseNode_Int2Float);
    if (node269 == nullptr) {
        node269 = new PhaseNode_Int2Float(269, phase);
        CALL_REGISTER_SKILL_NODE(10072, 269, node269)
    }
    if (noInit == true) {
        return node269;
    }
    auto variables = node269->getVariables();
    if (variables != nullptr) {
        node269->setInt(variables->getVariable<int32_t>(Variable_10072_miaozhunNum));
    }
    return node269;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(10072, 278) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Disable>(PhaseNode_PlayEffect::TRIGGER_DONE, 140, PhaseNode_Disable::FUNC_DO, &PhaseNode_Disable::Do);
}

REGISTER_CREATE_SKILL_NODE(10072, 278) {
    auto node278 = GET_SKILL_NODE(278, PhaseNode_PlayEffect);
    if (node278 == nullptr) {
        node278 = new PhaseNode_PlayEffect(278, phase);
        node278->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node278->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node278->setEffectID(1064);
        node278->setChangeColor(false);
        node278->setType(PhaseNode_PlayEffect::PlayEffect_Type::WithTarget);
        node278->getVars().reserve(6);
        node278->getVars().setVariable<uint64_t>(0, 0U);
        node278->getVars().setVariable<std::string>(1, "Effect");
        node278->getVars().setVariable<float>(2, .00f);
        node278->getVars().setVariable<float>(3, .00f);
        node278->getVars().setVariable<float>(4, .00f);
        node278->getVars().setVariable<bool>(5, false);
        node278->setRotation(.00f);
        node278->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(10072, 278, node278)
    }
    if (noInit == true) {
        return node278;
    }
    return node278;
}
//--------------------------------------------------------------------------------
// StopEffect
//
REGISTER_REGISTER_SKILL_NODE(10072, 280) {
    pnode->resizeTrigger(PhaseNode_StopEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StopEffect>(PhaseNode_StopEffect::TRIGGER_DONE, 227, PhaseNode_StopEffect::FUNC_DO, &PhaseNode_StopEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(10072, 280) {
    auto node280 = GET_SKILL_NODE(280, PhaseNode_StopEffect);
    if (node280 == nullptr) {
        node280 = new PhaseNode_StopEffect(280, phase);
        node280->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node280->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node280->setEffectID(1064);
        CALL_REGISTER_SKILL_NODE(10072, 280, node280)
    }
    if (noInit == true) {
        return node280;
    }
    return node280;
}
//--------------------------------------------------------------------------------
// CompareInt
//
REGISTER_REGISTER_SKILL_NODE(10072, 282) {
    pnode->resizeTrigger(PhaseNode_CompareInt::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_CompareInt::TRIGGER_EQUAL, 225, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(10072, 282) {
    auto node282 = GET_SKILL_NODE(282, PhaseNode_CompareInt);
    if (node282 == nullptr) {
        node282 = new PhaseNode_CompareInt(282, phase);
        node282->setB(0);
        CALL_REGISTER_SKILL_NODE(10072, 282, node282)
    }
    if (noInit == true) {
        return node282;
    }
    auto node255 = GET_SKILL_NODE(255, PhaseNode_TimeDown);
    if (node255 != nullptr) node282->setA(node255->getLeftNum());
    return node282;
}
//--------------------------------------------------------------------------------
// StopEffect
//
REGISTER_REGISTER_SKILL_NODE(10072, 284) {
}

REGISTER_CREATE_SKILL_NODE(10072, 284) {
    auto node284 = GET_SKILL_NODE(284, PhaseNode_StopEffect);
    if (node284 == nullptr) {
        node284 = new PhaseNode_StopEffect(284, phase);
        node284->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node284->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node284->setEffectID(1064);
        CALL_REGISTER_SKILL_NODE(10072, 284, node284)
    }
    if (noInit == true) {
        return node284;
    }
    return node284;
}
//--------------------------------------------------------------------------------
// PlayUIEffect
//
REGISTER_REGISTER_SKILL_NODE(10072, 287) {
    pnode->resizeTrigger(PhaseNode_PlayUIEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_PlayUIEffect::TRIGGER_DONE, 278, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(10072, 287) {
    auto node287 = GET_SKILL_NODE(287, PhaseNode_PlayUIEffect);
    if (node287 == nullptr) {
        node287 = new PhaseNode_PlayUIEffect(287, phase);
        node287->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node287->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node287->setTime(1.50f);
        node287->setType(1);
        CALL_REGISTER_SKILL_NODE(10072, 287, node287)
    }
    if (noInit == true) {
        return node287;
    }
    return node287;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10072, 289) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_IsInterruptType>(PhaseNode_Detect::TRIGGER_ON, 295, PhaseNode_IsInterruptType::FUNC_DO, &PhaseNode_IsInterruptType::Do);
}

REGISTER_CREATE_SKILL_NODE(10072, 289) {
    auto node289 = GET_SKILL_NODE(289, PhaseNode_Detect);
    if (node289 == nullptr) {
        node289 = new PhaseNode_Detect(289, phase);
        node289->setSelf(0U);
        node289->setEvent("daduan_001");
        node289->setType(PhaseNode_Detect::Detect_Type::Interrupt_Skill);
        node289->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10072, 289, node289)
    }
    if (noInit == true) {
        return node289;
    }
    return node289;
}
//--------------------------------------------------------------------------------
// SwitchToInt
//
REGISTER_REGISTER_SKILL_NODE(10072, 290) {
    pnode->resizeTrigger(4);
    pnode->regTrigger<PhaseNode_ResetCD>(1, 215, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(10072, 290) {
    auto node290 = GET_SKILL_NODE(290, PhaseNode_SwitchToInt);
    if (node290 == nullptr) {
        node290 = new PhaseNode_SwitchToInt(290, phase);
        CALL_REGISTER_SKILL_NODE(10072, 290, node290)
    }
    if (noInit == true) {
        return node290;
    }
    auto variables = node290->getVariables();
    if (variables != nullptr) {
        node290->setSelection(variables->getVariable<int32_t>(Variable_10072_a100722));
    }
    return node290;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10072, 292) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_RaiseEvent::TRIGGER_DONE, 301, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10072, 292) {
    auto node292 = GET_SKILL_NODE(292, PhaseNode_RaiseEvent);
    if (node292 == nullptr) {
        node292 = new PhaseNode_RaiseEvent(292, phase);
        node292->setEvent("daduan_001");
        node292->setTarget(0U);
        node292->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node292->setTypeParams(0, 0);
        node292->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10072, 292, node292)
    }
    if (noInit == true) {
        return node292;
    }
    return node292;
}
//--------------------------------------------------------------------------------
// StartPreInput
//
REGISTER_REGISTER_SKILL_NODE(10072, 293) {
    pnode->resizeTrigger(PhaseNode_StartPreInput::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_StartPreInput::TRIGGER_DONE, 297, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_StartPreInput::TRIGGER_DONE, 199, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10072, 293) {
    auto node293 = GET_SKILL_NODE(293, PhaseNode_StartPreInput);
    if (node293 == nullptr) {
        node293 = new PhaseNode_StartPreInput(293, phase);
        node293->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node293->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node293->setDelayTime(1.20f);
        CALL_REGISTER_SKILL_NODE(10072, 293, node293)
    }
    if (noInit == true) {
        return node293;
    }
    return node293;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(10072, 294) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_If::TRIGGER_TRUE, 296, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10072, 294) {
    auto node294 = GET_SKILL_NODE(294, PhaseNode_If);
    if (node294 == nullptr) {
        node294 = new PhaseNode_If(294, phase);
        CALL_REGISTER_SKILL_NODE(10072, 294, node294)
    }
    if (noInit == true) {
        return node294;
    }
    auto variables = node294->getVariables();
    if (variables != nullptr) {
        node294->setCondition(variables->getVariable<bool>(Variable_10072_InterruptAnimat));
    }
    return node294;
}
//--------------------------------------------------------------------------------
// IsInterruptType
//
REGISTER_REGISTER_SKILL_NODE(10072, 295) {
    pnode->resizeTrigger(PhaseNode_IsInterruptType::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SwitchToInt>(PhaseNode_IsInterruptType::TRIGGER_BUFF, 290, PhaseNode_SwitchToInt::FUNC_SWITCH, &PhaseNode_SwitchToInt::Switch);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_POSCHANGE, 294, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTAIM, 294, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTFIRE, 294, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTRELOAD, 294, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_USESKILL, 294, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(10072, 295) {
    auto node295 = GET_SKILL_NODE(295, PhaseNode_IsInterruptType);
    if (node295 == nullptr) {
        node295 = new PhaseNode_IsInterruptType(295, phase);
        node295->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node295->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10072, 295, node295)
    }
    if (noInit == true) {
        return node295;
    }
    auto node289 = GET_SKILL_NODE(289, PhaseNode_Detect);
    if (node289 != nullptr) node295->setType(node289->getVars().getVariable<int32_t>(2));
    return node295;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10072, 296) {
}

REGISTER_CREATE_SKILL_NODE(10072, 296) {
    auto node296 = GET_SKILL_NODE(296, PhaseNode_PlayAnimation);
    if (node296 == nullptr) {
        node296 = new PhaseNode_PlayAnimation(296, phase);
        node296->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node296->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node296->setTarget(0U);
        node296->setAnimation("Idle");
        node296->setParameter("");
        node296->setValue(false);
        CALL_REGISTER_SKILL_NODE(10072, 296, node296)
    }
    if (noInit == true) {
        return node296;
    }
    return node296;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10072, 297) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_Delay::TRIGGER_DONE, 300, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(10072, 297) {
    auto node297 = GET_SKILL_NODE(297, PhaseNode_Delay);
    if (node297 == nullptr) {
        node297 = new PhaseNode_Delay(297, phase);
        node297->setTime(1.20f);
        CALL_REGISTER_SKILL_NODE(10072, 297, node297)
    }
    if (noInit == true) {
        return node297;
    }
    return node297;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(10072, 300) {
}

REGISTER_CREATE_SKILL_NODE(10072, 300) {
    auto node300 = GET_SKILL_NODE(300, PhaseNode_SetBool);
    if (node300 == nullptr) {
        node300 = new PhaseNode_SetBool(300, phase);
        node300->setName("InterruptAnimat");
        node300->setValue(true);
        CALL_REGISTER_SKILL_NODE(10072, 300, node300)
    }
    if (noInit == true) {
        return node300;
    }
    return node300;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10072, 301) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StartPreInput>(PhaseNode_RaiseEvent::TRIGGER_DONE, 293, PhaseNode_StartPreInput::FUNC_DO, &PhaseNode_StartPreInput::Do);
}

REGISTER_CREATE_SKILL_NODE(10072, 301) {
    auto node301 = GET_SKILL_NODE(301, PhaseNode_RaiseEvent);
    if (node301 == nullptr) {
        node301 = new PhaseNode_RaiseEvent(301, phase);
        node301->setEvent("Dead_001");
        node301->setTarget(0U);
        node301->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node301->setTypeParams(0, 0);
        node301->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10072, 301, node301)
    }
    if (noInit == true) {
        return node301;
    }
    return node301;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10072, 302) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_Detect::TRIGGER_ON, 215, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(10072, 302) {
    auto node302 = GET_SKILL_NODE(302, PhaseNode_Detect);
    if (node302 == nullptr) {
        node302 = new PhaseNode_Detect(302, phase);
        node302->setSelf(0U);
        node302->setEvent("Dead_001");
        node302->setType(PhaseNode_Detect::Detect_Type::Actor_Dead);
        node302->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10072, 302, node302)
    }
    if (noInit == true) {
        return node302;
    }
    return node302;
}

//--------------------------------------------------------------------------------
// SkillCreator_10072
//
class SkillCreator_10072 : public SkillCreator {
public:
    SkillCreator_10072() {}
    virtual ~SkillCreator_10072() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_10072

//--------------------------------------------------------------------------------
// SkillPhase_10072
//
class SkillPhase_10072 : public SkillPhase {
public:
    SkillPhase_10072(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_10072() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(10072, 1) // StartPhase
        CASE_CREATE_SKILL_NODE(10072, 23) // Delay
        CASE_CREATE_SKILL_NODE(10072, 49) // Disable
        CASE_CREATE_SKILL_NODE(10072, 71) // PlaySound
        CASE_CREATE_SKILL_NODE(10072, 76) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(10072, 96) // EndPhase
        CASE_CREATE_SKILL_NODE(10072, 100) // PlayEffect
        CASE_CREATE_SKILL_NODE(10072, 103) // OffsetCalculate
        CASE_CREATE_SKILL_NODE(10072, 109) // PlayEffect
        CASE_CREATE_SKILL_NODE(10072, 110) // PlaySound
        CASE_CREATE_SKILL_NODE(10072, 112) // Delay
        CASE_CREATE_SKILL_NODE(10072, 114) // PlayEffect
        CASE_CREATE_SKILL_NODE(10072, 118) // CameraXYZShake
        CASE_CREATE_SKILL_NODE(10072, 140) // Disable
        CASE_CREATE_SKILL_NODE(10072, 170) // ConfirmPhase
        CASE_CREATE_SKILL_NODE(10072, 179) // GetInputRotation
        CASE_CREATE_SKILL_NODE(10072, 181) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10072, 185) // CameraOffset
        CASE_CREATE_SKILL_NODE(10072, 189) // FindSkillBuff
        CASE_CREATE_SKILL_NODE(10072, 191) // If
        CASE_CREATE_SKILL_NODE(10072, 197) // GetLocation
        CASE_CREATE_SKILL_NODE(10072, 199) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10072, 203) // GetActorAttribute
        CASE_CREATE_SKILL_NODE(10072, 205) // PlaySound
        CASE_CREATE_SKILL_NODE(10072, 208) // ResetCD
        CASE_CREATE_SKILL_NODE(10072, 215) // ResetCD
        CASE_CREATE_SKILL_NODE(10072, 220) // Delay
        CASE_CREATE_SKILL_NODE(10072, 222) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10072, 225) // PlayEffect
        CASE_CREATE_SKILL_NODE(10072, 227) // StopEffect
        CASE_CREATE_SKILL_NODE(10072, 229) // CancelPhase
        CASE_CREATE_SKILL_NODE(10072, 231) // CameraOffset
        CASE_CREATE_SKILL_NODE(10072, 233) // AreaCollisionNewPene
        CASE_CREATE_SKILL_NODE(10072, 235) // Delay
        CASE_CREATE_SKILL_NODE(10072, 241) // ReviseMapI32
        CASE_CREATE_SKILL_NODE(10072, 255) // TimeDown
        CASE_CREATE_SKILL_NODE(10072, 261) // IntOperation
        CASE_CREATE_SKILL_NODE(10072, 265) // SetInt
        CASE_CREATE_SKILL_NODE(10072, 269) // Int2Float
        CASE_CREATE_SKILL_NODE(10072, 278) // PlayEffect
        CASE_CREATE_SKILL_NODE(10072, 280) // StopEffect
        CASE_CREATE_SKILL_NODE(10072, 282) // CompareInt
        CASE_CREATE_SKILL_NODE(10072, 284) // StopEffect
        CASE_CREATE_SKILL_NODE(10072, 287) // PlayUIEffect
        CASE_CREATE_SKILL_NODE(10072, 289) // Detect
        CASE_CREATE_SKILL_NODE(10072, 290) // SwitchToInt
        CASE_CREATE_SKILL_NODE(10072, 292) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10072, 293) // StartPreInput
        CASE_CREATE_SKILL_NODE(10072, 294) // If
        CASE_CREATE_SKILL_NODE(10072, 295) // IsInterruptType
        CASE_CREATE_SKILL_NODE(10072, 296) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10072, 297) // Delay
        CASE_CREATE_SKILL_NODE(10072, 300) // SetBool
        CASE_CREATE_SKILL_NODE(10072, 301) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10072, 302) // Detect
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_10072

SkillLogic* SkillCreator_10072::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //设置变量
    Variable_10072_miaozhunNum = logic->getVariables().setVariable<int32_t>("miaozhunNum", 1);
    Variable_10072_a100722 = logic->getVariables().setVariable<int32_t>("a100722", 1);
    Variable_10072_InterruptAnimat = logic->getVariables().setVariable<bool>("InterruptAnimat");
    //创建阶段phase
    auto phase = new SkillPhase_10072(1, logic, 4);
    //设置phase执行器
    phase->setRunPhaseNode(1, 1);
    phase->addConfirmPhaseNode(2, 170);
    phase->addCancelPhaseNode(3, 229);
    phase->setDetectPhaseNode(4, 289);
    phase->setDetectPhaseNode(4, 302);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_10072::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
