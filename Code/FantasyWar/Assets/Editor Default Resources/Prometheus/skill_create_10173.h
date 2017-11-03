#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

#include "skill_psnode_delay.h"
#include "skill_psnode_detect.h"
#include "skill_psnode_disable.h"
#include "skill_psnode_endphase.h"
#include "skill_psnode_floatoperation.h"
#include "skill_psnode_for.h"
#include "skill_psnode_forcontinue.h"
#include "skill_psnode_getactorattribute.h"
#include "skill_psnode_getinputrotation.h"
#include "skill_psnode_getlocation.h"
#include "skill_psnode_if.h"
#include "skill_psnode_int2float.h"
#include "skill_psnode_isinterrupttype.h"
#include "skill_psnode_offsetcalculate.h"
#include "skill_psnode_playanimation.h"
#include "skill_psnode_playeffect.h"
#include "skill_psnode_playsound.h"
#include "skill_psnode_raiseevent.h"
#include "skill_psnode_resetcd.h"
#include "skill_psnode_setbool.h"
#include "skill_psnode_spawnprojectile.h"
#include "skill_psnode_startphase.h"
#include "skill_psnode_startpreinput.h"
#include "skill_psnode_switchtoint.h"

namespace pvp {

//变量声明
uint64_t Variable_10173_a101731 = 0;
uint64_t Variable_10173_InterruptAnimat = 0;
//--------------------------------------------------------------------------------
// StartPhase
//
REGISTER_REGISTER_SKILL_NODE(10173, 4) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_StartPhase::TRIGGER_START, 179, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(10173, 4) {
    auto node4 = GET_SKILL_NODE(4, PhaseNode_StartPhase);
    if (node4 == nullptr) {
        node4 = new PhaseNode_StartPhase(4, phase);
        CALL_REGISTER_SKILL_NODE(10173, 4, node4)
    }
    if (noInit == true) {
        return node4;
    }
    return node4;
}
//--------------------------------------------------------------------------------
// Disable
//
REGISTER_REGISTER_SKILL_NODE(10173, 8) {
    pnode->resizeTrigger(PhaseNode_Disable::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_Disable::TRIGGER_DONE, 168, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10173, 8) {
    auto node8 = GET_SKILL_NODE(8, PhaseNode_Disable);
    if (node8 == nullptr) {
        node8 = new PhaseNode_Disable(8, phase);
        node8->setTarget(0U);
        node8->setMove(true);
        node8->setSkill(true);
        node8->setShoot(true);
        node8->setTime(1.15f);
        node8->setRotate(true);
        CALL_REGISTER_SKILL_NODE(10173, 8, node8)
    }
    if (noInit == true) {
        return node8;
    }
    return node8;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10173, 111) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_For>(PhaseNode_Delay::TRIGGER_DONE, 143, PhaseNode_For::FUNC_START, &PhaseNode_For::Start);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_Delay::TRIGGER_DONE, 153, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_Delay::TRIGGER_DONE, 163, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
    pnode->regTrigger<PhaseNode_SpawnProjectile>(PhaseNode_Delay::TRIGGER_DONE, 151, PhaseNode_SpawnProjectile::FUNC_DO, &PhaseNode_SpawnProjectile::Do);
}

REGISTER_CREATE_SKILL_NODE(10173, 111) {
    auto node111 = GET_SKILL_NODE(111, PhaseNode_Delay);
    if (node111 == nullptr) {
        node111 = new PhaseNode_Delay(111, phase);
        node111->setTime(.52f);
        CALL_REGISTER_SKILL_NODE(10173, 111, node111)
    }
    if (noInit == true) {
        return node111;
    }
    return node111;
}
//--------------------------------------------------------------------------------
// SpawnProjectile
//
REGISTER_REGISTER_SKILL_NODE(10173, 129) {
    pnode->resizeTrigger(PhaseNode_SpawnProjectile::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ForContinue>(PhaseNode_SpawnProjectile::TRIGGER_DONE, 145, PhaseNode_ForContinue::FUNC_DO, &PhaseNode_ForContinue::Do);
}

REGISTER_CREATE_SKILL_NODE(10173, 129) {
    auto node129 = GET_SKILL_NODE(129, PhaseNode_SpawnProjectile);
    if (node129 == nullptr) {
        node129 = new PhaseNode_SpawnProjectile(129, phase);
        node129->setDataId(55174);
        node129->setPosZ(.00f);
        node129->setEndPosX(.00f);
        node129->setEndPosY(.00f);
        node129->setEndPosZ(.00f);
        node129->setMaxCount(0);
        CALL_REGISTER_SKILL_NODE(10173, 129, node129)
    }
    if (noInit == true) {
        return node129;
    }
    auto node137 = GET_SKILL_NODE(137, PhaseNode_OffsetCalculate);
    auto node135 = GET_SKILL_NODE(135, PhaseNode_GetInputRotation);
    if (node137 != nullptr) node129->setPosX(node137->getOutPosX());
    if (node137 != nullptr) node129->setPosY(node137->getOutPosY());
    if (node135 != nullptr) node129->setRotation(node135->getAngle());
    return node129;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(10173, 131) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetInputRotation>(PhaseNode_GetLocation::TRIGGER_DONE, 135, PhaseNode_GetInputRotation::FUNC_DO, &PhaseNode_GetInputRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(10173, 131) {
    auto node131 = GET_SKILL_NODE(131, PhaseNode_GetLocation);
    if (node131 == nullptr) {
        node131 = new PhaseNode_GetLocation(131, phase);
        node131->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node131->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(10173, 131, node131)
    }
    if (noInit == true) {
        return node131;
    }
    return node131;
}
//--------------------------------------------------------------------------------
// GetInputRotation
//
REGISTER_REGISTER_SKILL_NODE(10173, 135) {
    pnode->resizeTrigger(PhaseNode_GetInputRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_GetInputRotation::TRIGGER_DONE, 111, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_GetInputRotation::TRIGGER_DONE, 155, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(10173, 135) {
    auto node135 = GET_SKILL_NODE(135, PhaseNode_GetInputRotation);
    if (node135 == nullptr) {
        node135 = new PhaseNode_GetInputRotation(135, phase);
        node135->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        CALL_REGISTER_SKILL_NODE(10173, 135, node135)
    }
    if (noInit == true) {
        return node135;
    }
    return node135;
}
//--------------------------------------------------------------------------------
// OffsetCalculate
//
REGISTER_REGISTER_SKILL_NODE(10173, 137) {
    pnode->resizeTrigger(PhaseNode_OffsetCalculate::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnProjectile>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 129, PhaseNode_SpawnProjectile::FUNC_DO, &PhaseNode_SpawnProjectile::Do);
}

REGISTER_CREATE_SKILL_NODE(10173, 137) {
    auto node137 = GET_SKILL_NODE(137, PhaseNode_OffsetCalculate);
    if (node137 == nullptr) {
        node137 = new PhaseNode_OffsetCalculate(137, phase);
        node137->setPosZ(.00f);
        node137->setOffsetY(.00f);
        node137->setOffsetZ(.00f);
        node137->setRotOffset(.00f);
        CALL_REGISTER_SKILL_NODE(10173, 137, node137)
    }
    if (noInit == true) {
        return node137;
    }
    auto node131 = GET_SKILL_NODE(131, PhaseNode_GetLocation);
    auto node149 = GET_SKILL_NODE(149, PhaseNode_FloatOperation);
    auto node135 = GET_SKILL_NODE(135, PhaseNode_GetInputRotation);
    if (node131 != nullptr) node137->setPosX(node131->getX());
    if (node131 != nullptr) node137->setPosY(node131->getY());
    if (node149 != nullptr) node137->setOffsetX(node149->getFinal());
    if (node135 != nullptr) node137->setRotation(node135->getAngle());
    return node137;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10173, 139) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_Delay::TRIGGER_DONE, 141, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(10173, 139) {
    auto node139 = GET_SKILL_NODE(139, PhaseNode_Delay);
    if (node139 == nullptr) {
        node139 = new PhaseNode_Delay(139, phase);
        node139->setTime(.74f);
        CALL_REGISTER_SKILL_NODE(10173, 139, node139)
    }
    if (noInit == true) {
        return node139;
    }
    return node139;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(10173, 141) {
}

REGISTER_CREATE_SKILL_NODE(10173, 141) {
    auto node141 = GET_SKILL_NODE(141, PhaseNode_EndPhase);
    if (node141 == nullptr) {
        node141 = new PhaseNode_EndPhase(141, phase);
        node141->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node141->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10173, 141, node141)
    }
    if (noInit == true) {
        return node141;
    }
    return node141;
}
//--------------------------------------------------------------------------------
// For
//
REGISTER_REGISTER_SKILL_NODE(10173, 143) {
    pnode->resizeTrigger(PhaseNode_For::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Int2Float>(PhaseNode_For::TRIGGER_DO, 147, PhaseNode_Int2Float::FUNC_DO, &PhaseNode_Int2Float::Do);
}

REGISTER_CREATE_SKILL_NODE(10173, 143) {
    auto node143 = GET_SKILL_NODE(143, PhaseNode_For);
    if (node143 == nullptr) {
        node143 = new PhaseNode_For(143, phase);
        node143->setBegin(-2);
        node143->setIncrease(1);
        node143->setEnd(3);
        CALL_REGISTER_SKILL_NODE(10173, 143, node143)
    }
    if (noInit == true) {
        return node143;
    }
    return node143;
}
//--------------------------------------------------------------------------------
// ForContinue
//
REGISTER_REGISTER_SKILL_NODE(10173, 145) {
}

REGISTER_CREATE_SKILL_NODE(10173, 145) {
    auto node145 = GET_SKILL_NODE(145, PhaseNode_ForContinue);
    if (node145 == nullptr) {
        node145 = new PhaseNode_ForContinue(145, phase);
        CALL_REGISTER_SKILL_NODE(10173, 145, node145)
    }
    if (noInit == true) {
        return node145;
    }
    auto node143 = GET_SKILL_NODE(143, PhaseNode_For);
    if (node143 != nullptr) node145->setFID(node143->getFID());
    return node145;
}
//--------------------------------------------------------------------------------
// Int2Float
//
REGISTER_REGISTER_SKILL_NODE(10173, 147) {
    pnode->resizeTrigger(PhaseNode_Int2Float::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_FloatOperation>(PhaseNode_Int2Float::TRIGGER_DONE, 149, PhaseNode_FloatOperation::FUNC_OPERATION, &PhaseNode_FloatOperation::Operation);
}

REGISTER_CREATE_SKILL_NODE(10173, 147) {
    auto node147 = GET_SKILL_NODE(147, PhaseNode_Int2Float);
    if (node147 == nullptr) {
        node147 = new PhaseNode_Int2Float(147, phase);
        CALL_REGISTER_SKILL_NODE(10173, 147, node147)
    }
    if (noInit == true) {
        return node147;
    }
    auto node143 = GET_SKILL_NODE(143, PhaseNode_For);
    if (node143 != nullptr) node147->setInt(node143->getValue());
    return node147;
}
//--------------------------------------------------------------------------------
// FloatOperation
//
REGISTER_REGISTER_SKILL_NODE(10173, 149) {
    pnode->resizeTrigger(PhaseNode_FloatOperation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_OffsetCalculate>(PhaseNode_FloatOperation::TRIGGER_DONE, 137, PhaseNode_OffsetCalculate::FUNC_DO, &PhaseNode_OffsetCalculate::Do);
}

REGISTER_CREATE_SKILL_NODE(10173, 149) {
    auto node149 = GET_SKILL_NODE(149, PhaseNode_FloatOperation);
    if (node149 == nullptr) {
        node149 = new PhaseNode_FloatOperation(149, phase);
        node149->setValue(1.60f);
        node149->setMethod(PhaseNode_FloatOperation::FloatOperation_Method::Multi);
        CALL_REGISTER_SKILL_NODE(10173, 149, node149)
    }
    if (noInit == true) {
        return node149;
    }
    auto node147 = GET_SKILL_NODE(147, PhaseNode_Int2Float);
    if (node147 != nullptr) node149->setBase(node147->getFloat());
    return node149;
}
//--------------------------------------------------------------------------------
// SpawnProjectile
//
REGISTER_REGISTER_SKILL_NODE(10173, 151) {
}

REGISTER_CREATE_SKILL_NODE(10173, 151) {
    auto node151 = GET_SKILL_NODE(151, PhaseNode_SpawnProjectile);
    if (node151 == nullptr) {
        node151 = new PhaseNode_SpawnProjectile(151, phase);
        node151->setDataId(55173);
        node151->setPosZ(.00f);
        node151->setEndPosX(.00f);
        node151->setEndPosY(.00f);
        node151->setEndPosZ(.00f);
        node151->setMaxCount(0);
        CALL_REGISTER_SKILL_NODE(10173, 151, node151)
    }
    if (noInit == true) {
        return node151;
    }
    auto node131 = GET_SKILL_NODE(131, PhaseNode_GetLocation);
    auto node135 = GET_SKILL_NODE(135, PhaseNode_GetInputRotation);
    if (node131 != nullptr) node151->setPosX(node131->getX());
    if (node131 != nullptr) node151->setPosY(node131->getY());
    if (node135 != nullptr) node151->setRotation(node135->getAngle());
    return node151;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(10173, 153) {
}

REGISTER_CREATE_SKILL_NODE(10173, 153) {
    auto node153 = GET_SKILL_NODE(153, PhaseNode_PlayEffect);
    if (node153 == nullptr) {
        node153 = new PhaseNode_PlayEffect(153, phase);
        node153->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node153->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node153->setEffectID(101734);
        node153->setChangeColor(false);
        node153->setType(PhaseNode_PlayEffect::PlayEffect_Type::WithTarget);
        node153->getVars().reserve(6);
        node153->getVars().setVariable<uint64_t>(0, 0U);
        node153->getVars().setVariable<std::string>(1, "Bip001 R Hand");
        node153->getVars().setVariable<float>(2, .00f);
        node153->getVars().setVariable<float>(3, .00f);
        node153->getVars().setVariable<float>(4, .00f);
        node153->getVars().setVariable<bool>(5, false);
        node153->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(10173, 153, node153)
    }
    if (noInit == true) {
        return node153;
    }
    auto node135 = GET_SKILL_NODE(135, PhaseNode_GetInputRotation);
    if (node135 != nullptr) node153->setRotation(node135->getAngle());
    return node153;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(10173, 155) {
}

REGISTER_CREATE_SKILL_NODE(10173, 155) {
    auto node155 = GET_SKILL_NODE(155, PhaseNode_PlayEffect);
    if (node155 == nullptr) {
        node155 = new PhaseNode_PlayEffect(155, phase);
        node155->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node155->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node155->setEffectID(101733);
        node155->setChangeColor(false);
        node155->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node155->getVars().reserve(3);
        node155->getVars().setVariable<float>(0, .00f);
        node155->getVars().setVariable<float>(1, .00f);
        node155->getVars().setVariable<float>(2, .00f);
        node155->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(10173, 155, node155)
    }
    if (noInit == true) {
        return node155;
    }
    auto node131 = GET_SKILL_NODE(131, PhaseNode_GetLocation);
    auto node135 = GET_SKILL_NODE(135, PhaseNode_GetInputRotation);
    if (node131 != nullptr) node155->getVars().setVariable<float>(0, node131->getX());
    if (node131 != nullptr) node155->getVars().setVariable<float>(1, node131->getY());
    if (node135 != nullptr) node155->setRotation(node135->getAngle());
    return node155;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10173, 157) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Disable>(PhaseNode_PlaySound::TRIGGER_DONE, 8, PhaseNode_Disable::FUNC_DO, &PhaseNode_Disable::Do);
}

REGISTER_CREATE_SKILL_NODE(10173, 157) {
    auto node157 = GET_SKILL_NODE(157, PhaseNode_PlaySound);
    if (node157 == nullptr) {
        node157 = new PhaseNode_PlaySound(157, phase);
        node157->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node157->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node157->setSoundID("SE_Hero114_SkillC_P1");
        node157->setTarget(0U);
        node157->setUsePos(false);
        node157->setPosX(.00f);
        node157->setPosY(.00f);
        node157->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10173, 157, node157)
    }
    if (noInit == true) {
        return node157;
    }
    return node157;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10173, 163) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlaySound::TRIGGER_DONE, 139, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10173, 163) {
    auto node163 = GET_SKILL_NODE(163, PhaseNode_PlaySound);
    if (node163 == nullptr) {
        node163 = new PhaseNode_PlaySound(163, phase);
        node163->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node163->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node163->setSoundID("SE_Hero114_SkillC_P2");
        node163->setTarget(0U);
        node163->setUsePos(false);
        node163->setPosX(.00f);
        node163->setPosY(.00f);
        node163->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10173, 163, node163)
    }
    if (noInit == true) {
        return node163;
    }
    return node163;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10173, 165) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_IsInterruptType>(PhaseNode_Detect::TRIGGER_ON, 171, PhaseNode_IsInterruptType::FUNC_DO, &PhaseNode_IsInterruptType::Do);
}

REGISTER_CREATE_SKILL_NODE(10173, 165) {
    auto node165 = GET_SKILL_NODE(165, PhaseNode_Detect);
    if (node165 == nullptr) {
        node165 = new PhaseNode_Detect(165, phase);
        node165->setSelf(0U);
        node165->setEvent("daduan_001");
        node165->setType(PhaseNode_Detect::Detect_Type::Interrupt_Skill);
        node165->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10173, 165, node165)
    }
    if (noInit == true) {
        return node165;
    }
    return node165;
}
//--------------------------------------------------------------------------------
// SwitchToInt
//
REGISTER_REGISTER_SKILL_NODE(10173, 166) {
    pnode->resizeTrigger(4);
    pnode->regTrigger<PhaseNode_EndPhase>(1, 141, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(10173, 166) {
    auto node166 = GET_SKILL_NODE(166, PhaseNode_SwitchToInt);
    if (node166 == nullptr) {
        node166 = new PhaseNode_SwitchToInt(166, phase);
        CALL_REGISTER_SKILL_NODE(10173, 166, node166)
    }
    if (noInit == true) {
        return node166;
    }
    auto variables = node166->getVariables();
    if (variables != nullptr) {
        node166->setSelection(variables->getVariable<int32_t>(Variable_10173_a101731));
    }
    return node166;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10173, 168) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_RaiseEvent::TRIGGER_DONE, 177, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10173, 168) {
    auto node168 = GET_SKILL_NODE(168, PhaseNode_RaiseEvent);
    if (node168 == nullptr) {
        node168 = new PhaseNode_RaiseEvent(168, phase);
        node168->setEvent("daduan_001");
        node168->setTarget(0U);
        node168->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node168->setTypeParams(0, 0);
        node168->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10173, 168, node168)
    }
    if (noInit == true) {
        return node168;
    }
    return node168;
}
//--------------------------------------------------------------------------------
// StartPreInput
//
REGISTER_REGISTER_SKILL_NODE(10173, 169) {
    pnode->resizeTrigger(PhaseNode_StartPreInput::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_StartPreInput::TRIGGER_DONE, 173, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_StartPreInput::TRIGGER_DONE, 131, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(10173, 169) {
    auto node169 = GET_SKILL_NODE(169, PhaseNode_StartPreInput);
    if (node169 == nullptr) {
        node169 = new PhaseNode_StartPreInput(169, phase);
        node169->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node169->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node169->setDelayTime(.00f);
        CALL_REGISTER_SKILL_NODE(10173, 169, node169)
    }
    if (noInit == true) {
        return node169;
    }
    return node169;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(10173, 170) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_If::TRIGGER_TRUE, 172, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10173, 170) {
    auto node170 = GET_SKILL_NODE(170, PhaseNode_If);
    if (node170 == nullptr) {
        node170 = new PhaseNode_If(170, phase);
        CALL_REGISTER_SKILL_NODE(10173, 170, node170)
    }
    if (noInit == true) {
        return node170;
    }
    auto variables = node170->getVariables();
    if (variables != nullptr) {
        node170->setCondition(variables->getVariable<bool>(Variable_10173_InterruptAnimat));
    }
    return node170;
}
//--------------------------------------------------------------------------------
// IsInterruptType
//
REGISTER_REGISTER_SKILL_NODE(10173, 171) {
    pnode->resizeTrigger(PhaseNode_IsInterruptType::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SwitchToInt>(PhaseNode_IsInterruptType::TRIGGER_BUFF, 166, PhaseNode_SwitchToInt::FUNC_SWITCH, &PhaseNode_SwitchToInt::Switch);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_POSCHANGE, 170, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTAIM, 170, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTFIRE, 170, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTRELOAD, 170, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_USESKILL, 170, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(10173, 171) {
    auto node171 = GET_SKILL_NODE(171, PhaseNode_IsInterruptType);
    if (node171 == nullptr) {
        node171 = new PhaseNode_IsInterruptType(171, phase);
        node171->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node171->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10173, 171, node171)
    }
    if (noInit == true) {
        return node171;
    }
    auto node165 = GET_SKILL_NODE(165, PhaseNode_Detect);
    if (node165 != nullptr) node171->setType(node165->getVars().getVariable<int32_t>(2));
    return node171;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10173, 172) {
}

REGISTER_CREATE_SKILL_NODE(10173, 172) {
    auto node172 = GET_SKILL_NODE(172, PhaseNode_PlayAnimation);
    if (node172 == nullptr) {
        node172 = new PhaseNode_PlayAnimation(172, phase);
        node172->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node172->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node172->setTarget(0U);
        node172->setAnimation("Idle");
        node172->setParameter("");
        node172->setValue(false);
        CALL_REGISTER_SKILL_NODE(10173, 172, node172)
    }
    if (noInit == true) {
        return node172;
    }
    return node172;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10173, 173) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_Delay::TRIGGER_DONE, 176, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(10173, 173) {
    auto node173 = GET_SKILL_NODE(173, PhaseNode_Delay);
    if (node173 == nullptr) {
        node173 = new PhaseNode_Delay(173, phase);
        node173->setTime(.20f);
        CALL_REGISTER_SKILL_NODE(10173, 173, node173)
    }
    if (noInit == true) {
        return node173;
    }
    return node173;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(10173, 176) {
}

REGISTER_CREATE_SKILL_NODE(10173, 176) {
    auto node176 = GET_SKILL_NODE(176, PhaseNode_SetBool);
    if (node176 == nullptr) {
        node176 = new PhaseNode_SetBool(176, phase);
        node176->setName("InterruptAnimat");
        node176->setValue(true);
        CALL_REGISTER_SKILL_NODE(10173, 176, node176)
    }
    if (noInit == true) {
        return node176;
    }
    return node176;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10173, 177) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StartPreInput>(PhaseNode_RaiseEvent::TRIGGER_DONE, 169, PhaseNode_StartPreInput::FUNC_DO, &PhaseNode_StartPreInput::Do);
}

REGISTER_CREATE_SKILL_NODE(10173, 177) {
    auto node177 = GET_SKILL_NODE(177, PhaseNode_RaiseEvent);
    if (node177 == nullptr) {
        node177 = new PhaseNode_RaiseEvent(177, phase);
        node177->setEvent("Dead_001");
        node177->setTarget(0U);
        node177->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node177->setTypeParams(0, 0);
        node177->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10173, 177, node177)
    }
    if (noInit == true) {
        return node177;
    }
    return node177;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10173, 178) {
}

REGISTER_CREATE_SKILL_NODE(10173, 178) {
    auto node178 = GET_SKILL_NODE(178, PhaseNode_Detect);
    if (node178 == nullptr) {
        node178 = new PhaseNode_Detect(178, phase);
        node178->setSelf(0U);
        node178->setEvent("Dead_001");
        node178->setType(PhaseNode_Detect::Detect_Type::Actor_Dead);
        node178->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10173, 178, node178)
    }
    if (noInit == true) {
        return node178;
    }
    return node178;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(10173, 179) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_ResetCD::TRIGGER_DONE, 180, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10173, 179) {
    auto node179 = GET_SKILL_NODE(179, PhaseNode_ResetCD);
    if (node179 == nullptr) {
        node179 = new PhaseNode_ResetCD(179, phase);
        node179->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node179->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node179->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(10173, 179, node179)
    }
    if (noInit == true) {
        return node179;
    }
    return node179;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10173, 180) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_PlayAnimation::TRIGGER_DONE, 182, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(10173, 180) {
    auto node180 = GET_SKILL_NODE(180, PhaseNode_PlayAnimation);
    if (node180 == nullptr) {
        node180 = new PhaseNode_PlayAnimation(180, phase);
        node180->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node180->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node180->setTarget(0U);
        node180->setAnimation("Skill3S1");
        node180->setParameter("");
        node180->setValue(false);
        CALL_REGISTER_SKILL_NODE(10173, 180, node180)
    }
    if (noInit == true) {
        return node180;
    }
    return node180;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10173, 181) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_PlaySound::TRIGGER_DONE, 157, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10173, 181) {
    auto node181 = GET_SKILL_NODE(181, PhaseNode_PlaySound);
    if (node181 == nullptr) {
        node181 = new PhaseNode_PlaySound(181, phase);
        node181->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node181->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node181->setSoundID("");
        node181->setTarget(0U);
        node181->setUsePos(false);
        node181->setPosX(.00f);
        node181->setPosY(.00f);
        node181->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10173, 181, node181)
    }
    if (noInit == true) {
        return node181;
    }
    return node181;
}
//--------------------------------------------------------------------------------
// GetActorAttribute
//
REGISTER_REGISTER_SKILL_NODE(10173, 182) {
    pnode->resizeTrigger(PhaseNode_GetActorAttribute::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 181, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10173, 182) {
    auto node182 = GET_SKILL_NODE(182, PhaseNode_GetActorAttribute);
    if (node182 == nullptr) {
        node182 = new PhaseNode_GetActorAttribute(182, phase);
        node182->setTarget(0U);
        node182->setType({});
        CALL_REGISTER_SKILL_NODE(10173, 182, node182)
    }
    if (noInit == true) {
        return node182;
    }
    return node182;
}

//--------------------------------------------------------------------------------
// SkillCreator_10173
//
class SkillCreator_10173 : public SkillCreator {
public:
    SkillCreator_10173() {}
    virtual ~SkillCreator_10173() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_10173

//--------------------------------------------------------------------------------
// SkillPhase_10173
//
class SkillPhase_10173 : public SkillPhase {
public:
    SkillPhase_10173(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_10173() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(10173, 4) // StartPhase
        CASE_CREATE_SKILL_NODE(10173, 8) // Disable
        CASE_CREATE_SKILL_NODE(10173, 111) // Delay
        CASE_CREATE_SKILL_NODE(10173, 129) // SpawnProjectile
        CASE_CREATE_SKILL_NODE(10173, 131) // GetLocation
        CASE_CREATE_SKILL_NODE(10173, 135) // GetInputRotation
        CASE_CREATE_SKILL_NODE(10173, 137) // OffsetCalculate
        CASE_CREATE_SKILL_NODE(10173, 139) // Delay
        CASE_CREATE_SKILL_NODE(10173, 141) // EndPhase
        CASE_CREATE_SKILL_NODE(10173, 143) // For
        CASE_CREATE_SKILL_NODE(10173, 145) // ForContinue
        CASE_CREATE_SKILL_NODE(10173, 147) // Int2Float
        CASE_CREATE_SKILL_NODE(10173, 149) // FloatOperation
        CASE_CREATE_SKILL_NODE(10173, 151) // SpawnProjectile
        CASE_CREATE_SKILL_NODE(10173, 153) // PlayEffect
        CASE_CREATE_SKILL_NODE(10173, 155) // PlayEffect
        CASE_CREATE_SKILL_NODE(10173, 157) // PlaySound
        CASE_CREATE_SKILL_NODE(10173, 163) // PlaySound
        CASE_CREATE_SKILL_NODE(10173, 165) // Detect
        CASE_CREATE_SKILL_NODE(10173, 166) // SwitchToInt
        CASE_CREATE_SKILL_NODE(10173, 168) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10173, 169) // StartPreInput
        CASE_CREATE_SKILL_NODE(10173, 170) // If
        CASE_CREATE_SKILL_NODE(10173, 171) // IsInterruptType
        CASE_CREATE_SKILL_NODE(10173, 172) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10173, 173) // Delay
        CASE_CREATE_SKILL_NODE(10173, 176) // SetBool
        CASE_CREATE_SKILL_NODE(10173, 177) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10173, 178) // Detect
        CASE_CREATE_SKILL_NODE(10173, 179) // ResetCD
        CASE_CREATE_SKILL_NODE(10173, 180) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10173, 181) // PlaySound
        CASE_CREATE_SKILL_NODE(10173, 182) // GetActorAttribute
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_10173

SkillLogic* SkillCreator_10173::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //设置变量
    Variable_10173_a101731 = logic->getVariables().setVariable<int32_t>("a101731", 1);
    Variable_10173_InterruptAnimat = logic->getVariables().setVariable<bool>("InterruptAnimat");
    //创建阶段phase
    auto phase = new SkillPhase_10173(1, logic, 2);
    //设置phase执行器
    phase->setRunPhaseNode(1, 4);
    phase->setDetectPhaseNode(2, 165);
    phase->setDetectPhaseNode(2, 178);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_10173::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
