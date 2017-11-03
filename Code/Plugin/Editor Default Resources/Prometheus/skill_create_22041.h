#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

#include "skill_psnode_comparefloat.h"
#include "skill_psnode_delay.h"
#include "skill_psnode_detect.h"
#include "skill_psnode_endphase.h"
#include "skill_psnode_getbbparamuint64.h"
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
#include "skill_psnode_spawnprojectile.h"
#include "skill_psnode_startphase.h"
#include "skill_psnode_stopeffect.h"
#include "skill_psnode_triggerupdate.h"

namespace pvp {

//变量声明
//--------------------------------------------------------------------------------
// StartPhase
//
REGISTER_REGISTER_SKILL_NODE(22041, 2) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_StartPhase::TRIGGER_START, 62, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_StartPhase::TRIGGER_START, 81, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_StartPhase::TRIGGER_START, 64, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(22041, 2) {
    auto node2 = GET_SKILL_NODE(2, PhaseNode_StartPhase);
    if (node2 == nullptr) {
        node2 = new PhaseNode_StartPhase(2, phase);
        CALL_REGISTER_SKILL_NODE(22041, 2, node2)
    }
    if (noInit == true) {
        return node2;
    }
    return node2;
}
//--------------------------------------------------------------------------------
// TriggerUpdate
//
REGISTER_REGISTER_SKILL_NODE(22041, 6) {
}

REGISTER_CREATE_SKILL_NODE(22041, 6) {
    auto node6 = GET_SKILL_NODE(6, PhaseNode_TriggerUpdate);
    if (node6 == nullptr) {
        node6 = new PhaseNode_TriggerUpdate(6, phase);
        CALL_REGISTER_SKILL_NODE(22041, 6, node6)
    }
    if (noInit == true) {
        return node6;
    }
    return node6;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(22041, 22) {
}

REGISTER_CREATE_SKILL_NODE(22041, 22) {
    auto node22 = GET_SKILL_NODE(22, PhaseNode_EndPhase);
    if (node22 == nullptr) {
        node22 = new PhaseNode_EndPhase(22, phase);
        node22->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node22->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(22041, 22, node22)
    }
    if (noInit == true) {
        return node22;
    }
    return node22;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(22041, 25) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_Detect::TRIGGER_ON, 27, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(22041, 25) {
    auto node25 = GET_SKILL_NODE(25, PhaseNode_Detect);
    if (node25 == nullptr) {
        node25 = new PhaseNode_Detect(25, phase);
        node25->setSelf(0U);
        node25->setEvent("");
        node25->setType(PhaseNode_Detect::Detect_Type::Actor_Dead);
        node25->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(22041, 25, node25)
    }
    if (noInit == true) {
        return node25;
    }
    return node25;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(22041, 27) {
}

REGISTER_CREATE_SKILL_NODE(22041, 27) {
    auto node27 = GET_SKILL_NODE(27, PhaseNode_EndPhase);
    if (node27 == nullptr) {
        node27 = new PhaseNode_EndPhase(27, phase);
        node27->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node27->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(22041, 27, node27)
    }
    if (noInit == true) {
        return node27;
    }
    return node27;
}
//--------------------------------------------------------------------------------
// SpawnProjectile
//
REGISTER_REGISTER_SKILL_NODE(22041, 47) {
    pnode->resizeTrigger(PhaseNode_SpawnProjectile::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_SpawnProjectile::TRIGGER_DONE, 77, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(22041, 47) {
    auto node47 = GET_SKILL_NODE(47, PhaseNode_SpawnProjectile);
    if (node47 == nullptr) {
        node47 = new PhaseNode_SpawnProjectile(47, phase);
        node47->setDataId(52204);
        node47->setEndPosZ(.00f);
        node47->setMaxCount(0);
        CALL_REGISTER_SKILL_NODE(22041, 47, node47)
    }
    if (noInit == true) {
        return node47;
    }
    auto node70 = GET_SKILL_NODE(70, PhaseNode_OffsetCalculate);
    auto node61 = GET_SKILL_NODE(61, PhaseNode_GetLocation);
    if (node70 != nullptr) node47->setPosX(node70->getOutPosX());
    if (node70 != nullptr) node47->setPosY(node70->getOutPosY());
    if (node70 != nullptr) node47->setPosZ(node70->getOutPosZ());
    if (node61 != nullptr) node47->setEndPosX(node61->getX());
    if (node61 != nullptr) node47->setEndPosY(node61->getY());
    if (node70 != nullptr) node47->setRotation(node70->getOutRotation());
    return node47;
}
//--------------------------------------------------------------------------------
// GetBBParamUInt64
//
REGISTER_REGISTER_SKILL_NODE(22041, 59) {
    pnode->resizeTrigger(PhaseNode_GetBBParamUInt64::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_GetBBParamUInt64::TRIGGER_DONE, 61, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(22041, 59) {
    auto node59 = GET_SKILL_NODE(59, PhaseNode_GetBBParamUInt64);
    if (node59 == nullptr) {
        node59 = new PhaseNode_GetBBParamUInt64(59, phase);
        node59->setBBName("AtkTarget");
        CALL_REGISTER_SKILL_NODE(22041, 59, node59)
    }
    if (noInit == true) {
        return node59;
    }
    return node59;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(22041, 61) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnProjectile>(PhaseNode_GetLocation::TRIGGER_DONE, 47, PhaseNode_SpawnProjectile::FUNC_DO, &PhaseNode_SpawnProjectile::Do);
}

REGISTER_CREATE_SKILL_NODE(22041, 61) {
    auto node61 = GET_SKILL_NODE(61, PhaseNode_GetLocation);
    if (node61 == nullptr) {
        node61 = new PhaseNode_GetLocation(61, phase);
        node61->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        CALL_REGISTER_SKILL_NODE(22041, 61, node61)
    }
    if (noInit == true) {
        return node61;
    }
    auto node59 = GET_SKILL_NODE(59, PhaseNode_GetBBParamUInt64);
    if (node59 != nullptr) node61->setTarget(node59->getValue());
    return node61;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22041, 62) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_Delay::TRIGGER_DONE, 63, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(22041, 62) {
    auto node62 = GET_SKILL_NODE(62, PhaseNode_Delay);
    if (node62 == nullptr) {
        node62 = new PhaseNode_Delay(62, phase);
        node62->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(22041, 62, node62)
    }
    if (noInit == true) {
        return node62;
    }
    return node62;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(22041, 63) {
}

REGISTER_CREATE_SKILL_NODE(22041, 63) {
    auto node63 = GET_SKILL_NODE(63, PhaseNode_PlaySound);
    if (node63 == nullptr) {
        node63 = new PhaseNode_PlaySound(63, phase);
        node63->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node63->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node63->setSoundID("VO_MON2202_ATK1");
        node63->setTarget(0U);
        node63->setUsePos(false);
        node63->setPosX(.00f);
        node63->setPosY(.00f);
        node63->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(22041, 63, node63)
    }
    if (noInit == true) {
        return node63;
    }
    return node63;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(22041, 64) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_ResetCD::TRIGGER_DONE, 65, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(22041, 64) {
    auto node64 = GET_SKILL_NODE(64, PhaseNode_ResetCD);
    if (node64 == nullptr) {
        node64 = new PhaseNode_ResetCD(64, phase);
        node64->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node64->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node64->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(22041, 64, node64)
    }
    if (noInit == true) {
        return node64;
    }
    return node64;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(22041, 65) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_PlayAnimation::TRIGGER_DONE, 66, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(22041, 65) {
    auto node65 = GET_SKILL_NODE(65, PhaseNode_PlayAnimation);
    if (node65 == nullptr) {
        node65 = new PhaseNode_PlayAnimation(65, phase);
        node65->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node65->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node65->setTarget(0U);
        node65->setAnimation("Skill1S1");
        node65->setParameter("");
        node65->setValue(false);
        CALL_REGISTER_SKILL_NODE(22041, 65, node65)
    }
    if (noInit == true) {
        return node65;
    }
    return node65;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(22041, 66) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlaySound::TRIGGER_DONE, 67, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(22041, 66) {
    auto node66 = GET_SKILL_NODE(66, PhaseNode_PlaySound);
    if (node66 == nullptr) {
        node66 = new PhaseNode_PlaySound(66, phase);
        node66->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node66->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node66->setSoundID("SE_MON2205_ATK1_P1");
        node66->setTarget(0U);
        node66->setUsePos(false);
        node66->setPosX(.00f);
        node66->setPosY(.00f);
        node66->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(22041, 66, node66)
    }
    if (noInit == true) {
        return node66;
    }
    return node66;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22041, 67) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_Delay::TRIGGER_DONE, 68, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(22041, 67) {
    auto node67 = GET_SKILL_NODE(67, PhaseNode_Delay);
    if (node67 == nullptr) {
        node67 = new PhaseNode_Delay(67, phase);
        node67->setTime(.30f);
        CALL_REGISTER_SKILL_NODE(22041, 67, node67)
    }
    if (noInit == true) {
        return node67;
    }
    return node67;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(22041, 68) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetRotation>(PhaseNode_GetLocation::TRIGGER_DONE, 69, PhaseNode_GetRotation::FUNC_DO, &PhaseNode_GetRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(22041, 68) {
    auto node68 = GET_SKILL_NODE(68, PhaseNode_GetLocation);
    if (node68 == nullptr) {
        node68 = new PhaseNode_GetLocation(68, phase);
        node68->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node68->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(22041, 68, node68)
    }
    if (noInit == true) {
        return node68;
    }
    return node68;
}
//--------------------------------------------------------------------------------
// GetRotation
//
REGISTER_REGISTER_SKILL_NODE(22041, 69) {
    pnode->resizeTrigger(PhaseNode_GetRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_OffsetCalculate>(PhaseNode_GetRotation::TRIGGER_DONE, 70, PhaseNode_OffsetCalculate::FUNC_DO, &PhaseNode_OffsetCalculate::Do);
}

REGISTER_CREATE_SKILL_NODE(22041, 69) {
    auto node69 = GET_SKILL_NODE(69, PhaseNode_GetRotation);
    if (node69 == nullptr) {
        node69 = new PhaseNode_GetRotation(69, phase);
        node69->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node69->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(22041, 69, node69)
    }
    if (noInit == true) {
        return node69;
    }
    return node69;
}
//--------------------------------------------------------------------------------
// OffsetCalculate
//
REGISTER_REGISTER_SKILL_NODE(22041, 70) {
    pnode->resizeTrigger(PhaseNode_OffsetCalculate::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 72, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(22041, 70) {
    auto node70 = GET_SKILL_NODE(70, PhaseNode_OffsetCalculate);
    if (node70 == nullptr) {
        node70 = new PhaseNode_OffsetCalculate(70, phase);
        node70->setPosZ(.00f);
        node70->setOffsetX(1.66f);
        node70->setOffsetY(.43f);
        node70->setOffsetZ(3.00f);
        node70->setRotOffset(.00f);
        CALL_REGISTER_SKILL_NODE(22041, 70, node70)
    }
    if (noInit == true) {
        return node70;
    }
    auto node68 = GET_SKILL_NODE(68, PhaseNode_GetLocation);
    auto node69 = GET_SKILL_NODE(69, PhaseNode_GetRotation);
    if (node68 != nullptr) node70->setPosX(node68->getX());
    if (node68 != nullptr) node70->setPosY(node68->getY());
    if (node69 != nullptr) node70->setRotation(node69->getAngle());
    return node70;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(22041, 71) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_PlayEffect::TRIGGER_DONE, 74, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(22041, 71) {
    auto node71 = GET_SKILL_NODE(71, PhaseNode_PlayEffect);
    if (node71 == nullptr) {
        node71 = new PhaseNode_PlayEffect(71, phase);
        node71->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node71->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node71->setEffectID(0);
        node71->setChangeColor(false);
        node71->setType(PhaseNode_PlayEffect::PlayEffect_Type::WithTarget);
        node71->getVars().reserve(5);
        node71->getVars().setVariable<uint64_t>(0, 0U);
        node71->getVars().setVariable<std::string>(1, "");
        node71->getVars().setVariable<float>(2, .00f);
        node71->getVars().setVariable<float>(3, .00f);
        node71->getVars().setVariable<float>(4, .00f);
        node71->setScale(.00f);
        CALL_REGISTER_SKILL_NODE(22041, 71, node71)
    }
    if (noInit == true) {
        return node71;
    }
    auto node70 = GET_SKILL_NODE(70, PhaseNode_OffsetCalculate);
    if (node70 != nullptr) node71->getVars().setVariable<float>(2, node70->getOutPosX());
    if (node70 != nullptr) node71->getVars().setVariable<float>(3, node70->getOutPosY());
    if (node70 != nullptr) node71->getVars().setVariable<float>(4, node70->getOutPosZ());
    if (node70 != nullptr) node71->setRotation(node70->getOutRotation());
    return node71;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(22041, 72) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_FALSE, 73, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_TRUE, 71, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(22041, 72) {
    auto node72 = GET_SKILL_NODE(72, PhaseNode_If);
    if (node72 == nullptr) {
        node72 = new PhaseNode_If(72, phase);
        node72->setCondition(false);
        CALL_REGISTER_SKILL_NODE(22041, 72, node72)
    }
    if (noInit == true) {
        return node72;
    }
    return node72;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(22041, 73) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_PlayEffect::TRIGGER_DONE, 74, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(22041, 73) {
    auto node73 = GET_SKILL_NODE(73, PhaseNode_PlayEffect);
    if (node73 == nullptr) {
        node73 = new PhaseNode_PlayEffect(73, phase);
        node73->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node73->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node73->setEffectID(0);
        node73->setChangeColor(false);
        node73->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node73->getVars().reserve(3);
        node73->getVars().setVariable<float>(0, .00f);
        node73->getVars().setVariable<float>(1, .00f);
        node73->getVars().setVariable<float>(2, .00f);
        node73->setScale(.00f);
        CALL_REGISTER_SKILL_NODE(22041, 73, node73)
    }
    if (noInit == true) {
        return node73;
    }
    auto node70 = GET_SKILL_NODE(70, PhaseNode_OffsetCalculate);
    if (node70 != nullptr) node73->getVars().setVariable<float>(0, node70->getOutPosX());
    if (node70 != nullptr) node73->getVars().setVariable<float>(1, node70->getOutPosY());
    if (node70 != nullptr) node73->getVars().setVariable<float>(2, node70->getOutPosZ());
    if (node70 != nullptr) node73->setRotation(node70->getOutRotation());
    return node73;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(22041, 74) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetBBParamUInt64>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 59, PhaseNode_GetBBParamUInt64::FUNC_DO, &PhaseNode_GetBBParamUInt64::Do);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_LESS, 75, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_GetBBParamUInt64>(PhaseNode_CompareFloat::TRIGGER_LESS, 59, PhaseNode_GetBBParamUInt64::FUNC_DO, &PhaseNode_GetBBParamUInt64::Do);
}

REGISTER_CREATE_SKILL_NODE(22041, 74) {
    auto node74 = GET_SKILL_NODE(74, PhaseNode_CompareFloat);
    if (node74 == nullptr) {
        node74 = new PhaseNode_CompareFloat(74, phase);
        node74->setA(.00f);
        node74->setB(.00f);
        CALL_REGISTER_SKILL_NODE(22041, 74, node74)
    }
    if (noInit == true) {
        return node74;
    }
    return node74;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22041, 75) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StopEffect>(PhaseNode_Delay::TRIGGER_DONE, 76, PhaseNode_StopEffect::FUNC_DO, &PhaseNode_StopEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(22041, 75) {
    auto node75 = GET_SKILL_NODE(75, PhaseNode_Delay);
    if (node75 == nullptr) {
        node75 = new PhaseNode_Delay(75, phase);
        node75->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(22041, 75, node75)
    }
    if (noInit == true) {
        return node75;
    }
    return node75;
}
//--------------------------------------------------------------------------------
// StopEffect
//
REGISTER_REGISTER_SKILL_NODE(22041, 76) {
}

REGISTER_CREATE_SKILL_NODE(22041, 76) {
    auto node76 = GET_SKILL_NODE(76, PhaseNode_StopEffect);
    if (node76 == nullptr) {
        node76 = new PhaseNode_StopEffect(76, phase);
        node76->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node76->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node76->setEffectID(0);
        CALL_REGISTER_SKILL_NODE(22041, 76, node76)
    }
    if (noInit == true) {
        return node76;
    }
    return node76;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22041, 77) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_Delay::TRIGGER_DONE, 79, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(22041, 77) {
    auto node77 = GET_SKILL_NODE(77, PhaseNode_Delay);
    if (node77 == nullptr) {
        node77 = new PhaseNode_Delay(77, phase);
        node77->setTime(.50f);
        CALL_REGISTER_SKILL_NODE(22041, 77, node77)
    }
    if (noInit == true) {
        return node77;
    }
    return node77;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(22041, 78) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 22, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(22041, 78) {
    auto node78 = GET_SKILL_NODE(78, PhaseNode_SkillEndNotify);
    if (node78 == nullptr) {
        node78 = new PhaseNode_SkillEndNotify(78, phase);
        node78->setReturnType(false);
        CALL_REGISTER_SKILL_NODE(22041, 78, node78)
    }
    if (noInit == true) {
        return node78;
    }
    return node78;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(22041, 79) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_FALSE, 80, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_TRUE, 78, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
}

REGISTER_CREATE_SKILL_NODE(22041, 79) {
    auto node79 = GET_SKILL_NODE(79, PhaseNode_If);
    if (node79 == nullptr) {
        node79 = new PhaseNode_If(79, phase);
        node79->setCondition(false);
        CALL_REGISTER_SKILL_NODE(22041, 79, node79)
    }
    if (noInit == true) {
        return node79;
    }
    return node79;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(22041, 80) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 22, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(22041, 80) {
    auto node80 = GET_SKILL_NODE(80, PhaseNode_SkillEndNotify);
    if (node80 == nullptr) {
        node80 = new PhaseNode_SkillEndNotify(80, phase);
        node80->setReturnType(true);
        CALL_REGISTER_SKILL_NODE(22041, 80, node80)
    }
    if (noInit == true) {
        return node80;
    }
    return node80;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(22041, 81) {
}

REGISTER_CREATE_SKILL_NODE(22041, 81) {
    auto node81 = GET_SKILL_NODE(81, PhaseNode_RaiseEvent);
    if (node81 == nullptr) {
        node81 = new PhaseNode_RaiseEvent(81, phase);
        node81->setEvent("MonsterInterrupt");
        node81->setTarget(0U);
        node81->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node81->setTypeParams(0, 0);
        node81->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(22041, 81, node81)
    }
    if (noInit == true) {
        return node81;
    }
    return node81;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(22041, 82) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_Detect::TRIGGER_ON, 85, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(22041, 82) {
    auto node82 = GET_SKILL_NODE(82, PhaseNode_Detect);
    if (node82 == nullptr) {
        node82 = new PhaseNode_Detect(82, phase);
        node82->setSelf(0U);
        node82->setEvent("MonsterInterrupt");
        node82->setType(PhaseNode_Detect::Detect_Type::Interrupt_Skill);
        node82->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(22041, 82, node82)
    }
    if (noInit == true) {
        return node82;
    }
    return node82;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(22041, 83) {
}

REGISTER_CREATE_SKILL_NODE(22041, 83) {
    auto node83 = GET_SKILL_NODE(83, PhaseNode_EndPhase);
    if (node83 == nullptr) {
        node83 = new PhaseNode_EndPhase(83, phase);
        node83->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node83->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(22041, 83, node83)
    }
    if (noInit == true) {
        return node83;
    }
    return node83;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22041, 85) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_Delay::TRIGGER_DONE, 87, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(22041, 85) {
    auto node85 = GET_SKILL_NODE(85, PhaseNode_Delay);
    if (node85 == nullptr) {
        node85 = new PhaseNode_Delay(85, phase);
        node85->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(22041, 85, node85)
    }
    if (noInit == true) {
        return node85;
    }
    return node85;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(22041, 86) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 83, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(22041, 86) {
    auto node86 = GET_SKILL_NODE(86, PhaseNode_SkillEndNotify);
    if (node86 == nullptr) {
        node86 = new PhaseNode_SkillEndNotify(86, phase);
        node86->setReturnType(false);
        CALL_REGISTER_SKILL_NODE(22041, 86, node86)
    }
    if (noInit == true) {
        return node86;
    }
    return node86;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(22041, 87) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_FALSE, 88, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_TRUE, 86, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
}

REGISTER_CREATE_SKILL_NODE(22041, 87) {
    auto node87 = GET_SKILL_NODE(87, PhaseNode_If);
    if (node87 == nullptr) {
        node87 = new PhaseNode_If(87, phase);
        node87->setCondition(false);
        CALL_REGISTER_SKILL_NODE(22041, 87, node87)
    }
    if (noInit == true) {
        return node87;
    }
    return node87;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(22041, 88) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 83, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(22041, 88) {
    auto node88 = GET_SKILL_NODE(88, PhaseNode_SkillEndNotify);
    if (node88 == nullptr) {
        node88 = new PhaseNode_SkillEndNotify(88, phase);
        node88->setReturnType(true);
        CALL_REGISTER_SKILL_NODE(22041, 88, node88)
    }
    if (noInit == true) {
        return node88;
    }
    return node88;
}

//--------------------------------------------------------------------------------
// SkillCreator_22041
//
class SkillCreator_22041 : public SkillCreator {
public:
    SkillCreator_22041() {}
    virtual ~SkillCreator_22041() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_22041

//--------------------------------------------------------------------------------
// SkillPhase_22041
//
class SkillPhase_22041 : public SkillPhase {
public:
    SkillPhase_22041(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_22041() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(22041, 2) // StartPhase
        CASE_CREATE_SKILL_NODE(22041, 6) // TriggerUpdate
        CASE_CREATE_SKILL_NODE(22041, 22) // EndPhase
        CASE_CREATE_SKILL_NODE(22041, 25) // Detect
        CASE_CREATE_SKILL_NODE(22041, 27) // EndPhase
        CASE_CREATE_SKILL_NODE(22041, 47) // SpawnProjectile
        CASE_CREATE_SKILL_NODE(22041, 59) // GetBBParamUInt64
        CASE_CREATE_SKILL_NODE(22041, 61) // GetLocation
        CASE_CREATE_SKILL_NODE(22041, 62) // Delay
        CASE_CREATE_SKILL_NODE(22041, 63) // PlaySound
        CASE_CREATE_SKILL_NODE(22041, 64) // ResetCD
        CASE_CREATE_SKILL_NODE(22041, 65) // PlayAnimation
        CASE_CREATE_SKILL_NODE(22041, 66) // PlaySound
        CASE_CREATE_SKILL_NODE(22041, 67) // Delay
        CASE_CREATE_SKILL_NODE(22041, 68) // GetLocation
        CASE_CREATE_SKILL_NODE(22041, 69) // GetRotation
        CASE_CREATE_SKILL_NODE(22041, 70) // OffsetCalculate
        CASE_CREATE_SKILL_NODE(22041, 71) // PlayEffect
        CASE_CREATE_SKILL_NODE(22041, 72) // If
        CASE_CREATE_SKILL_NODE(22041, 73) // PlayEffect
        CASE_CREATE_SKILL_NODE(22041, 74) // CompareFloat
        CASE_CREATE_SKILL_NODE(22041, 75) // Delay
        CASE_CREATE_SKILL_NODE(22041, 76) // StopEffect
        CASE_CREATE_SKILL_NODE(22041, 77) // Delay
        CASE_CREATE_SKILL_NODE(22041, 78) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(22041, 79) // If
        CASE_CREATE_SKILL_NODE(22041, 80) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(22041, 81) // RaiseEvent
        CASE_CREATE_SKILL_NODE(22041, 82) // Detect
        CASE_CREATE_SKILL_NODE(22041, 83) // EndPhase
        CASE_CREATE_SKILL_NODE(22041, 85) // Delay
        CASE_CREATE_SKILL_NODE(22041, 86) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(22041, 87) // If
        CASE_CREATE_SKILL_NODE(22041, 88) // SkillEndNotify
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_22041

SkillLogic* SkillCreator_22041::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //创建阶段phase
    auto phase = new SkillPhase_22041(1, logic, 3);
    //设置phase执行器
    phase->setRunPhaseNode(1, 2);
    phase->setRunPhaseNode(2, 6);
    phase->setDetectPhaseNode(3, 25);
    phase->setDetectPhaseNode(3, 82);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_22041::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
