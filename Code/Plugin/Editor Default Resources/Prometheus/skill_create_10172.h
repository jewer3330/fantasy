#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

#include "skill_psnode_delay.h"
#include "skill_psnode_detect.h"
#include "skill_psnode_disable.h"
#include "skill_psnode_endphase.h"
#include "skill_psnode_findskillbuff.h"
#include "skill_psnode_for.h"
#include "skill_psnode_forcontinue.h"
#include "skill_psnode_getallobject.h"
#include "skill_psnode_getlocation.h"
#include "skill_psnode_getuint64svalue.h"
#include "skill_psnode_if.h"
#include "skill_psnode_isinterrupttype.h"
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
#include "skill_psnode_triggerupdate.h"
#include "skill_psnode_uint64ssize.h"

namespace pvp {

//变量声明
uint64_t Variable_10172_a101722 = 0;
uint64_t Variable_10172_InterruptAnimat = 0;
//--------------------------------------------------------------------------------
// StartPhase
//
REGISTER_REGISTER_SKILL_NODE(10172, 3) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_StartPhase::TRIGGER_START, 147, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10172, 3) {
    auto node3 = GET_SKILL_NODE(3, PhaseNode_StartPhase);
    if (node3 == nullptr) {
        node3 = new PhaseNode_StartPhase(3, phase);
        CALL_REGISTER_SKILL_NODE(10172, 3, node3)
    }
    if (noInit == true) {
        return node3;
    }
    return node3;
}
//--------------------------------------------------------------------------------
// TriggerUpdate
//
REGISTER_REGISTER_SKILL_NODE(10172, 5) {
}

REGISTER_CREATE_SKILL_NODE(10172, 5) {
    auto node5 = GET_SKILL_NODE(5, PhaseNode_TriggerUpdate);
    if (node5 == nullptr) {
        node5 = new PhaseNode_TriggerUpdate(5, phase);
        CALL_REGISTER_SKILL_NODE(10172, 5, node5)
    }
    if (noInit == true) {
        return node5;
    }
    return node5;
}
//--------------------------------------------------------------------------------
// Disable
//
REGISTER_REGISTER_SKILL_NODE(10172, 9) {
    pnode->resizeTrigger(PhaseNode_Disable::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_Disable::TRIGGER_DONE, 144, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_Disable::TRIGGER_DONE, 151, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_GetAllObject>(PhaseNode_Disable::TRIGGER_DONE, 120, PhaseNode_GetAllObject::FUNC_DO, &PhaseNode_GetAllObject::Do);
}

REGISTER_CREATE_SKILL_NODE(10172, 9) {
    auto node9 = GET_SKILL_NODE(9, PhaseNode_Disable);
    if (node9 == nullptr) {
        node9 = new PhaseNode_Disable(9, phase);
        node9->setTarget(0U);
        node9->setMove(true);
        node9->setSkill(true);
        node9->setShoot(true);
        node9->setTime(.80f);
        node9->setRotate(true);
        CALL_REGISTER_SKILL_NODE(10172, 9, node9)
    }
    if (noInit == true) {
        return node9;
    }
    return node9;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(10172, 90) {
}

REGISTER_CREATE_SKILL_NODE(10172, 90) {
    auto node90 = GET_SKILL_NODE(90, PhaseNode_EndPhase);
    if (node90 == nullptr) {
        node90 = new PhaseNode_EndPhase(90, phase);
        node90->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node90->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10172, 90, node90)
    }
    if (noInit == true) {
        return node90;
    }
    return node90;
}
//--------------------------------------------------------------------------------
// GetAllObject
//
REGISTER_REGISTER_SKILL_NODE(10172, 120) {
    pnode->resizeTrigger(PhaseNode_GetAllObject::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_UInt64sSize>(PhaseNode_GetAllObject::TRIGGER_DONE, 129, PhaseNode_UInt64sSize::FUNC_DO, &PhaseNode_UInt64sSize::Do);
}

REGISTER_CREATE_SKILL_NODE(10172, 120) {
    auto node120 = GET_SKILL_NODE(120, PhaseNode_GetAllObject);
    if (node120 == nullptr) {
        node120 = new PhaseNode_GetAllObject(120, phase);
        node120->setState(PhaseNode_GetAllObject::GetAllObject_State::Alive);
        node120->setCheckFaction(PhaseNode_GetAllObject::GetAllObject_CheckFaction::Enemy);
        node120->setOnHero(true);
        node120->setOnMinion(true);
        node120->setOnDestruct(false);
        CALL_REGISTER_SKILL_NODE(10172, 120, node120)
    }
    if (noInit == true) {
        return node120;
    }
    return node120;
}
//--------------------------------------------------------------------------------
// FindSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10172, 122) {
    pnode->resizeTrigger(PhaseNode_FindSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_FindSkillBuff::TRIGGER_DONE, 133, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(10172, 122) {
    auto node122 = GET_SKILL_NODE(122, PhaseNode_FindSkillBuff);
    if (node122 == nullptr) {
        node122 = new PhaseNode_FindSkillBuff(122, phase);
        node122->setSelfTarget(0U);
        node122->setConfigID(101747);
        CALL_REGISTER_SKILL_NODE(10172, 122, node122)
    }
    if (noInit == true) {
        return node122;
    }
    auto node131 = GET_SKILL_NODE(131, PhaseNode_GetUInt64sValue);
    if (node131 != nullptr) node122->setDetectTarget(node131->getValue());
    return node122;
}
//--------------------------------------------------------------------------------
// For
//
REGISTER_REGISTER_SKILL_NODE(10172, 127) {
    pnode->resizeTrigger(PhaseNode_For::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetUInt64sValue>(PhaseNode_For::TRIGGER_DO, 131, PhaseNode_GetUInt64sValue::FUNC_DO, &PhaseNode_GetUInt64sValue::Do);
}

REGISTER_CREATE_SKILL_NODE(10172, 127) {
    auto node127 = GET_SKILL_NODE(127, PhaseNode_For);
    if (node127 == nullptr) {
        node127 = new PhaseNode_For(127, phase);
        node127->setBegin(0);
        node127->setIncrease(1);
        CALL_REGISTER_SKILL_NODE(10172, 127, node127)
    }
    if (noInit == true) {
        return node127;
    }
    auto node129 = GET_SKILL_NODE(129, PhaseNode_UInt64sSize);
    if (node129 != nullptr) node127->setEnd(node129->getSize());
    return node127;
}
//--------------------------------------------------------------------------------
// UInt64sSize
//
REGISTER_REGISTER_SKILL_NODE(10172, 129) {
    pnode->resizeTrigger(PhaseNode_UInt64sSize::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_For>(PhaseNode_UInt64sSize::TRIGGER_DONE, 127, PhaseNode_For::FUNC_START, &PhaseNode_For::Start);
}

REGISTER_CREATE_SKILL_NODE(10172, 129) {
    auto node129 = GET_SKILL_NODE(129, PhaseNode_UInt64sSize);
    if (node129 == nullptr) {
        node129 = new PhaseNode_UInt64sSize(129, phase);
        CALL_REGISTER_SKILL_NODE(10172, 129, node129)
    }
    if (noInit == true) {
        return node129;
    }
    auto node120 = GET_SKILL_NODE(120, PhaseNode_GetAllObject);
    if (node120 != nullptr) node129->setArr(node120->getOutPut());
    return node129;
}
//--------------------------------------------------------------------------------
// GetUInt64sValue
//
REGISTER_REGISTER_SKILL_NODE(10172, 131) {
    pnode->resizeTrigger(PhaseNode_GetUInt64sValue::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_FindSkillBuff>(PhaseNode_GetUInt64sValue::TRIGGER_DONE, 122, PhaseNode_FindSkillBuff::FUNC_DO, &PhaseNode_FindSkillBuff::Do);
}

REGISTER_CREATE_SKILL_NODE(10172, 131) {
    auto node131 = GET_SKILL_NODE(131, PhaseNode_GetUInt64sValue);
    if (node131 == nullptr) {
        node131 = new PhaseNode_GetUInt64sValue(131, phase);
        CALL_REGISTER_SKILL_NODE(10172, 131, node131)
    }
    if (noInit == true) {
        return node131;
    }
    auto node120 = GET_SKILL_NODE(120, PhaseNode_GetAllObject);
    auto node127 = GET_SKILL_NODE(127, PhaseNode_For);
    if (node120 != nullptr) node131->setArr(node120->getOutPut());
    if (node127 != nullptr) node131->setIndex(node127->getValue());
    return node131;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(10172, 133) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ForContinue>(PhaseNode_If::TRIGGER_FALSE, 135, PhaseNode_ForContinue::FUNC_DO, &PhaseNode_ForContinue::Do);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_If::TRIGGER_TRUE, 140, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(10172, 133) {
    auto node133 = GET_SKILL_NODE(133, PhaseNode_If);
    if (node133 == nullptr) {
        node133 = new PhaseNode_If(133, phase);
        CALL_REGISTER_SKILL_NODE(10172, 133, node133)
    }
    if (noInit == true) {
        return node133;
    }
    auto node122 = GET_SKILL_NODE(122, PhaseNode_FindSkillBuff);
    if (node122 != nullptr) node133->setCondition(node122->getResult());
    return node133;
}
//--------------------------------------------------------------------------------
// ForContinue
//
REGISTER_REGISTER_SKILL_NODE(10172, 135) {
}

REGISTER_CREATE_SKILL_NODE(10172, 135) {
    auto node135 = GET_SKILL_NODE(135, PhaseNode_ForContinue);
    if (node135 == nullptr) {
        node135 = new PhaseNode_ForContinue(135, phase);
        CALL_REGISTER_SKILL_NODE(10172, 135, node135)
    }
    if (noInit == true) {
        return node135;
    }
    auto node127 = GET_SKILL_NODE(127, PhaseNode_For);
    if (node127 != nullptr) node135->setFID(node127->getFID());
    return node135;
}
//--------------------------------------------------------------------------------
// SpawnProjectile
//
REGISTER_REGISTER_SKILL_NODE(10172, 138) {
    pnode->resizeTrigger(PhaseNode_SpawnProjectile::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ForContinue>(PhaseNode_SpawnProjectile::TRIGGER_DONE, 135, PhaseNode_ForContinue::FUNC_DO, &PhaseNode_ForContinue::Do);
}

REGISTER_CREATE_SKILL_NODE(10172, 138) {
    auto node138 = GET_SKILL_NODE(138, PhaseNode_SpawnProjectile);
    if (node138 == nullptr) {
        node138 = new PhaseNode_SpawnProjectile(138, phase);
        node138->setDataId(55172);
        node138->setPosZ(.00f);
        node138->setEndPosX(.00f);
        node138->setEndPosY(.00f);
        node138->setEndPosZ(.00f);
        node138->setRotation(.00f);
        node138->setMaxCount(0);
        CALL_REGISTER_SKILL_NODE(10172, 138, node138)
    }
    if (noInit == true) {
        return node138;
    }
    auto node140 = GET_SKILL_NODE(140, PhaseNode_GetLocation);
    if (node140 != nullptr) node138->setPosX(node140->getX());
    if (node140 != nullptr) node138->setPosY(node140->getY());
    return node138;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(10172, 140) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnProjectile>(PhaseNode_GetLocation::TRIGGER_DONE, 138, PhaseNode_SpawnProjectile::FUNC_DO, &PhaseNode_SpawnProjectile::Do);
}

REGISTER_CREATE_SKILL_NODE(10172, 140) {
    auto node140 = GET_SKILL_NODE(140, PhaseNode_GetLocation);
    if (node140 == nullptr) {
        node140 = new PhaseNode_GetLocation(140, phase);
        node140->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        CALL_REGISTER_SKILL_NODE(10172, 140, node140)
    }
    if (noInit == true) {
        return node140;
    }
    auto node131 = GET_SKILL_NODE(131, PhaseNode_GetUInt64sValue);
    if (node131 != nullptr) node140->setTarget(node131->getValue());
    return node140;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10172, 144) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_Delay::TRIGGER_DONE, 90, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(10172, 144) {
    auto node144 = GET_SKILL_NODE(144, PhaseNode_Delay);
    if (node144 == nullptr) {
        node144 = new PhaseNode_Delay(144, phase);
        node144->setTime(.90f);
        CALL_REGISTER_SKILL_NODE(10172, 144, node144)
    }
    if (noInit == true) {
        return node144;
    }
    return node144;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10172, 147) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_PlayAnimation::TRIGGER_DONE, 157, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_PlayAnimation::TRIGGER_DONE, 149, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(10172, 147) {
    auto node147 = GET_SKILL_NODE(147, PhaseNode_PlayAnimation);
    if (node147 == nullptr) {
        node147 = new PhaseNode_PlayAnimation(147, phase);
        node147->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node147->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node147->setTarget(0U);
        node147->setAnimation("Skill2S1");
        node147->setParameter("SkillArmBusy");
        node147->setValue(true);
        CALL_REGISTER_SKILL_NODE(10172, 147, node147)
    }
    if (noInit == true) {
        return node147;
    }
    return node147;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(10172, 149) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_ResetCD::TRIGGER_DONE, 155, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(10172, 149) {
    auto node149 = GET_SKILL_NODE(149, PhaseNode_ResetCD);
    if (node149 == nullptr) {
        node149 = new PhaseNode_ResetCD(149, phase);
        node149->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node149->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node149->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(10172, 149, node149)
    }
    if (noInit == true) {
        return node149;
    }
    return node149;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10172, 151) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_Delay::TRIGGER_DONE, 159, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10172, 151) {
    auto node151 = GET_SKILL_NODE(151, PhaseNode_Delay);
    if (node151 == nullptr) {
        node151 = new PhaseNode_Delay(151, phase);
        node151->setTime(.36f);
        CALL_REGISTER_SKILL_NODE(10172, 151, node151)
    }
    if (noInit == true) {
        return node151;
    }
    return node151;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(10172, 153) {
}

REGISTER_CREATE_SKILL_NODE(10172, 153) {
    auto node153 = GET_SKILL_NODE(153, PhaseNode_PlayEffect);
    if (node153 == nullptr) {
        node153 = new PhaseNode_PlayEffect(153, phase);
        node153->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node153->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node153->setEffectID(101724);
        node153->setChangeColor(false);
        node153->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node153->getVars().reserve(3);
        node153->getVars().setVariable<float>(0, .00f);
        node153->getVars().setVariable<float>(1, .00f);
        node153->getVars().setVariable<float>(2, .00f);
        node153->setRotation(.00f);
        node153->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(10172, 153, node153)
    }
    if (noInit == true) {
        return node153;
    }
    auto node155 = GET_SKILL_NODE(155, PhaseNode_GetLocation);
    if (node155 != nullptr) node153->getVars().setVariable<float>(0, node155->getX());
    if (node155 != nullptr) node153->getVars().setVariable<float>(1, node155->getY());
    return node153;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(10172, 155) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Disable>(PhaseNode_GetLocation::TRIGGER_DONE, 9, PhaseNode_Disable::FUNC_DO, &PhaseNode_Disable::Do);
}

REGISTER_CREATE_SKILL_NODE(10172, 155) {
    auto node155 = GET_SKILL_NODE(155, PhaseNode_GetLocation);
    if (node155 == nullptr) {
        node155 = new PhaseNode_GetLocation(155, phase);
        node155->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node155->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(10172, 155, node155)
    }
    if (noInit == true) {
        return node155;
    }
    return node155;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10172, 157) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_PlaySound::TRIGGER_DONE, 164, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10172, 157) {
    auto node157 = GET_SKILL_NODE(157, PhaseNode_PlaySound);
    if (node157 == nullptr) {
        node157 = new PhaseNode_PlaySound(157, phase);
        node157->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node157->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node157->setSoundID("SE_Hero114_SkillB_P1");
        node157->setTarget(0U);
        node157->setUsePos(false);
        node157->setPosX(.00f);
        node157->setPosY(.00f);
        node157->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10172, 157, node157)
    }
    if (noInit == true) {
        return node157;
    }
    return node157;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10172, 159) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_PlaySound::TRIGGER_DONE, 153, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(10172, 159) {
    auto node159 = GET_SKILL_NODE(159, PhaseNode_PlaySound);
    if (node159 == nullptr) {
        node159 = new PhaseNode_PlaySound(159, phase);
        node159->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node159->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node159->setSoundID("SE_Hero114_SkillB_P2");
        node159->setTarget(0U);
        node159->setUsePos(false);
        node159->setPosX(.00f);
        node159->setPosY(.00f);
        node159->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10172, 159, node159)
    }
    if (noInit == true) {
        return node159;
    }
    return node159;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10172, 161) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_IsInterruptType>(PhaseNode_Detect::TRIGGER_ON, 167, PhaseNode_IsInterruptType::FUNC_DO, &PhaseNode_IsInterruptType::Do);
}

REGISTER_CREATE_SKILL_NODE(10172, 161) {
    auto node161 = GET_SKILL_NODE(161, PhaseNode_Detect);
    if (node161 == nullptr) {
        node161 = new PhaseNode_Detect(161, phase);
        node161->setSelf(0U);
        node161->setEvent("daduan_001");
        node161->setType(PhaseNode_Detect::Detect_Type::Interrupt_Skill);
        node161->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10172, 161, node161)
    }
    if (noInit == true) {
        return node161;
    }
    return node161;
}
//--------------------------------------------------------------------------------
// SwitchToInt
//
REGISTER_REGISTER_SKILL_NODE(10172, 162) {
    pnode->resizeTrigger(4);
    pnode->regTrigger<PhaseNode_EndPhase>(1, 90, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(10172, 162) {
    auto node162 = GET_SKILL_NODE(162, PhaseNode_SwitchToInt);
    if (node162 == nullptr) {
        node162 = new PhaseNode_SwitchToInt(162, phase);
        CALL_REGISTER_SKILL_NODE(10172, 162, node162)
    }
    if (noInit == true) {
        return node162;
    }
    auto variables = node162->getVariables();
    if (variables != nullptr) {
        node162->setSelection(variables->getVariable<int32_t>(Variable_10172_a101722));
    }
    return node162;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10172, 164) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_RaiseEvent::TRIGGER_DONE, 173, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10172, 164) {
    auto node164 = GET_SKILL_NODE(164, PhaseNode_RaiseEvent);
    if (node164 == nullptr) {
        node164 = new PhaseNode_RaiseEvent(164, phase);
        node164->setEvent("daduan_001");
        node164->setTarget(0U);
        node164->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node164->setTypeParams(0, 0);
        node164->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10172, 164, node164)
    }
    if (noInit == true) {
        return node164;
    }
    return node164;
}
//--------------------------------------------------------------------------------
// StartPreInput
//
REGISTER_REGISTER_SKILL_NODE(10172, 165) {
    pnode->resizeTrigger(PhaseNode_StartPreInput::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_StartPreInput::TRIGGER_DONE, 169, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10172, 165) {
    auto node165 = GET_SKILL_NODE(165, PhaseNode_StartPreInput);
    if (node165 == nullptr) {
        node165 = new PhaseNode_StartPreInput(165, phase);
        node165->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node165->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node165->setDelayTime(.00f);
        CALL_REGISTER_SKILL_NODE(10172, 165, node165)
    }
    if (noInit == true) {
        return node165;
    }
    return node165;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(10172, 166) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_If::TRIGGER_TRUE, 168, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10172, 166) {
    auto node166 = GET_SKILL_NODE(166, PhaseNode_If);
    if (node166 == nullptr) {
        node166 = new PhaseNode_If(166, phase);
        CALL_REGISTER_SKILL_NODE(10172, 166, node166)
    }
    if (noInit == true) {
        return node166;
    }
    auto variables = node166->getVariables();
    if (variables != nullptr) {
        node166->setCondition(variables->getVariable<bool>(Variable_10172_InterruptAnimat));
    }
    return node166;
}
//--------------------------------------------------------------------------------
// IsInterruptType
//
REGISTER_REGISTER_SKILL_NODE(10172, 167) {
    pnode->resizeTrigger(PhaseNode_IsInterruptType::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SwitchToInt>(PhaseNode_IsInterruptType::TRIGGER_BUFF, 162, PhaseNode_SwitchToInt::FUNC_SWITCH, &PhaseNode_SwitchToInt::Switch);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_POSCHANGE, 166, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTAIM, 166, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTFIRE, 166, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTRELOAD, 166, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_USESKILL, 166, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(10172, 167) {
    auto node167 = GET_SKILL_NODE(167, PhaseNode_IsInterruptType);
    if (node167 == nullptr) {
        node167 = new PhaseNode_IsInterruptType(167, phase);
        node167->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node167->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10172, 167, node167)
    }
    if (noInit == true) {
        return node167;
    }
    auto node161 = GET_SKILL_NODE(161, PhaseNode_Detect);
    if (node161 != nullptr) node167->setType(node161->getVars().getVariable<int32_t>(2));
    return node167;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10172, 168) {
}

REGISTER_CREATE_SKILL_NODE(10172, 168) {
    auto node168 = GET_SKILL_NODE(168, PhaseNode_PlayAnimation);
    if (node168 == nullptr) {
        node168 = new PhaseNode_PlayAnimation(168, phase);
        node168->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node168->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node168->setTarget(0U);
        node168->setAnimation("Idle");
        node168->setParameter("");
        node168->setValue(false);
        CALL_REGISTER_SKILL_NODE(10172, 168, node168)
    }
    if (noInit == true) {
        return node168;
    }
    return node168;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10172, 169) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_Delay::TRIGGER_DONE, 172, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(10172, 169) {
    auto node169 = GET_SKILL_NODE(169, PhaseNode_Delay);
    if (node169 == nullptr) {
        node169 = new PhaseNode_Delay(169, phase);
        node169->setTime(.20f);
        CALL_REGISTER_SKILL_NODE(10172, 169, node169)
    }
    if (noInit == true) {
        return node169;
    }
    return node169;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(10172, 172) {
}

REGISTER_CREATE_SKILL_NODE(10172, 172) {
    auto node172 = GET_SKILL_NODE(172, PhaseNode_SetBool);
    if (node172 == nullptr) {
        node172 = new PhaseNode_SetBool(172, phase);
        node172->setName("InterruptAnimat");
        node172->setValue(true);
        CALL_REGISTER_SKILL_NODE(10172, 172, node172)
    }
    if (noInit == true) {
        return node172;
    }
    return node172;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10172, 173) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StartPreInput>(PhaseNode_RaiseEvent::TRIGGER_DONE, 165, PhaseNode_StartPreInput::FUNC_DO, &PhaseNode_StartPreInput::Do);
}

REGISTER_CREATE_SKILL_NODE(10172, 173) {
    auto node173 = GET_SKILL_NODE(173, PhaseNode_RaiseEvent);
    if (node173 == nullptr) {
        node173 = new PhaseNode_RaiseEvent(173, phase);
        node173->setEvent("Dead_001");
        node173->setTarget(0U);
        node173->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node173->setTypeParams(0, 0);
        node173->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10172, 173, node173)
    }
    if (noInit == true) {
        return node173;
    }
    return node173;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10172, 174) {
}

REGISTER_CREATE_SKILL_NODE(10172, 174) {
    auto node174 = GET_SKILL_NODE(174, PhaseNode_Detect);
    if (node174 == nullptr) {
        node174 = new PhaseNode_Detect(174, phase);
        node174->setSelf(0U);
        node174->setEvent("Dead_001");
        node174->setType(PhaseNode_Detect::Detect_Type::Actor_Dead);
        node174->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10172, 174, node174)
    }
    if (noInit == true) {
        return node174;
    }
    return node174;
}

//--------------------------------------------------------------------------------
// SkillCreator_10172
//
class SkillCreator_10172 : public SkillCreator {
public:
    SkillCreator_10172() {}
    virtual ~SkillCreator_10172() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_10172

//--------------------------------------------------------------------------------
// SkillPhase_10172
//
class SkillPhase_10172 : public SkillPhase {
public:
    SkillPhase_10172(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_10172() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(10172, 3) // StartPhase
        CASE_CREATE_SKILL_NODE(10172, 5) // TriggerUpdate
        CASE_CREATE_SKILL_NODE(10172, 9) // Disable
        CASE_CREATE_SKILL_NODE(10172, 90) // EndPhase
        CASE_CREATE_SKILL_NODE(10172, 120) // GetAllObject
        CASE_CREATE_SKILL_NODE(10172, 122) // FindSkillBuff
        CASE_CREATE_SKILL_NODE(10172, 127) // For
        CASE_CREATE_SKILL_NODE(10172, 129) // UInt64sSize
        CASE_CREATE_SKILL_NODE(10172, 131) // GetUInt64sValue
        CASE_CREATE_SKILL_NODE(10172, 133) // If
        CASE_CREATE_SKILL_NODE(10172, 135) // ForContinue
        CASE_CREATE_SKILL_NODE(10172, 138) // SpawnProjectile
        CASE_CREATE_SKILL_NODE(10172, 140) // GetLocation
        CASE_CREATE_SKILL_NODE(10172, 144) // Delay
        CASE_CREATE_SKILL_NODE(10172, 147) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10172, 149) // ResetCD
        CASE_CREATE_SKILL_NODE(10172, 151) // Delay
        CASE_CREATE_SKILL_NODE(10172, 153) // PlayEffect
        CASE_CREATE_SKILL_NODE(10172, 155) // GetLocation
        CASE_CREATE_SKILL_NODE(10172, 157) // PlaySound
        CASE_CREATE_SKILL_NODE(10172, 159) // PlaySound
        CASE_CREATE_SKILL_NODE(10172, 161) // Detect
        CASE_CREATE_SKILL_NODE(10172, 162) // SwitchToInt
        CASE_CREATE_SKILL_NODE(10172, 164) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10172, 165) // StartPreInput
        CASE_CREATE_SKILL_NODE(10172, 166) // If
        CASE_CREATE_SKILL_NODE(10172, 167) // IsInterruptType
        CASE_CREATE_SKILL_NODE(10172, 168) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10172, 169) // Delay
        CASE_CREATE_SKILL_NODE(10172, 172) // SetBool
        CASE_CREATE_SKILL_NODE(10172, 173) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10172, 174) // Detect
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_10172

SkillLogic* SkillCreator_10172::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //设置变量
    Variable_10172_a101722 = logic->getVariables().setVariable<int32_t>("a101722", 1);
    Variable_10172_InterruptAnimat = logic->getVariables().setVariable<bool>("InterruptAnimat");
    //创建阶段phase
    auto phase = new SkillPhase_10172(1, logic, 3);
    //设置phase执行器
    phase->setRunPhaseNode(1, 3);
    phase->setRunPhaseNode(2, 5);
    phase->setDetectPhaseNode(3, 161);
    phase->setDetectPhaseNode(3, 174);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_10172::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
