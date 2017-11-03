#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

#include "skill_psnode_addskillbuffs.h"
#include "skill_psnode_areacollisionnewpene.h"
#include "skill_psnode_delay.h"
#include "skill_psnode_endphase.h"
#include "skill_psnode_float2int.h"
#include "skill_psnode_floatoperation.h"
#include "skill_psnode_for.h"
#include "skill_psnode_forcontinue.h"
#include "skill_psnode_getactorattribute.h"
#include "skill_psnode_getlocation.h"
#include "skill_psnode_getrotation.h"
#include "skill_psnode_if.h"
#include "skill_psnode_int2float.h"
#include "skill_psnode_offsetcalculate.h"
#include "skill_psnode_playanimation.h"
#include "skill_psnode_playeffect.h"
#include "skill_psnode_playsound.h"
#include "skill_psnode_resetcd.h"
#include "skill_psnode_skillendnotify.h"
#include "skill_psnode_startphase.h"
#include "skill_psnode_triggerupdate.h"

namespace pvp {

//变量声明
//--------------------------------------------------------------------------------
// StartPhase
//
REGISTER_REGISTER_SKILL_NODE(22104, 3) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_StartPhase::TRIGGER_START, 23, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(22104, 3) {
    auto node3 = GET_SKILL_NODE(3, PhaseNode_StartPhase);
    if (node3 == nullptr) {
        node3 = new PhaseNode_StartPhase(3, phase);
        CALL_REGISTER_SKILL_NODE(22104, 3, node3)
    }
    if (noInit == true) {
        return node3;
    }
    return node3;
}
//--------------------------------------------------------------------------------
// TriggerUpdate
//
REGISTER_REGISTER_SKILL_NODE(22104, 5) {
}

REGISTER_CREATE_SKILL_NODE(22104, 5) {
    auto node5 = GET_SKILL_NODE(5, PhaseNode_TriggerUpdate);
    if (node5 == nullptr) {
        node5 = new PhaseNode_TriggerUpdate(5, phase);
        CALL_REGISTER_SKILL_NODE(22104, 5, node5)
    }
    if (noInit == true) {
        return node5;
    }
    return node5;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(22104, 12) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlayEffect::TRIGGER_DONE, 14, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(22104, 12) {
    auto node12 = GET_SKILL_NODE(12, PhaseNode_PlayEffect);
    if (node12 == nullptr) {
        node12 = new PhaseNode_PlayEffect(12, phase);
        node12->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node12->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node12->setEffectID(1014);
        node12->setChangeColor(false);
        node12->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node12->getVars().reserve(3);
        node12->getVars().setVariable<float>(0, .00f);
        node12->getVars().setVariable<float>(1, .00f);
        node12->getVars().setVariable<float>(2, .20f);
        node12->setRotation(.00f);
        node12->setScale(2.50f);
        CALL_REGISTER_SKILL_NODE(22104, 12, node12)
    }
    if (noInit == true) {
        return node12;
    }
    auto node29 = GET_SKILL_NODE(29, PhaseNode_OffsetCalculate);
    if (node29 != nullptr) node12->getVars().setVariable<float>(0, node29->getOutPosX());
    if (node29 != nullptr) node12->getVars().setVariable<float>(1, node29->getOutPosY());
    return node12;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22104, 14) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_Delay::TRIGGER_DONE, 16, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(22104, 14) {
    auto node14 = GET_SKILL_NODE(14, PhaseNode_Delay);
    if (node14 == nullptr) {
        node14 = new PhaseNode_Delay(14, phase);
        node14->setTime(1.00f);
        CALL_REGISTER_SKILL_NODE(22104, 14, node14)
    }
    if (noInit == true) {
        return node14;
    }
    return node14;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(22104, 16) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_PlayAnimation::TRIGGER_DONE, 43, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(22104, 16) {
    auto node16 = GET_SKILL_NODE(16, PhaseNode_PlayAnimation);
    if (node16 == nullptr) {
        node16 = new PhaseNode_PlayAnimation(16, phase);
        node16->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node16->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node16->setTarget(0U);
        node16->setAnimation("Skill4S2");
        node16->setParameter("");
        node16->setValue(false);
        CALL_REGISTER_SKILL_NODE(22104, 16, node16)
    }
    if (noInit == true) {
        return node16;
    }
    return node16;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(22104, 19) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlayAnimation::TRIGGER_DONE, 58, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(22104, 19) {
    auto node19 = GET_SKILL_NODE(19, PhaseNode_PlayAnimation);
    if (node19 == nullptr) {
        node19 = new PhaseNode_PlayAnimation(19, phase);
        node19->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node19->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node19->setTarget(0U);
        node19->setAnimation("Skill4S3");
        node19->setParameter("");
        node19->setValue(false);
        CALL_REGISTER_SKILL_NODE(22104, 19, node19)
    }
    if (noInit == true) {
        return node19;
    }
    return node19;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(22104, 22) {
}

REGISTER_CREATE_SKILL_NODE(22104, 22) {
    auto node22 = GET_SKILL_NODE(22, PhaseNode_EndPhase);
    if (node22 == nullptr) {
        node22 = new PhaseNode_EndPhase(22, phase);
        node22->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node22->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(22104, 22, node22)
    }
    if (noInit == true) {
        return node22;
    }
    return node22;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(22104, 23) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_ResetCD::TRIGGER_DONE, 24, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(22104, 23) {
    auto node23 = GET_SKILL_NODE(23, PhaseNode_ResetCD);
    if (node23 == nullptr) {
        node23 = new PhaseNode_ResetCD(23, phase);
        node23->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node23->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node23->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(22104, 23, node23)
    }
    if (noInit == true) {
        return node23;
    }
    return node23;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(22104, 24) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_PlayAnimation::TRIGGER_DONE, 25, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(22104, 24) {
    auto node24 = GET_SKILL_NODE(24, PhaseNode_PlayAnimation);
    if (node24 == nullptr) {
        node24 = new PhaseNode_PlayAnimation(24, phase);
        node24->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node24->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node24->setTarget(0U);
        node24->setAnimation("Skill4S1");
        node24->setParameter("");
        node24->setValue(false);
        CALL_REGISTER_SKILL_NODE(22104, 24, node24)
    }
    if (noInit == true) {
        return node24;
    }
    return node24;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(22104, 25) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlaySound::TRIGGER_DONE, 26, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(22104, 25) {
    auto node25 = GET_SKILL_NODE(25, PhaseNode_PlaySound);
    if (node25 == nullptr) {
        node25 = new PhaseNode_PlaySound(25, phase);
        node25->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node25->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node25->setSoundID("");
        node25->setTarget(0U);
        node25->setUsePos(false);
        node25->setPosX(.00f);
        node25->setPosY(.00f);
        node25->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(22104, 25, node25)
    }
    if (noInit == true) {
        return node25;
    }
    return node25;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22104, 26) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_Delay::TRIGGER_DONE, 27, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(22104, 26) {
    auto node26 = GET_SKILL_NODE(26, PhaseNode_Delay);
    if (node26 == nullptr) {
        node26 = new PhaseNode_Delay(26, phase);
        node26->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(22104, 26, node26)
    }
    if (noInit == true) {
        return node26;
    }
    return node26;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(22104, 27) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetRotation>(PhaseNode_GetLocation::TRIGGER_DONE, 28, PhaseNode_GetRotation::FUNC_DO, &PhaseNode_GetRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(22104, 27) {
    auto node27 = GET_SKILL_NODE(27, PhaseNode_GetLocation);
    if (node27 == nullptr) {
        node27 = new PhaseNode_GetLocation(27, phase);
        node27->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node27->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(22104, 27, node27)
    }
    if (noInit == true) {
        return node27;
    }
    return node27;
}
//--------------------------------------------------------------------------------
// GetRotation
//
REGISTER_REGISTER_SKILL_NODE(22104, 28) {
    pnode->resizeTrigger(PhaseNode_GetRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_OffsetCalculate>(PhaseNode_GetRotation::TRIGGER_DONE, 29, PhaseNode_OffsetCalculate::FUNC_DO, &PhaseNode_OffsetCalculate::Do);
}

REGISTER_CREATE_SKILL_NODE(22104, 28) {
    auto node28 = GET_SKILL_NODE(28, PhaseNode_GetRotation);
    if (node28 == nullptr) {
        node28 = new PhaseNode_GetRotation(28, phase);
        node28->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node28->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(22104, 28, node28)
    }
    if (noInit == true) {
        return node28;
    }
    return node28;
}
//--------------------------------------------------------------------------------
// OffsetCalculate
//
REGISTER_REGISTER_SKILL_NODE(22104, 29) {
    pnode->resizeTrigger(PhaseNode_OffsetCalculate::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 12, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(22104, 29) {
    auto node29 = GET_SKILL_NODE(29, PhaseNode_OffsetCalculate);
    if (node29 == nullptr) {
        node29 = new PhaseNode_OffsetCalculate(29, phase);
        node29->setPosZ(.00f);
        node29->setOffsetX(.00f);
        node29->setOffsetY(.00f);
        node29->setOffsetZ(.00f);
        node29->setRotOffset(.00f);
        CALL_REGISTER_SKILL_NODE(22104, 29, node29)
    }
    if (noInit == true) {
        return node29;
    }
    auto node27 = GET_SKILL_NODE(27, PhaseNode_GetLocation);
    auto node28 = GET_SKILL_NODE(28, PhaseNode_GetRotation);
    if (node27 != nullptr) node29->setPosX(node27->getX());
    if (node27 != nullptr) node29->setPosY(node27->getY());
    if (node28 != nullptr) node29->setRotation(node28->getAngle());
    return node29;
}
//--------------------------------------------------------------------------------
// AreaCollisionNewPene
//
REGISTER_REGISTER_SKILL_NODE(22104, 30) {
    pnode->resizeTrigger(PhaseNode_AreaCollisionNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_AreaCollisionNewPene::TRIGGER_DONE, 42, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_AreaCollisionNewPene::TRIGGER_NONE, 40, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(22104, 30) {
    auto node30 = GET_SKILL_NODE(30, PhaseNode_AreaCollisionNewPene);
    if (node30 == nullptr) {
        node30 = new PhaseNode_AreaCollisionNewPene(30, phase);
        node30->setState(PhaseNode_AreaCollisionNewPene::AreaCollisionNewPene_State::Alive);
        node30->setFaction(PhaseNode_AreaCollisionNewPene::AreaCollisionNewPene_Faction::Enemy);
        node30->setOnHero(true);
        node30->setOnMinion(true);
        node30->setOnDestruct(true);
        node30->setOnShield(true);
        node30->setType(PhaseNode_AreaCollisionNewPene::AreaCollisionNewPene_Type::Rect);
        node30->setTypeParams(0, 2.00f);
        node30->setTypeParams(1, 5.00f);
        CALL_REGISTER_SKILL_NODE(22104, 30, node30)
    }
    if (noInit == true) {
        return node30;
    }
    auto node39 = GET_SKILL_NODE(39, PhaseNode_OffsetCalculate);
    if (node39 != nullptr) node30->setPositionX(node39->getOutPosX());
    if (node39 != nullptr) node30->setPositionY(node39->getOutPosY());
    if (node39 != nullptr) node30->setPositionZ(node39->getOutPosZ());
    if (node39 != nullptr) node30->setRotation(node39->getOutRotation());
    return node30;
}
//--------------------------------------------------------------------------------
// For
//
REGISTER_REGISTER_SKILL_NODE(22104, 31) {
    pnode->resizeTrigger(PhaseNode_For::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_FloatOperation>(PhaseNode_For::TRIGGER_DO, 34, PhaseNode_FloatOperation::FUNC_OPERATION, &PhaseNode_FloatOperation::Operation);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_For::TRIGGER_DONE, 19, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(22104, 31) {
    auto node31 = GET_SKILL_NODE(31, PhaseNode_For);
    if (node31 == nullptr) {
        node31 = new PhaseNode_For(31, phase);
        node31->setBegin(0);
        node31->setIncrease(1);
        CALL_REGISTER_SKILL_NODE(22104, 31, node31)
    }
    if (noInit == true) {
        return node31;
    }
    auto node33 = GET_SKILL_NODE(33, PhaseNode_Float2Int);
    if (node33 != nullptr) node31->setEnd(node33->getInt());
    return node31;
}
//--------------------------------------------------------------------------------
// FloatOperation
//
REGISTER_REGISTER_SKILL_NODE(22104, 32) {
    pnode->resizeTrigger(PhaseNode_FloatOperation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Float2Int>(PhaseNode_FloatOperation::TRIGGER_DONE, 33, PhaseNode_Float2Int::FUNC_DO, &PhaseNode_Float2Int::Do);
}

REGISTER_CREATE_SKILL_NODE(22104, 32) {
    auto node32 = GET_SKILL_NODE(32, PhaseNode_FloatOperation);
    if (node32 == nullptr) {
        node32 = new PhaseNode_FloatOperation(32, phase);
        node32->setBase(1.00f);
        node32->setValue(.05f);
        node32->setMethod(PhaseNode_FloatOperation::FloatOperation_Method::Divis);
        CALL_REGISTER_SKILL_NODE(22104, 32, node32)
    }
    if (noInit == true) {
        return node32;
    }
    return node32;
}
//--------------------------------------------------------------------------------
// Float2Int
//
REGISTER_REGISTER_SKILL_NODE(22104, 33) {
    pnode->resizeTrigger(PhaseNode_Float2Int::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_For>(PhaseNode_Float2Int::TRIGGER_DONE, 31, PhaseNode_For::FUNC_START, &PhaseNode_For::Start);
}

REGISTER_CREATE_SKILL_NODE(22104, 33) {
    auto node33 = GET_SKILL_NODE(33, PhaseNode_Float2Int);
    if (node33 == nullptr) {
        node33 = new PhaseNode_Float2Int(33, phase);
        CALL_REGISTER_SKILL_NODE(22104, 33, node33)
    }
    if (noInit == true) {
        return node33;
    }
    auto node32 = GET_SKILL_NODE(32, PhaseNode_FloatOperation);
    if (node32 != nullptr) node33->setFloat(node32->getFinal());
    return node33;
}
//--------------------------------------------------------------------------------
// FloatOperation
//
REGISTER_REGISTER_SKILL_NODE(22104, 34) {
    pnode->resizeTrigger(PhaseNode_FloatOperation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Int2Float>(PhaseNode_FloatOperation::TRIGGER_DONE, 35, PhaseNode_Int2Float::FUNC_DO, &PhaseNode_Int2Float::Do);
}

REGISTER_CREATE_SKILL_NODE(22104, 34) {
    auto node34 = GET_SKILL_NODE(34, PhaseNode_FloatOperation);
    if (node34 == nullptr) {
        node34 = new PhaseNode_FloatOperation(34, phase);
        node34->setBase(360.00f);
        node34->setMethod(PhaseNode_FloatOperation::FloatOperation_Method::Divis);
        CALL_REGISTER_SKILL_NODE(22104, 34, node34)
    }
    if (noInit == true) {
        return node34;
    }
    auto node32 = GET_SKILL_NODE(32, PhaseNode_FloatOperation);
    if (node32 != nullptr) node34->setValue(node32->getFinal());
    return node34;
}
//--------------------------------------------------------------------------------
// Int2Float
//
REGISTER_REGISTER_SKILL_NODE(22104, 35) {
    pnode->resizeTrigger(PhaseNode_Int2Float::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_FloatOperation>(PhaseNode_Int2Float::TRIGGER_DONE, 36, PhaseNode_FloatOperation::FUNC_OPERATION, &PhaseNode_FloatOperation::Operation);
}

REGISTER_CREATE_SKILL_NODE(22104, 35) {
    auto node35 = GET_SKILL_NODE(35, PhaseNode_Int2Float);
    if (node35 == nullptr) {
        node35 = new PhaseNode_Int2Float(35, phase);
        CALL_REGISTER_SKILL_NODE(22104, 35, node35)
    }
    if (noInit == true) {
        return node35;
    }
    auto node31 = GET_SKILL_NODE(31, PhaseNode_For);
    if (node31 != nullptr) node35->setInt(node31->getValue());
    return node35;
}
//--------------------------------------------------------------------------------
// FloatOperation
//
REGISTER_REGISTER_SKILL_NODE(22104, 36) {
    pnode->resizeTrigger(PhaseNode_FloatOperation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_FloatOperation>(PhaseNode_FloatOperation::TRIGGER_DONE, 37, PhaseNode_FloatOperation::FUNC_OPERATION, &PhaseNode_FloatOperation::Operation);
}

REGISTER_CREATE_SKILL_NODE(22104, 36) {
    auto node36 = GET_SKILL_NODE(36, PhaseNode_FloatOperation);
    if (node36 == nullptr) {
        node36 = new PhaseNode_FloatOperation(36, phase);
        node36->setMethod(PhaseNode_FloatOperation::FloatOperation_Method::Multi);
        CALL_REGISTER_SKILL_NODE(22104, 36, node36)
    }
    if (noInit == true) {
        return node36;
    }
    auto node34 = GET_SKILL_NODE(34, PhaseNode_FloatOperation);
    auto node35 = GET_SKILL_NODE(35, PhaseNode_Int2Float);
    if (node34 != nullptr) node36->setBase(node34->getFinal());
    if (node35 != nullptr) node36->setValue(node35->getFloat());
    return node36;
}
//--------------------------------------------------------------------------------
// FloatOperation
//
REGISTER_REGISTER_SKILL_NODE(22104, 37) {
    pnode->resizeTrigger(PhaseNode_FloatOperation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_OffsetCalculate>(PhaseNode_FloatOperation::TRIGGER_DONE, 39, PhaseNode_OffsetCalculate::FUNC_DO, &PhaseNode_OffsetCalculate::Do);
}

REGISTER_CREATE_SKILL_NODE(22104, 37) {
    auto node37 = GET_SKILL_NODE(37, PhaseNode_FloatOperation);
    if (node37 == nullptr) {
        node37 = new PhaseNode_FloatOperation(37, phase);
        node37->setMethod(PhaseNode_FloatOperation::FloatOperation_Method::Sub);
        CALL_REGISTER_SKILL_NODE(22104, 37, node37)
    }
    if (noInit == true) {
        return node37;
    }
    auto node29 = GET_SKILL_NODE(29, PhaseNode_OffsetCalculate);
    auto node36 = GET_SKILL_NODE(36, PhaseNode_FloatOperation);
    if (node29 != nullptr) node37->setBase(node29->getOutRotation());
    if (node36 != nullptr) node37->setValue(node36->getFinal());
    return node37;
}
//--------------------------------------------------------------------------------
// ForContinue
//
REGISTER_REGISTER_SKILL_NODE(22104, 38) {
}

REGISTER_CREATE_SKILL_NODE(22104, 38) {
    auto node38 = GET_SKILL_NODE(38, PhaseNode_ForContinue);
    if (node38 == nullptr) {
        node38 = new PhaseNode_ForContinue(38, phase);
        CALL_REGISTER_SKILL_NODE(22104, 38, node38)
    }
    if (noInit == true) {
        return node38;
    }
    auto node31 = GET_SKILL_NODE(31, PhaseNode_For);
    if (node31 != nullptr) node38->setFID(node31->getFID());
    return node38;
}
//--------------------------------------------------------------------------------
// OffsetCalculate
//
REGISTER_REGISTER_SKILL_NODE(22104, 39) {
    pnode->resizeTrigger(PhaseNode_OffsetCalculate::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 57, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(22104, 39) {
    auto node39 = GET_SKILL_NODE(39, PhaseNode_OffsetCalculate);
    if (node39 == nullptr) {
        node39 = new PhaseNode_OffsetCalculate(39, phase);
        node39->setOffsetX(.00f);
        node39->setOffsetY(5.00f);
        node39->setOffsetZ(.00f);
        node39->setRotOffset(.00f);
        CALL_REGISTER_SKILL_NODE(22104, 39, node39)
    }
    if (noInit == true) {
        return node39;
    }
    auto node29 = GET_SKILL_NODE(29, PhaseNode_OffsetCalculate);
    auto node37 = GET_SKILL_NODE(37, PhaseNode_FloatOperation);
    if (node29 != nullptr) node39->setPosX(node29->getOutPosX());
    if (node29 != nullptr) node39->setPosY(node29->getOutPosY());
    if (node29 != nullptr) node39->setPosZ(node29->getOutPosZ());
    if (node37 != nullptr) node39->setRotation(node37->getFinal());
    return node39;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22104, 40) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ForContinue>(PhaseNode_Delay::TRIGGER_DONE, 38, PhaseNode_ForContinue::FUNC_DO, &PhaseNode_ForContinue::Do);
}

REGISTER_CREATE_SKILL_NODE(22104, 40) {
    auto node40 = GET_SKILL_NODE(40, PhaseNode_Delay);
    if (node40 == nullptr) {
        node40 = new PhaseNode_Delay(40, phase);
        node40->setTime(.05f);
        CALL_REGISTER_SKILL_NODE(22104, 40, node40)
    }
    if (noInit == true) {
        return node40;
    }
    return node40;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(22104, 41) {
    pnode->resizeTrigger(PhaseNode_AddSkillBuffs::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_AddSkillBuffs::TRIGGER_DONE, 40, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(22104, 41) {
    auto node41 = GET_SKILL_NODE(41, PhaseNode_AddSkillBuffs);
    if (node41 == nullptr) {
        node41 = new PhaseNode_AddSkillBuffs(41, phase);
        node41->setConfigID({11});
        CALL_REGISTER_SKILL_NODE(22104, 41, node41)
    }
    if (noInit == true) {
        return node41;
    }
    auto node30 = GET_SKILL_NODE(30, PhaseNode_AreaCollisionNewPene);
    auto node42 = GET_SKILL_NODE(42, PhaseNode_GetActorAttribute);
    if (node30 != nullptr) node41->setTarget(node30->getColliders());
    if (node42 != nullptr) node41->setAttribute(node42->getAttribute());
    return node41;
}
//--------------------------------------------------------------------------------
// GetActorAttribute
//
REGISTER_REGISTER_SKILL_NODE(22104, 42) {
    pnode->resizeTrigger(PhaseNode_GetActorAttribute::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 41, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
}

REGISTER_CREATE_SKILL_NODE(22104, 42) {
    auto node42 = GET_SKILL_NODE(42, PhaseNode_GetActorAttribute);
    if (node42 == nullptr) {
        node42 = new PhaseNode_GetActorAttribute(42, phase);
        node42->setTarget(0U);
        node42->setType({202});
        CALL_REGISTER_SKILL_NODE(22104, 42, node42)
    }
    if (noInit == true) {
        return node42;
    }
    return node42;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(22104, 43) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_FloatOperation>(PhaseNode_If::TRIGGER_FALSE, 44, PhaseNode_FloatOperation::FUNC_OPERATION, &PhaseNode_FloatOperation::Operation);
    pnode->regTrigger<PhaseNode_FloatOperation>(PhaseNode_If::TRIGGER_TRUE, 32, PhaseNode_FloatOperation::FUNC_OPERATION, &PhaseNode_FloatOperation::Operation);
}

REGISTER_CREATE_SKILL_NODE(22104, 43) {
    auto node43 = GET_SKILL_NODE(43, PhaseNode_If);
    if (node43 == nullptr) {
        node43 = new PhaseNode_If(43, phase);
        node43->setCondition(true);
        CALL_REGISTER_SKILL_NODE(22104, 43, node43)
    }
    if (noInit == true) {
        return node43;
    }
    return node43;
}
//--------------------------------------------------------------------------------
// FloatOperation
//
REGISTER_REGISTER_SKILL_NODE(22104, 44) {
    pnode->resizeTrigger(PhaseNode_FloatOperation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Float2Int>(PhaseNode_FloatOperation::TRIGGER_DONE, 45, PhaseNode_Float2Int::FUNC_DO, &PhaseNode_Float2Int::Do);
}

REGISTER_CREATE_SKILL_NODE(22104, 44) {
    auto node44 = GET_SKILL_NODE(44, PhaseNode_FloatOperation);
    if (node44 == nullptr) {
        node44 = new PhaseNode_FloatOperation(44, phase);
        node44->setBase(1.00f);
        node44->setValue(.05f);
        node44->setMethod(PhaseNode_FloatOperation::FloatOperation_Method::Divis);
        CALL_REGISTER_SKILL_NODE(22104, 44, node44)
    }
    if (noInit == true) {
        return node44;
    }
    return node44;
}
//--------------------------------------------------------------------------------
// Float2Int
//
REGISTER_REGISTER_SKILL_NODE(22104, 45) {
    pnode->resizeTrigger(PhaseNode_Float2Int::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_For>(PhaseNode_Float2Int::TRIGGER_DONE, 46, PhaseNode_For::FUNC_START, &PhaseNode_For::Start);
}

REGISTER_CREATE_SKILL_NODE(22104, 45) {
    auto node45 = GET_SKILL_NODE(45, PhaseNode_Float2Int);
    if (node45 == nullptr) {
        node45 = new PhaseNode_Float2Int(45, phase);
        CALL_REGISTER_SKILL_NODE(22104, 45, node45)
    }
    if (noInit == true) {
        return node45;
    }
    auto node44 = GET_SKILL_NODE(44, PhaseNode_FloatOperation);
    if (node44 != nullptr) node45->setFloat(node44->getFinal());
    return node45;
}
//--------------------------------------------------------------------------------
// For
//
REGISTER_REGISTER_SKILL_NODE(22104, 46) {
    pnode->resizeTrigger(PhaseNode_For::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_FloatOperation>(PhaseNode_For::TRIGGER_DO, 47, PhaseNode_FloatOperation::FUNC_OPERATION, &PhaseNode_FloatOperation::Operation);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_For::TRIGGER_DONE, 19, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(22104, 46) {
    auto node46 = GET_SKILL_NODE(46, PhaseNode_For);
    if (node46 == nullptr) {
        node46 = new PhaseNode_For(46, phase);
        node46->setBegin(0);
        node46->setIncrease(1);
        CALL_REGISTER_SKILL_NODE(22104, 46, node46)
    }
    if (noInit == true) {
        return node46;
    }
    auto node45 = GET_SKILL_NODE(45, PhaseNode_Float2Int);
    if (node45 != nullptr) node46->setEnd(node45->getInt());
    return node46;
}
//--------------------------------------------------------------------------------
// FloatOperation
//
REGISTER_REGISTER_SKILL_NODE(22104, 47) {
    pnode->resizeTrigger(PhaseNode_FloatOperation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Int2Float>(PhaseNode_FloatOperation::TRIGGER_DONE, 48, PhaseNode_Int2Float::FUNC_DO, &PhaseNode_Int2Float::Do);
}

REGISTER_CREATE_SKILL_NODE(22104, 47) {
    auto node47 = GET_SKILL_NODE(47, PhaseNode_FloatOperation);
    if (node47 == nullptr) {
        node47 = new PhaseNode_FloatOperation(47, phase);
        node47->setBase(360.00f);
        node47->setMethod(PhaseNode_FloatOperation::FloatOperation_Method::Divis);
        CALL_REGISTER_SKILL_NODE(22104, 47, node47)
    }
    if (noInit == true) {
        return node47;
    }
    auto node44 = GET_SKILL_NODE(44, PhaseNode_FloatOperation);
    if (node44 != nullptr) node47->setValue(node44->getFinal());
    return node47;
}
//--------------------------------------------------------------------------------
// Int2Float
//
REGISTER_REGISTER_SKILL_NODE(22104, 48) {
    pnode->resizeTrigger(PhaseNode_Int2Float::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_FloatOperation>(PhaseNode_Int2Float::TRIGGER_DONE, 49, PhaseNode_FloatOperation::FUNC_OPERATION, &PhaseNode_FloatOperation::Operation);
}

REGISTER_CREATE_SKILL_NODE(22104, 48) {
    auto node48 = GET_SKILL_NODE(48, PhaseNode_Int2Float);
    if (node48 == nullptr) {
        node48 = new PhaseNode_Int2Float(48, phase);
        CALL_REGISTER_SKILL_NODE(22104, 48, node48)
    }
    if (noInit == true) {
        return node48;
    }
    auto node46 = GET_SKILL_NODE(46, PhaseNode_For);
    if (node46 != nullptr) node48->setInt(node46->getValue());
    return node48;
}
//--------------------------------------------------------------------------------
// FloatOperation
//
REGISTER_REGISTER_SKILL_NODE(22104, 49) {
    pnode->resizeTrigger(PhaseNode_FloatOperation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_FloatOperation>(PhaseNode_FloatOperation::TRIGGER_DONE, 50, PhaseNode_FloatOperation::FUNC_OPERATION, &PhaseNode_FloatOperation::Operation);
}

REGISTER_CREATE_SKILL_NODE(22104, 49) {
    auto node49 = GET_SKILL_NODE(49, PhaseNode_FloatOperation);
    if (node49 == nullptr) {
        node49 = new PhaseNode_FloatOperation(49, phase);
        node49->setMethod(PhaseNode_FloatOperation::FloatOperation_Method::Multi);
        CALL_REGISTER_SKILL_NODE(22104, 49, node49)
    }
    if (noInit == true) {
        return node49;
    }
    auto node47 = GET_SKILL_NODE(47, PhaseNode_FloatOperation);
    auto node48 = GET_SKILL_NODE(48, PhaseNode_Int2Float);
    if (node47 != nullptr) node49->setBase(node47->getFinal());
    if (node48 != nullptr) node49->setValue(node48->getFloat());
    return node49;
}
//--------------------------------------------------------------------------------
// FloatOperation
//
REGISTER_REGISTER_SKILL_NODE(22104, 50) {
    pnode->resizeTrigger(PhaseNode_FloatOperation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_OffsetCalculate>(PhaseNode_FloatOperation::TRIGGER_DONE, 51, PhaseNode_OffsetCalculate::FUNC_DO, &PhaseNode_OffsetCalculate::Do);
}

REGISTER_CREATE_SKILL_NODE(22104, 50) {
    auto node50 = GET_SKILL_NODE(50, PhaseNode_FloatOperation);
    if (node50 == nullptr) {
        node50 = new PhaseNode_FloatOperation(50, phase);
        node50->setMethod(PhaseNode_FloatOperation::FloatOperation_Method::Add);
        CALL_REGISTER_SKILL_NODE(22104, 50, node50)
    }
    if (noInit == true) {
        return node50;
    }
    auto node29 = GET_SKILL_NODE(29, PhaseNode_OffsetCalculate);
    auto node49 = GET_SKILL_NODE(49, PhaseNode_FloatOperation);
    if (node29 != nullptr) node50->setBase(node29->getOutRotation());
    if (node49 != nullptr) node50->setValue(node49->getFinal());
    return node50;
}
//--------------------------------------------------------------------------------
// OffsetCalculate
//
REGISTER_REGISTER_SKILL_NODE(22104, 51) {
    pnode->resizeTrigger(PhaseNode_OffsetCalculate::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AreaCollisionNewPene>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 52, PhaseNode_AreaCollisionNewPene::FUNC_DO, &PhaseNode_AreaCollisionNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(22104, 51) {
    auto node51 = GET_SKILL_NODE(51, PhaseNode_OffsetCalculate);
    if (node51 == nullptr) {
        node51 = new PhaseNode_OffsetCalculate(51, phase);
        node51->setOffsetX(.00f);
        node51->setOffsetY(5.00f);
        node51->setOffsetZ(.00f);
        node51->setRotOffset(.00f);
        CALL_REGISTER_SKILL_NODE(22104, 51, node51)
    }
    if (noInit == true) {
        return node51;
    }
    auto node29 = GET_SKILL_NODE(29, PhaseNode_OffsetCalculate);
    auto node50 = GET_SKILL_NODE(50, PhaseNode_FloatOperation);
    if (node29 != nullptr) node51->setPosX(node29->getOutPosX());
    if (node29 != nullptr) node51->setPosY(node29->getOutPosY());
    if (node29 != nullptr) node51->setPosZ(node29->getOutPosZ());
    if (node50 != nullptr) node51->setRotation(node50->getFinal());
    return node51;
}
//--------------------------------------------------------------------------------
// AreaCollisionNewPene
//
REGISTER_REGISTER_SKILL_NODE(22104, 52) {
    pnode->resizeTrigger(PhaseNode_AreaCollisionNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_AreaCollisionNewPene::TRIGGER_DONE, 53, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_AreaCollisionNewPene::TRIGGER_NONE, 55, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(22104, 52) {
    auto node52 = GET_SKILL_NODE(52, PhaseNode_AreaCollisionNewPene);
    if (node52 == nullptr) {
        node52 = new PhaseNode_AreaCollisionNewPene(52, phase);
        node52->setState(PhaseNode_AreaCollisionNewPene::AreaCollisionNewPene_State::Alive);
        node52->setFaction(PhaseNode_AreaCollisionNewPene::AreaCollisionNewPene_Faction::Enemy);
        node52->setOnHero(true);
        node52->setOnMinion(true);
        node52->setOnDestruct(true);
        node52->setOnShield(true);
        node52->setType(PhaseNode_AreaCollisionNewPene::AreaCollisionNewPene_Type::Rect);
        node52->setTypeParams(0, 2.00f);
        node52->setTypeParams(1, 5.00f);
        CALL_REGISTER_SKILL_NODE(22104, 52, node52)
    }
    if (noInit == true) {
        return node52;
    }
    auto node51 = GET_SKILL_NODE(51, PhaseNode_OffsetCalculate);
    if (node51 != nullptr) node52->setPositionX(node51->getOutPosX());
    if (node51 != nullptr) node52->setPositionY(node51->getOutPosY());
    if (node51 != nullptr) node52->setPositionZ(node51->getOutPosZ());
    if (node51 != nullptr) node52->setRotation(node51->getOutRotation());
    return node52;
}
//--------------------------------------------------------------------------------
// GetActorAttribute
//
REGISTER_REGISTER_SKILL_NODE(22104, 53) {
    pnode->resizeTrigger(PhaseNode_GetActorAttribute::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 54, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
}

REGISTER_CREATE_SKILL_NODE(22104, 53) {
    auto node53 = GET_SKILL_NODE(53, PhaseNode_GetActorAttribute);
    if (node53 == nullptr) {
        node53 = new PhaseNode_GetActorAttribute(53, phase);
        node53->setTarget(0U);
        node53->setType({202});
        CALL_REGISTER_SKILL_NODE(22104, 53, node53)
    }
    if (noInit == true) {
        return node53;
    }
    return node53;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(22104, 54) {
    pnode->resizeTrigger(PhaseNode_AddSkillBuffs::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_AddSkillBuffs::TRIGGER_DONE, 55, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(22104, 54) {
    auto node54 = GET_SKILL_NODE(54, PhaseNode_AddSkillBuffs);
    if (node54 == nullptr) {
        node54 = new PhaseNode_AddSkillBuffs(54, phase);
        node54->setConfigID({11});
        CALL_REGISTER_SKILL_NODE(22104, 54, node54)
    }
    if (noInit == true) {
        return node54;
    }
    auto node52 = GET_SKILL_NODE(52, PhaseNode_AreaCollisionNewPene);
    auto node53 = GET_SKILL_NODE(53, PhaseNode_GetActorAttribute);
    if (node52 != nullptr) node54->setTarget(node52->getColliders());
    if (node53 != nullptr) node54->setAttribute(node53->getAttribute());
    return node54;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22104, 55) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ForContinue>(PhaseNode_Delay::TRIGGER_DONE, 56, PhaseNode_ForContinue::FUNC_DO, &PhaseNode_ForContinue::Do);
}

REGISTER_CREATE_SKILL_NODE(22104, 55) {
    auto node55 = GET_SKILL_NODE(55, PhaseNode_Delay);
    if (node55 == nullptr) {
        node55 = new PhaseNode_Delay(55, phase);
        node55->setTime(.05f);
        CALL_REGISTER_SKILL_NODE(22104, 55, node55)
    }
    if (noInit == true) {
        return node55;
    }
    return node55;
}
//--------------------------------------------------------------------------------
// ForContinue
//
REGISTER_REGISTER_SKILL_NODE(22104, 56) {
}

REGISTER_CREATE_SKILL_NODE(22104, 56) {
    auto node56 = GET_SKILL_NODE(56, PhaseNode_ForContinue);
    if (node56 == nullptr) {
        node56 = new PhaseNode_ForContinue(56, phase);
        CALL_REGISTER_SKILL_NODE(22104, 56, node56)
    }
    if (noInit == true) {
        return node56;
    }
    auto node46 = GET_SKILL_NODE(46, PhaseNode_For);
    if (node46 != nullptr) node56->setFID(node46->getFID());
    return node56;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(22104, 57) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AreaCollisionNewPene>(PhaseNode_PlayEffect::TRIGGER_DONE, 30, PhaseNode_AreaCollisionNewPene::FUNC_DO, &PhaseNode_AreaCollisionNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(22104, 57) {
    auto node57 = GET_SKILL_NODE(57, PhaseNode_PlayEffect);
    if (node57 == nullptr) {
        node57 = new PhaseNode_PlayEffect(57, phase);
        node57->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node57->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node57->setEffectID(221022);
        node57->setChangeColor(false);
        node57->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node57->getVars().reserve(3);
        node57->getVars().setVariable<float>(0, .00f);
        node57->getVars().setVariable<float>(1, .00f);
        node57->getVars().setVariable<float>(2, .00f);
        node57->setScale(.00f);
        CALL_REGISTER_SKILL_NODE(22104, 57, node57)
    }
    if (noInit == true) {
        return node57;
    }
    auto node39 = GET_SKILL_NODE(39, PhaseNode_OffsetCalculate);
    if (node39 != nullptr) node57->getVars().setVariable<float>(0, node39->getOutPosX());
    if (node39 != nullptr) node57->getVars().setVariable<float>(1, node39->getOutPosY());
    if (node39 != nullptr) node57->getVars().setVariable<float>(2, node39->getOutPosZ());
    if (node39 != nullptr) node57->setRotation(node39->getOutRotation());
    return node57;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(22104, 58) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_Delay::TRIGGER_DONE, 60, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(22104, 58) {
    auto node58 = GET_SKILL_NODE(58, PhaseNode_Delay);
    if (node58 == nullptr) {
        node58 = new PhaseNode_Delay(58, phase);
        node58->setTime(.47f);
        CALL_REGISTER_SKILL_NODE(22104, 58, node58)
    }
    if (noInit == true) {
        return node58;
    }
    return node58;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(22104, 59) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 22, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(22104, 59) {
    auto node59 = GET_SKILL_NODE(59, PhaseNode_SkillEndNotify);
    if (node59 == nullptr) {
        node59 = new PhaseNode_SkillEndNotify(59, phase);
        node59->setReturnType(false);
        CALL_REGISTER_SKILL_NODE(22104, 59, node59)
    }
    if (noInit == true) {
        return node59;
    }
    return node59;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(22104, 60) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_FALSE, 61, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_TRUE, 59, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
}

REGISTER_CREATE_SKILL_NODE(22104, 60) {
    auto node60 = GET_SKILL_NODE(60, PhaseNode_If);
    if (node60 == nullptr) {
        node60 = new PhaseNode_If(60, phase);
        node60->setCondition(false);
        CALL_REGISTER_SKILL_NODE(22104, 60, node60)
    }
    if (noInit == true) {
        return node60;
    }
    return node60;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(22104, 61) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 22, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(22104, 61) {
    auto node61 = GET_SKILL_NODE(61, PhaseNode_SkillEndNotify);
    if (node61 == nullptr) {
        node61 = new PhaseNode_SkillEndNotify(61, phase);
        node61->setReturnType(true);
        CALL_REGISTER_SKILL_NODE(22104, 61, node61)
    }
    if (noInit == true) {
        return node61;
    }
    return node61;
}

//--------------------------------------------------------------------------------
// SkillCreator_22104
//
class SkillCreator_22104 : public SkillCreator {
public:
    SkillCreator_22104() {}
    virtual ~SkillCreator_22104() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_22104

//--------------------------------------------------------------------------------
// SkillPhase_22104
//
class SkillPhase_22104 : public SkillPhase {
public:
    SkillPhase_22104(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_22104() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(22104, 3) // StartPhase
        CASE_CREATE_SKILL_NODE(22104, 5) // TriggerUpdate
        CASE_CREATE_SKILL_NODE(22104, 12) // PlayEffect
        CASE_CREATE_SKILL_NODE(22104, 14) // Delay
        CASE_CREATE_SKILL_NODE(22104, 16) // PlayAnimation
        CASE_CREATE_SKILL_NODE(22104, 19) // PlayAnimation
        CASE_CREATE_SKILL_NODE(22104, 22) // EndPhase
        CASE_CREATE_SKILL_NODE(22104, 23) // ResetCD
        CASE_CREATE_SKILL_NODE(22104, 24) // PlayAnimation
        CASE_CREATE_SKILL_NODE(22104, 25) // PlaySound
        CASE_CREATE_SKILL_NODE(22104, 26) // Delay
        CASE_CREATE_SKILL_NODE(22104, 27) // GetLocation
        CASE_CREATE_SKILL_NODE(22104, 28) // GetRotation
        CASE_CREATE_SKILL_NODE(22104, 29) // OffsetCalculate
        CASE_CREATE_SKILL_NODE(22104, 30) // AreaCollisionNewPene
        CASE_CREATE_SKILL_NODE(22104, 31) // For
        CASE_CREATE_SKILL_NODE(22104, 32) // FloatOperation
        CASE_CREATE_SKILL_NODE(22104, 33) // Float2Int
        CASE_CREATE_SKILL_NODE(22104, 34) // FloatOperation
        CASE_CREATE_SKILL_NODE(22104, 35) // Int2Float
        CASE_CREATE_SKILL_NODE(22104, 36) // FloatOperation
        CASE_CREATE_SKILL_NODE(22104, 37) // FloatOperation
        CASE_CREATE_SKILL_NODE(22104, 38) // ForContinue
        CASE_CREATE_SKILL_NODE(22104, 39) // OffsetCalculate
        CASE_CREATE_SKILL_NODE(22104, 40) // Delay
        CASE_CREATE_SKILL_NODE(22104, 41) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(22104, 42) // GetActorAttribute
        CASE_CREATE_SKILL_NODE(22104, 43) // If
        CASE_CREATE_SKILL_NODE(22104, 44) // FloatOperation
        CASE_CREATE_SKILL_NODE(22104, 45) // Float2Int
        CASE_CREATE_SKILL_NODE(22104, 46) // For
        CASE_CREATE_SKILL_NODE(22104, 47) // FloatOperation
        CASE_CREATE_SKILL_NODE(22104, 48) // Int2Float
        CASE_CREATE_SKILL_NODE(22104, 49) // FloatOperation
        CASE_CREATE_SKILL_NODE(22104, 50) // FloatOperation
        CASE_CREATE_SKILL_NODE(22104, 51) // OffsetCalculate
        CASE_CREATE_SKILL_NODE(22104, 52) // AreaCollisionNewPene
        CASE_CREATE_SKILL_NODE(22104, 53) // GetActorAttribute
        CASE_CREATE_SKILL_NODE(22104, 54) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(22104, 55) // Delay
        CASE_CREATE_SKILL_NODE(22104, 56) // ForContinue
        CASE_CREATE_SKILL_NODE(22104, 57) // PlayEffect
        CASE_CREATE_SKILL_NODE(22104, 58) // Delay
        CASE_CREATE_SKILL_NODE(22104, 59) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(22104, 60) // If
        CASE_CREATE_SKILL_NODE(22104, 61) // SkillEndNotify
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_22104

SkillLogic* SkillCreator_22104::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //创建阶段phase
    auto phase = new SkillPhase_22104(1, logic, 2);
    //设置phase执行器
    phase->setRunPhaseNode(1, 3);
    phase->setRunPhaseNode(2, 5);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_22104::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
