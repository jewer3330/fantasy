#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

#include "skill_psnode_delay.h"
#include "skill_psnode_detect.h"
#include "skill_psnode_disable.h"
#include "skill_psnode_endphase.h"
#include "skill_psnode_getactorattribute.h"
#include "skill_psnode_getinputrotation.h"
#include "skill_psnode_getlocation.h"
#include "skill_psnode_if.h"
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
#include "skill_psnode_triggerupdate.h"

namespace pvp {

//变量声明
uint64_t Variable_10093_100932 = 0;
uint64_t Variable_10093_InterruptAnimat = 0;
//--------------------------------------------------------------------------------
// StartPhase
//
REGISTER_REGISTER_SKILL_NODE(10093, 2) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_StartPhase::TRIGGER_START, 403, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(10093, 2) {
    auto node2 = GET_SKILL_NODE(2, PhaseNode_StartPhase);
    if (node2 == nullptr) {
        node2 = new PhaseNode_StartPhase(2, phase);
        CALL_REGISTER_SKILL_NODE(10093, 2, node2)
    }
    if (noInit == true) {
        return node2;
    }
    return node2;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10093, 10) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_OffsetCalculate>(PhaseNode_Delay::TRIGGER_DONE, 16, PhaseNode_OffsetCalculate::FUNC_DO, &PhaseNode_OffsetCalculate::Do);
}

REGISTER_CREATE_SKILL_NODE(10093, 10) {
    auto node10 = GET_SKILL_NODE(10, PhaseNode_Delay);
    if (node10 == nullptr) {
        node10 = new PhaseNode_Delay(10, phase);
        node10->setTime(.44f);
        CALL_REGISTER_SKILL_NODE(10093, 10, node10)
    }
    if (noInit == true) {
        return node10;
    }
    return node10;
}
//--------------------------------------------------------------------------------
// Disable
//
REGISTER_REGISTER_SKILL_NODE(10093, 12) {
    pnode->resizeTrigger(PhaseNode_Disable::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_Disable::TRIGGER_DONE, 397, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_Disable::TRIGGER_DONE, 402, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_Disable::TRIGGER_DONE, 411, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10093, 12) {
    auto node12 = GET_SKILL_NODE(12, PhaseNode_Disable);
    if (node12 == nullptr) {
        node12 = new PhaseNode_Disable(12, phase);
        node12->setTarget(0U);
        node12->setMove(true);
        node12->setSkill(true);
        node12->setShoot(true);
        node12->setTime(.90f);
        node12->setRotate(true);
        CALL_REGISTER_SKILL_NODE(10093, 12, node12)
    }
    if (noInit == true) {
        return node12;
    }
    return node12;
}
//--------------------------------------------------------------------------------
// OffsetCalculate
//
REGISTER_REGISTER_SKILL_NODE(10093, 16) {
    pnode->resizeTrigger(PhaseNode_OffsetCalculate::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 71, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(10093, 16) {
    auto node16 = GET_SKILL_NODE(16, PhaseNode_OffsetCalculate);
    if (node16 == nullptr) {
        node16 = new PhaseNode_OffsetCalculate(16, phase);
        node16->setPosZ(.00f);
        node16->setOffsetX(.00f);
        node16->setOffsetY(.50f);
        node16->setOffsetZ(1.00f);
        node16->setRotOffset(.00f);
        CALL_REGISTER_SKILL_NODE(10093, 16, node16)
    }
    if (noInit == true) {
        return node16;
    }
    auto node397 = GET_SKILL_NODE(397, PhaseNode_GetLocation);
    auto node400 = GET_SKILL_NODE(400, PhaseNode_GetInputRotation);
    if (node397 != nullptr) node16->setPosX(node397->getX());
    if (node397 != nullptr) node16->setPosY(node397->getY());
    if (node400 != nullptr) node16->setRotation(node400->getAngle());
    return node16;
}
//--------------------------------------------------------------------------------
// TriggerUpdate
//
REGISTER_REGISTER_SKILL_NODE(10093, 18) {
}

REGISTER_CREATE_SKILL_NODE(10093, 18) {
    auto node18 = GET_SKILL_NODE(18, PhaseNode_TriggerUpdate);
    if (node18 == nullptr) {
        node18 = new PhaseNode_TriggerUpdate(18, phase);
        CALL_REGISTER_SKILL_NODE(10093, 18, node18)
    }
    if (noInit == true) {
        return node18;
    }
    return node18;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(10093, 69) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlayEffect::TRIGGER_DONE, 10, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10093, 69) {
    auto node69 = GET_SKILL_NODE(69, PhaseNode_PlayEffect);
    if (node69 == nullptr) {
        node69 = new PhaseNode_PlayEffect(69, phase);
        node69->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node69->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node69->setEffectID(100932);
        node69->setChangeColor(true);
        node69->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node69->getVars().reserve(3);
        node69->getVars().setVariable<float>(0, .00f);
        node69->getVars().setVariable<float>(1, .00f);
        node69->getVars().setVariable<float>(2, .00f);
        node69->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(10093, 69, node69)
    }
    if (noInit == true) {
        return node69;
    }
    auto node397 = GET_SKILL_NODE(397, PhaseNode_GetLocation);
    auto node400 = GET_SKILL_NODE(400, PhaseNode_GetInputRotation);
    if (node397 != nullptr) node69->getVars().setVariable<float>(0, node397->getX());
    if (node397 != nullptr) node69->getVars().setVariable<float>(1, node397->getY());
    if (node400 != nullptr) node69->setRotation(node400->getAngle());
    return node69;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(10093, 71) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlayEffect::TRIGGER_DONE, 165, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10093, 71) {
    auto node71 = GET_SKILL_NODE(71, PhaseNode_PlayEffect);
    if (node71 == nullptr) {
        node71 = new PhaseNode_PlayEffect(71, phase);
        node71->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node71->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node71->setEffectID(100933);
        node71->setChangeColor(true);
        node71->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node71->getVars().reserve(3);
        node71->getVars().setVariable<float>(0, .00f);
        node71->getVars().setVariable<float>(1, .00f);
        node71->getVars().setVariable<float>(2, .00f);
        node71->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(10093, 71, node71)
    }
    if (noInit == true) {
        return node71;
    }
    auto node16 = GET_SKILL_NODE(16, PhaseNode_OffsetCalculate);
    if (node16 != nullptr) node71->getVars().setVariable<float>(0, node16->getOutPosX());
    if (node16 != nullptr) node71->getVars().setVariable<float>(1, node16->getOutPosY());
    if (node16 != nullptr) node71->getVars().setVariable<float>(2, node16->getOutPosZ());
    if (node16 != nullptr) node71->setRotation(node16->getOutRotation());
    return node71;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10093, 165) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_Delay::TRIGGER_DONE, 392, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_Delay::TRIGGER_DONE, 228, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10093, 165) {
    auto node165 = GET_SKILL_NODE(165, PhaseNode_Delay);
    if (node165 == nullptr) {
        node165 = new PhaseNode_Delay(165, phase);
        node165->setTime(.30f);
        CALL_REGISTER_SKILL_NODE(10093, 165, node165)
    }
    if (noInit == true) {
        return node165;
    }
    return node165;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(10093, 202) {
}

REGISTER_CREATE_SKILL_NODE(10093, 202) {
    auto node202 = GET_SKILL_NODE(202, PhaseNode_EndPhase);
    if (node202 == nullptr) {
        node202 = new PhaseNode_EndPhase(202, phase);
        node202->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node202->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10093, 202, node202)
    }
    if (noInit == true) {
        return node202;
    }
    return node202;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10093, 228) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnProjectile>(PhaseNode_PlaySound::TRIGGER_DONE, 394, PhaseNode_SpawnProjectile::FUNC_DO, &PhaseNode_SpawnProjectile::Do);
}

REGISTER_CREATE_SKILL_NODE(10093, 228) {
    auto node228 = GET_SKILL_NODE(228, PhaseNode_PlaySound);
    if (node228 == nullptr) {
        node228 = new PhaseNode_PlaySound(228, phase);
        node228->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node228->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node228->setSoundID("SE_Hero109_Skill_C_P2");
        node228->setTarget(0U);
        node228->setUsePos(false);
        node228->setPosX(.00f);
        node228->setPosY(.00f);
        node228->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10093, 228, node228)
    }
    if (noInit == true) {
        return node228;
    }
    return node228;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10093, 392) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_Delay::TRIGGER_DONE, 202, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(10093, 392) {
    auto node392 = GET_SKILL_NODE(392, PhaseNode_Delay);
    if (node392 == nullptr) {
        node392 = new PhaseNode_Delay(392, phase);
        node392->setTime(.46f);
        CALL_REGISTER_SKILL_NODE(10093, 392, node392)
    }
    if (noInit == true) {
        return node392;
    }
    return node392;
}
//--------------------------------------------------------------------------------
// SpawnProjectile
//
REGISTER_REGISTER_SKILL_NODE(10093, 394) {
}

REGISTER_CREATE_SKILL_NODE(10093, 394) {
    auto node394 = GET_SKILL_NODE(394, PhaseNode_SpawnProjectile);
    if (node394 == nullptr) {
        node394 = new PhaseNode_SpawnProjectile(394, phase);
        node394->setDataId(55093);
        node394->setEndPosX(.00f);
        node394->setEndPosY(.00f);
        node394->setEndPosZ(.00f);
        node394->setMaxCount(0);
        CALL_REGISTER_SKILL_NODE(10093, 394, node394)
    }
    if (noInit == true) {
        return node394;
    }
    auto node16 = GET_SKILL_NODE(16, PhaseNode_OffsetCalculate);
    if (node16 != nullptr) node394->setPosX(node16->getOutPosX());
    if (node16 != nullptr) node394->setPosY(node16->getOutPosY());
    if (node16 != nullptr) node394->setPosZ(node16->getOutPosZ());
    if (node16 != nullptr) node394->setRotation(node16->getOutRotation());
    return node394;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(10093, 397) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetInputRotation>(PhaseNode_GetLocation::TRIGGER_DONE, 400, PhaseNode_GetInputRotation::FUNC_DO, &PhaseNode_GetInputRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(10093, 397) {
    auto node397 = GET_SKILL_NODE(397, PhaseNode_GetLocation);
    if (node397 == nullptr) {
        node397 = new PhaseNode_GetLocation(397, phase);
        node397->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node397->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(10093, 397, node397)
    }
    if (noInit == true) {
        return node397;
    }
    return node397;
}
//--------------------------------------------------------------------------------
// GetInputRotation
//
REGISTER_REGISTER_SKILL_NODE(10093, 400) {
    pnode->resizeTrigger(PhaseNode_GetInputRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_GetInputRotation::TRIGGER_DONE, 69, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(10093, 400) {
    auto node400 = GET_SKILL_NODE(400, PhaseNode_GetInputRotation);
    if (node400 == nullptr) {
        node400 = new PhaseNode_GetInputRotation(400, phase);
        node400->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        CALL_REGISTER_SKILL_NODE(10093, 400, node400)
    }
    if (noInit == true) {
        return node400;
    }
    return node400;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10093, 402) {
}

REGISTER_CREATE_SKILL_NODE(10093, 402) {
    auto node402 = GET_SKILL_NODE(402, PhaseNode_PlaySound);
    if (node402 == nullptr) {
        node402 = new PhaseNode_PlaySound(402, phase);
        node402->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node402->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node402->setSoundID("SE_Hero109_Skill_C_P1");
        node402->setTarget(0U);
        node402->setUsePos(false);
        node402->setPosX(.00f);
        node402->setPosY(.00f);
        node402->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10093, 402, node402)
    }
    if (noInit == true) {
        return node402;
    }
    return node402;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(10093, 403) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_ResetCD::TRIGGER_DONE, 404, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10093, 403) {
    auto node403 = GET_SKILL_NODE(403, PhaseNode_ResetCD);
    if (node403 == nullptr) {
        node403 = new PhaseNode_ResetCD(403, phase);
        node403->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node403->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node403->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(10093, 403, node403)
    }
    if (noInit == true) {
        return node403;
    }
    return node403;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10093, 404) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_PlayAnimation::TRIGGER_DONE, 406, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(10093, 404) {
    auto node404 = GET_SKILL_NODE(404, PhaseNode_PlayAnimation);
    if (node404 == nullptr) {
        node404 = new PhaseNode_PlayAnimation(404, phase);
        node404->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node404->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node404->setTarget(0U);
        node404->setAnimation("Skill3S1");
        node404->setParameter("");
        node404->setValue(false);
        CALL_REGISTER_SKILL_NODE(10093, 404, node404)
    }
    if (noInit == true) {
        return node404;
    }
    return node404;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10093, 405) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Disable>(PhaseNode_PlaySound::TRIGGER_DONE, 12, PhaseNode_Disable::FUNC_DO, &PhaseNode_Disable::Do);
}

REGISTER_CREATE_SKILL_NODE(10093, 405) {
    auto node405 = GET_SKILL_NODE(405, PhaseNode_PlaySound);
    if (node405 == nullptr) {
        node405 = new PhaseNode_PlaySound(405, phase);
        node405->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node405->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node405->setSoundID("VO_Hero109_Skill_C");
        node405->setTarget(0U);
        node405->setUsePos(false);
        node405->setPosX(.00f);
        node405->setPosY(.00f);
        node405->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10093, 405, node405)
    }
    if (noInit == true) {
        return node405;
    }
    return node405;
}
//--------------------------------------------------------------------------------
// GetActorAttribute
//
REGISTER_REGISTER_SKILL_NODE(10093, 406) {
    pnode->resizeTrigger(PhaseNode_GetActorAttribute::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 405, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10093, 406) {
    auto node406 = GET_SKILL_NODE(406, PhaseNode_GetActorAttribute);
    if (node406 == nullptr) {
        node406 = new PhaseNode_GetActorAttribute(406, phase);
        node406->setTarget(0U);
        node406->setType({});
        CALL_REGISTER_SKILL_NODE(10093, 406, node406)
    }
    if (noInit == true) {
        return node406;
    }
    return node406;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10093, 408) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_IsInterruptType>(PhaseNode_Detect::TRIGGER_ON, 414, PhaseNode_IsInterruptType::FUNC_DO, &PhaseNode_IsInterruptType::Do);
}

REGISTER_CREATE_SKILL_NODE(10093, 408) {
    auto node408 = GET_SKILL_NODE(408, PhaseNode_Detect);
    if (node408 == nullptr) {
        node408 = new PhaseNode_Detect(408, phase);
        node408->setSelf(0U);
        node408->setEvent("daduan_001");
        node408->setType(PhaseNode_Detect::Detect_Type::Interrupt_Skill);
        node408->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10093, 408, node408)
    }
    if (noInit == true) {
        return node408;
    }
    return node408;
}
//--------------------------------------------------------------------------------
// SwitchToInt
//
REGISTER_REGISTER_SKILL_NODE(10093, 409) {
    pnode->resizeTrigger(4);
    pnode->regTrigger<PhaseNode_EndPhase>(1, 202, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(10093, 409) {
    auto node409 = GET_SKILL_NODE(409, PhaseNode_SwitchToInt);
    if (node409 == nullptr) {
        node409 = new PhaseNode_SwitchToInt(409, phase);
        CALL_REGISTER_SKILL_NODE(10093, 409, node409)
    }
    if (noInit == true) {
        return node409;
    }
    auto variables = node409->getVariables();
    if (variables != nullptr) {
        node409->setSelection(variables->getVariable<int32_t>(Variable_10093_100932));
    }
    return node409;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10093, 411) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_RaiseEvent::TRIGGER_DONE, 420, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10093, 411) {
    auto node411 = GET_SKILL_NODE(411, PhaseNode_RaiseEvent);
    if (node411 == nullptr) {
        node411 = new PhaseNode_RaiseEvent(411, phase);
        node411->setEvent("daduan_001");
        node411->setTarget(0U);
        node411->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node411->setTypeParams(0, 0);
        node411->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10093, 411, node411)
    }
    if (noInit == true) {
        return node411;
    }
    return node411;
}
//--------------------------------------------------------------------------------
// StartPreInput
//
REGISTER_REGISTER_SKILL_NODE(10093, 412) {
    pnode->resizeTrigger(PhaseNode_StartPreInput::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_StartPreInput::TRIGGER_DONE, 416, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10093, 412) {
    auto node412 = GET_SKILL_NODE(412, PhaseNode_StartPreInput);
    if (node412 == nullptr) {
        node412 = new PhaseNode_StartPreInput(412, phase);
        node412->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node412->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node412->setDelayTime(.00f);
        CALL_REGISTER_SKILL_NODE(10093, 412, node412)
    }
    if (noInit == true) {
        return node412;
    }
    return node412;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(10093, 413) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_If::TRIGGER_TRUE, 415, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10093, 413) {
    auto node413 = GET_SKILL_NODE(413, PhaseNode_If);
    if (node413 == nullptr) {
        node413 = new PhaseNode_If(413, phase);
        CALL_REGISTER_SKILL_NODE(10093, 413, node413)
    }
    if (noInit == true) {
        return node413;
    }
    auto variables = node413->getVariables();
    if (variables != nullptr) {
        node413->setCondition(variables->getVariable<bool>(Variable_10093_InterruptAnimat));
    }
    return node413;
}
//--------------------------------------------------------------------------------
// IsInterruptType
//
REGISTER_REGISTER_SKILL_NODE(10093, 414) {
    pnode->resizeTrigger(PhaseNode_IsInterruptType::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SwitchToInt>(PhaseNode_IsInterruptType::TRIGGER_BUFF, 409, PhaseNode_SwitchToInt::FUNC_SWITCH, &PhaseNode_SwitchToInt::Switch);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_POSCHANGE, 413, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTAIM, 413, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTFIRE, 413, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTRELOAD, 413, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_USESKILL, 413, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(10093, 414) {
    auto node414 = GET_SKILL_NODE(414, PhaseNode_IsInterruptType);
    if (node414 == nullptr) {
        node414 = new PhaseNode_IsInterruptType(414, phase);
        node414->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node414->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10093, 414, node414)
    }
    if (noInit == true) {
        return node414;
    }
    auto node408 = GET_SKILL_NODE(408, PhaseNode_Detect);
    if (node408 != nullptr) node414->setType(node408->getVars().getVariable<int32_t>(2));
    return node414;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10093, 415) {
}

REGISTER_CREATE_SKILL_NODE(10093, 415) {
    auto node415 = GET_SKILL_NODE(415, PhaseNode_PlayAnimation);
    if (node415 == nullptr) {
        node415 = new PhaseNode_PlayAnimation(415, phase);
        node415->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node415->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node415->setTarget(0U);
        node415->setAnimation("Idle");
        node415->setParameter("");
        node415->setValue(false);
        CALL_REGISTER_SKILL_NODE(10093, 415, node415)
    }
    if (noInit == true) {
        return node415;
    }
    return node415;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10093, 416) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_Delay::TRIGGER_DONE, 419, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(10093, 416) {
    auto node416 = GET_SKILL_NODE(416, PhaseNode_Delay);
    if (node416 == nullptr) {
        node416 = new PhaseNode_Delay(416, phase);
        node416->setTime(.20f);
        CALL_REGISTER_SKILL_NODE(10093, 416, node416)
    }
    if (noInit == true) {
        return node416;
    }
    return node416;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(10093, 419) {
}

REGISTER_CREATE_SKILL_NODE(10093, 419) {
    auto node419 = GET_SKILL_NODE(419, PhaseNode_SetBool);
    if (node419 == nullptr) {
        node419 = new PhaseNode_SetBool(419, phase);
        node419->setName("InterruptAnimat");
        node419->setValue(true);
        CALL_REGISTER_SKILL_NODE(10093, 419, node419)
    }
    if (noInit == true) {
        return node419;
    }
    return node419;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10093, 420) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StartPreInput>(PhaseNode_RaiseEvent::TRIGGER_DONE, 412, PhaseNode_StartPreInput::FUNC_DO, &PhaseNode_StartPreInput::Do);
}

REGISTER_CREATE_SKILL_NODE(10093, 420) {
    auto node420 = GET_SKILL_NODE(420, PhaseNode_RaiseEvent);
    if (node420 == nullptr) {
        node420 = new PhaseNode_RaiseEvent(420, phase);
        node420->setEvent("Dead_001");
        node420->setTarget(0U);
        node420->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node420->setTypeParams(0, 0);
        node420->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10093, 420, node420)
    }
    if (noInit == true) {
        return node420;
    }
    return node420;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10093, 421) {
}

REGISTER_CREATE_SKILL_NODE(10093, 421) {
    auto node421 = GET_SKILL_NODE(421, PhaseNode_Detect);
    if (node421 == nullptr) {
        node421 = new PhaseNode_Detect(421, phase);
        node421->setSelf(0U);
        node421->setEvent("Dead_001");
        node421->setType(PhaseNode_Detect::Detect_Type::Actor_Dead);
        node421->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10093, 421, node421)
    }
    if (noInit == true) {
        return node421;
    }
    return node421;
}

//--------------------------------------------------------------------------------
// SkillCreator_10093
//
class SkillCreator_10093 : public SkillCreator {
public:
    SkillCreator_10093() {}
    virtual ~SkillCreator_10093() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_10093

//--------------------------------------------------------------------------------
// SkillPhase_10093
//
class SkillPhase_10093 : public SkillPhase {
public:
    SkillPhase_10093(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_10093() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(10093, 2) // StartPhase
        CASE_CREATE_SKILL_NODE(10093, 10) // Delay
        CASE_CREATE_SKILL_NODE(10093, 12) // Disable
        CASE_CREATE_SKILL_NODE(10093, 16) // OffsetCalculate
        CASE_CREATE_SKILL_NODE(10093, 18) // TriggerUpdate
        CASE_CREATE_SKILL_NODE(10093, 69) // PlayEffect
        CASE_CREATE_SKILL_NODE(10093, 71) // PlayEffect
        CASE_CREATE_SKILL_NODE(10093, 165) // Delay
        CASE_CREATE_SKILL_NODE(10093, 202) // EndPhase
        CASE_CREATE_SKILL_NODE(10093, 228) // PlaySound
        CASE_CREATE_SKILL_NODE(10093, 392) // Delay
        CASE_CREATE_SKILL_NODE(10093, 394) // SpawnProjectile
        CASE_CREATE_SKILL_NODE(10093, 397) // GetLocation
        CASE_CREATE_SKILL_NODE(10093, 400) // GetInputRotation
        CASE_CREATE_SKILL_NODE(10093, 402) // PlaySound
        CASE_CREATE_SKILL_NODE(10093, 403) // ResetCD
        CASE_CREATE_SKILL_NODE(10093, 404) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10093, 405) // PlaySound
        CASE_CREATE_SKILL_NODE(10093, 406) // GetActorAttribute
        CASE_CREATE_SKILL_NODE(10093, 408) // Detect
        CASE_CREATE_SKILL_NODE(10093, 409) // SwitchToInt
        CASE_CREATE_SKILL_NODE(10093, 411) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10093, 412) // StartPreInput
        CASE_CREATE_SKILL_NODE(10093, 413) // If
        CASE_CREATE_SKILL_NODE(10093, 414) // IsInterruptType
        CASE_CREATE_SKILL_NODE(10093, 415) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10093, 416) // Delay
        CASE_CREATE_SKILL_NODE(10093, 419) // SetBool
        CASE_CREATE_SKILL_NODE(10093, 420) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10093, 421) // Detect
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_10093

SkillLogic* SkillCreator_10093::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //设置变量
    Variable_10093_100932 = logic->getVariables().setVariable<int32_t>("100932", 1);
    Variable_10093_InterruptAnimat = logic->getVariables().setVariable<bool>("InterruptAnimat");
    //创建阶段phase
    auto phase = new SkillPhase_10093(1, logic, 3);
    //设置phase执行器
    phase->setRunPhaseNode(1, 2);
    phase->setRunPhaseNode(2, 18);
    phase->setDetectPhaseNode(3, 408);
    phase->setDetectPhaseNode(3, 421);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_10093::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
