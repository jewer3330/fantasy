#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

#include "skill_psnode_actorfilternewpene.h"
#include "skill_psnode_addskillbuff.h"
#include "skill_psnode_addskillbuffs.h"
#include "skill_psnode_attachto.h"
#include "skill_psnode_comparefloat.h"
#include "skill_psnode_createtriggernewpene.h"
#include "skill_psnode_delay.h"
#include "skill_psnode_destroycollider.h"
#include "skill_psnode_distance.h"
#include "skill_psnode_endphase.h"
#include "skill_psnode_getactorattribute.h"
#include "skill_psnode_getlocation.h"
#include "skill_psnode_getrotation.h"
#include "skill_psnode_if.h"
#include "skill_psnode_movenewpene.h"
#include "skill_psnode_offsetcalculate.h"
#include "skill_psnode_playanimation.h"
#include "skill_psnode_playsound.h"
#include "skill_psnode_removeskillbuff.h"
#include "skill_psnode_resetcd.h"
#include "skill_psnode_spawncollider.h"
#include "skill_psnode_startphase.h"
#include "skill_psnode_triggercheck.h"
#include "skill_psnode_triggerupdate.h"

namespace pvp {

//变量声明
//--------------------------------------------------------------------------------
// StartPhase
//
REGISTER_REGISTER_SKILL_NODE(23032, 2) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_StartPhase::TRIGGER_START, 6, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(23032, 2) {
    auto node2 = GET_SKILL_NODE(2, PhaseNode_StartPhase);
    if (node2 == nullptr) {
        node2 = new PhaseNode_StartPhase(2, phase);
        CALL_REGISTER_SKILL_NODE(23032, 2, node2)
    }
    if (noInit == true) {
        return node2;
    }
    return node2;
}
//--------------------------------------------------------------------------------
// TriggerUpdate
//
REGISTER_REGISTER_SKILL_NODE(23032, 4) {
}

REGISTER_CREATE_SKILL_NODE(23032, 4) {
    auto node4 = GET_SKILL_NODE(4, PhaseNode_TriggerUpdate);
    if (node4 == nullptr) {
        node4 = new PhaseNode_TriggerUpdate(4, phase);
        CALL_REGISTER_SKILL_NODE(23032, 4, node4)
    }
    if (noInit == true) {
        return node4;
    }
    return node4;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(23032, 6) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_ResetCD::TRIGGER_DONE, 8, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(23032, 6) {
    auto node6 = GET_SKILL_NODE(6, PhaseNode_ResetCD);
    if (node6 == nullptr) {
        node6 = new PhaseNode_ResetCD(6, phase);
        node6->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node6->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node6->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(23032, 6, node6)
    }
    if (noInit == true) {
        return node6;
    }
    return node6;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(23032, 8) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetRotation>(PhaseNode_GetLocation::TRIGGER_DONE, 10, PhaseNode_GetRotation::FUNC_DO, &PhaseNode_GetRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(23032, 8) {
    auto node8 = GET_SKILL_NODE(8, PhaseNode_GetLocation);
    if (node8 == nullptr) {
        node8 = new PhaseNode_GetLocation(8, phase);
        node8->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node8->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(23032, 8, node8)
    }
    if (noInit == true) {
        return node8;
    }
    return node8;
}
//--------------------------------------------------------------------------------
// GetRotation
//
REGISTER_REGISTER_SKILL_NODE(23032, 10) {
    pnode->resizeTrigger(PhaseNode_GetRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_GetRotation::TRIGGER_DONE, 12, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(23032, 10) {
    auto node10 = GET_SKILL_NODE(10, PhaseNode_GetRotation);
    if (node10 == nullptr) {
        node10 = new PhaseNode_GetRotation(10, phase);
        node10->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node10->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(23032, 10, node10)
    }
    if (noInit == true) {
        return node10;
    }
    return node10;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(23032, 12) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlayAnimation::TRIGGER_DONE, 14, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_PlayAnimation::TRIGGER_DONE, 139, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(23032, 12) {
    auto node12 = GET_SKILL_NODE(12, PhaseNode_PlayAnimation);
    if (node12 == nullptr) {
        node12 = new PhaseNode_PlayAnimation(12, phase);
        node12->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node12->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node12->setTarget(0U);
        node12->setAnimation("Skill2S1");
        node12->setParameter("");
        node12->setValue(false);
        CALL_REGISTER_SKILL_NODE(23032, 12, node12)
    }
    if (noInit == true) {
        return node12;
    }
    return node12;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(23032, 14) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnCollider>(PhaseNode_Delay::TRIGGER_DONE, 16, PhaseNode_SpawnCollider::FUNC_DO, &PhaseNode_SpawnCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(23032, 14) {
    auto node14 = GET_SKILL_NODE(14, PhaseNode_Delay);
    if (node14 == nullptr) {
        node14 = new PhaseNode_Delay(14, phase);
        node14->setTime(.47f);
        CALL_REGISTER_SKILL_NODE(23032, 14, node14)
    }
    if (noInit == true) {
        return node14;
    }
    return node14;
}
//--------------------------------------------------------------------------------
// SpawnCollider
//
REGISTER_REGISTER_SKILL_NODE(23032, 16) {
    pnode->resizeTrigger(PhaseNode_SpawnCollider::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AttachTo>(PhaseNode_SpawnCollider::TRIGGER_DONE, 18, PhaseNode_AttachTo::FUNC_DO, &PhaseNode_AttachTo::Do);
}

REGISTER_CREATE_SKILL_NODE(23032, 16) {
    auto node16 = GET_SKILL_NODE(16, PhaseNode_SpawnCollider);
    if (node16 == nullptr) {
        node16 = new PhaseNode_SpawnCollider(16, phase);
        node16->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node16->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node16->setMesh("");
        node16->setMeshScale(.00f);
        node16->setEffectID(0);
        node16->setEffectScale(.00f);
        node16->setType(PhaseNode_SpawnCollider::SpawnCollider_Type::Circle);
        node16->setTypeParams(0, .00f);
        node16->setTime(.00f);
        node16->setPosZ(1.50f);
        node16->setreentry(false);
        node16->setCheckPeneSound(false);
        CALL_REGISTER_SKILL_NODE(23032, 16, node16)
    }
    if (noInit == true) {
        return node16;
    }
    auto node8 = GET_SKILL_NODE(8, PhaseNode_GetLocation);
    auto node10 = GET_SKILL_NODE(10, PhaseNode_GetRotation);
    if (node8 != nullptr) node16->setPosX(node8->getX());
    if (node8 != nullptr) node16->setPosY(node8->getY());
    if (node10 != nullptr) node16->setRotation(node10->getAngle());
    return node16;
}
//--------------------------------------------------------------------------------
// AttachTo
//
REGISTER_REGISTER_SKILL_NODE(23032, 18) {
    pnode->resizeTrigger(PhaseNode_AttachTo::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_OffsetCalculate>(PhaseNode_AttachTo::TRIGGER_DONE, 56, PhaseNode_OffsetCalculate::FUNC_DO, &PhaseNode_OffsetCalculate::Do);
}

REGISTER_CREATE_SKILL_NODE(23032, 18) {
    auto node18 = GET_SKILL_NODE(18, PhaseNode_AttachTo);
    if (node18 == nullptr) {
        node18 = new PhaseNode_AttachTo(18, phase);
        node18->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node18->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node18->setChild(0U);
        node18->setChangeRotation(true);
        node18->setreentry(false);
        CALL_REGISTER_SKILL_NODE(23032, 18, node18)
    }
    if (noInit == true) {
        return node18;
    }
    auto node16 = GET_SKILL_NODE(16, PhaseNode_SpawnCollider);
    if (node16 != nullptr) node18->setParent(node16->getColliderID());
    return node18;
}
//--------------------------------------------------------------------------------
// SpawnCollider
//
REGISTER_REGISTER_SKILL_NODE(23032, 24) {
    pnode->resizeTrigger(PhaseNode_SpawnCollider::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_SpawnCollider::TRIGGER_DONE, 177, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(23032, 24) {
    auto node24 = GET_SKILL_NODE(24, PhaseNode_SpawnCollider);
    if (node24 == nullptr) {
        node24 = new PhaseNode_SpawnCollider(24, phase);
        node24->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node24->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node24->setMesh("");
        node24->setMeshScale(.00f);
        node24->setEffectID(0);
        node24->setEffectScale(.00f);
        node24->setType(PhaseNode_SpawnCollider::SpawnCollider_Type::Rect);
        node24->setTypeParams(0, 6.00f);
        node24->setTypeParams(1, 1.50f);
        node24->setTime(.20f);
        node24->setreentry(false);
        node24->setCheckPeneSound(false);
        CALL_REGISTER_SKILL_NODE(23032, 24, node24)
    }
    if (noInit == true) {
        return node24;
    }
    auto node26 = GET_SKILL_NODE(26, PhaseNode_OffsetCalculate);
    if (node26 != nullptr) node24->setPosX(node26->getOutPosX());
    if (node26 != nullptr) node24->setPosY(node26->getOutPosY());
    if (node26 != nullptr) node24->setPosZ(node26->getOutPosZ());
    if (node26 != nullptr) node24->setRotation(node26->getOutRotation());
    return node24;
}
//--------------------------------------------------------------------------------
// OffsetCalculate
//
REGISTER_REGISTER_SKILL_NODE(23032, 26) {
    pnode->resizeTrigger(PhaseNode_OffsetCalculate::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnCollider>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 24, PhaseNode_SpawnCollider::FUNC_DO, &PhaseNode_SpawnCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(23032, 26) {
    auto node26 = GET_SKILL_NODE(26, PhaseNode_OffsetCalculate);
    if (node26 == nullptr) {
        node26 = new PhaseNode_OffsetCalculate(26, phase);
        node26->setPosZ(.00f);
        node26->setOffsetX(.00f);
        node26->setOffsetY(3.00f);
        node26->setOffsetZ(.00f);
        node26->setRotOffset(.00f);
        CALL_REGISTER_SKILL_NODE(23032, 26, node26)
    }
    if (noInit == true) {
        return node26;
    }
    auto node8 = GET_SKILL_NODE(8, PhaseNode_GetLocation);
    auto node10 = GET_SKILL_NODE(10, PhaseNode_GetRotation);
    if (node8 != nullptr) node26->setPosX(node8->getX());
    if (node8 != nullptr) node26->setPosY(node8->getY());
    if (node10 != nullptr) node26->setRotation(node10->getAngle());
    return node26;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(23032, 37) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlayAnimation::TRIGGER_DONE, 39, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(23032, 37) {
    auto node37 = GET_SKILL_NODE(37, PhaseNode_PlayAnimation);
    if (node37 == nullptr) {
        node37 = new PhaseNode_PlayAnimation(37, phase);
        node37->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node37->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node37->setTarget(0U);
        node37->setAnimation("Skill2S3");
        node37->setParameter("");
        node37->setValue(false);
        CALL_REGISTER_SKILL_NODE(23032, 37, node37)
    }
    if (noInit == true) {
        return node37;
    }
    return node37;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(23032, 39) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_Delay::TRIGGER_DONE, 41, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(23032, 39) {
    auto node39 = GET_SKILL_NODE(39, PhaseNode_Delay);
    if (node39 == nullptr) {
        node39 = new PhaseNode_Delay(39, phase);
        node39->setTime(.50f);
        CALL_REGISTER_SKILL_NODE(23032, 39, node39)
    }
    if (noInit == true) {
        return node39;
    }
    return node39;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(23032, 41) {
}

REGISTER_CREATE_SKILL_NODE(23032, 41) {
    auto node41 = GET_SKILL_NODE(41, PhaseNode_EndPhase);
    if (node41 == nullptr) {
        node41 = new PhaseNode_EndPhase(41, phase);
        node41->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node41->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(23032, 41, node41)
    }
    if (noInit == true) {
        return node41;
    }
    return node41;
}
//--------------------------------------------------------------------------------
// OffsetCalculate
//
REGISTER_REGISTER_SKILL_NODE(23032, 56) {
    pnode->resizeTrigger(PhaseNode_OffsetCalculate::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_MoveNewPene>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 165, PhaseNode_MoveNewPene::FUNC_DO, &PhaseNode_MoveNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(23032, 56) {
    auto node56 = GET_SKILL_NODE(56, PhaseNode_OffsetCalculate);
    if (node56 == nullptr) {
        node56 = new PhaseNode_OffsetCalculate(56, phase);
        node56->setPosZ(.00f);
        node56->setOffsetX(.00f);
        node56->setOffsetY(6.00f);
        node56->setOffsetZ(.00f);
        node56->setRotOffset(.00f);
        CALL_REGISTER_SKILL_NODE(23032, 56, node56)
    }
    if (noInit == true) {
        return node56;
    }
    auto node8 = GET_SKILL_NODE(8, PhaseNode_GetLocation);
    auto node10 = GET_SKILL_NODE(10, PhaseNode_GetRotation);
    if (node8 != nullptr) node56->setPosX(node8->getX());
    if (node8 != nullptr) node56->setPosY(node8->getY());
    if (node10 != nullptr) node56->setRotation(node10->getAngle());
    return node56;
}
//--------------------------------------------------------------------------------
// SpawnCollider
//
REGISTER_REGISTER_SKILL_NODE(23032, 71) {
    pnode->resizeTrigger(PhaseNode_SpawnCollider::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_SpawnCollider::TRIGGER_DONE, 118, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(23032, 71) {
    auto node71 = GET_SKILL_NODE(71, PhaseNode_SpawnCollider);
    if (node71 == nullptr) {
        node71 = new PhaseNode_SpawnCollider(71, phase);
        node71->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node71->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node71->setMesh("");
        node71->setMeshScale(.00f);
        node71->setEffectID(230311);
        node71->setEffectScale(.00f);
        node71->setType(PhaseNode_SpawnCollider::SpawnCollider_Type::Circle);
        node71->setTypeParams(0, .00f);
        node71->setTime(.00f);
        node71->setreentry(false);
        node71->setCheckPeneSound(false);
        CALL_REGISTER_SKILL_NODE(23032, 71, node71)
    }
    if (noInit == true) {
        return node71;
    }
    auto node87 = GET_SKILL_NODE(87, PhaseNode_OffsetCalculate);
    if (node87 != nullptr) node71->setPosX(node87->getOutPosX());
    if (node87 != nullptr) node71->setPosY(node87->getOutPosY());
    if (node87 != nullptr) node71->setPosZ(node87->getOutPosZ());
    if (node87 != nullptr) node71->setRotation(node87->getOutRotation());
    return node71;
}
//--------------------------------------------------------------------------------
// OffsetCalculate
//
REGISTER_REGISTER_SKILL_NODE(23032, 87) {
    pnode->resizeTrigger(PhaseNode_OffsetCalculate::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnCollider>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 71, PhaseNode_SpawnCollider::FUNC_DO, &PhaseNode_SpawnCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(23032, 87) {
    auto node87 = GET_SKILL_NODE(87, PhaseNode_OffsetCalculate);
    if (node87 == nullptr) {
        node87 = new PhaseNode_OffsetCalculate(87, phase);
        node87->setPosZ(.00f);
        node87->setOffsetX(.27f);
        node87->setOffsetY(1.30f);
        node87->setOffsetZ(1.50f);
        node87->setRotOffset(.00f);
        CALL_REGISTER_SKILL_NODE(23032, 87, node87)
    }
    if (noInit == true) {
        return node87;
    }
    auto node8 = GET_SKILL_NODE(8, PhaseNode_GetLocation);
    auto node10 = GET_SKILL_NODE(10, PhaseNode_GetRotation);
    if (node8 != nullptr) node87->setPosX(node8->getX());
    if (node8 != nullptr) node87->setPosY(node8->getY());
    if (node10 != nullptr) node87->setRotation(node10->getAngle());
    return node87;
}
//--------------------------------------------------------------------------------
// DestroyCollider
//
REGISTER_REGISTER_SKILL_NODE(23032, 104) {
}

REGISTER_CREATE_SKILL_NODE(23032, 104) {
    auto node104 = GET_SKILL_NODE(104, PhaseNode_DestroyCollider);
    if (node104 == nullptr) {
        node104 = new PhaseNode_DestroyCollider(104, phase);
        CALL_REGISTER_SKILL_NODE(23032, 104, node104)
    }
    if (noInit == true) {
        return node104;
    }
    auto node71 = GET_SKILL_NODE(71, PhaseNode_SpawnCollider);
    if (node71 != nullptr) node104->setColliderID(node71->getColliderID());
    return node104;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(23032, 106) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_DestroyCollider>(PhaseNode_Delay::TRIGGER_DONE, 104, PhaseNode_DestroyCollider::FUNC_DO, &PhaseNode_DestroyCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(23032, 106) {
    auto node106 = GET_SKILL_NODE(106, PhaseNode_Delay);
    if (node106 == nullptr) {
        node106 = new PhaseNode_Delay(106, phase);
        node106->setTime(.10f);
        CALL_REGISTER_SKILL_NODE(23032, 106, node106)
    }
    if (noInit == true) {
        return node106;
    }
    return node106;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(23032, 118) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Distance>(PhaseNode_GetLocation::TRIGGER_DONE, 120, PhaseNode_Distance::FUNC_DO, &PhaseNode_Distance::Do);
}

REGISTER_CREATE_SKILL_NODE(23032, 118) {
    auto node118 = GET_SKILL_NODE(118, PhaseNode_GetLocation);
    if (node118 == nullptr) {
        node118 = new PhaseNode_GetLocation(118, phase);
        node118->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        CALL_REGISTER_SKILL_NODE(23032, 118, node118)
    }
    if (noInit == true) {
        return node118;
    }
    auto node16 = GET_SKILL_NODE(16, PhaseNode_SpawnCollider);
    if (node16 != nullptr) node118->setTarget(node16->getColliderID());
    return node118;
}
//--------------------------------------------------------------------------------
// Distance
//
REGISTER_REGISTER_SKILL_NODE(23032, 120) {
    pnode->resizeTrigger(PhaseNode_Distance::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_MoveNewPene>(PhaseNode_Distance::TRIGGER_DONE, 169, PhaseNode_MoveNewPene::FUNC_DO, &PhaseNode_MoveNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(23032, 120) {
    auto node120 = GET_SKILL_NODE(120, PhaseNode_Distance);
    if (node120 == nullptr) {
        node120 = new PhaseNode_Distance(120, phase);
        CALL_REGISTER_SKILL_NODE(23032, 120, node120)
    }
    if (noInit == true) {
        return node120;
    }
    auto node118 = GET_SKILL_NODE(118, PhaseNode_GetLocation);
    auto node8 = GET_SKILL_NODE(8, PhaseNode_GetLocation);
    if (node118 != nullptr) node120->setAX(node118->getX());
    if (node118 != nullptr) node120->setAY(node118->getY());
    if (node8 != nullptr) node120->setBX(node8->getX());
    if (node8 != nullptr) node120->setBY(node8->getY());
    return node120;
}
//--------------------------------------------------------------------------------
// AddSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(23032, 135) {
}

REGISTER_CREATE_SKILL_NODE(23032, 135) {
    auto node135 = GET_SKILL_NODE(135, PhaseNode_AddSkillBuff);
    if (node135 == nullptr) {
        node135 = new PhaseNode_AddSkillBuff(135, phase);
        node135->setConfigID(3);
        node135->setConfigIDs({});
        node135->setTarget(0U);
        node135->setAttribute({{}});
        CALL_REGISTER_SKILL_NODE(23032, 135, node135)
    }
    if (noInit == true) {
        return node135;
    }
    return node135;
}
//--------------------------------------------------------------------------------
// RemoveSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(23032, 137) {
}

REGISTER_CREATE_SKILL_NODE(23032, 137) {
    auto node137 = GET_SKILL_NODE(137, PhaseNode_RemoveSkillBuff);
    if (node137 == nullptr) {
        node137 = new PhaseNode_RemoveSkillBuff(137, phase);
        node137->setBuffID(0U);
        node137->setBuffIDs({});
        node137->setConfigID(0);
        node137->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(23032, 137, node137)
    }
    if (noInit == true) {
        return node137;
    }
    return node137;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(23032, 139) {
}

REGISTER_CREATE_SKILL_NODE(23032, 139) {
    auto node139 = GET_SKILL_NODE(139, PhaseNode_PlaySound);
    if (node139 == nullptr) {
        node139 = new PhaseNode_PlaySound(139, phase);
        node139->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node139->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node139->setSoundID("SE_MON2303_ATK1_P1");
        node139->setTarget(0U);
        node139->setUsePos(false);
        node139->setPosX(.00f);
        node139->setPosY(.00f);
        node139->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(23032, 139, node139)
    }
    if (noInit == true) {
        return node139;
    }
    return node139;
}
//--------------------------------------------------------------------------------
// MoveNewPene
//
REGISTER_REGISTER_SKILL_NODE(23032, 165) {
    pnode->resizeTrigger(PhaseNode_MoveNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_OffsetCalculate>(PhaseNode_MoveNewPene::TRIGGER_DONE, 26, PhaseNode_OffsetCalculate::FUNC_DO, &PhaseNode_OffsetCalculate::Do);
    pnode->regTrigger<PhaseNode_OffsetCalculate>(PhaseNode_MoveNewPene::TRIGGER_DONE, 87, PhaseNode_OffsetCalculate::FUNC_DO, &PhaseNode_OffsetCalculate::Do);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_MoveNewPene::TRIGGER_DONE, 37, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
    pnode->regTrigger<PhaseNode_RemoveSkillBuff>(PhaseNode_MoveNewPene::TRIGGER_DONE, 137, PhaseNode_RemoveSkillBuff::FUNC_REMOVE, &PhaseNode_RemoveSkillBuff::Remove);
    pnode->regTrigger<PhaseNode_AddSkillBuff>(PhaseNode_MoveNewPene::TRIGGER_STARTMOVE, 135, PhaseNode_AddSkillBuff::FUNC_ADD, &PhaseNode_AddSkillBuff::Add);
}

REGISTER_CREATE_SKILL_NODE(23032, 165) {
    auto node165 = GET_SKILL_NODE(165, PhaseNode_MoveNewPene);
    if (node165 == nullptr) {
        node165 = new PhaseNode_MoveNewPene(165, phase);
        node165->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node165->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node165->setPeneType(PhaseNode_MoveNewPene::MoveNewPene_PeneType::Move);
        node165->setPeneValue(0);
        node165->setType(PhaseNode_MoveNewPene::MoveNewPene_Type::Teleport);
        node165->getVars().reserve(2);
        node165->getVars().setVariable<float>(0, .00f);
        node165->getVars().setVariable<float>(1, .00f);
        node165->setreentry(false);
        node165->setStopWhenFail(true);
        node165->setCheckFaction(PhaseNode_MoveNewPene::MoveNewPene_CheckFaction::Enemy);
        CALL_REGISTER_SKILL_NODE(23032, 165, node165)
    }
    if (noInit == true) {
        return node165;
    }
    auto node16 = GET_SKILL_NODE(16, PhaseNode_SpawnCollider);
    auto node56 = GET_SKILL_NODE(56, PhaseNode_OffsetCalculate);
    if (node16 != nullptr) node165->setTarget(node16->getColliderID());
    if (node56 != nullptr) node165->getVars().setVariable<float>(0, node56->getOutPosX());
    if (node56 != nullptr) node165->getVars().setVariable<float>(1, node56->getOutPosY());
    return node165;
}
//--------------------------------------------------------------------------------
// MoveNewPene
//
REGISTER_REGISTER_SKILL_NODE(23032, 169) {
    pnode->resizeTrigger(PhaseNode_MoveNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_MoveNewPene::TRIGGER_DONE, 106, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(23032, 169) {
    auto node169 = GET_SKILL_NODE(169, PhaseNode_MoveNewPene);
    if (node169 == nullptr) {
        node169 = new PhaseNode_MoveNewPene(169, phase);
        node169->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node169->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node169->setPeneType(PhaseNode_MoveNewPene::MoveNewPene_PeneType::Move);
        node169->setPeneValue(0);
        node169->setType(PhaseNode_MoveNewPene::MoveNewPene_Type::Charge);
        node169->getVars().reserve(4);
        node169->getVars().setVariable<float>(0, 50.00f);
        node169->getVars().setVariable<float>(1, .00f);
        node169->getVars().setVariable<float>(2, .00f);
        node169->getVars().setVariable<float>(3, .00f);
        node169->setreentry(false);
        node169->setStopWhenFail(false);
        node169->setCheckFaction(PhaseNode_MoveNewPene::MoveNewPene_CheckFaction::Enemy);
        CALL_REGISTER_SKILL_NODE(23032, 169, node169)
    }
    if (noInit == true) {
        return node169;
    }
    auto node71 = GET_SKILL_NODE(71, PhaseNode_SpawnCollider);
    auto node120 = GET_SKILL_NODE(120, PhaseNode_Distance);
    if (node71 != nullptr) node169->setTarget(node71->getColliderID());
    if (node120 != nullptr) node169->getVars().setVariable<float>(1, node120->getResult());
    return node169;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(23032, 170) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 182, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 184, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(23032, 170) {
    auto node170 = GET_SKILL_NODE(170, PhaseNode_CreateTriggerNewPene);
    if (node170 == nullptr) {
        node170 = new PhaseNode_CreateTriggerNewPene(170, phase);
        node170->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::In);
        node170->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node170->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Enemy);
        node170->setOnHero(true);
        node170->setOnMinion(true);
        node170->setOnDestruct(true);
        node170->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(23032, 170, node170)
    }
    if (noInit == true) {
        return node170;
    }
    auto node24 = GET_SKILL_NODE(24, PhaseNode_SpawnCollider);
    if (node24 != nullptr) node170->setColliderID(node24->getColliderID());
    return node170;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(23032, 171) {
}

REGISTER_CREATE_SKILL_NODE(23032, 171) {
    auto node171 = GET_SKILL_NODE(171, PhaseNode_TriggerCheck);
    if (node171 == nullptr) {
        node171 = new PhaseNode_TriggerCheck(171, phase);
        auto node4 = GET_SKILL_NODE(4, PhaseNode_TriggerUpdate);
        if (node4 != nullptr) node4->addTriggerCheck(node171);
        
        CALL_REGISTER_SKILL_NODE(23032, 171, node171)
    }
    if (noInit == true) {
        return node171;
    }
    auto node180 = GET_SKILL_NODE(180, PhaseNode_CreateTriggerNewPene);
    if (node180 != nullptr) node171->setTrigger(0, node180->getTriggerID());
    return node171;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(23032, 172) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 173, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(23032, 172) {
    auto node172 = GET_SKILL_NODE(172, PhaseNode_ActorFilterNewPene);
    if (node172 == nullptr) {
        node172 = new PhaseNode_ActorFilterNewPene(172, phase);
        node172->setHero(true);
        node172->setMinion(true);
        node172->setDestruct(true);
        node172->setShield(false);
        node172->setTotalCount(0);
        node172->setPerCount(1);
        CALL_REGISTER_SKILL_NODE(23032, 172, node172)
    }
    if (noInit == true) {
        return node172;
    }
    auto node176 = GET_SKILL_NODE(176, PhaseNode_CreateTriggerNewPene);
    if (node176 != nullptr) node172->setInput(node176->getOther());
    return node172;
}
//--------------------------------------------------------------------------------
// GetActorAttribute
//
REGISTER_REGISTER_SKILL_NODE(23032, 173) {
    pnode->resizeTrigger(PhaseNode_GetActorAttribute::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 174, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 187, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 188, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 189, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
}

REGISTER_CREATE_SKILL_NODE(23032, 173) {
    auto node173 = GET_SKILL_NODE(173, PhaseNode_GetActorAttribute);
    if (node173 == nullptr) {
        node173 = new PhaseNode_GetActorAttribute(173, phase);
        node173->setTarget(0U);
        node173->setType({202});
        CALL_REGISTER_SKILL_NODE(23032, 173, node173)
    }
    if (noInit == true) {
        return node173;
    }
    return node173;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(23032, 174) {
}

REGISTER_CREATE_SKILL_NODE(23032, 174) {
    auto node174 = GET_SKILL_NODE(174, PhaseNode_AddSkillBuffs);
    if (node174 == nullptr) {
        node174 = new PhaseNode_AddSkillBuffs(174, phase);
        node174->setConfigID({230311});
        CALL_REGISTER_SKILL_NODE(23032, 174, node174)
    }
    if (noInit == true) {
        return node174;
    }
    auto node172 = GET_SKILL_NODE(172, PhaseNode_ActorFilterNewPene);
    auto node173 = GET_SKILL_NODE(173, PhaseNode_GetActorAttribute);
    if (node172 != nullptr) node174->setTarget(node172->getOutput());
    if (node173 != nullptr) node174->setAttribute(node173->getAttribute());
    return node174;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(23032, 175) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 170, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_LESS, 176, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
}

REGISTER_CREATE_SKILL_NODE(23032, 175) {
    auto node175 = GET_SKILL_NODE(175, PhaseNode_CompareFloat);
    if (node175 == nullptr) {
        node175 = new PhaseNode_CompareFloat(175, phase);
        node175->setA(.00f);
        node175->setB(.00f);
        CALL_REGISTER_SKILL_NODE(23032, 175, node175)
    }
    if (noInit == true) {
        return node175;
    }
    return node175;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(23032, 176) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 181, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 172, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(23032, 176) {
    auto node176 = GET_SKILL_NODE(176, PhaseNode_CreateTriggerNewPene);
    if (node176 == nullptr) {
        node176 = new PhaseNode_CreateTriggerNewPene(176, phase);
        node176->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::Tick);
        node176->setTypeParams(0, .00f);
        node176->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node176->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Enemy);
        node176->setOnHero(true);
        node176->setOnMinion(true);
        node176->setOnDestruct(true);
        node176->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(23032, 176, node176)
    }
    if (noInit == true) {
        return node176;
    }
    auto node24 = GET_SKILL_NODE(24, PhaseNode_SpawnCollider);
    if (node24 != nullptr) node176->setColliderID(node24->getColliderID());
    return node176;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(23032, 177) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_If::TRIGGER_FALSE, 178, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_If::TRIGGER_TRUE, 175, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(23032, 177) {
    auto node177 = GET_SKILL_NODE(177, PhaseNode_If);
    if (node177 == nullptr) {
        node177 = new PhaseNode_If(177, phase);
        node177->setCondition(false);
        CALL_REGISTER_SKILL_NODE(23032, 177, node177)
    }
    if (noInit == true) {
        return node177;
    }
    return node177;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(23032, 178) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 180, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_LESS, 179, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
}

REGISTER_CREATE_SKILL_NODE(23032, 178) {
    auto node178 = GET_SKILL_NODE(178, PhaseNode_CompareFloat);
    if (node178 == nullptr) {
        node178 = new PhaseNode_CompareFloat(178, phase);
        node178->setA(.00f);
        node178->setB(.00f);
        CALL_REGISTER_SKILL_NODE(23032, 178, node178)
    }
    if (noInit == true) {
        return node178;
    }
    return node178;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(23032, 179) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 183, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 185, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(23032, 179) {
    auto node179 = GET_SKILL_NODE(179, PhaseNode_CreateTriggerNewPene);
    if (node179 == nullptr) {
        node179 = new PhaseNode_CreateTriggerNewPene(179, phase);
        node179->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::Tick);
        node179->setTypeParams(0, .00f);
        node179->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node179->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Friend);
        node179->setOnHero(true);
        node179->setOnMinion(true);
        node179->setOnDestruct(true);
        node179->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(23032, 179, node179)
    }
    if (noInit == true) {
        return node179;
    }
    auto node24 = GET_SKILL_NODE(24, PhaseNode_SpawnCollider);
    if (node24 != nullptr) node179->setColliderID(node24->getColliderID());
    return node179;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(23032, 180) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 171, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 186, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(23032, 180) {
    auto node180 = GET_SKILL_NODE(180, PhaseNode_CreateTriggerNewPene);
    if (node180 == nullptr) {
        node180 = new PhaseNode_CreateTriggerNewPene(180, phase);
        node180->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::In);
        node180->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node180->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Friend);
        node180->setOnHero(true);
        node180->setOnMinion(true);
        node180->setOnDestruct(true);
        node180->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(23032, 180, node180)
    }
    if (noInit == true) {
        return node180;
    }
    auto node24 = GET_SKILL_NODE(24, PhaseNode_SpawnCollider);
    if (node24 != nullptr) node180->setColliderID(node24->getColliderID());
    return node180;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(23032, 181) {
}

REGISTER_CREATE_SKILL_NODE(23032, 181) {
    auto node181 = GET_SKILL_NODE(181, PhaseNode_TriggerCheck);
    if (node181 == nullptr) {
        node181 = new PhaseNode_TriggerCheck(181, phase);
        auto node4 = GET_SKILL_NODE(4, PhaseNode_TriggerUpdate);
        if (node4 != nullptr) node4->addTriggerCheck(node181);
        
        CALL_REGISTER_SKILL_NODE(23032, 181, node181)
    }
    if (noInit == true) {
        return node181;
    }
    auto node176 = GET_SKILL_NODE(176, PhaseNode_CreateTriggerNewPene);
    if (node176 != nullptr) node181->setTrigger(0, node176->getTriggerID());
    return node181;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(23032, 182) {
}

REGISTER_CREATE_SKILL_NODE(23032, 182) {
    auto node182 = GET_SKILL_NODE(182, PhaseNode_TriggerCheck);
    if (node182 == nullptr) {
        node182 = new PhaseNode_TriggerCheck(182, phase);
        auto node4 = GET_SKILL_NODE(4, PhaseNode_TriggerUpdate);
        if (node4 != nullptr) node4->addTriggerCheck(node182);
        
        CALL_REGISTER_SKILL_NODE(23032, 182, node182)
    }
    if (noInit == true) {
        return node182;
    }
    auto node170 = GET_SKILL_NODE(170, PhaseNode_CreateTriggerNewPene);
    if (node170 != nullptr) node182->setTrigger(0, node170->getTriggerID());
    return node182;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(23032, 183) {
}

REGISTER_CREATE_SKILL_NODE(23032, 183) {
    auto node183 = GET_SKILL_NODE(183, PhaseNode_TriggerCheck);
    if (node183 == nullptr) {
        node183 = new PhaseNode_TriggerCheck(183, phase);
        auto node4 = GET_SKILL_NODE(4, PhaseNode_TriggerUpdate);
        if (node4 != nullptr) node4->addTriggerCheck(node183);
        
        CALL_REGISTER_SKILL_NODE(23032, 183, node183)
    }
    if (noInit == true) {
        return node183;
    }
    auto node179 = GET_SKILL_NODE(179, PhaseNode_CreateTriggerNewPene);
    if (node179 != nullptr) node183->setTrigger(0, node179->getTriggerID());
    return node183;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(23032, 184) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 173, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(23032, 184) {
    auto node184 = GET_SKILL_NODE(184, PhaseNode_ActorFilterNewPene);
    if (node184 == nullptr) {
        node184 = new PhaseNode_ActorFilterNewPene(184, phase);
        node184->setHero(true);
        node184->setMinion(true);
        node184->setDestruct(true);
        node184->setShield(false);
        node184->setTotalCount(0);
        node184->setPerCount(1);
        CALL_REGISTER_SKILL_NODE(23032, 184, node184)
    }
    if (noInit == true) {
        return node184;
    }
    auto node170 = GET_SKILL_NODE(170, PhaseNode_CreateTriggerNewPene);
    if (node170 != nullptr) node184->setInput(node170->getOther());
    return node184;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(23032, 185) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 173, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(23032, 185) {
    auto node185 = GET_SKILL_NODE(185, PhaseNode_ActorFilterNewPene);
    if (node185 == nullptr) {
        node185 = new PhaseNode_ActorFilterNewPene(185, phase);
        node185->setHero(true);
        node185->setMinion(true);
        node185->setDestruct(true);
        node185->setShield(false);
        node185->setTotalCount(0);
        node185->setPerCount(1);
        CALL_REGISTER_SKILL_NODE(23032, 185, node185)
    }
    if (noInit == true) {
        return node185;
    }
    auto node179 = GET_SKILL_NODE(179, PhaseNode_CreateTriggerNewPene);
    if (node179 != nullptr) node185->setInput(node179->getOther());
    return node185;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(23032, 186) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 173, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(23032, 186) {
    auto node186 = GET_SKILL_NODE(186, PhaseNode_ActorFilterNewPene);
    if (node186 == nullptr) {
        node186 = new PhaseNode_ActorFilterNewPene(186, phase);
        node186->setHero(true);
        node186->setMinion(true);
        node186->setDestruct(true);
        node186->setShield(false);
        node186->setTotalCount(0);
        node186->setPerCount(1);
        CALL_REGISTER_SKILL_NODE(23032, 186, node186)
    }
    if (noInit == true) {
        return node186;
    }
    auto node180 = GET_SKILL_NODE(180, PhaseNode_CreateTriggerNewPene);
    if (node180 != nullptr) node186->setInput(node180->getOther());
    return node186;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(23032, 187) {
}

REGISTER_CREATE_SKILL_NODE(23032, 187) {
    auto node187 = GET_SKILL_NODE(187, PhaseNode_AddSkillBuffs);
    if (node187 == nullptr) {
        node187 = new PhaseNode_AddSkillBuffs(187, phase);
        node187->setConfigID({230311});
        CALL_REGISTER_SKILL_NODE(23032, 187, node187)
    }
    if (noInit == true) {
        return node187;
    }
    auto node184 = GET_SKILL_NODE(184, PhaseNode_ActorFilterNewPene);
    auto node173 = GET_SKILL_NODE(173, PhaseNode_GetActorAttribute);
    if (node184 != nullptr) node187->setTarget(node184->getOutput());
    if (node173 != nullptr) node187->setAttribute(node173->getAttribute());
    return node187;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(23032, 188) {
}

REGISTER_CREATE_SKILL_NODE(23032, 188) {
    auto node188 = GET_SKILL_NODE(188, PhaseNode_AddSkillBuffs);
    if (node188 == nullptr) {
        node188 = new PhaseNode_AddSkillBuffs(188, phase);
        node188->setConfigID({230311});
        CALL_REGISTER_SKILL_NODE(23032, 188, node188)
    }
    if (noInit == true) {
        return node188;
    }
    auto node185 = GET_SKILL_NODE(185, PhaseNode_ActorFilterNewPene);
    auto node173 = GET_SKILL_NODE(173, PhaseNode_GetActorAttribute);
    if (node185 != nullptr) node188->setTarget(node185->getOutput());
    if (node173 != nullptr) node188->setAttribute(node173->getAttribute());
    return node188;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(23032, 189) {
}

REGISTER_CREATE_SKILL_NODE(23032, 189) {
    auto node189 = GET_SKILL_NODE(189, PhaseNode_AddSkillBuffs);
    if (node189 == nullptr) {
        node189 = new PhaseNode_AddSkillBuffs(189, phase);
        node189->setConfigID({230311});
        CALL_REGISTER_SKILL_NODE(23032, 189, node189)
    }
    if (noInit == true) {
        return node189;
    }
    auto node186 = GET_SKILL_NODE(186, PhaseNode_ActorFilterNewPene);
    auto node173 = GET_SKILL_NODE(173, PhaseNode_GetActorAttribute);
    if (node186 != nullptr) node189->setTarget(node186->getOutput());
    if (node173 != nullptr) node189->setAttribute(node173->getAttribute());
    return node189;
}

//--------------------------------------------------------------------------------
// SkillCreator_23032
//
class SkillCreator_23032 : public SkillCreator {
public:
    SkillCreator_23032() {}
    virtual ~SkillCreator_23032() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_23032

//--------------------------------------------------------------------------------
// SkillPhase_23032
//
class SkillPhase_23032 : public SkillPhase {
public:
    SkillPhase_23032(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_23032() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(23032, 2) // StartPhase
        CASE_CREATE_SKILL_NODE(23032, 4) // TriggerUpdate
        CASE_CREATE_SKILL_NODE(23032, 6) // ResetCD
        CASE_CREATE_SKILL_NODE(23032, 8) // GetLocation
        CASE_CREATE_SKILL_NODE(23032, 10) // GetRotation
        CASE_CREATE_SKILL_NODE(23032, 12) // PlayAnimation
        CASE_CREATE_SKILL_NODE(23032, 14) // Delay
        CASE_CREATE_SKILL_NODE(23032, 16) // SpawnCollider
        CASE_CREATE_SKILL_NODE(23032, 18) // AttachTo
        CASE_CREATE_SKILL_NODE(23032, 24) // SpawnCollider
        CASE_CREATE_SKILL_NODE(23032, 26) // OffsetCalculate
        CASE_CREATE_SKILL_NODE(23032, 37) // PlayAnimation
        CASE_CREATE_SKILL_NODE(23032, 39) // Delay
        CASE_CREATE_SKILL_NODE(23032, 41) // EndPhase
        CASE_CREATE_SKILL_NODE(23032, 56) // OffsetCalculate
        CASE_CREATE_SKILL_NODE(23032, 71) // SpawnCollider
        CASE_CREATE_SKILL_NODE(23032, 87) // OffsetCalculate
        CASE_CREATE_SKILL_NODE(23032, 104) // DestroyCollider
        CASE_CREATE_SKILL_NODE(23032, 106) // Delay
        CASE_CREATE_SKILL_NODE(23032, 118) // GetLocation
        CASE_CREATE_SKILL_NODE(23032, 120) // Distance
        CASE_CREATE_SKILL_NODE(23032, 135) // AddSkillBuff
        CASE_CREATE_SKILL_NODE(23032, 137) // RemoveSkillBuff
        CASE_CREATE_SKILL_NODE(23032, 139) // PlaySound
        CASE_CREATE_SKILL_NODE(23032, 165) // MoveNewPene
        CASE_CREATE_SKILL_NODE(23032, 169) // MoveNewPene
        CASE_CREATE_SKILL_NODE(23032, 170) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(23032, 171) // TriggerCheck
        CASE_CREATE_SKILL_NODE(23032, 172) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(23032, 173) // GetActorAttribute
        CASE_CREATE_SKILL_NODE(23032, 174) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(23032, 175) // CompareFloat
        CASE_CREATE_SKILL_NODE(23032, 176) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(23032, 177) // If
        CASE_CREATE_SKILL_NODE(23032, 178) // CompareFloat
        CASE_CREATE_SKILL_NODE(23032, 179) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(23032, 180) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(23032, 181) // TriggerCheck
        CASE_CREATE_SKILL_NODE(23032, 182) // TriggerCheck
        CASE_CREATE_SKILL_NODE(23032, 183) // TriggerCheck
        CASE_CREATE_SKILL_NODE(23032, 184) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(23032, 185) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(23032, 186) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(23032, 187) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(23032, 188) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(23032, 189) // AddSkillBuffs
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_23032

SkillLogic* SkillCreator_23032::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //创建阶段phase
    auto phase = new SkillPhase_23032(1, logic, 2);
    //设置phase执行器
    phase->setRunPhaseNode(1, 2);
    phase->setRunPhaseNode(2, 4);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_23032::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
