#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

#include "skill_psnode_addskillbuff.h"
#include "skill_psnode_attachto.h"
#include "skill_psnode_cameraxyzshake.h"
#include "skill_psnode_delay.h"
#include "skill_psnode_destroycollider.h"
#include "skill_psnode_detect.h"
#include "skill_psnode_disable.h"
#include "skill_psnode_endphase.h"
#include "skill_psnode_findskillbuff.h"
#include "skill_psnode_getactorattribute.h"
#include "skill_psnode_getinputobject.h"
#include "skill_psnode_getlinerotation.h"
#include "skill_psnode_getlocation.h"
#include "skill_psnode_getrotation.h"
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
#include "skill_psnode_spawncollider.h"
#include "skill_psnode_startphase.h"
#include "skill_psnode_startpreinput.h"
#include "skill_psnode_switchtoint.h"
#include "skill_psnode_triggerupdate.h"

namespace pvp {

//变量声明
uint64_t Variable_10343_break = 0;
uint64_t Variable_10343_InterruptAnimat = 0;
//--------------------------------------------------------------------------------
// StartPhase
//
REGISTER_REGISTER_SKILL_NODE(10343, 3) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_StartPhase::TRIGGER_START, 143, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(10343, 3) {
    auto node3 = GET_SKILL_NODE(3, PhaseNode_StartPhase);
    if (node3 == nullptr) {
        node3 = new PhaseNode_StartPhase(3, phase);
        CALL_REGISTER_SKILL_NODE(10343, 3, node3)
    }
    if (noInit == true) {
        return node3;
    }
    return node3;
}
//--------------------------------------------------------------------------------
// Disable
//
REGISTER_REGISTER_SKILL_NODE(10343, 7) {
    pnode->resizeTrigger(PhaseNode_Disable::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_Disable::TRIGGER_DONE, 151, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10343, 7) {
    auto node7 = GET_SKILL_NODE(7, PhaseNode_Disable);
    if (node7 == nullptr) {
        node7 = new PhaseNode_Disable(7, phase);
        node7->setTarget(0U);
        node7->setMove(true);
        node7->setSkill(true);
        node7->setShoot(true);
        node7->setTime(1.10f);
        node7->setRotate(true);
        CALL_REGISTER_SKILL_NODE(10343, 7, node7)
    }
    if (noInit == true) {
        return node7;
    }
    return node7;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(10343, 13) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetInputObject>(PhaseNode_GetLocation::TRIGGER_DONE, 74, PhaseNode_GetInputObject::FUNC_DO, &PhaseNode_GetInputObject::Do);
}

REGISTER_CREATE_SKILL_NODE(10343, 13) {
    auto node13 = GET_SKILL_NODE(13, PhaseNode_GetLocation);
    if (node13 == nullptr) {
        node13 = new PhaseNode_GetLocation(13, phase);
        node13->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node13->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(10343, 13, node13)
    }
    if (noInit == true) {
        return node13;
    }
    return node13;
}
//--------------------------------------------------------------------------------
// OffsetCalculate
//
REGISTER_REGISTER_SKILL_NODE(10343, 26) {
    pnode->resizeTrigger(PhaseNode_OffsetCalculate::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 67, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(10343, 26) {
    auto node26 = GET_SKILL_NODE(26, PhaseNode_OffsetCalculate);
    if (node26 == nullptr) {
        node26 = new PhaseNode_OffsetCalculate(26, phase);
        node26->setPosZ(.00f);
        node26->setOffsetX(.00f);
        node26->setOffsetY(.00f);
        node26->setOffsetZ(.00f);
        node26->setRotOffset(180.00f);
        CALL_REGISTER_SKILL_NODE(10343, 26, node26)
    }
    if (noInit == true) {
        return node26;
    }
    auto node115 = GET_SKILL_NODE(115, PhaseNode_GetLocation);
    auto node117 = GET_SKILL_NODE(117, PhaseNode_GetRotation);
    if (node115 != nullptr) node26->setPosX(node115->getX());
    if (node115 != nullptr) node26->setPosY(node115->getY());
    if (node117 != nullptr) node26->setRotation(node117->getAngle());
    return node26;
}
//--------------------------------------------------------------------------------
// FindSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10343, 34) {
    pnode->resizeTrigger(PhaseNode_FindSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_FindSkillBuff::TRIGGER_DONE, 40, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(10343, 34) {
    auto node34 = GET_SKILL_NODE(34, PhaseNode_FindSkillBuff);
    if (node34 == nullptr) {
        node34 = new PhaseNode_FindSkillBuff(34, phase);
        node34->setSelfTarget(0U);
        node34->setDetectTarget(0U);
        node34->setConfigID(103403);
        CALL_REGISTER_SKILL_NODE(10343, 34, node34)
    }
    if (noInit == true) {
        return node34;
    }
    return node34;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10343, 38) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_Delay::TRIGGER_DONE, 47, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(10343, 38) {
    auto node38 = GET_SKILL_NODE(38, PhaseNode_Delay);
    if (node38 == nullptr) {
        node38 = new PhaseNode_Delay(38, phase);
        node38->setTime(1.50f);
        CALL_REGISTER_SKILL_NODE(10343, 38, node38)
    }
    if (noInit == true) {
        return node38;
    }
    return node38;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(10343, 40) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuff>(PhaseNode_If::TRIGGER_FALSE, 82, PhaseNode_AddSkillBuff::FUNC_ADD, &PhaseNode_AddSkillBuff::Add);
    pnode->regTrigger<PhaseNode_AddSkillBuff>(PhaseNode_If::TRIGGER_TRUE, 80, PhaseNode_AddSkillBuff::FUNC_ADD, &PhaseNode_AddSkillBuff::Add);
}

REGISTER_CREATE_SKILL_NODE(10343, 40) {
    auto node40 = GET_SKILL_NODE(40, PhaseNode_If);
    if (node40 == nullptr) {
        node40 = new PhaseNode_If(40, phase);
        CALL_REGISTER_SKILL_NODE(10343, 40, node40)
    }
    if (noInit == true) {
        return node40;
    }
    auto node34 = GET_SKILL_NODE(34, PhaseNode_FindSkillBuff);
    if (node34 != nullptr) node40->setCondition(node34->getResult());
    return node40;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(10343, 47) {
}

REGISTER_CREATE_SKILL_NODE(10343, 47) {
    auto node47 = GET_SKILL_NODE(47, PhaseNode_EndPhase);
    if (node47 == nullptr) {
        node47 = new PhaseNode_EndPhase(47, phase);
        node47->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node47->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10343, 47, node47)
    }
    if (noInit == true) {
        return node47;
    }
    return node47;
}
//--------------------------------------------------------------------------------
// TriggerUpdate
//
REGISTER_REGISTER_SKILL_NODE(10343, 62) {
}

REGISTER_CREATE_SKILL_NODE(10343, 62) {
    auto node62 = GET_SKILL_NODE(62, PhaseNode_TriggerUpdate);
    if (node62 == nullptr) {
        node62 = new PhaseNode_TriggerUpdate(62, phase);
        CALL_REGISTER_SKILL_NODE(10343, 62, node62)
    }
    if (noInit == true) {
        return node62;
    }
    return node62;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(10343, 64) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_PlayEffect::TRIGGER_DONE, 71, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(10343, 64) {
    auto node64 = GET_SKILL_NODE(64, PhaseNode_PlayEffect);
    if (node64 == nullptr) {
        node64 = new PhaseNode_PlayEffect(64, phase);
        node64->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node64->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node64->setEffectID(103431);
        node64->setChangeColor(true);
        node64->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node64->getVars().reserve(3);
        node64->getVars().setVariable<float>(0, .00f);
        node64->getVars().setVariable<float>(1, .00f);
        node64->getVars().setVariable<float>(2, .00f);
        node64->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(10343, 64, node64)
    }
    if (noInit == true) {
        return node64;
    }
    auto node26 = GET_SKILL_NODE(26, PhaseNode_OffsetCalculate);
    if (node26 != nullptr) node64->getVars().setVariable<float>(0, node26->getOutPosX());
    if (node26 != nullptr) node64->getVars().setVariable<float>(1, node26->getOutPosY());
    if (node26 != nullptr) node64->setRotation(node26->getOutRotation());
    return node64;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(10343, 67) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_PlayEffect::TRIGGER_DONE, 124, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10343, 67) {
    auto node67 = GET_SKILL_NODE(67, PhaseNode_PlayEffect);
    if (node67 == nullptr) {
        node67 = new PhaseNode_PlayEffect(67, phase);
        node67->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node67->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node67->setEffectID(103432);
        node67->setChangeColor(true);
        node67->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node67->getVars().reserve(3);
        node67->getVars().setVariable<float>(0, .00f);
        node67->getVars().setVariable<float>(1, .00f);
        node67->getVars().setVariable<float>(2, .00f);
        node67->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(10343, 67, node67)
    }
    if (noInit == true) {
        return node67;
    }
    auto node26 = GET_SKILL_NODE(26, PhaseNode_OffsetCalculate);
    if (node26 != nullptr) node67->getVars().setVariable<float>(0, node26->getOutPosX());
    if (node26 != nullptr) node67->getVars().setVariable<float>(1, node26->getOutPosY());
    if (node26 != nullptr) node67->setRotation(node26->getOutRotation());
    return node67;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(10343, 69) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlayEffect::TRIGGER_DONE, 92, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10343, 69) {
    auto node69 = GET_SKILL_NODE(69, PhaseNode_PlayEffect);
    if (node69 == nullptr) {
        node69 = new PhaseNode_PlayEffect(69, phase);
        node69->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node69->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node69->setEffectID(103433);
        node69->setChangeColor(true);
        node69->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node69->getVars().reserve(3);
        node69->getVars().setVariable<float>(0, .00f);
        node69->getVars().setVariable<float>(1, .00f);
        node69->getVars().setVariable<float>(2, .00f);
        node69->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(10343, 69, node69)
    }
    if (noInit == true) {
        return node69;
    }
    auto node119 = GET_SKILL_NODE(119, PhaseNode_GetLocation);
    auto node100 = GET_SKILL_NODE(100, PhaseNode_GetLineRotation);
    if (node119 != nullptr) node69->getVars().setVariable<float>(0, node119->getX());
    if (node119 != nullptr) node69->getVars().setVariable<float>(1, node119->getY());
    if (node100 != nullptr) node69->setRotation(node100->getRotation());
    return node69;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(10343, 71) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlayEffect::TRIGGER_DONE, 129, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10343, 71) {
    auto node71 = GET_SKILL_NODE(71, PhaseNode_PlayEffect);
    if (node71 == nullptr) {
        node71 = new PhaseNode_PlayEffect(71, phase);
        node71->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node71->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node71->setEffectID(103434);
        node71->setChangeColor(true);
        node71->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node71->getVars().reserve(3);
        node71->getVars().setVariable<float>(0, .00f);
        node71->getVars().setVariable<float>(1, .00f);
        node71->getVars().setVariable<float>(2, .00f);
        node71->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(10343, 71, node71)
    }
    if (noInit == true) {
        return node71;
    }
    auto node26 = GET_SKILL_NODE(26, PhaseNode_OffsetCalculate);
    if (node26 != nullptr) node71->getVars().setVariable<float>(0, node26->getOutPosX());
    if (node26 != nullptr) node71->getVars().setVariable<float>(1, node26->getOutPosY());
    if (node26 != nullptr) node71->setRotation(node26->getOutRotation());
    return node71;
}
//--------------------------------------------------------------------------------
// GetInputObject
//
REGISTER_REGISTER_SKILL_NODE(10343, 74) {
    pnode->resizeTrigger(PhaseNode_GetInputObject::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetRotation>(PhaseNode_GetInputObject::TRIGGER_DONE, 78, PhaseNode_GetRotation::FUNC_DO, &PhaseNode_GetRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(10343, 74) {
    auto node74 = GET_SKILL_NODE(74, PhaseNode_GetInputObject);
    if (node74 == nullptr) {
        node74 = new PhaseNode_GetInputObject(74, phase);
        node74->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        CALL_REGISTER_SKILL_NODE(10343, 74, node74)
    }
    if (noInit == true) {
        return node74;
    }
    return node74;
}
//--------------------------------------------------------------------------------
// AddSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10343, 76) {
    pnode->resizeTrigger(PhaseNode_AddSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_AddSkillBuff::TRIGGER_DONE, 38, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_AddSkillBuff::TRIGGER_DONE, 88, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(10343, 76) {
    auto node76 = GET_SKILL_NODE(76, PhaseNode_AddSkillBuff);
    if (node76 == nullptr) {
        node76 = new PhaseNode_AddSkillBuff(76, phase);
        node76->setConfigID(103431);
        node76->setConfigIDs({});
        node76->setAttribute({{}});
        CALL_REGISTER_SKILL_NODE(10343, 76, node76)
    }
    if (noInit == true) {
        return node76;
    }
    auto node74 = GET_SKILL_NODE(74, PhaseNode_GetInputObject);
    if (node74 != nullptr) node76->setTarget(node74->getSceneObjId());
    return node76;
}
//--------------------------------------------------------------------------------
// GetRotation
//
REGISTER_REGISTER_SKILL_NODE(10343, 78) {
    pnode->resizeTrigger(PhaseNode_GetRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuff>(PhaseNode_GetRotation::TRIGGER_DONE, 76, PhaseNode_AddSkillBuff::FUNC_ADD, &PhaseNode_AddSkillBuff::Add);
}

REGISTER_CREATE_SKILL_NODE(10343, 78) {
    auto node78 = GET_SKILL_NODE(78, PhaseNode_GetRotation);
    if (node78 == nullptr) {
        node78 = new PhaseNode_GetRotation(78, phase);
        node78->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node78->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(10343, 78, node78)
    }
    if (noInit == true) {
        return node78;
    }
    return node78;
}
//--------------------------------------------------------------------------------
// AddSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10343, 80) {
    pnode->resizeTrigger(PhaseNode_AddSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RemoveSkillBuff>(PhaseNode_AddSkillBuff::TRIGGER_DONE, 133, PhaseNode_RemoveSkillBuff::FUNC_REMOVE, &PhaseNode_RemoveSkillBuff::Remove);
}

REGISTER_CREATE_SKILL_NODE(10343, 80) {
    auto node80 = GET_SKILL_NODE(80, PhaseNode_AddSkillBuff);
    if (node80 == nullptr) {
        node80 = new PhaseNode_AddSkillBuff(80, phase);
        node80->setConfigID(103433);
        node80->setConfigIDs({});
        CALL_REGISTER_SKILL_NODE(10343, 80, node80)
    }
    if (noInit == true) {
        return node80;
    }
    auto node74 = GET_SKILL_NODE(74, PhaseNode_GetInputObject);
    auto node146 = GET_SKILL_NODE(146, PhaseNode_GetActorAttribute);
    if (node74 != nullptr) node80->setTarget(node74->getSceneObjId());
    if (node146 != nullptr) node80->setAttribute(node146->getAttribute());
    return node80;
}
//--------------------------------------------------------------------------------
// AddSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10343, 82) {
    pnode->resizeTrigger(PhaseNode_AddSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RemoveSkillBuff>(PhaseNode_AddSkillBuff::TRIGGER_DONE, 133, PhaseNode_RemoveSkillBuff::FUNC_REMOVE, &PhaseNode_RemoveSkillBuff::Remove);
}

REGISTER_CREATE_SKILL_NODE(10343, 82) {
    auto node82 = GET_SKILL_NODE(82, PhaseNode_AddSkillBuff);
    if (node82 == nullptr) {
        node82 = new PhaseNode_AddSkillBuff(82, phase);
        node82->setConfigID(103432);
        node82->setConfigIDs({});
        CALL_REGISTER_SKILL_NODE(10343, 82, node82)
    }
    if (noInit == true) {
        return node82;
    }
    auto node74 = GET_SKILL_NODE(74, PhaseNode_GetInputObject);
    auto node146 = GET_SKILL_NODE(146, PhaseNode_GetActorAttribute);
    if (node74 != nullptr) node82->setTarget(node74->getSceneObjId());
    if (node146 != nullptr) node82->setAttribute(node146->getAttribute());
    return node82;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(10343, 88) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLineRotation>(PhaseNode_GetLocation::TRIGGER_DONE, 100, PhaseNode_GetLineRotation::FUNC_DO, &PhaseNode_GetLineRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(10343, 88) {
    auto node88 = GET_SKILL_NODE(88, PhaseNode_GetLocation);
    if (node88 == nullptr) {
        node88 = new PhaseNode_GetLocation(88, phase);
        node88->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        CALL_REGISTER_SKILL_NODE(10343, 88, node88)
    }
    if (noInit == true) {
        return node88;
    }
    auto node74 = GET_SKILL_NODE(74, PhaseNode_GetInputObject);
    if (node74 != nullptr) node88->setTarget(node74->getSceneObjId());
    return node88;
}
//--------------------------------------------------------------------------------
// MoveNewPene
//
REGISTER_REGISTER_SKILL_NODE(10343, 90) {
    pnode->resizeTrigger(PhaseNode_MoveNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_DestroyCollider>(PhaseNode_MoveNewPene::TRIGGER_DONE, 135, PhaseNode_DestroyCollider::FUNC_DO, &PhaseNode_DestroyCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(10343, 90) {
    auto node90 = GET_SKILL_NODE(90, PhaseNode_MoveNewPene);
    if (node90 == nullptr) {
        node90 = new PhaseNode_MoveNewPene(90, phase);
        node90->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node90->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node90->setPeneType(PhaseNode_MoveNewPene::MoveNewPene_PeneType::Move);
        node90->setPeneValue(35);
        node90->setType(PhaseNode_MoveNewPene::MoveNewPene_Type::Teleport);
        node90->getVars().reserve(2);
        node90->getVars().setVariable<float>(0, .00f);
        node90->getVars().setVariable<float>(1, .00f);
        node90->setreentry(false);
        node90->setStopWhenFail(false);
        node90->setCheckFaction(PhaseNode_MoveNewPene::MoveNewPene_CheckFaction::Enemy);
        CALL_REGISTER_SKILL_NODE(10343, 90, node90)
    }
    if (noInit == true) {
        return node90;
    }
    auto node109 = GET_SKILL_NODE(109, PhaseNode_SpawnCollider);
    auto node94 = GET_SKILL_NODE(94, PhaseNode_OffsetCalculate);
    if (node109 != nullptr) node90->setTarget(node109->getColliderID());
    if (node94 != nullptr) node90->getVars().setVariable<float>(0, node94->getOutPosX());
    if (node94 != nullptr) node90->getVars().setVariable<float>(1, node94->getOutPosY());
    return node90;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10343, 92) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_MoveNewPene>(PhaseNode_Delay::TRIGGER_DONE, 102, PhaseNode_MoveNewPene::FUNC_DO, &PhaseNode_MoveNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(10343, 92) {
    auto node92 = GET_SKILL_NODE(92, PhaseNode_Delay);
    if (node92 == nullptr) {
        node92 = new PhaseNode_Delay(92, phase);
        node92->setTime(.40f);
        CALL_REGISTER_SKILL_NODE(10343, 92, node92)
    }
    if (noInit == true) {
        return node92;
    }
    return node92;
}
//--------------------------------------------------------------------------------
// OffsetCalculate
//
REGISTER_REGISTER_SKILL_NODE(10343, 94) {
    pnode->resizeTrigger(PhaseNode_OffsetCalculate::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnCollider>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 109, PhaseNode_SpawnCollider::FUNC_DO, &PhaseNode_SpawnCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(10343, 94) {
    auto node94 = GET_SKILL_NODE(94, PhaseNode_OffsetCalculate);
    if (node94 == nullptr) {
        node94 = new PhaseNode_OffsetCalculate(94, phase);
        node94->setPosZ(.00f);
        node94->setOffsetX(.00f);
        node94->setOffsetY(-1.50f);
        node94->setOffsetZ(.00f);
        node94->setRotOffset(.00f);
        CALL_REGISTER_SKILL_NODE(10343, 94, node94)
    }
    if (noInit == true) {
        return node94;
    }
    auto node88 = GET_SKILL_NODE(88, PhaseNode_GetLocation);
    auto node100 = GET_SKILL_NODE(100, PhaseNode_GetLineRotation);
    if (node88 != nullptr) node94->setPosX(node88->getX());
    if (node88 != nullptr) node94->setPosY(node88->getY());
    if (node100 != nullptr) node94->setRotation(node100->getRotation());
    return node94;
}
//--------------------------------------------------------------------------------
// GetLineRotation
//
REGISTER_REGISTER_SKILL_NODE(10343, 100) {
    pnode->resizeTrigger(PhaseNode_GetLineRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_OffsetCalculate>(PhaseNode_GetLineRotation::TRIGGER_DONE, 94, PhaseNode_OffsetCalculate::FUNC_DO, &PhaseNode_OffsetCalculate::Do);
}

REGISTER_CREATE_SKILL_NODE(10343, 100) {
    auto node100 = GET_SKILL_NODE(100, PhaseNode_GetLineRotation);
    if (node100 == nullptr) {
        node100 = new PhaseNode_GetLineRotation(100, phase);
        CALL_REGISTER_SKILL_NODE(10343, 100, node100)
    }
    if (noInit == true) {
        return node100;
    }
    auto node13 = GET_SKILL_NODE(13, PhaseNode_GetLocation);
    auto node88 = GET_SKILL_NODE(88, PhaseNode_GetLocation);
    if (node13 != nullptr) node100->setStartX(node13->getX());
    if (node13 != nullptr) node100->setStartY(node13->getY());
    if (node88 != nullptr) node100->setEndX(node88->getX());
    if (node88 != nullptr) node100->setEndY(node88->getY());
    return node100;
}
//--------------------------------------------------------------------------------
// MoveNewPene
//
REGISTER_REGISTER_SKILL_NODE(10343, 102) {
    pnode->resizeTrigger(PhaseNode_MoveNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_DestroyCollider>(PhaseNode_MoveNewPene::TRIGGER_DONE, 113, PhaseNode_DestroyCollider::FUNC_DO, &PhaseNode_DestroyCollider::Do);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_MoveNewPene::TRIGGER_STARTMOVE, 115, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(10343, 102) {
    auto node102 = GET_SKILL_NODE(102, PhaseNode_MoveNewPene);
    if (node102 == nullptr) {
        node102 = new PhaseNode_MoveNewPene(102, phase);
        node102->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node102->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node102->setPeneType(PhaseNode_MoveNewPene::MoveNewPene_PeneType::Move);
        node102->setPeneValue(15);
        node102->setType(PhaseNode_MoveNewPene::MoveNewPene_Type::Charge);
        node102->getVars().reserve(4);
        node102->getVars().setVariable<float>(0, 30.00f);
        node102->getVars().setVariable<float>(1, 3.00f);
        node102->getVars().setVariable<float>(2, .00f);
        node102->getVars().setVariable<float>(3, .00f);
        node102->setreentry(false);
        node102->setStopWhenFail(false);
        node102->setCheckFaction(PhaseNode_MoveNewPene::MoveNewPene_CheckFaction::Enemy);
        CALL_REGISTER_SKILL_NODE(10343, 102, node102)
    }
    if (noInit == true) {
        return node102;
    }
    auto node137 = GET_SKILL_NODE(137, PhaseNode_SpawnCollider);
    auto node100 = GET_SKILL_NODE(100, PhaseNode_GetLineRotation);
    if (node137 != nullptr) node102->setTarget(node137->getColliderID());
    if (node100 != nullptr) node102->getVars().setVariable<float>(2, node100->getRotation());
    return node102;
}
//--------------------------------------------------------------------------------
// SpawnCollider
//
REGISTER_REGISTER_SKILL_NODE(10343, 109) {
    pnode->resizeTrigger(PhaseNode_SpawnCollider::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AttachTo>(PhaseNode_SpawnCollider::TRIGGER_DONE, 111, PhaseNode_AttachTo::FUNC_DO, &PhaseNode_AttachTo::Do);
}

REGISTER_CREATE_SKILL_NODE(10343, 109) {
    auto node109 = GET_SKILL_NODE(109, PhaseNode_SpawnCollider);
    if (node109 == nullptr) {
        node109 = new PhaseNode_SpawnCollider(109, phase);
        node109->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node109->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node109->setMesh("");
        node109->setMeshScale(.00f);
        node109->setEffectID(0);
        node109->setEffectScale(.00f);
        node109->setType(PhaseNode_SpawnCollider::SpawnCollider_Type::Circle);
        node109->setTypeParams(0, .50f);
        node109->setTime(.00f);
        node109->setPosZ(.00f);
        node109->setreentry(false);
        node109->setCheckPeneSound(false);
        CALL_REGISTER_SKILL_NODE(10343, 109, node109)
    }
    if (noInit == true) {
        return node109;
    }
    auto node13 = GET_SKILL_NODE(13, PhaseNode_GetLocation);
    auto node100 = GET_SKILL_NODE(100, PhaseNode_GetLineRotation);
    if (node13 != nullptr) node109->setPosX(node13->getX());
    if (node13 != nullptr) node109->setPosY(node13->getY());
    if (node100 != nullptr) node109->setRotation(node100->getRotation());
    return node109;
}
//--------------------------------------------------------------------------------
// AttachTo
//
REGISTER_REGISTER_SKILL_NODE(10343, 111) {
    pnode->resizeTrigger(PhaseNode_AttachTo::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_MoveNewPene>(PhaseNode_AttachTo::TRIGGER_DONE, 90, PhaseNode_MoveNewPene::FUNC_DO, &PhaseNode_MoveNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(10343, 111) {
    auto node111 = GET_SKILL_NODE(111, PhaseNode_AttachTo);
    if (node111 == nullptr) {
        node111 = new PhaseNode_AttachTo(111, phase);
        node111->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node111->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node111->setChild(0U);
        node111->setChangeRotation(false);
        node111->setreentry(false);
        CALL_REGISTER_SKILL_NODE(10343, 111, node111)
    }
    if (noInit == true) {
        return node111;
    }
    auto node109 = GET_SKILL_NODE(109, PhaseNode_SpawnCollider);
    if (node109 != nullptr) node111->setParent(node109->getColliderID());
    return node111;
}
//--------------------------------------------------------------------------------
// DestroyCollider
//
REGISTER_REGISTER_SKILL_NODE(10343, 113) {
}

REGISTER_CREATE_SKILL_NODE(10343, 113) {
    auto node113 = GET_SKILL_NODE(113, PhaseNode_DestroyCollider);
    if (node113 == nullptr) {
        node113 = new PhaseNode_DestroyCollider(113, phase);
        CALL_REGISTER_SKILL_NODE(10343, 113, node113)
    }
    if (noInit == true) {
        return node113;
    }
    auto node137 = GET_SKILL_NODE(137, PhaseNode_SpawnCollider);
    if (node137 != nullptr) node113->setColliderID(node137->getColliderID());
    return node113;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(10343, 115) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetRotation>(PhaseNode_GetLocation::TRIGGER_DONE, 117, PhaseNode_GetRotation::FUNC_DO, &PhaseNode_GetRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(10343, 115) {
    auto node115 = GET_SKILL_NODE(115, PhaseNode_GetLocation);
    if (node115 == nullptr) {
        node115 = new PhaseNode_GetLocation(115, phase);
        node115->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node115->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(10343, 115, node115)
    }
    if (noInit == true) {
        return node115;
    }
    return node115;
}
//--------------------------------------------------------------------------------
// GetRotation
//
REGISTER_REGISTER_SKILL_NODE(10343, 117) {
    pnode->resizeTrigger(PhaseNode_GetRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_OffsetCalculate>(PhaseNode_GetRotation::TRIGGER_DONE, 26, PhaseNode_OffsetCalculate::FUNC_DO, &PhaseNode_OffsetCalculate::Do);
}

REGISTER_CREATE_SKILL_NODE(10343, 117) {
    auto node117 = GET_SKILL_NODE(117, PhaseNode_GetRotation);
    if (node117 == nullptr) {
        node117 = new PhaseNode_GetRotation(117, phase);
        node117->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node117->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(10343, 117, node117)
    }
    if (noInit == true) {
        return node117;
    }
    return node117;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(10343, 119) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnCollider>(PhaseNode_GetLocation::TRIGGER_DONE, 137, PhaseNode_SpawnCollider::FUNC_DO, &PhaseNode_SpawnCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(10343, 119) {
    auto node119 = GET_SKILL_NODE(119, PhaseNode_GetLocation);
    if (node119 == nullptr) {
        node119 = new PhaseNode_GetLocation(119, phase);
        node119->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node119->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(10343, 119, node119)
    }
    if (noInit == true) {
        return node119;
    }
    return node119;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10343, 121) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_PlaySound::TRIGGER_DONE, 119, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(10343, 121) {
    auto node121 = GET_SKILL_NODE(121, PhaseNode_PlaySound);
    if (node121 == nullptr) {
        node121 = new PhaseNode_PlaySound(121, phase);
        node121->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node121->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node121->setSoundID("SE_Hero134_SkillC_P1");
        node121->setTarget(0U);
        node121->setUsePos(false);
        node121->setPosX(.00f);
        node121->setPosY(.00f);
        node121->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10343, 121, node121)
    }
    if (noInit == true) {
        return node121;
    }
    return node121;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10343, 124) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_PlaySound::TRIGGER_DONE, 64, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(10343, 124) {
    auto node124 = GET_SKILL_NODE(124, PhaseNode_PlaySound);
    if (node124 == nullptr) {
        node124 = new PhaseNode_PlaySound(124, phase);
        node124->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node124->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node124->setSoundID("SE_Hero134_SkillC_P2");
        node124->setTarget(0U);
        node124->setUsePos(false);
        node124->setPosX(.00f);
        node124->setPosY(.00f);
        node124->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10343, 124, node124)
    }
    if (noInit == true) {
        return node124;
    }
    return node124;
}
//--------------------------------------------------------------------------------
// AddSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10343, 126) {
    pnode->resizeTrigger(PhaseNode_AddSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_AddSkillBuff::TRIGGER_DONE, 13, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(10343, 126) {
    auto node126 = GET_SKILL_NODE(126, PhaseNode_AddSkillBuff);
    if (node126 == nullptr) {
        node126 = new PhaseNode_AddSkillBuff(126, phase);
        node126->setConfigID(0);
        node126->setConfigIDs({103434,103401});
        node126->setTarget(0U);
        node126->setAttribute({{}});
        CALL_REGISTER_SKILL_NODE(10343, 126, node126)
    }
    if (noInit == true) {
        return node126;
    }
    return node126;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10343, 129) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CameraXYZShake>(PhaseNode_Delay::TRIGGER_DONE, 131, PhaseNode_CameraXYZShake::FUNC_DO, &PhaseNode_CameraXYZShake::Do);
}

REGISTER_CREATE_SKILL_NODE(10343, 129) {
    auto node129 = GET_SKILL_NODE(129, PhaseNode_Delay);
    if (node129 == nullptr) {
        node129 = new PhaseNode_Delay(129, phase);
        node129->setTime(.30f);
        CALL_REGISTER_SKILL_NODE(10343, 129, node129)
    }
    if (noInit == true) {
        return node129;
    }
    return node129;
}
//--------------------------------------------------------------------------------
// CameraXYZShake
//
REGISTER_REGISTER_SKILL_NODE(10343, 131) {
    pnode->resizeTrigger(PhaseNode_CameraXYZShake::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_FindSkillBuff>(PhaseNode_CameraXYZShake::TRIGGER_DONE, 34, PhaseNode_FindSkillBuff::FUNC_DO, &PhaseNode_FindSkillBuff::Do);
}

REGISTER_CREATE_SKILL_NODE(10343, 131) {
    auto node131 = GET_SKILL_NODE(131, PhaseNode_CameraXYZShake);
    if (node131 == nullptr) {
        node131 = new PhaseNode_CameraXYZShake(131, phase);
        node131->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node131->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node131->setShakeStyle(1);
        node131->setTarget(0U);
        node131->setX(.30f);
        node131->setY(.30f);
        node131->setZ(.30f);
        node131->setDuration(.10f);
        node131->setTimes(2);
        CALL_REGISTER_SKILL_NODE(10343, 131, node131)
    }
    if (noInit == true) {
        return node131;
    }
    return node131;
}
//--------------------------------------------------------------------------------
// RemoveSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10343, 133) {
}

REGISTER_CREATE_SKILL_NODE(10343, 133) {
    auto node133 = GET_SKILL_NODE(133, PhaseNode_RemoveSkillBuff);
    if (node133 == nullptr) {
        node133 = new PhaseNode_RemoveSkillBuff(133, phase);
        node133->setBuffID(0U);
        node133->setBuffIDs({});
        node133->setConfigID(103434);
        node133->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(10343, 133, node133)
    }
    if (noInit == true) {
        return node133;
    }
    return node133;
}
//--------------------------------------------------------------------------------
// DestroyCollider
//
REGISTER_REGISTER_SKILL_NODE(10343, 135) {
    pnode->resizeTrigger(PhaseNode_DestroyCollider::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_DestroyCollider::TRIGGER_DONE, 142, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(10343, 135) {
    auto node135 = GET_SKILL_NODE(135, PhaseNode_DestroyCollider);
    if (node135 == nullptr) {
        node135 = new PhaseNode_DestroyCollider(135, phase);
        CALL_REGISTER_SKILL_NODE(10343, 135, node135)
    }
    if (noInit == true) {
        return node135;
    }
    auto node109 = GET_SKILL_NODE(109, PhaseNode_SpawnCollider);
    if (node109 != nullptr) node135->setColliderID(node109->getColliderID());
    return node135;
}
//--------------------------------------------------------------------------------
// SpawnCollider
//
REGISTER_REGISTER_SKILL_NODE(10343, 137) {
    pnode->resizeTrigger(PhaseNode_SpawnCollider::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AttachTo>(PhaseNode_SpawnCollider::TRIGGER_DONE, 140, PhaseNode_AttachTo::FUNC_DO, &PhaseNode_AttachTo::Do);
}

REGISTER_CREATE_SKILL_NODE(10343, 137) {
    auto node137 = GET_SKILL_NODE(137, PhaseNode_SpawnCollider);
    if (node137 == nullptr) {
        node137 = new PhaseNode_SpawnCollider(137, phase);
        node137->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node137->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node137->setMesh("");
        node137->setMeshScale(.00f);
        node137->setEffectID(0);
        node137->setEffectScale(.00f);
        node137->setType(PhaseNode_SpawnCollider::SpawnCollider_Type::Circle);
        node137->setTypeParams(0, .50f);
        node137->setTime(.00f);
        node137->setPosZ(.00f);
        node137->setRotation(.00f);
        node137->setreentry(false);
        node137->setCheckPeneSound(false);
        CALL_REGISTER_SKILL_NODE(10343, 137, node137)
    }
    if (noInit == true) {
        return node137;
    }
    auto node119 = GET_SKILL_NODE(119, PhaseNode_GetLocation);
    if (node119 != nullptr) node137->setPosX(node119->getX());
    if (node119 != nullptr) node137->setPosY(node119->getY());
    return node137;
}
//--------------------------------------------------------------------------------
// AttachTo
//
REGISTER_REGISTER_SKILL_NODE(10343, 140) {
    pnode->resizeTrigger(PhaseNode_AttachTo::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_AttachTo::TRIGGER_DONE, 69, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(10343, 140) {
    auto node140 = GET_SKILL_NODE(140, PhaseNode_AttachTo);
    if (node140 == nullptr) {
        node140 = new PhaseNode_AttachTo(140, phase);
        node140->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node140->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node140->setChild(0U);
        node140->setChangeRotation(false);
        node140->setreentry(false);
        CALL_REGISTER_SKILL_NODE(10343, 140, node140)
    }
    if (noInit == true) {
        return node140;
    }
    auto node137 = GET_SKILL_NODE(137, PhaseNode_SpawnCollider);
    if (node137 != nullptr) node140->setParent(node137->getColliderID());
    return node140;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(10343, 142) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_PlayEffect::TRIGGER_DONE, 121, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10343, 142) {
    auto node142 = GET_SKILL_NODE(142, PhaseNode_PlayEffect);
    if (node142 == nullptr) {
        node142 = new PhaseNode_PlayEffect(142, phase);
        node142->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node142->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node142->setEffectID(103435);
        node142->setChangeColor(true);
        node142->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node142->getVars().reserve(3);
        node142->getVars().setVariable<float>(0, .00f);
        node142->getVars().setVariable<float>(1, .00f);
        node142->getVars().setVariable<float>(2, .00f);
        node142->setScale(.00f);
        CALL_REGISTER_SKILL_NODE(10343, 142, node142)
    }
    if (noInit == true) {
        return node142;
    }
    auto node94 = GET_SKILL_NODE(94, PhaseNode_OffsetCalculate);
    auto node100 = GET_SKILL_NODE(100, PhaseNode_GetLineRotation);
    if (node94 != nullptr) node142->getVars().setVariable<float>(0, node94->getOutPosX());
    if (node94 != nullptr) node142->getVars().setVariable<float>(1, node94->getOutPosY());
    if (node100 != nullptr) node142->setRotation(node100->getRotation());
    return node142;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(10343, 143) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_ResetCD::TRIGGER_DONE, 144, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10343, 143) {
    auto node143 = GET_SKILL_NODE(143, PhaseNode_ResetCD);
    if (node143 == nullptr) {
        node143 = new PhaseNode_ResetCD(143, phase);
        node143->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node143->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node143->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(10343, 143, node143)
    }
    if (noInit == true) {
        return node143;
    }
    return node143;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10343, 144) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_PlayAnimation::TRIGGER_DONE, 146, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(10343, 144) {
    auto node144 = GET_SKILL_NODE(144, PhaseNode_PlayAnimation);
    if (node144 == nullptr) {
        node144 = new PhaseNode_PlayAnimation(144, phase);
        node144->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node144->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node144->setTarget(0U);
        node144->setAnimation("Skill3S1");
        node144->setParameter("");
        node144->setValue(false);
        CALL_REGISTER_SKILL_NODE(10343, 144, node144)
    }
    if (noInit == true) {
        return node144;
    }
    return node144;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10343, 145) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Disable>(PhaseNode_PlaySound::TRIGGER_DONE, 7, PhaseNode_Disable::FUNC_DO, &PhaseNode_Disable::Do);
}

REGISTER_CREATE_SKILL_NODE(10343, 145) {
    auto node145 = GET_SKILL_NODE(145, PhaseNode_PlaySound);
    if (node145 == nullptr) {
        node145 = new PhaseNode_PlaySound(145, phase);
        node145->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node145->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node145->setSoundID("");
        node145->setTarget(0U);
        node145->setUsePos(false);
        node145->setPosX(.00f);
        node145->setPosY(.00f);
        node145->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10343, 145, node145)
    }
    if (noInit == true) {
        return node145;
    }
    return node145;
}
//--------------------------------------------------------------------------------
// GetActorAttribute
//
REGISTER_REGISTER_SKILL_NODE(10343, 146) {
    pnode->resizeTrigger(PhaseNode_GetActorAttribute::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 145, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10343, 146) {
    auto node146 = GET_SKILL_NODE(146, PhaseNode_GetActorAttribute);
    if (node146 == nullptr) {
        node146 = new PhaseNode_GetActorAttribute(146, phase);
        node146->setTarget(0U);
        node146->setType({});
        CALL_REGISTER_SKILL_NODE(10343, 146, node146)
    }
    if (noInit == true) {
        return node146;
    }
    return node146;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10343, 148) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_IsInterruptType>(PhaseNode_Detect::TRIGGER_ON, 154, PhaseNode_IsInterruptType::FUNC_DO, &PhaseNode_IsInterruptType::Do);
}

REGISTER_CREATE_SKILL_NODE(10343, 148) {
    auto node148 = GET_SKILL_NODE(148, PhaseNode_Detect);
    if (node148 == nullptr) {
        node148 = new PhaseNode_Detect(148, phase);
        node148->setSelf(0U);
        node148->setEvent("daduan_001");
        node148->setType(PhaseNode_Detect::Detect_Type::Interrupt_Skill);
        node148->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10343, 148, node148)
    }
    if (noInit == true) {
        return node148;
    }
    return node148;
}
//--------------------------------------------------------------------------------
// SwitchToInt
//
REGISTER_REGISTER_SKILL_NODE(10343, 149) {
}

REGISTER_CREATE_SKILL_NODE(10343, 149) {
    auto node149 = GET_SKILL_NODE(149, PhaseNode_SwitchToInt);
    if (node149 == nullptr) {
        node149 = new PhaseNode_SwitchToInt(149, phase);
        CALL_REGISTER_SKILL_NODE(10343, 149, node149)
    }
    if (noInit == true) {
        return node149;
    }
    auto variables = node149->getVariables();
    if (variables != nullptr) {
        node149->setSelection(variables->getVariable<int32_t>(Variable_10343_break));
    }
    return node149;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10343, 151) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_RaiseEvent::TRIGGER_DONE, 160, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10343, 151) {
    auto node151 = GET_SKILL_NODE(151, PhaseNode_RaiseEvent);
    if (node151 == nullptr) {
        node151 = new PhaseNode_RaiseEvent(151, phase);
        node151->setEvent("daduan_001");
        node151->setTarget(0U);
        node151->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node151->setTypeParams(0, 0);
        node151->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10343, 151, node151)
    }
    if (noInit == true) {
        return node151;
    }
    return node151;
}
//--------------------------------------------------------------------------------
// StartPreInput
//
REGISTER_REGISTER_SKILL_NODE(10343, 152) {
    pnode->resizeTrigger(PhaseNode_StartPreInput::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuff>(PhaseNode_StartPreInput::TRIGGER_DONE, 126, PhaseNode_AddSkillBuff::FUNC_ADD, &PhaseNode_AddSkillBuff::Add);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_StartPreInput::TRIGGER_DONE, 156, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10343, 152) {
    auto node152 = GET_SKILL_NODE(152, PhaseNode_StartPreInput);
    if (node152 == nullptr) {
        node152 = new PhaseNode_StartPreInput(152, phase);
        node152->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node152->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node152->setDelayTime(.00f);
        CALL_REGISTER_SKILL_NODE(10343, 152, node152)
    }
    if (noInit == true) {
        return node152;
    }
    return node152;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(10343, 153) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_If::TRIGGER_TRUE, 155, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10343, 153) {
    auto node153 = GET_SKILL_NODE(153, PhaseNode_If);
    if (node153 == nullptr) {
        node153 = new PhaseNode_If(153, phase);
        CALL_REGISTER_SKILL_NODE(10343, 153, node153)
    }
    if (noInit == true) {
        return node153;
    }
    auto variables = node153->getVariables();
    if (variables != nullptr) {
        node153->setCondition(variables->getVariable<bool>(Variable_10343_InterruptAnimat));
    }
    return node153;
}
//--------------------------------------------------------------------------------
// IsInterruptType
//
REGISTER_REGISTER_SKILL_NODE(10343, 154) {
    pnode->resizeTrigger(PhaseNode_IsInterruptType::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SwitchToInt>(PhaseNode_IsInterruptType::TRIGGER_BUFF, 149, PhaseNode_SwitchToInt::FUNC_SWITCH, &PhaseNode_SwitchToInt::Switch);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_POSCHANGE, 153, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTAIM, 153, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTFIRE, 153, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTRELOAD, 153, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_USESKILL, 153, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(10343, 154) {
    auto node154 = GET_SKILL_NODE(154, PhaseNode_IsInterruptType);
    if (node154 == nullptr) {
        node154 = new PhaseNode_IsInterruptType(154, phase);
        node154->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node154->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10343, 154, node154)
    }
    if (noInit == true) {
        return node154;
    }
    auto node148 = GET_SKILL_NODE(148, PhaseNode_Detect);
    if (node148 != nullptr) node154->setType(node148->getVars().getVariable<int32_t>(2));
    return node154;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10343, 155) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_PlayAnimation::TRIGGER_DONE, 47, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(10343, 155) {
    auto node155 = GET_SKILL_NODE(155, PhaseNode_PlayAnimation);
    if (node155 == nullptr) {
        node155 = new PhaseNode_PlayAnimation(155, phase);
        node155->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node155->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node155->setTarget(0U);
        node155->setAnimation("Idle");
        node155->setParameter("");
        node155->setValue(false);
        CALL_REGISTER_SKILL_NODE(10343, 155, node155)
    }
    if (noInit == true) {
        return node155;
    }
    return node155;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10343, 156) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_Delay::TRIGGER_DONE, 159, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(10343, 156) {
    auto node156 = GET_SKILL_NODE(156, PhaseNode_Delay);
    if (node156 == nullptr) {
        node156 = new PhaseNode_Delay(156, phase);
        node156->setTime(.20f);
        CALL_REGISTER_SKILL_NODE(10343, 156, node156)
    }
    if (noInit == true) {
        return node156;
    }
    return node156;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(10343, 159) {
}

REGISTER_CREATE_SKILL_NODE(10343, 159) {
    auto node159 = GET_SKILL_NODE(159, PhaseNode_SetBool);
    if (node159 == nullptr) {
        node159 = new PhaseNode_SetBool(159, phase);
        node159->setName("InterruptAnimat");
        node159->setValue(true);
        CALL_REGISTER_SKILL_NODE(10343, 159, node159)
    }
    if (noInit == true) {
        return node159;
    }
    return node159;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10343, 160) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StartPreInput>(PhaseNode_RaiseEvent::TRIGGER_DONE, 152, PhaseNode_StartPreInput::FUNC_DO, &PhaseNode_StartPreInput::Do);
}

REGISTER_CREATE_SKILL_NODE(10343, 160) {
    auto node160 = GET_SKILL_NODE(160, PhaseNode_RaiseEvent);
    if (node160 == nullptr) {
        node160 = new PhaseNode_RaiseEvent(160, phase);
        node160->setEvent("Dead_001");
        node160->setTarget(0U);
        node160->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node160->setTypeParams(0, 0);
        node160->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10343, 160, node160)
    }
    if (noInit == true) {
        return node160;
    }
    return node160;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10343, 161) {
}

REGISTER_CREATE_SKILL_NODE(10343, 161) {
    auto node161 = GET_SKILL_NODE(161, PhaseNode_Detect);
    if (node161 == nullptr) {
        node161 = new PhaseNode_Detect(161, phase);
        node161->setSelf(0U);
        node161->setEvent("Dead_001");
        node161->setType(PhaseNode_Detect::Detect_Type::Actor_Dead);
        node161->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10343, 161, node161)
    }
    if (noInit == true) {
        return node161;
    }
    return node161;
}

//--------------------------------------------------------------------------------
// SkillCreator_10343
//
class SkillCreator_10343 : public SkillCreator {
public:
    SkillCreator_10343() {}
    virtual ~SkillCreator_10343() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_10343

//--------------------------------------------------------------------------------
// SkillPhase_10343
//
class SkillPhase_10343 : public SkillPhase {
public:
    SkillPhase_10343(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_10343() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(10343, 3) // StartPhase
        CASE_CREATE_SKILL_NODE(10343, 7) // Disable
        CASE_CREATE_SKILL_NODE(10343, 13) // GetLocation
        CASE_CREATE_SKILL_NODE(10343, 26) // OffsetCalculate
        CASE_CREATE_SKILL_NODE(10343, 34) // FindSkillBuff
        CASE_CREATE_SKILL_NODE(10343, 38) // Delay
        CASE_CREATE_SKILL_NODE(10343, 40) // If
        CASE_CREATE_SKILL_NODE(10343, 47) // EndPhase
        CASE_CREATE_SKILL_NODE(10343, 62) // TriggerUpdate
        CASE_CREATE_SKILL_NODE(10343, 64) // PlayEffect
        CASE_CREATE_SKILL_NODE(10343, 67) // PlayEffect
        CASE_CREATE_SKILL_NODE(10343, 69) // PlayEffect
        CASE_CREATE_SKILL_NODE(10343, 71) // PlayEffect
        CASE_CREATE_SKILL_NODE(10343, 74) // GetInputObject
        CASE_CREATE_SKILL_NODE(10343, 76) // AddSkillBuff
        CASE_CREATE_SKILL_NODE(10343, 78) // GetRotation
        CASE_CREATE_SKILL_NODE(10343, 80) // AddSkillBuff
        CASE_CREATE_SKILL_NODE(10343, 82) // AddSkillBuff
        CASE_CREATE_SKILL_NODE(10343, 88) // GetLocation
        CASE_CREATE_SKILL_NODE(10343, 90) // MoveNewPene
        CASE_CREATE_SKILL_NODE(10343, 92) // Delay
        CASE_CREATE_SKILL_NODE(10343, 94) // OffsetCalculate
        CASE_CREATE_SKILL_NODE(10343, 100) // GetLineRotation
        CASE_CREATE_SKILL_NODE(10343, 102) // MoveNewPene
        CASE_CREATE_SKILL_NODE(10343, 109) // SpawnCollider
        CASE_CREATE_SKILL_NODE(10343, 111) // AttachTo
        CASE_CREATE_SKILL_NODE(10343, 113) // DestroyCollider
        CASE_CREATE_SKILL_NODE(10343, 115) // GetLocation
        CASE_CREATE_SKILL_NODE(10343, 117) // GetRotation
        CASE_CREATE_SKILL_NODE(10343, 119) // GetLocation
        CASE_CREATE_SKILL_NODE(10343, 121) // PlaySound
        CASE_CREATE_SKILL_NODE(10343, 124) // PlaySound
        CASE_CREATE_SKILL_NODE(10343, 126) // AddSkillBuff
        CASE_CREATE_SKILL_NODE(10343, 129) // Delay
        CASE_CREATE_SKILL_NODE(10343, 131) // CameraXYZShake
        CASE_CREATE_SKILL_NODE(10343, 133) // RemoveSkillBuff
        CASE_CREATE_SKILL_NODE(10343, 135) // DestroyCollider
        CASE_CREATE_SKILL_NODE(10343, 137) // SpawnCollider
        CASE_CREATE_SKILL_NODE(10343, 140) // AttachTo
        CASE_CREATE_SKILL_NODE(10343, 142) // PlayEffect
        CASE_CREATE_SKILL_NODE(10343, 143) // ResetCD
        CASE_CREATE_SKILL_NODE(10343, 144) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10343, 145) // PlaySound
        CASE_CREATE_SKILL_NODE(10343, 146) // GetActorAttribute
        CASE_CREATE_SKILL_NODE(10343, 148) // Detect
        CASE_CREATE_SKILL_NODE(10343, 149) // SwitchToInt
        CASE_CREATE_SKILL_NODE(10343, 151) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10343, 152) // StartPreInput
        CASE_CREATE_SKILL_NODE(10343, 153) // If
        CASE_CREATE_SKILL_NODE(10343, 154) // IsInterruptType
        CASE_CREATE_SKILL_NODE(10343, 155) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10343, 156) // Delay
        CASE_CREATE_SKILL_NODE(10343, 159) // SetBool
        CASE_CREATE_SKILL_NODE(10343, 160) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10343, 161) // Detect
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_10343

SkillLogic* SkillCreator_10343::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //设置变量
    Variable_10343_break = logic->getVariables().setVariable<int32_t>("break", 1);
    Variable_10343_InterruptAnimat = logic->getVariables().setVariable<bool>("InterruptAnimat");
    //创建阶段phase
    auto phase = new SkillPhase_10343(1, logic, 3);
    //设置phase执行器
    phase->setRunPhaseNode(1, 3);
    phase->setRunPhaseNode(2, 62);
    phase->setDetectPhaseNode(3, 148);
    phase->setDetectPhaseNode(3, 161);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_10343::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
