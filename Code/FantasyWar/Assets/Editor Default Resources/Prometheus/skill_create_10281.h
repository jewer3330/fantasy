#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

#include "skill_psnode_actorfilternewpene.h"
#include "skill_psnode_addskillbuff.h"
#include "skill_psnode_attachto.h"
#include "skill_psnode_cameraxyzshake.h"
#include "skill_psnode_cancelphase.h"
#include "skill_psnode_comparefloat.h"
#include "skill_psnode_confirmphase.h"
#include "skill_psnode_createtriggernewpene.h"
#include "skill_psnode_delay.h"
#include "skill_psnode_destroycollider.h"
#include "skill_psnode_detect.h"
#include "skill_psnode_disable.h"
#include "skill_psnode_distance.h"
#include "skill_psnode_endphase.h"
#include "skill_psnode_floatoperation.h"
#include "skill_psnode_getactorattribute.h"
#include "skill_psnode_getinputrotation.h"
#include "skill_psnode_getlocation.h"
#include "skill_psnode_getuint64svalue.h"
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
#include "skill_psnode_setuint64.h"
#include "skill_psnode_spawncollider.h"
#include "skill_psnode_startphase.h"
#include "skill_psnode_startpreinput.h"
#include "skill_psnode_stopeffect.h"
#include "skill_psnode_switchtoint.h"
#include "skill_psnode_triggercheck.h"
#include "skill_psnode_triggerupdate.h"

namespace pvp {

//变量声明
uint64_t Variable_10281_a102811 = 0;
uint64_t Variable_10281_a102812 = 0;
uint64_t Variable_10281_a102815 = 0;
uint64_t Variable_10281_InterruptAnimat = 0;
//--------------------------------------------------------------------------------
// StartPhase
//
REGISTER_REGISTER_SKILL_NODE(10281, 2) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Disable>(PhaseNode_StartPhase::TRIGGER_START, 439, PhaseNode_Disable::FUNC_DO, &PhaseNode_Disable::Do);
}

REGISTER_CREATE_SKILL_NODE(10281, 2) {
    auto node2 = GET_SKILL_NODE(2, PhaseNode_StartPhase);
    if (node2 == nullptr) {
        node2 = new PhaseNode_StartPhase(2, phase);
        CALL_REGISTER_SKILL_NODE(10281, 2, node2)
    }
    if (noInit == true) {
        return node2;
    }
    return node2;
}
//--------------------------------------------------------------------------------
// TriggerUpdate
//
REGISTER_REGISTER_SKILL_NODE(10281, 4) {
}

REGISTER_CREATE_SKILL_NODE(10281, 4) {
    auto node4 = GET_SKILL_NODE(4, PhaseNode_TriggerUpdate);
    if (node4 == nullptr) {
        node4 = new PhaseNode_TriggerUpdate(4, phase);
        CALL_REGISTER_SKILL_NODE(10281, 4, node4)
    }
    if (noInit == true) {
        return node4;
    }
    return node4;
}
//--------------------------------------------------------------------------------
// OffsetCalculate
//
REGISTER_REGISTER_SKILL_NODE(10281, 22) {
    pnode->resizeTrigger(PhaseNode_OffsetCalculate::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnCollider>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 24, PhaseNode_SpawnCollider::FUNC_DO, &PhaseNode_SpawnCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(10281, 22) {
    auto node22 = GET_SKILL_NODE(22, PhaseNode_OffsetCalculate);
    if (node22 == nullptr) {
        node22 = new PhaseNode_OffsetCalculate(22, phase);
        node22->setPosZ(.00f);
        node22->setOffsetX(.10f);
        node22->setOffsetY(.30f);
        node22->setOffsetZ(.00f);
        node22->setRotOffset(.00f);
        CALL_REGISTER_SKILL_NODE(10281, 22, node22)
    }
    if (noInit == true) {
        return node22;
    }
    auto node429 = GET_SKILL_NODE(429, PhaseNode_GetLocation);
    auto node431 = GET_SKILL_NODE(431, PhaseNode_GetInputRotation);
    if (node429 != nullptr) node22->setPosX(node429->getX());
    if (node429 != nullptr) node22->setPosY(node429->getY());
    if (node431 != nullptr) node22->setRotation(node431->getAngle());
    return node22;
}
//--------------------------------------------------------------------------------
// SpawnCollider
//
REGISTER_REGISTER_SKILL_NODE(10281, 24) {
    pnode->resizeTrigger(PhaseNode_SpawnCollider::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_SpawnCollider::TRIGGER_DONE, 109, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
    pnode->regTrigger<PhaseNode_SpawnCollider>(PhaseNode_SpawnCollider::TRIGGER_DONE, 418, PhaseNode_SpawnCollider::FUNC_DO, &PhaseNode_SpawnCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(10281, 24) {
    auto node24 = GET_SKILL_NODE(24, PhaseNode_SpawnCollider);
    if (node24 == nullptr) {
        node24 = new PhaseNode_SpawnCollider(24, phase);
        node24->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node24->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node24->setMesh("");
        node24->setMeshScale(.00f);
        node24->setEffectID(102811);
        node24->setEffectScale(1.00f);
        node24->setType(PhaseNode_SpawnCollider::SpawnCollider_Type::Circle);
        node24->setTypeParams(0, .30f);
        node24->setTime(.60f);
        node24->setreentry(false);
        node24->setCheckPeneSound(false);
        CALL_REGISTER_SKILL_NODE(10281, 24, node24)
    }
    if (noInit == true) {
        return node24;
    }
    auto node22 = GET_SKILL_NODE(22, PhaseNode_OffsetCalculate);
    if (node22 != nullptr) node24->setPosX(node22->getOutPosX());
    if (node22 != nullptr) node24->setPosY(node22->getOutPosY());
    if (node22 != nullptr) node24->setPosZ(node22->getOutPosZ());
    if (node22 != nullptr) node24->setRotation(node22->getOutRotation());
    return node24;
}
//--------------------------------------------------------------------------------
// GetUInt64sValue
//
REGISTER_REGISTER_SKILL_NODE(10281, 36) {
    pnode->resizeTrigger(PhaseNode_GetUInt64sValue::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetUInt64>(PhaseNode_GetUInt64sValue::TRIGGER_DONE, 54, PhaseNode_SetUInt64::FUNC_SET, &PhaseNode_SetUInt64::Set);
}

REGISTER_CREATE_SKILL_NODE(10281, 36) {
    auto node36 = GET_SKILL_NODE(36, PhaseNode_GetUInt64sValue);
    if (node36 == nullptr) {
        node36 = new PhaseNode_GetUInt64sValue(36, phase);
        node36->setIndex(0);
        CALL_REGISTER_SKILL_NODE(10281, 36, node36)
    }
    if (noInit == true) {
        return node36;
    }
    auto node477 = GET_SKILL_NODE(477, PhaseNode_ActorFilterNewPene);
    if (node477 != nullptr) node36->setArr(node477->getOutput());
    return node36;
}
//--------------------------------------------------------------------------------
// SetUInt64
//
REGISTER_REGISTER_SKILL_NODE(10281, 54) {
    pnode->resizeTrigger(PhaseNode_SetUInt64::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuff>(PhaseNode_SetUInt64::TRIGGER_DONE, 163, PhaseNode_AddSkillBuff::FUNC_ADD, &PhaseNode_AddSkillBuff::Add);
}

REGISTER_CREATE_SKILL_NODE(10281, 54) {
    auto node54 = GET_SKILL_NODE(54, PhaseNode_SetUInt64);
    if (node54 == nullptr) {
        node54 = new PhaseNode_SetUInt64(54, phase);
        node54->setName("a102811");
        CALL_REGISTER_SKILL_NODE(10281, 54, node54)
    }
    if (noInit == true) {
        return node54;
    }
    auto node36 = GET_SKILL_NODE(36, PhaseNode_GetUInt64sValue);
    if (node36 != nullptr) node54->setValue(node36->getValue());
    return node54;
}
//--------------------------------------------------------------------------------
// SpawnCollider
//
REGISTER_REGISTER_SKILL_NODE(10281, 66) {
    pnode->resizeTrigger(PhaseNode_SpawnCollider::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_MoveNewPene>(PhaseNode_SpawnCollider::TRIGGER_DONE, 372, PhaseNode_MoveNewPene::FUNC_DO, &PhaseNode_MoveNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(10281, 66) {
    auto node66 = GET_SKILL_NODE(66, PhaseNode_SpawnCollider);
    if (node66 == nullptr) {
        node66 = new PhaseNode_SpawnCollider(66, phase);
        node66->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node66->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node66->setMesh("");
        node66->setMeshScale(.00f);
        node66->setEffectID(102811);
        node66->setEffectScale(1.00f);
        node66->setType(PhaseNode_SpawnCollider::SpawnCollider_Type::Circle);
        node66->setTypeParams(0, .30f);
        node66->setTime(.40f);
        node66->setPosZ(.00f);
        node66->setreentry(false);
        node66->setCheckPeneSound(false);
        CALL_REGISTER_SKILL_NODE(10281, 66, node66)
    }
    if (noInit == true) {
        return node66;
    }
    auto node370 = GET_SKILL_NODE(370, PhaseNode_GetLocation);
    auto node431 = GET_SKILL_NODE(431, PhaseNode_GetInputRotation);
    if (node370 != nullptr) node66->setPosX(node370->getX());
    if (node370 != nullptr) node66->setPosY(node370->getY());
    if (node431 != nullptr) node66->setRotation(node431->getAngle());
    return node66;
}
//--------------------------------------------------------------------------------
// DestroyCollider
//
REGISTER_REGISTER_SKILL_NODE(10281, 68) {
    pnode->resizeTrigger(PhaseNode_DestroyCollider::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_DestroyCollider::TRIGGER_DONE, 358, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(10281, 68) {
    auto node68 = GET_SKILL_NODE(68, PhaseNode_DestroyCollider);
    if (node68 == nullptr) {
        node68 = new PhaseNode_DestroyCollider(68, phase);
        CALL_REGISTER_SKILL_NODE(10281, 68, node68)
    }
    if (noInit == true) {
        return node68;
    }
    auto node24 = GET_SKILL_NODE(24, PhaseNode_SpawnCollider);
    if (node24 != nullptr) node68->setColliderID(node24->getColliderID());
    return node68;
}
//--------------------------------------------------------------------------------
// Distance
//
REGISTER_REGISTER_SKILL_NODE(10281, 82) {
    pnode->resizeTrigger(PhaseNode_Distance::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_FloatOperation>(PhaseNode_Distance::TRIGGER_DONE, 467, PhaseNode_FloatOperation::FUNC_OPERATION, &PhaseNode_FloatOperation::Operation);
}

REGISTER_CREATE_SKILL_NODE(10281, 82) {
    auto node82 = GET_SKILL_NODE(82, PhaseNode_Distance);
    if (node82 == nullptr) {
        node82 = new PhaseNode_Distance(82, phase);
        CALL_REGISTER_SKILL_NODE(10281, 82, node82)
    }
    if (noInit == true) {
        return node82;
    }
    auto node429 = GET_SKILL_NODE(429, PhaseNode_GetLocation);
    auto node363 = GET_SKILL_NODE(363, PhaseNode_GetLocation);
    if (node429 != nullptr) node82->setAX(node429->getX());
    if (node429 != nullptr) node82->setAY(node429->getY());
    if (node363 != nullptr) node82->setBX(node363->getX());
    if (node363 != nullptr) node82->setBY(node363->getY());
    return node82;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10281, 109) {
}

REGISTER_CREATE_SKILL_NODE(10281, 109) {
    auto node109 = GET_SKILL_NODE(109, PhaseNode_PlayAnimation);
    if (node109 == nullptr) {
        node109 = new PhaseNode_PlayAnimation(109, phase);
        node109->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node109->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node109->setTarget(0U);
        node109->setAnimation("Skill1S2");
        node109->setParameter("");
        node109->setValue(false);
        CALL_REGISTER_SKILL_NODE(10281, 109, node109)
    }
    if (noInit == true) {
        return node109;
    }
    return node109;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10281, 112) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_PlayAnimation::TRIGGER_DONE, 403, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10281, 112) {
    auto node112 = GET_SKILL_NODE(112, PhaseNode_PlayAnimation);
    if (node112 == nullptr) {
        node112 = new PhaseNode_PlayAnimation(112, phase);
        node112->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node112->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node112->setTarget(0U);
        node112->setAnimation("Skill1S3");
        node112->setParameter("SkillArmBusy");
        node112->setValue(true);
        CALL_REGISTER_SKILL_NODE(10281, 112, node112)
    }
    if (noInit == true) {
        return node112;
    }
    return node112;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10281, 115) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_Delay::TRIGGER_DONE, 117, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(10281, 115) {
    auto node115 = GET_SKILL_NODE(115, PhaseNode_Delay);
    if (node115 == nullptr) {
        node115 = new PhaseNode_Delay(115, phase);
        node115->setTime(.15f);
        CALL_REGISTER_SKILL_NODE(10281, 115, node115)
    }
    if (noInit == true) {
        return node115;
    }
    return node115;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(10281, 117) {
}

REGISTER_CREATE_SKILL_NODE(10281, 117) {
    auto node117 = GET_SKILL_NODE(117, PhaseNode_EndPhase);
    if (node117 == nullptr) {
        node117 = new PhaseNode_EndPhase(117, phase);
        node117->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node117->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10281, 117, node117)
    }
    if (noInit == true) {
        return node117;
    }
    return node117;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(10281, 126) {
    pnode->resizeTrigger(PhaseNode_SetBool::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_MoveNewPene>(PhaseNode_SetBool::TRIGGER_DONE, 282, PhaseNode_MoveNewPene::FUNC_STOP, &PhaseNode_MoveNewPene::Stop);
}

REGISTER_CREATE_SKILL_NODE(10281, 126) {
    auto node126 = GET_SKILL_NODE(126, PhaseNode_SetBool);
    if (node126 == nullptr) {
        node126 = new PhaseNode_SetBool(126, phase);
        node126->setName("a102812");
        node126->setValue(true);
        CALL_REGISTER_SKILL_NODE(10281, 126, node126)
    }
    if (noInit == true) {
        return node126;
    }
    return node126;
}
//--------------------------------------------------------------------------------
// DestroyCollider
//
REGISTER_REGISTER_SKILL_NODE(10281, 157) {
    pnode->resizeTrigger(PhaseNode_DestroyCollider::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuff>(PhaseNode_DestroyCollider::TRIGGER_DONE, 219, PhaseNode_AddSkillBuff::FUNC_ADD, &PhaseNode_AddSkillBuff::Add);
}

REGISTER_CREATE_SKILL_NODE(10281, 157) {
    auto node157 = GET_SKILL_NODE(157, PhaseNode_DestroyCollider);
    if (node157 == nullptr) {
        node157 = new PhaseNode_DestroyCollider(157, phase);
        CALL_REGISTER_SKILL_NODE(10281, 157, node157)
    }
    if (noInit == true) {
        return node157;
    }
    auto node374 = GET_SKILL_NODE(374, PhaseNode_SpawnCollider);
    if (node374 != nullptr) node157->setColliderID(node374->getColliderID());
    return node157;
}
//--------------------------------------------------------------------------------
// AddSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10281, 163) {
    pnode->resizeTrigger(PhaseNode_AddSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuff>(PhaseNode_AddSkillBuff::TRIGGER_DONE, 217, PhaseNode_AddSkillBuff::FUNC_ADD, &PhaseNode_AddSkillBuff::Add);
}

REGISTER_CREATE_SKILL_NODE(10281, 163) {
    auto node163 = GET_SKILL_NODE(163, PhaseNode_AddSkillBuff);
    if (node163 == nullptr) {
        node163 = new PhaseNode_AddSkillBuff(163, phase);
        node163->setConfigID(102811);
        node163->setConfigIDs({});
        node163->setAttribute({{}});
        CALL_REGISTER_SKILL_NODE(10281, 163, node163)
    }
    if (noInit == true) {
        return node163;
    }
    auto node36 = GET_SKILL_NODE(36, PhaseNode_GetUInt64sValue);
    if (node36 != nullptr) node163->setTarget(node36->getValue());
    return node163;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10281, 180) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_OffsetCalculate>(PhaseNode_Delay::TRIGGER_DONE, 22, PhaseNode_OffsetCalculate::FUNC_DO, &PhaseNode_OffsetCalculate::Do);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_Delay::TRIGGER_DONE, 276, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(10281, 180) {
    auto node180 = GET_SKILL_NODE(180, PhaseNode_Delay);
    if (node180 == nullptr) {
        node180 = new PhaseNode_Delay(180, phase);
        node180->setTime(.07f);
        CALL_REGISTER_SKILL_NODE(10281, 180, node180)
    }
    if (noInit == true) {
        return node180;
    }
    return node180;
}
//--------------------------------------------------------------------------------
// AddSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10281, 217) {
    pnode->resizeTrigger(PhaseNode_AddSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_AddSkillBuff::TRIGGER_DONE, 126, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(10281, 217) {
    auto node217 = GET_SKILL_NODE(217, PhaseNode_AddSkillBuff);
    if (node217 == nullptr) {
        node217 = new PhaseNode_AddSkillBuff(217, phase);
        node217->setConfigID(102812);
        node217->setConfigIDs({});
        CALL_REGISTER_SKILL_NODE(10281, 217, node217)
    }
    if (noInit == true) {
        return node217;
    }
    auto node36 = GET_SKILL_NODE(36, PhaseNode_GetUInt64sValue);
    auto node481 = GET_SKILL_NODE(481, PhaseNode_GetActorAttribute);
    if (node36 != nullptr) node217->setTarget(node36->getValue());
    if (node481 != nullptr) node217->setAttribute(node481->getAttribute());
    return node217;
}
//--------------------------------------------------------------------------------
// AddSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10281, 219) {
}

REGISTER_CREATE_SKILL_NODE(10281, 219) {
    auto node219 = GET_SKILL_NODE(219, PhaseNode_AddSkillBuff);
    if (node219 == nullptr) {
        node219 = new PhaseNode_AddSkillBuff(219, phase);
        node219->setConfigID(102813);
        node219->setConfigIDs({});
        CALL_REGISTER_SKILL_NODE(10281, 219, node219)
    }
    if (noInit == true) {
        return node219;
    }
    auto variables = node219->getVariables();
    if (variables != nullptr) {
        node219->setTarget(variables->getVariable<uint64_t>(Variable_10281_a102811));
    }
    auto node481 = GET_SKILL_NODE(481, PhaseNode_GetActorAttribute);
    if (node481 != nullptr) node219->setAttribute(node481->getAttribute());
    return node219;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(10281, 276) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_PlayEffect::TRIGGER_DONE, 313, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10281, 276) {
    auto node276 = GET_SKILL_NODE(276, PhaseNode_PlayEffect);
    if (node276 == nullptr) {
        node276 = new PhaseNode_PlayEffect(276, phase);
        node276->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node276->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node276->setEffectID(102812);
        node276->setChangeColor(false);
        node276->setType(PhaseNode_PlayEffect::PlayEffect_Type::WithTarget);
        node276->getVars().reserve(5);
        node276->getVars().setVariable<uint64_t>(0, 0U);
        node276->getVars().setVariable<std::string>(1, "Bip001 R Hand");
        node276->getVars().setVariable<float>(2, .00f);
        node276->getVars().setVariable<float>(3, .00f);
        node276->getVars().setVariable<float>(4, .00f);
        node276->setRotation(.00f);
        node276->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(10281, 276, node276)
    }
    if (noInit == true) {
        return node276;
    }
    return node276;
}
//--------------------------------------------------------------------------------
// MoveNewPene
//
REGISTER_REGISTER_SKILL_NODE(10281, 282) {
    pnode->resizeTrigger(PhaseNode_MoveNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuff>(PhaseNode_MoveNewPene::TRIGGER_BLOCKBYSHIELD, 408, PhaseNode_AddSkillBuff::FUNC_ADD, &PhaseNode_AddSkillBuff::Add);
    pnode->regTrigger<PhaseNode_DestroyCollider>(PhaseNode_MoveNewPene::TRIGGER_BLOCKBYSHIELD, 423, PhaseNode_DestroyCollider::FUNC_DO, &PhaseNode_DestroyCollider::Do);
    pnode->regTrigger<PhaseNode_DestroyCollider>(PhaseNode_MoveNewPene::TRIGGER_BLOCKBYWALL, 423, PhaseNode_DestroyCollider::FUNC_DO, &PhaseNode_DestroyCollider::Do);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_MoveNewPene::TRIGGER_BLOCKBYWALL, 325, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_MoveNewPene::TRIGGER_DONE, 425, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10281, 282) {
    auto node282 = GET_SKILL_NODE(282, PhaseNode_MoveNewPene);
    if (node282 == nullptr) {
        node282 = new PhaseNode_MoveNewPene(282, phase);
        node282->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node282->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node282->setPeneType(PhaseNode_MoveNewPene::MoveNewPene_PeneType::Projectile);
        node282->setPeneValue(15);
        node282->setType(PhaseNode_MoveNewPene::MoveNewPene_Type::Charge);
        node282->getVars().reserve(4);
        node282->getVars().setVariable<float>(0, 35.00f);
        node282->getVars().setVariable<float>(1, 14.00f);
        node282->getVars().setVariable<float>(2, .00f);
        node282->getVars().setVariable<float>(3, .00f);
        node282->setreentry(false);
        node282->setStopWhenFail(true);
        node282->setCheckFaction(PhaseNode_MoveNewPene::MoveNewPene_CheckFaction::Enemy);
        CALL_REGISTER_SKILL_NODE(10281, 282, node282)
    }
    if (noInit == true) {
        return node282;
    }
    auto node24 = GET_SKILL_NODE(24, PhaseNode_SpawnCollider);
    auto node431 = GET_SKILL_NODE(431, PhaseNode_GetInputRotation);
    if (node24 != nullptr) node282->setTarget(node24->getColliderID());
    if (node431 != nullptr) node282->getVars().setVariable<float>(2, node431->getAngle());
    return node282;
}
//--------------------------------------------------------------------------------
// MoveNewPene
//
REGISTER_REGISTER_SKILL_NODE(10281, 284) {
    pnode->resizeTrigger(PhaseNode_MoveNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_DestroyCollider>(PhaseNode_MoveNewPene::TRIGGER_DONE, 157, PhaseNode_DestroyCollider::FUNC_DO, &PhaseNode_DestroyCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(10281, 284) {
    auto node284 = GET_SKILL_NODE(284, PhaseNode_MoveNewPene);
    if (node284 == nullptr) {
        node284 = new PhaseNode_MoveNewPene(284, phase);
        node284->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node284->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node284->setPeneType(PhaseNode_MoveNewPene::MoveNewPene_PeneType::Move);
        node284->setPeneValue(35);
        node284->setType(PhaseNode_MoveNewPene::MoveNewPene_Type::Charge);
        node284->getVars().reserve(4);
        node284->getVars().setVariable<float>(0, 50.00f);
        node284->getVars().setVariable<float>(1, .00f);
        node284->getVars().setVariable<float>(2, .00f);
        node284->getVars().setVariable<float>(3, 180.00f);
        node284->setreentry(false);
        node284->setStopWhenFail(false);
        node284->setCheckFaction(PhaseNode_MoveNewPene::MoveNewPene_CheckFaction::Enemy);
        CALL_REGISTER_SKILL_NODE(10281, 284, node284)
    }
    if (noInit == true) {
        return node284;
    }
    auto node374 = GET_SKILL_NODE(374, PhaseNode_SpawnCollider);
    auto node467 = GET_SKILL_NODE(467, PhaseNode_FloatOperation);
    auto node431 = GET_SKILL_NODE(431, PhaseNode_GetInputRotation);
    if (node374 != nullptr) node284->setTarget(node374->getColliderID());
    if (node467 != nullptr) node284->getVars().setVariable<float>(1, node467->getFinal());
    if (node431 != nullptr) node284->getVars().setVariable<float>(2, node431->getAngle());
    return node284;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(10281, 300) {
}

REGISTER_CREATE_SKILL_NODE(10281, 300) {
    auto node300 = GET_SKILL_NODE(300, PhaseNode_PlayEffect);
    if (node300 == nullptr) {
        node300 = new PhaseNode_PlayEffect(300, phase);
        node300->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node300->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node300->setEffectID(102815);
        node300->setChangeColor(false);
        node300->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node300->getVars().reserve(3);
        node300->getVars().setVariable<float>(0, .00f);
        node300->getVars().setVariable<float>(1, .00f);
        node300->getVars().setVariable<float>(2, .00f);
        node300->setRotation(.00f);
        node300->setScale(.00f);
        CALL_REGISTER_SKILL_NODE(10281, 300, node300)
    }
    if (noInit == true) {
        return node300;
    }
    auto node303 = GET_SKILL_NODE(303, PhaseNode_OffsetCalculate);
    if (node303 != nullptr) node300->getVars().setVariable<float>(0, node303->getOutPosX());
    if (node303 != nullptr) node300->getVars().setVariable<float>(1, node303->getOutPosY());
    if (node303 != nullptr) node300->getVars().setVariable<float>(2, node303->getOutPosZ());
    return node300;
}
//--------------------------------------------------------------------------------
// OffsetCalculate
//
REGISTER_REGISTER_SKILL_NODE(10281, 303) {
    pnode->resizeTrigger(PhaseNode_OffsetCalculate::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 300, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(10281, 303) {
    auto node303 = GET_SKILL_NODE(303, PhaseNode_OffsetCalculate);
    if (node303 == nullptr) {
        node303 = new PhaseNode_OffsetCalculate(303, phase);
        node303->setPosZ(.00f);
        node303->setOffsetX(-.10f);
        node303->setOffsetY(1.20f);
        node303->setOffsetZ(2.00f);
        node303->setRotOffset(.00f);
        CALL_REGISTER_SKILL_NODE(10281, 303, node303)
    }
    if (noInit == true) {
        return node303;
    }
    auto node405 = GET_SKILL_NODE(405, PhaseNode_GetLocation);
    auto node431 = GET_SKILL_NODE(431, PhaseNode_GetInputRotation);
    if (node405 != nullptr) node303->setPosX(node405->getX());
    if (node405 != nullptr) node303->setPosY(node405->getY());
    if (node431 != nullptr) node303->setRotation(node431->getAngle());
    return node303;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10281, 313) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CameraXYZShake>(PhaseNode_PlaySound::TRIGGER_DONE, 410, PhaseNode_CameraXYZShake::FUNC_DO, &PhaseNode_CameraXYZShake::Do);
}

REGISTER_CREATE_SKILL_NODE(10281, 313) {
    auto node313 = GET_SKILL_NODE(313, PhaseNode_PlaySound);
    if (node313 == nullptr) {
        node313 = new PhaseNode_PlaySound(313, phase);
        node313->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node313->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node313->setSoundID("SE_Hero107_SkillA_P1");
        node313->setTarget(0U);
        node313->setUsePos(false);
        node313->setPosX(.00f);
        node313->setPosY(.00f);
        node313->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10281, 313, node313)
    }
    if (noInit == true) {
        return node313;
    }
    return node313;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10281, 325) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_PlaySound::TRIGGER_DONE, 405, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(10281, 325) {
    auto node325 = GET_SKILL_NODE(325, PhaseNode_PlaySound);
    if (node325 == nullptr) {
        node325 = new PhaseNode_PlaySound(325, phase);
        node325->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node325->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node325->setSoundID("SE_Hero107_SkillA_P3");
        node325->setTarget(0U);
        node325->setUsePos(false);
        node325->setPosX(.00f);
        node325->setPosY(.00f);
        node325->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10281, 325, node325)
    }
    if (noInit == true) {
        return node325;
    }
    return node325;
}
//--------------------------------------------------------------------------------
// SetInt
//
REGISTER_REGISTER_SKILL_NODE(10281, 337) {
    pnode->resizeTrigger(PhaseNode_SetInt::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Disable>(PhaseNode_SetInt::TRIGGER_DONE, 439, PhaseNode_Disable::FUNC_CANCLE, &PhaseNode_Disable::Cancle);
}

REGISTER_CREATE_SKILL_NODE(10281, 337) {
    auto node337 = GET_SKILL_NODE(337, PhaseNode_SetInt);
    if (node337 == nullptr) {
        node337 = new PhaseNode_SetInt(337, phase);
        node337->setName("a102815");
        node337->setValue(2);
        CALL_REGISTER_SKILL_NODE(10281, 337, node337)
    }
    if (noInit == true) {
        return node337;
    }
    return node337;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10281, 354) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Disable>(PhaseNode_Delay::TRIGGER_DONE, 427, PhaseNode_Disable::FUNC_CANCLE, &PhaseNode_Disable::Cancle);
}

REGISTER_CREATE_SKILL_NODE(10281, 354) {
    auto node354 = GET_SKILL_NODE(354, PhaseNode_Delay);
    if (node354 == nullptr) {
        node354 = new PhaseNode_Delay(354, phase);
        node354->setTime(.35f);
        CALL_REGISTER_SKILL_NODE(10281, 354, node354)
    }
    if (noInit == true) {
        return node354;
    }
    return node354;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(10281, 358) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Distance>(PhaseNode_If::TRIGGER_FALSE, 385, PhaseNode_Distance::FUNC_DO, &PhaseNode_Distance::Do);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_If::TRIGGER_TRUE, 363, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(10281, 358) {
    auto node358 = GET_SKILL_NODE(358, PhaseNode_If);
    if (node358 == nullptr) {
        node358 = new PhaseNode_If(358, phase);
        CALL_REGISTER_SKILL_NODE(10281, 358, node358)
    }
    if (noInit == true) {
        return node358;
    }
    auto variables = node358->getVariables();
    if (variables != nullptr) {
        node358->setCondition(variables->getVariable<bool>(Variable_10281_a102812));
    }
    return node358;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(10281, 363) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Distance>(PhaseNode_GetLocation::TRIGGER_DONE, 82, PhaseNode_Distance::FUNC_DO, &PhaseNode_Distance::Do);
}

REGISTER_CREATE_SKILL_NODE(10281, 363) {
    auto node363 = GET_SKILL_NODE(363, PhaseNode_GetLocation);
    if (node363 == nullptr) {
        node363 = new PhaseNode_GetLocation(363, phase);
        node363->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        CALL_REGISTER_SKILL_NODE(10281, 363, node363)
    }
    if (noInit == true) {
        return node363;
    }
    auto variables = node363->getVariables();
    if (variables != nullptr) {
        node363->setTarget(variables->getVariable<uint64_t>(Variable_10281_a102811));
    }
    return node363;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(10281, 370) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_DestroyCollider>(PhaseNode_GetLocation::TRIGGER_DONE, 68, PhaseNode_DestroyCollider::FUNC_DO, &PhaseNode_DestroyCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(10281, 370) {
    auto node370 = GET_SKILL_NODE(370, PhaseNode_GetLocation);
    if (node370 == nullptr) {
        node370 = new PhaseNode_GetLocation(370, phase);
        node370->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        CALL_REGISTER_SKILL_NODE(10281, 370, node370)
    }
    if (noInit == true) {
        return node370;
    }
    auto node24 = GET_SKILL_NODE(24, PhaseNode_SpawnCollider);
    if (node24 != nullptr) node370->setTarget(node24->getColliderID());
    return node370;
}
//--------------------------------------------------------------------------------
// MoveNewPene
//
REGISTER_REGISTER_SKILL_NODE(10281, 372) {
    pnode->resizeTrigger(PhaseNode_MoveNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_DestroyCollider>(PhaseNode_MoveNewPene::TRIGGER_DONE, 376, PhaseNode_DestroyCollider::FUNC_DO, &PhaseNode_DestroyCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(10281, 372) {
    auto node372 = GET_SKILL_NODE(372, PhaseNode_MoveNewPene);
    if (node372 == nullptr) {
        node372 = new PhaseNode_MoveNewPene(372, phase);
        node372->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node372->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node372->setPeneType(PhaseNode_MoveNewPene::MoveNewPene_PeneType::Move);
        node372->setPeneValue(35);
        node372->setType(PhaseNode_MoveNewPene::MoveNewPene_Type::Charge);
        node372->getVars().reserve(4);
        node372->getVars().setVariable<float>(0, 50.00f);
        node372->getVars().setVariable<float>(1, .00f);
        node372->getVars().setVariable<float>(2, .00f);
        node372->getVars().setVariable<float>(3, 180.00f);
        node372->setreentry(false);
        node372->setStopWhenFail(false);
        node372->setCheckFaction(PhaseNode_MoveNewPene::MoveNewPene_CheckFaction::Enemy);
        CALL_REGISTER_SKILL_NODE(10281, 372, node372)
    }
    if (noInit == true) {
        return node372;
    }
    auto node66 = GET_SKILL_NODE(66, PhaseNode_SpawnCollider);
    auto node385 = GET_SKILL_NODE(385, PhaseNode_Distance);
    auto node431 = GET_SKILL_NODE(431, PhaseNode_GetInputRotation);
    if (node66 != nullptr) node372->setTarget(node66->getColliderID());
    if (node385 != nullptr) node372->getVars().setVariable<float>(1, node385->getResult());
    if (node431 != nullptr) node372->getVars().setVariable<float>(2, node431->getAngle());
    return node372;
}
//--------------------------------------------------------------------------------
// SpawnCollider
//
REGISTER_REGISTER_SKILL_NODE(10281, 374) {
    pnode->resizeTrigger(PhaseNode_SpawnCollider::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AttachTo>(PhaseNode_SpawnCollider::TRIGGER_DONE, 381, PhaseNode_AttachTo::FUNC_DO, &PhaseNode_AttachTo::Do);
}

REGISTER_CREATE_SKILL_NODE(10281, 374) {
    auto node374 = GET_SKILL_NODE(374, PhaseNode_SpawnCollider);
    if (node374 == nullptr) {
        node374 = new PhaseNode_SpawnCollider(374, phase);
        node374->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node374->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node374->setMesh("");
        node374->setMeshScale(.00f);
        node374->setEffectID(102811);
        node374->setEffectScale(1.00f);
        node374->setType(PhaseNode_SpawnCollider::SpawnCollider_Type::Circle);
        node374->setTypeParams(0, .50f);
        node374->setTime(.30f);
        node374->setPosZ(.00f);
        node374->setreentry(false);
        node374->setCheckPeneSound(false);
        CALL_REGISTER_SKILL_NODE(10281, 374, node374)
    }
    if (noInit == true) {
        return node374;
    }
    auto node363 = GET_SKILL_NODE(363, PhaseNode_GetLocation);
    auto node431 = GET_SKILL_NODE(431, PhaseNode_GetInputRotation);
    if (node363 != nullptr) node374->setPosX(node363->getX());
    if (node363 != nullptr) node374->setPosY(node363->getY());
    if (node431 != nullptr) node374->setRotation(node431->getAngle());
    return node374;
}
//--------------------------------------------------------------------------------
// DestroyCollider
//
REGISTER_REGISTER_SKILL_NODE(10281, 376) {
}

REGISTER_CREATE_SKILL_NODE(10281, 376) {
    auto node376 = GET_SKILL_NODE(376, PhaseNode_DestroyCollider);
    if (node376 == nullptr) {
        node376 = new PhaseNode_DestroyCollider(376, phase);
        CALL_REGISTER_SKILL_NODE(10281, 376, node376)
    }
    if (noInit == true) {
        return node376;
    }
    auto node66 = GET_SKILL_NODE(66, PhaseNode_SpawnCollider);
    if (node66 != nullptr) node376->setColliderID(node66->getColliderID());
    return node376;
}
//--------------------------------------------------------------------------------
// AttachTo
//
REGISTER_REGISTER_SKILL_NODE(10281, 381) {
    pnode->resizeTrigger(PhaseNode_AttachTo::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_MoveNewPene>(PhaseNode_AttachTo::TRIGGER_DONE, 284, PhaseNode_MoveNewPene::FUNC_DO, &PhaseNode_MoveNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(10281, 381) {
    auto node381 = GET_SKILL_NODE(381, PhaseNode_AttachTo);
    if (node381 == nullptr) {
        node381 = new PhaseNode_AttachTo(381, phase);
        node381->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node381->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node381->setChangeRotation(false);
        node381->setreentry(false);
        CALL_REGISTER_SKILL_NODE(10281, 381, node381)
    }
    if (noInit == true) {
        return node381;
    }
    auto variables = node381->getVariables();
    if (variables != nullptr) {
        node381->setChild(variables->getVariable<uint64_t>(Variable_10281_a102811));
    }
    auto node374 = GET_SKILL_NODE(374, PhaseNode_SpawnCollider);
    if (node374 != nullptr) node381->setParent(node374->getColliderID());
    return node381;
}
//--------------------------------------------------------------------------------
// Distance
//
REGISTER_REGISTER_SKILL_NODE(10281, 385) {
    pnode->resizeTrigger(PhaseNode_Distance::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnCollider>(PhaseNode_Distance::TRIGGER_DONE, 66, PhaseNode_SpawnCollider::FUNC_DO, &PhaseNode_SpawnCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(10281, 385) {
    auto node385 = GET_SKILL_NODE(385, PhaseNode_Distance);
    if (node385 == nullptr) {
        node385 = new PhaseNode_Distance(385, phase);
        CALL_REGISTER_SKILL_NODE(10281, 385, node385)
    }
    if (noInit == true) {
        return node385;
    }
    auto node429 = GET_SKILL_NODE(429, PhaseNode_GetLocation);
    auto node370 = GET_SKILL_NODE(370, PhaseNode_GetLocation);
    if (node429 != nullptr) node385->setAX(node429->getX());
    if (node429 != nullptr) node385->setAY(node429->getY());
    if (node370 != nullptr) node385->setBX(node370->getX());
    if (node370 != nullptr) node385->setBY(node370->getY());
    return node385;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(10281, 389) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuff>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 219, PhaseNode_AddSkillBuff::FUNC_ADD, &PhaseNode_AddSkillBuff::Add);
    pnode->regTrigger<PhaseNode_SpawnCollider>(PhaseNode_CompareFloat::TRIGGER_GREATER, 374, PhaseNode_SpawnCollider::FUNC_DO, &PhaseNode_SpawnCollider::Do);
    pnode->regTrigger<PhaseNode_AddSkillBuff>(PhaseNode_CompareFloat::TRIGGER_LESS, 219, PhaseNode_AddSkillBuff::FUNC_ADD, &PhaseNode_AddSkillBuff::Add);
}

REGISTER_CREATE_SKILL_NODE(10281, 389) {
    auto node389 = GET_SKILL_NODE(389, PhaseNode_CompareFloat);
    if (node389 == nullptr) {
        node389 = new PhaseNode_CompareFloat(389, phase);
        node389->setB(2.00f);
        CALL_REGISTER_SKILL_NODE(10281, 389, node389)
    }
    if (noInit == true) {
        return node389;
    }
    auto node82 = GET_SKILL_NODE(82, PhaseNode_Distance);
    if (node82 != nullptr) node389->setA(node82->getResult());
    return node389;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10281, 403) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlaySound::TRIGGER_DONE, 354, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10281, 403) {
    auto node403 = GET_SKILL_NODE(403, PhaseNode_PlaySound);
    if (node403 == nullptr) {
        node403 = new PhaseNode_PlaySound(403, phase);
        node403->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node403->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node403->setSoundID("SE_Hero107_SkillA_P2");
        node403->setTarget(0U);
        node403->setUsePos(false);
        node403->setPosX(.00f);
        node403->setPosY(.00f);
        node403->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10281, 403, node403)
    }
    if (noInit == true) {
        return node403;
    }
    return node403;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(10281, 405) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_OffsetCalculate>(PhaseNode_GetLocation::TRIGGER_DONE, 303, PhaseNode_OffsetCalculate::FUNC_DO, &PhaseNode_OffsetCalculate::Do);
}

REGISTER_CREATE_SKILL_NODE(10281, 405) {
    auto node405 = GET_SKILL_NODE(405, PhaseNode_GetLocation);
    if (node405 == nullptr) {
        node405 = new PhaseNode_GetLocation(405, phase);
        node405->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        CALL_REGISTER_SKILL_NODE(10281, 405, node405)
    }
    if (noInit == true) {
        return node405;
    }
    auto node24 = GET_SKILL_NODE(24, PhaseNode_SpawnCollider);
    if (node24 != nullptr) node405->setTarget(node24->getColliderID());
    return node405;
}
//--------------------------------------------------------------------------------
// AddSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10281, 408) {
    pnode->resizeTrigger(PhaseNode_AddSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_AddSkillBuff::TRIGGER_DONE, 325, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10281, 408) {
    auto node408 = GET_SKILL_NODE(408, PhaseNode_AddSkillBuff);
    if (node408 == nullptr) {
        node408 = new PhaseNode_AddSkillBuff(408, phase);
        node408->setConfigID(102812);
        node408->setConfigIDs({});
        CALL_REGISTER_SKILL_NODE(10281, 408, node408)
    }
    if (noInit == true) {
        return node408;
    }
    auto node282 = GET_SKILL_NODE(282, PhaseNode_MoveNewPene);
    auto node481 = GET_SKILL_NODE(481, PhaseNode_GetActorAttribute);
    if (node282 != nullptr) node408->setTarget(node282->getStopTarget());
    if (node481 != nullptr) node408->setAttribute(node481->getAttribute());
    return node408;
}
//--------------------------------------------------------------------------------
// CameraXYZShake
//
REGISTER_REGISTER_SKILL_NODE(10281, 410) {
}

REGISTER_CREATE_SKILL_NODE(10281, 410) {
    auto node410 = GET_SKILL_NODE(410, PhaseNode_CameraXYZShake);
    if (node410 == nullptr) {
        node410 = new PhaseNode_CameraXYZShake(410, phase);
        node410->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node410->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node410->setShakeStyle(0);
        node410->setTarget(0U);
        node410->setX(.10f);
        node410->setY(.10f);
        node410->setZ(.10f);
        node410->setDuration(.10f);
        node410->setTimes(1);
        CALL_REGISTER_SKILL_NODE(10281, 410, node410)
    }
    if (noInit == true) {
        return node410;
    }
    return node410;
}
//--------------------------------------------------------------------------------
// CameraXYZShake
//
REGISTER_REGISTER_SKILL_NODE(10281, 415) {
}

REGISTER_CREATE_SKILL_NODE(10281, 415) {
    auto node415 = GET_SKILL_NODE(415, PhaseNode_CameraXYZShake);
    if (node415 == nullptr) {
        node415 = new PhaseNode_CameraXYZShake(415, phase);
        node415->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node415->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node415->setShakeStyle(0);
        node415->setTarget(0U);
        node415->setX(.10f);
        node415->setY(.10f);
        node415->setZ(.10f);
        node415->setDuration(.10f);
        node415->setTimes(1);
        CALL_REGISTER_SKILL_NODE(10281, 415, node415)
    }
    if (noInit == true) {
        return node415;
    }
    return node415;
}
//--------------------------------------------------------------------------------
// SpawnCollider
//
REGISTER_REGISTER_SKILL_NODE(10281, 418) {
    pnode->resizeTrigger(PhaseNode_SpawnCollider::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AttachTo>(PhaseNode_SpawnCollider::TRIGGER_DONE, 421, PhaseNode_AttachTo::FUNC_DO, &PhaseNode_AttachTo::Do);
}

REGISTER_CREATE_SKILL_NODE(10281, 418) {
    auto node418 = GET_SKILL_NODE(418, PhaseNode_SpawnCollider);
    if (node418 == nullptr) {
        node418 = new PhaseNode_SpawnCollider(418, phase);
        node418->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node418->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node418->setMesh("");
        node418->setMeshScale(.00f);
        node418->setEffectID(0);
        node418->setEffectScale(.00f);
        node418->setType(PhaseNode_SpawnCollider::SpawnCollider_Type::Circle);
        node418->setTypeParams(0, 1.00f);
        node418->setTime(.60f);
        node418->setreentry(false);
        node418->setCheckPeneSound(false);
        CALL_REGISTER_SKILL_NODE(10281, 418, node418)
    }
    if (noInit == true) {
        return node418;
    }
    auto node22 = GET_SKILL_NODE(22, PhaseNode_OffsetCalculate);
    if (node22 != nullptr) node418->setPosX(node22->getOutPosX());
    if (node22 != nullptr) node418->setPosY(node22->getOutPosY());
    if (node22 != nullptr) node418->setPosZ(node22->getOutPosZ());
    if (node22 != nullptr) node418->setRotation(node22->getOutRotation());
    return node418;
}
//--------------------------------------------------------------------------------
// AttachTo
//
REGISTER_REGISTER_SKILL_NODE(10281, 421) {
    pnode->resizeTrigger(PhaseNode_AttachTo::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_AttachTo::TRIGGER_DONE, 476, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
    pnode->regTrigger<PhaseNode_MoveNewPene>(PhaseNode_AttachTo::TRIGGER_DONE, 282, PhaseNode_MoveNewPene::FUNC_DO, &PhaseNode_MoveNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(10281, 421) {
    auto node421 = GET_SKILL_NODE(421, PhaseNode_AttachTo);
    if (node421 == nullptr) {
        node421 = new PhaseNode_AttachTo(421, phase);
        node421->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node421->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node421->setChangeRotation(false);
        node421->setreentry(false);
        CALL_REGISTER_SKILL_NODE(10281, 421, node421)
    }
    if (noInit == true) {
        return node421;
    }
    auto node24 = GET_SKILL_NODE(24, PhaseNode_SpawnCollider);
    auto node418 = GET_SKILL_NODE(418, PhaseNode_SpawnCollider);
    if (node24 != nullptr) node421->setParent(node24->getColliderID());
    if (node418 != nullptr) node421->setChild(node418->getColliderID());
    return node421;
}
//--------------------------------------------------------------------------------
// DestroyCollider
//
REGISTER_REGISTER_SKILL_NODE(10281, 423) {
    pnode->resizeTrigger(PhaseNode_DestroyCollider::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_DestroyCollider::TRIGGER_DONE, 370, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_DestroyCollider::TRIGGER_DONE, 112, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10281, 423) {
    auto node423 = GET_SKILL_NODE(423, PhaseNode_DestroyCollider);
    if (node423 == nullptr) {
        node423 = new PhaseNode_DestroyCollider(423, phase);
        CALL_REGISTER_SKILL_NODE(10281, 423, node423)
    }
    if (noInit == true) {
        return node423;
    }
    auto node418 = GET_SKILL_NODE(418, PhaseNode_SpawnCollider);
    if (node418 != nullptr) node423->setColliderID(node418->getColliderID());
    return node423;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10281, 425) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_DestroyCollider>(PhaseNode_Delay::TRIGGER_DONE, 423, PhaseNode_DestroyCollider::FUNC_DO, &PhaseNode_DestroyCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(10281, 425) {
    auto node425 = GET_SKILL_NODE(425, PhaseNode_Delay);
    if (node425 == nullptr) {
        node425 = new PhaseNode_Delay(425, phase);
        node425->setTime(.15f);
        CALL_REGISTER_SKILL_NODE(10281, 425, node425)
    }
    if (noInit == true) {
        return node425;
    }
    return node425;
}
//--------------------------------------------------------------------------------
// Disable
//
REGISTER_REGISTER_SKILL_NODE(10281, 427) {
    pnode->resizeTrigger(PhaseNode_Disable::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CameraXYZShake>(PhaseNode_Disable::TRIGGER_CANCEL, 415, PhaseNode_CameraXYZShake::FUNC_DO, &PhaseNode_CameraXYZShake::Do);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_Disable::TRIGGER_CANCEL, 115, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_Disable::TRIGGER_DONE, 180, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10281, 427) {
    auto node427 = GET_SKILL_NODE(427, PhaseNode_Disable);
    if (node427 == nullptr) {
        node427 = new PhaseNode_Disable(427, phase);
        node427->setTarget(0U);
        node427->setMove(true);
        node427->setSkill(true);
        node427->setShoot(true);
        node427->setTime(1.50f);
        node427->setRotate(true);
        CALL_REGISTER_SKILL_NODE(10281, 427, node427)
    }
    if (noInit == true) {
        return node427;
    }
    return node427;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(10281, 429) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetInputRotation>(PhaseNode_GetLocation::TRIGGER_DONE, 431, PhaseNode_GetInputRotation::FUNC_DO, &PhaseNode_GetInputRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(10281, 429) {
    auto node429 = GET_SKILL_NODE(429, PhaseNode_GetLocation);
    if (node429 == nullptr) {
        node429 = new PhaseNode_GetLocation(429, phase);
        node429->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node429->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(10281, 429, node429)
    }
    if (noInit == true) {
        return node429;
    }
    return node429;
}
//--------------------------------------------------------------------------------
// GetInputRotation
//
REGISTER_REGISTER_SKILL_NODE(10281, 431) {
    pnode->resizeTrigger(PhaseNode_GetInputRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Disable>(PhaseNode_GetInputRotation::TRIGGER_DONE, 427, PhaseNode_Disable::FUNC_DO, &PhaseNode_Disable::Do);
}

REGISTER_CREATE_SKILL_NODE(10281, 431) {
    auto node431 = GET_SKILL_NODE(431, PhaseNode_GetInputRotation);
    if (node431 == nullptr) {
        node431 = new PhaseNode_GetInputRotation(431, phase);
        node431->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        CALL_REGISTER_SKILL_NODE(10281, 431, node431)
    }
    if (noInit == true) {
        return node431;
    }
    return node431;
}
//--------------------------------------------------------------------------------
// ConfirmPhase
//
REGISTER_REGISTER_SKILL_NODE(10281, 433) {
    pnode->resizeTrigger(PhaseNode_ConfirmPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetInt>(PhaseNode_ConfirmPhase::TRIGGER_CONFIRM, 337, PhaseNode_SetInt::FUNC_SET, &PhaseNode_SetInt::Set);
    pnode->regTrigger<PhaseNode_StopEffect>(PhaseNode_ConfirmPhase::TRIGGER_CONFIRM, 465, PhaseNode_StopEffect::FUNC_DO, &PhaseNode_StopEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(10281, 433) {
    auto node433 = GET_SKILL_NODE(433, PhaseNode_ConfirmPhase);
    if (node433 == nullptr) {
        node433 = new PhaseNode_ConfirmPhase(433, phase);
        CALL_REGISTER_SKILL_NODE(10281, 433, node433)
    }
    if (noInit == true) {
        return node433;
    }
    return node433;
}
//--------------------------------------------------------------------------------
// CancelPhase
//
REGISTER_REGISTER_SKILL_NODE(10281, 435) {
    pnode->resizeTrigger(PhaseNode_CancelPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RemoveSkillBuff>(PhaseNode_CancelPhase::TRIGGER_CANCEL, 474, PhaseNode_RemoveSkillBuff::FUNC_REMOVE, &PhaseNode_RemoveSkillBuff::Remove);
}

REGISTER_CREATE_SKILL_NODE(10281, 435) {
    auto node435 = GET_SKILL_NODE(435, PhaseNode_CancelPhase);
    if (node435 == nullptr) {
        node435 = new PhaseNode_CancelPhase(435, phase);
        CALL_REGISTER_SKILL_NODE(10281, 435, node435)
    }
    if (noInit == true) {
        return node435;
    }
    return node435;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(10281, 437) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_ResetCD::TRIGGER_DONE, 117, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(10281, 437) {
    auto node437 = GET_SKILL_NODE(437, PhaseNode_ResetCD);
    if (node437 == nullptr) {
        node437 = new PhaseNode_ResetCD(437, phase);
        node437->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node437->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node437->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(10281, 437, node437)
    }
    if (noInit == true) {
        return node437;
    }
    return node437;
}
//--------------------------------------------------------------------------------
// Disable
//
REGISTER_REGISTER_SKILL_NODE(10281, 439) {
    pnode->resizeTrigger(PhaseNode_Disable::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_Disable::TRIGGER_CANCEL, 478, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_Disable::TRIGGER_DONE, 486, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10281, 439) {
    auto node439 = GET_SKILL_NODE(439, PhaseNode_Disable);
    if (node439 == nullptr) {
        node439 = new PhaseNode_Disable(439, phase);
        node439->setTarget(0U);
        node439->setMove(false);
        node439->setSkill(true);
        node439->setShoot(true);
        node439->setTime(.00f);
        node439->setRotate(false);
        CALL_REGISTER_SKILL_NODE(10281, 439, node439)
    }
    if (noInit == true) {
        return node439;
    }
    return node439;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10281, 444) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlayAnimation::TRIGGER_DONE, 448, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10281, 444) {
    auto node444 = GET_SKILL_NODE(444, PhaseNode_PlayAnimation);
    if (node444 == nullptr) {
        node444 = new PhaseNode_PlayAnimation(444, phase);
        node444->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node444->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node444->setTarget(0U);
        node444->setAnimation("Skill1S4");
        node444->setParameter("SkillArmBusy");
        node444->setValue(true);
        CALL_REGISTER_SKILL_NODE(10281, 444, node444)
    }
    if (noInit == true) {
        return node444;
    }
    return node444;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10281, 448) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SwitchToInt>(PhaseNode_Delay::TRIGGER_DONE, 450, PhaseNode_SwitchToInt::FUNC_SWITCH, &PhaseNode_SwitchToInt::Switch);
}

REGISTER_CREATE_SKILL_NODE(10281, 448) {
    auto node448 = GET_SKILL_NODE(448, PhaseNode_Delay);
    if (node448 == nullptr) {
        node448 = new PhaseNode_Delay(448, phase);
        node448->setTime(.10f);
        CALL_REGISTER_SKILL_NODE(10281, 448, node448)
    }
    if (noInit == true) {
        return node448;
    }
    return node448;
}
//--------------------------------------------------------------------------------
// SwitchToInt
//
REGISTER_REGISTER_SKILL_NODE(10281, 450) {
    pnode->resizeTrigger(3);
    pnode->regTrigger<PhaseNode_PlayAnimation>(1, 461, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10281, 450) {
    auto node450 = GET_SKILL_NODE(450, PhaseNode_SwitchToInt);
    if (node450 == nullptr) {
        node450 = new PhaseNode_SwitchToInt(450, phase);
        CALL_REGISTER_SKILL_NODE(10281, 450, node450)
    }
    if (noInit == true) {
        return node450;
    }
    auto variables = node450->getVariables();
    if (variables != nullptr) {
        node450->setSelection(variables->getVariable<int32_t>(Variable_10281_a102815));
    }
    return node450;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10281, 461) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_PlayAnimation::TRIGGER_DONE, 463, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(10281, 461) {
    auto node461 = GET_SKILL_NODE(461, PhaseNode_PlayAnimation);
    if (node461 == nullptr) {
        node461 = new PhaseNode_PlayAnimation(461, phase);
        node461->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node461->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node461->setTarget(0U);
        node461->setAnimation("Skill1S5");
        node461->setParameter("");
        node461->setValue(false);
        CALL_REGISTER_SKILL_NODE(10281, 461, node461)
    }
    if (noInit == true) {
        return node461;
    }
    return node461;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(10281, 463) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuff>(PhaseNode_PlayEffect::TRIGGER_DONE, 469, PhaseNode_AddSkillBuff::FUNC_ADD, &PhaseNode_AddSkillBuff::Add);
}

REGISTER_CREATE_SKILL_NODE(10281, 463) {
    auto node463 = GET_SKILL_NODE(463, PhaseNode_PlayEffect);
    if (node463 == nullptr) {
        node463 = new PhaseNode_PlayEffect(463, phase);
        node463->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node463->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node463->setEffectID(1063);
        node463->setChangeColor(false);
        node463->setType(PhaseNode_PlayEffect::PlayEffect_Type::WithTarget);
        node463->getVars().reserve(6);
        node463->getVars().setVariable<uint64_t>(0, 0U);
        node463->getVars().setVariable<std::string>(1, "Bip001 R Finger0");
        node463->getVars().setVariable<float>(2, .00f);
        node463->getVars().setVariable<float>(3, .00f);
        node463->getVars().setVariable<float>(4, .00f);
        node463->getVars().setVariable<bool>(5, false);
        node463->setRotation(.00f);
        node463->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(10281, 463, node463)
    }
    if (noInit == true) {
        return node463;
    }
    return node463;
}
//--------------------------------------------------------------------------------
// StopEffect
//
REGISTER_REGISTER_SKILL_NODE(10281, 465) {
    pnode->resizeTrigger(PhaseNode_StopEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RemoveSkillBuff>(PhaseNode_StopEffect::TRIGGER_DONE, 472, PhaseNode_RemoveSkillBuff::FUNC_REMOVE, &PhaseNode_RemoveSkillBuff::Remove);
}

REGISTER_CREATE_SKILL_NODE(10281, 465) {
    auto node465 = GET_SKILL_NODE(465, PhaseNode_StopEffect);
    if (node465 == nullptr) {
        node465 = new PhaseNode_StopEffect(465, phase);
        node465->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node465->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node465->setEffectID(1063);
        CALL_REGISTER_SKILL_NODE(10281, 465, node465)
    }
    if (noInit == true) {
        return node465;
    }
    return node465;
}
//--------------------------------------------------------------------------------
// FloatOperation
//
REGISTER_REGISTER_SKILL_NODE(10281, 467) {
    pnode->resizeTrigger(PhaseNode_FloatOperation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_FloatOperation::TRIGGER_DONE, 389, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(10281, 467) {
    auto node467 = GET_SKILL_NODE(467, PhaseNode_FloatOperation);
    if (node467 == nullptr) {
        node467 = new PhaseNode_FloatOperation(467, phase);
        node467->setValue(2.00f);
        node467->setMethod(PhaseNode_FloatOperation::FloatOperation_Method::Sub);
        CALL_REGISTER_SKILL_NODE(10281, 467, node467)
    }
    if (noInit == true) {
        return node467;
    }
    auto node82 = GET_SKILL_NODE(82, PhaseNode_Distance);
    if (node82 != nullptr) node467->setBase(node82->getResult());
    return node467;
}
//--------------------------------------------------------------------------------
// AddSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10281, 469) {
}

REGISTER_CREATE_SKILL_NODE(10281, 469) {
    auto node469 = GET_SKILL_NODE(469, PhaseNode_AddSkillBuff);
    if (node469 == nullptr) {
        node469 = new PhaseNode_AddSkillBuff(469, phase);
        node469->setConfigID(0);
        node469->setConfigIDs({102814});
        node469->setTarget(0U);
        node469->setAttribute({{}});
        CALL_REGISTER_SKILL_NODE(10281, 469, node469)
    }
    if (noInit == true) {
        return node469;
    }
    return node469;
}
//--------------------------------------------------------------------------------
// RemoveSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10281, 472) {
}

REGISTER_CREATE_SKILL_NODE(10281, 472) {
    auto node472 = GET_SKILL_NODE(472, PhaseNode_RemoveSkillBuff);
    if (node472 == nullptr) {
        node472 = new PhaseNode_RemoveSkillBuff(472, phase);
        node472->setBuffID(0U);
        node472->setBuffIDs({});
        node472->setConfigID(102814);
        node472->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(10281, 472, node472)
    }
    if (noInit == true) {
        return node472;
    }
    return node472;
}
//--------------------------------------------------------------------------------
// RemoveSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10281, 474) {
    pnode->resizeTrigger(PhaseNode_RemoveSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_RemoveSkillBuff::TRIGGER_DONE, 117, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(10281, 474) {
    auto node474 = GET_SKILL_NODE(474, PhaseNode_RemoveSkillBuff);
    if (node474 == nullptr) {
        node474 = new PhaseNode_RemoveSkillBuff(474, phase);
        node474->setBuffID(0U);
        node474->setBuffIDs({});
        node474->setConfigID(102814);
        node474->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(10281, 474, node474)
    }
    if (noInit == true) {
        return node474;
    }
    return node474;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(10281, 475) {
}

REGISTER_CREATE_SKILL_NODE(10281, 475) {
    auto node475 = GET_SKILL_NODE(475, PhaseNode_TriggerCheck);
    if (node475 == nullptr) {
        node475 = new PhaseNode_TriggerCheck(475, phase);
        auto node4 = GET_SKILL_NODE(4, PhaseNode_TriggerUpdate);
        if (node4 != nullptr) node4->addTriggerCheck(node475);
        
        CALL_REGISTER_SKILL_NODE(10281, 475, node475)
    }
    if (noInit == true) {
        return node475;
    }
    auto node476 = GET_SKILL_NODE(476, PhaseNode_CreateTriggerNewPene);
    if (node476 != nullptr) node475->setTrigger(0, node476->getTriggerID());
    return node475;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(10281, 476) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 475, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 477, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(10281, 476) {
    auto node476 = GET_SKILL_NODE(476, PhaseNode_CreateTriggerNewPene);
    if (node476 == nullptr) {
        node476 = new PhaseNode_CreateTriggerNewPene(476, phase);
        node476->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::In);
        node476->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node476->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Enemy);
        node476->setOnHero(true);
        node476->setOnMinion(true);
        node476->setOnDestruct(false);
        node476->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(10281, 476, node476)
    }
    if (noInit == true) {
        return node476;
    }
    auto node418 = GET_SKILL_NODE(418, PhaseNode_SpawnCollider);
    if (node418 != nullptr) node476->setColliderID(node418->getColliderID());
    return node476;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(10281, 477) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetUInt64sValue>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 36, PhaseNode_GetUInt64sValue::FUNC_DO, &PhaseNode_GetUInt64sValue::Do);
}

REGISTER_CREATE_SKILL_NODE(10281, 477) {
    auto node477 = GET_SKILL_NODE(477, PhaseNode_ActorFilterNewPene);
    if (node477 == nullptr) {
        node477 = new PhaseNode_ActorFilterNewPene(477, phase);
        node477->setHero(true);
        node477->setMinion(true);
        node477->setDestruct(false);
        node477->setShield(false);
        node477->setTotalCount(1);
        node477->setPerCount(0);
        CALL_REGISTER_SKILL_NODE(10281, 477, node477)
    }
    if (noInit == true) {
        return node477;
    }
    auto node476 = GET_SKILL_NODE(476, PhaseNode_CreateTriggerNewPene);
    if (node476 != nullptr) node477->setInput(node476->getOther());
    return node477;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(10281, 478) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_ResetCD::TRIGGER_DONE, 479, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10281, 478) {
    auto node478 = GET_SKILL_NODE(478, PhaseNode_ResetCD);
    if (node478 == nullptr) {
        node478 = new PhaseNode_ResetCD(478, phase);
        node478->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node478->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node478->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(10281, 478, node478)
    }
    if (noInit == true) {
        return node478;
    }
    return node478;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10281, 479) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_PlayAnimation::TRIGGER_DONE, 481, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(10281, 479) {
    auto node479 = GET_SKILL_NODE(479, PhaseNode_PlayAnimation);
    if (node479 == nullptr) {
        node479 = new PhaseNode_PlayAnimation(479, phase);
        node479->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node479->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node479->setTarget(0U);
        node479->setAnimation("Skill1S1");
        node479->setParameter("SkillArmBusy");
        node479->setValue(false);
        CALL_REGISTER_SKILL_NODE(10281, 479, node479)
    }
    if (noInit == true) {
        return node479;
    }
    return node479;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10281, 480) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_PlaySound::TRIGGER_DONE, 429, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(10281, 480) {
    auto node480 = GET_SKILL_NODE(480, PhaseNode_PlaySound);
    if (node480 == nullptr) {
        node480 = new PhaseNode_PlaySound(480, phase);
        node480->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node480->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node480->setSoundID("VO_Hero107_Skill_A");
        node480->setTarget(0U);
        node480->setUsePos(false);
        node480->setPosX(.00f);
        node480->setPosY(.00f);
        node480->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10281, 480, node480)
    }
    if (noInit == true) {
        return node480;
    }
    return node480;
}
//--------------------------------------------------------------------------------
// GetActorAttribute
//
REGISTER_REGISTER_SKILL_NODE(10281, 481) {
    pnode->resizeTrigger(PhaseNode_GetActorAttribute::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 480, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10281, 481) {
    auto node481 = GET_SKILL_NODE(481, PhaseNode_GetActorAttribute);
    if (node481 == nullptr) {
        node481 = new PhaseNode_GetActorAttribute(481, phase);
        node481->setTarget(0U);
        node481->setType({});
        CALL_REGISTER_SKILL_NODE(10281, 481, node481)
    }
    if (noInit == true) {
        return node481;
    }
    return node481;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10281, 483) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_IsInterruptType>(PhaseNode_Detect::TRIGGER_ON, 489, PhaseNode_IsInterruptType::FUNC_DO, &PhaseNode_IsInterruptType::Do);
}

REGISTER_CREATE_SKILL_NODE(10281, 483) {
    auto node483 = GET_SKILL_NODE(483, PhaseNode_Detect);
    if (node483 == nullptr) {
        node483 = new PhaseNode_Detect(483, phase);
        node483->setSelf(0U);
        node483->setEvent("daduan_001");
        node483->setType(PhaseNode_Detect::Detect_Type::Interrupt_Skill);
        node483->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10281, 483, node483)
    }
    if (noInit == true) {
        return node483;
    }
    return node483;
}
//--------------------------------------------------------------------------------
// SwitchToInt
//
REGISTER_REGISTER_SKILL_NODE(10281, 484) {
    pnode->resizeTrigger(4);
    pnode->regTrigger<PhaseNode_ResetCD>(1, 437, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(10281, 484) {
    auto node484 = GET_SKILL_NODE(484, PhaseNode_SwitchToInt);
    if (node484 == nullptr) {
        node484 = new PhaseNode_SwitchToInt(484, phase);
        CALL_REGISTER_SKILL_NODE(10281, 484, node484)
    }
    if (noInit == true) {
        return node484;
    }
    auto variables = node484->getVariables();
    if (variables != nullptr) {
        node484->setSelection(variables->getVariable<int32_t>(Variable_10281_a102815));
    }
    return node484;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10281, 486) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_RaiseEvent::TRIGGER_DONE, 495, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10281, 486) {
    auto node486 = GET_SKILL_NODE(486, PhaseNode_RaiseEvent);
    if (node486 == nullptr) {
        node486 = new PhaseNode_RaiseEvent(486, phase);
        node486->setEvent("daduan_001");
        node486->setTarget(0U);
        node486->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node486->setTypeParams(0, 0);
        node486->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10281, 486, node486)
    }
    if (noInit == true) {
        return node486;
    }
    return node486;
}
//--------------------------------------------------------------------------------
// StartPreInput
//
REGISTER_REGISTER_SKILL_NODE(10281, 487) {
    pnode->resizeTrigger(PhaseNode_StartPreInput::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_StartPreInput::TRIGGER_DONE, 491, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_StartPreInput::TRIGGER_DONE, 444, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10281, 487) {
    auto node487 = GET_SKILL_NODE(487, PhaseNode_StartPreInput);
    if (node487 == nullptr) {
        node487 = new PhaseNode_StartPreInput(487, phase);
        node487->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node487->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node487->setDelayTime(.00f);
        CALL_REGISTER_SKILL_NODE(10281, 487, node487)
    }
    if (noInit == true) {
        return node487;
    }
    return node487;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(10281, 488) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_If::TRIGGER_TRUE, 490, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10281, 488) {
    auto node488 = GET_SKILL_NODE(488, PhaseNode_If);
    if (node488 == nullptr) {
        node488 = new PhaseNode_If(488, phase);
        CALL_REGISTER_SKILL_NODE(10281, 488, node488)
    }
    if (noInit == true) {
        return node488;
    }
    auto variables = node488->getVariables();
    if (variables != nullptr) {
        node488->setCondition(variables->getVariable<bool>(Variable_10281_InterruptAnimat));
    }
    return node488;
}
//--------------------------------------------------------------------------------
// IsInterruptType
//
REGISTER_REGISTER_SKILL_NODE(10281, 489) {
    pnode->resizeTrigger(PhaseNode_IsInterruptType::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SwitchToInt>(PhaseNode_IsInterruptType::TRIGGER_BUFF, 484, PhaseNode_SwitchToInt::FUNC_SWITCH, &PhaseNode_SwitchToInt::Switch);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_POSCHANGE, 488, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTAIM, 488, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTFIRE, 488, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTRELOAD, 488, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_USESKILL, 488, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(10281, 489) {
    auto node489 = GET_SKILL_NODE(489, PhaseNode_IsInterruptType);
    if (node489 == nullptr) {
        node489 = new PhaseNode_IsInterruptType(489, phase);
        node489->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node489->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10281, 489, node489)
    }
    if (noInit == true) {
        return node489;
    }
    auto node483 = GET_SKILL_NODE(483, PhaseNode_Detect);
    if (node483 != nullptr) node489->setType(node483->getVars().getVariable<int32_t>(2));
    return node489;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10281, 490) {
}

REGISTER_CREATE_SKILL_NODE(10281, 490) {
    auto node490 = GET_SKILL_NODE(490, PhaseNode_PlayAnimation);
    if (node490 == nullptr) {
        node490 = new PhaseNode_PlayAnimation(490, phase);
        node490->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node490->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node490->setTarget(0U);
        node490->setAnimation("Idle");
        node490->setParameter("");
        node490->setValue(false);
        CALL_REGISTER_SKILL_NODE(10281, 490, node490)
    }
    if (noInit == true) {
        return node490;
    }
    return node490;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10281, 491) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_Delay::TRIGGER_DONE, 494, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(10281, 491) {
    auto node491 = GET_SKILL_NODE(491, PhaseNode_Delay);
    if (node491 == nullptr) {
        node491 = new PhaseNode_Delay(491, phase);
        node491->setTime(.30f);
        CALL_REGISTER_SKILL_NODE(10281, 491, node491)
    }
    if (noInit == true) {
        return node491;
    }
    return node491;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(10281, 494) {
}

REGISTER_CREATE_SKILL_NODE(10281, 494) {
    auto node494 = GET_SKILL_NODE(494, PhaseNode_SetBool);
    if (node494 == nullptr) {
        node494 = new PhaseNode_SetBool(494, phase);
        node494->setName("InterruptAnimat");
        node494->setValue(true);
        CALL_REGISTER_SKILL_NODE(10281, 494, node494)
    }
    if (noInit == true) {
        return node494;
    }
    return node494;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10281, 495) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StartPreInput>(PhaseNode_RaiseEvent::TRIGGER_DONE, 487, PhaseNode_StartPreInput::FUNC_DO, &PhaseNode_StartPreInput::Do);
}

REGISTER_CREATE_SKILL_NODE(10281, 495) {
    auto node495 = GET_SKILL_NODE(495, PhaseNode_RaiseEvent);
    if (node495 == nullptr) {
        node495 = new PhaseNode_RaiseEvent(495, phase);
        node495->setEvent("Dead_001");
        node495->setTarget(0U);
        node495->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node495->setTypeParams(0, 0);
        node495->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10281, 495, node495)
    }
    if (noInit == true) {
        return node495;
    }
    return node495;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10281, 496) {
}

REGISTER_CREATE_SKILL_NODE(10281, 496) {
    auto node496 = GET_SKILL_NODE(496, PhaseNode_Detect);
    if (node496 == nullptr) {
        node496 = new PhaseNode_Detect(496, phase);
        node496->setSelf(0U);
        node496->setEvent("Dead_001");
        node496->setType(PhaseNode_Detect::Detect_Type::Actor_Dead);
        node496->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10281, 496, node496)
    }
    if (noInit == true) {
        return node496;
    }
    return node496;
}

//--------------------------------------------------------------------------------
// SkillCreator_10281
//
class SkillCreator_10281 : public SkillCreator {
public:
    SkillCreator_10281() {}
    virtual ~SkillCreator_10281() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_10281

//--------------------------------------------------------------------------------
// SkillPhase_10281
//
class SkillPhase_10281 : public SkillPhase {
public:
    SkillPhase_10281(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_10281() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(10281, 2) // StartPhase
        CASE_CREATE_SKILL_NODE(10281, 4) // TriggerUpdate
        CASE_CREATE_SKILL_NODE(10281, 22) // OffsetCalculate
        CASE_CREATE_SKILL_NODE(10281, 24) // SpawnCollider
        CASE_CREATE_SKILL_NODE(10281, 36) // GetUInt64sValue
        CASE_CREATE_SKILL_NODE(10281, 54) // SetUInt64
        CASE_CREATE_SKILL_NODE(10281, 66) // SpawnCollider
        CASE_CREATE_SKILL_NODE(10281, 68) // DestroyCollider
        CASE_CREATE_SKILL_NODE(10281, 82) // Distance
        CASE_CREATE_SKILL_NODE(10281, 109) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10281, 112) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10281, 115) // Delay
        CASE_CREATE_SKILL_NODE(10281, 117) // EndPhase
        CASE_CREATE_SKILL_NODE(10281, 126) // SetBool
        CASE_CREATE_SKILL_NODE(10281, 157) // DestroyCollider
        CASE_CREATE_SKILL_NODE(10281, 163) // AddSkillBuff
        CASE_CREATE_SKILL_NODE(10281, 180) // Delay
        CASE_CREATE_SKILL_NODE(10281, 217) // AddSkillBuff
        CASE_CREATE_SKILL_NODE(10281, 219) // AddSkillBuff
        CASE_CREATE_SKILL_NODE(10281, 276) // PlayEffect
        CASE_CREATE_SKILL_NODE(10281, 282) // MoveNewPene
        CASE_CREATE_SKILL_NODE(10281, 284) // MoveNewPene
        CASE_CREATE_SKILL_NODE(10281, 300) // PlayEffect
        CASE_CREATE_SKILL_NODE(10281, 303) // OffsetCalculate
        CASE_CREATE_SKILL_NODE(10281, 313) // PlaySound
        CASE_CREATE_SKILL_NODE(10281, 325) // PlaySound
        CASE_CREATE_SKILL_NODE(10281, 337) // SetInt
        CASE_CREATE_SKILL_NODE(10281, 354) // Delay
        CASE_CREATE_SKILL_NODE(10281, 358) // If
        CASE_CREATE_SKILL_NODE(10281, 363) // GetLocation
        CASE_CREATE_SKILL_NODE(10281, 370) // GetLocation
        CASE_CREATE_SKILL_NODE(10281, 372) // MoveNewPene
        CASE_CREATE_SKILL_NODE(10281, 374) // SpawnCollider
        CASE_CREATE_SKILL_NODE(10281, 376) // DestroyCollider
        CASE_CREATE_SKILL_NODE(10281, 381) // AttachTo
        CASE_CREATE_SKILL_NODE(10281, 385) // Distance
        CASE_CREATE_SKILL_NODE(10281, 389) // CompareFloat
        CASE_CREATE_SKILL_NODE(10281, 403) // PlaySound
        CASE_CREATE_SKILL_NODE(10281, 405) // GetLocation
        CASE_CREATE_SKILL_NODE(10281, 408) // AddSkillBuff
        CASE_CREATE_SKILL_NODE(10281, 410) // CameraXYZShake
        CASE_CREATE_SKILL_NODE(10281, 415) // CameraXYZShake
        CASE_CREATE_SKILL_NODE(10281, 418) // SpawnCollider
        CASE_CREATE_SKILL_NODE(10281, 421) // AttachTo
        CASE_CREATE_SKILL_NODE(10281, 423) // DestroyCollider
        CASE_CREATE_SKILL_NODE(10281, 425) // Delay
        CASE_CREATE_SKILL_NODE(10281, 427) // Disable
        CASE_CREATE_SKILL_NODE(10281, 429) // GetLocation
        CASE_CREATE_SKILL_NODE(10281, 431) // GetInputRotation
        CASE_CREATE_SKILL_NODE(10281, 433) // ConfirmPhase
        CASE_CREATE_SKILL_NODE(10281, 435) // CancelPhase
        CASE_CREATE_SKILL_NODE(10281, 437) // ResetCD
        CASE_CREATE_SKILL_NODE(10281, 439) // Disable
        CASE_CREATE_SKILL_NODE(10281, 444) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10281, 448) // Delay
        CASE_CREATE_SKILL_NODE(10281, 450) // SwitchToInt
        CASE_CREATE_SKILL_NODE(10281, 461) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10281, 463) // PlayEffect
        CASE_CREATE_SKILL_NODE(10281, 465) // StopEffect
        CASE_CREATE_SKILL_NODE(10281, 467) // FloatOperation
        CASE_CREATE_SKILL_NODE(10281, 469) // AddSkillBuff
        CASE_CREATE_SKILL_NODE(10281, 472) // RemoveSkillBuff
        CASE_CREATE_SKILL_NODE(10281, 474) // RemoveSkillBuff
        CASE_CREATE_SKILL_NODE(10281, 475) // TriggerCheck
        CASE_CREATE_SKILL_NODE(10281, 476) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(10281, 477) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(10281, 478) // ResetCD
        CASE_CREATE_SKILL_NODE(10281, 479) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10281, 480) // PlaySound
        CASE_CREATE_SKILL_NODE(10281, 481) // GetActorAttribute
        CASE_CREATE_SKILL_NODE(10281, 483) // Detect
        CASE_CREATE_SKILL_NODE(10281, 484) // SwitchToInt
        CASE_CREATE_SKILL_NODE(10281, 486) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10281, 487) // StartPreInput
        CASE_CREATE_SKILL_NODE(10281, 488) // If
        CASE_CREATE_SKILL_NODE(10281, 489) // IsInterruptType
        CASE_CREATE_SKILL_NODE(10281, 490) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10281, 491) // Delay
        CASE_CREATE_SKILL_NODE(10281, 494) // SetBool
        CASE_CREATE_SKILL_NODE(10281, 495) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10281, 496) // Detect
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_10281

SkillLogic* SkillCreator_10281::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //设置变量
    Variable_10281_a102811 = logic->getVariables().setVariable<uint64_t>("a102811", 0U);
    Variable_10281_a102812 = logic->getVariables().setVariable<bool>("a102812");
    Variable_10281_a102815 = logic->getVariables().setVariable<int32_t>("a102815", 1);
    Variable_10281_InterruptAnimat = logic->getVariables().setVariable<bool>("InterruptAnimat");
    //创建阶段phase
    auto phase = new SkillPhase_10281(1, logic, 5);
    //设置phase执行器
    phase->setRunPhaseNode(1, 2);
    phase->setRunPhaseNode(2, 4);
    phase->addConfirmPhaseNode(3, 433);
    phase->addCancelPhaseNode(4, 435);
    phase->setDetectPhaseNode(5, 483);
    phase->setDetectPhaseNode(5, 496);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_10281::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
