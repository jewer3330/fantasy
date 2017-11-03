#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

#include "skill_psnode_attachto.h"
#include "skill_psnode_comparefloat.h"
#include "skill_psnode_delay.h"
#include "skill_psnode_endphase.h"
#include "skill_psnode_for.h"
#include "skill_psnode_forcontinue.h"
#include "skill_psnode_getlinerotation.h"
#include "skill_psnode_getlocation.h"
#include "skill_psnode_getrotation.h"
#include "skill_psnode_if.h"
#include "skill_psnode_offsetcalculate.h"
#include "skill_psnode_playanimation.h"
#include "skill_psnode_playeffect.h"
#include "skill_psnode_playsound.h"
#include "skill_psnode_resetcd.h"
#include "skill_psnode_skillendnotify.h"
#include "skill_psnode_spawncollider.h"
#include "skill_psnode_spawnprojectile.h"
#include "skill_psnode_startphase.h"
#include "skill_psnode_stopeffect.h"
#include "skill_psnode_triggerupdate.h"

namespace pvp {

//变量声明
//--------------------------------------------------------------------------------
// StartPhase
//
REGISTER_REGISTER_SKILL_NODE(21065, 2) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_StartPhase::TRIGGER_START, 106, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(21065, 2) {
    auto node2 = GET_SKILL_NODE(2, PhaseNode_StartPhase);
    if (node2 == nullptr) {
        node2 = new PhaseNode_StartPhase(2, phase);
        CALL_REGISTER_SKILL_NODE(21065, 2, node2)
    }
    if (noInit == true) {
        return node2;
    }
    return node2;
}
//--------------------------------------------------------------------------------
// TriggerUpdate
//
REGISTER_REGISTER_SKILL_NODE(21065, 3) {
}

REGISTER_CREATE_SKILL_NODE(21065, 3) {
    auto node3 = GET_SKILL_NODE(3, PhaseNode_TriggerUpdate);
    if (node3 == nullptr) {
        node3 = new PhaseNode_TriggerUpdate(3, phase);
        CALL_REGISTER_SKILL_NODE(21065, 3, node3)
    }
    if (noInit == true) {
        return node3;
    }
    return node3;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(21065, 4) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_Delay::TRIGGER_DONE, 93, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(21065, 4) {
    auto node4 = GET_SKILL_NODE(4, PhaseNode_Delay);
    if (node4 == nullptr) {
        node4 = new PhaseNode_Delay(4, phase);
        node4->setTime(.50f);
        CALL_REGISTER_SKILL_NODE(21065, 4, node4)
    }
    if (noInit == true) {
        return node4;
    }
    return node4;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(21065, 5) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_PlayAnimation::TRIGGER_DONE, 15, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(21065, 5) {
    auto node5 = GET_SKILL_NODE(5, PhaseNode_PlayAnimation);
    if (node5 == nullptr) {
        node5 = new PhaseNode_PlayAnimation(5, phase);
        node5->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node5->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node5->setTarget(0U);
        node5->setAnimation("Skill3S2");
        node5->setParameter("");
        node5->setValue(false);
        CALL_REGISTER_SKILL_NODE(21065, 5, node5)
    }
    if (noInit == true) {
        return node5;
    }
    return node5;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(21065, 6) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ForContinue>(PhaseNode_Delay::TRIGGER_DONE, 7, PhaseNode_ForContinue::FUNC_DO, &PhaseNode_ForContinue::Do);
}

REGISTER_CREATE_SKILL_NODE(21065, 6) {
    auto node6 = GET_SKILL_NODE(6, PhaseNode_Delay);
    if (node6 == nullptr) {
        node6 = new PhaseNode_Delay(6, phase);
        node6->setTime(.60f);
        CALL_REGISTER_SKILL_NODE(21065, 6, node6)
    }
    if (noInit == true) {
        return node6;
    }
    return node6;
}
//--------------------------------------------------------------------------------
// ForContinue
//
REGISTER_REGISTER_SKILL_NODE(21065, 7) {
}

REGISTER_CREATE_SKILL_NODE(21065, 7) {
    auto node7 = GET_SKILL_NODE(7, PhaseNode_ForContinue);
    if (node7 == nullptr) {
        node7 = new PhaseNode_ForContinue(7, phase);
        CALL_REGISTER_SKILL_NODE(21065, 7, node7)
    }
    if (noInit == true) {
        return node7;
    }
    auto node13 = GET_SKILL_NODE(13, PhaseNode_For);
    if (node13 != nullptr) node7->setFID(node13->getFID());
    return node7;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(21065, 8) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlayAnimation::TRIGGER_DONE, 39, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(21065, 8) {
    auto node8 = GET_SKILL_NODE(8, PhaseNode_PlayAnimation);
    if (node8 == nullptr) {
        node8 = new PhaseNode_PlayAnimation(8, phase);
        node8->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node8->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node8->setTarget(0U);
        node8->setAnimation("Skill3S3");
        node8->setParameter("");
        node8->setValue(false);
        CALL_REGISTER_SKILL_NODE(21065, 8, node8)
    }
    if (noInit == true) {
        return node8;
    }
    return node8;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(21065, 9) {
}

REGISTER_CREATE_SKILL_NODE(21065, 9) {
    auto node9 = GET_SKILL_NODE(9, PhaseNode_EndPhase);
    if (node9 == nullptr) {
        node9 = new PhaseNode_EndPhase(9, phase);
        node9->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node9->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(21065, 9, node9)
    }
    if (noInit == true) {
        return node9;
    }
    return node9;
}
//--------------------------------------------------------------------------------
// SpawnProjectile
//
REGISTER_REGISTER_SKILL_NODE(21065, 12) {
    pnode->resizeTrigger(PhaseNode_SpawnProjectile::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_SpawnProjectile::TRIGGER_DONE, 6, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(21065, 12) {
    auto node12 = GET_SKILL_NODE(12, PhaseNode_SpawnProjectile);
    if (node12 == nullptr) {
        node12 = new PhaseNode_SpawnProjectile(12, phase);
        node12->setDataId(52107);
        node12->setEndPosX(26.17f);
        node12->setEndPosY(10.11f);
        node12->setEndPosZ(.00f);
        node12->setMaxCount(0);
        CALL_REGISTER_SKILL_NODE(21065, 12, node12)
    }
    if (noInit == true) {
        return node12;
    }
    auto node95 = GET_SKILL_NODE(95, PhaseNode_OffsetCalculate);
    if (node95 != nullptr) node12->setPosX(node95->getOutPosX());
    if (node95 != nullptr) node12->setPosY(node95->getOutPosY());
    if (node95 != nullptr) node12->setPosZ(node95->getOutPosZ());
    if (node95 != nullptr) node12->setRotation(node95->getOutRotation());
    return node12;
}
//--------------------------------------------------------------------------------
// For
//
REGISTER_REGISTER_SKILL_NODE(21065, 13) {
    pnode->resizeTrigger(PhaseNode_For::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_For::TRIGGER_DO, 16, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_For::TRIGGER_DONE, 8, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(21065, 13) {
    auto node13 = GET_SKILL_NODE(13, PhaseNode_For);
    if (node13 == nullptr) {
        node13 = new PhaseNode_For(13, phase);
        node13->setBegin(0);
        node13->setIncrease(1);
        node13->setEnd(3);
        CALL_REGISTER_SKILL_NODE(21065, 13, node13)
    }
    if (noInit == true) {
        return node13;
    }
    return node13;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(21065, 14) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnProjectile>(PhaseNode_Delay::TRIGGER_DONE, 12, PhaseNode_SpawnProjectile::FUNC_DO, &PhaseNode_SpawnProjectile::Do);
}

REGISTER_CREATE_SKILL_NODE(21065, 14) {
    auto node14 = GET_SKILL_NODE(14, PhaseNode_Delay);
    if (node14 == nullptr) {
        node14 = new PhaseNode_Delay(14, phase);
        node14->setTime(.20f);
        CALL_REGISTER_SKILL_NODE(21065, 14, node14)
    }
    if (noInit == true) {
        return node14;
    }
    return node14;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(21065, 15) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_PlaySound::TRIGGER_DONE, 97, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(21065, 15) {
    auto node15 = GET_SKILL_NODE(15, PhaseNode_PlaySound);
    if (node15 == nullptr) {
        node15 = new PhaseNode_PlaySound(15, phase);
        node15->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node15->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node15->setSoundID("SE_Boss2106_ATK2");
        node15->setTarget(0U);
        node15->setUsePos(false);
        node15->setPosX(.00f);
        node15->setPosY(.00f);
        node15->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(21065, 15, node15)
    }
    if (noInit == true) {
        return node15;
    }
    return node15;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(21065, 16) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_PlayAnimation::TRIGGER_DONE, 5, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(21065, 16) {
    auto node16 = GET_SKILL_NODE(16, PhaseNode_PlayAnimation);
    if (node16 == nullptr) {
        node16 = new PhaseNode_PlayAnimation(16, phase);
        node16->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node16->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node16->setTarget(0U);
        node16->setAnimation("Idle");
        node16->setParameter("");
        node16->setValue(false);
        CALL_REGISTER_SKILL_NODE(21065, 16, node16)
    }
    if (noInit == true) {
        return node16;
    }
    return node16;
}
//--------------------------------------------------------------------------------
// SpawnCollider
//
REGISTER_REGISTER_SKILL_NODE(21065, 25) {
    pnode->resizeTrigger(PhaseNode_SpawnCollider::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AttachTo>(PhaseNode_SpawnCollider::TRIGGER_DONE, 28, PhaseNode_AttachTo::FUNC_DO, &PhaseNode_AttachTo::Do);
}

REGISTER_CREATE_SKILL_NODE(21065, 25) {
    auto node25 = GET_SKILL_NODE(25, PhaseNode_SpawnCollider);
    if (node25 == nullptr) {
        node25 = new PhaseNode_SpawnCollider(25, phase);
        node25->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node25->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node25->setMesh("");
        node25->setMeshScale(.00f);
        node25->setEffectID(0);
        node25->setEffectScale(.00f);
        node25->setType(PhaseNode_SpawnCollider::SpawnCollider_Type::Circle);
        node25->setTypeParams(0, 1.00f);
        node25->setTime(.50f);
        node25->setPosZ(.00f);
        node25->setreentry(false);
        node25->setCheckPeneSound(false);
        CALL_REGISTER_SKILL_NODE(21065, 25, node25)
    }
    if (noInit == true) {
        return node25;
    }
    auto node108 = GET_SKILL_NODE(108, PhaseNode_OffsetCalculate);
    auto node37 = GET_SKILL_NODE(37, PhaseNode_GetLineRotation);
    if (node108 != nullptr) node25->setPosX(node108->getOutPosX());
    if (node108 != nullptr) node25->setPosY(node108->getOutPosY());
    if (node37 != nullptr) node25->setRotation(node37->getRotation());
    return node25;
}
//--------------------------------------------------------------------------------
// AttachTo
//
REGISTER_REGISTER_SKILL_NODE(21065, 28) {
    pnode->resizeTrigger(PhaseNode_AttachTo::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_AttachTo::TRIGGER_DONE, 89, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(21065, 28) {
    auto node28 = GET_SKILL_NODE(28, PhaseNode_AttachTo);
    if (node28 == nullptr) {
        node28 = new PhaseNode_AttachTo(28, phase);
        node28->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node28->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node28->setChild(0U);
        node28->setChangeRotation(true);
        node28->setreentry(false);
        CALL_REGISTER_SKILL_NODE(21065, 28, node28)
    }
    if (noInit == true) {
        return node28;
    }
    auto node25 = GET_SKILL_NODE(25, PhaseNode_SpawnCollider);
    if (node25 != nullptr) node28->setParent(node25->getColliderID());
    return node28;
}
//--------------------------------------------------------------------------------
// GetLineRotation
//
REGISTER_REGISTER_SKILL_NODE(21065, 37) {
    pnode->resizeTrigger(PhaseNode_GetLineRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnCollider>(PhaseNode_GetLineRotation::TRIGGER_DONE, 25, PhaseNode_SpawnCollider::FUNC_DO, &PhaseNode_SpawnCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(21065, 37) {
    auto node37 = GET_SKILL_NODE(37, PhaseNode_GetLineRotation);
    if (node37 == nullptr) {
        node37 = new PhaseNode_GetLineRotation(37, phase);
        node37->setEndX(26.17f);
        node37->setEndY(10.11f);
        CALL_REGISTER_SKILL_NODE(21065, 37, node37)
    }
    if (noInit == true) {
        return node37;
    }
    auto node108 = GET_SKILL_NODE(108, PhaseNode_OffsetCalculate);
    if (node108 != nullptr) node37->setStartX(node108->getOutPosX());
    if (node108 != nullptr) node37->setStartY(node108->getOutPosY());
    return node37;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(21065, 39) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_Delay::TRIGGER_DONE, 122, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(21065, 39) {
    auto node39 = GET_SKILL_NODE(39, PhaseNode_Delay);
    if (node39 == nullptr) {
        node39 = new PhaseNode_Delay(39, phase);
        node39->setTime(1.00f);
        CALL_REGISTER_SKILL_NODE(21065, 39, node39)
    }
    if (noInit == true) {
        return node39;
    }
    return node39;
}
//--------------------------------------------------------------------------------
// GetLineRotation
//
REGISTER_REGISTER_SKILL_NODE(21065, 63) {
    pnode->resizeTrigger(PhaseNode_GetLineRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnCollider>(PhaseNode_GetLineRotation::TRIGGER_DONE, 84, PhaseNode_SpawnCollider::FUNC_DO, &PhaseNode_SpawnCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(21065, 63) {
    auto node63 = GET_SKILL_NODE(63, PhaseNode_GetLineRotation);
    if (node63 == nullptr) {
        node63 = new PhaseNode_GetLineRotation(63, phase);
        node63->setEndX(9.60f);
        node63->setEndY(26.83f);
        CALL_REGISTER_SKILL_NODE(21065, 63, node63)
    }
    if (noInit == true) {
        return node63;
    }
    auto node124 = GET_SKILL_NODE(124, PhaseNode_OffsetCalculate);
    if (node124 != nullptr) node63->setStartX(node124->getOutPosX());
    if (node124 != nullptr) node63->setStartY(node124->getOutPosY());
    return node63;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(21065, 66) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_Delay::TRIGGER_DONE, 113, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(21065, 66) {
    auto node66 = GET_SKILL_NODE(66, PhaseNode_Delay);
    if (node66 == nullptr) {
        node66 = new PhaseNode_Delay(66, phase);
        node66->setTime(.50f);
        CALL_REGISTER_SKILL_NODE(21065, 66, node66)
    }
    if (noInit == true) {
        return node66;
    }
    return node66;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(21065, 67) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_PlayAnimation::TRIGGER_DONE, 74, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(21065, 67) {
    auto node67 = GET_SKILL_NODE(67, PhaseNode_PlayAnimation);
    if (node67 == nullptr) {
        node67 = new PhaseNode_PlayAnimation(67, phase);
        node67->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node67->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node67->setTarget(0U);
        node67->setAnimation("Skill3S2");
        node67->setParameter("");
        node67->setValue(false);
        CALL_REGISTER_SKILL_NODE(21065, 67, node67)
    }
    if (noInit == true) {
        return node67;
    }
    return node67;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(21065, 68) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ForContinue>(PhaseNode_Delay::TRIGGER_DONE, 69, PhaseNode_ForContinue::FUNC_DO, &PhaseNode_ForContinue::Do);
}

REGISTER_CREATE_SKILL_NODE(21065, 68) {
    auto node68 = GET_SKILL_NODE(68, PhaseNode_Delay);
    if (node68 == nullptr) {
        node68 = new PhaseNode_Delay(68, phase);
        node68->setTime(.60f);
        CALL_REGISTER_SKILL_NODE(21065, 68, node68)
    }
    if (noInit == true) {
        return node68;
    }
    return node68;
}
//--------------------------------------------------------------------------------
// ForContinue
//
REGISTER_REGISTER_SKILL_NODE(21065, 69) {
}

REGISTER_CREATE_SKILL_NODE(21065, 69) {
    auto node69 = GET_SKILL_NODE(69, PhaseNode_ForContinue);
    if (node69 == nullptr) {
        node69 = new PhaseNode_ForContinue(69, phase);
        CALL_REGISTER_SKILL_NODE(21065, 69, node69)
    }
    if (noInit == true) {
        return node69;
    }
    auto node72 = GET_SKILL_NODE(72, PhaseNode_For);
    if (node72 != nullptr) node69->setFID(node72->getFID());
    return node69;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(21065, 70) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlayAnimation::TRIGGER_DONE, 102, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(21065, 70) {
    auto node70 = GET_SKILL_NODE(70, PhaseNode_PlayAnimation);
    if (node70 == nullptr) {
        node70 = new PhaseNode_PlayAnimation(70, phase);
        node70->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node70->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node70->setTarget(0U);
        node70->setAnimation("Skill3S3");
        node70->setParameter("");
        node70->setValue(false);
        CALL_REGISTER_SKILL_NODE(21065, 70, node70)
    }
    if (noInit == true) {
        return node70;
    }
    return node70;
}
//--------------------------------------------------------------------------------
// SpawnProjectile
//
REGISTER_REGISTER_SKILL_NODE(21065, 71) {
    pnode->resizeTrigger(PhaseNode_SpawnProjectile::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_SpawnProjectile::TRIGGER_DONE, 68, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(21065, 71) {
    auto node71 = GET_SKILL_NODE(71, PhaseNode_SpawnProjectile);
    if (node71 == nullptr) {
        node71 = new PhaseNode_SpawnProjectile(71, phase);
        node71->setDataId(52107);
        node71->setEndPosX(9.60f);
        node71->setEndPosY(26.83f);
        node71->setEndPosZ(.00f);
        node71->setMaxCount(0);
        CALL_REGISTER_SKILL_NODE(21065, 71, node71)
    }
    if (noInit == true) {
        return node71;
    }
    auto node115 = GET_SKILL_NODE(115, PhaseNode_OffsetCalculate);
    if (node115 != nullptr) node71->setPosX(node115->getOutPosX());
    if (node115 != nullptr) node71->setPosY(node115->getOutPosY());
    if (node115 != nullptr) node71->setPosZ(node115->getOutPosZ());
    if (node115 != nullptr) node71->setRotation(node115->getOutRotation());
    return node71;
}
//--------------------------------------------------------------------------------
// For
//
REGISTER_REGISTER_SKILL_NODE(21065, 72) {
    pnode->resizeTrigger(PhaseNode_For::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_For::TRIGGER_DO, 75, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_For::TRIGGER_DONE, 70, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(21065, 72) {
    auto node72 = GET_SKILL_NODE(72, PhaseNode_For);
    if (node72 == nullptr) {
        node72 = new PhaseNode_For(72, phase);
        node72->setBegin(0);
        node72->setIncrease(1);
        node72->setEnd(3);
        CALL_REGISTER_SKILL_NODE(21065, 72, node72)
    }
    if (noInit == true) {
        return node72;
    }
    return node72;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(21065, 73) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnProjectile>(PhaseNode_Delay::TRIGGER_DONE, 71, PhaseNode_SpawnProjectile::FUNC_DO, &PhaseNode_SpawnProjectile::Do);
}

REGISTER_CREATE_SKILL_NODE(21065, 73) {
    auto node73 = GET_SKILL_NODE(73, PhaseNode_Delay);
    if (node73 == nullptr) {
        node73 = new PhaseNode_Delay(73, phase);
        node73->setTime(.20f);
        CALL_REGISTER_SKILL_NODE(21065, 73, node73)
    }
    if (noInit == true) {
        return node73;
    }
    return node73;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(21065, 74) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_PlaySound::TRIGGER_DONE, 117, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(21065, 74) {
    auto node74 = GET_SKILL_NODE(74, PhaseNode_PlaySound);
    if (node74 == nullptr) {
        node74 = new PhaseNode_PlaySound(74, phase);
        node74->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node74->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node74->setSoundID("SE_Boss2106_ATK2");
        node74->setTarget(0U);
        node74->setUsePos(false);
        node74->setPosX(.00f);
        node74->setPosY(.00f);
        node74->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(21065, 74, node74)
    }
    if (noInit == true) {
        return node74;
    }
    return node74;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(21065, 75) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_PlayAnimation::TRIGGER_DONE, 67, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(21065, 75) {
    auto node75 = GET_SKILL_NODE(75, PhaseNode_PlayAnimation);
    if (node75 == nullptr) {
        node75 = new PhaseNode_PlayAnimation(75, phase);
        node75->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node75->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node75->setTarget(0U);
        node75->setAnimation("Idle");
        node75->setParameter("");
        node75->setValue(false);
        CALL_REGISTER_SKILL_NODE(21065, 75, node75)
    }
    if (noInit == true) {
        return node75;
    }
    return node75;
}
//--------------------------------------------------------------------------------
// SpawnCollider
//
REGISTER_REGISTER_SKILL_NODE(21065, 84) {
    pnode->resizeTrigger(PhaseNode_SpawnCollider::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AttachTo>(PhaseNode_SpawnCollider::TRIGGER_DONE, 88, PhaseNode_AttachTo::FUNC_DO, &PhaseNode_AttachTo::Do);
}

REGISTER_CREATE_SKILL_NODE(21065, 84) {
    auto node84 = GET_SKILL_NODE(84, PhaseNode_SpawnCollider);
    if (node84 == nullptr) {
        node84 = new PhaseNode_SpawnCollider(84, phase);
        node84->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node84->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node84->setMesh("");
        node84->setMeshScale(.00f);
        node84->setEffectID(0);
        node84->setEffectScale(.00f);
        node84->setType(PhaseNode_SpawnCollider::SpawnCollider_Type::Circle);
        node84->setTypeParams(0, 1.00f);
        node84->setTime(.50f);
        node84->setPosZ(.00f);
        node84->setreentry(false);
        node84->setCheckPeneSound(false);
        CALL_REGISTER_SKILL_NODE(21065, 84, node84)
    }
    if (noInit == true) {
        return node84;
    }
    auto node124 = GET_SKILL_NODE(124, PhaseNode_OffsetCalculate);
    auto node63 = GET_SKILL_NODE(63, PhaseNode_GetLineRotation);
    if (node124 != nullptr) node84->setPosX(node124->getOutPosX());
    if (node124 != nullptr) node84->setPosY(node124->getOutPosY());
    if (node63 != nullptr) node84->setRotation(node63->getRotation());
    return node84;
}
//--------------------------------------------------------------------------------
// AttachTo
//
REGISTER_REGISTER_SKILL_NODE(21065, 88) {
    pnode->resizeTrigger(PhaseNode_AttachTo::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_AttachTo::TRIGGER_DONE, 109, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(21065, 88) {
    auto node88 = GET_SKILL_NODE(88, PhaseNode_AttachTo);
    if (node88 == nullptr) {
        node88 = new PhaseNode_AttachTo(88, phase);
        node88->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node88->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node88->setChild(0U);
        node88->setChangeRotation(true);
        node88->setreentry(false);
        CALL_REGISTER_SKILL_NODE(21065, 88, node88)
    }
    if (noInit == true) {
        return node88;
    }
    auto node84 = GET_SKILL_NODE(84, PhaseNode_SpawnCollider);
    if (node84 != nullptr) node88->setParent(node84->getColliderID());
    return node88;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(21065, 89) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_ResetCD::TRIGGER_DONE, 90, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(21065, 89) {
    auto node89 = GET_SKILL_NODE(89, PhaseNode_ResetCD);
    if (node89 == nullptr) {
        node89 = new PhaseNode_ResetCD(89, phase);
        node89->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node89->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node89->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(21065, 89, node89)
    }
    if (noInit == true) {
        return node89;
    }
    return node89;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(21065, 90) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_PlayAnimation::TRIGGER_DONE, 91, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(21065, 90) {
    auto node90 = GET_SKILL_NODE(90, PhaseNode_PlayAnimation);
    if (node90 == nullptr) {
        node90 = new PhaseNode_PlayAnimation(90, phase);
        node90->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node90->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node90->setTarget(0U);
        node90->setAnimation("Skill3S1");
        node90->setParameter("");
        node90->setValue(false);
        CALL_REGISTER_SKILL_NODE(21065, 90, node90)
    }
    if (noInit == true) {
        return node90;
    }
    return node90;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(21065, 91) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlaySound::TRIGGER_DONE, 92, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(21065, 91) {
    auto node91 = GET_SKILL_NODE(91, PhaseNode_PlaySound);
    if (node91 == nullptr) {
        node91 = new PhaseNode_PlaySound(91, phase);
        node91->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node91->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node91->setSoundID("");
        node91->setTarget(0U);
        node91->setUsePos(false);
        node91->setPosX(.00f);
        node91->setPosY(.00f);
        node91->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(21065, 91, node91)
    }
    if (noInit == true) {
        return node91;
    }
    return node91;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(21065, 92) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_Delay::TRIGGER_DONE, 4, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(21065, 92) {
    auto node92 = GET_SKILL_NODE(92, PhaseNode_Delay);
    if (node92 == nullptr) {
        node92 = new PhaseNode_Delay(92, phase);
        node92->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(21065, 92, node92)
    }
    if (noInit == true) {
        return node92;
    }
    return node92;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(21065, 93) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetRotation>(PhaseNode_GetLocation::TRIGGER_DONE, 94, PhaseNode_GetRotation::FUNC_DO, &PhaseNode_GetRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(21065, 93) {
    auto node93 = GET_SKILL_NODE(93, PhaseNode_GetLocation);
    if (node93 == nullptr) {
        node93 = new PhaseNode_GetLocation(93, phase);
        node93->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node93->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(21065, 93, node93)
    }
    if (noInit == true) {
        return node93;
    }
    return node93;
}
//--------------------------------------------------------------------------------
// GetRotation
//
REGISTER_REGISTER_SKILL_NODE(21065, 94) {
    pnode->resizeTrigger(PhaseNode_GetRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_OffsetCalculate>(PhaseNode_GetRotation::TRIGGER_DONE, 95, PhaseNode_OffsetCalculate::FUNC_DO, &PhaseNode_OffsetCalculate::Do);
}

REGISTER_CREATE_SKILL_NODE(21065, 94) {
    auto node94 = GET_SKILL_NODE(94, PhaseNode_GetRotation);
    if (node94 == nullptr) {
        node94 = new PhaseNode_GetRotation(94, phase);
        node94->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node94->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(21065, 94, node94)
    }
    if (noInit == true) {
        return node94;
    }
    return node94;
}
//--------------------------------------------------------------------------------
// OffsetCalculate
//
REGISTER_REGISTER_SKILL_NODE(21065, 95) {
    pnode->resizeTrigger(PhaseNode_OffsetCalculate::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_For>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 13, PhaseNode_For::FUNC_START, &PhaseNode_For::Start);
}

REGISTER_CREATE_SKILL_NODE(21065, 95) {
    auto node95 = GET_SKILL_NODE(95, PhaseNode_OffsetCalculate);
    if (node95 == nullptr) {
        node95 = new PhaseNode_OffsetCalculate(95, phase);
        node95->setPosZ(.00f);
        node95->setOffsetX(.90f);
        node95->setOffsetY(-.50f);
        node95->setOffsetZ(3.20f);
        node95->setRotOffset(.00f);
        CALL_REGISTER_SKILL_NODE(21065, 95, node95)
    }
    if (noInit == true) {
        return node95;
    }
    auto node93 = GET_SKILL_NODE(93, PhaseNode_GetLocation);
    auto node94 = GET_SKILL_NODE(94, PhaseNode_GetRotation);
    if (node93 != nullptr) node95->setPosX(node93->getX());
    if (node93 != nullptr) node95->setPosY(node93->getY());
    if (node94 != nullptr) node95->setRotation(node94->getAngle());
    return node95;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(21065, 96) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_PlayEffect::TRIGGER_DONE, 99, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(21065, 96) {
    auto node96 = GET_SKILL_NODE(96, PhaseNode_PlayEffect);
    if (node96 == nullptr) {
        node96 = new PhaseNode_PlayEffect(96, phase);
        node96->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node96->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node96->setEffectID(210631);
        node96->setChangeColor(false);
        node96->setType(PhaseNode_PlayEffect::PlayEffect_Type::WithTarget);
        node96->getVars().reserve(5);
        node96->getVars().setVariable<uint64_t>(0, 0U);
        node96->getVars().setVariable<std::string>(1, "");
        node96->getVars().setVariable<float>(2, .00f);
        node96->getVars().setVariable<float>(3, .00f);
        node96->getVars().setVariable<float>(4, .00f);
        node96->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(21065, 96, node96)
    }
    if (noInit == true) {
        return node96;
    }
    auto node95 = GET_SKILL_NODE(95, PhaseNode_OffsetCalculate);
    if (node95 != nullptr) node96->getVars().setVariable<float>(2, node95->getOutPosX());
    if (node95 != nullptr) node96->getVars().setVariable<float>(3, node95->getOutPosY());
    if (node95 != nullptr) node96->setRotation(node95->getOutRotation());
    return node96;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(21065, 97) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_FALSE, 98, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_TRUE, 96, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(21065, 97) {
    auto node97 = GET_SKILL_NODE(97, PhaseNode_If);
    if (node97 == nullptr) {
        node97 = new PhaseNode_If(97, phase);
        node97->setCondition(false);
        CALL_REGISTER_SKILL_NODE(21065, 97, node97)
    }
    if (noInit == true) {
        return node97;
    }
    return node97;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(21065, 98) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_PlayEffect::TRIGGER_DONE, 99, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(21065, 98) {
    auto node98 = GET_SKILL_NODE(98, PhaseNode_PlayEffect);
    if (node98 == nullptr) {
        node98 = new PhaseNode_PlayEffect(98, phase);
        node98->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node98->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node98->setEffectID(210631);
        node98->setChangeColor(false);
        node98->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node98->getVars().reserve(3);
        node98->getVars().setVariable<float>(0, .00f);
        node98->getVars().setVariable<float>(1, .00f);
        node98->getVars().setVariable<float>(2, .00f);
        node98->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(21065, 98, node98)
    }
    if (noInit == true) {
        return node98;
    }
    auto node95 = GET_SKILL_NODE(95, PhaseNode_OffsetCalculate);
    if (node95 != nullptr) node98->getVars().setVariable<float>(0, node95->getOutPosX());
    if (node95 != nullptr) node98->getVars().setVariable<float>(1, node95->getOutPosY());
    if (node95 != nullptr) node98->setRotation(node95->getOutRotation());
    return node98;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(21065, 99) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 14, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_LESS, 100, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_LESS, 14, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(21065, 99) {
    auto node99 = GET_SKILL_NODE(99, PhaseNode_CompareFloat);
    if (node99 == nullptr) {
        node99 = new PhaseNode_CompareFloat(99, phase);
        node99->setA(.00f);
        node99->setB(.00f);
        CALL_REGISTER_SKILL_NODE(21065, 99, node99)
    }
    if (noInit == true) {
        return node99;
    }
    return node99;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(21065, 100) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StopEffect>(PhaseNode_Delay::TRIGGER_DONE, 101, PhaseNode_StopEffect::FUNC_DO, &PhaseNode_StopEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(21065, 100) {
    auto node100 = GET_SKILL_NODE(100, PhaseNode_Delay);
    if (node100 == nullptr) {
        node100 = new PhaseNode_Delay(100, phase);
        node100->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(21065, 100, node100)
    }
    if (noInit == true) {
        return node100;
    }
    return node100;
}
//--------------------------------------------------------------------------------
// StopEffect
//
REGISTER_REGISTER_SKILL_NODE(21065, 101) {
}

REGISTER_CREATE_SKILL_NODE(21065, 101) {
    auto node101 = GET_SKILL_NODE(101, PhaseNode_StopEffect);
    if (node101 == nullptr) {
        node101 = new PhaseNode_StopEffect(101, phase);
        node101->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node101->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node101->setEffectID(210631);
        CALL_REGISTER_SKILL_NODE(21065, 101, node101)
    }
    if (noInit == true) {
        return node101;
    }
    return node101;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(21065, 102) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_Delay::TRIGGER_DONE, 104, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(21065, 102) {
    auto node102 = GET_SKILL_NODE(102, PhaseNode_Delay);
    if (node102 == nullptr) {
        node102 = new PhaseNode_Delay(102, phase);
        node102->setTime(.50f);
        CALL_REGISTER_SKILL_NODE(21065, 102, node102)
    }
    if (noInit == true) {
        return node102;
    }
    return node102;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(21065, 103) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 9, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(21065, 103) {
    auto node103 = GET_SKILL_NODE(103, PhaseNode_SkillEndNotify);
    if (node103 == nullptr) {
        node103 = new PhaseNode_SkillEndNotify(103, phase);
        node103->setReturnType(false);
        CALL_REGISTER_SKILL_NODE(21065, 103, node103)
    }
    if (noInit == true) {
        return node103;
    }
    return node103;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(21065, 104) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_FALSE, 105, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_TRUE, 103, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
}

REGISTER_CREATE_SKILL_NODE(21065, 104) {
    auto node104 = GET_SKILL_NODE(104, PhaseNode_If);
    if (node104 == nullptr) {
        node104 = new PhaseNode_If(104, phase);
        node104->setCondition(false);
        CALL_REGISTER_SKILL_NODE(21065, 104, node104)
    }
    if (noInit == true) {
        return node104;
    }
    return node104;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(21065, 105) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 9, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(21065, 105) {
    auto node105 = GET_SKILL_NODE(105, PhaseNode_SkillEndNotify);
    if (node105 == nullptr) {
        node105 = new PhaseNode_SkillEndNotify(105, phase);
        node105->setReturnType(true);
        CALL_REGISTER_SKILL_NODE(21065, 105, node105)
    }
    if (noInit == true) {
        return node105;
    }
    return node105;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(21065, 106) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetRotation>(PhaseNode_GetLocation::TRIGGER_DONE, 107, PhaseNode_GetRotation::FUNC_DO, &PhaseNode_GetRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(21065, 106) {
    auto node106 = GET_SKILL_NODE(106, PhaseNode_GetLocation);
    if (node106 == nullptr) {
        node106 = new PhaseNode_GetLocation(106, phase);
        node106->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node106->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(21065, 106, node106)
    }
    if (noInit == true) {
        return node106;
    }
    return node106;
}
//--------------------------------------------------------------------------------
// GetRotation
//
REGISTER_REGISTER_SKILL_NODE(21065, 107) {
    pnode->resizeTrigger(PhaseNode_GetRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_OffsetCalculate>(PhaseNode_GetRotation::TRIGGER_DONE, 108, PhaseNode_OffsetCalculate::FUNC_DO, &PhaseNode_OffsetCalculate::Do);
}

REGISTER_CREATE_SKILL_NODE(21065, 107) {
    auto node107 = GET_SKILL_NODE(107, PhaseNode_GetRotation);
    if (node107 == nullptr) {
        node107 = new PhaseNode_GetRotation(107, phase);
        node107->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node107->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(21065, 107, node107)
    }
    if (noInit == true) {
        return node107;
    }
    return node107;
}
//--------------------------------------------------------------------------------
// OffsetCalculate
//
REGISTER_REGISTER_SKILL_NODE(21065, 108) {
    pnode->resizeTrigger(PhaseNode_OffsetCalculate::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLineRotation>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 37, PhaseNode_GetLineRotation::FUNC_DO, &PhaseNode_GetLineRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(21065, 108) {
    auto node108 = GET_SKILL_NODE(108, PhaseNode_OffsetCalculate);
    if (node108 == nullptr) {
        node108 = new PhaseNode_OffsetCalculate(108, phase);
        node108->setPosZ(.00f);
        node108->setOffsetX(.00f);
        node108->setOffsetY(.00f);
        node108->setOffsetZ(.00f);
        node108->setRotOffset(.00f);
        CALL_REGISTER_SKILL_NODE(21065, 108, node108)
    }
    if (noInit == true) {
        return node108;
    }
    auto node106 = GET_SKILL_NODE(106, PhaseNode_GetLocation);
    auto node107 = GET_SKILL_NODE(107, PhaseNode_GetRotation);
    if (node106 != nullptr) node108->setPosX(node106->getX());
    if (node106 != nullptr) node108->setPosY(node106->getY());
    if (node107 != nullptr) node108->setRotation(node107->getAngle());
    return node108;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(21065, 109) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_ResetCD::TRIGGER_DONE, 110, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(21065, 109) {
    auto node109 = GET_SKILL_NODE(109, PhaseNode_ResetCD);
    if (node109 == nullptr) {
        node109 = new PhaseNode_ResetCD(109, phase);
        node109->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node109->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node109->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(21065, 109, node109)
    }
    if (noInit == true) {
        return node109;
    }
    return node109;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(21065, 110) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_PlayAnimation::TRIGGER_DONE, 111, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(21065, 110) {
    auto node110 = GET_SKILL_NODE(110, PhaseNode_PlayAnimation);
    if (node110 == nullptr) {
        node110 = new PhaseNode_PlayAnimation(110, phase);
        node110->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node110->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node110->setTarget(0U);
        node110->setAnimation("Skill3S1");
        node110->setParameter("");
        node110->setValue(false);
        CALL_REGISTER_SKILL_NODE(21065, 110, node110)
    }
    if (noInit == true) {
        return node110;
    }
    return node110;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(21065, 111) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlaySound::TRIGGER_DONE, 112, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(21065, 111) {
    auto node111 = GET_SKILL_NODE(111, PhaseNode_PlaySound);
    if (node111 == nullptr) {
        node111 = new PhaseNode_PlaySound(111, phase);
        node111->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node111->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node111->setSoundID("");
        node111->setTarget(0U);
        node111->setUsePos(false);
        node111->setPosX(.00f);
        node111->setPosY(.00f);
        node111->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(21065, 111, node111)
    }
    if (noInit == true) {
        return node111;
    }
    return node111;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(21065, 112) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_Delay::TRIGGER_DONE, 66, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(21065, 112) {
    auto node112 = GET_SKILL_NODE(112, PhaseNode_Delay);
    if (node112 == nullptr) {
        node112 = new PhaseNode_Delay(112, phase);
        node112->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(21065, 112, node112)
    }
    if (noInit == true) {
        return node112;
    }
    return node112;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(21065, 113) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetRotation>(PhaseNode_GetLocation::TRIGGER_DONE, 114, PhaseNode_GetRotation::FUNC_DO, &PhaseNode_GetRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(21065, 113) {
    auto node113 = GET_SKILL_NODE(113, PhaseNode_GetLocation);
    if (node113 == nullptr) {
        node113 = new PhaseNode_GetLocation(113, phase);
        node113->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node113->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(21065, 113, node113)
    }
    if (noInit == true) {
        return node113;
    }
    return node113;
}
//--------------------------------------------------------------------------------
// GetRotation
//
REGISTER_REGISTER_SKILL_NODE(21065, 114) {
    pnode->resizeTrigger(PhaseNode_GetRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_OffsetCalculate>(PhaseNode_GetRotation::TRIGGER_DONE, 115, PhaseNode_OffsetCalculate::FUNC_DO, &PhaseNode_OffsetCalculate::Do);
}

REGISTER_CREATE_SKILL_NODE(21065, 114) {
    auto node114 = GET_SKILL_NODE(114, PhaseNode_GetRotation);
    if (node114 == nullptr) {
        node114 = new PhaseNode_GetRotation(114, phase);
        node114->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node114->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(21065, 114, node114)
    }
    if (noInit == true) {
        return node114;
    }
    return node114;
}
//--------------------------------------------------------------------------------
// OffsetCalculate
//
REGISTER_REGISTER_SKILL_NODE(21065, 115) {
    pnode->resizeTrigger(PhaseNode_OffsetCalculate::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_For>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 72, PhaseNode_For::FUNC_START, &PhaseNode_For::Start);
}

REGISTER_CREATE_SKILL_NODE(21065, 115) {
    auto node115 = GET_SKILL_NODE(115, PhaseNode_OffsetCalculate);
    if (node115 == nullptr) {
        node115 = new PhaseNode_OffsetCalculate(115, phase);
        node115->setPosZ(.00f);
        node115->setOffsetX(.90f);
        node115->setOffsetY(-.50f);
        node115->setOffsetZ(3.20f);
        node115->setRotOffset(.00f);
        CALL_REGISTER_SKILL_NODE(21065, 115, node115)
    }
    if (noInit == true) {
        return node115;
    }
    auto node113 = GET_SKILL_NODE(113, PhaseNode_GetLocation);
    auto node114 = GET_SKILL_NODE(114, PhaseNode_GetRotation);
    if (node113 != nullptr) node115->setPosX(node113->getX());
    if (node113 != nullptr) node115->setPosY(node113->getY());
    if (node114 != nullptr) node115->setRotation(node114->getAngle());
    return node115;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(21065, 116) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_PlayEffect::TRIGGER_DONE, 119, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(21065, 116) {
    auto node116 = GET_SKILL_NODE(116, PhaseNode_PlayEffect);
    if (node116 == nullptr) {
        node116 = new PhaseNode_PlayEffect(116, phase);
        node116->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node116->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node116->setEffectID(210631);
        node116->setChangeColor(false);
        node116->setType(PhaseNode_PlayEffect::PlayEffect_Type::WithTarget);
        node116->getVars().reserve(5);
        node116->getVars().setVariable<uint64_t>(0, 0U);
        node116->getVars().setVariable<std::string>(1, "");
        node116->getVars().setVariable<float>(2, .00f);
        node116->getVars().setVariable<float>(3, .00f);
        node116->getVars().setVariable<float>(4, .00f);
        node116->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(21065, 116, node116)
    }
    if (noInit == true) {
        return node116;
    }
    auto node115 = GET_SKILL_NODE(115, PhaseNode_OffsetCalculate);
    if (node115 != nullptr) node116->getVars().setVariable<float>(2, node115->getOutPosX());
    if (node115 != nullptr) node116->getVars().setVariable<float>(3, node115->getOutPosY());
    if (node115 != nullptr) node116->setRotation(node115->getOutRotation());
    return node116;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(21065, 117) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_FALSE, 118, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_TRUE, 116, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(21065, 117) {
    auto node117 = GET_SKILL_NODE(117, PhaseNode_If);
    if (node117 == nullptr) {
        node117 = new PhaseNode_If(117, phase);
        node117->setCondition(false);
        CALL_REGISTER_SKILL_NODE(21065, 117, node117)
    }
    if (noInit == true) {
        return node117;
    }
    return node117;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(21065, 118) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_PlayEffect::TRIGGER_DONE, 119, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(21065, 118) {
    auto node118 = GET_SKILL_NODE(118, PhaseNode_PlayEffect);
    if (node118 == nullptr) {
        node118 = new PhaseNode_PlayEffect(118, phase);
        node118->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node118->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node118->setEffectID(210631);
        node118->setChangeColor(false);
        node118->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node118->getVars().reserve(3);
        node118->getVars().setVariable<float>(0, .00f);
        node118->getVars().setVariable<float>(1, .00f);
        node118->getVars().setVariable<float>(2, .00f);
        node118->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(21065, 118, node118)
    }
    if (noInit == true) {
        return node118;
    }
    auto node115 = GET_SKILL_NODE(115, PhaseNode_OffsetCalculate);
    if (node115 != nullptr) node118->getVars().setVariable<float>(0, node115->getOutPosX());
    if (node115 != nullptr) node118->getVars().setVariable<float>(1, node115->getOutPosY());
    if (node115 != nullptr) node118->setRotation(node115->getOutRotation());
    return node118;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(21065, 119) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 73, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_LESS, 120, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_LESS, 73, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(21065, 119) {
    auto node119 = GET_SKILL_NODE(119, PhaseNode_CompareFloat);
    if (node119 == nullptr) {
        node119 = new PhaseNode_CompareFloat(119, phase);
        node119->setA(.00f);
        node119->setB(.00f);
        CALL_REGISTER_SKILL_NODE(21065, 119, node119)
    }
    if (noInit == true) {
        return node119;
    }
    return node119;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(21065, 120) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StopEffect>(PhaseNode_Delay::TRIGGER_DONE, 121, PhaseNode_StopEffect::FUNC_DO, &PhaseNode_StopEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(21065, 120) {
    auto node120 = GET_SKILL_NODE(120, PhaseNode_Delay);
    if (node120 == nullptr) {
        node120 = new PhaseNode_Delay(120, phase);
        node120->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(21065, 120, node120)
    }
    if (noInit == true) {
        return node120;
    }
    return node120;
}
//--------------------------------------------------------------------------------
// StopEffect
//
REGISTER_REGISTER_SKILL_NODE(21065, 121) {
}

REGISTER_CREATE_SKILL_NODE(21065, 121) {
    auto node121 = GET_SKILL_NODE(121, PhaseNode_StopEffect);
    if (node121 == nullptr) {
        node121 = new PhaseNode_StopEffect(121, phase);
        node121->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node121->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node121->setEffectID(210631);
        CALL_REGISTER_SKILL_NODE(21065, 121, node121)
    }
    if (noInit == true) {
        return node121;
    }
    return node121;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(21065, 122) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetRotation>(PhaseNode_GetLocation::TRIGGER_DONE, 123, PhaseNode_GetRotation::FUNC_DO, &PhaseNode_GetRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(21065, 122) {
    auto node122 = GET_SKILL_NODE(122, PhaseNode_GetLocation);
    if (node122 == nullptr) {
        node122 = new PhaseNode_GetLocation(122, phase);
        node122->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node122->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(21065, 122, node122)
    }
    if (noInit == true) {
        return node122;
    }
    return node122;
}
//--------------------------------------------------------------------------------
// GetRotation
//
REGISTER_REGISTER_SKILL_NODE(21065, 123) {
    pnode->resizeTrigger(PhaseNode_GetRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_OffsetCalculate>(PhaseNode_GetRotation::TRIGGER_DONE, 124, PhaseNode_OffsetCalculate::FUNC_DO, &PhaseNode_OffsetCalculate::Do);
}

REGISTER_CREATE_SKILL_NODE(21065, 123) {
    auto node123 = GET_SKILL_NODE(123, PhaseNode_GetRotation);
    if (node123 == nullptr) {
        node123 = new PhaseNode_GetRotation(123, phase);
        node123->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node123->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(21065, 123, node123)
    }
    if (noInit == true) {
        return node123;
    }
    return node123;
}
//--------------------------------------------------------------------------------
// OffsetCalculate
//
REGISTER_REGISTER_SKILL_NODE(21065, 124) {
    pnode->resizeTrigger(PhaseNode_OffsetCalculate::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLineRotation>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 63, PhaseNode_GetLineRotation::FUNC_DO, &PhaseNode_GetLineRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(21065, 124) {
    auto node124 = GET_SKILL_NODE(124, PhaseNode_OffsetCalculate);
    if (node124 == nullptr) {
        node124 = new PhaseNode_OffsetCalculate(124, phase);
        node124->setPosZ(.00f);
        node124->setOffsetX(.00f);
        node124->setOffsetY(.00f);
        node124->setOffsetZ(.00f);
        node124->setRotOffset(.00f);
        CALL_REGISTER_SKILL_NODE(21065, 124, node124)
    }
    if (noInit == true) {
        return node124;
    }
    auto node122 = GET_SKILL_NODE(122, PhaseNode_GetLocation);
    auto node123 = GET_SKILL_NODE(123, PhaseNode_GetRotation);
    if (node122 != nullptr) node124->setPosX(node122->getX());
    if (node122 != nullptr) node124->setPosY(node122->getY());
    if (node123 != nullptr) node124->setRotation(node123->getAngle());
    return node124;
}

//--------------------------------------------------------------------------------
// SkillCreator_21065
//
class SkillCreator_21065 : public SkillCreator {
public:
    SkillCreator_21065() {}
    virtual ~SkillCreator_21065() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_21065

//--------------------------------------------------------------------------------
// SkillPhase_21065
//
class SkillPhase_21065 : public SkillPhase {
public:
    SkillPhase_21065(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_21065() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(21065, 2) // StartPhase
        CASE_CREATE_SKILL_NODE(21065, 3) // TriggerUpdate
        CASE_CREATE_SKILL_NODE(21065, 4) // Delay
        CASE_CREATE_SKILL_NODE(21065, 5) // PlayAnimation
        CASE_CREATE_SKILL_NODE(21065, 6) // Delay
        CASE_CREATE_SKILL_NODE(21065, 7) // ForContinue
        CASE_CREATE_SKILL_NODE(21065, 8) // PlayAnimation
        CASE_CREATE_SKILL_NODE(21065, 9) // EndPhase
        CASE_CREATE_SKILL_NODE(21065, 12) // SpawnProjectile
        CASE_CREATE_SKILL_NODE(21065, 13) // For
        CASE_CREATE_SKILL_NODE(21065, 14) // Delay
        CASE_CREATE_SKILL_NODE(21065, 15) // PlaySound
        CASE_CREATE_SKILL_NODE(21065, 16) // PlayAnimation
        CASE_CREATE_SKILL_NODE(21065, 25) // SpawnCollider
        CASE_CREATE_SKILL_NODE(21065, 28) // AttachTo
        CASE_CREATE_SKILL_NODE(21065, 37) // GetLineRotation
        CASE_CREATE_SKILL_NODE(21065, 39) // Delay
        CASE_CREATE_SKILL_NODE(21065, 63) // GetLineRotation
        CASE_CREATE_SKILL_NODE(21065, 66) // Delay
        CASE_CREATE_SKILL_NODE(21065, 67) // PlayAnimation
        CASE_CREATE_SKILL_NODE(21065, 68) // Delay
        CASE_CREATE_SKILL_NODE(21065, 69) // ForContinue
        CASE_CREATE_SKILL_NODE(21065, 70) // PlayAnimation
        CASE_CREATE_SKILL_NODE(21065, 71) // SpawnProjectile
        CASE_CREATE_SKILL_NODE(21065, 72) // For
        CASE_CREATE_SKILL_NODE(21065, 73) // Delay
        CASE_CREATE_SKILL_NODE(21065, 74) // PlaySound
        CASE_CREATE_SKILL_NODE(21065, 75) // PlayAnimation
        CASE_CREATE_SKILL_NODE(21065, 84) // SpawnCollider
        CASE_CREATE_SKILL_NODE(21065, 88) // AttachTo
        CASE_CREATE_SKILL_NODE(21065, 89) // ResetCD
        CASE_CREATE_SKILL_NODE(21065, 90) // PlayAnimation
        CASE_CREATE_SKILL_NODE(21065, 91) // PlaySound
        CASE_CREATE_SKILL_NODE(21065, 92) // Delay
        CASE_CREATE_SKILL_NODE(21065, 93) // GetLocation
        CASE_CREATE_SKILL_NODE(21065, 94) // GetRotation
        CASE_CREATE_SKILL_NODE(21065, 95) // OffsetCalculate
        CASE_CREATE_SKILL_NODE(21065, 96) // PlayEffect
        CASE_CREATE_SKILL_NODE(21065, 97) // If
        CASE_CREATE_SKILL_NODE(21065, 98) // PlayEffect
        CASE_CREATE_SKILL_NODE(21065, 99) // CompareFloat
        CASE_CREATE_SKILL_NODE(21065, 100) // Delay
        CASE_CREATE_SKILL_NODE(21065, 101) // StopEffect
        CASE_CREATE_SKILL_NODE(21065, 102) // Delay
        CASE_CREATE_SKILL_NODE(21065, 103) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(21065, 104) // If
        CASE_CREATE_SKILL_NODE(21065, 105) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(21065, 106) // GetLocation
        CASE_CREATE_SKILL_NODE(21065, 107) // GetRotation
        CASE_CREATE_SKILL_NODE(21065, 108) // OffsetCalculate
        CASE_CREATE_SKILL_NODE(21065, 109) // ResetCD
        CASE_CREATE_SKILL_NODE(21065, 110) // PlayAnimation
        CASE_CREATE_SKILL_NODE(21065, 111) // PlaySound
        CASE_CREATE_SKILL_NODE(21065, 112) // Delay
        CASE_CREATE_SKILL_NODE(21065, 113) // GetLocation
        CASE_CREATE_SKILL_NODE(21065, 114) // GetRotation
        CASE_CREATE_SKILL_NODE(21065, 115) // OffsetCalculate
        CASE_CREATE_SKILL_NODE(21065, 116) // PlayEffect
        CASE_CREATE_SKILL_NODE(21065, 117) // If
        CASE_CREATE_SKILL_NODE(21065, 118) // PlayEffect
        CASE_CREATE_SKILL_NODE(21065, 119) // CompareFloat
        CASE_CREATE_SKILL_NODE(21065, 120) // Delay
        CASE_CREATE_SKILL_NODE(21065, 121) // StopEffect
        CASE_CREATE_SKILL_NODE(21065, 122) // GetLocation
        CASE_CREATE_SKILL_NODE(21065, 123) // GetRotation
        CASE_CREATE_SKILL_NODE(21065, 124) // OffsetCalculate
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_21065

SkillLogic* SkillCreator_21065::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //创建阶段phase
    auto phase = new SkillPhase_21065(1, logic, 2);
    //设置phase执行器
    phase->setRunPhaseNode(1, 2);
    phase->setRunPhaseNode(2, 3);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_21065::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
