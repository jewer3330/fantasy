#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

#include "skill_psnode_addskillbuff.h"
#include "skill_psnode_confirmphase.h"
#include "skill_psnode_costbuffattribute.h"
#include "skill_psnode_delay.h"
#include "skill_psnode_destroyactor.h"
#include "skill_psnode_detect.h"
#include "skill_psnode_disable.h"
#include "skill_psnode_endflow.h"
#include "skill_psnode_endphase.h"
#include "skill_psnode_getbuffattribute.h"
#include "skill_psnode_getlocation.h"
#include "skill_psnode_getrotation.h"
#include "skill_psnode_if.h"
#include "skill_psnode_isinterrupttype.h"
#include "skill_psnode_offsetcalculate.h"
#include "skill_psnode_playanimation.h"
#include "skill_psnode_playsound.h"
#include "skill_psnode_raiseevent.h"
#include "skill_psnode_removeskillbuff.h"
#include "skill_psnode_resetcd.h"
#include "skill_psnode_setbool.h"
#include "skill_psnode_setbuffattribute.h"
#include "skill_psnode_setint.h"
#include "skill_psnode_setlocation.h"
#include "skill_psnode_setrotation.h"
#include "skill_psnode_setuint64.h"
#include "skill_psnode_spawnactor.h"
#include "skill_psnode_startphase.h"
#include "skill_psnode_startpreinput.h"
#include "skill_psnode_switchtoint.h"

namespace pvp {

//变量声明
uint64_t Variable_10041_hudunCancle = 0;
uint64_t Variable_10041_hudun = 0;
uint64_t Variable_10041_a100411 = 0;
uint64_t Variable_10041_renwudead = 0;
uint64_t Variable_10041_a100412 = 0;
uint64_t Variable_10041_InterruptAnimat = 0;
//--------------------------------------------------------------------------------
// StartPhase
//
REGISTER_REGISTER_SKILL_NODE(10041, 2) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_StartPhase::TRIGGER_START, 7, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10041, 2) {
    auto node2 = GET_SKILL_NODE(2, PhaseNode_StartPhase);
    if (node2 == nullptr) {
        node2 = new PhaseNode_StartPhase(2, phase);
        CALL_REGISTER_SKILL_NODE(10041, 2, node2)
    }
    if (noInit == true) {
        return node2;
    }
    return node2;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(10041, 3) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetRotation>(PhaseNode_GetLocation::TRIGGER_DONE, 4, PhaseNode_GetRotation::FUNC_DO, &PhaseNode_GetRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(10041, 3) {
    auto node3 = GET_SKILL_NODE(3, PhaseNode_GetLocation);
    if (node3 == nullptr) {
        node3 = new PhaseNode_GetLocation(3, phase);
        node3->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node3->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(10041, 3, node3)
    }
    if (noInit == true) {
        return node3;
    }
    return node3;
}
//--------------------------------------------------------------------------------
// GetRotation
//
REGISTER_REGISTER_SKILL_NODE(10041, 4) {
    pnode->resizeTrigger(PhaseNode_GetRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_GetRotation::TRIGGER_DONE, 573, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10041, 4) {
    auto node4 = GET_SKILL_NODE(4, PhaseNode_GetRotation);
    if (node4 == nullptr) {
        node4 = new PhaseNode_GetRotation(4, phase);
        node4->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node4->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(10041, 4, node4)
    }
    if (noInit == true) {
        return node4;
    }
    return node4;
}
//--------------------------------------------------------------------------------
// SpawnActor
//
REGISTER_REGISTER_SKILL_NODE(10041, 6) {
    pnode->resizeTrigger(PhaseNode_SpawnActor::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_SpawnActor::TRIGGER_DONE, 638, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(10041, 6) {
    auto node6 = GET_SKILL_NODE(6, PhaseNode_SpawnActor);
    if (node6 == nullptr) {
        node6 = new PhaseNode_SpawnActor(6, phase);
        node6->setConfigID(5001);
        node6->setTime(.00f);
        node6->setLevel(1);
        node6->setMaxCount(1);
        CALL_REGISTER_SKILL_NODE(10041, 6, node6)
    }
    if (noInit == true) {
        return node6;
    }
    auto node18 = GET_SKILL_NODE(18, PhaseNode_OffsetCalculate);
    if (node18 != nullptr) node6->setPosX(node18->getOutPosX());
    if (node18 != nullptr) node6->setPosY(node18->getOutPosY());
    if (node18 != nullptr) node6->setPosZ(node18->getOutPosZ());
    if (node18 != nullptr) node6->setRotation(node18->getOutRotation());
    return node6;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10041, 7) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_PlayAnimation::TRIGGER_DONE, 569, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_PlayAnimation::TRIGGER_DONE, 698, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10041, 7) {
    auto node7 = GET_SKILL_NODE(7, PhaseNode_PlayAnimation);
    if (node7 == nullptr) {
        node7 = new PhaseNode_PlayAnimation(7, phase);
        node7->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node7->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node7->setTarget(0U);
        node7->setAnimation("Skill1S1");
        node7->setParameter("SkillArmBusy");
        node7->setValue(true);
        CALL_REGISTER_SKILL_NODE(10041, 7, node7)
    }
    if (noInit == true) {
        return node7;
    }
    return node7;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(10041, 8) {
}

REGISTER_CREATE_SKILL_NODE(10041, 8) {
    auto node8 = GET_SKILL_NODE(8, PhaseNode_EndPhase);
    if (node8 == nullptr) {
        node8 = new PhaseNode_EndPhase(8, phase);
        node8->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node8->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10041, 8, node8)
    }
    if (noInit == true) {
        return node8;
    }
    return node8;
}
//--------------------------------------------------------------------------------
// SetUInt64
//
REGISTER_REGISTER_SKILL_NODE(10041, 14) {
    pnode->resizeTrigger(PhaseNode_SetUInt64::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuff>(PhaseNode_SetUInt64::TRIGGER_DONE, 652, PhaseNode_AddSkillBuff::FUNC_ADD, &PhaseNode_AddSkillBuff::Add);
}

REGISTER_CREATE_SKILL_NODE(10041, 14) {
    auto node14 = GET_SKILL_NODE(14, PhaseNode_SetUInt64);
    if (node14 == nullptr) {
        node14 = new PhaseNode_SetUInt64(14, phase);
        node14->setName("hudun");
        CALL_REGISTER_SKILL_NODE(10041, 14, node14)
    }
    if (noInit == true) {
        return node14;
    }
    auto node6 = GET_SKILL_NODE(6, PhaseNode_SpawnActor);
    if (node6 != nullptr) node14->setValue(node6->getActorID());
    return node14;
}
//--------------------------------------------------------------------------------
// DestroyActor
//
REGISTER_REGISTER_SKILL_NODE(10041, 17) {
}

REGISTER_CREATE_SKILL_NODE(10041, 17) {
    auto node17 = GET_SKILL_NODE(17, PhaseNode_DestroyActor);
    if (node17 == nullptr) {
        node17 = new PhaseNode_DestroyActor(17, phase);
        CALL_REGISTER_SKILL_NODE(10041, 17, node17)
    }
    if (noInit == true) {
        return node17;
    }
    auto variables = node17->getVariables();
    if (variables != nullptr) {
        node17->setActorID(variables->getVariable<uint64_t>(Variable_10041_hudun));
    }
    return node17;
}
//--------------------------------------------------------------------------------
// OffsetCalculate
//
REGISTER_REGISTER_SKILL_NODE(10041, 18) {
    pnode->resizeTrigger(PhaseNode_OffsetCalculate::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnActor>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 6, PhaseNode_SpawnActor::FUNC_DO, &PhaseNode_SpawnActor::Do);
}

REGISTER_CREATE_SKILL_NODE(10041, 18) {
    auto node18 = GET_SKILL_NODE(18, PhaseNode_OffsetCalculate);
    if (node18 == nullptr) {
        node18 = new PhaseNode_OffsetCalculate(18, phase);
        node18->setPosZ(.00f);
        node18->setOffsetX(.00f);
        node18->setOffsetY(2.00f);
        node18->setOffsetZ(.00f);
        node18->setRotOffset(.00f);
        CALL_REGISTER_SKILL_NODE(10041, 18, node18)
    }
    if (noInit == true) {
        return node18;
    }
    auto node3 = GET_SKILL_NODE(3, PhaseNode_GetLocation);
    auto node4 = GET_SKILL_NODE(4, PhaseNode_GetRotation);
    if (node3 != nullptr) node18->setPosX(node3->getX());
    if (node3 != nullptr) node18->setPosY(node3->getY());
    if (node4 != nullptr) node18->setRotation(node4->getAngle());
    return node18;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10041, 19) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetUInt64>(PhaseNode_PlayAnimation::TRIGGER_DONE, 14, PhaseNode_SetUInt64::FUNC_SET, &PhaseNode_SetUInt64::Set);
}

REGISTER_CREATE_SKILL_NODE(10041, 19) {
    auto node19 = GET_SKILL_NODE(19, PhaseNode_PlayAnimation);
    if (node19 == nullptr) {
        node19 = new PhaseNode_PlayAnimation(19, phase);
        node19->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node19->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node19->setTarget(0U);
        node19->setAnimation("Skill1S2");
        node19->setParameter("");
        node19->setValue(false);
        CALL_REGISTER_SKILL_NODE(10041, 19, node19)
    }
    if (noInit == true) {
        return node19;
    }
    return node19;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10041, 20) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Disable>(PhaseNode_PlayAnimation::TRIGGER_DONE, 672, PhaseNode_Disable::FUNC_DO, &PhaseNode_Disable::Do);
}

REGISTER_CREATE_SKILL_NODE(10041, 20) {
    auto node20 = GET_SKILL_NODE(20, PhaseNode_PlayAnimation);
    if (node20 == nullptr) {
        node20 = new PhaseNode_PlayAnimation(20, phase);
        node20->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node20->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node20->setTarget(0U);
        node20->setAnimation("Skill1S3");
        node20->setParameter("");
        node20->setValue(false);
        CALL_REGISTER_SKILL_NODE(10041, 20, node20)
    }
    if (noInit == true) {
        return node20;
    }
    return node20;
}
//--------------------------------------------------------------------------------
// RemoveSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10041, 53) {
    pnode->resizeTrigger(PhaseNode_RemoveSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuff>(PhaseNode_RemoveSkillBuff::TRIGGER_DONE, 596, PhaseNode_AddSkillBuff::FUNC_ADD, &PhaseNode_AddSkillBuff::Add);
}

REGISTER_CREATE_SKILL_NODE(10041, 53) {
    auto node53 = GET_SKILL_NODE(53, PhaseNode_RemoveSkillBuff);
    if (node53 == nullptr) {
        node53 = new PhaseNode_RemoveSkillBuff(53, phase);
        node53->setBuffID(0U);
        node53->setBuffIDs({});
        node53->setConfigID(100411);
        node53->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(10041, 53, node53)
    }
    if (noInit == true) {
        return node53;
    }
    return node53;
}
//--------------------------------------------------------------------------------
// EndFlow
//
REGISTER_REGISTER_SKILL_NODE(10041, 80) {
}

REGISTER_CREATE_SKILL_NODE(10041, 80) {
    auto node80 = GET_SKILL_NODE(80, PhaseNode_EndFlow);
    if (node80 == nullptr) {
        node80 = new PhaseNode_EndFlow(80, phase);
        CALL_REGISTER_SKILL_NODE(10041, 80, node80)
    }
    if (noInit == true) {
        return node80;
    }
    return node80;
}
//--------------------------------------------------------------------------------
// OffsetCalculate
//
REGISTER_REGISTER_SKILL_NODE(10041, 85) {
    pnode->resizeTrigger(PhaseNode_OffsetCalculate::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetLocation>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 86, PhaseNode_SetLocation::FUNC_DO, &PhaseNode_SetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(10041, 85) {
    auto node85 = GET_SKILL_NODE(85, PhaseNode_OffsetCalculate);
    if (node85 == nullptr) {
        node85 = new PhaseNode_OffsetCalculate(85, phase);
        node85->setPosZ(.00f);
        node85->setOffsetX(.00f);
        node85->setOffsetY(2.00f);
        node85->setOffsetZ(.00f);
        node85->setRotOffset(.00f);
        CALL_REGISTER_SKILL_NODE(10041, 85, node85)
    }
    if (noInit == true) {
        return node85;
    }
    auto node680 = GET_SKILL_NODE(680, PhaseNode_Detect);
    if (node680 != nullptr) node85->setPosX(node680->getVars().getVariable<float>(0));
    if (node680 != nullptr) node85->setPosY(node680->getVars().getVariable<float>(1));
    if (node680 != nullptr) node85->setRotation(node680->getVars().getVariable<float>(4));
    return node85;
}
//--------------------------------------------------------------------------------
// SetLocation
//
REGISTER_REGISTER_SKILL_NODE(10041, 86) {
    pnode->resizeTrigger(PhaseNode_SetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetRotation>(PhaseNode_SetLocation::TRIGGER_DONE, 87, PhaseNode_SetRotation::FUNC_DO, &PhaseNode_SetRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(10041, 86) {
    auto node86 = GET_SKILL_NODE(86, PhaseNode_SetLocation);
    if (node86 == nullptr) {
        node86 = new PhaseNode_SetLocation(86, phase);
        node86->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node86->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10041, 86, node86)
    }
    if (noInit == true) {
        return node86;
    }
    auto variables = node86->getVariables();
    if (variables != nullptr) {
        node86->setTarget(variables->getVariable<uint64_t>(Variable_10041_hudun));
    }
    auto node85 = GET_SKILL_NODE(85, PhaseNode_OffsetCalculate);
    auto node680 = GET_SKILL_NODE(680, PhaseNode_Detect);
    if (node85 != nullptr) node86->setX(node85->getOutPosX());
    if (node85 != nullptr) node86->setY(node85->getOutPosY());
    if (node680 != nullptr) node86->setVX(node680->getVars().getVariable<float>(2));
    if (node680 != nullptr) node86->setVY(node680->getVars().getVariable<float>(3));
    return node86;
}
//--------------------------------------------------------------------------------
// SetRotation
//
REGISTER_REGISTER_SKILL_NODE(10041, 87) {
}

REGISTER_CREATE_SKILL_NODE(10041, 87) {
    auto node87 = GET_SKILL_NODE(87, PhaseNode_SetRotation);
    if (node87 == nullptr) {
        node87 = new PhaseNode_SetRotation(87, phase);
        node87->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node87->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10041, 87, node87)
    }
    if (noInit == true) {
        return node87;
    }
    auto variables = node87->getVariables();
    if (variables != nullptr) {
        node87->setTarget(variables->getVariable<uint64_t>(Variable_10041_hudun));
    }
    auto node85 = GET_SKILL_NODE(85, PhaseNode_OffsetCalculate);
    if (node85 != nullptr) node87->setAngle(node85->getOutRotation());
    return node87;
}
//--------------------------------------------------------------------------------
// GetBuffAttribute
//
REGISTER_REGISTER_SKILL_NODE(10041, 88) {
    pnode->resizeTrigger(PhaseNode_GetBuffAttribute::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBuffAttribute>(PhaseNode_GetBuffAttribute::TRIGGER_DONE, 89, PhaseNode_SetBuffAttribute::FUNC_DO, &PhaseNode_SetBuffAttribute::Do);
}

REGISTER_CREATE_SKILL_NODE(10041, 88) {
    auto node88 = GET_SKILL_NODE(88, PhaseNode_GetBuffAttribute);
    if (node88 == nullptr) {
        node88 = new PhaseNode_GetBuffAttribute(88, phase);
        node88->setTarget(0U);
        node88->setAttribute(22);
        CALL_REGISTER_SKILL_NODE(10041, 88, node88)
    }
    if (noInit == true) {
        return node88;
    }
    return node88;
}
//--------------------------------------------------------------------------------
// SetBuffAttribute
//
REGISTER_REGISTER_SKILL_NODE(10041, 89) {
    pnode->resizeTrigger(PhaseNode_SetBuffAttribute::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_SetBuffAttribute::TRIGGER_DONE, 684, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10041, 89) {
    auto node89 = GET_SKILL_NODE(89, PhaseNode_SetBuffAttribute);
    if (node89 == nullptr) {
        node89 = new PhaseNode_SetBuffAttribute(89, phase);
        node89->setAttribute(1);
        CALL_REGISTER_SKILL_NODE(10041, 89, node89)
    }
    if (noInit == true) {
        return node89;
    }
    auto node6 = GET_SKILL_NODE(6, PhaseNode_SpawnActor);
    auto node88 = GET_SKILL_NODE(88, PhaseNode_GetBuffAttribute);
    if (node6 != nullptr) node89->setTarget(node6->getActorID());
    if (node88 != nullptr) node89->setValue(node88->getValue());
    return node89;
}
//--------------------------------------------------------------------------------
// CostBuffAttribute
//
REGISTER_REGISTER_SKILL_NODE(10041, 142) {
}

REGISTER_CREATE_SKILL_NODE(10041, 142) {
    auto node142 = GET_SKILL_NODE(142, PhaseNode_CostBuffAttribute);
    if (node142 == nullptr) {
        node142 = new PhaseNode_CostBuffAttribute(142, phase);
        node142->setTarget(0U);
        node142->setAttribute(22);
        CALL_REGISTER_SKILL_NODE(10041, 142, node142)
    }
    if (noInit == true) {
        return node142;
    }
    auto node691 = GET_SKILL_NODE(691, PhaseNode_Detect);
    if (node691 != nullptr) node142->setValue(node691->getVars().getVariable<int32_t>(0));
    return node142;
}
//--------------------------------------------------------------------------------
// RemoveSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10041, 207) {
    pnode->resizeTrigger(PhaseNode_RemoveSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_RemoveSkillBuff::TRIGGER_DONE, 667, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(10041, 207) {
    auto node207 = GET_SKILL_NODE(207, PhaseNode_RemoveSkillBuff);
    if (node207 == nullptr) {
        node207 = new PhaseNode_RemoveSkillBuff(207, phase);
        node207->setBuffID(0U);
        node207->setBuffIDs({});
        node207->setConfigID(100412);
        node207->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(10041, 207, node207)
    }
    if (noInit == true) {
        return node207;
    }
    return node207;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(10041, 364) {
    pnode->resizeTrigger(PhaseNode_SetBool::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_SetBool::TRIGGER_DONE, 640, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(10041, 364) {
    auto node364 = GET_SKILL_NODE(364, PhaseNode_SetBool);
    if (node364 == nullptr) {
        node364 = new PhaseNode_SetBool(364, phase);
        node364->setName("hudunCancle");
        node364->setValue(true);
        CALL_REGISTER_SKILL_NODE(10041, 364, node364)
    }
    if (noInit == true) {
        return node364;
    }
    return node364;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(10041, 366) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_If::TRIGGER_FALSE, 658, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_If::TRIGGER_TRUE, 693, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10041, 366) {
    auto node366 = GET_SKILL_NODE(366, PhaseNode_If);
    if (node366 == nullptr) {
        node366 = new PhaseNode_If(366, phase);
        CALL_REGISTER_SKILL_NODE(10041, 366, node366)
    }
    if (noInit == true) {
        return node366;
    }
    auto variables = node366->getVariables();
    if (variables != nullptr) {
        node366->setCondition(variables->getVariable<bool>(Variable_10041_hudunCancle));
    }
    return node366;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(10041, 369) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_ResetCD::TRIGGER_DONE, 20, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10041, 369) {
    auto node369 = GET_SKILL_NODE(369, PhaseNode_ResetCD);
    if (node369 == nullptr) {
        node369 = new PhaseNode_ResetCD(369, phase);
        node369->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node369->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node369->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(10041, 369, node369)
    }
    if (noInit == true) {
        return node369;
    }
    return node369;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10041, 569) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_PlaySound::TRIGGER_DONE, 3, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(10041, 569) {
    auto node569 = GET_SKILL_NODE(569, PhaseNode_PlaySound);
    if (node569 == nullptr) {
        node569 = new PhaseNode_PlaySound(569, phase);
        node569->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node569->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node569->setSoundID("VO_Hero101_Skill_A");
        node569->setTarget(0U);
        node569->setUsePos(false);
        node569->setPosX(.00f);
        node569->setPosY(.00f);
        node569->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10041, 569, node569)
    }
    if (noInit == true) {
        return node569;
    }
    return node569;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10041, 573) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RemoveSkillBuff>(PhaseNode_PlaySound::TRIGGER_DONE, 53, PhaseNode_RemoveSkillBuff::FUNC_REMOVE, &PhaseNode_RemoveSkillBuff::Remove);
}

REGISTER_CREATE_SKILL_NODE(10041, 573) {
    auto node573 = GET_SKILL_NODE(573, PhaseNode_PlaySound);
    if (node573 == nullptr) {
        node573 = new PhaseNode_PlaySound(573, phase);
        node573->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node573->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node573->setSoundID("SE_Hero101_Skill_A_P1");
        node573->setTarget(0U);
        node573->setUsePos(false);
        node573->setPosX(.00f);
        node573->setPosY(.00f);
        node573->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10041, 573, node573)
    }
    if (noInit == true) {
        return node573;
    }
    return node573;
}
//--------------------------------------------------------------------------------
// AddSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10041, 594) {
    pnode->resizeTrigger(PhaseNode_AddSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RemoveSkillBuff>(PhaseNode_AddSkillBuff::TRIGGER_DONE, 207, PhaseNode_RemoveSkillBuff::FUNC_REMOVE, &PhaseNode_RemoveSkillBuff::Remove);
}

REGISTER_CREATE_SKILL_NODE(10041, 594) {
    auto node594 = GET_SKILL_NODE(594, PhaseNode_AddSkillBuff);
    if (node594 == nullptr) {
        node594 = new PhaseNode_AddSkillBuff(594, phase);
        node594->setConfigID(100411);
        node594->setConfigIDs({});
        node594->setTarget(0U);
        node594->setAttribute({{}});
        CALL_REGISTER_SKILL_NODE(10041, 594, node594)
    }
    if (noInit == true) {
        return node594;
    }
    return node594;
}
//--------------------------------------------------------------------------------
// AddSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10041, 596) {
    pnode->resizeTrigger(PhaseNode_AddSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_OffsetCalculate>(PhaseNode_AddSkillBuff::TRIGGER_DONE, 18, PhaseNode_OffsetCalculate::FUNC_DO, &PhaseNode_OffsetCalculate::Do);
}

REGISTER_CREATE_SKILL_NODE(10041, 596) {
    auto node596 = GET_SKILL_NODE(596, PhaseNode_AddSkillBuff);
    if (node596 == nullptr) {
        node596 = new PhaseNode_AddSkillBuff(596, phase);
        node596->setConfigID(100412);
        node596->setConfigIDs({});
        node596->setTarget(0U);
        node596->setAttribute({{}});
        CALL_REGISTER_SKILL_NODE(10041, 596, node596)
    }
    if (noInit == true) {
        return node596;
    }
    return node596;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(10041, 638) {
    pnode->resizeTrigger(PhaseNode_SetBool::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetInt>(PhaseNode_SetBool::TRIGGER_DONE, 645, PhaseNode_SetInt::FUNC_SET, &PhaseNode_SetInt::Set);
}

REGISTER_CREATE_SKILL_NODE(10041, 638) {
    auto node638 = GET_SKILL_NODE(638, PhaseNode_SetBool);
    if (node638 == nullptr) {
        node638 = new PhaseNode_SetBool(638, phase);
        node638->setName("a100411");
        node638->setValue(true);
        CALL_REGISTER_SKILL_NODE(10041, 638, node638)
    }
    if (noInit == true) {
        return node638;
    }
    return node638;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(10041, 640) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_If::TRIGGER_FALSE, 8, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
    pnode->regTrigger<PhaseNode_DestroyActor>(PhaseNode_If::TRIGGER_TRUE, 17, PhaseNode_DestroyActor::FUNC_DO, &PhaseNode_DestroyActor::Do);
}

REGISTER_CREATE_SKILL_NODE(10041, 640) {
    auto node640 = GET_SKILL_NODE(640, PhaseNode_If);
    if (node640 == nullptr) {
        node640 = new PhaseNode_If(640, phase);
        CALL_REGISTER_SKILL_NODE(10041, 640, node640)
    }
    if (noInit == true) {
        return node640;
    }
    auto variables = node640->getVariables();
    if (variables != nullptr) {
        node640->setCondition(variables->getVariable<bool>(Variable_10041_a100411));
    }
    return node640;
}
//--------------------------------------------------------------------------------
// SetInt
//
REGISTER_REGISTER_SKILL_NODE(10041, 645) {
    pnode->resizeTrigger(PhaseNode_SetInt::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_SetInt::TRIGGER_DONE, 19, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10041, 645) {
    auto node645 = GET_SKILL_NODE(645, PhaseNode_SetInt);
    if (node645 == nullptr) {
        node645 = new PhaseNode_SetInt(645, phase);
        node645->setName("a100412");
        node645->setValue(2);
        CALL_REGISTER_SKILL_NODE(10041, 645, node645)
    }
    if (noInit == true) {
        return node645;
    }
    return node645;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(10041, 650) {
    pnode->resizeTrigger(PhaseNode_SetBool::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_SetBool::TRIGGER_DONE, 640, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(10041, 650) {
    auto node650 = GET_SKILL_NODE(650, PhaseNode_SetBool);
    if (node650 == nullptr) {
        node650 = new PhaseNode_SetBool(650, phase);
        node650->setName("hudunCancle");
        node650->setValue(true);
        CALL_REGISTER_SKILL_NODE(10041, 650, node650)
    }
    if (noInit == true) {
        return node650;
    }
    return node650;
}
//--------------------------------------------------------------------------------
// AddSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10041, 652) {
    pnode->resizeTrigger(PhaseNode_AddSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetBuffAttribute>(PhaseNode_AddSkillBuff::TRIGGER_DONE, 88, PhaseNode_GetBuffAttribute::FUNC_DO, &PhaseNode_GetBuffAttribute::Do);
}

REGISTER_CREATE_SKILL_NODE(10041, 652) {
    auto node652 = GET_SKILL_NODE(652, PhaseNode_AddSkillBuff);
    if (node652 == nullptr) {
        node652 = new PhaseNode_AddSkillBuff(652, phase);
        node652->setConfigID(7);
        node652->setConfigIDs({});
        node652->setAttribute({{}});
        CALL_REGISTER_SKILL_NODE(10041, 652, node652)
    }
    if (noInit == true) {
        return node652;
    }
    auto node6 = GET_SKILL_NODE(6, PhaseNode_SpawnActor);
    if (node6 != nullptr) node652->setTarget(node6->getActorID());
    return node652;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10041, 658) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_PlaySound::TRIGGER_DONE, 369, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(10041, 658) {
    auto node658 = GET_SKILL_NODE(658, PhaseNode_PlaySound);
    if (node658 == nullptr) {
        node658 = new PhaseNode_PlaySound(658, phase);
        node658->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node658->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node658->setSoundID("SE_Hero101_Skill_A_P3");
        node658->setTarget(0U);
        node658->setUsePos(false);
        node658->setPosX(.00f);
        node658->setPosY(.00f);
        node658->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10041, 658, node658)
    }
    if (noInit == true) {
        return node658;
    }
    return node658;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(10041, 664) {
    pnode->resizeTrigger(PhaseNode_SetBool::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_SetBool::TRIGGER_DONE, 640, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(10041, 664) {
    auto node664 = GET_SKILL_NODE(664, PhaseNode_SetBool);
    if (node664 == nullptr) {
        node664 = new PhaseNode_SetBool(664, phase);
        node664->setName("renwudead");
        node664->setValue(true);
        CALL_REGISTER_SKILL_NODE(10041, 664, node664)
    }
    if (noInit == true) {
        return node664;
    }
    return node664;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(10041, 667) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_If::TRIGGER_FALSE, 366, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_If::TRIGGER_TRUE, 8, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(10041, 667) {
    auto node667 = GET_SKILL_NODE(667, PhaseNode_If);
    if (node667 == nullptr) {
        node667 = new PhaseNode_If(667, phase);
        CALL_REGISTER_SKILL_NODE(10041, 667, node667)
    }
    if (noInit == true) {
        return node667;
    }
    auto variables = node667->getVariables();
    if (variables != nullptr) {
        node667->setCondition(variables->getVariable<bool>(Variable_10041_renwudead));
    }
    return node667;
}
//--------------------------------------------------------------------------------
// Disable
//
REGISTER_REGISTER_SKILL_NODE(10041, 672) {
    pnode->resizeTrigger(PhaseNode_Disable::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_Disable::TRIGGER_DONE, 675, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10041, 672) {
    auto node672 = GET_SKILL_NODE(672, PhaseNode_Disable);
    if (node672 == nullptr) {
        node672 = new PhaseNode_Disable(672, phase);
        node672->setTarget(0U);
        node672->setMove(false);
        node672->setSkill(true);
        node672->setShoot(true);
        node672->setTime(.30f);
        node672->setRotate(false);
        CALL_REGISTER_SKILL_NODE(10041, 672, node672)
    }
    if (noInit == true) {
        return node672;
    }
    return node672;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10041, 675) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_Delay::TRIGGER_DONE, 8, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(10041, 675) {
    auto node675 = GET_SKILL_NODE(675, PhaseNode_Delay);
    if (node675 == nullptr) {
        node675 = new PhaseNode_Delay(675, phase);
        node675->setTime(.30f);
        CALL_REGISTER_SKILL_NODE(10041, 675, node675)
    }
    if (noInit == true) {
        return node675;
    }
    return node675;
}
//--------------------------------------------------------------------------------
// ConfirmPhase
//
REGISTER_REGISTER_SKILL_NODE(10041, 677) {
    pnode->resizeTrigger(PhaseNode_ConfirmPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_ConfirmPhase::TRIGGER_CONFIRM, 364, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(10041, 677) {
    auto node677 = GET_SKILL_NODE(677, PhaseNode_ConfirmPhase);
    if (node677 == nullptr) {
        node677 = new PhaseNode_ConfirmPhase(677, phase);
        CALL_REGISTER_SKILL_NODE(10041, 677, node677)
    }
    if (noInit == true) {
        return node677;
    }
    return node677;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10041, 680) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_OffsetCalculate>(PhaseNode_Detect::TRIGGER_ON, 85, PhaseNode_OffsetCalculate::FUNC_DO, &PhaseNode_OffsetCalculate::Do);
}

REGISTER_CREATE_SKILL_NODE(10041, 680) {
    auto node680 = GET_SKILL_NODE(680, PhaseNode_Detect);
    if (node680 == nullptr) {
        node680 = new PhaseNode_Detect(680, phase);
        node680->setSelf(0U);
        node680->setEvent("hudunPos");
        node680->setType(PhaseNode_Detect::Detect_Type::Actor_POS);
        node680->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10041, 680, node680)
    }
    if (noInit == true) {
        return node680;
    }
    return node680;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10041, 682) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuff>(PhaseNode_Detect::TRIGGER_ON, 594, PhaseNode_AddSkillBuff::FUNC_ADD, &PhaseNode_AddSkillBuff::Add);
}

REGISTER_CREATE_SKILL_NODE(10041, 682) {
    auto node682 = GET_SKILL_NODE(682, PhaseNode_Detect);
    if (node682 == nullptr) {
        node682 = new PhaseNode_Detect(682, phase);
        node682->setEvent("hudunDead");
        node682->setType(PhaseNode_Detect::Detect_Type::Actor_Dead);
        node682->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10041, 682, node682)
    }
    if (noInit == true) {
        return node682;
    }
    auto variables = node682->getVariables();
    if (variables != nullptr) {
        node682->setSelf(variables->getVariable<uint64_t>(Variable_10041_hudun));
    }
    return node682;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10041, 684) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_RaiseEvent::TRIGGER_DONE, 687, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10041, 684) {
    auto node684 = GET_SKILL_NODE(684, PhaseNode_RaiseEvent);
    if (node684 == nullptr) {
        node684 = new PhaseNode_RaiseEvent(684, phase);
        node684->setEvent("hudunDead");
        node684->setTarget(0U);
        node684->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node684->setTypeParams(0, 0);
        node684->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10041, 684, node684)
    }
    if (noInit == true) {
        return node684;
    }
    return node684;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10041, 687) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_RaiseEvent::TRIGGER_DONE, 689, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10041, 687) {
    auto node687 = GET_SKILL_NODE(687, PhaseNode_RaiseEvent);
    if (node687 == nullptr) {
        node687 = new PhaseNode_RaiseEvent(687, phase);
        node687->setEvent("hudunPos");
        node687->setTarget(0U);
        node687->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node687->setTypeParams(0, 0);
        node687->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10041, 687, node687)
    }
    if (noInit == true) {
        return node687;
    }
    return node687;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10041, 689) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndFlow>(PhaseNode_RaiseEvent::TRIGGER_DONE, 80, PhaseNode_EndFlow::FUNC_DO, &PhaseNode_EndFlow::Do);
}

REGISTER_CREATE_SKILL_NODE(10041, 689) {
    auto node689 = GET_SKILL_NODE(689, PhaseNode_RaiseEvent);
    if (node689 == nullptr) {
        node689 = new PhaseNode_RaiseEvent(689, phase);
        node689->setEvent("hudunDamage");
        node689->setTarget(0U);
        node689->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node689->setTypeParams(0, 0);
        node689->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10041, 689, node689)
    }
    if (noInit == true) {
        return node689;
    }
    return node689;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10041, 691) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CostBuffAttribute>(PhaseNode_Detect::TRIGGER_ON, 142, PhaseNode_CostBuffAttribute::FUNC_DO, &PhaseNode_CostBuffAttribute::Do);
}

REGISTER_CREATE_SKILL_NODE(10041, 691) {
    auto node691 = GET_SKILL_NODE(691, PhaseNode_Detect);
    if (node691 == nullptr) {
        node691 = new PhaseNode_Detect(691, phase);
        node691->setEvent("hudunDamage");
        node691->setType(PhaseNode_Detect::Detect_Type::Damage);
        node691->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10041, 691, node691)
    }
    if (noInit == true) {
        return node691;
    }
    auto variables = node691->getVariables();
    if (variables != nullptr) {
        node691->setSelf(variables->getVariable<uint64_t>(Variable_10041_hudun));
    }
    return node691;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10041, 693) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_PlaySound::TRIGGER_DONE, 20, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10041, 693) {
    auto node693 = GET_SKILL_NODE(693, PhaseNode_PlaySound);
    if (node693 == nullptr) {
        node693 = new PhaseNode_PlaySound(693, phase);
        node693->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node693->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node693->setSoundID("SE_Hero101_Skill_A_P2");
        node693->setTarget(0U);
        node693->setUsePos(false);
        node693->setPosX(.00f);
        node693->setPosY(.00f);
        node693->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10041, 693, node693)
    }
    if (noInit == true) {
        return node693;
    }
    return node693;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10041, 695) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_IsInterruptType>(PhaseNode_Detect::TRIGGER_ON, 701, PhaseNode_IsInterruptType::FUNC_DO, &PhaseNode_IsInterruptType::Do);
}

REGISTER_CREATE_SKILL_NODE(10041, 695) {
    auto node695 = GET_SKILL_NODE(695, PhaseNode_Detect);
    if (node695 == nullptr) {
        node695 = new PhaseNode_Detect(695, phase);
        node695->setSelf(0U);
        node695->setEvent("daduan_001");
        node695->setType(PhaseNode_Detect::Detect_Type::Interrupt_Skill);
        node695->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10041, 695, node695)
    }
    if (noInit == true) {
        return node695;
    }
    return node695;
}
//--------------------------------------------------------------------------------
// SwitchToInt
//
REGISTER_REGISTER_SKILL_NODE(10041, 696) {
    pnode->resizeTrigger(4);
    pnode->regTrigger<PhaseNode_SetBool>(1, 650, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
    pnode->regTrigger<PhaseNode_SetBool>(2, 650, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(10041, 696) {
    auto node696 = GET_SKILL_NODE(696, PhaseNode_SwitchToInt);
    if (node696 == nullptr) {
        node696 = new PhaseNode_SwitchToInt(696, phase);
        CALL_REGISTER_SKILL_NODE(10041, 696, node696)
    }
    if (noInit == true) {
        return node696;
    }
    auto variables = node696->getVariables();
    if (variables != nullptr) {
        node696->setSelection(variables->getVariable<int32_t>(Variable_10041_a100412));
    }
    return node696;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10041, 698) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_RaiseEvent::TRIGGER_DONE, 707, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10041, 698) {
    auto node698 = GET_SKILL_NODE(698, PhaseNode_RaiseEvent);
    if (node698 == nullptr) {
        node698 = new PhaseNode_RaiseEvent(698, phase);
        node698->setEvent("daduan_001");
        node698->setTarget(0U);
        node698->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node698->setTypeParams(0, 0);
        node698->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10041, 698, node698)
    }
    if (noInit == true) {
        return node698;
    }
    return node698;
}
//--------------------------------------------------------------------------------
// StartPreInput
//
REGISTER_REGISTER_SKILL_NODE(10041, 699) {
    pnode->resizeTrigger(PhaseNode_StartPreInput::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_StartPreInput::TRIGGER_DONE, 703, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10041, 699) {
    auto node699 = GET_SKILL_NODE(699, PhaseNode_StartPreInput);
    if (node699 == nullptr) {
        node699 = new PhaseNode_StartPreInput(699, phase);
        node699->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node699->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node699->setDelayTime(.00f);
        CALL_REGISTER_SKILL_NODE(10041, 699, node699)
    }
    if (noInit == true) {
        return node699;
    }
    return node699;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(10041, 700) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_If::TRIGGER_TRUE, 702, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10041, 700) {
    auto node700 = GET_SKILL_NODE(700, PhaseNode_If);
    if (node700 == nullptr) {
        node700 = new PhaseNode_If(700, phase);
        CALL_REGISTER_SKILL_NODE(10041, 700, node700)
    }
    if (noInit == true) {
        return node700;
    }
    auto variables = node700->getVariables();
    if (variables != nullptr) {
        node700->setCondition(variables->getVariable<bool>(Variable_10041_InterruptAnimat));
    }
    return node700;
}
//--------------------------------------------------------------------------------
// IsInterruptType
//
REGISTER_REGISTER_SKILL_NODE(10041, 701) {
    pnode->resizeTrigger(PhaseNode_IsInterruptType::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SwitchToInt>(PhaseNode_IsInterruptType::TRIGGER_BUFF, 696, PhaseNode_SwitchToInt::FUNC_SWITCH, &PhaseNode_SwitchToInt::Switch);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_POSCHANGE, 700, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTAIM, 700, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTFIRE, 700, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTRELOAD, 700, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_USESKILL, 700, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(10041, 701) {
    auto node701 = GET_SKILL_NODE(701, PhaseNode_IsInterruptType);
    if (node701 == nullptr) {
        node701 = new PhaseNode_IsInterruptType(701, phase);
        node701->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node701->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10041, 701, node701)
    }
    if (noInit == true) {
        return node701;
    }
    auto node695 = GET_SKILL_NODE(695, PhaseNode_Detect);
    if (node695 != nullptr) node701->setType(node695->getVars().getVariable<int32_t>(2));
    return node701;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10041, 702) {
}

REGISTER_CREATE_SKILL_NODE(10041, 702) {
    auto node702 = GET_SKILL_NODE(702, PhaseNode_PlayAnimation);
    if (node702 == nullptr) {
        node702 = new PhaseNode_PlayAnimation(702, phase);
        node702->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node702->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node702->setTarget(0U);
        node702->setAnimation("Idle");
        node702->setParameter("");
        node702->setValue(false);
        CALL_REGISTER_SKILL_NODE(10041, 702, node702)
    }
    if (noInit == true) {
        return node702;
    }
    return node702;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10041, 703) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_Delay::TRIGGER_DONE, 706, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(10041, 703) {
    auto node703 = GET_SKILL_NODE(703, PhaseNode_Delay);
    if (node703 == nullptr) {
        node703 = new PhaseNode_Delay(703, phase);
        node703->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(10041, 703, node703)
    }
    if (noInit == true) {
        return node703;
    }
    return node703;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(10041, 706) {
}

REGISTER_CREATE_SKILL_NODE(10041, 706) {
    auto node706 = GET_SKILL_NODE(706, PhaseNode_SetBool);
    if (node706 == nullptr) {
        node706 = new PhaseNode_SetBool(706, phase);
        node706->setName("InterruptAnimat");
        node706->setValue(true);
        CALL_REGISTER_SKILL_NODE(10041, 706, node706)
    }
    if (noInit == true) {
        return node706;
    }
    return node706;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10041, 707) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StartPreInput>(PhaseNode_RaiseEvent::TRIGGER_DONE, 699, PhaseNode_StartPreInput::FUNC_DO, &PhaseNode_StartPreInput::Do);
}

REGISTER_CREATE_SKILL_NODE(10041, 707) {
    auto node707 = GET_SKILL_NODE(707, PhaseNode_RaiseEvent);
    if (node707 == nullptr) {
        node707 = new PhaseNode_RaiseEvent(707, phase);
        node707->setEvent("Dead_001");
        node707->setTarget(0U);
        node707->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node707->setTypeParams(0, 0);
        node707->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10041, 707, node707)
    }
    if (noInit == true) {
        return node707;
    }
    return node707;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10041, 708) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_Detect::TRIGGER_ON, 664, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(10041, 708) {
    auto node708 = GET_SKILL_NODE(708, PhaseNode_Detect);
    if (node708 == nullptr) {
        node708 = new PhaseNode_Detect(708, phase);
        node708->setSelf(0U);
        node708->setEvent("Dead_001");
        node708->setType(PhaseNode_Detect::Detect_Type::Actor_Dead);
        node708->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10041, 708, node708)
    }
    if (noInit == true) {
        return node708;
    }
    return node708;
}

//--------------------------------------------------------------------------------
// SkillCreator_10041
//
class SkillCreator_10041 : public SkillCreator {
public:
    SkillCreator_10041() {}
    virtual ~SkillCreator_10041() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_10041

//--------------------------------------------------------------------------------
// SkillPhase_10041
//
class SkillPhase_10041 : public SkillPhase {
public:
    SkillPhase_10041(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_10041() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(10041, 2) // StartPhase
        CASE_CREATE_SKILL_NODE(10041, 3) // GetLocation
        CASE_CREATE_SKILL_NODE(10041, 4) // GetRotation
        CASE_CREATE_SKILL_NODE(10041, 6) // SpawnActor
        CASE_CREATE_SKILL_NODE(10041, 7) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10041, 8) // EndPhase
        CASE_CREATE_SKILL_NODE(10041, 14) // SetUInt64
        CASE_CREATE_SKILL_NODE(10041, 17) // DestroyActor
        CASE_CREATE_SKILL_NODE(10041, 18) // OffsetCalculate
        CASE_CREATE_SKILL_NODE(10041, 19) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10041, 20) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10041, 53) // RemoveSkillBuff
        CASE_CREATE_SKILL_NODE(10041, 80) // EndFlow
        CASE_CREATE_SKILL_NODE(10041, 85) // OffsetCalculate
        CASE_CREATE_SKILL_NODE(10041, 86) // SetLocation
        CASE_CREATE_SKILL_NODE(10041, 87) // SetRotation
        CASE_CREATE_SKILL_NODE(10041, 88) // GetBuffAttribute
        CASE_CREATE_SKILL_NODE(10041, 89) // SetBuffAttribute
        CASE_CREATE_SKILL_NODE(10041, 142) // CostBuffAttribute
        CASE_CREATE_SKILL_NODE(10041, 207) // RemoveSkillBuff
        CASE_CREATE_SKILL_NODE(10041, 364) // SetBool
        CASE_CREATE_SKILL_NODE(10041, 366) // If
        CASE_CREATE_SKILL_NODE(10041, 369) // ResetCD
        CASE_CREATE_SKILL_NODE(10041, 569) // PlaySound
        CASE_CREATE_SKILL_NODE(10041, 573) // PlaySound
        CASE_CREATE_SKILL_NODE(10041, 594) // AddSkillBuff
        CASE_CREATE_SKILL_NODE(10041, 596) // AddSkillBuff
        CASE_CREATE_SKILL_NODE(10041, 638) // SetBool
        CASE_CREATE_SKILL_NODE(10041, 640) // If
        CASE_CREATE_SKILL_NODE(10041, 645) // SetInt
        CASE_CREATE_SKILL_NODE(10041, 650) // SetBool
        CASE_CREATE_SKILL_NODE(10041, 652) // AddSkillBuff
        CASE_CREATE_SKILL_NODE(10041, 658) // PlaySound
        CASE_CREATE_SKILL_NODE(10041, 664) // SetBool
        CASE_CREATE_SKILL_NODE(10041, 667) // If
        CASE_CREATE_SKILL_NODE(10041, 672) // Disable
        CASE_CREATE_SKILL_NODE(10041, 675) // Delay
        CASE_CREATE_SKILL_NODE(10041, 677) // ConfirmPhase
        CASE_CREATE_SKILL_NODE(10041, 680) // Detect
        CASE_CREATE_SKILL_NODE(10041, 682) // Detect
        CASE_CREATE_SKILL_NODE(10041, 684) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10041, 687) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10041, 689) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10041, 691) // Detect
        CASE_CREATE_SKILL_NODE(10041, 693) // PlaySound
        CASE_CREATE_SKILL_NODE(10041, 695) // Detect
        CASE_CREATE_SKILL_NODE(10041, 696) // SwitchToInt
        CASE_CREATE_SKILL_NODE(10041, 698) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10041, 699) // StartPreInput
        CASE_CREATE_SKILL_NODE(10041, 700) // If
        CASE_CREATE_SKILL_NODE(10041, 701) // IsInterruptType
        CASE_CREATE_SKILL_NODE(10041, 702) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10041, 703) // Delay
        CASE_CREATE_SKILL_NODE(10041, 706) // SetBool
        CASE_CREATE_SKILL_NODE(10041, 707) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10041, 708) // Detect
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_10041

SkillLogic* SkillCreator_10041::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //设置变量
    Variable_10041_hudunCancle = logic->getVariables().setVariable<bool>("hudunCancle");
    Variable_10041_hudun = logic->getVariables().setVariable<uint64_t>("hudun", 0U);
    Variable_10041_a100411 = logic->getVariables().setVariable<bool>("a100411");
    Variable_10041_renwudead = logic->getVariables().setVariable<bool>("renwudead");
    Variable_10041_a100412 = logic->getVariables().setVariable<int32_t>("a100412", 1);
    Variable_10041_InterruptAnimat = logic->getVariables().setVariable<bool>("InterruptAnimat");
    //创建阶段phase
    auto phase = new SkillPhase_10041(1, logic, 3);
    //设置phase执行器
    phase->setRunPhaseNode(1, 2);
    phase->addConfirmPhaseNode(2, 677);
    phase->setDetectPhaseNode(3, 680);
    phase->setDetectPhaseNode(3, 682);
    phase->setDetectPhaseNode(3, 691);
    phase->setDetectPhaseNode(3, 695);
    phase->setDetectPhaseNode(3, 708);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_10041::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
